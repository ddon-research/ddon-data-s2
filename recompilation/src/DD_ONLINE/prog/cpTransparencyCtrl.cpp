// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpTransparencyCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cDelegate.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sEventManager.h"
#include "../../XFramework/sMain.h"
#include "sPlayerManager.h"
#include "sWorkRate.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpTransparencyCtrl::getDTI() const {
    return cpTransparencyCtrl::DTI;
}

void* cpTransparencyCtrl::operator new(size_t sz, u32 align) {
    return cpTransparencyCtrl::getAllocator()->memAlloc(sz, align, cpTransparencyCtrl::DTI.getID());
}

cpTransparencyCtrl::cpTransparencyCtrl() {
    mBaseTrp = 1.0f;
    mStartTrp = 0.1f;
    mEndTrp = 1.0f;
    mIsClimbEnemy = false;
    mIsActive = false;
    mWaitTimer = 0.0f;
    mCamFadeStart = 0.0f;
    mCamFadeEnd = 0.0f;
    mCamFadeRno = 0;
    mCamFadeTimer = 0.0f;
    mSpeed = 0.01f;
    mpModel = nullptr;
}

cpTransparencyCtrl::~cpTransparencyCtrl() {
}

__attribute__((weak)) void cpTransparencyCtrl::setup() {
    DDON_STUB("cpTransparencyCtrl::setup")
    /* stub */
}

void cpTransparencyCtrl::createProperty(MtPropertyList& s) {
    this->cpComponent::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsActive", &mIsActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\210\235\346\234\237\345\200\244", &mStartTrp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\234\200\347\265\202\345\200\244", &mEndTrp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\244\211\345\214\226\351\200\237\345\272\246", &mSpeed, 0u, 0u);
}

__attribute__((weak)) void cpTransparencyCtrl::before() {
}

void cpTransparencyCtrl::update() {
    if (mpModel != nullptr) {
        if (mIsActive) {
            f32 t0 = mBaseTrp;
            f32 t1 = mSpeed;
            f32 t2 = sWorkRate::getInstance()->calc(3u);
            if (mSpeed > 0.0f) {
                if ((t0 + (t1 * t2)) >= mEndTrp) {
                    mIsActive = false;
                    mBaseTrp = mEndTrp;
                } else {
                    mBaseTrp = t0 + (t1 * t2);
                }
            } else {
                if (mEndTrp >= (t0 + (t1 * t2))) {
                    mIsActive = false;
                    mBaseTrp = mEndTrp;
                } else {
                    mBaseTrp = t0 + (t1 * t2);
                }
            }
            mpModel->mTransparency = mBaseTrp;
        }
        mIsClimbEnemy = false;
        if (sPlayerManager::getInstance()->getMyPlayer() != nullptr) {
            if (sPlayerManager::getInstance()->getMyPlayer()->mEnemyClimbInfo.mpModel == mpOwner) {
                if ((sPlayerManager::getInstance()->getMyPlayer()->mObjStatus & 32ul) != 0) {
                    if (checkFadeBellyVector()) {
                        mIsClimbEnemy = true;
                    }
                }
            }
        }
        f32 t3 = mBaseTrp;
        f32 t4 = getCameraRate();
        mpModel->mTransparency = t3 * t4;
        mIsClimbEnemy = false;
    }
}

void cpTransparencyCtrl::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

void cpTransparencyCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

void cpTransparencyCtrl::startChangeTrp(f32 initTrp, f32 endTrp, f32 frame) {
    if (mpModel == nullptr) {
        return;
    }
    if (0.0f > initTrp) {
    } else {
        if (initTrp > 1.0f) {
        } else {
            if (0.0f > endTrp) {
            } else {
                if (endTrp > 1.0f) {
                } else {
                    if (1.1920929e-7f > frame) {
                    } else {
                        mIsActive = true;
                        mStartTrp = initTrp;
                        mEndTrp = endTrp;
                        mSpeed = (endTrp - initTrp) / frame;
                        if (1e-5f > __builtin_fabsf((endTrp - initTrp) / frame)) {
                            mIsActive = false;
                            mBaseTrp = mEndTrp;
                        } else {
                            mBaseTrp = mStartTrp;
                        }
                        mpModel->mTransparency = mBaseTrp;
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void cpTransparencyCtrl::startChangeTrp(f32 endTrp, f32 frame) {
    DDON_STUB("cpTransparencyCtrl::startChangeTrp")
    /* stub */
}

__attribute__((weak)) f32 cpTransparencyCtrl::getCameraRate() {
    DDON_STUB("cpTransparencyCtrl::getCameraRate")
    return {};
}

__attribute__((weak)) bool cpTransparencyCtrl::checkFadeBellyVector() {
    DDON_STUB("cpTransparencyCtrl::checkFadeBellyVector")
    return {};
}

inline cpTransparencyCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpTransparencyCtrl::MyDTI cpTransparencyCtrl::DTI("cpTransparencyCtrl", &::cpComponent::DTI, 128ul, 0u, 0u);

MtObject* cpTransparencyCtrl::MyDTI::newInstance() const {
    return new (16u) cpTransparencyCtrl;
}

