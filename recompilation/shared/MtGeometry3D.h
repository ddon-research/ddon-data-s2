#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCapsule;
struct MtContact;
class MtCylinder;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtGeomAABB;
class MtGeomCapsule;
class MtGeomLine;
class MtGeomLineSegment;
class MtGeomOBB;
class MtGeomPlane;
class MtGeomPlaneXZ;
class MtGeomRay;
class MtGeomSphere;
class MtGeomTriangle;
class MtLine;
class MtLineSegment;
class MtMatrix;
class MtOBB;
class MtObject;
class MtPlane;
class MtPlaneXZ;
class MtPropertyList;
class MtRay;
class MtSphere;
class MtTriangle;
class MtVector3;
namespace nCollision { class cGeometry; }

// Declarations
class MtGeomConvex;
class MtGeometry;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class MtGeometry : public MtObject
{
    // inferred: nCollision::cGeometry::getGeometryType names MtGeometry::mType
    friend class nCollision::cGeometry;
public:
    enum Type
    {
        TYPE_NULL = 0,
        TYPE_LINE = 1,
        TYPE_LINESEGMENT = 2,
        TYPE_LINE_SEGMENT = 2,
        TYPE_RAY = 3,
        TYPE_PLANE = 4,
        TYPE_SPHERE = 5,
        TYPE_CAPSULE = 6,
        TYPE_AABB = 7,
        TYPE_OBB = 8,
        TYPE_CYLINDER = 9,
        TYPE_CONVEX_HULL = 10,
        TYPE_TRIANGLE = 11,
        TYPE_CONE = 12,
        TYPE_TORUS = 13,
        TYPE_ELLIPSOID = 14,
        TYPE_MINCOWSKI_SUM = 15,
        TYPE_MINCOWSKI_DIFF = 16,
        TYPE_LINE_SEGMENT4 = 17,
        TYPE_AABB4 = 18,
        TYPE_LINESWEPTSPHERE = 19,
        TYPE_PLANE_XZ = 20,
        TYPE_RAY_Y = 21,
        TYPE_NUM = 22,
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
    MtGeometry(Type type);
    virtual ~MtGeometry() {}
    virtual void load(MtDataReader& fin);  // vtable slot 6
    virtual void save(MtDataWriter& fout);  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void getBoundingAABB(MtAABB& aabb) const;  // vtable slot 8
    virtual void getBoundingSphere(MtSphere& sphere) const;  // vtable slot 9
    virtual bool isDegeneracy() const;  // vtable slot 10
    virtual void transform(const MtGeometry& input, const MtMatrix& transform_matrix);  // vtable slot 11
    virtual void copy(const MtGeometry& input);  // vtable slot 12
    Type getType() const;
    MT_CTSTR getTypeName() const;
    static void getBoundingAABB(MtGeometry& Geom, const MtVector3& PosOfs, const MtVector3& SpdOfs, MtAABB& aabbOut);
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
    virtual bool isIntersect(const MtCylinder& tri) const;  // vtable slot 24
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
    virtual bool isContact(const MtSphere& sphere, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;  // vtable slot 47
    virtual bool isContact(const MtCapsule& capsule, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;  // vtable slot 48
    bool isIntersect(const MtGeomLine& line) const;
    bool isIntersect(const MtGeomRay& ray) const;
    bool isIntersect(const MtGeomLineSegment& ls) const;
    bool isIntersect(const MtGeomSphere& sphereG) const;
    bool isIntersect(const MtGeomCapsule& capsuleG) const;
    bool isIntersect(const MtGeomAABB& aabbG) const;
    bool isIntersect(const MtGeomOBB& obbG) const;
    bool isIntersect(const MtGeomPlane& planeG) const;
    bool isIntersect(const MtGeomPlaneXZ& planeGXZ) const;
    bool isIntersect(const MtGeomTriangle& triG) const;
    bool getClosest(const MtGeomLine& line, MtContact* pContact) const;
    bool getClosest(const MtGeomRay& ray, MtContact* pContact) const;
    bool getClosest(const MtGeomLineSegment& ls, MtContact* pContact) const;
    bool getClosest(const MtGeomSphere& sphere, MtContact* pContact) const;
    bool getClosest(const MtGeomCapsule& capsule, MtContact* pContact) const;
    bool getClosest(const MtGeomAABB& aabb, MtContact* pContact) const;
    bool getClosest(const MtGeomOBB& obb, MtContact* pContact) const;
    bool getClosest(const MtGeomPlane& plane, MtContact* pContact) const;
    bool getClosest(const MtGeomTriangle& tri, MtContact* pContact) const;
    bool getClosestXZ(const MtGeomSphere& sphere, MtContact* pContact) const;
    bool getClosestXZ(const MtGeomCapsule& capsule, MtContact* pContact) const;
    bool getClosestXZ(const MtGeomAABB& aabb, MtContact* pContact) const;
    bool getClosestXZ(const MtGeomOBB& obb, MtContact* pContact) const;
    bool isFind(const MtGeomSphere& sphereG, const MtVector3& v, MtContact* pContact) const;
    bool isFind(const MtGeomCapsule& capsuleG, const MtVector3& v, MtContact* pContact) const;
    bool isFind(const MtGeomAABB& aabbG, const MtVector3& v, MtContact* pContact) const;
    bool isFind(const MtGeomOBB& obbG, const MtVector3& v, MtContact* pContact) const;
    bool isFind(const MtGeomPlane& planeG, const MtVector3& v, MtContact* pContact) const;
    bool isFind(const MtGeomTriangle& triG, const MtVector3& v, MtContact* pContact) const;
    bool isContact(const MtGeomSphere& sphere, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;
    bool isContact(const MtGeomCapsule& capsule, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;
    bool isIntersect(const MtGeometry& g) const;
    bool getClosest(const MtGeometry& g, MtContact* pContact) const;
    bool getClosestXZ(const MtGeometry& g, MtContact* pContact) const;
    bool isFind(const MtGeometry& g, const MtVector3& v, MtContact* pContact) const;
    bool isContact(const MtGeometry& g, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;
    bool isIntersectGeometry(const MtGeometry& g) const;
    bool getClosestGeometry(const MtGeometry& g, MtContact* pContact) const;
    bool getClosestXZGeometry(const MtGeometry& g, MtContact* pContact) const;
    bool isFindGeometry(const MtGeometry& g, const MtVector3& v, MtContact* pContact) const;
    bool isContactGeometry(const MtGeometry& g, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;
    void* memAlloc(size_t);
    void memFree(void*);
    size_t memSize(void*);
protected:
    u32 mType;  // offset: 0x8
public:
    static MyDTI DTI;
};

class MtGeomConvex : public MtGeometry
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
    MtGeomConvex(MtGeometry::Type type);
    virtual ~MtGeomConvex() {}
    virtual void load(MtDataReader& fin);  // vtable slot 6
    virtual void save(MtDataWriter& fout);  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtVector3 getSupportMarginConst(const MtVector3& v) const;  // vtable slot 49
    virtual MtVector3 getSupportMargin(const MtVector3& v);  // vtable slot 50
    virtual MtVector3 getSupportConst(const MtVector3& v) const;  // vtable slot 51
    virtual MtVector3 getSupport(const MtVector3& v);  // vtable slot 52
    virtual MtVector3 getInternalPos() const;  // vtable slot 53
    virtual void setMargin(f32 margin);  // vtable slot 54
    virtual f32 getMargin() const;  // vtable slot 55
    virtual void setScale(f32 scale);  // vtable slot 56
    virtual void addPos(const MtVector3& pos);  // vtable slot 57
    static void assertNonSupportConvex(u32 type);
protected:
    f32 mMargin;  // offset: 0xc
public:
    static MyDTI DTI;
    static f32 DISTANCE_DEFAULT_MARGIN;
};
