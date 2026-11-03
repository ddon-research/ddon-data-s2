#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"
#include "nRegionStatus.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cChildRegionStatusParamList;
class rChildRegionStatusParamList;
class uDDOModel;

// Declarations
class cpRegionStatusCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpRegionStatusCtrl : public cpComponent
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
    cpRegionStatusCtrl();
    virtual ~cpRegionStatusCtrl();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void changeRegionStatusNo(u32 statusNo, nRegionStatus::REGION_C_CHANGE_TYPE changeType);
    void setRegionStatusParamListRes(rChildRegionStatusParamList* pRes);
    const rChildRegionStatusParamList* getRegionStatusParamListRes() const;
    u32 getStatusNo() const;
    void updateRegionStatus();
private:
    nRegionStatus::REGION_C_STATUS_TYPE getStatusType(nRegionStatus::REGION_C_CHANGE_TYPE changeType, cChildRegionStatusParamList* pList) const;
    u32 getStatusPriority(nRegionStatus::REGION_C_STATUS_TYPE type) const;
    cChildRegionStatusParamList* findRegionStatusDataFromStatusNo(u32 statusNo) const;
private:
    uDDOModel* mpModel;  // offset: 0x50
    rChildRegionStatusParamList* mpRegionStatusParamListRes;  // offset: 0x58
    u32 mStatusNo;  // offset: 0x60
    nRegionStatus::REGION_C_STATUS_TYPE mStatusType;  // offset: 0x64
    u32 mStatusPriority;  // offset: 0x68
public:
    static MyDTI DTI;
private:
    static const u32 mRegionStatusPrio[9];
    static const u32 INVALID_STATUS_NO = 0;
};

inline void* cpRegionStatusCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cpRegionStatusCtrl::getStatusNo() const {
    return this->mStatusNo;
}
