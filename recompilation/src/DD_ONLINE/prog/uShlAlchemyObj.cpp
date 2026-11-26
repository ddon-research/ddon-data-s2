// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlAlchemyObj.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextInterface.h"
#include "cEfcHandle.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpJob09.h"
#include "cpObjCollision.h"
#include "nShlBase.h"
#include "rEffectProvider.h"
#include "rObjCollision.h"
#include "rShlParamList.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamAlchemyObj::getDTI() const {
    return cShlParamAlchemyObj::DTI;
}

inline void* cShlParamAlchemyObj::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamAlchemyObj::DTI)->memAlloc(sz, align, cShlParamAlchemyObj::DTI.getID());
}

inline void cShlParamAlchemyObj::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamAlchemyObj::DTI)->memFree(p_addr);
}

MtDTI& cShlParamAlchemyObj::getShlDTI() const {
    return uShlAlchemyObj::DTI;
}

void cShlParamAlchemyObj::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mHp", &mHp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPushCollisionNo", &mPushCollisionNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPushGroup", &mPushGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDamageActive", &mDamageActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isFuwaMove", &isFuwaMove, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "fuwaPeriod", &fuwaPeriod, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "fuwaScale", &fuwaScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "fuwaRandom", &fuwaRandom, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsWaitForKill", &mIsWaitForKill, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWaitForKillFrame", &mWaitForKillFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mKillDistance", &mKillDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDamageCameraShake", &mDamageCameraShake, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDamageCameraShake2", &mDamageCameraShake2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLimitHeight", &mLimitHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLimitHeightSpeed", &mLimitHeightSpeed, 0u, 0u);
}

void cShlParamAlchemyObj::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "mActiveEffect", &mActiveEffect, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgUseAreaEffect", &mFlgUseAreaEffect, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaEffectTime", &mAreaEffectTime, 0u, 0u);
}

void cShlParamAlchemyObj::createPropertySE(MtPropertyList& s) {
    this->cShlParamBase::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "mActiveSe", &mActiveSe, 0u, 0u);
}

cShlParamAlchemyObj::~cShlParamAlchemyObj() {
}

void cShlParamAlchemyObj::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamAlchemyObj* pParam = static_cast<const cShlParamAlchemyObj*>(pParamBase);
    mHp = pParam->mHp;
    mPushCollisionNo = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 360);
    mPushGroup = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 364);
    mActiveEffect = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 368);
    mActiveSe = pParam->mActiveSe;
    mDamageActive = pParam->mDamageActive;
    isFuwaMove = pParam->isFuwaMove;
    fuwaPeriod = pParam->fuwaPeriod;
    fuwaScale = pParam->fuwaScale;
    fuwaRandom = pParam->fuwaRandom;
    mIsWaitForKill = pParam->mIsWaitForKill;
    mWaitForKillFrame = pParam->mWaitForKillFrame;
    mKillDistance = pParam->mKillDistance;
    mFlgUseAreaEffect = pParam->mFlgUseAreaEffect;
    mAreaEffectTime = pParam->mAreaEffectTime;
    mDamageCameraShake = pParam->mDamageCameraShake;
    mDamageCameraShake2 = pParam->mDamageCameraShake2;
    mLimitHeight = pParam->mLimitHeight;
    mLimitHeightSpeed = pParam->mLimitHeightSpeed;
}

inline cShlParamAlchemyObj::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemyObj::MyDTI cShlParamAlchemyObj::DTI("cShlParamAlchemyObj", &::cShlParamBase::DTI, 432ul, 0u, 0u);

MtObject* cShlParamAlchemyObj::MyDTI::newInstance() const {
    return new (16u) cShlParamAlchemyObj;
}

const MtDTI& uShlAlchemyObj::getDTI() const {
    return uShlAlchemyObj::DTI;
}

inline void uShlAlchemyObj::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlAlchemyObj::DTI)->memFree(p_addr);
}

inline const cShlParamAlchemyObj* uShlAlchemyObj::getShlParam() const {
    return static_cast<const cShlParamAlchemyObj*>(mpShlParam2);
}

uShlAlchemyObj::uShlAlchemyObj() {
    DDON_STUB("uShlAlchemyObj::uShlAlchemyObj")
    /* stub */
}

uShlAlchemyObj::~uShlAlchemyObj() {
    DDON_STUB("uShlAlchemyObj::~uShlAlchemyObj")
    /* stub */
}

__attribute__((weak)) void uShlAlchemyObj::setup() {
    DDON_STUB("uShlAlchemyObj::setup")
    /* stub */
}

void uShlAlchemyObj::kill() {
    if (mpEfcAreaHandle != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpEfcAreaHandle, 4u);
        mpEfcAreaHandle = nullptr;
    }
    this->uShlBase::kill();
}

void uShlAlchemyObj::updatePtr() {
    this->uShlBase::updatePtr();
    if (mpRequestActiveSeTarget == nullptr) {
        return;
    }
    if (mpRequestActiveSeTarget->isEnable()) {
        return;
    }
    mpRequestActiveSeTarget = nullptr;
}

__attribute__((weak)) void uShlAlchemyObj::updateSub() {
    DDON_STUB("uShlAlchemyObj::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlAlchemyObj::callbackDamage(cHitInfo* pInfo) {
    DDON_STUB("uShlAlchemyObj::callbackDamage")
    /* stub */
}

__attribute__((weak)) void uShlAlchemyObj::requestAngle(const MtQuaternion& quat) {
    DDON_STUB("uShlAlchemyObj::requestAngle")
    /* stub */
}

__attribute__((weak)) void uShlAlchemyObj::progKillRequest() {
    DDON_STUB("uShlAlchemyObj::progKillRequest")
    /* stub */
}

void uShlAlchemyObj::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mpEfcAreaHandle == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpEfcAreaHandle)) {
        return;
    }
    mpEfcAreaHandle->mpOwner = nullptr;
    mpEfcAreaHandle = nullptr;
}

__attribute__((weak)) void uShlAlchemyObj::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlAlchemyObj::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uShlAlchemyObj::requestActiveEffectCore() {
    DDON_STUB("uShlAlchemyObj::requestActiveEffectCore")
    /* stub */
}

__attribute__((weak)) void uShlAlchemyObj::requestActiveSeCore() {
    DDON_STUB("uShlAlchemyObj::requestActiveSeCore")
    /* stub */
}

__attribute__((weak)) void uShlAlchemyObj::updateLandHoming() {
    DDON_STUB("uShlAlchemyObj::updateLandHoming")
    /* stub */
}

inline uShlAlchemyObj::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlAlchemyObj::MyDTI uShlAlchemyObj::DTI("uShlAlchemyObj", &::uShlBase::DTI, 11136ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlAlchemyObj::MyDTI::newInstance() const {
    DDON_STUB("uShlAlchemyObj::MyDTI::newInstance")
    return nullptr;
}

