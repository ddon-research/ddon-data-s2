#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive3D.h"
#include "cDelegate.h"
#include "cpComponent.h"
#include "nDDOUtility.h"
#include "sCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtVector3;
class uDDOModel;

// Declarations
class cpCheckWallCliff;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpCheckWallCliff : public cpComponent
{
public:
    enum PREVENTION_TYPE
    {
        PREVENT_TYPE_NONE = 0,
        PREVENT_TYPE_TRANS_ACT = 1,
        PREVENT_TYPE_CORRECT_ONLY = 2,
        PREVENT_TYPE_CORRECT_ATTACK = 3,
    };
public:
    class MyDTI;
public:
    using FallPreventPosList = nDDOUtility::cArray<MtVector3, 4>;
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
    cpCheckWallCliff();
    virtual ~cpCheckWallCliff();
    virtual void setup();  // vtable slot 6
    void update();
    void compMoveAfter();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    void resetPos(const MtVector3& pos);
private:
    void moveCheckWall();
    void moveCheckCliff2();
    bool isFallPreventionAction();
    PREVENTION_TYPE getPreventionType();
    bool checkFallPreventionGround(PREVENTION_TYPE type);
    void updateFallPreventionPos();
    bool checkFallPrevention();
public:
    void setEnableWallCheck(bool isEnable);
    void setWallCheckDate(s32 jnt, f32 range, u32 filter);
    void setWallCheckOffset(const MtVector3&);
    void setEnableCliffCheck(bool isEnable);
    void setCliffCheckDate(s32 jnt, f32 forword, f32 height, u32 filter);
    void setCliffCheckOffset(const MtVector3& offset);
    void setCliffCheckTargetPss(const MtVector3& tag);
    void setIsCliffCheckTargetPos(bool flg);
    MtLineSegment getCliffDownCheckSg() const;
    bool isWallStop() const;
private:
    bool mIsWallCheckEnable;  // offset: 0x50
    s32 mWallCheckCnsJnt;  // offset: 0x54
    f32 mWallCheckRange;  // offset: 0x58
    u32 mWallCheckFilter;  // offset: 0x5c
    MtVector3 mWallCheckOffset;  // offset: 0x60
    bool mIsCliffCheckEnable;  // offset: 0x70
    bool mIsHumitodomariHeight;  // offset: 0x71
    bool mIsWallStop;  // offset: 0x72
    s32 mCliffCheckCnsJnt;  // offset: 0x74
    f32 mCliffCheckRangeForward;  // offset: 0x78
    f32 mCliffCheckRangeHeight;  // offset: 0x7c
    u32 mCliffCheckFilter;  // offset: 0x80
    MtVector3 mCliffCheckOffset;  // offset: 0x90
    FallPreventPosList mFallPreventionPosList;  // offset: 0xa0
    MtVector3 mFallPreventionCorrectPos;  // offset: 0xe0
    f32 mHumitodomariTimer;  // offset: 0xf0
    bool mIsCliffCheckTarget;  // offset: 0xf4
    MtVector3 mCliffCheckTarget;  // offset: 0x100
    MtLineSegment mCliffCheckDownSg;  // offset: 0x110
public:
    cDelegate_1<void, sCollision::TriangleInfo&> callbackfindwall;  // offset: 0x130
    cDelegate_1<void, sCollision::TriangleInfo&> callbackfindcliff;  // offset: 0x148
    cDelegate_0<bool> transWallClimb;  // offset: 0x160
    cDelegate_0<bool> transDashJumpCliff;  // offset: 0x178
    cDelegate_1<void, const MtVector3&> correctFallPreventionPos;  // offset: 0x190
    uDDOModel* mpModel;  // offset: 0x1a8
    static MyDTI DTI;
private:
    static const s32 FALL_PREVENTION_POS_MAX = 4;
};
