#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/uConstraint.h"
#include "../shared/uModel.h"

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
class cShakeCtrl;
class cpShakeCtrl;
class uModel;

// Declarations
class uCnsShakeCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uCnsShakeCtrl : public uConstraint
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
    uCnsShakeCtrl();
    virtual ~uCnsShakeCtrl();
    void init();
    virtual void move();  // vtable slot 9
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
    void shake();
    void shake(const MtVector3& dir);
protected:
    void shake(f32 shake_rot, f32 shake_axis, f32 shake_trans, const MtVector3& dir);
public:
    void set(uModel* pModel, u32 JntNo, u32 Pri);
public:
    f32 mAmpRot;  // offset: 0x94
    f32 mAmpAxis;  // offset: 0x98
    f32 mAmpTrans;  // offset: 0x9c
    f32 mFrame;  // offset: 0xa0
    f32 mCycle;  // offset: 0xa4
    f32 mRate;  // offset: 0xa8
    MtVector3 mDir;  // offset: 0xb0
    uCnsShakeCtrl* mpChild;  // offset: 0xc0
protected:
    u32 mJoint;  // offset: 0xc8
    cpShakeCtrl* mpShakeCtrl;  // offset: 0xd0
    cShakeCtrl* mpShakeCtrlData;  // offset: 0xd8
    f32 mARot;  // offset: 0xe0
    f32 mAAxis;  // offset: 0xe4
    f32 mATrans;  // offset: 0xe8
    f32 mPhase;  // offset: 0xec
    f32 mTimer;  // offset: 0xf0
    u32 mIK;  // offset: 0xf4
    MtVector3 mLocalRotAxis;  // offset: 0x100
    MtVector3 mAxis;  // offset: 0x110
public:
    static MyDTI DTI;
};
