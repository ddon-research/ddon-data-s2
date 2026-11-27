// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentInviteAvailableListGet.h"
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

void nCaplink::ContentInviteAvailableListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mContentInviteInfoTbl.mAutoDelete = true;
    if (mContentInviteInfoTbl.mLength != 0) {
        u32 v0_0 = mContentInviteInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mContentInviteInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mContentInviteInfoTbl.mpArray[i0_3];
                v1_0 = mContentInviteInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContentInviteInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mContentInviteInfoTbl.mpArray));
    }
    mContentInviteInfoTbl.mpArray = nullptr;
    mContentInviteInfoTbl.mBufsiz = 0;
    mContentInviteInfoTbl.mLength = 0;
}

const MtDTI& nCaplink::ContentInviteAvailableListGetReqCtx::getDTI() const {
    return nCaplink::ContentInviteAvailableListGetReqCtx::DTI;
}

void* nCaplink::ContentInviteAvailableListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContentInviteAvailableListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ContentInviteAvailableListGetReqCtx::DTI.mID);
}

nCaplink::ContentInviteAvailableListGetReqCtx::ContentInviteAvailableListGetReqCtx(s32 offset, s32 count) {
    DDON_STUB("nCaplink::ContentInviteAvailableListGetReqCtx::ContentInviteAvailableListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteAvailableListGetReqCtx::update() {
    DDON_STUB("nCaplink::ContentInviteAvailableListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteAvailableListGetReqCtx::request() {
    DDON_STUB("nCaplink::ContentInviteAvailableListGetReqCtx::request")
    /* stub */
}

inline nCaplink::ContentInviteAvailableListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContentInviteAvailableListGetReqCtx::MyDTI nCaplink::ContentInviteAvailableListGetReqCtx::DTI("ContentInviteAvailableListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::ContentInviteAvailableListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::ContentInviteAvailableListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "unique_id") != 0) {
            if (::strcmp(chars, "nickname") != 0) {
                if (::strcmp(chars, "icon") != 0) {
                    if (::strcmp(chars, "code") != 0) {
                        int t0 = ::strcmp(chars, "detail_message");
                        mbCode = false;
                        mbTotal = false;
                        mbUniqueId = false;
                        mbNickname = false;
                        mbIcon = false;
                        if (t0 != 0) {
                            mbDetailMessage = false;
                        } else {
                            mbDetailMessage = true;
                        }
                    } else {
                        mbTotal = false;
                        mbUniqueId = false;
                        mbNickname = false;
                        mbIcon = false;
                        mbCode = true;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbUniqueId = false;
                    mbNickname = false;
                    mbIcon = true;
                    mbCode = false;
                    mbDetailMessage = false;
                }
            } else {
                mbTotal = false;
                mbUniqueId = false;
                mbNickname = true;
                mbIcon = false;
                mbCode = false;
                mbDetailMessage = false;
            }
        } else {
            mbTotal = false;
            mbUniqueId = true;
            mbNickname = false;
            mbIcon = false;
            mbCode = false;
            mbDetailMessage = false;
        }
    } else {
        mbTotal = true;
        mbDetailMessage = false;
        mbUniqueId = false;
        mbNickname = false;
        mbIcon = false;
        mbCode = false;
    }
}

__attribute__((weak)) void nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbCode) {
            mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
        }
    }
}

__attribute__((weak)) void nCaplink::ContentInviteAvailableListGetReqCtx::JsonParser::number(f64 value) {
}

