// Copyright 2015 The Cockroach Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the License.

package sql

import (
	"context"
	"sync"

	"github.com/cockroachdb/cockroach/pkg/sql/pgwire/pgerror"
	"github.com/cockroachdb/cockroach/pkg/sql/privilege"
	"github.com/cockroachdb/cockroach/pkg/sql/sem/tree"
	"github.com/cockroachdb/cockroach/pkg/sql/sem/types"
	"github.com/cockroachdb/cockroach/pkg/sql/sqlbase"
	"github.com/cockroachdb/cockroach/pkg/util/log"
	"github.com/cockroachdb/cockroach/pkg/util/tracing"
)

var deleteNodePool = sync.Pool{
	New: func() interface{} {
		return &deleteNode{}
	},
}

type deleteNode struct {
	source planNode

	// columns is set if this DELETE is returning any rows, to be
	// consumed by a renderNode upstream. This occurs when there is a
	// RETURNING clause with some scalar expressions.
	columns sqlbase.ResultColumns

	run deleteRun
}

// deleteNode implements the autoCommitNode interface.
var _ autoCommitNode = &deleteNode{}

// Delete removes rows from a table.
// Privileges: DELETE and SELECT on table. We currently always use a SELECT statement.
//   Notes: postgres requires DELETE. Also requires SELECT for "USING" and "WHERE" with tables.
//          mysql requires DELETE. Also requires SELECT if a table is used in the "WHERE" clause.
func (p *planner) Delete(
	ctx context.Context, n *tree.Delete, desiredTypes []types.T,
) (planNode, error) {
	// UX friendliness safeguard.
	if n.Where == nil && p.SessionData().SafeUpdates {
		return nil, pgerror.NewDangerousStatementErrorf("DELETE without WHERE clause")
	}

	// CTE analysis.
	resetter, err := p.initWith(ctx, n.With)
	if err != nil {
		return nil, err
	}
	if resetter != nil {
		defer resetter(p)
	}

	tracing.AnnotateTrace()

	// DELETE FROM xx AS yy - we want to know about xx (tn) because
	// that's what we get the descriptor with, and yy (alias) because
	// that's what RETURNING will use.
	tn, alias, err := p.getAliasedTableName(n.Table)
	if err != nil {
		return nil, err
	}

	// Find which table we're working on, check the permissions.
	desc, err := ResolveExistingObject(ctx, p, tn, true /*required*/, requireTableDesc)
	if err != nil {
		return nil, err
	}
	if err := p.CheckPrivilege(ctx, desc, privilege.DELETE); err != nil {
		return nil, err
	}

	// Determine what are the foreign key tables that are involved in the deletion.
	fkTables, err := sqlbase.TablesNeededForFKs(
		ctx,
		*desc,
		sqlbase.CheckDeletes,
		p.lookupFKTable,
		p.CheckPrivilege,
		p.analyzeExpr,
	)
	if err != nil {
		return nil, err
	}

	// rowsNeeded will help determine whether we can use the fast path
	// in startExec.
	rowsNeeded := resultsNeeded(n.Returning)

	// Also, rowsNeeded determines which rows of the source we need
	// in the table deleter.
	var requestedCols []sqlbase.ColumnDescriptor
	if rowsNeeded {
		// Note: in contrast to INSERT and UPDATE which also require the
		// data if there are CHECK expressions, DELETE does not care about
		// constraint checking (because the rows are being deleted after
		// all).

		// TODO(dan): This could be made tighter, just the rows needed for RETURNING
		// exprs.
		requestedCols = desc.Columns
	}

	// Create the table deleter, which does the bulk of the work.
	rd, err := sqlbase.MakeRowDeleter(
		p.txn, desc, fkTables, requestedCols, sqlbase.CheckFKs, p.EvalContext(), &p.alloc,
	)
	if err != nil {
		return nil, err
	}

	tracing.AnnotateTrace()

	// Determine the source for the deletion: the rows that are read,
	// filtered, limited, ordered, etc, prior to the deletion. One would
	// think there is only so much one wants to do with rows prior to a
	// deletion, but ORDER BY / LIMIT really determines which rows are
	// being deleted. Also RETURNING will expose this.
	rows, err := p.SelectClause(ctx, &tree.SelectClause{
		Exprs: sqlbase.ColumnsSelectors(rd.FetchCols, true /* forUpdateOrDelete */),
		From:  &tree.From{Tables: []tree.TableExpr{n.Table}},
		Where: n.Where,
	}, n.OrderBy, n.Limit, nil /*with*/, nil /*desiredTypes*/, publicAndNonPublicColumns)
	if err != nil {
		return nil, err
	}

	var columns sqlbase.ResultColumns
	if rowsNeeded {
		columns = planColumns(rows)
	}

	// Now make a delete node. We use a pool.
	dn := deleteNodePool.Get().(*deleteNode)
	*dn = deleteNode{
		source:  rows,
		columns: columns,
		run: deleteRun{
			td:         tableDeleter{rd: rd, alloc: &p.alloc},
			rowsNeeded: rowsNeeded,
		},
	}

	// Finally, handle RETURNING, if any.
	r, err := p.Returning(ctx, dn, n.Returning, desiredTypes, alias)
	if err != nil {
		// We close explicitly here to release the node to the pool.
		dn.Close(ctx)
	}
	return r, err
}

// deleteRun contains the run-time state of deleteNode during local execution.
type deleteRun struct {
	td         tableDeleter
	rowsNeeded bool

	// fastPath indicates whether the delete operation is running to
	// completion during startExec.
	fastPath bool

	// rowCount is the total row count if fastPath is set,
	// or the number of rows in the current batch otherwise.
	rowCount int

	// done informs a new call to BatchedNext() that the previous call
	// to BatchedNext() has completed the work already.
	done bool

	// rows contains the accumulated result rows if rowsNeeded is set.
	rows *sqlbase.RowContainer

	// autoCommit indicates whether the last KV batch processed by
	// this delete will also commit the KV txn.
	autoCommit autoCommitOpt

	// traceKV caches the current KV tracing flag.
	traceKV bool
}

// maxDeleteBatchSize is the max number of entries in the KV batch for
// the delete operation (including secondary index updates, FK
// cascading updates, etc), before the current KV batch is executed
// and a new batch is started.
const maxDeleteBatchSize = 10000

func (d *deleteNode) startExec(params runParams) error {
	if err := params.p.maybeSetSystemConfig(d.run.td.tableDesc().GetID()); err != nil {
		return err
	}

	// cache traceKV during execution, to avoid re-evaluating it for every row.
	d.run.traceKV = params.p.ExtendedEvalContext().Tracing.KVTracingEnabled()

	if scan, ok := canDeleteFast(params.ctx, d.source, &d.run); ok {
		d.run.fastPath = true
		return d.fastDelete(params, scan)
	}

	if d.run.rowsNeeded {
		d.run.rows = sqlbase.NewRowContainer(
			params.EvalContext().Mon.MakeBoundAccount(),
			sqlbase.ColTypeInfoFromResCols(d.columns),
			maxDeleteBatchSize)
	}
	return d.run.td.init(params.p.txn, params.EvalContext())
}

// Next is required because batchedPlanNode inherits from planNode, but
// batchedPlanNode doesn't really provide it. See the explanatory comments
// in plan_batch.go.
func (d *deleteNode) Next(params runParams) (bool, error) { panic("not valid") }

// Values is required because batchedPlanNode inherits from planNode, but
// batchedPlanNode doesn't really provide it. See the explanatory comments
// in plan_batch.go.
func (d *deleteNode) Values() tree.Datums { panic("not valid") }

// BatchedNext implements the batchedPlanNode interface.
func (d *deleteNode) BatchedNext(params runParams) (bool, error) {
	if d.run.fastPath || d.run.done {
		return false, nil
	}

	tracing.AnnotateTrace()

	// Advance one batch. First, clear the current batch.
	d.run.rowCount = 0
	if d.run.rows != nil {
		d.run.rows.Clear(params.ctx)
	}
	// Now consume/accumulate the rows for this batch.
	lastBatch := false
	for {
		if err := params.p.cancelChecker.Check(); err != nil {
			return false, err
		}

		// Advance one individual row.
		if next, err := d.source.Next(params); !next {
			lastBatch = true
			if err != nil {
				return false, err
			}
			break
		}

		// Process the deletion of the current source row,
		// potentially accumulating the result row for later.
		if err := d.processSourceRow(params, d.source.Values()); err != nil {
			return false, err
		}

		d.run.rowCount++

		// Are we done yet with the current batch?
		if d.run.td.curBatchSize() >= maxDeleteBatchSize {
			break
		}
	}

	if d.run.rowCount > 0 {
		if err := d.run.td.atBatchEnd(params.ctx, d.run.traceKV); err != nil {
			return false, err
		}

		if !lastBatch {
			// We only run/commit the batch if there were some rows processed
			// in this batch.
			if err := d.run.td.flushAndStartNewBatch(params.ctx); err != nil {
				return false, err
			}
		}
	}

	if lastBatch {
		if _, err := d.run.td.finalize(params.ctx, d.run.autoCommit, d.run.traceKV); err != nil {
			return false, err
		}
		// Remember we're done for the next call to BatchedNext().
		d.run.done = true
	}

	return d.run.rowCount > 0, nil
}

// processSourceRow processes one row from the source for deletion and, if
// result rows are needed, saves it in the result row container
func (d *deleteNode) processSourceRow(params runParams, sourceVals tree.Datums) error {
	// Queue the deletion in the KV batch.
	if _, err := d.run.td.row(params.ctx, sourceVals, d.run.traceKV); err != nil {
		return err
	}

	// If result rows need to be accumulated, do it.
	if d.run.rows != nil {
		if _, err := d.run.rows.AddRow(params.ctx, sourceVals); err != nil {
			return err
		}
	}

	return nil
}

// BatchedCount implements the batchedPlanNode interface.
func (d *deleteNode) BatchedCount() int { return d.run.rowCount }

// BatchedCount implements the batchedPlanNode interface.
func (d *deleteNode) BatchedValues(rowIdx int) tree.Datums { return d.run.rows.At(rowIdx) }

func (d *deleteNode) Close(ctx context.Context) {
	d.source.Close(ctx)
	if d.run.rows != nil {
		d.run.rows.Close(ctx)
		d.run.rows = nil
	}
	d.run.td.close(ctx)
	*d = deleteNode{}
	deleteNodePool.Put(d)
}

// FastPathResults implements the planNodeFastPath interface.
func (d *deleteNode) FastPathResults() (int, bool) {
	return d.run.rowCount, d.run.fastPath
}

// canDeleteFast determines if the deletion of `rows` can be done
// without actually scanning them.
// This should be called after plan simplification for optimal results.
func canDeleteFast(ctx context.Context, source planNode, r *deleteRun) (*scanNode, bool) {
	// Check that there are no secondary indexes, interleaving, FK
	// references checks, etc., ie. there is no extra work to be done
	// per row deleted.
	if !r.td.fastPathAvailable(ctx) {
		return nil, false
	}

	// If the rows are needed (a RETURNING clause), we can't skip them.
	if r.rowsNeeded {
		return nil, false
	}

	// Check whether the source plan is "simple": that it contains no
	// remaining filtering, limiting, sorting, etc.
	// TODO(dt): We could probably be smarter when presented with an
	// index-join, but this goes away anyway once we push-down more of
	// SQL.
	maybeScan := source
	if sel, ok := maybeScan.(*renderNode); ok {
		// There may be a projection to drop/rename some columns which the
		// optimizations did not remove at this point. We just ignore that
		// projection for the purpose of this check.
		maybeScan = sel.source.plan
	}

	scan, ok := maybeScan.(*scanNode)
	if !ok {
		// Not simple enough. Bail.
		return nil, false
	}

	// A scan ought to be simple enough, except when it's not: a scan
	// may have a remaining filter. We can't be fast over that.
	if scan.filter != nil {
		if log.V(2) {
			log.Infof(ctx, "delete forced to scan: values required for filter (%s)", scan.filter)
		}
		return nil, false
	}

	return scan, true
}

// `fastDelete` skips the scan of rows and just deletes the ranges that
// `scan` would scan. Should only be used if `canDeleteFast` indicates
// that it is safe to do so.
func (d *deleteNode) fastDelete(params runParams, scan *scanNode) error {
	if err := scan.initScan(params); err != nil {
		return err
	}
	if err := d.run.td.init(params.p.txn, params.EvalContext()); err != nil {
		return err
	}
	if err := params.p.cancelChecker.Check(); err != nil {
		return err
	}
	var err error
	d.run.rowCount, err = d.run.td.fastDelete(
		params.ctx, scan, d.run.autoCommit, d.run.traceKV)
	return err
}

// enableAutoCommit is part of the autoCommitNode interface.
func (d *deleteNode) enableAutoCommit() {
	d.run.autoCommit = autoCommitEnabled
}
