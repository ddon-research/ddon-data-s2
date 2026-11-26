// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIMouseOverCursor.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIMouseOverCursor::getDTI() const {
    return uGUIMouseOverCursor::DTI;
}

inline MtAllocator* uGUIMouseOverCursor::getAllocator() {
    return MtMemoryAllocator::getAllocator(uGUIMouseOverCursor::DTI);
}

void* uGUIMouseOverCursor::operator new(size_t sz, u32 align) {
    return uGUIMouseOverCursor::getAllocator()->memAlloc(sz, align, uGUIMouseOverCursor::DTI.getID());
}

inline void uGUIMouseOverCursor::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIMouseOverCursor::DTI)->memFree(p_addr);
}

__attribute__((noinline)) uGUIMouseOverCursor::~uGUIMouseOverCursor() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mMOC.mLength != 0) {
        u32 v0_0 = mMOC.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMOC.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMOC.mpArray[i0_3];
                v1_0 = mMOC.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMOC.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMOC.mpArray));
    }
    mMOC.mpArray = nullptr;
    mMOC.mBufsiz = 0;
    mMOC.mLength = 0;
}

bool uGUIMouseOverCursor::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CR_MOUSEOVER_GUI"), 129u, 1410154527l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIMouseOverCursor::setup() {
    DDON_STUB("uGUIMouseOverCursor::setup")
    /* stub */
}

void uGUIMouseOverCursor::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mMOC.mLength != 0) {
        u32 v0_0 = mMOC.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMOC.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMOC.mpArray[i0_3];
                v1_0 = mMOC.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMOC.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMOC.mpArray));
    }
    mMOC.mpArray = nullptr;
    mMOC.mBufsiz = 0;
    mMOC.mLength = 0;
}

void uGUIMouseOverCursor::move() {
    this->uGUIBase::move();
}

void uGUIMouseOverCursor::draw(cDraw* pDraw) {
    if (!static_cast<sGUIExt*>(sGUI::getInstance())->mMouse.isActiveMouse()) {
        return;
    }
    this->uGUIBase::draw(pDraw);
}

__attribute__((weak)) void uGUIMouseOverCursor::reqMouseOverCursor(MtRect rect, u32 uType) {
    DDON_STUB("uGUIMouseOverCursor::reqMouseOverCursor")
    /* stub */
}

__attribute__((weak)) void uGUIMouseOverCursor::beginMouseOverCursor() {
    DDON_STUB("uGUIMouseOverCursor::beginMouseOverCursor")
    /* stub */
}

void uGUIMouseOverCursor::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMouseOverCursor::updateWait);
}

__attribute__((weak)) void uGUIMouseOverCursor::updateWait() {
}

inline uGUIMouseOverCursor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMouseOverCursor::MyDTI uGUIMouseOverCursor::DTI("uGUIMouseOverCursor", &::uGUIBase::DTI, 2368ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMouseOverCursor::MyDTI::newInstance() const {
    DDON_STUB("uGUIMouseOverCursor::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIMouseOverCursor::cMOC::getDTI() const {
    return uGUIMouseOverCursor::cMOC::DTI;
}

inline void uGUIMouseOverCursor::cMOC::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIMouseOverCursor::cMOC::DTI)->memFree(p_addr);
}

__attribute__((weak)) void uGUIMouseOverCursor::cMOC::setAlpha(u8 uAlpha) {
    DDON_STUB("uGUIMouseOverCursor::cMOC::setAlpha")
    /* stub */
}

__attribute__((weak)) void uGUIMouseOverCursor::cMOC::setRect(MtRect rect) {
    DDON_STUB("uGUIMouseOverCursor::cMOC::setRect")
    /* stub */
}

inline uGUIMouseOverCursor::cMOC::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMouseOverCursor::cMOC::MyDTI uGUIMouseOverCursor::cMOC::DTI("uGUIMouseOverCursor::cMOC", &::MtObject::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMouseOverCursor::cMOC::MyDTI::newInstance() const {
    DDON_STUB("uGUIMouseOverCursor::cMOC::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uGUIMouseOverCursor::cMOC>::~MtTypedArray();

