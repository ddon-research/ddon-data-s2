// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPartyList.h"
#include "Protocol/PacketData/Community.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Party.h"
#include "cCharacterData.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIPageList.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cMenuSupport.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "../../XFramework/cResource.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "nNet.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sMain.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIPartyList::getDTI() const {
    return uGUIPartyList::DTI;
}

bool uGUIPartyList::Show(uGUIBase* base) {
    if (base != nullptr) {
        if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(base) + 32265)) != 0) {
            base->mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPartyList::updateInit);
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

__attribute__((weak)) bool uGUIPartyList::IsShortCutWait(uGUIBase* base) {
    DDON_STUB("uGUIPartyList::IsShortCutWait")
    return {};
}

void uGUIPartyList::SetSearchSettingParty(uGUIBase* base, cCharacterData::stSearchFilterSetting& settingParty) {
    if (base == nullptr) {
        return;
    }
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(base) + 36632) = settingParty.mPlayPurpose1;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(base) + 36636) = settingParty.mPlayStyle;
}

__attribute__((weak)) void uGUIPartyList::SetSearchSettingPlayer(uGUIBase* base, cCharacterData::stSearchFilterSetting& settingPlayer) {
    DDON_STUB("uGUIPartyList::SetSearchSettingPlayer")
    /* stub */
}

__attribute__((noinline)) uGUIPartyList::~uGUIPartyList() {
    DDON_STUB("uGUIPartyList::~uGUIPartyList")
    /* stub */
}

bool uGUIPartyList::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_PARTYLIST_GUI"), 129u, 1450068697l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_PARTYLIST_RES_GMD", 0u);
}

__attribute__((weak)) void uGUIPartyList::setup() {
    DDON_STUB("uGUIPartyList::setup")
    /* stub */
}

void uGUIPartyList::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIPartyList::updatePtr() {
}

s32 uGUIPartyList::getSMenuCursorX() {
    if (mMode == MODE_PLAYER_SEARCH_LIST) {
        return mControls.getCurrentPos(10u);
    } else {
        if (mMode == MODE_PARTY_SEARCH_LIST) {
            return mControls.getCurrentPos(6u);
        } else {
            return 0;
        }
    }
}

s32 uGUIPartyList::getSMenuCursorY() {
    static const s32 party_list_menu_ids[2] = {
        14,
        15,
    };
    switch (static_cast<unsigned int>(mMode - 1)) {
        case 0:
        {
            s32 t0 = mControls.getCurrentPos(0u);
            if (t0 == 1) {
                return (sMenu::getInstance()->mPartyMemberList.mReqMemberNum + sMenu::getInstance()->mPartyMemberList.mPartyMemberNum) + sMenu::getInstance()->mPartyMemberList.mInviteMemberNum;
            } else {
                if (t0 == 0) {
                    return mControls.getCurrentPos(1u);
                } else {
                    return 0;
                }
            }
            break;
        }
        case 1:
        {
            s32 t0 = mControls.getCurrentPos(0u);
            if (t0 == 1) {
                return (sMenu::getInstance()->mPartyMemberList.mReqMemberNum + sMenu::getInstance()->mPartyMemberList.mPartyMemberNum) + sMenu::getInstance()->mPartyMemberList.mInviteMemberNum;
            } else {
                if (t0 == 0) {
                    return mControls.getCurrentPos(1u);
                } else {
                    return 0;
                }
            }
            break;
        }
        case 2:
        {
            s32 t0 = mControls.getCurrentPos(0u);
            if (t0 == 1) {
                return (sMenu::getInstance()->mPartyMemberList.mReqMemberNum + sMenu::getInstance()->mPartyMemberList.mPartyMemberNum) + sMenu::getInstance()->mPartyMemberList.mInviteMemberNum;
            } else {
                if (t0 == 0) {
                    return mControls.getCurrentPos(1u);
                } else {
                    return 0;
                }
            }
            break;
        }
        case 5:
        {
            return mControls.getCurrentPos(2u);
        }
        case 8:
        {
            return mControls.getCurrentPos(3u);
        }
        case 10:
        {
            s32 t1 = mControls.getCurrentPos(4u);
            if (t1 == 1) {
                const u32 button_id = mControls.getCurrentPos(7u);
                if (button_id <= 1u) {
                    const s32 party_list_menu_id = party_list_menu_ids[button_id];
                    return (sMenu::mpInstance)->mPartyList.cMenuBase::getConvertCursorIdx(party_list_menu_id);
                } else {
                    return 0;
                }
            } else {
                if (t1 == 0) {
                    return mControls.getCurrentPos(5u);
                } else {
                    return 0;
                }
            }
            break;
        }
        case 11:
        {
            s32 t1 = mControls.getCurrentPos(4u);
            if (t1 == 1) {
                const u32 button_id = mControls.getCurrentPos(7u);
                if (button_id <= 1u) {
                    const s32 party_list_menu_id = party_list_menu_ids[button_id];
                    return (sMenu::mpInstance)->mPartyList.cMenuBase::getConvertCursorIdx(party_list_menu_id);
                } else {
                    return 0;
                }
            } else {
                if (t1 == 0) {
                    return mControls.getCurrentPos(5u);
                } else {
                    return 0;
                }
            }
            break;
        }
        case 14:
        {
            s32 t2 = mControls.getCurrentPos(8u);
            if (t2 == 1) {
                return (sMenu::mpInstance)->mCharacterList.cMenuBase::getConvertCursorIdx(14);
            } else {
                if (t2 == 0) {
                    return mControls.getCurrentPos(9u);
                } else {
                    return 0;
                }
            }
            break;
        }
        case 15:
        {
            s32 t2 = mControls.getCurrentPos(8u);
            if (t2 == 1) {
                return (sMenu::mpInstance)->mCharacterList.cMenuBase::getConvertCursorIdx(14);
            } else {
                if (t2 == 0) {
                    return mControls.getCurrentPos(9u);
                } else {
                    return 0;
                }
            }
            break;
        }
        default:
        {
            return 0;
        }
    }
}

__attribute__((weak)) s32 uGUIPartyList::getSMenuTab() {
    DDON_STUB("uGUIPartyList::getSMenuTab")
    return {};
}

void uGUIPartyList::updateInit() {
    mShortCutWaitFrame = 3;
    updateControlItemNum(false);
    initMode();
    if (mData.mpINST_Null_all != nullptr) {
        mData.mpINST_Null_all->setVisible(true);
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPartyList::updateWait);
}

__attribute__((weak)) void uGUIPartyList::updateWait() {
    DDON_STUB("uGUIPartyList::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::moveInput() {
    DDON_STUB("uGUIPartyList::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::moveEvent() {
    DDON_STUB("uGUIPartyList::moveEvent")
    /* stub */
}

u32 uGUIPartyList::evCtrlTabMove(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

__attribute__((weak)) void uGUIPartyList::evTabMove() {
    DDON_STUB("uGUIPartyList::evTabMove")
    /* stub */
}

u32 uGUIPartyList::evCtrlDecide(cControl::Message* msg) {
    setInputEvent(4u);
    return 0;
}

u32 uGUIPartyList::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

u32 uGUIPartyList::evCtrlDispChange(cControl::Message* msg) {
    setInputEvent(68u);
    return 0;
}

u32 uGUIPartyList::evCtrlButtonMove(cControl::Message* msg) {
    return 0;
}

u32 uGUIPartyList::evCtrlButtonClick(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->reason == nGUIExt::MOUSE_LCLICK) {
            if (msg->click_vol > -1) {
                mControls.setCurrentPos(4u, msg->click_vol);
            }
        }
    }
    setInputEvent(4u);
    return 0;
}

__attribute__((weak)) void uGUIPartyList::setupPlayerInfo(uGUIPartyList::cPlayerInfo& playerInfo, cGUIInstNull* instNull, u32 ID_INST_msg_list, u32 ID_INST_fix_job, u32 ID_INST_fix_icon_online, u32 ID_INST_comment, u32 ID_INST_favorite) {
    DDON_STUB("uGUIPartyList::setupPlayerInfo")
    /* stub */
}

void uGUIPartyList::setTitleText(uGUIPartyList::MODE mode, u32 dispMode) {
    if (static_cast<unsigned int>(mode) <= 16) {
        if (((0x1300Eul >> (static_cast<unsigned long>(mode) & 31)) & 1ul) != 0) {
            if (dispMode == 1) {
                MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 20u);
                if (mTitles.elems[2].mpUnit != nullptr) {
                    mTitles.elems[2].mpUnit->setObjectMessage(static_cast<cGUIObject*>(mTitles.elems[2].mpMsg), t0, 0u, false);
                }
                if (mTitles.elems[3].mpUnit != nullptr) {
                    mTitles.elems[3].mpUnit->setObjectMessage(static_cast<cGUIObject*>(mTitles.elems[3].mpMsg), "", 0u, false);
                }
            } else {
                MT_CTSTR t1 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 16u);
                if (mTitles.elems[2].mpUnit != nullptr) {
                    mTitles.elems[2].mpUnit->setObjectMessage(static_cast<cGUIObject*>(mTitles.elems[2].mpMsg), t1, 0u, false);
                    MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 18u);
                    if (mTitles.elems[3].mpUnit != nullptr) {
                        mTitles.elems[3].mpUnit->setObjectMessage(static_cast<cGUIObject*>(mTitles.elems[3].mpMsg), t2, 0u, false);
                    }
                } else {
                    MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGUIMsgs.elems[0], 18u);
                    if (mTitles.elems[3].mpUnit != nullptr) {
                        mTitles.elems[3].mpUnit->setObjectMessage(static_cast<cGUIObject*>(mTitles.elems[3].mpMsg), t2, 0u, false);
                    }
                }
            }
        }
    }
}

__attribute__((weak)) uGUIPartyList::MODE uGUIPartyList::getModeFromTabId(s32 tabId) const {
    DDON_STUB("uGUIPartyList::getModeFromTabId")
    return {};
}

__attribute__((weak)) u32 uGUIPartyList::updateControlItemNum(bool isUpdateMode) {
    DDON_STUB("uGUIPartyList::updateControlItemNum")
    return {};
}

__attribute__((weak)) void uGUIPartyList::initMode() {
    DDON_STUB("uGUIPartyList::initMode")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::updatePartySearchConditionMessage(bool isClear) {
    DDON_STUB("uGUIPartyList::updatePartySearchConditionMessage")
    /* stub */
}

inline uGUIPartyList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPartyList::MyDTI uGUIPartyList::DTI("uGUIPartyList", &::uGUIBase::DTI, 37024ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPartyList::MyDTI::newInstance() const {
    DDON_STUB("uGUIPartyList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIPartyList::cTitle::getDTI() const {
    return uGUIPartyList::cTitle::DTI;
}

inline uGUIPartyList::cTitle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPartyList::cTitle::MyDTI uGUIPartyList::cTitle::DTI("uGUIPartyList::cTitle", &::uGUIBase::cSupportBase::DTI, 40ul, 0u, 0u);

MtObject* uGUIPartyList::cTitle::MyDTI::newInstance() const {
    return new (16u) uGUIPartyList::cTitle;
}

uGUIPartyList::cPlayerInfo::cPlayerInfo() {
    DDON_STUB("uGUIPartyList::cPlayerInfo::cPlayerInfo")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::cPlayerInfo::setPawn(const cPawnListParam& pawnListParam, uGUIBase* pGUI) {
    DDON_STUB("uGUIPartyList::cPlayerInfo::setPawn")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::cPlayerInfo::setPlayer(cPartyMemberInfo* partyMemberInfo, s32 dispMode, MT_CTSTR joiningText) {
    DDON_STUB("uGUIPartyList::cPlayerInfo::setPlayer")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::cPlayerInfo::setPlayer(const cContextInstHm* context, s32 dispMode) {
    DDON_STUB("uGUIPartyList::cPlayerInfo::setPlayer")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::cPlayerInfo::setPlayer(uGUIPartyList* owner, const CDataClientPartyListInfo& partyListInfo, s32 dispMode, MT_CTSTR invitingText) {
    DDON_STUB("uGUIPartyList::cPlayerInfo::setPlayer")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::cPlayerInfo::setPlayer(uGUIPartyList* owner, u32 characterId, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanName, u32 jobId, u32 jobLv, MT_CTSTR comment, u32 onlineStatus, u32 serverId, u32 lobbyId, u32 partyMemberNum, s32 dispMode, MT_CTSTR invitingText) {
    DDON_STUB("uGUIPartyList::cPlayerInfo::setPlayer")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::cPlayerInfo::setEmpty() {
    DDON_STUB("uGUIPartyList::cPlayerInfo::setEmpty")
    /* stub */
}

const MtDTI& uGUIPartyList::cGUIPageListPartyMember::getDTI() const {
    return uGUIPartyList::cGUIPageListPartyMember::DTI;
}

s32 uGUIPartyList::cGUIPageListPartyMember::getItemNum() const {
    return (sMenu::getInstance()->mPartyMemberList.mReqMemberNum + sMenu::getInstance()->mPartyMemberList.mPartyMemberNum) + sMenu::getInstance()->mPartyMemberList.mInviteMemberNum;
}

__attribute__((weak)) f32 uGUIPartyList::cGUIPageListPartyMember::getCursorPosY(s32 dispItemIndex) const {
    DDON_STUB("uGUIPartyList::cGUIPageListPartyMember::getCursorPosY")
    return {};
}

__attribute__((weak)) void uGUIPartyList::cGUIPageListPartyMember::getMouseCollision(cGUIInstance* & instance, cGUIObject* & object, s32 dispItemIndex) const {
    DDON_STUB("uGUIPartyList::cGUIPageListPartyMember::getMouseCollision")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::cGUIPageListPartyMember::callbackShowItem(s32 dispItemIndex, s32 itemIndex) {
    DDON_STUB("uGUIPartyList::cGUIPageListPartyMember::callbackShowItem")
    /* stub */
}

inline uGUIPartyList::cGUIPageListPartyMember::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPartyList::cGUIPageListPartyMember::MyDTI uGUIPartyList::cGUIPageListPartyMember::DTI("uGUIPartyList::cGUIPageListPartyMember", &::uGUIPartyList::cGUIPageListCommon::DTI, 72ul, 0u, 0u);

MtObject* uGUIPartyList::cGUIPageListPartyMember::MyDTI::newInstance() const {
    return new (16u) uGUIPartyList::cGUIPageListPartyMember;
}

s32 uGUIPartyList::cGUIPageListCommon::getPageItemNum() const {
    return 14;
}

__attribute__((weak)) void uGUIPartyList::cGUIPageListCommon::getMouseCollision(cGUIInstance* & instance, cGUIObject* & object, s32 dispItemIndex) const {
    DDON_STUB("uGUIPartyList::cGUIPageListCommon::getMouseCollision")
    /* stub */
}

__attribute__((weak)) void uGUIPartyList::cGUIPageListCommon::callbackHideItem(s32 dispItemIndex) {
    DDON_STUB("uGUIPartyList::cGUIPageListCommon::callbackHideItem")
    /* stub */
}

inline uGUIPartyList::cGUIPageListCommon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPartyList::cGUIPageListCommon::MyDTI uGUIPartyList::cGUIPageListCommon::DTI("uGUIPartyList::cGUIPageListCommon", &::cGUIPageList::DTI, 72ul, 0u, 1u);

MtObject* uGUIPartyList::cGUIPageListCommon::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGUIPartyList::cGUIPageListMainPawn::getDTI() const {
    return uGUIPartyList::cGUIPageListMainPawn::DTI;
}

s32 uGUIPartyList::cGUIPageListMainPawn::getItemNum() const {
    return static_cast<s32>(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyPawnList.mLength);
}

__attribute__((weak)) void uGUIPartyList::cGUIPageListMainPawn::callbackShowItem(s32 dispItemIndex, s32 itemIndex) {
    DDON_STUB("uGUIPartyList::cGUIPageListMainPawn::callbackShowItem")
    /* stub */
}

inline uGUIPartyList::cGUIPageListMainPawn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPartyList::cGUIPageListMainPawn::MyDTI uGUIPartyList::cGUIPageListMainPawn::DTI("uGUIPartyList::cGUIPageListMainPawn", &::uGUIPartyList::cGUIPageListCommon::DTI, 72ul, 0u, 0u);

MtObject* uGUIPartyList::cGUIPageListMainPawn::MyDTI::newInstance() const {
    return new (16u) uGUIPartyList::cGUIPageListMainPawn;
}

const MtDTI& uGUIPartyList::cGUIPageListSupportPawn::getDTI() const {
    return uGUIPartyList::cGUIPageListSupportPawn::DTI;
}

s32 uGUIPartyList::cGUIPageListSupportPawn::getItemNum() const {
    return static_cast<s32>(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mRentedPawnList.mLength);
}

__attribute__((weak)) void uGUIPartyList::cGUIPageListSupportPawn::callbackShowItem(s32 dispItemIndex, s32 itemIndex) {
    DDON_STUB("uGUIPartyList::cGUIPageListSupportPawn::callbackShowItem")
    /* stub */
}

inline uGUIPartyList::cGUIPageListSupportPawn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPartyList::cGUIPageListSupportPawn::MyDTI uGUIPartyList::cGUIPageListSupportPawn::DTI("uGUIPartyList::cGUIPageListSupportPawn", &::uGUIPartyList::cGUIPageListCommon::DTI, 72ul, 0u, 0u);

MtObject* uGUIPartyList::cGUIPageListSupportPawn::MyDTI::newInstance() const {
    return new (16u) uGUIPartyList::cGUIPageListSupportPawn;
}

const MtDTI& uGUIPartyList::cGUIPageListPartySearch::getDTI() const {
    return uGUIPartyList::cGUIPageListPartySearch::DTI;
}

s32 uGUIPartyList::cGUIPageListPartySearch::getItemNum() const {
    return uGUIPartyList::GetPartyListSortCount();
}

__attribute__((weak)) void uGUIPartyList::cGUIPageListPartySearch::callbackShowItem(s32 dispItemIndex, s32 itemIndex) {
    DDON_STUB("uGUIPartyList::cGUIPageListPartySearch::callbackShowItem")
    /* stub */
}

inline uGUIPartyList::cGUIPageListPartySearch::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPartyList::cGUIPageListPartySearch::MyDTI uGUIPartyList::cGUIPageListPartySearch::DTI("uGUIPartyList::cGUIPageListPartySearch", &::uGUIPartyList::cGUIPageListCommon::DTI, 72ul, 0u, 0u);

MtObject* uGUIPartyList::cGUIPageListPartySearch::MyDTI::newInstance() const {
    return new (16u) uGUIPartyList::cGUIPageListPartySearch;
}

const MtDTI& uGUIPartyList::cGUIPageListPlayerSearch::getDTI() const {
    return uGUIPartyList::cGUIPageListPlayerSearch::DTI;
}

s32 uGUIPartyList::cGUIPageListPlayerSearch::getItemNum() const {
    return uGUIPartyList::GetPlayerListSortCount();
}

__attribute__((weak)) void uGUIPartyList::cGUIPageListPlayerSearch::callbackShowItem(s32 dispItemIndex, s32 itemIndex) {
    DDON_STUB("uGUIPartyList::cGUIPageListPlayerSearch::callbackShowItem")
    /* stub */
}

inline uGUIPartyList::cGUIPageListPlayerSearch::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPartyList::cGUIPageListPlayerSearch::MyDTI uGUIPartyList::cGUIPageListPlayerSearch::DTI("uGUIPartyList::cGUIPageListPlayerSearch", &::uGUIPartyList::cGUIPageListCommon::DTI, 72ul, 0u, 0u);

MtObject* uGUIPartyList::cGUIPageListPlayerSearch::MyDTI::newInstance() const {
    return new (16u) uGUIPartyList::cGUIPageListPlayerSearch;
}

