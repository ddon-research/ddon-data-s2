#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtGeomCapsule.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCapsule;
struct MtContact;
class MtDTI;
class MtOBB;
class MtObject;
class MtPlane;
class MtPlaneXZ;
class MtPropertyList;
class MtSphere;
class MtTriangle;
class MtVector3;

// Declarations
class MtGeomLineSweptSphere;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class MtGeomLineSweptSphere : public MtGeomCapsule
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
    MtGeomLineSweptSphere();
    MtGeomLineSweptSphere(const MtCapsule&);
    MtGeomLineSweptSphere(const MtVector3&, const MtVector3&, f32);
    virtual ~MtGeomLineSweptSphere();
    virtual void createPropertyList(MtPropertyList& s);  // vtable slot 58
    virtual bool isFind(const MtSphere& sphere, const MtVector3& v, MtContact* pContact) const;  // vtable slot 40
    virtual bool isFind(const MtCapsule& capsule, const MtVector3& v, MtContact* pContact) const;  // vtable slot 41
    virtual bool isFind(const MtAABB& aabb, const MtVector3& v, MtContact* pContact) const;  // vtable slot 42
    virtual bool isFind(const MtOBB& obb, const MtVector3& v, MtContact* pContact) const;  // vtable slot 43
    virtual bool isFind(const MtPlane& plane, const MtVector3& v, MtContact* pContact) const;  // vtable slot 44
    virtual bool isFind(const MtPlaneXZ& planeXZ, const MtVector3& v, MtContact* pContact) const;  // vtable slot 45
    virtual bool isFind(const MtTriangle& tri, const MtVector3& v, MtContact* pContact) const;  // vtable slot 46
    virtual bool isContact(const MtSphere& sphere, const MtVector3& v, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;  // vtable slot 47
    virtual bool isContact(const MtCapsule& capsule, const MtVector3& v, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const;  // vtable slot 48
protected:
    MtSphere getCapsulePointSphere0();
    void setCapsulePointSphere0(const MtSphere& sphere);
    MtSphere getCapsulePointSphere1();
    void setCapsulePointSphere1(const MtSphere& sphere);
public:
    static MyDTI DTI;
};

inline void* MtGeomLineSweptSphere::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "MtAllocator.h"
#include "MtMemoryAllocator.h"

inline void MtGeomLineSweptSphere::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtGeomLineSweptSphere::DTI)->memFree(p_addr);
}
