// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkTagListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::TagListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mTagInfoTbl.mAutoDelete = true;
    if (mTagInfoTbl.mLength != 0) {
        u32 v0_0 = mTagInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTagInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTagInfoTbl.mpArray[i0_3];
                v1_0 = mTagInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTagInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mTagInfoTbl.mpArray));
    }
    mTagInfoTbl.mpArray = nullptr;
    mTagInfoTbl.mBufsiz = 0;
    mTagInfoTbl.mLength = 0;
    mTotal = 0;
}

const MtDTI& nCaplink::TagListGetReqCtx::getDTI() const {
    return nCaplink::TagListGetReqCtx::DTI;
}

void* nCaplink::TagListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::TagListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::TagListGetReqCtx::DTI.mID);
}

nCaplink::TagListGetReqCtx::TagListGetReqCtx(MT_CTSTR from_datetime) {
    DDON_STUB("nCaplink::TagListGetReqCtx::TagListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::TagListGetReqCtx::update() {
    DDON_STUB("nCaplink::TagListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::TagListGetReqCtx::request() {
    DDON_STUB("nCaplink::TagListGetReqCtx::request")
    /* stub */
}

inline nCaplink::TagListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::TagListGetReqCtx::MyDTI nCaplink::TagListGetReqCtx::DTI("TagListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::TagListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::TagListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::TagListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::TagListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::TagListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::TagListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::TagListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::TagListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "tag_id") != 0) {
            if (::strcmp(chars, "tag_name") != 0) {
                if (::strcmp(chars, "code") != 0) {
                    int t0 = ::strcmp(chars, "detail_message");
                    mbTotal = false;
                    mbTagId = false;
                    mbTagName = false;
                    mbCode = false;
                    if (t0 == 0) {
                        mbDetailMessage = true;
                    } else {
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbTagId = false;
                    mbTagName = false;
                    mbCode = true;
                    mbDetailMessage = false;
                }
            } else {
                mbTotal = false;
                mbTagId = false;
                mbTagName = true;
                mbCode = false;
                mbDetailMessage = false;
            }
        } else {
            mbTotal = false;
            mbTagId = true;
            mbTagName = false;
            mbCode = false;
            mbDetailMessage = false;
        }
    } else {
        mbTotal = true;
        mbTagId = false;
        mbTagName = false;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::TagListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::TagListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::TagListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::TagListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbTagId) {
            mTagId = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbCode) {
                mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
            }
        }
    }
}

__attribute__((weak)) void nCaplink::TagListGetReqCtx::JsonParser::number(f64 value) {
}

