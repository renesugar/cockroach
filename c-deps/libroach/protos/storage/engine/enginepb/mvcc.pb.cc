// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: storage/engine/enginepb/mvcc.proto

#include "storage/engine/enginepb/mvcc.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace cockroach {
namespace storage {
namespace engine {
namespace enginepb {
class MVCCMetadataDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MVCCMetadata>
      _instance;
} _MVCCMetadata_default_instance_;
class MVCCStatsDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MVCCStats>
      _instance;
} _MVCCStats_default_instance_;
}  // namespace enginepb
}  // namespace engine
}  // namespace storage
}  // namespace cockroach
namespace protobuf_storage_2fengine_2fenginepb_2fmvcc_2eproto {
void InitDefaultsMVCCMetadataImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_storage_2fengine_2fenginepb_2fmvcc3_2eproto::InitDefaultsTxnMeta();
  protobuf_util_2fhlc_2flegacy_5ftimestamp_2eproto::InitDefaultsLegacyTimestamp();
  {
    void* ptr = &::cockroach::storage::engine::enginepb::_MVCCMetadata_default_instance_;
    new (ptr) ::cockroach::storage::engine::enginepb::MVCCMetadata();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::cockroach::storage::engine::enginepb::MVCCMetadata::InitAsDefaultInstance();
}

void InitDefaultsMVCCMetadata() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsMVCCMetadataImpl);
}

void InitDefaultsMVCCStatsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::cockroach::storage::engine::enginepb::_MVCCStats_default_instance_;
    new (ptr) ::cockroach::storage::engine::enginepb::MVCCStats();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::cockroach::storage::engine::enginepb::MVCCStats::InitAsDefaultInstance();
}

void InitDefaultsMVCCStats() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsMVCCStatsImpl);
}

}  // namespace protobuf_storage_2fengine_2fenginepb_2fmvcc_2eproto
namespace cockroach {
namespace storage {
namespace engine {
namespace enginepb {

// ===================================================================

void MVCCMetadata::InitAsDefaultInstance() {
  ::cockroach::storage::engine::enginepb::_MVCCMetadata_default_instance_._instance.get_mutable()->txn_ = const_cast< ::cockroach::storage::engine::enginepb::TxnMeta*>(
      ::cockroach::storage::engine::enginepb::TxnMeta::internal_default_instance());
  ::cockroach::storage::engine::enginepb::_MVCCMetadata_default_instance_._instance.get_mutable()->timestamp_ = const_cast< ::cockroach::util::hlc::LegacyTimestamp*>(
      ::cockroach::util::hlc::LegacyTimestamp::internal_default_instance());
  ::cockroach::storage::engine::enginepb::_MVCCMetadata_default_instance_._instance.get_mutable()->merge_timestamp_ = const_cast< ::cockroach::util::hlc::LegacyTimestamp*>(
      ::cockroach::util::hlc::LegacyTimestamp::internal_default_instance());
}
void MVCCMetadata::clear_txn() {
  if (txn_ != NULL) txn_->Clear();
  clear_has_txn();
}
void MVCCMetadata::clear_timestamp() {
  if (timestamp_ != NULL) timestamp_->Clear();
  clear_has_timestamp();
}
void MVCCMetadata::clear_merge_timestamp() {
  if (merge_timestamp_ != NULL) merge_timestamp_->Clear();
  clear_has_merge_timestamp();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MVCCMetadata::kTxnFieldNumber;
const int MVCCMetadata::kTimestampFieldNumber;
const int MVCCMetadata::kDeletedFieldNumber;
const int MVCCMetadata::kKeyBytesFieldNumber;
const int MVCCMetadata::kValBytesFieldNumber;
const int MVCCMetadata::kRawBytesFieldNumber;
const int MVCCMetadata::kMergeTimestampFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MVCCMetadata::MVCCMetadata()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_storage_2fengine_2fenginepb_2fmvcc_2eproto::InitDefaultsMVCCMetadata();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:cockroach.storage.engine.enginepb.MVCCMetadata)
}
MVCCMetadata::MVCCMetadata(const MVCCMetadata& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  raw_bytes_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_raw_bytes()) {
    raw_bytes_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.raw_bytes_);
  }
  if (from.has_txn()) {
    txn_ = new ::cockroach::storage::engine::enginepb::TxnMeta(*from.txn_);
  } else {
    txn_ = NULL;
  }
  if (from.has_timestamp()) {
    timestamp_ = new ::cockroach::util::hlc::LegacyTimestamp(*from.timestamp_);
  } else {
    timestamp_ = NULL;
  }
  if (from.has_merge_timestamp()) {
    merge_timestamp_ = new ::cockroach::util::hlc::LegacyTimestamp(*from.merge_timestamp_);
  } else {
    merge_timestamp_ = NULL;
  }
  ::memcpy(&key_bytes_, &from.key_bytes_,
    static_cast<size_t>(reinterpret_cast<char*>(&deleted_) -
    reinterpret_cast<char*>(&key_bytes_)) + sizeof(deleted_));
  // @@protoc_insertion_point(copy_constructor:cockroach.storage.engine.enginepb.MVCCMetadata)
}

void MVCCMetadata::SharedCtor() {
  _cached_size_ = 0;
  raw_bytes_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&txn_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&deleted_) -
      reinterpret_cast<char*>(&txn_)) + sizeof(deleted_));
}

MVCCMetadata::~MVCCMetadata() {
  // @@protoc_insertion_point(destructor:cockroach.storage.engine.enginepb.MVCCMetadata)
  SharedDtor();
}

void MVCCMetadata::SharedDtor() {
  raw_bytes_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete txn_;
  if (this != internal_default_instance()) delete timestamp_;
  if (this != internal_default_instance()) delete merge_timestamp_;
}

void MVCCMetadata::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const MVCCMetadata& MVCCMetadata::default_instance() {
  ::protobuf_storage_2fengine_2fenginepb_2fmvcc_2eproto::InitDefaultsMVCCMetadata();
  return *internal_default_instance();
}

MVCCMetadata* MVCCMetadata::New(::google::protobuf::Arena* arena) const {
  MVCCMetadata* n = new MVCCMetadata;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MVCCMetadata::Clear() {
// @@protoc_insertion_point(message_clear_start:cockroach.storage.engine.enginepb.MVCCMetadata)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!raw_bytes_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*raw_bytes_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(txn_ != NULL);
      txn_->Clear();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(timestamp_ != NULL);
      timestamp_->Clear();
    }
    if (cached_has_bits & 0x00000008u) {
      GOOGLE_DCHECK(merge_timestamp_ != NULL);
      merge_timestamp_->Clear();
    }
  }
  if (cached_has_bits & 112u) {
    ::memset(&key_bytes_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&deleted_) -
        reinterpret_cast<char*>(&key_bytes_)) + sizeof(deleted_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool MVCCMetadata::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:cockroach.storage.engine.enginepb.MVCCMetadata)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .cockroach.storage.engine.enginepb.TxnMeta txn = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_txn()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_timestamp()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_deleted();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &deleted_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_key_bytes();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &key_bytes_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          set_has_val_bytes();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &val_bytes_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bytes raw_bytes = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_raw_bytes()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .cockroach.util.hlc.LegacyTimestamp merge_timestamp = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(58u /* 58 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_merge_timestamp()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:cockroach.storage.engine.enginepb.MVCCMetadata)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:cockroach.storage.engine.enginepb.MVCCMetadata)
  return false;
#undef DO_
}

void MVCCMetadata::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:cockroach.storage.engine.enginepb.MVCCMetadata)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .cockroach.storage.engine.enginepb.TxnMeta txn = 1;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, *this->txn_, output);
  }

  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      2, *this->timestamp_, output);
  }

  if (cached_has_bits & 0x00000040u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->deleted(), output);
  }

  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->key_bytes(), output);
  }

  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(5, this->val_bytes(), output);
  }

  // optional bytes raw_bytes = 6;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      6, this->raw_bytes(), output);
  }

  // optional .cockroach.util.hlc.LegacyTimestamp merge_timestamp = 7;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      7, *this->merge_timestamp_, output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:cockroach.storage.engine.enginepb.MVCCMetadata)
}

size_t MVCCMetadata::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cockroach.storage.engine.enginepb.MVCCMetadata)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  if (_has_bits_[0 / 32] & 127u) {
    // optional bytes raw_bytes = 6;
    if (has_raw_bytes()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->raw_bytes());
    }

    // optional .cockroach.storage.engine.enginepb.TxnMeta txn = 1;
    if (has_txn()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *this->txn_);
    }

    if (has_timestamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *this->timestamp_);
    }

    // optional .cockroach.util.hlc.LegacyTimestamp merge_timestamp = 7;
    if (has_merge_timestamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *this->merge_timestamp_);
    }

    if (has_key_bytes()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->key_bytes());
    }

    if (has_val_bytes()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->val_bytes());
    }

    if (has_deleted()) {
      total_size += 1 + 1;
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MVCCMetadata::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const MVCCMetadata*>(&from));
}

void MVCCMetadata::MergeFrom(const MVCCMetadata& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cockroach.storage.engine.enginepb.MVCCMetadata)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 127u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_raw_bytes();
      raw_bytes_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.raw_bytes_);
    }
    if (cached_has_bits & 0x00000002u) {
      mutable_txn()->::cockroach::storage::engine::enginepb::TxnMeta::MergeFrom(from.txn());
    }
    if (cached_has_bits & 0x00000004u) {
      mutable_timestamp()->::cockroach::util::hlc::LegacyTimestamp::MergeFrom(from.timestamp());
    }
    if (cached_has_bits & 0x00000008u) {
      mutable_merge_timestamp()->::cockroach::util::hlc::LegacyTimestamp::MergeFrom(from.merge_timestamp());
    }
    if (cached_has_bits & 0x00000010u) {
      key_bytes_ = from.key_bytes_;
    }
    if (cached_has_bits & 0x00000020u) {
      val_bytes_ = from.val_bytes_;
    }
    if (cached_has_bits & 0x00000040u) {
      deleted_ = from.deleted_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void MVCCMetadata::CopyFrom(const MVCCMetadata& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cockroach.storage.engine.enginepb.MVCCMetadata)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MVCCMetadata::IsInitialized() const {
  return true;
}

void MVCCMetadata::Swap(MVCCMetadata* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MVCCMetadata::InternalSwap(MVCCMetadata* other) {
  using std::swap;
  raw_bytes_.Swap(&other->raw_bytes_);
  swap(txn_, other->txn_);
  swap(timestamp_, other->timestamp_);
  swap(merge_timestamp_, other->merge_timestamp_);
  swap(key_bytes_, other->key_bytes_);
  swap(val_bytes_, other->val_bytes_);
  swap(deleted_, other->deleted_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string MVCCMetadata::GetTypeName() const {
  return "cockroach.storage.engine.enginepb.MVCCMetadata";
}


// ===================================================================

void MVCCStats::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MVCCStats::kContainsEstimatesFieldNumber;
const int MVCCStats::kLastUpdateNanosFieldNumber;
const int MVCCStats::kIntentAgeFieldNumber;
const int MVCCStats::kGcBytesAgeFieldNumber;
const int MVCCStats::kLiveBytesFieldNumber;
const int MVCCStats::kLiveCountFieldNumber;
const int MVCCStats::kKeyBytesFieldNumber;
const int MVCCStats::kKeyCountFieldNumber;
const int MVCCStats::kValBytesFieldNumber;
const int MVCCStats::kValCountFieldNumber;
const int MVCCStats::kIntentBytesFieldNumber;
const int MVCCStats::kIntentCountFieldNumber;
const int MVCCStats::kSysBytesFieldNumber;
const int MVCCStats::kSysCountFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MVCCStats::MVCCStats()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_storage_2fengine_2fenginepb_2fmvcc_2eproto::InitDefaultsMVCCStats();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:cockroach.storage.engine.enginepb.MVCCStats)
}
MVCCStats::MVCCStats(const MVCCStats& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&last_update_nanos_, &from.last_update_nanos_,
    static_cast<size_t>(reinterpret_cast<char*>(&contains_estimates_) -
    reinterpret_cast<char*>(&last_update_nanos_)) + sizeof(contains_estimates_));
  // @@protoc_insertion_point(copy_constructor:cockroach.storage.engine.enginepb.MVCCStats)
}

void MVCCStats::SharedCtor() {
  _cached_size_ = 0;
  ::memset(&last_update_nanos_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&contains_estimates_) -
      reinterpret_cast<char*>(&last_update_nanos_)) + sizeof(contains_estimates_));
}

MVCCStats::~MVCCStats() {
  // @@protoc_insertion_point(destructor:cockroach.storage.engine.enginepb.MVCCStats)
  SharedDtor();
}

void MVCCStats::SharedDtor() {
}

void MVCCStats::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const MVCCStats& MVCCStats::default_instance() {
  ::protobuf_storage_2fengine_2fenginepb_2fmvcc_2eproto::InitDefaultsMVCCStats();
  return *internal_default_instance();
}

MVCCStats* MVCCStats::New(::google::protobuf::Arena* arena) const {
  MVCCStats* n = new MVCCStats;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MVCCStats::Clear() {
// @@protoc_insertion_point(message_clear_start:cockroach.storage.engine.enginepb.MVCCStats)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 255u) {
    ::memset(&last_update_nanos_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&val_bytes_) -
        reinterpret_cast<char*>(&last_update_nanos_)) + sizeof(val_bytes_));
  }
  if (cached_has_bits & 16128u) {
    ::memset(&val_count_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&contains_estimates_) -
        reinterpret_cast<char*>(&val_count_)) + sizeof(contains_estimates_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool MVCCStats::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:cockroach.storage.engine.enginepb.MVCCStats)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(9u /* 9 & 0xFF */)) {
          set_has_last_update_nanos();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &last_update_nanos_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(17u /* 17 & 0xFF */)) {
          set_has_intent_age();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &intent_age_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(25u /* 25 & 0xFF */)) {
          set_has_gc_bytes_age();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &gc_bytes_age_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(33u /* 33 & 0xFF */)) {
          set_has_live_bytes();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &live_bytes_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(41u /* 41 & 0xFF */)) {
          set_has_live_count();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &live_count_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(49u /* 49 & 0xFF */)) {
          set_has_key_bytes();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &key_bytes_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(57u /* 57 & 0xFF */)) {
          set_has_key_count();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &key_count_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(65u /* 65 & 0xFF */)) {
          set_has_val_bytes();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &val_bytes_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 9: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(73u /* 73 & 0xFF */)) {
          set_has_val_count();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &val_count_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 10: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(81u /* 81 & 0xFF */)) {
          set_has_intent_bytes();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &intent_bytes_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 11: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(89u /* 89 & 0xFF */)) {
          set_has_intent_count();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &intent_count_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 12: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(97u /* 97 & 0xFF */)) {
          set_has_sys_bytes();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &sys_bytes_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 13: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(105u /* 105 & 0xFF */)) {
          set_has_sys_count();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &sys_count_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      case 14: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(112u /* 112 & 0xFF */)) {
          set_has_contains_estimates();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &contains_estimates_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:cockroach.storage.engine.enginepb.MVCCStats)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:cockroach.storage.engine.enginepb.MVCCStats)
  return false;
#undef DO_
}

void MVCCStats::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:cockroach.storage.engine.enginepb.MVCCStats)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(1, this->last_update_nanos(), output);
  }

  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(2, this->intent_age(), output);
  }

  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(3, this->gc_bytes_age(), output);
  }

  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(4, this->live_bytes(), output);
  }

  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(5, this->live_count(), output);
  }

  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(6, this->key_bytes(), output);
  }

  if (cached_has_bits & 0x00000040u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(7, this->key_count(), output);
  }

  if (cached_has_bits & 0x00000080u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(8, this->val_bytes(), output);
  }

  if (cached_has_bits & 0x00000100u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(9, this->val_count(), output);
  }

  if (cached_has_bits & 0x00000200u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(10, this->intent_bytes(), output);
  }

  if (cached_has_bits & 0x00000400u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(11, this->intent_count(), output);
  }

  if (cached_has_bits & 0x00000800u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(12, this->sys_bytes(), output);
  }

  if (cached_has_bits & 0x00001000u) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(13, this->sys_count(), output);
  }

  if (cached_has_bits & 0x00002000u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(14, this->contains_estimates(), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:cockroach.storage.engine.enginepb.MVCCStats)
}

size_t MVCCStats::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cockroach.storage.engine.enginepb.MVCCStats)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  if (_has_bits_[0 / 32] & 255u) {
    if (has_last_update_nanos()) {
      total_size += 1 + 8;
    }

    if (has_intent_age()) {
      total_size += 1 + 8;
    }

    if (has_gc_bytes_age()) {
      total_size += 1 + 8;
    }

    if (has_live_bytes()) {
      total_size += 1 + 8;
    }

    if (has_live_count()) {
      total_size += 1 + 8;
    }

    if (has_key_bytes()) {
      total_size += 1 + 8;
    }

    if (has_key_count()) {
      total_size += 1 + 8;
    }

    if (has_val_bytes()) {
      total_size += 1 + 8;
    }

  }
  if (_has_bits_[8 / 32] & 16128u) {
    if (has_val_count()) {
      total_size += 1 + 8;
    }

    if (has_intent_bytes()) {
      total_size += 1 + 8;
    }

    if (has_intent_count()) {
      total_size += 1 + 8;
    }

    if (has_sys_bytes()) {
      total_size += 1 + 8;
    }

    if (has_sys_count()) {
      total_size += 1 + 8;
    }

    if (has_contains_estimates()) {
      total_size += 1 + 1;
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MVCCStats::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const MVCCStats*>(&from));
}

void MVCCStats::MergeFrom(const MVCCStats& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cockroach.storage.engine.enginepb.MVCCStats)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 255u) {
    if (cached_has_bits & 0x00000001u) {
      last_update_nanos_ = from.last_update_nanos_;
    }
    if (cached_has_bits & 0x00000002u) {
      intent_age_ = from.intent_age_;
    }
    if (cached_has_bits & 0x00000004u) {
      gc_bytes_age_ = from.gc_bytes_age_;
    }
    if (cached_has_bits & 0x00000008u) {
      live_bytes_ = from.live_bytes_;
    }
    if (cached_has_bits & 0x00000010u) {
      live_count_ = from.live_count_;
    }
    if (cached_has_bits & 0x00000020u) {
      key_bytes_ = from.key_bytes_;
    }
    if (cached_has_bits & 0x00000040u) {
      key_count_ = from.key_count_;
    }
    if (cached_has_bits & 0x00000080u) {
      val_bytes_ = from.val_bytes_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  if (cached_has_bits & 16128u) {
    if (cached_has_bits & 0x00000100u) {
      val_count_ = from.val_count_;
    }
    if (cached_has_bits & 0x00000200u) {
      intent_bytes_ = from.intent_bytes_;
    }
    if (cached_has_bits & 0x00000400u) {
      intent_count_ = from.intent_count_;
    }
    if (cached_has_bits & 0x00000800u) {
      sys_bytes_ = from.sys_bytes_;
    }
    if (cached_has_bits & 0x00001000u) {
      sys_count_ = from.sys_count_;
    }
    if (cached_has_bits & 0x00002000u) {
      contains_estimates_ = from.contains_estimates_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void MVCCStats::CopyFrom(const MVCCStats& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cockroach.storage.engine.enginepb.MVCCStats)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MVCCStats::IsInitialized() const {
  return true;
}

void MVCCStats::Swap(MVCCStats* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MVCCStats::InternalSwap(MVCCStats* other) {
  using std::swap;
  swap(last_update_nanos_, other->last_update_nanos_);
  swap(intent_age_, other->intent_age_);
  swap(gc_bytes_age_, other->gc_bytes_age_);
  swap(live_bytes_, other->live_bytes_);
  swap(live_count_, other->live_count_);
  swap(key_bytes_, other->key_bytes_);
  swap(key_count_, other->key_count_);
  swap(val_bytes_, other->val_bytes_);
  swap(val_count_, other->val_count_);
  swap(intent_bytes_, other->intent_bytes_);
  swap(intent_count_, other->intent_count_);
  swap(sys_bytes_, other->sys_bytes_);
  swap(sys_count_, other->sys_count_);
  swap(contains_estimates_, other->contains_estimates_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string MVCCStats::GetTypeName() const {
  return "cockroach.storage.engine.enginepb.MVCCStats";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace enginepb
}  // namespace engine
}  // namespace storage
}  // namespace cockroach

// @@protoc_insertion_point(global_scope)
