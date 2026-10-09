#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "uConstraint.h"
#include "uCoord.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
class cResource;
class rCnsJointOffset;
class uModel;

// Declarations
class uCnsJointOffset;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uCnsJointOffset : public uConstraint
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
    uCnsJointOffset();
    virtual ~uCnsJointOffset();
    virtual void setResource(cResource* pRes);  // vtable slot 32
    virtual cResource* getResource();  // vtable slot 33
    virtual void adjust(uModel::Joint* pJnt, uModel* pModel);  // vtable slot 29
    virtual void remove();  // vtable slot 31
    virtual void update();  // vtable slot 30
    virtual void evSetJoints(uModel::Joint* * pJnts, u32 Num);  // vtable slot 37
    bool setJoint(u32 JntNo);
    u32 getJoint();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void set(uModel* pModel, u32 JntNo, u32 Pri);
    void set(uModel* pModel, rCnsJointOffset* pRes);
protected:
    void setJointForProperty(u32 JntNo);
public:
    MtVector3 mRot;  // offset: 0xa0
    MtVector3 mScl;  // offset: 0xb0
    MtVector3 mTrans;  // offset: 0xc0
    union
    {
    public:
        u32 mOrderProp;  // offset: 0x0
        uCoord::ORDER mOrder;  // offset: 0x0
    };  // offset: 0xd0
protected:
    rCnsJointOffset* mpCnsJointOffsetRes;  // offset: 0xd8
    u32 mJoint;  // offset: 0xe0
public:
    static MyDTI DTI;
};
