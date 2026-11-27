// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cJob10Action.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cAction.h"
#include "cContextPlayerInfo.h"
#include "cHumanAction.h"
#include "cpActionManager.h"
#include "cpSequenceCtrl.h"
#include "cpjob10.h"
#include "nDDOUtility.h"
#include "uDDOModel.h"
#include "uHuman.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cJob10ExecuteBoost::getDTI() const {
    return cJob10ExecuteBoost::DTI;
}

void cJob10ExecuteBoost::init() {
    this->cHumanActBase::init();
    mIsStartDecSpirit = false;
    if (mpActMgr != nullptr) {
        if (mpHuman->mpContextPlayerInfo != nullptr) {
            if (mpHuman->mpContextPlayerInfo->mCurrentJob_pri == 10) {
                u32 nowAct = mpActMgr->getActionNo();
                if (nowAct == 8208) {
                    mpHuman->mpJob10->reqBoostMode(cpJob10::BOOST_MODE_NUKE);
                    uHuman* t0 = mpHuman;
                    if (t0->isMaster()) {
                        if ((t0->uDDOModel::mUnitId & 8u) != 0) {
                            nDDOUtility::requestOnTutorialFlg(102);
                        }
                    }
                    mpModel->setDDOMotion(MOT_BASE, 1055u, true, 0u, -1.0f, 0.0f, 1.0f);
                    mpHuman->getSequenceCtrlPtr()->setupSequenceCount(0, true, MOT_BASE, 1u, 16u);
                } else {
                    mpHuman->mpJob10->reqBoostMode(cpJob10::BOOST_MODE_SUPPORT);
                    uHuman* t0 = mpHuman;
                    if (t0->isMaster()) {
                        if ((t0->uDDOModel::mUnitId & 8u) != 0) {
                            nDDOUtility::requestOnTutorialFlg(102);
                        }
                    }
                    mpModel->setDDOMotion(MOT_BASE, 1056u, true, 0u, -1.0f, 0.0f, 1.0f);
                    mpHuman->getSequenceCtrlPtr()->setupSequenceCount(0, true, MOT_BASE, 1u, 16u);
                }
            } else {
                mpModel->setDDOMotion(MOT_BASE, 1055u, true, 0u, -1.0f, 0.0f, 1.0f);
                mpHuman->getSequenceCtrlPtr()->setupSequenceCount(0, true, MOT_BASE, 1u, 16u);
            }
        } else {
            mpModel->setDDOMotion(MOT_BASE, 1055u, true, 0u, -1.0f, 0.0f, 1.0f);
            mpHuman->getSequenceCtrlPtr()->setupSequenceCount(0, true, MOT_BASE, 1u, 16u);
        }
    } else {
        mpModel->setDDOMotion(MOT_BASE, 1055u, true, 0u, -1.0f, 0.0f, 1.0f);
        mpHuman->getSequenceCtrlPtr()->setupSequenceCount(0, true, MOT_BASE, 1u, 16u);
    }
}

void cJob10ExecuteBoost::move() {
    this->cHumanActBase::move();
    mpModel->mObjStatus = mpModel->mObjStatus | 1ul;
    mpHuman->mObjStatus = mpHuman->mObjStatus | 8192ul;
    if (!mIsStartDecSpirit) {
        if (mpHuman->getSequenceCtrlPtr()->getSequenceCount(0) > 0) {
            mpHuman->mpJob10->callbackFantasticBoost();
            mIsStartDecSpirit = true;
        }
    }
    if (!isActionMotionEnd(MOT_BASE)) {
        return;
    }
    endAction();
}

void cJob10ExecuteBoost::final() {
    if (!mIsStartDecSpirit) {
        if (mpHuman->mpContextPlayerInfo != nullptr) {
            if (mpHuman->mpContextPlayerInfo->mCurrentJob_pri == 10) {
                mpHuman->mpJob10->callbackFantasticBoost();
            }
        }
    }
    this->cHumanActBase::final();
    if (mpHuman->mpJob10 == nullptr) {
        return;
    }
    mpHuman->mpJob10->isJob10ActionEnd = true;
}

__attribute__((weak)) MtObject* cJob10ExecuteBoost::MyDTI::newInstance() const {
    DDON_STUB("cJob10ExecuteBoost::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cJob10NormalAttackBase::getDTI() const {
    return cJob10NormalAttackBase::DTI;
}

void cJob10NormalAttackBase::init() {
    this->cHumanActBase::init();
}

void cJob10NormalAttackBase::move() {
    this->cHumanActBase::move();
}

void cJob10NormalAttackBase::final() {
    this->cHumanActBase::final();
    if (mpHuman->mpJob10 == nullptr) {
        return;
    }
    mpHuman->mpJob10->isJob10ActionEnd = true;
}

inline cJob10NormalAttackBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cJob10NormalAttackBase::MyDTI cJob10NormalAttackBase::DTI("cJob10NormalAttackBase", &::cHumanActBase::DTI, 72ul, 0u, 0u);

MtObject* cJob10NormalAttackBase::MyDTI::newInstance() const {
    return new (16u) cJob10NormalAttackBase;
}

