// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlJob04CS14.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cEfcHandle.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "nDDOUtility.h"
#include "rEffectProvider.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlCustomSpline.h"
#include "uShlSpline.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamJob04CS14::getDTI() const {
    return cShlParamJob04CS14::DTI;
}

inline void* cShlParamJob04CS14::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamJob04CS14::DTI)->memAlloc(sz, align, cShlParamJob04CS14::DTI.getID());
}

inline void cShlParamJob04CS14::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamJob04CS14::DTI)->memFree(p_addr);
}

MtDTI& cShlParamJob04CS14::getShlDTI() const {
    return uShlJob04CS14::DTI;
}

void cShlParamJob04CS14::createProperty(MtPropertyList& proplist) {
    this->cShlParamCustomSpline::createProperty(proplist);
}

__attribute__((weak)) void cShlParamJob04CS14::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamJob04CS14::copy")
    /* stub */
}

inline cShlParamJob04CS14::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob04CS14::MyDTI cShlParamJob04CS14::DTI("cShlParamJob04CS14", &::cShlParamCustomSpline::DTI, 560ul, 0u, 0u);

MtObject* cShlParamJob04CS14::MyDTI::newInstance() const {
    return new (16u) cShlParamJob04CS14;
}

const MtDTI& uShlJob04CS14::getDTI() const {
    return uShlJob04CS14::DTI;
}

inline void* uShlJob04CS14::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlJob04CS14::DTI)->memAlloc(sz, align, uShlJob04CS14::DTI.getID());
}

inline void uShlJob04CS14::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlJob04CS14::DTI)->memFree(p_addr);
}

void uShlJob04CS14::setup() {
    this->uShlSpline::setup();
    if (mFirstEfcHnd == nullptr) {
        mFirstEfcHnd = reqBlastOptionEffect(mPos, 0);
    }
    if (mShotAfterEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mShotAfterEfcHnd, 1u);
        mShotAfterEfcHnd = nullptr;
    }
    mAlreadyShot = false;
    mIsNeedShotClear = false;
}

__attribute__((weak)) void uShlJob04CS14::updateSub() {
    DDON_STUB("uShlJob04CS14::updateSub")
    /* stub */
}

void uShlJob04CS14::kill() {
    this->uShlBase::kill();
    if (mFirstEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mFirstEfcHnd, 1u);
        mFirstEfcHnd = nullptr;
    }
    if (mShotAfterEfcHnd == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mShotAfterEfcHnd, 1u);
    mShotAfterEfcHnd = nullptr;
}

void uShlJob04CS14::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mFirstEfcHnd != nullptr) {
        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mFirstEfcHnd)) {
            mFirstEfcHnd->mpOwner = nullptr;
            mFirstEfcHnd = nullptr;
        }
    }
    if (mShotAfterEfcHnd == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mShotAfterEfcHnd)) {
        return;
    }
    mShotAfterEfcHnd->mpOwner = nullptr;
    mShotAfterEfcHnd = nullptr;
}

__attribute__((weak)) void uShlJob04CS14::movePos() {
    DDON_STUB("uShlJob04CS14::movePos")
    /* stub */
}

__attribute__((weak)) cEfcHandle* uShlJob04CS14::reqBlastOptionEffect(const MtVector3& pos, s32 no) {
    DDON_STUB("uShlJob04CS14::reqBlastOptionEffect")
    return nullptr;
}

inline uShlJob04CS14::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob04CS14::MyDTI uShlJob04CS14::DTI("uShlJob04CS14", &::uShlCustomSpline::DTI, 11488ul, 0u, 0u);

MtObject* uShlJob04CS14::MyDTI::newInstance() const {
    return new (16u) uShlJob04CS14;
}

