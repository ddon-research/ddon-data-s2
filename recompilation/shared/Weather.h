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
class CDataGameTimeBaseInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;

class CDataGameTimeBaseInfo : public CPacketDataBase
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
    explicit CDataGameTimeBaseInfo();
    explicit CDataGameTimeBaseInfo(u32, u32, u32, u32, u32, u32, s64, s64, u32, u32);
public:
    u32 m_unGameTimeOneDayMin;  // offset: 0x8
    u32 m_unGameTimeYearMonth;  // offset: 0xc
    u32 m_unGameTimeMonthDay;  // offset: 0x10
    u32 m_unGameTimeDayHour;  // offset: 0x14
    u32 m_unGameTimeWeekDay;  // offset: 0x18
    u32 m_unGameTimeMoonAge;  // offset: 0x1c
    s64 m_llOriginalRealTimeSec;  // offset: 0x20
    s64 m_llOriginalGameTimeSec;  // offset: 0x28
    u32 m_unOriginalWeek;  // offset: 0x30
    u32 m_unOriginalMoonAge;  // offset: 0x34
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataGameTimeBaseInfo::CDataGameTimeBaseInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unOriginalWeek = static_cast<u32>(0);
    this->m_unOriginalMoonAge = static_cast<u32>(0);
    this->m_llOriginalGameTimeSec = static_cast<s64>(0);
    this->m_llOriginalRealTimeSec = static_cast<s64>(0);
    this->m_unGameTimeWeekDay = static_cast<u32>(0);
    this->m_unGameTimeMoonAge = static_cast<u32>(0);
    this->m_unGameTimeMonthDay = static_cast<u32>(0);
    this->m_unGameTimeDayHour = static_cast<u32>(0);
    this->m_unGameTimeOneDayMin = static_cast<u32>(0);
    this->m_unGameTimeYearMonth = static_cast<u32>(0);
}
