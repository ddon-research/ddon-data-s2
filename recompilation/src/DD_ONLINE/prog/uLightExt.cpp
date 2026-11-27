// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uLightExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "cZoneUnitCtrl.h"
#include "../../XFramework/sCamera.h"
#include "sLightExt.h"
#include "sPlayerManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/uCamera.h"
#include "uDDOModel.h"
#include "../../XFramework/uLight.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& Bind::getDTI() const {
    return Bind::DTI;
}

Bind::~Bind() {
}

void Bind::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mBindType", &mBindType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNo", &mJointNo, 0u, 0u);
}

MtUI* Bind::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline Bind::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

Bind::MyDTI Bind::DTI("Bind", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* Bind::MyDTI::newInstance() const {
    DDON_STUB("Bind::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uPointLightExt::getDTI() const {
    return uPointLightExt::DTI;
}

void* uPointLightExt::operator new(size_t sz, u32 align) {
    return uPointLightExt::getAllocator()->memAlloc(sz, align, uPointLightExt::DTI.getID());
}

uPointLightExt::uPointLightExt() {
    DDON_STUB("uPointLightExt::uPointLightExt")
    /* stub */
}

uPointLightExt::~uPointLightExt() {
    DDON_STUB("uPointLightExt::~uPointLightExt")
    /* stub */
}

void uPointLightExt::setup() {
    this->cUnit::setup();
    mBaseLightColor.x = mColor.x;
    mBaseLightColor.y = mColor.y;
    mBaseLightColor.z = mColor.z;
    mBaseLightColor.pad_ = 0.0f;
}

__attribute__((weak)) void uPointLightExt::move() {
    DDON_STUB("uPointLightExt::move")
    /* stub */
}

__attribute__((weak)) void uPointLightExt::moveAfter() {
    DDON_STUB("uPointLightExt::moveAfter")
    /* stub */
}

void uPointLightExt::createProperty(MtPropertyList& s) {
    this->uPointLight::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableZone", &mDisableZone, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRnoPLE", &mRnoPLE, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnableSchedulerWorldOffset", &mEnableSchedulerWorldOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBind", static_cast<MtObject*>(&mBind), 0u, 0u);
}

__attribute__((weak)) void uPointLightExt::setOffset(const MtVector3& ofs) {
    DDON_STUB("uPointLightExt::setOffset")
    /* stub */
}

__attribute__((weak)) void uPointLightExt::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uPointLightExt::applyWorldOffset")
    /* stub */
}

void uPointLightExt::resetZoneUnitCtrl() {
    MtVector3 frame40;
    frame40.x = mPos.x + mOffset.x;
    frame40.y = mPos.y + mOffset.y;
    frame40.z = mPos.z + mOffset.z;
    frame40.pad_ = 0.0f;
    mZoneUnitCtrl.initZoneUnitCtrl(frame40, ZONE_UNIT_CTRL_TYPE_LIGHT, 1u);
}

inline uPointLightExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uPointLightExt::MyDTI uPointLightExt::DTI("uPointLightExt", &::uPointLight::DTI, 1280ul, 0u, 0u);

__attribute__((weak)) MtObject* uPointLightExt::MyDTI::newInstance() const {
    DDON_STUB("uPointLightExt::MyDTI::newInstance")
    return nullptr;
}

