// zlib for the Windows build (LLP64). The reconstruction declares zlib's
// stream with DWARF's layout (src/ZLIB/1.2.8/zlib.h), where `uLong` is the
// PS4's 8-byte `long unsigned int`; Windows' zlib has a 4-byte `uLong`, so
// the two `z_stream`s differ from offset 0x10 on. The link wraps the three
// functions the reconstruction calls (`-Wl,--wrap=`, library/CMakeLists.txt):
// each call goes here with the reconstruction's stream, which is copied to
// and from a native stream around the call to Windows' zlib. No byte of the
// compressed data is read here.

// Windows' zlib.h with the platform's own `long` (windows-lp64.h's macro
// widens it for the reconstruction's declarations only).
#if defined(long)
#undef long
#endif
#include <zlib.h>

#include <cstddef>
#include <cstdint>
#include <new>

namespace {

// The reconstruction's `z_stream_s`, at the offsets its header gives from
// DWARF, in fixed-width types.
struct Lp64Stream {
    Bytef* next_in;
    uInt avail_in;
    std::uint64_t total_in;
    Bytef* next_out;
    uInt avail_out;
    std::uint64_t total_out;
    char* msg;
    void* state;  // here: the native stream this one stands for
    alloc_func zalloc;
    free_func zfree;
    voidpf opaque;
    int data_type;
    std::uint64_t adler;
    std::uint64_t reserved;
};
static_assert(offsetof(Lp64Stream, total_in) == 0x10, "DWARF's z_stream_s");
static_assert(offsetof(Lp64Stream, next_out) == 0x18, "DWARF's z_stream_s");
static_assert(offsetof(Lp64Stream, total_out) == 0x28, "DWARF's z_stream_s");
static_assert(offsetof(Lp64Stream, state) == 0x38, "DWARF's z_stream_s");
static_assert(offsetof(Lp64Stream, opaque) == 0x50, "DWARF's z_stream_s");
static_assert(offsetof(Lp64Stream, adler) == 0x60, "DWARF's z_stream_s");
static_assert(sizeof(Lp64Stream) == 0x70, "DWARF's z_stream_s");

void to_native(const Lp64Stream& from, z_stream& to) {
    to.next_in = from.next_in;
    to.avail_in = from.avail_in;
    to.next_out = from.next_out;
    to.avail_out = from.avail_out;
}

void from_native(const z_stream& from, Lp64Stream& to) {
    to.next_in = from.next_in;
    to.avail_in = from.avail_in;
    to.total_in = from.total_in;
    to.next_out = from.next_out;
    to.avail_out = from.avail_out;
    to.total_out = from.total_out;
    to.msg = from.msg;
    to.data_type = from.data_type;
    to.adler = from.adler;
    to.reserved = from.reserved;
}

}  // namespace

extern "C" int __real_inflateInit_(z_stream* strm, const char* version, int stream_size);
extern "C" int __real_inflate(z_stream* strm, int flush);
extern "C" int __real_inflateEnd(z_stream* strm);

extern "C" int __wrap_inflateInit_(Lp64Stream* strm, const char* version, int stream_size) {
    if (strm == nullptr || stream_size != static_cast<int>(sizeof(Lp64Stream))) {
        return Z_VERSION_ERROR;
    }
    z_stream* native = new (std::nothrow) z_stream{};
    if (native == nullptr) {
        return Z_MEM_ERROR;
    }
    to_native(*strm, *native);
    native->zalloc = strm->zalloc;
    native->zfree = strm->zfree;
    native->opaque = strm->opaque;
    (void)version;  // the reconstruction asks for 1.2.8; zlib checks the major version
    int result = __real_inflateInit_(native, ZLIB_VERSION, static_cast<int>(sizeof(z_stream)));
    from_native(*native, *strm);
    if (result != Z_OK) {
        delete native;
        strm->state = nullptr;
        return result;
    }
    strm->state = native;
    return result;
}

extern "C" int __wrap_inflate(Lp64Stream* strm, int flush) {
    if (strm == nullptr || strm->state == nullptr) {
        return Z_STREAM_ERROR;
    }
    z_stream& native = *static_cast<z_stream*>(strm->state);
    to_native(*strm, native);
    int result = __real_inflate(&native, flush);
    from_native(native, *strm);
    return result;
}

extern "C" int __wrap_inflateEnd(Lp64Stream* strm) {
    if (strm == nullptr || strm->state == nullptr) {
        return Z_STREAM_ERROR;
    }
    z_stream* native = static_cast<z_stream*>(strm->state);
    int result = __real_inflateEnd(native);
    from_native(*native, *strm);
    delete native;
    strm->state = nullptr;
    return result;
}
