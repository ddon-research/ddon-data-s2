// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIQuestBoard.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Quest.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "../../XFramework/cUnit.h"
#include "nGUIExt.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "sChat.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIQuestBoardBase.h"
#include "uGUIQuestInfo.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIQuestBoard::getDTI() const {
    return uGUIQuestBoard::DTI;
}

uGUIQuestBoard::~uGUIQuestBoard() {
    if (mpGUIQuestInfo == nullptr) {
        return;
    }
    mpGUIQuestInfo->kill();
    mpGUIQuestInfo = nullptr;
}

void uGUIQuestBoard::createProperty(MtPropertyList& s) {
    this->uGUIQuestBoardBase::createProperty(s);
}

bool uGUIQuestBoard::loadResource() {
    return this->uGUIQuestBoardBase::loadResource();
}

__attribute__((weak)) void uGUIQuestBoard::setup() {
    DDON_STUB("uGUIQuestBoard::setup")
    /* stub */
}

void uGUIQuestBoard::kill() {
    this->uGUIQuestBoardBase::kill();
    if (mpGUIQuestInfo == nullptr) {
        return;
    }
    mpGUIQuestInfo->kill();
    mpGUIQuestInfo = nullptr;
}

void uGUIQuestBoard::updatePtr() {
    if (mpGUIQuestInfo != nullptr) {
        if (!mpGUIQuestInfo->isEnable()) {
            mpGUIQuestInfo = nullptr;
        }
    }
    if (mpConfirmDialog != nullptr) {
        if (!mpConfirmDialog->isEnable()) {
            mpConfirmDialog = nullptr;
        }
    }
    if (mpGpDialog == nullptr) {
        return;
    }
    if (mpGpDialog->isEnable()) {
        return;
    }
    mpGpDialog = nullptr;
}

void uGUIQuestBoard::setInfoFlow() {
    setFlowId(5u);
}

__attribute__((weak)) void uGUIQuestBoard::setFlowId(u32 flow_id) {
    DDON_STUB("uGUIQuestBoard::setFlowId")
    /* stub */
}

void uGUIQuestBoard::moveInput() {
    if (mFlowId == 5) {
        mMain.mClose.execute();
        mList.mListCtrl.executeCtrl();
        if (mpTabCtrl != nullptr) {
            mpTabCtrl->execute();
        }
        if (mpGpCompleteCtrl != nullptr) {
            mpGpCompleteCtrl->execute();
        }
        if (mpGUIQuestInfo != nullptr) {
            if ((mpGUIQuestInfo->getQuestInfoResult() - 1u) <= 1u) {
                switch (mpGUIQuestInfo->getQuestInfoResult()) {
                    case 1:
                    {
                        setFlowId(3u);
                        setInstanceVisible(static_cast<cGUIInstance*>(mMain.mpInstAnimWindowFrame), true);
                        break;
                    }
                    case 2:
                    {
                        setFlowId(2u);
                        setInstanceVisible(static_cast<cGUIInstance*>(mMain.mpInstAnimWindowFrame), true);
                        break;
                    }
                    default:
                    {
                        setInstanceVisible(static_cast<cGUIInstance*>(mMain.mpInstAnimWindowFrame), true);
                        break;
                    }
                }
            }
        }
    } else {
        if (mFlowId == 2) {
            mMain.mClose.execute();
            mList.mListCtrl.executeCtrl();
            if (mpTabCtrl != nullptr) {
                mpTabCtrl->execute();
            }
            if (mpDecideCtrl != nullptr) {
                mpDecideCtrl->execute();
            }
            if (mpCancelCtrl != nullptr) {
                mpCancelCtrl->execute();
            }
            if (mpGpCompleteCtrl != nullptr) {
                mpGpCompleteCtrl->execute();
            }
        }
    }
}

__attribute__((weak)) void uGUIQuestBoard::moveEvent() {
    DDON_STUB("uGUIQuestBoard::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIQuestBoard::updateMove() {
    DDON_STUB("uGUIQuestBoard::updateMove")
    /* stub */
}

void uGUIQuestBoard::updateExit() {
    end();
}

__attribute__((weak)) void uGUIQuestBoard::setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    DDON_STUB("uGUIQuestBoard::setupListItem")
    /* stub */
}

void uGUIQuestBoard::hideListItem(uGUIBase::cScrollListItemBase* pItemBase) {
    this->uGUIQuestBoardBase::hideListItem(pItemBase);
}

__attribute__((weak)) void uGUIQuestBoard::updateInit() {
    DDON_STUB("uGUIQuestBoard::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIQuestBoard::createList() {
    DDON_STUB("uGUIQuestBoard::createList")
    /* stub */
}

__attribute__((weak)) void uGUIQuestBoard::setupDetail() {
    DDON_STUB("uGUIQuestBoard::setupDetail")
    /* stub */
}

__attribute__((weak)) void uGUIQuestBoard::adjustListCursor() {
    DDON_STUB("uGUIQuestBoard::adjustListCursor")
    /* stub */
}

void uGUIQuestBoard::setupInfo() {
    if (mList.mListCtrl.mListPos < mList.mListCtrl.mInfoArray.mLength) {
        if (mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)] != nullptr) {
            unsigned long t0 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)]) + 8);
            if (t0 != 0) {
                setSequenceId(reinterpret_cast<cGUIInstAnimation*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 104)), 5u, true);
                setSequenceId(reinterpret_cast<cGUIInstAnimation*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 96)), 5u, true);
            }
            setInstanceVisible(static_cast<cGUIInstance*>(mMain.mpInstAnimWindowFrame), false);
            if (mpGUIQuestInfo != nullptr) {
                if (mpGUIQuestInfo->isCleared()) {
                    setupDetail();
                }
                mpGUIQuestInfo->setFocus(true);
            }
        } else {
            if (mpGUIQuestInfo != nullptr) {
                if (mpGUIQuestInfo->isCleared()) {
                    setupDetail();
                }
                mpGUIQuestInfo->setFocus(true);
            }
        }
    } else {
        if (mpGUIQuestInfo != nullptr) {
            if (mpGUIQuestInfo->isCleared()) {
                setupDetail();
            }
            mpGUIQuestInfo->setFocus(true);
        }
    }
}

__attribute__((weak)) void uGUIQuestBoard::initGpComplete() {
    DDON_STUB("uGUIQuestBoard::initGpComplete")
    /* stub */
}

__attribute__((weak)) void uGUIQuestBoard::setupGpComplete() {
    DDON_STUB("uGUIQuestBoard::setupGpComplete")
    /* stub */
}

__attribute__((weak)) void uGUIQuestBoard::checkDisableFocusGpComplate(u32 inputevent) {
    DDON_STUB("uGUIQuestBoard::checkDisableFocusGpComplate")
    /* stub */
}

__attribute__((weak)) void uGUIQuestBoard::enableGpComplete() {
    DDON_STUB("uGUIQuestBoard::enableGpComplete")
    /* stub */
}

__attribute__((weak)) void uGUIQuestBoard::updateDialog() {
    DDON_STUB("uGUIQuestBoard::updateDialog")
    /* stub */
}

__attribute__((weak)) void uGUIQuestBoard::updateGpCompleteWait() {
    DDON_STUB("uGUIQuestBoard::updateGpCompleteWait")
    /* stub */
}

void uGUIQuestBoard::eventAdjustTab() {
    if (mFlowId != 2) {
        return;
    }
    if (mIsGpComplete) {
        if (mList.mCursor.mpInstance != nullptr) {
            mList.mCursor.mpInstance->setVisible(true);
        }
        mIsFocusGpComplete = false;
        mMain.mButton.uGUIBase::cReferenceUIButton::setFocus(false);
        mList.mListCtrl.setEnableKey(true);
        if (mpDecideCtrl != nullptr) {
            mpDecideCtrl->mCtrlF = mpDecideCtrl->mCtrlF & 0xFFFFFFF7u;
        }
        if (mpGpCompleteCtrl != nullptr) {
            mpGpCompleteCtrl->mCtrlF = mpGpCompleteCtrl->mCtrlF | 8u;
        }
    }
    if (mpTabCtrl != nullptr) {
        mMain.mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(mpTabCtrl->getCurrentPos()), true, true);
    } else {
        mMain.mTab.uGUIBase::cReferenceUITab::setFocus(0u, true, true);
    }
    mList.mListCtrl.setListPos(0u, true);
    setFlowId(1u);
}

__attribute__((weak)) void uGUIQuestBoard::eventGpCompleteDecide() {
    DDON_STUB("uGUIQuestBoard::eventGpCompleteDecide")
    /* stub */
}

void uGUIQuestBoard::eventGpCompleteNotSelect() {
    if (mFlowId != 2) {
        if (mpGUIQuestInfo != nullptr) {
            mpGUIQuestInfo->cancelInfo();
        }
        setFlowId(2u);
    }
    if (mIsListEmpty) {
        sGUI* t0 = sGUI::getInstance();
        static_cast<sGUIExt*>(t0)->requestAnnounce(static_cast<sGUIExt*>(t0)->getMsgFromIdxInfo(mpGMDQuest, 113u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
    } else {
        if (mList.mListCtrl.mInfoArray.mLength != 0) {
            if (!mIsFocusGpComplete) {
                enableGpComplete();
            }
        }
    }
}

u32 uGUIQuestBoard::evCtrlDecide(cControl::Message* msg) {
    if (mFlowId == 2) {
        if (mList.mListCtrl.mListPos < mList.mListCtrl.mInfoArray.mLength) {
            if (mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)] != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mList.mListCtrl.mInfoArray.mpArray[static_cast<int>(mList.mListCtrl.mListPos)]) + 40)) != 0) {
                    if (msg != nullptr) {
                        msg->changeSE = 4;
                    }
                    setInputEvent(66u);
                    return 1;
                }
            }
        }
    }
    if (msg != nullptr) {
        msg->changeSE = 20;
    }
    setInputEvent(2u);
    return 0;
}

u32 uGUIQuestBoard::evCtrlCancel(cControl::Message* msg) {
    if (msg != nullptr) {
        msg->changeSE = 5;
    }
    setInputEvent(67u);
    return 1;
}

__attribute__((weak)) u32 uGUIQuestBoard::evCtrlShortCut(cControl::Message* msg) {
    DDON_STUB("uGUIQuestBoard::evCtrlShortCut")
    return {};
}

u32 uGUIQuestBoard::evCtrlAdjustTab(cControl::Message* msg) {
    setInputEvent(70u);
    return 1;
}

u32 uGUIQuestBoard::evCtrlMouseClick(cControl::Message* msg) {
    if (msg != nullptr) {
        if (mFlowId != 2) {
            if (mFlowId == 5) {
                if (mpGUIQuestInfo != nullptr) {
                    mpGUIQuestInfo->cancelInfo();
                }
                setFlowId(2u);
                msg->changeSE = 5;
                setInputEvent(70u);
                return 1;
            } else {
                return 0;
            }
        } else {
            setInputEvent(70u);
            return 1;
        }
    } else {
        return 0;
    }
}

bool uGUIQuestBoard::evCtrlScrl(cControl::Message* msg) {
    if (msg != nullptr) {
        cControl* t0 = msg->pSender;
        if (t0 != nullptr) {
            nGUIExt::MSG_REASON t1 = msg->reason;
            if (static_cast<unsigned int>(t1 - 37) <= 1) {
                bool t2 = mIsFocusGpComplete;
                if (t2) {
                    bool t3 = mIsGpComplete;
                    if (t3) {
                        cGUIInstAnimation* t4 = mList.mCursor.mpInstance;
                        if (t4 != nullptr) {
                            t4->setVisible(true);
                            mIsFocusGpComplete = false;
                            mMain.mButton.uGUIBase::cReferenceUIButton::setFocus(false);
                            mList.mListCtrl.setEnableKey(true);
                            cControl* t8 = mpDecideCtrl;
                            if (t8 != nullptr) {
                                unsigned char t9 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t8) + 3132);
                                t8->mCtrlF = t8->mCtrlF & 0xFFFFFFF7u;
                                cControl* t10 = mpGpCompleteCtrl;
                                if (t10 != nullptr) {
                                    unsigned char t11 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t10) + 3132);
                                    t10->mCtrlF = t10->mCtrlF | 8u;
                                }
                            } else {
                                cControl* t10 = mpGpCompleteCtrl;
                                if (t10 != nullptr) {
                                    unsigned char t11 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t10) + 3132);
                                    t10->mCtrlF = t10->mCtrlF | 8u;
                                }
                            }
                            msg->changeSE = 1;
                            setInputEvent(69u);
                            return false;
                        } else {
                            mIsFocusGpComplete = false;
                            mMain.mButton.uGUIBase::cReferenceUIButton::setFocus(false);
                            mList.mListCtrl.setEnableKey(true);
                            cControl* t8 = mpDecideCtrl;
                            if (t8 != nullptr) {
                                unsigned char t9 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t8) + 3132);
                                t8->mCtrlF = t8->mCtrlF & 0xFFFFFFF7u;
                                cControl* t10 = mpGpCompleteCtrl;
                                if (t10 != nullptr) {
                                    unsigned char t11 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t10) + 3132);
                                    t10->mCtrlF = t10->mCtrlF | 8u;
                                }
                            } else {
                                cControl* t10 = mpGpCompleteCtrl;
                                if (t10 != nullptr) {
                                    unsigned char t11 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t10) + 3132);
                                    t10->mCtrlF = t10->mCtrlF | 8u;
                                }
                            }
                            msg->changeSE = 1;
                            setInputEvent(69u);
                            return false;
                        }
                    } else {
                        msg->changeSE = 1;
                        setInputEvent(69u);
                        return false;
                    }
                } else {
                    s32 t12 = t0->getCurrentPos();
                    s32 t13 = t0->getOldPos();
                    u32 t14 = mFlowId;
                    if (t14 == 2) {
                        if (t1 == nGUIExt::MOUSE_LCLICK) {
                            if (t12 == t13) {
                                u32 t15 = mList.mListCtrl.mListPos;
                                u32 t16 = mList.mListCtrl.mInfoArray.mLength;
                                if (t15 < t16) {
                                    MtObject* * t17 = mList.mListCtrl.mInfoArray.mpArray;
                                    MtObject* t18 = t17[static_cast<int>(t15)];
                                    if (t18 != nullptr) {
                                        unsigned long t19 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t18) + 40);
                                        if (t19 != 0) {
                                            msg->changeSE = 4;
                                            setInputEvent(66u);
                                        } else {
                                            msg->changeSE = 20;
                                            setInputEvent(2u);
                                        }
                                        return false;
                                    } else {
                                        msg->changeSE = 20;
                                        setInputEvent(2u);
                                        return false;
                                    }
                                } else {
                                    msg->changeSE = 20;
                                    setInputEvent(2u);
                                    return false;
                                }
                            } else {
                                msg->changeSE = 1;
                                setInputEvent(69u);
                                return false;
                            }
                        } else {
                            msg->changeSE = 1;
                            setInputEvent(69u);
                            return false;
                        }
                    } else {
                        uGUIQuestInfo* t20 = mpGUIQuestInfo;
                        if (t20 != nullptr) {
                            t20->cancelInfo();
                        }
                        mList.mListCtrl.setListPos(false);
                        if (t12 != t13) {
                            setFlowId(2u);
                        }
                        msg->changeSE = 1;
                        setInputEvent(69u);
                        return false;
                    }
                }
            } else {
                return true;
            }
        } else {
            return true;
        }
    } else {
        return true;
    }
}

u32 uGUIQuestBoard::evCtrlGpCompleteDecide(cControl::Message* msg) {
    if (mIsListEmpty) {
        setInputEvent(72u);
        if (msg != nullptr) {
            msg->changeSE = 20;
        }
    } else {
        setInputEvent(71u);
    }
    return 0;
}

u32 uGUIQuestBoard::evCtrlGpCompleteUp(cControl::Message* msg) {
    if (mList.mListCtrl.mInfoArray.mLength != 0) {
        setInputEvent(73u);
    }
    return 0;
}

u32 uGUIQuestBoard::evCtrlGpCompleteDown(cControl::Message* msg) {
    if (mList.mListCtrl.mInfoArray.mLength != 0) {
        setInputEvent(74u);
    }
    return 0;
}

inline uGUIQuestBoard::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIQuestBoard::MyDTI uGUIQuestBoard::DTI("uGUIQuestBoard", &::uGUIQuestBoardBase::DTI, 8368ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIQuestBoard::MyDTI::newInstance() const {
    DDON_STUB("uGUIQuestBoard::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIQuestBoard::cListInfo::getDTI() const {
    return uGUIQuestBoard::cListInfo::DTI;
}

uGUIQuestBoard::cListInfo::~cListInfo() {
    if (mpData == nullptr) {
        return;
    }
    delete mpData;
    mpData = nullptr;
}

inline uGUIQuestBoard::cListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIQuestBoard::cListInfo::MyDTI uGUIQuestBoard::cListInfo::DTI("uGUIQuestBoard::cListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIQuestBoard::cListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIQuestBoard::cListInfo::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<nQuest::cGUIBoardData>::~MtTypedArray();

