// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentInviteListGet.h"
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

void nCaplink::ContentInviteListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mContentInviteUserInfoTbl.mAutoDelete = true;
    if (mContentInviteUserInfoTbl.mLength != 0) {
        u32 v0_0 = mContentInviteUserInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mContentInviteUserInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mContentInviteUserInfoTbl.mpArray[i0_3];
                v1_0 = mContentInviteUserInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContentInviteUserInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mContentInviteUserInfoTbl.mpArray));
    }
    mContentInviteUserInfoTbl.mpArray = nullptr;
    mContentInviteUserInfoTbl.mBufsiz = 0;
    mContentInviteUserInfoTbl.mLength = 0;
}

const MtDTI& nCaplink::ContentInviteListGetReqCtx::getDTI() const {
    return nCaplink::ContentInviteListGetReqCtx::DTI;
}

void* nCaplink::ContentInviteListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContentInviteListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ContentInviteListGetReqCtx::DTI.mID);
}

nCaplink::ContentInviteListGetReqCtx::ContentInviteListGetReqCtx(MT_CTSTR from_datetime, s32 offset, s32 count) {
    DDON_STUB("nCaplink::ContentInviteListGetReqCtx::ContentInviteListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteListGetReqCtx::update() {
    DDON_STUB("nCaplink::ContentInviteListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteListGetReqCtx::request() {
    DDON_STUB("nCaplink::ContentInviteListGetReqCtx::request")
    /* stub */
}

inline nCaplink::ContentInviteListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContentInviteListGetReqCtx::MyDTI nCaplink::ContentInviteListGetReqCtx::DTI("ContentInviteListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::ContentInviteListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::ContentInviteListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::ContentInviteListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::ContentInviteListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::ContentInviteListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::ContentInviteListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::ContentInviteListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::ContentInviteListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "unique_id") != 0) {
            if (::strcmp(chars, "nickname") != 0) {
                if (::strcmp(chars, "icon") != 0) {
                    if (::strcmp(chars, "content_id") != 0) {
                        if (::strcmp(chars, "message") != 0) {
                            if (::strcmp(chars, "alive") != 0) {
                                if (::strcmp(chars, "created_at") != 0) {
                                    if (::strcmp(chars, "code") != 0) {
                                        int t0 = ::strcmp(chars, "detail_message");
                                        mbCode = false;
                                        mbTotal = false;
                                        mbUniqueId = false;
                                        mbNickname = false;
                                        mbIcon = false;
                                        mbContentId = false;
                                        mbMessage = false;
                                        mbAlive = false;
                                        mbCreateAt = false;
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
                                        mbContentId = false;
                                        mbMessage = false;
                                        mbAlive = false;
                                        mbCreateAt = false;
                                        mbCode = true;
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbAlive = false;
                                    mbContentId = false;
                                    mbMessage = false;
                                    mbTotal = false;
                                    mbUniqueId = false;
                                    mbNickname = false;
                                    mbIcon = false;
                                    mbCreateAt = true;
                                    mbCode = false;
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbContentId = false;
                                mbMessage = false;
                                mbTotal = false;
                                mbUniqueId = false;
                                mbNickname = false;
                                mbIcon = false;
                                mbAlive = true;
                                mbCreateAt = false;
                                mbCode = false;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbContentId = false;
                            mbTotal = false;
                            mbUniqueId = false;
                            mbNickname = false;
                            mbIcon = false;
                            mbMessage = true;
                            mbAlive = false;
                            mbCreateAt = false;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbUniqueId = false;
                        mbNickname = false;
                        mbIcon = false;
                        mbContentId = true;
                        mbDetailMessage = false;
                        mbMessage = false;
                        mbAlive = false;
                        mbCreateAt = false;
                        mbCode = false;
                    }
                } else {
                    mbTotal = false;
                    mbUniqueId = false;
                    mbNickname = false;
                    mbIcon = true;
                    mbCode = false;
                    mbDetailMessage = false;
                    mbContentId = false;
                    mbMessage = false;
                    mbAlive = false;
                    mbCreateAt = false;
                }
            } else {
                mbTotal = false;
                mbUniqueId = false;
                mbNickname = true;
                mbDetailMessage = false;
                mbCreateAt = false;
                mbCode = false;
                mbIcon = false;
                mbContentId = false;
                mbMessage = false;
                mbAlive = false;
            }
        } else {
            mbTotal = false;
            mbUniqueId = true;
            mbNickname = false;
            mbIcon = false;
            mbContentId = false;
            mbMessage = false;
            mbAlive = false;
            mbCreateAt = false;
            mbCode = false;
            mbDetailMessage = false;
        }
    } else {
        mbTotal = true;
        mbDetailMessage = false;
        mbUniqueId = false;
        mbNickname = false;
        mbIcon = false;
        mbContentId = false;
        mbMessage = false;
        mbAlive = false;
        mbCreateAt = false;
        mbCode = false;
    }
}

__attribute__((weak)) void nCaplink::ContentInviteListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentInviteListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ContentInviteListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbCode) {
            mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
        }
    }
}

__attribute__((weak)) void nCaplink::ContentInviteListGetReqCtx::JsonParser::number(f64 value) {
}

