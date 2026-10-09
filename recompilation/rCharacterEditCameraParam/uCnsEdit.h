#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cDelegate.h"
#include "../shared/uConstraint.h"
#include "../shared/uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtUI;
class MtVector3;
class cDraw;
class cResource;
class uModel;

// Declarations
class uCnsEdit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uCnsEdit : public uConstraint
{
public:
    enum
    {
        FAT_ADJUST_WEAPON_NULL = 0,
        FAT_ADJUST_R_ARM = 1,
        FAT_ADJUST_L_ARM = 2,
    };
    enum
    {
        TX = 1,
        TY = 2,
        TZ = 4,
        COG = 8,
    };
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
    uCnsEdit();
    virtual ~uCnsEdit();
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
public:
    u32 mTransFlag;  // offset: 0x94
    u32 mFatAdjust;  // offset: 0x98
    f32 mEyeAnimScaleY;  // offset: 0x9c
    MtVector3 mOrgTrans;  // offset: 0xa0
    MtVector3 mOrgScl;  // offset: 0xb0
    MtQuaternion mOrgQuat;  // offset: 0xc0
    MtVector3 mPresetTrans;  // offset: 0xd0
    MtVector3 mPresetScl;  // offset: 0xe0
    MtQuaternion mPresetQuat;  // offset: 0xf0
    MtVector3 mTrans;  // offset: 0x100
    MtVector3 mScl;  // offset: 0x110
    MtQuaternion mQuat;  // offset: 0x120
    cDelegate_3<void, uModel::Joint*, uModel*, uCnsEdit*> adjustFunc;  // offset: 0x130
protected:
    u32 mJoint;  // offset: 0x148
public:
    static MyDTI DTI;
};
