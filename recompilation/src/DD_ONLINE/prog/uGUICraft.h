#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/Common.h"
#include "Protocol/PacketData/Craft.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtString.h"
#include "cContextInstance.h"
#include "cControl.h"
#include "cEquipData.h"
#include "cItemParam.h"
#include "cUIObject.h"
#include "nDDOUtility.h"
#include "rItemList.h"
#include "uGUIBase.h"

// Forward declarations
class CDataCommonU32;
class CDataCraftPawnList;
class CDataCraftProgress;
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector2;
class cContextInstHm;
class cControl;
class cEquipData;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjChildAnimationRoot;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObjTextureSet;
class cItemParam;
class cPawnListParam;
class rEffectProvider;
class rGUI;
class rGUIMessage;
class rSoundRequest;
class uGUIAnnounce;
class uGUIPopCmd01;
class uGUIPopCraftDetail;
class uGUIPopDetail01;
class uGUIPopFilter;
class uGUIPopNumber01;
class uGUIPopTopSel;
class uGUIQueueAnnounceLvUp;
class uGUISystemMsg;
class uScreenSpace;

// Declarations
class uGUICraft;

// Type aliases from DWARF
using CCraftPawnList = CDataCraftPawnList;
using CCraftProgress = CDataCraftProgress;
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUICraft : public uGUIBase
{
public:
    enum
    {
        FLOW_TOP = 0,
        FLOW_MAKE_CATEGORY = 1,
        FLOW_MAKE_ITEM = 2,
        FLOW_MAKE_ORDER = 3,
        FLOW_MAKE_ADD = 4,
        FLOW_MAKE_MAIN = 5,
        FLOW_MAKE_SUB = 6,
        FLOW_MAKE_CONFIRM = 7,
        FLOW_MAKE_RESULT_WAIT = 8,
        FLOW_MAKE_RESULT = 9,
        FLOW_MAKE_PROGRESS = 10,
        FLOW_MAKE_GOLD_CONFIRM = 11,
        FLOW_UPGRADE_CATEGORY = 12,
        FLOW_UPGRADE_ITEM = 13,
        FLOW_UPGRADE_ORDER = 14,
        FLOW_UPGRADE_MAIN = 15,
        FLOW_UPGRADE_SUB = 16,
        FLOW_UPGRADE_CONFIRM = 17,
        FLOW_UPGRADE_RESULT_WAIT = 18,
        FLOW_UPGRADE_RESULT = 19,
        FLOW_CREST_CATEGORY = 20,
        FLOW_CREST_ITEM = 21,
        FLOW_CREST_ORDER = 22,
        FLOW_CREST_MAIN = 23,
        FLOW_CREST_ADD = 24,
        FLOW_CREST_CONFIRM = 25,
        FLOW_CREST_RESULT_WAIT = 26,
        FLOW_CREST_RESULT = 27,
        FLOW_CREST_BREAK_CONFIRM = 28,
        FLOW_CREST_BREAK_RESULT_WAIT = 29,
        FLOW_CREST_BREAK_RESULT = 30,
        FLOW_COLOR_CATEGORY = 31,
        FLOW_COLOR_ITEM = 32,
        FLOW_COLOR_ORDER = 33,
        FLOW_COLOR_MAIN = 34,
        FLOW_COLOR_ADD_CATEGORY = 35,
        FLOW_COLOR_ADD_ITEM = 36,
        FLOW_COLOR_CONFIRM = 37,
        FLOW_COLOR_RESULT_WAIT = 38,
        FLOW_COLOR_RESULT = 39,
        FLOW_LV_UP = 40,
        FLOW_EXAM = 41,
        FLOW_EXAM_CLEAR_IN = 42,
        FLOW_EXAM_CLEAR_IN_WAIT = 43,
        FLOW_EXAM_CLEAR = 44,
        FLOW_POINT_PAWN = 45,
        FLOW_POINT = 46,
        FLOW_POINT_INPUT = 47,
        FLOW_POINT_CONFIRM = 48,
        FLOW_SUB_MENU = 49,
        FLOW_CHARA_SELECT = 50,
        FLOW_CHARA_REQ = 51,
        FLOW_FILTER = 52,
        FLOW_GET_CHEST = 53,
        FLOW_ANALYZE = 54,
        FLOW_CREATE_NUM_SELECT = 55,
        FLOW_NONE = 56,
        FLOW_INVISIBLE = 57,
    };
    enum
    {
        BUTTON_YES = 0,
        BUTTON_NO = 1,
        BUTTON_NUM = 2,
        BUTTON_BAG = 0,
        BUTTON_BOX = 1,
    };
    enum
    {
        GUIDE_DECIDE = 0,
        GUIDE_PAWN_OFF = 1,
        GUIDE_TOPPING_OFF = 2,
        GUIDE_CREST_OFF = 3,
        GUIDE_DETAIL = 4,
        GUIDE_CHARA_SELECT = 5,
        GUIDE_SUBMENU = 6,
        GUIDE_GET_CHEST = 7,
        GUIDE_NUM = 8,
    };
    enum
    {
        ORDER_UPGRADE_MAIN_ITEM = 0,
        ORDER_UPGRADE_POINT = 1,
        ORDER_UPGRADE_MAIN = 2,
        ORDER_UPGRADE_SUB_00 = 3,
        ORDER_UPGRADE_SUB_01 = 4,
        ORDER_UPGRADE_SUB_02 = 5,
        ORDER_UPGRADE_NUM = 6,
    };
    enum
    {
        TAB_ITEM_WEAPON = 0,
        TAB_ITEM_ARMOR = 1,
        TAB_ITEM_UPGRADE_NUM = 2,
        TAB_ITEM_USE = 2,
        TAB_ITEM_MATERIAL = 3,
        TAB_ITEM_SPECIAL = 4,
        TAB_ITEM_NUM = 5,
    };
    enum
    {
        TAB_MAIN_PAWN = 0,
        TAB_SUB_PAWN = 1,
        TAB_PAWN_NUM = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CLOSE = 68,
        INPUTEVENT_CHECK = 69,
        INPUTEVENT_SUB_MENU = 70,
        INPUTEVENT_POP_SEL_00 = 71,
        INPUTEVENT_POP_SEL_01 = 72,
        INPUTEVENT_GET_CHEST = 73,
        INPUTEVENT_ANALYZE = 74,
        INPUTEVENT_CREATE_NUM_SELECT = 75,
        INPUTEVENT_ADJUST_CURSOR = 76,
        INPUTEVENT_ADJUST_TAB = 77,
        INPUTEVENT_LEFT = 78,
        INPUTEVENT_RIGHT = 79,
    };
    enum
    {
        POINT_00 = 0,
        POINT_01 = 1,
        POINT_02 = 2,
        POINT_03 = 3,
        POINT_04 = 4,
        POINT_DECIDE = 5,
        POINT_NUM = 6,
    };
    enum
    {
        ORDER_MAIN_ITEM = 0,
        ORDER_MAIN = 1,
        ORDER_SUB_00 = 2,
        ORDER_SUB_01 = 3,
        ORDER_SUB_02 = 4,
        ORDER_ADD_ITEM = 5,
        ORDER_NUM = 6,
    };
    enum
    {
        ORDER_CREST_MAIN_ITEM = 0,
        ORDER_CREST_MAIN = 1,
        ORDER_CREST_SLOT_00 = 2,
        ORDER_CREST_SLOT_01 = 3,
        ORDER_CREST_SLOT_02 = 4,
        ORDER_CREST_SLOT_03 = 5,
        ORDER_CREST_NUM = 6,
    };
    enum
    {
        ORDER_COLOR_MAIN_ITEM = 0,
        ORDER_COLOR_NOW = 1,
        ORDER_COLOR_MAIN = 2,
        ORDER_COLOR_ADD = 3,
        ORDER_COLOR_NEXT = 4,
        ORDER_COLOR_NUM = 5,
    };
    enum
    {
        USE_ITEM_CATE_HP = 0,
        USE_ITEM_CATE_ST = 1,
        USE_ITEM_CATE_REPAIR = 2,
        USE_ITEM_CATE_ENCHANT = 3,
        USE_ITEM_CATE_THROW = 4,
        USE_ITEM_CATE_KEY = 5,
        USE_ITEM_CATE_JOB = 6,
        USE_ITEM_CATE_NUM = 7,
    };
    enum
    {
        MATERIAL_CATE_INGOT = 0,
        MATERIAL_CATE_CLOTH = 1,
        MATERIAL_CATE_THREAD = 2,
        MATERIAL_CATE_SCROLL = 3,
        MATERIAL_CATE_STR_WEP = 4,
        MATERIAL_CATE_STR_ARM = 5,
        MATERIAL_CATE_AREA = 6,
        MATERIAL_CATE_OTHER = 7,
        MATERIAL_CATE_NUM = 8,
    };
    enum
    {
        SPECIAL_CATE_EXAM = 0,
        SPECIAL_CATE_FURNITURE = 1,
        SPECIAL_CATE_NUM = 2,
    };
    enum
    {
        ITEM_TYPE_MAKE = 0,
        ITEM_TYPE_UPGRADE_EQUIP = 1,
        ITEM_TYPE_CREST_COLOR_EQUIP = 2,
        ITEM_TYPE_COLOR = 3,
    };
    enum
    {
        FILTER_JOB_ALL = 0,
        FILTER_JOB = 1,
        FILTER_IR_USE = 2,
        FILTER_IR_MIN = 3,
        FILTER_IR_MAX = 4,
        FILTER_EQUIP_USE = 5,
        FILTER_EQUIP_MIN = 6,
        FILTER_EQUIP_MAX = 7,
        FILTER_SEX = 8,
    };
public:
    class MyDTI;
    struct stPawnList;
    struct stPawnListItem;
    struct stMain;
    struct stOrder;
    struct stOrderListItem;
    struct stOrderCreateNum;
    struct stAnalyzeButton;
    struct stMakeItem;
    struct stCategoryListItem;
    class cListItem;
    struct stListHeader;
    struct stPawnSelect;
    struct stPawnSelectListItem;
    struct stAddItem;
    class cAddListItem;
    struct stResult;
    struct stTotal;
    struct stPawnIcon;
    struct stSkillParam;
    struct stTotalOrder;
    struct stStatus;
    struct stPawnParam;
    struct stExam;
    struct stPoint;
    struct stPointItem;
    struct stFilter;
    struct stVariable;
    struct stWatchTime;
    class cListInfo;
    class cCreateRecipeSort;
    class cAddListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stPawnListItem
    {
    public:
        stPawnListItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjNull* mpObjNullAnnounce;  // offset: 0x10
        cGUIObjNull* mpObjNullExam;  // offset: 0x18
        cGUIObjMessage* mpObjMsgName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgTime;  // offset: 0x28
        cGUIObjMessage* mpObjMsgLevel;  // offset: 0x30
        cGUIObjMessage* mpObjMsgAnnounce;  // offset: 0x38
        cGUIObjChildAnimationRoot* mpObjRootProgress;  // offset: 0x40
        uGUIBase::cReferenceUIIconCraftLv mCraftLvIcon;  // offset: 0x48
        uGUIBase::cReferenceUIChargesInfo mCharge;  // offset: 0xa0
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimHeader;  // offset: 0x10
        cGUIObjNull* mpObjNullHeader;  // offset: 0x18
        cGUIObjMessage* mpObjMsgGuide;  // offset: 0x20
        cGUIObjMessage* mpObjMsgHeader00;  // offset: 0x28
        cGUIObjMessage* mpObjMsgHeader01;  // offset: 0x30
        cGUIObjMessage* mpObjMsgHeader02;  // offset: 0x38
        cGUIObjMessage* mpObjMsgHeader03;  // offset: 0x40
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x48
    };
public:
    struct stOrderListItem
    {
    public:
        stOrderListItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimTextBox;  // offset: 0x10
        cGUIObjChildAnimationRoot* mpObjRootCrestIcon;  // offset: 0x18
        cGUIObjNull* mpObjNullPointerPos;  // offset: 0x20
        cGUIObjNull* mpObjNullBtn;  // offset: 0x28
        cGUIObjNull* mpObjNullCraftNum;  // offset: 0x30
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x38
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x40
        cGUIObjMessage* mpObjMsgTextBox;  // offset: 0x48
        cGUIObjMessage* mpObjMsgCraftNum;  // offset: 0x50
        cGUIObjPolygon* mpObjPolyIconCollision;  // offset: 0x58
        cGUIObjTexture* mpObjTexTextCollision;  // offset: 0x60
        cGUIObjTexture* mpObjTexCrestLockIcon;  // offset: 0x68
        uGUIBase::cReferenceUIIconCraftLv mCraftLvIcon;  // offset: 0x70
        u32 mMenuNo;  // offset: 0xc8
        bool mIsSelectable;  // offset: 0xcc
        bool mIsEnable;  // offset: 0xcd
        bool mIsCrestDisable;  // offset: 0xce
    };
public:
    struct stOrderCreateNum
    {
    public:
        stOrderCreateNum();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjNull* mpObjNullPointer;  // offset: 0x8
        cGUIObjPolygon* mpObjPolyMouseCollision;  // offset: 0x10
        cGUIObjTexture* mpObjTexMouseCollision;  // offset: 0x18
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x20
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x28
        cGUIObjMessage* mpObjMsgLimit;  // offset: 0x30
    };
public:
    struct stAnalyzeButton
    {
    public:
        stAnalyzeButton();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjNull* mpObjNullPointer;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
    };
public:
    struct stCategoryListItem
    {
    public:
        stCategoryListItem();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimColor;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        cGUIObjTextureSet* mpObjTexColor;  // offset: 0x18
        cGUIObjPolygon* mpObjPolyCollision;  // offset: 0x20
    };
public:
    struct stListHeader
    {
    public:
        stListHeader();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgCraft;  // offset: 0x8
        cGUIObjMessage* mpObjMsgLvVal;  // offset: 0x10
        cGUIObjMessage* mpObjMsgExam;  // offset: 0x18
    };
public:
    struct stPawnSelectListItem
    {
    public:
        stPawnSelectListItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimAddItemIcon;  // offset: 0x10
        cGUIObjMessage* mpObjMsgName;  // offset: 0x18
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x20
        cGUIObjMessage* mpObjMsgStatus;  // offset: 0x28
        cGUIObjMessage* mpObjMsgLimit;  // offset: 0x30
        cGUIObjMessage* mpObjMsgPoint;  // offset: 0x38
        cGUIObjNull* mpObjNullExam;  // offset: 0x40
        cGUIObjChildAnimationRoot* mpObjRootProgress;  // offset: 0x48
        cGUIObjPolygon* mpObjPolyCollision;  // offset: 0x50
        uGUIBase::cReferenceUIIconCraftLv mCraftLvIcon;  // offset: 0x58
        uGUIBase::cReferenceUIChargesInfo mCharge;  // offset: 0xb0
    };
public:
    class cAddListItem : public uGUIBase::cScrollListItemBase
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
        cAddListItem();
    public:
        cGUIObjMessage* mpObjMsgName;  // offset: 0x58
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x60
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x70
        uGUIBase::cReferenceUIIconStorage mStorage;  // offset: 0x1f0
        static MyDTI DTI;
    };
public:
    struct stResult
    {
    public:
        stResult();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimSuccess;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimGradeUp;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimPlus;  // offset: 0x18
        cGUIInstAnimation* mpInstAnimGaugeEffect;  // offset: 0x20
        cGUIObjChildAnimationRoot* mpObjRootGradeIcon[4];  // offset: 0x28
        cGUIObjChildAnimationRoot* mpObjRootCrestIcon;  // offset: 0x48
        cGUIObjColorAdjust* mpObjColorGaugeEffect;  // offset: 0x50
        cGUIObjMessage* mpObjMsgItemName;  // offset: 0x58
        cGUIObjMessage* mpObjMsgNotice;  // offset: 0x60
        cGUIObjMessage* mpObjMsgGradeMaxNotice;  // offset: 0x68
        cGUIObjMessage* mpObjMsgPlus00;  // offset: 0x70
        cGUIObjMessage* mpObjMsgPlusUnit00;  // offset: 0x78
        cGUIObjMessage* mpObjMsgPlus01;  // offset: 0x80
        cGUIObjMessage* mpObjMsgPlusUnit01;  // offset: 0x88
        cGUIObjMessage* mpObjMsgName;  // offset: 0x90
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x98
        cGUIObjMessage* mpObjMsgExp;  // offset: 0xa0
        cGUIObjMessage* mpObjMsgExpVal;  // offset: 0xa8
        cGUIObjMessage* mpObjMsgExpUnit;  // offset: 0xb0
        cGUIObjMessage* mpObjMsgPtVal;  // offset: 0xb8
        cGUIObjMessage* mpObjMsgPtUnit;  // offset: 0xc0
        cGUIObjTexture* mpObjTexGauge;  // offset: 0xc8
        cGUIObjTexture* mpObjTexGaugeUp;  // offset: 0xd0
        cGUIObjTexture* mpObjTexCrestIcon;  // offset: 0xd8
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0xe0
        uGUIBase::cReferenceUIIconCraftLv mCraftLvIcon;  // offset: 0x260
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0x2b8
        u32 mProgressIndex;  // offset: 0x5d8
        u32 mNowEquipPoint;  // offset: 0x5dc
        u32 mMaxPoint;  // offset: 0x5e0
        u32 mUpGradeItemId;  // offset: 0x5e4
        u32 mUpGradeItemGrade;  // offset: 0x5e8
        u32 mUpGradeBeforeItemId;  // offset: 0x5ec
        u32 mRno;  // offset: 0x5f0
        uGUIBase::cCalcMovePos mCounter;  // offset: 0x5f8
        MtColor mExpDefColor;  // offset: 0x618
        CommonU32Vec mUpGradeItemVec;  // offset: 0x620
        cItemParam mTempEquipParam;  // offset: 0x640
    };
public:
    struct stPawnIcon
    {
    public:
        stPawnIcon();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgNo;  // offset: 0x8
    };
public:
    struct stSkillParam
    {
    public:
        stSkillParam();
    public:
        cGUIObjMessage* mpObjMsg;  // offset: 0x0
        cGUIObjMessage* mpObjMsgEffect;  // offset: 0x8
        cGUIObjMessage* mpObjMsgVal[4];  // offset: 0x10
    };
public:
    struct stTotalOrder
    {
    public:
        stTotalOrder();
    public:
        cGUIInstAnimation* mpInstAnimAddItemIcon;  // offset: 0x0
        cGUIObjMessage* mpObjMsgMainItem;  // offset: 0x8
        cGUIObjMessage* mpObjMsgAddItem;  // offset: 0x10
        cGUIObjMessage* mpObjMsgSub00;  // offset: 0x18
        cGUIObjMessage* mpObjMsgSub01;  // offset: 0x20
        cGUIObjMessage* mpObjMsgSub02;  // offset: 0x28
        cGUIObjMessage* mpObjMsgMember;  // offset: 0x30
        cGUIObjMessage* mpObjMsgTime;  // offset: 0x38
        cGUIObjChildAnimationRoot* mpObjRootProgress;  // offset: 0x40
        uGUIBase::cReferenceUIIconItem mMainIcon;  // offset: 0x50
        uGUIBase::cReferenceUIIconItem mAddIcon;  // offset: 0x1d0
    };
public:
    struct stPawnParam
    {
    public:
        stPawnParam();
    public:
        cGUIObjMessage* mpObjMsg;  // offset: 0x0
        cGUIObjMessage* mpObjMsgVal;  // offset: 0x8
    };
public:
    struct stExam
    {
    public:
        stExam();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjNull* mpObjNullClassUp;  // offset: 0x10
        cGUIObjNull* mpObjNullStamp;  // offset: 0x18
        cGUIObjMessage* mpObjMsgName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgRank;  // offset: 0x28
        cGUIObjMessage* mpObjMsgRecipeTitle;  // offset: 0x30
        cGUIObjMessage* mpObjMsgRecipeName;  // offset: 0x38
        cGUIObjMessage* mpObjMsgResultTitle;  // offset: 0x40
        cGUIObjMessage* mpObjMsgResult00;  // offset: 0x48
        cGUIObjMessage* mpObjMsgResult01;  // offset: 0x50
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x60
        uGUIBase::cReferenceUIButton2 mButton;  // offset: 0x1e0
    };
public:
    struct stPointItem
    {
    public:
        stPointItem();
    public:
        cGUIObjMessage* mpObjMsgName;  // offset: 0x0
        cGUIObjMessage* mpObjMsgVal;  // offset: 0x8
        cGUIObjMessage* mpObjMsgPlus;  // offset: 0x10
        uGUIBase::cReferenceUINumBox mNumBox;  // offset: 0x18
    };
public:
    struct stFilter
    {
    public:
        stFilter();
        void reset();
    public:
        u32 mJobBit;  // offset: 0x0
        bool mUseItemRank;  // offset: 0x4
        u32 mItemRankMin;  // offset: 0x8
        u32 mItemRankMax;  // offset: 0xc
        bool mUseEquipLevel;  // offset: 0x10
        u32 mEquipLevelMin;  // offset: 0x14
        u32 mEquipLevelMax;  // offset: 0x18
        u32 mSex;  // offset: 0x1c
        bool mIsModify;  // offset: 0x20
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 mParam_pawnlist;  // offset: 0x0
        s32 mParam_itemlistcate;  // offset: 0x4
        s32 mParam_itemlistname;  // offset: 0x8
        s32 mParam_memberlist;  // offset: 0xc
        s32 mParam_cr_itemlistcate_x;  // offset: 0x10
        s32 mParam_cr_itemlistname_x;  // offset: 0x14
        s32 mParam_cr_memberlist_x;  // offset: 0x18
        s32 mParam_materiallist;  // offset: 0x1c
        s32 mParam_receiptlist;  // offset: 0x20
        s32 mParam_cr_materiallist_x;  // offset: 0x24
        s32 mParam_cr_receiptlist_x;  // offset: 0x28
        s32 mParam_rarity;  // offset: 0x2c
        s32 mParam_icon_item00;  // offset: 0x30
        s32 mParam_icon_item01;  // offset: 0x34
        s32 mParam_dialogbtn00_x;  // offset: 0x38
        s32 mParam_dialogbtn01_x;  // offset: 0x3c
        s32 mParam_cr_itemlistcate_y;  // offset: 0x40
        s32 mParam_btnsize_s;  // offset: 0x44
        s32 mParam_btnsize_l;  // offset: 0x48
        s32 mParam_itemlistheader;  // offset: 0x4c
        s32 mParam_headerspace;  // offset: 0x50
        s32 mParam_materialicon_x;  // offset: 0x54
        s32 mParam_cr_memberlist_y;  // offset: 0x58
        s32 mParam_cr_materiallist_y;  // offset: 0x5c
    };
public:
    struct stWatchTime
    {
    public:
        stWatchTime();
    public:
        u32 mPawnId;  // offset: 0x0
        u32 mSupportId[3];  // offset: 0x4
        f32 mTime;  // offset: 0x10
        static const u32 pawn_num = 10;
        static const u32 support_num = 3;
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
        virtual ~cListInfo() {}
    public:
        u32 mCategory;  // offset: 0x28
        u32 mIndex;  // offset: 0x2c
        u32 mExamPawnId;  // offset: 0x30
        f32 mListPos;  // offset: 0x34
        u8 mRank;  // offset: 0x38
        bool mIsMake;  // offset: 0x39
        bool mIsHeader;  // offset: 0x3a
        static MyDTI DTI;
    };
public:
    class cCreateRecipeSort : public cUIObject
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
        cCreateRecipeSort(u32 cate, u32 idx, u32 pawnId, u32 pawnIndex);
    public:
        u32 mCategory;  // offset: 0x8
        u32 mIndex;  // offset: 0xc
        u32 mItemId;  // offset: 0x10
        u32 mSortNo;  // offset: 0x14
        u32 mRank;  // offset: 0x18
        u32 mPawnId;  // offset: 0x1c
        u32 mPawnIndex;  // offset: 0x20
        u32 mGold;  // offset: 0x24
        static MyDTI DTI;
    };
public:
    class cAddListInfo : public uGUIBase::cScrollListInfoBase
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
        cAddListInfo();
        virtual ~cAddListInfo();
    public:
        MtString mUID;  // offset: 0x28
        rItemList::rItemParam* mpItemParam;  // offset: 0x30
        u32 mBagType;  // offset: 0x38
        static MyDTI DTI;
    };
public:
    struct stPawnList
    {
    public:
        stPawnList();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        uGUICraft::stPawnListItem mList[10];  // offset: 0x10
        f32 mChargeIconPos;  // offset: 0x13c0
        static const u32 list_max = 10;
    };
public:
    struct stOrder
    {
    public:
        stOrder();
    public:
        cGUIInstAnimation* mpInstAnimGradeIcon[4];  // offset: 0x0
        cGUIInstAnimation* mpInstAnimColor00;  // offset: 0x20
        cGUIInstAnimation* mpInstAnimColor01;  // offset: 0x28
        cGUIInstAnimation* mpInstAnimLine;  // offset: 0x30
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x38
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x40
        cGUIObjMessage* mpObjMsgHeader00;  // offset: 0x48
        cGUIObjMessage* mpObjMsgHeader01;  // offset: 0x50
        cGUIObjMessage* mpObjMsgHeader02;  // offset: 0x58
        cGUIObjMessage* mpObjMsgPt;  // offset: 0x60
        cGUIObjMessage* mpObjMsgPtVal;  // offset: 0x68
        cGUIObjTexture* mpObjTexGauge;  // offset: 0x70
        cGUIObjTexture* mpObjTexGaugeUp;  // offset: 0x78
        cGUIObjTextureSet* mpObjTexColor00;  // offset: 0x80
        cGUIObjTextureSet* mpObjTexColor01;  // offset: 0x88
        uGUICraft::stOrderListItem mList[6];  // offset: 0x90
        uGUICraft::stOrderCreateNum mCreateNum;  // offset: 0x570
        uGUICraft::stAnalyzeButton mAnalyze;  // offset: 0x5a8
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0x5c0
        MtColor mCraftNumDefColor;  // offset: 0x8e0
        u32 mListNum;  // offset: 0x8e4
        u32 mListIndex[9];  // offset: 0x8e8
        u32 mCreateNumIndex;  // offset: 0x90c
        u32 mAnalyzeIndex;  // offset: 0x910
        u32 mButtonIndex;  // offset: 0x914
        u32 mSelect;  // offset: 0x918
        u32 mDecideMenuNo;  // offset: 0x91c
        s32 mSelectSlotNo;  // offset: 0x920
        bool mIsAnalyzed;  // offset: 0x924
        bool mIsEnoughCraftCount;  // offset: 0x925
        static const u32 list_num = 6;
        static const u32 index_num = 9;
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
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimGradeIcon[4];  // offset: 0x60
        cGUIObjMessage* mpObjMsgName;  // offset: 0x80
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x88
        cGUIObjTexture* mpObjTexIconExp;  // offset: 0x90
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0xa0
        uGUIBase::cReferenceUIIconStorage mStorage;  // offset: 0x220
        uGUICraft::stListHeader mHeader;  // offset: 0x270
        static MyDTI DTI;
    };
public:
    struct stPawnSelect
    {
    public:
        stPawnSelect();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUICraft::stPawnSelectListItem mList[10];  // offset: 0x8
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x1460
        uGUIBase::cReferenceUITab mTab;  // offset: 0x1510
        f32 mBasePos;  // offset: 0x15c0
        f32 mListOffset;  // offset: 0x15c4
        f32 mCraftIconPos;  // offset: 0x15c8
        f32 mChargeIconPos;  // offset: 0x15cc
        static const u32 list_max = 10;
    };
public:
    struct stAddItem
    {
    public:
        stAddItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x8
        cGUIObjPolygon* mpObjPolyMaskBottom;  // offset: 0x10
        uGUICraft::cAddListItem mList[15];  // offset: 0x20
        uGUIBase::cScrollList mListCtrl;  // offset: 0x21e0
        static const u32 list_max = 15;
    };
public:
    struct stTotal
    {
    public:
        stTotal();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimLoading;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgAnalyzeResult;  // offset: 0x18
        cGUIObjMessage* mpObjMsgLegendSkill[3];  // offset: 0x20
        uGUICraft::stPawnIcon mPawnIcon[4];  // offset: 0x38
        uGUICraft::stSkillParam mParam[5];  // offset: 0x78
        uGUICraft::stTotalOrder mOrder;  // offset: 0x170
        uGUIBase::cReferenceUIChargesInfo mCharge;  // offset: 0x4c0
        MtColor mSkillEffectColorOrigin;  // offset: 0x618
        MtColor mLegendSkillColorOrigin;  // offset: 0x61c
        static const u32 legend_skill_num = 3;
    };
public:
    struct stStatus
    {
    public:
        stStatus();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindwoFrame;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgName;  // offset: 0x18
        cGUIObjMessage* mpObjMsgLevelVal;  // offset: 0x20
        cGUIObjMessage* mpObjMsgExp;  // offset: 0x28
        cGUIObjTexture* mpObjTexExpGauge;  // offset: 0x30
        uGUIBase::cReferenceUIIconCraftLv mCraftLvIcon;  // offset: 0x38
        uGUICraft::stPawnParam mParam[5];  // offset: 0x90
        cGUIObjMessage* mpObjMsgInfo;  // offset: 0xe0
    };
public:
    struct stPoint
    {
    public:
        stPoint();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x8
        cGUIInstAnimation* mpInstAnim;  // offset: 0x10
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x18
        cGUIObjMessage* mpObjMsgName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgLvVal;  // offset: 0x28
        cGUIObjMessage* mpObjMsgPoint;  // offset: 0x30
        cGUIObjMessage* mpObjMsgPointVal;  // offset: 0x38
        cGUIObjMessage* mpObjMsgPointUnit;  // offset: 0x40
        uGUICraft::stPointItem mItem[5];  // offset: 0x48
        uGUIBase::cReferenceUIIconCraftLv mCraftLvIcon;  // offset: 0x638
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0x690
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x9b0
        s32 mHavePoint;  // offset: 0xa48
        static const u32 skill_num = 5;
    };
public:
    struct stMakeItem
    {
    public:
        stMakeItem();
    public:
        cGUIObjMessage* mpObjMsgNotice;  // offset: 0x0
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x8
        uGUICraft::stCategoryListItem mCategory[15];  // offset: 0x10
        uGUICraft::cListItem mList[15];  // offset: 0x270
        uGUIBase::cReferenceUITab mMakeTab;  // offset: 0x28e0
        uGUIBase::cReferenceUITab mUpGradeTab;  // offset: 0x2990
        uGUIBase::cReferenceUIVlCursor mCateCursor;  // offset: 0x2a40
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x2af0
        uGUIBase::cScrollList mListCtrl;  // offset: 0x2b90
        nDDOUtility::cBitSet<8> mGuideBit;  // offset: 0x2e40
        nDDOUtility::cBitSet<8> mGuideBitPrev;  // offset: 0x2e44
        static const u32 category_max = 15;
        static const u32 item_list_max = 15;
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
    uGUICraft();
    virtual ~uGUICraft();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setFlowId(u32 flow_id);
    u32 getFlowId();
    void setupWindowActive();
    void updateRequest();
    u32 getSelectedCategory();
    u32 getSelectedIndex();
    u32 getSelectRecipeId();
    u32 getSelectedPawnSlotNo();
    bool isEndSuccessAnimation();
    void setEnableOrder(bool isEnable);
    void setEnableReceiveBag(bool isEnable);
    void setEnableReceiveBox(bool isEnable);
    void getSkillPoint(s32(&skill_point)[5]);
    nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE getRequestRecipeCategory();
    nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE getRecipeCategoryTypeFromWepId(u32 wep_id);
    nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE getRecipeCategoryTypeFromEquipCategory(u32 category);
protected:
    virtual void adjustScale();  // vtable slot 84
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void updateUpGradeResult();
    void setFlowIdSub(u32 flow_id);
    void setupTopMenu();
    void setupMainPawnStatus(bool isProgress);
    void setupMakeItem();
    void setupMakeCategory();
    void initListCategory();
    void setupMakeItemRecipeList();
    bool checkFilter(rItemList::rItemParam* pParam);
    void setupRequestRecipeCategory();
    void addListInfo(s32& pos, u32 type, u32 cate, u32 index, u32 rank, bool isHead, u32 exam_pawn_id);
    void setupMakeItemListControl();
    void returnItemListFromOrder();
    void setupMakeAddItem();
    void setupMakeAddItemList();
    u32 calcCrestHaveNum(const cItemParam* pParam);
    bool isMakedFurniture(const cListInfo* pInfo);
    void setupResultExp(u32 add_exp, u32 bonus_exp);
    void setupResultExp();
    void setupSubMenu();
    void updateSubMenu();
    void setupCharaSelect();
    void updateCharaSelect();
    void setupCharaReq();
    void updateCharaReq();
    void setupFilter();
    void updateFilter();
    void setupGetChest();
    void updateGetChest();
    void setupAnalyze();
    void updateAnalyze();
    void setupCreateNumSelect();
    void updateCreateNumSelect();
    void setupUpGradeItem();
    void setupUpGradeCategory();
    void setupUpGradeItemRecipeList();
    bool isLoadingUpGradeRecipe();
    void setupUpGradeOrder();
    void setupUpGradeResultWait();
    void setupUpGradeResult();
    void setupUpGradeParam();
    void setupUpGradeResultItem(u32 item_id);
    void setupUpGradeResultGauge(u32 point);
    void popUpGradeItem();
    void setupCrestEquipRecipeList();
    void setupCrestOrder();
    bool isDisableCrestSlot(cItemParam* pParam, u32 slot_no);
    void setupCrestResultWait();
    void setupCrestResult();
    void setupColorOrder();
    void setupColorItem();
    void setupColorItemCategory();
    void setupColorItemRecipeList();
    u32 getColorNo(rItemList::rItemParam* pItemParam);
    MT_CTSTR getColorText(u32 color_no);
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setupAddListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideAddListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setFocusSequence(cGUIInstAnimation* pInst, u32 seq_def, u32 seq_focus, bool isFocus);
    void setupPawnSelect();
    void setupPawnSelectList(u32 type);
    void setupOrderCommon();
    void setupOrder();
    void setupOrderListCtrl(u32 list_num);
    void setupOrderPawnInfo(stOrderListItem& order, u32 pawn_id);
    void setupOrderConfirm();
    void setupTotal();
    bool isHaveGrade(rItemList::rItemParam* pParam);
    void setupStatus(u32 pawn_id);
    void setupProgress();
    void setupProgressPawnList();
    void setupProgressDetail();
    void setupMakeResultWait();
    void setupMakeResult();
    void setupLvUp();
    void setupExam();
    void setupExamSub(u32 pawn_id, bool isCleared);
    void setupExamClearIn();
    void setupExamClear();
    void setupPointPawnSelect();
    void setupPointPawnSelectList();
    void setupPawnPoint();
    void setupPointInput();
    void setupPawnPointConfirm();
    void adjustListCategoryCursor(bool isImmediate);
    void adjustListItemCursor(bool isImmediate);
    void adjustMakeOrderCursor();
    void adjustPawnListCursor(bool isImmediate);
    void adjustMakeAddItemCursor();
    void adjustMakeResultCursor();
    void adjustPawnPointCursor();
    void adjustMakeCategoryTab();
    void adjustUpGradeCategoryTab();
    void adjustPawnListTab();
    void clearPawnSelectList();
    void clearStatus();
    void clearProgressDetail();
    void initPawnPoint();
    void subPawnPoint();
    void addPawnPoint();
    void callEffect(u32 element_no);
    void hideEffect();
    void setMakeOrderPointerPos();
    void resetItemDetailPage();
    void setupItemDetail(bool bDraw, bool bCraft, cItemParam* pParam, rItemList::rItemParam* pItemParam);
    const cPawnListParam* getPawnParam(u32 pawn_id);
    const cPawnListParam* getSelectedPawnParam();
    const CCraftPawnList* getPawnCraftParam(u32 pawn_id);
    const CCraftProgress* getPawnCraftProgress(u32 pawn_id);
    u32 getSelectedPawnId();
    u32 getSelectedProgressPawnId();
    void watchCraftProgressTime();
    s32 getProgressTime(u32 pawn_id);
    void setupMakeTime(cGUIObjMessage* pObj, s32 sec);
    MT_CTSTR getWepCategoryName(u32 wep_cate_id);
    bool checkUseItemCategory(u32 item_id, u32 use_item_cate_index);
    MT_CTSTR getUseItemCategoryName(u32 use_cate_index);
    u32 getMaterialIndexFromItemId(u32 item_id);
    MT_CTSTR getMaterialCategoryName(u32 mat_cate_index);
    MT_CTSTR getSpecialCategoryName(u32 special_cate_index);
    cItemParam* getItemParam(u32 recipe_type, u32 category, u32 index);
    const CCraftProgress* getProgressFromPawnId(u32 pawn_id);
    bool isChargeProgress(u32 pawn_id);
    void eventDecide();
    void eventCancel();
    void eventClose();
    void eventCheck();
    void eventSubMenu();
    void eventPopSel00();
    void eventPopSel01();
    void eventGetChest();
    void eventAnalyze();
    void eventCreateNumSelect();
    void eventAdjustCursor();
    void eventAdjustTab();
    void eventLeft();
    void eventRight();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlCheck(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustTab(cControl::Message* msg);
    u32 evCtrlLeft(cControl::Message* msg);
    u32 evCtrlRight(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    u32 callbackPopSel00(MtObject* pDummy, MtObject* pUnit);
    u32 callbackPopSel01(MtObject* pDummy, MtObject* pUnit);
    bool checkListInfoHeader(s32 index);
    bool isInstAnimEnd(cGUIInstAnimation* pInst);
public:
    u32 getTopMenuPos();
    u32 getCategoryPos();
    u32 getListPos();
    u32 getMenuNo();
    u32 getButtonPos();
    u32 getTabPos();
    virtual s32 getSMenuCursorY();  // vtable slot 72
private:
    void callPointer();
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getMenuMsg(u32 index);
    MT_CTSTR getParamMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
private:
    MtVector2 mPointerPos;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    rGUI* mpGUIResLvUp;  // offset: 0x8d8
    rGUIMessage* mpGMDRes;  // offset: 0x8e0
    rGUIMessage* mpGMDMenuRes;  // offset: 0x8e8
    rGUIMessage* mpGMDParamRes;  // offset: 0x8f0
    rSoundRequest* mpSeRes;  // offset: 0x8f8
    rEffectProvider* mpEffectRes;  // offset: 0x900
    cGUIInstNull* mpInstNull;  // offset: 0x908
    u32 mMenuType;  // offset: 0x910
    u32 mRecipeType;  // offset: 0x914
    u32 mRecipeId;  // offset: 0x918
    u32 mRecipeCategory;  // offset: 0x91c
    u32 mRecipeIndex;  // offset: 0x920
    bool mIsFurniture;  // offset: 0x924
    nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE mRequestRecipeCategory;  // offset: 0x928
    u32 mTempTabPos;  // offset: 0x92c
    u32 mTempCategoryPos;  // offset: 0x930
    u32 mTempListPos;  // offset: 0x934
    f32 mTempScrollPos;  // offset: 0x938
    u32 mFlowNow;  // offset: 0x93c
    u32 mFlowSub;  // offset: 0x940
    u32 mReturnFlowId;  // offset: 0x944
    u32 mPawnId;  // offset: 0x948
    u32 mCompPawnId;  // offset: 0x94c
    cContextInstHm mPawnContext;  // offset: 0x950
    stPawnList mPawnList;  // offset: 0x4ae0
    stMain mMain;  // offset: 0x5ea8
    stOrder mOrder;  // offset: 0x5f48
    stMakeItem mMakeItem;  // offset: 0x6870
    stPawnSelect mPawnSel;  // offset: 0x96c0
    stAddItem mAddItem;  // offset: 0xac90
    stResult mResult;  // offset: 0xd120
    stTotal mTotal;  // offset: 0xd7e0
    stStatus mStatus;  // offset: 0xde00
    stExam mExam;  // offset: 0xdef0
    stPoint mPoint;  // offset: 0xe260
    stFilter mFilter;  // offset: 0xecb0
    stVariable mVar;  // offset: 0xecd4
    cControl* mpDecideCtrl;  // offset: 0xed38
    cControl* mpCancelCtrl;  // offset: 0xed40
    cControl* mpCheckCtrl;  // offset: 0xed48
    cControl* mpStartCtrl;  // offset: 0xed50
    uGUIBase::cVerticalList* mpCategoryCtrl;  // offset: 0xed58
    uGUIBase::cVerticalList* mpListCtrl;  // offset: 0xed60
    uGUIBase::cHorizontalList* mpButtonCtrl;  // offset: 0xed68
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0xed70
    cControl* mpLRCtrl;  // offset: 0xed78
    uGUIPopTopSel* mpTopSel;  // offset: 0xed80
    uGUIPopCraftDetail* mpCraftDetail;  // offset: 0xed88
    uGUIPopDetail01* mpDetail;  // offset: 0xed90
    uGUIQueueAnnounceLvUp* mpLvUp;  // offset: 0xed98
    uGUIAnnounce* mpAnnounce;  // offset: 0xeda0
    uGUISystemMsg* mpSystemMsg;  // offset: 0xeda8
    uGUIPopNumber01* mpNumSelect;  // offset: 0xedb0
    uGUIPopCmd01* mpGUIPopCmd;  // offset: 0xedb8
    uGUIPopFilter* mpPopFilter;  // offset: 0xedc0
    uScreenSpace* mpScreenSpace;  // offset: 0xedc8
    MtStringEx<128> mTempStr;  // offset: 0xedd0
    stWatchTime mWatchTime[10];  // offset: 0xee54
    cItemParam* mpUpGradeEquip;  // offset: 0xef20
    cItemParam mTempItemParam;  // offset: 0xef28
    cEquipData mTempEquipData;  // offset: 0xefa0
    f32 mTempCrestColor;  // offset: 0x10208
    bool mIsOpen;  // offset: 0x1020c
    bool mIsUpdateReq;  // offset: 0x1020d
    bool mIsReturnItemList;  // offset: 0x1020e
    bool mIsEndAnim;  // offset: 0x1020f
    bool mIsEnableReceiveBag;  // offset: 0x10210
    bool mIsEnableReceiveBox;  // offset: 0x10211
    bool mIsUpdateProgressTime;  // offset: 0x10212
    bool mIsSkipExecute;  // offset: 0x10213
public:
    static MyDTI DTI;
    static const u32 grade_icon_num = 4;
};

inline void* uGUICraft::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUICraft::stOrderCreateNum::stOrderCreateNum() {
}

inline uGUICraft::stCategoryListItem::stCategoryListItem() {
}

inline void* uGUICraft::cListItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICraft::cAddListItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUICraft::stSkillParam::stSkillParam() {
}

inline void* uGUICraft::cListInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICraft::cCreateRecipeSort::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICraft::cAddListInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
