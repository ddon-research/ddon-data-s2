// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPopCmd01.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cMenuBase.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "../../XFramework/uCoord.h"
#include "uGUIBase.h"
#include "uGUIPopBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIPopCmd01::getDTI() const {
    return uGUIPopCmd01::DTI;
}

void* uGUIPopCmd01::operator new(size_t sz, u32 align) {
    return uGUIPopCmd01::getAllocator()->memAlloc(sz, align, uGUIPopCmd01::DTI.getID());
}

uGUIPopCmd01::~uGUIPopCmd01() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIPopCmd01::loadResource() {
    if (mpGUIRes == nullptr) {
        if ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_CMD01_GUI"), 129u, 1447310709l))) != nullptr) {
            if (loadGMDarc(getArcTag(0u), "RES_ID_POP_CMD_RES_GMD", 0u)) {
                return loadGMDarc(getArcTag(0u), "RES_ID_SUBMENU_RES_GMD", 1u);
            }
        }
    } else {
        if (loadGMDarc(getArcTag(0u), "RES_ID_POP_CMD_RES_GMD", 0u)) {
            return loadGMDarc(getArcTag(0u), "RES_ID_SUBMENU_RES_GMD", 1u);
        }
    }
    return false;
}

__attribute__((weak)) void uGUIPopCmd01::setup() {
    DDON_STUB("uGUIPopCmd01::setup")
    /* stub */
}

void uGUIPopCmd01::kill() {
    this->uGUIBase::kill();
    updatePtr();
    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 23u);
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIPopCmd01::move() {
    this->uGUIPopBase::move();
}

void uGUIPopCmd01::deleteDuplicateAll() {
    this->uGUIBase::deleteDuplicateInstanceAll();
    if (mItems.mLength != 0) {
        u32 v0_0 = mItems.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mItems.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mItems.mpArray[i0_3];
                v1_0 = mItems.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mItems.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mItems.mpArray));
    }
    mItems.mpArray = nullptr;
    mItems.mBufsiz = 0;
    mItems.mLength = 0;
}

__attribute__((weak)) void uGUIPopCmd01::moveInput() {
    DDON_STUB("uGUIPopCmd01::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIPopCmd01::moveEvent() {
    DDON_STUB("uGUIPopCmd01::moveEvent")
    /* stub */
}

void uGUIPopCmd01::addItemSystemMenu(u32 msgId, uGUIPopBase::MODE mode, s32 errMsg) {
    _addItem2(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[1], msgId), mode, errMsg);
}

MtSize uGUIPopCmd01::getWindowSize() {
    return mWindow.getWindowSize();
}

s32 uGUIPopCmd01::getSMenuCursorY() {
    if (mpCtrl != nullptr) {
        return mpCtrl->getCurrentPos();
    } else {
        return 0;
    }
}

void uGUIPopCmd01::updateInit() {
    executeWindow(false);
    if (mPosInit) {
        if (mPosReserve.x == MtVector3::Zero.x) {
            if (mPosReserve.y == MtVector3::Zero.y) {
                if (mPosReserve.z == MtVector3::Zero.z) {
                    if (!static_cast<sGUIExt*>(sGUI::getInstance())->isEnablePosPopCmd()) {
                        if (mPosSetWaitTimer > 0) {
                            mPosSetWaitTimer = mPosSetWaitTimer - 1;
                        } else {
                            MtVector3 frame56(static_cast<sGUIExt*>(sGUI::getInstance())->getPointerPosPopCmd());
                            mPosPointer.x = frame56.x;
                            mPosPointer.y = frame56.y;
                            mPosPointer.z = frame56.z;
                            mPosPointer.pad_ = 0.0f;
                            mPosInit = false;
                            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopCmd01::updateWait);
                        }
                    } else {
                        MtVector3 frame56(static_cast<sGUIExt*>(sGUI::getInstance())->getPointerPosPopCmd());
                        mPosPointer.x = frame56.x;
                        mPosPointer.y = frame56.y;
                        mPosPointer.z = frame56.z;
                        mPosPointer.pad_ = 0.0f;
                        mPosInit = false;
                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopCmd01::updateWait);
                    }
                } else {
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopCmd01::updateWait);
                }
            } else {
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopCmd01::updateWait);
            }
        } else {
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopCmd01::updateWait);
        }
    } else {
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopCmd01::updateWait);
    }
}

void uGUIPopCmd01::updateWait() {
    executeWindow(true);
    u32 i = 0;
    if (mItems.mLength != 0) {
        do {
            if (static_cast<cItem*>(mItems.getBuffer()[static_cast<int>(i)])->mMode != MODE_DEFAULT) {
                setMessageColor(static_cast<cGUIObject*>(static_cast<cItem*>(mItems.getBuffer()[static_cast<int>(i)])->mpOBJ_msg_cmnd_box_m_cmnd_name), sGUIExt::FONT_COLOR_DISABLE);
            } else {
                setMessageColor(static_cast<cGUIObject*>(static_cast<cItem*>(mItems.getBuffer()[static_cast<int>(i)])->mpOBJ_msg_cmnd_box_m_cmnd_name), sGUIExt::FONT_COLOR_DEFAULT);
            }
            i += 1u;
        } while (i < mItems.mLength);
    }
}

void uGUIPopCmd01::updateAutoKill() {
    executeWindow(false);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopCmd01::updateExit);
}

void uGUIPopCmd01::updateExit() {
    end();
}

__attribute__((weak)) void uGUIPopCmd01::executeWindow(bool execCtrl) {
    DDON_STUB("uGUIPopCmd01::executeWindow")
    /* stub */
}

__attribute__((weak)) void uGUIPopCmd01::_addItem(uGUIBase* pUnit, MT_CTSTR title, uGUIPopBase::DATA_FUNC pFunc, MtObject* pParam, uGUIPopBase::MODE mode, s32 errMsg) {
    DDON_STUB("uGUIPopCmd01::_addItem")
    /* stub */
}

__attribute__((weak)) void uGUIPopCmd01::_addItem2(MT_CTSTR title, uGUIPopBase::MODE mode, s32 errMsg) {
    DDON_STUB("uGUIPopCmd01::_addItem2")
    /* stub */
}

__attribute__((weak)) u32 uGUIPopCmd01::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIPopCmd01::evCtrlDecide")
    return {};
}

u32 uGUIPopCmd01::evCtrlCancel(cControl::Message* msg) {
    if (mExecMode == EXEC_MODE_SYSTEM_MENU) {
        setInputEvent(5u);
    } else {
        setInputEvent(66u);
    }
    return 0;
}

u32 uGUIPopCmd01::evCtrlMove(cControl::Message* msg) {
    setInputEvent(68u);
    return 0;
}

__attribute__((weak)) u32 uGUIPopCmd01::evCtrlClick(cControl::Message* msg) {
    DDON_STUB("uGUIPopCmd01::evCtrlClick")
    return {};
}

inline uGUIPopCmd01::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopCmd01::MyDTI uGUIPopCmd01::DTI("uGUIPopCmd01", &::uGUIPopBase::DTI, 3312ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopCmd01::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopCmd01::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIPopCmd01::cItem::getDTI() const {
    return uGUIPopCmd01::cItem::DTI;
}

__attribute__((weak)) void uGUIPopCmd01::cItem::load(uGUIPopCmd01* pPopUnit, cControl* pCtrl, u32 idx) {
    DDON_STUB("uGUIPopCmd01::cItem::load")
    /* stub */
}

inline uGUIPopCmd01::cItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopCmd01::cItem::MyDTI uGUIPopCmd01::cItem::DTI("uGUIPopCmd01::cItem", &::uGUIBase::cSupportBase::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopCmd01::cItem::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopCmd01::cItem::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uGUIPopCmd01::cItem>::~MtTypedArray();

