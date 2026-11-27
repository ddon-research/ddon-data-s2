// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cHumanAction.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtRandom.h"
#include "cActList.h"
#include "cAction.h"
#include "cComponentManager.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cHumanActId.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpActionSelect.h"
#include "cpComponent.h"
#include "cpEffectProvider.h"
#include "cpEffectStatusManager.h"
#include "cpEquip.h"
#include "cpInput.h"
#include "cpKeyCommand.h"
#include "cpOcdCtrl.h"
#include "cpRotateCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../generated/shared/nHuman.h"
#include "nHumanMsg.h"
#include "nShlBase.h"
#include "../../XFramework/rMotionList.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sEffectExt.h"
#include "sInputManager.h"
#include "sLockOnManager.h"
#include "../../XFramework/sMain.h"
#include "sNpcManager.h"
#include "sShlManager.h"
#include "sWorldOffset.h"
#include "uCameraBase.h"
#include "uControl.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cHumanActBase::getDTI() const {
    return cHumanActBase::DTI;
}

__attribute__((weak)) void cHumanActBase::init() {
    DDON_STUB("cHumanActBase::init")
    /* stub */
}

void cHumanActBase::move() {
    mpHuman->mIsOmTiming = false;
    this->cAction::move();
    if (0.0f >= mpHuman->mEmotionTimer) {
        if (mpHuman->isEventBusy()) {
            mpHuman->mIsCanSetEmotion = false;
        } else {
            u32 actno = mpHuman->getActMgrPtr()->getActionNo();
            if ((actno - 3u) > 1u) {
                if (!mpHuman->isFootWork()) {
                    if (actno != 382) {
                        if ((actno - 242u) > 130u) {
                            mpHuman->mIsCanSetEmotion = false;
                        } else {
                            mpHuman->mIsCanSetEmotion = true;
                        }
                    } else {
                        mpHuman->mIsCanSetEmotion = true;
                    }
                } else {
                    mpHuman->mIsCanSetEmotion = true;
                }
            } else {
                mpHuman->mIsCanSetEmotion = true;
            }
        }
    } else {
        mpHuman->mIsCanSetEmotion = false;
    }
}

void cHumanActBase::final() {
    this->cAction::final();
    uHuman* t0 = mpHuman;
    if (t0 == nullptr) {
        return;
    }
    f32 t1 = t0->getComAdjustParam(1u);
    t0->setDefaultRotateSpeed(0.017453294f * t1);
    mpHuman->mIsBeforeAttackHit = false;
    mpHuman->mIsBeforeGuarded = false;
    mpHuman->mIsRecevedDamage = false;
    mpHuman->mCanNextCustmSkillLevel = false;
    if (mpHuman == nullptr) {
        return;
    }
    mpHuman->mActionWorkFlag = false;
}

__attribute__((weak)) bool cHumanActBase::updateFinalQuatAndVelocity(f32 velocityRate, u32 type) {
    DDON_STUB("cHumanActBase::updateFinalQuatAndVelocity")
    return {};
}

__attribute__((weak)) void cHumanActBase::changeJobCommonMotion(u32& motNo) {
    DDON_STUB("cHumanActBase::changeJobCommonMotion")
    /* stub */
}

void cHumanActBase::getCustomSkillIDAndLevelFromActNo(u32 ActionNo) {
    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpHuman) + 13376)) != 0) {
        nHuman::CUSTOM_SKILL_ENUM t0 = cHumanActId::getCustomSkillId(ActionNo, static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpHuman) + 13376)) + 40)));
        mCustomSkillID = t0;
        unsigned long t1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpHuman) + 13376);
        if (t1 != 0) {
            if (static_cast<int>(mCustomSkillID) <= 20) {
                if (static_cast<unsigned char>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)) + 255) > 9) {
                    mSkillLv = nHuman::HM_SKILL_LV_NONE;
                } else {
                    u32 t2 = nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)));
                    unsigned int t3 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((t1 + (static_cast<unsigned long>(t2) * 80)) + (static_cast<unsigned long>(nHuman::getCustomSkillIdArrayIndex(t0)) * 4)) + 2376);
                    mSkillLv = static_cast<nHuman::HM_SKILL_LV>(t3);
                    if (t3 != 0) {
                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpHuman) + 13376)) != 0) {
                            nHuman::HM_SKILL_LV maxLv = cHumanActId::getCustomSkillLvMax(mCustomSkillID, static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpHuman) + 13376)) + 40)));
                            if (static_cast<int>(maxLv) < static_cast<int>(mSkillLv)) {
                                mSkillLv = maxLv;
                            }
                            if (static_cast<int>(mSkillLv) > 5) {
                                mpHuman->mCanNextCustmSkillLevel = true;
                            }
                        } else {
                            nHuman::HM_SKILL_LV maxLv = cHumanActId::getCustomSkillLvMax(mCustomSkillID, nHuman::JOB_ID_NONE);
                            if (static_cast<int>(maxLv) < static_cast<int>(mSkillLv)) {
                                mSkillLv = maxLv;
                            }
                            if (static_cast<int>(mSkillLv) > 5) {
                                mpHuman->mCanNextCustmSkillLevel = true;
                            }
                        }
                    }
                }
            } else {
                mSkillLv = nHuman::HM_SKILL_LV_NONE;
            }
        } else {
            mSkillLv = nHuman::HM_SKILL_LV_NONE;
        }
    } else {
        nHuman::CUSTOM_SKILL_ENUM t0 = cHumanActId::getCustomSkillId(ActionNo, nHuman::JOB_ID_NONE);
        mCustomSkillID = t0;
        unsigned long t1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpHuman) + 13376);
        if (t1 != 0) {
            if (static_cast<int>(mCustomSkillID) <= 20) {
                if (static_cast<unsigned char>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)) + 255) > 9) {
                    mSkillLv = nHuman::HM_SKILL_LV_NONE;
                } else {
                    u32 t2 = nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)));
                    unsigned int t3 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((t1 + (static_cast<unsigned long>(t2) * 80)) + (static_cast<unsigned long>(nHuman::getCustomSkillIdArrayIndex(t0)) * 4)) + 2376);
                    mSkillLv = static_cast<nHuman::HM_SKILL_LV>(t3);
                    if (t3 != 0) {
                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpHuman) + 13376)) != 0) {
                            nHuman::HM_SKILL_LV maxLv = cHumanActId::getCustomSkillLvMax(mCustomSkillID, static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpHuman) + 13376)) + 40)));
                            if (static_cast<int>(maxLv) < static_cast<int>(mSkillLv)) {
                                mSkillLv = maxLv;
                            }
                            if (static_cast<int>(mSkillLv) > 5) {
                                mpHuman->mCanNextCustmSkillLevel = true;
                            }
                        } else {
                            nHuman::HM_SKILL_LV maxLv = cHumanActId::getCustomSkillLvMax(mCustomSkillID, nHuman::JOB_ID_NONE);
                            if (static_cast<int>(maxLv) < static_cast<int>(mSkillLv)) {
                                mSkillLv = maxLv;
                            }
                            if (static_cast<int>(mSkillLv) > 5) {
                                mpHuman->mCanNextCustmSkillLevel = true;
                            }
                        }
                    }
                }
            } else {
                mSkillLv = nHuman::HM_SKILL_LV_NONE;
            }
        } else {
            mSkillLv = nHuman::HM_SKILL_LV_NONE;
        }
    }
}

__attribute__((weak)) void cHumanActBase::getCustomSkillIDAndLevelFromActNo_PreInit(u32 ActionNo) {
    DDON_STUB("cHumanActBase::getCustomSkillIDAndLevelFromActNo_PreInit")
    /* stub */
}

bool cHumanActBase::isCustomSKillBuildUp() const {
    return mSkillLv > 5;
}

void cHumanActBase::actionWorkFlag_On() {
    if (mpHuman == nullptr) {
        return;
    }
    mpHuman->mActionWorkFlag = true;
}

void cHumanActBase::setEndActNoSendOcdBadStatus() {
    if (mpHuman->getOcdCtrlPtr()->isOcdActive(4100u)) {
        mpModel->getActionRequestPtr()->mEndAction = 155;
    } else {
        if (mpHuman->getOcdCtrlPtr()->isOcdActive(4108u)) {
            mpModel->getActionRequestPtr()->mEndAction = 159;
        } else {
            if (!mpHuman->getOcdCtrlPtr()->isOcdActive(4106u)) {
                if (mpHuman->getOcdCtrlPtr()->isOcdActive(4107u)) {
                    mpModel->getActionRequestPtr()->mEndAction = 164;
                } else {
                    if (mpHuman->getOcdCtrlPtr()->isOcdActive(4126u)) {
                        mpModel->getActionRequestPtr()->mEndAction = 388;
                    }
                }
            } else {
                mpModel->getActionRequestPtr()->mEndAction = 164;
            }
        }
    }
    endActionNoSend();
}

inline cHumanActBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanActBase::MyDTI cHumanActBase::DTI("cHumanActBase", &::cAction::DTI, 72ul, 0u, 0u);

MtObject* cHumanActBase::MyDTI::newInstance() const {
    return new (16u) cHumanActBase;
}

const MtDTI& cHumanActEmotionBase::getDTI() const {
    return cHumanActEmotionBase::DTI;
}

void cHumanActEmotionBase::init() {
    this->cHumanActBase::init();
    mIntervalTime = 60.0f;
}

__attribute__((weak)) void cHumanActEmotionBase::move() {
    DDON_STUB("cHumanActEmotionBase::move")
    /* stub */
}

__attribute__((weak)) void cHumanActEmotionBase::final() {
    DDON_STUB("cHumanActEmotionBase::final")
    /* stub */
}

void cHumanActEmotionBase::setEmotionFingerMot() {
    u32 emoNo = mpParam->getMotNo0();
    const MtDTI& t0 = getDTI();
    MT_CTSTR v0_1 = cHumanActEmotionLoopEnd::DTI.mName;
    const MtDTI* v0_0 = &t0;
    const MtDTI* v1_0;
    MT_CTSTR v1_1;
    for (;;) {
        if (v0_1 == v0_0->mName) {
            cpActionManager* t2 = mpHuman->getActMgrPtr();
            const cActParam* t3 = t2->getActParam(t2->getActionNoOld());
            if (t3 != nullptr) {
                mpHuman->setDDOMotion(MOT_BLEND3, ((t3->getUParam0() + 1u) & 0xFFFFF1FFu) | 3072u, false, 0u, -1.0f, 0.0f, 1.0f);
            } else {
                mpHuman->setDDOMotion(MOT_BLEND3, (emoNo & 0xFFFFF1FFu) | 3072u, false, 0u, -1.0f, 0.0f, 1.0f);
            }
            return;
        } else {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                const MtDTI& t1 = getDTI();
                v1_1 = cHumanActEmotionLoopEndNoIK::DTI.mName;
                v1_0 = &t1;
                break;
            }
        }
    }
    for (;;) {
        if (v1_1 != v1_0->mName) {
            if (v1_0->mpParent == nullptr) {
                mpHuman->setDDOMotion(MOT_BLEND3, (emoNo & 0xFFFFF1FFu) | 3072u, false, 0u, -1.0f, 0.0f, 1.0f);
                return;
            } else {
                v1_0 = v1_0->mpParent;
            }
        } else {
            break;
        }
    }
    cpActionManager* t2 = mpHuman->getActMgrPtr();
    const cActParam* t3 = t2->getActParam(t2->getActionNoOld());
    if (t3 != nullptr) {
        mpHuman->setDDOMotion(MOT_BLEND3, ((t3->getUParam0() + 1u) & 0xFFFFF1FFu) | 3072u, false, 0u, -1.0f, 0.0f, 1.0f);
    } else {
        mpHuman->setDDOMotion(MOT_BLEND3, (emoNo & 0xFFFFF1FFu) | 3072u, false, 0u, -1.0f, 0.0f, 1.0f);
    }
}

inline cHumanActEmotionBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanActEmotionBase::MyDTI cHumanActEmotionBase::DTI("cHumanActEmotionBase", &::cHumanActBase::DTI, 72ul, 0u, 0u);

MtObject* cHumanActEmotionBase::MyDTI::newInstance() const {
    return new (16u) cHumanActEmotionBase;
}

const MtDTI& cHumanActEmotionLoop::getDTI() const {
    return cHumanActEmotionLoop::DTI;
}

void cHumanActEmotionLoop::init() {
    this->cHumanActBase::init();
    mIntervalTime = 60.0f;
    if (mpParam->getMotNo0() == 1610) {
        if (mpHuman->mSex != 0) {
            mpModel->setDDOMotion(MOT_BASE, 1613u, false, 0u, 10.0f, 0.0f, 1.0f);
        } else {
            mpModel->setDDOMotion(MOT_BASE, 1610u, false, 0u, 10.0f, 0.0f, 1.0f);
        }
    } else {
        mpModel->setDDOMotion(MOT_BASE, mpParam->getMotNo0(), false, 0u, 10.0f, 0.0f, 1.0f);
    }
    setEmotionFingerMot();
}

void cHumanActEmotionLoop::move() {
    this->cHumanActEmotionBase::move();
    mpModel->mObjStatus = 1;
    if (mpActMgr->getActionNo() != 287) {
        return;
    }
    if (mpHuman->mSex == 0) {
        return;
    }
    mpHuman->calcSetSitEmoHandPos();
}

__attribute__((weak)) void cHumanActEmotionLoop::final() {
    DDON_STUB("cHumanActEmotionLoop::final")
    /* stub */
}

inline cHumanActEmotionLoop::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanActEmotionLoop::MyDTI cHumanActEmotionLoop::DTI("cHumanActEmotionLoop", &::cHumanActEmotionBase::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cHumanActEmotionLoop::MyDTI::newInstance() const {
    DDON_STUB("cHumanActEmotionLoop::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cHumanActEmotionLoopEnd::getDTI() const {
    return cHumanActEmotionLoopEnd::DTI;
}

void cHumanActEmotionLoopEnd::init() {
    this->cHumanActBase::init();
    mIntervalTime = 60.0f;
    cpActionManager* t0 = mpHuman->getActMgrPtr();
    const cActParam* pAct = t0->getActParam(t0->getActionNoOld());
    if (pAct == nullptr) {
        return;
    }
    mpModel->setDDOMotion(MOT_BASE, pAct->getUParam0() + 1u, true, 0u, -1.0f, 0.0f, 1.0f);
    setEmotionFingerMot();
}

void cHumanActEmotionLoopEnd::move() {
    this->cHumanActEmotionBase::move();
    mpModel->mObjStatus = 1;
    if (!isActionMotionEnd(MOT_BASE)) {
        return;
    }
    endAction();
}

inline cHumanActEmotionLoopEnd::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanActEmotionLoopEnd::MyDTI cHumanActEmotionLoopEnd::DTI("cHumanActEmotionLoopEnd", &::cHumanActEmotionBase::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cHumanActEmotionLoopEnd::MyDTI::newInstance() const {
    DDON_STUB("cHumanActEmotionLoopEnd::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cHumanActEmotionLoopEndNoIK::getDTI() const {
    return cHumanActEmotionLoopEndNoIK::DTI;
}

void cHumanActEmotionLoopEndNoIK::init() {
    this->cHumanActBase::init();
    mIntervalTime = 60.0f;
    cpActionManager* t0 = mpHuman->getActMgrPtr();
    const cActParam* pAct = t0->getActParam(t0->getActionNoOld());
    if (pAct == nullptr) {
        return;
    }
    u32 motNo = pAct->getUParam0();
    if (motNo == 1610) {
        if (mpHuman->mSex != 0) {
            mpModel->setDDOMotion(MOT_BASE, 1614u, true, 0u, -1.0f, 0.0f, 1.0f);
        } else {
            mpModel->setDDOMotion(MOT_BASE, 1611u, true, 0u, -1.0f, 0.0f, 1.0f);
        }
    } else {
        mpModel->setDDOMotion(MOT_BASE, motNo + 1u, true, 0u, -1.0f, 0.0f, 1.0f);
    }
    setEmotionFingerMot();
}

void cHumanActEmotionLoopEndNoIK::move() {
    this->cHumanActEmotionBase::move();
    mpModel->mObjStatus = 1;
    if (mpHuman->getMotionNo(0u) == 1614) {
        if (mpHuman->mSex != 0) {
            mpHuman->calcSetSitEmoHandPos();
        }
    }
    if (!isActionMotionEnd(MOT_BASE)) {
        return;
    }
    endAction();
}

inline cHumanActEmotionLoopEndNoIK::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanActEmotionLoopEndNoIK::MyDTI cHumanActEmotionLoopEndNoIK::DTI("cHumanActEmotionLoopEndNoIK", &::cHumanActEmotionBase::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cHumanActEmotionLoopEndNoIK::MyDTI::newInstance() const {
    DDON_STUB("cHumanActEmotionLoopEndNoIK::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cHumanActSetNpcMotMyRoom::getDTI() const {
    return cHumanActSetNpcMotMyRoom::DTI;
}

u32 cHumanActSetNpcMotMyRoom::getEmotion() const {
    return mpModel->getActMgrPtr()->mActExParam.mUParam[3];
}

void cHumanActSetNpcMotMyRoom::setNextMotion() {
    mIsCancel = true;
}

__attribute__((weak)) void cHumanActSetNpcMotMyRoom::init() {
    DDON_STUB("cHumanActSetNpcMotMyRoom::init")
    /* stub */
}

__attribute__((weak)) void cHumanActSetNpcMotMyRoom::move() {
    DDON_STUB("cHumanActSetNpcMotMyRoom::move")
    /* stub */
}

void cHumanActSetNpcMotMyRoom::final() {
    this->cAction::final();
    uHuman* t0 = mpHuman;
    if (t0 == nullptr) {
        return;
    }
    f32 t1 = t0->getComAdjustParam(1u);
    t0->setDefaultRotateSpeed(0.017453294f * t1);
    mpHuman->mIsBeforeAttackHit = false;
    mpHuman->mIsBeforeGuarded = false;
    mpHuman->mIsRecevedDamage = false;
    mpHuman->mCanNextCustmSkillLevel = false;
    if (mpHuman == nullptr) {
        return;
    }
    mpHuman->mActionWorkFlag = false;
}

inline cHumanActSetNpcMotMyRoom::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanActSetNpcMotMyRoom::MyDTI cHumanActSetNpcMotMyRoom::DTI("cHumanActSetNpcMotMyRoom", &::cHumanActBase::DTI, 96ul, 0u, 0u);

MtObject* cHumanActSetNpcMotMyRoom::MyDTI::newInstance() const {
    return new (16u) cHumanActSetNpcMotMyRoom;
}

const MtDTI& cHumanActSetNpcMotion::getDTI() const {
    return cHumanActSetNpcMotion::DTI;
}

u32 cHumanActSetNpcMotion::getCategory() const {
    return mpModel->getActMgrPtr()->mActExParam.mUParam[0] - 1u;
}

u32 cHumanActSetNpcMotion::getMotionNo() const {
    return mpModel->getActMgrPtr()->mActExParam.mUParam[1];
}

__attribute__((weak)) void cHumanActSetNpcMotion::init() {
    DDON_STUB("cHumanActSetNpcMotion::init")
    /* stub */
}

__attribute__((weak)) void cHumanActSetNpcMotion::move() {
    DDON_STUB("cHumanActSetNpcMotion::move")
    /* stub */
}

void cHumanActSetNpcMotion::final() {
    this->cAction::final();
    uHuman* t0 = mpHuman;
    if (t0 == nullptr) {
        return;
    }
    f32 t1 = t0->getComAdjustParam(1u);
    t0->setDefaultRotateSpeed(0.017453294f * t1);
    mpHuman->mIsBeforeAttackHit = false;
    mpHuman->mIsBeforeGuarded = false;
    mpHuman->mIsRecevedDamage = false;
    mpHuman->mCanNextCustmSkillLevel = false;
    if (mpHuman == nullptr) {
        return;
    }
    mpHuman->mActionWorkFlag = false;
}

inline cHumanActSetNpcMotion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanActSetNpcMotion::MyDTI cHumanActSetNpcMotion::DTI("cHumanActSetNpcMotion", &::cHumanActBase::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cHumanActSetNpcMotion::MyDTI::newInstance() const {
    DDON_STUB("cHumanActSetNpcMotion::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) u32 nHumanActUtility::getSequenceCountNum(uHuman& human, u32 bit, MOT_TYPE blend, u32 seqPage) {
    DDON_STUB("nHumanActUtility::getSequenceCountNum")
    return {};
}

__attribute__((weak)) f32 nHumanActUtility::getAttackAngleY(uHuman& human, f32 range) {
    DDON_STUB("nHumanActUtility::getAttackAngleY")
    return {};
}

__attribute__((weak)) f32 nHumanActUtility::getAttackAngleY2(uHuman& human, f32 range) {
    DDON_STUB("nHumanActUtility::getAttackAngleY2")
    return {};
}

__attribute__((weak)) f32 nHumanActUtility::getAttackAngleY3(uHuman& human, f32 range) {
    DDON_STUB("nHumanActUtility::getAttackAngleY3")
    return {};
}

__attribute__((weak)) f32 nHumanActUtility::getAttackAngleY4(uHuman& human, f32 range) {
    DDON_STUB("nHumanActUtility::getAttackAngleY4")
    return {};
}

__attribute__((weak)) bool nHumanActUtility::reqSetSynchronizeEffect(uHuman* pHuman, u32 epvType, u64 syncFlag, u32 endType, s32 indexNo, s32 elementNo, s32 JointNo, const MtVector3& offset) {
    DDON_STUB("nHumanActUtility::reqSetSynchronizeEffect")
    return {};
}

__attribute__((weak)) bool nHumanActUtility::reqSetSynchronizeEffectToTarget(uHuman* pHuman, uDDOModel* pTarget, u32 epvType, u64 syncFlag, u32 endType, s32 indexNo, s32 elementNo, s32 JointNo, const MtVector3& offset) {
    DDON_STUB("nHumanActUtility::reqSetSynchronizeEffectToTarget")
    return {};
}

void nHumanActUtility::reqOnSyncFlag(uHuman* pHuman, u64 syncFlag) {
    if (pHuman == nullptr) {
        return;
    }
    if (pHuman->mpEffectStatusManager == nullptr) {
        return;
    }
    pHuman->mpEffectStatusManager->mSyncFlag = syncFlag | pHuman->mpEffectStatusManager->mSyncFlag;
}

__attribute__((weak)) void nHumanActUtility::setInvincibleTime(uHuman& human, f32 time, bool isApplyAbility) {
    DDON_STUB("nHumanActUtility::setInvincibleTime")
    /* stub */
}

__attribute__((weak)) cpInput::unBtnInfo nHumanActUtility::getSpecifiedCustomBtnInfo(nHuman::CUSTOM_SKILL_ENUM skillID, uHuman* pHuman) {
    DDON_STUB("nHumanActUtility::getSpecifiedCustomBtnInfo")
    __builtin_unreachable();
}

__attribute__((weak)) cpInput::unBtnInfo nHumanActUtility::getRendaCustomBtnInfo(nHuman::CUSTOM_SKILL_ENUM skillID, uHuman* pHuman) {
    DDON_STUB("nHumanActUtility::getRendaCustomBtnInfo")
    __builtin_unreachable();
}

__attribute__((weak)) bool nHumanActUtility::searchMyShlFromShlID(uDDOModel& mod, nShlBase::SHL_ID id) {
    DDON_STUB("nHumanActUtility::searchMyShlFromShlID")
    return {};
}

__attribute__((weak)) bool nHumanActUtility::cheakSequence(uHuman& human, u32 bit, u32 seqPage, MOT_TYPE s) {
    DDON_STUB("nHumanActUtility::cheakSequence")
    return {};
}

__attribute__((weak)) f32 nHumanActUtility::getSequenceCountFrame(uHuman& human, u32 seqCnt, u32 bit, MOT_TYPE blend, u32 seqPage) {
    DDON_STUB("nHumanActUtility::getSequenceCountFrame")
    return {};
}

void nHumanActUtility::setCstmResource(nHuman::CUSTOM_SKILL_ENUM skillID, uHuman* pHuman) {
    pHuman->setCstmMotionList(skillID);
    pHuman->setCstmCollision(skillID);
    pHuman->setCstmMotionSe(skillID);
}

void nHumanActUtility::resetCstmResource(uHuman* pHuman) {
    pHuman->resetCstmMotionList();
    pHuman->resetCstmCollision();
    pHuman->resetCstmMotionSe();
}

u32 nHumanActUtility::getActionNo(uDDOModel& mod) {
    if (mod.getActMgrPtr() != nullptr) {
        return mod.getActMgrPtr()->getActionNo();
    } else {
        return 0xFFFFFFFF;
    }
}

