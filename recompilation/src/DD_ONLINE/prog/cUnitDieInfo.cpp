// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cUnitDieInfo.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cUnitDieInfo::getDTI() const {
    return cUnitDieInfo::DTI;
}

cUnitDieInfo::cUnitDieInfo() {
    mpHitInfo = nullptr;
}

inline cUnitDieInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cUnitDieInfo::MyDTI cUnitDieInfo::DTI("cUnitDieInfo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cUnitDieInfo::MyDTI::newInstance() const {
    return new (16u) cUnitDieInfo;
}

