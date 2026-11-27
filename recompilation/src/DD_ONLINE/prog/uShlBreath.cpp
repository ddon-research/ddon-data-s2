// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlBreath.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cEfcHandle.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "cHitNode.h"
#include "cpObjCollision.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/rCollisionHeightField.h"
#include "rEffectProvider.h"
#include "../../XFramework/sCollision.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uEffect.h"
#include "uEffectExt.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamBreath::getDTI() const {
    return cShlParamBreath::DTI;
}

inline void cShlParamBreath::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamBreath::DTI)->memFree(p_addr);
}

MtDTI& cShlParamBreath::getShlDTI() const {
    return uShlBreath::DTI;
}

cShlParamBreath::~cShlParamBreath() {
}

void cShlParamBreath::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "\347\231\272\345\260\204\344\275\215\347\275\256\343\201\250\345\220\221\343\201\215", &FireMatrix, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNoneLockOnShopType", &mNoneLockOnShopType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "limitAngle", &limitAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dieDist", &dieDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dieFlag", &dieFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitShlNo", &hitShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "floorHitShlNo", &floorHitShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dirAdjustDist", &dirAdjustDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isEnchantShotSE", &isEnchantShotSE, 0u, 0u);
}

void cShlParamBreath::createPropertyCollision(MtPropertyList& s) {
    this->cShlParamBase::createPropertyCollision(s);
    s << MtProperty(static_cast<MtObject*>(this), "EPV Hit Index", &mHitEpvIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "EPV Hit No", &mHitEpvNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\231\272\345\260\204\346\231\202\343\202\265\343\202\244\343\202\272(\357\275\236\345\200\215)", &mHitStartSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\234\200\345\244\247\346\231\202\343\202\265\343\202\244\343\202\272(\357\275\236\345\200\215)", &mHitLimitSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\265\343\202\244\343\202\272\345\244\211\345\214\226\351\226\213\345\247\213\350\267\235\351\233\242", &mHitSizeChangeStartDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\244\211\345\214\226\350\267\235\351\233\242\343\202\271\343\203\206\343\203\203\343\203\227(\357\275\236cm\346\257\216)", &mHitStepDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\271\343\203\206\343\203\203\343\203\227\346\257\216\343\201\256\345\244\211\345\214\226\343\202\265\343\202\244\343\202\272", &mHitStepSize, 0u, 0u);
}

void cShlParamBreath::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoScrHit", &epvNoScrHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scrHitEfType", reinterpret_cast<s32*>(&scrHitEfType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoHitSlow", &epvNoHitSlow, 0u, 0u);
}

void cShlParamBreath::createPropertySE(MtPropertyList& s) {
    this->cShlParamBase::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "seNoScrHit", &seNoScrHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoHitSlow", &seNoHitSlow, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoHitSlowStop", &seNoHitSlowStop, 0u, 0u);
}

__attribute__((weak)) void cShlParamBreath::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamBreath::copy")
    /* stub */
}

inline cShlParamBreath::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamBreath::MyDTI cShlParamBreath::DTI("cShlParamBreath", &::cShlParamBase::DTI, 512ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamBreath::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamBreath::DTI)->memAlloc(sizeof(cShlParamBreath), 16u, cShlParamBreath::DTI.getID())) cShlParamBreath;
}

const MtDTI& uShlBreath::getDTI() const {
    return uShlBreath::DTI;
}

uShlBreath::~uShlBreath() {
    if (mpEpvHitHandle == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpEpvHitHandle, 2u);
    mpEpvHitHandle = nullptr;
}

__attribute__((weak)) void uShlBreath::setup() {
    DDON_STUB("uShlBreath::setup")
    /* stub */
}

void uShlBreath::initSub() {
    this->uShlBase::initSub();
}

__attribute__((weak)) void uShlBreath::updateSub() {
    DDON_STUB("uShlBreath::updateSub")
    /* stub */
}

void uShlBreath::kill() {
    getObjCollisionPtr()->killNodeAll();
    if (mpEpvHitHandle != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpEpvHitHandle, 4u);
        mpEpvHitHandle = nullptr;
    }
    this->uShlBase::kill();
}

void uShlBreath::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mpEpvHitHandle == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpEpvHitHandle)) {
        return;
    }
    mpEpvHitHandle->mpOwner = nullptr;
    mpEpvHitHandle = nullptr;
}

u32 uShlBreath::getCollisionIndex() const {
    return 0;
}

void uShlBreath::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    this->uShlBase::applyWorldOffset(offset, absolute_offset);
}

__attribute__((weak)) void uShlBreath::updateCollision() {
    DDON_STUB("uShlBreath::updateCollision")
    /* stub */
}

__attribute__((weak)) void uShlBreath::checkScr() {
    DDON_STUB("uShlBreath::checkScr")
    /* stub */
}

inline uShlBreath::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlBreath::MyDTI uShlBreath::DTI("uShlBreath", &::uShlBase::DTI, 11136ul, 0u, 0u);

MtObject* uShlBreath::MyDTI::newInstance() const {
    return new (16u) uShlBreath;
}

