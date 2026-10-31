// The deserialization harness's engine fixtures (024 T804). Each one is in
// fixture-boundary.txt with its reason. They stand in for engine services
// that do not interpret file bytes, and replace weak stubs only. The bundle
// links as an archive, so a member nothing else needs is never pulled in
// and a fixture of a name the bundle defines would replace its body without
// a duplicate definition: the harness refuses any fixture symbol the bundle
// defines strongly (T1032; merge43's proven `MtMemoryAllocator::getAllocator`
// had been shadowed so).
// No system header here beyond the forced includes: the bundle declares
// the PS4 libc's types (e.g. `pthread_mutex_t`), which a glibc header parsed
// after it would contradict.

#include "MtAllocator.h"
#include "MtCRC.h"
#include "MtDTI.h"
#include "runtime.h"
#include "sResource.h"

// The class registry (026 P113, ruling P57e-R): `MtDTI::MtDTI` 0xd61660 and
// `MtCRC::getCRC` 0xd7e390 are engine services whose bodies do not render,
// transcribed from the ELF's code. The constructor is a strong stub in the bundle
// (structors are never weak, 023 T577): the harness weakens it there only
// while the bundle refuses its body (ruling P113-A), so the
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
    void* memAlloc(size_t size, u32 align) override { return ddon_host_alloc(size, align); }
    void* memAlloc(size_t size, u32 align, u32) override { return ddon_host_alloc(size, align); }
    void* memAlloc(size_t size, u32 align, u32, u32) override {
        return ddon_host_alloc(size, align);
    }
    void memFree(void* ptr) override { ddon_host_free(ptr); }
    size_t memSize(void* ptr) override { return ddon_host_size(ptr); }
};

// The engine's resource manager, as the host's (constitution 2.7.0): the
// harness loads one root's files alone, and a sub-resource a load asks for
// (`sResource::create(const MtDTI&, MT_CTSTR, u32)`: a texture, a model, a
// nested effect) is another root's file. Each request gets a placeholder: a
// constructed, unloaded instance of the requested class, built by that
// class's own `MtDTI::newInstance` (the bundle's code, so a constructor that
// does not render is that file's wall), with its path set, and recorded in
// the file's record. It is never loaded or claimed correct. `addRef` and
// `release` keep the placeholder's own count, and the last release destroys
// it through its virtual destructor. The instance has no other engine
// state: its vtable holds those three at the slots the bundle's own
// declarations give them, and a trap at every other slot.

// Explicit instantiation ignores access ([temp.explicit]/14 in C++17): the
// placeholder's private `mPath` and `mRefCount`, and the manager's
// protected `addRef` and `release`, named as DWARF names them.
template <auto Member, typename Tag>
struct Grant {
    friend constexpr auto member(Tag) { return Member; }
};
struct PathOf {
    friend constexpr auto member(PathOf);
};
struct RefCountOf {
    friend constexpr auto member(RefCountOf);
};
template struct Grant<&cResource::mPath, PathOf>;
template struct Grant<&cResource::mRefCount, RefCountOf>;
struct AddRefOf {
    friend constexpr auto member(AddRefOf);
};
struct ReleaseOf {
    friend constexpr auto member(ReleaseOf);
};
template struct Grant<&sResource::addRef, AddRefOf>;
template struct Grant<&sResource::release, ReleaseOf>;

// The placeholders alive, so a release of any other resource traps.
constexpr unsigned kPlaceholders = 4096;
cResource* placeholders[kPlaceholders];
unsigned placeholder_count = 0;

cResource** placeholder_of(cResource* resource) {
    for (unsigned i = 0; i < placeholder_count; ++i) {
        if (placeholders[i] == resource) {
            return &placeholders[i];
        }
    }
    return nullptr;
}

cResource* host_create(sResource*, const MtDTI& dti, MT_CTSTR path, u32 mode) {
    // A class's `DTI` is a static object its `.ctors` initializer builds; a
    // bundle without that initializer leaves it zero (no vtable pointer, at
    // offset 0 of a dynamic class: Itanium C++ ABI 2.4), so no `newInstance`
    // can run: the placeholder's construction is the file's wall.
    void* vptr = nullptr;
    __builtin_memcpy(&vptr, &dti, sizeof vptr);
    if (vptr == nullptr) {
        ddon_placeholder_created(nullptr, path, mode);
        ddon_trap("sResource (host): the requested class's MtDTI is not constructed (its static initializer is not in the bundle)");
    }
    ddon_placeholder_created(dti.getName(), path, mode);
    MtObject* object = dti.newInstance();
    if (object == nullptr) {
        ddon_trap("sResource (host): the requested class's newInstance returned nullptr");
    }
    if (placeholder_count == kPlaceholders) {
        ddon_trap("sResource (host): more placeholders alive than the host keeps");
    }
    cResource* resource = static_cast<cResource*>(object);
    auto& to = resource->*member(PathOf{});
    unsigned long i = 0;
    for (; path != nullptr && path[i] != 0 && i + 1 < sizeof to; ++i) {
        to[i] = path[i];
    }
    to[i] = 0;
    placeholders[placeholder_count++] = resource;
    return resource;
}

void host_add_ref(sResource*, cResource* resource) {
    if (placeholder_of(resource) == nullptr) {
        ddon_trap("sResource (host): addRef of a resource the host did not create");
    }
    ++(resource->*member(RefCountOf{}));
}

void host_release(sResource*, cResource* resource) {
    cResource** slot = placeholder_of(resource);
    if (slot == nullptr) {
        ddon_trap("sResource (host): release of a resource the host did not create");
    }
    if (--(resource->*member(RefCountOf{})) > 0) {
        return;
    }
    *slot = placeholders[--placeholder_count];
    ddon_placeholder_released();
    // `MtObject`'s destructor is public and virtual: the class's own
    // deleting destructor runs.
    delete static_cast<MtObject*>(resource);
}

[[noreturn]] void host_resources_other(sResource*) {
    ddon_trap("sResource (host): a virtual other than create(const MtDTI&, MT_CTSTR, u32), addRef or release");
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
    unsigned long create = slot_of(Create{&sResource::create},
        "sResource (host): create(const MtDTI&, MT_CTSTR, u32) is no virtual of sResource");
    unsigned long add_ref = slot_of(Reference{member(AddRefOf{})},
        "sResource (host): addRef(cResource*) is no virtual of sResource");
    unsigned long release = slot_of(Reference{member(ReleaseOf{})},
        "sResource (host): release(cResource*) is no virtual of sResource");
    for (unsigned long i = 0; i < kHostSlots; ++i) {
        host_resources_vtable[2 + i] = reinterpret_cast<void*>(&host_resources_other);
    }
    host_resources_vtable[2 + create] = reinterpret_cast<void*>(&host_create);
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
    host_resources_init();
}
