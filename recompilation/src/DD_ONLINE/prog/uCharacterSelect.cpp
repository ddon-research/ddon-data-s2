// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCharacterSelect.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cCharacterData.h"
#include "cEquipData.h"
#include "../../XFramework/cResource.h"
#include "cStageEpvCtrl.h"
#include "../../XFramework/cUnit.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "rCharacterEditCameraParam.h"
#include "../../XFramework/rMotionList.h"
#include "sArchiveManager.h"
#include "sFlag.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "uCharacterEdit.h"
#include "uGUICharacterSelect.h"
#include "uMockUpModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCharacterSelect::getDTI() const {
    return uCharacterSelect::DTI;
}

void* uCharacterSelect::operator new(size_t sz, u32 align) {
    return uCharacterSelect::getAllocator()->memAlloc(sz, align, uCharacterSelect::DTI.getID());
}

uCharacterSelect::uCharacterSelect() : mMotionWaits() {
    mSelectIndex = 0xFFFFFFFF;
    mCharaNumOld = 0;
    mpCharaNum = nullptr;
    mppCharData = nullptr;
    mpGUI = nullptr;
    mLoadingTimer = sMain::getInstance()->getFps();
}

uCharacterSelect::~uCharacterSelect() {
    DDON_STUB("uCharacterSelect::~uCharacterSelect")
    /* stub */
}

void uCharacterSelect::setup() {
    this->uCharacterEditBase::setup();
    sGame::getInstance()->fadeOut(0.0f, 0u);
}

void uCharacterSelect::move() {
    this->uCharacterEditBase::move();
}

void uCharacterSelect::kill() {
    this->uCharacterEditBase::kill();
}

void uCharacterSelect::updatePtr() {
    this->uCharacterEditBase::updatePtr();
    if (mpGUI == nullptr) {
        return;
    }
    if (mpGUI->isEnable()) {
        return;
    }
    mpGUI = nullptr;
}

__attribute__((weak)) void uCharacterSelect::release() {
    DDON_STUB("uCharacterSelect::release")
    /* stub */
}

bool uCharacterSelect::moveLoadArc() {
    bool t0 = this->uCharacterEditBase::moveLoadArc();
    mLoadingTimer = mLoadingTimer - sMain::getInstance()->mDeltaTime;
    if (0.0f > mLoadingTimer) {
        sFlag::getInstance()->setFlag(6u, 12u, true, true, false);
    }
    return t0;
}

__attribute__((weak)) void uCharacterSelect::moveLoadUnit() {
    DDON_STUB("uCharacterSelect::moveLoadUnit")
    /* stub */
}

__attribute__((weak)) void uCharacterSelect::moveMain() {
    DDON_STUB("uCharacterSelect::moveMain")
    /* stub */
}

void uCharacterSelect::wakeup() {
    uGUICharacterSelect* t0 = mpGUI;
    if (t0 == nullptr) {
        return;
    }
    t0->mppCharacterData = mppCharData;
    t0->mpCharacterDataNum = mpCharaNum;
    t0->mIsWakeup = true;
    t0->wakeup();
}

void uCharacterSelect::updateModel() {
    if (mpModel == nullptr) {
        return;
    }
    if (mpGUI == nullptr) {
        return;
    }
    if (!mpGUI->isSafeCharacterData()) {
        return;
    }
    mpModel->setupEdit(&(*mppCharData)[mSelectIndex].mCharData.mCharacterEdit);
    if (mpModel != nullptr) {
        mpModel->updateBody(true);
        sArchiveManager* t0 = sArchiveManager::getInstance();
        ARC_TAGID t1 = rArchiveListArray::convTagId("character_edit_select");
        cResource* pRes = t0->createRes(t1, rArchiveListArray::convSearchId("RES_ID_CHARACTER_EDIT_LMT"), 1u, false);
        if (pRes != nullptr) {
            mpModel->setMotionList(static_cast<rMotionList*>(pRes), 0u);
            pRes->release();
        }
        setAction(static_cast<u32>(!isMale() * 5), true);
    } else {
        setAction(static_cast<u32>(!isMale() * 5), true);
    }
    mIsComplete = false;
}

void uCharacterSelect::setIsWakeup(bool flg) {
    if (mpGUI == nullptr) {
        return;
    }
    mpGUI->mIsWakeup = flg;
}

uCharacterEditCameraBase* uCharacterSelect::createCamera() {
    return new (16u) uCharacterSelectCamera;
}

inline uCharacterSelect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCharacterSelect::MyDTI uCharacterSelect::DTI("uCharacterSelect", &::uCharacterEditBase::DTI, 5392ul, 0u, 0u);

MtObject* uCharacterSelect::MyDTI::newInstance() const {
    return new (16u) uCharacterSelect;
}

const MtDTI& uCharacterSelectCamera::getDTI() const {
    return uCharacterSelectCamera::DTI;
}

uCharacterSelectCamera::~uCharacterSelectCamera() {
}

void uCharacterSelectCamera::updateCameraParam() {
    cCharacterEditCameraParam* t0 = getCameraParam("charaSelect");
    mpNowCameraParam = t0;
    if (mpOldCameraParam == mpNowCameraParam) {
        return;
    }
    if ((mpOldCameraParam = mpNowCameraParam) == nullptr) {
        return;
    }
    mLength = t0->mDefaultLength;
}

inline uCharacterSelectCamera::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCharacterSelectCamera::MyDTI uCharacterSelectCamera::DTI("uCharacterSelectCamera", &::uCharacterEditCameraBase::DTI, 768ul, 0u, 0u);

MtObject* uCharacterSelectCamera::MyDTI::newInstance() const {
    return new (16u) uCharacterSelectCamera;
}

