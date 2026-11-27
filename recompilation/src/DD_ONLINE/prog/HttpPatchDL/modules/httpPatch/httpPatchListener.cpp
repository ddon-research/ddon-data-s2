// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "httpPatchListener.h"
#include "HttpPatchManager.h"
#include "../../../../../MT/MtCollisionUtil.h"
#include "../../../../../MT/MtFile.h"
#include "../../../../../MT/MtStream.h"
#include "../../../../../MT/MtString.h"
#include "../../../../../MT/MtSynchronize.h"
#include "../../xvia/atomic.h"
#include "../../xXFramework/cHttpClient_C.h"
#include "../../../../../generated/shared/directory.h"
#include "utility/hash.h"
#include "httpPatch.h"
#include "httpPatchFileCtrl.h"
#include "httpPatchTypes.h"
#include "../network/networkHttpDownloadManager.h"
#include "../../xvia/path.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MT_CTSTR TempFileExtension = ".temp";

__attribute__((weak)) bool via::module::http_patch::ExeVersionListener::secceedAfter() {
    DDON_STUB("via::module::http_patch::ExeVersionListener::secceedAfter")
    return {};
}

via::module::http_patch::FileListener::~FileListener() {
    DDON_STUB("via::module::http_patch::FileListener::~FileListener")
    /* stub */
}

bool via::module::http_patch::FileListener::secceedAfter() {
    return true;
}

__attribute__((weak)) void via::module::http_patch::FileListener::reset() {
}

__attribute__((weak)) void via::module::http_patch::FileListener::onReceiveHeader(const HttpClient::ResponseHeader& header, const u32 attribute, HttpClient::RecvBuf& next_buf) {
    DDON_STUB("via::module::http_patch::FileListener::onReceiveHeader")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileListener::onReceiveData(const void* data_ptr, size_t data_size, HttpClient::RecvBuf& next_buf) {
    DDON_STUB("via::module::http_patch::FileListener::onReceiveData")
    /* stub */
}

__attribute__((weak)) bool via::module::http_patch::FileListener::onSucceed() {
    DDON_STUB("via::module::http_patch::FileListener::onSucceed")
    return {};
}

__attribute__((weak)) void via::module::http_patch::FileListener::onFail(HPDErrCategory ecType, s32 error) {
    DDON_STUB("via::module::http_patch::FileListener::onFail")
    /* stub */
}

via::module::http_patch::ParallelsListenerManager::~ParallelsListenerManager() {
    DDON_STUB("via::module::http_patch::ParallelsListenerManager::~ParallelsListenerManager")
    /* stub */
}

void via::module::http_patch::ParallelsListenerManager::onSucceedAll() {
    mPhase = ::via::module::http_patch::FileListener::Phase_Finished;
}

void via::module::http_patch::ParallelsListenerManager::onFailAll(s32 error) {
    mPhase = ::via::module::http_patch::FileListener::Phase_Failed;
}

__attribute__((weak)) void via::module::http_patch::ParallelsListenerManager::onStart(size_t task_index, size_t uri_index, const MtString& uri_path_str) {
    DDON_STUB("via::module::http_patch::ParallelsListenerManager::onStart")
    /* stub */
}

void via::module::http_patch::ParallelsListenerManager::onReceiveHeader(size_t task_index, size_t uri_index, const MtString& uri_path_str, const HttpClient::ResponseHeader& header, HttpClient::RecvBuf& next_buf) {
    mListenerPtr[task_index]->onReceiveHeader(header, 0u, next_buf);
}

__attribute__((weak)) void via::module::http_patch::ParallelsListenerManager::onReceiveData(size_t task_index, size_t uri_index, const MtString& uri_path_str, const void* data_ptr, size_t data_size, HttpClient::RecvBuf& next_buf) {
    DDON_STUB("via::module::http_patch::ParallelsListenerManager::onReceiveData")
    /* stub */
}

void via::module::http_patch::ParallelsListenerManager::onSucceed(size_t task_index, size_t uri_index, const MtString& uri_path_str) {
    onSucceedCore(task_index, uri_index, uri_path_str);
    if (!AuthorizationOutside) {
        if (mListenerPtr[task_index] != nullptr) {
            delete mListenerPtr[task_index];
            mListenerPtr[task_index] = nullptr;
        }
    }
    mListenerPtr[task_index] = nullptr;
}

bool via::module::http_patch::ParallelsListenerManager::onSucceedCore(size_t task_index, size_t uri_index, const MtString& uri_path_str) {
    return mListenerPtr[task_index]->onSucceed();
}

__attribute__((weak)) void via::module::http_patch::ParallelsListenerManager::onFail(size_t task_index, size_t uri_index, const MtString& uri_path_str, HPDErrCategory ecType, s32 error) {
    DDON_STUB("via::module::http_patch::ParallelsListenerManager::onFail")
    /* stub */
}

bool via::module::http_patch::ParallelsListenerManager::isAbortFlagInCB() {
    return ::via::module::http_patch::HttpPatchManager::instance()->isAbortFlag();
}

void via::module::http_patch::ParallelsListenerManager::setProgressDL1File(f32 per) {
    ::via::module::http_patch::HttpPatchManager::instance()->setProgressDL1File(per);
}

void via::module::http_patch::ParallelsListenerManager::getDLRetryParams(HTTPDL_RETRY_PARAMS* buff) {
    ::via::module::http_patch::HttpPatchManager::instance()->getDLRetryParams(buff);
}

void via::module::http_patch::ParallelsListenerManager::getDLRetryStatus(HTTPDL_RETRY_STATUS* buff) {
    ::via::module::http_patch::HttpPatchManager::instance()->getDLRetryStatus(buff);
}

void via::module::http_patch::ParallelsListenerManager::storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff) {
    ::via::module::http_patch::HttpPatchManager::instance()->storeDLRetryStatus(buff);
}

void via::module::http_patch::ParallelsListenerManager::addDownloadSizeProc(void* this_ptr, const s64 size) {
    via::module::http_patch::HttpPatchManager* t0 = ::via::module::http_patch::HttpPatchManager::instance();
    if (::scePthreadMutexLock(&t0->mMutex_Download_Size.mCSection) != 0) {
        ::abort();
    }
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this_ptr) + 48) = size + (*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this_ptr) + 48));
    if (::scePthreadMutexUnlock(&t0->mMutex_Download_Size.mCSection) != 0) {
        ::abort();
    }
}

void via::module::http_patch::ParallelsListenerManager::subDownloadSizeProc(void* this_ptr, const s64 size) {
    via::module::http_patch::HttpPatchManager* t0 = ::via::module::http_patch::HttpPatchManager::instance();
    if (::scePthreadMutexLock(&t0->mMutex_Download_Size.mCSection) != 0) {
        ::abort();
    }
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this_ptr) + 48) = (*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this_ptr) + 48)) - size;
    if (::scePthreadMutexUnlock(&t0->mMutex_Download_Size.mCSection) != 0) {
        ::abort();
    }
}

