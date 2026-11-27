// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendTagFree.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::FriendTagFreeAns::init() {
    this->::nCaplink::ContextListener::init();
    mTotal = 0;
    mLimmit = 0;
}

const MtDTI& nCaplink::FriendTagFreeReqCtx::getDTI() const {
    return nCaplink::FriendTagFreeReqCtx::DTI;
}

void* nCaplink::FriendTagFreeReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendTagFreeReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendTagFreeReqCtx::DTI.mID);
}

nCaplink::FriendTagFreeReqCtx::FriendTagFreeReqCtx(MT_CTSTR unique_id, MtArray free_tag_alive_list) {
    DDON_STUB("nCaplink::FriendTagFreeReqCtx::FriendTagFreeReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendTagFreeReqCtx::update() {
    DDON_STUB("nCaplink::FriendTagFreeReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendTagFreeReqCtx::request() {
    DDON_STUB("nCaplink::FriendTagFreeReqCtx::request")
    /* stub */
}

inline nCaplink::FriendTagFreeReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendTagFreeReqCtx::MyDTI nCaplink::FriendTagFreeReqCtx::DTI("FriendTagFreeReqCtx", &::nCaplink::HttpRequestContext::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::FriendTagFreeReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::FriendTagFreeReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::FriendTagFreeReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::FriendTagFreeReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendTagFreeReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendTagFreeReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendTagFreeReqCtx::JsonParser::number(s64 value) {
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

__attribute__((weak)) void nCaplink::FriendTagFreeReqCtx::JsonParser::number(f64 value) {
}

