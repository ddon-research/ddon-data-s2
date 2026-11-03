#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/CharacterParam.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "cGUIExtNetMgr.h"
#include "cUIObject.h"
#include "uGUIBase.h"

// Forward declarations
class CDataJobExpMode;
class CDataLearnedAcquirementParam;
class CDataPresetAbilityParam;
class CDataSkillLevelParam;
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector2;
class MtVector4;
class cContextInstHm;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjChildAnimationRoot;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObjTextureSet;
class cGUIObject;
namespace nJobParam { class cJobInfo; }
namespace rAcquirement { class cAbilityAddData; }
namespace rAcquirement { class cAbilityLevelData; }
namespace rAcquirement { class cSkillLevelData; }
namespace rAcquirement { class rAbilityAddData; }
class rGUI;
class rGUIMessage;
class rSoundRequest;
class uGUIPopCmd01;
class uGUIPopSkillInfo;
class uGUIPopTopSel;
class uGUISkillLvUp;
class uGUISystemMsg;
class uUIMockUp;

// Declarations
class uGUISkill;

// Type aliases from DWARF
using CPresetAbilityParam = CDataPresetAbilityParam;
using JobExpModeVec = MtTypedArray<CDataJobExpMode>;
using LearnedAcquirementParamVec = MtTypedArray<CDataLearnedAcquirementParam>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class uGUISkill : public uGUIBase
{
public:
    enum
    {
        TYPE_JOB = 0,
        TYPE_NORMAL = 1,
        TYPE_CUSTOM = 2,
        TYPE_ABILITY = 3,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_LOAD_WAIT = 1,
        FLOW_SERVER_WAIT = 2,
        FLOW_ERROR_DIALOG = 3,
        FLOW_TOP = 4,
        FLOW_JOB = 5,
        FLOW_JOB_CONFIRM = 6,
        FLOW_JOB_QUEST_WAIT = 7,
        FLOW_JOB_CHANGE_NOTICE_WAIT = 8,
        FLOW_JOB_ABILITY_NOTICE = 9,
        FLOW_CUSTOM_SELECT = 10,
        FLOW_CUSTOM_SET = 11,
        FLOW_CUSTOM_CMD = 12,
        FLOW_CUSTOM_JOB = 13,
        FLOW_CUSTOM_LVUP = 14,
        FLOW_NORMAL_SELECT = 15,
        FLOW_NORMAL_JOB = 16,
        FLOW_NORMAL_LVUP = 17,
        FLOW_ABILITY_SELECT = 18,
        FLOW_ABILITY_SET = 19,
        FLOW_ABILITY_CMD = 20,
        FLOW_ABILITY_SET_CMD = 21,
        FLOW_ABILITY_JOB = 22,
        FLOW_ABILITY_SEARCH = 23,
        FLOW_ABILITY_SEARCH_SUB = 24,
        FLOW_ABILITY_LVUP = 25,
        FLOW_PRESET_SELECT = 26,
        FLOW_PRESET_CMD = 27,
        FLOW_PRESET_RENAME = 28,
        FLOW_PRESET_RENAME_EXEC = 29,
        FLOW_END = 30,
    };
    enum SKL_GUIDE_BIT
    {
        SKL_CATCH = 1,
        SKL_SUBME = 2,
        SKL_DECIDE = 4,
        SKL_SET = 8,
        SKL_CHANGE = 16,
        SKL_CHG_SET = 32,
        SKL_GROUP_SWITCH = 64,
        SKL_CHANGE_PP_MODE = 128,
        SKL_BIT_MAX = 8,
    };
    enum
    {
        TAB_CUSTOM = 0,
        TAB_NORMAL = 1,
        TAB_ABILITY = 2,
        TAB_NUM = 3,
    };
    enum
    {
        BUTTON_YES = 0,
        BUTTON_NO = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        SEARCH_JOB_ALL = 0,
        SEARCH_JOB = 1,
        SEARCH_COST_OVER = 2,
        SEARCH_COST_UNDER = 3,
        SEARCH_LEARN = 4,
        SEARCH_KIND_ALL = 5,
        SEARCH_KIND_00 = 6,
        SEARCH_KIND_01 = 7,
        SEARCH_KIND_02 = 8,
        SEARCH_KIND_03 = 9,
        SEARCH_KIND_04 = 10,
        SEARCH_KIND_05 = 11,
        SEARCH_BUTTON = 12,
        SEARCH_NUM = 13,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CLOSE = 68,
        INPUTEVENT_SUBMENU = 69,
        INPUTEVENT_CHANGE_GROUP = 70,
        INPUTEVENT_SHORTCUT = 71,
        INPUTEVENT_CHANGE_PPMODE = 72,
        INPUTEVENT_ADJUST_CURSOR = 73,
        INPUTEVENT_ADJUST_TAB = 74,
        INPUTEVENT_POP_SEL_00 = 75,
        INPUTEVENT_POP_SEL_01 = 76,
        INPUTEVENT_POP_SEL_02 = 77,
    };
    enum
    {
        REQ_FLAG_GUIEXT = 0,
        REQ_FLAG_JOB_CHANGE = 1,
        REQ_FLAG_LEARN_CUSTOM_SKILL = 2,
        REQ_FLAG_LEARN_NORMAL_SKILL = 3,
        REQ_FLAG_LEARN_ABILITY = 4,
        REQ_FLAG_SET_SKILL = 5,
        REQ_FLAG_SET_ABILITY = 6,
        REQ_FLAG_REGIST_PRESET = 7,
        REQ_FLAG_REGIST_PRESET_NAME = 8,
        REQ_FLAG_SET_PRESET = 9,
        REQ_FLAG_SET_OFF_SKILL = 10,
        REQ_FLAG_SET_OFF_ABILITY = 11,
        REQ_FLAG_CHANGE_PP_MODE = 12,
        REQ_FLAG_NUM = 13,
    };
public:
    class MyDTI;
    class cListInfo;
    struct stMouse;
    struct stTop;
    struct stHeader;
    struct stProf;
    struct stList;
    struct stListHeader;
    class cListItem;
    struct stListMsg;
    struct stLvUpButton;
    struct stSet;
    struct stSetItem;
    struct stGuide;
    struct stSubSet;
    struct stInfo;
    struct stPresetLeft;
    struct stPresetRight;
    struct stSearch;
    struct stCheck;
    struct stPullDown;
    struct stNameEdit;
    struct stVar;
    class cJobData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
        bool isDispButton() const;
        bool isFocusEnable() const;
        virtual void addMouseTouchList(cControl* pCtrl, s32 pos);  // vtable slot 6
    public:
        u32 mIconId;  // offset: 0x28
        u32 mId;  // offset: 0x2c
        u32 mLvUpPoint;  // offset: 0x30
        u16 mLvUpJobLv;  // offset: 0x34
        u16 mMsgExpIndex;  // offset: 0x36
        u16 mCost;  // offset: 0x38
        u16 mSortNo;  // offset: 0x3a
        u8 mIndexNext;  // offset: 0x3c
        u8 mIndex;  // offset: 0x3d
        u8 mSlot;  // offset: 0x3e
        u8 mLv;  // offset: 0x3f
        u8 mJobId;  // offset: 0x40
        u8 mCategory;  // offset: 0x41
        u8 mPosX;  // offset: 0x42
        u8 mPosY;  // offset: 0x43
        u8 mListIndex;  // offset: 0x44
        bool mIsEnableJp;  // offset: 0x45
        bool mIsEnableLv;  // offset: 0x46
        bool mIsGetSpecial;  // offset: 0x47
        bool mIsNext;  // offset: 0x48
        bool mIsUseEnable;  // offset: 0x49
        bool mIsMaxLv;  // offset: 0x4a
        bool mIsPPRelease;  // offset: 0x4b
        bool mIsPPMode;  // offset: 0x4c
        static MyDTI DTI;
    };
public:
    struct stMouse
    {
    public:
        stMouse();
    public:
        cGUIInstNull* mpInstNullIcon;  // offset: 0x0
        uGUIBase::cReferenceUIIconSkill mIcon;  // offset: 0x8
        bool mIsPick;  // offset: 0xc8
        bool mIsDecide;  // offset: 0xc9
    };
public:
    struct stHeader
    {
    public:
        stHeader();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg00;  // offset: 0x8
        cGUIObjMessage* mpObjMsg01;  // offset: 0x10
        cGUIObjMessage* mpObjMsg02;  // offset: 0x18
        cGUIObjMessage* mpObjMsg03;  // offset: 0x20
    };
public:
    struct stProf
    {
    public:
        stProf();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgName;  // offset: 0x8
        cGUIObjTexture* mpObjTexEmblem;  // offset: 0x10
    };
public:
    struct stListHeader
    {
    public:
        stListHeader();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
    };
public:
    struct stListMsg
    {
    public:
        stListMsg();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgName;  // offset: 0x8
        cGUIObjMessage* mpObjMsgNext;  // offset: 0x10
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x18
        cGUIObjMessage* mpObjMsgLvVal;  // offset: 0x20
        cGUIObjMessage* mpObjMsgNeedLv;  // offset: 0x28
        cGUIObjMessage* mpObjMsgJp;  // offset: 0x30
        cGUIObjMessage* mpObjMsgJpVal;  // offset: 0x38
        cGUIObjMessage* mpObjMsgPP;  // offset: 0x40
        cGUIObjMessage* mpObjMsgPPVal;  // offset: 0x48
        cGUIObjMessage* mpObjMsgPointMode;  // offset: 0x50
        cGUIObjMessage* mpObjMsgCost;  // offset: 0x58
        cGUIObjMessage* mpObjMsgCostVal;  // offset: 0x60
        cGUIObjMessage* mpObjMsgPreset;  // offset: 0x68
        cGUIObjChildAnimationRoot* mpObjCARBase;  // offset: 0x70
        cGUIObjNull* mpObjNullPointer;  // offset: 0x78
        cGUIObjTexture* mpObjTexCostIcon;  // offset: 0x80
        cGUIObjTexture* mpObjTexArrow;  // offset: 0x88
        cGUIObjPolygon* mpObjPolyMouseCollision;  // offset: 0x90
    };
public:
    struct stLvUpButton
    {
    public:
        stLvUpButton();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjColorAdjust* mpColorAdjust;  // offset: 0x8
        cGUIObjTextureSet* mpObjTexFocus;  // offset: 0x10
        cGUIObjPolygon* mpObjPolyMouseCollision;  // offset: 0x18
        cGUIObject* mpObjPointerPos;  // offset: 0x20
    };
public:
    struct stGuide
    {
    public:
        stGuide();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgGuide;  // offset: 0x8
        cGUIObjMessage* mpObjMsgBtnL;  // offset: 0x10
        cGUIObjMessage* mpObjMsgBtnR;  // offset: 0x18
    };
public:
    struct stSubSet
    {
    public:
        stSubSet();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgPresetTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgCost;  // offset: 0x18
        cGUIObjMessage* mpObjMsgCostVal;  // offset: 0x20
        cGUIObjMessage* mpObjMsgCostMax;  // offset: 0x28
        cGUIObjTexture* mpObjTexGauge;  // offset: 0x30
        cGUIObjTexture* mpObjTexGaugeUp;  // offset: 0x38
    };
public:
    struct stInfo
    {
    public:
        stInfo();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgCaptionTitle;  // offset: 0x18
        cGUIObjMessage* mpObjMsgCaption;  // offset: 0x20
        cGUIObjMessage* mpObjMsgArmsTitle;  // offset: 0x28
        cGUIObjMessage* mpObjMsgArms00;  // offset: 0x30
        cGUIObjMessage* mpObjMsgArms01;  // offset: 0x38
        cGUIObjTexture* mpObjTexJobImg;  // offset: 0x40
        static const u32 step_icon_num = 11;
    };
public:
    struct stPresetLeft
    {
    public:
        stPresetLeft();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullScroll;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x10
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x18
        uGUISkill::stListMsg mList[10];  // offset: 0x20
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x610
        uGUIBase::cReferenceUIScrollBar mScrollBar;  // offset: 0x6c0
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x768
        u32 mPresetNum;  // offset: 0x7c0
        static const u32 list_num = 10;
    };
public:
    struct stCheck
    {
    public:
        stCheck();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
        uGUIBase::cReferenceUICheckbox mCheckBox;  // offset: 0x10
    };
public:
    struct stPullDown
    {
    public:
        stPullDown();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIObjMessage* mpObjMsgJp;  // offset: 0x8
        cGUIObjMessage* mpObjMsgJpVal;  // offset: 0x10
        uGUIBase::cReferenceUIIconJob mJobIcon;  // offset: 0x18
        uGUIBase::cReferenceUIPullDownSkill mPullDown;  // offset: 0x70
    };
public:
    struct stNameEdit
    {
    public:
        stNameEdit();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        uGUIBase::cReferenceUITextBox mTextBox;  // offset: 0x18
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0x180
    };
public:
    struct stVar
    {
    public:
        stVar();
    public:
        s32 param_spacing_job;  // offset: 0x0
        s32 param_spacing_preset;  // offset: 0x4
        s32 param_icon_skill00;  // offset: 0x8
        s32 param_icon_skill01;  // offset: 0xc
        s32 param_normalskill_line;  // offset: 0x10
        s32 param_spacing_ns_line;  // offset: 0x14
        s32 param_pull_move;  // offset: 0x18
        s32 param_cr_preset_ab_x;  // offset: 0x1c
        s32 param_cr_job_x;  // offset: 0x20
        s32 param_ofst_x_preset_ab;  // offset: 0x24
        s32 param_ofst_y_search_ab;  // offset: 0x28
        s32 param_btn_x;  // offset: 0x2c
        s32 param_spacing_list00_x;  // offset: 0x30
        s32 param_spacing_list00_y;  // offset: 0x34
        s32 param_ns_ctgry_y;  // offset: 0x38
        s32 param_scroll_size_y;  // offset: 0x3c
        s32 param_ofst_y_preset_ab;  // offset: 0x40
    };
public:
    class cJobData : public cUIObject
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
        cJobData();
    public:
        u32 mId;  // offset: 0x8
        u64 mJp;  // offset: 0x10
        static MyDTI DTI;
        static const u32 secret_id = 0;
    };
public:
    struct stTop
    {
    public:
        stTop();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullGuide;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimLoad;  // offset: 0x18
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x20
        cGUIObjMessage* mpObjMsgSubTitle;  // offset: 0x28
        cGUIObjMessage* mpObjMsgJp;  // offset: 0x30
        cGUIObjMessage* mpObjMsgJpVal;  // offset: 0x38
        cGUIObjMessage* mpObjMsgTotalJobLv;  // offset: 0x40
        cGUIObjTexture* mpObjTexMockup;  // offset: 0x48
        uGUISkill::stHeader mHeader;  // offset: 0x50
        uGUISkill::stProf mProf;  // offset: 0x78
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x90
        uGUIBase::cReferenceUITab mTab;  // offset: 0x130
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x1e0
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
        void clearNextLv();
        void clearMsg(cGUIObjMessage* pObj);
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimGauge;  // offset: 0x60
        cGUIObjMessage* mpObjMsgXp;  // offset: 0x68
        cGUIObjMessage* mpObjMsgXpVal;  // offset: 0x70
        cGUIObjTexture* mpObjTexGauge;  // offset: 0x78
        uGUISkill::stListMsg mMsg;  // offset: 0x80
        uGUISkill::stLvUpButton mButton;  // offset: 0x118
        uGUIBase::cReferenceUIIconSkill mIcon;  // offset: 0x140
        uGUIBase::cReferenceUIIconJob mJobIcon;  // offset: 0x200
        static MyDTI DTI;
    };
public:
    struct stSetItem
    {
    public:
        stSetItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUISkill::stGuide mGuide;  // offset: 0x8
        uGUISkill::stListMsg mMsg;  // offset: 0x28
        uGUIBase::cReferenceUIIconSkill mIcon;  // offset: 0xc0
        uGUIBase::cReferenceUIIconJob mJobIcon;  // offset: 0x180
        const uGUISkill::cListInfo* mpInfo;  // offset: 0x1d8
        MtVector2 mPointerPos;  // offset: 0x1e0
    };
public:
    struct stPresetRight
    {
    public:
        stPresetRight();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullScroll;  // offset: 0x8
        uGUISkill::stSubSet mSub;  // offset: 0x10
        uGUISkill::stSetItem mList[10];  // offset: 0x50
        static const u32 list_num = 10;
    };
public:
    struct stSearch
    {
    public:
        stSearch();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgOver;  // offset: 0x18
        cGUIObjMessage* mpObjMsgUnder;  // offset: 0x20
        uGUISkill::stHeader mHeader;  // offset: 0x28
        uGUISkill::stCheck mJobAllCheck;  // offset: 0x50
        uGUISkill::stCheck mKindAllCheck;  // offset: 0xb0
        uGUISkill::stCheck mLearnCheck;  // offset: 0x110
        uGUISkill::stCheck mNotLearnCheck;  // offset: 0x170
        uGUISkill::stCheck mKindCheck[12];  // offset: 0x1d0
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x650
        uGUIBase::cReferenceUIIconButton mJobIcon[10];  // offset: 0x6e8
        uGUIBase::cReferenceUINumBox mCostOver;  // offset: 0xb98
        uGUIBase::cReferenceUINumBox mCostUnder;  // offset: 0xcb0
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0xdc8
        u32 mJobBit;  // offset: 0x10e8
        u32 mKindBit;  // offset: 0x10ec
        u32 mCostOverVal;  // offset: 0x10f0
        u32 mCostUnderVal;  // offset: 0x10f4
        u32 mAbilityCostMax;  // offset: 0x10f8
        bool mIsLearn;  // offset: 0x10fc
        bool mIsNotLearn;  // offset: 0x10fd
        bool mIsAllJob;  // offset: 0x10fe
        bool mIsAllKind;  // offset: 0x10ff
        bool mIsSearch;  // offset: 0x1100
        bool mIsAnnounce;  // offset: 0x1101
        static const u32 icon_num = 10;
        static const u32 kind_num = 12;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x0
        uGUISkill::stListHeader mHeader[3];  // offset: 0x8
        uGUISkill::cListItem mList[16];  // offset: 0x50
        uGUIBase::cScrollList mListCtrl;  // offset: 0x25d0
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x2880
        bool mIsNoUpdate;  // offset: 0x2930
        bool mIsKeepSelect;  // offset: 0x2931
        static const u32 header_num = 3;
        static const u32 list_num = 16;
    };
public:
    struct stSet
    {
    public:
        stSet();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullScroll;  // offset: 0x8
        cGUIInstNull* mpInstNullCustom;  // offset: 0x10
        cGUIObjMessage* mpObjMsgCustomGroup;  // offset: 0x18
        uGUISkill::stSetItem mCustom[4];  // offset: 0x20
        uGUISkill::stSetItem mAbility[10];  // offset: 0x7c0
        uGUISkill::stSubSet mSub;  // offset: 0x1ad0
        uGUIBase::cReferenceUIScrollBar mScrollBar;  // offset: 0x1b10
        static const u32 custom_num = 4;
        static const u32 ability_num = 10;
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
    uGUISkill();
    virtual ~uGUISkill();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setMenuType(u32 menu_type);
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void updateLoadWait();
    void updateQuestWait();
    void requestJobTex(u32 job_id, bool isImmediate);
    void updateJobTex();
    void setFlowId(u32 flow_id);
    void setFlowIdSub(u32 flow_id);
    void setupWindowActive();
    void setupGuide(stGuide& guide, cGUIInstance* pInst);
    void setupListMsg(stListMsg& msg, cGUIInstance* pInst);
    void setupProf(stProf& prof, cGUIInstance* pInst);
    void setupHeader(stHeader& header, cGUIInstance* pInst);
    void setupSubSet(stSubSet& sub, cGUIInstance* pInst);
    void setupLvUpButton(stLvUpButton& button, cGUIInstance* pInst);
    void setupTopMenu();
    void setupJob();
    void setupMainWindow();
    void setupCustomSkill();
    void setupNormalSkill();
    void setupAbility();
    void setupJobInfo();
    void setupJobConfirm();
    void setupPullDown();
    void createCustomSkillList();
    void setupCustomSetList();
    void setupCustomSetListPointerPos();
    void hideCustomInfo();
    void setupCustomInfo(const cListInfo* pInfo);
    void updateCustomInfo();
    void setSelectInfo(const cListInfo* pInfo);
    void setupCustomDialog();
    void setupCustomCmd();
    void setupCustomSet();
    void setupCustomJob();
    void createNormalSkillList();
    void setupNormalDialog();
    void createAbilityList();
    bool isSearchJob(u32 job_id);
    void createAbilitySetList();
    void setupAbilitySetList();
    void setupAbilitySet();
    void setupAbilityCmd();
    void setupAbilitySetCmd();
    void setupAbilitySearch();
    void setupAbilityDialog();
    void setupAbilityJob();
    void setupPreset();
    void setupPresetList();
    void setupPresetSetList();
    void setupPresetCmd();
    void setupPresetRename();
    void setupPresetRenameExec();
    void updatePresetRenameExec();
    void setupJobChangeNoticeWait();
    void updateJobChangeNoticeWait();
    void setupJobAbilityNotice();
    void updateJobAbilityNotice();
    cListInfo* createAbilityListInfo(u32 id);
    bool abilityListSort(const cListInfo* pA, const cListInfo* pB, u32 param);
    void setupDialog(MT_CTSTR msg_notice, MT_CTSTR analyze0, MT_CTSTR analyze1, MT_CTSTR msg_ok, MT_CTSTR msg_cancel, bool isDefOk);
    void updateDialog();
    void updateMockUp();
    void setupMockUp(u32 job_id);
    u32 convEquipSlotFromSv(u32 sv_slot);
    u32 convEquipTypeFlomSv(u32 sv_type);
    void adjustJobCursor(bool isImmediate);
    void adjustCursorInit();
    void adjustCustomCursor();
    void adjustNormalCursor();
    void adjustAbilityCursor();
    void adjustSkillTab();
    void adjustSearchCursor();
    void adjustPresetCursor();
    void adjustRenameCursor();
    void decideJob();
    void decideJobConfirm();
    void decideCustomSelect();
    void decideCustomSet();
    void decideCustomJob();
    void decideNormalSelect();
    void decideNormalJob();
    void decideCustomLvUp();
    void decideNormalLvUp();
    void decideAbilitySelect();
    void decideAbilitySet();
    void decideAbilityJob();
    void decideAbilityLvUp();
    void decideAbilitySearch();
    void decidePreset();
    void decidePresetRename();
    bool isReleasedCustomSkill(const MtTypedArray<CDataSkillLevelParam>& list, u32 lv);
    const rAcquirement::cSkillLevelData* getSkillLevelParam(const MtTypedArray<rAcquirement::cSkillLevelData>& list, u32 lv);
    u32 getSkillLevel(u32 job_id, u32 id);
    bool isReleaseAbilityLv(const cGUIExtNetMgr::BasicAbilityInfo& info, u32 lv);
    const rAcquirement::cAbilityAddData* getAbilityAddData(u32 id);
    const rAcquirement::cAbilityLevelData* getAbilityLevelParam(u32 id, u32 lv);
    u32 getSetAbilitySlotNo(u32 job_id, u32 id);
    u32 getAbilityLevel(u32 job_id, u32 id);
    const CPresetAbilityParam* getPresetParam(u32 id);
    u32 getLearnedLevel(const LearnedAcquirementParamVec& list, u32 job_id, u32 id);
    void initCursor(uGUIBase::cReferenceUIVlCursor& cursor, const MtVector4& init_pos, bool isMovePointer);
    void setInstGrayOut(cGUIInstNull* pInst, bool isGrayOut);
    void setCustomListGrayOut(bool isGrayOut);
    const cContextInstHm* getContext();
    u32 getChangeJobId();
    const nJobParam::cJobInfo* getJobInfo(u32 job_id);
    u32 getJobLevel(u32 job_id);
    u32 getJobPoint(u32 job_id);
    bool isPPRelease(u32 job_lv);
    bool isPPMode(u32 job_id);
    u32 getPP(u32 job_id);
    cListInfo* getListInfo(u32 index);
    cListInfo* getListInfo();
    cListInfo* getNormalListInfo();
    void createLvUp(u32 type, u32 job_id, u32 id, u32 icon_id, u32 lv);
    void initList(s32 list_pos);
    void setupScrollList(s32 list_pos);
    cGUIObjPolygon* getObjPolyMask(u32 obj_id);
    void clearList();
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void applyListOriginal(cListItem* pItem);
    void setupJobItem(cListItem* pItem, cListInfo* pInfo, u32 index);
    bool isReleasedJob(u32 job_id);
    void setupItemCommon(cListItem* pItem, cListInfo* pInfo, u32 index, bool isFocus, bool isLeft);
    void setupCustomItem(cListItem* pItem, cListInfo* pInfo, u32 index);
    bool isMaxLvCustomSkill(u32 job_id, u32 skill_id, u32 lv);
    void setupNormalItem(cListItem* pItem, cListInfo* pInfo, u32 index);
    void setupAbilityItem(cListItem* pItem, cListInfo* pInfo, u32 index);
    bool isMaxLvAbility(u32 ability_id, u32 lv);
    void adjustSearchCost(bool isOver);
public:
    void setInputEvent(u32 eventId);
    void requestSkillData();
    void requestAbilityData();
    void requestPawnData();
    void eventDecide();
    void eventCancel();
    void eventClose();
    void eventSubMenu();
    void eventChangeGroup();
    void eventShortCut();
    void eventChangePPMode();
    void eventAdjustCursor();
    void eventAdjustTab();
    void eventSel00();
    void eventSel01();
    void eventSel02();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlSubMenu(cControl::Message* msg);
    u32 evCtrlShortCut(cControl::Message* msg);
    u32 evCtrlPPMode(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustTab(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    u32 evCtrlMouseDrag(cControl::Message* msg);
    u32 evCtrlMouseDrop(cControl::Message* msg);
    u32 callbackPopSel00(MtObject* pDummy, MtObject* pUnit);
    u32 callbackPopSel01(MtObject* pDummy, MtObject* pUnit);
    u32 callbackPopSel02(MtObject* pDummy, MtObject* pUnit);
private:
    bool isRequest(u32 flag);
    void setRequest(u32 flag);
    void clearRequest(u32 flag);
    void requestServer(u32 next_flow_id);
    void requestNext();
    void updateServerWait();
    virtual void setServerErrorEnd(u32 ErrorCode);  // vtable slot 89
    void requestJobChange();
    bool requestLearnCustomSkill();
    void callbackLearnCustomSkill();
    bool requestLearnNormalSkill();
    void callbackLearnNormalSkill();
    bool requestLearnAbility();
    void callbackLearnAbility();
    bool requestSetSkill();
    void callbackSetSkill();
    bool requestSetAbility();
    void callbackSetAbility();
    bool requestRegistPreset();
    void callbackRegistPreset();
    bool requestRegistPresetName();
    void callbackRegistPresetName();
    bool requestSetPreset();
    void callbackSetPreset();
    bool requestSetOffSkill();
    void callbackSetOffSkill();
    bool requestSetOffAbility();
    void callbackSetOffAbility();
    bool requestChangePPMode();
    void callbackChangePPMode();
    void updateErrorDialog();
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getMenuCmnMsg(u32 index);
    MT_CTSTR getAbilityCateMsg(u32);
    MT_CTSTR getCmnMsg(u32 index);
    MT_CTSTR getParamMsg(u32);
    void callPointer(u32 prio);
private:
    MtVector2 mPointerPos;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    rGUIMessage* mpGMDRes;  // offset: 0x8d8
    rGUIMessage* mpGMDMenuCmn;  // offset: 0x8e0
    rGUIMessage* mpGMDAbilityCategory;  // offset: 0x8e8
    rGUIMessage* mpGMDJobInfo;  // offset: 0x8f0
    rGUIMessage* mpGMDParameter;  // offset: 0x8f8
    rSoundRequest* mpSeRes;  // offset: 0x900
    rAcquirement::rAbilityAddData* mpAbilityAddData;  // offset: 0x908
    cGUIInstNull* mpInstNull;  // offset: 0x910
    cGUIInstNull* mpInstNullDetail;  // offset: 0x918
    cGUIInstNull* mpInstNullInfo;  // offset: 0x920
    cGUIInstNull* mpInstNullDialog;  // offset: 0x928
    u32 mFlowId;  // offset: 0x930
    u32 mFlowIdNext;  // offset: 0x934
    u32 mMenuType;  // offset: 0x938
    u32 mRequestFlag;  // offset: 0x93c
    u32 mRequestFlagNow;  // offset: 0x940
    u32 mPawnId;  // offset: 0x944
    u32 mNowReqPawnId;  // offset: 0x948
    const cListInfo* mpDrawSkillInfo;  // offset: 0x950
    const cListInfo* mpSelectSkillInfo;  // offset: 0x958
    stMouse mMouse;  // offset: 0x960
    stTop mTop;  // offset: 0xa30
    stList mList;  // offset: 0xc70
    stSet mSet;  // offset: 0x35b0
    stInfo mInfo;  // offset: 0x5168
    stPresetLeft mPresetL;  // offset: 0x51b0
    stPresetRight mPresetR;  // offset: 0x5980
    stSearch mSearch;  // offset: 0x6ce0
    stPullDown mPullDown;  // offset: 0x7df0
    stNameEdit mNameEdit;  // offset: 0x84f0
    stVar mVar;  // offset: 0x8990
    cControl* mpDecideCtrl;  // offset: 0x89d8
    cControl* mpCancelCtrl;  // offset: 0x89e0
    cControl* mpSubMenuCtrl;  // offset: 0x89e8
    cControl* mpShortCutCtrl;  // offset: 0x89f0
    cControl* mpPPModeCtrl;  // offset: 0x89f8
    uGUIBase::cVerticalList* mpListUDCtrl;  // offset: 0x8a00
    uGUIBase::cHorizontalList* mpListLRCtrl;  // offset: 0x8a08
    uGUIBase::cMatrix* mpSetCtrl;  // offset: 0x8a10
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x8a18
    uGUIBase::cHorizontalList* mpDialogCtrl;  // offset: 0x8a20
    uGUIBase::cVerticalList* mpPresetCtrl;  // offset: 0x8a28
    uGUIBase::cVerticalList* mpPullDownCtrl;  // offset: 0x8a30
    uGUIBase::cVerticalList* mpNameEditCtrl;  // offset: 0x8a38
    uGUIBase::cVerticalList* mpSearchCtrl;  // offset: 0x8a40
    uGUIBase::cHorizontalList* mpSearchJobCtrl;  // offset: 0x8a48
    cControl* mpSearchCostCtrl;  // offset: 0x8a50
    uGUIBase::cHorizontalList* mpSearchLearnCtrl;  // offset: 0x8a58
    uGUIBase::cHorizontalList* mpSearchKindCtrl;  // offset: 0x8a60
    u16 mCostNow;  // offset: 0x8a68
    u16 mCostMax;  // offset: 0x8a6a
    u8 mPresetNo;  // offset: 0x8a6c
    u8 mJobId;  // offset: 0x8a6d
    u32 mJobLevelMax;  // offset: 0x8a70
    u8 mSkillGroup;  // offset: 0x8a74
    u8 mSlotNo;  // offset: 0x8a75
    u8 mSkillIndex;  // offset: 0x8a76
    u8 mSkillIndexNext;  // offset: 0x8a77
    u8 mSkillLv;  // offset: 0x8a78
    u16 mAbilityCost;  // offset: 0x8a7a
    u32 mSkillId;  // offset: 0x8a7c
    u32 mSkillIconId;  // offset: 0x8a80
    MtStringEx<64> mPresetName;  // offset: 0x8a84
    u32 mDialogHandle;  // offset: 0x8ac8
    MtStringEx<64> mErrorMessage;  // offset: 0x8acc
    uGUIPopTopSel* mpGUIPopTopSel;  // offset: 0x8b10
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x8b18
    uGUIPopCmd01* mpGUIPopCmd;  // offset: 0x8b20
    uGUIPopSkillInfo* mpGUIPopSkillInfo;  // offset: 0x8b28
    uGUISkillLvUp* mpGUISkillLvUp;  // offset: 0x8b30
    uUIMockUp* mpUIMockUp;  // offset: 0x8b38
    MtTypedArray<cListInfo> mSetList;  // offset: 0x8b40
    MtTypedArray<cJobData> mJobList;  // offset: 0x8b60
    u8 mBlankSlot;  // offset: 0x8b80
    MtStringEx<128> mTempStr;  // offset: 0x8b84
    u32 mTexJobId;  // offset: 0x8c08
    uGUIBase::cTexArcLoader mTexLoader;  // offset: 0x8c10
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[8];  // offset: 0x8c98
    u32 mPPModeBit;  // offset: 0x8dd8
    JobExpModeVec mPPModeList;  // offset: 0x8de0
    bool mIsSetDraw;  // offset: 0x8e00
public:
    static MyDTI DTI;
};

inline void* uGUISkill::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uGUISkill::setupCustomJob() {
    if (this->mPullDown.mPullDown.::uGUIBase::cReferenceUIPullDown::mIsForbid) {
        return;
    }
    if (this->mPullDown.mPullDown.::uGUIBase::cReferenceUIPullDown::mState != static_cast<uGUIBase::cReferenceUIPullDown::STATE>(0)) {
        return;
    }
    this->mPullDown.mPullDown.::uGUIBase::cReferenceUIPullDown::mState = static_cast<uGUIBase::cReferenceUIPullDown::STATE>(1);
}

inline void uGUISkill::setupAbilityJob() {
    if (this->mPullDown.mPullDown.::uGUIBase::cReferenceUIPullDown::mIsForbid) {
        return;
    }
    if (this->mPullDown.mPullDown.::uGUIBase::cReferenceUIPullDown::mState != static_cast<uGUIBase::cReferenceUIPullDown::STATE>(0)) {
        return;
    }
    this->mPullDown.mPullDown.::uGUIBase::cReferenceUIPullDown::mState = static_cast<uGUIBase::cReferenceUIPullDown::STATE>(1);
}

inline void* uGUISkill::cListInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUISkill::stHeader::stHeader() {
}

inline uGUISkill::stProf::stProf() {
}

inline void* uGUISkill::cListItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUISkill::stListMsg::stListMsg() {
}

inline uGUISkill::stLvUpButton::stLvUpButton() {
}

inline uGUISkill::stInfo::stInfo() {
}

inline void* uGUISkill::cJobData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUISkill::cJobData::cJobData() {
    this->mId = 0;
    this->mJp = 0;
}
