// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "nQuest.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "Protocol/PacketData/Quest.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cCycleQuestManagerBase.h"
#include "cLightQuestManager.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "cQuestMemoryPool.h"
#include "cQuestTask.h"
#include "nDDOUtility.h"
#include "nHumanMsg.h"
#include "nJobParam.h"
#include "nMarker.h"
#include "../../XFramework/rGUIMessage.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sNpcManager.h"
#include "sQuestManagerExt.h"
#include "uGUIQueueAnnounce.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

namespace nQuest {
const nQuest::SCHEDULE_ID INVALID_SCHEDULE_ID;
}

namespace nQuest {
const nQuest::QUEST_ID INVALID_QUEST_ID;
}

__attribute__((weak)) bool nQuest::isDisableOrderCondition(u32 result, nQuest::ORDER_CONDITION_TYPE checkType) {
    DDON_STUB("nQuest::isDisableOrderCondition")
    return {};
}

bool nQuest::isPartyQuest(nQuest::QUEST_TYPE questType) {
    static const nQuest::QUEST_TYPE PARTY_QUEST_TABLE[5] = {
        static_cast<const nQuest::QUEST_TYPE>(0),
        static_cast<const nQuest::QUEST_TYPE>(1),
        static_cast<const nQuest::QUEST_TYPE>(6),
        static_cast<const nQuest::QUEST_TYPE>(7),
        static_cast<const nQuest::QUEST_TYPE>(8),
    };
    u32 i = 0;
    const nQuest::QUEST_TYPE* p2 = PARTY_QUEST_TABLE;
    do {
        if ((*p2) == questType) {
            return true;
        }
        i += 1u;
        p2 += static_cast<int>(1);
    } while (i <= 4u);
    return false;
}

bool nQuest::isSoloQuest(nQuest::QUEST_TYPE questType) {
    static const nQuest::QUEST_TYPE SOLO_QUEST_TABLE[4] = {
        static_cast<const nQuest::QUEST_TYPE>(2),
        static_cast<const nQuest::QUEST_TYPE>(3),
        static_cast<const nQuest::QUEST_TYPE>(4),
        static_cast<const nQuest::QUEST_TYPE>(10),
    };
    u32 i = 0;
    const nQuest::QUEST_TYPE* p2 = SOLO_QUEST_TABLE;
    do {
        if ((*p2) == questType) {
            return true;
        }
        i += 1u;
        p2 += static_cast<int>(1);
    } while (i <= 3u);
    return false;
}

bool nQuest::isCycleContents(nQuest::QUEST_TYPE questType) {
    u32 i = 0;
    const nQuest::QUEST_TYPE* p2 = nQuest::cycleContentTypeTbl;
    do {
        if ((*p2) == questType) {
            return true;
        }
        i += 1u;
        p2 += static_cast<int>(1);
    } while (i <= 1u);
    return false;
}

bool nQuest::isContents(nQuest::QUEST_TYPE questType) {
    static const nQuest::QUEST_TYPE CONTENTS_TABLE[3] = {
        static_cast<const nQuest::QUEST_TYPE>(6),
        static_cast<const nQuest::QUEST_TYPE>(7),
        static_cast<const nQuest::QUEST_TYPE>(8),
    };
    u32 i = 0;
    const nQuest::QUEST_TYPE* p2 = CONTENTS_TABLE;
    do {
        if ((*p2) == questType) {
            return true;
        }
        i += 1u;
        p2 += static_cast<int>(1);
    } while (i <= 2u);
    return false;
}

bool nQuest::isQuestListSet(nQuest::QUEST_TYPE questType) {
    static const nQuest::QUEST_TYPE QUEST_LIST_SET_TABLE[8] = {
        static_cast<const nQuest::QUEST_TYPE>(0),
        static_cast<const nQuest::QUEST_TYPE>(1),
        static_cast<const nQuest::QUEST_TYPE>(3),
        static_cast<const nQuest::QUEST_TYPE>(4),
        static_cast<const nQuest::QUEST_TYPE>(5),
        static_cast<const nQuest::QUEST_TYPE>(6),
        static_cast<const nQuest::QUEST_TYPE>(7),
        static_cast<const nQuest::QUEST_TYPE>(8),
    };
    u32 i = 0;
    const nQuest::QUEST_TYPE* p2 = QUEST_LIST_SET_TABLE;
    do {
        if ((*p2) == questType) {
            return true;
        }
        i += 1u;
        p2 += static_cast<int>(1);
    } while (i <= 7u);
    return false;
}

u32 nQuest::getGUIQuestAnnounceTYPE(nQuest::QUEST_TYPE questType) {
    static const uGUIQueueAnnounce::TYPE TYPE_TABLE[12] = {
        static_cast<const uGUIQueueAnnounce::TYPE>(0),
        static_cast<const uGUIQueueAnnounce::TYPE>(1),
        static_cast<const uGUIQueueAnnounce::TYPE>(2),
        static_cast<const uGUIQueueAnnounce::TYPE>(6),
        static_cast<const uGUIQueueAnnounce::TYPE>(3),
        static_cast<const uGUIQueueAnnounce::TYPE>(0),
        static_cast<const uGUIQueueAnnounce::TYPE>(4),
        static_cast<const uGUIQueueAnnounce::TYPE>(4),
        static_cast<const uGUIQueueAnnounce::TYPE>(5),
        static_cast<const uGUIQueueAnnounce::TYPE>(4),
        static_cast<const uGUIQueueAnnounce::TYPE>(6),
        static_cast<const uGUIQueueAnnounce::TYPE>(0),
    };
    if (static_cast<unsigned int>(questType) <= 11) {
        return static_cast<u32>(TYPE_TABLE[questType]);
    } else {
        return 0;
    }
}

__attribute__((weak)) nQuest::QUEST_UI_DISP_TYPE nQuest::getQuestLogDispType(nQuest::QUEST_TYPE questType) {
    DDON_STUB("nQuest::getQuestLogDispType")
    return {};
}

__attribute__((weak)) nQuest::QUEST_TYPE nQuest::getQuestType(nQuest::QUEST_UI_DISP_TYPE questUIDispType) {
    DDON_STUB("nQuest::getQuestType")
    return {};
}

u32 nQuest::getUseOrderConditionTagNum(u32 orderConditionType) {
    static const u32 useOrderConditionTagNum[15] = {
        0,
        1,
        2,
        0,
        0,
        0,
        1,
        1,
        1,
        2,
        0,
        0,
        0,
        0,
        0,
    };
    if (orderConditionType <= 14u) {
        return useOrderConditionTagNum[orderConditionType];
    } else {
        return 0;
    }
}

bool nQuest::isCyclePhaseQuest(nQuest::CYCLE_CONTENTS_NOTICE_TYPE type) {
    static const nQuest::CYCLE_CONTENTS_NOTICE_TYPE list[5] = {
        static_cast<const nQuest::CYCLE_CONTENTS_NOTICE_TYPE>(1),
        static_cast<const nQuest::CYCLE_CONTENTS_NOTICE_TYPE>(2),
        static_cast<const nQuest::CYCLE_CONTENTS_NOTICE_TYPE>(3),
        static_cast<const nQuest::CYCLE_CONTENTS_NOTICE_TYPE>(4),
        static_cast<const nQuest::CYCLE_CONTENTS_NOTICE_TYPE>(5),
    };
    u32 i = 0;
    const nQuest::CYCLE_CONTENTS_NOTICE_TYPE* p2 = list;
    do {
        if ((*p2) == type) {
            return true;
        }
        i += 1u;
        p2 += static_cast<int>(1);
    } while (i <= 4u);
    return false;
}

__attribute__((weak)) nQuest::CYCLE_CONTENTS_CATEGORY nQuest::getCycleContentsCategory(nQuest::CYCLE_CONTENTS_TYPE cycleContentsType) {
    DDON_STUB("nQuest::getCycleContentsCategory")
    return {};
}

__attribute__((weak)) nQuest::CYCLE_CONTENTS_SUB_CATEGORY nQuest::getCycleContentsSubCategory(nQuest::CYCLE_CONTENTS_TYPE cycleContentsType) {
    DDON_STUB("nQuest::getCycleContentsSubCategory")
    return {};
}

__attribute__((weak)) u32 nQuest::getQuestDispPriority(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("nQuest::getQuestDispPriority")
    return {};
}

__attribute__((weak)) nQuest::RET_DISABLE_ORDER_CONDITION_TYPE nQuest::getEnableOrderList(const nQuest::OrderConditionArray& orderConditionList) {
    DDON_STUB("nQuest::getEnableOrderList")
    return {};
}

__attribute__((weak)) nQuest::RET_DISABLE_ORDER_CONDITION_TYPE nQuest::getEnableOrderList(const nQuest::OrderConditionArray& orderConditionList, const cContextInstHm* pCtxt) {
    DDON_STUB("nQuest::getEnableOrderList")
    return {};
}

__attribute__((weak)) bool nQuest::isDispActiveQuest(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("nQuest::isDispActiveQuest")
    return {};
}

nQuest::SCHEDULE_ID::operator unsigned int() const {
    return mScheduleId;
}

bool nQuest::SCHEDULE_ID::operator==(nQuest::SCHEDULE_ID id) const {
    return mScheduleId == id.mScheduleId;
}

bool nQuest::SCHEDULE_ID::operator!=(nQuest::SCHEDULE_ID id) const {
    return mScheduleId != id.mScheduleId;
}

u32 nQuest::SCHEDULE_ID::toU32() const {
    return mScheduleId;
}

nQuest::SCHEDULE_ID::SCHEDULE_ID() {
    mScheduleId = 0;
}

nQuest::SCHEDULE_ID::SCHEDULE_ID(u32 scheduleId) {
    mScheduleId = scheduleId;
}

nQuest::SCHEDULE_ID::~SCHEDULE_ID() {
}

__attribute__((weak)) void nQuest::SCHEDULE_ID::createProperty(MtPropertyList& s) {
}

nQuest::QUEST_ID::operator unsigned int() const {
    return mQuestId;
}

bool nQuest::QUEST_ID::operator==(nQuest::QUEST_ID id) const {
    return mQuestId == id.mQuestId;
}

bool nQuest::QUEST_ID::operator!=(nQuest::QUEST_ID id) const {
    return mQuestId != id.mQuestId;
}

u32 nQuest::QUEST_ID::toU32() const {
    return mQuestId;
}

nQuest::QUEST_ID::QUEST_ID() {
    mQuestId = 0;
}

nQuest::QUEST_ID::QUEST_ID(u32 questId) {
    mQuestId = questId;
}

nQuest::QUEST_ID::~QUEST_ID() {
}

__attribute__((weak)) void nQuest::QUEST_ID::createProperty(MtPropertyList& s) {
}

const MtDTI& nQuest::cQuestInfoBase::getDTI() const {
    return nQuest::cQuestInfoBase::DTI;
}

inline nQuest::cQuestInfoBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cQuestInfoBase::MyDTI nQuest::cQuestInfoBase::DTI("nQuest::cQuestInfoBase", &::MtObject::DTI, 8ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cQuestInfoBase::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cQuestInfoBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cOrderCondition::getDTI() const {
    return nQuest::cOrderCondition::DTI;
}

void* nQuest::cOrderCondition::operator new(size_t sz, u32 align) {
    return ::nQuest::cOrderCondition::getAllocator()->memAlloc(sz, align, ::nQuest::cOrderCondition::DTI.getID());
}

nQuest::ORDER_CONDITION_TYPE nQuest::cOrderCondition::getConditionType() const {
    return static_cast<nQuest::ORDER_CONDITION_TYPE>(mConditionType);
}

MT_CTSTR nQuest::cOrderCondition::getConditionParam1Message() const {
    return mConditionParam1Message.ptr();
}

MT_CTSTR nQuest::cOrderCondition::getConditionParam2Message() const {
    return mConditionParam2Message.ptr();
}

nQuest::cOrderCondition::cOrderCondition(u8 type, u32 param1, u32 param2) {
    DDON_STUB("nQuest::cOrderCondition::cOrderCondition")
    /* stub */
}

nQuest::cOrderCondition::~cOrderCondition() {
}

__attribute__((weak)) void nQuest::cOrderCondition::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void nQuest::cOrderCondition::updateConditionMessage() {
    DDON_STUB("nQuest::cOrderCondition::updateConditionMessage")
    /* stub */
}

__attribute__((weak)) bool nQuest::cOrderCondition::loadConditionInfo() {
    DDON_STUB("nQuest::cOrderCondition::loadConditionInfo")
    return {};
}

inline nQuest::cOrderCondition::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cOrderCondition::MyDTI nQuest::cOrderCondition::DTI("nQuest::cOrderCondition", &::nQuest::cQuestInfoBase::DTI, 40ul, 0u, 0u);

MtObject* nQuest::cOrderCondition::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cOrderCondition;
}

const MtDTI& nQuest::cRepeatBonus::getDTI() const {
    return nQuest::cRepeatBonus::DTI;
}

nQuest::cRepeatBonus::cRepeatBonus() {
    mType = 0;
    mParam = 0;
    mNum = 0;
}

nQuest::cRepeatBonus::~cRepeatBonus() {
}

__attribute__((weak)) void nQuest::cRepeatBonus::createProperty(MtPropertyList& s) {
}

inline nQuest::cRepeatBonus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cRepeatBonus::MyDTI nQuest::cRepeatBonus::DTI("nQuest::cRepeatBonus", &::nQuest::cQuestInfoBase::DTI, 24ul, 0u, 0u);

MtObject* nQuest::cRepeatBonus::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cRepeatBonus;
}

const MtDTI& nQuest::cRewardData::getDTI() const {
    return nQuest::cRewardData::DTI;
}

u32 nQuest::cRewardData::getItemId() const {
    return mItemId;
}

nQuest::cRewardData& nQuest::cRewardData::setItemId(u32 itemId) {
    mItemId = itemId;
    return *this;
}

u32 nQuest::cRewardData::getItemNum() const {
    return mItemNum;
}

nQuest::cRewardData& nQuest::cRewardData::setItemNum(u32 itemNum) {
    mItemNum = itemNum;
    return *this;
}

nQuest::cRewardData::cRewardData() {
    mItemId = 0;
    mItemNum = 0;
}

nQuest::cRewardData::cRewardData(u32 itemId, u32 itemNum) {
    mItemId = itemId;
    mItemNum = itemNum;
}

nQuest::cRewardData::~cRewardData() {
}

__attribute__((weak)) void nQuest::cRewardData::createProperty(MtPropertyList& s) {
}

inline nQuest::cRewardData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cRewardData::MyDTI nQuest::cRewardData::DTI("nQuest::cRewardData", &::nQuest::cQuestInfoBase::DTI, 16ul, 0u, 0u);

MtObject* nQuest::cRewardData::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cRewardData;
}

const MtDTI& nQuest::cFixRewardData::getDTI() const {
    return nQuest::cFixRewardData::DTI;
}

u32 nQuest::cFixRewardData::getItemId(u32 idx) const {
    if (idx <= 4u) {
        return mRewardData[idx].mItemId;
    } else {
        return 0;
    }
}

u32 nQuest::cFixRewardData::getItemNum(u32 idx) const {
    if (idx <= 4u) {
        return mRewardData[idx].mItemNum;
    } else {
        return 0;
    }
}

__attribute__((weak)) nQuest::cFixRewardData& nQuest::cFixRewardData::setRewardData(u32 idx, const nQuest::cRewardData& rewardData) {
    DDON_STUB("nQuest::cFixRewardData::setRewardData")
    __builtin_unreachable();
}

nQuest::cFixRewardData::cFixRewardData() {
    DDON_STUB("nQuest::cFixRewardData::cFixRewardData")
    /* stub */
}

nQuest::cFixRewardData::~cFixRewardData() {
}

__attribute__((weak)) void nQuest::cFixRewardData::createProperty(MtPropertyList& s) {
}

inline nQuest::cFixRewardData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cFixRewardData::MyDTI nQuest::cFixRewardData::DTI("nQuest::cFixRewardData", &::nQuest::cQuestInfoBase::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cFixRewardData::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cFixRewardData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cDeliverRequestItemInfo::getDTI() const {
    return nQuest::cDeliverRequestItemInfo::DTI;
}

void* nQuest::cDeliverRequestItemInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cDeliverRequestItemInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cDeliverRequestItemInfo::DTI.getID());
}

nQuest::cDeliverRequestItemInfo::cDeliverRequestItemInfo() {
    mItemId = 0;
    mNeedItemNum = 0;
}

__attribute__((weak)) void nQuest::cDeliverRequestItemInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cDeliverRequestItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cDeliverRequestItemInfo::MyDTI nQuest::cDeliverRequestItemInfo::DTI("nQuest::cDeliverRequestItemInfo", &::nQuest::cQuestInfoBase::DTI, 16ul, 0u, 0u);

MtObject* nQuest::cDeliverRequestItemInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cDeliverRequestItemInfo;
}

const MtDTI& nQuest::cQuestDeliverRequestInfo::getDTI() const {
    return nQuest::cQuestDeliverRequestInfo::DTI;
}

void* nQuest::cQuestDeliverRequestInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cQuestDeliverRequestInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cQuestDeliverRequestInfo::DTI.getID());
}

nQuest::cQuestDeliverRequestInfo::cQuestDeliverRequestInfo() {
    DDON_STUB("nQuest::cQuestDeliverRequestInfo::cQuestDeliverRequestInfo")
    /* stub */
}

nQuest::cQuestDeliverRequestInfo::cQuestDeliverRequestInfo(const nQuest::cQuestDeliverRequestInfo& obj) {
    DDON_STUB("nQuest::cQuestDeliverRequestInfo::cQuestDeliverRequestInfo")
    /* stub */
}

nQuest::cQuestDeliverRequestInfo::~cQuestDeliverRequestInfo() {
    DDON_STUB("nQuest::cQuestDeliverRequestInfo::~cQuestDeliverRequestInfo")
    /* stub */
}

__attribute__((weak)) void nQuest::cQuestDeliverRequestInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cQuestDeliverRequestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cQuestDeliverRequestInfo::MyDTI nQuest::cQuestDeliverRequestInfo::DTI("nQuest::cQuestDeliverRequestInfo", &::nQuest::cQuestInfoBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cQuestDeliverRequestInfo::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cQuestDeliverRequestInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cDeliveredItemInfo::getDTI() const {
    return nQuest::cDeliveredItemInfo::DTI;
}

void* nQuest::cDeliveredItemInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cDeliveredItemInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cDeliveredItemInfo::DTI.getID());
}

nQuest::cDeliveredItemInfo::cDeliveredItemInfo() : mItemId(0u), mNeedItemNum(static_cast<u16>(0)), mType(static_cast<u8>(1)) {
    mCharacterDeliverInfo.mAutoDelete = true;
}

nQuest::cDeliveredItemInfo::~cDeliveredItemInfo() {
    if (mCharacterDeliverInfo.mLength != 0) {
        u32 v0_0 = mCharacterDeliverInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCharacterDeliverInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mCharacterDeliverInfo.mpArray[i0_3];
                v1_0 = mCharacterDeliverInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCharacterDeliverInfo.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mCharacterDeliverInfo.mpArray));
    }
    mCharacterDeliverInfo.mpArray = nullptr;
    mCharacterDeliverInfo.mBufsiz = 0;
    mCharacterDeliverInfo.mLength = 0;
}

__attribute__((weak)) void nQuest::cDeliveredItemInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cDeliveredItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cDeliveredItemInfo::MyDTI nQuest::cDeliveredItemInfo::DTI("nQuest::cDeliveredItemInfo", &::nQuest::cQuestInfoBase::DTI, 48ul, 0u, 0u);

MtObject* nQuest::cDeliveredItemInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cDeliveredItemInfo;
}

const MtDTI& nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::getDTI() const {
    return nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::DTI;
}

void* nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::DTI.getID());
}

__attribute__((weak)) void nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::operator delete(void* p_addr) {
    ::nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::getAllocator()->memFree(p_addr);
}

void nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mCharacterId", &mCharacterId, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mItemNum", &mItemNum, 0u, 0u);
}

inline nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::MyDTI nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::DTI("nQuest::cDeliveredItemInfo::cDeliverCharacterInfo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cDeliveredItemInfo::cDeliverCharacterInfo;
}

const MtDTI& nQuest::cQuestDeliveredInfo::getDTI() const {
    return nQuest::cQuestDeliveredInfo::DTI;
}

void* nQuest::cQuestDeliveredInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cQuestDeliveredInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cQuestDeliveredInfo::DTI.getID());
}

nQuest::cQuestDeliveredInfo::cQuestDeliveredInfo() {
    DDON_STUB("nQuest::cQuestDeliveredInfo::cQuestDeliveredInfo")
    /* stub */
}

nQuest::cQuestDeliveredInfo::~cQuestDeliveredInfo() {
    DDON_STUB("nQuest::cQuestDeliveredInfo::~cQuestDeliveredInfo")
    /* stub */
}

__attribute__((weak)) void nQuest::cQuestDeliveredInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cQuestDeliveredInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cQuestDeliveredInfo::MyDTI nQuest::cQuestDeliveredInfo::DTI("nQuest::cQuestDeliveredInfo", &::nQuest::cQuestInfoBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cQuestDeliveredInfo::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cQuestDeliveredInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cQuestMarker::getDTI() const {
    return nQuest::cQuestMarker::DTI;
}

void* nQuest::cQuestMarker::operator new(size_t sz, u32 align) {
    return ::nQuest::cQuestMarker::getAllocator()->memAlloc(sz, align, ::nQuest::cQuestMarker::DTI.getID());
}

const nMarker::cMarkerInfo& nQuest::cQuestMarker::getMarkerInfo() const {
    return mMarkerInfo;
}

const nMarker::cMarkerInfo* nQuest::cQuestMarker::getMarkerInfoPtr() const {
    return &mMarkerInfo;
}

void nQuest::cQuestMarker::setPosition(const MtVector3& pos) {
    if (mMarkerInfo.getPosList().mLength != 0) {
        mMarkerInfo.setPosition(0u, pos);
    } else {
        mMarkerInfo.addPosition(pos);
    }
}

bool nQuest::cQuestMarker::isActive() const {
    return mIsActive;
}

void nQuest::cQuestMarker::setActive(bool active) {
    mIsActive = active;
}

u32 nQuest::cQuestMarker::getQuestIdU32() const {
    return mQuestId.mQuestId;
}

void nQuest::cQuestMarker::setQuestId(nQuest::QUEST_ID questId) {
    mQuestId.mQuestId = questId.mQuestId;
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cQuestMarker::getScheduleId() const {
    DDON_STUB("nQuest::cQuestMarker::getScheduleId")
    __builtin_unreachable();
}

void nQuest::cQuestMarker::setScheduleId(nQuest::SCHEDULE_ID scheduleId) {
    mScheduleId.mScheduleId = scheduleId.mScheduleId;
}

u32 nQuest::cQuestMarker::getTargetType() const {
    return mTargetType;
}

void nQuest::cQuestMarker::setTargetType(u32 targetType) {
    mTargetType = static_cast<unsigned char>(targetType);
}

void nQuest::cQuestMarker::setIsOrder(bool isOrder) {
    mIsOrder = isOrder;
}

s32 nQuest::cQuestMarker::getStageNo() const {
    return mMarkerInfo.getStageNo();
}

void nQuest::cQuestMarker::setStageNo(s32 stageNo) {
    mMarkerInfo.setStageNo(static_cast<short>(stageNo));
}

u32 nQuest::cQuestMarker::getGroupNo() const {
    return mGroupNo;
}

void nQuest::cQuestMarker::setGroupNo(u32 groupNo) {
    mGroupNo = groupNo;
}

s16 nQuest::cQuestMarker::getMapGroupNo() const {
    return mMapGroupNo;
}

void nQuest::cQuestMarker::setMapGroupNo(s16 mapGroupNo) {
    mMapGroupNo = mapGroupNo;
}

__attribute__((weak)) void nQuest::cQuestMarker::setQuestType(nQuest::QUEST_TYPE questType) {
    DDON_STUB("nQuest::cQuestMarker::setQuestType")
    /* stub */
}

nQuest::cQuestMarker::cQuestMarker() {
    DDON_STUB("nQuest::cQuestMarker::cQuestMarker")
    /* stub */
}

nQuest::cQuestMarker::~cQuestMarker() {
    DDON_STUB("nQuest::cQuestMarker::~cQuestMarker")
    /* stub */
}

void nQuest::cQuestMarker::createProperty(MtPropertyList& s) {
    mMarkerInfo.::nMarker::cMarkerInfo::createProperty(s);
}

MtUI* nQuest::cQuestMarker::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

inline nQuest::cQuestMarker::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cQuestMarker::MyDTI nQuest::cQuestMarker::DTI("nQuest::cQuestMarker", &::nQuest::cQuestInfoBase::DTI, 136ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cQuestMarker::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cQuestMarker::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cCycleContentsPersonalRankInfo::getDTI() const {
    return nQuest::cCycleContentsPersonalRankInfo::DTI;
}

void* nQuest::cCycleContentsPersonalRankInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cCycleContentsPersonalRankInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cCycleContentsPersonalRankInfo::DTI.getID());
}

__attribute__((weak)) void nQuest::cCycleContentsPersonalRankInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cCycleContentsPersonalRankInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cCycleContentsPersonalRankInfo::MyDTI nQuest::cCycleContentsPersonalRankInfo::DTI("nQuest::cCycleContentsPersonalRankInfo", &::nQuest::cQuestInfoBase::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cCycleContentsPersonalRankInfo::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cCycleContentsPersonalRankInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cCycleContentsInfo::getDTI() const {
    return nQuest::cCycleContentsInfo::DTI;
}

void* nQuest::cCycleContentsInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cCycleContentsInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cCycleContentsInfo::DTI.getID());
}

MT_CTSTR nQuest::cCycleContentsInfo::getContentsName() const {
    return ::sQuestManagerExt::getInstance()->getCycleContentsName(static_cast<nQuest::CYCLE_CONTENTS_CATEGORY>(mCycleContentsCategory), static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mCycleContentsSubCategory));
}

bool nQuest::cCycleContentsInfo::isPlayContents() const {
    return mPlayNum != 0;
}

u32 nQuest::cCycleContentsInfo::getRanking() const {
    if (mContentsRank.mLength != 0) {
        u32 i = 0;
        do {
            if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mContentsRank.mpArray[i]) + 8)) == 1) {
                return static_cast<nQuest::cCycleContentsPersonalRankInfo*>(mContentsRank.mpArray[i])->getRanking();
            }
            i += 1u;
        } while (i < mContentsRank.mLength);
    }
    return 0;
}

u32 nQuest::cCycleContentsInfo::getPoint() const {
    return mTotalPoint;
}

u32 nQuest::cCycleContentsInfo::getRankPoint() const {
    if (mContentsRank.mLength != 0) {
        u32 i = 0;
        do {
            if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mContentsRank.mpArray[i]) + 8)) == 1) {
                return static_cast<nQuest::cCycleContentsPersonalRankInfo*>(mContentsRank.mpArray[i])->getScore();
            }
            i += 1u;
        } while (i < mContentsRank.mLength);
    }
    return 0;
}

MT_CTSTR nQuest::cCycleContentsInfo::getContentsInfo() const {
    return ::sQuestManagerExt::getInstance()->getCycleContentsInfo(static_cast<nQuest::CYCLE_CONTENTS_CATEGORY>(mCycleContentsCategory), static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mCycleContentsSubCategory));
}

MT_CTSTR nQuest::cCycleContentsInfo::getOrderPlace() const {
    return ::sQuestManagerExt::getInstance()->getCycleContentsOrderPlace(static_cast<nQuest::CYCLE_CONTENTS_CATEGORY>(mCycleContentsCategory), static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mCycleContentsSubCategory));
}

MT_CTSTR nQuest::cCycleContentsInfo::getPhaseName() const {
    return ::sQuestManagerExt::getInstance()->getCycleContentsSituationName(static_cast<nQuest::CYCLE_CONTENTS_CATEGORY>(mCycleContentsCategory), static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mCycleContentsSubCategory), mPeriod, getSituation());
}

MT_CTSTR nQuest::cCycleContentsInfo::getPhaseInfo() const {
    return ::sQuestManagerExt::getInstance()->getCycleContentsSituationInfo(static_cast<nQuest::CYCLE_CONTENTS_CATEGORY>(mCycleContentsCategory), static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mCycleContentsSubCategory), mPeriod, getSituation());
}

u32 nQuest::cCycleContentsInfo::getPhaseImageResId() const {
    if (mPeriod == 2) {
        return getSituation() + 5u;
    } else {
        return mPeriod;
    }
}

const MtTime& nQuest::cCycleContentsInfo::getStartTime() const {
    return mStartTime;
}

const MtTime& nQuest::cCycleContentsInfo::getEndTime() const {
    return mEndTime;
}

__attribute__((weak)) bool nQuest::cCycleContentsInfo::getRankingListUpdateTime(MtTime* time) const {
    DDON_STUB("nQuest::cCycleContentsInfo::getRankingListUpdateTime")
    return {};
}

u32 nQuest::cCycleContentsInfo::getRewardItem(u32 idx) const {
    if (idx <= 4u) {
        return mRewardItem[idx];
    } else {
        return 0;
    }
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cCycleContentsInfo::getRankingScheduleId() const {
    DDON_STUB("nQuest::cCycleContentsInfo::getRankingScheduleId")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cCycleContentsInfo::getCycleContentsScheduleId() const {
    DDON_STUB("nQuest::cCycleContentsInfo::getCycleContentsScheduleId")
    __builtin_unreachable();
}

nQuest::CYCLE_CONTENTS_PERIOD nQuest::cCycleContentsInfo::getCycleContentsPeriod() const {
    return static_cast<nQuest::CYCLE_CONTENTS_PERIOD>(mPeriod);
}

nQuest::CYCLE_CONTENTS_PERIOD nQuest::cCycleContentsInfo::getCycleContentsPeriodRealTime() const {
    cCycleQuestManagerBase* pMgr = ::sQuestManagerExt::getInstance()->getCycleContentsMgr(static_cast<nQuest::CYCLE_CONTENTS_CATEGORY>(mCycleContentsCategory), static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mCycleContentsSubCategory));
    if (pMgr != nullptr) {
        return pMgr->getCycleContentsPeriodFromSubCategory(static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mCycleContentsSubCategory));
    } else {
        return ::nQuest::CYCLE_CONTENTS_PERIOD_NONE;
    }
}

u32 nQuest::cCycleContentsInfo::getItemRankAvg() const {
    return mItemRankAvg;
}

nQuest::cCycleContentsInfo::cCycleContentsInfo() {
    DDON_STUB("nQuest::cCycleContentsInfo::cCycleContentsInfo")
    /* stub */
}

nQuest::cCycleContentsInfo::~cCycleContentsInfo() {
}

__attribute__((weak)) void nQuest::cCycleContentsInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cCycleContentsInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cCycleContentsInfo::MyDTI nQuest::cCycleContentsInfo::DTI("nQuest::cCycleContentsInfo", &::nQuest::cQuestInfoBase::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cCycleContentsInfo::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cCycleContentsInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cGUINewspaperSetQuestMonsterInfo::getDTI() const {
    return nQuest::cGUINewspaperSetQuestMonsterInfo::DTI;
}

void* nQuest::cGUINewspaperSetQuestMonsterInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUINewspaperSetQuestMonsterInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cGUINewspaperSetQuestMonsterInfo::DTI.getID());
}

nQuest::cGUINewspaperSetQuestMonsterInfo::cGUINewspaperSetQuestMonsterInfo(u32 lv, u32 id, bool isParty) {
    mEnemyLv = lv;
    mEnemyGroupId = id;
    mIsPartyRecommanded = isParty;
}

inline nQuest::cGUINewspaperSetQuestMonsterInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUINewspaperSetQuestMonsterInfo::MyDTI nQuest::cGUINewspaperSetQuestMonsterInfo::DTI("nQuest::cGUINewspaperSetQuestMonsterInfo", &::nQuest::cQuestInfoBase::DTI, 24ul, 0u, 0u);

MtObject* nQuest::cGUINewspaperSetQuestMonsterInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cGUINewspaperSetQuestMonsterInfo;
}

const MtDTI& nQuest::cGUINewspaperSetQuestItemInfo::getDTI() const {
    return nQuest::cGUINewspaperSetQuestItemInfo::DTI;
}

void* nQuest::cGUINewspaperSetQuestItemInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUINewspaperSetQuestItemInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cGUINewspaperSetQuestItemInfo::DTI.getID());
}

nQuest::cGUINewspaperSetQuestItemInfo::cGUINewspaperSetQuestItemInfo(u32 id, u32 num) {
    mItemId = id;
    mItemNum = num;
}

inline nQuest::cGUINewspaperSetQuestItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUINewspaperSetQuestItemInfo::MyDTI nQuest::cGUINewspaperSetQuestItemInfo::DTI("nQuest::cGUINewspaperSetQuestItemInfo", &::nQuest::cQuestInfoBase::DTI, 16ul, 0u, 0u);

MtObject* nQuest::cGUINewspaperSetQuestItemInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cGUINewspaperSetQuestItemInfo;
}

const MtDTI& nQuest::cGUINewspaperSetQuestInfo::getDTI() const {
    return nQuest::cGUINewspaperSetQuestInfo::DTI;
}

void* nQuest::cGUINewspaperSetQuestInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUINewspaperSetQuestInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cGUINewspaperSetQuestInfo::DTI.getID());
}

__attribute__((weak)) nQuest::QUEST_ID nQuest::cGUINewspaperSetQuestInfo::getQuestId() const {
    DDON_STUB("nQuest::cGUINewspaperSetQuestInfo::getQuestId")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cGUINewspaperSetQuestInfo::getScheduleId() const {
    DDON_STUB("nQuest::cGUINewspaperSetQuestInfo::getScheduleId")
    __builtin_unreachable();
}

MT_CTSTR nQuest::cGUINewspaperSetQuestInfo::getQuestName() const {
    if (mQuestId.mQuestId != 0) {
        if (!::sQuestManagerExt::getInstance()->isMyOrderQuest(mScheduleId)) {
            if (!isDiscover() && (mCompleteNum == 0)) {
                return static_cast<sGUIExt*>(::sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(::sGUI::getInstance())->getMsgCommonMessage(), 110u);
            }
        }
        return ::sQuestManagerExt::getInstance()->getQuestName(mQuestId);
    } else {
        return "";
    }
}

MT_CTSTR nQuest::cGUINewspaperSetQuestInfo::getEyewitnessInfo() const {
    if (mQuestId.mQuestId != 0) {
        return ::sQuestManagerExt::getInstance()->getQuestFindInfo(mQuestId);
    } else {
        return "";
    }
}

u32 nQuest::cGUINewspaperSetQuestInfo::getSelectReward(u32 idx) const {
    if (idx <= 4u) {
        return mSelectReward[idx];
    } else {
        return 0;
    }
}

u32 nQuest::cGUINewspaperSetQuestInfo::getRandomRewardNum() const {
    return mRandomRewardNum;
}

u32 nQuest::cGUINewspaperSetQuestInfo::getDiscoverRewardItemId() const {
    return mDiscoverBonusItemId;
}

u32 nQuest::cGUINewspaperSetQuestInfo::getDiscoverBonusGold() const {
    return mDiscoverBonusGold;
}

u32 nQuest::cGUINewspaperSetQuestInfo::getDiscoverBonusRim() const {
    return mDiscoverBonusRim;
}

u32 nQuest::cGUINewspaperSetQuestInfo::getDiscoverBonusExp() const {
    return mDiscoverBonusExp;
}

const MtTime& nQuest::cGUINewspaperSetQuestInfo::getEndDistributionDate() const {
    return mEndDistributionDate;
}

u32 nQuest::cGUINewspaperSetQuestInfo::getBaseLevel() const {
    return mBaseLevel;
}

u32 nQuest::cGUINewspaperSetQuestInfo::getThumbnailResourceId() const {
    return mQuestThumbnailResourceId;
}

bool nQuest::cGUINewspaperSetQuestInfo::isDiscover() const {
    return mIsDiscovery;
}

bool nQuest::cGUINewspaperSetQuestInfo::isCleared() const {
    return mCompleteNum != 0;
}

bool nQuest::cGUINewspaperSetQuestInfo::isPartyBonus() const {
    return mIsPartyBonus;
}

bool nQuest::cGUINewspaperSetQuestInfo::isPopularQuickParty() const {
    return mQuickPartyPopularity != 0;
}

u32 nQuest::cGUINewspaperSetQuestInfo::getTargetEnemyListNum() const {
    return mTargetEnemyArray.mLength;
}

MT_CTSTR nQuest::cGUINewspaperSetQuestInfo::getTargetEnemyName(u32 idx) const {
    if (idx < mTargetEnemyArray.mLength) {
        return static_cast<sGUIExt*>(::sGUI::getInstance())->getEnemyNameFromGroupId(static_cast<nQuest::cGUINewspaperSetQuestMonsterInfo*>(mTargetEnemyArray.mpArray[idx])->getEnemyGroupId());
    } else {
        return "";
    }
}

u32 nQuest::cGUINewspaperSetQuestInfo::getTargetEnemyLv(u32 idx) const {
    if (idx < mTargetEnemyArray.mLength) {
        return static_cast<nQuest::cGUINewspaperSetQuestMonsterInfo*>(mTargetEnemyArray.mpArray[idx])->getEnemyLv();
    } else {
        return 0;
    }
}

bool nQuest::cGUINewspaperSetQuestInfo::hasEnemyInfo(u32 enemyGroupId, u32 enemyLv) const {
    const u32 emIdNum = mTargetEnemyArray.mLength;
    if (emIdNum != 0) {
        MtObject* * v0_4 = mTargetEnemyArray.mpArray;
        for (u32 i = 0;;) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4[i]) + 12)) == enemyGroupId) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4[i]) + 8)) == enemyLv) {
                    return true;
                }
            }
            if ((i + 1u) < emIdNum) {
                i = i + 1u;
            } else {
                break;
            }
        }
    }
    return false;
}

u32 nQuest::cGUINewspaperSetQuestInfo::getDeliveryItemListNum() const {
    return mDeliveryItemArray.mLength;
}

u32 nQuest::cGUINewspaperSetQuestInfo::getDeliveryItemId(u32 idx) const {
    if (idx < mDeliveryItemArray.mLength) {
        return static_cast<nQuest::cGUINewspaperSetQuestItemInfo*>(mDeliveryItemArray.mpArray[idx])->getItemId();
    } else {
        return 0;
    }
}

u32 nQuest::cGUINewspaperSetQuestInfo::getDeliveryItemNum(u32 idx) const {
    if (idx < mDeliveryItemArray.mLength) {
        return static_cast<nQuest::cGUINewspaperSetQuestItemInfo*>(mDeliveryItemArray.mpArray[idx])->getItemNum();
    } else {
        return 0;
    }
}

nQuest::cGUINewspaperSetQuestInfo::cGUINewspaperSetQuestInfo() {
    DDON_STUB("nQuest::cGUINewspaperSetQuestInfo::cGUINewspaperSetQuestInfo")
    /* stub */
}

__attribute__((noinline)) nQuest::cGUINewspaperSetQuestInfo::~cGUINewspaperSetQuestInfo() {
    DDON_STUB("nQuest::cGUINewspaperSetQuestInfo::~cGUINewspaperSetQuestInfo")
    /* stub */
}

__attribute__((weak)) void nQuest::cGUINewspaperSetQuestInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUINewspaperSetQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUINewspaperSetQuestInfo::MyDTI nQuest::cGUINewspaperSetQuestInfo::DTI("nQuest::cGUINewspaperSetQuestInfo", &::nQuest::cQuestInfoBase::DTI, 208ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cGUINewspaperSetQuestInfo::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cGUINewspaperSetQuestInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cGUINewspaperRecommededQuestInfo::getDTI() const {
    return nQuest::cGUINewspaperRecommededQuestInfo::DTI;
}

void* nQuest::cGUINewspaperRecommededQuestInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUINewspaperRecommededQuestInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cGUINewspaperRecommededQuestInfo::DTI.getID());
}

u32 nQuest::cGUINewspaperRecommededQuestInfo::getAreaId() const {
    return mAreaId;
}

nQuest::cGUINewspaperRecommededQuestInfo::cGUINewspaperRecommededQuestInfo() {
    DDON_STUB("nQuest::cGUINewspaperRecommededQuestInfo::cGUINewspaperRecommededQuestInfo")
    /* stub */
}

nQuest::cGUINewspaperRecommededQuestInfo::~cGUINewspaperRecommededQuestInfo() {
}

__attribute__((weak)) void nQuest::cGUINewspaperRecommededQuestInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUINewspaperRecommededQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUINewspaperRecommededQuestInfo::MyDTI nQuest::cGUINewspaperRecommededQuestInfo::DTI("nQuest::cGUINewspaperRecommededQuestInfo", &::nQuest::cGUINewspaperSetQuestInfo::DTI, 216ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cGUINewspaperRecommededQuestInfo::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cGUINewspaperRecommededQuestInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cGUINewspaperSetQuestOpenDateInfo::getDTI() const {
    return nQuest::cGUINewspaperSetQuestOpenDateInfo::DTI;
}

void* nQuest::cGUINewspaperSetQuestOpenDateInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUINewspaperSetQuestOpenDateInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cGUINewspaperSetQuestOpenDateInfo::DTI.getID());
}

bool nQuest::cGUINewspaperSetQuestOpenDateInfo::isDiscover() const {
    return true;
}

nQuest::cGUINewspaperSetQuestOpenDateInfo::cGUINewspaperSetQuestOpenDateInfo() {
    DDON_STUB("nQuest::cGUINewspaperSetQuestOpenDateInfo::cGUINewspaperSetQuestOpenDateInfo")
    /* stub */
}

nQuest::cGUINewspaperSetQuestOpenDateInfo::~cGUINewspaperSetQuestOpenDateInfo() {
}

__attribute__((weak)) void nQuest::cGUINewspaperSetQuestOpenDateInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUINewspaperSetQuestOpenDateInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUINewspaperSetQuestOpenDateInfo::MyDTI nQuest::cGUINewspaperSetQuestOpenDateInfo::DTI("nQuest::cGUINewspaperSetQuestOpenDateInfo", &::nQuest::cGUINewspaperSetQuestInfo::DTI, 224ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cGUINewspaperSetQuestOpenDateInfo::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cGUINewspaperSetQuestOpenDateInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cCycleContentsResultPointInfo::getDTI() const {
    return nQuest::cCycleContentsResultPointInfo::DTI;
}

__attribute__((weak)) nQuest::cCycleContentsResultPointInfo* nQuest::cCycleContentsResultPointInfo::newInstance(nQuest::cCycleContentsResultPointInfo::RESULT_POINT_TYPE type, u32 param01, u32 param02, u32 point) {
    DDON_STUB("nQuest::cCycleContentsResultPointInfo::newInstance")
    return nullptr;
}

nQuest::cCycleContentsResultPointInfo::RESULT_POINT_TYPE nQuest::cCycleContentsResultPointInfo::getType() const {
    return static_cast<nQuest::cCycleContentsResultPointInfo::RESULT_POINT_TYPE>(mType);
}

u32 nQuest::cCycleContentsResultPointInfo::getEnemyId() const {
    if (mType == 1) {
        return mParam01;
    } else {
        return 0;
    }
}

u32 nQuest::cCycleContentsResultPointInfo::getEnemyNum() const {
    if (mType == 1) {
        return mParam02;
    } else {
        return 0;
    }
}

u32 nQuest::cCycleContentsResultPointInfo::getExtraBonusNo() const {
    if (mType == 2) {
        return mParam01;
    } else {
        return 0;
    }
}

u32 nQuest::cCycleContentsResultPointInfo::getPoint() const {
    return mPoint;
}

nQuest::cCycleContentsResultPointInfo::~cCycleContentsResultPointInfo() {
}

__attribute__((weak)) void nQuest::cCycleContentsResultPointInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cCycleContentsResultPointInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cCycleContentsResultPointInfo::MyDTI nQuest::cCycleContentsResultPointInfo::DTI("nQuest::cCycleContentsResultPointInfo", &::nQuest::cQuestInfoBase::DTI, 24ul, 0u, 0u);

MtObject* nQuest::cCycleContentsResultPointInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cCycleContentsResultPointInfo;
}

const MtDTI& nQuest::cCycleContentsResultRewardInfo::getDTI() const {
    return nQuest::cCycleContentsResultRewardInfo::DTI;
}

__attribute__((weak)) nQuest::cCycleContentsResultRewardInfo* nQuest::cCycleContentsResultRewardInfo::newInstance(nQuest::cCycleContentsResultRewardInfo::RESULT_REWARD_TYPE type, u32 param01) {
    DDON_STUB("nQuest::cCycleContentsResultRewardInfo::newInstance")
    return nullptr;
}

__attribute__((weak)) nQuest::cCycleContentsResultRewardInfo* nQuest::cCycleContentsResultRewardInfo::newInstance(nQuest::cCycleContentsResultRewardInfo::RESULT_REWARD_TYPE type, u32 param01, u32 param02) {
    DDON_STUB("nQuest::cCycleContentsResultRewardInfo::newInstance")
    return nullptr;
}

nQuest::cCycleContentsResultRewardInfo::RESULT_REWARD_TYPE nQuest::cCycleContentsResultRewardInfo::getType() const {
    return static_cast<nQuest::cCycleContentsResultRewardInfo::RESULT_REWARD_TYPE>(mType);
}

u32 nQuest::cCycleContentsResultRewardInfo::getItemId() const {
    if (static_cast<unsigned int>(mType - 1) <= 1) {
        return mParam01;
    } else {
        return 0;
    }
}

u32 nQuest::cCycleContentsResultRewardInfo::getItemNum() const {
    if (static_cast<unsigned int>(mType - 1) <= 1) {
        return mParam02;
    } else {
        return 0;
    }
}

u32 nQuest::cCycleContentsResultRewardInfo::getGold() const {
    if (mType == 3) {
        return mParam01;
    } else {
        return 0;
    }
}

u32 nQuest::cCycleContentsResultRewardInfo::getRim() const {
    if (mType == 4) {
        return mParam01;
    } else {
        return 0;
    }
}

u32 nQuest::cCycleContentsResultRewardInfo::getJobPoint() const {
    if (mType != 5) {
        if (mType == 9) {
            return mParam01;
        } else {
            return 0;
        }
    } else {
        return mParam01;
    }
}

u32 nQuest::cCycleContentsResultRewardInfo::getExp() const {
    if (mType != 6) {
        if (mType == 10) {
            return mParam01;
        } else {
            return 0;
        }
    } else {
        return mParam01;
    }
}

u32 nQuest::cCycleContentsResultRewardInfo::getBloodOrb() const {
    if (mType == 7) {
        return mParam01;
    } else {
        return 0;
    }
}

u32 nQuest::cCycleContentsResultRewardInfo::getAbilityNo() const {
    if (mType == 8) {
        return mParam01;
    } else {
        return 0;
    }
}

nQuest::cCycleContentsResultRewardInfo::~cCycleContentsResultRewardInfo() {
}

__attribute__((weak)) void nQuest::cCycleContentsResultRewardInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cCycleContentsResultRewardInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cCycleContentsResultRewardInfo::MyDTI nQuest::cCycleContentsResultRewardInfo::DTI("nQuest::cCycleContentsResultRewardInfo", &::nQuest::cQuestInfoBase::DTI, 24ul, 0u, 0u);

MtObject* nQuest::cCycleContentsResultRewardInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cCycleContentsResultRewardInfo;
}

const MtDTI& nQuest::cCycleContentsResultInfo::getDTI() const {
    return nQuest::cCycleContentsResultInfo::DTI;
}

MT_CTSTR nQuest::cCycleContentsResultInfo::getSituationName() const {
    return ::sQuestManagerExt::getInstance()->getCycleContentsSituationNamePlayNow();
}

u32 nQuest::cCycleContentsResultInfo::getResultPoint() const {
    return mResultPoint;
}

u32 nQuest::cCycleContentsResultInfo::getResultBonusPoint() const {
    return mResultBonusPoint;
}

u32 nQuest::cCycleContentsResultInfo::getTechnicalScore() const {
    return mTechnicalScore;
}

u32 nQuest::cCycleContentsResultInfo::getBestTechnicalScore() const {
    return mBestTechnicalScore;
}

bool nQuest::cCycleContentsResultInfo::isNewRecord() const {
    return mIsNewRecord;
}

u32 nQuest::cCycleContentsResultInfo::getTechnicalScoreTimeBonus() const {
    return mTechnicalSocreTimeBonus;
}

u32 nQuest::cCycleContentsResultInfo::getClearTimeBonusRate() const {
    return mClearTimeBonusRate;
}

const nQuest::CycleContentsResultPointInfoArray& nQuest::cCycleContentsResultInfo::getPointList() const {
    return mPointList;
}

const nQuest::CycleContentsResultRewardList& nQuest::cCycleContentsResultInfo::getRewardItemIdList() const {
    return mRewardList;
}

bool nQuest::cCycleContentsResultInfo::hasRegionBreakReward() const {
    return mHasRegionBreakReward;
}

nQuest::cCycleContentsResultInfo::cCycleContentsResultInfo() {
    mIsCreateRanking = false;
    mHasRegionBreakReward = false;
    mIsNewRecord = false;
    mClearTimeBonusRate = 0;
    mTechnicalSocreTimeBonus = 0;
    mBestTechnicalScore = 0;
    mResultPointTotal = 0;
    mTechnicalScore = 0;
    mDieCount = 0;
    mPointDownRate = 0;
    mResultPoint = 0;
    mResultBonusPoint = 0;
}

__attribute__((noinline)) nQuest::cCycleContentsResultInfo::~cCycleContentsResultInfo() {
    if (mPointList.mLength != 0) {
        u32 v0_0 = mPointList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPointList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPointList.mpArray[i0_3];
                v1_0 = mPointList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPointList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mPointList.mpArray));
    }
    mPointList.mpArray = nullptr;
    mPointList.mBufsiz = 0;
    mPointList.mLength = 0;
    if (mRewardList.mLength != 0) {
        u32 v3_0 = mRewardList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mRewardList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mRewardList.mpArray[i3_3];
                v4_0 = mRewardList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mRewardList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mRewardList.mpArray));
    }
    mRewardList.mpArray = nullptr;
    mRewardList.mBufsiz = 0;
    mRewardList.mLength = 0;
}

__attribute__((weak)) void nQuest::cCycleContentsResultInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cCycleContentsResultInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cCycleContentsResultInfo::MyDTI nQuest::cCycleContentsResultInfo::DTI("nQuest::cCycleContentsResultInfo", &::nQuest::cQuestInfoBase::DTI, 112ul, 0u, 0u);

MtObject* nQuest::cCycleContentsResultInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cCycleContentsResultInfo;
}

const MtDTI& nQuest::cCycleContentsRankingInfo::getDTI() const {
    return nQuest::cCycleContentsRankingInfo::DTI;
}

__attribute__((weak)) nQuest::cCycleContentsRankingInfo* nQuest::cCycleContentsRankingInfo::newInstance(u32 rank, s64 point, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanName) {
    DDON_STUB("nQuest::cCycleContentsRankingInfo::newInstance")
    return nullptr;
}

MT_CTSTR nQuest::cCycleContentsRankingInfo::getFirstName() const {
    return mFirstName.ptr();
}

MT_CTSTR nQuest::cCycleContentsRankingInfo::getLastName() const {
    return mLastName.ptr();
}

MT_CTSTR nQuest::cCycleContentsRankingInfo::getClanName() const {
    return mClanName.ptr();
}

u32 nQuest::cCycleContentsRankingInfo::getPoint() const {
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 40);
}

u32 nQuest::cCycleContentsRankingInfo::getRank() const {
    return mRank;
}

nQuest::cCycleContentsRankingInfo::~cCycleContentsRankingInfo() {
}

__attribute__((weak)) void nQuest::cCycleContentsRankingInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cCycleContentsRankingInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cCycleContentsRankingInfo::MyDTI nQuest::cCycleContentsRankingInfo::DTI("nQuest::cCycleContentsRankingInfo", &::nQuest::cQuestInfoBase::DTI, 48ul, 0u, 0u);

MtObject* nQuest::cCycleContentsRankingInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cCycleContentsRankingInfo;
}

const MtDTI& nQuest::cCycleContentsRankingRewardInfo::getDTI() const {
    return nQuest::cCycleContentsRankingRewardInfo::DTI;
}

__attribute__((weak)) nQuest::cCycleContentsRankingRewardInfo* nQuest::cCycleContentsRankingRewardInfo::newInstance(u32 underRank, u32 overRank) {
    DDON_STUB("nQuest::cCycleContentsRankingRewardInfo::newInstance")
    return nullptr;
}

void nQuest::cCycleContentsRankingRewardInfo::addReward(nQuest::cCycleContentsRankingRewardInfo* pInfo, nQuest::cCycleContentsResultRewardInfo* pReward) {
    u32 t0 = pInfo->mRewardList.mLength;
    u32 t1 = pInfo->mRewardList.mBufsiz;
    if (t0 < t1) {
        pInfo->mRewardList.mLength = t0 + 1u;
        pInfo->mRewardList.mpArray[t0] = static_cast<MtObject*>(pReward);
    } else {
        void* t2 = ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
        ::memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
        ::memcpy(t2, static_cast<const void*>(pInfo->mRewardList.mpArray), static_cast<size_t>(pInfo->mRewardList.mLength) * 8);
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(pInfo->mRewardList.mpArray));
        pInfo->mRewardList.mpArray = static_cast<MtObject* *>(t2);
        pInfo->mRewardList.mBufsiz = t1 + 32u;
        u32 t3 = pInfo->mRewardList.mLength;
        pInfo->mRewardList.mLength = t3 + 1u;
        pInfo->mRewardList.mpArray[t3] = static_cast<MtObject*>(pReward);
    }
}

u32 nQuest::cCycleContentsRankingRewardInfo::getUnderRank() const {
    return mUnderRank;
}

u32 nQuest::cCycleContentsRankingRewardInfo::getOverRank() const {
    return mOverRank;
}

const nQuest::CycleContentsResultRewardList& nQuest::cCycleContentsRankingRewardInfo::getRewardList() const {
    return mRewardList;
}

nQuest::cCycleContentsRankingRewardInfo::~cCycleContentsRankingRewardInfo() {
    if (mRewardList.mLength != 0) {
        u32 v0_0 = mRewardList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mRewardList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mRewardList.mpArray[i0_3];
                v1_0 = mRewardList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mRewardList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mRewardList.mpArray));
    }
    mRewardList.mpArray = nullptr;
    mRewardList.mBufsiz = 0;
    mRewardList.mLength = 0;
}

__attribute__((weak)) void nQuest::cCycleContentsRankingRewardInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cCycleContentsRankingRewardInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cCycleContentsRankingRewardInfo::MyDTI nQuest::cCycleContentsRankingRewardInfo::DTI("nQuest::cCycleContentsRankingRewardInfo", &::nQuest::cQuestInfoBase::DTI, 48ul, 0u, 0u);

MtObject* nQuest::cCycleContentsRankingRewardInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cCycleContentsRankingRewardInfo;
}

const MtDTI& nQuest::cCycleContentsBorderRewardInfo::getDTI() const {
    return nQuest::cCycleContentsBorderRewardInfo::DTI;
}

__attribute__((weak)) nQuest::cCycleContentsBorderRewardInfo* nQuest::cCycleContentsBorderRewardInfo::newInstance(s32 underPoint) {
    DDON_STUB("nQuest::cCycleContentsBorderRewardInfo::newInstance")
    return nullptr;
}

__attribute__((weak)) nQuest::cCycleContentsBorderRewardInfo* nQuest::cCycleContentsBorderRewardInfo::newInstance(s32 underPoint, s32 overPoint) {
    DDON_STUB("nQuest::cCycleContentsBorderRewardInfo::newInstance")
    return nullptr;
}

void nQuest::cCycleContentsBorderRewardInfo::addReward(nQuest::cCycleContentsBorderRewardInfo* pInfo, nQuest::cCycleContentsResultRewardInfo* pReward) {
    u32 t0 = pInfo->mRewardList.mLength;
    u32 t1 = pInfo->mRewardList.mBufsiz;
    if (t0 < t1) {
        pInfo->mRewardList.mLength = t0 + 1u;
        pInfo->mRewardList.mpArray[t0] = static_cast<MtObject*>(pReward);
    } else {
        void* t2 = ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
        ::memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
        ::memcpy(t2, static_cast<const void*>(pInfo->mRewardList.mpArray), static_cast<size_t>(pInfo->mRewardList.mLength) * 8);
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(pInfo->mRewardList.mpArray));
        pInfo->mRewardList.mpArray = static_cast<MtObject* *>(t2);
        pInfo->mRewardList.mBufsiz = t1 + 32u;
        u32 t3 = pInfo->mRewardList.mLength;
        pInfo->mRewardList.mLength = t3 + 1u;
        pInfo->mRewardList.mpArray[t3] = static_cast<MtObject*>(pReward);
    }
}

s32 nQuest::cCycleContentsBorderRewardInfo::getUnderPoint() const {
    return mUnderPoint;
}

s32 nQuest::cCycleContentsBorderRewardInfo::getOverPoint() const {
    return mOverPoint;
}

const nQuest::CycleContentsResultRewardList& nQuest::cCycleContentsBorderRewardInfo::getRewardList() const {
    return mRewardList;
}

nQuest::cCycleContentsBorderRewardInfo::~cCycleContentsBorderRewardInfo() {
    if (mRewardList.mLength != 0) {
        u32 v0_0 = mRewardList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mRewardList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mRewardList.mpArray[i0_3];
                v1_0 = mRewardList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mRewardList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mRewardList.mpArray));
    }
    mRewardList.mpArray = nullptr;
    mRewardList.mBufsiz = 0;
    mRewardList.mLength = 0;
}

__attribute__((weak)) void nQuest::cCycleContentsBorderRewardInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cCycleContentsBorderRewardInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cCycleContentsBorderRewardInfo::MyDTI nQuest::cCycleContentsBorderRewardInfo::DTI("nQuest::cCycleContentsBorderRewardInfo", &::nQuest::cQuestInfoBase::DTI, 48ul, 0u, 0u);

MtObject* nQuest::cCycleContentsBorderRewardInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cCycleContentsBorderRewardInfo;
}

const MtDTI& nQuest::cQuestCommand::getDTI() const {
    return nQuest::cQuestCommand::DTI;
}

nQuest::cQuestCommand::cQuestCommand() {
    m_usCommand = 0;
    m_nParam03 = 0;
    m_nParam04 = 0;
    m_nParam01 = 0;
    m_nParam02 = 0;
}

nQuest::cQuestCommand::~cQuestCommand() {
}

__attribute__((weak)) void nQuest::cQuestCommand::createProperty(MtPropertyList& s) {
}

void nQuest::cQuestCommand::copy(const CDataQuestCommand* pSrc) {
    m_usCommand = pSrc->m_usCommand;
    m_nParam01 = pSrc->m_nParam01;
    m_nParam02 = pSrc->m_nParam02;
    m_nParam03 = pSrc->m_nParam03;
    m_nParam04 = pSrc->m_nParam04;
}

inline nQuest::cQuestCommand::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cQuestCommand::MyDTI nQuest::cQuestCommand::DTI("nQuest::cQuestCommand", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* nQuest::cQuestCommand::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cQuestCommand;
}

const MtDTI& nQuest::cTalkData::getDTI() const {
    return nQuest::cTalkData::DTI;
}

void* nQuest::cTalkData::operator new(size_t sz, u32 align) {
    return ::nQuest::cTalkData::getAllocator()->memAlloc(sz, align, ::nQuest::cTalkData::DTI.getID());
}

nQuest::cTalkData::cTalkData() {
    mIsOneOnly = false;
    mIsDispOrderUI = false;
    mNoOrderGroupSerial = 0;
    mGroupSerial = 0;
    mNpcId = 0;
}

nQuest::cTalkData::~cTalkData() {
}

__attribute__((weak)) void nQuest::cTalkData::createProperty(MtPropertyList& s) {
}

inline nQuest::cTalkData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cTalkData::MyDTI nQuest::cTalkData::DTI("nQuest::cTalkData", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* nQuest::cTalkData::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cTalkData;
}

const MtDTI& nQuest::cDeliverTargetInfo::getDTI() const {
    return nQuest::cDeliverTargetInfo::DTI;
}

void* nQuest::cDeliverTargetInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cDeliverTargetInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cDeliverTargetInfo::DTI.getID());
}

u32 nQuest::cDeliverTargetInfo::getStageNo() const {
    return mStageNo;
}

u32 nQuest::cDeliverTargetInfo::getGroupNo() const {
    return mGroupNo;
}

u32 nQuest::cDeliverTargetInfo::getSetNo() const {
    return mSetNo;
}

u32 nQuest::cDeliverTargetInfo::getMsgGroupSerial() const {
    return mMsgGroupSerial;
}

u32 nQuest::cDeliverTargetInfo::getNpcId() const {
    return mNpcId;
}

bool nQuest::cDeliverTargetInfo::isQuestSet() const {
    return mNpcId == 0;
}

nQuest::cDeliverTargetInfo::cDeliverTargetInfo(u32 stageNo, u32 npcId, u32 msgGroupSerial) {
    mStageNo = stageNo;
    mGroupNo = 0;
    mSetNo = 0;
    mMsgGroupSerial = msgGroupSerial;
    mNpcId = npcId;
}

nQuest::cDeliverTargetInfo::cDeliverTargetInfo(u32 stageNo, u32 groupNo, u32 setNo, u32 msgGroupSerial) {
    mStageNo = stageNo;
    mGroupNo = groupNo;
    mSetNo = setNo;
    mMsgGroupSerial = msgGroupSerial;
    mNpcId = 0;
}

nQuest::cDeliverTargetInfo::~cDeliverTargetInfo() {
}

__attribute__((weak)) void nQuest::cDeliverTargetInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cDeliverTargetInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cDeliverTargetInfo::MyDTI nQuest::cDeliverTargetInfo::DTI("nQuest::cDeliverTargetInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* nQuest::cDeliverTargetInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cDeliverTargetInfo;
}

const MtDTI& nQuest::cGUIListData::getDTI() const {
    return nQuest::cGUIListData::DTI;
}

void* nQuest::cGUIListData::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUIListData::getAllocator()->memAlloc(sz, align, ::nQuest::cGUIListData::DTI.getID());
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cGUIListData::getScheduleId() const {
    DDON_STUB("nQuest::cGUIListData::getScheduleId")
    __builtin_unreachable();
}

nQuest::QUEST_ID nQuest::cGUIListData::getQuestId() const {
    return ::sQuestManagerExt::getInstance()->getQuestId(mScheduleId);
}

u32 nQuest::cGUIListData::getQuestIdU32() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getQuestIdU32();
    } else {
        return ::nQuest::INVALID_QUEST_ID.mQuestId;
    }
}

MT_CTSTR nQuest::cGUIListData::getQuestName() const {
    sQuestManagerExt* t0 = ::sQuestManagerExt::getInstance();
    return t0->getQuestName(t0->getQuestId(mScheduleId));
}

nQuest::QUEST_TYPE nQuest::cGUIListData::getQuestType() const {
    return ::sQuestManagerExt::getInstance()->getQuestType(mScheduleId);
}

u32 nQuest::cGUIListData::getBaseLevel() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getBaseLevel();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getAreaId() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getAreaId();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getRewardAreaPoint() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardAreaPoint();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getRewardExp() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardExp();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getRewardGold() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardGold();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getRewardRim() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardRim();
    } else {
        return 0;
    }
}

const nQuest::cRewardData* nQuest::cGUIListData::getFixReward(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getFixReward(idx);
    } else {
        return nullptr;
    }
}

const nQuest::cFixRewardData* nQuest::cGUIListData::getSelectReward(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getSelectReward(idx);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) const MtTime* nQuest::cGUIListData::getEndDistributionData() const {
    DDON_STUB("nQuest::cGUIListData::getEndDistributionData")
    return nullptr;
}

__attribute__((weak)) MT_CTSTR nQuest::cGUIListData::getMyPurposeMsg() const {
    DDON_STUB("nQuest::cGUIListData::getMyPurposeMsg")
    return {};
}

__attribute__((weak)) MT_CTSTR nQuest::cGUIListData::getLeaderPurposeMsg() const {
    DDON_STUB("nQuest::cGUIListData::getLeaderPurposeMsg")
    return {};
}

MT_CTSTR nQuest::cGUIListData::getOrderNpcName() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        sNpcManager* t0 = ::sNpcManager::getInstance();
        return t0->getNpcName(pTask->getOrderNpcId());
    } else {
        return "";
    }
}

u32 nQuest::cGUIListData::getClearNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getClearNum();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getOrderConditionNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderConditionNum();
    } else {
        return 0;
    }
}

MT_CTSTR nQuest::cGUIListData::getOrderConditionMsg(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderConditionMessage(idx);
    } else {
        return "";
    }
}

nQuest::REPEAT_BONUS_TYPE nQuest::cGUIListData::getRepeatBonusType() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRepeatBonusType();
    } else {
        return ::nQuest::REPEAT_BONUS_TYPE_NONE;
    }
}

__attribute__((weak)) void nQuest::cGUIListData::setupRepeatBonusMsg(rGUIMessage* pGMD) {
    DDON_STUB("nQuest::cGUIListData::setupRepeatBonusMsg")
    /* stub */
}

MT_CTSTR nQuest::cGUIListData::getRepeatBonusMsg() const {
    return mRepeatBonusText.ptr();
}

u32 nQuest::cGUIListData::getOrderConditionType(u32 Idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderConditionType(Idx);
    } else {
        return 0;
    }
}

bool nQuest::cGUIListData::isEnableCancel() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        if (pTask->getQuestType() != ::nQuest::QUEST_TYPE_MAIN) {
            return pTask->isEnableCancel();
        } else {
            return false;
        }
    } else {
        return true;
    }
}

bool nQuest::cGUIListData::isAreaBonus() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        if (pTask->getQuestType() == ::nQuest::QUEST_TYPE_LIGHT) {
            sQuestManagerExt* t0 = ::sQuestManagerExt::getInstance();
            return t0->isAreaBonus(pTask->getAreaId());
        }
    }
    return false;
}

u32 nQuest::cGUIListData::getAreaBonusRate() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        if (pTask->getQuestType() == ::nQuest::QUEST_TYPE_LIGHT) {
            sQuestManagerExt* t0 = ::sQuestManagerExt::getInstance();
            return t0->getAreaBonusRate(pTask->getAreaId());
        }
    }
    return 0;
}

u32 nQuest::cGUIListData::getDiscoverRewardItemId() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverItemId();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getDiscoverBonusGold() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverRewardGold();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getDiscoverBonusRim() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverRewardRim();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getDiscoverBonusExp() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverRewardExp();
    } else {
        return 0;
    }
}

bool nQuest::cGUIListData::isPartyBonus() const {
    return ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId) != nullptr;
}

__attribute__((weak)) u32 nQuest::cGUIListData::getPartyBonusRate() const {
    DDON_STUB("nQuest::cGUIListData::getPartyBonusRate")
    return {};
}

bool nQuest::cGUIListData::hasReceived() const {
    const nQuest::cPartyBonusInfo* pInfo = ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId);
    if (pInfo != nullptr) {
        return pInfo->hasReceived();
    } else {
        return false;
    }
}

bool nQuest::cGUIListData::isPartyBonusOrb() const {
    const nQuest::cPartyBonusInfo* pInfo = ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId);
    if (pInfo != nullptr) {
        return pInfo->mOrbNum != 0;
    } else {
        return false;
    }
}

u32 nQuest::cGUIListData::getPartyBonusOrbNum() const {
    const nQuest::cPartyBonusInfo* pInfo = ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId);
    if (pInfo != nullptr) {
        return pInfo->mOrbNum;
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getRandomRewardNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRandomRewardNum();
    } else {
        return 0;
    }
}

bool nQuest::cGUIListData::isProgressBonus() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->isProgressBonus();
    } else {
        return false;
    }
}

bool nQuest::cGUIListData::isClanQuest() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->isClanQuest();
    } else {
        return false;
    }
}

u32 nQuest::cGUIListData::getClanPoint() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getCP();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIListData::getClanClearNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getClearNum();
    } else {
        return 0;
    }
}

u16 nQuest::cGUIListData::getClanClearMax() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderLimit();
    } else {
        return 0;
    }
}

bool nQuest::cGUIListData::isClanClear() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->isClanClear();
    } else {
        return false;
    }
}

nQuest::cGUIListData::cGUIListData(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("nQuest::cGUIListData::cGUIListData")
    /* stub */
}

nQuest::cGUIListData::~cGUIListData() {
    DDON_STUB("nQuest::cGUIListData::~cGUIListData")
    /* stub */
}

__attribute__((weak)) void nQuest::cGUIListData::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUIListData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUIListData::MyDTI nQuest::cGUIListData::DTI("nQuest::cGUIListData", &::nQuest::cQuestInfoBase::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cGUIListData::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cGUIListData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cGUIInfoData::getDTI() const {
    return nQuest::cGUIInfoData::DTI;
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cGUIInfoData::getScheduleId() const {
    DDON_STUB("nQuest::cGUIInfoData::getScheduleId")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::QUEST_ID nQuest::cGUIInfoData::getQuestId() const {
    DDON_STUB("nQuest::cGUIInfoData::getQuestId")
    __builtin_unreachable();
}

u32 nQuest::cGUIInfoData::getQuestIdU32() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getQuestIdU32();
    } else {
        return ::nQuest::INVALID_QUEST_ID.mQuestId;
    }
}

MT_CTSTR nQuest::cGUIInfoData::getQuestName() const {
    sQuestManagerExt* t0 = ::sQuestManagerExt::getInstance();
    return t0->getQuestName(t0->getQuestId(mScheduleId));
}

nQuest::QUEST_TYPE nQuest::cGUIInfoData::getQuestType() const {
    return ::sQuestManagerExt::getInstance()->getQuestType(mScheduleId);
}

u32 nQuest::cGUIInfoData::getBaseLevel() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getBaseLevel();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getAreaId() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getAreaId();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getRewardAreaPoint() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardAreaPoint();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getRewardExp() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardExp();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getRewardGold() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardGold();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getRewardRim() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardRim();
    } else {
        return 0;
    }
}

const nQuest::cRewardData* nQuest::cGUIInfoData::getFixReward(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getFixReward(idx);
    } else {
        return nullptr;
    }
}

const nQuest::cFixRewardData* nQuest::cGUIInfoData::getSelectReward(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getSelectReward(idx);
    } else {
        return nullptr;
    }
}

nQuest::REPEAT_BONUS_TYPE nQuest::cGUIInfoData::getRepeatBonusType() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRepeatBonusType();
    } else {
        return ::nQuest::REPEAT_BONUS_TYPE_NONE;
    }
}

__attribute__((weak)) MT_CTSTR nQuest::cGUIInfoData::getRepeatBonusMsg(rGUIMessage* pGMD) {
    DDON_STUB("nQuest::cGUIInfoData::getRepeatBonusMsg")
    return {};
}

__attribute__((weak)) const MtTime* nQuest::cGUIInfoData::getEndDistributionData() const {
    DDON_STUB("nQuest::cGUIInfoData::getEndDistributionData")
    return nullptr;
}

MT_CTSTR nQuest::cGUIInfoData::getOrderNpcName() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        sNpcManager* t0 = ::sNpcManager::getInstance();
        return t0->getNpcName(pTask->getOrderNpcId());
    } else {
        return "";
    }
}

u32 nQuest::cGUIInfoData::getOrderConditionNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderConditionNum();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getOrderConditionType(u32 Idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderConditionType(Idx);
    } else {
        return 0;
    }
}

MT_CTSTR nQuest::cGUIInfoData::getOrderConditionMsg(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderConditionMessage(idx);
    } else {
        return "";
    }
}

bool nQuest::cGUIInfoData::isAreaBonus() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        if (pTask->getQuestType() == ::nQuest::QUEST_TYPE_LIGHT) {
            sQuestManagerExt* t0 = ::sQuestManagerExt::getInstance();
            return t0->isAreaBonus(pTask->getAreaId());
        }
    }
    return false;
}

u32 nQuest::cGUIInfoData::getAreaBonusRate() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        if (pTask->getQuestType() == ::nQuest::QUEST_TYPE_LIGHT) {
            sQuestManagerExt* t0 = ::sQuestManagerExt::getInstance();
            return t0->getAreaBonusRate(pTask->getAreaId());
        }
    }
    return 0;
}

u32 nQuest::cGUIInfoData::getDiscoverRewardItemId() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverItemId();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getDiscoverBonusGold() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverRewardGold();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getDiscoverBonusRim() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverRewardRim();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getDiscoverBonusExp() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverRewardExp();
    } else {
        return 0;
    }
}

bool nQuest::cGUIInfoData::isPartyBonus() const {
    return ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId) != nullptr;
}

__attribute__((weak)) u32 nQuest::cGUIInfoData::getPartyBonusRate() const {
    DDON_STUB("nQuest::cGUIInfoData::getPartyBonusRate")
    return {};
}

bool nQuest::cGUIInfoData::hasReceived() const {
    const nQuest::cPartyBonusInfo* pInfo = ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId);
    if (pInfo != nullptr) {
        return pInfo->hasReceived();
    } else {
        return false;
    }
}

bool nQuest::cGUIInfoData::isPartyBonusOrb() const {
    const nQuest::cPartyBonusInfo* pInfo = ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId);
    if (pInfo != nullptr) {
        return pInfo->mOrbNum != 0;
    } else {
        return false;
    }
}

u32 nQuest::cGUIInfoData::getPartyBonusOrbNum() const {
    const nQuest::cPartyBonusInfo* pInfo = ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId);
    if (pInfo != nullptr) {
        return pInfo->mOrbNum;
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getRandomRewardNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRandomRewardNum();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getClearNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getClearNum();
    } else {
        return 0;
    }
}

bool nQuest::cGUIInfoData::isProgressBonus() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->isProgressBonus();
    } else {
        return false;
    }
}

bool nQuest::cGUIInfoData::isClanQuest() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->isClanQuest();
    } else {
        return false;
    }
}

u32 nQuest::cGUIInfoData::getClanPoint() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getCP();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIInfoData::getClanClearNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getClearNum();
    } else {
        return 0;
    }
}

u16 nQuest::cGUIInfoData::getClanClearMax() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderLimit();
    } else {
        return 0;
    }
}

bool nQuest::cGUIInfoData::isClanClear() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->isClanClear();
    } else {
        return false;
    }
}

void nQuest::cGUIInfoData::resetInfoData() {
    mScheduleId.mScheduleId = ::nQuest::INVALID_SCHEDULE_ID.mScheduleId;
}

nQuest::cGUIInfoData::cGUIInfoData() {
    DDON_STUB("nQuest::cGUIInfoData::cGUIInfoData")
    /* stub */
}

nQuest::cGUIInfoData::cGUIInfoData(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("nQuest::cGUIInfoData::cGUIInfoData")
    /* stub */
}

nQuest::cGUIInfoData::~cGUIInfoData() {
    DDON_STUB("nQuest::cGUIInfoData::~cGUIInfoData")
    /* stub */
}

__attribute__((weak)) void nQuest::cGUIInfoData::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUIInfoData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUIInfoData::MyDTI nQuest::cGUIInfoData::DTI("nQuest::cGUIInfoData", &::nQuest::cQuestInfoBase::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cGUIInfoData::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cGUIInfoData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cGUIBoardData::getDTI() const {
    return nQuest::cGUIBoardData::DTI;
}

void* nQuest::cGUIBoardData::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUIBoardData::getAllocator()->memAlloc(sz, align, ::nQuest::cGUIBoardData::DTI.getID());
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cGUIBoardData::getScheduleId() const {
    DDON_STUB("nQuest::cGUIBoardData::getScheduleId")
    __builtin_unreachable();
}

MT_CTSTR nQuest::cGUIBoardData::getQuestName() const {
    sQuestManagerExt* t0 = ::sQuestManagerExt::getInstance();
    return t0->getQuestName(t0->getQuestId(mScheduleId));
}

u32 nQuest::cGUIBoardData::getBaseLevel() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getBaseLevel();
    } else {
        return 0;
    }
}

bool nQuest::cGUIBoardData::isEnableOrder() const {
    return ::sQuestManagerExt::getInstance()->getEnableOrder(mScheduleId, true) == ::nQuest::RET_DIS_ORDER_CONDITION_TYPE_NONE;
}

bool nQuest::cGUIBoardData::isOrder() const {
    return ::sQuestManagerExt::getInstance()->isOrderQuest(mScheduleId);
}

bool nQuest::cGUIBoardData::isClanClear() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->isClanClear();
    } else {
        return false;
    }
}

bool nQuest::cGUIBoardData::isClanQuest() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->isClanQuest();
    } else {
        return false;
    }
}

u32 nQuest::cGUIBoardData::getClanPoint() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getCP();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIBoardData::getClanPointOrigin() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOriginalCP();
    } else {
        return 0;
    }
}

nQuest::cGUIBoardData::cGUIBoardData(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("nQuest::cGUIBoardData::cGUIBoardData")
    /* stub */
}

nQuest::cGUIBoardData::~cGUIBoardData() {
}

__attribute__((weak)) void nQuest::cGUIBoardData::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUIBoardData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUIBoardData::MyDTI nQuest::cGUIBoardData::DTI("nQuest::cGUIBoardData", &::nQuest::cQuestInfoBase::DTI, 24ul, 0u, 0u);

MtObject* nQuest::cGUIBoardData::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cGUIBoardData;
}

const MtDTI& nQuest::cGUIDeliveryData::getDTI() const {
    return nQuest::cGUIDeliveryData::DTI;
}

void* nQuest::cGUIDeliveryData::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUIDeliveryData::getAllocator()->memAlloc(sz, align, ::nQuest::cGUIDeliveryData::DTI.getID());
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cGUIDeliveryData::getScheduleId() const {
    DDON_STUB("nQuest::cGUIDeliveryData::getScheduleId")
    __builtin_unreachable();
}

MT_CTSTR nQuest::cGUIDeliveryData::getQuestName() const {
    sQuestManagerExt* t0 = ::sQuestManagerExt::getInstance();
    return t0->getQuestName(t0->getQuestId(mScheduleId));
}

__attribute__((weak)) bool nQuest::cGUIDeliveryData::isPreWaitDeliver() const {
    DDON_STUB("nQuest::cGUIDeliveryData::isPreWaitDeliver")
    return {};
}

__attribute__((weak)) bool nQuest::cGUIDeliveryData::checkComplete() const {
    DDON_STUB("nQuest::cGUIDeliveryData::checkComplete")
    return {};
}

nQuest::cGUIDeliveryData::cGUIDeliveryData(nQuest::SCHEDULE_ID scheduleId, s32 blockNo) {
    DDON_STUB("nQuest::cGUIDeliveryData::cGUIDeliveryData")
    /* stub */
}

nQuest::cGUIDeliveryData::~cGUIDeliveryData() {
}

__attribute__((weak)) void nQuest::cGUIDeliveryData::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUIDeliveryData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUIDeliveryData::MyDTI nQuest::cGUIDeliveryData::DTI("nQuest::cGUIDeliveryData", &::nQuest::cQuestInfoBase::DTI, 32ul, 0u, 0u);

MtObject* nQuest::cGUIDeliveryData::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cGUIDeliveryData;
}

const MtDTI& nQuest::cGUIEventBoardData::getDTI() const {
    return nQuest::cGUIEventBoardData::DTI;
}

nQuest::cGUIEventBoardData::~cGUIEventBoardData() {
}

__attribute__((weak)) void nQuest::cGUIEventBoardData::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUIEventBoardData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUIEventBoardData::MyDTI nQuest::cGUIEventBoardData::DTI("nQuest::cGUIEventBoardData", &::nQuest::cQuestInfoBase::DTI, 24ul, 0u, 0u);

MtObject* nQuest::cGUIEventBoardData::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cGUIEventBoardData;
}

const MtDTI& nQuest::cGUIAreaMasterData::getDTI() const {
    return nQuest::cGUIAreaMasterData::DTI;
}

void* nQuest::cGUIAreaMasterData::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUIAreaMasterData::getAllocator()->memAlloc(sz, align, ::nQuest::cGUIAreaMasterData::DTI.getID());
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cGUIAreaMasterData::getScheduleId() const {
    DDON_STUB("nQuest::cGUIAreaMasterData::getScheduleId")
    __builtin_unreachable();
}

nQuest::QUEST_ID nQuest::cGUIAreaMasterData::getQuestId() const {
    return ::sQuestManagerExt::getInstance()->getQuestId(mScheduleId);
}

MT_CTSTR nQuest::cGUIAreaMasterData::getQuestName() const {
    if (!::sQuestManagerExt::getInstance()->isMyOrderQuest(mScheduleId) && !::sQuestManagerExt::getInstance()->isDiscoverdQuest(mScheduleId)) {
        cQuestTask* t2 = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
        if (t2 != nullptr) {
            if (t2->getClearNum() != 0) {
                sQuestManagerExt* t4 = ::sQuestManagerExt::getInstance();
                return t4->getQuestName(t4->getQuestId(mScheduleId));
            }
        }
        return static_cast<sGUIExt*>(::sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(::sGUI::getInstance())->getMsgCommonMessage(), 110u);
    }
    sQuestManagerExt* t4 = ::sQuestManagerExt::getInstance();
    return t4->getQuestName(t4->getQuestId(mScheduleId));
}

u32 nQuest::cGUIAreaMasterData::getBaseLevel() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getBaseLevel();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getRewardExp() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardExp();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getRewardGold() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardGold();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getRewardRim() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardRim();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getRewardAreaPoint() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRewardAreaPoint();
    } else {
        return 0;
    }
}

const nQuest::cRewardData* nQuest::cGUIAreaMasterData::getFixReward(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getFixReward(idx);
    } else {
        return nullptr;
    }
}

const nQuest::cFixRewardData* nQuest::cGUIAreaMasterData::getSelectReward(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getSelectReward(idx);
    } else {
        return nullptr;
    }
}

nQuest::REPEAT_BONUS_TYPE nQuest::cGUIAreaMasterData::getRepeatBonusType() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRepeatBonusType();
    } else {
        return ::nQuest::REPEAT_BONUS_TYPE_NONE;
    }
}

__attribute__((weak)) MT_CTSTR nQuest::cGUIAreaMasterData::getRepeatBonusMsg(rGUIMessage* pGMD) {
    DDON_STUB("nQuest::cGUIAreaMasterData::getRepeatBonusMsg")
    return {};
}

__attribute__((weak)) const MtTime* nQuest::cGUIAreaMasterData::getEndDistributionData() const {
    DDON_STUB("nQuest::cGUIAreaMasterData::getEndDistributionData")
    return nullptr;
}

u32 nQuest::cGUIAreaMasterData::getDiscoverRewardItemId() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverItemId();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getDiscoverBonusGold() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverRewardGold();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getDiscoverBonusRim() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverRewardRim();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getDiscoverBonusExp() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getUndiscoverRewardExp();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getEnemyNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getTargetEnemyGroupNum();
    } else {
        return 0;
    }
}

MT_CTSTR nQuest::cGUIAreaMasterData::getEnemyName(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        u32 enemyGroupId = pTask->getTargetEnemyGroupId(idx);
        return static_cast<sGUIExt*>(::sGUI::getInstance())->getEnemyNameFromGroupId(enemyGroupId);
    } else {
        return "";
    }
}

u32 nQuest::cGUIAreaMasterData::getEnemyLevel(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getTargetEnemyLevel(idx);
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getOrderConditionNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderConditionNum();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getOrderConditionType(u32 idx) const {
    cQuestTask* t0 = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (t0 != nullptr) {
        if (idx < t0->getOrderConditionNum()) {
            cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
            if (pTask != nullptr) {
                return pTask->getOrderConditionType(idx);
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

MT_CTSTR nQuest::cGUIAreaMasterData::getOrderConditionMsg(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getOrderConditionMessage(idx);
    } else {
        return "";
    }
}

bool nQuest::cGUIAreaMasterData::isPartyBonus() const {
    return ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId) != nullptr;
}

__attribute__((weak)) u32 nQuest::cGUIAreaMasterData::getPartyBonusRate() const {
    DDON_STUB("nQuest::cGUIAreaMasterData::getPartyBonusRate")
    return {};
}

bool nQuest::cGUIAreaMasterData::hasReceived() const {
    const nQuest::cPartyBonusInfo* pInfo = ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId);
    if (pInfo != nullptr) {
        return pInfo->hasReceived();
    } else {
        return false;
    }
}

bool nQuest::cGUIAreaMasterData::isPartyBonusOrb() const {
    const nQuest::cPartyBonusInfo* pInfo = ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId);
    if (pInfo != nullptr) {
        return pInfo->mOrbNum != 0;
    } else {
        return false;
    }
}

u32 nQuest::cGUIAreaMasterData::getPartyBonusOrbNum() const {
    const nQuest::cPartyBonusInfo* pInfo = ::sQuestManagerExt::getInstance()->getQuestPartyBonusInfo(mScheduleId);
    if (pInfo != nullptr) {
        return pInfo->mOrbNum;
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getRandomRewardNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getRandomRewardNum();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getClearNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getClearNum();
    } else {
        return 0;
    }
}

bool nQuest::cGUIAreaMasterData::isProgressBonus() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->isProgressBonus();
    } else {
        return false;
    }
}

u32 nQuest::cGUIAreaMasterData::getDeliveryItemInfoNum() const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        return pTask->getDeliveryItemInfoNum();
    } else {
        return 0;
    }
}

u32 nQuest::cGUIAreaMasterData::getDeliveryItemId(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        if (idx < pTask->getDeliveryItemInfoNum()) {
            return pTask->getDeliveryItemId(idx);
        }
    }
    return 0;
}

u32 nQuest::cGUIAreaMasterData::getDeliveryItemNum(u32 idx) const {
    cQuestTask* pTask = ::sQuestManagerExt::getInstance()->getQuestTask(mScheduleId);
    if (pTask != nullptr) {
        if (idx < pTask->getDeliveryItemInfoNum()) {
            return pTask->getDeliveryItemNum(idx);
        }
    }
    return 0;
}

nQuest::cGUIAreaMasterData::cGUIAreaMasterData() {
    DDON_STUB("nQuest::cGUIAreaMasterData::cGUIAreaMasterData")
    /* stub */
}

nQuest::cGUIAreaMasterData::cGUIAreaMasterData(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("nQuest::cGUIAreaMasterData::cGUIAreaMasterData")
    /* stub */
}

nQuest::cGUIAreaMasterData::~cGUIAreaMasterData() {
    DDON_STUB("nQuest::cGUIAreaMasterData::~cGUIAreaMasterData")
    /* stub */
}

__attribute__((weak)) void nQuest::cGUIAreaMasterData::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUIAreaMasterData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUIAreaMasterData::MyDTI nQuest::cGUIAreaMasterData::DTI("nQuest::cGUIAreaMasterData", &::nQuest::cQuestInfoBase::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cGUIAreaMasterData::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cGUIAreaMasterData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cGUIActiveData::getDTI() const {
    return nQuest::cGUIActiveData::DTI;
}

void* nQuest::cGUIActiveData::operator new(size_t sz, u32 align) {
    return ::nQuest::cGUIActiveData::getAllocator()->memAlloc(sz, align, ::nQuest::cGUIActiveData::DTI.getID());
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cGUIActiveData::getScheduleId() const {
    DDON_STUB("nQuest::cGUIActiveData::getScheduleId")
    __builtin_unreachable();
}

bool nQuest::cGUIActiveData::isOrder() const {
    return ::sQuestManagerExt::getInstance()->isOrderQuest(mScheduleId);
}

nQuest::cGUIActiveData::cGUIActiveData(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("nQuest::cGUIActiveData::cGUIActiveData")
    /* stub */
}

nQuest::cGUIActiveData::~cGUIActiveData() {
}

__attribute__((weak)) void nQuest::cGUIActiveData::createProperty(MtPropertyList& s) {
}

inline nQuest::cGUIActiveData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cGUIActiveData::MyDTI nQuest::cGUIActiveData::DTI("nQuest::cGUIActiveData", &::nQuest::cQuestInfoBase::DTI, 24ul, 0u, 0u);

MtObject* nQuest::cGUIActiveData::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cGUIActiveData;
}

const MtDTI& nQuest::cCycleContentsSituationInfo::getDTI() const {
    return nQuest::cCycleContentsSituationInfo::DTI;
}

void* nQuest::cCycleContentsSituationInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cCycleContentsSituationInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cCycleContentsSituationInfo::DTI.getID());
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cCycleContentsSituationInfo::getScheduleId() const {
    DDON_STUB("nQuest::cCycleContentsSituationInfo::getScheduleId")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::QUEST_ID nQuest::cCycleContentsSituationInfo::getQuestId() const {
    DDON_STUB("nQuest::cCycleContentsSituationInfo::getQuestId")
    __builtin_unreachable();
}

MT_CTSTR nQuest::cCycleContentsSituationInfo::getContentsName() const {
    return ::sQuestManagerExt::getInstance()->getCycleContentsSituationName(static_cast<nQuest::CYCLE_CONTENTS_CATEGORY>(mCycleContentsCategory), static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mCycleContentsSubCategory), 2u, mSituationNo);
}

MT_CTSTR nQuest::cCycleContentsSituationInfo::getContentsInfo() const {
    return ::sQuestManagerExt::getInstance()->getCycleContentsSituationDetailedInfo(static_cast<nQuest::CYCLE_CONTENTS_CATEGORY>(mCycleContentsCategory), static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mCycleContentsSubCategory), 2u, mSituationNo);
}

u32 nQuest::cCycleContentsSituationInfo::getBaseLevel() const {
    return mBaseLevel;
}

bool nQuest::cCycleContentsSituationInfo::isEnableOrder() const {
    return ::nQuest::getEnableOrderList(mOrderConditions) == ::nQuest::RET_DIS_ORDER_CONDITION_TYPE_NONE;
}

nQuest::RET_DISABLE_ORDER_CONDITION_TYPE nQuest::cCycleContentsSituationInfo::getEnableOrder() const {
    return ::nQuest::getEnableOrderList(mOrderConditions);
}

u32 nQuest::cCycleContentsSituationInfo::getOrderConditionNum() const {
    return mOrderConditions.mLength;
}

u32 nQuest::cCycleContentsSituationInfo::getOrderConditionType(u32 idx) const {
    if (idx < mOrderConditions.mLength) {
        return mOrderConditions[idx]->mConditionType;
    } else {
        return 0;
    }
}

MT_CTSTR nQuest::cCycleContentsSituationInfo::getOrderConditionMsg(u32 idx) const {
    if (idx < mOrderConditions.mLength) {
        return ::sQuestManagerExt::getInstance()->getOrderConditionText(mOrderConditions[idx]->mConditionType);
    } else {
        return "";
    }
}

__attribute__((weak)) MT_CTSTR nQuest::cCycleContentsSituationInfo::getOrderConditionParamMessage(u32 idx, u32 paramIdx) const {
    DDON_STUB("nQuest::cCycleContentsSituationInfo::getOrderConditionParamMessage")
    return {};
}

u32 nQuest::cCycleContentsSituationInfo::getRewardItem(u32 idx) const {
    if (idx <= 6u) {
        return mRewardItem[idx];
    } else {
        return 0;
    }
}

u32 nQuest::cCycleContentsSituationInfo::getMaxClearTimeBonusRatio() const {
    return mMaxClearTimeBonusRatio;
}

u32 nQuest::cCycleContentsSituationInfo::getSituationNo() const {
    return mSituationNo;
}

bool nQuest::cCycleContentsSituationInfo::isDistribution() const {
    return mIsDistribution;
}

void nQuest::cCycleContentsSituationInfo::setDistribution(bool setDist) {
    mIsDistribution = setDist;
}

__attribute__((weak)) void nQuest::cCycleContentsSituationInfo::addOrderCondition(u8 type, u32 param1, u32 param2) {
    DDON_STUB("nQuest::cCycleContentsSituationInfo::addOrderCondition")
    /* stub */
}

void nQuest::cCycleContentsSituationInfo::updateOrderConditionInfo() {
    u32 i = 0;
    if (mOrderConditions.mLength != 0) {
        do {
            static_cast<nQuest::cOrderCondition*>(mOrderConditions.getBuffer()[static_cast<int>(i)])->updateConditionMessage();
            i += 1u;
        } while (i < mOrderConditions.mLength);
    }
}

__attribute__((weak)) void nQuest::cCycleContentsSituationInfo::loadOrderConditionInfo() {
    DDON_STUB("nQuest::cCycleContentsSituationInfo::loadOrderConditionInfo")
    /* stub */
}

nQuest::cCycleContentsSituationInfo::cCycleContentsSituationInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, u8 situationNo, u8 CycleContentsCategory, u32 CycleContentsSubCategory, u32* item, u32 maxClearTimeBonusRatio, bool IsDistribution) {
    DDON_STUB("nQuest::cCycleContentsSituationInfo::cCycleContentsSituationInfo")
    /* stub */
}

nQuest::cCycleContentsSituationInfo::~cCycleContentsSituationInfo() {
    DDON_STUB("nQuest::cCycleContentsSituationInfo::~cCycleContentsSituationInfo")
    /* stub */
}

inline nQuest::cCycleContentsSituationInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cCycleContentsSituationInfo::MyDTI nQuest::cCycleContentsSituationInfo::DTI("nQuest::cCycleContentsSituationInfo", &::nQuest::cQuestInfoBase::DTI, 120ul, 0u, 0u);

MtObject* nQuest::cCycleContentsSituationInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cCycleContentsSituationInfo;
}

const MtDTI& nQuest::cEndContentsGroupQuestInfo::getDTI() const {
    return nQuest::cEndContentsGroupQuestInfo::DTI;
}

void* nQuest::cEndContentsGroupQuestInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cEndContentsGroupQuestInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cEndContentsGroupQuestInfo::DTI.getID());
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cEndContentsGroupQuestInfo::getScheduleId() const {
    DDON_STUB("nQuest::cEndContentsGroupQuestInfo::getScheduleId")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::QUEST_ID nQuest::cEndContentsGroupQuestInfo::getQuestId() const {
    DDON_STUB("nQuest::cEndContentsGroupQuestInfo::getQuestId")
    __builtin_unreachable();
}

bool nQuest::cEndContentsGroupQuestInfo::isEnableOrder() const {
    return ::nQuest::getEnableOrderList(mOrderConditions) == ::nQuest::RET_DIS_ORDER_CONDITION_TYPE_NONE;
}

nQuest::RET_DISABLE_ORDER_CONDITION_TYPE nQuest::cEndContentsGroupQuestInfo::getEnableOrder() const {
    return ::nQuest::getEnableOrderList(mOrderConditions);
}

u32 nQuest::cEndContentsGroupQuestInfo::getOrderConditionType(u32 idx) const {
    if (idx < mOrderConditions.mLength) {
        return mOrderConditions[idx]->mConditionType;
    } else {
        return 0;
    }
}

MT_CTSTR nQuest::cEndContentsGroupQuestInfo::getOrderConditionMsg(u32 idx) const {
    if (idx < mOrderConditions.mLength) {
        return ::sQuestManagerExt::getInstance()->getOrderConditionText(mOrderConditions[idx]->mConditionType);
    } else {
        return "";
    }
}

__attribute__((weak)) MT_CTSTR nQuest::cEndContentsGroupQuestInfo::getOrderConditionParamMessage(u32 idx, u32 paramIdx) const {
    DDON_STUB("nQuest::cEndContentsGroupQuestInfo::getOrderConditionParamMessage")
    return {};
}

__attribute__((weak)) void nQuest::cEndContentsGroupQuestInfo::addOrderCondition(u8 type, u32 param1, u32 param2) {
    DDON_STUB("nQuest::cEndContentsGroupQuestInfo::addOrderCondition")
    /* stub */
}

void nQuest::cEndContentsGroupQuestInfo::updateOrderConditionInfo() {
    u32 i = 0;
    if (mOrderConditions.mLength != 0) {
        do {
            static_cast<nQuest::cOrderCondition*>(mOrderConditions.getBuffer()[static_cast<int>(i)])->updateConditionMessage();
            i += 1u;
        } while (i < mOrderConditions.mLength);
    }
}

__attribute__((weak)) void nQuest::cEndContentsGroupQuestInfo::loadOrderConditionInfo() {
    DDON_STUB("nQuest::cEndContentsGroupQuestInfo::loadOrderConditionInfo")
    /* stub */
}

nQuest::cEndContentsGroupQuestInfo::cEndContentsGroupQuestInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("nQuest::cEndContentsGroupQuestInfo::cEndContentsGroupQuestInfo")
    /* stub */
}

nQuest::cEndContentsGroupQuestInfo::~cEndContentsGroupQuestInfo() {
    DDON_STUB("nQuest::cEndContentsGroupQuestInfo::~cEndContentsGroupQuestInfo")
    /* stub */
}

inline nQuest::cEndContentsGroupQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cEndContentsGroupQuestInfo::MyDTI nQuest::cEndContentsGroupQuestInfo::DTI("nQuest::cEndContentsGroupQuestInfo", &::nQuest::cQuestInfoBase::DTI, 72ul, 0u, 0u);

MtObject* nQuest::cEndContentsGroupQuestInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cEndContentsGroupQuestInfo;
}

const MtDTI& nQuest::cTargetEnemyInfo::getDTI() const {
    return nQuest::cTargetEnemyInfo::DTI;
}

void* nQuest::cTargetEnemyInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cTargetEnemyInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cTargetEnemyInfo::DTI.getID());
}

bool nQuest::cTargetEnemyInfo::sameInfo(u32 stageNo, u32 groupNo) const {
    if (mStageNo == stageNo) {
        return mGroupNo == groupNo;
    } else {
        return false;
    }
}

u32 nQuest::cTargetEnemyInfo::getStageNo() const {
    return mStageNo;
}

u32 nQuest::cTargetEnemyInfo::getGroupNo() const {
    return mGroupNo;
}

nQuest::cTargetEnemyInfo::cTargetEnemyInfo(u32 stageNo, u32 groupNo) {
    mStageNo = stageNo;
    mGroupNo = groupNo;
}

nQuest::cTargetEnemyInfo::~cTargetEnemyInfo() {
}

__attribute__((weak)) void nQuest::cTargetEnemyInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cTargetEnemyInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cTargetEnemyInfo::MyDTI nQuest::cTargetEnemyInfo::DTI("nQuest::cTargetEnemyInfo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* nQuest::cTargetEnemyInfo::MyDTI::newInstance() const {
    return new (16u) ::nQuest::cTargetEnemyInfo;
}

const MtDTI& nQuest::cScheduleInfo::getDTI() const {
    return nQuest::cScheduleInfo::DTI;
}

__attribute__((weak)) nQuest::QUEST_ID nQuest::cScheduleInfo::getQuestId() const {
    DDON_STUB("nQuest::cScheduleInfo::getQuestId")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cScheduleInfo::getScheduleId() const {
    DDON_STUB("nQuest::cScheduleInfo::getScheduleId")
    __builtin_unreachable();
}

nQuest::cScheduleInfo::cScheduleInfo() {
    DDON_STUB("nQuest::cScheduleInfo::cScheduleInfo")
    /* stub */
}

nQuest::cScheduleInfo::cScheduleInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("nQuest::cScheduleInfo::cScheduleInfo")
    /* stub */
}

nQuest::cScheduleInfo::~cScheduleInfo() {
}

__attribute__((weak)) void nQuest::cScheduleInfo::createProperty(MtPropertyList& s) {
}

inline nQuest::cScheduleInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cScheduleInfo::MyDTI nQuest::cScheduleInfo::DTI("nQuest::cScheduleInfo", &::MtObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cScheduleInfo::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cScheduleInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nQuest::cPartyBonusInfo::getDTI() const {
    return nQuest::cPartyBonusInfo::DTI;
}

void* nQuest::cPartyBonusInfo::operator new(size_t sz, u32 align) {
    return ::nQuest::cPartyBonusInfo::getAllocator()->memAlloc(sz, align, ::nQuest::cPartyBonusInfo::DTI.getID());
}

__attribute__((weak)) nQuest::SCHEDULE_ID nQuest::cPartyBonusInfo::getScheduleId() const {
    DDON_STUB("nQuest::cPartyBonusInfo::getScheduleId")
    __builtin_unreachable();
}

u32 nQuest::cPartyBonusInfo::getOrbNum() const {
    return mOrbNum;
}

void nQuest::cPartyBonusInfo::receive() {
    mHasReceived = true;
}

nQuest::cPartyBonusInfo::cPartyBonusInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 gold, u32 exp, u32 rim, u32 ap, u32 orb, bool isReceived) {
    DDON_STUB("nQuest::cPartyBonusInfo::cPartyBonusInfo")
    /* stub */
}

nQuest::cPartyBonusInfo::~cPartyBonusInfo() {
}

void nQuest::cPartyBonusInfo::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mQuestId", static_cast<MtObject*>(&mQuestId), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mScheduleId", static_cast<MtObject*>(&mScheduleId), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mGoldRatio", &mGoldRatio, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mExpRatio", &mExpRatio, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mRimRatio", &mRimRatio, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mAreaPointRatio", &mAreaPointRatio, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOrbNum", &mOrbNum, 0u, 0u);
}

inline nQuest::cPartyBonusInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nQuest::cPartyBonusInfo::MyDTI nQuest::cPartyBonusInfo::DTI("nQuest::cPartyBonusInfo", &::nQuest::cQuestInfoBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* nQuest::cPartyBonusInfo::MyDTI::newInstance() const {
    DDON_STUB("nQuest::cPartyBonusInfo::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) bool nQuest::cGUINewspaperSetQuestInfoList::isPartyRecommanded(const nQuest::cGUINewspaperSetQuestInfo* pInfo) const {
    DDON_STUB("nQuest::cGUINewspaperSetQuestInfoList::isPartyRecommanded")
    return {};
}

nQuest::cGUINewspaperSetQuestInfoList::cGUINewspaperSetQuestInfoList() {
    mAreaId = 0;
    mUnderBaseLevel = 0;
    mOverBaseLevel = 0;
}

u32 nQuest::TargetEnemyInfoArray::getFlagNo() const {
    return mFlagNo;
}

void nQuest::TargetEnemyInfoArray::setFlagNo(u32 flagNo) {
    mFlagNo = flagNo;
}

bool nQuest::TargetEnemyInfoArray::isValid() const {
    return mIsValid;
}

void nQuest::TargetEnemyInfoArray::setIsValid(bool isValid) {
    mIsValid = isValid;
}

nQuest::TargetEnemyInfoArray::TargetEnemyInfoArray() {
    mFlagNo = 0;
    mIsValid = false;
}

nQuest::TargetEnemyInfoArray::TargetEnemyInfoArray(const nQuest::TargetEnemyInfoArray& obj) {
    DDON_STUB("nQuest::TargetEnemyInfoArray::TargetEnemyInfoArray")
    /* stub */
}

nQuest::QuestCommandList::QuestCommandList() {
    mIsNotLeaderOnly = true;
}

nQuest::QuestCommandList::QuestCommandList(cQuestTask* pTask, const nQuest::QuestCommandList& obj) {
    DDON_STUB("nQuest::QuestCommandList::QuestCommandList")
    /* stub */
}

template MtTypedArray<nQuest::cCycleContentsPersonalRankInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cCycleContentsResultPointInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cCycleContentsResultRewardInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cDeliverRequestItemInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cDeliveredItemInfo::cDeliverCharacterInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cDeliveredItemInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cGUINewspaperSetQuestItemInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cGUINewspaperSetQuestMonsterInfo>::~MtTypedArray();

