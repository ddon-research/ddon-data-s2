// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rConvexHull.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtGeometry3D.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cGeomConvexHull::getDTI() const {
    return cGeomConvexHull::DTI;
}

void* cGeomConvexHull::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cGeomConvexHull::DTI)->memAlloc(sz, align, cGeomConvexHull::DTI.mID);
}

cGeomConvexHull::~cGeomConvexHull() {
    DDON_STUB("cGeomConvexHull::~cGeomConvexHull")
    /* stub */
}

__attribute__((weak)) MtVector3 cGeomConvexHull::getSupportConst(const MtVector3& v) const {
    DDON_STUB("cGeomConvexHull::getSupportConst")
    __builtin_unreachable();
}

MtVector3 cGeomConvexHull::getSupport(const MtVector3& v) {
    return getSupportConst(v);
}

__attribute__((weak)) void cGeomConvexHull::getBoundingAABB(MtAABB& aabb) const {
    DDON_STUB("cGeomConvexHull::getBoundingAABB")
    /* stub */
}

__attribute__((weak)) void cGeomConvexHull::getBoundingSphere(MtSphere& sphere) const {
    DDON_STUB("cGeomConvexHull::getBoundingSphere")
    /* stub */
}

__attribute__((weak)) void cGeomConvexHull::transform(const MtGeometry& input, const MtMatrix& transform_matrix) {
    DDON_STUB("cGeomConvexHull::transform")
    /* stub */
}

__attribute__((weak)) void cGeomConvexHull::copy(const MtGeometry& input) {
    DDON_STUB("cGeomConvexHull::copy")
    /* stub */
}

void cGeomConvexHull::setMatrix(const MtMatrix& mat) {
    mMat.m[0].x = mat.m[0].x;
    mMat.m[0].y = mat.m[0].y;
    mMat.m[0].z = mat.m[0].z;
    mMat.m[0].w = mat.m[0].w;
    mMat.m[1].x = mat.m[1].x;
    mMat.m[1].y = mat.m[1].y;
    mMat.m[1].z = mat.m[1].z;
    mMat.m[1].w = mat.m[1].w;
    mMat.m[2].x = mat.m[2].x;
    mMat.m[2].y = mat.m[2].y;
    mMat.m[2].z = mat.m[2].z;
    mMat.m[2].w = mat.m[2].w;
    mMat.m[3].x = mat.m[3].x;
    mMat.m[3].y = mat.m[3].y;
    mMat.m[3].z = mat.m[3].z;
    mMat.m[3].w = mat.m[3].w;
    MtMatrix frame104(mat.inverse());
    mInvMat.m[0].x = frame104.m[0].x;
    mInvMat.m[0].y = frame104.m[0].y;
    mInvMat.m[0].z = frame104.m[0].z;
    mInvMat.m[0].w = frame104.m[0].w;
    mInvMat.m[1].x = frame104.m[1].x;
    mInvMat.m[1].y = frame104.m[1].y;
    mInvMat.m[1].z = frame104.m[1].z;
    mInvMat.m[1].w = frame104.m[1].w;
    mInvMat.m[2].x = frame104.m[2].x;
    mInvMat.m[2].y = frame104.m[2].y;
    mInvMat.m[2].z = frame104.m[2].z;
    mInvMat.m[2].w = frame104.m[2].w;
    mInvMat.m[3].x = frame104.m[3].x;
    mInvMat.m[3].y = frame104.m[3].y;
    mInvMat.m[3].z = frame104.m[3].z;
    mInvMat.m[3].w = frame104.m[3].w;
}

__attribute__((weak)) MtMatrix cGeomConvexHull::getMatrixCopy() {
    DDON_STUB("cGeomConvexHull::getMatrixCopy")
    __builtin_unreachable();
}

MtUI* cGeomConvexHull::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cGeomConvexHull::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Resource", "resource", reinterpret_cast<MT_MFUNC>(&::cGeomConvexHull::getResource), reinterpret_cast<MT_MFUNC>(&::cGeomConvexHull::setResource), 16u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_MATRIX, "Transform", reinterpret_cast<MT_MFUNC>(&::cGeomConvexHull::getMatrixCopy), reinterpret_cast<MT_MFUNC>(&::cGeomConvexHull::setMatrix), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

static auto ddon_emit_0x01b91790 __attribute__((used)) = &cGeomConvexHull::getResource;

__attribute__((weak)) void cGeomConvexHull::setResource(rConvexHull* resource) {
    DDON_STUB("cGeomConvexHull::setResource")
    /* stub */
}

inline cGeomConvexHull::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGeomConvexHull::MyDTI cGeomConvexHull::DTI("cGeomConvexHull", &::MtGeomConvex::DTI, 176ul, 0u, 0u);

__attribute__((weak)) MtObject* cGeomConvexHull::MyDTI::newInstance() const {
    DDON_STUB("cGeomConvexHull::MyDTI::newInstance")
    return nullptr;
}

