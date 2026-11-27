// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpHumanWarpCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cDelegate.h"
#include "cpActionRequest.h"
#include "cpComponent.h"
#include "cpSafePos.h"
#include "nDDOUtility.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sPlayerManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpHumanWarpCtrl::getDTI() const {
    return cpHumanWarpCtrl::DTI;
}

void* cpHumanWarpCtrl::operator new(size_t sz, u32 align) {
    return cpHumanWarpCtrl::getAllocator()->memAlloc(sz, align, cpHumanWarpCtrl::DTI.getID());
}

cpHumanWarpCtrl::cpHumanWarpCtrl() {
    const f32 t0 = MtVector3::Zero.y;
    const f32 t1 = MtVector3::Zero.z;
    mHumanWarpInfo.elems[0].mWarpWorldPos.x = MtVector3::Zero.x;
    mHumanWarpInfo.elems[0].mWarpWorldPos.y = t0;
    mHumanWarpInfo.elems[0].mWarpWorldPos.z = t1;
    mHumanWarpInfo.elems[0].mWarpWorldPos.pad_ = 0.0f;
    mHumanWarpInfo.elems[0].mWarpAngle = 0.0f;
    mHumanWarpInfo.elems[0].mWarpRno = 0;
    mpHuman = nullptr;
}

__attribute__((weak)) void cpHumanWarpCtrl::setup() {
    DDON_STUB("cpHumanWarpCtrl::setup")
    /* stub */
}

__attribute__((weak)) void cpHumanWarpCtrl::kill() {
}

void cpHumanWarpCtrl::updatePtr() {
    this->cpComponent::updatePtr();
}

__attribute__((weak)) void cpHumanWarpCtrl::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
}

void cpHumanWarpCtrl::before() {
    beforeSubOneWayOm();
}

__attribute__((weak)) void cpHumanWarpCtrl::update() {
}

__attribute__((weak)) void cpHumanWarpCtrl::after() {
}

void cpHumanWarpCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    const MtDTI& t0 = pOwner->getDTI();
    MT_CTSTR v0_1 = uHuman::DTI.mName;
    if (v0_1 != t0.mName) {
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_0->mpParent == nullptr) {
                mpHuman = nullptr;
                return;
            } else {
                if (v0_1 != v0_0->mpParent->mName) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    mpHuman = static_cast<uHuman*>(pOwner);
}

void cpHumanWarpCtrl::requestOneWayWarp(const MtVector3& worldPos, const f32 angle) {
    mHumanWarpInfo.elems[0].mWarpRno = 1;
    mHumanWarpInfo.elems[0].mWarpWorldPos = worldPos;
    mHumanWarpInfo.elems[0].mWarpAngle = angle;
}

__attribute__((weak)) void cpHumanWarpCtrl::beforeSubOneWayOm() {
    DDON_STUB("cpHumanWarpCtrl::beforeSubOneWayOm")
    /* stub */
}

inline cpHumanWarpCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpHumanWarpCtrl::MyDTI cpHumanWarpCtrl::DTI("cpHumanWarpCtrl", &::cpComponent::DTI, 128ul, 0u, 0u);

MtObject* cpHumanWarpCtrl::MyDTI::newInstance() const {
    return new (16u) cpHumanWarpCtrl;
}

