// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cBlowShrinkDmInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "nObjCollision.h"
#include "rAttackParam.h"
#include "rCalcDamage.h"
#include "sObjCollision.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cBlowShrinkDmInfo::getDTI() const {
    return cBlowShrinkDmInfo::DTI;
}

void* cBlowShrinkDmInfo::operator new(size_t sz, u32 align) {
    return cBlowShrinkDmInfo::getAllocator()->memAlloc(sz, align, cBlowShrinkDmInfo::DTI.getID());
}

f32 cBlowShrinkDmInfo::calcBaseShrinkAttack(const cAttackParam* pAttackParam) {
    if (pAttackParam != nullptr) {
        if ((pAttackParam->mShrinkRate * (mPower + mShrinkWep)) > 1.1920929e-7f) {
            return mPawnAdjShrinkBlowAt + (pAttackParam->mShrinkRate * (mPower + mShrinkWep));
        } else {
            return pAttackParam->mShrinkRate * (mPower + mShrinkWep);
        }
    } else {
        return 0.0f;
    }
}

f32 cBlowShrinkDmInfo::calcBaseBlowAttack(const cAttackParam* pAttackParam) {
    if (pAttackParam != nullptr) {
        if ((pAttackParam->mBlowRate * (mPower + mBlowWep)) > 1.1920929e-7f) {
            return mPawnAdjShrinkBlowAt + (pAttackParam->mBlowRate * (mPower + mBlowWep));
        } else {
            return pAttackParam->mBlowRate * (mPower + mBlowWep);
        }
    } else {
        return 0.0f;
    }
}

f32 cBlowShrinkDmInfo::calcSaveShrinkBlowAttack(const cDmJobAdjParam* pJobAdjParam, uDDOModel* pDefender) {
    if (pJobAdjParam != nullptr) {
        if (pDefender != nullptr) {
            if ((pDefender->mUnitId & 2u) != 0) {
                sObjCollision* t1 = sObjCollision::getInstance();
                u32 t2 = pDefender->getLv();
                const cBlowSaveEmLvParam* pSaveLvParam = t1->getBlowSaveEmLvParam(t2);
                if (pSaveLvParam != nullptr) {
                    sObjCollision* t4 = sObjCollision::getInstance();
                    f32 baseAdj = t4->getSystemParam(sObjCollision::BLOW_SAVE_BASE_ADJ);
                    const f32 t5 = pJobAdjParam->mShrinkBlowSaveAdj;
                    u32 t6 = pDefender->getLv();
                    return (t5 * baseAdj) * (pSaveLvParam->mSaveRate * static_cast<float>((t6 - pSaveLvParam->mKeyLv) + 1u));
                } else {
                    return 0.0f;
                }
            } else {
                return 0.0f;
            }
        } else {
            return 0.0f;
        }
    } else {
        return 0.0f;
    }
}

void cBlowShrinkDmInfo::clear() {
        this->mPower = 10.0f;
        this->mBlowWep = 1.0f;
        this->mShrinkWep = 1.0f;
        this->mDownBase = 0.0f;
        this->mDownWep = 0.0f;
        this->mShakeBase = 0.0f;
        this->mWeight = 0.0f;
        this->mBlowCutRate = 1.0f;
        this->mShrinkCutRate = 1.0f;
        this->mDownCutRate = 1.0f;
        this->mShakeCutRate = 1.0f;
        this->mRageShrinkRate = 0.0f;
        this->mBlowValue = 0.0f;
        this->mShrinkValue = 0.0f;
        this->mDownValue = 0.0f;
        this->mShakeValue = 0.0f;
        this->mRageShrinkValue = 0.0f;
        this->mIsRageShrink_Shrink = true;
        this->mPawnAdjShrinkBlowAt = 0.0f;
        this->mPawnAdjFinalDamageShrink = 1.0f;
        this->mPawnAdjFinalDamageBlow = 1.0f;
        this->mpJobPawnAdjParam_AT = nullptr;
        this->mpDmLvPawnAdjParam_AT = nullptr;
        this->mpJobPawnAdjParam_DF = nullptr;
        this->mpDmLvPawnAdjParam_DF = nullptr;
        this->mBlowReason[0] = nObjCollision::BLOW_REASON_NONE;
        this->mBlowReason[1] = nObjCollision::BLOW_REASON_NONE;
        this->mBlowReason[2] = nObjCollision::BLOW_REASON_NONE;
        this->mBlowReason[3] = nObjCollision::BLOW_REASON_NONE;
        this->mBlowReason[4] = nObjCollision::BLOW_REASON_NONE;
        this->mBlowReason[5] = nObjCollision::BLOW_REASON_NONE;
        this->mBlowReason[6] = nObjCollision::BLOW_REASON_NONE;
        this->mForceShrinkType = nObjCollision::FORCE_REACTION_NONE;
        this->mForceBlowType = nObjCollision::FORCE_REACTION_NONE;
        this->mForceShakeType = nObjCollision::FORCE_REACTION_NONE;
        this->mForceDownType = nObjCollision::FORCE_REACTION_NONE;
        this->mShrinkAttackAdj[0] = 0.0f;
        this->mShrinkAttackAdj[1] = 0.0f;
        this->mShrinkAttackAdj[2] = 0.0f;
        this->mShrinkAttackAdj[3] = 0.0f;
        this->mShrinkDefenceAdj[0] = 0.0f;
        this->mShrinkDefenceAdj[1] = 0.0f;
        this->mShrinkDefenceAdj[2] = 0.0f;
        this->mShrinkDefenceAdj[3] = 0.0f;
        this->mBlowAttackAdj[0] = 0.0f;
        this->mBlowAttackAdj[1] = 0.0f;
        this->mBlowAttackAdj[2] = 0.0f;
        this->mBlowAttackAdj[3] = 0.0f;
        this->mBlowDefenceAdj[0] = 0.0f;
        this->mBlowDefenceAdj[1] = 0.0f;
        this->mBlowDefenceAdj[2] = 0.0f;
        this->mBlowDefenceAdj[3] = 0.0f;
        this->mDownAttackAdj[0] = 0.0f;
        this->mDownAttackAdj[1] = 0.0f;
        this->mDownAttackAdj[2] = 0.0f;
        this->mDownAttackAdj[3] = 0.0f;
        this->mDownDefenceAdj[0] = 0.0f;
        this->mDownDefenceAdj[1] = 0.0f;
        this->mDownDefenceAdj[2] = 0.0f;
        this->mDownDefenceAdj[3] = 0.0f;
        this->mShakeAttackAdj[0] = 0.0f;
        this->mShakeAttackAdj[1] = 0.0f;
        this->mShakeAttackAdj[2] = 0.0f;
        this->mShakeAttackAdj[3] = 0.0f;
        this->mShakeDefenceAdj[0] = 0.0f;
        this->mShakeDefenceAdj[1] = 0.0f;
        this->mShakeDefenceAdj[2] = 0.0f;
        this->mShakeDefenceAdj[3] = 0.0f;
}

inline cBlowShrinkDmInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cBlowShrinkDmInfo::MyDTI cBlowShrinkDmInfo::DTI("cBlowShrinkDmInfo", &::MtObject::DTI, 304ul, 0u, 0u);

__attribute__((weak)) MtObject* cBlowShrinkDmInfo::MyDTI::newInstance() const {
    DDON_STUB("cBlowShrinkDmInfo::MyDTI::newInstance")
    return nullptr;
}

