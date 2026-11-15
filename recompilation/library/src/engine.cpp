// The engine fixtures. Each one is in
// fixture-boundary.txt with its reason. They stand in for engine services
// that do not interpret file bytes, and replace weak stubs only. The bundle
// links as an archive, so a member nothing else needs is never pulled in
// and a fixture of a name the bundle defines would replace its body without
// a duplicate definition: the harness refuses any fixture symbol the bundle
// defines strongly, so a proven body is never shadowed so.
// No system header here beyond the forced includes: the bundle declares
// the PS4 libc's types (e.g. `pthread_mutex_t`), which a glibc header parsed
// after it would contradict.

#include "MtAllocator.h"
#include "MtCRC.h"
#include "MtDTI.h"
#include "MtStream.h"
#include "runtime.h"
#include "sResource.h"

// The class registry: `MtDTI::MtDTI` 0xd61660 and
// `MtCRC::getCRC` 0xd7e390 are engine services whose bodies do not render,
// transcribed from the ELF's code. The constructor is a strong stub in the bundle
// (structors are never weak): the harness weakens it there only
// while the bundle refuses its body, so the
// fixture goes when the body renders.

namespace {

// The reflected CRC-32 table, polynomial 0xEDB88320; its values are the
// ELF's `MtCRC::mCRCtable` at 0x1c1af20 byte for byte (the harness's
// `crc_table_is_the_elfs` test).
struct CrcTable {
    u32 value[256];
};
constexpr CrcTable reflected_crc32() {
    CrcTable table{};
    for (u32 n = 0; n < 256; ++n) {
        u32 c = n;
        for (int k = 0; k < 8; ++k) {
            c = (c & 1) != 0 ? (c >> 1) ^ 0xEDB88320u : c >> 1;
        }
        table.value[n] = c;
    }
    return table;
}
constexpr CrcTable kCrc = reflected_crc32();

}  // namespace

#define DDON_CRC1(i) kCrc.value[i]
#define DDON_CRC4(i) DDON_CRC1(i), DDON_CRC1(i + 1), DDON_CRC1(i + 2), DDON_CRC1(i + 3)
#define DDON_CRC16(i) DDON_CRC4(i), DDON_CRC4(i + 4), DDON_CRC4(i + 8), DDON_CRC4(i + 12)
#define DDON_CRC64(i) DDON_CRC16(i), DDON_CRC16(i + 16), DDON_CRC16(i + 32), DDON_CRC16(i + 48)
// Not defined in the bundle (a const object whose value its unit's bodies
// would fold); 0xd7e39b reads it.
const u32 MtCRC::mCRCtable[256] = {DDON_CRC64(0), DDON_CRC64(64), DDON_CRC64(128), DDON_CRC64(192)};
#undef DDON_CRC64
#undef DDON_CRC16
#undef DDON_CRC4
#undef DDON_CRC1

// 0xd7e390: a byte at a time through the table, from `crc32`, with no final
// inversion; an empty string returns `crc32`.
u32 MtCRC::getCRC(MT_CTSTR str, u32 crc32) {
    for (; *str != 0; ++str) {
        crc32 = mCRCtable[static_cast<unsigned char>(crc32) ^ static_cast<unsigned char>(*str)] ^ (crc32 >> 8);
    }
    return crc32;
}

// The registry's root: the bundle leaves it undefined (no member-wise
// spelling), and 0xd616ee takes it for a class with no parent. Its proven
// default constructor (0xd61650) sets the vtable pointer only.
MtDTI MtDTI::mDTI;

// 0xd61660: the name; the size in 4-byte units, the attribute, the
// allocator index kept (0xd61693); no hash link; the name's CRC as the id
// when none is given (0xd616be); the allocator index; then the class joins
// the end of its parent's child list (`mDTI` without one) and the end of
// its hash slot's chain (the id's low byte).
MtDTI::MtDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr, u32 alloc_id) {
    mName = class_name;
    mSize = static_cast<u32>(size >> MTDTI_CLASSSIZE_BITSHIFT) & 0x7FFFFFu;
    mAttr = attr & 7u;
    mpLink = nullptr;
    if (id == 0) {
        id = MtCRC::getCRC(class_name, 0xFFFFFFFFu) & 0x7FFFFFFFu;
    }
    mID = id;
    mAllocatorIndex = alloc_id & 0x3Fu;
    if (ps == nullptr) {
        ps = &mDTI;
    }
    mpParent = ps;
    if (ps->mpChild != nullptr) {
        MtDTI* last = ps->mpChild;
        while (last->mpNext != nullptr) {
            last = last->mpNext;
        }
        last->mpNext = this;
        mpNext = nullptr;
    } else {
        ps->mpChild = this;
    }
    MtDTI** slot = &mpHashTable[static_cast<unsigned char>(id)];
    if (*slot != nullptr) {
        MtDTI* last = *slot;
        while (last->mpLink != nullptr) {
            last = last->mpLink;
        }
        last->mpLink = this;
    } else {
        *slot = this;
    }
}

namespace {

// The engine's heap, as the host's.
class HostAllocator final : public MtAllocator {
public:
    void* memAlloc(size_t size, u32 align) override { return ddon_game_alloc(size, align); }
    void* memAlloc(size_t size, u32 align, u32) override { return ddon_game_alloc(size, align); }
    void* memAlloc(size_t size, u32 align, u32, u32) override {
        return ddon_game_alloc(size, align);
    }
    void memFree(void* ptr) override { ddon_game_free(ptr); }
    size_t memSize(void* ptr) override { return ddon_host_size(ptr); }
};

// The engine's resource manager, as the host's: the harness loads
// one root's files, and an inner resource that load asks for is built and
// loaded as the ELF does, through its own class's `load`:
// - `create(MtStream&, const MtDTI&, MT_CTSTR, QUALITY)` (slot 13; ELF
//   0x126d910, an archive's entry over its decompressing stream): the class's
//   `newInstance`, its id, size (the stream's length), path and quality set,
//   then `load` on that stream and `loadEnd`; a load that fails is released
//   and the answer is nullptr.
// - `create(const MtDTI&, MT_CTSTR, u32)` (slot 12; ELF 0x126dd20), with mode
//   1, `loadBlocking` (0x126dfb0): the same from the file `<path>.<ext>`
//   (`getExt`), which the corpus holds beside the root's file under its
//   archive's directory; a load that fails, the instance deleted, nullptr.
//   Mode 0x80 answers nullptr on a miss, as the ELF does.
// - Either first looks the id (the class's id over the path's CRC) up in the
//   host's table of what it answered, and a hit raises its count.
// Each load runs first in a child of its own (`ddon_inner_trial`). Only one
// that ran clean (no stub reached, no trap, no crash, its instance deleted
// again) runs in the file's process, where the requests it makes take the
// verdicts their own trials gave in that child (the rerun is
// the same code from the same state); one that met a wall, and a request with
// no file in the corpus or a mode the host does not load, get the
// placeholder instead (constructed, path set, never loaded), so a gap of the
// reconstruction or the corpus is never an answer of the game's. Every
// request, its route and its outcome go into the file's record as a note
// that no outcome reads. `addRef` and `release` keep the instance's own
// count, and the last release destroys it through its virtual destructor.
// The manager has no other engine state: its vtable holds these at the slots
// the bundle's own declarations give them, and a trap at every other slot.

// Explicit instantiation ignores access ([temp.explicit]/14 in C++17): the
// resource's private members and the manager's protected `addRef` and
// `release`, named as DWARF names them.
template <auto Member, typename Tag>
struct Grant {
    friend constexpr auto member(Tag) { return Member; }
};
#define DDON_GRANT(Tag, Pointer)          \
    struct Tag {                          \
        friend constexpr auto member(Tag); \
    };                                    \
    template struct Grant<Pointer, Tag>
DDON_GRANT(PathOf, &cResource::mPath);
DDON_GRANT(RefCountOf, &cResource::mRefCount);
DDON_GRANT(AttrOf, &cResource::mAttr);
DDON_GRANT(SizeOf, &cResource::mSize);
DDON_GRANT(IdOf, &cResource::mID);
DDON_GRANT(LoadOf, &cResource::load);
DDON_GRANT(LoadEndOf, &cResource::loadEnd);
DDON_GRANT(AddRefOf, &sResource::addRef);
DDON_GRANT(ReleaseOf, &sResource::release);
#undef DDON_GRANT

// The resources the host answered with, alive: the ELF's table (`mpTable`,
// keyed by `mID`), which `host_release` also takes, and only these and what
// the game built itself.
constexpr unsigned kResources = 4096;
cResource* resources[kResources];
unsigned resource_count = 0;

cResource** resource_of(cResource* resource) {
    for (unsigned i = 0; i < resource_count; ++i) {
        if (resources[i] == resource) {
            return &resources[i];
        }
    }
    return nullptr;
}

cResource* resource_by_id(u64 id) {
    for (unsigned i = 0; i < resource_count; ++i) {
        if (resources[i]->*member(IdOf{}) == id) {
            return resources[i];
        }
    }
    return nullptr;
}

// The id the ELF's three lookups compute (0x126d910, 0x126dd20, 0x126d470):
// the path without a leading backslash and with each doubled backslash
// single, its CRC from 0xFFFFFFFF, under the class's id in the high word.
u64 resource_id(const MtDTI& dti, MT_CTSTR path) {
    char text[512];
    unsigned long n = 0;
    const char* from = path != nullptr && *path == '\\' ? path + 1 : path;
    char last = 0;
    for (; from != nullptr && *from != 0 && n + 1 < sizeof text; ++from) {
        if (*from != '\\' || last != '\\') {
            text[n++] = *from;
        }
        last = *from;
    }
    text[n] = 0;
    return (static_cast<u64>(dti.getID()) << 32) | MtCRC::getCRC(text, 0xFFFFFFFFu);
}

// `mState` and `mQuality` are bit-fields of the word after `mAttr` (DWARF:
// 0x50 and 0x54), which no member pointer names.
u32& state_word(cResource* resource) {
    return *(&(resource->*member(AttrOf{})) + 1);
}

void join_table(cResource* resource) {
    if (resource_count == kResources) {
        ddon_trap("sResource (host): more resources alive than the host keeps");
    }
    resources[resource_count++] = resource;
}

// The class's own instance, its id and path set (0x126d9fb, 0x126e000).
cResource* construct(const MtDTI& dti, MT_CTSTR path, u64 id) {
    MtObject* object = dti.newInstance();
    if (object == nullptr) {
        ddon_trap("sResource (host): the requested class's newInstance returned nullptr");
    }
    cResource* resource = static_cast<cResource*>(object);
    resource->*member(IdOf{}) = id;
    auto& to = resource->*member(PathOf{});
    unsigned long i = 0;
    for (; path != nullptr && path[i] != 0 && i + 1 < sizeof to; ++i) {
        to[i] = path[i];
    }
    to[i] = 0;
    return resource;
}

// The class's DTI is a static object its `.ctors` initializer builds; a
// bundle without that initializer leaves it zero (no vtable pointer, at
// offset 0 of a dynamic class: Itanium C++ ABI 2.4), so no `newInstance` can
// run: the request is the file's wall.
void require_constructed(const MtDTI& dti, MT_CTSTR path, const char* via, u32 mode) {
    void* vptr = nullptr;
    __builtin_memcpy(&vptr, &dti, sizeof vptr);
    if (vptr == nullptr) {
        ddon_inner_requested(nullptr, path, via, mode, "class not constructed");
        ddon_trap("sResource (host): the requested class's MtDTI is not constructed (its static initializer is not in the bundle)");
    }
}

// `cResource::release` (0xe5e8f0) is the manager's, below.
void host_release(sResource*, cResource* resource);

// The ELF's load counter (`(n << 11) + 2048` into the state word's high bits):
// the host's own, one per process.
u32 loads_done = 0;

void mark_loaded(cResource* resource) {
    u32& word = state_word(resource);
    word |= 1u;
    word = ((++loads_done) << 11) | (word & 0x7FFu);
}

// One inner load as the ELF runs it.
struct InnerLoad {
    const MtDTI* dti;
    MT_CTSTR path;
    u64 id;
    // The archive's stream (slot 13), or null for a file (slot 12).
    MtStream* in;
    u32 mode;
    u32 quality;
};

enum class Loaded { yes, refused, no_file };

// 0x126d9fb-0x126dc3d: the instance joins the table before its load; a load
// that fails releases it.
Loaded load_from_stream(const InnerLoad& request, cResource*& answer) {
    cResource* resource = construct(*request.dti, request.path, request.id);
    MtStream& in = *request.in;
    resource->*member(SizeOf{}) = in.getLength();
    resource->*member(AttrOf{}) |= 0x80u;
    u32& word = state_word(resource);
    word = ((request.quality & 7u) << 8) | (word & 0xFFFFF8FFu);
    join_table(resource);
    ddon_inner_created();
    if (resource->*member(SizeOf{}) != 0 && (resource->*member(LoadOf{}))(in)
        && (resource->*member(LoadEndOf{}))()) {
        mark_loaded(resource);
        answer = resource;
        return Loaded::yes;
    }
    host_release(nullptr, resource);
    answer = nullptr;
    return Loaded::refused;
}

// 0x126dfb0 (`loadBlocking`): the quality from the mode's bits, the file
// `<path>.<ext>`; a load that fails, or no file, deletes the instance; one
// that loads joins the table.
Loaded load_from_file(const InnerLoad& request, cResource*& answer) {
    answer = nullptr;
    cResource* resource = construct(*request.dti, request.path, request.id);
    u32 quality = (request.mode & 0x8000u) ? 1024u
                  : (request.mode & 0x4000u) ? 768u
                  : (request.mode & 0x2000u) ? 256u
                                             : (~(request.mode >> 3) & 0x200u);
    u32& word = state_word(resource);
    word = quality | (word & 0xFFFFF8FFu);
    MtStream* in = ddon_inner_file(request.path, resource->getExt());
    if (in == nullptr) {
        delete static_cast<MtObject*>(resource);
        return Loaded::no_file;
    }
    resource->*member(SizeOf{}) = in->getLength();
    bool loaded = resource->*member(SizeOf{}) != 0 && (resource->*member(LoadOf{}))(*in)
                  && (resource->*member(LoadEndOf{}))();
    ddon_inner_file_close(in);
    if (!loaded) {
        delete static_cast<MtObject*>(resource);
        return Loaded::refused;
    }
    mark_loaded(resource);
    join_table(resource);
    ddon_inner_created();
    answer = resource;
    return Loaded::yes;
}

Loaded run_inner(const InnerLoad& request, cResource*& answer) {
    return request.in != nullptr ? load_from_stream(request, answer)
                                 : load_from_file(request, answer);
}

// The trial's child: the whole load and, when it loaded, the release that
// destroys it, so a wall in either stays there.
int trial(void* context) {
    cResource* answer = nullptr;
    Loaded loaded = run_inner(*static_cast<const InnerLoad*>(context), answer);
    if (answer != nullptr) {
        host_release(nullptr, answer);
    }
    return loaded == Loaded::yes ? 0 : loaded == Loaded::refused ? 1 : 2;
}

// A clean trial's rerun in the file's process, which keeps its answer.
struct Rerun {
    const InnerLoad* request;
    cResource* answer;
    Loaded loaded;
};

int rerun(void* context) {
    Rerun& state = *static_cast<Rerun*>(context);
    state.loaded = run_inner(*state.request, state.answer);
    return 0;
}

// The placeholder: the class's own instance, constructed and never
// loaded, in the table.
cResource* placeholder(const InnerLoad& request) {
    cResource* resource = construct(*request.dti, request.path, request.id);
    join_table(resource);
    ddon_inner_created();
    return resource;
}

// A request the table does not hold: its trial, then the load or the
// placeholder, recorded.
cResource* answer_request(const InnerLoad& request, const char* via) {
    const char* name = request.dti->getName();
    char wall[512];
    const DdonInnerKey key{name, request.path, via, request.mode};
    DdonInnerTrial tried = ddon_inner_trial(key, &trial, const_cast<InnerLoad*>(&request), wall,
                                            sizeof wall);
    if (tried == DdonInnerTrial::loaded || tried == DdonInnerTrial::refused) {
        Rerun state{&request, nullptr, Loaded::no_file};
        ddon_inner_rerun(&rerun, &state);
        ddon_inner_requested(name, request.path, via, request.mode,
                             state.loaded == Loaded::yes ? "loaded"
                             : state.loaded == Loaded::refused ? "load returned false"
                                                               : "no file");
        return state.answer;
    }
    char outcome[600] = "placeholder: ";
    const char* why = tried == DdonInnerTrial::no_file ? "no file in the corpus" : wall;
    unsigned long n = __builtin_strlen(outcome);
    for (unsigned long i = 0; why[i] != 0 && n + 1 < sizeof outcome; ++i) {
        outcome[n++] = why[i];
    }
    outcome[n] = 0;
    ddon_inner_requested(name, request.path, via, request.mode, outcome);
    return placeholder(request);
}

// A hit in the table: its count raised (0x126dc6b).
cResource* found(cResource* resource, const MtDTI& dti, MT_CTSTR path, const char* via, u32 mode) {
    ++(resource->*member(RefCountOf{}));
    ddon_inner_requested(dti.getName(), path, via, mode, "found");
    return resource;
}

cResource* host_create(sResource*, const MtDTI& dti, MT_CTSTR path, u32 mode) {
    require_constructed(dti, path, "file", mode);
    u64 id = resource_id(dti, path);
    if (cResource* hit = resource_by_id(id)) {
        return found(hit, dti, path, "file", mode);
    }
    if ((mode & 0x80u) != 0) {
        ddon_inner_requested(dti.getName(), path, "file", mode, "not loaded (mode 0x80)");
        return nullptr;
    }
    InnerLoad request{&dti, path, id, nullptr, mode, 0};
    if ((mode & 0x203u) != 1u) {
        // precreate (0x200) and the asynchronous load (2): the host has
        // neither.
        ddon_inner_requested(dti.getName(), path, "file", mode, "placeholder: a mode the host does not load");
        return placeholder(request);
    }
    cResource* answer = answer_request(request, "file");
    if (answer != nullptr && (mode & 0x100u) != 0) {
        answer->*member(AttrOf{}) |= 0x800u;
    }
    return answer;
}

cResource* host_create_from_stream(sResource*, MtStream& in, const MtDTI& dti, MT_CTSTR path,
                                   cResource::QUALITY quality) {
    require_constructed(dti, path, "stream", static_cast<u32>(quality));
    u64 id = resource_id(dti, path);
    if (cResource* hit = resource_by_id(id)) {
        return found(hit, dti, path, "stream", static_cast<u32>(quality));
    }
    InnerLoad request{&dti, path, id, &in, static_cast<u32>(quality), static_cast<u32>(quality)};
    return answer_request(request, "stream");
}

void host_add_ref(sResource*, cResource* resource) {
    if (resource_of(resource) == nullptr) {
        ddon_trap("sResource (host): addRef of a resource the host did not create");
    }
    ++(resource->*member(RefCountOf{}));
}

void host_release(sResource*, cResource* resource) {
    cResource** slot = resource_of(resource);
    if (slot == nullptr) {
        // A resource the game built itself through the engine's allocators
        // (`new (16u) rRegionBreakInfo()`, ELF 0x6e3170; rObjCollision's three
        // tables), alive by its block: `cResource::cResource`
        // starts its count at 1, and its owner's destructor releases it through
        // the manager (0xe5e8f0). Anything else, a block already freed among
        // them, is no resource here. The block's table is the only test: this
        // reads the object only after it.
        if (!ddon_game_allocated(resource)) {
            ddon_trap("sResource (host): release of a resource the host did not create");
        }
        auto& count = resource->*member(RefCountOf{});
        if (count <= 0) {
            ddon_trap("sResource (host): release of a game-built resource whose count is already zero");
        }
        if (--count == 0) {
            delete static_cast<MtObject*>(resource);
        }
        return;
    }
    // 0x126b420: the last release leaves the table, then deletes.
    if (--(resource->*member(RefCountOf{})) > 0) {
        return;
    }
    *slot = resources[--resource_count];
    ddon_inner_released();
    // `MtObject`'s destructor is public and virtual: the class's own
    // deleting destructor runs.
    delete static_cast<MtObject*>(resource);
}

// `sResource::create(u64 id)` (slot 14; ELF 0x126e630, sResource.cpp:4177-4196)
// returns the resource of the id table at +0x8048 whose `mID` (+0x60) is `id`
// and whose state has no 0x50 bit, with its count raised, and nullptr when the
// table holds no match: here, the host's table of what it answered (an ARCS
// archive's 8-byte keys find nothing at a file's start).
cResource* host_create_by_id(sResource*, u64 id) {
    cResource* resource = resource_by_id(id);
    if (resource != nullptr) {
        ++(resource->*member(RefCountOf{}));
    }
    return resource;
}

[[noreturn]] void host_resources_other(sResource*) {
    ddon_trap("sResource (host): a virtual other than create(MtStream&, const MtDTI&, MT_CTSTR, QUALITY), create(const MtDTI&, MT_CTSTR, u32), create(u64), addRef or release");
}

// More slots than `sResource`'s vtable has; each slot the host fills is
// checked against it.
constexpr unsigned long kHostSlots = 64;
// Offset to top and the type information, then the slots.
void* host_resources_vtable[2 + kHostSlots];
alignas(16) unsigned char host_resources[sizeof(sResource)];

// The vtable slot of a virtual member function of `sResource`.
template <typename Pointer>
unsigned long slot_of(Pointer pointer, const char* trap) {
    // Itanium C++ ABI 2.3: a pointer to a virtual member function holds 1
    // plus the function's byte offset in the vtable.
    struct MemberPointer {
        unsigned long ptr;
        long adj;
    } bits;
    static_assert(sizeof bits == sizeof pointer, "an Itanium member function pointer");
    __builtin_memcpy(&bits, &pointer, sizeof bits);
    unsigned long slot = (bits.ptr - 1) / sizeof(void*);
    if ((bits.ptr & 1) == 0 || bits.adj != 0 || slot >= kHostSlots) {
        ddon_trap(trap);
    }
    return slot;
}

}  // namespace

// `sResource::mpInstance` is private; set by symbol, as the allocator table.
extern sResource* ddon_resource_manager __asm__("_ZN9sResource10mpInstanceE");

namespace {

void host_resources_init() {
    using Create = cResource* (sResource::*)(const MtDTI&, MT_CTSTR, u32);
    using Reference = void (sResource::*)(cResource*);
    using CreateById = cResource* (sResource::*)(u64);
    using CreateFromStream =
        cResource* (sResource::*)(MtStream&, const MtDTI&, MT_CTSTR, cResource::QUALITY);
    unsigned long create = slot_of(Create{&sResource::create},
        "sResource (host): create(const MtDTI&, MT_CTSTR, u32) is no virtual of sResource");
    unsigned long create_from_stream = slot_of(CreateFromStream{&sResource::create},
        "sResource (host): create(MtStream&, const MtDTI&, MT_CTSTR, QUALITY) is no virtual of sResource");
    unsigned long create_by_id = slot_of(CreateById{&sResource::create},
        "sResource (host): create(u64) is no virtual of sResource");
    unsigned long add_ref = slot_of(Reference{member(AddRefOf{})},
        "sResource (host): addRef(cResource*) is no virtual of sResource");
    unsigned long release = slot_of(Reference{member(ReleaseOf{})},
        "sResource (host): release(cResource*) is no virtual of sResource");
    for (unsigned long i = 0; i < kHostSlots; ++i) {
        host_resources_vtable[2 + i] = reinterpret_cast<void*>(&host_resources_other);
    }
    host_resources_vtable[2 + create] = reinterpret_cast<void*>(&host_create);
    host_resources_vtable[2 + create_from_stream] = reinterpret_cast<void*>(&host_create_from_stream);
    host_resources_vtable[2 + create_by_id] = reinterpret_cast<void*>(&host_create_by_id);
    host_resources_vtable[2 + add_ref] = reinterpret_cast<void*>(&host_add_ref);
    host_resources_vtable[2 + release] = reinterpret_cast<void*>(&host_release);
    void* vptr = &host_resources_vtable[2];
    __builtin_memcpy(host_resources, &vptr, sizeof vptr);
    ddon_resource_manager = reinterpret_cast<sResource*>(host_resources);
}

}  // namespace

// `MtMemory::mpAllocatorType` is private; the fixture sets its storage by
// symbol, so the engine's own reads of it (the rendered
// `MtMemoryAllocator::getAllocator` among them) find the host allocator.
extern MtAllocator* ddon_allocator_types[64] __asm__("_ZN8MtMemory15mpAllocatorTypeE");

// `MtString::mpAllocator`, which the bundle leaves undefined (relocated
// bytes) and every string body reads. The game's startup sets it in
// `MtMemoryAllocator::setDefaultAppAllocator()` (0x5adb80): at 0x5b0e6d
// `mov 0x10(MtMemory::mpAllocatorType),%rax; mov %rax,MtString::mpAllocator`,
// the table's entry 2. Defined here by symbol (it is
// private), set from the same entry below.
MtAllocator* ddon_string_allocator __asm__("_ZN8MtString11mpAllocatorE") = nullptr;

// `MtFile::mpPathDriveTypeFunc` (a fixture, with `sFile` left out of the
// reconstruction). `_GLOBAL__sub_I_sFile.cpp`
// (0xe48fc0) installs `sFile::getDriveType` (0xe48940) in the ELF; this one
// gives its answers for a path's prefix: the drive, the bytes the prefix takes
// and the native mount. It departs from the ELF where `sFile`'s state decides:
// the temp and download mounts are empty, so an absolute path under them is
// HOME and `cache:` and `download:` mount at "", and `sFile::isDownloadFile`
// answers false (no download drive). Only where a bundle has the class: a
// `--root` bundle may not.
#if __has_include("MtFile.h")
#include "MtFile.h"

namespace {

bool host_is_separator(char c) { return c == '/' || c == '\\'; }

bool host_is_digit(char c) { return c >= '0' && c <= '9'; }

// `/addcont` and one digit, or two up to 63, before a separator
// (0xe48940's `/addcont` test).
bool host_addcont_path(const char* path) {
    if (__builtin_strncmp(path, "/addcont", 8) != 0 || !host_is_digit(path[8])) {
        return false;
    }
    if (host_is_separator(path[9])) {
        return true;
    }
    if (!host_is_separator(path[10])) {
        return false;
    }
    return path[8] <= '5' ? host_is_digit(path[9])
                          : path[8] == '6' && path[9] >= '0' && path[9] <= '3';
}

void host_drive_type(MT_CTSTR path, MtFile::DRIVETYPE& type, u32& offset, MT_STR mount) {
    struct Prefix {
        const char* text;
        u32 length;
        MtFile::DRIVETYPE type;
        const char* mount;
        bool separator;  // A separator must follow it, and it holds no `:`.
    };
    static const Prefix prefixes[] = {
        {"app0:", 5, MtFile::DRIVETYPE_APP, "/app0", false},
        {"cache:", 6, MtFile::DRIVETYPE_TEMP, "", false},
        {"download:", 9, MtFile::DRIVETYPE_DOWNLOAD, "", false},
        {"abs:", 4, MtFile::DRIVETYPE_ABS, "", false},
        {"avcont:", 7, MtFile::DRIVETYPE_AVCONTENTS, "/av_contents/content_tmp", false},
        {"addcont:", 8, MtFile::DRIVETYPE_ADDCONT, "/addcont", false},
        {"/app0", 5, MtFile::DRIVETYPE_APP, "/app0", true},
        {"/av_contents/content_tmp", 24, MtFile::DRIVETYPE_AVCONTENTS, "/av_contents/content_tmp",
         true},
    };
    Prefix answer{"", 0, MtFile::DRIVETYPE_HOME, "/app0", false};
    for (const Prefix& prefix : prefixes) {
        if (__builtin_strncmp(path, prefix.text, prefix.length) == 0
            && (!prefix.separator || host_is_separator(path[prefix.length]))) {
            answer = prefix;
            break;
        }
    }
    if (answer.length == 0 && host_addcont_path(path)) {
        answer = Prefix{"", 8, MtFile::DRIVETYPE_ADDCONT, "/addcont", false};
    }
    type = answer.type;
    offset = answer.length;
    if (mount != nullptr) {
        __builtin_strcpy(mount, answer.mount);
    }
}

}  // namespace

MtFile::PATH_DRIVETYPE_FUNC ddon_path_drive_type
    __asm__("_ZN6MtFile19mpPathDriveTypeFuncE") = &host_drive_type;
#endif

// `rArchive::mpGetCipherKey`: the getter the PC
// client installs at run time. rArchive::load (0x11c1370, rArchive.cpp:2488)
// calls it for an ARCC archive and hands its key to MtCipher::setKeyString;
// nothing in the PS4 ELF sets it (its three references are loads in that
// function, no relocation names it), so the PS4 build reads no ARCC table.
// The key is a host fact, never game code: the PC client's public key, the
// same text as ddon-extractor's BlowFishUtil, and it decodes 16,923 of the corpus's
// 16,923 ARCC entry tables (319,556 entries, names zero-padded, offset plus
// size inside the file).
// The bundle defines the pointer; the fixture only sets it. Only where a
// bundle has the class: a `--root` bundle may not.
#if __has_include("rArchive.h")
#include "rArchive.h"

namespace {

bool host_cipher_key(rArchive::CIPHER_KEY& key, rArchive*) {
    static const char text[] = "ABB(DF2I8[{Y-oS_CCMy(@<}qR}WYX11M)w[5V.~CbjwM5q<F1Iab+-";
    static_assert(sizeof(text) <= sizeof(key.key), "the key and its NUL fit CIPHER_KEY");
    __builtin_memset(key.key, 0, sizeof(key.key));
    __builtin_memcpy(key.key, text, sizeof(text));
    return true;
}

}  // namespace

extern rArchive::cipher_cb ddon_archive_cipher_key __asm__("_ZN8rArchive14mpGetCipherKeyE");
#endif

// No body in the bundle (inline-only in the ELF), and the host allocator's
// base: its members are the engine's bookkeeping, unused by the host heap.
MtAllocator::MtAllocator() {}

void ddon_fixtures_init() {
    // Built before any file runs: its base constructor may be a stub, which
    // must not count against a file.
    static HostAllocator host;
    for (auto& allocator : ddon_allocator_types) {
        allocator = &host;
    }
    ddon_string_allocator = ddon_allocator_types[2];
#if __has_include("rArchive.h")
    ddon_archive_cipher_key = &host_cipher_key;
#endif
    host_resources_init();
}
