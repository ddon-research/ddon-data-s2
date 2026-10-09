#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive3D.h"
#include "cSystem.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtLineSegment;
class MtMatrix;
class MtOBB;
class MtObject;
class MtPlane;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class cUnit;
class rOccluder;

// Declarations
class sOccluder;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sOccluder : public cSystem
{
public:
    class MyDTI;
    struct OcclusionInfo;
    struct BoundingBox;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct OcclusionInfo
    {
    public:
        u32 begin : 16;  // offset: 0x0
        u32 end : 16;  // offset: 0x0
    };
public:
    struct BoundingBox
    {
    public:
        MtVector3 x;  // offset: 0x0
        MtVector3 y;  // offset: 0x10
        MtVector3 z;  // offset: 0x20
        MtVector3 c;  // offset: 0x30
        MtVector3 w;  // offset: 0x40
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
    virtual ~sOccluder();
    static sOccluder* createInstance();
    static void deleteInstance();
    static sOccluder* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offse);  // vtable slot 9
    bool add(cUnit* punit);
    void del(cUnit* punit);
    virtual void reset();  // vtable slot 6
    u32 update(const MtMatrix& vp, const MtMatrix& vpi);
    bool isUseOccluder() const;
    void setUseOccluder(bool);
    bool isVisible(const MtSphere& sphere, u32 id);
    bool isVisible(const MtOBB& obb, u32 id);
    bool isVisible(const MtAABB& aabb, u32 id);
    bool isInvisible(const MtSphere& sphere, u32 id);
    bool isInvisible(const MtOBB& obb, u32 id);
    bool isInvisible(const MtAABB& aabb, u32 id);
    bool isInvisibleEx(const MtOBB& obb, u32 id);
    bool isVisibleEx(const MtOBB&, u32);
    bool isHit(const MtLineSegment& seg);
    u32 getDrawMode();
    void setDrawMode(u32);
    f32 getDiv();
    void setDiv(f32);
    bool getDebugEnable();
    void setDebugEnable(bool);
    bool getInflateEnable();
    void setInflateEnable(bool);
    void setWorldMatrix(const MtMatrix& world_matrix);
    void setResource(rOccluder* p_resource);
    rOccluder* getResource();
private:
    bool createFrustum(const MtMatrix& vp, const MtMatrix& vpi, const MtVector3* p_source, MtPlane* p_dest_frustum);
    u32 updateFrustum(const MtMatrix& vp, const MtMatrix& vpi);
    u32 updateFrustumEx(const MtMatrix& vp, const MtMatrix& vpi);
    void inflateFrustum(const MtPlane* p_target, const s32 state, MtVector3* p_source, MtPlane* p_source_frustum);
    bool isInvisibleEx(const BoundingBox& bb, u32 id, u32 depth, u32 mask);
    bool isInvisible(const BoundingBox& bb, u32 id, u32 mask);
    bool culling(const MtSphere& sphere, const MtPlane* p_plane);
    bool cullingOBB(const MtVector3& c, const MtVector3& x, const MtVector3& y, const MtVector3& z, const MtPlane* p_plane);
    bool cullingAABB(const MtVector3& c, const MtVector3& w, const MtPlane* p_plane);
    s32 cullingOBBState(const MtVector3& c, const MtVector3& x, const MtVector3& y, const MtVector3& z, const MtPlane* p_plane);
    s32 cullingAABBState(const MtVector3&, const MtVector3&, const MtPlane*);
    bool culling(const MtVector3* p_quad, MtPlane* p_plane);
    s32 cullingState(const MtVector3* p_quad, MtPlane* p_plane);
    s32 find(cUnit* punit);
public:
    sOccluder();
private:
    bool mUseOccluder;  // offset: 0x11
    bool mInflateOccluder;  // offset: 0x12
    bool mDebug;  // offset: 0x13
    f32 mDiv;  // offset: 0x14
    u32 mDrawMode;  // offset: 0x18
    u32 mUnitCount;  // offset: 0x1c
    cUnit* mpUnits[32];  // offset: 0x20
    u32 mInfoCount;  // offset: 0x120
    MtPlane mPlane[2048];  // offset: 0x130
    OcclusionInfo mInfo[120];  // offset: 0x8130
    MtMatrix mWorld;  // offset: 0x8310
    MtMatrix mOffset;  // offset: 0x8350
    rOccluder* mpOccluder;  // offset: 0x8390
public:
    static MyDTI DTI;
private:
    static const u32 MAX_UNIT = 32;
    static const u32 MAX_INFO = 120;
    static const u32 MAX_PLANE = 2048;
public:
    static sOccluder* mpInstance;
};
