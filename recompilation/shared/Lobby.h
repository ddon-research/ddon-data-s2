#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Community.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataCommunityCharacterBaseInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataLobbyInfo;
class CDataLobbyMemberInfo;

// Type aliases from DWARF
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataLobbyInfo : public CPacketDataBase
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
    explicit CDataLobbyInfo();
    explicit CDataLobbyInfo(const char*, u32, u32, u32);
public:
    MtString m_wstrName;  // offset: 0x8
    u32 m_unMaxJoinNum;  // offset: 0x10
    u32 m_unJoinNum;  // offset: 0x14
    u32 m_unVersion;  // offset: 0x18
    static MyDTI DTI;
};

class CDataLobbyMemberInfo : public CPacketDataBase
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
    explicit CDataLobbyMemberInfo();
    explicit CDataLobbyMemberInfo(const CCommunityCharacterBaseInfo&, u32, u8, u8, u8, u8);
public:
    CCommunityCharacterBaseInfo m_CommunityCharacterBaseInfo;  // offset: 0x8
    u32 m_unPawnId;  // offset: 0x38
    u8 m_ucPlatform;  // offset: 0x3c
    u8 m_ucClientVersion;  // offset: 0x3d
    u8 m_ucSessionStatus;  // offset: 0x3e
    u8 m_ucOnlineStatus;  // offset: 0x3f
    static MyDTI DTI;
};
