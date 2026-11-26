// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlStick.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextInterface.h"
#include "../../XFramework/cUnit.h"
#include "cpObjCollision.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "nShlBase.h"
#include "nShlStick.h"
#include "sSetManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamStick::getDTI() const {
    return cShlParamStick::DTI;
}

inline void* cShlParamStick::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamStick::DTI)->memAlloc(sz, align, cShlParamStick::DTI.getID());
}

inline void cShlParamStick::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamStick::DTI)->memFree(p_addr);
}

MtDTI& cShlParamStick::getShlDTI() const {
    return uShlStick::DTI;
}

cShlParamStick::~cShlParamStick() {
}

void cShlParamStick::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "stickOption", &stickOption, 0u, 0u);
}

void cShlParamStick::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamStick* pParam = static_cast<const cShlParamStick*>(pParamBase);
    stickOption = pParam->stickOption;
}

inline cShlParamStick::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamStick::MyDTI cShlParamStick::DTI("cShlParamStick", &::cShlParamBase::DTI, 368ul, 0u, 0u);

MtObject* cShlParamStick::MyDTI::newInstance() const {
    return new (16u) cShlParamStick;
}

const MtDTI& cShlParamStickCtrl::getDTI() const {
    return cShlParamStickCtrl::DTI;
}

inline void* cShlParamStickCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamStickCtrl::DTI)->memAlloc(sz, align, cShlParamStickCtrl::DTI.getID());
}

inline void cShlParamStickCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamStickCtrl::DTI)->memFree(p_addr);
}

MtDTI& cShlParamStickCtrl::getShlDTI() const {
    return uShlStickCtrl::DTI;
}

cShlParamStickCtrl::~cShlParamStickCtrl() {
}

void cShlParamStickCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "stickShlNo", &stickShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isControl", &isControl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "noConstShlNo", &noConstShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isInheritStickInfo", &isInheritStickInfo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isCallNotHitEndShl", &isCallNotHitEndShl, 0u, 0u);
}

void cShlParamStickCtrl::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamStickCtrl* pParam = static_cast<const cShlParamStickCtrl*>(pParamBase);
    stickShlNo = pParam->stickShlNo;
    isControl = pParam->isControl;
    isInheritStickInfo = pParam->isInheritStickInfo;
    noConstShlNo = pParam->noConstShlNo;
    isCallNotHitEndShl = pParam->isCallNotHitEndShl;
}

inline cShlParamStickCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamStickCtrl::MyDTI cShlParamStickCtrl::DTI("cShlParamStickCtrl", &::cShlParamBase::DTI, 368ul, 0u, 0u);

MtObject* cShlParamStickCtrl::MyDTI::newInstance() const {
    return new (16u) cShlParamStickCtrl;
}

const MtDTI& uShlStick::getDTI() const {
    return uShlStick::DTI;
}

inline void* uShlStick::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlStick::DTI)->memAlloc(sz, align, uShlStick::DTI.getID());
}

inline void uShlStick::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlStick::DTI)->memFree(p_addr);
}

inline const cShlParamStick* uShlStick::getShlParam() const {
    return static_cast<const cShlParamStick*>(mpShlParam2);
}

uShlStick::~uShlStick() {
    DDON_STUB("uShlStick::~uShlStick")
    /* stub */
}

__attribute__((weak)) void uShlStick::initSub() {
    DDON_STUB("uShlStick::initSub")
    /* stub */
}

__attribute__((weak)) void uShlStick::updateSub() {
    DDON_STUB("uShlStick::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlStick::updateStickPos() {
    DDON_STUB("uShlStick::updateStickPos")
    /* stub */
}

__attribute__((weak)) void uShlStick::updateStickAngle() {
    DDON_STUB("uShlStick::updateStickAngle")
    /* stub */
}

inline uShlStick::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlStick::MyDTI uShlStick::DTI("uShlStick", &::uShlBase::DTI, 10928ul, 0u, 0u);

MtObject* uShlStick::MyDTI::newInstance() const {
    return new (16u) uShlStick;
}

const MtDTI& uShlStickCtrl::getDTI() const {
    return uShlStickCtrl::DTI;
}

inline void* uShlStickCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlStickCtrl::DTI)->memAlloc(sz, align, uShlStickCtrl::DTI.getID());
}

inline void uShlStickCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlStickCtrl::DTI)->memFree(p_addr);
}

inline const cShlParamStickCtrl* uShlStickCtrl::getShlParam() const {
    return static_cast<const cShlParamStickCtrl*>(mpShlParam2);
}

uShlStickCtrl::~uShlStickCtrl() {
    DDON_STUB("uShlStickCtrl::~uShlStickCtrl")
    /* stub */
}

__attribute__((weak)) void uShlStickCtrl::sync() {
    DDON_STUB("uShlStickCtrl::sync")
    /* stub */
}

void uShlStickCtrl::setup() {
    this->uShlBase::setup();
    if (static_cast<int>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 356)) > -1) {
        if (mShotReqInfo.mLockOnIndex == -1) {
            createNextShl(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 356), 0u, false);
            requestKill();
            mIsAlreadyKill = true;
        }
    }
}

__attribute__((weak)) void uShlStickCtrl::update() {
    DDON_STUB("uShlStickCtrl::update")
    /* stub */
}

__attribute__((weak)) void uShlStickCtrl::callbackAttackTest(cHitInfo* pHitInfo) {
    DDON_STUB("uShlStickCtrl::callbackAttackTest")
    /* stub */
}

inline uShlStickCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlStickCtrl::MyDTI uShlStickCtrl::DTI("uShlStickCtrl", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlStickCtrl::MyDTI::newInstance() const {
    return new (16u) uShlStickCtrl;
}

