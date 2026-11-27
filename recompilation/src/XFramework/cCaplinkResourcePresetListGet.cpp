// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkResourcePresetListGet.h"
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

void nCaplink::ResourcePresetListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mResourceInfoTbl.mAutoDelete = true;
    if (mResourceInfoTbl.mLength != 0) {
        u32 v0_0 = mResourceInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mResourceInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mResourceInfoTbl.mpArray[i0_3];
                v1_0 = mResourceInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mResourceInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mResourceInfoTbl.mpArray));
    }
    mResourceInfoTbl.mpArray = nullptr;
    mResourceInfoTbl.mBufsiz = 0;
    mResourceInfoTbl.mLength = 0;
}

const MtDTI& nCaplink::ResourcePresetListGetReqCtx::getDTI() const {
    return nCaplink::ResourcePresetListGetReqCtx::DTI;
}

void* nCaplink::ResourcePresetListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ResourcePresetListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ResourcePresetListGetReqCtx::DTI.mID);
}

nCaplink::ResourcePresetListGetReqCtx::ResourcePresetListGetReqCtx(s8 resource_type, s32 offset, s32 count) {
    DDON_STUB("nCaplink::ResourcePresetListGetReqCtx::ResourcePresetListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ResourcePresetListGetReqCtx::update() {
    DDON_STUB("nCaplink::ResourcePresetListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ResourcePresetListGetReqCtx::request() {
    DDON_STUB("nCaplink::ResourcePresetListGetReqCtx::request")
    /* stub */
}

inline nCaplink::ResourcePresetListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ResourcePresetListGetReqCtx::MyDTI nCaplink::ResourcePresetListGetReqCtx::DTI("ResourcePresetListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::ResourcePresetListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::ResourcePresetListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::ResourcePresetListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::ResourcePresetListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::ResourcePresetListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::ResourcePresetListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::ResourcePresetListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::ResourcePresetListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "resource_id") != 0) {
            if (::strcmp(chars, "resource_category_id") != 0) {
                if (::strcmp(chars, "resource_type") != 0) {
                    if (::strcmp(chars, "resource_tag") != 0) {
                        if (::strcmp(chars, "resource_url") != 0) {
                            if (::strcmp(chars, "alive") != 0) {
                                if (::strcmp(chars, "code") != 0) {
                                    int t0 = ::strcmp(chars, "detail_message");
                                    mbTotal = false;
                                    mbResourceId = false;
                                    mbResourceCategoryId = false;
                                    mbResourceType = false;
                                    mbResourceTag = false;
                                    mbResourceUrl = false;
                                    mbAlive = false;
                                    mbCode = false;
                                    if (t0 == 0) {
                                        mbDetailMessage = true;
                                    } else {
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbAlive = false;
                                    mbResourceTag = false;
                                    mbResourceUrl = false;
                                    mbTotal = false;
                                    mbResourceId = false;
                                    mbResourceCategoryId = false;
                                    mbResourceType = false;
                                    mbCode = true;
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbResourceTag = false;
                                mbResourceUrl = false;
                                mbTotal = false;
                                mbResourceId = false;
                                mbResourceCategoryId = false;
                                mbResourceType = false;
                                mbAlive = true;
                                mbCode = false;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbResourceTag = false;
                            mbTotal = false;
                            mbResourceId = false;
                            mbResourceCategoryId = false;
                            mbResourceType = false;
                            mbResourceUrl = true;
                            mbAlive = false;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbResourceId = false;
                        mbResourceCategoryId = false;
                        mbResourceType = false;
                        mbResourceTag = true;
                        mbResourceUrl = false;
                        mbAlive = false;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbResourceId = false;
                    mbResourceCategoryId = false;
                    mbResourceType = true;
                    mbDetailMessage = false;
                    mbResourceTag = false;
                    mbResourceUrl = false;
                    mbAlive = false;
                    mbCode = false;
                }
            } else {
                mbTotal = false;
                mbResourceId = false;
                mbResourceCategoryId = true;
                mbCode = false;
                mbDetailMessage = false;
                mbResourceType = false;
                mbResourceTag = false;
                mbResourceUrl = false;
                mbAlive = false;
            }
        } else {
            mbTotal = false;
            mbResourceId = true;
            mbDetailMessage = false;
            mbAlive = false;
            mbCode = false;
            mbResourceCategoryId = false;
            mbResourceType = false;
            mbResourceTag = false;
            mbResourceUrl = false;
        }
    } else {
        mbTotal = true;
        mbResourceId = false;
        mbResourceCategoryId = false;
        mbResourceType = false;
        mbResourceTag = false;
        mbResourceUrl = false;
        mbAlive = false;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::ResourcePresetListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ResourcePresetListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ResourcePresetListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ResourcePresetListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbResourceId) {
            mResourceId = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbResourceCategoryId) {
                mResourceCategoryId = static_cast<s32>(static_cast<unsigned int>(value));
            } else {
                if (mbResourceType) {
                    mResourceType = static_cast<s8>(static_cast<unsigned char>(value));
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
    }
}

__attribute__((weak)) void nCaplink::ResourcePresetListGetReqCtx::JsonParser::number(f64 value) {
}

