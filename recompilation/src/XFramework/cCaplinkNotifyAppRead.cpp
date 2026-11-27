// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkNotifyAppRead.h"
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

void nCaplink::NotifyAppReadAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::NotifyAppReadReqCtx::getDTI() const {
    return nCaplink::NotifyAppReadReqCtx::DTI;
}

void* nCaplink::NotifyAppReadReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyAppReadReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::NotifyAppReadReqCtx::DTI.mID);
}

nCaplink::NotifyAppReadReqCtx::NotifyAppReadReqCtx(s32 notify_id) : nCaplink::HttpRequestContext(73) {
    mNotifyId = notify_id;
}

__attribute__((weak)) void nCaplink::NotifyAppReadReqCtx::update() {
    DDON_STUB("nCaplink::NotifyAppReadReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyAppReadReqCtx::request() {
    DDON_STUB("nCaplink::NotifyAppReadReqCtx::request")
    /* stub */
}

inline nCaplink::NotifyAppReadReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::NotifyAppReadReqCtx::MyDTI nCaplink::NotifyAppReadReqCtx::DTI("NotifyAppReadReqCtx", &::nCaplink::HttpRequestContext::DTI, 112ul, 0u, 0u);

MtObject* nCaplink::NotifyAppReadReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::NotifyAppReadReqCtx;
}

void nCaplink::NotifyAppReadReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::NotifyAppReadReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::NotifyAppReadReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyAppReadReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::NotifyAppReadReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::NotifyAppReadReqCtx::JsonParser::number(f64 value) {
}

