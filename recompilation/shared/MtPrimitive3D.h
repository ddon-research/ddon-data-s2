#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollisionMath.h"
#include "MtMath.h"

// Forward declarations
class MtAllocator;
namespace MtCollisionUtil { class MtRect3DC; }
namespace MtCollisionUtil { class MtSoaVector3; }
class MtColor;
struct MtFloat3;
struct MtFloat3A;
class MtMatrix;
class MtPoint;
class MtQuaternion;
class MtRect;
class MtVector2;
class MtVector3;
class MtVector4;

// Declarations
class MtAABB;
class MtAABB4;
class MtCapsule;
class MtCone;
class MtCylinder;
class MtEllipsoid;
class MtFrustum;
class MtLine;
class MtLineSegment;
class MtLineSegment4;
class MtOBB;
class MtPlane;
class MtPlaneXZ;
class MtRay;
class MtRayY;
class MtRect3D;
class MtRect3D_XZ;
class MtSphere;
class MtTorus;
class MtTriangle;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class MtAABB
{
public:
    MtAABB();
    MtAABB(const MtVector3& imin, const MtVector3& imax);
    MtAABB(const MtVector3* pvertex_list, u32 vertex_num);
    void setEmpty();
    void initialize(const MtVector3& _min, const MtVector3& _max);
    void getBoundingAABB(MtAABB& aabb) const;
    void getBoundingSphere(MtSphere& sphere) const;
    void getVertex(MtVector3* v) const;
    bool getVertex(MtVector3& vertex_out, u32 VoronoiID) const;
    bool setVertex(const MtVector3&, u32);
    bool getSurfaceVertex(MtVector3& p0, MtVector3& p1, MtVector3& p2, MtVector3& p3, u32 VoronoiID) const;
    void getEdge(MtLineSegment*) const;
    void getEdge(MtLineSegment*, MtVector3*) const;
    bool getEdge(MtLineSegment& edge_out, u32 VoronoiID) const;
    bool getEdge(MtVector3& p0, MtVector3& p1, u32 VoronoiID) const;
    MtVector3 getCenter() const;
    MtVector3 getExtent() const;
    MtVector3 getSize() const;
    MtPlane getSurfaceMinX() const;
    MtPlane getSurfaceMaxX() const;
    MtPlane getSurfaceMinY() const;
    MtPlane getSurfaceMaxY() const;
    MtPlane getSurfaceMinZ() const;
    MtPlane getSurfaceMaxZ() const;
    void getCandidateSurfaceAABB(const MtVector3& dir, MtVector3* SurfaceNormals, MtVector3& SurfaceDist) const;
    void getCandidateSurfaceAABBMirror(const MtVector3&, MtVector3*, MtVector3&) const;
    MtVector3 getSupport(const MtVector3& v) const;
    MtVector3 getSupportConst(const MtVector3& v) const;
    MtVector3 getInternalPos() const;
    void inflate(const MtVector3& v);
    void inflate(const MtAABB& a);
    void inflate(const MtSphere&);
    MtAABB getInflateAABB(const MtAABB& plus) const;
    void convertOBB(MtOBB& dest) const;
    MtAABB& operator=(const MtAABB& aabb);
    MtAABB operator+(const MtVector3& s) const;
    MtAABB& operator+=(const MtVector3& s);
    MtAABB operator-(const MtVector3& s) const;
    MtAABB& operator-=(const MtVector3& s);
    bool operator==(const MtAABB& other) const;
    bool operator!=(const MtAABB&) const;
    operator MtVector3 *();
    operator const MtVector3 *() const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest) const;
    bool isSetIllegalValue() const;
    static MtAABB getMergeAABB(const MtAABB& aabbA, const MtAABB& aabbB);
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtVector3 minpos;  // offset: 0x0
    MtVector3 maxpos;  // offset: 0x10
    static const MtAABB Empty;
    static const MtAABB Zero;
    static const u32 VERTEX_NUM = 8;
    static const u32 EDGE_NUM = 12;
    static const u32 PLANE_NUM = 6;
};

class MtAABB4
{
public:
    MtAABB4();
    MtAABB4(const MtAABB&);
    MtAABB4(const MtAABB&, const MtAABB&, const MtAABB&, const MtAABB&);
    MtAABB4(const MtAABB4&, u32);
    void initialize(const MtAABB& aabb);
    void initialize(const MtAABB& aabb0, const MtAABB& aabb1, const MtAABB& aabb2, const MtAABB& aabb3);
    void initialize(const MtAABB4&, u32);
    void initialize(const MtAABB&, u32);
    void getBoundingAABB(MtAABB& aabb) const;
    void getBoundingSphere(MtSphere& sphere) const;
    void setAABB(const MtAABB&, u32);
    MtAABB getAABB(u32 id) const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor c0, MtColor c1, MtColor c2, MtColor c3, bool ztest) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtCollisionUtil::MtSoaVector3 minpos4;  // offset: 0x0
    MtCollisionUtil::MtSoaVector3 maxpos4;  // offset: 0x30
};

class MtCapsule
{
public:
    MtCapsule();
    MtCapsule(const MtVector3& ip0, const MtVector3& ip1, const f32 ir);
    void initialize(const MtVector3& ip0, const MtVector3& ip1, const f32 ir);
    void getBoundingAABB(MtAABB& aabb) const;
    void getBoundingSphere(MtSphere& sphere) const;
    void getAxis(MtLineSegment&);
    const MtLineSegment& getAxisFast() const;
    MtSphere getSpherePoint0() const;
    MtSphere getSpherePoint1() const;
    f32 getRadiusByFloat() const;
    MtVector3 getRadiusByVector3() const;
    MtVector4 getRadiusByVector4() const;
    f32 getCapSurfaceAxisPos(const MtVector3& SurfacePos) const;
    MtVector3 getSupport(const MtVector3& v) const;
    MtVector3 getSupportConst(const MtVector3& v) const;
    MtVector3 getInternalPos() const;
    MtCapsule transform(const MtMatrix& mat) const;
    MtCapsule transformPos(const MtMatrix& mat) const;
    MtCapsule transformCoord(const MtMatrix&) const;
    MtCapsule& operator=(const MtCapsule& capsule);
    MtCapsule operator+(const MtVector3& s) const;
    MtCapsule& operator+=(const MtVector3& s);
    MtCapsule operator-(const MtVector3& s) const;
    MtCapsule& operator-=(const MtVector3&);
    MtCapsule operator*(f32) const;
    MtCapsule& operator*=(f32 scale);
    operator MtVector3 *();
    operator const MtVector3 *() const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor c, bool ztest, u32 div, u32 divu) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtVector3 p0;  // offset: 0x0
    MtVector3 p1;  // offset: 0x10
    f32 r;  // offset: 0x20
};

class MtCone
{
public:
    MtCone();
    MtCone(const MtVector3& ip0, const f32 ir0, const MtVector3& ip1, const f32 ir1);
    MtCone(const MtVector3& top, const MtVector3& bottom, const f32 angle);
    void debugDraw(const MtColor c, bool ztest, const u32 div) const;
public:
    MtFloat3A p0;  // offset: 0x0
    f32 r0;  // offset: 0xc
    MtFloat3A p1;  // offset: 0x10
    f32 r1;  // offset: 0x1c
};

class MtCylinder
{
public:
    MtCylinder();
    MtCylinder(const MtCylinder& c);
    MtCylinder(const MtVector3& ip0, const MtVector3& ip1, const f32 ir);
    MtCylinder(const MtVector3& ip0, const f32 ir, const f32 ih);
    void initialize(const MtVector3& ip0, const MtVector3& ip1, const f32 ir);
    void getBoundingAABB(MtAABB& aabb) const;
    void getBoundingSphere(MtSphere& sphere) const;
    const MtLineSegment& getAxisFast() const;
    f32 getHeight() const;
    MtVector3 getSupport(const MtVector3& v) const;
    MtVector3 getSupportConst(const MtVector3& v) const;
    MtVector3 getInternalPos() const;
    MtCylinder transform(const MtMatrix& matrix) const;
    MtCylinder transformPos(const MtMatrix&) const;
    MtCylinder transformCoord(const MtMatrix&) const;
    MtCylinder transformNormal(const MtMatrix&) const;
    MtCylinder operator+(const MtVector3& s) const;
    MtCylinder& operator+=(const MtVector3& s);
    MtCylinder operator-(const MtVector3& s) const;
    MtCylinder& operator-=(const MtVector3&);
    MtCylinder operator*(f32) const;
    MtCylinder& operator*=(f32 scale);
    operator MtVector3 *();
    operator const MtVector3 *() const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor c, bool ztest, u32 div, u32 divSide) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtVector3 p0;  // offset: 0x0
    MtVector3 p1;  // offset: 0x10
    f32 r;  // offset: 0x20
};

class MtEllipsoid
{
public:
    MtEllipsoid();
    MtEllipsoid(const MtVector3& ipos, const MtVector3& ir);
public:
    MtVector3 pos;  // offset: 0x0
    MtVector3 r;  // offset: 0x10
};

class MtLine
{
public:
    MtLine();
    MtLine(const MtLine& l);
    MtLine(const MtVector3& start, const MtVector3& end);
    void initialize(const MtVector3& start, const MtVector3& end);
    void initialize2(const MtVector3& start, const MtVector3& dirNormalized);
    MtVector3 getDir() const;
    MtVector3 getPos(const f32 t) const;
    MtVector3 getPos(const MtVector3&) const;
    MtLine& operator=(const MtLine& _line);
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest, f32 dirLen, u32 div) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtVector3 from;  // offset: 0x0
    MtVector3 dir;  // offset: 0x10
};

class MtLineSegment
{
public:
    MtLineSegment();
    MtLineSegment(const MtVector3& start, const MtVector3& end);
    MtLineSegment(const MtLineSegment& ls);
    void initialize(const MtVector3& start, const MtVector3& end);
    void getBoundingAABB(MtAABB& aabb) const;
    void getBoundingSphere(MtSphere& sphere) const;
    MtVector3 getDir() const;
    MtVector3 getDirNoNormalize() const;
    MtVector3 getPos(const f32 t) const;
    operator MtVector3 *();
    operator const MtVector3 *() const;
    MtVector3 getSupport(const MtVector3& v) const;
    MtVector3 getSupportConst(const MtVector3&) const;
    MtVector3 getInternalPos() const;
    MtLineSegment transform(const MtMatrix& matrix) const;
    MtLineSegment transformCoord(const MtMatrix&) const;
    MtLineSegment transformNormal(const MtMatrix&) const;
    MtLineSegment& operator=(const MtLineSegment& _ls);
    MtLineSegment operator+(const MtVector3& s) const;
    MtLineSegment& operator+=(const MtVector3& s);
    MtLineSegment operator-(const MtVector3& s) const;
    MtLineSegment& operator-=(const MtVector3& s);
    bool isDegeneracy(f32 epsilon) const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest, u32 div) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtVector3 p0;  // offset: 0x0
    MtVector3 p1;  // offset: 0x10
};

class MtLineSegment4
{
public:
    MtLineSegment4();
    MtLineSegment4(const MtLineSegment&);
    void getBoundingAABB(MtAABB& aabb) const;
    void getBoundingSphere(MtSphere& sphere) const;
    MtCollisionUtil::MtSoaVector3 getDirNoNormalize() const;
    MtLineSegment getLineSegment(u32 id) const;
    void setLineSegment(const MtLineSegment&, u32);
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color0, MtColor color1, MtColor color2, MtColor color3, bool ztest, u32 div) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtCollisionUtil::MtSoaVector3 p0_4;  // offset: 0x0
    MtCollisionUtil::MtSoaVector3 p1_4;  // offset: 0x30
};

class MtOBB
{
public:
    MtOBB();
    MtOBB(const MtVector3& iextent, const MtMatrix& icoord);
    MtOBB(MtVector3* pVertexList, const u32 num, bool optimize);
    void initialize(const MtOBB&);
    void initialize(const MtVector3& _extent, const MtMatrix& _coord);
    void initialize(const MtVector3&, const MtQuaternion&, const MtVector3&);
    void initialize(const MtVector3&, const MtVector3&, const MtVector3&);
    const MtMatrix& getMatrix() const;
    MtMatrix getMatrixInverse() const;
    const MtVector3& getPos() const;
    const MtVector3& getExtent() const;
    void getBoundingAABB(MtAABB& aabb) const;
    void getBoundingSphere(MtSphere& sphere) const;
    void getVertex(MtVector3* out) const;
    void getEdge(MtLineSegment*) const;
    void getEdge(MtLineSegment* edge_out, MtVector3* v) const;
    const MtVector3& getCenter() const;
    void getCandidateSurfaceOBB(const MtVector3& dir, MtVector3* SurfaceNormals, MtVector3& SurfaceDist) const;
    MtAABB getLocalAABB() const;
    MtVector3 getSupport(const MtVector3& v) const;
    MtVector3 getSupportConst(const MtVector3& v) const;
    MtVector3 getInternalPos() const;
    MtOBB transform(const MtMatrix& matrix) const;
    MtOBB transformFast(const MtMatrix& matrix) const;
    MtOBB& operator=(const MtOBB& obb);
    MtOBB operator+(const MtVector3& s) const;
    MtOBB& operator+=(const MtVector3& s);
    MtOBB operator-(const MtVector3& s) const;
    MtOBB& operator-=(const MtVector3&);
    MtOBB& operator*=(f32 scale);
    MtOBB operator*(f32) const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtMatrix coord;  // offset: 0x0
    MtVector3 extent;  // offset: 0x40
};

class alignas(16) MtPlane
{
public:
    MtPlane();
    MtPlane(const MtVector3& inormal, const MtVector3& p0);
    MtPlane(const MtVector3& inormal, f32 distance);
    MtPlane(const MtVector3& p0, const MtVector3& p1, const MtVector3& p2);
    MtPlane(f32 a, f32 b, f32 c, f32 d);
    MtPlane(const MtVector4& iv);
    void initialize(const MtVector3& inormal, const MtVector3& p0);
    void initialize(const MtVector3& inormal, f32 distance);
    void initialize(const MtVector3& p0, const MtVector3& p1, const MtVector3& p2);
    void initialize(f32 a, f32 b, f32 c, f32 d);
    void initialize(const MtVector4& iv);
    MtVector3 getNormal() const;
    const MtVector3& getNormalFast() const;
    f32 getDist() const;
    MtVector3 getDistByVector3() const;
    MtVector4 getDistByVector4() const;
    const MtPlane& operator=(const MtPlane& plane);
    operator MtVector4() const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest, f32 dirLen, u32 div) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtFloat3A normal;  // offset: 0x0
    f32 dist;  // offset: 0xc
};

class MtPlaneXZ
{
public:
    MtPlaneXZ();
    MtPlaneXZ(const MtVector3&);
    MtPlaneXZ(f32 PlaneHeight);
    void initialize(const MtVector3&);
    void initialize(f32 PlaneHeight);
    MtVector3 getNormal() const;
    const MtVector3& getNormalFast() const;
    f32 getDist() const;
    static f32 calcDotWithNormal(const MtVector3& p);
    static f32 calcDotWithNormalMirror(const MtVector3& p);
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest, f32 dirLen, u32 div) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t);
    static void operator delete(void*);
    static void operator delete[](void*);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    f32 dist;  // offset: 0x0
};

class MtRay
{
public:
    MtRay();
    MtRay(const MtRay& r);
    MtRay(const MtVector3& ifrom, const MtVector3& idirNormalized);
    void initialize(const MtVector3& ifrom, const MtVector3& idir_normalized);
    void setPickRay(const MtPoint& scr_pos, const MtMatrix& matModelView, const MtMatrix& matProj, const MtRect& viewport);
    MtVector3 getDir() const;
    MtVector3 getPos(const f32 t) const;
    MtVector3 getPos(const MtVector3&) const;
    MtRay operator-() const;
    MtRay& operator=(const MtRay& ray);
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest, f32 dirLen, u32 div) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtVector3 from;  // offset: 0x0
    MtVector3 dir;  // offset: 0x10
};

class MtRayY
{
public:
    MtRayY();
    MtRayY(const MtRayY& r);
    MtRayY(const MtVector3& ifrom, f32 Direction);
    void initialize(const MtRayY& r);
    void initialize(const MtVector3& ifrom, f32 Direction);
    MtVector3 getDir() const;
    MtVector3 getPos(const f32 t) const;
    const MtVector3& getFrom() const;
    MtRayY operator-() const;
    MtRay convertRay(const MtMatrix* pTransformMatrix) const;
    void convertRay(MtRay& rayOutput, const MtMatrix* pTransformMatrix) const;
    MtRayY& operator=(const MtRayY& ray);
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest, f32 dirLen, u32 div) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t);
    static void operator delete(void*);
    static void operator delete[](void*);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtFloat3 from;  // offset: 0x0
    f32 dir;  // offset: 0xc
};

class MtRect3D
{
public:
    void initialize(const MtVector3& _normal, const MtVector3& _center, const MtVector2& _size);
    MtVector3 getVertexLT() const;
    MtVector3 getVertexLB() const;
    MtVector3 getVertexRT() const;
    MtVector3 getVertexRB() const;
    MtVector3 getEdgeDirectionLR() const;
    MtVector3 getEdgeDirectionTB() const;
    f32 getEdgeLengthLR() const;
    f32 getEdgeLengthTB() const;
    MtVector3 getEdgeNormalizedDirectionLR() const;
    MtVector3 getEdgeNormalizedDirectionTB() const;
    const MtVector3& getNormal() const;
    MtPlane getPlane() const;
    MtTriangle getTriangle0() const;
    MtTriangle getTriangle1() const;
    MtCollisionUtil::MtRect3DC convertRect3DCollision() const;
    const MtVector3& getCenter() const;
    const MtVector2 getSize() const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest, f32 NormalLength) const;
    static void* operator new(size_t);
    static void* operator new[](size_t);
    static void operator delete(void*);
    static void operator delete[](void*);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
protected:
    MtFloat3 normal;  // offset: 0x0
    f32 sizeW;  // offset: 0xc
    MtFloat3 center;  // offset: 0x10
    f32 sizeH;  // offset: 0x1c
};

class alignas(16) MtRect3D_XZ
{
public:
    void initialize(const MtVector2& center, const MtVector2& size, f32 _Height);
    void initialize(f32 l, f32 t, f32 r, f32 b, f32 _height);
    MtVector3 getSupport(const MtVector3& v) const;
    MtVector3 getSupportConst(const MtVector3& v) const;
    MtVector3 getInternalPos() const;
    operator MtVector2 *();
    operator const MtVector2 *() const;
    f32 getLeft() const;
    void setLeft(f32);
    f32 getTop() const;
    void setTop(f32);
    f32 getRight() const;
    void setRight(f32);
    f32 getBottom() const;
    void setBottom(f32);
    f32 getHeight() const;
    void setHeight(f32);
    const MtVector2& getLT() const;
    void setLT(const MtVector2&);
    const MtVector2& getLB() const;
    void setLB(const MtVector2&);
    const MtVector2& getRT() const;
    void setRT(const MtVector2&);
    const MtVector2& getRB() const;
    void setRB(const MtVector2&);
    MtVector3 getVertex3D_LT() const;
    MtVector3 getVertex3D_LB() const;
    MtVector3 getVertex3D_RT() const;
    MtVector3 getVertex3D_RB() const;
    const MtVector3& getNormal() const;
    MtPlane getPlane() const;
    MtTriangle getTriangle0() const;
    MtTriangle getTriangle1() const;
    MtVector2 getCenter() const;
    MtVector2 getSize() const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest, f32 NormalLength) const;
    static void* operator new(size_t);
    static void* operator new[](size_t);
    static void operator delete(void*);
    static void operator delete[](void*);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
protected:
    MtVector2 lt;  // offset: 0x0
    MtVector2 lb;  // offset: 0x8
    MtVector2 rt;  // offset: 0x10
    MtVector2 rb;  // offset: 0x18
    f32 height;  // offset: 0x20
};

class alignas(16) MtSphere
{
public:
    MtSphere();
    MtSphere(const MtVector3& ipos, f32 ir);
    MtSphere(const f32 ix, const f32 iy, const f32 iz, const f32 ir);
    MtSphere(const MtVector3*, const u32);
    void initialize(const MtVector3& ipos, const f32 ir);
    void initialize(const MtVector3&, const MtVector3&);
    void setPos(const MtVector3& ipos);
    void setRadius(f32 radius);
    void getBoundingAABB(MtAABB& aabb) const;
    void getBoundingSphere(MtSphere& sphere) const;
    MtVector3 getPos() const;
    const MtVector3& getPosFast() const;
    f32 getRadius() const;
    f32 getRadiusByFloat() const;
    MtVector3 getRadiusByVector3() const;
    MtVector4 getRadiusByVector4() const;
    MtVector3 getSupport(const MtVector3& v) const;
    MtVector3 getSupportConst(const MtVector3& v) const;
    MtVector3 getInternalPos() const;
    MtSphere transform(const MtMatrix& mat) const;
    MtSphere transformPos(const MtMatrix& mat) const;
    MtSphere transformCoord(const MtMatrix&) const;
    bool isDegeneracy() const;
    MtSphere& operator=(const MtVector3&);
    MtSphere& operator=(const MtSphere& s);
    MtSphere operator+(const MtVector3& add) const;
    MtSphere& operator+=(const MtVector3& add);
    MtSphere operator-(const MtVector3& sub) const;
    MtSphere& operator-=(const MtVector3&);
    MtSphere& operator*=(const f32 scale);
    MtSphere operator*(const f32) const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest, u32 div) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtFloat3A pos;  // offset: 0x0
    f32 r;  // offset: 0xc
};

class MtTorus
{
public:
    MtTorus();
    MtTorus(const MtVector3& ipos, const MtVector3& iaxis, const f32 ir, const f32 icr);
public:
    MtFloat3A pos;  // offset: 0x0
    f32 r;  // offset: 0xc
    MtFloat3A axis;  // offset: 0x10
    f32 cr;  // offset: 0x1c
};

class MtTriangle
{
public:
    MtTriangle();
    MtTriangle(const MtVector3& ip0, const MtVector3& ip1, const MtVector3& ip2);
    void initialize(const MtVector3& ip0, const MtVector3& ip1, const MtVector3& ip2);
    void getBoundingAABB(MtAABB& aabb) const;
    void getBoundingSphere(MtSphere& sphere) const;
    const MtVector3 getNormal() const;
    const MtVector3 getNormalFast() const;
    const MtVector3 getNormalReverse() const;
    const MtVector3 getNormalReverseFast() const;
    const MtVector3& getVertex(const u32) const;
    bool getVertexFromVID(MtVector3& vertex_out, const u32 vid) const;
    void getEdge(MtLineSegment& edge_out, u32 pt0, u32 pt1) const;
    void getEdge(MtLineSegment& edge_out, u32 EdgeID) const;
    bool getEdgeFromVID(MtLineSegment& edge_out, u32 vid) const;
    bool getEdgeFromVertexVID(MtLineSegment&, MtLineSegment&, u32) const;
    bool getNearestEdgeFromUVW(MtLineSegment& edge_out, MtVector3& NoEdgeVtxOut, u32 vid, f32 u, f32 v, f32 w) const;
    MtVector3 getPos(f32, f32, f32) const;
    MtVector3 getPos(const MtVector3& uvw) const;
    MtVector3 getCenterOfGravity() const;
    bool isDegeneracy() const;
    u32 getDegeneracyType(bool FlgDegenerateFoundEnd) const;
    MtVector3 getSupport(const MtVector3& v) const;
    MtVector3 getSupportConst(const MtVector3& v) const;
    MtVector3 getInternalPos() const;
    MtTriangle transform(const MtMatrix& matrix) const;
    MtTriangle transformCoord(const MtMatrix&) const;
    MtTriangle& operator=(const MtTriangle& tri);
    MtTriangle operator+(const MtVector3& s) const;
    MtTriangle& operator+=(const MtVector3& s);
    MtTriangle operator-(const MtVector3& s) const;
    MtTriangle& operator-=(const MtVector3&);
    MtTriangle& operator*=(const f32 scale);
    MtTriangle operator*(const f32) const;
    operator MtVector3 *();
    operator const MtVector3 *() const;
    void trace() const;
    void traceByWarning() const;
    void traceByError() const;
    void debugDraw(MtColor color, bool ztest) const;
    bool isSetIllegalValue() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
public:
    MtVector3 p0;  // offset: 0x0
    MtVector3 p1;  // offset: 0x10
    MtVector3 p2;  // offset: 0x20
    static const f32 MAX_EDGE_LENGTH;
    static const u32 DEGENERACY_NONE = 0;
    static const u32 DEGENERACY_EDGE_TOO_LONG = 1;
    static const u32 DEGENERACY_EDGE_TOO_SHORT = 2;
    static const u32 DEGENERACY_POINT = 4;
    static const u32 DEGENERACY_LINE = 8;
    static const u32 DEGENERACY_OVERFLOW = 16;
};

class MtFrustum
{
public:
    enum HIT_TYPE
    {
        HIT_OUTSIDE = 0,
        HIT_INSIDE = 1,
        HIT_INTERSECT = 2,
    };
    enum PLANE_TYPE
    {
        PLANE_BOTTOM = 0,
        PLANE_TOP = 1,
        PLANE_LEFT = 2,
        PLANE_RIGHT = 3,
        PLANE_NEAR = 4,
        PLANE_FAR = 5,
    };
public:
    MtFrustum();
    MtFrustum(f32 fov, f32 aspect_ratio, f32 nearz, f32 farz);
    MtFrustum(f32 fov, f32 aspect_ratio, f32 nearz);
    MtFrustum(MtPlane* plane);
    void transform(const MtMatrix& mat);
    u32 getPlaneNum() const;
    MtPlane getPlane(u32 index) const;
    HIT_TYPE isIntersect(const MtVector3& pos) const;
    HIT_TYPE isIntersect(const MtVector3& pos, f32 radius) const;
    HIT_TYPE isIntersect(const MtSphere& sphere) const;
    HIT_TYPE isIntersect(const MtAABB& aabb) const;
    HIT_TYPE isIntersect(const MtOBB& obb) const;
    static void* operator new(size_t);
    static void* operator new[](size_t);
    static void operator delete(void*);
    static void operator delete[](void*);
    static void* operator new(size_t, void*);
    static void* operator new[](size_t, void*);
    void* memAlloc(u32);
    void memFree(void*);
    static MtAllocator* getAllocator();
protected:
    void init(f32 fov, f32 aspect_ratio, f32 nearz, f32 farz);
protected:
    MtPlane planes[6];  // offset: 0x0
    bool infinite;  // offset: 0x60
};

// Inline, no code of its own: checked where it is inlined.
inline MtPlane::MtPlane() {
}
