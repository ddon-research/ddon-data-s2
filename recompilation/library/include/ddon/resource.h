// The load/save library's interface: one root's
// file loaded through the game's own `load`, saved through its own `save`
// (or the save derived from its load), and destroyed, outside the harness's
// test runner. C++17, no exceptions, no RTTI: a result says what happened in
// its `Status`.
//
// Standard headers only, and the engine's types forward-declared: a program
// that includes this never parses the bundle's PS4 libc declarations before
// its own C library's (`fixtures.cpp`).
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

class cResource;
struct DdonRoot;

namespace ddon {

enum class Status {
    // load returned true, every byte consumed, no stub reached, nothing read
    // after a read at the end.
    ok,
    load_returned_false,
    // Bytes left, or a read past the end that returned bytes.
    not_whole,
    // A body the reconstruction refused ran (its name in `stubs`).
    stub_reached,
    // No such root in this build's table.
    unknown_root,
    // The format census classes this file (not yet answered).
    format_differs,
    // The root has neither its own save nor a derived one.
    no_save,
    save_returned_false,
    // The save read its output stream or sought outside what it wrote: its
    // bytes are no round trip (the harness's `read from the output stream`,
    // `seek outside the output stream`).
    save_used_stream,
    // InnerLoads::isolate where this build has no isolation.
    unsupported_option,
    io_error,
};

// The name of a status, as the library spells it.
const char* status_name(Status status);

enum class InnerLoads {
    // Each inner load first in a child of its own; a wall gets the
    // placeholder (the harness's rule). Where the host cannot fork (Windows):
    // `unsupported_option`.
    isolate,
    // The class's own load, in this process: a stub inside it fails the root
    // (`stub_reached`), a trap ends the process.
    in_place,
    // Never load an inner resource: constructed, path set, not loaded.
    placeholder,
};

// `derived`: the save inverted from the load, never the game's code.
enum class SaveRoute { own, derived };

// One request the root's load made of the engine's resource manager.
struct InnerRequest {
    std::string class_name, path, via, outcome;
    unsigned mode = 0;
};

struct LoadOptions {
    // `cResource::mPath`; else derived from the file's path under `data_root`
    // (under the nearest ancestor with a sibling `.arc`).
    const char* game_path = nullptr;
    // The `rom` folder. The inner files resolve under the root's archive
    // directory: the file's path less its game path, else `data_root`.
    const char* data_root = nullptr;
    InnerLoads inner = InnerLoads::isolate;
};

// The move-only owner of one root object.
class Resource {
public:
    Resource() = default;
    Resource(const Resource&) = delete;
    Resource& operator=(const Resource&) = delete;
    Resource(Resource&& other) noexcept;
    Resource& operator=(Resource&& other) noexcept;
    // The root's destroy hook (its class's virtual deleting destructor), which
    // releases its inner resources through `sResource`.
    ~Resource();
    explicit operator bool() const { return mObject != nullptr; }
    const char* root() const;
    // Include the class's header to use it as its type.
    cResource* get() const;

private:
    friend struct Access;
    const DdonRoot* mRoot = nullptr;
    void* mObject = nullptr;
};

struct LoadResult {
    Status status = Status::io_error;
    // Held only when `status` is `ok`: any other load is destroyed.
    Resource resource;
    std::uint32_t consumed = 0, size = 0, reads_at_end = 0;
    std::vector<std::string> stubs;
    std::vector<InnerRequest> inner;
    // The resources left in the manager's table after a failed load's
    // destroy; for an `ok` one, `destroy` returns it.
    unsigned inner_left_after_destroy = 0;
};

struct SaveResult {
    Status status = Status::no_save;
    SaveRoute route = SaveRoute::own;
    std::vector<unsigned char> bytes;
    std::vector<std::string> stubs;
};

// The supported roots, null-terminated.
const char* const* roots();
// The stubs reached before any load: static initializers and the engine's
// set-up (`MtCriticalSection::MtCriticalSection` today).
const std::vector<std::string>& setup_stubs();
LoadResult load_file(const char* root, const char* path, const LoadOptions& options = {});
LoadResult load_bytes(const char* root, const void* bytes, std::size_t size,
                      const LoadOptions& options = {});
// The own save first, else the derived one, marked by `route`.
SaveResult save(const Resource& resource);
// Destroys the root; returns the resources left in the manager's table.
unsigned destroy(Resource&& resource);

// Must not return; the default prints the name and ends the process with
// exit code 3. A trap cannot unwind under -fno-exceptions.
using TrapHandler = void (*)(const char* name);
void set_trap_handler(TrapHandler handler);

}  // namespace ddon
