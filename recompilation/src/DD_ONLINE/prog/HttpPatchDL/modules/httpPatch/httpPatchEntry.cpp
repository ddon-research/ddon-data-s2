// Reconstructed from the game's DWARF debug information.
#include <new>
#include "httpPatchEntry.h"
#include "HttpPatchManager.h"
#include "../../../../../MT/MtNetObject.h"
#include "../network/networkHttpDownloadManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) via::module::ModuleError_Type via::HttpPatchModule::initialize() {
    DDON_STUB("via::HttpPatchModule::initialize")
    return {};
}

via::module::ModuleError_Type via::HttpPatchModule::terminate() {
    if ((::via::module::network::utility::HttpDownloadManager::mpInstance) != nullptr) {
        delete (::via::module::network::utility::HttpDownloadManager::mpInstance);
        ::via::module::network::utility::HttpDownloadManager::mpInstance = nullptr;
    }
    if ((::via::module::http_patch::HttpPatchManager::mpInstance) != nullptr) {
        (::via::module::http_patch::HttpPatchManager::mpInstance)->::via::module::http_patch::HttpPatchManager::finalize();
        if ((::via::module::http_patch::HttpPatchManager::mpInstance) != nullptr) {
            delete (::via::module::http_patch::HttpPatchManager::mpInstance);
            ::via::module::http_patch::HttpPatchManager::mpInstance = nullptr;
        }
    }
    return ::via::module::ModuleError_None;
}

void via::HttpPatchModule::update() {
    ::via::module::http_patch::HttpPatchManager::instance()->update();
    ::via::module::network::utility::HttpDownloadManager::instance()->update();
}

