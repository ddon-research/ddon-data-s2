// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPSStore.h"
#include "Protocol/PacketData/DLCLineup.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "sChat.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIPSStore::getDTI() const {
    return uGUIPSStore::DTI;
}

void* uGUIPSStore::operator new(size_t sz, u32 align) {
    return uGUIPSStore::getAllocator()->memAlloc(sz, align, uGUIPSStore::DTI.getID());
}

__attribute__((noinline)) uGUIPSStore::~uGUIPSStore() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpGUIDialog != nullptr) {
        mpGUIDialog->kill();
        mpGUIDialog = nullptr;
    }
}

bool uGUIPSStore::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_DLC_STATION_GUI"), 129u, 1436277534l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_DLC_STATION_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIPSStore::updatePtr() {
    if (mpGUIDialog == nullptr) {
        return;
    }
    if (mpGUIDialog->isEnable()) {
        return;
    }
    mpGUIDialog = nullptr;
}

__attribute__((weak)) void uGUIPSStore::setup() {
    DDON_STUB("uGUIPSStore::setup")
    /* stub */
}

void uGUIPSStore::kill() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpGUIDialog != nullptr) {
        mpGUIDialog->kill();
        mpGUIDialog = nullptr;
    }
    this->uGUIBase::kill();
}

void uGUIPSStore::moveInput() {
    mClose.execute();
    if (!mIsSetup) {
        return;
    }
    if (mDlcFlow != LIST_FLOW_ITEM_CONFIRM) {
        s32 t0 = mCategoryCtrlMgr.getCurrentPos(0u);
        if (t0 == 1) {
            mHistoryScrlList.executeCtrl();
        } else {
            if (t0 == 0) {
                mStationScrlList.executeCtrl();
            }
        }
        mCategoryCtrlMgr.moveInput();
        if (mpCtrlCancel != nullptr) {
            mpCtrlCancel->execute();
        }
        if (mpCtrlDecide != nullptr) {
            mpCtrlDecide->execute();
        }
    } else {
        if (mpCtrlCancel != nullptr) {
            mpCtrlCancel->execute();
        }
        if (mpCtrlDecide != nullptr) {
            mpCtrlDecide->execute();
        }
    }
}

__attribute__((weak)) void uGUIPSStore::moveEvent() {
    DDON_STUB("uGUIPSStore::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIPSStore::updateWait() {
    DDON_STUB("uGUIPSStore::updateWait")
    /* stub */
}

u32 uGUIPSStore::evCtrlCancel(cControl::Message* pMsg) {
    setInputEvent(67u);
    return 1;
}

u32 uGUIPSStore::evCtrlCategoryMenuCursorUD(cControl::Message* pMsg) {
    if (mDlcFlow == LIST_FLOW_CATEGORY) {
        setInputEvent(68u);
    }
    return 1;
}

u32 uGUIPSStore::evCtrlDecide(cControl::Message* pMsg) {
    if (mDlcFlow == LIST_FLOW_STATION) {
        setInputEvent(72u);
    } else {
        if (mDlcFlow == LIST_FLOW_CATEGORY) {
            setInputEvent(69u);
        }
    }
    return 1;
}

u32 uGUIPSStore::evCtrlClose(cControl::Message* pMsg) {
    setInputEvent(66u);
    return 1;
}

u32 uGUIPSStore::evCtrlCateLClick(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        if (pMsg->pSender != nullptr) {
            if (mCategoryCtrlMgr.mControl[0].mpScrollList != nullptr) {
                if (pMsg->pSender == mCategoryCtrlMgr.mControl[0].mpScrollList->getCtrl()) {
                    if (pMsg->pSender->getCurrentPos() == pMsg->pSender->mOldPos) {
                        setInputEvent(75u);
                    } else {
                        setInputEvent(74u);
                    }
                }
            } else {
                if (pMsg->pSender == mCategoryCtrlMgr.mControl[0].mpCtrl) {
                    if (pMsg->pSender->getCurrentPos() == pMsg->pSender->mOldPos) {
                        setInputEvent(75u);
                    } else {
                        setInputEvent(74u);
                    }
                }
            }
        }
    }
    return 1;
}

u32 uGUIPSStore::evCtrlListLClick(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        if (pMsg->pSender != nullptr) {
            if (mStationScrlList.getCtrl() != nullptr) {
                if (pMsg->pSender == mStationScrlList.getCtrl()) {
                    setInputEvent(76u);
                }
            }
            if (mHistoryScrlList.getCtrl() != nullptr) {
                if (mHistoryScrlList.getCtrl() == pMsg->pSender) {
                    setInputEvent(77u);
                }
            }
        }
    }
    return 1;
}

__attribute__((weak)) void uGUIPSStore::setupWindow() {
    DDON_STUB("uGUIPSStore::setupWindow")
    /* stub */
}

__attribute__((weak)) void uGUIPSStore::setupCategoryMenu() {
    DDON_STUB("uGUIPSStore::setupCategoryMenu")
    /* stub */
}

__attribute__((weak)) void uGUIPSStore::setupStationWindow() {
    DDON_STUB("uGUIPSStore::setupStationWindow")
    /* stub */
}

void uGUIPSStore::setupHistoryCommon() {
    cGUIInstance* t0 = getInstance(56u, false);
    if (t0 != nullptr) {
        cGUIObject* t1 = getObjectFromId(t0, 2u);
        if ((mpHistoryCaption = static_cast<cGUIObjMessage*>(t1)) != nullptr) {
            t1->setVisible(false);
            cGUIInstance* t2 = getInstance(58u, false);
            if (t2 != nullptr) {
                cGUIObject* t3 = getObjectFromId(t2, 3u);
                if (t3 != nullptr) {
                    setObjectMessage(t3, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 8u), 0u, false);
                    cGUIObject* t4 = getObjectFromId(t2, 6u);
                    if (t4 != nullptr) {
                        setObjectMessage(t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 9u), 0u, false);
                        cGUIObject* t5 = getObjectFromId(t2, 4u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                        }
                    } else {
                        cGUIObject* t5 = getObjectFromId(t2, 4u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                        }
                    }
                } else {
                    cGUIObject* t4 = getObjectFromId(t2, 6u);
                    if (t4 != nullptr) {
                        setObjectMessage(t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 9u), 0u, false);
                        cGUIObject* t5 = getObjectFromId(t2, 4u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                        }
                    } else {
                        cGUIObject* t5 = getObjectFromId(t2, 4u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                        }
                    }
                }
            }
        } else {
            cGUIInstance* t2 = getInstance(58u, false);
            if (t2 != nullptr) {
                cGUIObject* t3 = getObjectFromId(t2, 3u);
                if (t3 != nullptr) {
                    setObjectMessage(t3, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 8u), 0u, false);
                    cGUIObject* t4 = getObjectFromId(t2, 6u);
                    if (t4 != nullptr) {
                        setObjectMessage(t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 9u), 0u, false);
                        cGUIObject* t5 = getObjectFromId(t2, 4u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                        }
                    } else {
                        cGUIObject* t5 = getObjectFromId(t2, 4u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                        }
                    }
                } else {
                    cGUIObject* t4 = getObjectFromId(t2, 6u);
                    if (t4 != nullptr) {
                        setObjectMessage(t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 9u), 0u, false);
                        cGUIObject* t5 = getObjectFromId(t2, 4u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                        }
                    } else {
                        cGUIObject* t5 = getObjectFromId(t2, 4u);
                        if (t5 != nullptr) {
                            setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                        }
                    }
                }
            }
        }
    } else {
        cGUIInstance* t2 = getInstance(58u, false);
        if (t2 != nullptr) {
            cGUIObject* t3 = getObjectFromId(t2, 3u);
            if (t3 != nullptr) {
                setObjectMessage(t3, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 8u), 0u, false);
                cGUIObject* t4 = getObjectFromId(t2, 6u);
                if (t4 != nullptr) {
                    setObjectMessage(t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 9u), 0u, false);
                    cGUIObject* t5 = getObjectFromId(t2, 4u);
                    if (t5 != nullptr) {
                        setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                    }
                } else {
                    cGUIObject* t5 = getObjectFromId(t2, 4u);
                    if (t5 != nullptr) {
                        setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                    }
                }
            } else {
                cGUIObject* t4 = getObjectFromId(t2, 6u);
                if (t4 != nullptr) {
                    setObjectMessage(t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 9u), 0u, false);
                    cGUIObject* t5 = getObjectFromId(t2, 4u);
                    if (t5 != nullptr) {
                        setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                    }
                } else {
                    cGUIObject* t5 = getObjectFromId(t2, 4u);
                    if (t5 != nullptr) {
                        setObjectMessage(t5, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 10u), 0u, false);
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void uGUIPSStore::setupHistoryWindow() {
    DDON_STUB("uGUIPSStore::setupHistoryWindow")
    /* stub */
}

__attribute__((weak)) void uGUIPSStore::setFlow(s32 categoryMenuCurrentIndex) {
    DDON_STUB("uGUIPSStore::setFlow")
    /* stub */
}

__attribute__((weak)) void uGUIPSStore::adjustCategoryMenuCursor() {
    DDON_STUB("uGUIPSStore::adjustCategoryMenuCursor")
    /* stub */
}

__attribute__((weak)) void uGUIPSStore::adjustList() {
    DDON_STUB("uGUIPSStore::adjustList")
    /* stub */
}

__attribute__((weak)) void uGUIPSStore::setupStationScrollInfo() {
    DDON_STUB("uGUIPSStore::setupStationScrollInfo")
    /* stub */
}

void uGUIPSStore::updateStationItemDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    if (pListItem == nullptr) {
        return;
    }
    if (pDispItem == nullptr) {
        return;
    }
    pDispItem->mpInstBase->setVisible(true);
    pDispItem->mpInstBase->setExecute(true);
    pDispItem->mpInstBase->setPositionY(mStationListOffsetY * static_cast<float>(Index));
    if (pListItem->mpItem == nullptr) {
        return;
    }
    cStationListItem* pdisp = static_cast<cStationListItem*>(pDispItem);
    if (pdisp->mpObjContent != nullptr) {
        cStationListInfo* pinfo = static_cast<cStationListInfo*>(pListItem);
        setObjectMessage(static_cast<cGUIObject*>(pdisp->mpObjContent), pinfo->mpItemName, 0u, false);
        if (pdisp->mpObjStack != nullptr) {
            setMsgAnalyzerWork(0u, static_cast<s32>(pinfo->mStack));
            cGUIObjMessage* t0 = pdisp->mpObjStack;
            setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 6u), 0u, false);
            if (pdisp->mpInstButton != nullptr) {
                cGUIObject* t1 = getObjectFromId(static_cast<cGUIInstance*>(pdisp->mpInstButton), 24u);
                if (t1 != nullptr) {
                    setObjectMessage(t1, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 7u), 0u, false);
                }
                pinfo->mpInstButton = pdisp->mpInstButton;
                pdisp->mItemIndex = static_cast<s32>(Index);
                pinfo->mItemBaseIndex = pdisp->mItemIndex;
            } else {
                pinfo->mpInstButton = pdisp->mpInstButton;
                pdisp->mItemIndex = static_cast<s32>(Index);
                pinfo->mItemBaseIndex = pdisp->mItemIndex;
            }
        } else {
            if (pdisp->mpInstButton != nullptr) {
                cGUIObject* t1 = getObjectFromId(static_cast<cGUIInstance*>(pdisp->mpInstButton), 24u);
                if (t1 != nullptr) {
                    setObjectMessage(t1, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 7u), 0u, false);
                }
                pinfo->mpInstButton = pdisp->mpInstButton;
                pdisp->mItemIndex = static_cast<s32>(Index);
                pinfo->mItemBaseIndex = pdisp->mItemIndex;
            } else {
                pinfo->mpInstButton = pdisp->mpInstButton;
                pdisp->mItemIndex = static_cast<s32>(Index);
                pinfo->mItemBaseIndex = pdisp->mItemIndex;
            }
        }
    } else {
        if (pdisp->mpObjStack != nullptr) {
            cStationListInfo* pinfo = static_cast<cStationListInfo*>(pListItem);
            setMsgAnalyzerWork(0u, static_cast<s32>(pinfo->mStack));
            cGUIObjMessage* t0 = pdisp->mpObjStack;
            setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 6u), 0u, false);
            if (pdisp->mpInstButton != nullptr) {
                cGUIObject* t1 = getObjectFromId(static_cast<cGUIInstance*>(pdisp->mpInstButton), 24u);
                if (t1 != nullptr) {
                    setObjectMessage(t1, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 7u), 0u, false);
                }
                pinfo->mpInstButton = pdisp->mpInstButton;
                pdisp->mItemIndex = static_cast<s32>(Index);
                pinfo->mItemBaseIndex = pdisp->mItemIndex;
            } else {
                pinfo->mpInstButton = pdisp->mpInstButton;
                pdisp->mItemIndex = static_cast<s32>(Index);
                pinfo->mItemBaseIndex = pdisp->mItemIndex;
            }
        } else {
            if (pdisp->mpInstButton != nullptr) {
                cGUIObject* t1 = getObjectFromId(static_cast<cGUIInstance*>(pdisp->mpInstButton), 24u);
                if (t1 != nullptr) {
                    setObjectMessage(t1, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 7u), 0u, false);
                    cStationListInfo* pinfo = static_cast<cStationListInfo*>(pListItem);
                    pinfo->mpInstButton = pdisp->mpInstButton;
                    pdisp->mItemIndex = static_cast<s32>(Index);
                    pinfo->mItemBaseIndex = pdisp->mItemIndex;
                } else {
                    cStationListInfo* pinfo = static_cast<cStationListInfo*>(pListItem);
                    pinfo->mpInstButton = pdisp->mpInstButton;
                    pdisp->mItemIndex = static_cast<s32>(Index);
                    pinfo->mItemBaseIndex = pdisp->mItemIndex;
                }
            } else {
                cStationListInfo* pinfo = static_cast<cStationListInfo*>(pListItem);
                pinfo->mpInstButton = pdisp->mpInstButton;
                pdisp->mItemIndex = static_cast<s32>(Index);
                pinfo->mItemBaseIndex = pdisp->mItemIndex;
            }
        }
    }
}

void uGUIPSStore::updateStationItemHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem == nullptr) {
        return;
    }
    if (pDispItem->mpInstBase == nullptr) {
        return;
    }
    cStationListItem* pdisp = static_cast<cStationListItem*>(pDispItem);
    pdisp->mItemIndex = -1;
    pDispItem->mpInstBase->setVisible(false);
    pDispItem->mpInstBase->setExecute(false);
}

__attribute__((weak)) void uGUIPSStore::useItem() {
    DDON_STUB("uGUIPSStore::useItem")
    /* stub */
}

__attribute__((weak)) void uGUIPSStore::setupHistoryScrollInfo() {
    DDON_STUB("uGUIPSStore::setupHistoryScrollInfo")
    /* stub */
}

__attribute__((weak)) void uGUIPSStore::updateHistoryItemDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIPSStore::updateHistoryItemDisp")
    /* stub */
}

void uGUIPSStore::updateHistoryItemHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem == nullptr) {
        return;
    }
    if (pDispItem->mpInstBase == nullptr) {
        return;
    }
    pDispItem->mpInstBase->setVisible(false);
    pDispItem->mpInstBase->setExecute(false);
}

__attribute__((weak)) void uGUIPSStore::setupItemUseDialog() {
    DDON_STUB("uGUIPSStore::setupItemUseDialog")
    /* stub */
}

void uGUIPSStore::psstoreEventShiftStation() {
    if (mStationItemNum != 0) {
        s32 posIndex = mCategoryCtrlMgr.getCurrentPos(0u);
        if (static_cast<unsigned int>(posIndex) <= 1) {
            if (mCategoryItem[posIndex].pInst != nullptr) {
                mCategoryItem[posIndex].pInst->setSequenceId(5u);
            }
        }
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
        setFlow(0);
        if (mStationScrlList.getCtrl() != nullptr) {
            if (!static_cast<sGUIExt*>(sGUI::getInstance())->mMouse.mIsMouseMode) {
                mStationScrlList.setListPos(static_cast<u32>(mStationScrlList.getCtrl()->getCurrentPos()), false);
            }
        }
    } else {
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 20u);
    }
}

void uGUIPSStore::psstoreEventShiftHistory() {
    if (mHistoryItemNum != 0) {
        s32 posIndex = mCategoryCtrlMgr.getCurrentPos(0u);
        if (static_cast<unsigned int>(posIndex) <= 1) {
            if (mCategoryItem[posIndex].pInst != nullptr) {
                mCategoryItem[posIndex].pInst->setSequenceId(5u);
            }
        }
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
        setFlow(1);
        if (!static_cast<sGUIExt*>(sGUI::getInstance())->mMouse.mIsMouseMode) {
            if (mHistoryScrlList.getCtrl() != nullptr) {
                mHistoryScrlList.setListPos(static_cast<u32>(mHistoryScrlList.getCtrl()->getCurrentPos()), false);
            }
        }
    } else {
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 20u);
    }
}

void uGUIPSStore::checkRequestList() {
    s32 posIndex = mCategoryCtrlMgr.getCurrentPos(0u);
    if (posIndex == 1) {
        if (!mIsGetHistoryItems) {
            mHistoryScrlList.clear();
            if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIPSStore::requestServerHistoryList);
                mServerCommandStatusRsv = 490;
                mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIPSStore::initHisotryCallback);
                mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
            } else {
                mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIPSStore::requestServerHistoryList);
                mServerCommandStatus = 490;
                mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIPSStore::initHisotryCallback);
                mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                mServerRno = 0;
                mServerResult = 0;
            }
        }
    } else {
        if (posIndex == 0) {
            if (!mIsGetStationItems) {
                mStationScrlList.clear();
                if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                    mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIPSStore::requestServerStationList);
                    mServerCommandStatusRsv = 488;
                    mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIPSStore::initStationCallback);
                    mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                } else {
                    mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIPSStore::requestServerStationList);
                    mServerCommandStatus = 488;
                    mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIPSStore::initStationCallback);
                    mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                    mServerRno = 0;
                    mServerResult = 0;
                }
            }
        }
    }
}

void uGUIPSStore::initStationCallback() {
    DLCLineupBoughtVec* pStationItems = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getDLCLineupBoughts();
    if (pStationItems != nullptr) {
        static_cast<sGUIExt*>(sGUI::getInstance())->mIsNoUseDLC = pStationItems->mLength != 0;
        mIsGetStationItems = true;
        cGUIInstAnimation* t0 = mpStationScrollBar;
        cGUIInstance* t1 = getInstance(27u, false);
        cGUIObject* t2 = getObjectFromId(25u, 3u);
        mStationScrlList.mpOwner = static_cast<uGUIBase*>(this);
        mStationScrlList.mpSetupFunc = static_cast<cScrollList::SetupFunc>(&::uGUIPSStore::updateStationItemDisp);
        mStationScrlList.mpHideFunc = static_cast<cScrollList::HideFunc>(&::uGUIPSStore::updateStationItemHide);
        mStationScrlList.mBar.setup(static_cast<uGUIBase*>(this), static_cast<cGUIInstance*>(t0), t2);
        mStationScrlList.mpInstNullScroll = static_cast<cGUIInstNull*>(t1);
        if (t0 != nullptr) {
            t0->setVisible(false);
        }
        setupStationScrollInfo();
        setFlow(static_cast<s32>(mDlcFlow));
    } else {
        if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
            mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIPSStore::requestServerStationList);
            mServerCommandStatusRsv = 488;
            mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIPSStore::initStationCallback);
            mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
        } else {
            mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIPSStore::requestServerStationList);
            mServerCommandStatus = 488;
            mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIPSStore::initStationCallback);
            mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
            mServerRno = 0;
            mServerResult = 0;
        }
    }
}

void uGUIPSStore::initHisotryCallback() {
    DLCLineupHistoryVec* pHisotryItems = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getDLCLineupHistorys();
    if (pHisotryItems != nullptr) {
        mIsGetHistoryItems = true;
        cGUIInstAnimation* t0 = mpHistoryScrollBar;
        cGUIInstance* t1 = getInstance(60u, false);
        cGUIObject* t2 = getObjectFromId(59u, 3u);
        mHistoryScrlList.mpOwner = static_cast<uGUIBase*>(this);
        mHistoryScrlList.mpSetupFunc = static_cast<cScrollList::SetupFunc>(&::uGUIPSStore::updateHistoryItemDisp);
        mHistoryScrlList.mpHideFunc = static_cast<cScrollList::HideFunc>(&::uGUIPSStore::updateHistoryItemHide);
        mHistoryScrlList.mBar.setup(static_cast<uGUIBase*>(this), static_cast<cGUIInstance*>(t0), t2);
        mHistoryScrlList.mpInstNullScroll = static_cast<cGUIInstNull*>(t1);
        if (t0 != nullptr) {
            t0->setVisible(false);
        }
        setupHistoryScrollInfo();
        setFlow(static_cast<s32>(mDlcFlow));
    } else {
        if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
            mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIPSStore::requestServerStationList);
            mServerCommandStatusRsv = 488;
            mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIPSStore::initStationCallback);
            mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
        } else {
            mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIPSStore::requestServerStationList);
            mServerCommandStatus = 488;
            mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIPSStore::initStationCallback);
            mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
            mServerRno = 0;
            mServerResult = 0;
        }
    }
}

void uGUIPSStore::initRequestCallback() {
    cGUIInstAnimation* t0 = mpStationScrollBar;
    cGUIInstance* t1 = getInstance(27u, false);
    cGUIObject* t2 = getObjectFromId(25u, 3u);
    mStationScrlList.mpOwner = static_cast<uGUIBase*>(this);
    mStationScrlList.mpSetupFunc = static_cast<cScrollList::SetupFunc>(&::uGUIPSStore::updateStationItemDisp);
    mStationScrlList.mpHideFunc = static_cast<cScrollList::HideFunc>(&::uGUIPSStore::updateStationItemHide);
    mStationScrlList.mBar.setup(static_cast<uGUIBase*>(this), static_cast<cGUIInstance*>(t0), t2);
    mStationScrlList.mpInstNullScroll = static_cast<cGUIInstNull*>(t1);
    if (t0 != nullptr) {
        t0->setVisible(false);
        setupStationScrollInfo();
        cGUIInstAnimation* t3 = mpHistoryScrollBar;
        cGUIInstance* t4 = getInstance(60u, false);
        cGUIObject* t5 = getObjectFromId(59u, 3u);
        mHistoryScrlList.mpOwner = static_cast<uGUIBase*>(this);
        mHistoryScrlList.mpSetupFunc = static_cast<cScrollList::SetupFunc>(&::uGUIPSStore::updateHistoryItemDisp);
        mHistoryScrlList.mpHideFunc = static_cast<cScrollList::HideFunc>(&::uGUIPSStore::updateHistoryItemHide);
        mHistoryScrlList.mBar.setup(static_cast<uGUIBase*>(this), static_cast<cGUIInstance*>(t3), t5);
        mHistoryScrlList.mpInstNullScroll = static_cast<cGUIInstNull*>(t4);
        if (t3 != nullptr) {
            t3->setVisible(false);
        }
        setupHistoryScrollInfo();
    } else {
        setupStationScrollInfo();
        cGUIInstAnimation* t3 = mpHistoryScrollBar;
        cGUIInstance* t4 = getInstance(60u, false);
        cGUIObject* t5 = getObjectFromId(59u, 3u);
        mHistoryScrlList.mpOwner = static_cast<uGUIBase*>(this);
        mHistoryScrlList.mpSetupFunc = static_cast<cScrollList::SetupFunc>(&::uGUIPSStore::updateHistoryItemDisp);
        mHistoryScrlList.mpHideFunc = static_cast<cScrollList::HideFunc>(&::uGUIPSStore::updateHistoryItemHide);
        mHistoryScrlList.mBar.setup(static_cast<uGUIBase*>(this), static_cast<cGUIInstance*>(t3), t5);
        mHistoryScrlList.mpInstNullScroll = static_cast<cGUIInstNull*>(t4);
        if (t3 != nullptr) {
            t3->setVisible(false);
        }
        setupHistoryScrollInfo();
    }
}

__attribute__((weak)) void uGUIPSStore::itemUseCallback() {
    DDON_STUB("uGUIPSStore::itemUseCallback")
    /* stub */
}

bool uGUIPSStore::requestServerStationList() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->reqDLCLineupBoughts();
    return true;
}

bool uGUIPSStore::requestServerHistoryList() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->reqDLCLineupHistorys();
    return true;
}

bool uGUIPSStore::requestServerUseItem() {
    if (mpReqItemInfo != nullptr) {
        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->reqDLCLineupUse(mpReqItemInfo->mItemID);
    }
    return true;
}

inline uGUIPSStore::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPSStore::MyDTI uGUIPSStore::DTI("uGUIPSStore", &::uGUIBase::DTI, 18304ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPSStore::MyDTI::newInstance() const {
    DDON_STUB("uGUIPSStore::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIPSStore::cStationListItem::getDTI() const {
    return uGUIPSStore::cStationListItem::DTI;
}

inline uGUIPSStore::cStationListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPSStore::cStationListItem::MyDTI uGUIPSStore::cStationListItem::DTI("uGUIPSStore::cStationListItem", &::uGUIBase::cScrollListItemBase::DTI, 136ul, 0u, 0u);

MtObject* uGUIPSStore::cStationListItem::MyDTI::newInstance() const {
    return new (16u) uGUIPSStore::cStationListItem;
}

const MtDTI& uGUIPSStore::cHistoryListItem::getDTI() const {
    return uGUIPSStore::cHistoryListItem::DTI;
}

inline uGUIPSStore::cHistoryListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPSStore::cHistoryListItem::MyDTI uGUIPSStore::cHistoryListItem::DTI("uGUIPSStore::cHistoryListItem", &::uGUIBase::cScrollListItemBase::DTI, 120ul, 0u, 0u);

MtObject* uGUIPSStore::cHistoryListItem::MyDTI::newInstance() const {
    return new (16u) uGUIPSStore::cHistoryListItem;
}

const MtDTI& uGUIPSStore::cStationListInfo::getDTI() const {
    return uGUIPSStore::cStationListInfo::DTI;
}

inline uGUIPSStore::cStationListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPSStore::cStationListInfo::MyDTI uGUIPSStore::cStationListInfo::DTI("uGUIPSStore::cStationListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPSStore::cStationListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIPSStore::cStationListInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIPSStore::cHistoryListInfo::getDTI() const {
    return uGUIPSStore::cHistoryListInfo::DTI;
}

uGUIPSStore::cHistoryListInfo::~cHistoryListInfo() {
}

inline uGUIPSStore::cHistoryListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPSStore::cHistoryListInfo::MyDTI uGUIPSStore::cHistoryListInfo::DTI("uGUIPSStore::cHistoryListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPSStore::cHistoryListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIPSStore::cHistoryListInfo::MyDTI::newInstance")
    return nullptr;
}

