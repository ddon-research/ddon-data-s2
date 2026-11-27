// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsLegCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/uConstraint.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCnsLegCtrl::getDTI() const {
    return uCnsLegCtrl::DTI;
}

void* uCnsLegCtrl::operator new(size_t sz, u32 align) {
    return uCnsLegCtrl::getAllocator()->memAlloc(sz, align, uCnsLegCtrl::DTI.getID());
}

uCnsLegCtrl::uCnsLegCtrl() {
    DDON_STUB("uCnsLegCtrl::uCnsLegCtrl")
    /* stub */
}

uCnsLegCtrl::~uCnsLegCtrl() {
}

__attribute__((weak)) void uCnsLegCtrl::setResource(cResource* pRes) {
}

cResource* uCnsLegCtrl::getResource() {
    return nullptr;
}

__attribute__((weak)) void uCnsLegCtrl::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uCnsLegCtrl::adjust")
    /* stub */
}

void uCnsLegCtrl::remove() {
    removeConstraint();
}

void uCnsLegCtrl::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsLegCtrl::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
    if (Num == 0) {
        return;
    }
    mJoint = (*pJnts)->mNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsLegCtrl::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mEnableCenterRot", &mEnableCenterRot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotMat", &mRotMat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffset", &mOffset, 0u, 0u);
}

MtUI* uCnsLegCtrl::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

__attribute__((weak)) void uCnsLegCtrl::draw(cDraw* pDraw) {
}

void uCnsLegCtrl::set(uModel* pModel, u32 JntNo, u32 Pri) {
    setModel(pModel);
    setPri(Pri);
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

inline uCnsLegCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsLegCtrl::MyDTI uCnsLegCtrl::DTI("uCnsLegCtrl", &::uConstraint::DTI, 320ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsLegCtrl::MyDTI::newInstance() const {
    DDON_STUB("uCnsLegCtrl::MyDTI::newInstance")
    return nullptr;
}

