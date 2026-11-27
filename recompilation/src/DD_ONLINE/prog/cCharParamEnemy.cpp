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
    s << MtProperty(static_cast<MtObject*>(this), "基礎物理攻撃力", &mAttackBasePhys, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "基礎魔法攻撃力", &mAttackBaseMagic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "装備物理攻撃力", &mAttackWepPhys, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "装備魔法攻撃力", &mAttackWepMagic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "基礎物理防御力", &mDefenceBasePhys, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "基礎魔法防御力", &mDefenceBaseMagic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "装備物理防御力", &mDefenceWepPhys, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "装備魔法防御力", &mDefenceWepMagic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "筋力", &mPower, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ガード基礎攻撃力", &mGuardAttackBase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ガード基礎防御力", &mGuardDefenceBase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ガード装備防御力", &mGuardDefenceWep, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "武器の種類", &mWeaponTypeSe, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "体のサイズ", &mEnemyBodySizeSe, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "プッシュグループ", &mPushGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SCR当たり属性", &mScrAdjustType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SCR当たりサイズ", &mScrAdjustSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "重量", &mWeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "モデルスケール値", &mEnemyScaleBase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "敵思考テーブルのスケール値", &mcThinkMgrScaleParam, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "揺さぶられアクションを取る", &mIsShakedActionEnemy, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "怒り時の揺さぶり値回復倍率", &mShakeCureRateRage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "つかまれのタイプ", &mHangdType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "揺さぶりゲージにダウン値使用", &mIsDispDownGuage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "エンチャント使う？", &mIsUseEnchant, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "エンチャントタイプ", &mEnchantType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJumpAttackSpeed", static_cast<MtObject*>(&mJumpAttackSpeed[0]), 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "ダメージを受ける高さ", &mFallDamageCheckHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ブレンド数", &mUseMotionBlendNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "履歴ブレンド使用", &mUseMotionHistory, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "履歴ブレンド数", &mUseMotionHistoryNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "リターンテリトリー継続タイム", &mReturnTerritoryContTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "押さえ付け効き易さ", &mBeardownEffective, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGuardCounter", static_cast<MtObject*>(&mGuardCounter[0]), 32u, 10u);
    s << MtProperty(static_cast<MtObject*>(this), "ガードリアクションチェック", &mGuardReactionCheckType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "明るいときのリンクする範囲", &mEnemyLinkRadiusA, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "暗い時のリンクする範囲を設定", &mEnemyLinkRadiusBOn, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "暗い時のリンクする範囲", &mEnemyLinkRadiusB, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "男性の場合", &mEvaluationPLSex[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "女性の場合", &mEvaluationPLSex[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "チャンスダウン時の演出をしない", &mDownPerformanceOff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "優勢曲をコールしない", &mIsNoneAdbantageBGM, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ダメージの特殊設定タイプ", &mDamageSpecialAdjType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ダメージボーナスフラグ", &mDamageBounisFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "のけぞり時に疲れ値が減る割合", &mShrinkBounisShakeRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "シーケンス有効時のゆさぶり補正倍率", &mShakeRateSequence, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "GUIの表示領域倍率", &mScaleDispGui, 0u, 0u);
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
    s << MtProperty(static_cast<MtObject*>(this), "有効フラグ", &mIsValid, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "前方速度", &mSpeedZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Ｙ初速", &mSpeedY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "重力", &mGravity, 0u, 0u);
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
    s << MtProperty(static_cast<MtObject*>(this), "ガード回数(以下)", &mTimes, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "反撃確率(％以下で反撃)", &mPercent, 0u, 0u);
}

MtUI* cCharParamEnemy::cGuardCounter::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cCharParamEnemy::cGuardCounter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCharParamEnemy::cGuardCounter::MyDTI cCharParamEnemy::cGuardCounter::DTI("cCharParamEnemy::cGuardCounter", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCharParamEnemy::cGuardCounter::MyDTI::newInstance() const {
    return new (16u) cCharParamEnemy::cGuardCounter;
}

