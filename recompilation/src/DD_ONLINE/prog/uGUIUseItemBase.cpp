// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIUseItemBase.h"
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Stage.h"
#include "cControl.h"
#include "cGUIUtility.h"
#include "cItemParam.h"
#include "../../XFramework/cUnit.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "nGUIItem.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "sPlayerManager.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "../../XFramework/uCoord.h"
#include "uGUIBase.h"
#include "uGUIPopCmd01.h"
#include "uGUIPopDetail01.h"
#include "uGUIPopListDialog.h"
#include "uGUIPopNumber01.h"
#include "uGUIShopBuy.h"
#include "uGUISystemMsg.h"
#include "uGUIsMenuBase.h"
#include "uHuman.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIUseItemBase::getDTI() const {
    return uGUIUseItemBase::DTI;
}

__attribute__((noinline)) uGUIUseItemBase::~uGUIUseItemBase() {
    if (mIsEndShareUnitUse) {
        if (mpShareUnit != nullptr) {
            mpShareUnit->setFlowId(10u);
            mpShareUnit->mEndMode = true;
            mIsEndShareUnitUse = false;
        }
    }
    if (mpDetail != nullptr) {
        mpDetail->kill();
        mpDetail = nullptr;
    }
    if (mpUnitPopNumber != nullptr) {
        mpUnitPopNumber->kill();
        mpUnitPopNumber = nullptr;
    }
    if (mpUnitPopCmd != nullptr) {
        mpUnitPopCmd->kill();
        mpUnitPopCmd = nullptr;
    }
    if (mpUnitPopCmd2 != nullptr) {
        mpUnitPopCmd2->kill();
        mpUnitPopCmd2 = nullptr;
    }
    if (mpUnitPopBuy != nullptr) {
        mpUnitPopBuy->kill();
        mpUnitPopBuy = nullptr;
    }
    if (mpUnitSystemMsg != nullptr) {
        mpUnitSystemMsg->kill();
        mpUnitSystemMsg = nullptr;
    }
    if (mpUnitPopList != nullptr) {
        mpUnitPopList->kill();
        mpUnitPopList = nullptr;
    }
    if (mpWaitPopBase != nullptr) {
        mpWaitPopBase->kill();
        mpWaitPopBase = nullptr;
    }
}

void uGUIUseItemBase::setup() {
    this->uGUIBase::setup();
}

void uGUIUseItemBase::kill() {
    this->uGUIBase::kill();
}

__attribute__((weak)) void uGUIUseItemBase::move() {
    DDON_STUB("uGUIUseItemBase::move")
    /* stub */
}

void uGUIUseItemBase::updatePtr() {
    if (mpDetail != nullptr) {
        if (!mpDetail->isEnable()) {
            mpDetail = nullptr;
        }
    }
    if (mpShareUnit != nullptr) {
        if (!mpShareUnit->isEnable()) {
            mpShareUnit = nullptr;
        }
    }
    if (mpUnitPopNumber != nullptr) {
        if (!mpUnitPopNumber->isEnable()) {
            mpUnitPopNumber = nullptr;
        }
    }
    if (mpUnitPopCmd != nullptr) {
        if (!mpUnitPopCmd->isEnable()) {
            mpUnitPopCmd = nullptr;
        }
    }
    if (mpUnitPopCmd2 != nullptr) {
        if (!mpUnitPopCmd2->isEnable()) {
            mpUnitPopCmd2 = nullptr;
        }
    }
    if (mpUnitSystemMsg != nullptr) {
        if (!mpUnitSystemMsg->isEnable()) {
            mpUnitSystemMsg = nullptr;
        }
    }
    if (mpUnitPopList != nullptr) {
        if (!mpUnitPopList->isEnable()) {
            mpUnitPopList = nullptr;
        }
    }
    if (mpUnitPopBuy != nullptr) {
        if (!mpUnitPopBuy->isEnable()) {
            mpUnitPopBuy = nullptr;
        }
    }
    if (mpWaitPopBase != nullptr) {
        if (!mpWaitPopBase->isEnable()) {
            mpWaitPopBase = nullptr;
        }
    }
}

__attribute__((weak)) void uGUIUseItemBase::adjustScale() {
    DDON_STUB("uGUIUseItemBase::adjustScale")
    /* stub */
}

s32 uGUIUseItemBase::getFreeSlotNum() {
    return 0;
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackUseItem(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::callbackUseItem")
    return {};
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackThrowItem(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::callbackThrowItem")
    return {};
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackPopDiscardItemNum(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::callbackPopDiscardItemNum")
    return {};
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackPopDiscardItemList(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::callbackPopDiscardItemList")
    return {};
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackGetItem(MtObject* pCaller, MtObject* pData, bool isUseNumbox, bool isAllNum) {
    DDON_STUB("uGUIUseItemBase::callbackGetItem")
    return {};
}

u32 uGUIUseItemBase::callbackGetItems(MtObject* pCaller, MtObject* pData) {
    if (pData != nullptr) {
        if (pData->isKindOf(nGUIItem::cItemList::DTI)) {
            if (static_cast<nGUIItem::cItemList*>(pData)->sendItems(mFromBagGroup, mToBagGroup) != nGUIItem::RET_TYPE_ERROR) {
                mItemList.mWaitFlag = 4;
                setFlowId(8u);
                if (mpShareUnit != nullptr) {
                    mpShareUnit->mItemList.mWaitFlag = mItemList.getWaitFlag();
                    mpShareUnit->setFlowId(8u);
                }
                return 3;
            }
        }
    }
    return 1;
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackExchangeItem(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::callbackExchangeItem")
    return {};
}

u32 uGUIUseItemBase::callbackMoveItem(MtObject* pCaller, MtObject* pData) {
    if (pData != nullptr) {
        if (!pData->isKindOf(nGUIItem::cItem::DTI)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

u32 uGUIUseItemBase::callbackEquipItem(MtObject* pCaller, MtObject* pData) {
    if (pData != nullptr) {
        if (!pData->isKindOf(uGUIUseItemBase::cEquipInfo::DTI)) {
            return 1;
        } else {
            cEquipInfo* p = static_cast<cEquipInfo*>(pData);
            if (p->mpItem != nullptr) {
                p->mpItem->equip(0xFFFFFFFFu, 0xFFFFFFFFu, nCharacterData::EQUIP_TYPE_PERFORMANCE);
                setFlowId(8u);
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        return 1;
    }
}

u32 uGUIUseItemBase::callbackSellItem(MtObject* pCaller, MtObject* pData) {
    if (pData != nullptr) {
        if (pData->isKindOf(nGUIItem::cItem::DTI)) {
            if (mpUnitPopBuy != nullptr) {
                mpUnitPopBuy->setInfoSell(static_cast<const nGUIItem::cItem*>(pData));
                mItemList.mWaitFlag = 4096;
                mIsShopExecute = true;
                setFlowId(5u);
                return 0;
            }
        }
    }
    return 1;
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackPopSellItemList(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::callbackPopSellItemList")
    return {};
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackGetItemFromOm(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::callbackGetItemFromOm")
    return {};
}

u32 uGUIUseItemBase::callbackSortMenu(MtObject* pCaller, MtObject* pData) {
    if (mpUnitPopCmd2 != nullptr) {
        mpUnitPopCmd2->kill();
        mpUnitPopCmd2 = nullptr;
        uGUIPopCmd01* t0 = createPopCmd01(false);
        if ((mpUnitPopCmd2 = t0) != nullptr) {
            t0->setSleepUnit(static_cast<uGUIBase*>(this));
            mpWaitPopBase = static_cast<uGUIBase*>(mpUnitPopCmd2);
            setFlowId(5u);
        }
        return 0;
    } else {
        uGUIPopCmd01* t0 = createPopCmd01(false);
        if ((mpUnitPopCmd2 = t0) != nullptr) {
            t0->setSleepUnit(static_cast<uGUIBase*>(this));
            mpWaitPopBase = static_cast<uGUIBase*>(mpUnitPopCmd2);
            setFlowId(5u);
        }
        return 0;
    }
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackPopItemList(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::callbackPopItemList")
    return {};
}

__attribute__((weak)) u32 uGUIUseItemBase::callbackOnlineShopDialog(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::callbackOnlineShopDialog")
    return {};
}

void uGUIUseItemBase::updateExit() {
    mIsEndShareUnitUse = true;
    endShareUnit();
    end();
}

void uGUIUseItemBase::updateWaitPopup() {
    if (mpUnitPopBuy != nullptr) {
        if (mIsShopExecute) {
            if (!mpUnitPopBuy->isActive()) {
                mIsShopExecute = false;
                setFlowId(4u);
            }
            return;
        }
    }
    const MtDTI* v0_0;
    MT_CTSTR v0_1;
    if (mpWaitPopBase != nullptr) {
        if (mpWaitPopBase->mResult != RESULT_EXIT) {
            return;
        } else {
            const MtDTI& t0 = mpWaitPopBase->getDTI();
            v0_1 = uGUIPopListDialog::DTI.mName;
            v0_0 = &t0;
        }
    } else {
        setFlowId(4u);
        return;
    }
    const MtDTI* v1_0;
    MT_CTSTR v1_1;
    for (;;) {
        if (v0_1 == v0_0->mName) {
            mpWaitPopBase->mEndType = 0;
            setFlowId(4u);
            return;
        } else {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                const MtDTI& t1 = mpWaitPopBase->getDTI();
                v1_1 = uGUISystemMsg::DTI.mName;
                v1_0 = &t1;
                break;
            }
        }
    }
    for (;;) {
        if (v1_1 != v1_0->mName) {
            if (v1_0->mpParent == nullptr) {
                setFlowId(4u);
                return;
            } else {
                v1_0 = v1_0->mpParent;
            }
        } else {
            break;
        }
    }
    mpWaitPopBase->mEndType = 0;
    setFlowId(4u);
}

void uGUIUseItemBase::updateOneFrameWait() {
    setFlowId(2u);
}

void uGUIUseItemBase::execOneFrameWait() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIUseItemBase::updateOneFrameWait);
}

__attribute__((weak)) u32 uGUIUseItemBase::evCtrlChangeBoxCore(cControl::Message* msg, nGUIExt::MSG_REASON reason) {
    if (mpShareUnit != nullptr) {
        if (msg != nullptr) {
            if (msg->reason == reason) {
                setWindowActive(true);
                mpShareUnit->setWindowActive(false);
                mpShareUnit->execOneFrameWait();
                mpShareUnit->mFocus = false;
                mFocus = true;
            } else {
                setWindowActive(false);
                mpShareUnit->setWindowActive(true);
                mpShareUnit->execOneFrameWait();
                mpShareUnit->mFocus = true;
                mFocus = false;
            }
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
            if (msg->reason == reason) {
                msg->changeSE = 0;
            }
        } else {
            setWindowActive(false);
            mpShareUnit->setWindowActive(true);
            mpShareUnit->execOneFrameWait();
            mpShareUnit->mFocus = true;
            mFocus = false;
            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 2u);
        }
    } else {
        if (msg != nullptr) {
            if (msg->reason == reason) {
                msg->changeSE = 0;
            }
        }
    }
    return 0;
}

u32 uGUIUseItemBase::evCtrlChangeBox(cControl::Message* msg) {
    if (msg != nullptr) {
        evCtrlChangeBoxCore(msg, (msg->reason == nGUIExt::TRG_START) ? nGUIExt::BTN_START : msg->reason);
    } else {
        evCtrlChangeBoxCore(msg, nGUIExt::BTN_START);
    }
    return 0;
}

bool uGUIUseItemBase::isEndPopup() {
    if (mpUnitPopBuy != nullptr) {
        if (mIsShopExecute) {
            if (mpUnitPopBuy->isActive()) {
                return false;
            } else {
                mIsShopExecute = false;
                return true;
            }
        } else {
            if (mpWaitPopBase != nullptr) {
                if (mpWaitPopBase->mResult == RESULT_EXIT) {
                    if (!mpWaitPopBase->getDTI().MtDTI::operator==(uGUIPopListDialog::DTI)) {
                        if (mpWaitPopBase->getDTI().MtDTI::operator==(uGUISystemMsg::DTI)) {
                            mpWaitPopBase->mEndType = 0;
                        }
                    } else {
                        mpWaitPopBase->mEndType = 0;
                    }
                    return true;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        }
    } else {
        if (mpWaitPopBase != nullptr) {
            if (mpWaitPopBase->mResult == RESULT_EXIT) {
                if (!mpWaitPopBase->getDTI().MtDTI::operator==(uGUIPopListDialog::DTI)) {
                    if (mpWaitPopBase->getDTI().MtDTI::operator==(uGUISystemMsg::DTI)) {
                        mpWaitPopBase->mEndType = 0;
                    }
                } else {
                    mpWaitPopBase->mEndType = 0;
                }
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
}

__attribute__((weak)) void uGUIUseItemBase::endShareUnit() {
    if (!mIsEndShareUnitUse) {
        return;
    }
    if (mpShareUnit == nullptr) {
        return;
    }
    mpShareUnit->setFlowId(10u);
    mpShareUnit->mEndMode = true;
    mIsEndShareUnitUse = false;
}

__attribute__((weak)) void uGUIUseItemBase::setPopupPos(uGUIUseItemBase::POPUP idx, const MtVector3& pos) {
    DDON_STUB("uGUIUseItemBase::setPopupPos")
    /* stub */
}

void uGUIUseItemBase::setFocus(bool b) {
    mFocus = b;
}

void uGUIUseItemBase::setFlowId(u32 flowId) {
    mFlowId = flowId;
    switch (flowId - 2u) {
        case 0:
        {
            mIsExeCtrl = true;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIUseItemBase::updateWait);
            break;
        }
        case 2:
        {
            mIsExeCtrl = false;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIUseItemBase::updateOneFrameWait);
            break;
        }
        case 3:
        {
            mIsExeCtrl = false;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIUseItemBase::updateWaitPopup);
            break;
        }
        case 6:
        {
            mIsExeCtrl = false;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIUseItemBase::updateWaitServer);
            break;
        }
        case 8:
        {
            mIsExeCtrl = false;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIUseItemBase::updateExit);
            break;
        }
        default:
        {
            break;
        }
    }
}

u32 uGUIUseItemBase::getFlowId() {
    return mFlowId;
}

void uGUIUseItemBase::releaseGlobalItem(bool isItemInit) {
    static_cast<sGUIExt*>(sGUI::getInstance())->releasePointerItem();
    static_cast<sGUIExt*>(sGUI::getInstance())->resetSendItemParameter(isItemInit);
}

__attribute__((weak)) bool uGUIUseItemBase::isCatchMode() {
    DDON_STUB("uGUIUseItemBase::isCatchMode")
    return {};
}

__attribute__((weak)) u32 uGUIUseItemBase::_callbackGetItem(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::_callbackGetItem")
    return {};
}

__attribute__((weak)) u32 uGUIUseItemBase::_callbackDiscardItem(MtObject* pCaller, MtObject* pData) {
    DDON_STUB("uGUIUseItemBase::_callbackDiscardItem")
    return {};
}

u32 uGUIUseItemBase::_callbackDiscardItems(MtObject* pCaller, MtObject* pData) {
    if (pData != nullptr) {
        if (pData->isKindOf(nGUIItem::cItemList::DTI)) {
            if (static_cast<nGUIItem::cItemList*>(pData)->discard(mFromBagGroup, mToBagGroup) != nGUIItem::RET_TYPE_ERROR) {
                mItemList.mWaitFlag = 2;
                setFlowId(8u);
                if (mpShareUnit != nullptr) {
                    mpShareUnit->mItemList.mWaitFlag = mItemList.getWaitFlag();
                    mpShareUnit->setFlowId(8u);
                }
                return 3;
            }
        }
    }
    return 1;
}

u32 uGUIUseItemBase::_callbackSellItems(MtObject* pCaller, MtObject* pData) {
    if (pData != nullptr) {
        if (pData->isKindOf(nGUIItem::cItemList::DTI)) {
            if (static_cast<nGUIItem::cItemList*>(pData)->sell(mFromBagGroup, mToBagGroup) != nGUIItem::RET_TYPE_ERROR) {
                mItemList.mWaitFlag = 4096;
                setFlowId(8u);
                if (mpShareUnit != nullptr) {
                    mpShareUnit->mItemList.mWaitFlag = mItemList.getWaitFlag();
                    mpShareUnit->setFlowId(8u);
                }
                return 3;
            }
        }
    }
    return 1;
}

inline uGUIUseItemBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIUseItemBase::MyDTI uGUIUseItemBase::DTI("uGUIUseItemBase", &::uGUIsMenuBase::DTI, 3136ul, 0u, 1u);

MtObject* uGUIUseItemBase::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGUIUseItemBase::cEquipInfo::getDTI() const {
    return uGUIUseItemBase::cEquipInfo::DTI;
}

inline uGUIUseItemBase::cEquipInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIUseItemBase::cEquipInfo::MyDTI uGUIUseItemBase::cEquipInfo::DTI("uGUIUseItemBase::cEquipInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* uGUIUseItemBase::cEquipInfo::MyDTI::newInstance() const {
    return new (16u) uGUIUseItemBase::cEquipInfo;
}

const MtDTI& uGUIUseItemBase::cGetItemInfo::getDTI() const {
    return uGUIUseItemBase::cGetItemInfo::DTI;
}

__attribute__((weak)) void uGUIUseItemBase::cGetItemInfo::operator delete(void* p_addr) {
    uGUIUseItemBase::cGetItemInfo::getAllocator()->memFree(p_addr);
}

inline uGUIUseItemBase::cGetItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIUseItemBase::cGetItemInfo::MyDTI uGUIUseItemBase::cGetItemInfo::DTI("uGUIUseItemBase::cGetItemInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* uGUIUseItemBase::cGetItemInfo::MyDTI::newInstance() const {
    return new (16u) uGUIUseItemBase::cGetItemInfo;
}

