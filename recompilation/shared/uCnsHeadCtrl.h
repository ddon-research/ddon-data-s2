#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "uConstraint.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cDraw;
class cResource;
class cpHeadCtrl;
class uModel;

// Declarations
class uCnsHeadCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uCnsHeadCtrl : public uConstraint
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
    uCnsHeadCtrl();
    virtual ~uCnsHeadCtrl();
    void init();
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
protected:
    u32 mJoint;  // offset: 0x94
    cpHeadCtrl* mpHeadCtrl;  // offset: 0x98
    u32 mLocalAxis;  // offset: 0xa0
    f32 mRightLimit;  // offset: 0xa4
    f32 mLeftLimit;  // offset: 0xa8
    f32 mUpperLimit;  // offset: 0xac
    f32 mLowerLimit;  // offset: 0xb0
    f32 mAngleBlend;  // offset: 0xb4
    f32 mPitchBlend;  // offset: 0xb8
    bool mLocal;  // offset: 0xbc
public:
    static MyDTI DTI;
};
