// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkWebsocketServerListGet.h"
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

void nCaplink::WebsocketServerListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mTotal = 0;
    mWebsocketServerInfoTbl.mAutoDelete = true;
    if (mWebsocketServerInfoTbl.mLength != 0) {
        u32 v0_0 = mWebsocketServerInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mWebsocketServerInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mWebsocketServerInfoTbl.mpArray[i0_3];
                v1_0 = mWebsocketServerInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mWebsocketServerInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mWebsocketServerInfoTbl.mpArray));
    }
    mWebsocketServerInfoTbl.mpArray = nullptr;
    mWebsocketServerInfoTbl.mBufsiz = 0;
    mWebsocketServerInfoTbl.mLength = 0;
    mTotal = 0;
}

const MtDTI& nCaplink::WebsocketServerListGetReqCtx::getDTI() const {
    return nCaplink::WebsocketServerListGetReqCtx::DTI;
}

void* nCaplink::WebsocketServerListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::WebsocketServerListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::WebsocketServerListGetReqCtx::DTI.mID);
}

nCaplink::WebsocketServerListGetReqCtx::WebsocketServerListGetReqCtx() {
    DDON_STUB("nCaplink::WebsocketServerListGetReqCtx::WebsocketServerListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::WebsocketServerListGetReqCtx::update() {
    DDON_STUB("nCaplink::WebsocketServerListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::WebsocketServerListGetReqCtx::request() {
    DDON_STUB("nCaplink::WebsocketServerListGetReqCtx::request")
    /* stub */
}

inline nCaplink::WebsocketServerListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::WebsocketServerListGetReqCtx::MyDTI nCaplink::WebsocketServerListGetReqCtx::DTI("WebsocketServerListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::WebsocketServerListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::WebsocketServerListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::WebsocketServerListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::WebsocketServerListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::WebsocketServerListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::WebsocketServerListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::WebsocketServerListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::WebsocketServerListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "host") != 0) {
            if (::strcmp(chars, "port") != 0) {
                if (::strcmp(chars, "path") != 0) {
                    if (::strcmp(chars, "loadaverage") != 0) {
                        if (::strcmp(chars, "connections") != 0) {
                            if (::strcmp(chars, "last_life_datetime") != 0) {
                                if (::strcmp(chars, "code") != 0) {
                                    int t0 = ::strcmp(chars, "detail_message");
                                    mbTotal = false;
                                    mbHostname = false;
                                    mbPort = false;
                                    mbPath = false;
                                    mbLoadaverage = false;
                                    mbConnections = false;
                                    mbLastLifeDatetime = false;
                                    mbCode = false;
                                    if (t0 == 0) {
                                        mbDetailMessage = true;
                                    } else {
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbLastLifeDatetime = false;
                                    mbLoadaverage = false;
                                    mbConnections = false;
                                    mbTotal = false;
                                    mbHostname = false;
                                    mbPort = false;
                                    mbPath = false;
                                    mbCode = true;
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbLoadaverage = false;
                                mbConnections = false;
                                mbTotal = false;
                                mbHostname = false;
                                mbPort = false;
                                mbPath = false;
                                mbLastLifeDatetime = true;
                                mbCode = false;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbLoadaverage = false;
                            mbTotal = false;
                            mbHostname = false;
                            mbPort = false;
                            mbPath = false;
                            mbConnections = true;
                            mbLastLifeDatetime = false;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbHostname = false;
                        mbPort = false;
                        mbPath = false;
                        mbLoadaverage = true;
                        mbConnections = false;
                        mbLastLifeDatetime = false;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbHostname = false;
                    mbPort = false;
                    mbPath = true;
                    mbDetailMessage = false;
                    mbLoadaverage = false;
                    mbConnections = false;
                    mbLastLifeDatetime = false;
                    mbCode = false;
                }
            } else {
                mbTotal = false;
                mbHostname = false;
                mbPort = true;
                mbCode = false;
                mbDetailMessage = false;
                mbPath = false;
                mbLoadaverage = false;
                mbConnections = false;
                mbLastLifeDatetime = false;
            }
        } else {
            mbTotal = false;
            mbHostname = true;
            mbDetailMessage = false;
            mbLastLifeDatetime = false;
            mbCode = false;
            mbPort = false;
            mbPath = false;
            mbLoadaverage = false;
            mbConnections = false;
        }
    } else {
        mbTotal = true;
        mbHostname = false;
        mbPort = false;
        mbPath = false;
        mbLoadaverage = false;
        mbConnections = false;
        mbLastLifeDatetime = false;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::WebsocketServerListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::WebsocketServerListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::WebsocketServerListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::WebsocketServerListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbPort) {
            mPort = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbLoadaverage) {
                mLoadaverage = static_cast<s32>(static_cast<unsigned int>(value));
            } else {
                if (mbConnections) {
                    mConnections = static_cast<s32>(static_cast<unsigned int>(value));
                } else {
                    if (mbCode) {
                        mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::WebsocketServerListGetReqCtx::JsonParser::number(f64 value) {
}

