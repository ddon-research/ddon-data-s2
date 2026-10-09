#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
namespace MtCollisionUtil { class MtArrayEx; }
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cAbilityData;
class cAbilityParam;
class cContextCharacter;
class cContextInstChar;
class cControl;
class cCraftRecipe;
class cCycleQuestManagerBase;
class cCycleQuestSubCategoryManager;
class cDDMaterialCtrl;
class cDynamicBVHCollision;
class cEndContentsManager;
class cFSMUnit;
class cGUIFloorManager;
class cGroupParam;
class cHitNode;
class cMagicCommandList;
class cMenuBase;
class cMenuBlackList;
class cMenuCharacterList;
class cMenuEntryBoardRecruit;
class cMenuFriendList;
class cMenuGroupChatMemberList;
class cMenuMail;
class cMenuPartyList;
class cMenuPawnHistory;
class cMenuPawnSearch;
class cMenuSearchFilter;
class cMenuSimplePartyReq;
class cNetGameServer;
class cNetLoginServer;
class cOmControl;
class cOnceRequestEffectType;
class cPawnAIAction;
class cPawnQuestManager;
class cQuestManagerBase;
class cQuestPersonalData;
class cQuestPhaseManager;
class cQuestSvRequestManager;
class cQuestTask;
class cQuestTaskParam;
class cQuestUnitGroup;
class cQuestUnitManager;
class cServerUIClientControl;
class cShlGroupParam;
class cStageCtrl;
class cStaminaDecList;
class cTalkMsgData;
class cZCEFLControl;
class cZoneContactInfoList;
class cZoneLayout;
class cZoneMultiStack;
class cpCorePointCtrl;
class cpHpDamageCtrl;
class cpJob09;
class cpLockOn;
class cpObjCollisionBase;
namespace nCaplink { class ChatGroupListGetAns; }
namespace nCaplink { class ContentAchievementGetAns; }
namespace nCaplink { class ContentAchievementListGetAns; }
namespace nCaplink { class ContentAchievementRelationGetAns; }
namespace nCaplink { class ContentInviteAvailableListGetAns; }
namespace nCaplink { class ContentInviteListGetAns; }
namespace nCaplink { class ContentListGetAns; }
namespace nCaplink { class FriendEntryRecvListGetAns; }
namespace nCaplink { class FriendEntrySendListGetAns; }
namespace nCaplink { class FriendListGetAns; }
namespace nCaplink { class FriendTagContentListGetAns; }
namespace nCaplink { class FriendTagFreeListGetAns; }
namespace nCaplink { class NotifyAppListGetAns; }
namespace nCaplink { class ResourcePresetListGetAns; }
namespace nCaplink { class TagListGetAns; }
namespace nCaplink { class TagVisibleListGetAns; }
namespace nCaplink { class UserIgnoreListGetAns; }
namespace nCaplink { class UserProfileContentListGetAns; }
namespace nCaplink { class UserSearchAns; }
namespace nCaplink { class WebsocketServerListGetAns; }
namespace nCollision { class cCollisionNode; }
namespace nCollision { class cCollisionNodeObject; }
namespace nFurnitureMenuFlow { class cFurnitureGroupListItems; }
namespace nFurnitureMenuFlow { class cFurnitureListItems; }
namespace nHumanBow { class cBowActParam; }
namespace nMenuKeyConfig { class KeyListItems; }
namespace nQuest { class cCycleContentsSituationInfo; }
namespace nQuest { class cEndContentsGroupQuestInfo; }
namespace nQuest { class cGUIEventBoardData; }
namespace nQuest { class cGUINewspaperSetQuestInfo; }
namespace nQuest { class cQuestMarker; }
namespace nSessionManager { class cNetSessionManager; }
namespace nZone { class cLayoutElement; }
class rAIPawnAutoMotionTbl;
class rAISensor;
class rAbilityList;
class rBowActParamList;
class rCameraQuakeList;
class rCycleQuestInfo;
class rGUIMapSetting;
class rGeometry2;
class rGeometry3;
class rJobTutorialQuestList;
class rLayout;
class rLoadingParam;
class rMagicCommandList;
class rMsgSet;
class rNpcLedgerList;
class rOccluderEx;
class rOmKey;
class rOutlineParamList;
class rQuestMarkerInfo;
class rScenario;
class rSoundSubMixer;
class rSoundSubMixerSet;
class rStaminaDecTbl;
class rTable;
class rTblMenuComm;
class rTblMenuOption;
class rTexDetailEdit;
class rWeatherEffectParam;
class sBrowser;
class sCaplinkManager;
class sCollision;
class sCraftManager;
class sGUIExt;
class sGame;
class sNetworkExt;
class sNpcManager;
class sQuestManagerExt;
class sShadow;
class sSoundExt;
class sSoundManager;
class sTalkManager;
class sZone;
class uDDOModel;
class uGUIBaseExt;
class uGUIGiveAndTake;
class uGUIInfo;
class uGUIMap;
class uGUIMapMini;
class uGUIMissionResult;
class uGUINpcWindow;
class uGUIPopCmd01;
class uGUISystemMsg;
class uGeometry2;
class uGeometry2Group;
class uGeometry2GroupCollider;
class uScrollCollisionGeometry;
class uSoundZoneBase;
class uStageFieldCtrl;
class uStageJointCtrl;
class uStageMyRoom;
class uStagePartsCtrl;

// Declarations
class MtArray;
class MtMap;
template <typename T> class MtTypedArray;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class MtArray : public MtObject
{
    // inferred: MtCollisionUtil::MtArrayEx::getElementDtiName names MtArray::mLength
    friend class MtCollisionUtil::MtArrayEx;
    // inferred: cAbilityData::cAbilityData names cAbilityData::mParamArray.::MtArray::mAutoDelete
    friend class cAbilityData;
    // inferred: cAbilityParam::cAbilityParam names cAbilityParam::mParamDataArray.::MtArray::mAutoDelete
    friend class cAbilityParam;
    // inferred: cContextCharacter::isReqStickShl names cContextCharacter::mShlStickInfoArray.::MtArray::mLength
    friend class cContextCharacter;
    // inferred: cContextInstChar::getCorePointMsgNum names cContextInstChar::mCorePointMsgArray.::MtArray::mLength
    friend class cContextInstChar;
    // inferred: cControl::clearMouseTouchList names cControl::mMouseExec.mMTI.::MtArray::mLength
    friend class cControl;
    // inferred: cCraftRecipe::getItemCategoyNum names MtArray::mLength
    friend class cCraftRecipe;
    // inferred: cCycleQuestManagerBase::getCycleContentsPeriodFromSubCategory names cCycleQuestManagerBase::mSubCategory.::MtArray::mLength
    friend class cCycleQuestManagerBase;
    // inferred: cCycleQuestSubCategoryManager::release names cCycleQuestSubCategoryManager::mSituationInfo.::MtArray::mLength
    friend class cCycleQuestSubCategoryManager;
    // inferred: cDDMaterialCtrl::resetDataMaterialDefaultColors names cDDMaterialCtrl::mMaterialData.::MtArray::mpArray
    friend class cDDMaterialCtrl;
    // inferred: cDynamicBVHCollision::removeAll names cDynamicBVHCollision::mNoUseNodeArray.::MtArray::mLength
    friend class cDynamicBVHCollision;
    // inferred: cEndContentsManager::resetDistEndContentsList names cEndContentsManager::mDistEndContentsList.::MtArray::mLength
    friend class cEndContentsManager;
    // inferred: cFSMUnit::isExistEnemyUnit names sUnitManager::mRefArray.::MtArray::mLength
    friend class cFSMUnit;
    // inferred: cGUIFloorManager::getFloorGroupNo names cGUIFloorManager::mParamArray.::MtArray::mLength
    friend class cGUIFloorManager;
    // inferred: cGroupParam::isKillAreaInside names cGroupParam::mKillAreaList.::MtArray::mLength
    friend class cGroupParam;
    // inferred: cHitNode::updateNode names cHitNode::mGeomArray.mLength
    friend class cHitNode;
    // inferred: cMagicCommandList::clear names cMagicCommandList::mMagicCommandListEasy.::MtArray::mLength
    friend class cMagicCommandList;
    // inferred: cMenuBase::initMenu names cMenuBase::mMenuSupportList.::MtArray::mLength
    friend class cMenuBase;
    // inferred: cMenuBlackList::initBlackList names cNetGameServer::mBlackList.::MtArray::mLength
    friend class cMenuBlackList;
    // inferred: cMenuCharacterList::initCharacterList names nUserSession::CPacket_S2C_CHARACTER_SEARCH_RES::m_CharacterList.::MtArray::mLength
    friend class cMenuCharacterList;
    // inferred: cMenuEntryBoardRecruit::exitMenu names cMenuEntryBoardRecruit::mRecruitData.::MtArray::mLength
    friend class cMenuEntryBoardRecruit;
    // inferred: cMenuFriendList::getListType names cNetGameServer::mApplyingFriendList.::MtArray::mLength
    friend class cMenuFriendList;
    // inferred: cMenuGroupChatMemberList::exitMenu names cMenuGroupChatMemberList::mMemberList.::MtArray::mLength
    friend class cMenuGroupChatMemberList;
    // inferred: cMenuMail::getListCount names cNetGameServer::mMailList.::MtArray::mLength
    friend class cMenuMail;
    // inferred: cMenuPartyList::initPartyList names cNetGameServer::mPartyListInfoVec.::MtArray::mLength
    friend class cMenuPartyList;
    // inferred: cMenuPawnHistory::exitMenu names cNetGameServer::mPawnHistoryList.::MtArray::mLength
    friend class cMenuPawnHistory;
    // inferred: cMenuPawnSearch::exitMenu names cNetGameServer::mRegisterdPawnList.::MtArray::mLength
    friend class cMenuPawnSearch;
    // inferred: cMenuSearchFilter::exitMenu names cMenuSearchFilter::mExcludeList.::MtArray::mLength
    friend class cMenuSearchFilter;
    // inferred: cMenuSimplePartyReq::exitMenu names cNetGameServer::mPartyListInfoVec.::MtArray::mLength
    friend class cMenuSimplePartyReq;
    // inferred: cNetGameServer::createParty names nUserSession::CPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC::m_MemberMinimum.::MtArray::mLength
    friend class cNetGameServer;
    // inferred: cNetLoginServer::clearAll names cNetLoginServer::mCharacterInfoForCreate.m_CharacterJobDataList.::MtArray::mAutoDelete
    friend class cNetLoginServer;
    // inferred: cOmControl::setActiveAllSbcParts names sCollision::mSbcArray.::MtArray::mpArray
    friend class cOmControl;
    // inferred: cOnceRequestEffectType::init names cOnceRequestEffectType::mORETD.::MtArray::mLength
    friend class cOnceRequestEffectType;
    // inferred: cPawnAIAction::getPawnAIActInterNum names cPawnAIAction::mpActInters.::MtArray::mLength
    friend class cPawnAIAction;
    // inferred: cPawnQuestManager::release names cPawnQuestManager::mPawnQuestInfoList.::MtArray::mLength
    friend class cPawnQuestManager;
    // inferred: cQuestManagerBase::getQuestNum names cQuestManagerBase::mQuestTask.::MtArray::mLength
    friend class cQuestManagerBase;
    // inferred: cQuestPersonalData::deleteFlags names cQuestPersonalData::mQuestFlag.::MtArray::mLength
    friend class cQuestPersonalData;
    // inferred: cQuestPhaseManager::release names cQuestPhaseManager::mEventList.::MtArray::mLength
    friend class cQuestPhaseManager;
    // inferred: cQuestSvRequestManager::isEmpty names cQuestSvRequestManager::mQuestSvRequestQueue.::MtArray::mLength
    friend class cQuestSvRequestManager;
    // inferred: cQuestTask::getDeliveryItemInfoNum names cQuestTask::mDeliveryItemArray.::MtArray::mLength
    friend class cQuestTask;
    // inferred: cQuestTaskParam::resetOrderCondition names cQuestTaskParam::mOrderConditions.::MtArray::mLength
    friend class cQuestTaskParam;
    // inferred: cQuestUnitGroup::cQuestUnitGroup names cQuestUnitGroup::mCtrlListOm.::MtArray::mAutoDelete
    friend class cQuestUnitGroup;
    // inferred: cQuestUnitManager::release names cQuestUnitManager::mGroupList.::MtArray::mLength
    friend class cQuestUnitManager;
    // inferred: cServerUIClientControl::openServerUI names cServerUIClientControl::mServerUIList.::MtArray::mLength
    friend class cServerUIClientControl;
    // inferred: cShlGroupParam::getParamNum names cShlGroupParam::mShlList.mLength
    friend class cShlGroupParam;
    // inferred: cStageCtrl::clear names cStageCtrl::mAreaArray.::MtArray::mLength
    friend class cStageCtrl;
    // inferred: cStaminaDecList::cStaminaDecList names cStaminaDecList::mStaminaDecList.::MtArray::mAutoDelete
    friend class cStaminaDecList;
    // inferred: cTalkMsgData::getDispMsgType names rMsgSet::cMsgGroup::mMsgData.::MtArray::mLength
    friend class cTalkMsgData;
    // inferred: cZCEFLControl::getResourceSetNum names cZCEFLControl::mSetList.::MtArray::mLength
    friend class cZCEFLControl;
    // inferred: cZoneContactInfoList::initList names cZoneContactInfoList::mContactPairListStart.::MtArray::mLength
    friend class cZoneContactInfoList;
    // inferred: cZoneLayout::getGroupManagerNum names cZoneLayout::mGroupManagerArray.::MtArray::mLength
    friend class cZoneLayout;
    // inferred: cZoneMultiStack::getZoneNum names cZoneMultiStack::mNotifiedStack.::MtArray::mLength
    friend class cZoneMultiStack;
    // inferred: cpCorePointCtrl::getActiveCorePointArrayNum names cpCorePointCtrl::mActiveCorePointArray.::MtArray::mLength
    friend class cpCorePointCtrl;
    // inferred: cpHpDamageCtrl::updatePtr names cpHpDamageCtrl::mParentRegionStatusArray.::MtArray::mLength
    friend class cpHpDamageCtrl;
    // inferred: cpJob09::checkShlAlchemyValue names cpJob09::mShlArray.::MtArray::mLength
    friend class cpJob09;
    // inferred: cpLockOn::after names cpLockOn::mArray.::MtArray::mLength
    friend class cpLockOn;
    // inferred: cpObjCollisionBase::deleteNodeAll names cpObjCollisionBase::mNodeArray.mLength
    friend class cpObjCollisionBase;
    // inferred: nCaplink::ChatGroupListGetAns::init names nCaplink::ChatGroupListGetAns::mChatGroupInfoTbl.mAutoDelete
    friend class nCaplink::ChatGroupListGetAns;
    // inferred: nCaplink::ContentAchievementGetAns::init names nCaplink::ContentAchievementGetAns::mExtended.::MtArray::mAutoDelete
    friend class nCaplink::ContentAchievementGetAns;
    // inferred: nCaplink::ContentAchievementListGetAns::init names nCaplink::ContentAchievementListGetAns::mAchievementList.::MtArray::mAutoDelete
    friend class nCaplink::ContentAchievementListGetAns;
    // inferred: nCaplink::ContentAchievementRelationGetAns::init names nCaplink::ContentAchievementRelationGetAns::mAchievementList.::MtArray::mAutoDelete
    friend class nCaplink::ContentAchievementRelationGetAns;
    // inferred: nCaplink::ContentInviteAvailableListGetAns::init names nCaplink::ContentInviteAvailableListGetAns::mContentInviteInfoTbl.mAutoDelete
    friend class nCaplink::ContentInviteAvailableListGetAns;
    // inferred: nCaplink::ContentInviteListGetAns::init names nCaplink::ContentInviteListGetAns::mContentInviteUserInfoTbl.mAutoDelete
    friend class nCaplink::ContentInviteListGetAns;
    // inferred: nCaplink::ContentListGetAns::init names nCaplink::ContentListGetAns::mContentInfoTbl.mAutoDelete
    friend class nCaplink::ContentListGetAns;
    // inferred: nCaplink::FriendEntryRecvListGetAns::init names nCaplink::FriendEntryRecvListGetAns::mFriendEntryInfoTbl.mAutoDelete
    friend class nCaplink::FriendEntryRecvListGetAns;
    // inferred: nCaplink::FriendEntrySendListGetAns::init names nCaplink::FriendEntrySendListGetAns::mFriendEntryInfoTbl.mAutoDelete
    friend class nCaplink::FriendEntrySendListGetAns;
    // inferred: nCaplink::FriendListGetAns::init names nCaplink::FriendListGetAns::mFriendInfoTbl.mAutoDelete
    friend class nCaplink::FriendListGetAns;
    // inferred: nCaplink::FriendTagContentListGetAns::init names nCaplink::FriendTagContentListGetAns::mContentTagInfoTbl.mAutoDelete
    friend class nCaplink::FriendTagContentListGetAns;
    // inferred: nCaplink::FriendTagFreeListGetAns::init names nCaplink::FriendTagFreeListGetAns::mFreeTagInfoTbl.mAutoDelete
    friend class nCaplink::FriendTagFreeListGetAns;
    // inferred: nCaplink::NotifyAppListGetAns::init names nCaplink::NotifyAppListGetAns::mNotifyAppInfoTbl.mAutoDelete
    friend class nCaplink::NotifyAppListGetAns;
    // inferred: nCaplink::ResourcePresetListGetAns::init names nCaplink::ResourcePresetListGetAns::mResourceInfoTbl.mAutoDelete
    friend class nCaplink::ResourcePresetListGetAns;
    // inferred: nCaplink::TagListGetAns::init names nCaplink::TagListGetAns::mTagInfoTbl.mAutoDelete
    friend class nCaplink::TagListGetAns;
    // inferred: nCaplink::TagVisibleListGetAns::init names nCaplink::TagVisibleListGetAns::mTagVisibleInfoTbl.mAutoDelete
    friend class nCaplink::TagVisibleListGetAns;
    // inferred: nCaplink::UserIgnoreListGetAns::init names nCaplink::UserIgnoreListGetAns::mIgnoreUserInfoTbl.mAutoDelete
    friend class nCaplink::UserIgnoreListGetAns;
    // inferred: nCaplink::UserProfileContentListGetAns::init names nCaplink::UserProfileContentListGetAns::mUserContentTagInfoTbl.mAutoDelete
    friend class nCaplink::UserProfileContentListGetAns;
    // inferred: nCaplink::UserSearchAns::init names nCaplink::UserSearchAns::mUserInfoTbl.mAutoDelete
    friend class nCaplink::UserSearchAns;
    // inferred: nCaplink::WebsocketServerListGetAns::init names nCaplink::WebsocketServerListGetAns::mWebsocketServerInfoTbl.mAutoDelete
    friend class nCaplink::WebsocketServerListGetAns;
    // inferred: nCollision::cCollisionNode::setGeometry names nCollision::cCollisionNode::mGeometryArray.::MtArray::mLength
    friend class nCollision::cCollisionNode;
    // inferred: nCollision::cCollisionNodeObject::setGeometry names nCollision::cCollisionNode::mGeometryArray.::MtArray::mLength
    friend class nCollision::cCollisionNodeObject;
    // inferred: nFurnitureMenuFlow::cFurnitureGroupListItems::release names nFurnitureMenuFlow::cFurnitureGroupListItems::mItems.::MtArray::mLength
    friend class nFurnitureMenuFlow::cFurnitureGroupListItems;
    // inferred: nFurnitureMenuFlow::cFurnitureListItems::getItemNum names nFurnitureMenuFlow::cFurnitureListItems::mItems.::MtArray::mLength
    friend class nFurnitureMenuFlow::cFurnitureListItems;
    // inferred: nHumanBow::cBowActParam::cBowActParam names nHumanBow::cBowActParam::shootCtrlList.mAutoDelete
    friend class nHumanBow::cBowActParam;
    // inferred: nMenuKeyConfig::KeyListItems::getItemNum names rKeyConfigTextTable::mSortedArray.::MtArray::mLength
    friend class nMenuKeyConfig::KeyListItems;
    // inferred: nQuest::cCycleContentsSituationInfo::getOrderConditionNum names nQuest::cCycleContentsSituationInfo::mOrderConditions.::MtArray::mLength
    friend class nQuest::cCycleContentsSituationInfo;
    // inferred: nQuest::cEndContentsGroupQuestInfo::updateOrderConditionInfo names nQuest::cEndContentsGroupQuestInfo::mOrderConditions.::MtArray::mLength
    friend class nQuest::cEndContentsGroupQuestInfo;
    // inferred: nQuest::cGUINewspaperSetQuestInfo::getTargetEnemyListNum names nQuest::cGUINewspaperSetQuestInfo::mTargetEnemyArray.::MtArray::mLength
    friend class nQuest::cGUINewspaperSetQuestInfo;
    // inferred: nQuest::cQuestMarker::setPosition names MtArray::mLength
    friend class nQuest::cQuestMarker;
    // inferred: nSessionManager::cNetSessionManager::finalLobbyFlow names cNetGameServer::mLobbyMembers.::MtArray::mLength
    friend class nSessionManager::cNetSessionManager;
    // inferred: nZone::cLayoutElement::setContentsPoolID names nZone::cContentsPool::mContentsListArray.::MtArray::mLength
    friend class nZone::cLayoutElement;
    // inferred: rAIPawnAutoMotionTbl::rAIPawnAutoMotionTbl names rAIPawnAutoMotionTbl::mArray.::MtArray::mAutoDelete
    friend class rAIPawnAutoMotionTbl;
    // inferred: rAISensor::rAISensor names rAISensor::mNodes.::MtArray::mAutoDelete
    friend class rAISensor;
    // inferred: rAbilityList::rAbilityList names rAbilityList::mDataList.::MtArray::mAutoDelete
    friend class rAbilityList;
    // inferred: rBowActParamList::rBowActParamList names rBowActParamList::mParamList.mAutoDelete
    friend class rBowActParamList;
    // inferred: rCameraQuakeList::rCameraQuakeList names rCameraQuakeList::mQuakeList.mAutoDelete
    friend class rCameraQuakeList;
    // inferred: rCycleQuestInfo::save names rCycleQuestInfo::mCycleQuestInfo.::MtArray::mLength
    friend class rCycleQuestInfo;
    // inferred: rGUIMapSetting::clear names rGUIMapSetting::mArray.::MtArray::mLength
    friend class rGUIMapSetting;
    // inferred: rGeometry2::getGeometryNum names nCollision::cCollisionNode::mGeometryArray.::MtArray::mLength
    friend class rGeometry2;
    // inferred: rGeometry3::clear names rGeometry3::mGroupArray.mLength
    friend class rGeometry3;
    // inferred: rJobTutorialQuestList::getJobTutorialQuestNum names rJobTutorialQuestList::mJobTutorialList.::MtArray::mLength
    friend class rJobTutorialQuestList;
    // inferred: rLayout::rLayout names rLayout::mSetInfoSingleNewArray.mAutoDelete
    friend class rLayout;
    // inferred: rLoadingParam::rLoadingParam names rLoadingParam::mArray.::MtArray::mAutoDelete
    friend class rLoadingParam;
    // inferred: rMagicCommandList::rMagicCommandList names rMagicCommandList::mMagicCommandList.::MtArray::mAutoDelete
    friend class rMagicCommandList;
    // inferred: rMsgSet::rMsgSet names rMsgSet::mArray.::MtArray::mAutoDelete
    friend class rMsgSet;
    // inferred: rNpcLedgerList::getLedgerSize names rNpcLedgerList::mArray.::MtArray::mLength
    friend class rNpcLedgerList;
    // inferred: rOccluderEx::getAreaNum names rOccluderEx::mAreaList.mLength
    friend class rOccluderEx;
    // inferred: rOmKey::rOmKey names rOmKey::mOmKey.::MtArray::mAutoDelete
    friend class rOmKey;
    // inferred: rOutlineParamList::rOutlineParamList names rOutlineParamList::mParamList.mAutoDelete
    friend class rOutlineParamList;
    // inferred: rQuestMarkerInfo::rQuestMarkerInfo names rQuestMarkerInfo::mInfoList.::MtArray::mAutoDelete
    friend class rQuestMarkerInfo;
    // inferred: rScenario::clear names rScenario::mArray.mLength
    friend class rScenario;
    // inferred: rSoundSubMixer::clear names rSoundSubMixer::mFaders.::MtArray::mLength
    friend class rSoundSubMixer;
    // inferred: rSoundSubMixerSet::rSoundSubMixerSet names rSoundSubMixerSet::mSubMixerLists.mAutoDelete
    friend class rSoundSubMixerSet;
    // inferred: rStaminaDecTbl::rStaminaDecTbl names rStaminaDecTbl::mDecTbl.::MtArray::mAutoDelete
    friend class rStaminaDecTbl;
    // inferred: rTable::getDataBase names rTable::mArray.mLength
    friend class rTable;
    // inferred: rTblMenuComm::rTblMenuComm names rTblMenuComm::mArray.::MtArray::mAutoDelete
    friend class rTblMenuComm;
    // inferred: rTblMenuOption::rTblMenuOption names rTblMenuOption::mCtgr.::MtArray::mAutoDelete
    friend class rTblMenuOption;
    // inferred: rTexDetailEdit::clear names rTexDetailEdit::mEditList.mLength
    friend class rTexDetailEdit;
    // inferred: rWeatherEffectParam::getCorrectParamNum names MtArray::mLength
    friend class rWeatherEffectParam;
    // inferred: sBrowser::isBusy names sBrowser::mRequest.::MtArray::mLength
    friend class sBrowser;
    // inferred: sCaplinkManager::isDispErrorDialog names sCaplinkManager::mListener.::MtArray::mLength
    friend class sCaplinkManager;
    // inferred: sCollision::getSbcSize names sCollision::mSbcArray.::MtArray::mLength
    friend class sCollision;
    // inferred: sCraftManager::reset names sCraftManager::mRequest.::MtArray::mLength
    friend class sCraftManager;
    // inferred: sGUIExt::isActiveServerUI names cServerUIClientControl::mServerUIList.::MtArray::mLength
    friend class sGUIExt;
    // inferred: sGame::clearChargeCourse names sGame::mPacketGPCourseInfo.m_CourseInfo.::MtArray::mLength
    friend class sGame;
    // inferred: sNetworkExt::clearFriendInfo names cNetGameServer::mFriendList.::MtArray::mLength
    friend class sNetworkExt;
    // inferred: sNpcManager::isHaveFunction names MtArray::mLength
    friend class sNpcManager;
    // inferred: sQuestManagerExt::getHoldingCycleContentsNum names sQuestManagerExt::mCycleContentsInfoList.::MtArray::mLength
    friend class sQuestManagerExt;
    // inferred: sShadow::getNodeNum names sShadow::mNodes.mLength
    friend class sShadow;
    // inferred: sSoundExt::reset names sSoundExt::mVoiceRequest.::MtArray::mLength
    friend class sSoundExt;
    // inferred: sSoundManager::getBattleInfoNum names sSoundManager::mEmSetState.::MtArray::mLength
    friend class sSoundManager;
    // inferred: sTalkManager::clearSelectData names sTalkManager::mSelectData.::MtArray::mLength
    friend class sTalkManager;
    // inferred: sZone::reset names sZone::mZoneLayoutArray.::MtArray::mLength
    friend class sZone;
    // inferred: uDDOModel::releaseAsyncArc names uDDOModel::mAsyncArc.::MtArray::mLength
    friend class uDDOModel;
    // inferred: uGUIBaseExt::releaseResources names uGUIBaseExt::mResources.::MtArray::mpArray
    friend class uGUIBaseExt;
    // inferred: uGUIGiveAndTake::moveEvent names uGUIGiveAndTake::mItemGiveList.::MtArray::mLength
    friend class uGUIGiveAndTake;
    // inferred: uGUIInfo::evCtrlMouse names uGUIInfo::mList.mListCtrl.mInfoArray.::MtArray::mLength
    friend class uGUIInfo;
    // inferred: uGUIMap::setupMarker names uGUIMap::mMarker.::MtArray::mLength
    friend class uGUIMap;
    // inferred: uGUIMapMini::evCtrlStart names uGUIMap::mMarker.::MtArray::mLength
    friend class uGUIMapMini;
    // inferred: uGUIMissionResult::kill names uGUIMissionResult::mResultData.mResPointList.::MtArray::mLength
    friend class uGUIMissionResult;
    // inferred: uGUINpcWindow::restart names uGUISystemMsg::mArrayPageInfo.::MtArray::mLength
    friend class uGUINpcWindow;
    // inferred: uGUIPopCmd01::deleteDuplicateAll names uGUIPopCmd01::mItems.::MtArray::mLength
    friend class uGUIPopCmd01;
    // inferred: uGUISystemMsg::getFinalPageIdx names uGUISystemMsg::mArrayPageInfo.::MtArray::mLength
    friend class uGUISystemMsg;
    // inferred: uGeometry2::getGeometryNum names uGeometry2::mGeometryArray.::nCollision::cCollisionNode::mGeometryArray.::MtArray::mLength
    friend class uGeometry2;
    // inferred: uGeometry2Group::setGeometryGroupDispAllON names uGeometry2Group::mGeometryGroupArray.::MtArray::mLength
    friend class uGeometry2Group;
    // inferred: uGeometry2GroupCollider::registGeometryGroupUnit names uGeometry2GroupCollider::mNodeArray.::MtArray::mLength
    friend class uGeometry2GroupCollider;
    // inferred: uScrollCollisionGeometry::getGeometryInfoNum names uScrollCollisionGeometry::mColliderGeometryArray.::MtArray::mLength
    friend class uScrollCollisionGeometry;
    // inferred: uSoundZoneBase::setupFromResource names sZone::mZoneLayoutArray.::MtArray::mLength
    friend class uSoundZoneBase;
    // inferred: uStageFieldCtrl::updatePtr names uStageFieldCtrl::mSplitLotAry.::MtArray::mLength
    friend class uStageFieldCtrl;
    // inferred: uStageJointCtrl::updatePtr names uStageJointCtrl::mJointMdlAry.::MtArray::mLength
    friend class uStageJointCtrl;
    // inferred: uStageMyRoom::getMyRoomBgmListCount names uStageMyRoom::mBgmAcquirementNoList.::MtArray::mLength
    friend class uStageMyRoom;
    // inferred: uStagePartsCtrl::isSetup names uStagePartsCtrl::mPartsDataAry.::MtArray::mLength
    friend class uStagePartsCtrl;
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    MtArray();
    MtArray(s32 siz);
    MtArray(const MtArray& a);
    MtArray& operator=(const MtArray& a);
    void operator+=(const MtArray& add_array);
    virtual ~MtArray();
    void setAutoDelete(bool f);
    bool isAutoDelete() const;
    void reserve(u32 siz);
    void resize(u32 siz);
    void add(MtObject* pobj);
    void add(const MtArray& add_array);
    void insert(MtObject* pobj, u32 index);
    MtObject* & operator[](u32 index);
    MtObject* operator[](u32 index) const;
    MtObject* at(u32 index);
    MtObject* at(u32 index) const;
    u32 length() const;
    u32 size() const;
    u32 capacity() const;
    void clear(bool buffree);
    void sort(bool(*pfunc)(const MtObject*, const MtObject*, u32), const u32 param);
    void sort(MtObject* pFuncOwner, bool(MtObject::*pfunc)(const MtObject*, const MtObject*, u32), const u32 param);
    void deleteAll(bool buffree);
    MtObject* * getBuffer();
    const MtObject* const * getBuffer() const;
    void erase(MtObject* pobj);
    void erase(s32 index);
    void erase(u32 index);
    void erase();
    s32 find(MtObject* pobj) const;
    s32 find(bool(*pfunc)(const MtObject*, u32), const u32 param);
    s32 find(MtObject* pFuncOwner, bool(MtObject::*pfunc)(const MtObject*, u32), const u32 param);
    s32 find(bool(*pfunc)(const MtObject*, u64), const u64 param);
    s32 find(MtObject* pFuncOwner, bool(MtObject::*pfunc)(const MtObject*, u64), const u64 param);
    s32 find(const MtDTI& dti, s32 StartPos) const;
    s32 findFast(const MtDTI&, s32) const;
private:
    void setCount(u32 c);
    void setClass(MtObject* pobj, u32 i);
    MtObject* getClass(u32 i);
    void extendBuffer(u32 siz);
private:
    u32 mLength;  // offset: 0x8
    u32 mBufsiz;  // offset: 0xc
    bool mAutoDelete;  // offset: 0x10
    MtObject* * mpArray;  // offset: 0x18
public:
    static MyDTI DTI;
};

class MtMap : public MtObject
{
public:
    struct Cell;
    class MyDTI;
public:
    struct Cell
    {
    public:
        u32 mCrc;  // offset: 0x0
        MtObject* mpObj;  // offset: 0x8
        MtMap::Cell* mpNext;  // offset: 0x10
    };
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    MtMap();
    virtual ~MtMap();
    void clear();
    bool add(MtString _key, MtObject* pobj);
    MtObject* pop(MtString _key);
    void erase(MtString _key);
    MtObject* at(u32 pos);
    void del(u32 pos);
    MtObject* find(MtString);
    MtObject* getFirst(u32 crc);
    u32 size() const;
    void setAutoSort(bool f);
    bool isAutoSort() const;
private:
    bool hash_add(MtObject* pobj, u32 _crc);
    u32 hash_func(u32 _crc);
    Cell* hash_get(u32 _crc);
    void hash_del(u32 _crc);
    void hash_clear();
private:
    Cell* mpHashTable[256];  // offset: 0x8
    u32 mList[4096];  // offset: 0x808
    u32 mListNum;  // offset: 0x4808
    u32 mRefCount;  // offset: 0x480c
    bool mAutoSort;  // offset: 0x4810
public:
    static MyDTI DTI;
};

template <typename T>
class MtTypedArray : public MtArray
{
public:
    MtTypedArray();
    MtTypedArray(const MtTypedArray<T>& that);
    virtual ~MtTypedArray();
    void add(T* obj);
    void add(const MtTypedArray<T>& that);
    T* & operator[](u32 index);
    T* operator[](u32 index) const;
    T* at(u32 index);
    T* at(u32 index) const;
    void erase(T* obj);
    void erase(s32 index);
    void erase(u32 index);
    s32 find(bool(*pFunc)(const T*, u32), u32 param);
    void erase();
    void sort(bool(*pFunc)(const T*, const T*, u32), const u32 param);
    MtTypedArray<T>& operator=(const MtTypedArray<T>& that);
    void sort(MtObject* pFuncOwner, bool(MtObject::*pFunc)(const T*, const T*, const u32), u32 param);
    void insert(T* obj, u32 index);
    s32 find(T* obj) const;
    void operator+=(const MtTypedArray<T>& that);
    MtTypedArray(s32 size);
};

// Inline, no code of its own: checked where it is inlined.
inline MtArray::MtArray() {
    this->mLength = static_cast<u32>(0);
    this->mBufsiz = static_cast<u32>(0);
    this->mAutoDelete = false;
    this->mpArray = static_cast<MtObject* *>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline u32 MtArray::size() const {
    return this->mLength;
}

// Inline, no code of its own: checked where it is inlined.
inline MtObject* * MtArray::getBuffer() {
    return this->mpArray;
}

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else MtCollection.cpp, instantiates it for the body oracle.
// approximate: the family's one template definition, for an instance the renderer refused (constitution 2.4.0); its verdict is reported
template <typename T>
MtTypedArray<T>::~MtTypedArray() {
}

// Generic (024 T863c): every instance's inlined copies give this body; no code of its own, checked where it is inlined (rendered.json inline_proofs).
template <typename T>
inline MtTypedArray<T>::MtTypedArray() {
}
