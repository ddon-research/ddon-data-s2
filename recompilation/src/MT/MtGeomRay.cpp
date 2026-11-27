// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtGeomRay.h"
#include "MtAllocator.h"
#include "MtCollision.h"
#include "MtDTI.h"
#include "MtDataReader.h"
#include "MtDataWriter.h"
#include "MtGeometry3D.h"
#include "MtMath.h"
#include "MtMemoryAllocator.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "MtProperty.h"
#include "MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtGeomRay::getDTI() const {
    return MtGeomRay::DTI;
}

void* MtGeomRay::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtGeomRay::DTI)->memAlloc(sz, align, MtGeomRay::DTI.mID);
}

void MtGeomRay::load(MtDataReader& fin) {
    mRay.from.x = fin.readF32();
    mRay.dir.x = fin.readF32();
    mRay.from.y = fin.readF32();
    mRay.dir.y = fin.readF32();
    mRay.from.z = fin.readF32();
    mRay.dir.z = fin.readF32();
    mRay.from.pad_ = fin.readF32();
    mRay.dir.pad_ = fin.readF32();
}

void MtGeomRay::save(MtDataWriter& fout) {
    fout.writeF32(mRay.from.x);
    fout.writeF32(mRay.dir.x);
    fout.writeF32(mRay.from.y);
    fout.writeF32(mRay.dir.y);
    fout.writeF32(mRay.from.z);
    fout.writeF32(mRay.dir.z);
    fout.writeF32(mRay.from.pad_);
    fout.writeF32(mRay.dir.pad_);
}

__attribute__((weak)) void MtGeomRay::createProperty(MtPropertyList& s) {
    DDON_STUB("MtGeomRay::createProperty")
    /* stub */
}

__attribute__((weak)) void MtGeomRay::copy(const MtGeometry& input) {
    mRay.from.x = static_cast<const MtGeomRay&>(input).mRay.from.x;
    mRay.from.y = static_cast<const MtGeomRay&>(input).mRay.from.y;
    mRay.from.z = static_cast<const MtGeomRay&>(input).mRay.from.z;
    mRay.from.pad_ = 0.0f;
    mRay.dir.x = static_cast<const MtGeomRay&>(input).mRay.dir.x;
    mRay.dir.y = static_cast<const MtGeomRay&>(input).mRay.dir.y;
    mRay.dir.z = static_cast<const MtGeomRay&>(input).mRay.dir.z;
    mRay.dir.pad_ = 0.0f;
}

bool MtGeomRay::isIntersect(const MtVector3& pos) const {
    return MtCollision::intersect(mRay, pos, 1.1920929e-7f);
}

bool MtGeomRay::isIntersect(const MtLine& line) const {
    return MtCollision::intersect(mRay, line, 1.1920929e-7f);
}

bool MtGeomRay::isIntersect(const MtRay& ray) const {
    return MtCollision::intersect(mRay, ray, 1.1920929e-7f);
}

bool MtGeomRay::isIntersect(const MtLineSegment& ls) const {
    return MtCollision::intersect(mRay, ls, 1.1920929e-7f);
}

bool MtGeomRay::isIntersect(const MtSphere& sphere) const {
    return MtCollision::intersect(sphere, mRay);
}

bool MtGeomRay::isIntersect(const MtCapsule& capsule) const {
    return MtCollision::intersect(capsule, mRay);
}

bool MtGeomRay::isIntersect(const MtAABB& aabb) const {
    return MtCollision::intersect(aabb, mRay);
}

bool MtGeomRay::isIntersect(const MtOBB& obb) const {
    return MtCollision::intersect(obb, mRay);
}

bool MtGeomRay::isIntersect(const MtPlane& plane) const {
    return MtCollision::intersect(mRay, plane);
}

bool MtGeomRay::isIntersect(const MtPlaneXZ& planeXZ) const {
    return false;
}

bool MtGeomRay::isIntersect(const MtTriangle& tri) const {
    return MtCollision::intersect(tri, mRay);
}

bool MtGeomRay::isIntersect(const MtCylinder& cylinder) const {
    return MtCollision::intersect(cylinder, mRay);
}

bool MtGeomRay::getClosest(const MtVector3& pos, MtContact* pContact) const {
    f32 t;
    f32 t1 = MtCollision::sqrDistance(mRay, pos, &t);
    if (pContact != nullptr) {
        float t2 = 1.1920929e-7f;
        f32 t3 = t;
        const f32 t4 = MtVector3::Zero.x;
        pContact->pos.x = t4;
        const f32 t5 = MtVector3::Zero.y;
        pContact->pos.y = t5;
        const f32 t6 = MtVector3::Zero.z;
        pContact->pos.z = t6;
        pContact->pos.pad_ = 0.0f;
        const f32 t7 = MtVector3::Zero.x;
        pContact->normal.x = t7;
        const f32 t8 = MtVector3::Zero.y;
        pContact->normal.y = t8;
        const f32 t9 = MtVector3::Zero.z;
        pContact->normal.z = t9;
        pContact->normal.pad_ = 0.0f;
        pContact->distance = 0.0f;
        pContact->toi = t3;
        pContact->bFind = t2 > t1;
        return 1.1920929e-7f > t1;
    } else {
        return 1.1920929e-7f > t1;
    }
}

bool MtGeomRay::getClosest(const MtLine& line, MtContact* pContact) const {
    float t0 = 0.001f;
    f32 t;
    f32 t2 = MtCollision::sqrDistance(mRay, line, &t, static_cast<f32*>(nullptr), t0);
    if (pContact != nullptr) {
        float t3 = 1.1920929e-7f;
        f32 t4 = t;
        const f32 t5 = MtVector3::Zero.x;
        pContact->pos.x = t5;
        const f32 t6 = MtVector3::Zero.y;
        pContact->pos.y = t6;
        const f32 t7 = MtVector3::Zero.z;
        pContact->pos.z = t7;
        pContact->pos.pad_ = 0.0f;
        const f32 t8 = MtVector3::Zero.x;
        pContact->normal.x = t8;
        const f32 t9 = MtVector3::Zero.y;
        pContact->normal.y = t9;
        const f32 t10 = MtVector3::Zero.z;
        pContact->normal.z = t10;
        pContact->normal.pad_ = 0.0f;
        pContact->distance = 0.0f;
        pContact->toi = t4;
        pContact->bFind = t3 > t2;
        return 1.1920929e-7f > t2;
    } else {
        return 1.1920929e-7f > t2;
    }
}

bool MtGeomRay::getClosest(const MtRay& ray, MtContact* pContact) const {
    float t0 = 0.001f;
    f32 t;
    f32 t2 = MtCollision::sqrDistance(mRay, ray, &t, static_cast<f32*>(nullptr), t0);
    if (pContact != nullptr) {
        float t3 = 1.1920929e-7f;
        f32 t4 = t;
        const f32 t5 = MtVector3::Zero.x;
        pContact->pos.x = t5;
        const f32 t6 = MtVector3::Zero.y;
        pContact->pos.y = t6;
        const f32 t7 = MtVector3::Zero.z;
        pContact->pos.z = t7;
        pContact->pos.pad_ = 0.0f;
        const f32 t8 = MtVector3::Zero.x;
        pContact->normal.x = t8;
        const f32 t9 = MtVector3::Zero.y;
        pContact->normal.y = t9;
        const f32 t10 = MtVector3::Zero.z;
        pContact->normal.z = t10;
        pContact->normal.pad_ = 0.0f;
        pContact->distance = 0.0f;
        pContact->toi = t4;
        pContact->bFind = t3 > t2;
        return 1.1920929e-7f > t2;
    } else {
        return 1.1920929e-7f > t2;
    }
}

bool MtGeomRay::getClosest(const MtLineSegment& ls, MtContact* pContact) const {
    float t0 = 0.001f;
    f32 t;
    f32 t2 = MtCollision::sqrDistance(mRay, ls, &t, static_cast<f32*>(nullptr), t0);
    if (pContact != nullptr) {
        float t3 = 1.1920929e-7f;
        f32 t4 = t;
        const f32 t5 = MtVector3::Zero.x;
        pContact->pos.x = t5;
        const f32 t6 = MtVector3::Zero.y;
        pContact->pos.y = t6;
        const f32 t7 = MtVector3::Zero.z;
        pContact->pos.z = t7;
        pContact->pos.pad_ = 0.0f;
        const f32 t8 = MtVector3::Zero.x;
        pContact->normal.x = t8;
        const f32 t9 = MtVector3::Zero.y;
        pContact->normal.y = t9;
        const f32 t10 = MtVector3::Zero.z;
        pContact->normal.z = t10;
        pContact->normal.pad_ = 0.0f;
        pContact->distance = 0.0f;
        pContact->toi = t4;
        pContact->bFind = t3 > t2;
        return 1.1920929e-7f > t2;
    } else {
        return 1.1920929e-7f > t2;
    }
}

__attribute__((weak)) bool MtGeomRay::getClosest(const MtSphere& sphere, MtContact* pContact) const {
    DDON_STUB("MtGeomRay::getClosest")
    return {};
}

__attribute__((weak)) bool MtGeomRay::getClosest(const MtCapsule& capsule, MtContact* pContact) const {
    DDON_STUB("MtGeomRay::getClosest")
    return {};
}

__attribute__((weak)) bool MtGeomRay::getClosest(const MtAABB& aabb, MtContact* pContact) const {
    DDON_STUB("MtGeomRay::getClosest")
    return {};
}

__attribute__((weak)) bool MtGeomRay::getClosest(const MtOBB& obb, MtContact* pContact) const {
    DDON_STUB("MtGeomRay::getClosest")
    return {};
}

bool MtGeomRay::getClosest(const MtPlane& plane, MtContact* pContact) const {
    f32 t;
    bool t0 = MtCollision::closest(mRay, plane, &t, static_cast<MtContact*>(nullptr));
    if (pContact != nullptr) {
        f32 t2 = t;
        const f32 t3 = MtVector3::Zero.x;
        pContact->pos.x = t3;
        const f32 t4 = MtVector3::Zero.y;
        pContact->pos.y = t4;
        const f32 t5 = MtVector3::Zero.z;
        pContact->pos.z = t5;
        pContact->pos.pad_ = 0.0f;
        const f32 t6 = MtVector3::Zero.x;
        pContact->normal.x = t6;
        const f32 t7 = MtVector3::Zero.y;
        pContact->normal.y = t7;
        const f32 t8 = MtVector3::Zero.z;
        pContact->normal.z = t8;
        pContact->normal.pad_ = 0.0f;
        pContact->distance = 0.0f;
        pContact->toi = t2;
        pContact->bFind = t0;
        return pContact->bFind;
    } else {
        return t0;
    }
}

bool MtGeomRay::getClosest(const MtPlaneXZ& planeXZ, MtContact* pContact) const {
    return false;
}

__attribute__((weak)) bool MtGeomRay::getClosest(const MtTriangle& tri, MtContact* pContact) const {
    DDON_STUB("MtGeomRay::getClosest")
    return {};
}

bool MtGeomRay::isFind(const MtSphere& sphere, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRay, sphere, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRay::isFind(const MtCapsule& capsule, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRay, capsule, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRay::isFind(const MtAABB& aabb, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRay, aabb, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRay::isFind(const MtOBB& obb, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRay, obb, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRay::isFind(const MtPlane& plane, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRay, plane, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRay::isFind(const MtPlaneXZ& planeXZ, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRay, planeXZ, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRay::isFind(const MtTriangle& tri, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRay, tri, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

inline MtGeomRay::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtGeomRay::MyDTI MtGeomRay::DTI("MtGeomRay", &::MtGeometry::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* MtGeomRay::MyDTI::newInstance() const {
    DDON_STUB("MtGeomRay::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtGeomRayY::getDTI() const {
    return MtGeomRayY::DTI;
}

void MtGeomRayY::load(MtDataReader& fin) {
    mRayY.from.x = fin.readF32();
    mRayY.from.y = fin.readF32();
    mRayY.from.z = fin.readF32();
    mRayY.dir = fin.readF32();
    mRayY.dir = fin.readF32();
}

void MtGeomRayY::save(MtDataWriter& fout) {
    fout.writeF32(mRayY.from.x);
    fout.writeF32(mRayY.from.y);
    fout.writeF32(mRayY.from.z);
    fout.writeF32(mRayY.dir);
    fout.writeF32(mRayY.dir);
}

MtUI* MtGeomRayY::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void MtGeomRayY::createProperty(MtPropertyList& s) {
    this->MtGeometry::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "from", &mRayY.from, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dir", &mRayY.dir, 0u, 0u);
}

__attribute__((weak)) void MtGeomRayY::copy(const MtGeometry& input) {
    DDON_STUB("MtGeomRayY::copy")
    /* stub */
}

bool MtGeomRayY::isIntersect(const MtVector3& pos) const {
    return false;
}

bool MtGeomRayY::isIntersect(const MtLine& line) const {
    return false;
}

bool MtGeomRayY::isIntersect(const MtRay& ray) const {
    return false;
}

bool MtGeomRayY::isIntersect(const MtLineSegment& ls) const {
    return false;
}

bool MtGeomRayY::isIntersect(const MtSphere& sphere) const {
    return false;
}

bool MtGeomRayY::isIntersect(const MtCapsule& capsule) const {
    return false;
}

bool MtGeomRayY::isIntersect(const MtAABB& aabb) const {
    if (aabb.minpos.x > mRayY.from.x) {
        return false;
    } else {
        if (aabb.minpos.z > mRayY.from.z) {
            return false;
        } else {
            if (mRayY.from.x > aabb.maxpos.x) {
                return false;
            } else {
                if (mRayY.from.z > aabb.maxpos.z) {
                    return false;
                } else {
                    if (0.0f > mRayY.dir) {
                        if (aabb.minpos.y > mRayY.from.y) {
                            return false;
                        }
                    } else {
                        if (mRayY.from.y > aabb.maxpos.y) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    }
}

bool MtGeomRayY::isIntersect(const MtOBB& obb) const {
    return false;
}

bool MtGeomRayY::isIntersect(const MtPlane& plane) const {
    return MtCollision::intersect(mRayY, plane);
}

bool MtGeomRayY::isIntersect(const MtPlaneXZ& planeXZ) const {
    return false;
}

bool MtGeomRayY::isIntersect(const MtTriangle& tri) const {
    return MtCollision::intersect(mRayY, tri);
}

bool MtGeomRayY::isIntersect(const MtCylinder& cylinder) const {
    return false;
}

bool MtGeomRayY::isFind(const MtSphere& sphere, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRayY, sphere, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRayY::isFind(const MtCapsule& capsule, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRayY, capsule, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRayY::isFind(const MtAABB& aabb, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRayY, aabb, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRayY::isFind(const MtOBB& obb, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRayY, obb, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

__attribute__((weak)) bool MtGeomRayY::isFind(const MtPlane& plane, const MtVector3& v, MtContact* pContact) const {
    DDON_STUB("MtGeomRayY::isFind")
    return {};
}

bool MtGeomRayY::isFind(const MtPlaneXZ& planeXZ, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRayY, planeXZ, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

bool MtGeomRayY::isFind(const MtTriangle& tri, const MtVector3& v, MtContact* pContact) const {
    return MtCollision::find(mRayY, tri, static_cast<f32*>(nullptr), pContact, static_cast<MtContact*>(nullptr));
}

inline MtGeomRayY::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtGeomRayY::MyDTI MtGeomRayY::DTI("MtGeomRayY", &::MtGeometry::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* MtGeomRayY::MyDTI::newInstance() const {
    DDON_STUB("MtGeomRayY::MyDTI::newInstance")
    return nullptr;
}

