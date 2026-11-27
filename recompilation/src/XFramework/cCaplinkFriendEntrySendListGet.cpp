// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendEntrySendListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::FriendEntrySendListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mFriendEntryInfoTbl.mAutoDelete = true;
    if (mFriendEntryInfoTbl.mLength != 0) {
        u32 v0_0 = mFriendEntryInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mFriendEntryInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mFriendEntryInfoTbl.mpArray[i0_3];
                v1_0 = mFriendEntryInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFriendEntryInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mFriendEntryInfoTbl.mpArray));
    }
    mFriendEntryInfoTbl.mpArray = nullptr;
    mFriendEntryInfoTbl.mBufsiz = 0;
    mFriendEntryInfoTbl.mLength = 0;
}

const MtDTI& nCaplink::FriendEntrySendListGetReqCtx::getDTI() const {
    return nCaplink::FriendEntrySendListGetReqCtx::DTI;
}

void* nCaplink::FriendEntrySendListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendEntrySendListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendEntrySendListGetReqCtx::DTI.mID);
}

nCaplink::FriendEntrySendListGetReqCtx::FriendEntrySendListGetReqCtx(s32 offset, s32 count) {
    DDON_STUB("nCaplink::FriendEntrySendListGetReqCtx::FriendEntrySendListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntrySendListGetReqCtx::update() {
    DDON_STUB("nCaplink::FriendEntrySendListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntrySendListGetReqCtx::request() {
    DDON_STUB("nCaplink::FriendEntrySendListGetReqCtx::request")
    /* stub */
}

inline nCaplink::FriendEntrySendListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendEntrySendListGetReqCtx::MyDTI nCaplink::FriendEntrySendListGetReqCtx::DTI("FriendEntrySendListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::FriendEntrySendListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::FriendEntrySendListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::FriendEntrySendListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::FriendEntrySendListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::FriendEntrySendListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::FriendEntrySendListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::FriendEntrySendListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::FriendEntrySendListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "unique_id") != 0) {
            if (::strcmp(chars, "nickname") != 0) {
                if (::strcmp(chars, "icon") != 0) {
                    if (::strcmp(chars, "message") != 0) {
                        if (::strcmp(chars, "request_at") != 0) {
                            if (::strcmp(chars, "updated_at") != 0) {
                                if (::strcmp(chars, "code") != 0) {
                                    int t0 = ::strcmp(chars, "detail_message");
                                    mbTotal = false;
                                    mbUniqueId = false;
                                    mbNickname = false;
                                    mbIcon = false;
                                    mbMessage = false;
                                    mbRequestAt = false;
                                    mbUpdatedAt = false;
                                    mbCode = false;
                                    if (t0 == 0) {
                                        mbDetailMessage = true;
                                    } else {
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbUpdatedAt = false;
                                    mbMessage = false;
                                    mbRequestAt = false;
                                    mbTotal = false;
                                    mbUniqueId = false;
                                    mbNickname = false;
                                    mbIcon = false;
                                    mbCode = true;
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbMessage = false;
                                mbRequestAt = false;
                                mbTotal = false;
                                mbUniqueId = false;
                                mbNickname = false;
                                mbIcon = false;
                                mbUpdatedAt = true;
                                mbCode = false;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbMessage = false;
                            mbTotal = false;
                            mbUniqueId = false;
                            mbNickname = false;
                            mbIcon = false;
                            mbRequestAt = true;
                            mbUpdatedAt = false;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbUniqueId = false;
                        mbNickname = false;
                        mbIcon = false;
                        mbMessage = true;
                        mbRequestAt = false;
                        mbUpdatedAt = false;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbUniqueId = false;
                    mbNickname = false;
                    mbMessage = false;
                    mbIcon = true;
                    mbRequestAt = false;
                    mbUpdatedAt = false;
                    mbCode = false;
                    mbDetailMessage = false;
                }
            } else {
                mbTotal = false;
                mbUniqueId = false;
                mbNickname = true;
                mbCode = false;
                mbDetailMessage = false;
                mbIcon = false;
                mbMessage = false;
                mbRequestAt = false;
                mbUpdatedAt = false;
            }
        } else {
            mbTotal = false;
            mbUniqueId = true;
            mbDetailMessage = false;
            mbUpdatedAt = false;
            mbCode = false;
            mbNickname = false;
            mbIcon = false;
            mbMessage = false;
            mbRequestAt = false;
        }
    } else {
        mbTotal = true;
        mbUniqueId = false;
        mbNickname = false;
        mbIcon = false;
        mbMessage = false;
        mbRequestAt = false;
        mbUpdatedAt = false;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::FriendEntrySendListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendEntrySendListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntrySendListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendEntrySendListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbCode) {
            mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
        }
    }
}

__attribute__((weak)) void nCaplink::FriendEntrySendListGetReqCtx::JsonParser::number(f64 value) {
}

