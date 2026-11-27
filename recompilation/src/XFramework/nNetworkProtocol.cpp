// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "nNetworkProtocol.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetDevice.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtRandom.h"
#include "../MT/MtStream.h"
#include "nNetworkCoder.h"
#include "nNetworkPacket.h"
#include "nNetworkQueue.h"
#include "nNetworkRoute.h"
#include "nNetworkSession.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void nNetwork::Protocol::createProperty(MtPropertyList& s) {
}

void nNetwork::Protocol::setup(nNetwork::Session* ps) {
    mpSession = ps;
}

__attribute__((weak)) void nNetwork::Protocol::move() {
}

__attribute__((weak)) void nNetwork::Protocol::create(s32 index) {
}

__attribute__((weak)) void nNetwork::Protocol::remove(s32 index) {
}

__attribute__((weak)) void nNetwork::Protocol::dbgGetSummary(s32 index, MtString& sum) {
}

inline nNetwork::Protocol::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::Protocol::MyDTI nNetwork::Protocol::DTI("nNetwork::Protocol", &::MtObject::DTI, 24ul, 0u, 1u);

MtObject* nNetwork::Protocol::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& nNetwork::ProtocolStandard::getDTI() const {
    return nNetwork::ProtocolStandard::DTI;
}

void* nNetwork::ProtocolStandard::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::ProtocolStandard::DTI)->memAlloc(sz, align, ::nNetwork::ProtocolStandard::DTI.mID);
}

__attribute__((noinline)) nNetwork::ProtocolStandard::~ProtocolStandard() {
    DDON_STUB("nNetwork::ProtocolStandard::~ProtocolStandard")
    /* stub */
}

void nNetwork::ProtocolStandard::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mRedundancy", &mRedundancy, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mQueue", static_cast<MtObject*>(&mQueue[0]), 32u, 16u);
}

MtUI* nNetwork::ProtocolStandard::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((weak)) void nNetwork::ProtocolStandard::move() {
    DDON_STUB("nNetwork::ProtocolStandard::move")
    /* stub */
}

void nNetwork::ProtocolStandard::create(s32 index) {
    nNetwork::Session* j0;
    nNetwork::Session* t0 = mpSession;
    if (t0 == nullptr) {
        return;
    }
    if (mQueue[index].mpPool == nullptr) {
        mQueue[index].::nNetwork::BlockBuffer::init(t0->mpPool, 128u, &mQueue[index].mBlockList[0]);
        j0 = mpSession;
    } else {
        j0 = t0;
    }
    mBuffer[index].mpBlock = static_cast<u8*>(j0->mpPool->allocate());
    mBuffer[index].mFatal = false;
}

void nNetwork::ProtocolStandard::remove(s32 index) {
    mQueue[index].::nNetwork::BlockQueue::clear();
    mQueue[index].mHeadSequence = 1;
    mQueue[index].mTailSequence = 1;
    mQueue[index].mSendSequence = 0;
    mQueue[index].mRecvSequence = 0;
    mQueue[index].mAckTime = 0;
    mQueue[index].mCutoff = 0;
    mQueue[index].mSmoothedSpace = 512;
    mQueue[index].mSmoothedUnrel = 256;
    mQueue[index].mCutoffTime = 0;
    mQueue[index].mTotal[14] = 0;
    mQueue[index].mTotal[15] = 0;
    mQueue[index].mTotal[12] = 0;
    mQueue[index].mTotal[13] = 0;
    mQueue[index].mTotal[10] = 0;
    mQueue[index].mTotal[11] = 0;
    mQueue[index].mTotal[8] = 0;
    mQueue[index].mTotal[9] = 0;
    mQueue[index].mTotal[6] = 0;
    mQueue[index].mTotal[7] = 0;
    mQueue[index].mTotal[4] = 0;
    mQueue[index].mTotal[5] = 0;
    mQueue[index].mTotal[2] = 0;
    mQueue[index].mTotal[3] = 0;
    mQueue[index].mTotal[0] = 0;
    mQueue[index].mTotal[1] = 0;
    if (mBuffer[index].mpExtra != nullptr) {
        ::MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(mBuffer[index].mpExtra));
        mBuffer[index].mpExtra = nullptr;
    }
    mBuffer[index].mLength = 0;
    mBuffer[index].mSequence = 0;
    mBuffer[index].mTag = 0;
    if (mBuffer[index].mpBlock == nullptr) {
        return;
    }
    mpSession->mpPool->free(static_cast<void*>(mBuffer[index].mpBlock));
    mBuffer[index].mpBlock = nullptr;
}

__attribute__((weak)) bool nNetwork::ProtocolStandard::put(const void* data_ptr, u32 data_size, s32 index, u32 param, u32 callback, s32 tag) {
    DDON_STUB("nNetwork::ProtocolStandard::put")
    return {};
}

__attribute__((weak)) bool nNetwork::ProtocolStandard::get(s32 index, nNetwork::PacketWriter& packet, u32 target, const nNetwork::Route* route) {
    DDON_STUB("nNetwork::ProtocolStandard::get")
    return {};
}

__attribute__((weak)) void nNetwork::ProtocolStandard::receive(s32 index, nNetwork::PacketReader& packet) {
    DDON_STUB("nNetwork::ProtocolStandard::receive")
    /* stub */
}

__attribute__((weak)) void nNetwork::ProtocolStandard::dbgGetSummary(s32 index, MtString& sum) {
}

inline nNetwork::ProtocolStandard::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::ProtocolStandard::MyDTI nNetwork::ProtocolStandard::DTI("nNetwork::ProtocolStandard", &::nNetwork::Protocol::DTI, 19488ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::ProtocolStandard::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::ProtocolStandard::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::ProtocolStandard::Queue::getDTI() const {
    return nNetwork::ProtocolStandard::Queue::DTI;
}

void nNetwork::ProtocolStandard::Queue::createProperty(MtPropertyList& s) {
    this->::nNetwork::BlockQueue::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mHeadSequence", &mHeadSequence, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTailSequence", &mTailSequence, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mSendSequence", &mSendSequence, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mRecvSequence", &mRecvSequence, 0u, 0u);
}

inline nNetwork::ProtocolStandard::Queue::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::ProtocolStandard::Queue::MyDTI nNetwork::ProtocolStandard::Queue::DTI("nNetwork::ProtocolStandard::Queue", &::nNetwork::BlockQueue::DTI, 1184ul, 0u, 0u);

MtObject* nNetwork::ProtocolStandard::Queue::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::ProtocolStandard::Queue;
}

void nNetwork::ProtocolStandard::Buffer::write(nNetwork::Decoder* pdec, u32 data_size, u16 seq) {
    if (mFatal) {
        return;
    }
    if (mpBlock == nullptr) {
        return;
    }
    if (mSequence != 0) {
        if (mSequence != seq) {
            if (mpExtra != nullptr) {
                ::MtMemory::mpAllocatorType[7]->memFree(static_cast<void*>(mpExtra));
                mpExtra = nullptr;
            }
            mLength = 0;
            mTag = 0;
            mSequence = seq;
            if (data_size > 1024u) {
                void* t0 = ::MtMemory::mpAllocatorType[7]->memAlloc(16384ul, 32u);
                if ((mpExtra = static_cast<u8*>(t0)) != nullptr) {
                    if (mLength != 0) {
                        ::memcpy(t0, static_cast<const void*>(mpBlock), mLength);
                        if (mpExtra != nullptr) {
                            if (data_size != pdec->mStream.read(static_cast<void*>(&mpExtra[mLength]), data_size)) {
                                pdec->mIsDrain = true;
                            }
                        } else {
                            if (data_size != pdec->mStream.read(static_cast<void*>(&mpBlock[mLength]), data_size)) {
                                pdec->mIsDrain = true;
                            }
                        }
                    } else {
                        if (data_size != pdec->mStream.read(static_cast<void*>(&mpExtra[mLength]), data_size)) {
                            pdec->mIsDrain = true;
                        }
                    }
                    mLength = data_size + mLength;
                } else {
                    mFatal = true;
                }
            } else {
                if (data_size != pdec->mStream.read(static_cast<void*>(mpBlock), data_size)) {
                    pdec->mIsDrain = true;
                }
                mLength = data_size + mLength;
            }
        } else {
            mSequence = seq;
            if (mpExtra != nullptr) {
                if (data_size != pdec->mStream.read(static_cast<void*>(&mpExtra[mLength]), data_size)) {
                    pdec->mIsDrain = true;
                }
                mLength = data_size + mLength;
            } else {
                if ((data_size + mLength) > 1024u) {
                    void* t0 = ::MtMemory::mpAllocatorType[7]->memAlloc(16384ul, 32u);
                    if ((mpExtra = static_cast<u8*>(t0)) != nullptr) {
                        if (mLength != 0) {
                            ::memcpy(t0, static_cast<const void*>(mpBlock), mLength);
                            if (mpExtra != nullptr) {
                                if (data_size != pdec->mStream.read(static_cast<void*>(&mpExtra[mLength]), data_size)) {
                                    pdec->mIsDrain = true;
                                }
                            } else {
                                if (data_size != pdec->mStream.read(static_cast<void*>(&mpBlock[mLength]), data_size)) {
                                    pdec->mIsDrain = true;
                                }
                            }
                        } else {
                            if (data_size != pdec->mStream.read(static_cast<void*>(&mpExtra[mLength]), data_size)) {
                                pdec->mIsDrain = true;
                            }
                        }
                        mLength = data_size + mLength;
                    } else {
                        mFatal = true;
                    }
                } else {
                    if (data_size != pdec->mStream.read(static_cast<void*>(&mpBlock[mLength]), data_size)) {
                        pdec->mIsDrain = true;
                    }
                    mLength = data_size + mLength;
                }
            }
        }
    } else {
        mSequence = seq;
        if (mpExtra != nullptr) {
            if (data_size != pdec->mStream.read(static_cast<void*>(&mpExtra[mLength]), data_size)) {
                pdec->mIsDrain = true;
            }
            mLength = data_size + mLength;
        } else {
            if ((data_size + mLength) > 1024u) {
                void* t0 = ::MtMemory::mpAllocatorType[7]->memAlloc(16384ul, 32u);
                if ((mpExtra = static_cast<u8*>(t0)) != nullptr) {
                    if (mLength != 0) {
                        ::memcpy(t0, static_cast<const void*>(mpBlock), mLength);
                        if (mpExtra != nullptr) {
                            if (data_size != pdec->mStream.read(static_cast<void*>(&mpExtra[mLength]), data_size)) {
                                pdec->mIsDrain = true;
                            }
                        } else {
                            if (data_size != pdec->mStream.read(static_cast<void*>(&mpBlock[mLength]), data_size)) {
                                pdec->mIsDrain = true;
                            }
                        }
                    } else {
                        if (data_size != pdec->mStream.read(static_cast<void*>(&mpExtra[mLength]), data_size)) {
                            pdec->mIsDrain = true;
                        }
                    }
                    mLength = data_size + mLength;
                } else {
                    mFatal = true;
                }
            } else {
                if (data_size != pdec->mStream.read(static_cast<void*>(&mpBlock[mLength]), data_size)) {
                    pdec->mIsDrain = true;
                }
                mLength = data_size + mLength;
            }
        }
    }
}

