// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIMenuAreaInfo.h"
#include "Protocol/PacketData/AreaMaster.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cCharacterData.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uGUI.h"
#include "uGUIAreaMaster.h"
#include "uGUIBase.h"
#include "uGUIPopCmd01.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIMenuAreaInfo::getDTI() const {
    return uGUIMenuAreaInfo::DTI;
}

void* uGUIMenuAreaInfo::operator new(size_t sz, u32 align) {
    return uGUIMenuAreaInfo::getAllocator()->memAlloc(sz, align, uGUIMenuAreaInfo::DTI.getID());
}

__attribute__((noinline)) uGUIMenuAreaInfo::~uGUIMenuAreaInfo() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIMenuAreaInfo::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIMenuAreaInfo::loadResource() {
    if (mpGUIRes == nullptr) {
        if ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_AREADIARY_GUI"), 129u, 1473927593l))) != nullptr) {
            if (loadGMDarc(getArcTag(0u), "RES_ID_MENUAREAINFO_RES_GMD", 0u)) {
                return loadGMDarc(getArcTag(0u), "RES_ID_POPTOP_SEL_RES_GMD", 1u);
            }
        }
    } else {
        if (loadGMDarc(getArcTag(0u), "RES_ID_MENUAREAINFO_RES_GMD", 0u)) {
            return loadGMDarc(getArcTag(0u), "RES_ID_POPTOP_SEL_RES_GMD", 1u);
        }
    }
    return false;
}

__attribute__((weak)) void uGUIMenuAreaInfo::setup() {
    DDON_STUB("uGUIMenuAreaInfo::setup")
    /* stub */
}

void uGUIMenuAreaInfo::kill() {
    if (mpGUIPopCmd != nullptr) {
        mpGUIPopCmd->kill();
        mpGUIPopCmd = nullptr;
    }
    if (mpGUIAreaMaster != nullptr) {
        mpGUIAreaMaster->kill();
        mpGUIAreaMaster = nullptr;
    }
    this->uGUIBase::kill();
}

void uGUIMenuAreaInfo::updatePtr() {
    if (mpGUIPopCmd != nullptr) {
        if (!mpGUIPopCmd->isEnable()) {
            mpGUIPopCmd = nullptr;
        }
    }
    if (mpGUIAreaMaster == nullptr) {
        return;
    }
    if (mpGUIAreaMaster->isEnable()) {
        return;
    }
    mpGUIAreaMaster = nullptr;
}

void uGUIMenuAreaInfo::updateWait() {
    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
    mGuide.uGUIBase::cReferenceUIBtnGuide::update();
    if ((mFlowId & 0xFFFFFFFEu) == 2) {
        mScrollList.uGUIBase::cScrollList::update(getDeltaTime());
    }
    if ((mFlowId - 4u) <= 2u) {
        updateAreaMaster();
    } else {
        if (mFlowId == 3) {
            if (mpGUIPopCmd == nullptr) {
                switch (mCmdResult) {
                    case 0:
                    {
                        setFlowId(2u);
                        break;
                    }
                    case 1:
                    {
                        setFlowId(4u);
                        break;
                    }
                    case 2:
                    {
                        setFlowId(5u);
                        break;
                    }
                    case 3:
                    {
                        setFlowId(6u);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
        }
    }
}

void uGUIMenuAreaInfo::updateExit() {
    end();
}

__attribute__((weak)) void uGUIMenuAreaInfo::setFlowId(u32 flow_id) {
    DDON_STUB("uGUIMenuAreaInfo::setFlowId")
    /* stub */
}

__attribute__((weak)) void uGUIMenuAreaInfo::setupList() {
    DDON_STUB("uGUIMenuAreaInfo::setupList")
    /* stub */
}

void uGUIMenuAreaInfo::setupSectionMessage() {
    cGUIObjMessage* t0 = mpObjMsgSection02;
    if (mListMode == 1) {
        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 8u), 0u, false);
        cGUIObjMessage* t1 = mpObjMsgSection03;
        setObjectMessage(static_cast<cGUIObject*>(t1), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 9u), 0u, false);
    } else {
        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 5u), 0u, false);
        cGUIObjMessage* t2 = mpObjMsgSection03;
        setObjectMessage(static_cast<cGUIObject*>(t2), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 6u), 0u, false);
    }
}

__attribute__((weak)) void uGUIMenuAreaInfo::setupSubMenu() {
    DDON_STUB("uGUIMenuAreaInfo::setupSubMenu")
    /* stub */
}

__attribute__((weak)) void uGUIMenuAreaInfo::setupAreaMaster(u32 mode) {
    DDON_STUB("uGUIMenuAreaInfo::setupAreaMaster")
    /* stub */
}

__attribute__((weak)) void uGUIMenuAreaInfo::updateAreaMaster() {
    if (mpGUIAreaMaster != nullptr) {
        if (mpGUIAreaMaster->mResult == RESULT_EXIT) {
            mpGUIAreaMaster->mEndType = 0;
            mpGUIAreaMaster->end();
            mpGUIAreaMaster = nullptr;
            static_cast<sGUIExt*>(sGUI::getInstance())->reqWindowActive(static_cast<uGUIBase*>(this));
            if (mFlowId == 6) {
                mRequestFlag = mRequestFlag | 1u;
                mFlowIdNext = 2;
                setFlowId(1u);
                if ((mRequestFlag & 1u) != 0) {
                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIMenuAreaInfo::requestAreaBaseInfoList);
                        mServerCommandStatusRsv = 373;
                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIMenuAreaInfo::callbackAreaBaseInfoList);
                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                    } else {
                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIMenuAreaInfo::requestAreaBaseInfoList);
                        mServerCommandStatus = 373;
                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIMenuAreaInfo::callbackAreaBaseInfoList);
                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                        mServerRno = 0;
                        mServerResult = 0;
                    }
                } else {
                    setFlowId(mFlowIdNext);
                }
            } else {
                setFlowId(2u);
            }
        }
    } else {
        mpGUIAreaMaster = nullptr;
        static_cast<sGUIExt*>(sGUI::getInstance())->reqWindowActive(static_cast<uGUIBase*>(this));
        if (mFlowId == 6) {
            mRequestFlag = mRequestFlag | 1u;
            mFlowIdNext = 2;
            setFlowId(1u);
            if ((mRequestFlag & 1u) != 0) {
                if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                    mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIMenuAreaInfo::requestAreaBaseInfoList);
                    mServerCommandStatusRsv = 373;
                    mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIMenuAreaInfo::callbackAreaBaseInfoList);
                    mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                } else {
                    mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIMenuAreaInfo::requestAreaBaseInfoList);
                    mServerCommandStatus = 373;
                    mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIMenuAreaInfo::callbackAreaBaseInfoList);
                    mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                    mServerRno = 0;
                    mServerResult = 0;
                }
            } else {
                setFlowId(mFlowIdNext);
            }
        } else {
            setFlowId(2u);
        }
    }
}

bool uGUIMenuAreaInfo::requestAreaBaseInfoList() {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getAreaPointList();
}

__attribute__((weak)) void uGUIMenuAreaInfo::callbackAreaBaseInfoList() {
    DDON_STUB("uGUIMenuAreaInfo::callbackAreaBaseInfoList")
    /* stub */
}

void uGUIMenuAreaInfo::moveInput() {
    if (mFlowId != 2) {
        return;
    }
    mCloseBtn.execute();
    mScrollList.executeCtrl();
    if (mpCtrl == nullptr) {
        return;
    }
    mpCtrl->execute();
}

__attribute__((weak)) void uGUIMenuAreaInfo::moveEvent() {
    DDON_STUB("uGUIMenuAreaInfo::moveEvent")
    /* stub */
}

void uGUIMenuAreaInfo::evEnd() {
    setFlowId(7u);
}

__attribute__((weak)) u32 uGUIMenuAreaInfo::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIMenuAreaInfo::evCtrlDecide")
    return {};
}

u32 uGUIMenuAreaInfo::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(67u);
    return 1;
}

u32 uGUIMenuAreaInfo::evCtrlClose(cControl::Message* msg) {
    setInputEvent(68u);
    return 1;
}

u32 uGUIMenuAreaInfo::evCtrlChangeList(cControl::Message* msg) {
    setInputEvent(69u);
    return 1;
}

__attribute__((weak)) bool uGUIMenuAreaInfo::evCtrlScrlMouseClick(cControl::Message* msg) {
    DDON_STUB("uGUIMenuAreaInfo::evCtrlScrlMouseClick")
    return {};
}

u32 uGUIMenuAreaInfo::callbackCmd00(MtObject* pCaller, MtObject* pDummy) {
    mCmdResult = 1;
    return 0;
}

u32 uGUIMenuAreaInfo::callbackCmd01(MtObject* pCaller, MtObject* pDummy) {
    mCmdResult = 2;
    return 0;
}

u32 uGUIMenuAreaInfo::callbackCmd02(MtObject* pCaller, MtObject* pDummy) {
    mCmdResult = 3;
    return 0;
}

__attribute__((weak)) void uGUIMenuAreaInfo::initScrollList() {
    DDON_STUB("uGUIMenuAreaInfo::initScrollList")
    /* stub */
}

__attribute__((weak)) void uGUIMenuAreaInfo::updateScrollListDisp(uGUIBase::cScrollListItemBase* pListItem, uGUIBase::cScrollListInfoBase* pListInfo, u32 Index) {
    DDON_STUB("uGUIMenuAreaInfo::updateScrollListDisp")
    /* stub */
}

__attribute__((weak)) void uGUIMenuAreaInfo::updateScrollListHide(uGUIBase::cScrollListItemBase* pListItem) {
    DDON_STUB("uGUIMenuAreaInfo::updateScrollListHide")
    /* stub */
}

__attribute__((weak)) MtObject* uGUIMenuAreaInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIMenuAreaInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIMenuAreaInfo::cListItem::getDTI() const {
    return uGUIMenuAreaInfo::cListItem::DTI;
}

inline uGUIMenuAreaInfo::cListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMenuAreaInfo::cListItem::MyDTI uGUIMenuAreaInfo::cListItem::DTI("uGUIMenuAreaInfo::cListItem", &::uGUIBase::cScrollListItemBase::DTI, 232ul, 0u, 0u);

MtObject* uGUIMenuAreaInfo::cListItem::MyDTI::newInstance() const {
    return new (16u) uGUIMenuAreaInfo::cListItem;
}

const MtDTI& uGUIMenuAreaInfo::cHeaderItem::getDTI() const {
    return uGUIMenuAreaInfo::cHeaderItem::DTI;
}

inline uGUIMenuAreaInfo::cHeaderItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMenuAreaInfo::cHeaderItem::MyDTI uGUIMenuAreaInfo::cHeaderItem::DTI("uGUIMenuAreaInfo::cHeaderItem", &::uGUIBase::cScrollListItemBase::DTI, 96ul, 0u, 0u);

MtObject* uGUIMenuAreaInfo::cHeaderItem::MyDTI::newInstance() const {
    return new (16u) uGUIMenuAreaInfo::cHeaderItem;
}

const MtDTI& uGUIMenuAreaInfo::cListInfo::getDTI() const {
    return uGUIMenuAreaInfo::cListInfo::DTI;
}

inline uGUIMenuAreaInfo::cListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMenuAreaInfo::cListInfo::MyDTI uGUIMenuAreaInfo::cListInfo::DTI("uGUIMenuAreaInfo::cListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMenuAreaInfo::cListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIMenuAreaInfo::cListInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIMenuAreaInfo::cHeaderInfo::getDTI() const {
    return uGUIMenuAreaInfo::cHeaderInfo::DTI;
}

inline uGUIMenuAreaInfo::cHeaderInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMenuAreaInfo::cHeaderInfo::MyDTI uGUIMenuAreaInfo::cHeaderInfo::DTI("uGUIMenuAreaInfo::cHeaderInfo", &::uGUIBase::cScrollListInfoBase::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMenuAreaInfo::cHeaderInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIMenuAreaInfo::cHeaderInfo::MyDTI::newInstance")
    return nullptr;
}

