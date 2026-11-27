// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIBaseExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cGUIInstance.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "sArchiveManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBaseExt::getDTI() const {
    return uGUIBaseExt::DTI;
}

uGUIBaseExt::~uGUIBaseExt() {
    DDON_STUB("uGUIBaseExt::~uGUIBaseExt")
    /* stub */
}

__attribute__((weak)) void uGUIBaseExt::setAutoShow(bool isAutoShow) {
    DDON_STUB("uGUIBaseExt::setAutoShow")
    /* stub */
}

bool uGUIBaseExt::isShowable() const {
    if (isAttachedResource()) {
        return mUpdateMode != UPDATE_MODE_SHOW;
    } else {
        return false;
    }
}

bool uGUIBaseExt::isShow() const {
    if (isAttachedResource()) {
        return mUpdateMode == UPDATE_MODE_SHOW;
    } else {
        return false;
    }
}

bool uGUIBaseExt::show() {
    if (isAttachedResource()) {
        if (mUpdateMode != UPDATE_MODE_SHOW) {
            mUpdateMode = UPDATE_MODE_SHOW;
            onShow();
            return true;
        } else {
            return mUpdateMode == UPDATE_MODE_SHOW;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) bool uGUIBaseExt::hide() {
    DDON_STUB("uGUIBaseExt::hide")
    return {};
}

__attribute__((weak)) void uGUIBaseExt::pauseInput(bool isPauseInput) {
    DDON_STUB("uGUIBaseExt::pauseInput")
    /* stub */
}

MT_CTSTR uGUIBaseExt::getLoadArcTagName(u32 arcIndex) const {
    return "";
}

bool uGUIBaseExt::isLoadArcKeep(u32 arcIndex) const {
    return false;
}

const nGUIBaseExt::ResInfo* uGUIBaseExt::getGuiResInfo() const {
    return nullptr;
}

t64 uGUIBaseExt::getGuiResUpdateTime() const {
    return 0;
}

const nGUIBaseExt::ResInfo* uGUIBaseExt::getGmdResInfo(u32 gmdResIndex) const {
    return nullptr;
}

u32 uGUIBaseExt::getGmdResNum() const {
    return 0;
}

const nGUIBaseExt::ResInfo* uGUIBaseExt::getResInfo(u32 resIndex) const {
    return nullptr;
}

u32 uGUIBaseExt::getResNum() const {
    return 0;
}

cResource* uGUIBaseExt::getRes(u32 resIndex) const {
    if (resIndex < mResources.mLength) {
        return static_cast<cResource*>(mResources.mpArray[resIndex]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void uGUIBaseExt::setupAfterLoad() {
}

bool uGUIBaseExt::isDrawable() const {
    return true;
}

__attribute__((weak)) void uGUIBaseExt::onSetup() {
}

__attribute__((weak)) void uGUIBaseExt::onKill() {
}

__attribute__((weak)) void uGUIBaseExt::onMoveInput() {
}

__attribute__((weak)) void uGUIBaseExt::onMoveEvent() {
}

__attribute__((weak)) void uGUIBaseExt::onShow() {
}

__attribute__((weak)) void uGUIBaseExt::onHide() {
}

__attribute__((weak)) void uGUIBaseExt::onPauseInput(bool isPauseInput) {
}

__attribute__((weak)) void uGUIBaseExt::onPauseDraw(bool isPauseDraw) {
}

__attribute__((weak)) void uGUIBaseExt::onUpdateShow() {
}

__attribute__((weak)) void uGUIBaseExt::onUpdateHide() {
}

__attribute__((weak)) void uGUIBaseExt::onAfterUpdate() {
}

__attribute__((weak)) bool uGUIBaseExt::loadArchive() {
    DDON_STUB("uGUIBaseExt::loadArchive")
    return {};
}

bool uGUIBaseExt::loadResource() {
    const nGUIBaseExt::ResInfo* t0 = getGuiResInfo();
    if (t0 != nullptr) {
        const MT_CTSTR t1 = t0->mSearchName;
        t64 t2 = getGuiResUpdateTime();
        if (mpGUIRes == nullptr) {
            u32 t3 = getArcTag(0u);
            if ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(t3, rArchiveListArray::convSearchId(t1), 129u, t2))) == nullptr) {
                mpGUIRes;
                return false;
            }
        }
    }
    u32 t4 = getGmdResNum();
    if (((t4 <= 3u) ? t4 : 4u) != 0) {
        unsigned int i0_3 = 0;
        for (const u32 gmd_res_num = (t4 <= 3u) ? t4 : 4u;;) {
            const nGUIBaseExt::ResInfo* t5 = getGmdResInfo(i0_3);
            if (t5 != nullptr) {
                if (!loadGMDarc(rArchiveListArray::convTagId(t5->mArcTagName), t5->mSearchName, i0_3)) {
                    return false;
                }
            }
            if ((i0_3 + 1u) < gmd_res_num) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    const u32 other_res_num = getResNum();
    if (other_res_num != 0) {
        for (unsigned int i3_3 = 0;;) {
            const nGUIBaseExt::ResInfo* t6 = getResInfo(i3_3);
            if (t6 != nullptr) {
                ARC_TAGID t7 = rArchiveListArray::convTagId(t6->mArcTagName);
                if (mResources.getBuffer()[static_cast<int>(i3_3)] == nullptr) {
                    cResource* t8 = uiCreateResource(t7, rArchiveListArray::convSearchId(t6->mSearchName), 129u, 0l);
                    mResources.getBuffer()[static_cast<int>(i3_3)] = static_cast<MtObject*>(t8);
                    if (mResources.getBuffer()[static_cast<int>(i3_3)] == nullptr) {
                        return false;
                    }
                }
            }
            if ((i3_3 + 1u) < other_res_num) {
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

__attribute__((weak)) void uGUIBaseExt::setup() {
    DDON_STUB("uGUIBaseExt::setup")
    /* stub */
}

void uGUIBaseExt::kill() {
    this->uGUIBase::kill();
    releaseResources();
    onKill();
}

__attribute__((weak)) void uGUIBaseExt::moveInput() {
    DDON_STUB("uGUIBaseExt::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIBaseExt::moveEvent() {
    DDON_STUB("uGUIBaseExt::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIBaseExt::releaseResources() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    releaseGMD();
    if (mResources.size() != 0) {
        u32 v0_0 = mResources.size();
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mResources.getBuffer()[static_cast<int>(i0_3)] == nullptr) {
                v1_0 = v0_0;
            } else {
                static_cast<cResource*>(mResources.getBuffer()[static_cast<int>(i0_3)])->release();
                mResources.getBuffer()[static_cast<int>(i0_3)] = nullptr;
                v1_0 = mResources.size();
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mResources.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mResources.mpArray));
    }
    mResources.mpArray = nullptr;
    mResources.mBufsiz = 0;
    mResources.mLength = 0;
}

__attribute__((weak)) void uGUIBaseExt::updateMain() {
    DDON_STUB("uGUIBaseExt::updateMain")
    /* stub */
}

inline uGUIBaseExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBaseExt::MyDTI uGUIBaseExt::DTI("uGUIBaseExt", &::uGUIBase::DTI, 2304ul, 0u, 1u);

MtObject* uGUIBaseExt::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGUIBaseExtHud::getDTI() const {
    return uGUIBaseExtHud::DTI;
}

uGUIBaseExtHud::~uGUIBaseExtHud() {
}

__attribute__((weak)) void uGUIBaseExtHud::onSetupAfterLoad() {
}

__attribute__((weak)) void uGUIBaseExtHud::onShow() {
    DDON_STUB("uGUIBaseExtHud::onShow")
    /* stub */
}

void uGUIBaseExtHud::onHide() {
    mAlpha = 1.0f;
}

__attribute__((weak)) void uGUIBaseExtHud::onUpdateHide() {
    DDON_STUB("uGUIBaseExtHud::onUpdateHide")
    /* stub */
}

__attribute__((weak)) bool uGUIBaseExtHud::isDrawable() const {
    DDON_STUB("uGUIBaseExtHud::isDrawable")
    return {};
}

void uGUIBaseExtHud::setupAfterLoad() {
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(7u), true);
    setPlay(true);
    onSetupAfterLoad();
    cGUIInstNull* t0 = getInstNull();
    if (t0 != nullptr) {
        t0->setVisible(false);
        t0->setExecute(false);
    }
    mIsDrawable = false;
}

inline uGUIBaseExtHud::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBaseExtHud::MyDTI uGUIBaseExtHud::DTI("uGUIBaseExtHud", &::uGUIBaseExt::DTI, 2320ul, 0u, 1u);

MtObject* uGUIBaseExtHud::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGUIBaseExtWindow::getDTI() const {
    return uGUIBaseExtWindow::DTI;
}

uGUIBaseExtWindow::~uGUIBaseExtWindow() {
}

inline uGUIBaseExtWindow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBaseExtWindow::MyDTI uGUIBaseExtWindow::DTI("uGUIBaseExtWindow", &::uGUIBaseExt::DTI, 2304ul, 0u, 1u);

MtObject* uGUIBaseExtWindow::MyDTI::newInstance() const {
    return nullptr;
}

template MtTypedArray<cResource>::~MtTypedArray();

