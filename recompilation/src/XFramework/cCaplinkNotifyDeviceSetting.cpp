// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkNotifyDeviceSetting.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::NotifyDeviceSettingAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::NotifyDeviceSettingReqCtx::getDTI() const {
    return nCaplink::NotifyDeviceSettingReqCtx::DTI;
}

void* nCaplink::NotifyDeviceSettingReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyDeviceSettingReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::NotifyDeviceSettingReqCtx::DTI.mID);
}

nCaplink::NotifyDeviceSettingReqCtx::NotifyDeviceSettingReqCtx() : nCaplink::HttpRequestContext(74) {
}

__attribute__((weak)) void nCaplink::NotifyDeviceSettingReqCtx::update() {
    DDON_STUB("nCaplink::NotifyDeviceSettingReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyDeviceSettingReqCtx::request() {
    DDON_STUB("nCaplink::NotifyDeviceSettingReqCtx::request")
    /* stub */
}

inline nCaplink::NotifyDeviceSettingReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::NotifyDeviceSettingReqCtx::MyDTI nCaplink::NotifyDeviceSettingReqCtx::DTI("NotifyDeviceSettingReqCtx", &::nCaplink::HttpRequestContext::DTI, 112ul, 0u, 0u);

MtObject* nCaplink::NotifyDeviceSettingReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::NotifyDeviceSettingReqCtx;
}

void nCaplink::NotifyDeviceSettingReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "all") != 0) {
        if (::strcmp(chars, "profile") != 0) {
            if (::strcmp(chars, "friend") != 0) {
                if (::strcmp(chars, "timeline") != 0) {
                    if (::strcmp(chars, "chat") != 0) {
                        if (::strcmp(chars, "game") != 0) {
                            if (::strcmp(chars, "code") != 0) {
                                int t0 = ::strcmp(chars, "detail_message");
                                mbCode = false;
                                mbChat = false;
                                mbGame = false;
                                mbAll = false;
                                mbProfile = false;
                                mbFriend = false;
                                mbTimeline = false;
                                if (t0 == 0) {
                                    mbDetailMessage = true;
                                } else {
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbChat = false;
                                mbGame = false;
                                mbAll = false;
                                mbProfile = false;
                                mbFriend = false;
                                mbTimeline = false;
                                mbCode = true;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbChat = false;
                            mbAll = false;
                            mbProfile = false;
                            mbFriend = false;
                            mbTimeline = false;
                            mbGame = true;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbAll = false;
                        mbProfile = false;
                        mbFriend = false;
                        mbTimeline = false;
                        mbChat = true;
                        mbGame = false;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbAll = false;
                    mbProfile = false;
                    mbFriend = false;
                    mbTimeline = true;
                    mbChat = false;
                    mbGame = false;
                    mbCode = false;
                    mbDetailMessage = false;
                }
            } else {
                mbAll = false;
                mbProfile = false;
                mbFriend = true;
                mbDetailMessage = false;
                mbTimeline = false;
                mbChat = false;
                mbGame = false;
                mbCode = false;
            }
        } else {
            mbAll = false;
            mbProfile = true;
            mbCode = false;
            mbDetailMessage = false;
            mbFriend = false;
            mbTimeline = false;
            mbChat = false;
            mbGame = false;
        }
    } else {
        mbAll = true;
        mbDetailMessage = false;
        mbGame = false;
        mbCode = false;
        mbProfile = false;
        mbFriend = false;
        mbTimeline = false;
        mbChat = false;
    }
}

__attribute__((weak)) void nCaplink::NotifyDeviceSettingReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::NotifyDeviceSettingReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyDeviceSettingReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::NotifyDeviceSettingReqCtx::JsonParser::number(s64 value) {
    if (mbAll) {
        mpParent->mAll = static_cast<s8>(static_cast<unsigned char>(value));
    } else {
        if (mbProfile) {
            mpParent->mProfile = static_cast<s8>(static_cast<unsigned char>(value));
        } else {
            if (mbFriend) {
                mpParent->mFriend = static_cast<s8>(static_cast<unsigned char>(value));
            } else {
                if (mbTimeline) {
                    mpParent->mTimeline = static_cast<s8>(static_cast<unsigned char>(value));
                } else {
                    if (mbChat) {
                        mpParent->mChat = static_cast<s8>(static_cast<unsigned char>(value));
                    } else {
                        if (mbGame) {
                            mpParent->mGame = static_cast<s8>(static_cast<unsigned char>(value));
                        } else {
                            if (mbCode) {
                                mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                            }
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::NotifyDeviceSettingReqCtx::JsonParser::number(f64 value) {
}

