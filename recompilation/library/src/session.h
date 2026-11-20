// The library's own seam between its API (`resource.cpp`) and its default
// host (`host.cpp`), and the root table the build generates. Not public: it
// includes the bundle's `MtStream.h`, after the system headers.
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "MtStream.h"
#include "resource.h"
#include "runtime.h"

// One root the library offers: its hooks (`driver::hooks`) and the
// setter of its file's game path, or null.
struct DdonLibraryRoot {
    const DdonRoot* root;
    void (*place_path)(void* root, const char* path);
};
// The build's roots, null-terminated (generated beside the bundle).
extern const DdonLibraryRoot* const ddon_library_roots[];

namespace ddon {
namespace session {

// What one load, save or destroy records while it runs.
struct Entry {
    std::vector<std::string>* stubs = nullptr;
    std::vector<InnerRequest>* inner = nullptr;
    InnerLoads inner_loads = InnerLoads::in_place;
    // Where an inner file `<path>.<ext>` resolves, ending in `/`; empty for
    // none.
    std::string archive_dir;
};

// The engine set up once (`ddon_fixtures_init`), before the first entry.
void set_up();
// One entry at a time: a second traps.
void begin(Entry& entry);
void end();
// The resources alive in the manager's table.
unsigned inner_alive();
const std::vector<std::string>& stubs_before_any_entry();

}  // namespace session

// A file's bytes as the engine's stream interface. Reads asked at the end
// are counted, and one that returns bytes after them (a seek back, then a
// read) is noted; a seek outside the bytes is clamped and noted. As an output
// stream (`writable`), a read serves nothing and is noted, and a write grows
// the bytes.
class MemoryStream final : public MtStream {
public:
    MemoryStream(std::vector<unsigned char>& bytes, bool writable)
        : mBytes(bytes), mWritable(writable) {}
    bool isReadable() override { return !mWritable; }
    bool isWritable() override { return mWritable; }
    bool isSeekable() override { return true; }
    bool isAsyncReadable() override { return false; }
    u32 getPosition() override { return mPos; }
    u32 read(void* ptr, u32 bytes) override;
    u32 readAsync(void* ptr, u32 bytes) override { return read(ptr, bytes); }
    bool isAsyncReading() const override { return false; }
    u32 write(const void* ptr, u32 bytes) override;
    u32 getLength() override { return static_cast<u32>(mBytes.size()); }
    u32 seek(s32 offset, MtStream::SEEK_ORIGIN origin) override;
    void skip(u32 size) override { seek(static_cast<s32>(size), ORG_CURRENT); }
    bool isAsyncOperationSucceeded() const override { return true; }

    unsigned reads_at_end = 0;
    bool read_after_end = false;
    bool misused = false;

private:
    std::vector<unsigned char>& mBytes;
    bool mWritable;
    u32 mPos = 0;
};

}  // namespace ddon
