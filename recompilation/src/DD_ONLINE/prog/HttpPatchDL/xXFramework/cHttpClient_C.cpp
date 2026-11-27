// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <kernel.h>
#include <stdlib.h>
#include "cHttpClient_C.h"
#include "../modules/httpPatch/HttpPatchManager.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtMemory.h"
#include "../../../../MT/MtMemoryAllocator.h"
#include "../../../../MT/MtNetMediator.h"
#include "../../../../MT/MtNetObject.h"
#include "../../../../MT/MtString.h"
#include "../../../../MT/MtSynchronize.h"
#include "../../../../MT/MtThread.h"
#include "../../../../XFramework/cHttpClient.h"
#include "../modules/httpPatch/httpPatch.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static int g_createInstance_sema_name_counter;

u32 httpPatchDL_CurrentIPAddress;

__attribute__((weak)) HttpClient* HttpClient::createInstance() {
    DDON_STUB("HttpClient::createInstance")
    return nullptr;
}

void HttpClient::deleteInstance(HttpClient* ptr) {
    if (ptr == nullptr) {
        return;
    }
    delete ptr;
}

__attribute__((noinline)) HttpClient::~HttpClient() {
    DDON_STUB("HttpClient::~HttpClient")
    /* stub */
}

HttpClient::Error HttpClient::request(HttpClient::Listener& listener, bool is_keepalive, MT_CTSTR uri_authority_str_ptr, MT_CTSTR uri_path_str_ptr, HttpClient::Method method, MT_CTSTR header_str_ptr, const void* data_ptr, s32 data_size) {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        ::abort();
    }
    if (mIsInProgress && !mIsWaiting) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            ::abort();
        }
        return Error_Pending;
    }
    mListenerPtr = &listener;
    mRequestArg.isKeepalive = is_keepalive;
    mRequestArg.uriAuthStrPtr = uri_authority_str_ptr;
    mRequestArg.uriPathStrPtr = uri_path_str_ptr;
    mRequestArg.method = method;
    mRequestArg.headerStrPtr = header_str_ptr;
    if (data_ptr != nullptr) {
        if (data_size > 0) {
            mRequestArg.dataPtr = data_ptr;
            mRequestArg.dataSize = data_size;
        } else {
            mRequestArg.dataPtr = nullptr;
            mRequestArg.dataSize = 0;
        }
    } else {
        mRequestArg.dataPtr = nullptr;
        mRequestArg.dataSize = 0;
    }
    mIsInProgress = true;
    mIsWaiting = false;
    mIsGoRequest = true;
    sceKernelSignalSema(mSemaphore.mHandle, 1);
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
    return Error_None;
}

__attribute__((weak)) void HttpClient::abort() {
    DDON_STUB("HttpClient::abort")
    /* stub */
}

bool HttpClient::isInProgress() const {
    return mIsInProgress;
}

bool HttpClient::isWaiting() const {
    return mIsWaiting;
}

void HttpClient::endRequest() {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        ::abort();
    }
    mIsInProgress = true;
    mIsWaiting = false;
    mIsGoFinalize = true;
    sceKernelSignalSema(mSemaphore.mHandle, 1);
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
}

void HttpClient::setReceiveDataMaxSize(size_t data_size) {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        ::abort();
    }
    mReceiveDataMaxSize = data_size;
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
}

void HttpClient::setUserAgent(MT_CTSTR str_ptr) {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        ::abort();
    }
    mpUserAgentString = str_ptr;
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
}

void HttpClient::setProxyServer(MT_STR str_ptr) {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        ::abort();
    }
    mpProxyServerName = str_ptr;
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
}

void HttpClient::setSecurityFlags(u32 flags) {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        ::abort();
    }
    mSecurityFlags = flags;
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
}

void HttpClient::setRedirectPolicy(HttpClient::RedirectPolicy policy) {
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        ::abort();
    }
    mRedirectPolicy = policy;
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
}

__attribute__((weak)) void HttpClient::process(void* param_ptr) {
    DDON_STUB("HttpClient::process")
    /* stub */
}

__attribute__((weak)) bool HttpClient::setupTaskThread(MtObject* object, HttpClient::RequestCallback callback, MT_CTSTR thread_name, void* argument_ptr) {
    DDON_STUB("HttpClient::setupTaskThread")
    return {};
}

__attribute__((weak)) void HttpClient::nativeConstructor() {
    DDON_STUB("HttpClient::nativeConstructor")
    /* stub */
}

__attribute__((weak)) void HttpClient::nativeDestructor() {
    DDON_STUB("HttpClient::nativeDestructor")
    /* stub */
}

__attribute__((weak)) bool HttpClient::nativeInitialize(const HttpClient::RequestArg& arg) {
    DDON_STUB("HttpClient::nativeInitialize")
    return {};
}

__attribute__((weak)) void HttpClient::nativeRequest(const HttpClient::RequestArg& arg) {
    DDON_STUB("HttpClient::nativeRequest")
    /* stub */
}

__attribute__((weak)) void HttpClient::nativeRequestSleeping(HTTPDL_RETRY_STATUS* state, u32 wait) {
    DDON_STUB("HttpClient::nativeRequestSleeping")
    /* stub */
}

__attribute__((weak)) MT_CTSTR HttpClient::parseHeader(MtString& field_str, MtString& data_str, MT_CTSTR str_ptr) {
    DDON_STUB("HttpClient::parseHeader")
    return {};
}

__attribute__((weak)) bool HttpClient::addUserHeaderParam(char* strHeader) {
    DDON_STUB("HttpClient::addUserHeaderParam")
    return {};
}

__attribute__((weak)) void HttpClient::Listener::onErrorEncounterd(s32 error) {
}

void HttpClient::MtThread_HttpReqTaskProcessThread::execute(void* pcontext) {
    mpHttpClient->process(pcontext);
}

