// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cMethodConstantManagerBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cMethodConstantTimeName::cMethodConstantBase::getDTI() const {
    return cMethodConstantTimeName::cMethodConstantBase::DTI;
}

cMethodConstantTimeName::cMethodConstantBase::cMethodConstantBase() {
    DDON_STUB("cMethodConstantTimeName::cMethodConstantBase::cMethodConstantBase")
    /* stub */
}

bool cMethodConstantTimeName::cMethodConstantBase::checkTimer() {
    if (0.0f >= (mTimerMax - mTimer)) {
        mTimer = mTimer - mTimerMax;
        return true;
    } else {
        return false;
    }
}

__attribute__((weak)) bool cMethodConstantTimeName::cMethodConstantBase::update(MtObject* pObject) {
    DDON_STUB("cMethodConstantTimeName::cMethodConstantBase::update")
    return {};
}

inline cMethodConstantTimeName::cMethodConstantBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMethodConstantTimeName::cMethodConstantBase::MyDTI cMethodConstantTimeName::cMethodConstantBase::DTI("cMethodConstantBase", &::MtObject::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* cMethodConstantTimeName::cMethodConstantBase::MyDTI::newInstance() const {
    DDON_STUB("cMethodConstantTimeName::cMethodConstantBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMethodConstantTimeName::cMethodConstantManagerBase::getDTI() const {
    return cMethodConstantTimeName::cMethodConstantManagerBase::DTI;
}

cMethodConstantTimeName::cMethodConstantManagerBase::cMethodConstantManagerBase() {
    DDON_STUB("cMethodConstantTimeName::cMethodConstantManagerBase::cMethodConstantManagerBase")
    /* stub */
}

void cMethodConstantTimeName::cMethodConstantManagerBase::after() {
    u32 v0_0 = mSyncCheck;
    for (u32 i = 0;;) {
        mMethodRepeat[i].mSyncCheck = v0_0 | mMethodRepeat[i].mSyncCheck;
        if (mMethodRepeat[i].mKeepSync != 0) {
            if (mMethodRepeat[i].mKeepSync == mMethodRepeat[i].mSyncCheck) {
                mMethodRepeat[i].mUse = false;
            }
        }
        mMethodRepeat[i].mSyncCheck = 0;
        if (i != 31) {
            i = i + 1u;
        } else {
            break;
        }
    }
}

__attribute__((weak)) void cMethodConstantTimeName::cMethodConstantManagerBase::update(MtObject* pObject) {
    DDON_STUB("cMethodConstantTimeName::cMethodConstantManagerBase::update")
    /* stub */
}

__attribute__((weak)) cMethodConstantTimeName::cMethodConstantBase* cMethodConstantTimeName::cMethodConstantManagerBase::setRepeatMethd(u32 index, cMethodConstantTimeName::cMethodConstantBase::REPEAT_CALLBACK_PARAM_STATUS repMethodRunParam, u32 repCount, f32 repTimer, bool fastmethdRun, u32 syncKeep) {
    DDON_STUB("cMethodConstantTimeName::cMethodConstantManagerBase::setRepeatMethd")
    return nullptr;
}

inline cMethodConstantTimeName::cMethodConstantManagerBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMethodConstantTimeName::cMethodConstantManagerBase::MyDTI cMethodConstantTimeName::cMethodConstantManagerBase::DTI("cMethodConstantManagerBase", &::MtObject::DTI, 5152ul, 0u, 0u);

__attribute__((weak)) MtObject* cMethodConstantTimeName::cMethodConstantManagerBase::MyDTI::newInstance() const {
    DDON_STUB("cMethodConstantTimeName::cMethodConstantManagerBase::MyDTI::newInstance")
    return nullptr;
}

