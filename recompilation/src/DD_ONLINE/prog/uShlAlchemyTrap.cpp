// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlAlchemyTrap.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cContextPlayerInfo.h"
#include "cpObjCollision.h"
#include "nHumanMsg.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlAlchemyObj.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamAlchemyTrap::getDTI() const {
    return cShlParamAlchemyTrap::DTI;
}

inline void cShlParamAlchemyTrap::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamAlchemyTrap::DTI)->memFree(p_addr);
}

MtDTI& cShlParamAlchemyTrap::getShlDTI() const {
    return uShlAlchemyTrap::DTI;
}

__attribute__((noinline)) cShlParamAlchemyTrap::~cShlParamAlchemyTrap() {
    for (u32 i = 0; i < mCreateShlInfoArray.mLength; i++) {
        delete mCreateShlInfoArray.mpArray[i];
    }
    if (mCreateShlInfoArray.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mCreateShlInfoArray.mpArray));
    }
    mCreateShlInfoArray.mpArray = nullptr;
    mCreateShlInfoArray.mBufsiz = 0;
    mCreateShlInfoArray.mLength = 0;
}

void cShlParamAlchemyTrap::createProperty(MtPropertyList& s) {
    this->cShlParamAlchemyObj::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckShlIntervalTime", &mCheckShlIntervalTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCustomSkillNo", &mCustomSkillNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckCount", &mCheckCount[0], 32u, 10u);
    s << MtProperty(static_cast<MtObject*>(this), "mTurnTarget", &mTurnTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCreateShlInfoArray", static_cast<MtObject*>(&mCreateShlInfoArray), 0u, 0u);
}

void cShlParamAlchemyTrap::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    mHp = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 356);
    mPushCollisionNo = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 360);
    mPushGroup = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 364);
    mActiveEffect = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 368);
    const cShlParamAlchemyTrap* pParam = static_cast<const cShlParamAlchemyTrap*>(pParamBase);
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
    mCheckShlIntervalTime = pParam->mCheckShlIntervalTime;
    mCustomSkillNo = pParam->mCustomSkillNo;
    mCheckCount[0] = pParam->mCheckCount[0];
    mCheckCount[1] = pParam->mCheckCount[1];
    mCheckCount[2] = pParam->mCheckCount[2];
    mCheckCount[3] = pParam->mCheckCount[3];
    mCheckCount[4] = pParam->mCheckCount[4];
    mCheckCount[5] = pParam->mCheckCount[5];
    mCheckCount[6] = pParam->mCheckCount[6];
    mCheckCount[7] = pParam->mCheckCount[7];
    mCheckCount[8] = pParam->mCheckCount[8];
    mCheckCount[9] = pParam->mCheckCount[9];
    mTurnTarget = pParam->mTurnTarget;
    copyList(static_cast<const cShlParamAlchemyTrap*>(pParamBase));
}

__attribute__((weak)) void cShlParamAlchemyTrap::copyList(const cShlParamAlchemyTrap* pParam) {
    DDON_STUB("cShlParamAlchemyTrap::copyList")
    /* stub */
}

inline cShlParamAlchemyTrap::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemyTrap::MyDTI cShlParamAlchemyTrap::DTI("cShlParamAlchemyTrap", &::cShlParamAlchemyObj::DTI, 512ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamAlchemyTrap::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamAlchemyTrap::DTI)->memAlloc(sizeof(cShlParamAlchemyTrap), 16u, cShlParamAlchemyTrap::DTI.getID())) cShlParamAlchemyTrap;
}

const MtDTI& cShlParamAlchemyTrap::cTrapAttackShlInfo::getDTI() const {
    return cShlParamAlchemyTrap::cTrapAttackShlInfo::DTI;
}

inline void* cShlParamAlchemyTrap::cTrapAttackShlInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamAlchemyTrap::cTrapAttackShlInfo::DTI)->memAlloc(sz, align, cShlParamAlchemyTrap::cTrapAttackShlInfo::DTI.getID());
}

inline void cShlParamAlchemyTrap::cTrapAttackShlInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamAlchemyTrap::cTrapAttackShlInfo::DTI)->memFree(p_addr);
}

void cShlParamAlchemyTrap::cTrapAttackShlInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCheckDisMin", &mCheckDisMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckDisMax", &mCheckDisMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCreateShlNo", &mCreateShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseKnockBack", &mUseKnockBack, 0u, 0u);
}

inline cShlParamAlchemyTrap::cTrapAttackShlInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemyTrap::cTrapAttackShlInfo::MyDTI cShlParamAlchemyTrap::cTrapAttackShlInfo::DTI("cShlParamAlchemyTrap::cTrapAttackShlInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cShlParamAlchemyTrap::cTrapAttackShlInfo::MyDTI::newInstance() const {
    return new (16u) cShlParamAlchemyTrap::cTrapAttackShlInfo;
}

const MtDTI& cShlParamAlchemyTrapAttack::getDTI() const {
    return cShlParamAlchemyTrapAttack::DTI;
}

inline void* cShlParamAlchemyTrapAttack::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamAlchemyTrapAttack::DTI)->memAlloc(sz, align, cShlParamAlchemyTrapAttack::DTI.getID());
}

MtDTI& cShlParamAlchemyTrapAttack::getShlDTI() const {
    return uShlAlchemyTrapAttack::DTI;
}

cShlParamAlchemyTrapAttack::cShlParamAlchemyTrapAttack() {
}

cShlParamAlchemyTrapAttack::~cShlParamAlchemyTrapAttack() {
}

void cShlParamAlchemyTrapAttack::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
}

void cShlParamAlchemyTrapAttack::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
}

inline cShlParamAlchemyTrapAttack::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamAlchemyTrapAttack::MyDTI cShlParamAlchemyTrapAttack::DTI("cShlParamAlchemyTrapAttack", &::cShlParamBase::DTI, 352ul, 0u, 0u);

MtObject* cShlParamAlchemyTrapAttack::MyDTI::newInstance() const {
    return new (16u) cShlParamAlchemyTrapAttack;
}

const MtDTI& uShlAlchemyTrap::getDTI() const {
    return uShlAlchemyTrap::DTI;
}

inline void* uShlAlchemyTrap::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlAlchemyTrap::DTI)->memAlloc(sz, align, uShlAlchemyTrap::DTI.getID());
}

inline void uShlAlchemyTrap::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlAlchemyTrap::DTI)->memFree(p_addr);
}

uShlAlchemyTrap::~uShlAlchemyTrap() {
}

__attribute__((weak)) void uShlAlchemyTrap::setup() {
    DDON_STUB("uShlAlchemyTrap::setup")
    /* stub */
}

void uShlAlchemyTrap::updateSub() {
    this->uShlAlchemyObj::updateSub();
    if (mCheckShlIntervalTime > 0.0f) {
        mCheckShlIntervalTime = mCheckShlIntervalTime - mDeltaTime;
    }
}

void uShlAlchemyTrap::updatePtr() {
    this->uShlAlchemyObj::updatePtr();
}

void uShlAlchemyTrap::callbackAttackTest(cHitInfo* pHitInfo) {
    this->uShlBase::callbackAttackTest(pHitInfo);
    if (mCheckShlIntervalTime > 0.0f) {
    } else {
        createAttackShl(pHitInfo);
    }
}

__attribute__((weak)) void uShlAlchemyTrap::createAttackShl(cHitInfo* pHitInfo) {
    DDON_STUB("uShlAlchemyTrap::createAttackShl")
    /* stub */
}

inline uShlAlchemyTrap::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlAlchemyTrap::MyDTI uShlAlchemyTrap::DTI("uShlAlchemyTrap", &::uShlAlchemyObj::DTI, 11136ul, 0u, 0u);

MtObject* uShlAlchemyTrap::MyDTI::newInstance() const {
    return new (16u) uShlAlchemyTrap;
}

const MtDTI& uShlAlchemyTrapAttack::getDTI() const {
    return uShlAlchemyTrapAttack::DTI;
}

inline void* uShlAlchemyTrapAttack::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlAlchemyTrapAttack::DTI)->memAlloc(sz, align, uShlAlchemyTrapAttack::DTI.getID());
}

inline void uShlAlchemyTrapAttack::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlAlchemyTrapAttack::DTI)->memFree(p_addr);
}

uShlAlchemyTrapAttack::uShlAlchemyTrapAttack() {
    mKnockBackPos = MtVector3::Zero;
    mFlgNextTrap = false;
}

uShlAlchemyTrapAttack::~uShlAlchemyTrapAttack() {
}

__attribute__((weak)) void uShlAlchemyTrapAttack::callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo) {
    DDON_STUB("uShlAlchemyTrapAttack::callbackReplaceHitInfo_Atk")
    /* stub */
}

__attribute__((weak)) void uShlAlchemyTrapAttack::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlAlchemyTrapAttack::applyWorldOffset")
    /* stub */
}

inline uShlAlchemyTrapAttack::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlAlchemyTrapAttack::MyDTI uShlAlchemyTrapAttack::DTI("uShlAlchemyTrapAttack", &::uShlBase::DTI, 10960ul, 0u, 0u);

MtObject* uShlAlchemyTrapAttack::MyDTI::newInstance() const {
    return new (16u) uShlAlchemyTrapAttack;
}

template MtTypedArray<cShlParamAlchemyTrap::cTrapAttackShlInfo>::~MtTypedArray();

