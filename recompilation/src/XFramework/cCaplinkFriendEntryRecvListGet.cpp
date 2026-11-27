// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendEntryRecvListGet.h"
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

void nCaplink::FriendEntryRecvListGetAns::init() {
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

const MtDTI& nCaplink::FriendEntryRecvListGetReqCtx::getDTI() const {
    return nCaplink::FriendEntryRecvListGetReqCtx::DTI;
}

void* nCaplink::FriendEntryRecvListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendEntryRecvListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendEntryRecvListGetReqCtx::DTI.mID);
}

nCaplink::FriendEntryRecvListGetReqCtx::FriendEntryRecvListGetReqCtx(MT_CTSTR datetime, s32 offset, s32 count) {
    DDON_STUB("nCaplink::FriendEntryRecvListGetReqCtx::FriendEntryRecvListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntryRecvListGetReqCtx::update() {
    DDON_STUB("nCaplink::FriendEntryRecvListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntryRecvListGetReqCtx::request() {
    DDON_STUB("nCaplink::FriendEntryRecvListGetReqCtx::request")
    /* stub */
}

inline nCaplink::FriendEntryRecvListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendEntryRecvListGetReqCtx::MyDTI nCaplink::FriendEntryRecvListGetReqCtx::DTI("FriendEntryRecvListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::FriendEntryRecvListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::FriendEntryRecvListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "unique_id") != 0) {
            if (::strcmp(chars, "nickname") != 0) {
                if (::strcmp(chars, "icon") != 0) {
                    if (::strcmp(chars, "message") != 0) {
                        if (::strcmp(chars, "status") != 0) {
                            if (::strcmp(chars, "request_at") != 0) {
                                if (::strcmp(chars, "updated_at") != 0) {
                                    if (::strcmp(chars, "code") != 0) {
                                        int t0 = ::strcmp(chars, "detail_message");
                                        mbCode = false;
                                        mbTotal = false;
                                        mbUniqueId = false;
                                        mbNickname = false;
                                        mbIcon = false;
                                        mbMessage = false;
                                        mbStatus = false;
                                        mbRequestAt = false;
                                        mbUpdatedAt = false;
                                        if (t0 == 0) {
                                            mbDetailMessage = true;
                                        } else {
                                            mbDetailMessage = false;
                                        }
                                    } else {
                                        mbTotal = false;
                                        mbUniqueId = false;
                                        mbNickname = false;
                                        mbIcon = false;
                                        mbMessage = false;
                                        mbStatus = false;
                                        mbRequestAt = false;
                                        mbUpdatedAt = false;
                                        mbCode = true;
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbRequestAt = false;
                                    mbMessage = false;
                                    mbStatus = false;
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
                                mbStatus = false;
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
                            mbMessage = false;
                            mbTotal = false;
                            mbUniqueId = false;
                            mbNickname = false;
                            mbIcon = false;
                            mbStatus = true;
                            mbRequestAt = false;
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
                        mbDetailMessage = false;
                        mbStatus = false;
                        mbRequestAt = false;
                        mbUpdatedAt = false;
                        mbCode = false;
                    }
                } else {
                    mbTotal = false;
                    mbUniqueId = false;
                    mbNickname = false;
                    mbIcon = true;
                    mbCode = false;
                    mbDetailMessage = false;
                    mbMessage = false;
                    mbStatus = false;
                    mbRequestAt = false;
                    mbUpdatedAt = false;
                }
            } else {
                mbTotal = false;
                mbUniqueId = false;
                mbNickname = true;
                mbDetailMessage = false;
                mbUpdatedAt = false;
                mbCode = false;
                mbIcon = false;
                mbMessage = false;
                mbStatus = false;
                mbRequestAt = false;
            }
        } else {
            mbTotal = false;
            mbUniqueId = true;
            mbNickname = false;
            mbCode = false;
            mbDetailMessage = false;
            mbMessage = false;
            mbStatus = false;
            mbRequestAt = false;
            mbUpdatedAt = false;
        }
    } else {
        mbTotal = true;
        mbUniqueId = false;
        mbNickname = false;
        mbCode = false;
        mbDetailMessage = false;
        mbMessage = false;
        mbStatus = false;
        mbRequestAt = false;
        mbUpdatedAt = false;
    }
}

__attribute__((weak)) void nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbStatus) {
            mStatus = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbCode) {
                mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
            }
        }
    }
}

__attribute__((weak)) void nCaplink::FriendEntryRecvListGetReqCtx::JsonParser::number(f64 value) {
}

