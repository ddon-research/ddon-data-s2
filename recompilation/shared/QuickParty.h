#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataQuickPartyMatching;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u32 = unsigned int;

class CDataQuickPartyMatching : public CPacketDataBase
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
    explicit CDataQuickPartyMatching();
    explicit CDataQuickPartyMatching(u32, u32, b8, b8, b8);
public:
    u32 m_unParam1;  // offset: 0x8
    u32 m_unParam2;  // offset: 0xc
    b8 m_bIsJobBalance;  // offset: 0x10
    b8 m_bIsLevelBalance;  // offset: 0x11
    b8 m_bIsLeader;  // offset: 0x12
    static MyDTI DTI;
};
