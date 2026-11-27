// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_kernel.h>
#include <_pthread.h>
#include <stdlib.h>
#include "MtThread.h"
#include "MtAllocator.h"
#include "MtDTI.h"
#include "MtMemoryAllocator.h"
#include "MtObject.h"
#include "MtSynchronize.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtThread::getDTI() const {
    return MtThread::DTI;
}

void* MtThread::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtThread::DTI)->memAlloc(sz, align, MtThread::DTI.mID);
}

__attribute__((weak)) void MtThread::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(MtThread::DTI)->memFree(p_addr);
}

MtThread::MtThread(u32 stack_size, void* pcontext, MT_CTSTR name) {
    DDON_STUB("MtThread::MtThread")
    /* stub */
}

MtThread::~MtThread() {
    DDON_STUB("MtThread::~MtThread")
    /* stub */
}

void MtThread::resume() {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        abort();
    }
    if (mStatus == SUSPENDED) {
        if (scePthreadMutexUnlock(&mSuspendSection.mCSection) != 0) {
            abort();
        }
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void MtThread::sleep(u32 time) {
    sceKernelUsleep(time * 1000u);
}

void MtThread::terminate() {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        abort();
    }
    if (mTerminate) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    } else {
        mTerminate = true;
        if (mStatus == SUSPENDED) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
            }
            if (mStatus == SUSPENDED) {
                if (scePthreadMutexUnlock(&mSuspendSection.mCSection) != 0) {
                    abort();
                }
            }
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
        scePthreadJoin(mThreadID, static_cast<void* *>(nullptr));
        mStatus = TERMINATED;
    }
}

void MtThread::setPriority(s32 prio) {
    scePthreadSetprio(mThreadID, prio);
}

void MtThread::setProcessor(u32 p) {
    scePthreadSetaffinity(mThreadID, p);
}

MtThread::STATUS MtThread::getStatus() const {
    return mStatus;
}

void MtThread::lock() {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        abort();
    }
}

void MtThread::unlock() {
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

__attribute__((weak)) void MtThread::execute(void*) {
}

bool MtThread::isRequestedTermination() const {
    return mTerminate;
}

__attribute__((weak)) void* MtThread::innerFunction(void* pthis) {
    DDON_STUB("MtThread::innerFunction")
    return nullptr;
}

inline MtThread::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtThread::MyDTI MtThread::DTI("MtThread", &::MtObject::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* MtThread::MyDTI::newInstance() const {
    DDON_STUB("MtThread::MyDTI::newInstance")
    return nullptr;
}

