// Reconstructed from the game's DWARF debug information.
#include <new>
#include "HttpPatchManager.h"
#include "../../../../../MT/MtAllocator.h"
#include "../../../../../MT/MtCollisionUtil.h"
#include "../../../../../MT/MtFile.h"
#include "../../../../../MT/MtMemoryAllocator.h"
#include "../../../../../MT/MtNetObject.h"
#include "../../../../../MT/MtPerformance.h"
#include "../../../../../MT/MtStream.h"
#include "../../../../../MT/MtString.h"
#include "../../../../../MT/MtSynchronize.h"
#include "../../../../../MT/MtThread.h"
#include "../../../../../generated/shared/directory.h"
#include "httpPatch.h"
#include "httpPatchClient.h"
#include "httpPatchFileCtrl.h"
#include "httpPatchListener.h"
#include "httpPatchResultCtrl.h"
#include "httpPatchTypes.h"
#include "../network/networkHttpDownloadManager.h"
#include "../../xvia/path.h"
#include "utility/requestQueue.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MT_CTSTR HDDVersionFilePath = "versionlist";

__attribute__((weak)) bool via::module::http_patch::HttpPatchManager::abort() {
    DDON_STUB("via::module::http_patch::HttpPatchManager::abort")
    return {};
}

__attribute__((weak)) via::module::http_patch::RequestParam* via::module::http_patch::HttpPatchManager::createRequestParam() {
    DDON_STUB("via::module::http_patch::HttpPatchManager::createRequestParam")
    return nullptr;
}

void via::module::http_patch::HttpPatchManager::deleteRequestParam(via::module::http_patch::RequestParam* result) {
    mResultPtr = nullptr;
    if (result == nullptr) {
        return;
    }
    delete result;
}

const MtString& via::module::http_patch::HttpPatchManager::getTempDirectory() {
    return ::via::module::http_patch::HttpPatchManager::instance()->mTempDirectory;
}

const MtString& via::module::http_patch::HttpPatchManager::getDownloadDirectory() {
    return ::via::module::http_patch::HttpPatchManager::instance()->mDownloadDirectory;
}

__attribute__((weak)) void via::module::http_patch::HttpPatchManager::update() {
}

__attribute__((weak)) void via::module::http_patch::HttpPatchManager::addFailedFileInfo(const via::module::http_patch::ParallelsFileData& info) {
    DDON_STUB("via::module::http_patch::HttpPatchManager::addFailedFileInfo")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::HttpPatchManager::setDebugDraw(bool enable) {
}

__attribute__((noinline)) via::module::http_patch::HttpPatchManager::~HttpPatchManager() {
    DDON_STUB("via::module::http_patch::HttpPatchManager::~HttpPatchManager")
    /* stub */
}

void via::module::http_patch::HttpPatchManager::finalize() {
    mhDownloadRequest.exit();
}

void via::module::http_patch::HttpPatchManager::requestPopEvent(via::module::http_patch::HttpPatchManager::RequestProcParam& info) {
    info.result_ptr->mPhase = ::via::module::http_patch::Phase_PopRequest;
}

void via::module::http_patch::HttpPatchManager::requestPushEvent(via::module::http_patch::HttpPatchManager::RequestProcParam& info) {
    info.result_ptr->mPhase = ::via::module::http_patch::Phase_PushRequest;
}

__attribute__((weak)) void via::module::http_patch::HttpPatchManager::updateProc(void* param, via::module::http_patch::HttpPatchManager::RequestProcParam& info) {
    DDON_STUB("via::module::http_patch::HttpPatchManager::updateProc")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::HttpPatchManager::setupRequest(const via::module::http_patch::HttpPatchManager::RequestProcParam& info) {
    DDON_STUB("via::module::http_patch::HttpPatchManager::setupRequest")
    /* stub */
}

__attribute__((weak)) u32 via::module::http_patch::HttpPatchManager::loadNormalVersionFile() {
    DDON_STUB("via::module::http_patch::HttpPatchManager::loadNormalVersionFile")
    return {};
}

__attribute__((weak)) via::module::http_patch::ExeVersionResult* via::module::http_patch::HttpPatchManager::exeVersionCheck(const via::module::http_patch::RequestParam* param_ptr, const u32 version_launcher, const u32 version_gameapp) {
    DDON_STUB("via::module::http_patch::HttpPatchManager::exeVersionCheck")
    return nullptr;
}

__attribute__((weak)) via::module::http_patch::Result via::module::http_patch::HttpPatchManager::exeVersionCheck(const via::module::http_patch::HttpPatchManager::RequestProcParam& info) {
    DDON_STUB("via::module::http_patch::HttpPatchManager::exeVersionCheck")
    return {};
}

__attribute__((weak)) via::module::http_patch::Result via::module::http_patch::HttpPatchManager::exeVersionCheck(MT_CTSTR versionlist_name, u32& version_launcher, u32& version_gameapp, via::module::http_patch::exefileinfo_array_t& exefileinfo) {
    DDON_STUB("via::module::http_patch::HttpPatchManager::exeVersionCheck")
    return {};
}

__attribute__((weak)) via::module::http_patch::VersionResult* via::module::http_patch::HttpPatchManager::nomalVersionCheck(const via::module::http_patch::RequestParam* param_ptr) {
    DDON_STUB("via::module::http_patch::HttpPatchManager::nomalVersionCheck")
    return nullptr;
}

__attribute__((weak)) via::module::http_patch::Result via::module::http_patch::HttpPatchManager::normalCheck(const via::module::http_patch::HttpPatchManager::RequestProcParam& info) {
    DDON_STUB("via::module::http_patch::HttpPatchManager::normalCheck")
    return {};
}

__attribute__((weak)) via::module::http_patch::Result via::module::http_patch::HttpPatchManager::normalCheck(MT_CTSTR versionlist_name, s32& app_version, via::module::http_patch::versioninfo_array_t& version_list) {
    DDON_STUB("via::module::http_patch::HttpPatchManager::normalCheck")
    return {};
}

void via::module::http_patch::HttpPatchManager::setResultDetail(HPDErrCategory ecType, s32 errCode) {
    if (mResultPtr == nullptr) {
        return;
    }
    mResultPtr->mEcType = ecType;
    mResultPtr->mErCode = errCode;
}

void via::module::http_patch::HttpPatchManager::setErrFilePath(MT_CHAR* fn) {
    if (mResultPtr == nullptr) {
        return;
    }
    mResultPtr->setErrFilePath(fn);
}

void via::module::http_patch::HttpPatchManager::setDLFilePath(MT_CHAR* fn) {
    if (mResultPtr == nullptr) {
        return;
    }
    mResultPtr->setDLFilePath(fn);
}

void via::module::http_patch::HttpPatchManager::setInsFilePath(MT_CHAR* fn) {
    if (mResultPtr == nullptr) {
        return;
    }
    mResultPtr->setInsFilePath(fn);
}

void via::module::http_patch::HttpPatchManager::setProgressDL1File(f32 per) {
    if (mResultPtr == nullptr) {
        return;
    }
    mResultPtr->mPerDL1File = per;
}

void via::module::http_patch::HttpPatchManager::setProgressFarExtract(f32 per) {
    if (mResultPtr == nullptr) {
        return;
    }
    mResultPtr->mPerFarExtract = per;
}

f32 via::module::http_patch::HttpPatchManager::getDLSpeedMbps(f32 spdLimit) {
    if (mResultPtr != nullptr) {
        return mResultPtr->getDLSpeedMbps();
    } else {
        return spdLimit;
    }
}

void via::module::http_patch::HttpPatchManager::getDLRetryParams(HTTPDL_RETRY_PARAMS* buff) {
    if (mResultPtr != nullptr) {
        mResultPtr->getDLRetryParams(buff);
    } else {
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(buff) + 0) = 0x25800000000;
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(buff) + 8) = 0x4019999A;
    }
}

void via::module::http_patch::HttpPatchManager::getDLRetryStatus(HTTPDL_RETRY_STATUS* buff) {
    if (mResultPtr == nullptr) {
        return;
    }
    mResultPtr->getDLRetryStatus(buff);
}

void via::module::http_patch::HttpPatchManager::storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff) {
    if (mResultPtr == nullptr) {
        return;
    }
    mResultPtr->storeDLRetryStatus(buff);
}

void via::module::http_patch::HttpPatchManager::setupResultPtr(via::module::http_patch::ResultBase* ptr) {
    mResultPtr = ptr;
}

via::module::http_patch::HttpPatchManager* via::module::http_patch::HttpPatchManager::mpInstance;

