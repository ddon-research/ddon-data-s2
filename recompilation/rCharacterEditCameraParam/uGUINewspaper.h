#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/cGUIControlMgr.h"
#include "../shared/nQuest.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class CDataAreaWarpPoint;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtVector2;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjChildAnimationRoot;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObjTextureSet;
namespace nQuest { class cCycleContentsInfo; }
namespace nQuest { class cCycleContentsResultRewardInfo; }
namespace nQuest { class cGUINewspaperSetQuestInfo; }
class rGUI;
class rGUIMessage;
class uGUIPopCmd01;
class uGUIPopDetail01;
class uGUISystemMsg;

// Declarations
class uGUINewspaper;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUINewspaper : public uGUIBase
{
public:
    enum NEWSPAPER_TYPE
    {
        NEWS_TYPE_NEWS = 0,
        NEWS_TYPE_CONTENTS = 1,
        NEWS_TYPE_QUICKPARTY = 2,
    };
    enum Direction
    {
        NEXT = 0,
        PREV = 1,
    };
    enum
    {
        STATUS_NONE = 0,
        STATUS_NET_WAIT = 1,
    };
    enum
    {
        MODE_SELECT_AREA = 0,
        MODE_SELECT_QUEST = 1,
        MODE_SELECT_QUESTDETAIL = 2,
        MODE_SELECT_CONTENT = 3,
        MODE_SELECT_CONTENTDETAIL = 4,
        MODE_REWARD_CMD = 5,
        MODE_REWARD_SUMMARY = 6,
        MODE_REWARD_DETAIL = 7,
        MODE_RANKING_CMD = 8,
        MODE_RANKING_LIST = 9,
        MODE_NONE = 10,
    };
    enum
    {
        TYPE_NEWS = 0,
        TYPE_EVENT = 1,
        TYPE_REWARD = 2,
        TYPE_RANKING = 3,
        TYPE_ENTRY = 4,
        TYPE_NUM = 5,
        TYPE_EVENTPAGE_START = 1,
        TYPE_EVENT_1ST = 5,
    };
    enum
    {
        DIALOG_MODE_WARP = 0,
        DIALOG_MODE_MESSAGE = 1,
        DIALOG_MODE_NUM = 2,
    };
    enum
    {
        AREA_LIST_DISP_NUM = 20,
        AREA_LIST_MAX = 22,
        QUEST_LIST_DISP_NUM = 15,
        QUEST_LIST_MAX = 17,
        INFO_LIST_DISP_S_MAX = 17,
        INFO_LIST_DISP_D_MAX = 7,
        INFO_LIST_MAX = 19,
        EVENT_REWARD_MAX = 5,
        RANKING_LIST_DISP_MAX = 10,
        RANKING_LIST_MAX = 12,
        REWARD_SUMMARY_DISP_MAX = 13,
        REWARD_SUMMARY_MAX = 15,
        REWARD_DETAIL_DISP_MAX = 13,
        REWARD_DETAIL_MAX = 15,
        QUEST_THUMBNAIL_NOTDISCOVER = 0,
        EVENT_TAB_NUM = 3,
        REWARD_ICON_MAXNUM = 7,
        PARTY_BONUS_DEFAULT = 1,
    };
    enum
    {
        BUTTON_WARP = 0,
        BUTTON_QUICKMATCH = 1,
        BUTTON_NUM = 2,
        BUTTON_DEFAULT = 0,
    };
    enum
    {
        NOWARP_TYPE_NOUSE = 0,
        NOWARP_TYPE_BATTLE = 1,
        NOWARP_TYPE_NOFAVORITE = 2,
        NOWARP_TYPE_NUM = 3,
        NOWARP_TYPE_NONE = 4,
    };
    enum
    {
        NOQUICK_TYPE_ALREADY_ENTRY = 0,
        NOQUICK_TYPE_NUM = 1,
        NOQUICK_TYPE_NONE = 2,
    };
    enum
    {
        NOENTRY_TYPE_ISENTRY = 0,
        NOENTRY_TYPE_ISCONTENT = 1,
        NOENTRY_TYPE_PLAYNOW = 2,
        NOENTRY_TYPE_NOTFROMMENU = 3,
        NOENTRY_TYPE_NOOPEN = 4,
        NOENTRY_TYPE_CANT = 5,
        NOENTRY_TYPE_NUM = 6,
        NOENTRY_TYPE_NONE = 7,
    };
    enum
    {
        EVENTRNK_CATE_TECH = 0,
        EVENTRNK_CATE_NUM = 1,
        EVENTRNK_CATE_NONE = 2,
    };
    enum
    {
        EVENTRWD_CATE_BORDER = 0,
        EVENTRWD_CATE_RANKING = 1,
        EVENTRWD_CATE_NUM = 2,
        EVENTRWD_CATE_NONE = 3,
    };
    enum
    {
        MGR_ID_NEWS_CMN = 0,
        MGR_ID_NEWSBUTTON = 1,
        MGR_ID_NEWSICONS = 2,
        MGR_ID_EVENTCMN = 3,
        MGR_ID_EVENTINFO = 4,
        MGR_ID_REWARD_LIST = 5,
        MGR_ID_RANKING_LIST = 6,
    };
    enum
    {
        CONTROL_CATEGORY_NEWS = 0,
        CONTROL_CATEGORY_NEWSQUEST = 1,
        CONTROL_CATEGORY_EVENTCMN = 2,
        CONTROL_CATEGORY_EVENTINFO = 3,
        CONTROL_CATEGORY_EVENTRANK = 4,
        CONTROL_CATEGORY_EVENTREWARD = 5,
    };
    enum
    {
        CLICK_NONE = 0,
        CLICK_UBUTTON = 1,
        CLICK_DBUTTON = 2,
        CLICK_EVENT = 3,
    };
    enum
    {
        LIST_TYPE_NONE = 0,
        LIST_TYPE_AREA = 1,
        LIST_TYPE_LAND = 2,
        LIST_TYPE_CONTENT = 3,
    };
    enum
    {
        GUIDE_TYPE_NEWS_AREA = 0,
        GUIDE_TYPE_NEWS_QUEST_LIST = 1,
        GUIDE_TYPE_NEWS_QUEST_DETAIL = 2,
        GUIDE_TYPE_EVENT = 3,
    };
    enum
    {
        EVENTINFO_IDX_JOINBUTTON = 0,
        EVENTINFO_IDX_NUM = 1,
    };
    enum
    {
        EVENTRNK_IDX_CMDBUTTON = 0,
        EVENTRNK_IDX_LIST = 1,
        EVENTRNK_IDX_NUM = 2,
    };
    enum
    {
        EVENTRWD_IDX_CMDBUTTON = 0,
        EVENTRWD_IDX_LIST = 1,
        EVENTRWD_IDX_NUM = 2,
    };
    enum
    {
        INPUTEVENT_xxx = 66,
        INPUTEVENT_CMN_CHANGEEVENT = 67,
        INPUTEVENT_CMN_CHANGENEWS = 68,
        INPUTEVENT_CMN_DIALOGOPEN = 69,
        INPUTEVENT_NEWSCMN_CANCEL = 70,
        INPUTEVENT_SELECTLIST_DECIDE = 71,
        INPUTEVENT_SELECTLIST_CURSOR = 72,
        INPUTEVENT_SELECTLIST_CLICK_CURSOR = 73,
        INPUTEVENT_SELECTLIST_CLICK_DECIDE = 74,
        INPUTEVENT_SELECTLIST_NEXTLAND = 75,
        INPUTEVENT_SELECTLIST_PREVLAND = 76,
        INPUTEVENT_SELECTLIST_UP = 77,
        INPUTEVENT_SELECTLIST_DOWN = 78,
        INPUTEVENT_QUESTLIST_DECIDE = 79,
        INPUTEVENT_QUESTLIST_CLICK_CURSOR = 80,
        INPUTEVENT_QUESTLIST_CLICK_DICEDE = 81,
        INPUTEVENT_QUESTLIST_NEXTQUEST = 82,
        INPUTEVENT_QUESTLIST_PREVQUEST = 83,
        INPUTEVENT_CHANGE_REWARDICON = 84,
        INPUTEVENT_CHANGE_WARPBUTTONS = 85,
        INPUTEVENT_CHANGEQUESTSELECTBUTTON = 86,
        INPUTEVENT_QUESTWARP = 87,
        INPUTEVENT_NOQUESTWARP = 88,
        INPUTEVENT_MOUSE_QUESTWARP = 89,
        INPUTEVENT_MOUSE_NOQUESTWARP = 90,
        INPUTEVENT_QUICKMATCH = 91,
        INPUTEVENT_CANCELQUICKMATCH = 92,
        INPUTEVENT_NOQUICKMATCH = 93,
        INPUTEVENT_MOUSE_QUICKMATCH = 94,
        INPUTEVENT_MOUSE_CANCELQUICKMATCH = 95,
        INPUTEVENT_UPDATEREWARDICON_CURSOR = 96,
        INPUTEVENT_UPDATEREWARDICON_MOUSE = 97,
        INPUTEVENT_CONTENTLIST_DECIDE = 98,
        INPUTEVENT_CONTENTLIST_CLICK_CURSOR = 99,
        INPUTEVENT_CONTENTLIST_CLICK_DECIDE = 100,
        INPUTEVENT_EVENTCMN_CANCEL = 101,
        INPUTEVENT_EVENTTAB_UD = 102,
        INPUTEVENT_EVENTTAB_JOIN = 103,
        INPUTEVENT_REWARDTAB_TO_BUTTON = 104,
        INPUTEVENT_REWARDTAB_TO_LIST = 105,
        INPUTEVENT_REWARDTAB_BUTTON_CLICK = 106,
        INPUTEVENT_REWARDTAB_BUTTON = 107,
        INPUTEVENT_REWARDTABD_SUMMARY_UD = 108,
        INPUTEVENT_REWARDTABD_SUMMARY_DECIDE = 109,
        INPUTEVENT_REWARDTABD_SUMMARY_CLICK = 110,
        INPUTEVENT_REWARDTABD_DETAIL_CANCEL = 111,
        INPUTEVENT_REWARDTABD_DETAIL_CLICK = 112,
        INPUTEVENT_RANKINGTAB_TO_BUTTON = 113,
        INPUTEVENT_RANKINGTAB_TO_LIST = 114,
        INPUTEVENT_RANKINGTAB_BUTTON_CLICK = 115,
        INPUTEVENT_RANKINGTAB_BUTTON = 116,
        INPUTEVENT_RANKINGTAB_LIST_UD = 117,
        INPUTEVENT_RANKINGTAB_LIST_CLICK = 118,
    };
    enum
    {
        AREA_INFO_LIMIT = 0,
        AREA_INFO_PARTY = 1,
        AREA_INFO_CONFIRM = 2,
        AREA_INFO_NUM = 3,
    };
    enum
    {
        REWARD_TYPE_ITEM = 0,
        REWARD_TYPE_NUMBER = 1,
        REWARD_TYPE_NUM = 2,
    };
public:
    class MyDTI;
    struct _infoList;
    struct _infoMonsterList;
    struct _infoItemList;
    class cCycleContentsNewsInfo;
    struct _AreaInfo;
    class cScrollAreaDispList;
    class cScrollQuestDispList;
    struct _QuestInfo;
    struct _QuestInfoButton;
    class cScrollRankingDispList;
    class cScrollRewardSummaryItemList;
    class cScrollRewardDetailItemList;
    class cScrollAreaItemList;
    class cScrollQuestItemList;
    class cScrollRankingItemList;
    class cScrollRewardDetailInfoList;
    class cScrollRewardSummaryInfoList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct _infoMonsterList
    {
    public:
        _infoMonsterList();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjLv;  // offset: 0x8
        cGUIObjMessage* mpObjLvVal;  // offset: 0x10
        cGUIObjMessage* mpObjName;  // offset: 0x18
    };
public:
    struct _infoItemList
    {
    public:
        _infoItemList();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjName;  // offset: 0x8
    };
public:
    class cCycleContentsNewsInfo : public MtObject
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
        cCycleContentsNewsInfo();
        virtual ~cCycleContentsNewsInfo();
    public:
        s32 mIndex;  // offset: 0x8
        MtString mPhaseName;  // offset: 0x10
        MtString mPhaseInfo;  // offset: 0x18
        static MyDTI DTI;
    };
public:
    struct _AreaInfo
    {
    public:
        _AreaInfo();
    public:
        cGUIObjMessage* mpNum;  // offset: 0x0
        cGUIInstAnimation* mpIcon;  // offset: 0x8
        cGUIObjMessage* mpText;  // offset: 0x10
    };
public:
    class cScrollAreaDispList : public uGUIBase::cScrollListItemBase
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
        cScrollAreaDispList();
        // Address: 0x01afba40 - 0x01afba41 (1 bytes)
        virtual ~cScrollAreaDispList() {}
    public:
        s32 mIndex;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimArea;  // offset: 0x60
        cGUIObjMessage* mpObjMsgAreaName;  // offset: 0x68
        cGUIInstAnimation* mpInstAnimLand;  // offset: 0x70
        cGUIObjMessage* mpObjMsgLandName;  // offset: 0x78
        static MyDTI DTI;
    };
public:
    class cScrollQuestDispList : public uGUIBase::cScrollListItemBase
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
        cScrollQuestDispList();
        // Address: 0x01afba30 - 0x01afba31 (1 bytes)
        virtual ~cScrollQuestDispList() {}
    public:
        s32 mIndex;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimLimit;  // offset: 0x60
        cGUIInstAnimation* mpInstAnimParty;  // offset: 0x68
        cGUIInstAnimation* mpInstAnimBonus;  // offset: 0x70
        cGUIInstAnimation* mpInstAnimClear;  // offset: 0x78
        cGUIInstAnimation* mpInstAnimName;  // offset: 0x80
        cGUIObjMessage* mpObjMsgName;  // offset: 0x88
        cGUIInstAnimation* mpInstAnimLevel;  // offset: 0x90
        cGUIObjMessage* mpObjMsgLevel;  // offset: 0x98
        static MyDTI DTI;
    };
public:
    struct _QuestInfoButton
    {
    public:
        _QuestInfoButton();
    public:
        cGUIObjTextureSet* pBase0;  // offset: 0x0
        cGUIObjTextureSet* pBase1;  // offset: 0x8
        cGUIObjTexture* pLocal;  // offset: 0x10
        cGUIObjNull* pPointer;  // offset: 0x18
    };
public:
    class cScrollRankingDispList : public uGUIBase::cScrollListItemBase
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
        cScrollRankingDispList();
        // Address: 0x01afba20 - 0x01afba21 (1 bytes)
        virtual ~cScrollRankingDispList() {}
    public:
        s32 mIndex;  // offset: 0x58
        cGUIInstAnimation* mpInst;  // offset: 0x60
        cGUIObjMessage* mpRank;  // offset: 0x68
        cGUIObjMessage* mpName;  // offset: 0x70
        cGUIObjMessage* mpClan;  // offset: 0x78
        cGUIObjMessage* mpPoint;  // offset: 0x80
        cGUIObjTexture* mpPlate;  // offset: 0x88
        cGUIObjTexture* mpIcon;  // offset: 0x90
        cGUIObjChildAnimationRoot* mpArrow;  // offset: 0x98
        static MyDTI DTI;
    };
public:
    class cScrollRewardSummaryItemList : public uGUIBase::cScrollListItemBase
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
        cScrollRewardSummaryItemList();
        // Address: 0x01afba10 - 0x01afba11 (1 bytes)
        virtual ~cScrollRewardSummaryItemList() {}
    public:
        s32 mIndex;  // offset: 0x58
        cGUIInstNull* mpNull;  // offset: 0x60
        cGUIObjMessage* mpLabel;  // offset: 0x68
        cGUIObjNull* mpMyMark;  // offset: 0x70
        cGUIObjTexture* mpListIcon;  // offset: 0x78
        static MyDTI DTI;
    };
public:
    class cScrollRewardDetailItemList : public uGUIBase::cScrollListItemBase
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
        cScrollRewardDetailItemList();
        // Address: 0x01afba00 - 0x01afba01 (1 bytes)
        virtual ~cScrollRewardDetailItemList() {}
    public:
        s32 mIndex;  // offset: 0x58
        cGUIInstNull* mpNull;  // offset: 0x60
        cGUIObjMessage* mpItemName;  // offset: 0x68
        static MyDTI DTI;
    };
public:
    class cScrollAreaItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollAreaItemList();
        cScrollAreaItemList(f32 Top, f32 Bottom);
        virtual ~cScrollAreaItemList();
    public:
        MtString mpText;  // offset: 0x28
        u32 mListType;  // offset: 0x30
        s32 mAreaId;  // offset: 0x34
        static MyDTI DTI;
    };
public:
    class cScrollQuestItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollQuestItemList();
        cScrollQuestItemList(f32 Top, f32 Bottom);
        virtual ~cScrollQuestItemList();
    public:
        u32 mLevel;  // offset: 0x28
        MtString mpQuestName;  // offset: 0x30
        bool mIsLimit;  // offset: 0x38
        bool mIsParty;  // offset: 0x39
        bool mIsBonus;  // offset: 0x3a
        bool mIsClear;  // offset: 0x3b
        bool mIsRecommand;  // offset: 0x3c
        static MyDTI DTI;
    };
public:
    class cScrollRankingItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollRankingItemList();
        cScrollRankingItemList(f32 Top, f32 Bottom);
        // Address: 0x01afbc10 - 0x01afbc11 (1 bytes)
        virtual ~cScrollRankingItemList() {}
    public:
        static MyDTI DTI;
    };
public:
    class cScrollRewardDetailInfoList : public uGUIBase::cScrollListInfoBase
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
        cScrollRewardDetailInfoList();
        cScrollRewardDetailInfoList(f32 Top, f32 Bottom);
        // Address: 0x01afbb70 - 0x01afbb71 (1 bytes)
        virtual ~cScrollRewardDetailInfoList() {}
    public:
        u32 mItemId;  // offset: 0x28
        nQuest::cCycleContentsResultRewardInfo* mpRewardInfo;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    class cScrollRewardSummaryInfoList : public uGUIBase::cScrollListInfoBase
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
        cScrollRewardSummaryInfoList();
        cScrollRewardSummaryInfoList(f32 Top, f32 Bottom);
        // Address: 0x01afbbc0 - 0x01afbbc1 (1 bytes)
        virtual ~cScrollRewardSummaryInfoList() {}
    public:
        bool mIsMyMark;  // offset: 0x25
        s32 mUnderParam;  // offset: 0x28
        s32 mOverParam;  // offset: 0x2c
        static MyDTI DTI;
    };
public:
    struct _infoList
    {
    public:
        _infoList();
    public:
        cGUIInstNull* mpListNull;  // offset: 0x0
        cGUIInstNull* mpMonsterNull;  // offset: 0x8
        cGUIInstNull* mpItemNull;  // offset: 0x10
        cGUIInstAnimation* mpLabelMonster;  // offset: 0x18
        cGUIInstAnimation* mpLabelItem;  // offset: 0x20
        bool mIsShow;  // offset: 0x28
        f32 mBaseY;  // offset: 0x2c
        uGUINewspaper::_infoMonsterList mMonsterList[19];  // offset: 0x30
        uGUINewspaper::_infoItemList mItemList[19];  // offset: 0x290
    };
public:
    struct _QuestInfo
    {
    public:
        _QuestInfo();
    public:
        cGUIInstAnimation* mpInst;  // offset: 0x0
        cGUIInstAnimation* mpQuestIcon[3];  // offset: 0x8
        uGUIBase::cTexArcLoader mQuestImage;  // offset: 0x20
        cGUIObjTexture* mpQuestImage;  // offset: 0xa8
        cGUIInstAnimation* mpQuestImageLoadIcon;  // offset: 0xb0
        cGUIObjPolygon* mpQuestNamePlate;  // offset: 0xb8
        cGUIObjMessage* mpQuestName;  // offset: 0xc0
        cGUIObjMessage* mpQuestLv;  // offset: 0xc8
        cGUIObjTexture* mpAreaName;  // offset: 0xd0
        cGUIObjMessage* mpQuestText;  // offset: 0xd8
        cGUIObjNull* mpUnknown;  // offset: 0xe0
        cGUIObjMessage* mpUnknownReward;  // offset: 0xe8
        cGUIObjMessage* mpUnknownRewardName;  // offset: 0xf0
        cGUIObjMessage* mpUnknownUnit;  // offset: 0xf8
        cGUIObjMessage* mpLimitTime;  // offset: 0x100
        uGUINewspaper::_QuestInfoButton mButtonJump;  // offset: 0x108
        uGUINewspaper::_QuestInfoButton mButtonQuickMatch;  // offset: 0x128
        cGUIInstAnimation* mpRewardIconBaseNorm;  // offset: 0x148
        cGUIInstAnimation* mpRewardIconBaseRand;  // offset: 0x150
        cGUIObjMessage* mpObjSelectRewardMsg;  // offset: 0x158
        u32 mRewardIconNumNorm;  // offset: 0x160
        u32 mRewardIconNumRand;  // offset: 0x164
        uGUIBase::cReferenceUIIconItem mRewardIcon[7];  // offset: 0x170
        cGUIInstNull* mpRewardIconNull[7];  // offset: 0xbf0
        s32 mRewardIconBaseX;  // offset: 0xc28
        cGUIObjTexture* mpRecommendLabel;  // offset: 0xc30
        bool mIsRecommend;  // offset: 0xc38
        cGUIObjTexture* mpClearedStamp;  // offset: 0xc40
        bool mIsPopular;  // offset: 0xc48
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
    uGUINewspaper();
    virtual ~uGUINewspaper();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void end();  // vtable slot 79
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void setFirstOpenTypeEvent(NEWSPAPER_TYPE type, u32 eventNo);
    u32 evCtrlClose(cControl::Message* pMsg);
    u32 evCtrlNewsCmnCancel(cControl::Message* pMsg);
    u32 evCtrlNewsCmnLR(cControl::Message* pMsg);
    u32 evCtrlNewsCmnClick(cControl::Message* pMsg);
    u32 evCtrlNewsChangeEvent(cControl::Message* pMsg);
    u32 evCtrlSelectListDecide(cControl::Message* pMsg);
    u32 evCtrlSelectListClick(cControl::Message* pMsg);
    u32 evCtrlSelectListCursorLR(cControl::Message* pMsg);
    u32 evCtrlSelectListCursorUD(cControl::Message* pMsg);
    u32 evCtrlDialogChangeEvent(cControl::Message* pMsg);
    u32 evCtrlAreaQuestDecide(cControl::Message* pMsg);
    u32 evCtrlAreaQuestClick(cControl::Message* pMsg);
    u32 evCtrlQuestButtonDecide(cControl::Message* pMsg);
    u32 evCtrlQuestButtonCursorUD(cControl::Message* pMsg);
    u32 evCtrlRewardIconCursorLR(cControl::Message* pMsg);
    u32 evCtrlRewardIconCursorUR(cControl::Message* pMsg);
    u32 evCtrlRewardIconCursorMouseOver(cControl::Message* pMsg);
    u32 evCtrlRewardIconCursorMouseClick(cControl::Message* pMsg);
    u32 evCtrlEventCmnCancel(cControl::Message* pMsg);
    u32 evCtrlEventCursorUD(cControl::Message* pMsg);
    u32 evCtrlEventCursorDecide(cControl::Message* pMsg);
    u32 evCtrlEventChangeNews(cControl::Message* pMsg);
    u32 evCtrlRewardCursorUD(cControl::Message* pMsg);
    u32 evCtrlRewardCursorDecide(cControl::Message* pMsg);
    u32 evCtrlRewardSummaryCursorUD(cControl::Message* pMsg);
    u32 evCtrlRewardSummaryCursorDecide(cControl::Message* pMsg);
    u32 evCtrlRewardSummaryClick(cControl::Message* pMsg);
    u32 evCtrlRewardDetailCancel(cControl::Message* pMsg);
    u32 evCtrlRewardDetailClick(cControl::Message* pMsg);
    u32 evCtrlRankingCursorUD(cControl::Message* pMsg);
    u32 evCtrlRankingCursorDecide(cControl::Message* pMsg);
    u32 evCtrlRankingListCursorUD(cControl::Message* pMsg);
    u32 evCtrlRankingListClick(cControl::Message* pMsg);
    void startGetQuestInfo();
    void initCallback(u32 ErrorCode);
    void areaChangeCallBack(u32 ErrorCode);
    void discoveredCallBack(u32 ErrorCode);
    bool questwarplistRequestServer();
    void questwarplistCallBack();
    void requestRanking();
    void rankingCallback(u32 ErrorCode);
    void requestReward();
    void rewardCallback(u32 ErrorCode);
    void onStatus(u32 Status);
    void offStatus(u32 Status);
    bool isOnStatus(u32 Status);
    void initNews();
    void initEventPop();
    void initEventCommon();
    void initEvent();
    void initRanking();
    void initReward();
    void initEventReward();
    void initEventRewardSummary();
    void initEventRewardDetail();
    void initEventPage();
    void initQuestInfo();
    void setType(s32 Type);
    void setButtonGuide(s32 guideType);
    void setupMode(s32 Mode);
    void updateAreaListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateAreaListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateAreaQuestListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateAreaQuestListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateWait();
    void updateNews();
    void updateRanking();
    void updateReward();
    void updateEntryQuickParty();
    void updateCancelQuickParty();
    void updateMapCursor();
    MtVector2 getMapPos(u32 areaId);
    void nodispRewardIcon();
    void updateRewardRankingCommandButton();
    void updateRewardRankingCommandButtonCursor();
    void checkStrToEnd3Dots(MtString& rStr, MT_CTSTR pStr, u32 num);
    bool moveBonusDialog();
    void setupDialog();
    void openDialog();
    void closeDialog();
    s32 getAreaID(s32 currentPos);
    s32 getSelectAreaID();
    s32 getLandID(s32 areaId);
    s32 getSelectAreaListIndex(s32 areaId);
    s32 getLandNum();
    s32 getInnerAreaNum(s32 landId);
    s32 getInnerEnableAreaNum(s32 landId);
    MT_CTSTR getLandName(s32 landId);
    s32 getLandTopIndex(s32 landId);
    s32 getLandIdFromIdx(u32 index);
    u32 getRewardItemNumNorm(const nQuest::cGUINewspaperSetQuestInfo* pQuest);
    u32 getRewardItemNumRand(const nQuest::cGUINewspaperSetQuestInfo* pQuest);
    void setVisibleRewardIcons(_QuestInfo& QuestInfo, bool visible);
    void setVisibleRewardIconBase(_QuestInfo& QuestInfo, bool visible);
    void updateRewardIcons(_QuestInfo& QuestInfo);
    void setQuestRewardIcons(const nQuest::cGUINewspaperSetQuestInfo* pQuest, _QuestInfo& QuestInfo, bool isLoadImage);
    void setRewardIconControl(bool isRewardIconControl, s32 buttonPos);
    void updateRewardIconCursor();
    void unFocusRewardIcons();
    void updateDetail();
    void showDetail(u32 itemID);
    void hideDetail();
    bool isVisibleDetail();
    nQuest::cCycleContentsResultRewardInfo* getRewardTypedInfo(s32 summaryIdx, s32 detailIdx, u32 localRewardType);
    bool isDispCurrencyType(u32 itemId);
    void setupCycleContentsInfo();
    cCycleContentsNewsInfo* getCycleContentsPhaseInfo(s32 Index);
    void updateEventPop();
    void setContentsImage(u32 CategoryId, u32 SubCategoryId);
    void setContentsMiniImage(u32 CategoryId, u32 SubCategoryId, u32 SituationId);
    void updateEvent();
    void updateEventCommon();
    void updateEventMyInfo();
    void showSubMenu();
    void updateEventJoinButton();
    bool isEnableJoinContents();
    void updateEntryBoard();
    void setNoEntryAnnounce();
    void initEventInfoActiveControl();
    void showEventInfoPopup();
    void hideEventInfoPopup();
    bool isVisibleEventInfoPopup();
    void updateEventInfoPopup();
    void clearRankingDisp();
    void clearRankingFocus();
    void updateRankingCursor();
    void setVisibleRankingArea(bool visible);
    void showRankingTab();
    void setRankingList();
    bool isEnableRankingCmdButton();
    void initRankingActiveControl();
    void setRankingTabMode(s32 mode);
    void updateRankingListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateRankingListHide(uGUIBase::cScrollListItemBase* pDispItem);
    u32 getRankingCategoryNum();
    u32 submenuReqRanking(MtObject* pDummy, MtObject* pUnit);
    void clearRewardDisp();
    void clearRewardDetailDisp();
    void clearRewardFocus();
    void showRewardTab();
    void setRewardList();
    void setRewardDetailList();
    void initRewardActiveControl();
    void setRewardTabMode(s32 mode);
    void updateRewardTabCursor();
    void updateRewardTabList();
    void updateRewardTabDetailCursor();
    s32 getListIndex();
    u32 getRewardCategoryNum();
    bool isEnableRewardCmdButton();
    void updateRewardListSummaryDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateRewardListSummaryHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateRewardListDetailDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateRewardListDetailHide(uGUIBase::cScrollListItemBase* pDispItem);
    void createRewardItemLabel(const nQuest::cCycleContentsResultRewardInfo* pReward, MtString& OutStr);
    u32 submenuReqBorderReward(MtObject* pDummy, MtObject* pUnit);
    u32 submenuReqRankingReward(MtObject* pDummy, MtObject* pUnit);
    void requestAreaChange();
    void setSelectList(s32 Type, bool isReest);
    void setAreaSelectList();
    void setContentSelectList();
    void updateAreaList();
    void updateAreaCursor();
    void setChangeLand(Direction dir);
    bool isListHeader(s32 index);
    void setAreaQuestList();
    void updateAreaQuestList();
    void updateAreaQuestCursor();
    void setQuestImage(u32 Index);
    void updateQuestPage();
    void setVisibleLoadIcons(bool visible);
    void setVisibleQuestImages(bool visible);
    void setVisibleNoQuestMessage(bool visible);
    void setVisibleQuestInfo(bool visible);
    void setVisibleQuestMap(bool visible);
    void setVisibleRecommendFlash(bool isVisible);
    void setQuestInfo(s32 ArrayIndex, s32 AreaNo, _QuestInfo& QuestInfo, bool isLoadImage);
    void setDiscoverQuestInfo(const nQuest::cGUINewspaperSetQuestInfo* pQuest, _QuestInfo& QuestInfo, s32 AreaNo, bool isLoadImage);
    void setAreaQuestInfo(const nQuest::cGUINewspaperSetQuestInfo* pQuest, _QuestInfo& QuestInfo, s32 AreaNo, bool isLoadImage);
    void setVisiblePopularIcon(bool isVisible);
    void updateAreaInfo();
    void updateDiscoverInfo();
    void updateQuestInfo(u32 EndNum, u32 BonusNum, u32 PartyNum);
    bool isEnableQuestWarp();
    const CDataAreaWarpPoint* getWarpInfo();
    void setNoQuickPartyAnnounce();
    bool isEnableQuickParty();
    bool isAlreadyEntryQuickMatch();
    void setChangeQuest(Direction dir);
    void updateQuestPageNo();
    void setQuestInfoPopup();
    void resetQuestInfoPopup();
    void showQuestInfoPopup();
    void hideQuestInfoPopup();
    bool isVisibleQuestInfoPopup();
    bool isExistQuestInfoPopup();
    void updateQuestInfoPopup();
    void unFocusButton();
    void setQuestInfoButtonFrame(_QuestInfoButton& QuestButton, f32 Frame);
    void updateQuestSelectButton();
    void updateJumpButton();
    void updateQuickMatchButton();
    void setWarpDialog();
    bool moveWarpDialog();
    bool questwarpRequestServer();
    void questwarpCallBack();
    void setNoWarpAnnounce();
    void startQuickMatch();
    void startCancelQuickMatch();
    u32 getQuestSId(u32 ArrayIndex, u32 AreaNo);
    MT_CTSTR getQuestName(u32 ArrayIndex, u32 AreaNo);
    bool isPlayHoldingCycleContent();
    bool isPlayHoldingCycleContentNow();
    bool isHoldingCycleContent();
    void setCycleContentsPeriodPlate(const nQuest::cCycleContentsInfo* pinfo);
    void setCycleContentsPeriodPlate(nQuest::CYCLE_CONTENTS_PERIOD period, bool isPlayContents);
    bool isExistItem(u32 itemID);
    bool isEndQuest(const nQuest::cGUINewspaperSetQuestInfo* pQuest);
    bool isRecommandQuest(const nQuest::cGUINewspaperSetQuestInfo* pQuest);
    bool isPartyQuest(const nQuest::cGUINewspaperSetQuestInfo* pQuest);
    bool isBonusQuest(const nQuest::cGUINewspaperSetQuestInfo* pQuest);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rGUIMessage* mpGMDQuestRes;  // offset: 0x8d8
    u32 mStatus;  // offset: 0x8e0
    s32 mType;  // offset: 0x8e4
    s32 mMode;  // offset: 0x8e8
    s32 mListType;  // offset: 0x8ec
    s32 mFirstOpenType;  // offset: 0x8f0
    u32 mFirstOpenEventNo;  // offset: 0x8f4
    bool mIsEnableJoinContentsButton;  // offset: 0x8f8
    uGUISystemMsg* mpDialog;  // offset: 0x900
    u32 mDialogMode;  // offset: 0x908
    uGUISystemMsg* mpGUIDialog;  // offset: 0x910
    u32 mPartyBonusNum;  // offset: 0x918
    bool mIsBOBonus;  // offset: 0x91c
    cGUIControlMgr mControls;  // offset: 0x920
    s32 mAreaNum;  // offset: 0xdd0
    s32 mNowAreaID;  // offset: 0xdd4
    s32 mLandNum;  // offset: 0xdd8
    s32 mSelectAreaQuestNum;  // offset: 0xddc
    s32 mSelectAreaQuestNo;  // offset: 0xde0
    bool mIsFirstLoad;  // offset: 0xde4
    bool mIsEnableQuestWarp;  // offset: 0xde5
    bool mIsMoveQuickPartyMenu;  // offset: 0xde6
    u32 mQuestSelectButton;  // offset: 0xde8
    u32 mNoWarpType;  // offset: 0xdec
    u32 mNoQuickPartyType;  // offset: 0xdf0
    _infoList mQuestInfoList;  // offset: 0xdf8
    s32 mRewardMode;  // offset: 0x11b8
    s32 mRankingMode;  // offset: 0x11bc
    uGUIBase::cScrollList mRankingScrollbar;  // offset: 0x11c0
    s32 mEventNum;  // offset: 0x1470
    s32 mNowEventNo;  // offset: 0x1474
    bool mIsCreateRanking;  // offset: 0x1478
    uGUIBase::cTexArcLoader mContentsMiniImage;  // offset: 0x1480
    uGUIBase::cTexArcLoader mContentsImage;  // offset: 0x1508
    u32 mNoEntryType;  // offset: 0x1590
    MtTypedArray<cCycleContentsNewsInfo> mCycleContentPhaseInfo;  // offset: 0x1598
    s32 mRankingType;  // offset: 0x15b8
    u32 mRankingListNum;  // offset: 0x15bc
    f32 mRankingListBaseY;  // offset: 0x15c0
    f32 mRankingListOfsY;  // offset: 0x15c4
    s32 mRewardType;  // offset: 0x15c8
    uGUIBase::cScrollList mRewardSummaryScrollbar;  // offset: 0x15d0
    f32 mRewardSummaryListBaseY;  // offset: 0x1880
    f32 mRewardSummaryListOfsY;  // offset: 0x1884
    u32 mRewardSummaryListNum;  // offset: 0x1888
    uGUIBase::cScrollList mRewardDetailScrollbar;  // offset: 0x1890
    f32 mRewardDetailListBaseY;  // offset: 0x1b40
    f32 mRewardDetailListOfsY;  // offset: 0x1b44
    u32 mRewardDetailListNum;  // offset: 0x1b48
    bool mHasBorderReward;  // offset: 0x1b4c
    bool mHasRankingReward;  // offset: 0x1b4d
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x1b50
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x1ba8
    cGUIInstAnimation* mpQuestNoList;  // offset: 0x1c40
    cGUIInstNull* mpItemDetailBaseNull;  // offset: 0x1c48
    uGUIPopDetail01* mpGUIPopDetail;  // offset: 0x1c50
    cGUIObjMessage* mpAreaListTitle;  // offset: 0x1c58
    cGUIInstAnimation* mpAreaListMask;  // offset: 0x1c60
    cGUIInstAnimation* mpAreaListBase;  // offset: 0x1c68
    _AreaInfo mAreaInfo[3];  // offset: 0x1c70
    cScrollAreaDispList mAreaList[22];  // offset: 0x1cb8
    cGUIInstNull* mpAreaQuestListNull;  // offset: 0x27b8
    cScrollQuestDispList mAreaQuestList[17];  // offset: 0x27c0
    cGUIInstAnimation* mpAreaQuestInfo[3];  // offset: 0x3260
    cGUIInstNull* mpMapNull;  // offset: 0x3278
    cGUIInstAnimation* mpMap;  // offset: 0x3280
    cGUIInstAnimation* mpMapIcon;  // offset: 0x3288
    cGUIInstAnimation* mpMapPin;  // offset: 0x3290
    cGUIInstAnimation* mpLoadIconQuestImage;  // offset: 0x3298
    cGUIInstAnimation* mpLoadIconRewardIcon;  // offset: 0x32a0
    cGUIInstAnimation* mpLoadIconQuest;  // offset: 0x32a8
    cGUIObjMessage* mpQuestNum;  // offset: 0x32b0
    cGUIInstAnimation* mpInstAnimFlashRecommend;  // offset: 0x32b8
    cGUIInstAnimation* mpInstAnimPopular;  // offset: 0x32c0
    _QuestInfo mQuestList;  // offset: 0x32d0
    cGUIInstNull* mpQuestAreaInstNull;  // offset: 0x3f20
    cGUIInstNull* mpEventPop;  // offset: 0x3f28
    cGUIInstAnimation* mpEventPopBase;  // offset: 0x3f30
    cGUIInstAnimation* mpEventPopInst;  // offset: 0x3f38
    cGUIInstAnimation* mpEventPopImage;  // offset: 0x3f40
    cGUIInstAnimation* mpEventPopJoin;  // offset: 0x3f48
    cGUIObjMessage* mpEventPopJoinText;  // offset: 0x3f50
    cGUIObjMessage* mpEventPopTitle;  // offset: 0x3f58
    cGUIObjMessage* mpEventPopTimeS;  // offset: 0x3f60
    cGUIObjMessage* mpEventPopTimeE;  // offset: 0x3f68
    cGUIObjMessage* mpEventPopRank;  // offset: 0x3f70
    cGUIObjMessage* mpEventPopPoint;  // offset: 0x3f78
    cGUIInstAnimation* mpEventJoin;  // offset: 0x3f80
    cGUIObjMessage* mpEventJoinText;  // offset: 0x3f88
    cGUIObjMessage* mpEventRank;  // offset: 0x3f90
    cGUIObjMessage* mpEventUpdate;  // offset: 0x3f98
    uGUIBase::cReferenceUIBtnGuide mEventGuide;  // offset: 0x3fa0
    cGUIInstAnimation* mpEventTab;  // offset: 0x4038
    cGUIInstAnimation* mpCommandButton;  // offset: 0x4040
    uGUIBase::cReferenceUIIconItem mEventReward[5];  // offset: 0x4050
    cGUIObjMessage* mpEventTotalPoint;  // offset: 0x47d0
    cGUIObjMessage* mpEventTitle;  // offset: 0x47d8
    cGUIObjMessage* mpEventTime;  // offset: 0x47e0
    cGUIObjMessage* mpEventText;  // offset: 0x47e8
    cGUIObjMessage* mpEventPlace;  // offset: 0x47f0
    cGUIInstAnimation* mpEventImage;  // offset: 0x47f8
    cGUIObjMessage* mpEventStatus;  // offset: 0x4800
    cGUIObjMessage* mpEventStatusText;  // offset: 0x4808
    _QuestInfoButton mButtonJoin;  // offset: 0x4810
    cGUIInstance* mpButtonJoinInst;  // offset: 0x4830
    cGUIInstAnimation* mpEventCursor;  // offset: 0x4838
    cGUIObjMessage* mpRankingTitleRank;  // offset: 0x4840
    cGUIObjMessage* mpRankingTitleCharaName;  // offset: 0x4848
    cGUIObjMessage* mpRankingUpdate;  // offset: 0x4850
    cScrollRankingDispList mRankingList[12];  // offset: 0x4858
    cScrollRewardSummaryItemList mRewardSummaryList[15];  // offset: 0x4fd8
    cScrollRewardDetailItemList mRewardDetailList[15];  // offset: 0x5758
    uGUIBase::cScrollList mAreaScrollbar;  // offset: 0x5df0
    uGUIBase::cReferenceUIVlCursor mAreaListCursor;  // offset: 0x60a0
    f32 mAreaListBaseY;  // offset: 0x6150
    f32 mAreaListOfsY;  // offset: 0x6154
    uGUIBase::cScrollList mAreaQuestListScrollbar;  // offset: 0x6160
    uGUIBase::cReferenceUIVlCursor mAreaQuestListCursor;  // offset: 0x6410
    f32 mAreaQuestListBaseY;  // offset: 0x64c0
    f32 mAreaQuestListOfsY;  // offset: 0x64c4
    uGUIPopCmd01* mpSubMenu;  // offset: 0x64c8
public:
    static MyDTI DTI;
};
