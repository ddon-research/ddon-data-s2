// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "MtNetDevice.h"
#include "MtAllocator.h"
#include "MtDTI.h"
#include "MtMemoryAllocator.h"
#include "MtNetObject.h"
#include "MtSynchronize.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) s32 MtNetBase64Url::encode(const void* pIn, u32 cIn, void* pOut, u32 cOut) {
    DDON_STUB("MtNetBase64Url::encode")
    return {};
}

__attribute__((weak)) s32 MtNetBase64Url::decode(const void* pIn, u32 cIn, void* pOut, u32 cOut) {
    DDON_STUB("MtNetBase64Url::decode")
    return {};
}

u16 MtNetByteOrder::netToHost16(u16 net_u16) {
    return __builtin_bswap16(static_cast<unsigned short>(net_u16));
}

u16 MtNetByteOrder::hostToNet16(u16 host_u16) {
    return __builtin_bswap16(static_cast<unsigned short>(host_u16));
}

u32 MtNetByteOrder::netToHost32(u32 net_u32) {
    return ((((net_u32 & 255u) * 0x1000000u) | (((net_u32 >> 8) & 255u) * 0x10000u)) | (((net_u32 >> 16) & 255u) * 256u)) | ((net_u32 >> 24) & 255u);
}

u32 MtNetByteOrder::hostToNet32(u32 host_u32) {
    return ((((host_u32 & 255u) * 0x1000000u) | (((host_u32 >> 8) & 255u) * 0x10000u)) | (((host_u32 >> 16) & 255u) * 256u)) | ((host_u32 >> 24) & 255u);
}

u64 MtNetByteOrder::netToHost64(u64 net_u64) {
    return ((((((((net_u64 & 255ul) * 0x100000000000000ul) | (((net_u64 >> 8) & 255ul) * 0x1000000000000ul)) | (((net_u64 >> 16) & 255ul) * 0x10000000000ul)) | (((net_u64 >> 24) & 255ul) * 0x100000000ul)) | (((net_u64 >> 32) & 255ul) * 0x1000000ul)) | (((net_u64 >> 40) & 255ul) * 0x10000ul)) | (((net_u64 >> 48) & 255ul) * 256ul)) | ((net_u64 >> 56) & 255ul);
}

u64 MtNetByteOrder::hostToNet64(u64 host_u64) {
    return ((((((((host_u64 & 255ul) * 0x100000000000000ul) | (((host_u64 >> 8) & 255ul) * 0x1000000000000ul)) | (((host_u64 >> 16) & 255ul) * 0x10000000000ul)) | (((host_u64 >> 24) & 255ul) * 0x100000000ul)) | (((host_u64 >> 32) & 255ul) * 0x1000000ul)) | (((host_u64 >> 40) & 255ul) * 0x10000ul)) | (((host_u64 >> 48) & 255ul) * 256ul)) | ((host_u64 >> 56) & 255ul);
}

void MtNetLog::setLevel(s32 level) {
    mLevel = level;
}

s32 MtNetLog::getLevel() {
    return mLevel;
}

MtNetLog::~MtNetLog() {
}

const MtDTI& MtNetServiceError::getDTI() const {
    return MtNetServiceError::DTI;
}

void* MtNetServiceError::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtNetServiceError::DTI)->memAlloc(sz, align, MtNetServiceError::DTI.mID);
}

MtNetServiceError::MtNetServiceError() {
    DDON_STUB("MtNetServiceError::MtNetServiceError")
    /* stub */
}

MtNetServiceError::~MtNetServiceError() {
    MtNetServiceError::mpInstance = nullptr;
}

__attribute__((weak)) void MtNetServiceError::add(s32 level, MtNetError* err, const void* obj) {
    DDON_STUB("MtNetServiceError::add")
    /* stub */
}

bool MtNetServiceError::isExist() {
    return mInfo[0].mLevel != 0;
}

s32 MtNetServiceError::get(MtNetError* err, s32* index) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        s32 t1 = mInfo[0].mLevel;
        if (t1 != 0) {
            mInfo[0].mIsGot = true;
            if (err != nullptr) {
                *err = mInfo[0].mError;
                s32 t2 = mInfo[0].mLevel;
                if (index != nullptr) {
                    *index = mInfo[0].mIndex;
                }
                if (mIsThreadSafe) {
                    mLockCount = mLockCount - 1;
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return t2;
            } else {
                if (index != nullptr) {
                    *index = mInfo[0].mIndex;
                    if (mIsThreadSafe) {
                        mLockCount = mLockCount - 1;
                        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                            abort();
                        }
                    }
                } else {
                    if (mIsThreadSafe) {
                        mLockCount = t0;
                        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                            abort();
                        }
                    }
                }
                return t1;
            }
        } else {
            if (mIsThreadSafe) {
                mLockCount = t0;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return 0;
        }
    } else {
        s32 t1 = mInfo[0].mLevel;
        if (t1 != 0) {
            mInfo[0].mIsGot = true;
            if (err != nullptr) {
                *err = mInfo[0].mError;
                s32 t2 = mInfo[0].mLevel;
                if (index != nullptr) {
                    *index = mInfo[0].mIndex;
                }
                if (mIsThreadSafe) {
                    mLockCount = mLockCount - 1;
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return t2;
            } else {
                if (index != nullptr) {
                    *index = mInfo[0].mIndex;
                }
                if (mIsThreadSafe) {
                    mLockCount = mLockCount - 1;
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return t1;
            }
        } else {
            if (mIsThreadSafe) {
                mLockCount = mLockCount - 1;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return 0;
        }
    }
}

__attribute__((weak)) void MtNetServiceError::clear() {
    DDON_STUB("MtNetServiceError::clear")
    /* stub */
}

void MtNetServiceError::addTarget(const void* obj) {
    s32 idx = 0;
    Target* p1 = &mTarget[0];
    do {
        if (p1->mpObject == nullptr) {
            p1->mpObject = obj;
            mTarget[idx].mIndex = -1;
            return;
        }
        idx += 1;
        p1 += static_cast<int>(1);
    } while (idx <= 15);
}

void MtNetServiceError::removeTarget(const void* obj) {
    s32 idx = 0;
    Target* p1 = &mTarget[0];
    do {
        if (obj == p1->mpObject) {
            p1->mpObject = nullptr;
            mTarget[idx].mIndex = -1;
            return;
        }
        idx += 1;
        p1 += static_cast<int>(1);
    } while (idx <= 15);
}

inline MtNetServiceError::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNetServiceError::MyDTI MtNetServiceError::DTI("MtNetServiceError", &::MtNetObject::DTI, 360ul, 0u, 0u);

MtNetServiceError* MtNetServiceError::mpInstance;

__attribute__((weak)) MtObject* MtNetServiceError::MyDTI::newInstance() const {
    DDON_STUB("MtNetServiceError::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void MtNetTime::updateTime() {
    DDON_STUB("MtNetTime::updateTime")
    /* stub */
}

MtNetTime::Total MtNetTime::getTotalTime() const {
    return mTotalTime;
}

MtNetTime::~MtNetTime() {
    DDON_STUB("MtNetTime::~MtNetTime")
    /* stub */
}

