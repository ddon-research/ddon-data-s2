#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../XFramework/cAIObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtVector3;
class cAINavPathTrace;
class cpPathFinding;

// Declarations
class cAIRouteInfo;
class cAIRouteInfoParts;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cAIRouteInfoParts : public cAIObject
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
    cAIRouteInfoParts();
    virtual ~cAIRouteInfoParts();
public:
    MtLineSegment mNodeEdgeBegin;  // offset: 0x10
    MtVector3 mNodeRealPosEnd;  // offset: 0x30
    u32 mNodeIndexBegin;  // offset: 0x40
    f32 mMinX;  // offset: 0x44
    f32 mMaxX;  // offset: 0x48
    f32 mMinZ;  // offset: 0x4c
    f32 mMaxZ;  // offset: 0x50
    u32 mRouteInfoID;  // offset: 0x54
    static MyDTI DTI;
};

class cAIRouteInfo : public cAIObject
{
    friend class cpPathFinding;
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
    cAIRouteInfo();
    virtual ~cAIRouteInfo();
    void clearRouteInfo();
    void addRouteInfo(cAINavPathTrace* pNavPath, u32 startAttr, u32 endAttr, u32 routeInfoID, bool isDistance);
    void endAddRouteInfo();
    u32 getRouteInfoTiming(MtVector3* pDstOfsPos, f32* pDstDir, const MtVector3& ownerOfsPos, f32 distance, f32 climbHeight) const;
    bool isRouteInfo() const;
    const cAIRouteInfoParts* searchTargetRoteInfo(u32 routeInfoID, u32 startNodeIdx);
    const cAIRouteInfoParts* searchTargetRoteInfoFromIndex(u32 nodeIdx);
private:
    MtTypedArray<cAIRouteInfoParts> mPartsInfo;  // offset: 0x8
public:
    static MyDTI DTI;
};

inline void* cAIRouteInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAIRouteInfoParts::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
