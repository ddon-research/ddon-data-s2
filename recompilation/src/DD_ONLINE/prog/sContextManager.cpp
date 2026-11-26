// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "sContextManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtSynchronize.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cCharacterData.h"
#include "cContext.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cEditParam.h"
#include "cEquipData.h"
#include "cNetGameServer.h"
#include "cPlayerLoadManager.h"
#include "../../XFramework/cSystem.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "../../generated/shared/nGroup.h"
#include "nHumanMsg.h"
#include "nJobParam.h"
#include "nLayout.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sControlManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sPlayerManager.h"
#include "sSetManager.h"
#include "uControl.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sContextManager::getDTI() const {
    return sContextManager::DTI;
}

inline MtAllocator* sContextManager::getAllocator() {
    return MtMemoryAllocator::getAllocator(sContextManager::DTI);
}

void* sContextManager::operator new(size_t sz, u32 align) {
    return sContextManager::getAllocator()->memAlloc(sz, align, sContextManager::DTI.getID());
}

inline void sContextManager::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(sContextManager::DTI)->memFree(p_addr);
}

sContextManager::sContextManager() {
    DDON_STUB("sContextManager::sContextManager")
    /* stub */
}

__attribute__((noinline)) sContextManager::~sContextManager() {
    DDON_STUB("sContextManager::~sContextManager")
    /* stub */
}

__attribute__((weak)) void sContextManager::createMenu(MtPropertyList& s) {
}

void sContextManager::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

MtUI* sContextManager::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sContextManager::move() {
    mDeleteTimer = mDeleteTimer - (sMain::mpInstance)->mDeltaTime;
    updateContextInstanceCore(mList[12]);
    updateContextInstanceCore(mList[9]);
    updateContextInstanceCore(mList[11]);
    updateContextInstanceCore(mList[7]);
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isResetInstanceArea()) {
        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mIsResetInstanceArea = false;
    }
    if (0.0f > mDeleteTimer) {
        mDeleteTimer = mDeleteInterval;
    }
}

__attribute__((weak)) void sContextManager::reset() {
}

void sContextManager::removeAllContext() {
    u32 i = 0;
    cContext* v1_5;
    for (;;) {
        if (i != 2) {
            if (mList[i].mpTop != nullptr) {
                v1_5 = mList[i].mpTop;
                for (;;) {
                    cContext* v2_3 = v1_5->mpNext;
                    if (v1_5 != nullptr) {
                        delete v1_5;
                    }
                    if (v2_3 != nullptr) {
                        v1_5 = v2_3;
                    } else {
                        break;
                    }
                }
            }
        }
        if ((i + 1u) != 13) {
            i = i + 1u;
        } else {
            break;
        }
    }
    removeAllContextPartyPlayer(false);
    removeAllContextPlayer();
}

__attribute__((weak)) cContextInstance* sContextManager::requestCreateContextInst(u32 id, u32 uniqueId, s32 encountArea) {
    DDON_STUB("sContextManager::requestCreateContextInst")
    return nullptr;
}

__attribute__((weak)) cContextInstance* sContextManager::getContextInstFromUniqueId(u32 UniqueId) {
    DDON_STUB("sContextManager::getContextInstFromUniqueId")
    return nullptr;
}

__attribute__((weak)) cContextInstance* sContextManager::createContextInstance(u32 id, u32 uniqueId, s32 stageNo, s32 encountArea) {
    DDON_STUB("sContextManager::createContextInstance")
    return nullptr;
}

__attribute__((weak)) void sContextManager::onSyncContextInstance(u32 uniqueId) {
    DDON_STUB("sContextManager::onSyncContextInstance")
    /* stub */
}

__attribute__((weak)) cContext* sContextManager::createContext(u32 id) {
    DDON_STUB("sContextManager::createContext")
    return nullptr;
}

__attribute__((weak)) bool sContextManager::registContext(cContext* pContext) {
    DDON_STUB("sContextManager::registContext")
    return {};
}

__attribute__((weak)) bool sContextManager::removeContext(cContext* pContext) {
    DDON_STUB("sContextManager::removeContext")
    return {};
}

cContextInstHm* sContextManager::searchContext(u32 unitUniqId) {
    cContext* v2_8;
    if (mList[2].getTop() == nullptr) {
        v2_8 = nullptr;
    } else {
        for (cContext* v0_3 = mList[2].getTop();;) {
            if (v0_3->mId != 2) {
                v2_8 = nullptr;
                return static_cast<cContextInstHm*>(v2_8);
            } else {
                if (unitUniqId != cContextInterface::getUniqueId(static_cast<const cContextInstance*>(v0_3), static_cast<const cContextCharacter*>(nullptr))) {
                    if (v0_3->mpNext != nullptr) {
                        v0_3 = v0_3->mpNext;
                    } else {
                        break;
                    }
                } else {
                    v2_8 = v0_3;
                    return static_cast<cContextInstHm*>(v2_8);
                }
            }
        }
        v2_8 = nullptr;
    }
    return static_cast<cContextInstHm*>(v2_8);
}

__attribute__((weak)) cContextInstHm* sContextManager::searchContextFromCharId(u32 charId, u32 pawnId, MtArray* pArray) {
    DDON_STUB("sContextManager::searchContextFromCharId")
    return nullptr;
}

cContextInstHm* sContextManager::getContextMyPlayer() {
    return mpContextPlayer;
}

cContextInstHm* sContextManager::getMyPawnPartyContextSequential(u32& cur, u32 pawnType) {
    cContextInstHm* v5_8;
    if ((cur) > 7u) {
        v5_8 = nullptr;
    } else {
        cContextInstHm* v3_3;
        if (pawnType == 0) {
            for (u32 v2_0 = cur;;) {
                cContextInstHm* t5 = mpContextPartyPlayerList[v2_0];
                if (t5 != nullptr) {
                    if ((t5->mIsValid & 1) != 0) {
                        if (cContextInterface::isPawn(t5)) {
                            if (cContextInterface::isPawnOwner(t5)) {
                                v3_3 = t5;
                                break;
                            }
                        }
                    }
                }
                u32 t8 = cur;
                cur = t8 + 1u;
                if ((cur) <= 7u) {
                    v2_0 = t8 + 1u;
                } else {
                    v5_8 = nullptr;
                    return v5_8;
                }
            }
        } else {
            for (u32 v0_0 = cur;;) {
                cContextInstHm* t0 = mpContextPartyPlayerList[v0_0];
                if (t0 != nullptr) {
                    if ((t0->mIsValid & 1) != 0) {
                        if (cContextInterface::isPawn(t0)) {
                            if (cContextInterface::isPawnOwner(t0)) {
                                if (cContextInterface::getPawnType(t0) == pawnType) {
                                    v3_3 = t0;
                                    break;
                                }
                            }
                        }
                    }
                }
                u32 t4 = cur;
                cur = t4 + 1u;
                if ((cur) <= 7u) {
                    v0_0 = t4 + 1u;
                } else {
                    v5_8 = nullptr;
                    return v5_8;
                }
            }
        }
        u32 t9 = cur;
        cur = t9 + 1u;
        v5_8 = v3_3;
    }
    return v5_8;
}

__attribute__((weak)) cContextInstHm* sContextManager::getMyPawnContext(u32 pawnId, u32 pawnType) {
    DDON_STUB("sContextManager::getMyPawnContext")
    return nullptr;
}

__attribute__((weak)) void sContextManager::updateContextInstanceCore(sContextManager::List& ContextList) {
    DDON_STUB("sContextManager::updateContextInstanceCore")
    /* stub */
}

bool sContextManager::isMemberContext(const cContextInstHm* pContext) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    cContextInstHm* p0_0 = mpContextPlayer;
    for (unsigned int i0_1 = 0; i0_1 <= 99u; p0_0 += 1, i0_1 += 1u) {
        if ((p0_0->mIsValid & 1) != 0) {
            if (pContext == p0_0) {
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return true;
            }
        }
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    return false;
}

__attribute__((weak)) void sContextManager::entryContextPlayer(u32 characterId, u32 pawnId) {
    DDON_STUB("sContextManager::entryContextPlayer")
    /* stub */
}

__attribute__((weak)) void sContextManager::removeContextPlayer(u32 characterId, u32 pawnId) {
    DDON_STUB("sContextManager::removeContextPlayer")
    /* stub */
}

__attribute__((weak)) void sContextManager::removeAllContextPlayer() {
    DDON_STUB("sContextManager::removeAllContextPlayer")
    /* stub */
}

__attribute__((weak)) cContextInstHm* sContextManager::getContextPlayer(u32 characterId, u32 pawnId) {
    DDON_STUB("sContextManager::getContextPlayer")
    return nullptr;
}

cContextInstHm* sContextManager::getContextPlayerIndex(u32 index, bool validCheck) {
    if (index <= 99u) {
        if (validCheck) {
            if (!mpContextPlayer[index].isValid()) {
                return nullptr;
            }
        }
        return &mpContextPlayer[index];
    } else {
        return nullptr;
    }
}

bool sContextManager::isPlayerRPCID(u32 rpcId) {
    return (rpcId - 2000u) <= 999u;
}

__attribute__((weak)) cContextInstHm* sContextManager::getContextPlayerRPCID(u32 rpcId) {
    DDON_STUB("sContextManager::getContextPlayerRPCID")
    return nullptr;
}

__attribute__((weak)) cContextInstHm* sContextManager::getContextPlayerSender(u32 rpcId, u32 characterId, u32 searchId) {
    DDON_STUB("sContextManager::getContextPlayerSender")
    return nullptr;
}

__attribute__((weak)) cContextInstHm* sContextManager::entryContextPartyPlayer(s32 memberIndex, u32 characterId, u32 pawnId) {
    DDON_STUB("sContextManager::entryContextPartyPlayer")
    return nullptr;
}

__attribute__((weak)) void sContextManager::removeContextPartyPlayer(s32 memberIndex, bool bRemoveUI) {
    if (memberIndex > -1) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
            }
        }
        if (mpContextPartyPlayerList[memberIndex] != nullptr) {
            sGame* t0 = sGame::getInstance();
            if (!t0->isMySelfCharacterId(cContextInterface::getPlCharacterId(mpContextPartyPlayerList[memberIndex]))) {
                if (!!bRemoveUI) {
                    static_cast<sGUIExt*>(sGUI::getInstance())->removeGauge(memberIndex);
                }
            }
            mpContextPartyPlayerList[memberIndex]->cContextInstHm::removeParty();
            mpContextPartyPlayerList[memberIndex] = nullptr;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    }
}

__attribute__((weak)) void sContextManager::removeAllContextPartyPlayer(bool bRemoveUI) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    removeContextPartyPlayer(0, bRemoveUI);
    removeContextPartyPlayer(1, bRemoveUI);
    removeContextPartyPlayer(2, bRemoveUI);
    removeContextPartyPlayer(3, bRemoveUI);
    removeContextPartyPlayer(4, bRemoveUI);
    removeContextPartyPlayer(5, bRemoveUI);
    removeContextPartyPlayer(6, bRemoveUI);
    removeContextPartyPlayer(7, bRemoveUI);
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

cContextInstHm* sContextManager::getContextPartyPlayer(u32 characterId, u32 pawnId) {
    u32 i = 0;
    cContextInstHm* * p8 = &mpContextPartyPlayerList[0];
    do {
        if ((*p8) != nullptr) {
            if ((*p8)->cContextInstance::isValid()) {
                if (cContextInterface::checkId(*p8, characterId, pawnId)) {
                    return *p8;
                }
            }
        }
        i += 1u;
        p8 += static_cast<int>(1);
    } while (i <= 7u);
    return nullptr;
}

cContextInstHm* sContextManager::getContextPartyPlayerIndex(u32 index, bool validCheck) {
    if (index <= 7u) {
        if (mpContextPartyPlayerList[index] != nullptr) {
            if (validCheck) {
                if (mpContextPartyPlayerList[index]->cContextInstance::isValid()) {
                    return mpContextPartyPlayerList[index];
                } else {
                    return nullptr;
                }
            } else {
                return mpContextPartyPlayerList[index];
            }
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

cContextInstHm* sContextManager::getContextPartyPlayerFromMemberIndex(s32 memberIndex) {
    if (memberIndex != -1) {
        u32 i = 0;
        for (cContextInstHm* * p0_8 = &mpContextPartyPlayerList[0]; i <= 7u; i += 1u, p0_8 += 1) {
            if ((*p0_8) != nullptr) {
                if ((*p0_8)->cContextInstance::isValid()) {
                    if (memberIndex == cContextInterface::getMemberIndex(*p0_8)) {
                        return *p0_8;
                    }
                }
            }
        }
    }
    sGame* t0 = sGame::getInstance();
    if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(reinterpret_cast<char*>(t0) + t0->getSelfMemberIndex()) + 216)) == 0) {
        return mpContextPlayer;
    } else {
        return nullptr;
    }
}

__attribute__((weak)) const cContextInstHm* sContextManager::getContextPartyLeader() {
    DDON_STUB("sContextManager::getContextPartyLeader")
    return nullptr;
}

bool sContextManager::isPartyMember(u32 characterId, u32 pawnId) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    for (u32 i = 0; i <= 7u; i = i + 1u) {
        bool v1_0 = cContextInterface::checkId(mpContextPartyPlayerList[i], characterId, pawnId);
        if (v1_0) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return true;
        }
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    return false;
}

bool sContextManager::isPartyMember(const cContextInstHm* pContext) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    cContextInstHm* * p0_0 = &mpContextPartyPlayerList[0];
    unsigned int i0_1 = 0;
    cContextInstHm* * v1_0;
    for (;;) {
        if (pContext == (*p0_0)) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return true;
        } else {
            if ((i0_1 + 1u) <= 7u) {
                p0_0 += 1;
                i0_1 += 1u;
            } else {
                v1_0 = &p0_0[1];
                break;
            }
        }
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    return false;
}

__attribute__((weak)) s32 sContextManager::getPartyPawnEntryNum(u8 pawnType, bool isOwner) {
    DDON_STUB("sContextManager::getPartyPawnEntryNum")
    return {};
}

__attribute__((weak)) cContextInstHm* sContextManager::getContextPartyPawn(u8 pawnType, u32 pawnId, bool isOwner) {
    DDON_STUB("sContextManager::getContextPartyPawn")
    return nullptr;
}

__attribute__((weak)) bool sContextManager::isExistPartyPawn(u8 pawnType, u32 pawnId, bool isOwner) {
    DDON_STUB("sContextManager::isExistPartyPawn")
    return {};
}

__attribute__((weak)) void sContextManager::setContextPawnReaction(u32 pawnId, u32 reactNo, u32 motNo) {
    DDON_STUB("sContextManager::setContextPawnReaction")
    /* stub */
}

__attribute__((weak)) void sContextManager::initChargeInfoAllContext() {
    DDON_STUB("sContextManager::initChargeInfoAllContext")
    /* stub */
}

__attribute__((weak)) cContextInstance* sContextManager::searchContextInstance(nGroup::ID_CONTEXT Type, u32 UniqueId) {
    DDON_STUB("sContextManager::searchContextInstance")
    return nullptr;
}

cContextInstNpc* sContextManager::searchContextNpc(u32 UniqueId) {
    cContext* v0_2 = mList[10].getTop();
    cContext* v1_0;
    for (;;) {
        if (v0_2 == nullptr) {
            v1_0 = nullptr;
            break;
        } else {
            if (v0_2->mId != 10) {
                v1_0 = nullptr;
                break;
            } else {
                if (UniqueId == cContextInterface::getUniqueId(static_cast<const cContextInstance*>(v0_2), static_cast<const cContextCharacter*>(nullptr))) {
                    v1_0 = v0_2;
                    break;
                } else {
                    v0_2 = v0_2->mpNext;
                }
            }
        }
    }
    return static_cast<cContextInstNpc*>(v1_0);
}

__attribute__((weak)) cContextInstOm* sContextManager::searchContextOm(u32 UniqueId) {
    DDON_STUB("sContextManager::searchContextOm")
    return nullptr;
}

__attribute__((weak)) void sContextManager::setContextCharacter(cCharacterData& src, cContextInstHm& dst, u32 characterId, bool resetFlag) {
    DDON_STUB("sContextManager::setContextCharacter")
    /* stub */
}

__attribute__((weak)) void sContextManager::setReturnPrepareStatus(cContextInstHm* pContext) {
    DDON_STUB("sContextManager::setReturnPrepareStatus")
    /* stub */
}

__attribute__((weak)) bool sContextManager::isDeadEnemy(u32 uniqueId) {
    DDON_STUB("sContextManager::isDeadEnemy")
    return {};
}

void sContextManager::getContextEnemytList(u32 stageNo, u32 groupNo, MtArray& list) {
    s32 stageId = static_cast<sAreaExt*>(sArea::getInstance())->convertStageId(static_cast<s32>(stageNo));
    cContext* v0_3;
    if (stageId > 0) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
        if (list.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(list.mpArray));
        }
        list.mpArray = nullptr;
        list.mLength = 0;
        list.mBufsiz = 0;
        v0_3 = mList[9].getTop();
    } else {
        return;
    }
    for (;;) {
        if (v0_3 == nullptr) {
            break;
        } else {
            if (v0_3->mId == 9) {
                u32 t0 = cContextInterface::getUniqueId(static_cast<const cContextInstance*>(v0_3), static_cast<const cContextCharacter*>(nullptr));
                if (stageId == static_cast<int>(nLayout::getUniqueIDStageId(t0))) {
                    if (groupNo == nLayout::getUniqueIDLayoutGroup(t0)) {
                        u32 t1 = list.mLength;
                        u32 t2 = list.mBufsiz;
                        if (t1 < t2) {
                            list.mLength = t1 + 1u;
                            list.mpArray[t1] = static_cast<MtObject*>(v0_3);
                        } else {
                            void* t3 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t2 + 32u) * 8, 16u);
                            memset(t3, 0, static_cast<size_t>(t2 + 32u) * 8);
                            memcpy(t3, static_cast<const void*>(list.mpArray), static_cast<size_t>(list.mLength) * 8);
                            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(list.mpArray));
                            list.mpArray = static_cast<MtObject* *>(t3);
                            list.mBufsiz = t2 + 32u;
                            u32 t4 = list.mLength;
                            list.mLength = t4 + 1u;
                            list.mpArray[t4] = static_cast<MtObject*>(v0_3);
                        }
                    }
                }
            }
        }
        v0_3 = v0_3->mpNext;
    }
    for (cContext* v3_3 = mList[12].getTop();;) {
        if (v3_3 == nullptr) {
            break;
        } else {
            if (v3_3->mId == 12) {
                u32 t5 = cContextInterface::getUniqueId(static_cast<const cContextInstance*>(v3_3), static_cast<const cContextCharacter*>(nullptr));
                if (stageId == static_cast<int>(nLayout::getUniqueIDStageId(t5))) {
                    if (groupNo == nLayout::getUniqueIDLayoutGroup(t5)) {
                        u32 t6 = list.mLength;
                        u32 t7 = list.mBufsiz;
                        if (t6 < t7) {
                            list.mLength = t6 + 1u;
                            list.mpArray[t6] = static_cast<MtObject*>(v3_3);
                        } else {
                            void* t8 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t7 + 32u) * 8, 16u);
                            memset(t8, 0, static_cast<size_t>(t7 + 32u) * 8);
                            memcpy(t8, static_cast<const void*>(list.mpArray), static_cast<size_t>(list.mLength) * 8);
                            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(list.mpArray));
                            list.mpArray = static_cast<MtObject* *>(t8);
                            list.mBufsiz = t7 + 32u;
                            u32 t9 = list.mLength;
                            list.mLength = t9 + 1u;
                            list.mpArray[t9] = static_cast<MtObject*>(v3_3);
                        }
                    }
                }
            }
        }
        v3_3 = v3_3->mpNext;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

__attribute__((weak)) bool sContextManager::removeContextEnemytList(u32 stageNo, u32 groupNo, MtArray& list) {
    DDON_STUB("sContextManager::removeContextEnemytList")
    return {};
}

cContextInstance* sContextManager::getContextEnemyAlive(nLayout::stLayoutID layoutID, u32 setNo) {
    s32 stageId = static_cast<sAreaExt*>(sArea::getInstance())->convertStageId(static_cast<s32>(layoutID.mLayoutID & 1023u));
    cContext* v0_3;
    if (stageId > 0) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
            }
        }
        v0_3 = mList[9].getTop();
    } else {
        return nullptr;
    }
    cContext* v2_11;
    for (;;) {
        if (v0_3 == nullptr) {
            v2_11 = nullptr;
            break;
        } else {
            if (v0_3->mId == 9) {
                u32 t0 = cContextInterface::getUniqueId(static_cast<const cContextInstance*>(v0_3), static_cast<const cContextCharacter*>(nullptr));
                if (stageId == static_cast<int>(nLayout::getUniqueIDStageId(t0))) {
                    u32 t1 = nLayout::getUniqueIDLayoutGroup(t0);
                    if ((layoutID.mLayoutID >> 10) == t1) {
                        if (setNo == nLayout::getUniqueIDLayoutID(t0)) {
                            if (cContextInterface::getHp(static_cast<const cContextInstance*>(v0_3), static_cast<const cContextCharacter*>(nullptr), 0u) != 0) {
                                v2_11 = v0_3;
                                break;
                            }
                        }
                    }
                }
            }
        }
        v0_3 = v0_3->mpNext;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    return static_cast<cContextInstance*>(v2_11);
}

inline sContextManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sContextManager::MyDTI sContextManager::DTI("sContextManager", &::cSystem::DTI, 528ul, 0u, 0u);

sContextManager* sContextManager::mpInstance;

__attribute__((weak)) MtObject* sContextManager::MyDTI::newInstance() const {
    DDON_STUB("sContextManager::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sContextManager::List::getDTI() const {
    return sContextManager::List::DTI;
}

inline void* sContextManager::List::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sContextManager::List::DTI)->memAlloc(sz, align, sContextManager::List::DTI.getID());
}

inline void sContextManager::List::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(sContextManager::List::DTI)->memFree(p_addr);
}

sContextManager::List::~List() {
}

__attribute__((weak)) void sContextManager::List::createProperty(MtPropertyList& s) {
}

MtUI* sContextManager::List::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline sContextManager::List::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sContextManager::List::MyDTI sContextManager::List::DTI("sContextManager::List", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* sContextManager::List::MyDTI::newInstance() const {
    return new (16u) sContextManager::List;
}

