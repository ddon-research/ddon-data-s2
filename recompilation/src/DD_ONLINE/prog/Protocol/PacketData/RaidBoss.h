#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataRaidBossRegionInfo;
class CDataRaidBossUnitInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using RaidBossRegionInfoVec = MtTypedArray<CDataRaidBossRegionInfo>;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class CDataRaidBossRegionInfo : public CPacketDataBase
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
    explicit CDataRaidBossRegionInfo();
    explicit CDataRaidBossRegionInfo(u32, u32);
public:
    u32 m_unRagionNo;  // offset: 0x8
    u32 m_unVital;  // offset: 0xc
    static MyDTI DTI;
};

class CDataRaidBossUnitInfo : public CPacketDataBase
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
    explicit CDataRaidBossUnitInfo();
    explicit CDataRaidBossUnitInfo(u32, const RaidBossRegionInfoVec&);
public:
    u32 m_unRaidBossID;  // offset: 0x8
    RaidBossRegionInfoVec m_RegionInfoList;  // offset: 0x10
    static MyDTI DTI;
};

inline void* CDataRaidBossRegionInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataRaidBossRegionInfo::CDataRaidBossRegionInfo() {
    this->m_unRagionNo = 0;
    this->m_unVital = 0;
}

inline void* CDataRaidBossUnitInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataRaidBossUnitInfo::CDataRaidBossUnitInfo() {
    this->m_unRaidBossID = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtMemoryAllocator.h"

inline MtAllocator* CDataRaidBossRegionInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataRaidBossRegionInfo::DTI);
}

inline MtAllocator* CDataRaidBossUnitInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataRaidBossUnitInfo::DTI);
}

inline void* CDataRaidBossUnitInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::CDataRaidBossUnitInfo::DTI)->memAlloc(sz, align, ::CDataRaidBossUnitInfo::DTI.::MtDTI::getID());
}
