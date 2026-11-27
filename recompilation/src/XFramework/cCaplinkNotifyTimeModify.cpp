// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkNotifyTimeModify.h"
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

void nCaplink::NotifyTimeModifyAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::NotifyTimeModifyReqCtx::getDTI() const {
    return nCaplink::NotifyTimeModifyReqCtx::DTI;
}

void* nCaplink::NotifyTimeModifyReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyTimeModifyReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::NotifyTimeModifyReqCtx::DTI.mID);
}

nCaplink::NotifyTimeModifyReqCtx::NotifyTimeModifyReqCtx(s8 morning, s8 afternoon, s8 midnight, s8 evening) : nCaplink::HttpRequestContext(77) {
    mMorning = morning;
    mAfternoon = afternoon;
    mMidnight = midnight;
    mEvening = evening;
}

__attribute__((weak)) void nCaplink::NotifyTimeModifyReqCtx::update() {
    DDON_STUB("nCaplink::NotifyTimeModifyReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyTimeModifyReqCtx::request() {
    DDON_STUB("nCaplink::NotifyTimeModifyReqCtx::request")
    /* stub */
}

inline nCaplink::NotifyTimeModifyReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::NotifyTimeModifyReqCtx::MyDTI nCaplink::NotifyTimeModifyReqCtx::DTI("NotifyTimeModifyReqCtx", &::nCaplink::HttpRequestContext::DTI, 112ul, 0u, 0u);

MtObject* nCaplink::NotifyTimeModifyReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::NotifyTimeModifyReqCtx;
}

void nCaplink::NotifyTimeModifyReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::NotifyTimeModifyReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::NotifyTimeModifyReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyTimeModifyReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::NotifyTimeModifyReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::NotifyTimeModifyReqCtx::JsonParser::number(f64 value) {
}

