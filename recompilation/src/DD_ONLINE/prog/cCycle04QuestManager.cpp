// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCycle04QuestManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Quest.h"
#include "Protocol/UserSession/S2C.h"
#include "cCycleQuestManagerBase.h"
#include "cCycleQuestSubCategoryManager.h"
#include "cNetGameServer.h"
#include "cQuestSvNotice.h"
#include "cQuestSvNoticeManager.h"
#include "nQuest.h"
#include "../../XFramework/rGUIMessage.h"
#include "rNamedParam.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCycle04QuestManager::getDTI() const {
    return cCycle04QuestManager::DTI;
}

void* cCycle04QuestManager::operator new(size_t sz, u32 align) {
    return cCycle04QuestManager::getAllocator()->memAlloc(sz, align, cCycle04QuestManager::DTI.getID());
}

u32 cCycle04QuestManager::getQuestManagerType() const {
    return 7;
}

__attribute__((weak)) u32 cCycle04QuestManager::getMainStageNo(nQuest::SCHEDULE_ID cycleContentsScheduleId) const {
    DDON_STUB("cCycle04QuestManager::getMainStageNo")
    return {};
}

nQuest::CYCLE_CONTENTS_CATEGORY cCycle04QuestManager::getCycleContentsCategory() const {
    return nQuest::CYCLE_CONTENTS_CATEGORY_RAID_BOSS;
}

__attribute__((weak)) void cCycle04QuestManager::callbackPhase(void* pPacket) {
    DDON_STUB("cCycle04QuestManager::callbackPhase")
    /* stub */
}

__attribute__((weak)) void cCycle04QuestManager::setClearTimeBonus(const ClearTimePointBonusVec& clearTimePointBonus) {
    DDON_STUB("cCycle04QuestManager::setClearTimeBonus")
    /* stub */
}

void cCycle04QuestManager::setRaidBossEnemyParam(const CRaidBossEnemyParam& enemyParam) {
    mRaidBossId = enemyParam.m_unRaidBossId;
    mpRaidBossEnemyParam->mHpRate = enemyParam.m_unRateHp;
    mpRaidBossEnemyParam->mHpSub = enemyParam.m_usRateHpPart;
    mpRaidBossEnemyParam->mShrinkEnduranceMain = enemyParam.m_usRateShrinkDef;
    mpRaidBossEnemyParam->mShrinkEnduranceSub = enemyParam.m_usRateShrinkDefPart;
    mpRaidBossEnemyParam->mBlowEnduranceMain = enemyParam.m_usRateBlowDef;
    mpRaidBossEnemyParam->mBlowEnduranceSub = enemyParam.m_usRateBlowDefPart;
    mpRaidBossEnemyParam->mOcdEndurance = enemyParam.m_usRateOcdDef;
    mpRaidBossEnemyParam->mAilmentDamage = enemyParam.m_usRateOcdAtk;
    mpRaidBossEnemyParam->mShakeEnduranceMain = enemyParam.m_usRateShakeDef;
    mpRaidBossEnemyParam->mDownEnduranceMain = enemyParam.m_usRateDownDef;
    mpRaidBossEnemyParam->mPower = enemyParam.m_usRateStr;
    mpRaidBossEnemyParam->mAttackBasePhys = enemyParam.m_usRatePhyAtkBase;
    mpRaidBossEnemyParam->mAttackBaseMagic = enemyParam.m_usRateMagAtkBase;
    mpRaidBossEnemyParam->mDefenceBasePhys = enemyParam.m_usRatePhyDefBase;
    mpRaidBossEnemyParam->mDefenceBaseMagic = enemyParam.m_usRateMagDefBase;
}

__attribute__((weak)) void cCycle04QuestManager::setRaidBossHasRegionBreakReward(const HasRegionBreakRewardVec& regionBreakRewardList) {
    DDON_STUB("cCycle04QuestManager::setRaidBossHasRegionBreakReward")
    /* stub */
}

cNamedParam* cCycle04QuestManager::getRaidBossEnemyParam(u32 raidBossId) const {
    if (mRaidBossId == raidBossId) {
        return mpRaidBossEnemyParam;
    } else {
        return nullptr;
    }
}

__attribute__((weak)) u32 cCycle04QuestManager::getStartDemoStageNo() const {
    DDON_STUB("cCycle04QuestManager::getStartDemoStageNo")
    return {};
}

__attribute__((weak)) u32 cCycle04QuestManager::getStartDemoNo() const {
    DDON_STUB("cCycle04QuestManager::getStartDemoNo")
    return {};
}

__attribute__((weak)) void cCycle04QuestManager::calcResultPointEx() {
    DDON_STUB("cCycle04QuestManager::calcResultPointEx")
    /* stub */
}

__attribute__((weak)) void cCycle04QuestManager::callbackBreakRegion(uCharacter* pCharacter, u32 regionNo) {
    DDON_STUB("cCycle04QuestManager::callbackBreakRegion")
    /* stub */
}

cCycle04QuestManager::cCycle04QuestManager() : cCycleQuestManagerBase("Grand Mission:Raid Boss") {
    mpRaidBossEnemyParam = new (16u) cNamedParam;
    mRaidBossId = 0;
    mRaidBossPlayEndDist = 100.0f;
    cQuestSvNoticeManager::addCallbackFunc(cQuestSvNoticeCallback::DTI, cQuestSvNotCycle04Phase::DTI)->cQuestSvNoticeCallback::setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvNoticeCallback::PCallbackFunc>(&::cCycle04QuestManager::callbackPhase));
}

__attribute__((noinline)) cCycle04QuestManager::~cCycle04QuestManager() {
    if (mClearTimeBonusList.mLength != 0) {
        u32 v0_0 = mClearTimeBonusList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mClearTimeBonusList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mClearTimeBonusList.mpArray[i0_3];
                v1_0 = mClearTimeBonusList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mClearTimeBonusList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mClearTimeBonusList.mpArray));
    }
    mClearTimeBonusList.mpArray = nullptr;
    mClearTimeBonusList.mBufsiz = 0;
    mClearTimeBonusList.mLength = 0;
    if (mRegionBreakRewardList.mLength != 0) {
        u32 v3_0 = mRegionBreakRewardList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mRegionBreakRewardList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mRegionBreakRewardList.mpArray[i3_3];
                v4_0 = mRegionBreakRewardList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mRegionBreakRewardList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mRegionBreakRewardList.mpArray));
    }
    mRegionBreakRewardList.mpArray = nullptr;
    mRegionBreakRewardList.mBufsiz = 0;
    mRegionBreakRewardList.mLength = 0;
    release();
    if (mpRaidBossEnemyParam != nullptr) {
        delete mpRaidBossEnemyParam;
        mpRaidBossEnemyParam = nullptr;
    }
}

inline cCycle04QuestManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCycle04QuestManager::MyDTI cCycle04QuestManager::DTI("cCycle04QuestManager", &::cCycleQuestManagerBase::DTI, 312ul, 0u, 0u);

MtObject* cCycle04QuestManager::MyDTI::newInstance() const {
    return new (16u) cCycle04QuestManager;
}

const MtDTI& cCycle04QuestManager::cClearTimeBonus::getDTI() const {
    return cCycle04QuestManager::cClearTimeBonus::DTI;
}

cCycle04QuestManager::cClearTimeBonus::~cClearTimeBonus() {
}

__attribute__((weak)) void cCycle04QuestManager::cClearTimeBonus::createProerty(MtPropertyList& s) {
}

inline cCycle04QuestManager::cClearTimeBonus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCycle04QuestManager::cClearTimeBonus::MyDTI cCycle04QuestManager::cClearTimeBonus::DTI("cCycle04QuestManager::cClearTimeBonus", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCycle04QuestManager::cClearTimeBonus::MyDTI::newInstance() const {
    return new (16u) cCycle04QuestManager::cClearTimeBonus;
}

const MtDTI& cCycle04QuestManager::cRegionBreakReward::getDTI() const {
    return cCycle04QuestManager::cRegionBreakReward::DTI;
}

inline cCycle04QuestManager::cRegionBreakReward::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCycle04QuestManager::cRegionBreakReward::MyDTI cCycle04QuestManager::cRegionBreakReward::DTI("cCycle04QuestManager::cRegionBreakReward", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCycle04QuestManager::cRegionBreakReward::MyDTI::newInstance() const {
    return new (16u) cCycle04QuestManager::cRegionBreakReward;
}

template MtTypedArray<cCycle04QuestManager::cClearTimeBonus>::~MtTypedArray();

template MtTypedArray<cCycle04QuestManager::cRegionBreakReward>::~MtTypedArray();

