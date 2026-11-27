// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUIBazaarDealSheet.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "../../XFramework/rSoundRequest.h"
#include "sBazaarManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBazaarDealSheet::getDTI() const {
    return uGUIBazaarDealSheet::DTI;
}

void* uGUIBazaarDealSheet::operator new(size_t sz, u32 align) {
    return uGUIBazaarDealSheet::getAllocator()->memAlloc(sz, align, uGUIBazaarDealSheet::DTI.getID());
}

__attribute__((noinline)) uGUIBazaarDealSheet::~uGUIBazaarDealSheet() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpSNDRes == nullptr) {
        return;
    }
    mpSNDRes->release();
    mpSNDRes = nullptr;
}

void uGUIBazaarDealSheet::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIBazaarDealSheet::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZZAR_DEALSHEET_GUI"), 129u, 1419397593l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZAAR_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpSNDRes == nullptr) && ((mpSNDRes = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_BAZAAR_SRQR"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIBazaarDealSheet::move() {
    mIsCancel = false;
    mIsDecide = false;
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIBazaarDealSheet::setup() {
    DDON_STUB("uGUIBazaarDealSheet::setup")
    /* stub */
}

void uGUIBazaarDealSheet::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes == nullptr) {
        return;
    }
    mpGMDRes->release();
    mpGMDRes = nullptr;
}

__attribute__((weak)) void uGUIBazaarDealSheet::updatePtr() {
}

void uGUIBazaarDealSheet::begin() {
    replacePriority(11u);
    mIsBegin = true;
    mIsShortCut = false;
    setWindowActive(true);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarDealSheet::updateInit);
}

__attribute__((weak)) void uGUIBazaarDealSheet::hide() {
    DDON_STUB("uGUIBazaarDealSheet::hide")
    /* stub */
}

void uGUIBazaarDealSheet::stay() {
    if (mpMenuCtrl != nullptr) {
        mpMenuCtrl->setFocus(false);
    }
    if (mpPageCtrl != nullptr) {
        mpPageCtrl->setFocus(false);
    }
    setWindowActive(false);
    mIsBegin = false;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarDealSheet::updateWait);
}

u32 uGUIBazaarDealSheet::getSelectNo() {
    u32 v0_1 = mCurrentOld;
    unsigned int i0_2 = 0;
    for (u32* v0_3 = &mDealData[0].mTag; i0_2 <= 4u; i0_2 += 1u, v0_3 += 140) {
        if ((*v0_3) == v0_1) {
            return i0_2;
        }
    }
    return 0;
}

u32 uGUIBazaarDealSheet::getSelectTag() {
    return mCurrentOld;
}

s32 uGUIBazaarDealSheet::getSelectBazaarListIdx() {
    return static_cast<s32>((mCurrentOld == 10) ? 0xFFFFFFFFu : mCurrentOld);
}

__attribute__((weak)) void uGUIBazaarDealSheet::createMenuTag() {
    DDON_STUB("uGUIBazaarDealSheet::createMenuTag")
    /* stub */
}

bool uGUIBazaarDealSheet::sortByCustomSort(const uGUIBazaarDealSheet::cListData* src, const uGUIBazaarDealSheet::cListData* dst, u32 param) {
    if (param != 0) {
        if (dst->mSortState < src->mSortState) {
            return false;
        }
    } else {
        if (src->mSortState < dst->mSortState) {
            return false;
        }
    }
    return true;
}

void uGUIBazaarDealSheet::moveInput() {
    if (mpMenuCtrl != nullptr) {
        if (mpMenuCtrl->getFocus()) {
            mpMenuCtrl->execute();
        }
    }
    if (mpPageCtrl != nullptr) {
        if (mpPageCtrl->getFocus()) {
            mNumPageBtn.execute();
            mpPageCtrl->execute();
        }
    }
    if (isBegin()) {
        mCloseButton.execute();
    }
    setPointerPos();
}

void uGUIBazaarDealSheet::moveEvent() {
    u32 t0 = getInputEvent();
    if (static_cast<int>(t0) <= 65) {
        if ((t0 - 52u) > 1u) {
            bool t11 = isBegin();
            if (t11) {
                mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                (&mSaleBtn)->update();
            }
        } else {
            cHorizontalList* t6 = mpPageCtrl;
            s32 t7 = t6->getCurrentPos();
            mPageOld = static_cast<u32>(t7);
            resetMenuCtrl();
            unsigned char t10 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t10 | 1;
            bool t11 = isBegin();
            if (t11) {
                mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                (&mSaleBtn)->update();
            }
        }
    } else {
        switch (t0 - 66u) {
            case 0:
            {
                cVerticalList* t1 = mpMenuCtrl;
                unsigned long t2 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 3120);
                u32 t3 = t1->getCurrentTag();
                if (t2 != 0) {
                    unsigned int t4 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t2 + (static_cast<long>(static_cast<int>(t3)) * 4)) + 0);
                    if (t4 == 10) {
                        unsigned long t5 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t29 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(true);
                        unsigned char t30 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t30 | 1;
                        eventDecide();
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    } else {
                        sBazaarManager* t25 = sBazaarManager::getInstance();
                        unsigned int t26 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t2 + (static_cast<long>(static_cast<int>(t3)) * 4)) + 0);
                        t25->mCharInfoCtrl.mSelectNo = static_cast<s32>(t26);
                        unsigned long t27 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t29 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(false);
                        unsigned char t30 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t30 | 1;
                        eventDecide();
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    }
                } else {
                    if (t3 == 10) {
                        unsigned long t5 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t29 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(true);
                        unsigned char t30 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t30 | 1;
                        eventDecide();
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    } else {
                        sBazaarManager* t25 = sBazaarManager::getInstance();
                        t25->mCharInfoCtrl.mSelectNo = static_cast<s32>(t3);
                        unsigned long t27 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t29 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(false);
                        unsigned char t30 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t30 | 1;
                        eventDecide();
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    }
                }
                break;
            }
            case 1:
            {
                cVerticalList* t13 = mpMenuCtrl;
                t13->setFocus(false);
                mIsCancel = true;
                sGUI* t22 = sGUI::getInstance();
                static_cast<sGUIExt*>(t22)->requestSE(0u, 5u);
                bool t11 = isBegin();
                if (t11) {
                    mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                    (&mSaleBtn)->update();
                }
                break;
            }
            case 3:
            {
                cHorizontalList* t6 = mpPageCtrl;
                s32 t7 = t6->getCurrentPos();
                mPageOld = static_cast<u32>(t7);
                resetMenuCtrl();
                unsigned char t10 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t10 | 1;
                bool t11 = isBegin();
                if (t11) {
                    mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                    (&mSaleBtn)->update();
                }
                break;
            }
            case 4:
            {
                cVerticalList* t15 = mpMenuCtrl;
                unsigned long t16 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t15) + 3120);
                u32 t17 = t15->getCurrentTag();
                if (t16 != 0) {
                    unsigned int t18 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t16 + (static_cast<long>(static_cast<int>(t17)) * 4)) + 0);
                    if (t18 == 10) {
                        unsigned long t19 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t38 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(true);
                        unsigned char t39 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t39 | 1;
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    } else {
                        sBazaarManager* t33 = sBazaarManager::getInstance();
                        unsigned int t34 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t16 + (static_cast<long>(static_cast<int>(t17)) * 4)) + 0);
                        t33->mCharInfoCtrl.mSelectNo = static_cast<s32>(t34);
                        unsigned long t35 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t38 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(false);
                        unsigned char t39 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t39 | 1;
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    }
                } else {
                    if (t17 == 10) {
                        unsigned long t19 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t38 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(true);
                        unsigned char t39 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t39 | 1;
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    } else {
                        sBazaarManager* t33 = sBazaarManager::getInstance();
                        t33->mCharInfoCtrl.mSelectNo = static_cast<s32>(t17);
                        unsigned long t35 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t38 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(false);
                        unsigned char t39 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t39 | 1;
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    }
                }
                break;
            }
            case 5:
            {
                cVerticalList* t20 = mpMenuCtrl;
                t20->setFocus(false);
                mIsCancel = true;
                mIsShortCut = true;
                sGUI* t22 = sGUI::getInstance();
                static_cast<sGUIExt*>(t22)->requestSE(0u, 5u);
                bool t11 = isBegin();
                if (t11) {
                    mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                    (&mSaleBtn)->update();
                }
                break;
            }
            case 6:
            {
                cVerticalList* t1 = mpMenuCtrl;
                unsigned long t2 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 3120);
                u32 t3 = t1->getCurrentTag();
                if (t2 != 0) {
                    unsigned int t4 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t2 + (static_cast<long>(static_cast<int>(t3)) * 4)) + 0);
                    if (t4 == 10) {
                        unsigned long t5 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t29 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(true);
                        unsigned char t30 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t30 | 1;
                        eventDecide();
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    } else {
                        sBazaarManager* t25 = sBazaarManager::getInstance();
                        unsigned int t26 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t2 + (static_cast<long>(static_cast<int>(t3)) * 4)) + 0);
                        t25->mCharInfoCtrl.mSelectNo = static_cast<s32>(t26);
                        unsigned long t27 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t29 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(false);
                        unsigned char t30 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t30 | 1;
                        eventDecide();
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    }
                } else {
                    if (t3 == 10) {
                        unsigned long t5 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t29 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(true);
                        unsigned char t30 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t30 | 1;
                        eventDecide();
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    } else {
                        sBazaarManager* t25 = sBazaarManager::getInstance();
                        t25->mCharInfoCtrl.mSelectNo = static_cast<s32>(t3);
                        unsigned long t27 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144);
                        unsigned long t29 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 5144)) + 120);
                        (&mSaleBtn)->setFocus(false);
                        unsigned char t30 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980);
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5980) = t30 | 1;
                        eventDecide();
                        bool t11 = isBegin();
                        if (t11) {
                            mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                            (&mSaleBtn)->update();
                        }
                    }
                }
                break;
            }
            default:
            {
                bool t11 = isBegin();
                if (t11) {
                    mCloseButton.uGUIBase::cReferenceUICloseBtn::update();
                    (&mSaleBtn)->update();
                }
                break;
            }
        }
    }
}

__attribute__((weak)) void uGUIBazaarDealSheet::updateInit() {
    DDON_STUB("uGUIBazaarDealSheet::updateInit")
    /* stub */
}

void uGUIBazaarDealSheet::updateMove() {
    updateDealList();
    mDealData[0].mItemIcon.uGUIBase::cReferenceUIIconItem::update();
    mDealData[1].mItemIcon.uGUIBase::cReferenceUIIconItem::update();
    mDealData[2].mItemIcon.uGUIBase::cReferenceUIIconItem::update();
    mDealData[3].mItemIcon.uGUIBase::cReferenceUIIconItem::update();
    mDealData[4].mItemIcon.uGUIBase::cReferenceUIIconItem::update();
    mNumPageBtn.uGUIBase::cReferenceUINumPager::update();
    mButtonGuide.uGUIBase::cReferenceUIBtnGuide::update();
}

__attribute__((weak)) void uGUIBazaarDealSheet::updateWait() {
}

__attribute__((weak)) void uGUIBazaarDealSheet::initialize() {
    DDON_STUB("uGUIBazaarDealSheet::initialize")
    /* stub */
}

u32 uGUIBazaarDealSheet::evCtrlSelectMenu(cControl::Message* msg) {
    setInputEvent(70u);
    return 0;
}

u32 uGUIBazaarDealSheet::evCtrlDecideMenu(cControl::Message* msg) {
    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
        if (msg->mouse_hit_id == 10) {
            mpMenuCtrl->setCurrentPos(0, false);
            setInputEvent(72u);
        } else {
            setInputEvent(66u);
        }
    } else {
        setInputEvent(66u);
    }
    return 0;
}

u32 uGUIBazaarDealSheet::evCtrlCancelMenu(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIBazaarDealSheet::evCtrlShortCut(cControl::Message* msg) {
    setInputEvent(71u);
    return 0;
}

u32 uGUIBazaarDealSheet::evCtrlSelectPage(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

__attribute__((weak)) void uGUIBazaarDealSheet::updateDealList() {
    DDON_STUB("uGUIBazaarDealSheet::updateDealList")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarDealSheet::setPointerPos() {
    DDON_STUB("uGUIBazaarDealSheet::setPointerPos")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarDealSheet::resetMenuCtrl() {
    DDON_STUB("uGUIBazaarDealSheet::resetMenuCtrl")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarDealSheet::eventDecide() {
    DDON_STUB("uGUIBazaarDealSheet::eventDecide")
    /* stub */
}

inline uGUIBazaarDealSheet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarDealSheet::MyDTI uGUIBazaarDealSheet::DTI("uGUIBazaarDealSheet", &::uGUIBase::DTI, 6032ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBazaarDealSheet::MyDTI::newInstance() const {
    DDON_STUB("uGUIBazaarDealSheet::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBazaarDealSheet::cDealData::getDTI() const {
    return uGUIBazaarDealSheet::cDealData::DTI;
}

inline uGUIBazaarDealSheet::cDealData::cDealData() : mpInstDealNull(static_cast<cGUIInstance*>(nullptr)) {
    memset(static_cast<void*>(&mpInstAnimDealList), 0, 156ul);
}

uGUIBazaarDealSheet::cDealData::~cDealData() {
}

inline uGUIBazaarDealSheet::cDealData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarDealSheet::cDealData::MyDTI uGUIBazaarDealSheet::cDealData::DTI("uGUIBazaarDealSheet::cDealData", &::MtObject::DTI, 560ul, 0u, 0u);

MtObject* uGUIBazaarDealSheet::cDealData::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarDealSheet::cDealData;
}

const MtDTI& uGUIBazaarDealSheet::cListData::getDTI() const {
    return uGUIBazaarDealSheet::cListData::DTI;
}

inline uGUIBazaarDealSheet::cListData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarDealSheet::cListData::MyDTI uGUIBazaarDealSheet::cListData::DTI("uGUIBazaarDealSheet::cListData", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* uGUIBazaarDealSheet::cListData::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarDealSheet::cListData;
}

