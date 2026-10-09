#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class uDDOModel;

// Declarations
class cpHugeble;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpHugeble : public cpComponent
{
    // inferred: uDDOModel::setInstantDeath names cpHugeble::mIsInstantDeath
    friend class uDDOModel;
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
    cpHugeble();
    virtual ~cpHugeble();
    virtual void setup();  // vtable slot 6
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void initHugeble();
    void endHugeble();
    void moveHugeble();
    bool checkHugeble(const MtVector3& checkPos);
    void setInstantDeath(bool flag);
    bool getHugebleEffPos(MtVector3& pos);
    void setHugebleDeathEff(const MtVector3& pos);
    void syncHugebleDeathEff();
    void endHugebleDeathEff();
    bool isInstantDeath();
    bool isSafePos();
    bool isHugeble() const;
    bool isHugebleFixed() const;
    bool isWaterCheck() const;
    f32 getWaterDepth() const;
    f32 getHugebleDepth(bool is_force) const;
    void resetHugebleOldPos(const MtVector3& pos);
    const MtVector3 getHugebleOldPos() const;
private:
    void setHugebleDeath();
    void hitInstantDeath(bool isFall, bool isWall);
public:
    uDDOModel* mpModel;  // offset: 0x50
private:
    bool mIsWaterDepthCheck;  // offset: 0x58
    f32 mWaterDepth;  // offset: 0x5c
    bool mIsHugebleNoCheck;  // offset: 0x60
    bool mIsHugebleDeath;  // offset: 0x61
    u32 mHugebleRno;  // offset: 0x64
    f32 mHugebleTimer;  // offset: 0x68
    f32 mHugebleTime;  // offset: 0x6c
    f32 mInstantDeathDepth;  // offset: 0x70
    bool mIsInstantDeath;  // offset: 0x74
    bool mIsSafePos;  // offset: 0x75
    bool mWaterCheck;  // offset: 0x76
    u32 mSeJoint;  // offset: 0x78
    MtVector3 mWaterJudgePos;  // offset: 0x80
    MtVector3 mHugebleDeathEffPos;  // offset: 0x90
    MtVector3 mHugebleOldPos;  // offset: 0xa0
    bool mFlgHugebleOldPosInited;  // offset: 0xb0
public:
    static MyDTI DTI;
};
