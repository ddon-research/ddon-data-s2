#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cHitInfo;
class cHitNode;
class uBaseModel;
class uHuman;

// Declarations
class uAimCheck;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uAimCheck : public uDDOModel
{
public:
    enum AIM_TYPE
    {
        AIM_NONE = 0,
        AIM_CAMERA = 1,
        AIM_FALL_SHOT = 2,
    };
    enum
    {
        FILTER_NONE = 0,
        FILTER_CHARACTER_BASE = 1,
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
    uAimCheck();
    virtual ~uAimCheck();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void createComponent();  // vtable slot 43
    virtual void callbackAttackTest(cHitInfo* pHitInfo);  // vtable slot 85
    void initAim(AIM_TYPE type, const MtVector3& ofs0, const MtVector3& ofs1, f32 rad, s32 joint, u32 filter);
    virtual void updatePtr();  // vtable slot 17
protected:
    virtual void update();  // vtable slot 173
private:
    void setCollision();
public:
    void setOwner(uHuman* pOwner);
    void setActive(bool a);
    bool isAim() const;
    bool isAimOld() const;
    const MtVector3& getAimPos() const;
    void setOffset0(const MtVector3&);
    void setOffset1(const MtVector3&);
    const MtVector3& getOffset0() const;
    const MtVector3& getOffset1() const;
    const uBaseModel* getAimTarget();
    AIM_TYPE getAimType() const;
    void setRadiusRate(f32 rate);
private:
    AIM_TYPE mAimType;  // offset: 0x246c
    bool mIsActive;  // offset: 0x2470
    uHuman* mpOwner;  // offset: 0x2478
    const uBaseModel* mpTarget;  // offset: 0x2480
    s32 mAimFlag;  // offset: 0x2488
    s32 mAimFlagOld;  // offset: 0x248c
    MtVector3 mAimPos;  // offset: 0x2490
    MtVector3 mAimOfs0;  // offset: 0x24a0
    MtVector3 mAimOfs1;  // offset: 0x24b0
    f32 mAimRad;  // offset: 0x24c0
    s32 mJoint;  // offset: 0x24c4
    MtVector3 mAimVec;  // offset: 0x24d0
    u32 mHitCnt;  // offset: 0x24e0
    u32 mFilter;  // offset: 0x24e4
    f32 mPrioDot;  // offset: 0x24e8
    f32 mRadiusRate;  // offset: 0x24ec
    f32 mAimLength;  // offset: 0x24f0
    cHitNode* mpNode;  // offset: 0x24f8
public:
    static MyDTI DTI;
};
