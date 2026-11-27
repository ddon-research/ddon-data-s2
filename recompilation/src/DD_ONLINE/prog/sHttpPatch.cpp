// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sHttpPatch.h"
#include "HttpPatchDL/modules/httpPatch/HttpPatchManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollisionUtil.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cSystem.h"
#include "HttpPatchDL/modules/httpPatch/httpPatch.h"
#include "HttpPatchDL/modules/httpPatch/httpPatchClient.h"
#include "HttpPatchDL/modules/httpPatch/httpPatchEntry.h"
#include "HttpPatchDL/modules/httpPatch/httpPatchResultCtrl.h"
#include "sDDOMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sHttpPatch::getDTI() const {
    return sHttpPatch::DTI;
}

void* sHttpPatch::operator new(size_t sz, u32 align) {
    return sHttpPatch::getAllocator()->memAlloc(sz, align, sHttpPatch::DTI.getID());
}

sHttpPatch::sHttpPatch() {
    DDON_STUB("sHttpPatch::sHttpPatch")
    /* stub */
}

__attribute__((noinline)) sHttpPatch::~sHttpPatch() {
    DDON_STUB("sHttpPatch::~sHttpPatch")
    /* stub */
}

void sHttpPatch::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

MtUI* sHttpPatch::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sHttpPatch::clearResult() {
    if (_ExeVersionResultCtrl != nullptr) {
        delete _ExeVersionResultCtrl;
    }
    if (_VersionResultCtrl != nullptr) {
        delete _VersionResultCtrl;
    }
    _VersionResultCtrl = nullptr;
    _ExeVersionResultCtrl = nullptr;
    mpHPManager->setupResultPtr(static_cast<via::module::http_patch::ResultBase*>(nullptr));
}

__attribute__((weak)) bool sHttpPatch::checkSetupEnable() {
    DDON_STUB("sHttpPatch::checkSetupEnable")
    return {};
}

void sHttpPatch::move() {
    if (!checkSetupEnable()) {
        return;
    }
    mpHPModule->update();
    moveExeVerCheck();
    moveNormalVerCheck();
}

void sHttpPatch::abortUpdate() {
    if (mExeVerCheckRno != 2) {
        if (mNormalVerCheckRno == 2) {
            if (mpHPManager != nullptr) {
                mpHPManager->abort();
                mIsAbort = true;
            }
        }
    } else {
        if (mpHPManager != nullptr) {
            mpHPManager->abort();
            mIsAbort = true;
        }
    }
}

__attribute__((weak)) void sHttpPatch::registDLServer() {
    DDON_STUB("sHttpPatch::registDLServer")
    /* stub */
}

void sHttpPatch::reqExeVerCheck() {
    mErrorCode = 0;
    mIsError = false;
    mIsAbort = false;
    registDLServer();
    mExeVerCheckRno = 0;
}

__attribute__((weak)) void sHttpPatch::moveExeVerCheck() {
    DDON_STUB("sHttpPatch::moveExeVerCheck")
    /* stub */
}

bool sHttpPatch::isUpdateExeLauncher() {
    if (_ExeVersionResultCtrl != nullptr) {
        return !_ExeVersionResultCtrl->isMatchLauncher();
    } else {
        return false;
    }
}

bool sHttpPatch::isUpdateExeGameApp() {
    if (_ExeVersionResultCtrl != nullptr) {
        return !_ExeVersionResultCtrl->isMatchGameApp();
    } else {
        return false;
    }
}

void sHttpPatch::reqNormalVerCheck() {
    mErrorCode = 0;
    mIsError = false;
    mNormalVerCheckRno = 0;
}

__attribute__((weak)) void sHttpPatch::moveNormalVerCheck() {
    DDON_STUB("sHttpPatch::moveNormalVerCheck")
    /* stub */
}

bool sHttpPatch::isUpdate() {
    if (_VersionResultCtrl != nullptr) {
        return _VersionResultCtrl->isUpdate();
    } else {
        return false;
    }
}

inline sHttpPatch::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sHttpPatch::MyDTI sHttpPatch::DTI("sHttpPatch", &::cSystem::DTI, 168ul, 0u, 0u);

sHttpPatch* sHttpPatch::mpInstance;

__attribute__((weak)) MtObject* sHttpPatch::MyDTI::newInstance() const {
    DDON_STUB("sHttpPatch::MyDTI::newInstance")
    return nullptr;
}

