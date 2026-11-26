// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUIBoxGachaInfo.h"
#include "Protocol/PacketData/BoxGacha.h"
#include "Protocol/PacketData/Gacha.h"
#include "Protocol/PacketData/Item.h"
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
#include "cGUIObjTextureRef.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
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
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIGPShop.h"
#include "uGUIPopDetail01.h"
#include "uGUISystemMsg.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBoxGachaInfo::getDTI() const {
    return uGUIBoxGachaInfo::DTI;
}

inline MtAllocator* uGUIBoxGachaInfo::getAllocator() {
    return MtMemoryAllocator::getAllocator(uGUIBoxGachaInfo::DTI);
}

void* uGUIBoxGachaInfo::operator new(size_t sz, u32 align) {
    return uGUIBoxGachaInfo::getAllocator()->memAlloc(sz, align, uGUIBoxGachaInfo::DTI.getID());
}

inline void uGUIBoxGachaInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIBoxGachaInfo::DTI)->memFree(p_addr);
}

__attribute__((noinline)) uGUIBoxGachaInfo::~uGUIBoxGachaInfo() {
    if (mpDetail != nullptr) {
        mpDetail->kill();
        mpDetail = nullptr;
    }
    if (mpGPShop != nullptr) {
        mpGPShop->kill();
        mpGPShop = nullptr;
    }
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearBoxGachaListPacket();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearBoxGachaBuyPacket();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearBoxGachaResetPacket();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearBoxGachaDrawInfoPacket();
}

bool uGUIBoxGachaInfo::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BOX_GACHA_INFO_GUI"), 129u, 1472555712l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_GACHA_GMD", 0u);
}

__attribute__((weak)) void uGUIBoxGachaInfo::setup() {
    DDON_STUB("uGUIBoxGachaInfo::setup")
    /* stub */
}

void uGUIBoxGachaInfo::kill() {
    this->uGUIBase::kill();
    if (mpDetail != nullptr) {
        mpDetail->kill();
        mpDetail = nullptr;
    }
    if (mpGPShop != nullptr) {
        mpGPShop->kill();
        mpGPShop = nullptr;
    }
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->mEndType = 0;
        mpGUISystemMsg->end();
    }
    mpGUISystemMsg = nullptr;
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIBoxGachaInfo::setupListLot(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    if (pItemBase == nullptr) {
        return;
    }
    if (pInfoBase == nullptr) {
        return;
    }
    setupListLot(static_cast<cLotList*>(pItemBase), static_cast<cLotInfo*>(pInfoBase), index, false);
}

__attribute__((weak)) void uGUIBoxGachaInfo::setupListLot(uGUIBoxGachaInfo::cLotList* pLot, uGUIBoxGachaInfo::cLotInfo* pInfo, u32 index, bool select) {
    DDON_STUB("uGUIBoxGachaInfo::setupListLot")
    /* stub */
}

void uGUIBoxGachaInfo::hideListLot(uGUIBase::cScrollListItemBase* pLotBase) {
    if (pLotBase == nullptr) {
        return;
    }
    cLotList* pLot = static_cast<cLotList*>(pLotBase);
    if (pLot->mpInstNullLotlist == nullptr) {
        return;
    }
    pLot->mpInstNullLotlist->setVisible(false);
}

void uGUIBoxGachaInfo::setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    if (pItemBase == nullptr) {
        return;
    }
    if (pInfoBase == nullptr) {
        return;
    }
    setupListItem(static_cast<cListItem*>(pItemBase), static_cast<cListInfo*>(pInfoBase), index, false);
}

__attribute__((weak)) void uGUIBoxGachaInfo::setupListItem(uGUIBoxGachaInfo::cListItem* pItem, uGUIBoxGachaInfo::cListInfo* pInfo, u32 index, bool select) {
    DDON_STUB("uGUIBoxGachaInfo::setupListItem")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::hideListItem(uGUIBase::cScrollListItemBase* pItemBase) {
    DDON_STUB("uGUIBoxGachaInfo::hideListItem")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::refreshInfo() {
    DDON_STUB("uGUIBoxGachaInfo::refreshInfo")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::restartFromBoughtBox() {
    DDON_STUB("uGUIBoxGachaInfo::restartFromBoughtBox")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::adjustCursor(bool isFocus) {
    DDON_STUB("uGUIBoxGachaInfo::adjustCursor")
    /* stub */
}

void uGUIBoxGachaInfo::dlAbort() {
    mSummary.mRefImageLoader.abort();
}

void uGUIBoxGachaInfo::setBoxFlag(bool flag) {
    bool t0 = mBox;
    mBox = flag;
    if (t0 != flag) {
        mInfoIndex = 0;
    }
    createLotList();
    if (mpHCtrl != nullptr) {
        if (!mBox) {
            mpHCtrl->resetItemNum(1, static_cast<const u32*>(nullptr), 0);
        } else {
            mpHCtrl->resetItemNum(2, static_cast<const u32*>(nullptr), 0);
        }
    }
    if (mResetBtn.mpInstance != nullptr) {
        mResetBtn.mpInstance->setVisible(mBox);
    }
    if (mBox) {
        MT_CTSTR t1 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 54u);
        cGUIObject* t2 = getObjectFromId(6u, 2u);
        mCommon.mpObjMsgHeader = static_cast<cGUIObjMessage*>(t2);
        setObjectMessage(t2, t1, 0u, false);
        MT_CTSTR t5 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 55u);
        cGUIObject* t6 = getObjectFromId(6u, 10u);
        mCommon.mpObjMsgHeaderSub = static_cast<cGUIObjMessage*>(t6);
        setObjectMessage(t6, t5, 0u, false);
    } else {
        MT_CTSTR t3 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 37u);
        cGUIObject* t4 = getObjectFromId(6u, 2u);
        mCommon.mpObjMsgHeader = static_cast<cGUIObjMessage*>(t4);
        setObjectMessage(t4, t3, 0u, false);
        MT_CTSTR t5 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 36u);
        cGUIObject* t6 = getObjectFromId(6u, 10u);
        mCommon.mpObjMsgHeaderSub = static_cast<cGUIObjMessage*>(t6);
        setObjectMessage(t6, t5, 0u, false);
    }
    setMessageHorizontalInterval(static_cast<cGUIObj2D*>(mCommon.mpObjMsgHeader), static_cast<cGUIObj2D*>(mCommon.mpObjMsgHeaderSub), 8.0f, true);
}

__attribute__((weak)) void uGUIBoxGachaInfo::createLotList() {
    DDON_STUB("uGUIBoxGachaInfo::createLotList")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::gachaReset() {
    DDON_STUB("uGUIBoxGachaInfo::gachaReset")
    /* stub */
}

__attribute__((weak)) bool uGUIBoxGachaInfo::getBoughtBoxListRequestServer() {
    DDON_STUB("uGUIBoxGachaInfo::getBoughtBoxListRequestServer")
    return {};
}

__attribute__((weak)) void uGUIBoxGachaInfo::getBoughtBoxListCallBack() {
    DDON_STUB("uGUIBoxGachaInfo::getBoughtBoxListCallBack")
    /* stub */
}

void uGUIBoxGachaInfo::updatePtr() {
    if (mpDetail != nullptr) {
        if (!mpDetail->isEnable()) {
            mpDetail = nullptr;
        }
    }
    if (mpGUISystemMsg != nullptr) {
        if (!mpGUISystemMsg->isEnable()) {
            mpGUISystemMsg = nullptr;
        }
    }
    if (mpGPShop == nullptr) {
        return;
    }
    if (mpGPShop->isEnable()) {
        return;
    }
    mpGPShop = nullptr;
}

__attribute__((weak)) void uGUIBoxGachaInfo::updateInit() {
    DDON_STUB("uGUIBoxGachaInfo::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::updateWait() {
    DDON_STUB("uGUIBoxGachaInfo::updateWait")
    /* stub */
}

void uGUIBoxGachaInfo::updateExit() {
    end();
}

__attribute__((weak)) void uGUIBoxGachaInfo::moveInput() {
    DDON_STUB("uGUIBoxGachaInfo::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::moveEvent() {
    DDON_STUB("uGUIBoxGachaInfo::moveEvent")
    /* stub */
}

void uGUIBoxGachaInfo::init() {
    cGUIObjMessage* t0 = mSummary.mpObjImgMsg;
    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 39u), 0u, false);
    if (mSummary.mpObjImgMsg != nullptr) {
        mSummary.mpObjImgMsg->setVisible(false);
    }
    u32 v0_0 = mList.mListCtrl.mItemArray.mLength;
    u32 v0_3 = mList.mListCtrl.mItemArray.mBufsiz;
    unsigned int i0_10 = 19968;
    u32 v1_0;
    u32 v1_3;
    for (;;) {
        if (v0_0 < v0_3) {
            mList.mListCtrl.mItemArray.mLength = v0_0 + 1u;
            mList.mListCtrl.mItemArray.mpArray[v0_0] = reinterpret_cast<MtObject*>(reinterpret_cast<char*>(this) + i0_10);
            v1_0 = v0_0 + 1u;
            v1_3 = v0_3;
        } else {
            void* t1 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(v0_3 + 32u) * 8, 16u);
            memset(t1, 0, static_cast<size_t>(v0_3 + 32u) * 8);
            memcpy(t1, static_cast<const void*>(mList.mListCtrl.mItemArray.mpArray), static_cast<size_t>(mList.mListCtrl.mItemArray.mLength) * 8);
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mList.mListCtrl.mItemArray.mpArray));
            mList.mListCtrl.mItemArray.mpArray = static_cast<MtObject* *>(t1);
            mList.mListCtrl.mItemArray.mBufsiz = v0_3 + 32u;
            u32 t2 = mList.mListCtrl.mItemArray.mLength;
            mList.mListCtrl.mItemArray.mLength = t2 + 1u;
            mList.mListCtrl.mItemArray.mpArray[t2] = reinterpret_cast<MtObject*>(reinterpret_cast<char*>(this) + i0_10);
            v1_0 = t2 + 1u;
            v1_3 = v0_3 + 32u;
        }
        if ((i0_10 + 560u) != 31168) {
            v0_0 = v1_0;
            v0_3 = v1_3;
            i0_10 = i0_10 + 560u;
        } else {
            break;
        }
    }
    u32 v3_0 = mResult.mListCtrl.mItemArray.mLength;
    u32 v3_3 = mResult.mListCtrl.mItemArray.mBufsiz;
    unsigned int i3_10 = 32352;
    u32 v4_0;
    u32 v4_3;
    for (;;) {
        if (v3_0 < v3_3) {
            mResult.mListCtrl.mItemArray.mLength = v3_0 + 1u;
            mResult.mListCtrl.mItemArray.mpArray[v3_0] = reinterpret_cast<MtObject*>(reinterpret_cast<char*>(this) + i3_10);
            v4_0 = v3_0 + 1u;
            v4_3 = v3_3;
        } else {
            void* t3 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(v3_3 + 32u) * 8, 16u);
            memset(t3, 0, static_cast<size_t>(v3_3 + 32u) * 8);
            memcpy(t3, static_cast<const void*>(mResult.mListCtrl.mItemArray.mpArray), static_cast<size_t>(mResult.mListCtrl.mItemArray.mLength) * 8);
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mResult.mListCtrl.mItemArray.mpArray));
            mResult.mListCtrl.mItemArray.mpArray = static_cast<MtObject* *>(t3);
            mResult.mListCtrl.mItemArray.mBufsiz = v3_3 + 32u;
            u32 t4 = mResult.mListCtrl.mItemArray.mLength;
            mResult.mListCtrl.mItemArray.mLength = t4 + 1u;
            mResult.mListCtrl.mItemArray.mpArray[t4] = reinterpret_cast<MtObject*>(reinterpret_cast<char*>(this) + i3_10);
            v4_0 = t4 + 1u;
            v4_3 = v3_3 + 32u;
        }
        if ((i3_10 + 560u) != 43552) {
            v3_0 = v4_0;
            v3_3 = v4_3;
            i3_10 = i3_10 + 560u;
        } else {
            break;
        }
    }
    u32 v6_0 = mLotList.mListCtrl.mItemArray.mLength;
    u32 v6_3 = mLotList.mListCtrl.mItemArray.mBufsiz;
    unsigned int i6_10 = 3496;
    u32 v7_0;
    u32 v7_3;
    for (;;) {
        if (v6_0 < v6_3) {
            mLotList.mListCtrl.mItemArray.mLength = v6_0 + 1u;
            mLotList.mListCtrl.mItemArray.mpArray[v6_0] = reinterpret_cast<MtObject*>(reinterpret_cast<char*>(this) + i6_10);
            v7_0 = v6_0 + 1u;
            v7_3 = v6_3;
        } else {
            void* t5 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(v6_3 + 32u) * 8, 16u);
            memset(t5, 0, static_cast<size_t>(v6_3 + 32u) * 8);
            memcpy(t5, static_cast<const void*>(mLotList.mListCtrl.mItemArray.mpArray), static_cast<size_t>(mLotList.mListCtrl.mItemArray.mLength) * 8);
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mLotList.mListCtrl.mItemArray.mpArray));
            mLotList.mListCtrl.mItemArray.mpArray = static_cast<MtObject* *>(t5);
            mLotList.mListCtrl.mItemArray.mBufsiz = v6_3 + 32u;
            u32 t6 = mLotList.mListCtrl.mItemArray.mLength;
            mLotList.mListCtrl.mItemArray.mLength = t6 + 1u;
            mLotList.mListCtrl.mItemArray.mpArray[t6] = reinterpret_cast<MtObject*>(reinterpret_cast<char*>(this) + i6_10);
            v7_0 = t6 + 1u;
            v7_3 = v6_3 + 32u;
        }
        if ((i6_10 + 736u) != 14536) {
            v6_0 = v7_0;
            v6_3 = v7_3;
            i6_10 = i6_10 + 736u;
        } else {
            break;
        }
    }
    createLotList();
    adjustTabCursor(false);
}

__attribute__((weak)) void uGUIBoxGachaInfo::createList() {
    DDON_STUB("uGUIBoxGachaInfo::createList")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::createListBox() {
    DDON_STUB("uGUIBoxGachaInfo::createListBox")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::createListSummary() {
    DDON_STUB("uGUIBoxGachaInfo::createListSummary")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::createResultList() {
    DDON_STUB("uGUIBoxGachaInfo::createResultList")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::createFree(cGUIInstAnimation* pCaption, cGUIObjMessage* pText) {
    DDON_STUB("uGUIBoxGachaInfo::createFree")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::adjustTabCursor(bool isFocus) {
    DDON_STUB("uGUIBoxGachaInfo::adjustTabCursor")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::selectFlow(u32 flowID) {
    DDON_STUB("uGUIBoxGachaInfo::selectFlow")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::updateDetail() {
    DDON_STUB("uGUIBoxGachaInfo::updateDetail")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::updateItem() {
    DDON_STUB("uGUIBoxGachaInfo::updateItem")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::setupDialog() {
    DDON_STUB("uGUIBoxGachaInfo::setupDialog")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::setupDialogReset() {
    DDON_STUB("uGUIBoxGachaInfo::setupDialogReset")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::setupDialogResetMes() {
    DDON_STUB("uGUIBoxGachaInfo::setupDialogResetMes")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::setupDialogGPShop() {
    DDON_STUB("uGUIBoxGachaInfo::setupDialogGPShop")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::setupDialogSettlement() {
    DDON_STUB("uGUIBoxGachaInfo::setupDialogSettlement")
    /* stub */
}

__attribute__((weak)) bool uGUIBoxGachaInfo::updateDialog() {
    DDON_STUB("uGUIBoxGachaInfo::updateDialog")
    return {};
}

__attribute__((weak)) void uGUIBoxGachaInfo::setupPlayDialog() {
    DDON_STUB("uGUIBoxGachaInfo::setupPlayDialog")
    /* stub */
}

__attribute__((weak)) void uGUIBoxGachaInfo::updatePriceInfo() {
    DDON_STUB("uGUIBoxGachaInfo::updatePriceInfo")
    /* stub */
}

__attribute__((weak)) bool uGUIBoxGachaInfo::dispError() {
    DDON_STUB("uGUIBoxGachaInfo::dispError")
    return {};
}

void uGUIBoxGachaInfo::updateJpegLoader() {
    mSummary.mRefImageLoader.update(getDeltaTime());
    if (mSummary.mRefImageLoader.isReplaceTex()) {
        if (mSummary.mRefImageLoader.isHaveTicket()) {
            if (mSummary.mRefImageLoader.isFail()) {
                if (mSummary.mpInstImgLoadAnm != nullptr) {
                    mSummary.mpInstImgLoadAnm->setVisible(false);
                }
                if (mSummary.mpObjImgMsg != nullptr) {
                    mSummary.mpObjImgMsg->setVisible(true);
                }
            } else {
                if (mSummary.mpInstImgLoadAnm != nullptr) {
                    mSummary.mpInstImgLoadAnm->setVisible(true);
                }
                if (mSummary.mpObjImgMsg != nullptr) {
                    mSummary.mpObjImgMsg->setVisible(false);
                }
            }
        } else {
            if (mSummary.mpInstImgLoadAnm != nullptr) {
                mSummary.mpInstImgLoadAnm->setVisible(false);
            }
            if (mSummary.mpObjImgMsg != nullptr) {
                mSummary.mpObjImgMsg->setVisible(false);
            }
        }
    } else {
        if (mSummary.mRefImageLoader.isFail()) {
            if (mSummary.mpInstImgLoadAnm != nullptr) {
                mSummary.mpInstImgLoadAnm->setVisible(false);
            }
            if (mSummary.mpObjImgMsg != nullptr) {
                mSummary.mpObjImgMsg->setVisible(true);
            }
        } else {
            if (mSummary.mpInstImgLoadAnm != nullptr) {
                mSummary.mpInstImgLoadAnm->setVisible(true);
            }
            if (mSummary.mpObjImgMsg != nullptr) {
                mSummary.mpObjImgMsg->setVisible(false);
            }
        }
    }
}

void uGUIBoxGachaInfo::listLotUpdate(uGUIBoxGachaInfo::cLotList* pLot, uGUIBoxGachaInfo::cLotInfo* pInfo) {
    if (pLot == nullptr) {
        return;
    }
    if (pInfo == nullptr) {
        return;
    }
    if ((pLot->mpInstNullLotlist->mAttr & 1u) == 0) {
        return;
    }
    pLot->mRefJpegDL.update(getDeltaTime());
    if (pLot->mRefJpegDL.isReplaceTex()) {
        if (pLot->mRefJpegDL.isHaveTicket()) {
            if (pLot->mRefJpegDL.isFail()) {
                if (pLot->mpObjTexRefIcon != nullptr) {
                    pLot->mpObjTexRefIcon->setVisible(false);
                }
                if (pLot->mpInstImgLoadAnm != nullptr) {
                    pLot->mpInstImgLoadAnm->setVisible(false);
                }
            } else {
                if (pLot->mpInstImgLoadAnm != nullptr) {
                    pLot->mpInstImgLoadAnm->setVisible(true);
                }
                if (pLot->mpObjTexRefIcon != nullptr) {
                    pLot->mpObjTexRefIcon->setVisible(false);
                }
            }
        } else {
            if (pLot->mpObjTexRefIcon != nullptr) {
                pLot->mpObjTexRefIcon->setVisible(true);
            }
            if (pLot->mpInstImgLoadAnm != nullptr) {
                pLot->mpInstImgLoadAnm->setVisible(false);
            }
        }
    } else {
        if (pLot->mRefJpegDL.isFail()) {
            if (pLot->mpObjTexRefIcon != nullptr) {
                pLot->mpObjTexRefIcon->setVisible(false);
            }
            if (pLot->mpInstImgLoadAnm != nullptr) {
                pLot->mpInstImgLoadAnm->setVisible(false);
            }
        } else {
            if (pLot->mpInstImgLoadAnm != nullptr) {
                pLot->mpInstImgLoadAnm->setVisible(true);
            }
            if (pLot->mpObjTexRefIcon != nullptr) {
                pLot->mpObjTexRefIcon->setVisible(false);
            }
        }
    }
}

__attribute__((weak)) void uGUIBoxGachaInfo::evDecide() {
    DDON_STUB("uGUIBoxGachaInfo::evDecide")
    /* stub */
}

void uGUIBoxGachaInfo::evCancel() {
    if (mCtrlType != 0) {
        mCtrlType = 0;
        mGPBtn.uGUIBase::cReferenceUIButton::setFocus(false);
        mResetBtn.uGUIBase::cReferenceUIButton::setFocus(false);
    } else {
        if (mLotList.mListCtrl.getCtrl() != nullptr) {
            mLotList.mListCtrl.getCtrl()->setCurrentPos(0, false);
            mLotList.mListCtrl.setListPos(false);
        }
        mpTabCtrl->setCurrentPos(0, false);
        selectFlow(3u);
        adjustTabCursor(true);
        mSelectResult = 2;
    }
}

void uGUIBoxGachaInfo::evAdjustTab() {
    adjustTabCursor(true);
    setWindowActive(true);
    mIsForceRefresh = true;
    mIsValidCtrl = true;
    mBtnCtrl = true;
    mList.mListCtrl.setEnableKey(false);
    mResult.mListCtrl.setEnableKey(false);
    mList.mListCtrl.clearCursorFocus();
    mResult.mListCtrl.clearCursorFocus();
    if (mList.mListCtrl.mpOwner != nullptr) {
        mList.mListCtrl.mIsAutoDispPointer = false;
        mList.mListCtrl.mPointerPrio = mList.mListCtrl.mpOwner->getBasePointerPriority();
    } else {
        mList.mListCtrl.mIsAutoDispPointer = false;
        mList.mListCtrl.mPointerPrio = 10;
    }
    if (mResult.mListCtrl.mpOwner != nullptr) {
        mResult.mListCtrl.mIsAutoDispPointer = false;
        mResult.mListCtrl.mPointerPrio = mResult.mListCtrl.mpOwner->getBasePointerPriority();
    } else {
        mResult.mListCtrl.mIsAutoDispPointer = false;
        mResult.mListCtrl.mPointerPrio = 10;
    }
    adjustCursor(true);
}

u32 uGUIBoxGachaInfo::evCtrlDecide(cControl::Message* msg) {
    if (mIsNowRequestBoughtItemNum) {
        if (msg != nullptr) {
            msg->changeSE = 0;
        }
    } else {
        if (mCtrlType != 0) {
            if (mFlowId <= 9u) {
                if (((840ul >> static_cast<unsigned long>(mFlowId & 31u)) & 1ul) != 0) {
                    setInputEvent(66u);
                }
            }
        } else {
            setInputEvent(66u);
        }
    }
    return 0;
}

u32 uGUIBoxGachaInfo::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIBoxGachaInfo::evCtrlAdjustCursorH(cControl::Message* msg) {
    setInputEvent(68u);
    return 0;
}

u32 uGUIBoxGachaInfo::evCtrlTabLRMove(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

u32 uGUIBoxGachaInfo::evCtrlBtnClick(cControl::Message* msg) {
    if (msg->mouse_hit_id == 1) {
        mGPBtn.uGUIBase::cReferenceUIButton::setFocus(true);
        mResetBtn.uGUIBase::cReferenceUIButton::setFocus(true);
        if (mpHCtrl != nullptr) {
            mpHCtrl->setCurrentPos(msg->mouse_hit_id, false);
        }
        setWindowActive(true);
        mBtnCtrl = true;
        if (mIsNowRequestBoughtItemNum) {
            if (msg != nullptr) {
                msg->changeSE = 0;
            }
        } else {
            if (mCtrlType != 0) {
                if (mFlowId <= 9u) {
                    if (((840ul >> static_cast<unsigned long>(mFlowId & 31u)) & 1ul) != 0) {
                        setInputEvent(66u);
                    }
                }
            } else {
                setInputEvent(66u);
            }
        }
    } else {
        if (msg->mouse_hit_id == 0) {
            mGPBtn.uGUIBase::cReferenceUIButton::setFocus(true);
            mResetBtn.uGUIBase::cReferenceUIButton::setFocus(false);
            if (mpHCtrl != nullptr) {
                mpHCtrl->setCurrentPos(msg->mouse_hit_id, false);
            }
            setWindowActive(true);
            mBtnCtrl = true;
            if (mIsNowRequestBoughtItemNum) {
                if (msg != nullptr) {
                    msg->changeSE = 0;
                }
            } else {
                if (mCtrlType != 0) {
                    if (mFlowId <= 9u) {
                        if (((840ul >> static_cast<unsigned long>(mFlowId & 31u)) & 1ul) != 0) {
                            setInputEvent(66u);
                        }
                    }
                } else {
                    setInputEvent(66u);
                }
            }
        }
    }
    return 0;
}

u32 uGUIBoxGachaInfo::evCtrlStart(cControl::Message* msg) {
    setInputEvent(70u);
    return 0;
}

u32 uGUIBoxGachaInfo::evCtrlUp(cControl::Message* msg) {
    setInputEvent(71u);
    return 0;
}

u32 uGUIBoxGachaInfo::evCtrlDown(cControl::Message* msg) {
    setInputEvent(72u);
    return 0;
}

inline uGUIBoxGachaInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBoxGachaInfo::MyDTI uGUIBoxGachaInfo::DTI("uGUIBoxGachaInfo", &::uGUIsMenuBase::DTI, 44688ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBoxGachaInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIBoxGachaInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBoxGachaInfo::cLotList::getDTI() const {
    return uGUIBoxGachaInfo::cLotList::DTI;
}

inline void uGUIBoxGachaInfo::cLotList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIBoxGachaInfo::cLotList::DTI)->memFree(p_addr);
}

inline uGUIBoxGachaInfo::cLotList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBoxGachaInfo::cLotList::MyDTI uGUIBoxGachaInfo::cLotList::DTI("uGUIBoxGachaInfo::cLotList", &::uGUIBase::cScrollListItemBase::DTI, 736ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBoxGachaInfo::cLotList::MyDTI::newInstance() const {
    DDON_STUB("uGUIBoxGachaInfo::cLotList::MyDTI::newInstance")
    return nullptr;
}

uGUIBoxGachaInfo::stSummary::stSummary() {
    DDON_STUB("uGUIBoxGachaInfo::stSummary::stSummary")
    /* stub */
}

const MtDTI& uGUIBoxGachaInfo::cSumList::getDTI() const {
    return uGUIBoxGachaInfo::cSumList::DTI;
}

inline void* uGUIBoxGachaInfo::cSumList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uGUIBoxGachaInfo::cSumList::DTI)->memAlloc(sz, align, uGUIBoxGachaInfo::cSumList::DTI.getID());
}

inline void uGUIBoxGachaInfo::cSumList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIBoxGachaInfo::cSumList::DTI)->memFree(p_addr);
}

inline uGUIBoxGachaInfo::cSumList::cSumList() {
    memset(static_cast<void*>(&mpInstNull), 0, 200ul);
}

inline uGUIBoxGachaInfo::cSumList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBoxGachaInfo::cSumList::MyDTI uGUIBoxGachaInfo::cSumList::DTI("uGUIBoxGachaInfo::cSumList", &::uGUIBase::cScrollListItemBase::DTI, 288ul, 0u, 0u);

MtObject* uGUIBoxGachaInfo::cSumList::MyDTI::newInstance() const {
    return new (16u) uGUIBoxGachaInfo::cSumList;
}

uGUIBoxGachaInfo::stList::stList() {
    DDON_STUB("uGUIBoxGachaInfo::stList::stList")
    /* stub */
}

const MtDTI& uGUIBoxGachaInfo::cListItem::getDTI() const {
    return uGUIBoxGachaInfo::cListItem::DTI;
}

inline void uGUIBoxGachaInfo::cListItem::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIBoxGachaInfo::cListItem::DTI)->memFree(p_addr);
}

inline uGUIBoxGachaInfo::cListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBoxGachaInfo::cListItem::MyDTI uGUIBoxGachaInfo::cListItem::DTI("uGUIBoxGachaInfo::cListItem", &::uGUIBase::cScrollListItemBase::DTI, 560ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBoxGachaInfo::cListItem::MyDTI::newInstance() const {
    DDON_STUB("uGUIBoxGachaInfo::cListItem::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBoxGachaInfo::cLotInfo::getDTI() const {
    return uGUIBoxGachaInfo::cLotInfo::DTI;
}

inline uGUIBoxGachaInfo::cLotInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBoxGachaInfo::cLotInfo::MyDTI uGUIBoxGachaInfo::cLotInfo::DTI("uGUIBoxGachaInfo::cLotInfo", &::uGUIBase::cScrollListInfoBase::DTI, 328ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBoxGachaInfo::cLotInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIBoxGachaInfo::cLotInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBoxGachaInfo::cListInfo::getDTI() const {
    return uGUIBoxGachaInfo::cListInfo::DTI;
}

inline void uGUIBoxGachaInfo::cListInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIBoxGachaInfo::cListInfo::DTI)->memFree(p_addr);
}

inline uGUIBoxGachaInfo::cListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBoxGachaInfo::cListInfo::MyDTI uGUIBoxGachaInfo::cListInfo::DTI("uGUIBoxGachaInfo::cListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBoxGachaInfo::cListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIBoxGachaInfo::cListInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBoxGachaInfo::cItemInfo::getDTI() const {
    return uGUIBoxGachaInfo::cItemInfo::DTI;
}

inline void* uGUIBoxGachaInfo::cItemInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uGUIBoxGachaInfo::cItemInfo::DTI)->memAlloc(sz, align, uGUIBoxGachaInfo::cItemInfo::DTI.getID());
}

inline void uGUIBoxGachaInfo::cItemInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIBoxGachaInfo::cItemInfo::DTI)->memFree(p_addr);
}

inline uGUIBoxGachaInfo::cItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBoxGachaInfo::cItemInfo::MyDTI uGUIBoxGachaInfo::cItemInfo::DTI("uGUIBoxGachaInfo::cItemInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* uGUIBoxGachaInfo::cItemInfo::MyDTI::newInstance() const {
    return new (16u) uGUIBoxGachaInfo::cItemInfo;
}

