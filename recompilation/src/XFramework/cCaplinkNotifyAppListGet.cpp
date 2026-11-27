// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkNotifyAppListGet.h"
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

void nCaplink::NotifyAppListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mNotifyAppInfoTbl.mAutoDelete = true;
    if (mNotifyAppInfoTbl.mLength != 0) {
        u32 v0_0 = mNotifyAppInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mNotifyAppInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mNotifyAppInfoTbl.mpArray[i0_3];
                v1_0 = mNotifyAppInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mNotifyAppInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mNotifyAppInfoTbl.mpArray));
    }
    mNotifyAppInfoTbl.mpArray = nullptr;
    mNotifyAppInfoTbl.mBufsiz = 0;
    mNotifyAppInfoTbl.mLength = 0;
    mTotal = 0;
}

const MtDTI& nCaplink::NotifyAppListGetReqCtx::getDTI() const {
    return nCaplink::NotifyAppListGetReqCtx::DTI;
}

void* nCaplink::NotifyAppListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyAppListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::NotifyAppListGetReqCtx::DTI.mID);
}

nCaplink::NotifyAppListGetReqCtx::NotifyAppListGetReqCtx(s32 offset, s32 count) {
    DDON_STUB("nCaplink::NotifyAppListGetReqCtx::NotifyAppListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyAppListGetReqCtx::update() {
    DDON_STUB("nCaplink::NotifyAppListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyAppListGetReqCtx::request() {
    DDON_STUB("nCaplink::NotifyAppListGetReqCtx::request")
    /* stub */
}

inline nCaplink::NotifyAppListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::NotifyAppListGetReqCtx::MyDTI nCaplink::NotifyAppListGetReqCtx::DTI("NotifyAppListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::NotifyAppListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::NotifyAppListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::NotifyAppListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::NotifyAppListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::NotifyAppListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::NotifyAppListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::NotifyAppListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::NotifyAppListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "notify_id") != 0) {
            if (::strcmp(chars, "content_id") != 0) {
                if (::strcmp(chars, "message") != 0) {
                    if (::strcmp(chars, "param") != 0) {
                        if (::strcmp(chars, "unique_id") != 0) {
                            if (::strcmp(chars, "nickname") != 0) {
                                if (::strcmp(chars, "icon") != 0) {
                                    if (::strcmp(chars, "notify_type") != 0) {
                                        if (::strcmp(chars, "view_type") != 0) {
                                            if (::strcmp(chars, "updated_at") != 0) {
                                                if (::strcmp(chars, "code") != 0) {
                                                    int t0 = ::strcmp(chars, "detail_message");
                                                    mbNotifyType = false;
                                                    mbViewType = false;
                                                    mbUpdatedAt = false;
                                                    mbCode = false;
                                                    mbTotal = false;
                                                    mbNotifyId = false;
                                                    mbContentId = false;
                                                    mbMessage = false;
                                                    mbParam = false;
                                                    mbUniqueId = false;
                                                    mbNickname = false;
                                                    mbIcon = false;
                                                    if (t0 == 0) {
                                                        mbDetailMessage = true;
                                                    } else {
                                                        mbDetailMessage = false;
                                                    }
                                                } else {
                                                    mbUpdatedAt = false;
                                                    mbNotifyType = false;
                                                    mbViewType = false;
                                                    mbTotal = false;
                                                    mbNotifyId = false;
                                                    mbContentId = false;
                                                    mbMessage = false;
                                                    mbParam = false;
                                                    mbUniqueId = false;
                                                    mbNickname = false;
                                                    mbIcon = false;
                                                    mbCode = true;
                                                    mbDetailMessage = false;
                                                }
                                            } else {
                                                mbNotifyType = false;
                                                mbViewType = false;
                                                mbTotal = false;
                                                mbNotifyId = false;
                                                mbContentId = false;
                                                mbMessage = false;
                                                mbParam = false;
                                                mbUniqueId = false;
                                                mbNickname = false;
                                                mbIcon = false;
                                                mbUpdatedAt = true;
                                                mbCode = false;
                                                mbDetailMessage = false;
                                            }
                                        } else {
                                            mbNotifyType = false;
                                            mbTotal = false;
                                            mbNotifyId = false;
                                            mbContentId = false;
                                            mbMessage = false;
                                            mbParam = false;
                                            mbUniqueId = false;
                                            mbNickname = false;
                                            mbIcon = false;
                                            mbViewType = true;
                                            mbUpdatedAt = false;
                                            mbCode = false;
                                            mbDetailMessage = false;
                                        }
                                    } else {
                                        mbTotal = false;
                                        mbNotifyId = false;
                                        mbContentId = false;
                                        mbMessage = false;
                                        mbParam = false;
                                        mbUniqueId = false;
                                        mbNickname = false;
                                        mbIcon = false;
                                        mbNotifyType = true;
                                        mbViewType = false;
                                        mbUpdatedAt = false;
                                        mbCode = false;
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbNickname = false;
                                    mbParam = false;
                                    mbUniqueId = false;
                                    mbTotal = false;
                                    mbNotifyId = false;
                                    mbContentId = false;
                                    mbMessage = false;
                                    mbIcon = true;
                                    mbDetailMessage = false;
                                    mbNotifyType = false;
                                    mbViewType = false;
                                    mbUpdatedAt = false;
                                    mbCode = false;
                                }
                            } else {
                                mbParam = false;
                                mbUniqueId = false;
                                mbTotal = false;
                                mbNotifyId = false;
                                mbContentId = false;
                                mbMessage = false;
                                mbNickname = true;
                                mbCode = false;
                                mbDetailMessage = false;
                                mbIcon = false;
                                mbNotifyType = false;
                                mbViewType = false;
                                mbUpdatedAt = false;
                            }
                        } else {
                            mbParam = false;
                            mbTotal = false;
                            mbNotifyId = false;
                            mbContentId = false;
                            mbMessage = false;
                            mbUniqueId = true;
                            mbDetailMessage = false;
                            mbUpdatedAt = false;
                            mbCode = false;
                            mbNickname = false;
                            mbIcon = false;
                            mbNotifyType = false;
                            mbViewType = false;
                        }
                    } else {
                        mbTotal = false;
                        mbNotifyId = false;
                        mbContentId = false;
                        mbMessage = false;
                        mbParam = true;
                        mbUniqueId = false;
                        mbNickname = false;
                        mbIcon = false;
                        mbNotifyType = false;
                        mbViewType = false;
                        mbUpdatedAt = false;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbNotifyId = false;
                    mbContentId = false;
                    mbMessage = true;
                    mbDetailMessage = false;
                    mbParam = false;
                    mbUniqueId = false;
                    mbNickname = false;
                    mbIcon = false;
                    mbNotifyType = false;
                    mbViewType = false;
                    mbUpdatedAt = false;
                    mbCode = false;
                }
            } else {
                mbTotal = false;
                mbNotifyId = false;
                mbContentId = true;
                mbCode = false;
                mbDetailMessage = false;
                mbMessage = false;
                mbParam = false;
                mbUniqueId = false;
                mbNickname = false;
                mbIcon = false;
                mbNotifyType = false;
                mbViewType = false;
                mbUpdatedAt = false;
            }
        } else {
            mbTotal = false;
            mbNotifyId = true;
            mbDetailMessage = false;
            mbUpdatedAt = false;
            mbCode = false;
            mbContentId = false;
            mbMessage = false;
            mbParam = false;
            mbUniqueId = false;
            mbNickname = false;
            mbIcon = false;
            mbNotifyType = false;
            mbViewType = false;
        }
    } else {
        mbTotal = true;
        mbViewType = false;
        mbUpdatedAt = false;
        mbCode = false;
        mbDetailMessage = false;
        mbNotifyId = false;
        mbContentId = false;
        mbMessage = false;
        mbParam = false;
        mbUniqueId = false;
        mbNickname = false;
        mbIcon = false;
        mbNotifyType = false;
    }
}

__attribute__((weak)) void nCaplink::NotifyAppListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::NotifyAppListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyAppListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::NotifyAppListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbNotifyId) {
            mNotifyId = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbNotifyType) {
                mNotifyType = static_cast<s32>(static_cast<unsigned int>(value));
            } else {
                if (mbViewType) {
                    mViewType = static_cast<s32>(static_cast<unsigned int>(value));
                } else {
                    if (mbCode) {
                        mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::NotifyAppListGetReqCtx::JsonParser::number(f64 value) {
}

