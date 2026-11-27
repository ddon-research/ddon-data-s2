// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendTagFreeListGet.h"
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

void nCaplink::FriendTagFreeListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mFreeTagInfoTbl.mAutoDelete = true;
    if (mFreeTagInfoTbl.mLength != 0) {
        u32 v0_0 = mFreeTagInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mFreeTagInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mFreeTagInfoTbl.mpArray[i0_3];
                v1_0 = mFreeTagInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFreeTagInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mFreeTagInfoTbl.mpArray));
    }
    mFreeTagInfoTbl.mpArray = nullptr;
    mFreeTagInfoTbl.mBufsiz = 0;
    mFreeTagInfoTbl.mLength = 0;
    mTotal = 0;
}

const MtDTI& nCaplink::FriendTagFreeListGetReqCtx::getDTI() const {
    return nCaplink::FriendTagFreeListGetReqCtx::DTI;
}

void* nCaplink::FriendTagFreeListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendTagFreeListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendTagFreeListGetReqCtx::DTI.mID);
}

nCaplink::FriendTagFreeListGetReqCtx::FriendTagFreeListGetReqCtx(MT_CTSTR from_datetime, s32 offset, s32 count) {
    DDON_STUB("nCaplink::FriendTagFreeListGetReqCtx::FriendTagFreeListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendTagFreeListGetReqCtx::update() {
    DDON_STUB("nCaplink::FriendTagFreeListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendTagFreeListGetReqCtx::request() {
    DDON_STUB("nCaplink::FriendTagFreeListGetReqCtx::request")
    /* stub */
}

inline nCaplink::FriendTagFreeListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendTagFreeListGetReqCtx::MyDTI nCaplink::FriendTagFreeListGetReqCtx::DTI("FriendTagFreeListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::FriendTagFreeListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::FriendTagFreeListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::FriendTagFreeListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::FriendTagFreeListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::FriendTagFreeListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::FriendTagFreeListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::FriendTagFreeListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::FriendTagFreeListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "unique_id") != 0) {
            if (::strcmp(chars, "tag_id") != 0) {
                if (::strcmp(chars, "alive") != 0) {
                    if (::strcmp(chars, "updated_at") != 0) {
                        if (::strcmp(chars, "code") != 0) {
                            int t0 = ::strcmp(chars, "detail_message");
                            mbUpdateAt = false;
                            mbCode = false;
                            mbTotal = false;
                            mbUniqueId = false;
                            mbTagId = false;
                            mbAlive = false;
                            if (t0 == 0) {
                                mbDetailMessage = true;
                            } else {
                                mbDetailMessage = false;
                            }
                        } else {
                            mbUpdateAt = false;
                            mbTotal = false;
                            mbUniqueId = false;
                            mbTagId = false;
                            mbAlive = false;
                            mbCode = true;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbUniqueId = false;
                        mbTagId = false;
                        mbAlive = false;
                        mbUpdateAt = true;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbUniqueId = false;
                    mbTagId = false;
                    mbAlive = true;
                    mbUpdateAt = false;
                    mbCode = false;
                    mbDetailMessage = false;
                }
            } else {
                mbTotal = false;
                mbUniqueId = false;
                mbTagId = true;
                mbAlive = false;
                mbUpdateAt = false;
                mbCode = false;
                mbDetailMessage = false;
            }
        } else {
            mbTotal = false;
            mbUniqueId = true;
            mbDetailMessage = false;
            mbTagId = false;
            mbAlive = false;
            mbUpdateAt = false;
            mbCode = false;
        }
    } else {
        mbTotal = true;
        mbCode = false;
        mbDetailMessage = false;
        mbUniqueId = false;
        mbTagId = false;
        mbAlive = false;
        mbUpdateAt = false;
    }
}

__attribute__((weak)) void nCaplink::FriendTagFreeListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendTagFreeListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendTagFreeListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendTagFreeListGetReqCtx::JsonParser::number(s64 value) {
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

__attribute__((weak)) void nCaplink::FriendTagFreeListGetReqCtx::JsonParser::number(f64 value) {
}

