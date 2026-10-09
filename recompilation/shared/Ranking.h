#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Community.h"
#include "MtDTI.h"
#include "cPacket.h"

// Forward declarations
class CDataCommunityCharacterBaseInfo;
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataRankingBoard;
class CDataRankingData;

// Type aliases from DWARF
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataRankingBoard : public CPacketDataBase
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
    explicit CDataRankingBoard();
    explicit CDataRankingBoard(u32, u32, u8, u32, s64, s64, s64, s64);
public:
    u32 m_unId;  // offset: 0x8
    u32 m_unQuestId;  // offset: 0xc
    u8 m_ucState;  // offset: 0x10
    u32 m_unRegisterdNum;  // offset: 0x14
    s64 m_llBegin;  // offset: 0x18
    s64 m_llEnd;  // offset: 0x20
    s64 m_llExpire;  // offset: 0x28
    s64 m_llModified;  // offset: 0x30
    static MyDTI DTI;
};

class CDataRankingData : public CPacketDataBase
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
    explicit CDataRankingData();
    explicit CDataRankingData(u32, u32, s64, const CCommunityCharacterBaseInfo&);
public:
    u32 m_unRank;  // offset: 0x8
    u32 m_unSerial;  // offset: 0xc
    s64 m_llScore;  // offset: 0x10
    CCommunityCharacterBaseInfo m_CommunityCharacterBaseInfo;  // offset: 0x18
    static MyDTI DTI;
};
