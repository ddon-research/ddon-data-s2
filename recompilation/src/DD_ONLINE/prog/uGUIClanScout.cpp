// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIClanScout.h"
#include "Protocol/PacketData/Clan.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/UserSession/S2C.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIPageList.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cMenuSupport.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIClanScout::getDTI() const {
    return uGUIClanScout::DTI;
}

inline void uGUIClanScout::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIClanScout::DTI)->memFree(p_addr);
}

uGUIClanScout::uGUIClanScout() {
    DDON_STUB("uGUIClanScout::uGUIClanScout")
    /* stub */
}

uGUIClanScout::~uGUIClanScout() {
    DDON_STUB("uGUIClanScout::~uGUIClanScout")
    /* stub */
}

s32 uGUIClanScout::getSMenuCursorX() {
    return mControlMgr.getCurrentPos(2u);
}

s32 uGUIClanScout::getSMenuCursorY() {
    return mControlMgr.getCurrentPos(1u);
}

void uGUIClanScout::initFlow() {
    setFlowAndInit(8u, false);
}

void uGUIClanScout::setupInstances() {
    if (mpInstNullDesign == nullptr) {
        return;
    }
    mpInstNullDesign->setVisible(false);
}

void uGUIClanScout::setupObjects() {
    setObjectMessageFromId(4u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 21u), 0u, false);
    setObjectMessageFromId(4u, 4u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 22u), 0u, false);
    setObjectMessageFromId(108u, 4u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 5u), 0u, false);
    setObjectMessageFromId(108u, 12u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 8u), 0u, false);
    MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 28u);
    cGUIObject* t1 = getObjectFromId(155u, 2u);
    mpOBJ_msg_no_list_m_txt = static_cast<cGUIObjMessage*>(t1);
    setObjectMessage(t1, t0, 0u, false);
}

__attribute__((weak)) void uGUIClanScout::setupRefrenceUIs() {
    DDON_STUB("uGUIClanScout::setupRefrenceUIs")
    /* stub */
}

__attribute__((weak)) void uGUIClanScout::setupControls() {
    DDON_STUB("uGUIClanScout::setupControls")
    /* stub */
}

void uGUIClanScout::updateControls() {
    mControlMgr.offAllFocus();
    mControlMgr.setCategoryFocus(0u, true);
    if (static_cast<int>(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getClanScoutEntryListPacket()->m_SearchResult.mLength) > 0) {
        const s32 new_page_num = mPageListScoutEntry.getPageNum();
        if (mControlMgr.mControl[2].mItemNum != static_cast<unsigned int>(new_page_num)) {
            const s32 page_pos = mControlMgr.getCurrentPos(2u);
            mControlMgr.resetItemNum(2u, static_cast<u32>(new_page_num), 0u);
            if (new_page_num > 0) {
                mControlMgr.setCurrentPos(2u, page_pos);
                const s32 disp_item_num = mPageListScoutEntry.getDispItemNum();
                if (mControlMgr.mControl[1].mItemNum != static_cast<unsigned int>(disp_item_num)) {
                    const s32 cursor_pos = mControlMgr.getCurrentPos(1u);
                    mControlMgr.resetItemNum(1u, static_cast<u32>(disp_item_num), 0u);
                    if (disp_item_num > 0) {
                        mControlMgr.setCurrentPos(1u, cursor_pos);
                    }
                    mControlMgr.setCategoryFocus(1u, true);
                    mPageListScoutEntry.updateMouseTouchList();
                } else {
                    mControlMgr.setCategoryFocus(1u, true);
                    mPageListScoutEntry.updateMouseTouchList();
                }
            } else {
                const s32 disp_item_num = mPageListScoutEntry.getDispItemNum();
                if (mControlMgr.mControl[1].mItemNum != static_cast<unsigned int>(disp_item_num)) {
                    const s32 cursor_pos = mControlMgr.getCurrentPos(1u);
                    mControlMgr.resetItemNum(1u, static_cast<u32>(disp_item_num), 0u);
                    if (disp_item_num > 0) {
                        mControlMgr.setCurrentPos(1u, cursor_pos);
                    }
                    mControlMgr.setCategoryFocus(1u, true);
                    mPageListScoutEntry.updateMouseTouchList();
                } else {
                    mControlMgr.setCategoryFocus(1u, true);
                    mPageListScoutEntry.updateMouseTouchList();
                }
            }
        } else {
            const s32 disp_item_num = mPageListScoutEntry.getDispItemNum();
            if (mControlMgr.mControl[1].mItemNum != static_cast<unsigned int>(disp_item_num)) {
                const s32 cursor_pos = mControlMgr.getCurrentPos(1u);
                mControlMgr.resetItemNum(1u, static_cast<u32>(disp_item_num), 0u);
                if (disp_item_num > 0) {
                    mControlMgr.setCurrentPos(1u, cursor_pos);
                }
                mControlMgr.setCategoryFocus(1u, true);
                mPageListScoutEntry.updateMouseTouchList();
            } else {
                mControlMgr.setCategoryFocus(1u, true);
                mPageListScoutEntry.updateMouseTouchList();
            }
        }
    } else {
        mPageListScoutEntry.updateMouseTouchList();
    }
}

__attribute__((weak)) void uGUIClanScout::moveInput() {
    DDON_STUB("uGUIClanScout::moveInput")
    /* stub */
}

void uGUIClanScout::moveEvent() {
    const u32 event_id = getInputEvent();
    mPageListScoutEntry.moveEvent(event_id);
    if ((mInputEventId & 0xFFFFFFFEu) != 52) {
        return;
    }
    (&mPageListScoutEntry)->evMovePage();
}

u32 uGUIClanScout::evCtrlDecide(cControl::Message* msg) {
    setInputEvent(4u);
    return 0;
}

u32 uGUIClanScout::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

void uGUIClanScout::onUpdateInit() {
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 4396) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 4396)) | 2;
}

__attribute__((weak)) void uGUIClanScout::onUpdateWait() {
    DDON_STUB("uGUIClanScout::onUpdateWait")
    /* stub */
}

__attribute__((weak)) void uGUIClanScout::onDecide() {
}

inline uGUIClanScout::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanScout::MyDTI uGUIClanScout::DTI("uGUIClanScout", &::uGUIClanScoutBase::DTI, 5888ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanScout::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanScout::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void uGUIClanScout::ScoutEntry::setup(s32 index, uGUIClanScout* owner, cGUIInstNull* pINST_Null, cGUIInstance* pINST_duplicated) {
    DDON_STUB("uGUIClanScout::ScoutEntry::setup")
    /* stub */
}

const MtDTI& uGUIClanScout::cGUIPageListScoutEntry::getDTI() const {
    return uGUIClanScout::cGUIPageListScoutEntry::DTI;
}

inline void* uGUIClanScout::cGUIPageListScoutEntry::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uGUIClanScout::cGUIPageListScoutEntry::DTI)->memAlloc(sz, align, uGUIClanScout::cGUIPageListScoutEntry::DTI.getID());
}

inline void uGUIClanScout::cGUIPageListScoutEntry::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIClanScout::cGUIPageListScoutEntry::DTI)->memFree(p_addr);
}

s32 uGUIClanScout::cGUIPageListScoutEntry::getItemNum() const {
    return static_cast<s32>(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getClanScoutEntryListPacket()->m_SearchResult.size());
}

s32 uGUIClanScout::cGUIPageListScoutEntry::getPageItemNum() const {
    return 10;
}

__attribute__((weak)) void uGUIClanScout::cGUIPageListScoutEntry::getMouseCollision(cGUIInstance* & instance, cGUIObject* & object, s32 dispItemIndex) const {
    DDON_STUB("uGUIClanScout::cGUIPageListScoutEntry::getMouseCollision")
    /* stub */
}

__attribute__((weak)) void uGUIClanScout::cGUIPageListScoutEntry::callbackShowItem(s32 dispItemIndex, s32 itemIndex) {
    DDON_STUB("uGUIClanScout::cGUIPageListScoutEntry::callbackShowItem")
    /* stub */
}

__attribute__((weak)) void uGUIClanScout::cGUIPageListScoutEntry::callbackHideItem(s32 dispItemIndex) {
    DDON_STUB("uGUIClanScout::cGUIPageListScoutEntry::callbackHideItem")
    /* stub */
}

inline uGUIClanScout::cGUIPageListScoutEntry::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanScout::cGUIPageListScoutEntry::MyDTI uGUIClanScout::cGUIPageListScoutEntry::DTI("uGUIClanScout::cGUIPageListScoutEntry", &::cGUIPageList::DTI, 72ul, 0u, 0u);

MtObject* uGUIClanScout::cGUIPageListScoutEntry::MyDTI::newInstance() const {
    return new (16u) uGUIClanScout::cGUIPageListScoutEntry;
}

const MtDTI& uGUIClanScoutBase::getDTI() const {
    return uGUIClanScoutBase::DTI;
}

inline void uGUIClanScoutBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIClanScoutBase::DTI)->memFree(p_addr);
}

uGUIClanScoutBase::~uGUIClanScoutBase() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIClanScoutBase::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CLAN_SCOUT_GUI"), 129u, 1434093049l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_CLAN_SCOUT_GMD", 0u);
}

void uGUIClanScoutBase::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(11u), true);
    setPlay(true);
    initFlow();
    setupInstances();
    setupObjects();
    setupRefrenceUIs();
    setupControls();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIClanScoutBase::updateInit);
}

void uGUIClanScoutBase::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIClanScoutBase::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIClanScoutBase::initFlow() {
}

__attribute__((weak)) void uGUIClanScoutBase::setupInstances() {
}

__attribute__((weak)) void uGUIClanScoutBase::setupObjects() {
}

__attribute__((weak)) void uGUIClanScoutBase::setupRefrenceUIs() {
}

void uGUIClanScoutBase::setupControls() {
    mControlMgr.setup(static_cast<uGUIBase*>(this));
    mControlMgr.mIsChildPosTransfar = false;
}

void uGUIClanScoutBase::updateInit() {
    onUpdateInit();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIClanScoutBase::updateWait);
}

void uGUIClanScoutBase::updateWait() {
    onUpdateWait();
}

__attribute__((weak)) void uGUIClanScoutBase::onUpdateInit() {
}

__attribute__((weak)) void uGUIClanScoutBase::onUpdateWait() {
}

inline uGUIClanScoutBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanScoutBase::MyDTI uGUIClanScoutBase::DTI("uGUIClanScoutBase", &::uGUIBase::DTI, 3456ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanScoutBase::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanScoutBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIClanScoutEntry::getDTI() const {
    return uGUIClanScoutEntry::DTI;
}

inline void uGUIClanScoutEntry::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIClanScoutEntry::DTI)->memFree(p_addr);
}

uGUIClanScoutEntry::uGUIClanScoutEntry() {
    DDON_STUB("uGUIClanScoutEntry::uGUIClanScoutEntry")
    /* stub */
}

uGUIClanScoutEntry::~uGUIClanScoutEntry() {
}

s32 uGUIClanScoutEntry::getSMenuCursorY() {
    const s32 pos_v = mControlMgr.getCurrentPos(0u);
    switch (static_cast<unsigned int>(pos_v)) {
        case 0:
        {
            return (sMenu::mpInstance)->mMenuClanScoutEntry.cMenuBase::getIndexFromMenuId(2);
        }
        case 1:
        {
            return (sMenu::mpInstance)->mMenuClanScoutEntry.cMenuBase::getIndexFromMenuId(3);
        }
        case 2:
        {
            return (sMenu::mpInstance)->mMenuClanScoutEntry.cMenuBase::getIndexFromMenuId(5);
        }
        case 3:
        {
            return (sMenu::mpInstance)->mMenuClanScoutEntry.cMenuBase::getIndexFromMenuId(6);
        }
        case 4:
        {
            const s32 button_id = mControlMgr.getCurrentPos(1u);
            if (button_id == 1) {
                return (sMenu::mpInstance)->mMenuClanScoutEntry.cMenuBase::getIndexFromMenuId(9);
            } else {
                if (button_id == 0) {
                    return (sMenu::mpInstance)->mMenuClanScoutEntry.cMenuBase::getIndexFromMenuId(8);
                } else {
                    return (sMenu::mpInstance)->mMenuClanScoutEntry.cMenuBase::getIndexFromMenuId(10);
                }
            }
            break;
        }
        default:
        {
            return (sMenu::mpInstance)->mMenuClanScoutEntry.cMenuBase::getIndexFromMenuId(10);
        }
    }
}

void uGUIClanScoutEntry::initFlow() {
    setFlowAndInit(3u, false);
}

void uGUIClanScoutEntry::setupInstances() {
    mpINST_window_frame = static_cast<cGUIInstAnimation*>(getInstance(3u, false));
    mpINST_Null_checklist00 = static_cast<cGUIInstNull*>(getInstance(26u, false));
}

void uGUIClanScoutEntry::setupObjects() {
    setObjectMessageFromId(4u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 21u), 0u, false);
    setObjectMessageFromId(4u, 4u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 22u), 0u, false);
    setObjectMessageFromId(15u, 3u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 2u), 0u, false);
    setObjectMessageFromId(17u, 3u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 3u), 0u, false);
    setObjectMessageFromId(18u, 3u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 4u), 0u, false);
    setObjectMessageFromId(107u, 3u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 8u), 0u, false);
}

__attribute__((weak)) void uGUIClanScoutEntry::setupRefrenceUIs() {
    DDON_STUB("uGUIClanScoutEntry::setupRefrenceUIs")
    /* stub */
}

__attribute__((weak)) void uGUIClanScoutEntry::setupControls() {
    DDON_STUB("uGUIClanScoutEntry::setupControls")
    /* stub */
}

__attribute__((weak)) void uGUIClanScoutEntry::moveInput() {
    DDON_STUB("uGUIClanScoutEntry::moveInput")
    /* stub */
}

void uGUIClanScoutEntry::moveEvent() {
    if (static_cast<int>(getInputEvent()) <= 55) {
        if (getInputEvent() == 4) {
            evDecide();
        }
    } else {
        if (getInputEvent() != 56) {
            if (getInputEvent() == 57) {
                if (mControlMgr.getCurrentPos(0u) == 1) {
                    if (mCheckList.mPage == 1) {
                        mCheckList.setForm(uGUIBase::cReferenceUICheckListForClan::FORM_TIME, mClanParamDay, 0u, false);
                    } else {
                        mCheckList.setVisible(false);
                        if (mpINST_window_frame != nullptr) {
                            mpINST_window_frame->setVisible(true);
                        }
                    }
                } else {
                    mCheckList.setVisible(false);
                    if (mpINST_window_frame != nullptr) {
                        mpINST_window_frame->setVisible(true);
                    }
                }
            } else {
                if (getInputEvent() == 67) {
                    evDecide();
                }
            }
        } else {
            evCheckListDecide();
        }
    }
}

u32 uGUIClanScoutEntry::evCtrlMove(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

__attribute__((weak)) u32 uGUIClanScoutEntry::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIClanScoutEntry::evCtrlDecide")
    return {};
}

u32 uGUIClanScoutEntry::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

__attribute__((weak)) void uGUIClanScoutEntry::evDecide() {
    DDON_STUB("uGUIClanScoutEntry::evDecide")
    /* stub */
}

__attribute__((weak)) void uGUIClanScoutEntry::evCheckListDecide() {
    sMenu* v0_10 = sMenu::getInstance();
    s32 t0 = mControlMgr.getCurrentPos(0u);
    if (t0 != 2) {
        if (t0 == 1) {
            if (mCheckList.getPage() == 1) {
                v0_10->mMenuClanScoutEntry.mEntryParam.m_unActiveTime = 0;
                for (unsigned int i0_3 = 0;;) {
                    if (i0_3 >= mCheckList.mCheckBoxNum) {
                        break;
                    } else {
                        if (!mCheckList.isCheck(static_cast<s32>(i0_3))) {
                            i0_3 += 1u;
                        } else {
                            v0_10->mMenuClanScoutEntry.mEntryParam.m_unActiveTime = static_cast<unsigned int>(static_cast<unsigned long>(v0_10->mMenuClanScoutEntry.mEntryParam.m_unActiveTime) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(i0_3 + 1u) & 31)));
                            break;
                        }
                    }
                }
                v0_10->mMenuClanScoutEntry.mEntryParam.m_unActiveDays = mClanParamDay;
                mCheckList.setVisible(false);
                if (mpINST_window_frame != nullptr) {
                    mpINST_window_frame->setVisible(true);
                }
                mClanPolicyMessages.applyPolicy(sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unMotto, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveDays, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic);
                return;
            } else {
                if (mCheckList.getPage() != 0) {
                    mCheckList.setVisible(false);
                    if (mpINST_window_frame != nullptr) {
                        mpINST_window_frame->setVisible(true);
                    }
                    mClanPolicyMessages.applyPolicy(sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unMotto, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveDays, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic);
                    return;
                } else {
                    mClanParamDay = 0;
                    unsigned int i2_3 = 0;
                    unsigned int v3_3;
                    for (;;) {
                        if (i2_3 >= mCheckList.mCheckBoxNum) {
                            mCheckList.setForm(uGUIBase::cReferenceUICheckListForClan::FORM_TIME, v0_10->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, 1u, false);
                            return;
                        } else {
                            if (!mCheckList.isCheck(static_cast<s32>(i2_3))) {
                                i2_3 += 1u;
                            } else {
                                v3_3 = i2_3 + 1u;
                                break;
                            }
                        }
                    }
                    mClanParamDay = static_cast<unsigned int>(static_cast<unsigned long>(mClanParamDay) | (1ul << static_cast<unsigned long>(v3_3 & 31u)));
                    mCheckList.setForm(uGUIBase::cReferenceUICheckListForClan::FORM_TIME, v0_10->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, 1u, false);
                    return;
                }
            }
        } else {
            if (t0 != 0) {
                mCheckList.setVisible(false);
                if (mpINST_window_frame != nullptr) {
                    mpINST_window_frame->setVisible(true);
                }
                mClanPolicyMessages.applyPolicy(sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unMotto, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveDays, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic);
                return;
            } else {
                v0_10->mMenuClanScoutEntry.mEntryParam.m_unMotto = 0;
                if (mCheckList.mCheckBoxNum == 0) {
                    mCheckList.setVisible(false);
                    if (mpINST_window_frame != nullptr) {
                        mpINST_window_frame->setVisible(true);
                    }
                    mClanPolicyMessages.applyPolicy(sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unMotto, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveDays, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic);
                    return;
                } else {
                    for (unsigned int i4_3 = 0;;) {
                        if (mCheckList.isCheck(static_cast<s32>(i4_3))) {
                            v0_10->mMenuClanScoutEntry.mEntryParam.m_unMotto = static_cast<unsigned int>(static_cast<unsigned long>(v0_10->mMenuClanScoutEntry.mEntryParam.m_unMotto) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(i4_3 + 1u) & 31)));
                        }
                        if ((i4_3 + 1u) < mCheckList.mCheckBoxNum) {
                            i4_3 += 1u;
                        } else {
                            break;
                        }
                    }
                    mCheckList.setVisible(false);
                    if (mpINST_window_frame != nullptr) {
                        mpINST_window_frame->setVisible(true);
                    }
                    mClanPolicyMessages.applyPolicy(sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unMotto, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveDays, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic);
                    return;
                }
            }
        }
    } else {
        v0_10->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic = 0;
        if (mCheckList.mCheckBoxNum == 0) {
            mCheckList.setVisible(false);
            if (mpINST_window_frame != nullptr) {
                mpINST_window_frame->setVisible(true);
            }
            mClanPolicyMessages.applyPolicy(sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unMotto, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveDays, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic);
            return;
        } else {
            for (unsigned int i7_3 = 0;;) {
                if (mCheckList.isCheck(static_cast<s32>(i7_3))) {
                    v0_10->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic = static_cast<unsigned int>(static_cast<unsigned long>(v0_10->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(i7_3 + 1u) & 31)));
                }
                if ((i7_3 + 1u) < mCheckList.mCheckBoxNum) {
                    i7_3 += 1u;
                } else {
                    break;
                }
            }
            mCheckList.setVisible(false);
            if (mpINST_window_frame != nullptr) {
                mpINST_window_frame->setVisible(true);
            }
            mClanPolicyMessages.applyPolicy(sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unMotto, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveDays, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic);
            return;
        }
    }
}

__attribute__((weak)) void uGUIClanScoutEntry::updateFocus() {
    DDON_STUB("uGUIClanScoutEntry::updateFocus")
    /* stub */
}

inline void uGUIClanScoutEntry::updateKeyword() {
    mClanPolicyMessages.applyPolicy(sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unMotto, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveDays, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unActiveTime, sMenu::getInstance()->mMenuClanScoutEntry.mEntryParam.m_unCharacteristic);
}

void uGUIClanScoutEntry::onUpdateInit() {
    updateKeyword();
}

__attribute__((weak)) void uGUIClanScoutEntry::onUpdateWait() {
    DDON_STUB("uGUIClanScoutEntry::onUpdateWait")
    /* stub */
}

__attribute__((weak)) void uGUIClanScoutEntry::onDecide() {
    DDON_STUB("uGUIClanScoutEntry::onDecide")
    /* stub */
}

inline uGUIClanScoutEntry::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanScoutEntry::MyDTI uGUIClanScoutEntry::DTI("uGUIClanScoutEntry", &::uGUIClanScoutBase::DTI, 6496ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanScoutEntry::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanScoutEntry::MyDTI::newInstance")
    return nullptr;
}

