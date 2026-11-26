// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlMeteo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cEfcHandle.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "../../XFramework/cUnit.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/rCollisionHeightField.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sShlManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlGenerator.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamMeteo::getDTI() const {
    return cShlParamMeteo::DTI;
}

inline void* cShlParamMeteo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamMeteo::DTI)->memAlloc(sz, align, cShlParamMeteo::DTI.getID());
}

inline void cShlParamMeteo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamMeteo::DTI)->memFree(p_addr);
}

MtDTI& cShlParamMeteo::getShlDTI() const {
    return uShlMeteo::DTI;
}

void cShlParamMeteo::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "distWallCheck", &distWallCheck, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "fallFrame", &fallFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "vanishTime", &vanishTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "moveCurve", &moveCurve, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNoHitExp", &shlNoHitExp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "noticeShlNo", &noticeShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoFall", &seNoFall, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "distance", &distance, 0u, 0u);
}

void cShlParamMeteo::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoKira", &epvNoKira, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoTarget", &epvNoTarget, 0u, 0u);
}

void cShlParamMeteo::createPropertySE(MtPropertyList& s) {
    this->cShlParamBase::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "seNoFall", &seNoFall, 0u, 0u);
}

cShlParamMeteo::~cShlParamMeteo() {
}

__attribute__((weak)) void cShlParamMeteo::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamMeteo::copy")
    /* stub */
}

inline cShlParamMeteo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamMeteo::MyDTI cShlParamMeteo::DTI("cShlParamMeteo", &::cShlParamBase::DTI, 464ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamMeteo::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamMeteo::DTI)->memAlloc(sizeof(cShlParamMeteo), 16u, cShlParamMeteo::DTI.getID())) cShlParamMeteo;
}

const MtDTI& cShlParamMeteoCtrl::getDTI() const {
    return cShlParamMeteoCtrl::DTI;
}

inline void* cShlParamMeteoCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamMeteoCtrl::DTI)->memAlloc(sz, align, cShlParamMeteoCtrl::DTI.getID());
}

inline void cShlParamMeteoCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamMeteoCtrl::DTI)->memFree(p_addr);
}

MtDTI& cShlParamMeteoCtrl::getShlDTI() const {
    return uShlMeteoCtrl::DTI;
}

void cShlParamMeteoCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamGenerator::createProperty(s);
}

void cShlParamMeteoCtrl::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamGenerator::createPropertyEffect(s);
}

void cShlParamMeteoCtrl::createPropertySE(MtPropertyList& s) {
    this->cShlParamBase::createPropertySE(s);
}

void cShlParamMeteoCtrl::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    isOwnerScaleOffset = static_cast<bool>(*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(pParamBase) + 352));
    generatorOption = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 392);
    if (shlList.mLength != 0) {
        u32 v0_0 = shlList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (shlList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete shlList.mpArray[i0_3];
                v1_0 = shlList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (shlList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(shlList.mpArray));
    }
    shlList.mpArray = nullptr;
    shlList.mBufsiz = 0;
    shlList.mLength = 0;
    addShlList(static_cast<const cShlParamGenerator*>(pParamBase));
}

inline cShlParamMeteoCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamMeteoCtrl::MyDTI cShlParamMeteoCtrl::DTI("cShlParamMeteoCtrl", &::cShlParamGenerator::DTI, 400ul, 0u, 0u);

MtObject* cShlParamMeteoCtrl::MyDTI::newInstance() const {
    return new (16u) cShlParamMeteoCtrl;
}

const MtDTI& uShlMeteo::getDTI() const {
    return uShlMeteo::DTI;
}

inline void* uShlMeteo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlMeteo::DTI)->memAlloc(sz, align, uShlMeteo::DTI.getID());
}

inline void uShlMeteo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlMeteo::DTI)->memFree(p_addr);
}

inline const cShlParamMeteo* uShlMeteo::getShlParam() const {
    return static_cast<const cShlParamMeteo*>(mpShlParam2);
}

uShlMeteo::~uShlMeteo() {
}

__attribute__((weak)) void uShlMeteo::setup() {
    DDON_STUB("uShlMeteo::setup")
    /* stub */
}

__attribute__((weak)) void uShlMeteo::initSub() {
    DDON_STUB("uShlMeteo::initSub")
    /* stub */
}

__attribute__((weak)) void uShlMeteo::updateSub() {
    DDON_STUB("uShlMeteo::updateSub")
    /* stub */
}

void uShlMeteo::kill() {
    if (mpTargetEfcHandle != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpTargetEfcHandle, 4u);
        mpTargetEfcHandle = nullptr;
    }
    this->uShlBase::kill();
}

void uShlMeteo::updatePtr() {
    this->uShlBase::updatePtr();
}

void uShlMeteo::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mpTargetEfcHandle == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpTargetEfcHandle)) {
        return;
    }
    mpTargetEfcHandle->mpOwner = nullptr;
    mpTargetEfcHandle = nullptr;
}

__attribute__((weak)) void uShlMeteo::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlMeteo::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uShlMeteo::checkScr() {
    DDON_STUB("uShlMeteo::checkScr")
    /* stub */
}

__attribute__((weak)) void uShlMeteo::createNoticeShl(u32 index) {
    DDON_STUB("uShlMeteo::createNoticeShl")
    /* stub */
}

__attribute__((weak)) uShlBase* uShlMeteo::createHitScrShl(u32 index, u32 shotSts, bool isNow) {
    DDON_STUB("uShlMeteo::createHitScrShl")
    return nullptr;
}

inline uShlMeteo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlMeteo::MyDTI uShlMeteo::DTI("uShlMeteo", &::uShlBase::DTI, 10976ul, 0u, 0u);

MtObject* uShlMeteo::MyDTI::newInstance() const {
    return new (16u) uShlMeteo;
}

const MtDTI& uShlMeteoCtrl::getDTI() const {
    return uShlMeteoCtrl::DTI;
}

inline void uShlMeteoCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlMeteoCtrl::DTI)->memFree(p_addr);
}

uShlMeteoCtrl::~uShlMeteoCtrl() {
}

void uShlMeteoCtrl::setup() {
    this->uShlGenerator::setup();
}

void uShlMeteoCtrl::updateSub() {
    this->uShlGenerator::updateSub();
}

void uShlMeteoCtrl::kill() {
    this->uShlBase::kill();
}

void uShlMeteoCtrl::updatePtr() {
    this->uShlBase::updatePtr();
}

void uShlMeteoCtrl::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
}

__attribute__((weak)) void uShlMeteoCtrl::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlMeteoCtrl::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uShlMeteoCtrl::setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY) {
    DDON_STUB("uShlMeteoCtrl::setShl")
    /* stub */
}

inline uShlMeteoCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlMeteoCtrl::MyDTI uShlMeteoCtrl::DTI("uShlMeteoCtrl", &::uShlGenerator::DTI, 11040ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlMeteoCtrl::MyDTI::newInstance() const {
    DDON_STUB("uShlMeteoCtrl::MyDTI::newInstance")
    return nullptr;
}

