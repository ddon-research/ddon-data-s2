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
class CDataGameServerListInfo;
class CDataGameTime;
class CDataURLInfo;
class CDataWeatherForecast;
class CDataWorldInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataGameServerListInfo : public CPacketDataBase
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
    explicit CDataGameServerListInfo();
    explicit CDataGameServerListInfo(u16, const char*, const char*, const char*, u32, u32, u32, const char*, u16, b8);
public:
    u16 m_usId;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    MtString m_wstrBrief;  // offset: 0x18
    MtString m_wstrTrafficName;  // offset: 0x20
    u32 m_unTrafficLevel;  // offset: 0x28
    u32 m_unMaxLoginNum;  // offset: 0x2c
    u32 m_unLoginNum;  // offset: 0x30
    MtString m_wstrAddr;  // offset: 0x38
    u16 m_usPort;  // offset: 0x40
    b8 m_bIsHide;  // offset: 0x42
    static MyDTI DTI;
};

class CDataGameTime : public CPacketDataBase
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
    explicit CDataGameTime();
    explicit CDataGameTime(u8, u8, u8, u8, u8, u8, u8, u16);
public:
    u8 m_ucMoon;  // offset: 0x8
    u8 m_ucSec;  // offset: 0x9
    u8 m_ucMin;  // offset: 0xa
    u8 m_ucHour;  // offset: 0xb
    u8 m_ucMDay;  // offset: 0xc
    u8 m_ucMon;  // offset: 0xd
    u8 m_ucWDay;  // offset: 0xe
    u16 m_usYear;  // offset: 0x10
    static MyDTI DTI;
};

class CDataURLInfo : public CPacketDataBase
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
    explicit CDataURLInfo();
    explicit CDataURLInfo(u32, const char*);
public:
    u32 m_unType;  // offset: 0x8
    MtString m_wstrUrl;  // offset: 0x10
    static MyDTI DTI;
};

class CDataWeatherForecast : public CPacketDataBase
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
    explicit CDataWeatherForecast();
    explicit CDataWeatherForecast(u32);
public:
    u32 m_unWeather;  // offset: 0x8
    static MyDTI DTI;
};

class CDataWorldInfo : public CPacketDataBase
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
    explicit CDataWorldInfo();
    explicit CDataWorldInfo(u16, const char*, const char*, u8, u8, u32, u32, u32, u32, const char*, const char*, const char*, const char*, u8);
public:
    u16 m_usId;  // offset: 0x8
    MtString m_wstrName;  // offset: 0x10
    MtString m_wstrBrief;  // offset: 0x18
    u8 m_ucDragonType;  // offset: 0x20
    u8 m_ucSetType;  // offset: 0x21
    u32 m_unTemp0;  // offset: 0x24
    u32 m_unTemp1;  // offset: 0x28
    u32 m_unTemp2;  // offset: 0x2c
    u32 m_unTemp3;  // offset: 0x30
    MtString m_wstrTempStr0;  // offset: 0x38
    MtString m_wstrTempStr1;  // offset: 0x40
    MtString m_wstrTempStr2;  // offset: 0x48
    MtString m_wstrTempStr3;  // offset: 0x50
    u8 m_ucCycleContentsState;  // offset: 0x58
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataGameTime::CDataGameTime() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_usYear = static_cast<u16>(0);
    this->m_ucWDay = static_cast<u8>(0);
    this->m_ucMDay = static_cast<u8>(0);
    this->m_ucMon = static_cast<u8>(0);
    this->m_ucMoon = static_cast<u8>(0);
    this->m_ucSec = static_cast<u8>(0);
    this->m_ucMin = static_cast<u8>(0);
    this->m_ucHour = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataURLInfo::CDataURLInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unType = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataWeatherForecast::CDataWeatherForecast() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unWeather = static_cast<u32>(0);
}
