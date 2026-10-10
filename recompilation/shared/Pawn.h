#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "CharacterCommon.h"
#include "CharacterEdit.h"
#include "Community.h"
#include "Item.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataCharacterEquipData;
class CDataCharacterJobData;
class CDataCommunityCharacterBaseInfo;
class CDataContextAcquirementData;
class CDataContextNormalSkillData;
class CDataEditInfo;
class CDataEquipJobItem;
class CDataOrbGainExtendParam;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataFreeRentalPawnList;
class CDataPartnerPawnData;
class CDataPawnCraftData;
class CDataPawnCraftSkill;
class CDataPawnFeedback;
class CDataPawnHistory;
class CDataPawnHp;
class CDataPawnInfo;
class CDataPawnListData;
class CDataPawnName;
class CDataPawnReaction;
class CDataPawnTotalScore;

// Type aliases from DWARF
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CEditInfo = CDataEditInfo;
using COrbGainExtendParam = CDataOrbGainExtendParam;
using CPawnCraftData = CDataPawnCraftData;
using CPawnFeedback = CDataPawnFeedback;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class CDataFreeRentalPawnList : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataFreeRentalPawnList();
    explicit CDataFreeRentalPawnList(u32, const char*, u32, u32, u32, u64);
public:
    u32 m_unPawnId;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    u32 m_unFrameIconId;  // offset: 0x18
    u32 m_unBackIconId;  // offset: 0x1c
    u32 m_unLineupId;  // offset: 0x20
    u64 m_ullExpireDateTime;  // offset: 0x28
    static MyDTI DTI;
};

class CDataPartnerPawnData : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPartnerPawnData();
    explicit CDataPartnerPawnData(u32, u32, u8);
public:
    u32 m_unPawnId;  // offset: 0x8
    u32 m_unLikability;  // offset: 0xc
    u8 m_ucPersonality;  // offset: 0x10
    static MyDTI DTI;
};

class CDataPawnCraftSkill : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnCraftSkill();
    explicit CDataPawnCraftSkill(u8 in_Type, u32 in_Level);
public:
    u8 m_ucType;  // offset: 0x8
    u32 m_unLevel;  // offset: 0xc
    static MyDTI DTI;
};

class CDataPawnFeedback : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnFeedback();
    explicit CDataPawnFeedback(u8 in_Type, u8 in_Value, u8 in_CommentNo);
public:
    u8 m_ucType;  // offset: 0x8
    u8 m_ucValue;  // offset: 0x9
    u8 m_ucCommentNo;  // offset: 0xa
    static MyDTI DTI;
};

class CDataPawnHistory : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnHistory();
    explicit CDataPawnHistory(u32, const CCommunityCharacterBaseInfo&, u64, u64, u8, u8, u32, const CPawnFeedback&);
public:
    u32 m_unPawnID;  // offset: 0x8
    CCommunityCharacterBaseInfo m_DebtorBaseInfo;  // offset: 0x10
    u64 m_ullReturnDate;  // offset: 0x40
    u64 m_ullAdventureTime;  // offset: 0x48
    u8 m_ucAdventureCount;  // offset: 0x50
    u8 m_ucCraftCount;  // offset: 0x51
    u32 m_unKillEnemyNum;  // offset: 0x54
    CPawnFeedback m_PawnFeedback;  // offset: 0x58
    static MyDTI DTI;
};

class CDataPawnHp : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnHp();
    explicit CDataPawnHp(u32 in_PawnId, u32 in_Hp);
public:
    u32 m_unPawnId;  // offset: 0x8
    u32 m_unHp;  // offset: 0xc
    static MyDTI DTI;
};

class CDataPawnListData : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnListData();
    explicit CDataPawnListData(u8, u32, u32, const MtTypedArray<CDataPawnCraftSkill>&, u32, u64);
public:
    u8 m_ucJob;  // offset: 0x8
    u32 m_unLevel;  // offset: 0xc
    u32 m_unCraftRank;  // offset: 0x10
    MtTypedArray<CDataPawnCraftSkill> m_PawnCraftSkillList;  // offset: 0x18
    u32 m_unCommentSize;  // offset: 0x38
    u64 m_ullLatestReturnDate;  // offset: 0x40
    static MyDTI DTI;
};

class CDataPawnName : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnName();
    explicit CDataPawnName(const char*);
public:
    MtString m_wstrName;  // offset: 0x8
    static MyDTI DTI;
};

class CDataPawnReaction : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnReaction();
    explicit CDataPawnReaction(u8, u32);
public:
    u8 m_ucReactionType;  // offset: 0x8
    u32 m_unMotionNo;  // offset: 0xc
    static MyDTI DTI;
};

class CDataPawnTotalScore : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnTotalScore();
    explicit CDataPawnTotalScore(u32, u32, u32, const MtTypedArray<CDataPawnFeedback>&);
public:
    u32 m_unRentalCount;  // offset: 0x8
    u32 m_unBattleCount;  // offset: 0xc
    u32 m_unCraftCount;  // offset: 0x10
    MtTypedArray<CDataPawnFeedback> m_AveragePawnFeedbackList;  // offset: 0x18
    static MyDTI DTI;
};

class CDataPawnCraftData : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnCraftData();
    explicit CDataPawnCraftData(u32, u32, u32, u32, const MtTypedArray<CDataPawnCraftSkill>&);
public:
    u32 m_unCraftExp;  // offset: 0x8
    u32 m_unCraftRank;  // offset: 0xc
    u32 m_unCraftRankLimit;  // offset: 0x10
    u32 m_unCraftPoint;  // offset: 0x14
    MtTypedArray<CDataPawnCraftSkill> m_PawnCraftSkillList;  // offset: 0x18
    static MyDTI DTI;
};

class CDataPawnInfo : public CPacketDataBase
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
    explicit CDataPawnInfo();
    explicit CDataPawnInfo(u32, const char*, const CEditInfo&, u8, u32, u32, u8, const MtTypedArray<CDataCharacterJobData>&, const MtTypedArray<CDataCharacterEquipData>&, const MtTypedArray<CDataCharacterEquipData>&, const MtTypedArray<CDataEquipJobItem>&, u8, const CPawnCraftData&, const MtTypedArray<CDataPawnReaction>&, b8, b8, u8, u8, u8, u8, const MtTypedArray<CDataContextNormalSkillData>&, const MtTypedArray<CDataContextAcquirementData>&, const MtTypedArray<CDataContextAcquirementData>&, u32, const COrbGainExtendParam&, u8, u8, u32);
public:
    u32 m_unVersion;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    CEditInfo m_EditInfo;  // offset: 0x18
    u8 m_ucState;  // offset: 0xa0
    u32 m_unMaxHp;  // offset: 0xa4
    u32 m_unMaxStamina;  // offset: 0xa8
    u8 m_ucJob;  // offset: 0xac
    MtTypedArray<CDataCharacterJobData> m_CharacterJobDataList;  // offset: 0xb0
    MtTypedArray<CDataCharacterEquipData> m_CharacterEquipDataList;  // offset: 0xd0
    MtTypedArray<CDataCharacterEquipData> m_CharacterEquipViewDataList;  // offset: 0xf0
    MtTypedArray<CDataEquipJobItem> m_CharacterEquipJobItemList;  // offset: 0x110
    u8 m_ucJewelrySlotNum;  // offset: 0x130
    CPawnCraftData m_CraftData;  // offset: 0x138
    MtTypedArray<CDataPawnReaction> m_PawnReactionList;  // offset: 0x170
    b8 m_bHideEquipHead;  // offset: 0x190
    b8 m_bHideEquipLantern;  // offset: 0x191
    u8 m_ucAdventureCount;  // offset: 0x192
    u8 m_ucCraftCount;  // offset: 0x193
    u8 m_ucMaxAdventureCount;  // offset: 0x194
    u8 m_ucMaxCraftCount;  // offset: 0x195
    MtTypedArray<CDataContextNormalSkillData> m_ContextNormalSkillList;  // offset: 0x198
    MtTypedArray<CDataContextAcquirementData> m_ContextSkillList;  // offset: 0x1b8
    MtTypedArray<CDataContextAcquirementData> m_ContextAbilityList;  // offset: 0x1d8
    u32 m_unAbilityCostMax;  // offset: 0x1f8
    COrbGainExtendParam m_ExtendParam;  // offset: 0x200
    u8 m_ucPawnType;  // offset: 0x228
    u8 m_ucShareRange;  // offset: 0x229
    u32 m_unLikability;  // offset: 0x22c
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPartnerPawnData::CDataPartnerPawnData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unPawnId = static_cast<u32>(0);
    this->m_unLikability = static_cast<u32>(0);
    this->m_ucPersonality = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPawnCraftSkill::CDataPawnCraftSkill() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucType = static_cast<u8>(0);
    this->m_unLevel = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPawnFeedback::CDataPawnFeedback() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucType = static_cast<u8>(0);
    this->m_ucValue = static_cast<u8>(0);
    this->m_ucCommentNo = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPawnHp::CDataPawnHp() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unPawnId = static_cast<u32>(0);
    this->m_unHp = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPawnListData::CDataPawnListData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucJob = static_cast<u8>(0);
    this->m_unLevel = static_cast<u32>(0);
    this->m_unCraftRank = static_cast<u32>(0);
    this->m_unCommentSize = static_cast<u32>(0);
    this->m_ullLatestReturnDate = static_cast<u64>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPawnName::CDataPawnName() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPawnReaction::CDataPawnReaction() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucReactionType = static_cast<u8>(0);
    this->m_unMotionNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPawnTotalScore::CDataPawnTotalScore() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unRentalCount = static_cast<u32>(0);
    this->m_unBattleCount = static_cast<u32>(0);
    this->m_unCraftCount = static_cast<u32>(0);
}
