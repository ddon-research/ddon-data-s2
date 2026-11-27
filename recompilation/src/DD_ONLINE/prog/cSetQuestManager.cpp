// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cSetQuestManager.h"
#include "Protocol/PacketData/AreaMaster.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "Protocol/PacketData/Quest.h"
#include "Protocol/UserSession/S2C.h"
#include "cNetGameServer.h"
#include "cQuestManagerBase.h"
#include "cQuestSvRequest.h"
#include "cQuestSvRequestManager.h"
#include "cQuestTask.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSetQuestManager::getDTI() const {
    return cSetQuestManager::DTI;
}

void* cSetQuestManager::operator new(size_t sz, u32 align) {
    return cSetQuestManager::getAllocator()->memAlloc(sz, align, cSetQuestManager::DTI.getID());
}

u32 cSetQuestManager::getQuestManagerType() const {
    return 1;
}

__attribute__((weak)) void cSetQuestManager::getQuestList(u32 setQstDistId) {
    DDON_STUB("cSetQuestManager::getQuestList")
    /* stub */
}

__attribute__((weak)) void cSetQuestManager::registQuestList() {
    DDON_STUB("cSetQuestManager::registQuestList")
    /* stub */
}

__attribute__((weak)) void cSetQuestManager::registTask(u32 distId, const SetQuestListVec& list) {
    DDON_STUB("cSetQuestManager::registTask")
    /* stub */
}

__attribute__((weak)) void cSetQuestManager::registTask(const SetQuestOrderListVec& list) {
    DDON_STUB("cSetQuestManager::registTask")
    /* stub */
}

void cSetQuestManager::callbackClear(nQuest::SCHEDULE_ID scheduleId, bool isParty) {
    this->cQuestManagerBase::callbackClear(scheduleId, isParty);
}

__attribute__((weak)) void cSetQuestManager::cancelWaitOrder(cQuestTask* pTask, bool& isReqCancel) {
    DDON_STUB("cSetQuestManager::cancelWaitOrder")
    /* stub */
}

__attribute__((weak)) void cSetQuestManager::callbackGetSetQuestList(u32 characterId, u32 setQuestDistId) {
    DDON_STUB("cSetQuestManager::callbackGetSetQuestList")
    /* stub */
}

__attribute__((weak)) void cSetQuestManager::resetPartyMemberInfo() {
    DDON_STUB("cSetQuestManager::resetPartyMemberInfo")
    /* stub */
}

void cSetQuestManager::resetPartyMemberInfo(u32 characterId) {
    callbackGetSetQuestList(characterId, 0u);
    cMemberInfo* v0_0 = mpMemberInfo;
    cMemberInfo* p0_1 = v0_0;
    for (unsigned int i0_3 = 0; i0_3 <= 7u; p0_1 += 1, i0_3 = i0_3 + 1u) {
        if (p0_1->mCharacterId == characterId) {
            p0_1->mCharacterId = 0;
            v0_0[i0_3].mSetQuestDistributeId = 0;
            return;
        }
    }
}

__attribute__((weak)) void cSetQuestManager::callbackGetAreaQuestInfoList(u32 errorCode) {
    DDON_STUB("cSetQuestManager::callbackGetAreaQuestInfoList")
    /* stub */
}

__attribute__((weak)) void cSetQuestManager::getQuestList() {
    DDON_STUB("cSetQuestManager::getQuestList")
    /* stub */
}

cSetQuestManager::~cSetQuestManager() {
    if (mpMemberInfo == nullptr) {
        return;
    }
    delete[] mpMemberInfo;
    mpMemberInfo = nullptr;
}

inline cSetQuestManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSetQuestManager::MyDTI cSetQuestManager::DTI("cSetQuestManager", &::cQuestManagerBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cSetQuestManager::MyDTI::newInstance() const {
    DDON_STUB("cSetQuestManager::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cSetQuestManager::cMemberInfo::getDTI() const {
    return cSetQuestManager::cMemberInfo::DTI;
}

cSetQuestManager::cMemberInfo::~cMemberInfo() {
}

inline cSetQuestManager::cMemberInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSetQuestManager::cMemberInfo::MyDTI cSetQuestManager::cMemberInfo::DTI("cSetQuestManager::cMemberInfo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cSetQuestManager::cMemberInfo::MyDTI::newInstance() const {
    return new (16u) cSetQuestManager::cMemberInfo;
}

