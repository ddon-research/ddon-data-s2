// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkContext.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nCaplink::Context::getDTI() const {
    return nCaplink::Context::DTI;
}

void nCaplink::Context::start(nCaplink::ContextListener* pListener, cWebsocketClient* pWsc) {
    mpListener = pListener;
    mPhase = 0;
    mIsInProgress = true;
    mpWsc = pWsc;
}

void nCaplink::Context::end() {
    mpListener = nullptr;
}

inline nCaplink::Context::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::Context::MyDTI nCaplink::Context::DTI("Context", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* nCaplink::Context::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::Context;
}

const MtDTI& nCaplink::ContextListener::getDTI() const {
    return nCaplink::ContextListener::DTI;
}

__attribute__((weak)) void nCaplink::ContextListener::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::ContextListener::DTI)->memFree(p_addr);
}

nCaplink::ContextListener::ContextListener() {
    mStatus = 0;
}

nCaplink::ContextListener::~ContextListener() {
    DDON_STUB("nCaplink::ContextListener::~ContextListener")
    /* stub */
}

void nCaplink::ContextListener::init() {
    mStatus = 0;
    mErrorType = 0;
    mErrorCode = 0;
    if (mDetailMessage.value == nullptr) {
        return;
    }
    if (static_cast<const void*>("") == static_cast<const void*>(&mDetailMessage.value->str)) {
        return;
    }
    if (::__atomic_fetch_add(&mDetailMessage.value->ref, -1, __ATOMIC_SEQ_CST) == 1) {
        (::MtString::mpAllocator)->memFree(static_cast<void*>(mDetailMessage.value));
    }
    mDetailMessage.value = nullptr;
}

inline nCaplink::ContextListener::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContextListener::MyDTI nCaplink::ContextListener::DTI("ContextListener", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* nCaplink::ContextListener::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ContextListener;
}

const MtDTI& nCaplink::HttpRequestContext::getDTI() const {
    return nCaplink::HttpRequestContext::DTI;
}

nCaplink::HttpRequestContext::HttpRequestContext() {
    DDON_STUB("nCaplink::HttpRequestContext::HttpRequestContext")
    /* stub */
}

nCaplink::HttpRequestContext::HttpRequestContext(s32 type) {
    DDON_STUB("nCaplink::HttpRequestContext::HttpRequestContext")
    /* stub */
}

nCaplink::HttpRequestContext::~HttpRequestContext() {
    DDON_STUB("nCaplink::HttpRequestContext::~HttpRequestContext")
    /* stub */
}

void nCaplink::HttpRequestContext::start(nCaplink::ContextListener* pListener, cWebsocketClient* pWsc) {
    mpHttpClient = nullptr;
    mpHttpClient = new (16u) ::cHttpClient;
    u32 t1 = mHttpClientListener.mpStream->getPosition();
    mHttpClientListener.mSeekPt = static_cast<s32>(mHttpClientListener.mSeekPt + t1);
    mHttpClientListener.mStatus = 0;
    mHttpClientListener.mCode = 0;
    mHttpClientListener.mError = 0;
    mpListener = pListener;
    mPhase = 0;
    mIsInProgress = true;
    mpWsc = pWsc;
}

void nCaplink::HttpRequestContext::end() {
    if (mpHttpClient != nullptr) {
        delete mpHttpClient;
        mpHttpClient = nullptr;
    }
    mpListener = nullptr;
}

void nCaplink::HttpRequestContext::update() {
    if (mpHttpClient == nullptr) {
        return;
    }
    mpHttpClient->move();
}

__attribute__((weak)) void nCaplink::HttpRequestContext::request() {
}

void nCaplink::HttpRequestContext::initHttpClient() {
    if (mpHttpClient == nullptr) {
        mpHttpClient = new (16u) ::cHttpClient;
        u32 t1 = mHttpClientListener.mpStream->getPosition();
        mHttpClientListener.mSeekPt = static_cast<s32>(mHttpClientListener.mSeekPt + t1);
    } else {
        u32 t1 = mHttpClientListener.mpStream->getPosition();
        mHttpClientListener.mSeekPt = static_cast<s32>(mHttpClientListener.mSeekPt + t1);
    }
    mHttpClientListener.mStatus = 0;
    mHttpClientListener.mCode = 0;
    mHttpClientListener.mError = 0;
}

__attribute__((weak)) MtString nCaplink::HttpRequestContext::makeRequestBody(MtString path, MtString data) {
    DDON_STUB("nCaplink::HttpRequestContext::makeRequestBody")
    __builtin_unreachable();
}

inline nCaplink::HttpRequestContext::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::HttpRequestContext::MyDTI nCaplink::HttpRequestContext::DTI("HttpRequestContext", &::nCaplink::Context::DTI, 104ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::HttpRequestContext::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::HttpRequestContext::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::HttpRequestContext::HttpClientListener::onReceiveHeader(const cHttpClient::ResponseHeader* pHeader) {
    mCode = pHeader->mStatusCode;
    mStatus = 1;
}

__attribute__((weak)) void nCaplink::HttpRequestContext::HttpClientListener::onReceiveData(void* pData, s32 cData) {
    DDON_STUB("nCaplink::HttpRequestContext::HttpClientListener::onReceiveData")
    /* stub */
}

void nCaplink::HttpRequestContext::HttpClientListener::onErrorEncounterd(s32 error) {
    mStatus = 3;
    mError = error;
}

