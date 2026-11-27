// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIBazaarHistory.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/rSoundRequest.h"
#include "sBazaarManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBazaarHistory::getDTI() const {
    return uGUIBazaarHistory::DTI;
}

void* uGUIBazaarHistory::operator new(size_t sz, u32 align) {
    return uGUIBazaarHistory::getAllocator()->memAlloc(sz, align, uGUIBazaarHistory::DTI.getID());
}

uGUIBazaarHistory::uGUIBazaarHistory() : uGUIBase(0u, false) {
    mBaseF = mBaseF | 64u;
    mpSNDRes = nullptr;
    mpGMDRes = nullptr;
    mpGUIRes = nullptr;
    setArcTag(rArchiveListArray::convTagId("uGUIBazaar"), 0u, false);
    mIsBegin = false;
    mFocus = false;
    mpCtrl = nullptr;
    mStay = false;
    mpObjMsgHeader03 = nullptr;
    mpObjMsgHeader02 = nullptr;
    mpObjMsgHeader01 = nullptr;
    mpObjMsgHeader00 = nullptr;
    mpObjMsgTitle = nullptr;
    mListNum = 0;
    mItemNo = 0;
    mMode = 0;
    mListType = 0;
}

uGUIBazaarHistory::~uGUIBazaarHistory() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpSNDRes == nullptr) {
        return;
    }
    mpSNDRes->release();
    mpSNDRes = nullptr;
}

void uGUIBazaarHistory::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "開始", static_cast<MT_MFUNC>(&::uGUIBazaarHistory::begin), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "終了", static_cast<MT_MFUNC>(&::uGUIBazaarHistory::hide), 10u);
}

bool uGUIBazaarHistory::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_BAZZARINFO_GUI"), 129u, 1418994382l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZAAR_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpSNDRes == nullptr) && ((mpSNDRes = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_BAZAAR_SRQR"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIBazaarHistory::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIBazaarHistory::setup() {
    DDON_STUB("uGUIBazaarHistory::setup")
    /* stub */
}

void uGUIBazaarHistory::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes == nullptr) {
        return;
    }
    mpGMDRes->release();
    mpGMDRes = nullptr;
}

__attribute__((weak)) void uGUIBazaarHistory::updatePtr() {
}

void uGUIBazaarHistory::begin() {
    replacePriority(11u);
    mFocus = true;
    mpCtrl->setFocus(true);
    (&mBtnGuide)->setFocus(true);
    mStay = false;
    mIsBegin = true;
    mListType = 1;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarHistory::updateInit);
}

__attribute__((weak)) void uGUIBazaarHistory::hide() {
    DDON_STUB("uGUIBazaarHistory::hide")
    /* stub */
}

void uGUIBazaarHistory::moveInput() {
    if (!mpCtrl->getFocus()) {
        return;
    }
    mpCtrl->execute();
}

__attribute__((weak)) void uGUIBazaarHistory::moveEvent() {
}

__attribute__((weak)) void uGUIBazaarHistory::updateInit() {
    DDON_STUB("uGUIBazaarHistory::updateInit")
    /* stub */
}

void uGUIBazaarHistory::updateMove() {
    if (mListType == 1) {
        updateTradeList();
    } else {
        updateExhibitList();
    }
}

__attribute__((weak)) void uGUIBazaarHistory::updateWait() {
}

void uGUIBazaarHistory::updateChange() {
    if (mListType == 1) {
        if ((sBazaarManager::getInstance()->getGetAnExhibitItemHistoryReqResult() - 2u) <= 1u) {
            mListNum = -1;
            if (mMode == 0) {
                mpCtrl->setFocus(false);
            } else {
                mpCtrl->setFocus(true);
            }
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarHistory::updateMove);
        } else {
            if (sBazaarManager::getInstance()->getGetAnExhibitItemHistoryReqResult() == 0) {
                sBazaarManager::getInstance()->reqGetAnExhibitItemHistory(mItemNo);
            }
        }
    } else {
        if ((sBazaarManager::getInstance()->getResultAnExhibitItemInfo() - 2u) <= 1u) {
            mListNum = -1;
            if (mMode != 0) {
                mpCtrl->setFocus(true);
            } else {
                mpCtrl->setFocus(false);
            }
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarHistory::updateMove);
        } else {
            if (sBazaarManager::getInstance()->getResultAnExhibitItemInfo() == 0) {
                sBazaarManager::getInstance()->reqGetAnExhibitItemInfo(mItemNo);
            }
        }
    }
}

void uGUIBazaarHistory::initialize() {
    cGUIObjMessage* t0 = mpObjMsgTitle;
    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 51u), 0u, false);
    cGUIObjMessage* t1 = mpObjMsgHeader00;
    setObjectMessage(static_cast<cGUIObject*>(t1), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 53u), 0u, false);
    cGUIObjMessage* t2 = mpObjMsgHeader01;
    setObjectMessage(static_cast<cGUIObject*>(t2), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 41u), 0u, false);
    cGUIObjMessage* t3 = mpObjMsgHeader02;
    setObjectMessage(static_cast<cGUIObject*>(t3), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 54u), 0u, false);
    cGUIObjMessage* t4 = mpObjMsgHeader03;
    setObjectMessage(static_cast<cGUIObject*>(t4), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 42u), 0u, false);
    mListNum = -1;
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[0].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[0].mpInstHistory), false);
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[1].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[1].mpInstHistory), false);
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[2].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[2].mpInstHistory), false);
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[3].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[3].mpInstHistory), false);
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[4].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[4].mpInstHistory), false);
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[5].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[5].mpInstHistory), false);
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[6].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[6].mpInstHistory), false);
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[7].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[7].mpInstHistory), false);
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[8].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[8].mpInstHistory), false);
    setInstanceVisibleTree(static_cast<cGUIInstance*>(mItemHistory[9].mpInstHistory), false);
    setInstanceExecuteTree(static_cast<cGUIInstance*>(mItemHistory[9].mpInstHistory), false);
}

u32 uGUIBazaarHistory::evCtrlTopBtn(cControl::Message* msg) {
    mpCtrl->setFocus(false);
    mListType = static_cast<u32>(mListType == 0);
    static_cast<sSoundExt*>(sSound::getInstance())->requestSe(mpSNDRes, 12u, reinterpret_cast<uintptr>(this), 0u, static_cast<sSound::CALLBACK_FUNC>(nullptr), static_cast<void*>(nullptr));
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarHistory::updateChange);
    return 0;
}

__attribute__((weak)) void uGUIBazaarHistory::updateTradeList() {
    DDON_STUB("uGUIBazaarHistory::updateTradeList")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarHistory::updateExhibitList() {
    DDON_STUB("uGUIBazaarHistory::updateExhibitList")
    /* stub */
}

inline uGUIBazaarHistory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarHistory::MyDTI uGUIBazaarHistory::DTI("uGUIBazaarHistory", &::uGUIBase::DTI, 3152ul, 0u, 0u);

MtObject* uGUIBazaarHistory::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarHistory;
}

const MtDTI& uGUIBazaarHistory::cItemHistory::getDTI() const {
    return uGUIBazaarHistory::cItemHistory::DTI;
}

inline uGUIBazaarHistory::cItemHistory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarHistory::cItemHistory::MyDTI uGUIBazaarHistory::cItemHistory::DTI("uGUIBazaarHistory::cItemHistory", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* uGUIBazaarHistory::cItemHistory::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarHistory::cItemHistory;
}

