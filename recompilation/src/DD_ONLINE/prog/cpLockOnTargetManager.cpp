// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpLockOnTargetManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "cGeneralPointPtr.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "cpLockOn.h"
#include "../../generated/shared/nDDOGame.h"
#include "../../generated/shared/nDDOModel.h"
#include "nDDOUtility.h"
#include "../../generated/shared/nGUIAim.h"
#include "../../XFramework/rSoundRequest.h"
#include "sArchiveManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void elf_v_Z29GUIAIM_TARGET_MARKER_SAFE_ENDRj(unsigned int&) __asm__("_Z29GUIAIM_TARGET_MARKER_SAFE_ENDRj");

const MtDTI& cpLockOnTargetManager::getDTI() const {
    return cpLockOnTargetManager::DTI;
}

void* cpLockOnTargetManager::operator new(size_t sz, u32 align) {
    return cpLockOnTargetManager::getAllocator()->memAlloc(sz, align, cpLockOnTargetManager::DTI.getID());
}

cpLockOnTargetManager::cpLockOnTargetManager() {
    DDON_STUB("cpLockOnTargetManager::cpLockOnTargetManager")
    /* stub */
}

cpLockOnTargetManager::~cpLockOnTargetManager() {
    if (mprSE == nullptr) {
        return;
    }
    mprSE->release();
    mprSE = nullptr;
}

void cpLockOnTargetManager::init(u32 maxLockOnNum, bool isSameMulti, nGUIAim::TARGET_MARKER_TYPE targetMarkerType, nDDOModel::LOCKON_TARGET_TYPE lockOnTargetType) {
    mMaxNum = maxLockOnNum;
    mNextIndex = 0;
    mTargetMarkerIdNow = 0xFFFFFFFF;
    mTargetMarkerIds.elems[6] = 0xFFFFFFFF;
    mTargetMarkerIds.elems[7] = 0xFFFFFFFF;
    mTargetMarkerIds.elems[4] = 0xFFFFFFFF;
    mTargetMarkerIds.elems[5] = 0xFFFFFFFF;
    mTargetMarkerIds.elems[2] = 0xFFFFFFFF;
    mTargetMarkerIds.elems[3] = 0xFFFFFFFF;
    mTargetMarkerIds.elems[0] = 0xFFFFFFFF;
    mTargetMarkerIds.elems[1] = 0xFFFFFFFF;
    mpLockOnLast = nullptr;
    mTargetMarkerType = targetMarkerType;
    mLockOnType = lockOnTargetType;
    mIsInit = true;
    mIsSameMulti = isSameMulti;
    mEffectiveDist = 3000.0f;
    mMaterialFlag = 0xFFFFFFFF;
}

void cpLockOnTargetManager::setMaxLockOnNum(u32 num) {
    mMaxNum = num;
    if (mPtrs.elems[(mNextIndex <= 7u) ? mNextIndex : 0u].mpPtr == nullptr) {
        return;
    }
    mNextIndex = ((mNextIndex + 1u) < num) ? (mNextIndex + 1u) : 0u;
}

__attribute__((weak)) void cpLockOnTargetManager::add(const cpLockOn::cLockOnTarget* p, bool isEffect) {
    DDON_STUB("cpLockOnTargetManager::add")
    /* stub */
}

__attribute__((weak)) bool cpLockOnTargetManager::insertToEmpty(const cpLockOn::cLockOnTarget* p, bool isEffect, bool isSE) {
    DDON_STUB("cpLockOnTargetManager::insertToEmpty")
    return {};
}

__attribute__((weak)) void cpLockOnTargetManager::erase(const cpLockOn::cLockOnTarget* p) {
    DDON_STUB("cpLockOnTargetManager::erase")
    /* stub */
}

__attribute__((weak)) void cpLockOnTargetManager::setup() {
    DDON_STUB("cpLockOnTargetManager::setup")
    /* stub */
}

__attribute__((weak)) void cpLockOnTargetManager::move() {
    DDON_STUB("cpLockOnTargetManager::move")
    /* stub */
}

void cpLockOnTargetManager::updateEfcHandle() {
    static_cast<sGUIExt*>(sGUI::getInstance())->updateAimTargetMarkerId(mTargetMarkerIds.elems[0]);
    static_cast<sGUIExt*>(sGUI::getInstance())->updateAimTargetMarkerId(mTargetMarkerIds.elems[1]);
    static_cast<sGUIExt*>(sGUI::getInstance())->updateAimTargetMarkerId(mTargetMarkerIds.elems[2]);
    static_cast<sGUIExt*>(sGUI::getInstance())->updateAimTargetMarkerId(mTargetMarkerIds.elems[3]);
    static_cast<sGUIExt*>(sGUI::getInstance())->updateAimTargetMarkerId(mTargetMarkerIds.elems[4]);
    static_cast<sGUIExt*>(sGUI::getInstance())->updateAimTargetMarkerId(mTargetMarkerIds.elems[5]);
    static_cast<sGUIExt*>(sGUI::getInstance())->updateAimTargetMarkerId(mTargetMarkerIds.elems[6]);
    static_cast<sGUIExt*>(sGUI::getInstance())->updateAimTargetMarkerId(mTargetMarkerIds.elems[7]);
    static_cast<sGUIExt*>(sGUI::getInstance())->updateAimTargetMarkerId(mTargetMarkerIdNow);
}

void cpLockOnTargetManager::end(u32 index) {
    mPtrs.elems[(index <= 7u) ? index : 0u].mpPtr = nullptr;
    elf_v_Z29GUIAIM_TARGET_MARKER_SAFE_ENDRj(mTargetMarkerIds.elems[(index <= 7u) ? index : 0u]);
    elf_v_Z29GUIAIM_TARGET_MARKER_SAFE_ENDRj(mTargetMarkerIdNow);
}

__attribute__((weak)) void cpLockOnTargetManager::endAll() {
    DDON_STUB("cpLockOnTargetManager::endAll")
    /* stub */
}

__attribute__((weak)) u32 cpLockOnTargetManager::getLockNum() const {
    DDON_STUB("cpLockOnTargetManager::getLockNum")
    return {};
}

void cpLockOnTargetManager::setLockOnType(nDDOModel::LOCKON_TARGET_TYPE type) {
    mLockOnType = type;
    if (type != nDDOModel::TYPE_SUPPORT) {
        if (type == nDDOModel::TYPE_ATTACK) {
            mSENoLockOn = 202;
        } else {
            if (type == nDDOModel::TYPE_COMMON) {
                mSENoLockOn = 201;
            }
        }
    } else {
        mSENoLockOn = 203;
    }
}

inline cpLockOnTargetManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpLockOnTargetManager::MyDTI cpLockOnTargetManager::DTI("cpLockOnTargetManager", &::cpComponent::DTI, 304ul, 0u, 0u);

__attribute__((weak)) MtObject* cpLockOnTargetManager::MyDTI::newInstance() const {
    DDON_STUB("cpLockOnTargetManager::MyDTI::newInstance")
    return nullptr;
}

