// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpWallExitCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "sWorkRate.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpWallExitCtrl::getDTI() const {
    return cpWallExitCtrl::DTI;
}

void* cpWallExitCtrl::operator new(size_t sz, u32 align) {
    return cpWallExitCtrl::getAllocator()->memAlloc(sz, align, cpWallExitCtrl::DTI.getID());
}

cpWallExitCtrl::cpWallExitCtrl() {
    mWallState = STATE_NONE;
    mpModel = nullptr;
    mWallHitTimer = 0.0f;
    mWallExitFrame = 30.0f;
    mMoveDir = -1.0f;
    mExitSpeed = 0.0f;
    mExitSpeedMax = 60.0f;
    mExitAdd = 1.0f;
}

void cpWallExitCtrl::setup() {
    this->cpComponent::setup();
}

void cpWallExitCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

void cpWallExitCtrl::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

void cpWallExitCtrl::callbackHitWall_Init(cWallHitInfo& hitInfo) {
    mWallHitTimer = mWallExitFrame;
    mWallState = STATE_NONE;
    mMoveDir = -1.0f;
    mExitSpeed = 0.0f;
}

__attribute__((weak)) void cpWallExitCtrl::callbackHitWall_Move(cWallHitInfo& hitInfo) {
    DDON_STUB("cpWallExitCtrl::callbackHitWall_Move")
    /* stub */
}

void cpWallExitCtrl::callbackHitWall_Final(cWallHitInfo& hitInfo) {
    mWallHitTimer = mWallExitFrame;
    mWallState = STATE_NONE;
    mMoveDir = -1.0f;
    mExitSpeed = 0.0f;
}

inline cpWallExitCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpWallExitCtrl::MyDTI cpWallExitCtrl::DTI("cpWallExitCtrl", &::cpComponent::DTI, 120ul, 0u, 0u);

MtObject* cpWallExitCtrl::MyDTI::newInstance() const {
    return new (16u) cpWallExitCtrl;
}

