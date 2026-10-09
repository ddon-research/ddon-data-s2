#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Common.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "cPacket.h"

// Forward declarations
class CDataCommonU32;
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataJobOrbDevoteElement;
class CDataJobOrbTreeStatus;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataJobOrbDevoteElement : public CPacketDataBase
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
    explicit CDataJobOrbDevoteElement();
    explicit CDataJobOrbDevoteElement(u32, u8, u32, u8, u32, u32, u32, u32, b8, const MtTypedArray<CDataCommonU32>&, const MtTypedArray<CDataCommonU32>&);
public:
    u32 m_unElementID;  // offset: 0x8
    u8 m_ucJobID;  // offset: 0xc
    u32 m_unRequireOrb;  // offset: 0x10
    u8 m_ucOrbRewardType;  // offset: 0x14
    u32 m_unParamID;  // offset: 0x18
    u32 m_unParamValue;  // offset: 0x1c
    u32 m_unPosX;  // offset: 0x20
    u32 m_unPosY;  // offset: 0x24
    b8 m_bIsReleased;  // offset: 0x28
    MtTypedArray<CDataCommonU32> m_RequireElementIDList;  // offset: 0x30
    MtTypedArray<CDataCommonU32> m_RequireQuestList;  // offset: 0x50
    static MyDTI DTI;
};

class CDataJobOrbTreeStatus : public CPacketDataBase
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
    explicit CDataJobOrbTreeStatus();
    explicit CDataJobOrbTreeStatus(u8, b8, f32);
public:
    u8 m_ucJobID;  // offset: 0x8
    b8 m_bIsReleased;  // offset: 0x9
    f32 m_fRate;  // offset: 0xc
    static MyDTI DTI;
};
