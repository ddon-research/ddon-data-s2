// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentListGet.h"
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

void nCaplink::ContentListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mContentInfoTbl.mAutoDelete = true;
    if (mContentInfoTbl.mLength != 0) {
        u32 v0_0 = mContentInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mContentInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mContentInfoTbl.mpArray[i0_3];
                v1_0 = mContentInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContentInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mContentInfoTbl.mpArray));
    }
    mContentInfoTbl.mpArray = nullptr;
    mContentInfoTbl.mBufsiz = 0;
    mContentInfoTbl.mLength = 0;
    mTotal = 0;
}

const MtDTI& nCaplink::ContentListGetReqCtx::getDTI() const {
    return nCaplink::ContentListGetReqCtx::DTI;
}

void* nCaplink::ContentListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContentListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ContentListGetReqCtx::DTI.mID);
}

nCaplink::ContentListGetReqCtx::ContentListGetReqCtx(s32 offset, s32 count) {
    DDON_STUB("nCaplink::ContentListGetReqCtx::ContentListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentListGetReqCtx::update() {
    DDON_STUB("nCaplink::ContentListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentListGetReqCtx::request() {
    DDON_STUB("nCaplink::ContentListGetReqCtx::request")
    /* stub */
}

inline nCaplink::ContentListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContentListGetReqCtx::MyDTI nCaplink::ContentListGetReqCtx::DTI("ContentListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::ContentListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::ContentListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::ContentListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::ContentListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::ContentListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::ContentListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::ContentListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::ContentListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "content_id") != 0) {
            if (::strcmp(chars, "content_name") != 0) {
                if (::strcmp(chars, "tag_id") != 0) {
                    if (::strcmp(chars, "tag_name") != 0) {
                        if (::strcmp(chars, "comment") != 0) {
                            if (::strcmp(chars, "appdata") != 0) {
                                if (::strcmp(chars, "alive") != 0) {
                                    if (::strcmp(chars, "code") != 0) {
                                        int t0 = ::strcmp(chars, "detail_message");
                                        mbCode = false;
                                        mbTotal = false;
                                        mbContentId = false;
                                        mbContentName = false;
                                        mbTagId = false;
                                        mbTagName = false;
                                        mbComment = false;
                                        mbAppData = false;
                                        mbAlive = false;
                                        if (t0 == 0) {
                                            mbDetailMessage = true;
                                        } else {
                                            mbDetailMessage = false;
                                        }
                                    } else {
                                        mbTotal = false;
                                        mbContentId = false;
                                        mbContentName = false;
                                        mbTagId = false;
                                        mbTagName = false;
                                        mbComment = false;
                                        mbAppData = false;
                                        mbAlive = false;
                                        mbCode = true;
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbAppData = false;
                                    mbTagName = false;
                                    mbComment = false;
                                    mbTotal = false;
                                    mbContentId = false;
                                    mbContentName = false;
                                    mbTagId = false;
                                    mbAlive = true;
                                    mbCode = false;
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbTagName = false;
                                mbComment = false;
                                mbTotal = false;
                                mbContentId = false;
                                mbContentName = false;
                                mbTagId = false;
                                mbAppData = true;
                                mbAlive = false;
                                mbCode = false;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbTagName = false;
                            mbTotal = false;
                            mbContentId = false;
                            mbContentName = false;
                            mbTagId = false;
                            mbComment = true;
                            mbAppData = false;
                            mbAlive = false;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbContentId = false;
                        mbContentName = false;
                        mbTagId = false;
                        mbTagName = true;
                        mbDetailMessage = false;
                        mbComment = false;
                        mbAppData = false;
                        mbAlive = false;
                        mbCode = false;
                    }
                } else {
                    mbTotal = false;
                    mbContentId = false;
                    mbContentName = false;
                    mbTagId = true;
                    mbCode = false;
                    mbDetailMessage = false;
                    mbTagName = false;
                    mbComment = false;
                    mbAppData = false;
                    mbAlive = false;
                }
            } else {
                mbTotal = false;
                mbContentId = false;
                mbContentName = true;
                mbDetailMessage = false;
                mbAlive = false;
                mbCode = false;
                mbTagId = false;
                mbTagName = false;
                mbComment = false;
                mbAppData = false;
            }
        } else {
            mbTotal = false;
            mbContentId = true;
            mbContentName = false;
            mbTagId = false;
            mbTagName = false;
            mbComment = false;
            mbAppData = false;
            mbAlive = false;
            mbCode = false;
            mbDetailMessage = false;
        }
    } else {
        mbTotal = true;
        mbDetailMessage = false;
        mbContentId = false;
        mbContentName = false;
        mbTagId = false;
        mbTagName = false;
        mbComment = false;
        mbAppData = false;
        mbAlive = false;
        mbCode = false;
    }
}

__attribute__((weak)) void nCaplink::ContentListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ContentListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbTagId) {
            mTagId = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbAlive) {
                mAlive = static_cast<s8>(static_cast<unsigned char>(value));
            } else {
                if (mbCode) {
                    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::ContentListGetReqCtx::JsonParser::number(f64 value) {
}

