// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpWallMaria.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "cpOcdCtrl.h"
#include "cpScrCollision.h"
#include "../../generated/shared/nDDOMath.h"
#include "rEmWeakSafe.h"
#include "../../XFramework/sCollision.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpWallMaria::getDTI() const {
    return cpWallMaria::DTI;
}

void* cpWallMaria::operator new(size_t sz, u32 align) {
    return cpWallMaria::getAllocator()->memAlloc(sz, align, cpWallMaria::DTI.getID());
}

cpWallMaria::cpWallMaria() {
    DDON_STUB("cpWallMaria::cpWallMaria")
    /* stub */
}

void cpWallMaria::setup() {
    this->cpComponent::setup();
    mSphereSafe.r = 5.0f;
}

__attribute__((weak)) void cpWallMaria::after() {
    DDON_STUB("cpWallMaria::after")
    /* stub */
}

void cpWallMaria::kill() {
    if (mpWeakSafe == nullptr) {
        return;
    }
    mpWeakSafe->release();
    mpWeakSafe = nullptr;
}

void cpWallMaria::updatePtr() {
    this->cpComponent::updatePtr();
}

void cpWallMaria::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mOldPos.x = offset.x + mOldPos.x;
    mOldPos.y = offset.y + mOldPos.y;
    mOldPos.z = offset.z + mOldPos.z;
}

void cpWallMaria::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

__attribute__((weak)) void cpWallMaria::setResource(rEmWeakSafe* pRes) {
    DDON_STUB("cpWallMaria::setResource")
    /* stub */
}

inline cpWallMaria::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpWallMaria::MyDTI cpWallMaria::DTI("cpWallMaria", &::cpComponent::DTI, 192ul, 0u, 0u);

__attribute__((weak)) MtObject* cpWallMaria::MyDTI::newInstance() const {
    DDON_STUB("cpWallMaria::MyDTI::newInstance")
    return nullptr;
}

