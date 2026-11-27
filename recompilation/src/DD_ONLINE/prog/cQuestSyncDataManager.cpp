// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestSyncDataManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "nDDOUtility.h"
#include "nNet.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestSyncDataManager::getDTI() const {
    return cQuestSyncDataManager::DTI;
}

__attribute__((weak)) void cQuestSyncDataManager::clear(bool IsLeaveParty) {
    DDON_STUB("cQuestSyncDataManager::clear")
    /* stub */
}

void cQuestSyncDataManager::reset() {
    mQuestScheduleId.mScheduleId = nQuest::INVALID_SCHEDULE_ID.mScheduleId;
    mProcessNo = 0;
    mBlockNo = 0;
    mFlagNo = nNetSv::PARTY_SYNC_NUM;
}

__attribute__((weak)) void cQuestSyncDataManager::onFlagMySelf() {
    DDON_STUB("cQuestSyncDataManager::onFlagMySelf")
    /* stub */
}

__attribute__((weak)) void cQuestSyncDataManager::offFlagMySelf() {
    DDON_STUB("cQuestSyncDataManager::offFlagMySelf")
    /* stub */
}

__attribute__((weak)) void cQuestSyncDataManager::offFlagMySelfAll() {
    DDON_STUB("cQuestSyncDataManager::offFlagMySelfAll")
    /* stub */
}

__attribute__((weak)) bool cQuestSyncDataManager::isSuccessSync() {
    DDON_STUB("cQuestSyncDataManager::isSuccessSync")
    return {};
}

__attribute__((weak)) bool cQuestSyncDataManager::checkFlagMyself() {
    DDON_STUB("cQuestSyncDataManager::checkFlagMyself")
    return {};
}

cQuestSyncDataManager::cQuestSyncDataManager() {
    DDON_STUB("cQuestSyncDataManager::cQuestSyncDataManager")
    /* stub */
}

cQuestSyncDataManager::~cQuestSyncDataManager() {
}

void cQuestSyncDataManager::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mOnMemberNum", &mOnMemberNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestScheduleId", static_cast<MtObject*>(&mQuestScheduleId), 0u, 0u);
}

inline cQuestSyncDataManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSyncDataManager::MyDTI cQuestSyncDataManager::DTI("cQuestSyncDataManager", &::MtObject::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSyncDataManager::MyDTI::newInstance() const {
    DDON_STUB("cQuestSyncDataManager::MyDTI::newInstance")
    return nullptr;
}

