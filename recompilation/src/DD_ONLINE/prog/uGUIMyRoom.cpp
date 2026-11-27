// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUIMyRoom.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemory.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtStlAllocator.h"
#include "../../MT/MtStlCustom.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "nGUIMyRoom.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "uGUIBase.h"
#include "uGUIBaseExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIMyRoom::getDTI() const {
    return uGUIMyRoom::DTI;
}

void* uGUIMyRoom::operator new(size_t sz, u32 align) {
    return uGUIMyRoom::getAllocator()->memAlloc(sz, align, uGUIMyRoom::DTI.getID());
}

uGUIMyRoom::uGUIMyRoom() {
    DDON_STUB("uGUIMyRoom::uGUIMyRoom")
    /* stub */
}

uGUIMyRoom::~uGUIMyRoom() {
}

__attribute__((weak)) void uGUIMyRoom::setPawnInfo(MT_CTSTR name, u32 jobId, u32 jobLevel, u32 craftLevel) {
    if (isAttachedResource()) {
        auto* t1 = reinterpret_cast<u8*>(&mPartnerPawnInfo);
        auto* t2 = *reinterpret_cast<cGUIObjMessage**>(t1);
        if (t2 != nullptr) {
            if (name != nullptr) {
                t2->setMessage(name, static_cast<u32>(strlen(name)));
            } else {
                (*reinterpret_cast<void (***)(cGUIObjMessage*)>(t2))[25](t2);
            }
        }
        reinterpret_cast<uGUIBase::cReferenceUIIconJob*>(t1 + 0x18)->set(jobId);
    
        MtStringEx<32> t3;
        t3.format("%u", jobLevel);
        auto* t4 = *reinterpret_cast<cGUIObjMessage**>(t1 + 0x8);
        if (t4 != nullptr) {
            t4->setMessage(reinterpret_cast<MT_CTSTR>(&t3) + sizeof(u32), *reinterpret_cast<const u32*>(&t3));
        }
    
        MtStringEx<32> t5;
        t5.format("%u", craftLevel);
        auto* t6 = *reinterpret_cast<cGUIObjMessage**>(t1 + 0x10);
        if (t6 != nullptr) {
            t6->setMessage(reinterpret_cast<MT_CTSTR>(&t5) + sizeof(u32), *reinterpret_cast<const u32*>(&t5));
        }
    }
}

__attribute__((weak)) void uGUIMyRoom::setListItems(const nGUIMyRoom::cListItems& listItems) {
    DDON_STUB("uGUIMyRoom::setListItems")
    /* stub */
}

void uGUIMyRoom::setInputEventHandler(nGUIMyRoom::cListInputEventHandler* listInputEventHandler) {
    mListInputEventHandler = listInputEventHandler;
}

u32 uGUIMyRoom::getItemIndex() const {
    if (mList.mScrollList.mpVCtrl != nullptr) {
        return static_cast<u32>(mList.mScrollList.mpVCtrl->getCurrentPos());
    } else {
        return 0;
    }
}

__attribute__((weak)) void uGUIMyRoom::setupAfterLoad() {
    DDON_STUB("uGUIMyRoom::setupAfterLoad")
    /* stub */
}

void uGUIMyRoom::onMoveInput() {
    mControlMgr.offAllFocus();
    mControlMgr.setCategoryFocus(0u, true);
    mControlMgr.moveInput();
    mCloseButton.execute();
}

__attribute__((weak)) void uGUIMyRoom::onMoveEvent() {
    DDON_STUB("uGUIMyRoom::onMoveEvent")
    /* stub */
}

void uGUIMyRoom::onShow() {
    if (mpINST_Null_main != nullptr) {
        mpINST_Null_main->setVisible(true);
        if (mpINST_Null_main != nullptr) {
            mpINST_Null_main->setExecute(true);
        }
    }
    if (mListInputEventHandler == nullptr) {
        return;
    }
    s32 t0 = mControlMgr.getCurrentPos(1u);
    mListInputEventHandler->onListInputEventSelect(*this, static_cast<u32>(t0));
}

void uGUIMyRoom::onHide() {
    if (mpINST_Null_main == nullptr) {
        return;
    }
    mpINST_Null_main->setVisible(false);
    if (mpINST_Null_main == nullptr) {
        return;
    }
    mpINST_Null_main->setExecute(false);
}

void uGUIMyRoom::onUpdateShow() {
    mList.mScrollList.uGUIBase::cScrollList::update(getDeltaTime());
    u32 i = 0;
    if (mRefrenceUIArray.mLength != 0) {
        do {
            static_cast<cReferenceUIBase*>(mRefrenceUIArray.getBuffer()[static_cast<int>(i)])->update();
            i += 1u;
        } while (i < mRefrenceUIArray.mLength);
    }
}

__attribute__((weak)) u32 uGUIMyRoom::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIMyRoom::evCtrlDecide")
    return {};
}

u32 uGUIMyRoom::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

__attribute__((weak)) bool uGUIMyRoom::evCtrlScrollList(cControl::Message* msg) {
    DDON_STUB("uGUIMyRoom::evCtrlScrollList")
    return {};
}

__attribute__((weak)) void uGUIMyRoom::showListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    DDON_STUB("uGUIMyRoom::showListItem")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoom::hideListItem(uGUIBase::cScrollListItemBase* pItemBase) {
    DDON_STUB("uGUIMyRoom::hideListItem")
    /* stub */
}

inline uGUIMyRoom::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMyRoom::MyDTI uGUIMyRoom::DTI("uGUIMyRoom", &::uGUIMyRoomBase::DTI, 5632ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMyRoom::MyDTI::newInstance() const {
    DDON_STUB("uGUIMyRoom::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void uGUIMyRoom::cPartnerPawnInfo::setup(uGUIMyRoom& owner) {
    DDON_STUB("uGUIMyRoom::cPartnerPawnInfo::setup")
    /* stub */
}

uGUIMyRoom::cList::cList() {
    DDON_STUB("uGUIMyRoom::cList::cList")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoom::cList::setup(uGUIMyRoom& owner) {
    DDON_STUB("uGUIMyRoom::cList::setup")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoom::cList::setItems(const nGUIMyRoom::cListItems& listItems, cGUIControlMgr& controlMgr, u32 controlId, u32 categoryId) {
    DDON_STUB("uGUIMyRoom::cList::setItems")
    /* stub */
}

const MtDTI& uGUIMyRoom::cList::cItem::getDTI() const {
    return uGUIMyRoom::cList::cItem::DTI;
}

__attribute__((weak)) void uGUIMyRoom::cList::cItem::setup(uGUIMyRoom& owner, cGUIInstNull* inst_null_list01) {
    DDON_STUB("uGUIMyRoom::cList::cItem::setup")
    /* stub */
}

inline uGUIMyRoom::cList::cItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMyRoom::cList::cItem::MyDTI uGUIMyRoom::cList::cItem::DTI("uGUIMyRoom::cList::cItem", &::uGUIBase::cScrollListItemBase::DTI, 104ul, 0u, 0u);

MtObject* uGUIMyRoom::cList::cItem::MyDTI::newInstance() const {
    return new (16u) uGUIMyRoom::cList::cItem;
}

const MtDTI& uGUIMyRoom::cList::cInfo::getDTI() const {
    return uGUIMyRoom::cList::cInfo::DTI;
}

uGUIMyRoom::cList::cInfo::~cInfo() {
}

inline uGUIMyRoom::cList::cInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMyRoom::cList::cInfo::MyDTI uGUIMyRoom::cList::cInfo::DTI("uGUIMyRoom::cList::cInfo", &::uGUIBase::cScrollListInfoBase::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMyRoom::cList::cInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIMyRoom::cList::cInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIMyRoomBase::getDTI() const {
    return uGUIMyRoomBase::DTI;
}

uGUIMyRoomBase::~uGUIMyRoomBase() {
}

__attribute__((weak)) MT_CTSTR uGUIMyRoomBase::getLoadArcTagName(u32 arcIndex) const {
    DDON_STUB("uGUIMyRoomBase::getLoadArcTagName")
    return {};
}

__attribute__((weak)) const nGUIBaseExt::ResInfo* uGUIMyRoomBase::getGuiResInfo() const {
    DDON_STUB("uGUIMyRoomBase::getGuiResInfo")
    return nullptr;
}

t64 uGUIMyRoomBase::getGuiResUpdateTime() const {
    return 1473313874;
}

__attribute__((weak)) const nGUIBaseExt::ResInfo* uGUIMyRoomBase::getGmdResInfo(u32 gmdResIndex) const {
    DDON_STUB("uGUIMyRoomBase::getGmdResInfo")
    return nullptr;
}

u32 uGUIMyRoomBase::getGmdResNum() const {
    return 1;
}

void uGUIMyRoomBase::setupAfterLoad() {
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(11u), true);
    setPlay(true);
    setFlowAndInit(3u, false);
    mpINST_Null_main = static_cast<cGUIInstNull*>(getInstance(347u, false));
    cGUIInstance* t0 = getInstance(348u, false);
    mpINST_Null_pop = static_cast<cGUIInstNull*>(t0);
    if (mpINST_Null_main != nullptr) {
        mpINST_Null_main->setVisible(false);
        if (mpINST_Null_main != nullptr) {
            mpINST_Null_main->setExecute(false);
        }
        if (mpINST_Null_pop != nullptr) {
            mpINST_Null_pop->setVisible(false);
            if (mpINST_Null_pop != nullptr) {
                mpINST_Null_pop->setExecute(false);
            }
        }
    } else {
        if (mpINST_Null_pop != nullptr) {
            t0->setVisible(false);
            if (mpINST_Null_pop != nullptr) {
                mpINST_Null_pop->setExecute(false);
            }
        }
    }
}

inline uGUIMyRoomBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMyRoomBase::MyDTI uGUIMyRoomBase::DTI("uGUIMyRoomBase", &::uGUIBaseExtWindow::DTI, 3520ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMyRoomBase::MyDTI::newInstance() const {
    DDON_STUB("uGUIMyRoomBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIMyRoomPopup::getDTI() const {
    return uGUIMyRoomPopup::DTI;
}

void* uGUIMyRoomPopup::operator new(size_t sz, u32 align) {
    return uGUIMyRoomPopup::getAllocator()->memAlloc(sz, align, uGUIMyRoomPopup::DTI.getID());
}

uGUIMyRoomPopup::uGUIMyRoomPopup() {
    DDON_STUB("uGUIMyRoomPopup::uGUIMyRoomPopup")
    /* stub */
}

__attribute__((noinline)) uGUIMyRoomPopup::~uGUIMyRoomPopup() {
}

void uGUIMyRoomPopup::setTitle(MT_CTSTR title) {
    if (!isAttachedResource()) {
        return;
    }
    cGUIObjMessage* t0 = mTitle.mpOBJ_msg_poptitile_m_poptitle;
    if (t0 == nullptr) {
        return;
    }
    if (title != nullptr) {
        t0->setMessage(title, static_cast<unsigned int>(strlen(title)));
    } else {
        t0->clearMessage();
    }
}

__attribute__((weak)) void uGUIMyRoomPopup::setListItems(const nGUIMyRoom::cPopupListItems& listItems) {
    DDON_STUB("uGUIMyRoomPopup::setListItems")
    /* stub */
}

void uGUIMyRoomPopup::setInputEventHandler(nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler) {
    mPopupListInputEventHandler = popupListInputEventHandler;
}

__attribute__((weak)) void uGUIMyRoomPopup::setupAfterLoad() {
    DDON_STUB("uGUIMyRoomPopup::setupAfterLoad")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoomPopup::onMoveInput() {
    DDON_STUB("uGUIMyRoomPopup::onMoveInput")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoomPopup::onMoveEvent() {
    DDON_STUB("uGUIMyRoomPopup::onMoveEvent")
    /* stub */
}

void uGUIMyRoomPopup::onShow() {
    if (mpINST_Null_pop != nullptr) {
        mpINST_Null_pop->setVisible(true);
        if (mpINST_Null_pop != nullptr) {
            mpINST_Null_pop->setExecute(true);
        }
    }
    if (mPopupListInputEventHandler == nullptr) {
        return;
    }
    s32 t0 = mControlMgr.getCurrentPos(2u);
    if (static_cast<unsigned int>(t0) < mList.mScrollList.mInfoArray.mLength) {
        if (mList.mScrollList.mInfoArray.getBuffer()[t0] != nullptr) {
            mPopupListInputEventHandler->onPopupListInputEventSelect(*this, static_cast<u32>(t0), static_cast<uGUIMyRoomPopup::cList::cInfo*>(mList.mScrollList.mInfoArray.getBuffer()[t0])->getListIndex());
        } else {
            mPopupListInputEventHandler->onPopupListInputEventSelect(*this, static_cast<u32>(t0), 0u);
        }
    } else {
        mPopupListInputEventHandler->onPopupListInputEventSelect(*this, static_cast<u32>(t0), 0u);
    }
}

void uGUIMyRoomPopup::onHide() {
    if (mpINST_Null_pop == nullptr) {
        return;
    }
    mpINST_Null_pop->setVisible(false);
    if (mpINST_Null_pop == nullptr) {
        return;
    }
    mpINST_Null_pop->setExecute(false);
}

void uGUIMyRoomPopup::onUpdateShow() {
    mList.mScrollList.uGUIBase::cScrollList::update(getDeltaTime());
    updateFocus();
    u32 i = 0;
    if (mRefrenceUIArray.mLength != 0) {
        do {
            static_cast<cReferenceUIBase*>(mRefrenceUIArray.getBuffer()[static_cast<int>(i)])->update();
            i += 1u;
        } while (i < mRefrenceUIArray.mLength);
    }
}

__attribute__((weak)) void uGUIMyRoomPopup::setupControls() {
    DDON_STUB("uGUIMyRoomPopup::setupControls")
    /* stub */
}

u32 uGUIMyRoomPopup::evCtrlDecide(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

__attribute__((weak)) void uGUIMyRoomPopup::evDecide() {
    DDON_STUB("uGUIMyRoomPopup::evDecide")
    /* stub */
}

u32 uGUIMyRoomPopup::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIMyRoomPopup::evCtrlMoveLayout(cControl::Message* msg) {
    if (msg != nullptr) {
        const s32 old_layout_id = mControlMgr.getOldPos(1u);
        const s32 current_layout_id = mControlMgr.getCurrentPos(1u);
        if (old_layout_id != current_layout_id) {
            if (current_layout_id == 0) {
                if (msg->reason == nGUIExt::TRG_DOWN) {
                    setInputEvent(70u);
                } else {
                    if (msg->reason == nGUIExt::BTN_START) {
                        setInputEvent(71u);
                    } else {
                        setInputEvent(68u);
                    }
                }
            } else {
                setInputEvent(68u);
            }
        } else {
            setInputEvent(68u);
        }
        return 0;
    } else {
        setInputEvent(68u);
        return 0;
    }
}

u32 uGUIMyRoomPopup::evCtrlMoveButton(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

u32 uGUIMyRoomPopup::evCtrlButtonMouseDecide(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->reason == nGUIExt::MOUSE_LCLICK) {
            const s32 click_vol = msg->click_vol;
            if (click_vol > -1) {
                const s32 layout_id = mControlMgr.getCurrentPos(1u);
                if (click_vol != layout_id) {
                    mControlMgr.setCurrentPos(1u, click_vol);
                }
                setInputEvent(66u);
                return 0;
            } else {
                setInputEvent(69u);
                return 0;
            }
        } else {
            setInputEvent(69u);
            return 0;
        }
    } else {
        setInputEvent(69u);
        return 0;
    }
}

bool uGUIMyRoomPopup::evCtrlScrollList(cControl::Message* msg) {
    if (msg != nullptr) {
        if (static_cast<unsigned int>(msg->reason - 37) <= 1) {
            const s32 click_vol = msg->click_vol;
            if (click_vol > -1) {
                const s32 layout_id = mControlMgr.getCurrentPos(1u);
                if (click_vol != layout_id) {
                    mControlMgr.setCurrentPos(1u, click_vol);
                }
                return true;
            } else {
                return true;
            }
        } else {
            return true;
        }
    } else {
        return true;
    }
}

__attribute__((weak)) void uGUIMyRoomPopup::updateFocus() {
    DDON_STUB("uGUIMyRoomPopup::updateFocus")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoomPopup::showListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    DDON_STUB("uGUIMyRoomPopup::showListItem")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoomPopup::hideListItem(uGUIBase::cScrollListItemBase* pItemBase) {
    DDON_STUB("uGUIMyRoomPopup::hideListItem")
    /* stub */
}

inline uGUIMyRoomPopup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMyRoomPopup::MyDTI uGUIMyRoomPopup::DTI("uGUIMyRoomPopup", &::uGUIMyRoomBase::DTI, 19392ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMyRoomPopup::MyDTI::newInstance() const {
    DDON_STUB("uGUIMyRoomPopup::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void uGUIMyRoomPopup::cList::setup(uGUIMyRoomPopup& owner) {
    DDON_STUB("uGUIMyRoomPopup::cList::setup")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoomPopup::cList::setItems(const nGUIMyRoom::cPopupListItems& listItems, MT_CTSTR removeString, cGUIControlMgr& controlMgr, u32 controlId, u32 parentId, s32 movePos) {
    DDON_STUB("uGUIMyRoomPopup::cList::setItems")
    /* stub */
}

const MtDTI& uGUIMyRoomPopup::cList::cInfo::getDTI() const {
    return uGUIMyRoomPopup::cList::cInfo::DTI;
}

uGUIMyRoomPopup::cList::cInfo::~cInfo() {
    DDON_STUB("uGUIMyRoomPopup::cList::cInfo::~cInfo")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoomPopup::cList::cInfo::addMouseTouchList(cControl* control, s32 pos) {
    DDON_STUB("uGUIMyRoomPopup::cList::cInfo::addMouseTouchList")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoomPopup::cList::cInfo::setListSize(u32 listSize) {
    DDON_STUB("uGUIMyRoomPopup::cList::cInfo::setListSize")
    /* stub */
}

__attribute__((weak)) void uGUIMyRoomPopup::cList::cInfo::setListString(u32 listIndex, MT_CTSTR str) {
    DDON_STUB("uGUIMyRoomPopup::cList::cInfo::setListString")
    /* stub */
}

inline uGUIMyRoomPopup::cList::cInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMyRoomPopup::cList::cInfo::MyDTI uGUIMyRoomPopup::cList::cInfo::DTI("uGUIMyRoomPopup::cList::cInfo", &::uGUIBase::cScrollListInfoBase::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMyRoomPopup::cList::cInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIMyRoomPopup::cList::cInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIMyRoomPopup::cList::cItem::getDTI() const {
    return uGUIMyRoomPopup::cList::cItem::DTI;
}

uGUIMyRoomPopup::cList::cItem::~cItem() {
}

__attribute__((weak)) void uGUIMyRoomPopup::cList::cItem::setup(uGUIMyRoomPopup& owner, cGUIInstNull* inst_null_list03) {
    DDON_STUB("uGUIMyRoomPopup::cList::cItem::setup")
    /* stub */
}

bool uGUIMyRoomPopup::cList::cItem::moveEvent(uGUIMyRoomPopup& owner, uGUIMyRoomPopup::cList& list, uGUIMyRoomPopup::cList::cInfo& info, nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler) {
    if (mMode == MODE_PULLDOWN) {
        mPulldown.moveEvent();
        if (mPulldown.isDecide()) {
            const u32 item_list_index = mPulldown.getIdx();
            info.mListIndex = item_list_index;
            if (popupListInputEventHandler != nullptr) {
                if (list.mScrollList.mpVCtrl != nullptr) {
                    const u32 item_index = list.mScrollList.mpVCtrl->getCurrentPos();
                    popupListInputEventHandler->onPopupListInputEventChange(owner, item_index, item_list_index);
                    if (mPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                        info.mBottomPos = info.mTopPos + mDefaultItemSpacing;
                        mDefaultItemSpacing = 0.0f;
                        if (mpINST_Null_list03 != nullptr) {
                            mpINST_Null_list03->setPriority(mDefaultNullPriority);
                        }
                        list.mScrollList.setupList(list.mMaskHeight, list.mMaskHeight, false);
                        list.mScrollList.setSliderPos(list.mScrollList.getSliderPos(), true);
                        list.mScrollList.setListPos(true);
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    popupListInputEventHandler->onPopupListInputEventChange(owner, 0u, item_list_index);
                    if (mPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                        info.mBottomPos = info.mTopPos + mDefaultItemSpacing;
                        mDefaultItemSpacing = 0.0f;
                        if (mpINST_Null_list03 != nullptr) {
                            mpINST_Null_list03->setPriority(mDefaultNullPriority);
                        }
                        list.mScrollList.setupList(list.mMaskHeight, list.mMaskHeight, false);
                        list.mScrollList.setSliderPos(list.mScrollList.getSliderPos(), true);
                        list.mScrollList.setListPos(true);
                        return false;
                    } else {
                        return true;
                    }
                }
            } else {
                if (mPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                    info.mBottomPos = info.mTopPos + mDefaultItemSpacing;
                    mDefaultItemSpacing = 0.0f;
                    if (mpINST_Null_list03 != nullptr) {
                        mpINST_Null_list03->setPriority(mDefaultNullPriority);
                    }
                    list.mScrollList.setupList(list.mMaskHeight, list.mMaskHeight, false);
                    list.mScrollList.setSliderPos(list.mScrollList.getSliderPos(), true);
                    list.mScrollList.setListPos(true);
                    return false;
                } else {
                    return true;
                }
            }
        } else {
            if (mPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                info.mBottomPos = info.mTopPos + mDefaultItemSpacing;
                mDefaultItemSpacing = 0.0f;
                if (mpINST_Null_list03 != nullptr) {
                    mpINST_Null_list03->setPriority(mDefaultNullPriority);
                }
                list.mScrollList.setupList(list.mMaskHeight, list.mMaskHeight, false);
                list.mScrollList.setSliderPos(list.mScrollList.getSliderPos(), true);
                list.mScrollList.setListPos(true);
                return false;
            } else {
                return true;
            }
        }
    } else {
        return true;
    }
}

bool uGUIMyRoomPopup::cList::cItem::onDecide(uGUIMyRoomPopup& owner, uGUIMyRoomPopup::cList& list, uGUIMyRoomPopup::cList::cInfo& info, nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler) {
    if (mMode == MODE_PULLDOWN) {
        if (!mPulldown.mIsForbid && (mPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE)) {
            mPulldown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
            const f32 bottom_pos = info.mBottomPos;
            mDefaultItemSpacing = bottom_pos - info.mTopPos;
            info.mBottomPos = bottom_pos + mPulldown.mListSizeH;
            if (mpINST_Null_list03 != nullptr) {
                mpINST_Null_list03->setPriority(mDefaultNullPriority + 1u);
            }
            list.mScrollList.setupList(list.mMaskHeight, list.mMaskHeight, false);
            list.mScrollList.setSliderPos(list.mScrollList.getSliderPos(), true);
            list.mScrollList.setListPos(true);
            return true;
        }
    } else {
        if (mMode == MODE_CHECKBOX) {
            if (!mCheckbox.mIsForbid) {
                mCheckbox.mCheck = !mCheckbox.mCheck;
                mCheckbox._update();
            }
            info.mListIndex = mCheckbox.mCheck;
            if (popupListInputEventHandler != nullptr) {
                if (list.mScrollList.mpVCtrl != nullptr) {
                    const u32 item_index = list.mScrollList.mpVCtrl->getCurrentPos();
                    popupListInputEventHandler->onPopupListInputEventChange(owner, item_index, mCheckbox.mCheck);
                    return false;
                }
                popupListInputEventHandler->onPopupListInputEventChange(owner, 0u, mCheckbox.mCheck);
            }
        }
    }
    return false;
}

__attribute__((weak)) void uGUIMyRoomPopup::cList::cItem::show(uGUIMyRoomPopup::cList::cInfo& info) {
    DDON_STUB("uGUIMyRoomPopup::cList::cItem::show")
    /* stub */
}

inline uGUIMyRoomPopup::cList::cItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIMyRoomPopup::cList::cItem::MyDTI uGUIMyRoomPopup::cList::cItem::DTI("uGUIMyRoomPopup::cList::cItem", &::uGUIBase::cScrollListItemBase::DTI, 1792ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIMyRoomPopup::cList::cItem::MyDTI::newInstance() const {
    DDON_STUB("uGUIMyRoomPopup::cList::cItem::MyDTI::newInstance")
    return nullptr;
}

