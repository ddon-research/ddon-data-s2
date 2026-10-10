#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataCharacterListElement;
class CDataCharacterName;
class CDataCommunityCharacterBaseInfo;
class CDataFriendInfo;
class CDataJobBaseInfo;

// Type aliases from DWARF
using CCharacterListElement = CDataCharacterListElement;
using CCharacterName = CDataCharacterName;
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CJobBaseInfo = CDataJobBaseInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataCharacterName : public CPacketDataBase
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
    explicit CDataCharacterName();
    explicit CDataCharacterName(const char* in_strFirstName, const char* in_strLastName);
public:
    MtString m_wstrFirstName;  // offset: 0x8
    MtString m_wstrLastName;  // offset: 0x10
    static MyDTI DTI;
};

class CDataCommunityCharacterBaseInfo : public CPacketDataBase
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
    explicit CDataCommunityCharacterBaseInfo();
    explicit CDataCommunityCharacterBaseInfo(u32, const CCharacterName&, const char*);
public:
    u32 m_unCharacterID;  // offset: 0x8
    CCharacterName m_CharacterName;  // offset: 0x10
    MtString m_wstrClanName;  // offset: 0x28
    static MyDTI DTI;
};

class CDataJobBaseInfo : public CPacketDataBase
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
    explicit CDataJobBaseInfo();
    explicit CDataJobBaseInfo(u8, u8);
public:
    u8 m_ucJob;  // offset: 0x8
    u8 m_ucLv;  // offset: 0x9
    static MyDTI DTI;
};

class CDataCharacterListElement : public CPacketDataBase
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
    explicit CDataCharacterListElement();
    explicit CDataCharacterListElement(const CCommunityCharacterBaseInfo&, u16, u8, const CJobBaseInfo&, const CJobBaseInfo&, const char*);
public:
    CCommunityCharacterBaseInfo m_BaseInfo;  // offset: 0x8
    u16 m_usServerID;  // offset: 0x38
    u8 m_ucOnlineStatus;  // offset: 0x3a
    CJobBaseInfo m_CurrentJobInfo;  // offset: 0x40
    CJobBaseInfo m_EntryJobInfo;  // offset: 0x50
    MtString m_wstrMatchingPlofile;  // offset: 0x60
    static MyDTI DTI;
};

class CDataFriendInfo : public CPacketDataBase
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
    explicit CDataFriendInfo();
    explicit CDataFriendInfo(const CCharacterListElement&, u8, u32, b8);
public:
    CCharacterListElement m_CharacterListElement;  // offset: 0x8
    u8 m_ucPendingStatus;  // offset: 0x70
    u32 m_unFriendNo;  // offset: 0x74
    b8 m_bFavorite;  // offset: 0x78
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataJobBaseInfo::CDataJobBaseInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ucJob = static_cast<u8>(0);
    this->m_ucLv = static_cast<u8>(0);
}
