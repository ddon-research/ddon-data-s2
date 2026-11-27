// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIFreeGroupChat.h"
#include "Protocol/PacketData/Community.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "uGUIBase.h"
#include "uGUICommunityList.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIFreeGroupChat::getDTI() const {
    return uGUIFreeGroupChat::DTI;
}

uGUIFreeGroupChat::~uGUIFreeGroupChat() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpCommList == nullptr) {
        return;
    }
    mpCommList->kill();
    mpCommList = nullptr;
}

void uGUIFreeGroupChat::createProperty(MtPropertyList& s) {
    this->uGUIsMenuBase::createProperty(s);
}

bool uGUIFreeGroupChat::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_FREEGROUP_GUI"), 129u, 1428922128l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_FREEGROUPCHAT_GMD", 0u);
}

__attribute__((weak)) void uGUIFreeGroupChat::setup() {
    DDON_STUB("uGUIFreeGroupChat::setup")
    /* stub */
}

void uGUIFreeGroupChat::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpCommList == nullptr) {
        return;
    }
    mpCommList->kill();
    mpCommList = nullptr;
}

void uGUIFreeGroupChat::move() {
    this->uGUIsMenuBase::move();
}

__attribute__((weak)) s32 uGUIFreeGroupChat::getSMenuCursorX() {
    DDON_STUB("uGUIFreeGroupChat::getSMenuCursorX")
    return {};
}

__attribute__((weak)) s32 uGUIFreeGroupChat::getSMenuCursorY() {
    DDON_STUB("uGUIFreeGroupChat::getSMenuCursorY")
    return {};
}

__attribute__((weak)) void uGUIFreeGroupChat::updatePtr() {
}

__attribute__((weak)) void uGUIFreeGroupChat::setupListInfo() {
    DDON_STUB("uGUIFreeGroupChat::setupListInfo")
    /* stub */
}

__attribute__((weak)) void uGUIFreeGroupChat::updateList() {
    DDON_STUB("uGUIFreeGroupChat::updateList")
    /* stub */
}

__attribute__((weak)) void uGUIFreeGroupChat::setMemberInfo(const CDataCharacterListElement* pData, u32 dispIndex) {
    DDON_STUB("uGUIFreeGroupChat::setMemberInfo")
    /* stub */
}

void uGUIFreeGroupChat::updateInit() {
    if (mpCtrl == nullptr) {
        return;
    }
    if (mpVCtrl == nullptr) {
        return;
    }
    if (mpHCtrl == nullptr) {
        return;
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIFreeGroupChat::updateWait);
}

__attribute__((weak)) void uGUIFreeGroupChat::updateWait() {
    DDON_STUB("uGUIFreeGroupChat::updateWait")
    /* stub */
}

void uGUIFreeGroupChat::updateExit() {
    if (mGUIFreeGrpChatInst.Null_all != nullptr) {
        mGUIFreeGrpChatInst.Null_all->setVisible(false);
    }
    end();
}

void uGUIFreeGroupChat::changeDisp() {
    if (mDispMode != 0) {
        mGUIFreeGrpChatObj.msg_slct_union->setVisible(false);
        cGUIObjMessage* t0 = mGUIFreeGrpChatObj.msg_slct_lobby;
        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 6u), 0u, false);
    } else {
        mGUIFreeGrpChatObj.msg_slct_union->setVisible(true);
        cGUIObjMessage* t1 = mGUIFreeGrpChatObj.msg_slct_lobby;
        setObjectMessage(static_cast<cGUIObject*>(t1), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 4u), 0u, false);
    }
    for (u32 i = 0; i != 15; i = i + 1u) {
        if (mDispMode != 0) {
            static_cast<cPlInfo*>(mPlInfoArray.getBuffer()[i])->mpOBJ_msg_list_m_loby->setVisible(false);
            static_cast<cPlInfo*>(mPlInfoArray.getBuffer()[i])->mpOBJ_msg_list_m_union->setVisible(false);
            static_cast<cPlInfo*>(mPlInfoArray.getBuffer()[i])->mpOBJ_msg_list_m_comment->setVisible(true);
        } else {
            static_cast<cPlInfo*>(mPlInfoArray.getBuffer()[i])->mpOBJ_msg_list_m_loby->setVisible(true);
            static_cast<cPlInfo*>(mPlInfoArray.getBuffer()[i])->mpOBJ_msg_list_m_union->setVisible(true);
            static_cast<cPlInfo*>(mPlInfoArray.getBuffer()[i])->mpOBJ_msg_list_m_comment->setVisible(false);
        }
    }
}

__attribute__((weak)) void uGUIFreeGroupChat::moveInput() {
    DDON_STUB("uGUIFreeGroupChat::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIFreeGroupChat::moveEvent() {
    DDON_STUB("uGUIFreeGroupChat::moveEvent")
    /* stub */
}

u32 uGUIFreeGroupChat::evCtrlEnd(cControl::Message* msg) {
    if (sMenu::getInstance()->mMenuGroupChatMemberList.mMenuRno[0] == 3) {
        setInputEvent(5u);
    }
    return 0;
}

u32 uGUIFreeGroupChat::evCtrlLClick(cControl::Message* msg) {
    setInputEvent(4u);
    return 0;
}

u32 uGUIFreeGroupChat::evCtrlVMove(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

u32 uGUIFreeGroupChat::evCtrlPageMove(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIFreeGroupChat::evCtrlHMove(cControl::Message* msg) {
    setInputEvent(68u);
    return 0;
}

u32 uGUIFreeGroupChat::evCtrlDecide(cControl::Message* msg) {
    setInputEvent(4u);
    return 0;
}

u32 uGUIFreeGroupChat::evCtrlSwitch(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

u32 uGUIFreeGroupChat::evCtrlBtnClick(cControl::Message* msg) {
    if (msg != nullptr) {
        if (mpVCtrl != nullptr) {
            mpVCtrl->setCurrentPos(mpVCtrl->getItemNum() - 1, false);
        }
        if (mpHCtrl != nullptr) {
            mpHCtrl->setCurrentPos(msg->click_vol, false);
        }
        setInputEvent(4u);
    }
    return 0;
}

__attribute__((weak)) MtObject* uGUIFreeGroupChat::MyDTI::newInstance() const {
    DDON_STUB("uGUIFreeGroupChat::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIFreeGroupChat::cPlInfo::getDTI() const {
    return uGUIFreeGroupChat::cPlInfo::DTI;
}

inline uGUIFreeGroupChat::cPlInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIFreeGroupChat::cPlInfo::MyDTI uGUIFreeGroupChat::cPlInfo::DTI("uGUIFreeGroupChat::cPlInfo", &::MtObject::DTI, 848ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIFreeGroupChat::cPlInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIFreeGroupChat::cPlInfo::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uGUIFreeGroupChat::cPlInfo>::~MtTypedArray();

