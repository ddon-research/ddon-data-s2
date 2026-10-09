#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "cDelegate.h"
#include "cpComponent.h"
#include "sCollision.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cWallHitInfo;
class uDDOModel;

// Declarations
class cGroundAttrInfo;
class cpScrCollision;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cGroundAttrInfo : public MtObject
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
    cGroundAttrInfo();
    virtual ~cGroundAttrInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setEnable(bool enable);
    bool isEnable();
    void setUpCheckEnable(bool enable);
    void update(uDDOModel* pParent);
public:
    MtVector3 mTop;  // offset: 0x10
    MtVector3 mBottom;  // offset: 0x20
    u32 mType;  // offset: 0x30
    u32 mFilter;  // offset: 0x34
    u32 mTopFilter;  // offset: 0x38
    sCollision::TriangleInfo mTriangle;  // offset: 0x40
    u32 mHitFlag;  // offset: 0x110
protected:
    bool mEnable;  // offset: 0x114
    bool mIsUpCheck;  // offset: 0x115
public:
    static MyDTI DTI;
};

class cpScrCollision : public cpComponent
{
public:
    enum
    {
        FLAG_HIT_LAND_PRECHECK = 1,
        FLAG_NO_GROUND_ADJUST = 2,
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
    cpScrCollision();
    virtual ~cpScrCollision();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    u32 scrAdjust(MtVector3& NewPos, MtVector3& OldPos);
    u32 getFilter();
    void setFilter(u32 filter);
    void setCapsule(const MtCapsule& capsule);
    void setSupportVector(const MtVector3&);
    void setFlag(u32);
    void onFlag(u32 flag);
    void offFlag(u32 flag);
    u32 callbackAdjustPosition(const sCollision::ScrCollisionInfo& NowScrCollisionInfo, const sCollision::SbcInfo& info, u32 param);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    void setFallLimit(f32 fallLimig);
    MtVector3 getAdustPos();
    void resetLastNormal();
    bool isHitLandOld() const;
    bool isHitLand() const;
    void setSleep(bool slp);
    bool isSleep();
    void setEnableFall(bool IsFall);
    bool isEnableFall();
    cGroundAttrInfo& getGroundAttrInfoEff();
    cGroundAttrInfo& getGroundAttrInfoScr();
    cGroundAttrInfo& getGroundAttrInfoWaterDepth();
    void updateGroundInfo();
    void onLandCastConvex(f32 radius);
    void offLandCastConvex();
    void onNoAngleCapsule();
    void offNoAngleCapsule();
    u32 getResultHit() const;
    u32 getScrHitInfoHit() const;
    bool isAdjustSlopeHit() const;
public:
    MtCapsule mCap;  // offset: 0x50
    MtVector3 mSupportVector;  // offset: 0x80
    MtVector3 mHitNormal;  // offset: 0x90
    uDDOModel* mpModel;  // offset: 0xa0
    cDelegate_0<void> callbackHitLand;  // offset: 0xa8
    cDelegate_0<void> callbackFall;  // offset: 0xc0
    cDelegate_1<void, cWallHitInfo&> callbackHitWall_Init;  // offset: 0xd8
    cDelegate_1<void, cWallHitInfo&> callbackHitWall_Move;  // offset: 0xf0
    cDelegate_1<void, cWallHitInfo&> callbackHitWall_Final;  // offset: 0x108
private:
    f32 mFallLimit;  // offset: 0x120
    f32 mLastNormal;  // offset: 0x124
    u32 mFlag;  // offset: 0x128
    bool mIsHitLandOld;  // offset: 0x12c
    bool mIsHitWallOld;  // offset: 0x12d
    bool mIsHitCeilingOld;  // offset: 0x12e
    bool mIsHitLand;  // offset: 0x12f
    bool mIsHitWall;  // offset: 0x130
    bool mIsHitCeiling;  // offset: 0x131
    bool mIsEnableFall;  // offset: 0x132
    bool mIsLandCastConvex;  // offset: 0x133
    bool mIsNoAngleCapsule;  // offset: 0x134
    bool mIsAdjustSlopeHit;  // offset: 0x135
    u32 mResult;  // offset: 0x138
    u32 mFilter;  // offset: 0x13c
    u32 mScrtHitAttr;  // offset: 0x140
    u32 mScrHitInfoHit;  // offset: 0x144
    f32 mCastConvexSphereRadius;  // offset: 0x148
    bool mIsSleep;  // offset: 0x14c
    u32 mScrAdjustAttribute;  // offset: 0x150
    cGroundAttrInfo mGroundAttrInfoEff;  // offset: 0x160
    cGroundAttrInfo mGroundAttrInfoScr;  // offset: 0x280
    cGroundAttrInfo mGroundAttrInfoWaterDepth;  // offset: 0x3a0
    MtVector3 mAdjustPos;  // offset: 0x4c0
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 cpScrCollision::getFilter() {
    return this->mFilter;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cpScrCollision::isHitLand() const {
    return this->mIsHitLand;
}
