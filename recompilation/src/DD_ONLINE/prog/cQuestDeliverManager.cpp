// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestDeliverManager.h"
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Quest.h"
#include "Protocol/UserSession/S2C.h"
#include "cNetGameServer.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestManagerBase.h"
#include "cQuestSvNotice.h"
#include "cQuestSvNoticeManager.h"
#include "cQuestSvRequest.h"
#include "cQuestSvRequestManager.h"
#include "cQuestTask.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "sTalkManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestDeliverManager::getDTI() const {
    return cQuestDeliverManager::DTI;
}

void* cQuestDeliverManager::operator new(size_t sz, u32 align) {
    return cQuestDeliverManager::getAllocator()->memAlloc(sz, align, cQuestDeliverManager::DTI.getID());
}

bool cQuestDeliverManager::isReqDeliverItem() const {
    return mIsReqDeliverItem;
}

const nQuest::cQuestDeliverRequestInfo* cQuestDeliverManager::getQuestDeliverRequestInfo(const nQuest::SCHEDULE_ID& scheduleId) const {
    cQuestTask* pTask = sQuestManagerExt::getInstance()->getQuestTask(scheduleId);
    if (pTask != nullptr) {
        if (!pTask->isWaitDeliver() && !pTask->isPreWaitDeliver()) {
            return nullptr;
        }
        return pTask->getDeliverRequestInfo();
    } else {
        return nullptr;
    }
}

__attribute__((weak)) nQuest::cQuestDeliveredInfo* cQuestDeliverManager::getQuestDeliveredInfo(const nQuest::SCHEDULE_ID& scheduleId) const {
    DDON_STUB("cQuestDeliverManager::getQuestDeliveredInfo")
    return nullptr;
}

__attribute__((weak)) bool cQuestDeliverManager::fulfillDeliverItem(nQuest::SCHEDULE_ID scheduleId, u32 itemId) const {
    DDON_STUB("cQuestDeliverManager::fulfillDeliverItem")
    return {};
}

__attribute__((weak)) void cQuestDeliverManager::deliverItem(const nQuest::SCHEDULE_ID& scheduleId, ItemUIDListVec& itemUIDList) {
    DDON_STUB("cQuestDeliverManager::deliverItem")
    /* stub */
}

__attribute__((weak)) void cQuestDeliverManager::updateDeliveredInfo(nQuest::SCHEDULE_ID scheduleId, u32 charcterId, const MtTypedArray<CDataDeliveredItem>& deliveredList) {
    DDON_STUB("cQuestDeliverManager::updateDeliveredInfo")
    /* stub */
}

void cQuestDeliverManager::release() {
    if (mDeliverItemList.mLength != 0) {
        u32 v0_0 = mDeliverItemList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mDeliverItemList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mDeliverItemList.mpArray[i0_3];
                v1_0 = mDeliverItemList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mDeliverItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDeliverItemList.mpArray));
    }
    mDeliverItemList.mpArray = nullptr;
    mDeliverItemList.mBufsiz = 0;
    mDeliverItemList.mLength = 0;
    if (mDeliverInfo.mLength != 0) {
        u32 v3_0 = mDeliverInfo.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mDeliverInfo.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mDeliverInfo.mpArray[i3_3];
                v4_0 = mDeliverInfo.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mDeliverInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDeliverInfo.mpArray));
    }
    mDeliverInfo.mpArray = nullptr;
    mDeliverInfo.mBufsiz = 0;
    mDeliverInfo.mLength = 0;
    mIsReqDeliverItem = false;
}

__attribute__((weak)) void cQuestDeliverManager::deleteDeliveredInfo(nQuest::SCHEDULE_ID scheduleId, u32 itemId) {
    DDON_STUB("cQuestDeliverManager::deleteDeliveredInfo")
    /* stub */
}

__attribute__((weak)) void cQuestDeliverManager::decideDeliverItem(nQuest::SCHEDULE_ID scheduleId, u32 itemId) {
    DDON_STUB("cQuestDeliverManager::decideDeliverItem")
    /* stub */
}

__attribute__((weak)) void cQuestDeliverManager::callbackLeaveParty() {
    DDON_STUB("cQuestDeliverManager::callbackLeaveParty")
    /* stub */
}

__attribute__((weak)) void cQuestDeliverManager::callbackLeaveParty(u32 characterId) {
    DDON_STUB("cQuestDeliverManager::callbackLeaveParty")
    /* stub */
}

void cQuestDeliverManager::callbackDeliverItem(void* pParam) {
    mIsReqDeliverItem = false;
    if (mDeliverItemList.mLength != 0) {
        u32 v0_0 = mDeliverItemList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mDeliverItemList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mDeliverItemList.mpArray[i0_3];
                v1_0 = mDeliverItemList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mDeliverItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDeliverItemList.mpArray));
    }
    mDeliverItemList.mpArray = nullptr;
    mDeliverItemList.mBufsiz = 0;
    mDeliverItemList.mLength = 0;
}

__attribute__((weak)) void cQuestDeliverManager::callbackDecideDeliveryItem(void* pPacket) {
    DDON_STUB("cQuestDeliverManager::callbackDecideDeliveryItem")
    /* stub */
}

cQuestDeliverManager::cQuestDeliverManager() {
    mIsReqDeliverItem = false;
    cQuestSvNoticeManager::addCallbackFunc(cQuestSvNoticeCallback::DTI, cQuestSvNotDecideDeliveryItem::DTI)->cQuestSvNoticeCallback::setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvNoticeCallback::PCallbackFunc>(&::cQuestDeliverManager::callbackDecideDeliveryItem));
}

__attribute__((noinline)) cQuestDeliverManager::~cQuestDeliverManager() {
    if (mDeliverItemList.mLength != 0) {
        u32 v0_0 = mDeliverItemList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mDeliverItemList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mDeliverItemList.mpArray[i0_3];
                v1_0 = mDeliverItemList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mDeliverItemList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDeliverItemList.mpArray));
    }
    mDeliverItemList.mpArray = nullptr;
    mDeliverItemList.mBufsiz = 0;
    mDeliverItemList.mLength = 0;
    if (mDeliverInfo.mLength != 0) {
        u32 v3_0 = mDeliverInfo.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mDeliverInfo.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mDeliverInfo.mpArray[i3_3];
                v4_0 = mDeliverInfo.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mDeliverInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDeliverInfo.mpArray));
    }
    mDeliverInfo.mpArray = nullptr;
    mDeliverInfo.mBufsiz = 0;
    mDeliverInfo.mLength = 0;
}

__attribute__((weak)) void cQuestDeliverManager::createProperty(MtPropertyList& s) {
}

inline cQuestDeliverManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestDeliverManager::MyDTI cQuestDeliverManager::DTI("cQuestDeliverManager", &::cQuestFunctionManagerBase::DTI, 80ul, 0u, 0u);

MtObject* cQuestDeliverManager::MyDTI::newInstance() const {
    return new (16u) cQuestDeliverManager;
}

template MtTypedArray<nQuest::cQuestDeliveredInfo>::~MtTypedArray();

