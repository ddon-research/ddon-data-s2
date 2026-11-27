// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatSend.h"
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

__attribute__((weak)) void nCaplink::ChatSendAns::init() {
    DDON_STUB("nCaplink::ChatSendAns::init")
    /* stub */
}

const MtDTI& nCaplink::ChatSendReqCtx::getDTI() const {
    return nCaplink::ChatSendReqCtx::DTI;
}

void* nCaplink::ChatSendReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatSendReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatSendReqCtx::DTI.mID);
}

nCaplink::ChatSendReqCtx::ChatSendReqCtx(s32 chat_type, MT_CTSTR id, MT_CTSTR message, s32 stamp_id, MT_CTSTR image, MT_CTSTR position) {
    DDON_STUB("nCaplink::ChatSendReqCtx::ChatSendReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatSendReqCtx::update() {
    DDON_STUB("nCaplink::ChatSendReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatSendReqCtx::request() {
    DDON_STUB("nCaplink::ChatSendReqCtx::request")
    /* stub */
}

inline nCaplink::ChatSendReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatSendReqCtx::MyDTI nCaplink::ChatSendReqCtx::DTI("ChatSendReqCtx", &::nCaplink::HttpRequestContext::DTI, 168ul, 0u, 0u);

MtObject* nCaplink::ChatSendReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ChatSendReqCtx;
}

void nCaplink::ChatSendReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "chat_id") != 0) {
        if (::strcmp(chars, "message") != 0) {
            if (::strcmp(chars, "code") != 0) {
                int t0 = ::strcmp(chars, "detail_message");
                mbChatId = false;
                mbChatMessage = false;
                mbCode = false;
                if (t0 != 0) {
                    mbDetailMessage = false;
                } else {
                    mbDetailMessage = true;
                }
            } else {
                mbChatId = false;
                mbChatMessage = false;
                mbCode = true;
                mbDetailMessage = false;
            }
        } else {
            mbChatId = false;
            mbChatMessage = true;
            mbCode = false;
            mbDetailMessage = false;
        }
    } else {
        mbChatId = true;
        mbChatMessage = false;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::ChatSendReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatSendReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatSendReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatSendReqCtx::JsonParser::number(s64 value) {
    if (mbChatId) {
        mChatId = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbCode) {
            mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
        }
    }
}

__attribute__((weak)) void nCaplink::ChatSendReqCtx::JsonParser::number(f64 value) {
}

