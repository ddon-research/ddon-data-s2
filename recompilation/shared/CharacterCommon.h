#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Achievement.h"
#include "Item.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "cPacket.h"

// Forward declarations
class CDataAchievementIdentifier;
class CDataEquipItemInfo;
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataArisenProfile;
class CDataCharacterEquipData;
class CDataCharacterJobData;
class CDataContextAcquirementData;
class CDataContextNormalSkillData;
class CDataOrbCategoryStatus;
class CDataOrbGainExtendParam;
class CDataOrbPageStatus;
class CDataReleaseOrbElement;
class CDataStatusInfo;

// Type aliases from DWARF
using CAchievementIdentifier = CDataAchievementIdentifier;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using OrbCategoryStatusVec = MtTypedArray<CDataOrbCategoryStatus>;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataArisenProfile : public CPacketDataBase
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
    explicit CDataArisenProfile();
    explicit CDataArisenProfile(u8, const CAchievementIdentifier&, u16, u32);
public:
    u8 m_ucBackgroundID;  // offset: 0x8
    CAchievementIdentifier m_Title;  // offset: 0x10
    u16 m_usMotionID;  // offset: 0x20
    u32 m_unMotionFrameNo;  // offset: 0x24
    static MyDTI DTI;
};

class CDataCharacterEquipData : public CPacketDataBase
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
    explicit CDataCharacterEquipData();
    explicit CDataCharacterEquipData(const MtTypedArray<CDataEquipItemInfo>&);
public:
    MtTypedArray<CDataEquipItemInfo> m_EquipList;  // offset: 0x8
    static MyDTI DTI;
};

class CDataCharacterJobData : public CPacketDataBase
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
    explicit CDataCharacterJobData();
    explicit CDataCharacterJobData(u8, u32, u32, u32, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);
public:
    u8 m_ucJob;  // offset: 0x8
    u32 m_unExp;  // offset: 0xc
    u32 m_unJobPoint;  // offset: 0x10
    u32 m_unLv;  // offset: 0x14
    u16 m_usAtk;  // offset: 0x18
    u16 m_usDef;  // offset: 0x1a
    u16 m_usMAtk;  // offset: 0x1c
    u16 m_usMDef;  // offset: 0x1e
    u16 m_usStrength;  // offset: 0x20
    u16 m_usDownPower;  // offset: 0x22
    u16 m_usShakePower;  // offset: 0x24
    u16 m_usStunPower;  // offset: 0x26
    u16 m_usConstitution;  // offset: 0x28
    u16 m_usGuts;  // offset: 0x2a
    u8 m_ucFireResist;  // offset: 0x2c
    u8 m_ucIceResist;  // offset: 0x2d
    u8 m_ucThunderResist;  // offset: 0x2e
    u8 m_ucHolyResist;  // offset: 0x2f
    u8 m_ucDarkResist;  // offset: 0x30
    u8 m_ucSpreadResist;  // offset: 0x31
    u8 m_ucFreezeResist;  // offset: 0x32
    u8 m_ucShockResist;  // offset: 0x33
    u8 m_ucAbsorbResist;  // offset: 0x34
    u8 m_ucDarkElmResist;  // offset: 0x35
    u8 m_ucPoisonResist;  // offset: 0x36
    u8 m_ucSlowResist;  // offset: 0x37
    u8 m_ucSleepResist;  // offset: 0x38
    u8 m_ucStunResist;  // offset: 0x39
    u8 m_ucWetResist;  // offset: 0x3a
    u8 m_ucOilResist;  // offset: 0x3b
    u8 m_ucSealResist;  // offset: 0x3c
    u8 m_ucCurseResist;  // offset: 0x3d
    u8 m_ucSoftResist;  // offset: 0x3e
    u8 m_ucStoneResist;  // offset: 0x3f
    u8 m_ucGoldResist;  // offset: 0x40
    u8 m_ucFireReduceResist;  // offset: 0x41
    u8 m_ucIceReduceResist;  // offset: 0x42
    u8 m_ucThunderReduceResist;  // offset: 0x43
    u8 m_ucHolyReduceResist;  // offset: 0x44
    u8 m_ucDarkReduceResist;  // offset: 0x45
    u8 m_ucAtkDownResist;  // offset: 0x46
    u8 m_ucDefDownResist;  // offset: 0x47
    u8 m_ucMAtkDownResist;  // offset: 0x48
    u8 m_ucMDefDownResist;  // offset: 0x49
    static MyDTI DTI;
};

class CDataContextAcquirementData : public CPacketDataBase
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
    explicit CDataContextAcquirementData();
    explicit CDataContextAcquirementData(u8, u32, u8);
public:
    u8 m_ucSlotNo;  // offset: 0x8
    u32 m_unAcquirementNo;  // offset: 0xc
    u8 m_ucAcquirementLv;  // offset: 0x10
    static MyDTI DTI;
};

class CDataContextNormalSkillData : public CPacketDataBase
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
    explicit CDataContextNormalSkillData();
    explicit CDataContextNormalSkillData(u8);
public:
    u8 m_ucSkillNo;  // offset: 0x8
    static MyDTI DTI;
};

class CDataOrbCategoryStatus : public CPacketDataBase
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
    explicit CDataOrbCategoryStatus();
    explicit CDataOrbCategoryStatus(u8, u8);
public:
    u8 m_ucCategoryID;  // offset: 0x8
    u8 m_ucReleaseNum;  // offset: 0x9
    static MyDTI DTI;
};

class CDataOrbGainExtendParam : public CPacketDataBase
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
    explicit CDataOrbGainExtendParam();
    explicit CDataOrbGainExtendParam(u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16);
public:
    u16 m_usHpMax;  // offset: 0x8
    u16 m_usStaminaMax;  // offset: 0xa
    u16 m_usAttack;  // offset: 0xc
    u16 m_usDefence;  // offset: 0xe
    u16 m_usMagicAttack;  // offset: 0x10
    u16 m_usMagicDefence;  // offset: 0x12
    u16 m_usAbilityCost;  // offset: 0x14
    u16 m_usJewerlySlot;  // offset: 0x16
    u16 m_usUseItemSlot;  // offset: 0x18
    u16 m_usMaterialItemSlot;  // offset: 0x1a
    u16 m_usEquipItemSlot;  // offset: 0x1c
    u16 m_usMainPawnSlot;  // offset: 0x1e
    u16 m_usSupportPawnSlot;  // offset: 0x20
    static MyDTI DTI;
};

class CDataOrbPageStatus : public CPacketDataBase
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
    explicit CDataOrbPageStatus();
    explicit CDataOrbPageStatus(u8, const OrbCategoryStatusVec&);
public:
    u8 m_ucPageNo;  // offset: 0x8
    OrbCategoryStatusVec m_CategoryStatusList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataReleaseOrbElement : public CPacketDataBase
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
    explicit CDataReleaseOrbElement();
    explicit CDataReleaseOrbElement(u32, u8, u8, u8);
public:
    u32 m_unElementID;  // offset: 0x8
    u8 m_ucPageNo;  // offset: 0xc
    u8 m_ucGroupNo;  // offset: 0xd
    u8 m_ucIndex;  // offset: 0xe
    static MyDTI DTI;
};

class CDataStatusInfo : public CPacketDataBase
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
    explicit CDataStatusInfo();
    explicit CDataStatusInfo(u32 in_Hp, u32 in_Stamina, u8 in_RevivePoint, u32 in_MaxHp, u32 in_MaxStamina, u32 in_WhiteHp, u32 in_GainHp, u32 in_GainStamina, u32 in_GainAttack, u32 in_GainDefense, u32 in_GainMagicAttack, u32 in_GainMagicDefense);
public:
    u32 m_unHp;  // offset: 0x8
    u32 m_unStamina;  // offset: 0xc
    u8 m_ucRevivePoint;  // offset: 0x10
    u32 m_unMaxHp;  // offset: 0x14
    u32 m_unMaxStamina;  // offset: 0x18
    u32 m_unWhiteHp;  // offset: 0x1c
    u32 m_unGainHp;  // offset: 0x20
    u32 m_unGainStamina;  // offset: 0x24
    u32 m_unGainAttack;  // offset: 0x28
    u32 m_unGainDefense;  // offset: 0x2c
    u32 m_unGainMagicAttack;  // offset: 0x30
    u32 m_unGainMagicDefense;  // offset: 0x34
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataArisenProfile::CDataArisenProfile() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucBackgroundID = static_cast<u8>(0);
    this->m_usMotionID = static_cast<u16>(0);
    this->m_unMotionFrameNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataCharacterEquipData::CDataCharacterEquipData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataCharacterJobData::CDataCharacterJobData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucJob = static_cast<u8>(0);
    this->m_ucMAtkDownResist = static_cast<u8>(0);
    this->m_ucMDefDownResist = static_cast<u8>(0);
    this->m_ucHolyReduceResist = static_cast<u8>(0);
    this->m_ucDarkReduceResist = static_cast<u8>(0);
    this->m_ucAtkDownResist = static_cast<u8>(0);
    this->m_ucDefDownResist = static_cast<u8>(0);
    this->m_ucSealResist = static_cast<u8>(0);
    this->m_ucCurseResist = static_cast<u8>(0);
    this->m_ucSoftResist = static_cast<u8>(0);
    this->m_ucStoneResist = static_cast<u8>(0);
    this->m_ucGoldResist = static_cast<u8>(0);
    this->m_ucFireReduceResist = static_cast<u8>(0);
    this->m_ucIceReduceResist = static_cast<u8>(0);
    this->m_ucThunderReduceResist = static_cast<u8>(0);
    this->m_ucAbsorbResist = static_cast<u8>(0);
    this->m_ucDarkElmResist = static_cast<u8>(0);
    this->m_ucPoisonResist = static_cast<u8>(0);
    this->m_ucSlowResist = static_cast<u8>(0);
    this->m_ucSleepResist = static_cast<u8>(0);
    this->m_ucStunResist = static_cast<u8>(0);
    this->m_ucWetResist = static_cast<u8>(0);
    this->m_ucOilResist = static_cast<u8>(0);
    this->m_ucFireResist = static_cast<u8>(0);
    this->m_ucIceResist = static_cast<u8>(0);
    this->m_ucThunderResist = static_cast<u8>(0);
    this->m_ucHolyResist = static_cast<u8>(0);
    this->m_ucDarkResist = static_cast<u8>(0);
    this->m_ucSpreadResist = static_cast<u8>(0);
    this->m_ucFreezeResist = static_cast<u8>(0);
    this->m_ucShockResist = static_cast<u8>(0);
    this->m_usShakePower = static_cast<u16>(0);
    this->m_usStunPower = static_cast<u16>(0);
    this->m_usConstitution = static_cast<u16>(0);
    this->m_usGuts = static_cast<u16>(0);
    this->m_usMAtk = static_cast<u16>(0);
    this->m_usMDef = static_cast<u16>(0);
    this->m_usStrength = static_cast<u16>(0);
    this->m_usDownPower = static_cast<u16>(0);
    this->m_unLv = static_cast<u32>(0);
    this->m_usAtk = static_cast<u16>(0);
    this->m_usDef = static_cast<u16>(0);
    this->m_unExp = static_cast<u32>(0);
    this->m_unJobPoint = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataContextAcquirementData::CDataContextAcquirementData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucSlotNo = static_cast<u8>(0);
    this->m_unAcquirementNo = static_cast<u32>(0);
    this->m_ucAcquirementLv = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataContextNormalSkillData::CDataContextNormalSkillData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucSkillNo = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataOrbCategoryStatus::CDataOrbCategoryStatus() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucCategoryID = static_cast<u8>(0);
    this->m_ucReleaseNum = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataOrbGainExtendParam::CDataOrbGainExtendParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_usSupportPawnSlot = static_cast<u16>(0);
    this->m_usUseItemSlot = static_cast<u16>(0);
    this->m_usMaterialItemSlot = static_cast<u16>(0);
    this->m_usEquipItemSlot = static_cast<u16>(0);
    this->m_usMainPawnSlot = static_cast<u16>(0);
    this->m_usMagicAttack = static_cast<u16>(0);
    this->m_usMagicDefence = static_cast<u16>(0);
    this->m_usAbilityCost = static_cast<u16>(0);
    this->m_usJewerlySlot = static_cast<u16>(0);
    this->m_usHpMax = static_cast<u16>(0);
    this->m_usStaminaMax = static_cast<u16>(0);
    this->m_usAttack = static_cast<u16>(0);
    this->m_usDefence = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataOrbPageStatus::CDataOrbPageStatus() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucPageNo = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataReleaseOrbElement::CDataReleaseOrbElement() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucIndex = static_cast<u8>(0);
    this->m_ucPageNo = static_cast<u8>(0);
    this->m_ucGroupNo = static_cast<u8>(0);
    this->m_unElementID = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataStatusInfo::CDataStatusInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unHp = static_cast<u32>(0);
    this->m_unStamina = static_cast<u32>(0);
    this->m_ucRevivePoint = static_cast<u8>(0);
    this->m_unGainMagicDefense = static_cast<u32>(0);
    this->m_unGainDefense = static_cast<u32>(0);
    this->m_unGainMagicAttack = static_cast<u32>(0);
    this->m_unGainStamina = static_cast<u32>(0);
    this->m_unGainAttack = static_cast<u32>(0);
    this->m_unWhiteHp = static_cast<u32>(0);
    this->m_unGainHp = static_cast<u32>(0);
    this->m_unMaxHp = static_cast<u32>(0);
    this->m_unMaxStamina = static_cast<u32>(0);
}
