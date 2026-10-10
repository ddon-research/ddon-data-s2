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
class CDataContextSetBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class CDataContextSetBase : public CPacketDataBase
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
    explicit CDataContextSetBase();
    explicit CDataContextSetBase(u32, u32, s32, s32, s32);
public:
    u32 m_unID;  // offset: 0x8
    u32 m_unUniqueID;  // offset: 0xc
    s32 m_nStageNo;  // offset: 0x10
    s32 m_nEncountArea;  // offset: 0x14
    s32 m_nMasterIndex;  // offset: 0x18
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataContextSetBase::CDataContextSetBase() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_nMasterIndex = static_cast<s32>(0);
    this->m_nStageNo = static_cast<s32>(0);
    this->m_nEncountArea = static_cast<s32>(0);
    this->m_unID = static_cast<u32>(0);
    this->m_unUniqueID = static_cast<u32>(0);
}
