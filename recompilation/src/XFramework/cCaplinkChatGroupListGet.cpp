// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkChatGroupListGet.h"
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

void nCaplink::ChatGroupListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mChatGroupInfoTbl.mAutoDelete = true;
    if (mChatGroupInfoTbl.mLength != 0) {
        u32 v0_0 = mChatGroupInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mChatGroupInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mChatGroupInfoTbl.mpArray[i0_3];
                v1_0 = mChatGroupInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mChatGroupInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mChatGroupInfoTbl.mpArray));
    }
    mChatGroupInfoTbl.mpArray = nullptr;
    mChatGroupInfoTbl.mBufsiz = 0;
    mChatGroupInfoTbl.mLength = 0;
    mTotal = 0;
}

const MtDTI& nCaplink::ChatGroupListGetReqCtx::getDTI() const {
    return nCaplink::ChatGroupListGetReqCtx::DTI;
}

void* nCaplink::ChatGroupListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatGroupListGetReqCtx::DTI.mID);
}

nCaplink::ChatGroupListGetReqCtx::ChatGroupListGetReqCtx(MT_CTSTR datetime, s32 offset, s32 count) {
    DDON_STUB("nCaplink::ChatGroupListGetReqCtx::ChatGroupListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupListGetReqCtx::update() {
    DDON_STUB("nCaplink::ChatGroupListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupListGetReqCtx::request() {
    DDON_STUB("nCaplink::ChatGroupListGetReqCtx::request")
    /* stub */
}

inline nCaplink::ChatGroupListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatGroupListGetReqCtx::MyDTI nCaplink::ChatGroupListGetReqCtx::DTI("ChatGroupListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 200ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::ChatGroupListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::ChatGroupListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::ChatGroupListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::ChatGroupListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::ChatGroupListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::ChatGroupListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::ChatGroupListGetReqCtx::JsonParser::endObject")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupListGetReqCtx::JsonParser::fieldName")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatGroupListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbIdType) {
            mIdType = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbStatus) {
                mStatus = static_cast<s32>(static_cast<unsigned int>(value));
            } else {
                if (mbVisible) {
                    mVisible = static_cast<s32>(static_cast<unsigned int>(value));
                } else {
                    if (mbGroupSkinId) {
                        mGroupSkinId = static_cast<s32>(static_cast<unsigned int>(value));
                    } else {
                        if (mbLastChatId) {
                            mLastChatId = static_cast<s32>(static_cast<unsigned int>(value));
                        } else {
                            if (mbReadChatId) {
                                mReadChatId = static_cast<s32>(static_cast<unsigned int>(value));
                            } else {
                                if (mbMemberTotal) {
                                    mMemberTotal = static_cast<s32>(static_cast<unsigned int>(value));
                                } else {
                                    if (mbMemberLimit) {
                                        mMemberLimit = static_cast<s32>(static_cast<unsigned int>(value));
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
            }
        }
    }
}

__attribute__((weak)) void nCaplink::ChatGroupListGetReqCtx::JsonParser::number(f64 value) {
}

