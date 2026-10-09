#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
class MtDTI;
class MtGeomConvex;
class MtMatrix;
class MtOBB;
class MtPropertyList;
class MtSphere;
class MtVector3;
class cCollGeom;
class cCollNode;
class cHitNode;
class cpObjCollisionBase;

// Declarations
class cGeomIterator;
class cHitGeom;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGeomIterator : public MtObject
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
    cGeomIterator();
    void begin(cpObjCollisionBase* pObjCollision, u32 attr);
    void next();
    bool isEnd();
    cHitGeom* getGeom();
private:
    void nextNode();
private:
    cHitNode* mpNode;  // offset: 0x8
    cHitGeom* mpGeom;  // offset: 0x10
    cpObjCollisionBase* mpObjCollision;  // offset: 0x18
    u32 mNodeIndex;  // offset: 0x20
    u32 mGeomIndex;  // offset: 0x24
    bool mIsEnd;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cHitGeom : public MtObject
{
public:
    enum InterpolateRno
    {
        NO_INTERPOLATE = 0,
        INTERPOLATE_INIT = 1,
        INTERPOLATE_MOVE = 2,
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
    cHitGeom();
    virtual ~cHitGeom();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    const MtSphere* getSphere() const;
    void setSphere(const MtSphere& sphere);
    const MtCapsule* getInterpolateCapsule() const;
    void setInterpolateCapsule(const MtCapsule& capsule);
    const MtCapsule* getCapsule() const;
    void setCapsule(const MtCapsule& capsule);
    const MtOBB* getOBB() const;
    void setOBB(const MtOBB& obb);
    void updateGeom();
    void updateRangeCheckMat();
    void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
    bool isInterpolate() const;
public:
    const cCollGeom* mpSrcGeom;  // offset: 0x8
    const cCollNode* mpSrcNode;  // offset: 0x10
    MtGeomConvex* mpGeom;  // offset: 0x18
    MtGeomConvex* mpGeomInter;  // offset: 0x20
    cpObjCollisionBase* mpObjCollision;  // offset: 0x28
    cHitNode* mpNode;  // offset: 0x30
    bool mIsActive;  // offset: 0x38
    u32 mInterpolate;  // offset: 0x3c
    MtMatrix mRangeCheckMat;  // offset: 0x40
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cGeomIterator::cGeomIterator() {
    this->mIsEnd = false;
    this->mNodeIndex = static_cast<u32>(0);
    this->mGeomIndex = static_cast<u32>(0);
    this->mpObjCollision = static_cast<cpObjCollisionBase*>(nullptr);
    this->mpGeom = static_cast<cHitGeom*>(nullptr);
    this->mpNode = static_cast<cHitNode*>(nullptr);
}
