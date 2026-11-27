// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlLaser.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cEfcHandle.h"
#include "rEffectProvider.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/uCoord.h"
#include "uEffectExt.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamLaser::getDTI() const {
    return cShlParamLaser::DTI;
}

inline void cShlParamLaser::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamLaser::DTI)->memFree(p_addr);
}

MtDTI& cShlParamLaser::getShlDTI() const {
    return uShlLaser::DTI;
}

void cShlParamLaser::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mLaserBaseLength", &mLaserBaseLength, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxScale", &mMaxScale, 0u, 0u);
}

void cShlParamLaser::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "mLandEffectNo", &mLandEffectNo, 0u, 0u);
}

void cShlParamLaser::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamLaser* pParam = static_cast<const cShlParamLaser*>(pParamBase);
    mLaserBaseLength = pParam->mLaserBaseLength;
    mMaxScale = pParam->mMaxScale;
    mLandEffectNo = pParam->mLandEffectNo;
}

inline cShlParamLaser::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamLaser::MyDTI cShlParamLaser::DTI("cShlParamLaser", &::cShlParamBase::DTI, 368ul, 0u, 0u);

MtObject* cShlParamLaser::MyDTI::newInstance() const {
    return new (16u) cShlParamLaser;
}

const MtDTI& uShlLaser::getDTI() const {
    return uShlLaser::DTI;
}

void uShlLaser::setup() {
    this->uShlBase::setup();
}

void uShlLaser::kill() {
    this->uShlBase::kill();
    if (mpEfcHandleLand == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpEfcHandleLand, 4u);
    mpEfcHandleLand = nullptr;
}

__attribute__((weak)) void uShlLaser::update() {
    DDON_STUB("uShlLaser::update")
    /* stub */
}

void uShlLaser::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mpEfcHandleLand == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpEfcHandleLand)) {
        return;
    }
    mpEfcHandleLand->mpOwner = nullptr;
    mpEfcHandleLand = nullptr;
}

void uShlLaser::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    this->uShlBase::applyWorldOffset(offset, absolute_offset);
    mHitLandPos.x = offset.x + mHitLandPos.x;
    mHitLandPos.y = offset.y + mHitLandPos.y;
    mHitLandPos.z = offset.z + mHitLandPos.z;
}

inline uShlLaser::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlLaser::MyDTI uShlLaser::DTI("uShlLaser", &::uShlBase::DTI, 10976ul, 0u, 0u);

MtObject* uShlLaser::MyDTI::newInstance() const {
    return new (16u) uShlLaser;
}

