#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "cpComponent.h"
#include "uCnsHeadCtrl.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class rHeadCtrl;
class uCnsHeadCtrl;
class uDDOModel;
class uNpc;

// Declarations
class cpHeadCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpHeadCtrl : public cpComponent
{
    // inferred: uNpc::setHeadCtrlSpeedRate names cpHeadCtrl::mAngleSpeedRate
    friend class uNpc;
public:
    enum
    {
        FLAG_DISABLE_SEQUENCE = 1,
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
    cpHeadCtrl();
    virtual ~cpHeadCtrl();
    virtual void setup();  // vtable slot 6
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setupComponentPtr();  // vtable slot 12
    void initHeadCtrl();
    void updateHeadCtrl();
    void adjustYaw();
    void adjustPitch();
    void setResource(rHeadCtrl* pRes);
    rHeadCtrl* getResource();
    MtVector3 getTargetPos();
    void setTargetPos(const MtVector3& pos);
    f32 getAngleY();
    f32 getPitch();
    bool isSleep();
    void onFlag(u32 flag);
    void offFlag(u32 flag);
    bool isFlag(u32);
    void setFlag(u32);
    u32 getFlag();
    void setAngleSpeedRate(f32 rate);
    f32 getAngleSpeedRate();
    void setPitchSpeedRate(f32 rate);
    f32 getPitchSpeedRate();
protected:
    void removeConstraint();
public:
    uDDOModel* mpModel;  // offset: 0x50
protected:
    MtTypedArray<uCnsHeadCtrl> mCnsHeadCtrlArray;  // offset: 0x58
    rHeadCtrl* mpResource;  // offset: 0x78
    MtVector3 mTargetPos;  // offset: 0x80
    u32 mFlag;  // offset: 0x90
    f32 mAngleY;  // offset: 0x94
    f32 mTgtAngleY;  // offset: 0x98
    f32 mAngleYMin;  // offset: 0x9c
    f32 mAngleYMax;  // offset: 0xa0
    f32 mAngleYOld;  // offset: 0xa4
    f32 mAngleYDiff;  // offset: 0xa8
    f32 mPitch;  // offset: 0xac
    f32 mTgtPitch;  // offset: 0xb0
    f32 mPitchMin;  // offset: 0xb4
    f32 mPitchMax;  // offset: 0xb8
    f32 mPitchOld;  // offset: 0xbc
    f32 mAngleSpeedRate;  // offset: 0xc0
    f32 mPitchSpeedRate;  // offset: 0xc4
    bool mIsSleep;  // offset: 0xc8
    bool mEnable;  // offset: 0xc9
public:
    static MyDTI DTI;
};
