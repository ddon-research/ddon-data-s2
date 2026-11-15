// The load/save library's API: a root's file over a
// memory stream through the game's own `load`, its game path in
// `cResource::mPath` first, and the result's status by the library's `ok`
// rule: load returned true, every byte consumed, no stub reached, and no read
// that returned bytes after a read at the end. The harness's attribution of
// `MtDataReader`'s refill is not reproduced: `reads_at_end` is a note.

#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>
#include <system_error>
#include <utility>
#include <vector>

#include "isolate.h"
#include "session.h"

namespace ddon {

namespace {

// Reads asked at the end before the load ends as a trap (the harness's cap:
// a skip by a wrapped count looped 4.29e9 times).
constexpr unsigned kEndReads = 65536;

}  // namespace

u32 MemoryStream::read(void* ptr, u32 bytes) {
    if (mWritable) {
        misused = true;
        return 0;
    }
    if (bytes != 0 && mPos >= getLength() && ++reads_at_end >= kEndReads) {
        ddon_trap("the input stream: 65536 reads at the end");
    }
    u32 left = getLength() - mPos;
    u32 n = bytes < left ? bytes : left;
    read_after_end |= n != 0 && reads_at_end != 0;
    if (n != 0) {
        std::memcpy(ptr, mBytes.data() + mPos, n);
    }
    mPos += n;
    return n;
}

u32 MemoryStream::write(const void* ptr, u32 bytes) {
    if (!mWritable) {
        misused = true;
        return 0;
    }
    if (bytes == 0) {
        return 0;
    }
    std::size_t end = static_cast<std::size_t>(mPos) + bytes;
    if (end > mBytes.size()) {
        mBytes.resize(end);
    }
    std::memcpy(mBytes.data() + mPos, ptr, bytes);
    mPos = static_cast<u32>(end);
    return bytes;
}

// A seek outside the bytes is clamped and noted: `MtDataReader`'s destructor
// seeks back by what its buffer did not use, so a reader that read past the
// end asks for a target past it.
u32 MemoryStream::seek(s32 offset, MtStream::SEEK_ORIGIN origin) {
    // `std::int64_t`, not `long long`: the Windows build's forced include
    // spells the reconstruction's `long` as `long long` (windows-lp64.h).
    std::int64_t length = static_cast<std::int64_t>(mBytes.size());
    std::int64_t base = origin == ORG_BEGIN ? 0 : origin == ORG_CURRENT ? mPos : length;
    std::int64_t target = base + offset;
    if (target < 0 || target > length) {
        misused = true;
        target = target < 0 ? 0 : length;
    }
    mPos = static_cast<u32>(target);
    return mPos;
}

// The private members the API's functions reach.
struct Access {
    static Resource make(const DdonRoot* root, void* object) {
        Resource resource;
        resource.mRoot = root;
        resource.mObject = object;
        return resource;
    }
    static const DdonRoot* root(const Resource& resource) { return resource.mRoot; }
    static void* object(const Resource& resource) { return resource.mObject; }
    static void* take(Resource& resource) {
        void* object = resource.mObject;
        resource.mObject = nullptr;
        return object;
    }
};

namespace {

// The root's destroy hook in an entry of its own; its stubs go nowhere (no
// result carries them). Returns the resources left in the manager's table.
unsigned destroy_object(const DdonRoot& root, void* object) {
    std::vector<std::string> stubs;
    std::vector<InnerRequest> inner;
    session::Entry entry;
    entry.stubs = &stubs;
    entry.inner = &inner;
    session::begin(entry);
    root.destroy(object);
    session::end();
    return session::inner_alive();
}

const DdonLibraryRoot* find_root(const char* name) {
    if (name == nullptr) {
        return nullptr;
    }
    for (const DdonLibraryRoot* const* at = ddon_library_roots; *at != nullptr; ++at) {
        if (std::strcmp((*at)->root->name, name) == 0) {
            return *at;
        }
    }
    return nullptr;
}

std::string slashed(const char* path) {
    std::string text = path != nullptr ? path : "";
    for (char& c : text) {
        if (c == '\\') {
            c = '/';
        }
    }
    while (text.size() > 1 && text.back() == '/') {
        text.pop_back();
    }
    return text;
}

// The text before the last component's extension.
std::string without_extension(const std::string& file) {
    std::size_t dot = file.rfind('.');
    std::size_t slash = file.rfind('/');
    return dot != std::string::npos && (slash == std::string::npos || dot > slash)
               ? file.substr(0, dot)
               : file;
}

bool is_file(const std::string& path) {
    std::error_code error;
    return std::filesystem::is_regular_file(path, error);
}

// Where the root's game path and its inner files come from.
struct Placement {
    std::string game_path;
    std::string archive_dir;
};

// The file's game path: its path under the nearest ancestor
// below `data` with a sibling `<name>.arc`, else under `data`, without its
// extension and with backslashes; that ancestor is the archive directory.
Placement derived_placement(const std::string& file, const std::string& data) {
    Placement placement;
    if (data.empty() || file.size() <= data.size() + 1 || file.compare(0, data.size(), data) != 0
        || file[data.size()] != '/') {
        return placement;
    }
    std::string root = data;
    for (std::size_t slash = file.rfind('/'); slash != std::string::npos && slash > data.size();
         slash = file.rfind('/', slash - 1)) {
        std::string ancestor = file.substr(0, slash);
        if (is_file(ancestor + ".arc")) {
            root = ancestor;
            break;
        }
    }
    placement.game_path = without_extension(file).substr(root.size() + 1);
    for (char& c : placement.game_path) {
        if (c == '/') {
            c = '\\';
        }
    }
    placement.archive_dir = root + "/";
    return placement;
}

// A given game path: the archive directory is the file's path less its
// extension less that game path (the harness's `ddon_inner_file`), else
// `data`.
Placement given_placement(const std::string& file, const char* game, const std::string& data) {
    Placement placement;
    placement.game_path = game;
    std::string stem = without_extension(file);
    std::string wanted = slashed(game);
    if (!file.empty() && !wanted.empty() && stem.size() > wanted.size()
        && stem.compare(stem.size() - wanted.size(), wanted.size(), wanted) == 0) {
        placement.archive_dir = stem.substr(0, stem.size() - wanted.size());
    } else if (!data.empty()) {
        placement.archive_dir = data + "/";
    }
    return placement;
}

LoadResult run_load(const DdonLibraryRoot& entry_root, std::vector<unsigned char> bytes,
                    const Placement& placement, InnerLoads inner) {
    LoadResult result;
    const DdonRoot& root = *entry_root.root;
    session::set_up();
    session::Entry entry;
    entry.stubs = &result.stubs;
    entry.inner = &result.inner;
    entry.inner_loads = inner;
    entry.archive_dir = placement.archive_dir;
    session::begin(entry);
    MemoryStream in(bytes, false);
    void* object = root.create();
    if (entry_root.place_path != nullptr && !placement.game_path.empty()) {
        entry_root.place_path(object, placement.game_path.c_str());
    }
    bool loaded = root.load(object, in);
    result.consumed = in.getPosition();
    result.size = static_cast<std::uint32_t>(bytes.size());
    result.reads_at_end = in.reads_at_end;
    session::end();
    if (!result.stubs.empty()) {
        result.status = Status::stub_reached;
    } else if (!loaded) {
        result.status = Status::load_returned_false;
    } else if (result.consumed != result.size || in.read_after_end || in.misused) {
        result.status = Status::not_whole;
    } else {
        result.status = Status::ok;
    }
    if (result.status == Status::ok) {
        result.resource = Access::make(&root, object);
    } else {
        result.inner_left_after_destroy = destroy_object(root, object);
    }
    return result;
}

LoadResult refused(Status status) {
    LoadResult result;
    result.status = status;
    return result;
}

}  // namespace

Resource::Resource(Resource&& other) noexcept : mRoot(other.mRoot), mObject(other.mObject) {
    other.mObject = nullptr;
}

Resource& Resource::operator=(Resource&& other) noexcept {
    if (this != &other) {
        if (mObject != nullptr) {
            destroy_object(*mRoot, mObject);
        }
        mRoot = other.mRoot;
        mObject = other.mObject;
        other.mObject = nullptr;
    }
    return *this;
}

Resource::~Resource() {
    if (mObject != nullptr) {
        destroy_object(*mRoot, mObject);
    }
}

const char* Resource::root() const { return mRoot != nullptr ? mRoot->name : nullptr; }

cResource* Resource::get() const { return static_cast<cResource*>(mObject); }

const char* status_name(Status status) {
    switch (status) {
    case Status::ok: return "ok";
    case Status::load_returned_false: return "load returned false";
    case Status::not_whole: return "not whole";
    case Status::stub_reached: return "stub reached";
    case Status::unknown_root: return "unknown root";
    case Status::format_differs: return "format differs";
    case Status::no_save: return "no save";
    case Status::save_returned_false: return "save returned false";
    case Status::save_used_stream: return "save used its stream";
    case Status::unsupported_option: return "unsupported option";
    case Status::io_error: return "io error";
    }
    return "unknown status";
}

const char* const* roots() {
    static std::vector<const char*> names;
    if (names.empty()) {
        for (const DdonLibraryRoot* const* at = ddon_library_roots; *at != nullptr; ++at) {
            names.push_back((*at)->root->name);
        }
        names.push_back(nullptr);
    }
    return names.data();
}

const std::vector<std::string>& setup_stubs() {
    session::set_up();
    return session::stubs_before_any_entry();
}

LoadResult load_file(const char* root, const char* path, const LoadOptions& options) {
    const DdonLibraryRoot* found = find_root(root);
    if (found == nullptr) {
        return refused(Status::unknown_root);
    }
    if (options.inner == InnerLoads::isolate && !isolate::supported()) {
        return refused(Status::unsupported_option);
    }
    std::ifstream in(path != nullptr ? path : "", std::ios::binary);
    if (!in) {
        return refused(Status::io_error);
    }
    std::vector<unsigned char> bytes((std::istreambuf_iterator<char>(in)),
                                     std::istreambuf_iterator<char>());
    std::string file = slashed(path);
    std::string data = slashed(options.data_root);
    Placement placement = options.game_path != nullptr
                              ? given_placement(file, options.game_path, data)
                              : derived_placement(file, data);
    return run_load(*found, std::move(bytes), placement, options.inner);
}

LoadResult load_bytes(const char* root, const void* bytes, std::size_t size,
                      const LoadOptions& options) {
    const DdonLibraryRoot* found = find_root(root);
    if (found == nullptr) {
        return refused(Status::unknown_root);
    }
    if (options.inner == InnerLoads::isolate && !isolate::supported()) {
        return refused(Status::unsupported_option);
    }
    if (bytes == nullptr && size != 0) {
        return refused(Status::io_error);
    }
    const auto* first = static_cast<const unsigned char*>(bytes);
    std::vector<unsigned char> copy(first, first + size);
    Placement placement = options.game_path != nullptr
                              ? given_placement("", options.game_path, slashed(options.data_root))
                              : Placement{};
    if (options.game_path == nullptr && options.data_root != nullptr) {
        placement.archive_dir = slashed(options.data_root) + "/";
    }
    return run_load(*found, std::move(copy), placement, options.inner);
}

SaveResult save(const Resource& resource) {
    SaveResult result;
    const DdonRoot* root = Access::root(resource);
    void* object = Access::object(resource);
    if (root == nullptr || object == nullptr) {
        return result;
    }
    if (root->save == nullptr && root->derived_save == nullptr) {
        result.status = Status::no_save;
        return result;
    }
    bool (*writer)(void*, MtStream&) = root->save != nullptr ? root->save : root->derived_save;
    result.route = root->save != nullptr ? SaveRoute::own : SaveRoute::derived;
    std::vector<InnerRequest> inner;
    session::Entry entry;
    entry.stubs = &result.stubs;
    entry.inner = &inner;
    session::begin(entry);
    MemoryStream out(result.bytes, true);
    bool saved = writer(object, out);
    session::end();
    result.status = !result.stubs.empty() ? Status::stub_reached
                    : !saved              ? Status::save_returned_false
                    : out.misused         ? Status::save_used_stream
                                          : Status::ok;
    return result;
}

unsigned destroy(Resource&& resource) {
    Resource owned = std::move(resource);
    const DdonRoot* root = Access::root(owned);
    void* object = Access::take(owned);
    if (root == nullptr || object == nullptr) {
        return session::inner_alive();
    }
    return destroy_object(*root, object);
}

}  // namespace ddon
