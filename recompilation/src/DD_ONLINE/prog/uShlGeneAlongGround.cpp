// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlGeneAlongGround.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlGenerator.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamGeneAlongGround::getDTI() const {
    return cShlParamGeneAlongGround::DTI;
}

MtDTI& cShlParamGeneAlongGround::getShlDTI() const {
    return uShlGeneAlongGround::DTI;
}

cShlParamGeneAlongGround::~cShlParamGeneAlongGround() {
}

void cShlParamGeneAlongGround::createProperty(MtPropertyList& s) {
    this->cShlParamGenerator::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mGroundCheckYMax", &mGroundCheckYMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroundCheckYMin", &mGroundCheckYMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWallCheck", &mWallCheck, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWallCheckHeight", &mWallCheckHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWallCheckCreateForOnce", &mWallCheckCreateForOnce, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCliffSafeOffset", &mCliffSafeOffset, 0u, 0u);
}

__attribute__((weak)) void cShlParamGeneAlongGround::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamGeneAlongGround::copy")
    /* stub */
}

inline cShlParamGeneAlongGround::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamGeneAlongGround::MyDTI cShlParamGeneAlongGround::DTI("cShlParamGeneAlongGround", &::cShlParamGenerator::DTI, 432ul, 0u, 0u);

MtObject* cShlParamGeneAlongGround::MyDTI::newInstance() const {
    return new (16u) cShlParamGeneAlongGround;
}

const MtDTI& uShlGeneAlongGround::getDTI() const {
    return uShlGeneAlongGround::DTI;
}

uShlGeneAlongGround::~uShlGeneAlongGround() {
}

void uShlGeneAlongGround::setup() {
    this->uShlGenerator::setup();
    mLastGeneratPos = mPos;
}

void uShlGeneAlongGround::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    this->uShlBase::applyWorldOffset(offset, absolute_offset);
    mLastGeneratPos.x = offset.x + mLastGeneratPos.x;
    mLastGeneratPos.y = offset.y + mLastGeneratPos.y;
    mLastGeneratPos.z = offset.z + mLastGeneratPos.z;
}

__attribute__((weak)) void uShlGeneAlongGround::setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY) {
    DDON_STUB("uShlGeneAlongGround::setShl")
    /* stub */
}

__attribute__((weak)) bool uShlGeneAlongGround::enableCreateShell(MtVector3& pos, const MtVector3& cliff_safe_pos) {
    DDON_STUB("uShlGeneAlongGround::enableCreateShell")
    return {};
}

inline uShlGeneAlongGround::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlGeneAlongGround::MyDTI uShlGeneAlongGround::DTI("uShlGeneAlongGround", &::uShlGenerator::DTI, 10976ul, 0u, 0u);

MtObject* uShlGeneAlongGround::MyDTI::newInstance() const {
    return new (16u) uShlGeneAlongGround;
}

