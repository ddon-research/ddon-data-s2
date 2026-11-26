// The engine fixtures. Each one is in
// fixture-boundary.txt with its reason. They stand in for engine services
// that do not interpret file bytes, and replace weak stubs only. The bundle
// links as an archive, so a member nothing else needs is never pulled in
// and a fixture of a name the bundle defines would replace its body without
// a duplicate definition, and no fixture is a symbol the bundle
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
// (structors are never weak): this fixture stands in only
// while the bundle refuses its body, so the
// fixture goes when the body renders.

namespace {

// The reflected CRC-32 table, polynomial 0xEDB88320; its values are the
// ELF's `MtCRC::mCRCtable` at 0x1c1af20 byte for byte.
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
        crc32 = mCRCtable[static_cast<unsigned char>(crc32) ^ static_cast<unsigned char>(*str)] ^
                (crc32 >> 8);
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

// rMaterial's DTI by its symbol: null in a bundle without the class.
extern const MtDTI ddon_material_dti __asm__("_ZN9rMaterial3DTIE") __attribute__((weak));

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

// The engine's resource manager, as the host's: the library loads
// one root's files, and an inner resource that load asks for is built and
// loaded as the ELF does, through its own class's `load`:
// - `create(MtStream&, const MtDTI&, MT_CTSTR, QUALITY)` (slot 13; ELF
//   0x126d910, an archive's entry over its decompressing stream): the class's
//   `newInstance`, its id, size (the stream's length), path and quality set,
//   then `load` on that stream and `loadEnd`; a load that fails is released
//   and the answer is nullptr. A class the stage translates loads the staged
//   image of the stream's bytes instead (`staged_image`).
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
// placeholder instead (constructed, path set, never loaded), and so does a
// load that refuses the 32-bit PC client's XFS database or an archive entry's
// staged image, so a gap of the reconstruction or the corpus is never an answer of the game's.
// Every request, its route and its outcome go into the file's record as a note that no outcome
// reads. `addRef` and `release` keep the instance's own count, and the last release destroys it
// through its virtual destructor. The manager has no other engine state: its vtable holds these at
// the slots the bundle's own declarations give them, and a trap at every other slot.

// Explicit instantiation ignores access ([temp.explicit]/14 in C++17): the
// resource's private members and the manager's protected `addRef` and
// `release`, named as DWARF names them.
template <auto Member, typename Tag>
struct Grant {
    friend constexpr auto member(Tag) { return Member; }
};
#define DDON_GRANT(Tag, Pointer)           \
    struct Tag {                           \
        friend constexpr auto member(Tag); \
    };                                     \
    template struct Grant<Pointer, Tag>
DDON_GRANT(PathOf, &cResource::mPath);
DDON_GRANT(RefCountOf, &cResource::mRefCount);
DDON_GRANT(AttrOf, &cResource::mAttr);
DDON_GRANT(SizeOf, &cResource::mSize);
DDON_GRANT(IdOf, &cResource::mID);
DDON_GRANT(LoadOf, &cResource::load);
DDON_GRANT(LoadEndOf, &cResource::loadEnd);
DDON_GRANT(SaveOf, &cResource::save);
DDON_GRANT(AddRefOf, &sResource::addRef);
DDON_GRANT(ReleaseOf, &sResource::release);
// `DDON_GRANT` stays defined for rArchive's members, below.

#if __has_include("rArchive.h")
// rArchive's writer (below): what an archive's
// load asked of the manager, entry by entry, in the order it asked.
bool is_host_class(const MtDTI& dti);
void note_archive_entry(MtStream& in, const MtDTI& dti, MT_CTSTR path, u32 quality,
                        cResource* answer);
void note_archive_key(u64 id);
#endif

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
u32& state_word(cResource* resource) { return *(&(resource->*member(AttrOf{})) + 1); }

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
        ddon_trap(
            "sResource (host): the requested class's MtDTI is not constructed (its static "
            "initializer is not in the bundle)");
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

// What a request with no file does with the instance it constructed: deletes
// it, as the ELF does, or keeps it as the placeholder that answers (a load
// with no trial, which has no second instance to make).
enum class NoFile { delete_it, keep_it };

// What a request's stream holds from its position on, in host storage.
struct HeldBytes {
    unsigned char* data = nullptr;
    u32 size = 0;

    HeldBytes() = default;
    HeldBytes(const HeldBytes&) = delete;
    HeldBytes& operator=(const HeldBytes&) = delete;
    ~HeldBytes() { ddon_host_free(data); }
};

[[noreturn]] void entry_wall(const char* name, const char* why) {
    char text[200];
    unsigned long n = 0;
    for (const char* part : {name, " (host): ", why}) {
        for (; *part != 0 && n + 1 < sizeof text; ++part) {
            text[n++] = *part;
        }
    }
    text[n] = 0;
    ddon_trap(text);
}

// The staged translation of what `in` holds, for a class whose resources the
// PC client wrote in a 32-bit layout (`ddon_entry_translated`): an archive's
// entry, or a file the host read as the client wrote it. The archives are
// where the corpus's plain files come from (150,372 of 150,372 entries), so
// the image is the one the stage gives the plain file of the same bytes,
// found by their SHA-256. Failing closed: bytes no staged file has are the
// load's wall, since the class's load would take one layout for another.
MtStream* staged_image(MtStream& in, const char* name, MT_CTSTR ext) {
    HeldBytes bytes;
    bytes.size = in.getLength() - in.getPosition();
    bytes.data = static_cast<unsigned char*>(ddon_own_alloc(bytes.size != 0 ? bytes.size : 1, 16));
    if (bytes.data == nullptr) {
        entry_wall(name, "out of host storage");
    }
    if (in.read(bytes.data, bytes.size) != bytes.size) {
        entry_wall(name, "the stream gave less than its length");
    }
    MtStream* image = ddon_entry_image(bytes.data, bytes.size, ext);
    if (image == nullptr) {
        entry_wall(name, "no staged file has these bytes");
    }
    return image;
}

// The instance's own loadEnd. An rMaterial's that answers false is a wall and
// no answer of the game's: it looks its render states up in the shader package
// (0x11f3580, 142 objects by name) and its materials' classes in the registry,
// of which the host has some. Exit: those objects in the sShader2 fixture.
bool load_end(const InnerLoad& request, cResource* resource) {
    const bool ended = (resource->*member(LoadEndOf{}))();
    if (!ended && &ddon_material_dti != nullptr && request.dti == &ddon_material_dti) {
        ddon_trap("rMaterial (host): loadEnd found no render state or material class");
    }
    return ended;
}

// 0x126d9fb-0x126dc3d: the instance joins the table before its load; a load
// that fails releases it.
Loaded load_from_stream(const InnerLoad& request, cResource*& answer) {
    cResource* resource = construct(*request.dti, request.path, request.id);
    const char* name = request.dti->getName();
    MtStream* image =
        ddon_entry_translated(name) ? staged_image(*request.in, name, resource->getExt()) : nullptr;
    MtStream& in = image != nullptr ? *image : *request.in;
    resource->*member(SizeOf{}) = in.getLength();
    resource->*member(AttrOf{}) |= 0x80u;
    u32& word = state_word(resource);
    word = ((request.quality & 7u) << 8) | (word & 0xFFFFF8FFu);
    join_table(resource);
    ddon_inner_created();
    const bool loaded = resource->*member(SizeOf{}) != 0 && (resource->*member(LoadOf{}))(in) &&
                        load_end(request, resource);
    ddon_inner_file_close(image);
    if (loaded) {
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
Loaded load_from_file(const InnerLoad& request, cResource*& answer, NoFile no_file) {
    answer = nullptr;
    cResource* resource = construct(*request.dti, request.path, request.id);
    bool staged = true;
    MtStream* in = ddon_inner_file(request.path, resource->getExt(), &staged);
    if (in == nullptr && no_file == NoFile::keep_it) {
        join_table(resource);
        ddon_inner_created();
        answer = resource;
        return Loaded::no_file;
    }
    u32 quality = (request.mode & 0x8000u)   ? 1024u
                  : (request.mode & 0x4000u) ? 768u
                  : (request.mode & 0x2000u) ? 256u
                                             : (~(request.mode >> 3) & 0x200u);
    u32& word = state_word(resource);
    word = quality | (word & 0xFFFFF8FFu);
    if (in == nullptr) {
        delete static_cast<MtObject*>(resource);
        return Loaded::no_file;
    }
    // The stage gave its files in the PS4 layout; one read from the data tree
    // is as the PC client wrote it.
    const char* name = request.dti->getName();
    if (!staged && ddon_entry_translated(name)) {
        MtStream* image = staged_image(*in, name, resource->getExt());
        ddon_inner_file_close(in);
        in = image;
    }
    resource->*member(SizeOf{}) = in->getLength();
    bool loaded = resource->*member(SizeOf{}) != 0 && (resource->*member(LoadOf{}))(*in) &&
                  load_end(request, resource);
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

Loaded run_inner(const InnerLoad& request, cResource*& answer, NoFile no_file) {
    return request.in != nullptr ? load_from_stream(request, answer)
                                 : load_from_file(request, answer, no_file);
}

// The trial's child: the whole load and, when it loaded, the release that
// destroys it, so a wall in either stays there.
int trial(void* context) {
    cResource* answer = nullptr;
    Loaded loaded = run_inner(*static_cast<const InnerLoad*>(context), answer, NoFile::delete_it);
    if (answer != nullptr) {
        host_release(nullptr, answer);
    }
    return loaded == Loaded::yes ? 0 : loaded == Loaded::refused ? 1 : 2;
}

// Whether the stream's bytes are the PC client's XFS 15 database: its object
// table, right after the header, holds u32 offsets as the client wrote it, the
// first object's after the table itself, or the u64 offsets of a file the stage
// translated (the PS4 reader's entries, 0xdcb1f0; `xfs.rs` gives both
// layouts). The corpus holds no other database. Or they are rZone's container
// (its DATA_MAGIC and DATA_VERSION), whose contents and layouts are such
// databases at places only its load reaches (`xfs/zone.rs` walks all 3,141).
bool corpus_xfs(MtStream& in) {
    u32 head[8] = {};
    auto* bytes = reinterpret_cast<unsigned char*>(head);
    u32 got = 0;
    while (got < sizeof head) {
        u32 n = in.read(bytes + got, static_cast<u32>(sizeof head) - got);
        if (n == 0) {
            return false;
        }
        got += n;
    }
    if (head[0] == 7237498u && head[1] == 2016020100u) {
        return true;
    }
    const u32 objects = head[4];
    return head[0] == 0x00534658u && (head[1] & 0xFFFFu) == 15u && objects != 0 &&
           (head[6] == 4u * objects || (head[6] == 8u * objects && head[7] == 0));
}

// The child that looks at a request's bytes: 0 for an XFS database of the PC
// client's, staged or not.
int look(void* context) {
    const InnerLoad& request = *static_cast<const InnerLoad*>(context);
    if (request.in != nullptr) {
        return corpus_xfs(*request.in) ? 0 : 1;
    }
    cResource* resource = construct(*request.dti, request.path, request.id);
    MtStream* in = ddon_inner_file(request.path, resource->getExt(), nullptr);
    return in != nullptr && corpus_xfs(*in) ? 0 : 1;
}

// A clean trial's rerun in the file's process, which keeps its answer.
struct Rerun {
    const InnerLoad* request;
    cResource* answer;
    Loaded loaded;
    NoFile no_file;
};

int rerun(void* context) {
    Rerun& state = *static_cast<Rerun*>(context);
    state.loaded = run_inner(*state.request, state.answer, state.no_file);
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

// Whose load answered: a host class's is counted apart from the game's.
const char* loaded_by(const MtDTI& dti) {
#if __has_include("rArchive.h")
    if (is_host_class(dti)) {
        return "kept by a host class";
    }
#endif
    return "loaded";
}

// A request the table does not hold: its trial, then the load or the
// placeholder, recorded.
cResource* answer_request(const InnerLoad& request, const char* via) {
    const char* name = request.dti->getName();
    char wall[512];
    const DdonInnerKey key{name, request.path, via, request.mode};
    DdonInnerTrial tried =
        ddon_inner_trial(key, &trial, const_cast<InnerLoad*>(&request), wall, sizeof wall);
    const char* differs = nullptr;
    if (tried == DdonInnerTrial::refused && request.in != nullptr && ddon_entry_translated(name)) {
        // As below, for every format the stage translates: the PC client's
        // archives hold no entry it refuses, so a refusal of the host's image
        // is a gap of the reconstruction (a class the closure lacks).
        differs = "its load refused the staged image of the PC client's bytes";
    } else if (tried == DdonInnerTrial::refused) {
        // A load that refused the PC client's database refused the corpus's
        // format, or a class the host's closure lacks (MtDTI::from's null,
        // 0xdcb1f0), which is never an answer of the game's (a child looks,
        // so the stream stays where it is).
        char unread[512];
        const DdonInnerKey bytes{name, request.path, "format", request.mode};
        if (ddon_inner_trial(bytes, &look, const_cast<InnerLoad*>(&request), unread,
                             sizeof unread) == DdonInnerTrial::loaded) {
            differs = "format differs: the PC client's XFS 15 database";
        }
    }
    const bool direct = tried == DdonInnerTrial::direct;
    if (differs == nullptr &&
        (direct || tried == DdonInnerTrial::loaded || tried == DdonInnerTrial::refused)) {
        Rerun state{&request, nullptr, Loaded::no_file,
                    direct ? NoFile::keep_it : NoFile::delete_it};
        ddon_inner_rerun(&rerun, &state);
        if (direct && state.loaded == Loaded::refused) {
            // Only a refused trial leaves the stream for `look`: the file
            // runs again with a trial for every load.
            ddon_trap("sResource (host): a load with no trial returned false");
        }
        ddon_inner_requested(name, request.path, via, request.mode,
                             state.loaded == Loaded::yes       ? loaded_by(*request.dti)
                             : state.loaded == Loaded::refused ? "load returned false"
                             : direct ? "placeholder: no file in the corpus"
                                      : "no file");
        return state.answer;
    }
    char outcome[600] = "placeholder: ";
    const char* why = differs != nullptr                 ? differs
                      : tried == DdonInnerTrial::no_file ? "no file in the corpus"
                                                         : wall;
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
        ddon_inner_requested(dti.getName(), path, "file", mode,
                             "placeholder: a mode the host does not load");
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
    cResource* answer = nullptr;
    if (cResource* hit = resource_by_id(id)) {
        answer = found(hit, dti, path, "stream", static_cast<u32>(quality));
    } else {
        InnerLoad request{
            &dti, path, id, &in, static_cast<u32>(quality), static_cast<u32>(quality)};
        answer = answer_request(request, "stream");
    }
#if __has_include("rArchive.h")
    note_archive_entry(in, dti, path, static_cast<u32>(quality), answer);
#endif
    return answer;
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
            ddon_trap(
                "sResource (host): release of a game-built resource whose count is already zero");
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
#if __has_include("rArchive.h")
    note_archive_key(id);
#endif
    cResource* resource = resource_by_id(id);
    if (resource != nullptr) {
        ++(resource->*member(RefCountOf{}));
    }
    return resource;
}

[[noreturn]] void host_resources_other(sResource*) {
    ddon_trap(
        "sResource (host): a virtual other than create(MtStream&, const MtDTI&, MT_CTSTR, "
        "QUALITY), create(const MtDTI&, MT_CTSTR, u32), create(u64), addRef or release");
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

#if __has_include("MtProperty.h")
#include "MtProperty.h"

// `MtProperty::mpCustom` is private; set by symbol. `sResource::sResource`
// registers its `Property` there (0x126a269, the one call of
// `MtProperty`'s custom registration, 0xd625f0, which takes the first free entry), so
// a property of the custom type "resource" is TYPE_CUSTOM and its load and
// save go through `sResource::Property`.
extern MtProperty::Custom* ddon_property_customs[16] __asm__("_ZN10MtProperty8mpCustomE")
    __attribute__((weak));

namespace {

void host_resource_property_init() {
    if (&ddon_property_customs[0] != nullptr) {
        static sResource::Property property;
        ddon_property_customs[0] = &property;
    }
}

}  // namespace

#else

namespace {

void host_resource_property_init() {}

}  // namespace

#endif

namespace {

void host_resources_init() {
    host_resource_property_init();
    using Create = cResource* (sResource::*)(const MtDTI&, MT_CTSTR, u32);
    using Reference = void (sResource::*)(cResource*);
    using CreateById = cResource* (sResource::*)(u64);
    using CreateFromStream =
        cResource* (sResource::*)(MtStream&, const MtDTI&, MT_CTSTR, cResource::QUALITY);
    unsigned long create =
        slot_of(Create{&sResource::create},
                "sResource (host): create(const MtDTI&, MT_CTSTR, u32) is no virtual of sResource");
    unsigned long create_from_stream = slot_of(CreateFromStream{&sResource::create},
                                               "sResource (host): create(MtStream&, const MtDTI&, "
                                               "MT_CTSTR, QUALITY) is no virtual of sResource");
    unsigned long create_by_id = slot_of(
        CreateById{&sResource::create}, "sResource (host): create(u64) is no virtual of sResource");
    unsigned long add_ref =
        slot_of(Reference{member(AddRefOf{})},
                "sResource (host): addRef(cResource*) is no virtual of sResource");
    unsigned long release =
        slot_of(Reference{member(ReleaseOf{})},
                "sResource (host): release(cResource*) is no virtual of sResource");
    for (unsigned long i = 0; i < kHostSlots; ++i) {
        host_resources_vtable[2 + i] = reinterpret_cast<void*>(&host_resources_other);
    }
    host_resources_vtable[2 + create] = reinterpret_cast<void*>(&host_create);
    host_resources_vtable[2 + create_from_stream] =
        reinterpret_cast<void*>(&host_create_from_stream);
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
        if (__builtin_strncmp(path, prefix.text, prefix.length) == 0 &&
            (!prefix.separator || host_is_separator(path[prefix.length]))) {
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

MtFile::PATH_DRIVETYPE_FUNC ddon_path_drive_type __asm__("_ZN6MtFile19mpPathDriveTypeFuncE") =
    &host_drive_type;
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

// rArchive's container writer: a save the
// host writes, never the game's (the ELF writes no archive), run as the root's
// derived save with route `host` and counted apart from the game's own save.
// It writes the header from the loaded archive (`mbCrypted`, DATA_VERSION,
// `mResourceNum`), the table of contents from each entry's resource (path,
// class id, quality, sizes) and the host's notes of what the load asked
// (where each entry was), and each entry's bytes: a loaded resource whose
// class has a `save` of its own writes them, through its derived save where
// the bundle has one (`ddon_entry_save`: a class whose own save reads no
// member and writes no file, as rSwingModel's, which returns false). Where
// they are exactly what the load was given (what the entry's stored bytes
// inflate to, or that in the PS4 layout, `saves_back`), those stay: how
// the PC packer's zlib deflated them is no fact of the resource (the host's
// zlib 1.4 reproduces no level or memory setting of 34 of 36 measured
// rGUIMessage entries whose saved bytes are equal). Otherwise they are
// deflated (zlib's default level; host zlib) and padded to 8 bytes with
// zeros. Any other entry gets its stored bytes, kept as the load reached
// them, and so does a class the stage translates whose save does not give its
// image back: raw fills, each counted by class (`ddon_note_kept_entry`), so an
// archive's round trip shows its container and nothing of them. A derived save
// that puts an XFS file's own bytes back (`ddon_put_back_skipped`) is no entry's
// (driver.rs). An ARCC table and its entries are
// encrypted again with the game's own MtCipher under the host's key (above).
// An ARCS archive writes its 8-byte keys as the load asked for them. What the
// notes cannot answer (an entry the load never asked for, a quality the clamp
// hid) fails the save: nothing is guessed.
extern "C" int compress2(unsigned char* dest, unsigned long* dest_len, const unsigned char* source,
                         unsigned long source_len, int level);
extern "C" unsigned long compressBound(unsigned long source_len);
extern "C" int uncompress(unsigned char* dest, unsigned long* dest_len, const unsigned char* source,
                          unsigned long source_len);

// How an entry's resource is saved: its class's derived save, or null for
// the game's own. Defined by rArchive's driver where the bundle has one for a
// class with a `save` of its own (driver.rs); absent elsewhere.
using DdonEntrySave = bool (*)(const cResource&, MtStream&);
__attribute__((weak)) DdonEntrySave ddon_entry_save(const cResource& resource);

// The base `save` (cResource.cpp, returns false): a class whose vtable holds
// it has no save of its own.
extern bool ddon_base_save(cResource*, MtStream&) __asm__("_ZN9cResource4saveER8MtStream");

namespace {

DDON_GRANT(ArcResourcesOf, &rArchive::mpResource);
DDON_GRANT(ArcCountOf, &rArchive::mResourceNum);
DDON_GRANT(ArcEncryptedOf, &rArchive::mbCrypted);
DDON_GRANT(DecompressInOf, &rArchive::DecompressStream::mpIn);
DDON_GRANT(DecompressArcOf, &rArchive::DecompressStream::mpArc);
DDON_GRANT(DecompressOffsetOf, &rArchive::DecompressStream::mInOffset);
DDON_GRANT(DecompressDataSizeOf, &rArchive::DecompressStream::mDataSize);
DDON_GRANT(DecompressOrgSizeOf, &rArchive::DecompressStream::mOrgSize);
DDON_GRANT(CipherInOf, &rArchive::CipherStream::mpSt);

// A growable byte buffer in host storage.
struct Bytes {
    unsigned char* data = nullptr;
    unsigned long size = 0;
    unsigned long capacity = 0;

    void reserve(unsigned long wanted) {
        if (wanted <= capacity) {
            return;
        }
        unsigned long grown = capacity * 2 > wanted ? capacity * 2 : wanted;
        auto* next = static_cast<unsigned char*>(ddon_own_alloc(grown, 16));
        if (next == nullptr) {
            ddon_trap("rArchive's writer (host): out of host storage");
        }
        if (size != 0) {
            __builtin_memcpy(next, data, size);
        }
        ddon_host_free(data);
        data = next;
        capacity = grown;
    }
    void resize(unsigned long wanted) {
        reserve(wanted);
        if (wanted > size) {
            __builtin_memset(data + size, 0, wanted - size);
        }
        size = wanted;
    }
    void put(unsigned long at, const void* from, unsigned long n) {
        if (at + n > size) {
            resize(at + n);
        }
        if (n != 0) {
            __builtin_memcpy(data + at, from, n);
        }
    }
    void release() {
        ddon_host_free(data);
        data = nullptr;
        size = capacity = 0;
    }
};

// A save's sink: what it writes, in host storage; a read is no save's.
class SinkStream final : public MtStream {
public:
    explicit SinkStream(Bytes& bytes) : mBytes(bytes) {}
    bool isReadable() override { return false; }
    bool isWritable() override { return true; }
    bool isSeekable() override { return true; }
    bool isAsyncReadable() override { return false; }
    u32 getPosition() override { return mPos; }
    u32 read(void*, u32) override {
        mRead = true;
        return 0;
    }
    u32 readAsync(void* ptr, u32 bytes) override { return read(ptr, bytes); }
    bool isAsyncReading() const override { return false; }
    u32 write(const void* ptr, u32 bytes) override {
        mBytes.put(mPos, ptr, bytes);
        mPos += bytes;
        return bytes;
    }
    u32 getLength() override { return static_cast<u32>(mBytes.size); }
    u32 seek(s32 offset, MtStream::SEEK_ORIGIN origin) override {
        // `long`, 8 bytes on every route with no system header (above): the PS4 and the
        // host are LP64, and the export's Windows build spells it `long long`
        // (windows-lp64.h), which a `long long` here would double (031 EXPORT-LP64-1).
        long base = origin == ORG_BEGIN ? 0 : origin == ORG_CURRENT ? mPos : mBytes.size;
        long target = base + offset;
        if (target < 0 || target > static_cast<long>(mBytes.size)) {
            mRead = true;
            target = target < 0 ? 0 : static_cast<long>(mBytes.size);
        }
        mPos = static_cast<u32>(target);
        return mPos;
    }
    void skip(u32 size) override { seek(static_cast<s32>(size), ORG_CURRENT); }
    bool isAsyncOperationSucceeded() const override { return true; }
    // A read, or a seek outside what was written: not a plain save.
    bool strayed() const { return mRead; }

private:
    Bytes& mBytes;
    u32 mPos = 0;
    bool mRead = false;
};

// One entry an archive's load asked the manager for (slot 13), as the host
// saw it: the request's own arguments, the entry's place in the file from
// the decompressing stream `DecompressStream::open` set (rArchive.h), the
// answer, and the entry's stored bytes.
struct ArchiveEntry {
    const rArchive* archive;
    u32 type;
    char path[64];
    u32 quality;
    u32 offset;
    u32 datasize;
    u32 orgsize;
    cResource* answer;
    // The file's own bytes, which outlive the save.
    struct {
        const unsigned char* data;
        unsigned long size;
    } kept;
};

ArchiveEntry* archive_entries = nullptr;
unsigned long archive_entry_count = 0;
unsigned long archive_entry_capacity = 0;
Bytes archive_keys;  // create(u64)'s ids, 8 bytes each, in the order asked

// Whether `resource` was loaded (`mark_loaded`) and its class has a `save`
// of its own.
bool writes_itself(cResource* resource) {
    if (resource == nullptr || (state_word(resource) & 1u) == 0) {
        return false;
    }
    using Save = bool (cResource::*)(MtStream&);
    static const unsigned long slot =
        slot_of(Save{member(SaveOf{})},
                "rArchive's writer (host): save(MtStream&) is no virtual of cResource");
    void* const* vtable = nullptr;
    __builtin_memcpy(&vtable, resource, sizeof vtable);
    return vtable[slot] != reinterpret_cast<void*>(&ddon_base_save);
}

void note_archive_entry(MtStream& in, const MtDTI& dti, MT_CTSTR path, u32 quality,
                        cResource* answer) {
    if (&in.getDTI() != &rArchive::DecompressStream::DTI) {
        return;
    }
    auto& stream = static_cast<rArchive::DecompressStream&>(in);
    if (archive_entry_count == archive_entry_capacity) {
        unsigned long grown = archive_entry_capacity ? archive_entry_capacity * 2 : 64;
        auto* next = static_cast<ArchiveEntry*>(ddon_own_alloc(grown * sizeof(ArchiveEntry), 16));
        if (next == nullptr) {
            ddon_trap("rArchive's writer (host): out of host storage");
        }
        if (archive_entry_count != 0) {
            __builtin_memcpy(static_cast<void*>(next), archive_entries,
                             archive_entry_count * sizeof(ArchiveEntry));
        }
        ddon_host_free(archive_entries);
        archive_entries = next;
        archive_entry_capacity = grown;
    }
    ArchiveEntry& entry = archive_entries[archive_entry_count++];
    __builtin_memset(static_cast<void*>(&entry), 0, sizeof entry);
    entry.archive = stream.*member(DecompressArcOf{});
    entry.type = dti.getID();
    for (unsigned long i = 0; path != nullptr && path[i] != 0 && i + 1 < sizeof entry.path; ++i) {
        entry.path[i] = path[i];
    }
    entry.quality = quality;
    entry.offset = stream.*member(DecompressOffsetOf{});
    entry.datasize = stream.*member(DecompressDataSizeOf{});
    entry.orgsize = stream.*member(DecompressOrgSizeOf{});
    entry.answer = answer;
    // The bytes below the cipher: the file's own, where the entry lies
    // (`ddon_input_bytes` answers only for the file's input stream).
    MtStream* below = stream.*member(DecompressInOf{});
    if (entry.archive != nullptr && entry.archive->*member(ArcEncryptedOf{}) != 0 &&
        below != nullptr) {
        below = static_cast<rArchive::CipherStream*>(below)->*member(CipherInOf{});
    }
    if (const unsigned char* stored = ddon_input_bytes(below, entry.offset, entry.datasize)) {
        entry.kept = {stored, entry.datasize};
    }
}

// Whether `raw`, what `resource` saved, is what its load was given: the bytes
// `entry`'s stored ones inflate to, or their staged image for a class the
// stage translates, whose translation back is injective on what it accepts
// (`pc32.rs`): the verdict a root's own file of that class gets.
bool saves_back(const ArchiveEntry& entry, const MtCipher* cipher, cResource& resource,
                const Bytes& raw) {
    if (entry.kept.size == 0 || entry.kept.size != entry.datasize) {
        return false;
    }
    Bytes stored;
    stored.put(0, entry.kept.data, entry.kept.size);
    if (cipher != nullptr) {
        cipher->decryptBF(stored.data, stored.data, static_cast<u32>(stored.size));
    }
    Bytes inflated;
    inflated.resize(entry.orgsize + 1ul);
    unsigned long size = inflated.size;
    bool same =
        uncompress(inflated.data, &size, stored.data, stored.size) == 0 && size == entry.orgsize;
    stored.release();
    if (same && ddon_entry_translated(resource.getDTI().getName())) {
        MtStream* image = ddon_entry_image(inflated.data, entry.orgsize, resource.getExt());
        same = image != nullptr;
        if (same) {
            size = image->getLength();
            inflated.resize(size);
            same = image->read(inflated.data, static_cast<u32>(size)) == size;
            ddon_inner_file_close(image);
        }
    }
    same = same && size == raw.size && __builtin_memcmp(inflated.data, raw.data, raw.size) == 0;
    inflated.release();
    return same;
}

void note_archive_key(u64 id) { archive_keys.put(archive_keys.size, &id, sizeof id); }

}  // namespace

// The writer itself, named in the root's driver (`DerivedRoute::Host`).
bool ddon_archive_save(const rArchive& root, MtStream& out) {
    const u32 count = root.*member(ArcCountOf{});
    cResource* const* resources = root.*member(ArcResourcesOf{});
    const bool encrypted = root.*member(ArcEncryptedOf{}) != 0;
    rArchive::ARCHIVE_HDR header{};
    header.version = 7;  // rArchive::DATA_VERSION, the only one load takes
    header.resource_num = static_cast<u16>(count);
    if (header.resource_num != count) {
        return false;
    }
    unsigned long first = 0;
    unsigned long entries = 0;
    for (unsigned long i = 0; i < archive_entry_count; ++i) {
        if (archive_entries[i].archive == &root) {
            first = entries++ == 0 ? i : first;
        }
    }
    Bytes image;
    if (!encrypted && entries == 0) {
        // ARCS: the keys, as the load asked for them (0x11c15c1).
        if (count == 0 || archive_keys.size != count * 8ul) {
            return false;
        }
        header.magic = 0x53435241u;
        image.put(0, &header, sizeof header);
        for (u32 i = 0; i < count; ++i) {
            u64 key = 0;
            __builtin_memcpy(&key, archive_keys.data + i * 8ul, sizeof key);
            if (resources[i] != nullptr && resources[i]->*member(IdOf{}) != key) {
                return false;
            }
            image.put(sizeof header + i * 8ul, &key, sizeof key);
        }
        bool wrote = out.write(image.data, static_cast<u32>(image.size)) == image.size;
        image.release();
        return wrote;
    }
    if (entries != count) {
        return false;
    }
    header.magic = encrypted ? 0x43435241u : 0x00435241u;
    rArchive::CIPHER_KEY key{};
    MtCipher cipher;
    if (encrypted) {
        if (ddon_archive_cipher_key == nullptr ||
            !ddon_archive_cipher_key(key, const_cast<rArchive*>(&root))) {
            return false;
        }
        cipher.setKeyString(reinterpret_cast<MT_CTSTR>(key.key));
        cipher.initializeBF();
    }
    const unsigned long table = sizeof header + count * sizeof(rArchive::RESOURCE_INFO);
    image.resize(table);
    image.put(0, &header, sizeof header);
    const s32 root_quality = static_cast<s32>(root.getQuality());
    bool ok = true;
    for (u32 i = 0, at = static_cast<u32>(first); ok && i < count; ++at) {
        const ArchiveEntry& entry = archive_entries[at];
        if (entry.archive != &root) {
            continue;
        }
        cResource* resource = resources[i];
        if (resource != entry.answer) {
            ok = false;
            break;
        }
        // The load's quality, clamped to [QUALITY_LOWEST, QUALITY_HIGHEST]
        // after the archive's own was added (0x11c1bf0-0x11c1c2b): at a bound
        // the clamp may have hidden the stored value.
        const s32 stored_quality =
            static_cast<s32>(entry.quality) - root_quality + rArchive::QUALITY_DEFAULT;
        if (entry.quality == rArchive::QUALITY_HIGHEST ||
            (entry.quality == rArchive::QUALITY_LOWEST && stored_quality != 0) ||
            stored_quality < 0 || stored_quality > 7) {
            ok = false;
            break;
        }
        rArchive::RESOURCE_INFO info{};
        const char* path = resource != nullptr ? &(resource->*member(PathOf{}))[0] : entry.path;
        for (unsigned long c = 0; path[c] != 0 && c + 1 < sizeof info.path; ++c) {
            info.path[c] = path[c];
        }
        info.type = resource != nullptr ? resource->getDTI().getID() : entry.type;
        info.quality = static_cast<u32>(stored_quality);
        info.offset = entry.offset;
        Bytes data;
        Bytes raw;
        const bool saved = writes_itself(resource);
        // Its stored bytes with nothing saved to hold them against: counted, whatever
        // the reason (no save of its own, not loaded, a save that gives other bytes).
        bool raw_fill = !saved;
        if (saved) {
            SinkStream sink(raw);
            DdonEntrySave derived =
                ddon_entry_save != nullptr ? ddon_entry_save(*resource) : nullptr;
            ok = (derived != nullptr ? derived(*resource, sink)
                                     : (resource->*member(SaveOf{}))(sink)) &&
                 !sink.strayed();
        }
        const char* name = resource != nullptr ? resource->getDTI().getName() : "(none)";
        bool keep = !saved;
        if (saved) {
            keep = ok && saves_back(entry, encrypted ? &cipher : nullptr, *resource, raw);
            if (!keep && ddon_entry_translated(name)) {
                // What it saved is no image of the PC client's bytes: a raw
                // fill.
                raw_fill = keep = ok = true;
            }
        }
        if (keep) {
            if (entry.kept.size != entry.datasize) {
                ok = false;
                break;
            }
            if (raw_fill) {
                ddon_note_kept_entry(name, entry.kept.size);
            }
            info.datasize = entry.datasize;
            info.orgsize = entry.orgsize;
            image.put(entry.offset, entry.kept.data, entry.kept.size);
        } else {
            unsigned long bound = compressBound(raw.size);
            data.resize((bound + 7) & ~7ul);
            unsigned long packed = bound;
            ok = ok && compress2(data.data, &packed, raw.data, raw.size, -1) == 0;
            data.resize((packed + 7) & ~7ul);
            __builtin_memset(data.data + packed, 0, data.size - packed);
            info.datasize = static_cast<u32>(data.size);
            info.orgsize = static_cast<u32>(raw.size);
            ok = ok && info.orgsize == raw.size;
            if (ok && encrypted) {
                cipher.encryptBF(data.data, data.data, static_cast<u32>(data.size));
            }
            image.put(entry.offset, data.data, data.size);
            data.release();
        }
        raw.release();
        image.put(sizeof header + i * sizeof info, &info, sizeof info);
        ++i;
    }
    if (ok && encrypted) {
        cipher.encryptBF(image.data + sizeof header, image.data + sizeof header,
                         static_cast<u32>(table - sizeof header));
    }
    ok = ok && out.write(image.data, static_cast<u32>(image.size)) == image.size;
    image.release();
    return ok;
}

namespace {

// The classes of the corpus's archives that the PS4 build does not register,
// so rArchive::load's lookup fails (0x11c1b35-0x11c1b40) and the archive with
// it. The entry's id is the name's CRC; the name is the PC client's (its
// executable holds both strings), and no PS4 build has either class:
// - rSoundSourceMSADPCM (0x724df879): RIFF WAVE, format tag 2, MS-ADPCM;
//   90,483 entries in 1,876 of the corpus's ARCC archives;
// - rLinkageEnemy (0x53dec7d3): obj/em/em<N>/le, three entries in three
//   archives; this ELF's line table names rLinkageEnemy.cpp and nothing else
//   of it.
// A host class, never the game's (the PC parents are not in DWARF; cResource
// here): its load keeps the entry's bytes as the archive's stream delivers
// them, its save writes them back unchanged, and the report counts its loads
// as "kept by a host class", apart from the game's. Exit: a PS4 build whose
// ELF has the class.
class HostKeptBytes final : public cResource {
public:
    class Dti final : public MtDTI {
    public:
        explicit Dti(MT_CTSTR name)
            : MtDTI(name, &cResource::DTI, sizeof(HostKeptBytes), 0u, 0u, 0u) {}
        MtObject* newInstance() const override { return new (16u) HostKeptBytes(*this); }
    };
    explicit HostKeptBytes(const Dti& dti) : mDti(dti) {}
    static void* operator new(size_t size, u32 align) { return ddon_host_alloc(size, align); }
    static void operator delete(void* memory) { ddon_host_free(memory); }
    ~HostKeptBytes() override { mBytes.release(); }
    const MtDTI& getDTI() const override { return mDti; }
    bool load(MtStream& in) override {
        const u32 size = in.getLength();
        mBytes.resize(size);
        u32 got = 0;
        while (got < size) {
            u32 n = in.read(mBytes.data + got, size - got);
            if (n == 0) {
                break;
            }
            got += n;
        }
        return size != 0 && got == size;
    }
    bool save(MtStream& out) override {
        return out.write(mBytes.data, static_cast<u32>(mBytes.size)) == mBytes.size;
    }
    // rSoundSource's first two virtuals, at its slots 16 and 17: a sound
    // bank's loadEnd (0xe45d10) asks each source it requested to prepare, and
    // these bytes are in memory from load on.
    virtual void initIdentifier(u32*) const {
        ddon_trap("rSoundSourceMSADPCM (host): initIdentifier, which no load calls");
    }
    virtual bool prepareToBuffer() { return true; }

private:
    const Dti& mDti;
    Bytes mBytes;
};

struct HostClass {
    u32 id;
    const char* name;
};

const HostClass HOST_CLASSES[] = {
    {0x724df879u, "rSoundSourceMSADPCM"},
    {0x53dec7d3u, "rLinkageEnemy"},
};

// Built in `ddon_fixtures_init`, after every static initializer, so their
// parent's descriptor is already in the registry.
alignas(
    HostKeptBytes::Dti) unsigned char host_class_dtis[sizeof HOST_CLASSES / sizeof *HOST_CLASSES]
                                                     [sizeof(HostKeptBytes::Dti)];

void host_classes_register() {
    unsigned long i = 0;
    for (const HostClass& host : HOST_CLASSES) {
        if (MtDTI::from(host.id) == nullptr) {
            ::new (static_cast<void*>(host_class_dtis[i])) HostKeptBytes::Dti(host.name);
        }
        ++i;
    }
}

bool is_host_class(const MtDTI& dti) {
    for (const auto& slot : host_class_dtis) {
        if (static_cast<const void*>(&dti) == static_cast<const void*>(slot)) {
            return true;
        }
    }
    return false;
}

}  // namespace
#endif

// `sRender::mpInstance`: the renderer, an engine singleton whose pointer the
// library defines and the game's start-up sets. The host's instance is a
// zeroed block of `sizeof(sRender)` bytes (18,009,328), untouched pages
// staying unmapped and shared across the file's forks, whose vptr is a table
// of traps: the host answers no virtual of the renderer. Only `mScreenSize`
// holds a value, the game's: `sRender::sRender` (0x125e990) stores 0x780 and
// 0x438 at +0xc8 and +0xcc (0x125eb9a, 0x125eba4), which rRenderTargetTexture's
// load and save read through the inlined `getScreenSize`. The constructor's
// other stores (`mDisplaySize` at +0xd0, the same two values; `mFeatureLevel`
// 2 at +0x3c) and everything it builds stay zero: no load reads them. The
// library defines the pointer; the host only sets it, where the library has
// the class.
#if __has_include("sRender.h")
#include "sRender.h"

namespace {

// `mScreenSize` is protected; named as DWARF names it ([temp.explicit]/14).
struct ScreenSizeOf {
    friend constexpr auto member(ScreenSizeOf);
};
template struct Grant<&sRender::mScreenSize, ScreenSizeOf>;

// The ELF's screen: the immediates of the two stores at 0x125eb9a.
constexpr s32 kScreenWidth = 0x780;
constexpr s32 kScreenHeight = 0x438;

[[noreturn]] void host_render_other(sRender*) {
    ddon_trap("sRender (host): a virtual of the renderer, which the host does not answer");
}

// More slots than `sRender`'s vtable has (its own and `cSystem`'s); all trap.
constexpr unsigned long kRenderSlots = 256;
// Offset to top and the type information, then the slots.
void* host_render_vtable[2 + kRenderSlots];
alignas(16) unsigned char host_render[sizeof(sRender)];

}  // namespace

extern sRender* ddon_render_instance __asm__("_ZN7sRender10mpInstanceE");

namespace {

void host_render_init() {
    for (unsigned long i = 0; i < kRenderSlots; ++i) {
        host_render_vtable[2 + i] = reinterpret_cast<void*>(&host_render_other);
    }
    void* vptr = &host_render_vtable[2];
    __builtin_memcpy(host_render, &vptr, sizeof vptr);
    sRender* render = reinterpret_cast<sRender*>(host_render);
    const s32 screen[2] = {kScreenWidth, kScreenHeight};
    static_assert(sizeof(render->*member(ScreenSizeOf{})) == sizeof screen,
                  "MtSize is DWARF's two s32, w then h");
    __builtin_memcpy(&(render->*member(ScreenSizeOf{})), screen, sizeof screen);
    ddon_render_instance = render;
}

}  // namespace
#endif

// `sArchiveManager::mpInstance`: the archive manager, an engine singleton the
// game builds at start-up. rCameraParamList's load
// names its curves through `createRes(const MtDTI&, path, mode, warningOff)`
// (0x720d20), which the bundle proves: `sResource::makeID` and
// `sResource::create(u64)`, the only member it touches `mLastError`. The
// host's instance is a zeroed block of `sizeof(sArchiveManager)` bytes, an
// empty list of archives, whose vptr is a table of traps: the host answers no
// virtual of the manager.
#if __has_include("sArchiveManager.h")
#include "sArchiveManager.h"

namespace {

[[noreturn]] void host_archive_manager_other(sArchiveManager*) {
    ddon_trap(
        "sArchiveManager (host): a virtual of the archive manager, which the host does not answer");
}

// More slots than `sArchiveManager`'s vtable has (its own and `cSystem`'s).
constexpr unsigned long kArchiveManagerSlots = 64;
// Offset to top and the type information, then the slots.
void* host_archive_manager_vtable[2 + kArchiveManagerSlots];
alignas(16) unsigned char host_archive_manager[sizeof(sArchiveManager)];

}  // namespace

extern sArchiveManager* ddon_archive_manager_instance __asm__("_ZN15sArchiveManager10mpInstanceE");

namespace {

void host_archive_manager_init() {
    for (unsigned long i = 0; i < kArchiveManagerSlots; ++i) {
        host_archive_manager_vtable[2 + i] = reinterpret_cast<void*>(&host_archive_manager_other);
    }
    void* vptr = &host_archive_manager_vtable[2];
    __builtin_memcpy(host_archive_manager, &vptr, sizeof vptr);
    ddon_archive_manager_instance = reinterpret_cast<sArchiveManager*>(host_archive_manager);
}

}  // namespace
#endif

// `sAI::mpInstance`: the AI manager, an engine singleton the game builds at
// start-up. rAIFSM's load asks it for the user process service
// (`getService(cAISvUserProcess::DTI, nullptr)`, called at 0x1060824 and
// 0x1060861 in `cAIUserProcessReference::getProcessContainer`) and searches that
// service's containers by name, with no null test of the service. The host's
// manager is a zeroed block of `sizeof(sAI)` bytes whose one service is a zeroed
// `cAISvUserProcess`: `getDTI` is the bundle's own body and every other virtual
// of both traps. No container is registered, so every search answers null; the
// game's own start-up registers them, and the six processes a node finds there
// are no property of it.
#if __has_include("sAI.h") && __has_include("cAISvUserProcess.h")
#include "sAI.h"
#include "cAISvUserProcess.h"

namespace {

DDON_GRANT(AiServiceTopOf, &sAI::mpServiceTop);
DDON_GRANT(AiServiceBottomOf, &sAI::mpServiceBottom);

[[noreturn]] void host_ai_other(sAI*) {
    ddon_trap("sAI (host): a virtual of the AI manager, which the host does not answer");
}

[[noreturn]] void host_user_process_other(cAISvUserProcess*) {
    ddon_trap("cAISvUserProcess (host): a virtual of the service, which the host does not answer");
}

const MtDTI& host_user_process_dti(const cAISvUserProcess* service) {
    return service->cAISvUserProcess::getDTI();
}

void* host_ai_vtable[2 + kHostSlots];
void* host_user_process_vtable[2 + kHostSlots];
alignas(16) unsigned char host_ai[sizeof(sAI)];
alignas(16) unsigned char host_user_process[sizeof(cAISvUserProcess)];

}  // namespace

extern sAI* ddon_ai_instance __asm__("_ZN3sAI10mpInstanceE");

namespace {

void host_ai_init() {
    using Dti = const MtDTI& (cAISvUserProcess::*)() const;
    unsigned long dti = slot_of(Dti{&cAISvUserProcess::getDTI},
                                "cAISvUserProcess (host): getDTI is no virtual of it");
    for (unsigned long i = 0; i < kHostSlots; ++i) {
        host_ai_vtable[2 + i] = reinterpret_cast<void*>(&host_ai_other);
        host_user_process_vtable[2 + i] = reinterpret_cast<void*>(&host_user_process_other);
    }
    host_user_process_vtable[2 + dti] = reinterpret_cast<void*>(&host_user_process_dti);
    void* vptr = &host_ai_vtable[2];
    __builtin_memcpy(host_ai, &vptr, sizeof vptr);
    vptr = &host_user_process_vtable[2];
    __builtin_memcpy(host_user_process, &vptr, sizeof vptr);
    sAI* ai = reinterpret_cast<sAI*>(host_ai);
    cAISvUserProcess* service = reinterpret_cast<cAISvUserProcess*>(host_user_process);
    ai->*member(AiServiceTopOf{}) = service;
    ai->*member(AiServiceBottomOf{}) = service;
    ddon_ai_instance = ai;
}

}  // namespace
#endif

// `sScenario::mpInstance`: the scenario, an engine singleton the game builds at
// start-up. `cScenarioArg_AreaJump`'s destructor asks it to delete its system
// message (`deleteSystemMsg`, 0x838540, proven: it returns where
// `mpGUISystemMsg` is null). The host's instance is a zeroed block of
// `sizeof(sScenario)` bytes, no message shown, whose vptr is a table of traps.
#if __has_include("sScenario.h")
#include "sScenario.h"

namespace {

[[noreturn]] void host_scenario_other(sScenario*) {
    ddon_trap("sScenario (host): a virtual of the scenario, which the host does not answer");
}

void* host_scenario_vtable[2 + kHostSlots];
alignas(16) unsigned char host_scenario[sizeof(sScenario)];

}  // namespace

extern sScenario* ddon_scenario_instance __asm__("_ZN9sScenario10mpInstanceE");

namespace {

void host_scenario_init() {
    for (unsigned long i = 0; i < kHostSlots; ++i) {
        host_scenario_vtable[2 + i] = reinterpret_cast<void*>(&host_scenario_other);
    }
    void* vptr = &host_scenario_vtable[2];
    __builtin_memcpy(host_scenario, &vptr, sizeof vptr);
    ddon_scenario_instance = reinterpret_cast<sScenario*>(host_scenario);
}

}  // namespace
#endif

// `sShader2::mpInstance`: the shader manager, an engine singleton the game
// builds at start-up (`sShader2::sShader2`, 0x127aa40, which sets the pointer
// at 0x127aa82). The host's instance is a zeroed block of `sizeof(sShader2)`
// bytes whose vptr is a table of traps, as the renderer's. The members the
// loads read hold a value:
// - `mShaderVersion` (+0xc0050), which rMaterial::load compares with its
//   header's `shader_version` (0x11d3a46) and fails on a mismatch. The
//   constructor copies it from the root shader file it loads (0x127ac04:
//   the rShader2 at +0x18, its +0x70, that record's +0x8), so no ELF byte
//   holds it. inferred: the version every .mrl file of the corpus carries,
//   0x4363cdf4 (14,122 of 14,122), the one value that takes the ELF's
//   matching path; the corpus has no shader file to read it from.
// - `mSRGBEnable` (+0xc6173), which rTexture::getDataVersion reads
//   (0x11e1f73) to pick the texture version 0x2000 | 157 over 0xa000 | 157.
//   The constructor copies the renderer's `mSRGBEnable` (0x127aad6), which
//   `sRender::sRender` sets from its flags' bit 9 (0x125eb75), passed by its
//   caller. inferred: true, the setting every .tex file of the corpus was
//   written for (version 0x209d in 81,927 of 81,927).
// - `mObjectNum`, `mObjectInfos` and `mpRemapObjectHandleSearchAccessTable`
//   (+0x40, +0x28, +0x30), the root shader package's objects, which
//   sShader2::remapObjectHandle (0x12807e0) searches: a handle is the CRC of
//   an object's name (its low 20 bits) and the object's index.
//   inferred: the PC client's DDOShaderPackage.mfx (the corpus's shader
//   version, 0x4363cdf4), whose objects 1 to 118 are its input layouts, below by
//   name; every inputlayout of the 14,048 .mod files is one of them, its id and
//   its index (22 handles of 188,918 primitives), so the remap keeps each. The
//   later objects (shaders and states) are left out: no load reads one here.
// - `mpNullMaterial` (+0xc6060), which rModel::initMaterial (0x11d854f) takes a
//   reference of where a model's material has no such name: a zeroed block of
//   `sizeof(nDraw::Material)` bytes with one reference, the manager's own, its
//   vptr a table of traps but for `release`, the bundle's own body called by
//   its qualified name (rModel::clear releases the reference). inferred: that it is not null (the
//   ELF adds the reference unchecked).
// Exit: the game's own start-up values, from a PS4 shader file and the
// renderer's flags, read by the host; until then they are catalogued.
#if __has_include("sShader2.h")
#include "sShader2.h"
#if __has_include("nDrawMaterial.h")
#include "nDrawMaterial.h"
#endif

namespace {

DDON_GRANT(ShaderVersionOf, &sShader2::mShaderVersion);
DDON_GRANT(ShaderSrgbOf, &sShader2::mSRGBEnable);
DDON_GRANT(ShaderObjectNumOf, &sShader2::mObjectNum);
DDON_GRANT(ShaderObjectInfosOf, &sShader2::mObjectInfos);
DDON_GRANT(ShaderSearchOf, &sShader2::mpRemapObjectHandleSearchAccessTable);

// inferred: the corpus's shader version and sRGB setting (above).
constexpr u32 kShaderVersion = 0x4363cdf4u;
constexpr bool kShaderSrgb = true;

// inferred: the corpus's shader package's objects (above), from object 1.
constexpr const char* kShaderObjects[] = {"IASystemCopy",
                                          "IASystemClear",
                                          "IADevelopPrim2D",
                                          "IADevelopPrim3D",
                                          "IACollisionInput",
                                          "IAFilter",
                                          "IAFilter0",
                                          "IAFilter1",
                                          "IAFilter2",
                                          "IASwing",
                                          "IASwing2",
                                          "IASwingHighPrecision",
                                          "IASwing2HighPrecision",
                                          "IAInstancing",
                                          "IAInstancingColor",
                                          "IALatticeDeform",
                                          "IATetraDeform",
                                          "IATetraDeform2",
                                          "IASkinBridge1wt",
                                          "IASkinBridge2wt",
                                          "IASkinBridge4wt",
                                          "IASkinBridge8wt",
                                          "IASkinBridge4wt4M",
                                          "IASkinTB1wt",
                                          "IASkinTBN1wt",
                                          "IASkinTBC1wt",
                                          "IASkinTBNLA1wt",
                                          "IASkinTB2wt",
                                          "IASkinTBN2wt",
                                          "IASkinTBC2wt",
                                          "IASkinTBNLA2wt",
                                          "IASkinTB4wt",
                                          "IASkinTBN4wt",
                                          "IASkinTBC4wt",
                                          "IASkinTBNLA4wt",
                                          "IASkinTB8wt",
                                          "IASkinTBN8wt",
                                          "IASkinTBC8wt",
                                          "IASkinTBNLA8wt",
                                          "IANonSkinTB",
                                          "IANonSkinTBC",
                                          "IANonSkinTBL",
                                          "IANonSkinTBL_LA",
                                          "IANonSkinTBN",
                                          "IANonSkinTBA",
                                          "IANonSkinTBNC",
                                          "IANonSkinTBNL",
                                          "IANonSkinTBNL_LA",
                                          "IANonSkinTBNA",
                                          "IANonSkinTBLA",
                                          "IANonSkinTBCA",
                                          "IANonSkinTBNCA",
                                          "IANonSkinTBNLA",
                                          "IANonSkinB",
                                          "IANonSkinBC",
                                          "IANonSkinBL",
                                          "IANonSkinBL_LA",
                                          "IANonSkinBA",
                                          "IANonSkinBLA",
                                          "IANonSkinBCA",
                                          "IASkinOTB_4WT_4M",
                                          "IANonSkinTBN_4M",
                                          "IASkinBridge1wtf",
                                          "IASkinBridge2wtf",
                                          "IASkinBridge4wtf",
                                          "IASkinBridge8wtf",
                                          "IASkinTB1wtf",
                                          "IASkinTB2wtf",
                                          "IASkinTB4wtf",
                                          "IASkinTB8wtf",
                                          "IASkinVelocytyEdge",
                                          "IADualParaboloid",
                                          "IA_DeferredLighting_LightVolume",
                                          "IAPrimitiveCloudBillboard",
                                          "IAPrimitiveCloud",
                                          "IAPrimitiveSprite",
                                          "IAPrimitiveNT",
                                          "IAPrimitivePolyline",
                                          "IAPrimitivePolygon",
                                          "IACubeMapFilter",
                                          "IAGSDOFFilter",
                                          "IABokeh",
                                          "IAWater",
                                          "IAWaterRipple",
                                          "IAGUI",
                                          "IATextureBlend",
                                          "IAGPUParticle",
                                          "IAGPULineParticle",
                                          "IAGPUPolylineParticle",
                                          "IALightShaftInput",
                                          "IAGrass",
                                          "IAGrassHicomp",
                                          "IAGrassHicomp2",
                                          "IAGrassPoint",
                                          "IAGrassLowest",
                                          "IAGrassSPU",
                                          "IAGrassOutsourcing",
                                          "IAGrassOutsourcingF32",
                                          "IAMirage",
                                          "IASimWaterForViewInput",
                                          "IASoftBodyQuad",
                                          "IASoftBodyVertex",
                                          "IASoftBodyDecouple",
                                          "IASoftBodyVertexNoVTF",
                                          "IASoftBodyVertexPS3",
                                          "IASoftBodyDecoupleNoVTF",
                                          "IATattooBlend2D",
                                          "IABuilder",
                                          "IASky",
                                          "IAAstralBody",
                                          "IASkyStar",
                                          "IAAmbientShadow",
                                          "IAVertexIndexF32",
                                          "IAVertexIndexF16",
                                          "IATriangleF32",
                                          "IATriangleF16",
                                          "IAInfParticle",
                                          "IABrowserFont"};
constexpr u32 kShaderObjectNum = 1 + sizeof kShaderObjects / sizeof *kShaderObjects;

// nDraw::OBJECT_INFO (0x10 bytes): id, the low 20 bits of its first word, is
// all the loads read.
struct HostObjectInfo {
    u32 bits;
    u32 padding;
    const u16* indices;
};
static_assert(sizeof(HostObjectInfo) == 0x10);
HostObjectInfo host_shader_objects[kShaderObjectNum];
// The objects' indices by their ids, as the search expects them.
u32 host_shader_search[kShaderObjectNum];

[[noreturn]] void host_shader_other(sShader2*) {
    ddon_trap("sShader2 (host): a virtual of the shader manager, which the host does not answer");
}

constexpr unsigned long kShaderSlots = 256;
void* host_shader_vtable[2 + kShaderSlots];
alignas(16) unsigned char host_shader[sizeof(sShader2)];

}  // namespace

#if __has_include("nDrawMaterial.h")
namespace {

DDON_GRANT(ShaderNullMaterialOf, &sShader2::mpNullMaterial);
DDON_GRANT(DrawReferencesOf, &nDraw::Resource::mRefCount);

[[noreturn]] void host_material_other(nDraw::Material*) {
    ddon_trap("sShader2 (host): a virtual of the null material, which the host does not answer");
}

void host_material_release(nDraw::Material* material) { material->nDraw::Resource::release(); }

void* host_material_vtable[2 + kHostSlots];
alignas(16) unsigned char host_null_material[sizeof(nDraw::Material)];

void host_null_material_init(sShader2* shader) {
    for (unsigned long i = 0; i < kHostSlots; ++i) {
        host_material_vtable[2 + i] = reinterpret_cast<void*>(&host_material_other);
    }
    using Release = void (nDraw::Resource::*)();
    unsigned long release = slot_of(Release{&nDraw::Resource::release},
                                    "sShader2 (host): no slot for nDraw::Resource::release");
    host_material_vtable[2 + release] = reinterpret_cast<void*>(&host_material_release);
    void* vptr = &host_material_vtable[2];
    __builtin_memcpy(host_null_material, &vptr, sizeof vptr);
    nDraw::Material* material = reinterpret_cast<nDraw::Material*>(host_null_material);
    material->*member(DrawReferencesOf{}) = 1;
    shader->*member(ShaderNullMaterialOf{}) = material;
}

}  // namespace
#endif

extern sShader2* ddon_shader_instance __asm__("_ZN8sShader210mpInstanceE");

namespace {

void host_shader_init() {
    for (unsigned long i = 0; i < kShaderSlots; ++i) {
        host_shader_vtable[2 + i] = reinterpret_cast<void*>(&host_shader_other);
    }
    void* vptr = &host_shader_vtable[2];
    __builtin_memcpy(host_shader, &vptr, sizeof vptr);
    sShader2* shader = reinterpret_cast<sShader2*>(host_shader);
    shader->*member(ShaderVersionOf{}) = kShaderVersion;
    shader->*member(ShaderSrgbOf{}) = kShaderSrgb;
    for (u32 i = 1; i < kShaderObjectNum; ++i) {
        host_shader_objects[i].bits = MtCRC::getCRC(kShaderObjects[i - 1], 0xFFFFFFFFu) & 0xFFFFFu;
    }
    for (u32 i = 0; i < kShaderObjectNum; ++i) {
        u32 at = i;
        for (; at != 0 &&
               host_shader_objects[host_shader_search[at - 1]].bits > host_shader_objects[i].bits;
             --at) {
            host_shader_search[at] = host_shader_search[at - 1];
        }
        host_shader_search[at] = i;
    }
    shader->*member(ShaderObjectNumOf{}) = kShaderObjectNum;
    shader->*member(ShaderObjectInfosOf{}) =
        reinterpret_cast<nDraw::OBJECT_INFO*>(host_shader_objects);
    shader->*member(ShaderSearchOf{}) = host_shader_search;
#if __has_include("nDrawMaterial.h")
    host_null_material_init(shader);
#endif
    ddon_shader_instance = shader;
}

}  // namespace
#endif

// `sScene::mpInstance`: the scene, an engine singleton the game builds as an
// `sSceneExt` (`sSceneExt::sSceneExt` 0x839740, called at 0x85e7a4), whose
// base constructor sets the pointer. The host's instance is a zeroed block
// of `sizeof(sSceneExt)` bytes whose vptr is a table of traps but for the
// three virtuals rTexture::load reaches, each the
// bundle's own body called by its qualified name: `getTextureDetail`
// (sSceneExt's, which calls `getTextureDetailMain`, sSceneExt's, reading
// `mTextureDetail`) and `getTextureMipLimite` (sScene's, reading
// `mTextureMipLimite`). Their slots are the bundle's declarations', read
// from the member function pointers. The two members hold the values
// `sScene::sScene` stores (0x126f35f: one 8-byte store at +0x7c of
// 0x100000000, `mTextureDetail` 0 and `mTextureMipLimite` 1, sScene.cpp:153);
// sSceneExt's constructor stores neither. The texture detail table that
// `loadTxd` reads from an archive stays empty, as the members alone answer.
#if __has_include("sSceneExt.h")
#include "sSceneExt.h"

namespace {

DDON_GRANT(TextureDetailOf, &sScene::mTextureDetail);
DDON_GRANT(TextureMipLimiteOf, &sScene::mTextureMipLimite);

// The immediate of `movabsq $0x100000000, %rax` at 0x126f35f, stored at +0x7c.
constexpr u32 kTextureDetail = 0;
constexpr u32 kTextureMipLimite = 1;

[[noreturn]] void host_scene_other(sSceneExt*) {
    ddon_trap("sScene (host): a virtual of the scene, which the host does not answer");
}

u32 host_scene_detail(sSceneExt* scene, MT_CTSTR path) {
    return scene->sSceneExt::getTextureDetail(path);
}

u32 host_scene_detail_main(sSceneExt* scene, MT_CTSTR path) {
    return scene->sSceneExt::getTextureDetailMain(path);
}

u32 host_scene_mip_limite(sSceneExt* scene, MT_CTSTR path) {
    return scene->sScene::getTextureMipLimite(path);
}

void* host_scene_vtable[2 + kHostSlots];
alignas(16) unsigned char host_scene[sizeof(sSceneExt)];

}  // namespace

extern sScene* ddon_scene_instance __asm__("_ZN6sScene10mpInstanceE");

namespace {

void host_scene_init() {
    using Query = u32 (sSceneExt::*)(MT_CTSTR);
    unsigned long detail = slot_of(Query{&sSceneExt::getTextureDetail},
                                   "sScene (host): getTextureDetail is no virtual of sSceneExt");
    unsigned long detail_main =
        slot_of(Query{&sSceneExt::getTextureDetailMain},
                "sScene (host): getTextureDetailMain is no virtual of sSceneExt");
    unsigned long mip_limite =
        slot_of(Query{&sSceneExt::getTextureMipLimite},
                "sScene (host): getTextureMipLimite is no virtual of sSceneExt");
    for (unsigned long i = 0; i < kHostSlots; ++i) {
        host_scene_vtable[2 + i] = reinterpret_cast<void*>(&host_scene_other);
    }
    host_scene_vtable[2 + detail] = reinterpret_cast<void*>(&host_scene_detail);
    host_scene_vtable[2 + detail_main] = reinterpret_cast<void*>(&host_scene_detail_main);
    host_scene_vtable[2 + mip_limite] = reinterpret_cast<void*>(&host_scene_mip_limite);
    void* vptr = &host_scene_vtable[2];
    __builtin_memcpy(host_scene, &vptr, sizeof vptr);
    sSceneExt* scene = reinterpret_cast<sSceneExt*>(host_scene);
    scene->*member(TextureDetailOf{}) = kTextureDetail;
    scene->*member(TextureMipLimiteOf{}) = kTextureMipLimite;
    ddon_scene_instance = scene;
}

}  // namespace
#endif

// `sSound::mpInstance`: the sound system, an engine singleton the game builds
// as an `sSoundExt` (`sSoundExt::sSoundExt` 0x84af90, called at 0x85e960),
// whose base constructor sets the pointer. The host's instance is a zeroed
// block of `sizeof(sSoundExt)` bytes whose vptr is a table of traps, as the
// renderer's. One member holds a value, the one rSoundStreamRequest::load
// reads (`getIsStreamSourcePackage` 0x129e0f0, called at 0x12039ac):
// `mIsStreamSourcePackage` (+0x476b0), true, the byte `sSound::sSound` stores
// (0x129173d, sSound.cpp:4167). `setIsStreamSourcePackage` (0x129e100), the
// only other store at that offset, has no direct call in the ELF. The voices
// and the driver stay zero: no load reads them.
#if __has_include("sSoundExt.h")
#include "sSoundExt.h"

namespace {

DDON_GRANT(StreamSourcePackageOf, &sSound::mIsStreamSourcePackage);

// The immediate of `movb $0x1, 0x476b0(%r15)` at 0x129173d.
constexpr bool kStreamSourcePackage = true;

[[noreturn]] void host_sound_other(sSoundExt*) {
    ddon_trap("sSound (host): a virtual of the sound system, which the host does not answer");
}

void* host_sound_vtable[2 + kHostSlots];
alignas(16) unsigned char host_sound[sizeof(sSoundExt)];

}  // namespace

extern sSound* ddon_sound_instance __asm__("_ZN6sSound10mpInstanceE");

namespace {

void host_sound_init() {
    for (unsigned long i = 0; i < kHostSlots; ++i) {
        host_sound_vtable[2 + i] = reinterpret_cast<void*>(&host_sound_other);
    }
    void* vptr = &host_sound_vtable[2];
    __builtin_memcpy(host_sound, &vptr, sizeof vptr);
    sSoundExt* sound = reinterpret_cast<sSoundExt*>(host_sound);
    sound->*member(StreamSourcePackageOf{}) = kStreamSourcePackage;
    ddon_sound_instance = sound;
}

}  // namespace
#endif
// `sGUI::mpInstance`: the GUI manager, an engine singleton the game builds at
// start-up (`sGUI::sGUI` 0x1241c00, which sets the pointer). The host's
// instance is a zeroed block of `sizeof(sGUI)` bytes whose vptr is a table of
// traps: rGUI::setData calls four members of it, none virtual, each the
// bundle's own body. Three members hold a value:
// - `mLanguageId` (+0x24), three zeros (LANGUAGE_JAPANESE), as the constructor
//   stores;
// - `mpObjectClassInfo` (+0xc8) and `mpInstanceClassInfo` (+0xd0), the tables
//   the constructor builds (0x1241feb, 0x1242048) with `buildClassInfo`
//   (0x12446a0): one entry per class under cGUIObject and cGUIInstance whose
//   descriptor is not abstract (its attribute's bit 0), depth first, then an
//   entry of id 0. The host walks the registry the same way, but
//   `createClassInfo` (0x1244710) fills an entry's setters from a new object's
//   property list, through constructors and `createProperty` bodies the bundle
//   does not have: the host's entries hold no setter, so `getPropSetter`
//   answers null and every `pFunc` the load stores is null. Exit: those bodies
//   in the bundle, then the ELF's own `createClassInfo`; until then catalogued.
#if __has_include("sGUI.h") && __has_include("cGUIObject.h") && __has_include("cGUIInstance.h")
#include "cGUIInstance.h"
#include "cGUIObject.h"
#include "sGUI.h"

namespace {

DDON_GRANT(GuiObjectInfoOf, &sGUI::mpObjectClassInfo);
DDON_GRANT(GuiInstanceInfoOf, &sGUI::mpInstanceClassInfo);
DDON_GRANT(DtiChildOf, &MtDTI::mpChild);
DDON_GRANT(DtiNextOf, &MtDTI::mpNext);

[[noreturn]] void host_gui_other(sGUI*) {
    ddon_trap("sGUI (host): a virtual of the GUI manager, which the host does not answer");
}

// The classes of the ELF's registry that the files name and the bundle's
// closure lacks, as the registry's entries alone, each with the name, parent,
// size and attribute of the ELF's initializer. Exit: the classes in the
// closure, whose own descriptors are then already there.
// - cGUIObjFreePolygonDDO (0xd9e50), one object's class: nothing in a load
//   builds it.
// - The font filters (0x1335690): `newInstance` answers null, as it does in
//   the ELF for an allocation that failed, and rGUI::createFontFilter then
//   returns. Without the entry `MtDTI::from` answers null instead, and the
//   loop reads the filter's parameters as class ids (the id of rTexture among
//   them in 9 files). The host therefore builds no filter. Exit: their
//   constructors and `createParamProperty` bodies in the bundle.
class HostGuiDti final : public MtDTI {
public:
    enum Builds { kNever, kNull };
    HostGuiDti(MT_CTSTR name, MtDTI* parent, size_t size, Builds builds)
        : MtDTI(name, parent, size, 0u, 0u, 0u), mBuilds(builds) {}
    MtObject* newInstance() const override {
        if (mBuilds == kNever) {
            ddon_trap("a GUI object's class (host): not in the bundle");
        }
        return nullptr;
    }

private:
    Builds mBuilds;
};
constexpr unsigned long kGuiHostClasses = 4;
alignas(HostGuiDti) unsigned char host_gui_dti[kGuiHostClasses][sizeof(HostGuiDti)];

// The parent by its id, as the registry holds it: a bundle without it gets no entry.
void host_gui_class(unsigned long slot, u32 id, MT_CTSTR name, u32 parent, size_t size,
                    HostGuiDti::Builds builds) {
    MtDTI* base = const_cast<MtDTI*>(MtDTI::from(parent));
    if (base != nullptr && MtDTI::from(id) == nullptr) {
        ::new (static_cast<void*>(host_gui_dti[slot])) HostGuiDti(name, base, size, builds);
    }
}

void* host_gui_vtable[2 + kHostSlots];
alignas(16) unsigned char host_gui[sizeof(sGUI)];

constexpr unsigned long kGuiClasses = 256;
nGUI::CLASS_INFO host_gui_objects[kGuiClasses];
nGUI::CLASS_INFO host_gui_instances[kGuiClasses];

// 0x12446a0: `MtDTI::mAttr` is DWARF's bit field at +0x30, its three high
// bits, which no pointer to member names; bit 0 of it is the ELF's test
// (byte 0x33, 0x20).
void host_gui_classes(const MtDTI& parent, nGUI::CLASS_INFO (&table)[kGuiClasses], u32& count) {
    for (const MtDTI* dti = parent.*member(DtiChildOf{}); dti != nullptr;
         dti = dti->*member(DtiNextOf{})) {
        u32 bits = 0;
        __builtin_memcpy(&bits, reinterpret_cast<const unsigned char*>(dti) + 0x30, sizeof bits);
        if ((bits >> 29 & 1u) == 0) {
            if (count + 1 == kGuiClasses) {
                ddon_trap("sGUI (host): more GUI classes than the host's table holds");
            }
            table[count].dtiId = dti->getID();
            ++count;
        }
        host_gui_classes(*dti, table, count);
    }
}

}  // namespace

extern sGUI* ddon_gui_instance __asm__("_ZN4sGUI10mpInstanceE");

namespace {

void host_gui_init() {
    for (unsigned long i = 0; i < kHostSlots; ++i) {
        host_gui_vtable[2 + i] = reinterpret_cast<void*>(&host_gui_other);
    }
    void* vptr = &host_gui_vtable[2];
    __builtin_memcpy(host_gui, &vptr, sizeof vptr);
    constexpr u32 font_filter = 0x134935e4u;  // cGUIFontFilter
    host_gui_class(0, 0x367e3297u, "cGUIObjFreePolygonDDO", cGUIObj2D::DTI.getID(), 0x100u,
                   HostGuiDti::kNever);
    host_gui_class(1, 0x5f704244u, "cGUIFontFilterShadow", font_filter, 0x20u, HostGuiDti::kNull);
    host_gui_class(2, 0x6df3ab1eu, "cGUIFontFilterBorder", font_filter, 0x18u, HostGuiDti::kNull);
    host_gui_class(3, 0x77214222u, "cGUIFontFilterGradationOverlay", font_filter, 0x18u,
                   HostGuiDti::kNull);
    u32 objects = 0;
    host_gui_classes(cGUIObject::DTI, host_gui_objects, objects);
    u32 instances = 0;
    host_gui_classes(cGUIInstance::DTI, host_gui_instances, instances);
    sGUI* gui = reinterpret_cast<sGUI*>(host_gui);
    gui->*member(GuiObjectInfoOf{}) = host_gui_objects;
    gui->*member(GuiInstanceInfoOf{}) = host_gui_instances;
    ddon_gui_instance = gui;
}

}  // namespace
#define DDON_HOST_GUI 1
#endif
#undef DDON_GRANT

// No body in the bundle (inline-only in the ELF), and the host allocator's
// base: its members are the engine's bookkeeping, unused by the host heap.
MtAllocator::MtAllocator() {}

#if __has_include("MtSerializer.h")
const char* ddon_class_name(unsigned id) {
    const MtDTI* dti = MtDTI::from(id);
    return dti != nullptr ? dti->getName() : nullptr;
}
#endif

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
    host_classes_register();
#endif
#if __has_include("sRender.h")
    host_render_init();
#endif
#if __has_include("sArchiveManager.h")
    host_archive_manager_init();
#endif
#if __has_include("sAI.h") && __has_include("cAISvUserProcess.h")
    host_ai_init();
#endif
#if __has_include("sScenario.h")
    host_scenario_init();
#endif
#if __has_include("sShader2.h")
    host_shader_init();
#endif
#if __has_include("sSceneExt.h")
    host_scene_init();
#endif
#if __has_include("sSoundExt.h")
    host_sound_init();
#endif
#ifdef DDON_HOST_GUI
    host_gui_init();
#endif
    host_resources_init();
}
