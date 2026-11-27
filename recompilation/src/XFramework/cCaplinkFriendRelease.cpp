// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendRelease.h"
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

void nCaplink::FriendReleaseAns::init() {
    this->::nCaplink::ContextListener::init();
    mTotal = 0;
    mLimmit = 0;
}

const MtDTI& nCaplink::FriendReleaseReqCtx::getDTI() const {
    return nCaplink::FriendReleaseReqCtx::DTI;
}

void* nCaplink::FriendReleaseReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendReleaseReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendReleaseReqCtx::DTI.mID);
}

nCaplink::FriendReleaseReqCtx::FriendReleaseReqCtx(MT_CTSTR unique_id) {
    DDON_STUB("nCaplink::FriendReleaseReqCtx::FriendReleaseReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendReleaseReqCtx::update() {
    DDON_STUB("nCaplink::FriendReleaseReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendReleaseReqCtx::request() {
    DDON_STUB("nCaplink::FriendReleaseReqCtx::request")
    /* stub */
}

inline nCaplink::FriendReleaseReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendReleaseReqCtx::MyDTI nCaplink::FriendReleaseReqCtx::DTI("FriendReleaseReqCtx", &::nCaplink::HttpRequestContext::DTI, 120ul, 0u, 0u);

MtObject* nCaplink::FriendReleaseReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::FriendReleaseReqCtx;
}

void nCaplink::FriendReleaseReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "limit") != 0) {
            if (::strcmp(chars, "code") != 0) {
                int t0 = ::strcmp(chars, "detail_message");
                mbTotal = false;
                mbLimmit = false;
                mbCode = false;
                if (t0 != 0) {
                    mbDetailMessage = false;
                } else {
                    mbDetailMessage = true;
                }
            } else {
                mbTotal = false;
                mbLimmit = false;
                mbCode = true;
                mbDetailMessage = false;
            }
        } else {
            mbTotal = false;
            mbLimmit = true;
            mbCode = false;
            mbDetailMessage = false;
        }
    } else {
        mbTotal = true;
        mbLimmit = false;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::FriendReleaseReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendReleaseReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendReleaseReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendReleaseReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbLimmit) {
            mpParent->mLimmit = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbCode) {
                mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
            }
        }
    }
}

__attribute__((weak)) void nCaplink::FriendReleaseReqCtx::JsonParser::number(f64 value) {
}

