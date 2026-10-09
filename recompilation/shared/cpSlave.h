#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cpThinkBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class uDDOModel;

// Declarations
class cpSlave;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpSlave : public cpThinkBase
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
    cpSlave();
    virtual ~cpSlave();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    u32 callbackGetAction();
    const MtVector3& getMoveTargetPos() const;
    f32 getRotTargetAngle() const;
    const MtVector3& getInterpolateVec() const;
    void setInterpolateType(u32 interpolate);
    void moveInterpolate();
    void updateInterpolatePos(const MtVector3& pos, bool forceSet);
    void updateInterpolateAngle(f32 angle);
    void setForceSet(u32 interpolate);
protected:
    u32 checkCommand();
    void interpolate();
    u32 getMoveAction();
private:
    void interpolatePos();
    void interpolateAngle();
    void setPos();
    void setAngle();
    void setMoveTragetPos(const MtVector3& pos);
    void setRotTargetAngle(f32 angleY);
    u32 getInterpolateType();
    bool interpolatePosForMove();
    void interpolateAngleForMove();
    void interpolatePosForSpecialMove();
    f32 getMyMoveSpeed(f32 distance);
    u32 checkCsChange(const u32 act_no);
public:
    virtual f32 getMoveTargetAngle();  // vtable slot 24
    virtual f32 getMoveAngle();  // vtable slot 25
    virtual const MtVector3& getTargetPos();  // vtable slot 20
    virtual u32 getTargetUID();  // vtable slot 21
    void setIsFirstMove(bool flg);
    bool isFirstMove();
    void setIsMove(bool);
    bool isMove();
    void setInterpolateMoveSpeed(f32 max, f32 min);
    void setMoveMaxSpeed(f32 sp);
    void setMoveMinSpeed(f32 sp);
protected:
    uDDOModel* mpModel;  // offset: 0x50
    u32 mFallAction;  // offset: 0x58
    u32 mEndAction;  // offset: 0x5c
    u32 mLandAction;  // offset: 0x60
private:
    MtVector3 mMoveTargetPos;  // offset: 0x70
    f32 mRotTargetAngle;  // offset: 0x80
    f32 mWalkBorder;  // offset: 0x84
    f32 mRunBorder;  // offset: 0x88
    f32 mDashBorder;  // offset: 0x8c
    u32 mInterpolateType;  // offset: 0x90
    MtVector3 mInterpolateVec;  // offset: 0xa0
    f32 mInterpolatePosTimer;  // offset: 0xb0
    f32 mInterpolateAngle;  // offset: 0xb4
    f32 mInterpolateAngleTimer;  // offset: 0xb8
    f32 mDefInterpolatePosTimer;  // offset: 0xbc
    f32 mDefInterpolateAngleTimer;  // offset: 0xc0
    bool mFirstReceivePos;  // offset: 0xc4
    bool mFirstReceiveAngle;  // offset: 0xc5
    bool mForceSetPos;  // offset: 0xc6
    bool mForceSetAngle;  // offset: 0xc7
    MtVector3 mTargetPos;  // offset: 0xd0
    bool mIsFirstMove;  // offset: 0xe0
    bool mIsMove;  // offset: 0xe1
    MtVector3 mBeginMyPos;  // offset: 0xf0
    MtVector3 mBeginMyDir;  // offset: 0x100
    f32 mMoveMaxSpeed;  // offset: 0x110
    f32 mMoveMinSpeed;  // offset: 0x114
    f32 mMoveAngle;  // offset: 0x118
    f32 mPositionInterValRate;  // offset: 0x11c
    f32 minterpolateForMoveTime;  // offset: 0x120
    f32 mClogTimer;  // offset: 0x124
    f32 mTargetLength;  // offset: 0x128
    f32 mMoveLength;  // offset: 0x12c
    f32 mOldMoveLength;  // offset: 0x130
public:
    static MyDTI DTI;
};
