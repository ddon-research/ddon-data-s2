// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "httpPatchClient.h"
#include "../../../../../MT/MtString.h"
#include "httpPatch.h"
#include "httpPatchListener.h"
#include "httpPatchTypes.h"
#include "../network/networkHttpDownloadManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

via::module::http_patch::ClientManager::ClientManager() {
    DDON_STUB("via::module::http_patch::ClientManager::ClientManager")
    /* stub */
}

via::module::http_patch::ClientManager::~ClientManager() {
}

void via::module::http_patch::ClientManager::setParam(const via::module::http_patch::RequestParamCore& param) {
    MtString::STRING* t0 = param.mAuthorityURL.value;
    if ((&mAuthorityURL.mStr[0]) != param.mAuthorityURL.ptr()) {
        size_t t1 = ::strlen(param.mAuthorityURL.ptr());
        mAuthorityURL.mLength = (static_cast<int>(t1) <= 1023) ? static_cast<unsigned int>(t1) : 1023u;
        if (((static_cast<int>(t1) <= 1023) ? static_cast<unsigned int>(t1) : 1023u) != 0) {
            ::memcpy(static_cast<void*>(&mAuthorityURL.mStr[0]), static_cast<const void*>(param.mAuthorityURL.ptr()), static_cast<size_t>((static_cast<int>(t1) <= 1023) ? static_cast<unsigned int>(t1) : 1023u));
            mAuthorityURL.mStr[(static_cast<int>(t1) <= 1023) ? static_cast<unsigned int>(t1) : 1023u] = 0;
        } else {
            mAuthorityURL.mStr[0] = 0;
        }
    }
    MtString::STRING* t2 = param.mURLDirectory.value;
    if ((&mURLDirectory.mStr[0]) != param.mURLDirectory.ptr()) {
        size_t t3 = ::strlen(param.mURLDirectory.ptr());
        mURLDirectory.mLength = (static_cast<int>(t3) <= 1023) ? static_cast<unsigned int>(t3) : 1023u;
        if (((static_cast<int>(t3) <= 1023) ? static_cast<unsigned int>(t3) : 1023u) != 0) {
            ::memcpy(static_cast<void*>(&mURLDirectory.mStr[0]), static_cast<const void*>(param.mURLDirectory.ptr()), static_cast<size_t>((static_cast<int>(t3) <= 1023) ? static_cast<unsigned int>(t3) : 1023u));
            mURLDirectory.mStr[(static_cast<int>(t3) <= 1023) ? static_cast<unsigned int>(t3) : 1023u] = 0;
        } else {
            mURLDirectory.mStr[0] = 0;
        }
    }
    MtString::STRING* t4 = param.mUserAgent.value;
    if ((&mUserAgent.mStr[0]) != param.mUserAgent.ptr()) {
        size_t t5 = ::strlen(param.mUserAgent.ptr());
        mUserAgent.mLength = (static_cast<int>(t5) <= 127) ? static_cast<unsigned int>(t5) : 127u;
        if (((static_cast<int>(t5) <= 127) ? static_cast<unsigned int>(t5) : 127u) != 0) {
            ::memcpy(static_cast<void*>(&mUserAgent.mStr[0]), static_cast<const void*>(param.mUserAgent.ptr()), static_cast<size_t>((static_cast<int>(t5) <= 127) ? static_cast<unsigned int>(t5) : 127u));
            mUserAgent.mStr[(static_cast<int>(t5) <= 127) ? static_cast<unsigned int>(t5) : 127u] = 0;
        } else {
            mUserAgent.mStr[0] = 0;
        }
    }
    MtString::STRING* t6 = param.mProxyServer.value;
    if ((&mProxyServer.mStr[0]) != param.mProxyServer.ptr()) {
        size_t t7 = ::strlen(param.mProxyServer.ptr());
        mProxyServer.mLength = (static_cast<int>(t7) <= 127) ? static_cast<unsigned int>(t7) : 127u;
        if (((static_cast<int>(t7) <= 127) ? static_cast<unsigned int>(t7) : 127u) != 0) {
            ::memcpy(static_cast<void*>(&mProxyServer.mStr[0]), static_cast<const void*>(param.mProxyServer.ptr()), static_cast<size_t>((static_cast<int>(t7) <= 127) ? static_cast<unsigned int>(t7) : 127u));
            mProxyServer.mStr[(static_cast<int>(t7) <= 127) ? static_cast<unsigned int>(t7) : 127u] = 0;
        } else {
            mProxyServer.mStr[0] = 0;
        }
    }
    MtString::STRING* t8 = param.mVersionListName.value;
    if ((&mVersionListName.mStr[0]) != param.mVersionListName.ptr()) {
        size_t t9 = ::strlen(param.mVersionListName.ptr());
        mVersionListName.mLength = (static_cast<int>(t9) <= 127) ? static_cast<unsigned int>(t9) : 127u;
        if (((static_cast<int>(t9) <= 127) ? static_cast<unsigned int>(t9) : 127u) != 0) {
            ::memcpy(static_cast<void*>(&mVersionListName.mStr[0]), static_cast<const void*>(param.mVersionListName.ptr()), static_cast<size_t>((static_cast<int>(t9) <= 127) ? static_cast<unsigned int>(t9) : 127u));
            mVersionListName.mStr[(static_cast<int>(t9) <= 127) ? static_cast<unsigned int>(t9) : 127u] = 0;
        } else {
            mVersionListName.mStr[0] = 0;
        }
    }
    MtString::STRING* t10 = param.mFileListName.value;
    if ((&mFileListName.mStr[0]) != param.mFileListName.ptr()) {
        size_t t11 = ::strlen(param.mFileListName.ptr());
        mFileListName.mLength = (static_cast<int>(t11) <= 127) ? static_cast<unsigned int>(t11) : 127u;
        if (((static_cast<int>(t11) <= 127) ? static_cast<unsigned int>(t11) : 127u) != 0) {
            ::memcpy(static_cast<void*>(&mFileListName.mStr[0]), static_cast<const void*>(param.mFileListName.ptr()), static_cast<size_t>((static_cast<int>(t11) <= 127) ? static_cast<unsigned int>(t11) : 127u));
            mFileListName.mStr[(static_cast<int>(t11) <= 127) ? static_cast<unsigned int>(t11) : 127u] = 0;
        } else {
            mFileListName.mStr[0] = 0;
        }
    }
    MtString::STRING* t12 = param.mExeVersionFileName.value;
    if ((&mExeVersionFileName.mStr[0]) != param.mExeVersionFileName.ptr()) {
        size_t t13 = ::strlen(param.mExeVersionFileName.ptr());
        mExeVersionFileName.mLength = (static_cast<int>(t13) <= 127) ? static_cast<unsigned int>(t13) : 127u;
        if (((static_cast<int>(t13) <= 127) ? static_cast<unsigned int>(t13) : 127u) != 0) {
            ::memcpy(static_cast<void*>(&mExeVersionFileName.mStr[0]), static_cast<const void*>(param.mExeVersionFileName.ptr()), static_cast<size_t>((static_cast<int>(t13) <= 127) ? static_cast<unsigned int>(t13) : 127u));
            mExeVersionFileName.mStr[(static_cast<int>(t13) <= 127) ? static_cast<unsigned int>(t13) : 127u] = 0;
        } else {
            mExeVersionFileName.mStr[0] = 0;
        }
    }
    mRedirectPolicy = static_cast<via::module::http_patch::RedirectPolicy>(param.mRedirectPolicy);
    mExecThreadNum = param.mExecThreadNum;
    MtString::STRING* t14 = param.mSaveDirectoryName.value;
    if ((&mSaveDirectoryName.mStr[0]) != param.mSaveDirectoryName.ptr()) {
        size_t t15 = ::strlen(param.mSaveDirectoryName.ptr());
        mSaveDirectoryName.mLength = (static_cast<int>(t15) <= 127) ? static_cast<unsigned int>(t15) : 127u;
        if (((static_cast<int>(t15) <= 127) ? static_cast<unsigned int>(t15) : 127u) != 0) {
            ::memcpy(static_cast<void*>(&mSaveDirectoryName.mStr[0]), static_cast<const void*>(param.mSaveDirectoryName.ptr()), static_cast<size_t>((static_cast<int>(t15) <= 127) ? static_cast<unsigned int>(t15) : 127u));
            mSaveDirectoryName.mStr[(static_cast<int>(t15) <= 127) ? static_cast<unsigned int>(t15) : 127u] = 0;
        } else {
            mSaveDirectoryName.mStr[0] = 0;
        }
    }
    mSecurityFlags = param.mSecurityFlags;
    mAllowInsecure = param.mAllowInsecure;
}

via::module::http_patch::Result via::module::http_patch::ClientManager::request(via::module::http_patch::ParallelsListenerManager* listener_ptr, MT_CTSTR uri_path_str_ptr) {
    if (listener_ptr != nullptr) {
        setupCommon();
        listener_ptr->mPhase = ::via::module::http_patch::FileListener::Phase_Request;
        return static_cast<via::module::http_patch::Result>((::via::module::network::utility::HttpDownloadManager::instance()->request(*listener_ptr, &mAuthorityURL.mStr[0], uri_path_str_ptr, -1) != ::HttpClient::Error_None) * 5);
    } else {
        return ::via::module::http_patch::Result_ErrorRequest;
    }
}

__attribute__((weak)) void via::module::http_patch::ClientManager::setupCommon() {
    DDON_STUB("via::module::http_patch::ClientManager::setupCommon")
    /* stub */
}

via::module::http_patch::RequestParam::RequestParam() {
    DDON_STUB("via::module::http_patch::RequestParam::RequestParam")
    /* stub */
}

via::module::http_patch::RequestParam::~RequestParam() {
    DDON_STUB("via::module::http_patch::RequestParam::~RequestParam")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::RequestParam::setUriAuthorityStr(MT_CTSTR str_ptr) {
    DDON_STUB("via::module::http_patch::RequestParam::setUriAuthorityStr")
    /* stub */
}

