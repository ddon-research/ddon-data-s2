// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentInviteTotalGet.h"
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

void nCaplink::ContentInviteTotalGetAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ContentInviteTotalGetReqCtx::getDTI() const {
    return nCaplink::ContentInviteTotalGetReqCtx::DTI;
}

void* nCaplink::ContentInviteTotalGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContentInviteTotalGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ContentInviteTotalGetReqCtx::DTI.mID);
}

nCaplink::ContentInviteTotalGetReqCtx::ContentInviteTotalGetReqCtx(MT_CTSTR from_datetime) {
    DDON_STUB("nCaplink::ContentInviteTotalGetReqCtx::ContentInviteTotalGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteTotalGetReqCtx::update() {
    DDON_STUB("nCaplink::ContentInviteTotalGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteTotalGetReqCtx::request() {
    DDON_STUB("nCaplink::ContentInviteTotalGetReqCtx::request")
    /* stub */
}

inline nCaplink::ContentInviteTotalGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContentInviteTotalGetReqCtx::MyDTI nCaplink::ContentInviteTotalGetReqCtx::DTI("ContentInviteTotalGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 120ul, 0u, 0u);

MtObject* nCaplink::ContentInviteTotalGetReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ContentInviteTotalGetReqCtx;
}

void nCaplink::ContentInviteTotalGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "code") != 0) {
            int t0 = ::strcmp(chars, "detail_message");
            mbTotal = false;
            mbCode = false;
            if (t0 == 0) {
                mbDetailMessage = true;
            } else {
                mbDetailMessage = false;
            }
        } else {
            mbTotal = false;
            mbCode = true;
            mbDetailMessage = false;
        }
    } else {
        mbTotal = true;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::ContentInviteTotalGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentInviteTotalGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteTotalGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ContentInviteTotalGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbCode) {
            mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
        }
    }
}

__attribute__((weak)) void nCaplink::ContentInviteTotalGetReqCtx::JsonParser::number(f64 value) {
}

