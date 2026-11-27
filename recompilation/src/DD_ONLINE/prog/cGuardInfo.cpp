// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cGuardInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cBlowShrinkDmInfo.h"
#include "nObjCollision.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cGuardInfo::getDTI() const {
    return cGuardInfo::DTI;
}

void* cGuardInfo::operator new(size_t sz, u32 align) {
    return cGuardInfo::getAllocator()->memAlloc(sz, align, cGuardInfo::DTI.getID());
}

cGuardInfo::cGuardInfo() {
    mIsJustGuardSuccess = false;
    mpBlowShrinkInfo = new (16u) cBlowShrinkDmInfo;
    mGuardDefenceBase = 0.0f;
    mGuardDefenceWep = 0.0f;
    mPawnAdjGuardDefenceBase = 0.0f;
    mSaminaDamageAdj[2] = 0.0f;
    mSaminaDamageAdj[3] = 0.0f;
    mSaminaDamageAdj[0] = 0.0f;
    mSaminaDamageAdj[1] = 0.0f;
    mGuardDefenceAdj[2] = 0.0f;
    mGuardDefenceAdj[3] = 0.0f;
    mGuardDefenceAdj[0] = 0.0f;
    mGuardDefenceAdj[1] = 0.0f;
    mGuardAttackAdj[2] = 0.0f;
    mGuardAttackAdj[3] = 0.0f;
    mGuardAttackAdj[0] = 0.0f;
    mGuardAttackAdj[1] = 0.0f;
    mPawnAdjStaminaDamage = 1.0f;
    mStaminaDamage = 1.0f;
    mGuardDefenceResultType = 0;
    mGuardAttack = 0.0f;
    mGuardDefence = 0.0f;
    mIsSuccessNoReaction = false;
}

cGuardInfo::~cGuardInfo() {
    if (mpBlowShrinkInfo == nullptr) {
        return;
    }
    delete mpBlowShrinkInfo;
    mpBlowShrinkInfo = nullptr;
}

inline cGuardInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGuardInfo::MyDTI cGuardInfo::DTI("cGuardInfo", &::MtObject::DTI, 104ul, 0u, 0u);

MtObject* cGuardInfo::MyDTI::newInstance() const {
    return new (16u) cGuardInfo;
}

