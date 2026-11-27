// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUICaplinkImageSelect.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "sCaplinkManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUICaplinkProfile.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUICaplinkImageSelect::getDTI() const {
    return uGUICaplinkImageSelect::DTI;
}

void* uGUICaplinkImageSelect::operator new(size_t sz, u32 align) {
    return uGUICaplinkImageSelect::getAllocator()->memAlloc(sz, align, uGUICaplinkImageSelect::DTI.getID());
}

__attribute__((noinline)) uGUICaplinkImageSelect::~uGUICaplinkImageSelect() {
    DDON_STUB("uGUICaplinkImageSelect::~uGUICaplinkImageSelect")
    /* stub */
}

void uGUICaplinkImageSelect::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUICaplinkImageSelect::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CAP_IMAGE_GUI"), 129u, 1428554834l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_CAPLINK_RES_GMD", 0u);
}

__attribute__((weak)) void uGUICaplinkImageSelect::setup() {
    DDON_STUB("uGUICaplinkImageSelect::setup")
    /* stub */
}

void uGUICaplinkImageSelect::kill() {
    this->uGUIBase::kill();
}

void uGUICaplinkImageSelect::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUICaplinkImageSelect::updatePtr() {
}

void uGUICaplinkImageSelect::draw(cDraw* pDraw) {
    this->uGUIBase::draw(pDraw);
}

__attribute__((weak)) void uGUICaplinkImageSelect::setFlowId(u32 flow_id) {
    DDON_STUB("uGUICaplinkImageSelect::setFlowId")
    /* stub */
}

void uGUICaplinkImageSelect::moveInput() {
    if (mFlowId != 1) {
        return;
    }
    mMain.mClose.execute();
    if (mpCancelCtrl != nullptr) {
        mpCancelCtrl->execute();
    }
    if (mpDecideCtrl != nullptr) {
        mpDecideCtrl->execute();
    }
    if (mpListCtrl != nullptr) {
        mpListCtrl->execute();
    }
    if (mpTabCtrl != nullptr) {
        mpTabCtrl->execute();
    }
    if (mpButtonCtrl == nullptr) {
        return;
    }
    mpButtonCtrl->execute();
}

__attribute__((weak)) void uGUICaplinkImageSelect::moveEvent() {
    DDON_STUB("uGUICaplinkImageSelect::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkImageSelect::updateMove() {
    DDON_STUB("uGUICaplinkImageSelect::updateMove")
    /* stub */
}

void uGUICaplinkImageSelect::updateExit() {
    end();
}

void uGUICaplinkImageSelect::setupTab() {
    u32 t0 = static_cast<sGUIExt*>(sGUI::getInstance())->mCaplinkIcon.mLength;
    mMain.mTabNum = static_cast<unsigned int>(((static_cast<unsigned long>(t0) * 0x38E38E39) >> 33) + (t0 != static_cast<unsigned int>(((static_cast<unsigned long>(t0) * 0x38E38E39) >> 33) * 9ul)));
    mMain.mTab.setVisibleTabMax(static_cast<unsigned int>(((static_cast<unsigned long>(t0) * 0x38E38E39) >> 33) + (t0 != static_cast<unsigned int>(((static_cast<unsigned long>(t0) * 0x38E38E39) >> 33) * 9ul))));
    if (mMain.mTabNum != 0) {
        if (mpTabCtrl != nullptr) {
            mpTabCtrl->resetItemNum(static_cast<s32>(mMain.mTabNum), static_cast<const u32*>(nullptr), 0);
            mMain.mTab.setupMouseTouchList(static_cast<cControl*>(mpTabCtrl), -1);
            cHorizontalList* t1 = mpTabCtrl;
            if (t1 != nullptr) {
                t1->mCtrlF = t1->mCtrlF & 0xFFFFFFF7u;
                mMain.mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t1->getCurrentPos()), true, true);
            } else {
                mMain.mTab.uGUIBase::cReferenceUITab::setFocus(0u, true, true);
            }
            setupList();
        } else {
            mMain.mTab.setupMouseTouchList(static_cast<cControl*>(nullptr), -1);
            cHorizontalList* t1 = mpTabCtrl;
            if (t1 != nullptr) {
                t1->mCtrlF = t1->mCtrlF & 0xFFFFFFF7u;
                mMain.mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t1->getCurrentPos()), true, true);
            } else {
                mMain.mTab.uGUIBase::cReferenceUITab::setFocus(0u, true, true);
            }
            setupList();
        }
    } else {
        if (mpTabCtrl != nullptr) {
            mpTabCtrl->setFocus(false);
        }
        setupList();
    }
}

__attribute__((weak)) void uGUICaplinkImageSelect::setupList() {
    DDON_STUB("uGUICaplinkImageSelect::setupList")
    /* stub */
}

__attribute__((weak)) void uGUICaplinkImageSelect::adjustCursor() {
    DDON_STUB("uGUICaplinkImageSelect::adjustCursor")
    /* stub */
}

__attribute__((weak)) u32 uGUICaplinkImageSelect::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUICaplinkImageSelect::evCtrlDecide")
    return {};
}

u32 uGUICaplinkImageSelect::evCtrlCancel(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 5;
    }
    setInputEvent(68u);
    return 1;
}

u32 uGUICaplinkImageSelect::evCtrlClose(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 5;
    }
    setInputEvent(68u);
    return 1;
}

__attribute__((weak)) u32 uGUICaplinkImageSelect::evCtrlAdjustCursor(cControl::Message* msg) {
    DDON_STUB("uGUICaplinkImageSelect::evCtrlAdjustCursor")
    return {};
}

u32 uGUICaplinkImageSelect::evCtrlAdjustTab(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 3;
    }
    setInputEvent(70u);
    return 1;
}

u32 uGUICaplinkImageSelect::evCtrlMouseClick(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->pSender != nullptr) {
            if (msg->pSender != mpListCtrl) {
                if (msg->pSender != mpButtonCtrl) {
                    return 0;
                }
                mMain.mIsSelectList = false;
            } else {
                mMain.mIsSelectList = true;
            }
            adjustCursor();
            return evCtrlDecide(msg);
        }
    }
    return 0;
}

inline uGUICaplinkImageSelect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICaplinkImageSelect::MyDTI uGUICaplinkImageSelect::DTI("uGUICaplinkImageSelect", &::uGUIBase::DTI, 4160ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICaplinkImageSelect::MyDTI::newInstance() const {
    DDON_STUB("uGUICaplinkImageSelect::MyDTI::newInstance")
    return nullptr;
}

uGUICaplinkImageSelect::stMain::stMain() {
    DDON_STUB("uGUICaplinkImageSelect::stMain::stMain")
    /* stub */
}

