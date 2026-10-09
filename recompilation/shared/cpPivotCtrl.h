#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class uDDOModel;

// Declarations
class cpPivotCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpPivotCtrl : public cpComponent
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
    cpPivotCtrl();
    virtual ~cpPivotCtrl();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    virtual void setActive(bool active);  // vtable slot 13
    void before();
    void after();
    void setPivotOffset(const MtVector3& offset);
    MtVector3 getPivotOffset();
    void setPivotJointNo(u32 JntNo);
    u32 getPivotJointNo();
    void setPivotPos(const MtVector3& pos);
    MtVector3 getPivotPos();
protected:
    bool isActive();
public:
    uDDOModel* mpModel;  // offset: 0x50
protected:
    u32 mPivotJointNo;  // offset: 0x58
    MtVector3 mPivotOffset;  // offset: 0x60
    MtVector3 mOrgPos;  // offset: 0x70
    MtVector3 mOrgPosModel;  // offset: 0x80
    MtVector3 mPivotPos;  // offset: 0x90
public:
    static MyDTI DTI;
};
