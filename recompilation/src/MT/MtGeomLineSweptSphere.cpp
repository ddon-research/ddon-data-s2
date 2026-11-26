// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtGeomLineSweptSphere.h"
#include "MtAllocator.h"
#include "MtCollision.h"
#include "MtDTI.h"
#include "MtGeomCapsule.h"
#include "MtGeometry3D.h"
#include "MtMemoryAllocator.h"
#include "MtPrimitive3D.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtGeomLineSweptSphere::getDTI() const {
    return MtGeomLineSweptSphere::DTI;
}

void* MtGeomLineSweptSphere::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtGeomLineSweptSphere::DTI)->memAlloc(sz, align, MtGeomLineSweptSphere::DTI.mID);
}

inline void MtGeomLineSweptSphere::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(MtGeomLineSweptSphere::DTI)->memFree(p_addr);
}

MtGeomLineSweptSphere::~MtGeomLineSweptSphere() {
}

void MtGeomLineSweptSphere::createPropertyList(MtPropertyList& s) {
    this->MtGeomCapsule::createProperty(s);
}

__attribute__((weak)) bool MtGeomLineSweptSphere::isFind(const MtSphere& sphere, const MtVector3& v, MtContact* pContact) const {
    DDON_STUB("MtGeomLineSweptSphere::isFind")
    return {};
}

__attribute__((weak)) bool MtGeomLineSweptSphere::isFind(const MtCapsule& capsule, const MtVector3& v, MtContact* pContact) const {
    DDON_STUB("MtGeomLineSweptSphere::isFind")
    return {};
}

__attribute__((weak)) bool MtGeomLineSweptSphere::isFind(const MtAABB& aabb, const MtVector3& v, MtContact* pContact) const {
    DDON_STUB("MtGeomLineSweptSphere::isFind")
    return {};
}

__attribute__((weak)) bool MtGeomLineSweptSphere::isFind(const MtOBB& obb, const MtVector3& v, MtContact* pContact) const {
    DDON_STUB("MtGeomLineSweptSphere::isFind")
    return {};
}

__attribute__((weak)) bool MtGeomLineSweptSphere::isFind(const MtPlane& plane, const MtVector3& v, MtContact* pContact) const {
    DDON_STUB("MtGeomLineSweptSphere::isFind")
    return {};
}

__attribute__((weak)) bool MtGeomLineSweptSphere::isFind(const MtPlaneXZ& planeXZ, const MtVector3& v, MtContact* pContact) const {
    DDON_STUB("MtGeomLineSweptSphere::isFind")
    return {};
}

__attribute__((weak)) bool MtGeomLineSweptSphere::isFind(const MtTriangle& tri, const MtVector3& v, MtContact* pContact) const {
    DDON_STUB("MtGeomLineSweptSphere::isFind")
    return {};
}

__attribute__((weak)) bool MtGeomLineSweptSphere::isContact(const MtSphere& sphere, const MtVector3& v, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const {
    DDON_STUB("MtGeomLineSweptSphere::isContact")
    return {};
}

__attribute__((weak)) bool MtGeomLineSweptSphere::isContact(const MtCapsule& capsule, const MtVector3& v, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const {
    DDON_STUB("MtGeomLineSweptSphere::isContact")
    return {};
}

inline MtGeomLineSweptSphere::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtGeomLineSweptSphere::MyDTI MtGeomLineSweptSphere::DTI("MtGeomLineSweptSphere", &::MtGeomCapsule::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* MtGeomLineSweptSphere::MyDTI::newInstance() const {
    DDON_STUB("MtGeomLineSweptSphere::MyDTI::newInstance")
    return nullptr;
}

