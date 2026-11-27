// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestSvRequest.h"
#include "Protocol/PacketData/Common.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "Protocol/PacketData/Quest.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "cQuestResourceLoadManager.h"
#include "cQuestSvRequestManager.h"
#include "cQuestTask.h"
#include "nQuest.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "sTalkManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestSvReqCycleContentsPlayEnd::getDTI() const {
    return cQuestSvReqCycleContentsPlayEnd::DTI;
}

u32 cQuestSvReqCycleContentsPlayEnd::getComId() const {
    return 199;
}

bool cQuestSvReqCycleContentsPlayEnd::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->cycleContentsPlayEnd();
}

inline cQuestSvReqCycleContentsPlayEnd::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqCycleContentsPlayEnd::MyDTI cQuestSvReqCycleContentsPlayEnd::DTI("cQuestSvReqCycleContentsPlayEnd", &::cQuestSvRequest::DTI, 40ul, 0u, 0u);

MtObject* cQuestSvReqCycleContentsPlayEnd::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqCycleContentsPlayEnd;
}

const MtDTI& cQuestSvReqDecideDeliveryItem::getDTI() const {
    return cQuestSvReqDecideDeliveryItem::DTI;
}

u32 cQuestSvReqDecideDeliveryItem::getComId() const {
    return 159;
}

__attribute__((weak)) bool cQuestSvReqDecideDeliveryItem::serverRequest() const {
    DDON_STUB("cQuestSvReqDecideDeliveryItem::serverRequest")
    return {};
}

bool cQuestSvReqDecideDeliveryItem::isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const {
    bool t0 = scheduleId.nQuest::SCHEDULE_ID::operator==(mScheduleId);
    return t0;
}

inline cQuestSvReqDecideDeliveryItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqDecideDeliveryItem::MyDTI cQuestSvReqDecideDeliveryItem::DTI("cQuestSvReqDecideDeliveryItem", &::cQuestSvRequest::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSvReqDecideDeliveryItem::MyDTI::newInstance() const {
    DDON_STUB("cQuestSvReqDecideDeliveryItem::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestSvReqGetActiveQuest::getDTI() const {
    return cQuestSvReqGetActiveQuest::DTI;
}

u32 cQuestSvReqGetActiveQuest::getComId() const {
    return 139;
}

bool cQuestSvReqGetActiveQuest::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->sendGetActiveQuest();
}

inline cQuestSvReqGetActiveQuest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetActiveQuest::MyDTI cQuestSvReqGetActiveQuest::DTI("cQuestSvReqGetActiveQuest", &::cQuestSvRequest::DTI, 40ul, 0u, 0u);

MtObject* cQuestSvReqGetActiveQuest::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGetActiveQuest;
}

const MtDTI& cQuestSvReqGetAreaBonusList::getDTI() const {
    return cQuestSvReqGetAreaBonusList::DTI;
}

u32 cQuestSvReqGetAreaBonusList::getComId() const {
    return 51;
}

bool cQuestSvReqGetAreaBonusList::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getAreaBonusList();
}

inline cQuestSvReqGetAreaBonusList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetAreaBonusList::MyDTI cQuestSvReqGetAreaBonusList::DTI("cQuestSvReqGetAreaBonusList", &::cQuestSvRequest::DTI, 40ul, 0u, 0u);

MtObject* cQuestSvReqGetAreaBonusList::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGetAreaBonusList;
}

const MtDTI& cQuestSvReqGetLightQuestList::getDTI() const {
    return cQuestSvReqGetLightQuestList::DTI;
}

u32 cQuestSvReqGetLightQuestList::getComId() const {
    return 118;
}

bool cQuestSvReqGetLightQuestList::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLightQuestList(mBoardId);
}

inline cQuestSvReqGetLightQuestList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetLightQuestList::MyDTI cQuestSvReqGetLightQuestList::DTI("cQuestSvReqGetLightQuestList", &::cQuestSvRequest::DTI, 48ul, 0u, 0u);

MtObject* cQuestSvReqGetLightQuestList::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGetLightQuestList;
}

const MtDTI& cQuestSvReqGetPartyQuestProgressInfo::getDTI() const {
    return cQuestSvReqGetPartyQuestProgressInfo::DTI;
}

u32 cQuestSvReqGetPartyQuestProgressInfo::getComId() const {
    return 160;
}

bool cQuestSvReqGetPartyQuestProgressInfo::serverRequest() const {
    if (sQuestManagerExt::getInstance()->isJoinLeader()) {
        return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getPartyQuestProgressInfo();
    } else {
        return false;
    }
}

inline cQuestSvReqGetPartyQuestProgressInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetPartyQuestProgressInfo::MyDTI cQuestSvReqGetPartyQuestProgressInfo::DTI("cQuestSvReqGetPartyQuestProgressInfo", &::cQuestSvRequest::DTI, 40ul, 0u, 0u);

MtObject* cQuestSvReqGetPartyQuestProgressInfo::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGetPartyQuestProgressInfo;
}

const MtDTI& cQuestSvReqGetQuestCompleteList::getDTI() const {
    return cQuestSvReqGetQuestCompleteList::DTI;
}

u32 cQuestSvReqGetQuestCompleteList::getComId() const {
    return 135;
}

bool cQuestSvReqGetQuestCompleteList::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getQuestCompleteList(static_cast<u32>(mQuestType));
}

inline cQuestSvReqGetQuestCompleteList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetQuestCompleteList::MyDTI cQuestSvReqGetQuestCompleteList::DTI("cQuestSvReqGetQuestCompleteList", &::cQuestSvRequest::DTI, 48ul, 0u, 0u);

MtObject* cQuestSvReqGetQuestCompleteList::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGetQuestCompleteList;
}

const MtDTI& cQuestSvReqGetRankingDataRankByQuestScheduleId::getDTI() const {
    return cQuestSvReqGetRankingDataRankByQuestScheduleId::DTI;
}

u32 cQuestSvReqGetRankingDataRankByQuestScheduleId::getComId() const {
    return 428;
}

__attribute__((weak)) bool cQuestSvReqGetRankingDataRankByQuestScheduleId::serverRequest() const {
    DDON_STUB("cQuestSvReqGetRankingDataRankByQuestScheduleId::serverRequest")
    return {};
}

bool cQuestSvReqGetRankingDataRankByQuestScheduleId::isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const {
    bool t0 = scheduleId.nQuest::SCHEDULE_ID::operator==(mScheduleId);
    return t0;
}

__attribute__((weak)) void cQuestSvReqGetRankingDataRankByQuestScheduleId::executeCallbackFunc(u32 errorCode) {
    DDON_STUB("cQuestSvReqGetRankingDataRankByQuestScheduleId::executeCallbackFunc")
    /* stub */
}

inline cQuestSvReqGetRankingDataRankByQuestScheduleId::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetRankingDataRankByQuestScheduleId::MyDTI cQuestSvReqGetRankingDataRankByQuestScheduleId::DTI("cQuestSvReqGetRankingDataRankByQuestScheduleId", &::cQuestSvRequest::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSvReqGetRankingDataRankByQuestScheduleId::MyDTI::newInstance() const {
    DDON_STUB("cQuestSvReqGetRankingDataRankByQuestScheduleId::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestSvReqGetRecommendedQuestInfoList::getDTI() const {
    return cQuestSvReqGetRecommendedQuestInfoList::DTI;
}

u32 cQuestSvReqGetRecommendedQuestInfoList::getComId() const {
    return 129;
}

bool cQuestSvReqGetRecommendedQuestInfoList::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getRecommendedQuestInfoList();
}

__attribute__((weak)) void cQuestSvReqGetRecommendedQuestInfoList::executeCallbackFunc(u32 errorCode) {
    DDON_STUB("cQuestSvReqGetRecommendedQuestInfoList::executeCallbackFunc")
    /* stub */
}

inline cQuestSvReqGetRecommendedQuestInfoList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetRecommendedQuestInfoList::MyDTI cQuestSvReqGetRecommendedQuestInfoList::DTI("cQuestSvReqGetRecommendedQuestInfoList", &::cQuestSvRequest::DTI, 40ul, 0u, 0u);

MtObject* cQuestSvReqGetRecommendedQuestInfoList::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGetRecommendedQuestInfoList;
}

const MtDTI& cQuestSvReqGetSetQuestInfoList::getDTI() const {
    return cQuestSvReqGetSetQuestInfoList::DTI;
}

u32 cQuestSvReqGetSetQuestInfoList::getComId() const {
    return 127;
}

bool cQuestSvReqGetSetQuestInfoList::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getSetQuestInfoList(mAreaNo);
}

__attribute__((weak)) void cQuestSvReqGetSetQuestInfoList::executeCallbackFunc(u32 errorCode) {
    DDON_STUB("cQuestSvReqGetSetQuestInfoList::executeCallbackFunc")
    /* stub */
}

inline cQuestSvReqGetSetQuestInfoList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetSetQuestInfoList::MyDTI cQuestSvReqGetSetQuestInfoList::DTI("cQuestSvReqGetSetQuestInfoList", &::cQuestSvRequest::DTI, 48ul, 0u, 0u);

MtObject* cQuestSvReqGetSetQuestInfoList::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGetSetQuestInfoList;
}

const MtDTI& cQuestSvReqGetSetQuestList::getDTI() const {
    return cQuestSvReqGetSetQuestList::DTI;
}

u32 cQuestSvReqGetSetQuestList::getComId() const {
    return 119;
}

bool cQuestSvReqGetSetQuestList::serverRequest() const {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
        return false;
    } else {
        return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getSetQuestList(mAreaNo);
    }
}

inline cQuestSvReqGetSetQuestList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetSetQuestList::MyDTI cQuestSvReqGetSetQuestList::DTI("cQuestSvReqGetSetQuestList", &::cQuestSvRequest::DTI, 48ul, 0u, 0u);

MtObject* cQuestSvReqGetSetQuestList::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGetSetQuestList;
}

const MtDTI& cQuestSvReqGetTutorialQuestList::getDTI() const {
    return cQuestSvReqGetTutorialQuestList::DTI;
}

u32 cQuestSvReqGetTutorialQuestList::getComId() const {
    return 121;
}

bool cQuestSvReqGetTutorialQuestList::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getTutorialQuestList(mStageNo);
}

inline cQuestSvReqGetTutorialQuestList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGetTutorialQuestList::MyDTI cQuestSvReqGetTutorialQuestList::DTI("cQuestSvReqGetTutorialQuestList", &::cQuestSvRequest::DTI, 48ul, 0u, 0u);

MtObject* cQuestSvReqGetTutorialQuestList::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGetTutorialQuestList;
}

const MtDTI& cQuestSvReqGpCompleteLightQuestList::getDTI() const {
    return cQuestSvReqGpCompleteLightQuestList::DTI;
}

u32 cQuestSvReqGpCompleteLightQuestList::getComId() const {
    return 144;
}

bool cQuestSvReqGpCompleteLightQuestList::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->reqBoardQuestAllComplete(mBoardId);
}

inline cQuestSvReqGpCompleteLightQuestList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqGpCompleteLightQuestList::MyDTI cQuestSvReqGpCompleteLightQuestList::DTI("cQuestSvReqGpCompleteLightQuestList", &::cQuestSvRequest::DTI, 48ul, 0u, 0u);

MtObject* cQuestSvReqGpCompleteLightQuestList::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqGpCompleteLightQuestList;
}

const MtDTI& cQuestSvReqQuestCancel::getDTI() const {
    return cQuestSvReqQuestCancel::DTI;
}

u32 cQuestSvReqQuestCancel::getComId() const {
    return 132;
}

__attribute__((weak)) bool cQuestSvReqQuestCancel::serverRequest() const {
    DDON_STUB("cQuestSvReqQuestCancel::serverRequest")
    return {};
}

bool cQuestSvReqQuestCancel::isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const {
    bool t0 = scheduleId.nQuest::SCHEDULE_ID::operator==(mScheduleId);
    return t0;
}

void cQuestSvReqQuestCancel::resetParam() {
    MtObject* v0_3 = mpFromClass;
    if (v0_3 != nullptr) {
        const MtDTI& t0 = v0_3->getDTI();
        MT_CTSTR v0_1 = cQuestTask::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cQuestTask*>(v0_3)->resetQuestCancelParam();
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

inline cQuestSvReqQuestCancel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqQuestCancel::MyDTI cQuestSvReqQuestCancel::DTI("cQuestSvReqQuestCancel", &::cQuestSvRequest::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSvReqQuestCancel::MyDTI::newInstance() const {
    DDON_STUB("cQuestSvReqQuestCancel::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestSvReqQuestCompleteFlagClear::getDTI() const {
    return cQuestSvReqQuestCompleteFlagClear::DTI;
}

u32 cQuestSvReqQuestCompleteFlagClear::getComId() const {
    return 134;
}

__attribute__((weak)) bool cQuestSvReqQuestCompleteFlagClear::serverRequest() const {
    DDON_STUB("cQuestSvReqQuestCompleteFlagClear::serverRequest")
    return {};
}

bool cQuestSvReqQuestCompleteFlagClear::isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const {
    bool t0 = scheduleId.nQuest::SCHEDULE_ID::operator==(mScheduleId);
    return t0;
}

inline cQuestSvReqQuestCompleteFlagClear::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqQuestCompleteFlagClear::MyDTI cQuestSvReqQuestCompleteFlagClear::DTI("cQuestSvReqQuestCompleteFlagClear", &::cQuestSvRequest::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSvReqQuestCompleteFlagClear::MyDTI::newInstance() const {
    DDON_STUB("cQuestSvReqQuestCompleteFlagClear::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestSvReqQuestOrder::getDTI() const {
    return cQuestSvReqQuestOrder::DTI;
}

u32 cQuestSvReqQuestOrder::getComId() const {
    return 130;
}

__attribute__((weak)) bool cQuestSvReqQuestOrder::serverRequest() const {
    DDON_STUB("cQuestSvReqQuestOrder::serverRequest")
    return {};
}

bool cQuestSvReqQuestOrder::isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const {
    bool t0 = scheduleId.nQuest::SCHEDULE_ID::operator==(mScheduleId);
    return t0;
}

inline cQuestSvReqQuestOrder::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqQuestOrder::MyDTI cQuestSvReqQuestOrder::DTI("cQuestSvReqQuestOrder", &::cQuestSvRequest::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSvReqQuestOrder::MyDTI::newInstance() const {
    DDON_STUB("cQuestSvReqQuestOrder::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestSvReqQuestProgress::getDTI() const {
    return cQuestSvReqQuestProgress::DTI;
}

u32 cQuestSvReqQuestProgress::getComId() const {
    return 131;
}

__attribute__((weak)) bool cQuestSvReqQuestProgress::serverRequest() const {
    DDON_STUB("cQuestSvReqQuestProgress::serverRequest")
    return {};
}

bool cQuestSvReqQuestProgress::isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const {
    bool t0 = scheduleId.nQuest::SCHEDULE_ID::operator==(mScheduleId);
    return t0;
}

void cQuestSvReqQuestProgress::resetParam() {
    MtObject* v0_3 = mpFromClass;
    if (v0_3 != nullptr) {
        const MtDTI& t0 = v0_3->getDTI();
        MT_CTSTR v0_1 = cQuestTask::cQuestProcess::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cQuestTask::cQuestProcess*>(v0_3)->resetProgressParam();
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

inline cQuestSvReqQuestProgress::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqQuestProgress::MyDTI cQuestSvReqQuestProgress::DTI("cQuestSvReqQuestProgress", &::cQuestSvRequest::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSvReqQuestProgress::MyDTI::newInstance() const {
    DDON_STUB("cQuestSvReqQuestProgress::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestSvReqSendLeaderQuestOrderConditionInfo::getDTI() const {
    return cQuestSvReqSendLeaderQuestOrderConditionInfo::DTI;
}

u32 cQuestSvReqSendLeaderQuestOrderConditionInfo::getComId() const {
    return 53;
}

bool cQuestSvReqSendLeaderQuestOrderConditionInfo::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->sendLeaderQuestOrderConditionInfo(mOrderConditionInfoList);
}

cQuestSvReqSendLeaderQuestOrderConditionInfo::~cQuestSvReqSendLeaderQuestOrderConditionInfo() {
    if (mOrderConditionInfoList.mLength != 0) {
        u32 v0_0 = mOrderConditionInfoList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mOrderConditionInfoList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mOrderConditionInfoList.mpArray[i0_3];
                v1_0 = mOrderConditionInfoList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mOrderConditionInfoList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mOrderConditionInfoList.mpArray));
    }
    mOrderConditionInfoList.mpArray = nullptr;
    mOrderConditionInfoList.mBufsiz = 0;
    mOrderConditionInfoList.mLength = 0;
}

inline cQuestSvReqSendLeaderQuestOrderConditionInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqSendLeaderQuestOrderConditionInfo::MyDTI cQuestSvReqSendLeaderQuestOrderConditionInfo::DTI("cQuestSvReqSendLeaderQuestOrderConditionInfo", &::cQuestSvRequest::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSvReqSendLeaderQuestOrderConditionInfo::MyDTI::newInstance() const {
    DDON_STUB("cQuestSvReqSendLeaderQuestOrderConditionInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestSvReqSendLeaderWaitOrderQuestList::getDTI() const {
    return cQuestSvReqSendLeaderWaitOrderQuestList::DTI;
}

u32 cQuestSvReqSendLeaderWaitOrderQuestList::getComId() const {
    return 54;
}

bool cQuestSvReqSendLeaderWaitOrderQuestList::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->sendLeaderWaitOrderQuestList(mScheduleIdList);
}

cQuestSvReqSendLeaderWaitOrderQuestList::~cQuestSvReqSendLeaderWaitOrderQuestList() {
    if (mScheduleIdList.mLength != 0) {
        u32 v0_0 = mScheduleIdList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mScheduleIdList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mScheduleIdList.mpArray[i0_3];
                v1_0 = mScheduleIdList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mScheduleIdList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mScheduleIdList.mpArray));
    }
    mScheduleIdList.mpArray = nullptr;
    mScheduleIdList.mBufsiz = 0;
    mScheduleIdList.mLength = 0;
}

inline cQuestSvReqSendLeaderWaitOrderQuestList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqSendLeaderWaitOrderQuestList::MyDTI cQuestSvReqSendLeaderWaitOrderQuestList::DTI("cQuestSvReqSendLeaderWaitOrderQuestList", &::cQuestSvRequest::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSvReqSendLeaderWaitOrderQuestList::MyDTI::newInstance() const {
    DDON_STUB("cQuestSvReqSendLeaderWaitOrderQuestList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestSvReqStartQuestTime::getDTI() const {
    return cQuestSvReqStartQuestTime::DTI;
}

u32 cQuestSvReqStartQuestTime::getComId() const {
    return 196;
}

bool cQuestSvReqStartQuestTime::serverRequest() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->startQuestTime();
}

inline cQuestSvReqStartQuestTime::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvReqStartQuestTime::MyDTI cQuestSvReqStartQuestTime::DTI("cQuestSvReqStartQuestTime", &::cQuestSvRequest::DTI, 40ul, 0u, 0u);

MtObject* cQuestSvReqStartQuestTime::MyDTI::newInstance() const {
    return new (16u) cQuestSvReqStartQuestTime;
}

cQuestSvRequest& cQuestSvRequest::setFromClass(MtObject* pFrom) {
    mpFromClass = pFrom;
    return *this;
}

const MtObject* cQuestSvRequest::getFromClass() const {
    return mpFromClass;
}

cQuestSvRequest& cQuestSvRequest::setCallbackFunc(cQuestSvRequest::PCallbackFunc pCallbackFunc) {
    mpCallbackFunc = pCallbackFunc;
    return *this;
}

bool cQuestSvRequest::isDelete() const {
    return mRno0 == 3;
}

bool cQuestSvRequest::isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const {
    return false;
}

bool cQuestSvRequest::waitsResult() const {
    return mRno0 == 2;
}

__attribute__((weak)) void cQuestSvRequest::resetParam() {
}

__attribute__((weak)) void cQuestSvRequest::executeCallbackFunc(u32 errorCode) {
    DDON_STUB("cQuestSvRequest::executeCallbackFunc")
    /* stub */
}

__attribute__((weak)) void cQuestSvRequest::createProperty(MtPropertyList& s) {
}

MtUI* cQuestSvRequest::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cQuestSvRequest::move() {
    DDON_STUB("cQuestSvRequest::move")
    /* stub */
}

inline cQuestSvRequest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvRequest::MyDTI cQuestSvRequest::DTI("cQuestSvRequest", &::MtObject::DTI, 40ul, 0u, 1u);

MtObject* cQuestSvRequest::MyDTI::newInstance() const {
    return nullptr;
}

template MtTypedArray<CDataOrderConditionInfo>::~MtTypedArray();

