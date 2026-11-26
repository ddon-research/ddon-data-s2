// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cAreaHitElement.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cAreaHit.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& AHShapeBox::getDTI() const {
    return AHShapeBox::DTI;
}

inline void AHShapeBox::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(AHShapeBox::DTI)->memFree(p_addr);
}

void AHShapeBox::createProperty(MtPropertyList& s) {
    this->AreaHitShape::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "Box.mHeight", &mHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Box.mPosY", &mPosY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Box.mSetPos0", &mPos[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Box.mSetPos1", &mPos[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Box.mSetPos2", &mPos[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Box.mSetPos3", &mPos[3], 0u, 0u);
}

MtUI* AHShapeBox::createUI(MtProperty& prop) {
    return this->AreaHitShape::createUI(prop);
}

__attribute__((weak)) AreaHitShape& AHShapeBox::operator=(const AreaHitShape& shape) {
    DDON_STUB("AHShapeBox::operator=")
    __builtin_unreachable();
}

bool AHShapeBox::hitCheck(const MtVector3& pos) const {
    if (((((pos.x - mCircleCenter.x) * (pos.x - mCircleCenter.x)) + ((pos.y - mCircleCenter.y) * (pos.y - mCircleCenter.y))) + ((pos.z - mCircleCenter.z) * (pos.z - mCircleCenter.z))) > mCircleRadSq) {
        return false;
    } else {
        if (mPosY > pos.y) {
            return false;
        } else {
            if (pos.y > (mPosY + mHeight)) {
                return false;
            } else {
                if (((pos.z - mPos[0].z) * (mPos[1].x - mPos[0].x)) > ((pos.x - mPos[0].x) * (mPos[1].z - mPos[0].z))) {
                    return false;
                } else {
                    if (((pos.x - mPos[0].x) * (mPos[3].z - mPos[0].z)) > ((pos.z - mPos[0].z) * (mPos[3].x - mPos[0].x))) {
                        return false;
                    } else {
                        if (((pos.x - mPos[2].x) * (mPos[1].z - mPos[2].z)) > ((pos.z - mPos[2].z) * (mPos[1].x - mPos[2].x))) {
                            return false;
                        } else {
                            if (((pos.z - mPos[2].z) * (mPos[3].x - mPos[2].x)) > ((pos.x - mPos[2].x) * (mPos[3].z - mPos[2].z))) {
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) bool AHShapeBox::calcIntersectionLine(cAreaHit* pArea, const MtVector3& pos0, const MtVector3& pos1, MtVector3& pos_out) const {
    DDON_STUB("AHShapeBox::calcIntersectionLine")
    return {};
}

__attribute__((weak)) void AHShapeBox::makeCircle() {
    DDON_STUB("AHShapeBox::makeCircle")
    /* stub */
}

__attribute__((weak)) void AHShapeBox::setCenter(const MtVector3& pos) {
    DDON_STUB("AHShapeBox::setCenter")
    /* stub */
}

__attribute__((weak)) MtVector3 AHShapeBox::getCenter() const {
    DDON_STUB("AHShapeBox::getCenter")
    __builtin_unreachable();
}

f32 AHShapeBox::getHeight() {
    return mHeight;
}

AREAHIT_SHAPE_TYPE_ENUM AHShapeBox::getShapeType() const {
    return AREAHIT_SHAPE_TYPE_BOX;
}

inline AHShapeBox::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

AHShapeBox::MyDTI AHShapeBox::DTI("AHShapeBox", &::AreaHitShape::DTI, 192ul, 0u, 0u);

__attribute__((weak)) MtObject* AHShapeBox::MyDTI::newInstance() const {
    DDON_STUB("AHShapeBox::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& AHShapeBoxRotate::getDTI() const {
    return AHShapeBoxRotate::DTI;
}

inline void AHShapeBoxRotate::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(AHShapeBoxRotate::DTI)->memFree(p_addr);
}

void AHShapeBoxRotate::createProperty(MtPropertyList& s) {
    this->AreaHitShape::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "BoxRotate.mHeight", &mHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "BoxRotate.mAngle", reinterpret_cast<MT_MFUNC>(&::AHShapeBoxRotate::getAngle), reinterpret_cast<MT_MFUNC>(&::AHShapeBoxRotate::setAngle), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "BoxRotate.mCtr", &mCtr, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "BoxRotate.mSetPos0", &mPos[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "BoxRotate.mSetPos1", &mPos[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "BoxRotate.mSetPos2", &mPos[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "BoxRotate.mSetPos3", &mPos[3], 0u, 0u);
}

MtUI* AHShapeBoxRotate::createUI(MtProperty& prop) {
    return this->AreaHitShape::createUI(prop);
}

__attribute__((weak)) AreaHitShape& AHShapeBoxRotate::operator=(const AreaHitShape& shape) {
    DDON_STUB("AHShapeBoxRotate::operator=")
    __builtin_unreachable();
}

__attribute__((weak)) void AHShapeBoxRotate::makeCircle() {
    DDON_STUB("AHShapeBoxRotate::makeCircle")
    /* stub */
}

MtVector3 AHShapeBoxRotate::getCenter() const {
    return mCtr;
}

void AHShapeBoxRotate::setCenter(const MtVector3& pos) {
    mCtr = pos;
    makeCircle();
}

f32 AHShapeBoxRotate::getHeight() {
    return mHeight;
}

AREAHIT_SHAPE_TYPE_ENUM AHShapeBoxRotate::getShapeType() const {
    return AREAHIT_SHAPE_TYPE_DUMMY_05;
}

__attribute__((weak)) bool AHShapeBoxRotate::hitCheck(const MtVector3& _pos) const {
    DDON_STUB("AHShapeBoxRotate::hitCheck")
    return {};
}

MtVector3 AHShapeBoxRotate::getAngle() const {
    return mAngle;
}

__attribute__((weak)) void AHShapeBoxRotate::setAngle(const MtVector3& ang) {
    DDON_STUB("AHShapeBoxRotate::setAngle")
    /* stub */
}

inline AHShapeBoxRotate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

AHShapeBoxRotate::MyDTI AHShapeBoxRotate::DTI("AHShapeBoxRotate", &::AreaHitShape::DTI, 224ul, 0u, 0u);

__attribute__((weak)) MtObject* AHShapeBoxRotate::MyDTI::newInstance() const {
    DDON_STUB("AHShapeBoxRotate::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& AHShapeCone::getDTI() const {
    return AHShapeCone::DTI;
}

inline void* AHShapeCone::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(AHShapeCone::DTI)->memAlloc(sz, align, AHShapeCone::DTI.getID());
}

inline void AHShapeCone::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(AHShapeCone::DTI)->memFree(p_addr);
}

inline AHShapeCone::AHShapeCone() {
    mCenterPos.x = MtVector3::Zero.x;
    mCenterPos.y = MtVector3::Zero.y;
    mCenterPos.z = MtVector3::Zero.z;
    mCenterPos.pad_ = 0.0f;
    mHeight = 300.0f;
    mTopRadius = 250.0f;
    mBottomRadius = 100.0f;
}

void AHShapeCone::createProperty(MtPropertyList& s) {
    this->AreaHitShape::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "Cone.mCenterPos", &mCenterPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Cone.mHeight", &mHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Cone.mTopRadius", &mTopRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Cone.mBottomRadius", &mBottomRadius, 0u, 0u);
}

MtUI* AHShapeCone::createUI(MtProperty& prop) {
    return this->AreaHitShape::createUI(prop);
}

__attribute__((weak)) AreaHitShape& AHShapeCone::operator=(const AreaHitShape& shape) {
    DDON_STUB("AHShapeCone::operator=")
    __builtin_unreachable();
}

__attribute__((weak)) bool AHShapeCone::hitCheck(const MtVector3& pos) const {
    DDON_STUB("AHShapeCone::hitCheck")
    return {};
}

void AHShapeCone::setCenter(const MtVector3& pos) {
    mCenterPos = pos;
}

MtVector3 AHShapeCone::getCenter() const {
    return mCenterPos;
}

f32 AHShapeCone::getHeight() {
    return mHeight;
}

AREAHIT_SHAPE_TYPE_ENUM AHShapeCone::getShapeType() const {
    return AREAHIT_SHAPE_TYPE_CONE;
}

inline AHShapeCone::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

AHShapeCone::MyDTI AHShapeCone::DTI("AHShapeCone", &::AreaHitShape::DTI, 112ul, 0u, 0u);

MtObject* AHShapeCone::MyDTI::newInstance() const {
    return new (16u) AHShapeCone;
}

const MtDTI& AHShapeCylinder::getDTI() const {
    return AHShapeCylinder::DTI;
}

inline void* AHShapeCylinder::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(AHShapeCylinder::DTI)->memAlloc(sz, align, AHShapeCylinder::DTI.getID());
}

inline void AHShapeCylinder::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(AHShapeCylinder::DTI)->memFree(p_addr);
}

inline AHShapeCylinder::AHShapeCylinder() {
    mCenterPos.x = MtVector3::Zero.x;
    mCenterPos.y = MtVector3::Zero.y;
    mCenterPos.z = MtVector3::Zero.z;
    mCenterPos.pad_ = 0.0f;
    mHeight = 300.0f;
    mRadius = 200.0f;
}

void AHShapeCylinder::createProperty(MtPropertyList& s) {
    this->AreaHitShape::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "Cylinder.mCenterPos", &mCenterPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Cylinder.mHeight", &mHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Cylinder.mRadius", &mRadius, 0u, 0u);
}

MtUI* AHShapeCylinder::createUI(MtProperty& prop) {
    return this->AreaHitShape::createUI(prop);
}

__attribute__((weak)) AreaHitShape& AHShapeCylinder::operator=(const AreaHitShape& shape) {
    DDON_STUB("AHShapeCylinder::operator=")
    __builtin_unreachable();
}

__attribute__((weak)) bool AHShapeCylinder::hitCheck(const MtVector3& pos) const {
    DDON_STUB("AHShapeCylinder::hitCheck")
    return {};
}

MtVector3 AHShapeCylinder::getCenter() const {
    return mCenterPos;
}

void AHShapeCylinder::setCenter(const MtVector3& pos) {
    mCenterPos = pos;
}

f32 AHShapeCylinder::getHeight() {
    return mHeight;
}

AREAHIT_SHAPE_TYPE_ENUM AHShapeCylinder::getShapeType() const {
    return AREAHIT_SHAPE_TYPE_CYLINDER;
}

inline AHShapeCylinder::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

AHShapeCylinder::MyDTI AHShapeCylinder::DTI("AHShapeCylinder", &::AreaHitShape::DTI, 112ul, 0u, 0u);

MtObject* AHShapeCylinder::MyDTI::newInstance() const {
    return new (16u) AHShapeCylinder;
}

const MtDTI& AHShapePolygon::getDTI() const {
    return AHShapePolygon::DTI;
}

inline void AHShapePolygon::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(AHShapePolygon::DTI)->memFree(p_addr);
}

AHShapePolygon::AHShapePolygon() {
    DDON_STUB("AHShapePolygon::AHShapePolygon")
    /* stub */
}

__attribute__((noinline)) AHShapePolygon::~AHShapePolygon() {
    if (mPosList.mLength != 0) {
        u32 v0_0 = mPosList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPosList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPosList.mpArray[i0_3];
                v1_0 = mPosList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPosList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mPosList.mpArray));
    }
    mPosList.mpArray = nullptr;
    mPosList.mBufsiz = 0;
    mPosList.mLength = 0;
    if (mShapeList.mLength != 0) {
        u32 v3_0 = mShapeList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mShapeList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mShapeList.mpArray[i3_3];
                v4_0 = mShapeList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mShapeList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mShapeList.mpArray));
    }
    mShapeList.mpArray = nullptr;
    mShapeList.mBufsiz = 0;
    mShapeList.mLength = 0;
}

void AHShapePolygon::createProperty(MtPropertyList& s) {
    this->AreaHitShape::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mHeight", &mHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPosList", static_cast<MtObject*>(&mPosList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShapeList", static_cast<MtObject*>(&mShapeList), 0u, 0u);
}

MtUI* AHShapePolygon::createUI(MtProperty& prop) {
    return this->AreaHitShape::createUI(prop);
}

__attribute__((weak)) AreaHitShape& AHShapePolygon::operator=(const AreaHitShape& shape) {
    DDON_STUB("AHShapePolygon::operator=")
    __builtin_unreachable();
}

__attribute__((weak)) bool AHShapePolygon::hitCheck(const MtVector3& tarPos) const {
    DDON_STUB("AHShapePolygon::hitCheck")
    return {};
}

__attribute__((weak)) void AHShapePolygon::makeCircle() {
    DDON_STUB("AHShapePolygon::makeCircle")
    /* stub */
}

__attribute__((weak)) MtVector3 AHShapePolygon::getCenter() const {
    DDON_STUB("AHShapePolygon::getCenter")
    __builtin_unreachable();
}

__attribute__((weak)) void AHShapePolygon::setCenter(const MtVector3& pos) {
    DDON_STUB("AHShapePolygon::setCenter")
    /* stub */
}

AREAHIT_SHAPE_TYPE_ENUM AHShapePolygon::getShapeType() const {
    return AREAHIT_SHAPE_TYPE_DUMMY_04;
}

inline AHShapePolygon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

AHShapePolygon::MyDTI AHShapePolygon::DTI("AHShapePolygon", &::AreaHitShape::DTI, 192ul, 0u, 0u);

__attribute__((weak)) MtObject* AHShapePolygon::MyDTI::newInstance() const {
    DDON_STUB("AHShapePolygon::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& AHShapePolygon::PosUnit::getDTI() const {
    return AHShapePolygon::PosUnit::DTI;
}

inline void AHShapePolygon::PosUnit::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(AHShapePolygon::PosUnit::DTI)->memFree(p_addr);
}

__attribute__((weak)) void AHShapePolygon::PosUnit::createProperty(MtPropertyList& s) {
}

MtUI* AHShapePolygon::PosUnit::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

AHShapePolygon::PosUnit& AHShapePolygon::PosUnit::operator=(const AHShapePolygon::PosUnit& unit) {
    mPos = unit.mPos;
    mChildPosIndex[0] = unit.mChildPosIndex[0];
    mChildPosIndex[1] = unit.mChildPosIndex[1];
    return *this;
}

inline AHShapePolygon::PosUnit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

AHShapePolygon::PosUnit::MyDTI AHShapePolygon::PosUnit::DTI("AHShapePolygon::PosUnit", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* AHShapePolygon::PosUnit::MyDTI::newInstance() const {
    DDON_STUB("AHShapePolygon::PosUnit::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& AHShapeSphere::getDTI() const {
    return AHShapeSphere::DTI;
}

inline void* AHShapeSphere::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(AHShapeSphere::DTI)->memAlloc(sz, align, AHShapeSphere::DTI.getID());
}

inline void AHShapeSphere::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(AHShapeSphere::DTI)->memFree(p_addr);
}

inline AHShapeSphere::AHShapeSphere() {
    mCenterPos.x = MtVector3::Zero.x;
    mCenterPos.y = MtVector3::Zero.y;
    mCenterPos.z = MtVector3::Zero.z;
    mCenterPos.pad_ = 0.0f;
    mRadius = 100.0f;
}

void AHShapeSphere::createProperty(MtPropertyList& s) {
    this->AreaHitShape::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "Sphere.mCenterPos", &mCenterPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Sphere.mRadius", &mRadius, 0u, 0u);
}

MtUI* AHShapeSphere::createUI(MtProperty& prop) {
    return this->AreaHitShape::createUI(prop);
}

__attribute__((weak)) AreaHitShape& AHShapeSphere::operator=(const AreaHitShape& shape) {
    DDON_STUB("AHShapeSphere::operator=")
    __builtin_unreachable();
}

__attribute__((weak)) bool AHShapeSphere::hitCheck(const MtVector3& pos) const {
    DDON_STUB("AHShapeSphere::hitCheck")
    return {};
}

MtVector3 AHShapeSphere::getCenter() const {
    return mCenterPos;
}

__attribute__((weak)) void AHShapeSphere::setCenter(const MtVector3& pos) {
    DDON_STUB("AHShapeSphere::setCenter")
    /* stub */
}

AREAHIT_SHAPE_TYPE_ENUM AHShapeSphere::getShapeType() const {
    return AREAHIT_SHAPE_TYPE_SPHERE;
}

inline AHShapeSphere::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

AHShapeSphere::MyDTI AHShapeSphere::DTI("AHShapeSphere", &::AreaHitShape::DTI, 112ul, 0u, 0u);

MtObject* AHShapeSphere::MyDTI::newInstance() const {
    return new (16u) AHShapeSphere;
}

const MtDTI& AHShapeTriangle::getDTI() const {
    return AHShapeTriangle::DTI;
}

inline void* AHShapeTriangle::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(AHShapeTriangle::DTI)->memAlloc(sz, align, AHShapeTriangle::DTI.getID());
}

inline void AHShapeTriangle::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(AHShapeTriangle::DTI)->memFree(p_addr);
}

void AHShapeTriangle::createProperty(MtPropertyList& s) {
    this->AreaHitShape::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "Triangle.mCorePos", &mCorePos->x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Triangle.mSubPos[0]", &mSubPos[0]->x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Triangle.mSubPos[1]", &mSubPos[1]->x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Triangle.mHeight", &mHeight, 0u, 0u);
}

MtUI* AHShapeTriangle::createUI(MtProperty& prop) {
    return this->AreaHitShape::createUI(prop);
}

__attribute__((weak)) AreaHitShape& AHShapeTriangle::operator=(const AreaHitShape& shape) {
    DDON_STUB("AHShapeTriangle::operator=")
    __builtin_unreachable();
}

__attribute__((weak)) bool AHShapeTriangle::hitCheck(const MtVector3& pos) const {
    DDON_STUB("AHShapeTriangle::hitCheck")
    return {};
}

inline AHShapeTriangle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

AHShapeTriangle::MyDTI AHShapeTriangle::DTI("AHShapeTriangle", &::AreaHitShape::DTI, 112ul, 0u, 0u);

MtObject* AHShapeTriangle::MyDTI::newInstance() const {
    return new (16u) AHShapeTriangle;
}

