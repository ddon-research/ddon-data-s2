// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cAreaHit.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollision.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cUnit.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/nZone.h"
#include "sAreaHit.h"
#include "sPlayerManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& AreaHitShape::getDTI() const {
    return AreaHitShape::DTI;
}

inline MtAllocator* AreaHitShape::getAllocator() {
    return MtMemoryAllocator::getAllocator(AreaHitShape::DTI);
}

void* AreaHitShape::operator new(size_t sz, u32 align) {
    return AreaHitShape::getAllocator()->memAlloc(sz, align, AreaHitShape::DTI.getID());
}

void* AreaHitShape::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

__attribute__((noinline)) AreaHitShape::AreaHitShape() {
    mCheckAngle = 0.0f;
    mCheckRange = 0.0f;
    mCheckToward = 0.0f;
    mAngleFlag = false;
    mTowardFlag = false;
    mIsDeleteZone = true;
    mpZone = nullptr;
    mZoneBoundingBox.minpos = MtVector3::Zero;
    mZoneBoundingBox.maxpos = MtVector3::One;
}

AreaHitShape::~AreaHitShape() {
    if (mIsDeleteZone) {
        if (mpZone != nullptr) {
            delete mpZone;
            mpZone = nullptr;
        }
    } else {
        mIsDeleteZone = false;
        mpZone = nullptr;
    }
}

void AreaHitShape::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Name", &mName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CheckAngle", &mCheckAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CheckRange", &mCheckRange, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CheckToward", &mCheckToward, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "AngleFlag", &mAngleFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "TowardFlag", &mTowardFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpZone", reinterpret_cast<MT_MFUNC>(&::AreaHitShape::getZone), reinterpret_cast<MT_MFUNC>(&::AreaHitShape::setZone), 132u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mZoneBoundingBox", &mZoneBoundingBox, 0u, 0u);
}

MtUI* AreaHitShape::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool AreaHitShape::load(MtDataReader& r, AreaHitShape::NativeAllocInfo* pBuffer) {
    nDDOIO::readData(r, mName);
    nDDOIO::readData(r, mCheckAngle);
    nDDOIO::readData(r, mCheckRange);
    nDDOIO::readData(r, mCheckToward);
    nDDOIO::readData(r, mAngleFlag);
    nDDOIO::readData(r, mTowardFlag);
    AREAHIT_SHAPE_TYPE_ENUM type = static_cast<AREAHIT_SHAPE_TYPE_ENUM>(r.readS32());
    mIsDeleteZone = true;
    MtCylinder cyl;
    switch (type) {
    case AREAHIT_SHAPE_TYPE_BOX:
        if (pBuffer != nullptr && pBuffer->pShapeBoxArray != nullptr && pBuffer->ShapeBoxUseNum < pBuffer->ShapeBoxMaxNum) {
            mpZone = &pBuffer->pShapeBoxArray[pBuffer->ShapeBoxUseNum++];
            mIsDeleteZone = false;
        } else {
            mpZone = new (16u) nZone::ShapeInfoArea;
        }
        break;
    case AREAHIT_SHAPE_TYPE_SPHERE:
        if (pBuffer != nullptr && pBuffer->pShapeSphereArray != nullptr && pBuffer->ShapeSphereUseNum < pBuffer->ShapeSphereMaxNum) {
            mpZone = &pBuffer->pShapeSphereArray[pBuffer->ShapeSphereUseNum++];
            mIsDeleteZone = false;
        } else {
            mpZone = new (16u) nZone::ShapeInfoSphere;
        }
        break;
    case AREAHIT_SHAPE_TYPE_CYLINDER: {
        nZone::ShapeInfoCylinder* t1 = nullptr;
        if (pBuffer != nullptr && pBuffer->pShapeCylinderArray != nullptr && pBuffer->ShapeCylinderUseNum < pBuffer->ShapeCylinderMaxNum) {
            t1 = &pBuffer->pShapeCylinderArray[pBuffer->ShapeCylinderUseNum++];
            mIsDeleteZone = false;
        } else {
            t1 = new (16u) nZone::ShapeInfoCylinder;
        }
        cyl.p0 = MtVector3::Zero;
        cyl.p1 = MtVector3(0.0f, 100.0f, 0.0f);
        cyl.r = 50.0f;
        t1->setParam(cyl);
        mpZone = t1;
        break;
    }
    case AREAHIT_SHAPE_TYPE_CONE:
        if (pBuffer != nullptr && pBuffer->pShapeConeArray != nullptr && pBuffer->ShapeConeUseNum < pBuffer->ShapeConeMaxNum) {
            mpZone = &pBuffer->pShapeConeArray[pBuffer->ShapeConeUseNum++];
            mIsDeleteZone = false;
        } else {
            mpZone = new (16u) nZone::ShapeInfoCone;
        }
        break;
    case AREAHIT_SHAPE_TYPE_AABB:
        if (pBuffer != nullptr && pBuffer->pShapeAABBArray != nullptr && pBuffer->ShapeAABBUseNum < pBuffer->ShapeAABBMaxNum) {
            mpZone = &pBuffer->pShapeAABBArray[pBuffer->ShapeAABBUseNum++];
            mIsDeleteZone = false;
        } else {
            mpZone = new (16u) nZone::ShapeInfoAABB;
        }
        break;
    case AREAHIT_SHAPE_TYPE_OBB:
        if (pBuffer != nullptr && pBuffer->pShapeOBBArray != nullptr && pBuffer->ShapeOBBUseNum < pBuffer->ShapeOBBMaxNum) {
            mpZone = &pBuffer->pShapeOBBArray[pBuffer->ShapeOBBUseNum++];
            mIsDeleteZone = false;
        } else {
            mpZone = new (16u) nZone::ShapeInfoOBB;
        }
        break;
    default:
        mpZone = nullptr;
        break;
    }
    if (mpZone == nullptr) {
        return type == AREAHIT_SHAPE_TYPE_NONE;
    }
    mpZone->loadBinary(r);
    mZoneBoundingBox = mpZone->getAABB();
    return true;
}

__attribute__((weak)) bool AreaHitShape::save(MtDataWriter& w) {
    nDDOIO::writeData(w, mName);
    nDDOIO::writeData(w, mCheckAngle);
    nDDOIO::writeData(w, mCheckRange);
    nDDOIO::writeData(w, mCheckToward);
    nDDOIO::writeData(w, mAngleFlag);
    nDDOIO::writeData(w, mTowardFlag);
    AREAHIT_SHAPE_TYPE_ENUM type = getShapeType();
    w.writeS32(type);
    if (type == AREAHIT_SHAPE_TYPE_NONE) {
        return true;
    }
    if (mpZone == nullptr) {
        return false;
    }
    mpZone->saveBinary(w);
    return true;
}

__attribute__((weak)) AreaHitShape& AreaHitShape::operator=(const AreaHitShape& shape) {
    DDON_STUB("AreaHitShape::operator=")
    __builtin_unreachable();
}

__attribute__((weak)) AreaHitShape* AreaHitShape::createShape(AREAHIT_SHAPE_TYPE_ENUM e) {
    DDON_STUB("AreaHitShape::createShape")
    return nullptr;
}

AREAHIT_SHAPE_TYPE_ENUM AreaHitShape::getShapeType() const {
    AREAHIT_SHAPE_TYPE_ENUM type = AREAHIT_SHAPE_TYPE_NONE;
    if (mpZone != nullptr) {
        switch (mpZone->getShapeType()) {
        case nZone::ShapeInfoBase::SHAPE_TYPE_AREA:
            type = AREAHIT_SHAPE_TYPE_BOX;
            break;
        case nZone::ShapeInfoBase::SHAPE_TYPE_AABB:
            type = AREAHIT_SHAPE_TYPE_AABB;
            break;
        case nZone::ShapeInfoBase::SHAPE_TYPE_OBB:
            type = AREAHIT_SHAPE_TYPE_OBB;
            break;
        case nZone::ShapeInfoBase::SHAPE_TYPE_SPHERE:
            type = AREAHIT_SHAPE_TYPE_SPHERE;
            break;
        case nZone::ShapeInfoBase::SHAPE_TYPE_CYLINDER:
            type = AREAHIT_SHAPE_TYPE_CYLINDER;
            break;
        case nZone::ShapeInfoBase::SHAPE_TYPE_CONE:
            type = AREAHIT_SHAPE_TYPE_CONE;
            break;
        default:
            break;
        }
    }
    return type;
}

__attribute__((weak)) MtVector3 AreaHitShape::getCenter() const {
    DDON_STUB("AreaHitShape::getCenter")
    __builtin_unreachable();
}

__attribute__((weak)) void AreaHitShape::setCenter(const MtVector3& pos) {
    DDON_STUB("AreaHitShape::setCenter")
    /* stub */
}

bool AreaHitShape::hitCheck(const MtVector3& tarPos) const {
    if (mpZone != nullptr) {
        return mpZone->isHit(tarPos);
    } else {
        return false;
    }
}

__attribute__((weak)) bool AreaHitShape::calcIntersectionLine2Line2D(const MtVector3& pos0, const MtVector3& pos1, const MtVector3& pos2, const MtVector3& pos3, MtVector3& pos_out) const {
    DDON_STUB("AreaHitShape::calcIntersectionLine2Line2D")
    return {};
}

void AreaHitShape::setZone(ZShape* p) {
    if (mpZone != p) {
        if (mIsDeleteZone) {
            if (mpZone != nullptr) {
                delete mpZone;
                mpZone = nullptr;
            }
        } else {
            mIsDeleteZone = false;
            mpZone = nullptr;
        }
        mpZone = p;
        if (mpZone != nullptr) {
            mZoneBoundingBox = mpZone->getAABB();
        }
    }
}

ZShape* AreaHitShape::getZone() const {
    return mpZone;
}

inline AreaHitShape::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

AreaHitShape::MyDTI AreaHitShape::DTI("AreaHitShape", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* AreaHitShape::MyDTI::newInstance() const {
    return new (16u) AreaHitShape;
}

const MtDTI& cAreaHit::getDTI() const {
    return cAreaHit::DTI;
}

inline void* cAreaHit::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAreaHit::DTI)->memAlloc(sz, align, cAreaHit::DTI.getID());
}

inline void cAreaHit::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAreaHit::DTI)->memFree(p_addr);
}

inline cAreaHit::cAreaHit() {
    mpOwner = nullptr;
    mOwnerId = 0;
    mbEnable = true;
    mbFix = false;
    mUID = 0;
    mDetect = 0;
    mpShape = nullptr;
    mAttr = 0;
    mWorld.x = MtVector3::Zero.x;
    mWorld.y = MtVector3::Zero.y;
    mWorld.z = MtVector3::Zero.z;
    mWorld.pad_ = 0.0f;
    mLocal.x = MtVector3::Zero.x;
    mLocal.y = MtVector3::Zero.y;
    mLocal.z = MtVector3::Zero.z;
    mLocal.pad_ = 0.0f;
    mRotate.x = MtVector3::Zero.x;
    mRotate.y = MtVector3::Zero.y;
    mRotate.z = MtVector3::Zero.z;
    mpSpTarget = nullptr;
    mCkRange = 0.0f;
    mCkToward = 0.0f;
    mRotate.pad_ = 0.0f;
    mCkAngle = 0.0f;
    mRefPos.x = MtVector3::Zero.x;
    mRefPos.y = MtVector3::Zero.y;
    mRefPos.z = MtVector3::Zero.z;
    mRefPos.pad_ = 0.0f;
    mRefJointNo = 0;
    mOwnerJointNo = 0;
}

cAreaHit::~cAreaHit() {
    if (mpShape != nullptr) {
        delete mpShape;
        mpShape = nullptr;
    }
    mbEnable = false;
}

__attribute__((weak)) void cAreaHit::createProperty(MtPropertyList& s) {
}

MtUI* cAreaHit::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cAreaHit::setup(AREAHIT_SHAPE_TYPE_ENUM type, MtObject* pOwner) {
    mpOwner = pOwner;
    if (pOwner != nullptr) {
        mOwnerId = pOwner->getDTI().getID();
    }
    mbEnable = true;
    mbFix = false;
    mAttr = 0;
    mDetect = 0;
    mWorld.x = MtVector3::Zero.x;
    mWorld.y = MtVector3::Zero.y;
    mWorld.z = MtVector3::Zero.z;
    mWorld.pad_ = 0.0f;
    mLocal.x = MtVector3::Zero.x;
    mLocal.y = MtVector3::Zero.y;
    mLocal.z = MtVector3::Zero.z;
    mLocal.pad_ = 0.0f;
    mRotate.x = MtVector3::Zero.x;
    mRotate.y = MtVector3::Zero.y;
    mRotate.z = MtVector3::Zero.z;
    mCkRange = 0.0f;
    mCkToward = 0.0f;
    mRotate.pad_ = 0.0f;
    mCkAngle = 0.0f;
    if (mpShape != nullptr) {
        delete mpShape;
        mpShape = nullptr;
    }
    mpShape = AreaHitShape::createShape(type);
}

void cAreaHit::final() {
    if (mpShape != nullptr) {
        delete mpShape;
        mpShape = nullptr;
    }
    mbEnable = false;
}

void cAreaHit::move() {
    mDetect = 0;
    update();
    if ((mAttr & 31u) != 0) {
        if ((sPlayerManager::mpInstance)->sPlayerManager::getMyPlayer() != nullptr) {
            if (collide(static_cast<uDDOModel*>((sPlayerManager::mpInstance)->sPlayerManager::getMyPlayer()))) {
                mDetect = mDetect | 17u;
            }
        }
    }
    if ((mAttr & 1024u) == 0) {
        return;
    }
    if (!collide(static_cast<uDDOModel*>(nullptr))) {
        return;
    }
    mDetect = mDetect | 1024u;
}

__attribute__((weak)) void cAreaHit::update() {
    DDON_STUB("cAreaHit::update")
    /* stub */
}

__attribute__((weak)) void cAreaHit::copyShape(AreaHitShape* pShape) {
    DDON_STUB("cAreaHit::copyShape")
    /* stub */
}

__attribute__((weak)) bool cAreaHit::collide(uDDOModel* pObj) {
    DDON_STUB("cAreaHit::collide")
    return {};
}

__attribute__((weak)) bool cAreaHit::collide(const MtVector3& pos, f32 ang) {
    DDON_STUB("cAreaHit::collide")
    return {};
}

__attribute__((weak)) bool cAreaHit::checkToward(const uDDOModel* pObj) {
    DDON_STUB("cAreaHit::checkToward")
    return {};
}

__attribute__((weak)) MtVector3 cAreaHit::getCenter() const {
    DDON_STUB("cAreaHit::getCenter")
    __builtin_unreachable();
}

__attribute__((weak)) void cAreaHit::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("cAreaHit::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void cAreaHit::getTargetPos(uDDOModel* pObj, MtVector3* pTargetPos, MtVector3* pTargetUnderPos) const {
    DDON_STUB("cAreaHit::getTargetPos")
    /* stub */
}

inline cAreaHit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAreaHit::MyDTI cAreaHit::DTI("cAreaHit", &::MtObject::DTI, 160ul, 0u, 0u);

MtObject* cAreaHit::MyDTI::newInstance() const {
    return new (16u) cAreaHit;
}

