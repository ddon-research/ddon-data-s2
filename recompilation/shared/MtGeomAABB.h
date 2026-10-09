#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtGeometry3D.h"
#include "MtPrimitive3D.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCapsule;
struct MtContact;
class MtCylinder;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtGeometry;
class MtLine;
class MtLineSegment;
class MtOBB;
class MtObject;
class MtPlane;
class MtPlaneXZ;
class MtPropertyList;
class MtRay;
class MtSphere;
class MtTriangle;
class MtVector3;

// Declarations
class MtGeomAABB;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class MtGeomAABB : public MtGeomConvex
{
public:
    enum AABB_VORONOI_ID
    {
        X_MIN_BIT = 1,
        X_MAX_BIT = 2,
        Y_MIN_BIT = 4,
        Y_MAX_BIT = 8,
        Z_MIN_BIT = 16,
        Z_MAX_BIT = 32,
        AABB_VORONOI_INTERNAL = 0,
        AABB_VORONOI_P_YZX0 = 1,
        AABB_VORONOI_P_YZX1 = 2,
        AABB_VORONOI_P_ZXY0 = 4,
        AABB_VORONOI_P_ZXY1 = 8,
        AABB_VORONOI_P_XYZ0 = 16,
        AABB_VORONOI_P_XYZ1 = 32,
        AABB_VORONOI_E_XY0Z0 = 20,
        AABB_VORONOI_E_XY1Z0 = 24,
        AABB_VORONOI_E_XY0Z1 = 36,
        AABB_VORONOI_E_XY1Z1 = 40,
        AABB_VORONOI_E_YZ0X0 = 17,
        AABB_VORONOI_E_YZ1X0 = 33,
        AABB_VORONOI_E_YZ0X1 = 18,
        AABB_VORONOI_E_YZ1X1 = 34,
        AABB_VORONOI_E_ZX0Y0 = 5,
        AABB_VORONOI_E_ZX1Y0 = 6,
        AABB_VORONOI_E_ZX0Y1 = 9,
        AABB_VORONOI_E_ZX1Y1 = 10,
        AABB_VORONOI_V_X0Y0Z0 = 21,
        AABB_VORONOI_V_X1Y0Z0 = 22,
        AABB_VORONOI_V_X0Y1Z0 = 25,
        AABB_VORONOI_V_X1Y1Z0 = 26,
        AABB_VORONOI_V_X0Y0Z1 = 37,
        AABB_VORONOI_V_X1Y0Z1 = 38,
        AABB_VORONOI_V_X0Y1Z1 = 41,
        AABB_VORONOI_V_X1Y1Z1 = 42,
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
    MtGeomAABB();
    MtGeomAABB(const MtAABB& _aabb);
    MtGeomAABB(const MtVector3& _minpos, const MtVector3& _maxpos);
    // Address: 0x01be3e90 - 0x01be3e91 (1 bytes)
    virtual ~MtGeomAABB() {}
    virtual void load(MtDataReader& fin);  // vtable slot 6
    virtual void save(MtDataWriter& fout);  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void getBoundingAABB(MtAABB& aabb) const;  // vtable slot 8
    virtual void getBoundingSphere(MtSphere& sphere) const;  // vtable slot 9
    virtual bool isIntersect(const MtVector3& pos) const;  // vtable slot 13
    virtual bool isIntersect(const MtLine& line) const;  // vtable slot 14
    virtual bool isIntersect(const MtRay& ray) const;  // vtable slot 15
    virtual bool isIntersect(const MtLineSegment& ls) const;  // vtable slot 16
    virtual bool isIntersect(const MtSphere& sphere) const;  // vtable slot 17
    virtual bool isIntersect(const MtCapsule& capsule) const;  // vtable slot 18
    virtual bool isIntersect(const MtAABB& aabb) const;  // vtable slot 19
    virtual bool isIntersect(const MtOBB& obb) const;  // vtable slot 20
    virtual bool isIntersect(const MtPlane& plane) const;  // vtable slot 21
    virtual bool isIntersect(const MtPlaneXZ& planeXZ) const;  // vtable slot 22
    virtual bool isIntersect(const MtTriangle& tri) const;  // vtable slot 23
    virtual bool isIntersect(const MtCylinder& cylinder) const;  // vtable slot 24
    virtual bool getClosest(const MtVector3& pos, MtContact* pContact) const;  // vtable slot 25
    virtual bool getClosest(const MtLine& line, MtContact* pContact) const;  // vtable slot 26
    virtual bool getClosest(const MtRay& ray, MtContact* pContact) const;  // vtable slot 27
    virtual bool getClosest(const MtLineSegment& ls, MtContact* pContact) const;  // vtable slot 28
    virtual bool getClosest(const MtSphere& sphere, MtContact* pContact) const;  // vtable slot 29
    virtual bool getClosest(const MtCapsule& capsule, MtContact* pContact) const;  // vtable slot 30
    virtual bool getClosest(const MtAABB& aabb, MtContact* pContact) const;  // vtable slot 31
    virtual bool getClosest(const MtOBB& obb, MtContact* pContact) const;  // vtable slot 32
    virtual bool getClosest(const MtPlane& plane, MtContact* pContact) const;  // vtable slot 33
    virtual bool getClosest(const MtPlaneXZ& planeXZ, MtContact* pContact) const;  // vtable slot 34
    virtual bool getClosest(const MtTriangle& tri, MtContact* pContact) const;  // vtable slot 35
    virtual bool getClosestXZ(const MtSphere& sphere, MtContact* pContact) const;  // vtable slot 36
    virtual bool getClosestXZ(const MtCapsule& capsule, MtContact* pContact) const;  // vtable slot 37
    virtual bool getClosestXZ(const MtAABB& aabb, MtContact* pContact) const;  // vtable slot 38
    virtual bool getClosestXZ(const MtOBB& obb, MtContact* pContact) const;  // vtable slot 39
    virtual bool isFind(const MtSphere& sphere, const MtVector3& v, MtContact* pContact) const;  // vtable slot 40
    virtual bool isFind(const MtCapsule& capsule, const MtVector3& v, MtContact* pContact) const;  // vtable slot 41
    virtual bool isFind(const MtAABB& aabb, const MtVector3& v, MtContact* pContact) const;  // vtable slot 42
    virtual bool isFind(const MtOBB& obb, const MtVector3& v, MtContact* pContact) const;  // vtable slot 43
    virtual bool isFind(const MtPlane& plane, const MtVector3& v, MtContact* pContact) const;  // vtable slot 44
    virtual bool isFind(const MtPlaneXZ& planeXZ, const MtVector3& v, MtContact* pContact) const;  // vtable slot 45
    virtual bool isFind(const MtTriangle& tri, const MtVector3& v, MtContact* pContact) const;  // vtable slot 46
    virtual MtVector3 getSupportConst(const MtVector3& v) const;  // vtable slot 51
    virtual MtVector3 getInternalPos() const;  // vtable slot 53
    virtual void addPos(const MtVector3& pos);  // vtable slot 57
    virtual void copy(const MtGeometry& input);  // vtable slot 12
    static f32 sqrDistance(const MtAABB& aabb, const MtVector3& pos);
    static f32 sqrDistance(const MtAABB&, const MtLine&);
    static f32 sqrDistance(const MtAABB&, const MtLine&, f32*);
    static f32 sqrDistance(const MtAABB&, const MtRay&);
    static f32 sqrDistance(const MtAABB&, const MtRay&, f32*);
    static f32 sqrDistance(const MtAABB&, const MtLineSegment&);
    static f32 sqrDistance(const MtAABB&, const MtLineSegment&, f32*);
    static f32 sqrDistance(const MtAABB&, const MtAABB&);
    static bool intersect(const MtAABB& aabb, const MtVector3& pos);
    static bool intersect(const MtAABB&, const MtLine&);
    static bool intersect(const MtAABB&, const MtLine&, f32*);
    static bool intersect(const MtAABB&, const MtRay&);
    static bool intersect(const MtAABB&, const MtRay&, f32*);
    static bool intersect(const MtAABB&, const MtLineSegment&);
    static bool intersect(const MtAABB&, const MtLineSegment&, f32*);
    static bool intersect(const MtAABB& aabb, const MtSphere& sphere);
    static bool intersect(const MtAABB&, const MtCapsule&);
    static bool intersect(const MtAABB&, const MtAABB&);
    static bool intersect(const MtAABB&, const MtOBB&);
    static bool intersect(const MtAABB&, const MtPlane&);
    static bool closest(const MtAABB&, const MtVector3&, MtContact*);
    static bool closest(const MtAABB&, const MtLine&, MtContact*, f32*);
    static bool closest(const MtAABB&, const MtRay&, MtContact*, f32*);
    static bool closest(const MtAABB&, const MtLineSegment&, MtContact*, f32*);
    static bool closest(const MtAABB&, const MtCapsule&, MtContact*, MtContact*);
    static u32 getVoronoiId(const MtAABB& aabb, const MtVector3& pos);
    static f32 getMinimumDistSq(const MtAABB&, const MtLineSegment&, AABB_VORONOI_ID, f32*);
    static f32 getMinimumDistSq(const MtAABB&, const MtLine&, AABB_VORONOI_ID, f32*);
    static f32 getMinimumDistSq(const MtAABB&, const MtRay&, AABB_VORONOI_ID, f32*);
    static void getMinimumDistSqEdgeFlags(AABB_VORONOI_ID, bool*);
    static bool getMinimumDistSqEdge(const MtAABB&, MtLineSegment&, bool*, u32);
    static bool getAABBSurfaceRect(MtVector3& p0, MtVector3& p1, MtVector3& p2, MtVector3& p3, const MtAABB& aabb, u32 VoronoiID);
    static bool getAABBSurfaceTriangle(MtTriangle&, MtTriangle&, const MtAABB&, u32);
    static bool getAABBEdge(MtLineSegment& edge, const MtAABB& aabb, u32 VoronoiID);
    static u32 getAABBEdgeList(MtLineSegment*, const MtAABB&, u32);
    static bool getAABBVertex(MtVector3& pos, const MtAABB& aabb, u32 VoronoiID);
public:
    MtAABB mAABB;  // offset: 0x10
    static MyDTI DTI;
};
