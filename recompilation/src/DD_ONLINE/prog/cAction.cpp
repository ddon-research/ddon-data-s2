// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cAction.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cDelegate.h"
#include "cState.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpPivotCtrl.h"
#include "cpStateManager.h"
#include "uControl.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAction::getDTI() const {
    return cAction::DTI;
}

cAction::cAction() {
    this->mRno = 0;
    mpModel = nullptr;
    mpActReq = nullptr;
    mpActMgr = nullptr;
}

cAction::~cAction() {
}

void cAction::preInit() {
    if (mpModel == nullptr) {
        return;
    }
    mpModel->resetAtkAdjust();
}

void cAction::init() {
    if (mpModel != nullptr) {
        if (mpModel->mGuardComponent.mpActionRequest != nullptr) {
            if (mpModel->getStateActionPtr() != nullptr) {
                cState* v0_9 = mpModel->getStateActionPtr()->mpCurrentState;
                if (v0_9 != nullptr) {
                    const MtDTI& t0 = v0_9->getDTI();
                    MT_CTSTR v0_1 = cStateAction::DTI.mName;
                    for (const MtDTI* v0_0 = &t0;;) {
                        if (v0_1 != v0_0->mName) {
                            if (v0_0->mpParent != nullptr) {
                                v0_0 = v0_0->mpParent;
                            } else {
                                break;
                            }
                        } else {
                            mpModel->getActionRequestPtr()->mEndAction = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 24);
                            mpModel->getActionRequestPtr()->mLandAction = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 28);
                            mpModel->getActionRequestPtr()->mFallAction = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 32);
                            mpModel->getActionRequestPtr()->mShrinkAction = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 40);
                            mpModel->getActionRequestPtr()->mBlowAction = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 36);
                            break;
                        }
                    }
                }
            }
        }
        if (mpModel != nullptr) {
            if (mpModel->getCtrl() != nullptr) {
                mpModel->getCtrl()->mForcePeriodic = nNetMsgData::nCtrl::NET_MSG_ID_PERIODIC_NOTHING;
            }
        }
    }
}

__attribute__((weak)) void cAction::move() {
}

void cAction::final() {
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->mpPivotCtrl == nullptr) {
        return;
    }
    mpModel->mpPivotCtrl->setActive(false);
}

__attribute__((weak)) void cAction::moveAfter() {
}

bool cAction::checkInit() {
    return true;
}

bool cAction::checkMove() {
    return true;
}

bool cAction::checkFinal() {
    return true;
}

bool cAction::checkMoveAfter() {
    return true;
}

__attribute__((weak)) void cAction::createProperty(MtPropertyList& s) {
}

void cAction::setEndAction(u32 ActNo) {
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->getActionRequestPtr() == nullptr) {
        return;
    }
    mpModel->getActionRequestPtr()->mEndAction = ActNo;
}

void cAction::setLandAction(u32 ActNo) {
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->getActionRequestPtr() == nullptr) {
        return;
    }
    mpModel->getActionRequestPtr()->mLandAction = ActNo;
}

void cAction::setFallAction(u32 ActNo) {
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->getActionRequestPtr() == nullptr) {
        return;
    }
    mpModel->getActionRequestPtr()->mFallAction = ActNo;
}

void cAction::requestAction(u32 ActNo) {
    if (mpActReq == nullptr) {
        return;
    }
    mpActReq->mRequestActionReq = ActNo;
}

__attribute__((weak)) void cAction::endAction() {
    DDON_STUB("cAction::endAction")
    /* stub */
}

void cAction::endActionNoSend() {
    if (mpActMgr == nullptr) {
        return;
    }
    mpActMgr->endActionNoSend();
}

__attribute__((weak)) bool cAction::isActionMotionEnd(MOT_TYPE type) {
    DDON_STUB("cAction::isActionMotionEnd")
    return {};
}

inline cAction::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAction::MyDTI cAction::DTI("cAction", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cAction::MyDTI::newInstance() const {
    return new (16u) cAction;
}

