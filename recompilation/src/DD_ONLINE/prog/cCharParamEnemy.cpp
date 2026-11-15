// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCharParamEnemy.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cCharParam.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCharParamEnemy::getDTI() const {
    return cCharParamEnemy::DTI;
}

inline MtAllocator* cCharParamEnemy::getAllocator() {
    return MtMemoryAllocator::getAllocator(cCharParamEnemy::DTI);
}

void* cCharParamEnemy::operator new(size_t sz, u32 align) {
    return cCharParamEnemy::getAllocator()->memAlloc(sz, align, cCharParamEnemy::DTI.getID());
}

inline void cCharParamEnemy::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCharParamEnemy::DTI)->memFree(p_addr);
}

__attribute__((noinline)) cCharParamEnemy::cCharParamEnemy() {
    u32 i;
    mAttackBasePhys = 10.0f;
    mAttackBaseMagic = 10.0f;
    mAttackWepPhys = 10.0f;
    mAttackWepMagic = 10.0f;
    mDefenceBasePhys = 10.0f;
    mDefenceBaseMagic = 10.0f;
    mDefenceWepPhys = 10.0f;
    mDefenceWepMagic = 10.0f;
    mPower = 10.0f;
    mWeight = 10.0f;
    mGuardAttackBase = 10.0f;
    mGuardDefenceBase = 10.0f;
    mGuardDefenceWep = 10.0f;
    mWeaponTypeSe = 0;
    mEnemyBodySizeSe = 0;
    mPushGroup = 0;
    mScrAdjustType = 3;
    mScrAdjustSize = 0;
    mFallDamageCheckHeight = 1000.0f;
    mUseMotionBlendNum = 1;
    mUseMotionHistory = false;
    mUseMotionHistoryNum = 0;
    mReturnTerritoryContTime = 5400.0f;
    mBeardownEffective = 0;
    mGuardReactionCheckType = 0;
    mIsShakedActionEnemy = false;
    mShakeCureRateRage = 1.0f;
    mEnemyScaleBase = 1.0f;
    mcThinkMgrScaleParam = 1.0f;
    mEnemyLinkRadiusA = 1000.0f;
    mEnemyLinkRadiusBOn = false;
    mEnemyLinkRadiusB = 1000.0f;
    for (i = 0; i < 10; i++) {
        mEvaluationPLJobs[i] = 1.0f;
    }
    for (i = 0; i < 2; i++) {
        mEvaluationPLSex[i] = 1.0f;
    }
    mHangdType = 0;
    mDownPerformanceOff = false;
    mIsDispDownGuage = false;
    mIsNoneAdbantageBGM = false;
    mEnemyScaleThinkTable = 1.0f;
    mIsUseEnchant = false;
    mEnchantType = 1;
    mDamageSpecialAdjType = 0;
    mDamageBounisFlag = 0;
    mShrinkBounisShakeRate = 0.0f;
    mShakeRateSequence = 1.0f;
    mScaleDispGui = 1.0f;
}

__attribute__((weak)) void cCharParamEnemy::createProperty(MtPropertyList& s) {
    DDON_STUB("cCharParamEnemy::createProperty")
    /* stub */
}

MtUI* cCharParamEnemy::createUI(MtProperty& prop) {
    return this->cCharParam::createUI(prop);
}

__attribute__((weak)) void cCharParamEnemy::paramClassCopy(MtObject* pObject) {
    DDON_STUB("cCharParamEnemy::paramClassCopy")
    /* stub */
}

inline cCharParamEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCharParamEnemy::MyDTI cCharParamEnemy::DTI("cCharParamEnemy", &::cCharParam::DTI, 480ul, 0u, 0u);

__attribute__((weak)) MtObject* cCharParamEnemy::MyDTI::newInstance() const {
    DDON_STUB("cCharParamEnemy::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCharParamEnemy::cJumpAttackSpeed::getDTI() const {
    return cCharParamEnemy::cJumpAttackSpeed::DTI;
}

inline void* cCharParamEnemy::cJumpAttackSpeed::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cCharParamEnemy::cJumpAttackSpeed::DTI)->memAlloc(sz, align, cCharParamEnemy::cJumpAttackSpeed::DTI.getID());
}

inline void cCharParamEnemy::cJumpAttackSpeed::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCharParamEnemy::cJumpAttackSpeed::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cCharParamEnemy::cJumpAttackSpeed::createProperty(MtPropertyList& s) {
    DDON_STUB("cCharParamEnemy::cJumpAttackSpeed::createProperty")
    /* stub */
}

MtUI* cCharParamEnemy::cJumpAttackSpeed::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cCharParamEnemy::cJumpAttackSpeed::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCharParamEnemy::cJumpAttackSpeed::MyDTI cCharParamEnemy::cJumpAttackSpeed::DTI("cCharParamEnemy::cJumpAttackSpeed", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cCharParamEnemy::cJumpAttackSpeed::MyDTI::newInstance() const {
    return new (16u) cCharParamEnemy::cJumpAttackSpeed;
}

const MtDTI& cCharParamEnemy::cGuardCounter::getDTI() const {
    return cCharParamEnemy::cGuardCounter::DTI;
}

inline void* cCharParamEnemy::cGuardCounter::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cCharParamEnemy::cGuardCounter::DTI)->memAlloc(sz, align, cCharParamEnemy::cGuardCounter::DTI.getID());
}

inline void cCharParamEnemy::cGuardCounter::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCharParamEnemy::cGuardCounter::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cCharParamEnemy::cGuardCounter::createProperty(MtPropertyList& s) {
    DDON_STUB("cCharParamEnemy::cGuardCounter::createProperty")
    /* stub */
}

MtUI* cCharParamEnemy::cGuardCounter::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cCharParamEnemy::cGuardCounter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCharParamEnemy::cGuardCounter::MyDTI cCharParamEnemy::cGuardCounter::DTI("cCharParamEnemy::cGuardCounter", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCharParamEnemy::cGuardCounter::MyDTI::newInstance() const {
    return new (16u) cCharParamEnemy::cGuardCounter;
}

