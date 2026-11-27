// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cQuestManagerBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cQuestMarkerManager.h"
#include "cQuestSvRequestManager.h"
#include "cQuestTask.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "sTalkManager.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestManagerBase::getDTI() const {
    return cQuestManagerBase::DTI;
}

u32 cQuestManagerBase::getQuestNum() const {
    return mQuestTask.mLength;
}

__attribute__((weak)) u32 cQuestManagerBase::getQuestOrderNum() const {
    DDON_STUB("cQuestManagerBase::getQuestOrderNum")
    return {};
}

cQuestTask* cQuestManagerBase::getQuestTask(u32 index) const {
    if (index < getQuestNum()) {
        return static_cast<cQuestTask*>(mQuestTask.mpArray[index]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) cQuestTask* cQuestManagerBase::getQuestTask(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("cQuestManagerBase::getQuestTask")
    return nullptr;
}

__attribute__((weak)) cQuestTask* cQuestManagerBase::getQuestTask(nQuest::QUEST_ID questId) const {
    DDON_STUB("cQuestManagerBase::getQuestTask")
    return nullptr;
}

bool cQuestManagerBase::hasEndDistributionQuest() const {
    const u32 questNum = getQuestNum();
    bool b2_0;
    if (questNum == 0) {
        b2_0 = false;
    } else {
        for (unsigned int i0_3 = 0;;) {
            if (getQuestTask(i0_3)->isEndDistribution()) {
                b2_0 = true;
                return b2_0;
            } else {
                if ((i0_3 + 1u) < questNum) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        b2_0 = false;
    }
    return b2_0;
}

void cQuestManagerBase::cancelQuestNotOrder() {
    const u32 taskNum = mQuestTask.mLength;
    if (taskNum != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t0 = mQuestTask.getBuffer()[static_cast<int>(i0_3)];
            if (!static_cast<cQuestTask*>(t0)->isMyOrder()) {
                static_cast<cQuestTask*>(t0)->requestCancel();
            }
            if (taskNum != (i0_3 + 1u)) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void cQuestManagerBase::cancelQuestNotOrderEndDistribution() {
    DDON_STUB("cQuestManagerBase::cancelQuestNotOrderEndDistribution")
    /* stub */
}

void cQuestManagerBase::deleteQuestTask(cQuestTask* pTask) {
    cQuestSvRequestManager* t0 = sQuestManagerExt::getInstance()->getQuestSvRequestMgr();
    t0->deleteRequestQueue(pTask->getScheduleId());
    cQuestMarkerManager* t1 = sQuestManagerExt::getInstance()->getQuestMarkerMgr();
    t1->removeMarker(pTask->getScheduleId(), -1);
    u32 v0_0 = mQuestTask.mLength;
    if (v0_0 != 0) {
        MtObject* * v0_1 = mQuestTask.mpArray;
        unsigned int i0_3 = 0;
        u32 v3_0;
        unsigned int v4_1;
        u32 v4_2;
        unsigned int v4_3;
        for (;;) {
            if (pTask == v0_1[i0_3]) {
                if (!mQuestTask.mAutoDelete) {
                    v3_0 = v0_0;
                } else {
                    if (pTask == nullptr) {
                        v3_0 = v0_0;
                    } else {
                        delete pTask;
                        v3_0 = mQuestTask.mLength;
                    }
                }
                if ((i0_3 + 1u) < v3_0) {
                    v4_1 = i0_3 + 1u;
                    v4_2 = v3_0;
                    v4_3 = i0_3;
                    for (;;) {
                        mQuestTask.mpArray[v4_3] = mQuestTask.mpArray[v4_1];
                        if (v4_2 != (v4_1 + 1u)) {
                            v4_3 = v4_1;
                            v4_1 = v4_1 + 1u;
                        } else {
                            break;
                        }
                    }
                }
                mQuestTask.mLength = v3_0 - 1u;
                break;
            } else {
                if ((i0_3 + 1u) < v0_0) {
                    i0_3 = i0_3 + 1u;
                } else {
                    break;
                }
            }
        }
    }
}

void cQuestManagerBase::initStage() {
    const u32 questNum = getQuestNum();
    if (questNum != 0) {
        for (unsigned int i0_3 = 0;;) {
            cQuestTask* t0 = getQuestTask(i0_3);
            if (t0 != nullptr) {
                t0->deleteFlagFsm();
            }
            if (questNum != (i0_3 + 1u)) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) cQuestTask* cQuestManagerBase::newInstanceTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 keyId) {
    DDON_STUB("cQuestManagerBase::newInstanceTask")
    return nullptr;
}

void cQuestManagerBase::addTask(cQuestTask* pTask) {
    if (pTask == nullptr) {
        return;
    }
    sQuestManagerExt* t0 = sQuestManagerExt::getInstance();
    t0->loadQuestResource(pTask->getQuestId());
    u32 t1 = mQuestTask.mLength;
    u32 t2 = mQuestTask.mBufsiz;
    if (t1 < t2) {
        mQuestTask.mLength = t1 + 1u;
        mQuestTask.mpArray[t1] = static_cast<MtObject*>(pTask);
    } else {
        void* t3 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t2 + 32u) * 8, 16u);
        memset(t3, 0, static_cast<size_t>(t2 + 32u) * 8);
        memcpy(t3, static_cast<const void*>(mQuestTask.mpArray), static_cast<size_t>(mQuestTask.mLength) * 8);
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mQuestTask.mpArray));
        mQuestTask.mpArray = static_cast<MtObject* *>(t3);
        mQuestTask.mBufsiz = t2 + 32u;
        u32 t4 = mQuestTask.mLength;
        mQuestTask.mLength = t4 + 1u;
        mQuestTask.mpArray[t4] = static_cast<MtObject*>(pTask);
    }
}

void cQuestManagerBase::updateQuestTask(cQuestTask* pTask) {
    pTask->move();
}

void cQuestManagerBase::release() {
    u32 i = 0;
    if (mQuestTask.mLength != 0) {
        do {
            static_cast<cQuestTask*>(mQuestTask.getBuffer()[static_cast<int>(i)])->forceDelete();
            i += 1u;
        } while (i < mQuestTask.mLength);
    }
}

void cQuestManagerBase::move() {
    if (mQuestTask.mLength != 0) {
        unsigned int i0_8 = 0;
        u32 v0_10 = mQuestTask.mLength;
        u32 v1_8;
        for (;;) {
            v1_8 = v0_10;
            for (;;) {
                MtObject* t0 = mQuestTask.getBuffer()[static_cast<int>(i0_8)];
                static_cast<cQuestTask*>(t0)->move();
                if (!static_cast<cQuestTask*>(t0)->isDelete()) {
                    break;
                } else {
                    static_cast<cQuestTask*>(t0)->getQuestManager()->deleteQuestTask(static_cast<cQuestTask*>(t0));
                    if (i0_8 < (v1_8 - 1u)) {
                        v1_8 += 0xFFFFFFFFu;
                    } else {
                        return;
                    }
                }
            }
            if ((i0_8 + 1u) < v1_8) {
                i0_8 += 1u;
                v0_10 = v1_8;
            } else {
                break;
            }
        }
    }
}

void cQuestManagerBase::getQuestList() {
    mIsReqGetQuestList = true;
}

__attribute__((weak)) bool cQuestManagerBase::registTask(const CQuestList& param, const MtTypedArray<CDataQuestProcessState>& processList, cQuestTask* * ppTask) {
    DDON_STUB("cQuestManagerBase::registTask")
    return {};
}

__attribute__((weak)) bool cQuestManagerBase::registTask(const CQuestOrderList& param, cQuestTask* * ppTask) {
    DDON_STUB("cQuestManagerBase::registTask")
    return {};
}

__attribute__((weak)) bool cQuestManagerBase::registTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList, const MtTypedArray<CDataQuestEnemyInfo>& enemyInfoList, const MtTypedArray<CDataQuestLayoutFlagSetInfo>& layoutFlagSetInfoList, cQuestTask* * ppTask) {
    DDON_STUB("cQuestManagerBase::registTask")
    return {};
}

__attribute__((weak)) bool cQuestManagerBase::registTask(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, const MtTypedArray<CDataQuestProcessState>& processList, cQuestTask* * ppTask) {
    DDON_STUB("cQuestManagerBase::registTask")
    return {};
}

__attribute__((weak)) bool cQuestManagerBase::registHelperTask(const CQuestOrderList& param, cQuestTask* * ppTask) {
    DDON_STUB("cQuestManagerBase::registHelperTask")
    return {};
}

void cQuestManagerBase::noticeDecideDeliverItem(nQuest::SCHEDULE_ID scheduleId) {
    cQuestTask* pTask = getQuestTask(scheduleId);
    if (pTask == nullptr) {
        return;
    }
    u32 npcId = sTalkManager::getInstance()->getNpcId();
    pTask->notifyDecideDeliverItem(npcId);
}

void cQuestManagerBase::callbackReloadMasterData() {
    if (mQuestTask.mLength == 0) {
        getQuestList();
        return;
    }
    u32 i = 0;
    do {
        static_cast<cQuestTask*>(mQuestTask.getBuffer()[static_cast<int>(i)])->forceDelete();
        i += 1u;
    } while (i < mQuestTask.mLength);
    getQuestList();
}

void cQuestManagerBase::callbackClear(nQuest::SCHEDULE_ID scheduleId, bool isParty) {
    cQuestTask* pTask = getQuestTask(scheduleId);
    if (pTask == nullptr) {
        return;
    }
    pTask->callbackClear();
}

__attribute__((weak)) void cQuestManagerBase::cancelWaitOrder(cQuestTask* pTask, bool& isReqCancel) {
    DDON_STUB("cQuestManagerBase::cancelWaitOrder")
    /* stub */
}

void cQuestManagerBase::callbackGetQuestList(u32 errorCode) {
    mIsReqGetQuestList = false;
    if (errorCode == 0) {
        registQuestList();
    }
}

cQuestManagerBase::cQuestManagerBase(MT_CTSTR managerName) {
    mIsReqGetQuestList = false;
    mQuestTask.mAutoDelete = true;
}

cQuestManagerBase::~cQuestManagerBase() {
    unsigned int i3 = 0;
    if (mQuestTask.mLength != 0) {
        do {
            static_cast<cQuestTask*>(mQuestTask.getBuffer()[static_cast<int>(i3)])->forceDelete();
            i3 += 1u;
        } while (i3 < mQuestTask.mLength);
    }
}

inline cQuestManagerBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestManagerBase::MyDTI cQuestManagerBase::DTI("cQuestManagerBase", &::MtObject::DTI, 48ul, 0u, 1u);

MtObject* cQuestManagerBase::MyDTI::newInstance() const {
    return nullptr;
}

template MtTypedArray<cQuestTask>::~MtTypedArray();

