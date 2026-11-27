// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cTutorialQuestManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "Protocol/PacketData/Quest.h"
#include "cNetGameServer.h"
#include "cQuestManagerBase.h"
#include "cQuestSvRequest.h"
#include "cQuestSvRequestManager.h"
#include "cQuestTask.h"
#include "nQuest.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cTutorialQuestManager::getDTI() const {
    return cTutorialQuestManager::DTI;
}

void* cTutorialQuestManager::operator new(size_t sz, u32 align) {
    return cTutorialQuestManager::getAllocator()->memAlloc(sz, align, cTutorialQuestManager::DTI.getID());
}

u32 cTutorialQuestManager::getQuestManagerType() const {
    return 3;
}

__attribute__((weak)) void cTutorialQuestManager::getQuestList(u32 stageNo) {
    DDON_STUB("cTutorialQuestManager::getQuestList")
    /* stub */
}

__attribute__((weak)) void cTutorialQuestManager::registQuestList() {
    DDON_STUB("cTutorialQuestManager::registQuestList")
    /* stub */
}

__attribute__((weak)) void cTutorialQuestManager::callbackClear(nQuest::SCHEDULE_ID scheduleId, bool isParty) {
    DDON_STUB("cTutorialQuestManager::callbackClear")
    /* stub */
}

__attribute__((weak)) void cTutorialQuestManager::registTask(const TutorialQuestOrderListVec& list) {
    DDON_STUB("cTutorialQuestManager::registTask")
    /* stub */
}

void cTutorialQuestManager::release() {
    this->cQuestManagerBase::release();
    mStageNo = 0;
}

cTutorialQuestManager::cTutorialQuestManager() : cQuestManagerBase("Tutorual quest") {
    mStageNo = 0;
}

inline cTutorialQuestManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cTutorialQuestManager::MyDTI cTutorialQuestManager::DTI("cTutorialQuestManager", &::cQuestManagerBase::DTI, 48ul, 0u, 0u);

MtObject* cTutorialQuestManager::MyDTI::newInstance() const {
    return new (16u) cTutorialQuestManager;
}

