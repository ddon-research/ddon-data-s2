// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlElementCover.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cEfcHandle.h"
#include "../../generated/shared/nDDOGame.h"
#include "nDDOUtility.h"
#include "rEffectProvider.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "uShlBase.h"
#include "uShlCondition.h"
#include "uShlCustomCondition.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamElemntCover::getDTI() const {
    return cShlParamElemntCover::DTI;
}

inline void cShlParamElemntCover::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamElemntCover::DTI)->memFree(p_addr);
}

MtDTI& cShlParamElemntCover::getShlDTI() const {
    return uShlElementCover::DTI;
}

__attribute__((weak)) void cShlParamElemntCover::createProperty(MtPropertyList& proplist) {
    cShlParamCustomConditionBase::createProperty(proplist);
    for (u8 i = 0; i < 10; i++) {
        proplist << MtProperty(static_cast<MtObject*>(this), "mAdjustRateCover", mAdjustRateCover, MtProperty::ATTR_ARRAY, 10);
        proplist << MtProperty(static_cast<MtObject*>(this), "adjustRateDamage", adjustRateDamage, MtProperty::ATTR_ARRAY, 10);
    }
}

void cShlParamElemntCover::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_FIRE].mEpvIndex", &mEffectInfo.elems[2].mEpvIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_FIRE].mEpvElement", &mEffectInfo.elems[2].mEpvElement, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_ICE].mEpvIndex", &mEffectInfo.elems[3].mEpvIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_ICE].mEpvElement", &mEffectInfo.elems[3].mEpvElement, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_THUNDER].mEpvIndex", &mEffectInfo.elems[4].mEpvIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_THUNDER].mEpvElement", &mEffectInfo.elems[4].mEpvElement, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_HOLY].mEpvIndex", &mEffectInfo.elems[5].mEpvIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_HOLY].mEpvElement", &mEffectInfo.elems[5].mEpvElement, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_DARK].mEpvIndex", &mEffectInfo.elems[6].mEpvIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_DARK].mEpvElement", &mEffectInfo.elems[6].mEpvElement, 0u, 0u);
}

void cShlParamElemntCover::createPropertySE(MtPropertyList& s) {
    this->cShlParamBase::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_FIRE].mSeReqNo", &mEffectInfo.elems[2].mSeReqNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_ICE].mSeReqNo", &mEffectInfo.elems[3].mSeReqNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_THUNDER].mSeReqNo", &mEffectInfo.elems[4].mSeReqNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_HOLY].mSeReqNo", &mEffectInfo.elems[5].mSeReqNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectInfo[nDDOGame::ELEMENT_TYPE_DARK].mSeReqNo", &mEffectInfo.elems[6].mSeReqNo, 0u, 0u);
}

__attribute__((weak)) void cShlParamElemntCover::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamElemntCover::copy")
    /* stub */
}

inline cShlParamElemntCover::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamElemntCover::MyDTI cShlParamElemntCover::DTI("cShlParamElemntCover", &::cShlParamCustomConditionBase::DTI, 608ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamElemntCover::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamElemntCover::DTI)->memAlloc(sizeof(cShlParamElemntCover), 16u, cShlParamElemntCover::DTI.getID())) cShlParamElemntCover;
}

const MtDTI& uShlElementCover::getDTI() const {
    return uShlElementCover::DTI;
}

inline void uShlElementCover::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlElementCover::DTI)->memFree(p_addr);
}

inline const cShlParamElemntCover* uShlElementCover::getShlParam() const {
    return static_cast<const cShlParamElemntCover*>(mpShlParam2);
}

__attribute__((weak)) void uShlElementCover::setup() {
    DDON_STUB("uShlElementCover::setup")
    /* stub */
}

__attribute__((weak)) void uShlElementCover::initSub() {
    DDON_STUB("uShlElementCover::initSub")
    /* stub */
}

void uShlElementCover::kill() {
    this->uShlBase::kill();
    if (mpCoverEffHandle == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpCoverEffHandle, 4u);
    mpCoverEffHandle = nullptr;
}

void uShlElementCover::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mpCoverEffHandle == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpCoverEffHandle)) {
        return;
    }
    mpCoverEffHandle->mpOwner = nullptr;
    mpCoverEffHandle = nullptr;
}

__attribute__((weak)) void uShlElementCover::setCoverEffect() {
    DDON_STUB("uShlElementCover::setCoverEffect")
    /* stub */
}

void uShlElementCover::setElementTypeCover(nDDOGame::ELEMENT_TYPE type) {
    mElementTypeCover = type;
}

__attribute__((weak)) void uShlElementCover::reCreateInfo() {
    DDON_STUB("uShlElementCover::reCreateInfo")
    /* stub */
}

inline uShlElementCover::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlElementCover::MyDTI uShlElementCover::DTI("uShlElementCover", &::uShlCustomConditionBase::DTI, 10976ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlElementCover::MyDTI::newInstance() const {
    DDON_STUB("uShlElementCover::MyDTI::newInstance")
    return nullptr;
}

