// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpPivotCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpPivotCtrl::getDTI() const {
    return cpPivotCtrl::DTI;
}

void* cpPivotCtrl::operator new(size_t sz, u32 align) {
    return cpPivotCtrl::getAllocator()->memAlloc(sz, align, cpPivotCtrl::DTI.getID());
}

cpPivotCtrl::cpPivotCtrl() {
    mpModel = nullptr;
    mPivotPos = MtVector3::Zero;
    mPivotJointNo = 255;
    mPivotOffset = MtVector3::Zero;
    mOrgPos = MtVector3::Zero;
}

cpPivotCtrl::~cpPivotCtrl() {
}

void cpPivotCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

void cpPivotCtrl::setup() {
    this->cpComponent::setup();
    mpModel = static_cast<uDDOModel*>(getOwner());
}

void cpPivotCtrl::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

void cpPivotCtrl::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mOrgPos.x = offset.x + mOrgPos.x;
    mOrgPos.y = offset.y + mOrgPos.y;
    mOrgPos.z = offset.z + mOrgPos.z;
    mOrgPosModel.x = offset.x + mOrgPosModel.x;
    mOrgPosModel.y = offset.y + mOrgPosModel.y;
    mOrgPosModel.z = offset.z + mOrgPosModel.z;
    mPivotPos.x = offset.x + mPivotPos.x;
    mPivotPos.y = offset.y + mPivotPos.y;
    mPivotPos.z = offset.z + mPivotPos.z;
}

__attribute__((weak)) void cpPivotCtrl::setActive(bool active) {
    DDON_STUB("cpPivotCtrl::setActive")
    /* stub */
}

__attribute__((weak)) void cpPivotCtrl::before() {
    DDON_STUB("cpPivotCtrl::before")
    /* stub */
}

__attribute__((weak)) void cpPivotCtrl::after() {
    DDON_STUB("cpPivotCtrl::after")
    /* stub */
}

__attribute__((weak)) void cpPivotCtrl::setPivotOffset(const MtVector3& offset) {
    DDON_STUB("cpPivotCtrl::setPivotOffset")
    /* stub */
}

__attribute__((weak)) void cpPivotCtrl::setPivotPos(const MtVector3& pos) {
    DDON_STUB("cpPivotCtrl::setPivotPos")
    /* stub */
}

inline cpPivotCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpPivotCtrl::MyDTI cpPivotCtrl::DTI("cpPivotCtrl", &::cpComponent::DTI, 160ul, 0u, 0u);

MtObject* cpPivotCtrl::MyDTI::newInstance() const {
    return new (16u) cpPivotCtrl;
}

