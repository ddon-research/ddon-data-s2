// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatGroupRemove.h"
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

void nCaplink::ChatGroupRemoveAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ChatGroupRemoveReqCtx::getDTI() const {
    return nCaplink::ChatGroupRemoveReqCtx::DTI;
}

void* nCaplink::ChatGroupRemoveReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupRemoveReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatGroupRemoveReqCtx::DTI.mID);
}

nCaplink::ChatGroupRemoveReqCtx::ChatGroupRemoveReqCtx(s32 chat_type, MT_CTSTR group_id) {
    DDON_STUB("nCaplink::ChatGroupRemoveReqCtx::ChatGroupRemoveReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupRemoveReqCtx::update() {
    DDON_STUB("nCaplink::ChatGroupRemoveReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupRemoveReqCtx::request() {
    DDON_STUB("nCaplink::ChatGroupRemoveReqCtx::request")
    /* stub */
}

inline nCaplink::ChatGroupRemoveReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatGroupRemoveReqCtx::MyDTI nCaplink::ChatGroupRemoveReqCtx::DTI("ChatGroupRemoveReqCtx", &::nCaplink::HttpRequestContext::DTI, 120ul, 0u, 0u);

MtObject* nCaplink::ChatGroupRemoveReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ChatGroupRemoveReqCtx;
}

void nCaplink::ChatGroupRemoveReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "code") != 0) {
        int t0 = ::strcmp(chars, "detail_message");
        mbCode = false;
        if (t0 != 0) {
            mbDetailMessage = false;
        } else {
            mbDetailMessage = true;
        }
    } else {
        mbCode = true;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::ChatGroupRemoveReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupRemoveReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupRemoveReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatGroupRemoveReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ChatGroupRemoveReqCtx::JsonParser::number(f64 value) {
}

