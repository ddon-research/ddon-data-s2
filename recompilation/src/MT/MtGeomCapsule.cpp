// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtGeomCapsule.h"
#include "MtAllocator.h"
#include "MtCollision.h"
#include "MtDTI.h"
#include "MtDataReader.h"
#include "MtDataWriter.h"
#include "MtGeometry3D.h"
#include "MtMath.h"
#include "MtMemoryAllocator.h"
#include "MtPrimitive3D.h"
#include "MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtGeomCapsule::getDTI() const {
    return MtGeomCapsule::DTI;
}

void* MtGeomCapsule::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtGeomCapsule::DTI)->memAlloc(sz, align, MtGeomCapsule::DTI.mID);
}

void MtGeomCapsule::load(MtDataReader& fin) {
    mCapsule.p0.x = fin.readF32();
    mCapsule.p1.x = fin.readF32();
    mCapsule.p0.y = fin.readF32();
    mCapsule.p1.y = fin.readF32();
    mCapsule.p0.z = fin.readF32();
    mCapsule.p1.z = fin.readF32();
    mCapsule.p0.pad_ = fin.readF32();
    mCapsule.p1.pad_ = fin.readF32();
    mCapsule.r = fin.readF32();
}

void MtGeomCapsule::save(MtDataWriter& fout) {
    fout.writeF32(mCapsule.p0.x);
    fout.writeF32(mCapsule.p1.x);
    fout.writeF32(mCapsule.p0.y);
    fout.writeF32(mCapsule.p1.y);
    fout.writeF32(mCapsule.p0.z);
    fout.writeF32(mCapsule.p1.z);
    fout.writeF32(mCapsule.p0.pad_);
    fout.writeF32(mCapsule.p1.pad_);
    fout.writeF32(mCapsule.r);
}

__attribute__((weak)) void MtGeomCapsule::createProperty(MtPropertyList& s) {
    DDON_STUB("MtGeomCapsule::createProperty")
    /* stub */
}

__attribute__((weak)) void MtGeomCapsule::getBoundingAABB(MtAABB& aabb) const {
    DDON_STUB("MtGeomCapsule::getBoundingAABB")
    /* stub */
}

__attribute__((weak)) void MtGeomCapsule::getBoundingSphere(MtSphere& sphere) const {
    DDON_STUB("MtGeomCapsule::getBoundingSphere")
    /* stub */
}

__attribute__((weak)) void MtGeomCapsule::transform(const MtGeometry& input, const MtMatrix& transform_matrix) {
    DDON_STUB("MtGeomCapsule::transform")
    /* stub */
}

__attribute__((weak)) void MtGeomCapsule::copy(const MtGeometry& input) {
    DDON_STUB("MtGeomCapsule::copy")
    /* stub */
}

bool MtGeomCapsule::isIntersect(const MtVector3& pos) const {
    return MtCollision::intersect(mCapsule, pos);
}

bool MtGeomCapsule::isIntersect(const MtLine& line) const {
    return MtCollision::intersect(mCapsule, line);
}

bool MtGeomCapsule::isIntersect(const MtRay& ray) const {
    return MtCollision::intersect(mCapsule, ray);
}

bool MtGeomCapsule::isIntersect(const MtLineSegment& ls) const {
    return MtCollision::intersect(mCapsule, ls);
}

bool MtGeomCapsule::isIntersect(const MtSphere& sphere) const {
    return MtCollision::intersect(mCapsule, sphere);
}

bool MtGeomCapsule::isIntersect(const MtCapsule& capsule) const {
    return MtCollision::intersect(mCapsule, capsule);
}

bool MtGeomCapsule::isIntersect(const MtAABB& aabb) const {
    return MtCollision::intersect(mCapsule, aabb);
}

bool MtGeomCapsule::isIntersect(const MtOBB& obb) const {
    return MtCollision::intersect(mCapsule, obb);
}

bool MtGeomCapsule::isIntersect(const MtPlane& plane) const {
    return MtCollision::intersect(mCapsule, plane);
}

bool MtGeomCapsule::isIntersect(const MtPlaneXZ& planeXZ) const {
    return false;
}

bool MtGeomCapsule::isIntersect(const MtTriangle& tri) const {
    return MtCollision::intersect(tri, mCapsule);
}

bool MtGeomCapsule::isIntersect(const MtCylinder& cylinder) const {
    return MtCollision::intersect(cylinder, mCapsule);
}

bool MtGeomCapsule::getClosest(const MtVector3& pos, MtContact* pContact) const {
    return MtCollision::closest(mCapsule, pos, pContact);
}

bool MtGeomCapsule::getClosest(const MtLine& line, MtContact* pContact) const {
    return MtCollision::closest(mCapsule, line, pContact, static_cast<f32*>(nullptr));
}

bool MtGeomCapsule::getClosest(const MtRay& ray, MtContact* pContact) const {
    return MtCollision::closest(mCapsule, ray, pContact, static_cast<f32*>(nullptr));
}

bool MtGeomCapsule::getClosest(const MtLineSegment& ls, MtContact* pContact) const {
    return MtCollision::closest(mCapsule, ls, pContact, static_cast<f32*>(nullptr));
}

bool MtGeomCapsule::getClosest(const MtSphere& sphere, MtContact* pContact) const {
    return MtCollision::closest(mCapsule, sphere, pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::getClosest(const MtCapsule& capsule, MtContact* pContact) const {
    return MtCollision::closest(mCapsule, capsule, pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::getClosest(const MtAABB& aabb, MtContact* pContact) const {
    return MtCollision::closest(aabb, mCapsule, static_cast<MtContact*>(nullptr), pContact);
}

bool MtGeomCapsule::getClosest(const MtOBB& obb, MtContact* pContact) const {
    return MtCollision::closest(obb, mCapsule, static_cast<MtContact*>(nullptr), pContact);
}

bool MtGeomCapsule::getClosest(const MtPlane& plane, MtContact* pContact) const {
    return MtCollision::closest(mCapsule, plane, pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::getClosest(const MtPlaneXZ& planeXZ, MtContact* pContact) const {
    return false;
}

bool MtGeomCapsule::getClosest(const MtTriangle& tri, MtContact* pContact) const {
    return MtCollision::closest(tri, mCapsule, static_cast<MtContact*>(nullptr), pContact);
}

bool MtGeomCapsule::getClosestXZ(const MtSphere& sphere, MtContact* pContact) const {
    return MtCollision::closestXZ(mCapsule, sphere, pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::getClosestXZ(const MtCapsule& capsule, MtContact* pContact) const {
    return MtCollision::closestXZ(mCapsule, capsule, pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::getClosestXZ(const MtAABB& aabb, MtContact* pContact) const {
    return MtCollision::closestXZ(mCapsule, aabb, pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::getClosestXZ(const MtOBB& obb, MtContact* pContact) const {
    return MtCollision::closestXZ(mCapsule, obb, pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::isFind(const MtSphere& sphere, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mCapsule, sphere, v, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::isFind(const MtCapsule& capsule, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mCapsule, capsule, v, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::isFind(const MtAABB& aabb, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mCapsule, aabb, v, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::isFind(const MtOBB& obb, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mCapsule, obb, v, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::isFind(const MtPlane& plane, const MtVector3& v, MtContact* pContact) const {
    return false;
}

bool MtGeomCapsule::isFind(const MtPlaneXZ& planeXZ, const MtVector3& v, MtContact* pContact) const {
    return false;
}

bool MtGeomCapsule::isFind(const MtTriangle& tri, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mCapsule, tri, v, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomCapsule::isContact(const MtSphere& sphere, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const {
    return MtCollision::contact(mCapsule, sphere, v0, v1, static_cast<f32*>(nullptr), pContact0, pContact1);
}

bool MtGeomCapsule::isContact(const MtCapsule& capsule, const MtVector3& v0, const MtVector3& v1, MtContact* pContact0, MtContact* pContact1) const {
    return MtCollision::contact(mCapsule, capsule, v0, v1, static_cast<f32*>(nullptr), pContact0, pContact1);
}

__attribute__((weak)) MtVector3 MtGeomCapsule::getSupportConst(const MtVector3& v) const {
    DDON_STUB("MtGeomCapsule::getSupportConst")
    __builtin_unreachable();
}

MtVector3 MtGeomCapsule::getInternalPos() const {
    MtVector3 result;
    const f32 t0 = mCapsule.p0.y;
    const f32 t1 = mCapsule.p1.y;
    const f32 t2 = mCapsule.p1.z;
    const f32 t3 = mCapsule.p0.z;
    result.x = mCapsule.p0.x + (0.5f * (mCapsule.p1.x - mCapsule.p0.x));
    result.y = t0 + (0.5f * (t1 - t0));
    result.z = t3 + (0.5f * (t2 - t3));
    result.pad_ = 0.0f;
    return result;
}

void MtGeomCapsule::setScale(f32 scale) {
    mCapsule.p0.x = mCapsule.p0.x * scale;
    mCapsule.p0.y = mCapsule.p0.y * scale;
    mCapsule.p0.z = mCapsule.p0.z * scale;
    mCapsule.p1.x = mCapsule.p1.x * scale;
    mCapsule.p1.y = mCapsule.p1.y * scale;
    mCapsule.p1.z = mCapsule.p1.z * scale;
    mCapsule.r = mCapsule.r * scale;
}

void MtGeomCapsule::addPos(const MtVector3& pos) {
    mCapsule.p0.x = pos.x + mCapsule.p0.x;
    mCapsule.p0.y = pos.y + mCapsule.p0.y;
    mCapsule.p0.z = pos.z + mCapsule.p0.z;
    mCapsule.p1.x = pos.x + mCapsule.p1.x;
    mCapsule.p1.y = pos.y + mCapsule.p1.y;
    mCapsule.p1.z = pos.z + mCapsule.p1.z;
}

inline MtGeomCapsule::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtGeomCapsule::MyDTI MtGeomCapsule::DTI("MtGeomCapsule", &::MtGeomConvex::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* MtGeomCapsule::MyDTI::newInstance() const {
    DDON_STUB("MtGeomCapsule::MyDTI::newInstance")
    return nullptr;
}

