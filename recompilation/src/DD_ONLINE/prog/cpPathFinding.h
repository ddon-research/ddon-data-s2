#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cAIRouteInfo.h"
#include "cpComponent.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cAINavPathTrace;
class cAIRouteInfo;
class cAIRouteInfoParts;
class uDDOModel;

// Declarations
class cpPathFinding;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cRouteInfoIDFlag = nDDOUtility::cBitSet<7>;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpPathFinding : public cpComponent
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
    cpPathFinding();
    virtual ~cpPathFinding();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    void setTraceRange(f32 range);
    cAINavPathTrace* getNavigationMesh();
    u32 trace(const MtVector3& TargetPos, MtVector3& NextPos, f32& NextDir);
    u32 traceCore(const MtVector3& TargetPos, MtVector3& NextPos, f32& NextDir);
    u32 getTraceResult();
    f32 getTraceRange();
    u32 getRouteInfo(MtVector3* pDstOfsPos, f32* pDstDir, f32 dis) const;
    void setRouteInfoParam(f32 jumpDis, f32 climbHeight, f32 dismountHeight);
    void clearRouteInfo();
    const cAIRouteInfoParts* searchTargetRoteInfo(u32 routeInfoID);
    u32 getCurrentNodeIndex() const;
    cRouteInfoIDFlag& checkRouteInfoID();
    f32 getClimbHeight() const;
    f32 getDismountHeight() const;
    f32 getJumpDistance() const;
    f32 getTraceLength();
    bool isRouteInfo() const;
    bool isTraceLink(const MtVector3& pos);
    void setOnAimGrand(bool on);
    void setOnFloatEnemy(bool on);
    void setAutoBackCheck(bool on);
    const MtVector3& getTargetRealPos();
    void setRouteForceUpdateOn();
protected:
    uDDOModel* mpModel;  // offset: 0x50
    cAINavPathTrace* mpNavTrace;  // offset: 0x58
    f32 mMeshUpdateFrame;  // offset: 0x60
    f32 mTraceRange;  // offset: 0x64
    f32 mTraceEndRange;  // offset: 0x68
    f32 mTimer;  // offset: 0x6c
    u32 mUseMeshUID;  // offset: 0x70
    u32 mTraceResult;  // offset: 0x74
    u32 mOldResult;  // offset: 0x78
    bool mOnAimGrand;  // offset: 0x7c
    bool mOnFloatEnemy;  // offset: 0x7d
    bool mForceUpdate;  // offset: 0x7e
    bool mAutoBackCheck;  // offset: 0x7f
    MtVector3 mOldTargetRealPos;  // offset: 0x80
    MtVector3 mOldOwnerRealPos;  // offset: 0x90
    MtVector3 mTraceTargetRealPos;  // offset: 0xa0
    MtVector3 mOldNextRealPos;  // offset: 0xb0
    f32 mOldDir;  // offset: 0xc0
    f32 mOldLength;  // offset: 0xc4
    cAIRouteInfo mRouteInfo;  // offset: 0xc8
    f32 mClimbHeight;  // offset: 0xf0
    f32 mDismountHeight;  // offset: 0xf4
    f32 mJumpDistance;  // offset: 0xf8
    cRouteInfoIDFlag mCheckRouteInfoID;  // offset: 0xfc
public:
    static const f32 ROUTE_ENABLE_DISTANCE;
    static MyDTI DTI;
};

inline void* cpPathFinding::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline f32 cpPathFinding::getTraceRange() {
    return this->mTraceRange;
}
