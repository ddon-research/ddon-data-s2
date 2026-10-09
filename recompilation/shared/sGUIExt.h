#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "AreaMaster.h"
#include "Character.h"
#include "Item.h"
#include "JobOrbTree.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive2D.h"
#include "MtString.h"
#include "MtSynchronize.h"
#include "Quest.h"
#include "Stage.h"
#include "cArcLoader.h"
#include "cCharacterData.h"
#include "cGUIExtNetMgr.h"
#include "cItemParam.h"
#include "cPcTouchAction.h"
#include "cUIObject.h"
#include "nCharacterData.h"
#include "nCharacterEdit.h"
#include "nDDOModel.h"
#include "nDDOUtility.h"
#include "nErosionEnemyBase.h"
#include "nGUIAim.h"
#include "nGUIExt.h"
#include "nGUIHudJob10.h"
#include "nGUIItem.h"
#include "nHuman.h"
#include "nHumanMsg.h"
#include "nKeyCustom.h"
#include "rItemList.h"
#include "rTbl2ChatMacro.h"
#include "sGUI.h"
#include "sItemManager.h"
#include "sPadExt.h"

// Forward declarations
class CDataAbilityLevelParam;
class CDataAreaBaseInfo;
class CDataArisenProfile;
class CDataCommonU32;
class CDataCommunicationShortCut;
class CDataEquipPreset;
class CDataGatheringItemGetRequest;
class CDataGetRewardBoxItem;
class CDataJobChangeInfo;
class CDataJobOrbTreeStatus;
class CDataLearnedAcquirementParam;
class CDataMoveItemUIDFromTo;
class CDataNormalSkillParam;
class CDataPresetAbilityParam;
class CDataSetAcquirementParam;
class CDataShortCut;
class CDataSkillLevelParam;
class CDataSkillParam;
class CDataStorageItemUIDList;
class MtAllocator;
class MtColor;
class MtCriticalSection;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtPoint;
class MtPropertyList;
class MtRect;
class MtRectF;
class MtSize;
class MtString;
class MtVector2;
class MtVector3;
class MtVector4;
class cAchievementData;
namespace cAcquirement { class cCustomSkillData; }
namespace cAcquirement { class cNormalSkillData; }
namespace cAcquirement { class cSkillDataBase; }
class cArcLoaderBase;
class cContextInstHm;
class cGUIExtNetMgr;
class cGUIFloorManager;
class cGUIKeepString;
class cGUIMessageAnalyzer;
class cGUIObjMessage;
class cGUIObjPolygon;
class cItemParam;
class cPcTouchAction;
class cServerUIClientControl;
class cTbl2ChatMacro;
class cTexturePNG;
class cUnit;
class cWarpLocation;
namespace nGUI { struct ICON_INFO; }
namespace nGUIExt { struct stMsgAnalyzerWork; }
namespace nGUIExt { struct stWindowActive; }
namespace nGUIItem { class cItem; }
namespace nGUIItem { class cItemList; }
namespace nInputText { struct CandidateList; }
namespace nInputText { struct Context; }
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cGUIDeliveryData; }
namespace nUserSession { class CPacket_S2C_OPEN_UI_NTC; }
class rAchievement;
class rFieldMapData;
class rGUIFont;
class rGUIMessage;
class rMapSpotData;
class rMapSpotStageList;
class rReplaceWardGmdList;
class rSoundRequest;
class rStageMap;
class rStartPosArea;
class rTblMenuComm;
class rTexture;
class rTextureJpeg;
class rWarpLocation;
class uCharacter;
class uGUI;
class uGUIActionPalette;
class uGUIAim;
class uGUIAnnounce;
class uGUIBase;
class uGUIBrowserBG;
class uGUIChargesHUD;
class uGUIChat;
class uGUICommunityList;
class uGUIDamage;
class uGUIEngageInfo;
class uGUIFKeyPalette;
class uGUIGainInfo;
class uGUIGameMenu;
class uGUIGauge;
class uGUIGaugeArts;
class uGUIGaugeArtsV01_03;
class uGUIGaugeEnemyBoss;
class uGUIGaugeExp;
class uGUIGaugeSkill;
class uGUIGaugeSorcery;
class uGUIHudCustomSkillPallet;
class uGUIHudJob10Gauge;
class uGUIIndicator;
class uGUIInfo;
class uGUIInputText;
class uGUIJobMaster;
class uGUILoading;
class uGUIMap;
class uGUIMouseOverCursor;
class uGUIMousePointer;
class uGUINpcWindow;
class uGUIPlace;
class uGUIPointer;
class uGUIPopCmd01;
class uGUIPopCnvWnd;
class uGUIQuestActive;
class uGUIQuestBoard;
class uGUIQuestDelivery;
class uGUIQuestInfo;
class uGUIQueueAnnounce;
class uGUIShakeEnemy;
class uGUIShakeStick;
class uGUIShopTitle;
class uGUISkill;
class uGUISystemMsg;
class uGUITelop;
class uGUITextHud;
class uGUITouchTargetSelector;
class uGUITutorialAnnounce;
class uPlayer;

// Declarations
class sGUIExt;

// Type aliases from DWARF
using AbilityLevelParamVec = MtTypedArray<CDataAbilityLevelParam>;
using CAbilityLevelParam = CDataAbilityLevelParam;
using CEquipPreset = CDataEquipPreset;
using CJobOrbTreeStatus = CDataJobOrbTreeStatus;
using CSkillLevelParam = CDataSkillLevelParam;
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using CommunicationShortCutVec = MtTypedArray<CDataCommunicationShortCut>;
using EquipPresetVec = MtTypedArray<CDataEquipPreset>;
using GatheringItemGetRequestVec = MtTypedArray<CDataGatheringItemGetRequest>;
using GetRewardBoxItemVec = MtTypedArray<CDataGetRewardBoxItem>;
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using JOBHANDLE = u64;
using JobChangeInfoVec = MtTypedArray<CDataJobChangeInfo>;
using LearnedAcquirementParamVec = MtTypedArray<CDataLearnedAcquirementParam>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using MoveItemUIDFromToVec = MtTypedArray<CDataMoveItemUIDFromTo>;
using NormalSkillParamVec = MtTypedArray<CDataNormalSkillParam>;
using PresetAbilityParamVec = MtTypedArray<CDataPresetAbilityParam>;
using SetAcquirementParamVec = MtTypedArray<CDataSetAcquirementParam>;
using ShortCutVec = MtTypedArray<CDataShortCut>;
using SkillLevelParamVec = MtTypedArray<CDataSkillLevelParam>;
using SkillParamVec = MtTypedArray<CDataSkillParam>;
using StorageItemUIDListVec = MtTypedArray<CDataStorageItemUIDList>;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using cArcLoader32 = cArcLoader<32>;
using f32 = float;
namespace nGUIExt { using StringEnemyName = MtStringEx<256>; }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class sGUIExt : public sGUI
{
public:
    enum INFO_FLAG
    {
        INFO_FLAG_PARTY = 0,
        INFO_FLAG_FRIEND = 1,
        INFO_FLAG_CLAN_INVITE = 2,
        INFO_FLAG_CLAN_MISSION = 3,
        INFO_FLAG_CLAN_LVUP = 4,
        INFO_FLAG_FREE_GROUP = 5,
        INFO_FLAG_MAIL = 6,
        INFO_FLAG_NEWSPAPER = 7,
        INFO_FLAG_ENTRY = 8,
        INFO_FLAG_TUTORIAL = 9,
        INFO_FLAG_QUEST_RECEIVE = 10,
        INFO_FLAG_SYSTEM_INFO = 11,
        INFO_FLAG_PARTY_READY = 12,
        INFO_FLAG_QUICK_READY = 13,
        INFO_FLAG_ENTRY_BOARD_READY = 14,
        INFO_FLAG_ENTRY_BOARD_TIMEOUT = 15,
        INFO_FLAG_ENTRY_BOARD_DEPART = 16,
        INFO_FLAG_ENTRY_BOARD_REENTRY = 17,
        INFO_FLAG_LEAVE_ON_THE_WAY = 18,
        INFO_FLAG_QUEST_END_DIST = 19,
        INFO_FLAG_ACHIEVE_GET = 20,
        INFO_FLAG_ACHIEVE_UNLOCK = 21,
        INFO_FLAG_NO_LEADER = 22,
        INFO_FLAG_DISABLE_CONTENTS = 23,
        INFO_FLAG_CLAN_SCOUT = 24,
        INFO_FLAG_CLAN_APPROVE = 25,
        INFO_FLAG_CLAN_JOIN = 26,
        INFO_FLAG_CLAN_MASTER = 27,
        INFO_FLAG_CLAN_LEADER = 28,
        INFO_FLAG_CLAN_UPDATE_INFO = 29,
        INFO_FLAG_CLAN_DIRECT_INVITE = 30,
        INFO_FLAG_CAPLINK_FRIEND_ONLINE = 31,
        INFO_FLAG_CAPLINK_FRIEND_REQUEST = 32,
        INFO_FLAG_CAPLINK_FRIEND_CONSENT = 33,
        INFO_FLAG_CAPLINK_FRIEND_MODIFY = 34,
        INFO_FLAG_CAPLINK_INVITE = 35,
        INFO_FLAG_CAPLINK_NEW_CHAT = 36,
        INFO_FLAG_CAPLINK_MESSAGE = 37,
        INFO_FLAG_CAPLINK_MAINTENANCE = 38,
        INFO_FLAG_INVITE_ENTRY = 39,
        INFO_FLAG_NO_SITUATION = 40,
        INFO_FLAG_DLC_NOT_RECEIVE = 41,
        INFO_FLAG_MAX = 42,
        INFO_FLAG_NONE = -1,
    };
    enum BROWSER_GUIDE
    {
        BROWSER_GUIDE_CLOSE = 0,
        BROWSER_GUIDE_CHANGE_FOCUS_RETURN = 1,
        BROWSER_GUIDE_NUM = 2,
    };
    enum ANNOUNCE_TYPE
    {
        ANNOUNCE_TYPE_NONE = 0,
        ANNOUNCE_TYPE_TUTORIAL = 1,
        ANNOUNCE_TYPE_ENTRY_BOARD = 2,
        ANNOUNCE_TYPE_QUICK_PARTY = 3,
        ANNOUNCE_TYPE_INVITE = 4,
        ANNOUNCE_TYPE_INVITE_MEMBER = 5,
        ANNOUNCE_TYPE_INVITE_ENTRY = 6,
    };
    enum DL_STATE
    {
        NOW_STANDBY = 0,
        NOW_DOWNLOAD = 1,
    };
    enum RET_ITEMCBF
    {
        RET_ITEMCBF_ON = 0,
        RET_ITEMCBF_OFF = 1,
        RET_ITEMCBF_NONE = 2,
    };
    enum MENUIF
    {
        MENUIF_NONE = 0,
        MENUIF_GAMEMENU = 1,
        MENUIF_SCM = 2,
        MENUIF_CHATACTIVE = 4,
        MENUIF_NPCTALK = 8,
        MENUIF_ERRDIALOG = 16,
        MENUIF_ANYMENU = 32,
        MENUIF_DEAD = 64,
        MENUIF_PAWNREVIVE = 128,
        MENUIF_RESULT = 256,
        MENUIF_PHOTO = 512,
        MENUIF_MAP_L = 1024,
        MENUIF_OUTOFGAME = 2048,
        MENUIF_RIMWARP = 4096,
        MENUIF_LOADING = 8192,
        MENUIF_NUMBOX_EDIT = 16384,
        MENUIF_FORCE_DWORD = -1,
    };
    enum SPUIF
    {
        SPUIF_NONE = 0,
        SPUIF_DOGMAORB = 1,
        SPUIF_CRAFT = 2,
        SPUIF_OPTION = 4,
        SPUIF_KEYCONFIG_INPUT = 8,
        SPUIF_FORCE_DWORD = -1,
    };
    enum GUITMP_FLAG
    {
        GUITMP_FLAG_PL_RETSAFEPOS = 0,
        GUITMP_FLAG_CAMERA_ZRESET_OFF = 1,
        GUITMP_FLAG_NUM = 2,
    };
    enum HIDE_EQUIP_TYPE
    {
        HIDE_EQUIP_TYPE_PL_HEAD = 0,
        HIDE_EQUIP_TYPE_PL_LANTERN = 1,
        HIDE_EQUIP_TYPE_PAWN_HEAD = 2,
        HIDE_EQUIP_TYPE_PAWN_LANTERN = 3,
        HIDE_EQUIP_TYPE_NUM = 4,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
    };
    enum
    {
        GAININFOTYPE_EXP = 0,
        GAININFOTYPE_MONEY = 1,
        GAININFOTYPE_RIM = 2,
        GAININFOTYPE_BO = 3,
        GAININFOTYPE_GP = 4,
        GAININFOTYPE_TICKET = 5,
        GAININFOTYPE_SUPPORT = 6,
        GAININFOTYPE_PP = 7,
        GAININFOTYPE_MAX = 8,
    };
    enum
    {
        ICONFONT_PAD = 0,
        ICONFONT_KB = 1,
    };
    enum
    {
        PRIOGRP_LOW = 0,
        PRIOGRP_HEADER_NPC = 1,
        PRIOGRP_HEADER_EM = 2,
        PRIOGRP_HEADER_CV = 3,
        PRIOGRP_HEADER_PT = 4,
        PRIOGRP_ANNOUNCE_LOW = 5,
        PRIOGRP_ANNOUNCE_HIGH = 6,
        PRIOGRP_HUD = 7,
        PRIOGRP_MAPMINI = 8,
        PRIOGRP_VARIABLE = 9,
        PRIOGRP_MENU_LOW = 10,
        PRIOGRP_MENU = 11,
        PRIOGRP_HIGH = 12,
        PRIOGRP_POINTER = 13,
        PRIOGRP_ONFADE = 14,
        PRIOGRP_NET_INDICATOR = 15,
        PRIOGRP_ERROR = 16,
        PRIOGRP_DBGRECT = 17,
        PRIOGRP_DBGPRINT = 18,
        PRIOGRP_MOUSEPOINTER = 19,
        PRIOGRP_MAX = 20,
    };
    enum
    {
        PRIO_BOTTOM = 0,
        PRIO_BOTTOM_TOP = 1,
        PRIO_LOW = 1,
        PRIO_LOW_TOP = 11,
        PRIO_HEADER_NPC = 11,
        PRIO_HEADER_NPC_TOP = 139,
        PRIO_HEADER_EM = 139,
        PRIO_HEADER_EM_TOP = 171,
        PRIO_HEADER_CV = 171,
        PRIO_HEADER_CV_TOP = 175,
        PRIO_HEADER_PT = 175,
        PRIO_HEADER_PT_TOP = 191,
        PRIO_ANNOUNCE_LOW = 191,
        PRIO_ANNOUNCE_LOW_TOP = 195,
        PRIO_ANNOUNCE_HIGH = 195,
        PRIO_ANNOUNCE_HIGH_TOP = 199,
        PRIO_HUD = 199,
        PRIO_HUD_TOP = 263,
        PRIO_MAPMINI = 263,
        PRIO_MAPMINI_TOP = 267,
        PRIO_VARIABLE = 267,
        PRIO_VARIABLE_TOP = 271,
        PRIO_MENU_LOW = 271,
        PRIO_MENU_LOW_TOP = 287,
        PRIO_MENU = 287,
        PRIO_MENU_TOP = 311,
        PRIO_HIGH = 311,
        PRIO_HIGH_TOP = 343,
        PRIO_POINTER = 343,
        PRIO_POINTER_TOP = 347,
        PRIO_ONFADE = 347,
        PRIO_ONFADE_TOP = 379,
        PRIO_NET_INDICATOR = 379,
        PRIO_NET_INDICATOR_TOP = 383,
        PRIO_ERROR = 383,
        PRIO_ERROR_TOP = 387,
        PRIO_DBGRECT = 387,
        PRIO_DBGRECT_TOP = 391,
        PRIO_DBGPRINT = 391,
        PRIO_DBGPRINT_TOP = 395,
        PRIO_MOUSEPOINTER = 395,
        PRIO_MOUSEPOINTER_TOP = 399,
        PRIO_TOP = 400,
        PRIOHANDLE_MAX = 400,
        PRIO_OVER_SCREEN_SPACE = 27000,
    };
    enum
    {
        ITEMCBF_NONE = 0,
        ITEMCBF_USE = 1,
        ITEMCBF_DELETE = 2,
        ITEMCBF_MOVE = 4,
        ITEMCBF_GET = 8,
        ITEMCBF_ORB_HP = 16,
        ITEMCBF_ORB_ST = 32,
        ITEMCBF_ORB_LT = 64,
        ITEMCBF_ORB_AB = 128,
        ITEMCBF_REWARD = 256,
        ITEMCBF_SUPPLIES = 512,
        ITEMCBF_JOB = 1024,
        ITEMCBF_EXCHANGE = 2048,
        ITEMCBF_SELL = 4096,
        ITEMCBF_BUY = 8192,
    };
    enum
    {
        SETYPE_CMN = 0,
        SETYPE_CRAFT = 1,
        SETYPE_GACHA = 2,
        SETYPE_PP = 3,
    };
    enum REQ_POINTER_GUIDE_TYPE
    {
        REQ_POINTER_GUIDE_TYPE_NONE = 0,
        REQ_POINTER_GUIDE_TYPE_SET = 1,
        REQ_POINTER_GUIDE_TYPE_CLEAR = 2,
    };
    enum
    {
        PTR_DIALOG = 0,
        PTR_CHATMENU = 1,
        PTR_CHAT = 2,
        PTR_CMN07 = 3,
        PTR_CMN06 = 4,
        PTR_CMN05 = 5,
        PTR_CMN04 = 6,
        PTR_CMN03 = 7,
        PTR_CMN02 = 8,
        PTR_CMN01 = 9,
        PTR_CMN00 = 10,
        PTR_NUM = 11,
        PTR_INVALID = 11,
    };
    enum
    {
        DISP_REWARD_ITEM_NUM = 5,
    };
    enum
    {
        TCO_TYPE_ENEMY = 0,
    };
public:
    class MyDTI;
    struct stGatheringData;
    class cMousePointer;
    struct stSendItemParam;
    struct requestPointerGuide;
    class cPrioHandle;
    struct stScreenAdjustPos;
    struct stDbgIndicatorWork;
    struct stPlayerIdling;
    class cRatingEmoteInfo;
    struct stOnlineStatusAFK;
    struct stServerOption;
    class cChat;
    class cSEPlayer;
    class cAnnounceQueue;
    struct stInfomation;
    struct SHOPTITLE_TYPE;
    class cDivItemIcon;
    struct stQueueAnnounce;
    struct stRewardItem;
    struct stGainInfoQueue;
    class cMap;
    class cSCM;
    class cChatMacro;
    class cJpegDecode;
    struct stChangeEquipInfo;
    class cLifeGaugeWork;
    class cWardInfo;
    class cSameWardInfo;
    class cReplaceWardMap;
    class cDlTicket;
    struct stSystemMsg;
    class cItemTmp;
    class cDialog;
public:
    using cItemListTmp = MtTypedArray<cItemParam>;
    using AnnounceString = MtStringEx<256>;
    using ClanEmblemMarkArcNameString = MtStringEx<64>;
    using cNgWard = MtTypedArray<sGUIExt::cWardInfo>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stGatheringData
    {
    public:
        stGatheringData();
    public:
        sItemManager::cItemBag::cGatheringItemData mGatherData;  // offset: 0x0
        GatheringItemGetRequestVec mOmSendList;  // offset: 0x18
        bool mUse;  // offset: 0x38
        MtObject* mpWho;  // offset: 0x40
    };
public:
    class cMousePointer : public MtObject
    {
    public:
        enum
        {
            MSG_NONE = 0,
            MSG_LCLICK = 1,
            MSG_RCLICK = 2,
            MSG_MCLICK = 4,
            MSG_DBLCLICK = 8,
            MSG_LDRAG = 16,
            MSG_RDRAG = 32,
            MSG_MDRAG = 64,
            MSG_LDROP = 128,
            MSG_RDROP = 256,
            MSG_MDROP = 512,
            MSG_LDRAG_TRG = 1024,
            MSG_RDRAG_TRG = 2048,
            MSG_MDRAG_TRG = 4096,
            MSG_WHEEL_FORWARD = 8192,
            MSG_WHEEL_BACK = 16384,
        };
        enum
        {
            ANMTYPE_NONE = 0,
            ANMTYPE_POINT = 1,
            ANMTYPE_OPENHAND = 2,
            ANMTYPE_GRAB = 3,
            ANMTYPE_TALK = 4,
            ANMTYPE_INPUT = 5,
            ANMTYPE_HIDE = 6,
            ANMTYPE_MAX = 7,
        };
        enum
        {
            MOTYPE_NONE = 0,
            MOTYPE_RECT = 1,
        };
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
        cMousePointer();
        virtual ~cMousePointer();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void move();
        void createGUI();
        void deleteGUI();
        bool isEnable();
        MtVector3 getPos();
        MtVector3 getPosOld();
        MtVector3 getPosDrag();
        u32 getMsg();
        MtVector2 getMove();
        s32 getAxisZ();
        void setAnmTypeReq(u32 uAnmType, u32 uPrio);
        void setMouseMode(bool);
        bool isMouseMode();
        bool isActiveMouse();
        void reqMouseOverCursor(MtRect rect, u32 uType);
        void beginMouseOverCursor();
    private:
        uGUIMousePointer* mpGUI;  // offset: 0x8
        uGUIMouseOverCursor* mpGUIMOC;  // offset: 0x10
        MtVector3 mPos;  // offset: 0x20
        MtVector3 mPosOld;  // offset: 0x30
        MtVector3 mPosDrag;  // offset: 0x40
        MtVector2 mMove;  // offset: 0x50
        u32 mMsg;  // offset: 0x58
        u32 mMsgDragRev;  // offset: 0x5c
        f32 mTimeDisable;  // offset: 0x60
        f32 mTimeDblClick;  // offset: 0x64
        u32 mAnmTypeReq;  // offset: 0x68
        u32 mAnmTypeReqPrio;  // offset: 0x6c
        bool mIsMouseMode;  // offset: 0x70
        bool mIsActiveMouse;  // offset: 0x71
    public:
        static MyDTI DTI;
        static const u32 DISABLE_TIME = 300;
        static const u32 DBLCLICK_TIME = 30;
        static const u32 DIST_MOUSEMOVE = 16;
        static const u32 ANMTYPEREQPRIO_EDITSLIDER = 4294967292;
        static const u32 ANMTYPEREQPRIO_SCRBAR = 4294967293;
        static const u32 ANMTYPEREQPRIO_WNDWDRAG = 4294967294;
        static const u32 ANMTYPEREQPRIO_MAX = 4294967295;
        static const s32 MAP_CURSOR_OFFSET = 20;
    };
public:
    struct stSendItemParam
    {
    public:
        stSendItemParam();
    public:
        cUnit* mpUnit;  // offset: 0x0
        nGUIItem::cItem mItem;  // offset: 0x8
        nGUIItem::cItem mTmpItem;  // offset: 0x68
        nGUIItem::cItemList mTmpItemList;  // offset: 0xc8
    };
public:
    struct requestPointerGuide
    {
    public:
        cUnit* mpUnit;  // offset: 0x0
        u32 mType;  // offset: 0x8
        u32 mPrio;  // offset: 0xc
        u32 mDispPrio;  // offset: 0x10
        nKeyCustom::KB_CUSTOM mKeyCustom;  // offset: 0x14
        MtString mMsg;  // offset: 0x18
    };
public:
    class cPrioHandle : public MtObject
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
        cPrioHandle();
        virtual ~cPrioHandle();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void init();
    public:
        u32 mPrio;  // offset: 0x8
        f32 mDistCam;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    struct stScreenAdjustPos
    {
    public:
        stScreenAdjustPos();
    public:
        bool enableX;  // offset: 0x0
        bool enableY;  // offset: 0x1
        bool enableScale;  // offset: 0x2
        f32 overLen;  // offset: 0x4
    };
public:
    struct stDbgIndicatorWork
    {
    public:
        bool mVisible;  // offset: 0x0
        bool mVisibleOld;  // offset: 0x1
        bool mShowFps;  // offset: 0x2
        bool mShowAxis;  // offset: 0x3
        bool mShowProcessBar;  // offset: 0x4
        bool mShowCameraTarget;  // offset: 0x5
        bool mShowWorldPos;  // offset: 0x6
        bool mShowPad1;  // offset: 0x7
        bool mShowPad2;  // offset: 0x8
        bool mShowMemory;  // offset: 0x9
        bool mShowLoadingInfo;  // offset: 0xa
        bool mShowBuildVersion;  // offset: 0xb
        bool mShowScrCollisionProfile;  // offset: 0xc
        bool mShowPerfGraph;  // offset: 0xd
        bool mGUIDbgPrintVisible;  // offset: 0xe
        bool mGUIDbgRectVisible;  // offset: 0xf
    };
public:
    struct stPlayerIdling
    {
    public:
        f32 mCnt;  // offset: 0x0
    };
public:
    class cRatingEmoteInfo : public MtObject
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
        cRatingEmoteInfo(u32 EmoteNum);
        // Address: 0x01ac4d80 - 0x01ac4d81 (1 bytes)
        virtual ~cRatingEmoteInfo() {}
    private:
        cRatingEmoteInfo();
    public:
        u32 getEmoteNum();
    private:
        u32 mEmoteNum;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    struct stOnlineStatusAFK
    {
    public:
        bool mIsAutoAFK;  // offset: 0x0
        f32 mTimerToAutoAFK;  // offset: 0x4
        f32 mOldRemainTime;  // offset: 0x8
    };
public:
    struct stServerOption
    {
    public:
        bool mIsStart;  // offset: 0x0
        bool mIsDispHeadArmorPl;  // offset: 0x1
        bool mIsDispHeadArmorPawn;  // offset: 0x2
        bool mIsDispLanternPl;  // offset: 0x3
        bool mIsDispLanternPawn;  // offset: 0x4
        bool mIsClanNtc;  // offset: 0x5
        f32 mTimer;  // offset: 0x8
    };
public:
    class cChat : public MtObject
    {
        // inferred: sGUIExt::isChatMenuUI names sGUIExt::mChat.mpGUIChat
        friend class sGUIExt;
    public:
        enum
        {
            CH_GENERAL = 0,
            CH_PARTY = 1,
            CH_CUSTOM0 = 2,
            CH_CUSTOM1 = 3,
            CH_MAX = 4,
        };
    public:
        class MyDTI;
        struct stChannel;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct stChannel
        {
        public:
            MT_CHAR mName[17];  // offset: 0x0
            u32 mFilterBit;  // offset: 0x14
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
        cChat();
        virtual ~cChat();
        uGUIChat* createGUI();
        void deleteGUI();
        void bootup();
        void finish();
        void noticeLogReset();
        bool noticeLogAdd(s32 sFiterGrp);
        bool isDefaultBoot();
        void setDefaultBoot(bool);
        s32 getChatArea();
        void setChatArea(s32 chatArea);
        stChannel& getCh(u32 uIdx);
        void deleteCh(u32 uIdx);
        void setCustomChToCharData();
        u32 getEnableChNum();
        MtVector4 getChFilterColorScale(u32 uType);
        u32 getChFilterSEId(u32 uType);
        u32 getCCFFromCFG(s32 sFilterType);
        MtVector4 getLogColorScale(s32 sFilterType);
        u32 getSEIdFromCFG(s32 sFilterType);
        uGUIChat* getGUIChat();
    private:
        bool mIsDefaultBoot;  // offset: 0x8
        s32 mChatArea;  // offset: 0xc
        stChannel mCh[4];  // offset: 0x10
        uGUIChat* mpGUIChat;  // offset: 0x70
    public:
        static MyDTI DTI;
        static const u32 NAME_LENGTH = 17;
        static const u32 CFCOLOR_NUM = 12;
        static const u32 CFSE_NUM = 9;
    };
public:
    class cSEPlayer : public MtObject
    {
        // inferred: uGUISystemMsg::evCtrlListCancel names uGUISystemMsg::mReserveSEList.elems[5].sound.mpRes
        friend class uGUISystemMsg;
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
        cSEPlayer();
        virtual ~cSEPlayer();
        void play(u32 id);
        void set(rSoundRequest* pRes);
        rSoundRequest* get();
    private:
        rSoundRequest* mpRes;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class cAnnounceQueue
    {
    public:
        cAnnounceQueue();
        void clear();
        bool checkSameMsg(MT_CTSTR pMsg, MT_CTSTR pAnalyze0, MT_CTSTR pAnalyze1, u32 AnalyzeNum0, u32 AnalyzeNum1) const;
    public:
        sGUIExt::AnnounceString mMsg;  // offset: 0x0
        MtStringEx<64> mAnalyzerMsg[2];  // offset: 0x104
        u32 mAnalyzerNum[2];  // offset: 0x18c
        sGUIExt::cAnnounceQueue* mpNext;  // offset: 0x198
        u32 mColorType;  // offset: 0x1a0
        bool mIsUse;  // offset: 0x1a4
        bool mIsAnalyze;  // offset: 0x1a5
    };
public:
    struct stInfomation
    {
    public:
        stInfomation();
        void reset();
    public:
        sGUIExt::stInfomation* mpNext;  // offset: 0x0
        sGUIExt::INFO_FLAG mFlag;  // offset: 0x8
        MtString mMsg;  // offset: 0x10
        MtString mAnalyzerMsg[2];  // offset: 0x18
        bool mIsUse;  // offset: 0x28
        bool mIsAnalyze;  // offset: 0x29
    };
public:
    struct SHOPTITLE_TYPE
    {
    public:
        enum Type
        {
            NODISP = 0,
            GOLD = 1,
            RIM = 2,
            DOGMAORB = 3,
            GP_CT = 4,
            RIM_SP = 5,
            PP = 6,
            CLAN_POINT = 7,
            NUM = 8,
        };
        enum TitleType
        {
            SHOP = 0,
            ORB_SHOP = 1,
            AREA_MASTER = 2,
            JOB_MASTER = 3,
            REVIVAL_RECOVER = 4,
            BEAUTY_PARLOR = 5,
            PARTY_SUPPORT = 6,
            ARTS_SUPPORT = 7,
            CRAFT = 8,
            CLAN = 9,
            DELIVERY = 10,
            CYCLE_CONTENTS = 11,
            WAREHOUSE = 12,
            INN = 13,
            BAZAAR = 14,
            RIM_STONE = 15,
            GACHA = 16,
            QUEST_BOARD = 17,
            END_CONTENTS = 18,
            APPRAISE = 19,
            DEPOSITBOX = 20,
            PLAYPOINT = 21,
            CLAN_BASE = 22,
            CLAN_QUEST_BOARD = 23,
            CLAN_END_CONTENTS = 24,
            TITLE_TYPE_NUM = 25,
        };
    };
public:
    class cDivItemIcon : public MtObject
    {
    public:
        enum
        {
            RNO_INIT = 0,
            RNO_LOAD_ITEMBAG = 1,
            RNO_MOVE = 2,
            RNO_DBG_LOADALL = 3,
        };
    public:
        class MyDTI;
        class cItemIcon;
        class cAutoCriticalSection;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cItemIcon : public MtObject
        {
        public:
            cItemIcon();
            virtual ~cItemIcon();
            void init();
            void reset(bool bChkInBag);
            void loadArchive(u32 uIconNo);
            void loadTexture();
            void release();
            bool isBagItemIcon();
        public:
            rTexture* mpTexture;  // offset: 0x8
            TICKET mArcTicketTex;  // offset: 0x10
            u32 mIconNo;  // offset: 0x18
            u8 mRefCount;  // offset: 0x1c
            bool mEnable;  // offset: 0x1d
            bool mIsLoading;  // offset: 0x1e
        };
    public:
        class cAutoCriticalSection
        {
        public:
            cAutoCriticalSection(sGUIExt::cDivItemIcon* p);
            ~cAutoCriticalSection();
        public:
            sGUIExt::cDivItemIcon* mpDivItemIcon;  // offset: 0x0
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
        cDivItemIcon();
        virtual ~cDivItemIcon();
        void move();
        void clear();
        rTexture* getItemIconTex(u32 uIconNo, u32& uIdx);
        void releaseItemIconTex(u32 uIconNo, u32& uIdx);
        void setRno(u32 uRno);
        u32 getRno();
    private:
        void lock();
        void unlock();
    public:
        cItemIcon mItemIcon[128];  // offset: 0x8
        MtTypedArray<cItemIcon> mLoadingItemIcon;  // offset: 0x1008
    private:
        u32 mRno;  // offset: 0x1028
        MtCriticalSection mCS;  // offset: 0x1030
    public:
        static MyDTI DTI;
        static const u32 ICONNO_INVALID = 80;
    };
public:
    struct stRewardItem
    {
    public:
        stRewardItem();
    public:
        bool mIsCharge;  // offset: 0x0
        u32 mItemNum;  // offset: 0x4
        u32 mItemNo;  // offset: 0x8
    };
public:
    struct stGainInfoQueue
    {
    public:
        bool mEnable;  // offset: 0x0
        u32 mType;  // offset: 0x4
        s32 mData0;  // offset: 0x8
        s32 mData1;  // offset: 0xc
    };
public:
    class cMap : public MtObject
    {
        // inferred: sGUIExt::getMapModeMini names sGUIExt::mMap.mModeMini
        friend class sGUIExt;
    public:
        enum
        {
            RNO0_INIT = 0,
            RNO0_REQLOADFLOOR = 1,
            RNO0_CREATEFLOOR = 2,
            RNO0_CREATEGRID = 3,
            RNO0_STARTLOAD = 4,
            RNO0_LOAD = 5,
            RNO0_MOVE = 6,
        };
        enum
        {
            MAPTYPE_CURRENT = 0,
            MAPTYPE_FIELD = 1,
            MAPTYPE_WFIELD = 2,
            MAPTYPE_TGTSTG = 3,
            MAPTYPE_MAX = 4,
        };
        enum
        {
            GRIDTYPE_NORMAL = 0,
            GRIDTYPE_PARTS = 1,
            GRIDTYPE_MAX = 2,
        };
        enum
        {
            MODEMINI_S = 0,
            MODEMINI_L = 1,
            MODEMINI_NDISP = 2,
            MODEMINI_MAX = 3,
        };
        enum
        {
            RNO2_MSD_SEARCH_FILE = 0,
            RNO2_MSD_ARC_LOAD = 1,
            RNO2_MSD_WAIT = 2,
        };
        enum
        {
            LAND_FIRST = 1,
            LAND_RESTANIA = 1,
            LAND_ISLAND = 2,
            LAND_FINDAM = 3,
            LAND_MAX = 4,
            LAND_NUM = 3,
        };
    public:
        class MyDTI;
        class cMapGrid;
        class cMarkerSave;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cMapGrid : public MtObject
        {
        public:
            cMapGrid();
            virtual ~cMapGrid();
            void init();
        public:
            bool mEnable;  // offset: 0x8
            MtString mArcPath;  // offset: 0x10
            u32 mParts;  // offset: 0x18
            u32 mRows;  // offset: 0x1c
            u32 mCols;  // offset: 0x20
            u32 mFloor;  // offset: 0x24
            s32 mFloorBase;  // offset: 0x28
            s32 mFloorRef;  // offset: 0x2c
            u32 mRowsMax;  // offset: 0x30
            u32 mColsMax;  // offset: 0x34
            s32 mFloorGroupNo;  // offset: 0x38
            MtVector2 mOfs;  // offset: 0x40
            TICKET mArcTicketTex;  // offset: 0x48
            rTexture* mpTexture;  // offset: 0x50
            rFieldMapData* mpFmd;  // offset: 0x58
        };
    public:
        class cMarkerSave : public MtObject
        {
        public:
            enum
            {
                MARKER_SAVE_INIT = 0,
                MARKER_SAVE_MOVE = 1,
                MARKER_SAVE_END = 2,
                MARKER_SAVE_MODE_NUM = 3,
            };
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
            cMarkerSave();
            virtual ~cMarkerSave();
            void update();
            void action();
        public:
            MtVector3 mPos;  // offset: 0x10
            f32 mTimeCount;  // offset: 0x20
            f32 mEndTime;  // offset: 0x24
            f32 mRange;  // offset: 0x28
            f32 mHeight;  // offset: 0x2c
            u32 mID;  // offset: 0x30
            u32 mMode;  // offset: 0x34
            u32 mIcon;  // offset: 0x38
            s32 mMarkerType;  // offset: 0x3c
            s32 mSE_ID;  // offset: 0x40
            static MyDTI DTI;
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
        cMap();
        virtual ~cMap();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void move();
        void updateQuestMarkerList();
        void updateFreeMarker();
        void updateMapDispPosition();
        void updateMapData();
        void finalGame();
        MtVector2 getMapPos(const MtVector3& vPos, f32 fScale, f32 fRot, bool notCast);
        MtVector3 getRealPos(const MtVector2& vPos, f32 fScale, f32 fRot);
        MtVector2 getPos2SetQuestHintDiscoveredOfs(u32 uSdlId, bool bField);
        u32 getGridIdx(u32 uRows, u32 uCols, s32 sFloor);
        rTexture* getGridTexture(u32 uIdx);
        cMapGrid* getGrid(u32 uIdx);
        bool isFieldMap();
        bool isFieldMapOnCurrent();
        bool isFieldMapInNotField();
        bool checkReload();
        s32 getStageNoDisplayedMap();
        u32 getMapGridLength();
        void setGUIMap(uGUIMap* pGUIMap);
        uGUIMap* getGUIMap();
        rMapSpotData* getMSData() const;
        void setPosCenter(const MtVector3&);
        MtVector3 getPosCenter();
        void setPosFocus(const MtVector3& vPos);
        MtVector3 getPosFocus();
        void setPos2Center(const MtVector2&);
        MtVector2 getPos2Center();
        void setPos2CenterOfs(const MtVector2&);
        MtVector2 getPos2CenterOfs();
        void setPos2CenterMenuOfs(const MtVector2&);
        MtVector2 getPos2CenterMenuOfs();
        void setPos2CenterMenuOfsReq(const MtVector2& vPos);
        MtVector2 getPos2CenterMenuOfsReq();
        void setMapType(u32 uType);
        u32 getMapType();
        void setMapLandType(s32);
        s32 getMapLandType();
        void setGridType(u32);
        u32 getGridType();
        void setTargetStage(u32 uTargetStage);
        u32 getTargetStage();
        void setModeMini(u32 uMode);
        u32 getModeMini();
        void setTypeIconFilter(u32);
        u32 getTypeIconFilter();
        void setVisibleMask(bool bVisible);
        bool isVisibleMask();
        void setAlpha(u32);
        u32 getAlpha();
        bool isUseAlpha();
        void setRno(u32);
        u32 getRno();
        void setRno0(u8 uRno);
        u8 getRno0();
        void setRno1(u8);
        u8 getRno1();
        void setRno2(u8);
        u8 getRno2();
        void setRno3(u8);
        u8 getRno3();
        void setUsageStage(bool bFlag);
        bool isUsageStage();
        void setFollowPlPos(bool bFlag);
        bool isFollowPlPos();
        void setStayPlPos(bool bFlag);
        bool isStayPlPos();
        void setTexReleaseWait(bool bFlag);
        bool isTexReleaseWait();
        void setWorldOfsUpd(bool bFlag);
        bool isWorldOfsUpd();
        void setCtrlMap(bool bFlag);
        bool isCtrlMap();
        void reqSendFreeMarker();
        void reqSendReservFreeMarkerIdx(u32 idx);
        void reqSendReservFreeMarkerAll();
        void clearSendReservFreeMarkerIdx();
        u32 getSendReservFreeMarkerNum();
        bool isReqSendReservFreeMarkerIdx(u32 idx);
        void setEditFreeMarkerIdx(u32 idx);
        u32 getEditFreeMarkerIdx();
        void setPosFocusEnable(bool bEnable, bool bKeep);
        void setMapWindowSize(const MtFloat2& size);
        MtFloat2 getMapWindowSize();
        void setMapWindowPos(const MtFloat2& pos);
        MtFloat2 getMapWindowPos();
        void setDragMap(const bool drag);
        bool isDragMap();
        void setMapZoomRate(f32 rate);
        u32 getVisibleTreasureDistance();
        u32 getVisibleTreasureDistanceField();
        void setUpdateQuestMarker(bool flg);
        bool isUpdateQuestMarker();
        void setReloadForce(bool flg);
        cGUIFloorManager* getFloorManager();
        s32 getFloorId();
        s32 getFloorIdFromPos(const MtVector3& vPos, s32& groupNo);
        u32 getPartsIdFromPos(const MtVector3& vPos);
        s32 getFloorIdTgtstg(s32 floorId);
        s32 getQuestMarkerIndexFromSdlId(u32 sdlId);
        void setQuestFocus(u32 uSdlId, bool bKeep);
        u32 getSdlIdQstFocus();
        u32 getSdlIdQstFocusAreaMaster();
        bool isReloadGridMapTex(bool erase);
        bool isLoadingFloor();
        bool isMouseCtrlMiniMap();
        bool isMouseCtrlMenuMap();
        MtVector3 getPosPLFreeMarker(u32 idx);
        void setPosPLFreeMarker(const MtVector3& vPos, u32 idx);
        s32 getStageNoPLFreeMarker(u32 idx);
        void setStageNoPLFreeMarker(s32 sStageNo, u32 idx);
        s32 getGroupNoPLFreeMarker(u32 idx);
        void setGroupNoPLFreeMarker(s32 sGroupNo, u32 idx);
        void setIsThereLeader(bool flg, u32 idx);
        bool isThereLeader(u32 idx);
        MtSize getSizeS();
        MtSize getSizeL();
        MtSize getSizeMenu();
        bool isQuestHintIcon(u32 scheduleId, s32 questStageNo);
        bool isEnableQuestHintIcon(u32 scheduleId, s32 questStageNo);
        void updateAllMarkerSave();
        bool addMarkerSave(cMarkerSave* addMarker);
        void actionMarkerSaveByIndex(u32 Idx);
        const cMarkerSave* getMarkerSaveFromIdx(u32 Idx);
        s32 getMarkerSaveIndex(u32 uID, s32 type);
        u32 getMarkerSaveArrayLength() const;
    private:
        void deleteMapGrid();
        bool createFloorNormal();
        bool createFloorParts();
        void createGridNormal();
        void createGridParts();
        void loadTextureNormal();
        void loadTextureParts();
        MtVector3 getAdjoinInfoPos(s32 sStageNo);
        bool getMapFilePath(MtString& path);
        void updateMSDate();
        void releaseMSData();
        void checkMapCtrl();
    private:
        MtTypedArray<cMapGrid> mMapGrid;  // offset: 0x8
        MtTypedArray<cMarkerSave> mMarkerSaveArray;  // offset: 0x28
        uGUIMap* mpGUIMap;  // offset: 0x48
        rMapSpotData* mpMSData;  // offset: 0x50
        MtVector3 mPosCenter;  // offset: 0x60
        MtVector3 mPosFocus;  // offset: 0x70
        MtVector3 mPosPLFreeMarker[3];  // offset: 0x80
        MtVector2 mPos2Center;  // offset: 0xb0
        MtVector2 mPos2CenterOfs;  // offset: 0xb8
        MtVector2 mPos2LoadCenter;  // offset: 0xc0
        MtVector2 mPos2CenterMenuOfs;  // offset: 0xc8
        MtVector2 mPos2CenterMenuOfsReq;  // offset: 0xd0
        MtVector2 mPos2CenterLimit;  // offset: 0xd8
        MtVector2 mPos2CenterStay;  // offset: 0xe0
        MtFloat2 mMapLimit;  // offset: 0xe8
        MtFloat2 mMapWndwSize;  // offset: 0xf0
        MtFloat2 mMapWndwPos;  // offset: 0xf8
        MtFloat2 mReloadDist;  // offset: 0x100
        MtSize mSizeS;  // offset: 0x108
        MtSize mSizeL;  // offset: 0x110
        MtSize mSizeMenu;  // offset: 0x118
        double mMapReducedRate;  // offset: 0x120
        double mFieldReducedRate;  // offset: 0x128
        double mFieldWReducedRate;  // offset: 0x130
        double mPartsReducedRate;  // offset: 0x138
        double mReducedScale;  // offset: 0x140
        f32 mDistLimit;  // offset: 0x148
        f32 mRateDistLimit;  // offset: 0x14c
        f32 mCntSendFreeMarker;  // offset: 0x150
        f32 mMapZoomRate;  // offset: 0x154
        f32 mMapZoomRateSave;  // offset: 0x158
        u32 mMapType;  // offset: 0x15c
        u32 mMapTypeOld;  // offset: 0x160
        s32 mMapLandType;  // offset: 0x164
        s32 mMapLandTypeOld;  // offset: 0x168
        s32 mMapLMWorldType;  // offset: 0x16c
        s32 mMapMSDataStage;  // offset: 0x170
        u32 mGridType;  // offset: 0x174
        u32 mTargetStage;  // offset: 0x178
        u32 mTargetStageOld;  // offset: 0x17c
        u32 mModeMini;  // offset: 0x180
        u32 mTypeIconFilter;  // offset: 0x184
        s32 mFloorIdOld;  // offset: 0x188
        u32 mSdlIdQstFocus;  // offset: 0x18c
        u32 mSdlIdQstFocusAreaMaster;  // offset: 0x190
        u32 mSpType;  // offset: 0x194
        u32 mEditFreeMarkerIdx;  // offset: 0x198
        s32 mStageNoPLFreeMarker[3];  // offset: 0x19c
        s32 mGroupNoPLFreeMarker[3];  // offset: 0x1a8
        bool mIsThereLeader[3];  // offset: 0x1b4
        bool mVisibleMask;  // offset: 0x1b7
        bool mIsReloadForce;  // offset: 0x1b8
        u32 mAlpha;  // offset: 0x1bc
        cArcLoader32 mArcLoader;  // offset: 0x1c0
        TICKET mArcTicketFloor;  // offset: 0x370
        bool mArcLoadEnd;  // offset: 0x378
        bool mIsTexReleaseWait;  // offset: 0x379
        bool mIsWorldOfsUpd;  // offset: 0x37a
        bool mIsWorldOfs;  // offset: 0x37b
        bool mIsCtrlMap;  // offset: 0x37c
        bool mIsReqSendFreeMarker;  // offset: 0x37d
        bool mIsKeepPosFocus;  // offset: 0x37e
        bool mIsPosFocus;  // offset: 0x37f
        bool mIsDragMap;  // offset: 0x380
        bool mIsReloadGridMapTex;  // offset: 0x381
        bool mIsBeforeCreateGrid;  // offset: 0x382
        bool mIsUpdateQuestMarker;  // offset: 0x383
        bool mIsReloadFloor;  // offset: 0x384
        TICKET mArcTicketLMField;  // offset: 0x388
        bool mArcLMFieldLoadEnd;  // offset: 0x390
        TICKET mArcTicketMSData;  // offset: 0x398
        bool mArcMSDataLoadEnd;  // offset: 0x3a0
        cGUIFloorManager* mpFloorManager;  // offset: 0x3a8
        u32 mVisibleTreasureDistance;  // offset: 0x3b0
        u32 mVisibleTreasureDistanceField;  // offset: 0x3b4
        union
        {
        public:
            struct
            {
            public:
                u8 mRno0;  // offset: 0x0
                u8 mRno1;  // offset: 0x1
                u8 mRno2;  // offset: 0x2
                u8 mRno3;  // offset: 0x3
            };  // offset: 0x0
            u32 mRno;  // offset: 0x0
        };  // offset: 0x3b8
        bool mIsUsageStage;  // offset: 0x3bc
        bool mIsFollowPlPos;  // offset: 0x3bd
        bool mIsStayPlPos;  // offset: 0x3be
        bool mIsSendReservFreeMarker[3];  // offset: 0x3bf
        bool mUseAlpha;  // offset: 0x3c2
    public:
        static MyDTI DTI;
        static const u32 FLOOR_MAX = 8;
        static const u32 GRIDROWS_NUM = 32;
        static const u32 GRIDCOLS_NUM = 32;
        static const u32 MAPGRID_MAX = 8192;
        static const u32 PATHBUF_MAX = 256;
        static const u32 TEXSIZE_NORMALD = 512;
        static const u32 TEXSIZE_PARTSD = 512;
        static const u32 METRETEX_NORMAL = 180;
        static const u32 METRETEX_FIELD = 570;
        static const u32 PRIMINST_NUM = 16;
        static const u32 PARTSD_MAX = 32;
        static const u32 INVALID_GRIDIDX = 4294967295;
        static const u32 RATE_WFIELD = 4;
        static const u32 FRM_SENDFREEMARKER = 150;
    };
public:
    class cSCM : public MtObject
    {
    public:
        enum
        {
            RNO0_INIT = 0,
            RNO0_WATCH = 1,
            RNO0_EXEC = 2,
        };
        enum
        {
            MODE_NONE = 0,
            MODE_SCM = 1,
            MODE_SCC = 2,
        };
        enum
        {
            DISPTYPEFKEYPLT_SCM = 0,
            DISPTYPEFKEYPLT_SCC = 1,
        };
        enum
        {
            SCMEDIT_STATE_NONE = 0,
            SCMEDIT_STATE_EDIT = 1,
            SCMEDIT_STATE_DELETE = 2,
            SCMEDIT_STATE_MAX = 3,
        };
    public:
        class MyDTI;
        struct stSCMEditData;
        struct stSCCEditData;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct stSCMEditData
        {
        public:
            u8 mType;  // offset: 0x0
            u32 mMsgId;  // offset: 0x4
            u32 mU32Data;  // offset: 0x8
            f32 mF32Data;  // offset: 0xc
            u8 mState;  // offset: 0x10
        };
    public:
        struct stSCCEditData
        {
        public:
            u8 mType;  // offset: 0x0
            u8 mCtgr;  // offset: 0x1
            u32 mId;  // offset: 0x4
            u8 mState;  // offset: 0x8
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
        cSCM();
        virtual ~cSCM();
        void move();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        static void setDefault(cCharacterData::SCM::stScmPltArrayList& dataScm, cCharacterData::SCM::stSccPltArrayList& dataScc);
        static void setPltDataSCM(cCharacterData::SCM::stScmPltArrayList& data, u32 uPageIdx, u32 uPltIdx, u32 uExecType, u32 uMenuId, u32 uU32Data, f32 fF32Data);
        static void setPltDataSCC(cCharacterData::SCM::stSccPltArrayList& data, u32 uPageIdx, u32 uPltIdx, u32 uExecType, u32 uCtgr, u32 uId);
        void reqMenuUI(u32 uMenuId);
        const MtDTI* getDtiFromMenuId(u32 uMenuId);
        void setEnable(bool bEnable);
        bool isEnable();
        bool isPlayerCSPlt();
        void setReqMenuIdSCM(u32);
        u32 getReqMenuIdSCM();
        void setMode(u32);
        u32 getMode();
        void setModeEdit(u32 uMode);
        u32 getModeEdit();
        void setCurrentPage(u32, u32);
        u32 getCurrentPage(u32 uMode);
        u32 getPageMax();
        void setRno(u32);
        u32 getRno();
        void setRno0(u8);
        u8 getRno0();
        void setRno1(u8);
        u8 getRno1();
        void setRno2(u8);
        u8 getRno2();
        void setRno3(u8);
        u8 getRno3();
        u32 getDispTypeFKeyPlt();
        void setCurrentSCMEditData(u8 uType, u32 uMsgId, u32 uU32Data, f32 fF32Data);
        const stSCMEditData* getSCMEditData(u32 uPage, u32 uKey);
        void setCurrentSCCEditData(u8 uType, u8 uCtgr, u32 uId);
        const stSCCEditData* getSCCEditData(u32 uPage, u32 uKey);
        nKeyCustom::KB_CUSTOM getSCMPadBtnType(u32 uId);
        nKeyCustom::KB_CUSTOM getSCCPadBtnType(u32 uId);
        bool isSCMDataEnable(u8 uType, u32 uMsgId, u32 uU32Data, f32 fF32Data);
        bool isSCCDataEnable(u8 uType, u8 uCtgr, u32 uId);
        void reqSaveToServerForce();
        void execSaveToServer();
        nKeyCustom::KB_CUSTOM getSCCKB(u32 uIdx);
        bool isEnableSCM();
    private:
        void execSCMPlt(u32 uPageIdx, u32 uBtnIdx, u32 uMode, bool bKB);
        void execSCCPlt(u32 uPageIdx, u32 uBtnIdx, u32 uMode, bool bKB);
        void execSCMPltWithTrgBtn();
        void execSCCPltWithTrgBtn();
        void execSCMPltWithKB();
        void execSCCPltWithKB();
        bool execShortcutMenuWithKB();
    public:
        void setSCMEditDataDefault();
    private:
        void saveSCMEditData();
        void setSCMEditDataCurrent(u32 uPage, u32 uKey, bool bKB);
    public:
        void setSCCEditDataDefault();
    private:
        void saveSCCEditData();
        void setSCCEditDataCurrent(u32 uPage, u32 uKey, bool bKB);
    private:
        bool mEnable;  // offset: 0x8
        bool mEnableSCM;  // offset: 0x9
        bool mEnableSCC;  // offset: 0xa
        bool mIsPlayerCSPlt;  // offset: 0xb
        bool mIsReqSaveSCMToServer;  // offset: 0xc
        bool mIsReqSaveSCCToServer;  // offset: 0xd
        f32 mSecSaveSCMToServer;  // offset: 0x10
        f32 mSecSaveSCCToServer;  // offset: 0x14
        u32 mMode;  // offset: 0x18
        u32 mModeEdit;  // offset: 0x1c
        u32 mSCMCurrentPage;  // offset: 0x20
        u32 mSCMOldPage;  // offset: 0x24
        u32 mSCCCurrentPage;  // offset: 0x28
        u32 mSCCOldPage;  // offset: 0x2c
        u32 mReqMenuIdSCM;  // offset: 0x30
        u32 mDispTypeFKeyPlt;  // offset: 0x34
        stSCMEditData mCurrentSCMEditData;  // offset: 0x38
        stSCMEditData mSCMEditData[3][4];  // offset: 0x4c
        stSCCEditData mCurrentSCCEditData;  // offset: 0x13c
        stSCCEditData mSCCEditData[3][8];  // offset: 0x148
        ShortCutVec listSCMSaveToServer;  // offset: 0x268
        CommunicationShortCutVec listSCCSaveToServer;  // offset: 0x288
        union
        {
        public:
            struct
            {
            public:
                u8 mRno0;  // offset: 0x0
                u8 mRno1;  // offset: 0x1
                u8 mRno2;  // offset: 0x2
                u8 mRno3;  // offset: 0x3
            };  // offset: 0x0
            u32 mRno;  // offset: 0x0
        };  // offset: 0x2a8
    public:
        static MyDTI DTI;
        static const s32 SCM_SEC_REQSAVETOSERVER = 20;
        static const u32 KB_SCC = 18;
    };
public:
    class cChatMacro : public MtObject
    {
    public:
        enum
        {
            CMD_NONE = 0,
            CMD_LOGOUT = 1,
            CMD_INVITE = 2,
        };
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
        cChatMacro();
        virtual ~cChatMacro();
        bool exec(MT_CTSTR pMsgSrc);
        u32 analyzeCmdPart(MT_CHAR* pMsgSrc, MT_CHAR* pMsgArg, u32 uMode);
        void setChatErrorCmd();
        void setCmdF(u32);
        void orCmdF(u32 uFlag);
        void xorCmdF(u32);
        void clrCmdF(u32 uFlag);
        bool isCmdF(u32 uFlag);
        u32 getCmdF();
        bool cmdCHAT_AD(MT_CHAR* pMsgSrc, s32 sChatArea);
        bool cmdEMOT(MT_CHAR* pMsgSrc, u32 uIdx);
        bool cmdNONE(MT_CHAR* pMsgSrc);
        bool cmdHELP(MT_CHAR* pMsgSrc);
        bool cmdLOGOUT(MT_CHAR* pMsgSrc);
        bool cmdINVITE(MT_CHAR* pMsgSrc);
        bool cmdCHAT_AD_SAY(MT_CHAR* pMsgSrc);
        bool cmdCHAT_AD_SHOUT(MT_CHAR* pMsgSrc);
        bool cmdCHAT_AD_PARTY(MT_CHAR* pMsgSrc);
        bool cmdCHAT_AD_TELL(MT_CHAR* pMsgSrc);
        bool cmdCHAT_AD_CLAN(MT_CHAR* pMsgSrc);
        bool cmdCHAT_AD_GROUP(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0000(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0001(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0002(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0003(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0004(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0005(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0006(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0007(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0008(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0009(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0010(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0011(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0012(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0013(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0014(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0015(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0016(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0017(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0018(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0019(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0020(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0021(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0022(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0023(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0024(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0025(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0026(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0027(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0028(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0029(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0030(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0031(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0032(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0033(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0034(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0035(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0036(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0037(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0038(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0039(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0040(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0041(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0042(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0043(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0044(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0045(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0046(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0047(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0048(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0049(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0050(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0051(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0052(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0053(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0054(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0055(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0056(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0057(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0058(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0059(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0060(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0061(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0062(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0063(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0064(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0065(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0066(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0067(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0068(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0069(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0070(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0071(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0072(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0073(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0074(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0075(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0076(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0077(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0078(MT_CHAR* pMsgSrc);
        bool cmdEMOT_0079(MT_CHAR* pMsgSrc);
    public:
        MtTypedArray<cTbl2ChatMacro> mTblData;  // offset: 0x8
        bool(sGUIExt::cChatMacro::*execCmd[100])(MT_CHAR*);  // offset: 0x28
        MT_CHAR mSrcStr[255];  // offset: 0x668
        MtString mDstStrChatMacro;  // offset: 0x768
        MT_CHAR* mpArgStr;  // offset: 0x770
        u32 mCmdNum;  // offset: 0x778
        u32 mCmdF;  // offset: 0x77c
        static MyDTI DTI;
        static const u32 CMDMSG_LEN = 255;
        static const u32 CMDNUM_MAX = 100;
    };
public:
    class cJpegDecode : private MtObject
    {
    public:
        class MyDTI;
        class cDecodeSet;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cDecodeSet
        {
        public:
            cDecodeSet();
            ~cDecodeSet();
        public:
            rTextureJpeg* mpTex;  // offset: 0x0
            JOBHANDLE mJobHandle;  // offset: 0x8
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
        cJpegDecode();
        virtual ~cJpegDecode();
        void move();
        s32 requestDecode(void* pJpegBuff, u32 buffSize, rTextureJpeg* & jpegTexture, JOBHANDLE& jobHandle);
    private:
        void lock();
        void unlock();
    private:
        MtCriticalSection mCS;  // offset: 0x8
        nDDOUtility::cArray<cDecodeSet, 16> mDecodeArray;  // offset: 0x10
    public:
        static MyDTI DTI;
    private:
        static const u32 JPEG_ARRAY_MAX_SIZE = 16;
    };
public:
    struct stChangeEquipInfo
    {
    public:
        cItemParam* mpItemParam;  // offset: 0x0
        bool mIsRemove;  // offset: 0x8
    };
public:
    class cLifeGaugeWork
    {
    public:
        cLifeGaugeWork();
        void update(s32 index);
        f32 getLostTimerRate() const;
    private:
        u32 mStateLive;  // offset: 0x0
        f32 mLostTimerMax;  // offset: 0x4
        f32 mLostTimerLeft;  // offset: 0x8
        f32 mLostTimerRate;  // offset: 0xc
    };
public:
    class cWardInfo : public MtObject
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
        cWardInfo();
        // Address: 0x01ac4ef0 - 0x01ac4ef1 (1 bytes)
        virtual ~cWardInfo() {}
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
    public:
        MT_CHAR mChar[8];  // offset: 0x8
        u8 mCharLen;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cSameWardInfo : public MtObject
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
        cSameWardInfo();
        virtual ~cSameWardInfo();
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
        void setWardMap(MT_CTSTR srcStr, MT_CTSTR dstStr);
        u32 getSrcLenUTF8() const;
        u32 getDstLenUTF8() const;
    public:
        MtTypedArray<sGUIExt::cWardInfo> mSrcWardInfo;  // offset: 0x8
        MtTypedArray<sGUIExt::cWardInfo> mDstWardInfo;  // offset: 0x28
    private:
        u32 mSrcLenUTF8;  // offset: 0x48
        u32 mDstLenUTF8;  // offset: 0x4c
    public:
        static MyDTI DTI;
    };
public:
    class cReplaceWardMap : public MtObject
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
        cReplaceWardMap();
        // Address: 0x01ac4f40 - 0x01ac4f41 (1 bytes)
        virtual ~cReplaceWardMap() {}
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
    public:
        MT_CHAR mpSrcChar[8];  // offset: 0x8
        u8 mSrcCharLen;  // offset: 0x10
        MT_CHAR mpDstChar[8];  // offset: 0x11
        u8 mDstCharLen;  // offset: 0x19
        static MyDTI DTI;
    };
public:
    class cDlTicket : public MtObject
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
        cDlTicket(u32 no);
    public:
        u32 mTicket;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    struct stSystemMsg
    {
    public:
        u32 mSkipType;  // offset: 0x0
    };
public:
    class cItemTmp : public MtObject
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
        cItemTmp();
        // Address: 0x01ac4f90 - 0x01ac4f91 (1 bytes)
        virtual ~cItemTmp() {}
    public:
        u32 mItemId;  // offset: 0x8
        u32 mItemNum;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cDialog
    {
    public:
        cDialog();
        void updatePtr();
        bool createDialog(MT_CTSTR msg, s32 cancelPos, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4);
        s32 getDialogPos();
        bool isEnableDialog();
    private:
        uGUISystemMsg* mpGUISystemMsg;  // offset: 0x0
    public:
        static const s32 DISABLE_IDX = -1;
    };
public:
    struct stQueueAnnounce
    {
    public:
        stQueueAnnounce();
        void clear();
    public:
        bool mEnable;  // offset: 0x0
        u32 mScheduleId;  // offset: 0x4
        u32 mType;  // offset: 0x8
        u32 mState;  // offset: 0xc
        MtString mName;  // offset: 0x10
        MtString mInfo;  // offset: 0x18
        s32 mNumber;  // offset: 0x20
        sGUIExt::stRewardItem mRewardItem[5];  // offset: 0x24
        u8 mRandRewardNum;  // offset: 0x60
        u8 mChargeRewardNum;  // offset: 0x61
        u32 mDeliverItemId;  // offset: 0x64
        u32 mDeliverItemNum;  // offset: 0x68
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
    sGUIExt();
    virtual ~sGUIExt();
    u32 getAllOrbFlag() const;
    const MtFloat2 getGUIDefaultResolution();
    stGatheringData* getGatheringData(MtObject* pWho);
    void releaseGatheringData(MtObject* pWho);
    void resetSendItemParameter(bool isInitItem);
    void setSendItemParameter(cUnit* pUnit, nGUIItem::cItem& item);
    cUnit* getSendItemUnit();
    stSendItemParam& getSendItemData();
    nGUIItem::cItem& getPickItem();
    nGUIItem::cItem& getTmpItem();
    nGUIItem::cItemList& getTmpItemList();
    bool isMouseMove();
    void setIsMouseMove(bool flag);
    void onTouchActEnableMenu();
    void offTouchActEnableMenu();
    bool isTouchActEnableMenu() const;
    void createAimUnit();
    void killAimUnit();
    u32 setAimTargetMarker(nGUIAim::TARGET_MARKER_TYPE targetMarkerType, nDDOModel::LOCKON_TARGET_TYPE lockOnTargetType, const MtVector3& targetPos);
    void endAimTargetMarker(u32 targetMarkerId);
    void setAimTargetMarkerPos(u32 targetMarkerId, const MtVector3& pos);
    bool isValidAimTargetMarkerId(u32 targetMarkerId) const;
    bool updateAimTargetMarkerId(u32& targetMarkerId);
    void clearAllAimTargetMarkers();
    void onMagicBowShot();
    virtual void begin();  // vtable slot 11
    virtual void move();  // vtable slot 7
    virtual void setup();  // vtable slot 10
    virtual void reset();  // vtable slot 6
    void updatePtr();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool callbackInvalidCharacter(cGUIMessageAnalyzer* pAnalyzer, rGUIFont* pFont, u32 code);  // vtable slot 15
    // Address: 0x01ac49b0 - 0x01ac49b1 (1 bytes)
    virtual void callbackAllocMTagError() {}  // vtable slot 16
    void setupIconFont(u8 uType);
    void resetIconFont();
    void loadResidentResource();
    void setupResidentUnit();
    u32 getKbFromPadBtnType(sPadExt::PAD_BTN_TYPE button);
    void setupGUICursorPointer();
    void deleteResidentResource();
    void killResidentUnit();
    MT_CTSTR getLanguageDir();
    MT_CTSTR getNormalSkillName(u32 job_id, u32 index);
    MT_CTSTR getNormalSkillNameFromMsgIndex(u32 job_id, u32 msg_index);
    MT_CTSTR getCustomSkillName(u32 job_id, u32 skill_id);
    MT_CTSTR getAbilityName(u32 ability_id);
    MT_CTSTR getAbilityExplain(rGUIMessage* pRes, u32 ability_id);
    MT_CTSTR getStageName(u32 uMsgId);
    MT_CTSTR getAreaNameFromId(u32 area_id);
    MT_CTSTR getLandNameFromId(u32 land_id);
    MT_CTSTR getJobName(u32 job_id);
    MT_CTSTR getWeaponCtgrName(u32 uWeaponCtgr);
    MT_CTSTR getAchievementName(u32 achievement_id);
    u32 getNormalSkillMessageNum(u32 job_id);
    bool isCustomSkillMsg(MT_CTSTR str, u32 job_id);
    u32 getWarpInfoNum();
    const cWarpLocation* getWarpInfo(u32 idx);
    const cAchievementData* getAchievementData(u32 achievement_id);
    void loadCustomSkillData(u32 job_id);
    cAcquirement::cCustomSkillData* getCustomSkillData();
    cAcquirement::cCustomSkillData* getCustomSkillData(u32 job_id);
    cAcquirement::cNormalSkillData* getNormalSkillData(u32 job_id);
    void releaseSkillData();
private:
    cAcquirement::cSkillDataBase* getSkillDataBase(cAcquirement::cSkillDataBase* (&Array)[3], u32 job_id);
public:
    void setDbgIndicatorVisible(bool);
    bool isDbgIndicatorVisible();
    rGUIMessage* getMsgNormalSkill(u32 job_index) const;
    rGUIMessage* getMsgCustomSkill(u32) const;
    rGUIMessage* getMsgAbility() const;
    rGUIMessage* getMsgEnemyName() const;
    rGUIMessage* getMsgNamedEnemy() const;
    rGUIMessage* getMsgTmpMsgCtgr() const;
    rGUIMessage* getMsgTmpMsg() const;
    rGUIMessage* getMsgEmotionCtgr() const;
    rGUIMessage* getMsgEmotion() const;
    rGUIMessage* getMsgPawnOrderCtgr() const;
    rGUIMessage* getMsgPawnOrder() const;
    rGUIMessage* getMsgGameMenu() const;
    rGUIMessage* getMsgCommonDialog() const;
    rGUIMessage* getMsgCommonMessage() const;
    rGUIMessage* getMsgSystemNetwork() const;
    rGUIMessage* getMsgSystemLog() const;
    rGUIMessage* getMsgChatFilter() const;
    rGUIMessage* getMsgHud() const;
    rGUIMessage* getMsgSpotName() const;
    rGUIMessage* getMsgConditionName() const;
    rGUIMessage* getMsgFuncClassName() const;
    rGUIMessage* getMsgNGWordChat() const;
    rGUIMessage* getMsgNGWordName() const;
    rGUIMessage* getMsgInfomation() const;
    rGUIMessage* getMsgJobName() const;
    rGUIMessage* getMsgWeaponCtgrName() const;
    rGUIMessage* getMsgShopTitle() const;
    rGUIMessage* getMsgChatMacroHelp() const;
    rGUIMessage* getMsgChargesInfo() const;
    rGUIMessage* getMsgReleaseContent() const;
    rGUIMessage* getMsgPlatformWord() const;
    rGUIMessage* getMsgCaplinkError() const;
    rGUIMessage* getMsgKeyName() const;
    rSoundRequest* getSndReqCmn() const;
    rTblMenuComm* getTblMenuCommTmpMessage() const;
    rTblMenuComm* getTblMenuCommEmotion() const;
    rTblMenuComm* getTblMenuCommPawnOrder() const;
    rMapSpotStageList* getMSSList() const;
    rStartPosArea* getStartPosAreaField() const;
    rStageMap* getStageMap() const;
    rWarpLocation* getWarpLocation() const;
    void setNDispGUIFromBaseF(u32 uBaseF);
    void clearNDispGUIFromBaseF(u32 uBaseF);
    bool isNDispGUIFromBaseF(u32 uBaseF);
    uGUIQueueAnnounce* getGUIQueueAnnounce();
    uGUIBrowserBG* getGUIBrowserBG();
    f32 getGainInfoNullOffsetPosY();
    void setCharacterEditUnit(cUnit* pUnit);
    u32 getCharacterEditMode();
    bool isItemCBF(u32 uFlag);
    RET_ITEMCBF isItemCBFUpdate(u32 flag);
    void setItemCBF(u32);
    void orItemCBF(u32 uFlag);
    void xorItemCBF(u32);
    void clrItemCBF(u32 uFlag);
    u32 getItemCBF();
    u32 getItemCBFOld();
    bool isItemDetailVisibleDetail();
    void createTelop();
    void deleteTelop();
    void createTelopFSM(MT_CTSTR name, MT_CTSTR msg, f32 fTimer);
    void addTelopFSM(MT_CTSTR name, MT_CTSTR msg, f32 fTimer);
    bool isTelopFSMEnd();
    void setVisibleTelop(bool b);
    bool isVisibleTelop();
    u32 getTelopCurrentPage();
    u32 getTelopFinalPageIdx();
    u32 getPrioDist(u32 uPrioGrp);
    u32 getPrioGrpTop(u32 uPrioGrp);
    u32 getPrioGrpFromIssueIdx(u32 uIssueIdx);
    u32 getIssuePriority(u32 uIssueIdx);
    u32 issuePriority(u32 uPrioGrp);
    void returnPriority(u32 uIssueIdx);
    void setPrioHandleDistCam(u32 uIssueIdx, f32 fDist);
    u32 getPrioTop(u32);
    void requestSE(rSoundRequest* pSndReq, u32 uReqNo);
    void requestSE(u32 uType, u32 uReqNo);
    void requestSECmn(u32 uReqNo);
    rTexture* getDivItemIconTex(u32 uIconNo, u32& uIdx);
    void releaseDivItemIconTex(u32 uIconNo, u32& uIdx);
    void setDivItemIconRno(u32 uRno);
    u32 getDivItemIconRno();
    void bootupGameUI();
    void finishGameUI();
    void reqSaveShortcut();
    const stScreenAdjustPos& getScreenAdjustPosInfo();
    bool isPhotoMode();
    void setPhotoMode(bool IsPhoto);
    bool isBlackOut();
    uGUIBase* newSingletonMenu(const MtDTI* pDTI);
    void setSingletonMenu(uGUIBase* p);
    uGUIBase* getSingletonMenu();
    void killSingletonMenu();
    void setEnableMenuUI(bool bFlg);
    bool isEnableMenuUI() const;
    void setMenuUIF(const MENUIF flag);
    void clearMenuUIF(const MENUIF flag);
    bool isMenuUIF(const u32 flags) const;
    u32 getMenuUIF() const;
    void setSpUIF(SPUIF uFlag);
    void clearSpUIF(SPUIF uFlag);
    bool isSpUIF(u32 uFlag) const;
    bool isExitSituationForSingletonMenu();
    void noticeUpdateButtonGuide();
    u32 getUpdateButtonGuideFrame() const;
    bool setActiveNumBox(void* numBox);
    void resetActiveNumBox(void* numBox);
    bool isActiveNumBox(void* numBox);
    bool isActiveNumBox();
    void saveString(u32 Type, MT_CTSTR pString, u32 Arg);
    void getSaveString(u32 Type, MtString& OutBuff, u32* pArg);
    void reqGUITmpFlag(GUITMP_FLAG ReqId);
    bool isGUITmpFlag(GUITMP_FLAG ReqId);
private:
    void applyGUITmpFlag();
public:
    void setPS4ShareNG(bool IsNG);
    void reqWindowActive(const nGUIExt::stWindowActive& WindowActive);
    void reqWindowActive(uGUIBase* pGUI);
    bool isWindowActive(const nGUIExt::stWindowActive& WindowActive);
    bool isWindowActiveEx(const nGUIExt::stWindowActive& WindowActive);
    bool isExistActiveWindow();
    void offWindowActive(const nGUIExt::stWindowActive& WindowActive);
    void eraseHistoryWindowActive(const nGUIExt::stWindowActive& WindowActive);
    s32 getWindowActiveMgrNo();
    void releaseWindowActiveMgrNo(nGUIExt::stWindowActive& WindowActive);
    bool isUseWindowActive();
    void setUseWindowActive(bool IsUse);
    MtPoint getBrowserDispPos();
    void setBrowserDispPos(s32 PosX, s32 PosY);
    void setBrowserDispPos(MtPoint Pos);
    bool isDispBrowser();
    bool isActiveEventBanner();
private:
    void mgrWindowActive();
    void pushWindowActive(const nGUIExt::stWindowActive& WindowActive);
    void shiftWindowActiveHistory(s32 DestStart, s32 OrgStart, s32 Length);
    nGUIExt::stWindowActive popWindowActive();
    void popWindowActive(const nGUIExt::stWindowActive& WindowActive);
    void restoreWindowActive();
    void setRequestWindowActive(nGUIExt::stWindowActive WindowActive);
    void offWindowActiveCore(const nGUIExt::stWindowActive& WindowActive);
    bool isWindowActiveCore(const nGUIExt::stWindowActive& WindowActive);
public:
    void reqUseItemFromUI(sItemManager::cItemBag* pItemBag, MT_CTSTR UID, u32 uNum);
    void reqDeleteItemFromUI(sItemManager::cItemBag* pItemBag, MT_CTSTR UID, u32 uNum);
    sItemManager::stRequest* reqDeleteItemsFromUI(sItemManager::cItemBag* pItemBag, StorageItemUIDListVec& itemArray);
    sItemManager::stRequest* reqSellItemsFromUI(sItemManager::cItemBag* pItemBag, StorageItemUIDListVec& itemArray);
    sItemManager::stRequest* reqMoveItemFromUI(sItemManager::cItemBag* pItemBag, nItem::E_STORAGE_TYPE from, nItem::E_STORAGE_TYPE to, MT_CTSTR UID, u32 uNum, s32 uTargetSlotNo);
    sItemManager::stRequest* reqMoveItemsFromUI(sItemManager::cItemBag* pItemBag, nItem::E_STORAGE_TYPE uBaseNo, MoveItemUIDFromToVec& itemArray);
    sItemManager::stRequest* reqGetItemFromPickUI(u32 type, sItemManager::cItemBag* pItemBag, stGatheringData* pData);
    sItemManager::stRequest* reqOrbPowerUp(sItemManager::USE_POINT_FOR type, u32 targetLv);
    sItemManager::stRequest* reqExchangeItemFromUI(sItemManager::cItemBag* pItemBag, MoveItemUIDFromToVec& itemArray);
    void useItemReflection(rItemList::rParam* pParam, bool* isBsRecover, bool isPawn);
    void callbackUseItemReq(void* param);
    void callbackUseItemReqSubPawnRecoverOCD(u32 ocd, u32 itemKindType);
    void callbackUseItemReqSubPawnCatchOCD(u32 ocd, u32 itemKindType, f32 itemKindParam);
    void callbackDeleteItemReq(void* param);
    void callbackSellItemReq(void* param);
    void callbackMoveItemReq(void* param);
    void callbackGetItemFromOmReq(void* param);
    void _callbackOrbPowerUpReqCommon(void* param, u32 flag);
    void callbackOrbPowerUpReqHP(void* param);
    void callbackOrbPowerUpReqST(void* param);
    void callbackOrbPowerUpReqLT(void* param);
    void callbackExchangeItemReq(void* param);
    MoveItemUIDFromToVec& getMoveItemVec();
    StorageItemUIDListVec& getStorageItemVec();
    GetRewardBoxItemVec& getRewardItemVec();
    void callbackRewardReceive(void* param);
    sItemManager::cItemBag::cAreaMasterSuppyData& getSupplyData();
    void callbackSuppliesReceive(void* param);
    sItemManager::cEquipList* createEquipList();
    void deleteEquipList();
    void setChangeEquipParam(u32 slot, cItemParam* pParam);
    void cancelChangeEquip(u32 slot);
    bool checkEquipSlotCategory(u32 slot, u32 itemId);
    void requestChangeEquip(u32 bagType, nCharacterData::EQUIP_TYPE equipType, u32 pawnId);
    void callbackEquipChange(void* param);
    bool isExecuteEquipChange();
    u32 getEquipSlotTableIndexFromEquipSlotType(u32 equip_slot_type);
    void callbackJobChange(void* param);
    bool isCompleteMaintenanceRequest();
    void clearMaintenanceReceivedFlag();
    bool isExitMaintenanceRequest(u32 ReqID);
    u32 requestGetJobChangeList(bool isForceUpdate);
    u32 requestGetCustomSkillParam(u32 job_id, bool isForceUpdate);
    u32 requestGetAbilityParam(u32 job_id, bool isForceUpdate);
    u32 requestGetLearnedCustomSkill(bool isForceUpdate);
    u32 requestGetLearnedNormalSkill(bool isForceUpdate);
    u32 requestGetLearnedAbility(bool isForceUpdate);
    u32 requestGetSetCustomSkill(u32 job_id, bool isForceUpdate);
    u32 requestGetSetAbility(bool isForceUpdate);
    u32 requestGetPresetAbility(bool isForceUpdate);
    u32 requestGetAbilityCost(bool isForceUpdate);
    u32 requestGetDogmaOrb(bool isForceUpdate);
    u32 requestGetOrbGainExtendParam(bool isForceUpdate);
    u32 requestGetPawnDogmaOrb(u32 PawnId, bool isForceUpdate);
    void resetAbilityReceiveFlag();
    void resetCustomSkillReceiveFlag();
    void resetJobChangeReceiveFlag();
    void resetPawnJobChangeReceiveFlag();
    void resetOrbGainParamReceiveFlag();
    u32 requestGetPawnLearnedCustomSkill(u32 pawn_id, bool isForceUpdate);
    u32 requestGetPawnLearnedNormalSkill(u32 pawn_id, bool isForceUpdate);
    u32 requestGetPawnLearnedAbility(u32 pawn_id, bool isForceUpdate);
    u32 requestGetPawnSetCustomSkill(u32 pawn_id, u32 job_id, bool isForceUpdate);
    u32 requestGetPawnSetAbility(u32 pawn_id, bool isForceUpdate);
    u32 requestGetPawnAbilityCost(u32 pawn_id, bool isForceUpdate);
    void checkPawnSkillReceiveId(u32 pawn_id);
    void resetPawnSkillReceiveFlag();
    u32 requestGetPresetEquipList(bool isForceUpdate);
    u32 requestSaveArisenCardData(const CDataArisenProfile& Profile);
    u32 requestSavePawnCardData(u32 PawnId, const CDataArisenProfile& Profile, MtString& Comment);
    u32 requestGetCogId(bool isForceUpdate);
    bool isReleasedJob(u32 job_id);
    const JobChangeInfoVec& getJobChangeList(u32 pawn_id);
    const JobChangeInfoVec& getJobReleaseList(u32 pawn_id);
    void getMargeJobChangeList(u32 pawn_id, JobChangeInfoVec& out);
    const SkillParamVec& getCustomSkillParam(u32 job_id);
    bool isReceiveCustomSkillParam(u32 job_id);
    const cGUIExtNetMgr::BasicAbilityInfo& getAbilityParam(u32 abilityId);
    bool isPawnDisableAbility(u32 abilityId);
    const LearnedAcquirementParamVec& getLearnedCustomSkill();
    const NormalSkillParamVec& getLearnedNormalSkill();
    const LearnedAcquirementParamVec& getLearnedAbility();
    const SetAcquirementParamVec& getSetCustomSkill(u32 job_id);
    const SetAcquirementParamVec& getSetAbility();
    const PresetAbilityParamVec& getPresetAbility();
    u32 getAbilityCost();
    const cGUIExtNetMgr::DogmaOrbInfo* getDogmaOrbInfo();
    u32 getDogmaOrbAllBranchSkill(u32);
    u32 getDogmaOrbAllTreeSkill();
    u32 getDogmaOrbAllPageParcent(u32 PageNo);
    const cGUIExtNetMgr::DogmaOrbInfo* getPawnDogmaOrbInfo();
    u32 getPawnDogmaOrbAllBranchSkill(u32);
    u32 getPawnDogmaOrbAllTreeSkill();
    u32 getPawnDogmaOrbAllPageParcent(u32 PageNo);
    static u32 getJobArrayIndex(u32 job_id);
    static u32 getJobID(u32);
    const LearnedAcquirementParamVec& getPawnLearnedCustomSkill();
    const NormalSkillParamVec& getPawnLearnedNormalSkill();
    const LearnedAcquirementParamVec& getPawnLearnedAbility();
    const SetAcquirementParamVec& getPawnSetCustomSkill(u32 job_id);
    const SetAcquirementParamVec& getPawnSetAbility();
    u32 getPawnAbilityCost();
    bool isLearnedNormalSkill(const NormalSkillParamVec& list, u32 job_id, u32 index);
    u32 getLearnedAcquirementLevel(const LearnedAcquirementParamVec& list, u32 job_id, u32 id);
    const CSkillLevelParam* getCustomSkillLevelParam(const SkillLevelParamVec& list, u32 lv);
    const CAbilityLevelParam* getAbilityLevelParam(const AbilityLevelParamVec& list, u32 lv);
    void setupPresetEquipList(const EquipPresetVec& list);
    void setupPresetEquipInfo(const CEquipPreset* pData);
    void setPresetEquipName(s32 preset_no, MT_CTSTR name);
    const cGUIExtNetMgr::PresetEquipInfo& getPresetEquipInfo(u32 PresetNo);
    const cGUIExtNetMgr::WarpPoint& getWarpPointList();
    void setupWarpPointList(const CommonU32Vec& list);
    void addWarpPointList(u32 id);
    MT_CTSTR getCogId();
    void setCogId(MT_CTSTR pId);
    bool isReceivedJobOrbTreeInfo();
    void initJobOrbTreeInfo(const MtTypedArray<CDataJobOrbTreeStatus>& list);
    void clearJobOrbTreeInfo();
    const CJobOrbTreeStatus* getJobOrbTreeInfo(u8 job_id);
    void setJobOrbTreeInfo(const CJobOrbTreeStatus& in_info);
    uGUIJobMaster* getJobMaster();
    void setJobMaster(uGUIJobMaster* set);
    void releaseJobMaster();
    u32 requestPawnContext(u32 pawn_id, cContextInstHm* pRecvContext);
    u32 getRequestPawnContextId();
    void setRecvPawnData(const cCharacterData::stPawnData& pawn_data);
    void clearRequestPawnContext();
    u32 getCaplinkIconNum();
    rTexture* getCaplinkIcon(u32 index);
    void setCaplinkIcon(void* ppng, size_t size, s32 id);
    void loadCaplinkIcon();
    void loadCaplinkProfileIcon();
    void loadCaplinkTrophyIcon();
    void deleteCaplinkIcon();
    bool replaceNGWord(nGUIExt::NG_WORD_TYPE type, MT_STR pDstStr, MT_CTSTR pSrcStr, u32 uLength);
    void setSCMEnable(bool bEnable);
    bool isSCMEnable();
    bool isSCMExec();
    void setSCMReqMenuIdSCM(u32);
    u32 getSCMReqMenuIdSCM();
    u32 getSCMMode();
    void setSCMModeEdit(u32 uMode);
    u32 getSCMModeEdit();
    void setSCMCurrentSCMEditData(u8 uType, u32 uMsgId, u32 uU32Data, f32 fF32Data);
    const cSCM::stSCMEditData* getSCMSCMEditData(u32 uPage, u32 uKey);
    void setSCMCurrentSCCEditData(u8 uType, u8 uCtgr, u32 uId);
    const cSCM::stSCCEditData* getSCMSCCEditData(u32 uPage, u32 uKey);
    u32 getGenderType(u32 uSGender, u32 uLGender);
    void getTargetCursorOffsetFromResource(u32 type, u32 id, s32& out_jointNo, MtVector3& out_offset);
    u32 convertDecToHex(u32 dec);
    MT_CTSTR getMsgFromIdxInfo(const rGUIMessage* pMsg, u32 uIdxId);
    void getEnemyName(nGUIExt::StringEnemyName& nameDst, uCharacter* pEnemy);
    void getEnemyName(nGUIExt::StringEnemyName& nameDst, u32 uEnemyId, u32 uEnemyNamedId, nErosionEnemyBase::EROSION_LEVEL erosionLevel, bool isErosionSmallEnemy);
    void getNamedEnemyName(nGUIExt::StringEnemyName& nameDst, MT_CTSTR pDefaultName, u32 uEnemyNamedId);
    MT_CTSTR getEnemyNameFromGroupId(u32 enemy_group_id);
    MT_CTSTR getMsgTmpMessageCtgrMessage(u32 uCtgr);
    MT_CTSTR getMsgTmpMessage(u32 uCtgr, u32 uId, bool bUseId2);
    u32 getTmpMessageVoiceId(u32 uCtgr, u32 uId);
    u32 getTmpMessageVoiceId(u32 uMsgId);
    u32 getTmpMessageCtgrMsgNum(u32 uCtgr);
    u32 getTmpMessageCtgrNum();
    u32 getTmpMessageNum();
    bool isBattle();
    bool isPartyLarge();
    bool isEnableRimWarp(bool isPermitLargeParty);
    bool isEnableRimWarpDecide(bool isPermitLargeParty);
    bool checkReleasedEmotionFromVoiceId(u32 voice_id);
    bool checkReleasedEmotionFromMsgIndex(u32 msg_index);
    bool checkReleasedEmotionFromCategoryIndex(u32 category, u32 index);
    MT_CTSTR getMsgEmotionCtgrMessage(u32 uCtgr);
    MT_CTSTR getMsgEmotionMessageFromIndex(u32 CategoryId, u32 MenuIdx);
    MT_CTSTR getMsgEmotionMessage(u32 CategoryId, u32 ResourceIdx);
    u32 getEmotionIdx(u32 uCtgr, u32 uIndex);
    u32 getEmotionResIdxFromEmotionIdx(u32 uCtgr, u32 uEmotionIdx);
    u32 getEmotionIdxFromEmotionId(u32 uEmotionId);
    u32 getEmotionId(u32 uIdx);
    u32 getEmotionIdFromMenuIndex(u32 uCtgr, u32 uIndex);
    u32 getEmotionCtgrIdxFromEmotionId(u32 uEmotionId);
    u32 getEmotionMsgIdxFromEmotionId(u32 uEmotionId);
    u32 getEmotionMsgIdFromEmotionId(u32 uEmotionId);
    u32 getEmotionCtgrMsgNum(u32 CategoryId);
    u32 getEmotionCtgrNum();
    u32 getEmotionNum();
    u32 getEmotionCheckedMsgId(u32 CategoryId, u32 MenuIdx);
    MT_CTSTR getMsgEmotionMacroFromIndex(u32 uCtgr, u32 uIndex);
    MT_CTSTR getMsgEmotionMacro(u32 uEmotionId);
    u32 getEmotionNo(u32 uIdx, bool IsMan);
    u32 getEmotionNo(u32 uCtgr, u32 uId, bool IsMan);
    s32 getProfileEmotionCtgrMsgNum(u32 CategoryId);
    u32 getProfileEmotionCheckedMsgId(u32 CategoryId, u32 MenuIdx);
    MT_CTSTR getMsgProfileEmotionMessageFromIndex(u32 CategoryId, u32 MenuIdx);
private:
    u32 getEmotionCtgrMsgNumCore(u32 CategoryId, bool IsCheckRating);
    u32 getEmotionCheckedMsgIdCore(u32 CategoryId, u32 MenuIdx, bool IsCheckRating);
    u32 getRatingEmotionNum(u32 CategoryId);
    bool isRatingEmotion(u32 MsgId);
    void setupRatingInfo();
public:
    MT_CTSTR getMsgPawnOrderCtgrMessage(u32 uCtgr);
    MT_CTSTR getMsgPawnOrderMessage(u32 uCtgr, u32 uId);
    MT_CTSTR getMsgPawnOrderMessageFromOrderId(u32 uOrderId);
    u32 getPawnOrderCtgrMsgNum(u32 uCtgr);
    u32 getPawnOrderCtgrNum();
    u32 getPawnOrderNum();
    u32 getPawnOrderOrderId(u32 uCtgr, u32 uId);
    f32 getWindowSizeRate(u32 uIdx);
    void moveReqTutorialAnnounce();
    void setReqTutorialAnnounce(ANNOUNCE_TYPE type, bool bReq);
    bool checkPriorityTutorialAnnounce(ANNOUNCE_TYPE newType, ANNOUNCE_TYPE oldType);
    bool isReqTutorialAnnouce() const;
    ANNOUNCE_TYPE getReqTutorialAnnounceType() const;
    void moveTutorialPopFromTA();
    void setTutorialPopFromTA(bool b);
    void bootupChat();
    void finishChat();
    void noticeChatLogReset();
    bool noticeChatLogAdd(s32 sFiterGrp);
    void updateChatForm();
    bool isChatMenuUI();
    bool isChatMenuUISubMenu();
    bool isChatInput();
    void setupChatTell();
    void reqChatNActive(bool bDispOff, bool bForbid);
    void setChatForbid(bool bForbid);
    bool isChatForbid();
    bool isChatDefaultBoot();
    s32 getChatArea();
    void setChatArea(s32 chatArea);
    cChat::stChannel& getChatCh(u32 uIdx);
    void deleteChatCh(u32 uIdx);
    void setCustomChatChToCharData();
    u32 getChatEnableChNum();
    MtVector4 getChatChFilterColorScale(u32 uType);
    MtColor getChatChFilterColor(u32 uType);
    u32 getChatChFilterSEId(u32 uType);
    MtVector4 getChatLogColorScale(s32 sFiterGrp);
    u32 getChatSEIdFromCFG(s32 sFiterGrp);
    uGUIChat* getChat();
    void setChatAlpha(f32 fAlpha);
    MtRectF getChatFormSize() const;
    void createDamage();
    void deleteDamage();
    void generateDamageUI(u8 uType, s32 sValue, f32 fRate, u32 uDmgF, const MtVector3* vPos);
    void createShakeStick();
    void deleteShakeStick();
    void setShakeStickCount(s32 count, s32 countMax);
    void setShakeStickSuccess();
    void setShakeStickFailure();
    void requestAnnounce(MT_CTSTR pMsg, u32 color_type, MT_CTSTR pAnalyzerMsg0, MT_CTSTR pAnalyzerMsg1, u32 AnalyzerNum0, u32 AnalyzerNum1, bool isAnalyze);
    void requestAnnounceAnalyzeOff(MT_CTSTR pMsg, u32 color_type);
    void clearAnnounce();
    void createNoLeaderAnnounce(MT_CTSTR msg);
    void createEntryReadyAnnounce(MT_CTSTR msg);
    void createEntryDepartAnnounce(MT_CTSTR msg);
    void createEntryReentryAnnounce(MT_CTSTR msg);
    void createDisableContentsAnnounce(MT_CTSTR msg);
    void createNoSituationAnnounce(MT_CTSTR msg);
    void checkCreateDepartReentryAnnounce();
    void requestInfomation(INFO_FLAG flag, MT_CTSTR pAnalyzeMsg0, MT_CTSTR pAnalyzeMsg1);
    void requestInfomation(INFO_FLAG flag, MT_CTSTR pMsg, MT_CTSTR pAnalyzerMsg0, MT_CTSTR pAnalyzerMsg1, bool isAnalyze);
    void clearInfomation(bool isHideInfomation);
    void clearInfomation(INFO_FLAG flag);
    uGUIInfo* getGUIInfo();
    void createActionPalette();
    void deleteActionPalette();
    bool isActionPaletteEnable();
    void setActionPaletteVisible(bool bVisible);
    bool isActionPaletteVisible();
    void setActionPaletteSCMEditMode(u32 uMode, bool bFKey);
    void createFKeyPalette();
    void deleteFKeyPalette();
    void updateFKeyPaletteGuide();
    void setIndicatorVisible(u32 uType, bool bVisible);
    bool isIndicatorVisible(u32 uType);
    void setIndicatorType(u32 uType);
    void setSaveIndicatorVisibleOff(bool bVisible);
private:
    uGUIIndicator* getIndicatorUnit(u32 uType);
public:
    void reqDispCommIndicator();
    bool isDispCommIndicator();
    void moveCommIndicator();
    void createGameMenu(u32 uMenuId, s32 infoFlag, u32 infoId);
    bool isGameMenuOpenEnable(bool bChkEnableMenuUI);
    bool isGameMenuOpenEnableWithoutUI();
    bool isPlayerTouchAction(const uPlayer* pPlayer);
    bool isGUIGameMenuEnd();
    bool isEnablePauseMenu();
    u32 getEndSelectGameMenu();
    void initGameMenuEndSelect();
    bool isGameMenuCreate(uGUIBase* pGUI);
    bool isGachaActiveGameMenu();
    void createQuestActive();
    void deleteQuestActive();
    void addQuestActiveContentPoint(u32 point);
    void addQuestActiveContentTime(f32 time);
    void setMoveQuestActive(bool flg);
    void addQueueAnnounce(u32 uScheduleId, u32 uType, u32 uState, MT_CTSTR name, MT_CTSTR info, s32 number);
    void addQueueAnnounce(stQueueAnnounce* pQueue);
    void addQueueAnnounceMulti(stQueueAnnounce* pQueue);
    void setQueueAnnouceMove(bool);
    void clearQueueAnnounce();
    void createGauge();
    void deleteGauge();
    void setGaugeVisible(bool bVisible);
    bool isGaugeVisible();
    void addGauge(s32 memberIndex);
    void removeGauge(s32 memberIndex);
private:
    void moveLifeGaugeWorks();
public:
    const cLifeGaugeWork* refLifeGaugeWork(s32 memberIndex) const;
    void createGaugeExp();
    void deleteGaugeExp();
    void attachGaugeEnemyBoss(uCharacter* pCharacter, bool isFirstOnly);
    void eraseGaugeEnemyBoss();
    uGUIGaugeEnemyBoss* getGaugeEnemyBoss();
    void createGaugeSkill();
    void deleteGaugeSkill();
    void setGaugeSkillVisible(bool isVisible);
    void gaugeSkillRendaStart(nKeyCustom::KB_CUSTOM keyCustom, bool isIgnoreModifierKey);
    void gaugeSkillRendaEnd();
    void gaugeSkillRendaUpdate(u32 count, u32 countMax, u32 level, u32 levelMax);
    void createGaugeSorcery();
    void deleteGaugeSorcery();
    uGUIGaugeSorcery* getGaugeSorcery();
    void createGaugeArts();
    void deleteGaugeArts();
    uGUIGaugeArts* getGaugeArts();
    void createGaugeArtsV01_03();
    void deleteGaugeArtsV01_03();
    uGUIGaugeArtsV01_03* getGaugeArtsV01_03();
    void createHudJob10Gauge();
    void deleteHudJob10Gauge();
    bool HudJob10Gauge_isShow();
    void HudJob10Gauge_hide();
    void HudJob10Gauge_updateState(nGUIHudJob10::GAUGE_MODE geugeMode, f32 geugeValue, f32 geugeValueMax);
    void HudJob10Gauge_updateState(nGUIHudJob10::GAUGE_MODE geugeMode);
    void HudJob10Gauge_updateState(f32 geugeValue, f32 geugeValueMax);
    void createJobHud(u32 jobId);
    void deleteJobHud();
    void createTouchTargetSelector();
    void deleteTouchTargetSelector();
    void createTextHud();
    void deleteTextHud();
    void startTextHud(u32 hudMsgId, u32 optionHudMsgId);
    void startTextHud(u32 hudMsgId, nKeyCustom::KB_CUSTOM keyCustom, bool isIgnoreModifier);
    void endTextHud();
    void createHudCustomSkillPallet();
    void deleteHudCustomSkillPallet();
    void showHudCustomSkillPallet(nHuman::CUSTOM_SKILL_GROUP customSkillGroup);
    void hideHudCustomSkillPallet();
    void switchHudCustomSkillPallet(nHuman::CUSTOM_SKILL_GROUP customSkillGroup);
    void createShakeEnemy();
    void deleteShakeEnemy();
    void createEngageInfo();
    void deleteEngageInfo();
    void createGainInfo();
    void deleteGainInfo();
    void addGainInfoQueue(u32 uType, s32 sData0, s32 sData1);
    void clearGainInfoQueue();
    void createSystemMsg(MT_CTSTR msg, u32 errType, u32 baseInitFlags);
    void createSystemMsg(MT_CTSTR msg, u32 errType);
    void createSystemMsg(MT_CTSTR msg);
    void createSystemMsgEx(MT_CTSTR msg, u32 errType, u32 baseInitFlags);
    void createSystemMsgEx(MT_CTSTR msg, u32 errType);
    void createSystemMsgEx(MT_CTSTR msg);
    void deleteSystemMsg();
    bool isSystemMsg();
    u32 getSystemMsgErrType();
    void setSystemMsgWindowInfo(stSystemMsg Info);
    void setSystemMsgMode(u32 uMode);
    void setSystemMsgSkipType(u32 uSkipType);
    void setSystemMsgCntSkipChk(f32 fCnt);
    void addSystemMsgPageInfo(MT_CTSTR msg);
    void addSystemMsgPageInfo(u32 uMsgId);
    void addSystemMsgChoiceInfo(MT_CTSTR msg, u32 uScheduleId, s32 sPage);
    s32 getSystemMsgChoicePos(s32 sPage);
    void setSystemMsgCancelChoicePos(s32 sCancelChoicePos, s32 sPage);
    void setSystemMsgDefaultChoicePos(s32 sDefaultChoicePos, s32 sPage);
    void exitSystemMsg();
    void setSystemMsgMAWText(u32 uIdx, MT_CTSTR pMsg, s32 sPage);
    void setSystemMsgMAWText(u32 uIdx, s32 sNum, s32 sPage);
    void setSystemMsgMAWChoiceTitle(u32 uIdx, MT_CTSTR pMsg, s32 sPage);
    void setSystemMsgMAWChoiceTitle(u32 uIdx, s32 sNum, s32 sPage);
    void setSystemMsgMAWChoiceMsg(u32 uIdx, MT_CTSTR pMsg, s32 sChoicePos, s32 sPage);
    void setSystemMsgMAWChoiceMsg(u32 uIdx, s32 sNum, s32 sChoicePos, s32 sPage);
    void setSystemMsgRealText(MT_CTSTR pText, s32 sPage);
    void setSystemMsgExitFuncType(u32 exitFuncType);
    bool isSystemMsgStop();
    void restartSystemMsg();
    void createChargesHUD();
    void deleteChargesHUD();
    void addDataChargesHUD(u32 charges, u32 disp_flag, MT_CTSTR edit);
    void addAttributeChargesHUD(u32 attr, u32 disp_flag);
    void deleteDataChargesHUD();
    void setPointerPos(const MtVector2& pos, bool isMove);
    void hidePointer(u32 uPrio);
    void pickPointerItem(u32 item_id, u32 uPrio);
    void pickPointerItem(cItemParam* pParam, u32 uPrio);
    void pickPointerSkill(u32 id, u32 type, u32 lv, u32 uPrio);
    void releasePointerItem();
    void hidePointerGuide();
    void clearPointerGuideMsg();
    void updatePointerGuide(u32 uPrio);
    void setPointerGuideMsg(MT_CTSTR msg, u32 height_type, bool isForceDraw, nKeyCustom::KB_CUSTOM keyCustom);
    void pointerGuideReq(cUnit* pUnit, u32 Type, u32 Prio, u32 DispPrio, MT_CTSTR str, nKeyCustom::KB_CUSTOM keyCustom);
    void setPointerPosReq(uGUIBase* pUnit, const MtVector2& pos, u32 uPrio, u32 uUnitPrioGrp, const MtVector2* pPopTarget);
    uGUIPointer* getGUIPointer();
    void setupPointerPosFromReq();
    MtVector3 getPointerPosPopCmd();
    MtVector2 getPointerRequestPosPrev();
    void setPopReqSetting(uGUIPopCmd01* pGUI);
    bool isEnablePosPopCmd();
    void createNpcWindow();
    void restartNpcWindow();
    void killNpcWindow();
    void addNpcWindowText(MT_CTSTR text);
    void setNpcWindowTextFromTextOld();
    MT_CTSTR getNpcWindowText(s32 sPage);
    void setNpcWindowInfo(MT_CTSTR name, u32 uNpcGender, u32 uNpcEnj, bool bNpcEnjDisp);
    void setNpcWindowTimer(f32 fSec);
    void setNpcWindowNpcEnjoyment(u32 uNpcEnj);
    void setNpcWindowChoiceTitle(MT_CTSTR text, s32 sPage);
    void addNpcWindowChoiceInfo(MT_CTSTR text, u32 uScheduleId, nHuman::JOB_ENUM job, s32 sPage, bool isDispLv);
    void setNpcWindowChoiceDefaultSelectedPos(s32 sPos, s32 sPage);
    void setNpcWindowChoiceCancelPos(s32 sPos, s32 sPage);
    s32 getNpcWindowChoiceSelectedPos(s32 sPage);
    bool isNpcWindowEnd();
    bool isNpcWindowFinalPage();
    u32 getNpcWindowCurrentPage();
    u32 getNpcWindowFinalPageIdx();
    void finishNpcWindow();
    void deleteNpcWindow();
    MtVector2 getNpcWindowChoiceWindowPos();
    void setNpcWindowMAWText(u32 uIdx, MT_CTSTR pMsg, s32 sPage);
    void setNpcWindowMAWText(u32 uIdx, s32 sNum, s32 sPage);
    void setNpcWindowMAWChoiceTitle(u32 uIdx, MT_CTSTR pMsg, s32 sPage);
    void setNpcWindowMAWChoiceTitle(u32 uIdx, s32 sNum, s32 sPage);
    void setNpcWindowMAWChoiceMsg(u32 uIdx, MT_CTSTR pMsg, s32 sChoicePos, s32 sPage);
    void setNpcWindowMAWChoiceMsg(u32 uIdx, s32 sNum, s32 sChoicePos, s32 sPage);
    void setNpcWindowScheduleId(nQuest::SCHEDULE_ID scheduleId);
    void setNpcWindowAutoColor(bool autoColor);
    void setNpcWindowAutoClear(bool autoClear);
    uGUIBase* createRankingBoard();
    uGUIBase* createEventBoard();
    void createQuestBoard();
    void deleteQuestBoard();
    bool isExecuteQuestBoard();
    u32 getQuestBoardResult();
    void createClanQuestBoard();
    void deleteClanQuestBoard();
    bool isExecuteClanQuestBoard();
    u32 getClanQuestBoardResult();
    void createQuestInfo(const MtVector3& pos, nQuest::SCHEDULE_ID* pSchedule);
    void deleteQuestInfo();
    u32 getQuestInfoResult();
    void createDelivery();
    void deleteDelivery();
    bool isExecuteDelivery();
    void createDeliveryItem(nQuest::cGUIDeliveryData* pIndexData);
    void deleteDeliveryItem();
    bool isExecuteDeliveryItem();
    void createShopTitle(SHOPTITLE_TYPE::TitleType Title, SHOPTITLE_TYPE::Type Type);
    void createShopTitle(MT_CTSTR title, MT_CTSTR sub_title, SHOPTITLE_TYPE::Type Type);
    void deleteShopTitle();
    void createMapGrid(u32 uMapType);
    rTexture* getMapTexture();
    void setFocusMap(uGUIMap* pGUIMap);
    uGUIMap* getFocusMap();
    void setMapModeMini(u32 uMode);
    u32 getMapModeMini();
    void setMapVisibleMask(bool bVisible);
    bool isMapVisibleMask();
    void setMapMapType(u32 uType, u32 uTargetStage);
    void setLoadingAreaNo(s32 sStageNo, s32 sStartPosNo, bool bCheckLobby);
    void createPlaceName();
    void deletePlaceName();
    void dispStageName(s32 sStageNo);
    void dispSpotName(u32 spotId);
    void dispPlaceName(MT_CTSTR placeName);
    void createInputText();
    void deleteInputText();
    bool isInputTextVisible();
    f32 getInputTextCaretWidth();
    void setInputTextPosScale(const MtFloat2& pos, f32 scale);
    void setInputTextPosScale(const cGUIObjMessage* objMessage, const MtVector3& unitPos, f32 scale);
    void setInputTextProperty(const MtFloat2& pos, const MtSize& fontSize, const MtFloat2& messageSize, u32 autoWrap, u32 layout, u32 controlPoint, f32 instNullScale, f32 inputModeIconWidth, bool isWallpaper, const MtFloat2* maskSize);
    void setInputTextProperty(const cGUIObjMessage* objMessage, const MtVector3& unitPos, f32 instNullScale, f32 inputModeIconWidth, const cGUIObjPolygon* objMask);
    const MtRectF applyInputTextContext(const nInputText::Context& inputTextContext);
    void applyCandidateList(const nInputText::CandidateList& candidateList, const MtRectF& compositionRect, bool isDispCompositionRectSide);
    void startBrowser(MT_CTSTR URL, f32 PosX, f32 PosY, f32 WebSizeW, f32 WebSizeH, bool isMenu, bool isShareNG, u32 browserBuffSize);
    void startBrowserNoBG(MT_CTSTR URL, f32 PosX, f32 PosY, f32 WebSizeW, f32 WebSizeH);
    void setBrowserNoCloseMode();
    void addBrowserGuide(BROWSER_GUIDE GuideType);
    void setBrowserActive(bool IsActive);
    void endBrowser();
    bool isExecBrowser();
    bool isEnableBrowser();
    void browserCallBack(s32& Width, s32& Height, MT_CTSTR TypeName, MT_CTSTR Url);
    nGUIExt::BROWSER_RESULT getBrowserResult();
    void setLowPriorityBrowser();
    void resetPriorityBrowser();
    void stopBrowserOperate();
    void cancelStopBrowserOperate();
    bool isStopBrowserOperate();
    void setBrowserPos(f32 PosX, f32 PosY);
    void openBrowser(u32 browserBuffSize);
    void setupBrowserDrawByLoadingState();
    bool isBrowserInputEnable();
    bool isChangeBannerSize(f32 scale, const MtSize& screen_size);
    bool initEventBanner();
    void wakeupEventBanner();
    void sleepEventBanner();
    void exitEventBanner();
    void setActiveEventBanner(bool IsActive);
    const MtRect& getEventBannerRect();
private:
    void mgrBrowser();
    bool isExecBrowserCore();
public:
    void setOpenCommunityList(uGUICommunityList* pGUICommunityList);
    uGUICommunityList* getOpenCommunityList();
    void clearOpenCommunityList();
    bool isOpenCommunityList();
    void reqCloseCommunityList();
    void setInputState(bool flg);
    bool ckInput();
    bool isNotifiedReward();
    void setNotifiedReward(bool notified);
    void moveMenuUIF();
private:
    void movePlayerIdlingEmotion();
    void clearOnlineStatusAFK();
    void moveOnlineStatusAFK();
public:
    void setServerOption();
private:
    void moveServerOption();
    void moveChargeInfo();
    void moveAnnounce();
    void moveInfomation();
    void moveActionPalette();
    void moveGaugeEnemy();
    void moveQueueAnnounce();
    void moveGainInfoQueue();
    void movePointer();
    void initPointerGuide();
    void movePointerGuide();
    void resetNgward(nGUIExt::NG_WORD_TYPE type);
    void resetNgWardAll();
    void setupNgWord(rGUIMessage* pRes, nGUIExt::NG_WORD_TYPE type, bool isReset);
    void setSameWordMap(rGUIMessage* pRes, bool isReset);
    void setSameWordMap(rReplaceWardGmdList* pRes, bool isReset);
    void resetSameWordMap();
    bool isRegistedReplaceWard(MT_STR str, u32 strLength) const;
    bool findReplaceWard(cReplaceWardMap& replaceWardMap);
    void replaceSameWord(cReplaceWardMap* pReplaceWardMapArray, u32 arraySize);
    bool isRegistedReplaceWard2(MT_CTSTR str) const;
protected:
    virtual void analyzeTagExtend(cGUIMessageAnalyzer* pAnalyzer, u32 tag, MT_CTSTR pParam, bool end, uGUI* pUnit);  // vtable slot 17
    virtual u32 analyzeTagIcon(MT_CTSTR pParam, nGUI::ICON_INFO* pIconInfo);  // vtable slot 18
private:
    const nGUIExt::stMsgAnalyzerWork* getAnalyzerMsg(uGUI* pUnit, bool isCountUp);
    u32 getAnalyzerQuestScheduleId(uGUI* pUnit);
    bool getAnalyzerAutoColor(uGUI* pUnit);
    bool isAnalyzerDispQuestInfoMySelf(uGUI* pUnit);
    void setAnalyzerMsg(cGUIMessageAnalyzer* pAnalyzer, uGUI* pUnit);
    void setAnalyzerMsgEx(cGUIMessageAnalyzer* pAnalyzer, uGUI* pUnit, MT_CTSTR format);
    void analyzeMsgWithChangeColor(cGUIMessageAnalyzer* pAnalyzer, MT_CTSTR pMsg, u32 Length, const MtColor& Color, bool IsChange);
    void analyzeTagKeyCustom(cGUIMessageAnalyzer* pAnalyzer, MT_CTSTR pParam, u8 actPltType);
    void analyzeTagKeyCustomText(cGUIMessageAnalyzer* pAnalyzer, MT_CTSTR pParam, u8 actPltType);
    void moveTakeFlowStatistics();
    void movePrioHandle();
    void sortPrioHandleDistCam(u32 uPrioGrp);
public:
    bool isHighResolution();
    u32 checkEditNameFlag(MT_CTSTR Name, nCharacterEdit::EDIT_NAME_TYPE nameType, nGUIExt::CHARA_EDIT editType) const;
    nCharacterEdit::EDIT_NAME_CHECK checkEditNameType(MT_CTSTR FirstName, MT_CTSTR LastName, nGUIExt::CHARA_EDIT editType) const;
private:
    bool checkStringLength(MT_CTSTR Name, u32 min, u32 max) const;
    bool checkNameCharacter(MT_CTSTR Name, nGUIExt::CHARA_EDIT editType) const;
public:
    void setGameMenuJumpPlace(s32 stage_no, s32 pos_no);
    s32 getMenuJumpStageNo();
    s32 getMenuJumpPosNo();
    bool isLobbyWarpRequest();
    bool isLobbyWarpRequest(s32 stage_no);
    u32 dlTicketRequest();
    bool dlTicketWaiting(u32& pRequestNo);
    void dlTicketReturn(u32 requestNo);
private:
    void moveDlTicket();
public:
    s32 getClanEmblemMarkNum() const;
    bool getClanEmblemArcName(ClanEmblemMarkArcNameString& arcName, s32 markId) const;
    s32 getClanEmblemBaseNum() const;
    s32 getClanEmblemColorNum(uGUIBase* pGUI) const;
    MtColor getClanEmblemColor(uGUIBase* pGUI, s32 colorId) const;
    sItemManager::cHideEquip* getHideEquipData(HIDE_EQUIP_TYPE type);
    void setDispGuideNo(u32 No);
    u32 getDispGuideNo();
    bool isPlActThrow(MT_CTSTR str);
    bool isEntryDepart();
    void setEntryDepart(bool flg);
    void requestOpenServerUI(u32 uiid);
    bool isRequestServerUI();
    bool isActiveServerUI();
    void catchServerUINtc(nUserSession::CPacket_S2C_OPEN_UI_NTC* packet);
private:
    void moveServerUI();
public:
    void setUseDLCInfo(bool isNoUse);
    bool isNoUseDLC();
private:
    nDDOUtility::cArray<stGatheringData, 4> mGatheringDataArray;  // offset: 0x190
public:
    cItemListTmp mItemListTmpBoughtBox;  // offset: 0x2b0
    bool mIsUseCharacterEditGUI;  // offset: 0x2d0
    cMousePointer mMouse;  // offset: 0x2e0
private:
    bool mIsMouseMove;  // offset: 0x360
    bool mUpdatePointerGuideSetFlag;  // offset: 0x361
    bool mPointerGuideUpdate;  // offset: 0x362
    bool mPointerGuideClearFlag;  // offset: 0x363
    stSendItemParam mSendItemParam;  // offset: 0x368
    requestPointerGuide mRequestPointerGude;  // offset: 0x5a8
    u32 mGUIBaseF;  // offset: 0x5c8
    u32 mGUIEndType;  // offset: 0x5cc
    s32 mGUINum;  // offset: 0x5d0
    u32 mRno;  // offset: 0x5d4
    u32 mCreateGUIUnitDTIType;  // offset: 0x5d8
    bool mIsPhotoMode;  // offset: 0x5dc
    cPrioHandle mPrioHandle[400];  // offset: 0x5e0
    u32 mPrioTop[20];  // offset: 0x1ee0
    stScreenAdjustPos mScreenAdjustPos;  // offset: 0x1f30
    stDbgIndicatorWork mDIW;  // offset: 0x1f38
    u32 mNDispGUIFromBaseF;  // offset: 0x1f48
    stPlayerIdling mPlayerIdling;  // offset: 0x1f4c
    nDDOUtility::cBitSet<32> mWindowActiveMgr;  // offset: 0x1f50
    bool mIsUseWindowActive;  // offset: 0x1f54
    nGUIExt::stWindowActive mNowWindowActive;  // offset: 0x1f55
    nGUIExt::stWindowActive mReqWindowActive;  // offset: 0x1f57
    nGUIExt::stWindowActive mWindowActiveHistory[32];  // offset: 0x1f59
    MtPoint mBrowserDispPos;  // offset: 0x1fa0
    bool mDispOffIndicator;  // offset: 0x1fa8
    bool mDispCommIndicator;  // offset: 0x1fa9
    f32 mCommIndicatorTimer;  // offset: 0x1fac
    bool mIsBrowserNoBG;  // offset: 0x1fb0
    bool mIsStopBrowserOperate;  // offset: 0x1fb1
    bool mIsBrowserExec;  // offset: 0x1fb2
    bool mIsOpenBrowser;  // offset: 0x1fb3
    bool mIsTouchActEnableMenu;  // offset: 0x1fb4
    bool mIsEventBannerInit;  // offset: 0x1fb5
    bool mIsActiveEventBanner;  // offset: 0x1fb6
    MtRect mBannerDispRect;  // offset: 0x1fb8
    MtSize mBannerDispScreenSize;  // offset: 0x1fc8
    f32 mBannerDispScale;  // offset: 0x1fd0
    MtTypedArray<cRatingEmoteInfo> mRatingEmoteInfoArray;  // offset: 0x1fd8
public:
    stOnlineStatusAFK mOnlineStatusAFK;  // offset: 0x1ff8
    stServerOption mServerOption;  // offset: 0x2004
    u32 mWndwSizeIdx;  // offset: 0x2010
private:
    cUnit* mpUnitCharacterEdit;  // offset: 0x2018
    rGUIMessage* mpMsgNormalSkill[10];  // offset: 0x2020
    rGUIMessage* mpMsgCustomSkill[10];  // offset: 0x2070
    rGUIMessage* mpMsgAbility;  // offset: 0x20c0
    rGUIMessage* mpMsgStageName;  // offset: 0x20c8
    rGUIMessage* mpMsgAreaName;  // offset: 0x20d0
    rGUIMessage* mpMsgLandName;  // offset: 0x20d8
    rGUIMessage* mpMsgEnemyName;  // offset: 0x20e0
    rGUIMessage* mpMsgNamedEnemy;  // offset: 0x20e8
    rGUIMessage* mpMsgTmpMsgCtgr;  // offset: 0x20f0
    rGUIMessage* mpMsgTmpMsg;  // offset: 0x20f8
    rGUIMessage* mpMsgEmotionCtgr;  // offset: 0x2100
    rGUIMessage* mpMsgEmotion;  // offset: 0x2108
    rGUIMessage* mpMsgPawnOrderCtgr;  // offset: 0x2110
    rGUIMessage* mpMsgPawnOrder;  // offset: 0x2118
    rGUIMessage* mpMsgGameMenu;  // offset: 0x2120
    rGUIMessage* mpMsgCommonDialog;  // offset: 0x2128
    rGUIMessage* mpMsgCommonMessage;  // offset: 0x2130
    rGUIMessage* mpMsgSystemNetwork;  // offset: 0x2138
    rGUIMessage* mpMsgSystemLog;  // offset: 0x2140
    rGUIMessage* mpMsgChatFilter;  // offset: 0x2148
    rGUIMessage* mpMsgHud;  // offset: 0x2150
    rGUIMessage* mpMsgSpotName;  // offset: 0x2158
    rGUIMessage* mpMsgConditionName;  // offset: 0x2160
    rGUIMessage* mpMsgFuncClassName;  // offset: 0x2168
    rGUIMessage* mpMsgNGWordChat;  // offset: 0x2170
    rGUIMessage* mpMsgNGWordName;  // offset: 0x2178
    rGUIMessage* mpMsgInfomation;  // offset: 0x2180
    rGUIMessage* mpMsgJobName;  // offset: 0x2188
    rGUIMessage* mpMsgWeaponCtgrName;  // offset: 0x2190
    rGUIMessage* mpMsgShopTitle;  // offset: 0x2198
    rGUIMessage* mpMsgChatMacroHelp;  // offset: 0x21a0
    rGUIMessage* mpMsgChargesInfo;  // offset: 0x21a8
    rGUIMessage* mpMsgAchievementName;  // offset: 0x21b0
    rGUIMessage* mpMsgReleaseContent;  // offset: 0x21b8
    rGUIMessage* mpMsgPlatformWord;  // offset: 0x21c0
    rGUIMessage* mpMsgCaplinkError;  // offset: 0x21c8
    rGUIMessage* mpMsgKeyName;  // offset: 0x21d0
    rGUIMessage* mpMsgAccountingCourse;  // offset: 0x21d8
    rSoundRequest* mpSndReqCmn;  // offset: 0x21e0
    rSoundRequest* mpSndReqCmn22;  // offset: 0x21e8
    rSoundRequest* mpSndReqPP;  // offset: 0x21f0
    rTexture* mpTexMap;  // offset: 0x21f8
    rTblMenuComm* mpTblMenuCommTmpMessage;  // offset: 0x2200
    rTblMenuComm* mpTblMenuCommEmotion;  // offset: 0x2208
    rTblMenuComm* mpTblMenuCommPawnOrder;  // offset: 0x2210
    rMapSpotStageList* mpMSSList;  // offset: 0x2218
    rStartPosArea* mpStartPosAreaField;  // offset: 0x2220
    rStageMap* mpStageMap;  // offset: 0x2228
    rWarpLocation* mpWarpLocation;  // offset: 0x2230
    rAchievement* mpAchievement;  // offset: 0x2238
    s32 mRefCountForPS4ShareNG;  // offset: 0x2240
    bool mIsEnableMenuUI;  // offset: 0x2244
    u32 mMenuUIF;  // offset: 0x2248
    u32 mSpecialUIF;  // offset: 0x224c
    u32 mItemCBFSave;  // offset: 0x2250
    u32 mItemCBFOld;  // offset: 0x2254
    u32 mItemCBF;  // offset: 0x2258
    bool mIsItemDetailVisibleDefault;  // offset: 0x225c
    u32 mUpdateButtonGuideFrame;  // offset: 0x2260
    void* mActiveNumBoxId;  // offset: 0x2268
    cGUIKeepString* mpKeepString;  // offset: 0x2270
    cChat mChat;  // offset: 0x2278
    cAnnounceQueue mAnnounceList[8];  // offset: 0x22f0
    cAnnounceQueue* mpAnnounceListHead;  // offset: 0x3030
    uGUIAnnounce* mpGUIAnnounce;  // offset: 0x3038
    stInfomation mInfomationList[8];  // offset: 0x3040
    stInfomation* mpInfomationListHead;  // offset: 0x31c0
    uGUIInfo* mpGUIInfo;  // offset: 0x31c8
    uGUIDamage* mpGUIDamage;  // offset: 0x31d0
    uGUIShakeStick* mpGUIShakeStick;  // offset: 0x31d8
    uGUIActionPalette* mpGUIActionPalette;  // offset: 0x31e0
    uGUIFKeyPalette* mpGUIFKeyPalette;  // offset: 0x31e8
    uGUIIndicator* mpGUIIndicator;  // offset: 0x31f0
    uGUIIndicator* mpGUINetIndicator;  // offset: 0x31f8
    uGUIGameMenu* mpGUIGameMenu;  // offset: 0x3200
    uGUIQuestBoard* mpGUIQuestBoard;  // offset: 0x3208
    uGUIQuestBoard* mpGUIClanQuestBoard;  // offset: 0x3210
    uGUIQuestInfo* mpGUIQuestInfo;  // offset: 0x3218
    uGUIQuestDelivery* mpGUIQuestDelivery;  // offset: 0x3220
    uGUISkill* mpGUISkill;  // offset: 0x3228
    uGUIShopTitle* mpGUIShopTitle;  // offset: 0x3230
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x3238
    uGUITelop* mpGUITelop;  // offset: 0x3240
    uGUIQuestActive* mpGUIQuestActive;  // offset: 0x3248
    uGUIQueueAnnounce* mpGUIQueueAnnounce;  // offset: 0x3250
    uGUINpcWindow* mpGUINpcWindow;  // offset: 0x3258
    uGUIGauge* mpGUIGauge;  // offset: 0x3260
    uGUIGaugeExp* mpGUIGaugeExp;  // offset: 0x3268
    uGUIGaugeEnemyBoss* mpGUIGaugeEnemyBoss;  // offset: 0x3270
    uGUIGaugeSkill* mpGUIGaugeSkill;  // offset: 0x3278
    uGUIGaugeArts* mpGUIGaugeArts;  // offset: 0x3280
    uGUIEngageInfo* mpGUIEngageInfo;  // offset: 0x3288
    uGUIShakeEnemy* mpGUIShakeEnemy;  // offset: 0x3290
    uGUIAnnounce* mpGUIDownAnnounce;  // offset: 0x3298
    uGUIAnnounce* mpGUINoLeaderAnnounce;  // offset: 0x32a0
    uGUIAnnounce* mpGUIEntryBoardReadyAnnounce;  // offset: 0x32a8
    uGUIAnnounce* mpGUIEntryBoardDepartAnnounce;  // offset: 0x32b0
    uGUIAnnounce* mpGUIEntryBoardReentryAnnounce;  // offset: 0x32b8
    uGUIAnnounce* mpGUIDisableContentsAnnounce;  // offset: 0x32c0
    uGUIAnnounce* mpGUINoSituationAnnounce;  // offset: 0x32c8
    uGUIChargesHUD* mpGUIChargesHUD;  // offset: 0x32d0
    uGUIPointer* mpGUIPointer;  // offset: 0x32d8
    uGUILoading* mpGUILoading;  // offset: 0x32e0
    uGUIPlace* mpGUIPlace;  // offset: 0x32e8
    uGUIBase* mpSingletonMenu;  // offset: 0x32f0
    uGUIBrowserBG* mpGUIBrowserBG;  // offset: 0x32f8
    uGUIAim* mpAimUnit;  // offset: 0x3300
    uGUIInputText* mpGUIInputText;  // offset: 0x3308
    uGUIPopCnvWnd* mpGUIPopCnvWnd;  // offset: 0x3310
    uGUIGaugeSorcery* mpGUIGaugeSorcery;  // offset: 0x3318
    uGUIGaugeArtsV01_03* mpGUIGaugeArtsV01_03;  // offset: 0x3320
    uGUIHudJob10Gauge* mpGUIHudJob10Gauge;  // offset: 0x3328
    uGUITouchTargetSelector* mpGUITouchTargetSelector;  // offset: 0x3330
    uGUITextHud* mpGUITextHud;  // offset: 0x3338
    uGUIHudCustomSkillPallet* mpGUIHudCustomSkillPallet;  // offset: 0x3340
    uGUICommunityList* mpGUICommunityList;  // offset: 0x3348
    cDivItemIcon mDivItemIcon;  // offset: 0x3350
    stQueueAnnounce mQueueAnnounce[16];  // offset: 0x4388
    stQueueAnnounce mQueueAnnounceMulti[16];  // offset: 0x4a88
    bool mIsQueueAnnouceMove;  // offset: 0x5188
    uGUIGainInfo* mpGUIGainInfo[8];  // offset: 0x5190
    stGainInfoQueue mGainInfoQueue[8][16];  // offset: 0x51d0
    uGUITutorialAnnounce* mpGUITutorialAnnounce;  // offset: 0x59d0
    bool mIsReqTutorialAnnouce;  // offset: 0x59d8
    bool mIsTutorialPopFromTA;  // offset: 0x59d9
    bool mIsNotifiedReward;  // offset: 0x59da
    f32 mNullGainPosYOffset;  // offset: 0x59dc
public:
    cMap mMap;  // offset: 0x59e0
    cSCM mSCM;  // offset: 0x5db0
    MtTypedArray<CDataAreaBaseInfo> mAreaPointList;  // offset: 0x6060
    cChatMacro mChatMacro;  // offset: 0x6080
    cJpegDecode mJpegDecode;  // offset: 0x6800
private:
    nDDOUtility::cBitSet<2> mGUITmpFlagReq;  // offset: 0x6910
    nDDOUtility::cBitSet<2> mGUITmpFlag;  // offset: 0x6914
    nDDOUtility::cBitSet<2> mGUITmpFlagOld;  // offset: 0x6918
    CJobOrbTreeStatus mJobOrbTreeInfoList[10];  // offset: 0x6920
    cAcquirement::cCustomSkillData* mpNowJobCustomSkillData;  // offset: 0x69c0
    cAcquirement::cSkillDataBase* mpCustomSkillData[3];  // offset: 0x69c8
    cAcquirement::cSkillDataBase* mpNormalSkillData[3];  // offset: 0x69e0
    MoveItemUIDFromToVec mMoveItemVec;  // offset: 0x69f8
    StorageItemUIDListVec mStorageItemVec;  // offset: 0x6a18
    GetRewardBoxItemVec mRewardItemVec;  // offset: 0x6a38
    sItemManager::cItemBag::cAreaMasterSuppyData mSupplyData;  // offset: 0x6a58
    stChangeEquipInfo mChangeEquip[15];  // offset: 0x6a68
    sItemManager::cEquipList* mpEquipList;  // offset: 0x6b58
    cGUIExtNetMgr mNetMgr;  // offset: 0x6b60
    uGUIJobMaster* mpGUIJobMaster;  // offset: 0x96b0
    cContextInstHm* mpPawnContext;  // offset: 0x96b8
    u32 mPawnContextId;  // offset: 0x96c0
    MtTypedArray<cTexturePNG> mCaplinkIcon;  // offset: 0x96c8
public:
    cPcTouchAction mPcTouchAction;  // offset: 0x96e8
private:
    nDDOUtility::cArray<cLifeGaugeWork, 8> mLifeGaugeWorks;  // offset: 0x9708
public:
    volatile s32 mInputState;  // offset: 0x9788
private:
    MtTypedArray<MtTypedArray<cWardInfo> > mNgWordArray[2];  // offset: 0x9790
    MtTypedArray<cSameWardInfo> mSameWardInfoArray;  // offset: 0x97d0
    MtTypedArray<cReplaceWardMap> mNgWardMapArray[7];  // offset: 0x97f0
    s32 mJumpStageNo;  // offset: 0x98d0
    s32 mJumpPosNo;  // offset: 0x98d4
    MtTypedArray<cDlTicket> mDlTicketArray;  // offset: 0x98d8
    u32 mSaveTicketNo;  // offset: 0x98f8
    u32 mEraseCounter;  // offset: 0x98fc
    u32 mDestructionCounter;  // offset: 0x9900
    DL_STATE mDlState;  // offset: 0x9904
    sItemManager::cHideEquip mHideEquipData[4];  // offset: 0x9908
    u32 mDispGuideNo;  // offset: 0x9948
    bool mIsEntryDepart;  // offset: 0x994c
    cServerUIClientControl* mpServerUIControl;  // offset: 0x9950
    bool mIsNoUseDLC;  // offset: 0x9958
public:
    static MyDTI DTI;
    static const MtColor FONT_COLOR_DEFAULT;
    static const MtColor FONT_COLOR_FOCUS;
    static const MtColor FONT_COLOR_UNFOCUS;
    static const MtColor FONT_COLOR_TITLE;
    static const MtColor FONT_COLOR_SELECT;
    static const MtColor FONT_COLOR_DISABLE;
    static const MtColor FONT_COLOR_ERROR;
    static const MtColor FONT_COLOR_ERROR_DIALOG;
    static const MtColor FONT_COLOR_STATUS_UP;
    static const MtColor FONT_COLOR_STATUS_DOWN;
    static const MtColor FONT_COLOR_RECOVERY;
    static const MtColor FONT_COLOR_TOLERANCE;
    static const MtColor FONT_COLOR_CHARGE;
    static const MtColor FONT_COLOR_DEFAULT_BLACK;
    static const MtColor FONT_COLOR_MULTI_SELECT;
    static const MtColor FONT_COLOR_ITEM_MAX;
    static const MtColor FONT_COLOR_QST_M;
    static const MtColor FONT_COLOR_QST_S;
    static const MtColor FONT_COLOR_QST_L;
    static const MtColor FONT_COLOR_GAIN_UP;
    static const MtColor FONT_COLOR_GAIN_DOWN;
    static const MtColor FONT_COLOR_GAIN_BO;
    static const MtColor FONT_COLOR_GAIN_PP;
    static const MtColor FONT_COLOR_GAUGE_FACILITY;
    static const MtColor FONT_COLOR_GAUGE_PC;
    static const MtColor FONT_COLOR_GAUGE_PT_MEMBER;
    static const MtColor FONT_COLOR_CHARGE_COURSE;
    static const MtColor FONT_COLOR_ITEM_INFO_UP;
    static const MtColor FONT_COLOR_ITEM_INFO_DOWN;
    static const MtColor FONT_COLOR_ITEM_INFO_RECOVERY;
    static const MtColor FONT_COLOR_ITEM_INFO_TOLERANCE;
    static const MtColor FONT_COLOR_ITEM_INFO_CHARGE;
    static const MtColor FONT_COLOR_ITEM_INFO_VSEM;
    static const MtColor CRAFT_COLOR_DEFAULT;
    static const MtColor CRAFT_COLOR_RED;
    static const MtColor CRAFT_COLOR_GREEN;
    static const MtColor CRAFT_COLOR_BLUE;
    static const MtColor CRAFT_COLOR_YELLOW;
    static const MtColor CRAFT_COLOR_PINK;
    static const MtColor CRAFT_COLOR_BLACK;
    static const MtVector3 NPC_QUEST_INFO_POS;
    static const s32 KetaTable[10];
    static const s32 DispNumMax;
    static const u32 PRIO_INVALID = 4294967295;
    static const u32 SCRL_DIST = 3;
    static const u32 GUIDBGPRINTBUF_MAX = 1024;
    static const u64 HP_MAX = 99999999;
    static const u32 DIVITEMICON_NUM = 128;
    static const u32 TMPMSG_NUM = 32;
    static const u32 WNDWSIZETYPE_MAX = 3;
    static const u32 ACTIVE_WINDOW_MGR_NUM = 32;
    static const u32 ANNOUNCE_BUFF_SIZE = 256;
    static const u32 ANNOUNCE_ANALYZE_BUFF_SIZE = 64;
    static const u32 ANNOUNCE_ANALYZER_MAX = 2;
    static const u32 INFOMATION_ANALYZER_MAX = 2;
    static const u32 BOUGHTBOX_LIST_MAX = 400;
private:
    static const u32 TFSINFO_MAX = 65536;
    static const u32 QUEUEANNOUNCE_MAX = 16;
    static const u32 SERVERMSGQUEUE_MAX = 128;
    static const u32 GAININFOQUEUE_MAX = 16;
    static const u32 COMM_INDICATOR_MIN_TIME = 60;
    static const u32 ANNOUNCE_STACK_NUM = 8;
    static const u32 INFOMATION_STACK_NUM = 8;
public:
    static const u32 SKILL_DATA_LOAD_NUM = 3;
private:
    static const u32 MAX_UTF_CHAR_SIZE = 8;
    static const u32 REPLACE_WARD_LENTYPE_MAX = 7;
public:
    static const u32 TICKET_MAX = 100;
    static const u32 BLANK_TICKET_NO = 99999;
    static const u32 ERASE_COUNT = 5;
    static const u32 DESTRUCTION_COUNT = 300;
    static const MT_CTSTR CLANEMBLEMMARK_RESID;
};

// Inline, no code of its own: checked where it is inlined.
inline rGUIMessage* sGUIExt::getMsgEnemyName() const {
    return this->mpMsgEnemyName;
}

// Inline, no code of its own: checked where it is inlined.
inline rGUIMessage* sGUIExt::getMsgCommonDialog() const {
    return this->mpMsgCommonDialog;
}

// Inline, no code of its own: checked where it is inlined.
inline rGUIMessage* sGUIExt::getMsgCommonMessage() const {
    return this->mpMsgCommonMessage;
}

// Inline, no code of its own: checked where it is inlined.
inline rGUIMessage* sGUIExt::getMsgSystemLog() const {
    return this->mpMsgSystemLog;
}

// Inline, no code of its own: checked where it is inlined.
inline rSoundRequest* sGUIExt::getSndReqCmn() const {
    return this->mpSndReqCmn;
}

// Inline, no code of its own: checked where it is inlined.
inline bool sGUIExt::isReqTutorialAnnouce() const {
    return this->mIsReqTutorialAnnouce;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIInfo* sGUIExt::getGUIInfo() {
    return this->mpGUIInfo;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUICommunityList* sGUIExt::getOpenCommunityList() {
    return this->mpGUICommunityList;
}

// Inline, no code of its own: checked where it is inlined.
inline sGUIExt::cPrioHandle::cPrioHandle() {
    this->mPrio = static_cast<u32>(4294967295);
    this->mDistCam = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIChat* sGUIExt::cChat::getGUIChat() {
    return this->mpGUIChat;
}

// Inline, no code of its own: checked where it is inlined.
inline sGUIExt::cSEPlayer::cSEPlayer() {
    this->mpRes = static_cast<rSoundRequest*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline sGUIExt::cWardInfo::cWardInfo() {
    this->mCharLen = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sGUIExt::cReplaceWardMap::cReplaceWardMap() {
    this->mSrcCharLen = static_cast<u8>(0);
    this->mDstCharLen = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sGUIExt::cItemTmp::cItemTmp() {
    this->mItemId = static_cast<u32>(0);
    this->mItemNum = static_cast<u32>(0);
}
