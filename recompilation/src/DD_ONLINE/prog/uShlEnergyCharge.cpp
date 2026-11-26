// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlEnergyCharge.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "../../XFramework/cResource.h"
#include "cpObjCollision.h"
#include "cpShlShotCtrl.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "uControl.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamEnergyCharge::getDTI() const {
    return cShlParamEnergyCharge::DTI;
}

inline void* cShlParamEnergyCharge::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamEnergyCharge::DTI)->memAlloc(sz, align, cShlParamEnergyCharge::DTI.getID());
}

inline void cShlParamEnergyCharge::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamEnergyCharge::DTI)->memFree(p_addr);
}

MtDTI& cShlParamEnergyCharge::getShlDTI() const {
    return uShlEnergyCharge::DTI;
}

void cShlParamEnergyCharge::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxPowerVal", &mMaxPowerVal, 0u, 0u);
}

cShlParamEnergyCharge::~cShlParamEnergyCharge() {
}

void cShlParamEnergyCharge::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamEnergyCharge* pParam = static_cast<const cShlParamEnergyCharge*>(pParamBase);
    mMaxPowerVal = pParam->mMaxPowerVal;
}

inline cShlParamEnergyCharge::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamEnergyCharge::MyDTI cShlParamEnergyCharge::DTI("cShlParamEnergyCharge", &::cShlParamBase::DTI, 368ul, 0u, 0u);

MtObject* cShlParamEnergyCharge::MyDTI::newInstance() const {
    return new (16u) cShlParamEnergyCharge;
}

const MtDTI& uShlEnergyCharge::getDTI() const {
    return uShlEnergyCharge::DTI;
}

inline void* uShlEnergyCharge::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlEnergyCharge::DTI)->memAlloc(sz, align, uShlEnergyCharge::DTI.getID());
}

inline void uShlEnergyCharge::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlEnergyCharge::DTI)->memFree(p_addr);
}

inline const cShlParamEnergyCharge* uShlEnergyCharge::getShlParam() const {
    return static_cast<const cShlParamEnergyCharge*>(mpShlParam2);
}

uShlEnergyCharge::~uShlEnergyCharge() {
}

__attribute__((weak)) void uShlEnergyCharge::setup() {
    DDON_STUB("uShlEnergyCharge::setup")
    /* stub */
}

__attribute__((weak)) void uShlEnergyCharge::updateSub() {
}

__attribute__((weak)) void uShlEnergyCharge::kill() {
    DDON_STUB("uShlEnergyCharge::kill")
    /* stub */
}

void uShlEnergyCharge::updatePtr() {
    this->uShlBase::updatePtr();
}

void uShlEnergyCharge::callbackCheck(cHitInfo* pHitInfo) {
    this->uShlBase::callbackCheck(pHitInfo);
}

void uShlEnergyCharge::callbackDamage(cHitInfo* pHitInfo) {
    this->uShlBase::callbackDamage(pHitInfo);
}

__attribute__((weak)) void uShlEnergyCharge::executeAddDamage() {
    DDON_STUB("uShlEnergyCharge::executeAddDamage")
    /* stub */
}

inline uShlEnergyCharge::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlEnergyCharge::MyDTI uShlEnergyCharge::DTI("uShlEnergyCharge", &::uShlBase::DTI, 10928ul, 0u, 0u);

MtObject* uShlEnergyCharge::MyDTI::newInstance() const {
    return new (16u) uShlEnergyCharge;
}

