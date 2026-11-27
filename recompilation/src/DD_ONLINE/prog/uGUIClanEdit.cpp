// Reconstructed from the game's DWARF debug information.
#include <new>
#include <stdio.h>
#include "uGUIClanEdit.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cMenuBase.h"
#include "../../XFramework/cResource.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIClanEditBase::getDTI() const {
    return uGUIClanEditBase::DTI;
}

uGUIClanEditBase::~uGUIClanEditBase() {
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

bool uGUIClanEditBase::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CLAN_EDIT_GUI"), 129u, 1434959476l))) == nullptr)) {
        return false;
    }
    if ((mpSeRes == nullptr) && ((mpSeRes = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_CLAN_SRQR"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_CLAN_EDIT_GMD", 0u);
}

void uGUIClanEditBase::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(11u), true);
    setPlay(true);
    initFlow();
    mData.mpINST_window00 = static_cast<cGUIInstAnimation*>(getInstance(2u, false));
    mData.mpINST_window_frame00 = static_cast<cGUIInstAnimation*>(getInstance(3u, false));
    mData.mpINST_Null = static_cast<cGUIInstNull*>(getInstance(6u, false));
    mData.mpINST_Null_all = static_cast<cGUIInstNull*>(getInstance(7u, false));
    mData.mpINST_emblemback = static_cast<cGUIInstAnimation*>(getInstance(9u, false));
    mData.mpINST_msg_edit00 = static_cast<cGUIInstAnimation*>(getInstance(10u, false));
    mData.mpINST_msg_textbox01 = static_cast<cGUIInstAnimation*>(getInstance(11u, false));
    mData.mpINST_msg_textbox00 = static_cast<cGUIInstAnimation*>(getInstance(12u, false));
    mData.mpINST_fix_check = static_cast<cGUIInstAnimation*>(getInstance(56u, false));
    mData.mpINST_msg_edit01 = static_cast<cGUIInstAnimation*>(getInstance(15u, false));
    mData.mpINST_msg_edit02 = static_cast<cGUIInstAnimation*>(getInstance(17u, false));
    mData.mpINST_msg_edit03 = static_cast<cGUIInstAnimation*>(getInstance(18u, false));
    mData.mpINST_msg_edit04 = static_cast<cGUIInstAnimation*>(getInstance(20u, false));
    mData.mpINST_msg_textbox02 = static_cast<cGUIInstAnimation*>(getInstance(22u, false));
    mData.mpINST_Null_emblem = static_cast<cGUIInstNull*>(getInstance(23u, false));
    mData.mpINST_checkbox = static_cast<cGUIInstAnimation*>(getInstance(84u, false));
    mData.mpINST_Null_checkbox = static_cast<cGUIInstNull*>(getInstance(83u, false));
    mData.mpINST_msg_check = static_cast<cGUIInstAnimation*>(getInstance(85u, false));
    mData.mpINST_msg_clanname = static_cast<cGUIInstAnimation*>(getInstance(34u, false));
    mData.mpINST_msg_edit05 = static_cast<cGUIInstAnimation*>(getInstance(35u, false));
    mData.mpINST_msg_textbox03 = static_cast<cGUIInstAnimation*>(getInstance(36u, false));
    mData.mpINST_msg_btn04 = static_cast<cGUIInstAnimation*>(getInstance(37u, false));
    mData.mpINST_msg_btn05 = static_cast<cGUIInstAnimation*>(getInstance(38u, false));
    mData.mpINST_msg_pop = static_cast<cGUIInstAnimation*>(getInstance(40u, false));
    cGUIInstAnimation* t0 = mData.mpINST_msg_edit00;
    MT_CTSTR t1 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 0u);
    cGUIObject* t2 = getObjectFromId(static_cast<cGUIInstance*>(t0), 3u);
    mData.mpOBJ_msg_edit00_m_section00 = static_cast<cGUIObjMessage*>(t2);
    setObjectMessage(t2, t1, 0u, false);
    cGUIInstAnimation* t3 = mData.mpINST_msg_edit00;
    MT_CTSTR t4 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 1u);
    cGUIObject* t5 = getObjectFromId(static_cast<cGUIInstance*>(t3), 5u);
    mData.mpOBJ_msg_edit00_m_section01 = static_cast<cGUIObjMessage*>(t5);
    setObjectMessage(t5, t4, 0u, false);
    cGUIInstAnimation* t6 = mData.mpINST_msg_edit01;
    MT_CTSTR t7 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 2u);
    cGUIObject* t8 = getObjectFromId(static_cast<cGUIInstance*>(t6), 3u);
    mData.mpOBJ_msg_edit01_m_section00 = static_cast<cGUIObjMessage*>(t8);
    setObjectMessage(t8, t7, 0u, false);
    cGUIInstAnimation* t9 = mData.mpINST_msg_edit02;
    MT_CTSTR t10 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 3u);
    cGUIObject* t11 = getObjectFromId(static_cast<cGUIInstance*>(t9), 3u);
    mData.mpOBJ_msg_edit02_m_section00 = static_cast<cGUIObjMessage*>(t11);
    setObjectMessage(t11, t10, 0u, false);
    cGUIInstAnimation* t12 = mData.mpINST_msg_edit03;
    MT_CTSTR t13 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 4u);
    cGUIObject* t14 = getObjectFromId(static_cast<cGUIInstance*>(t12), 3u);
    mData.mpOBJ_msg_edit03_m_section00 = static_cast<cGUIObjMessage*>(t14);
    setObjectMessage(t14, t13, 0u, false);
    cGUIInstAnimation* t15 = mData.mpINST_msg_edit04;
    MT_CTSTR t16 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 5u);
    cGUIObject* t17 = getObjectFromId(static_cast<cGUIInstance*>(t15), 3u);
    mData.mpOBJ_msg_edit04_m_section00 = static_cast<cGUIObjMessage*>(t17);
    setObjectMessage(t17, t16, 0u, false);
    cGUIInstAnimation* t18 = mData.mpINST_msg_edit05;
    MT_CTSTR t19 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 20u);
    cGUIObject* t20 = getObjectFromId(static_cast<cGUIInstance*>(t18), 3u);
    mData.mpOBJ_msg_edit05_m_section00 = static_cast<cGUIObjMessage*>(t20);
    setObjectMessage(t20, t19, 0u, false);
    cGUIObject* t21 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_check), 2u);
    mData.mpOBJ_msg_check_m_keyword = static_cast<cGUIObjMessage*>(t21);
    setObjectMessage(t21, "12", 0u, false);
    cGUIObject* t22 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_clanname), 8u);
    mData.mpOBJ_msg_clanname_m_keywordedit = static_cast<cGUIObjMessage*>(t22);
    setObjectMessage(t22, "14", 0u, false);
    if (mData.mpOBJ_msg_clanname_m_keywordedit != nullptr) {
        mData.mpOBJ_msg_clanname_m_keywordedit->mMsgAttr = mData.mpOBJ_msg_clanname_m_keywordedit->mMsgAttr & 0xFFFFFFF7u;
        cGUIObject* t23 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_clanname), 4u);
        mData.mpOBJ_msg_clanname_m_abbreviate = static_cast<cGUIObjMessage*>(t23);
        setObjectMessage(t23, "14", 0u, false);
        if (mData.mpOBJ_msg_clanname_m_abbreviate != nullptr) {
            mData.mpOBJ_msg_clanname_m_abbreviate->mMsgAttr = mData.mpOBJ_msg_clanname_m_abbreviate->mMsgAttr & 0xFFFFFFF7u;
            cGUIObject* t24 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_pop), 3u);
            mData.mpOBJ_msg_pop_m_section00 = static_cast<cGUIObjMessage*>(t24);
            setObjectMessage(t24, "15", 0u, false);
            cGUIObject* t25 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_pop), 6u);
            mData.mpOBJ_msg_pop_m_text = static_cast<cGUIObjMessage*>(t25);
            setObjectMessage(t25, "16", 0u, false);
            setObjectMessageFromId(4u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 21u), 0u, false);
            setObjectMessageFromId(4u, 4u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 22u), 0u, false);
            setupInstances();
            setupObjects();
            setupRefrenceUIs();
            setupControls();
        } else {
            cGUIObject* t24 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_pop), 3u);
            mData.mpOBJ_msg_pop_m_section00 = static_cast<cGUIObjMessage*>(t24);
            setObjectMessage(t24, "15", 0u, false);
            cGUIObject* t25 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_pop), 6u);
            mData.mpOBJ_msg_pop_m_text = static_cast<cGUIObjMessage*>(t25);
            setObjectMessage(t25, "16", 0u, false);
            setObjectMessageFromId(4u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 21u), 0u, false);
            setObjectMessageFromId(4u, 4u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 22u), 0u, false);
            setupInstances();
            setupObjects();
            setupRefrenceUIs();
            setupControls();
        }
    } else {
        cGUIObject* t23 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_clanname), 4u);
        mData.mpOBJ_msg_clanname_m_abbreviate = static_cast<cGUIObjMessage*>(t23);
        setObjectMessage(t23, "14", 0u, false);
        if (mData.mpOBJ_msg_clanname_m_abbreviate != nullptr) {
            mData.mpOBJ_msg_clanname_m_abbreviate->mMsgAttr = mData.mpOBJ_msg_clanname_m_abbreviate->mMsgAttr & 0xFFFFFFF7u;
            cGUIObject* t24 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_pop), 3u);
            mData.mpOBJ_msg_pop_m_section00 = static_cast<cGUIObjMessage*>(t24);
            setObjectMessage(t24, "15", 0u, false);
            cGUIObject* t25 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_pop), 6u);
            mData.mpOBJ_msg_pop_m_text = static_cast<cGUIObjMessage*>(t25);
            setObjectMessage(t25, "16", 0u, false);
            setObjectMessageFromId(4u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 21u), 0u, false);
            setObjectMessageFromId(4u, 4u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 22u), 0u, false);
            setupInstances();
            setupObjects();
            setupRefrenceUIs();
            setupControls();
        } else {
            cGUIObject* t24 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_pop), 3u);
            mData.mpOBJ_msg_pop_m_section00 = static_cast<cGUIObjMessage*>(t24);
            setObjectMessage(t24, "15", 0u, false);
            cGUIObject* t25 = getObjectFromId(static_cast<cGUIInstance*>(mData.mpINST_msg_pop), 6u);
            mData.mpOBJ_msg_pop_m_text = static_cast<cGUIObjMessage*>(t25);
            setObjectMessage(t25, "16", 0u, false);
            setObjectMessageFromId(4u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 21u), 0u, false);
            setObjectMessageFromId(4u, 4u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 22u), 0u, false);
            setupInstances();
            setupObjects();
            setupRefrenceUIs();
            setupControls();
        }
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIClanEditBase::updateInit);
}

void uGUIClanEditBase::kill() {
    this->uGUIBase::kill();
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

void uGUIClanEditBase::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIClanEditBase::initFlow() {
}

__attribute__((weak)) void uGUIClanEditBase::setupInstances() {
}

__attribute__((weak)) void uGUIClanEditBase::setupObjects() {
}

__attribute__((weak)) void uGUIClanEditBase::setupRefrenceUIs() {
}

__attribute__((weak)) void uGUIClanEditBase::setupButton() {
    DDON_STUB("uGUIClanEditBase::setupButton")
    /* stub */
}

void uGUIClanEditBase::setupControls() {
    mControlMgr.setup(static_cast<uGUIBase*>(this));
    mControlMgr.mIsChildPosTransfar = false;
}

__attribute__((weak)) void uGUIClanEditBase::setupButtonControl(u32 controlId, u32 parentId, s32 movePos, s32 initPos) {
    DDON_STUB("uGUIClanEditBase::setupButtonControl")
    /* stub */
}

u32 uGUIClanEditBase::evCtrlMove(cControl::Message* msg) {
    return onEvCtrlMove(msg);
}

u32 uGUIClanEditBase::evCtrlDecide(cControl::Message* msg) {
    return onEvCtrlDecide(msg);
}

u32 uGUIClanEditBase::evCtrlCancel(cControl::Message* msg) {
    return onEvCtrlCancel(msg);
}

u32 uGUIClanEditBase::onEvCtrlMove(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

u32 uGUIClanEditBase::onEvCtrlDecide(cControl::Message* msg) {
    setInputEvent(4u);
    return 0;
}

u32 uGUIClanEditBase::onEvCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

void uGUIClanEditBase::updateInit() {
    onUpdateInit();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIClanEditBase::updateWait);
}

void uGUIClanEditBase::updateWait() {
    onUpdateWait();
}

__attribute__((weak)) void uGUIClanEditBase::onUpdateInit() {
}

__attribute__((weak)) void uGUIClanEditBase::onUpdateWait() {
}

inline uGUIClanEditBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanEditBase::MyDTI uGUIClanEditBase::DTI("uGUIClanEditBase", &::uGUIBase::DTI, 4560ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanEditBase::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanEditBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIClanEditInputName::getDTI() const {
    return uGUIClanEditInputName::DTI;
}

uGUIClanEditInputName::~uGUIClanEditInputName() {
}

s32 uGUIClanEditInputName::getSMenuCursorY() {
    const s32 pos_v = mControlMgr.getCurrentPos(0u);
    if (pos_v == 1) {
        const s32 button_id = mControlMgr.getCurrentPos(1u);
        if (button_id == 1) {
            return (sMenu::mpInstance)->mMenuSetClanName.cMenuBase::getIndexFromMenuId(2);
        } else {
            if (button_id == 0) {
                return (sMenu::mpInstance)->mMenuSetClanName.cMenuBase::getIndexFromMenuId(1);
            } else {
                return (sMenu::mpInstance)->mMenuSetClanName.cMenuBase::getIndexFromMenuId(0);
            }
        }
    } else {
        return (sMenu::mpInstance)->mMenuSetClanName.cMenuBase::getIndexFromMenuId(0);
    }
}

void uGUIClanEditInputName::setupInstances() {
    cGUIInstance* t0 = getInstance(11u, false);
    if (t0 == nullptr) {
        return;
    }
    t0->setVisible(false);
}

void uGUIClanEditInputName::setupObjects() {
    setObjectMessageFromId(40u, 6u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 16u), 0u, false);
    setObjectMessageFromId(106u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 17u), 0u, false);
}

__attribute__((weak)) void uGUIClanEditInputName::setupTextBox() {
    DDON_STUB("uGUIClanEditInputName::setupTextBox")
    /* stub */
}

void uGUIClanEditInputName::onDecide() {
    setMessage();
}

void uGUIClanEditInputName::setMessage() {
    snprintf(&(sMenu::mpInstance)->mMenuSetClanName.mClanName[0], 13ul, "%s", mTextBox.mMsg.ptr());
}

void uGUIClanEditInputName::setButtonEnable(s32 buttonId) {
    if (buttonId == 0) {
        mButtons.elems[(static_cast<unsigned int>(buttonId) <= 1) ? static_cast<unsigned int>(buttonId) : 0u].setEnable(sMenu::getInstance()->mMenuSetClanName.isEnableMenu(1));
    } else {
        mButtons.elems[(static_cast<unsigned int>(buttonId) <= 1) ? static_cast<unsigned int>(buttonId) : 0u].setEnable(true);
    }
}

inline uGUIClanEditInputName::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanEditInputName::MyDTI uGUIClanEditInputName::DTI("uGUIClanEditInputName", &::uGUIClanEditInputNameBase::DTI, 4912ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanEditInputName::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanEditInputName::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIClanEditInputNameBase::getDTI() const {
    return uGUIClanEditInputNameBase::DTI;
}

uGUIClanEditInputNameBase::~uGUIClanEditInputNameBase() {
}

void uGUIClanEditInputNameBase::initFlow() {
    setFlowAndInit(6u, false);
}

void uGUIClanEditInputNameBase::setupRefrenceUIs() {
    setupTextBox();
    setupButton();
}

__attribute__((weak)) void uGUIClanEditInputNameBase::setupControls() {
    DDON_STUB("uGUIClanEditInputNameBase::setupControls")
    /* stub */
}

__attribute__((weak)) void uGUIClanEditInputNameBase::setupTextBox() {
}

__attribute__((weak)) void uGUIClanEditInputNameBase::moveInput() {
    DDON_STUB("uGUIClanEditInputNameBase::moveInput")
    /* stub */
}

void uGUIClanEditInputNameBase::moveEvent() {
    if (getInputEvent() != 4) {
        if (getInputEvent() == 67) {
            s32 t0 = mControlMgr.getCurrentPos(0u);
            if (mTextBox.isWakeupKeyboard()) {
                mTextBox.closeKeyboard(true);
                if (t0 == 1) {
                    if (mControlMgr.getCurrentPos(1u) == 0) {
                        onDecide();
                    }
                }
            } else {
                if (t0 == 1) {
                    if (mControlMgr.getCurrentPos(1u) == 0) {
                        onDecide();
                    }
                } else {
                    if (t0 == 0) {
                        mTextBox.wakeupKeyboard(1);
                    }
                }
            }
        }
    } else {
        s32 t0 = mControlMgr.getCurrentPos(0u);
        if (mTextBox.isWakeupKeyboard()) {
            mTextBox.closeKeyboard(true);
            if (t0 == 1) {
                if (mControlMgr.getCurrentPos(1u) == 0) {
                    onDecide();
                }
            }
        } else {
            if (t0 == 1) {
                if (mControlMgr.getCurrentPos(1u) == 0) {
                    onDecide();
                }
            } else {
                if (t0 == 0) {
                    mTextBox.wakeupKeyboard(1);
                }
            }
        }
    }
}

__attribute__((weak)) u32 uGUIClanEditInputNameBase::onEvCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIClanEditInputNameBase::onEvCtrlDecide")
    return {};
}

void uGUIClanEditInputNameBase::onUpdateInit() {
    onUpdateWait();
}

void uGUIClanEditInputNameBase::onUpdateWait() {
    if (mRefrenceUIArray.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            static_cast<cReferenceUIBase*>(mRefrenceUIArray.getBuffer()[static_cast<int>(i0_3)])->setFocus(false);
            if ((i0_3 + 1u) < mRefrenceUIArray.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    s32 t0 = mControlMgr.getCurrentPos(0u);
    if (t0 == 1) {
        s32 t1 = mControlMgr.getCurrentPos(1u);
        mButtons.elems[(static_cast<unsigned int>(t1) <= 1) ? static_cast<unsigned int>(t1) : 0u].setFocus(true);
    } else {
        if (t0 == 0) {
            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
        }
    }
    setMessage();
    setButtonEnable(0);
    setButtonEnable(1);
    if (mRefrenceUIArray.mLength != 0) {
        for (unsigned int i2_3 = 0;;) {
            static_cast<cReferenceUIBase*>(mRefrenceUIArray.getBuffer()[static_cast<int>(i2_3)])->update();
            if ((i2_3 + 1u) < mRefrenceUIArray.mLength) {
                i2_3 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void uGUIClanEditInputNameBase::onDecide() {
}

inline uGUIClanEditInputNameBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanEditInputNameBase::MyDTI uGUIClanEditInputNameBase::DTI("uGUIClanEditInputNameBase", &::uGUIClanEditBase::DTI, 4912ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanEditInputNameBase::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanEditInputNameBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIClanEditInputNickname::getDTI() const {
    return uGUIClanEditInputNickname::DTI;
}

uGUIClanEditInputNickname::~uGUIClanEditInputNickname() {
}

s32 uGUIClanEditInputNickname::getSMenuCursorY() {
    const s32 pos_v = mControlMgr.getCurrentPos(0u);
    if (pos_v == 1) {
        const s32 button_id = mControlMgr.getCurrentPos(1u);
        if (button_id == 1) {
            return (sMenu::mpInstance)->mMenuSetClanNickName.cMenuBase::getIndexFromMenuId(2);
        } else {
            if (button_id == 0) {
                return (sMenu::mpInstance)->mMenuSetClanNickName.cMenuBase::getIndexFromMenuId(1);
            } else {
                return (sMenu::mpInstance)->mMenuSetClanNickName.cMenuBase::getIndexFromMenuId(0);
            }
        }
    } else {
        return (sMenu::mpInstance)->mMenuSetClanNickName.cMenuBase::getIndexFromMenuId(0);
    }
}

void uGUIClanEditInputNickname::setupInstances() {
    cGUIInstance* t0 = getInstance(12u, false);
    if (t0 == nullptr) {
        return;
    }
    t0->setVisible(false);
}

void uGUIClanEditInputNickname::setupObjects() {
    setObjectMessageFromId(40u, 6u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 18u), 0u, false);
    setObjectMessageFromId(106u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 19u), 0u, false);
}

__attribute__((weak)) void uGUIClanEditInputNickname::setupTextBox() {
    DDON_STUB("uGUIClanEditInputNickname::setupTextBox")
    /* stub */
}

void uGUIClanEditInputNickname::onDecide() {
    setMessage();
}

void uGUIClanEditInputNickname::setMessage() {
    snprintf(&(sMenu::mpInstance)->mMenuSetClanNickName.mClanNickName[0], 4ul, "%s", mTextBox.mMsg.ptr());
}

void uGUIClanEditInputNickname::setButtonEnable(s32 buttonId) {
    if (buttonId == 0) {
        mButtons.elems[(static_cast<unsigned int>(buttonId) <= 1) ? static_cast<unsigned int>(buttonId) : 0u].setEnable(sMenu::getInstance()->mMenuSetClanNickName.isEnableMenu(1));
    } else {
        mButtons.elems[(static_cast<unsigned int>(buttonId) <= 1) ? static_cast<unsigned int>(buttonId) : 0u].setEnable(true);
    }
}

inline uGUIClanEditInputNickname::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanEditInputNickname::MyDTI uGUIClanEditInputNickname::DTI("uGUIClanEditInputNickname", &::uGUIClanEditInputNameBase::DTI, 4912ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanEditInputNickname::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanEditInputNickname::MyDTI::newInstance")
    return nullptr;
}

