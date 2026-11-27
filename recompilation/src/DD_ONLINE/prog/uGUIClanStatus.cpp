// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUIClanStatus.h"
#include "Protocol/PacketData/Clan.h"
#include "Protocol/PacketData/Community.h"
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
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cMenuBaseClan.h"
#include "cMenuSupport.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sUnit.h"
#include "uGUIBase.h"
#include "uGUIMenuAreaInfo.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIClanStatus::getDTI() const {
    return uGUIClanStatus::DTI;
}

__attribute__((weak)) void uGUIClanStatus::setHistoryListItems(const uGUIClanStatus::cHistoryListItems& historyListItems) {
    DDON_STUB("uGUIClanStatus::setHistoryListItems")
    /* stub */
}

uGUIClanStatus::uGUIClanStatus() {
    DDON_STUB("uGUIClanStatus::uGUIClanStatus")
    /* stub */
}

__attribute__((noinline)) uGUIClanStatus::~uGUIClanStatus() {
    if (mpGUIAreaInfo == nullptr) {
        return;
    }
    mpGUIAreaInfo->kill();
    mpGUIAreaInfo = nullptr;
}

void uGUIClanStatus::kill() {
    if (mpGUIAreaInfo != nullptr) {
        mpGUIAreaInfo->kill();
        mpGUIAreaInfo = nullptr;
    }
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

__attribute__((weak)) void uGUIClanStatus::move() {
    DDON_STUB("uGUIClanStatus::move")
    /* stub */
}

void uGUIClanStatus::updatePtr() {
    if (mpGUIAreaInfo == nullptr) {
        return;
    }
    if (mpGUIAreaInfo->isEnable()) {
        return;
    }
    mpGUIAreaInfo = nullptr;
}

s32 uGUIClanStatus::getSMenuCursorX() {
    return 0;
}

s32 uGUIClanStatus::getSMenuCursorY() {
    if (mScrollListMember.mpVCtrl != nullptr) {
        return mScrollListMember.mpVCtrl->getCurrentPos();
    } else {
        return 0;
    }
}

s32 uGUIClanStatus::getSMenuTab() {
    static const s32 tab_selects[3] = {
        0,
        1,
        2,
    };
    const s32 tab_id = mControlMgr.getCurrentPos(0u);
    if (static_cast<unsigned int>(tab_id) <= 2) {
        return tab_selects[tab_id];
    } else {
        return 0;
    }
}

u32 uGUIClanStatus::getMemberListCursorPos() {
    return static_cast<u32>(mControlMgr.getCurrentPos(4u));
}

void uGUIClanStatus::resetMemberListSize(u32 listSize, u32 cursorPos) {
    mControlMgr.resetItemNum(4u, mScrollListMember.length(), cursorPos);
}

void uGUIClanStatus::initMembers() {
    if (sMenu::getInstance()->mClanInfoManager.isMove()) {
        if (sMenu::getInstance()->mClanInfoManager.mpClanParam != nullptr) {
            mIsMyClan = (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyClanParam.m_ClanServerParam.m_unID != 0) && (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyClanParam.m_ClanServerParam.m_unID == sMenu::getInstance()->mClanInfoManager.mpClanParam->m_ClanServerParam.m_unID);
            if ((static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyClanParam.m_ClanServerParam.m_unID != 0) && (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyClanParam.m_ClanServerParam.m_unID == sMenu::getInstance()->mClanInfoManager.mpClanParam->m_ClanServerParam.m_unID)) {
                mIsMaster = static_cast<sNetworkExt*>(sNetwork::getInstance())->isClanLeader();
            } else {
                mIsMaster = false;
            }
        } else {
            mIsMyClan = false;
            mIsMaster = false;
        }
    } else {
        mIsMyClan = true;
        mIsMaster = static_cast<sNetworkExt*>(sNetwork::getInstance())->isClanLeader();
    }
}

void uGUIClanStatus::setupInstances() {
    cGUIInstance* t0 = getInstance(46u, false);
    if ((mpINST_scr_bar = static_cast<cGUIInstAnimation*>(t0)) != nullptr) {
        t0->setVisible(false);
    }
    mpINST_Null_list00 = static_cast<cGUIInstNull*>(getInstance(33u, false));
    mpINST_msg_text = static_cast<cGUIInstAnimation*>(getInstance(245u, false));
    mStatus.mpINST_fix_leader = static_cast<cGUIInstAnimation*>(getInstance(34u, false));
}

void uGUIClanStatus::setupObjects() {
    this->uGUIClanStatusBase::setupObjects();
    setObjectMessageFromId(10u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 19u), 0u, false);
    setObjectMessageFromId(10u, 4u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 18u), 0u, false);
    setObjectMessageFromId(8u, 35u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 21u), 0u, false);
    setObjectMessageFromId(8u, 39u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 119u), 0u, false);
    setObjectMessageFromId(8u, 38u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 19u), 0u, false);
    setObjectMessageFromId(16u, 14u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 1u), 0u, false);
    setObjectMessageFromId(16u, 15u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 17u), 0u, false);
    setObjectMessageFromId(16u, 52u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 25u), 0u, false);
    setObjectMessageFromId(16u, 54u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 19u), 0u, false);
    setObjectMessageFromId(17u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 12u), 0u, false);
    setObjectMessageFromId(17u, 10u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 2u), 0u, false);
    setObjectMessageFromId(17u, 16u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 3u), 0u, false);
    setObjectMessageFromId(121u, 2u, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 10u), 0u, false);
    mStatus.mpOBJ_msg_clanname_m_clanname = static_cast<cGUIObjMessage*>(getObjectFromId(8u, 10u));
    mStatus.mpOBJ_msg_clanname_m_abbreviate = static_cast<cGUIObjMessage*>(getObjectFromId(8u, 12u));
    mStatus.mpOBJ_msg_clanname_m_master = static_cast<cGUIObjMessage*>(getObjectFromId(8u, 14u));
    mStatus.mpOBJ_msg_clanname_m_clanlvnum = static_cast<cGUIObjMessage*>(getObjectFromId(8u, 36u));
    mStatus.mpOBJ_msg_clanname_m_clanpoint = static_cast<cGUIObjMessage*>(getObjectFromId(8u, 37u));
    mStatus.mpOBJ_msg_status00_m_member = static_cast<cGUIObjMessage*>(getObjectFromId(16u, 16u));
    mStatus.mpOBJ_msg_status00_m_date = static_cast<cGUIObjMessage*>(getObjectFromId(16u, 17u));
    mStatus.mpOBJ_msg_status00_m_cpnum = static_cast<cGUIObjMessage*>(getObjectFromId(16u, 53u));
    mStatus.mpOBJ_msg_status00_m_title = static_cast<cGUIObjMessage*>(getObjectFromId(16u, 18u));
    cGUIObject* t0 = getObjectFromId(121u, 3u);
    if ((mStatus.mpOBJ_msg_status02_m_text00 = static_cast<cGUIObjMessage*>(t0)) != nullptr) {
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 296)) & 247;
        cGUIObject* t1 = getObjectFromId(121u, 13u);
        if ((mStatus.mpOBJ_msg_status02_m_text01 = static_cast<cGUIObjMessage*>(t1)) != nullptr) {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296)) & 247;
        }
        MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 11u);
        cGUIObject* t3 = getObjectFromId(121u, 11u);
        mStatus.mpOBJ_msg_status02_m_section01 = static_cast<cGUIObjMessage*>(t3);
        setObjectMessage(t3, t2, 0u, false);
        mpOBJ_msg_list_m_history = static_cast<cGUIObjMessage*>(getObjectFromId(311u, 17u));
    } else {
        cGUIObject* t1 = getObjectFromId(121u, 13u);
        if ((mStatus.mpOBJ_msg_status02_m_text01 = static_cast<cGUIObjMessage*>(t1)) != nullptr) {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296)) & 247;
        }
        MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 11u);
        cGUIObject* t3 = getObjectFromId(121u, 11u);
        mStatus.mpOBJ_msg_status02_m_section01 = static_cast<cGUIObjMessage*>(t3);
        setObjectMessage(t3, t2, 0u, false);
        mpOBJ_msg_list_m_history = static_cast<cGUIObjMessage*>(getObjectFromId(311u, 17u));
    }
}

__attribute__((weak)) void uGUIClanStatus::setupRefrenceUIs() {
    DDON_STUB("uGUIClanStatus::setupRefrenceUIs")
    /* stub */
}

__attribute__((weak)) void uGUIClanStatus::setupControls() {
    DDON_STUB("uGUIClanStatus::setupControls")
    /* stub */
}

__attribute__((weak)) void uGUIClanStatus::moveInput() {
    DDON_STUB("uGUIClanStatus::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIClanStatus::moveEvent() {
    DDON_STUB("uGUIClanStatus::moveEvent")
    /* stub */
}

u32 uGUIClanStatus::evCtrlChangeTab(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIClanStatus::evCtrlEditStatus(cControl::Message* msg) {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->isClanPermission(nClan::CLAN_PERMISSION_STATUS_CHANGE, static_cast<const CClanMemberInfo*>(nullptr))) {
        setInputEvent(68u);
    }
    return 0;
}

u32 uGUIClanStatus::evCtrlAreaInfo(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

void uGUIClanStatus::onUpdateInit() {
    const s32 tab_select = sMenu::getInstance()->mClanInfoManager.mMenuCursor[0];
    if (tab_select != 2) {
        if (tab_select == 1) {
            mControlMgr.setCurrentPos(0u, tab_select);
            s32 t0 = mControlMgr.getCurrentPos(0u);
            if (t0 == 2) {
                setFlowAndInit(8u, false);
                mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t0), true, true);
                setColumnNames(static_cast<COLUMN_TYPE>(t0));
            } else {
                if (t0 == 1) {
                    setFlowAndInit(5u, false);
                    mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t0), true, true);
                    setColumnNames(static_cast<COLUMN_TYPE>(t0));
                } else {
                    setFlowAndInit(3u, false);
                    mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t0), true, true);
                    setColumnNames(COLUMN_TYPE_NONE);
                }
            }
        } else {
            mControlMgr.setCurrentPos(0u, 0);
            s32 t0 = mControlMgr.getCurrentPos(0u);
            if (t0 == 2) {
                setFlowAndInit(8u, false);
                mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t0), true, true);
                setColumnNames(static_cast<COLUMN_TYPE>(t0));
            } else {
                if (t0 == 1) {
                    setFlowAndInit(5u, false);
                    mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t0), true, true);
                    setColumnNames(static_cast<COLUMN_TYPE>(t0));
                } else {
                    setFlowAndInit(3u, false);
                    mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t0), true, true);
                    setColumnNames(COLUMN_TYPE_NONE);
                }
            }
        }
    } else {
        mControlMgr.setCurrentPos(0u, tab_select);
        s32 t0 = mControlMgr.getCurrentPos(0u);
        if (t0 == 2) {
            setFlowAndInit(8u, false);
            mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t0), true, true);
            setColumnNames(static_cast<COLUMN_TYPE>(t0));
        } else {
            if (t0 == 1) {
                setFlowAndInit(5u, false);
                mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t0), true, true);
                setColumnNames(static_cast<COLUMN_TYPE>(t0));
            } else {
                setFlowAndInit(3u, false);
                mTab.uGUIBase::cReferenceUITab::setFocus(static_cast<u32>(t0), true, true);
                setColumnNames(COLUMN_TYPE_NONE);
            }
        }
    }
}

__attribute__((weak)) void uGUIClanStatus::onUpdateWait() {
    DDON_STUB("uGUIClanStatus::onUpdateWait")
    /* stub */
}

void uGUIClanStatus::updateEdit() {
    if (mRefrenceUIArray.mLength == 0) {
        mClanEmblem.updateArcLoader(getDeltaTime());
        return;
    }
    unsigned int i3 = 0;
    do {
        static_cast<cReferenceUIBase*>(mRefrenceUIArray.getBuffer()[static_cast<int>(i3)])->update();
        i3 += 1u;
    } while (i3 < mRefrenceUIArray.mLength);
    mClanEmblem.updateArcLoader(getDeltaTime());
}

void uGUIClanStatus::updateAreaInfo() {
    if (mRefrenceUIArray.mLength == 0) {
        mClanEmblem.updateArcLoader(getDeltaTime());
        return;
    }
    unsigned int i3 = 0;
    do {
        static_cast<cReferenceUIBase*>(mRefrenceUIArray.getBuffer()[static_cast<int>(i3)])->update();
        i3 += 1u;
    } while (i3 < mRefrenceUIArray.mLength);
    mClanEmblem.updateArcLoader(getDeltaTime());
}

__attribute__((weak)) void uGUIClanStatus::updateDispStatus() {
    DDON_STUB("uGUIClanStatus::updateDispStatus")
    /* stub */
}

void uGUIClanStatus::updateDispHistory() {
    f32 t0 = getDeltaTime();
    bool t1 = mHistoryList.mScrollList.uGUIBase::cScrollList::update(t0);
    u32 t3 = mHistoryList.mScrollList.mVisualInfoArray.mLength;
    if (t3 == 0) {
        bool t4 = mIsInitScrollListHistory;
        if (t4) {
            rGUIMessage* t5 = mpGUIMsgs.elems[0];
            cGUIObjMessage* t6 = mpOBJ_msg_text_m_text;
            sGUI* t7 = sGUI::getInstance();
            MT_CTSTR t8 = static_cast<sGUIExt*>(t7)->getMsgFromIdxInfo(t5, 28u);
            setObjectMessage(static_cast<cGUIObject*>(t6), t8, 0u, false);
            cGUIInstAnimation* t12 = mpINST_msg_text;
            if (t12 != nullptr) {
                t12->setVisible(t3 == 0);
                cGUIInstAnimation* t15 = mpINST_msg_text;
                if (t15 != nullptr) {
                    t15->setExecute(t3 == 0);
                }
            }
        } else {
            cGUIInstAnimation* t12 = mpINST_msg_text;
            if (t12 != nullptr) {
                t12->setVisible(t3 == 0);
                cGUIInstAnimation* t15 = mpINST_msg_text;
                if (t15 != nullptr) {
                    t15->setExecute(t3 == 0);
                }
            }
        }
    } else {
        cGUIInstAnimation* t12 = mpINST_msg_text;
        if (t12 != nullptr) {
            t12->setVisible(t3 == 0);
            cGUIInstAnimation* t15 = mpINST_msg_text;
            if (t15 != nullptr) {
                t15->setExecute(t3 == 0);
            }
        }
    }
}

__attribute__((weak)) void uGUIClanStatus::makeHistoryDetail(MtString& detail, u8 historyType, MT_CTSTR firstName, MT_CTSTR lastName, u32 param1, u32 param2, u32 param3, MT_CTSTR freeText) {
    DDON_STUB("uGUIClanStatus::makeHistoryDetail")
    /* stub */
}

__attribute__((weak)) void uGUIClanStatus::showHistoryListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    DDON_STUB("uGUIClanStatus::showHistoryListItem")
    /* stub */
}

__attribute__((weak)) void uGUIClanStatus::hideHistoryListItem(uGUIBase::cScrollListItemBase* pItemBase) {
    DDON_STUB("uGUIClanStatus::hideHistoryListItem")
    /* stub */
}

__attribute__((weak)) MtObject* uGUIClanStatus::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanStatus::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIClanStatus::cHistoryItem::getDTI() const {
    return uGUIClanStatus::cHistoryItem::DTI;
}

__attribute__((weak)) void uGUIClanStatus::cHistoryItem::show(uGUIClanStatus::cHistoryInfo& info) {
    DDON_STUB("uGUIClanStatus::cHistoryItem::show")
    /* stub */
}

inline uGUIClanStatus::cHistoryItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanStatus::cHistoryItem::MyDTI uGUIClanStatus::cHistoryItem::DTI("uGUIClanStatus::cHistoryItem", &::uGUIBase::cScrollListItemBase::DTI, 112ul, 0u, 0u);

MtObject* uGUIClanStatus::cHistoryItem::MyDTI::newInstance() const {
    return new (16u) uGUIClanStatus::cHistoryItem;
}

const MtDTI& uGUIClanStatus::cHistoryInfo::getDTI() const {
    return uGUIClanStatus::cHistoryInfo::DTI;
}

uGUIClanStatus::cHistoryInfo::~cHistoryInfo() {
}

inline uGUIClanStatus::cHistoryInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanStatus::cHistoryInfo::MyDTI uGUIClanStatus::cHistoryInfo::DTI("uGUIClanStatus::cHistoryInfo", &::uGUIBase::cScrollListInfoBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanStatus::cHistoryInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanStatus::cHistoryInfo::MyDTI::newInstance")
    return nullptr;
}

uGUIClanStatus::cHistoryList::~cHistoryList() {
}

__attribute__((weak)) void uGUIClanStatus::cHistoryList::setup(uGUIClanStatus& owner, uGUIClanStatus::HistoryItems& items) {
    DDON_STUB("uGUIClanStatus::cHistoryList::setup")
    /* stub */
}

const MtDTI& uGUIClanStatusBase::getDTI() const {
    return uGUIClanStatusBase::DTI;
}

__attribute__((noinline)) uGUIClanStatusBase::~uGUIClanStatusBase() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIClanStatusBase::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CLAN_STATUS_GUI"), 129u, 1471352082l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_CLAN_STATUS_GMD", 0u);
}

void uGUIClanStatusBase::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(11u), true);
    setPlay(true);
    initMembers();
    initFlow();
    setupInstances();
    setupObjects();
    setupRefrenceUIs();
    setupControls();
    if (mpInstNullDesign != nullptr) {
        mpInstNullDesign->setVisible(false);
    }
    mIsSetup = true;
}

void uGUIClanStatusBase::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIClanStatusBase::move() {
    this->uGUIBase::move();
}

bool uGUIClanStatusBase::show() {
    if (mIsSetup) {
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIClanStatusBase::updateInit);
    }
    return mIsSetup;
}

__attribute__((weak)) void uGUIClanStatusBase::updateMemberList() {
    DDON_STUB("uGUIClanStatusBase::updateMemberList")
    /* stub */
}

u32 uGUIClanStatusBase::getMemberListCursorPos() {
    return 0;
}

__attribute__((weak)) void uGUIClanStatusBase::resetMemberListSize(u32 listSize, u32 cursorPos) {
}

__attribute__((weak)) void uGUIClanStatusBase::initMembers() {
}

void uGUIClanStatusBase::initFlow() {
    setFlowAndInit(10u, false);
}

void uGUIClanStatusBase::setupInstances() {
    cGUIInstance* t0 = getInstance(46u, false);
    if ((mpINST_scr_bar = static_cast<cGUIInstAnimation*>(t0)) != nullptr) {
        t0->setVisible(false);
    }
    mpINST_Null_list00 = static_cast<cGUIInstNull*>(getInstance(33u, false));
    mpINST_msg_text = static_cast<cGUIInstAnimation*>(getInstance(245u, false));
}

__attribute__((weak)) void uGUIClanStatusBase::setupObjects() {
    mpOBJ_msg_text_m_text = static_cast<cGUIObjMessage*>(getObjectFromId(245u, 2u));
    mpOBJ_mask_top = static_cast<cGUIObjPolygon*>(getObjectFromId(32u, 4u));
    mpOBJ_mask_center = static_cast<cGUIObjPolygon*>(getObjectFromId(32u, 2u));
    mpOBJ_mask_bottom = static_cast<cGUIObjPolygon*>(getObjectFromId(32u, 3u));
    mpOBJ_msg_select_m_sections.elems[0] = static_cast<cGUIObjMessage*>(getObjectFromId(29u, 4u));
    mpOBJ_msg_select_m_sections.elems[1] = static_cast<cGUIObjMessage*>(getObjectFromId(29u, 20u));
    mpOBJ_msg_select_m_sections.elems[2] = static_cast<cGUIObjMessage*>(getObjectFromId(29u, 23u));
    mpOBJ_msg_select_m_sections.elems[3] = static_cast<cGUIObjMessage*>(getObjectFromId(29u, 26u));
    mpOBJ_msg_select_m_sections.elems[4] = static_cast<cGUIObjMessage*>(getObjectFromId(29u, 46u));
    mpOBJ_msg_select_m_sections.elems[5] = static_cast<cGUIObjMessage*>(getObjectFromId(29u, 47u));
}

void uGUIClanStatusBase::setupRefrenceUIs() {
    mCloseButton.setup(static_cast<uGUIBase*>(this), getInstance(97u, false), static_cast<cReferenceUICloseBtn::CloseFunc>(&::uGUIClanStatusBase::evCtrlCancel));
    mButtonGuide.setup(static_cast<uGUIBase*>(this), getInstance(9u, false), 0.0f);
    setupScrollListMember();
}

void uGUIClanStatusBase::setupControls() {
    mControlMgr.setup(static_cast<uGUIBase*>(this));
    mControlMgr.mIsChildPosTransfar = false;
}

u32 uGUIClanStatusBase::evCtrlDecide(cControl::Message* msg) {
    setInputEvent(4u);
    return 0;
}

u32 uGUIClanStatusBase::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

u32 uGUIClanStatusBase::evCtrlDispChange(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

void uGUIClanStatusBase::updateInit() {
    onUpdateInit();
    if (mpInstNullDesign != nullptr) {
        mpInstNullDesign->setVisible(true);
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIClanStatusBase::updateWait);
}

void uGUIClanStatusBase::updateWait() {
    onUpdateWait();
}

__attribute__((weak)) void uGUIClanStatusBase::onUpdateInit() {
}

__attribute__((weak)) void uGUIClanStatusBase::onUpdateWait() {
}

__attribute__((weak)) void uGUIClanStatusBase::setColumnNames(uGUIClanStatusBase::COLUMN_TYPE columnType) {
    DDON_STUB("uGUIClanStatusBase::setColumnNames")
    /* stub */
}

__attribute__((weak)) void uGUIClanStatusBase::setupScrollListMember() {
    DDON_STUB("uGUIClanStatusBase::setupScrollListMember")
    /* stub */
}

__attribute__((weak)) void uGUIClanStatusBase::initScrollListMember() {
    DDON_STUB("uGUIClanStatusBase::initScrollListMember")
    /* stub */
}

__attribute__((weak)) void uGUIClanStatusBase::showListItemMember(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index) {
    DDON_STUB("uGUIClanStatusBase::showListItemMember")
    /* stub */
}

__attribute__((weak)) void uGUIClanStatusBase::hideListItemMember(uGUIBase::cScrollListItemBase* pItemBase) {
    DDON_STUB("uGUIClanStatusBase::hideListItemMember")
    /* stub */
}

void uGUIClanStatusBase::updateDispMember() {
    f32 t0 = getDeltaTime();
    bool t1 = mScrollListMember.uGUIBase::cScrollList::update(t0);
    u32 t3 = mScrollListMember.length();
    if (t3 == 0) {
        bool t4 = mIsInitScrollListMember;
        if (t4) {
            rGUIMessage* t5 = mpGUIMsgs.elems[0];
            cGUIObjMessage* t6 = mpOBJ_msg_text_m_text;
            sGUI* t7 = sGUI::getInstance();
            MT_CTSTR t8 = static_cast<sGUIExt*>(t7)->getMsgFromIdxInfo(t5, 24u);
            if (t6 != nullptr) {
                if (t8 != nullptr) {
                    size_t t10 = strlen(t8);
                    t6->setMessage(t8, static_cast<unsigned int>(t10));
                    cGUIInstAnimation* t16 = mpINST_msg_text;
                    if (t16 != nullptr) {
                        t16->setVisible(t3 == 0);
                        cGUIInstAnimation* t19 = mpINST_msg_text;
                        if (t19 != nullptr) {
                            t19->setExecute(t3 == 0);
                        }
                    }
                } else {
                    t6->clearMessage();
                    cGUIInstAnimation* t16 = mpINST_msg_text;
                    if (t16 != nullptr) {
                        t16->setVisible(t3 == 0);
                        cGUIInstAnimation* t19 = mpINST_msg_text;
                        if (t19 != nullptr) {
                            t19->setExecute(t3 == 0);
                        }
                    }
                }
            } else {
                cGUIInstAnimation* t16 = mpINST_msg_text;
                if (t16 != nullptr) {
                    t16->setVisible(t3 == 0);
                    cGUIInstAnimation* t19 = mpINST_msg_text;
                    if (t19 != nullptr) {
                        t19->setExecute(t3 == 0);
                    }
                }
            }
        } else {
            cGUIInstAnimation* t16 = mpINST_msg_text;
            if (t16 != nullptr) {
                t16->setVisible(t3 == 0);
                cGUIInstAnimation* t19 = mpINST_msg_text;
                if (t19 != nullptr) {
                    t19->setExecute(t3 == 0);
                }
            }
        }
    } else {
        cGUIInstAnimation* t16 = mpINST_msg_text;
        if (t16 != nullptr) {
            t16->setVisible(t3 == 0);
            cGUIInstAnimation* t19 = mpINST_msg_text;
            if (t19 != nullptr) {
                t19->setExecute(t3 == 0);
            }
        }
    }
}

inline uGUIClanStatusBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanStatusBase::MyDTI uGUIClanStatusBase::DTI("uGUIClanStatusBase", &::uGUIBase::DTI, 11520ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanStatusBase::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanStatusBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIClanStatusBase::cScrollListItemMember::getDTI() const {
    return uGUIClanStatusBase::cScrollListItemMember::DTI;
}

__attribute__((weak)) void uGUIClanStatusBase::cScrollListItemMember::setup(uGUIClanStatusBase* owner, cGUIInstNull* instNull) {
    DDON_STUB("uGUIClanStatusBase::cScrollListItemMember::setup")
    /* stub */
}

inline uGUIClanStatusBase::cScrollListItemMember::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanStatusBase::cScrollListItemMember::MyDTI uGUIClanStatusBase::cScrollListItemMember::DTI("uGUIClanStatusBase::cScrollListItemMember", &::uGUIBase::cScrollListItemBase::DTI, 352ul, 0u, 0u);

MtObject* uGUIClanStatusBase::cScrollListItemMember::MyDTI::newInstance() const {
    return new (16u) uGUIClanStatusBase::cScrollListItemMember;
}

const MtDTI& uGUIClanStatusBase::cScrollListInfoMember::getDTI() const {
    return uGUIClanStatusBase::cScrollListInfoMember::DTI;
}

inline uGUIClanStatusBase::cScrollListInfoMember::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanStatusBase::cScrollListInfoMember::MyDTI uGUIClanStatusBase::cScrollListInfoMember::DTI("uGUIClanStatusBase::cScrollListInfoMember", &::uGUIBase::cScrollListInfoBase::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIClanStatusBase::cScrollListInfoMember::MyDTI::newInstance() const {
    DDON_STUB("uGUIClanStatusBase::cScrollListInfoMember::MyDTI::newInstance")
    return nullptr;
}

