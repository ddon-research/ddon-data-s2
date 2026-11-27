// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "sQuestManagerExt.h"
#include "Protocol/PacketData/Common.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "../../MT/MtTime.h"
#include "Protocol/PacketData/Quest.h"
#include "Protocol/PacketData/Ranking.h"
#include "Protocol/UserSession/S2C.h"
#include "Protocol/PacketData/Warp.h"
#include "aMenu.h"
#include "aStage.h"
#include "cActiveQuestManager.h"
#include "../../XFramework/cArea.h"
#include "cAreaHit.h"
#include "cAreaReleaseManager.h"
#include "cCharacterData.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cCycle04QuestManager.h"
#include "cCycleQuestManagerBase.h"
#include "cCycleQuestSubCategoryManager.h"
#include "cEndContentsManager.h"
#include "cGUIUtility.h"
#include "cLightQuestManager.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "cOmComponent.h"
#include "cPRTManager.h"
#include "cPawnQuestManager.h"
#include "cQuestDeliverManager.h"
#include "cQuestEventArg.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestManagerBase.h"
#include "cQuestMarkerManager.h"
#include "cQuestMemoryPool.h"
#include "cQuestPhaseManager.h"
#include "cQuestPhaseState.h"
#include "cQuestResourceLoadManager.h"
#include "cQuestResourceManager.h"
#include "cQuestSvNotice.h"
#include "cQuestSvNoticeManager.h"
#include "cQuestSvRequest.h"
#include "cQuestSvRequestManager.h"
#include "cQuestSyncDataManager.h"
#include "cQuestTask.h"
#include "cScenario.h"
#include "cSetQuestManager.h"
#include "../../XFramework/cSystem.h"
#include "cTutorialQuestManager.h"
#include "../../XFramework/cUnit.h"
#include "cpLayout.h"
#include "cpNpc.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "nLayout.h"
#include "nNet.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "rNpcMeetingPlace.h"
#include "rTutorialQuestGroup.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sChat.h"
#include "sContextManager.h"
#include "sEnemyManager.h"
#include "sEventManager.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sNpcManager.h"
#include "sPlayerManager.h"
#include "sScenario.h"
#include "sSetManager.h"
#include "sSoundManager.h"
#include "sTalkManager.h"
#include "sWeatherManager.h"
#include "sWorldOffset.h"
#include "uControl.h"
#include "uControlEnemy.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uOmModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sQuestManagerExt::getDTI() const {
    return sQuestManagerExt::DTI;
}

void* sQuestManagerExt::operator new(size_t sz, u32 align) {
    return sQuestManagerExt::getAllocator()->memAlloc(sz, align, sQuestManagerExt::DTI.getID());
}

__attribute__((weak)) bool sQuestManagerExt::isReqDeliverItem() const {
    DDON_STUB("sQuestManagerExt::isReqDeliverItem")
    return {};
}

__attribute__((weak)) const nQuest::cQuestDeliverRequestInfo* sQuestManagerExt::getQuestDeliverRequestInfo(const nQuest::SCHEDULE_ID& scheduleId) const {
    DDON_STUB("sQuestManagerExt::getQuestDeliverRequestInfo")
    return nullptr;
}

__attribute__((weak)) const nQuest::cQuestDeliveredInfo* sQuestManagerExt::getQuestDeliveredInfo(const nQuest::SCHEDULE_ID& scheduleId) const {
    DDON_STUB("sQuestManagerExt::getQuestDeliveredInfo")
    return nullptr;
}

__attribute__((weak)) bool sQuestManagerExt::fulfillDeliver(const nQuest::SCHEDULE_ID& scheduleId) const {
    DDON_STUB("sQuestManagerExt::fulfillDeliver")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::decideDeliverItem(const nQuest::SCHEDULE_ID& scheduleId) {
    DDON_STUB("sQuestManagerExt::decideDeliverItem")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::deliverItem(const nQuest::SCHEDULE_ID& scheduleId, ItemUIDListVec& itemUIDList) {
    DDON_STUB("sQuestManagerExt::deliverItem")
    /* stub */
}

void sQuestManagerExt::updateDeliveredInfo(nQuest::SCHEDULE_ID scheduleId, u32 charcterId, const MtTypedArray<CDataDeliveredItem>& deliveredList) {
    u32 v0_2 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_2;
    if (v0_2 == 0) {
        v2_2 = nullptr;
    } else {
        MtObject* * v0_3 = mFunctionInfo.mpArray;
        for (unsigned int i0_1 = 0;;) {
            if (v0_3[i0_1] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[i0_1]) + 8)) == 8) {
                    v2_2 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_3[i0_1])->getFunctionManager();
                    break;
                }
            }
            if ((i0_1 + 1u) < v0_2) {
                i0_1 = i0_1 + 1u;
            } else {
                v2_2 = nullptr;
                break;
            }
        }
    }
    static_cast<cQuestDeliverManager*>(v2_2)->updateDeliveredInfo(scheduleId, charcterId, deliveredList);
}

__attribute__((weak)) nQuest::SCHEDULE_ID sQuestManagerExt::getEventBoardQuestAcceptedScheduleId() const {
    DDON_STUB("sQuestManagerExt::getEventBoardQuestAcceptedScheduleId")
    __builtin_unreachable();
}

bool sQuestManagerExt::isDogmaOrb() const {
    return static_cast<bool>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 1865)) & 1);
}

bool sQuestManagerExt::isEndTextOm(u32 stageNo, u32 groupNo, s32 setNo) const {
    if (mpTouchOmInfo != nullptr) {
        if (mpTouchOmInfo->mLayoutId.mLayoutID == ((groupNo * 1024u) | (stageNo & 1023u))) {
            if (mpTouchOmInfo->mSetNo == static_cast<unsigned int>(setNo)) {
                return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 1866)) & 4) >> 2);
            }
        }
    }
    return false;
}

bool sQuestManagerExt::isEndTextOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq) const {
    if (mpTouchOmInfo != nullptr) {
        if (mpTouchOmInfo->isQuestSet()) {
            if (mpTouchOmInfo->mLayoutId.mLayoutID == ((groupNo * 1024u) | (stageNo & 1023u))) {
                if (mpTouchOmInfo->mSetNo == static_cast<unsigned int>(setNo)) {
                    return static_cast<bool>((static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 1866)) & 4) >> 2) & static_cast<unsigned long>(mpTouchOmInfo->mQuestSeq == questSeq));
                }
            }
        }
    }
    return false;
}

u32 sQuestManagerExt::getTalkEndNpcId() const {
    return mTalkEndNpcId;
}

void sQuestManagerExt::notifyTalkEnd(u32 npcId) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864)) | 1;
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    mTalkEndNpcId = npcId;
    mIsOrderUIDecide = false;
    mOrderUIScheduleId.mScheduleId = nQuest::INVALID_SCHEDULE_ID.mScheduleId;
    static_cast<sGUIExt*>(sGUI::getInstance())->deleteQuestInfo();
}

void sQuestManagerExt::notifyReloadMasterData() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864)) | 2;
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 0) {
                    v2_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    v2_4->callbackReloadMasterData();
    u32 v3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v5_4;
    if (v3_0 == 0) {
        v5_4 = nullptr;
    } else {
        MtObject* * v3_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i3_2 = 0;;) {
            if (v3_1[i3_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 1) {
                    v5_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v3_1[i3_2])->getQuestManager();
                    break;
                }
            }
            if ((i3_2 + 1u) < v3_0) {
                i3_2 = i3_2 + 1u;
            } else {
                v5_4 = nullptr;
                break;
            }
        }
    }
    v5_4->callbackReloadMasterData();
    u32 v6_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v8_4;
    if (v6_0 == 0) {
        v8_4 = nullptr;
    } else {
        MtObject* * v6_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i6_2 = 0;;) {
            if (v6_1[i6_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v6_1[i6_2]) + 8)) == 2) {
                    v8_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v6_1[i6_2])->getQuestManager();
                    break;
                }
            }
            if ((i6_2 + 1u) < v6_0) {
                i6_2 = i6_2 + 1u;
            } else {
                v8_4 = nullptr;
                break;
            }
        }
    }
    v8_4->callbackReloadMasterData();
    u32 v9_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v11_4;
    if (v9_0 == 0) {
        v11_4 = nullptr;
    } else {
        MtObject* * v9_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i9_2 = 0;;) {
            if (v9_1[i9_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v9_1[i9_2]) + 8)) == 3) {
                    v11_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v9_1[i9_2])->getQuestManager();
                    break;
                }
            }
            if ((i9_2 + 1u) < v9_0) {
                i9_2 = i9_2 + 1u;
            } else {
                v11_4 = nullptr;
                break;
            }
        }
    }
    v11_4->callbackReloadMasterData();
    u32 v12_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v14_4;
    if (v12_0 == 0) {
        v14_4 = nullptr;
    } else {
        MtObject* * v12_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i12_2 = 0;;) {
            if (v12_1[i12_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v12_1[i12_2]) + 8)) == 5) {
                    v14_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v12_1[i12_2])->getQuestManager();
                    break;
                }
            }
            if ((i12_2 + 1u) < v12_0) {
                i12_2 = i12_2 + 1u;
            } else {
                v14_4 = nullptr;
                break;
            }
        }
    }
    v14_4->callbackReloadMasterData();
    u32 v15_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v17_4;
    if (v15_0 == 0) {
        v17_4 = nullptr;
    } else {
        MtObject* * v15_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i15_2 = 0;;) {
            if (v15_1[i15_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v15_1[i15_2]) + 8)) == 6) {
                    v17_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v15_1[i15_2])->getQuestManager();
                    break;
                }
            }
            if ((i15_2 + 1u) < v15_0) {
                i15_2 = i15_2 + 1u;
            } else {
                v17_4 = nullptr;
                break;
            }
        }
    }
    v17_4->callbackReloadMasterData();
    u32 v18_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v21_4;
    if (v18_0 == 0) {
        v21_4 = nullptr;
    } else {
        MtObject* * v18_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i18_2 = 0;;) {
            if (v18_1[i18_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v18_1[i18_2]) + 8)) == 7) {
                    v21_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v18_1[i18_2])->getQuestManager();
                    v21_4->callbackReloadMasterData();
                    return;
                }
            }
            if ((i18_2 + 1u) < v18_0) {
                i18_2 = i18_2 + 1u;
            } else {
                break;
            }
        }
        v21_4 = nullptr;
    }
    v21_4->callbackReloadMasterData();
}

void sQuestManagerExt::notifyAddItem(u8 itemType) {
    if (itemType == 29) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
            }
        }
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869)) | 16;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    } else {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
            }
        }
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864)) | 4;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
}

__attribute__((weak)) void sQuestManagerExt::notifySetTouchOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq) {
    DDON_STUB("sQuestManagerExt::notifySetTouchOm")
    /* stub */
}

void sQuestManagerExt::notifyReleaseTouchOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq) {
    if (mpTouchOmInfo == nullptr) {
        return;
    }
    if (mpTouchOmInfo->mLayoutId.mLayoutID != ((groupNo * 1024u) | (stageNo & 1023u))) {
        return;
    }
    if (mpTouchOmInfo->mSetNo != static_cast<unsigned int>(setNo)) {
        return;
    }
    if (mpTouchOmInfo->mQuestSeq != questSeq) {
        return;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864)) | 16;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyClearSetQuest(u32 areaId) {
    unsigned int* p0_0 = &mClearSetQuestAreaId[0];
    for (unsigned int i0_1 = 0; i0_1 <= 3u; p0_0 += 1, i0_1 += 1u) {
        if ((*p0_0) == 0) {
            *p0_0 = areaId;
            break;
        }
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1864)) | 32;
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

__attribute__((weak)) void sQuestManagerExt::notifyEntryParty() {
    DDON_STUB("sQuestManagerExt::notifyEntryParty")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::notifyLeaveParty() {
    DDON_STUB("sQuestManagerExt::notifyLeaveParty")
    /* stub */
}

void sQuestManagerExt::notifyDogmaOrb() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865)) | 1;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyTouchEventBoard() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865)) | 4;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenJobMaster() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865)) | 32;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyTouchRimStone() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865)) | 64;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyGetAchievement() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1865)) | 128;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyEndTalkSpecial() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866)) | 1;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyClearPartyQuest(const nQuest::SCHEDULE_ID& scheduleId) {
    unsigned int i0_3 = 0;
    unsigned int i1_2;
    for (;;) {
        if (!nQuest::isSoloQuest(static_cast<nQuest::QUEST_TYPE>(i0_3))) {
            u32 v1_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
            if (v1_0 != 0) {
                MtObject* * v1_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
                i1_2 = 0;
                for (;;) {
                    if (v1_1[i1_2] != nullptr) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1[i1_2]) + 8)) == i0_3) {
                            if (static_cast<sQuestManagerExt::cManagerInfo*>(v1_1[i1_2])->getQuestManager() != nullptr) {
                                static_cast<sQuestManagerExt::cManagerInfo*>(v1_1[i1_2])->getQuestManager()->callbackClear(scheduleId, true);
                            }
                            break;
                        }
                    }
                    if ((i1_2 + 1u) < v1_0) {
                        i1_2 = i1_2 + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
        if ((i0_3 + 1u) != 12) {
            i0_3 += 1u;
        } else {
            break;
        }
    }
}

void sQuestManagerExt::notifyEndTextOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq) {
    if (mpTouchOmInfo == nullptr) {
        return;
    }
    if (mpTouchOmInfo->mLayoutId.mLayoutID != ((groupNo * 1024u) | (stageNo & 1023u))) {
        return;
    }
    if (mpTouchOmInfo->mSetNo != static_cast<unsigned int>(setNo)) {
        return;
    }
    if (mpTouchOmInfo->mQuestSeq != questSeq) {
        return;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866)) | 4;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifySetSkill() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866)) | 8;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenAreaMaster() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866)) | 16;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenNewspaper() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866)) | 32;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenQuestBoard() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866)) | 64;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOrderLightQuest() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1866)) | 128;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOrderWorldQuest() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867)) | 1;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyLostMainPawn() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867)) | 2;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyHugeble() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867)) | 4;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenAreaMasterSupplies() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867)) | 8;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenEntryBoard() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867)) | 16;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyNoticeInterruptContents() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867)) | 32;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenRetrySelect() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867)) | 64;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyNoticePartyInvite() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1867)) | 128;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyPartyReward() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868)) | 2;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenCraftExam() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868)) | 4;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyLevelUpCraft() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868)) | 8;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyClearLightQuest() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868)) | 16;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenJobMasterReward() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868)) | 32;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyKilledAreaBoss() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868)) | 1;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenWarehouse() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868)) | 64;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpneRewardBox() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1868)) | 128;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifySearchClan() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869)) | 1;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenAreaList() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869)) | 2;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyPresentPartnerPawn() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869)) | 4;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyReleasePortal() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869)) | 8;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

__attribute__((weak)) void sQuestManagerExt::notifyDivideWarpPlayer(bool isSuccess, u32 characterId) {
    DDON_STUB("sQuestManagerExt::notifyDivideWarpPlayer")
    /* stub */
}

void sQuestManagerExt::notifyOrderPawnQuest() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869)) | 32;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOpenPPShop() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869)) | 64;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyTouchClanBoard() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1869)) | 128;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::notifyOneOffGather() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1870) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 1870)) | 1;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

__attribute__((weak)) void sQuestManagerExt::addCheckSayMessage(nQuest::QUEST_ID questId, u32 msgIdx) {
    DDON_STUB("sQuestManagerExt::addCheckSayMessage")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::removeCheckSayMessage(nQuest::QUEST_ID questId) {
    DDON_STUB("sQuestManagerExt::removeCheckSayMessage")
    /* stub */
}

void sQuestManagerExt::checkSayMessage(MT_CTSTR message) {
    u32 v0_8 = mSayInfoList.mLength;
    if (v0_8 != 0) {
        if ((*message) != 0) {
            for (unsigned int i0_3 = 0;;) {
                matchMessage(message, static_cast<cSayInfo*>(mSayInfoList.getBuffer()[static_cast<int>(i0_3)]));
                if (v0_8 != (i0_3 + 1u)) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
}

__attribute__((weak)) bool sQuestManagerExt::matchMessage(MT_CTSTR message, sQuestManagerExt::cSayInfo* pInfo) {
    DDON_STUB("sQuestManagerExt::matchMessage")
    return {};
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::matchPattern(MT_CTSTR message, MT_CTSTR pattern) {
    DDON_STUB("sQuestManagerExt::matchPattern")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::killedEnemy(u32 stageNo, u32 enemyId) {
    DDON_STUB("sQuestManagerExt::killedEnemy")
    /* stub */
}

u32 sQuestManagerExt::getKilledEnemyNum(u32 stageNo, u32 enemyId) {
    if (mKilledEnemy.mLength != 0) {
        unsigned int i0 = 0;
        do {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mKilledEnemy.getBuffer()[static_cast<int>(i0)]) + 8)) == stageNo) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mKilledEnemy.getBuffer()[static_cast<int>(i0)]) + 12)) == enemyId) {
                    if (mKilledEnemy.getBuffer()[static_cast<int>(i0)] != nullptr) {
                        return static_cast<sQuestManagerExt::cKilledEnemy*>(mKilledEnemy.getBuffer()[static_cast<int>(i0)])->getKilledNum();
                    } else {
                        return 0;
                    }
                }
            }
            i0 += 1u;
        } while (i0 < mKilledEnemy.mLength);
    }
    return 0;
}

__attribute__((weak)) void sQuestManagerExt::callQuestAnnounce(const cQuestTask* pTask, s32 announceType, s32 purposeNo, bool isDiscovered, s32 num) {
    DDON_STUB("sQuestManagerExt::callQuestAnnounce")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callFailedQuestAnnounce(nQuest::QUEST_TYPE questType, nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 commonDialog) {
    DDON_STUB("sQuestManagerExt::callFailedQuestAnnounce")
    /* stub */
}

void sQuestManagerExt::requestOverWriteBgm(s32 bgmType, s32 bgmId, s32 callType) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (bgmType == 1) {
        sSoundManager::getInstance()->startQuestReq(bgmId, 2u, static_cast<u32>(callType));
    } else {
        if (bgmType == 0) {
            sSoundManager::getInstance()->startQuestReq(bgmId, 0u, 0u);
        }
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::requestOverWriteBgmFix(s32 bgmType, s32 bgmId) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (bgmType == 1) {
        sSoundManager::getInstance()->startQuestReq(bgmId, 2u, 0u);
    } else {
        if (bgmType == 0) {
            sSoundManager::getInstance()->startQuestReq(bgmId, 0u, 0u);
        }
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::requestRestoreBgm(bool IsRequestEvent) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    sSoundManager::getInstance()->endQuestReq(IsRequestEvent);
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::updateQuestAnnounce() {
    u32 v0_10 = mCallQuestAnnounce.mLength;
    cCallQuestAnnounce* pLog;
    unsigned int i3_10;
    u32 v6_0;
    unsigned int v6_11;
    unsigned int v7_1;
    u32 v7_6;
    unsigned int v7_10;
    for (;;) {
        if (v0_10 == 0) {
            break;
        } else {
            pLog = static_cast<cCallQuestAnnounce*>(*mCallQuestAnnounce.getBuffer());
            if (pLog == nullptr) {
                continue;
            }
        }
        pLog->update();
        if (!pLog->isDelete()) {
            break;
        }
        u32 v3_0 = mCallQuestAnnounce.mLength;
        if (v3_0 != 0) {
            MtObject* * v3_1 = mCallQuestAnnounce.mpArray;
            i3_10 = 0;
            for (;;) {
                if (pLog == v3_1[i3_10]) {
                    if (!mCallQuestAnnounce.mAutoDelete) {
                        v6_0 = v3_0;
                    } else {
                        delete pLog;
                        v6_0 = mCallQuestAnnounce.mLength;
                    }
                    v6_11 = i3_10 + 1u;
                    if (v6_11 < v6_0) {
                        v7_1 = v6_11;
                        v7_6 = v6_0;
                        v7_10 = i3_10;
                        for (;;) {
                            mCallQuestAnnounce.mpArray[v7_10] = mCallQuestAnnounce.mpArray[v7_1];
                            if (v7_6 != (v7_1 + 1u)) {
                                v7_10 = v7_1;
                                v7_1 = v7_1 + 1u;
                            } else {
                                break;
                            }
                        }
                    }
                    mCallQuestAnnounce.mLength = v6_0 - 1u;
                    break;
                } else {
                    if ((i3_10 + 1u) < v3_0) {
                        i3_10 = i3_10 + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
        delete pLog;
        v0_10 += 0xFFFFFFFFu;
    }
}

__attribute__((weak)) void sQuestManagerExt::loadStage() {
    DDON_STUB("sQuestManagerExt::loadStage")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::initStage() {
    DDON_STUB("sQuestManagerExt::initStage")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::initLobby() {
}

void sQuestManagerExt::initGame() {
    mNowSetQuestDistId = 0;
    u32 v0_0 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_1[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    static_cast<cQuestResourceManager*>(v2_4)->initGame();
    if (mSystemLogQueue.mLength != 0) {
        u32 v3_0 = mSystemLogQueue.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mSystemLogQueue.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mSystemLogQueue.mpArray[i3_3];
                v4_0 = mSystemLogQueue.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSystemLogQueue.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSystemLogQueue.mpArray));
    }
    mSystemLogQueue.mpArray = nullptr;
    mSystemLogQueue.mBufsiz = 0;
    mSystemLogQueue.mLength = 0;
}

__attribute__((weak)) void sQuestManagerExt::finalGame() {
    DDON_STUB("sQuestManagerExt::finalGame")
    /* stub */
}

bool sQuestManagerExt::isResetInstanceArea() const {
    return mIsResetInstanceArea;
}

__attribute__((weak)) void sQuestManagerExt::setResetInstanceArea() {
    DDON_STUB("sQuestManagerExt::setResetInstanceArea")
    /* stub */
}

__attribute__((weak)) u32 sQuestManagerExt::getQuestListSetNum() const {
    DDON_STUB("sQuestManagerExt::getQuestListSetNum")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getQuestListSetQuestId(u32 idx) const {
    DDON_STUB("sQuestManagerExt::getQuestListSetQuestId")
    return {};
}

__attribute__((weak)) cNamedParam* sQuestManagerExt::getRaidBossEnemyParam(u32 raidBossId) const {
    DDON_STUB("sQuestManagerExt::getRaidBossEnemyParam")
    return nullptr;
}

__attribute__((weak)) bool sQuestManagerExt::isCycleContentsHolding() const {
    DDON_STUB("sQuestManagerExt::isCycleContentsHolding")
    return {};
}

u32 sQuestManagerExt::getHoldingCycleContentsNum() const {
    return mCycleContentsInfoList.mLength;
}

__attribute__((weak)) nQuest::CYCLE_CONTENTS_PERIOD sQuestManagerExt::getHoldingContentsPeriod(nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::getHoldingContentsPeriod")
    return {};
}

const nQuest::cCycleContentsInfo* sQuestManagerExt::getHoldingCycleContentsInfo(u32 idx) const {
    if (idx < mCycleContentsInfoList.mLength) {
        return static_cast<const nQuest::cCycleContentsInfo*>(mCycleContentsInfoList.mpArray[idx]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) u32 sQuestManagerExt::getHoldingCycleContentsListIndex(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::getHoldingCycleContentsListIndex")
    return {};
}

__attribute__((weak)) nQuest::QUEST_ID sQuestManagerExt::getCycleContentsPlayNowQuestId() const {
    DDON_STUB("sQuestManagerExt::getCycleContentsPlayNowQuestId")
    __builtin_unreachable();
}

bool sQuestManagerExt::isCycleContentsDemoNow() const {
    return getCycleContentsMgrDemoNow() != nullptr;
}

bool sQuestManagerExt::isCycleContentsPlayNow() const {
    return getCycleContentsMgrPlayNow() != nullptr;
}

bool sQuestManagerExt::isCycleContentsPlayNowAll() const {
    return getCycleContentsMgrPlayNowAll() != nullptr;
}

__attribute__((weak)) bool sQuestManagerExt::isCycleContentsPlayNowResult() const {
    DDON_STUB("sQuestManagerExt::isCycleContentsPlayNowResult")
    return {};
}

bool sQuestManagerExt::isCycleContentsEndFlowNow() {
    u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 6) {
                    v2_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    bool t0 = static_cast<cCycleQuestManagerBase*>(v2_4)->isPlayNow();
    u32 v3_1 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v10_4;
    if (t0) {
        if (v3_1 == 0) {
            v10_4 = nullptr;
        } else {
            MtObject* * v3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i3_2 = 0;;) {
                if (v3_0[i3_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_0[i3_2]) + 8)) == 6) {
                        v10_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v3_0[i3_2])->getQuestManager();
                        break;
                    }
                }
                if ((i3_2 + 1u) < v3_1) {
                    i3_2 = i3_2 + 1u;
                } else {
                    v10_4 = nullptr;
                    break;
                }
            }
        }
    } else {
        cQuestManagerBase* v7_4;
        if (v3_1 == 0) {
            v7_4 = nullptr;
        } else {
            MtObject* * v5_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i5_2 = 0;;) {
                if (v5_0[i5_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v5_0[i5_2]) + 8)) == 7) {
                        v7_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v5_0[i5_2])->getQuestManager();
                        break;
                    }
                }
                if ((i5_2 + 1u) < v3_1) {
                    i5_2 = i5_2 + 1u;
                } else {
                    v7_4 = nullptr;
                    break;
                }
            }
        }
        if (!static_cast<cCycleQuestManagerBase*>(v7_4)->isPlayNow()) {
            return false;
        } else {
            u32 v8_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
            if (v8_0 == 0) {
                v10_4 = nullptr;
            } else {
                MtObject* * v8_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
                for (unsigned int i8_2 = 0;;) {
                    if (v8_1[i8_2] != nullptr) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v8_1[i8_2]) + 8)) == 7) {
                            v10_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v8_1[i8_2])->getQuestManager();
                            break;
                        }
                    }
                    if ((i8_2 + 1u) < v8_0) {
                        i8_2 = i8_2 + 1u;
                    } else {
                        v10_4 = nullptr;
                        break;
                    }
                }
            }
        }
    }
    return static_cast<cCycleQuestManagerBase*>(v10_4)->isEndFlowNow();
}

u32 sQuestManagerExt::getCycleContentsPoint() const {
    cCycleQuestManagerBase* pMgr = getCycleContentsMgrPlayNow();
    if (pMgr != nullptr) {
        return pMgr->getCycleContentsPoint();
    } else {
        return 0;
    }
}

__attribute__((weak)) bool sQuestManagerExt::isDispCycleContentsTimer() const {
    DDON_STUB("sQuestManagerExt::isDispCycleContentsTimer")
    return {};
}

__attribute__((weak)) f32 sQuestManagerExt::getCycleContentsTimer() const {
    u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 7) {
                    v2_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    if (!static_cast<cCycleQuestManagerBase*>(v2_4)->isPlayNow()) {
        u32 v3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
        cQuestManagerBase* v5_4;
        if (v3_0 == 0) {
            v5_4 = nullptr;
        } else {
            MtObject* * v3_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i3_2 = 0;;) {
                if (v3_1[i3_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 6) {
                        v5_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v3_1[i3_2])->getQuestManager();
                        break;
                    }
                }
                if ((i3_2 + 1u) < v3_0) {
                    i3_2 = i3_2 + 1u;
                } else {
                    v5_4 = nullptr;
                    break;
                }
            }
        }
        if (!static_cast<cCycleQuestManagerBase*>(v5_4)->isPlayNow()) {
            u32 v6_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
            cQuestManagerBase* v8_4;
            if (v6_0 == 0) {
                v8_4 = nullptr;
            } else {
                MtObject* * v6_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
                for (unsigned int i6_2 = 0;;) {
                    if (v6_1[i6_2] != nullptr) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v6_1[i6_2]) + 8)) == 8) {
                            v8_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v6_1[i6_2])->getQuestManager();
                            break;
                        }
                    }
                    if ((i6_2 + 1u) < v6_0) {
                        i6_2 = i6_2 + 1u;
                    } else {
                        v8_4 = nullptr;
                        break;
                    }
                }
            }
            if (!static_cast<cEndContentsManager*>(v8_4)->isPlayNow()) {
                return 0.0f;
            }
        }
    }
    return mpCycleContentsTimer->getRemainingTime();
}

void sQuestManagerExt::finishCycleContentsTimer() {
    mpCycleContentsTimer->finish();
    mIsDispContentsTimer = false;
}

__attribute__((weak)) void sQuestManagerExt::stopCycleContentsTimer() {
    DDON_STUB("sQuestManagerExt::stopCycleContentsTimer")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::hasStartedCycleContentsTimer() const {
    DDON_STUB("sQuestManagerExt::hasStartedCycleContentsTimer")
    return {};
}

u32 sQuestManagerExt::getCycleContentsPurposeNum() const {
    cCycleQuestManagerBase* pMgr = getCycleContentsMgrPlayNow();
    if (pMgr != nullptr) {
        return pMgr->getCyclePurposeNum();
    } else {
        return 0;
    }
}

MT_CTSTR sQuestManagerExt::getCycleContentsPurpose(u32 idx) const {
    cCycleQuestManagerBase* pMgr = getCycleContentsMgrPlayNow();
    if (pMgr != nullptr) {
        const s32 purposeNo = pMgr->getCyclePurposeNo(idx);
        if (purposeNo != -1) {
            MT_CTSTR t1 = getQuestPurposeMsg(pMgr->getMainTaskQuestId(), purposeNo);
            return t1;
        } else {
            return "";
        }
    } else {
        return "";
    }
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getCycleContentsNamePlayNow() const {
    DDON_STUB("sQuestManagerExt::getCycleContentsNamePlayNow")
    return {};
}

const nQuest::cCycleContentsResultInfo& sQuestManagerExt::getCycleContentsResultInfo() const {
    return mCycleContentsResultInfo;
}

MT_CTSTR sQuestManagerExt::getCycleContentsExtraBonusMsg(u32 extraBonusNo) const {
    return "";
}

const nQuest::CycleContentsRankingList& sQuestManagerExt::getCycleContentsRankingList() const {
    return mCycleContentsRankingList;
}

const nQuest::CycleContentsRankingRewardList& sQuestManagerExt::getCycleContentsRankingRewardList() const {
    return mCycleContentsRankingRewardList;
}

const nQuest::CycleContentsBorderRewardList& sQuestManagerExt::getCycleContentsBorderRewardList() const {
    return mCycleContentsBorderRewardList;
}

bool sQuestManagerExt::isCycleContentsTimerZero() const {
    return mIsContentsTimerTimeup;
}

__attribute__((weak)) f32 sQuestManagerExt::getCycleContentsPlayTime() const {
    DDON_STUB("sQuestManagerExt::getCycleContentsPlayTime")
    return {};
}

void sQuestManagerExt::clearRequestEntryInfoSave() {
    nNet::resetEntryBoardInfo(mRequestEntryInfoSave);
    mIsSaveRequestEntryInfoSave = false;
}

void sQuestManagerExt::saveRequestEntryInfo(const nNet::stEntryBoardItemInfo& info) {
    mIsSaveRequestEntryInfoSave = true;
    nNet::copyEntryBoardItemInfo(mRequestEntryInfoSave, info);
}

void sQuestManagerExt::loadRequestEntryInfo(nNet::stEntryBoardItemInfo& info) {
    nNet::copyEntryBoardItemInfo(info, mRequestEntryInfoSave);
}

void sQuestManagerExt::clearEntrySearchFilterSave() {
    mIsSaveEntrySearchFilterSave = false;
    mEntrySearchFilterSave.setDefaultData();
    mEntrySearchFilterSave.initSearchFilter(5);
}

__attribute__((weak)) void sQuestManagerExt::saveEntrySearchFilter(const cCharacterData::stSearchFilterSetting& info) {
    DDON_STUB("sQuestManagerExt::saveEntrySearchFilter")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::loadEntrySearchFilter(cCharacterData::stSearchFilterSetting& info) {
    DDON_STUB("sQuestManagerExt::loadEntrySearchFilter")
    /* stub */
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getCycleContentsName(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsName")
    return {};
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getCycleContentsInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsInfo")
    return {};
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getCycleContentsSituationName(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, u32 period, u32 situation) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsSituationName")
    return {};
}

MT_CTSTR sQuestManagerExt::getCycleContentsSituationNamePlayNow() const {
    const cCycleQuestManagerBase* pMgr = getCycleContentsMgrPlayNow();
    if (pMgr != nullptr) {
        return pMgr->getPlaySituationName();
    } else {
        return "";
    }
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getCycleContentsSituationInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, u32 period, u32 situation) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsSituationInfo")
    return {};
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getCycleContentsSituationDetailedInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, u32 period, u32 situation) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsSituationDetailedInfo")
    return {};
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getCycleContentsOrderPlace(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsOrderPlace")
    return {};
}

__attribute__((weak)) const nQuest::cCycleContentsSituationInfo* sQuestManagerExt::getCycleContentsSituationData(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsSituationData")
    return nullptr;
}

__attribute__((weak)) nQuest::QUEST_TYPE sQuestManagerExt::getCycleContentsQuestType(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsQuestType")
    return {};
}

void sQuestManagerExt::setEntryCycleContentCategory(u32 NpcId) {
    mEntryNpcId = NpcId;
    u32 v0_0 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_1[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    mEntryContentCategory = static_cast<cQuestResourceManager*>(v2_4)->getCycleContentsCategory(NpcId);
    u32 v3_0 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v6_4;
    if (v3_0 == 0) {
        v6_4 = nullptr;
    } else {
        MtObject* * v3_1 = mFunctionInfo.mpArray;
        for (unsigned int i3_2 = 0;;) {
            if (v3_1[i3_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 4) {
                    v6_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v3_1[i3_2])->getFunctionManager();
                    mEntryContentSubCategory = static_cast<cQuestResourceManager*>(v6_4)->getCycleContentsSubCategory(NpcId);
                    return;
                }
            }
            if ((i3_2 + 1u) < v3_0) {
                i3_2 = i3_2 + 1u;
            } else {
                break;
            }
        }
        v6_4 = nullptr;
    }
    mEntryContentSubCategory = static_cast<cQuestResourceManager*>(v6_4)->getCycleContentsSubCategory(NpcId);
}

void sQuestManagerExt::clearEntryCycleContentCategory() {
    mEntryContentCategory = 0;
    mEntryContentSubCategory = 0;
}

__attribute__((weak)) u32 sQuestManagerExt::getCycleContentEntryStage() {
    DDON_STUB("sQuestManagerExt::getCycleContentEntryStage")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getCycleContentEntryStartPos() {
    DDON_STUB("sQuestManagerExt::getCycleContentEntryStartPos")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::setCycleContentEntryNpcId(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::setCycleContentEntryNpcId")
    /* stub */
}

void sQuestManagerExt::setCycleContentEntryNpcId(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) {
    u32 v0_3 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_3;
    if (v0_3 == 0) {
        v2_3 = nullptr;
    } else {
        MtObject* * v0_1 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 4) {
                    v2_3 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_1[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_3) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_3 = nullptr;
                break;
            }
        }
    }
    u32 npcId = static_cast<cQuestResourceManager*>(v2_3)->getCycleContentsGatherNpcId(static_cast<u32>(category), static_cast<u32>(subCategory));
    mEntryNpcId = npcId;
    u32 v3_0 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v5_5;
    if (v3_0 == 0) {
        v5_5 = nullptr;
    } else {
        MtObject* * v3_1 = mFunctionInfo.mpArray;
        for (unsigned int i3_2 = 0;;) {
            if (v3_1[i3_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 4) {
                    v5_5 = static_cast<sQuestManagerExt::cFunctionInfo*>(v3_1[i3_2])->getFunctionManager();
                    break;
                }
            }
            if ((i3_2 + 1u) < v3_0) {
                i3_2 = i3_2 + 1u;
            } else {
                v5_5 = nullptr;
                break;
            }
        }
    }
    mEntryContentCategory = static_cast<cQuestResourceManager*>(v5_5)->getCycleContentsCategory(npcId);
    u32 v6_0 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v9_5;
    if (v6_0 == 0) {
        v9_5 = nullptr;
    } else {
        MtObject* * v6_1 = mFunctionInfo.mpArray;
        for (unsigned int i6_2 = 0;;) {
            if (v6_1[i6_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v6_1[i6_2]) + 8)) == 4) {
                    v9_5 = static_cast<sQuestManagerExt::cFunctionInfo*>(v6_1[i6_2])->getFunctionManager();
                    mEntryContentSubCategory = static_cast<cQuestResourceManager*>(v9_5)->getCycleContentsSubCategory(npcId);
                    return;
                }
            }
            if ((i6_2 + 1u) < v6_0) {
                i6_2 = i6_2 + 1u;
            } else {
                break;
            }
        }
        v9_5 = nullptr;
    }
    mEntryContentSubCategory = static_cast<cQuestResourceManager*>(v9_5)->getCycleContentsSubCategory(npcId);
}

cCycleQuestManagerBase* sQuestManagerExt::getCycleContentsMgr(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const {
    if (category == nQuest::CYCLE_CONTENTS_CATEGORY_RAID_BOSS) {
        u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
        if (v0_0 != 0) {
            MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i0_2 = 0;;) {
                if (v0_1[i0_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 7) {
                        return static_cast<cCycleQuestManagerBase*>(static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager());
                    }
                }
                if ((i0_2 + 1u) < v0_0) {
                    i0_2 = i0_2 + 1u;
                } else {
                    break;
                }
            }
        }
    } else {
        if (category == nQuest::CYCLE_CONTENTS_CATEGORY_FORT_DEFENSE) {
            u32 v3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
            if (v3_0 != 0) {
                MtObject* * v3_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
                for (unsigned int i3_2 = 0;;) {
                    if (v3_1[i3_2] != nullptr) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 6) {
                            return static_cast<cCycleQuestManagerBase*>(static_cast<sQuestManagerExt::cManagerInfo*>(v3_1[i3_2])->getQuestManager());
                        }
                    }
                    if ((i3_2 + 1u) < v3_0) {
                        i3_2 = i3_2 + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return nullptr;
}

__attribute__((weak)) cCycleQuestManagerBase* sQuestManagerExt::getCycleContentsMgr(u32 npcId) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsMgr")
    return nullptr;
}

__attribute__((weak)) cCycleQuestSubCategoryManager* sQuestManagerExt::getCycleContentsSubCategoryMgr(u32 npcId) const {
    DDON_STUB("sQuestManagerExt::getCycleContentsSubCategoryMgr")
    return nullptr;
}

__attribute__((weak)) u32 sQuestManagerExt::getCycleContentsScheduleIdFromQuestScheduleId(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::getCycleContentsScheduleIdFromQuestScheduleId")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isEnableEntryBoard() {
    DDON_STUB("sQuestManagerExt::isEnableEntryBoard")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::releaseEntryBoardChangePhase(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::releaseEntryBoardChangePhase")
    /* stub */
}

bool sQuestManagerExt::isDistEnableEntryBoard(u32 npcId) {
    cCycleQuestSubCategoryManager* pMgr = getCycleContentsSubCategoryMgr(npcId);
    if (pMgr != nullptr) {
        return pMgr->isDistEnable();
    } else {
        return true;
    }
}

__attribute__((weak)) nQuest::SCHEDULE_ID sQuestManagerExt::getCycleContentsScheduleIdFromSituation(nQuest::SCHEDULE_ID SituationScheduleId) {
    DDON_STUB("sQuestManagerExt::getCycleContentsScheduleIdFromSituation")
    __builtin_unreachable();
}

__attribute__((weak)) bool sQuestManagerExt::isDistributionSituation(nQuest::SCHEDULE_ID SituationScheduleId) {
    DDON_STUB("sQuestManagerExt::isDistributionSituation")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isHoldingAnyCycleContents() const {
    DDON_STUB("sQuestManagerExt::isHoldingAnyCycleContents")
    return {};
}

__attribute__((weak)) cCycleQuestManagerBase* sQuestManagerExt::getCycleContentsMgrDemoNow() const {
    u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 6) {
                    v2_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    bool t0 = static_cast<cCycleQuestManagerBase*>(v2_4)->isDemoNow();
    u32 v3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v12_0;
    if (t0) {
        if (v3_0 == 0) {
            v12_0 = nullptr;
        } else {
            MtObject* * v3_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i3_2 = 0;;) {
                if (v3_1[i3_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 6) {
                        v12_0 = static_cast<sQuestManagerExt::cManagerInfo*>(v3_1[i3_2])->getQuestManager();
                        return static_cast<cCycleQuestManagerBase*>(v12_0);
                    }
                }
                if ((i3_2 + 1u) < v3_0) {
                    i3_2 = i3_2 + 1u;
                } else {
                    break;
                }
            }
            v12_0 = nullptr;
        }
    } else {
        cQuestManagerBase* v8_4;
        if (v3_0 == 0) {
            v8_4 = nullptr;
        } else {
            MtObject* * v6_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i6_2 = 0;;) {
                if (v6_0[i6_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v6_0[i6_2]) + 8)) == 7) {
                        v8_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v6_0[i6_2])->getQuestManager();
                        break;
                    }
                }
                if ((i6_2 + 1u) < v3_0) {
                    i6_2 = i6_2 + 1u;
                } else {
                    v8_4 = nullptr;
                    break;
                }
            }
        }
        if (!static_cast<cCycleQuestManagerBase*>(v8_4)->isDemoNow()) {
            v12_0 = nullptr;
        } else {
            u32 v9_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
            if (v9_0 == 0) {
                v12_0 = nullptr;
            } else {
                MtObject* * v9_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
                for (unsigned int i9_2 = 0;;) {
                    if (v9_1[i9_2] != nullptr) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v9_1[i9_2]) + 8)) == 7) {
                            v12_0 = static_cast<sQuestManagerExt::cManagerInfo*>(v9_1[i9_2])->getQuestManager();
                            return static_cast<cCycleQuestManagerBase*>(v12_0);
                        }
                    }
                    if ((i9_2 + 1u) < v9_0) {
                        i9_2 = i9_2 + 1u;
                    } else {
                        break;
                    }
                }
                v12_0 = nullptr;
            }
        }
    }
    return static_cast<cCycleQuestManagerBase*>(v12_0);
}

__attribute__((weak)) cCycleQuestManagerBase* sQuestManagerExt::getCycleContentsMgrPlayNow() const {
    u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 6) {
                    v2_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    bool t0 = static_cast<cCycleQuestManagerBase*>(v2_4)->isPlayNow();
    u32 v3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v12_0;
    if (t0) {
        if (v3_0 == 0) {
            v12_0 = nullptr;
        } else {
            MtObject* * v3_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i3_2 = 0;;) {
                if (v3_1[i3_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 6) {
                        v12_0 = static_cast<sQuestManagerExt::cManagerInfo*>(v3_1[i3_2])->getQuestManager();
                        return static_cast<cCycleQuestManagerBase*>(v12_0);
                    }
                }
                if ((i3_2 + 1u) < v3_0) {
                    i3_2 = i3_2 + 1u;
                } else {
                    break;
                }
            }
            v12_0 = nullptr;
        }
    } else {
        cQuestManagerBase* v8_4;
        if (v3_0 == 0) {
            v8_4 = nullptr;
        } else {
            MtObject* * v6_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i6_2 = 0;;) {
                if (v6_0[i6_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v6_0[i6_2]) + 8)) == 7) {
                        v8_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v6_0[i6_2])->getQuestManager();
                        break;
                    }
                }
                if ((i6_2 + 1u) < v3_0) {
                    i6_2 = i6_2 + 1u;
                } else {
                    v8_4 = nullptr;
                    break;
                }
            }
        }
        if (!static_cast<cCycleQuestManagerBase*>(v8_4)->isPlayNow()) {
            v12_0 = nullptr;
        } else {
            u32 v9_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
            if (v9_0 == 0) {
                v12_0 = nullptr;
            } else {
                MtObject* * v9_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
                for (unsigned int i9_2 = 0;;) {
                    if (v9_1[i9_2] != nullptr) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v9_1[i9_2]) + 8)) == 7) {
                            v12_0 = static_cast<sQuestManagerExt::cManagerInfo*>(v9_1[i9_2])->getQuestManager();
                            return static_cast<cCycleQuestManagerBase*>(v12_0);
                        }
                    }
                    if ((i9_2 + 1u) < v9_0) {
                        i9_2 = i9_2 + 1u;
                    } else {
                        break;
                    }
                }
                v12_0 = nullptr;
            }
        }
    }
    return static_cast<cCycleQuestManagerBase*>(v12_0);
}

__attribute__((weak)) cCycleQuestManagerBase* sQuestManagerExt::getCycleContentsMgrPlayNowAll() const {
    u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 6) {
                    v2_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    bool t0 = static_cast<cCycleQuestManagerBase*>(v2_4)->isPlayNowAll();
    u32 v3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v12_0;
    if (t0) {
        if (v3_0 == 0) {
            v12_0 = nullptr;
        } else {
            MtObject* * v3_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i3_2 = 0;;) {
                if (v3_1[i3_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 6) {
                        v12_0 = static_cast<sQuestManagerExt::cManagerInfo*>(v3_1[i3_2])->getQuestManager();
                        return static_cast<cCycleQuestManagerBase*>(v12_0);
                    }
                }
                if ((i3_2 + 1u) < v3_0) {
                    i3_2 = i3_2 + 1u;
                } else {
                    break;
                }
            }
            v12_0 = nullptr;
        }
    } else {
        cQuestManagerBase* v8_4;
        if (v3_0 == 0) {
            v8_4 = nullptr;
        } else {
            MtObject* * v6_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i6_2 = 0;;) {
                if (v6_0[i6_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v6_0[i6_2]) + 8)) == 7) {
                        v8_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v6_0[i6_2])->getQuestManager();
                        break;
                    }
                }
                if ((i6_2 + 1u) < v3_0) {
                    i6_2 = i6_2 + 1u;
                } else {
                    v8_4 = nullptr;
                    break;
                }
            }
        }
        if (!static_cast<cCycleQuestManagerBase*>(v8_4)->isPlayNowAll()) {
            v12_0 = nullptr;
        } else {
            u32 v9_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
            if (v9_0 == 0) {
                v12_0 = nullptr;
            } else {
                MtObject* * v9_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
                for (unsigned int i9_2 = 0;;) {
                    if (v9_1[i9_2] != nullptr) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v9_1[i9_2]) + 8)) == 7) {
                            v12_0 = static_cast<sQuestManagerExt::cManagerInfo*>(v9_1[i9_2])->getQuestManager();
                            return static_cast<cCycleQuestManagerBase*>(v12_0);
                        }
                    }
                    if ((i9_2 + 1u) < v9_0) {
                        i9_2 = i9_2 + 1u;
                    } else {
                        break;
                    }
                }
                v12_0 = nullptr;
            }
        }
    }
    return static_cast<cCycleQuestManagerBase*>(v12_0);
}

bool sQuestManagerExt::isActiveQuest(nQuest::SCHEDULE_ID scheduleId, u32* pIdx, s32 dispType) const {
    u32 v0_2 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_2;
    if (v0_2 == 0) {
        v2_2 = nullptr;
    } else {
        MtObject* * v0_3 = mFunctionInfo.mpArray;
        for (unsigned int i0_1 = 0;;) {
            if (v0_3[i0_1] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[i0_1]) + 8)) == 3) {
                    v2_2 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_3[i0_1])->getFunctionManager();
                    break;
                }
            }
            if ((i0_1 + 1u) < v0_2) {
                i0_1 = i0_1 + 1u;
            } else {
                v2_2 = nullptr;
                break;
            }
        }
    }
    bool t0 = static_cast<cActiveQuestManager*>(v2_2)->isActiveQuest(scheduleId, pIdx, dispType);
    return t0;
}

__attribute__((weak)) u32 sQuestManagerExt::getActiveQuestDispType() const {
    DDON_STUB("sQuestManagerExt::getActiveQuestDispType")
    return {};
}

__attribute__((weak)) nQuest::SCHEDULE_ID sQuestManagerExt::getActiveQuest(u32 idx) const {
    DDON_STUB("sQuestManagerExt::getActiveQuest")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::SCHEDULE_ID sQuestManagerExt::getActiveQuest(u32 dispType, u32 idx) const {
    DDON_STUB("sQuestManagerExt::getActiveQuest")
    __builtin_unreachable();
}

__attribute__((weak)) void sQuestManagerExt::setActiveQuest(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("sQuestManagerExt::setActiveQuest")
    /* stub */
}

bool sQuestManagerExt::isEnableRequestActiveQuest() {
    u32 v0_1 = mFunctionInfo.mLength;
    bool v8_0;
    if (v0_1 != 0) {
        MtObject* * v0_2 = mFunctionInfo.mpArray;
        unsigned int i0_0 = 0;
        unsigned int i2_0;
        cQuestFunctionManagerBase* v5_4;
        for (;;) {
            if (v0_2[i0_0] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_2[i0_0]) + 8)) == 3) {
                    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v0_2[i0_0]) + 16)) == 0) {
                        v8_0 = false;
                    } else {
                        i2_0 = 0;
                        for (;;) {
                            if (v0_2[i2_0] != nullptr) {
                                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_2[i2_0]) + 8)) == 3) {
                                    v5_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_2[i2_0])->getFunctionManager();
                                    break;
                                }
                            }
                            if ((i2_0 + 1u) < v0_1) {
                                i2_0 = i2_0 + 1u;
                            } else {
                                v5_4 = nullptr;
                                break;
                            }
                        }
                        v8_0 = static_cast<cActiveQuestManager*>(v5_4)->isEnableRequest();
                    }
                    break;
                }
            }
            if ((i0_0 + 1u) < v0_1) {
                i0_0 = i0_0 + 1u;
            } else {
                v8_0 = false;
                break;
            }
        }
    } else {
        v8_0 = false;
    }
    return v8_0;
}

bool sQuestManagerExt::isEnableRequestAutoActiveQuest() {
    u32 v0_1 = mFunctionInfo.mLength;
    bool v8_0;
    if (v0_1 != 0) {
        MtObject* * v0_2 = mFunctionInfo.mpArray;
        unsigned int i0_0 = 0;
        unsigned int i2_0;
        cQuestFunctionManagerBase* v5_4;
        for (;;) {
            if (v0_2[i0_0] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_2[i0_0]) + 8)) == 3) {
                    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v0_2[i0_0]) + 16)) == 0) {
                        v8_0 = false;
                    } else {
                        i2_0 = 0;
                        for (;;) {
                            if (v0_2[i2_0] != nullptr) {
                                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_2[i2_0]) + 8)) == 3) {
                                    v5_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_2[i2_0])->getFunctionManager();
                                    break;
                                }
                            }
                            if ((i2_0 + 1u) < v0_1) {
                                i2_0 = i2_0 + 1u;
                            } else {
                                v5_4 = nullptr;
                                break;
                            }
                        }
                        v8_0 = static_cast<cActiveQuestManager*>(v5_4)->isEnableRequestNum();
                    }
                    break;
                }
            }
            if ((i0_0 + 1u) < v0_1) {
                i0_0 = i0_0 + 1u;
            } else {
                v8_0 = false;
                break;
            }
        }
    } else {
        v8_0 = false;
    }
    return v8_0;
}

__attribute__((weak)) void sQuestManagerExt::recvNoticeActiveQuest(u32 characterId, const PriorityQuestVec& priorityQuestList) {
    DDON_STUB("sQuestManagerExt::recvNoticeActiveQuest")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::deleteActiveQuestList(u32 characterId) {
    DDON_STUB("sQuestManagerExt::deleteActiveQuestList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::reqGetActiveQuest() {
    DDON_STUB("sQuestManagerExt::reqGetActiveQuest")
    /* stub */
}

void sQuestManagerExt::cancelActiveQuest(nQuest::SCHEDULE_ID scheduleId) {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 3) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    static_cast<cActiveQuestManager*>(v2_4)->cancelActiveQuest(scheduleId);
}

u32 sQuestManagerExt::getEndContentsPurposeNum() const {
    u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 8) {
                    v2_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    cQuestManagerBase* v6_4;
    if (!static_cast<cEndContentsManager*>(v2_4)->isPlayNow()) {
        return 0;
    } else {
        u32 v3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
        if (v3_0 == 0) {
            v6_4 = nullptr;
        } else {
            MtObject* * v3_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (unsigned int i3_2 = 0;;) {
                if (v3_1[i3_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 8) {
                        v6_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v3_1[i3_2])->getQuestManager();
                        return static_cast<cEndContentsManager*>(v6_4)->getEndContentsPurposeNum();
                    }
                }
                if ((i3_2 + 1u) < v3_0) {
                    i3_2 = i3_2 + 1u;
                } else {
                    break;
                }
            }
            v6_4 = nullptr;
        }
    }
    return static_cast<cEndContentsManager*>(v6_4)->getEndContentsPurposeNum();
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getEndContentsPurpose(u32 idx) const {
    DDON_STUB("sQuestManagerExt::getEndContentsPurpose")
    return {};
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getEndContentsName() const {
    DDON_STUB("sQuestManagerExt::getEndContentsName")
    return {};
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getEndContentsName(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::getEndContentsName")
    return {};
}

bool sQuestManagerExt::isLeftCycleTimer(f32 sec) const {
    f32 t0 = sQuestManagerExt::getInstance()->getCycleContentsTimer();
    return (sec >= t0) && (t0 > 0.0f);
}

void sQuestManagerExt::setEndContentsEntry(u32 npcId, bool solo) {
    mEntryNpcId = npcId;
    mEntrySolo = solo;
    mEntryContentCategory = 0;
    mEntryContentSubCategory = 0;
}

u32 sQuestManagerExt::getEndContentEntryStage() {
    cNpcMeetingPlace* pPlace = sNpcManager::getInstance()->getMeetingPlace(mEntryNpcId);
    if (pPlace != nullptr) {
        return static_cast<u32>(pPlace->mStageNo);
    } else {
        return 0;
    }
}

u32 sQuestManagerExt::getEndContentEntryStartPos() {
    cNpcMeetingPlace* pPlace = sNpcManager::getInstance()->getMeetingPlace(mEntryNpcId);
    if (pPlace != nullptr) {
        return pPlace->mStartPosNo;
    } else {
        return 0;
    }
}

u32 sQuestManagerExt::getEndContentsGroupNo(u32 NpcId) const {
    u32 v0_0 = mManagerInfo.mLength;
    if (v0_0 != 0) {
        MtObject* * v0_1 = mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 8) {
                    if (static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager() != nullptr) {
                        return static_cast<cEndContentsManager*>(static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager())->getEndContentsGroupNo(NpcId);
                    } else {
                        return 0;
                    }
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
    }
    return 0;
}

u32 sQuestManagerExt::getEndContentsGroupNo(nQuest::QUEST_ID QuestId) const {
    u32 t0 = QuestId.toU32();
    if (static_cast<int>(t0) <= 50208999) {
        if (static_cast<int>(t0) <= 50204999) {
            if ((t0 - 0x2FE01A8u) > 1u) {
                if ((t0 - 0x2FE0590u) > 1u) {
                    if ((t0 - 0x2FE0978u) <= 1u) {
                        return 2;
                    } else {
                        return 1;
                    }
                } else {
                    return 2;
                }
            } else {
                return 2;
            }
        } else {
            if ((t0 - 0x2FE1148u) <= 3u) {
                return 4;
            } else {
                return 1;
            }
        }
    } else {
        if (t0 == 0x2FE20E8) {
            return 3;
        } else {
            return 1;
        }
    }
}

u32 sQuestManagerExt::getEndContentsEntryNpcId(u32 GroupNo) const {
    u32 v0_0 = mManagerInfo.mLength;
    if (v0_0 != 0) {
        MtObject* * v0_1 = mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 8) {
                    if (static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager() != nullptr) {
                        return static_cast<cEndContentsManager*>(static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager())->getEndContentsEntryNpcId(GroupNo);
                    } else {
                        return 0;
                    }
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
    }
    return 0;
}

__attribute__((weak)) bool sQuestManagerExt::isEndContentsPlayNow() const {
    DDON_STUB("sQuestManagerExt::isEndContentsPlayNow")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isContentsPlayNowEndFlow() {
    DDON_STUB("sQuestManagerExt::isContentsPlayNowEndFlow")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::registEndContents(const CEndContentsGroup& group) {
    DDON_STUB("sQuestManagerExt::registEndContents")
    /* stub */
}

cQuestManagerBase* sQuestManagerExt::getQuestManager(nQuest::QUEST_TYPE type) const {
    if (mManagerInfo.mLength != 0) {
        u32 i = 0;
        do {
            if (mManagerInfo.mpArray[i] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mManagerInfo.mpArray[i]) + 8)) == static_cast<unsigned int>(type)) {
                    return static_cast<sQuestManagerExt::cManagerInfo*>(mManagerInfo.mpArray[i])->getQuestManager();
                }
            }
            i += 1u;
        } while (i < mManagerInfo.mLength);
    }
    return nullptr;
}

__attribute__((weak)) bool sQuestManagerExt::registQuestManager(nQuest::QUEST_TYPE type, cQuestManagerBase* pMgr) {
    DDON_STUB("sQuestManagerExt::registQuestManager")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::registFunctionManager(nQuest::FUNCTION_TYPE type, cQuestFunctionManagerBase* pMgr) {
    DDON_STUB("sQuestManagerExt::registFunctionManager")
    return {};
}

__attribute__((weak)) cPRTManager* sQuestManagerExt::getPRTMgr() const {
    DDON_STUB("sQuestManagerExt::getPRTMgr")
    return nullptr;
}

__attribute__((weak)) cQuestMemoryPool* sQuestManagerExt::getQuestMemoryPool() const {
    DDON_STUB("sQuestManagerExt::getQuestMemoryPool")
    return nullptr;
}

__attribute__((weak)) cQuestMarkerManager* sQuestManagerExt::getQuestMarkerMgr() const {
    DDON_STUB("sQuestManagerExt::getQuestMarkerMgr")
    return nullptr;
}

__attribute__((weak)) cActiveQuestManager* sQuestManagerExt::getActiveQuestMgr() const {
    DDON_STUB("sQuestManagerExt::getActiveQuestMgr")
    return nullptr;
}

__attribute__((weak)) cQuestResourceManager* sQuestManagerExt::getQuestResourceMgr() const {
    DDON_STUB("sQuestManagerExt::getQuestResourceMgr")
    return nullptr;
}

__attribute__((weak)) cQuestResourceLoadManager* sQuestManagerExt::getQuestResourceLoadMgr() const {
    DDON_STUB("sQuestManagerExt::getQuestResourceLoadMgr")
    return nullptr;
}

__attribute__((weak)) cQuestSvRequestManager* sQuestManagerExt::getQuestSvRequestMgr() const {
    DDON_STUB("sQuestManagerExt::getQuestSvRequestMgr")
    return nullptr;
}

__attribute__((weak)) cQuestSvNoticeManager* sQuestManagerExt::getQuestSvNoticeMgr() const {
    DDON_STUB("sQuestManagerExt::getQuestSvNoticeMgr")
    return nullptr;
}

__attribute__((weak)) cQuestDeliverManager* sQuestManagerExt::getQuestDeliverMgr() const {
    DDON_STUB("sQuestManagerExt::getQuestDeliverMgr")
    return nullptr;
}

__attribute__((weak)) cQuestEventManager* sQuestManagerExt::getQuestEventMgr() const {
    DDON_STUB("sQuestManagerExt::getQuestEventMgr")
    return nullptr;
}

__attribute__((weak)) cQuestPhaseManager* sQuestManagerExt::getQuestPhaseMgr() const {
    DDON_STUB("sQuestManagerExt::getQuestPhaseMgr")
    return nullptr;
}

__attribute__((weak)) bool sQuestManagerExt::isEmptyRequestQueue() const {
    DDON_STUB("sQuestManagerExt::isEmptyRequestQueue")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::moveManager() {
    DDON_STUB("sQuestManagerExt::moveManager")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::moveManagerBefore() {
    DDON_STUB("sQuestManagerExt::moveManagerBefore")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::moveManagerAfter() {
    DDON_STUB("sQuestManagerExt::moveManagerAfter")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isClearedMainQuest(nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::isClearedMainQuest")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isClearedTutorialQuest(nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::isClearedTutorialQuest")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isClearedEndContents(nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::isClearedEndContents")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isClearedQuest(nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::isClearedQuest")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isClearedQuest(nQuest::SCHEDULE_ID ScheduleId) const {
    DDON_STUB("sQuestManagerExt::isClearedQuest")
    return {};
}

const nQuest::QuestIdArray& sQuestManagerExt::getClearedMainQuesetList() const {
    return mClearedMainQuestList;
}

__attribute__((weak)) bool sQuestManagerExt::isMainQuestHelper() {
    DDON_STUB("sQuestManagerExt::isMainQuestHelper")
    return {};
}

bool sQuestManagerExt::isOrderedSoloMainQuest() {
    unsigned int i0_8 = 0;
    MtObject* * p1_0;
    MtObject* v2_1;
    MtObject* * p3_0;
    MtObject* v4_1;
    unsigned int i5_10;
    for (;;) {
        p1_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (;;) {
            v2_1 = *p1_0;
            if (v2_1 != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v2_1) + 8)) == 0) {
                    break;
                }
            }
            p1_0 += 1;
        }
        if (i0_8 >= static_cast<sQuestManagerExt::cManagerInfo*>(v2_1)->getQuestManager()->getQuestNum()) {
            break;
        } else {
            p3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        }
        for (;;) {
            v4_1 = *p3_0;
            if (v4_1 != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v4_1) + 8)) == 0) {
                    break;
                }
            }
            p3_0 += 1;
        }
        cQuestTask* pTask = static_cast<sQuestManagerExt::cManagerInfo*>(v4_1)->getQuestManager()->getQuestTask(i0_8);
        if (pTask != nullptr) {
            if (pTask->isMyMainQuest()) {
                if (pTask->isOrder()) {
                    if (pTask->getOrderConditionNum() != 0) {
                        i5_10 = 0;
                        for (;;) {
                            u32 t0 = pTask->getOrderConditionType(i5_10);
                            if (t0 != 3) {
                                if (t0 == 10) {
                                    return true;
                                } else {
                                    if ((i5_10 + 1u) < pTask->getOrderConditionNum()) {
                                        i5_10 += 1u;
                                    } else {
                                        break;
                                    }
                                }
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        i0_8 += 1u;
    }
    return false;
}

void sQuestManagerExt::requestGetQuestCompleteList(nQuest::SV_QUEST_TYPE questType) {
    if (questType == nQuest::SV_QUEST_TYPE_MAIN) {
        mIsGetQuestClearList = false;
    }
    cArea* pArea = sArea::getInstance()->mpArea[1];
    const MtDTI& t0 = pArea->getDTI();
    MT_CTSTR v0_1 = aMenu::DTI.mName;
    const MtDTI* v0_0 = &t0;
    const MtDTI* v1_0;
    MT_CTSTR v1_1;
    for (;;) {
        if (v0_1 != v0_0->mName) {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                cQuestSvRequest* t3 = cQuestSvRequestManager::pushRequest(cQuestSvReqGetQuestCompleteList::DTI);
                if (t3 != nullptr) {
                    t3->setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvRequest::PCallbackFunc>(&::sQuestManagerExt::callbackGetQuestCompleteList));
                }
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 40) = static_cast<unsigned int>(questType);
                return;
            }
        } else {
            if (pArea == nullptr) {
                cQuestSvRequest* t3 = cQuestSvRequestManager::pushRequest(cQuestSvReqGetQuestCompleteList::DTI);
                if (t3 != nullptr) {
                    t3->setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvRequest::PCallbackFunc>(&::sQuestManagerExt::callbackGetQuestCompleteList));
                }
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 40) = static_cast<unsigned int>(questType);
                return;
            } else {
                const MtDTI& t2 = pArea->getDTI();
                v1_1 = aMenu::DTI.mName;
                v1_0 = &t2;
                break;
            }
        }
    }
    for (;;) {
        if (v1_1 == v1_0->mName) {
            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getQuestCompleteList(static_cast<u32>(questType));
            mHasRequestedGetCompleteListFromaMenu = true;
            return;
        } else {
            if (v1_0->mpParent != nullptr) {
                v1_0 = v1_0->mpParent;
            } else {
                break;
            }
        }
    }
    cQuestSvRequest* t3 = cQuestSvRequestManager::pushRequest(cQuestSvReqGetQuestCompleteList::DTI);
    if (t3 != nullptr) {
        t3->setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvRequest::PCallbackFunc>(&::sQuestManagerExt::callbackGetQuestCompleteList));
    }
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 40) = static_cast<unsigned int>(questType);
}

__attribute__((weak)) void sQuestManagerExt::callbackGetQuestCompleteList(u32 errorCode) {
    DDON_STUB("sQuestManagerExt::callbackGetQuestCompleteList")
    /* stub */
}

__attribute__((weak)) const nQuest::QuestMarkerArray& sQuestManagerExt::getQuestMarkerCurrentStage() const {
    DDON_STUB("sQuestManagerExt::getQuestMarkerCurrentStage")
    __builtin_unreachable();
}

__attribute__((weak)) const nQuest::QuestMarkerArray& sQuestManagerExt::getQuestMarkerForMap() const {
    DDON_STUB("sQuestManagerExt::getQuestMarkerForMap")
    __builtin_unreachable();
}

void sQuestManagerExt::requestGetRewardBoxList() {
    mIsCompleteGetRewardList = false;
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getRewardBoxList();
}

const RewardBoxRecordVec& sQuestManagerExt::getRewardBoxData() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getRewardBoxRecordListRef();
}

__attribute__((weak)) void sQuestManagerExt::completeRewardBoxList() {
    DDON_STUB("sQuestManagerExt::completeRewardBoxList")
    /* stub */
}

void sQuestManagerExt::requestGetCycleContentsRewardList() {
    mIsCompleteGetCycleContentsRewardList = false;
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getCycleContentsRewardList();
}

const RewardBoxRecordVec& sQuestManagerExt::getCycleContentsRewardData() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getCycleContentsRewardListPacket()->m_RewardBoxRecordList;
}

const CycleContentsRewardRecordVec& sQuestManagerExt::getCycleContentsRewardExData() const {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getCycleContentsRewardListPacket()->m_CycleContentsRewardRecordList;
}

__attribute__((weak)) void sQuestManagerExt::completeCycleContentsRewardList() {
    DDON_STUB("sQuestManagerExt::completeCycleContentsRewardList")
    /* stub */
}

MT_CTSTR sQuestManagerExt::getQuestName(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    MT_CTSTR t0 = static_cast<cQuestResourceManager*>(v2_4)->getQuestName(questId);
    return t0;
}

MT_CTSTR sQuestManagerExt::getRewardBoxQuestName(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    MT_CTSTR t0 = static_cast<cQuestResourceManager*>(v2_4)->getRewardBoxQuestName(questId);
    return t0;
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getQuestNameMyMainQuest() const {
    DDON_STUB("sQuestManagerExt::getQuestNameMyMainQuest")
    return {};
}

MT_CTSTR sQuestManagerExt::getQuestDetail(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    MT_CTSTR t0 = static_cast<cQuestResourceManager*>(v2_4)->getOrderMsg(questId);
    return t0;
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getQuestPartyPurposeMsg(nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::getQuestPartyPurposeMsg")
    return {};
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getQuestPurposeMsg(nQuest::QUEST_ID questId, s32 idx) const {
    DDON_STUB("sQuestManagerExt::getQuestPurposeMsg")
    return {};
}

MT_CTSTR sQuestManagerExt::getQuestFindInfo(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    MT_CTSTR t0 = static_cast<cQuestResourceManager*>(v2_4)->getFindInfoMsg(questId);
    return t0;
}

MT_CTSTR sQuestManagerExt::getQuestFindInfoDetail(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    MT_CTSTR t0 = static_cast<cQuestResourceManager*>(v2_4)->getFindInfoDetailMsg(questId);
    return t0;
}

MT_CTSTR sQuestManagerExt::getQuestContentsDetail(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    MT_CTSTR t0 = static_cast<cQuestResourceManager*>(v2_4)->getContentsDetailMsg(questId);
    return t0;
}

__attribute__((weak)) u32 sQuestManagerExt::getQuestBaseLevel(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::getQuestBaseLevel")
    return {};
}

bool sQuestManagerExt::isFinishedLoadingQuestResource(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    bool t0 = static_cast<cQuestResourceManager*>(v2_4)->isFinishedLoading(questId);
    return t0;
}

bool sQuestManagerExt::isFinishedLoadingQuestResourceRewardBox(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    bool t0 = static_cast<cQuestResourceManager*>(v2_4)->isFinishedLoadingRewardBox(questId);
    return t0;
}

cTalkMsgData* sQuestManagerExt::getQuestMessageData(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    cTalkMsgData* t0 = static_cast<cQuestResourceManager*>(v2_4)->getMessageData(questId);
    return t0;
}

cTalkMsgData* sQuestManagerExt::getQuestExmineData(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    cTalkMsgData* t0 = static_cast<cQuestResourceManager*>(v2_4)->getExmineData(questId);
    return t0;
}

__attribute__((weak)) u32 sQuestManagerExt::getQuestArea(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::getQuestArea")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getJobTutorialQuestOrderNum() const {
    DDON_STUB("sQuestManagerExt::getJobTutorialQuestOrderNum")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isOrderJobTutorialQuest(nQuest::QUEST_ID jobTutoQuestId) const {
    DDON_STUB("sQuestManagerExt::isOrderJobTutorialQuest")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::setIsOpenNewspaper(bool isOpen) {
    DDON_STUB("sQuestManagerExt::setIsOpenNewspaper")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::setReleaseContentResouce(u32 category, nQuest::SCHEDULE_ID shceduleId) {
    DDON_STUB("sQuestManagerExt::setReleaseContentResouce")
    /* stub */
}

void sQuestManagerExt::loadQuestResource(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    static_cast<cQuestResourceManager*>(v2_4)->requestLoadResource(questId);
}

void sQuestManagerExt::loadQuestResourceRewardBox(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    static_cast<cQuestResourceManager*>(v2_4)->requestLoadResourceRewardBox(questId);
}

void sQuestManagerExt::releaseRewardBox() {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_4;
    if (v0_1 == 0) {
        v3_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v3_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    static_cast<cQuestResourceManager*>(v3_4)->releaseRewardBox();
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearRewardBoxListPacket();
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearCycleContentsRewardListPacket();
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearCycleContentsRewardItemPacket();
                    return;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_4 = nullptr;
    }
    static_cast<cQuestResourceManager*>(v3_4)->releaseRewardBox();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearRewardBoxListPacket();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearCycleContentsRewardListPacket();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearCycleContentsRewardItemPacket();
}

bool sQuestManagerExt::isQuestFlag(u32 flagNo) const {
    bool t0 = isQuestFlag(flagNo, nQuest::INVALID_QUEST_ID);
    return t0;
}

__attribute__((weak)) bool sQuestManagerExt::isQuestFlag(u32 flagNo, nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::isQuestFlag")
    return {};
}

bool sQuestManagerExt::isMyQuestFlag(u32 flagNo) const {
    bool t0 = isMyQuestFlag(flagNo, nQuest::INVALID_QUEST_ID);
    return t0;
}

__attribute__((weak)) bool sQuestManagerExt::isMyQuestFlag(u32 flagNo, nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::isMyQuestFlag")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isQuestLayoutFlag(u32 flagNo, nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::isQuestLayoutFlag")
    return {};
}

bool sQuestManagerExt::isEnableParty_Invite() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 48)) & 2) >> 1);
}

bool sQuestManagerExt::isEnableSetQuest() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 48)) & 8) >> 3);
}

bool sQuestManagerExt::isEnableCycleQuest() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 48)) & 16) >> 4);
}

bool sQuestManagerExt::isEnableClan() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 51)) & 8) >> 3);
}

bool sQuestManagerExt::isEnableRimStone() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 49)) & 16) >> 4);
}

bool sQuestManagerExt::isEnableLightQuest() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 49)) & 32) >> 5);
}

bool sQuestManagerExt::isEnableQuickParty() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 52)) & 4) >> 2);
}

bool sQuestManagerExt::isEnableAreaMaster() {
    return static_cast<bool>(static_cast<unsigned long>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 49)) >> 7);
}

bool sQuestManagerExt::isEnableMenu_Option() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 51)) & 16) >> 4);
}

bool sQuestManagerExt::isEnableMenu_VisualEquip() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 48)) & 64) >> 6);
}

bool sQuestManagerExt::isEnableMenu_Pawn() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 48)) & 4) >> 2);
}

__attribute__((weak)) bool sQuestManagerExt::isEnableMenu_Newspaper() {
    DDON_STUB("sQuestManagerExt::isEnableMenu_Newspaper")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isEnableMenu_Master() {
    DDON_STUB("sQuestManagerExt::isEnableMenu_Master")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isEnableMenu_RimWarp() {
    DDON_STUB("sQuestManagerExt::isEnableMenu_RimWarp")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isEnableMenu_Party() {
    DDON_STUB("sQuestManagerExt::isEnableMenu_Party")
    return {};
}

bool sQuestManagerExt::isEnableMenu_Clan() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 51)) & 8) >> 3);
}

__attribute__((weak)) bool sQuestManagerExt::isEnableMenu_MatchingProf() {
    DDON_STUB("sQuestManagerExt::isEnableMenu_MatchingProf")
    return {};
}

bool sQuestManagerExt::isEnableMyRoom() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 54)) & 2) >> 1);
}

bool sQuestManagerExt::isChangeBgmIsland() {
    return static_cast<bool>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 54)) & 1);
}

bool sQuestManagerExt::isEnablePlayPoint() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 55)) & 2) >> 1);
}

__attribute__((weak)) cQuestTask* sQuestManagerExt::getQuestTask(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::getQuestTask")
    return nullptr;
}

__attribute__((weak)) cQuestTask* sQuestManagerExt::getQuestTask(nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::getQuestTask")
    return nullptr;
}

bool sQuestManagerExt::isPlayMainQuest(nQuest::QUEST_ID questId) const {
    MtObject* * p0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 0) {
                break;
            }
        }
        p0_0 += 1;
    }
    cQuestTask* t0 = static_cast<sQuestManagerExt::cManagerInfo*>(v1_1)->getQuestManager()->getQuestTask(questId);
    return t0 != nullptr;
}

bool sQuestManagerExt::isEnableOrder(nQuest::SCHEDULE_ID scheduleId) const {
    nQuest::RET_DISABLE_ORDER_CONDITION_TYPE t0 = getEnableOrder(scheduleId, true);
    return t0 == nQuest::RET_DIS_ORDER_CONDITION_TYPE_NONE;
}

__attribute__((weak)) bool sQuestManagerExt::isEnableOrderMySelf(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::isEnableOrderMySelf")
    return {};
}

__attribute__((weak)) nQuest::RET_DISABLE_ORDER_CONDITION_TYPE sQuestManagerExt::getEnableOrder(nQuest::SCHEDULE_ID scheduleId, bool IsLeader) const {
    DDON_STUB("sQuestManagerExt::getEnableOrder")
    return {};
}

nQuest::RET_DISABLE_ORDER_CONDITION_TYPE sQuestManagerExt::getEnableOrderMySelf(nQuest::SCHEDULE_ID scheduleId) const {
    nQuest::RET_DISABLE_ORDER_CONDITION_TYPE t0 = getEnableOrder(scheduleId, false);
    return t0;
}

__attribute__((weak)) bool sQuestManagerExt::canProgress(nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::canProgress")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::canProgress(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::canProgress")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getOfferedChaliceNum() const {
    DDON_STUB("sQuestManagerExt::getOfferedChaliceNum")
    return {};
}

__attribute__((weak)) nQuest::QUEST_ID sQuestManagerExt::getQuestId(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::getQuestId")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::SCHEDULE_ID sQuestManagerExt::getScheduleIdMyMainQuest() const {
    DDON_STUB("sQuestManagerExt::getScheduleIdMyMainQuest")
    __builtin_unreachable();
}

u32 sQuestManagerExt::getProgressMyMainQuest() const {
    MtObject* * p0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 0) {
                break;
            }
        }
        p0_0 += 1;
    }
    const u32 questNum = static_cast<sQuestManagerExt::cManagerInfo*>(v1_1)->getQuestManager()->getQuestNum();
    unsigned int v7_11;
    if (questNum == 0) {
        v7_11 = 0;
    } else {
        unsigned int i2_3 = 0;
        MtObject* * p3_0;
        MtObject* v4_1;
        for (;;) {
            p3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (;;) {
                v4_1 = *p3_0;
                if (v4_1 != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v4_1) + 8)) == 0) {
                        break;
                    }
                }
                p3_0 += 1;
            }
            cQuestTask* t0 = static_cast<sQuestManagerExt::cManagerInfo*>(v4_1)->getQuestManager()->getQuestTask(i2_3);
            if (t0 != nullptr) {
                if (!t0->isOrder()) {
                    return t0->getBlockNo(0u);
                } else {
                    v7_11 = t0->getPurpose() | 65536;
                    return v7_11;
                }
            } else {
                if ((i2_3 + 1u) < questNum) {
                    i2_3 += 1u;
                } else {
                    break;
                }
            }
        }
        v7_11 = 0;
    }
    return v7_11;
}

__attribute__((weak)) bool sQuestManagerExt::isHelper(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::isHelper")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::cancelQuest(const nQuest::cGUIListData* pIndex) {
    DDON_STUB("sQuestManagerExt::cancelQuest")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isFinishedCancelQuest() const {
    DDON_STUB("sQuestManagerExt::isFinishedCancelQuest")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getBoardDataList(nQuest::GUIBoardDataArray& list) const {
    DDON_STUB("sQuestManagerExt::getBoardDataList")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getOrderQuestListDataList(nQuest::QUEST_TYPE type, nQuest::GUIListDataArray& list) const {
    DDON_STUB("sQuestManagerExt::getOrderQuestListDataList")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getWaitOrderQuestListDataList(nQuest::GUIListDataArray& list) const {
    DDON_STUB("sQuestManagerExt::getWaitOrderQuestListDataList")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getWaitDeliverQuestDeliveryDataList(nQuest::QUEST_TYPE type, nQuest::GUIDeliveryDataArraay& list) const {
    DDON_STUB("sQuestManagerExt::getWaitDeliverQuestDeliveryDataList")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getMoveQuestAreaMasterDataListNum(u32 areaId) const {
    DDON_STUB("sQuestManagerExt::getMoveQuestAreaMasterDataListNum")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getMoveQuestAreaMasterDataList(u32 areaId, nQuest::GUIAreaMasterDataArray& list) const {
    DDON_STUB("sQuestManagerExt::getMoveQuestAreaMasterDataList")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getOrderQuestActiveDataList(nQuest::QUEST_TYPE type, nQuest::GUIActiveDataArray& list) const {
    DDON_STUB("sQuestManagerExt::getOrderQuestActiveDataList")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getLeaderOrderQuestListDataList(nQuest::QUEST_TYPE type, nQuest::GUIListDataArray& list) const {
    DDON_STUB("sQuestManagerExt::getLeaderOrderQuestListDataList")
    return {};
}

__attribute__((weak)) nQuest::SCHEDULE_ID sQuestManagerExt::getQuestTargetEmScheduleId(uCharacter* pEm, nQuest::cQuestMarker* * ppMarker) const {
    DDON_STUB("sQuestManagerExt::getQuestTargetEmScheduleId")
    __builtin_unreachable();
}

nQuest::SCHEDULE_ID sQuestManagerExt::getQuestTargetEmScheduleId(uCharacter* pEm) const {
    return getQuestTargetEmScheduleId(pEm, static_cast<nQuest::cQuestMarker* *>(nullptr));
}

__attribute__((weak)) u32 sQuestManagerExt::getQuestTargetOmScheduleId(uOmModel* pOm) const {
    DDON_STUB("sQuestManagerExt::getQuestTargetOmScheduleId")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isUpdateIndexList(nQuest::QUEST_TYPE type) const {
    DDON_STUB("sQuestManagerExt::isUpdateIndexList")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isUpdateIndexListForSetQuest(u32 areaId) const {
    DDON_STUB("sQuestManagerExt::isUpdateIndexListForSetQuest")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isUpdateIndexListForOrder() const {
    DDON_STUB("sQuestManagerExt::isUpdateIndexListForOrder")
    return {};
}

void sQuestManagerExt::requestOrderLightQuest(const nQuest::SCHEDULE_ID& scheduleId) {
    u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 2) {
                    v2_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    static_cast<cLightQuestManager*>(v2_4)->requestOrderQuest(scheduleId);
}

__attribute__((weak)) bool sQuestManagerExt::isFinishedOrderLightQuest() const {
    DDON_STUB("sQuestManagerExt::isFinishedOrderLightQuest")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::requestGpCompleteLightQuest() {
    DDON_STUB("sQuestManagerExt::requestGpCompleteLightQuest")
    /* stub */
}

bool sQuestManagerExt::isFinishedGpCompleteLightQuest() const {
    MtObject* * p0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 2) {
                break;
            }
        }
        p0_0 += 1;
    }
    return !static_cast<cLightQuestManager*>(static_cast<sQuestManagerExt::cManagerInfo*>(v1_1)->getQuestManager())->isFinishedGpComplete();
}

u32 sQuestManagerExt::getGpCompleteLightQuestErrorCode() const {
    MtObject* * p0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 2) {
                break;
            }
        }
        p0_0 += 1;
    }
    return static_cast<cLightQuestManager*>(static_cast<sQuestManagerExt::cManagerInfo*>(v1_1)->getQuestManager())->getGpCompleteErrorCode();
}

bool sQuestManagerExt::isGpCompleteLightQuest() const {
    MtObject* * p0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 2) {
                break;
            }
        }
        p0_0 += 1;
    }
    return static_cast<cLightQuestManager*>(static_cast<sQuestManagerExt::cManagerInfo*>(v1_1)->getQuestManager())->isGpComplete();
}

u32 sQuestManagerExt::getNotCompleteLightQuestNum() const {
    MtObject* * p0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 2) {
                break;
            }
        }
        p0_0 += 1;
    }
    return static_cast<cLightQuestManager*>(static_cast<sQuestManagerExt::cManagerInfo*>(v1_1)->getQuestManager())->getNotCompleteQuestNum();
}

u32 sQuestManagerExt::getGpCompleteLightQuestGp() const {
    MtObject* * p0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 2) {
                break;
            }
        }
        p0_0 += 1;
    }
    return static_cast<cLightQuestManager*>(static_cast<sQuestManagerExt::cManagerInfo*>(v1_1)->getQuestManager())->getCompleteGp();
}

__attribute__((weak)) sQuestManagerExt::QUEST_RET sQuestManagerExt::getQuestServerParam(const nQuest::SCHEDULE_ID& scheduleId) {
    DDON_STUB("sQuestManagerExt::getQuestServerParam")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isBlankMyOrder() const {
    DDON_STUB("sQuestManagerExt::isBlankMyOrder")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isBlankLeaderOrder() const {
    DDON_STUB("sQuestManagerExt::isBlankLeaderOrder")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getQuestOrderNowNum() const {
    DDON_STUB("sQuestManagerExt::getQuestOrderNowNum")
    return {};
}

u32 sQuestManagerExt::getQuestOrderMaxNum() const {
    return *(!sGame::getInstance()->isChargeEffect(nGpCourse::GP_COURSE_EFFECT_QUEST_ORDER_LIST_EXTEND) ? (&mOrderMaxNum) : (&mGPOrderMaxNum));
}

u32 sQuestManagerExt::getQuestRewardBoxMaxNum() const {
    return mRewardBoxMaxNum;
}

bool sQuestManagerExt::isEndDistributionQuestCancel() const {
    return mIsEndDistQuestCancel;
}

void sQuestManagerExt::offEndDistributionQuestCnacel() {
    mIsEndDistQuestCancel = false;
}

__attribute__((weak)) bool sQuestManagerExt::isClearedTutorialQuestGroup(u32 groupId) const {
    DDON_STUB("sQuestManagerExt::isClearedTutorialQuestGroup")
    return {};
}

void sQuestManagerExt::interruptBarricade() {
    mIsInterruptBarricade = true;
    mInterruptBarricadeTimer = sMain::getInstance()->getFps() * 5.0f;
}

__attribute__((weak)) bool sQuestManagerExt::isEnableInterruptBarricade() {
    DDON_STUB("sQuestManagerExt::isEnableInterruptBarricade")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isEnableOrderButton(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::isEnableOrderButton")
    return {};
}

void sQuestManagerExt::setEndContentsInfo(nQuest::QUEST_ID QuestId, bool isClear) {
    mEndContentsInfo.mQuestId.mQuestId = QuestId.mQuestId;
    mEndContentsInfo.mIsClear = isClear;
}

__attribute__((weak)) bool sQuestManagerExt::getTargetEnemyGroupId(nQuest::SCHEDULE_ID scheduleId, u32& val) const {
    DDON_STUB("sQuestManagerExt::getTargetEnemyGroupId")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::getTargetEnemyLevel(nQuest::SCHEDULE_ID scheduleId, u32& val) const {
    DDON_STUB("sQuestManagerExt::getTargetEnemyLevel")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::getTargetItemId(nQuest::SCHEDULE_ID scheduleId, u32& val) const {
    DDON_STUB("sQuestManagerExt::getTargetItemId")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::getTargetNum(nQuest::SCHEDULE_ID scheduleId, u32& val) const {
    DDON_STUB("sQuestManagerExt::getTargetNum")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::move() {
    DDON_STUB("sQuestManagerExt::move")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isOrderQuest(nQuest::SCHEDULE_ID ScheduleId) const {
    DDON_STUB("sQuestManagerExt::isOrderQuest")
    return {};
}

bool sQuestManagerExt::isOrderQuest(nQuest::QUEST_ID QuestId) const {
    cQuestTask* pTask = getQuestTask(QuestId);
    if (pTask != nullptr) {
        return pTask->isOrder();
    } else {
        return false;
    }
}

bool sQuestManagerExt::isOrderMyMainQuest() const {
    MtObject* * p0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 0) {
                break;
            }
        }
        p0_0 += 1;
    }
    const u32 questNum = static_cast<sQuestManagerExt::cManagerInfo*>(v1_1)->getQuestManager()->getQuestNum();
    bool b8_0;
    if (questNum == 0) {
        b8_0 = false;
    } else {
        unsigned int i2_3 = 0;
        MtObject* * p3_0;
        MtObject* v4_1;
        for (;;) {
            p3_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
            for (;;) {
                v4_1 = *p3_0;
                if (v4_1 != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v4_1) + 8)) == 0) {
                        break;
                    }
                }
                p3_0 += 1;
            }
            cQuestTask* t0 = static_cast<sQuestManagerExt::cManagerInfo*>(v4_1)->getQuestManager()->getQuestTask(i2_3);
            if (t0 != nullptr) {
                if (t0->isMyOrder()) {
                    b8_0 = true;
                    return b8_0;
                }
            }
            if ((i2_3 + 1u) < questNum) {
                i2_3 += 1u;
            } else {
                break;
            }
        }
        b8_0 = false;
    }
    return b8_0;
}

__attribute__((weak)) bool sQuestManagerExt::isMyOrderQuest(nQuest::SCHEDULE_ID ScheduleId) const {
    DDON_STUB("sQuestManagerExt::isMyOrderQuest")
    return {};
}

bool sQuestManagerExt::isOrderPawnQuest() const {
    MtObject* * p0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 10) {
                break;
            }
        }
        p0_0 += 1;
    }
    cQuestTask* t0 = static_cast<sQuestManagerExt::cManagerInfo*>(v1_1)->getQuestManager()->getQuestTask(0u);
    if (t0 != nullptr) {
        bool t1 = t0->isOrder();
        return t1;
    } else {
        return false;
    }
}

__attribute__((weak)) bool sQuestManagerExt::isDiscoverdQuest(nQuest::SCHEDULE_ID ScheduleId) const {
    DDON_STUB("sQuestManagerExt::isDiscoverdQuest")
    return {};
}

bool sQuestManagerExt::isDiscoverdQuest(nQuest::QUEST_ID questId) const {
    cQuestTask* pTask = getQuestTask(questId);
    if (pTask != nullptr) {
        return pTask->isDiscovery();
    } else {
        return false;
    }
}

__attribute__((weak)) bool sQuestManagerExt::isEnableDeliveryLightQuest() const {
    DDON_STUB("sQuestManagerExt::isEnableDeliveryLightQuest")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getOnlyOneQuestTalkScheduleId(u32 NpcId) const {
    DDON_STUB("sQuestManagerExt::getOnlyOneQuestTalkScheduleId")
    return {};
}

u32 sQuestManagerExt::getOnlyOneQuestTalkScheduleId(u32 NpcId, nQuest::QUEST_ID QuestId, bool IsChkQuestId) const {
    if (IsChkQuestId) {
        cQuestTask* pTask = getQuestTask(QuestId);
        if (pTask != nullptr) {
            if (!pTask->isDelete()) {
                if (!pTask->progresses()) {
                    nQuest::cTalkData* pTalkData = pTask->getTalkData(NpcId);
                    if (pTalkData != nullptr) {
                        return pTask->getScheduleIdU32();
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return getOnlyOneQuestTalkScheduleId(NpcId);
    }
}

__attribute__((weak)) bool sQuestManagerExt::isHaveEnableQuestTalk(nQuest::QUEST_TYPE questType, u32 npcId, u32 questId, bool IsChkQuestId) const {
    DDON_STUB("sQuestManagerExt::isHaveEnableQuestTalk")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::hasQuestTalk(u32 npcId) const {
    DDON_STUB("sQuestManagerExt::hasQuestTalk")
    return {};
}

__attribute__((weak)) u32 sQuestManagerExt::getHaveQuestTalkNum(nQuest::QUEST_TYPE questType, u32 npcId) const {
    DDON_STUB("sQuestManagerExt::getHaveQuestTalkNum")
    return {};
}

__attribute__((weak)) nQuest::SCHEDULE_ID sQuestManagerExt::getHaveQuestTalkScheduleId(u32 npcId) const {
    DDON_STUB("sQuestManagerExt::getHaveQuestTalkScheduleId")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::SCHEDULE_ID sQuestManagerExt::getHaveQuestTalkScheduleId(nQuest::QUEST_TYPE questType, u32 npcId) const {
    DDON_STUB("sQuestManagerExt::getHaveQuestTalkScheduleId")
    __builtin_unreachable();
}

__attribute__((weak)) nQuest::SCHEDULE_ID sQuestManagerExt::getHaveQuestTalkConnectMarkerScheduleId(u32 npcId, nQuest::QUEST_ID npcQuestId, bool isDispElseQuestTalk) const {
    DDON_STUB("sQuestManagerExt::getHaveQuestTalkConnectMarkerScheduleId")
    __builtin_unreachable();
}

__attribute__((weak)) void sQuestManagerExt::addQuestTalk(nQuest::QUEST_TYPE questType, u32 npcId, nQuest::QUEST_ID questId, MtObject* pClass, void(MtObject::*pCallback)(const cQuestTask*, const nQuest::cTalkData*)) {
    DDON_STUB("sQuestManagerExt::addQuestTalk")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::buysHint(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("sQuestManagerExt::buysHint")
    return {};
}

__attribute__((weak)) nQuest::QUEST_TYPE sQuestManagerExt::getQuestType(nQuest::QUEST_ID questId) const {
    DDON_STUB("sQuestManagerExt::getQuestType")
    return {};
}

__attribute__((weak)) nQuest::QUEST_TYPE sQuestManagerExt::getQuestType(nQuest::SCHEDULE_ID ScheduleId) const {
    DDON_STUB("sQuestManagerExt::getQuestType")
    return {};
}

void sQuestManagerExt::getWaypointGoto(u32 npcId, s32& waypoint0, s32& waypoint1, s32& waypoint2) const {
    if (mWaypointNpc != npcId) {
        waypoint0 = -1;
        waypoint1 = -1;
        waypoint2 = -1;
    }
    waypoint0 = mWaypointGotoPointNo0;
    waypoint1 = mWaypointGotoPointNo1;
    waypoint2 = mWaypointGotoPointNo2;
}

__attribute__((weak)) void sQuestManagerExt::setWaypointGoto(u32 npcId, s32 gotoPointNo0, s32 gotoPointNo1, s32 gotoPointNo2) {
    DDON_STUB("sQuestManagerExt::setWaypointGoto")
    /* stub */
}

bool sQuestManagerExt::isUpdateWaypoint() const {
    return mIsUpdateWaypoint;
}

__attribute__((weak)) bool sQuestManagerExt::getSetQuestList() {
    DDON_STUB("sQuestManagerExt::getSetQuestList")
    return {};
}

void sQuestManagerExt::forceGetSetQuestList() {
    u32 v0_0 = sQuestManagerExt::getInstance()->mManagerInfo.mLength;
    cQuestManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = sQuestManagerExt::getInstance()->mManagerInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 1) {
                    v2_4 = static_cast<sQuestManagerExt::cManagerInfo*>(v0_1[i0_2])->getQuestManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    static_cast<cSetQuestManager*>(v2_4)->cSetQuestManager::getQuestList(mNowSetQuestDistId);
    cQuestSvRequest* t0 = cQuestSvRequestManager::pushRequest(cQuestSvReqGetAreaBonusList::DTI);
    if (t0 != nullptr) {
        t0->setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvRequest::PCallbackFunc>(&::sQuestManagerExt::callbackGetAreaBonusList));
    }
}

const nQuest::cGUINewspaperSetQuestInfoList& sQuestManagerExt::getSetQuestInfoListRef() const {
    return mSetQuestInfoList;
}

const nQuest::GUINewspaperRecommededQuestInfoArray& sQuestManagerExt::getRecommededQuestInfoListRef() const {
    return mRecommendedQuestInfoList;
}

u32 sQuestManagerExt::getQuestSeq(nQuest::QUEST_ID questId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_1 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 4) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    u32 t0 = static_cast<cQuestResourceManager*>(v2_4)->getQuestSequence(questId);
    return t0;
}

__attribute__((weak)) cQuestTask* sQuestManagerExt::addHelperTask(const CQuestOrderList* pOrder) {
    DDON_STUB("sQuestManagerExt::addHelperTask")
    return nullptr;
}

__attribute__((weak)) cQuestTask* sQuestManagerExt::addHelperTask(const CMainQuestList* pOrder) {
    DDON_STUB("sQuestManagerExt::addHelperTask")
    return nullptr;
}

__attribute__((weak)) MT_CTSTR sQuestManagerExt::getOrderConditionText(u32 ConditionType) {
    DDON_STUB("sQuestManagerExt::getOrderConditionText")
    return {};
}

void sQuestManagerExt::requestRepairMyQuestInfo() {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLeaderCharacterId != static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLobbyCharacterId) {
        return;
    }
    cQuestSvRequest* pReq = cQuestSvRequestManager::pushRequest(cQuestSvReqGetPartyQuestProgressInfo::DTI);
    if (pReq == nullptr) {
        return;
    }
    pReq->setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvRequest::PCallbackFunc>(&::sQuestManagerExt::callbackRepairMyQuestInfo));
}

__attribute__((weak)) void sQuestManagerExt::setTutorialInvincible(uCharacter* pCharacter) {
    DDON_STUB("sQuestManagerExt::setTutorialInvincible")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::endDistributionQuestCancel() {
    DDON_STUB("sQuestManagerExt::endDistributionQuestCancel")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::resetMainQstSyncInfo() {
    DDON_STUB("sQuestManagerExt::resetMainQstSyncInfo")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isMainQstSyncFlag(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::isMainQstSyncFlag")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::reqQuestOrder(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::reqQuestOrder")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::cancelReqQuestOrder(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::cancelReqQuestOrder")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isQuestOrderProgress(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::isQuestOrderProgress")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isAutoPartyProgress(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::isAutoPartyProgress")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::callbackInstanceAreaReset() {
    DDON_STUB("sQuestManagerExt::callbackInstanceAreaReset")
    /* stub */
}

void sQuestManagerExt::reqSendLeaderQuestOrderConditionInfo() {
    mReqSendLeaderQuestOrderConditionInfo = true;
}

__attribute__((weak)) void sQuestManagerExt::sendLeaderQuestOrderConditionInfo() {
    DDON_STUB("sQuestManagerExt::sendLeaderQuestOrderConditionInfo")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::resetLeaderQuestOrderConditionInfo() {
    DDON_STUB("sQuestManagerExt::resetLeaderQuestOrderConditionInfo")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::sendLeaderWaitOrderQuestList() {
    DDON_STUB("sQuestManagerExt::sendLeaderWaitOrderQuestList")
    /* stub */
}

void sQuestManagerExt::callbackCycleContentsPlayStart() {
    mIsContentsTimerTimeup = false;
}

bool sQuestManagerExt::hasCycleContentsPlayEndNotice() const {
    return mHasCycleContentsPlayEndNotice;
}

void sQuestManagerExt::reqCycleContentsPlayEnd() {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLeaderCharacterId != static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLobbyCharacterId) {
        return;
    }
    cQuestSvRequest* pReq = cQuestSvRequestManager::pushRequest(cQuestSvReqCycleContentsPlayEnd::DTI);
    if (pReq == nullptr) {
        return;
    }
    pReq->setFromClass(static_cast<MtObject*>(this));
}

void sQuestManagerExt::resetHasCycleContentsPlayEndNotice() {
    mHasCycleContentsPlayEndNotice = false;
}

bool sQuestManagerExt::isEnableOrderMainQuest() {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowPartyReq()) {
        return false;
    } else {
        return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getPartyInviteJoinMemberPacket()->m_MemberMinimum.mLength == 0;
    }
}

bool sQuestManagerExt::isEnableProgressSoloQuest() {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowPartyReq()) {
        return false;
    } else {
        return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getPartyInviteJoinMemberPacket()->m_MemberMinimum.mLength == 0;
    }
}

__attribute__((weak)) void sQuestManagerExt::resetLoginInfo() {
    DDON_STUB("sQuestManagerExt::resetLoginInfo")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isForceInBattleState() {
    DDON_STUB("sQuestManagerExt::isForceInBattleState")
    return {};
}

void sQuestManagerExt::resetEndContentsInfo() {
    mEndContentsInfo.mQuestId.mQuestId = nQuest::INVALID_QUEST_ID.mQuestId;
    mEndContentsInfo.mIsClear = false;
    mEndContentsInfo.mPlayTimeMillSec = 0;
}

__attribute__((weak)) void sQuestManagerExt::callbackQuestProgress(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackQuestProgress")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetSetQuestList(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackGetSetQuestList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackQuestTimer(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackQuestTimer")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackQuestComplete(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackQuestComplete")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackQuestProgressWorkSave(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackQuestProgressWorkSave")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackCycleContentsPlayEnd(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackCycleContentsPlayEnd")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackPlayStartTimer(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackPlayStartTimer")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackPlayAddTimer(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackPlayAddTimer")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackPlayTimeup(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackPlayTimeup")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackEndDistributionQuestCancel(u32 errorCode) {
    DDON_STUB("sQuestManagerExt::callbackEndDistributionQuestCancel")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackLoadResourceListEndDistributionQuests(u32 arg, const nQuest::QuestIdArray& ids) {
    DDON_STUB("sQuestManagerExt::callbackLoadResourceListEndDistributionQuests")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackLeaderQuestProgress(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackLeaderQuestProgress")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetMainQuestList(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackGetMainQuestList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackStopTimer(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackStopTimer")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackRestartTimer(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackRestartTimer")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackEndContentsPlayEnd(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackEndContentsPlayEnd")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackRepairMyQuestInfo(u32 errorCode) {
    DDON_STUB("sQuestManagerExt::callbackRepairMyQuestInfo")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackQuestCancel(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackQuestCancel")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackQuestOrder(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackQuestOrder")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackQuestEnable(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackQuestEnable")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackCycleContentsEnable(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackCycleContentsEnable")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackJoinLobbyQuestInfo(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackJoinLobbyQuestInfo")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackRemainingTime30Sec() {
    DDON_STUB("sQuestManagerExt::callbackRemainingTime30Sec")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackRemainingTime60Sec() {
    DDON_STUB("sQuestManagerExt::callbackRemainingTime60Sec")
    /* stub */
}

void sQuestManagerExt::callbackEntryParty(cQuestEventArg* pArg) {
    u32 t0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getCharacterId();
    if (t0 == static_cast<cQuestEventArgEntryParty*>(pArg)->getCharacterId()) {
        return;
    }
    if (!static_cast<cQuestEventArgEntryParty*>(pArg)->isPawn()) {
        sendLeaderQuestOrderConditionInfo();
        sendLeaderWaitOrderQuestList();
    }
}

__attribute__((weak)) void sQuestManagerExt::callbackLeaveParty(cQuestEventArg* pArg) {
    DDON_STUB("sQuestManagerExt::callbackLeaveParty")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackSendLeaderQuestOrderConditionInfo(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackSendLeaderQuestOrderConditionInfo")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackSendLeaderWaitOrderQuestList(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackSendLeaderWaitOrderQuestList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetAreaBonusList(u32 errorCode) {
    DDON_STUB("sQuestManagerExt::callbackGetAreaBonusList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackSetQuestUnreleasedArea(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackSetQuestUnreleasedArea")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackReleaseSetQuestArea(void* pPacket) {
    DDON_STUB("sQuestManagerExt::callbackReleaseSetQuestArea")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::setNewspaperQuestInfo(nQuest::cGUINewspaperSetQuestInfo* pInfo, CSetQuestInfoList* pSvInfo) {
    DDON_STUB("sQuestManagerExt::setNewspaperQuestInfo")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isOrderUIDecide(nQuest::SCHEDULE_ID ScheduleId) const {
    DDON_STUB("sQuestManagerExt::isOrderUIDecide")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::setOrderUI(nQuest::SCHEDULE_ID scheduleId, u32 npcId) {
    DDON_STUB("sQuestManagerExt::setOrderUI")
    return {};
}

sQuestManagerExt::QUEST_UI_RESULT sQuestManagerExt::moveOrderUI() {
    u32 result = static_cast<sGUIExt*>(sGUI::getInstance())->getQuestInfoResult();
    if (result != 0) {
        if (result == 2) {
            static_cast<sGUIExt*>(sGUI::getInstance())->deleteQuestInfo();
            return RESULT_NO;
        } else {
            if (result == 1) {
                mIsOrderUIDecide = true;
                static_cast<sGUIExt*>(sGUI::getInstance())->deleteQuestInfo();
                return RESULT_YES;
            } else {
                static_cast<sGUIExt*>(sGUI::getInstance())->deleteQuestInfo();
                return RESULT_NONE;
            }
        }
    } else {
        return RESULT_NONE;
    }
}

__attribute__((weak)) bool sQuestManagerExt::setDeliverUI(nQuest::SCHEDULE_ID scheduleId, uControl* pCtrl) {
    DDON_STUB("sQuestManagerExt::setDeliverUI")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::callbackGetSetQuestInfoList() {
    DDON_STUB("sQuestManagerExt::callbackGetSetQuestInfoList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetRecommendedQuestInfoList() {
    DDON_STUB("sQuestManagerExt::callbackGetRecommendedQuestInfoList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetSetQuestOpenDateList() {
    DDON_STUB("sQuestManagerExt::callbackGetSetQuestOpenDateList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetCycleContentsNewsList() {
    DDON_STUB("sQuestManagerExt::callbackGetCycleContentsNewsList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetRankingDataRank() {
    DDON_STUB("sQuestManagerExt::callbackGetRankingDataRank")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetCycleContentsRankingRewardList() {
    DDON_STUB("sQuestManagerExt::callbackGetCycleContentsRankingRewardList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetCycleContentsBorderRewardList() {
    DDON_STUB("sQuestManagerExt::callbackGetCycleContentsBorderRewardList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetQuestPartyBonusList() {
    DDON_STUB("sQuestManagerExt::callbackGetQuestPartyBonusList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackGetRankingBoardListByScheduleId() {
    DDON_STUB("sQuestManagerExt::callbackGetRankingBoardListByScheduleId")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::canRequestOrderWaitOrderQuest(const nQuest::SCHEDULE_ID& scheduleId) {
    DDON_STUB("sQuestManagerExt::canRequestOrderWaitOrderQuest")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::requestOrderWaitOrderQuest(const nQuest::SCHEDULE_ID& scheduleId) {
    DDON_STUB("sQuestManagerExt::requestOrderWaitOrderQuest")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isWaitOrderQuest(const nQuest::SCHEDULE_ID& scheduleId) {
    DDON_STUB("sQuestManagerExt::isWaitOrderQuest")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isFinishedOrderWaitOrder() const {
    DDON_STUB("sQuestManagerExt::isFinishedOrderWaitOrder")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::addWaitOrder(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("sQuestManagerExt::addWaitOrder")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::removeWaitOrder(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("sQuestManagerExt::removeWaitOrder")
    /* stub */
}

u32 sQuestManagerExt::getAreaReleaseByRankUp(u32 index) const {
    u32 v0_3 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_3;
    if (v0_3 == 0) {
        v3_3 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 9) {
                    v3_3 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    return static_cast<cAreaReleaseManager*>(v3_3)->getAreaReleaseByRankUp(index);
                }
            }
            if ((i0_2 + 1u) < v0_3) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_3 = nullptr;
    }
    return static_cast<cAreaReleaseManager*>(v3_3)->getAreaReleaseByRankUp(index);
}

__attribute__((weak)) void sQuestManagerExt::setAreaReleaseByRankUp(u32 data) {
    DDON_STUB("sQuestManagerExt::setAreaReleaseByRankUp")
    /* stub */
}

u32 sQuestManagerExt::getAreaReleaseNumByRankUp() const {
    MtObject* * p0_0 = mFunctionInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 9) {
                break;
            }
        }
        p0_0 += 1;
    }
    return static_cast<cAreaReleaseManager*>(static_cast<sQuestManagerExt::cFunctionInfo*>(v1_1)->getFunctionManager())->getAreaReleaseNumByRankUp();
}

__attribute__((weak)) void sQuestManagerExt::setAreaRelease(u16 id) {
    DDON_STUB("sQuestManagerExt::setAreaRelease")
    /* stub */
}

void sQuestManagerExt::setAreaId(u32 areaId) {
    MtObject* * p0_0 = mFunctionInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 9) {
                break;
            }
        }
        p0_0 += 1;
    }
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(static_cast<sQuestManagerExt::cFunctionInfo*>(v1_1)->getFunctionManager()) + 8) = areaId;
}

u32 sQuestManagerExt::getAreaId() const {
    MtObject* * p0_0 = mFunctionInfo.mpArray;
    MtObject* v1_1;
    for (;;) {
        v1_1 = *p0_0;
        if (v1_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v1_1) + 8)) == 9) {
                break;
            }
        }
        p0_0 += 1;
    }
    return static_cast<cAreaReleaseManager*>(static_cast<sQuestManagerExt::cFunctionInfo*>(v1_1)->getFunctionManager())->getAreaId();
}

__attribute__((weak)) bool sQuestManagerExt::isAreaRelease(u16 id) {
    DDON_STUB("sQuestManagerExt::isAreaRelease")
    return {};
}

u32 sQuestManagerExt::getAreaMasterRank(u32 areaNo) const {
    if ((areaNo - 1u) <= 16u) {
        return mAreaMasterRank[areaNo - 1u];
    } else {
        return 1;
    }
}

void sQuestManagerExt::setAreaMasterRank(u32 areaNo, u32 rank) {
    if ((areaNo - 1u) <= 16u) {
        mAreaMasterRank[areaNo - 1u] = static_cast<unsigned char>(rank);
    }
}

__attribute__((weak)) bool sQuestManagerExt::reqGetAreaReleaseInfo() {
    DDON_STUB("sQuestManagerExt::reqGetAreaReleaseInfo")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::getAreaReleaseInfo() {
    DDON_STUB("sQuestManagerExt::getAreaReleaseInfo")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::resetAreaRelease() {
    DDON_STUB("sQuestManagerExt::resetAreaRelease")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::resetAreaReleaseByRankUp() {
    DDON_STUB("sQuestManagerExt::resetAreaReleaseByRankUp")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::resetReleaseInfoRequest() {
    DDON_STUB("sQuestManagerExt::resetReleaseInfoRequest")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::disableReleaseInfoRequest() {
    DDON_STUB("sQuestManagerExt::disableReleaseInfoRequest")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isEnableReleaseInfoSendMsg() {
    DDON_STUB("sQuestManagerExt::isEnableReleaseInfoSendMsg")
    return {};
}

void sQuestManagerExt::csLock() {
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sQuestManagerExt::csUnlock() {
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

bool sQuestManagerExt::isLeaderReturn() const {
    bool t0 = cContextInterface::isSessionLost(sContextManager::getInstance()->getContextPartyLeader());
    return mIsLeaderLost && (mIsLeaderLost != t0);
}

__attribute__((weak)) void sQuestManagerExt::addLeaderOrderedQuest(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, bool hasOrdered) {
    DDON_STUB("sQuestManagerExt::addLeaderOrderedQuest")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isPartyBonusOrb() const {
    DDON_STUB("sQuestManagerExt::isPartyBonusOrb")
    return {};
}

__attribute__((weak)) const nQuest::cPartyBonusInfo* sQuestManagerExt::getQuestPartyBonusInfo(nQuest::SCHEDULE_ID scheduleId) const {
    DDON_STUB("sQuestManagerExt::getQuestPartyBonusInfo")
    return nullptr;
}

__attribute__((weak)) void sQuestManagerExt::recievePartyBonus(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("sQuestManagerExt::recievePartyBonus")
    /* stub */
}

bool sQuestManagerExt::isFavoriteWarpPoint(u32 warpPointId) const {
    const u32 num = mFavoriteWarpPointList.mLength;
    if (num != 0) {
        MtObject* * v0_4 = mFavoriteWarpPointList.mpArray;
        for (u32 i = 0;;) {
            if (v0_4[i] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4[i]) + 12)) == warpPointId) {
                    return true;
                }
            }
            if ((i + 1u) < num) {
                i = i + 1u;
            } else {
                break;
            }
        }
    }
    return false;
}

__attribute__((weak)) void sQuestManagerExt::callbackGetFavoriteWarpPointList(const MtTypedArray<CDataFavoriteWarpPoint>& list) {
    DDON_STUB("sQuestManagerExt::callbackGetFavoriteWarpPointList")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::callbackRegisterFavoriteWarp(u32 slotNo, u32 warpPointId) {
    DDON_STUB("sQuestManagerExt::callbackRegisterFavoriteWarp")
    /* stub */
}

bool sQuestManagerExt::isJoinLeader() const {
    u32 v0_6 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLeaderCharacterId;
    bool b3_0;
    if (v0_6 == static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLobbyCharacterId) {
        b3_0 = true;
    } else {
        sContextManager* v0_3 = sContextManager::getInstance();
        unsigned int v2_3;
        if (v0_6 == 0) {
            v2_3 = 0xFFFFFFFF;
        } else {
            u32 v0_5 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mPartyMemberInfoVec.size();
            if (v0_5 == 0) {
                v2_3 = 0xFFFFFFFF;
            } else {
                MtObject* * v0_4 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mPartyMemberInfoVec.getBuffer();
                for (unsigned int i0_2 = 0;;) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4[static_cast<int>(i0_2)]) + 24)) == v0_6) {
                        if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_4[static_cast<int>(i0_2)]) + 120)) <= 3) {
                            if (((12ul >> static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_4[static_cast<int>(i0_2)]) + 120)) & 15)) & 1ul) == 0) {
                                v2_3 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4[static_cast<int>(i0_2)]) + 116);
                                break;
                            }
                        } else {
                            v2_3 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4[static_cast<int>(i0_2)]) + 116);
                            break;
                        }
                    }
                    if ((i0_2 + 1u) < v0_5) {
                        i0_2 += 1u;
                    } else {
                        v2_3 = 0xFFFFFFFF;
                        break;
                    }
                }
            }
        }
        cContextInstHm* t0 = v0_3->getContextPartyPlayerFromMemberIndex(static_cast<s32>(v2_3));
        if (t0 != nullptr) {
            return (t0->mIsValid & 11) == 11;
        } else {
            b3_0 = false;
        }
    }
    return b3_0;
}

__attribute__((weak)) bool sQuestManagerExt::addSystemLog(MT_CTSTR message, nQuest::QUEST_ID quest_id, MT_CTSTR analizeMsg0, MT_CTSTR analizeMsg1, bool withAnnounce, u32 filter, bool isWarning) {
    DDON_STUB("sQuestManagerExt::addSystemLog")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::dispHelperSystemLog() {
    DDON_STUB("sQuestManagerExt::dispHelperSystemLog")
    /* stub */
}

bool sQuestManagerExt::isAreaBonus(u32 areaId) const {
    for (u32 i = 0; i <= 16u; i = i + 1u) {
        if (mAreaBonusList[i].mAreaId == areaId) {
            if (mAreaBonusList[i].mMaxRate != 100) {
                return true;
            }
        }
    }
    return false;
}

u32 sQuestManagerExt::getAreaBonusRate(u32 areaId) const {
    u32 i = 0;
    do {
        if (mAreaBonusList[i].mAreaId == areaId) {
            return mAreaBonusList[i].mMaxRate;
        }
        i += 1u;
    } while (i <= 16u);
    return 100;
}

__attribute__((weak)) void sQuestManagerExt::setBarricade(nQuest::SCHEDULE_ID scheduleId, s32 stageNo, s32 startPos, s32 sceHitNo, s32 inSceHitNo) {
    DDON_STUB("sQuestManagerExt::setBarricade")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::resetBarricade(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("sQuestManagerExt::resetBarricade")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::updateBarricade() {
    DDON_STUB("sQuestManagerExt::updateBarricade")
    /* stub */
}

__attribute__((weak)) bool sQuestManagerExt::isEnableStageJump() {
    DDON_STUB("sQuestManagerExt::isEnableStageJump")
    return {};
}

__attribute__((weak)) cJobMasterCtrl* sQuestManagerExt::getJobMasterCtrlData(u32 JobId) const {
    DDON_STUB("sQuestManagerExt::getJobMasterCtrlData")
    return nullptr;
}

__attribute__((weak)) bool sQuestManagerExt::isEnableContents(u32 chkContents) const {
    DDON_STUB("sQuestManagerExt::isEnableContents")
    return {};
}

__attribute__((weak)) bool sQuestManagerExt::isJoinPartyPawn_Create() {
    DDON_STUB("sQuestManagerExt::isJoinPartyPawn_Create")
    return {};
}

__attribute__((weak)) void sQuestManagerExt::addFuncChkData(u32 FunctionId, nQuest::SCHEDULE_ID ScheduleId, s32 Param) {
    DDON_STUB("sQuestManagerExt::addFuncChkData")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::deleteFuncChkData(nQuest::SCHEDULE_ID ScheduleId) {
    DDON_STUB("sQuestManagerExt::deleteFuncChkData")
    /* stub */
}

__attribute__((weak)) u32 sQuestManagerExt::getFuncChkScheduleId(u32 FunctionId) {
    DDON_STUB("sQuestManagerExt::getFuncChkScheduleId")
    return {};
}

bool sQuestManagerExt::isWQUnreleasedArea(u32 areaId) const {
    if (mWQUnreleasedAreaList.mLength != 0) {
        u32 i = 0;
        do {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mWQUnreleasedAreaList.mpArray[i]) + 8)) == areaId) {
                return true;
            }
            i += 1u;
        } while (i < mWQUnreleasedAreaList.mLength);
    }
    return false;
}

bool sQuestManagerExt::isWaitDivide() const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_4;
    if (v0_1 == 0) {
        v3_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 12) {
                    v3_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    return cQuestPhaseState::isDivideProcess(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_4 = nullptr;
    }
    return cQuestPhaseState::isDivideProcess(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
}

bool sQuestManagerExt::isDivideSetup() const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_4;
    if (v0_1 == 0) {
        v3_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 12) {
                    v3_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    return cQuestPhaseState::isDivideSetup(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_4 = nullptr;
    }
    return cQuestPhaseState::isDivideSetup(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
}

bool sQuestManagerExt::isFinishDivide() const {
    return mIsFinishDivide;
}

bool sQuestManagerExt::isSucceededDevide() const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_4;
    if (v0_1 == 0) {
        v3_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 12) {
                    v3_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    return cQuestPhaseState::isDivideSuccess(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_4 = nullptr;
    }
    return cQuestPhaseState::isDivideSuccess(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
}

bool sQuestManagerExt::isWarpCharacter(u32 characterId) const {
    u32 v0_0 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 12) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_1[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    if (cQuestPhaseState::isWarpPlayer(static_cast<cQuestPhaseManager*>(v2_4)->getQuestPhaseState())) {
        u32 v3_0 = mFunctionInfo.mLength;
        cQuestFunctionManagerBase* v5_4;
        if (v3_0 == 0) {
            v5_4 = nullptr;
        } else {
            MtObject* * v3_1 = mFunctionInfo.mpArray;
            for (unsigned int i3_2 = 0;;) {
                if (v3_1[i3_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 12) {
                        v5_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v3_1[i3_2])->getFunctionManager();
                        break;
                    }
                }
                if ((i3_2 + 1u) < v3_0) {
                    i3_2 = i3_2 + 1u;
                } else {
                    v5_4 = nullptr;
                    break;
                }
            }
        }
        if (cQuestPhaseState::isDividePlayer(static_cast<cQuestPhaseManager*>(v5_4)->getQuestPhaseState(), characterId)) {
            return true;
        }
    }
    return isReturnCharacter(characterId);
}

__attribute__((weak)) bool sQuestManagerExt::isReturnCharacter(u32 characterId) const {
    u32 v0_0 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 12) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_1[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    if (cQuestPhaseState::isReturnPlayer(static_cast<cQuestPhaseManager*>(v2_4)->getQuestPhaseState())) {
        u32 v3_0 = mFunctionInfo.mLength;
        cQuestFunctionManagerBase* v5_4;
        if (v3_0 == 0) {
            v5_4 = nullptr;
        } else {
            MtObject* * v3_1 = mFunctionInfo.mpArray;
            for (unsigned int i3_2 = 0;;) {
                if (v3_1[i3_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 12) {
                        v5_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v3_1[i3_2])->getFunctionManager();
                        break;
                    }
                }
                if ((i3_2 + 1u) < v3_0) {
                    i3_2 = i3_2 + 1u;
                } else {
                    v5_4 = nullptr;
                    break;
                }
            }
        }
        if (cQuestPhaseState::isReturnPlayer(static_cast<cQuestPhaseManager*>(v5_4)->getQuestPhaseState(), characterId)) {
            return true;
        }
    }
    return false;
}

void sQuestManagerExt::getWarpPlayerStageNoStartPos(u32& stageNo, u32& startPos) const {
    stageNo = 0;
    startPos = 0;
    u32 v0_0 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v2_4;
    if (v0_0 == 0) {
        v2_4 = nullptr;
    } else {
        MtObject* * v0_1 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[i0_2]) + 8)) == 12) {
                    v2_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_1[i0_2])->getFunctionManager();
                    break;
                }
            }
            if ((i0_2 + 1u) < v0_0) {
                i0_2 = i0_2 + 1u;
            } else {
                v2_4 = nullptr;
                break;
            }
        }
    }
    if (cQuestPhaseState::isWarpPlayer(static_cast<cQuestPhaseManager*>(v2_4)->getQuestPhaseState())) {
        u32 v3_0 = mFunctionInfo.mLength;
        cQuestFunctionManagerBase* v5_4;
        if (v3_0 == 0) {
            v5_4 = nullptr;
        } else {
            MtObject* * v3_1 = mFunctionInfo.mpArray;
            for (unsigned int i3_2 = 0;;) {
                if (v3_1[i3_2] != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v3_1[i3_2]) + 8)) == 12) {
                        v5_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v3_1[i3_2])->getFunctionManager();
                        break;
                    }
                }
                if ((i3_2 + 1u) < v3_0) {
                    i3_2 = i3_2 + 1u;
                } else {
                    v5_4 = nullptr;
                    break;
                }
            }
        }
        cQuestPhaseState::getWarpPlayerStageNoStartPos(static_cast<cQuestPhaseManager*>(v5_4)->getQuestPhaseState(), stageNo, startPos);
    }
    u32 v7_0 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v9_4;
    if (v7_0 == 0) {
        v9_4 = nullptr;
    } else {
        MtObject* * v7_1 = mFunctionInfo.mpArray;
        for (unsigned int i7_2 = 0;;) {
            if (v7_1[i7_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v7_1[i7_2]) + 8)) == 12) {
                    v9_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v7_1[i7_2])->getFunctionManager();
                    break;
                }
            }
            if ((i7_2 + 1u) < v7_0) {
                i7_2 = i7_2 + 1u;
            } else {
                v9_4 = nullptr;
                break;
            }
        }
    }
    if (cQuestPhaseState::isReturnPlayer(static_cast<cQuestPhaseManager*>(v9_4)->getQuestPhaseState())) {
        stageNo = static_cast<u32>(mBarricadeStageNo);
        startPos = static_cast<u32>(mBarricadeStartPos);
    }
}

bool sQuestManagerExt::hasRequestedWarpPlayer(u32 characterId) const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_4;
    if (v0_1 == 0) {
        v3_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 12) {
                    v3_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    return cQuestPhaseState::hasRequestedWarpPlayer(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState(), characterId);
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_4 = nullptr;
    }
    return cQuestPhaseState::hasRequestedWarpPlayer(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState(), characterId);
}

void sQuestManagerExt::requestWarpPlayer(u32 characterId) {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_4;
    if (v0_1 == 0) {
        v3_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 12) {
                    v3_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    cQuestPhaseState::requestWarpPlayer(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState(), characterId);
                    return;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_4 = nullptr;
    }
    cQuestPhaseState::requestWarpPlayer(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState(), characterId);
}

bool sQuestManagerExt::isExistDividePlayer() const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_4;
    if (v0_1 == 0) {
        v3_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 12) {
                    v3_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    return cQuestPhaseState::isExistDividePlayer(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_4 = nullptr;
    }
    return cQuestPhaseState::isExistDividePlayer(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
}

bool sQuestManagerExt::isFinishedEnemyDivideAction() const {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_4;
    if (v0_1 == 0) {
        v3_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 12) {
                    v3_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    return cQuestPhaseState::isFinishedEnemyDivideAction(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_4 = nullptr;
    }
    return cQuestPhaseState::isFinishedEnemyDivideAction(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
}

void sQuestManagerExt::finishEnemyDivideAction() {
    u32 v0_1 = mFunctionInfo.mLength;
    cQuestFunctionManagerBase* v3_4;
    if (v0_1 == 0) {
        v3_4 = nullptr;
    } else {
        MtObject* * v0_0 = mFunctionInfo.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if (v0_0[i0_2] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_0[i0_2]) + 8)) == 12) {
                    v3_4 = static_cast<sQuestManagerExt::cFunctionInfo*>(v0_0[i0_2])->getFunctionManager();
                    cQuestPhaseState::finishEnemyDivideAction(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
                    return;
                }
            }
            if ((i0_2 + 1u) < v0_1) {
                i0_2 = i0_2 + 1u;
            } else {
                break;
            }
        }
        v3_4 = nullptr;
    }
    cQuestPhaseState::finishEnemyDivideAction(static_cast<cQuestPhaseManager*>(v3_4)->getQuestPhaseState());
}

sQuestManagerExt::sQuestManagerExt() {
    DDON_STUB("sQuestManagerExt::sQuestManagerExt")
    /* stub */
}

__attribute__((noinline)) sQuestManagerExt::~sQuestManagerExt() {
    DDON_STUB("sQuestManagerExt::~sQuestManagerExt")
    /* stub */
}

inline sQuestManagerExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::MyDTI sQuestManagerExt::DTI("sQuestManagerExt", &::cSystem::DTI, 1952ul, 0u, 0u);

sQuestManagerExt* sQuestManagerExt::mpInstance;

__attribute__((weak)) MtObject* sQuestManagerExt::MyDTI::newInstance() const {
    DDON_STUB("sQuestManagerExt::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sQuestManagerExt::cKilledEnemy::getDTI() const {
    return sQuestManagerExt::cKilledEnemy::DTI;
}

sQuestManagerExt::cKilledEnemy::~cKilledEnemy() {
}

inline sQuestManagerExt::cKilledEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cKilledEnemy::MyDTI sQuestManagerExt::cKilledEnemy::DTI("sQuestManagerExt::cKilledEnemy", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* sQuestManagerExt::cKilledEnemy::MyDTI::newInstance() const {
    return new (16u) sQuestManagerExt::cKilledEnemy;
}

const MtDTI& sQuestManagerExt::cManagerInfo::getDTI() const {
    return sQuestManagerExt::cManagerInfo::DTI;
}

sQuestManagerExt::cManagerInfo::~cManagerInfo() {
    if (mpMgr == nullptr) {
        return;
    }
    delete mpMgr;
    mpMgr = nullptr;
}

__attribute__((weak)) void sQuestManagerExt::cManagerInfo::createProperty(MtPropertyList& s) {
}

inline sQuestManagerExt::cManagerInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cManagerInfo::MyDTI sQuestManagerExt::cManagerInfo::DTI("sQuestManagerExt::cManagerInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* sQuestManagerExt::cManagerInfo::MyDTI::newInstance() const {
    return new (16u) sQuestManagerExt::cManagerInfo;
}

const MtDTI& sQuestManagerExt::cTouchOmInfo::getDTI() const {
    return sQuestManagerExt::cTouchOmInfo::DTI;
}

void* sQuestManagerExt::cTouchOmInfo::operator new(size_t sz, u32 align) {
    return sQuestManagerExt::cTouchOmInfo::getAllocator()->memAlloc(sz, align, sQuestManagerExt::cTouchOmInfo::DTI.getID());
}

const nLayout::stLayoutID& sQuestManagerExt::cTouchOmInfo::getLayoutId() const {
    return mLayoutId;
}

u32 sQuestManagerExt::cTouchOmInfo::getSetNo() const {
    return mSetNo;
}

u32 sQuestManagerExt::cTouchOmInfo::getQuestSequence() const {
    return mQuestSeq;
}

u32 sQuestManagerExt::cTouchOmInfo::getUniqueId() const {
    if (mQuestSeq != 0) {
        return nLayout::createUniqueIDQuestSetSeq(mQuestSeq, static_cast<s32>(mLayoutId.mLayoutID & 1023u), mLayoutId.mLayoutID >> 10, mSetNo);
    } else {
        return nLayout::createUniqueID(nLayout::U_OM, mLayoutId.mLayoutID >> 10, mSetNo, static_cast<s32>(mLayoutId.mLayoutID & 1023u));
    }
}

sQuestManagerExt::cTouchOmInfo::~cTouchOmInfo() {
}

inline sQuestManagerExt::cTouchOmInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cTouchOmInfo::MyDTI sQuestManagerExt::cTouchOmInfo::DTI("sQuestManagerExt::cTouchOmInfo", &::MtObject::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* sQuestManagerExt::cTouchOmInfo::MyDTI::newInstance() const {
    DDON_STUB("sQuestManagerExt::cTouchOmInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sQuestManagerExt::cFunctionInfo::getDTI() const {
    return sQuestManagerExt::cFunctionInfo::DTI;
}

sQuestManagerExt::cFunctionInfo::~cFunctionInfo() {
    if (mpFuncMgr == nullptr) {
        return;
    }
    delete mpFuncMgr;
    mpFuncMgr = nullptr;
}

__attribute__((weak)) void sQuestManagerExt::cFunctionInfo::createProperty(MtPropertyList& s) {
}

inline sQuestManagerExt::cFunctionInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cFunctionInfo::MyDTI sQuestManagerExt::cFunctionInfo::DTI("sQuestManagerExt::cFunctionInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* sQuestManagerExt::cFunctionInfo::MyDTI::newInstance() const {
    return new (16u) sQuestManagerExt::cFunctionInfo;
}

const MtDTI& sQuestManagerExt::cSystemLogNode::getDTI() const {
    return sQuestManagerExt::cSystemLogNode::DTI;
}

__attribute__((weak)) void sQuestManagerExt::cSystemLogNode::update() {
    DDON_STUB("sQuestManagerExt::cSystemLogNode::update")
    /* stub */
}

sQuestManagerExt::cSystemLogNode::cSystemLogNode(MT_CTSTR message, nQuest::QUEST_ID questId, MT_CTSTR analizeMsg0, MT_CTSTR analizeMsg1, bool withAnnounce, u32 filter, bool isWarning) {
    DDON_STUB("sQuestManagerExt::cSystemLogNode::cSystemLogNode")
    /* stub */
}

__attribute__((noinline)) sQuestManagerExt::cSystemLogNode::~cSystemLogNode() {
}

inline sQuestManagerExt::cSystemLogNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cSystemLogNode::MyDTI sQuestManagerExt::cSystemLogNode::DTI("sQuestManagerExt::cSystemLogNode", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* sQuestManagerExt::cSystemLogNode::MyDTI::newInstance() const {
    return new (16u) sQuestManagerExt::cSystemLogNode;
}

const MtDTI& sQuestManagerExt::cClearedQuestInfo::getDTI() const {
    return sQuestManagerExt::cClearedQuestInfo::DTI;
}

__attribute__((weak)) void sQuestManagerExt::cClearedQuestInfo::callbackFinish() {
    DDON_STUB("sQuestManagerExt::cClearedQuestInfo::callbackFinish")
    /* stub */
}

sQuestManagerExt::cClearedQuestInfo::~cClearedQuestInfo() {
    DDON_STUB("sQuestManagerExt::cClearedQuestInfo::~cClearedQuestInfo")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::cClearedQuestInfo::createProperty(MtPropertyList& s) {
}

inline sQuestManagerExt::cClearedQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cClearedQuestInfo::MyDTI sQuestManagerExt::cClearedQuestInfo::DTI("sQuestManagerExt::cClearedQuestInfo", &::MtObject::DTI, 128ul, 0u, 0u);

MtObject* sQuestManagerExt::cClearedQuestInfo::MyDTI::newInstance() const {
    return new (16u) sQuestManagerExt::cClearedQuestInfo;
}

const MtDTI& sQuestManagerExt::cTimer::getDTI() const {
    return sQuestManagerExt::cTimer::DTI;
}

__attribute__((weak)) void sQuestManagerExt::cTimer::update() {
    DDON_STUB("sQuestManagerExt::cTimer::update")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::cTimer::addCallbackElapsedTime(u32 time, MtObject* pClass, void(MtObject::*pCallback)()) {
    DDON_STUB("sQuestManagerExt::cTimer::addCallbackElapsedTime")
    /* stub */
}

sQuestManagerExt::cTimer::~cTimer() {
    if (mElapsedTimeArray.mLength != 0) {
        u32 v0_0 = mElapsedTimeArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mElapsedTimeArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mElapsedTimeArray.mpArray[i0_3];
                v1_0 = mElapsedTimeArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mElapsedTimeArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mElapsedTimeArray.mpArray));
    }
    mElapsedTimeArray.mpArray = nullptr;
    mElapsedTimeArray.mBufsiz = 0;
    mElapsedTimeArray.mLength = 0;
}

__attribute__((weak)) void sQuestManagerExt::cTimer::createProperty(MtPropertyList& s) {
}

inline sQuestManagerExt::cTimer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cTimer::MyDTI sQuestManagerExt::cTimer::DTI("sQuestManagerExt::cTimer", &::MtObject::DTI, 104ul, 0u, 0u);

MtObject* sQuestManagerExt::cTimer::MyDTI::newInstance() const {
    return new (16u) sQuestManagerExt::cTimer;
}

const MtDTI& sQuestManagerExt::cCallQuestAnnounce::getDTI() const {
    return sQuestManagerExt::cCallQuestAnnounce::DTI;
}

__attribute__((weak)) void sQuestManagerExt::cCallQuestAnnounce::setParam(const cQuestTask* pTask, s32 announceType, s32 purposeNo, bool isDiscovered, s32 num) {
    DDON_STUB("sQuestManagerExt::cCallQuestAnnounce::setParam")
    /* stub */
}

__attribute__((weak)) void sQuestManagerExt::cCallQuestAnnounce::update() {
    DDON_STUB("sQuestManagerExt::cCallQuestAnnounce::update")
    /* stub */
}

sQuestManagerExt::cCallQuestAnnounce::~cCallQuestAnnounce() {
}

__attribute__((weak)) void sQuestManagerExt::cCallQuestAnnounce::createProperty(MtPropertyList& s) {
}

inline sQuestManagerExt::cCallQuestAnnounce::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cCallQuestAnnounce::MyDTI sQuestManagerExt::cCallQuestAnnounce::DTI("sQuestManagerExt::cCallQuestAnnounce", &::MtObject::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* sQuestManagerExt::cCallQuestAnnounce::MyDTI::newInstance() const {
    DDON_STUB("sQuestManagerExt::cCallQuestAnnounce::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sQuestManagerExt::cUnreleasedArea::getDTI() const {
    return sQuestManagerExt::cUnreleasedArea::DTI;
}

sQuestManagerExt::cUnreleasedArea::~cUnreleasedArea() {
}

__attribute__((weak)) void sQuestManagerExt::cUnreleasedArea::createProperty(MtPropertyList& s) {
}

inline sQuestManagerExt::cUnreleasedArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cUnreleasedArea::MyDTI sQuestManagerExt::cUnreleasedArea::DTI("sQuestManagerExt::cUnreleasedArea", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* sQuestManagerExt::cUnreleasedArea::MyDTI::newInstance() const {
    return new (16u) sQuestManagerExt::cUnreleasedArea;
}

const MtDTI& sQuestManagerExt::cSayInfo::getDTI() const {
    return sQuestManagerExt::cSayInfo::DTI;
}

sQuestManagerExt::cSayInfo::~cSayInfo() {
}

inline sQuestManagerExt::cSayInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sQuestManagerExt::cSayInfo::MyDTI sQuestManagerExt::cSayInfo::DTI("sQuestManagerExt::cSayInfo", &::MtObject::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* sQuestManagerExt::cSayInfo::MyDTI::newInstance() const {
    DDON_STUB("sQuestManagerExt::cSayInfo::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<nQuest::cCycleContentsBorderRewardInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cCycleContentsInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cCycleContentsRankingInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cCycleContentsRankingRewardInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cGUINewspaperRecommededQuestInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cGUINewspaperSetQuestOpenDateInfo>::~MtTypedArray();

template MtTypedArray<nQuest::cPartyBonusInfo>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cCallQuestAnnounce>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cClearedQuestInfo>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cFunctionInfo>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cKilledEnemy>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cManagerInfo>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cQstFunctionCheck>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cSayInfo>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cSystemLogNode>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cTimer::cCallbackElapsedTime>::~MtTypedArray();

template MtTypedArray<sQuestManagerExt::cUnreleasedArea>::~MtTypedArray();

