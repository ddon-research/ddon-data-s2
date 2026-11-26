// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlRenmadanCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cEfcHandle.h"
#include "../../XFramework/cUnit.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "nShlStick.h"
#include "rEffectProvider.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sSetManager.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlHoming.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamRenmadanCtrl::getDTI() const {
    return cShlParamRenmadanCtrl::DTI;
}

inline void* cShlParamRenmadanCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamRenmadanCtrl::DTI)->memAlloc(sz, align, cShlParamRenmadanCtrl::DTI.getID());
}

inline void cShlParamRenmadanCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamRenmadanCtrl::DTI)->memFree(p_addr);
}

MtDTI& cShlParamRenmadanCtrl::getShlDTI() const {
    return uShlRenmadanCtrl::DTI;
}

void cShlParamRenmadanCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "renmaMainShotNo", &renmaMainShotNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "renmaHitHomingNo", &renmaHitHomingNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "renmaNoHitShlNo", &renmaNoHitShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "renmaSubWaitTime", &renmaSubWaitTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "renmaSubList", static_cast<MtObject*>(&renmaSubList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "renmaSubInterval", &renmaSubInterval, 0u, 0u);
}

__attribute__((noinline)) cShlParamRenmadanCtrl::~cShlParamRenmadanCtrl() {
    for (u32 i = 0; i < renmaSubList.mLength; i++) {
        delete renmaSubList.mpArray[i];
    }
    if (renmaSubList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(renmaSubList.mpArray));
    }
    renmaSubList.mpArray = nullptr;
    renmaSubList.mBufsiz = 0;
    renmaSubList.mLength = 0;
}

void cShlParamRenmadanCtrl::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamRenmadanCtrl* pParam = static_cast<const cShlParamRenmadanCtrl*>(pParamBase);
    renmaMainShotNo = pParam->renmaMainShotNo;
    renmaHitHomingNo = pParam->renmaHitHomingNo;
    renmaNoHitShlNo = pParam->renmaNoHitShlNo;
    renmaSubWaitTime = pParam->renmaSubWaitTime;
    renmaSubInterval = pParam->renmaSubInterval;
    if (renmaSubList.mLength != 0) {
        u32 v0_0 = renmaSubList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (renmaSubList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete renmaSubList.mpArray[i0_3];
                v1_0 = renmaSubList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (renmaSubList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(renmaSubList.mpArray));
    }
    renmaSubList.mpArray = nullptr;
    renmaSubList.mBufsiz = 0;
    renmaSubList.mLength = 0;
    addShlList(static_cast<const cShlParamRenmadanCtrl*>(pParamBase));
}

__attribute__((weak)) void cShlParamRenmadanCtrl::addShlList(const cShlParamRenmadanCtrl* pParam) {
    DDON_STUB("cShlParamRenmadanCtrl::addShlList")
    /* stub */
}

inline cShlParamRenmadanCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamRenmadanCtrl::MyDTI cShlParamRenmadanCtrl::DTI("cShlParamRenmadanCtrl", &::cShlParamBase::DTI, 416ul, 0u, 0u);

MtObject* cShlParamRenmadanCtrl::MyDTI::newInstance() const {
    return new (16u) cShlParamRenmadanCtrl;
}

const MtDTI& cShlParamRenmadanCtrl::cRenmaSubCtrlParam::getDTI() const {
    return cShlParamRenmadanCtrl::cRenmaSubCtrlParam::DTI;
}

inline void* cShlParamRenmadanCtrl::cRenmaSubCtrlParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamRenmadanCtrl::cRenmaSubCtrlParam::DTI)->memAlloc(sz, align, cShlParamRenmadanCtrl::cRenmaSubCtrlParam::DTI.getID());
}

inline void cShlParamRenmadanCtrl::cRenmaSubCtrlParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamRenmadanCtrl::cRenmaSubCtrlParam::DTI)->memFree(p_addr);
}

void cShlParamRenmadanCtrl::cRenmaSubCtrlParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "waitFrame", &waitFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNo", &shlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "offset", &offset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "degX", &degX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "degY", &degY, 0u, 0u);
}

void cShlParamRenmadanCtrl::cRenmaSubCtrlParam::createPropertyTool(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\347\231\272\345\260\204\345\276\205\343\201\241\346\231\202\351\226\223", &waitFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "No", &shlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\231\272\345\260\204\343\202\252\343\203\225\343\202\273\343\203\203\343\203\210", &offset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\231\272\345\260\204\350\247\222\345\272\246X", &degX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\231\272\345\260\204\350\247\222\345\272\246Y", &degY, 0u, 0u);
}

inline cShlParamRenmadanCtrl::cRenmaSubCtrlParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamRenmadanCtrl::cRenmaSubCtrlParam::MyDTI cShlParamRenmadanCtrl::cRenmaSubCtrlParam::DTI("cShlParamRenmadanCtrl::cRenmaSubCtrlParam", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cShlParamRenmadanCtrl::cRenmaSubCtrlParam::MyDTI::newInstance() const {
    return new (16u) cShlParamRenmadanCtrl::cRenmaSubCtrlParam;
}

const MtDTI& cShlParamRenmadanMain::getDTI() const {
    return cShlParamRenmadanMain::DTI;
}

inline void cShlParamRenmadanMain::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamRenmadanMain::DTI)->memFree(p_addr);
}

MtDTI& cShlParamRenmadanMain::getShlDTI() const {
    return uShlRenmadanMain::DTI;
}

cShlParamRenmadanMain::~cShlParamRenmadanMain() {
}

inline cShlParamRenmadanMain::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamRenmadanMain::MyDTI cShlParamRenmadanMain::DTI("cShlParamRenmadanMain", &::cShlParamHoming::DTI, 592ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamRenmadanMain::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamRenmadanMain::DTI)->memAlloc(sizeof(cShlParamRenmadanMain), 16u, cShlParamRenmadanMain::DTI.getID())) cShlParamRenmadanMain;
}

const MtDTI& uShlRenmadanCtrl::getDTI() const {
    return uShlRenmadanCtrl::DTI;
}

inline void uShlRenmadanCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlRenmadanCtrl::DTI)->memFree(p_addr);
}

inline const cShlParamRenmadanCtrl* uShlRenmadanCtrl::getShlParam() const {
    return static_cast<const cShlParamRenmadanCtrl*>(mpShlParam2);
}

inline uShlRenmadanCtrl::uShlRenmadanCtrl() {
    mpRenmaTarget = nullptr;
    mpRenmaMain = nullptr;
    mSubWaitTimer = 0.0f;
    mSubDelayTimer = 0.0f;
    mShlSetNum = 0;
    mShlSetFrame = 0.0f;
    mpTargetEfcHandle = nullptr;
    mSubTargetUID = 0;
    mJointNo = -1;
    mOffset.x = MtVector3::Zero.x;
    mOffset.y = MtVector3::Zero.y;
    mOffset.z = MtVector3::Zero.z;
    mOffset.pad_ = 0.0f;
    mRenmaState = 0;
    mSubHomingFirstArray.mpArray = nullptr;
    mSubHomingFirstArray.mBufsiz = 0;
    mSubHomingFirstArray.mLength = 0;
    mSubHomingSecondArray.mpArray = nullptr;
    mSubHomingSecondArray.mLength = 0;
    mSubHomingSecondArray.mBufsiz = 0;
}

uShlRenmadanCtrl::~uShlRenmadanCtrl() {
}

__attribute__((weak)) void uShlRenmadanCtrl::setup() {
    DDON_STUB("uShlRenmadanCtrl::setup")
    /* stub */
}

void uShlRenmadanCtrl::kill() {
    this->uShlBase::kill();
    if (mpTargetEfcHandle == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpTargetEfcHandle, 4u);
    mpTargetEfcHandle = nullptr;
}

__attribute__((weak)) void uShlRenmadanCtrl::updateSub() {
    DDON_STUB("uShlRenmadanCtrl::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlRenmadanCtrl::updatePtr() {
    DDON_STUB("uShlRenmadanCtrl::updatePtr")
    /* stub */
}

void uShlRenmadanCtrl::updateEfcHandle() {
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

__attribute__((weak)) uShlBase* uShlRenmadanCtrl::setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY, u32 tagUid, s32 lockIndex) {
    DDON_STUB("uShlRenmadanCtrl::setShl")
    return nullptr;
}

inline uShlRenmadanCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlRenmadanCtrl::MyDTI uShlRenmadanCtrl::DTI("uShlRenmadanCtrl", &::uShlBase::DTI, 11072ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlRenmadanCtrl::MyDTI::newInstance() const {
    DDON_STUB("uShlRenmadanCtrl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uShlRenmadanMain::getDTI() const {
    return uShlRenmadanMain::DTI;
}

inline void* uShlRenmadanMain::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlRenmadanMain::DTI)->memAlloc(sz, align, uShlRenmadanMain::DTI.getID());
}

inline void uShlRenmadanMain::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlRenmadanMain::DTI)->memFree(p_addr);
}

uShlRenmadanMain::~uShlRenmadanMain() {
    DDON_STUB("uShlRenmadanMain::~uShlRenmadanMain")
    /* stub */
}

void uShlRenmadanMain::updatePtr() {
    this->uShlBase::updatePtr();
    if (mpRenmaCtrl == nullptr) {
        return;
    }
    if (mpRenmaCtrl->isEnable()) {
        return;
    }
    mpRenmaCtrl = nullptr;
}

__attribute__((weak)) void uShlRenmadanMain::callbackAttack(cHitInfo* pHitInfo) {
    DDON_STUB("uShlRenmadanMain::callbackAttack")
    /* stub */
}

inline uShlRenmadanMain::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlRenmadanMain::MyDTI uShlRenmadanMain::DTI("uShlRenmadanMain", &::uShlHoming::DTI, 11248ul, 0u, 0u);

MtObject* uShlRenmadanMain::MyDTI::newInstance() const {
    return new (16u) uShlRenmadanMain;
}

template MtTypedArray<uShlHoming>::~MtTypedArray();

