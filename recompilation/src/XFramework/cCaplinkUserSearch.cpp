// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkUserSearch.h"
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

void nCaplink::UserSearchAns::init() {
    this->::nCaplink::ContextListener::init();
    mUserInfoTbl.mAutoDelete = true;
    if (mUserInfoTbl.mLength != 0) {
        u32 v0_0 = mUserInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mUserInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mUserInfoTbl.mpArray[i0_3];
                v1_0 = mUserInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mUserInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mUserInfoTbl.mpArray));
    }
    mUserInfoTbl.mpArray = nullptr;
    mUserInfoTbl.mBufsiz = 0;
    mUserInfoTbl.mLength = 0;
}

const MtDTI& nCaplink::UserSearchReqCtx::getDTI() const {
    return nCaplink::UserSearchReqCtx::DTI;
}

void* nCaplink::UserSearchReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::UserSearchReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::UserSearchReqCtx::DTI.mID);
}

nCaplink::UserSearchReqCtx::UserSearchReqCtx(s32 searchType, MT_CTSTR keyword, s32 offset, s32 count) {
    DDON_STUB("nCaplink::UserSearchReqCtx::UserSearchReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserSearchReqCtx::update() {
    DDON_STUB("nCaplink::UserSearchReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserSearchReqCtx::request() {
    DDON_STUB("nCaplink::UserSearchReqCtx::request")
    /* stub */
}

inline nCaplink::UserSearchReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::UserSearchReqCtx::MyDTI nCaplink::UserSearchReqCtx::DTI("UserSearchReqCtx", &::nCaplink::HttpRequestContext::DTI, 168ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::UserSearchReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::UserSearchReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::UserSearchReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::UserSearchReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::UserSearchReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::UserSearchReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::UserSearchReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::UserSearchReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "count") != 0) {
            if (::strcmp(chars, "unique_id") != 0) {
                if (::strcmp(chars, "nickname") != 0) {
                    if (::strcmp(chars, "icon") != 0) {
                        if (::strcmp(chars, "code") != 0) {
                            int t0 = ::strcmp(chars, "detail_message");
                            mbIconNormalUrl = false;
                            mbCode = false;
                            mbTotal = false;
                            mbCount = false;
                            mbUniqueId = false;
                            mbNickName = false;
                            if (t0 == 0) {
                                mbDetailMessage = true;
                            } else {
                                mbDetailMessage = false;
                            }
                        } else {
                            mbIconNormalUrl = false;
                            mbTotal = false;
                            mbCount = false;
                            mbUniqueId = false;
                            mbNickName = false;
                            mbCode = true;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbCount = false;
                        mbUniqueId = false;
                        mbNickName = false;
                        mbIconNormalUrl = true;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbCount = false;
                    mbUniqueId = false;
                    mbNickName = true;
                    mbIconNormalUrl = false;
                    mbCode = false;
                    mbDetailMessage = false;
                }
            } else {
                mbTotal = false;
                mbCount = false;
                mbUniqueId = true;
                mbNickName = false;
                mbIconNormalUrl = false;
                mbCode = false;
                mbDetailMessage = false;
            }
        } else {
            mbTotal = false;
            mbCount = true;
            mbDetailMessage = false;
            mbUniqueId = false;
            mbNickName = false;
            mbIconNormalUrl = false;
            mbCode = false;
        }
    } else {
        mbTotal = true;
        mbCode = false;
        mbDetailMessage = false;
        mbCount = false;
        mbUniqueId = false;
        mbNickName = false;
        mbIconNormalUrl = false;
    }
}

__attribute__((weak)) void nCaplink::UserSearchReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::UserSearchReqCtx::JsonParser::string")
    /* stub */
}

void nCaplink::UserSearchReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbCount) {
            mpParent->mCount = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbCode) {
                mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
            }
        }
    }
}

__attribute__((weak)) void nCaplink::UserSearchReqCtx::JsonParser::number(f64 value) {
}

