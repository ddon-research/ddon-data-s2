// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCycleQuestSubCategoryManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "Protocol/PacketData/Quest.h"
#include "cCycleQuestManagerBase.h"
#include "cQuestManagerBase.h"
#include "cQuestResourceManager.h"
#include "cQuestTask.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "sChat.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCycleQuestSubCategoryManager::getDTI() const {
    return cCycleQuestSubCategoryManager::DTI;
}

void* cCycleQuestSubCategoryManager::operator new(size_t sz, u32 align) {
    return cCycleQuestSubCategoryManager::getAllocator()->memAlloc(sz, align, cCycleQuestSubCategoryManager::DTI.getID());
}

u32 cCycleQuestSubCategoryManager::getQuestManagerType() const {
    if (mpParent != nullptr) {
        return mpParent->getQuestManagerType();
    } else {
        return 9;
    }
}

void cCycleQuestSubCategoryManager::setParent(cCycleQuestManagerBase* pParent) {
    mpParent = pParent;
}

__attribute__((weak)) nQuest::SCHEDULE_ID cCycleQuestSubCategoryManager::getScheduleIdFromNoticeType(nQuest::CYCLE_CONTENTS_NOTICE_TYPE noticeType) const {
    DDON_STUB("cCycleQuestSubCategoryManager::getScheduleIdFromNoticeType")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::QUEST_ID cCycleQuestSubCategoryManager::getQuestId(u32 period, u32 situationNo) const {
    DDON_STUB("cCycleQuestSubCategoryManager::getQuestId")
    __builtin_unreachable();
}

void cCycleQuestSubCategoryManager::setSubCategoryType(nQuest::CYCLE_CONTENTS_SUB_CATEGORY type) {
    mSubCategoryType = static_cast<s32>(type);
}

nQuest::CYCLE_CONTENTS_SUB_CATEGORY cCycleQuestSubCategoryManager::getSubCategoryType() const {
    return static_cast<nQuest::CYCLE_CONTENTS_SUB_CATEGORY>(mSubCategoryType);
}

__attribute__((weak)) nQuest::CYCLE_CONTENTS_NOTICE_TYPE cCycleQuestSubCategoryManager::getNoticeType(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("cCycleQuestSubCategoryManager::getNoticeType")
    return {};
}

const nQuest::CycleContentsSituationInfoArray& cCycleQuestSubCategoryManager::getSituationInfoArray() const {
    return mSituationInfo;
}

__attribute__((weak)) nQuest::SCHEDULE_ID cCycleQuestSubCategoryManager::getCycleContentsScheduleId() const {
    DDON_STUB("cCycleQuestSubCategoryManager::getCycleContentsScheduleId")
    __builtin_unreachable();
}

void cCycleQuestSubCategoryManager::setCycleContentsScheduleId(nQuest::SCHEDULE_ID scheduleId) {
    mCycleContentsScheduleId.mScheduleId = scheduleId.mScheduleId;
}

nQuest::CYCLE_CONTENTS_PERIOD cCycleQuestSubCategoryManager::getCycleContentsPeriod() const {
    return mCycleContentsPeriod;
}

void cCycleQuestSubCategoryManager::setCycleContentsPeriod(nQuest::CYCLE_CONTENTS_PERIOD period) {
    mCycleContentsPeriod = period;
}

bool cCycleQuestSubCategoryManager::isDistEnable() const {
    return mIsDistEnable;
}

void cCycleQuestSubCategoryManager::callbackCycleContentsEnable(bool isEnable) {
    mIsDistEnable = isEnable;
}

__attribute__((weak)) void cCycleQuestSubCategoryManager::setDistributeSituation(QuestContentsSituationInfoVec& list) {
    DDON_STUB("cCycleQuestSubCategoryManager::setDistributeSituation")
    /* stub */
}

__attribute__((weak)) void cCycleQuestSubCategoryManager::registTask(const FortDefenseNoticeDataVec& noticeDataList) {
    DDON_STUB("cCycleQuestSubCategoryManager::registTask")
    /* stub */
}

__attribute__((weak)) void cCycleQuestSubCategoryManager::registTask(const RaidBossNoticeDataVec& noticeDataList) {
    DDON_STUB("cCycleQuestSubCategoryManager::registTask")
    /* stub */
}

void cCycleQuestSubCategoryManager::deleteTaskWithoutMainTask() {
    const u32 taskNum = mQuestTask.mLength;
    if (taskNum != 0) {
        for (unsigned int i0_3 = 0;;) {
            if (mQuestTask.getBuffer()[static_cast<int>(i0_3)] != nullptr) {
                if (mQuestTask.getBuffer()[static_cast<int>(i0_3)] != mpMainTask) {
                    static_cast<cQuestTask*>(mQuestTask.getBuffer()[static_cast<int>(i0_3)])->forceDelete();
                }
            }
            if (taskNum != (i0_3 + 1u)) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSituationInfo.mLength != 0) {
        u32 v3_0 = mSituationInfo.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mSituationInfo.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mSituationInfo.mpArray[i3_3];
                v4_0 = mSituationInfo.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSituationInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSituationInfo.mpArray));
    }
    mSituationInfo.mpArray = nullptr;
    mSituationInfo.mBufsiz = 0;
    mSituationInfo.mLength = 0;
}

__attribute__((weak)) void cCycleQuestSubCategoryManager::registSituationInfo(const QuestContentsSituationInfoDetailVec& list) {
    DDON_STUB("cCycleQuestSubCategoryManager::registSituationInfo")
    /* stub */
}

__attribute__((weak)) bool cCycleQuestSubCategoryManager::registMainTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList, const MtTypedArray<CDataQuestEnemyInfo>& enemyInfoList, const MtTypedArray<CDataQuestLayoutFlagSetInfo>& layoutFlagSetInfoList) {
    DDON_STUB("cCycleQuestSubCategoryManager::registMainTask")
    return {};
}

cQuestTask* cCycleQuestSubCategoryManager::getMainTask() const {
    return mpMainTask;
}

__attribute__((weak)) void cCycleQuestSubCategoryManager::addTaskInfo(cQuestTask* pTask, nQuest::CYCLE_CONTENTS_NOTICE_TYPE noticeType) {
    DDON_STUB("cCycleQuestSubCategoryManager::addTaskInfo")
    /* stub */
}

cCycleQuestSubCategoryManager::cCycleQuestSubCategoryManager() : cQuestManagerBase("SubCategory"), mpMainTask(static_cast<cQuestTask*>(nullptr)), mpParent(static_cast<cCycleQuestManagerBase*>(nullptr)) {
    mCycleContentsPeriod = nQuest::CYCLE_CONTENTS_PERIOD_NONE;
    mSubCategoryType = 0;
    mIsDistEnable = true;
}

__attribute__((noinline)) cCycleQuestSubCategoryManager::~cCycleQuestSubCategoryManager() {
    if (mTaskInfo.mLength != 0) {
        u32 v0_0 = mTaskInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTaskInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTaskInfo.mpArray[i0_3];
                v1_0 = mTaskInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTaskInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mTaskInfo.mpArray));
    }
    mTaskInfo.mpArray = nullptr;
    mTaskInfo.mBufsiz = 0;
    mTaskInfo.mLength = 0;
    if (mSituationInfo.mLength != 0) {
        u32 v3_0 = mSituationInfo.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mSituationInfo.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mSituationInfo.mpArray[i3_3];
                v4_0 = mSituationInfo.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSituationInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSituationInfo.mpArray));
    }
    mSituationInfo.mpArray = nullptr;
    mSituationInfo.mBufsiz = 0;
    mSituationInfo.mLength = 0;
}

__attribute__((weak)) void cCycleQuestSubCategoryManager::move() {
    DDON_STUB("cCycleQuestSubCategoryManager::move")
    /* stub */
}

void cCycleQuestSubCategoryManager::release() {
    if (mSituationInfo.mLength != 0) {
        u32 v0_0 = mSituationInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSituationInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSituationInfo.mpArray[i0_3];
                v1_0 = mSituationInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSituationInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSituationInfo.mpArray));
    }
    mSituationInfo.mpArray = nullptr;
    mSituationInfo.mBufsiz = 0;
    mSituationInfo.mLength = 0;
    this->cQuestManagerBase::release();
}

inline cCycleQuestSubCategoryManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCycleQuestSubCategoryManager::MyDTI cCycleQuestSubCategoryManager::DTI("cCycleQuestSubCategoryManager", &::cQuestManagerBase::DTI, 160ul, 0u, 0u);

MtObject* cCycleQuestSubCategoryManager::MyDTI::newInstance() const {
    return new (16u) cCycleQuestSubCategoryManager;
}

const MtDTI& cCycleQuestSubCategoryManager::cCycleContentsTaskInfo::getDTI() const {
    return cCycleQuestSubCategoryManager::cCycleContentsTaskInfo::DTI;
}

cCycleQuestSubCategoryManager::cCycleContentsTaskInfo::~cCycleContentsTaskInfo() {
}

__attribute__((weak)) void cCycleQuestSubCategoryManager::cCycleContentsTaskInfo::createProperty(MtPropertyList& s) {
}

inline cCycleQuestSubCategoryManager::cCycleContentsTaskInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCycleQuestSubCategoryManager::cCycleContentsTaskInfo::MyDTI cCycleQuestSubCategoryManager::cCycleContentsTaskInfo::DTI("cCycleQuestSubCategoryManager::cCycleContentsTaskInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cCycleQuestSubCategoryManager::cCycleContentsTaskInfo::MyDTI::newInstance() const {
    return new (16u) cCycleQuestSubCategoryManager::cCycleContentsTaskInfo;
}

template MtTypedArray<cCycleQuestSubCategoryManager::cCycleContentsTaskInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cCycleContentsSituationInfo>::~MtTypedArray();

