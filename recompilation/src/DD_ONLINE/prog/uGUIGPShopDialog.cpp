// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIGPShopDialog.h"
#include "Protocol/PacketData/GP.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "Protocol/UserSession/S2C.h"
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
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sKeyboardInterface.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIGPShop.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIGPShopDialog::getDTI() const {
    return uGUIGPShopDialog::DTI;
}

void* uGUIGPShopDialog::operator new(size_t sz, u32 align) {
    return uGUIGPShopDialog::getAllocator()->memAlloc(sz, align, uGUIGPShopDialog::DTI.getID());
}

__attribute__((noinline)) uGUIGPShopDialog::~uGUIGPShopDialog() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->releaseGPPeriodPacket();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpGPShop == nullptr) {
        return;
    }
    mpGPShop->kill();
    mpGPShop = nullptr;
}

bool uGUIGPShopDialog::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_GPSHOP_DIALOG_GUI"), 129u, 1428652135l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_GPSHOPDIALOG_RES_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIGPShopDialog::updatePtr() {
    if (mpGPShop == nullptr) {
        return;
    }
    if (mpGPShop->isEnable()) {
        return;
    }
    mpGPShop = nullptr;
}

void uGUIGPShopDialog::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(11u), true);
    setPlay(true);
    mGuideCode.setup(static_cast<uGUIBase*>(this), getInstance(286u, false), 0.0f);
    mGuideDialog.setup(static_cast<uGUIBase*>(this), getInstance(287u, false), 0.0f);
    initType();
}

void uGUIGPShopDialog::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpGPShop == nullptr) {
        return;
    }
    mpGPShop->kill();
    mpGPShop = nullptr;
}

void uGUIGPShopDialog::adjustScale() {
    this->uGUIBase::adjustScale();
    if (mpGPShop != nullptr) {
        return;
    }
    if (!static_cast<sGUIExt*>(sGUI::getInstance())->isExecBrowser()) {
        return;
    }
    f32 scale = getScaleForDefaultResolution(1.0f);
    static_cast<sGUIExt*>(sGUI::getInstance())->setBrowserPos(580.0f * scale, 114.0f * scale);
}

__attribute__((weak)) void uGUIGPShopDialog::moveInput() {
    DDON_STUB("uGUIGPShopDialog::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::moveEvent() {
    DDON_STUB("uGUIGPShopDialog::moveEvent")
    /* stub */
}

void uGUIGPShopDialog::updateWait() {
    mClose.uGUIBase::cReferenceUICloseBtn::update();
}

void uGUIGPShopDialog::updateLimit() {
    mClose.uGUIBase::cReferenceUICloseBtn::update();
    MtVector2 frame64(getObjectScreenPos(static_cast<cGUIObject*>(mpLimitExplainCursorObj), mPos));
    u32 t1 = getBasePointerPriority();
    sGUI* t2 = sGUI::getInstance();
    static_cast<sGUIExt*>(t2)->setPointerPosReq(static_cast<uGUIBase*>(this), frame64, t1, static_cast<sGUIExt*>(t2)->getPrioGrpFromIssueIdx(mPrioIssueIdx), static_cast<const MtVector2*>(nullptr));
    mLimitScrollbar.uGUIBase::cScrollList::update(getDeltaTime());
}

void uGUIGPShopDialog::updateHistory() {
    mClose.uGUIBase::cReferenceUICloseBtn::update();
    mHistoryScrollbar.uGUIBase::cScrollList::update(getDeltaTime());
}

void uGUIGPShopDialog::updateGoldStone() {
    mClose.uGUIBase::cReferenceUICloseBtn::update();
    MtVector2 frame64(getObjectScreenPos(static_cast<cGUIObject*>(mpGSBuyButtonCursorObj), mPos));
    u32 t1 = getBasePointerPriority();
    sGUI* t2 = sGUI::getInstance();
    static_cast<sGUIExt*>(t2)->setPointerPosReq(static_cast<uGUIBase*>(this), frame64, t1, static_cast<sGUIExt*>(t2)->getPrioGrpFromIssueIdx(mPrioIssueIdx), static_cast<const MtVector2*>(nullptr));
}

__attribute__((weak)) void uGUIGPShopDialog::updateEventCode() {
    DDON_STUB("uGUIGPShopDialog::updateEventCode")
    /* stub */
}

u32 uGUIGPShopDialog::evCtrlCancel(cControl::Message* pMsg) {
    if (mpCtrl != nullptr) {
        mpCtrl->setFocus(false);
    }
    setInputEvent(66u);
    return 1;
}

u32 uGUIGPShopDialog::evCtrlTabLR(cControl::Message* pMsg) {
    setInputEvent(67u);
    return 1;
}

u32 uGUIGPShopDialog::evCtrlGSDecide(cControl::Message* pMsg) {
    if (mIsOnlineShopOpen) {
        setInputEvent(72u);
    } else {
        setInputEvent(71u);
    }
    return 1;
}

u32 uGUIGPShopDialog::evCtrlLimitDecide(cControl::Message* pMsg) {
    setInputEvent(68u);
    return 1;
}

u32 uGUIGPShopDialog::evCtrlLimitCursorUD(cControl::Message* pMsg) {
    if (mLimitListNum > 3) {
        if (pMsg != nullptr) {
            if (pMsg->reason == nGUIExt::TRG_DOWN) {
                mScrollDir = 1;
                setInputEvent(69u);
                return 1;
            } else {
                if (pMsg->reason == nGUIExt::BTN_START) {
                    mScrollDir = -1;
                    setInputEvent(69u);
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

u32 uGUIGPShopDialog::evCtrlHistoryCursorUD(cControl::Message* pMsg) {
    if (mHistoryListNum > 8) {
        if (pMsg != nullptr) {
            if (pMsg->reason == nGUIExt::TRG_DOWN) {
                mScrollDir = 1;
                setInputEvent(70u);
                return 1;
            } else {
                if (pMsg->reason == nGUIExt::BTN_START) {
                    mScrollDir = -1;
                    setInputEvent(70u);
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

u32 uGUIGPShopDialog::evCtrlEventCodeCancel(cControl::Message* pMsg) {
    if (mpCtrl != nullptr) {
        mpCtrl->setFocus(false);
    }
    setInputEvent(66u);
    return 1;
}

__attribute__((weak)) u32 uGUIGPShopDialog::evCtrlEventCodeDecide(cControl::Message* pMsg) {
    DDON_STUB("uGUIGPShopDialog::evCtrlEventCodeDecide")
    return {};
}

u32 uGUIGPShopDialog::evCtrlEventCodeCursorLR(cControl::Message* pMsg) {
    setInputEvent(73u);
    return 1;
}

__attribute__((weak)) u32 uGUIGPShopDialog::evCtrlEventCodeCursorUD(cControl::Message* pMsg) {
    DDON_STUB("uGUIGPShopDialog::evCtrlEventCodeCursorUD")
    return {};
}

__attribute__((weak)) u32 uGUIGPShopDialog::evCtrlEventCodeMouseClick(cControl::Message* pMsg) {
    DDON_STUB("uGUIGPShopDialog::evCtrlEventCodeMouseClick")
    return {};
}

u32 uGUIGPShopDialog::evCtrlEventCodeNext(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        setInputEvent(78u);
    }
    return 0;
}

__attribute__((weak)) void uGUIGPShopDialog::initType() {
    DDON_STUB("uGUIGPShopDialog::initType")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::initConfirmCommon() {
    DDON_STUB("uGUIGPShopDialog::initConfirmCommon")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::initGoldStone() {
    DDON_STUB("uGUIGPShopDialog::initGoldStone")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::initLimit() {
    DDON_STUB("uGUIGPShopDialog::initLimit")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::initHistory() {
    DDON_STUB("uGUIGPShopDialog::initHistory")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::initEventCode() {
    DDON_STUB("uGUIGPShopDialog::initEventCode")
    /* stub */
}

bool uGUIGPShopDialog::initConfirmRequestServer() {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGPPeriod();
}

bool uGUIGPShopDialog::limitRequestServer() {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGPPeriod();
}

bool uGUIGPShopDialog::historyRequestServer() {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGPDetailHistory(true);
}

void uGUIGPShopDialog::initConfirmCallBack() {
    mIsGoldStoneRequest = true;
    setupGoldStone();
}

void uGUIGPShopDialog::limitCallBack() {
    mIsLimitRequest = true;
    setupLimit();
}

void uGUIGPShopDialog::historyCallBack() {
    mIsHistoryRequest = true;
    setupHistory();
}

__attribute__((weak)) void uGUIGPShopDialog::setupGoldStone() {
    DDON_STUB("uGUIGPShopDialog::setupGoldStone")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::setupLimit() {
    DDON_STUB("uGUIGPShopDialog::setupLimit")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::setupHistory() {
    DDON_STUB("uGUIGPShopDialog::setupHistory")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::updateEventCodeLine() {
    DDON_STUB("uGUIGPShopDialog::updateEventCodeLine")
    /* stub */
}

__attribute__((weak)) void uGUIGPShopDialog::updateScrollLimitListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIGPShopDialog::updateScrollLimitListDisp")
    /* stub */
}

void uGUIGPShopDialog::updateScrollLimitListHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem == nullptr) {
        return;
    }
    cScrollLimitDispList* pdisp = static_cast<cScrollLimitDispList*>(pDispItem);
    if (pdisp->mpInst == nullptr) {
        return;
    }
    pdisp->mpInst->setVisible(false);
}

__attribute__((weak)) void uGUIGPShopDialog::updateScrollHistoryListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIGPShopDialog::updateScrollHistoryListDisp")
    /* stub */
}

void uGUIGPShopDialog::updateScrollHistoryListHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem == nullptr) {
        return;
    }
    cScrollHistoryDispList* pdisp = static_cast<cScrollHistoryDispList*>(pDispItem);
    if (pdisp->mpInst == nullptr) {
        return;
    }
    pdisp->mpInst->setVisible(false);
}

void uGUIGPShopDialog::setType(u32 Type) {
    switch (Type) {
        case 0:
        {
            if (mType == 4) {
                setPlayingFlow(getFlow(43u), true);
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateEventCode);
                updateEventCodeLine();
                play(0.0f);
                mType = Type;
            }
            break;
        }
        case 1:
        {
            if (mType != 0) {
                setPlayingFlow(getFlow(44u), true);
                if (mpGSConfirm == nullptr) {
                    if (mpGSCaution == nullptr) {
                        if (mpGSCautionTxt == nullptr) {
                            if (mpCaution == nullptr) {
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            } else {
                                mpCaution->setVisible(false);
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            }
                        } else {
                            mpGSCautionTxt->setVisible(false);
                            if (mpCaution == nullptr) {
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            } else {
                                mpCaution->setVisible(false);
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        mpGSCaution->setVisible(false);
                        if (mpGSCautionTxt == nullptr) {
                            if (mpCaution == nullptr) {
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            } else {
                                mpCaution->setVisible(false);
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            }
                        } else {
                            mpGSCautionTxt->setVisible(false);
                            if (mpCaution == nullptr) {
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            } else {
                                mpCaution->setVisible(false);
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    mpGSConfirm->setSequenceId(4u);
                    if (mpGSCaution == nullptr) {
                        if (mpGSCautionTxt == nullptr) {
                            if (mpCaution == nullptr) {
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            } else {
                                mpCaution->setVisible(false);
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            }
                        } else {
                            mpGSCautionTxt->setVisible(false);
                            if (mpCaution == nullptr) {
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            } else {
                                mpCaution->setVisible(false);
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        mpGSCaution->setVisible(false);
                        if (mpGSCautionTxt == nullptr) {
                            if (mpCaution == nullptr) {
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            } else {
                                mpCaution->setVisible(false);
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            }
                        } else {
                            mpGSCautionTxt->setVisible(false);
                            if (mpCaution == nullptr) {
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            } else {
                                mpCaution->setVisible(false);
                                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateGoldStone);
                                if (mIsGoldStoneRequest) {
                                    play(0.0f);
                                    mType = Type;
                                    if (Type != 0) {
                                        mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                        mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                    }
                                } else {
                                    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                        mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatusRsv = 206;
                                        mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    } else {
                                        mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::initConfirmRequestServer);
                                        mServerCommandStatus = 206;
                                        mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::initConfirmCallBack);
                                        mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                        mServerRno = 0;
                                        mServerResult = 0;
                                        play(0.0f);
                                        mType = Type;
                                        if (Type != 0) {
                                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            break;
        }
        case 2:
        {
            if (mType != 0) {
                setPlayingFlow(getFlow(45u), true);
                if (mpLimitExplain == nullptr) {
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateLimit);
                    if (mLimitScrollbar.mpVCtrl == nullptr) {
                        if (mIsLimitRequest) {
                            play(0.0f);
                            mType = Type;
                            if (Type != 0) {
                                mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                            }
                        } else {
                            if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::limitRequestServer);
                                mServerCommandStatusRsv = 206;
                                mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::limitCallBack);
                                mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                play(0.0f);
                                mType = Type;
                                if (Type != 0) {
                                    mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                }
                            } else {
                                mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::limitRequestServer);
                                mServerCommandStatus = 206;
                                mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::limitCallBack);
                                mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                mServerRno = 0;
                                mServerResult = 0;
                                play(0.0f);
                                mType = Type;
                                if (Type != 0) {
                                    mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                }
                            }
                        }
                    } else {
                        mLimitScrollbar.mpVCtrl->setCurrentPos(0, false);
                        if (mIsLimitRequest) {
                            play(0.0f);
                            mType = Type;
                            if (Type != 0) {
                                mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                            }
                        } else {
                            if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::limitRequestServer);
                                mServerCommandStatusRsv = 206;
                                mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::limitCallBack);
                                mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                play(0.0f);
                                mType = Type;
                                if (Type != 0) {
                                    mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                }
                            } else {
                                mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::limitRequestServer);
                                mServerCommandStatus = 206;
                                mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::limitCallBack);
                                mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                mServerRno = 0;
                                mServerResult = 0;
                                play(0.0f);
                                mType = Type;
                                if (Type != 0) {
                                    mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                }
                            }
                        }
                    }
                } else {
                    mpLimitExplain->setSequenceId(4u);
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateLimit);
                    if (mLimitScrollbar.mpVCtrl == nullptr) {
                        if (mIsLimitRequest) {
                            play(0.0f);
                            mType = Type;
                            if (Type != 0) {
                                mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                            }
                        } else {
                            if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::limitRequestServer);
                                mServerCommandStatusRsv = 206;
                                mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::limitCallBack);
                                mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                play(0.0f);
                                mType = Type;
                                if (Type != 0) {
                                    mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                }
                            } else {
                                mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::limitRequestServer);
                                mServerCommandStatus = 206;
                                mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::limitCallBack);
                                mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                mServerRno = 0;
                                mServerResult = 0;
                                play(0.0f);
                                mType = Type;
                                if (Type != 0) {
                                    mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                }
                            }
                        }
                    } else {
                        mLimitScrollbar.mpVCtrl->setCurrentPos(0, false);
                        if (mIsLimitRequest) {
                            play(0.0f);
                            mType = Type;
                            if (Type != 0) {
                                mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                            }
                        } else {
                            if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                                mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::limitRequestServer);
                                mServerCommandStatusRsv = 206;
                                mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::limitCallBack);
                                mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                play(0.0f);
                                mType = Type;
                                if (Type != 0) {
                                    mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                }
                            } else {
                                mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::limitRequestServer);
                                mServerCommandStatus = 206;
                                mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::limitCallBack);
                                mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                                mServerRno = 0;
                                mServerResult = 0;
                                play(0.0f);
                                mType = Type;
                                if (Type != 0) {
                                    mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                    mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                                }
                            }
                        }
                    }
                }
            }
            break;
        }
        case 3:
        {
            if (mType != 0) {
                setPlayingFlow(getFlow(48u), true);
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateHistory);
                if (mHistoryScrollbar.mpVCtrl == nullptr) {
                    if (mIsHistoryRequest) {
                        play(0.0f);
                        mType = Type;
                        if (Type != 0) {
                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                        }
                    } else {
                        if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                            mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::historyRequestServer);
                            mServerCommandStatusRsv = 205;
                            mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::historyCallBack);
                            mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                            play(0.0f);
                            mType = Type;
                            if (Type != 0) {
                                mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                            }
                        } else {
                            mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::historyRequestServer);
                            mServerCommandStatus = 205;
                            mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::historyCallBack);
                            mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                            mServerRno = 0;
                            mServerResult = 0;
                            play(0.0f);
                            mType = Type;
                            if (Type != 0) {
                                mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                            }
                        }
                    }
                } else {
                    mHistoryScrollbar.mpVCtrl->setCurrentPos(0, false);
                    if (mIsHistoryRequest) {
                        play(0.0f);
                        mType = Type;
                        if (Type != 0) {
                            mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                            mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                            mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                        }
                    } else {
                        if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                            mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::historyRequestServer);
                            mServerCommandStatusRsv = 205;
                            mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::historyCallBack);
                            mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                            play(0.0f);
                            mType = Type;
                            if (Type != 0) {
                                mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                            }
                        } else {
                            mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIGPShopDialog::historyRequestServer);
                            mServerCommandStatus = 205;
                            mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIGPShopDialog::historyCallBack);
                            mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                            mServerRno = 0;
                            mServerResult = 0;
                            play(0.0f);
                            mType = Type;
                            if (Type != 0) {
                                mTab.uGUIBase::cReferenceUITab::setFocus(0u, (Type & 0xFFFFFFFEu) != 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(1u, Type == 2, true);
                                mTab.uGUIBase::cReferenceUITab::setFocus(2u, Type == 3, true);
                            }
                        }
                    }
                }
            }
            break;
        }
        default:
        {
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGPShopDialog::updateWait);
            break;
        }
    }
}

__attribute__((weak)) void uGUIGPShopDialog::startGPShop() {
    DDON_STUB("uGUIGPShopDialog::startGPShop")
    /* stub */
}

__attribute__((weak)) bool uGUIGPShopDialog::initEventCodeSend() {
    DDON_STUB("uGUIGPShopDialog::initEventCodeSend")
    return {};
}

void uGUIGPShopDialog::initEventCodeSendCallBack() {
    mEndReason = END_REASON_START_BTN;
    end();
}

bool uGUIGPShopDialog::onKeyEvent(const nInputTextKeyboardHook::Keycode& keycode) {
    if (sKeyboardInterface::getInstance()->isSoftwareKeyboard()) {
        return false;
    } else {
        return this->uGUIBase::onKeyEvent(keycode);
    }
}

__attribute__((weak)) MtObject* uGUIGPShopDialog::MyDTI::newInstance() const {
    DDON_STUB("uGUIGPShopDialog::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIGPShopDialog::cScrollLimitDispList::getDTI() const {
    return uGUIGPShopDialog::cScrollLimitDispList::DTI;
}

inline uGUIGPShopDialog::cScrollLimitDispList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIGPShopDialog::cScrollLimitDispList::MyDTI uGUIGPShopDialog::cScrollLimitDispList::DTI("uGUIGPShopDialog::cScrollLimitDispList", &::uGUIBase::cScrollListItemBase::DTI, 120ul, 0u, 0u);

MtObject* uGUIGPShopDialog::cScrollLimitDispList::MyDTI::newInstance() const {
    return new (16u) uGUIGPShopDialog::cScrollLimitDispList;
}

const MtDTI& uGUIGPShopDialog::cScrollHistoryDispList::getDTI() const {
    return uGUIGPShopDialog::cScrollHistoryDispList::DTI;
}

inline uGUIGPShopDialog::cScrollHistoryDispList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIGPShopDialog::cScrollHistoryDispList::MyDTI uGUIGPShopDialog::cScrollHistoryDispList::DTI("uGUIGPShopDialog::cScrollHistoryDispList", &::uGUIBase::cScrollListItemBase::DTI, 128ul, 0u, 0u);

MtObject* uGUIGPShopDialog::cScrollHistoryDispList::MyDTI::newInstance() const {
    return new (16u) uGUIGPShopDialog::cScrollHistoryDispList;
}

const MtDTI& uGUIGPShopDialog::cScrollLimitItemList::getDTI() const {
    return uGUIGPShopDialog::cScrollLimitItemList::DTI;
}

inline uGUIGPShopDialog::cScrollLimitItemList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIGPShopDialog::cScrollLimitItemList::MyDTI uGUIGPShopDialog::cScrollLimitItemList::DTI("uGUIGPShopDialog::cScrollLimitItemList", &::uGUIBase::cScrollListInfoBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIGPShopDialog::cScrollLimitItemList::MyDTI::newInstance() const {
    DDON_STUB("uGUIGPShopDialog::cScrollLimitItemList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIGPShopDialog::cScrollHistoryItemList::getDTI() const {
    return uGUIGPShopDialog::cScrollHistoryItemList::DTI;
}

inline uGUIGPShopDialog::cScrollHistoryItemList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIGPShopDialog::cScrollHistoryItemList::MyDTI uGUIGPShopDialog::cScrollHistoryItemList::DTI("uGUIGPShopDialog::cScrollHistoryItemList", &::uGUIBase::cScrollListInfoBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIGPShopDialog::cScrollHistoryItemList::MyDTI::newInstance() const {
    DDON_STUB("uGUIGPShopDialog::cScrollHistoryItemList::MyDTI::newInstance")
    return nullptr;
}

