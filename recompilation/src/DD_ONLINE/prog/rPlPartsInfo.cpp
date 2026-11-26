// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rPlPartsInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtStream.h"
#include "../../XFramework/cResource.h"
#include "cpCharacterEdit.h"
#include "cpEquip.h"
#include "rCharacterEdit.h"
#include "../../XFramework/uBaseModel.h"
#include "uHuman.h"
#include "uMockUpModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rPlPartsInfo::getDTI() const {
    return rPlPartsInfo::DTI;
}

inline MtAllocator* rPlPartsInfo::getAllocator() {
    return MtMemoryAllocator::getAllocator(rPlPartsInfo::DTI);
}

inline void* rPlPartsInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rPlPartsInfo::DTI)->memAlloc(sz, align, rPlPartsInfo::DTI.getID());
}

inline void rPlPartsInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rPlPartsInfo::DTI)->memFree(p_addr);
}

inline rPlPartsInfo::rPlPartsInfo() {
    setAttribute(16u);
    mpHeader = nullptr;
}

rPlPartsInfo::~rPlPartsInfo() {
    MtMemoryAllocator::getAllocator(rPlPartsInfo::DTI)->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

void rPlPartsInfo::clear() {
    rPlPartsInfo::getAllocator()->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

bool rPlPartsInfo::load(MtStream& in) {
    u32 size = in.getLength();
    void* t0 = MtMemoryAllocator::getAllocator(rPlPartsInfo::DTI)->memAlloc(size, 16u);
    mpHeader = static_cast<HEADER*>(t0);
    in.read(t0, size);
    if (mpHeader->magic == 0x495350) {
        if (mpHeader->version == 1) {
            mpHeader->parts = reinterpret_cast<s16*>(reinterpret_cast<char*>(mpHeader) + reinterpret_cast<long>(mpHeader->parts));
            return true;
        }
    }
    return false;
}

MT_CTSTR rPlPartsInfo::getExt() const {
    return "psi";
}

__attribute__((weak)) void rPlPartsInfo::setParts(uModel* pModel, s32 parts, bool flag, cpEquip* pEquip) {
    DDON_STUB("rPlPartsInfo::setParts")
    /* stub */
}

__attribute__((weak)) void rPlPartsInfo::setScar(uModel* pModel, s32 parts, bool flag, cpEquip* pEquip) {
    DDON_STUB("rPlPartsInfo::setScar")
    /* stub */
}

inline rPlPartsInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPlPartsInfo::MyDTI rPlPartsInfo::DTI("rPlPartsInfo", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rPlPartsInfo::MyDTI::newInstance() const {
    return new (16u) rPlPartsInfo;
}

