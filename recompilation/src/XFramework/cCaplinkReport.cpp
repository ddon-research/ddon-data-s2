// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkReport.h"
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

void nCaplink::ReportAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ReportReqCtx::getDTI() const {
    return nCaplink::ReportReqCtx::DTI;
}

void* nCaplink::ReportReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ReportReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ReportReqCtx::DTI.mID);
}

nCaplink::ReportReqCtx::ReportReqCtx(MT_CTSTR unique_id, s8 place, MT_CTSTR detail) {
    DDON_STUB("nCaplink::ReportReqCtx::ReportReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ReportReqCtx::update() {
    DDON_STUB("nCaplink::ReportReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ReportReqCtx::request() {
    DDON_STUB("nCaplink::ReportReqCtx::request")
    /* stub */
}

inline nCaplink::ReportReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ReportReqCtx::MyDTI nCaplink::ReportReqCtx::DTI("ReportReqCtx", &::nCaplink::HttpRequestContext::DTI, 128ul, 0u, 0u);

MtObject* nCaplink::ReportReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ReportReqCtx;
}

void nCaplink::ReportReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::ReportReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ReportReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ReportReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ReportReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ReportReqCtx::JsonParser::number(f64 value) {
}

