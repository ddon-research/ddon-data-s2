// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cShlNotifyInfo.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cpObjCollision.h"
#include "rAttackParam.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlNotifyInfo::getDTI() const {
    return cShlNotifyInfo::DTI;
}

cShlNotifyInfo::cShlNotifyInfo() {
    mpDfdGeom = nullptr;
    mpAtkGeom = nullptr;
    mpDfdModel = nullptr;
    mpAtkModel = nullptr;
    mpAttackParam = nullptr;
    mHitPos.x = MtVector3::Zero.x;
    mHitPos.y = MtVector3::Zero.y;
    mHitPos.z = MtVector3::Zero.z;
    mHitPos.pad_ = 0.0f;
}

__attribute__((weak)) void cShlNotifyInfo::createParam(cHitInfo* pHitInfo) {
    DDON_STUB("cShlNotifyInfo::createParam")
    /* stub */
}

inline cShlNotifyInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlNotifyInfo::MyDTI cShlNotifyInfo::DTI("cShlNotifyInfo", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cShlNotifyInfo::MyDTI::newInstance() const {
    return new (16u) cShlNotifyInfo;
}

