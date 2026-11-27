// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkUserIgnoreListGet.h"
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

void nCaplink::UserIgnoreListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mIgnoreUserInfoTbl.mAutoDelete = true;
    if (mIgnoreUserInfoTbl.mLength != 0) {
        u32 v0_0 = mIgnoreUserInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mIgnoreUserInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mIgnoreUserInfoTbl.mpArray[i0_3];
                v1_0 = mIgnoreUserInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mIgnoreUserInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mIgnoreUserInfoTbl.mpArray));
    }
    mIgnoreUserInfoTbl.mpArray = nullptr;
    mIgnoreUserInfoTbl.mBufsiz = 0;
    mIgnoreUserInfoTbl.mLength = 0;
    mTotal = 0;
}

const MtDTI& nCaplink::UserIgnoreListGetReqCtx::getDTI() const {
    return nCaplink::UserIgnoreListGetReqCtx::DTI;
}

void* nCaplink::UserIgnoreListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::UserIgnoreListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::UserIgnoreListGetReqCtx::DTI.mID);
}

nCaplink::UserIgnoreListGetReqCtx::UserIgnoreListGetReqCtx(s32 offset, s32 count) {
    DDON_STUB("nCaplink::UserIgnoreListGetReqCtx::UserIgnoreListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserIgnoreListGetReqCtx::update() {
    DDON_STUB("nCaplink::UserIgnoreListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserIgnoreListGetReqCtx::request() {
    DDON_STUB("nCaplink::UserIgnoreListGetReqCtx::request")
    /* stub */
}

inline nCaplink::UserIgnoreListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::UserIgnoreListGetReqCtx::MyDTI nCaplink::UserIgnoreListGetReqCtx::DTI("UserIgnoreListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::UserIgnoreListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::UserIgnoreListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::UserIgnoreListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::UserIgnoreListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::UserIgnoreListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::UserIgnoreListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::UserIgnoreListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::UserIgnoreListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "unique_id") != 0) {
            if (::strcmp(chars, "nickname") != 0) {
                if (::strcmp(chars, "icon") != 0) {
                    if (::strcmp(chars, "message") != 0) {
                        if (::strcmp(chars, "ignore_at") != 0) {
                            if (::strcmp(chars, "code") != 0) {
                                int t0 = ::strcmp(chars, "detail_message");
                                mbCode = false;
                                mbMessage = false;
                                mbIgnoreAt = false;
                                mbTotal = false;
                                mbUniqueId = false;
                                mbNickname = false;
                                mbIcon = false;
                                if (t0 == 0) {
                                    mbDetailMessage = true;
                                } else {
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbMessage = false;
                                mbIgnoreAt = false;
                                mbTotal = false;
                                mbUniqueId = false;
                                mbNickname = false;
                                mbIcon = false;
                                mbCode = true;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbMessage = false;
                            mbTotal = false;
                            mbUniqueId = false;
                            mbNickname = false;
                            mbIcon = false;
                            mbIgnoreAt = true;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbUniqueId = false;
                        mbNickname = false;
                        mbIcon = false;
                        mbMessage = true;
                        mbIgnoreAt = false;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbUniqueId = false;
                    mbNickname = false;
                    mbIcon = true;
                    mbMessage = false;
                    mbIgnoreAt = false;
                    mbCode = false;
                    mbDetailMessage = false;
                }
            } else {
                mbTotal = false;
                mbUniqueId = false;
                mbNickname = true;
                mbDetailMessage = false;
                mbIcon = false;
                mbMessage = false;
                mbIgnoreAt = false;
                mbCode = false;
            }
        } else {
            mbTotal = false;
            mbUniqueId = true;
            mbCode = false;
            mbDetailMessage = false;
            mbNickname = false;
            mbIcon = false;
            mbMessage = false;
            mbIgnoreAt = false;
        }
    } else {
        mbTotal = true;
        mbDetailMessage = false;
        mbIgnoreAt = false;
        mbCode = false;
        mbUniqueId = false;
        mbNickname = false;
        mbIcon = false;
        mbMessage = false;
    }
}

__attribute__((weak)) void nCaplink::UserIgnoreListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::UserIgnoreListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserIgnoreListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::UserIgnoreListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbCode) {
            mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
        }
    }
}

__attribute__((weak)) void nCaplink::UserIgnoreListGetReqCtx::JsonParser::number(f64 value) {
}

