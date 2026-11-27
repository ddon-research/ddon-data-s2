// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatRead.h"
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

void nCaplink::ChatReadAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ChatReadReqCtx::getDTI() const {
    return nCaplink::ChatReadReqCtx::DTI;
}

void* nCaplink::ChatReadReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatReadReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatReadReqCtx::DTI.mID);
}

nCaplink::ChatReadReqCtx::ChatReadReqCtx(s32 chat_type, MT_CTSTR id, s32 chat_id) {
    DDON_STUB("nCaplink::ChatReadReqCtx::ChatReadReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatReadReqCtx::update() {
    DDON_STUB("nCaplink::ChatReadReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatReadReqCtx::request() {
    DDON_STUB("nCaplink::ChatReadReqCtx::request")
    /* stub */
}

inline nCaplink::ChatReadReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatReadReqCtx::MyDTI nCaplink::ChatReadReqCtx::DTI("ChatReadReqCtx", &::nCaplink::HttpRequestContext::DTI, 128ul, 0u, 0u);

MtObject* nCaplink::ChatReadReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ChatReadReqCtx;
}

void nCaplink::ChatReadReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::ChatReadReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatReadReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatReadReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatReadReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ChatReadReqCtx::JsonParser::number(f64 value) {
}

