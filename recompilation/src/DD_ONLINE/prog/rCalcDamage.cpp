// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rCalcDamage.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cDmJobAdjParam>::allocData(unsigned int);
#endif

const MtDTI& cAdjLimitParam::getDTI() const {
    return cAdjLimitParam::DTI;
}

cAdjLimitParam::cAdjLimitParam() {
    memset(static_cast<void*>(&mGuardAtkAdjMax[0]), 0, 792ul);
    mHolyAbsorpMax = 3000;
    mHolyAbsorpMin = 0;
    mDamageMax = 9999.0f;
    mDamageMin = 0.0f;
}

inline cAdjLimitParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAdjLimitParam::MyDTI cAdjLimitParam::DTI("cAdjLimitParam", &::MtObject::DTI, 816ul, 0u, 0u);

MtObject* cAdjLimitParam::MyDTI::newInstance() const {
    return new (16u) cAdjLimitParam;
}

const MtDTI& cBlowSaveEmLvParam::getDTI() const {
    return cBlowSaveEmLvParam::DTI;
}

void cBlowSaveEmLvParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Lv", &mKeyLv, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "減算値", &mSaveRate, 0u, 0u);
}

inline cBlowSaveEmLvParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cBlowSaveEmLvParam::MyDTI cBlowSaveEmLvParam::DTI("cBlowSaveEmLvParam", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cBlowSaveEmLvParam::MyDTI::newInstance() const {
    return new (16u) cBlowSaveEmLvParam;
}

const MtDTI& cCalcDamageAtdmAdj::getDTI() const {
    return cCalcDamageAtdmAdj::DTI;
}

void cCalcDamageAtdmAdj::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "攻防比", &mAtdmRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ダメージ補正", &mDamageAdj, 0u, 0u);
}

inline cCalcDamageAtdmAdj::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCalcDamageAtdmAdj::MyDTI cCalcDamageAtdmAdj::DTI("cCalcDamageAtdmAdj", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCalcDamageAtdmAdj::MyDTI::newInstance() const {
    return new (16u) cCalcDamageAtdmAdj;
}

const MtDTI& cCalcDamageAtdmAdjRate::getDTI() const {
    return cCalcDamageAtdmAdjRate::DTI;
}

void cCalcDamageAtdmAdjRate::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "武器攻撃防御力", &mKeyValue, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "攻防比への補正", &mAtdmAdjRate, 0u, 0u);
}

inline cCalcDamageAtdmAdjRate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCalcDamageAtdmAdjRate::MyDTI cCalcDamageAtdmAdjRate::DTI("cCalcDamageAtdmAdjRate", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCalcDamageAtdmAdjRate::MyDTI::newInstance() const {
    return new (16u) cCalcDamageAtdmAdjRate;
}

const MtDTI& cCalcDamageLvAdj::getDTI() const {
    return cCalcDamageLvAdj::DTI;
}

void cCalcDamageLvAdj::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "レベル差", &mLvDiff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ダメージ補正", &mLvAdj[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "のけぞり補正", &mLvAdj[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ぶっ飛び補正", &mLvAdj[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "状態異常補正", &mLvAdj[3], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ダウン値補正", &mLvAdj[4], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "スタミナダメージ補正", &mLvAdj[5], 0u, 0u);
}

inline cCalcDamageLvAdj::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCalcDamageLvAdj::MyDTI cCalcDamageLvAdj::DTI("cCalcDamageLvAdj", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cCalcDamageLvAdj::MyDTI::newInstance() const {
    return new (16u) cCalcDamageLvAdj;
}

const MtDTI& cDamageSaveEmLvParam::getDTI() const {
    return cDamageSaveEmLvParam::DTI;
}

void cDamageSaveEmLvParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Lv", &mKeyLv, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "減算値係数A", &mSaveParamA, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "減算値係数B", &mSaveParamB, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "減算値係数C", &mSaveParamC, 0u, 0u);
}

inline cDamageSaveEmLvParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cDamageSaveEmLvParam::MyDTI cDamageSaveEmLvParam::DTI("cDamageSaveEmLvParam", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cDamageSaveEmLvParam::MyDTI::newInstance() const {
    return new (16u) cDamageSaveEmLvParam;
}

const MtDTI& cDamageSpecialAdj::getDTI() const {
    return cDamageSpecialAdj::DTI;
}

void cDamageSpecialAdj::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "ダメージへの割合", &mDamageRate, 0u, 0u);
}

inline cDamageSpecialAdj::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cDamageSpecialAdj::MyDTI cDamageSpecialAdj::DTI("cDamageSpecialAdj", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cDamageSpecialAdj::MyDTI::newInstance() const {
    return new (16u) cDamageSpecialAdj;
}

const MtDTI& cDmJobAdjParam::getDTI() const {
    return cDmJobAdjParam::DTI;
}

void cDmJobAdjParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "ジョブタイプ", &mJobType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "アクション倍率補正", &mActionRateAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ダメージ補正", &mDamageAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "スタミナダメージ補正", &mStaminaDamageAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "エンチャントダメージ補正", &mEnchantDamageAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "疲労値ダメージ補正", &mTiredDamageAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "チャンス攻力ダメージ補正", &mChanceDamageAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "アビリティ吹き飛ばし力補正", &mAbilityBlowAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "人間敵状態異常加算補正", &mHumanEmOcdAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "攻防比物理最大値", &mAtDmRateMaxPhys, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "攻防比魔法最大値", &mAtDmRateMaxMagic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "回復計算補正A", &mHealBaseMagicAdjAdd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "回復計算補正B", &mHealBaseMagicAdjMulti, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "回復計算補正C", &mHealWepMagicAdjAdd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "回復計算補正D", &mHealWepMagicAdjMulti, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "吹き飛ばし値へ減算値係数", &mShrinkBlowSaveAdj, 0u, 0u);
}

inline cDmJobAdjParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cDmJobAdjParam::MyDTI cDmJobAdjParam::DTI("cDmJobAdjParam", &::MtObject::DTI, 72ul, 0u, 0u);

MtObject* cDmJobAdjParam::MyDTI::newInstance() const {
    return new (16u) cDmJobAdjParam;
}

const MtDTI& cDmJobPawnAdjParam::getDTI() const {
    return cDmJobPawnAdjParam::DTI;
}

void cDmJobPawnAdjParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "ジョブタイプ", &mJobType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "素体攻撃に対する補正", &mBaseAttackAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "素体魔法攻撃に対する補正", &mBaseMagicAttackAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "のけぞりぶっ飛び攻撃に対する補正", &mBaseBlowShrinkAdj, 0u, 0u);
}

inline cDmJobPawnAdjParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cDmJobPawnAdjParam::MyDTI cDmJobPawnAdjParam::DTI("cDmJobPawnAdjParam", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cDmJobPawnAdjParam::MyDTI::newInstance() const {
    return new (16u) cDmJobPawnAdjParam;
}

const MtDTI& cDmLvPawnAdjParam::getDTI() const {
    return cDmLvPawnAdjParam::DTI;
}

void cDmLvPawnAdjParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Lv", &mKeyLv, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "LV下駄(素体)", &mLvAdjRateBase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "LV下駄(Wep)", &mLvAdjRateWep, 0u, 0u);
}

inline cDmLvPawnAdjParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cDmLvPawnAdjParam::MyDTI cDmLvPawnAdjParam::DTI("cDmLvPawnAdjParam", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cDmLvPawnAdjParam::MyDTI::newInstance() const {
    return new (16u) cDmLvPawnAdjParam;
}

const MtDTI& cErosionShakeConvert::getDTI() const {
    return cErosionShakeConvert::DTI;
}

void cErosionShakeConvert::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "攻撃揺さぶりレート", &mKeyShakesRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "コアポイントの加算時間(Frame)", &mAddCoreTime, 0u, 0u);
}

inline cErosionShakeConvert::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cErosionShakeConvert::MyDTI cErosionShakeConvert::DTI("cErosionShakeConvert", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cErosionShakeConvert::MyDTI::newInstance() const {
    return new (16u) cErosionShakeConvert;
}

const MtDTI& cShrinkBlowValue::getDTI() const {
    return cShrinkBlowValue::DTI;
}

void cShrinkBlowValue::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "タイプ", &mDamageType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "威力設定", &mLv, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "XZ軸方向速度", &mSpeedXZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "XZ軸方向減速", &mAccelerateXZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Y軸方向速度", &mSpeedY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Y軸方向減速", &mGravityY, 0u, 0u);
}

inline cShrinkBlowValue::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShrinkBlowValue::MyDTI cShrinkBlowValue::DTI("cShrinkBlowValue", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cShrinkBlowValue::MyDTI::newInstance() const {
    return new (16u) cShrinkBlowValue;
}

const MtDTI& rAdjLimitParam::getDTI() const {
    return rAdjLimitParam::DTI;
}

bool rAdjLimitParam::loadData(MtDataReader& r, cAdjLimitParam* pData) {
    pData->mGuardAtkAdjMax[0] = r.readF32();
    pData->mGuardAtkAdjMin[0] = r.readF32();
    pData->mGuardAtkAdjMax[1] = r.readF32();
    pData->mGuardAtkAdjMin[1] = r.readF32();
    pData->mGuardAtkAdjMax[2] = r.readF32();
    pData->mGuardAtkAdjMin[2] = r.readF32();
    pData->mGuardAtkAdjMax[3] = r.readF32();
    pData->mGuardAtkAdjMin[3] = r.readF32();
    pData->mGuardAtkAdjMax[4] = r.readF32();
    pData->mGuardAtkAdjMin[4] = r.readF32();
    pData->mGuardDefAdjMax[0] = r.readF32();
    pData->mGuardDefAdjMin[0] = r.readF32();
    pData->mGuardDefAdjMax[1] = r.readF32();
    pData->mGuardDefAdjMin[1] = r.readF32();
    pData->mGuardDefAdjMax[2] = r.readF32();
    pData->mGuardDefAdjMin[2] = r.readF32();
    pData->mGuardDefAdjMax[3] = r.readF32();
    pData->mGuardDefAdjMin[3] = r.readF32();
    pData->mGuardDefAdjMax[4] = r.readF32();
    pData->mGuardDefAdjMin[4] = r.readF32();
    pData->mStaminaDamageAdjMax[0] = r.readF32();
    pData->mStaminaDamageAdjMin[0] = r.readF32();
    pData->mStaminaDamageAdjMax[1] = r.readF32();
    pData->mStaminaDamageAdjMin[1] = r.readF32();
    pData->mStaminaDamageAdjMax[2] = r.readF32();
    pData->mStaminaDamageAdjMin[2] = r.readF32();
    pData->mStaminaDamageAdjMax[3] = r.readF32();
    pData->mStaminaDamageAdjMin[3] = r.readF32();
    pData->mStaminaDamageAdjMax[4] = r.readF32();
    pData->mStaminaDamageAdjMin[4] = r.readF32();
    pData->mHpDamageAtkAdjMax[0] = r.readF32();
    pData->mHpDamageAtkAdjMin[0] = r.readF32();
    pData->mHpDamageAtkAdjMax[1] = r.readF32();
    pData->mHpDamageAtkAdjMin[1] = r.readF32();
    pData->mHpDamageAtkAdjMax[2] = r.readF32();
    pData->mHpDamageAtkAdjMin[2] = r.readF32();
    pData->mHpDamageAtkAdjMax[3] = r.readF32();
    pData->mHpDamageAtkAdjMin[3] = r.readF32();
    pData->mHpDamageAtkAdjMax[4] = r.readF32();
    pData->mHpDamageAtkAdjMin[4] = r.readF32();
    pData->mHpDamageAtkAdjMax[5] = r.readF32();
    pData->mHpDamageAtkAdjMin[5] = r.readF32();
    pData->mHpDamageAtkAdjMax[6] = r.readF32();
    pData->mHpDamageAtkAdjMin[6] = r.readF32();
    pData->mHpDamageDefAdjMax[0] = r.readF32();
    pData->mHpDamageDefAdjMin[0] = r.readF32();
    pData->mHpDamageDefAdjMax[1] = r.readF32();
    pData->mHpDamageDefAdjMin[1] = r.readF32();
    pData->mHpDamageDefAdjMax[2] = r.readF32();
    pData->mHpDamageDefAdjMin[2] = r.readF32();
    pData->mHpDamageDefAdjMax[3] = r.readF32();
    pData->mHpDamageDefAdjMin[3] = r.readF32();
    pData->mHpDamageDefAdjMax[4] = r.readF32();
    pData->mHpDamageDefAdjMin[4] = r.readF32();
    pData->mHpDamageDefAdjMax[5] = r.readF32();
    pData->mHpDamageDefAdjMin[5] = r.readF32();
    pData->mHpDamageDefAdjMax[6] = r.readF32();
    pData->mHpDamageDefAdjMin[6] = r.readF32();
    pData->mShrinkAtkAdjMax[0] = r.readF32();
    pData->mShrinkAtkAdjMin[0] = r.readF32();
    pData->mShrinkAtkAdjMax[1] = r.readF32();
    pData->mShrinkAtkAdjMin[1] = r.readF32();
    pData->mShrinkAtkAdjMax[2] = r.readF32();
    pData->mShrinkAtkAdjMin[2] = r.readF32();
    pData->mShrinkAtkAdjMax[3] = r.readF32();
    pData->mShrinkAtkAdjMin[3] = r.readF32();
    pData->mShrinkAtkAdjMax[4] = r.readF32();
    pData->mShrinkAtkAdjMin[4] = r.readF32();
    pData->mShrinkDefAdjMax[0] = r.readF32();
    pData->mShrinkDefAdjMin[0] = r.readF32();
    pData->mShrinkDefAdjMax[1] = r.readF32();
    pData->mShrinkDefAdjMin[1] = r.readF32();
    pData->mShrinkDefAdjMax[2] = r.readF32();
    pData->mShrinkDefAdjMin[2] = r.readF32();
    pData->mShrinkDefAdjMax[3] = r.readF32();
    pData->mShrinkDefAdjMin[3] = r.readF32();
    pData->mShrinkDefAdjMax[4] = r.readF32();
    pData->mShrinkDefAdjMin[4] = r.readF32();
    pData->mBlowAtkAdjMax[0] = r.readF32();
    pData->mBlowAtkAdjMin[0] = r.readF32();
    pData->mBlowAtkAdjMax[1] = r.readF32();
    pData->mBlowAtkAdjMin[1] = r.readF32();
    pData->mBlowAtkAdjMax[2] = r.readF32();
    pData->mBlowAtkAdjMin[2] = r.readF32();
    pData->mBlowAtkAdjMax[3] = r.readF32();
    pData->mBlowAtkAdjMin[3] = r.readF32();
    pData->mBlowAtkAdjMax[4] = r.readF32();
    pData->mBlowAtkAdjMin[4] = r.readF32();
    pData->mBlowDefAdjMax[0] = r.readF32();
    pData->mBlowDefAdjMin[0] = r.readF32();
    pData->mBlowDefAdjMax[1] = r.readF32();
    pData->mBlowDefAdjMin[1] = r.readF32();
    pData->mBlowDefAdjMax[2] = r.readF32();
    pData->mBlowDefAdjMin[2] = r.readF32();
    pData->mBlowDefAdjMax[3] = r.readF32();
    pData->mBlowDefAdjMin[3] = r.readF32();
    pData->mBlowDefAdjMax[4] = r.readF32();
    pData->mBlowDefAdjMin[4] = r.readF32();
    pData->mShakeAtkAdjMax[0] = r.readF32();
    pData->mShakeAtkAdjMin[0] = r.readF32();
    pData->mShakeAtkAdjMax[1] = r.readF32();
    pData->mShakeAtkAdjMin[1] = r.readF32();
    pData->mShakeAtkAdjMax[2] = r.readF32();
    pData->mShakeAtkAdjMin[2] = r.readF32();
    pData->mShakeAtkAdjMax[3] = r.readF32();
    pData->mShakeAtkAdjMin[3] = r.readF32();
    pData->mShakeAtkAdjMax[4] = r.readF32();
    pData->mShakeAtkAdjMin[4] = r.readF32();
    pData->mShakeDefAdjMax[0] = r.readF32();
    pData->mShakeDefAdjMin[0] = r.readF32();
    pData->mShakeDefAdjMax[1] = r.readF32();
    pData->mShakeDefAdjMin[1] = r.readF32();
    pData->mShakeDefAdjMax[2] = r.readF32();
    pData->mShakeDefAdjMin[2] = r.readF32();
    pData->mShakeDefAdjMax[3] = r.readF32();
    pData->mShakeDefAdjMin[3] = r.readF32();
    pData->mShakeDefAdjMax[4] = r.readF32();
    pData->mShakeDefAdjMin[4] = r.readF32();
    pData->mDownAtkAdjMax[0] = r.readF32();
    pData->mDownAtkAdjMin[0] = r.readF32();
    pData->mDownAtkAdjMax[1] = r.readF32();
    pData->mDownAtkAdjMin[1] = r.readF32();
    pData->mDownAtkAdjMax[2] = r.readF32();
    pData->mDownAtkAdjMin[2] = r.readF32();
    pData->mDownAtkAdjMax[3] = r.readF32();
    pData->mDownAtkAdjMin[3] = r.readF32();
    pData->mDownAtkAdjMax[4] = r.readF32();
    pData->mDownAtkAdjMin[4] = r.readF32();
    pData->mDownDefAdjMax[0] = r.readF32();
    pData->mDownDefAdjMin[0] = r.readF32();
    pData->mDownDefAdjMax[1] = r.readF32();
    pData->mDownDefAdjMin[1] = r.readF32();
    pData->mDownDefAdjMax[2] = r.readF32();
    pData->mDownDefAdjMin[2] = r.readF32();
    pData->mDownDefAdjMax[3] = r.readF32();
    pData->mDownDefAdjMin[3] = r.readF32();
    pData->mDownDefAdjMax[4] = r.readF32();
    pData->mDownDefAdjMin[4] = r.readF32();
    pData->mOcdAtkAdjMax[0] = r.readF32();
    pData->mOcdAtkAdjMin[0] = r.readF32();
    pData->mOcdAtkAdjMax[1] = r.readF32();
    pData->mOcdAtkAdjMin[1] = r.readF32();
    pData->mOcdAtkAdjMax[2] = r.readF32();
    pData->mOcdAtkAdjMin[2] = r.readF32();
    pData->mOcdAtkAdjMax[3] = r.readF32();
    pData->mOcdAtkAdjMin[3] = r.readF32();
    pData->mOcdAtkAdjMax[4] = r.readF32();
    pData->mOcdAtkAdjMin[4] = r.readF32();
    pData->mOcdDefAdjMax[0] = r.readF32();
    pData->mOcdDefAdjMin[0] = r.readF32();
    pData->mOcdDefAdjMax[1] = r.readF32();
    pData->mOcdDefAdjMin[1] = r.readF32();
    pData->mOcdDefAdjMax[2] = r.readF32();
    pData->mOcdDefAdjMin[2] = r.readF32();
    pData->mOcdDefAdjMax[3] = r.readF32();
    pData->mOcdDefAdjMin[3] = r.readF32();
    pData->mOcdDefAdjMax[4] = r.readF32();
    pData->mOcdDefAdjMin[4] = r.readF32();
    pData->mHpHealAtkAdjMax[0] = r.readF32();
    pData->mHpHealAtkAdjMin[0] = r.readF32();
    pData->mHpHealAtkAdjMax[1] = r.readF32();
    pData->mHpHealAtkAdjMin[1] = r.readF32();
    pData->mHpHealAtkAdjMax[2] = r.readF32();
    pData->mHpHealAtkAdjMin[2] = r.readF32();
    pData->mHpHealAtkAdjMax[3] = r.readF32();
    pData->mHpHealAtkAdjMin[3] = r.readF32();
    pData->mHpHealAtkAdjMax[4] = r.readF32();
    pData->mHpHealAtkAdjMin[4] = r.readF32();
    pData->mHpHealDefAdjMax[0] = r.readF32();
    pData->mHpHealDefAdjMin[0] = r.readF32();
    pData->mHpHealDefAdjMax[1] = r.readF32();
    pData->mHpHealDefAdjMin[1] = r.readF32();
    pData->mHpHealDefAdjMax[2] = r.readF32();
    pData->mHpHealDefAdjMin[2] = r.readF32();
    pData->mHpHealDefAdjMax[3] = r.readF32();
    pData->mHpHealDefAdjMin[3] = r.readF32();
    pData->mHpHealDefAdjMax[4] = r.readF32();
    pData->mHpHealDefAdjMin[4] = r.readF32();
    pData->mStaminaHealAtkAdjMax[0] = r.readF32();
    pData->mStaminaHealAtkAdjMin[0] = r.readF32();
    pData->mStaminaHealAtkAdjMax[1] = r.readF32();
    pData->mStaminaHealAtkAdjMin[1] = r.readF32();
    pData->mStaminaHealAtkAdjMax[2] = r.readF32();
    pData->mStaminaHealAtkAdjMin[2] = r.readF32();
    pData->mStaminaHealAtkAdjMax[3] = r.readF32();
    pData->mStaminaHealAtkAdjMin[3] = r.readF32();
    pData->mStaminaHealAtkAdjMax[4] = r.readF32();
    pData->mStaminaHealAtkAdjMin[4] = r.readF32();
    pData->mStaminaHealDefAdjMax[0] = r.readF32();
    pData->mStaminaHealDefAdjMin[0] = r.readF32();
    pData->mStaminaHealDefAdjMax[1] = r.readF32();
    pData->mStaminaHealDefAdjMin[1] = r.readF32();
    pData->mStaminaHealDefAdjMax[2] = r.readF32();
    pData->mStaminaHealDefAdjMin[2] = r.readF32();
    pData->mStaminaHealDefAdjMax[3] = r.readF32();
    pData->mStaminaHealDefAdjMin[3] = r.readF32();
    pData->mStaminaHealDefAdjMax[4] = r.readF32();
    pData->mStaminaHealDefAdjMin[4] = r.readF32();
    nDDOIO::readData(r, pData->mHolyAbsorpMax);
    nDDOIO::readData(r, pData->mHolyAbsorpMin);
    nDDOIO::readData(r, pData->mDamageMax);
    nDDOIO::readData(r, pData->mDamageMin);
    return true;
}

MT_CTSTR rAdjLimitParam::getExt() const {
    return "alp";
}

u32 rAdjLimitParam::getDataVersion() const {
    return 5;
}

inline rAdjLimitParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAdjLimitParam::MyDTI rAdjLimitParam::DTI("rAdjLimitParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rAdjLimitParam::MyDTI::newInstance() const {
    return new (16u) rAdjLimitParam;
}

const MtDTI& rBlowSaveEmLvParam::getDTI() const {
    return rBlowSaveEmLvParam::DTI;
}

bool rBlowSaveEmLvParam::loadData(MtDataReader& in, cBlowSaveEmLvParam* pData) {
    nDDOIO::readData(in, pData->mKeyLv);
    nDDOIO::readData(in, pData->mSaveRate);
    return true;
}

MT_CTSTR rBlowSaveEmLvParam::getExt() const {
    return "blow_save";
}

u32 rBlowSaveEmLvParam::getDataVersion() const {
    return 2;
}

inline rBlowSaveEmLvParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rBlowSaveEmLvParam::MyDTI rBlowSaveEmLvParam::DTI("rBlowSaveEmLvParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rBlowSaveEmLvParam::MyDTI::newInstance() const {
    return new (16u) rBlowSaveEmLvParam;
}

const MtDTI& rCalcDamageAtdmAdj::getDTI() const {
    return rCalcDamageAtdmAdj::DTI;
}

bool rCalcDamageAtdmAdj::loadData(MtDataReader& in, cCalcDamageAtdmAdj* pData) {
    nDDOIO::readData(in, pData->mAtdmRate);
    nDDOIO::readData(in, pData->mDamageAdj);
    return true;
}

MT_CTSTR rCalcDamageAtdmAdj::getExt() const {
    return "cda";
}

u32 rCalcDamageAtdmAdj::getDataVersion() const {
    return 1;
}

inline rCalcDamageAtdmAdj::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCalcDamageAtdmAdj::MyDTI rCalcDamageAtdmAdj::DTI("rCalcDamageAtdmAdj", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCalcDamageAtdmAdj::MyDTI::newInstance() const {
    return new (16u) rCalcDamageAtdmAdj;
}

const MtDTI& rCalcDamageAtdmAdjRate::getDTI() const {
    return rCalcDamageAtdmAdjRate::DTI;
}

bool rCalcDamageAtdmAdjRate::loadData(MtDataReader& in, cCalcDamageAtdmAdjRate* pData) {
    nDDOIO::readData(in, pData->mKeyValue);
    nDDOIO::readData(in, pData->mAtdmAdjRate);
    return true;
}

MT_CTSTR rCalcDamageAtdmAdjRate::getExt() const {
    return "cdarate";
}

u32 rCalcDamageAtdmAdjRate::getDataVersion() const {
    return 1;
}

inline rCalcDamageAtdmAdjRate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCalcDamageAtdmAdjRate::MyDTI rCalcDamageAtdmAdjRate::DTI("rCalcDamageAtdmAdjRate", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCalcDamageAtdmAdjRate::MyDTI::newInstance() const {
    return new (16u) rCalcDamageAtdmAdjRate;
}

const MtDTI& rCalcDamageLvAdj::getDTI() const {
    return rCalcDamageLvAdj::DTI;
}

bool rCalcDamageLvAdj::loadData(MtDataReader& in, cCalcDamageLvAdj* pData) {
    pData->mLvDiff = in.readS16();
    pData->mLvAdj[0] = in.readF32();
    pData->mLvAdj[1] = in.readF32();
    pData->mLvAdj[2] = in.readF32();
    pData->mLvAdj[3] = in.readF32();
    pData->mLvAdj[4] = in.readF32();
    pData->mLvAdj[5] = in.readF32();
    return true;
}

MT_CTSTR rCalcDamageLvAdj::getExt() const {
    return "cdl";
}

u32 rCalcDamageLvAdj::getDataVersion() const {
    return 17;
}

inline rCalcDamageLvAdj::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCalcDamageLvAdj::MyDTI rCalcDamageLvAdj::DTI("rCalcDamageLvAdj", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCalcDamageLvAdj::MyDTI::newInstance() const {
    return new (16u) rCalcDamageLvAdj;
}

const MtDTI& rDamageSaveEmLvParam::getDTI() const {
    return rDamageSaveEmLvParam::DTI;
}

bool rDamageSaveEmLvParam::loadData(MtDataReader& in, cDamageSaveEmLvParam* pData) {
    nDDOIO::readData(in, pData->mKeyLv);
    nDDOIO::readData(in, pData->mSaveParamA);
    nDDOIO::readData(in, pData->mSaveParamB);
    nDDOIO::readData(in, pData->mSaveParamC);
    return true;
}

MT_CTSTR rDamageSaveEmLvParam::getExt() const {
    return "damage_save";
}

u32 rDamageSaveEmLvParam::getDataVersion() const {
    return 2;
}

inline rDamageSaveEmLvParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDamageSaveEmLvParam::MyDTI rDamageSaveEmLvParam::DTI("rDamageSaveEmLvParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rDamageSaveEmLvParam::MyDTI::newInstance() const {
    return new (16u) rDamageSaveEmLvParam;
}

const MtDTI& rDamageSpecialAdj::getDTI() const {
    return rDamageSpecialAdj::DTI;
}

bool rDamageSpecialAdj::loadData(MtDataReader& in, cDamageSpecialAdj* pData) {
    nDDOIO::readData(in, pData->mDamageRate);
    return true;
}

MT_CTSTR rDamageSpecialAdj::getExt() const {
    return "damage_spAdj";
}

u32 rDamageSpecialAdj::getDataVersion() const {
    return 2;
}

inline rDamageSpecialAdj::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDamageSpecialAdj::MyDTI rDamageSpecialAdj::DTI("rDamageSpecialAdj", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rDamageSpecialAdj::MyDTI::newInstance() const {
    return new (16u) rDamageSpecialAdj;
}

const MtDTI& rDmJobAdjParam::getDTI() const {
    return rDmJobAdjParam::DTI;
}

bool rDmJobAdjParam::loadData(MtDataReader& in, cDmJobAdjParam* pData) {
    nDDOIO::readData(in, pData->mJobType);
    nDDOIO::readData(in, pData->mActionRateAdj);
    nDDOIO::readData(in, pData->mDamageAdj);
    nDDOIO::readData(in, pData->mStaminaDamageAdj);
    nDDOIO::readData(in, pData->mEnchantDamageAdj);
    nDDOIO::readData(in, pData->mAbilityBlowAdj);
    nDDOIO::readData(in, pData->mHumanEmOcdAdj);
    nDDOIO::readData(in, pData->mTiredDamageAdj);
    nDDOIO::readData(in, pData->mChanceDamageAdj);
    nDDOIO::readData(in, pData->mAtDmRateMaxPhys);
    nDDOIO::readData(in, pData->mAtDmRateMaxMagic);
    nDDOIO::readData(in, pData->mHealBaseMagicAdjAdd);
    nDDOIO::readData(in, pData->mHealBaseMagicAdjMulti);
    nDDOIO::readData(in, pData->mHealWepMagicAdjAdd);
    nDDOIO::readData(in, pData->mHealWepMagicAdjMulti);
    nDDOIO::readData(in, pData->mShrinkBlowSaveAdj);
    return true;
}

MT_CTSTR rDmJobAdjParam::getExt() const {
    return "dja";
}

u32 rDmJobAdjParam::getDataVersion() const {
    return 9;
}

inline rDmJobAdjParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDmJobAdjParam::MyDTI rDmJobAdjParam::DTI("rDmJobAdjParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rDmJobAdjParam::MyDTI::newInstance() const {
    return new (16u) rDmJobAdjParam;
}

const MtDTI& rDmJobPawnAdjParam::getDTI() const {
    return rDmJobPawnAdjParam::DTI;
}

bool rDmJobPawnAdjParam::loadData(MtDataReader& in, cDmJobPawnAdjParam* pData) {
    nDDOIO::readData(in, pData->mJobType);
    nDDOIO::readData(in, pData->mBaseAttackAdj);
    nDDOIO::readData(in, pData->mBaseMagicAttackAdj);
    nDDOIO::readData(in, pData->mBaseBlowShrinkAdj);
    return true;
}

MT_CTSTR rDmJobPawnAdjParam::getExt() const {
    return "dja_pawn";
}

u32 rDmJobPawnAdjParam::getDataVersion() const {
    return 2;
}

inline rDmJobPawnAdjParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDmJobPawnAdjParam::MyDTI rDmJobPawnAdjParam::DTI("rDmJobPawnAdjParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rDmJobPawnAdjParam::MyDTI::newInstance() const {
    return new (16u) rDmJobPawnAdjParam;
}

const MtDTI& rDmLvPawnAdjParam::getDTI() const {
    return rDmLvPawnAdjParam::DTI;
}

bool rDmLvPawnAdjParam::loadData(MtDataReader& in, cDmLvPawnAdjParam* pData) {
    nDDOIO::readData(in, pData->mKeyLv);
    nDDOIO::readData(in, pData->mLvAdjRateBase);
    nDDOIO::readData(in, pData->mLvAdjRateWep);
    return true;
}

MT_CTSTR rDmLvPawnAdjParam::getExt() const {
    return "cdl_pawn";
}

u32 rDmLvPawnAdjParam::getDataVersion() const {
    return 2;
}

inline rDmLvPawnAdjParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDmLvPawnAdjParam::MyDTI rDmLvPawnAdjParam::DTI("rDmLvPawnAdjParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rDmLvPawnAdjParam::MyDTI::newInstance() const {
    return new (16u) rDmLvPawnAdjParam;
}

const MtDTI& rErosionShakeConvert::getDTI() const {
    return rErosionShakeConvert::DTI;
}

bool rErosionShakeConvert::loadData(MtDataReader& in, cErosionShakeConvert* pData) {
    nDDOIO::readData(in, pData->mKeyShakesRate);
    nDDOIO::readData(in, pData->mAddCoreTime);
    return true;
}

MT_CTSTR rErosionShakeConvert::getExt() const {
    return "ero_addTime";
}

u32 rErosionShakeConvert::getDataVersion() const {
    return 1;
}

inline rErosionShakeConvert::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rErosionShakeConvert::MyDTI rErosionShakeConvert::DTI("rErosionShakeConvert", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rErosionShakeConvert::MyDTI::newInstance() const {
    return new (16u) rErosionShakeConvert;
}

const MtDTI& rShrinkBlowValue::getDTI() const {
    return rShrinkBlowValue::DTI;
}

bool rShrinkBlowValue::loadData(MtDataReader& in, cShrinkBlowValue* pData) {
    nDDOIO::readData(in, pData->mDamageType);
    nDDOIO::readData(in, pData->mLv);
    nDDOIO::readData(in, pData->mSpeedXZ);
    nDDOIO::readData(in, pData->mAccelerateXZ);
    nDDOIO::readData(in, pData->mSpeedY);
    nDDOIO::readData(in, pData->mGravityY);
    return true;
}

MT_CTSTR rShrinkBlowValue::getExt() const {
    return "sbv";
}

u32 rShrinkBlowValue::getDataVersion() const {
    return 2;
}

inline rShrinkBlowValue::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rShrinkBlowValue::MyDTI rShrinkBlowValue::DTI("rShrinkBlowValue", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rShrinkBlowValue::MyDTI::newInstance() const {
    return new (16u) rShrinkBlowValue;
}

template cAdjLimitParam* rTbl2<cAdjLimitParam>::getData(unsigned int);

template cBlowSaveEmLvParam* rTbl2<cBlowSaveEmLvParam>::getData(unsigned int);

template cCalcDamageAtdmAdj* rTbl2<cCalcDamageAtdmAdj>::getData(unsigned int);

template cCalcDamageAtdmAdjRate* rTbl2<cCalcDamageAtdmAdjRate>::getData(unsigned int);

template cCalcDamageLvAdj* rTbl2<cCalcDamageLvAdj>::getData(unsigned int);

template cDamageSaveEmLvParam* rTbl2<cDamageSaveEmLvParam>::getData(unsigned int);

template cDamageSpecialAdj* rTbl2<cDamageSpecialAdj>::getData(unsigned int);

template cDmJobAdjParam* rTbl2<cDmJobAdjParam>::getData(unsigned int);

template cDmJobPawnAdjParam* rTbl2<cDmJobPawnAdjParam>::getData(unsigned int);

template cDmLvPawnAdjParam* rTbl2<cDmLvPawnAdjParam>::getData(unsigned int);

template cErosionShakeConvert* rTbl2<cErosionShakeConvert>::getData(unsigned int);

template cShrinkBlowValue* rTbl2<cShrinkBlowValue>::getData(unsigned int);

template bool rTbl2<cAdjLimitParam>::load(MtStream&);

template bool rTbl2<cBlowSaveEmLvParam>::load(MtStream&);

template bool rTbl2<cCalcDamageAtdmAdj>::load(MtStream&);

template bool rTbl2<cCalcDamageAtdmAdjRate>::load(MtStream&);

template bool rTbl2<cCalcDamageLvAdj>::load(MtStream&);

template bool rTbl2<cDamageSaveEmLvParam>::load(MtStream&);

template bool rTbl2<cDamageSpecialAdj>::load(MtStream&);

template bool rTbl2<cDmJobAdjParam>::load(MtStream&);

template bool rTbl2<cDmJobPawnAdjParam>::load(MtStream&);

template bool rTbl2<cDmLvPawnAdjParam>::load(MtStream&);

template bool rTbl2<cErosionShakeConvert>::load(MtStream&);

template bool rTbl2<cShrinkBlowValue>::load(MtStream&);

template bool rTbl2<cAdjLimitParam>::loadCore(MtDataReader&);

template bool rTbl2<cBlowSaveEmLvParam>::loadCore(MtDataReader&);

template bool rTbl2<cCalcDamageAtdmAdj>::loadCore(MtDataReader&);

template bool rTbl2<cCalcDamageAtdmAdjRate>::loadCore(MtDataReader&);

template bool rTbl2<cCalcDamageLvAdj>::loadCore(MtDataReader&);

template bool rTbl2<cDamageSaveEmLvParam>::loadCore(MtDataReader&);

template bool rTbl2<cDamageSpecialAdj>::loadCore(MtDataReader&);

template bool rTbl2<cDmJobAdjParam>::loadCore(MtDataReader&);

template bool rTbl2<cDmJobPawnAdjParam>::loadCore(MtDataReader&);

template bool rTbl2<cDmLvPawnAdjParam>::loadCore(MtDataReader&);

template bool rTbl2<cErosionShakeConvert>::loadCore(MtDataReader&);

template bool rTbl2<cShrinkBlowValue>::loadCore(MtDataReader&);

template const cAdjLimitParam* rTbl2<cAdjLimitParam>::getData(unsigned int) const;

template const cBlowSaveEmLvParam* rTbl2<cBlowSaveEmLvParam>::getData(unsigned int) const;

template const cCalcDamageAtdmAdj* rTbl2<cCalcDamageAtdmAdj>::getData(unsigned int) const;

template const cCalcDamageAtdmAdjRate* rTbl2<cCalcDamageAtdmAdjRate>::getData(unsigned int) const;

template const cCalcDamageLvAdj* rTbl2<cCalcDamageLvAdj>::getData(unsigned int) const;

template const cDamageSaveEmLvParam* rTbl2<cDamageSaveEmLvParam>::getData(unsigned int) const;

template const cDamageSpecialAdj* rTbl2<cDamageSpecialAdj>::getData(unsigned int) const;

template const cDmJobAdjParam* rTbl2<cDmJobAdjParam>::getData(unsigned int) const;

template const cDmJobPawnAdjParam* rTbl2<cDmJobPawnAdjParam>::getData(unsigned int) const;

template const cDmLvPawnAdjParam* rTbl2<cDmLvPawnAdjParam>::getData(unsigned int) const;

template const cErosionShakeConvert* rTbl2<cErosionShakeConvert>::getData(unsigned int) const;

template const cShrinkBlowValue* rTbl2<cShrinkBlowValue>::getData(unsigned int) const;

template unsigned int rTbl2<cAdjLimitParam>::getDataNum() const;

template unsigned int rTbl2<cBlowSaveEmLvParam>::getDataNum() const;

template unsigned int rTbl2<cCalcDamageAtdmAdj>::getDataNum() const;

template unsigned int rTbl2<cCalcDamageAtdmAdjRate>::getDataNum() const;

template unsigned int rTbl2<cCalcDamageLvAdj>::getDataNum() const;

template unsigned int rTbl2<cDamageSaveEmLvParam>::getDataNum() const;

template unsigned int rTbl2<cDamageSpecialAdj>::getDataNum() const;

template unsigned int rTbl2<cDmJobAdjParam>::getDataNum() const;

template unsigned int rTbl2<cDmJobPawnAdjParam>::getDataNum() const;

template unsigned int rTbl2<cDmLvPawnAdjParam>::getDataNum() const;

template unsigned int rTbl2<cErosionShakeConvert>::getDataNum() const;

template unsigned int rTbl2<cShrinkBlowValue>::getDataNum() const;

template rTbl2<cAdjLimitParam>::~rTbl2();

template rTbl2<cBlowSaveEmLvParam>::~rTbl2();

template rTbl2<cCalcDamageAtdmAdj>::~rTbl2();

template rTbl2<cCalcDamageAtdmAdjRate>::~rTbl2();

template rTbl2<cCalcDamageLvAdj>::~rTbl2();

template rTbl2<cDamageSaveEmLvParam>::~rTbl2();

template rTbl2<cDamageSpecialAdj>::~rTbl2();

template rTbl2<cDmJobAdjParam>::~rTbl2();

template rTbl2<cDmJobPawnAdjParam>::~rTbl2();

template rTbl2<cDmLvPawnAdjParam>::~rTbl2();

template rTbl2<cErosionShakeConvert>::~rTbl2();

template rTbl2<cShrinkBlowValue>::~rTbl2();

