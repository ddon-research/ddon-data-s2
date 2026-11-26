// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsHeadCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpHeadCtrl.h"
#include "../../XFramework/uConstraint.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCnsHeadCtrl::getDTI() const {
    return uCnsHeadCtrl::DTI;
}

inline MtAllocator* uCnsHeadCtrl::getAllocator() {
    return MtMemoryAllocator::getAllocator(uCnsHeadCtrl::DTI);
}

void* uCnsHeadCtrl::operator new(size_t sz, u32 align) {
    return uCnsHeadCtrl::getAllocator()->memAlloc(sz, align, uCnsHeadCtrl::DTI.getID());
}

inline void uCnsHeadCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uCnsHeadCtrl::DTI)->memFree(p_addr);
}

uCnsHeadCtrl::uCnsHeadCtrl() {
    mJoint = 0;
    mpHeadCtrl = nullptr;
    mRightLimit = -3.141593f;
    mLeftLimit = 3.141593f;
    mUpperLimit = -3.141593f;
    mLowerLimit = 3.141593f;
    mLocal = false;
    mAngleBlend = 1.0f;
    mPitchBlend = 1.0f;
    mLocalAxis = 0;
}

uCnsHeadCtrl::~uCnsHeadCtrl() {
}

__attribute__((weak)) void uCnsHeadCtrl::setResource(cResource* pRes) {
}

cResource* uCnsHeadCtrl::getResource() {
    return nullptr;
}

__attribute__((weak)) void uCnsHeadCtrl::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uCnsHeadCtrl::adjust")
    /* stub */
}

void uCnsHeadCtrl::remove() {
    removeConstraint();
}

void uCnsHeadCtrl::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsHeadCtrl::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
    if (Num == 0) {
        return;
    }
    mJoint = (*pJnts)->mNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsHeadCtrl::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mJoint", &mJoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLocalAxis", &mLocalAxis, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRightLimit", &mRightLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLeftLimit", &mLeftLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpperLimit", &mUpperLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowerLimit", &mLowerLimit, 0u, 0u);
}

MtUI* uCnsHeadCtrl::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

__attribute__((weak)) void uCnsHeadCtrl::draw(cDraw* pDraw) {
}

void uCnsHeadCtrl::set(uModel* pModel, u32 JntNo, u32 Pri) {
    setModel(pModel);
    setPri(Pri);
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

inline uCnsHeadCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsHeadCtrl::MyDTI uCnsHeadCtrl::DTI("uCnsHeadCtrl", &::uConstraint::DTI, 192ul, 0u, 0u);

MtObject* uCnsHeadCtrl::MyDTI::newInstance() const {
    return new (16u) uCnsHeadCtrl;
}

