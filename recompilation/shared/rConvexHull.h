#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtGeometry3D.h"
#include "MtMath.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtColor;
class MtDTI;
class MtGeometry;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class rConvexHull;

// Declarations
class cGeomConvexHull;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGeomConvexHull : public MtGeomConvex
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
    cGeomConvexHull();
    virtual ~cGeomConvexHull();
    virtual MtVector3 getSupportConst(const MtVector3& v) const;  // vtable slot 51
    virtual MtVector3 getSupport(const MtVector3& v);  // vtable slot 52
    virtual void getBoundingAABB(MtAABB& aabb) const;  // vtable slot 8
    virtual void getBoundingSphere(MtSphere& sphere) const;  // vtable slot 9
    virtual void transform(const MtGeometry& input, const MtMatrix& transform_matrix);  // vtable slot 11
    virtual void copy(const MtGeometry& input);  // vtable slot 12
    void setMatrix(const MtMatrix& mat);
    MtMatrix getMatrixCopy();
    const MtMatrix& getMatrix();
    const MtMatrix& getMatrixInv();
    void drawConvexHull(MtColor c, u32 attr) const;
    const cGeomConvexHull& operator=(const cGeomConvexHull& convex_hull);
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    rConvexHull* getResource();
    void setResource(rConvexHull* resource);
public:
    MtVector3 pos;  // offset: 0x10
    MtMatrix mMat;  // offset: 0x20
    MtMatrix mInvMat;  // offset: 0x60
    rConvexHull* mpCH;  // offset: 0xa0
    static MyDTI DTI;
};
