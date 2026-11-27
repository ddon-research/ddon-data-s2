// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkNotifyTimeGet.h"
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

void nCaplink::NotifyTimeGetAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::NotifyTimeGetReqCtx::getDTI() const {
    return nCaplink::NotifyTimeGetReqCtx::DTI;
}

void* nCaplink::NotifyTimeGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyTimeGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::NotifyTimeGetReqCtx::DTI.mID);
}

nCaplink::NotifyTimeGetReqCtx::NotifyTimeGetReqCtx() : nCaplink::HttpRequestContext(76) {
}

__attribute__((weak)) void nCaplink::NotifyTimeGetReqCtx::update() {
    DDON_STUB("nCaplink::NotifyTimeGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyTimeGetReqCtx::request() {
    DDON_STUB("nCaplink::NotifyTimeGetReqCtx::request")
    /* stub */
}

inline nCaplink::NotifyTimeGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::NotifyTimeGetReqCtx::MyDTI nCaplink::NotifyTimeGetReqCtx::DTI("NotifyTimeGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 112ul, 0u, 0u);

MtObject* nCaplink::NotifyTimeGetReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::NotifyTimeGetReqCtx;
}

void nCaplink::NotifyTimeGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "morning") != 0) {
        if (::strcmp(chars, "afternoon") != 0) {
            if (::strcmp(chars, "midnight") != 0) {
                if (::strcmp(chars, "evening") != 0) {
                    if (::strcmp(chars, "code") != 0) {
                        int t0 = ::strcmp(chars, "detail_message");
                        mbCode = false;
                        mbMorning = false;
                        mbAfternoon = false;
                        mbMidnight = false;
                        mbEvening = false;
                        if (t0 != 0) {
                            mbDetailMessage = false;
                        } else {
                            mbDetailMessage = true;
                        }
                    } else {
                        mbMorning = false;
                        mbAfternoon = false;
                        mbMidnight = false;
                        mbEvening = false;
                        mbCode = true;
                        mbDetailMessage = false;
                    }
                } else {
                    mbMorning = false;
                    mbAfternoon = false;
                    mbMidnight = false;
                    mbEvening = true;
                    mbCode = false;
                    mbDetailMessage = false;
                }
            } else {
                mbMorning = false;
                mbAfternoon = false;
                mbMidnight = true;
                mbEvening = false;
                mbCode = false;
                mbDetailMessage = false;
            }
        } else {
            mbMorning = false;
            mbAfternoon = true;
            mbMidnight = false;
            mbEvening = false;
            mbCode = false;
            mbDetailMessage = false;
        }
    } else {
        mbMorning = true;
        mbDetailMessage = false;
        mbAfternoon = false;
        mbMidnight = false;
        mbEvening = false;
        mbCode = false;
    }
}

__attribute__((weak)) void nCaplink::NotifyTimeGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::NotifyTimeGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyTimeGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::NotifyTimeGetReqCtx::JsonParser::number(s64 value) {
    if (mbMorning) {
        mpParent->mMorning = static_cast<s8>(static_cast<unsigned char>(value));
    } else {
        if (mbAfternoon) {
            mpParent->mAfternoon = static_cast<s8>(static_cast<unsigned char>(value));
        } else {
            if (mbMidnight) {
                mpParent->mMidnight = static_cast<s8>(static_cast<unsigned char>(value));
            } else {
                if (mbEvening) {
                    mpParent->mEvening = static_cast<s8>(static_cast<unsigned char>(value));
                } else {
                    if (mbCode) {
                        mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::NotifyTimeGetReqCtx::JsonParser::number(f64 value) {
}

