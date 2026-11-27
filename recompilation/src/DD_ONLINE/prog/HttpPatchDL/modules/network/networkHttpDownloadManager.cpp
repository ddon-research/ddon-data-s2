// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "networkHttpDownloadManager.h"
#include "../../../../../MT/MtAllocator.h"
#include "../../../../../MT/MtCollisionUtil.h"
#include "../../../../../MT/MtDTI.h"
#include "../../../../../MT/MtMemory.h"
#include "../../../../../MT/MtMemoryAllocator.h"
#include "../../../../../MT/MtObject.h"
#include "../../../../../MT/MtString.h"
#include "../../../../../MT/MtSynchronize.h"
#include "../../xvia/atomic.h"
#include "../../xXFramework/cHttpClient_C.h"
#include "../httpPatch/httpPatch.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

via::module::network::utility::HttpDownloadManager::HttpDownloadManager() {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::HttpDownloadManager")
    /* stub */
}

__attribute__((noinline)) via::module::network::utility::HttpDownloadManager::~HttpDownloadManager() {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::~HttpDownloadManager")
    /* stub */
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::update() {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::update")
    /* stub */
}

__attribute__((weak)) HttpClient::Error via::module::network::utility::HttpDownloadManager::request(via::module::network::utility::HttpDownloadManager::Listener& listener, MT_CTSTR uri_authority_str_ptr, MT_CTSTR uri_path_str_ptr, const int affinity) {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::request")
    return {};
}

__attribute__((weak)) HttpClient::Error via::module::network::utility::HttpDownloadManager::request(via::module::network::utility::HttpDownloadManager::Listener& listener, size_t task_num, MT_CTSTR uri_authority_str_ptr, const httpdl_array_MtStringExURL* uri_path_str_tbl, const httpdl_array_s32* affinity_tbl) {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::request")
    return {};
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::abortAll() {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::abortAll")
    /* stub */
}

bool via::module::network::utility::HttpDownloadManager::isInProgress() const {
    return mIsInProgress.mBool;
}

void via::module::network::utility::HttpDownloadManager::setReceiveDataMaxSize(size_t data_size) {
    if (::scePthreadMutexLock(&mCS.mCSection) != 0) {
        ::abort();
    }
    mReceiveDataMaxSize = data_size;
    if (::scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
}

void via::module::network::utility::HttpDownloadManager::setUserAgent(MT_CTSTR str_ptr) {
    if (mIsThreadSafe) {
        if (::scePthreadMutexLock(&mCS.mCSection) != 0) {
            ::abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        mUserAgentStrPtr = str_ptr;
        if (mIsThreadSafe) {
            mLockCount = t0;
            if (::scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                ::abort();
            }
        }
    } else {
        mUserAgentStrPtr = str_ptr;
    }
}

void via::module::network::utility::HttpDownloadManager::setProxyServer(MT_CTSTR str_ptr) {
    if (mIsThreadSafe) {
        if (::scePthreadMutexLock(&mCS.mCSection) != 0) {
            ::abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        mProxyNameStrPtr = str_ptr;
        if (mIsThreadSafe) {
            mLockCount = t0;
            if (::scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                ::abort();
            }
        }
    } else {
        mProxyNameStrPtr = str_ptr;
    }
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::setAllowInsecure(bool flag) {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::setAllowInsecure")
    /* stub */
}

void via::module::network::utility::HttpDownloadManager::setSecurityFlags(u32 flags) {
    if (mIsThreadSafe) {
        if (::scePthreadMutexLock(&mCS.mCSection) != 0) {
            ::abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        mSecurityFlags = flags;
        if (mIsThreadSafe) {
            mLockCount = t0;
            if (::scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                ::abort();
            }
        }
    } else {
        mSecurityFlags = flags;
    }
}

void via::module::network::utility::HttpDownloadManager::setRedirectPolicy(HttpClient::RedirectPolicy policy) {
    if (mIsThreadSafe) {
        if (::scePthreadMutexLock(&mCS.mCSection) != 0) {
            ::abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        mRedirectPolicy = policy;
        if (mIsThreadSafe) {
            mLockCount = t0;
            if (::scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                ::abort();
            }
        }
    } else {
        mRedirectPolicy = policy;
    }
}

void via::module::network::utility::HttpDownloadManager::taskInit(HttpClient* ptr) {
    if (mIsThreadSafe) {
        if (::scePthreadMutexLock(&mCS.mCSection) != 0) {
            ::abort();
        }
        mLockCount = mLockCount + 1;
    }
    ptr->setReceiveDataMaxSize(mReceiveDataMaxSize);
    ptr->setUserAgent(mUserAgentStrPtr);
    ptr->setProxyServer(const_cast<char*>(mProxyNameStrPtr));
    ptr->setSecurityFlags(mSecurityFlags);
    ptr->setRedirectPolicy(mRedirectPolicy);
    if (!mIsThreadSafe) {
        return;
    }
    mLockCount = mLockCount - 1;
    if (::scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        ::abort();
    }
}

via::module::network::utility::HttpDownloadManager* via::module::network::utility::HttpDownloadManager::mpInstance;

via::module::network::utility::HttpDownloadManager::Task::Task() {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::Task::Task")
    /* stub */
}

via::module::network::utility::HttpDownloadManager::Task::~Task() {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::Task::~Task")
    /* stub */
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::Task::update() {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::Task::update")
    /* stub */
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::Task::onReceiveHeader(const HttpClient::ResponseHeader& header, HttpClient::RecvBuf& next_buf) {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::Task::onReceiveHeader")
    /* stub */
}

void via::module::network::utility::HttpDownloadManager::Task::onReceiveData(const void* data_ptr, size_t data_size, HttpClient::RecvBuf& next_buf) {
    if (mManagerPtr->mListenerPtr == nullptr) {
        return;
    }
    mManagerPtr->mListenerPtr->onReceiveData(mIndex, mUriIdx, mUriStr, data_ptr, data_size, next_buf);
}

void via::module::network::utility::HttpDownloadManager::Task::onSucceed() {
    size_t t0 = mCbStatusCode;
    via::module::network::utility::HttpDownloadManager* t1 = mManagerPtr;
    size_t t2 = mIndex;
    size_t t3 = mUriIdx;
    if (t0 == 200) {
        t1->mPathUriTbl.succeed(mUriStr);
        if (t1->mListenerPtr != nullptr) {
            t1->mListenerPtr->onSucceed(t2, t3, mUriStr);
        }
    } else {
        t1->mPathUriTbl.fail(mUriStr, ::HPDE_Http, static_cast<s32>(static_cast<unsigned int>(t0)));
        if (t1->mListenerPtr != nullptr) {
            t1->mListenerPtr->onFail(t2, t3, mUriStr, ::HPDE_Http, static_cast<s32>(static_cast<unsigned int>(t0)));
        }
    }
}

void via::module::network::utility::HttpDownloadManager::Task::onFail(HPDErrCategory ecType, s32 error) {
    via::module::network::utility::HttpDownloadManager* t0 = mManagerPtr;
    size_t t1 = mIndex;
    size_t t2 = mUriIdx;
    t0->mPathUriTbl.fail(mUriStr, ecType, error);
    if (t0->mListenerPtr == nullptr) {
        return;
    }
    t0->mListenerPtr->onFail(t1, t2, mUriStr, ecType, error);
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::Task::onWait() {
}

void via::module::network::utility::HttpDownloadManager::Task::setProgressDL1File(f32 per) {
    if (mManagerPtr->mListenerPtr == nullptr) {
        return;
    }
    mManagerPtr->mListenerPtr->setProgressDL1File(per);
}

void via::module::network::utility::HttpDownloadManager::Task::getDLRetryParams(HTTPDL_RETRY_PARAMS* buff) {
    if (mManagerPtr->mListenerPtr != nullptr) {
        mManagerPtr->mListenerPtr->getDLRetryParams(buff);
    } else {
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(buff) + 0) = 0x25800000000;
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(buff) + 8) = 0x4019999A;
    }
}

void via::module::network::utility::HttpDownloadManager::Task::getDLRetryStatus(HTTPDL_RETRY_STATUS* buff) {
    if (mManagerPtr->mListenerPtr == nullptr) {
        return;
    }
    mManagerPtr->mListenerPtr->getDLRetryStatus(buff);
}

void via::module::network::utility::HttpDownloadManager::Task::storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff) {
    if (mManagerPtr->mListenerPtr == nullptr) {
        return;
    }
    mManagerPtr->mListenerPtr->storeDLRetryStatus(buff);
}

bool via::module::network::utility::HttpDownloadManager::Task::isAbortFlagInCB() {
    return mManagerPtr->mListenerPtr->isAbortFlagInCB();
}

u32 via::module::network::utility::HttpDownloadManager::Task::getCbContentLength() {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 96);
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::UriTbl::clear() {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::UriTbl::clear")
    /* stub */
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::UriTbl::import(const httpdl_array_MtStringExURL* tbl, const httpdl_array_s32* affinity_tbl) {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::UriTbl::import")
    /* stub */
}

__attribute__((weak)) s32 via::module::network::utility::HttpDownloadManager::UriTbl::next(const size_t task_index, MtString* & ptr) {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::UriTbl::next")
    return {};
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::UriTbl::succeed(const MtString& str) {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::UriTbl::succeed")
    /* stub */
}

__attribute__((weak)) void via::module::network::utility::HttpDownloadManager::UriTbl::fail(const MtString& str, HPDErrCategory ecType, s32 error) {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::UriTbl::fail")
    /* stub */
}

const MtDTI& via::module::network::utility::HttpDownloadManager::UriTbl::Uri::getDTI() const {
    return via::module::network::utility::HttpDownloadManager::UriTbl::Uri::DTI;
}

inline via::module::network::utility::HttpDownloadManager::UriTbl::Uri::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

via::module::network::utility::HttpDownloadManager::UriTbl::Uri::MyDTI via::module::network::utility::HttpDownloadManager::UriTbl::Uri::DTI("via::module::network::utility::HttpDownloadManager::UriTbl::Uri", &::MtObject::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* via::module::network::utility::HttpDownloadManager::UriTbl::Uri::MyDTI::newInstance() const {
    DDON_STUB("via::module::network::utility::HttpDownloadManager::UriTbl::Uri::MyDTI::newInstance")
    return nullptr;
}

