// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendTagContentListGet.h"
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

void nCaplink::FriendTagContentListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mContentTagInfoTbl.mAutoDelete = true;
    if (mContentTagInfoTbl.mLength != 0) {
        u32 v0_0 = mContentTagInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mContentTagInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mContentTagInfoTbl.mpArray[i0_3];
                v1_0 = mContentTagInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContentTagInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mContentTagInfoTbl.mpArray));
    }
    mContentTagInfoTbl.mpArray = nullptr;
    mContentTagInfoTbl.mBufsiz = 0;
    mContentTagInfoTbl.mLength = 0;
    mTotal = 0;
}

const MtDTI& nCaplink::FriendTagContentListGetReqCtx::getDTI() const {
    return nCaplink::FriendTagContentListGetReqCtx::DTI;
}

void* nCaplink::FriendTagContentListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendTagContentListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendTagContentListGetReqCtx::DTI.mID);
}

nCaplink::FriendTagContentListGetReqCtx::FriendTagContentListGetReqCtx(MT_CTSTR from_datetime, s32 offset, s32 count) {
    DDON_STUB("nCaplink::FriendTagContentListGetReqCtx::FriendTagContentListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendTagContentListGetReqCtx::update() {
    DDON_STUB("nCaplink::FriendTagContentListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendTagContentListGetReqCtx::request() {
    DDON_STUB("nCaplink::FriendTagContentListGetReqCtx::request")
    /* stub */
}

inline nCaplink::FriendTagContentListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendTagContentListGetReqCtx::MyDTI nCaplink::FriendTagContentListGetReqCtx::DTI("FriendTagContentListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::FriendTagContentListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::FriendTagContentListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::FriendTagContentListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::FriendTagContentListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::FriendTagContentListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::FriendTagContentListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::FriendTagContentListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::FriendTagContentListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "unique_id") != 0) {
            if (::strcmp(chars, "tag_id") != 0) {
                if (::strcmp(chars, "character_name") != 0) {
                    if (::strcmp(chars, "online") != 0) {
                        if (::strcmp(chars, "visible") != 0) {
                            if (::strcmp(chars, "updated_at") != 0) {
                                if (::strcmp(chars, "code") != 0) {
                                    int t0 = ::strcmp(chars, "detail_message");
                                    mbTotal = false;
                                    mbUniqueId = false;
                                    mbTagId = false;
                                    mbCharacterName = false;
                                    mbOnline = false;
                                    mbVisible = false;
                                    mbUpdateAt = false;
                                    mbCode = false;
                                    if (t0 == 0) {
                                        mbDetailMessage = true;
                                    } else {
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbUpdateAt = false;
                                    mbOnline = false;
                                    mbVisible = false;
                                    mbTotal = false;
                                    mbUniqueId = false;
                                    mbTagId = false;
                                    mbCharacterName = false;
                                    mbCode = true;
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbOnline = false;
                                mbVisible = false;
                                mbTotal = false;
                                mbUniqueId = false;
                                mbTagId = false;
                                mbCharacterName = false;
                                mbUpdateAt = true;
                                mbCode = false;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbOnline = false;
                            mbTotal = false;
                            mbUniqueId = false;
                            mbTagId = false;
                            mbCharacterName = false;
                            mbVisible = true;
                            mbUpdateAt = false;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbUniqueId = false;
                        mbTagId = false;
                        mbCharacterName = false;
                        mbOnline = true;
                        mbVisible = false;
                        mbUpdateAt = false;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbUniqueId = false;
                    mbTagId = false;
                    mbCharacterName = true;
                    mbDetailMessage = false;
                    mbOnline = false;
                    mbVisible = false;
                    mbUpdateAt = false;
                    mbCode = false;
                }
            } else {
                mbTotal = false;
                mbUniqueId = false;
                mbTagId = true;
                mbCode = false;
                mbDetailMessage = false;
                mbCharacterName = false;
                mbOnline = false;
                mbVisible = false;
                mbUpdateAt = false;
            }
        } else {
            mbTotal = false;
            mbUniqueId = true;
            mbDetailMessage = false;
            mbUpdateAt = false;
            mbCode = false;
            mbTagId = false;
            mbCharacterName = false;
            mbOnline = false;
            mbVisible = false;
        }
    } else {
        mbTotal = true;
        mbUniqueId = false;
        mbTagId = false;
        mbCharacterName = false;
        mbOnline = false;
        mbVisible = false;
        mbUpdateAt = false;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::FriendTagContentListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendTagContentListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendTagContentListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendTagContentListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbTagId) {
            mTagId = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbOnline) {
                mOnline = static_cast<s8>(static_cast<unsigned char>(value));
            } else {
                if (mbVisible) {
                    mVisible = static_cast<s8>(static_cast<unsigned char>(value));
                } else {
                    if (mbCode) {
                        mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::FriendTagContentListGetReqCtx::JsonParser::number(f64 value) {
}

