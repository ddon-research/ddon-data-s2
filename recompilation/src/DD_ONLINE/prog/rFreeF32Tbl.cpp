// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rFreeF32Tbl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rFreeF32Tbl::getDTI() const {
    return rFreeF32Tbl::DTI;
}

inline void* rFreeF32Tbl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rFreeF32Tbl::DTI)->memAlloc(sz, align, rFreeF32Tbl::DTI.getID());
}

inline void rFreeF32Tbl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFreeF32Tbl::DTI)->memFree(p_addr);
}

inline rFreeF32Tbl::rFreeF32Tbl() {
    setAttribute(16u);
    mpHeader = nullptr;
}

rFreeF32Tbl::~rFreeF32Tbl() {
    if (mpHeader == nullptr) {
        return;
    }
    MtMemoryAllocator::getAllocator(rFreeF32Tbl::DTI)->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

f32 rFreeF32Tbl::getIndexF32(u32 idx, f32 def) {
    if (mpHeader != nullptr) {
        if (idx < mpHeader->TagNum) {
            if (mpHeader->Tags[idx].pVal != nullptr) {
                return *mpHeader->Tags[idx].pVal;
            }
        }
    }
    return def;
}

__attribute__((weak)) MtVector3 rFreeF32Tbl::getIndexVec3(u32 idx, const MtVector3& def) {
    DDON_STUB("rFreeF32Tbl::getIndexVec3")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector4 rFreeF32Tbl::getIndexVec4(u32 idx, const MtVector4& def) {
    DDON_STUB("rFreeF32Tbl::getIndexVec4")
    __builtin_unreachable();
}

f32 rFreeF32Tbl::getTagF32(u32 tag, f32 def) {
    u32 t0 = getTagIndex(tag);
    return getIndexF32(t0, def);
}

__attribute__((weak)) MtVector3 rFreeF32Tbl::getTagVec3(u32 tag, const MtVector3& def) {
    DDON_STUB("rFreeF32Tbl::getTagVec3")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector4 rFreeF32Tbl::getTagVec4(u32 tag, const MtVector4& def) {
    DDON_STUB("rFreeF32Tbl::getTagVec4")
    __builtin_unreachable();
}

u32 rFreeF32Tbl::getTagIndex(u32 tag) {
    u32 v2_0;
    if (mpHeader == nullptr) {
        v2_0 = 0;
    } else {
        u32 v0_2 = mpHeader->TagNum;
        if (v0_2 == 0) {
            v2_0 = 0;
        } else {
            unsigned int i0_0 = 0;
            for (stTag* p0_1 = &mpHeader->Tags[0];;) {
                if (p0_1->Tag == tag) {
                    v2_0 = i0_0;
                    return v2_0;
                } else {
                    if ((i0_0 + 1u) < v0_2) {
                        i0_0 += 1u;
                        p0_1 += 1;
                    } else {
                        break;
                    }
                }
            }
            v2_0 = v0_2;
        }
    }
    return v2_0;
}

MT_CTSTR rFreeF32Tbl::getExt() const {
    return "f2p";
}

__attribute__((weak)) bool rFreeF32Tbl::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    u32 len = in.getLength();
    allocMem(len);
    stHeader* p_header = mpHeader;
    if (p_header == nullptr) {
        return false;
    }
    if (len < HEADER_SIZE) {
        return false;
    }
    in.read(p_header, HEADER_SIZE);
    if (p_header->Version != DATA_VERSION) {
        freeMem();
        return false;
    }
    in.read(p_header->Tags, len - HEADER_SIZE);
    u32 tag_num = p_header->TagNum;
    for (u32 tag_idx = 0; tag_idx < tag_num; ++tag_idx) {
        stTag& tag = p_header->Tags[tag_idx];
        tag.pVal = reinterpret_cast<f32*>(reinterpret_cast<size_t>(tag.pVal) + reinterpret_cast<size_t>(p_header));
    }
    return true;
}

inline rFreeF32Tbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFreeF32Tbl::MyDTI rFreeF32Tbl::DTI("rFreeF32Tbl", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rFreeF32Tbl::MyDTI::newInstance() const {
    return new (16u) rFreeF32Tbl;
}

