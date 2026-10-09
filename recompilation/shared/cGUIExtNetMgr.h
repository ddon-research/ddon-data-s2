#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "CharacterCommon.h"
#include "JobMaster.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "Skill.h"
#include "nDDOUtility.h"

// Forward declarations
class CDataArisenProfile;
class CDataCommonU32;
class CDataEquipPreset;
class CDataJobChangeInfo;
class CDataLearnedAcquirementParam;
class CDataNormalSkillParam;
class CDataPawnJobChangeInfo;
class CDataPresetAbilityParam;
class CDataSetAcquirementParam;
class CDataSkillParam;
class MtAllocator;
class MtDTI;
class MtString;
namespace rAcquirement { class rAbilityData; }

// Declarations
class cGUIExtNetMgr;

// Type aliases from DWARF
using CEquipPreset = CDataEquipPreset;
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using EquipPresetVec = MtTypedArray<CDataEquipPreset>;
using JobChangeInfoVec = MtTypedArray<CDataJobChangeInfo>;
using LearnedAcquirementParamVec = MtTypedArray<CDataLearnedAcquirementParam>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using NormalSkillParamVec = MtTypedArray<CDataNormalSkillParam>;
using PawnJobChangeInfoVec = MtTypedArray<CDataPawnJobChangeInfo>;
using PresetAbilityParamVec = MtTypedArray<CDataPresetAbilityParam>;
using SetAcquirementParamVec = MtTypedArray<CDataSetAcquirementParam>;
using SkillParamVec = MtTypedArray<CDataSkillParam>;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cGUIExtNetMgr : private MtObject
{
public:
    enum
    {
        REQ_NONE = 0,
        REQ_CUSTOM_SKILL = 1,
        REQ_ABILITY = 2,
        REQ_LEARNED_CUSTOM_SKILL = 3,
        REQ_LEARNED_NORMAL_SKILL = 4,
        REQ_LEARNED_ABILITY = 5,
        REQ_SET_CUSTOM_SKILL = 6,
        REQ_SET_ABILITY = 7,
        REQ_PRESET_ABILITY = 8,
        REQ_ABILITY_COST = 9,
        REQ_JOB_CHANGE_LIST = 10,
        REQ_ORB_GET_LIST = 11,
        REQ_ORB_GAIN_EXTEND_PARAM = 12,
        REQ_PAWN_ORB_GET_LIST = 13,
        REQ_PAWN_LEARNED_CUSTOM_SKILL = 14,
        REQ_PAWN_LEARNED_NORMAL_SKILL = 15,
        REQ_PAWN_LEARNED_ABILITY = 16,
        REQ_PAWN_SET_CUSTOM_SKILL = 17,
        REQ_PAWN_SET_ABILITY = 18,
        REQ_PAWN_ABILITY_COST = 19,
        REQ_PRESET_EQUIP_LIST = 20,
        REQ_SEND_ARISENCARD_DATA = 21,
        REQ_SEND_PAWNCARD_DATA = 22,
        REQ_GET_COG_ID = 23,
        REQ_GET_MYPAWN_DATA = 24,
        REQ_NUM = 25,
    };
    enum
    {
        BasicAbilityMax = 500,
        PawnDisableAbilityMax = 48,
        PresetEquipMax = 10,
        WarpPointMax = 80,
    };
public:
    class MyDTI;
    struct _REQData;
    struct _DLData;
    struct DogmaOrbInfo;
    struct BasicAbilityInfo;
    struct PresetEquipInfo;
    struct PresetEquip;
    struct WarpPoint;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct _REQData
    {
    public:
        _REQData();
    public:
        u32 Bit;  // offset: 0x0
        u32 Param;  // offset: 0x4
        bool IsRequest;  // offset: 0x8
    };
public:
    struct DogmaOrbInfo
    {
    public:
        void clear();
    public:
        nDDOUtility::cBitSet<8> Branch[4];  // offset: 0x0
        nDDOUtility::cBitSet<5> Tree;  // offset: 0x10
    };
public:
    struct BasicAbilityInfo
    {
    public:
        BasicAbilityInfo();
        bool isEnable() const;
    public:
        nDDOUtility::cBitSet<32> mRelease;  // offset: 0x0
        u16 mMsgIndex;  // offset: 0x4
        u16 mSortNo;  // offset: 0x6
        u8 mIconId;  // offset: 0x8
        u8 mCost;  // offset: 0x9
        u8 mJobId;  // offset: 0xa
        u8 mMaxLv;  // offset: 0xb
    };
public:
    struct PresetEquip
    {
    public:
        PresetEquip();
    public:
        MtString UID;  // offset: 0x0
        u32 ItemId;  // offset: 0x8
    };
public:
    struct WarpPoint
    {
    public:
        WarpPoint();
    public:
        u32 Id[80];  // offset: 0x0
        u32 Num;  // offset: 0x140
    };
public:
    struct PresetEquipInfo
    {
    public:
        PresetEquipInfo();
    public:
        cGUIExtNetMgr::PresetEquip Equip[17];  // offset: 0x0
        MtString Name;  // offset: 0x110
        u8 JobId;  // offset: 0x118
    };
public:
    struct _DLData
    {
    public:
        _DLData();
    public:
        u32 ReceiveAbilityParam;  // offset: 0x0
        u32 ReceiveSetCustomSkill;  // offset: 0x4
        u32 ReceivePawnSetCustomSkill;  // offset: 0x8
        u32 ReceiveSkillAbilityPawnId;  // offset: 0xc
        bool ReceiveCustomSkill;  // offset: 0x10
        bool ReceiveNormalSkill;  // offset: 0x11
        bool ReceiveAbility;  // offset: 0x12
        bool ReceiveSetAbility;  // offset: 0x13
        bool ReceivePresetAbility;  // offset: 0x14
        bool ReceiveAbilityCost;  // offset: 0x15
        bool ReceiveDogmaOrb;  // offset: 0x16
        bool ReceiveOrbGainExtendParam;  // offset: 0x17
        bool ReceivePawnDogmaOrb;  // offset: 0x18
        bool ReceiveCustomSkillParam[10];  // offset: 0x19
        bool ReceivePawnCustomSkill;  // offset: 0x23
        bool ReceivePawnNormalSkill;  // offset: 0x24
        bool ReceivePawnAbility;  // offset: 0x25
        bool ReceivePawnSetAbility;  // offset: 0x26
        bool ReceivePawnAbilityCost;  // offset: 0x27
        bool ReceivePresetEquip;  // offset: 0x28
        bool ReceiveGetCogId;  // offset: 0x29
        cGUIExtNetMgr::DogmaOrbInfo DogmaOrb[4];  // offset: 0x2c
        cGUIExtNetMgr::DogmaOrbInfo PawnDogmaOrb[4];  // offset: 0x7c
        SkillParamVec CustomSkillParam[10];  // offset: 0xd0
        cGUIExtNetMgr::BasicAbilityInfo AbilityParam[500];  // offset: 0x210
        u16 PawnDisableAbility[48];  // offset: 0x1980
        SetAcquirementParamVec SetCustomSkill[10];  // offset: 0x19e0
        SetAcquirementParamVec PawnSetCustomSkill[10];  // offset: 0x1b20
        cGUIExtNetMgr::PresetEquipInfo PresetEquipList[10];  // offset: 0x1c60
        cGUIExtNetMgr::WarpPoint WarpPointList;  // offset: 0x27a0
        MtString CogId;  // offset: 0x28e8
        u32 ReleasedJobBit;  // offset: 0x28f0
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    void clearReceiveFlags();
    void clearPawnSkillReceiveFlags();
    void clearAbilityReceiveFlags();
    void clearCustomSkillReceiveFlags();
    void clearJobChangeReceiveFlags();
    void clearPawnJobChangeReceiveFlags();
    void clearOrbGainParamReceiveFlags();
    const SkillParamVec& getCustomSkillParam(u32 JobId);
    bool isReceiveCustomSkillParam(u32 JobId);
    const BasicAbilityInfo& getAbilityParam(u32 abilityId);
    const LearnedAcquirementParamVec& getLearnedCustomSkill();
    const NormalSkillParamVec& getLearnedNormalSkill();
    const LearnedAcquirementParamVec& getLearnedAbility();
    const SetAcquirementParamVec& getSetCustomSkill(u32 JobId);
    const SetAcquirementParamVec& getSetAbility();
    const PresetAbilityParamVec& getPresetAbility();
    u32 getAbilityCost();
    bool isReleasedJob(u32 JobId);
    const JobChangeInfoVec& getJobChangeList();
    const JobChangeInfoVec& getJobReleaseList();
    const PawnJobChangeInfoVec& getPawnJobChangeList();
    u32 getDogmaOrbAllBranchSkill(u32 BranchNo) const;
    u32 getDogmaOrbAllTreeSkill() const;
    u32 getDogmaOrbPageParcent(u32 Page) const;
    u32 getPawnDogmaOrbAllBranchSkill(u32 BranchNo) const;
    u32 getPawnDogmaOrbAllTreeSkill() const;
    u32 getPawnDogmaOrbPageParcent(u32 Page) const;
    void setupAbilityParam(rAcquirement::rAbilityData* pData);
    bool isExitRequest(u32 ReqID);
    static u32 checkAfterRequest(u32 ReqID1, u32 ReqID2);
    const LearnedAcquirementParamVec& getPawnLearnedCustomSkill();
    const NormalSkillParamVec& getPawnLearnedNormalSkill();
    const LearnedAcquirementParamVec& getPawnLearnedAbility();
    const SetAcquirementParamVec& getPawnSetCustomSkill(u32 JobId);
    const SetAcquirementParamVec& getPawnSetAbility();
    u32 getPawnAbilityCost();
    void setupPresetEquipList(const EquipPresetVec& List);
    void setupPresetEquipInfo(const CEquipPreset* pData);
    void setPresetEquipName(s32 PresetNo, MT_CTSTR Name);
    const PresetEquipInfo& getPresetEquipInfo(u32 PresetNo);
    void setupWarpPointList(const CommonU32Vec& List);
    void addWarpPointList(u32 Id);
    void setArisenCardProfile(const CDataArisenProfile& Profile);
    void setArisenCardComment(MtString& Comment);
    MT_CTSTR getCogId();
    void setCogId(MT_CTSTR pId);
private:
    bool reqCustomSkill(_REQData* pData);
    void initCustomSkill(_REQData* pData);
    bool reqAbility(_REQData* pData);
    void initAbility(_REQData* pData);
    bool reqLearnedCustomSkill(_REQData* pData);
    void initLearnedCustomSkill(_REQData* pData);
    bool reqLearnedNormalSkill(_REQData* pData);
    void initLearnedNormalSkill(_REQData* pData);
    bool reqLearnedAbility(_REQData* pData);
    void initLearnedAbility(_REQData* pData);
    bool reqSetCustomSkill(_REQData* pData);
    void initSetCustomSkill(_REQData* pData);
    bool reqSetAbility(_REQData* pData);
    void initSetAbility(_REQData* pData);
    bool reqPresetAbility(_REQData* pData);
    void initPresetAbility(_REQData* pData);
    bool reqAbilityCost(_REQData* pData);
    void initAbilityCost(_REQData* pData);
    bool reqJobChangeList(_REQData* pData);
    void initJobChangeList(_REQData* pData);
    bool reqOrbGetList(_REQData* pData);
    void initOrbGetList(_REQData* pData);
    bool reqOrbGainExtendParam(_REQData* pData);
    void initOrbGainExtendParam(_REQData* pData);
    bool reqPawnOrbGetList(_REQData* pData);
    void initPawnOrbGetList(_REQData* pData);
    bool reqPawnLearnedCustomSkill(_REQData* pData);
    void initPawnLearnedCustomSkill(_REQData* pData);
    bool reqPawnLearnedNormalSkill(_REQData* pData);
    void initPawnLearnedNormalSkill(_REQData* pData);
    bool reqPawnLearnedAbility(_REQData* pData);
    void initPawnLearnedAbility(_REQData* pData);
    bool reqPawnSetCustomSkill(_REQData* pData);
    void initPawnSetCustomSkill(_REQData* pData);
    bool reqPawnSetAbility(_REQData* pData);
    void initPawnSetAbility(_REQData* pData);
    bool reqPawnAbilityCost(_REQData* pData);
    void initPawnAbilityCost(_REQData* pData);
    bool reqPresetEquipList(_REQData* pData);
    void initPresetEquipList(_REQData* pData);
    bool reqSendArisenCardData(_REQData* pData);
    void initSendArisenCardData(_REQData* pData);
    bool reqSendPawnCardData(_REQData* pData);
    void initSendPawnCardData(_REQData* pData);
    bool reqGetCogId(_REQData* pData);
    void initGetCogId(_REQData* pData);
    bool reqGetMyPawnData(_REQData* pData);
public:
    cGUIExtNetMgr();
    virtual ~cGUIExtNetMgr();
    void move();
    bool isRequest();
    bool isComplete();
    void setRequest(u32 ReqId);
    void setRequestParam(u32 ReqId, u32 Param);
    void setRequestBit(u32 ReqId, u32 Bit);
    void clearRequest(u32);
    void clearRequest(_REQData* pData);
    u32 getRequestParam(u32);
    u32 getRequestBit(u32);
private:
    void moveWaitServer();
    void moveNextRequest();
    u32 pickoutJobIdFromBit(u32& Bit);
    u32 calcDogmaOrbAllBranchSkill(const DogmaOrbInfo* pInfoHead, u32 BranchNo) const;
    u32 calcDogmaOrbAllTreeSkill(const DogmaOrbInfo* pInfoHead) const;
    u32 calcDogmaOrbPageParcent(const DogmaOrbInfo* pInfo) const;
public:
    _REQData mReqData[25];  // offset: 0x8
    _DLData mData;  // offset: 0x138
    bool mIsComplete;  // offset: 0x2a30
private:
    u32 mServerCommandId;  // offset: 0x2a34
    u32 mRequestId;  // offset: 0x2a38
    LearnedAcquirementParamVec dummy_learned_custom_skill;  // offset: 0x2a40
    LearnedAcquirementParamVec dummy_learned_ability;  // offset: 0x2a60
    SetAcquirementParamVec dummy_set_ability;  // offset: 0x2a80
    PresetAbilityParamVec dummy_preset_ability;  // offset: 0x2aa0
    JobChangeInfoVec dummy_jobchange_list;  // offset: 0x2ac0
    PawnJobChangeInfoVec dummy_pawn_jobchange_list;  // offset: 0x2ae0
    NormalSkillParamVec dummy_learned_normal_skill;  // offset: 0x2b00
    CDataArisenProfile mArisenCardData;  // offset: 0x2b20
    MtString mArisenCardComment;  // offset: 0x2b48
public:
    static MyDTI DTI;
};
