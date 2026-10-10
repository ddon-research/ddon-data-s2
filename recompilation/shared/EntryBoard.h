#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Common.h"
#include "Community.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataCharacterListElement;
class CDataCommonU8;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataEntryBoardItemSearchParameter;
class CDataEntryItem;
class CDataEntryItemParam;
class CDataEntryMemberData;
class CDataEntryRecruitData;
class CDataEntryRecruitJob;

// Type aliases from DWARF
using CCharacterListElement = CDataCharacterListElement;
using CEntryItemParam = CDataEntryItemParam;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataEntryBoardItemSearchParameter : public CPacketDataBase
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
    explicit CDataEntryBoardItemSearchParameter();
    explicit CDataEntryBoardItemSearchParameter(const MtTypedArray<CDataCommonU8>&, const char*, const char*, b8, u32, u32, u32, b8, u32, u32);
public:
    MtTypedArray<CDataCommonU8> m_SearchGroups;  // offset: 0x8
    MtString m_wstrFirstName;  // offset: 0x28
    MtString m_wstrLastName;  // offset: 0x30
    b8 m_bRankSetting;  // offset: 0x38
    u32 m_unRankMin;  // offset: 0x3c
    u32 m_unRankMax;  // offset: 0x40
    u32 m_unJob;  // offset: 0x44
    b8 m_bIsNoPassword;  // offset: 0x48
    u32 m_unRequiredItemRankMin;  // offset: 0x4c
    u32 m_unRequiredItemRankMax;  // offset: 0x50
    static MyDTI DTI;
};

class CDataEntryMemberData : public CPacketDataBase
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
    explicit CDataEntryMemberData();
    explicit CDataEntryMemberData(u16, b8, const CCharacterListElement&);
public:
    u16 m_usID;  // offset: 0x8
    b8 m_bIsReady;  // offset: 0xa
    CCharacterListElement m_CharacterListElement;  // offset: 0x10
    static MyDTI DTI;
};

class CDataEntryRecruitJob : public CPacketDataBase
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
    explicit CDataEntryRecruitJob();
    explicit CDataEntryRecruitJob(u8);
public:
    u8 m_ucjob;  // offset: 0x8
    static MyDTI DTI;
};

class CDataEntryRecruitData : public CPacketDataBase
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
    explicit CDataEntryRecruitData();
    explicit CDataEntryRecruitData(u16, const MtTypedArray<CDataEntryRecruitJob>&);
public:
    u16 m_usID;  // offset: 0x8
    MtTypedArray<CDataEntryRecruitJob> m_EnableJobList;  // offset: 0x10
    static MyDTI DTI;
};

class CDataEntryItemParam : public CPacketDataBase
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
    explicit CDataEntryItemParam();
    explicit CDataEntryItemParam(b8, b8, s32, s32, u16, u8, u32, u16, u16, const char*, const MtTypedArray<CDataEntryRecruitData>&);
public:
    b8 m_bPasswordOn;  // offset: 0x8
    b8 m_bPawnOn;  // offset: 0x9
    s32 m_nBottomEntryJobLevel;  // offset: 0xc
    s32 m_nTopEntryJobLevel;  // offset: 0x10
    u16 m_usRequiredItemRank;  // offset: 0x14
    u8 m_ucItemRankType;  // offset: 0x16
    u32 m_unItemRankCheckRoleType;  // offset: 0x18
    u16 m_usMinEntryNum;  // offset: 0x1c
    u16 m_usMaxEntryNum;  // offset: 0x1e
    MtString m_wstrComment;  // offset: 0x20
    MtTypedArray<CDataEntryRecruitData> m_EntryRecruitList;  // offset: 0x28
    static MyDTI DTI;
};

class CDataEntryItem : public CPacketDataBase
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
    explicit CDataEntryItem();
    explicit CDataEntryItem(u32, const CEntryItemParam&, const MtTypedArray<CDataEntryMemberData>&, u16, u16, u32);
public:
    u32 m_unID;  // offset: 0x8
    CEntryItemParam m_Param;  // offset: 0x10
    MtTypedArray<CDataEntryMemberData> m_EntryMemberList;  // offset: 0x58
    u16 m_usBoardRequiredAvgItemRank;  // offset: 0x78
    u16 m_usTimeOut;  // offset: 0x7a
    u32 m_unLeaderPartyId;  // offset: 0x7c
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataEntryRecruitData::CDataEntryRecruitData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_usID = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataEntryRecruitJob::CDataEntryRecruitJob() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucjob = static_cast<u8>(0);
}
