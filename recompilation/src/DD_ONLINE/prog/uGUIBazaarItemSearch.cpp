// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIBazaarItemSearch.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCharSet.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtFunctionReplacement.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "sBazaarManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIPopBase.h"
#include "uGUIPopDetail01.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBazaarItemSearch::getDTI() const {
    return uGUIBazaarItemSearch::DTI;
}

void* uGUIBazaarItemSearch::operator new(size_t sz, u32 align) {
    return uGUIBazaarItemSearch::getAllocator()->memAlloc(sz, align, uGUIBazaarItemSearch::DTI.getID());
}

__attribute__((noinline)) uGUIBazaarItemSearch::~uGUIBazaarItemSearch() {
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

void uGUIBazaarItemSearch::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "開始", static_cast<MT_MFUNC>(&::uGUIBazaarItemSearch::begin), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "終了", static_cast<MT_MFUNC>(&::uGUIBazaarItemSearch::hide), 10u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "Filter", reinterpret_cast<MT_MFUNC>(&::uGUIBazaarItemSearch::getKeyword), reinterpret_cast<MT_MFUNC>(&::uGUIBazaarItemSearch::setKeyword), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

bool uGUIBazaarItemSearch::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZZAR_ITEMSEARCH_GUI"), 129u, 1419397670l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZAAR_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIBazaarItemSearch::move() {
    mIsCancel = false;
    mIsDecide = false;
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIBazaarItemSearch::setup() {
    DDON_STUB("uGUIBazaarItemSearch::setup")
    /* stub */
}

void uGUIBazaarItemSearch::kill() {
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

void uGUIBazaarItemSearch::updatePtr() {
    if (mpItemDetail == nullptr) {
        return;
    }
    if (mpItemDetail->isEnable()) {
        return;
    }
    mpItemDetail = nullptr;
}

__attribute__((weak)) void uGUIBazaarItemSearch::begin() {
    DDON_STUB("uGUIBazaarItemSearch::begin")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarItemSearch::hide() {
    DDON_STUB("uGUIBazaarItemSearch::hide")
    /* stub */
}

void uGUIBazaarItemSearch::stay() {
    mFocus = false;
    mpItemListCtrl->setFocus(false);
    mpPageCtrl->setFocus(false);
    setWindowActive(false);
    mpMenuCtrl->setFocus(false);
    mpHnumboxCtrl->setFocus(false);
    mpCategoryCtrl->setFocus(false);
    mpItemListCtrl->setFocus(false);
    mpPageCtrl->setFocus(false);
    mStay = true;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateWait);
}

void uGUIBazaarItemSearch::beginList() {
    replacePriority(11u);
    setWindowActive(true);
    mpMenuCtrl->setFocus(true);
    if (mpMenuCtrl != nullptr) {
        mpMenuCtrl->mCtrlF = mpMenuCtrl->mCtrlF | 8u;
    }
    mpHnumboxCtrl->setFocus(true);
    if (mpHnumboxCtrl != nullptr) {
        mpHnumboxCtrl->mCtrlF = mpHnumboxCtrl->mCtrlF | 8u;
    }
    mpCategoryCtrl->setFocus(true);
    if (mpCategoryCtrl != nullptr) {
        mpCategoryCtrl->mCtrlF = mpCategoryCtrl->mCtrlF | 8u;
    }
    mpItemListCtrl->setFocus(true);
    mpPageCtrl->setFocus(true);
    mFocus = false;
    mpItemListCtrl->setFocus(false);
    mpPageCtrl->setFocus(false);
    mStay = false;
    mIsBegin = true;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
}

void uGUIBazaarItemSearch::setDetailPos(MtVector3& pos) {
    mDetailPos = pos;
}

__attribute__((weak)) void uGUIBazaarItemSearch::setKeyword(MtString& keyword) {
    DDON_STUB("uGUIBazaarItemSearch::setKeyword")
    /* stub */
}

MT_CTSTR uGUIBazaarItemSearch::getKeyword() {
    return mFreeword.ptr();
}

__attribute__((weak)) void uGUIBazaarItemSearch::setFreeword(MtString& str) {
    DDON_STUB("uGUIBazaarItemSearch::setFreeword")
    /* stub */
}

bool uGUIBazaarItemSearch::sortByID(const uGUIBazaarItemSearch::cSearchItemData* src, const uGUIBazaarItemSearch::cSearchItemData* dst, u32 param) {
    if (param == 1) {
        if (dst->mSortNo < src->mSortNo) {
            return true;
        } else {
            return false;
        }
    } else {
        if (src->mSortNo >= dst->mSortNo) {
            return false;
        } else {
            return true;
        }
    }
}

__attribute__((weak)) void uGUIBazaarItemSearch::moveInput() {
    DDON_STUB("uGUIBazaarItemSearch::moveInput")
    /* stub */
}

void uGUIBazaarItemSearch::moveEvent() {
    if (!mCateBigPullDown.moveEvent()) {
        if (!mCateSmallPullDown.moveEvent()) {
            switch (getInputEvent() - 52u) {
                case 0:
                {
                    evSelectPage();
                    mNumBoxBtn.moveEvent();
                    break;
                }
                case 1:
                {
                    evSelectPage();
                    mNumBoxBtn.moveEvent();
                    break;
                }
                case 14:
                {
                    mItemSelCursor.setCtrlPos(mpItemListCtrl->getCurrentPos(), false);
                    s32 t0 = mpItemListCtrl->getCurrentPos();
                    s32 t1 = mListTopOld;
                    sBazaarManager::getInstance()->mItemListCtrl.setSelectNo(t0 + t1);
                    if (static_cast<unsigned int>(t0 + t1) < sBazaarManager::getInstance()->mItemListCtrl.mItemList.mLength) {
                        if (sBazaarManager::getInstance()->mItemListCtrl.mItemList.mpArray[static_cast<unsigned int>(t0 + t1)] != nullptr) {
                            mIsDecide = true;
                            static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                            if (mpItemDetail != nullptr) {
                                mpItemDetail->kill();
                                mpItemDetail = nullptr;
                                mNumBoxBtn.moveEvent();
                            } else {
                                mNumBoxBtn.moveEvent();
                            }
                        } else {
                            mNumBoxBtn.moveEvent();
                        }
                    } else {
                        mNumBoxBtn.moveEvent();
                    }
                    break;
                }
                case 15:
                {
                    if (mpItemListCtrl->getFocus()) {
                        cGUIObjMessage* t2 = mpObjMsgSearchAnnounce;
                        setObjectMessage(static_cast<cGUIObject*>(t2), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 80u), 0u, false);
                        retSearchToMove();
                        mIsCancel = true;
                        mNumBoxBtn.moveEvent();
                    } else {
                        mIsCancel = true;
                        mNumBoxBtn.moveEvent();
                    }
                    break;
                }
                case 17:
                {
                    evSelectPage();
                    mNumBoxBtn.moveEvent();
                    break;
                }
                case 18:
                {
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    if (mpMenuCtrl != nullptr) {
                        mpMenuCtrl->mCtrlF = mpMenuCtrl->mCtrlF | 8u;
                        if (mpCategoryCtrl != nullptr) {
                            mpCategoryCtrl->mCtrlF = mpCategoryCtrl->mCtrlF | 8u;
                            if (mpHnumboxCtrl != nullptr) {
                                mpHnumboxCtrl->mCtrlF = mpHnumboxCtrl->mCtrlF | 8u;
                                createSearchItemList();
                                if (mIsSearchOver) {
                                    sGUI* t3 = sGUI::getInstance();
                                    static_cast<sGUIExt*>(t3)->requestAnnounce(static_cast<sGUIExt*>(t3)->getMsgFromIdxInfo(mpGMDRes, 92u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                                    mIsSearchOver = false;
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                } else {
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                }
                            } else {
                                createSearchItemList();
                                if (mIsSearchOver) {
                                    sGUI* t3 = sGUI::getInstance();
                                    static_cast<sGUIExt*>(t3)->requestAnnounce(static_cast<sGUIExt*>(t3)->getMsgFromIdxInfo(mpGMDRes, 92u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                                    mIsSearchOver = false;
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                } else {
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                }
                            }
                        } else {
                            if (mpHnumboxCtrl != nullptr) {
                                mpHnumboxCtrl->mCtrlF = mpHnumboxCtrl->mCtrlF | 8u;
                                createSearchItemList();
                                if (mIsSearchOver) {
                                    sGUI* t3 = sGUI::getInstance();
                                    static_cast<sGUIExt*>(t3)->requestAnnounce(static_cast<sGUIExt*>(t3)->getMsgFromIdxInfo(mpGMDRes, 92u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                                    mIsSearchOver = false;
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                } else {
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                }
                            } else {
                                createSearchItemList();
                                if (mIsSearchOver) {
                                    sGUI* t3 = sGUI::getInstance();
                                    static_cast<sGUIExt*>(t3)->requestAnnounce(static_cast<sGUIExt*>(t3)->getMsgFromIdxInfo(mpGMDRes, 92u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                                    mIsSearchOver = false;
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                } else {
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                }
                            }
                        }
                    } else {
                        if (mpCategoryCtrl != nullptr) {
                            mpCategoryCtrl->mCtrlF = mpCategoryCtrl->mCtrlF | 8u;
                            if (mpHnumboxCtrl != nullptr) {
                                mpHnumboxCtrl->mCtrlF = mpHnumboxCtrl->mCtrlF | 8u;
                                createSearchItemList();
                                if (mIsSearchOver) {
                                    sGUI* t3 = sGUI::getInstance();
                                    static_cast<sGUIExt*>(t3)->requestAnnounce(static_cast<sGUIExt*>(t3)->getMsgFromIdxInfo(mpGMDRes, 92u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                                    mIsSearchOver = false;
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                } else {
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                }
                            } else {
                                createSearchItemList();
                                if (mIsSearchOver) {
                                    sGUI* t3 = sGUI::getInstance();
                                    static_cast<sGUIExt*>(t3)->requestAnnounce(static_cast<sGUIExt*>(t3)->getMsgFromIdxInfo(mpGMDRes, 92u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                                    mIsSearchOver = false;
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                } else {
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                }
                            }
                        } else {
                            if (mpHnumboxCtrl != nullptr) {
                                mpHnumboxCtrl->mCtrlF = mpHnumboxCtrl->mCtrlF | 8u;
                                createSearchItemList();
                                if (mIsSearchOver) {
                                    sGUI* t3 = sGUI::getInstance();
                                    static_cast<sGUIExt*>(t3)->requestAnnounce(static_cast<sGUIExt*>(t3)->getMsgFromIdxInfo(mpGMDRes, 92u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                                    mIsSearchOver = false;
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                } else {
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                }
                            } else {
                                createSearchItemList();
                                if (mIsSearchOver) {
                                    sGUI* t3 = sGUI::getInstance();
                                    static_cast<sGUIExt*>(t3)->requestAnnounce(static_cast<sGUIExt*>(t3)->getMsgFromIdxInfo(mpGMDRes, 92u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                                    mIsSearchOver = false;
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                } else {
                                    if (mpPageCtrl != nullptr) {
                                        mpPageCtrl->setCurrentPos(0, false);
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    } else {
                                        mpItemListCtrl->setCurrentPos(0, false);
                                        mItemSelCursor.setCtrlPos(0, false);
                                        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateSearch);
                                        mNumBoxBtn.moveEvent();
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
                case 19:
                {
                    eventSelectRank();
                    mNumBoxBtn.moveEvent();
                    break;
                }
                case 20:
                {
                    eventSelectRank();
                    mNumBoxBtn.moveEvent();
                    break;
                }
                case 21:
                {
                    eventSelectRank();
                    mNumBoxBtn.moveEvent();
                    break;
                }
                case 22:
                {
                    mItemSelCursor.setCtrlPos(mpItemListCtrl->getCurrentPos(), false);
                    mNumBoxBtn.moveEvent();
                    break;
                }
                case 23:
                {
                    mNumBoxBtn.setMode(uGUIBase::cReferenceUINumBox::MODE_EDIT);
                    mpMenuCtrl->setFocus(false);
                    mpHnumboxCtrl->setFocus(false);
                    mpCategoryCtrl->setFocus(false);
                    mNumBoxBtn.moveEvent();
                    break;
                }
                case 24:
                {
                    eventSelectRank();
                    mNumBoxBtn.setMode(uGUIBase::cReferenceUINumBox::MODE_EDIT);
                    mpMenuCtrl->setFocus(false);
                    mpHnumboxCtrl->setFocus(false);
                    mpCategoryCtrl->setFocus(false);
                    mNumBoxBtn.moveEvent();
                    break;
                }
                default:
                {
                    mNumBoxBtn.moveEvent();
                    break;
                }
            }
        } else {
            mNumBoxBtn.moveEvent();
        }
    } else {
        mNumBoxBtn.moveEvent();
    }
}

__attribute__((weak)) void uGUIBazaarItemSearch::adjustScale() {
    DDON_STUB("uGUIBazaarItemSearch::adjustScale")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarItemSearch::updateInit() {
    DDON_STUB("uGUIBazaarItemSearch::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarItemSearch::updateMove() {
    DDON_STUB("uGUIBazaarItemSearch::updateMove")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarItemSearch::updateFreeWordWait() {
    DDON_STUB("uGUIBazaarItemSearch::updateFreeWordWait")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarItemSearch::updateSearch() {
    DDON_STUB("uGUIBazaarItemSearch::updateSearch")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarItemSearch::retSearchToMove() {
    DDON_STUB("uGUIBazaarItemSearch::retSearchToMove")
    /* stub */
}

void uGUIBazaarItemSearch::updateWait() {
    mItemSelCursor.uGUIBase::cReferenceUIVlCursor::update();
}

__attribute__((weak)) void uGUIBazaarItemSearch::initialize() {
    DDON_STUB("uGUIBazaarItemSearch::initialize")
    /* stub */
}

u32 uGUIBazaarItemSearch::evCtrlSelectCategory(cControl::Message* msg) {
    setInputEvent(68u);
    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 1) {
            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
        } else {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 0) {
                mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
            }
        }
    } else {
        if (msg->pSender->getCurrentTag() == 1) {
            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
        } else {
            if (msg->pSender->getCurrentTag() == 0) {
                mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
            }
        }
    }
    return 0;
}

u32 uGUIBazaarItemSearch::evCtrlDecideCategory(cControl::Message* msg) {
    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
        if (msg->mouse_hit_id > -1) {
            if (mpItemListCtrl->getFocus()) {
                static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 5u);
                cGUIObjMessage* t0 = mpObjMsgSearchAnnounce;
                setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 80u), 0u, false);
                retSearchToMove();
                setInputEvent(68u);
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 1) {
                        mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                        mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                        mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                        mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                        mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                        mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                        mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                        if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 6573)) == 0) {
                            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 6496)) == 0) {
                                mCateSmallPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                            }
                        }
                        mpCategoryCtrl->setFocus(false);
                        mpMenuCtrl->setFocus(false);
                        mpHnumboxCtrl->setFocus(false);
                    } else {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 0) {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                            if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5021)) == 0) {
                                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4944)) == 0) {
                                    mCateBigPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                                }
                            }
                            mpCategoryCtrl->setFocus(false);
                            mpMenuCtrl->setFocus(false);
                            mpHnumboxCtrl->setFocus(false);
                        }
                    }
                } else {
                    if (msg->pSender->getCurrentTag() == 1) {
                        mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                        mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                        mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                        mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                        mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                        mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                        mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                        if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 6573)) == 0) {
                            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 6496)) == 0) {
                                mCateSmallPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                            }
                        }
                        mpCategoryCtrl->setFocus(false);
                        mpMenuCtrl->setFocus(false);
                        mpHnumboxCtrl->setFocus(false);
                    } else {
                        if (msg->pSender->getCurrentTag() == 0) {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                            if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5021)) == 0) {
                                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4944)) == 0) {
                                    mCateBigPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                                }
                            }
                            mpCategoryCtrl->setFocus(false);
                            mpMenuCtrl->setFocus(false);
                            mpHnumboxCtrl->setFocus(false);
                        }
                    }
                }
                return 0;
            }
            setInputEvent(68u);
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 1) {
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                    if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 6573)) == 0) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 6496)) == 0) {
                            mCateSmallPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                        }
                    }
                    mpCategoryCtrl->setFocus(false);
                    mpMenuCtrl->setFocus(false);
                    mpHnumboxCtrl->setFocus(false);
                } else {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 0) {
                        mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                        mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                        mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                        mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                        mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                        mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                        mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                        if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5021)) == 0) {
                            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4944)) == 0) {
                                mCateBigPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                            }
                        }
                        mpCategoryCtrl->setFocus(false);
                        mpMenuCtrl->setFocus(false);
                        mpHnumboxCtrl->setFocus(false);
                    }
                }
            } else {
                if (msg->pSender->getCurrentTag() == 1) {
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                    if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 6573)) == 0) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 6496)) == 0) {
                            mCateSmallPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                        }
                    }
                    mpCategoryCtrl->setFocus(false);
                    mpMenuCtrl->setFocus(false);
                    mpHnumboxCtrl->setFocus(false);
                } else {
                    if (msg->pSender->getCurrentTag() == 0) {
                        mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                        mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                        mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                        mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                        mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                        mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                        mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                        if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5021)) == 0) {
                            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4944)) == 0) {
                                mCateBigPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                            }
                        }
                        mpCategoryCtrl->setFocus(false);
                        mpMenuCtrl->setFocus(false);
                        mpHnumboxCtrl->setFocus(false);
                    }
                }
            }
        }
    } else {
        setInputEvent(68u);
        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 1) {
                mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 6573)) == 0) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 6496)) == 0) {
                        mCateSmallPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                    }
                }
                mpCategoryCtrl->setFocus(false);
                mpMenuCtrl->setFocus(false);
                mpHnumboxCtrl->setFocus(false);
            } else {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) == 0) {
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                    if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5021)) == 0) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4944)) == 0) {
                            mCateBigPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                        }
                    }
                    mpCategoryCtrl->setFocus(false);
                    mpMenuCtrl->setFocus(false);
                    mpHnumboxCtrl->setFocus(false);
                }
            }
        } else {
            if (msg->pSender->getCurrentTag() == 1) {
                mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 6573)) == 0) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 6496)) == 0) {
                        mCateSmallPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                    }
                }
                mpCategoryCtrl->setFocus(false);
                mpMenuCtrl->setFocus(false);
                mpHnumboxCtrl->setFocus(false);
            } else {
                if (msg->pSender->getCurrentTag() == 0) {
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(true);
                    if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 5021)) == 0) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4944)) == 0) {
                            mCateBigPullDown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                        }
                    }
                    mpCategoryCtrl->setFocus(false);
                    mpMenuCtrl->setFocus(false);
                    mpHnumboxCtrl->setFocus(false);
                }
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 uGUIBazaarItemSearch::evCtrlSelectMenu(cControl::Message* msg) {
    DDON_STUB("uGUIBazaarItemSearch::evCtrlSelectMenu")
    return {};
}

__attribute__((weak)) u32 uGUIBazaarItemSearch::evCtrlLRSelectMenu(cControl::Message* msg) {
    DDON_STUB("uGUIBazaarItemSearch::evCtrlLRSelectMenu")
    return {};
}

u32 uGUIBazaarItemSearch::evCtrlDecideMenu(cControl::Message* msg) {
    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
        if (msg->mouse_hit_id > -1) {
            if (mpItemListCtrl->getFocus()) {
                static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 5u);
                cGUIObjMessage* t0 = mpObjMsgSearchAnnounce;
                setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 80u), 0u, false);
                retSearchToMove();
                setInputEvent(68u);
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
                    switch (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) {
                        case 0:
                        {
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            return 0;
                        }
                        case 1:
                        {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
                            return 0;
                        }
                        case 2:
                        {
                            if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                                evCtrlSelectMenu(msg);
                                setInputEvent(70u);
                                return 0;
                            } else {
                                setInputEvent(70u);
                                return 0;
                            }
                            break;
                        }
                        case 3:
                        {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
                            mTextBox.wakeupKeyboard();
                            mpMenuCtrl->setFocus(false);
                            mpCategoryCtrl->setFocus(false);
                            mpHnumboxCtrl->setFocus(false);
                            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateFreeWordWait);
                            return 0;
                        }
                        case 4:
                        {
                            if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                                evCtrlSelectMenu(msg);
                                setInputEvent(70u);
                                return 0;
                            } else {
                                setInputEvent(70u);
                                return 0;
                            }
                            break;
                        }
                        default:
                        {
                            return 0;
                        }
                    }
                } else {
                    switch (msg->pSender->getCurrentTag()) {
                        case 0:
                        {
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            return 0;
                        }
                        case 1:
                        {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
                            return 0;
                        }
                        case 2:
                        {
                            if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                                evCtrlSelectMenu(msg);
                                setInputEvent(70u);
                                return 0;
                            } else {
                                setInputEvent(70u);
                                return 0;
                            }
                            break;
                        }
                        case 3:
                        {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
                            mTextBox.wakeupKeyboard();
                            mpMenuCtrl->setFocus(false);
                            mpCategoryCtrl->setFocus(false);
                            mpHnumboxCtrl->setFocus(false);
                            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateFreeWordWait);
                            return 0;
                        }
                        case 4:
                        {
                            if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                                evCtrlSelectMenu(msg);
                                setInputEvent(70u);
                                return 0;
                            } else {
                                setInputEvent(70u);
                                return 0;
                            }
                            break;
                        }
                        default:
                        {
                            return 0;
                        }
                    }
                }
            } else {
                setInputEvent(68u);
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
                    switch (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) {
                        case 0:
                        {
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            return 0;
                        }
                        case 1:
                        {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
                            return 0;
                        }
                        case 2:
                        {
                            if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                                evCtrlSelectMenu(msg);
                                setInputEvent(70u);
                                return 0;
                            } else {
                                setInputEvent(70u);
                                return 0;
                            }
                            break;
                        }
                        case 3:
                        {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
                            mTextBox.wakeupKeyboard();
                            mpMenuCtrl->setFocus(false);
                            mpCategoryCtrl->setFocus(false);
                            mpHnumboxCtrl->setFocus(false);
                            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateFreeWordWait);
                            return 0;
                        }
                        case 4:
                        {
                            if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                                evCtrlSelectMenu(msg);
                                setInputEvent(70u);
                                return 0;
                            } else {
                                setInputEvent(70u);
                                return 0;
                            }
                            break;
                        }
                        default:
                        {
                            return 0;
                        }
                    }
                } else {
                    switch (msg->pSender->getCurrentTag()) {
                        case 0:
                        {
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            return 0;
                        }
                        case 1:
                        {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
                            return 0;
                        }
                        case 2:
                        {
                            if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                                evCtrlSelectMenu(msg);
                                setInputEvent(70u);
                                return 0;
                            } else {
                                setInputEvent(70u);
                                return 0;
                            }
                            break;
                        }
                        case 3:
                        {
                            mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                            mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                            mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
                            mTextBox.wakeupKeyboard();
                            mpMenuCtrl->setFocus(false);
                            mpCategoryCtrl->setFocus(false);
                            mpHnumboxCtrl->setFocus(false);
                            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateFreeWordWait);
                            return 0;
                        }
                        case 4:
                        {
                            if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                                evCtrlSelectMenu(msg);
                                setInputEvent(70u);
                                return 0;
                            } else {
                                setInputEvent(70u);
                                return 0;
                            }
                            break;
                        }
                        default:
                        {
                            return 0;
                        }
                    }
                }
            }
        } else {
            return 0;
        }
    } else {
        setInputEvent(68u);
        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) != 0) {
            switch (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(msg->pSender) + 3120)) + (static_cast<long>(static_cast<int>(msg->pSender->getCurrentTag())) * 4)) + 0)) {
                case 0:
                {
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    return 0;
                }
                case 1:
                {
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
                    return 0;
                }
                case 2:
                {
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlSelectMenu(msg);
                        setInputEvent(70u);
                        return 0;
                    } else {
                        setInputEvent(70u);
                        return 0;
                    }
                    break;
                }
                case 3:
                {
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
                    mTextBox.wakeupKeyboard();
                    mpMenuCtrl->setFocus(false);
                    mpCategoryCtrl->setFocus(false);
                    mpHnumboxCtrl->setFocus(false);
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateFreeWordWait);
                    return 0;
                }
                case 4:
                {
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlSelectMenu(msg);
                        setInputEvent(70u);
                        return 0;
                    } else {
                        setInputEvent(70u);
                        return 0;
                    }
                    break;
                }
                default:
                {
                    return 0;
                }
            }
        } else {
            switch (msg->pSender->getCurrentTag()) {
                case 0:
                {
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    return 0;
                }
                case 1:
                {
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
                    return 0;
                }
                case 2:
                {
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlSelectMenu(msg);
                        setInputEvent(70u);
                        return 0;
                    } else {
                        setInputEvent(70u);
                        return 0;
                    }
                    break;
                }
                case 3:
                {
                    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
                    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(false);
                    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
                    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
                    mTextBox.wakeupKeyboard();
                    mpMenuCtrl->setFocus(false);
                    mpCategoryCtrl->setFocus(false);
                    mpHnumboxCtrl->setFocus(false);
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaarItemSearch::updateFreeWordWait);
                    return 0;
                }
                case 4:
                {
                    if (msg->reason == nGUIExt::MOUSE_LCLICK) {
                        evCtrlSelectMenu(msg);
                        setInputEvent(70u);
                        return 0;
                    } else {
                        setInputEvent(70u);
                        return 0;
                    }
                    break;
                }
                default:
                {
                    return 0;
                }
            }
        }
    }
}

u32 uGUIBazaarItemSearch::evCtrlCancelMenu(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIBazaarItemSearch::evCtrlSelectList(cControl::Message* msg) {
    setInputEvent(74u);
    return 0;
}

u32 uGUIBazaarItemSearch::evCtrlDecideList(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

u32 uGUIBazaarItemSearch::evCtrlCancelList(cControl::Message* msg) {
    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 5u);
    cGUIObjMessage* t0 = mpObjMsgSearchAnnounce;
    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 80u), 0u, false);
    retSearchToMove();
    return 0;
}

u32 uGUIBazaarItemSearch::evCtrlSelectPage(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

u32 uGUIBazaarItemSearch::evCtrlStartMenu(cControl::Message* msg) {
    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpMenuCtrl) + 3120)) != 0) {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpMenuCtrl) + 3120)) + (static_cast<long>(static_cast<int>(mpMenuCtrl->getCurrentTag())) * 4)) + 0)) == 1) {
            setInputEvent(75u);
        }
    } else {
        if (mpMenuCtrl->getCurrentTag() == 1) {
            setInputEvent(75u);
        }
    }
    return 0;
}

__attribute__((weak)) void uGUIBazaarItemSearch::evSelectPage() {
    s32 listNum = sBazaarManager::getInstance()->mItemListCtrl.mItemList.mLength;
    unsigned int v0_0;
    if (mpPageCtrl == nullptr) {
        v0_0 = 0;
    } else {
        v0_0 = mpPageCtrl->mCurrentPos * 10;
    }
    cVerticalList* v4_2 = mpItemListCtrl;
    s32 t0 = v4_2->getCurrentPos();
    unsigned int v7_3;
    if ((listNum - v0_0) > 9u) {
        s32 v3_10;
        if (v4_2 == nullptr) {
            v3_10 = t0;
        } else {
            v4_2->clearMouseTouchList();
            mpItemListCtrl->resetItemNum(10, static_cast<const u32*>(nullptr), t0);
            for (unsigned int i1_10 = 0; i1_10 != 10; i1_10 = i1_10 + 1u) {
                cGUIObjPolygon* t1 = mItemData[i1_10].mpObjMouseOver;
                cGUIUtility::AdjustMouseCollisionSize(t1, mItemSelCursor.getDistY());
                mpItemListCtrl->addMouseTouchList(static_cast<cGUIInstance*>(mItemData[i1_10].mpInstAnimMsgList), static_cast<cGUIObject*>(t1), static_cast<s32>(i1_10), static_cast<cGUIObject*>(nullptr), 1u, 1u, -1);
            }
            v3_10 = mpItemListCtrl->getCurrentPos();
        }
        v7_3 = v3_10;
    } else {
        s32 v4_4;
        if (t0 < static_cast<int>(listNum - v0_0)) {
            listNum = listNum - v0_0;
            v4_4 = t0;
        } else {
            v4_4 = (static_cast<int>((listNum - v0_0) - 1u) <= -1) ? 0u : ((listNum - v0_0) - 1u);
            listNum = listNum - v0_0;
        }
        if (v4_2 != nullptr) {
            if (static_cast<unsigned int>(listNum) <= 10) {
                v4_2->clearMouseTouchList();
                mpItemListCtrl->resetItemNum(listNum, static_cast<const u32*>(nullptr), v4_4);
                if (listNum > 0) {
                    for (unsigned int i5_10 = 0;;) {
                        cGUIObjPolygon* t2 = mItemData[i5_10].mpObjMouseOver;
                        cGUIUtility::AdjustMouseCollisionSize(t2, mItemSelCursor.getDistY());
                        mpItemListCtrl->addMouseTouchList(static_cast<cGUIInstance*>(mItemData[i5_10].mpInstAnimMsgList), static_cast<cGUIObject*>(t2), static_cast<s32>(i5_10), static_cast<cGUIObject*>(nullptr), 1u, 1u, -1);
                        if (listNum != static_cast<int>(i5_10 + 1u)) {
                            i5_10 += 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        v7_3 = mpItemListCtrl->getCurrentPos();
    }
    mItemSelCursor.setCtrlPos(static_cast<s32>(v7_3), false);
}

__attribute__((weak)) void uGUIBazaarItemSearch::clearItemList() {
    DDON_STUB("uGUIBazaarItemSearch::clearItemList")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarItemSearch::setItem(u32 index, sBazaarManager::cBazaarItemListData* pListData) {
    DDON_STUB("uGUIBazaarItemSearch::setItem")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarItemSearch::createItemDetail() {
    DDON_STUB("uGUIBazaarItemSearch::createItemDetail")
    /* stub */
}

__attribute__((weak)) bool uGUIBazaarItemSearch::createSearchItemList() {
    DDON_STUB("uGUIBazaarItemSearch::createSearchItemList")
    return {};
}

__attribute__((weak)) void uGUIBazaarItemSearch::updateItemIcon() {
    DDON_STUB("uGUIBazaarItemSearch::updateItemIcon")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarItemSearch::eventSelectRank() {
    if (mpHnumboxCtrl != nullptr) {
        mpHnumboxCtrl->mCtrlF = mpHnumboxCtrl->mCtrlF & 0xFFFFFFF7u;
    }
    if (mpCategoryCtrl != nullptr) {
        mpCategoryCtrl->mCtrlF = mpCategoryCtrl->mCtrlF | 8u;
    }
    mCateSmallPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
    mCateBigPullDown.uGUIBase::cReferenceUIPullDown::setFocus(false);
    if (getInputEvent() == 71) {
        mNumBoxBtn.pushLArrow(-1);
    }
    if (getInputEvent() == 72) {
        mNumBoxBtn.pushRArrow(1);
    }
    mNumBoxBtn.uGUIBase::cReferenceUINumBox::setFocus(true);
    mCateSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
    mFreeSearchBtn.uGUIBase::cReferenceUIButton::setFocus(false);
    mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
}

inline uGUIBazaarItemSearch::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarItemSearch::MyDTI uGUIBazaarItemSearch::DTI("uGUIBazaarItemSearch", &::uGUIBase::DTI, 12880ul, 0u, 0u);

alignas(4) unsigned char uGUIBazaarItemSearch_mCategoryTag_bytes[8] __asm__("_ZN20uGUIBazaarItemSearch12mCategoryTagE") = {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};

alignas(4) unsigned char uGUIBazaarItemSearch_mMenuTag_bytes[20] __asm__("_ZN20uGUIBazaarItemSearch8mMenuTagE") = {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTag1None_bytes[5] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTag1NoneE") = {0x02, 0x01, 0x03, 0x0d, 0x13};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTag2None_bytes[3] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTag2NoneE") = {0x0e, 0x11, 0x12};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTag3None_bytes[6] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTag3NoneE") = {0x07, 0x08, 0x09, 0x0a, 0x0c, 0x16};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTag4None_bytes[3] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTag4NoneE") = {0x04, 0x05, 0x06};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTag5None_bytes[5] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTag5NoneE") = {0x14, 0x17, 0x1d, 0x1e, 0x1c};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTag6None_bytes[2] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTag6NoneE") = {0x18, 0x19};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTag7None_bytes[2] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTag7NoneE") = {0x1a, 0x1b};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTag8None_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTag8NoneE") = {0x1e};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagStone_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTagStoneE") = {0x02};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagMetal_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTagMetalE") = {0x01};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagSand_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch12mMenuTagSandE") = {0x03};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagJewel_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTagJewelE") = {0x0d};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagLiquid_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch14mMenuTagLiquidE") = {0x13};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagGrass_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTagGrassE") = {0x0e};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagMushroom_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch16mMenuTagMushroomE") = {0x11};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagWoodchip_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch16mMenuTagWoodchipE") = {0x12};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagBark_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch12mMenuTagBarkE") = {0x07};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagBone_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch12mMenuTagBoneE") = {0x08};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagFang_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch12mMenuTagFangE") = {0x09};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagHorn_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch12mMenuTagHornE") = {0x0a};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagWing_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch12mMenuTagWingE") = {0x0c};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagMeat_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch12mMenuTagMeatE") = {0x16};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagCloth_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTagClothE") = {0x04};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagThread_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch14mMenuTagThreadE") = {0x05};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagWool_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch12mMenuTagWoolE") = {0x06};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagBanderole_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch17mMenuTagBanderoleE") = {0x14};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagOther_bytes[3] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTagOtherE") = {0x17, 0x1d, 0x1e};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagColor_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch13mMenuTagColorE") = {0x1c};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagElementWep_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch18mMenuTagElementWepE") = {0x18};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagElementArmor_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch20mMenuTagElementArmorE") = {0x19};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagSpecialWep_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch18mMenuTagSpecialWepE") = {0x1a};

alignas(1) unsigned char uGUIBazaarItemSearch_mMenuTagSpecialArmor_bytes[1] __asm__("_ZN20uGUIBazaarItemSearch20mMenuTagSpecialArmorE") = {0x1b};

alignas(4) unsigned char uGUIBazaarItemSearch_mBigCategoryMenuList_bytes[32] __asm__("_ZN20uGUIBazaarItemSearch20mBigCategoryMenuListE") = {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00};

__attribute__((weak)) MtObject* uGUIBazaarItemSearch::MyDTI::newInstance() const {
    DDON_STUB("uGUIBazaarItemSearch::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBazaarItemSearch::cItemData::getDTI() const {
    return uGUIBazaarItemSearch::cItemData::DTI;
}

inline uGUIBazaarItemSearch::cItemData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarItemSearch::cItemData::MyDTI uGUIBazaarItemSearch::cItemData::DTI("uGUIBazaarItemSearch::cItemData", &::MtObject::DTI, 448ul, 0u, 0u);

MtObject* uGUIBazaarItemSearch::cItemData::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarItemSearch::cItemData;
}

const MtDTI& uGUIBazaarItemSearch::cCategoryBigData::getDTI() const {
    return uGUIBazaarItemSearch::cCategoryBigData::DTI;
}

__attribute__((noinline)) uGUIBazaarItemSearch::cCategoryBigData::~cCategoryBigData() {
    DDON_STUB("uGUIBazaarItemSearch::cCategoryBigData::~cCategoryBigData")
    /* stub */
}

inline uGUIBazaarItemSearch::cCategoryBigData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarItemSearch::cCategoryBigData::MyDTI uGUIBazaarItemSearch::cCategoryBigData::DTI("uGUIBazaarItemSearch::cCategoryBigData", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* uGUIBazaarItemSearch::cCategoryBigData::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarItemSearch::cCategoryBigData;
}

const MtDTI& uGUIBazaarItemSearch::cCategoryData::getDTI() const {
    return uGUIBazaarItemSearch::cCategoryData::DTI;
}

inline uGUIBazaarItemSearch::cCategoryData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarItemSearch::cCategoryData::MyDTI uGUIBazaarItemSearch::cCategoryData::DTI("uGUIBazaarItemSearch::cCategoryData", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBazaarItemSearch::cCategoryData::MyDTI::newInstance() const {
    DDON_STUB("uGUIBazaarItemSearch::cCategoryData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIBazaarItemSearch::cSearchItemData::getDTI() const {
    return uGUIBazaarItemSearch::cSearchItemData::DTI;
}

inline uGUIBazaarItemSearch::cSearchItemData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarItemSearch::cSearchItemData::MyDTI uGUIBazaarItemSearch::cSearchItemData::DTI("uGUIBazaarItemSearch::cSearchItemData", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* uGUIBazaarItemSearch::cSearchItemData::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarItemSearch::cSearchItemData;
}

template MtTypedArray<uGUIBazaarItemSearch::cCategoryData>::~MtTypedArray();

