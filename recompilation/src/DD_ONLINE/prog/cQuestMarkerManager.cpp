// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestMarkerManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cEndContentsManager.h"
#include "cGUIFloorManager.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestTask.h"
#include "../../XFramework/cResource.h"
#include "nLayout.h"
#include "nMarker.h"
#include "nQuest.h"
#include "rFieldAreaList.h"
#include "rFieldAreaMarkerInfo.h"
#include "rQuestMarkerInfo.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sControlManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMarker.h"
#include "sNpcManager.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uNpc.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestMarkerManager::getDTI() const {
    return cQuestMarkerManager::DTI;
}

void* cQuestMarkerManager::operator new(size_t sz, u32 align) {
    return cQuestMarkerManager::getAllocator()->memAlloc(sz, align, cQuestMarkerManager::DTI.getID());
}

__attribute__((weak)) void cQuestMarkerManager::callbackChangeFieldArea(const rFieldAreaList::cFieldAreaInfo* pFieldAreaInfo) {
    DDON_STUB("cQuestMarkerManager::callbackChangeFieldArea")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::callbackChangeStage(s32 stageNo) {
    DDON_STUB("cQuestMarkerManager::callbackChangeStage")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::callbackChangeResourceCore(cQuestMarkerManager::DATA_TYPE dataType, u32 stageNo) {
    DDON_STUB("cQuestMarkerManager::callbackChangeResourceCore")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::loadQuestSetMarker(nQuest::QUEST_ID questId) {
    DDON_STUB("cQuestMarkerManager::loadQuestSetMarker")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::releaseQuestSetMarker(nQuest::QUEST_ID questId) {
    DDON_STUB("cQuestMarkerManager::releaseQuestSetMarker")
    /* stub */
}

const MtTypedArray<nQuest::cQuestMarker>& cQuestMarkerManager::getQuestMarker() const {
    return mMarkerDispList[0];
}

const MtTypedArray<nQuest::cQuestMarker>& cQuestMarkerManager::getQuestMarkerForMap() const {
    return mMarkerDispList[1];
}

void cQuestMarkerManager::removeMarker(nQuest::SCHEDULE_ID scheduleId) {
    removeMarker(scheduleId, -1);
}

__attribute__((weak)) void cQuestMarkerManager::removeMarker(nQuest::SCHEDULE_ID scheduleId, s32 processNo) {
    DDON_STUB("cQuestMarkerManager::removeMarker")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::removeMarkerAtReturnAreaPos(nQuest::SCHEDULE_ID scheduleId, s32 processNo, u32 stageNo, u32 groupNo) {
    DDON_STUB("cQuestMarkerManager::removeMarkerAtReturnAreaPos")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtNpcPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 npcNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtNpcPos")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtNpcPosQuestSet(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 setNo, u32 setQuestId) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtNpcPosQuestSet")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtNpcUnit(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 setNo, u32 setQuestId) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtNpcUnit")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtScenarioPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 sceNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtScenarioPos")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtReturnAreaPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 markerDispType) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtReturnAreaPos")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtQuestOmPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 setNo, u32 questId) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtQuestOmPos")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtLayoutOmPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 setNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtLayoutOmPos")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtStage(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtStage")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtPrt(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, const MtVector3& pos) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtPrt")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtWhiteDragon(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtWhiteDragon")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtQuestBoard(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtQuestBoard")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtWarpPoint(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 warpPointId) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtWarpPoint")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtArchibald(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtArchibald")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtWarehouse(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtWarehouse")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtMyRoomRimStone(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtMyRoomRimStone")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtMyRoomPartner(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtMyRoomPartner")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtClanQuestBoard(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtClanQuestBoard")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerAtRenten(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo) {
    DDON_STUB("cQuestMarkerManager::addMarkerAtRenten")
    /* stub */
}

__attribute__((weak)) bool cQuestMarkerManager::hasMarkerNpc(nQuest::SCHEDULE_ID scheduleId, u32 npcId, nQuest::QUEST_ID setQuestId) const {
    DDON_STUB("cQuestMarkerManager::hasMarkerNpc")
    return {};
}

__attribute__((weak)) nQuest::SCHEDULE_ID cQuestMarkerManager::getScheduleIdFromMarkerType(nQuest::MARKER_DISP_TYPE type) const {
    DDON_STUB("cQuestMarkerManager::getScheduleIdFromMarkerType")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::SCHEDULE_ID cQuestMarkerManager::getScheduleIdFromMarkerWarpPoint(u32 warpPointId) const {
    DDON_STUB("cQuestMarkerManager::getScheduleIdFromMarkerWarpPoint")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::cQuestMarker* cQuestMarkerManager::getQuestMarkerEm(nQuest::SCHEDULE_ID scheduleId, uCharacter* pEm) const {
    DDON_STUB("cQuestMarkerManager::getQuestMarkerEm")
    return nullptr;
}

__attribute__((weak)) void cQuestMarkerManager::addMarkerTask(cQuestMarkerManager::cMarkerTask* pTask) {
    DDON_STUB("cQuestMarkerManager::addMarkerTask")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::addDispMarkerList(nQuest::QuestMarkerArray& dispMarkerList, const cQuestMarkerManager::MarkerDataArray& src, bool enableQuestMarker) const {
    DDON_STUB("cQuestMarkerManager::addDispMarkerList")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::move() {
    DDON_STUB("cQuestMarkerManager::move")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::updateDisp() {
    DDON_STUB("cQuestMarkerManager::updateDisp")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::callbackActiveQuest(cQuestEventArg* pArg) {
    DDON_STUB("cQuestMarkerManager::callbackActiveQuest")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::callbackOrderQuest(cQuestEventArg* pArg) {
    DDON_STUB("cQuestMarkerManager::callbackOrderQuest")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::callbackBuyHint(cQuestEventArg* pArg) {
    DDON_STUB("cQuestMarkerManager::callbackBuyHint")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::callbackKilledEnemy(cQuestEventArg* pArg) {
    DDON_STUB("cQuestMarkerManager::callbackKilledEnemy")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::callbackContentsPlayStart(cQuestEventArg* pArg) {
    DDON_STUB("cQuestMarkerManager::callbackContentsPlayStart")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::callbackUpdateCache(cQuestEventArg* pArg) {
    DDON_STUB("cQuestMarkerManager::callbackUpdateCache")
    /* stub */
}

cQuestMarkerManager::cQuestMarkerManager() {
    DDON_STUB("cQuestMarkerManager::cQuestMarkerManager")
    /* stub */
}

__attribute__((noinline)) cQuestMarkerManager::~cQuestMarkerManager() {
    DDON_STUB("cQuestMarkerManager::~cQuestMarkerManager")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::createProperty(MtPropertyList& s) {
}

MtUI* cQuestMarkerManager::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cQuestMarkerManager::release() {
    if (mSetupQuestListMarker.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSetupQuestListMarker.mpArray));
    }
    mSetupQuestListMarker.mpArray = nullptr;
    mSetupQuestListMarker.mLength = 0;
    mSetupQuestListMarker.mBufsiz = 0;
    if (mSetupMarkerData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSetupMarkerData.mpArray));
    }
    mSetupMarkerData.mpArray = nullptr;
    mSetupMarkerData.mLength = 0;
    mSetupMarkerData.mBufsiz = 0;
    if (mSetupMapGroupNo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSetupMapGroupNo.mpArray));
    }
    mSetupMapGroupNo.mpArray = nullptr;
    mSetupMapGroupNo.mBufsiz = 0;
    mSetupMapGroupNo.mLength = 0;
    mCurrentStageNo = 0;
    mpNpcUnitMarkerData[0] = nullptr;
    if (mMarkerData[0].mLength != 0) {
        u32 v0_0 = mMarkerData[0].mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMarkerData[0].mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMarkerData[0].mpArray[i0_3];
                v1_0 = mMarkerData[0].mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMarkerData[0].mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMarkerData[0].mpArray));
    }
    mMarkerData[0].mpArray = nullptr;
    mMarkerData[0].mBufsiz = 0;
    mMarkerData[0].mLength = 0;
    if (mMarkerDispList[0].mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMarkerDispList[0].mpArray));
    }
    mMarkerDispList[0].mpArray = nullptr;
    mMarkerDispList[0].mBufsiz = 0;
    mMarkerDispList[0].mLength = 0;
    mpNpcUnitMarkerData[1] = nullptr;
    if (mMarkerData[1].mLength != 0) {
        u32 v3_0 = mMarkerData[1].mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mMarkerData[1].mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mMarkerData[1].mpArray[i3_3];
                v4_0 = mMarkerData[1].mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMarkerData[1].mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMarkerData[1].mpArray));
    }
    mMarkerData[1].mpArray = nullptr;
    mMarkerData[1].mBufsiz = 0;
    mMarkerData[1].mLength = 0;
    if (mMarkerDispList[1].mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMarkerDispList[1].mpArray));
    }
    mMarkerDispList[1].mpArray = nullptr;
    mMarkerDispList[1].mLength = 0;
    mMarkerDispList[1].mBufsiz = 0;
    if (mMarkerTask.mLength != 0) {
        u32 v6_0 = mMarkerTask.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mMarkerTask.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mMarkerTask.mpArray[i6_3];
                v7_0 = mMarkerTask.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMarkerTask.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMarkerTask.mpArray));
    }
    mMarkerTask.mpArray = nullptr;
    mMarkerTask.mBufsiz = 0;
    mMarkerTask.mLength = 0;
}

inline cQuestMarkerManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestMarkerManager::MyDTI cQuestMarkerManager::DTI("cQuestMarkerManager", &::cQuestFunctionManagerBase::DTI, 384ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestMarkerManager::MyDTI::newInstance() const {
    DDON_STUB("cQuestMarkerManager::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestMarkerManager::cMarkerTask::getDTI() const {
    return cQuestMarkerManager::cMarkerTask::DTI;
}

__attribute__((weak)) nQuest::QUEST_ID cQuestMarkerManager::cMarkerTask::getTargetQuestId() const {
    DDON_STUB("cQuestMarkerManager::cMarkerTask::getTargetQuestId")
    __builtin_unreachable();
}

cQuestMarkerManager::cMarkerTask::~cMarkerTask() {
}

__attribute__((weak)) void cQuestMarkerManager::cMarkerTask::createProperty(MtPropertyList& s) {
}

MtUI* cQuestMarkerManager::cMarkerTask::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cQuestMarkerManager::cMarkerTask::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestMarkerManager::cMarkerTask::MyDTI cQuestMarkerManager::cMarkerTask::DTI("cQuestMarkerManager::cMarkerTask", &::MtObject::DTI, 96ul, 0u, 0u);

cQuestMarkerManager* cQuestMarkerManager::cMarkerTask::mpParent;

__attribute__((weak)) MtObject* cQuestMarkerManager::cMarkerTask::MyDTI::newInstance() const {
    DDON_STUB("cQuestMarkerManager::cMarkerTask::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestMarkerManager::cQuestSetMarkerInfoBase::getDTI() const {
    return cQuestMarkerManager::cQuestSetMarkerInfoBase::DTI;
}

cResource* cQuestMarkerManager::cQuestSetMarkerInfoBase::getMarkerInfoForNpc() const {
    return nullptr;
}

cResource* cQuestMarkerManager::cQuestSetMarkerInfoBase::getMarkerInfoForOm() const {
    return nullptr;
}

__attribute__((weak)) void cQuestMarkerManager::cQuestSetMarkerInfoBase::move() {
}

cQuestMarkerManager::cQuestSetMarkerInfoBase::~cQuestSetMarkerInfoBase() {
}

__attribute__((weak)) void cQuestMarkerManager::cQuestSetMarkerInfoBase::createProperty(MtPropertyList& s) {
}

inline cQuestMarkerManager::cQuestSetMarkerInfoBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestMarkerManager::cQuestSetMarkerInfoBase::MyDTI cQuestMarkerManager::cQuestSetMarkerInfoBase::DTI("cQuestMarkerManager::cQuestSetMarkerInfoBase", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cQuestMarkerManager::cQuestSetMarkerInfoBase::MyDTI::newInstance() const {
    return new (16u) cQuestMarkerManager::cQuestSetMarkerInfoBase;
}

const MtDTI& cQuestMarkerManager::cMarkerData::getDTI() const {
    return cQuestMarkerManager::cMarkerData::DTI;
}

__attribute__((weak)) void cQuestMarkerManager::cMarkerData::updateDisp() {
    DDON_STUB("cQuestMarkerManager::cMarkerData::updateDisp")
    /* stub */
}

__attribute__((weak)) bool cQuestMarkerManager::cMarkerData::isDispSameStage() {
    DDON_STUB("cQuestMarkerManager::cMarkerData::isDispSameStage")
    return {};
}

__attribute__((weak)) void cQuestMarkerManager::cMarkerData::setup() {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setup")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::cMarkerData::setupSameStage(nQuest::QuestMarkerArray& marker) {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setupSameStage")
    /* stub */
}

__attribute__((weak)) void cQuestMarkerManager::cMarkerData::setupOtherStage(nQuest::QuestMarkerArray& marker, u32 goalStage) const {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setupOtherStage")
    /* stub */
}

__attribute__((weak)) bool cQuestMarkerManager::cMarkerData::setupMarkerAtLayoutNpc(MtVector3& pos) const {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setupMarkerAtLayoutNpc")
    return {};
}

__attribute__((weak)) bool cQuestMarkerManager::cMarkerData::setupMarkerAtQuestNpc(MtVector3& pos) const {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setupMarkerAtQuestNpc")
    return {};
}

__attribute__((weak)) bool cQuestMarkerManager::cMarkerData::setupMarkerAtNpcUnit(MtVector3& pos) const {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setupMarkerAtNpcUnit")
    return {};
}

__attribute__((weak)) bool cQuestMarkerManager::cMarkerData::setupMarkerAtEnemyEncountArea(MtVector3& pos) const {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setupMarkerAtEnemyEncountArea")
    return {};
}

__attribute__((weak)) bool cQuestMarkerManager::cMarkerData::setupMarkerAtScenario(MtVector3& pos) const {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setupMarkerAtScenario")
    return {};
}

__attribute__((weak)) bool cQuestMarkerManager::cMarkerData::setupMarkerAtQuestOm(MtVector3& pos) const {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setupMarkerAtQuestOm")
    return {};
}

__attribute__((weak)) bool cQuestMarkerManager::cMarkerData::setupMarkerAtLayoutOm(MtVector3& pos) const {
    DDON_STUB("cQuestMarkerManager::cMarkerData::setupMarkerAtLayoutOm")
    return {};
}

cQuestMarkerManager::cMarkerData::~cMarkerData() {
    if (mMarker.mLength != 0) {
        u32 v0_0 = mMarker.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMarker.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMarker.mpArray[i0_3];
                v1_0 = mMarker.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMarker.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMarker.mpArray));
    }
    mMarker.mpArray = nullptr;
    mMarker.mBufsiz = 0;
    mMarker.mLength = 0;
    mpParent = nullptr;
}

__attribute__((weak)) void cQuestMarkerManager::cMarkerData::createProperty(MtPropertyList& s) {
}

inline cQuestMarkerManager::cMarkerData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestMarkerManager::cMarkerData::MyDTI cQuestMarkerManager::cMarkerData::DTI("cQuestMarkerManager::cMarkerData", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* cQuestMarkerManager::cMarkerData::MyDTI::newInstance() const {
    return new (16u) cQuestMarkerManager::cMarkerData;
}

const MtDTI& cQuestMarkerManager::cQuestSetMarkerInfoStage::getDTI() const {
    return cQuestMarkerManager::cQuestSetMarkerInfoStage::DTI;
}

cResource* cQuestMarkerManager::cQuestSetMarkerInfoStage::getMarkerInfoForNpc() const {
    return mpMarkerInfoNpc;
}

cResource* cQuestMarkerManager::cQuestSetMarkerInfoStage::getMarkerInfoForOm() const {
    return mpMarkerInfoOm;
}

__attribute__((weak)) void cQuestMarkerManager::cQuestSetMarkerInfoStage::move() {
    DDON_STUB("cQuestMarkerManager::cQuestSetMarkerInfoStage::move")
    /* stub */
}

cQuestMarkerManager::cQuestSetMarkerInfoStage::~cQuestSetMarkerInfoStage() {
    if (mpMarkerInfoNpc != nullptr) {
        mpMarkerInfoNpc->release();
        mpMarkerInfoNpc = nullptr;
    }
    if (mpMarkerInfoOm == nullptr) {
        return;
    }
    mpMarkerInfoOm->release();
    mpMarkerInfoOm = nullptr;
}

void cQuestMarkerManager::cQuestSetMarkerInfoStage::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
}

inline cQuestMarkerManager::cQuestSetMarkerInfoStage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestMarkerManager::cQuestSetMarkerInfoStage::MyDTI cQuestMarkerManager::cQuestSetMarkerInfoStage::DTI("cQuestMarkerManager::cQuestSetMarkerInfoStage", &::cQuestMarkerManager::cQuestSetMarkerInfoBase::DTI, 56ul, 0u, 0u);

MtObject* cQuestMarkerManager::cQuestSetMarkerInfoStage::MyDTI::newInstance() const {
    return new (16u) cQuestMarkerManager::cQuestSetMarkerInfoStage;
}

const MtDTI& cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::getDTI() const {
    return cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::DTI;
}

cResource* cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::getMarkerInfoForNpc() const {
    return mpMarkerInfoNpc;
}

cResource* cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::getMarkerInfoForOm() const {
    return mpMarkerInfoOm;
}

__attribute__((weak)) void cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::move() {
    DDON_STUB("cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::move")
    /* stub */
}

cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::~cQuestSetMarkerInfoFieldArea() {
    if (mpMarkerInfoNpc != nullptr) {
        mpMarkerInfoNpc->release();
        mpMarkerInfoNpc = nullptr;
    }
    if (mpMarkerInfoOm == nullptr) {
        return;
    }
    mpMarkerInfoOm->release();
    mpMarkerInfoOm = nullptr;
}

void cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mFieldAreaId", &mFieldAreaId, 0u, 0u);
}

inline cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::MyDTI cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::DTI("cQuestMarkerManager::cQuestSetMarkerInfoFieldArea", &::cQuestMarkerManager::cQuestSetMarkerInfoBase::DTI, 56ul, 0u, 0u);

MtObject* cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::MyDTI::newInstance() const {
    return new (16u) cQuestMarkerManager::cQuestSetMarkerInfoFieldArea;
}

template MtTypedArray<cQuestMarkerManager::cMarkerData>::~MtTypedArray();

template MtTypedArray<cQuestMarkerManager::cMarkerTask>::~MtTypedArray();

template MtTypedArray<cQuestMarkerManager::cQuestSetMarkerInfoBase>::~MtTypedArray();

template MtTypedArray<nQuest::cQuestMarker>::~MtTypedArray();

