// Reconstructed from the game's DWARF debug information.
#include <new>
#include "httpPatchResultCtrl.h"
#include "../../../../../MT/MtCollisionUtil.h"
#include "../../../../../MT/MtPerformance.h"
#include "httpPatch.h"
#include "httpPatchTypes.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

via::module::http_patch::ExeVersionResult::~ExeVersionResult() {
    DDON_STUB("via::module::http_patch::ExeVersionResult::~ExeVersionResult")
    /* stub */
}

f64 via::module::http_patch::ExeVersionResult::getProgress() const {
    return 0.0;
}

bool via::module::http_patch::ExeVersionResult::isMatchLauncher() const {
    return getServerVersionLauncher() == mDefineVersionLauncher;
}

bool via::module::http_patch::ExeVersionResult::isMatchGameApp() const {
    return getServerVersionGameApp() == mDefineVersionGameApp;
}

__attribute__((weak)) void via::module::http_patch::ResultBase::setDLRetryParams(HTTPDL_RETRY_PARAMS* buff) {
    DDON_STUB("via::module::http_patch::ResultBase::setDLRetryParams")
    /* stub */
}

void via::module::http_patch::ResultBase::getDLRetryParams(HTTPDL_RETRY_PARAMS* buff) {
    unsigned long t0 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 40);
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(buff) + 8) = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 48);
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(buff) + 0) = t0;
}

__attribute__((weak)) void via::module::http_patch::ResultBase::storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff) {
    DDON_STUB("via::module::http_patch::ResultBase::storeDLRetryStatus")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::ResultBase::getDLRetryStatus(HTTPDL_RETRY_STATUS* buff) {
    DDON_STUB("via::module::http_patch::ResultBase::getDLRetryStatus")
    /* stub */
}

f32 via::module::http_patch::ResultBase::getDLSpeedMbps() {
    return mDLSpeedUR;
}

__attribute__((weak)) void via::module::http_patch::ResultBase::setDLFilePath(MT_CHAR* fn) {
    DDON_STUB("via::module::http_patch::ResultBase::setDLFilePath")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::ResultBase::setInsFilePath(MT_CHAR* fn) {
    DDON_STUB("via::module::http_patch::ResultBase::setInsFilePath")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::ResultBase::setErrFilePath(MT_CHAR* fn) {
    DDON_STUB("via::module::http_patch::ResultBase::setErrFilePath")
    /* stub */
}

via::module::http_patch::VersionResult::~VersionResult() {
    DDON_STUB("via::module::http_patch::VersionResult::~VersionResult")
    /* stub */
}

__attribute__((weak)) bool via::module::http_patch::VersionResult::isUpdate() const {
    DDON_STUB("via::module::http_patch::VersionResult::isUpdate")
    return {};
}

__attribute__((weak)) f64 via::module::http_patch::VersionResult::getProgress() const {
    DDON_STUB("via::module::http_patch::VersionResult::getProgress")
    return {};
}

u64 via::module::http_patch::VersionResult::getCheckLength() const {
    return mCheckLength;
}

u64 via::module::http_patch::VersionResult::getCheckCount() const {
    return mCheckCount;
}

