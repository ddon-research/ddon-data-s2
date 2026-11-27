// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIMousePointer.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sApp.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sRender.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIMousePointer::getDTI() const {
    return uGUIMousePointer::DTI;
}

void* uGUIMousePointer::operator new(size_t sz, u32 align) {
    return uGUIMousePointer::getAllocator()->memAlloc(sz, align, uGUIMousePointer::DTI.getID());
}

uGUIMousePointer::uGUIMousePointer() : uGUIBase(0u, false) {
    mpInstAnim = nullptr;
    mpGUIRes = nullptr;
    mAlpha = 1.0f;
    mRemainingTime = 0.0f;
    mRemainingTimeMax = 10.0f;
    mEndType = 1;
    setArcTag(rArchiveListArray::convTagId("uGUIMousePointer"), 0u, false);
}

uGUIMousePointer::~uGUIMousePointer() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIMousePointer::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_MOUSE_GUI"), 129u, 1417150317l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIMousePointer::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(19u), true);
    setPlay(true);
    setInstNull(static_cast<cGUIInstNull*>(getInstance(3u, false)), true);
    mpInstAnim = static_cast<cGUIInstAnimation*>(getInstance(2u, false));
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMousePointer::updateInit);
}

void uGUIMousePointer::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIMousePointer::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIMousePointer::draw(cDraw* pDraw) {
    DDON_STUB("uGUIMousePointer::draw")
    /* stub */
}

__attribute__((weak)) void uGUIMousePointer::setAnmType(u32 uAnmType) {
    DDON_STUB("uGUIMousePointer::setAnmType")
    /* stub */
}

void uGUIMousePointer::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMousePointer::updateWait);
}

__attribute__((weak)) void uGUIMousePointer::updateWait() {
    DDON_STUB("uGUIMousePointer::updateWait")
    /* stub */
}

inline uGUIMousePointer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMousePointer::MyDTI uGUIMousePointer::DTI("uGUIMousePointer", &::uGUIBase::DTI, 2288ul, 0u, 0u);

MtObject* uGUIMousePointer::MyDTI::newInstance() const {
    return new (16u) uGUIMousePointer;
}

