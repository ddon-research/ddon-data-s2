// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sPadExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "sInputManager.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sPad.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sPadExt::getDTI() const {
    return sPadExt::DTI;
}

void* sPadExt::operator new(size_t sz, u32 align) {
    return sPadExt::getAllocator()->memAlloc(sz, align, sPadExt::DTI.getID());
}

sPadExt::~sPadExt() {
    DDON_STUB("sPadExt::~sPadExt")
    /* stub */
}

__attribute__((weak)) void sPadExt::move() {
    DDON_STUB("sPadExt::move")
    /* stub */
}

__attribute__((weak)) void sPadExt::reset() {
}

void sPadExt::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "GamePadId", reinterpret_cast<MT_MFUNC>(&::sPadExt::getGamePadId), reinterpret_cast<MT_MFUNC>(&::sPadExt::setGamePad), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mIsIgnore", &mIsIgnore, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIgnoreTimer", &mIgnoreTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDeltaTime", &mDeltaTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPadInfo", static_cast<MtObject*>(&mPadInfo[0]), 32u, 1u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsEnableReplaceDC", &mIsEnableReplaceDC, 0u, 0u);
    this->sPad::createProperty(s);
}

void sPadExt::initRepeat() {
    mSysRepeadStDefault = static_cast<unsigned int>(static_cast<long>(12000.0f / sMain::getInstance()->getFps()));
    mSysRepeadNxDefault = static_cast<unsigned int>(static_cast<long>(3000.0f / sMain::getInstance()->getFps()));
    setRepeat(0u, static_cast<unsigned int>(static_cast<long>(12000.0f / sMain::getInstance()->getFps())), static_cast<unsigned int>(static_cast<long>(3000.0f / sMain::getInstance()->getFps())));
    setRepeat(1u, mSysRepeadStDefault, mSysRepeadNxDefault);
    setRepeat(2u, mSysRepeadStDefault, mSysRepeadNxDefault);
    setRepeat(3u, mSysRepeadStDefault, mSysRepeadNxDefault);
}

void sPadExt::setGamePad(u32 id) {
    mPadInfo[0].mPadId = id;
    mPadInfo[0].mIsEnable = false;
    mGamePadId = static_cast<s32>(id);
}

__attribute__((weak)) void sPadExt::setVibrationEnable(bool flag) {
    DDON_STUB("sPadExt::setVibrationEnable")
    /* stub */
}

u32 sPadExt::getDecideButton() const {
    if (mIsEnableReplaceDC) {
        return mCancelButton;
    } else {
        return mDecideButton;
    }
}

u32 sPadExt::getCancelButton() const {
    if (mIsEnableReplaceDC) {
        return mDecideButton;
    } else {
        return mCancelButton;
    }
}

static auto ddon_emit_0x01ac8a20 __attribute__((used)) = &sPadExt::getGamePadId;

__attribute__((weak)) bool sPadExt::isTrgCheck(sPadExt::PAD_BTN_TYPE button, u32 pad_id) {
    DDON_STUB("sPadExt::isTrgCheck")
    return {};
}

__attribute__((weak)) bool sPadExt::isOnCheck(sPadExt::PAD_BTN_TYPE button, u32 pad_id) {
    DDON_STUB("sPadExt::isOnCheck")
    return {};
}

void sPadExt::clearInputData() {
    mPad[0].initData();
    mPad[0].initVib();
    mPad[1].initData();
    mPad[1].initVib();
    mPad[2].initData();
    mPad[2].initVib();
    mPad[3].initData();
    mPad[3].initVib();
    mPadInfo[0].mRepTimer = 0.0f;
    mPadInfo[0].mAclTimer = 0.0f;
    mPadInfo[0].mBtn.acl = 0;
    mPadInfo[0].mBtn.rel = 0;
    mPadInfo[0].mBtn.rep = 0;
    mPadInfo[0].mBtn.on = 0;
    mPadInfo[0].mBtn.trg = 0;
    mPadInfo[0].mSensor.z = 0.0f;
    mPadInfo[0].mSensor.g = 0.0f;
    mPadInfo[0].mSensor.x = 0.0f;
    mPadInfo[0].mSensor.y = 0.0f;
    mPadInfo[0].mPress.L3 = 0.0f;
    mPadInfo[0].mPress.R3 = 0.0f;
    mPadInfo[0].mPress.R2 = 0.0f;
    mPadInfo[0].mPress.Select = 0.0f;
    mPadInfo[0].mPress.L2 = 0.0f;
    mPadInfo[0].mPress.R1 = 0.0f;
    mPadInfo[0].mPress.Rleft = 0.0f;
    mPadInfo[0].mPress.L1 = 0.0f;
    mPadInfo[0].mPress.Rright = 0.0f;
    mPadInfo[0].mPress.Rdown = 0.0f;
    mPadInfo[0].mPress.Lleft = 0.0f;
    mPadInfo[0].mPress.Rup = 0.0f;
    mPadInfo[0].mPress.Lright = 0.0f;
    mPadInfo[0].mPress.Ldown = 0.0f;
    mPadInfo[0].mAnlg[1].y = 0.0f;
    mPadInfo[0].mPress.Lup = 0.0f;
    mPadInfo[0].mAnlg[0].y = 0.0f;
    mPadInfo[0].mAnlg[1].x = 0.0f;
    mPadInfo[0].mBtnUDRL.acl = 0;
    mPadInfo[0].mAnlg[0].x = 0.0f;
    mPadInfo[0].mBtnUDRL.rel = 0;
    mPadInfo[0].mBtnUDRL.rep = 0;
    mPadInfo[0].mBtnUDRL.on = 0;
    mPadInfo[0].mBtnUDRL.trg = 0;
}

void sPadExt::onAutoRunButtonHold() {
    if (sInputManager::getInstance()->getInputMode() != 0) {
        return;
    }
    mIsAutoRunButtonHold = true;
}

inline sPadExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sPadExt::MyDTI sPadExt::DTI("sPadExt", &::sPad::DTI, 5632ul, 0u, 0u);

__attribute__((weak)) MtObject* sPadExt::MyDTI::newInstance() const {
    DDON_STUB("sPadExt::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sPadExt::cPadInfo::getDTI() const {
    return sPadExt::cPadInfo::DTI;
}

sPadExt::cPadInfo::cPadInfo() {
    DDON_STUB("sPadExt::cPadInfo::cPadInfo")
    /* stub */
}

sPadExt::cPadInfo::~cPadInfo() {
}

void sPadExt::cPadInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPadId", &mPadId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPadEnableId", &mPadEnableId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsEnable", &mIsEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsVibEnable", &mIsVibEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRepTimer", &mRepTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAclTimer", &mAclTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtn.on", &mBtn.on, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtn.trg", &mBtn.trg, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtn.rel", &mBtn.rel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtn.rep", &mBtn.rep, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtn.acl", &mBtn.acl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtnUDRL.on", &mBtnUDRL.on, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtnUDRL.trg", &mBtnUDRL.trg, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtnUDRL.rel", &mBtnUDRL.rel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtnUDRL.rep", &mBtnUDRL.rep, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBtnUDRL.acl", &mBtnUDRL.acl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAnlg[LEFT].x", &mAnlg[0].x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAnlg[LEFT].y", &mAnlg[0].y, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAnlg[RIGHT].x", &mAnlg[1].x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAnlg[RIGHT].y", &mAnlg[1].y, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.Lup", &mPress.Lup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.Lright", &mPress.Lright, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.Ldown", &mPress.Ldown, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.Lleft", &mPress.Lleft, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.Rup", &mPress.Rup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.Rright", &mPress.Rright, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.Rdown", &mPress.Rdown, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.Rleft", &mPress.Rleft, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.L1", &mPress.L1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.L2", &mPress.L2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.R1", &mPress.R1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.R2", &mPress.R2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.Select", &mPress.Select, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.L3", &mPress.L3, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPress.R3", &mPress.R3, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSensor.x", &mSensor.x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSensor.y", &mSensor.y, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSensor.z", &mSensor.z, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSensor.g", &mSensor.g, 0u, 0u);
}

void sPadExt::cPadInfo::clear(bool flag) {
    if (!flag) {
        mPadEnableId = 0xFFFF;
    }
    mRepTimer = 0.0f;
    mAclTimer = 0.0f;
    mBtn.acl = 0;
    mBtn.rel = 0;
    mBtn.rep = 0;
    mBtn.on = 0;
    mBtn.trg = 0;
    mSensor.z = 0.0f;
    mSensor.g = 0.0f;
    mSensor.x = 0.0f;
    mSensor.y = 0.0f;
    mPress.L3 = 0.0f;
    mPress.R3 = 0.0f;
    mPress.R2 = 0.0f;
    mPress.Select = 0.0f;
    mPress.L2 = 0.0f;
    mPress.R1 = 0.0f;
    mPress.Rleft = 0.0f;
    mPress.L1 = 0.0f;
    mPress.Rright = 0.0f;
    mPress.Rdown = 0.0f;
    mPress.Lleft = 0.0f;
    mPress.Rup = 0.0f;
    mPress.Lright = 0.0f;
    mPress.Ldown = 0.0f;
    mAnlg[1].y = 0.0f;
    mPress.Lup = 0.0f;
    mAnlg[0].y = 0.0f;
    mAnlg[1].x = 0.0f;
    mBtnUDRL.acl = 0;
    mAnlg[0].x = 0.0f;
    mBtnUDRL.rel = 0;
    mBtnUDRL.rep = 0;
    mBtnUDRL.on = 0;
    mBtnUDRL.trg = 0;
}

__attribute__((weak)) void sPadExt::cPadInfo::update() {
    DDON_STUB("sPadExt::cPadInfo::update")
    /* stub */
}

__attribute__((weak)) void sPadExt::cPadInfo::stopVibration() {
    DDON_STUB("sPadExt::cPadInfo::stopVibration")
    /* stub */
}

u32 sPadExt::cPadInfo::getPadSetting(sPadExt::PAD_BTN_TYPE button) {
    if (button <= 56) {
        return mPadSetting[button];
    } else {
        return 63;
    }
}

u32 sPadExt::cPadInfo::getBtnInfoOn() const {
    if (!sInputManager::getInstance()->isDisableInputGame()) {
        return mBtn.on;
    } else {
        return 0;
    }
}

u32 sPadExt::cPadInfo::getBtnInfoTrg() const {
    if (!sInputManager::getInstance()->isDisableInputGame()) {
        return mBtn.trg;
    } else {
        return 0;
    }
}

f32 sPadExt::cPadInfo::getAnlgInfoLx() const {
    if (!sInputManager::getInstance()->isDisableInputGame()) {
        return mAnlg[0].x;
    } else {
        return 0.0f;
    }
}

f32 sPadExt::cPadInfo::getAnlgInfoLy() const {
    if (!sInputManager::getInstance()->isDisableInputGame()) {
        return mAnlg[0].y;
    } else {
        return 0.0f;
    }
}

f32 sPadExt::cPadInfo::getAnlgInfoRx() const {
    if (!sInputManager::getInstance()->isDisableInputGame()) {
        return mAnlg[1].x;
    } else {
        return 0.0f;
    }
}

f32 sPadExt::cPadInfo::getAnlgInfoRy() const {
    if (!sInputManager::getInstance()->isDisableInputGame()) {
        return mAnlg[1].y;
    } else {
        return 0.0f;
    }
}

inline sPadExt::cPadInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sPadExt::cPadInfo::MyDTI sPadExt::cPadInfo::DTI("sPadExt::cPadInfo", &::MtObject::DTI, 776ul, 0u, 0u);

__attribute__((weak)) MtObject* sPadExt::cPadInfo::MyDTI::newInstance() const {
    DDON_STUB("sPadExt::cPadInfo::MyDTI::newInstance")
    return nullptr;
}

