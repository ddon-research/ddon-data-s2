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

void* cCharParamEnemy::operator new(size_t sz, u32 align) {
    return cCharParamEnemy::getAllocator()->memAlloc(sz, align, cCharParamEnemy::DTI.getID());
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

void cCharParamEnemy::createProperty(MtPropertyList& s) {
    this->cCharParam::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "\345\237\272\347\244\216\347\211\251\347\220\206\346\224\273\346\222\203\345\212\233", &mAttackBasePhys, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\237\272\347\244\216\351\255\224\346\263\225\346\224\273\346\222\203\345\212\233", &mAttackBaseMagic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\243\205\345\202\231\347\211\251\347\220\206\346\224\273\346\222\203\345\212\233", &mAttackWepPhys, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\243\205\345\202\231\351\255\224\346\263\225\346\224\273\346\222\203\345\212\233", &mAttackWepMagic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\237\272\347\244\216\347\211\251\347\220\206\351\230\262\345\276\241\345\212\233", &mDefenceBasePhys, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\237\272\347\244\216\351\255\224\346\263\225\351\230\262\345\276\241\345\212\233", &mDefenceBaseMagic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\243\205\345\202\231\347\211\251\347\220\206\351\230\262\345\276\241\345\212\233", &mDefenceWepPhys, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\243\205\345\202\231\351\255\224\346\263\225\351\230\262\345\276\241\345\212\233", &mDefenceWepMagic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\255\213\345\212\233", &mPower, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\254\343\203\274\343\203\211\345\237\272\347\244\216\346\224\273\346\222\203\345\212\233", &mGuardAttackBase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\254\343\203\274\343\203\211\345\237\272\347\244\216\351\230\262\345\276\241\345\212\233", &mGuardDefenceBase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\254\343\203\274\343\203\211\350\243\205\345\202\231\351\230\262\345\276\241\345\212\233", &mGuardDefenceWep, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\255\246\345\231\250\343\201\256\347\250\256\351\241\236", &mWeaponTypeSe, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\344\275\223\343\201\256\343\202\265\343\202\244\343\202\272", &mEnemyBodySizeSe, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\227\343\203\203\343\202\267\343\203\245\343\202\260\343\203\253\343\203\274\343\203\227", &mPushGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SCR\345\275\223\343\201\237\343\202\212\345\261\236\346\200\247", &mScrAdjustType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SCR\345\275\223\343\201\237\343\202\212\343\202\265\343\202\244\343\202\272", &mScrAdjustSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\351\207\215\351\207\217", &mWeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\242\343\203\207\343\203\253\343\202\271\343\202\261\343\203\274\343\203\253\345\200\244", &mEnemyScaleBase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\225\265\346\200\235\350\200\203\343\203\206\343\203\274\343\203\226\343\203\253\343\201\256\343\202\271\343\202\261\343\203\274\343\203\253\345\200\244", &mcThinkMgrScaleParam, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\217\272\343\201\225\343\201\266\343\202\211\343\202\214\343\202\242\343\202\257\343\202\267\343\203\247\343\203\263\343\202\222\345\217\226\343\202\213", &mIsShakedActionEnemy, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\200\222\343\202\212\346\231\202\343\201\256\346\217\272\343\201\225\343\201\266\343\202\212\345\200\244\345\233\236\345\276\251\345\200\215\347\216\207", &mShakeCureRateRage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\201\244\343\201\213\343\201\276\343\202\214\343\201\256\343\202\277\343\202\244\343\203\227", &mHangdType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\217\272\343\201\225\343\201\266\343\202\212\343\202\262\343\203\274\343\202\270\343\201\253\343\203\200\343\202\246\343\203\263\345\200\244\344\275\277\347\224\250", &mIsDispDownGuage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\250\343\203\263\343\203\201\343\203\243\343\203\263\343\203\210\344\275\277\343\201\206\357\274\237", &mIsUseEnchant, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\250\343\203\263\343\203\201\343\203\243\343\203\263\343\203\210\343\202\277\343\202\244\343\203\227", &mEnchantType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJumpAttackSpeed", static_cast<MtObject*>(&mJumpAttackSpeed[0]), 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\200\343\203\241\343\203\274\343\202\270\343\202\222\345\217\227\343\201\221\343\202\213\351\253\230\343\201\225", &mFallDamageCheckHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\226\343\203\254\343\203\263\343\203\211\346\225\260", &mUseMotionBlendNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\261\245\346\255\264\343\203\226\343\203\254\343\203\263\343\203\211\344\275\277\347\224\250", &mUseMotionHistory, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\261\245\346\255\264\343\203\226\343\203\254\343\203\263\343\203\211\346\225\260", &mUseMotionHistoryNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\252\343\202\277\343\203\274\343\203\263\343\203\206\343\203\252\343\203\210\343\203\252\343\203\274\347\266\231\347\266\232\343\202\277\343\202\244\343\203\240", &mReturnTerritoryContTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\212\274\343\201\225\343\201\210\344\273\230\343\201\221\345\212\271\343\201\215\346\230\223\343\201\225", &mBeardownEffective, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGuardCounter", static_cast<MtObject*>(&mGuardCounter[0]), 32u, 10u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\254\343\203\274\343\203\211\343\203\252\343\202\242\343\202\257\343\202\267\343\203\247\343\203\263\343\203\201\343\202\247\343\203\203\343\202\257", &mGuardReactionCheckType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\230\216\343\202\213\343\201\204\343\201\250\343\201\215\343\201\256\343\203\252\343\203\263\343\202\257\343\201\231\343\202\213\347\257\204\345\233\262", &mEnemyLinkRadiusA, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\232\227\343\201\204\346\231\202\343\201\256\343\203\252\343\203\263\343\202\257\343\201\231\343\202\213\347\257\204\345\233\262\343\202\222\350\250\255\345\256\232", &mEnemyLinkRadiusBOn, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\232\227\343\201\204\346\231\202\343\201\256\343\203\252\343\203\263\343\202\257\343\201\231\343\202\213\347\257\204\345\233\262", &mEnemyLinkRadiusB, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\224\267\346\200\247\343\201\256\345\240\264\345\220\210", &mEvaluationPLSex[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\245\263\346\200\247\343\201\256\345\240\264\345\220\210", &mEvaluationPLSex[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\201\343\203\243\343\203\263\343\202\271\343\203\200\343\202\246\343\203\263\346\231\202\343\201\256\346\274\224\345\207\272\343\202\222\343\201\227\343\201\252\343\201\204", &mDownPerformanceOff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\204\252\345\213\242\346\233\262\343\202\222\343\202\263\343\203\274\343\203\253\343\201\227\343\201\252\343\201\204", &mIsNoneAdbantageBGM, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\200\343\203\241\343\203\274\343\202\270\343\201\256\347\211\271\346\256\212\350\250\255\345\256\232\343\202\277\343\202\244\343\203\227", &mDamageSpecialAdjType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\200\343\203\241\343\203\274\343\202\270\343\203\234\343\203\274\343\203\212\343\202\271\343\203\225\343\203\251\343\202\260", &mDamageBounisFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\201\256\343\201\221\343\201\236\343\202\212\346\231\202\343\201\253\347\226\262\343\202\214\345\200\244\343\201\214\346\270\233\343\202\213\345\211\262\345\220\210", &mShrinkBounisShakeRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\267\343\203\274\343\202\261\343\203\263\343\202\271\346\234\211\345\212\271\346\231\202\343\201\256\343\202\206\343\201\225\343\201\266\343\202\212\350\243\234\346\255\243\345\200\215\347\216\207", &mShakeRateSequence, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "GUI\343\201\256\350\241\250\347\244\272\351\240\230\345\237\237\345\200\215\347\216\207", &mScaleDispGui, 0u, 0u);
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

void cCharParamEnemy::cJumpAttackSpeed::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\346\234\211\345\212\271\343\203\225\343\203\251\343\202\260", &mIsValid, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\211\215\346\226\271\351\200\237\345\272\246", &mSpeedZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\357\274\271\345\210\235\351\200\237", &mSpeedY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\351\207\215\345\212\233", &mGravity, 0u, 0u);
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

void cCharParamEnemy::cGuardCounter::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\254\343\203\274\343\203\211\345\233\236\346\225\260(\344\273\245\344\270\213)", &mTimes, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\217\215\346\222\203\347\242\272\347\216\207(\357\274\205\344\273\245\344\270\213\343\201\247\345\217\215\346\222\203)", &mPercent, 0u, 0u);
}

MtUI* cCharParamEnemy::cGuardCounter::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cCharParamEnemy::cGuardCounter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCharParamEnemy::cGuardCounter::MyDTI cCharParamEnemy::cGuardCounter::DTI("cCharParamEnemy::cGuardCounter", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCharParamEnemy::cGuardCounter::MyDTI::newInstance() const {
    return new (16u) cCharParamEnemy::cGuardCounter;
}

