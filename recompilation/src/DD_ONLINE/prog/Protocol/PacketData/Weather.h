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
class CDataGameTimeBaseInfo;
class CDataMoonSchedule;
class CDataWeatherLoop;
class CDataWeatherSchedule;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

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

class CDataMoonSchedule : public CPacketDataBase
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
    explicit CDataMoonSchedule();
    explicit CDataMoonSchedule(u8, s64, s64);
public:
    u8 m_ucMoonAge;  // offset: 0x8
    s64 m_llBeginTimeSec;  // offset: 0x10
    s64 m_llEndTimeSec;  // offset: 0x18
    static MyDTI DTI;
};

class CDataWeatherLoop : public CPacketDataBase
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
    explicit CDataWeatherLoop();
    explicit CDataWeatherLoop(u8, u32);
public:
    u8 m_ucWeatherId;  // offset: 0x8
    u32 m_unTimeSec;  // offset: 0xc
    static MyDTI DTI;
};

class CDataWeatherSchedule : public CPacketDataBase
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
    explicit CDataWeatherSchedule();
    explicit CDataWeatherSchedule(u8, s64, s64);
public:
    u8 m_ucWeatherId;  // offset: 0x8
    s64 m_llBeginTimeSec;  // offset: 0x10
    s64 m_llEndTimeSec;  // offset: 0x18
    static MyDTI DTI;
};

inline void* CDataGameTimeBaseInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataGameTimeBaseInfo::CDataGameTimeBaseInfo() {
    this->m_unOriginalWeek = 0;
    this->m_unOriginalMoonAge = 0;
    this->m_llOriginalGameTimeSec = 0;
    this->m_llOriginalRealTimeSec = 0;
    this->m_unGameTimeWeekDay = 0;
    this->m_unGameTimeMoonAge = 0;
    this->m_unGameTimeMonthDay = 0;
    this->m_unGameTimeDayHour = 0;
    this->m_unGameTimeOneDayMin = 0;
    this->m_unGameTimeYearMonth = 0;
}

inline void* CDataMoonSchedule::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataMoonSchedule::CDataMoonSchedule() {
    this->m_ucMoonAge = 0;
    this->m_llEndTimeSec = 0;
    this->m_llBeginTimeSec = 0;
}

inline void* CDataWeatherLoop::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataWeatherLoop::CDataWeatherLoop() {
    this->m_ucWeatherId = 0;
    this->m_unTimeSec = 0;
}

inline void* CDataWeatherSchedule::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataWeatherSchedule::CDataWeatherSchedule() {
    this->m_ucWeatherId = 0;
    this->m_llEndTimeSec = 0;
    this->m_llBeginTimeSec = 0;
}
