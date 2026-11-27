// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpOmBlink.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpDDMrlMgr.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sGame.h"
#include "sPlayerManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpOmBlink::getDTI() const {
    return cpOmBlink::DTI;
}

void* cpOmBlink::operator new(size_t sz, u32 align) {
    return cpOmBlink::getAllocator()->memAlloc(sz, align, cpOmBlink::DTI.getID());
}

cpOmBlink::cpOmBlink() {
    mpModel = nullptr;
    mBlinkType = 0;
    mRangeNear = 200.0f;
    mRangeFar = 400.0f;
    mDiffuseColorCtr = 0.0f;
    mDiffuseIdleTimer = 0.0f;
}

cpOmBlink::~cpOmBlink() {
}

void cpOmBlink::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

void cpOmBlink::setup() {
    switch (static_cast<sAreaExt*>(sArea::getInstance())->getStageType(sGame::getInstance()->getStageNo()) - 1u) {
        case 0:
        {
            mRangeNear = 200.0f;
            mRangeFar = 400.0f;
            break;
        }
        case 1:
        {
            mRangeNear = 800.0f;
            mRangeFar = 1600.0f;
            break;
        }
        case 2:
        {
            mRangeNear = 200.0f;
            mRangeFar = 400.0f;
            break;
        }
        case 3:
        {
            mRangeNear = 500.0f;
            mRangeFar = 1200.0f;
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void cpOmBlink::move() {
    DDON_STUB("cpOmBlink::move")
    /* stub */
}

void cpOmBlink::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

void cpOmBlink::setBlinkOff() {
    mBlinkType = 0;
    mpModel->mpDDMrlMgr->resetMaterialMode();
}

inline cpOmBlink::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpOmBlink::MyDTI cpOmBlink::DTI("cpOmBlink", &::cpComponent::DTI, 112ul, 0u, 0u);

MtObject* cpOmBlink::MyDTI::newInstance() const {
    return new (16u) cpOmBlink;
}

