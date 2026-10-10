#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataAbilityLevelParam;
class CDataAbilityParam;
class CDataLearnedAcquirementParam;
class CDataNormalSkillParam;
class CDataPresetAbilityParam;
class CDataReleaseAcquirementParam;
class CDataSetAcquirementParam;
class CDataSkillLevelParam;
class CDataSkillParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SetAcquirementParamVec = MtTypedArray<CDataSetAcquirementParam>;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataAbilityLevelParam : public CPacketDataBase
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
    explicit CDataAbilityLevelParam();
    explicit CDataAbilityLevelParam(u8, u32, u32, b8);
public:
    u8 m_ucLv;  // offset: 0x8
    u32 m_unRequireJobLevel;  // offset: 0xc
    u32 m_unRequireJobPoint;  // offset: 0x10
    b8 m_bIsRelease;  // offset: 0x14
    static MyDTI DTI;
};

class CDataAbilityParam : public CPacketDataBase
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
    explicit CDataAbilityParam();
    explicit CDataAbilityParam(u32, u8, u8, u8, u8, u32, const MtTypedArray<CDataAbilityLevelParam>&);
public:
    u32 m_unAbilityNo;  // offset: 0x8
    u8 m_ucJob;  // offset: 0xc
    u8 m_ucCategory;  // offset: 0xd
    u8 m_ucSortCategory;  // offset: 0xe
    u8 m_ucType;  // offset: 0xf
    u32 m_unCost;  // offset: 0x10
    MtTypedArray<CDataAbilityLevelParam> m_Param;  // offset: 0x18
    static MyDTI DTI;
};

class CDataLearnedAcquirementParam : public CPacketDataBase
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
    explicit CDataLearnedAcquirementParam();
    explicit CDataLearnedAcquirementParam(u8, u8, u32, u8, u32);
public:
    u8 m_ucJob;  // offset: 0x8
    u8 m_ucType;  // offset: 0x9
    u32 m_unAcquirementNo;  // offset: 0xc
    u8 m_ucAcquirementLv;  // offset: 0x10
    u32 m_unAcquirementParamID;  // offset: 0x14
    static MyDTI DTI;
};

class CDataNormalSkillParam : public CPacketDataBase
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
    explicit CDataNormalSkillParam();
    explicit CDataNormalSkillParam(u8, u32, u32, u32);
public:
    u8 m_ucJob;  // offset: 0x8
    u32 m_unSkillNo;  // offset: 0xc
    u32 m_unIndex;  // offset: 0x10
    u32 m_unPreSkillNo;  // offset: 0x14
    static MyDTI DTI;
};

class CDataReleaseAcquirementParam : public CPacketDataBase
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
    explicit CDataReleaseAcquirementParam();
    explicit CDataReleaseAcquirementParam(u8, u8, u32, u8, u32);
public:
    u8 m_ucJob;  // offset: 0x8
    u8 m_ucType;  // offset: 0x9
    u32 m_unAcquirementNo;  // offset: 0xc
    u8 m_ucAcquirementLv;  // offset: 0x10
    u32 m_unAcquirementParamID;  // offset: 0x14
    static MyDTI DTI;
};

class CDataSetAcquirementParam : public CPacketDataBase
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
    explicit CDataSetAcquirementParam();
    explicit CDataSetAcquirementParam(u8, u8, u8, u32, u8);
public:
    u8 m_ucJob;  // offset: 0x8
    u8 m_ucType;  // offset: 0x9
    u8 m_ucSlotNo;  // offset: 0xa
    u32 m_unAcquirementNo;  // offset: 0xc
    u8 m_ucAcquirementLv;  // offset: 0x10
    static MyDTI DTI;
};

class CDataSkillLevelParam : public CPacketDataBase
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
    explicit CDataSkillLevelParam();
    explicit CDataSkillLevelParam(u8, u32, u32, b8);
public:
    u8 m_ucLv;  // offset: 0x8
    u32 m_unRequireJobLevel;  // offset: 0xc
    u32 m_unRequireJobPoint;  // offset: 0x10
    b8 m_bIsRelease;  // offset: 0x14
    static MyDTI DTI;
};

class CDataSkillParam : public CPacketDataBase
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
    explicit CDataSkillParam();
    explicit CDataSkillParam(u32, u8, u8, const MtTypedArray<CDataSkillLevelParam>&);
public:
    u32 m_unSkillNo;  // offset: 0x8
    u8 m_ucJob;  // offset: 0xc
    u8 m_ucType;  // offset: 0xd
    MtTypedArray<CDataSkillLevelParam> m_Param;  // offset: 0x10
    static MyDTI DTI;
};

class CDataPresetAbilityParam : public CPacketDataBase
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
    explicit CDataPresetAbilityParam();
    explicit CDataPresetAbilityParam(u8, const char*, const SetAcquirementParamVec&);
public:
    u8 m_ucPresetNo;  // offset: 0x8
    MtString m_wstrPresetName;  // offset: 0x10
    SetAcquirementParamVec m_AbilityList;  // offset: 0x18
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataAbilityLevelParam::CDataAbilityLevelParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucLv = static_cast<u8>(0);
    this->m_unRequireJobLevel = static_cast<u32>(0);
    this->m_unRequireJobPoint = static_cast<u32>(0);
    this->m_bIsRelease = false;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataLearnedAcquirementParam::CDataLearnedAcquirementParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucJob = static_cast<u8>(0);
    this->m_ucType = static_cast<u8>(0);
    this->m_unAcquirementNo = static_cast<u32>(0);
    this->m_ucAcquirementLv = static_cast<u8>(0);
    this->m_unAcquirementParamID = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataNormalSkillParam::CDataNormalSkillParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucJob = static_cast<u8>(0);
    this->m_unSkillNo = static_cast<u32>(0);
    this->m_unIndex = static_cast<u32>(0);
    this->m_unPreSkillNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPresetAbilityParam::CDataPresetAbilityParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucPresetNo = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataReleaseAcquirementParam::CDataReleaseAcquirementParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucJob = static_cast<u8>(0);
    this->m_ucType = static_cast<u8>(0);
    this->m_unAcquirementNo = static_cast<u32>(0);
    this->m_ucAcquirementLv = static_cast<u8>(0);
    this->m_unAcquirementParamID = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataSetAcquirementParam::CDataSetAcquirementParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucJob = static_cast<u8>(0);
    this->m_ucType = static_cast<u8>(0);
    this->m_ucSlotNo = static_cast<u8>(0);
    this->m_unAcquirementNo = static_cast<u32>(0);
    this->m_ucAcquirementLv = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataSkillLevelParam::CDataSkillLevelParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucLv = static_cast<u8>(0);
    this->m_unRequireJobLevel = static_cast<u32>(0);
    this->m_unRequireJobPoint = static_cast<u32>(0);
    this->m_bIsRelease = false;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataSkillParam::CDataSkillParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unSkillNo = static_cast<u32>(0);
    this->m_ucJob = static_cast<u8>(0);
    this->m_ucType = static_cast<u8>(0);
}
