// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIRankUp.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cResource.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIRankUp::getDTI() const {
    return uGUIRankUp::DTI;
}

void* uGUIRankUp::operator new(size_t sz, u32 align) {
    return uGUIRankUp::getAllocator()->memAlloc(sz, align, uGUIRankUp::DTI.getID());
}

uGUIRankUp::uGUIRankUp() : uGUIBase(0u, false) {
    mEndType = 0;
    mFlowId = 0;
    mpSeRes = nullptr;
    mpGUIRes = nullptr;
    mRank = 0;
    mDispFrame = 0.0f;
    mpObjMsgNum = nullptr;
    mpInstAnim = nullptr;
    mpInstNull = nullptr;
    setArcTag(rArchiveListArray::convTagId("uGUIRankUp"), 0u, false);
}

uGUIRankUp::~uGUIRankUp() {
    if (mpSeRes != nullptr) {
        mpSeRes->release();
        mpSeRes = nullptr;
    }
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIRankUp::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIRankUp::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_RANKUP_GUI"), 129u, 1419490149l))) == nullptr)) {
        return false;
    }
    if ((mpSeRes == nullptr) && ((mpSeRes = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_MASTER_SRQR"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIRankUp::setup() {
    DDON_STUB("uGUIRankUp::setup")
    /* stub */
}

void uGUIRankUp::kill() {
    this->uGUIBase::kill();
}

void uGUIRankUp::move() {
    this->uGUIBase::move();
}

void uGUIRankUp::updateMove() {
    if (mFlowId != 3) {
        if (mFlowId == 2) {
            mDispFrame = mDispFrame - mDeltaTime;
            if (0.0f >= mDispFrame) {
                mFlowId = 3;
                setSequenceId(mpInstAnim, 3u, false);
            }
        } else {
            if (mFlowId == 1) {
                if (mpInstAnim != nullptr) {
                    if (mpInstAnim->isAnimationEnd()) {
                        mFlowId = 2;
                        mDispFrame = 90.0f;
                    }
                } else {
                    mFlowId = 2;
                    mDispFrame = 90.0f;
                }
            }
        }
    } else {
        if (mpInstAnim != nullptr) {
            if (mpInstAnim->isAnimationEnd()) {
                mFlowId = 4;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIRankUp::updateExit);
            }
        } else {
            mFlowId = 4;
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIRankUp::updateExit);
        }
    }
}

void uGUIRankUp::updateExit() {
    end();
}

inline uGUIRankUp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIRankUp::MyDTI uGUIRankUp::DTI("uGUIRankUp", &::uGUIBase::DTI, 2304ul, 0u, 0u);

MtObject* uGUIRankUp::MyDTI::newInstance() const {
    return new (16u) uGUIRankUp;
}

