// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "MtNetObject.h"
#include "MtAllocator.h"
#include "MtDTI.h"
#include "MtMemoryAllocator.h"
#include "MtObject.h"
#include "MtProperty.h"
#include "MtPropertyList.h"
#include "MtSynchronize.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtNetObject::getDTI() const {
    return MtNetObject::DTI;
}

__attribute__((weak)) void MtNetObject::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(MtNetObject::DTI)->memFree(p_addr);
}

void* MtNetObject::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtNetObject::DTI)->memAlloc(sz, align, MtNetObject::DTI.mID);
}

MtNetObject::MtNetObject() {
    DDON_STUB("MtNetObject::MtNetObject")
    /* stub */
}

MtNetObject::~MtNetObject() {
    DDON_STUB("MtNetObject::~MtNetObject")
    /* stub */
}

void MtNetObject::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsThreadSafe", &mIsThreadSafe, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLockCount", &mLockCount, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFatal.mNo", &mFatal.mNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFatal.mCause", &mFatal.mCause, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFatal.mNative", &mFatal.mNative, 0u, 0u);
}

bool MtNetObject::isFatal() const {
    return mFatal.mNo != 0;
}

void MtNetObject::getFatal(MtNetError* err) {
    if (err == nullptr) {
        return;
    }
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        mLockCount = mLockCount + 1;
    }
    *err = mFatal;
    if (!mIsThreadSafe) {
        return;
    }
    mLockCount = mLockCount - 1;
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

__attribute__((weak)) void MtNetObject::clearFatal() {
    DDON_STUB("MtNetObject::clearFatal")
    /* stub */
}

__attribute__((weak)) void MtNetObject::setFatal(const MtNetError* err) {
    DDON_STUB("MtNetObject::setFatal")
    /* stub */
}

void MtNetObject::setFatal(s32 no, s32 cause, s32 native) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        mLockCount = mLockCount + 1;
    }
    if (!isFatal()) {
        mFatal.mNo = no;
        mFatal.mCause = cause;
        mFatal.mNative = native;
    }
    if (!mIsThreadSafe) {
        return;
    }
    mLockCount = mLockCount - 1;
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

inline MtNetObject::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNetObject::MyDTI MtNetObject::DTI("MtNetObject", &::MtObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* MtNetObject::MyDTI::newInstance() const {
    DDON_STUB("MtNetObject::MyDTI::newInstance")
    return nullptr;
}

