#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollisionSimplexSolver.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
namespace MtCollisionUtil { class MtSimplexSolver; }
class MtColor;
struct MtContact;
class MtDTI;
class MtGeomConvex;
class MtLineSegment;
class MtRay;
class MtVector3;

// Declarations
class MtCollisionGjk;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class MtCollisionGjk : public MtObject
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
    MtCollisionGjk(f32 GjkEpsilon, u32 GjkLoopMax, f32 EpaEpsilon, f32 SimplexSolverEpsilon);
    // Address: 0x01b2a5e0 - 0x01b2a5e1 (1 bytes)
    virtual ~MtCollisionGjk() {}
    bool intersectLegacy(const MtGeomConvex&, const MtGeomConvex&);
    bool closestLegacy(const MtGeomConvex&, const MtGeomConvex&, MtContact*, MtContact*);
    bool find(const MtRay& ray, const MtGeomConvex& Geom1, f32* pLsToi, MtContact* pContact1);
    bool find(const MtLineSegment& ls, const MtGeomConvex& Geom1, f32* pLsToi, MtContact* pContact1);
    bool findLegacy(const MtGeomConvex&, const MtGeomConvex&, const MtVector3&, MtContact*, MtContact*);
    bool contactLegacy(const MtGeomConvex&, const MtGeomConvex&, const MtVector3&, const MtVector3&, MtContact*, MtContact*);
    bool calcTOI(const MtGeomConvex& Geom0, const MtGeomConvex& Geom1, const MtVector3& v0, MtContact* pContact0, MtContact* pContact1);
    bool calcTOI(const MtGeomConvex& Geom0, const MtGeomConvex& Geom1, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1);
    void setConvexA(MtGeomConvex*);
    void setConvexB(MtGeomConvex*);
    MtGeomConvex* getConvexA();
    MtGeomConvex* getConvexB();
    bool isEndGjkLoopFast(const MtVector3&, MtVector3&);
    bool isEndGjkLoop(const MtVector3& SeparateAxis, MtVector3& w, f32 epsilon);
    void testDrawPt(MtVector3&, MtColor);
    void testDrawLine(MtVector3&, MtVector3&, MtColor);
protected:
    void testDrawSolverVertex(MtCollisionUtil::MtSimplexSolver& solver, u32 LoopCount, const MtVector3& s);
public:
    MtCollisionUtil::MtSimplexSolver mSolver;  // offset: 0x10
    u32 mIteration;  // offset: 0x190
    f32 mEpsilon;  // offset: 0x194
    f32 mEpaEpsilon;  // offset: 0x198
    f32 mSimplexSolverEpsilon;  // offset: 0x19c
protected:
    MtGeomConvex* mpConvexA;  // offset: 0x1a0
    MtGeomConvex* mpConvexB;  // offset: 0x1a8
    MtVector3 mCachedSeparateAxis;  // offset: 0x1b0
public:
    static MyDTI DTI;
    static const f32 DEFAULT_EPSILON;
};
