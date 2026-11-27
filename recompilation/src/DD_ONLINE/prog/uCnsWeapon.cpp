// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsWeapon.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/uConstraint.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCnsWeapon::getDTI() const {
    return uCnsWeapon::DTI;
}

void* uCnsWeapon::operator new(size_t sz, u32 align) {
    return uCnsWeapon::getAllocator()->memAlloc(sz, align, uCnsWeapon::DTI.getID());
}

uCnsWeapon::uCnsWeapon() {
    mJoint = 0;
    mpWeapon = nullptr;
}

uCnsWeapon::~uCnsWeapon() {
}

__attribute__((weak)) void uCnsWeapon::setResource(cResource* pRes) {
}

cResource* uCnsWeapon::getResource() {
    return nullptr;
}

__attribute__((weak)) void uCnsWeapon::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uCnsWeapon::adjust")
    /* stub */
}

void uCnsWeapon::remove() {
    removeConstraint();
}

void uCnsWeapon::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsWeapon::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
    if (Num == 0) {
        return;
    }
    mJoint = (*pJnts)->mNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsWeapon::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
}

MtUI* uCnsWeapon::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

__attribute__((weak)) void uCnsWeapon::draw(cDraw* pDraw) {
}

void uCnsWeapon::set(uModel* pModel, u32 JntNo, u32 Pri) {
    setModel(pModel);
    setPri(Pri);
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

inline uCnsWeapon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsWeapon::MyDTI uCnsWeapon::DTI("uCnsWeapon", &::uConstraint::DTI, 160ul, 0u, 0u);

MtObject* uCnsWeapon::MyDTI::newInstance() const {
    return new (16u) uCnsWeapon;
}

