// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsBowUpper.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/uConstraint.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCnsBowUpper::getDTI() const {
    return uCnsBowUpper::DTI;
}

inline void* uCnsBowUpper::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uCnsBowUpper::DTI)->memAlloc(sz, align, uCnsBowUpper::DTI.getID());
}

inline void uCnsBowUpper::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uCnsBowUpper::DTI)->memFree(p_addr);
}

uCnsBowUpper::uCnsBowUpper() {
    mJoint = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 224) = 0;
    mScl.x = 1.0f;
    mScl.y = 1.0f;
    mScl.z = 1.0f;
    mScl.pad_ = 0.0f;
    mRot = MtVector3::Zero;
    mTrans = MtVector3::Zero;
    mDir = MtVector3::AxisZ;
}

uCnsBowUpper::~uCnsBowUpper() {
    removeConstraint();
}

cResource* uCnsBowUpper::getResource() {
    return nullptr;
}

__attribute__((weak)) void uCnsBowUpper::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uCnsBowUpper::adjust")
    /* stub */
}

void uCnsBowUpper::remove() {
    removeConstraint();
}

void uCnsBowUpper::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsBowUpper::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
    if (Num == 0) {
        return;
    }
    mJoint = (*pJnts)->mNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsBowUpper::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpCnsBowUpperRes", "resource", reinterpret_cast<MT_MFUNC>(&::uCnsBowUpper::getResource), reinterpret_cast<MT_MFUNC>(&::uConstraint::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mScl", &mScl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOrder", &(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 224)), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRot", &mRot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTrans", &mTrans, 0u, 0u);
}

MtUI* uCnsBowUpper::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

__attribute__((weak)) void uCnsBowUpper::draw(cDraw* pDraw) {
}

void uCnsBowUpper::set(uModel* pModel, u32 JntNo, u32 Pri) {
    setModel(pModel);
    setPri(Pri);
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

inline uCnsBowUpper::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsBowUpper::MyDTI uCnsBowUpper::DTI("uCnsBowUpper", &::uConstraint::DTI, 240ul, 0u, 0u);

MtObject* uCnsBowUpper::MyDTI::newInstance() const {
    return new (16u) uCnsBowUpper;
}

