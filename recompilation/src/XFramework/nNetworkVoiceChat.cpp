// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "nNetworkVoiceChat.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetDevice.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSynchronize.h"
#include "nNetworkCallback.h"
#include "nNetworkDatabase.h"
#include "nNetworkSession.h"
#include "sNetwork.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nNetwork::VoiceChat::VoiceChat() {
    DDON_STUB("nNetwork::VoiceChat::VoiceChat")
    /* stub */
}

__attribute__((noinline)) nNetwork::VoiceChat::~VoiceChat() {
    DDON_STUB("nNetwork::VoiceChat::~VoiceChat")
    /* stub */
}

const MtDTI& nNetwork::VoiceChat::getDTI() const {
    return nNetwork::VoiceChat::DTI;
}

void* nNetwork::VoiceChat::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::VoiceChat::DTI)->memAlloc(sz, align, ::nNetwork::VoiceChat::DTI.mID);
}

inline void nNetwork::VoiceChat::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::VoiceChat::DTI)->memFree(p_addr);
}

void nNetwork::VoiceChat::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mInit", &mInit, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mAutoAdd", &mAutoAdd, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTalker", static_cast<MtObject*>(&mTalker[0]), 32u, 1u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_U32, "SessionIndex", reinterpret_cast<MT_MFUNC>(&::nNetwork::VoiceChat::getSessionIndex), reinterpret_cast<MT_MFUNC>(&::nNetwork::VoiceChat::setSessionIndex), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mMicAttached", &mMicAttached, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mBitrate", &mBitrate, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_BOOL, "MicMute", reinterpret_cast<MT_MFUNC>(&::nNetwork::VoiceChat::isMicMute), reinterpret_cast<MT_MFUNC>(&::nNetwork::VoiceChat::setMicMute), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_F32, "SpeakerVolume", reinterpret_cast<MT_MFUNC>(&::nNetwork::VoiceChat::getSpeakerVolume), reinterpret_cast<MT_MFUNC>(&::nNetwork::VoiceChat::setSpeakerVolume), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* nNetwork::VoiceChat::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nNetwork::VoiceChat::init() {
    if (::scePthreadMutexLock(&mCS.mCSection) != 0) {
        ::abort();
    }
    if (!mInit) {
        nativeInit();
    }
    if (::scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
}

__attribute__((weak)) void nNetwork::VoiceChat::move() {
    DDON_STUB("nNetwork::VoiceChat::move")
    /* stub */
}

__attribute__((weak)) bool nNetwork::VoiceChat::addVoiceMember(s32 member_index) {
    DDON_STUB("nNetwork::VoiceChat::addVoiceMember")
    return {};
}

__attribute__((weak)) void nNetwork::VoiceChat::removeVoiceMember(s32 member_index) {
    DDON_STUB("nNetwork::VoiceChat::removeVoiceMember")
    /* stub */
}

void nNetwork::VoiceChat::setSessionIndex(u32 index) {
    if (index <= 3u) {
        u32 t0 = mSessionIndex;
        if (t0 != index) {
            bool t1 = mTalker[0].mInit;
            if (t1) {
                *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 40) = 0;
                unsigned char t2 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 48);
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 48) = t2 | 2;
                sNetwork* t3 = ::sNetwork::mpInstance;
                nNetwork::Session* t4 = t3->mpSession[0];
                if (t4 != nullptr) {
                    t4->mCallback.clear(4);
                    sNetwork* t6 = ::sNetwork::mpInstance;
                    nNetwork::Session* t7 = (::sNetwork::mpInstance)->mpSession[1];
                    if (t7 != nullptr) {
                        t7->mCallback.clear(4);
                        sNetwork* t9 = ::sNetwork::mpInstance;
                        nNetwork::Session* t10 = (::sNetwork::mpInstance)->mpSession[2];
                        if (t10 != nullptr) {
                            t10->mCallback.clear(4);
                            sNetwork* t12 = ::sNetwork::mpInstance;
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        } else {
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        }
                    } else {
                        nNetwork::Session* t10 = (::sNetwork::mpInstance)->mpSession[2];
                        if (t10 != nullptr) {
                            t10->mCallback.clear(4);
                            sNetwork* t12 = ::sNetwork::mpInstance;
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        } else {
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        }
                    }
                } else {
                    nNetwork::Session* t7 = (::sNetwork::mpInstance)->mpSession[1];
                    if (t7 != nullptr) {
                        t7->mCallback.clear(4);
                        sNetwork* t9 = ::sNetwork::mpInstance;
                        nNetwork::Session* t10 = (::sNetwork::mpInstance)->mpSession[2];
                        if (t10 != nullptr) {
                            t10->mCallback.clear(4);
                            sNetwork* t12 = ::sNetwork::mpInstance;
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        } else {
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        }
                    } else {
                        nNetwork::Session* t10 = (::sNetwork::mpInstance)->mpSession[2];
                        if (t10 != nullptr) {
                            t10->mCallback.clear(4);
                            sNetwork* t12 = ::sNetwork::mpInstance;
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        } else {
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        }
                    }
                }
            } else {
                sNetwork* t3 = ::sNetwork::mpInstance;
                nNetwork::Session* t4 = t3->mpSession[0];
                if (t4 != nullptr) {
                    t4->mCallback.clear(4);
                    sNetwork* t6 = ::sNetwork::mpInstance;
                    nNetwork::Session* t7 = (::sNetwork::mpInstance)->mpSession[1];
                    if (t7 != nullptr) {
                        t7->mCallback.clear(4);
                        sNetwork* t9 = ::sNetwork::mpInstance;
                        nNetwork::Session* t10 = (::sNetwork::mpInstance)->mpSession[2];
                        if (t10 != nullptr) {
                            t10->mCallback.clear(4);
                            sNetwork* t12 = ::sNetwork::mpInstance;
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        } else {
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        }
                    } else {
                        nNetwork::Session* t10 = (::sNetwork::mpInstance)->mpSession[2];
                        if (t10 != nullptr) {
                            t10->mCallback.clear(4);
                            sNetwork* t12 = ::sNetwork::mpInstance;
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        } else {
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        }
                    }
                } else {
                    nNetwork::Session* t7 = (::sNetwork::mpInstance)->mpSession[1];
                    if (t7 != nullptr) {
                        t7->mCallback.clear(4);
                        sNetwork* t9 = ::sNetwork::mpInstance;
                        nNetwork::Session* t10 = (::sNetwork::mpInstance)->mpSession[2];
                        if (t10 != nullptr) {
                            t10->mCallback.clear(4);
                            sNetwork* t12 = ::sNetwork::mpInstance;
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        } else {
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        }
                    } else {
                        nNetwork::Session* t10 = (::sNetwork::mpInstance)->mpSession[2];
                        if (t10 != nullptr) {
                            t10->mCallback.clear(4);
                            sNetwork* t12 = ::sNetwork::mpInstance;
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        } else {
                            nNetwork::Session* t13 = (::sNetwork::mpInstance)->mpSession[3];
                            if (t13 != nullptr) {
                                t13->mCallback.clear(4);
                            }
                            mSessionIndex = index;
                        }
                    }
                }
            }
        } else {
            mSessionIndex = index;
        }
    }
}

static auto ddon_emit_0x01bd8740 __attribute__((used)) = &nNetwork::VoiceChat::getSessionIndex;

__attribute__((weak)) void nNetwork::VoiceChat::setMicMute(bool f) {
    DDON_STUB("nNetwork::VoiceChat::setMicMute")
    /* stub */
}

static auto ddon_emit_0x01bd8750 __attribute__((used)) = &nNetwork::VoiceChat::isMicMute;

__attribute__((weak)) void nNetwork::VoiceChat::setSpeakerVolume(f32 vol) {
    DDON_STUB("nNetwork::VoiceChat::setSpeakerVolume")
    /* stub */
}

static auto ddon_emit_0x01bd8760 __attribute__((used)) = &nNetwork::VoiceChat::getSpeakerVolume;

__attribute__((weak)) void nNetwork::VoiceChat::nativeInit() {
    DDON_STUB("nNetwork::VoiceChat::nativeInit")
    /* stub */
}

__attribute__((weak)) void nNetwork::VoiceChat::nativeMoveTalker(u32 talker_index, bool update) {
    DDON_STUB("nNetwork::VoiceChat::nativeMoveTalker")
    /* stub */
}

__attribute__((weak)) void nNetwork::VoiceChat::moveTalker(u32 i, bool update) {
    DDON_STUB("nNetwork::VoiceChat::moveTalker")
    /* stub */
}

__attribute__((weak)) void nNetwork::VoiceChat::process(s32 src_index, const void* data_ptr, u32 data_size) {
    DDON_STUB("nNetwork::VoiceChat::process")
    /* stub */
}

__attribute__((weak)) void nNetwork::VoiceChat::putVoiceData(u8* pbuf, u32 len, s32 dst, bool rel) {
    DDON_STUB("nNetwork::VoiceChat::putVoiceData")
    /* stub */
}

inline nNetwork::VoiceChat::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::VoiceChat::MyDTI nNetwork::VoiceChat::DTI("nNetwork::VoiceChat", &::MtObject::DTI, 0x40160ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::VoiceChat::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::VoiceChat::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::VoiceChat::Talker::getDTI() const {
    return nNetwork::VoiceChat::Talker::DTI;
}

inline void* nNetwork::VoiceChat::Talker::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::VoiceChat::Talker::DTI)->memAlloc(sz, align, ::nNetwork::VoiceChat::Talker::DTI.mID);
}

inline void nNetwork::VoiceChat::Talker::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::VoiceChat::Talker::DTI)->memFree(p_addr);
}

void nNetwork::VoiceChat::Talker::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "Init", static_cast<MT_MFUNC>(&::nNetwork::VoiceChat::Talker::init), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Final", static_cast<MT_MFUNC>(&::nNetwork::VoiceChat::Talker::final), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Loopback", static_cast<MT_MFUNC>(&::nNetwork::VoiceChat::Talker::loopback), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTask", &mTask, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mInit", &mInit, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mLoopback", &mLoopback, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mDst", &mDst, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mUpdateTime", &mUpdateTime, 0u, 0u);
}

static auto ddon_emit_0x01bd8e90 __attribute__((used)) = &nNetwork::VoiceChat::Talker::init;

static auto ddon_emit_0x01bd8770 __attribute__((used)) = &nNetwork::VoiceChat::Talker::final;

static auto ddon_emit_0x01bd8ea0 __attribute__((used)) = &nNetwork::VoiceChat::Talker::loopback;

inline nNetwork::VoiceChat::Talker::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::VoiceChat::Talker::MyDTI nNetwork::VoiceChat::Talker::DTI("nNetwork::VoiceChat::Talker", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* nNetwork::VoiceChat::Talker::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::VoiceChat::Talker;
}

