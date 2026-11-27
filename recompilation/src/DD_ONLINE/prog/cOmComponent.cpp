// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cOmComponent.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "cComponentManager.h"
#include "cEfcHandle.h"
#include "cNetGameServer.h"
#include "cObjHitCache.h"
#include "cOmControl.h"
#include "cResPath.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpCatchCtrl.h"
#include "cpComponent.h"
#include "cpEffectProvider.h"
#include "cpHeadCtrl.h"
#include "cpLayout.h"
#include "cpMotionSe.h"
#include "cpNpc.h"
#include "cpObjCollision.h"
#include "cpOmBlink.h"
#include "cpOmComponent.h"
#include "cpOmGather.h"
#include "cpRootComponent.h"
#include "cpSoftBody.h"
#include "cpTalk.h"
#include "cpTransparencyCtrl.h"
#include "rOmParam.h"
#include "rSoundMotionSe.h"
#include "../../XFramework/rSoundRequest.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sNpcManager.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#include "uOmModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

cOmComponent::cOmComponent() {
    mIsCallSe = false;
    mpSoundRequest = nullptr;
    mpuCatchOld = nullptr;
    mbSlave = false;
    mSyncValue = 0;
    mbReqKill = false;
    mRno = 0;
    mOmType = 0;
    mUseComponent = 0;
    mpOmModel = nullptr;
    mpOmControl = nullptr;
    memset(static_cast<void*>(&mphEfc[0]), 0, 130ul);
}

cOmComponent::~cOmComponent() {
    for (u32 fcnt = 0; fcnt != 16; fcnt = fcnt + 1u) {
        if (mphEfc[fcnt] != nullptr) {
            static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mphEfc[fcnt], 4u);
            mphEfc[fcnt] = nullptr;
        }
    }
}

__attribute__((weak)) void cOmComponent::setup(uBaseModel* pum) {
    DDON_STUB("cOmComponent::setup")
    /* stub */
}

void cOmComponent::move(uBaseModel* pum) {
    if (pum == nullptr) {
        return;
    }
    loopSeControl(pum);
    if (!mbReqKill) {
        return;
    }
    cpTransparencyCtrl* pCtrl = static_cast<cpTransparencyCtrl*>(mpOmModel->mComponentMgr.getRootComponent()->find(cpTransparencyCtrl::DTI, true, true));
    if (pCtrl != nullptr) {
        if (!pCtrl->mIsActive) {
            mpOmModel->kill();
        }
    } else {
        mpOmModel->kill();
    }
}

__attribute__((weak)) void cOmComponent::kill(uBaseModel* pum) {
    DDON_STUB("cOmComponent::kill")
    /* stub */
}

void cOmComponent::reqKill() {
    mbReqKill = true;
    if (mpOmModel == nullptr) {
        return;
    }
    cpTransparencyCtrl* pCtrl = static_cast<cpTransparencyCtrl*>(mpOmModel->mComponentMgr.getRootComponent()->find(cpTransparencyCtrl::DTI, true, true));
    if (pCtrl == nullptr) {
        return;
    }
    pCtrl->startChangeTrp(1.0f, 0.0f, 15.0f);
}

__attribute__((weak)) void cOmComponent::updatePtr() {
    DDON_STUB("cOmComponent::updatePtr")
    /* stub */
}

__attribute__((weak)) void cOmComponent::createComponent(cpComponent* pRootCP, MtObject* pOwner, u32 questNo) {
    DDON_STUB("cOmComponent::createComponent")
    /* stub */
}

bool cOmComponent::isOnFlag(u32 flag) {
    if (((flag >> 8) & 4u) != 0) {
        if ((mpOmControl != nullptr) && (mpOmControl->mOmID == 522157)) {
            return true;
        }
    }
    return (flag & mUseComponent) != 0;
}

__attribute__((weak)) void cOmComponent::initObjCollision(uOmModel* puom, rObjCollision* pRes) {
    DDON_STUB("cOmComponent::initObjCollision")
    /* stub */
}

void cOmComponent::eraseObjCollision(uOmModel* puom) {
    if (puom == nullptr) {
        return;
    }
    cpComponent* t0 = puom->mComponentMgr.getRootComponent()->find(cpObjCollisionBase::DTI, true, true);
    if (t0 == nullptr) {
        return;
    }
    static_cast<cpObjCollisionBase*>(t0)->setResource(static_cast<rObjCollision*>(nullptr), 0u);
    static_cast<cpObjCollisionBase*>(t0)->killNodeAll();
}

void cOmComponent::killNodeAll(uOmModel* puom) {
    if (puom == nullptr) {
        return;
    }
    cpObjCollisionBase* p_comp = static_cast<cpObjCollisionBase*>(puom->mComponentMgr.getRootComponent()->find(cpObjCollisionBase::DTI, true, true));
    if (p_comp == nullptr) {
        return;
    }
    p_comp->killNodeAll();
}

void cOmComponent::keyOffSe() {
    if (mpOmModel == nullptr) {
        return;
    }
    static_cast<sSoundExt*>(sSound::getInstance())->keyOffSe(mpSoundRequest, 1u, reinterpret_cast<const uintptr>(mpOmModel), sSoundExt::SE_SEARCH_KEY_ALL);
}

void cOmComponent::initMotionSe(uOmModel* puom, const cOmParam* pParam) {
    if (puom == nullptr) {
        return;
    }
    cpComponent* t0 = puom->mComponentMgr.getRootComponent()->find(cpMotionSe::DTI, true, true);
    if (t0 == nullptr) {
        return;
    }
    cResource* t1 = sArchiveManager::getInstance()->createRes(pParam->mrSoundMotionSe.getResId(), 1u, false);
    if (t1 != nullptr) {
        static_cast<cpMotionSe*>(t0)->setMotionSe(static_cast<rSoundMotionSe*>(t1));
        t1->release();
        cResource* t2 = sArchiveManager::getInstance()->createRes(pParam->mrSoundRequest.getResId(), 1u, false);
        if (t2 != nullptr) {
            static_cast<cpMotionSe*>(t0)->setRequest(static_cast<rSoundRequest*>(t2), 0u);
            t2->release();
        }
    } else {
        cResource* t2 = sArchiveManager::getInstance()->createRes(pParam->mrSoundRequest.getResId(), 1u, false);
        if (t2 != nullptr) {
            static_cast<cpMotionSe*>(t0)->setRequest(static_cast<rSoundRequest*>(t2), 0u);
            t2->release();
        }
    }
}

__attribute__((weak)) void cOmComponent::loopSeControl(uBaseModel* pum) {
    DDON_STUB("cOmComponent::loopSeControl")
    /* stub */
}

__attribute__((weak)) void cOmComponent::initEffectProvider(uOmModel* puom, rEffectProvider* pRes) {
    DDON_STUB("cOmComponent::initEffectProvider")
    /* stub */
}

void cOmComponent::updateEfcHandle() {
    for (u32 fcnt = 0; fcnt != 16; fcnt = fcnt + 1u) {
        if (mphEfc[fcnt] != nullptr) {
            if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mphEfc[fcnt])) {
                mphEfc[fcnt]->mpOwner = nullptr;
                mphEfc[fcnt] = nullptr;
            }
        }
    }
}

__attribute__((weak)) void cOmComponent::setEffect(s32 index, uOmModel* puom) {
    DDON_STUB("cOmComponent::setEffect")
    /* stub */
}

void cOmComponent::finishFx(s32 index, uOmModel* puom) {
    if (puom == nullptr) {
        return;
    }
    if (index > -1) {
        if (static_cast<unsigned int>(index) <= 15) {
            if (puom->mOmComp.mphEfc[index] != nullptr) {
                static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(puom->mOmComp.mphEfc[index], 1u);
                puom->mOmComp.mphEfc[index] = nullptr;
            }
        }
    }
}

