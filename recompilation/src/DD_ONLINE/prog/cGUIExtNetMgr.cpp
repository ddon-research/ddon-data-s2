// Reconstructed from the game's DWARF debug information.
#include <new>
#include <sce_atomic.h>
#include <string.h>
#include "cGUIExtNetMgr.h"
#include "Protocol/PacketData/Achievement.h"
#include "Protocol/PacketData/CharacterCommon.h"
#include "Protocol/PacketData/Common.h"
#include "Protocol/PacketData/Item.h"
#include "Protocol/PacketData/JobMaster.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/UserSession/S2C.h"
#include "Protocol/PacketData/Skill.h"
#include "cNetGameServer.h"
#include "nDDOUtility.h"
#include "nHumanMsg.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cGUIExtNetMgr::getDTI() const {
    return cGUIExtNetMgr::DTI;
}

void cGUIExtNetMgr::clearReceiveFlags() {
    mData.ReceiveAbilityParam = 0;
    mData.ReceiveSetCustomSkill = 0;
    mData.ReceivePawnDogmaOrb = false;
    mData.ReceivePawnSetCustomSkill = 0;
    mData.ReceiveDogmaOrb = false;
    mData.ReceivePresetAbility = false;
    mData.ReceiveAbilityCost = false;
    mData.ReceiveCustomSkill = false;
    mData.ReceiveNormalSkill = false;
    mData.ReceiveAbility = false;
    mData.ReceiveSetAbility = false;
    mData.ReceiveGetCogId = false;
    mData.ReceivePawnAbilityCost = false;
    mData.ReceivePresetEquip = false;
    mData.ReceivePawnCustomSkill = false;
    mData.ReceivePawnNormalSkill = false;
    mData.ReceivePawnAbility = false;
    mData.ReceivePawnSetAbility = false;
    u32 idx = 0;
    u32 v1_0;
    unsigned int i1_3;
    u32 v2_0;
    u32 v4_0;
    unsigned int i4_7;
    u32 v5_0;
    u32 v7_0;
    unsigned int i7_3;
    u32 v8_0;
    for (;;) {
        mData.ReceiveCustomSkillParam[idx] = false;
        if (mData.CustomSkillParam[idx].mLength != 0) {
            v1_0 = mData.CustomSkillParam[idx].mLength;
            i1_3 = 0;
            for (;;) {
                if (mData.CustomSkillParam[idx].mpArray[i1_3] == nullptr) {
                    v2_0 = v1_0;
                } else {
                    delete mData.CustomSkillParam[idx].mpArray[i1_3];
                    v2_0 = mData.CustomSkillParam[idx].mLength;
                }
                if ((i1_3 + 1u) < v2_0) {
                    v1_0 = v2_0;
                    i1_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mData.CustomSkillParam[idx].mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mData.CustomSkillParam[idx].mpArray));
        }
        mData.CustomSkillParam[idx].mpArray = nullptr;
        mData.CustomSkillParam[idx].mBufsiz = 0;
        mData.CustomSkillParam[idx].mLength = 0;
        if (mData.SetCustomSkill[idx].mLength != 0) {
            v4_0 = mData.SetCustomSkill[idx].mLength;
            i4_7 = 0;
            for (;;) {
                if (mData.SetCustomSkill[idx].mpArray[i4_7] == nullptr) {
                    v5_0 = v4_0;
                } else {
                    delete mData.SetCustomSkill[idx].mpArray[i4_7];
                    v5_0 = mData.SetCustomSkill[idx].mLength;
                }
                if ((i4_7 + 1u) < v5_0) {
                    v4_0 = v5_0;
                    i4_7 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mData.SetCustomSkill[idx].mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mData.SetCustomSkill[idx].mpArray));
        }
        mData.SetCustomSkill[idx].mpArray = nullptr;
        mData.SetCustomSkill[idx].mBufsiz = 0;
        mData.SetCustomSkill[idx].mLength = 0;
        if (mData.PawnSetCustomSkill[idx].mLength != 0) {
            v7_0 = mData.PawnSetCustomSkill[idx].mLength;
            i7_3 = 0;
            for (;;) {
                if (mData.PawnSetCustomSkill[idx].mpArray[i7_3] == nullptr) {
                    v8_0 = v7_0;
                } else {
                    delete mData.PawnSetCustomSkill[idx].mpArray[i7_3];
                    v8_0 = mData.PawnSetCustomSkill[idx].mLength;
                }
                if ((i7_3 + 1u) < v8_0) {
                    v7_0 = v8_0;
                    i7_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mData.PawnSetCustomSkill[idx].mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mData.PawnSetCustomSkill[idx].mpArray));
        }
        mData.PawnSetCustomSkill[idx].mpArray = nullptr;
        mData.PawnSetCustomSkill[idx].mBufsiz = 0;
        mData.PawnSetCustomSkill[idx].mLength = 0;
        if ((idx + 1u) != 10) {
            idx = idx + 1u;
        } else {
            break;
        }
    }
}

const SkillParamVec& cGUIExtNetMgr::getCustomSkillParam(u32 JobId) {
    return mData.CustomSkillParam[nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(JobId))];
}

bool cGUIExtNetMgr::isReceiveCustomSkillParam(u32 JobId) {
    return mData.ReceiveCustomSkillParam[nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(JobId))];
}

const cGUIExtNetMgr::BasicAbilityInfo& cGUIExtNetMgr::getAbilityParam(u32 abilityId) {
    if (abilityId <= 499u) {
        return mData.AbilityParam[abilityId];
    } else {
        return mData.AbilityParam[0];
    }
}

const LearnedAcquirementParamVec& cGUIExtNetMgr::getLearnedCustomSkill() {
    const nUserSession::CPacket_S2C_GET_LEARNED_SKILL_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetLearnedSkillListPacket();
    return *((pData == nullptr) ? (&dummy_learned_custom_skill) : (&pData->m_LearnedAcquirementParamList));
}

const NormalSkillParamVec& cGUIExtNetMgr::getLearnedNormalSkill() {
    const nUserSession::CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetLearnedNormalSkillListPacket();
    return *((pData == nullptr) ? (&dummy_learned_normal_skill) : (&pData->m_NormalSkillParamList));
}

const LearnedAcquirementParamVec& cGUIExtNetMgr::getLearnedAbility() {
    const nUserSession::CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetLearnedAbilityList();
    return *((pData == nullptr) ? (&dummy_learned_ability) : (&pData->m_LearnedAcquirementParamList));
}

const SetAcquirementParamVec& cGUIExtNetMgr::getSetCustomSkill(u32 JobId) {
    return mData.SetCustomSkill[nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(JobId))];
}

const SetAcquirementParamVec& cGUIExtNetMgr::getSetAbility() {
    const nUserSession::CPacket_S2C_GET_SET_ABILITY_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetSetAbilityList();
    return *((pData == nullptr) ? (&dummy_set_ability) : (&pData->m_SetAcquirementParamList));
}

const PresetAbilityParamVec& cGUIExtNetMgr::getPresetAbility() {
    const nUserSession::CPacket_S2C_GET_PRESET_ABILITY_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getPresetAbilityListPacket();
    return *((pData == nullptr) ? (&dummy_preset_ability) : (&pData->m_PresetAbilityParamList));
}

u32 cGUIExtNetMgr::getAbilityCost() {
    const nUserSession::CPacket_S2C_GET_ABILITY_COST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getAbilityCostPacket();
    if (pData != nullptr) {
        return pData->CostMax();
    } else {
        return 9999;
    }
}

const JobChangeInfoVec& cGUIExtNetMgr::getJobChangeList() {
    const nUserSession::CPacket_S2C_GET_JOB_CHANGE_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetJobChangeListPacket();
    return *((pData == nullptr) ? (&dummy_jobchange_list) : (&pData->m_JobChangeInfo));
}

const JobChangeInfoVec& cGUIExtNetMgr::getJobReleaseList() {
    const nUserSession::CPacket_S2C_GET_JOB_CHANGE_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetJobChangeListPacket();
    return *((pData == nullptr) ? (&dummy_jobchange_list) : (&pData->m_JobReleaseInfo));
}

const PawnJobChangeInfoVec& cGUIExtNetMgr::getPawnJobChangeList() {
    const nUserSession::CPacket_S2C_GET_JOB_CHANGE_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetJobChangeListPacket();
    return *((pData == nullptr) ? (&dummy_pawn_jobchange_list) : (&pData->m_PawnJobChangeInfoList));
}

u32 cGUIExtNetMgr::getDogmaOrbPageParcent(u32 Page) const {
    return calcDogmaOrbPageParcent(&mData.DogmaOrb[Page]);
}

u32 cGUIExtNetMgr::getPawnDogmaOrbPageParcent(u32 Page) const {
    return calcDogmaOrbPageParcent(&mData.PawnDogmaOrb[Page]);
}

__attribute__((weak)) void cGUIExtNetMgr::setupAbilityParam(rAcquirement::rAbilityData* pData) {
    DDON_STUB("cGUIExtNetMgr::setupAbilityParam")
    /* stub */
}

__attribute__((weak)) bool cGUIExtNetMgr::isExitRequest(u32 ReqID) {
    DDON_STUB("cGUIExtNetMgr::isExitRequest")
    return {};
}

u32 cGUIExtNetMgr::checkAfterRequest(u32 ReqID1, u32 ReqID2) {
    return (ReqID2 < ReqID1) ? ReqID1 : ReqID2;
}

const LearnedAcquirementParamVec& cGUIExtNetMgr::getPawnLearnedCustomSkill() {
    const nUserSession::CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetPawnLearnedSkillListPacket();
    return *((pData == nullptr) ? (&dummy_learned_custom_skill) : (&pData->m_LearnedAcquirementParamList));
}

const NormalSkillParamVec& cGUIExtNetMgr::getPawnLearnedNormalSkill() {
    const nUserSession::CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetPawnLearnedNormalSkillListPacket();
    return *((pData == nullptr) ? (&dummy_learned_normal_skill) : (&pData->m_NormalSkillParamList));
}

const LearnedAcquirementParamVec& cGUIExtNetMgr::getPawnLearnedAbility() {
    const nUserSession::CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetPawnLearnedAbilityList();
    return *((pData == nullptr) ? (&dummy_learned_ability) : (&pData->m_LearnedAcquirementParamList));
}

const SetAcquirementParamVec& cGUIExtNetMgr::getPawnSetCustomSkill(u32 JobId) {
    return mData.PawnSetCustomSkill[nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(JobId))];
}

const SetAcquirementParamVec& cGUIExtNetMgr::getPawnSetAbility() {
    const nUserSession::CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetPawnSetAbilityList();
    return *((pData == nullptr) ? (&dummy_set_ability) : (&pData->m_SetAcquirementParamList));
}

u32 cGUIExtNetMgr::getPawnAbilityCost() {
    const nUserSession::CPacket_S2C_GET_PAWN_ABILITY_COST_RES* pData = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getPawnAbilityCostPacket();
    if (pData != nullptr) {
        return pData->CostMax();
    } else {
        return 9999;
    }
}

__attribute__((weak)) void cGUIExtNetMgr::setupPresetEquipList(const EquipPresetVec& List) {
    DDON_STUB("cGUIExtNetMgr::setupPresetEquipList")
    /* stub */
}

__attribute__((weak)) void cGUIExtNetMgr::setupPresetEquipInfo(const CEquipPreset* pData) {
    DDON_STUB("cGUIExtNetMgr::setupPresetEquipInfo")
    /* stub */
}

void cGUIExtNetMgr::setPresetEquipName(s32 PresetNo, MT_CTSTR Name) {
    if (PresetNo == 0) {
        return;
    }
    if (PresetNo <= 10) {
        if (Name != mData.PresetEquipList[PresetNo - 1].Name.ptr()) {
            if (mData.PresetEquipList[PresetNo - 1].Name.value != nullptr) {
                if (sceAtomicAdd32Relaxed(&mData.PresetEquipList[PresetNo - 1].Name.value->ref, -1) == 1) {
                    (MtString::mpAllocator)->memFree(static_cast<void*>(mData.PresetEquipList[PresetNo - 1].Name.value));
                }
                mData.PresetEquipList[PresetNo - 1].Name.value = nullptr;
            }
            if (Name != nullptr) {
                size_t t0 = strlen(Name);
                if (static_cast<unsigned int>(t0) != 0) {
                    void* t1 = (MtString::mpAllocator)->memAlloc(static_cast<size_t>(static_cast<unsigned int>(t0)) + 12, 16u);
                    mData.PresetEquipList[PresetNo - 1].Name.value = static_cast<MtString::STRING*>(t1);
                    mData.PresetEquipList[PresetNo - 1].Name.value->ref = 1;
                    mData.PresetEquipList[PresetNo - 1].Name.value->length = static_cast<unsigned int>(t0);
                    strcpy(reinterpret_cast<char*>(mData.PresetEquipList[PresetNo - 1].Name.value->str), Name);
                } else {
                    mData.PresetEquipList[PresetNo - 1].Name.value = nullptr;
                }
            } else {
                mData.PresetEquipList[PresetNo - 1].Name.value = nullptr;
            }
        }
    }
}

const cGUIExtNetMgr::PresetEquipInfo& cGUIExtNetMgr::getPresetEquipInfo(u32 PresetNo) {
    if (PresetNo != 0) {
        if (PresetNo <= 10u) {
            return mData.PresetEquipList[PresetNo - 1u];
        }
    }
    return mData.PresetEquipList[0];
}

__attribute__((weak)) void cGUIExtNetMgr::setupWarpPointList(const CommonU32Vec& List) {
    DDON_STUB("cGUIExtNetMgr::setupWarpPointList")
    /* stub */
}

void cGUIExtNetMgr::addWarpPointList(u32 Id) {
    if (mData.WarpPointList.Num <= 79u) {
        if (mData.WarpPointList.Num == 0) {
            mData.WarpPointList.Id[0] = Id;
            mData.WarpPointList.Num = mData.WarpPointList.Num + 1u;
            return;
        }
    } else {
        return;
    }
    u32 i = 0;
    do {
        if (mData.WarpPointList.Id[i] == Id) {
            return;
        }
        i += 1u;
    } while (i < mData.WarpPointList.Num);
    mData.WarpPointList.Id[mData.WarpPointList.Num] = Id;
    mData.WarpPointList.Num = mData.WarpPointList.Num + 1u;
}

void cGUIExtNetMgr::setArisenCardProfile(const CDataArisenProfile& Profile) {
    mArisenCardData.m_ucBackgroundID = Profile.m_ucBackgroundID;
    mArisenCardData.m_Title.m_unIndex = Profile.m_Title.m_unIndex;
    mArisenCardData.m_Title.m_unUid = Profile.m_Title.m_unUid;
    mArisenCardData.m_usMotionID = Profile.m_usMotionID;
    mArisenCardData.m_unMotionFrameNo = Profile.m_unMotionFrameNo;
}

__attribute__((weak)) void cGUIExtNetMgr::setArisenCardComment(MtString& Comment) {
    DDON_STUB("cGUIExtNetMgr::setArisenCardComment")
    /* stub */
}

__attribute__((weak)) void cGUIExtNetMgr::initCustomSkill(cGUIExtNetMgr::_REQData* pData) {
    DDON_STUB("cGUIExtNetMgr::initCustomSkill")
    /* stub */
}

__attribute__((weak)) void cGUIExtNetMgr::initAbility(cGUIExtNetMgr::_REQData* pData) {
    DDON_STUB("cGUIExtNetMgr::initAbility")
    /* stub */
}

__attribute__((weak)) void cGUIExtNetMgr::initSetCustomSkill(cGUIExtNetMgr::_REQData* pData) {
    DDON_STUB("cGUIExtNetMgr::initSetCustomSkill")
    /* stub */
}

__attribute__((weak)) void cGUIExtNetMgr::initPawnSetCustomSkill(cGUIExtNetMgr::_REQData* pData) {
    DDON_STUB("cGUIExtNetMgr::initPawnSetCustomSkill")
    /* stub */
}

cGUIExtNetMgr::cGUIExtNetMgr() {
    DDON_STUB("cGUIExtNetMgr::cGUIExtNetMgr")
    /* stub */
}

__attribute__((noinline)) cGUIExtNetMgr::~cGUIExtNetMgr() {
    DDON_STUB("cGUIExtNetMgr::~cGUIExtNetMgr")
    /* stub */
}

void cGUIExtNetMgr::move() {
    if (mIsComplete) {
        return;
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->isDispErrorDialog()) {
        return;
    }
    if (mServerCommandId != 0) {
        moveWaitServer();
        if (mServerCommandId == 0) {
            moveNextRequest();
        }
    } else {
        moveNextRequest();
    }
}

__attribute__((weak)) void cGUIExtNetMgr::moveWaitServer() {
    DDON_STUB("cGUIExtNetMgr::moveWaitServer")
    /* stub */
}

__attribute__((weak)) void cGUIExtNetMgr::moveNextRequest() {
    DDON_STUB("cGUIExtNetMgr::moveNextRequest")
    /* stub */
}

__attribute__((weak)) u32 cGUIExtNetMgr::calcDogmaOrbPageParcent(const cGUIExtNetMgr::DogmaOrbInfo* pInfo) const {
    DDON_STUB("cGUIExtNetMgr::calcDogmaOrbPageParcent")
    return {};
}

inline cGUIExtNetMgr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIExtNetMgr::MyDTI cGUIExtNetMgr::DTI("cGUIExtNetMgr", &::MtObject::DTI, 11088ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIExtNetMgr::MyDTI::newInstance() const {
    DDON_STUB("cGUIExtNetMgr::MyDTI::newInstance")
    return nullptr;
}

cGUIExtNetMgr::_DLData::_DLData() {
    DDON_STUB("cGUIExtNetMgr::_DLData::_DLData")
    /* stub */
}

template MtTypedArray<CDataJobChangeInfo>::~MtTypedArray();

template MtTypedArray<CDataLearnedAcquirementParam>::~MtTypedArray();

template MtTypedArray<CDataNormalSkillParam>::~MtTypedArray();

template MtTypedArray<CDataPawnJobChangeInfo>::~MtTypedArray();

template MtTypedArray<CDataPresetAbilityParam>::~MtTypedArray();

template MtTypedArray<CDataSetAcquirementParam>::~MtTypedArray();

template MtTypedArray<CDataSkillLevelParam>::~MtTypedArray();

template MtTypedArray<CDataSkillParam>::~MtTypedArray();

