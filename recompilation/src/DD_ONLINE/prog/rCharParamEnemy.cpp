// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCharParamEnemy.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cCharParamEnemy.h"
#include "cCharParamEnemyFly.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rCharParamEnemy::getDTI() const {
    return rCharParamEnemy::DTI;
}

inline void* rCharParamEnemy::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rCharParamEnemy::DTI)->memAlloc(sz, align, rCharParamEnemy::DTI.getID());
}

inline void rCharParamEnemy::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rCharParamEnemy::DTI)->memFree(p_addr);
}

inline rCharParamEnemy::rCharParamEnemy() {
    setAttribute(22u);
    mFlgEnemyFly = false;
    mpCharParamEnemy = nullptr;
}

rCharParamEnemy::~rCharParamEnemy() {
    if (mpCharParamEnemy == nullptr) {
        return;
    }
    delete mpCharParamEnemy;
    mpCharParamEnemy = nullptr;
}

MT_CTSTR rCharParamEnemy::getExt() const {
    return "cpe";
}

void rCharParamEnemy::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgEnemyFly", &mFlgEnemyFly, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCharParamEnemy", reinterpret_cast<MtObject* *>(&mpCharParamEnemy), 0u, 0u);
}

__attribute__((weak)) bool rCharParamEnemy::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if (r.readU32() != 0x657063u) {
        return false;
    }
    if (r.readU32() != DATA_VERSION) {
        return false;
    }
    nDDOIO::readData(r, mFlgEnemyFly);
    cCharParamEnemyFly* pFlyData = nullptr;
    if (mFlgEnemyFly) {
        pFlyData = new (16u) cCharParamEnemyFly;
        mpCharParamEnemy = pFlyData;
    } else {
        mpCharParamEnemy = new (16u) cCharParamEnemy;
    }
    if (mpCharParamEnemy == nullptr) {
        return false;
    }
    nDDOIO::readData(r, mpCharParamEnemy->mAttackBasePhys);
    nDDOIO::readData(r, mpCharParamEnemy->mAttackBaseMagic);
    nDDOIO::readData(r, mpCharParamEnemy->mAttackWepPhys);
    nDDOIO::readData(r, mpCharParamEnemy->mAttackWepMagic);
    nDDOIO::readData(r, mpCharParamEnemy->mDefenceBasePhys);
    nDDOIO::readData(r, mpCharParamEnemy->mDefenceBaseMagic);
    nDDOIO::readData(r, mpCharParamEnemy->mDefenceWepPhys);
    nDDOIO::readData(r, mpCharParamEnemy->mDefenceWepMagic);
    nDDOIO::readData(r, mpCharParamEnemy->mPower);
    nDDOIO::readData(r, mpCharParamEnemy->mWeight);
    nDDOIO::readData(r, mpCharParamEnemy->mGuardAttackBase);
    nDDOIO::readData(r, mpCharParamEnemy->mGuardDefenceBase);
    nDDOIO::readData(r, mpCharParamEnemy->mGuardDefenceWep);
    nDDOIO::readData(r, mpCharParamEnemy->mWeaponTypeSe);
    nDDOIO::readData(r, mpCharParamEnemy->mEnemyBodySizeSe);
    nDDOIO::readData(r, mpCharParamEnemy->mPushGroup);
    nDDOIO::readData(r, mpCharParamEnemy->mScrAdjustType);
    nDDOIO::readData(r, mpCharParamEnemy->mScrAdjustSize);
    nDDOIO::readData(r, mpCharParamEnemy->mShakeCureRateRage);
    for (u32 i = 0; i < 4; i++) {
        nDDOIO::readData(r, mpCharParamEnemy->mJumpAttackSpeed[i].mIsValid);
        nDDOIO::readData(r, mpCharParamEnemy->mJumpAttackSpeed[i].mSpeedZ);
        nDDOIO::readData(r, mpCharParamEnemy->mJumpAttackSpeed[i].mSpeedY);
        nDDOIO::readData(r, mpCharParamEnemy->mJumpAttackSpeed[i].mGravity);
    }
    nDDOIO::readData(r, mpCharParamEnemy->mFallDamageCheckHeight);
    nDDOIO::readData(r, mpCharParamEnemy->mUseMotionBlendNum);
    nDDOIO::readData(r, mpCharParamEnemy->mUseMotionHistory);
    nDDOIO::readData(r, mpCharParamEnemy->mUseMotionHistoryNum);
    nDDOIO::readData(r, mpCharParamEnemy->mReturnTerritoryContTime);
    nDDOIO::readData(r, mpCharParamEnemy->mBeardownEffective);
    for (u32 i = 0; i < 10; i++) {
        nDDOIO::readData(r, mpCharParamEnemy->mGuardCounter[i].mTimes);
        nDDOIO::readData(r, mpCharParamEnemy->mGuardCounter[i].mPercent);
    }
    nDDOIO::readData(r, mpCharParamEnemy->mGuardReactionCheckType);
    nDDOIO::readData(r, mpCharParamEnemy->mEnemyScaleBase);
    nDDOIO::readData(r, mpCharParamEnemy->mEnemyScaleThinkTable);
    nDDOIO::readData(r, mpCharParamEnemy->mIsShakedActionEnemy);
    nDDOIO::readData(r, mpCharParamEnemy->mHangdType);
    nDDOIO::readData(r, mpCharParamEnemy->mcThinkMgrScaleParam);
    nDDOIO::readData(r, mpCharParamEnemy->mEnemyLinkRadiusA);
    nDDOIO::readData(r, mpCharParamEnemy->mEnemyLinkRadiusBOn);
    nDDOIO::readData(r, mpCharParamEnemy->mEnemyLinkRadiusB);
    nDDOIO::readDataArray(r, mpCharParamEnemy->mEvaluationPLJobs, 10u);
    nDDOIO::readDataArray(r, mpCharParamEnemy->mEvaluationPLSex, 2u);
    nDDOIO::readData(r, mpCharParamEnemy->mDownPerformanceOff);
    nDDOIO::readData(r, mpCharParamEnemy->mIsDispDownGuage);
    nDDOIO::readData(r, mpCharParamEnemy->mIsNoneAdbantageBGM);
    nDDOIO::readData(r, mpCharParamEnemy->mIsUseEnchant);
    nDDOIO::readData(r, mpCharParamEnemy->mEnchantType);
    nDDOIO::readData(r, mpCharParamEnemy->mDamageSpecialAdjType);
    nDDOIO::readData(r, mpCharParamEnemy->mDamageBounisFlag);
    nDDOIO::readData(r, mpCharParamEnemy->mShrinkBounisShakeRate);
    nDDOIO::readData(r, mpCharParamEnemy->mShakeRateSequence);
    if (pFlyData != nullptr) {
        nDDOIO::readData(r, pFlyData->mHoverSpeed);
        nDDOIO::readDataArray(r, pFlyData->mHoverAltitude, 4u);
        nDDOIO::readData(r, pFlyData->mHoverLevelMax);
        nDDOIO::readData(r, pFlyData->mHoverLevelRange);
        nDDOIO::readData(r, pFlyData->mFlySpeed);
        nDDOIO::readData(r, pFlyData->mFlyAltitude);
    }
    nDDOIO::readData(r, mpCharParamEnemy->mScaleDispGui);
    return true;
}

__attribute__((weak)) bool rCharParamEnemy::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    w.writeU32(0x657063u);
    w.writeU32(DATA_VERSION);
    nDDOIO::writeData(w, mFlgEnemyFly);
    nDDOIO::writeData(w, mpCharParamEnemy->mAttackBasePhys);
    nDDOIO::writeData(w, mpCharParamEnemy->mAttackBaseMagic);
    nDDOIO::writeData(w, mpCharParamEnemy->mAttackWepPhys);
    nDDOIO::writeData(w, mpCharParamEnemy->mAttackWepMagic);
    nDDOIO::writeData(w, mpCharParamEnemy->mDefenceBasePhys);
    nDDOIO::writeData(w, mpCharParamEnemy->mDefenceBaseMagic);
    nDDOIO::writeData(w, mpCharParamEnemy->mDefenceWepPhys);
    nDDOIO::writeData(w, mpCharParamEnemy->mDefenceWepMagic);
    nDDOIO::writeData(w, mpCharParamEnemy->mPower);
    nDDOIO::writeData(w, mpCharParamEnemy->mWeight);
    nDDOIO::writeData(w, mpCharParamEnemy->mGuardAttackBase);
    nDDOIO::writeData(w, mpCharParamEnemy->mGuardDefenceBase);
    nDDOIO::writeData(w, mpCharParamEnemy->mGuardDefenceWep);
    nDDOIO::writeData(w, mpCharParamEnemy->mWeaponTypeSe);
    nDDOIO::writeData(w, mpCharParamEnemy->mEnemyBodySizeSe);
    nDDOIO::writeData(w, mpCharParamEnemy->mPushGroup);
    nDDOIO::writeData(w, mpCharParamEnemy->mScrAdjustType);
    nDDOIO::writeData(w, mpCharParamEnemy->mScrAdjustSize);
    nDDOIO::writeData(w, mpCharParamEnemy->mShakeCureRateRage);
    for (u32 i = 0; i < 4; i++) {
        nDDOIO::writeData(w, mpCharParamEnemy->mJumpAttackSpeed[i].mIsValid);
        nDDOIO::writeData(w, mpCharParamEnemy->mJumpAttackSpeed[i].mSpeedZ);
        nDDOIO::writeData(w, mpCharParamEnemy->mJumpAttackSpeed[i].mSpeedY);
        nDDOIO::writeData(w, mpCharParamEnemy->mJumpAttackSpeed[i].mGravity);
    }
    nDDOIO::writeData(w, mpCharParamEnemy->mFallDamageCheckHeight);
    nDDOIO::writeData(w, mpCharParamEnemy->mUseMotionBlendNum);
    nDDOIO::writeData(w, mpCharParamEnemy->mUseMotionHistory);
    nDDOIO::writeData(w, mpCharParamEnemy->mUseMotionHistoryNum);
    nDDOIO::writeData(w, mpCharParamEnemy->mReturnTerritoryContTime);
    nDDOIO::writeData(w, mpCharParamEnemy->mBeardownEffective);
    for (u32 i = 0; i < 10; i++) {
        nDDOIO::writeData(w, mpCharParamEnemy->mGuardCounter[i].mTimes);
        nDDOIO::writeData(w, mpCharParamEnemy->mGuardCounter[i].mPercent);
    }
    nDDOIO::writeData(w, mpCharParamEnemy->mGuardReactionCheckType);
    nDDOIO::writeData(w, mpCharParamEnemy->mEnemyScaleBase);
    nDDOIO::writeData(w, mpCharParamEnemy->mEnemyScaleThinkTable);
    nDDOIO::writeData(w, mpCharParamEnemy->mIsShakedActionEnemy);
    nDDOIO::writeData(w, mpCharParamEnemy->mHangdType);
    nDDOIO::writeData(w, mpCharParamEnemy->mcThinkMgrScaleParam);
    nDDOIO::writeData(w, mpCharParamEnemy->mEnemyLinkRadiusA);
    nDDOIO::writeData(w, mpCharParamEnemy->mEnemyLinkRadiusBOn);
    nDDOIO::writeData(w, mpCharParamEnemy->mEnemyLinkRadiusB);
    nDDOIO::writeDataArray(w, mpCharParamEnemy->mEvaluationPLJobs, 10u);
    nDDOIO::writeDataArray(w, mpCharParamEnemy->mEvaluationPLSex, 2u);
    nDDOIO::writeData(w, mpCharParamEnemy->mDownPerformanceOff);
    nDDOIO::writeData(w, mpCharParamEnemy->mIsDispDownGuage);
    nDDOIO::writeData(w, mpCharParamEnemy->mIsNoneAdbantageBGM);
    nDDOIO::writeData(w, mpCharParamEnemy->mIsUseEnchant);
    nDDOIO::writeData(w, mpCharParamEnemy->mEnchantType);
    nDDOIO::writeData(w, mpCharParamEnemy->mDamageSpecialAdjType);
    nDDOIO::writeData(w, mpCharParamEnemy->mDamageBounisFlag);
    nDDOIO::writeData(w, mpCharParamEnemy->mShrinkBounisShakeRate);
    nDDOIO::writeData(w, mpCharParamEnemy->mShakeRateSequence);
    if (mFlgEnemyFly && mpCharParamEnemy->isKindOf(cCharParamEnemyFly::DTI)) {
        cCharParamEnemyFly* pFlyData = static_cast<cCharParamEnemyFly*>(mpCharParamEnemy);
        if (pFlyData != nullptr) {
            nDDOIO::writeData(w, pFlyData->mHoverSpeed);
            nDDOIO::writeDataArray(w, pFlyData->mHoverAltitude, 4u);
            nDDOIO::writeData(w, pFlyData->mHoverLevelMax);
            nDDOIO::writeData(w, pFlyData->mHoverLevelRange);
            nDDOIO::writeData(w, pFlyData->mFlySpeed);
            nDDOIO::writeData(w, pFlyData->mFlyAltitude);
        }
    }
    nDDOIO::writeData(w, mpCharParamEnemy->mScaleDispGui);
    return true;
}

inline rCharParamEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCharParamEnemy::MyDTI rCharParamEnemy::DTI("rCharParamEnemy", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rCharParamEnemy::MyDTI::newInstance() const {
    return new (16u) rCharParamEnemy;
}

