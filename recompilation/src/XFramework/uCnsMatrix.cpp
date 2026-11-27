// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsMatrix.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "uConstraint.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uCnsMatrix::usage() {
}

const MtDTI& uCnsMatrix::getDTI() const {
    return uCnsMatrix::DTI;
}

uCnsMatrix::uCnsMatrix() {
    DDON_STUB("uCnsMatrix::uCnsMatrix")
    /* stub */
}

uCnsMatrix::~uCnsMatrix() {
    DDON_STUB("uCnsMatrix::~uCnsMatrix")
    /* stub */
}

void uCnsMatrix::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpCnsMatrixRes", "resource", reinterpret_cast<MT_MFUNC>(&::uCnsMatrix::getResource), reinterpret_cast<MT_MFUNC>(&::uCnsMatrix::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "Joint", reinterpret_cast<MT_MFUNC>(&::uCnsMatrix::getJoint), reinterpret_cast<MT_MFUNC>(&::uCnsMatrix::setJointForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mMat", &mMat, 0u, 0u);
}

MtUI* uCnsMatrix::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

__attribute__((weak)) void uCnsMatrix::draw(cDraw* pDraw) {
}

__attribute__((weak)) void uCnsMatrix::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uCnsMatrix::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uCnsMatrix::setResource(cResource* pRes) {
    DDON_STUB("uCnsMatrix::setResource")
    /* stub */
}

__attribute__((weak)) cResource* uCnsMatrix::getResource() {
    DDON_STUB("uCnsMatrix::getResource")
    return nullptr;
}

__attribute__((weak)) void uCnsMatrix::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uCnsMatrix::adjust")
    /* stub */
}

void uCnsMatrix::remove() {
    removeConstraint();
}

void uCnsMatrix::update() {
    setConstraint(getModel(), mJoint);
}

void uCnsMatrix::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
    if (Num == 0) {
        return;
    }
    mJoint = static_cast<s32>((*pJnts)->mNo);
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), mJoint);
}

void uCnsMatrix::set(uModel* pModel, u32 JntNo, u32 Pri) {
    setModel(pModel);
    setPri(Pri);
    mJoint = static_cast<s32>(JntNo);
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), mJoint);
}

static auto ddon_emit_0x01b67730 __attribute__((used)) = &uCnsMatrix::getJoint;

void uCnsMatrix::setJointForProperty(u32 JntNo) {
    mJoint = static_cast<s32>(JntNo);
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), mJoint);
}

inline uCnsMatrix::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsMatrix::MyDTI uCnsMatrix::DTI("uCnsMatrix", &::uConstraint::DTI, 240ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsMatrix::MyDTI::newInstance() const {
    uCnsMatrix* t1 = new (MtMemoryAllocator::getAllocator(uCnsMatrix::DTI)->memAlloc(
        sizeof(uCnsMatrix), alignof(uCnsMatrix), uCnsMatrix::DTI.getID())) uCnsMatrix;
    t1->mpCnsMatrixRes = nullptr;
    t1->mMat = MtMatrix::Identity;
    t1->mJoint = 0;
    t1->mPos = true;
    t1->mRot = true;
    return t1;
}

