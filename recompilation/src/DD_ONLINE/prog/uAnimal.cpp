// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uAnimal.h"
#include "Protocol/PacketData/Enemy.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "cAction.h"
#include "cComponentManager.h"
#include "cDelegate.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpComponent.h"
#include "cpEffectProvider.h"
#include "cpMotionSe.h"
#include "cpScrCollision.h"
#include "../../generated/shared/nDDOMath.h"
#include "rArchiveListArray.h"
#include "rEffectProvider.h"
#include "rSoundMotionSe.h"
#include "../../XFramework/rSoundRequest.h"
#include "sArchiveManager.h"
#include "../../XFramework/sCamera.h"
#include "../../XFramework/sCollision.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sMain.h"
#include "sPlayerManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uAnimal::getDTI() const {
    return uAnimal::DTI;
}

uAnimal::~uAnimal() {
}

__attribute__((weak)) void uAnimal::setup() {
    DDON_STUB("uAnimal::setup")
    /* stub */
}

__attribute__((weak)) void uAnimal::move() {
    DDON_STUB("uAnimal::move")
    /* stub */
}

void uAnimal::kill() {
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mArcTicket != t0) {
        sArchiveManager::getInstance()->returnTicket(mArcTicket);
        mArcTicket = t0;
    }
    this->uDDOModel::kill();
}

__attribute__((weak)) void uAnimal::checkAction() {
    DDON_STUB("uAnimal::checkAction")
    /* stub */
}

void uAnimal::updateMotion() {
    moveMotion();
}

void uAnimal::updateMatrix() {
    updateLocalMatrix();
    updateWorldMatrix();
}

__attribute__((weak)) void uAnimal::createComponent() {
    DDON_STUB("uAnimal::createComponent")
    /* stub */
}

void uAnimal::setModelType(u32 type) {
    if (type <= 9u) {
        mModelType = type;
    }
}

__attribute__((weak)) bool uAnimal::setResource() {
    DDON_STUB("uAnimal::setResource")
    return {};
}

__attribute__((weak)) void uAnimal::move_main() {
    DDON_STUB("uAnimal::move_main")
    /* stub */
}

__attribute__((weak)) u32 uAnimal::checkWall(f32 dist) {
    DDON_STUB("uAnimal::checkWall")
    return {};
}

__attribute__((weak)) void uAnimal::updateObjStatus() {
    DDON_STUB("uAnimal::updateObjStatus")
    /* stub */
}

inline uAnimal::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uAnimal::MyDTI uAnimal::DTI("uAnimal", &::uDDOModel::DTI, 9376ul, 0u, 0u);

MtObject* uAnimal::MyDTI::newInstance() const {
    return new (16u) uAnimal;
}

const MtDTI& uAnimal::ActBase::getDTI() const {
    return uAnimal::ActBase::DTI;
}

void uAnimal::ActBase::init() {
    this->cAction::init();
    mpAnimal = static_cast<uAnimal*>(mpModel);
}

void uAnimal::ActBase::updatePtr() {
    if (mpAnimal == nullptr) {
        return;
    }
    if (mpAnimal->isEnable()) {
        return;
    }
    mpAnimal = nullptr;
}

MtObject* uAnimal::ActBase::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActBase;
}

const MtDTI& uAnimal::ActFootwork::getDTI() const {
    return uAnimal::ActFootwork::DTI;
}

__attribute__((weak)) void uAnimal::ActFootwork::init() {
    DDON_STUB("uAnimal::ActFootwork::init")
    /* stub */
}

__attribute__((weak)) void uAnimal::ActFootwork::move() {
    DDON_STUB("uAnimal::ActFootwork::move")
    /* stub */
}

MtObject* uAnimal::ActFootwork::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActFootwork;
}

const MtDTI& uAnimal::ActWalk::getDTI() const {
    return uAnimal::ActWalk::DTI;
}

__attribute__((weak)) void uAnimal::ActWalk::init() {
    DDON_STUB("uAnimal::ActWalk::init")
    /* stub */
}

__attribute__((weak)) void uAnimal::ActWalk::move() {
    DDON_STUB("uAnimal::ActWalk::move")
    /* stub */
}

MtObject* uAnimal::ActWalk::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActWalk;
}

const MtDTI& uAnimal::ActRun::getDTI() const {
    return uAnimal::ActRun::DTI;
}

__attribute__((weak)) void uAnimal::ActRun::init() {
    DDON_STUB("uAnimal::ActRun::init")
    /* stub */
}

__attribute__((weak)) void uAnimal::ActRun::move() {
    DDON_STUB("uAnimal::ActRun::move")
    /* stub */
}

MtObject* uAnimal::ActRun::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActRun;
}

const MtDTI& uAnimal::ActTurn::getDTI() const {
    return uAnimal::ActTurn::DTI;
}

void uAnimal::ActTurn::init() {
    this->cAction::init();
    mpAnimal = static_cast<uAnimal*>(mpModel);
    u32 t0 = MtRandom::instance.nrand();
    mType = t0 & 1u;
    if ((t0 & 1u) != 0) {
        if (mpAnimal != nullptr) {
            if (mpAnimal->isExistMotionNo(16u)) {
                mpAnimal->setDDOMotion(MOT_BASE, 16u, true, 0u, 15.0f, 0.0f, 1.0f);
            } else {
                mpAnimal->setDDOMotion(MOT_BASE, 0u, true, 0u, -1.0f, 0.0f, 1.0f);
            }
            if (mpAnimal->mModelType == 9) {
                if (mType != 0) {
                    mTurnAngleY = 1.5707965f / (mpAnimal->mMotion[0].getFrameMax() * 0.5f);
                } else {
                    mTurnAngleY = -1.5707965f / (mpAnimal->mMotion[0].getFrameMax() * 0.5f);
                }
            }
        } else {
            if (mpAnimal->mModelType == 9) {
                mTurnAngleY = 1.5707965f / (mpAnimal->mMotion[0].getFrameMax() * 0.5f);
            }
        }
    } else {
        if (mpAnimal != nullptr) {
            if (mpAnimal->isExistMotionNo(15u)) {
                mpAnimal->setDDOMotion(MOT_BASE, 15u, true, 0u, 15.0f, 0.0f, 1.0f);
            } else {
                mpAnimal->setDDOMotion(MOT_BASE, 0u, true, 0u, -1.0f, 0.0f, 1.0f);
            }
            if (mpAnimal->mModelType == 9) {
                if (mType != 0) {
                    mTurnAngleY = 1.5707965f / (mpAnimal->mMotion[0].getFrameMax() * 0.5f);
                } else {
                    mTurnAngleY = -1.5707965f / (mpAnimal->mMotion[0].getFrameMax() * 0.5f);
                }
            }
        } else {
            if (mpAnimal->mModelType == 9) {
                mTurnAngleY = -1.5707965f / (mpAnimal->mMotion[0].getFrameMax() * 0.5f);
            }
        }
    }
}

void uAnimal::ActTurn::move() {
    if (mpAnimal->mModelType == 9) {
        MtVector3 frame56(mpAnimal->getAngle());
        mpAnimal->setAngle(frame56.y + (mTurnAngleY * sMain::getInstance()->mDeltaTime));
        if (isActionMotionEnd(MOT_BASE)) {
            if (mpAnimal != nullptr) {
                if (mpAnimal->getActMgrPtr() != nullptr) {
                    mpAnimal->getActMgrPtr()->setAction(1u, false, 0u, 0u, 0u, 0u, 0.0f, 0.0f, 0.0f, 0.0f);
                }
            }
        }
    } else {
        if (isActionMotionEnd(MOT_BASE)) {
            if (mpAnimal != nullptr) {
                if (mpAnimal->getActMgrPtr() != nullptr) {
                    mpAnimal->getActMgrPtr()->setAction(1u, false, 0u, 0u, 0u, 0u, 0.0f, 0.0f, 0.0f, 0.0f);
                }
            }
        }
    }
}

MtObject* uAnimal::ActTurn::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActTurn;
}

const MtDTI& uAnimal::ActCollapse::getDTI() const {
    return uAnimal::ActCollapse::DTI;
}

void uAnimal::ActCollapse::init() {
    this->cAction::init();
    mpAnimal = static_cast<uAnimal*>(mpModel);
    if (mpAnimal != nullptr) {
        if (mpModel->isExistMotionNo(569u)) {
            mpAnimal->setDDOMotion(MOT_BASE, 569u, true, 0u, 15.0f, 0.0f, 1.0f);
        } else {
            mpAnimal->setDDOMotion(MOT_BASE, 0u, true, 0u, -1.0f, 0.0f, 1.0f);
        }
    }
    mTimer = sMain::getInstance()->getFps() * 3.0f;
}

__attribute__((weak)) void uAnimal::ActCollapse::move() {
    DDON_STUB("uAnimal::ActCollapse::move")
    /* stub */
}

MtObject* uAnimal::ActCollapse::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActCollapse;
}

const MtDTI& uAnimal::ActEscape::getDTI() const {
    return uAnimal::ActEscape::DTI;
}

__attribute__((weak)) void uAnimal::ActEscape::init() {
    DDON_STUB("uAnimal::ActEscape::init")
    /* stub */
}

__attribute__((weak)) void uAnimal::ActEscape::move() {
    DDON_STUB("uAnimal::ActEscape::move")
    /* stub */
}

MtObject* uAnimal::ActEscape::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActEscape;
}

const MtDTI& uAnimal::ActApproach::getDTI() const {
    return uAnimal::ActApproach::DTI;
}

__attribute__((weak)) void uAnimal::ActApproach::init() {
    DDON_STUB("uAnimal::ActApproach::init")
    /* stub */
}

__attribute__((weak)) void uAnimal::ActApproach::move() {
    DDON_STUB("uAnimal::ActApproach::move")
    /* stub */
}

MtObject* uAnimal::ActApproach::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActApproach;
}

const MtDTI& uAnimal::ActFlap::getDTI() const {
    return uAnimal::ActFlap::DTI;
}

void uAnimal::ActFlap::init() {
    this->cAction::init();
    mpAnimal = static_cast<uAnimal*>(mpModel);
    if (mpAnimal == nullptr) {
        return;
    }
    if (mpModel->isExistMotionNo(367u)) {
        mpAnimal->setDDOMotion(MOT_BASE, 367u, true, 0u, 15.0f, 0.0f, 1.0f);
    } else {
        mpAnimal->setDDOMotion(MOT_BASE, 0u, true, 0u, -1.0f, 0.0f, 1.0f);
    }
}

__attribute__((weak)) void uAnimal::ActFlap::move() {
    DDON_STUB("uAnimal::ActFlap::move")
    /* stub */
}

MtObject* uAnimal::ActFlap::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActFlap;
}

const MtDTI& uAnimal::ActSleep::getDTI() const {
    return uAnimal::ActSleep::DTI;
}

uAnimal::ActSleep::~ActSleep() {
    if (mpEfcHandle == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpEfcHandle, 2u);
    mpEfcHandle = nullptr;
}

void uAnimal::ActSleep::init() {
    this->cAction::init();
    mpAnimal = static_cast<uAnimal*>(mpModel);
    if (mpAnimal != nullptr) {
        if (mpModel->isExistMotionNo(610u)) {
            mpAnimal->setDDOMotion(MOT_BASE, 610u, true, 0u, 15.0f, 0.0f, 1.0f);
        } else {
            mpAnimal->setDDOMotion(MOT_BASE, 0u, true, 0u, -1.0f, 0.0f, 1.0f);
        }
    }
    mTimer = sMain::getInstance()->getFps() * 5.0f;
}

__attribute__((weak)) void uAnimal::ActSleep::move() {
    DDON_STUB("uAnimal::ActSleep::move")
    /* stub */
}

MtObject* uAnimal::ActSleep::MyDTI::newInstance() const {
    return new (16u) uAnimal::ActSleep;
}

