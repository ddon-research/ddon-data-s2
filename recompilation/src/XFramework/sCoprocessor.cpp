// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "sCoprocessor.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtSynchronize.h"
#include "cSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) u32 sCoprocessor::coprocessorLoop(sCoprocessor::COPROCESSOR_THREAD* ph) {
    DDON_STUB("sCoprocessor::coprocessorLoop")
    return {};
}

sCoprocessor::QUEUE_WORK32* sCoprocessor::getCoprocessorJob(sCoprocessor::QUEUE_KIND kind) {
    if (kind == QUEUE_FRAME) {
        if (mCoprocessorFrameQueueReadPt != mCoprocessorFrameQueueWritePt) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                    abort();
                }
                u32 t0 = mCoprocessorFrameQueueReadPt;
                if (t0 < mCoprocessorFrameQueueWritePt) {
                    mCoprocessorFrameQueueReadPt = t0 + 1u;
                    if (mThreadSafe || (cSystem::mJobSafe)) {
                        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                            abort();
                        }
                    }
                    return &mCoprocessorFrameQueue[t0];
                } else {
                    if (mThreadSafe || (cSystem::mJobSafe)) {
                        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                            abort();
                        }
                    }
                    return nullptr;
                }
            } else {
                u32 t0 = mCoprocessorFrameQueueReadPt;
                if (t0 < mCoprocessorFrameQueueWritePt) {
                    mCoprocessorFrameQueueReadPt = t0 + 1u;
                    if (mThreadSafe || (cSystem::mJobSafe)) {
                        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                            abort();
                        }
                    }
                    return &mCoprocessorFrameQueue[t0];
                } else {
                    if (mThreadSafe || (cSystem::mJobSafe)) {
                        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                            abort();
                        }
                    }
                    return nullptr;
                }
            }
        } else {
            return nullptr;
        }
    } else {
        if (kind == QUEUE_DRAW) {
            if (mCoprocessorDrawQueueReadPt != mCoprocessorDrawQueueWritePt) {
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                        abort();
                    }
                    u32 t1 = mCoprocessorDrawQueueReadPt;
                    if (t1 < mCoprocessorDrawQueueWritePt) {
                        mCoprocessorDrawQueueReadPt = t1 + 1u;
                        if (mThreadSafe || (cSystem::mJobSafe)) {
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                        }
                        return &mCoprocessorDrawQueue[t1];
                    } else {
                        if (mThreadSafe || (cSystem::mJobSafe)) {
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                        }
                        return nullptr;
                    }
                } else {
                    u32 t1 = mCoprocessorDrawQueueReadPt;
                    if (t1 < mCoprocessorDrawQueueWritePt) {
                        mCoprocessorDrawQueueReadPt = t1 + 1u;
                        if (mThreadSafe || (cSystem::mJobSafe)) {
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                        }
                        return &mCoprocessorDrawQueue[t1];
                    } else {
                        if (mThreadSafe || (cSystem::mJobSafe)) {
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                        }
                        return nullptr;
                    }
                }
            } else {
                return nullptr;
            }
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return nullptr;
        }
    }
}

const MtDTI& sCoprocessor::getDTI() const {
    return sCoprocessor::DTI;
}

void* sCoprocessor::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sCoprocessor::DTI)->memAlloc(sz, align, sCoprocessor::DTI.mID);
}

sCoprocessor::sCoprocessor() {
    sCoprocessor::mpInstance = this;
}

sCoprocessor::~sCoprocessor() {
    DDON_STUB("sCoprocessor::~sCoprocessor")
    /* stub */
}

void sCoprocessor::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

MtUI* sCoprocessor::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) void sCoprocessor::begin() {
}

__attribute__((weak)) void sCoprocessor::move() {
}

__attribute__((weak)) void sCoprocessor::end() {
}

inline sCoprocessor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCoprocessor::MyDTI sCoprocessor::DTI("sCoprocessor", &::cSystem::DTI, 16728ul, 0u, 0u);

sCoprocessor* sCoprocessor::mpInstance;

MtObject* sCoprocessor::MyDTI::newInstance() const {
    return new (16u) sCoprocessor;
}

