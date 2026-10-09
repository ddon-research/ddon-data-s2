#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/cUIObject.h"
#include "../shared/nQuest.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class CDataAreaQuestHint;
class CDataAreaRankUpQuestInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector2;
class MtVector3;
class cAreaMasterSpotData;
class cAreaMasterSpotDetailData;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObject;
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cGUIAreaMasterData; }
class rAreaMasterRankData;
class rAreaMasterSpotData;
class rAreaMasterSpotDetailData;
class rGUI;
class rGUIMessage;
class rSoundRequest;
class uGUIGiveAndTake;
class uGUIMap;
class uGUIMapMini;
class uGUIPopDetail01;
class uGUIPopTopSel;
class uGUISystemMsg;

// Declarations
class uGUIAreaMaster;

// Type aliases from DWARF
using CAreaQuestHint = CDataAreaQuestHint;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIAreaMaster : public uGUIBase
{
public:
    enum
    {
        MODE_NORMAL = 0,
        MODE_SPOT = 1,
        MODE_HISTORY = 2,
        MODE_SUPPLIES = 3,
        MODE_PAWN = 4,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_DIALOG = 1,
        FLOW_TOP = 2,
        FLOW_QUEST_LIST = 3,
        FLOW_QUEST_INFO_WAIT = 4,
        FLOW_QUEST_INFO = 5,
        FLOW_QUEST_CONFIRM = 6,
        FLOW_QUEST_CONFIRM_WAIT = 7,
        FLOW_QUEST_MAP = 8,
        FLOW_SPOT_LIST = 9,
        FLOW_SPOT_INFO = 10,
        FLOW_SPOT_MAP = 11,
        FLOW_QUICK_PARTY = 12,
        FLOW_QUICK_PARTY_CANCEL = 13,
        FLOW_PAWN_EXPEDITION = 14,
        FLOW_HISTORY = 15,
        FLOW_SUPPLIES_LIST = 16,
        FLOW_SUPPLIES_TALK = 17,
        FLOW_SUPPLIES_RECEIVE = 18,
        FLOW_SUPPLIES_RECEIVE_WAIT = 19,
        FLOW_END = 20,
    };
    enum
    {
        TAB_DETAIL = 0,
        TAB_REWARD = 1,
        TAB_NUM = 2,
    };
    enum
    {
        TAB_POINT = 0,
        TAB_SUPPLIES = 1,
        TAB_POINT_NUM = 2,
    };
    enum
    {
        REQ_FLAG_GET_AREA_MASTER_INFO = 0,
        REQ_FLAG_GET_SUPPLY_LIST = 1,
        REQ_FLAG_GET_QUEST_LIST = 2,
        REQ_FLAG_BUY_QUEST_INFO = 3,
        REQ_FLAG_GET_SPOT_LIST = 4,
        REQ_FLAG_NUM = 5,
    };
    enum
    {
        FLOW_TYPE_NONE = 0,
        FLOW_TYPE_TOP = 1,
        FLOW_TYPE_QUEST = 2,
        FLOW_TYPE_SPOT = 3,
        FLOW_TYPE_HISTORY = 4,
        FLOW_TYPE_SUPPLIES = 5,
        FLOW_TYPE_END = 6,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CLOSE = 68,
        INPUTEVENT_CHECK = 69,
        INPUTEVENT_ADJUST_CURSOR = 70,
        INPUTEVENT_ADJUST_TAB = 71,
    };
    enum
    {
        QUEST_CATEGORY_DISCOVER = 0,
        QUEST_CATEGORY_UNDISCOVER = 1,
        QUEST_CATEGORY_NUM = 2,
    };
    enum
    {
        LIST_TYPE_QUEST = 0,
        LIST_TYPE_SPOT = 1,
    };
    enum
    {
        SPOT_CATEGORY_OUTLINE = 0,
        SPOT_CATEGORY_SAFE = 1,
        SPOT_CATEGORY_DANGER = 2,
        SPOT_CATEGORY_SEARCH = 3,
        SPOT_CATEGORY_NUM = 4,
    };
    enum
    {
        ITEM_TYPE_LIST = 0,
        ITEM_TYPE_PAWN = 1,
        ITEM_TYPE_BONUS = 2,
        ITEM_TYPE_SUPPLIES_HEADER = 3,
        ITEM_TYPE_SUPPLIES_ITEM = 4,
    };
public:
    class MyDTI;
    struct stCommon;
    struct stList;
    struct stListHeader;
    class cListItem;
    class cPawnListItem;
    class cPointItem;
    class cSuppliesHeaderItem;
    class cSuppliesItem;
    struct stQuestInfo;
    struct stMonsterItem;
    struct stDeliverItem;
    struct stMoneyItem;
    struct stRewardItem;
    struct stQuestBonusItem;
    struct stQuickPartyItem;
    class cSpotTexLoader;
    struct stMap;
    struct stPointList;
    struct stPointInfo;
    struct stVariable;
    class cDetailInfo;
    class cListInfo;
    class cPointInfo;
    class cSortData;
    class cSuppliesHeaderInfo;
    class cSuppliesInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stCommon
    {
    public:
        stCommon();
    public:
        cGUIInstNull* mpInstNullSign;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimListHeader;  // offset: 0x8
        cGUIObjMessage* mpObjMsgRank;  // offset: 0x10
        cGUIObjMessage* mpObjMsgRankVal;  // offset: 0x18
        cGUIObjMessage* mpObjMsgAreaName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x28
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x30
        cGUIObjMessage* mpObjMsgHead00;  // offset: 0x38
        cGUIObjMessage* mpObjMsgHead01;  // offset: 0x40
        cGUIObjMessage* mpObjMsgHead02;  // offset: 0x48
        cGUIObjMessage* mpObjMsgHead03;  // offset: 0x50
        cGUIObjMessage* mpObjMsgHead04;  // offset: 0x58
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x60
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0xf8
    };
public:
    struct stListHeader
    {
    public:
        stListHeader();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
        cGUIObjTexture* mpObjTexIcon;  // offset: 0x10
    };
public:
    class cListItem : public uGUIBase::cScrollListItemBase
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
        cListItem();
        // Address: 0x01ad93a0 - 0x01ad93a1 (1 bytes)
        virtual ~cListItem() {}
    public:
        cGUIInstAnimation* mpInstAnimQuest;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimPrice;  // offset: 0x60
        cGUIInstAnimation* mpInstAnimSpot;  // offset: 0x68
        cGUIInstAnimation* mpInstAnimSpotIcon;  // offset: 0x70
        cGUIInstAnimation* mpInstAnimDoor;  // offset: 0x78
        cGUIObjMessage* mpObjMsgQuestTitle;  // offset: 0x80
        cGUIObjMessage* mpObjMsgQuestLv;  // offset: 0x88
        cGUIObjMessage* mpObjMsgQuestLvVal;  // offset: 0x90
        cGUIObjMessage* mpObjMsgSpotTitle;  // offset: 0x98
        cGUIObjMessage* mpObjMsgSpotLv;  // offset: 0xa0
        cGUIObjMessage* mpObjMsgSpotLvVal;  // offset: 0xa8
        cGUIObjMessage* mpObjMsgIR;  // offset: 0xb0
        cGUIObjMessage* mpObjMsgIRVal;  // offset: 0xb8
        cGUIObjMessage* mpObjMsgPrice;  // offset: 0xc0
        cGUIObjMessage* mpObjMsgPriceUnit;  // offset: 0xc8
        cGUIObjMessage* mpObjMsgBought;  // offset: 0xd0
        static MyDTI DTI;
    };
public:
    class cPawnListItem : public uGUIBase::cScrollListItemBase
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
        cPawnListItem();
        // Address: 0x01ad9390 - 0x01ad9391 (1 bytes)
        virtual ~cPawnListItem() {}
    public:
        cGUIInstAnimation* mpInstAnimHotIcon;  // offset: 0x58
        cGUIObjMessage* mpObjMsgName;  // offset: 0x60
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x68
        static MyDTI DTI;
    };
public:
    class cPointItem : public uGUIBase::cScrollListItemBase
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
        cPointItem();
        // Address: 0x01ad9380 - 0x01ad9381 (1 bytes)
        virtual ~cPointItem() {}
    public:
        cGUIInstAnimation* mpInstAnimHeader;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimList;  // offset: 0x60
        cGUIObjMessage* mpObjMsgRank;  // offset: 0x68
        cGUIObjMessage* mpObjMsgRankVal;  // offset: 0x70
        cGUIObjMessage* mpObjMsgText;  // offset: 0x78
        cGUIObjMessage* mpObjMsgPt;  // offset: 0x80
        cGUIObjMessage* mpObjMsgPtVal;  // offset: 0x88
        cGUIObjMessage* mpObjMsgTest;  // offset: 0x90
        uGUIBase::cReferenceUIIconQuest mQuestIcon;  // offset: 0x98
        static MyDTI DTI;
    };
public:
    class cSuppliesHeaderItem : public uGUIBase::cScrollListItemBase
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
        cSuppliesHeaderItem();
        // Address: 0x01ad9370 - 0x01ad9371 (1 bytes)
        virtual ~cSuppliesHeaderItem() {}
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x58
        cGUIObjMessage* mpObjMsg;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    class cSuppliesItem : public uGUIBase::cScrollListItemBase
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
        cSuppliesItem();
        virtual ~cSuppliesItem();
    public:
        cGUIObjMessage* mpObjMsg;  // offset: 0x58
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    struct stMonsterItem
    {
    public:
        stMonsterItem();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjNull* mpObjNullPointer;  // offset: 0x8
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x10
        cGUIObjMessage* mpObjMsgLvVal;  // offset: 0x18
        cGUIObjMessage* mpObjMsgName;  // offset: 0x20
    };
public:
    struct stDeliverItem
    {
    public:
        stDeliverItem();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjNull* mpObjNullPointer;  // offset: 0x8
        cGUIObjMessage* mpObjMsgName;  // offset: 0x10
    };
public:
    struct stMoneyItem
    {
    public:
        stMoneyItem();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgVal;  // offset: 0x8
        cGUIObjMessage* mpObjMsgUnit;  // offset: 0x10
        cGUIObjMessage* mpObjMsgUnknown;  // offset: 0x18
    };
public:
    struct stRewardItem
    {
    public:
        stRewardItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimSpecial;  // offset: 0x8
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x10
    };
public:
    struct stQuestBonusItem
    {
    public:
        stQuestBonusItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgCaption;  // offset: 0x18
        cGUIObjMessage* mpObjMsgTerm;  // offset: 0x20
        cGUIObjPolygon* mpObjPolyLine;  // offset: 0x28
        uGUIBase::cReferenceUIChargesInfo mCharge;  // offset: 0x30
    };
public:
    struct stQuickPartyItem
    {
    public:
        stQuickPartyItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimIcon;  // offset: 0x10
        cGUIObjNull* mpObjNullPointer;  // offset: 0x18
    };
public:
    class cSpotTexLoader : public uGUIBase::cTexArcLoader
    {
    public:
        cSpotTexLoader();
        virtual ~cSpotTexLoader();
        void request(u32 spot_id, bool isImmediate);
        bool isExist(u32 spot_id);
    private:
        u32 mSpotId;  // offset: 0x84
    };
public:
    struct stMap
    {
    public:
        stMap();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullMiniMap;  // offset: 0x8
        cGUIInstNull* mpInstNullMiniMapOffset;  // offset: 0x10
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x18
        cGUIObjMessage* mpObjMsgPosX;  // offset: 0x20
        cGUIObjMessage* mpObjMsgPosY;  // offset: 0x28
        uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x30
        bool mIsDrawMap;  // offset: 0xc8
        u32 mFirstDraw;  // offset: 0xcc
        bool mIsFirstDraw;  // offset: 0xd0
    };
public:
    struct stPointList
    {
    public:
        stPointList();
    public:
        cGUIInstAnimation* mpInstAnimTip;  // offset: 0x0
        cGUIObjMessage* mpObjMsgNext;  // offset: 0x8
        cGUIObjMessage* mpObjMsgNextVal;  // offset: 0x10
        cGUIObjMessage* mpObjMsgNextUnit;  // offset: 0x18
        cGUIObjMessage* mpObjMsgTip;  // offset: 0x20
        cGUIObjTexture* mpObjTexTipCenter;  // offset: 0x28
        cGUIObjTexture* mpObjTexTipLeft;  // offset: 0x30
        uGUIBase::cReferenceUITab mTab;  // offset: 0x40
        bool mIsRequestQuestName;  // offset: 0xf0
    };
public:
    struct stPointInfo
    {
    public:
        stPointInfo();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgPreWeek;  // offset: 0x10
        cGUIObjMessage* mpObjMsgPrePt;  // offset: 0x18
        cGUIObjMessage* mpObjMsgPrePtVal;  // offset: 0x20
        cGUIObjMessage* mpObjMsgThisWeek;  // offset: 0x28
        cGUIObjMessage* mpObjMsgThisPt;  // offset: 0x30
        cGUIObjMessage* mpObjMsgThisPtVal;  // offset: 0x38
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 mParam_questlist;  // offset: 0x0
        s32 mParam_questheader;  // offset: 0x4
        s32 mParam_reward;  // offset: 0x8
        s32 mParam_cr_list00_x;  // offset: 0xc
        s32 mParam_tab00;  // offset: 0x10
        s32 mParam_cr_list01_x;  // offset: 0x14
        s32 mParam_monsterlist;  // offset: 0x18
        s32 mParam_list_goods;  // offset: 0x1c
        s32 mParam_spacing_reward;  // offset: 0x20
        s32 mParam_size_questlv;  // offset: 0x24
        s32 mParam_size_condition;  // offset: 0x28
        s32 mParam_ofst_condition;  // offset: 0x2c
        s32 mParam_size_caption;  // offset: 0x30
        s32 mParam_ofst_caption;  // offset: 0x34
        s32 mParam_size_monster;  // offset: 0x38
        s32 mParam_size_rewardheader;  // offset: 0x3c
        s32 mParam_size_reward;  // offset: 0x40
        s32 mParam_size_reward01;  // offset: 0x44
        s32 mParam_size_spotimg;  // offset: 0x48
        s32 mParam_size_specialtyheader;  // offset: 0x4c
        s32 mParam_size_selectreward;  // offset: 0x50
        s32 mParam_size_specialty;  // offset: 0x54
        s32 mParam_charges_size_x;  // offset: 0x58
        s32 mParam_size_suppliesheader;  // offset: 0x5c
        s32 mParam_size_supplieslist;  // offset: 0x60
        s32 mParam_tooltip_y;  // offset: 0x64
        s32 mParam_size_bonuslist;  // offset: 0x68
        s32 mParam_ofst_bonuslist;  // offset: 0x6c
    };
public:
    class cDetailInfo : public uGUIBase::cScrollListInfoBase
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
        cDetailInfo();
        // Address: 0x01adaac0 - 0x01adaac1 (1 bytes)
        virtual ~cDetailInfo() {}
        virtual void addMouseTouchList(cControl* pCtrl, s32 pos);  // vtable slot 6
    public:
        uGUIAreaMaster* mpOwner;  // offset: 0x28
        cGUIInstance* mpInstPointerTarget;  // offset: 0x30
        cGUIObject* mpObjPointerTarget;  // offset: 0x38
        bool mIsReward;  // offset: 0x40
        bool mIsButton;  // offset: 0x41
        bool mIsSpotButton;  // offset: 0x42
        static MyDTI DTI;
    };
public:
    class cListInfo : public uGUIBase::cScrollListInfoBase
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
        cListInfo();
        virtual ~cListInfo();
    public:
        nQuest::cGUIAreaMasterData mIndexData;  // offset: 0x28
        u32 mId;  // offset: 0x48
        u32 mPrice;  // offset: 0x4c
        u32 mIR;  // offset: 0x50
        u32 mNum;  // offset: 0x54
        u8 mListType;  // offset: 0x58
        bool mIsNew;  // offset: 0x59
        bool mIsRelease;  // offset: 0x5a
        bool mIsHotSpot;  // offset: 0x5b
        bool mIsBought;  // offset: 0x5c
        bool mIsBuyable;  // offset: 0x5d
        static MyDTI DTI;
    };
public:
    class cPointInfo : public uGUIBase::cScrollListInfoBase
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
        cPointInfo();
        // Address: 0x01adac30 - 0x01adac31 (1 bytes)
        virtual ~cPointInfo() {}
    public:
        u32 mIndex;  // offset: 0x28
        u32 mPoint;  // offset: 0x2c
        u32 mQuestId;  // offset: 0x30
        u8 mRank;  // offset: 0x34
        u8 mBonusType;  // offset: 0x35
        bool mIsRelease;  // offset: 0x36
        bool mIsDispQuestName;  // offset: 0x37
        static MyDTI DTI;
    };
public:
    class cSortData : public cUIObject
    {
    public:
        cSortData();
    public:
        const CAreaQuestHint* mpHint;  // offset: 0x8
        const nQuest::cGUIAreaMasterData* mpData;  // offset: 0x10
    };
public:
    class cSuppliesHeaderInfo : public uGUIBase::cScrollListInfoBase
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
        cSuppliesHeaderInfo();
        // Address: 0x01adaa30 - 0x01adaa31 (1 bytes)
        virtual ~cSuppliesHeaderInfo() {}
    public:
        u32 mPointLow;  // offset: 0x28
        u32 mPointHigh;  // offset: 0x2c
        static MyDTI DTI;
    };
public:
    class cSuppliesInfo : public uGUIBase::cScrollListInfoBase
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
        cSuppliesInfo();
        // Address: 0x01ada9e0 - 0x01ada9e1 (1 bytes)
        virtual ~cSuppliesInfo() {}
    public:
        u32 mItemId;  // offset: 0x28
        u32 mItemNum;  // offset: 0x2c
        static MyDTI DTI;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstNull* mpInstNullScroll;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x8
        uGUIAreaMaster::stListHeader mHeader[4];  // offset: 0x10
        uGUIAreaMaster::cListItem mList[24];  // offset: 0x70
        uGUIAreaMaster::cPawnListItem mPawnList[24];  // offset: 0x14b0
        uGUIAreaMaster::cPointItem mPoint[19];  // offset: 0x1f30
        uGUIAreaMaster::cSuppliesHeaderItem mSuppliesHeader[9];  // offset: 0x3b18
        uGUIAreaMaster::cSuppliesItem mSuppliesItem[14];  // offset: 0x3ec0
        uGUIBase::cScrollList mListCtrl;  // offset: 0x5900
        f32 mQuestListBasePos;  // offset: 0x5bb0
        f32 mQuestListCursorOffset;  // offset: 0x5bb4
        f32 mPointListCursorOffset;  // offset: 0x5bb8
        f32 mHeaderOffset;  // offset: 0x5bbc
        static const u32 header_num = 4;
        static const u32 list_num = 24;
        static const u32 point_num = 19;
        static const u32 supplies_header_num = 9;
        static const u32 supplies_item_num = 14;
    };
public:
    struct stQuestInfo
    {
    public:
        stQuestInfo();
    public:
        cGUIInstNull* mpInstNullImg;  // offset: 0x0
        cGUIInstNull* mpInstNullLv;  // offset: 0x8
        cGUIInstNull* mpInstNullCondition;  // offset: 0x10
        cGUIInstNull* mpInstNullItemHeader;  // offset: 0x18
        cGUIInstNull* mpInstNullCaption;  // offset: 0x20
        cGUIInstNull* mpInstNullMonster;  // offset: 0x28
        cGUIInstNull* mpInstNullDeliveryItem;  // offset: 0x30
        cGUIInstNull* mpInstNullRewardHeader;  // offset: 0x38
        cGUIInstNull* mpInstNullReward;  // offset: 0x40
        cGUIInstNull* mpInstNullAP;  // offset: 0x48
        cGUIInstNull* mpInstNullNoItem;  // offset: 0x50
        cGUIInstNull* mpInstNullItem;  // offset: 0x58
        cGUIInstNull* mpInstNullBonus;  // offset: 0x60
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x68
        cGUIInstAnimation* mpInstAnimEmblem;  // offset: 0x70
        cGUIInstAnimation* mpInstAnimMonsterHeader;  // offset: 0x78
        cGUIInstAnimation* mpInstAnimDeliverItemHeader;  // offset: 0x80
        cGUIInstAnimation* mpInstAnimPeriod;  // offset: 0x88
        cGUIInstAnimation* mpInstAnimRewardBox[3];  // offset: 0x90
        cGUIInstAnimation* mpInstAnimAreaPoint;  // offset: 0xa8
        cGUIObjMessage* mpObjMsgQuestTitle;  // offset: 0xb0
        cGUIObjMessage* mpObjMsgSpotTitle;  // offset: 0xb8
        cGUIObjMessage* mpObjMsgRecommend;  // offset: 0xc0
        cGUIObjMessage* mpObjMsgLv;  // offset: 0xc8
        cGUIObjMessage* mpObjMsgLvVal;  // offset: 0xd0
        cGUIObjMessage* mpObjMsgConditionHeader;  // offset: 0xd8
        cGUIObjMessage* mpObjMsgCondition;  // offset: 0xe0
        cGUIObjMessage* mpObjMsgCaption;  // offset: 0xe8
        cGUIObjMessage* mpObjMsgClient;  // offset: 0xf0
        cGUIObjMessage* mpObjMsgAreaName;  // offset: 0xf8
        cGUIObjMessage* mpObjMsgAreaPointVal;  // offset: 0x100
        cGUIObjMessage* mpObjMsgAreaPointUnit;  // offset: 0x108
        cGUIObjMessage* mpObjMsgAreaPointUnknown;  // offset: 0x110
        cGUIObjMessage* mpObjMsgMonster;  // offset: 0x118
        cGUIObjMessage* mpObjMsgDeliveryItem;  // offset: 0x120
        cGUIObjMessage* mpObjMsgMonsterUnknown;  // offset: 0x128
        cGUIObjMessage* mpObjMsgSelectReward;  // offset: 0x130
        cGUIObjMessage* mpObjMsgRandomReward;  // offset: 0x138
        cGUIObjMessage* mpObjMsgBonus;  // offset: 0x140
        cGUIObjMessage* mpObjMsgBonusUnknown;  // offset: 0x148
        cGUIObjMessage* mpObjMsgPeriod;  // offset: 0x150
        cGUIObjMessage* mpObjMsgReward;  // offset: 0x158
        cGUIObjMessage* mpObjMsgItem;  // offset: 0x160
        cGUIObjMessage* mpObjMsgNoItem;  // offset: 0x168
        cGUIObjNull* mpObjNullCondition;  // offset: 0x170
        cGUIObjNull* mpObjNullCaption;  // offset: 0x178
        cGUIObjNull* mpObjNullReward;  // offset: 0x180
        cGUIObjNull* mpObjNullMonster;  // offset: 0x188
        cGUIObjNull* mpObjNullDeliveryItem;  // offset: 0x190
        cGUIObjTexture* mpObjTexSpotImg;  // offset: 0x198
        cGUIObjTexture* mpObjTexCaptionBg;  // offset: 0x1a0
        cGUIObjTexture* mpObjTexCaptionBottom;  // offset: 0x1a8
        uGUIAreaMaster::stMonsterItem mMonster[30];  // offset: 0x1b0
        uGUIAreaMaster::stDeliverItem mDeliverItem[5];  // offset: 0x660
        uGUIAreaMaster::stMoneyItem mMoney[3];  // offset: 0x6d8
        uGUIAreaMaster::stRewardItem mReward[7];  // offset: 0x740
        uGUIAreaMaster::stQuestBonusItem mBonus[6];  // offset: 0x1230
        uGUIAreaMaster::stQuickPartyItem mQuickParty;  // offset: 0x1b60
        uGUIBase::cScrollListItemBase mListItem[30];  // offset: 0x1b80
        uGUIBase::cReferenceUIButton mButton;  // offset: 0x25d0
        uGUIBase::cReferenceUITab mTab;  // offset: 0x2760
        uGUIBase::cScrollList mScrollCtrl;  // offset: 0x2810
        uGUIAreaMaster::cSpotTexLoader mTexLoader;  // offset: 0x2ac0
        nQuest::SCHEDULE_ID mNowScheduleId;  // offset: 0x2b48
        u32 mRewardIndex;  // offset: 0x2b58
        u32 mRewardNum;  // offset: 0x2b5c
        u32 mMonsterNum;  // offset: 0x2b60
        u32 mDeliverItemNum;  // offset: 0x2b64
        f32 mUpdateTimer;  // offset: 0x2b68
        f32 mCaptionBgDefSize;  // offset: 0x2b6c
        f32 mCaptionBottomDefPos;  // offset: 0x2b70
        bool mIsUpdate;  // offset: 0x2b74
        static const u32 monster_num = 30;
        static const u32 deliver_item_num = 5;
        static const u32 money_num = 3;
        static const u32 reward_num = 7;
        static const u32 bonus_num = 6;
        static const u32 list_item_num = 30;
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
    void setupMouseCollision(cControl* pCtrl, s32 pos, bool isReward, bool isButton, bool isQuickParty);
    uGUIAreaMaster();
    virtual ~uGUIAreaMaster();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void setMenuMode(u32 area_id, u32 mode);
    s32 getSuppliesTalkNo();
    void resetSuppliesTalkNo();
    bool isPawnExpeditionSally();
    bool isPawnExpeditionReqSuccess();
protected:
    virtual void adjustScale();  // vtable slot 84
private:
    void setFlowId(u32 flow_id);
    void setProcess(u32 flow_id, bool isInit);
    void setupWindowActive();
    u32 getFlowType(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateSetFlow();
    void updateMove();
    void updateWait();
    void updateExit();
    void initDialog();
    void updateDialog();
    void initTop();
    void inputTop();
    void decideTop();
    void cancelTop();
    void cancelToTop();
    void initQuest();
    void createQuestList();
    void clearInfoVisible();
    void clearQuestInfo();
    void setupQuestInfo();
    void setupCaptionPos(s32& top_pos, s32& list_pos, bool isClient, bool isAddInfo);
    void setupMonsterPos(u32 lv, MT_CTSTR name, s32& top_pos, s32& list_pos);
    void setupDeliverItemPos(u32 num, u32 itemId, s32& top_pos, s32& list_pos);
    void setupBonusPos(stQuestBonusItem& bonus, s32& top_pos, s32& list_pos, s32 bonus_top);
    void updateQuestInfoWait();
    void updateQuestInfo();
    void setupItemIcon(u32& count, u32 id, u32 num, bool isOffset, bool isSpecial);
    void setupUnkownIcon(u32& count, bool isOffset);
    void decideQuestList();
    void decideQuestInfo();
    void cancelQuestInfo();
    void setupQuestConfirm();
    void updateQuestConfirm();
    void decideQuestConfirm();
    void cancelQuestConfirm();
    void adjustQuestListCursor();
    void adjustQuestInfoCursor();
    void adjustQuestTab();
    void setupLRCtrlEnable();
    cDetailInfo* addInfo(cGUIInstance* pInst, cGUIObject* pObj, s32 top, s32 bottom, s32 mouse_top);
    void setupDetailItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideDetailItem(uGUIBase::cScrollListItemBase* pItemBase);
    void initSpot();
    void createSpotList();
    bool isPawnHotSpot(u32 spot_id);
    u32 getSallyNum(u32 spot_id);
    const cAreaMasterSpotData* getSpotData(u32 spot_id);
    const cAreaMasterSpotDetailData* getSpotDetailData(u32 spot_id);
    void setupSpotInfo();
    void decideSpotList();
    void decideSpotInfo();
    void cancelSpotInfo();
    void adjustSpotListCursor();
    void adjustSpotInfoCursor();
    void setupQuickParty();
    void updateQuickParty();
    void setupQuickPartyCancel();
    void updateQuickPartyCancel();
    void setupPawnExpedition();
    void updatePawnExpedition();
    void makeYesNoDialog();
    void makeNotice(MT_CTSTR msg);
    bool reqCostRecover();
    bool reqSallyInfo();
    bool reqSally();
    bool reqGoldSally();
    void callbackPawnExpeditionReq();
    void initHistory();
    void createHistoryList();
    u32 getRankUpQuestId(u8 rank, const MtTypedArray<CDataAreaRankUpQuestInfo>& list);
    void adjustHistoryCursor(bool isImmediate);
    void initSuppliesList();
    void createSuppliesList();
    void adjustSuppliesListCursor(bool isImmediate);
    void initSupplies();
    void updateSuppliesTalk();
    void initSuppliesReceive();
    void updateSuppliesReceive();
    void decideSuppliesReceive();
    void cancelSuppliesReceive();
    void updateSuppliesReceiveWait();
    void clearListHeader();
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    cListInfo* getListInfo(u32 index);
    cListInfo* getListInfo();
    cPointInfo* getPointInfo(u32 index);
    cPointInfo* getPointInfo();
    void setMapScheduleId(u32 schedule_id);
    void setDrawMap(bool isDraw);
    bool isDrawMap();
    bool setupQuestMap();
    void setupSpotMap();
    void setupLargeMap();
    void updateLargeMap();
    s32 getStageNoQuestMap(nQuest::SCHEDULE_ID sdlId);
    void drawDetail(u32 item_id);
    void hideDetail();
    void updateDetail();
    void calcMapPos(bool in_force);
    bool questListSort(const cSortData* pA, const cSortData* pB, u32 param);
    bool isRequest(u32 flag);
    void setRequest(u32 flag);
    void clearRequest(u32 flag);
    void requestServer(u32 next_flow_id);
    bool requestAreaMasterInfo();
    void callbackAreaMasterInfo();
    bool requestGetSupplyList();
    void callbackGetSupplyList();
    bool requestGetQuestList();
    void callbackGetQuestList();
    bool requestBuyQuestInfo();
    void callbackBuyQuestInfo();
    bool requestGetSpotInfoList();
    void callbackGetSpotInfoList();
    void eventDecide();
    void eventCancel();
    void eventClose();
    void eventCheck();
    void eventAdjustCursor();
    void eventAdjustTab();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlCheck(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustTab(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getQuestMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    MT_CTSTR getMsg(rGUIMessage* pMsg, u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rGUIMessage* mpGMDQuestRes;  // offset: 0x8d8
    rGUIMessage* mpGMDRankRes;  // offset: 0x8e0
    rGUIMessage* mpGMDSpotNameRes;  // offset: 0x8e8
    rGUIMessage* mpGMDSpotInfoRes;  // offset: 0x8f0
    rGUIMessage* mpGMDSpotCategory;  // offset: 0x8f8
    rSoundRequest* mpSeRes;  // offset: 0x900
    rAreaMasterRankData* mpRankRes;  // offset: 0x908
    rAreaMasterSpotData* mpSpotRes;  // offset: 0x910
    rAreaMasterSpotDetailData* mpSpotDetailRes;  // offset: 0x918
    cGUIInstNull* mpInstNull;  // offset: 0x920
    u32 mMode;  // offset: 0x928
    u32 mFlowId;  // offset: 0x92c
    u32 mFlowIdNext;  // offset: 0x930
    u32 mFlowIdBack;  // offset: 0x934
    u32 mSubFlowId;  // offset: 0x938
    u32 mRequestFlag;  // offset: 0x93c
    u32 mAreaId;  // offset: 0x940
    nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x948
    s32 mSuppliesTalkNo;  // offset: 0x958
    u32 mDrawItemId;  // offset: 0x95c
    u32 mSelectItemId;  // offset: 0x960
    stCommon mCommon;  // offset: 0x968
    stList mList;  // offset: 0xac0
    stQuestInfo mQuestInfo;  // offset: 0x6680
    stMap mMap;  // offset: 0x9200
    stPointList mPointList;  // offset: 0x92e0
    stPointInfo mPointInfo;  // offset: 0x93e0
    stVariable mVar;  // offset: 0x9420
    cControl* mpDecideCtrl;  // offset: 0x9490
    cControl* mpCancelCtrl;  // offset: 0x9498
    cControl* mpMapCtrl;  // offset: 0x94a0
    uGUIBase::cHorizontalList* mpInfoLRCtrl;  // offset: 0x94a8
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x94b0
    MtVector3 mMiniMapPos;  // offset: 0x94c0
    MtVector2 mPos2CenterMapOld;  // offset: 0x94d0
    MtStringEx<256> mTempStr;  // offset: 0x94d8
    uGUIPopTopSel* mpGUIPopTopSel;  // offset: 0x95e0
    uGUIGiveAndTake* mpGUIGiveAndTake;  // offset: 0x95e8
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x95f0
    uGUIMapMini* mpGUIMap;  // offset: 0x95f8
    uGUIMap* mpGUILargeMap;  // offset: 0x9600
    uGUIPopDetail01* mpGUIPopDetail;  // offset: 0x9608
    bool mIsInit;  // offset: 0x9610
    bool mIsCreateList;  // offset: 0x9611
    bool mIsPawnExpeditionSally;  // offset: 0x9612
    bool mIsPawnExpeditionReqSuccess;  // offset: 0x9613
    bool mIsPawnExpeditionUseGP;  // offset: 0x9614
public:
    static MyDTI DTI;
};
