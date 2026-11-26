// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlFriendSupport.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cEfcHandle.h"
#include "../../XFramework/cUnit.h"
#include "cpEffectProvider.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamFriendSupport::getDTI() const {
    return cShlParamFriendSupport::DTI;
}

inline void* cShlParamFriendSupport::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamFriendSupport::DTI)->memAlloc(sz, align, cShlParamFriendSupport::DTI.getID());
}

inline void cShlParamFriendSupport::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamFriendSupport::DTI)->memFree(p_addr);
}

MtDTI& cShlParamFriendSupport::getShlDTI() const {
    return uShlFriendSupport::DTI;
}

cShlParamFriendSupport::~cShlParamFriendSupport() {
}

void cShlParamFriendSupport::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckShl", &mCheckShl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConstInterval", &mConstInterval, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpeedInit", &mSpeedInit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAccel", &mAccel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpeedLimit", &mSpeedLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDistanceLimit", &mDistanceLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgStopArrive", &mFlgStopArrive, 0u, 0u);
}

void cShlParamFriendSupport::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "mJobCommonEffectIndex", &mJobCommonEffectIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJobCommonEffectNo", &mJobCommonEffectNo, 0u, 0u);
}

__attribute__((weak)) void cShlParamFriendSupport::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamFriendSupport::copy")
    /* stub */
}

inline cShlParamFriendSupport::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamFriendSupport::MyDTI cShlParamFriendSupport::DTI("cShlParamFriendSupport", &::cShlParamBase::DTI, 400ul, 0u, 0u);

MtObject* cShlParamFriendSupport::MyDTI::newInstance() const {
    return new (16u) cShlParamFriendSupport;
}

const MtDTI& uShlFriendSupport::getDTI() const {
    return uShlFriendSupport::DTI;
}

inline void* uShlFriendSupport::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlFriendSupport::DTI)->memAlloc(sz, align, uShlFriendSupport::DTI.getID());
}

inline void uShlFriendSupport::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlFriendSupport::DTI)->memFree(p_addr);
}

const cShlParamFriendSupport* uShlFriendSupport::getShlParam() const {
    return static_cast<const cShlParamFriendSupport*>(getShlParamBase());
}

uShlFriendSupport::~uShlFriendSupport() {
}

__attribute__((weak)) void uShlFriendSupport::initSub() {
    DDON_STUB("uShlFriendSupport::initSub")
    /* stub */
}

void uShlFriendSupport::callbackCheck(cHitInfo* pHitInfo) {
    this->uShlBase::callbackCheck(pHitInfo);
}

__attribute__((weak)) void uShlFriendSupport::updateSub() {
    DDON_STUB("uShlFriendSupport::updateSub")
    /* stub */
}

void uShlFriendSupport::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mpJobCommonEfcHandle == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpJobCommonEfcHandle)) {
        return;
    }
    mpJobCommonEfcHandle->mpOwner = nullptr;
    mpJobCommonEfcHandle = nullptr;
}

void uShlFriendSupport::kill() {
    this->uShlBase::kill();
    if (mpJobCommonEfcHandle == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpJobCommonEfcHandle, 4u);
    mpJobCommonEfcHandle = nullptr;
}

inline uShlFriendSupport::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlFriendSupport::MyDTI uShlFriendSupport::DTI("uShlFriendSupport", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlFriendSupport::MyDTI::newInstance() const {
    return new (16u) uShlFriendSupport;
}

