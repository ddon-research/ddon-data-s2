// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sOccluderExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/nZone.h"
#include "rOccluderExt.h"

#include "../../XFramework/rOccluder.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sCamera.h"
#include "../../XFramework/sOccluder.h"
#include "../../XFramework/uCamera.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sOccluderEx::getDTI() const {
    return sOccluderEx::DTI;
}

inline MtAllocator* sOccluderEx::getAllocator() {
    return MtMemoryAllocator::getAllocator(sOccluderEx::DTI);
}

void* sOccluderEx::operator new(size_t sz, u32 align) {
    return sOccluderEx::getAllocator()->memAlloc(sz, align, sOccluderEx::DTI.getID());
}

inline void sOccluderEx::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(sOccluderEx::DTI)->memFree(p_addr);
}

sOccluderEx::sOccluderEx() {
    sOccluder::mpInstance = static_cast<sOccluder*>(this);
    mprOCC = nullptr;
    mpFilterTarget = nullptr;
    mCameraAreaNum = 0;
    mCameraAreaNo = 0;
}

sOccluderEx::~sOccluderEx() {
    sOccluder::mpInstance = nullptr;
}

void sOccluderEx::createProperty(MtPropertyList& s) {
    this->sOccluder::createProperty(s);
}

MtUI* sOccluderEx::createUI(MtProperty& prop) {
    return this->sOccluder::createUI(prop);
}

void sOccluderEx::move() {
    updateCameraArea();
    rOccluderEx* t0 = mprOCC;
    if (t0 == nullptr) {
        return;
    }
    if (t0->getArea(mCameraAreaNo) != nullptr) {
        Area* t1 = t0->getArea(mCameraAreaNo);
        if (t1 != nullptr) {
            setResource(t1->mprOCC);
        }
    } else {
        Area* t1 = t0->getArea(0u);
        if (t1 != nullptr) {
            setResource(t1->mprOCC);
        }
    }
}

__attribute__((weak)) void sOccluderEx::updateCameraArea() {
    DDON_STUB("sOccluderEx::updateCameraArea")
    /* stub */
}

__attribute__((weak)) void sOccluderEx::stageInit() {
    DDON_STUB("sOccluderEx::stageInit")
    /* stub */
}

void sOccluderEx::stageFinal() {
    setResource(static_cast<rOccluder*>(nullptr));
    if (mprOCC == nullptr) {
        return;
    }
    mprOCC->release();
    mprOCC = nullptr;
}

__attribute__((weak)) void sOccluderEx::partsInit(rOccluderEx* prOCC) {
    DDON_STUB("sOccluderEx::partsInit")
    /* stub */
}

void sOccluderEx::partsFinal() {
    setResource(static_cast<rOccluder*>(nullptr));
    if (mprOCC == nullptr) {
        return;
    }
    mprOCC->release();
    mprOCC = nullptr;
}

inline sOccluderEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sOccluderEx::MyDTI sOccluderEx::DTI("sOccluderEx", &::sOccluder::DTI, 33712ul, 0u, 0u);

MtObject* sOccluderEx::MyDTI::newInstance() const {
    return new (16u) sOccluderEx;
}

const MtDTI& sOccluderEx::Area::getDTI() const {
    return sOccluderEx::Area::DTI;
}

inline void* sOccluderEx::Area::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sOccluderEx::Area::DTI)->memAlloc(sz, align, sOccluderEx::Area::DTI.getID());
}

inline void sOccluderEx::Area::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(sOccluderEx::Area::DTI)->memFree(p_addr);
}

__attribute__((noinline)) sOccluderEx::Area::~Area() {
    if (mprOCC != nullptr) {
        mprOCC->release();
        mprOCC = nullptr;
    }
    mShapeList.deleteAll(true);
}

void sOccluderEx::Area::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaName", &mAreaName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPrio", &mPrio, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mbOCC", &mbOCC, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShapeList", static_cast<MtObject*>(&mShapeList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mprOCC", "resource", static_cast<void*>(&mprOCC), 0u, 0u);
}

MtUI* sOccluderEx::Area::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

sOccluderEx::Shape* sOccluderEx::Area::getShape(u32 index) {
    if (index < mShapeList.mLength) {
        return static_cast<Shape*>(mShapeList.mpArray[index]);
    } else {
        return nullptr;
    }
}

u32 sOccluderEx::Area::getShapeNum() {
    return mShapeList.mLength;
}

inline sOccluderEx::Area::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sOccluderEx::Area::MyDTI sOccluderEx::Area::DTI("sOccluderEx::Area", &::MtObject::DTI, 72ul, 0u, 0u);

MtObject* sOccluderEx::Area::MyDTI::newInstance() const {
    return new (16u) sOccluderEx::Area;
}

const MtDTI& sOccluderEx::Shape::getDTI() const {
    return sOccluderEx::Shape::DTI;
}

inline void* sOccluderEx::Shape::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sOccluderEx::Shape::DTI)->memAlloc(sz, align, sOccluderEx::Shape::DTI.getID());
}

inline void sOccluderEx::Shape::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(sOccluderEx::Shape::DTI)->memFree(p_addr);
}

inline sOccluderEx::Shape::Shape() {
    mbEnable = true;
    mType = nZone::ShapeInfoBase::SHAPE_TYPE_OBB;
    mpZShape = static_cast<nZone::ShapeInfoBase*>(new (16u) nZone::ShapeInfoOBB);
}

sOccluderEx::Shape::~Shape() {
    if (mpZShape == nullptr) {
        return;
    }
    delete mpZShape;
    mpZShape = nullptr;
}

void sOccluderEx::Shape::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mbEnable", &mbEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "mType", reinterpret_cast<MT_MFUNC>(&::sOccluderEx::Shape::getShapeType), reinterpret_cast<MT_MFUNC>(&::sOccluderEx::Shape::setShapeType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpZShape", reinterpret_cast<MT_MFUNC>(&::sOccluderEx::Shape::getZone), reinterpret_cast<MT_MFUNC>(&::sOccluderEx::Shape::setZone), 132u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* sOccluderEx::Shape::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

nZone::ShapeInfoBase::SHAPE_TYPE sOccluderEx::Shape::getShapeType() {
    return mType;
}

__attribute__((weak)) void sOccluderEx::Shape::setShapeType(nZone::ShapeInfoBase::SHAPE_TYPE type) {
    if (mType == type) {
        return;
    }
    mType = type;
    nZone::ShapeInfoBase* ps = nullptr;
    switch (type) {
    case nZone::ShapeInfoBase::SHAPE_TYPE_AREA:
        ps = new (16u) nZone::ShapeInfoArea;
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_AABB:
        ps = new (16u) nZone::ShapeInfoAABB;
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_OBB:
        ps = new (16u) nZone::ShapeInfoOBB;
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_SPHERE:
        ps = new (16u) nZone::ShapeInfoSphere;
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_CAPSULE:
        ps = new (16u) nZone::ShapeInfoCapsule;
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_CYLINDER:
        ps = new (16u) nZone::ShapeInfoCylinder;
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_PANEL:
        ps = new (16u) nZone::ShapeInfoPanel;
        break;
    default:
        break;
    }
    if (mpZShape != ps) {
        if (mpZShape != nullptr) {
            delete mpZShape;
            mpZShape = nullptr;
        }
        mpZShape = ps;
    }
}

nZone::ShapeInfoBase* sOccluderEx::Shape::getZone() {
    return mpZShape;
}

void sOccluderEx::Shape::setZone(nZone::ShapeInfoBase* pInfo) {
    if (mpZShape != pInfo) {
        if (mpZShape != nullptr) {
            delete mpZShape;
            mpZShape = nullptr;
        }
        mpZShape = pInfo;
    }
}

inline sOccluderEx::Shape::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sOccluderEx::Shape::MyDTI sOccluderEx::Shape::DTI("sOccluderEx::Shape", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* sOccluderEx::Shape::MyDTI::newInstance() const {
    return new (16u) sOccluderEx::Shape;
}

