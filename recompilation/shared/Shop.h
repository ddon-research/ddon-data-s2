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
class CDataGoodsParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class CDataGoodsParam : public CPacketDataBase
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
    explicit CDataGoodsParam();
    explicit CDataGoodsParam(u32, u32, u32, u32, u32, u32);
public:
    u32 m_unIndex;  // offset: 0x8
    u32 m_unPrice;  // offset: 0xc
    u32 m_unStock;  // offset: 0x10
    u32 m_unMaxStock;  // offset: 0x14
    u32 m_unRequireFavorite;  // offset: 0x18
    u32 m_unItemID;  // offset: 0x1c
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataGoodsParam::CDataGoodsParam() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unRequireFavorite = static_cast<u32>(0);
    this->m_unItemID = static_cast<u32>(0);
    this->m_unStock = static_cast<u32>(0);
    this->m_unMaxStock = static_cast<u32>(0);
    this->m_unIndex = static_cast<u32>(0);
    this->m_unPrice = static_cast<u32>(0);
}
