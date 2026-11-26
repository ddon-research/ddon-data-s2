// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cSetInfoCoord.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cSetInfo.h"
#include "../../generated/shared/nDDOIO.h"
#include "sWorldOffset.h"
#include "uControl.h"
#include "../../XFramework/uCoord.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSetInfoCoord::getDTI() const {
    return cSetInfoCoord::DTI;
}

inline void* cSetInfoCoord::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cSetInfoCoord::DTI)->memAlloc(sz, align, cSetInfoCoord::DTI.getID());
}

cSetInfoCoord::cSetInfoCoord() {
        this->mPosition.x = 0.0f;
        this->mPosition.y = 0.0f;
        this->mPosition.z = 0.0f;
        this->mAngle.x = 0.0f;
        this->mAngle.y = 0.0f;
        this->mAngle.z = 0.0f;
        this->mScale.x = 1.0f;
        this->mScale.y = 1.0f;
        this->mScale.z = 1.0f;
        this->mUnitID = -1;
        this->mAreaHitNo = -1;
        this->mVersion = 0;
        this->mTblIndex = -1;
}

cSetInfoCoord::~cSetInfoCoord() {
}

void cSetInfoCoord::createProperty(MtPropertyList& s) {
    this->cSetInfo::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mName", reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::getcSetName), reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::setcSetName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "mUnitID", reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::getUnitID), reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::setUnitID), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mPosition", reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::getPositionForProperty), reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::setPositionForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mAngle", reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::getAngleForProperty), reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::setAngleForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mScale", reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::getScaleForProperty), reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::setScaleForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAreaHitNo", &mAreaHitNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVersion", &mVersion, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_MATRIX, "Matrix", reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::getMatrix), reinterpret_cast<MT_MFUNC>(&::cSetInfoCoord::setMatrix), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) bool cSetInfoCoord::load(MtDataReader& r) {
        char t0[256];
        r.readString(t0, 256u);
        mName = t0;
        mUnitID = r.readS32();
        MtVector3 pos;
        MtVector3 angle;
        MtVector3 scale;
        pos = r.readV3();
        angle = r.readV3();
        scale = r.readV3();
        mPosition.x = pos.x;
        mPosition.y = pos.y;
        mPosition.z = pos.z;
        mAngle.x = angle.x;
        mAngle.y = angle.y;
        mAngle.z = angle.z;
        mScale.x = scale.x;
        mScale.y = scale.y;
        mScale.z = scale.z;
        mAreaHitNo = r.readS32();
        return true;
}

__attribute__((weak)) bool cSetInfoCoord::save(MtDataWriter& w) {
    nDDOIO::writeData(w, mName);
    nDDOIO::writeData(w, mUnitID);
    MtVector3 pos(mPosition.x, mPosition.y, mPosition.z);
    MtVector3 angle(mAngle.x, mAngle.y, mAngle.z);
    MtVector3 scale(mScale.x, mScale.y, mScale.z);
    nDDOIO::writeData(w, pos);
    nDDOIO::writeData(w, angle);
    nDDOIO::writeData(w, scale);
    nDDOIO::writeData(w, mAreaHitNo);
    return true;
}

__attribute__((weak)) void cSetInfoCoord::createToolProperty(MtPropertyList& s) {
}

MtUI* cSetInfoCoord::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool cSetInfoCoord::applyInfo(cUnit* pu) const {
    DDON_STUB("cSetInfoCoord::applyInfo")
    return {};
}

__attribute__((weak)) void cSetInfoCoord::copy(cSetInfo* p) {
    DDON_STUB("cSetInfoCoord::copy")
    /* stub */
}

MT_CTSTR cSetInfoCoord::getcSetName() const {
    return mName.ptr();
}

__attribute__((weak)) void cSetInfoCoord::setcSetName(const MtString& name) {
    mName = name;
}

static auto ddon_emit_0x01a60bf0 __attribute__((used)) = &cSetInfoCoord::getUnitID;

void cSetInfoCoord::setUnitID(s32 id) {
    mUnitID = id;
}

void cSetInfoCoord::setPosition(const MtVector3& pos) {
    mPosition.x = pos.x;
    mPosition.y = pos.y;
    mPosition.z = pos.z;
}

void cSetInfoCoord::setAngle(const MtVector3& ang) {
    mAngle.x = ang.x;
    mAngle.y = ang.y;
    mAngle.z = ang.z;
}

__attribute__((weak)) MtMatrix cSetInfoCoord::getMatrix() {
    DDON_STUB("cSetInfoCoord::getMatrix")
    __builtin_unreachable();
}

__attribute__((weak)) void cSetInfoCoord::setMatrix(MtMatrix& mat) {
    DDON_STUB("cSetInfoCoord::setMatrix")
    /* stub */
}

MtVector3 cSetInfoCoord::getPositionForProperty() const {
    MtVector3 result;
    result.x = mPosition.x;
    result.y = mPosition.y;
    result.z = mPosition.z;
    result.pad_ = 0.0f;
    return result;
}

void cSetInfoCoord::setPositionForProperty(const MtVector3& pos) {
    mPosition.x = pos.x;
    mPosition.y = pos.y;
    mPosition.z = pos.z;
}

MtVector3 cSetInfoCoord::getAngleForProperty() const {
    MtVector3 result;
    result.x = mAngle.x;
    result.y = mAngle.y;
    result.z = mAngle.z;
    result.pad_ = 0.0f;
    return result;
}

void cSetInfoCoord::setAngleForProperty(const MtVector3& angle) {
    mAngle.x = angle.x;
    mAngle.y = angle.y;
    mAngle.z = angle.z;
}

MtVector3 cSetInfoCoord::getScaleForProperty() const {
    MtVector3 result;
    result.x = mScale.x;
    result.y = mScale.y;
    result.z = mScale.z;
    result.pad_ = 0.0f;
    return result;
}

void cSetInfoCoord::setScaleForProperty(const MtVector3& scale) {
    mScale.x = scale.x;
    mScale.y = scale.y;
    mScale.z = scale.z;
}

inline cSetInfoCoord::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSetInfoCoord::MyDTI cSetInfoCoord::DTI("cSetInfoCoord", &::cSetInfo::DTI, 72ul, 0u, 0u);

MtObject* cSetInfoCoord::MyDTI::newInstance() const {
    return new (16u) cSetInfoCoord;
}

