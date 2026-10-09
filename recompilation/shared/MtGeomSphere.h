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

// Declarations
class MtGeomSphere;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class MtGeomSphere : public MtGeomConvex
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
    MtGeomSphere();
    MtGeomSphere(const MtSphere& sphere);
    // Address: 0x01b30f00 - 0x01b30f01 (1 bytes)
    virtual ~MtGeomSphere() {}
    virtual void load(MtDataReader& fin);  // vtable slot 6
    virtual void save(MtDataWriter& fout);  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void getBoundingAABB(MtAABB& aabb) const;  // vtable slot 8
    virtual void getBoundingSphere(MtSphere& sphere) const;  // vtable slot 9
    virtual bool isDegeneracy() const;  // vtable slot 10
    virtual void transform(const MtGeometry& input, const MtMatrix& transform_matrix);  // vtable slot 11
    virtual void copy(const MtGeometry& input);  // vtable slot 12
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
    virtual bool isContact(const MtSphere& sphere, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;  // vtable slot 47
    virtual bool isContact(const MtCapsule& capsule, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;  // vtable slot 48
    virtual MtVector3 getSupportConst(const MtVector3& v) const;  // vtable slot 51
    virtual MtVector3 getInternalPos() const;  // vtable slot 53
    virtual void setScale(f32 scale);  // vtable slot 56
    virtual void addPos(const MtVector3& pos);  // vtable slot 57
    static bool intersect(const MtSphere&, const MtVector3&);
    static bool intersect(const MtSphere&, const MtLine&);
    static bool intersect(const MtSphere&, const MtRay&);
    static bool intersect(const MtSphere&, const MtLineSegment&);
    static bool intersect(const MtSphere&, const MtSphere&);
    static bool intersect(const MtSphere&, const MtCapsule&);
    static bool intersect(const MtSphere&, const MtAABB&);
    static bool intersect(const MtSphere&, const MtOBB&);
    static bool intersect(const MtSphere&, const MtPlane&);
    static bool closest(const MtSphere&, const MtLine&, MtContact*, f32*);
    static bool closest(const MtSphere&, const MtRay&, MtContact*, f32*);
    static bool closest(const MtSphere&, const MtLineSegment&, MtContact*, f32*);
    static bool closest(const MtSphere&, const MtSphere&, MtContact*, MtContact*);
    static bool closest(const MtSphere&, const MtAABB&, MtContact*, MtContact*);
    static bool closest(const MtSphere&, const MtPlane&, MtContact*, MtContact*);
    static bool find(const MtSphere&, const MtSphere&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool find(const MtSphere&, const MtAABB&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool find(const MtSphere&, const MtOBB&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool find(const MtSphere&, const MtCapsule&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool find(const MtSphere&, const MtPlane&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool find(const MtSphere&, const MtTriangle&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool contact(const MtSphere&, const MtSphere&, const MtVector3&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool contact(const MtSphere&, const MtAABB&, const MtVector3&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool contact(const MtSphere&, const MtOBB&, const MtVector3&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool contact(const MtSphere&, const MtCapsule&, const MtVector3&, const MtVector3&, f32*, MtContact*, MtContact*);
    static bool contact(const MtSphere&, const MtTriangle&, const MtVector3&, const MtVector3&, f32*, MtContact*, MtContact*);
public:
    MtSphere mSphere;  // offset: 0x10
    static MyDTI DTI;
};
