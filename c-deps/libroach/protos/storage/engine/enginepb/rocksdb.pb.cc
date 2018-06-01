// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: storage/engine/enginepb/rocksdb.proto

#include "storage/engine/enginepb/rocksdb.pb.h"

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
class SSTUserPropertiesDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SSTUserProperties>
      _instance;
} _SSTUserProperties_default_instance_;
class SSTUserPropertiesCollectionDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SSTUserPropertiesCollection>
      _instance;
} _SSTUserPropertiesCollection_default_instance_;
}  // namespace enginepb
}  // namespace engine
}  // namespace storage
}  // namespace cockroach
namespace protobuf_storage_2fengine_2fenginepb_2frocksdb_2eproto {
void InitDefaultsSSTUserPropertiesImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_util_2fhlc_2ftimestamp_2eproto::InitDefaultsTimestamp();
  {
    void* ptr = &::cockroach::storage::engine::enginepb::_SSTUserProperties_default_instance_;
    new (ptr) ::cockroach::storage::engine::enginepb::SSTUserProperties();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::cockroach::storage::engine::enginepb::SSTUserProperties::InitAsDefaultInstance();
}

void InitDefaultsSSTUserProperties() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSSTUserPropertiesImpl);
}

void InitDefaultsSSTUserPropertiesCollectionImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_storage_2fengine_2fenginepb_2frocksdb_2eproto::InitDefaultsSSTUserProperties();
  {
    void* ptr = &::cockroach::storage::engine::enginepb::_SSTUserPropertiesCollection_default_instance_;
    new (ptr) ::cockroach::storage::engine::enginepb::SSTUserPropertiesCollection();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::cockroach::storage::engine::enginepb::SSTUserPropertiesCollection::InitAsDefaultInstance();
}

void InitDefaultsSSTUserPropertiesCollection() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSSTUserPropertiesCollectionImpl);
}

}  // namespace protobuf_storage_2fengine_2fenginepb_2frocksdb_2eproto
namespace cockroach {
namespace storage {
namespace engine {
namespace enginepb {

// ===================================================================

void SSTUserProperties::InitAsDefaultInstance() {
  ::cockroach::storage::engine::enginepb::_SSTUserProperties_default_instance_._instance.get_mutable()->ts_min_ = const_cast< ::cockroach::util::hlc::Timestamp*>(
      ::cockroach::util::hlc::Timestamp::internal_default_instance());
  ::cockroach::storage::engine::enginepb::_SSTUserProperties_default_instance_._instance.get_mutable()->ts_max_ = const_cast< ::cockroach::util::hlc::Timestamp*>(
      ::cockroach::util::hlc::Timestamp::internal_default_instance());
}
void SSTUserProperties::clear_ts_min() {
  if (GetArenaNoVirtual() == NULL && ts_min_ != NULL) {
    delete ts_min_;
  }
  ts_min_ = NULL;
}
void SSTUserProperties::clear_ts_max() {
  if (GetArenaNoVirtual() == NULL && ts_max_ != NULL) {
    delete ts_max_;
  }
  ts_max_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SSTUserProperties::kPathFieldNumber;
const int SSTUserProperties::kTsMinFieldNumber;
const int SSTUserProperties::kTsMaxFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SSTUserProperties::SSTUserProperties()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_storage_2fengine_2fenginepb_2frocksdb_2eproto::InitDefaultsSSTUserProperties();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:cockroach.storage.engine.enginepb.SSTUserProperties)
}
SSTUserProperties::SSTUserProperties(const SSTUserProperties& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  path_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.path().size() > 0) {
    path_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.path_);
  }
  if (from.has_ts_min()) {
    ts_min_ = new ::cockroach::util::hlc::Timestamp(*from.ts_min_);
  } else {
    ts_min_ = NULL;
  }
  if (from.has_ts_max()) {
    ts_max_ = new ::cockroach::util::hlc::Timestamp(*from.ts_max_);
  } else {
    ts_max_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:cockroach.storage.engine.enginepb.SSTUserProperties)
}

void SSTUserProperties::SharedCtor() {
  path_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&ts_min_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&ts_max_) -
      reinterpret_cast<char*>(&ts_min_)) + sizeof(ts_max_));
  _cached_size_ = 0;
}

SSTUserProperties::~SSTUserProperties() {
  // @@protoc_insertion_point(destructor:cockroach.storage.engine.enginepb.SSTUserProperties)
  SharedDtor();
}

void SSTUserProperties::SharedDtor() {
  path_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete ts_min_;
  if (this != internal_default_instance()) delete ts_max_;
}

void SSTUserProperties::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const SSTUserProperties& SSTUserProperties::default_instance() {
  ::protobuf_storage_2fengine_2fenginepb_2frocksdb_2eproto::InitDefaultsSSTUserProperties();
  return *internal_default_instance();
}

SSTUserProperties* SSTUserProperties::New(::google::protobuf::Arena* arena) const {
  SSTUserProperties* n = new SSTUserProperties;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SSTUserProperties::Clear() {
// @@protoc_insertion_point(message_clear_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  path_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == NULL && ts_min_ != NULL) {
    delete ts_min_;
  }
  ts_min_ = NULL;
  if (GetArenaNoVirtual() == NULL && ts_max_ != NULL) {
    delete ts_max_;
  }
  ts_max_ = NULL;
  _internal_metadata_.Clear();
}

bool SSTUserProperties::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string path = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_path()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->path().data(), static_cast<int>(this->path().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "cockroach.storage.engine.enginepb.SSTUserProperties.path"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .cockroach.util.hlc.Timestamp ts_min = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_ts_min()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .cockroach.util.hlc.Timestamp ts_max = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_ts_max()));
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
  // @@protoc_insertion_point(parse_success:cockroach.storage.engine.enginepb.SSTUserProperties)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:cockroach.storage.engine.enginepb.SSTUserProperties)
  return false;
#undef DO_
}

void SSTUserProperties::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string path = 1;
  if (this->path().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->path().data(), static_cast<int>(this->path().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cockroach.storage.engine.enginepb.SSTUserProperties.path");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->path(), output);
  }

  // .cockroach.util.hlc.Timestamp ts_min = 2;
  if (this->has_ts_min()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      2, *this->ts_min_, output);
  }

  // .cockroach.util.hlc.Timestamp ts_max = 3;
  if (this->has_ts_max()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      3, *this->ts_max_, output);
  }

  output->WriteRaw((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).data(),
                   static_cast<int>((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size()));
  // @@protoc_insertion_point(serialize_end:cockroach.storage.engine.enginepb.SSTUserProperties)
}

size_t SSTUserProperties::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  size_t total_size = 0;

  total_size += (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size();

  // string path = 1;
  if (this->path().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->path());
  }

  // .cockroach.util.hlc.Timestamp ts_min = 2;
  if (this->has_ts_min()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *this->ts_min_);
  }

  // .cockroach.util.hlc.Timestamp ts_max = 3;
  if (this->has_ts_max()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *this->ts_max_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SSTUserProperties::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const SSTUserProperties*>(&from));
}

void SSTUserProperties::MergeFrom(const SSTUserProperties& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.path().size() > 0) {

    path_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.path_);
  }
  if (from.has_ts_min()) {
    mutable_ts_min()->::cockroach::util::hlc::Timestamp::MergeFrom(from.ts_min());
  }
  if (from.has_ts_max()) {
    mutable_ts_max()->::cockroach::util::hlc::Timestamp::MergeFrom(from.ts_max());
  }
}

void SSTUserProperties::CopyFrom(const SSTUserProperties& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cockroach.storage.engine.enginepb.SSTUserProperties)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SSTUserProperties::IsInitialized() const {
  return true;
}

void SSTUserProperties::Swap(SSTUserProperties* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SSTUserProperties::InternalSwap(SSTUserProperties* other) {
  using std::swap;
  path_.Swap(&other->path_);
  swap(ts_min_, other->ts_min_);
  swap(ts_max_, other->ts_max_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string SSTUserProperties::GetTypeName() const {
  return "cockroach.storage.engine.enginepb.SSTUserProperties";
}


// ===================================================================

void SSTUserPropertiesCollection::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SSTUserPropertiesCollection::kSstFieldNumber;
const int SSTUserPropertiesCollection::kErrorFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SSTUserPropertiesCollection::SSTUserPropertiesCollection()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_storage_2fengine_2fenginepb_2frocksdb_2eproto::InitDefaultsSSTUserPropertiesCollection();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
}
SSTUserPropertiesCollection::SSTUserPropertiesCollection(const SSTUserPropertiesCollection& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      sst_(from.sst_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  error_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.error().size() > 0) {
    error_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.error_);
  }
  // @@protoc_insertion_point(copy_constructor:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
}

void SSTUserPropertiesCollection::SharedCtor() {
  error_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

SSTUserPropertiesCollection::~SSTUserPropertiesCollection() {
  // @@protoc_insertion_point(destructor:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  SharedDtor();
}

void SSTUserPropertiesCollection::SharedDtor() {
  error_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void SSTUserPropertiesCollection::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const SSTUserPropertiesCollection& SSTUserPropertiesCollection::default_instance() {
  ::protobuf_storage_2fengine_2fenginepb_2frocksdb_2eproto::InitDefaultsSSTUserPropertiesCollection();
  return *internal_default_instance();
}

SSTUserPropertiesCollection* SSTUserPropertiesCollection::New(::google::protobuf::Arena* arena) const {
  SSTUserPropertiesCollection* n = new SSTUserPropertiesCollection;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SSTUserPropertiesCollection::Clear() {
// @@protoc_insertion_point(message_clear_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  sst_.Clear();
  error_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool SSTUserPropertiesCollection::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_sst()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string error = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_error()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->error().data(), static_cast<int>(this->error().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error"));
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
  // @@protoc_insertion_point(parse_success:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  return false;
#undef DO_
}

void SSTUserPropertiesCollection::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->sst_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->sst(static_cast<int>(i)), output);
  }

  // string error = 2;
  if (this->error().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->error().data(), static_cast<int>(this->error().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->error(), output);
  }

  output->WriteRaw((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).data(),
                   static_cast<int>((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size()));
  // @@protoc_insertion_point(serialize_end:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
}

size_t SSTUserPropertiesCollection::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  size_t total_size = 0;

  total_size += (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size();

  {
    unsigned int count = static_cast<unsigned int>(this->sst_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->sst(static_cast<int>(i)));
    }
  }

  // string error = 2;
  if (this->error().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->error());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SSTUserPropertiesCollection::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const SSTUserPropertiesCollection*>(&from));
}

void SSTUserPropertiesCollection::MergeFrom(const SSTUserPropertiesCollection& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  sst_.MergeFrom(from.sst_);
  if (from.error().size() > 0) {

    error_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.error_);
  }
}

void SSTUserPropertiesCollection::CopyFrom(const SSTUserPropertiesCollection& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SSTUserPropertiesCollection::IsInitialized() const {
  return true;
}

void SSTUserPropertiesCollection::Swap(SSTUserPropertiesCollection* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SSTUserPropertiesCollection::InternalSwap(SSTUserPropertiesCollection* other) {
  using std::swap;
  sst_.InternalSwap(&other->sst_);
  error_.Swap(&other->error_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string SSTUserPropertiesCollection::GetTypeName() const {
  return "cockroach.storage.engine.enginepb.SSTUserPropertiesCollection";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace enginepb
}  // namespace engine
}  // namespace storage
}  // namespace cockroach

// @@protoc_insertion_point(global_scope)
