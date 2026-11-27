// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpHugeble.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpEffectStatusManager.h"
#include "../../XFramework/rCollisionHeightField.h"
#include "rEffectProvider.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sGame.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpHugeble::getDTI() const {
    return cpHugeble::DTI;
}

void* cpHugeble::operator new(size_t sz, u32 align) {
    return cpHugeble::getAllocator()->memAlloc(sz, align, cpHugeble::DTI.getID());
}

cpHugeble::cpHugeble() {
    mpModel = nullptr;
    mIsWaterDepthCheck = true;
    mInstantDeathDepth = 300.0f;
    mWaterDepth = 0.0f;
    mIsHugebleNoCheck = false;
    mIsHugebleDeath = false;
    mHugebleRno = 0;
    mHugebleTimer = 0.0f;
    mHugebleTime = 150.0f;
    mIsInstantDeath = false;
    const f32 t0 = MtVector3::Zero.x;
    const f32 t1 = MtVector3::Zero.y;
    const f32 t2 = MtVector3::Zero.z;
    mIsSafePos = true;
    mSeJoint = 2;
    mWaterCheck = false;
    mHugebleOldPos.x = t0;
    mHugebleOldPos.y = t1;
    mHugebleOldPos.z = t2;
    mHugebleOldPos.pad_ = 0.0f;
    mFlgHugebleOldPosInited = false;
}

cpHugeble::~cpHugeble() {
    if (mpModel == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(static_cast<sSoundExt*>(sSound::getInstance())->getGameBuffResource(), 101u, static_cast<MtObject*>(mpModel));
    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(static_cast<sSoundExt*>(sSound::getInstance())->getGameBuffResource(), 103u, static_cast<MtObject*>(mpModel));
}

__attribute__((weak)) void cpHugeble::setup() {
    DDON_STUB("cpHugeble::setup")
    /* stub */
}

void cpHugeble::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mHugebleDeathEffPos.x = offset.x + mHugebleDeathEffPos.x;
    mHugebleDeathEffPos.y = offset.y + mHugebleDeathEffPos.y;
    mHugebleDeathEffPos.z = offset.z + mHugebleDeathEffPos.z;
    mHugebleOldPos.x = offset.x + mHugebleOldPos.x;
    mHugebleOldPos.y = offset.y + mHugebleOldPos.y;
    mHugebleOldPos.z = offset.z + mHugebleOldPos.z;
}

void cpHugeble::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

void cpHugeble::initHugeble() {
    mWaterDepth = 0.0f;
    mIsHugebleNoCheck = false;
    mIsHugebleDeath = false;
    mHugebleRno = 0;
    mHugebleTimer = 0.0f;
    mHugebleTime = 150.0f;
    mIsInstantDeath = false;
    if (mpModel == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(static_cast<sSoundExt*>(sSound::getInstance())->getGameBuffResource(), 101u, static_cast<MtObject*>(mpModel));
    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(static_cast<sSoundExt*>(sSound::getInstance())->getGameBuffResource(), 103u, static_cast<MtObject*>(mpModel));
}

__attribute__((weak)) void cpHugeble::moveHugeble() {
    DDON_STUB("cpHugeble::moveHugeble")
    /* stub */
}

__attribute__((weak)) bool cpHugeble::checkHugeble(const MtVector3& checkPos) {
    DDON_STUB("cpHugeble::checkHugeble")
    return {};
}

__attribute__((weak)) bool cpHugeble::getHugebleEffPos(MtVector3& pos) {
    DDON_STUB("cpHugeble::getHugebleEffPos")
    return {};
}

__attribute__((weak)) void cpHugeble::setHugebleDeathEff(const MtVector3& pos) {
    DDON_STUB("cpHugeble::setHugebleDeathEff")
    /* stub */
}

void cpHugeble::syncHugebleDeathEff() {
    if (mpModel->mpEffectStatusManager == nullptr) {
        return;
    }
    mpModel->mpEffectStatusManager->mSyncFlag = mpModel->mpEffectStatusManager->mSyncFlag | 2ul;
}

void cpHugeble::endHugebleDeathEff() {
    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(static_cast<sSoundExt*>(sSound::getInstance())->getGameBuffResource(), 103u, static_cast<MtObject*>(mpModel));
}

bool cpHugeble::isInstantDeath() {
    return mIsInstantDeath;
}

bool cpHugeble::isSafePos() {
    return mIsSafePos;
}

bool cpHugeble::isHugeble() const {
    return mHugebleRno != 0;
}

bool cpHugeble::isHugebleFixed() const {
    return mHugebleRno > 2u;
}

void cpHugeble::resetHugebleOldPos(const MtVector3& pos) {
    mHugebleOldPos = pos;
}

inline cpHugeble::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpHugeble::MyDTI cpHugeble::DTI("cpHugeble", &::cpComponent::DTI, 192ul, 0u, 0u);

MtObject* cpHugeble::MyDTI::newInstance() const {
    return new (16u) cpHugeble;
}

