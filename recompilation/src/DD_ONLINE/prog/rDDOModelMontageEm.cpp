// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rDDOModelMontageEm.h"

#include "../../MT/MtStream.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/nDrawConstantTable.h"
#include "../../XFramework/nDrawMaterial.h"
#include "../../XFramework/uBaseModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rDDOModelMontageEm::getDTI() const {
    return rDDOModelMontageEm::DTI;
}

inline MtAllocator* rDDOModelMontageEm::getAllocator() {
    return MtMemoryAllocator::getAllocator(rDDOModelMontageEm::DTI);
}

inline void* rDDOModelMontageEm::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rDDOModelMontageEm::DTI)->memAlloc(sz, align, rDDOModelMontageEm::DTI.getID());
}

inline void rDDOModelMontageEm::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rDDOModelMontageEm::DTI)->memFree(p_addr);
}

inline rDDOModelMontageEm::rDDOModelMontageEm() {
    setAttribute(16u);
    mpHeader = nullptr;
}

rDDOModelMontageEm::~rDDOModelMontageEm() {
    MtMemoryAllocator::getAllocator(rDDOModelMontageEm::DTI)->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

void rDDOModelMontageEm::clear() {
    rDDOModelMontageEm::getAllocator()->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

__attribute__((weak)) bool rDDOModelMontageEm::load(MtStream& in) {
    u32 size = in.getLength();
    mpHeader = static_cast<HEADER*>(getAllocator()->memAlloc(size, 16u));
    in.read(mpHeader, size);
    if (mpHeader->magic != 0x00454d44u) {
        return false;
    }
    if (mpHeader->version != DATA_VERSION) {
        return false;
    }
    mpHeader->parts = reinterpret_cast<PARTS*>(reinterpret_cast<uintptr>(mpHeader->parts) + reinterpret_cast<uintptr>(mpHeader));
    mpHeader->mindex = reinterpret_cast<MONTAGE**>(reinterpret_cast<uintptr>(mpHeader->mindex) + reinterpret_cast<uintptr>(mpHeader));
    mpHeader->montage = reinterpret_cast<MONTAGE*>(reinterpret_cast<uintptr>(mpHeader->montage) + reinterpret_cast<uintptr>(mpHeader));
    mpHeader->cindex = reinterpret_cast<COLOR_INFO*>(reinterpret_cast<uintptr>(mpHeader->cindex) + reinterpret_cast<uintptr>(mpHeader));
    for (u32 i = 0; i < mpHeader->montage_max; ++i) {
        if (mpHeader->mindex[i] != nullptr) {
            mpHeader->mindex[i] = reinterpret_cast<MONTAGE*>(reinterpret_cast<uintptr>(mpHeader->mindex[i]) + reinterpret_cast<uintptr>(mpHeader));
        }
    }
    return true;
}

MT_CTSTR rDDOModelMontageEm::getExt() const {
    return "dme";
}

__attribute__((weak)) u32 rDDOModelMontageEm::applyMontage(uModel* pmod, u32 no, rDDOModelMontageEm::PARTS_DISP dispType, bool setColor) {
    DDON_STUB("rDDOModelMontageEm::applyMontage")
    return {};
}

__attribute__((weak)) u32 rDDOModelMontageEm::applyMontageFirstSet(uModel* pmod, u32 no) {
    DDON_STUB("rDDOModelMontageEm::applyMontageFirstSet")
    return {};
}

__attribute__((weak)) void rDDOModelMontageEm::applyCore(uModel* pmod, rDDOModelMontageEm::MONTAGE* pmtg, rDDOModelMontageEm::PARTS_DISP dispType, bool setColor) {
    DDON_STUB("rDDOModelMontageEm::applyCore")
    /* stub */
}

inline rDDOModelMontageEm::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDDOModelMontageEm::MyDTI rDDOModelMontageEm::DTI("rDDOModelMontageEm", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rDDOModelMontageEm::MyDTI::newInstance() const {
    return new (16u) rDDOModelMontageEm;
}

