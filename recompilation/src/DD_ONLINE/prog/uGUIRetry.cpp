// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIRetry.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uGUI.h"
#include "uGUIAnnounce.h"
#include "uGUIBase.h"
#include "uGUIRetrySelect.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIRetry::getDTI() const {
    return uGUIRetry::DTI;
}

void* uGUIRetry::operator new(size_t sz, u32 align) {
    return uGUIRetry::getAllocator()->memAlloc(sz, align, uGUIRetry::DTI.getID());
}

uGUIRetry::~uGUIRetry() {
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIRetry::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_RETRY_GUI"), 129u, 1413870035l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIRetry::setup() {
    DDON_STUB("uGUIRetry::setup")
    /* stub */
}

void uGUIRetry::kill() {
    if (mpGUIAnnounce != nullptr) {
        mpGUIAnnounce->kill();
        mpGUIAnnounce = nullptr;
    }
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->kill();
        mpGUISystemMsg = nullptr;
        this->uGUIBase::kill();
        uGUIRetrySelect* t0 = mpGUISelect;
        if (t0 != nullptr) {
            if (t0->mpListCtrl != nullptr) {
                t0->mpListCtrl->setCurrentPos(2, false);
            }
            t0->setFlowId(3u);
        }
    } else {
        this->uGUIBase::kill();
        uGUIRetrySelect* t0 = mpGUISelect;
        if (t0 != nullptr) {
            if (t0->mpListCtrl != nullptr) {
                t0->mpListCtrl->setCurrentPos(2, false);
            }
            t0->setFlowId(3u);
        }
    }
}

void uGUIRetry::move() {
    this->uGUIBase::move();
}

void uGUIRetry::updatePtr() {
    if (mpGUIAnnounce != nullptr) {
        if (!mpGUIAnnounce->isEnable()) {
            mpGUIAnnounce = nullptr;
        }
    }
    if (mpGUISystemMsg != nullptr) {
        if (!mpGUISystemMsg->isEnable()) {
            mpGUISystemMsg = nullptr;
        }
    }
    if (mpGUISelect == nullptr) {
        return;
    }
    if (mpGUISelect->isEnable()) {
        return;
    }
    mpGUISelect = nullptr;
}

__attribute__((weak)) void uGUIRetry::initDown() {
    DDON_STUB("uGUIRetry::initDown")
    /* stub */
}

__attribute__((weak)) void uGUIRetry::initDownDialog() {
    DDON_STUB("uGUIRetry::initDownDialog")
    /* stub */
}

__attribute__((weak)) void uGUIRetry::restartDown() {
    DDON_STUB("uGUIRetry::restartDown")
    /* stub */
}

__attribute__((weak)) void uGUIRetry::initDialog(MT_CTSTR text, MT_CTSTR analyze) {
    DDON_STUB("uGUIRetry::initDialog")
    /* stub */
}

__attribute__((weak)) void uGUIRetry::initRevive(u32 type) {
    DDON_STUB("uGUIRetry::initRevive")
    /* stub */
}

__attribute__((weak)) void uGUIRetry::initReviveDialog() {
    DDON_STUB("uGUIRetry::initReviveDialog")
    /* stub */
}

__attribute__((weak)) void uGUIRetry::restartRevive() {
    DDON_STUB("uGUIRetry::restartRevive")
    /* stub */
}

__attribute__((weak)) void uGUIRetry::hideRevive() {
    DDON_STUB("uGUIRetry::hideRevive")
    /* stub */
}

__attribute__((weak)) void uGUIRetry::setTimer(s32 timer) {
    DDON_STUB("uGUIRetry::setTimer")
    /* stub */
}

__attribute__((weak)) void uGUIRetry::setNum(u32 index, u64 num) {
    DDON_STUB("uGUIRetry::setNum")
    /* stub */
}

void uGUIRetry::setEnable(u32 index, bool isEnable) {
    if (index <= 4u) {
        mItem[index].isEnable = isEnable;
        cVerticalList* t0 = mpListCtrl;
        if (t0 != nullptr) {
            s32 t1 = t0->getCurrentPos();
            if (isEnable) {
                cGUIInstAnimation* t2 = mItem[index].mpInstAnimText;
                setSequenceId(t2, static_cast<u32>((t1 == static_cast<int>(index)) ? 4 : 1), false);
            } else {
                cGUIInstAnimation* t2 = mItem[index].mpInstAnimText;
                setSequenceId(t2, 7u, false);
            }
        } else {
            if (isEnable) {
                cGUIInstAnimation* t2 = mItem[index].mpInstAnimText;
                setSequenceId(t2, static_cast<u32>((index == 0) ? 4 : 1), false);
            } else {
                cGUIInstAnimation* t2 = mItem[index].mpInstAnimText;
                setSequenceId(t2, 7u, false);
            }
        }
    }
}

void uGUIRetry::reqDecideAnim() {
    if (mpGUISelect == nullptr) {
        return;
    }
    mpGUISelect->setFlowId(3u);
    mpGUISelect = nullptr;
}

__attribute__((weak)) void uGUIRetry::updateInit() {
}

void uGUIRetry::updateList() {
    sGUI* t0 = sGUI::getInstance();
    u8 t1 = static_cast<sGUIExt*>(t0)->mSCM.mRno0;
    if (t1 == 2) {
        u32 t2 = static_cast<sGUIExt*>(t0)->mSCM.mMode;
        if (t2 == 2) {
            cGUIInstAnimation* t3 = mpInstAnimWindow;
            setInstanceVisible(static_cast<cGUIInstance*>(t3), false);
        } else {
            sMenu* t4 = sMenu::getInstance();
            if (t4->mPawnRevive.isUpdateCursor()) {
                u32 t6 = mType;
                if (t6 == 2) {
                    uGUIRetrySelect* t7 = mpGUISelect;
                    if (t7 != nullptr) {
                        cHorizontalList* t8 = t7->mpListCtrl;
                        if (t8 != nullptr) {
                            s32 t9 = t8->getCurrentPos();
                            cVerticalList* t10 = mpListCtrl;
                            if (t10 != nullptr) {
                                t10->setCurrentPos(t9, false);
                                uGUIRetrySelect* t12 = mpGUISelect;
                                bool t13 = mpGUISelect->isDecide();
                                mIsDecide = t13;
                                cGUIInstAnimation* t21 = mpInstAnimWindow;
                                setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                            } else {
                                bool t13 = mpGUISelect->isDecide();
                                mIsDecide = t13;
                                cGUIInstAnimation* t21 = mpInstAnimWindow;
                                setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                            }
                        } else {
                            cVerticalList* t10 = mpListCtrl;
                            if (t10 != nullptr) {
                                t10->setCurrentPos(0, false);
                                uGUIRetrySelect* t12 = mpGUISelect;
                                bool t13 = mpGUISelect->isDecide();
                                mIsDecide = t13;
                                cGUIInstAnimation* t21 = mpInstAnimWindow;
                                setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                            } else {
                                bool t13 = mpGUISelect->isDecide();
                                mIsDecide = t13;
                                cGUIInstAnimation* t21 = mpInstAnimWindow;
                                setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                            }
                        }
                    } else {
                        cVerticalList* t19 = mpListCtrl;
                        if (t19 != nullptr) {
                            t19->setCurrentPos(2, false);
                            mIsDecide = true;
                            cGUIInstAnimation* t21 = mpInstAnimWindow;
                            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                        } else {
                            mIsDecide = true;
                            cGUIInstAnimation* t21 = mpInstAnimWindow;
                            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                        }
                    }
                } else {
                    bool t14 = mIsDecide;
                    if (!t14) {
                        bool t15 = mIsCancel;
                        if (!t15) {
                            cVerticalList* t16 = mpListCtrl;
                            if (t16 != nullptr) {
                                t16->execute();
                                mCursor.uGUIBase::cReferenceUIVlCursor::update();
                                cGUIInstAnimation* t21 = mpInstAnimWindow;
                                setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                            } else {
                                mCursor.uGUIBase::cReferenceUIVlCursor::update();
                                cGUIInstAnimation* t21 = mpInstAnimWindow;
                                setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                            }
                        } else {
                            mCursor.uGUIBase::cReferenceUIVlCursor::update();
                            cGUIInstAnimation* t21 = mpInstAnimWindow;
                            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                        }
                    } else {
                        mCursor.uGUIBase::cReferenceUIVlCursor::update();
                        cGUIInstAnimation* t21 = mpInstAnimWindow;
                        setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                    }
                }
            } else {
                cGUIInstAnimation* t21 = mpInstAnimWindow;
                setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
            }
        }
    } else {
        sMenu* t4 = sMenu::getInstance();
        if (t4->mPawnRevive.isUpdateCursor()) {
            u32 t6 = mType;
            if (t6 == 2) {
                uGUIRetrySelect* t7 = mpGUISelect;
                if (t7 != nullptr) {
                    cHorizontalList* t8 = t7->mpListCtrl;
                    if (t8 != nullptr) {
                        s32 t9 = t8->getCurrentPos();
                        cVerticalList* t10 = mpListCtrl;
                        if (t10 != nullptr) {
                            t10->setCurrentPos(t9, false);
                            uGUIRetrySelect* t12 = mpGUISelect;
                            bool t13 = mpGUISelect->isDecide();
                            mIsDecide = t13;
                            cGUIInstAnimation* t21 = mpInstAnimWindow;
                            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                        } else {
                            bool t13 = mpGUISelect->isDecide();
                            mIsDecide = t13;
                            cGUIInstAnimation* t21 = mpInstAnimWindow;
                            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                        }
                    } else {
                        cVerticalList* t10 = mpListCtrl;
                        if (t10 != nullptr) {
                            t10->setCurrentPos(0, false);
                            uGUIRetrySelect* t12 = mpGUISelect;
                            bool t13 = mpGUISelect->isDecide();
                            mIsDecide = t13;
                            cGUIInstAnimation* t21 = mpInstAnimWindow;
                            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                        } else {
                            bool t13 = mpGUISelect->isDecide();
                            mIsDecide = t13;
                            cGUIInstAnimation* t21 = mpInstAnimWindow;
                            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                        }
                    }
                } else {
                    cVerticalList* t19 = mpListCtrl;
                    if (t19 != nullptr) {
                        t19->setCurrentPos(2, false);
                        mIsDecide = true;
                        cGUIInstAnimation* t21 = mpInstAnimWindow;
                        setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                    } else {
                        mIsDecide = true;
                        cGUIInstAnimation* t21 = mpInstAnimWindow;
                        setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                    }
                }
            } else {
                bool t14 = mIsDecide;
                if (!t14) {
                    bool t15 = mIsCancel;
                    if (!t15) {
                        cVerticalList* t16 = mpListCtrl;
                        if (t16 != nullptr) {
                            t16->execute();
                            mCursor.uGUIBase::cReferenceUIVlCursor::update();
                            cGUIInstAnimation* t21 = mpInstAnimWindow;
                            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                        } else {
                            mCursor.uGUIBase::cReferenceUIVlCursor::update();
                            cGUIInstAnimation* t21 = mpInstAnimWindow;
                            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                        }
                    } else {
                        mCursor.uGUIBase::cReferenceUIVlCursor::update();
                        cGUIInstAnimation* t21 = mpInstAnimWindow;
                        setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                    }
                } else {
                    mCursor.uGUIBase::cReferenceUIVlCursor::update();
                    cGUIInstAnimation* t21 = mpInstAnimWindow;
                    setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
                }
            }
        } else {
            cGUIInstAnimation* t21 = mpInstAnimWindow;
            setInstanceVisible(static_cast<cGUIInstance*>(t21), true);
        }
    }
}

__attribute__((weak)) void uGUIRetry::updateConfirm() {
    DDON_STUB("uGUIRetry::updateConfirm")
    /* stub */
}

void uGUIRetry::updateCountDown() {
    mCharge.uGUIBase::cReferenceUIChargesInfo::update();
}

void uGUIRetry::updateHide() {
    mCursor.uGUIBase::cReferenceUIVlCursor::update();
}

u32 uGUIRetry::evCtrlListDecide(cControl::Message* msg) {
    mIsDecide = true;
    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
    return 1;
}

u32 uGUIRetry::evCtrlListCancel(cControl::Message* msg) {
    mIsCancel = true;
    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 5u);
    return 1;
}

__attribute__((weak)) u32 uGUIRetry::evCtrlListMove(cControl::Message* msg) {
    DDON_STUB("uGUIRetry::evCtrlListMove")
    return {};
}

__attribute__((weak)) u32 uGUIRetry::evCtrlMouseClick(cControl::Message* msg) {
    DDON_STUB("uGUIRetry::evCtrlMouseClick")
    return {};
}

void uGUIRetry::clearItem() {
    for (unsigned int i0_3 = 0; i0_3 != 320; i0_3 = i0_3 + 64u) {
        setInstanceVisible(reinterpret_cast<cGUIInstance*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(reinterpret_cast<char*>(this) + i0_3) + 2304)), false);
        setInstanceVisible(reinterpret_cast<cGUIInstance*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(reinterpret_cast<char*>(this) + i0_3) + 2312)), false);
        setObjectMessage(reinterpret_cast<cGUIObject*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(reinterpret_cast<char*>(this) + i0_3) + 2344)), "", 0u, false);
        setObjectMessage(reinterpret_cast<cGUIObject*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(reinterpret_cast<char*>(this) + i0_3) + 2336)), "", 0u, false);
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(reinterpret_cast<char*>(this) + i0_3) + 2360) = 0;
    }
    setInstanceVisible(static_cast<cGUIInstance*>(mCount[0].mpInstAnim), false);
    setObjectMessage(static_cast<cGUIObject*>(mCount[0].mpObjMsg), "", 0u, false);
    setInstanceVisible(static_cast<cGUIInstance*>(mCount[1].mpInstAnim), false);
    setObjectMessage(static_cast<cGUIObject*>(mCount[1].mpObjMsg), "", 0u, false);
}

inline uGUIRetry::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIRetry::MyDTI uGUIRetry::DTI("uGUIRetry", &::uGUIBase::DTI, 3248ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIRetry::MyDTI::newInstance() const {
    DDON_STUB("uGUIRetry::MyDTI::newInstance")
    return nullptr;
}

