// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlDamageSync.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpLockOn.h"
#include "cpObjCollision.h"
#include "cpShlShotCtrl.h"
#include "rObjCollision.h"
#include "sGeneralPoint.h"
#include "sShlManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamDamageSync::getDTI() const {
    return cShlParamDamageSync::DTI;
}

inline void cShlParamDamageSync::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamDamageSync::DTI)->memFree(p_addr);
}

MtDTI& cShlParamDamageSync::getShlDTI() const {
    return uShlDamageSync::DTI;
}

cShlParamDamageSync::~cShlParamDamageSync() {
}

void cShlParamDamageSync::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
}

void cShlParamDamageSync::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
}

inline cShlParamDamageSync::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamDamageSync::MyDTI cShlParamDamageSync::DTI("cShlParamDamageSync", &::cShlParamBase::DTI, 352ul, 0u, 0u);

MtObject* cShlParamDamageSync::MyDTI::newInstance() const {
    return new (16u) cShlParamDamageSync;
}

const MtDTI& cShlParamDamageSyncBreak::getDTI() const {
    return cShlParamDamageSyncBreak::DTI;
}

inline void cShlParamDamageSyncBreak::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamDamageSyncBreak::DTI)->memFree(p_addr);
}

MtDTI& cShlParamDamageSyncBreak::getShlDTI() const {
    return uShlDamageSyncBreak::DTI;
}

cShlParamDamageSyncBreak::~cShlParamDamageSyncBreak() {
}

void cShlParamDamageSyncBreak::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
}

void cShlParamDamageSyncBreak::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
}

inline cShlParamDamageSyncBreak::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamDamageSyncBreak::MyDTI cShlParamDamageSyncBreak::DTI("cShlParamDamageSyncBreak", &::cShlParamBase::DTI, 352ul, 0u, 0u);

MtObject* cShlParamDamageSyncBreak::MyDTI::newInstance() const {
    return new (16u) cShlParamDamageSyncBreak;
}

const MtDTI& cShlParamDamageSyncCtrl::getDTI() const {
    return cShlParamDamageSyncCtrl::DTI;
}

inline void cShlParamDamageSyncCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamDamageSyncCtrl::DTI)->memFree(p_addr);
}

MtDTI& cShlParamDamageSyncCtrl::getShlDTI() const {
    return uShlDamageSyncCtrl::DTI;
}

cShlParamDamageSyncCtrl::~cShlParamDamageSyncCtrl() {
}

void cShlParamDamageSyncCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mShlNum", &mShlNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShlNo", &mShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIntervalTime", &mIntervalTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSyncOption", &mSyncOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShlNoBreak", &mShlNoBreak, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFirstIntervalTime", &mFirstIntervalTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPushCollisionNo", &mPushCollisionNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPushGroup", &mPushGroup, 0u, 0u);
}

void cShlParamDamageSyncCtrl::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamDamageSyncCtrl* pParam = static_cast<const cShlParamDamageSyncCtrl*>(pParamBase);
    mShlNum = pParam->mShlNum;
    mShlNo = pParam->mShlNo;
    mIntervalTime = pParam->mIntervalTime;
    mSyncOption = pParam->mSyncOption;
    mShlNoBreak = pParam->mShlNoBreak;
    mFirstIntervalTime = pParam->mFirstIntervalTime;
    mPushCollisionNo = pParam->mPushCollisionNo;
    mPushGroup = pParam->mPushGroup;
}

inline cShlParamDamageSyncCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamDamageSyncCtrl::MyDTI cShlParamDamageSyncCtrl::DTI("cShlParamDamageSyncCtrl", &::cShlParamBase::DTI, 384ul, 0u, 0u);

MtObject* cShlParamDamageSyncCtrl::MyDTI::newInstance() const {
    return new (16u) cShlParamDamageSyncCtrl;
}

const MtDTI& uShlDamageSync::getDTI() const {
    return uShlDamageSync::DTI;
}

void uShlDamageSync::updateSub() {
    this->uShlBase::updateSub();
    if (!isMaster()) {
        return;
    }
    if (mpShlParent == nullptr) {
        requestKill();
    }
}

void uShlDamageSync::updatePtr() {
    this->uShlBase::updatePtr();
    if (mpShlParent == nullptr) {
        return;
    }
    if (mpShlParent->isEnable()) {
        return;
    }
    mpShlParent = nullptr;
}

__attribute__((weak)) void uShlDamageSync::eventCreatedBreakShl(uShlBase& shl) {
    DDON_STUB("uShlDamageSync::eventCreatedBreakShl")
    /* stub */
}

inline uShlDamageSync::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlDamageSync::MyDTI uShlDamageSync::DTI("uShlDamageSync", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlDamageSync::MyDTI::newInstance() const {
    return new (16u) uShlDamageSync;
}

const MtDTI& uShlDamageSyncBreak::getDTI() const {
    return uShlDamageSyncBreak::DTI;
}

void uShlDamageSyncBreak::updateSub() {
    this->uShlBase::updateSub();
}

void uShlDamageSyncBreak::updatePtr() {
    this->uShlBase::updatePtr();
    if (mpShlParent == nullptr) {
        return;
    }
    if (mpShlParent->isEnable()) {
        return;
    }
    mpShlParent = nullptr;
}

void uShlDamageSyncBreak::callbackAttack(cHitInfo* pHitInfo) {
    this->uShlBase::callbackAttack(pHitInfo);
    if (mpShlParent == nullptr) {
        return;
    }
    mpShlParent->mSyncAttack = true;
}

inline uShlDamageSyncBreak::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlDamageSyncBreak::MyDTI uShlDamageSyncBreak::DTI("uShlDamageSyncBreak", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlDamageSyncBreak::MyDTI::newInstance() const {
    return new (16u) uShlDamageSyncBreak;
}

const MtDTI& uShlDamageSyncCtrl::getDTI() const {
    return uShlDamageSyncCtrl::DTI;
}

__attribute__((weak)) void uShlDamageSyncCtrl::setup() {
    DDON_STUB("uShlDamageSyncCtrl::setup")
    /* stub */
}

__attribute__((weak)) void uShlDamageSyncCtrl::updateSub() {
    DDON_STUB("uShlDamageSyncCtrl::updateSub")
    /* stub */
}

void uShlDamageSyncCtrl::updatePtr() {
    this->uShlBase::updatePtr();
    if (mpShlChild != nullptr) {
        if (!mpShlChild->isEnable()) {
            mpShlChild = nullptr;
        }
    }
    if (mpShlChildBreak == nullptr) {
        return;
    }
    if (mpShlChildBreak->isEnable()) {
        return;
    }
    mpShlChildBreak = nullptr;
}

__attribute__((weak)) void uShlDamageSyncCtrl::createSyncShl() {
    DDON_STUB("uShlDamageSyncCtrl::createSyncShl")
    /* stub */
}

inline uShlDamageSyncCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlDamageSyncCtrl::MyDTI uShlDamageSyncCtrl::DTI("uShlDamageSyncCtrl", &::uShlBase::DTI, 10960ul, 0u, 0u);

MtObject* uShlDamageSyncCtrl::MyDTI::newInstance() const {
    return new (16u) uShlDamageSyncCtrl;
}

