#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../MT/MtDTI.h"
#include "../../cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataCheatInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataCheatInfo : public CPacketDataBase
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
    explicit CDataCheatInfo();
    explicit CDataCheatInfo(u8, u8, u32, u32, u32);
public:
    u8 m_ucId;  // offset: 0x8
    u8 m_ucCount;  // offset: 0x9
    u32 m_unParam1;  // offset: 0xc
    u32 m_unParam2;  // offset: 0x10
    u32 m_unParam3;  // offset: 0x14
    static MyDTI DTI;
};

inline CDataCheatInfo::CDataCheatInfo() {
    this->m_ucId = 0;
    this->m_ucCount = 0;
    this->m_unParam1 = 0;
    this->m_unParam2 = 0;
    this->m_unParam3 = 0;
}
