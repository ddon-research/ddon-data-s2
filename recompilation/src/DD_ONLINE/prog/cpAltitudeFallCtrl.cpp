// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpAltitudeFallCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "cCharParamEnemy.h"
#include "cContextPlayerInfo.h"
#include "cDelegate.h"
#include "cpActionRequest.h"
#include "cpComponent.h"
#include "cpScrCollision.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpAltitudeFallCtrl::getDTI() const {
    return cpAltitudeFallCtrl::DTI;
}

void* cpAltitudeFallCtrl::operator new(size_t sz, u32 align) {
    return cpAltitudeFallCtrl::getAllocator()->memAlloc(sz, align, cpAltitudeFallCtrl::DTI.getID());
}

cpAltitudeFallCtrl::cpAltitudeFallCtrl() {
    DDON_STUB("cpAltitudeFallCtrl::cpAltitudeFallCtrl")
    /* stub */
}

cpAltitudeFallCtrl::~cpAltitudeFallCtrl() {
    DDON_STUB("cpAltitudeFallCtrl::~cpAltitudeFallCtrl")
    /* stub */
}

__attribute__((weak)) void cpAltitudeFallCtrl::setup() {
    DDON_STUB("cpAltitudeFallCtrl::setup")
    /* stub */
}

void cpAltitudeFallCtrl::updatePtr() {
    this->cpComponent::updatePtr();
}

__attribute__((weak)) void cpAltitudeFallCtrl::after() {
    DDON_STUB("cpAltitudeFallCtrl::after")
    /* stub */
}

void cpAltitudeFallCtrl::setCharParamEnemy(cCharParamEnemy* pParam) {
    if (pParam != nullptr) {
        mDamageHeight = -pParam->mFallDamageCheckHeight;
    } else {
        mDamageHeight = -1000.0f;
    }
}

__attribute__((weak)) void cpAltitudeFallCtrl::callbackHitLand() {
    DDON_STUB("cpAltitudeFallCtrl::callbackHitLand")
    /* stub */
}

__attribute__((weak)) void cpAltitudeFallCtrl::callbackFall() {
    DDON_STUB("cpAltitudeFallCtrl::callbackFall")
    /* stub */
}

inline cpAltitudeFallCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpAltitudeFallCtrl::MyDTI cpAltitudeFallCtrl::DTI("cpAltitudeFallCtrl", &::cpComponent::DTI, 168ul, 0u, 0u);

__attribute__((weak)) MtObject* cpAltitudeFallCtrl::MyDTI::newInstance() const {
    DDON_STUB("cpAltitudeFallCtrl::MyDTI::newInstance")
    return nullptr;
}

