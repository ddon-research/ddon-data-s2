// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cOcdBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextPlayerInfo.h"
#include "cEfcHandle.h"
#include "cHitInfoAfter.h"
#include "cOcdCache.h"
#include "cOcdCustomReqInfo.h"
#include "cOcdDamageInfo.h"
#include "cOcdInfo.h"
#include "cOcdParamRes.h"
#include "cOcdPriority.h"
#include "../../XFramework/cUnit.h"
#include "cpEmParamCtrl.h"
#include "cpOcdCtrl.h"
#include "../../generated/shared/nAbility.h"
#include "nDDOUtility.h"
#include "nObjCollision.h"
#include "nObjCondition.h"
#include "nOcdMsg.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sMain.h"
#include "sObjCollision.h"
#include "sObjCondition.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "sWorkRate.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cOcdBase::getDTI() const {
    return cOcdBase::DTI;
}

cOcdBase::cOcdBase() {
    DDON_STUB("cOcdBase::cOcdBase")
    /* stub */
}

cOcdBase::~cOcdBase() {
}

void cOcdBase::createProperty(MtPropertyList& s) {
    mStatusParam.cOcdStatusParam::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mImmuneMode", reinterpret_cast<s32*>(&mImmuneMode), 0u, 0u);
    mImmuneParam.cOcdImmuneParam::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "タイマー更新速度", &mActiveTimerRate, 0u, 0u);
}

void cOcdBase::setup() {
    const cOcdPriorityParam* pData = sObjCondition::getInstance()->getPriorityData(mOcdUID);
    if (pData != nullptr) {
        mStatusParam.mIsMultiApply = pData->isMultiApply();
        mStatusParam.mIsMultiNumLimit = pData->isMultiNumLimit();
        u32 t0 = pData->getMultiApplyNum();
        mStatusParam.mMultiApplyNum = t0;
        mStatusParam.mMultiApplyNumMax = mStatusParam.mMultiApplyNum;
        mImmuneMode = nObjCondition::OCD_IMMUNE_MODE_NORMAL;
        if ((mpModel->mUnitId & 16u) != 0) {
            mImmuneMode = nObjCondition::OCD_IMMUNE_MODE_BOOST;
            mImmuneParam.mImmuneLv = 0;
            mImmuneParam.mImmuneLvMax = 7;
        } else {
            mImmuneMode = nObjCondition::OCD_IMMUNE_MODE_NORMAL;
        }
    } else {
        mImmuneMode = nObjCondition::OCD_IMMUNE_MODE_NORMAL;
        if ((mpModel->mUnitId & 16u) != 0) {
            mImmuneMode = nObjCondition::OCD_IMMUNE_MODE_BOOST;
            mImmuneParam.mImmuneLv = 0;
            mImmuneParam.mImmuneLvMax = 7;
        } else {
            mImmuneMode = nObjCondition::OCD_IMMUNE_MODE_NORMAL;
        }
    }
}

void cOcdBase::updatePtr() {
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

__attribute__((weak)) void cOcdBase::updateEfcHandle() {
    DDON_STUB("cOcdBase::updateEfcHandle")
    /* stub */
}

__attribute__((weak)) void cOcdBase::init(bool initFlag) {
    DDON_STUB("cOcdBase::init")
    /* stub */
}

void cOcdBase::move() {
    updateActiveTimer();
    if (mpModel != nullptr) {
        if (mpModel->isDamageAttrActive(0x80000u)) {
            if (mpOcdCtrl != nullptr) {
                mpOcdCtrl->reqOcdCure(mOcdUID);
            }
        }
        if (mpModel != nullptr) {
            if ((mRequreOST & mpModel->mObjStatus) == 0) {
                if ((mRequreOST & mpModel->mObjStatusOld) != 0) {
                    if (mpOcdCtrl != nullptr) {
                        mpOcdCtrl->reqOcdCure(mOcdUID);
                    }
                }
            } else {
                if (mpOcdCtrl != nullptr) {
                    mpOcdCtrl->reqOcdCure(mOcdUID);
                }
            }
        }
    }
    if (mpOcdCtrl == nullptr) {
        return;
    }
    if (!mpOcdCtrl->isOcdSystemFlagActive(nObjCondition::SYSTEM_FLAG_EFF_OFF)) {
        registOcdShader(mOcdUID);
    }
}

__attribute__((weak)) void cOcdBase::final() {
    DDON_STUB("cOcdBase::final")
    /* stub */
}

__attribute__((weak)) void cOcdBase::multiInit(bool initFlag) {
    DDON_STUB("cOcdBase::multiInit")
    /* stub */
}

__attribute__((weak)) void cOcdBase::resetParam() {
    DDON_STUB("cOcdBase::resetParam")
    /* stub */
}

void cOcdBase::update() {
    checkEnduranceCure();
    mOcdActiveCache.update(sWorkRate::getInstance()->calc(3u));
}

bool cOcdBase::isEnableInit() const {
    if (mStatusParam.isEffective()) {
        if (mpModel != nullptr) {
            if (((mNonInitOST & mpModel->mObjStatus) == 0) && ((mNonInitOST & mpModel->mObjStatusOld) == 0)) {
                return !mOcdActiveCache.mIsActive;
            }
            return false;
        } else {
            return !mOcdActiveCache.mIsActive;
        }
    } else {
        return false;
    }
}

bool cOcdBase::isEnableMove() const {
    return true;
}

bool cOcdBase::isEnableFinal() const {
    return true;
}

bool cOcdBase::isEnableMoveAfter() const {
    return true;
}

bool cOcdBase::isEnableMultiInit() const {
    if (mStatusParam.isMultiApply()) {
        return mStatusParam.mMultiApplyNum != 0;
    } else {
        return false;
    }
}

bool cOcdBase::isEnableEndAction() const {
    return mIsEndReaction;
}

bool cOcdBase::isEffective() const {
    return mStatusParam.mIsEffective;
}

__attribute__((weak)) void cOcdBase::setStatusParamRes(const cOcdStatusParamRes& data) {
    DDON_STUB("cOcdBase::setStatusParamRes")
    /* stub */
}

void cOcdBase::setImuuneParamRes(const cOcdImmuneParamRes& data) {
    mImmuneParam.mImmuneRate = data.mImmuneRate;
    mImmuneParam.mImmuneLv = 0;
    mImmuneParam.mImmuneLvMax = data.mImmuneNum;
}

__attribute__((weak)) void cOcdBase::applyImmuneNormal(u32 immuneLv) {
    DDON_STUB("cOcdBase::applyImmuneNormal")
    /* stub */
}

void cOcdBase::applyImmuneBoost(u32 immuneLv) {
    if (immuneLv == 9) {
        return;
    }
    mImmuneParam.mImmuneLv = immuneLv;
}

__attribute__((weak)) void cOcdBase::callbackDamage(cHitInfoAfter* pHitInfo) {
    DDON_STUB("cOcdBase::callbackDamage")
    /* stub */
}

__attribute__((weak)) void cOcdBase::addOcdDamage(f32 damage, nObjCondition::OCD_REASON reason, f32 cacheTime, bool isAddAccumulation, nObjCollision::UNIT_INV_THROUGH_TYPE invThroughType) {
    DDON_STUB("cOcdBase::addOcdDamage")
    /* stub */
}

__attribute__((weak)) void cOcdBase::callbackHitShlCondition_Catch(const cShlConditionInfo* pShlInfo) {
}

__attribute__((weak)) void cOcdBase::resetActiveTimer() {
    DDON_STUB("cOcdBase::resetActiveTimer")
    /* stub */
}

__attribute__((weak)) void cOcdBase::checkCheatOcd() {
    DDON_STUB("cOcdBase::checkCheatOcd")
    /* stub */
}

bool cOcdBase::isActive() const {
    if (mpOwner != nullptr) {
        return mpOwner->isActive();
    } else {
        return false;
    }
}

void cOcdBase::requestCure(u32 OcdUID) {
    if (mpOcdCtrl == nullptr) {
        return;
    }
    mpOcdCtrl->reqOcdCure(OcdUID);
}

void cOcdBase::applyCustomRequest(const cOcdCustomReqInfo& info) {
    if (info.mActiveTime > 1.1920929e-7f) {
        mStatusParam.mActiveTime = info.mActiveTime;
        mStatusParam.mActiveTimeCheatCheck = mStatusParam.mActiveTime;
    }
    if (mImmuneMode != nObjCondition::OCD_IMMUNE_MODE_BOOST) {
        return;
    }
    if (info.mImmuneBoostLv == nObjCondition::IMMUNE_BOOST_LV_INVALID) {
        return;
    }
    mImmuneParam.mImmuneLv = static_cast<u32>(info.mImmuneBoostLv);
}

__attribute__((weak)) void cOcdBase::applyCustomRequestMulti(const cOcdCustomReqInfo& info) {
    DDON_STUB("cOcdBase::applyCustomRequestMulti")
    /* stub */
}

bool cOcdBase::isCustomRequest() const {
    if (mpOwner != nullptr) {
        return mpOwner->isCustomRequest();
    } else {
        return false;
    }
}

__attribute__((weak)) void cOcdBase::setActiveTimerRateByAbility(nAbility::ABILITY_ID AbilityId) {
    DDON_STUB("cOcdBase::setActiveTimerRateByAbility")
    /* stub */
}

__attribute__((weak)) void cOcdBase::checkEnduranceCure() {
    DDON_STUB("cOcdBase::checkEnduranceCure")
    /* stub */
}

__attribute__((weak)) void cOcdBase::updateActiveTimer() {
    DDON_STUB("cOcdBase::updateActiveTimer")
    /* stub */
}

__attribute__((weak)) void cOcdBase::callOcdEffectInit() {
    DDON_STUB("cOcdBase::callOcdEffectInit")
    /* stub */
}

void cOcdBase::callOcdEffectFinal() {
    if (!mFlgCallInitFinishlEffect) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(&mEfcHandle, 1u);
    if (!mpOcdCtrl->isOcdSystemFlagActive(nObjCondition::SYSTEM_FLAG_EFF_OFF)) {
        static_cast<sEffectExt*>(sEffect::getInstance())->setOcdEffect(mpModel, -1, mOcdUID, true, static_cast<MtTypedArray<cEfcHandle>*>(nullptr));
    }
}

__attribute__((weak)) void cOcdBase::callOcdDamageOutLineSe(u32 OcdUID) {
    DDON_STUB("cOcdBase::callOcdDamageOutLineSe")
    /* stub */
}

__attribute__((weak)) void cOcdBase::registOcdShader(u32 OcdUID) {
    if (mpOcdCtrl == nullptr) {
        return;
    }
    switch (OcdUID - 4097u) {
        case 0:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_GENERAL, 100u, -1);
            break;
        }
        case 1:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_GENERAL, 100u, -1);
            break;
        }
        case 4:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_WET_OIL, 200u, -1);
            break;
        }
        case 5:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_WET_OIL, 200u, -1);
            break;
        }
        case 6:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_GENERAL, 100u, -1);
            break;
        }
        case 7:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_GENERAL, 100u, -1);
            break;
        }
        case 8:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_GENERAL, 100u, -1);
            break;
        }
        case 9:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_STONE, 400u, -1);
            break;
        }
        case 10:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_GOLD, 500u, -1);
            break;
        }
        case 11:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_FIRE, 300u, -1);
            break;
        }
        case 12:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_FREEZE, 300u, -1);
            break;
        }
        case 26:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_EROSION, 600u, 4123);
            break;
        }
        case 27:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_EROSION, 600u, 4124);
            break;
        }
        case 28:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_EROSION, 600u, 4125);
            break;
        }
        case 29:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_EROSION, 600u, 4125);
            break;
        }
        case 30:
        {
            mpOcdCtrl->registOcdShader(nDDOShader::SHADER_MODE_GENERAL, 100u, -1);
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void cOcdBase::requestOcdSeInit(u32 OcdUID) {
    DDON_STUB("cOcdBase::requestOcdSeInit")
    /* stub */
}

__attribute__((weak)) s32 cOcdBase::getOcdSeOffset() const {
    DDON_STUB("cOcdBase::getOcdSeOffset")
    return {};
}

__attribute__((weak)) s32 cOcdBase::getCenterJointNo() const {
    DDON_STUB("cOcdBase::getCenterJointNo")
    return {};
}

void cOcdBase::addOcdBadNonDamageList(nObjCondition::OCD_BAD_TYPE type) {
    if (static_cast<unsigned int>(type - 4097) <= 30) {
        mOcdBadNonDamageList.elems[static_cast<unsigned int>(type - 4097)] = true;
    }
}

__attribute__((weak)) MtObject* cOcdBase::MyDTI::newInstance() const {
    DDON_STUB("cOcdBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cOcdImmuneParam::getDTI() const {
    return cOcdImmuneParam::DTI;
}

__attribute__((weak)) void cOcdImmuneParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mImmuneRate", &mImmuneRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mImmuneLv", &mImmuneLv, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mImmuneLvMax", &mImmuneLvMax, 0u, 0u);
}

inline cOcdImmuneParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOcdImmuneParam::MyDTI cOcdImmuneParam::DTI("cOcdImmuneParam", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cOcdImmuneParam::MyDTI::newInstance() const {
    return new (16u) cOcdImmuneParam;
}

const MtDTI& cOcdStatusParam::getDTI() const {
    return cOcdStatusParam::DTI;
}

void cOcdStatusParam::setParamFromRes(const cOcdStatusParamRes* pStatusRes) {
    if (pStatusRes == nullptr) {
        return;
    }
    mIsEffective = pStatusRes->isEffective();
    f32 t0 = pStatusRes->getEndurance();
    mEndurance = t0;
    mEnduranceCheatCheck = mEndurance;
    f32 t1 = pStatusRes->getEndurance();
    mEnduranceMax = t1;
    mEnduranceMaxCheatCheck = mEnduranceMax;
    mIsTimeRecover = pStatusRes->isTimeRecover();
    f32 t2 = pStatusRes->getActiveTime();
    f32 t3 = sMain::getInstance()->getFps();
    mActiveTime = t3 * t2;
    mActiveTimeCheatCheck = mActiveTime;
    mActiveTimeMax = mActiveTimeCheatCheck;
    mActiveTimeMaxCheatCheck = mActiveTimeMax;
    const f32 t4 = pStatusRes->mCureWaitTime;
    mCureWaitTime = t3 * t4;
    mCureWaitTimeMax = mCureWaitTime;
    f32 t5 = pStatusRes->getCureValue();
    mCureValue = t5;
    mCureValueCheatCheck = mCureValue;
    f32 t6 = pStatusRes->getFreeParam0();
    mFreeParam0 = t6;
    mFreeParam0CheatCheck = mFreeParam0;
    f32 t7 = pStatusRes->getFreeParam1();
    mFreeParam1 = t7;
    mFreeParam1CheatCheck = mFreeParam1;
}

void cOcdStatusParam::resetActiveTime() {
    mActiveTime = getActiveTimeMaxPrivate();
    mActiveTimeCheatCheck = mActiveTime;
}

__attribute__((weak)) void cOcdStatusParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsEffective", &mIsEffective, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mEndurance", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::getEndurance), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::setEndurance), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mEnduranceMax", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::getEnduranceMax), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::setEnduranceMax), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAccumulationValue", &mAccumulationValue, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsTimeRecover", &mIsTimeRecover, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mActiveTime", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::getActiveTime), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::setActiveTime), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mActiveTimeMax", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::getActiveTimeMax), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::setActiveTimeMax), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mCureWaitTime", &mCureWaitTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCureWaitTimeMax", &mCureWaitTimeMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mCureValue", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::getCureValue), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::setCureValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mFreeParam0", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::getFreeParam0), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::setFreeParam0), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mFreeParam1", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::getFreeParam1), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParam::setFreeParam1), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mIsMultiApply", &mIsMultiApply, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsMultiNumLimit", &mIsMultiNumLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMultiApplyNum", &mMultiApplyNum, 0u, 0u);
}

f32 cOcdStatusParam::getEndurance() const {
    return mEndurance;
}

f32 cOcdStatusParam::getEnduranceMax() const {
    return mEnduranceMax;
}

f32 cOcdStatusParam::getActiveTime() const {
    return mActiveTime;
}

f32 cOcdStatusParam::getActiveTimeMax() const {
    return mActiveTimeMax;
}

f32 cOcdStatusParam::getCureValue() const {
    return mCureValue;
}

f32 cOcdStatusParam::getFreeParam0() const {
    return mFreeParam0;
}

f32 cOcdStatusParam::getFreeParam1() const {
    return mFreeParam1;
}

void cOcdStatusParam::setEndurance(f32 endurance) {
    mEndurance = endurance;
    mEnduranceCheatCheck = endurance;
}

void cOcdStatusParam::setEnduranceMax(f32 EnduranceMax) {
    mEnduranceMax = EnduranceMax;
    mEnduranceMaxCheatCheck = EnduranceMax;
}

void cOcdStatusParam::setActiveTime(f32 ActiveTime) {
    mActiveTime = ActiveTime;
    mActiveTimeCheatCheck = ActiveTime;
}

void cOcdStatusParam::setActiveTimeMax(f32 ActiveTimeMax) {
    mActiveTimeMax = ActiveTimeMax;
    mActiveTimeMaxCheatCheck = ActiveTimeMax;
}

void cOcdStatusParam::setCureValue(f32 CureValue) {
    mCureValue = CureValue;
    mCureValueCheatCheck = CureValue;
}

void cOcdStatusParam::setFreeParam0(f32 FreeParam0) {
    mFreeParam0 = FreeParam0;
    mFreeParam0CheatCheck = FreeParam0;
}

void cOcdStatusParam::setFreeParam1(f32 FreeParam1) {
    mFreeParam1 = FreeParam1;
    mFreeParam1CheatCheck = FreeParam1;
}

inline cOcdStatusParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOcdStatusParam::MyDTI cOcdStatusParam::DTI("cOcdStatusParam", &::MtObject::DTI, 96ul, 0u, 0u);

MtObject* cOcdStatusParam::MyDTI::newInstance() const {
    return new (16u) cOcdStatusParam;
}

