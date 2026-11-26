// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cLightQuestManager.h"
#include "Protocol/PacketData/Common.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCharset.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Quest.h"
#include "Protocol/UserSession/S2C.h"
#include "cNetGameServer.h"
#include "cQuestManagerBase.h"
#include "cQuestSvRequest.h"
#include "cQuestSvRequestManager.h"
#include "cQuestTask.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "sSetManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cLightQuestManager::getDTI() const {
    return cLightQuestManager::DTI;
}

inline MtAllocator* cLightQuestManager::getAllocator() {
    return MtMemoryAllocator::getAllocator(cLightQuestManager::DTI);
}

void* cLightQuestManager::operator new(size_t sz, u32 align) {
    return cLightQuestManager::getAllocator()->memAlloc(sz, align, cLightQuestManager::DTI.getID());
}

inline void cLightQuestManager::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cLightQuestManager::DTI)->memFree(p_addr);
}

u32 cLightQuestManager::getQuestManagerType() const {
    return 2;
}

__attribute__((weak)) cLightQuestManager::cLightQuestInfo* cLightQuestManager::getLightQuestInfo(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("cLightQuestManager::getLightQuestInfo")
    return nullptr;
}

__attribute__((weak)) cLightQuestManager::cLightQuestInfo* cLightQuestManager::getLightQuestInfo(nQuest::QUEST_ID questId) const {
    DDON_STUB("cLightQuestManager::getLightQuestInfo")
    return nullptr;
}

__attribute__((weak)) u32 cLightQuestManager::getLightQuestTargetNumNow(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("cLightQuestManager::getLightQuestTargetNumNow")
    return {};
}

bool cLightQuestManager::isFinishedQuesetOrder() const {
    return !mIsReqOrderQuest;
}

void cLightQuestManager::move() {
    this->cQuestManagerBase::move();
}

__attribute__((weak)) void cLightQuestManager::getQuestList() {
    DDON_STUB("cLightQuestManager::getQuestList")
    /* stub */
}

__attribute__((weak)) void cLightQuestManager::registTask(const LightQuestOrderListVec& list) {
    DDON_STUB("cLightQuestManager::registTask")
    /* stub */
}

__attribute__((weak)) void cLightQuestManager::requestOrderQuest(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("cLightQuestManager::requestOrderQuest")
    /* stub */
}

__attribute__((weak)) void cLightQuestManager::callbackOrder(u32 errorCode) {
    DDON_STUB("cLightQuestManager::callbackOrder")
    /* stub */
}

void cLightQuestManager::requestGpComplete() {
    cQuestSvRequest* t0 = cQuestSvRequestManager::pushRequest(cQuestSvReqGpCompleteLightQuestList::DTI);
    if (t0 != nullptr) {
        t0->setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvRequest::PCallbackFunc>(&::cLightQuestManager::callbackGpComplete));
    }
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t0) + 40) = mQuestBoardBaseId;
    mIsReqGpComplete = true;
}

__attribute__((weak)) void cLightQuestManager::callbackGpComplete(u32 errorCode) {
    DDON_STUB("cLightQuestManager::callbackGpComplete")
    /* stub */
}

__attribute__((weak)) void cLightQuestManager::callbackGetLightQuestList(u32 errorCode) {
    DDON_STUB("cLightQuestManager::callbackGetLightQuestList")
    /* stub */
}

__attribute__((weak)) void cLightQuestManager::addLightQuestInfo(nQuest::SCHEDULE_ID scheduleId, nQuest::QUEST_ID questId, CLightQuestList* pNode) {
    DDON_STUB("cLightQuestManager::addLightQuestInfo")
    /* stub */
}

__attribute__((weak)) void cLightQuestManager::addLightQuestInfo(nQuest::SCHEDULE_ID scheduleId, nQuest::QUEST_ID questId, CLightQuestOrderList* pNode) {
    DDON_STUB("cLightQuestManager::addLightQuestInfo")
    /* stub */
}

__attribute__((weak)) void cLightQuestManager::forceDeleteNotOrder() {
    DDON_STUB("cLightQuestManager::forceDeleteNotOrder")
    /* stub */
}

cLightQuestManager::cLightQuestManager() : cQuestManagerBase("Board quest") {
    mQuestBoardBaseId = 1;
    mIsReqOrderQuest = false;
    mCompleteGp = 0;
    mIsGpComplete = false;
    mIsReqGpComplete = false;
    mNotCompleteQuestNum = 0;
    mGpCompleteErrorCode = 0;
}

cLightQuestManager::~cLightQuestManager() {
    if (mLightQuestInfo.mLength != 0) {
        u32 v0_0 = mLightQuestInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mLightQuestInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mLightQuestInfo.mpArray[i0_3];
                v1_0 = mLightQuestInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mLightQuestInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mLightQuestInfo.mpArray));
    }
    mLightQuestInfo.mpArray = nullptr;
    mLightQuestInfo.mBufsiz = 0;
    mLightQuestInfo.mLength = 0;
}

inline cLightQuestManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cLightQuestManager::MyDTI cLightQuestManager::DTI("cLightQuestManager", &::cQuestManagerBase::DTI, 104ul, 0u, 0u);

MtObject* cLightQuestManager::MyDTI::newInstance() const {
    return new (16u) cLightQuestManager;
}

const MtDTI& cLightQuestManager::cLightQuestInfo::getDTI() const {
    return cLightQuestManager::cLightQuestInfo::DTI;
}

inline void* cLightQuestManager::cLightQuestInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cLightQuestManager::cLightQuestInfo::DTI)->memAlloc(sz, align, cLightQuestManager::cLightQuestInfo::DTI.getID());
}

cLightQuestManager::cLightQuestInfo::~cLightQuestInfo() {
}

inline cLightQuestManager::cLightQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cLightQuestManager::cLightQuestInfo::MyDTI cLightQuestManager::cLightQuestInfo::DTI("cLightQuestManager::cLightQuestInfo", &::MtObject::DTI, 72ul, 0u, 0u);

MtObject* cLightQuestManager::cLightQuestInfo::MyDTI::newInstance() const {
    return new (16u) cLightQuestManager::cLightQuestInfo;
}

template MtTypedArray<CDataQuestProcessState>::~MtTypedArray();

template MtTypedArray<cLightQuestManager::cLightQuestInfo>::~MtTypedArray();

