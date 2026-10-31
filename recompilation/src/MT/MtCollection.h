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
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class SCE_AH_LIST;
class cAbilityData;
class cAbilityParam;
class cAreaMasterSpotDetailData;
class cContextCharacter;
class cContextInstChar;
class cControl;
class cCraftRecipe;
class cCycleQuestManagerBase;
class cCycleQuestSubCategoryManager;
class cDDMaterialCtrl;
class cDynamicBVHCollision;
class cEffectCycleCtrl;
class cEndContentsManager;
class cEnemyGroup;
class cFSMUnit;
class cFurniture;
class cGUIFloorManager;
class cGroupParam;
class cHitNode;
class cLayoutSet;
class cLayoutSetEnemy;
class cLayoutSetNpc;
class cMagicCommandList;
class cMenuBase;
class cMenuBlackList;
class cMenuCharacterList;
class cMenuEntryBoardItemList;
class cMenuEntryBoardRecruit;
class cMenuFriendList;
class cMenuGetItemBaggageListToServer;
class cMenuGetItemListToServer;
class cMenuGroupChatMemberList;
class cMenuMail;
class cMenuPartyList;
class cMenuPawnHistory;
class cMenuPawnPoint;
class cMenuPawnSearch;
class cMenuSearchFilter;
class cMenuSimplePartyReq;
class cModelList;
class cNetGameServer;
class cNetLoginServer;
class cOmControl;
class cOnceRequestEffectType;
class cPartsGroupList;
class cPawnAIAction;
class cPawnActInterface;
class cPawnQuestManager;
class cPlayPointInfo;
class cPrioThkIO;
class cQuestManagerBase;
class cQuestPersonalData;
class cQuestPhaseEvent;
class cQuestPhaseManager;
class cQuestResourceLoadManager;
class cQuestStage;
class cQuestSvNoticeManager;
class cQuestSvRequestManager;
class cQuestTask;
class cQuestTaskParam;
class cQuestUnitGroup;
class cQuestUnitManager;
class cServerUIClientControl;
class cShlGroupParam;
class cStageCtrl;
class cStageMap;
class cStaminaDecList;
class cTalkMsgData;
class cWeatherScript;
class cWeatherScriptIO;
class cWebsocketClient;
class cZCEFLControl;
class cZoneContactInfoList;
class cZoneLayout;
class cZoneMultiStack;
class cpCorePointCtrl;
class cpEffectStatusManager;
class cpHpDamageCtrl;
class cpItemThrow;
class cpJob09;
class cpLockOn;
class cpObjCollisionBase;
class cpOcdCtrl;
class cpShakeCtrl;
class cpStateManager;
class cpStatusChange;
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
namespace nGUIItem { class cItemList; }
namespace nHumanBow { class cBowActParam; }
namespace nMarker { class cMarkerInfo; }
namespace nMarker { class cWarpMarkerInfoStage; }
namespace nMenuKeyConfig { class KeyListItems; }
namespace nQuest { class cCycleContentsBorderRewardInfo; }
namespace nQuest { class cCycleContentsInfo; }
namespace nQuest { class cCycleContentsRankingRewardInfo; }
namespace nQuest { class cCycleContentsResultInfo; }
namespace nQuest { class cCycleContentsSituationInfo; }
namespace nQuest { class cDeliveredItemInfo; }
namespace nQuest { class cEndContentsGroupQuestInfo; }
namespace nQuest { class cGUIEventBoardData; }
namespace nQuest { class cGUINewspaperSetQuestInfo; }
namespace nQuest { class cQuestMarker; }
namespace nSessionManager { class cNetSessionManager; }
namespace nZone { class cContentsPool; }
namespace nZone { class cLayoutElement; }
class rAIPawnAutoMotionTbl;
class rAISensor;
class rAbilityList;
namespace rAcquirement { class cAbilityAddData; }
namespace rAcquirement { class cCustomSkillData; }
class rAreaInfo;
class rAreaInfoJointArea;
class rAreaInfoStage;
class rBowActParamList;
class rCameraParamList;
class rCameraQuakeList;
class rCraftRecipe;
class rCycleQuestInfo;
class rDungeonMarker;
class rFieldAreaAdjoinList;
class rFieldAreaMarkerInfo;
class rGUIMapSetting;
class rGeometry2;
class rGeometry3;
class rItemList;
class rJobTutorialQuestList;
class rKeyConfigTextTable;
class rLandInfo;
class rLayout;
class rLoadingParam;
class rMagicCommandList;
class rMsgSet;
class rNpcLedgerList;
class rOccluderEx;
class rOmKey;
class rOutlineParamList;
class rPawnQuestTalk;
class rQuestList;
class rQuestMarkerInfo;
class rQuestTextData;
class rScenario;
class rSituationMsgCtrl;
class rSoundEQ;
class rSoundMotionSe;
class rSoundReverb;
class rSoundSequenceSe;
class rSoundSimpleCurve;
class rSoundSubMixer;
class rSoundSubMixerSet;
class rStageAdjoinList;
class rStageCustomPartsEx;
class rStaminaDecTbl;
class rTable;
class rTblMenuComm;
class rTblMenuOption;
class rTexDetailEdit;
class rTutorialDialogMessage;
class rTutorialList;
class rTutorialQuestGroup;
class rWaypoint;
class rWaypoint2;
class rWeatherEffectParam;
class sAreaHit;
class sBrowser;
class sCameraExt;
class sCaplinkManager;
class sCollision;
class sControlManager;
class sCraftManager;
class sEffectExt;
class sEnemyManager;
class sGUIExt;
class sGame;
class sInputManager;
class sItemManager;
class sLockOnManager;
class sMenu;
class sNetworkExt;
class sNpcManager;
class sOccluderEx;
class sOmManager;
class sQuestManagerExt;
class sScenario;
class sSetManager;
class sShadow;
class sSoundExt;
class sSoundManager;
class sTalkManager;
class sTutorialGuide;
class sUnitManager;
class sZone;
class uDDOModel;
class uGUI;
class uGUIBase;
class uGUIBaseExt;
class uGUICaplinkTopMenu;
class uGUICommunityList;
class uGUIContentsBoard;
class uGUIEntryBoard;
class uGUIGiveAndTake;
class uGUIInfo;
class uGUIMap;
class uGUIMapMini;
class uGUIMissionResult;
class uGUIMouseOverCursor;
class uGUINpcWindow;
class uGUIPopCmd01;
class uGUIPopFilter;
class uGUIPopListDialog;
class uGUIShopBuy;
class uGUISystemMsg;
class uGeometry2;
class uGeometry2Group;
class uGeometry2GroupCollider;
class uScrollCollisionGeometry;
class uShlKeepOwnerLog;
class uSoundZoneBase;
class uStageFieldCtrl;
class uStageJointCtrl;
class uStageMyRoom;
class uStagePartsCtrl;
class uStageRevivalPawn;
class uWeapon;

// Declarations
class MtArray;
class MtMap;
class MtTree;
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
    friend class MtCollisionUtil::MtArrayEx;
    friend class SCE_AH_LIST;
    friend class cAbilityData;
    friend class cAbilityParam;
    friend class cAreaMasterSpotDetailData;
    friend class cContextCharacter;
    friend class cContextInstChar;
    friend class cControl;
    friend class cCraftRecipe;
    friend class cCycleQuestManagerBase;
    friend class cCycleQuestSubCategoryManager;
    friend class cDDMaterialCtrl;
    friend class cDynamicBVHCollision;
    friend class cEffectCycleCtrl;
    friend class cEndContentsManager;
    friend class cEnemyGroup;
    friend class cFSMUnit;
    friend class cFurniture;
    friend class cGUIFloorManager;
    friend class cGroupParam;
    friend class cHitNode;
    friend class cLayoutSet;
    friend class cLayoutSetEnemy;
    friend class cLayoutSetNpc;
    friend class cMagicCommandList;
    friend class cMenuBase;
    friend class cMenuBlackList;
    friend class cMenuCharacterList;
    friend class cMenuEntryBoardItemList;
    friend class cMenuEntryBoardRecruit;
    friend class cMenuFriendList;
    friend class cMenuGetItemBaggageListToServer;
    friend class cMenuGetItemListToServer;
    friend class cMenuGroupChatMemberList;
    friend class cMenuMail;
    friend class cMenuPartyList;
    friend class cMenuPawnHistory;
    friend class cMenuPawnPoint;
    friend class cMenuPawnSearch;
    friend class cMenuSearchFilter;
    friend class cMenuSimplePartyReq;
    friend class cModelList;
    friend class cNetGameServer;
    friend class cNetLoginServer;
    friend class cOmControl;
    friend class cOnceRequestEffectType;
    friend class cPartsGroupList;
    friend class cPawnAIAction;
    friend class cPawnActInterface;
    friend class cPawnQuestManager;
    friend class cPlayPointInfo;
    friend class cPrioThkIO;
    friend class cQuestManagerBase;
    friend class cQuestPersonalData;
    friend class cQuestPhaseEvent;
    friend class cQuestPhaseManager;
    friend class cQuestResourceLoadManager;
    friend class cQuestStage;
    friend class cQuestSvNoticeManager;
    friend class cQuestSvRequestManager;
    friend class cQuestTask;
    friend class cQuestTaskParam;
    friend class cQuestUnitGroup;
    friend class cQuestUnitManager;
    friend class cServerUIClientControl;
    friend class cShlGroupParam;
    friend class cStageCtrl;
    friend class cStageMap;
    friend class cStaminaDecList;
    friend class cTalkMsgData;
    friend class cWeatherScript;
    friend class cWeatherScriptIO;
    friend class cWebsocketClient;
    friend class cZCEFLControl;
    friend class cZoneContactInfoList;
    friend class cZoneLayout;
    friend class cZoneMultiStack;
    friend class cpCorePointCtrl;
    friend class cpEffectStatusManager;
    friend class cpHpDamageCtrl;
    friend class cpItemThrow;
    friend class cpJob09;
    friend class cpLockOn;
    friend class cpObjCollisionBase;
    friend class cpOcdCtrl;
    friend class cpShakeCtrl;
    friend class cpStateManager;
    friend class cpStatusChange;
    friend class nCaplink::ChatGroupListGetAns;
    friend class nCaplink::ContentAchievementGetAns;
    friend class nCaplink::ContentAchievementListGetAns;
    friend class nCaplink::ContentAchievementRelationGetAns;
    friend class nCaplink::ContentInviteAvailableListGetAns;
    friend class nCaplink::ContentInviteListGetAns;
    friend class nCaplink::ContentListGetAns;
    friend class nCaplink::FriendEntryRecvListGetAns;
    friend class nCaplink::FriendEntrySendListGetAns;
    friend class nCaplink::FriendListGetAns;
    friend class nCaplink::FriendTagContentListGetAns;
    friend class nCaplink::FriendTagFreeListGetAns;
    friend class nCaplink::NotifyAppListGetAns;
    friend class nCaplink::ResourcePresetListGetAns;
    friend class nCaplink::TagListGetAns;
    friend class nCaplink::TagVisibleListGetAns;
    friend class nCaplink::UserIgnoreListGetAns;
    friend class nCaplink::UserProfileContentListGetAns;
    friend class nCaplink::UserSearchAns;
    friend class nCaplink::WebsocketServerListGetAns;
    friend class nCollision::cCollisionNode;
    friend class nCollision::cCollisionNodeObject;
    friend class nFurnitureMenuFlow::cFurnitureGroupListItems;
    friend class nFurnitureMenuFlow::cFurnitureListItems;
    friend class nGUIItem::cItemList;
    friend class nHumanBow::cBowActParam;
    friend class nMarker::cMarkerInfo;
    friend class nMarker::cWarpMarkerInfoStage;
    friend class nMenuKeyConfig::KeyListItems;
    friend class nQuest::cCycleContentsBorderRewardInfo;
    friend class nQuest::cCycleContentsInfo;
    friend class nQuest::cCycleContentsRankingRewardInfo;
    friend class nQuest::cCycleContentsResultInfo;
    friend class nQuest::cCycleContentsSituationInfo;
    friend class nQuest::cDeliveredItemInfo;
    friend class nQuest::cEndContentsGroupQuestInfo;
    friend class nQuest::cGUINewspaperSetQuestInfo;
    friend class nQuest::cQuestMarker;
    friend class nSessionManager::cNetSessionManager;
    friend class nZone::cContentsPool;
    friend class nZone::cLayoutElement;
    friend class rAIPawnAutoMotionTbl;
    friend class rAISensor;
    friend class rAbilityList;
    friend class rAcquirement::cAbilityAddData;
    friend class rAcquirement::cCustomSkillData;
    friend class rAreaInfo;
    friend class rAreaInfoJointArea;
    friend class rAreaInfoStage;
    friend class rBowActParamList;
    friend class rCameraParamList;
    friend class rCameraQuakeList;
    friend class rCraftRecipe;
    friend class rCycleQuestInfo;
    friend class rDungeonMarker;
    friend class rFieldAreaAdjoinList;
    friend class rFieldAreaMarkerInfo;
    friend class rGUIMapSetting;
    friend class rGeometry2;
    friend class rGeometry3;
    friend class rItemList;
    friend class rJobTutorialQuestList;
    friend class rKeyConfigTextTable;
    friend class rLandInfo;
    friend class rLayout;
    friend class rLoadingParam;
    friend class rMagicCommandList;
    friend class rMsgSet;
    friend class rNpcLedgerList;
    friend class rOccluderEx;
    friend class rOmKey;
    friend class rOutlineParamList;
    friend class rPawnQuestTalk;
    friend class rQuestList;
    friend class rQuestMarkerInfo;
    friend class rQuestTextData;
    friend class rScenario;
    friend class rSituationMsgCtrl;
    friend class rSoundEQ;
    friend class rSoundMotionSe;
    friend class rSoundReverb;
    friend class rSoundSequenceSe;
    friend class rSoundSimpleCurve;
    friend class rSoundSubMixer;
    friend class rSoundSubMixerSet;
    friend class rStageAdjoinList;
    friend class rStageCustomPartsEx;
    friend class rStaminaDecTbl;
    friend class rTable;
    friend class rTblMenuComm;
    friend class rTblMenuOption;
    friend class rTexDetailEdit;
    friend class rTutorialDialogMessage;
    friend class rTutorialList;
    friend class rTutorialQuestGroup;
    friend class rWaypoint;
    friend class rWaypoint2;
    friend class rWeatherEffectParam;
    friend class sAreaHit;
    friend class sBrowser;
    friend class sCameraExt;
    friend class sCaplinkManager;
    friend class sCollision;
    friend class sControlManager;
    friend class sCraftManager;
    friend class sEffectExt;
    friend class sEnemyManager;
    friend class sGUIExt;
    friend class sGame;
    friend class sInputManager;
    friend class sItemManager;
    friend class sLockOnManager;
    friend class sMenu;
    friend class sNetworkExt;
    friend class sNpcManager;
    friend class sOccluderEx;
    friend class sOmManager;
    friend class sQuestManagerExt;
    friend class sScenario;
    friend class sSetManager;
    friend class sShadow;
    friend class sSoundExt;
    friend class sSoundManager;
    friend class sTalkManager;
    friend class sTutorialGuide;
    friend class sUnitManager;
    friend class sZone;
    friend class uDDOModel;
    friend class uGUI;
    friend class uGUIBase;
    friend class uGUIBaseExt;
    friend class uGUICaplinkTopMenu;
    friend class uGUICommunityList;
    friend class uGUIContentsBoard;
    friend class uGUIEntryBoard;
    friend class uGUIGiveAndTake;
    friend class uGUIInfo;
    friend class uGUIMap;
    friend class uGUIMapMini;
    friend class uGUIMissionResult;
    friend class uGUIMouseOverCursor;
    friend class uGUINpcWindow;
    friend class uGUIPopCmd01;
    friend class uGUIPopFilter;
    friend class uGUIPopListDialog;
    friend class uGUIShopBuy;
    friend class uGUISystemMsg;
    friend class uGeometry2;
    friend class uGeometry2Group;
    friend class uGeometry2GroupCollider;
    friend class uScrollCollisionGeometry;
    friend class uShlKeepOwnerLog;
    friend class uSoundZoneBase;
    friend class uStageFieldCtrl;
    friend class uStageJointCtrl;
    friend class uStageMyRoom;
    friend class uStagePartsCtrl;
    friend class uStageRevivalPawn;
    friend class uWeapon;
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

class MtTree : public MtObject
{
public:
    class MyDTI;
    class Node;
    struct FlagPtr;
public:
    using TRAVERSE_CALLBACK = bool(MtObject::*)(MtTree::Node&, void*);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Node : public MtObject
    {
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
        Node(MtObject* pRegistObject);
        virtual ~Node();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        MtObject* getObject() const;
        void setObject(MtObject* pNewObject);
        MtTree::Node* getParent();
        const MtTree::Node* getParentConst() const;
        MtTree::Node* getChild();
        const MtTree::Node* getChildConst() const;
        MtTree::Node* getNext();
        const MtTree::Node* getNextConst() const;
        MtTree::Node* getBack();
        const MtTree::Node* getBackConst() const;
        bool isAutoDeleteObject() const;
        void setAutoDeleteObject(bool);
        bool isAutoDeleteChild() const;
        void setAutoDeleteChild(bool);
        bool isAutoDeleteNext() const;
        void setAutoDeleteNext(bool);
        MT_CTSTR getName() const;
        void setName(MT_CTSTR);
        bool isExpand() const;
        void setExpand(bool);
        void* memAlloc(u32);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        void separate();
        void setChild(MtTree::Node* pNewChildNode);
        void setChildTail(MtTree::Node* pNewChildNode);
        void setNext(MtTree::Node* pNewNext);
        void setNextTail(MtTree::Node* pNewNext);
        void setBack(MtTree::Node* pNewBack);
    protected:
        MtObject* mpObject;  // offset: 0x8
        MtTree::Node* mpNext;  // offset: 0x10
        MtTree::Node* mpBack;  // offset: 0x18
        MtTree::Node* mpParent;  // offset: 0x20
        MtTree::Node* mpChild;  // offset: 0x28
        bool mFlgAutoDeleteObject;  // offset: 0x30
        bool mFlgAutoDeleteChild;  // offset: 0x31
        bool mFlgAutoDeleteNext;  // offset: 0x32
    public:
        static MyDTI DTI;
    };
public:
    struct FlagPtr
    {
    public:
        void* ptr;  // offset: 0x0
        bool flag;  // offset: 0x8
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
    MtTree();
    virtual ~MtTree();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    Node* getRoot();
    const Node* getRootConst() const;
    void deleteRoot();
    Node* getNextSibling(Node* pTreeNode);
    const Node* getNextSiblingConst(const Node* pTreeNode) const;
    Node* getBackSibling(Node* pTreeNode);
    const Node* getBackSiblingConst(const Node* pTreeNode) const;
    Node* getParent(Node* pTreeNode);
    const Node* getParentConst(const Node* pTreeNode) const;
    Node* getChild(Node* pTreeNode);
    const Node* getChildConst(const Node* pTreeNode) const;
    MtObject* createBackSibling(Node* pTreeNode, const MtDTI& dti);
    MtObject* createNextSibling(Node* pTreeNode, const MtDTI& dti);
    MtObject* createChild(Node* pTreeNode, const MtDTI& dti);
    void setRoot(Node* pNewRoot);
    void setBackSibling(Node* pTreeNode, Node* pRegistTreeElement);
    void setNextSibling(Node* pTreeNode, Node* pRegistTreeElement);
    void setNextSiblingTail(Node* pTreeNode, Node* pNewNext);
    void setChild(Node* pTreeNode, Node* pNewChildNode);
    void setChildTail(Node* pTreeNode, Node* pNewChildNode);
    void moveNode(Node* pMoveNode, Node* pTargetNode);
    void removeNode(Node* pDeleteNode);
    void removeNodeChild(Node* pDeleteNodeParent);
    void separateNode(Node* pDeleteNode);
    void setAutoDelete(bool);
    bool isAutoDelete() const;
    Node* searchElement(MtObject* pTargetObject);
    bool isRegistItem(Node* pTargetItem);
    void find(MtObject* pCallbackOwner, TRAVERSE_CALLBACK pCallbackFunc, void* ptr);
    void* memAlloc(u32);
    void memFree(void*);
    size_t memSize(void*);
protected:
    Node* searchElementCore(Node* pNowElement, MtObject* pTargetObject);
    bool isRegistItemCore(Node& item, void* pResultFlag);
    void findCore(Node* pNowElement, MtObject* pCallbackOwner, TRAVERSE_CALLBACK pCallbackFunc, void* ptr);
protected:
    Node* mpRoot;  // offset: 0x8
    bool mFlgAutoDelete;  // offset: 0x10
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

inline MtArray::MtArray() {
    this->mLength = 0;
    this->mBufsiz = 0;
    this->mAutoDelete = false;
    this->mpArray = nullptr;
}

inline u32 MtArray::size() const {
    return this->mLength;
}

inline MtObject* * MtArray::getBuffer() {
    return this->mpArray;
}

template <typename T>
MtTypedArray<T>::~MtTypedArray() {
}

template <typename T>
inline MtTypedArray<T>::MtTypedArray() {
}
