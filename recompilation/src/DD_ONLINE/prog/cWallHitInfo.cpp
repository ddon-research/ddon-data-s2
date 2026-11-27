// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cWallHitInfo.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cWallHitInfo::getDTI() const {
    return cWallHitInfo::DTI;
}

cWallHitInfo::cWallHitInfo() {
    mResult = 0;
    mScrAdjustAttribute = 0;
}

cWallHitInfo::~cWallHitInfo() {
}

inline cWallHitInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWallHitInfo::MyDTI cWallHitInfo::DTI("cWallHitInfo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cWallHitInfo::MyDTI::newInstance() const {
    return new (16u) cWallHitInfo;
}

