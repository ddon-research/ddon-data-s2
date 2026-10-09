#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "nStatusEnemy.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cEmWorkRateTable;
class rEmWorkRateTable;
class uEnemy;

// Declarations
class cEmWorkRateCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cEmWorkRateCtrl : public MtObject
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
    cEmWorkRateCtrl();
    virtual ~cEmWorkRateCtrl();
    void setup();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void updatePtr();
    void setOwner(uEnemy* pEnemy);
    void changeWorkRateNo(u32 statusNo, nStatusEnemy::WORKRATE_CHANGE_TYPE changeType);
    void setEmWorkRateRes(rEmWorkRateTable* pRes);
    u32 getEmWorkRateStatusNo() const;
    void updateEmWorkRate();
private:
    nStatusEnemy::WORKRATE_STATUS_TYPE getStatusType(nStatusEnemy::WORKRATE_CHANGE_TYPE changeType, const cEmWorkRateTable* pTableData) const;
    u32 getStatusPriority(nStatusEnemy::WORKRATE_STATUS_TYPE type) const;
    const cEmWorkRateTable* findEmWorkRateData(u32 statusNo) const;
private:
    uEnemy* mpEnemy;  // offset: 0x8
    rEmWorkRateTable* mpEmWorkRateTableRes;  // offset: 0x10
    u32 mStatusNo;  // offset: 0x18
    nStatusEnemy::WORKRATE_STATUS_TYPE mStatusType;  // offset: 0x1c
    u32 mStatusPriority;  // offset: 0x20
public:
    static MyDTI DTI;
private:
    static const u32 mRegionStatusPrio[5];
    static const u32 INVALID_STATUS_NO = 4294967295;
};
