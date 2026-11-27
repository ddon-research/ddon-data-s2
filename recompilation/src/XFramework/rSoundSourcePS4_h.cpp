// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "rSoundSourcePS4_h.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtFile.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtStream.h"
#include "../MT/MtSynchronize.h"
#include "cResource.h"
#include "rSoundSource.h"
#include "rSoundStreamSourcePackage.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rSoundSourceAT9::getDTI() const {
    return rSoundSourceAT9::DTI;
}

rSoundSourceAT9::~rSoundSourceAT9() {
}

MT_CTSTR rSoundSourceAT9::getExt() const {
    return "at9";
}

const MtDTI* rSoundSourceAT9::getDTINative() const {
    return &rSoundSourceAT9::DTI;
}

bool rSoundSourceAT9::checkNativeEncodeParameter(const u32 encodeParam) const {
    return mEncodeParam == encodeParam;
}

__attribute__((weak)) bool rSoundSourceAT9::load(MtStream& in) {
    DDON_STUB("rSoundSourceAT9::load")
    return {};
}

__attribute__((weak)) bool rSoundSourceAT9::initAT9(MtStream& in) {
    DDON_STUB("rSoundSourceAT9::initAT9")
    return {};
}

inline rSoundSourceAT9::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundSourceAT9::MyDTI rSoundSourceAT9::DTI("rSoundSourceAT9", &::rSoundSource::DTI, 320ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundSourceAT9::MyDTI::newInstance() const {
    DDON_STUB("rSoundSourceAT9::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rSoundSourceStreamAT9::getDTI() const {
    return rSoundSourceStreamAT9::DTI;
}

rSoundSourceStreamAT9::~rSoundSourceStreamAT9() {
}

const MtDTI* rSoundSourceStreamAT9::getDTINative() const {
    return &rSoundSourceStreamAT9::DTI;
}

bool rSoundSourceStreamAT9::prepareToBuffer() {
    if (mpStreamSourcePackage != nullptr) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mpBuffer == nullptr) {
            u32 t0 = mDescriptor.mStreamSize;
            void* pbuf = MtMemoryAllocator::getAllocator(rSoundSource::DTI)->memAlloc(t0, 16u, rSoundSource::DTI.mID);
            if (pbuf != nullptr) {
                if (mpStreamSourcePackage != nullptr) {
                    if (mpStreamSourcePackage->mOpenCtr != 0) {
                        mpStreamSourcePackage->mGlobalID = (mPackageFileOffset < mpStreamSourcePackage->mDescriptor.mStreamSize) ? mPackageFileOffset : (mpStreamSourcePackage->mDescriptor.mStreamSize - 1u);
                        u32 read_size = read(pbuf, mDescriptor.mStreamSize, static_cast<u32*>(nullptr));
                        if (mDescriptor.mStreamSize == read_size) {
                            if (mpFile != nullptr) {
                                delete mpFile;
                                mpFile = nullptr;
                                mpBuffer = pbuf;
                                mBufferLength = mDescriptor.mStreamSize;
                            } else {
                                mpFile = nullptr;
                                mpBuffer = pbuf;
                                mBufferLength = read_size;
                            }
                            mSelfAllocation = true;
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                            return true;
                        } else {
                            MtMemoryAllocator::getAllocator(rSoundSourceStreamAT9::DTI)->memFree(pbuf);
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                            return false;
                        }
                    } else {
                        u32 read_size = read(pbuf, mDescriptor.mStreamSize, static_cast<u32*>(nullptr));
                        if (mDescriptor.mStreamSize == read_size) {
                            if (mpFile != nullptr) {
                                delete mpFile;
                                mpFile = nullptr;
                                mpBuffer = pbuf;
                                mBufferLength = mDescriptor.mStreamSize;
                            } else {
                                mpFile = nullptr;
                                mpBuffer = pbuf;
                                mBufferLength = read_size;
                            }
                            mSelfAllocation = true;
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                            return true;
                        } else {
                            MtMemoryAllocator::getAllocator(rSoundSourceStreamAT9::DTI)->memFree(pbuf);
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                            return false;
                        }
                    }
                } else {
                    if (mOpenCtr != 0) {
                        mGlobalID = (mDescriptor.mStreamSize == 0) ? (mDescriptor.mStreamSize - 1u) : 0u;
                        u32 read_size = read(pbuf, mDescriptor.mStreamSize, static_cast<u32*>(nullptr));
                        if (mDescriptor.mStreamSize == read_size) {
                            if (mpFile != nullptr) {
                                delete mpFile;
                                mpFile = nullptr;
                                mpBuffer = pbuf;
                                mBufferLength = mDescriptor.mStreamSize;
                            } else {
                                mpFile = nullptr;
                                mpBuffer = pbuf;
                                mBufferLength = read_size;
                            }
                            mSelfAllocation = true;
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                            return true;
                        } else {
                            MtMemoryAllocator::getAllocator(rSoundSourceStreamAT9::DTI)->memFree(pbuf);
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                            return false;
                        }
                    } else {
                        u32 read_size = read(pbuf, mDescriptor.mStreamSize, static_cast<u32*>(nullptr));
                        if (mDescriptor.mStreamSize == read_size) {
                            if (mpFile != nullptr) {
                                delete mpFile;
                                mpFile = nullptr;
                                mpBuffer = pbuf;
                                mBufferLength = mDescriptor.mStreamSize;
                            } else {
                                mpFile = nullptr;
                                mpBuffer = pbuf;
                                mBufferLength = read_size;
                            }
                            mSelfAllocation = true;
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                            return true;
                        } else {
                            MtMemoryAllocator::getAllocator(rSoundSourceStreamAT9::DTI)->memFree(pbuf);
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                            }
                            return false;
                        }
                    }
                }
            } else {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
                return false;
            }
        } else {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
            return true;
        }
    } else {
        return this->rSoundSource::prepareToBuffer();
    }
}

bool rSoundSourceStreamAT9::open() {
    if (mpStreamSourcePackage != nullptr) {
        mOpenCtr = mOpenCtr + 1;
        return true;
    } else {
        return this->rSoundSource::open();
    }
}

bool rSoundSourceStreamAT9::close() {
    if (mpStreamSourcePackage != nullptr) {
        mOpenCtr = mOpenCtr - 1;
        return true;
    } else {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if ((mpBuffer == nullptr) && (mpFile == nullptr)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
            return false;
        }
        s32 t0 = mOpenCtr;
        mOpenCtr = t0 - 1;
        if (t0 > 0) {
            if (mOpenCtr == 0) {
                if (mpFile != nullptr) {
                    mpFile->close();
                }
            }
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
            return true;
        } else {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
            return false;
        }
    }
}

__attribute__((weak)) u32 rSoundSourceStreamAT9::seek(u32 pos, u32* pid) {
    DDON_STUB("rSoundSourceStreamAT9::seek")
    return {};
}

__attribute__((weak)) u32 rSoundSourceStreamAT9::read(void* pdest, u32 size, u32* pid) {
    if (mpStreamSourcePackage != nullptr) {
        return mpStreamSourcePackage->read(pdest, size, pid, mPackageFileOffset);
    } else {
        if (mOpenCtr != 0) {
            if (mpBuffer != nullptr) {
                u32 t0 = *((pid == nullptr) ? (&mGlobalID) : pid);
                u32 t1 = mBufferLength;
                memcpy(pdest, static_cast<char*>(mpBuffer) + t0, (t1 < (size + t0)) ? (t1 - t0) : size);
                u32 t2 = *((pid == nullptr) ? (&mGlobalID) : pid);
                *((pid == nullptr) ? (&mGlobalID) : pid) = t2 + ((t1 < (size + t0)) ? (t1 - t0) : size);
                mFilePosition = *((pid == nullptr) ? (&mGlobalID) : pid);
                return (t1 < (size + t0)) ? (t1 - t0) : size;
            } else {
                if (mpFile != nullptr) {
                    if (mpFile->isReadable()) {
                        if ((*((pid == nullptr) ? (&mGlobalID) : pid)) != mFilePosition) {
                            mpFile->seek(static_cast<s32>(*((pid == nullptr) ? (&mGlobalID) : pid)), MtStream::ORG_BEGIN);
                            u32 t3 = mpFile->read(pdest, size);
                            u32 t4 = *((pid == nullptr) ? (&mGlobalID) : pid);
                            *((pid == nullptr) ? (&mGlobalID) : pid) = t4 + t3;
                            mFilePosition = *((pid == nullptr) ? (&mGlobalID) : pid);
                            return t3;
                        } else {
                            u32 t3 = mpFile->read(pdest, size);
                            u32 t4 = *((pid == nullptr) ? (&mGlobalID) : pid);
                            *((pid == nullptr) ? (&mGlobalID) : pid) = t4 + t3;
                            mFilePosition = *((pid == nullptr) ? (&mGlobalID) : pid);
                            return t3;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    }
}

static auto ddon_emit_0x01375180 __attribute__((used)) = &rSoundSourceStreamAT9::getSourcePackage;

static auto ddon_emit_0x01375190 __attribute__((used)) = &rSoundSourceStreamAT9::getPackageFileOffset;

inline rSoundSourceStreamAT9::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundSourceStreamAT9::MyDTI rSoundSourceStreamAT9::DTI("rSoundSourceStreamAT9", &::rSoundSourceAT9::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundSourceStreamAT9::MyDTI::newInstance() const {
    DDON_STUB("rSoundSourceStreamAT9::MyDTI::newInstance")
    return nullptr;
}

