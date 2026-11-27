// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPopFilter.h"
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
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/uCoord.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIPopFilter::getDTI() const {
    return uGUIPopFilter::DTI;
}

void* uGUIPopFilter::operator new(size_t sz, u32 align) {
    return uGUIPopFilter::getAllocator()->memAlloc(sz, align, uGUIPopFilter::DTI.getID());
}

__attribute__((noinline)) uGUIPopFilter::~uGUIPopFilter() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mCheckBox.mLength != 0) {
        u32 v0_0 = mCheckBox.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCheckBox.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mCheckBox.mpArray[i0_3];
                v1_0 = mCheckBox.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCheckBox.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCheckBox.mpArray));
    }
    mCheckBox.mpArray = nullptr;
    mCheckBox.mBufsiz = 0;
    mCheckBox.mLength = 0;
    if (mNumBox.mLength != 0) {
        u32 v3_0 = mNumBox.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mNumBox.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mNumBox.mpArray[i3_3];
                v4_0 = mNumBox.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mNumBox.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNumBox.mpArray));
    }
    mNumBox.mpArray = nullptr;
    mNumBox.mBufsiz = 0;
    mNumBox.mLength = 0;
    if (mPullDown.mLength != 0) {
        u32 v6_0 = mPullDown.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mPullDown.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mPullDown.mpArray[i6_3];
                v7_0 = mPullDown.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPullDown.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mPullDown.mpArray));
    }
    mPullDown.mpArray = nullptr;
    mPullDown.mBufsiz = 0;
    mPullDown.mLength = 0;
}

bool uGUIPopFilter::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_FILTER"), 129u, 1477029345l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_POP_FILTER_GMD", 0u);
}

__attribute__((weak)) void uGUIPopFilter::setup() {
    DDON_STUB("uGUIPopFilter::setup")
    /* stub */
}

void uGUIPopFilter::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    mList.mListCtrl.clearInfo();
    if (mData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mData.mpArray));
    }
    mData.mpArray = nullptr;
    mData.mLength = 0;
    mData.mBufsiz = 0;
}

__attribute__((weak)) void uGUIPopFilter::setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    DDON_STUB("uGUIPopFilter::setupListItem")
    /* stub */
}

void uGUIPopFilter::hideListItem(uGUIBase::cScrollListItemBase* pItemBase) {
    if (pItemBase == nullptr) {
        return;
    }
    if (pItemBase->mpInstBase != nullptr) {
        pItemBase->mpInstBase->setVisible(false);
    }
    setVisibleRef(static_cast<cListItem*>(pItemBase), false);
}

__attribute__((weak)) void uGUIPopFilter::setVisibleRef(uGUIPopFilter::cListItem* pItem, bool visible) {
    DDON_STUB("uGUIPopFilter::setVisibleRef")
    /* stub */
}

void uGUIPopFilter::setWindowTitle(MT_CTSTR title) {
    if ((*title) == 0) {
        return;
    }
    setObjectMessage(getObjectFromId(getInstance(5u, false), 2u), title, 0u, false);
    mWindowTitle = title;
}

void uGUIPopFilter::setWindowTitle(s32 id) {
    mWindowTitleId = id;
    mRefresh = true;
}

void uGUIPopFilter::setBtnTitle(MT_CTSTR btitle1, MT_CTSTR btitle2) {
    if ((*btitle1) != 0) {
        mBtnTitle1 = btitle1;
        mBtn[0].setMessage(btitle1);
    }
    if ((*btitle2) == 0) {
        return;
    }
    mBtnTitle2 = btitle2;
    mBtn[1].setMessage(btitle2);
}

__attribute__((weak)) void uGUIPopFilter::editRefName(u32 idx, MtString str) {
    DDON_STUB("uGUIPopFilter::editRefName")
    /* stub */
}

__attribute__((weak)) bool uGUIPopFilter::addReference(uGUIPopFilter::REF_TYPE type, s32 def, MT_CTSTR str, uGUIPopFilter::TITLE_PRE style, s32 max, s32 min, MT_CTSTR name, uGUIPopFilter::ATTR_BIT bit) {
    DDON_STUB("uGUIPopFilter::addReference")
    return {};
}

__attribute__((weak)) bool uGUIPopFilter::addReference(uGUIPopFilter::REF_TYPE type, s32 def, s32 titleid, uGUIPopFilter::TITLE_PRE style, s32 nameid, s32 max, s32 min, uGUIPopFilter::ATTR_BIT bit) {
    DDON_STUB("uGUIPopFilter::addReference")
    return {};
}

__attribute__((weak)) bool uGUIPopFilter::addJobIcon(s32 def, s32 strid, bool all, s32 checkboxnameid, uGUIPopFilter::TITLE_PRE style) {
    DDON_STUB("uGUIPopFilter::addJobIcon")
    return {};
}

bool uGUIPopFilter::addReferenceMaxMin(s32 defmax, s32 defmin, s32 max, s32 min, s32 titleid, s32 strmaxid, s32 strminid, uGUIPopFilter::TITLE_PRE style) {
    if (addReference(REF_NUMBOX, defmin, titleid, style, strminid, max, min, ATTR_MIN)) {
        u32 t0 = mData.mLength;
        if (addReference(REF_NUMBOX, defmax, -1, style, strmaxid, max, min, ATTR_MAX)) {
            u32 t1 = mData.mLength;
            static_cast<cData*>(mData.getBuffer()[static_cast<int>(t1 - 1u)])->mExtindex = t0 - 1u;
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mData.getBuffer()[static_cast<int>(t0 - 1u)]) + 56) = t1 - 1u;
            return true;
        } else {
            static_cast<cData*>(mData.getBuffer()[static_cast<int>(t0 - 1u)])->mVisible = false;
            return false;
        }
    } else {
        return false;
    }
}

bool uGUIPopFilter::addCheckBox(s32 nameid, s32 def, s32 titleid, uGUIPopFilter::TITLE_PRE style) {
    return addReference(REF_CHECKBOX, def, titleid, style, nameid, 0, 0, ATTR_NONE);
}

bool uGUIPopFilter::addCheckBox(MT_CTSTR name, s32 def, MT_CTSTR title, uGUIPopFilter::TITLE_PRE style) {
    return addReference(REF_CHECKBOX, def, title, style, 0, 0, name, ATTR_NONE);
}

void uGUIPopFilter::setCheckBoxTitle(u32 idx, s32 titleid, s32 val) {
    if (mData.mLength >= idx) {
        if (static_cast<cData*>(mData.getBuffer()[static_cast<int>(idx)])->mType == REF_CHECKBOX) {
            static_cast<cData*>(mData.getBuffer()[static_cast<int>(idx)])->mTitleId = titleid;
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mData.getBuffer()[static_cast<int>(idx)]) + 108) = static_cast<unsigned int>(val);
            mRefresh = true;
        }
    }
}

bool uGUIPopFilter::addNumBox(s32 def, s32 max, s32 min, MT_CTSTR name, MT_CTSTR title, uGUIPopFilter::TITLE_PRE style) {
    return addReference(REF_NUMBOX, def, title, style, max, min, name, ATTR_NONE);
}

bool uGUIPopFilter::addPullDown(s32 def, MT_CTSTR title, s32 listsize, uGUIPopFilter::TITLE_PRE style) {
    if (addReference(REF_PULLDOWN, def, title, style, 0, 0, "", ATTR_NONE)) {
        static_cast<cData*>(mData.getBuffer()[static_cast<int>(mData.mLength - 1u)])->mPullDownSize = listsize;
        return true;
    } else {
        return false;
    }
}

__attribute__((weak)) void uGUIPopFilter::addPullDownList(u32 idx, MT_CTSTR listname) {
    DDON_STUB("uGUIPopFilter::addPullDownList")
    /* stub */
}

__attribute__((weak)) void uGUIPopFilter::addPullDownList(u32 idx, s32 id) {
    DDON_STUB("uGUIPopFilter::addPullDownList")
    /* stub */
}

void uGUIPopFilter::setReferenceEnable(u32 idx, bool enable) {
    if (idx < mData.mLength) {
        static_cast<cData*>(mData.getBuffer()[static_cast<int>(idx)])->mEnable = enable;
        mRefresh = true;
    }
}

void uGUIPopFilter::setGrayOut(u32 idx, bool flag) {
    if (idx < mData.mLength) {
        static_cast<cData*>(mData.getBuffer()[static_cast<int>(idx)])->mGrayOut = flag;
        mRefresh = true;
    }
}

__attribute__((weak)) bool uGUIPopFilter::setParam(u32 idx, s32 param) {
    DDON_STUB("uGUIPopFilter::setParam")
    return {};
}

__attribute__((weak)) s32 uGUIPopFilter::getParam(u32 idx) {
    DDON_STUB("uGUIPopFilter::getParam")
    return {};
}

__attribute__((weak)) void uGUIPopFilter::onChangeNumBox() {
    DDON_STUB("uGUIPopFilter::onChangeNumBox")
    /* stub */
}

void uGUIPopFilter::setDecideEnable(bool flag) {
    mBtn[0].setEnable(flag);
    mIsEnable[0] = flag;
}

void uGUIPopFilter::setBtnDefautPos(u32 pos) {
    if (pos <= 1u) {
        mBtnPos = pos;
        if (mpHCtrl != nullptr) {
            mpHCtrl->setCurrentPos(static_cast<s32>(pos), false);
        }
    }
}

void uGUIPopFilter::updateInit() {
    cHorizontalList* t0 = mpHCtrl;
    if (t0 != nullptr) {
        s32 t1 = t0->getCurrentPos();
        if (t1 == 1) {
            (&mBtn[0])->setFocus(false);
            unsigned long t3 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 3184);
            unsigned long t7 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 3184)) + 120);
            (&mBtn[1])->setFocus(true);
            createList();
            updateWait();
            mBtnCtrl = false;
            cHorizontalList* t10 = mpHCtrl;
            if (t10 != nullptr) {
                unsigned char t11 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t10) + 3132);
                t10->mCtrlF = t10->mCtrlF & 0xFFFFFFF7u;
                mList.mListCtrl.setEnableKey(false);
                mList.mListCtrl.clearCursorFocus();
                uGUIBase* t14 = mList.mListCtrl.mpOwner;
                if (t14 != nullptr) {
                    u32 t15 = t14->getBasePointerPriority();
                    mList.mListCtrl.mIsAutoDispPointer = false;
                    mList.mListCtrl.mPointerPrio = t15;
                } else {
                    mList.mListCtrl.mIsAutoDispPointer = false;
                    mList.mListCtrl.mPointerPrio = 10;
                }
            } else {
                mList.mListCtrl.setEnableKey(false);
                mList.mListCtrl.clearCursorFocus();
                uGUIBase* t14 = mList.mListCtrl.mpOwner;
                if (t14 != nullptr) {
                    u32 t15 = t14->getBasePointerPriority();
                    mList.mListCtrl.mIsAutoDispPointer = false;
                    mList.mListCtrl.mPointerPrio = t15;
                } else {
                    mList.mListCtrl.mIsAutoDispPointer = false;
                    mList.mListCtrl.mPointerPrio = 10;
                }
            }
        } else {
            if (t1 == 0) {
                (&mBtn[0])->setFocus(true);
                unsigned long t5 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 3184);
                unsigned long t7 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 3184)) + 120);
                (&mBtn[1])->setFocus(false);
                createList();
                updateWait();
                mBtnCtrl = false;
                cHorizontalList* t10 = mpHCtrl;
                if (t10 != nullptr) {
                    unsigned char t11 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t10) + 3132);
                    t10->mCtrlF = t10->mCtrlF & 0xFFFFFFF7u;
                    mList.mListCtrl.setEnableKey(false);
                    mList.mListCtrl.clearCursorFocus();
                    uGUIBase* t14 = mList.mListCtrl.mpOwner;
                    if (t14 != nullptr) {
                        u32 t15 = t14->getBasePointerPriority();
                        mList.mListCtrl.mIsAutoDispPointer = false;
                        mList.mListCtrl.mPointerPrio = t15;
                    } else {
                        mList.mListCtrl.mIsAutoDispPointer = false;
                        mList.mListCtrl.mPointerPrio = 10;
                    }
                } else {
                    mList.mListCtrl.setEnableKey(false);
                    mList.mListCtrl.clearCursorFocus();
                    uGUIBase* t14 = mList.mListCtrl.mpOwner;
                    if (t14 != nullptr) {
                        u32 t15 = t14->getBasePointerPriority();
                        mList.mListCtrl.mIsAutoDispPointer = false;
                        mList.mListCtrl.mPointerPrio = t15;
                    } else {
                        mList.mListCtrl.mIsAutoDispPointer = false;
                        mList.mListCtrl.mPointerPrio = 10;
                    }
                }
            } else {
                createList();
                updateWait();
                mBtnCtrl = false;
                cHorizontalList* t10 = mpHCtrl;
                if (t10 != nullptr) {
                    unsigned char t11 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t10) + 3132);
                    t10->mCtrlF = t10->mCtrlF & 0xFFFFFFF7u;
                    mList.mListCtrl.setEnableKey(false);
                    mList.mListCtrl.clearCursorFocus();
                    uGUIBase* t14 = mList.mListCtrl.mpOwner;
                    if (t14 != nullptr) {
                        u32 t15 = t14->getBasePointerPriority();
                        mList.mListCtrl.mIsAutoDispPointer = false;
                        mList.mListCtrl.mPointerPrio = t15;
                    } else {
                        mList.mListCtrl.mIsAutoDispPointer = false;
                        mList.mListCtrl.mPointerPrio = 10;
                    }
                } else {
                    mList.mListCtrl.setEnableKey(false);
                    mList.mListCtrl.clearCursorFocus();
                    uGUIBase* t14 = mList.mListCtrl.mpOwner;
                    if (t14 != nullptr) {
                        u32 t15 = t14->getBasePointerPriority();
                        mList.mListCtrl.mIsAutoDispPointer = false;
                        mList.mListCtrl.mPointerPrio = t15;
                    } else {
                        mList.mListCtrl.mIsAutoDispPointer = false;
                        mList.mListCtrl.mPointerPrio = 10;
                    }
                }
            }
        }
    } else {
        (&mBtn[0])->setFocus(true);
        unsigned long t5 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 3184);
        unsigned long t7 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 3184)) + 120);
        (&mBtn[1])->setFocus(false);
        createList();
        updateWait();
        mBtnCtrl = false;
        cHorizontalList* t10 = mpHCtrl;
        if (t10 != nullptr) {
            unsigned char t11 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t10) + 3132);
            t10->mCtrlF = t10->mCtrlF & 0xFFFFFFF7u;
            mList.mListCtrl.setEnableKey(false);
            mList.mListCtrl.clearCursorFocus();
            uGUIBase* t14 = mList.mListCtrl.mpOwner;
            if (t14 != nullptr) {
                u32 t15 = t14->getBasePointerPriority();
                mList.mListCtrl.mIsAutoDispPointer = false;
                mList.mListCtrl.mPointerPrio = t15;
            } else {
                mList.mListCtrl.mIsAutoDispPointer = false;
                mList.mListCtrl.mPointerPrio = 10;
            }
        } else {
            mList.mListCtrl.setEnableKey(false);
            mList.mListCtrl.clearCursorFocus();
            uGUIBase* t14 = mList.mListCtrl.mpOwner;
            if (t14 != nullptr) {
                u32 t15 = t14->getBasePointerPriority();
                mList.mListCtrl.mIsAutoDispPointer = false;
                mList.mListCtrl.mPointerPrio = t15;
            } else {
                mList.mListCtrl.mIsAutoDispPointer = false;
                mList.mListCtrl.mPointerPrio = 10;
            }
        }
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopFilter::updateWait);
}

__attribute__((weak)) void uGUIPopFilter::updateWait() {
    DDON_STUB("uGUIPopFilter::updateWait")
    /* stub */
}

void uGUIPopFilter::updateNone() {
    if (mWaitReq == true) {
        return;
    }
    mDecide = false;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopFilter::updateWait);
}

__attribute__((weak)) void uGUIPopFilter::updateWakeUp() {
    DDON_STUB("uGUIPopFilter::updateWakeUp")
    /* stub */
}

void uGUIPopFilter::updateExit() {
    end();
}

void uGUIPopFilter::moveInput() {
    if (!mWaitReq) {
        if (mBtnCtrl) {
            if (mpHCtrl != nullptr) {
                mpHCtrl->mCtrlF = mpHCtrl->mCtrlF & 0xFFFFFFF7u;
            }
            mList.mListCtrl.setEnableKey(false);
        } else {
            mList.mListCtrl.setEnableKey(true);
        }
        u32 num = mNumBox.mLength;
        if (num != 0) {
            for (unsigned int i0_3 = 0;;) {
                static_cast<uGUIBase::cReferenceUINumBox*>(mNumBox.getBuffer()[static_cast<int>(i0_3)])->moveInput();
                if (num != (i0_3 + 1u)) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
            u32 v2_0 = mNumBox.mLength;
            if (v2_0 != 0) {
                MtObject* * v2_1 = mNumBox.getBuffer();
                for (unsigned int i2_2 = 0;;) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v2_1[static_cast<int>(i2_2)]) + 232)) == 1) {
                        return;
                    } else {
                        if ((i2_2 + 1u) < v2_0) {
                            i2_2 += 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        mIsPullDownWakeup = false;
        if (mPullDown.mLength != 0) {
            unsigned int i4_3 = 0;
            num = mPullDown.mLength;
            for (;;) {
                static_cast<uGUIBase::cReferenceUIPullDown*>(mPullDown.getBuffer()[static_cast<int>(i4_3)])->execute();
                if (static_cast<cReferenceUIPullDown*>(mPullDown.getBuffer()[static_cast<int>(i4_3)])->mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                    if ((i4_3 + 1u) < num) {
                        i4_3 += 1u;
                    } else {
                        break;
                    }
                } else {
                    mIsPullDownWakeup = true;
                    return;
                }
            }
        }
        mList.mListCtrl.executeCtrl();
        (&mBtn[0])->update();
        (&mBtn[1])->update();
        mResetBtn.uGUIBase::cReferenceUIIconButton::update();
        cControl* t0 = mpButtonCtrl;
        if (isWindowActive()) {
            if (t0 != nullptr) {
                t0->mCtrlF = t0->mCtrlF & 0xFFFFFFF7u;
                t0->execute();
            }
        } else {
            if (t0 != nullptr) {
                t0->execute();
            }
        }
        if (mpHCtrl != nullptr) {
            mpHCtrl->execute();
        }
        if (mpClickCtrl != nullptr) {
            mpClickCtrl->execute();
            return;
        }
    }
}

__attribute__((weak)) void uGUIPopFilter::moveEvent() {
    DDON_STUB("uGUIPopFilter::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIPopFilter::createList() {
    DDON_STUB("uGUIPopFilter::createList")
    /* stub */
}

__attribute__((weak)) void uGUIPopFilter::evDecide() {
    DDON_STUB("uGUIPopFilter::evDecide")
    /* stub */
}

__attribute__((weak)) void uGUIPopFilter::evNumBoxMoveL() {
    DDON_STUB("uGUIPopFilter::evNumBoxMoveL")
    /* stub */
}

__attribute__((weak)) void uGUIPopFilter::evNumBoxMoveR() {
    DDON_STUB("uGUIPopFilter::evNumBoxMoveR")
    /* stub */
}

__attribute__((weak)) u32 uGUIPopFilter::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIPopFilter::evCtrlDecide")
    return {};
}

u32 uGUIPopFilter::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

__attribute__((weak)) u32 uGUIPopFilter::evCtrlStart(cControl::Message* msg) {
    DDON_STUB("uGUIPopFilter::evCtrlStart")
    return {};
}

u32 uGUIPopFilter::evCtrlUp(cControl::Message* msg) {
    setInputEvent(68u);
    return 0;
}

u32 uGUIPopFilter::evCtrlDown(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

__attribute__((weak)) u32 uGUIPopFilter::evCtrlBtnClick(cControl::Message* msg) {
    DDON_STUB("uGUIPopFilter::evCtrlBtnClick")
    return {};
}

__attribute__((weak)) u32 uGUIPopFilter::evCtrlNumBoxMoveL(cControl::Message* msg) {
    DDON_STUB("uGUIPopFilter::evCtrlNumBoxMoveL")
    return {};
}

__attribute__((weak)) u32 uGUIPopFilter::evCtrlNumBoxMoveR(cControl::Message* msg) {
    DDON_STUB("uGUIPopFilter::evCtrlNumBoxMoveR")
    return {};
}

__attribute__((weak)) void uGUIPopFilter::createReference(u32 idx) {
    DDON_STUB("uGUIPopFilter::createReference")
    /* stub */
}

__attribute__((weak)) void uGUIPopFilter::setAllJob(bool allon, u32 idx) {
    DDON_STUB("uGUIPopFilter::setAllJob")
    /* stub */
}

__attribute__((weak)) void uGUIPopFilter::resetParam() {
    DDON_STUB("uGUIPopFilter::resetParam")
    /* stub */
}

inline uGUIPopFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopFilter::MyDTI uGUIPopFilter::DTI("uGUIPopFilter", &::uGUIsMenuBase::DTI, 39120ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopFilter::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopFilter::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIPopFilter::cData::getDTI() const {
    return uGUIPopFilter::cData::DTI;
}

inline uGUIPopFilter::cData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopFilter::cData::MyDTI uGUIPopFilter::cData::DTI("uGUIPopFilter::cData", &::uGUIBase::cScrollListInfoBase::DTI, 376ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopFilter::cData::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopFilter::cData::MyDTI::newInstance")
    return nullptr;
}

uGUIPopFilter::stList::stList() {
    DDON_STUB("uGUIPopFilter::stList::stList")
    /* stub */
}

const MtDTI& uGUIPopFilter::cListItem::getDTI() const {
    return uGUIPopFilter::cListItem::DTI;
}

uGUIPopFilter::cListItem::cListItem() {
    DDON_STUB("uGUIPopFilter::cListItem::cListItem")
    /* stub */
}

inline uGUIPopFilter::cListItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopFilter::cListItem::MyDTI uGUIPopFilter::cListItem::DTI("uGUIPopFilter::cListItem", &::uGUIBase::cScrollListItemBase::DTI, 1720ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopFilter::cListItem::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopFilter::cListItem::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uGUIBase::cReferenceUICheckbox>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUINumBox>::~MtTypedArray();

template MtTypedArray<uGUIBase::cReferenceUIPullDown>::~MtTypedArray();

template MtTypedArray<uGUIPopFilter::cData>::~MtTypedArray();

