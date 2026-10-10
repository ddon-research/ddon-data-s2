#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Community.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "cPacket.h"

// Forward declarations
class CDataCharacterListElement;
class CDataCommunityCharacterBaseInfo;
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataPartyListInfo;
class CDataPartyMember;
class CDataPartyMemberMaxNum;
class CDataPartyMemberMinimum;

namespace nParty {
    enum E_JOIN_STATE
    {
        JOIN_STATE_NONE = 0,
        JOIN_STATE_PREPARE = 1,
        JOIN_STATE_ON = 2,
    };
}  // namespace nParty

// Type aliases from DWARF
using CCharacterListElement = CDataCharacterListElement;
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using b8 = bool;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class CDataPartyMember : public CPacketDataBase
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
    explicit CDataPartyMember();
    explicit CDataPartyMember(const CCharacterListElement&, u8, s32, u32, b8, b8, b8, u8, u8);
public:
    CCharacterListElement m_CharacterListElement;  // offset: 0x8
    u8 m_ucMemberType;  // offset: 0x70
    s32 m_nMemberIndex;  // offset: 0x74
    u32 m_unPawnId;  // offset: 0x78
    b8 m_bIsLeader;  // offset: 0x7c
    b8 m_bIsPawn;  // offset: 0x7d
    b8 m_bIsPlayEntry;  // offset: 0x7e
    u8 m_ucJoinState;  // offset: 0x7f
    u8 m_ucAnyValueList[8];  // offset: 0x80
    u8 m_ucSessionStatus;  // offset: 0x88
    static MyDTI DTI;
};

class CDataPartyMemberMaxNum : public CPacketDataBase
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
    explicit CDataPartyMemberMaxNum();
    explicit CDataPartyMemberMaxNum(u32, u32);
public:
    u32 m_unContentType;  // offset: 0x8
    u32 m_unNum;  // offset: 0xc
    static MyDTI DTI;
};

class CDataPartyMemberMinimum : public CPacketDataBase
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
    explicit CDataPartyMemberMinimum();
    explicit CDataPartyMemberMinimum(const CCommunityCharacterBaseInfo& in_CommunityCharacterBaseInfo, u8 in_MemberType, s32 in_MemberIndex, u32 in_PawnId, b8 in_IsLeader, b8 in_IsPawn);
public:
    CCommunityCharacterBaseInfo m_CommunityCharacterBaseInfo;  // offset: 0x8
    u8 m_ucMemberType;  // offset: 0x38
    s32 m_nMemberIndex;  // offset: 0x3c
    u32 m_unPawnId;  // offset: 0x40
    b8 m_bIsLeader;  // offset: 0x44
    b8 m_bIsPawn;  // offset: 0x45
    static MyDTI DTI;
};

class CDataPartyListInfo : public CPacketDataBase
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
    explicit CDataPartyListInfo();
    explicit CDataPartyListInfo(u32, u32, const MtTypedArray<CDataPartyMember>&, u32, u64);
public:
    u32 m_unServerId;  // offset: 0x8
    u32 m_unPartyId;  // offset: 0xc
    MtTypedArray<CDataPartyMember> m_MemberList;  // offset: 0x10
    u32 m_unSequence;  // offset: 0x30
    u64 m_ullContentNumber;  // offset: 0x38
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPartyListInfo::CDataPartyListInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unServerId = static_cast<u32>(0);
    this->m_unPartyId = static_cast<u32>(0);
    this->m_unSequence = static_cast<u32>(0);
    this->m_ullContentNumber = static_cast<u64>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataPartyMemberMaxNum::CDataPartyMemberMaxNum() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unContentType = static_cast<u32>(0);
    this->m_unNum = static_cast<u32>(0);
}
