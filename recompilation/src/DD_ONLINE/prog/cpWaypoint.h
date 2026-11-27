#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class rWaypoint;

// Declarations
class cpWaypoint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpWaypoint : public cpComponent
{
public:
    enum
    {
        GOAL_IDX_0 = 0,
        GOAL_IDX_1 = 1,
        GOAL_IDX_2 = 2,
        GOAL_POINT_NUM = 3,
    };
public:
    class MyDTI;
    class cWork;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cWork : public MtObject
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
        cWork();
        virtual ~cWork() {}
    public:
        s32 mPrevIdx;  // offset: 0x8
        f32 mTotalWeight;  // offset: 0xc
        bool mIsFix;  // offset: 0x10
        static MyDTI DTI;
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
    rWaypoint* getWaypoint() const;
    u32 getGotoPointNo() const;
    virtual void setActive(bool active);  // vtable slot 13
    void setGoalPointNo(s32 pointNo0, s32 pointNo1, s32 pointNo2);
    MtVector3 getNextPoint() const;
    MtVector3 getTargetPos() const;
    bool isGoalGotoPointNo() const;
    u32 getGoalPointNum() const;
    void checkGoal();
    void setMoveType(s32 moveType);
    void setIsCheckScr(bool check = false);
    void calcNextPoint();
    void calcGotoPoint();
    void updateNextPoint();
    void traceNaviMesh();
    void openDoor();
    cpWaypoint();
    virtual ~cpWaypoint();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
protected:
    s32 mNextPointNo;  // offset: 0x50
    s32 mGotoPointNo;  // offset: 0x54
    MtTypedArray<cWork> mWork;  // offset: 0x58
    bool mIsGoal;  // offset: 0x78
    s32 mGoalPointNo[3];  // offset: 0x7c
    s32 mGoalIndex;  // offset: 0x88
    u32 mOpenDoorUID;  // offset: 0x8c
    MtVector3 mTargetPos;  // offset: 0x90
    s32 mMoveType;  // offset: 0xa0
    bool mIsCheckScr;  // offset: 0xa4
public:
    static MyDTI DTI;
};

inline void* cpWaypoint::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cpWaypoint::setIsCheckScr(bool check) {
    this->mIsCheckScr = false;
}

inline void* cpWaypoint::cWork::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cpWaypoint::cWork::cWork() {
    this->mPrevIdx = -1;
    this->mTotalWeight = -1.0f;
    this->mIsFix = false;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpWaypoint::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpWaypoint::DTI);
}

inline void cpWaypoint::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpWaypoint::DTI)->memFree(p_addr);
}

inline void* cpWaypoint::cWork::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cpWaypoint::cWork::DTI)->memAlloc(sz, align, ::cpWaypoint::cWork::DTI.::MtDTI::getID());
}

inline void cpWaypoint::cWork::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpWaypoint::cWork::DTI)->memFree(p_addr);
}
