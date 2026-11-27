// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEquipPartsInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtStream.h"
#include "../../XFramework/cResource.h"
#include "cpEquip.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rEquipPartsInfo::getDTI() const {
    return rEquipPartsInfo::DTI;
}

rEquipPartsInfo::~rEquipPartsInfo() {
    MtMemoryAllocator::getAllocator(rEquipPartsInfo::DTI)->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

void rEquipPartsInfo::clear() {
    rEquipPartsInfo::getAllocator()->memFree(static_cast<void*>(mpHeader));
    mpHeader = nullptr;
}

bool rEquipPartsInfo::load(MtStream& in) {
    u32 size = in.getLength();
    void* t0 = MtMemoryAllocator::getAllocator(rEquipPartsInfo::DTI)->memAlloc(size, 16u);
    mpHeader = static_cast<HEADER*>(t0);
    in.read(t0, size);
    if (mpHeader->magic == 0x495045) {
        if (mpHeader->version == 1) {
            mpHeader->parts = reinterpret_cast<s16*>(reinterpret_cast<char*>(mpHeader) + reinterpret_cast<long>(mpHeader->parts));
            return true;
        }
    }
    return false;
}

MT_CTSTR rEquipPartsInfo::getExt() const {
    return "epi";
}

__attribute__((weak)) void rEquipPartsInfo::setEquipPartsDispFlag(s32 parts, bool flag, cpEquip* pEquip) {
    DDON_STUB("rEquipPartsInfo::setEquipPartsDispFlag")
    /* stub */
}

inline rEquipPartsInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEquipPartsInfo::MyDTI rEquipPartsInfo::DTI("rEquipPartsInfo", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rEquipPartsInfo::MyDTI::newInstance() const {
    return new (16u) rEquipPartsInfo;
}

