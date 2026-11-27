// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUILoading.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cGUIInstance.h"
#include "cGUIObjTextureRef.h"
#include "../../XFramework/cGUIObject.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rLoadingParam.h"
#include "../../XFramework/rTexture.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUILoading::getDTI() const {
    return uGUILoading::DTI;
}

void* uGUILoading::operator new(size_t sz, u32 align) {
    return uGUILoading::getAllocator()->memAlloc(sz, align, uGUILoading::DTI.getID());
}

uGUILoading::uGUILoading() : uGUIBase(0u, false) {
    mAreaNo = 0;
    mStageNo = 0;
    mEnable = false;
    mIsUseLoadingInfoSdl = false;
    mpObjTexRefBack = nullptr;
    mpObjMsgText = nullptr;
    mpInstMsg = nullptr;
    mpLoadingParam = nullptr;
    mpGUIRes = nullptr;
    mLoadingId = -1;
    mMsgIdx = 0;
    mImgId = 0;
    mArcTicket = sArchiveManager::INVALID_TICKET;
    mpLoadingMsg = nullptr;
    mpTexImg = nullptr;
    mPos2InstMsgInit = MtVector2::Zero;
    mEndType = 1;
    setArcTag(rArchiveListArray::convTagId("uGUILoading"), 0u, false);
}

__attribute__((noinline)) uGUILoading::~uGUILoading() {
    DDON_STUB("uGUILoading::~uGUILoading")
    /* stub */
}

bool uGUILoading::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_LOADING00_GUI"), 129u, 1419489049l))) == nullptr)) {
        return false;
    }
    if ((mpLoadingParam == nullptr) && ((mpLoadingParam = static_cast<rLoadingParam*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_LDPARAM_LDP"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUILoading::setup() {
    DDON_STUB("uGUILoading::setup")
    /* stub */
}

void uGUILoading::kill() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpLoadingParam != nullptr) {
        mpLoadingParam->release();
        mpLoadingParam = nullptr;
        cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
        if (mArcTicket != t0) {
            sArchiveManager::getInstance()->returnTicket(mArcTicket);
            mArcTicket = t0;
        }
        if (mpTexImg != nullptr) {
            mpTexImg->release();
            mpTexImg = nullptr;
        }
        if (mpLoadingMsg != nullptr) {
            mpLoadingMsg->release();
            mpLoadingMsg = nullptr;
        }
        this->uGUIBase::kill();
    } else {
        cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
        if (mArcTicket != t0) {
            sArchiveManager::getInstance()->returnTicket(mArcTicket);
            mArcTicket = t0;
        }
        if (mpTexImg != nullptr) {
            mpTexImg->release();
            mpTexImg = nullptr;
        }
        if (mpLoadingMsg != nullptr) {
            mpLoadingMsg->release();
            mpLoadingMsg = nullptr;
        }
        this->uGUIBase::kill();
    }
}

__attribute__((weak)) void uGUILoading::move() {
    DDON_STUB("uGUILoading::move")
    /* stub */
}

void uGUILoading::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUILoading::updateWait);
}

__attribute__((weak)) void uGUILoading::updateWait() {
    DDON_STUB("uGUILoading::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUILoading::adjustScale() {
    DDON_STUB("uGUILoading::adjustScale")
    /* stub */
}

inline uGUILoading::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUILoading::MyDTI uGUILoading::DTI("uGUILoading", &::uGUIBase::DTI, 2352ul, 0u, 0u);

MtObject* uGUILoading::MyDTI::newInstance() const {
    return new (16u) uGUILoading;
}

