// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIMailDetail.h"
#include "Protocol/PacketData/Mail.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/UserSession/S2C.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cMenuSupport.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIMail.h"
#include "uGUIPopDetail01.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIMailDetail::getDTI() const {
    return uGUIMailDetail::DTI;
}

__attribute__((noinline)) uGUIMailDetail::~uGUIMailDetail() {
    if (mpDetail != nullptr) {
        mpDetail->kill();
        mpDetail = nullptr;
    }
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIMailDetail::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIMailDetail::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_MAIL_DETAIL_GUI"), 129u, 1418991891l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_MAIL_BOX_GMD", 0u);
}

__attribute__((weak)) void uGUIMailDetail::setup() {
    DDON_STUB("uGUIMailDetail::setup")
    /* stub */
}

void uGUIMailDetail::kill() {
    this->uGUIBase::kill();
    if (mpDetail != nullptr) {
        mpDetail->kill();
        mpDetail = nullptr;
    }
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIMailDetail::updatePtr() {
    if (mpDetail == nullptr) {
        return;
    }
    if (mpDetail->isEnable()) {
        return;
    }
    mpDetail = nullptr;
}

__attribute__((weak)) s32 uGUIMailDetail::getSMenuCursorY() {
    DDON_STUB("uGUIMailDetail::getSMenuCursorY")
    return {};
}

void uGUIMailDetail::updateInit() {
    if (sMenu::getInstance()->mMenuMailDetail.mMenuRno[0] != 4) {
        return;
    }
    setMailData();
    evAdjCursor();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMailDetail::updateWait);
}

__attribute__((weak)) void uGUIMailDetail::updateWait() {
    DDON_STUB("uGUIMailDetail::updateWait")
    /* stub */
}

void uGUIMailDetail::updateExit() {
    end();
}

__attribute__((weak)) void uGUIMailDetail::setMailData() {
    DDON_STUB("uGUIMailDetail::setMailData")
    /* stub */
}

__attribute__((weak)) void uGUIMailDetail::moveInput() {
    DDON_STUB("uGUIMailDetail::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIMailDetail::moveEvent() {
    DDON_STUB("uGUIMailDetail::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIMailDetail::evAdjCursor() {
    DDON_STUB("uGUIMailDetail::evAdjCursor")
    /* stub */
}

__attribute__((weak)) void uGUIMailDetail::setItemCursor(s32 point) {
    DDON_STUB("uGUIMailDetail::setItemCursor")
    /* stub */
}

__attribute__((weak)) void uGUIMailDetail::setBtnCursor(s32 point) {
    DDON_STUB("uGUIMailDetail::setBtnCursor")
    /* stub */
}

u32 uGUIMailDetail::evCtrlDecide(cControl::Message* msg) {
    if (sMenu::getInstance()->mMenuMailDetail.mMenuRno[0] == 4) {
        if (mpVCtrl != nullptr) {
            if (mpVCtrl->mCurrentPos == 1) {
                setInputEvent(4u);
            }
        }
    }
    return 0;
}

u32 uGUIMailDetail::evCtrlCancel(cControl::Message* msg) {
    if (sMenu::getInstance()->mMenuMailDetail.mMenuRno[0] == 4) {
        setInputEvent(5u);
    }
    return 0;
}

u32 uGUIMailDetail::evCtrlAdjCursor(cControl::Message* msg) {
    setInputEvent(68u);
    return 0;
}

u32 uGUIMailDetail::evCtrlAdjCursorItem(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

u32 uGUIMailDetail::evCtrlAdjCursorBtn(cControl::Message* msg) {
    setInputEvent(70u);
    return 0;
}

__attribute__((weak)) u32 uGUIMailDetail::evCtrlBtnClick(cControl::Message* msg) {
    DDON_STUB("uGUIMailDetail::evCtrlBtnClick")
    return {};
}

u32 uGUIMailDetail::evCtrlItemClick(cControl::Message* msg) {
    if (mpVCtrl != nullptr) {
        if (mpVCtrl->mCurrentPos != 0) {
            mpVCtrl->setCurrentPos(0, false);
            setInputEvent(71u);
        } else {
            if (mpItemCtrl != nullptr) {
                if (mpItemCtrl->getCurrentPos() == mpItemCtrl->mOldPos) {
                    msg->changeSE = 0;
                } else {
                    setInputEvent(69u);
                }
            } else {
                msg->changeSE = 0;
            }
        }
    } else {
        if (mpItemCtrl != nullptr) {
            if (mpItemCtrl->getCurrentPos() == mpItemCtrl->mOldPos) {
                msg->changeSE = 0;
            } else {
                setInputEvent(69u);
            }
        } else {
            msg->changeSE = 0;
        }
    }
    return 0;
}

u32 uGUIMailDetail::evCtrlItemOver(cControl::Message* msg) {
    mMouseOverId = msg->mouse_hit_id;
    setInputEvent(72u);
    return 0;
}

u32 uGUIMailDetail::evCtrlItemOut(cControl::Message* msg) {
    mMouseOverId = -1;
    setInputEvent(73u);
    return 0;
}

inline uGUIMailDetail::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMailDetail::MyDTI uGUIMailDetail::DTI("uGUIMailDetail", &::uGUIBase::DTI, 5104ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMailDetail::MyDTI::newInstance() const {
    DDON_STUB("uGUIMailDetail::MyDTI::newInstance")
    return nullptr;
}

