// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIDamage.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/nGUI.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sPlayerManager.h"
#include "../../XFramework/uCoord.h"
#include "uGUIBase.h"
#include "../../XFramework/uModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const f32 SlipValueOffsetYs[2] = {
    -0x1.ep+3f,
    0x1.68p+5f,
};

static const f32 NormalValueOffsetYs[2] = {
    -0x1.68p+5f,
    0x1.ep+3f,
};

const MtDTI& uGUIDamage::getDTI() const {
    return uGUIDamage::DTI;
}

void* uGUIDamage::operator new(size_t sz, u32 align) {
    return uGUIDamage::getAllocator()->memAlloc(sz, align, uGUIDamage::DTI.getID());
}

uGUIDamage::~uGUIDamage() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIDamage::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_DAMAGE_GUI"), 129u, 1427088956l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIDamage::setup() {
    DDON_STUB("uGUIDamage::setup")
    /* stub */
}

void uGUIDamage::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIDamage::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    for (unsigned int i0_0 = 0;;) {
        if (mInstInfos[i0_0].mEnable) {
            mInstInfos[i0_0].mPos.x = offset.x + mInstInfos[i0_0].mPos.x;
            mInstInfos[i0_0].mPos.y = offset.y + mInstInfos[i0_0].mPos.y;
            mInstInfos[i0_0].mPos.z = offset.z + mInstInfos[i0_0].mPos.z;
        }
        if (i0_0 != 31) {
            i0_0 = i0_0 + 1u;
        } else {
            break;
        }
    }
    if (mSlipInstInfos[0].mEnable) {
        mSlipInstInfos[0].mPos.x = offset.x + mSlipInstInfos[0].mPos.x;
        mSlipInstInfos[0].mPos.y = offset.y + mSlipInstInfos[0].mPos.y;
        mSlipInstInfos[0].mPos.z = offset.z + mSlipInstInfos[0].mPos.z;
    }
    if (mSlipInstInfos[1].mEnable) {
        mSlipInstInfos[1].mPos.x = offset.x + mSlipInstInfos[1].mPos.x;
        mSlipInstInfos[1].mPos.y = offset.y + mSlipInstInfos[1].mPos.y;
        mSlipInstInfos[1].mPos.z = offset.z + mSlipInstInfos[1].mPos.z;
    }
    if (mTextInstInfos[0].mEnable) {
        mTextInstInfos[0].mPos.x = offset.x + mTextInstInfos[0].mPos.x;
        mTextInstInfos[0].mPos.y = offset.y + mTextInstInfos[0].mPos.y;
        mTextInstInfos[0].mPos.z = offset.z + mTextInstInfos[0].mPos.z;
    }
    if (mTextInstInfos[1].mEnable) {
        mTextInstInfos[1].mPos.x = offset.x + mTextInstInfos[1].mPos.x;
        mTextInstInfos[1].mPos.y = offset.y + mTextInstInfos[1].mPos.y;
        mTextInstInfos[1].mPos.z = offset.z + mTextInstInfos[1].mPos.z;
    }
    if (mTextInstInfos[2].mEnable) {
        mTextInstInfos[2].mPos.x = offset.x + mTextInstInfos[2].mPos.x;
        mTextInstInfos[2].mPos.y = offset.y + mTextInstInfos[2].mPos.y;
        mTextInstInfos[2].mPos.z = offset.z + mTextInstInfos[2].mPos.z;
    }
    if (mTextInstInfos[3].mEnable) {
        mTextInstInfos[3].mPos.x = offset.x + mTextInstInfos[3].mPos.x;
        mTextInstInfos[3].mPos.y = offset.y + mTextInstInfos[3].mPos.y;
        mTextInstInfos[3].mPos.z = offset.z + mTextInstInfos[3].mPos.z;
    }
}

__attribute__((weak)) void uGUIDamage::generateInstance(u8 uType, s32 sValue, f32 fRate, u32 uFlags, const MtVector3* vPos) {
    DDON_STUB("uGUIDamage::generateInstance")
    /* stub */
}

__attribute__((weak)) bool uGUIDamage::fixCameraRelatedScreenPos() {
    DDON_STUB("uGUIDamage::fixCameraRelatedScreenPos")
    return {};
}

__attribute__((weak)) void uGUIDamage::adjustScale() {
    DDON_STUB("uGUIDamage::adjustScale")
    /* stub */
}

void uGUIDamage::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIDamage::updateWait);
}

__attribute__((weak)) void uGUIDamage::updateWait() {
    DDON_STUB("uGUIDamage::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUIDamage::prepareInstInfo(uGUIDamage::stInstInfo& instInfo) {
    DDON_STUB("uGUIDamage::prepareInstInfo")
    /* stub */
}

__attribute__((weak)) void uGUIDamage::initInstInfo(uGUIDamage::stInstInfo& instInfo, u8 uType, s32 sValue, f32 fRate, u32 uFlags) {
    DDON_STUB("uGUIDamage::initInstInfo")
    /* stub */
}

__attribute__((weak)) void uGUIDamage::reapplyInstInfo(uGUIDamage::stInstInfo& instInfo, s32 sValue) {
    DDON_STUB("uGUIDamage::reapplyInstInfo")
    /* stub */
}

__attribute__((weak)) MtColor uGUIDamage::getFontColor(u8 uType, u16 uFlags, s32 sValue) const {
    DDON_STUB("uGUIDamage::getFontColor")
    __builtin_unreachable();
}

__attribute__((weak)) void uGUIDamage::pushTextCoreInfo(u8 uType, s32 sValue, f32 fRate, u32 uFlags) {
    DDON_STUB("uGUIDamage::pushTextCoreInfo")
    /* stub */
}

__attribute__((weak)) void uGUIDamage::updateTextInstInfo(f32 deltaTime) {
    DDON_STUB("uGUIDamage::updateTextInstInfo")
    /* stub */
}

inline uGUIDamage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIDamage::MyDTI uGUIDamage::DTI("uGUIDamage", &::uGUIBase::DTI, 12560ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIDamage::MyDTI::newInstance() const {
    DDON_STUB("uGUIDamage::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void uGUIDamage::stInstInfo::updatePos() {
    DDON_STUB("uGUIDamage::stInstInfo::updatePos")
    /* stub */
}

__attribute__((weak)) void uGUIDamage::stInstInfo::updateValue() {
    DDON_STUB("uGUIDamage::stInstInfo::updateValue")
    /* stub */
}

__attribute__((weak)) void uGUIDamage::stInstInfo::update(uGUIDamage& guiDamage, f32 dispTime, f32 fadeInTime, f32 fadeOutTime, f32 deltaTime) {
    DDON_STUB("uGUIDamage::stInstInfo::update")
    /* stub */
}

__attribute__((weak)) void uGUIDamage::stInstInfo::updateFadeOut(uGUIDamage& guiDamage, f32 fadeInTime, f32 dispTime, f32 fadeOutTime, f32 deltaTime) {
    DDON_STUB("uGUIDamage::stInstInfo::updateFadeOut")
    /* stub */
}

