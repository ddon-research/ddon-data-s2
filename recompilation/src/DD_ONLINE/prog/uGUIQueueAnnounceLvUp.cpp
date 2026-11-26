// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIQueueAnnounceLvUp.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sMain.h"
#include "uGUIBase.h"
#include "uGUIQueueAnnounce.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIQueueAnnounceLvUp::getDTI() const {
    return uGUIQueueAnnounceLvUp::DTI;
}

inline MtAllocator* uGUIQueueAnnounceLvUp::getAllocator() {
    return MtMemoryAllocator::getAllocator(uGUIQueueAnnounceLvUp::DTI);
}

void* uGUIQueueAnnounceLvUp::operator new(size_t sz, u32 align) {
    return uGUIQueueAnnounceLvUp::getAllocator()->memAlloc(sz, align, uGUIQueueAnnounceLvUp::DTI.getID());
}

inline void uGUIQueueAnnounceLvUp::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIQueueAnnounceLvUp::DTI)->memFree(p_addr);
}

uGUIQueueAnnounceLvUp::uGUIQueueAnnounceLvUp() {
    DDON_STUB("uGUIQueueAnnounceLvUp::uGUIQueueAnnounceLvUp")
    /* stub */
}

uGUIQueueAnnounceLvUp::~uGUIQueueAnnounceLvUp() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIQueueAnnounceLvUp::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_JOB_LV_UP_GUI"), 129u, 1419496719l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIQueueAnnounceLvUp::setup() {
    DDON_STUB("uGUIQueueAnnounceLvUp::setup")
    /* stub */
}

void uGUIQueueAnnounceLvUp::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIQueueAnnounceLvUp::updateInit() {
    if (mpINST_msg_joblv != nullptr) {
        setSequenceId(mpINST_msg_joblv, 2u, true);
        STATE t0 = mState;
        if (mpOBJ_msg_joblv_craft != nullptr) {
            mpOBJ_msg_joblv_craft->setVisible(t0 != STATE_JOB_LVUP);
        }
        if (mpOBJ_msg_joblv_symbol00 != nullptr) {
            mpOBJ_msg_joblv_symbol00->setVisible(t0 == STATE_JOB_LVUP);
        }
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIQueueAnnounceLvUp::updateIn);
    } else {
        STATE t0 = mState;
        if (mpOBJ_msg_joblv_craft != nullptr) {
            mpOBJ_msg_joblv_craft->setVisible(t0 != STATE_JOB_LVUP);
        }
        if (mpOBJ_msg_joblv_symbol00 != nullptr) {
            mpOBJ_msg_joblv_symbol00->setVisible(t0 == STATE_JOB_LVUP);
        }
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIQueueAnnounceLvUp::updateIn);
    }
}

void uGUIQueueAnnounceLvUp::updateIn() {
    if (!mIsFlowEnd) {
        return;
    }
    if (mpINST_msg_joblv != nullptr) {
        setSequenceId(mpINST_msg_joblv, 1u, true);
        STATE t0 = mState;
        if (mpOBJ_msg_joblv_craft != nullptr) {
            mpOBJ_msg_joblv_craft->setVisible(t0 != STATE_JOB_LVUP);
        }
        if (mpOBJ_msg_joblv_symbol00 != nullptr) {
            mpOBJ_msg_joblv_symbol00->setVisible(t0 == STATE_JOB_LVUP);
        }
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIQueueAnnounceLvUp::updateWait);
    } else {
        STATE t0 = mState;
        if (mpOBJ_msg_joblv_craft != nullptr) {
            mpOBJ_msg_joblv_craft->setVisible(t0 != STATE_JOB_LVUP);
        }
        if (mpOBJ_msg_joblv_symbol00 != nullptr) {
            mpOBJ_msg_joblv_symbol00->setVisible(t0 == STATE_JOB_LVUP);
        }
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIQueueAnnounceLvUp::updateWait);
    }
}

void uGUIQueueAnnounceLvUp::updateWait() {
    mFadeCount = mFadeCount + (sMain::getInstance()->mDeltaTime / sMain::getInstance()->mFps);
    if (mFadeCountChk > mFadeCount) {
    } else {
        if (mpINST_msg_joblv != nullptr) {
            setSequenceId(mpINST_msg_joblv, 3u, true);
            setChangeFlowVariable(2u, true);
            STATE t0 = mState;
            if (mpOBJ_msg_joblv_craft != nullptr) {
                mpOBJ_msg_joblv_craft->setVisible(t0 != STATE_JOB_LVUP);
            }
            if (mpOBJ_msg_joblv_symbol00 != nullptr) {
                mpOBJ_msg_joblv_symbol00->setVisible(t0 == STATE_JOB_LVUP);
            }
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIQueueAnnounceLvUp::updateOut);
        } else {
            setChangeFlowVariable(2u, true);
            STATE t0 = mState;
            if (mpOBJ_msg_joblv_craft != nullptr) {
                mpOBJ_msg_joblv_craft->setVisible(t0 != STATE_JOB_LVUP);
            }
            if (mpOBJ_msg_joblv_symbol00 != nullptr) {
                mpOBJ_msg_joblv_symbol00->setVisible(t0 == STATE_JOB_LVUP);
            }
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIQueueAnnounceLvUp::updateOut);
        }
    }
}

void uGUIQueueAnnounceLvUp::updateOut() {
    if (!mIsFlowEnd) {
        return;
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIQueueAnnounceLvUp::updateExit);
}

void uGUIQueueAnnounceLvUp::updateExit() {
    end();
}

inline uGUIQueueAnnounceLvUp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIQueueAnnounceLvUp::MyDTI uGUIQueueAnnounceLvUp::DTI("uGUIQueueAnnounceLvUp", &::uGUIBase::DTI, 2896ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIQueueAnnounceLvUp::MyDTI::newInstance() const {
    DDON_STUB("uGUIQueueAnnounceLvUp::MyDTI::newInstance")
    return nullptr;
}

