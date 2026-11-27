// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIMail.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
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
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIMail::getDTI() const {
    return uGUIMail::DTI;
}

__attribute__((noinline)) uGUIMail::~uGUIMail() {
    DDON_STUB("uGUIMail::~uGUIMail")
    /* stub */
}

void uGUIMail::createProperty(MtPropertyList& s) {
    this->uGUIsMenuBase::createProperty(s);
}

bool uGUIMail::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_MAIL_GUI"), 129u, 1419397718l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_MAIL_BOX_GMD", 0u);
}

__attribute__((weak)) void uGUIMail::setup() {
    DDON_STUB("uGUIMail::setup")
    /* stub */
}

void uGUIMail::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIMail::move() {
    this->uGUIsMenuBase::move();
}

__attribute__((weak)) MtVector4 uGUIMail::getDetailSetPosition() {
    DDON_STUB("uGUIMail::getDetailSetPosition")
    __builtin_unreachable();
}

f32 uGUIMail::getMailIconFrame(CMailInfo* pMailInfo) {
    bool t0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isUnOpenedMail(pMailInfo);
    bool t1 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isUnGetItemMail(pMailInfo);
    if (t0) {
        if (!t1) {
            return 0.0f;
        } else {
            return 2.0f;
        }
    } else {
        if (!t1) {
            return 1.0f;
        } else {
            return 3.0f;
        }
    }
}

s32 uGUIMail::getSMenuCursorX() {
    return 0;
}

__attribute__((weak)) s32 uGUIMail::getSMenuCursorY() {
    DDON_STUB("uGUIMail::getSMenuCursorY")
    return {};
}

s32 uGUIMail::getSMenuTab() {
    if (mpTabCtrl != nullptr) {
        return mpTabCtrl->getCurrentPos();
    } else {
        return 0;
    }
}

__attribute__((weak)) void uGUIMail::setupListInfo() {
    DDON_STUB("uGUIMail::setupListInfo")
    /* stub */
}

__attribute__((weak)) void uGUIMail::initScrollList(uGUIMail::cTabData* pTabData) {
    DDON_STUB("uGUIMail::initScrollList")
    /* stub */
}

__attribute__((weak)) void uGUIMail::updateScrollList(uGUIMail::cTabData* pTabData, bool oldPosUse) {
    DDON_STUB("uGUIMail::updateScrollList")
    /* stub */
}

__attribute__((weak)) void uGUIMail::updateScrollListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIMail::updateScrollListDisp")
    /* stub */
}

__attribute__((weak)) void uGUIMail::updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem) {
}

__attribute__((weak)) bool uGUIMail::evScrollMsgEvent(cControl::Message* msg) {
    DDON_STUB("uGUIMail::evScrollMsgEvent")
    return {};
}

void uGUIMail::updateInit() {
    setCurrentTab(0);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMail::updateWait);
}

__attribute__((weak)) void uGUIMail::updateWait() {
    DDON_STUB("uGUIMail::updateWait")
    /* stub */
}

void uGUIMail::updateExit() {
    end();
}

__attribute__((weak)) void uGUIMail::moveInput() {
    DDON_STUB("uGUIMail::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIMail::moveEvent() {
    DDON_STUB("uGUIMail::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIMail::setCurrentTab(s32 tabNo) {
    DDON_STUB("uGUIMail::setCurrentTab")
    /* stub */
}

__attribute__((weak)) void uGUIMail::setControlPoint(s32 point) {
    DDON_STUB("uGUIMail::setControlPoint")
    /* stub */
}

void uGUIMail::setBtnCursor(s32 point) {
    (&mBtn)->setFocus(false);
    mReceiveBtn.uGUIBase::cReferenceUIIconButton::setFocus(false);
    mReceiveBtn.setSelected(false);
    if (point == 1) {
        (&mBtn)->setFocus(true);
        static_cast<sGUIExt*>(sGUI::getInstance())->clearPointerGuideMsg();
    } else {
        if (point == 0) {
            mReceiveBtn.uGUIBase::cReferenceUIIconButton::setFocus(true);
            mReceiveBtn.setSelected(true);
            sGUI* t0 = sGUI::getInstance();
            static_cast<sGUIExt*>(t0)->setPointerGuideMsg(static_cast<sGUIExt*>(t0)->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 23u), 0u, false, nKeyCustom::KEY_CUSTOM_NOTHING);
        }
    }
}

u32 uGUIMail::evCtrlDecide(cControl::Message* msg) {
    if (sMenu::getInstance()->mMenuMail.mMenuRno[0] == 4) {
        setInputEvent(4u);
    } else {
        msg->changeSE = 0;
    }
    return 0;
}

__attribute__((weak)) u32 uGUIMail::evCtrlCancel(cControl::Message* msg) {
    DDON_STUB("uGUIMail::evCtrlCancel")
    return {};
}

u32 uGUIMail::evCtrlStart(cControl::Message* msg) {
    if (sMenu::getInstance()->mMenuMail.mMenuRno[0] == 4) {
        setInputEvent(5u);
    }
    return 0;
}

u32 uGUIMail::evCtrlChkout(cControl::Message* msg) {
    if (sMenu::getInstance()->mMenuMail.mMenuRno[0] == 4) {
        setInputEvent(6u);
    }
    return 0;
}

u32 uGUIMail::evCtrlTopbtn(cControl::Message* msg) {
    if (sMenu::getInstance()->mMenuMail.mMenuRno[0] == 4) {
        if (mpTabCtrl != nullptr) {
            if (static_cast<unsigned int>(mpTabCtrl->getCurrentPos() - 1) <= 1) {
                setInputEvent(7u);
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 uGUIMail::evCtrlAdjCursor(cControl::Message* msg) {
    DDON_STUB("uGUIMail::evCtrlAdjCursor")
    return {};
}

u32 uGUIMail::evCtrlAdjTab(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

u32 uGUIMail::evCtrlAdjBtn(cControl::Message* msg) {
    setInputEvent(70u);
    return 0;
}

__attribute__((weak)) u32 uGUIMail::evCtrlBtnClick(cControl::Message* msg) {
    DDON_STUB("uGUIMail::evCtrlBtnClick")
    return {};
}

__attribute__((weak)) MtObject* uGUIMail::MyDTI::newInstance() const {
    DDON_STUB("uGUIMail::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIMail::cTabData::getDTI() const {
    return uGUIMail::cTabData::DTI;
}

uGUIMail::cTabData::cTabData() {
    DDON_STUB("uGUIMail::cTabData::cTabData")
    /* stub */
}

uGUIMail::cTabData::~cTabData() {
}

__attribute__((weak)) void uGUIMail::cTabData::init(uGUIMail* pOwner, uGUIMail::MAIL_TAB tabType) {
    DDON_STUB("uGUIMail::cTabData::init")
    /* stub */
}

__attribute__((weak)) void uGUIMail::cTabData::setData(uGUIMail::cMailData* pMailData, u32 cursorIndex) {
    DDON_STUB("uGUIMail::cTabData::setData")
    /* stub */
}

inline uGUIMail::cTabData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMail::cTabData::MyDTI uGUIMail::cTabData::DTI("uGUIMail::cTabData", &::MtObject::DTI, 2176ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMail::cTabData::MyDTI::newInstance() const {
    DDON_STUB("uGUIMail::cTabData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIMail::cMailData::getDTI() const {
    return uGUIMail::cMailData::DTI;
}

inline uGUIMail::cMailData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMail::cMailData::MyDTI uGUIMail::cMailData::DTI("uGUIMail::cMailData", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* uGUIMail::cMailData::MyDTI::newInstance() const {
    return new (16u) uGUIMail::cMailData;
}

const MtDTI& uGUIMail::cScrollDispList::getDTI() const {
    return uGUIMail::cScrollDispList::DTI;
}

inline uGUIMail::cScrollDispList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMail::cScrollDispList::MyDTI uGUIMail::cScrollDispList::DTI("uGUIMail::cScrollDispList", &::uGUIBase::cScrollListItemBase::DTI, 104ul, 0u, 0u);

MtObject* uGUIMail::cScrollDispList::MyDTI::newInstance() const {
    return new (16u) uGUIMail::cScrollDispList;
}

const MtDTI& uGUIMail::cScrollItemList::getDTI() const {
    return uGUIMail::cScrollItemList::DTI;
}

inline uGUIMail::cScrollItemList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMail::cScrollItemList::MyDTI uGUIMail::cScrollItemList::DTI("uGUIMail::cScrollItemList", &::uGUIBase::cScrollListInfoBase::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMail::cScrollItemList::MyDTI::newInstance() const {
    DDON_STUB("uGUIMail::cScrollItemList::MyDTI::newInstance")
    return nullptr;
}

