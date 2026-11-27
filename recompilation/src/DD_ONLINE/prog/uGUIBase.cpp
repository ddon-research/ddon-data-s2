// Reconstructed from the game's DWARF debug information.
#include <new>
#include <sce_atomic.h>
#include <stdio.h>
#include <string.h>
#include "uGUIBase.h"
#include "Protocol/PacketData/Clan.h"
#include "../../generated/shared/Error.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCharSet.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemory.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "cArcLoader.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cControl.h"
#include "../../XFramework/cDraw.h"
#include "cGUIExtNetMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "cGUIObjTextureRef.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIPageList.h"
#include "cGUIUtility.h"
#include "../../XFramework/cGUIVariable.h"
#include "cInputTextKeyboardHook.h"
#include "cItemParam.h"
#include "cNetGameServer.h"
#include "cQuestSvRequestManager.h"
#include "../../XFramework/cResource.h"
#include "cUIObject.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "nGUIItem.h"
#include "../../generated/shared/nHuman.h"
#include "nHumanMsg.h"
#include "nJobParam.h"
#include "../../generated/shared/nKeyCustom.h"
#include "nNet.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "rEmblemColorTable.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIFont.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "../../XFramework/rTexture.h"
#include "sArchiveManager.h"
#include "../../XFramework/sCamera.h"
#include "sContextManager.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sHttpClient.h"
#include "sInputManager.h"
#include "sItemManager.h"
#include "../../XFramework/sKeyboard.h"
#include "sKeyboardInterface.h"
#include "../../XFramework/sMain.h"
#include "sMarker.h"
#include "../../XFramework/sMouse.h"
#include "sMouseExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sRender.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIMap.h"
#include "uHuman.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

namespace nGUIExt {
static const u32 EQUIP_SLOT_TABLE[17] = {
    1,
    3,
    4,
    6,
    7,
    5,
    8,
    9,
    15,
    2,
    17,
    18,
    10,
    11,
    12,
    13,
    14,
};
}

const MtDTI& uGUIBase::getDTI() const {
    return uGUIBase::DTI;
}

bool uGUIBase::isSMENUdecide() {
    return mSMENUdecide;
}

bool uGUIBase::isSMENUcancel() {
    return mSMENUcancel;
}

bool uGUIBase::isSMENUchkout() {
    return mSMENUchkout;
}

bool uGUIBase::isSMENUtopbtn() {
    return mSMENUtopbtn;
}

static auto ddon_emit_0x01adbcc0 __attribute__((used)) = &uGUIBase::evCtrlDummy;

__attribute__((weak)) u32 uGUIBase::evCtrlControlMgrCancel(cControl::Message* pMsg) {
    DDON_STUB("uGUIBase::evCtrlControlMgrCancel")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlControlMgrStart(cControl::Message* pMsg) {
    DDON_STUB("uGUIBase::evCtrlControlMgrStart")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlControlMgrDecide(cControl::Message* pMsg) {
    DDON_STUB("uGUIBase::evCtrlControlMgrDecide")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlControlMgrTabMove(cControl::Message* pMsg) {
    DDON_STUB("uGUIBase::evCtrlControlMgrTabMove")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlControlMgrVListMove(cControl::Message* pMsg) {
    DDON_STUB("uGUIBase::evCtrlControlMgrVListMove")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlControlMgrHListMove(cControl::Message* pMsg) {
    DDON_STUB("uGUIBase::evCtrlControlMgrHListMove")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlPageListMoveParent(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlPageListMoveParent")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlPageListMoveCursor(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlPageListMoveCursor")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlPageListMovePage(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlPageListMovePage")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlPageListMouseSelect(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlPageListMouseSelect")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlPageListMouseDecide(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlPageListMouseDecide")
    return {};
}

__attribute__((weak)) void uGUIBase::setupEquipEnableJobIcon(uGUIBase::cReferenceUIIconJob(&icons)[10], u32 item_id) {
    DDON_STUB("uGUIBase::setupEquipEnableJobIcon")
    /* stub */
}

__attribute__((weak)) u32 uGUIBase::evCtrlBtnGuideMouseLClick(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlBtnGuideMouseLClick")
    return {};
}

u32 uGUIBase::evCtrlTextBoxDecide(cControl::Message* msg) {
    mInputEventId = 54;
    return 0;
}

u32 uGUIBase::evCtrlTextBoxCancel(cControl::Message* msg) {
    mInputEventId = 55;
    return 0;
}

u32 uGUIBase::evCtrlcReferenceUIToggleBtnSwitch(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->pSender != nullptr) {
            msg->pSender->setCurrentPos(static_cast<s32>((msg->current - (((msg->current + (static_cast<unsigned int>(msg->current + 1) >> 31)) + 1u) & 0xFFFFFFFEu)) + 1u), false);
            return 1;
        }
    }
    return 0;
}

u32 uGUIBase::evCtrlcReferenceUICheckListCancel(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->pSender != nullptr) {
            if (msg->pData != nullptr) {
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(msg->pData) + 1244) = 2;
                msg->changeSE = 5;
                mInputEventId = 57;
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 uGUIBase::evCtrlcReferenceUICheckListMove(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlcReferenceUICheckListMove")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlcReferenceUICheckListMtxDecide(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlcReferenceUICheckListMtxDecide")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlcReferenceUICheckListHListDecide(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlcReferenceUICheckListHListDecide")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlcReferenceUICheckListMtxClick(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlcReferenceUICheckListMtxClick")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlcReferenceUICheckListHListClick(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlcReferenceUICheckListHListClick")
    return {};
}

u32 uGUIBase::cReferenceUINumBoxEvCtrlCursorRMove(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        void* t0 = pMsg->pData;
        if (t0 != nullptr) {
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 25;
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

u32 uGUIBase::cReferenceUINumBoxEvCtrlCursorLMove(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        void* t0 = pMsg->pData;
        if (t0 != nullptr) {
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 24;
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

u32 uGUIBase::cReferenceUINumBoxEvCtrlCursorUMove(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        void* t0 = pMsg->pData;
        if (t0 != nullptr) {
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 22;
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

u32 uGUIBase::cReferenceUINumBoxEvCtrlCursorDMove(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        void* t0 = pMsg->pData;
        if (t0 != nullptr) {
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 23;
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

u32 uGUIBase::cReferenceUINumBoxEvCtrlCursorDecide(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        void* t0 = pMsg->pData;
        if (t0 != nullptr) {
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 26;
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

u32 uGUIBase::cReferenceUINumBoxEvCtrlCursorCancel(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        void* t0 = pMsg->pData;
        if (t0 != nullptr) {
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 27;
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

u32 uGUIBase::cReferenceUINumBoxEvCtrlLClickOOMT(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        void* t0 = pMsg->pData;
        if (t0 != nullptr) {
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 29;
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

u32 uGUIBase::cReferenceUINumBoxEvCtrlMouseWheel(cControl::Message* pMsg) {
    cControl* const sender = pMsg->pSender;
    if (sender != nullptr) {
        if (!sender->mMouseExec.mIsOOMT) {
            if (pMsg->click_vol == 2) {
                if (pMsg->reason == nGUIExt::MOUSE_WHEEL_BACK) {
                    if (pMsg != nullptr) {
                        void* t0 = pMsg->pData;
                        if (t0 != nullptr) {
                            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 31;
                            }
                        }
                        return 0;
                    }
                } else {
                    if (pMsg->reason == nGUIExt::MOUSE_WHEEL_FORWARD) {
                        if (pMsg != nullptr) {
                            void* t1 = pMsg->pData;
                            if (t1 != nullptr) {
                                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 16)) != 0) {
                                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 272) = 1;
                                    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 16)) + 2104) = 30;
                                }
                            }
                            return 0;
                        }
                    }
                }
            }
        } else {
            if (pMsg->reason == nGUIExt::MOUSE_WHEEL_BACK) {
                if (pMsg != nullptr) {
                    void* t0 = pMsg->pData;
                    if (t0 != nullptr) {
                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 31;
                        }
                    }
                    return 0;
                }
            } else {
                if (pMsg->reason == nGUIExt::MOUSE_WHEEL_FORWARD) {
                    if (pMsg != nullptr) {
                        void* t1 = pMsg->pData;
                        if (t1 != nullptr) {
                            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 16)) != 0) {
                                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 272) = 1;
                                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 16)) + 2104) = 30;
                            }
                        }
                        return 0;
                    }
                }
            }
        }
    } else {
        if (pMsg->click_vol == 2) {
            if (pMsg->reason == nGUIExt::MOUSE_WHEEL_BACK) {
                if (pMsg != nullptr) {
                    void* t0 = pMsg->pData;
                    if (t0 != nullptr) {
                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 272) = 1;
                            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 2104) = 31;
                        }
                    }
                    return 0;
                }
            } else {
                if (pMsg->reason == nGUIExt::MOUSE_WHEEL_FORWARD) {
                    if (pMsg != nullptr) {
                        void* t1 = pMsg->pData;
                        if (t1 != nullptr) {
                            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 16)) != 0) {
                                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 272) = 1;
                                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 16)) + 2104) = 30;
                            }
                        }
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 uGUIBase::evCtrlNumPagerMouseClick(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlNumPagerMouseClick")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlNumPagerMouseWheel(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlNumPagerMouseWheel")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListUp(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListUp")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListDown(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListDown")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListLeft(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListLeft")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListRight(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListRight")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListMouseSelect(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListMouseSelect")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListMouseDecide(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListMouseDecide")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListMouseLClickOOMT(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListMouseLClickOOMT")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListDecide(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListDecide")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListTopbtn(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListTopbtn")
    return {};
}

__attribute__((weak)) u32 uGUIBase::evCtrlScrollListChkout(cControl::Message* msg) {
    DDON_STUB("uGUIBase::evCtrlScrollListChkout")
    return {};
}

u32 uGUIBase::cReferenceUIPullDown_evCtrlCancel(cControl::Message* msg) {
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(msg->pData) + 1516) = 1;
    mInputEventId = 45;
    return 0;
}

u32 uGUIBase::cReferenceUIPullDown_evCtrlDecide(cControl::Message* msg) {
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(msg->pData) + 1516) = 1;
    mInputEventId = 46;
    return 0;
}

__attribute__((weak)) void uGUIBase::updateScrollListDisp_PullDown(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUIBase::updateScrollListDisp_PullDown")
    /* stub */
}

__attribute__((weak)) void uGUIBase::updateScrollListHide_PullDown(uGUIBase::cScrollListItemBase* pDispItem) {
}

uGUIBase::uGUIBase(u32 initFlags, bool isChatSubMenu) {
    DDON_STUB("uGUIBase::uGUIBase")
    /* stub */
}

__attribute__((noinline)) uGUIBase::~uGUIBase() {
    DDON_STUB("uGUIBase::~uGUIBase")
    /* stub */
}

__attribute__((weak)) void uGUIBase::move() {
    DDON_STUB("uGUIBase::move")
    /* stub */
}

void uGUIBase::moveAfter() {
    this->uGUI::moveAfter();
}

bool uGUIBase::errorResourceCheck(rGUI* pResource) {
    return pResource != nullptr;
}

__attribute__((weak)) void uGUIBase::setup() {
    DDON_STUB("uGUIBase::setup")
    /* stub */
}

void uGUIBase::kill() {
    if (mpItemMgrRequest != nullptr) {
        if (!mpItemMgrRequest->isExit(static_cast<void*>(this))) {
            mpItemMgrRequest->mIsResultCancel = true;
        }
        mpItemMgrRequest = nullptr;
    }
    if ((sQuestManagerExt::mpInstance) != nullptr) {
        cQuestSvRequestManager::popRequest(static_cast<const MtObject*>(this));
    }
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) == 0) {
        if ((mBeFlag - 1u) <= 1u) {
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
        }
    }
    if (mpEmblemColorTable != nullptr) {
        mpEmblemColorTable->release();
        mpEmblemColorTable = nullptr;
    }
    if (mpMsgOnlineStatus != nullptr) {
        mpMsgOnlineStatus->release();
        mpMsgOnlineStatus = nullptr;
    }
    if (mpMsgPawnPersonality != nullptr) {
        mpMsgPawnPersonality->release();
        mpMsgPawnPersonality = nullptr;
    }
    if (mpMsgPawnFeedbackComment != nullptr) {
        mpMsgPawnFeedbackComment->release();
        mpMsgPawnFeedbackComment = nullptr;
    }
    if (mpMsgPawnShareRange != nullptr) {
        mpMsgPawnShareRange->release();
        mpMsgPawnShareRange = nullptr;
    }
    if (mpMsgPawnStatus != nullptr) {
        mpMsgPawnStatus->release();
        mpMsgPawnStatus = nullptr;
    }
    if (mpMsgPlayStyleItem != nullptr) {
        mpMsgPlayStyleItem->release();
        mpMsgPlayStyleItem = nullptr;
    }
    if (mpMsgClanProfileItem != nullptr) {
        mpMsgClanProfileItem->release();
        mpMsgClanProfileItem = nullptr;
    }
}

void uGUIBase::draw(cDraw* pDraw) {
    u32 v0_0;
    MtObject* * v0_1;
    unsigned int i0_2;
    if ((((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pDraw) + 560)) & 0xFFFF000000000000ul) ^ 0x1000000000000ul) == 0) {
        if (fixCameraRelatedScreenPos()) {
            if ((mBaseF & 128u) == 0) {
                if ((mBaseF & static_cast<sGUIExt*>(sGUI::getInstance())->mNDispGUIFromBaseF) == 0) {
                    this->uGUI::draw(pDraw);
                    v0_0 = mAryKeepInScreen.mLength;
                    if (v0_0 != 0) {
                        v0_1 = mAryKeepInScreen.getBuffer();
                        i0_2 = 0;
                    } else {
                        return;
                    }
                } else {
                    return;
                }
            } else {
                return;
            }
        } else {
            return;
        }
    } else {
        if ((mBaseF & 128u) == 0) {
            if ((mBaseF & static_cast<sGUIExt*>(sGUI::getInstance())->mNDispGUIFromBaseF) == 0) {
                this->uGUI::draw(pDraw);
                v0_0 = mAryKeepInScreen.mLength;
                if (v0_0 != 0) {
                    v0_1 = mAryKeepInScreen.getBuffer();
                    i0_2 = 0;
                } else {
                    return;
                }
            } else {
                return;
            }
        } else {
            return;
        }
    }
    for (;;) {
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 9) = 1;
        if ((i0_2 + 1u) < v0_0) {
            i0_2 += 1u;
        } else {
            break;
        }
    }
}

void uGUIBase::takeOverEndFlag(uGUIBase* pBaseGUI) {
    if (pBaseGUI == nullptr) {
        return;
    }
    if ((pBaseGUI->mBaseF & 4u) != 0) {
        mBaseF = mBaseF | 4u;
    } else {
        if ((pBaseGUI->mBaseF & 8u) != 0) {
            mBaseF = mBaseF | 8u;
        }
    }
}

bool uGUIBase::isStartEnd() const {
    return ((mBaseF & 8u) != 0) || (mEndReason == END_REASON_START_BTN);
}

__attribute__((weak)) void uGUIBase::setGUIMove(bool IsMove) {
    DDON_STUB("uGUIBase::setGUIMove")
    /* stub */
}

void uGUIBase::setStopAllContol(bool b) {
    mIsStopAllControl = b;
}

__attribute__((weak)) bool uGUIBase::isEnableControlExecution() const {
    DDON_STUB("uGUIBase::isEnableControlExecution")
    return {};
}

void uGUIBase::executedMsgEventNtc(s32 reason) {
    if (reason == 8) {
        mEndReason = END_REASON_START_BTN;
    } else {
        if (reason == 5) {
            mEndReason = END_REASON_CANCEL_BTN;
        } else {
            mEndReason = END_REASON_DEFAULT;
        }
    }
}

void uGUIBase::setUseIGUIExtNetFunc(u32 ReqID) {
    mGUIExtNetMgrUseId = cGUIExtNetMgr::checkAfterRequest(mGUIExtNetMgrUseId, ReqID);
}

void uGUIBase::setUseIItemMangerNetFunc(sItemManager::stRequest* pRequest) {
    mpItemMgrRequest = pRequest;
}

bool uGUIBase::isForceSamplerLinear(cGUIObject* pObj) const {
    if (mpInstNullBase != nullptr) {
        if (mpInstNullBase->mScale.x > 1.0f) {
            return true;
        }
    }
    return false;
}

__attribute__((weak)) uGUIPopCmd01* uGUIBase::createPopCmd01(bool isChatSubMenu) {
    DDON_STUB("uGUIBase::createPopCmd01")
    return nullptr;
}

__attribute__((weak)) void uGUIBase::deleteDuplicateAll() {
    DDON_STUB("uGUIBase::deleteDuplicateAll")
    /* stub */
}

__attribute__((weak)) void uGUIBase::deleteDuplicateInstance(cGUIInstance* pInst) {
    DDON_STUB("uGUIBase::deleteDuplicateInstance")
    /* stub */
}

void uGUIBase::deleteDuplicateInstanceAll() {
    if (mDuplicates.mLength == 0) {
        deleteDuplicateAll();
        return;
    }
    u32 i = 0;
    do {
        deleteInstance(mDuplicates.mpArray[i]->mpInst);
        i += 1u;
    } while (i < mDuplicates.mLength);
    deleteDuplicateAll();
}

s32 uGUIBase::getSMenuCursorX() {
    return uGUIBase::DISABLE_IDX;
}

s32 uGUIBase::getSMenuCursorXOrder(s32 orderId) {
    return uGUIBase::DISABLE_IDX;
}

s32 uGUIBase::getSMenuCursorY() {
    return uGUIBase::DISABLE_IDX;
}

s32 uGUIBase::getSMenuCursorYOrder(s32 orderId) {
    return uGUIBase::DISABLE_IDX;
}

s32 uGUIBase::getSMenuTab() {
    return uGUIBase::DISABLE_IDX;
}

u32 uGUIBase::getVariableParamU32FromId(u32 varId) {
    cGUIVariable* pVar = getVariable(varId);
    if (pVar != nullptr) {
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pVar) + 24);
    } else {
        return 0;
    }
}

s32 uGUIBase::getVariableParamS32FromId(u32 varId) {
    cGUIVariable* pVar = getVariable(varId);
    if (pVar != nullptr) {
        return static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pVar) + 24));
    } else {
        return 0;
    }
}

s32 uGUIBase::getVariableParamS32FromName(MT_CTSTR varName) {
    cGUIVariable* pVar = getVariableFromName(varName);
    if (pVar != nullptr) {
        return static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pVar) + 24));
    } else {
        return 0;
    }
}

u32 uGUIBase::getVariableInitParamU32FromId(u32 varId) {
    cGUIVariable* pVar = getVariable(varId);
    if (pVar != nullptr) {
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pVar) + 32);
    } else {
        return 0;
    }
}

s32 uGUIBase::getVariableInitParamS32FromId(u32 varId) {
    cGUIVariable* pVar = getVariable(varId);
    if (pVar != nullptr) {
        return static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pVar) + 32));
    } else {
        return 0;
    }
}

__attribute__((weak)) f32 uGUIBase::getVariableInitParamF32FromId(u32 varId) {
    DDON_STUB("uGUIBase::getVariableInitParamF32FromId")
    return {};
}

bool uGUIBase::loadResource() {
    return false;
}

__attribute__((weak)) bool uGUIBase::loadArchive() {
    DDON_STUB("uGUIBase::loadArchive")
    return {};
}

void uGUIBase::update() {
    if (!mIsCurrentFuncExecute) {
        return;
    }
    if (mpCurrentFunc == static_cast<void(uGUIBase::*)()>(0)) {
        return;
    }
    (this->*mpCurrentFunc)();
}

__attribute__((weak)) void uGUIBase::end() {
    DDON_STUB("uGUIBase::end")
    /* stub */
}

__attribute__((weak)) bool uGUIBase::loadResourceBase() {
    DDON_STUB("uGUIBase::loadResourceBase")
    return {};
}

__attribute__((weak)) void uGUIBase::setPriority(u32 uIssueIdx, bool bSetScreenLayer) {
    static const u32 uTblScrl[20] = {
        0,
        3,
        6,
        9,
        12,
        15,
        18,
        21,
        24,
        27,
        30,
        33,
        36,
        39,
        46,
        49,
        52,
        55,
        58,
        61,
    };
    if (mIsChatSubMenu) {
        if (uIssueIdx <= 346u) {
            static_cast<sGUIExt*>(sGUI::getInstance())->returnPriority(uIssueIdx);
            u32 t0 = static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(14u);
            if (t0 <= 399u) {
                mPrioIssueIdx = t0;
                u32 uPrio = static_cast<sGUIExt*>(sGUI::getInstance())->getIssuePriority(t0);
                if ((mAttr & 0x100000u) == 0) {
                    mPriority = ((uPrio * 32u) <= 0xFFFFFu) ? (uPrio * 32u) : 0xFFFFFu;
                } else {
                    mPriority = uPrio * 32u;
                }
                if (bSetScreenLayer) {
                    s32 sPrioGrp = static_cast<sGUIExt*>(sGUI::getInstance())->getPrioGrpFromIssueIdx(uPrio);
                    if (static_cast<unsigned int>(sPrioGrp) <= 19) {
                        mScreenLayer = (uTblScrl[sPrioGrp] <= 127u) ? uTblScrl[sPrioGrp] : 127u;
                    }
                }
            }
        } else {
            if (uIssueIdx <= 399u) {
                mPrioIssueIdx = uIssueIdx;
                u32 uPrio = static_cast<sGUIExt*>(sGUI::getInstance())->getIssuePriority(uIssueIdx);
                if ((mAttr & 0x100000u) == 0) {
                    mPriority = ((uPrio * 32u) <= 0xFFFFFu) ? (uPrio * 32u) : 0xFFFFFu;
                } else {
                    mPriority = uPrio * 32u;
                }
                if (bSetScreenLayer) {
                    s32 sPrioGrp = static_cast<sGUIExt*>(sGUI::getInstance())->getPrioGrpFromIssueIdx(uPrio);
                    if (static_cast<unsigned int>(sPrioGrp) <= 19) {
                        mScreenLayer = (uTblScrl[sPrioGrp] <= 127u) ? uTblScrl[sPrioGrp] : 127u;
                    }
                }
            }
        }
    } else {
        if (uIssueIdx <= 399u) {
            mPrioIssueIdx = uIssueIdx;
            u32 uPrio = static_cast<sGUIExt*>(sGUI::getInstance())->getIssuePriority(uIssueIdx);
            if ((mAttr & 0x100000u) == 0) {
                mPriority = ((uPrio * 32u) <= 0xFFFFFu) ? (uPrio * 32u) : 0xFFFFFu;
            } else {
                mPriority = uPrio * 32u;
            }
            if (bSetScreenLayer) {
                s32 sPrioGrp = static_cast<sGUIExt*>(sGUI::getInstance())->getPrioGrpFromIssueIdx(uPrio);
                if (static_cast<unsigned int>(sPrioGrp) <= 19) {
                    mScreenLayer = (uTblScrl[sPrioGrp] <= 127u) ? uTblScrl[sPrioGrp] : 127u;
                }
            }
        }
    }
}

void uGUIBase::replacePriority(u32 uPrioGrp) {
    static_cast<sGUIExt*>(sGUI::getInstance())->returnPriority(mPrioIssueIdx);
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(uPrioGrp), true);
}

bool uGUIBase::fixCameraRelatedScreenPos() {
    return true;
}

static auto ddon_emit_0x01ae17f0 __attribute__((used)) = &uGUIBase::forceExitFunc;

__attribute__((weak)) void uGUIBase::setWindowActive(bool IsActive) {
    DDON_STUB("uGUIBase::setWindowActive")
    /* stub */
}

void uGUIBase::setFocusForActiveBar(bool IsActive) {
    if (mpActiveBar == nullptr) {
        return;
    }
    mpActiveBar->setVisible(IsActive && !mIsActiveBarForceDispOff);
}

__attribute__((weak)) void uGUIBase::managerWindowActive() {
    DDON_STUB("uGUIBase::managerWindowActive")
    /* stub */
}

cGUIInstance* uGUIBase::getInstance(const u32 id, bool isAssert) const {
    return this->uGUI::getInstance(id, isAssert);
}

void uGUIBase::setSequenceId(cGUIInstAnimation* pInstAnim, u32 uSeqId, bool bReset) {
    if (pInstAnim != nullptr) {
        const MtDTI& t0 = pInstAnim->getDTI();
        MT_CTSTR v0_1 = cGUIInstAnimation::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                pInstAnim->setSequenceId(uSeqId);
                if (bReset) {
                    pInstAnim->resetCurrentFrame();
                }
                return;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
}

void uGUIBase::setSequenceId(cGUIObjChildAnimationRoot* pInst, u32 uSeqId, bool bReset) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cGUIObjChildAnimationRoot::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                pInst->setChildSequenceId(uSeqId);
                if (bReset) {
                    pInst->setChildAnimationCurrentFrame(0.0f);
                }
                return;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
}

u32 uGUIBase::getSequenceId(cGUIInstAnimation* pInst) {
    if (pInst != nullptr) {
        return pInst->getSequenceId();
    } else {
        return 0;
    }
}

void uGUIBase::setInstNull(cGUIInstNull* pInstNull, bool bOptionData) {
    mpInstNullBase = pInstNull;
}

void uGUIBase::setInstanceVisible(cGUIInstance* pInst, bool bVisible) {
    if (pInst == nullptr) {
        return;
    }
    pInst->setVisible(bVisible);
}

void uGUIBase::setInstanceVisible(u32 instId, bool bVisible) {
    cGUIInstance* pInst = getInstance(instId, false);
    if (pInst == nullptr) {
        return;
    }
    pInst->setVisible(bVisible);
}

__attribute__((weak)) void uGUIBase::setInstanceVisibleTree(cGUIInstance* pInst, bool bVisible) {
    DDON_STUB("uGUIBase::setInstanceVisibleTree")
    /* stub */
}

void uGUIBase::setInstanceExecute(cGUIInstance* pInst, bool bExecute) {
    if (pInst == nullptr) {
        return;
    }
    pInst->setExecute(bExecute);
}

__attribute__((weak)) void uGUIBase::setInstanceExecuteTree(cGUIInstance* pInst, bool bExecute) {
    DDON_STUB("uGUIBase::setInstanceExecuteTree")
    /* stub */
}

__attribute__((weak)) void uGUIBase::copyInstanceExecuteTree(cGUIInstance* pTreeOrg, cGUIInstance* pTreeDup) {
    DDON_STUB("uGUIBase::copyInstanceExecuteTree")
    /* stub */
}

__attribute__((weak)) MtVector4 uGUIBase::getInstancePositionRoot(cGUIInstance* pInst, MtVector3* pScaleRoot) {
    DDON_STUB("uGUIBase::getInstancePositionRoot")
    __builtin_unreachable();
}

void uGUIBase::adjustScale() {
    cGUIInstNull* t0 = mpInstNullBase;
    f32 t1 = getScaleForDefaultResolution(1.0f);
    if (t0 == nullptr) {
        return;
    }
    t0->setScaleX(t1);
    t0->setScaleY(t1);
    t0->setScaleZ(t1);
}

__attribute__((weak)) void uGUIBase::updateScaleForWindow(f32& fScaleRate) {
}

f32 uGUIBase::getScaleForDefaultResolution(f32 fScaleRate) {
    return cGUIUtility::getScaleForDefaultResolution(fScaleRate);
}

__attribute__((weak)) bool uGUIBase::isHitInstanceChild(cGUIInstance* pInstance, const MtVector3& pt, f32 ratio) const {
    DDON_STUB("uGUIBase::isHitInstanceChild")
    return {};
}

__attribute__((weak)) f32 uGUIBase::getTabWidth(u32 InstId, u32 ObjCenterCenterId) {
    DDON_STUB("uGUIBase::getTabWidth")
    return {};
}

__attribute__((weak)) cGUIInstance* uGUIBase::ManageDuplicate(cGUIInstance* pOrgInst, cGUIInstance* pParentInst) {
    DDON_STUB("uGUIBase::ManageDuplicate")
    return nullptr;
}

__attribute__((weak)) cGUIObject* uGUIBase::getObjectFromId(cGUIInstance* pInst, u32 uId) {
    DDON_STUB("uGUIBase::getObjectFromId")
    return nullptr;
}

cGUIObject* uGUIBase::getObjectFromId(u32 uInstId, u32 uId) {
    cGUIInstAnimation* pInst = static_cast<cGUIInstAnimation*>(getInstance(uInstId, false));
    if (pInst != nullptr) {
        if (pInst->mpObjRoot != nullptr) {
            return pInst->mpObjRoot->getObjectFromId(uId);
        }
    }
    return nullptr;
}

MtVector2 uGUIBase::getObjectScreenPos(cGUIObject* pObj, const MtVector3& offset) {
    MtVector2 obj_pos;
    if (pObj != nullptr) {
        const f32 t0 = offset.y;
        f32 t1 = pObj->mMat.m[3].y;
        obj_pos.x = offset.x + pObj->mMat.m[3].x;
        obj_pos.y = t0 + t1;
        return obj_pos;
    } else {
        obj_pos.x = MtVector2::Zero.x;
        obj_pos.y = MtVector2::Zero.y;
        return obj_pos;
    }
}

__attribute__((weak)) MtVector2 uGUIBase::getInstanceScreenPos(cGUIInstance* pInst, const MtVector3& offset) {
    DDON_STUB("uGUIBase::getInstanceScreenPos")
    __builtin_unreachable();
}

void uGUIBase::setMsgAnalyzerWork(u32 uIdx, MT_CTSTR pAnalyzeMsg) {
    if (uIdx <= 9u) {
        mMsgAnalyzerWork[uIdx].mEnable = true;
        if (pAnalyzeMsg != mMsgAnalyzerWork[uIdx].mAnalyzeMsg.ptr()) {
            if (mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value != nullptr) {
                if (sceAtomicAdd32Relaxed(&mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value->ref, -1) == 1) {
                    (MtString::mpAllocator)->memFree(static_cast<void*>(mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value));
                }
                mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value = nullptr;
            }
            if (pAnalyzeMsg != nullptr) {
                size_t t0 = strlen(pAnalyzeMsg);
                if (static_cast<unsigned int>(t0) != 0) {
                    void* t1 = (MtString::mpAllocator)->memAlloc(static_cast<size_t>(static_cast<unsigned int>(t0)) + 12, 16u);
                    mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value = static_cast<MtString::STRING*>(t1);
                    mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value->ref = 1;
                    mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value->length = static_cast<unsigned int>(t0);
                    strcpy(reinterpret_cast<char*>(mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value->str), pAnalyzeMsg);
                } else {
                    mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value = nullptr;
                }
            } else {
                mMsgAnalyzerWork[uIdx].mAnalyzeMsg.value = nullptr;
            }
        }
    }
}

void uGUIBase::setMsgAnalyzerWork(u32 uIdx, s32 sAnalyzeNum) {
    if (uIdx <= 9u) {
        mMsgAnalyzerWork[uIdx].mEnable = true;
        mMsgAnalyzerWork[uIdx].mAnalyzeNum = sAnalyzeNum;
    }
}

void uGUIBase::setMessageColor(cGUIObject* pObj, const MtColor& color) {
    if (pObj != nullptr) {
        const MtDTI& t0 = pObj->getDTI();
        MT_CTSTR v0_1 = cGUIObjMessage::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cGUIObjMessage*>(pObj)->setColor(color);
                return;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
}

__attribute__((weak)) void uGUIBase::setObjectMessage(cGUIObject* pObj, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap) {
    DDON_STUB("uGUIBase::setObjectMessage")
    /* stub */
}

__attribute__((weak)) void uGUIBase::setObjectMessageFromId(u32 instId, u32 objId, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap) {
    DDON_STUB("uGUIBase::setObjectMessageFromId")
    /* stub */
}

__attribute__((weak)) void uGUIBase::setObjectMessageFromId(cGUIInstance* pInst, u32 objId, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap) {
    DDON_STUB("uGUIBase::setObjectMessageFromId")
    /* stub */
}

__attribute__((weak)) void uGUIBase::setObjectMessageAdjustSize(cGUIObject* pObj, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap) {
    DDON_STUB("uGUIBase::setObjectMessageAdjustSize")
    /* stub */
}

__attribute__((weak)) void uGUIBase::setObjectMessageFit(cGUIObjMessage* pObjMsg, MT_CTSTR msg, size_t size) {
    DDON_STUB("uGUIBase::setObjectMessageFit")
    /* stub */
}

__attribute__((weak)) void uGUIBase::setWindowTitle(u32 InstId, u32 EngObjId, u32 JpObjId, MT_CTSTR pEngName, MT_CTSTR pJpName) {
    DDON_STUB("uGUIBase::setWindowTitle")
    /* stub */
}

void uGUIBase::setWindowTitle(cGUIObjMessage* pEngObj, cGUIObjMessage* pJpObj, MT_CTSTR pEngName, MT_CTSTR pJpName) {
    if (pEngObj != nullptr) {
        setObjectMessage(static_cast<cGUIObject*>(pEngObj), pEngName, 0u, false);
        if (pJpObj != nullptr) {
            setObjectMessage(static_cast<cGUIObject*>(pJpObj), pJpName, 0u, false);
            pJpObj->setPositionX(pEngObj->mPosition.x + (pEngObj->getMessageWidth() + 8.0f));
        }
    } else {
        if (pJpObj != nullptr) {
            setObjectMessage(static_cast<cGUIObject*>(pJpObj), pJpName, 0u, false);
        }
    }
}

void uGUIBase::setVariableParamFromId(u32 varId, s32 prm, bool reset) {
    cGUIVariable* pVar = getVariable(varId);
    if (pVar == nullptr) {
        return;
    }
    static_cast<cGUIVarInt*>(pVar)->set(prm, reset);
}

void uGUIBase::setVariableParamFromId(u32 varId, u32 prm, bool reset) {
    cGUIVariable* t0 = getVariable(varId);
    if (t0 == nullptr) {
        return;
    }
    static_cast<cGUIVarInt*>(t0)->set(static_cast<s32>(prm), reset);
}

__attribute__((weak)) void uGUIBase::subVariableRegister(uGUIBase::cDuplicateData* pDuplicate, cGUIInstance* pInst) {
    DDON_STUB("uGUIBase::subVariableRegister")
    /* stub */
}

void uGUIBase::evChangeFlow(const nGUI::FLOW* pNewFlow, const nGUI::FLOW* pNowFlow) {
    mIsFlowEnd = true;
    u32 v0_0 = mAryKeepInScreen.mLength;
    if (v0_0 != 0) {
        MtObject* * v0_1 = mAryKeepInScreen.getBuffer();
        for (unsigned int i0_2 = 0;;) {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 9) = 0;
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 12) = 0;
            if ((i0_2 + 1u) < v0_0) {
                i0_2 += 1u;
            } else {
                break;
            }
        }
    }
}

void uGUIBase::setFlowAndInit(const u32 flowId, bool isEndWait) {
    setPlayingFlow(getFlow(flowId), true);
    mIsFlowEnd = getProcessEndCondition(flowId) == 2;
    play(0.0f);
    mIsFlowWaitMode = isEndWait;
}

void uGUIBase::setChangeFlowVariable(const u32 varId, bool bChange) {
    cGUIVariable* t0 = getVariable(varId);
    if (t0 != nullptr) {
        static_cast<cGUIVarInt*>(t0)->set(bChange, true);
    }
    play(0.0f);
    mIsFlowEnd = false;
    mIsFlowWaitMode = false;
}

void uGUIBase::changeFlow(u32 uVarIdSW, u32 uFlowSwitch, u32 uVarIdCF) {
    cGUIVariable* t0 = getVariable(uVarIdSW);
    if (t0 != nullptr) {
        static_cast<cGUIVarInt*>(t0)->set(static_cast<s32>(uFlowSwitch), true);
        cGUIVariable* t1 = getVariable(uVarIdCF);
        if (t1 != nullptr) {
            static_cast<cGUIVarInt*>(t1)->set(1, true);
        }
        play(0.0f);
    } else {
        cGUIVariable* t1 = getVariable(uVarIdCF);
        if (t1 != nullptr) {
            static_cast<cGUIVarInt*>(t1)->set(1, true);
        }
        play(0.0f);
    }
    mIsFlowEnd = false;
    mIsFlowWaitMode = false;
}

__attribute__((weak)) void uGUIBase::setStatusGauge(cGUIObject* pObjGauge, cGUIObject* pObjMsgValue, f32 value, f32 max_value, bool isInverce) {
    DDON_STUB("uGUIBase::setStatusGauge")
    /* stub */
}

__attribute__((weak)) void uGUIBase::setExpGauge(cGUIObject* pObjTexGauge, cGUIObject* pObjMsgValue, const nJobParam::cJobInfo* pJobInfo, bool isInverce) {
    DDON_STUB("uGUIBase::setExpGauge")
    /* stub */
}

__attribute__((weak)) void uGUIBase::setMessageHorizontalInterval(cGUIObj2D* pObjLeft, cGUIObj2D* pObjRight, f32 interval, bool isLeftBase) {
    DDON_STUB("uGUIBase::setMessageHorizontalInterval")
    /* stub */
}

s32 uGUIBase::convertJobID2ResJobFrame(nHuman::JOB_ENUM val) {
    return val - 1;
}

void uGUIBase::setArcTag(u32 tagId, u32 index, bool isKeep) {
    if (index <= 4u) {
        mArcTag[index] = tagId;
        mArcKeep[index] = isKeep;
    }
}

u32 uGUIBase::getArcTag(u32 index) {
    if (index <= 4u) {
        return mArcTag[index];
    } else {
        return 0;
    }
}

cResource* uGUIBase::uiCreateResource(u32 arcTag, u32 searchId, u32 mode, t64 update_time) {
    cResource* pRes = sArchiveManager::getInstance()->createRes(arcTag, searchId, mode, false);
    cResource* v2_3;
    if (pRes == nullptr) {
        v2_3 = nullptr;
        return v2_3;
    } else {
        if ((pRes->mState & 1u) != 0) {
            if (update_time != 0) {
                const MtDTI& t0 = pRes->getDTI();
                MT_CTSTR v0_1 = rGUI::DTI.mName;
                for (const MtDTI* v0_0 = &t0;;) {
                    if (v0_1 != v0_0->mName) {
                        if (v0_0->mpParent != nullptr) {
                            v0_0 = v0_0->mpParent;
                        } else {
                            break;
                        }
                    } else {
                        setResourceWithCheck(static_cast<rGUI*>(pRes), update_time, true);
                        v2_3 = pRes;
                        return v2_3;
                    }
                }
            } else {
                v2_3 = pRes;
                return v2_3;
            }
        }
    }
    pRes->release();
    v2_3 = nullptr;
    return v2_3;
}

bool uGUIBase::loadGMD(MT_CTSTR str, u32 aryIdx) {
    if (mpGUIMsgs.elems[(aryIdx <= 3u) ? aryIdx : 0u] == nullptr) {
        unsigned int t0 = mArcTag[0];
        sArchiveManager* t1 = sArchiveManager::getInstance();
        cResource* t2 = t1->createRes(t0, rArchiveListArray::convSearchId(str), 129u, false);
        if (t2 != nullptr) {
            if ((t2->mState & 1u) != 0) {
                mpGUIMsgs.elems[(aryIdx <= 3u) ? aryIdx : 0u] = static_cast<rGUIMessage*>(t2);
                return true;
            }
            t2->release();
        }
        return false;
    } else {
        return true;
    }
}

bool uGUIBase::loadGMDarc(u32 arcTag, MT_CTSTR resTag, u32 aryIdx) {
    if (mpGUIMsgs.elems[(aryIdx <= 3u) ? aryIdx : 0u] == nullptr) {
        sArchiveManager* t0 = sArchiveManager::getInstance();
        cResource* t1 = t0->createRes(arcTag, rArchiveListArray::convSearchId(resTag), 129u, false);
        if (t1 != nullptr) {
            if ((t1->mState & 1u) != 0) {
                mpGUIMsgs.elems[(aryIdx <= 3u) ? aryIdx : 0u] = static_cast<rGUIMessage*>(t1);
                return true;
            }
            t1->release();
        }
        return false;
    } else {
        return true;
    }
}

void uGUIBase::releaseGMD() {
    if (mpGUIMsgs.elems[0] != nullptr) {
        mpGUIMsgs.elems[0]->cResource::release();
        mpGUIMsgs.elems[0] = nullptr;
    }
    if (mpGUIMsgs.elems[1] != nullptr) {
        mpGUIMsgs.elems[1]->cResource::release();
        mpGUIMsgs.elems[1] = nullptr;
    }
    if (mpGUIMsgs.elems[2] != nullptr) {
        mpGUIMsgs.elems[2]->cResource::release();
        mpGUIMsgs.elems[2] = nullptr;
    }
    if (mpGUIMsgs.elems[3] == nullptr) {
        return;
    }
    mpGUIMsgs.elems[3]->cResource::release();
    mpGUIMsgs.elems[3] = nullptr;
}

__attribute__((weak)) MT_CTSTR uGUIBase::getGMDMsgValNum(u32 gmdIdx, u32 aryIdx, s32 val1, s32 val2, s32 val3) {
    DDON_STUB("uGUIBase::getGMDMsgValNum")
    return {};
}

void uGUIBase::setPS4ShareNG(bool IsNG) {
    if (IsNG) {
        if ((mBaseF & 512u) == 0) {
            static_cast<sGUIExt*>(sGUI::getInstance())->setPS4ShareNG(true);
        }
        mBaseF = mBaseF | 512u;
    } else {
        if ((mBaseF & 512u) != 0) {
            static_cast<sGUIExt*>(sGUI::getInstance())->setPS4ShareNG(false);
        }
        mBaseF = mBaseF & 0xFFFFFDFFu;
    }
}

__attribute__((weak)) MtVector2 uGUIBase::getDistanceBetweenInstances(cGUIInstance* pInstFrom, cGUIInstance* pInstTo) {
    DDON_STUB("uGUIBase::getDistanceBetweenInstances")
    __builtin_unreachable();
}

__attribute__((weak)) bool uGUIBase::autoWrapMessage(MT_STR pDst, MT_CTSTR pSrc, u32 srcLength, MtSize size, MtFloat2 region, s32 letterSpace, const rGUIFont* pFont) {
    DDON_STUB("uGUIBase::autoWrapMessage")
    return {};
}

bool uGUIBase::isNoRegistSystemCallBack() {
    if ((mGUIExtNetMgrUseId == 0) && (mpItemMgrRequest == nullptr)) {
        return !cQuestSvRequestManager::hasRequest(static_cast<const MtObject*>(this));
    }
    return false;
}

__attribute__((weak)) void uGUIBase::manageCommunicateServer() {
    DDON_STUB("uGUIBase::manageCommunicateServer")
    /* stub */
}

__attribute__((weak)) void uGUIBase::moveInput() {
}

__attribute__((weak)) void uGUIBase::moveEvent() {
}

void uGUIBase::setServerErrorEnd(u32 ErrorCode) {
    end();
}

void uGUIBase::setInputEvent(u32 EventId) {
    mInputEventId = EventId;
    switch (EventId - 4u) {
        case 0:
        {
            mSMENUdecide = true;
            break;
        }
        case 1:
        {
            mSMENUcancel = true;
            break;
        }
        case 2:
        {
            mSMENUchkout = true;
            break;
        }
        case 3:
        {
            mSMENUtopbtn = true;
            break;
        }
        case 4:
        {
            mSMENUdecide = true;
            mSMENUcancel = true;
            break;
        }
        default:
        {
            break;
        }
    }
}

bool uGUIBase::isMouseOver() const {
    u32 length = mControls.mLength;
    if (length != 0) {
        MtObject* * v0_2 = mControls.mpArray;
        for (u32 i = 0;;) {
            if (v0_2[i] != nullptr) {
                if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_2[i]) + 2836)) != 0) {
                    return true;
                }
            }
            if ((i + 1u) < length) {
                i = i + 1u;
            } else {
                break;
            }
        }
    }
    return false;
}

__attribute__((weak)) void uGUIBase::moveAutoAlpharingMenu() {
    DDON_STUB("uGUIBase::moveAutoAlpharingMenu")
    /* stub */
}

void uGUIBase::moveTextBox() {
    cReferenceUITextBox* const text_box = mpActiveTextBox;
    if (text_box == nullptr) {
        return;
    }
    const u32 event_id = getInputEvent();
    if (event_id == 55) {
        if (text_box->mState != uGUIBase::cReferenceUITextBox::STATE_NONE) {
            if (text_box->mpUnit != nullptr) {
                if (text_box == text_box->mpUnit->mpActiveTextBox) {
                    sKeyboardInterface::getInstance()->requestClose(true);
                    text_box->mpUnit->mpActiveTextBox = nullptr;
                }
            }
            text_box->mState = uGUIBase::cReferenceUITextBox::STATE_NONE;
            text_box->setFocus(text_box->mFocus);
        }
    } else {
        if (event_id == 54) {
            if (text_box->mState != uGUIBase::cReferenceUITextBox::STATE_NONE) {
                if (text_box->mpUnit != nullptr) {
                    if (text_box == text_box->mpUnit->mpActiveTextBox) {
                        sKeyboardInterface::getInstance()->requestClose(false);
                        text_box->mpUnit->mpActiveTextBox = nullptr;
                    }
                }
                text_box->mState = uGUIBase::cReferenceUITextBox::STATE_NONE;
                text_box->setFocus(text_box->mFocus);
            }
        }
    }
}

__attribute__((weak)) bool uGUIBase::onKeyEvent(const nInputTextKeyboardHook::Keycode& keycode) {
    DDON_STUB("uGUIBase::onKeyEvent")
    return {};
}

__attribute__((weak)) MtObject* uGUIBase::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIBase::getDTI() const {
    return uGUIBase::cReferenceUIBase::DTI;
}

__attribute__((weak)) void uGUIBase::cReferenceUIBase::setFocus(bool b) {
}

bool uGUIBase::cReferenceUIBase::isFocus() {
    return false;
}

s32 uGUIBase::cReferenceUIBase::getVItemNum() {
    return 1;
}

cGUIObjPolygon* uGUIBase::cReferenceUIBase::getMouseOverObject() {
    if (mpObjMouseOver == nullptr) {
        if (getInstance() != nullptr) {
            if (getInstance()->mpObjRoot != nullptr) {
                return static_cast<cGUIObjPolygon*>(getInstance()->mpObjRoot->getObjectFromName("mouseover"));
            }
        }
        return nullptr;
    } else {
        return mpObjMouseOver;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIBase::registerThis() {
    if (mIsRegister) {
        return;
    }
    uGUIBase* t0 = mpUnit;
    if (t0 == nullptr) {
        return;
    }
    u32 t1 = t0->mRefrenceUIArray.mLength;
    u32 t2 = t0->mRefrenceUIArray.mBufsiz;
    if (t1 < t2) {
        t0->mRefrenceUIArray.mLength = t1 + 1u;
        t0->mRefrenceUIArray.mpArray[t1] = static_cast<MtObject*>(this);
        mIsRegister = true;
    } else {
        void* t3 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t2 + 32u) * 8, 16u);
        memset(t3, 0, static_cast<size_t>(t2 + 32u) * 8);
        memcpy(t3, static_cast<const void*>(t0->mRefrenceUIArray.mpArray), static_cast<size_t>(t0->mRefrenceUIArray.mLength) * 8);
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(t0->mRefrenceUIArray.mpArray));
        t0->mRefrenceUIArray.mpArray = static_cast<MtObject* *>(t3);
        t0->mRefrenceUIArray.mBufsiz = t2 + 32u;
        u32 t4 = t0->mRefrenceUIArray.mLength;
        t0->mRefrenceUIArray.mLength = t4 + 1u;
        t0->mRefrenceUIArray.mpArray[t4] = static_cast<MtObject*>(this);
        mIsRegister = true;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIBase::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIBase::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUIBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIBase::MyDTI uGUIBase::cReferenceUIBase::DTI("uGUIBase::cReferenceUIBase", &::uGUIBase::cSupportInstAnim::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIBase::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIBase;
}

const MtDTI& uGUIBase::cSupportInstAnim::getDTI() const {
    return uGUIBase::cSupportInstAnim::DTI;
}

void uGUIBase::cSupportInstAnim::setExecute(bool b) {
    if (mpInstance == nullptr) {
        return;
    }
    mpInstance->setExecute(b);
}

__attribute__((weak)) bool uGUIBase::cSupportInstAnim::isExecute() {
    DDON_STUB("uGUIBase::cSupportInstAnim::isExecute")
    return {};
}

__attribute__((weak)) void uGUIBase::cSupportInstAnim::setSequence(u32 id, bool reset) {
    DDON_STUB("uGUIBase::cSupportInstAnim::setSequence")
    /* stub */
}

__attribute__((weak)) bool uGUIBase::cSupportInstAnim::setupPointerPos() {
    DDON_STUB("uGUIBase::cSupportInstAnim::setupPointerPos")
    return {};
}

void uGUIBase::cSupportInstAnim::setPointerPos(const MtVector2& v2Pos) {
    mPosPointer.x = v2Pos.x;
    mPosPointer.y = v2Pos.y;
}

MtVector2 uGUIBase::cSupportInstAnim::getPointerPos() {
    return mPosPointer;
}

void uGUIBase::cSupportInstAnim::setPosPointerReqAuto(bool bAuto) {
    setPosPointerReqAuto(bAuto, mpUnit->getBasePointerPriority());
}

void uGUIBase::cSupportInstAnim::setPosPointerReqAuto(bool bAuto, u32 uPrio) {
    mIsPosPointerReqAuto = bAuto;
    mPrioPointer = uPrio;
    setPointerPos(MtVector2::Zero);
}

void uGUIBase::cSupportInstAnim::update() {
    updatePointerPos();
}

inline uGUIBase::cSupportInstAnim::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cSupportInstAnim::MyDTI uGUIBase::cSupportInstAnim::DTI("uGUIBase::cSupportInstAnim", &::uGUIBase::cSupportBase::DTI, 56ul, 0u, 0u);

MtObject* uGUIBase::cSupportInstAnim::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cSupportInstAnim;
}

const MtDTI& uGUIBase::cSupportBase::getDTI() const {
    return uGUIBase::cSupportBase::DTI;
}

__attribute__((weak)) void uGUIBase::cSupportBase::operator delete(void* p_addr) {
    uGUIBase::cSupportBase::getAllocator()->memFree(p_addr);
}

inline uGUIBase::cSupportBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cSupportBase::MyDTI uGUIBase::cSupportBase::DTI("uGUIBase::cSupportBase", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* uGUIBase::cSupportBase::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cSupportBase;
}

const MtDTI& uGUIBase::cReferenceUITextBox::getDTI() const {
    return uGUIBase::cReferenceUITextBox::DTI;
}

uGUIBase::cReferenceUITextBox::cReferenceUITextBox() {
    DDON_STUB("uGUIBase::cReferenceUITextBox::cReferenceUITextBox")
    /* stub */
}

uGUIBase::cReferenceUITextBox::~cReferenceUITextBox() {
    if (mpUnit == nullptr) {
        return;
    }
    if (this != mpUnit->mpActiveTextBox) {
        return;
    }
    sKeyboardInterface::getInstance()->requestClose(true);
}

__attribute__((weak)) void uGUIBase::cReferenceUITextBox::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, const MtFloat2& size, MT_CTSTR pMsgInit, u32 uLenMaxText, bool bDispCharNum) {
    DDON_STUB("uGUIBase::cReferenceUITextBox::setup")
    /* stub */
}

void uGUIBase::cReferenceUITextBox::execute() {
    if (mState == STATE_NONE) {
        return;
    }
    if (mCtrlMouse == nullptr) {
        return;
    }
    mCtrlMouse->execute();
}

void uGUIBase::cReferenceUITextBox::update() {
    updatePointerPos();
    if (updateKeyboard()) {
        if (mpUnit != nullptr) {
            if (this == mpUnit->mpActiveTextBox) {
                mpUnit->mpActiveTextBox = nullptr;
            }
        }
    } else {
        if (mpUnit != nullptr) {
            if (!mpUnit->mIsWindowActive) {
                if (mState != STATE_NONE) {
                    if (this == mpUnit->mpActiveTextBox) {
                        sKeyboardInterface::getInstance()->requestClose(true);
                        mpUnit->mpActiveTextBox = nullptr;
                    }
                    mState = STATE_NONE;
                    setFocus(mFocus);
                }
            }
        } else {
            if (mState != STATE_NONE) {
                mState = STATE_NONE;
                setFocus(mFocus);
            }
        }
    }
}

void uGUIBase::cReferenceUITextBox::setMessage(MT_CTSTR pMsg) {
    if (pMsg != mMsg.ptr()) {
        if (mMsg.value != nullptr) {
            if (sceAtomicAdd32Relaxed(&mMsg.value->ref, -1) == 1) {
                (MtString::mpAllocator)->memFree(static_cast<void*>(mMsg.value));
            }
            mMsg.value = nullptr;
        }
        if (pMsg != nullptr) {
            size_t t0 = strlen(pMsg);
            if (static_cast<unsigned int>(t0) != 0) {
                void* t1 = (MtString::mpAllocator)->memAlloc(static_cast<size_t>(static_cast<unsigned int>(t0)) + 12, 16u);
                mMsg.value = static_cast<MtString::STRING*>(t1);
                mMsg.value->ref = 1;
                mMsg.value->length = static_cast<unsigned int>(t0);
                strcpy(reinterpret_cast<char*>(mMsg.value->str), pMsg);
                cGUIUtility::TruncateStr(mMsg, pMsg, mLenMaxText, 0u, static_cast<MT_CHAR>(0));
                resetMsgLength();
            } else {
                mMsg.value = nullptr;
                cGUIUtility::TruncateStr(mMsg, pMsg, mLenMaxText, 0u, static_cast<MT_CHAR>(0));
                resetMsgLength();
            }
        } else {
            mMsg.value = nullptr;
            cGUIUtility::TruncateStr(mMsg, pMsg, mLenMaxText, 0u, static_cast<MT_CHAR>(0));
            resetMsgLength();
        }
    } else {
        cGUIUtility::TruncateStr(mMsg, pMsg, mLenMaxText, 0u, static_cast<MT_CHAR>(0));
        resetMsgLength();
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUITextBox::resetMsgLength() {
    DDON_STUB("uGUIBase::cReferenceUITextBox::resetMsgLength")
    /* stub */
}

void uGUIBase::cReferenceUITextBox::setFocus(bool b) {
    mFocus = b;
    if (mState == STATE_NONE) {
        setSequence(static_cast<u32>((b * 3) + 1), true);
    } else {
        setSequence(5u, true);
    }
}

bool uGUIBase::cReferenceUITextBox::isFocus() {
    return mFocus;
}

__attribute__((weak)) void uGUIBase::cReferenceUITextBox::setFontSize(s32 fontSize) {
    DDON_STUB("uGUIBase::cReferenceUITextBox::setFontSize")
    /* stub */
}

void uGUIBase::cReferenceUITextBox::setLayout(u32 layout) {
    if (mpObjMsgText == nullptr) {
        return;
    }
    mpObjMsgText->setLayout(layout);
    mLayout = layout;
}

bool uGUIBase::cReferenceUITextBox::isWakeupKeyboard() const {
    return mState != STATE_NONE;
}

bool uGUIBase::cReferenceUITextBox::isEndKeyboard() const {
    return mState == STATE_NONE;
}

bool uGUIBase::cReferenceUITextBox::wakeupKeyboard() {
    if (mState == STATE_NONE) {
        setSequence(5u, true);
        if (tryWakeupKeyboard()) {
            mState = STATE_OPEN;
        } else {
            mState = STATE_WAIT;
        }
    }
    return true;
}

bool uGUIBase::cReferenceUITextBox::wakeupKeyboard(s32 keyboardType) {
    mKeyboardType = keyboardType;
    if (mState == STATE_NONE) {
        setSequence(5u, true);
        if (tryWakeupKeyboard()) {
            mState = STATE_OPEN;
        } else {
            mState = STATE_WAIT;
        }
    }
    return true;
}

__attribute__((weak)) bool uGUIBase::cReferenceUITextBox::wakeupKeyboard(s32 keyboardType, MT_CTSTR initText) {
    DDON_STUB("uGUIBase::cReferenceUITextBox::wakeupKeyboard")
    return {};
}

__attribute__((weak)) bool uGUIBase::cReferenceUITextBox::updateKeyboard() {
    DDON_STUB("uGUIBase::cReferenceUITextBox::updateKeyboard")
    return {};
}

void uGUIBase::cReferenceUITextBox::closeKeyboard(bool isCancel) {
    if (mState == STATE_NONE) {
        return;
    }
    if (mpUnit != nullptr) {
        if (this == mpUnit->mpActiveTextBox) {
            sKeyboardInterface::getInstance()->requestClose(isCancel);
            mpUnit->mpActiveTextBox = nullptr;
        }
    }
    mState = STATE_NONE;
    setFocus(mFocus);
}

__attribute__((weak)) void uGUIBase::cReferenceUITextBox::resetTextSize() {
    DDON_STUB("uGUIBase::cReferenceUITextBox::resetTextSize")
    /* stub */
}

void uGUIBase::cReferenceUITextBox::addMouseTouchList(cControl* pOwner, s32 pos, s32 vol, bool autoErase) {
    if (pOwner == nullptr) {
        return;
    }
    if (mpObjMouseOver == nullptr) {
        return;
    }
    if (autoErase) {
        if (vol > -1) {
            pOwner->eraseMouseTouchListPosVol(pos, vol);
        } else {
            pOwner->eraseMouseTouchList(pos);
        }
    }
    pOwner->addMouseTouchList(static_cast<cGUIInstance*>(mpInstance), static_cast<cGUIObject*>(mpObjMouseOver), pos, static_cast<cGUIObject*>(nullptr), 1u, 5u, vol);
}

__attribute__((weak)) bool uGUIBase::cReferenceUITextBox::tryWakeupKeyboard() {
    if (mpUnit != nullptr) {
        if (mpUnit->mpActiveTextBox != nullptr) {
            return false;
        } else {
            if (sKeyboardInterface::getInstance()->isBusy()) {
                return false;
            } else {
                const sKeyboardInterface::KEYBOARD_TYPE keyboard_type = static_cast<const sKeyboardInterface::KEYBOARD_TYPE>(mKeyboardType);
                sKeyboardInterface::getInstance()->setKeyboardSetting(keyboard_type, "", mMsg.ptr(), static_cast<s32>(mLenMaxText));
                if (sKeyboardInterface::getInstance()->requestOpenPad(0u, static_cast<cInputTextKeyboardHook*>(&mpUnit->mInputTextKeyboardHook))) {
                    sGUI* t0 = sGUI::getInstance();
                    uGUIBase* t1 = mpUnit;
                    cGUIObjMessage* t2 = mpObjMsgText;
                    static_cast<sGUIExt*>(t0)->setInputTextProperty(t2, t1->mPos, t1->getScaleForDefaultResolution(1.0f), 0.0f, static_cast<const cGUIObjPolygon*>(nullptr));
                    mpUnit->mpActiveTextBox = this;
                    return true;
                } else {
                    return false;
                }
            }
        }
    } else {
        return false;
    }
}

void uGUIBase::cReferenceUITextBox::setSequence(u32 id, bool reset) {
    this->uGUIBase::cSupportInstAnim::setSequence(id, reset);
    resetTextSize();
    if (mpObjMsgText == nullptr) {
        return;
    }
    mpObjMsgText->setAutoWrap(mAutoWrap);
    if (mDefaultFontSize.wh != mFontSize.wh) {
        mpObjMsgText->setFontSize(mFontSize);
        mpObjMsgText->setLayout(mLayout);
        if (mMsg.value != nullptr) {
            mpObjMsgText->setMessage(mMsg.ptr(), mMsg.value->length);
        } else {
            mpObjMsgText->setMessage(mMsg.ptr(), 0u);
        }
    }
}

inline uGUIBase::cReferenceUITextBox::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUITextBox::MyDTI uGUIBase::cReferenceUITextBox::DTI("uGUIBase::cReferenceUITextBox", &::uGUIBase::cReferenceUIBase::DTI, 360ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUITextBox::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUITextBox::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cAdjustableWindow::getDTI() const {
    return uGUIBase::cAdjustableWindow::DTI;
}

uGUIBase::cAdjustableWindow::cAdjustableWindow() {
    DDON_STUB("uGUIBase::cAdjustableWindow::cAdjustableWindow")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cAdjustableWindow::setup(uGUIBase* pUnit, cGUIInstance* pInst, u32 LT, u32 LC, u32 LB, u32 CT, u32 CC, u32 CB, u32 RT, u32 RC, u32 RB) {
    DDON_STUB("uGUIBase::cAdjustableWindow::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cAdjustableWindow::setWindowSize(uGUIBase::cAdjustableWindow::CELL align, MtSize size, const MtFloat2& ofs, uGUIBase::cAdjustableWindow::CELL ctrlpt) {
    DDON_STUB("uGUIBase::cAdjustableWindow::setWindowSize")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cAdjustableWindow::setWindowSizeDefaultPlus(uGUIBase::cAdjustableWindow::CELL align, const MtSize& size, const MtFloat2& ofs, uGUIBase::cAdjustableWindow::CELL ctrlpt) {
    DDON_STUB("uGUIBase::cAdjustableWindow::setWindowSizeDefaultPlus")
    /* stub */
}

__attribute__((weak)) MtSize uGUIBase::cAdjustableWindow::getWindowSize() const {
    DDON_STUB("uGUIBase::cAdjustableWindow::getWindowSize")
    __builtin_unreachable();
}

__attribute__((weak)) MtSize uGUIBase::cAdjustableWindow::getDefaultWindowSize() const {
    DDON_STUB("uGUIBase::cAdjustableWindow::getDefaultWindowSize")
    __builtin_unreachable();
}

__attribute__((weak)) void uGUIBase::cAdjustableWindow::_setWindowData(uGUIBase::cAdjustableWindow::CELL align, MtSize& size, MtFloat2& ofs) {
    DDON_STUB("uGUIBase::cAdjustableWindow::_setWindowData")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cAdjustableWindow::_setup9(uGUIBase* pUnit, cGUIInstance* pInst, const u32* table, u32 arrayNum, u32 stIdx) {
    DDON_STUB("uGUIBase::cAdjustableWindow::_setup9")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cAdjustableWindow::_setup8(uGUIBase* pUnit, cGUIInstance* pInst, const u32* table, u32 arrayNum, u32 stIdx) {
    DDON_STUB("uGUIBase::cAdjustableWindow::_setup8")
    /* stub */
}

inline uGUIBase::cAdjustableWindow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cAdjustableWindow::MyDTI uGUIBase::cAdjustableWindow::DTI("uGUIBase::cAdjustableWindow", &::uGUIBase::cSupportBase::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cAdjustableWindow::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cAdjustableWindow::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIWndwDrag::getDTI() const {
    return uGUIBase::cReferenceUIWndwDrag::DTI;
}

uGUIBase::cReferenceUIWndwDrag::cReferenceUIWndwDrag() {
    mDragOld = false;
    mDragEnable = false;
    mpObjPolygon = nullptr;
    mpInstNull = nullptr;
    mPosClick.z = 0.0f;
    mPosClick.pad_ = 0.0f;
    mPosClick.x = 0.0f;
    mPosClick.y = 0.0f;
}

__attribute__((weak)) void uGUIBase::cReferenceUIWndwDrag::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, MtFloat2 size, cGUIInstNull* pInstNull) {
    DDON_STUB("uGUIBase::cReferenceUIWndwDrag::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIWndwDrag::update() {
}

__attribute__((weak)) void uGUIBase::cReferenceUIWndwDrag::setCollisionSize(MtFloat2 size) {
    DDON_STUB("uGUIBase::cReferenceUIWndwDrag::setCollisionSize")
    /* stub */
}

inline uGUIBase::cReferenceUIWndwDrag::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIWndwDrag::MyDTI uGUIBase::cReferenceUIWndwDrag::DTI("uGUIBase::cReferenceUIWndwDrag", &::uGUIBase::cReferenceUIBase::DTI, 128ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIWndwDrag::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIWndwDrag;
}

const MtDTI& uGUIBase::cKeepInScreen::getDTI() const {
    return uGUIBase::cKeepInScreen::DTI;
}

__attribute__((noinline)) uGUIBase::cKeepInScreen::~cKeepInScreen() {
    DDON_STUB("uGUIBase::cKeepInScreen::~cKeepInScreen")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cKeepInScreen::setup(uGUIBase* pGUI, cGUIInstance* pInst, bool bEnable) {
    DDON_STUB("uGUIBase::cKeepInScreen::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cKeepInScreen::update() {
    DDON_STUB("uGUIBase::cKeepInScreen::update")
    /* stub */
}

inline uGUIBase::cKeepInScreen::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cKeepInScreen::MyDTI uGUIBase::cKeepInScreen::DTI("uGUIBase::cKeepInScreen", &::MtObject::DTI, 40ul, 0u, 1u);

MtObject* uGUIBase::cKeepInScreen::MyDTI::newInstance() const {
    return nullptr;
}

bool uGUIBase::InputTextKeyboardHook::onKeyEvent(const nInputTextKeyboardHook::Keycode& keycode) {
    if (mOwner != nullptr) {
        return mOwner->onKeyEvent(keycode);
    } else {
        return false;
    }
}

const MtDTI& uGUIBase::cReferenceUIIconJob::getDTI() const {
    return uGUIBase::cReferenceUIIconJob::DTI;
}

uGUIBase::cReferenceUIIconJob::cReferenceUIIconJob() {
    mJobId = 0;
    mIsFocus = false;
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconJob::setup(uGUIBase* pBase, cGUIInstance* pInst) {
    DDON_STUB("uGUIBase::cReferenceUIIconJob::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconJob::set(u32 jobId) {
    DDON_STUB("uGUIBase::cReferenceUIIconJob::set")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconJob::setWithSecret(u32 jobId) {
    DDON_STUB("uGUIBase::cReferenceUIIconJob::setWithSecret")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconJob::setRole(u32 roleId) {
    DDON_STUB("uGUIBase::cReferenceUIIconJob::setRole")
    /* stub */
}

void uGUIBase::cReferenceUIIconJob::setEntryCustom() {
    if (mpInstance != nullptr) {
        mpInstance->setCurrentFrame(51.0f, true);
    }
    mJobId = 51;
}

void uGUIBase::cReferenceUIIconJob::noBaseSequence() {
    if (mpInstance == nullptr) {
        return;
    }
    mpInstance->setSequenceId(0xF4240u);
}

void uGUIBase::cReferenceUIIconJob::setFocus(bool isFocus) {
    mIsFocus = isFocus;
}

bool uGUIBase::cReferenceUIIconJob::isFocus() {
    return mIsFocus;
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconJob::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIIconJob::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUIIconJob::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconJob::MyDTI uGUIBase::cReferenceUIIconJob::DTI("uGUIBase::cReferenceUIIconJob", &::uGUIBase::cReferenceUIBase::DTI, 88ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconJob::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconJob;
}

const MtDTI& uGUIBase::cScrollListItemBase::getDTI() const {
    return uGUIBase::cScrollListItemBase::DTI;
}

__attribute__((weak)) void uGUIBase::cScrollListItemBase::operator delete(void* p_addr) {
    uGUIBase::cScrollListItemBase::getAllocator()->memFree(p_addr);
}

inline uGUIBase::cScrollListItemBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cScrollListItemBase::MyDTI uGUIBase::cScrollListItemBase::DTI("uGUIBase::cScrollListItemBase", &::cUIObject::DTI, 88ul, 0u, 0u);

MtObject* uGUIBase::cScrollListItemBase::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cScrollListItemBase;
}

const MtDTI& uGUIBase::cScrollListInfoBase::getDTI() const {
    return uGUIBase::cScrollListInfoBase::DTI;
}

void* uGUIBase::cScrollListInfoBase::operator new(size_t sz, u32 align) {
    return uGUIBase::cScrollListInfoBase::getAllocator()->memAlloc(sz, align, uGUIBase::cScrollListInfoBase::DTI.getID());
}

void uGUIBase::cScrollListInfoBase::addMouseTouchList(cControl* pCtrl, s32 pos) {
    if (pCtrl == nullptr) {
        return;
    }
    if (mpItem == nullptr) {
        return;
    }
    adjustMouseCollisionSize(mpItem->mpObjMouseCollision);
    pCtrl->addMouseTouchListLight(mpItem->mpInstMouseCollision, mpItem->mpObjMouseCollision, pos, -1);
}

void uGUIBase::cScrollListInfoBase::adjustMouseCollisionSize(cGUIObject* objMouseCollision) {
    if (objMouseCollision == nullptr) {
        return;
    }
    cGUIUtility::AdjustMouseCollisionSize(static_cast<cGUIObjPolygon*>(objMouseCollision), mMouseBottomPos - mMouseTopPos);
}

inline uGUIBase::cScrollListInfoBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cScrollListInfoBase::MyDTI uGUIBase::cScrollListInfoBase::DTI("uGUIBase::cScrollListInfoBase", &::cUIObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cScrollListInfoBase::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cScrollListInfoBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIPullDown::getDTI() const {
    return uGUIBase::cReferenceUIPullDown::DTI;
}

void* uGUIBase::cReferenceUIPullDown::operator new(size_t sz, u32 align) {
    return uGUIBase::cReferenceUIPullDown::getAllocator()->memAlloc(sz, align, uGUIBase::cReferenceUIPullDown::DTI.getID());
}

uGUIBase::cReferenceUIPullDown::cReferenceUIPullDown() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::cReferenceUIPullDown")
    /* stub */
}

__attribute__((noinline)) uGUIBase::cReferenceUIPullDown::~cReferenceUIPullDown() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::~cReferenceUIPullDown")
    /* stub */
}

void uGUIBase::cReferenceUIPullDown::setup(uGUIBase* pBase, u32 msg_pulldownID, u32 mask_pulldownID, u32 windowID, u32 cursorID, u32 mask_pulldownlistID, u32 msg_listID, u32 null_pull_scrollID, u32 null_scroll01ID, u32 scrbarID, f32 uiWidth, s32 visibleSize) {
    mpUnit = pBase;
    if (pBase != nullptr) {
        unsigned long t0 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pBase) + 0);
        cGUIInstance* pMsgPulldown = pBase->getInstance(msg_pulldownID, false);
        uGUIBase* t2 = mpUnit;
        if (t2 != nullptr) {
            cGUIInstance* pMaskPulldown = t2->getInstance(mask_pulldownID, false);
            uGUIBase* t4 = mpUnit;
            if (t4 != nullptr) {
                cGUIInstance* pWindow = t4->getInstance(windowID, false);
                uGUIBase* t6 = mpUnit;
                if (t6 != nullptr) {
                    cGUIInstance* pCursor = t6->getInstance(cursorID, false);
                    uGUIBase* t8 = mpUnit;
                    if (t8 != nullptr) {
                        cGUIInstance* pMaskPulldownList = t8->getInstance(mask_pulldownlistID, false);
                        uGUIBase* t10 = mpUnit;
                        if (t10 != nullptr) {
                            cGUIInstance* t11 = t10->getInstance(msg_listID, false);
                            uGUIBase* t13 = mpUnit;
                            if (t13 != nullptr) {
                                cGUIInstance* pNullPullScrollId = t13->getInstance(null_pull_scrollID, false);
                                uGUIBase* t15 = mpUnit;
                                if (t15 != nullptr) {
                                    cGUIInstance* pNullScroll01Id = t15->getInstance(null_scroll01ID, false);
                                    uGUIBase* t17 = mpUnit;
                                    if (t17 != nullptr) {
                                        cGUIInstance* pScrbar = t17->getInstance(scrbarID, false);
                                        setup(pBase, pMsgPulldown, pMaskPulldown, pWindow, pCursor, pMaskPulldownList, t11, pNullPullScrollId, pNullScroll01Id, pScrbar, uiWidth, visibleSize);
                                    } else {
                                        setup(pBase, pMsgPulldown, pMaskPulldown, pWindow, pCursor, pMaskPulldownList, t11, pNullPullScrollId, pNullScroll01Id, static_cast<cGUIInstance*>(nullptr), uiWidth, visibleSize);
                                    }
                                } else {
                                    setup(pBase, pMsgPulldown, pMaskPulldown, pWindow, pCursor, pMaskPulldownList, t11, pNullPullScrollId, static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), uiWidth, visibleSize);
                                }
                            } else {
                                setup(pBase, pMsgPulldown, pMaskPulldown, pWindow, pCursor, pMaskPulldownList, t11, static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), uiWidth, visibleSize);
                            }
                        } else {
                            setup(pBase, pMsgPulldown, pMaskPulldown, pWindow, pCursor, pMaskPulldownList, static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), uiWidth, visibleSize);
                        }
                    } else {
                        setup(pBase, pMsgPulldown, pMaskPulldown, pWindow, pCursor, static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), uiWidth, visibleSize);
                    }
                } else {
                    setup(pBase, pMsgPulldown, pMaskPulldown, pWindow, static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), uiWidth, visibleSize);
                }
            } else {
                setup(pBase, pMsgPulldown, pMaskPulldown, static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), uiWidth, visibleSize);
            }
        } else {
            setup(pBase, pMsgPulldown, static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), uiWidth, visibleSize);
        }
    } else {
        setup(pBase, static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), static_cast<cGUIInstance*>(nullptr), uiWidth, visibleSize);
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::setup(uGUIBase* pBase, cGUIInstance* pMsgPulldown, cGUIInstance* pMaskPulldown, cGUIInstance* pWindow, cGUIInstance* pCursor, cGUIInstance* pMaskPulldownList, cGUIInstance* pMsgList, cGUIInstance* pNullPullScrollId, cGUIInstance* pNullScroll01Id, cGUIInstance* pScrbar, f32 uiWidth, s32 visibleSize) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::addMessage(MT_CTSTR str, bool isAnalyze) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::addMessage")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::setMessageColor(u32 idx, MtColor color) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::setMessageColor")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::update() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::update")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::execute() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::execute")
    /* stub */
}

bool uGUIBase::cReferenceUIPullDown::moveEvent() {
    if (mState == STATE_IDLE) {
        if (!mIsInputEvent && !mScrList.isInputEvent()) {
            return false;
        }
        if (mpUnit->mInputEventId <= 51u) {
            if (((0x2100000000000ul >> static_cast<unsigned long>(mpUnit->mInputEventId & 63u)) & 1ul) == 0) {
                if (((0x8200000000000ul >> static_cast<unsigned long>(mpUnit->mInputEventId & 63u)) & 1ul) != 0) {
                    mCancel = true;
                    mState = STATE_CLOSE_INIT;
                    return true;
                } else {
                    if (((0x4400000000000ul >> static_cast<unsigned long>(mpUnit->mInputEventId & 63u)) & 1ul) != 0) {
                        mDecide = true;
                        mState = STATE_CLOSE_INIT;
                        if (mScrList.mpVCtrl != nullptr) {
                            if (mScrList.mpVCtrl->getCurrentPos() < static_cast<int>(mMsgArray.mLength)) {
                                changeTitleText(static_cast<u32>(mScrList.mpVCtrl->getCurrentPos()));
                            }
                        } else {
                            if (static_cast<int>(mMsgArray.mLength) > 0) {
                                changeTitleText(0u);
                            }
                        }
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                if (mScrList.mpVCtrl != nullptr) {
                    mScrList.setListPos(static_cast<u32>(mScrList.mpVCtrl->getCurrentPos()), false);
                } else {
                    mScrList.setListPos(0u, false);
                }
                return true;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::deleteMsgList() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::deleteMsgList")
    /* stub */
}

void uGUIBase::cReferenceUIPullDown::close(bool isAnim) {
    if (isAnim) {
        if (mState != STATE_NONE) {
            mState = STATE_CLOSE_INIT;
        }
    } else {
        if (mState != STATE_NONE) {
            mState = STATE_NONE;
            mMovePos.mPos.x = mEndPos;
            mMovePos.mPos.y = 0.0f;
            mMovePos.mTimer = 0.0f;
            if (mData.mpINST_Null_pull_scroll != nullptr) {
                mData.mpINST_Null_pull_scroll->setPositionY(mEndPos);
            }
        }
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::setFocus(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::setFocus")
    /* stub */
}

bool uGUIBase::cReferenceUIPullDown::isFocus() {
    return mFocus;
}

void uGUIBase::cReferenceUIPullDown::setVisibleSize(s32 n) {
    mVisibleSize = n;
    mListSizeH = mCursor.mDistY * static_cast<float>(n);
    resetWindowSize();
    createDuplicate(static_cast<u32>(mVisibleSize));
    updateScrollList(mMsgArray.size());
    if (mData.mpINST_Null_pull_scroll == nullptr) {
        return;
    }
    mData.mpINST_Null_pull_scroll->setPositionY(mEndPos);
}

void uGUIBase::cReferenceUIPullDown::reqSE(uGUIBase::cReferenceUIPullDown::SE type) {
    if (type == SE_CLOSE) {
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 11u);
    } else {
        if (type == SE_OPEN) {
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 6u);
        }
    }
}

void uGUIBase::cReferenceUIPullDown::changeTitleText(u32 idx) {
    if (idx < mMsgArray.mLength) {
        mCursorIdx = static_cast<s32>(idx);
        setTitleText(static_cast<const cMsg*>(mMsgArray.getBuffer()[static_cast<int>(idx)]));
    }
}

u32 uGUIBase::cReferenceUIPullDown::addMouseTouchList(cControl* pOwner, s32 pos, s32 vol, bool autoErase) {
    if (pOwner != nullptr) {
        if (mData.mpOBJ_msg_pulldown_mouseover != nullptr) {
            if (autoErase) {
                if (vol > -1) {
                    pOwner->eraseMouseTouchListPosVol(pos, vol);
                } else {
                    pOwner->eraseMouseTouchList(pos);
                }
            }
            return pOwner->addMouseTouchList(static_cast<cGUIInstance*>(mData.mpINST_msg_pulldown), static_cast<cGUIObject*>(mData.mpOBJ_msg_pulldown_mouseover), pos, static_cast<cGUIObject*>(nullptr), 1u, 1u, vol);
        }
    }
    return 0xFFFFFFFF;
}

void uGUIBase::cReferenceUIPullDown::setForbid(bool bForbid, s32 sIdx) {
    mIsForbid = bForbid;
    if (sIdx > -1) {
        if (mScrList.mpVCtrl != nullptr) {
            mScrList.mpVCtrl->setCurrentPos(sIdx, false);
        }
        changeTitleText(static_cast<u32>(sIdx));
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::updateString(uGUIBase::cReferenceUIPullDown::cData* pData, u32 curIdx) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::updateString")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::updatePointerPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::createDuplicate(u32 num) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::createDuplicate")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::initScrollList(u32 startIdx) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::initScrollList")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::updateScrollList(u32 listNum) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::updateScrollList")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::resetFormSize() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::resetFormSize")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::resetWindowSize() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::resetWindowSize")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::setSequenceIdEx(cGUIInstAnimation* pInst, u32 id) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::setSequenceIdEx")
    /* stub */
}

__attribute__((weak)) f32 uGUIBase::cReferenceUIPullDown::setupObject(f32 width) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::setupObject")
    return {};
}

__attribute__((weak)) uGUIBase::cReferenceUIPullDown::cData* uGUIBase::cReferenceUIPullDown::newData() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::newData")
    return nullptr;
}

__attribute__((weak)) uGUIBase::cReferenceUIPullDown::cMsg* uGUIBase::cReferenceUIPullDown::newMsg() {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::newMsg")
    return nullptr;
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::setTitleText(const uGUIBase::cReferenceUIPullDown::cMsg* msg) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::setTitleText")
    /* stub */
}

inline uGUIBase::cReferenceUIPullDown::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIPullDown::MyDTI uGUIBase::cReferenceUIPullDown::DTI("uGUIBase::cReferenceUIPullDown", &::uGUIBase::cReferenceUIBase::DTI, 1552ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIPullDown::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIPullDown::cData::getDTI() const {
    return uGUIBase::cReferenceUIPullDown::cData::DTI;
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDown::cData::setup(uGUIBase::cReferenceUIPullDown* pPar, cGUIInstance* pInstance) {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::cData::setup")
    /* stub */
}

inline uGUIBase::cReferenceUIPullDown::cData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIPullDown::cData::MyDTI uGUIBase::cReferenceUIPullDown::cData::DTI("uGUIBase::cReferenceUIPullDown::cData", &::MtObject::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIPullDown::cData::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::cData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIPullDown::cScrollListItemBasePD::getDTI() const {
    return uGUIBase::cReferenceUIPullDown::cScrollListItemBasePD::DTI;
}

MtObject* uGUIBase::cReferenceUIPullDown::cScrollListItemBasePD::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIPullDown::cScrollListItemBasePD;
}

const MtDTI& uGUIBase::cReferenceUIPullDown::cMsg::getDTI() const {
    return uGUIBase::cReferenceUIPullDown::cMsg::DTI;
}

uGUIBase::cReferenceUIPullDown::cMsg::~cMsg() {
}

inline uGUIBase::cReferenceUIPullDown::cMsg::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIPullDown::cMsg::MyDTI uGUIBase::cReferenceUIPullDown::cMsg::DTI("uGUIBase::cReferenceUIPullDown::cMsg", &::MtObject::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIPullDown::cMsg::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIPullDown::cMsg::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIVlCursor::getDTI() const {
    return uGUIBase::cReferenceUIVlCursor::DTI;
}

uGUIBase::cReferenceUIVlCursor::cReferenceUIVlCursor() {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::cReferenceUIVlCursor")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIVlCursor::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, const MtFloat2& size, f32 fDistY) {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIVlCursor::setType(uGUIBase::cReferenceUIVlCursor::TYPE type) {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::setType")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIVlCursor::update() {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::update")
    /* stub */
}

void uGUIBase::cReferenceUIVlCursor::setPointerPosOfs(const MtVector2& v2Ofs) {
    if (mpUnit != nullptr) {
        f32 t0 = cGUIUtility::getScaleForDefaultResolution(1.0f);
        const f32 t1 = v2Ofs.y;
        mPosPointerOfs.x = v2Ofs.x * t0;
        mPosPointerOfs.y = t1 * t0;
    } else {
        mPosPointerOfs.x = v2Ofs.x;
        mPosPointerOfs.y = v2Ofs.y;
    }
}

MtVector2 uGUIBase::cReferenceUIVlCursor::getPointerPos() {
    MtVector2 result;
    f32 t0 = mPosPointer.y;
    f32 t1 = mPosPointerOfs.y;
    result.x = mPosPointer.x + mPosPointerOfs.x;
    result.y = t0 + t1;
    return result;
}

__attribute__((weak)) void uGUIBase::cReferenceUIVlCursor::setCtrlPos(s32 sPos, bool isImmediate) {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::setCtrlPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIVlCursor::setCtrlPos(s32 sPos, f32 dPos, bool isImmediate) {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::setCtrlPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIVlCursor::setSize(MtFloat2 size, f32 dist) {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::setSize")
    /* stub */
}

__attribute__((weak)) MtFloat2 uGUIBase::cReferenceUIVlCursor::getSize() {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::getSize")
    __builtin_unreachable();
}

__attribute__((weak)) void uGUIBase::cReferenceUIVlCursor::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUIVlCursor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIVlCursor::MyDTI uGUIBase::cReferenceUIVlCursor::DTI("uGUIBase::cReferenceUIVlCursor", &::uGUIBase::cSupportInstAnim::DTI, 176ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIVlCursor::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIVlCursor::MyDTI::newInstance")
    return nullptr;
}

uGUIBase::cScrollList::cScrollList() {
    DDON_STUB("uGUIBase::cScrollList::cScrollList")
    /* stub */
}

void uGUIBase::cScrollList::clearInfo() {
    if (mInfoArray.mAutoDelete) {
        if (mInfoArray.mLength != 0) {
            u32 v0_0 = mInfoArray.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mInfoArray.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mInfoArray.mpArray[i0_3];
                    v1_0 = mInfoArray.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mInfoArray.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mInfoArray.mpArray));
        }
        mInfoArray.mpArray = nullptr;
        mInfoArray.mBufsiz = 0;
        mInfoArray.mLength = 0;
    } else {
        if (mInfoArray.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mInfoArray.mpArray));
        }
        mInfoArray.mpArray = nullptr;
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 280) = 0;
    }
    if (mVisualInfoArray.mAutoDelete) {
        if (mVisualInfoArray.mLength != 0) {
            u32 v6_0 = mVisualInfoArray.mLength;
            unsigned int i6_3 = 0;
            u32 v7_0;
            for (;;) {
                if (mVisualInfoArray.mpArray[i6_3] == nullptr) {
                    v7_0 = v6_0;
                } else {
                    delete mVisualInfoArray.mpArray[i6_3];
                    v7_0 = mVisualInfoArray.mLength;
                }
                if ((i6_3 + 1u) < v7_0) {
                    v6_0 = v7_0;
                    i6_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mVisualInfoArray.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mVisualInfoArray.mpArray));
        }
        mVisualInfoArray.mpArray = nullptr;
        mVisualInfoArray.mBufsiz = 0;
        mVisualInfoArray.mLength = 0;
    } else {
        if (mVisualInfoArray.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mVisualInfoArray.mpArray));
        }
        mVisualInfoArray.mpArray = nullptr;
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 344) = 0;
    }
    uGUIBase* v12_9 = mpOwner;
    if (v12_9 != nullptr) {
        cVerticalList* v12_8 = mpVCtrl;
        if (v12_8 != nullptr) {
            u32 v12_0 = v12_9->mControls.mLength;
            if (v12_0 != 0) {
                MtObject* * v12_1 = v12_9->mControls.mpArray;
                unsigned int i12_3 = 0;
                u32 v15_0;
                unsigned int v15_8;
                unsigned int v16_1;
                u32 v16_2;
                unsigned int v16_3;
                for (;;) {
                    if (v12_8 == v12_1[i12_3]) {
                        if (!v12_9->mControls.mAutoDelete) {
                            v15_0 = v12_0;
                        } else {
                            delete v12_8;
                            v15_0 = v12_9->mControls.mLength;
                        }
                        v15_8 = i12_3 + 1u;
                        if (v15_8 < v15_0) {
                            v16_1 = v15_8;
                            v16_2 = v15_0;
                            v16_3 = i12_3;
                            for (;;) {
                                v12_9->mControls.mpArray[v16_3] = v12_9->mControls.mpArray[v16_1];
                                if (v16_2 != (v16_1 + 1u)) {
                                    v16_3 = v16_1;
                                    v16_1 = v16_1 + 1u;
                                } else {
                                    break;
                                }
                            }
                        }
                        v12_9->mControls.mLength = v15_0 - 1u;
                        break;
                    } else {
                        if ((i12_3 + 1u) < v12_0) {
                            i12_3 = i12_3 + 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
            delete v12_8;
        }
        mpVCtrl = nullptr;
    }
    mDispNum = 0;
}

__attribute__((weak)) void uGUIBase::cScrollList::setupList(f32 bar_length, f32 disp_range, f32 visible_top, f32 visible_bottom, s32 currentPos, f32 sliderPos, bool useLR) {
    DDON_STUB("uGUIBase::cScrollList::setupList")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollList::setupList(cGUIInstNull* pInstMask, u32 topObjId, u32 centerObjId, u32 bottomObjId, s32 currentPos, f32 sliderPos, bool useLR) {
    DDON_STUB("uGUIBase::cScrollList::setupList")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollList::clear() {
    DDON_STUB("uGUIBase::cScrollList::clear")
    /* stub */
}

void uGUIBase::cScrollList::setListPos(bool isImmediate) {
    if (mpVCtrl != nullptr) {
        setListPos(static_cast<u32>(mpVCtrl->getCurrentPos()), isImmediate);
    } else {
        setListPos(0u, isImmediate);
    }
}

__attribute__((weak)) void uGUIBase::cScrollList::setListPos(u32 pos, bool isImmediate) {
    DDON_STUB("uGUIBase::cScrollList::setListPos")
    /* stub */
}

__attribute__((weak)) bool uGUIBase::cScrollList::isVisiblePos() {
    DDON_STUB("uGUIBase::cScrollList::isVisiblePos")
    return {};
}

bool uGUIBase::cScrollList::update(f32 delta_time) {
    bool t0 = mIsExecuteCtrl;
    mIsExecuteCtrl = false;
    mIsInputEvent = false;
    bool t1 = mClearFirst;
    mClearFirst = false;
    bool t2 = mIsNoScrollNoCursor;
    if (t2) {
        return false;
    } else {
        bool t3 = mIsFocusCursor;
        if (t3) {
            updateCursor();
            bool t4 = mIsAutoDispPointer;
            if (t4) {
                if (!t1) {
                    u32 t5 = mListPos;
                    u32 t6 = mInfoArray.mLength;
                    if (t5 < t6) {
                        MtObject* * t7 = mInfoArray.getBuffer();
                        MtObject* t8 = t7[static_cast<int>(t5)];
                        if (t8 != nullptr) {
                            unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 8);
                            setupPointerPos(reinterpret_cast<cScrollListItemBase*>(t9));
                            bool t10 = mIsAutoUpdateMouseOperation;
                            if (t0 || t10) {
                                bool t11 = updateMouseOperation(delta_time);
                                if (!t11) {
                                    if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                        updateListItem();
                                        return true;
                                    } else {
                                        return false;
                                    }
                                } else {
                                    return true;
                                }
                            } else {
                                if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                    updateListItem();
                                    return true;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            bool t10 = mIsAutoUpdateMouseOperation;
                            if (t0 || t10) {
                                bool t11 = updateMouseOperation(delta_time);
                                if (!t11) {
                                    if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                        updateListItem();
                                        return true;
                                    } else {
                                        return false;
                                    }
                                } else {
                                    return true;
                                }
                            } else {
                                if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                    updateListItem();
                                    return true;
                                } else {
                                    return false;
                                }
                            }
                        }
                    } else {
                        bool t10 = mIsAutoUpdateMouseOperation;
                        if (t0 || t10) {
                            bool t11 = updateMouseOperation(delta_time);
                            if (!t11) {
                                if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                    updateListItem();
                                    return true;
                                } else {
                                    return false;
                                }
                            } else {
                                return true;
                            }
                        } else {
                            if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                updateListItem();
                                return true;
                            } else {
                                return false;
                            }
                        }
                    }
                } else {
                    bool t10 = mIsAutoUpdateMouseOperation;
                    if (t0 || t10) {
                        bool t11 = updateMouseOperation(delta_time);
                        if (!t11) {
                            if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                updateListItem();
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return true;
                        }
                    } else {
                        if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                            updateListItem();
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
            } else {
                bool t10 = mIsAutoUpdateMouseOperation;
                if (t0 || t10) {
                    bool t11 = updateMouseOperation(delta_time);
                    if (!t11) {
                        if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                            updateListItem();
                            return true;
                        } else {
                            return false;
                        }
                    } else {
                        return true;
                    }
                } else {
                    if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                        updateListItem();
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        } else {
            bool t4 = mIsAutoDispPointer;
            if (t4) {
                if (!t1) {
                    u32 t5 = mListPos;
                    u32 t6 = mInfoArray.mLength;
                    if (t5 < t6) {
                        MtObject* * t7 = mInfoArray.getBuffer();
                        MtObject* t8 = t7[static_cast<int>(t5)];
                        if (t8 != nullptr) {
                            unsigned long t9 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 8);
                            setupPointerPos(reinterpret_cast<cScrollListItemBase*>(t9));
                            bool t10 = mIsAutoUpdateMouseOperation;
                            if (t0 || t10) {
                                bool t11 = updateMouseOperation(delta_time);
                                if (!t11) {
                                    if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                        updateListItem();
                                        return true;
                                    } else {
                                        return false;
                                    }
                                } else {
                                    return true;
                                }
                            } else {
                                if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                    updateListItem();
                                    return true;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            bool t10 = mIsAutoUpdateMouseOperation;
                            if (t0 || t10) {
                                bool t11 = updateMouseOperation(delta_time);
                                if (!t11) {
                                    if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                        updateListItem();
                                        return true;
                                    } else {
                                        return false;
                                    }
                                } else {
                                    return true;
                                }
                            } else {
                                if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                    updateListItem();
                                    return true;
                                } else {
                                    return false;
                                }
                            }
                        }
                    } else {
                        bool t10 = mIsAutoUpdateMouseOperation;
                        if (t0 || t10) {
                            bool t11 = updateMouseOperation(delta_time);
                            if (!t11) {
                                if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                    updateListItem();
                                    return true;
                                } else {
                                    return false;
                                }
                            } else {
                                return true;
                            }
                        } else {
                            if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                updateListItem();
                                return true;
                            } else {
                                return false;
                            }
                        }
                    }
                } else {
                    bool t10 = mIsAutoUpdateMouseOperation;
                    if (t0 || t10) {
                        bool t11 = updateMouseOperation(delta_time);
                        if (!t11) {
                            if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                                updateListItem();
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return true;
                        }
                    } else {
                        if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                            updateListItem();
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
            } else {
                bool t10 = mIsAutoUpdateMouseOperation;
                if (t0 || t10) {
                    bool t11 = updateMouseOperation(delta_time);
                    if (!t11) {
                        if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                            updateListItem();
                            return true;
                        } else {
                            return false;
                        }
                    } else {
                        return true;
                    }
                } else {
                    if (this->uGUIBase::cScrollCtrl::updateScroll(delta_time)) {
                        updateListItem();
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
}

__attribute__((weak)) bool uGUIBase::cScrollList::updateMouseOperation(f32 delta_time) {
    DDON_STUB("uGUIBase::cScrollList::updateMouseOperation")
    return {};
}

__attribute__((weak)) void uGUIBase::cScrollList::setupAllItem() {
    DDON_STUB("uGUIBase::cScrollList::setupAllItem")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollList::executeCtrl() {
    DDON_STUB("uGUIBase::cScrollList::executeCtrl")
    /* stub */
}

void uGUIBase::cScrollList::setFocus(bool flag) {
    if (mpVCtrl == nullptr) {
        return;
    }
    mpVCtrl->setFocus(flag);
}

void uGUIBase::cScrollList::setEnableKey(bool flag) {
    if (mpVCtrl == nullptr) {
        return;
    }
    if (flag) {
        mpVCtrl->mCtrlF = mpVCtrl->mCtrlF & 0xFFFFFFF7u;
    } else {
        mpVCtrl->mCtrlF = mpVCtrl->mCtrlF | 8u;
    }
}

bool uGUIBase::cScrollList::moveEvent() {
    if (mIsInputEvent) {
        if (mpOwner->getInputEvent() <= 15u) {
            if ((((48640ul >> static_cast<unsigned long>(mpOwner->getInputEvent() & 31u)) & 1ul) == 0) && (((16400ul >> static_cast<unsigned long>(mpOwner->getInputEvent() & 31u)) & 1ul) == 0)) {
                return false;
            }
            if (mpVCtrl != nullptr) {
                setListPos(static_cast<u32>(mpVCtrl->getCurrentPos()), false);
            } else {
                setListPos(0u, false);
            }
            return true;
        }
    }
    return false;
}

u32 uGUIBase::cScrollList::getInputEvent() {
    if (mIsInputEvent) {
        return mpOwner->getInputEvent();
    } else {
        return 0;
    }
}

void uGUIBase::cScrollList::setFocusCursor(bool bFocus) {
    if (bFocus) {
        mIsFocusCursor = true;
        if (mCursor.mpInstance != nullptr) {
            mCursor.mpInstance->setVisible(true);
        }
    } else {
        mIsFocusCursor = false;
        if (mCursor.mpInstance != nullptr) {
            mCursor.mpInstance->setVisible(false);
        }
    }
}

u32 uGUIBase::cScrollList::getDispIndex(uGUIBase::cScrollListItemBase* pItem) {
    if (mItemArray.mLength != 0) {
        u32 i = 0;
        do {
            if (pItem == mItemArray.getBuffer()[static_cast<int>(i)]) {
                return i;
            }
            i += 1u;
        } while (i < mItemArray.mLength);
    }
    return 0;
}

__attribute__((weak)) uGUIBase::cScrollListItemBase* uGUIBase::cScrollList::getCurrentItem() {
    DDON_STUB("uGUIBase::cScrollList::getCurrentItem")
    return nullptr;
}

__attribute__((weak)) void uGUIBase::cScrollList::updateCursor() {
    DDON_STUB("uGUIBase::cScrollList::updateCursor")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollList::updateListItem() {
    DDON_STUB("uGUIBase::cScrollList::updateListItem")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollList::setListFocus(bool isClear) {
    DDON_STUB("uGUIBase::cScrollList::setListFocus")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollList::setupPointerPos(uGUIBase::cScrollListItemBase* pItem) {
    DDON_STUB("uGUIBase::cScrollList::setupPointerPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollList::setupList(f32 bar_length, f32 disp_range, bool isResetPos) {
    DDON_STUB("uGUIBase::cScrollList::setupList")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollList::setupCtrl(bool useLR) {
    DDON_STUB("uGUIBase::cScrollList::setupCtrl")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollList::setupCursor(cGUIInstance* pInst, const MtFloat2& size, f32 fDistY) {
    DDON_STUB("uGUIBase::cScrollList::setupCursor")
    /* stub */
}

void uGUIBase::cScrollList::clearCursorFocus() {
    mIsCursorClear = true;
    if (mCursor.mpInstance != nullptr) {
        mCursor.mpInstance->setVisible(false);
    }
    setListFocus(true);
}

void uGUIBase::cScrollList::resetListItem() {
    clear();
    updateListItem();
}

uGUIBase::cScrollCtrl::cScrollCtrl() {
    DDON_STUB("uGUIBase::cScrollCtrl::cScrollCtrl")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cScrollCtrl::setSliderPos(f32 scroll_pos, bool isImmediate) {
    DDON_STUB("uGUIBase::cScrollCtrl::setSliderPos")
    /* stub */
}

__attribute__((weak)) f32 uGUIBase::cScrollCtrl::getSliderPos() {
    DDON_STUB("uGUIBase::cScrollCtrl::getSliderPos")
    return {};
}

__attribute__((weak)) void uGUIBase::cScrollCtrl::moveScroll(s32 scroll_num) {
    DDON_STUB("uGUIBase::cScrollCtrl::moveScroll")
    /* stub */
}

bool uGUIBase::cScrollCtrl::update(f32 delta_time) {
    if (mIsAutoUpdateMouseOperation && updateMouseOperation(delta_time)) {
        return true;
    }
    return updateScroll(delta_time);
}

__attribute__((weak)) bool uGUIBase::cScrollCtrl::updateMouseOperation(f32 delta_time) {
    DDON_STUB("uGUIBase::cScrollCtrl::updateMouseOperation")
    return {};
}

__attribute__((weak)) bool uGUIBase::cScrollCtrl::updateScroll(f32 delta_time) {
    DDON_STUB("uGUIBase::cScrollCtrl::updateScroll")
    return {};
}

const MtDTI& uGUIBase::cReferenceUIScrollBar::getDTI() const {
    return uGUIBase::cReferenceUIScrollBar::DTI;
}

uGUIBase::cReferenceUIScrollBar::cReferenceUIScrollBar() {
    mDragOld = false;
    mDragEnable = false;
    mMoveLength = 0.0f;
    mDispRange = 0.0f;
    mScrollPos = 0.0f;
    mScrollBarLength = 0.0f;
    mListRange = 0.0f;
    mpInstPolWheel = nullptr;
    mpObjPolWheel = nullptr;
    mpObjTexWakuBottom = nullptr;
    mpObjTexWakuCenter = nullptr;
    mpObjTexWakuTop = nullptr;
    mpObjTexSliderBottom = nullptr;
    mpObjTexSliderCenter = nullptr;
    mpObjTexSliderTop = nullptr;
}

__attribute__((weak)) void uGUIBase::cReferenceUIScrollBar::setup(uGUIBase* pUnit, cGUIInstance* pInstance, cGUIObject* pObjWheel) {
    DDON_STUB("uGUIBase::cReferenceUIScrollBar::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIScrollBar::execute(bool isCheckWheel) {
    DDON_STUB("uGUIBase::cReferenceUIScrollBar::execute")
    /* stub */
}

__attribute__((weak)) s32 uGUIBase::cReferenceUIScrollBar::getWheelMoveDir() {
    DDON_STUB("uGUIBase::cReferenceUIScrollBar::getWheelMoveDir")
    return {};
}

__attribute__((weak)) void uGUIBase::cReferenceUIScrollBar::setSize(f32 length, f32 list_range, f32 disp_range, bool execVisible) {
    DDON_STUB("uGUIBase::cReferenceUIScrollBar::setSize")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIScrollBar::setSliderPos(f32 scroll_pos) {
    DDON_STUB("uGUIBase::cReferenceUIScrollBar::setSliderPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIScrollBar::moveSliderPosByScreenDist(f32 move_dist) {
    DDON_STUB("uGUIBase::cReferenceUIScrollBar::moveSliderPosByScreenDist")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIScrollBar::moveSliderPosByListDist(f32 move_dist) {
    DDON_STUB("uGUIBase::cReferenceUIScrollBar::moveSliderPosByListDist")
    /* stub */
}

inline uGUIBase::cReferenceUIScrollBar::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIScrollBar::MyDTI uGUIBase::cReferenceUIScrollBar::DTI("uGUIBase::cReferenceUIScrollBar", &::uGUIBase::cReferenceUIBase::DTI, 168ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIScrollBar::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIScrollBar;
}

const MtDTI& uGUIBase::cVerticalList::getDTI() const {
    return uGUIBase::cVerticalList::DTI;
}

void* uGUIBase::cVerticalList::operator new(size_t sz, u32 align) {
    return uGUIBase::cVerticalList::getAllocator()->memAlloc(sz, align, uGUIBase::cVerticalList::DTI.getID());
}

void uGUIBase::cVerticalList::setUsePresetSE(bool bUse) {
    this->cControl::setUsePresetSE(bUse);
}

__attribute__((weak)) void uGUIBase::cVerticalList::setCurrentPos(s32 sPos, bool bDisableLoop) {
    DDON_STUB("uGUIBase::cVerticalList::setCurrentPos")
    /* stub */
}

bool uGUIBase::cVerticalList::execute() {
    return this->cControl::execute();
}

__attribute__((weak)) void uGUIBase::cVerticalList::checkLoop(u32 uKeyOnF, s32 sMoveDir, nGUIExt::MSG_REASON Reason, s32& sAddPos) {
    DDON_STUB("uGUIBase::cVerticalList::checkLoop")
    /* stub */
}

__attribute__((weak)) s32 uGUIBase::cVerticalList::getInputDirection(nGUIExt::MSG_REASON Reason) const {
    DDON_STUB("uGUIBase::cVerticalList::getInputDirection")
    return {};
}

inline uGUIBase::cVerticalList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cVerticalList::MyDTI uGUIBase::cVerticalList::DTI("uGUIBase::cVerticalList", &::cControl::DTI, 3160ul, 0u, 1u);

MtObject* uGUIBase::cVerticalList::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUICloseBtn::getDTI() const {
    return uGUIBase::cReferenceUICloseBtn::DTI;
}

uGUIBase::cReferenceUICloseBtn::cReferenceUICloseBtn() {
    mEnable = true;
    mpCtrl = nullptr;
}

__attribute__((weak)) void uGUIBase::cReferenceUICloseBtn::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, uGUIBase::cReferenceUICloseBtn::CloseFunc pCloseFunc) {
    DDON_STUB("uGUIBase::cReferenceUICloseBtn::setup")
    /* stub */
}

void uGUIBase::cReferenceUICloseBtn::update() {
    if (mpInstance == nullptr) {
        return;
    }
    mpInstance->setVisible(false);
    if (!mEnable) {
        return;
    }
    mpInstance->setVisible(true);
}

void uGUIBase::cReferenceUICloseBtn::execute() {
    if (!mEnable) {
        return;
    }
    if (mpCtrl == nullptr) {
        return;
    }
    mpCtrl->execute();
    if (!mpCtrl->isExecuteMsgEvent()) {
        return;
    }
    mpUnit->mEndReason = uGUIBase::END_REASON_CLOSE_BTN;
}

inline uGUIBase::cReferenceUICloseBtn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUICloseBtn::MyDTI uGUIBase::cReferenceUICloseBtn::DTI("uGUIBase::cReferenceUICloseBtn", &::uGUIBase::cReferenceUIBase::DTI, 88ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUICloseBtn::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUICloseBtn;
}

const MtDTI& uGUIBase::cReferenceUIIconQuest::getDTI() const {
    return uGUIBase::cReferenceUIIconQuest::DTI;
}

uGUIBase::cReferenceUIIconQuest::cReferenceUIIconQuest() {
    DDON_STUB("uGUIBase::cReferenceUIIconQuest::cReferenceUIIconQuest")
    /* stub */
}

void uGUIBase::cReferenceUIIconQuest::setup(uGUIBase* pBase, cGUIInstance* pInst) {
    mpUnit = pBase;
    mpInstance = static_cast<cGUIInstAnimation*>(pInst);
    if (pInst != nullptr) {
        static_cast<cGUIInstNull*>(pInst)->setColorControl(0u);
        cGUIInstAnimation* v0_1;
        cGUIObject* v0_9;
        if (mpInstance->mpObjRoot == nullptr) {
            v0_1 = mpInstance;
            v0_9 = nullptr;
        } else {
            v0_9 = mpInstance->mpObjRoot->getObjectFromId(4u);
            v0_1 = mpInstance;
        }
        mpObjNullNormal = static_cast<cGUIObjNull*>(v0_9);
        cGUIObject* v1_0;
        cGUIInstAnimation* v1_1;
        if (v0_1->mpObjRoot == nullptr) {
            v1_0 = nullptr;
            v1_1 = v0_1;
        } else {
            v1_0 = v0_1->mpObjRoot->getObjectFromId(2u);
            v1_1 = mpInstance;
        }
        mpObjBaseL = static_cast<cGUIObjTexture*>(v1_0);
        cGUIObject* v2_0;
        cGUIInstAnimation* v2_1;
        if (v1_1->mpObjRoot == nullptr) {
            v2_0 = nullptr;
            v2_1 = v1_1;
        } else {
            v2_0 = v1_1->mpObjRoot->getObjectFromId(5u);
            v2_1 = mpInstance;
        }
        mpObjBaseR = static_cast<cGUIObjTexture*>(v2_0);
        cGUIObject* v3_0;
        cGUIInstAnimation* v3_1;
        if (v2_1->mpObjRoot == nullptr) {
            v3_0 = nullptr;
            v3_1 = v2_1;
        } else {
            v3_0 = v2_1->mpObjRoot->getObjectFromId(6u);
            v3_1 = mpInstance;
        }
        mpObjIcon = static_cast<cGUIObjTexture*>(v3_0);
        cGUIObject* v4_0;
        cGUIInstAnimation* v4_1;
        if (v3_1->mpObjRoot == nullptr) {
            v4_0 = nullptr;
            v4_1 = v3_1;
        } else {
            v4_0 = v3_1->mpObjRoot->getObjectFromId(53u);
            v4_1 = mpInstance;
        }
        mpObjIconSp = static_cast<cGUIObjTexture*>(v4_0);
        cGUIObject* v5_0;
        cGUIInstAnimation* v5_1;
        if (v4_1->mpObjRoot == nullptr) {
            v5_0 = nullptr;
            v5_1 = v4_1;
        } else {
            v5_0 = v4_1->mpObjRoot->getObjectFromId(8u);
            v5_1 = mpInstance;
        }
        mpObjNullActive = static_cast<cGUIObjNull*>(v5_0);
        cGUIObject* v6_0;
        cGUIInstAnimation* v6_1;
        if (v5_1->mpObjRoot == nullptr) {
            v6_0 = nullptr;
            v6_1 = v5_1;
        } else {
            v6_0 = v5_1->mpObjRoot->getObjectFromId(51u);
            v6_1 = mpInstance;
        }
        mpObjNullIconSp = static_cast<cGUIObjNull*>(v6_0);
        cGUIObject* v7_0;
        cGUIInstAnimation* v7_1;
        if (v6_1->mpObjRoot == nullptr) {
            v7_0 = nullptr;
            v7_1 = v6_1;
        } else {
            v7_0 = v6_1->mpObjRoot->getObjectFromId(14u);
            v7_1 = mpInstance;
        }
        mpObjColorAdjust = static_cast<cGUIObjColorAdjust*>(v7_0);
        cGUIObject* v8_0;
        cGUIInstAnimation* v8_1;
        if (v7_1->mpObjRoot == nullptr) {
            v8_0 = nullptr;
            v8_1 = v7_1;
        } else {
            v8_0 = v7_1->mpObjRoot->getObjectFromId(16u);
            v8_1 = mpInstance;
        }
        mpObjActiveHL = static_cast<cGUIObjTexture*>(v8_0);
        cGUIObject* v9_0;
        cGUIInstAnimation* v9_1;
        if (v8_1->mpObjRoot == nullptr) {
            v9_0 = nullptr;
            v9_1 = v8_1;
        } else {
            v9_0 = v8_1->mpObjRoot->getObjectFromId(17u);
            v9_1 = mpInstance;
        }
        mpObjActiveHR = static_cast<cGUIObjTexture*>(v9_0);
        cGUIObject* v10_0;
        cGUIInstAnimation* v10_1;
        if (v9_1->mpObjRoot == nullptr) {
            v10_0 = nullptr;
            v10_1 = v9_1;
        } else {
            v10_0 = v9_1->mpObjRoot->getObjectFromId(11u);
            v10_1 = mpInstance;
        }
        mpObjActiveML = static_cast<cGUIObjTexture*>(v10_0);
        cGUIObject* v11_0;
        cGUIInstAnimation* v11_1;
        if (v10_1->mpObjRoot == nullptr) {
            v11_0 = nullptr;
            v11_1 = v10_1;
        } else {
            v11_0 = v10_1->mpObjRoot->getObjectFromId(12u);
            v11_1 = mpInstance;
        }
        mpObjActiveMR = static_cast<cGUIObjTexture*>(v11_0);
        cGUIObject* v12_0;
        cGUIInstAnimation* v12_1;
        if (v11_1->mpObjRoot == nullptr) {
            v12_0 = nullptr;
            v12_1 = v11_1;
        } else {
            v12_0 = v11_1->mpObjRoot->getObjectFromId(3u);
            v12_1 = mpInstance;
        }
        mpObjActiveLL = static_cast<cGUIObjTexture*>(v12_0);
        cGUIObject* v13_0;
        cGUIInstAnimation* v13_1;
        if (v12_1->mpObjRoot == nullptr) {
            v13_0 = nullptr;
            v13_1 = v12_1;
        } else {
            v13_0 = v12_1->mpObjRoot->getObjectFromId(10u);
            v13_1 = mpInstance;
        }
        mpObjActiveLR = static_cast<cGUIObjTexture*>(v13_0);
        cGUIObject* v14_0;
        cGUIInstAnimation* v14_1;
        if (v13_1->mpObjRoot == nullptr) {
            v14_0 = nullptr;
            v14_1 = v13_1;
        } else {
            v14_0 = v13_1->mpObjRoot->getObjectFromId(54u);
            v14_1 = mpInstance;
        }
        mpObjNullChip = static_cast<cGUIObjNull*>(v14_0);
        cGUIObject* v15_0;
        if (v14_1->mpObjRoot == nullptr) {
            v15_0 = nullptr;
        } else {
            v15_0 = v14_1->mpObjRoot->getObjectFromId(55u);
        }
        mpObjChip = static_cast<cGUIObjTexture*>(v15_0);
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconQuest::setDisp(uGUIBase::cReferenceUIIconQuest::TYPE type, uGUIBase::cReferenceUIIconQuest::STATE state) {
    DDON_STUB("uGUIBase::cReferenceUIIconQuest::setDisp")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconQuest::setDispFromQuestType(nQuest::QUEST_TYPE quest_type, uGUIBase::cReferenceUIIconQuest::STATE state) {
    DDON_STUB("uGUIBase::cReferenceUIIconQuest::setDispFromQuestType")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconQuest::setSdlId(u32 uSdlId, u32 uDispMode, nQuest::cQuestMarker* pMarker) {
    DDON_STUB("uGUIBase::cReferenceUIIconQuest::setSdlId")
    /* stub */
}

__attribute__((weak)) bool uGUIBase::cReferenceUIIconQuest::isEnableSyncChip(u32 uSdlId) {
    DDON_STUB("uGUIBase::cReferenceUIIconQuest::isEnableSyncChip")
    return {};
}

void uGUIBase::cReferenceUIIconQuest::setSize(uGUIBase::cReferenceUIIconQuest::SIZE size) {
    mSize = size;
}

__attribute__((weak)) bool uGUIBase::cReferenceUIIconQuest::IsActiveQuest(u32 scheduleId, u32 ActiveQuestDispType, u32* activeQuestIndex) {
    DDON_STUB("uGUIBase::cReferenceUIIconQuest::IsActiveQuest")
    return {};
}

inline uGUIBase::cReferenceUIIconQuest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconQuest::MyDTI uGUIBase::cReferenceUIIconQuest::DTI("uGUIBase::cReferenceUIIconQuest", &::uGUIBase::cReferenceUIBase::DTI, 224ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIIconQuest::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIIconQuest::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIButton::getDTI() const {
    return uGUIBase::cReferenceUIButton::DTI;
}

uGUIBase::cReferenceUIButton::cReferenceUIButton() {
    DDON_STUB("uGUIBase::cReferenceUIButton::cReferenceUIButton")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIButton::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, MT_CTSTR pMsgInit, f32 fSize) {
    DDON_STUB("uGUIBase::cReferenceUIButton::setup")
    /* stub */
}

void uGUIBase::cReferenceUIButton::setMessage(MT_CTSTR pMsg) {
    snprintf(&mMsg[0], 256ul, "%s", pMsg);
    if (mpUnit != nullptr) {
        mpUnit->setObjectMessage(static_cast<cGUIObject*>(mpObjMsgText), &mMsg[0], 0u, false);
    }
    setBtnSize(mBtnSize, false);
}

__attribute__((weak)) void uGUIBase::cReferenceUIButton::setFocus(bool isFocus) {
    DDON_STUB("uGUIBase::cReferenceUIButton::setFocus")
    /* stub */
}

bool uGUIBase::cReferenceUIButton::isFocus() {
    return mFocus;
}

void uGUIBase::cReferenceUIButton::setEnable(bool isEnable) {
    mIsEnable = isEnable;
    setFocus(mFocus);
}

__attribute__((weak)) void uGUIBase::cReferenceUIButton::setBtnSize(f32 fSize, bool changeSizeForced) {
    DDON_STUB("uGUIBase::cReferenceUIButton::setBtnSize")
    /* stub */
}

__attribute__((weak)) s32 uGUIBase::cReferenceUIButton::getWidth() {
    DDON_STUB("uGUIBase::cReferenceUIButton::getWidth")
    return {};
}

__attribute__((weak)) void uGUIBase::cReferenceUIButton::adjust2Buttons(uGUIBase::cReferenceUIButton& right, s32 interval) {
    DDON_STUB("uGUIBase::cReferenceUIButton::adjust2Buttons")
    /* stub */
}

u32 uGUIBase::cReferenceUIButton::addMouseTouchList(cControl* pOwner, s32 pos, s32 vol, bool autoErase) {
    if (pOwner != nullptr) {
        if (mpObjMouseOver != nullptr) {
            if (autoErase) {
                if (vol > -1) {
                    pOwner->eraseMouseTouchListPosVol(pos, vol);
                } else {
                    pOwner->eraseMouseTouchList(pos);
                }
            }
            return pOwner->addMouseTouchList(static_cast<cGUIInstance*>(mpInstance), static_cast<cGUIObject*>(mpObjMouseOver), pos, static_cast<cGUIObject*>(nullptr), 1u, 1u, vol);
        }
    }
    return 0xFFFFFFFF;
}

__attribute__((weak)) void uGUIBase::cReferenceUIButton::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIButton::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUIButton::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIButton::MyDTI uGUIBase::cReferenceUIButton::DTI("uGUIBase::cReferenceUIButton", &::uGUIBase::cReferenceUIBase::DTI, 400ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIButton::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIButton::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cMsgAnalyzer::getDTI() const {
    return uGUIBase::cMsgAnalyzer::DTI;
}

__attribute__((weak)) void uGUIBase::cMsgAnalyzer::operator delete(void* p_addr) {
    uGUIBase::cMsgAnalyzer::getAllocator()->memFree(p_addr);
}

uGUIBase::cMsgAnalyzer::~cMsgAnalyzer() {
    DDON_STUB("uGUIBase::cMsgAnalyzer::~cMsgAnalyzer")
    /* stub */
}

void uGUIBase::cMsgAnalyzer::setMsgAnalyzerWork(u32 uIdx, MT_CTSTR pAnalyzeMsg) {
    if (uIdx <= 9u) {
        mMAW[uIdx].mEnable = true;
        if (pAnalyzeMsg != mMAW[uIdx].mAnalyzeMsg.ptr()) {
            if (mMAW[uIdx].mAnalyzeMsg.value != nullptr) {
                if (sceAtomicAdd32Relaxed(&mMAW[uIdx].mAnalyzeMsg.value->ref, -1) == 1) {
                    (MtString::mpAllocator)->memFree(static_cast<void*>(mMAW[uIdx].mAnalyzeMsg.value));
                }
                mMAW[uIdx].mAnalyzeMsg.value = nullptr;
            }
            if (pAnalyzeMsg != nullptr) {
                size_t t0 = strlen(pAnalyzeMsg);
                if (static_cast<unsigned int>(t0) != 0) {
                    void* t1 = (MtString::mpAllocator)->memAlloc(static_cast<size_t>(static_cast<unsigned int>(t0)) + 12, 16u);
                    mMAW[uIdx].mAnalyzeMsg.value = static_cast<MtString::STRING*>(t1);
                    mMAW[uIdx].mAnalyzeMsg.value->ref = 1;
                    mMAW[uIdx].mAnalyzeMsg.value->length = static_cast<unsigned int>(t0);
                    strcpy(reinterpret_cast<char*>(mMAW[uIdx].mAnalyzeMsg.value->str), pAnalyzeMsg);
                } else {
                    mMAW[uIdx].mAnalyzeMsg.value = nullptr;
                }
            } else {
                mMAW[uIdx].mAnalyzeMsg.value = nullptr;
            }
        }
    }
}

void uGUIBase::cMsgAnalyzer::setMsgAnalyzerWork(u32 uIdx, s32 sAnalyzeNum) {
    if (uIdx <= 9u) {
        mMAW[uIdx].mEnable = true;
        mMAW[uIdx].mAnalyzeNum = sAnalyzeNum;
    }
}

__attribute__((weak)) void uGUIBase::cMsgAnalyzer::setObjectMessage(uGUIBase* pUnit, cGUIObject* pObj, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap) {
    DDON_STUB("uGUIBase::cMsgAnalyzer::setObjectMessage")
    /* stub */
}

inline uGUIBase::cMsgAnalyzer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cMsgAnalyzer::MyDTI uGUIBase::cMsgAnalyzer::DTI("uGUIBase::cMsgAnalyzer", &::MtObject::DTI, 168ul, 0u, 1u);

MtObject* uGUIBase::cMsgAnalyzer::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGUIBase::cHorizontalList::getDTI() const {
    return uGUIBase::cHorizontalList::DTI;
}

void* uGUIBase::cHorizontalList::operator new(size_t sz, u32 align) {
    return uGUIBase::cHorizontalList::getAllocator()->memAlloc(sz, align, uGUIBase::cHorizontalList::DTI.getID());
}

bool uGUIBase::cHorizontalList::isTabType() const {
    return mTabType;
}

void uGUIBase::cHorizontalList::setUsePresetSE(bool bUse) {
    this->cControl::setUsePresetSE(bUse);
}

__attribute__((weak)) void uGUIBase::cHorizontalList::setCurrentPos(s32 sPos, bool bDisableLoop) {
    DDON_STUB("uGUIBase::cHorizontalList::setCurrentPos")
    /* stub */
}

bool uGUIBase::cHorizontalList::execute() {
    return this->cControl::execute();
}

s32 uGUIBase::cHorizontalList::getInputDirection(nGUIExt::MSG_REASON Reason) const {
    if (isTabType()) {
        if (Reason != nGUIExt::TRG_LB) {
            return Reason == nGUIExt::TRG_RB;
        }
    } else {
        if (Reason != nGUIExt::TRG_LEFT) {
            return Reason == nGUIExt::TRG_RIGHT;
        }
    }
    return -1;
}

inline uGUIBase::cHorizontalList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cHorizontalList::MyDTI uGUIBase::cHorizontalList::DTI("uGUIBase::cHorizontalList", &::cControl::DTI, 3160ul, 0u, 1u);

MtObject* uGUIBase::cHorizontalList::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUITab::getDTI() const {
    return uGUIBase::cReferenceUITab::DTI;
}

uGUIBase::cReferenceUITab::cReferenceUITab() {
    DDON_STUB("uGUIBase::cReferenceUITab::cReferenceUITab")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUITab::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, u32 uNum, f32 fDist, uGUIBase::cReferenceUITab::ALIGN align) {
    DDON_STUB("uGUIBase::cReferenceUITab::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUITab::createArrayTabWork(u32 uNum) {
    DDON_STUB("uGUIBase::cReferenceUITab::createArrayTabWork")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUITab::setAutoPos() {
    DDON_STUB("uGUIBase::cReferenceUITab::setAutoPos")
    /* stub */
}

__attribute__((weak)) MtFloat2 uGUIBase::cReferenceUITab::getTabSize() {
    DDON_STUB("uGUIBase::cReferenceUITab::getTabSize")
    __builtin_unreachable();
}

void uGUIBase::cReferenceUITab::setTabMessage(u32 uIdx, MT_CTSTR pMsg) {
    if (mWork.mLength == 0) {
        return;
    }
    if (uIdx < mWork.mLength) {
        MtObject* t0 = mWork.mpArray[uIdx];
        if (t0 != nullptr) {
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 72)) != 0) {
                if (mIsAnalyzeTag) {
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 72)) + 296) = (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 72)) + 296)) | 8u;
                } else {
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 72)) + 296) = (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 72)) + 296)) & 0xFFFFFFF7u;
                }
            }
            snprintf(reinterpret_cast<char*>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 80))), 255ul, "%s", pMsg);
            if (mpUnit != nullptr) {
                mpUnit->setObjectMessage(reinterpret_cast<cGUIObject*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 72)), reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 80))), 0u, false);
            }
        }
    }
}

void uGUIBase::cReferenceUITab::setFocus(u32 uIdx, bool bFocus, bool bAutoFocus) {
    if (mWork.mLength == 0) {
        return;
    }
    if (uIdx >= mWork.mLength) {
        return;
    }
    u32 i = 0;
    do {
        if (mWork.mpArray[i] != nullptr) {
            if (static_cast<cTabWork*>(mWork.mpArray[i])->mpInst != nullptr) {
                if (uIdx == i) {
                    _setSequenceIdPrivate(static_cast<cTabWork*>(mWork.mpArray[i]), static_cast<u32>((bFocus * 3) + 1), uIdx);
                    mFocusIdx = static_cast<s32>(uIdx);
                } else {
                    if (bFocus && bAutoFocus) {
                        _setSequenceIdPrivate(static_cast<cTabWork*>(mWork.mpArray[i]), 1u, i);
                    }
                }
            }
        }
        i += 1u;
    } while (i < mWork.mLength);
}

void uGUIBase::cReferenceUITab::setVisible(bool bVisible) {
    u32 i = 0;
    if (mWork.mLength != 0) {
        do {
            if (mWork.mpArray[i] != nullptr) {
                if (static_cast<cTabWork*>(mWork.mpArray[i])->mpInst != nullptr) {
                    if (mpUnit != nullptr) {
                        static_cast<cTabWork*>(mWork.mpArray[i])->mpInst->setVisible(bVisible);
                    }
                }
            }
            i += 1u;
        } while (i < mWork.mLength);
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUITab::setVisibleTabMax(u32 max) {
    DDON_STUB("uGUIBase::cReferenceUITab::setVisibleTabMax")
    /* stub */
}

__attribute__((weak)) s32 uGUIBase::cReferenceUITab::getLRWidth() {
    DDON_STUB("uGUIBase::cReferenceUITab::getLRWidth")
    return {};
}

f32 uGUIBase::cReferenceUITab::getConvertWindowCenterX(f32 center_center_x) {
    return -4.0f + center_center_x;
}

__attribute__((weak)) void uGUIBase::cReferenceUITab::resizeForVisible() {
    DDON_STUB("uGUIBase::cReferenceUITab::resizeForVisible")
    /* stub */
}

cGUIInstAnimation* uGUIBase::cReferenceUITab::getInstance(u32 uIdx) {
    if (mWork.mLength != 0) {
        if (uIdx < mWork.mLength) {
            if (mWork.mpArray[uIdx] != nullptr) {
                return static_cast<cTabWork*>(mWork.mpArray[uIdx])->mpInst;
            }
        }
    }
    return nullptr;
}

cGUIObjPolygon* uGUIBase::cReferenceUITab::getMouseOverObj(u32 uIdx) {
    if (mWork.mLength != 0) {
        if (uIdx < mWork.mLength) {
            if (mWork.mpArray[uIdx] != nullptr) {
                return static_cast<cTabWork*>(mWork.mpArray[uIdx])->mpMouseOver;
            }
        }
    }
    return nullptr;
}

cGUIObjNull* uGUIBase::cReferenceUITab::getNullPointerObj(u32 uIdx) {
    if (mWork.mLength != 0) {
        if (uIdx < mWork.mLength) {
            if (mWork.mpArray[uIdx] != nullptr) {
                return static_cast<cTabWork*>(mWork.mpArray[uIdx])->mpNullPointer;
            }
        }
    }
    return nullptr;
}

void uGUIBase::cReferenceUITab::setCtrlable(bool bEnable) {
    if (mWork.mLength == 0) {
        return;
    }
    mIsCtrlable = bEnable;
    setupLRGuide();
}

void uGUIBase::cReferenceUITab::setupMouseTouchList(cControl* pCtrl, s32 vol) {
    if (pCtrl != nullptr) {
        pCtrl->clearMouseTouchList();
        if (mWork.mLength != 0) {
            u32 v0_0 = mWork.mLength;
            for (unsigned int i0_3 = 0;;) {
                if (v0_0 != 0) {
                    if (i0_3 < v0_0) {
                        if (mWork.mpArray[i0_3] != nullptr) {
                            if (mWork.mpArray[i0_3] != nullptr) {
                                pCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(static_cast<cTabWork*>(mWork.mpArray[i0_3])->mpInst), static_cast<cGUIObject*>(static_cast<cTabWork*>(mWork.mpArray[i0_3])->mpMouseOver), static_cast<s32>(i0_3), vol);
                            } else {
                                pCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(static_cast<cTabWork*>(mWork.mpArray[i0_3])->mpInst), static_cast<cGUIObject*>(nullptr), static_cast<s32>(i0_3), vol);
                            }
                        } else {
                            if (mWork.mpArray[i0_3] != nullptr) {
                                pCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(nullptr), static_cast<cGUIObject*>(static_cast<cTabWork*>(mWork.mpArray[i0_3])->mpMouseOver), static_cast<s32>(i0_3), vol);
                            } else {
                                pCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(nullptr), static_cast<cGUIObject*>(nullptr), static_cast<s32>(i0_3), vol);
                            }
                        }
                    } else {
                        pCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(nullptr), static_cast<cGUIObject*>(nullptr), static_cast<s32>(i0_3), vol);
                    }
                } else {
                    pCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(nullptr), static_cast<cGUIObject*>(nullptr), static_cast<s32>(i0_3), vol);
                }
                if ((i0_3 + 1u) < mWork.mLength) {
                    v0_0 = mWork.mLength;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUITab::updateButtonGuide() {
    DDON_STUB("uGUIBase::cReferenceUITab::updateButtonGuide")
    /* stub */
}

void uGUIBase::cReferenceUITab::setShape(u32 index, uGUIBase::cReferenceUITab::SHAPE shape) {
    if (index < mWork.mLength) {
        if (mWork.getBuffer()[static_cast<int>(index)] != nullptr) {
            static_cast<cTabWork*>(mWork.getBuffer()[static_cast<int>(index)])->mShape = shape;
        }
    }
}

void uGUIBase::cReferenceUITab::setAnalyzeTag(bool isAnalyzeTag) {
    mIsAnalyzeTag = isAnalyzeTag;
    if (mWork.size() != 0) {
        u32 v0_0 = mWork.size();
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mWork.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                if (static_cast<cTabWork*>(mWork.mpArray[i0_3])->mpObjMsg == nullptr) {
                    v1_0 = v0_0;
                } else {
                    static_cast<cTabWork*>(mWork.mpArray[i0_3])->mpObjMsg->mMsgAttr = !isAnalyzeTag ? (static_cast<cTabWork*>(mWork.mpArray[i0_3])->mpObjMsg->mMsgAttr & 0xFFFFFFF7u) : (static_cast<cTabWork*>(mWork.mpArray[i0_3])->mpObjMsg->mMsgAttr | 8u);
                    if (mpUnit == nullptr) {
                        v1_0 = v0_0;
                    } else {
                        mpUnit->setObjectMessage(static_cast<cGUIObject*>(static_cast<cTabWork*>(mWork.mpArray[i0_3])->mpObjMsg), &static_cast<cTabWork*>(mWork.mpArray[i0_3])->mMsg[0], 0u, false);
                        v1_0 = mWork.size();
                    }
                }
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUITab::_setSequenceIdPrivate(uGUIBase::cReferenceUITab::cTabWork* pWork, u32 seqId, u32 uIdx) {
    DDON_STUB("uGUIBase::cReferenceUITab::_setSequenceIdPrivate")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUITab::setupLRGuide() {
    DDON_STUB("uGUIBase::cReferenceUITab::setupLRGuide")
    /* stub */
}

inline uGUIBase::cReferenceUITab::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUITab::MyDTI uGUIBase::cReferenceUITab::DTI("uGUIBase::cReferenceUITab", &::uGUIBase::cReferenceUIBase::DTI, 176ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUITab::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUITab::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUITab::cTabWork::getDTI() const {
    return uGUIBase::cReferenceUITab::cTabWork::DTI;
}

inline uGUIBase::cReferenceUITab::cTabWork::cTabWork() {
    memset(static_cast<void*>(&mpInst), 0, 332ul);
}

inline uGUIBase::cReferenceUITab::cTabWork::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUITab::cTabWork::MyDTI uGUIBase::cReferenceUITab::cTabWork::DTI("uGUIBase::cReferenceUITab::cTabWork", &::MtObject::DTI, 344ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUITab::cTabWork::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUITab::cTabWork;
}

__attribute__((weak)) bool uGUIBase::cInputGuideMonitor::checkUpdate() {
    DDON_STUB("uGUIBase::cInputGuideMonitor::checkUpdate")
    return {};
}

const MtDTI& uGUIBase::cReferenceUIBtnGuide::getDTI() const {
    return uGUIBase::cReferenceUIBtnGuide::DTI;
}

uGUIBase::cReferenceUIBtnGuide::cReferenceUIBtnGuide() {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::cReferenceUIBtnGuide")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIBtnGuide::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, f32 fWidth) {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIBtnGuide::update() {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::update")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIBtnGuide::createArrayBtnGuideWork() {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::createArrayBtnGuideWork")
    /* stub */
}

void uGUIBase::cReferenceUIBtnGuide::addGuide(uGUIBase::cReferenceUIBtnGuide::GUIDE_TYPE type) {
    static const GuideTypeParam guide_type_params[15] = {
        {static_cast<nKeyCustom::KB_CUSTOM>(0), 48, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(62), 49, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(63), 49, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(59), 50, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(62), 51, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(63), 51, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(59), 56, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(60), 52, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(60), 53, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(59), 54, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(63), 55, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(55), 84, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(56), 84, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(60), 55, static_cast<nGUIExt::ICONTAGKB>(0)},
        {static_cast<nKeyCustom::KB_CUSTOM>(61), 81, static_cast<nGUIExt::ICONTAGKB>(0)},
    };
    if (static_cast<unsigned int>(type) <= 14) {
        MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), guide_type_params[static_cast<int>(type)].msgId);
        addGuide(guide_type_params[static_cast<int>(type)].kbCustom, t0, guide_type_params[static_cast<int>(type)].wayType, static_cast<MT_CTSTR>(nullptr), false);
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIBtnGuide::addGuide(nKeyCustom::KB_CUSTOM kbCustom, MT_CTSTR pMsg, nGUIExt::ICONTAGKB wayType, MT_CTSTR pKbdMsg, bool isIgnoreModifier) {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::addGuide")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIBtnGuide::clearGuide() {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::clearGuide")
    /* stub */
}

__attribute__((weak)) u32 uGUIBase::cReferenceUIBtnGuide::getGuideNum() {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::getGuideNum")
    return {};
}

void uGUIBase::cReferenceUIBtnGuide::setVisible(bool bVisible) {
    mIsBaseVisible = bVisible;
    unsigned int i3 = 0;
    if (mWork.mLength != 0) {
        do {
            if (mWork.mpArray[i3] != nullptr) {
                if (static_cast<cWork*>(mWork.mpArray[i3])->mpInst != nullptr) {
                    if (mpUnit != nullptr) {
                        static_cast<cWork*>(mWork.mpArray[i3])->mpInst->setVisible(bVisible);
                    }
                }
            }
            i3 += 1u;
        } while (i3 < mWork.mLength);
    }
}

__attribute__((weak)) f32 uGUIBase::cReferenceUIBtnGuide::getCenterX() const {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::getCenterX")
    return {};
}

__attribute__((weak)) void uGUIBase::cReferenceUIBtnGuide::addBtnIcon(u32 uIdx, nKeyCustom::KB_CUSTOM kbCustom) {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::addBtnIcon")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIBtnGuide::adjustDisp() {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::adjustDisp")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIBtnGuide::setDispBit(u32 bit) {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::setDispBit")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIBtnGuide::setMsg(uGUIBase::cReferenceUIBtnGuide::cWork* pWork) {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::setMsg")
    /* stub */
}

inline uGUIBase::cReferenceUIBtnGuide::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIBtnGuide::MyDTI uGUIBase::cReferenceUIBtnGuide::DTI("uGUIBase::cReferenceUIBtnGuide", &::uGUIBase::cReferenceUIBase::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIBtnGuide::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIBtnGuide::cWork::getDTI() const {
    return uGUIBase::cReferenceUIBtnGuide::cWork::DTI;
}

inline uGUIBase::cReferenceUIBtnGuide::cWork::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIBtnGuide::cWork::MyDTI uGUIBase::cReferenceUIBtnGuide::cWork::DTI("uGUIBase::cReferenceUIBtnGuide::cWork", &::MtObject::DTI, 368ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIBtnGuide::cWork::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIBtnGuide::cWork::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUITooltip::getDTI() const {
    return uGUIBase::cReferenceUITooltip::DTI;
}

uGUIBase::cReferenceUITooltip::cReferenceUITooltip() {
    DDON_STUB("uGUIBase::cReferenceUITooltip::cReferenceUITooltip")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUITooltip::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, MT_CTSTR pMsg) {
    DDON_STUB("uGUIBase::cReferenceUITooltip::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUITooltip::setMessage(MT_CTSTR pMsg) {
    DDON_STUB("uGUIBase::cReferenceUITooltip::setMessage")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUITooltip::adjustSize() {
    DDON_STUB("uGUIBase::cReferenceUITooltip::adjustSize")
    /* stub */
}

f32 uGUIBase::cReferenceUITooltip::getMessageWidth() const {
    if (mpObjMsg != nullptr) {
        return mpObjMsg->getMessageWidth();
    } else {
        return 0.0f;
    }
}

f32 uGUIBase::cReferenceUITooltip::getMessageHeight() const {
    if (mpObjMsg != nullptr) {
        return mpObjMsg->getMessageHeight();
    } else {
        return 0.0f;
    }
}

inline uGUIBase::cReferenceUITooltip::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUITooltip::MyDTI uGUIBase::cReferenceUITooltip::DTI("uGUIBase::cReferenceUITooltip", &::uGUIBase::cReferenceUIBase::DTI, 368ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUITooltip::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUITooltip::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cMatrix::getDTI() const {
    return uGUIBase::cMatrix::DTI;
}

bool uGUIBase::cMatrix::execute() {
    return this->cControl::execute();
}

bool uGUIBase::cMatrix::isUpperRow() {
    return mCurrentRow <= 0;
}

bool uGUIBase::cMatrix::isLastRow() {
    return mCurrentRow >= (mRow - 1);
}

__attribute__((weak)) u32 uGUIBase::cMatrix::resetItemNum(s32 num, s32 col, const u32* tags, s32 pos, u32 flag) {
    DDON_STUB("uGUIBase::cMatrix::resetItemNum")
    return {};
}

__attribute__((weak)) void uGUIBase::cMatrix::setCurrentPos(s32 sPos, bool bDisableLoop) {
    DDON_STUB("uGUIBase::cMatrix::setCurrentPos")
    /* stub */
}

void uGUIBase::cMatrix::setCurrentColumn(s32 sCol) {
    setCurrentPos(sCol + (mColumn * mCurrentRow), false);
}

void uGUIBase::cMatrix::setCurrentRow(s32 sRow) {
    setCurrentPos(mCurrentColumn + (sRow * mColumn), false);
}

s32 uGUIBase::cMatrix::getVisibleTopPosX() const {
    return mCurrentColumn - mLocateX;
}

s32 uGUIBase::cMatrix::getVisibleTopPosY() const {
    return mCurrentRow - mLocateY;
}

void uGUIBase::cMatrix::addVisibleTopPos(s32 add) {
    s32 t0 = mLocateY;
    mLocateY = add + t0;
    if (((((mCurrentRow - add) - t0) + mVisibleH) - mRow) > 0) {
        mLocateY = (mCurrentRow + mVisibleH) - mRow;
    }
    if (((mCurrentRow - add) - t0) <= -1) {
        mLocateY = mCurrentRow;
    }
}

void uGUIBase::cMatrix::setUsePresetSE(bool bUse) {
    this->cControl::setUsePresetSE(bUse);
}

__attribute__((weak)) void uGUIBase::cMatrix::checkLoop(u32 uKeyOnF, s32 sMoveDir, nGUIExt::MSG_REASON Reason, s32& sAddPos) {
    DDON_STUB("uGUIBase::cMatrix::checkLoop")
    /* stub */
}

void uGUIBase::cMatrix::setLoop(bool flag) {
    mEnableLoop = flag;
    mEnableLoopX = flag;
    mEnableLoopY = flag;
}

void uGUIBase::cMatrix::setTrgLoop(bool flag) {
    mEnableTrgLoop = flag;
    mEnableTrgLoopX = flag;
    mEnableTrgLoopY = flag;
}

__attribute__((weak)) s32 uGUIBase::cMatrix::getInputDirection(nGUIExt::MSG_REASON Reason) const {
    s32 dir = 0;
    if (Reason == nGUIExt::TRG_UP || Reason == nGUIExt::TRG_LEFT) {
        dir = -1;
    } else if (Reason == nGUIExt::TRG_DOWN || Reason == nGUIExt::TRG_RIGHT) {
        dir = 1;
    }
    return dir;
}

inline uGUIBase::cMatrix::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cMatrix::MyDTI uGUIBase::cMatrix::DTI("uGUIBase::cMatrix", &::cControl::DTI, 3184ul, 0u, 1u);

MtObject* uGUIBase::cMatrix::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGUIBase::cMaskScroll::getDTI() const {
    return uGUIBase::cMaskScroll::DTI;
}

__attribute__((weak)) void uGUIBase::cMaskScroll::operator delete(void* p_addr) {
    uGUIBase::cMaskScroll::getAllocator()->memFree(p_addr);
}

__attribute__((weak)) void uGUIBase::cMaskScroll::setup(cGUIObject* pObj, f32 fMaskWidth, f32 fStartFrame, f32 fEndWaitFrame, f32 fMoveX, bool bLoop) {
    DDON_STUB("uGUIBase::cMaskScroll::setup")
    /* stub */
}

inline uGUIBase::cMaskScroll::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cMaskScroll::MyDTI uGUIBase::cMaskScroll::DTI("uGUIBase::cMaskScroll", &::MtObject::DTI, 56ul, 0u, 1u);

MtObject* uGUIBase::cMaskScroll::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGUIBase::cValueList::getDTI() const {
    return uGUIBase::cValueList::DTI;
}

uGUIBase::cValueList::cValueList(MT_CTSTR v0, MT_CTSTR v1, MT_CTSTR v2, MT_CTSTR v3, MT_CTSTR v4, MT_CTSTR v5, MT_CTSTR v6, MT_CTSTR v7, MT_CTSTR v8, MT_CTSTR v9, MT_CTSTR v10, MT_CTSTR v11, MT_CTSTR v12, MT_CTSTR v13, MT_CTSTR v14, MT_CTSTR v15, MT_CTSTR v16, MT_CTSTR v17, MT_CTSTR v18, MT_CTSTR v19) {
    DDON_STUB("uGUIBase::cValueList::cValueList")
    /* stub */
}

void uGUIBase::cValueList::clearStr() {
    mValues.elems[0].mStr[0] = 0;
    mValues.elems[0].mLength = 0;
    mValues.elems[1].mStr[0] = 0;
    mValues.elems[1].mLength = 0;
    mValues.elems[2].mStr[0] = 0;
    mValues.elems[2].mLength = 0;
    mValues.elems[3].mStr[0] = 0;
    mValues.elems[3].mLength = 0;
    mValues.elems[4].mStr[0] = 0;
    mValues.elems[4].mLength = 0;
    mValues.elems[5].mStr[0] = 0;
    mValues.elems[5].mLength = 0;
    mValues.elems[6].mStr[0] = 0;
    mValues.elems[6].mLength = 0;
    mValues.elems[7].mStr[0] = 0;
    mValues.elems[7].mLength = 0;
    mValues.elems[8].mStr[0] = 0;
    mValues.elems[8].mLength = 0;
    mValues.elems[9].mStr[0] = 0;
    mValues.elems[9].mLength = 0;
    mValues.elems[10].mStr[0] = 0;
    mValues.elems[10].mLength = 0;
    mValues.elems[11].mStr[0] = 0;
    mValues.elems[11].mLength = 0;
    mValues.elems[12].mStr[0] = 0;
    mValues.elems[12].mLength = 0;
    mValues.elems[13].mStr[0] = 0;
    mValues.elems[13].mLength = 0;
    mValues.elems[14].mStr[0] = 0;
    mValues.elems[14].mLength = 0;
    mValues.elems[15].mStr[0] = 0;
    mValues.elems[15].mLength = 0;
    mValues.elems[16].mStr[0] = 0;
    mValues.elems[16].mLength = 0;
    mValues.elems[17].mStr[0] = 0;
    mValues.elems[17].mLength = 0;
    mValues.elems[18].mStr[0] = 0;
    mValues.elems[18].mLength = 0;
    mValues.elems[19].mStr[0] = 0;
    mValues.elems[19].mLength = 0;
    mNum = 0;
}

inline uGUIBase::cValueList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cValueList::MyDTI uGUIBase::cValueList::DTI("uGUIBase::cValueList", &::MtObject::DTI, 736ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cValueList::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cValueList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cInterpolationValue::getDTI() const {
    return uGUIBase::cInterpolationValue::DTI;
}

uGUIBase::cInterpolationValue::cInterpolationValue() {
    DDON_STUB("uGUIBase::cInterpolationValue::cInterpolationValue")
    /* stub */
}

void uGUIBase::cInterpolationValue::set(f32 val, f32 speed) {
    mMax = val;
    mSpeed = speed;
    mPow = 0.0f;
    mDifference = __builtin_fabsf(val - mValue);
}

__attribute__((weak)) f32 uGUIBase::cInterpolationValue::execute() {
    DDON_STUB("uGUIBase::cInterpolationValue::execute")
    return {};
}

inline uGUIBase::cInterpolationValue::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cInterpolationValue::MyDTI uGUIBase::cInterpolationValue::DTI("uGUIBase::cInterpolationValue", &::MtObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cInterpolationValue::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cInterpolationValue::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cUnitWatcher::getDTI() const {
    return uGUIBase::cUnitWatcher::DTI;
}

uGUIBase::cUnitWatcher::cUnitWatcher() {
    DDON_STUB("uGUIBase::cUnitWatcher::cUnitWatcher")
    /* stub */
}

void uGUIBase::cUnitWatcher::update() {
    mpOldUnit = mpUnit;
    if (mpOldUnit == nullptr) {
        return;
    }
    if (mpUnit->isEnable()) {
        return;
    }
    mpUnit = nullptr;
}

__attribute__((weak)) bool uGUIBase::cUnitWatcher::isEnd() {
    DDON_STUB("uGUIBase::cUnitWatcher::isEnd")
    return {};
}

void uGUIBase::cUnitWatcher::clear() {
    if (mKillReq) {
        if (mpUnit != nullptr) {
            const MtDTI& t0 = mpUnit->getDTI();
            MT_CTSTR v0_1 = uGUIMap::DTI.mName;
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_1 != v0_0->mName) {
                    if (v0_0->mpParent != nullptr) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    static_cast<sGUIExt*>(sGUI::getInstance())->setFocusMap(static_cast<uGUIMap*>(nullptr));
                    break;
                }
            }
            if (mpUnit != nullptr) {
                mpUnit->kill();
                mpUnit = nullptr;
            }
        }
    }
    mpUnit = nullptr;
    mpOldUnit = nullptr;
    mKillReq = false;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 48) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 40) = 0;
    mEndFunc.mpUnit = nullptr;
}

void uGUIBase::cUnitWatcher::addUnit(uGUIBase* pUnit, u32 line, u64 groupbit) {
    mpUnit = pUnit;
    if (pUnit != nullptr) {
        sUnit::getInstance()->addBottom(static_cast<MOVE_LINE>(line), static_cast<cUnit*>(pUnit), groupbit);
    }
    mKillReq = true;
}

inline uGUIBase::cUnitWatcher::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cUnitWatcher::MyDTI uGUIBase::cUnitWatcher::DTI("uGUIBase::cUnitWatcher", &::MtObject::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cUnitWatcher::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cUnitWatcher::MyDTI::newInstance")
    return nullptr;
}

uGUIBase::cTexRefJpegDownloader::cTexRefJpegDownloader() {
    DDON_STUB("uGUIBase::cTexRefJpegDownloader::cTexRefJpegDownloader")
    /* stub */
}

__attribute__((noinline)) uGUIBase::cTexRefJpegDownloader::~cTexRefJpegDownloader() {
    static_cast<sGUIExt*>(sGUI::getInstance())->dlTicketReturn(mDlTicket);
    if (mpTex == nullptr) {
        return;
    }
    mpTex->release();
    mpTex = nullptr;
}

void uGUIBase::cTexRefJpegDownloader::setup(cGUIObject* objTexRef) {
    mpObjTexRef = static_cast<cGUIObjTextureRef*>(objTexRef);
    if (objTexRef == nullptr) {
        return;
    }
    objTexRef->setVisible(false);
}

__attribute__((weak)) void uGUIBase::cTexRefJpegDownloader::request(MT_CTSTR url) {
    // workaround
    MT_STR t1 = reinterpret_cast<MT_STR>(&mURL_Jpeg) + sizeof(u32);
    if (url[0] != '\0' && (t1 == url || (url != nullptr ? strcmp(t1, url) : static_cast<s32>(reinterpret_cast<u32&>(mURL_Jpeg))) == 0)) {
        return;
    }
    
    if (url == nullptr) {
        t1[0] = '\0';
        reinterpret_cast<u32&>(mURL_Jpeg) = 0;
    } else if (t1 != url) {
        s32 t2 = static_cast<s32>(strlen(url));
        t2 = t2 <= static_cast<s32>(sizeof(mURL_Jpeg) - sizeof(u32) - 1)
            ? t2 : static_cast<s32>(sizeof(mURL_Jpeg) - sizeof(u32) - 1);
        reinterpret_cast<u32&>(mURL_Jpeg) = static_cast<u32>(t2);
        if (t2 != 0) {
            memcpy(t1, url, static_cast<u32>(t2));
            t1[static_cast<u32>(t2)] = '\0';
        } else {
            t1[0] = '\0';
        }
    }
    
    if (mDlTicket == sGUIExt::BLANK_TICKET_NO) {
        mIsRequest = true;
        mDlTicket = static_cast<sGUIExt*>(sGUI::getInstance())->dlTicketRequest();
    } else {
        mIsRequestBuf = true;
    }
    mIsRequest = true;
    mWaitTime = 0.0f;
    if (mpObjTexRef != nullptr) {
        mpObjTexRef->setVisible(false);
    }
}

__attribute__((weak)) void uGUIBase::cTexRefJpegDownloader::update(f32 delta_time) {
    DDON_STUB("uGUIBase::cTexRefJpegDownloader::update")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cTexRefJpegDownloader::abort() {
    DDON_STUB("uGUIBase::cTexRefJpegDownloader::abort")
    /* stub */
}

bool uGUIBase::cTexRefJpegDownloader::isHaveTicket() {
    return mDlTicket != 0x1869F;
}

uGUIBase::cImageDownloader::~cImageDownloader() {
    DDON_STUB("uGUIBase::cImageDownloader::~cImageDownloader")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cImageDownloader::request(MT_CTSTR url) {
    DDON_STUB("uGUIBase::cImageDownloader::request")
    /* stub */
}

const MtDTI& uGUIBase::cReferenceUISlider::getDTI() const {
    return uGUIBase::cReferenceUISlider::DTI;
}

inline uGUIBase::cReferenceUISlider::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUISlider::MyDTI uGUIBase::cReferenceUISlider::DTI("uGUIBase::cReferenceUISlider", &::uGUIBase::cSupportInstAnim::DTI, 88ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUISlider::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUISlider;
}

const MtDTI& uGUIBase::cReferenceUIDropIcon::getDTI() const {
    return uGUIBase::cReferenceUIDropIcon::DTI;
}

inline uGUIBase::cReferenceUIDropIcon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIDropIcon::MyDTI uGUIBase::cReferenceUIDropIcon::DTI("uGUIBase::cReferenceUIDropIcon", &::uGUIBase::cReferenceUIBase::DTI, 88ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIDropIcon::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIDropIcon;
}

const MtDTI& uGUIBase::cReferenceUICursor::getDTI() const {
    return uGUIBase::cReferenceUICursor::DTI;
}

inline uGUIBase::cReferenceUICursor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUICursor::MyDTI uGUIBase::cReferenceUICursor::DTI("uGUIBase::cReferenceUICursor", &::uGUIBase::cSupportInstAnim::DTI, 224ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUICursor::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUICursor;
}

const MtDTI& uGUIBase::cReferenceUISelector::getDTI() const {
    return uGUIBase::cReferenceUISelector::DTI;
}

__attribute__((weak)) void uGUIBase::cReferenceUISelector::setup(uGUIBase* pUnit, cGUIInstance* pInst) {
    DDON_STUB("uGUIBase::cReferenceUISelector::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUISelector::setMessage(u32 index, MT_CTSTR msg) {
    DDON_STUB("uGUIBase::cReferenceUISelector::setMessage")
    /* stub */
}

void uGUIBase::cReferenceUISelector::setIndex(u32 index) {
    if (index < mMsgList.mNum) {
        if (mpUnit != nullptr) {
            mpUnit->setObjectMessage(static_cast<cGUIObject*>(mpObjMsg), &mMsgList.mValues.elems[(index <= 19u) ? index : 0u].mStr[0], 0u, false);
        }
        mIndex = index;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUISelector::setFocus(bool isFocus) {
    DDON_STUB("uGUIBase::cReferenceUISelector::setFocus")
    /* stub */
}

MtVector2 uGUIBase::cReferenceUISelector::getPointerPos() {
    MtVector2 result;
    if (mpUnit != nullptr) {
        if (mpObjNullPointer != nullptr) {
            const f32 t0 = MtVector3::Zero.y;
            f32 t1 = mpObjNullPointer->mMat.m[3].y;
            result.x = MtVector3::Zero.x + mpObjNullPointer->mMat.m[3].x;
            result.y = t0 + t1;
            return result;
        }
    }
    result.x = MtVector2::Zero.x;
    result.y = MtVector2::Zero.y;
    return result;
}

void uGUIBase::cReferenceUISelector::addMouseTouchList(cControl* pCtrl, s32 pos) {
    if (pCtrl == nullptr) {
        return;
    }
    pCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(mpInstance), static_cast<cGUIObject*>(mpObjPolyMouseCollisionCenter), pos, 0);
    pCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(mpInstance), static_cast<cGUIObject*>(mpObjPolyMouseCollisionLeft), pos, 1);
    pCtrl->addMouseTouchListLight(static_cast<cGUIInstance*>(mpInstance), static_cast<cGUIObject*>(mpObjPolyMouseCollisionRight), pos, 2);
}

inline uGUIBase::cReferenceUISelector::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUISelector::MyDTI uGUIBase::cReferenceUISelector::DTI("uGUIBase::cReferenceUISelector", &::uGUIBase::cReferenceUIBase::DTI, 864ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUISelector::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUISelector::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIGoldRim::getDTI() const {
    return uGUIBase::cReferenceUIGoldRim::DTI;
}

inline uGUIBase::cReferenceUIGoldRim::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIGoldRim::MyDTI uGUIBase::cReferenceUIGoldRim::DTI("uGUIBase::cReferenceUIGoldRim", &::uGUIBase::cSupportInstAnim::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIGoldRim::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIGoldRim::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIChargesInfo::getDTI() const {
    return uGUIBase::cReferenceUIChargesInfo::DTI;
}

void* uGUIBase::cReferenceUIChargesInfo::operator new(size_t sz, u32 align) {
    return uGUIBase::cReferenceUIChargesInfo::getAllocator()->memAlloc(sz, align, uGUIBase::cReferenceUIChargesInfo::DTI.getID());
}

uGUIBase::cReferenceUIChargesInfo::cReferenceUIChargesInfo() {
    DDON_STUB("uGUIBase::cReferenceUIChargesInfo::cReferenceUIChargesInfo")
    /* stub */
}

uGUIBase::cReferenceUIChargesInfo::~cReferenceUIChargesInfo() {
}

__attribute__((weak)) void uGUIBase::cReferenceUIChargesInfo::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, u32 uAttr) {
    DDON_STUB("uGUIBase::cReferenceUIChargesInfo::setup")
    /* stub */
}

void uGUIBase::cReferenceUIChargesInfo::setAttribute(u32 uAttr, u32 uDispF) {
    mRno = 0;
    mCurrentIdxData = 0;
    mCourseTimer = 0.0f;
    mDispTimer = 0.0f;
    if (mList.mLength != 0) {
        u32 v0_0 = mList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mList.mpArray[i0_3];
                v1_0 = mList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mList.mpArray));
    }
    mList.mpArray = nullptr;
    mList.mBufsiz = 0;
    mList.mLength = 0;
    mpContext = nullptr;
    if (uAttr != 0) {
        for (unsigned int i3_3 = 0; i3_3 != 51; i3_3 += 1u) {
            if (sGame::getInstance()->isChargeEffectAttr(static_cast<nGpCourse::E_GP_COURSE_EFFECT>(i3_3), uAttr)) {
                addData(i3_3, uDispF, static_cast<MT_CTSTR>(nullptr));
            }
        }
    }
}

void uGUIBase::cReferenceUIChargesInfo::addAttribute(u32 uAttr, u32 uDispF) {
    u32 i = 0;
    if (uAttr != 0) {
        do {
            if (sGame::getInstance()->isChargeEffectAttr(static_cast<nGpCourse::E_GP_COURSE_EFFECT>(i), uAttr)) {
                addData(i, uDispF, static_cast<MT_CTSTR>(nullptr));
            }
            i += 1u;
        } while (i != 51);
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIChargesInfo::update() {
    DDON_STUB("uGUIBase::cReferenceUIChargesInfo::update")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIChargesInfo::addData(u32 uCharges, u32 uDispF, MT_CTSTR pMsgEdit) {
    DDON_STUB("uGUIBase::cReferenceUIChargesInfo::addData")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIChargesInfo::addDataToCharaSel(u32 uCharges, u64 uEndTime, u32 uDispF, MT_CTSTR pMsgEdit) {
    DDON_STUB("uGUIBase::cReferenceUIChargesInfo::addDataToCharaSel")
    /* stub */
}

void uGUIBase::cReferenceUIChargesInfo::resetState() {
    mRno = 0;
    mCurrentIdxData = 0;
    mCourseTimer = 0.0f;
    mDispTimer = 0.0f;
}

void uGUIBase::cReferenceUIChargesInfo::deleteData() {
    mRno = 0;
    mCurrentIdxData = 0;
    mCourseTimer = 0.0f;
    mDispTimer = 0.0f;
    if (mList.mLength != 0) {
        u32 v0_0 = mList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mList.mpArray[i0_3];
                v1_0 = mList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mList.mpArray));
    }
    mList.mpArray = nullptr;
    mList.mBufsiz = 0;
    mList.mLength = 0;
    mpContext = nullptr;
}

__attribute__((weak)) void uGUIBase::cReferenceUIChargesInfo::setSizeW() {
    DDON_STUB("uGUIBase::cReferenceUIChargesInfo::setSizeW")
    /* stub */
}

__attribute__((weak)) u32 uGUIBase::cReferenceUIChargesInfo::getNextIndex() {
    DDON_STUB("uGUIBase::cReferenceUIChargesInfo::getNextIndex")
    return {};
}

__attribute__((weak)) bool uGUIBase::cReferenceUIChargesInfo::addDataCore(uGUIBase::cReferenceUIChargesInfo::cData* pData, u32 uCharges, u32 uDispF, MT_CTSTR pMsgEdit) {
    DDON_STUB("uGUIBase::cReferenceUIChargesInfo::addDataCore")
    return {};
}

inline uGUIBase::cReferenceUIChargesInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIChargesInfo::MyDTI uGUIBase::cReferenceUIChargesInfo::DTI("uGUIBase::cReferenceUIChargesInfo", &::uGUIBase::cReferenceUIBase::DTI, 344ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIChargesInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIChargesInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIChargesInfo::cData::getDTI() const {
    return uGUIBase::cReferenceUIChargesInfo::cData::DTI;
}

uGUIBase::cReferenceUIChargesInfo::cData::~cData() {
}

inline uGUIBase::cReferenceUIChargesInfo::cData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIChargesInfo::cData::MyDTI uGUIBase::cReferenceUIChargesInfo::cData::DTI("uGUIBase::cReferenceUIChargesInfo::cData", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIChargesInfo::cData::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIChargesInfo::cData;
}

const MtDTI& uGUIBase::cReferenceUIIconItem::getDTI() const {
    return uGUIBase::cReferenceUIIconItem::DTI;
}

uGUIBase::cReferenceUIIconItem::cReferenceUIIconItem() {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::cReferenceUIIconItem")
    /* stub */
}

uGUIBase::cReferenceUIIconItem::~cReferenceUIIconItem() {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::~cReferenceUIIconItem")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo) {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::update() {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::update")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setEmpty() {
    if (mpInstances.elems[0] != nullptr) {
        mpInstances.elems[0]->cGUIInstance::setVisible(false);
    }
    setColor(0u);
    cGUIObjMessage* v1_3 = mpNums;
    if (v1_3 != nullptr) {
        uGUIBase* v1_4 = mpUnit;
        if (v1_4 != nullptr) {
            const char* v1_2;
            if (mIsDispNumZero) {
                v1_2 = "0";
            } else {
                v1_2 = "";
            }
            v1_4->setObjectMessage(static_cast<cGUIObject*>(v1_3), v1_2, 0u, false);
        }
    }
    mLocalNum = 0;
    if (mpQuality != nullptr) {
        if (mpUnit != nullptr) {
            mpUnit->setObjectMessage(static_cast<cGUIObject*>(mpQuality), "", 0u, false);
        }
    }
    mQuality = 0;
    if (mpGradeIcon[0] != nullptr) {
        mpGradeIcon[0]->cGUIObject::setCurrentFrame(0.0f, true);
    }
    if (mpGradeIcon[1] != nullptr) {
        mpGradeIcon[1]->cGUIObject::setCurrentFrame(0.0f, true);
    }
    if (mpGradeIcon[2] != nullptr) {
        mpGradeIcon[2]->cGUIObject::setCurrentFrame(0.0f, true);
    }
    if (mpGradeIcon[3] != nullptr) {
        mpGradeIcon[3]->cGUIObject::setCurrentFrame(0.0f, true);
    }
    mEquipColor = EQUIP_COLOR_DEFAULT;
    if (mpColor != nullptr) {
        mpColor->setCurrentFrame(0.0f, true);
    }
    mIsCheck = false;
    if (mpCheck != nullptr) {
        mpCheck->setVisible(false);
    }
    mItemId = 0;
    mIsArms = false;
    mIsEmpty = true;
    setupIconFrame();
    mIsDispName = false;
}

void uGUIBase::cReferenceUIIconItem::setUnknown(bool isRare) {
    setEmpty();
    mIsEmpty = false;
    setImage(0u);
    setColor(static_cast<u32>(static_cast<unsigned long>(isRare) | 300));
    setupIconFrame();
}

void uGUIBase::cReferenceUIIconItem::setUnknown(rItemList::rItemParam* pParam) {
    if (pParam != nullptr) {
        u8 t0 = pParam->mRank;
        setEmpty();
        mIsEmpty = false;
        setImage(0u);
        if (t0 <= 4) {
            setColor(300u);
        } else {
            setColor(301u);
        }
        setupIconFrame();
    } else {
        setEmpty();
        mIsEmpty = false;
        setImage(0u);
        setColor(300u);
        setupIconFrame();
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setImage(u32 img) {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::setImage")
    /* stub */
}

void uGUIBase::cReferenceUIIconItem::setItem(nGUIItem::cItem* pItem) {
    if (pItem == nullptr) {
        return;
    }
    cItemParam* t0 = pItem->getItemParam();
    if (t0 != nullptr) {
        setIconFromParam(sItemManager::getInstance()->getItemParam(t0->getItemNo()));
        if (mIsArms) {
            setQuality(t0->mCraftParam.mCraftPlusParam);
            setEquipColorFromColorNo(t0->mColorNo);
        } else {
            setNum(t0->mItemParam.mItemNum_Guard);
        }
        mpItemParam = t0;
    } else {
        if (pItem->getResourceParam() != nullptr) {
            setIconFromParam(pItem->getResourceParam());
        } else {
            setIconFromParam(sItemManager::getInstance()->getItemParam(pItem->getItemNo()));
        }
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setSize(uGUIBase::cReferenceUIIconItem::SIZE size) {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::setSize")
    /* stub */
}

void uGUIBase::cReferenceUIIconItem::setScale(f32 scale) {
    cGUIInstAnimation* pInst = mpInstances.elems[0];
    if (pInst != nullptr) {
        pInst->setScaleX(scale);
        pInst->setScaleY(scale);
        cGUIInstAnimation* t0 = mpInstances.elems[1];
        if (t0 != nullptr) {
            t0->setScaleX(scale);
            t0->setScaleY(scale);
            cGUIInstAnimation* t1 = mpInstances.elems[2];
            if (t1 != nullptr) {
                t1->setScaleX(scale);
                t1->setScaleY(scale);
            }
        } else {
            cGUIInstAnimation* t1 = mpInstances.elems[2];
            if (t1 != nullptr) {
                t1->setScaleX(scale);
                t1->setScaleY(scale);
            }
        }
    } else {
        cGUIInstAnimation* t0 = mpInstances.elems[1];
        if (t0 != nullptr) {
            t0->setScaleX(scale);
            t0->setScaleY(scale);
            cGUIInstAnimation* t1 = mpInstances.elems[2];
            if (t1 != nullptr) {
                t1->setScaleX(scale);
                t1->setScaleY(scale);
            }
        } else {
            cGUIInstAnimation* t1 = mpInstances.elems[2];
            if (t1 != nullptr) {
                t1->setScaleX(scale);
                t1->setScaleY(scale);
            }
        }
    }
}

void uGUIBase::cReferenceUIIconItem::setIconFromId(u32 item_id) {
    setIconFromParam(sItemManager::getInstance()->getItemParam(item_id));
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setIconFromParam(rItemList::rItemParam* pItemParam) {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::setIconFromParam")
    /* stub */
}

void uGUIBase::cReferenceUIIconItem::setIconFromParam(cItemParam* pParam) {
    if (pParam == nullptr) {
        return;
    }
    setIconFromParam(sItemManager::getInstance()->getItemParam(pParam->getItemNo()));
    if (mIsArms) {
        setQuality(pParam->mCraftParam.mCraftPlusParam);
        setEquipColorFromColorNo(pParam->mColorNo);
    } else {
        setNum(pParam->mItemParam.mItemNum_Guard);
    }
    mpItemParam = pParam;
}

__attribute__((weak)) MtVector2 uGUIBase::cReferenceUIIconItem::getPointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::getPointerPos")
    __builtin_unreachable();
}

void uGUIBase::cReferenceUIIconItem::setVisible(bool b) {
    if (mpInstances.elems[0] != nullptr) {
        mpInstances.elems[0]->cGUIInstance::setVisible(b);
    }
    if (mpInstances.elems[1] != nullptr) {
        mpInstances.elems[1]->cGUIInstance::setVisible(b);
    }
    if (mpInstances.elems[2] == nullptr) {
        return;
    }
    mpInstances.elems[2]->cGUIInstance::setVisible(b);
}

void uGUIBase::cReferenceUIIconItem::setExecuteTree(bool b, u32 uIdx) {
    if (uIdx > 2u) {
        cGUIUtility::setExecuteTree(static_cast<cGUIInstance*>(mpInstances.elems[0]), b);
        cGUIUtility::setExecuteTree(static_cast<cGUIInstance*>(mpInstances.elems[1]), b);
        cGUIUtility::setExecuteTree(static_cast<cGUIInstance*>(mpInstances.elems[2]), b);
    } else {
        cGUIUtility::setExecuteTree(static_cast<cGUIInstance*>(mpInstances.elems[uIdx]), b);
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setNum(u32 n) {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::setNum")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setQuality(u32 quality) {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::setQuality")
    /* stub */
}

void uGUIBase::cReferenceUIIconItem::setGrade(u32 grade) {
    if (mpGradeIcon[0] != nullptr) {
        if (grade == 0) {
            mpGradeIcon[0]->cGUIObject::setCurrentFrame(0.0f, true);
        } else {
            mpGradeIcon[0]->cGUIObject::setCurrentFrame(1.0f, true);
        }
    }
    if (mpGradeIcon[1] != nullptr) {
        if (grade <= 1u) {
            mpGradeIcon[1]->cGUIObject::setCurrentFrame(0.0f, true);
        } else {
            mpGradeIcon[1]->cGUIObject::setCurrentFrame(1.0f, true);
        }
    }
    if (mpGradeIcon[2] != nullptr) {
        if (grade <= 2u) {
            mpGradeIcon[2]->cGUIObject::setCurrentFrame(0.0f, true);
        } else {
            mpGradeIcon[2]->cGUIObject::setCurrentFrame(1.0f, true);
        }
    }
    if (mpGradeIcon[3] == nullptr) {
        return;
    }
    if (grade <= 3u) {
        mpGradeIcon[3]->cGUIObject::setCurrentFrame(0.0f, true);
    } else {
        mpGradeIcon[3]->cGUIObject::setCurrentFrame(1.0f, true);
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setEquipColorFromColorNo(u32 color_no) {
    switch (color_no - 3u) {
        case 0:
        {
            mEquipColor = EQUIP_COLOR_RED;
            if (mpColor != nullptr) {
                mpColor->setCurrentFrame(1.0f, true);
            }
            break;
        }
        case 1:
        {
            mEquipColor = EQUIP_COLOR_GREEN;
            if (mpColor != nullptr) {
                mpColor->setCurrentFrame(3.0f, true);
            }
            break;
        }
        case 2:
        {
            mEquipColor = EQUIP_COLOR_BLUE;
            if (mpColor != nullptr) {
                mpColor->setCurrentFrame(5.0f, true);
            }
            break;
        }
        case 3:
        {
            mEquipColor = EQUIP_COLOR_YELLOW;
            if (mpColor != nullptr) {
                mpColor->setCurrentFrame(2.0f, true);
            }
            break;
        }
        case 4:
        {
            mEquipColor = EQUIP_COLOR_PURPLE;
            if (mpColor != nullptr) {
                mpColor->setCurrentFrame(4.0f, true);
            }
            break;
        }
        case 5:
        {
            mEquipColor = EQUIP_COLOR_BLACK;
            if (mpColor != nullptr) {
                mpColor->setCurrentFrame(6.0f, true);
            }
            break;
        }
        default:
        {
            mEquipColor = EQUIP_COLOR_DEFAULT;
            if (mpColor != nullptr) {
                mpColor->setCurrentFrame(0.0f, true);
            }
            break;
        }
    }
}

void uGUIBase::cReferenceUIIconItem::setCheck(bool b) {
    mIsCheck = b;
    if (mpCheck == nullptr) {
        return;
    }
    mpCheck->setVisible(b);
}

void uGUIBase::cReferenceUIIconItem::setFocus(bool b) {
    mIsFocus = b;
    if (mpFocus != nullptr) {
        mpFocus->setVisible(b);
        if (!mIsAutoDispName) {
            if (!mIsFocus) {
                setDispName(b);
            }
        } else {
            setDispName(b);
        }
    } else {
        if (!mIsAutoDispName) {
            if (!b) {
                setDispName(b);
            }
        } else {
            setDispName(b);
        }
    }
}

bool uGUIBase::cReferenceUIIconItem::isFocus() {
    return mIsFocus;
}

void uGUIBase::cReferenceUIIconItem::setAutoDispName(bool b, bool apply) {
    if (mIsAutoDispName == b) {
        return;
    }
    mIsAutoDispName = b;
    if (!apply) {
        return;
    }
    if (mIsDispName == b) {
        return;
    }
    if (b) {
        if (mIsFocus) {
            setDispName(true);
        }
    } else {
        mIsDispName = false;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setDispName(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::setDispName")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setDispMsg(MT_CTSTR msg, bool isForceDraw) {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::setDispMsg")
    /* stub */
}

void uGUIBase::cReferenceUIIconItem::addMouseTouchList(cControl* pOwner, s32 pos, s32 vol) {
    if (pOwner == nullptr) {
        return;
    }
    cGUIInstAnimation* t0 = mpInstance;
    pOwner->addMouseTouchList(static_cast<cGUIInstance*>(t0), static_cast<cGUIObject*>(getMouseOverObject()), pos, static_cast<cGUIObject*>(nullptr), 1u, 1u, vol);
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setColor(u32 color) {
    if (mpBase00 != nullptr) {
        mpBase00->setCurrentFrame(static_cast<float>(color), true);
    }
    if (mpBase01 != nullptr) {
        mpBase01->setCurrentFrame(static_cast<float>(color), true);
    }
    if (mpBase02 != nullptr) {
        mpBase02->setCurrentFrame(static_cast<float>(color), true);
    }
    if (mpBase03 != nullptr) {
        mpBase03->setCurrentFrame(static_cast<float>(color), true);
    }
    if (mpBase04 != nullptr) {
        mpBase04->setCurrentFrame(static_cast<float>(color), true);
    }
    if (mpBase05 == nullptr) {
        return;
    }
    mpBase05->setCurrentFrame(static_cast<float>(color), true);
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::setupIconFrame() {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::setupIconFrame")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconItem::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUIIconItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconItem::MyDTI uGUIBase::cReferenceUIIconItem::DTI("uGUIBase::cReferenceUIIconItem", &::uGUIBase::cReferenceUIBase::DTI, 384ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIIconItem::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIIconItem::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIIconEquip::getDTI() const {
    return uGUIBase::cReferenceUIIconEquip::DTI;
}

uGUIBase::cReferenceUIIconEquip::cReferenceUIIconEquip() {
    DDON_STUB("uGUIBase::cReferenceUIIconEquip::cReferenceUIIconEquip")
    /* stub */
}

uGUIBase::cReferenceUIIconEquip::~cReferenceUIIconEquip() {
}

void uGUIBase::cReferenceUIIconEquip::setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo) {
    this->uGUIBase::cReferenceUIIconItem::setup(pParentGUI, pInstItemIcon, pInstFixIconBase, pInstFixIconInfo);
}

void uGUIBase::cReferenceUIIconEquip::setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo, cGUIInstance* pInstCategoryIcon, u32 slot_no) {
    mpInstAnimCategoryIcon = static_cast<cGUIInstAnimation*>(pInstCategoryIcon);
    mSlotNo = slot_no;
    this->uGUIBase::cReferenceUIIconItem::setup(pParentGUI, pInstItemIcon, pInstFixIconBase, pInstFixIconInfo);
}

void uGUIBase::cReferenceUIIconEquip::setEmpty() {
    static const s32 cate_frame[17] = {
        0,
        1,
        2,
        4,
        5,
        3,
        6,
        7,
        8,
        9,
        10,
        10,
        11,
        11,
        11,
        11,
        11,
    };
    this->uGUIBase::cReferenceUIIconItem::setEmpty();
    u32 v0_1 = mSlotNo;
    unsigned int i0_0 = 0;
    for (const unsigned int* p0_2 = nGUIExt::EQUIP_SLOT_TABLE; i0_0 <= 16u; i0_0 = i0_0 + 1u, p0_2 += 1) {
        if ((*p0_2) == v0_1) {
            if (mpInstAnimCategoryIcon != nullptr) {
                mpInstAnimCategoryIcon->setCurrentFrame(static_cast<float>(cate_frame[i0_0]), true);
                if (mpInstAnimCategoryIcon != nullptr) {
                    mpInstAnimCategoryIcon->setVisible(true);
                }
            }
            return;
        }
    }
}

void uGUIBase::cReferenceUIIconEquip::setIconFromParam(rItemList::rItemParam* pItemParam) {
    this->uGUIBase::cReferenceUIIconItem::setIconFromParam(pItemParam);
    if (mItemId == 0) {
        return;
    }
    if (mpInstAnimCategoryIcon == nullptr) {
        return;
    }
    mpInstAnimCategoryIcon->setVisible(false);
}

void uGUIBase::cReferenceUIIconEquip::setIconFromParam(cItemParam* pParam) {
    if (pParam != nullptr) {
        setIconFromParam(sItemManager::getInstance()->getItemParam(pParam->getItemNo()));
        if (mIsArms) {
            setQuality(pParam->mCraftParam.mCraftPlusParam);
            setEquipColorFromColorNo(pParam->mColorNo);
        } else {
            setNum(pParam->mItemParam.mItemNum_Guard);
        }
        mpItemParam = pParam;
    }
    if (mItemId == 0) {
        return;
    }
    if (mpInstAnimCategoryIcon == nullptr) {
        return;
    }
    mpInstAnimCategoryIcon->setVisible(false);
}

void uGUIBase::cReferenceUIIconEquip::setLock() {
    setColor(310u);
}

inline uGUIBase::cReferenceUIIconEquip::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconEquip::MyDTI uGUIBase::cReferenceUIIconEquip::DTI("uGUIBase::cReferenceUIIconEquip", &::uGUIBase::cReferenceUIIconItem::DTI, 400ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIIconEquip::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIIconEquip::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIIconItemCharges::getDTI() const {
    return uGUIBase::cReferenceUIIconItemCharges::DTI;
}

uGUIBase::cReferenceUIIconItemCharges::cReferenceUIIconItemCharges() {
    DDON_STUB("uGUIBase::cReferenceUIIconItemCharges::cReferenceUIIconItemCharges")
    /* stub */
}

uGUIBase::cReferenceUIIconItemCharges::~cReferenceUIIconItemCharges() {
}

void uGUIBase::cReferenceUIIconItemCharges::setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo) {
    this->uGUIBase::cReferenceUIIconItem::setup(pParentGUI, pInstItemIcon, pInstFixIconBase, pInstFixIconInfo);
}

void uGUIBase::cReferenceUIIconItemCharges::setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo, cGUIInstance* pInstChargesInfo) {
    this->uGUIBase::cReferenceUIIconItem::setup(pParentGUI, pInstItemIcon, pInstFixIconBase, pInstFixIconInfo);
    mChargesInfo.setup(pParentGUI, pInstChargesInfo, 0u);
}

void uGUIBase::cReferenceUIIconItemCharges::update() {
    this->uGUIBase::cReferenceUIIconItem::update();
    mChargesInfo.uGUIBase::cReferenceUIChargesInfo::update();
}

inline uGUIBase::cReferenceUIIconItemCharges::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconItemCharges::MyDTI uGUIBase::cReferenceUIIconItemCharges::DTI("uGUIBase::cReferenceUIIconItemCharges", &::uGUIBase::cReferenceUIIconItem::DTI, 720ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIIconItemCharges::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIIconItemCharges::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIIconSkill::getDTI() const {
    return uGUIBase::cReferenceUIIconSkill::DTI;
}

uGUIBase::cReferenceUIIconSkill::cReferenceUIIconSkill() {
    mType = TYPE_SKILL;
    mId = 0xFFFF;
    mLevel = 0;
    mTicket = sArchiveManager::INVALID_TICKET;
    mpObjTexSetIcon = nullptr;
    mpObjMsgLv = nullptr;
    mpObjNullLv = nullptr;
    mpObjTexFocus = nullptr;
    mpObjTexBase = nullptr;
    mpObjTexFrame = nullptr;
    mpObjTexHighlight = nullptr;
    mpObjTexIcon = nullptr;
    mpInstAnimInfo = nullptr;
    mpInstAnimBase = nullptr;
    mpInstAnimIcon = nullptr;
    mIsLevelVisible = true;
    mIsEnable = true;
    mIsFocus = false;
}

uGUIBase::cReferenceUIIconSkill::~cReferenceUIIconSkill() {
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mTicket == t0) {
        return;
    }
    sArchiveManager::getInstance()->returnTicket(mTicket);
    mTicket = t0;
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconSkill::setup(uGUIBase* pUnit, cGUIInstance* pInstIcon, cGUIInstance* pInstBase, cGUIInstance* pInstInfo) {
    DDON_STUB("uGUIBase::cReferenceUIIconSkill::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconSkill::update() {
    DDON_STUB("uGUIBase::cReferenceUIIconSkill::update")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconSkill::setImage(u32 id) {
    DDON_STUB("uGUIBase::cReferenceUIIconSkill::setImage")
    /* stub */
}

void uGUIBase::cReferenceUIIconSkill::setEmpty() {
    mId = 0xFFFF;
    if (mpObjTexIcon != nullptr) {
        mpObjTexIcon->setVisible(false);
        if (mpObjTexIcon != nullptr) {
            mpObjTexIcon->setReferenceTexture(static_cast<rTexture*>(nullptr));
        }
    }
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mTicket != t0) {
        sArchiveManager::getInstance()->returnTicket(mTicket);
        mTicket = t0;
    }
    mIsEnable = true;
    if (mpUnit != nullptr) {
        if (mpObjMsgLv != nullptr) {
            mpUnit->setObjectMessage(static_cast<cGUIObject*>(mpObjMsgLv), "", 0u, false);
            if (mpObjNullLv != nullptr) {
                mpObjNullLv->setVisible(false);
            }
        }
    }
    mLevel = 0;
    u16 v3_0 = mId;
    float v3_8;
    if (mType == TYPE_SKILL) {
        v3_8 = 0.0f;
    } else {
        v3_8 = 100.0f;
    }
    float v4_9;
    if (v3_0 == 0xFFFF) {
        v4_9 = 0.0f;
    } else {
        if (mIsEnable) {
            v4_9 = 1.0f;
        } else {
            v4_9 = 10.0f;
        }
    }
    if (mpInstAnimBase != nullptr) {
        mpInstAnimBase->setCurrentFrame(v3_8 + v4_9, true);
    }
    if (mpObjTexSetIcon != nullptr) {
        mpObjTexSetIcon->setVisible(false);
        return;
    }
}

void uGUIBase::cReferenceUIIconSkill::setVisible(bool isVisible) {
    if (mpInstAnimIcon != nullptr) {
        mpInstAnimIcon->setVisible(isVisible);
    }
    if (mpInstAnimBase != nullptr) {
        mpInstAnimBase->setVisible(isVisible);
    }
    if (mpInstAnimInfo == nullptr) {
        return;
    }
    mpInstAnimInfo->setVisible(isVisible);
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconSkill::setLevel(u32 lv) {
    DDON_STUB("uGUIBase::cReferenceUIIconSkill::setLevel")
    /* stub */
}

void uGUIBase::cReferenceUIIconSkill::setLevelVisible(bool isVisible) {
    mIsLevelVisible = isVisible;
    setLevel(mLevel);
}

void uGUIBase::cReferenceUIIconSkill::setSetIcon(bool isSet) {
    if (mpObjTexSetIcon == nullptr) {
        return;
    }
    mpObjTexSetIcon->setVisible(isSet);
}

void uGUIBase::cReferenceUIIconSkill::setFocus(bool isFocus) {
    mIsFocus = isFocus;
    if (mpObjTexFocus == nullptr) {
        return;
    }
    mpObjTexFocus->setVisible(isFocus);
}

bool uGUIBase::cReferenceUIIconSkill::isFocus() {
    return mIsFocus;
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconSkill::setEnable(bool isEnable) {
    DDON_STUB("uGUIBase::cReferenceUIIconSkill::setEnable")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconSkill::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIIconSkill::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUIIconSkill::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconSkill::MyDTI uGUIBase::cReferenceUIIconSkill::DTI("uGUIBase::cReferenceUIIconSkill", &::uGUIBase::cReferenceUIBase::DTI, 192ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconSkill::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconSkill;
}

const MtDTI& uGUIBase::cReferenceUIIconStatus::getDTI() const {
    return uGUIBase::cReferenceUIIconStatus::DTI;
}

uGUIBase::cReferenceUIIconStatus::cReferenceUIIconStatus() {
    mpNull_gauge_up = nullptr;
    mOcdId = 0;
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconStatus::setup(cGUIInstance* pInst) {
    DDON_STUB("uGUIBase::cReferenceUIIconStatus::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconStatus::set(u32 ocdId) {
    DDON_STUB("uGUIBase::cReferenceUIIconStatus::set")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconStatus::set(u32 ocdId, f32 ocdAccumulation, f32 ocdEnduranceMax) {
    DDON_STUB("uGUIBase::cReferenceUIIconStatus::set")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconStatus::setOccurred(u32 ocdId, f32 animFrame) {
    DDON_STUB("uGUIBase::cReferenceUIIconStatus::setOccurred")
    /* stub */
}

__attribute__((weak)) f32 uGUIBase::cReferenceUIIconStatus::GetIconFrameFromOcdId(u32 ocdId) {
    DDON_STUB("uGUIBase::cReferenceUIIconStatus::GetIconFrameFromOcdId")
    return {};
}

inline uGUIBase::cReferenceUIIconStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconStatus::MyDTI uGUIBase::cReferenceUIIconStatus::DTI("uGUIBase::cReferenceUIIconStatus", &::uGUIBase::cSupportInstAnim::DTI, 72ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconStatus::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconStatus;
}

const MtDTI& uGUIBase::cReferenceUIIconCraftLv::getDTI() const {
    return uGUIBase::cReferenceUIIconCraftLv::DTI;
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconCraftLv::setup(uGUIBase* pUnit, cGUIInstance* pInst) {
    DDON_STUB("uGUIBase::cReferenceUIIconCraftLv::setup")
    /* stub */
}

void uGUIBase::cReferenceUIIconCraftLv::setLevel(u32 level) {
    cGUIObject* t0 = mpObjIcon;
    if (t0 == nullptr) {
        return;
    }
    if (level != 0) {
        t0->mAttr = t0->mAttr | 8u;
        if (static_cast<unsigned int>(((static_cast<unsigned long>(level) * 0xCCCCCCCDul) >> 35) + 1ul) > 2) {
            t0->setCurrentFrame(3.0f, false);
        } else {
            t0->setCurrentFrame(static_cast<float>(static_cast<unsigned int>(((static_cast<unsigned long>(level) * 0xCCCCCCCDul) >> 35) + 1ul)), false);
        }
        mpObjIcon->setVisible(true);
    } else {
        t0->setVisible(false);
    }
}

inline uGUIBase::cReferenceUIIconCraftLv::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconCraftLv::MyDTI uGUIBase::cReferenceUIIconCraftLv::DTI("uGUIBase::cReferenceUIIconCraftLv", &::uGUIBase::cReferenceUIBase::DTI, 88ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconCraftLv::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconCraftLv;
}

const MtDTI& uGUIBase::cReferenceUIIconStorage::getDTI() const {
    return uGUIBase::cReferenceUIIconStorage::DTI;
}

void uGUIBase::cReferenceUIIconStorage::setup(uGUIBase* pUnit, cGUIInstance* pInst) {
    mpUnit = pUnit;
    registerThis();
    mpInstance = static_cast<cGUIInstAnimation*>(pInst);
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconStorage::setImage(u32 bag_type, cItemParam* pParam) {
    DDON_STUB("uGUIBase::cReferenceUIIconStorage::setImage")
    /* stub */
}

inline uGUIBase::cReferenceUIIconStorage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconStorage::MyDTI uGUIBase::cReferenceUIIconStorage::DTI("uGUIBase::cReferenceUIIconStorage", &::uGUIBase::cReferenceUIBase::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconStorage::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconStorage;
}

const MtDTI& uGUIBase::cReferenceUIIconShake::getDTI() const {
    return uGUIBase::cReferenceUIIconShake::DTI;
}

void uGUIBase::cReferenceUIIconShake::setup(uGUIBase* pUnit, cGUIInstance* pInstShake00, cGUIInstance* pInstShake01) {
    mpUnit = pUnit;
    registerThis();
    mpInstance = static_cast<cGUIInstAnimation*>(pInstShake00);
    mpInstShake00 = static_cast<cGUIInstAnimation*>(pInstShake00);
    mpInstShake01 = static_cast<cGUIInstAnimation*>(pInstShake01);
    mModeRequest = MODE_INVISIBLE;
    if (0.0f >= mFrame) {
        if (pInstShake00 != nullptr) {
            pInstShake00->setVisible(false);
            if (mpInstShake01 != nullptr) {
                mpInstShake01->setVisible(false);
            }
        } else {
            if (pInstShake01 != nullptr) {
                pInstShake01->setVisible(false);
            }
        }
        mMode = MODE_INVISIBLE;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconShake::setMode(uGUIBase::cReferenceUIIconShake::MODE mode) {
    DDON_STUB("uGUIBase::cReferenceUIIconShake::setMode")
    /* stub */
}

void uGUIBase::cReferenceUIIconShake::updateTimer(f32 delta_time) {
    if (mFrame > 0.0f) {
        mFrame = mFrame - delta_time;
        if (0.0f >= mFrame) {
            mFrame = 0.0f;
            setMode(mModeRequest);
        }
    }
}

inline uGUIBase::cReferenceUIIconShake::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconShake::MyDTI uGUIBase::cReferenceUIIconShake::DTI("uGUIBase::cReferenceUIIconShake", &::uGUIBase::cReferenceUIBase::DTI, 104ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIIconShake::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIIconShake::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIIconSCM::getDTI() const {
    return uGUIBase::cReferenceUIIconSCM::DTI;
}

uGUIBase::cReferenceUIIconSCM::cReferenceUIIconSCM() {
}

void uGUIBase::cReferenceUIIconSCM::setup(uGUIBase* pBase, cGUIInstance* pInst) {
    mpUnit = pBase;
    mpInstance = static_cast<cGUIInstAnimation*>(pInst);
    if (pInst == nullptr) {
        return;
    }
    pInst->setVisible(false);
}

inline uGUIBase::cReferenceUIIconSCM::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconSCM::MyDTI uGUIBase::cReferenceUIIconSCM::DTI("uGUIBase::cReferenceUIIconSCM", &::uGUIBase::cReferenceUIBase::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconSCM::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconSCM;
}

const MtDTI& uGUIBase::cReferenceUIIconGameMenu::getDTI() const {
    return uGUIBase::cReferenceUIIconGameMenu::DTI;
}

uGUIBase::cReferenceUIIconGameMenu::cReferenceUIIconGameMenu() {
}

void uGUIBase::cReferenceUIIconGameMenu::setup(uGUIBase* pBase, cGUIInstance* pInst) {
    mpUnit = pBase;
    mpInstance = static_cast<cGUIInstAnimation*>(pInst);
}

inline uGUIBase::cReferenceUIIconGameMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconGameMenu::MyDTI uGUIBase::cReferenceUIIconGameMenu::DTI("uGUIBase::cReferenceUIIconGameMenu", &::uGUIBase::cReferenceUIBase::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconGameMenu::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconGameMenu;
}

const MtDTI& uGUIBase::cReferenceUIIconComm::getDTI() const {
    return uGUIBase::cReferenceUIIconComm::DTI;
}

uGUIBase::cReferenceUIIconComm::cReferenceUIIconComm() {
}

void uGUIBase::cReferenceUIIconComm::setup(uGUIBase* pBase, cGUIInstance* pInst) {
    mpUnit = pBase;
    mpInstance = static_cast<cGUIInstAnimation*>(pInst);
}

inline uGUIBase::cReferenceUIIconComm::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconComm::MyDTI uGUIBase::cReferenceUIIconComm::DTI("uGUIBase::cReferenceUIIconComm", &::uGUIBase::cReferenceUIBase::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconComm::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconComm;
}

const MtDTI& uGUIBase::cReferenceUIIconOnlineStatus::getDTI() const {
    return uGUIBase::cReferenceUIIconOnlineStatus::DTI;
}

uGUIBase::cReferenceUIIconOnlineStatus::cReferenceUIIconOnlineStatus() {
}

void uGUIBase::cReferenceUIIconOnlineStatus::setup(uGUIBase* pBase, cGUIInstance* pInst) {
    mpUnit = pBase;
    registerThis();
    mpInstance = static_cast<cGUIInstAnimation*>(pInst);
}

void uGUIBase::cReferenceUIIconOnlineStatus::setOnlineStatus(u32 onlineStatus) {
    static const s32 fixfs[13] = {
        -1,
        1,
        0,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        0,
        0,
    };
    if (onlineStatus != 0) {
        if (onlineStatus <= 12u) {
            if (mpInstance != nullptr) {
                mpInstance->gotoAndStop(static_cast<float>(fixfs[onlineStatus]), true);
            }
            if (mpInstance != nullptr) {
                mpInstance->setVisible(true);
            }
        } else {
            if (mpInstance != nullptr) {
                mpInstance->setVisible(false);
            }
        }
    } else {
        if (mpInstance != nullptr) {
            mpInstance->setVisible(false);
        }
    }
}

inline uGUIBase::cReferenceUIIconOnlineStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconOnlineStatus::MyDTI uGUIBase::cReferenceUIIconOnlineStatus::DTI("uGUIBase::cReferenceUIIconOnlineStatus", &::uGUIBase::cReferenceUIBase::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconOnlineStatus::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconOnlineStatus;
}

const MtDTI& uGUIBase::cReferenceUIIconClanTitle::getDTI() const {
    return uGUIBase::cReferenceUIIconClanTitle::DTI;
}

inline uGUIBase::cReferenceUIIconClanTitle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconClanTitle::MyDTI uGUIBase::cReferenceUIIconClanTitle::DTI("uGUIBase::cReferenceUIIconClanTitle", &::uGUIBase::cReferenceUIBase::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconClanTitle::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconClanTitle;
}

const MtDTI& uGUIBase::cReferenceUIGammaBoard::getDTI() const {
    return uGUIBase::cReferenceUIGammaBoard::DTI;
}

uGUIBase::cReferenceUIGammaBoard::cReferenceUIGammaBoard() {
    mpObjMsgB = nullptr;
    mpObjMsgA = nullptr;
    mpObjTexB = nullptr;
    mpObjTexA = nullptr;
    mpInstB = nullptr;
    mpInstA = nullptr;
}

__attribute__((weak)) void uGUIBase::cReferenceUIGammaBoard::setup(uGUIBase* pBase, cGUIInstance* pInstA, cGUIInstance* pInstB) {
    DDON_STUB("uGUIBase::cReferenceUIGammaBoard::setup")
    /* stub */
}

MtObject* uGUIBase::cReferenceUIGammaBoard::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIGammaBoard;
}

const MtDTI& uGUIBase::cReferenceUICheckbox::getDTI() const {
    return uGUIBase::cReferenceUICheckbox::DTI;
}

void* uGUIBase::cReferenceUICheckbox::operator new(size_t sz, u32 align) {
    return uGUIBase::cReferenceUICheckbox::getAllocator()->memAlloc(sz, align, uGUIBase::cReferenceUICheckbox::DTI.getID());
}

uGUIBase::cReferenceUICheckbox::cReferenceUICheckbox() {
    mFocus = false;
    mCheck = false;
    mIsForbid = false;
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckbox::setup(uGUIBase* pBase, u32 instID) {
    DDON_STUB("uGUIBase::cReferenceUICheckbox::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckbox::setup(uGUIBase* pBase, cGUIInstAnimation* pInst) {
    DDON_STUB("uGUIBase::cReferenceUICheckbox::setup")
    /* stub */
}

void uGUIBase::cReferenceUICheckbox::setFocus(bool b) {
    mFocus = b;
    _update();
}

bool uGUIBase::cReferenceUICheckbox::isFocus() {
    return mFocus;
}

void uGUIBase::cReferenceUICheckbox::update() {
    updatePointerPos();
    _update();
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckbox::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUICheckbox::updatePointerPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckbox::_update() {
    DDON_STUB("uGUIBase::cReferenceUICheckbox::_update")
    /* stub */
}

inline uGUIBase::cReferenceUICheckbox::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUICheckbox::MyDTI uGUIBase::cReferenceUICheckbox::DTI("uGUIBase::cReferenceUICheckbox", &::uGUIBase::cReferenceUIBase::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUICheckbox::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUICheckbox;
}

const MtDTI& uGUIBase::cReferenceUIButton2::getDTI() const {
    return uGUIBase::cReferenceUIButton2::DTI;
}

__attribute__((weak)) void uGUIBase::cReferenceUIButton2::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, MT_CTSTR pMsgInit, f32 fSize) {
    DDON_STUB("uGUIBase::cReferenceUIButton2::setup")
    /* stub */
}

inline uGUIBase::cReferenceUIButton2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIButton2::MyDTI uGUIBase::cReferenceUIButton2::DTI("uGUIBase::cReferenceUIButton2", &::uGUIBase::cReferenceUIButton::DTI, 400ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIButton2::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIButton2::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIToggleBtn::getDTI() const {
    return uGUIBase::cReferenceUIToggleBtn::DTI;
}

uGUIBase::cReferenceUIToggleBtn::cReferenceUIToggleBtn() {
    mType = 0;
    mValue = 0;
    mpCtrl = nullptr;
    mpObjTxt = nullptr;
    mpObjInfoL = nullptr;
    mpObjInfoC = nullptr;
    mpObjInfoR = nullptr;
    mpObjInfoColAdjust = nullptr;
    mpObjTexRight = nullptr;
    mpObjTexLeft = nullptr;
    mpObjNullIcon = nullptr;
    mpObjNullInfo = nullptr;
    mpObjNullBtn = nullptr;
    mValueForbid = 2;
    mIsEnable = true;
    mFocus = false;
    mSwitch = false;
    mIsTxtVisible = true;
}

__attribute__((weak)) void uGUIBase::cReferenceUIToggleBtn::setup(uGUIBase* pParentGUI, cGUIInstance* pInst, u8 uValueInit, u8 uValueForbid, u8 type, MT_CTSTR str) {
    DDON_STUB("uGUIBase::cReferenceUIToggleBtn::setup")
    /* stub */
}

void uGUIBase::cReferenceUIToggleBtn::update() {
    mSwitch = false;
    updatePointerPos();
    if (mpInstance == nullptr) {
        return;
    }
    if (mIsEnable) {
        if (mFocus) {
            if (mpCtrl != nullptr) {
                mpCtrl->mCtrlF = mpCtrl->mCtrlF & 0xFFFFFFF7u;
            }
        } else {
            if (mpCtrl != nullptr) {
                mpCtrl->mCtrlF = mpCtrl->mCtrlF | 8u;
            }
        }
    } else {
        if (mpCtrl != nullptr) {
            mpCtrl->mCtrlF = mpCtrl->mCtrlF | 8u;
        }
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIToggleBtn::execute() {
    DDON_STUB("uGUIBase::cReferenceUIToggleBtn::execute")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIToggleBtn::setFocus(bool isFocus) {
    DDON_STUB("uGUIBase::cReferenceUIToggleBtn::setFocus")
    /* stub */
}

bool uGUIBase::cReferenceUIToggleBtn::isFocus() {
    return mFocus;
}

__attribute__((weak)) void uGUIBase::cReferenceUIToggleBtn::setTxt(MT_CTSTR str) {
    DDON_STUB("uGUIBase::cReferenceUIToggleBtn::setTxt")
    /* stub */
}

void uGUIBase::cReferenceUIToggleBtn::setTxtVisible(bool isVisible) {
    mIsTxtVisible = isVisible;
    if (mpObjNullInfo == nullptr) {
        return;
    }
    mpObjNullInfo->setVisible(isVisible);
}

__attribute__((weak)) void uGUIBase::cReferenceUIToggleBtn::setValue(u8 uValue) {
    DDON_STUB("uGUIBase::cReferenceUIToggleBtn::setValue")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIToggleBtn::setValueForbid(u8 uValue, bool bReset) {
    DDON_STUB("uGUIBase::cReferenceUIToggleBtn::setValueForbid")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIToggleBtn::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIToggleBtn::updatePointerPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIToggleBtn::setupIconFrame() {
    DDON_STUB("uGUIBase::cReferenceUIToggleBtn::setupIconFrame")
    /* stub */
}

inline uGUIBase::cReferenceUIToggleBtn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIToggleBtn::MyDTI uGUIBase::cReferenceUIToggleBtn::DTI("uGUIBase::cReferenceUIToggleBtn", &::uGUIBase::cReferenceUIBase::DTI, 176ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIToggleBtn::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIToggleBtn;
}

const MtDTI& uGUIBase::cReferenceUIPullDownSkill::getDTI() const {
    return uGUIBase::cReferenceUIPullDownSkill::DTI;
}

uGUIBase::cReferenceUIPullDownSkill::cReferenceUIPullDownSkill() {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::cReferenceUIPullDownSkill")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDownSkill::addMessage(MT_CTSTR str, MT_CTSTR num) {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::addMessage")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDownSkill::changeTitleText(MT_CTSTR title, MT_CTSTR num) {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::changeTitleText")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDownSkill::setup(uGUIBase* pBase, cGUIInstance* pPulldown, cGUIInstance* pMaskPulldown, cGUIInstance* pWindow, cGUIInstance* pCursor, cGUIInstance* pMaskPulldownList, cGUIInstance* pMsgList, cGUIInstance* pNullPullScrollId, cGUIInstance* pNullScroll01Id, cGUIInstance* pScrbar, f32 uiWidth, s32 visibleSize) {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDownSkill::updateString(uGUIBase::cReferenceUIPullDown::cData* pData, u32 curIdx) {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::updateString")
    /* stub */
}

__attribute__((weak)) uGUIBase::cReferenceUIPullDown::cData* uGUIBase::cReferenceUIPullDownSkill::newData() {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::newData")
    return nullptr;
}

__attribute__((weak)) uGUIBase::cReferenceUIPullDownSkill::cMsgEx* uGUIBase::cReferenceUIPullDownSkill::newMsg() {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::newMsg")
    return nullptr;
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDownSkill::changeTitleText(u32 idx) {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::changeTitleText")
    /* stub */
}

inline uGUIBase::cReferenceUIPullDownSkill::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIPullDownSkill::MyDTI uGUIBase::cReferenceUIPullDownSkill::DTI("uGUIBase::cReferenceUIPullDownSkill", &::uGUIBase::cReferenceUIPullDown::DTI, 1680ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIPullDownSkill::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIPullDownSkill::cMsgEx::getDTI() const {
    return uGUIBase::cReferenceUIPullDownSkill::cMsgEx::DTI;
}

uGUIBase::cReferenceUIPullDownSkill::cMsgEx::~cMsgEx() {
}

inline uGUIBase::cReferenceUIPullDownSkill::cMsgEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIPullDownSkill::cMsgEx::MyDTI uGUIBase::cReferenceUIPullDownSkill::cMsgEx::DTI("uGUIBase::cReferenceUIPullDownSkill::cMsgEx", &::uGUIBase::cReferenceUIPullDown::cMsg::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIPullDownSkill::cMsgEx::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::cMsgEx::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIPullDownSkill::cDataEx::getDTI() const {
    return uGUIBase::cReferenceUIPullDownSkill::cDataEx::DTI;
}

__attribute__((weak)) void uGUIBase::cReferenceUIPullDownSkill::cDataEx::setup(uGUIBase::cReferenceUIPullDown* pPar, cGUIInstance* pInstance) {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::cDataEx::setup")
    /* stub */
}

inline uGUIBase::cReferenceUIPullDownSkill::cDataEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIPullDownSkill::cDataEx::MyDTI uGUIBase::cReferenceUIPullDownSkill::cDataEx::DTI("uGUIBase::cReferenceUIPullDownSkill::cDataEx", &::uGUIBase::cReferenceUIPullDown::cData::DTI, 176ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIPullDownSkill::cDataEx::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIPullDownSkill::cDataEx::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUISimpleBtn::getDTI() const {
    return uGUIBase::cReferenceUISimpleBtn::DTI;
}

uGUIBase::cReferenceUISimpleBtn::cReferenceUISimpleBtn() {
    DDON_STUB("uGUIBase::cReferenceUISimpleBtn::cReferenceUISimpleBtn")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUISimpleBtn::setup(uGUIBase* pBase, u32 instID, u32 ptrObjID, u32 msgObjID, MT_CTSTR pMsg) {
    DDON_STUB("uGUIBase::cReferenceUISimpleBtn::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUISimpleBtn::setFocus(bool b) {
    DDON_STUB("uGUIBase::cReferenceUISimpleBtn::setFocus")
    /* stub */
}

bool uGUIBase::cReferenceUISimpleBtn::isFocus() {
    return mFocus;
}

__attribute__((weak)) MtVector2 uGUIBase::cReferenceUISimpleBtn::getPointerPos() {
    DDON_STUB("uGUIBase::cReferenceUISimpleBtn::getPointerPos")
    __builtin_unreachable();
}

__attribute__((weak)) void uGUIBase::cReferenceUISimpleBtn::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUISimpleBtn::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUISimpleBtn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUISimpleBtn::MyDTI uGUIBase::cReferenceUISimpleBtn::DTI("uGUIBase::cReferenceUISimpleBtn", &::uGUIBase::cReferenceUIBase::DTI, 360ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUISimpleBtn::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUISimpleBtn::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIEditBtn::getDTI() const {
    return uGUIBase::cReferenceUIEditBtn::DTI;
}

uGUIBase::cReferenceUIEditBtn::cReferenceUIEditBtn() {
    mFocus = false;
    mDisable = false;
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditBtn::setup(uGUIBase* pBase, u32 instID) {
    DDON_STUB("uGUIBase::cReferenceUIEditBtn::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditBtn::setFocus(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIEditBtn::setFocus")
    /* stub */
}

bool uGUIBase::cReferenceUIEditBtn::isFocus() {
    return mFocus;
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditBtn::disable(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIEditBtn::disable")
    /* stub */
}

inline uGUIBase::cReferenceUIEditBtn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIEditBtn::MyDTI uGUIBase::cReferenceUIEditBtn::DTI("uGUIBase::cReferenceUIEditBtn", &::uGUIBase::cReferenceUIBase::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIEditBtn::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIEditBtn;
}

const MtDTI& uGUIBase::cReferenceUICheckList::getDTI() const {
    return uGUIBase::cReferenceUICheckList::DTI;
}

uGUIBase::cReferenceUICheckList::cReferenceUICheckList() {
    DDON_STUB("uGUIBase::cReferenceUICheckList::cReferenceUICheckList")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckList::setup(uGUIBase* pBase, s32 num, s32 col, u32 topNullID, u32 nullCheckboxID, u32 checkboxID, u32 msg_checkID, u32 msg_titleID, u32 windowID, u32 window_frameID, u32 msg_btnID, u32 msg_cancel_btnID) {
    DDON_STUB("uGUIBase::cReferenceUICheckList::setup")
    /* stub */
}

void uGUIBase::cReferenceUICheckList::execute() {
    if (mData.mpINST_Null == nullptr) {
        return;
    }
    if ((mData.mpINST_Null->mAttr & 9u) != 9) {
        return;
    }
    if (mCtrlFocus == mCtrlFocusOld) {
        if (mpCtrl != nullptr) {
            mpCtrl->execute();
        }
        if (mpMtxCtrl != nullptr) {
            mpMtxCtrl->mCtrlF = (((mCtrlFocus == 0) && (mCtrlFocus == mCtrlFocusOld)) == false) ? (mpMtxCtrl->mCtrlF | 8u) : (mpMtxCtrl->mCtrlF & 0xFFFFFFF7u);
            mpMtxCtrl->execute();
        }
        if (mpHCtrl != nullptr) {
            mpHCtrl->mCtrlF = (((mCtrlFocus == 1) && (mCtrlFocus == mCtrlFocusOld)) == false) ? (mpHCtrl->mCtrlF | 8u) : (mpHCtrl->mCtrlF & 0xFFFFFFF7u);
            mpHCtrl->execute();
        }
        if (sInputManager::getInstance()->getKeyCommon(nKeyCustom::KEY_CUSTOM_UI_START, nKeyCustom::GET_TRG, nKeyCustom::MODE_CUSTOM, 0u) != 0) {
            mCtrlFocus = 1;
            if (mpHCtrl != nullptr) {
                mpHCtrl->setCurrentPos(0, false);
            }
        } else {
            mCtrlFocusOld = mCtrlFocus;
        }
    } else {
        mCtrlFocusOld = mCtrlFocus;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckList::update() {
    DDON_STUB("uGUIBase::cReferenceUICheckList::update")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckList::updateDisp() {
    DDON_STUB("uGUIBase::cReferenceUICheckList::updateDisp")
    /* stub */
}

void uGUIBase::cReferenceUICheckList::initAllCheck() {
    u32 i = 0;
    if (mListArray.size() != 0) {
        do {
            if (mListArray.getBuffer()[static_cast<int>(i)] != nullptr) {
                if (!static_cast<cList*>(mListArray.getBuffer()[static_cast<int>(i)])->mCheckbox.mIsForbid) {
                    static_cast<cList*>(mListArray.getBuffer()[static_cast<int>(i)])->mCheckbox.mCheck = false;
                    static_cast<cList*>(mListArray.getBuffer()[static_cast<int>(i)])->mCheckbox._update();
                }
            }
            i += 1u;
        } while (i < mListArray.size());
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckList::addFactor(MT_CTSTR str, s32 posX, s32 posY) {
    DDON_STUB("uGUIBase::cReferenceUICheckList::addFactor")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckList::setMessage(MT_CTSTR str, s32 idx) {
    DDON_STUB("uGUIBase::cReferenceUICheckList::setMessage")
    /* stub */
}

void uGUIBase::cReferenceUICheckList::setCheck(s32 idx, bool b) {
    if (idx < static_cast<int>(mListArray.mLength)) {
        if (mListArray.getBuffer()[idx] != nullptr) {
            if (!static_cast<cList*>(mListArray.getBuffer()[idx])->mCheckbox.mIsForbid) {
                static_cast<cList*>(mListArray.getBuffer()[idx])->mCheckbox.mCheck = b;
                static_cast<cList*>(mListArray.getBuffer()[idx])->mCheckbox._update();
            }
        }
    }
}

__attribute__((weak)) bool uGUIBase::cReferenceUICheckList::isCheck(s32 idx) {
    DDON_STUB("uGUIBase::cReferenceUICheckList::isCheck")
    return {};
}

void uGUIBase::cReferenceUICheckList::setCheckBoxNum(u32 num, bool bResetCtrl) {
    mCheckBoxNum = num;
    updateWindow();
    if (!bResetCtrl) {
        return;
    }
    if (mpMtxCtrl != nullptr) {
        mpMtxCtrl->setCurrentPos(0, false);
    }
    if (mpHCtrl == nullptr) {
        return;
    }
    mpHCtrl->setCurrentPos(0, false);
}

void uGUIBase::cReferenceUICheckList::setVisible(bool b) {
    mIsVisible = b;
    if (mData.mpINST_Null == nullptr) {
        return;
    }
    mData.mpINST_Null->setVisible(b);
}

bool uGUIBase::cReferenceUICheckList::isVisible() {
    if (mData.mpINST_Null != nullptr) {
        return static_cast<bool>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mData.mpINST_Null) + 88)) & 1);
    } else {
        return false;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckList::setLock(u32 uIdx, bool bLock, MT_CTSTR pMsgAnnounceLock) {
    DDON_STUB("uGUIBase::cReferenceUICheckList::setLock")
    /* stub */
}

__attribute__((weak)) MtSizeF uGUIBase::cReferenceUICheckList::calcWindowSize(f32 totalWidth, f32 rowHeight, s32 rowNum, MtFloat2& outWindowFrameOffset, MtFloat2& outTitleOffset, MtFloat2& outCheckboxOffset, MtFloat2& outButtonOffset) {
    DDON_STUB("uGUIBase::cReferenceUICheckList::calcWindowSize")
    __builtin_unreachable();
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckList::setWindowSize(uGUIBase::cAdjustableWindow& window, const MtSize& windowSize) {
    DDON_STUB("uGUIBase::cReferenceUICheckList::setWindowSize")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckList::updateWindowSize() {
    DDON_STUB("uGUIBase::cReferenceUICheckList::updateWindowSize")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckList::updateWindow() {
    DDON_STUB("uGUIBase::cReferenceUICheckList::updateWindow")
    /* stub */
}

inline uGUIBase::cReferenceUICheckList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUICheckList::MyDTI uGUIBase::cReferenceUICheckList::DTI("uGUIBase::cReferenceUICheckList", &::uGUIBase::cReferenceUIBase::DTI, 1336ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUICheckList::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUICheckList::MyDTI::newInstance")
    return nullptr;
}

uGUIBase::cReferenceUICheckList::cList::~cList() {
}

const MtDTI& uGUIBase::cReferenceUICheckListForClan::getDTI() const {
    return uGUIBase::cReferenceUICheckListForClan::DTI;
}

uGUIBase::cReferenceUICheckListForClan::cReferenceUICheckListForClan() {
    DDON_STUB("uGUIBase::cReferenceUICheckListForClan::cReferenceUICheckListForClan")
    /* stub */
}

uGUIBase::cReferenceUICheckListForClan::~cReferenceUICheckListForClan() {
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckListForClan::init(s32 enableNum, s32 max) {
    DDON_STUB("uGUIBase::cReferenceUICheckListForClan::init")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUICheckListForClan::setForm(uGUIBase::cReferenceUICheckListForClan::FORM form, u32& param, u32 page, bool isForSearch) {
    DDON_STUB("uGUIBase::cReferenceUICheckListForClan::setForm")
    /* stub */
}

void uGUIBase::cReferenceUICheckListForClan::setForm(uGUIBase::cReferenceUICheckListForClan::FORM form, CClanParam* pClanParam, u32 page, bool isForSearch) {
    if (pClanParam == nullptr) {
        return;
    }
    if (form != FORM_FEATURE) {
        if (form == FORM_TIME) {
            if (page == 1) {
                setForm(FORM_TIME, pClanParam->m_ClanUserParam.m_unActiveTime, 1u, isForSearch);
            } else {
                if (page == 0) {
                    setForm(FORM_TIME, pClanParam->m_ClanUserParam.m_unActiveDays, 0u, isForSearch);
                }
            }
        } else {
            if (form == FORM_MOTTO) {
                setForm(FORM_MOTTO, pClanParam->m_ClanUserParam.m_unMotto, page, isForSearch);
            }
        }
    } else {
        setForm(FORM_FEATURE, pClanParam->m_ClanUserParam.m_unCharacteristic, page, isForSearch);
    }
}

inline uGUIBase::cReferenceUICheckListForClan::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUICheckListForClan::MyDTI uGUIBase::cReferenceUICheckListForClan::DTI("uGUIBase::cReferenceUICheckListForClan", &::uGUIBase::cReferenceUICheckList::DTI, 1408ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUICheckListForClan::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUICheckListForClan::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIClanEmblem::getDTI() const {
    return uGUIBase::cReferenceUIClanEmblem::DTI;
}

uGUIBase::cReferenceUIClanEmblem::cReferenceUIClanEmblem() {
    DDON_STUB("uGUIBase::cReferenceUIClanEmblem::cReferenceUIClanEmblem")
    /* stub */
}

uGUIBase::cReferenceUIClanEmblem::~cReferenceUIClanEmblem() {
    DDON_STUB("uGUIBase::cReferenceUIClanEmblem::~cReferenceUIClanEmblem")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIClanEmblem::setup(uGUIBase* pBase, cGUIInstance* pEmblembase, cGUIInstance* pFix_pattern, cGUIInstance* pEmblem, cGUIInstance* pEmblemframe) {
    DDON_STUB("uGUIBase::cReferenceUIClanEmblem::setup")
    /* stub */
}

void uGUIBase::cReferenceUIClanEmblem::updateArcLoader(f32 deltaTime) {
    mTexRefArcLoader.update(deltaTime);
}

__attribute__((weak)) void uGUIBase::cReferenceUIClanEmblem::setFocus(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIClanEmblem::setFocus")
    /* stub */
}

bool uGUIBase::cReferenceUIClanEmblem::isFocus() {
    if (mInst.mpEmblemframe != nullptr) {
        return mInst.mpEmblemframe->getSequenceId() == 4;
    } else {
        return false;
    }
}

void uGUIBase::cReferenceUIClanEmblem::setEmblemBase(s32 emblemBaseId) {
    if (mBaseId == emblemBaseId) {
        return;
    }
    if (emblemBaseId > 0) {
        if (static_cast<sGUIExt*>(sGUI::getInstance())->getClanEmblemBaseNum() >= emblemBaseId) {
            if (mInst.mpFix_pattern != nullptr) {
                mInst.mpFix_pattern->setCurrentFrame(static_cast<float>(emblemBaseId - 1), true);
            }
            mBaseId = emblemBaseId;
        } else {
            if (mInst.mpFix_pattern != nullptr) {
                mInst.mpFix_pattern->setCurrentFrame(0.0f, true);
            }
            mBaseId = 0;
        }
    } else {
        if (mInst.mpFix_pattern != nullptr) {
            mInst.mpFix_pattern->setCurrentFrame(0.0f, true);
        }
        mBaseId = 0;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIClanEmblem::setEmblemMark(s32 emblemMarkId) {
    DDON_STUB("uGUIBase::cReferenceUIClanEmblem::setEmblemMark")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIClanEmblem::setVisible(uGUIBase::cReferenceUIClanEmblem::INST_TYPE instType, bool b) {
    DDON_STUB("uGUIBase::cReferenceUIClanEmblem::setVisible")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIClanEmblem::setColor(uGUIBase::cReferenceUIClanEmblem::COLOR_TYPE colorType, s32 colorId) {
    DDON_STUB("uGUIBase::cReferenceUIClanEmblem::setColor")
    /* stub */
}

void uGUIBase::cReferenceUIClanEmblem::applyParam(const nNet::stClanEmblem& emblem) {
    setEmblemMark(emblem.mark);
    const u8 t0 = emblem.base;
    if (static_cast<unsigned int>(t0) != static_cast<unsigned int>(mBaseId)) {
        if (t0 != 0) {
            if (static_cast<sGUIExt*>(sGUI::getInstance())->getClanEmblemBaseNum() >= static_cast<int>(t0)) {
                if (mInst.mpFix_pattern != nullptr) {
                    mInst.mpFix_pattern->setCurrentFrame(static_cast<float>(t0 - 1), true);
                }
                mBaseId = t0;
            } else {
                if (mInst.mpFix_pattern != nullptr) {
                    mInst.mpFix_pattern->setCurrentFrame(0.0f, true);
                }
                mBaseId = 0;
            }
        } else {
            if (mInst.mpFix_pattern != nullptr) {
                mInst.mpFix_pattern->setCurrentFrame(0.0f, true);
            }
            mBaseId = 0;
        }
    }
    setColor(COLOR_TYPE_MAIN, emblem.baseMainColor);
    setColor(COLOR_TYPE_SUB, emblem.baseSubColor);
}

void uGUIBase::cReferenceUIClanEmblem::applyParam(const CClanParam& param) {
    setEmblemMark(param.m_ClanUserParam.m_ucEmblemMarkType);
    const u8 t0 = param.m_ClanUserParam.m_ucEmblemBaseType;
    if (static_cast<unsigned int>(t0) != static_cast<unsigned int>(mBaseId)) {
        if (t0 != 0) {
            if (static_cast<sGUIExt*>(sGUI::getInstance())->getClanEmblemBaseNum() >= static_cast<int>(t0)) {
                if (mInst.mpFix_pattern != nullptr) {
                    mInst.mpFix_pattern->setCurrentFrame(static_cast<float>(t0 - 1), true);
                }
                mBaseId = t0;
            } else {
                if (mInst.mpFix_pattern != nullptr) {
                    mInst.mpFix_pattern->setCurrentFrame(0.0f, true);
                }
                mBaseId = 0;
            }
        } else {
            if (mInst.mpFix_pattern != nullptr) {
                mInst.mpFix_pattern->setCurrentFrame(0.0f, true);
            }
            mBaseId = 0;
        }
    }
    setColor(COLOR_TYPE_MAIN, param.m_ClanUserParam.m_ucEmblemBaseMainColor);
    setColor(COLOR_TYPE_SUB, param.m_ClanUserParam.m_ucEmblemBaseSubColor);
}

inline uGUIBase::cReferenceUIClanEmblem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIClanEmblem::MyDTI uGUIBase::cReferenceUIClanEmblem::DTI("uGUIBase::cReferenceUIClanEmblem", &::uGUIBase::cReferenceUIBase::DTI, 264ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIClanEmblem::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIClanEmblem::MyDTI::newInstance")
    return nullptr;
}

uGUIBase::cTexRefArcLoader::cTexRefArcLoader() {
    DDON_STUB("uGUIBase::cTexRefArcLoader::cTexRefArcLoader")
    /* stub */
}

uGUIBase::cTexRefArcLoader::~cTexRefArcLoader() {
}

void uGUIBase::cTexRefArcLoader::setup(cGUIObject* objTexRef) {
    mpObjTexRef = static_cast<cGUIObjTextureRef*>(objTexRef);
    if (objTexRef == nullptr) {
        return;
    }
    objTexRef->setVisible(false);
}

void uGUIBase::cTexRefArcLoader::request(MT_CTSTR arcName, MT_CTSTR searchId, f32 waitFrame) {
    if (searchId != nullptr) {
        if (searchId != (&mSearchId.mStr[0])) {
            size_t t0 = strlen(searchId);
            mSearchId.mLength = (static_cast<int>(t0) <= 63) ? static_cast<unsigned int>(t0) : 63u;
            if (((static_cast<int>(t0) <= 63) ? static_cast<unsigned int>(t0) : 63u) != 0) {
                memcpy(static_cast<void*>(&mSearchId.mStr[0]), static_cast<const void*>(searchId), static_cast<size_t>((static_cast<int>(t0) <= 63) ? static_cast<unsigned int>(t0) : 63u));
                mSearchId.mStr[(static_cast<int>(t0) <= 63) ? static_cast<unsigned int>(t0) : 63u] = 0;
                ARC_TAGID t1 = rArchiveListArray::convTagId(arcName);
                if (mArcTagIdReq != t1) {
                    if (mArcTagId != t1) {
                        if (t1 != 1) {
                            mArcTagIdReq = t1;
                            mTimer = waitFrame;
                            mIsLoading = true;
                        } else {
                            mArcTagIdReq = 1;
                        }
                    } else {
                        mArcTagIdReq = 1;
                    }
                }
                if (mpObjTexRef != nullptr) {
                    mpObjTexRef->setVisible(false);
                }
            } else {
                mSearchId.mStr[0] = 0;
                ARC_TAGID t1 = rArchiveListArray::convTagId(arcName);
                if (mArcTagIdReq != t1) {
                    if (mArcTagId != t1) {
                        if (t1 != 1) {
                            mArcTagIdReq = t1;
                            mTimer = waitFrame;
                            mIsLoading = true;
                        } else {
                            mArcTagIdReq = 1;
                        }
                    } else {
                        mArcTagIdReq = 1;
                    }
                }
                if (mpObjTexRef != nullptr) {
                    mpObjTexRef->setVisible(false);
                }
            }
        } else {
            ARC_TAGID t1 = rArchiveListArray::convTagId(arcName);
            if (mArcTagIdReq != t1) {
                if (mArcTagId != t1) {
                    if (t1 != 1) {
                        mArcTagIdReq = t1;
                        mTimer = waitFrame;
                        mIsLoading = true;
                    } else {
                        mArcTagIdReq = 1;
                    }
                } else {
                    mArcTagIdReq = 1;
                }
            }
            if (mpObjTexRef != nullptr) {
                mpObjTexRef->setVisible(false);
            }
        }
    } else {
        mSearchId.mStr[0] = 0;
        mSearchId.mLength = 0;
        ARC_TAGID t1 = rArchiveListArray::convTagId(arcName);
        if (mArcTagIdReq != t1) {
            if (mArcTagId != t1) {
                if (t1 != 1) {
                    mArcTagIdReq = t1;
                    mTimer = waitFrame;
                    mIsLoading = true;
                } else {
                    mArcTagIdReq = 1;
                }
            } else {
                mArcTagIdReq = 1;
            }
        }
        if (mpObjTexRef != nullptr) {
            mpObjTexRef->setVisible(false);
        }
    }
}

__attribute__((weak)) void uGUIBase::cTexRefArcLoader::update(f32 deltaTime) {
    DDON_STUB("uGUIBase::cTexRefArcLoader::update")
    /* stub */
}

void uGUIBase::cTexRefArcLoader::release() {
    if ("" != (&mSearchId.mStr[0])) {
        mSearchId.mLength = 0;
        mSearchId.mStr[0] = 0;
    }
    if (mpObjTexRef != nullptr) {
        mpObjTexRef->setVisible(false);
        cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
        if (mTicket != t0) {
            sArchiveManager::getInstance()->returnTicket(mTicket);
            mTicket = t0;
        }
        mArcTagId = 1;
        mArcTagIdReq = 1;
        mIsLoading = false;
        mIsComplete = false;
    } else {
        cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
        if (mTicket != t0) {
            sArchiveManager::getInstance()->returnTicket(mTicket);
            mTicket = t0;
        }
        mArcTagId = 1;
        mArcTagIdReq = 1;
        mIsLoading = false;
        mIsComplete = false;
    }
}

uGUIBase::cArcLoader::~cArcLoader() {
    DDON_STUB("uGUIBase::cArcLoader::~cArcLoader")
    /* stub */
}

cResource* uGUIBase::cArcLoader::createRes(MT_CTSTR search_id) {
    ARC_SEARCHID t0 = rArchiveListArray::convSearchId(search_id);
    return sArchiveManager::getInstance()->createRes(mArcTagId, t0, 1u, false);
}

void uGUIBase::cArcLoader::load() {
    TICKET t0 = mTicket;
    cArcLoaderBase* const t1 = sArchiveManager::INVALID_TICKET;
    if (t0 != t1) {
        sArchiveManager::getInstance()->returnTicket(t0);
        mTicket = t1;
        mArcTagId = 1;
        mIsLoading = false;
        mIsComplete = false;
        if (mArcTagIdReq != 1) {
            TICKET t2 = sArchiveManager::getInstance()->IssueTicket();
            if (t1 != (mTicket = t2)) {
                ARC_TAGID t3 = mArcTagIdReq;
                mArcTagId = t3;
                mArcTagIdReq = 1;
                t2->mPri = 5;
                sArchiveManager::getInstance()->addTagEx(t2, t3);
                sArchiveManager::getInstance()->attestationTicket(mTicket);
                mIsLoading = true;
            }
        }
    } else {
        mArcTagId = 1;
        mIsLoading = false;
        mIsComplete = false;
        if (mArcTagIdReq != 1) {
            TICKET t2 = sArchiveManager::getInstance()->IssueTicket();
            if (t0 != (mTicket = t2)) {
                ARC_TAGID t3 = mArcTagIdReq;
                mArcTagId = t3;
                mArcTagIdReq = 1;
                t2->mPri = 5;
                sArchiveManager::getInstance()->addTagEx(t2, t3);
                sArchiveManager::getInstance()->attestationTicket(mTicket);
                mIsLoading = true;
            }
        }
    }
}

const MtDTI& uGUIBase::cReferenceUINumBox::getDTI() const {
    return uGUIBase::cReferenceUINumBox::DTI;
}

void* uGUIBase::cReferenceUINumBox::operator new(size_t sz, u32 align) {
    return uGUIBase::cReferenceUINumBox::getAllocator()->memAlloc(sz, align, uGUIBase::cReferenceUINumBox::DTI.getID());
}

uGUIBase::cReferenceUINumBox::cReferenceUINumBox() {
    DDON_STUB("uGUIBase::cReferenceUINumBox::cReferenceUINumBox")
    /* stub */
}

uGUIBase::cReferenceUINumBox::~cReferenceUINumBox() {
    static_cast<sGUIExt*>(sGUI::getInstance())->resetActiveNumBox(static_cast<void*>(this));
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::setup(uGUIBase* pUnit, cGUIInstAnimation* pInst, s32 Min, s32 Max, s32 Num) {
    DDON_STUB("uGUIBase::cReferenceUINumBox::setup")
    /* stub */
}

void uGUIBase::cReferenceUINumBox::setEnable(bool isEnable) {
    mIsEnable = isEnable;
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::moveInput() {
    DDON_STUB("uGUIBase::cReferenceUINumBox::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::moveEvent() {
    DDON_STUB("uGUIBase::cReferenceUINumBox::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::update() {
    DDON_STUB("uGUIBase::cReferenceUINumBox::update")
    /* stub */
}

void uGUIBase::cReferenceUINumBox::setFocus(bool IsFocus) {
    mIsFocus = IsFocus;
}

bool uGUIBase::cReferenceUINumBox::isFocus() {
    return mIsFocus;
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::setMode(uGUIBase::cReferenceUINumBox::MODE mode) {
    DDON_STUB("uGUIBase::cReferenceUINumBox::setMode")
    /* stub */
}

void uGUIBase::cReferenceUINumBox::pushLArrow(s32 AddNum) {
    s32 t0 = getCurrentNum();
    if (mMinNum == t0) {
        return;
    }
    if (mMinNum == mMaxNum) {
        mCurrentNum = mMinNum;
        mGrayOutType = 3;
        mIsChangeNum = true;
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
    } else {
        if (mMinNum < (AddNum + t0)) {
            if ((AddNum + t0) < mMaxNum) {
                mCurrentNum = AddNum + t0;
                mGrayOutType = 0;
                if (t0 != mCurrentNum) {
                    mIsChangeNum = true;
                    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
                }
            } else {
                mCurrentNum = mMaxNum;
                mGrayOutType = 2;
                if (t0 != mMaxNum) {
                    mIsChangeNum = true;
                    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
                }
            }
        } else {
            mCurrentNum = mMinNum;
            mGrayOutType = 1;
            mIsChangeNum = true;
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
        }
    }
    dispRefresh();
    mIsPushAllowL = true;
}

void uGUIBase::cReferenceUINumBox::pushRArrow(s32 AddNum) {
    s32 t0 = getCurrentNum();
    if (mMaxNum == t0) {
        return;
    }
    if (mMaxNum == mMinNum) {
        mCurrentNum = mMaxNum;
        mGrayOutType = 3;
        mIsChangeNum = true;
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
    } else {
        if (mMinNum < (AddNum + t0)) {
            if ((AddNum + t0) < mMaxNum) {
                mCurrentNum = AddNum + t0;
                mGrayOutType = 0;
                if (t0 != mCurrentNum) {
                    mIsChangeNum = true;
                    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
                }
            } else {
                mCurrentNum = mMaxNum;
                mGrayOutType = 2;
                mIsChangeNum = true;
                static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
            }
        } else {
            mCurrentNum = mMinNum;
            mGrayOutType = 1;
            if (t0 != mMinNum) {
                mIsChangeNum = true;
                static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
            }
        }
    }
    dispRefresh();
    mIsPushAllowR = true;
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::dispRefresh() {
    DDON_STUB("uGUIBase::cReferenceUINumBox::dispRefresh")
    /* stub */
}

void uGUIBase::cReferenceUINumBox::setNum(s32 Num) {
    const s32 old = getCurrentNum();
    if (mMinNum == mMaxNum) {
        mCurrentNum = mMinNum;
        mGrayOutType = 3;
        if (old != mMinNum) {
            mIsChangeNum = true;
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
        }
    } else {
        if (mMinNum < Num) {
            if (Num < mMaxNum) {
                mCurrentNum = Num;
                mGrayOutType = 0;
                if (old != Num) {
                    mIsChangeNum = true;
                    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
                }
            } else {
                mCurrentNum = mMaxNum;
                mGrayOutType = 2;
                if (old != mMaxNum) {
                    mIsChangeNum = true;
                    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
                }
            }
        } else {
            mCurrentNum = mMinNum;
            mGrayOutType = 1;
            if (old != mMinNum) {
                mIsChangeNum = true;
                static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
            }
        }
    }
    dispRefresh();
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::setMax(s32 n) {
    DDON_STUB("uGUIBase::cReferenceUINumBox::setMax")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::resetInputRange(s32 Min, s32 Max) {
    DDON_STUB("uGUIBase::cReferenceUINumBox::resetInputRange")
    /* stub */
}

void uGUIBase::cReferenceUINumBox::addMouseTouchList(cControl* pOwner, u32 id) {
    if (pOwner == nullptr) {
        return;
    }
    if (mpInstance == nullptr) {
        return;
    }
    pOwner->addMouseTouchList(static_cast<cGUIInstance*>(mpInstance), static_cast<cGUIObject*>(mpCMouseOver), static_cast<s32>(id), static_cast<cGUIObject*>(nullptr), 1u, 1u, 2);
    pOwner->addMouseTouchList(static_cast<cGUIInstance*>(mpInstance), static_cast<cGUIObject*>(mpLMouseOver), static_cast<s32>(id), static_cast<cGUIObject*>(nullptr), 1u, 1u, 0);
    pOwner->addMouseTouchList(static_cast<cGUIInstance*>(mpInstance), static_cast<cGUIObject*>(mpRMouseOver), static_cast<s32>(id), static_cast<cGUIObject*>(nullptr), 1u, 1u, 1);
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUINumBox::updatePointerPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::moveEdit() {
    DDON_STUB("uGUIBase::cReferenceUINumBox::moveEdit")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::setStatusLArrow(bool IsEnable, bool IsPush) {
    if (mpInstance->getSequenceId() == 4) {
        if (mpLArrow != nullptr) {
            if (IsEnable) {
                mpLArrow->setCurrentFrame(0.0f, true);
            } else {
                mpLArrow->setCurrentFrame(1.0f, true);
            }
        }
        if (mpLPushArrow != nullptr) {
            if (IsPush) {
                mpLPushArrow->setCurrentFrame(0.0f, false);
            } else {
                mpLPushArrow->setCurrentFrame(2.0f, false);
            }
        }
    } else {
        if (mpLArrow != nullptr) {
            mpLArrow->setCurrentFrame(1.0f, true);
        }
        if (mpLPushArrow != nullptr) {
            mpLPushArrow->setCurrentFrame(2.0f, false);
        }
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::setStatusRArrow(bool IsEnable, bool IsPush) {
    if (mpInstance->getSequenceId() == 4) {
        if (mpRArrow != nullptr) {
            if (IsEnable) {
                mpRArrow->setCurrentFrame(0.0f, true);
            } else {
                mpRArrow->setCurrentFrame(1.0f, true);
            }
        }
        if (mpRPushArrow != nullptr) {
            if (IsPush) {
                mpRPushArrow->setCurrentFrame(0.0f, false);
            } else {
                mpRPushArrow->setCurrentFrame(2.0f, false);
            }
        }
    } else {
        if (mpRArrow != nullptr) {
            mpRArrow->setCurrentFrame(1.0f, true);
        }
        if (mpRPushArrow != nullptr) {
            mpRPushArrow->setCurrentFrame(2.0f, false);
        }
    }
}

void uGUIBase::cReferenceUINumBox::setStatusArrow(bool IsLPush, bool IsRPush) {
    if (mGrayOutType != 1) {
        if (mGrayOutType == 2) {
            setStatusLArrow(true, IsLPush);
            setStatusRArrow(false, IsRPush);
        } else {
            if (mGrayOutType == 3) {
                setStatusLArrow(false, IsLPush);
                setStatusRArrow(false, IsRPush);
            } else {
                setStatusLArrow(true, IsLPush);
                setStatusRArrow(true, IsRPush);
            }
        }
    } else {
        setStatusLArrow(false, IsLPush);
        setStatusRArrow(true, IsRPush);
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUINumBox::setWidth(f32 Size) {
    DDON_STUB("uGUIBase::cReferenceUINumBox::setWidth")
    /* stub */
}

s32 uGUIBase::cReferenceUINumBox::getMaxNum() const {
    return mMaxNum;
}

s32 uGUIBase::cReferenceUINumBox::getMinNum() const {
    return mMinNum;
}

inline uGUIBase::cReferenceUINumBox::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUINumBox::MyDTI uGUIBase::cReferenceUINumBox::DTI("uGUIBase::cReferenceUINumBox", &::uGUIBase::cReferenceUIBase::DTI, 280ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUINumBox::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUINumBox::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIPageDot::getDTI() const {
    return uGUIBase::cReferenceUIPageDot::DTI;
}

uGUIBase::cReferenceUIPageDot::cReferenceUIPageDot() {
    mWork.mAutoDelete = true;
    mpInstPager = nullptr;
    mCurrentPos = 0;
    mDispPageNum = 0;
    mEnable = true;
    mFocus = true;
}

__attribute__((weak)) void uGUIBase::cReferenceUIPageDot::setup(uGUIBase* pParentGUI, cGUIInstance* pInstPoint, cGUIInstance* pInstPager, u32 uPageMax, u32 uDispPageNum) {
    DDON_STUB("uGUIBase::cReferenceUIPageDot::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPageDot::updateDisp() {
    DDON_STUB("uGUIBase::cReferenceUIPageDot::updateDisp")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPageDot::setCurrentPos(u32 uPos) {
    DDON_STUB("uGUIBase::cReferenceUIPageDot::setCurrentPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIPageDot::setDispPageNum(u32 uNum) {
    DDON_STUB("uGUIBase::cReferenceUIPageDot::setDispPageNum")
    /* stub */
}

void uGUIBase::cReferenceUIPageDot::setVisible(bool visible) {
    u32 i = 0;
    if (mWork.mLength != 0) {
        do {
            if (mWork.mpArray[i] != nullptr) {
                if (static_cast<cPageDotWork*>(mWork.mpArray[i])->mpInst != nullptr) {
                    static_cast<cPageDotWork*>(mWork.mpArray[i])->mpInst->setVisible(visible);
                }
            }
            i += 1u;
        } while (i < mWork.mLength);
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIPageDot::setFocus(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIPageDot::setFocus")
    /* stub */
}

bool uGUIBase::cReferenceUIPageDot::isFocus() {
    if (mEnable) {
        return mFocus;
    } else {
        return false;
    }
}

__attribute__((weak)) void uGUIBase::cReferenceUIPageDot::setEnable(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIPageDot::setEnable")
    /* stub */
}

__attribute__((weak)) MtVector2 uGUIBase::cReferenceUIPageDot::getPointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIPageDot::getPointerPos")
    __builtin_unreachable();
}

inline uGUIBase::cReferenceUIPageDot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIPageDot::MyDTI uGUIBase::cReferenceUIPageDot::DTI("uGUIBase::cReferenceUIPageDot", &::uGUIBase::cReferenceUIBase::DTI, 136ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIPageDot::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIPageDot;
}

const MtDTI& uGUIBase::cReferenceUIPageDot::cPageDotWork::getDTI() const {
    return uGUIBase::cReferenceUIPageDot::cPageDotWork::DTI;
}

inline uGUIBase::cReferenceUIPageDot::cPageDotWork::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIPageDot::cPageDotWork::MyDTI uGUIBase::cReferenceUIPageDot::cPageDotWork::DTI("uGUIBase::cReferenceUIPageDot::cPageDotWork", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIPageDot::cPageDotWork::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIPageDot::cPageDotWork;
}

const MtDTI& uGUIBase::cReferenceUIRadioButton::getDTI() const {
    return uGUIBase::cReferenceUIRadioButton::DTI;
}

__attribute__((noinline)) uGUIBase::cReferenceUIRadioButton::~cReferenceUIRadioButton() {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::~cReferenceUIRadioButton")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIRadioButton::setup(uGUIBase* pBase, cGUIInstance* pInst, s32 num, s32 select, const MtVector2& nextMove) {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIRadioButton::execute() {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::execute")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIRadioButton::setFocus(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::setFocus")
    /* stub */
}

bool uGUIBase::cReferenceUIRadioButton::isFocus() {
    return mFocus;
}

void uGUIBase::cReferenceUIRadioButton::setMessage(u32 idx, MT_CTSTR msg) {
    if (mMode == MODE_SINGLE) {
        if (mpUnit != nullptr) {
            mpUnit->setObjectMessage(static_cast<cGUIObject*>(mSingleObject.mpObjMsgTitle), msg, 0u, false);
        }
    } else {
        if (mpUnit != nullptr) {
            mpUnit->setObjectMessage(static_cast<cGUIObject*>(static_cast<cObject*>(mArray.getBuffer()[static_cast<int>(idx)])->mpObjMsgTitle), msg, 0u, false);
        }
    }
}

s32 uGUIBase::cReferenceUIRadioButton::getVItemNum() {
    return static_cast<s32>(mArray.size());
}

__attribute__((weak)) void uGUIBase::cReferenceUIRadioButton::deleteInstance() {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::deleteInstance")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIRadioButton::setSelect(s32 idx, bool select) {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::setSelect")
    /* stub */
}

s32 uGUIBase::cReferenceUIRadioButton::getSelectIndex() {
    if (mMode == MODE_SINGLE) {
        return static_cast<signed char>(mSingleObject.isSelect() + 255);
    } else {
        return mSelectIdx;
    }
}

void uGUIBase::cReferenceUIRadioButton::addMouseTouchList(cControl* pCtrl, s32 startPos, s32 vol, bool autoErase) {
    if (pCtrl != nullptr) {
        if (mMode == MODE_MULTI) {
            u32 v0_8 = mArray.size();
            if (v0_8 != 0) {
                for (unsigned int i0_10 = 0;;) {
                    MtObject* t0 = mArray.getBuffer()[static_cast<int>(i0_10)];
                    if (t0 != nullptr) {
                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 80)) != 0) {
                            if (autoErase) {
                                if (vol > -1) {
                                    pCtrl->eraseMouseTouchListPosVol(static_cast<s32>(startPos + i0_10), vol);
                                } else {
                                    pCtrl->eraseMouseTouchList(static_cast<s32>(startPos + i0_10));
                                }
                            }
                            pCtrl->addMouseTouchList(reinterpret_cast<cGUIInstance*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48)), reinterpret_cast<cGUIObject*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 80)), static_cast<s32>(startPos + i0_10), static_cast<cGUIObject*>(nullptr), 1u, 1u, vol);
                        }
                    }
                    if (v0_8 != (i0_10 + 1u)) {
                        i0_10 += 1u;
                    } else {
                        break;
                    }
                }
            }
        } else {
            if (mMode == MODE_SINGLE) {
                if (mSingleObject.mpObjMouseOver != nullptr) {
                    if (autoErase) {
                        if (vol > -1) {
                            pCtrl->eraseMouseTouchListPosVol(startPos, vol);
                        } else {
                            pCtrl->eraseMouseTouchList(startPos);
                        }
                    }
                    pCtrl->addMouseTouchList(reinterpret_cast<cGUIInstance*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 168)), static_cast<cGUIObject*>(mSingleObject.mpObjMouseOver), startPos, static_cast<cGUIObject*>(nullptr), 1u, 1u, vol);
                }
            }
        }
    }
}

__attribute__((weak)) bool uGUIBase::cReferenceUIRadioButton::setupPointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::setupPointerPos")
    return {};
}

__attribute__((weak)) void uGUIBase::cReferenceUIRadioButton::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUIRadioButton::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIRadioButton::MyDTI uGUIBase::cReferenceUIRadioButton::DTI("uGUIBase::cReferenceUIRadioButton", &::uGUIBase::cReferenceUIBase::DTI, 240ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIRadioButton::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIRadioButton::cObject::getDTI() const {
    return uGUIBase::cReferenceUIRadioButton::cObject::DTI;
}

__attribute__((weak)) void uGUIBase::cReferenceUIRadioButton::cObject::setFocus(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::cObject::setFocus")
    /* stub */
}

inline uGUIBase::cReferenceUIRadioButton::cObject::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIRadioButton::cObject::MyDTI uGUIBase::cReferenceUIRadioButton::cObject::DTI("uGUIBase::cReferenceUIRadioButton::cObject", &::uGUIBase::cSupportBase::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIRadioButton::cObject::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIRadioButton::cObject::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUINumPager::getDTI() const {
    return uGUIBase::cReferenceUINumPager::DTI;
}

__attribute__((weak)) void uGUIBase::cReferenceUINumPager::setup(uGUIBase* pBase, cGUIInstance* pInst, s32 num, s32 max, u8 uColorType) {
    DDON_STUB("uGUIBase::cReferenceUINumPager::setup")
    /* stub */
}

void uGUIBase::cReferenceUINumPager::execute() {
    if (mpPagerCtrl == nullptr) {
        return;
    }
    mpPagerCtrl->execute();
}

__attribute__((weak)) void uGUIBase::cReferenceUINumPager::update() {
    DDON_STUB("uGUIBase::cReferenceUINumPager::update")
    /* stub */
}

void uGUIBase::cReferenceUINumPager::setOwnerCtrl(cControl* pOwnerCtrl) {
    if (pOwnerCtrl == nullptr) {
        return;
    }
    mpOwnerCtrl = pOwnerCtrl;
    mNum = pOwnerCtrl->getCurrentPos();
    changeString();
    mMax = mpOwnerCtrl->getItemNum();
    changeString();
}

__attribute__((weak)) void uGUIBase::cReferenceUINumPager::addNum(s32 n) {
    DDON_STUB("uGUIBase::cReferenceUINumPager::addNum")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUINumPager::changeString() {
    DDON_STUB("uGUIBase::cReferenceUINumPager::changeString")
    /* stub */
}

void uGUIBase::cReferenceUINumPager::addMouseTouchList(cControl* pOwner) {
    if (pOwner == nullptr) {
        return;
    }
    pOwner->clearMouseTouchList();
    pOwner->addMouseTouchList(static_cast<cGUIInstance*>(getInstance()), static_cast<cGUIObject*>(mpOBJ_mouseover_left), 0, static_cast<cGUIObject*>(nullptr), 1u, 1u, 0);
    pOwner->addMouseTouchList(static_cast<cGUIInstance*>(getInstance()), static_cast<cGUIObject*>(mpOBJ_mouseover_right), 1, static_cast<cGUIObject*>(nullptr), 1u, 1u, 1);
}

void uGUIBase::cReferenceUINumPager::addMouseWheelTouchListInstAnimation(u32 instAnimationId) {
    if (mpUnit == nullptr) {
        return;
    }
    cGUIInstance* t0 = mpUnit->getInstance(instAnimationId, false);
    if (t0 == nullptr) {
        return;
    }
    if (static_cast<cGUIInstAnimation*>(t0)->getRootObject() == nullptr) {
        return;
    }
    if (mpPagerCtrl == nullptr) {
        return;
    }
    u32 t1 = mpPagerCtrl->addMouseTouchList(static_cast<cGUIInstance*>(getInstance()), static_cast<cGUIObject*>(static_cast<cGUIInstAnimation*>(t0)->getRootObject()), 2, static_cast<cGUIObject*>(nullptr), 0u, 0u, 2);
    if (t1 == 0xFFFFFFFFu) {
        return;
    }
    mpPagerCtrl->setMouseTouchListLimitedReason(t1, 1536u);
}

void uGUIBase::cReferenceUINumPager::addMouseWheelTouchListInstScissorMask(u32 instScissorMaskId) {
    if (mpUnit == nullptr) {
        return;
    }
    cGUIInstance* t0 = mpUnit->getInstance(instScissorMaskId, false);
    if (t0 == nullptr) {
        return;
    }
    if (mpPagerCtrl == nullptr) {
        return;
    }
    u32 t1 = mpPagerCtrl->addMouseTouchList(t0, static_cast<cGUIObject*>(nullptr), 2, static_cast<cGUIObject*>(nullptr), 0u, 0u, 2);
    if (t1 == 0xFFFFFFFFu) {
        return;
    }
    mpPagerCtrl->setMouseTouchListLimitedReason(t1, 1536u);
}

inline uGUIBase::cReferenceUINumPager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUINumPager::MyDTI uGUIBase::cReferenceUINumPager::DTI("uGUIBase::cReferenceUINumPager", &::uGUIBase::cReferenceUIBase::DTI, 168ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUINumPager::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUINumPager;
}

const MtDTI& uGUIBase::cReferenceUIIconButton::getDTI() const {
    return uGUIBase::cReferenceUIIconButton::DTI;
}

uGUIBase::cReferenceUIIconButton::cReferenceUIIconButton() {
    mIsFocus = false;
    mIsSelected = false;
    mShape = SHAPE_QUAD;
    mIconFrame = 0;
    mColorFrame = 0;
    mOBJ_fix_job_waku01 = nullptr;
    mOBJ_fix_job_f_job = nullptr;
    mIsEnable = true;
    mJobId = 0;
}

uGUIBase::cReferenceUIIconButton::~cReferenceUIIconButton() {
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconButton::setup(uGUIBase* pUnit, cGUIInstAnimation* inst, uGUIBase::cReferenceUIIconButton::SHAPE shape) {
    DDON_STUB("uGUIBase::cReferenceUIIconButton::setup")
    /* stub */
}

void uGUIBase::cReferenceUIIconButton::setPositionX(f32 x) {
    if (mpInstance == nullptr) {
        return;
    }
    mpInstance->setPositionX(x);
}

f32 uGUIBase::cReferenceUIIconButton::getPositionX() const {
    if (mpInstance != nullptr) {
        return mpInstance->mPosition.x;
    } else {
        return 0.0f;
    }
}

void uGUIBase::cReferenceUIIconButton::setFocus(bool isFocus) {
    if (mpInstance == nullptr) {
        return;
    }
    setState(isFocus, mIsSelected);
}

bool uGUIBase::cReferenceUIIconButton::isFocus() {
    return mIsFocus;
}

void uGUIBase::cReferenceUIIconButton::setSelected(bool isSelected) {
    if (mpInstance == nullptr) {
        return;
    }
    setState(mIsFocus, isSelected);
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconButton::setState(bool isFocus, bool isSelected) {
    DDON_STUB("uGUIBase::cReferenceUIIconButton::setState")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconButton::setJobId(u32 jobId) {
    DDON_STUB("uGUIBase::cReferenceUIIconButton::setJobId")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconButton::setType(uGUIBase::cReferenceUIIconButton::TYPE type) {
    DDON_STUB("uGUIBase::cReferenceUIIconButton::setType")
    /* stub */
}

void uGUIBase::cReferenceUIIconButton::setEnable(bool isEnable) {
    mIsEnable = isEnable;
    setState(mIsFocus, mIsSelected);
}

void uGUIBase::cReferenceUIIconButton::update() {
    updatePointerPos();
    setState(mIsFocus, mIsSelected);
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconButton::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIIconButton::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUIIconButton::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconButton::MyDTI uGUIBase::cReferenceUIIconButton::DTI("uGUIBase::cReferenceUIIconButton", &::uGUIBase::cReferenceUIBase::DTI, 120ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconButton::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconButton;
}

const MtDTI& uGUIBase::cReferenceUIEditSlider::getDTI() const {
    return uGUIBase::cReferenceUIEditSlider::DTI;
}

uGUIBase::cReferenceUIEditSlider::cReferenceUIEditSlider() {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::cReferenceUIEditSlider")
    /* stub */
}

uGUIBase::cReferenceUIEditSlider::~cReferenceUIEditSlider() {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::~cReferenceUIEditSlider")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditSlider::setup(uGUIBase* pBase, cGUIInstance* pInst, s32 sizeX, s32 div, s32 pos, MT_CTSTR leftName, MT_CTSTR topName) {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditSlider::setupSize() {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::setupSize")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditSlider::setSliderPos(s32 n, bool bInit) {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::setSliderPos")
    /* stub */
}

void uGUIBase::cReferenceUIEditSlider::setSliderOffset(s32 n) {
    mSliderOffset = n;
    if (mpObjNullSlider == nullptr) {
        return;
    }
    mpObjNullSlider->setPositionX(static_cast<float>(n));
}

__attribute__((weak)) bool uGUIBase::cReferenceUIEditSlider::executeMouse() {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::executeMouse")
    return {};
}

__attribute__((weak)) bool uGUIBase::cReferenceUIEditSlider::execute(bool isSkipMouse) {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::execute")
    return {};
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditSlider::setFocus(bool b) {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::setFocus")
    /* stub */
}

bool uGUIBase::cReferenceUIEditSlider::isFocus() {
    return mFocus;
}

__attribute__((weak)) MtVector2 uGUIBase::cReferenceUIEditSlider::getPointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::getPointerPos")
    __builtin_unreachable();
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditSlider::setDefaultPos(s32 sPos) {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::setDefaultPos")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditSlider::setDecidePos(s32 sPos) {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::setDecidePos")
    /* stub */
}

void uGUIBase::cReferenceUIEditSlider::setVisibleTexPointAll(bool visible) {
    if (mpTexPoint[0] != nullptr) {
        mpTexPoint[0]->cGUIObject::setVisible(visible);
    }
    if (mpTexPoint[1] != nullptr) {
        mpTexPoint[1]->cGUIObject::setVisible(visible);
    }
    if (mpTexPoint[2] != nullptr) {
        mpTexPoint[2]->cGUIObject::setVisible(visible);
    }
    if (mpTexPoint[3] != nullptr) {
        mpTexPoint[3]->cGUIObject::setVisible(visible);
    }
    if (mpTexPoint[4] == nullptr) {
        return;
    }
    mpTexPoint[4]->cGUIObject::setVisible(visible);
}

void uGUIBase::cReferenceUIEditSlider::setVisibleDefaultObj(bool visible) {
    if (mpObjDefault == nullptr) {
        return;
    }
    mpObjDefault->setVisible(visible);
}

void uGUIBase::cReferenceUIEditSlider::setVisibleTexDecideObj(bool visible) {
    if (mpTexPointDecide == nullptr) {
        return;
    }
    mpTexPointDecide->setVisible(visible);
}

void uGUIBase::cReferenceUIEditSlider::setVisibleNullSlider(bool visible) {
    if (mpObjNullSlider == nullptr) {
        return;
    }
    mpObjNullSlider->setVisible(visible);
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditSlider::setMsgNumStr(s32 n, bool bInit) {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::setMsgNumStr")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cReferenceUIEditSlider::updatePointerPos() {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::updatePointerPos")
    /* stub */
}

inline uGUIBase::cReferenceUIEditSlider::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIEditSlider::MyDTI uGUIBase::cReferenceUIEditSlider::DTI("uGUIBase::cReferenceUIEditSlider", &::uGUIBase::cReferenceUIBase::DTI, 304ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cReferenceUIEditSlider::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cReferenceUIEditSlider::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBase::cReferenceUIIconFriend::getDTI() const {
    return uGUIBase::cReferenceUIIconFriend::DTI;
}

uGUIBase::cReferenceUIIconFriend::cReferenceUIIconFriend() {
}

__attribute__((weak)) void uGUIBase::cReferenceUIIconFriend::setup(uGUIBase* pUnit, cGUIInstance* pInst) {
    DDON_STUB("uGUIBase::cReferenceUIIconFriend::setup")
    /* stub */
}

void uGUIBase::cReferenceUIIconFriend::setStatus(u32 status) {
    if (mpInstance == nullptr) {
        return;
    }
    mpInstance->setCurrentFrame(static_cast<float>(status), true);
}

inline uGUIBase::cReferenceUIIconFriend::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cReferenceUIIconFriend::MyDTI uGUIBase::cReferenceUIIconFriend::DTI("uGUIBase::cReferenceUIIconFriend", &::uGUIBase::cReferenceUIBase::DTI, 80ul, 0u, 0u);

MtObject* uGUIBase::cReferenceUIIconFriend::MyDTI::newInstance() const {
    return new (16u) uGUIBase::cReferenceUIIconFriend;
}

const MtDTI& uGUIBase::cScreenAdjustPos::getDTI() const {
    return uGUIBase::cScreenAdjustPos::DTI;
}

uGUIBase::cScreenAdjustPos::cScreenAdjustPos() {
    DDON_STUB("uGUIBase::cScreenAdjustPos::cScreenAdjustPos")
    /* stub */
}

inline uGUIBase::cScreenAdjustPos::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBase::cScreenAdjustPos::MyDTI uGUIBase::cScreenAdjustPos::DTI("uGUIBase::cScreenAdjustPos", &::MtObject::DTI, 128ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBase::cScreenAdjustPos::MyDTI::newInstance() const {
    DDON_STUB("uGUIBase::cScreenAdjustPos::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void uGUIBase::cTextSlider::setup(uGUIBase* pUnit, cGUIInstance* pInstNull, cGUIObject* pObjMsg, cGUIObject* pObjMaskCenter, f32 speed, f32 begin_frame, f32 end_frame) {
    DDON_STUB("uGUIBase::cTextSlider::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cTextSlider::start(MT_CTSTR pMsg) {
    DDON_STUB("uGUIBase::cTextSlider::start")
    /* stub */
}

bool uGUIBase::cTextSlider::update(f32 delta_time) {
    u32 t0 = mRno;
    if (t0 == 2) {
        f32 t1 = mSpeed;
        f32 t2 = mScrollWidth;
        mScrollWidth = t2 - (t1 * delta_time);
        f32 t3 = mDefaultPos;
        if (mScrollWidth > 0.0f) {
            cGUIInstNull* t4 = mpInstNull;
            if (t4 != nullptr) {
                t4->setPositionX(t3 + (t2 - (t1 * delta_time)));
                return true;
            } else {
                cGUIObjMessage* t11 = mpObjMsg;
                if (t11 != nullptr) {
                    t11->setPositionX(t3 + (t2 - (t1 * delta_time)));
                }
                return true;
            }
        } else {
            cGUIInstNull* t9 = mpInstNull;
            if (t9 != nullptr) {
                t9->setPositionX(t3);
                mScrollWidth = 0.0f;
                f32 t16 = mEndFrame;
                mTimer = t16;
                mRno = 1;
                return true;
            } else {
                cGUIObjMessage* t14 = mpObjMsg;
                if (t14 != nullptr) {
                    t14->setPositionX(t3);
                    mScrollWidth = 0.0f;
                    f32 t16 = mEndFrame;
                    mTimer = t16;
                    mRno = 1;
                    return true;
                } else {
                    mScrollWidth = 0.0f;
                    f32 t16 = mEndFrame;
                    mTimer = t16;
                    mRno = 1;
                    return true;
                }
            }
        }
    } else {
        if (t0 == 1) {
            f32 t7 = mTimer;
            mTimer = t7 - delta_time;
            if (0.0f >= mTimer) {
                f32 t8 = mScrollWidth;
                if (t8 != 0.0f) {
                    mRno = 2;
                } else {
                    mRno = 3;
                }
                return true;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }
}

uGUIBase::cTexArcLoader::cTexArcLoader() {
    DDON_STUB("uGUIBase::cTexArcLoader::cTexArcLoader")
    /* stub */
}

uGUIBase::cTexArcLoader::~cTexArcLoader() {
}

void uGUIBase::cTexArcLoader::setup(uGUIBase* pGUI, cGUIObject* pObjTex, u32 tex_index) {
    mpParent = pGUI;
    mpObjTex = static_cast<cGUIObjTexture*>(pObjTex);
    mTexIndex = tex_index;
    mIsAutoAttach = true;
}

__attribute__((weak)) void uGUIBase::cTexArcLoader::update(f32 delta_time) {
    DDON_STUB("uGUIBase::cTexArcLoader::update")
    /* stub */
}

void uGUIBase::cTexArcLoader::request(MT_CTSTR arc_name, MT_CTSTR search_id, f32 wait_frame) {
    if (search_id != nullptr) {
        if (search_id != (&mSearchId.mStr[0])) {
            size_t t0 = strlen(search_id);
            mSearchId.mLength = (static_cast<int>(t0) <= 63) ? static_cast<unsigned int>(t0) : 63u;
            if (((static_cast<int>(t0) <= 63) ? static_cast<unsigned int>(t0) : 63u) != 0) {
                memcpy(static_cast<void*>(&mSearchId.mStr[0]), static_cast<const void*>(search_id), static_cast<size_t>((static_cast<int>(t0) <= 63) ? static_cast<unsigned int>(t0) : 63u));
                mSearchId.mStr[(static_cast<int>(t0) <= 63) ? static_cast<unsigned int>(t0) : 63u] = 0;
            } else {
                mSearchId.mStr[0] = 0;
            }
            if (mpObjTex != nullptr) {
                mpObjTex->setVisible(false);
                ARC_TAGID t1 = rArchiveListArray::convTagId(arc_name);
                if (mArcTagIdReq != t1) {
                    if (mArcTagId != t1) {
                        if (t1 != 1) {
                            mArcTagIdReq = t1;
                            mTimer = wait_frame;
                            mIsLoading = true;
                        } else {
                            mArcTagIdReq = 1;
                        }
                    } else {
                        mArcTagIdReq = 1;
                    }
                }
            } else {
                ARC_TAGID t1 = rArchiveListArray::convTagId(arc_name);
                if (mArcTagIdReq != t1) {
                    if (mArcTagId != t1) {
                        if (t1 != 1) {
                            mArcTagIdReq = t1;
                            mTimer = wait_frame;
                            mIsLoading = true;
                        } else {
                            mArcTagIdReq = 1;
                        }
                    } else {
                        mArcTagIdReq = 1;
                    }
                }
            }
        } else {
            if (mpObjTex != nullptr) {
                mpObjTex->setVisible(false);
                ARC_TAGID t1 = rArchiveListArray::convTagId(arc_name);
                if (mArcTagIdReq != t1) {
                    if (mArcTagId != t1) {
                        if (t1 != 1) {
                            mArcTagIdReq = t1;
                            mTimer = wait_frame;
                            mIsLoading = true;
                        } else {
                            mArcTagIdReq = 1;
                        }
                    } else {
                        mArcTagIdReq = 1;
                    }
                }
            } else {
                ARC_TAGID t1 = rArchiveListArray::convTagId(arc_name);
                if (mArcTagIdReq != t1) {
                    if (mArcTagId != t1) {
                        if (t1 != 1) {
                            mArcTagIdReq = t1;
                            mTimer = wait_frame;
                            mIsLoading = true;
                        } else {
                            mArcTagIdReq = 1;
                        }
                    } else {
                        mArcTagIdReq = 1;
                    }
                }
            }
        }
    } else {
        mSearchId.mStr[0] = 0;
        mSearchId.mLength = 0;
        if (mpObjTex != nullptr) {
            mpObjTex->setVisible(false);
            ARC_TAGID t1 = rArchiveListArray::convTagId(arc_name);
            if (mArcTagIdReq != t1) {
                if (mArcTagId != t1) {
                    if (t1 != 1) {
                        mArcTagIdReq = t1;
                        mTimer = wait_frame;
                        mIsLoading = true;
                    } else {
                        mArcTagIdReq = 1;
                    }
                } else {
                    mArcTagIdReq = 1;
                }
            }
        } else {
            ARC_TAGID t1 = rArchiveListArray::convTagId(arc_name);
            if (mArcTagIdReq != t1) {
                if (mArcTagId != t1) {
                    if (t1 != 1) {
                        mArcTagIdReq = t1;
                        mTimer = wait_frame;
                        mIsLoading = true;
                    } else {
                        mArcTagIdReq = 1;
                    }
                } else {
                    mArcTagIdReq = 1;
                }
            }
        }
    }
    update(0.0f);
}

rTexture* uGUIBase::cTexArcLoader::replaceTex(rTexture* pTex, bool IsReleaseOldTex) {
    if (pTex != nullptr) {
        if (mpParent != nullptr) {
            rGUI* pres = mpParent->mpResource;
            if (pres != nullptr) {
                rTexture* pold = pres->replaceTexture(mTexIndex, pTex);
                if (mpObjTex != nullptr) {
                    mpObjTex->setVisible(true);
                }
                if (pold != nullptr) {
                    if (IsReleaseOldTex) {
                        pold->release();
                        return nullptr;
                    }
                }
                return pold;
            } else {
                return nullptr;
            }
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void uGUIBase::cTexArcLoader::resizeTex(s32 SizeW, s32 SizeH) {
    DDON_STUB("uGUIBase::cTexArcLoader::resizeTex")
    /* stub */
}

void uGUIBase::cTexArcLoader::setBlendState(u32 BlendState) {
    if (mpObjTex == nullptr) {
        return;
    }
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpObjTex) + 248) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpObjTex) + 248)) & 0xFFFFF00Fu) | ((BlendState * 16u) & 0xFF0u);
}

uGUIBase::cQuestTexLoader::cQuestTexLoader() {
    DDON_STUB("uGUIBase::cQuestTexLoader::cQuestTexLoader")
    /* stub */
}

uGUIBase::cQuestTexLoader::~cQuestTexLoader() {
}

__attribute__((weak)) void uGUIBase::cQuestTexLoader::request(u32 quest_id, bool isImmediate) {
    DDON_STUB("uGUIBase::cQuestTexLoader::request")
    /* stub */
}

uGUIBase::cClanPolicyMessages::cClanPolicyMessages() : mMottoMsgObjs(), mDayMsgObjs(), mHourMsgObjs(), mFeatureMsgObjs() {
    mpParent = nullptr;
    mHour = 0;
    mFeature = 0;
    mMotto = 0;
    mDay = 0;
}

uGUIBase::cClanPolicyMessages::~cClanPolicyMessages() {
}

__attribute__((weak)) void uGUIBase::cClanPolicyMessages::setup(uGUIBase* unit, const uGUIBase::cClanPolicyMessages::MsgObjParam(&mottoMsgObjParams)[2], const uGUIBase::cClanPolicyMessages::MsgObjParam(&dayMsgObjParams)[1], const uGUIBase::cClanPolicyMessages::MsgObjParam(&hourMsgObjParams)[1], const uGUIBase::cClanPolicyMessages::MsgObjParam(&featureMsgObjParams)[4]) {
    DDON_STUB("uGUIBase::cClanPolicyMessages::setup")
    /* stub */
}

__attribute__((weak)) void uGUIBase::cClanPolicyMessages::applyPolicy(u32 motto, u32 day, u32 hour, u32 feature) {
    DDON_STUB("uGUIBase::cClanPolicyMessages::applyPolicy")
    /* stub */
}

template MtTypedArray<cControl>::~MtTypedArray();

template MtTypedArray<uGUIBase::cKeepInScreen>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUIBase>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUIBtnGuide::cWork>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUIChargesInfo::cData>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUICheckList::cList>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUIPageDot::cPageDotWork>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUIPullDown::cData>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUIPullDown::cMsg>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUIRadioButton::cObject>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUITab::cTabWork>::~MtTypedArray();

template nDDOUtility::cNoObjectArray<cGUIInstAnimVariable>::~cNoObjectArray();

template nDDOUtility::cNoObjectArray<uGUIBase::cDuplicateData>::~cNoObjectArray();

template nDDOUtility::cNoObjectArray<uGUIBase::cVarData>::~cNoObjectArray();

