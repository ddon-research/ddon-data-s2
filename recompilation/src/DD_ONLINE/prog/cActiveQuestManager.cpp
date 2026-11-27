// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cActiveQuestManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "Protocol/PacketData/Quest.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestSvRequest.h"
#include "cQuestSvRequestManager.h"
#include "nQuest.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cActiveQuestManager::getDTI() const {
    return cActiveQuestManager::DTI;
}

void* cActiveQuestManager::operator new(size_t sz, u32 align) {
    return cActiveQuestManager::getAllocator()->memAlloc(sz, align, cActiveQuestManager::DTI.getID());
}

__attribute__((weak)) bool cActiveQuestManager::isActiveQuest(nQuest::SCHEDULE_ID scheduleId, u32* pIdx, s32 dispType) const {
    DDON_STUB("cActiveQuestManager::isActiveQuest")
    return {};
}

nQuest::ACTIVE_QUEST_TYPE cActiveQuestManager::getActiveQuestDispType() const {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLeaderCharacterId == static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLobbyCharacterId) {
        return static_cast<nQuest::ACTIVE_QUEST_TYPE>(static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->getGameSessionPlayerMemberNum(true) > 1);
    } else {
        return nQuest::ACTIVE_QUEST_TYPE_PARTY;
    }
}

__attribute__((weak)) nQuest::SCHEDULE_ID cActiveQuestManager::getActiveQuest(u32 idx) const {
    DDON_STUB("cActiveQuestManager::getActiveQuest")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::SCHEDULE_ID cActiveQuestManager::getActiveQuest(nQuest::ACTIVE_QUEST_TYPE dispType, u32 idx) const {
    DDON_STUB("cActiveQuestManager::getActiveQuest")
    __builtin_unreachable();
}

__attribute__((weak)) bool cActiveQuestManager::setActiveQuest(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("cActiveQuestManager::setActiveQuest")
    return {};
}

void cActiveQuestManager::callbackRequestSetActiveQuest() {
    mIsRequestEnable = false;
    mRequestNum = mRequestNum + 1u;
}

__attribute__((weak)) u32 cActiveQuestManager::getActiveQuestNum(nQuest::ACTIVE_QUEST_TYPE dispType) const {
    DDON_STUB("cActiveQuestManager::getActiveQuestNum")
    return {};
}

void cActiveQuestManager::requestGetActiveQuest() {
    cQuestSvRequest* pReq = cQuestSvRequestManager::pushRequest(cQuestSvReqGetActiveQuest::DTI);
    if (pReq != nullptr) {
        pReq->setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvRequest::PCallbackFunc>(&::cActiveQuestManager::callbackGetActiveQuest));
    }
    mIsRequestEnable = false;
}

__attribute__((weak)) void cActiveQuestManager::cancelActiveQuest(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("cActiveQuestManager::cancelActiveQuest")
    /* stub */
}

void cActiveQuestManager::deleteActiveQuest(u32 characterId) {
    cActiveQuestData* p0_0 = mpActiveQuestList;
    for (unsigned int i0_1 = 0; i0_1 <= 7u; p0_0 += 1, i0_1 += 1u) {
        if (p0_0->mCharacterId == characterId) {
            p0_0->mScheduleId[1] = 0;
            p0_0->mScheduleId[2] = 0;
            p0_0->mCharacterId = 0;
            p0_0->mScheduleId[0] = 0;
            return;
        }
    }
}

void cActiveQuestManager::deleteActiveQuestAll() {
    cActiveQuestData* t0 = mpActiveQuestList;
    t0->mScheduleId[1] = 0;
    t0->mScheduleId[2] = 0;
    t0->mCharacterId = 0;
    t0->mScheduleId[0] = 0;
    cActiveQuestData* t1 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 40) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 32) = 0;
    cActiveQuestData* t2 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t2) + 64) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t2) + 56) = 0;
    cActiveQuestData* t3 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t3) + 88) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t3) + 80) = 0;
    cActiveQuestData* t4 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t4) + 112) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t4) + 104) = 0;
    cActiveQuestData* t5 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t5) + 136) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t5) + 128) = 0;
    cActiveQuestData* t6 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t6) + 160) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t6) + 152) = 0;
    cActiveQuestData* t7 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t7) + 184) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t7) + 176) = 0;
}

__attribute__((weak)) void cActiveQuestManager::callbackNoticeSetActiveQuest(u32 characterId, const PriorityQuestVec& priorityQuestList) {
    DDON_STUB("cActiveQuestManager::callbackNoticeSetActiveQuest")
    /* stub */
}

void cActiveQuestManager::release() {
    cActiveQuestData* t0 = mpActiveQuestList;
    t0->mScheduleId[1] = 0;
    t0->mScheduleId[2] = 0;
    t0->mCharacterId = 0;
    t0->mScheduleId[0] = 0;
    cActiveQuestData* t1 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 40) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 32) = 0;
    cActiveQuestData* t2 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t2) + 64) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t2) + 56) = 0;
    cActiveQuestData* t3 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t3) + 88) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t3) + 80) = 0;
    cActiveQuestData* t4 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t4) + 112) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t4) + 104) = 0;
    cActiveQuestData* t5 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t5) + 136) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t5) + 128) = 0;
    cActiveQuestData* t6 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t6) + 160) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t6) + 152) = 0;
    cActiveQuestData* t7 = mpActiveQuestList;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t7) + 184) = 0;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t7) + 176) = 0;
    mRequestNum = 0;
}

bool cActiveQuestManager::isEnableRequest() const {
    return mIsRequestEnable;
}

bool cActiveQuestManager::isEnableRequestNum() const {
    const u32 t0 = mRequestNum;
    u32 t1 = getActiveQuestNum(nQuest::ACTIVE_QUEST_TYPE_MYSELF);
    return (t0 + t1) <= 2u;
}

void cActiveQuestManager::registActiveQuestList(const PriorityQuestVec& priorityQuestList) {
    callbackNoticeSetActiveQuest(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getCharacterId(), priorityQuestList);
}

__attribute__((weak)) void cActiveQuestManager::callbackGetActiveQuest(u32 errorCode) {
    DDON_STUB("cActiveQuestManager::callbackGetActiveQuest")
    /* stub */
}

void cActiveQuestManager::callbackSetActiveQuest(u32 errorCode) {
    mIsRequestEnable = true;
    mRequestNum = mRequestNum - 1u;
}

void cActiveQuestManager::callbackCancelActiveQuest(u32 errorCode) {
    mIsRequestEnable = true;
    if (errorCode == 0) {
        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getCancelPriorityQuestPacket();
    }
}

cActiveQuestManager::cActiveQuestManager() {
    DDON_STUB("cActiveQuestManager::cActiveQuestManager")
    /* stub */
}

cActiveQuestManager::~cActiveQuestManager() {
    if (mpActiveQuestList == nullptr) {
        return;
    }
    delete[] mpActiveQuestList;
    mpActiveQuestList = nullptr;
}

__attribute__((weak)) void cActiveQuestManager::createProperty(MtPropertyList& s) {
}

inline cActiveQuestManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cActiveQuestManager::MyDTI cActiveQuestManager::DTI("cActiveQuestManager", &::cQuestFunctionManagerBase::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cActiveQuestManager::MyDTI::newInstance() const {
    DDON_STUB("cActiveQuestManager::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cActiveQuestManager::cActiveQuestData::getDTI() const {
    return cActiveQuestManager::cActiveQuestData::DTI;
}

cActiveQuestManager::cActiveQuestData::~cActiveQuestData() {
}

__attribute__((weak)) void cActiveQuestManager::cActiveQuestData::createProperty(MtPropertyList& s) {
}

inline cActiveQuestManager::cActiveQuestData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cActiveQuestManager::cActiveQuestData::MyDTI cActiveQuestManager::cActiveQuestData::DTI("cActiveQuestManager::cActiveQuestData", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cActiveQuestManager::cActiveQuestData::MyDTI::newInstance() const {
    return new (16u) cActiveQuestManager::cActiveQuestData;
}

