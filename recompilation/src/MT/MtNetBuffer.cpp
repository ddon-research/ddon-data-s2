// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "MtNetBuffer.h"
#include "MtCharSet.h"
#include "MtDTI.h"
#include "MtMemoryAllocator.h"
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "MtObject.h"
#include "MtProperty.h"
#include "MtPropertyList.h"
#include "MtSynchronize.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MtNetBuffer::MtNetBuffer() {
    mBufferSize = 0;
    mDataLength = 0;
    mpBuffer = nullptr;
}

MtNetBuffer::~MtNetBuffer() {
}

void MtNetBuffer::createProperty(MtPropertyList& s) {
    this->MtNetObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mBufferSize", &mBufferSize, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDataLength", &mDataLength, 1u, 0u);
}

void MtNetBuffer::create(u8* data_buf, u32 data_buf_size) {
    mpBuffer = data_buf;
    mBufferSize = data_buf_size;
    mDataLength = 0;
    memset(static_cast<void*>(data_buf), 0, data_buf_size);
}

void MtNetBuffer::clear() {
    if (mpBuffer == nullptr) {
        return;
    }
    memset(static_cast<void*>(mpBuffer), 0, mBufferSize);
}

void MtNetBuffer::cast(u8* data_buf, u32 data_len) {
    mpBuffer = data_buf;
    mBufferSize = data_len;
    mDataLength = data_len;
}

s32 MtNetBuffer::serialize(u8* data_buf, u32 data_buf_size) const {
    if (mpBuffer != nullptr) {
        if (data_buf != nullptr) {
            if (data_buf_size >= mDataLength) {
                if (mDataLength != 0) {
                    memcpy(static_cast<void*>(data_buf), static_cast<const void*>(mpBuffer), mDataLength);
                    return static_cast<s32>(mDataLength);
                } else {
                    return 0;
                }
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

s32 MtNetBuffer::deserialize(const u8* data_buf, u32 data_size) {
    if (mpBuffer != nullptr) {
        if (data_buf != nullptr) {
            if (mBufferSize >= data_size) {
                if (data_size != 0) {
                    mDataLength = data_size;
                    memcpy(static_cast<void*>(mpBuffer), static_cast<const void*>(data_buf), data_size);
                    return static_cast<s32>(mDataLength);
                } else {
                    return 0;
                }
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

s32 MtNetBuffer::duplicate(const MtNetBuffer* obj) {
    if (mpBuffer != nullptr) {
        if (obj != nullptr) {
            if (obj->mpBuffer != nullptr) {
                if (mBufferSize >= obj->mDataLength) {
                    if (obj->mDataLength != 0) {
                        memcpy(static_cast<void*>(mpBuffer), static_cast<const void*>(obj->mpBuffer), obj->mDataLength);
                        const u32 t0 = obj->mDataLength;
                        mDataLength = t0;
                        return static_cast<s32>(t0);
                    } else {
                        return 0;
                    }
                } else {
                    return -1;
                }
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

__attribute__((weak)) bool MtNetBuffer::equals(const MtNetBuffer* obj) const {
    DDON_STUB("MtNetBuffer::equals")
    return {};
}

__attribute__((weak)) void MtNetBuffer::encrypt(u8 key_byte, u32 offset, u32 data_len) {
    DDON_STUB("MtNetBuffer::encrypt")
    /* stub */
}

__attribute__((weak)) void MtNetBuffer::decrypt(u8 key_byte, u32 offset, u32 data_len) {
    DDON_STUB("MtNetBuffer::decrypt")
    /* stub */
}

__attribute__((weak)) u16 MtNetBuffer::getCRC16(u32 data_len) const {
    DDON_STUB("MtNetBuffer::getCRC16")
    return {};
}

__attribute__((weak)) void MtNetBuffer::dump(u32 offset, u32 size) {
}

MtNetFriendList::MtNetFriendList() {
    DDON_STUB("MtNetFriendList::MtNetFriendList")
    /* stub */
}

MtNetFriendList::~MtNetFriendList() {
    DDON_STUB("MtNetFriendList::~MtNetFriendList")
    /* stub */
}

void MtNetFriendList::createProperty(MtPropertyList& s) {
    this->MtNetObject::createProperty(s);
}

MtUI* MtNetFriendList::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void MtNetFriendList::clear() {
    DDON_STUB("MtNetFriendList::clear")
    /* stub */
}

MtNetFriendList& MtNetFriendList::operator=(const MtNetFriendList& src_list) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        mLockCount = mLockCount + 1;
    }
    mUserIndex = src_list.mUserIndex;
    mValidNum = src_list.mValidNum;
    for (s32 i = 0;;) {
        if (static_cast<unsigned char>(src_list.mUniqueId[i].mData[0] + 255) <= 20) {
            if (mUniqueId[i].mpBuffer != nullptr) {
                if (src_list.mUniqueId[i].mpBuffer != nullptr) {
                    if ((src_list.mUniqueId[i].mDataLength - 1u) >= mUniqueId[i].mBufferSize) {
                    } else {
                        memcpy(static_cast<void*>(mUniqueId[i].mpBuffer), static_cast<const void*>(src_list.mUniqueId[i].mpBuffer), src_list.mUniqueId[i].mDataLength);
                        mUniqueId[i].mDataLength = src_list.mUniqueId[i].mDataLength;
                    }
                }
            }
        } else {
            mUniqueId[i].clear();
        }
        if (i != 1999) {
            i = i + 1;
        } else {
            break;
        }
    }
    if (mIsThreadSafe) {
        mLockCount = mLockCount - 1;
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    return *this;
}

s32 MtNetFriendList::getUniqueIdList(MtNetUniqueId* uniq_id_list, s32 uniq_id_max_num) {
    unsigned int v1_8;
    if (uniq_id_list != nullptr) {
        if (uniq_id_max_num > 0) {
            if (mIsThreadSafe) {
                if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                    abort();
                }
                mLockCount = mLockCount + 1;
            }
            if (mValidNum <= 0) {
                v1_8 = 0;
            } else {
                s32 i = 1;
                MtNetUniqueId* p0_3 = &mUniqueId[0];
                for (MtNetUniqueId* p0_9 = uniq_id_list;;) {
                    if (static_cast<unsigned char>(p0_3->mData[0] + 255) <= 20) {
                        if (p0_9->mpBuffer != nullptr) {
                            if (p0_3->mpBuffer != nullptr) {
                                if ((p0_3->mDataLength - 1u) < p0_9->mBufferSize) {
                                    memcpy(static_cast<void*>(p0_9->mpBuffer), static_cast<const void*>(p0_3->mpBuffer), p0_3->mDataLength);
                                    p0_9->mDataLength = p0_3->mDataLength;
                                }
                            }
                        }
                    }
                    if (i >= uniq_id_max_num) {
                        v1_8 = i;
                        break;
                    } else {
                        if (i < mValidNum) {
                            i += 1;
                            p0_3 += 1;
                            p0_9 += 1;
                        } else {
                            v1_8 = i;
                            break;
                        }
                    }
                }
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    if (mIsThreadSafe) {
        mLockCount = mLockCount - 1;
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    return static_cast<s32>(v1_8);
}

void MtNetFriendList::add(MtNetUniqueId* uniq_id) {
    if (uniq_id == nullptr) {
        return;
    }
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        if (mValidNum <= 1999) {
            if (!inUniqueIdList(uniq_id)) {
                s32 t1 = mValidNum;
                if (static_cast<unsigned char>(uniq_id->mData[0] + 255) <= 20) {
                    if (mUniqueId[t1].mpBuffer != nullptr) {
                        if (uniq_id->mpBuffer != nullptr) {
                            if ((uniq_id->mDataLength - 1u) < mUniqueId[t1].mBufferSize) {
                                memcpy(static_cast<void*>(mUniqueId[t1].mpBuffer), static_cast<const void*>(uniq_id->mpBuffer), uniq_id->mDataLength);
                                mUniqueId[t1].mDataLength = uniq_id->mDataLength;
                                mValidNum = mValidNum + 1;
                            } else {
                                mValidNum = t1 + 1;
                            }
                        } else {
                            mValidNum = t1 + 1;
                        }
                    } else {
                        mValidNum = t1 + 1;
                    }
                } else {
                    mValidNum = t1 + 1;
                }
                if (mIsThreadSafe) {
                    mLockCount = mLockCount - 1;
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
            } else {
                if (mIsThreadSafe) {
                    mLockCount = mLockCount - 1;
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
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
    } else {
        if (mValidNum <= 1999) {
            if (!inUniqueIdList(uniq_id)) {
                s32 t1 = mValidNum;
                if (static_cast<unsigned char>(uniq_id->mData[0] + 255) <= 20) {
                    if (mUniqueId[t1].mpBuffer != nullptr) {
                        if (uniq_id->mpBuffer != nullptr) {
                            if ((uniq_id->mDataLength - 1u) < mUniqueId[t1].mBufferSize) {
                                memcpy(static_cast<void*>(mUniqueId[t1].mpBuffer), static_cast<const void*>(uniq_id->mpBuffer), uniq_id->mDataLength);
                                mUniqueId[t1].mDataLength = uniq_id->mDataLength;
                                mValidNum = mValidNum + 1;
                            } else {
                                mValidNum = t1 + 1;
                            }
                        } else {
                            mValidNum = t1 + 1;
                        }
                    } else {
                        mValidNum = t1 + 1;
                    }
                } else {
                    mValidNum = t1 + 1;
                }
                if (mIsThreadSafe) {
                    mLockCount = mLockCount - 1;
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
            } else {
                if (mIsThreadSafe) {
                    mLockCount = mLockCount - 1;
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
            }
        } else {
            if (mIsThreadSafe) {
                mLockCount = mLockCount - 1;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    }
}

__attribute__((weak)) bool MtNetFriendList::inUniqueIdList(MtNetUniqueId* uniq_id) {
    DDON_STUB("MtNetFriendList::inUniqueIdList")
    return {};
}

const MtDTI& MtNetUniqueId::getDTI() const {
    return MtNetUniqueId::DTI;
}

MtNetUniqueId::MtNetUniqueId() {
    DDON_STUB("MtNetUniqueId::MtNetUniqueId")
    /* stub */
}

MtNetUniqueId::~MtNetUniqueId() {
}

void MtNetUniqueId::createProperty(MtPropertyList& s) {
    this->MtNetObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mBufferSize", &mBufferSize, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDataLength", &mDataLength, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mData", &mData[0], 32u, 64u);
}

MtUI* MtNetUniqueId::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

bool MtNetUniqueId::isValid() const {
    return static_cast<unsigned char>(mData[0] + 255) <= 20;
}

__attribute__((weak)) void MtNetUniqueId::importFrom(u8 target, const void* data, u32 size) {
    DDON_STUB("MtNetUniqueId::importFrom")
    /* stub */
}

void MtNetUniqueId::exportTo(void* data, u32 size) const {
    if (data == nullptr) {
        return;
    }
    if (size <= 60u) {
        if (mData[0] == 5) {
            if (size == 16) {
                u64 t0 = MtNetByteOrder::netToHost64(static_cast<u64>(*reinterpret_cast<const unsigned long*>(reinterpret_cast<const char*>(this) + 60)));
                u32 t1 = MtNetByteOrder::netToHost32(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 68));
                *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(data) + 8) = (static_cast<unsigned long>(MtNetByteOrder::netToHost32(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 72))) * 0x100000000ul) | static_cast<unsigned long>(t1);
                *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(data) + 0) = static_cast<unsigned long>(t0);
            }
        } else {
            memcpy(data, static_cast<const void*>(&mData[4]), size);
        }
    }
}

__attribute__((weak)) void MtNetUniqueId::exportTo(MT_STR str, u32 size) const {
    DDON_STUB("MtNetUniqueId::exportTo")
    /* stub */
}

MtNetUniqueId& MtNetUniqueId::operator=(const MtNetUniqueId& uniq_id) {
    if (static_cast<unsigned char>(uniq_id.mData[0] + 255) <= 20) {
        if (mpBuffer != nullptr) {
            if (uniq_id.mpBuffer != nullptr) {
                if ((uniq_id.mDataLength - 1u) < mBufferSize) {
                    memcpy(static_cast<void*>(mpBuffer), static_cast<const void*>(uniq_id.mpBuffer), uniq_id.mDataLength);
                    mDataLength = uniq_id.mDataLength;
                }
            }
        }
    }
    return *this;
}

__attribute__((weak)) bool MtNetUniqueId::equals(const MtNetUniqueId* uniq_id) const {
    DDON_STUB("MtNetUniqueId::equals")
    return {};
}

__attribute__((weak)) bool MtNetUniqueId::operator==(const MtNetUniqueId& uniq_id) const {
    DDON_STUB("MtNetUniqueId::operator==")
    return {};
}

__attribute__((weak)) bool MtNetUniqueId::equals(const MtNetBuffer* obj) const {
    DDON_STUB("MtNetUniqueId::equals")
    return {};
}

inline MtNetUniqueId::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNetUniqueId::MyDTI MtNetUniqueId::DTI("MtNetUniqueId", &::MtNetObject::DTI, 120ul, 0u, 0u);

__attribute__((weak)) MtObject* MtNetUniqueId::MyDTI::newInstance() const {
    DDON_STUB("MtNetUniqueId::MyDTI::newInstance")
    return nullptr;
}

