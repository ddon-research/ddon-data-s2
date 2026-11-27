#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cHumanAction.h"
#include "uHuman.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
class MtDTI;
class MtMatrix;
class MtObject;
class MtQuaternion;
class MtVector3;
class cHitGeom;
class uDDOModel;
class uHuman;

// Declarations
class cHumanActEnemyClimb;
class cHumanActEnemyClimbBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cHumanActEnemyClimbBase : public cHumanActBase
{
    friend class cHumanActEnemyClimb;
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
    cHumanActEnemyClimbBase();
    virtual void init();  // vtable slot 7
    virtual void final();  // vtable slot 9
    virtual bool checkEscape();  // vtable slot 18
    bool findClimbCapsule(uDDOModel* pDDOModel, uHuman::cEnemyClimbInfo* climbInfo, const MtVector3& pos);
    bool findClimbCapsule2(uDDOModel* pObjModel, uHuman::cEnemyClimbInfo* climbInfo, uHuman* pHuman, MtVector3& ret_pos, MtQuaternion& ret_quat, MtVector3& ret_push_pos);
    bool findClimbCapsuleError();
    void calcCapsuleHitPos(const MtCapsule& cap, const MtVector3& pos, MtVector3& hit_pos, MtVector3& normal);
    void initFollowCapsule(uHuman::cEnemyClimbInfo* climbInfo, uHuman* pHuman);
    void updateFollowCapsule(uHuman::cEnemyClimbInfo* climbInfo, uHuman* pHuman);
    void followCapsule(uHuman::cEnemyClimbInfo* climbInfo, uHuman* pHuman);
    void storeClimbInfo(uHuman::cEnemyClimbInfo* pClimbInfo, const cHitGeom* pGeom, uDDOModel* pDDOModel);
    void keepHeadUp(f32 rotSpeed);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 13
protected:
    void updateInterpolatePos(MtVector3& pos, f32 deltaTime);
    void setInterpolatePos(const MtVector3& nowpos, const MtVector3& targetpos, const MtVector3& targetoffset, f32 interpolateTime);
    bool isInterpolateActive() const;
    void updateClimbInterpolatePos(uHuman& human);
    void setInterpolatePos4AtkAct(uHuman& human, f32 length);
    void debugDispTargetPos(uHuman& human);
protected:
    MtVector3 mBeginPivotOffset;  // offset: 0x50
    MtVector3 mClimbPivotOffset;  // offset: 0x60
private:
    f32 mNotFoundNodeTime;  // offset: 0x70
    bool mIsInterpolateActive;  // offset: 0x74
    MtVector3 mInterpolateVec;  // offset: 0x80
    f32 mInterpolateTimer;  // offset: 0x90
    f32 mTimer;  // offset: 0x94
    MtVector3 mMoveTargetPos;  // offset: 0xa0
    MtVector3 mMoveTargetOffset;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cHumanActEnemyClimb : public cHumanActEnemyClimbBase
{
public:
    enum
    {
        CLIMB_WAIT = 0,
        CLIMB_UP = 1,
        CLIMB_DOWN = 2,
        CLIMB_RIGHT = 3,
        CLIMB_LEFT = 4,
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
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    void moveClimb();
    virtual bool checkEscape();  // vtable slot 18
    void moveClimbNormal();
    void moveClimbVert();
    bool isHeadUp();
    void moveBeforSlave();
    bool isVertical();
private:
    s32 mPhaseClimbVert;  // offset: 0xc0
    s32 mIsEnd;  // offset: 0xc4
    s32 mUpDown;  // offset: 0xc8
    s32 mRightLeft;  // offset: 0xcc
    MtMatrix mCnvMat;  // offset: 0xd0
    bool mIsVertical;  // offset: 0x110
    f32 mCapMissingTimer;  // offset: 0x114
    bool mUpdateFollowCapsule;  // offset: 0x118
    bool mKeepDir;  // offset: 0x119
    MtVector3 mMoveDir;  // offset: 0x120
public:
    static MyDTI DTI;
};

inline void* cHumanActEnemyClimb::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cHumanActEnemyClimbBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cHumanActEnemyClimb::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cHumanActEnemyClimb::DTI)->memFree(p_addr);
}

inline void cHumanActEnemyClimbBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cHumanActEnemyClimbBase::DTI)->memFree(p_addr);
}
