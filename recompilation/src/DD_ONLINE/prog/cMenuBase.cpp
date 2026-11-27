// Reconstructed from the game's DWARF debug information.
#include <new>
#include <sce_atomic.h>
#include <stdio.h>
#include <string.h>
#include "cMenuBase.h"
#include "Protocol/PacketData/Clan.h"
#include "Protocol/PacketData/Common.h"
#include "Protocol/PacketData/Community.h"
#include "Protocol/PacketData/Craft.h"
#include "Protocol/PacketData/Enemy.h"
#include "Protocol/PacketData/Item.h"
#include "Protocol/PacketData/JobMaster.h"
#include "Protocol/PacketData/Mail.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Party.h"
#include "Protocol/PacketData/Pawn.h"
#include "Protocol/PacketData/QuickParty.h"
#include "Protocol/UserSession/S2C.h"
#include "Protocol/PacketData/Server.h"
#include "Protocol/PacketData/SupportPoint.h"
#include "aMenu.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cCharacterData.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cControl.h"
#include "cCraftRecipe.h"
#include "cCraftSkill.h"
#include "cCursor.h"
#include "cEndContentsManager.h"
#include "cEquipData.h"
#include "cGUIUtility.h"
#include "cItemParam.h"
#include "cKeyCustom.h"
#include "cMenuBaseClan.h"
#include "cMenuEntryBoard.h"
#include "cMenuSupport.h"
#include "cNetBase.h"
#include "cNetGameServer.h"
#include "cNetSessionManager.h"
#include "cPRTManager.h"
#include "cQuestManagerBase.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpTalk.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "nGUIKeyConfig.h"
#include "nHumanMsg.h"
#include "nJobParam.h"
#include "nMenu.h"
#include "nMenuKeyConfig.h"
#include "nNet.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "rCraftCapPass.h"
#include "rCraftRecipe.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "rKeyConfigTextTable.h"
#include "../../XFramework/rSoundRequest.h"
#include "sAIPawnSys.h"
#include "sAIPawnTalkMgr.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sBazaarManager.h"
#include "sChat.h"
#include "sContextManager.h"
#include "sCraftManager.h"
#include "sDialogBase.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sInputManager.h"
#include "sItemManager.h"
#include "sKeyboardInterface.h"
#include "../../XFramework/sMain.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sNpcManager.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sRender.h"
#include "sReward.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "sSoundManager.h"
#include "sTalkManager.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "uControl.h"
#include "uControlNpc.h"
#include "uDDOModel.h"
#include "uGUIAreaMaster.h"
#include "uGUIArisenCard.h"
#include "uGUIBase.h"
#include "uGUIBaseExt.h"
#include "uGUIBazaar.h"
#include "uGUIBoughtBox.h"
#include "uGUIBoxGachaInfo.h"
#include "uGUICharacterEditPopCard.h"
#include "uGUICommunityList.h"
#include "uGUICraft.h"
#include "uGUIDialogTextBox.h"
#include "uGUIFreeGroupChat.h"
#include "uGUIGPShop.h"
#include "uGUIGPShopDialog.h"
#include "uGUIKeyConfig.h"
#include "uGUIMail.h"
#include "uGUIMailDetail.h"
#include "uGUIMenuAreaInfo.h"
#include "uGUINewspaper.h"
#include "uGUIOption.h"
#include "uGUIPartyList.h"
#include "uGUIPawnReview.h"
#include "uGUIPopCmd01.h"
#include "uGUIPopFilter.h"
#include "uGUIPopPartyList.h"
#include "uGUIPopPartyMember.h"
#include "uGUIPopPawnList.h"
#include "uGUIPopPawnPoint.h"
#include "uGUIPopProfile.h"
#include "uGUIPopTopSel.h"
#include "uGUIRankUp.h"
#include "uGUIRetry.h"
#include "uGUIRimStone.h"
#include "uGUIServerSelect.h"
#include "uGUISystemMsg.h"
#include "uHuman.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

namespace nNet {
static const u32 RECOMMEND_ROLE_LIST_4[3] = {
    2,
    1,
    1,
};
}

static const u32 tblErrMsg[99] = {
    184,
    145,
    146,
    147,
    148,
    149,
    285,
    286,
    227,
    150,
    151,
    152,
    153,
    154,
    374,
    254,
    155,
    156,
    157,
    492,
    158,
    159,
    160,
    161,
    162,
    163,
    164,
    252,
    253,
    287,
    288,
    350,
    227,
    165,
    255,
    166,
    167,
    168,
    169,
    211,
    470,
    170,
    171,
    254,
    227,
    227,
    254,
    172,
    173,
    422,
    174,
    466,
    175,
    176,
    445,
    177,
    445,
    255,
    254,
    178,
    348,
    254,
    254,
    179,
    347,
    180,
    181,
    182,
    183,
    227,
    499,
    147,
    289,
    290,
    151,
    351,
    392,
    227,
    227,
    142,
    227,
    254,
    281,
    348,
    422,
    227,
    504,
    438,
    437,
    436,
    471,
    450,
    449,
    451,
    481,
    493,
    488,
    489,
    494,
};

const MtDTI& cMenuActiveList::getDTI() const {
    return cMenuActiveList::DTI;
}

__attribute__((weak)) void cMenuActiveList::initActiveList(uGUIBase* pRefGUI, s32 type, nCharacterData::stCharacterName* pDstName, u32* pCharacterId, CommunityCharacterBaseInfoVec* pExcludeList) {
    DDON_STUB("cMenuActiveList::initActiveList")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuActiveList::moveActiveList() {
    DDON_STUB("cMenuActiveList::moveActiveList")
    return {};
}

void cMenuActiveList::exitMenu() {
    cMenuActiveList::getAllocator()->memFree(static_cast<void*>(mpSortList));
    cMenuActiveList::getAllocator()->memFree(static_cast<void*>(mpSortCharId));
    cMenuActiveList::getAllocator()->memFree(static_cast<void*>(mpListType));
    cMenuActiveList::getAllocator()->memFree(static_cast<void*>(mpMenuList));
    cMenuActiveList::getAllocator()->memFree(static_cast<void*>(mpMenuParts));
    mpMenuParts = nullptr;
    mpMenuList = nullptr;
    mpListType = nullptr;
    mpSortCharId = nullptr;
    mpSortList = nullptr;
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) void cMenuActiveList::createSortList(bool clearOnly) {
    DDON_STUB("cMenuActiveList::createSortList")
    /* stub */
}

__attribute__((weak)) void cMenuActiveList::updateSortList() {
    DDON_STUB("cMenuActiveList::updateSortList")
    /* stub */
}

inline cMenuActiveList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuActiveList::MyDTI cMenuActiveList::DTI("cMenuActiveList", &::cMenuBase::DTI, 248ul, 0u, 0u);

MtObject* cMenuActiveList::MyDTI::newInstance() const {
    return new (16u) cMenuActiveList;
}

const MtDTI& cMenuApplyFriend::getDTI() const {
    return cMenuApplyFriend::DTI;
}

cMenuApplyFriend::~cMenuApplyFriend() {
}

__attribute__((weak)) void cMenuApplyFriend::initApplyFriend(u32 charId, MtString& friendFirstName, MtString& friendLastName) {
    DDON_STUB("cMenuApplyFriend::initApplyFriend")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuApplyFriend::moveApplyFriend() {
    DDON_STUB("cMenuApplyFriend::moveApplyFriend")
    return {};
}

__attribute__((weak)) void cMenuApplyFriend::exitMenu() {
    DDON_STUB("cMenuApplyFriend::exitMenu")
    /* stub */
}

inline cMenuApplyFriend::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuApplyFriend::MyDTI cMenuApplyFriend::DTI("cMenuApplyFriend", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuApplyFriend::MyDTI::newInstance() const {
    return new (16u) cMenuApplyFriend;
}

const MtDTI& cMenuApproveFriend::getDTI() const {
    return cMenuApproveFriend::DTI;
}

cMenuApproveFriend::~cMenuApproveFriend() {
}

__attribute__((weak)) void cMenuApproveFriend::initApproveFriend(u32 type, u32 reqId, MtString& charFirstName, MtString& charLastName) {
    DDON_STUB("cMenuApproveFriend::initApproveFriend")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuApproveFriend::moveApproveFriend() {
    DDON_STUB("cMenuApproveFriend::moveApproveFriend")
    return {};
}

__attribute__((weak)) void cMenuApproveFriend::exitMenu() {
    DDON_STUB("cMenuApproveFriend::exitMenu")
    /* stub */
}

inline cMenuApproveFriend::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuApproveFriend::MyDTI cMenuApproveFriend::DTI("cMenuApproveFriend", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuApproveFriend::MyDTI::newInstance() const {
    return new (16u) cMenuApproveFriend;
}

const MtDTI& cMenuAreaMaster::getDTI() const {
    return cMenuAreaMaster::DTI;
}

cMenuAreaMaster::cMenuAreaMaster() {
    mArcTicket = sArchiveManager::INVALID_TICKET;
    mSuppliesTalkMsgNo = -1;
}

cMenuAreaMaster::~cMenuAreaMaster() {
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mArcTicket == t0) {
        return;
    }
    sArchiveManager::getInstance()->returnTicket(mArcTicket);
    mArcTicket = t0;
}

void cMenuAreaMaster::initAreaMaster() {
    initMenu();
    mMenuRno[0] = 0;
    mMenuCursor[0] = 0;
    mSuppliesTalkMsgNo = -1;
    TICKET t0 = mArcTicket;
    if (t0 != (sArchiveManager::INVALID_TICKET)) {
        return;
    }
    TICKET t1 = sArchiveManager::getInstance()->IssueTicket();
    if (t0 == (mArcTicket = t1)) {
        return;
    }
    sArchiveManager* t2 = sArchiveManager::getInstance();
    t2->addTagEx(t1, rArchiveListArray::convTagId("uGUIAreaMaster"));
    sArchiveManager::getInstance()->attestationTicket(mArcTicket);
}

__attribute__((weak)) nMenu::MENU_RET cMenuAreaMaster::moveAreaMaster() {
    DDON_STUB("cMenuAreaMaster::moveAreaMaster")
    return {};
}

void cMenuAreaMaster::exitMenu() {
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mArcTicket != t0) {
        sArchiveManager::getInstance()->returnTicket(mArcTicket);
        mArcTicket = t0;
    }
    static_cast<sGUIExt*>(sGUI::getInstance())->deleteShopTitle();
    this->cMenuBase::exitMenu();
}

inline cMenuAreaMaster::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuAreaMaster::MyDTI cMenuAreaMaster::DTI("cMenuAreaMaster", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuAreaMaster::MyDTI::newInstance() const {
    return new (16u) cMenuAreaMaster;
}

const MtDTI& cMenuAreaMasterHistory::getDTI() const {
    return cMenuAreaMasterHistory::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuAreaMasterHistory::moveAreaMasterHistory() {
    DDON_STUB("cMenuAreaMasterHistory::moveAreaMasterHistory")
    return {};
}

inline cMenuAreaMasterHistory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuAreaMasterHistory::MyDTI cMenuAreaMasterHistory::DTI("cMenuAreaMasterHistory", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuAreaMasterHistory::MyDTI::newInstance() const {
    return new (16u) cMenuAreaMasterHistory;
}

const MtDTI& cMenuAreaMasterQuestInfo::getDTI() const {
    return cMenuAreaMasterQuestInfo::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuAreaMasterQuestInfo::moveAreaMasterQuestInfo() {
    DDON_STUB("cMenuAreaMasterQuestInfo::moveAreaMasterQuestInfo")
    return {};
}

inline cMenuAreaMasterQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuAreaMasterQuestInfo::MyDTI cMenuAreaMasterQuestInfo::DTI("cMenuAreaMasterQuestInfo", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuAreaMasterQuestInfo::MyDTI::newInstance() const {
    return new (16u) cMenuAreaMasterQuestInfo;
}

const MtDTI& cMenuAreaMasterRankUp::getDTI() const {
    return cMenuAreaMasterRankUp::DTI;
}

cMenuAreaMasterRankUp::cMenuAreaMasterRankUp() {
    mRank = 0;
    mRequestMessage = -1;
    mpGUIRankUp = nullptr;
}

cMenuAreaMasterRankUp::~cMenuAreaMasterRankUp() {
    if (mpGUIRankUp == nullptr) {
        return;
    }
    mpGUIRankUp->kill();
    mpGUIRankUp = nullptr;
}

__attribute__((weak)) nMenu::MENU_RET cMenuAreaMasterRankUp::moveAreaMasterRankUp() {
    DDON_STUB("cMenuAreaMasterRankUp::moveAreaMasterRankUp")
    return {};
}

__attribute__((weak)) void cMenuAreaMasterRankUp::updatePtr() {
    DDON_STUB("cMenuAreaMasterRankUp::updatePtr")
    /* stub */
}

void cMenuAreaMasterRankUp::exitMenu() {
    if (mpGUIRankUp != nullptr) {
        mpGUIRankUp->kill();
        mpGUIRankUp = nullptr;
    }
    this->cMenuBase::exitMenu();
}

inline cMenuAreaMasterRankUp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuAreaMasterRankUp::MyDTI cMenuAreaMasterRankUp::DTI("cMenuAreaMasterRankUp", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuAreaMasterRankUp::MyDTI::newInstance() const {
    return new (16u) cMenuAreaMasterRankUp;
}

const MtDTI& cMenuAreaMasterSpotInfo::getDTI() const {
    return cMenuAreaMasterSpotInfo::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuAreaMasterSpotInfo::moveAreaMasterSpotInfo() {
    DDON_STUB("cMenuAreaMasterSpotInfo::moveAreaMasterSpotInfo")
    return {};
}

inline cMenuAreaMasterSpotInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuAreaMasterSpotInfo::MyDTI cMenuAreaMasterSpotInfo::DTI("cMenuAreaMasterSpotInfo", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuAreaMasterSpotInfo::MyDTI::newInstance() const {
    return new (16u) cMenuAreaMasterSpotInfo;
}

const MtDTI& cMenuAreaMasterSupplies::getDTI() const {
    return cMenuAreaMasterSupplies::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuAreaMasterSupplies::moveAreaMasterSupplies() {
    DDON_STUB("cMenuAreaMasterSupplies::moveAreaMasterSupplies")
    return {};
}

inline cMenuAreaMasterSupplies::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuAreaMasterSupplies::MyDTI cMenuAreaMasterSupplies::DTI("cMenuAreaMasterSupplies", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuAreaMasterSupplies::MyDTI::newInstance() const {
    return new (16u) cMenuAreaMasterSupplies;
}

const MtDTI& cMenuBaggageMenu::getDTI() const {
    return cMenuBaggageMenu::DTI;
}

__attribute__((weak)) void cMenuBaggageMenu::initBaggageMenu() {
    initMenu();
    mMenuRno[BAGGAGE_RNO_BASE] = RNO_INIT;
    mpGUIGPShop = nullptr;
    mpGUIItemBaggage = nullptr;
    mLeftStorage = nItem::STORAGE_TYPE_BAGGAGE_FREE;
    mRightStorage = nItem::STORAGE_TYPE_BAG_USE;
    setupSupportMenu(BAGGAGE_MAX, false, true);
    const u32 menu_1_tbl[2] = { 5, 6 };
    for (u32 i = 0; i < 2; ++i) {
        addMenuList(menu_1_tbl[i]);
    }
    uGUIPopTopSel* const pGUI = new (16u) uGUIPopTopSel(false, 0);
    if (pGUI != nullptr) {
        *reinterpret_cast<u32*>(reinterpret_cast<char*>(pGUI) + 0xa94) = uGUIPopTopSel::MODE_BAGGAGE;
        static_cast<sGUIExt*>(sGUI::getInstance())->setSingletonMenu(pGUI);
        mpGUIMenu = pGUI;
        mUseGUIMenu = true;
        static_cast<sGUIExt*>(sGUI::getInstance())->createShopTitle(sGUIExt::SHOPTITLE_TYPE::DEPOSITBOX, sGUIExt::SHOPTITLE_TYPE::GOLD);
    }
}

__attribute__((weak)) nMenu::MENU_RET cMenuBaggageMenu::moveBaggageMenu() {
    DDON_STUB("cMenuBaggageMenu::moveBaggageMenu")
    return {};
}

void cMenuBaggageMenu::exitMenu() {
    if (mUseGUIMenu) {
        static_cast<sGUIExt*>(sGUI::getInstance())->deleteShopTitle();
    }
    this->cMenuBase::exitMenu();
}

inline cMenuBaggageMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuBaggageMenu::MyDTI cMenuBaggageMenu::DTI("cMenuBaggageMenu", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuBaggageMenu::MyDTI::newInstance() const {
    return new (16u) cMenuBaggageMenu;
}

const MtDTI& cMenuBase::getDTI() const {
    return cMenuBase::DTI;
}

cMenuBase::cMenuBase() {
    mNowMoveFlag = false;
    mIsUpdateButton = false;
    mIsUpdateCursor = false;
    mIsUpdateTab = false;
    mMenuCursor[6] = 0;
    mMenuCursor[4] = 0;
    mMenuCursor[5] = 0;
    mMenuCursor[2] = 0;
    mMenuCursor[3] = 0;
    mMenuCursor[0] = 0;
    mMenuCursor[1] = 0;
    mMenuRno[4] = 0;
    mMenuRno[5] = 0;
    mMenuRno[2] = 0;
    mMenuRno[3] = 0;
    mMenuRno[0] = 0;
    mMenuRno[1] = 0;
    mpMenuParts = nullptr;
    mpMenuList = nullptr;
    mUseGUIMenu = false;
    mpGUISystemMsg = nullptr;
    mpRefGUI = nullptr;
    mpGUIMenu = nullptr;
    mMenuSupportList.mAutoDelete = true;
}

__attribute__((noinline)) cMenuBase::~cMenuBase() {
    if (mMenuSupportList.mLength != 0) {
        u32 v0_0 = mMenuSupportList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMenuSupportList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMenuSupportList.mpArray[i0_3];
                v1_0 = mMenuSupportList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMenuSupportList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMenuSupportList.mpArray));
    }
    mMenuSupportList.mpArray = nullptr;
    mMenuSupportList.mBufsiz = 0;
    mMenuSupportList.mLength = 0;
    if (mpGUIMenu != nullptr) {
        mpGUIMenu->kill();
        mpGUIMenu = nullptr;
    }
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->kill();
        mpGUISystemMsg = nullptr;
    }
}

MtUI* cMenuBase::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cMenuBase::createProperty(MtPropertyList& s) {
}

void cMenuBase::updatePtr() {
    if (mpGUIMenu != nullptr) {
        if (!mpGUIMenu->isEnable()) {
            mpGUIMenu = nullptr;
        }
    }
    if (mpRefGUI != nullptr) {
        if (!mpRefGUI->isEnable()) {
            mpRefGUI = nullptr;
        }
    }
    if (mpGUISystemMsg != nullptr) {
        if (!mpGUISystemMsg->isEnable()) {
            mpGUISystemMsg = nullptr;
        }
    }
    if (mMenuSupportList.mLength == 0) {
        return;
    }
    u32 i = 0;
    do {
        static_cast<cMenuSupport*>(mMenuSupportList.getBuffer()[static_cast<int>(i)])->updatePtr();
        i += 1u;
    } while (i < mMenuSupportList.mLength);
}

bool cMenuBase::isMove() {
    return sMenu::getInstance()->checkMoveMenu(this, false);
}

bool cMenuBase::isUpdateCursor() {
    if (sMenu::getInstance()->checkMoveMenu(this, false) && !mBusyFlag) {
        return mIsUpdateCursor;
    }
    return false;
}

bool cMenuBase::isUpdateTab() {
    if (sMenu::getInstance()->checkMoveMenu(this, false) && !mBusyFlag) {
        return mIsUpdateTab;
    }
    return false;
}

bool cMenuBase::isUpdateButton() {
    if (sMenu::getInstance()->checkMoveMenu(this, false) && !mBusyFlag) {
        return mIsUpdateButton;
    }
    return false;
}

__attribute__((weak)) s32 cMenuBase::getConvertCursorIdx(s32 idx) {
    DDON_STUB("cMenuBase::getConvertCursorIdx")
    return {};
}

__attribute__((weak)) const nMenu::MENU_PARTS& cMenuBase::getMenuParts(s32 index) {
    DDON_STUB("cMenuBase::getMenuParts")
    __builtin_unreachable();
}

__attribute__((weak)) bool cMenuBase::isEnableMenu(s32 menuId) {
    DDON_STUB("cMenuBase::isEnableMenu")
    return {};
}

__attribute__((weak)) u32 cMenuBase::getNextBasePointerPrio() {
        if (mCustomBasePrio != 0xFFFFFFFF) {
            return mCustomBasePrio;
        }
        uGUIBase* pGUI = mpGUIMenu;
        if (pGUI == nullptr) {
            pGUI = mpRefGUI;
            if (pGUI == nullptr) {
                return 9;
            }
        }
        return pGUI->mBasePointerPrio - pGUI->mPointerPrioRange;
}

__attribute__((weak)) bool cMenuBase::isCancel(u32 cancelSe) {
    DDON_STUB("cMenuBase::isCancel")
    return {};
}

__attribute__((weak)) bool cMenuBase::isDecide() {
    DDON_STUB("cMenuBase::isDecide")
    return {};
}

__attribute__((weak)) bool cMenuBase::isDecideIndex(s32 partsIndex, u32 decideSe, u32 notSelectSe) {
    DDON_STUB("cMenuBase::isDecideIndex")
    return {};
}

__attribute__((weak)) bool cMenuBase::isTrgCheck(sPadExt::PAD_BTN_TYPE button, u32 useSe, u32 pad_id) {
    DDON_STUB("cMenuBase::isTrgCheck")
    return {};
}

bool cMenuBase::isOnCheck(sPadExt::PAD_BTN_TYPE button, u32 pad_id) {
    if (mpGUIMenu == nullptr) {
        if (mpRefGUI != nullptr) {
            if (mUseGUIMenu) {
                return false;
            }
        }
    } else {
        if (mUseGUIMenu) {
            return false;
        }
    }
    return static_cast<sPadExt*>(sPad::getInstance())->isOnCheck(button, pad_id);
}

bool cMenuBase::reqDialog(nGUIExt::REQ_DIALOG_TYPE dialogType, MT_CTSTR mainMsg, s32 defPos, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4) {
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->kill();
        mpGUISystemMsg = nullptr;
        uGUISystemMsg* t0 = cGUIUtility::reqDialog(dialogType, mainMsg, defPos, choice1, choice2, choice3, choice4, static_cast<sGUIExt*>(sGUI::getInstance())->isChatMenuUISubMenu());
        if ((mpGUISystemMsg = t0) != nullptr) {
            t0->mBasePointerPrio = getNextBasePointerPrio();
            return true;
        } else {
            return false;
        }
    } else {
        uGUISystemMsg* t0 = cGUIUtility::reqDialog(dialogType, mainMsg, defPos, choice1, choice2, choice3, choice4, static_cast<sGUIExt*>(sGUI::getInstance())->isChatMenuUISubMenu());
        if ((mpGUISystemMsg = t0) != nullptr) {
            t0->mBasePointerPrio = getNextBasePointerPrio();
            return true;
        } else {
            return false;
        }
    }
}

__attribute__((weak)) s32 cMenuBase::updateCursorX(cCursor& cursorClass, s32& cursor, s32 orderId) {
    DDON_STUB("cMenuBase::updateCursorX")
    return {};
}

__attribute__((weak)) s32 cMenuBase::updateCursorY(cCursor& cursorClass, s32& cursor, s32 orderId) {
    DDON_STUB("cMenuBase::updateCursorY")
    return {};
}

__attribute__((weak)) void cMenuBase::updateCursorTab(s32& tab, s32 max) {
    DDON_STUB("cMenuBase::updateCursorTab")
    /* stub */
}

__attribute__((weak)) uGUIBase* cMenuBase::registerGUI(const MtDTI& dti, u32 line, u64 group) {
    DDON_STUB("cMenuBase::registerGUI")
    return nullptr;
}

uGUIBase* cMenuBase::registerGUI(uGUIBase* guiUnit, u32 line, u64 group) {
    if (mpGUIMenu != nullptr) {
        mpGUIMenu->kill();
        mpGUIMenu = nullptr;
    }
    uGUIBase* v3_0;
    if (guiUnit == nullptr) {
        v3_0 = nullptr;
        mUseGUIMenu = v3_0 != nullptr;
        return v3_0;
    } else {
        const MtDTI& t0 = guiUnit->getDTI();
        MT_CTSTR v0_1 = uGUIBase::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v3_0 = nullptr;
                    mUseGUIMenu = v3_0 != nullptr;
                    return v3_0;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
            if (guiUnit == nullptr) {
                v3_0 = nullptr;
                mUseGUIMenu = v3_0 != nullptr;
                return v3_0;
            }
        }
    }
    sUnit::getInstance()->addBottom(static_cast<MOVE_LINE>(line), static_cast<cUnit*>(guiUnit), group);
    v3_0 = guiUnit;
    mUseGUIMenu = v3_0 != nullptr;
    return v3_0;
}

__attribute__((weak)) bool cMenuBase::isCancelFromGUI() {
    DDON_STUB("cMenuBase::isCancelFromGUI")
    return {};
}

bool cMenuBase::isUseGUI() {
    if ((mpGUIMenu == nullptr) && (mpRefGUI == nullptr)) {
        return false;
    }
    return mUseGUIMenu;
}

__attribute__((weak)) bool cMenuBase::isGUIWindowActive() const {
    DDON_STUB("cMenuBase::isGUIWindowActive")
    return {};
}

__attribute__((weak)) void cMenuBase::setGUIWindowActive(bool isActive) {
    DDON_STUB("cMenuBase::setGUIWindowActive")
    /* stub */
}

__attribute__((weak)) void cMenuBase::initMenu() {
    if (sMenu::getInstance()->checkMoveMenu(this, false)) {
        exitMenu();
    }
    mIsUpdateCursor = false;
    mIsUpdateTab = false;
    mIsUpdateButton = false;
    sMenu::getInstance()->entryMenu(this);
    mBusyFlag = false;
    mMenuCursor[6] = 0;
    mMenuCursor[4] = 0;
    mMenuCursor[5] = 0;
    mMenuCursor[2] = 0;
    mMenuCursor[3] = 0;
    mMenuCursor[0] = 0;
    mMenuCursor[1] = 0;
    mMenuRno[4] = 0;
    mMenuRno[5] = 0;
    mMenuRno[2] = 0;
    mMenuRno[3] = 0;
    mMenuRno[0] = 0;
    mMenuRno[1] = 0;
    mCustomBasePrio = 0xFFFFFFFF;
    if (mMenuSupportList.mLength != 0) {
        u32 v0_0 = mMenuSupportList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMenuSupportList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMenuSupportList.mpArray[i0_3];
                v1_0 = mMenuSupportList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMenuSupportList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMenuSupportList.mpArray));
    }
    mMenuSupportList.mpArray = nullptr;
    mMenuSupportList.mBufsiz = 0;
    mMenuSupportList.mLength = 0;
    mpList = nullptr;
    mpMenu = nullptr;
    mpDialogFlow = nullptr;
}

__attribute__((weak)) void cMenuBase::moveMenu() {
    DDON_STUB("cMenuBase::moveMenu")
    /* stub */
}

__attribute__((weak)) void cMenuBase::exitMenu() {
    mNowMoveFlag = false;
    updatePtr();
    if (mMenuSupportList.mLength != 0) {
        u32 v0_0 = mMenuSupportList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMenuSupportList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMenuSupportList.mpArray[i0_3];
                v1_0 = mMenuSupportList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMenuSupportList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMenuSupportList.mpArray));
    }
    mMenuSupportList.mpArray = nullptr;
    mMenuSupportList.mBufsiz = 0;
    mMenuSupportList.mLength = 0;
    if (mpGUIMenu != nullptr) {
        mpGUIMenu->kill();
        mpGUIMenu = nullptr;
    }
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->kill();
        mpGUISystemMsg = nullptr;
    }
    mpRefGUI = nullptr;
    sMenu::getInstance()->eraseMenu(this);
}

void cMenuBase::setRefGUI(uGUIBase* pRefGUI, bool useGUI) {
    mpRefGUI = pRefGUI;
    if (pRefGUI == nullptr) {
        mUseGUIMenu = false;
    } else {
        mUseGUIMenu = useGUI;
    }
}

__attribute__((weak)) void cMenuBase::setGUIBasePointerPriority(u32 prio) {
    DDON_STUB("cMenuBase::setGUIBasePointerPriority")
    /* stub */
}

s32 cMenuBase::getMenuId(s32 index) {
    if (sMenu::getInstance()->checkMoveMenu(this, false)) {
        if (mpList == nullptr) {
            if (mpMenu != nullptr) {
                return mpMenu->getMenuId(index);
            } else {
                if (static_cast<unsigned int>(index) < mMenuNum) {
                    if (mpMenuList != nullptr) {
                        return mpMenuList[(index <= -1) ? 0 : index];
                    }
                }
                return 0;
            }
        } else {
            return mpList->getMenuId(index);
        }
    } else {
        return 0;
    }
}

s32 cMenuBase::getIndexFromMenuId(s32 menuId) {
    if (mpMenu != nullptr) {
        return mpMenu->getIndexFromMenuId(menuId);
    } else {
        return getConvertCursorIdx(menuId);
    }
}

s32 cMenuBase::getListCursor() {
    if (mpList != nullptr) {
        return mpList->getCursor();
    } else {
        if (mpMenu != nullptr) {
            return mpMenu->getCursor();
        } else {
            return 0;
        }
    }
}

s32 cMenuBase::getBaseListIndexNow() {
    if (mpList != nullptr) {
        return mpList->getBaseListIndexNow();
    } else {
        return -1;
    }
}

bool cMenuBase::checkListFilter(u32 sortListIndex) {
    return true;
}

__attribute__((weak)) cMenuDialogFlow* cMenuBase::setupDialogFlow(u32 attr) {
    DDON_STUB("cMenuBase::setupDialogFlow")
    return nullptr;
}

cMenuDialogFlow* cMenuBase::resetDialogFlow(u32 attr) {
    if (mpDialogFlow != nullptr) {
        mpDialogFlow->initialize(attr);
        return mpDialogFlow;
    } else {
        return nullptr;
    }
}

cMenuDialogFlow::RET cMenuBase::moveDialogFlow() {
    if (mpDialogFlow != nullptr) {
        return mpDialogFlow->moveFlow();
    } else {
        return cMenuDialogFlow::RET_DLG_NULL;
    }
}

__attribute__((weak)) cMenuSupportMenu* cMenuBase::setupSupportMenu(u32 menuMax, bool isSimple, bool isAutoUpdate) {
    DDON_STUB("cMenuBase::setupSupportMenu")
    return nullptr;
}

void cMenuBase::moveSupportMenu(s32 cursorOrderId) {
    if (mpMenu == nullptr) {
        return;
    }
    mpMenu->moveMenu(cursorOrderId);
}

void cMenuBase::createMenuListTbl(const s32* pTbl, u32 menuNum) {
    if (mpMenu == nullptr) {
        return;
    }
    mpMenu->createMenuListTbl(pTbl, menuNum);
}

void cMenuBase::addMenuList(s32 menuId) {
    if (mpMenu == nullptr) {
        return;
    }
    mpMenu->addMenuList(menuId);
}

bool cMenuBase::isDecideMenu(u32 decideSe, u32 notSelectSe) {
    if (mpMenu != nullptr) {
        if ((mpMenu->mMenuNum != 0) && isDecideIndex(mpMenu->getCursor(), decideSe, notSelectSe)) {
            return true;
        }
    }
    return false;
}

__attribute__((weak)) cMenuSupportList* cMenuBase::setupSupportList(u32 listMax, u32 pageElemMax, u32 pageMenuMax) {
    DDON_STUB("cMenuBase::setupSupportList")
    return nullptr;
}

void cMenuBase::createList(u32 length) {
    if (mpList == nullptr) {
        return;
    }
    mpList->createList(length);
}

void cMenuBase::moveList(u32 length) {
    if (mpList == nullptr) {
        return;
    }
    mpList->moveList(length);
}

void cMenuBase::setListCursor(s32 cursorPos) {
    if (mpList == nullptr) {
        if (mpMenu != nullptr) {
            mpMenu->mListCursor = cursorPos;
        }
    } else {
        mpList->mListCursor = cursorPos;
    }
}

inline cMenuBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuBase::MyDTI cMenuBase::DTI("cMenuBase", &::MtObject::DTI, 176ul, 0u, 0u);

MtObject* cMenuBase::MyDTI::newInstance() const {
    return new (16u) cMenuBase;
}

const MtDTI& cMenuBazaarBuy::getDTI() const {
    return cMenuBazaarBuy::DTI;
}

inline cMenuBazaarBuy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuBazaarBuy::MyDTI cMenuBazaarBuy::DTI("cMenuBazaarBuy", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuBazaarBuy::MyDTI::newInstance() const {
    return new (16u) cMenuBazaarBuy;
}

const MtDTI& cMenuBazaarMenu::getDTI() const {
    return cMenuBazaarMenu::DTI;
}

void cMenuBazaarMenu::initBazaarMenu() {
    initMenu();
    mMenuRno[0] = 0;
    mMenuCursor[0] = 0;
    mMenuCursor[1] = 0;
    mMenuCursor[2] = 0;
    if ((mpGUIMenu = static_cast<sGUIExt*>(sGUI::getInstance())->newSingletonMenu(static_cast<const MtDTI*>(&uGUIBazaar::DTI))) == nullptr) {
        return;
    }
    mUseGUIMenu = true;
}

__attribute__((weak)) nMenu::MENU_RET cMenuBazaarMenu::moveBazaarMenu() {
    DDON_STUB("cMenuBazaarMenu::moveBazaarMenu")
    return {};
}

inline cMenuBazaarMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuBazaarMenu::MyDTI cMenuBazaarMenu::DTI("cMenuBazaarMenu", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuBazaarMenu::MyDTI::newInstance() const {
    return new (16u) cMenuBazaarMenu;
}

const MtDTI& cMenuBlackList::getDTI() const {
    return cMenuBlackList::DTI;
}

void cMenuBlackList::initBlackList(uGUIBase* pRefGUI) {
    initMenu();
    mMenuRno[0] = 0;
    setupSupportList(static_cast<sNetworkExt*>(sNetwork::getInstance())->getBlackListMax(), static_cast<sNetworkExt*>(sNetwork::getInstance())->getBlackListMax(), 0u);
    if (mpList != nullptr) {
        mpList->createList(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mBlackList.mLength);
    }
    setRefGUI(pRefGUI, true);
}

__attribute__((weak)) nMenu::MENU_RET cMenuBlackList::moveBlackList() {
    DDON_STUB("cMenuBlackList::moveBlackList")
    return {};
}

void cMenuBlackList::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuBlackList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuBlackList::MyDTI cMenuBlackList::DTI("cMenuBlackList", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuBlackList::MyDTI::newInstance() const {
    return new (16u) cMenuBlackList;
}

const MtDTI& cMenuBreakupParty::getDTI() const {
    return cMenuBreakupParty::DTI;
}

nMenu::MENU_RET cMenuBreakupParty::moveBreakupParty() {
    moveMenu();
    if (mMenuRno[0] == 0) {
        if (mpDialogFlow != nullptr) {
            cMenuDialogFlow::RET t0 = mpDialogFlow->moveFlow();
            switch (t0) {
                case cMenuDialogFlow::RET_DLG_SET_DLG:
                {
                    cMenuDialogFlow* t1 = getDialogFlow();
                    MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 18u);
                    MT_CTSTR t3 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                    t1->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t2, 1, t3, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                    if (mpDialogFlow != nullptr) {
                        mpDialogFlow->setDialogSE(4u, 311u, static_cast<rSoundRequest*>(nullptr));
                        return nMenu::MENU_RET_CONTINUE;
                    } else {
                        if (mpGUISystemMsg != nullptr) {
                            mpGUISystemMsg->setSE(nGUIExt::TRG_DECIDE, 311u, static_cast<rSoundRequest*>(nullptr));
                            return nMenu::MENU_RET_CONTINUE;
                        } else {
                            return nMenu::MENU_RET_CONTINUE;
                        }
                    }
                    break;
                }
                case cMenuDialogFlow::RET_DLG_CHOICE:
                {
                    if (getDialogFlow()->mChoice == 0) {
                        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->breakupParty();
                        getDialogFlow()->setComWait(42);
                        return nMenu::MENU_RET_CONTINUE;
                    } else {
                        return nMenu::MENU_RET_CANCEL;
                    }
                    break;
                }
                case cMenuDialogFlow::RET_DLG_SET_RESULT:
                {
                    cMenuDialogFlow* t4 = getDialogFlow();
                    t4->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 19u), 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                    return nMenu::MENU_RET_CONTINUE;
                }
                case cMenuDialogFlow::RET_DLG_EXIT:
                {
                    return nMenu::MENU_RET_EXIT;
                }
                case cMenuDialogFlow::RET_DLG_ERROR:
                {
                    return nMenu::MENU_RET_CANCEL;
                }
                case cMenuDialogFlow::RET_DLG_NULL:
                {
                    return nMenu::MENU_RET_CANCEL;
                }
                default:
                {
                    return nMenu::MENU_RET_CONTINUE;
                }
            }
        } else {
            return nMenu::MENU_RET_CANCEL;
        }
    } else {
        return nMenu::MENU_RET_CONTINUE;
    }
}

void cMenuBreakupParty::exitMenu() {
    this->cMenuBase::exitMenu();
}

bool cMenuBreakupParty::callbackCheckCloseDialog() {
    if ((static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->getGameSessionMemberNum(true) == 1) && !static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
        return true;
    }
    return sSoundManager::getInstance()->getBattleState() == sBattleState::SYS_STATE_BATTLE;
}

inline cMenuBreakupParty::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuBreakupParty::MyDTI cMenuBreakupParty::DTI("cMenuBreakupParty", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuBreakupParty::MyDTI::newInstance() const {
    return new (16u) cMenuBreakupParty;
}

const MtDTI& cMenuCancelFriend::getDTI() const {
    return cMenuCancelFriend::DTI;
}

cMenuCancelFriend::~cMenuCancelFriend() {
}

nMenu::MENU_RET cMenuCancelFriend::moveCancelFriend() {
    moveMenu();
    if (mMenuRno[0] == 0) {
        if (mpDialogFlow != nullptr) {
            cMenuDialogFlow::RET t0 = mpDialogFlow->moveFlow();
            switch (t0) {
                case cMenuDialogFlow::RET_DLG_SET_DLG:
                {
                    cMenuDialogFlow* t1 = getDialogFlow();
                    MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 200u);
                    MT_CTSTR t3 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                    t1->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t2, 1, t3, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                    getDialogFlow()->setMsgAnalyzerWork(0u, mCharName.ptr());
                    return nMenu::MENU_RET_CONTINUE;
                }
                case cMenuDialogFlow::RET_DLG_CHOICE:
                {
                    if (getDialogFlow()->mChoice == 0) {
                        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->cancelFriend(mCharacterId);
                        getDialogFlow()->setComWait(313);
                        return nMenu::MENU_RET_CONTINUE;
                    } else {
                        return nMenu::MENU_RET_CANCEL;
                    }
                    break;
                }
                case cMenuDialogFlow::RET_DLG_SET_RESULT:
                {
                    cMenuDialogFlow* t4 = getDialogFlow();
                    t4->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 201u), 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                    getDialogFlow()->setMsgAnalyzerWork(0u, mCharName.ptr());
                    return nMenu::MENU_RET_CONTINUE;
                }
                case cMenuDialogFlow::RET_DLG_EXIT:
                {
                    return nMenu::MENU_RET_EXIT;
                }
                case cMenuDialogFlow::RET_DLG_NULL:
                {
                    return nMenu::MENU_RET_CANCEL;
                }
                default:
                {
                    return nMenu::MENU_RET_CONTINUE;
                }
            }
        } else {
            return nMenu::MENU_RET_CANCEL;
        }
    } else {
        return nMenu::MENU_RET_CONTINUE;
    }
}

__attribute__((weak)) void cMenuCancelFriend::exitMenu() {
    DDON_STUB("cMenuCancelFriend::exitMenu")
    /* stub */
}

inline cMenuCancelFriend::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCancelFriend::MyDTI cMenuCancelFriend::DTI("cMenuCancelFriend", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuCancelFriend::MyDTI::newInstance() const {
    return new (16u) cMenuCancelFriend;
}

const MtDTI& cMenuChangeServer::getDTI() const {
    return cMenuChangeServer::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuChangeServer::moveChangeServer() {
    DDON_STUB("cMenuChangeServer::moveChangeServer")
    return {};
}

void cMenuChangeServer::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuChangeServer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuChangeServer::MyDTI cMenuChangeServer::DTI("cMenuChangeServer", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuChangeServer::MyDTI::newInstance() const {
    return new (16u) cMenuChangeServer;
}

const MtDTI& cMenuCharacterList::getDTI() const {
    return cMenuCharacterList::DTI;
}

void cMenuCharacterList::initCharacterList(uGUIBase* pGUIRefMenu) {
    initMenu();
    mMenuRno[0] = 0;
    mSearchSetting.setDefaultData();
    mSearchSetting.initSearchFilter(1);
    cMenuSupportList* pList = setupSupportList(256u, 14u, 15u);
    if (pList != nullptr) {
        pList->mMenuTopId = 0;
        pList->addBelowMenu(14);
        nUserSession::CPacket_S2C_CHARACTER_SEARCH_RES* t0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getCharacterSearchPacket();
        if (mpList != nullptr) {
            mpList->createList(t0->m_CharacterList.mLength);
        }
        mFirst = true;
        setRefGUI(pGUIRefMenu, true);
    } else {
        mFirst = true;
        setRefGUI(pGUIRefMenu, true);
    }
}

__attribute__((weak)) nMenu::MENU_RET cMenuCharacterList::moveCharacterList() {
    DDON_STUB("cMenuCharacterList::moveCharacterList")
    return {};
}

void cMenuCharacterList::exitMenu() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearCharacterSearchPacket();
    this->cMenuBase::exitMenu();
}

inline cMenuCharacterList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCharacterList::MyDTI cMenuCharacterList::DTI("cMenuCharacterList", &::cMenuBase::DTI, 480ul, 0u, 0u);

MtObject* cMenuCharacterList::MyDTI::newInstance() const {
    return new (16u) cMenuCharacterList;
}

const MtDTI& cMenuCraftColorFrame::getDTI() const {
    return cMenuCraftColorFrame::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftColorFrame::moveCraftColorFrame(u32* slotNo) {
    DDON_STUB("cMenuCraftColorFrame::moveCraftColorFrame")
    return {};
}

inline cMenuCraftColorFrame::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftColorFrame::MyDTI cMenuCraftColorFrame::DTI("cMenuCraftColorFrame", &::cMenuBase::DTI, 224ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuCraftColorFrame::MyDTI::newInstance() const {
    DDON_STUB("cMenuCraftColorFrame::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuCraftColorFrame::cMenuCtrl::getDTI() const {
    return cMenuCraftColorFrame::cMenuCtrl::DTI;
}

inline cMenuCraftColorFrame::cMenuCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftColorFrame::cMenuCtrl::MyDTI cMenuCraftColorFrame::cMenuCtrl::DTI("cMenuCraftColorFrame::cMenuCtrl", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuCraftColorFrame::cMenuCtrl::MyDTI::newInstance() const {
    DDON_STUB("cMenuCraftColorFrame::cMenuCtrl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuCraftColorItem::getDTI() const {
    return cMenuCraftColorItem::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftColorItem::moveCraftColorItem() {
    DDON_STUB("cMenuCraftColorItem::moveCraftColorItem")
    return {};
}

inline cMenuCraftColorItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftColorItem::MyDTI cMenuCraftColorItem::DTI("cMenuCraftColorItem", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuCraftColorItem::MyDTI::newInstance() const {
    return new (16u) cMenuCraftColorItem;
}

const MtDTI& cMenuCraftCreateItem::getDTI() const {
    return cMenuCraftCreateItem::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftCreateItem::moveCraftCreateItem() {
    DDON_STUB("cMenuCraftCreateItem::moveCraftCreateItem")
    return {};
}

inline cMenuCraftCreateItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftCreateItem::MyDTI cMenuCraftCreateItem::DTI("cMenuCraftCreateItem", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuCraftCreateItem::MyDTI::newInstance() const {
    return new (16u) cMenuCraftCreateItem;
}

const MtDTI& cMenuCraftElementFrame::getDTI() const {
    return cMenuCraftElementFrame::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftElementFrame::moveCraftElementFrame(u32* slotNo) {
    DDON_STUB("cMenuCraftElementFrame::moveCraftElementFrame")
    return {};
}

inline cMenuCraftElementFrame::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftElementFrame::MyDTI cMenuCraftElementFrame::DTI("cMenuCraftElementFrame", &::cMenuBase::DTI, 272ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuCraftElementFrame::MyDTI::newInstance() const {
    DDON_STUB("cMenuCraftElementFrame::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuCraftElementFrame::cMenuCtrl::getDTI() const {
    return cMenuCraftElementFrame::cMenuCtrl::DTI;
}

inline cMenuCraftElementFrame::cMenuCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftElementFrame::cMenuCtrl::MyDTI cMenuCraftElementFrame::cMenuCtrl::DTI("cMenuCraftElementFrame::cMenuCtrl", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuCraftElementFrame::cMenuCtrl::MyDTI::newInstance() const {
    DDON_STUB("cMenuCraftElementFrame::cMenuCtrl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuCraftElementItem::getDTI() const {
    return cMenuCraftElementItem::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftElementItem::moveCraftElementItem() {
    DDON_STUB("cMenuCraftElementItem::moveCraftElementItem")
    return {};
}

inline cMenuCraftElementItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftElementItem::MyDTI cMenuCraftElementItem::DTI("cMenuCraftElementItem", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuCraftElementItem::MyDTI::newInstance() const {
    return new (16u) cMenuCraftElementItem;
}

const MtDTI& cMenuCraftGoldStoneDialog::getDTI() const {
    return cMenuCraftGoldStoneDialog::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftGoldStoneDialog::moveCraftGoldStoneDialog(s32* selectType) {
    DDON_STUB("cMenuCraftGoldStoneDialog::moveCraftGoldStoneDialog")
    return {};
}

inline cMenuCraftGoldStoneDialog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftGoldStoneDialog::MyDTI cMenuCraftGoldStoneDialog::DTI("cMenuCraftGoldStoneDialog", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuCraftGoldStoneDialog::MyDTI::newInstance() const {
    return new (16u) cMenuCraftGoldStoneDialog;
}

const MtDTI& cMenuCraftItemSelect::getDTI() const {
    return cMenuCraftItemSelect::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftItemSelect::moveCraftItemSelect() {
    DDON_STUB("cMenuCraftItemSelect::moveCraftItemSelect")
    return {};
}

inline cMenuCraftItemSelect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftItemSelect::MyDTI cMenuCraftItemSelect::DTI("cMenuCraftItemSelect", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuCraftItemSelect::MyDTI::newInstance() const {
    return new (16u) cMenuCraftItemSelect;
}

const MtDTI& cMenuCraftMenu::getDTI() const {
    return cMenuCraftMenu::DTI;
}

void cMenuCraftMenu::initCraftMenu() {
    initMenu();
    sCraftManager::getInstance()->mCraftCtrl.resetCraftPawn();
    sCraftManager::getInstance()->mCraftCtrl.mRecipeId = 0;
    sCraftManager::getInstance()->mCraftCtrl.resetSelectedCraftPawn();
    mMenuRno[0] = 0;
    mMenuCursor[0] = 0;
    if ((mpGUIMenu = static_cast<sGUIExt*>(sGUI::getInstance())->newSingletonMenu(static_cast<const MtDTI*>(&uGUICraft::DTI))) != nullptr) {
        mUseGUIMenu = true;
    }
    static_cast<sGUIExt*>(sGUI::getInstance())->createShopTitle(sGUIExt::SHOPTITLE_TYPE::CRAFT, sGUIExt::SHOPTITLE_TYPE::GOLD);
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftMenu::moveCraftMenu() {
    DDON_STUB("cMenuCraftMenu::moveCraftMenu")
    return {};
}

void cMenuCraftMenu::exitMenu() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearCraftProductInfoPacket();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearCraftProductPacket();
    this->cMenuBase::exitMenu();
}

inline cMenuCraftMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftMenu::MyDTI cMenuCraftMenu::DTI("cMenuCraftMenu", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuCraftMenu::MyDTI::newInstance() const {
    return new (16u) cMenuCraftMenu;
}

const MtDTI& cMenuCraftMyPawnList::getDTI() const {
    return cMenuCraftMyPawnList::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftMyPawnList::moveCraftMyPawnList() {
    DDON_STUB("cMenuCraftMyPawnList::moveCraftMyPawnList")
    return {};
}

inline cMenuCraftMyPawnList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftMyPawnList::MyDTI cMenuCraftMyPawnList::DTI("cMenuCraftMyPawnList", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuCraftMyPawnList::MyDTI::newInstance() const {
    return new (16u) cMenuCraftMyPawnList;
}

const MtDTI& cMenuCraftPoint::getDTI() const {
    return cMenuCraftPoint::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftPoint::moveCraftPoint() {
    DDON_STUB("cMenuCraftPoint::moveCraftPoint")
    return {};
}

inline cMenuCraftPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftPoint::MyDTI cMenuCraftPoint::DTI("cMenuCraftPoint", &::cMenuBase::DTI, 208ul, 0u, 0u);

MtObject* cMenuCraftPoint::MyDTI::newInstance() const {
    return new (16u) cMenuCraftPoint;
}

const MtDTI& cMenuCraftProcessMenu::getDTI() const {
    return cMenuCraftProcessMenu::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftProcessMenu::moveCraftProcessMenu(u32* slotNo) {
    DDON_STUB("cMenuCraftProcessMenu::moveCraftProcessMenu")
    return {};
}

__attribute__((weak)) cMenuCraftMenu::CREATE_STATE cMenuCraftProcessMenu::isPrice(u32 itemId, u8 priceType) {
    DDON_STUB("cMenuCraftProcessMenu::isPrice")
    return {};
}

inline cMenuCraftProcessMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftProcessMenu::MyDTI cMenuCraftProcessMenu::DTI("cMenuCraftProcessMenu", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuCraftProcessMenu::MyDTI::newInstance() const {
    return new (16u) cMenuCraftProcessMenu;
}

const MtDTI& cMenuCraftRecipeList::getDTI() const {
    return cMenuCraftRecipeList::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftRecipeList::moveCraftRecipeList() {
    DDON_STUB("cMenuCraftRecipeList::moveCraftRecipeList")
    return {};
}

__attribute__((weak)) cMenuCraftMenu::CREATE_STATE cMenuCraftRecipeList::isCreate(u32 recipeId, u32 type, bool isEffect) {
    DDON_STUB("cMenuCraftRecipeList::isCreate")
    return {};
}

void cMenuCraftRecipeList::errorAnnounce(cMenuCraftMenu::CREATE_STATE state) {
    switch (static_cast<unsigned int>(state - 1)) {
        case 0:
        {
            sGUI* t0 = sGUI::getInstance();
            static_cast<sGUIExt*>(t0)->requestAnnounce(static_cast<sGUIExt*>(t0)->getMsgFromIdxInfo(static_cast<sGUIExt*>(t0)->getMsgCommonDialog(), 327u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
            break;
        }
        case 1:
        {
            sGUI* t1 = sGUI::getInstance();
            static_cast<sGUIExt*>(t1)->requestAnnounce(static_cast<sGUIExt*>(t1)->getMsgFromIdxInfo(static_cast<sGUIExt*>(t1)->getMsgCommonDialog(), 328u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
            break;
        }
        case 2:
        {
            sGUI* t2 = sGUI::getInstance();
            static_cast<sGUIExt*>(t2)->requestAnnounce(static_cast<sGUIExt*>(t2)->getMsgFromIdxInfo(static_cast<sGUIExt*>(t2)->getMsgCommonDialog(), 329u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
            break;
        }
        case 3:
        {
            sGUI* t3 = sGUI::getInstance();
            static_cast<sGUIExt*>(t3)->requestAnnounce(static_cast<sGUIExt*>(t3)->getMsgFromIdxInfo(static_cast<sGUIExt*>(t3)->getMsgCommonDialog(), 330u), 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
            break;
        }
        default:
        {
            break;
        }
    }
}

inline cMenuCraftRecipeList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftRecipeList::MyDTI cMenuCraftRecipeList::DTI("cMenuCraftRecipeList", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuCraftRecipeList::MyDTI::newInstance() const {
    return new (16u) cMenuCraftRecipeList;
}

const MtDTI& cMenuCraftSupportFrame::getDTI() const {
    return cMenuCraftSupportFrame::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftSupportFrame::moveCraftSupportFrame(u32* slotNo) {
    DDON_STUB("cMenuCraftSupportFrame::moveCraftSupportFrame")
    return {};
}

inline cMenuCraftSupportFrame::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftSupportFrame::MyDTI cMenuCraftSupportFrame::DTI("cMenuCraftSupportFrame", &::cMenuBase::DTI, 280ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuCraftSupportFrame::MyDTI::newInstance() const {
    DDON_STUB("cMenuCraftSupportFrame::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuCraftSupportFrame::cMenuCtrl::getDTI() const {
    return cMenuCraftSupportFrame::cMenuCtrl::DTI;
}

inline cMenuCraftSupportFrame::cMenuCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftSupportFrame::cMenuCtrl::MyDTI cMenuCraftSupportFrame::cMenuCtrl::DTI("cMenuCraftSupportFrame::cMenuCtrl", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuCraftSupportFrame::cMenuCtrl::MyDTI::newInstance() const {
    DDON_STUB("cMenuCraftSupportFrame::cMenuCtrl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuCraftSupportList::getDTI() const {
    return cMenuCraftSupportList::DTI;
}

inline cMenuCraftSupportList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftSupportList::MyDTI cMenuCraftSupportList::DTI("cMenuCraftSupportList", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuCraftSupportList::MyDTI::newInstance() const {
    return new (16u) cMenuCraftSupportList;
}

const MtDTI& cMenuCraftTask::getDTI() const {
    return cMenuCraftTask::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftTask::moveCraftTask() {
    DDON_STUB("cMenuCraftTask::moveCraftTask")
    return {};
}

inline cMenuCraftTask::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftTask::MyDTI cMenuCraftTask::DTI("cMenuCraftTask", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuCraftTask::MyDTI::newInstance() const {
    return new (16u) cMenuCraftTask;
}

const MtDTI& cMenuCraftUpGradeItem::getDTI() const {
    return cMenuCraftUpGradeItem::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftUpGradeItem::moveCraftUpGradeItem() {
    DDON_STUB("cMenuCraftUpGradeItem::moveCraftUpGradeItem")
    return {};
}

inline cMenuCraftUpGradeItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftUpGradeItem::MyDTI cMenuCraftUpGradeItem::DTI("cMenuCraftUpGradeItem", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuCraftUpGradeItem::MyDTI::newInstance() const {
    return new (16u) cMenuCraftUpGradeItem;
}

const MtDTI& cMenuCraftUpGradeList::getDTI() const {
    return cMenuCraftUpGradeList::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCraftUpGradeList::moveCraftUpGradeList() {
    DDON_STUB("cMenuCraftUpGradeList::moveCraftUpGradeList")
    return {};
}

inline cMenuCraftUpGradeList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCraftUpGradeList::MyDTI cMenuCraftUpGradeList::DTI("cMenuCraftUpGradeList", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuCraftUpGradeList::MyDTI::newInstance() const {
    return new (16u) cMenuCraftUpGradeList;
}

const MtDTI& cMenuCreateGameSession::getDTI() const {
    return cMenuCreateGameSession::DTI;
}

void cMenuCreateGameSession::initCreateGameSession(s32 type) {
    initMenu();
    mMenuRno[0] = 0;
    mCreateGameSessionDialogHandle = 0xFFFFFFFF;
    mCreateType = type;
}

__attribute__((weak)) nMenu::MENU_RET cMenuCreateGameSession::moveCreateGameSession() {
    DDON_STUB("cMenuCreateGameSession::moveCreateGameSession")
    return {};
}

inline cMenuCreateGameSession::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCreateGameSession::MyDTI cMenuCreateGameSession::DTI("cMenuCreateGameSession", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuCreateGameSession::MyDTI::newInstance() const {
    return new (16u) cMenuCreateGameSession;
}

const MtDTI& cMenuCustomize::getDTI() const {
    return cMenuCustomize::DTI;
}

cMenuCustomize::~cMenuCustomize() {
}

__attribute__((weak)) void cMenuCustomize::initCustomize(u32 pawnId, u32 prio) {
    DDON_STUB("cMenuCustomize::initCustomize")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuCustomize::moveCustomize() {
    DDON_STUB("cMenuCustomize::moveCustomize")
    return {};
}

inline cMenuCustomize::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuCustomize::MyDTI cMenuCustomize::DTI("cMenuCustomize", &::cMenuBase::DTI, 6688ul, 0u, 0u);

alignas(4) unsigned char cMenuCustomize_edit_target_bytes[28] __asm__("_ZN14cMenuCustomize11edit_targetE") = {0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00};

MtObject* cMenuCustomize::MyDTI::newInstance() const {
    return new (16u) cMenuCustomize;
}

const MtDTI& cMenuDispStatus::getDTI() const {
    return cMenuDispStatus::DTI;
}

__attribute__((weak)) void cMenuDispStatus::initDispStatus(s32 dispType, const cContextInstHm& context, u32 prio, bool isChatSubMenu) {
    DDON_STUB("cMenuDispStatus::initDispStatus")
    /* stub */
}

void cMenuDispStatus::initDispStatus(s32 dispType, s32 charType, s32 masterId, s32 pawnType, u32 prio, bool isChatSubMenu) {
    initMenu();
    mMasterId = 0;
    mPawnType = 0;
    mDispType = 0;
    mCharType = 0;
    mContext.cContextInstHm::reset();
    mpRefContext = &mContext;
    mMenuCursor[0] = 0;
    mMenuRno[0] = 0;
    mIsMyPawn = false;
    mIsPartyPawn = false;
    mIsChatSubMenu = false;
    mDispType = dispType;
    mCharType = charType;
    mMasterId = static_cast<u32>(masterId);
    mPawnType = pawnType;
    if (charType != 0) {
        if (pawnType == 0) {
            mIsMyPawn = true;
        }
    } else {
        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLobbyCharacterId == static_cast<unsigned int>(masterId)) {
            mpRefContext = sContextManager::getInstance()->getContextMyPlayer();
        }
    }
    mBasePointerPrio = prio;
    mIsChatSubMenu = isChatSubMenu;
}

__attribute__((weak)) nMenu::MENU_RET cMenuDispStatus::moveDispStatus() {
    DDON_STUB("cMenuDispStatus::moveDispStatus")
    return {};
}

inline cMenuDispStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuDispStatus::MyDTI cMenuDispStatus::DTI("cMenuDispStatus", &::cMenuBase::DTI, 30144ul, 0u, 0u);

MtObject* cMenuDispStatus::MyDTI::newInstance() const {
    return new (16u) cMenuDispStatus;
}

const MtDTI& cMenuEditBlackList::getDTI() const {
    return cMenuEditBlackList::DTI;
}

__attribute__((noinline)) cMenuEditBlackList::~cMenuEditBlackList() {
}

__attribute__((weak)) nMenu::MENU_RET cMenuEditBlackList::moveEditBlackList() {
    DDON_STUB("cMenuEditBlackList::moveEditBlackList")
    return {};
}

void cMenuEditBlackList::exitMenu() {
    nNet::clearBaseInfo(mBaseInfo);
    this->cMenuBase::exitMenu();
}

inline cMenuEditBlackList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuEditBlackList::MyDTI cMenuEditBlackList::DTI("cMenuEditBlackList", &::cMenuBase::DTI, 232ul, 0u, 0u);

MtObject* cMenuEditBlackList::MyDTI::newInstance() const {
    return new (16u) cMenuEditBlackList;
}

const MtDTI& cMenuEditFavoritePawn::getDTI() const {
    return cMenuEditFavoritePawn::DTI;
}

cMenuEditFavoritePawn::~cMenuEditFavoritePawn() {
}

nMenu::MENU_RET cMenuEditFavoritePawn::moveEditFavoritePawn() {
    moveMenu();
    if (mMenuRno[0] == 0) {
        if (mpDialogFlow != nullptr) {
            cMenuDialogFlow::RET t0 = mpDialogFlow->moveFlow();
            switch (t0) {
                case cMenuDialogFlow::RET_DLG_SET_DLG:
                {
                    if (mType != 0) {
                        cMenuDialogFlow* t1 = getDialogFlow();
                        MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 197u);
                        MT_CTSTR t3 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                        t1->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t2, 0, t3, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                        getDialogFlow()->setMsgAnalyzerWork(0u, mPawnName.ptr());
                        return nMenu::MENU_RET_CONTINUE;
                    } else {
                        cMenuDialogFlow* t1 = getDialogFlow();
                        MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 196u);
                        MT_CTSTR t3 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                        t1->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t2, 0, t3, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                        getDialogFlow()->setMsgAnalyzerWork(0u, mPawnName.ptr());
                        return nMenu::MENU_RET_CONTINUE;
                    }
                    break;
                }
                case cMenuDialogFlow::RET_DLG_CHOICE:
                {
                    if (getDialogFlow()->mChoice == 0) {
                        if (mType != 0) {
                            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->deleteFavoritePawn(mPawnId);
                            getDialogFlow()->setComWait(84);
                            return nMenu::MENU_RET_CONTINUE;
                        } else {
                            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->setFavoritePawn(mPawnId);
                            getDialogFlow()->setComWait(83);
                            return nMenu::MENU_RET_CONTINUE;
                        }
                    } else {
                        return nMenu::MENU_RET_CANCEL;
                    }
                    break;
                }
                case cMenuDialogFlow::RET_DLG_SET_RESULT:
                {
                    if (mType != 0) {
                        cMenuDialogFlow* t4 = getDialogFlow();
                        t4->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 199u), 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                        getDialogFlow()->setMsgAnalyzerWork(0u, mPawnName.ptr());
                        return nMenu::MENU_RET_CONTINUE;
                    } else {
                        cMenuDialogFlow* t4 = getDialogFlow();
                        t4->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 198u), 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                        getDialogFlow()->setMsgAnalyzerWork(0u, mPawnName.ptr());
                        return nMenu::MENU_RET_CONTINUE;
                    }
                    break;
                }
                case cMenuDialogFlow::RET_DLG_EXIT:
                {
                    return nMenu::MENU_RET_EXIT;
                }
                case cMenuDialogFlow::RET_DLG_NULL:
                {
                    return nMenu::MENU_RET_CANCEL;
                }
                default:
                {
                    return nMenu::MENU_RET_CONTINUE;
                }
            }
        } else {
            return nMenu::MENU_RET_CANCEL;
        }
    } else {
        return nMenu::MENU_RET_CONTINUE;
    }
}

__attribute__((weak)) void cMenuEditFavoritePawn::exitMenu() {
    DDON_STUB("cMenuEditFavoritePawn::exitMenu")
    /* stub */
}

inline cMenuEditFavoritePawn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuEditFavoritePawn::MyDTI cMenuEditFavoritePawn::DTI("cMenuEditFavoritePawn", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuEditFavoritePawn::MyDTI::newInstance() const {
    return new (16u) cMenuEditFavoritePawn;
}

const MtDTI& cMenuEntryGameSession::getDTI() const {
    return cMenuEntryGameSession::DTI;
}

inline cMenuEntryGameSession::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuEntryGameSession::MyDTI cMenuEntryGameSession::DTI("cMenuEntryGameSession", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuEntryGameSession::MyDTI::newInstance() const {
    return new (16u) cMenuEntryGameSession;
}

const MtDTI& cMenuFavoriteFriend::getDTI() const {
    return cMenuFavoriteFriend::DTI;
}

cMenuFavoriteFriend::~cMenuFavoriteFriend() {
}

__attribute__((weak)) void cMenuFavoriteFriend::initFavoriteFriend(u32 friendNo, MtString& charFirstName, MtString& charLastName, bool nowFavorite) {
    DDON_STUB("cMenuFavoriteFriend::initFavoriteFriend")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuFavoriteFriend::moveFavoriteFriend() {
    DDON_STUB("cMenuFavoriteFriend::moveFavoriteFriend")
    return {};
}

__attribute__((weak)) void cMenuFavoriteFriend::exitMenu() {
    DDON_STUB("cMenuFavoriteFriend::exitMenu")
    /* stub */
}

inline cMenuFavoriteFriend::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuFavoriteFriend::MyDTI cMenuFavoriteFriend::DTI("cMenuFavoriteFriend", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuFavoriteFriend::MyDTI::newInstance() const {
    return new (16u) cMenuFavoriteFriend;
}

const MtDTI& cMenuFirstOption::getDTI() const {
    return cMenuFirstOption::DTI;
}

void cMenuFirstOption::initFirstOption() {
    initMenu();
    mMenuRno[0] = 0;
    setupDialogFlow(0u);
}

__attribute__((weak)) nMenu::MENU_RET cMenuFirstOption::moveFirstOption() {
    DDON_STUB("cMenuFirstOption::moveFirstOption")
    return {};
}

void cMenuFirstOption::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuFirstOption::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuFirstOption::MyDTI cMenuFirstOption::DTI("cMenuFirstOption", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuFirstOption::MyDTI::newInstance() const {
    return new (16u) cMenuFirstOption;
}

const MtDTI& cMenuFriendList::getDTI() const {
    return cMenuFriendList::DTI;
}

void cMenuFriendList::exitMenu() {
    cMenuFriendList::getAllocator()->memFree(static_cast<void*>(mpSortList));
    cMenuFriendList::getAllocator()->memFree(static_cast<void*>(mpMenuList));
    cMenuFriendList::getAllocator()->memFree(static_cast<void*>(mpMenuParts));
    mpSortList = nullptr;
    mpMenuParts = nullptr;
    mpMenuList = nullptr;
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) void cMenuFriendList::initFriendList(uGUIBase* pRefGUI, u32 type, nCharacterData::stCharacterName* pDstName, u32* pCharacterId, CommunityCharacterBaseInfoVec* pExcludeList) {
    DDON_STUB("cMenuFriendList::initFriendList")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuFriendList::moveFriendList() {
    DDON_STUB("cMenuFriendList::moveFriendList")
    return {};
}

cMenuFriendList::LIST_TYPE cMenuFriendList::getListType(u32 index) {
    if (mType != 1) {
        if (index >= static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mApplyingFriendList.mLength) {
            if ((index - static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mApplyingFriendList.mLength) >= static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mApprovingFriendList.mLength) {
                return LIST_TYPE_FRIEND;
            } else {
                return LIST_TYPE_APPROVING;
            }
        } else {
            return LIST_TYPE_APPLYING;
        }
    } else {
        return LIST_TYPE_FRIEND;
    }
}

void cMenuFriendList::createSortList() {
    mSortListCount = 0;
    u32* v0_1 = mpSortList;
    if (v0_1 != nullptr) {
        sNetwork* v0_4 = sNetwork::getInstance();
        u32 v2_3;
        if (static_cast<sNetworkExt*>(v0_4)->mFriendListMax != 0) {
            unsigned int i0_0 = 0;
            u32 v1_3;
            for (;;) {
                v0_1[i0_0] = 0;
                v1_3 = static_cast<sNetworkExt*>(v0_4)->getFriendListMax();
                if ((i0_0 + 1u) < v1_3) {
                    i0_0 += 1u;
                } else {
                    break;
                }
            }
            v2_3 = v1_3;
        } else {
            v2_3 = 0;
        }
        cNetGameServer* v3_4 = static_cast<sNetworkExt*>(v0_4)->getGameServer();
        if (mType != 1) {
            if (v3_4->mApplyingFriendList.mLength != 0) {
                u32 v3_0 = mSortListCount;
                unsigned int i3_2 = 0;
                for (u32 v3_3 = v2_3;;) {
                    if (v3_0 >= v3_3) {
                        break;
                    } else {
                        v0_1[v3_0] = i3_2;
                        u32 t0 = mSortListCount;
                        mSortListCount = t0 + 1u;
                        if ((i3_2 + 1u) >= v3_4->mApplyingFriendList.mLength) {
                            break;
                        } else {
                            v3_0 = t0 + 1u;
                            i3_2 += 1u;
                            v3_3 = static_cast<sNetworkExt*>(v0_4)->getFriendListMax();
                        }
                    }
                }
            }
            if (v3_4->mApprovingFriendList.mLength != 0) {
                unsigned int i5_0 = 0;
                for (u32 v5_2 = mSortListCount;;) {
                    u32 t1 = static_cast<sNetworkExt*>(v0_4)->mFriendListMax;
                    if (v5_2 >= t1) {
                        break;
                    } else {
                        v0_1[v5_2] = i5_0;
                        u32 t2 = mSortListCount;
                        mSortListCount = t2 + 1u;
                        if ((i5_0 + 1u) < v3_4->mApprovingFriendList.mLength) {
                            i5_0 += 1u;
                            v5_2 = t2 + 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        if (v3_4->mFriendList.mLength != 0) {
            unsigned int i7_0 = 0;
            for (u32 v7_2 = mSortListCount;;) {
                u32 t3 = static_cast<sNetworkExt*>(v0_4)->mFriendListMax;
                if (v7_2 >= t3) {
                    break;
                } else {
                    v0_1[v7_2] = i7_0;
                    u32 t4 = mSortListCount;
                    mSortListCount = t4 + 1u;
                    if ((i7_0 + 1u) < v3_4->mFriendList.mLength) {
                        i7_0 += 1u;
                        v7_2 = t4 + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
        mMenuNum = 0;
        s32* v9_1 = mpMenuList;
        if (v9_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4) + 5788)) != 0) {
                unsigned int i9_0 = 0;
                for (unsigned int v9_2 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4) + 5788);;) {
                    int t5 = mMenuCursor[1];
                    u32 t6 = mSortListCount;
                    if ((i9_0 + (v9_2 * t5)) >= t6) {
                        break;
                    } else {
                        u32 t7 = mMenuNum;
                        mMenuNum = t7 + 1u;
                        v9_1[t7] = static_cast<s32>(i9_0);
                        if ((i9_0 + 1u) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4) + 5788))) {
                            i9_0 += 1u;
                            v9_2 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_4) + 5788);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        mIsRemakeList = true;
    }
}

inline cMenuFriendList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuFriendList::MyDTI cMenuFriendList::DTI("cMenuFriendList", &::cMenuBase::DTI, 224ul, 0u, 0u);

MtObject* cMenuFriendList::MyDTI::newInstance() const {
    return new (16u) cMenuFriendList;
}

const MtDTI& cMenuGetAreaMasterInfo::getDTI() const {
    return cMenuGetAreaMasterInfo::DTI;
}

inline cMenuGetAreaMasterInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetAreaMasterInfo::MyDTI cMenuGetAreaMasterInfo::DTI("cMenuGetAreaMasterInfo", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuGetAreaMasterInfo::MyDTI::newInstance() const {
    return new (16u) cMenuGetAreaMasterInfo;
}

const MtDTI& cMenuGetBlackList::getDTI() const {
    return cMenuGetBlackList::DTI;
}

inline cMenuGetBlackList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetBlackList::MyDTI cMenuGetBlackList::DTI("cMenuGetBlackList", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuGetBlackList::MyDTI::newInstance() const {
    return new (16u) cMenuGetBlackList;
}

const MtDTI& cMenuGetCharacterName::getDTI() const {
    return cMenuGetCharacterName::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuGetCharacterName::moveGetCharacterName() {
    DDON_STUB("cMenuGetCharacterName::moveGetCharacterName")
    return {};
}

inline cMenuGetCharacterName::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetCharacterName::MyDTI cMenuGetCharacterName::DTI("cMenuGetCharacterName", &::cMenuBase::DTI, 216ul, 0u, 0u);

MtObject* cMenuGetCharacterName::MyDTI::newInstance() const {
    return new (16u) cMenuGetCharacterName;
}

const MtDTI& cMenuGetCraftRecipeToServer::getDTI() const {
    return cMenuGetCraftRecipeToServer::DTI;
}

nMenu::MENU_RET cMenuGetCraftRecipeToServer::moveGetCraftRecipeToServer() {
    moveMenu();
    if (mMenuRno[0] == 1) {
        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[528] != sNetworkExt::NET_STAT_ERROR) {
            sCraftManager::cCraftRecipeControl* t0 = sCraftManager::getInstance()->getCraftRecipeCtrl(static_cast<sCraftManager::RECIPE_TYPE>(mType), static_cast<nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE>(mCategory));
            if (t0 != nullptr) {
                if (t0->getLoadStatus() != sCraftManager::cCraftRecipeControl::RECIPE_STATE_END) {
                    if (t0->getLoadStatus() == sCraftManager::cCraftRecipeControl::RECIPE_STATE_LOAD_END) {
                        mMenuRno[0] = 0;
                    }
                    return nMenu::MENU_RET_CONTINUE;
                } else {
                    sCraftManager::RECIPE_REQ_STATE t2 = sCraftManager::getInstance()->reqCraftRecipeDesignate(static_cast<sCraftManager::RECIPE_TYPE>(mType), static_cast<nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE>(mCategory));
                    if (t2 != sCraftManager::RECIPE_REQ_STATE_END) {
                        if (t2 != sCraftManager::RECIPE_REQ_STATE_ERROR) {
                            if (t2 == sCraftManager::RECIPE_REQ_STATE_SUCCESS) {
                                sCraftManager::cCraftRecipeControl* t3 = sCraftManager::getInstance()->getCraftRecipeCtrl(static_cast<sCraftManager::RECIPE_TYPE>(mType), static_cast<nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE>(mCategory));
                                if (t3 != nullptr) {
                                    t3->mState = sCraftManager::cCraftRecipeControl::RECIPE_STATE_LOADING;
                                    mMenuRno[0] = 1;
                                    return nMenu::MENU_RET_CONTINUE;
                                } else {
                                    return nMenu::MENU_RET_FAILED;
                                }
                            } else {
                                return nMenu::MENU_RET_CONTINUE;
                            }
                        } else {
                            return nMenu::MENU_RET_FAILED;
                        }
                    } else {
                        if (!mIsEnd) {
                            mIsEnd = true;
                            return nMenu::MENU_RET_SUCCESS;
                        } else {
                            return nMenu::MENU_RET_EXIT;
                        }
                    }
                }
            } else {
                return nMenu::MENU_RET_FAILED;
            }
        } else {
            return nMenu::MENU_RET_FAILED;
        }
    } else {
        if (mMenuRno[0] == 0) {
            sCraftManager::RECIPE_REQ_STATE t1 = sCraftManager::getInstance()->reqCraftRecipe(static_cast<sCraftManager::RECIPE_TYPE>(mType), static_cast<nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE>(mCategory));
            if (t1 == sCraftManager::RECIPE_REQ_STATE_END) {
                sCraftManager::RECIPE_REQ_STATE t2 = sCraftManager::getInstance()->reqCraftRecipeDesignate(static_cast<sCraftManager::RECIPE_TYPE>(mType), static_cast<nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE>(mCategory));
                if (t2 != sCraftManager::RECIPE_REQ_STATE_END) {
                    if (t2 != sCraftManager::RECIPE_REQ_STATE_ERROR) {
                        if (t2 == sCraftManager::RECIPE_REQ_STATE_SUCCESS) {
                            sCraftManager::cCraftRecipeControl* t3 = sCraftManager::getInstance()->getCraftRecipeCtrl(static_cast<sCraftManager::RECIPE_TYPE>(mType), static_cast<nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE>(mCategory));
                            if (t3 != nullptr) {
                                t3->mState = sCraftManager::cCraftRecipeControl::RECIPE_STATE_LOADING;
                                mMenuRno[0] = 1;
                                return nMenu::MENU_RET_CONTINUE;
                            } else {
                                return nMenu::MENU_RET_FAILED;
                            }
                        } else {
                            return nMenu::MENU_RET_CONTINUE;
                        }
                    } else {
                        return nMenu::MENU_RET_FAILED;
                    }
                } else {
                    if (!mIsEnd) {
                        mIsEnd = true;
                        return nMenu::MENU_RET_SUCCESS;
                    } else {
                        return nMenu::MENU_RET_EXIT;
                    }
                }
            } else {
                if (t1 != sCraftManager::RECIPE_REQ_STATE_ERROR) {
                    if (t1 == sCraftManager::RECIPE_REQ_STATE_SUCCESS) {
                        sCraftManager::cCraftRecipeControl* t3 = sCraftManager::getInstance()->getCraftRecipeCtrl(static_cast<sCraftManager::RECIPE_TYPE>(mType), static_cast<nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE>(mCategory));
                        if (t3 != nullptr) {
                            t3->mState = sCraftManager::cCraftRecipeControl::RECIPE_STATE_LOADING;
                            mMenuRno[0] = 1;
                            return nMenu::MENU_RET_CONTINUE;
                        } else {
                            return nMenu::MENU_RET_FAILED;
                        }
                    } else {
                        return nMenu::MENU_RET_CONTINUE;
                    }
                } else {
                    return nMenu::MENU_RET_FAILED;
                }
            }
        } else {
            return nMenu::MENU_RET_CONTINUE;
        }
    }
}

void cMenuGetCraftRecipeToServer::setRecipeType(sCraftManager::RECIPE_TYPE type, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category) {
    mMenuRno[0] = 0;
    mType = static_cast<u32>(type);
    mCategory = static_cast<u32>(category);
    mIsEnd = false;
}

inline cMenuGetCraftRecipeToServer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetCraftRecipeToServer::MyDTI cMenuGetCraftRecipeToServer::DTI("cMenuGetCraftRecipeToServer", &::cMenuBase::DTI, 288ul, 0u, 0u);

MtObject* cMenuGetCraftRecipeToServer::MyDTI::newInstance() const {
    return new (16u) cMenuGetCraftRecipeToServer;
}

const MtDTI& cMenuGetFriendList::getDTI() const {
    return cMenuGetFriendList::DTI;
}

inline cMenuGetFriendList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetFriendList::MyDTI cMenuGetFriendList::DTI("cMenuGetFriendList", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuGetFriendList::MyDTI::newInstance() const {
    return new (16u) cMenuGetFriendList;
}

const MtDTI& cMenuGetItemBaggageListToServer::getDTI() const {
    return cMenuGetItemBaggageListToServer::DTI;
}

cMenuGetItemBaggageListToServer::~cMenuGetItemBaggageListToServer() {
    if (mStorageList.mLength != 0) {
        u32 v0_0 = mStorageList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mStorageList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mStorageList.mpArray[i0_3];
                v1_0 = mStorageList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mStorageList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mStorageList.mpArray));
    }
    mStorageList.mpArray = nullptr;
    mStorageList.mBufsiz = 0;
    mStorageList.mLength = 0;
}

__attribute__((weak)) void cMenuGetItemBaggageListToServer::initGetItemBaggageListToServer(sItemManager::STORAGE_FILLTER_TYPE type) {
    DDON_STUB("cMenuGetItemBaggageListToServer::initGetItemBaggageListToServer")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuGetItemBaggageListToServer::moveGetItemBaggageListToServer() {
    DDON_STUB("cMenuGetItemBaggageListToServer::moveGetItemBaggageListToServer")
    return {};
}

void cMenuGetItemBaggageListToServer::itemListGetCallBack(void* param) {
    if (static_cast<int>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(param) + 136)) > -1) {
        mServerResult = 2;
        sItemManager::cItemBag* v0_10 = sItemManager::getInstance()->setLinkItem(static_cast<nCharacterData::ITEM_BAG_TYPE>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(param) + 48)));
        if (v0_10 != nullptr) {
            if (v0_10->getItemBagNum() != 0) {
                for (unsigned int i0_3 = 0;;) {
                    v0_10->getItemParam(i0_3);
                    if ((i0_3 + 1u) < v0_10->getItemBagNum()) {
                        i0_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    } else {
        mServerResult = 3;
    }
}

inline cMenuGetItemBaggageListToServer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetItemBaggageListToServer::MyDTI cMenuGetItemBaggageListToServer::DTI("cMenuGetItemBaggageListToServer", &::cMenuBase::DTI, 224ul, 0u, 0u);

MtObject* cMenuGetItemBaggageListToServer::MyDTI::newInstance() const {
    return new (16u) cMenuGetItemBaggageListToServer;
}

const MtDTI& cMenuGetItemListToServer::getDTI() const {
    return cMenuGetItemListToServer::DTI;
}

cMenuGetItemListToServer::~cMenuGetItemListToServer() {
    if (mStorageList.mLength != 0) {
        u32 v0_0 = mStorageList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mStorageList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mStorageList.mpArray[i0_3];
                v1_0 = mStorageList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mStorageList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mStorageList.mpArray));
    }
    mStorageList.mpArray = nullptr;
    mStorageList.mBufsiz = 0;
    mStorageList.mLength = 0;
}

__attribute__((weak)) void cMenuGetItemListToServer::initGetItemListToServer() {
    DDON_STUB("cMenuGetItemListToServer::initGetItemListToServer")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuGetItemListToServer::moveGetItemListToServer() {
    DDON_STUB("cMenuGetItemListToServer::moveGetItemListToServer")
    return {};
}

void cMenuGetItemListToServer::itemListGetCallBack(void* param) {
    if (static_cast<int>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(param) + 136)) > -1) {
        mServerResult = 2;
        sItemManager::cItemBag* v0_10 = sItemManager::getInstance()->setLinkItem(static_cast<nCharacterData::ITEM_BAG_TYPE>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(param) + 48)));
        if (v0_10 != nullptr) {
            if (v0_10->getItemBagNum() != 0) {
                for (unsigned int i0_3 = 0;;) {
                    v0_10->getItemParam(i0_3);
                    if ((i0_3 + 1u) < v0_10->getItemBagNum()) {
                        i0_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    } else {
        mServerResult = 3;
    }
}

inline cMenuGetItemListToServer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetItemListToServer::MyDTI cMenuGetItemListToServer::DTI("cMenuGetItemListToServer", &::cMenuBase::DTI, 224ul, 0u, 0u);

MtObject* cMenuGetItemListToServer::MyDTI::newInstance() const {
    return new (16u) cMenuGetItemListToServer;
}

const MtDTI& cMenuGetMailList::getDTI() const {
    return cMenuGetMailList::DTI;
}

void cMenuGetMailList::initGetMailList(bool newMailOnly) {
    initMenu();
    mMenuCursor[0] = 0;
    mMenuRno[0] = 0;
    mSystemMailFlag = false;
    mNewMailOnly = newMailOnly;
}

__attribute__((weak)) nMenu::MENU_RET cMenuGetMailList::moveGetMailList() {
    DDON_STUB("cMenuGetMailList::moveGetMailList")
    return {};
}

inline cMenuGetMailList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetMailList::MyDTI cMenuGetMailList::DTI("cMenuGetMailList", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuGetMailList::MyDTI::newInstance() const {
    return new (16u) cMenuGetMailList;
}

const MtDTI& cMenuGetMatchingProfile::getDTI() const {
    return cMenuGetMatchingProfile::DTI;
}

void cMenuGetMatchingProfile::exitMenu() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearGetMatchingProfilePacket();
    this->cMenuBase::exitMenu();
}

inline cMenuGetMatchingProfile::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetMatchingProfile::MyDTI cMenuGetMatchingProfile::DTI("cMenuGetMatchingProfile", &::cMenuBase::DTI, 208ul, 0u, 0u);

MtObject* cMenuGetMatchingProfile::MyDTI::newInstance() const {
    return new (16u) cMenuGetMatchingProfile;
}

const MtDTI& cMenuGetOrbGainExtendParam::getDTI() const {
    return cMenuGetOrbGainExtendParam::DTI;
}

void cMenuGetOrbGainExtendParam::initGetOrbGainExtendParam() {
    initMenu();
    mMenuRno[0] = 0;
}

__attribute__((weak)) nMenu::MENU_RET cMenuGetOrbGainExtendParam::moveGetOrbGainExtendParam() {
    DDON_STUB("cMenuGetOrbGainExtendParam::moveGetOrbGainExtendParam")
    return {};
}

inline cMenuGetOrbGainExtendParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetOrbGainExtendParam::MyDTI cMenuGetOrbGainExtendParam::DTI("cMenuGetOrbGainExtendParam", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuGetOrbGainExtendParam::MyDTI::newInstance() const {
    return new (16u) cMenuGetOrbGainExtendParam;
}

const MtDTI& cMenuGetPawnName::getDTI() const {
    return cMenuGetPawnName::DTI;
}

inline cMenuGetPawnName::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetPawnName::MyDTI cMenuGetPawnName::DTI("cMenuGetPawnName", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuGetPawnName::MyDTI::newInstance() const {
    return new (16u) cMenuGetPawnName;
}

const MtDTI& cMenuGetRecentList::getDTI() const {
    return cMenuGetRecentList::DTI;
}

inline cMenuGetRecentList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGetRecentList::MyDTI cMenuGetRecentList::DTI("cMenuGetRecentList", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuGetRecentList::MyDTI::newInstance() const {
    return new (16u) cMenuGetRecentList;
}

const MtDTI& cMenuGroupChatMemberList::getDTI() const {
    return cMenuGroupChatMemberList::DTI;
}

__attribute__((weak)) void cMenuGroupChatMemberList::initGroupChatMemberList() {
    DDON_STUB("cMenuGroupChatMemberList::initGroupChatMemberList")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuGroupChatMemberList::moveGroupChatMemberList() {
    DDON_STUB("cMenuGroupChatMemberList::moveGroupChatMemberList")
    return {};
}

__attribute__((weak)) void cMenuGroupChatMemberList::updatePtr() {
    DDON_STUB("cMenuGroupChatMemberList::updatePtr")
    /* stub */
}

void cMenuGroupChatMemberList::exitMenu() {
    MtMemoryAllocator::getAllocator(cMenuGroupChatMemberList::DTI)->memFree(static_cast<void*>(mpSortList));
    mpSortList = nullptr;
    if (mpGUIActiveList != nullptr) {
        mpGUIActiveList->kill();
        mpGUIActiveList = nullptr;
    }
    if (mMemberList.mLength != 0) {
        u32 v0_0 = mMemberList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMemberList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMemberList.mpArray[i0_3];
                v1_0 = mMemberList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMemberList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMemberList.mpArray));
    }
    mMemberList.mpArray = nullptr;
    mMemberList.mBufsiz = 0;
    mMemberList.mLength = 0;
    if (mExcludeList.mLength != 0) {
        u32 v3_0 = mExcludeList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mExcludeList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mExcludeList.mpArray[i3_3];
                v4_0 = mExcludeList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mExcludeList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mExcludeList.mpArray));
    }
    mExcludeList.mpArray = nullptr;
    mExcludeList.mBufsiz = 0;
    mExcludeList.mLength = 0;
    this->cMenuBase::exitMenu();
}

void cMenuGroupChatMemberList::setPage(s32 page) {
    if (static_cast<unsigned int>(page) < (((mSortListCount + 14u) <= 14u) ? 1ul : ((static_cast<unsigned long>(mSortListCount + 14u) * 0x88888889ul) >> 35))) {
        mMenuCursor[1] = page;
        mMenuNum = 0;
        u32 v0_0 = mSortListCount;
        unsigned int i0_1 = 0;
        for (s32 v0_3 = page;;) {
            if ((i0_1 + (v0_3 * 15)) >= v0_0) {
                break;
            } else {
                u32 t0 = mMenuNum;
                mMenuNum = t0 + 1u;
                mMenuList[t0] = static_cast<int>(i0_1);
                if ((i0_1 + 1u) > 14u) {
                    break;
                } else {
                    v0_0 = mSortListCount;
                    i0_1 += 1u;
                    v0_3 = mMenuCursor[1];
                }
            }
        }
        u32 t1 = mMenuNum;
        mMenuNum = t1 + 1u;
        mMenuList[t1] = 15;
        u32 t2 = mMenuNum;
        mMenuNum = t2 + 1u;
        mMenuList[t2] = 16;
    }
}

u32 cMenuGroupChatMemberList::getPageNum() {
    return static_cast<u32>(((mSortListCount + 14u) <= 14u) ? 1ul : ((static_cast<unsigned long>(mSortListCount + 14u) * 0x88888889ul) >> 35));
}

u32 cMenuGroupChatMemberList::getListIndex(u32 page, u32 cursor) {
    return (page * 15u) + cursor;
}

__attribute__((weak)) u32 cMenuGroupChatMemberList::getPageMemberNum() {
    DDON_STUB("cMenuGroupChatMemberList::getPageMemberNum")
    return {};
}

void cMenuGroupChatMemberList::createSortList() {
    mSortListCount = 0;
    u32* v0_3 = mpSortList;
    if (v0_3 != nullptr) {
        sNetwork* v0_1 = sNetwork::getInstance();
        u32 v2_0;
        if (static_cast<sNetworkExt*>(v0_1)->mGroupChatMemberMax != 0) {
            unsigned int i0_2 = 0;
            u32 v1_0;
            for (;;) {
                v0_3[i0_2] = 0;
                v1_0 = static_cast<sNetworkExt*>(v0_1)->getGroupChatMemberMax();
                if ((i0_2 + 1u) < v1_0) {
                    i0_2 += 1u;
                } else {
                    break;
                }
            }
            v2_0 = v1_0;
        } else {
            v2_0 = 0;
        }
        if (mMemberList.mLength != 0) {
            u32 v3_0 = v2_0;
            unsigned int i3_2 = 0;
            for (u32 v3_3 = mSortListCount;;) {
                if (v3_3 >= v3_0) {
                    break;
                } else {
                    v0_3[v3_3] = i3_2;
                    u32 t0 = mSortListCount;
                    mSortListCount = t0 + 1u;
                    if ((i3_2 + 1u) >= mMemberList.mLength) {
                        break;
                    } else {
                        v3_0 = static_cast<sNetworkExt*>(v0_1)->getGroupChatMemberMax();
                        i3_2 += 1u;
                        v3_3 = t0 + 1u;
                    }
                }
            }
        }
        mMenuNum = 0;
        for (unsigned int i5_0 = 0; i5_0 <= 14u; i5_0 += 1u) {
            int t1 = mMenuCursor[1];
            u32 t2 = mSortListCount;
            if ((i5_0 + (t1 * 15)) >= t2) {
                break;
            } else {
                u32 t3 = mMenuNum;
                mMenuNum = t3 + 1u;
                mMenuList[t3] = static_cast<int>(i5_0);
            }
        }
        u32 t4 = mMenuNum;
        mMenuNum = t4 + 1u;
        mMenuList[t4] = 15;
        u32 t5 = mMenuNum;
        mMenuNum = t5 + 1u;
        mMenuList[t5] = 16;
        uGUIBase* t6 = mpGUIMenu;
        if (t6 != nullptr) {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t6) + 4224) = 0;
        }
    }
}

inline cMenuGroupChatMemberList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuGroupChatMemberList::MyDTI cMenuGroupChatMemberList::DTI("cMenuGroupChatMemberList", &::cMenuBase::DTI, 472ul, 0u, 0u);

MtObject* cMenuGroupChatMemberList::MyDTI::newInstance() const {
    return new (16u) cMenuGroupChatMemberList;
}

const MtDTI& cMenuInvite::getDTI() const {
    return cMenuInvite::DTI;
}

void cMenuInvite::initInviteCore(s32 inviteType, cPawnListParam* pPawnParam, CDataClientPartyListInfo* pPartyParam, u32 characterId, CHAR_NAME* pCharacterName) {
    initMenu();
    mMenuRno[0] = 0;
    mInviteType = inviteType;
    mpPawnParam = pPawnParam;
    mpPartyParam = pPartyParam;
    mCharacterId = characterId;
    mCharacterName.clearName();
    if (pCharacterName != nullptr) {
        mCharacterName.clearName();
        snprintf(&mCharacterName.mFirstName[0], 13ul, "%s", pCharacterName);
        snprintf(&mCharacterName.mLastName[0], 9ul, "%s", &pCharacterName->mLastName[0]);
    } else {
        if (mpPartyParam != nullptr) {
            snprintf(&mCharacterName.mFirstName[0], 13ul, "%s", mpPartyParam->m_LeaderBaseInfo.m_CharacterName.m_wstrFirstName.ptr());
            snprintf(&mCharacterName.mLastName[0], 9ul, "%s", mpPartyParam->m_LeaderBaseInfo.m_CharacterName.m_wstrLastName.ptr());
        }
    }
    setupDialogFlow(3u);
}

__attribute__((weak)) nMenu::MENU_RET cMenuInvite::moveInvite() {
    DDON_STUB("cMenuInvite::moveInvite")
    return {};
}

inline cMenuInvite::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuInvite::MyDTI cMenuInvite::DTI("cMenuInvite", &::cMenuBase::DTI, 224ul, 0u, 0u);

MtObject* cMenuInvite::MyDTI::newInstance() const {
    return new (16u) cMenuInvite;
}

const MtDTI& cMenuInviteGroupChat::getDTI() const {
    return cMenuInviteGroupChat::DTI;
}

cMenuInviteGroupChat::~cMenuInviteGroupChat() {
}

__attribute__((weak)) void cMenuInviteGroupChat::initInviteGroupChat(u32 charId, MtString& friendFirstName, MtString& friendLastName) {
    DDON_STUB("cMenuInviteGroupChat::initInviteGroupChat")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuInviteGroupChat::moveInviteGroupChat() {
    DDON_STUB("cMenuInviteGroupChat::moveInviteGroupChat")
    return {};
}

__attribute__((weak)) void cMenuInviteGroupChat::exitMenu() {
    DDON_STUB("cMenuInviteGroupChat::exitMenu")
    /* stub */
}

inline cMenuInviteGroupChat::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuInviteGroupChat::MyDTI cMenuInviteGroupChat::DTI("cMenuInviteGroupChat", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuInviteGroupChat::MyDTI::newInstance() const {
    return new (16u) cMenuInviteGroupChat;
}

const MtDTI& cMenuJoinGameSession::getDTI() const {
    return cMenuJoinGameSession::DTI;
}

void cMenuJoinGameSession::initJoinGameSession(u32 joinType) {
    initMenu();
    mMenuRno[0] = 0;
    mJoinGameSessionDialogHandle = 0xFFFFFFFF;
    mJoinType = joinType;
}

__attribute__((weak)) nMenu::MENU_RET cMenuJoinGameSession::moveJoinGameSession() {
    DDON_STUB("cMenuJoinGameSession::moveJoinGameSession")
    return {};
}

inline cMenuJoinGameSession::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuJoinGameSession::MyDTI cMenuJoinGameSession::DTI("cMenuJoinGameSession", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuJoinGameSession::MyDTI::newInstance() const {
    return new (16u) cMenuJoinGameSession;
}

const MtDTI& cMenuJoinPartyFlow::getDTI() const {
    return cMenuJoinPartyFlow::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuJoinPartyFlow::moveJoinPartyFlow() {
    DDON_STUB("cMenuJoinPartyFlow::moveJoinPartyFlow")
    return {};
}

void cMenuJoinPartyFlow::exitMenu() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->endReadyAction();
    this->cMenuBase::exitMenu();
}

inline cMenuJoinPartyFlow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuJoinPartyFlow::MyDTI cMenuJoinPartyFlow::DTI("cMenuJoinPartyFlow", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuJoinPartyFlow::MyDTI::newInstance() const {
    return new (16u) cMenuJoinPartyFlow;
}

const MtDTI& cMenuKeyConfig::getDTI() const {
    return cMenuKeyConfig::DTI;
}

cMenuKeyConfig::cMenuKeyConfig() {
    DDON_STUB("cMenuKeyConfig::cMenuKeyConfig")
    /* stub */
}

cMenuKeyConfig::~cMenuKeyConfig() {
    DDON_STUB("cMenuKeyConfig::~cMenuKeyConfig")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::init(nMenuKeyConfig::KeyCustomManagers* keyCustomManagers) {
    DDON_STUB("cMenuKeyConfig::init")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuKeyConfig::move() {
    DDON_STUB("cMenuKeyConfig::move")
    return {};
}

void cMenuKeyConfig::exitMenu() {
    sGame::getInstance()->offDisableActionPlayer();
    mKeyCustomManagers.release();
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) bool cMenuKeyConfig::showGUI(uGUIKeyConfig& guiKeyConfig) {
    DDON_STUB("cMenuKeyConfig::showGUI")
    return {};
}

void cMenuKeyConfig::onClose(uGUIKeyConfig& guiKeyConfig) {
    if (mKeyCustomManagers.isExistOverlap()) {
        if (mpDialogFlow != nullptr) {
            mpDialogFlow->initialize(2u);
            cMenuDialogFlow* const dialog_flow = mpDialogFlow;
            if (dialog_flow != nullptr) {
                MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 482u);
                MT_CTSTR t1 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 483u);
                dialog_flow->setDialog(nGUIExt::DIALOG_TYPE_ROW_BUTTON, t0, 1, t1, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 4u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                mMenuRno[0] = 5;
                guiKeyConfig.pauseInput(true);
            } else {
                mMenuRno[0] = 5;
                guiKeyConfig.pauseInput(true);
            }
        } else {
            mMenuRno[0] = 5;
            guiKeyConfig.pauseInput(true);
        }
    } else {
        finalCheckBeforeExit();
        guiKeyConfig.pauseInput(true);
    }
}

void cMenuKeyConfig::onInitialize(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex) {
    if (mpDialogFlow != nullptr) {
        mpDialogFlow->initialize(2u);
        cMenuDialogFlow* const dialog_flow = mpDialogFlow;
        if (dialog_flow != nullptr) {
            MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 490u);
            MT_CTSTR t1 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
            dialog_flow->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t0, 1, t1, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
            mMenuRno[0] = 4;
            guiKeyConfig.pauseInput(true);
        } else {
            mMenuRno[0] = 4;
            guiKeyConfig.pauseInput(true);
        }
    } else {
        mMenuRno[0] = 4;
        guiKeyConfig.pauseInput(true);
    }
}

void cMenuKeyConfig::onBlankAll(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex) {
    if (mpDialogFlow != nullptr) {
        mpDialogFlow->initialize(2u);
        cMenuDialogFlow* const dialog_flow = mpDialogFlow;
        if (dialog_flow != nullptr) {
            MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 500u);
            MT_CTSTR t1 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
            dialog_flow->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t0, 1, t1, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
            mMenuRno[0] = 8;
            guiKeyConfig.pauseInput(true);
        } else {
            mMenuRno[0] = 8;
            guiKeyConfig.pauseInput(true);
        }
    } else {
        mMenuRno[0] = 8;
        guiKeyConfig.pauseInput(true);
    }
}

__attribute__((weak)) void cMenuKeyConfig::onUndo(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex, u32 keyListIndex, nGUIKeyConfig::Key key) {
    DDON_STUB("cMenuKeyConfig::onUndo")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::onChangeCategory(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex) {
    DDON_STUB("cMenuKeyConfig::onChangeCategory")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::onChangeKey(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex, u32 keyListIndex, nGUIKeyConfig::Key key) {
    DDON_STUB("cMenuKeyConfig::onChangeKey")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::onChangeSortType(uGUIKeyConfig& guiKeyConfig, nGUIKeyConfig::SORT_TYPE sortType) {
    DDON_STUB("cMenuKeyConfig::onChangeSortType")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::onKeyListSubMenu(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex, u32 keyListIndex) {
    DDON_STUB("cMenuKeyConfig::onKeyListSubMenu")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::onCategoryListSubMenu(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex) {
    DDON_STUB("cMenuKeyConfig::onCategoryListSubMenu")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::initializeSetting(uGUIKeyConfig& guiKeyConfig) {
    DDON_STUB("cMenuKeyConfig::initializeSetting")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::applySetting(uGUIKeyConfig& guiKeyConfig) {
    DDON_STUB("cMenuKeyConfig::applySetting")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::copySetting(uGUIKeyConfig& guiKeyConfig) {
    DDON_STUB("cMenuKeyConfig::copySetting")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::setBlankAll(uGUIKeyConfig& guiKeyConfig) {
    DDON_STUB("cMenuKeyConfig::setBlankAll")
    /* stub */
}

__attribute__((weak)) void cMenuKeyConfig::finalCheckBeforeExit() {
    for (unsigned int i0_3 = 0; i0_3 <= 2u; i0_3 += 1u) {
        if (!mKeyCustomManagers.isExistOverlap(i0_3)) {
            if (mKeyCustomManagers.isExistChange(i0_3, true)) {
                if (mpDialogFlow != nullptr) {
                    mpDialogFlow->initialize(0u);
                    cMenuDialogFlow* t0 = mpDialogFlow;
                    if (t0 != nullptr) {
                        t0->setDialogNoCancel(nGUIExt::DIALOG_TYPE_NORMAL, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 497u), 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr));
                    }
                }
                mMenuRno[0] = 7;
                return;
            }
        }
    }
    mMenuRno[0] = 3;
}

inline cMenuKeyConfig::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuKeyConfig::MyDTI cMenuKeyConfig::DTI("cMenuKeyConfig", &::cMenuBase::DTI, 224ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuKeyConfig::MyDTI::newInstance() const {
    DDON_STUB("cMenuKeyConfig::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuKeyConfigCopyCategory::getDTI() const {
    return cMenuKeyConfigCopyCategory::DTI;
}

cMenuKeyConfigCopyCategory::cMenuKeyConfigCopyCategory() {
    mCategoryListIndex = 0;
    mSelectIndex = 0;
    mKeyCustomManagers = nullptr;
}

cMenuKeyConfigCopyCategory::~cMenuKeyConfigCopyCategory() {
}

__attribute__((weak)) void cMenuKeyConfigCopyCategory::initGUI(uGUIBase& parent) {
    DDON_STUB("cMenuKeyConfigCopyCategory::initGUI")
    /* stub */
}

inline cMenuKeyConfigCopyCategory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuKeyConfigCopyCategory::MyDTI cMenuKeyConfigCopyCategory::DTI("cMenuKeyConfigCopyCategory", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuKeyConfigCopyCategory::MyDTI::newInstance() const {
    return new (16u) cMenuKeyConfigCopyCategory;
}

const MtDTI& cMenuKeyConfigRenameCategory::getDTI() const {
    return cMenuKeyConfigRenameCategory::DTI;
}

cMenuKeyConfigRenameCategory::cMenuKeyConfigRenameCategory() {
    DDON_STUB("cMenuKeyConfigRenameCategory::cMenuKeyConfigRenameCategory")
    /* stub */
}

cMenuKeyConfigRenameCategory::~cMenuKeyConfigRenameCategory() {
}

__attribute__((weak)) nMenu::MENU_RET cMenuKeyConfigRenameCategory::move() {
    DDON_STUB("cMenuKeyConfigRenameCategory::move")
    return {};
}

__attribute__((weak)) void cMenuKeyConfigRenameCategory::initGUI(uGUIBase& parent) {
    DDON_STUB("cMenuKeyConfigRenameCategory::initGUI")
    /* stub */
}

inline cMenuKeyConfigRenameCategory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuKeyConfigRenameCategory::MyDTI cMenuKeyConfigRenameCategory::DTI("cMenuKeyConfigRenameCategory", &::cMenuBase::DTI, 232ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuKeyConfigRenameCategory::MyDTI::newInstance() const {
    DDON_STUB("cMenuKeyConfigRenameCategory::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuKeyConfigSubMenu::getDTI() const {
    return cMenuKeyConfigSubMenu::DTI;
}

cMenuKeyConfigSubMenu::~cMenuKeyConfigSubMenu() {
}

inline cMenuKeyConfigSubMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuKeyConfigSubMenu::MyDTI cMenuKeyConfigSubMenu::DTI("cMenuKeyConfigSubMenu", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuKeyConfigSubMenu::MyDTI::newInstance() const {
    return new (16u) cMenuKeyConfigSubMenu;
}

const MtDTI& cMenuKeyConfigSubMenuCategoryList::getDTI() const {
    return cMenuKeyConfigSubMenuCategoryList::DTI;
}

cMenuKeyConfigSubMenuCategoryList::cMenuKeyConfigSubMenuCategoryList() {
    mItemIndex = ITEM_INVALID;
}

cMenuKeyConfigSubMenuCategoryList::~cMenuKeyConfigSubMenuCategoryList() {
}

void cMenuKeyConfigSubMenuCategoryList::onShow(uGUIPopCmd01& subMenu) {
    subMenu.addItemSystemMenu(57u, uGUIPopBase::MODE_DEFAULT, -1);
    subMenu.addItemSystemMenu(58u, uGUIPopBase::MODE_DEFAULT, -1);
}

void cMenuKeyConfigSubMenuCategoryList::onDecide(uGUIPopCmd01& subMenu) {
    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&subMenu) + 3216)) != 0) {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&subMenu) + 3216)) + 3096)) <= 1u) {
            mItemIndex = static_cast<ITEM_INDEX>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&subMenu) + 3216)) + 3096));
        }
    } else {
        mItemIndex = ITEM_RENAME;
    }
}

inline cMenuKeyConfigSubMenuCategoryList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuKeyConfigSubMenuCategoryList::MyDTI cMenuKeyConfigSubMenuCategoryList::DTI("cMenuKeyConfigSubMenuCategoryList", &::cMenuKeyConfigSubMenu::DTI, 184ul, 0u, 0u);

MtObject* cMenuKeyConfigSubMenuCategoryList::MyDTI::newInstance() const {
    return new (16u) cMenuKeyConfigSubMenuCategoryList;
}

const MtDTI& cMenuKeyConfigSubMenuKeyList::getDTI() const {
    return cMenuKeyConfigSubMenuKeyList::DTI;
}

cMenuKeyConfigSubMenuKeyList::cMenuKeyConfigSubMenuKeyList() {
    mIsChangeAllowed = false;
    mIsBlankAllowed = false;
    mItemIndex = ITEM_INVALID;
}

cMenuKeyConfigSubMenuKeyList::~cMenuKeyConfigSubMenuKeyList() {
}

void cMenuKeyConfigSubMenuKeyList::onShow(uGUIPopCmd01& subMenu) {
    if (mIsChangeAllowed) {
        subMenu.addItemSystemMenu(59u, static_cast<uGUIPopBase::MODE>(!mIsBlankAllowed), 484);
        subMenu.addItemSystemMenu(60u, uGUIPopBase::MODE_DEFAULT, -1);
        subMenu.addItemSystemMenu(61u, uGUIPopBase::MODE_DEFAULT, -1);
    } else {
        subMenu.addItemSystemMenu(59u, uGUIPopBase::MODE_DISABLE, 501);
        subMenu.addItemSystemMenu(60u, uGUIPopBase::MODE_DISABLE, 501);
        subMenu.addItemSystemMenu(61u, uGUIPopBase::MODE_DISABLE, 501);
    }
}

void cMenuKeyConfigSubMenuKeyList::onDecide(uGUIPopCmd01& subMenu) {
    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&subMenu) + 3216)) != 0) {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&subMenu) + 3216)) + 3096)) <= 2u) {
            mItemIndex = static_cast<ITEM_INDEX>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&subMenu) + 3216)) + 3096));
        }
    } else {
        mItemIndex = ITEM_BLANK;
    }
}

inline cMenuKeyConfigSubMenuKeyList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuKeyConfigSubMenuKeyList::MyDTI cMenuKeyConfigSubMenuKeyList::DTI("cMenuKeyConfigSubMenuKeyList", &::cMenuKeyConfigSubMenu::DTI, 184ul, 0u, 0u);

MtObject* cMenuKeyConfigSubMenuKeyList::MyDTI::newInstance() const {
    return new (16u) cMenuKeyConfigSubMenuKeyList;
}

const MtDTI& cMenuKeyJobLink::getDTI() const {
    return cMenuKeyJobLink::DTI;
}

cMenuKeyJobLink::cMenuKeyJobLink() {
    DDON_STUB("cMenuKeyJobLink::cMenuKeyJobLink")
    /* stub */
}

__attribute__((noinline)) cMenuKeyJobLink::~cMenuKeyJobLink() {
    DDON_STUB("cMenuKeyJobLink::~cMenuKeyJobLink")
    /* stub */
}

__attribute__((weak)) void cMenuKeyJobLink::init(MT_CTSTR windowTitle, MT_CTSTR decideButtonTitle, MT_CTSTR pulldownNameFormat, u8(*keyJobLinks)[10], const nMenuKeyConfig::KeyCustomManagers* keyCustomManagers) {
    DDON_STUB("cMenuKeyJobLink::init")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuKeyJobLink::move() {
    DDON_STUB("cMenuKeyJobLink::move")
    return {};
}

__attribute__((weak)) void cMenuKeyJobLink::exitMenu() {
    DDON_STUB("cMenuKeyJobLink::exitMenu")
    /* stub */
}

__attribute__((weak)) void cMenuKeyJobLink::initGUI() {
    DDON_STUB("cMenuKeyJobLink::initGUI")
    /* stub */
}

__attribute__((weak)) bool cMenuKeyJobLink::waitGUI(uGUIPopFilter& guiPopFilter) {
    DDON_STUB("cMenuKeyJobLink::waitGUI")
    return {};
}

inline cMenuKeyJobLink::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuKeyJobLink::MyDTI cMenuKeyJobLink::DTI("cMenuKeyJobLink", &::cMenuBase::DTI, 296ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuKeyJobLink::MyDTI::newInstance() const {
    DDON_STUB("cMenuKeyJobLink::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuKickGroupChat::getDTI() const {
    return cMenuKickGroupChat::DTI;
}

cMenuKickGroupChat::~cMenuKickGroupChat() {
}

__attribute__((weak)) void cMenuKickGroupChat::initKickGroupChat(u32 charId, MtString& friendFirstName, MtString& friendLastName) {
    DDON_STUB("cMenuKickGroupChat::initKickGroupChat")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuKickGroupChat::moveKickGroupChat() {
    DDON_STUB("cMenuKickGroupChat::moveKickGroupChat")
    return {};
}

__attribute__((weak)) void cMenuKickGroupChat::exitMenu() {
    DDON_STUB("cMenuKickGroupChat::exitMenu")
    /* stub */
}

inline cMenuKickGroupChat::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuKickGroupChat::MyDTI cMenuKickGroupChat::DTI("cMenuKickGroupChat", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuKickGroupChat::MyDTI::newInstance() const {
    return new (16u) cMenuKickGroupChat;
}

const MtDTI& cMenuLeaveGroupChat::getDTI() const {
    return cMenuLeaveGroupChat::DTI;
}

nMenu::MENU_RET cMenuLeaveGroupChat::moveLeaveGroupChat() {
    moveMenu();
    switch (mMenuRno[0]) {
        case 0:
        {
            mMenuRno[0] = 1;
            MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 118u);
            MT_CTSTR t1 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
            MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u);
            if (mpGUISystemMsg != nullptr) {
                mpGUISystemMsg->kill();
                mpGUISystemMsg = nullptr;
                uGUISystemMsg* t4 = cGUIUtility::reqDialog(nGUIExt::DIALOG_TYPE_NORMAL, t0, 1, t1, t2, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<sGUIExt*>(sGUI::getInstance())->isChatMenuUISubMenu());
                if ((mpGUISystemMsg = t4) != nullptr) {
                    t4->mBasePointerPrio = getNextBasePointerPrio();
                    return nMenu::MENU_RET_CONTINUE;
                } else {
                    return nMenu::MENU_RET_CONTINUE;
                }
            } else {
                uGUISystemMsg* t4 = cGUIUtility::reqDialog(nGUIExt::DIALOG_TYPE_NORMAL, t0, 1, t1, t2, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<sGUIExt*>(sGUI::getInstance())->isChatMenuUISubMenu());
                if ((mpGUISystemMsg = t4) != nullptr) {
                    t4->mBasePointerPrio = getNextBasePointerPrio();
                    return nMenu::MENU_RET_CONTINUE;
                } else {
                    return nMenu::MENU_RET_CONTINUE;
                }
            }
            break;
        }
        case 1:
        {
            if (mpGUISystemMsg != nullptr) {
                if (mpGUISystemMsg->mResult == uGUIBase::RESULT_EXIT) {
                    s32 choice = mpGUISystemMsg->getChoicePos(-1);
                    if (mpGUISystemMsg != nullptr) {
                        mpGUISystemMsg->kill();
                        mpGUISystemMsg = nullptr;
                        if (choice == 0) {
                            mMenuRno[0] = 2;
                            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->leaveGroupChat();
                            return nMenu::MENU_RET_CONTINUE;
                        } else {
                            return nMenu::MENU_RET_CANCEL;
                        }
                    } else {
                        if (choice == 0) {
                            mMenuRno[0] = 2;
                            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->leaveGroupChat();
                            return nMenu::MENU_RET_CONTINUE;
                        } else {
                            return nMenu::MENU_RET_CANCEL;
                        }
                    }
                } else {
                    return nMenu::MENU_RET_CONTINUE;
                }
            } else {
                return nMenu::MENU_RET_CANCEL;
            }
            break;
        }
        case 2:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[444] == sNetworkExt::NET_STAT_ERROR) {
                mMenuRno[0] = 3;
                return nMenu::MENU_RET_CONTINUE;
            } else {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[444] == sNetworkExt::NET_STAT_SUCCESS) {
                    mMenuRno[0] = 4;
                    MT_CTSTR t3 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 119u);
                    if (mpGUISystemMsg != nullptr) {
                        mpGUISystemMsg->kill();
                        mpGUISystemMsg = nullptr;
                        uGUISystemMsg* t4 = cGUIUtility::reqDialog(nGUIExt::DIALOG_TYPE_NORMAL, t3, 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<sGUIExt*>(sGUI::getInstance())->isChatMenuUISubMenu());
                        if ((mpGUISystemMsg = t4) != nullptr) {
                            t4->mBasePointerPrio = getNextBasePointerPrio();
                            return nMenu::MENU_RET_CONTINUE;
                        } else {
                            return nMenu::MENU_RET_CONTINUE;
                        }
                    } else {
                        uGUISystemMsg* t4 = cGUIUtility::reqDialog(nGUIExt::DIALOG_TYPE_NORMAL, t3, 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<sGUIExt*>(sGUI::getInstance())->isChatMenuUISubMenu());
                        if ((mpGUISystemMsg = t4) != nullptr) {
                            t4->mBasePointerPrio = getNextBasePointerPrio();
                            return nMenu::MENU_RET_CONTINUE;
                        } else {
                            return nMenu::MENU_RET_CONTINUE;
                        }
                    }
                } else {
                    return nMenu::MENU_RET_CONTINUE;
                }
            }
            break;
        }
        case 3:
        {
            if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->isDispErrorDialog()) {
                return nMenu::MENU_RET_CANCEL;
            } else {
                return nMenu::MENU_RET_CONTINUE;
            }
            break;
        }
        case 4:
        {
            if (mpGUISystemMsg != nullptr) {
                if (mpGUISystemMsg->mResult == uGUIBase::RESULT_EXIT) {
                    mpGUISystemMsg->kill();
                    mpGUISystemMsg = nullptr;
                    return nMenu::MENU_RET_EXIT;
                } else {
                    return nMenu::MENU_RET_CONTINUE;
                }
            } else {
                return nMenu::MENU_RET_EXIT;
            }
            break;
        }
        default:
        {
            return nMenu::MENU_RET_CONTINUE;
        }
    }
}

void cMenuLeaveGroupChat::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuLeaveGroupChat::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuLeaveGroupChat::MyDTI cMenuLeaveGroupChat::DTI("cMenuLeaveGroupChat", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuLeaveGroupChat::MyDTI::newInstance() const {
    return new (16u) cMenuLeaveGroupChat;
}

const MtDTI& cMenuLeaveOnTheWay::getDTI() const {
    return cMenuLeaveOnTheWay::DTI;
}

void cMenuLeaveOnTheWay::initLeaveOnTheWay() {
    initMenu();
    mMenuRno[0] = 0;
}

__attribute__((weak)) nMenu::MENU_RET cMenuLeaveOnTheWay::moveLeaveOnTheWay() {
    DDON_STUB("cMenuLeaveOnTheWay::moveLeaveOnTheWay")
    return {};
}

void cMenuLeaveOnTheWay::exitMenu() {
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) void cMenuLeaveOnTheWay::createSelectDialog(u32 type) {
    DDON_STUB("cMenuLeaveOnTheWay::createSelectDialog")
    /* stub */
}

inline cMenuLeaveOnTheWay::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuLeaveOnTheWay::MyDTI cMenuLeaveOnTheWay::DTI("cMenuLeaveOnTheWay", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuLeaveOnTheWay::MyDTI::newInstance() const {
    return new (16u) cMenuLeaveOnTheWay;
}

const MtDTI& cMenuLostPawnList::getDTI() const {
    return cMenuLostPawnList::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuLostPawnList::moveLostPawnList() {
    DDON_STUB("cMenuLostPawnList::moveLostPawnList")
    return {};
}

inline cMenuLostPawnList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuLostPawnList::MyDTI cMenuLostPawnList::DTI("cMenuLostPawnList", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuLostPawnList::MyDTI::newInstance() const {
    return new (16u) cMenuLostPawnList;
}

const MtDTI& cMenuLostPawnRevive::getDTI() const {
    return cMenuLostPawnRevive::DTI;
}

cMenuLostPawnRevive::~cMenuLostPawnRevive() {
}

void cMenuLostPawnRevive::initLostPawnRevive(u32 pawnId, MT_CTSTR pPawnName, u32 useRim) {
    initMenu();
    mMenuRno[0] = 0;
    mPawnId = pawnId;
    if (pPawnName != mPawnName.ptr()) {
        if (mPawnName.value != nullptr) {
            if (sceAtomicAdd32Relaxed(&mPawnName.value->ref, -1) == 1) {
                (MtString::mpAllocator)->memFree(static_cast<void*>(mPawnName.value));
            }
            mPawnName.value = nullptr;
        }
        if (pPawnName != nullptr) {
            size_t t0 = strlen(pPawnName);
            if (static_cast<unsigned int>(t0) != 0) {
                void* t1 = (MtString::mpAllocator)->memAlloc(static_cast<size_t>(static_cast<unsigned int>(t0)) + 12, 16u);
                mPawnName.value = static_cast<MtString::STRING*>(t1);
                mPawnName.value->ref = 1;
                mPawnName.value->length = static_cast<unsigned int>(t0);
                strcpy(reinterpret_cast<char*>(mPawnName.value->str), pPawnName);
                mUseRim = useRim;
                setupDialogFlow(3u);
            } else {
                mPawnName.value = nullptr;
                mUseRim = useRim;
                setupDialogFlow(3u);
            }
        } else {
            mPawnName.value = nullptr;
            mUseRim = useRim;
            setupDialogFlow(3u);
        }
    } else {
        mUseRim = useRim;
        setupDialogFlow(3u);
    }
}

nMenu::MENU_RET cMenuLostPawnRevive::moveLostPawnRevive() {
    moveMenu();
    cCursor cursor;
    if (mMenuRno[0] == 0) {
        if (mpDialogFlow != nullptr) {
            cMenuDialogFlow::RET t0 = mpDialogFlow->moveFlow();
            switch (t0) {
                case cMenuDialogFlow::RET_DLG_SET_DLG:
                {
                    cMenuDialogFlow* t1 = getDialogFlow();
                    MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 391u);
                    MT_CTSTR t3 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                    t1->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t2, 1, t3, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                    getDialogFlow()->setMsgAnalyzerWork(0u, static_cast<s32>(mUseRim));
                    getDialogFlow()->setMsgAnalyzerWork(1u, mPawnName.ptr());
                    break;
                }
                case cMenuDialogFlow::RET_DLG_CHOICE:
                {
                    if (getDialogFlow()->mChoice != 0) {
                        return nMenu::MENU_RET_CANCEL;
                    } else {
                        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->lostPawnWalletRevive(mPawnId, nCharacter::WALLET_POINT_TYPE_RIM, mUseRim);
                        getDialogFlow()->setComWait(80);
                    }
                    break;
                }
                case cMenuDialogFlow::RET_DLG_SET_RESULT:
                {
                    cMenuDialogFlow* t4 = getDialogFlow();
                    t4->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 393u), 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                    getDialogFlow()->setMsgAnalyzerWork(0u, mPawnName.ptr());
                    u32 v0_0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyPawnList.mLength;
                    if (v0_0 != 0) {
                        MtObject* * v0_1 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyPawnList.mpArray;
                        for (unsigned int i0_3 = 0;;) {
                            if (v0_1[static_cast<int>(i0_3)] != nullptr) {
                                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_3)]) + 8)) == mPawnId) {
                                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_3)]) + 25) = 0;
                                    break;
                                }
                            }
                            if ((i0_3 + 1u) < v0_0) {
                                i0_3 += 1u;
                            } else {
                                break;
                            }
                        }
                    }
                    break;
                }
                case cMenuDialogFlow::RET_DLG_EXIT:
                {
                    return nMenu::MENU_RET_EXIT;
                }
                case cMenuDialogFlow::RET_DLG_NULL:
                {
                    return nMenu::MENU_RET_CANCEL;
                }
                default:
                {
                    break;
                }
            }
        } else {
            return nMenu::MENU_RET_CANCEL;
        }
    }
    return nMenu::MENU_RET_CONTINUE;
}

__attribute__((weak)) void cMenuLostPawnRevive::exitMenu() {
    DDON_STUB("cMenuLostPawnRevive::exitMenu")
    /* stub */
}

inline cMenuLostPawnRevive::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuLostPawnRevive::MyDTI cMenuLostPawnRevive::DTI("cMenuLostPawnRevive", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuLostPawnRevive::MyDTI::newInstance() const {
    return new (16u) cMenuLostPawnRevive;
}

const MtDTI& cMenuMail::getDTI() const {
    return cMenuMail::DTI;
}

__attribute__((weak)) void cMenuMail::initMail() {
    DDON_STUB("cMenuMail::initMail")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuMail::moveMail() {
    DDON_STUB("cMenuMail::moveMail")
    return {};
}

__attribute__((weak)) void cMenuMail::createSortList() {
    DDON_STUB("cMenuMail::createSortList")
    /* stub */
}

__attribute__((weak)) CMailInfo* cMenuMail::getMailInfo(s32 tab, s32 cursor) {
    DDON_STUB("cMenuMail::getMailInfo")
    return nullptr;
}

u32 cMenuMail::getListCount(s32 tabType) {
    if (tabType != 2) {
        if (tabType == 1) {
            return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMailList.mLength;
        } else {
            if (tabType == 0) {
                return getSortListCount();
            } else {
                return 0;
            }
        }
    } else {
        return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mSysMailList.mLength;
    }
}

__attribute__((weak)) void cMenuMail::deleteCheck() {
    DDON_STUB("cMenuMail::deleteCheck")
    /* stub */
}

inline cMenuMail::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMail::MyDTI cMenuMail::DTI("cMenuMail", &::cMenuBase::DTI, 5016ul, 0u, 0u);

MtObject* cMenuMail::MyDTI::newInstance() const {
    return new (16u) cMenuMail;
}

const MtDTI& cMenuMailCreate::getDTI() const {
    return cMenuMailCreate::DTI;
}

cMenuMailCreate::~cMenuMailCreate() {
}

__attribute__((weak)) void cMenuMailCreate::exitMenu() {
    DDON_STUB("cMenuMailCreate::exitMenu")
    /* stub */
}

__attribute__((weak)) void cMenuMailCreate::initMailCreate(CCommunityCharacterBaseInfo* pCharacterInfo, u32 prio) {
    DDON_STUB("cMenuMailCreate::initMailCreate")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuMailCreate::moveMailCreate() {
    DDON_STUB("cMenuMailCreate::moveMailCreate")
    return {};
}

__attribute__((weak)) void cMenuMailCreate::addList(u32 characterId, CHAR_NAME& charName) {
    DDON_STUB("cMenuMailCreate::addList")
    /* stub */
}

__attribute__((weak)) void cMenuMailCreate::eraseList(u32 index) {
    DDON_STUB("cMenuMailCreate::eraseList")
    /* stub */
}

inline cMenuMailCreate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMailCreate::MyDTI cMenuMailCreate::DTI("cMenuMailCreate", &::cMenuBase::DTI, 320ul, 0u, 0u);

MtObject* cMenuMailCreate::MyDTI::newInstance() const {
    return new (16u) cMenuMailCreate;
}

const MtDTI& cMenuMailDelete::getDTI() const {
    return cMenuMailDelete::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuMailDelete::moveMailDelete() {
    DDON_STUB("cMenuMailDelete::moveMailDelete")
    return {};
}

inline cMenuMailDelete::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMailDelete::MyDTI cMenuMailDelete::DTI("cMenuMailDelete", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuMailDelete::MyDTI::newInstance() const {
    return new (16u) cMenuMailDelete;
}

const MtDTI& cMenuMailDeleteMulti::getDTI() const {
    return cMenuMailDeleteMulti::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuMailDeleteMulti::moveMailDeleteMulti() {
    DDON_STUB("cMenuMailDeleteMulti::moveMailDeleteMulti")
    return {};
}

inline cMenuMailDeleteMulti::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMailDeleteMulti::MyDTI cMenuMailDeleteMulti::DTI("cMenuMailDeleteMulti", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuMailDeleteMulti::MyDTI::newInstance() const {
    return new (16u) cMenuMailDeleteMulti;
}

const MtDTI& cMenuMailDetail::getDTI() const {
    return cMenuMailDetail::DTI;
}

__attribute__((weak)) void cMenuMailDetail::initMailDetail(CMailInfo& info, const MtVector4& setPos) {
    DDON_STUB("cMenuMailDetail::initMailDetail")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuMailDetail::moveMailDetail() {
    DDON_STUB("cMenuMailDetail::moveMailDetail")
    return {};
}

void cMenuMailDetail::exitMenu() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearMailDetail();
    this->cMenuBase::exitMenu();
}

inline cMenuMailDetail::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMailDetail::MyDTI cMenuMailDetail::DTI("cMenuMailDetail", &::cMenuBase::DTI, 224ul, 0u, 0u);

MtObject* cMenuMailDetail::MyDTI::newInstance() const {
    return new (16u) cMenuMailDetail;
}

const MtDTI& cMenuMailGetItem::getDTI() const {
    return cMenuMailGetItem::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuMailGetItem::moveMailGetItem() {
    DDON_STUB("cMenuMailGetItem::moveMailGetItem")
    return {};
}

void cMenuMailGetItem::exitMenu() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearGetAttachmentList();
    this->cMenuBase::exitMenu();
}

inline cMenuMailGetItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMailGetItem::MyDTI cMenuMailGetItem::DTI("cMenuMailGetItem", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuMailGetItem::MyDTI::newInstance() const {
    return new (16u) cMenuMailGetItem;
}

const MtDTI& cMenuMailGetItemAll::getDTI() const {
    return cMenuMailGetItemAll::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuMailGetItemAll::moveMailGetItemAll() {
    DDON_STUB("cMenuMailGetItemAll::moveMailGetItemAll")
    return {};
}

void cMenuMailGetItemAll::exitMenu() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearGetAttachmentList();
    this->cMenuBase::exitMenu();
}

inline cMenuMailGetItemAll::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMailGetItemAll::MyDTI cMenuMailGetItemAll::DTI("cMenuMailGetItemAll", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuMailGetItemAll::MyDTI::newInstance() const {
    return new (16u) cMenuMailGetItemAll;
}

const MtDTI& cMenuMailToList::getDTI() const {
    return cMenuMailToList::DTI;
}

void cMenuMailToList::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuMailToList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMailToList::MyDTI cMenuMailToList::DTI("cMenuMailToList", &::cMenuBase::DTI, 256ul, 0u, 0u);

MtObject* cMenuMailToList::MyDTI::newInstance() const {
    return new (16u) cMenuMailToList;
}

const MtDTI& cMenuMatchingProfile::getDTI() const {
    return cMenuMatchingProfile::DTI;
}

__attribute__((weak)) void cMenuMatchingProfile::initMatchingProfile(bool IsCardType, u32 PointerPrio) {
    DDON_STUB("cMenuMatchingProfile::initMatchingProfile")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuMatchingProfile::moveMatchingProfile() {
    DDON_STUB("cMenuMatchingProfile::moveMatchingProfile")
    return {};
}

void cMenuMatchingProfile::exitMenu() {
    if (mpGUIMenu != static_cast<sGUIExt*>(sGUI::getInstance())->mpSingletonMenu) {
        if (mpGUIMenu != nullptr) {
            mpGUIMenu->kill();
            mpGUIMenu = nullptr;
        }
    } else {
        static_cast<sGUIExt*>(sGUI::getInstance())->killSingletonMenu();
        mpGUIMenu = nullptr;
    }
    this->cMenuBase::exitMenu();
}

s32 cMenuMatchingProfile::getEntryJobList(s32 cursor) {
    if (cursor <= 9) {
        return mEntryJobList[cursor];
    } else {
        return 1;
    }
}

__attribute__((weak)) u32 cMenuMatchingProfile::getSettingMenuNum(s32 listType) {
    DDON_STUB("cMenuMatchingProfile::getSettingMenuNum")
    return {};
}

__attribute__((weak)) u32 cMenuMatchingProfile::getSettingListNum(s32 listType) {
    DDON_STUB("cMenuMatchingProfile::getSettingListNum")
    return {};
}

__attribute__((weak)) s32 cMenuMatchingProfile::getCursorPosFromParam(s32 listType, s32 param) {
    DDON_STUB("cMenuMatchingProfile::getCursorPosFromParam")
    return {};
}

__attribute__((weak)) s32 cMenuMatchingProfile::getCursorPosFromParam(s32 listType) {
    DDON_STUB("cMenuMatchingProfile::getCursorPosFromParam")
    return {};
}

inline cMenuMatchingProfile::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMatchingProfile::MyDTI cMenuMatchingProfile::DTI("cMenuMatchingProfile", &::cMenuBase::DTI, 488ul, 0u, 0u);

alignas(4) unsigned char cMenuMatchingProfile_purposeMainSetting_bytes[24] __asm__("_ZN20cMenuMatchingProfile18purposeMainSettingE") = {0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00};

alignas(4) unsigned char cMenuMatchingProfile_purposeSubSetting_bytes[48] __asm__("_ZN20cMenuMatchingProfile17purposeSubSettingE") = {0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00};

alignas(4) unsigned char cMenuMatchingProfile_playStyleSetting_bytes[112] __asm__("_ZN20cMenuMatchingProfile16playStyleSettingE") = {0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00};

MtObject* cMenuMatchingProfile::MyDTI::newInstance() const {
    return new (16u) cMenuMatchingProfile;
}

const MtDTI& cMenuMyPawnList::getDTI() const {
    return cMenuMyPawnList::DTI;
}

__attribute__((weak)) void cMenuMyPawnList::initMyPawnList(u32 attr, s32 cursorPos, u32 listType) {
    DDON_STUB("cMenuMyPawnList::initMyPawnList")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuMyPawnList::moveMyPawnList() {
    DDON_STUB("cMenuMyPawnList::moveMyPawnList")
    return {};
}

__attribute__((weak)) bool cMenuMyPawnList::moveMyPawnDetail() {
    DDON_STUB("cMenuMyPawnList::moveMyPawnDetail")
    return {};
}

__attribute__((weak)) void cMenuMyPawnList::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    DDON_STUB("cMenuMyPawnList::checkMenuPartsParam")
    /* stub */
}

inline cMenuMyPawnList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuMyPawnList::MyDTI cMenuMyPawnList::DTI("cMenuMyPawnList", &::cMenuBase::DTI, 272ul, 0u, 0u);

MtObject* cMenuMyPawnList::MyDTI::newInstance() const {
    return new (16u) cMenuMyPawnList;
}

const MtDTI& cMenuOnlineShop::getDTI() const {
    return cMenuOnlineShop::DTI;
}

__attribute__((weak)) void cMenuOnlineShop::initMenuOnlineShop(u32 moveline) {
    DDON_STUB("cMenuOnlineShop::initMenuOnlineShop")
    /* stub */
}

nMenu::MENU_RET cMenuOnlineShop::moveMenuOnlineShop() {
    moveMenu();
    cCursor cursor;
    if (mMenuRno[0] == 1) {
        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->isDispErrorDialog()) {
            return nMenu::MENU_RET_CONTINUE;
        } else {
            return nMenu::MENU_RET_FAILED;
        }
    } else {
        if (mMenuRno[0] == 0) {
            if (mpGUIMenu != nullptr) {
                if (mpGUIMenu->mResult == uGUIBase::RESULT_EXIT) {
                    return static_cast<nMenu::MENU_RET>(static_cast<unsigned long>(sItemManager::getInstance()->getGp() != 0) | 2);
                }
            }
        }
        return nMenu::MENU_RET_CONTINUE;
    }
}

inline cMenuOnlineShop::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuOnlineShop::MyDTI cMenuOnlineShop::DTI("cMenuOnlineShop", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuOnlineShop::MyDTI::newInstance() const {
    return new (16u) cMenuOnlineShop;
}

const MtDTI& cMenuPartyList::getDTI() const {
    return cMenuPartyList::DTI;
}

void cMenuPartyList::initPartyList(uGUIBase* pGUIRefMenu) {
    initMenu();
    mMenuRno[0] = 0;
    mSearchSetting.setDefaultData();
    mSearchSetting.initSearchFilter(0);
    cNetGameServer* v0_10 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer();
    if (v0_10->mPartyListInfoVec.mLength != 0) {
        u32 v0_0 = v0_10->mPartyListInfoVec.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (v0_10->mPartyListInfoVec.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete v0_10->mPartyListInfoVec.mpArray[i0_3];
                v1_0 = v0_10->mPartyListInfoVec.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (v0_10->mPartyListInfoVec.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(v0_10->mPartyListInfoVec.mpArray));
    }
    v0_10->mPartyListInfoVec.mpArray = nullptr;
    v0_10->mPartyListInfoVec.mBufsiz = 0;
    v0_10->mPartyListInfoVec.mLength = 0;
    mFirst = true;
    cMenuSupportList* t0 = setupSupportList(256u, 14u, 16u);
    if (t0 != nullptr) {
        t0->addBelowMenu(14);
        t0->addBelowMenu(15);
    }
    setRefGUI(pGUIRefMenu, true);
}

__attribute__((weak)) nMenu::MENU_RET cMenuPartyList::movePartyList() {
    DDON_STUB("cMenuPartyList::movePartyList")
    return {};
}

void cMenuPartyList::exitMenu() {
    cNetGameServer* v0_8 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer();
    if (v0_8->mPartyListInfoVec.mLength != 0) {
        u32 v0_0 = v0_8->mPartyListInfoVec.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (v0_8->mPartyListInfoVec.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete v0_8->mPartyListInfoVec.mpArray[i0_3];
                v1_0 = v0_8->mPartyListInfoVec.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (v0_8->mPartyListInfoVec.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(v0_8->mPartyListInfoVec.mpArray));
    }
    v0_8->mPartyListInfoVec.mpArray = nullptr;
    v0_8->mPartyListInfoVec.mBufsiz = 0;
    v0_8->mPartyListInfoVec.mLength = 0;
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) void cMenuPartyList::updatePtr() {
    DDON_STUB("cMenuPartyList::updatePtr")
    /* stub */
}

__attribute__((weak)) bool cMenuPartyList::isEnableSimplePartyReq() {
    DDON_STUB("cMenuPartyList::isEnableSimplePartyReq")
    return {};
}

void cMenuPartyList::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    if (menuId != 15) {
        return;
    }
    pParts->attr = 1;
    if (sQuestManagerExt::getInstance()->isEnableParty_Invite()) {
        if (sArea::getInstance()->mpArea[2] != nullptr) {
            if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(sArea::getInstance()->mpArea[2]) + 350)) == 0) {
                if (static_cast<sAreaExt*>(sArea::getInstance())->isLobby()) {
                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLeader()) {
                        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
                            pParts->param = 4;
                        } else {
                            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->getPartySpaceNum() > 0) {
                                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowQuickMatchFlow()) {
                                    pParts->param = 6;
                                } else {
                                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyInvited()) {
                                        pParts->param = 7;
                                    } else {
                                        pParts->attr = 0;
                                    }
                                }
                            } else {
                                pParts->param = 5;
                            }
                        }
                    } else {
                        pParts->param = 3;
                    }
                } else {
                    pParts->param = 2;
                }
            } else {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLeader()) {
                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
                        pParts->param = 4;
                    } else {
                        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->getPartySpaceNum() > 0) {
                            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowQuickMatchFlow()) {
                                pParts->param = 6;
                            } else {
                                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyInvited()) {
                                    pParts->param = 7;
                                } else {
                                    pParts->attr = 0;
                                }
                            }
                        } else {
                            pParts->param = 5;
                        }
                    }
                } else {
                    pParts->param = 3;
                }
            }
        } else {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLeader()) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
                    pParts->param = 4;
                } else {
                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->getPartySpaceNum() > 0) {
                        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowQuickMatchFlow()) {
                            pParts->param = 6;
                        } else {
                            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyInvited()) {
                                pParts->param = 7;
                            } else {
                                pParts->attr = 0;
                            }
                        }
                    } else {
                        pParts->param = 5;
                    }
                }
            } else {
                pParts->param = 3;
            }
        }
    } else {
        pParts->param = 1;
    }
}

bool cMenuPartyList::checkListFilter(u32 sortListIndex) {
    if ((sortListIndex < static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mPartyListInfoVec.mLength) && static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyReqOk(static_cast<s32>(sortListIndex), false, false)) {
        return true;
    }
    return false;
}

inline cMenuPartyList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPartyList::MyDTI cMenuPartyList::DTI("cMenuPartyList", &::cMenuBase::DTI, 480ul, 0u, 0u);

MtObject* cMenuPartyList::MyDTI::newInstance() const {
    return new (16u) cMenuPartyList;
}

const MtDTI& cMenuPartyListMemberInfo::getDTI() const {
    return cMenuPartyListMemberInfo::DTI;
}

__attribute__((weak)) void cMenuPartyListMemberInfo::initPartyListMemberInfo(MtTypedArray<CDataPartyMember>* pInfo, u32 prio) {
    DDON_STUB("cMenuPartyListMemberInfo::initPartyListMemberInfo")
    /* stub */
}

inline cMenuPartyListMemberInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPartyListMemberInfo::MyDTI cMenuPartyListMemberInfo::DTI("cMenuPartyListMemberInfo", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuPartyListMemberInfo::MyDTI::newInstance() const {
    return new (16u) cMenuPartyListMemberInfo;
}

const MtDTI& cMenuPartyManager::getDTI() const {
    return cMenuPartyManager::DTI;
}

__attribute__((weak)) void cMenuPartyManager::initPartyManager(cMenuPartyManager::PARTY_MANAGER_TAB tab, bool isShortCut) {
    DDON_STUB("cMenuPartyManager::initPartyManager")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPartyManager::movePartyManager() {
    DDON_STUB("cMenuPartyManager::movePartyManager")
    return {};
}

void cMenuPartyManager::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuPartyManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPartyManager::MyDTI cMenuPartyManager::DTI("cMenuPartyManager", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuPartyManager::MyDTI::newInstance() const {
    return new (16u) cMenuPartyManager;
}

const MtDTI& cMenuPartyMemberList::getDTI() const {
    return cMenuPartyMemberList::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuPartyMemberList::movePartyMemberList() {
    DDON_STUB("cMenuPartyMemberList::movePartyMemberList")
    return {};
}

__attribute__((weak)) bool cMenuPartyMemberList::isPartyMember(s32 cursorIndex) {
    DDON_STUB("cMenuPartyMemberList::isPartyMember")
    return {};
}

__attribute__((weak)) bool cMenuPartyMemberList::isReqMember(s32 cursorIndex) {
    DDON_STUB("cMenuPartyMemberList::isReqMember")
    return {};
}

s32 cMenuPartyMemberList::getPartyMemberIndex(s32 cursorIndex) {
    if (sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(this), false)) {
        if (mpList == nullptr) {
            if (mpMenu != nullptr) {
                return mpMenu->getMenuId(cursorIndex);
            } else {
                if (static_cast<unsigned int>(cursorIndex) < mMenuNum) {
                    if (mpMenuList != nullptr) {
                        return mpMenuList[(cursorIndex <= -1) ? 0 : cursorIndex];
                    }
                }
                return 0;
            }
        } else {
            return mpList->getMenuId(cursorIndex);
        }
    } else {
        return 0;
    }
}

s32 cMenuPartyMemberList::getReqMemberIndex(s32 cursorIndex) {
    if (sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(this), false)) {
        if (mpList == nullptr) {
            if (mpMenu != nullptr) {
                return mpMenu->getMenuId(cursorIndex) - 8;
            } else {
                if (static_cast<unsigned int>(cursorIndex) < mMenuNum) {
                    if (mpMenuList != nullptr) {
                        return mpMenuList[(cursorIndex <= -1) ? 0 : cursorIndex] - 8;
                    }
                }
                return -8;
            }
        } else {
            return mpList->getMenuId(cursorIndex) - 8;
        }
    } else {
        return -8;
    }
}

__attribute__((weak)) void cMenuPartyMemberList::updatePtr() {
    DDON_STUB("cMenuPartyMemberList::updatePtr")
    /* stub */
}

__attribute__((weak)) bool cMenuPartyMemberList::isEnableLeaveParty() {
    DDON_STUB("cMenuPartyMemberList::isEnableLeaveParty")
    return {};
}

void cMenuPartyMemberList::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    if ((menuId & -8) == 8) {
        return;
    }
    if (static_cast<unsigned int>(menuId) > 7) {
        if (menuId == 17) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->getGameSessionMemberNum(true) <= 1) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
                    if (sSoundManager::getInstance()->getBattleState() == sBattleState::SYS_STATE_BATTLE) {
                        pParts->attr = 1;
                        pParts->param = 2;
                    } else {
                        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowQuickMatchFlow()) {
                            pParts->attr = 1;
                            pParts->param = 3;
                        } else {
                            if (!static_cast<cEndContentsManager*>(sQuestManagerExt::getInstance()->getQuestManager(nQuest::QUEST_TYPE_END_CONTENTS))->isPlayNow()) {
                                if (sQuestManagerExt::getInstance()->isCycleContentsPlayNow()) {
                                    pParts->attr = 1;
                                    pParts->param = 4;
                                }
                            } else {
                                pParts->attr = 1;
                                pParts->param = 4;
                            }
                        }
                    }
                } else {
                    pParts->attr = 1;
                    pParts->param = 1;
                }
            } else {
                if (sSoundManager::getInstance()->getBattleState() == sBattleState::SYS_STATE_BATTLE) {
                    pParts->attr = 1;
                    pParts->param = 2;
                } else {
                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowQuickMatchFlow()) {
                        pParts->attr = 1;
                        pParts->param = 3;
                    } else {
                        if (!static_cast<cEndContentsManager*>(sQuestManagerExt::getInstance()->getQuestManager(nQuest::QUEST_TYPE_END_CONTENTS))->isPlayNow()) {
                            if (sQuestManagerExt::getInstance()->isCycleContentsPlayNow()) {
                                pParts->attr = 1;
                                pParts->param = 4;
                            }
                        } else {
                            pParts->attr = 1;
                            pParts->param = 4;
                        }
                    }
                }
            }
        }
    }
}

bool cMenuPartyMemberList::callbackCheckCloseDialog() {
    if ((static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->getGameSessionMemberNum(true) == 1) && !static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isPartyLarge(true)) {
        return true;
    }
    return sSoundManager::getInstance()->getBattleState() == sBattleState::SYS_STATE_BATTLE;
}

inline cMenuPartyMemberList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPartyMemberList::MyDTI cMenuPartyMemberList::DTI("cMenuPartyMemberList", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuPartyMemberList::MyDTI::newInstance() const {
    return new (16u) cMenuPartyMemberList;
}

const MtDTI& cMenuPartyReq::getDTI() const {
    return cMenuPartyReq::DTI;
}

void cMenuPartyReq::initPartyReq(CDataClientPartyListInfo* pInfo, u32 characterId, CHAR_NAME* pCharacterName) {
    initMenu();
    mMenuRno[0] = 0;
    mpPartyReqInfo = pInfo;
    mCharacterId = characterId;
    mCharacterName.clearName();
    if (pCharacterName != nullptr) {
        mCharacterName.clearName();
        snprintf(&mCharacterName.mFirstName[0], 13ul, "%s", pCharacterName);
        snprintf(&mCharacterName.mLastName[0], 9ul, "%s", &pCharacterName->mLastName[0]);
    } else {
        if (mpPartyReqInfo != nullptr) {
            snprintf(&mCharacterName.mFirstName[0], 13ul, "%s", mpPartyReqInfo->m_LeaderBaseInfo.m_CharacterName.m_wstrFirstName.ptr());
            snprintf(&mCharacterName.mLastName[0], 9ul, "%s", mpPartyReqInfo->m_LeaderBaseInfo.m_CharacterName.m_wstrLastName.ptr());
        }
    }
    setupDialogFlow(0u);
}

__attribute__((weak)) nMenu::MENU_RET cMenuPartyReq::movePartyReq() {
    DDON_STUB("cMenuPartyReq::movePartyReq")
    return {};
}

inline cMenuPartyReq::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPartyReq::MyDTI cMenuPartyReq::DTI("cMenuPartyReq", &::cMenuBase::DTI, 216ul, 0u, 0u);

MtObject* cMenuPartyReq::MyDTI::newInstance() const {
    return new (16u) cMenuPartyReq;
}

const MtDTI& cMenuPawnDelete::getDTI() const {
    return cMenuPawnDelete::DTI;
}

nMenu::MENU_RET cMenuPawnDelete::movePawnDelete() {
    moveMenu();
    u32 v0_0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->mpGameServer->mMyPawnList.mLength;
    if (v0_0 != 0) {
        u32 v0_1 = mPawnId;
        MtObject* * v0_2 = static_cast<sNetworkExt*>(sNetwork::getInstance())->mpGameServer->mMyPawnList.getBuffer();
        for (unsigned int i0_3 = 0;;) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_2[static_cast<int>(i0_3)]) + 8)) == v0_1) {
                mpPawnParam = static_cast<cPawnListParam*>(v0_2[static_cast<int>(i0_3)]);
                if (mpPawnParam != nullptr) {
                    if (mMenuRno[0] == 0) {
                        if (mpDialogFlow != nullptr) {
                            cMenuDialogFlow::RET t0 = mpDialogFlow->moveFlow();
                            switch (t0) {
                                case cMenuDialogFlow::RET_DLG_SET_DLG:
                                {
                                    s32 t1 = sItemManager::getInstance()->getEquipItemToTotalBagEmptySlotNum(mPawnId, static_cast<u8>(2));
                                    cMenuDialogFlow* t2 = getDialogFlow();
                                    if (t1 > -1) {
                                        MT_CTSTR t3 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 70u);
                                        MT_CTSTR t4 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                                        t2->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t3, 1, t4, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                                        mIsKeepEquip = true;
                                        getDialogFlow()->setMsgAnalyzerWork(0u, mpPawnParam->m_wstrName.ptr());
                                        return nMenu::MENU_RET_CONTINUE;
                                    } else {
                                        MT_CTSTR t6 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 313u);
                                        MT_CTSTR t7 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                                        t2->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t6, 1, t7, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                                        mIsKeepEquip = false;
                                        getDialogFlow()->setMsgAnalyzerWork(0u, mpPawnParam->m_wstrName.ptr());
                                        return nMenu::MENU_RET_CONTINUE;
                                    }
                                    break;
                                }
                                case cMenuDialogFlow::RET_DLG_CHOICE:
                                {
                                    if (getDialogFlow()->mChoice == 0) {
                                        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->deleteMyPawn(static_cast<s32>(mpPawnParam->m_unSlotNo), mIsKeepEquip);
                                        getDialogFlow()->setComWait(60);
                                        return nMenu::MENU_RET_CONTINUE;
                                    } else {
                                        return nMenu::MENU_RET_CANCEL;
                                    }
                                    break;
                                }
                                case cMenuDialogFlow::RET_DLG_SET_RESULT:
                                {
                                    cMenuDialogFlow* t5 = getDialogFlow();
                                    t5->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 71u), 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                                    getDialogFlow()->setMsgAnalyzerWork(0u, mpPawnParam->m_wstrName.ptr());
                                    return nMenu::MENU_RET_CONTINUE;
                                }
                                case cMenuDialogFlow::RET_DLG_EXIT:
                                {
                                    return nMenu::MENU_RET_EXIT;
                                }
                                case cMenuDialogFlow::RET_DLG_NULL:
                                {
                                    return nMenu::MENU_RET_CANCEL;
                                }
                                default:
                                {
                                    return nMenu::MENU_RET_CONTINUE;
                                }
                            }
                        } else {
                            return nMenu::MENU_RET_CANCEL;
                        }
                    } else {
                        return nMenu::MENU_RET_CONTINUE;
                    }
                } else {
                    return nMenu::MENU_RET_FAILED;
                }
            } else {
                if ((i0_3 + 1u) < v0_0) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    mpPawnParam = nullptr;
    return nMenu::MENU_RET_FAILED;
}

inline cMenuPawnDelete::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnDelete::MyDTI cMenuPawnDelete::DTI("cMenuPawnDelete", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuPawnDelete::MyDTI::newInstance() const {
    return new (16u) cMenuPawnDelete;
}

const MtDTI& cMenuPawnFeedback::getDTI() const {
    return cMenuPawnFeedback::DTI;
}

__attribute__((weak)) void cMenuPawnFeedback::initPawnFeedback(nNet::FEEDBACK_TYPE type, nNet::stFeedbackData& feedback) {
    DDON_STUB("cMenuPawnFeedback::initPawnFeedback")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnFeedback::movePawnFeedback() {
    DDON_STUB("cMenuPawnFeedback::movePawnFeedback")
    return {};
}

void cMenuPawnFeedback::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuPawnFeedback::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnFeedback::MyDTI cMenuPawnFeedback::DTI("cMenuPawnFeedback", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuPawnFeedback::MyDTI::newInstance() const {
    return new (16u) cMenuPawnFeedback;
}

const MtDTI& cMenuPawnHistory::getDTI() const {
    return cMenuPawnHistory::DTI;
}

void cMenuPawnHistory::exitMenu() {
    cNetGameServer* v0_8 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer();
    if (v0_8->mPawnHistoryList.mLength != 0) {
        u32 v0_0 = v0_8->mPawnHistoryList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (v0_8->mPawnHistoryList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete v0_8->mPawnHistoryList.mpArray[i0_3];
                v1_0 = v0_8->mPawnHistoryList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (v0_8->mPawnHistoryList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(v0_8->mPawnHistoryList.mpArray));
    }
    v0_8->mPawnHistoryList.mpArray = nullptr;
    v0_8->mPawnHistoryList.mBufsiz = 0;
    v0_8->mPawnHistoryList.mLength = 0;
    this->cMenuBase::exitMenu();
}

inline cMenuPawnHistory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnHistory::MyDTI cMenuPawnHistory::DTI("cMenuPawnHistory", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuPawnHistory::MyDTI::newInstance() const {
    return new (16u) cMenuPawnHistory;
}

const MtDTI& cMenuPawnManageMenu::getDTI() const {
    return cMenuPawnManageMenu::DTI;
}

__attribute__((weak)) void cMenuPawnManageMenu::initPawnManageMenu() {
    DDON_STUB("cMenuPawnManageMenu::initPawnManageMenu")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnManageMenu::movePawnManageMenu() {
    DDON_STUB("cMenuPawnManageMenu::movePawnManageMenu")
    return {};
}

void cMenuPawnManageMenu::exitMenu() {
    if (mUseGUIMenu) {
        static_cast<sGUIExt*>(sGUI::getInstance())->deleteShopTitle();
    }
    this->cMenuBase::exitMenu();
}

inline cMenuPawnManageMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnManageMenu::MyDTI cMenuPawnManageMenu::DTI("cMenuPawnManageMenu", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuPawnManageMenu::MyDTI::newInstance() const {
    return new (16u) cMenuPawnManageMenu;
}

const MtDTI& cMenuPawnManager::getDTI() const {
    return cMenuPawnManager::DTI;
}

__attribute__((weak)) void cMenuPawnManager::initPawnManager(s32 initTab) {
    DDON_STUB("cMenuPawnManager::initPawnManager")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnManager::movePawnManager() {
    DDON_STUB("cMenuPawnManager::movePawnManager")
    return {};
}

void cMenuPawnManager::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuPawnManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnManager::MyDTI cMenuPawnManager::DTI("cMenuPawnManager", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuPawnManager::MyDTI::newInstance() const {
    return new (16u) cMenuPawnManager;
}

const MtDTI& cMenuPawnPoint::getDTI() const {
    return cMenuPawnPoint::DTI;
}

cMenuPawnPoint::~cMenuPawnPoint() {
    if (mUseSupportPointVec.mLength != 0) {
        u32 v0_0 = mUseSupportPointVec.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mUseSupportPointVec.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mUseSupportPointVec.mpArray[i0_3];
                v1_0 = mUseSupportPointVec.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mUseSupportPointVec.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mUseSupportPointVec.mpArray));
    }
    mUseSupportPointVec.mpArray = nullptr;
    mUseSupportPointVec.mBufsiz = 0;
    mUseSupportPointVec.mLength = 0;
}

__attribute__((weak)) void cMenuPawnPoint::initPawnPoint(u32 pawnId) {
    DDON_STUB("cMenuPawnPoint::initPawnPoint")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnPoint::movePawnPoint() {
    DDON_STUB("cMenuPawnPoint::movePawnPoint")
    return {};
}

inline cMenuPawnPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnPoint::MyDTI cMenuPawnPoint::DTI("cMenuPawnPoint", &::cMenuBase::DTI, 216ul, 0u, 0u);

MtObject* cMenuPawnPoint::MyDTI::newInstance() const {
    return new (16u) cMenuPawnPoint;
}

const MtDTI& cMenuPawnRental::getDTI() const {
    return cMenuPawnRental::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnRental::movePawnRental() {
    DDON_STUB("cMenuPawnRental::movePawnRental")
    return {};
}

inline cMenuPawnRental::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnRental::MyDTI cMenuPawnRental::DTI("cMenuPawnRental", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuPawnRental::MyDTI::newInstance() const {
    return new (16u) cMenuPawnRental;
}

const MtDTI& cMenuPawnReqList::getDTI() const {
    return cMenuPawnReqList::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnReqList::movePawnReqList() {
    DDON_STUB("cMenuPawnReqList::movePawnReqList")
    return {};
}

inline cMenuPawnReqList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnReqList::MyDTI cMenuPawnReqList::DTI("cMenuPawnReqList", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuPawnReqList::MyDTI::newInstance() const {
    return new (16u) cMenuPawnReqList;
}

const MtDTI& cMenuPawnReqMenu::getDTI() const {
    return cMenuPawnReqMenu::DTI;
}

__attribute__((weak)) void cMenuPawnReqMenu::initPawnReqMenu() {
    DDON_STUB("cMenuPawnReqMenu::initPawnReqMenu")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnReqMenu::movePawnReqMenu() {
    DDON_STUB("cMenuPawnReqMenu::movePawnReqMenu")
    return {};
}

inline cMenuPawnReqMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnReqMenu::MyDTI cMenuPawnReqMenu::DTI("cMenuPawnReqMenu", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuPawnReqMenu::MyDTI::newInstance() const {
    return new (16u) cMenuPawnReqMenu;
}

const MtDTI& cMenuPawnReturn::getDTI() const {
    return cMenuPawnReturn::DTI;
}

__attribute__((weak)) void cMenuPawnReturn::initPawnReturn(u32 pawnId, u32 prio) {
    DDON_STUB("cMenuPawnReturn::initPawnReturn")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnReturn::movePawnReturn() {
    DDON_STUB("cMenuPawnReturn::movePawnReturn")
    return {};
}

__attribute__((weak)) void cMenuPawnReturn::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    DDON_STUB("cMenuPawnReturn::checkMenuPartsParam")
    /* stub */
}

inline cMenuPawnReturn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnReturn::MyDTI cMenuPawnReturn::DTI("cMenuPawnReturn", &::cMenuBase::DTI, 208ul, 0u, 0u);

MtObject* cMenuPawnReturn::MyDTI::newInstance() const {
    return new (16u) cMenuPawnReturn;
}

const MtDTI& cMenuPawnRevive::getDTI() const {
    return cMenuPawnRevive::DTI;
}

__attribute__((weak)) void cMenuPawnRevive::initPawnRevive(s32 type) {
    initMenu();
    mMenuCursor[PAWN_REVIVE_CURSOR_SELECT] = 0;
    mMenuRno[PAWN_REVIVE_RNO_BASE] = MOVE_PAWN_REVIVE_RNO_INIT;
    mType = type;
    uGUIRetry* pGUIRetry = nullptr;
    if (type == PAWN_REVIVE_MENU_TYPE_PL_DEAD) {
        pGUIRetry = new (16u) uGUIRetry;
        if (pGUIRetry != nullptr) {
            sUnit::getInstance()->addBottom(static_cast<MOVE_LINE>(sUnitExt::ML_UI_AREA1), pGUIRetry, sUnitExt::GPT_UI_SUB);
        }
    } else {
        pGUIRetry = static_cast<uGUIRetry*>(static_cast<sGUIExt*>(sGUI::getInstance())->newSingletonMenu(&uGUIRetry::DTI));
    }
    if (pGUIRetry != nullptr) {
        mpGUIMenu = pGUIRetry;
        mUseGUIMenu = true;
    }
    mpGUIShop = nullptr;
    mKodouIndex = 0;
    mUseRim = 0;
    mMenuNum = 0;
    if (mType == PAWN_REVIVE_MENU_TYPE_PL_DEAD) {
        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getReturnLocation();
        sQuestManagerExt::getInstance()->notifyOpenRetrySelect();
    }
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnRevive::movePawnRevive(uHuman* pHm, s32& retReviveType) {
    DDON_STUB("cMenuPawnRevive::movePawnRevive")
    return {};
}

void cMenuPawnRevive::exitMenu() {
    if (mpGUIShop != nullptr) {
        mpGUIShop->kill();
        mpGUIShop = nullptr;
    }
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) void cMenuPawnRevive::updatePtr() {
    DDON_STUB("cMenuPawnRevive::updatePtr")
    /* stub */
}

s32 cMenuPawnRevive::getMenuList(s32 cursor) {
    if (sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(this), false)) {
        if (cursor > -1) {
            return mpMenuList[(static_cast<unsigned int>(cursor) < mMenuNum) ? cursor : 0];
        } else {
            return static_cast<s32>(mMenuNum);
        }
    } else {
        return 0;
    }
}

__attribute__((weak)) bool cMenuPawnRevive::isCancel(u32 cancelSe) {
    DDON_STUB("cMenuPawnRevive::isCancel")
    return {};
}

__attribute__((weak)) bool cMenuPawnRevive::isDecide() {
    DDON_STUB("cMenuPawnRevive::isDecide")
    return {};
}

inline cMenuPawnRevive::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnRevive::MyDTI cMenuPawnRevive::DTI("cMenuPawnRevive", &::cMenuBase::DTI, 232ul, 0u, 0u);

MtObject* cMenuPawnRevive::MyDTI::newInstance() const {
    return new (16u) cMenuPawnRevive;
}

const MtDTI& cMenuPawnSearch::getDTI() const {
    return cMenuPawnSearch::DTI;
}

__attribute__((weak)) void cMenuPawnSearch::initPawnSearch() {
    DDON_STUB("cMenuPawnSearch::initPawnSearch")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnSearch::movePawnSearch() {
    DDON_STUB("cMenuPawnSearch::movePawnSearch")
    return {};
}

void cMenuPawnSearch::exitMenu() {
    cNetGameServer* v0_8 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer();
    if (v0_8->mRegisterdPawnList.mLength != 0) {
        u32 v0_0 = v0_8->mRegisterdPawnList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (v0_8->mRegisterdPawnList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete v0_8->mRegisterdPawnList.mpArray[i0_3];
                v1_0 = v0_8->mRegisterdPawnList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (v0_8->mRegisterdPawnList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(v0_8->mRegisterdPawnList.mpArray));
    }
    v0_8->mRegisterdPawnList.mpArray = nullptr;
    v0_8->mRegisterdPawnList.mBufsiz = 0;
    v0_8->mRegisterdPawnList.mLength = 0;
    if (mExcludeList.mLength != 0) {
        u32 v3_0 = mExcludeList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mExcludeList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mExcludeList.mpArray[i3_3];
                v4_0 = mExcludeList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mExcludeList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mExcludeList.mpArray));
    }
    mExcludeList.mpArray = nullptr;
    mExcludeList.mBufsiz = 0;
    mExcludeList.mLength = 0;
    if (mList.mLength != 0) {
        u32 v6_0 = mList.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mList.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mList.mpArray[i6_3];
                v7_0 = mList.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mList.mpArray));
    }
    mList.mpArray = nullptr;
    mList.mBufsiz = 0;
    mList.mLength = 0;
    this->cMenuBase::exitMenu();
}

void cMenuPawnSearch::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    if (pMenu != mpCategoryMenu) {
        if (menuId == 10) {
            if (pMenu == mpSearchList) {
                if (mpCategoryMenu != nullptr) {
                    if (mpCategoryMenu->getMenuId(-1) != 0) {
                        pParts->attr = 1;
                    }
                }
            }
        }
    } else {
        if (static_cast<unsigned int>(menuId) <= 7) {
            if (((249ul >> static_cast<unsigned long>(static_cast<unsigned int>(menuId) & 31)) & 1ul) == 0) {
                pParts->attr = 1;
            }
        } else {
            pParts->attr = 1;
        }
    }
}

__attribute__((weak)) void cMenuPawnSearch::selectCategory() {
    DDON_STUB("cMenuPawnSearch::selectCategory")
    /* stub */
}

inline cMenuPawnSearch::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnSearch::MyDTI cMenuPawnSearch::DTI("cMenuPawnSearch", &::cMenuBase::DTI, 904ul, 0u, 0u);

MtObject* cMenuPawnSearch::MyDTI::newInstance() const {
    return new (16u) cMenuPawnSearch;
}

const MtDTI& cMenuPawnSetPartner::getDTI() const {
    return cMenuPawnSetPartner::DTI;
}

nMenu::MENU_RET cMenuPawnSetPartner::movePawnSetPartner() {
    moveMenu();
    u32 v0_0 = static_cast<sNetworkExt*>(sNetwork::getInstance())->mpGameServer->mMyPawnList.mLength;
    if (v0_0 != 0) {
        u32 v0_1 = mPawnId;
        MtObject* * v0_2 = static_cast<sNetworkExt*>(sNetwork::getInstance())->mpGameServer->mMyPawnList.getBuffer();
        for (unsigned int i0_3 = 0;;) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_2[static_cast<int>(i0_3)]) + 8)) == v0_1) {
                mpPawnParam = static_cast<cPawnListParam*>(v0_2[static_cast<int>(i0_3)]);
                if (mpPawnParam != nullptr) {
                    if (mMenuRno[0] == 0) {
                        if (mpDialogFlow != nullptr) {
                            cMenuDialogFlow::RET t0 = mpDialogFlow->moveFlow();
                            switch (t0) {
                                case cMenuDialogFlow::RET_DLG_SET_DLG:
                                {
                                    cMenuDialogFlow* t1 = getDialogFlow();
                                    MT_CTSTR t2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 453u);
                                    MT_CTSTR t3 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                                    t1->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, t2, 1, t3, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                                    getDialogFlow()->setMsgAnalyzerWork(0u, mpPawnParam->m_wstrName.ptr());
                                    return nMenu::MENU_RET_CONTINUE;
                                }
                                case cMenuDialogFlow::RET_DLG_CHOICE:
                                {
                                    if (getDialogFlow()->mChoice == 0) {
                                        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->setPartnerPawn(mPawnId);
                                        getDialogFlow()->setComWait(518);
                                        return nMenu::MENU_RET_CONTINUE;
                                    } else {
                                        return nMenu::MENU_RET_CANCEL;
                                    }
                                    break;
                                }
                                case cMenuDialogFlow::RET_DLG_SET_RESULT:
                                {
                                    cMenuDialogFlow* t4 = getDialogFlow();
                                    t4->setDialog(nGUIExt::DIALOG_TYPE_NORMAL, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 452u), 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), false);
                                    getDialogFlow()->setMsgAnalyzerWork(0u, mpPawnParam->m_wstrName.ptr());
                                    return nMenu::MENU_RET_CONTINUE;
                                }
                                case cMenuDialogFlow::RET_DLG_EXIT:
                                {
                                    return nMenu::MENU_RET_EXIT;
                                }
                                case cMenuDialogFlow::RET_DLG_ERROR:
                                {
                                    return nMenu::MENU_RET_CANCEL;
                                }
                                case cMenuDialogFlow::RET_DLG_NULL:
                                {
                                    return nMenu::MENU_RET_CANCEL;
                                }
                                default:
                                {
                                    return nMenu::MENU_RET_CONTINUE;
                                }
                            }
                        } else {
                            return nMenu::MENU_RET_CANCEL;
                        }
                    } else {
                        return nMenu::MENU_RET_CONTINUE;
                    }
                } else {
                    return nMenu::MENU_RET_FAILED;
                }
            } else {
                if ((i0_3 + 1u) < v0_0) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    mpPawnParam = nullptr;
    return nMenu::MENU_RET_FAILED;
}

inline cMenuPawnSetPartner::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnSetPartner::MyDTI cMenuPawnSetPartner::DTI("cMenuPawnSetPartner", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuPawnSetPartner::MyDTI::newInstance() const {
    return new (16u) cMenuPawnSetPartner;
}

const MtDTI& cMenuPawnShareRange::getDTI() const {
    return cMenuPawnShareRange::DTI;
}

__attribute__((weak)) void cMenuPawnShareRange::initPawnShareRange(u32 pawnId, u32 prio) {
    DDON_STUB("cMenuPawnShareRange::initPawnShareRange")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPawnShareRange::movePawnShareRange() {
    DDON_STUB("cMenuPawnShareRange::movePawnShareRange")
    return {};
}

inline cMenuPawnShareRange::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPawnShareRange::MyDTI cMenuPawnShareRange::DTI("cMenuPawnShareRange", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuPawnShareRange::MyDTI::newInstance() const {
    return new (16u) cMenuPawnShareRange;
}

const MtDTI& cMenuPlDeadMenu::getDTI() const {
    return cMenuPlDeadMenu::DTI;
}

__attribute__((weak)) void cMenuPlDeadMenu::initPlDeadMenu() {
    DDON_STUB("cMenuPlDeadMenu::initPlDeadMenu")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuPlDeadMenu::movePlDeadMenu() {
    DDON_STUB("cMenuPlDeadMenu::movePlDeadMenu")
    return {};
}

__attribute__((weak)) bool cMenuPlDeadMenu::isCancel(u32 cancelSe) {
    DDON_STUB("cMenuPlDeadMenu::isCancel")
    return {};
}

__attribute__((weak)) bool cMenuPlDeadMenu::isDecide() {
    DDON_STUB("cMenuPlDeadMenu::isDecide")
    return {};
}

inline cMenuPlDeadMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuPlDeadMenu::MyDTI cMenuPlDeadMenu::DTI("cMenuPlDeadMenu", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuPlDeadMenu::MyDTI::newInstance() const {
    return new (16u) cMenuPlDeadMenu;
}

const MtDTI& cMenuQuickMatch::getDTI() const {
    return cMenuQuickMatch::DTI;
}

cMenuQuickMatch::~cMenuQuickMatch() {
}

__attribute__((weak)) void cMenuQuickMatch::initQuickMatch(nNet::QUICK_MATCH_TYPE type, u32 id1, u32 id2, MT_CTSTR pName, uGUIBase* pParentGUI) {
    DDON_STUB("cMenuQuickMatch::initQuickMatch")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuQuickMatch::moveQuickMatch() {
    DDON_STUB("cMenuQuickMatch::moveQuickMatch")
    return {};
}

__attribute__((weak)) void cMenuQuickMatch::exitMenu() {
    DDON_STUB("cMenuQuickMatch::exitMenu")
    /* stub */
}

void cMenuQuickMatch::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    switch (static_cast<unsigned int>(menuId)) {
        case 0:
        {
            if ((static_cast<unsigned long>(mType) | 2) == 2) {
                pParts->attr = 1;
            }
            break;
        }
        case 1:
        {
            if (!checkJobBalance()) {
                pParts->attr = 1;
                mJob = false;
            }
            break;
        }
        case 2:
        {
            if (!checkLevelBalance()) {
                pParts->attr = 1;
                mLevel = false;
            }
            break;
        }
        case 4:
        {
            if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isEnableQuickParty()) {
                pParts->attr = 1;
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) bool cMenuQuickMatch::checkLevelBalance() {
    DDON_STUB("cMenuQuickMatch::checkLevelBalance")
    return {};
}

__attribute__((weak)) bool cMenuQuickMatch::checkJobBalance() {
    DDON_STUB("cMenuQuickMatch::checkJobBalance")
    return {};
}

inline cMenuQuickMatch::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuQuickMatch::MyDTI cMenuQuickMatch::DTI("cMenuQuickMatch", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuQuickMatch::MyDTI::newInstance() const {
    return new (16u) cMenuQuickMatch;
}

const MtDTI& cMenuQuickMatchCancel::getDTI() const {
    return cMenuQuickMatchCancel::DTI;
}

__attribute__((weak)) void cMenuQuickMatchCancel::initQuickMatchCancel(uGUIBase* pParentGUI) {
    DDON_STUB("cMenuQuickMatchCancel::initQuickMatchCancel")
    /* stub */
}

nMenu::MENU_RET cMenuQuickMatchCancel::moveQuickMatchCancel() {
    moveMenu();
    if (mMenuRno[0] != 1) {
        if (mMenuRno[0] == 0) {
            mMenuRno[0] = 1;
            if (mpMenu != nullptr) {
                mpMenu->moveMenu(-1);
            }
            if (!isCancel(5u)) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowQuickMatchFlow()) {
                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowQuickMatchReq()) {
                        if (mpMenu != nullptr) {
                            if (mpMenu->mMenuNum != 0) {
                                if (isDecideIndex(mpMenu->getCursor(), 4u, 20u)) {
                                    if (sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(this), false)) {
                                        if (mpList == nullptr) {
                                            if (mpMenu != nullptr) {
                                                s32 t0 = mpMenu->getMenuId(-1);
                                                if (t0 != 5) {
                                                    if (t0 == 6) {
                                                        static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->cancelQuickMatch(true);
                                                        return nMenu::MENU_RET_EXIT;
                                                    } else {
                                                        return nMenu::MENU_RET_CONTINUE;
                                                    }
                                                } else {
                                                    return nMenu::MENU_RET_CANCEL;
                                                }
                                            } else {
                                                return nMenu::MENU_RET_CONTINUE;
                                            }
                                        } else {
                                            s32 t0 = mpList->getMenuId(-1);
                                            if (t0 != 5) {
                                                if (t0 == 6) {
                                                    static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->cancelQuickMatch(true);
                                                    return nMenu::MENU_RET_EXIT;
                                                } else {
                                                    return nMenu::MENU_RET_CONTINUE;
                                                }
                                            } else {
                                                return nMenu::MENU_RET_CANCEL;
                                            }
                                        }
                                    } else {
                                        return nMenu::MENU_RET_CONTINUE;
                                    }
                                } else {
                                    return nMenu::MENU_RET_CONTINUE;
                                }
                            } else {
                                return nMenu::MENU_RET_CONTINUE;
                            }
                        } else {
                            return nMenu::MENU_RET_CONTINUE;
                        }
                    } else {
                        return nMenu::MENU_RET_CONTINUE;
                    }
                } else {
                    return nMenu::MENU_RET_CANCEL;
                }
            } else {
                return nMenu::MENU_RET_CANCEL;
            }
        } else {
            return nMenu::MENU_RET_CONTINUE;
        }
    } else {
        if (mpMenu != nullptr) {
            mpMenu->moveMenu(-1);
        }
        if (!isCancel(5u)) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowQuickMatchFlow()) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->isNowQuickMatchReq()) {
                    if (mpMenu != nullptr) {
                        if (mpMenu->mMenuNum != 0) {
                            if (isDecideIndex(mpMenu->getCursor(), 4u, 20u)) {
                                if (sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(this), false)) {
                                    if (mpList == nullptr) {
                                        if (mpMenu != nullptr) {
                                            s32 t0 = mpMenu->getMenuId(-1);
                                            if (t0 != 5) {
                                                if (t0 == 6) {
                                                    static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->cancelQuickMatch(true);
                                                    return nMenu::MENU_RET_EXIT;
                                                } else {
                                                    return nMenu::MENU_RET_CONTINUE;
                                                }
                                            } else {
                                                return nMenu::MENU_RET_CANCEL;
                                            }
                                        } else {
                                            return nMenu::MENU_RET_CONTINUE;
                                        }
                                    } else {
                                        s32 t0 = mpList->getMenuId(-1);
                                        if (t0 != 5) {
                                            if (t0 == 6) {
                                                static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->cancelQuickMatch(true);
                                                return nMenu::MENU_RET_EXIT;
                                            } else {
                                                return nMenu::MENU_RET_CONTINUE;
                                            }
                                        } else {
                                            return nMenu::MENU_RET_CANCEL;
                                        }
                                    }
                                } else {
                                    return nMenu::MENU_RET_CONTINUE;
                                }
                            } else {
                                return nMenu::MENU_RET_CONTINUE;
                            }
                        } else {
                            return nMenu::MENU_RET_CONTINUE;
                        }
                    } else {
                        return nMenu::MENU_RET_CONTINUE;
                    }
                } else {
                    return nMenu::MENU_RET_CONTINUE;
                }
            } else {
                return nMenu::MENU_RET_CANCEL;
            }
        } else {
            return nMenu::MENU_RET_CANCEL;
        }
    }
}

inline cMenuQuickMatchCancel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuQuickMatchCancel::MyDTI cMenuQuickMatchCancel::DTI("cMenuQuickMatchCancel", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuQuickMatchCancel::MyDTI::newInstance() const {
    return new (16u) cMenuQuickMatchCancel;
}

const MtDTI& cMenuQuickMatchRetry::getDTI() const {
    return cMenuQuickMatchRetry::DTI;
}

nMenu::MENU_RET cMenuQuickMatchRetry::moveQuickMatchRetry() {
    moveMenu();
    if (mMenuRno[0] != 1) {
        if (mMenuRno[0] == 0) {
            mMenuRno[0] = 1;
            if (mpMenu != nullptr) {
                mpMenu->moveMenu(-1);
            }
            if (!isCancel(5u)) {
                if (mpMenu != nullptr) {
                    if (mpMenu->mMenuNum != 0) {
                        if (isDecideIndex(mpMenu->getCursor(), 4u, 20u)) {
                            if (sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(this), false)) {
                                if (mpList == nullptr) {
                                    if (mpMenu != nullptr) {
                                        s32 t0 = mpMenu->getMenuId(-1);
                                        if (t0 != 1) {
                                            if (t0 == 0) {
                                                static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->startQuickMatch(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLastQuickType(), static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mQuickPartySetting);
                                                return nMenu::MENU_RET_EXIT;
                                            } else {
                                                return nMenu::MENU_RET_CONTINUE;
                                            }
                                        } else {
                                            return nMenu::MENU_RET_CANCEL;
                                        }
                                    } else {
                                        static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->startQuickMatch(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLastQuickType(), static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mQuickPartySetting);
                                        return nMenu::MENU_RET_EXIT;
                                    }
                                } else {
                                    s32 t0 = mpList->getMenuId(-1);
                                    if (t0 != 1) {
                                        if (t0 == 0) {
                                            static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->startQuickMatch(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLastQuickType(), static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mQuickPartySetting);
                                            return nMenu::MENU_RET_EXIT;
                                        } else {
                                            return nMenu::MENU_RET_CONTINUE;
                                        }
                                    } else {
                                        return nMenu::MENU_RET_CANCEL;
                                    }
                                }
                            } else {
                                static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->startQuickMatch(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLastQuickType(), static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mQuickPartySetting);
                                return nMenu::MENU_RET_EXIT;
                            }
                        } else {
                            return nMenu::MENU_RET_CONTINUE;
                        }
                    } else {
                        return nMenu::MENU_RET_CONTINUE;
                    }
                } else {
                    return nMenu::MENU_RET_CONTINUE;
                }
            } else {
                return nMenu::MENU_RET_EXIT;
            }
        } else {
            return nMenu::MENU_RET_CONTINUE;
        }
    } else {
        if (mpMenu != nullptr) {
            mpMenu->moveMenu(-1);
        }
        if (!isCancel(5u)) {
            if (mpMenu != nullptr) {
                if (mpMenu->mMenuNum != 0) {
                    if (isDecideIndex(mpMenu->getCursor(), 4u, 20u)) {
                        if (sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(this), false)) {
                            if (mpList == nullptr) {
                                if (mpMenu != nullptr) {
                                    s32 t0 = mpMenu->getMenuId(-1);
                                    if (t0 != 1) {
                                        if (t0 == 0) {
                                            static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->startQuickMatch(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLastQuickType(), static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mQuickPartySetting);
                                            return nMenu::MENU_RET_EXIT;
                                        } else {
                                            return nMenu::MENU_RET_CONTINUE;
                                        }
                                    } else {
                                        return nMenu::MENU_RET_CANCEL;
                                    }
                                } else {
                                    static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->startQuickMatch(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLastQuickType(), static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mQuickPartySetting);
                                    return nMenu::MENU_RET_EXIT;
                                }
                            } else {
                                s32 t0 = mpList->getMenuId(-1);
                                if (t0 != 1) {
                                    if (t0 == 0) {
                                        static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->startQuickMatch(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLastQuickType(), static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mQuickPartySetting);
                                        return nMenu::MENU_RET_EXIT;
                                    } else {
                                        return nMenu::MENU_RET_CONTINUE;
                                    }
                                } else {
                                    return nMenu::MENU_RET_CANCEL;
                                }
                            }
                        } else {
                            static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->startQuickMatch(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getLastQuickType(), static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mQuickPartySetting);
                            return nMenu::MENU_RET_EXIT;
                        }
                    } else {
                        return nMenu::MENU_RET_CONTINUE;
                    }
                } else {
                    return nMenu::MENU_RET_CONTINUE;
                }
            } else {
                return nMenu::MENU_RET_CONTINUE;
            }
        } else {
            return nMenu::MENU_RET_EXIT;
        }
    }
}

inline cMenuQuickMatchRetry::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuQuickMatchRetry::MyDTI cMenuQuickMatchRetry::DTI("cMenuQuickMatchRetry", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuQuickMatchRetry::MyDTI::newInstance() const {
    return new (16u) cMenuQuickMatchRetry;
}

const MtDTI& cMenuQuickMatchSelect::getDTI() const {
    return cMenuQuickMatchSelect::DTI;
}

void cMenuQuickMatchSelect::exitMenu() {
    if (mpGUINews != nullptr) {
        mpGUINews->kill();
        mpGUINews = nullptr;
    }
    if (mpGUIAreaInfo != nullptr) {
        mpGUIAreaInfo->kill();
        mpGUIAreaInfo = nullptr;
    }
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) void cMenuQuickMatchSelect::initQuickMatchSelect(s32 type) {
    DDON_STUB("cMenuQuickMatchSelect::initQuickMatchSelect")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuQuickMatchSelect::moveQuickMatchSelect() {
    DDON_STUB("cMenuQuickMatchSelect::moveQuickMatchSelect")
    return {};
}

__attribute__((weak)) void cMenuQuickMatchSelect::updatePtr() {
    DDON_STUB("cMenuQuickMatchSelect::updatePtr")
    /* stub */
}

void cMenuQuickMatchSelect::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    if (menuId == 1) {
        if (!sQuestManagerExt::getInstance()->isEnableMenu_Newspaper()) {
            pParts->attr = 1;
            pParts->param = 3;
        }
    } else {
        if (menuId == 0) {
            if (sQuestManagerExt::getInstance()->isOrderMyMainQuest()) {
                if (sQuestManagerExt::getInstance()->isOrderedSoloMainQuest()) {
                    pParts->attr = 1;
                    pParts->param = 2;
                }
            } else {
                pParts->attr = 1;
                pParts->param = 1;
            }
        }
    }
}

__attribute__((weak)) void cMenuQuickMatchSelect::setDisableMenu() {
    DDON_STUB("cMenuQuickMatchSelect::setDisableMenu")
    /* stub */
}

inline cMenuQuickMatchSelect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuQuickMatchSelect::MyDTI cMenuQuickMatchSelect::DTI("cMenuQuickMatchSelect", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuQuickMatchSelect::MyDTI::newInstance() const {
    return new (16u) cMenuQuickMatchSelect;
}

const MtDTI& cMenuReadyCheck::getDTI() const {
    return cMenuReadyCheck::DTI;
}

void cMenuReadyCheck::exitMenu() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->endReadyAction();
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) void cMenuReadyCheck::initReadyCheck(u32 type) {
    DDON_STUB("cMenuReadyCheck::initReadyCheck")
    /* stub */
}

nMenu::MENU_RET cMenuReadyCheck::moveReadyCheck() {
    nMenu::MENU_RET ret = moveReadyCheckCore();
    if (ret == nMenu::MENU_RET_CANCEL) {
        static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->requestJumpLobbyNoParty();
    }
    return ret;
}

bool cMenuReadyCheck::isReadyWait() {
    return mMenuRno[0] == 6;
}

__attribute__((weak)) nMenu::MENU_RET cMenuReadyCheck::moveReadyCheckCore() {
    DDON_STUB("cMenuReadyCheck::moveReadyCheckCore")
    return {};
}

void cMenuReadyCheck::setDisableMenu() {
    if (mpGUISystemMsg != nullptr) {
        if (mMenuNum != 0) {
            unsigned int i0_3 = 0;
            const char* v1_2;
            for (;;) {
                bool t0 = sMenu::getInstance()->isMaskMenu(mpMenuParts, static_cast<u32>(mpMenuList[i0_3]));
                mpGUISystemMsg->setChoiceEnable(i0_3, !t0, -1);
                if (!t0) {
                    v1_2 = "";
                } else {
                    if (mpMenuParts[mpMenuList[i0_3]].param != 1) {
                        v1_2 = "";
                    } else {
                        v1_2 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 227u);
                    }
                }
                mpGUISystemMsg->setChoiceErrorMsg(i0_3, v1_2, -1);
                if ((i0_3 + 1u) < mMenuNum) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
}

void cMenuReadyCheck::initEntryFlow() {
    sAIPawnSys::getInstance()->resetPartyInDeploy();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getSessionManager()->setReadyAction((mType - 1u) > 1u);
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mIsInviteAcceptNotice = false;
    if (mType != 2) {
        if (mType == 1) {
            mMenuRno[0] = 6;
            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->reqQuickPartyEntry();
            MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonDialog(), 62u);
            if (mpGUISystemMsg != nullptr) {
                mpGUISystemMsg->kill();
                mpGUISystemMsg = nullptr;
                uGUISystemMsg* t1 = cGUIUtility::reqDialog(nGUIExt::DIALOG_TYPE_NO_BUTTON, t0, 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<sGUIExt*>(sGUI::getInstance())->isChatMenuUISubMenu());
                if ((mpGUISystemMsg = t1) != nullptr) {
                    t1->mBasePointerPrio = getNextBasePointerPrio();
                }
                static_cast<sNetworkExt*>(sNetwork::getInstance())->mPartyMatchType = sNetworkExt::MATCH_TYPE_QUICK;
            } else {
                uGUISystemMsg* t1 = cGUIUtility::reqDialog(nGUIExt::DIALOG_TYPE_NO_BUTTON, t0, 0, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<sGUIExt*>(sGUI::getInstance())->isChatMenuUISubMenu());
                if ((mpGUISystemMsg = t1) != nullptr) {
                    t1->mBasePointerPrio = getNextBasePointerPrio();
                }
                static_cast<sNetworkExt*>(sNetwork::getInstance())->mPartyMatchType = sNetworkExt::MATCH_TYPE_QUICK;
            }
        } else {
            if (mType == 0) {
                mMenuRno[0] = 4;
                static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->entryInvite();
                static_cast<sNetworkExt*>(sNetwork::getInstance())->mPartyMatchType = sNetworkExt::MATCH_TYPE_INVITE;
            }
        }
    } else {
        mMenuRno[0] = 5;
        sMenu::getInstance()->mMenuReadyEntryBoardItem.initReadyEntryBoardItem();
        static_cast<sNetworkExt*>(sNetwork::getInstance())->mPartyMatchType = sNetworkExt::MATCH_TYPE_ENTRYBOARD;
    }
}

inline cMenuReadyCheck::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuReadyCheck::MyDTI cMenuReadyCheck::DTI("cMenuReadyCheck", &::cMenuBase::DTI, 224ul, 0u, 0u);

MtObject* cMenuReadyCheck::MyDTI::newInstance() const {
    return new (16u) cMenuReadyCheck;
}

const MtDTI& cMenuRecentList::getDTI() const {
    return cMenuRecentList::DTI;
}

void cMenuRecentList::initRecentList(uGUIBase* pRefGUI) {
    initMenu();
    mMenuCursor[0] = 0;
    mMenuCursor[1] = 0;
    mMenuRno[0] = 0;
    mpMenuList = static_cast<s32*>(cMenuRecentList::getAllocator()->memAlloc(static_cast<size_t>(static_cast<sNetworkExt*>(sNetwork::getInstance())->mRecentListMax) * 4, 16u));
    mpSortList = static_cast<u32*>(cMenuRecentList::getAllocator()->memAlloc(static_cast<size_t>(static_cast<sNetworkExt*>(sNetwork::getInstance())->mRecentListMax) * 4, 16u));
    createSortList();
    setRefGUI(pRefGUI, true);
}

__attribute__((weak)) nMenu::MENU_RET cMenuRecentList::moveRecentList() {
    DDON_STUB("cMenuRecentList::moveRecentList")
    return {};
}

void cMenuRecentList::exitMenu() {
    cMenuRecentList::getAllocator()->memFree(static_cast<void*>(mpSortList));
    cMenuRecentList::getAllocator()->memFree(static_cast<void*>(mpMenuList));
    mpSortList = nullptr;
    mpMenuList = nullptr;
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) void cMenuRecentList::createSortList() {
    mSortListCount = 0;
    u32* v0_1 = mpSortList;
    if (v0_1 != nullptr) {
        sNetwork* v0_3 = sNetwork::getInstance();
        u32 v2_2;
        if (static_cast<sNetworkExt*>(v0_3)->mRecentListMax != 0) {
            unsigned int i0_0 = 0;
            u32 v1_2;
            for (;;) {
                v0_1[i0_0] = 0;
                v1_2 = static_cast<sNetworkExt*>(v0_3)->getRecentListMax();
                if ((i0_0 + 1u) < v1_2) {
                    i0_0 += 1u;
                } else {
                    break;
                }
            }
            v2_2 = v1_2;
        } else {
            v2_2 = 0;
        }
        cNetGameServer* v3_4 = static_cast<sNetworkExt*>(v0_3)->getGameServer();
        if (v3_4->mRecentList.mLength != 0) {
            u32 v3_0 = mSortListCount;
            u32 v3_2 = v2_2;
            for (unsigned int i3_3 = 0;;) {
                if (v3_0 >= v3_2) {
                    break;
                } else {
                    v0_1[v3_0] = i3_3;
                    u32 t0 = mSortListCount;
                    mSortListCount = t0 + 1u;
                    if ((i3_3 + 1u) >= v3_4->mRecentList.mLength) {
                        break;
                    } else {
                        v3_0 = t0 + 1u;
                        v3_2 = static_cast<sNetworkExt*>(v0_3)->getRecentListMax();
                        i3_3 += 1u;
                    }
                }
            }
        }
        mMenuCursor[1] = 0;
        mMenuNum = 0;
        s32* v5_1 = mpMenuList;
        if (v5_1 != nullptr) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3) + 5796)) != 0) {
                unsigned int v5_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3) + 5796);
                unsigned int i5_2 = 0;
                for (int v5_3 = 0;;) {
                    u32 t1 = mSortListCount;
                    if ((i5_2 + (v5_0 * v5_3)) >= t1) {
                        break;
                    } else {
                        u32 t2 = mMenuNum;
                        mMenuNum = t2 + 1u;
                        v5_1[t2] = static_cast<s32>(i5_2);
                        if ((i5_2 + 1u) >= (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3) + 5796))) {
                            break;
                        } else {
                            v5_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3) + 5796);
                            i5_2 += 1u;
                            v5_3 = mMenuCursor[1];
                        }
                    }
                }
            }
        }
        mIsRemakeList = true;
    }
}

inline cMenuRecentList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuRecentList::MyDTI cMenuRecentList::DTI("cMenuRecentList", &::cMenuBase::DTI, 192ul, 0u, 0u);

MtObject* cMenuRecentList::MyDTI::newInstance() const {
    return new (16u) cMenuRecentList;
}

const MtDTI& cMenuRemoveFriend::getDTI() const {
    return cMenuRemoveFriend::DTI;
}

cMenuRemoveFriend::~cMenuRemoveFriend() {
}

__attribute__((weak)) void cMenuRemoveFriend::initRemoveFriend(u32 friendNo, MtString& charFirstName, MtString& charLastName) {
    DDON_STUB("cMenuRemoveFriend::initRemoveFriend")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuRemoveFriend::moveRemoveFriend() {
    DDON_STUB("cMenuRemoveFriend::moveRemoveFriend")
    return {};
}

__attribute__((weak)) void cMenuRemoveFriend::exitMenu() {
    DDON_STUB("cMenuRemoveFriend::exitMenu")
    /* stub */
}

inline cMenuRemoveFriend::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuRemoveFriend::MyDTI cMenuRemoveFriend::DTI("cMenuRemoveFriend", &::cMenuBase::DTI, 200ul, 0u, 0u);

MtObject* cMenuRemoveFriend::MyDTI::newInstance() const {
    return new (16u) cMenuRemoveFriend;
}

const MtDTI& cMenuRentalPawnList::getDTI() const {
    return cMenuRentalPawnList::DTI;
}

void cMenuRentalPawnList::initRentalPawnList(s32 listType, s32 cursorPos, s32 listAttr) {
    initMenu();
    mMenuRno[0] = 0;
    mMenuRno[1] = 0;
    mListType = listType;
    mListAttr = listAttr;
    mpRefGUI = nullptr;
    mUseGUIMenu = false;
    setupSupportList(10u, 10u, 0u);
    if (mpList != nullptr) {
        mpList->mListCursor = cursorPos;
        mpList->createList(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mRentedPawnList.mLength);
    } else {
        if (mpMenu != nullptr) {
            mpMenu->mListCursor = cursorPos;
        }
    }
    mMenuParts[0] = sMenu::mDefMenuParts;
    mMenuParts[1] = sMenu::mDefMenuParts;
    mMenuParts[2] = sMenu::mDefMenuParts;
    mMenuParts[3] = sMenu::mDefMenuParts;
    mMenuParts[4] = sMenu::mDefMenuParts;
    mMenuParts[5] = sMenu::mDefMenuParts;
    mMenuParts[6] = sMenu::mDefMenuParts;
    mMenuParts[7] = sMenu::mDefMenuParts;
    mMenuParts[8] = sMenu::mDefMenuParts;
    mMenuParts[9] = sMenu::mDefMenuParts;
    mpMenuParts = &mMenuParts[0];
    if (listType == 3) {
        if (sMenu::getInstance()->mPawnManager.mpGUIMenu == nullptr) {
            setRefGUI(sMenu::getInstance()->mPawnManager.mpRefGUI, true);
        } else {
            setRefGUI(sMenu::getInstance()->mPawnManager.mpGUIMenu, true);
        }
        return;
    } else {
        if (listType == 2) {
            if (sMenu::getInstance()->mPartyManager.mpGUIMenu == nullptr) {
                setRefGUI(sMenu::getInstance()->mPartyManager.mpRefGUI, true);
            } else {
                setRefGUI(sMenu::getInstance()->mPartyManager.mpGUIMenu, true);
            }
            return;
        } else {
            uGUIBase* v0_9 = static_cast<sGUIExt*>(sGUI::getInstance())->getSingletonMenu();
            if (v0_9 != nullptr) {
                const MtDTI& t0 = v0_9->getDTI();
                MT_CTSTR v0_1 = uGUICraft::DTI.mName;
                for (const MtDTI* v0_0 = &t0;;) {
                    if (v0_1 == v0_0->mName) {
                        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_9) + 2364)) != 57) {
                            setRefGUI(v0_9, true);
                        }
                        return;
                    } else {
                        if (v0_0->mpParent != nullptr) {
                            v0_0 = v0_0->mpParent;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) nMenu::MENU_RET cMenuRentalPawnList::moveRentalPawnList() {
    DDON_STUB("cMenuRentalPawnList::moveRentalPawnList")
    return {};
}

__attribute__((weak)) bool cMenuRentalPawnList::moveRentalPawnDetail() {
    DDON_STUB("cMenuRentalPawnList::moveRentalPawnDetail")
    return {};
}

__attribute__((weak)) void cMenuRentalPawnList::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    DDON_STUB("cMenuRentalPawnList::checkMenuPartsParam")
    /* stub */
}

inline cMenuRentalPawnList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuRentalPawnList::MyDTI cMenuRentalPawnList::DTI("cMenuRentalPawnList", &::cMenuBase::DTI, 272ul, 0u, 0u);

MtObject* cMenuRentalPawnList::MyDTI::newInstance() const {
    return new (16u) cMenuRentalPawnList;
}

const MtDTI& cMenuResetCraftPoint::getDTI() const {
    return cMenuResetCraftPoint::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuResetCraftPoint::moveResetCraftPoint() {
    DDON_STUB("cMenuResetCraftPoint::moveResetCraftPoint")
    return {};
}

inline cMenuResetCraftPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuResetCraftPoint::MyDTI cMenuResetCraftPoint::DTI("cMenuResetCraftPoint", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuResetCraftPoint::MyDTI::newInstance() const {
    return new (16u) cMenuResetCraftPoint;
}

const MtDTI& cMenuSearchFilter::getDTI() const {
    return cMenuSearchFilter::DTI;
}

__attribute__((weak)) void cMenuSearchFilter::initSearchFilter(s32 type, cCharacterData::stSearchFilterSetting& setting, uGUIBase* pParentGUI, uGUIBase* pRefGUI) {
    DDON_STUB("cMenuSearchFilter::initSearchFilter")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuSearchFilter::moveSearchFilter() {
    DDON_STUB("cMenuSearchFilter::moveSearchFilter")
    return {};
}

void cMenuSearchFilter::exitMenu() {
    if (mExcludeList.mLength != 0) {
        u32 v0_0 = mExcludeList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mExcludeList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mExcludeList.mpArray[i0_3];
                v1_0 = mExcludeList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mExcludeList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mExcludeList.mpArray));
    }
    mExcludeList.mpArray = nullptr;
    mExcludeList.mBufsiz = 0;
    mExcludeList.mLength = 0;
    this->cMenuBase::exitMenu();
}

__attribute__((weak)) void cMenuSearchFilter::initExcludeList() {
    DDON_STUB("cMenuSearchFilter::initExcludeList")
    /* stub */
}

void cMenuSearchFilter::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    if (menuId != 42) {
        return;
    }
    if (mType == 5) {
        if (mSearchTab == 1) {
            if (mpSetting->mCharacterName.mFirstName[0] != 0) {
                if (mpSetting->mCharacterName.mLastName[0] == 0) {
                    if ((mpSetting->mCommunity & 15) == 0) {
                        pParts->attr = 1;
                        pParts->param = 1;
                    }
                }
            } else {
                if ((mpSetting->mCommunity & 15) == 0) {
                    pParts->attr = 1;
                    pParts->param = 1;
                }
            }
        }
    } else {
        if (mType == 3) {
            if (mpSetting->mCharacterName.mFirstName[0] == 0) {
                if (mpSetting->mCharacterName.mLastName[0] == 0) {
                    pParts->attr = 1;
                    pParts->param = 1;
                }
            }
        }
    }
}

inline cMenuSearchFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuSearchFilter::MyDTI cMenuSearchFilter::DTI("cMenuSearchFilter", &::cMenuBase::DTI, 264ul, 0u, 0u);

MtObject* cMenuSearchFilter::MyDTI::newInstance() const {
    return new (16u) cMenuSearchFilter;
}

const MtDTI& cMenuServerList::getDTI() const {
    return cMenuServerList::DTI;
}

__attribute__((weak)) void cMenuServerList::initServerList() {
    DDON_STUB("cMenuServerList::initServerList")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuServerList::moveServerList() {
    DDON_STUB("cMenuServerList::moveServerList")
    return {};
}

void cMenuServerList::exitMenu() {
    this->cMenuBase::exitMenu();
}

s32 cMenuServerList::getServerIndex(u32 i) {
    if (mpMenuList != nullptr) {
        if (static_cast<unsigned int>((mMenuCursor[1] * 256) + mpMenuList[i]) < mSortListCount) {
            return static_cast<s32>(mSortList[static_cast<unsigned int>((mMenuCursor[1] * 256) + mpMenuList[i])]);
        } else {
            return -1;
        }
    } else {
        return 0;
    }
}

__attribute__((weak)) CGameServerListInfo* cMenuServerList::getSelectServerInfo() {
    DDON_STUB("cMenuServerList::getSelectServerInfo")
    return nullptr;
}

s32 cMenuServerList::getServerId(s32 cursorPos) {
    if (!mBusyFlag) {
        if (sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(this), false)) {
            if (mpMenuList != nullptr) {
                if (static_cast<unsigned int>((mMenuCursor[1] * 256) + mpMenuList[static_cast<unsigned int>(cursorPos)]) < mSortListCount) {
                    unsigned int t0 = mSortList[static_cast<unsigned int>((mMenuCursor[1] * 256) + mpMenuList[static_cast<unsigned int>(cursorPos)])];
                    if (static_cast<int>(t0) > -1) {
                        nUserSession::CPacket_S2C_GET_SERVER_LIST_RES* t1 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getGetServerListPacket();
                        if (t1->m_ServerList.getBuffer()[static_cast<int>(t0)] != nullptr) {
                            return static_cast<CDataGameServerListInfo*>(t1->m_ServerList.getBuffer()[static_cast<int>(t0)])->m_usId;
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

__attribute__((weak)) bool cMenuServerList::isChangeServer() {
    DDON_STUB("cMenuServerList::isChangeServer")
    return {};
}

__attribute__((weak)) void cMenuServerList::createSortList() {
    DDON_STUB("cMenuServerList::createSortList")
    /* stub */
}

inline cMenuServerList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuServerList::MyDTI cMenuServerList::DTI("cMenuServerList", &::cMenuBase::DTI, 2240ul, 0u, 0u);

MtObject* cMenuServerList::MyDTI::newInstance() const {
    return new (16u) cMenuServerList;
}

const MtDTI& cMenuSetJob::getDTI() const {
    return cMenuSetJob::DTI;
}

__attribute__((weak)) void cMenuSetJob::initSetJob(u32 attr, u32& dstJob, bool* pSetting, u32 setNum, uGUIBase* pRefGUI) {
    DDON_STUB("cMenuSetJob::initSetJob")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuSetJob::moveSetJob() {
    DDON_STUB("cMenuSetJob::moveSetJob")
    return {};
}

void cMenuSetJob::exitMenu() {
    this->cMenuBase::exitMenu();
}

void cMenuSetJob::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    if (static_cast<unsigned int>(menuId) <= 13) {
        if (((12289ul >> static_cast<unsigned long>(static_cast<unsigned int>(menuId) & 31)) & 1ul) == 0) {
            if (mSetting) {
                if ((mAttr & 4u) != 0) {
                    pParts->attr = 1;
                }
            } else {
                pParts->attr = 1;
            }
        }
    } else {
        if (mSetting) {
            if ((mAttr & 4u) != 0) {
                pParts->attr = 1;
            }
        } else {
            pParts->attr = 1;
        }
    }
}

inline cMenuSetJob::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuSetJob::MyDTI cMenuSetJob::DTI("cMenuSetJob", &::cMenuBase::DTI, 224ul, 0u, 0u);

MtObject* cMenuSetJob::MyDTI::newInstance() const {
    return new (16u) cMenuSetJob;
}

const MtDTI& cMenuSetLevel::getDTI() const {
    return cMenuSetLevel::DTI;
}

void cMenuSetLevel::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuSetLevel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuSetLevel::MyDTI cMenuSetLevel::DTI("cMenuSetLevel", &::cMenuBase::DTI, 248ul, 0u, 0u);

MtObject* cMenuSetLevel::MyDTI::newInstance() const {
    return new (16u) cMenuSetLevel;
}

const MtDTI& cMenuSetLimitPreset::getDTI() const {
    return cMenuSetLimitPreset::DTI;
}

__attribute__((weak)) void cMenuSetLimitPreset::initSetLimitPreset(u32 type, u32 attr, u32* dstLevelMin, u32* dstLevelMax, bool* pSetting) {
    DDON_STUB("cMenuSetLimitPreset::initSetLimitPreset")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuSetLimitPreset::moveSetLimitPreset() {
    DDON_STUB("cMenuSetLimitPreset::moveSetLimitPreset")
    return {};
}

void cMenuSetLimitPreset::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuSetLimitPreset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuSetLimitPreset::MyDTI cMenuSetLimitPreset::DTI("cMenuSetLimitPreset", &::cMenuBase::DTI, 248ul, 0u, 0u);

alignas(4) unsigned char cMenuSetLimitPreset_clanLevelPresetTbl_bytes[24] __asm__("_ZN19cMenuSetLimitPreset18clanLevelPresetTblE") = {0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00};

alignas(4) unsigned char cMenuSetLimitPreset_clanMemberPresetTbl_bytes[32] __asm__("_ZN19cMenuSetLimitPreset19clanMemberPresetTblE") = {0x01, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x63, 0x00, 0x00, 0x00};

MtObject* cMenuSetLimitPreset::MyDTI::newInstance() const {
    return new (16u) cMenuSetLimitPreset;
}

const MtDTI& cMenuSimplePartyReq::getDTI() const {
    return cMenuSimplePartyReq::DTI;
}

__attribute__((weak)) nMenu::MENU_RET cMenuSimplePartyReq::moveSimplePartyReq() {
    DDON_STUB("cMenuSimplePartyReq::moveSimplePartyReq")
    return {};
}

void cMenuSimplePartyReq::exitMenu() {
    cNetGameServer* v0_8 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer();
    if (v0_8->mPartyListInfoVec.mLength != 0) {
        u32 v0_0 = v0_8->mPartyListInfoVec.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (v0_8->mPartyListInfoVec.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete v0_8->mPartyListInfoVec.mpArray[i0_3];
                v1_0 = v0_8->mPartyListInfoVec.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (v0_8->mPartyListInfoVec.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(v0_8->mPartyListInfoVec.mpArray));
    }
    v0_8->mPartyListInfoVec.mpArray = nullptr;
    v0_8->mPartyListInfoVec.mBufsiz = 0;
    v0_8->mPartyListInfoVec.mLength = 0;
    this->cMenuBase::exitMenu();
}

inline cMenuSimplePartyReq::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuSimplePartyReq::MyDTI cMenuSimplePartyReq::DTI("cMenuSimplePartyReq", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuSimplePartyReq::MyDTI::newInstance() const {
    return new (16u) cMenuSimplePartyReq;
}

const MtDTI& cMenuStartGameSession::getDTI() const {
    return cMenuStartGameSession::DTI;
}

inline cMenuStartGameSession::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuStartGameSession::MyDTI cMenuStartGameSession::DTI("cMenuStartGameSession", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuStartGameSession::MyDTI::newInstance() const {
    return new (16u) cMenuStartGameSession;
}

const MtDTI& cMenuSubMenu::getDTI() const {
    return cMenuSubMenu::DTI;
}

__attribute__((noinline)) cMenuSubMenu::~cMenuSubMenu() {
}

void cMenuSubMenu::initSubMenu(s32 menuType, u32 masterId, s32 masterType, MT_CTSTR pName, MT_CTSTR pLastName, MT_CTSTR pClanName) {
    initSubMenuCore(menuType, masterId, masterType, static_cast<cPawnListParam*>(nullptr), static_cast<CDataClientPartyListInfo*>(nullptr), pName, pLastName, pClanName, static_cast<CEntryMemberData*>(nullptr), static_cast<CClanScoutEntrySearchResult*>(nullptr), 0u, false);
}

void cMenuSubMenu::initSubMenu(s32 menuType, u32 masterId, s32 masterType, u32 mSubId) {
    initSubMenuCore(menuType, masterId, masterType, static_cast<cPawnListParam*>(nullptr), static_cast<CDataClientPartyListInfo*>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<CEntryMemberData*>(nullptr), static_cast<CClanScoutEntrySearchResult*>(nullptr), mSubId, false);
}

void cMenuSubMenu::initSubMenu(s32 menuType, u32 masterId, s32 masterType, cPawnListParam* pPawnParam, bool posFix) {
    initSubMenuCore(menuType, masterId, masterType, pPawnParam, static_cast<CDataClientPartyListInfo*>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<CEntryMemberData*>(nullptr), static_cast<CClanScoutEntrySearchResult*>(nullptr), 0u, posFix);
}

void cMenuSubMenu::initSubMenu(s32 menuType, u32 masterId, s32 masterType, CEntryMemberData* pEntryMember) {
    initSubMenuCore(menuType, masterId, masterType, static_cast<cPawnListParam*>(nullptr), static_cast<CDataClientPartyListInfo*>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), pEntryMember, static_cast<CClanScoutEntrySearchResult*>(nullptr), 0u, false);
}

void cMenuSubMenu::initSubMenu(s32 menuType, CClanScoutEntrySearchResult* pScoutEntryParam) {
    initSubMenuCore(menuType, pScoutEntryParam->m_CommunityCharacterBaseInfo.m_unCharacterID, 7, static_cast<cPawnListParam*>(nullptr), static_cast<CDataClientPartyListInfo*>(nullptr), pScoutEntryParam->m_CommunityCharacterBaseInfo.m_CharacterName.m_wstrFirstName.ptr(), pScoutEntryParam->m_CommunityCharacterBaseInfo.m_CharacterName.m_wstrLastName.ptr(), pScoutEntryParam->m_CommunityCharacterBaseInfo.m_wstrClanName.ptr(), static_cast<CEntryMemberData*>(nullptr), pScoutEntryParam, 0u, false);
}

__attribute__((weak)) void cMenuSubMenu::initSubMenuCore(s32 menuType, u32 masterId, s32 masterType, cPawnListParam* pPawnParam, CDataClientPartyListInfo* pPartyParam, MT_CTSTR pName, MT_CTSTR pLastName, MT_CTSTR pClanName, CEntryMemberData* pEntryMember, CClanScoutEntrySearchResult* pScoutEntryParam, u32 subId, bool posFix) {
    DDON_STUB("cMenuSubMenu::initSubMenuCore")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuSubMenu::moveSubMenu() {
    DDON_STUB("cMenuSubMenu::moveSubMenu")
    return {};
}

__attribute__((weak)) void cMenuSubMenu::exitMenu() {
    DDON_STUB("cMenuSubMenu::exitMenu")
    /* stub */
}

__attribute__((weak)) void cMenuSubMenu::setBasePointerPrio(cMenuBase* pMenuBase) {
    DDON_STUB("cMenuSubMenu::setBasePointerPrio")
    /* stub */
}

__attribute__((weak)) void cMenuSubMenu::setBasePointerPrio(uGUIBase* pParentGUI) {
    DDON_STUB("cMenuSubMenu::setBasePointerPrio")
    /* stub */
}

__attribute__((weak)) void cMenuSubMenu::setupGUIMenu() {
    DDON_STUB("cMenuSubMenu::setupGUIMenu")
    /* stub */
}

__attribute__((weak)) void cMenuSubMenu::createBaseInfo(CCommunityCharacterBaseInfo& baseInfo) {
    DDON_STUB("cMenuSubMenu::createBaseInfo")
    /* stub */
}

__attribute__((weak)) void cMenuSubMenu::checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {
    DDON_STUB("cMenuSubMenu::checkMenuPartsParam")
    /* stub */
}

void cMenuSubMenu::setBaseInfo(const CCommunityCharacterBaseInfo& info) {
    mCharacterId = info.m_unCharacterID;
    snprintf(&mCharacterName.mFirstName[0], 13ul, "%s", info.m_CharacterName.m_wstrFirstName.ptr());
    snprintf(&mCharacterName.mLastName[0], 9ul, "%s", info.m_CharacterName.m_wstrLastName.ptr());
    MtString::STRING* t1 = info.m_wstrClanName.value;
    if (info.m_wstrClanName.ptr() == mClanNickname.ptr()) {
        return;
    }
    if (mClanNickname.value != nullptr) {
        if (sceAtomicAdd32Relaxed(&mClanNickname.value->ref, -1) == 1) {
            (MtString::mpAllocator)->memFree(static_cast<void*>(mClanNickname.value));
            mClanNickname.value = nullptr;
            size_t t2 = strlen(info.m_wstrClanName.ptr());
            if (static_cast<unsigned int>(t2) != 0) {
                void* t3 = (MtString::mpAllocator)->memAlloc(static_cast<size_t>(static_cast<unsigned int>(t2)) + 12, 16u);
                mClanNickname.value = static_cast<MtString::STRING*>(t3);
                mClanNickname.value->ref = 1;
                mClanNickname.value->length = static_cast<unsigned int>(t2);
                strcpy(reinterpret_cast<char*>(mClanNickname.value->str), info.m_wstrClanName.ptr());
            } else {
                mClanNickname.value = nullptr;
            }
        } else {
            mClanNickname.value = nullptr;
            size_t t2 = strlen(info.m_wstrClanName.ptr());
            if (static_cast<unsigned int>(t2) != 0) {
                void* t3 = (MtString::mpAllocator)->memAlloc(static_cast<size_t>(static_cast<unsigned int>(t2)) + 12, 16u);
                mClanNickname.value = static_cast<MtString::STRING*>(t3);
                mClanNickname.value->ref = 1;
                mClanNickname.value->length = static_cast<unsigned int>(t2);
                strcpy(reinterpret_cast<char*>(mClanNickname.value->str), info.m_wstrClanName.ptr());
            } else {
                mClanNickname.value = nullptr;
            }
        }
    } else {
        size_t t2 = strlen(info.m_wstrClanName.ptr());
        if (static_cast<unsigned int>(t2) != 0) {
            void* t3 = (MtString::mpAllocator)->memAlloc(static_cast<size_t>(static_cast<unsigned int>(t2)) + 12, 16u);
            mClanNickname.value = static_cast<MtString::STRING*>(t3);
            mClanNickname.value->ref = 1;
            mClanNickname.value->length = static_cast<unsigned int>(t2);
            strcpy(reinterpret_cast<char*>(mClanNickname.value->str), info.m_wstrClanName.ptr());
        } else {
            mClanNickname.value = nullptr;
        }
    }
}

__attribute__((weak)) void cMenuSubMenu::setContextInfo(const cContextInstHm& context) {
    DDON_STUB("cMenuSubMenu::setContextInfo")
    /* stub */
}

__attribute__((weak)) void cMenuSubMenu::createMenuList() {
    DDON_STUB("cMenuSubMenu::createMenuList")
    /* stub */
}

uDDOModel* cMenuSubMenu::searchUnit(u32 charId, u32 pawnId) {
    cContextInstHm* v6_13;
    if (charId == 0) {
        if (pawnId == 0) {
            return nullptr;
        } else {
            for (unsigned int i5_3 = 0;;) {
                cContextInstHm* t2 = sContextManager::getInstance()->getContextPartyPlayerIndex(i5_3, true);
                if (t2 != nullptr) {
                    if (cContextInterface::getHumanType(t2) == 1) {
                        if (pawnId == cContextInterface::getPawnId(t2)) {
                            v6_13 = t2;
                            break;
                        }
                    }
                }
                if ((i5_3 + 1u) > 7u) {
                    return nullptr;
                } else {
                    i5_3 += 1u;
                }
            }
        }
    } else {
        unsigned int i3_11;
        if (!static_cast<sAreaExt*>(sArea::getInstance())->isLobby()) {
            i3_11 = 0;
        } else {
            for (unsigned int i0_3 = 0; i0_3 <= 99u; i0_3 += 1u) {
                cContextInstHm* t0 = sContextManager::getInstance()->getContextPlayerIndex(i0_3, true);
                if (t0 != nullptr) {
                    if (cContextInterface::getHumanType(t0) == 0) {
                        if (charId == cContextInterface::getPlCharacterId(t0)) {
                            v6_13 = t0;
                            return sPlayerManager::getInstance()->getPlayer(v6_13);
                        }
                    }
                }
            }
            i3_11 = 0;
        }
        for (;;) {
            cContextInstHm* t1 = sContextManager::getInstance()->getContextPartyPlayerIndex(i3_11, true);
            if (t1 != nullptr) {
                if (cContextInterface::getHumanType(t1) == 0) {
                    if (charId == cContextInterface::getPlCharacterId(t1)) {
                        v6_13 = t1;
                        break;
                    }
                }
            }
            if ((i3_11 + 1u) > 7u) {
                return nullptr;
            } else {
                i3_11 += 1u;
            }
        }
    }
    return sPlayerManager::getInstance()->getPlayer(v6_13);
}

inline cMenuSubMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuSubMenu::MyDTI cMenuSubMenu::DTI("cMenuSubMenu", &::cMenuBase::DTI, 568ul, 0u, 0u);

__attribute__((weak)) MtObject* cMenuSubMenu::MyDTI::newInstance() const {
    DDON_STUB("cMenuSubMenu::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cMenuTraining::getDTI() const {
    return cMenuTraining::DTI;
}

__attribute__((weak)) void cMenuTraining::initMenuTraining(u32 moveline) {
    DDON_STUB("cMenuTraining::initMenuTraining")
    /* stub */
}

__attribute__((weak)) nMenu::MENU_RET cMenuTraining::moveMenuTraining() {
    DDON_STUB("cMenuTraining::moveMenuTraining")
    return {};
}

inline cMenuTraining::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuTraining::MyDTI cMenuTraining::DTI("cMenuTraining", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuTraining::MyDTI::newInstance() const {
    return new (16u) cMenuTraining;
}

const MtDTI& cMenuTreasuresLot::getDTI() const {
    return cMenuTreasuresLot::DTI;
}

__attribute__((weak)) void cMenuTreasuresLot::initTreasuresLotMenu(u32 type, u32 moveLine) {
    cMenuBase::initMenu();
    mUseGUIMenu = false;
    mCheckDraw = false;
    mpGUIGPShop = nullptr;
    mpGUITopSel = nullptr;
    mpGUIBoughtBox = nullptr;
    mpGUIGPShopDialog = nullptr;
    mType = type;
    mMoveLine = moveLine;
    mIsInit = true;
    mMenuRno[TREASURESLOT_RNO_BASE] = RNO_LOT_MENU_SETLECT;
    
    uGUIBoxGachaInfo* const pGUI = new (16u) uGUIBoxGachaInfo;
    if (pGUI != nullptr) {
        mpGUIMenu = pGUI;
        pGUI->setGUIMove(false);
        constexpr u32 t1 = 0xae15;
        *reinterpret_cast<bool*>(reinterpret_cast<char*>(pGUI) + t1) = false;
        pGUI->setWindowActive(false);
        mUseGUIMenu = true;
        sUnit::getInstance()->addBottom(static_cast<MOVE_LINE>(mMoveLine), mpGUIMenu, sUnitExt::GPT_UI_SUB);
        static_cast<sGUIExt*>(sGUI::getInstance())->createShopTitle(sGUIExt::SHOPTITLE_TYPE::GACHA, sGUIExt::SHOPTITLE_TYPE::GP_CT);
        static_cast<sGUIExt*>(sGUI::getInstance())->setMoveQuestActive(false);
    }
    
    uGUIPopTopSel* const t2 = new (16u) uGUIPopTopSel(false, 0u);
    mpGUITopSel = t2;
    if (t2 != nullptr) {
        constexpr u32 t3 = 0xa94;
        *reinterpret_cast<u32*>(reinterpret_cast<char*>(t2) + t3) = uGUIPopTopSel::MODE_GACHA;
        sUnit::getInstance()->addBottom(static_cast<MOVE_LINE>(mMoveLine), t2, sUnitExt::GPT_UI_SUB);
        mpGUITopSel->begin();
    }
}

__attribute__((weak)) nMenu::MENU_RET cMenuTreasuresLot::moveTreasuresLotMenu() {
    DDON_STUB("cMenuTreasuresLot::moveTreasuresLotMenu")
    return {};
}

__attribute__((weak)) void cMenuTreasuresLot::updatePtr() {
    DDON_STUB("cMenuTreasuresLot::updatePtr")
    /* stub */
}

void cMenuTreasuresLot::exitMenu() {
    static_cast<sGUIExt*>(sGUI::getInstance())->setMoveQuestActive(true);
    static_cast<sGUIExt*>(sGUI::getInstance())->deleteShopTitle();
    if (mpGUIGPShopDialog != nullptr) {
        mpGUIGPShopDialog->kill();
        mpGUIGPShopDialog = nullptr;
    }
    if (mpGUIBoughtBox != nullptr) {
        mpGUIBoughtBox->kill();
        mpGUIBoughtBox = nullptr;
    }
    if (mpGUITopSel != nullptr) {
        mpGUITopSel->kill();
        mpGUITopSel = nullptr;
    }
    if (mpGUIGPShop != nullptr) {
        mpGUIGPShop->kill();
        mpGUIGPShop = nullptr;
    }
    this->cMenuBase::exitMenu();
}

inline cMenuTreasuresLot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuTreasuresLot::MyDTI cMenuTreasuresLot::DTI("cMenuTreasuresLot", &::cMenuBase::DTI, 224ul, 0u, 0u);

MtObject* cMenuTreasuresLot::MyDTI::newInstance() const {
    return new (16u) cMenuTreasuresLot;
}

const MtDTI& cMenuTreasuresLotAnnounce::getDTI() const {
    return cMenuTreasuresLotAnnounce::DTI;
}

void cMenuTreasuresLotAnnounce::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuTreasuresLotAnnounce::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuTreasuresLotAnnounce::MyDTI cMenuTreasuresLotAnnounce::DTI("cMenuTreasuresLotAnnounce", &::cMenuBase::DTI, 176ul, 0u, 0u);

MtObject* cMenuTreasuresLotAnnounce::MyDTI::newInstance() const {
    return new (16u) cMenuTreasuresLotAnnounce;
}

const MtDTI& cMenuUILargeSetting::getDTI() const {
    return cMenuUILargeSetting::DTI;
}

nMenu::MENU_RET cMenuUILargeSetting::move() {
    moveMenu();
    switch (static_cast<unsigned int>(mMenuRno[0] - 1)) {
        case 0:
        {
            if (mpDialogFlow != nullptr) {
                cMenuDialogFlow::RET t0 = mpDialogFlow->moveFlow();
                if (t0 != cMenuDialogFlow::RET_DLG_NULL) {
                    if (t0 == cMenuDialogFlow::RET_DLG_CHOICE) {
                        if (getDialogFlow()->getDialogId() == 1) {
                            if (getDialogFlow()->mChoice != 0) {
                                bool t1 = isLarge;
                                static_cast<sSavedataExt*>(sSavedata::getInstance())->getStorageData().mOptionSys.mUILarge = t1;
                                getDialogFlow()->retryFlow(0);
                                return nMenu::MENU_RET_CONTINUE;
                            } else {
                                mMenuRno[0] = 2;
                                return nMenu::MENU_RET_CONTINUE;
                            }
                        } else {
                            if (getDialogFlow()->getDialogId() == 0) {
                                s32 t8 = getDialogFlow()->mChoice;
                                static_cast<sSavedataExt*>(sSavedata::getInstance())->getStorageData().mOptionSys.mUILarge = t8 == 0;
                                getDialogFlow()->retryFlow(1);
                                return nMenu::MENU_RET_CONTINUE;
                            } else {
                                return nMenu::MENU_RET_CONTINUE;
                            }
                        }
                    } else {
                        if (t0 == cMenuDialogFlow::RET_DLG_SET_DLG) {
                            if (getDialogFlow()->getDialogId() == 1) {
                                sArchiveManager* t2 = sArchiveManager::getInstance();
                                ARC_TAGID t3 = rArchiveListArray::convTagId("systemFlow");
                                cResource* t4 = t2->createRes(t3, rArchiveListArray::convSearchId("RES_ID_SYSTEM_MESSASGE_GMD"), 1u, false);
                                cMenuDialogFlow* t5 = getDialogFlow();
                                MT_CTSTR t6 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<const rGUIMessage*>(t4), 23u);
                                MT_CTSTR t7 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                                t5->setDialogNoCancel(nGUIExt::DIALOG_TYPE_NORMAL, t6, 0, t7, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr));
                                if (t4 != nullptr) {
                                    t4->release();
                                    return nMenu::MENU_RET_CONTINUE;
                                } else {
                                    return nMenu::MENU_RET_CONTINUE;
                                }
                            } else {
                                if (getDialogFlow()->getDialogId() == 0) {
                                    sArchiveManager* t9 = sArchiveManager::getInstance();
                                    ARC_TAGID t10 = rArchiveListArray::convTagId("systemFlow");
                                    cResource* t11 = t9->createRes(t10, rArchiveListArray::convSearchId("RES_ID_SYSTEM_MESSASGE_GMD"), 1u, false);
                                    cMenuDialogFlow* t12 = getDialogFlow();
                                    MT_CTSTR t13 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<const rGUIMessage*>(t11), 20u);
                                    MT_CTSTR t14 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<const rGUIMessage*>(t11), 21u);
                                    t12->setDialogNoCancel(nGUIExt::DIALOG_TYPE_ROW_BUTTON, t13, 0, t14, static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<const rGUIMessage*>(t11), 22u), static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr));
                                    if (t11 != nullptr) {
                                        t11->release();
                                        return nMenu::MENU_RET_CONTINUE;
                                    } else {
                                        return nMenu::MENU_RET_CONTINUE;
                                    }
                                } else {
                                    return nMenu::MENU_RET_CONTINUE;
                                }
                            }
                        } else {
                            return nMenu::MENU_RET_CONTINUE;
                        }
                    }
                } else {
                    mMenuRno[0] = 2;
                    return nMenu::MENU_RET_CONTINUE;
                }
            } else {
                mMenuRno[0] = 2;
                return nMenu::MENU_RET_CONTINUE;
            }
            break;
        }
        case 1:
        {
            static_cast<sSavedataExt*>(sSavedata::getInstance())->saveData(SAVEDATA_TYPE_MAIN);
            mMenuRno[0] = 3;
            return nMenu::MENU_RET_CONTINUE;
        }
        case 2:
        {
            if (!static_cast<sSavedataExt*>(sSavedata::getInstance())->isBusy()) {
                mMenuRno[0] = 4;
                return nMenu::MENU_RET_CONTINUE;
            } else {
                return nMenu::MENU_RET_CONTINUE;
            }
            break;
        }
        case 3:
        {
            return nMenu::MENU_RET_EXIT;
        }
        default:
        {
            return nMenu::MENU_RET_CONTINUE;
        }
    }
}

inline cMenuUILargeSetting::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuUILargeSetting::MyDTI cMenuUILargeSetting::DTI("cMenuUILargeSetting", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuUILargeSetting::MyDTI::newInstance() const {
    return new (16u) cMenuUILargeSetting;
}

const MtDTI& cMenuUpdateCommunityList::getDTI() const {
    return cMenuUpdateCommunityList::DTI;
}

void cMenuUpdateCommunityList::initUpdateCommunityList(bool isGetRecentList) {
    initMenu();
    mMenuCursor[0] = 0;
    mMenuRno[0] = 0;
    mIsGetRecentList = isGetRecentList;
}

__attribute__((weak)) nMenu::MENU_RET cMenuUpdateCommunityList::moveUpdateCommunityList() {
    DDON_STUB("cMenuUpdateCommunityList::moveUpdateCommunityList")
    return {};
}

void cMenuUpdateCommunityList::exitMenu() {
    this->cMenuBase::exitMenu();
}

inline cMenuUpdateCommunityList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMenuUpdateCommunityList::MyDTI cMenuUpdateCommunityList::DTI("cMenuUpdateCommunityList", &::cMenuBase::DTI, 184ul, 0u, 0u);

MtObject* cMenuUpdateCommunityList::MyDTI::newInstance() const {
    return new (16u) cMenuUpdateCommunityList;
}

template MtTypedArray<CDataCharacterListElement>::~MtTypedArray();

template MtTypedArray<CDataCommunityCharacterBaseInfo>::~MtTypedArray();

template MtTypedArray<CDataPawnReaction>::~MtTypedArray();

template MtTypedArray<CDataUseSupportPoint>::~MtTypedArray();

template MtTypedArray<cMenuSupport>::~MtTypedArray();

template MtTypedArray<sItemManager::cItemList>::~MtTypedArray();

