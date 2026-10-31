#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "nGUIItem.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtVector4;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
class cGUIObjTextureSet;
namespace nGUIItem { class cItemList; }
class rGUI;
class uGUIPopDetail01;
class uGUIPopRmcQuestInfo;

// Declarations
class uGUIMissionInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMissionInfo : public uGUIsMenuBase
{
public:
    enum MI_GUIDE_BIT
    {
        MI_MEMBER = 1,
        MI_DETAIL = 2,
        MI_BIT_MAX = 2,
    };
    enum PLAY_TYPE
    {
        PLAY_NONE = 0,
        PLAY_MULTI = 1,
        PLAY_SOLO = 2,
    };
    enum MENU_TYPE
    {
        BTN_MENU = 0,
        MENU_TYPE_NONE_ITEM_NUM = 1,
        ITEM_MENU = 1,
        MENU_TYPE_NUM = 2,
    };
    enum BTN_TYPE
    {
        DECIDE_BTN = 0,
        CANCEL_BTN = 1,
        BTN_TYPE_NUM = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR_V = 68,
        INPUTEVENT_ADJUST_CURSOR_BTN = 69,
        INPUTEVENT_ADJUST_CURSOR_ITEM = 70,
        INPUTEVENT_CLICK_BTN = 71,
        INPUTEVENT_CHKOUT = 72,
        INPUTEVENT_CHANGE_WINDOW = 73,
    };
public:
    class MyDTI;
    class cItem;
    struct guiInst;
    struct guiObj;
    struct missionInfo;
    struct variableInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cItem : public MtObject
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
        cItem();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        uGUIBase::cReferenceUIIconItem mRefItem;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    struct guiInst
    {
    public:
        cGUIInstNull* Null;  // offset: 0x0
        cGUIInstNull* Null_request;  // offset: 0x8
        cGUIInstAnimation* bg;  // offset: 0x10
        cGUIInstAnimation* msg_title;  // offset: 0x18
        cGUIInstAnimation* msg_terms;  // offset: 0x20
        cGUIInstAnimation* msg_caption;  // offset: 0x28
        cGUIInstNull* Null_itemlist00;  // offset: 0x30
        cGUIInstAnimation* msg_lv;  // offset: 0x38
        cGUIInstAnimation* msg_header02;  // offset: 0x40
        cGUIInstAnimation* mask;  // offset: 0x48
        cGUIInstNull* Null_scroll;  // offset: 0x50
        cGUIInstAnimation* item_icon0;  // offset: 0x58
        cGUIInstNull* Null_terms00;  // offset: 0x60
        cGUIInstNull* Null_terms01;  // offset: 0x68
        cGUIInstAnimation* window_frame;  // offset: 0x70
        cGUIInstAnimation* window;  // offset: 0x78
        cGUIInstNull* Null_all;  // offset: 0x80
        cGUIInstAnimation* msg_btn;  // offset: 0x88
        cGUIInstAnimation* msg_btn_emphasis;  // offset: 0x90
        cGUIInstAnimation* msg_btn_emphasis2;  // offset: 0x98
        cGUIInstNull* Null_caption;  // offset: 0xa0
        cGUIInstNull* Null_reward;  // offset: 0xa8
        cGUIInstNull* Null_lv;  // offset: 0xb0
        cGUIInstAnimation* fix_iconinfo;  // offset: 0xb8
        cGUIInstAnimation* msg_mission;  // offset: 0xc0
        cGUIInstAnimation* fix_iconbase;  // offset: 0xc8
        cGUIInstAnimation* fix_emblem;  // offset: 0xd0
    };
public:
    struct guiObj
    {
    public:
        cGUIObjMessage* msg_title_m_title;  // offset: 0x0
        cGUIObjMessage* msg_header_m_header;  // offset: 0x8
        cGUIObjMessage* msg_terms_m_header;  // offset: 0x10
        cGUIObjMessage* msg_terms_m_terms;  // offset: 0x18
        cGUIObjMessage* msg_terms_m_pt;  // offset: 0x20
        cGUIObjMessage* msg_caption_m_caption;  // offset: 0x28
        cGUIObjMessage* msg_lv_m_recmd;  // offset: 0x30
        cGUIObjMessage* msg_lv_m_lv;  // offset: 0x38
        cGUIObjMessage* msg_lv_m_num;  // offset: 0x40
        cGUIObjMessage* msg_mission_m_title;  // offset: 0x48
        cGUIObjTextureSet* msg_caption_frame_bottom;  // offset: 0x50
        cGUIObjTexture* msg_caption_bg;  // offset: 0x58
    };
public:
    struct missionInfo
    {
    public:
        missionInfo();
    public:
        u32 mQuestID;  // offset: 0x0
        u32 mScheduleID;  // offset: 0x4
        u32 mItemID[7];  // offset: 0x8
    };
public:
    struct variableInfo
    {
    public:
        variableInfo();
    public:
        s32 param_size_questlv;  // offset: 0x0
        s32 param_size_terms00;  // offset: 0x4
        s32 param_ofst_terms00;  // offset: 0x8
        s32 param_margin_caption;  // offset: 0xc
        s32 param_size_caption;  // offset: 0x10
        s32 param_ofst_caption;  // offset: 0x14
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
    uGUIMissionInfo();
    virtual ~uGUIMissionInfo();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    bool isDecide();
    bool isCancel();
    bool isMemberInfo();
    void clearDecideCancel();
    bool isSelectDecideButton();
    void initSystem(bool focus);
    void reStartSystem(bool focus);
    bool setIDQuestSchedule(const u32 questID, const u32 scheduleID);
    void updateInfo();
    bool isSetupComp();
    void setupDetailPos();
    void setupPopBonusPos();
    void leftCenterAlignment();
    uGUIPopRmcQuestInfo* getGUIPopRmcQuestInfoPtr();
    void setExecuteCtrl(bool flag);
    void setStandAlone(bool flag);
    void setInitWindowActive(bool flag);
    bool isSolo();
    void setInvitation(bool flag);
    u32 getMemberNum();
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    void init();
    void setItemDetail(u32 itemId);
    void updateDetail();
    void updateGuide();
    void settingItemInit(f32 offset);
    void updateItem();
    void updateCharges();
    void updateCycleInfo();
    void updateEndInfo();
    void addStrOrderCondition(MtString& str, MT_CTSTR addStr, bool enableCondition);
    void disableBtn();
    void enableBtn();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlCursorV(cControl::Message* msg);
    u32 evCtrlCursorBtn(cControl::Message* msg);
    u32 evCtrlCursorItem(cControl::Message* msg);
    u32 evCtrlItemClick(cControl::Message* msg);
    u32 evCtrlOver(cControl::Message* msg);
    u32 evCtrlBtnClick(cControl::Message* msg);
    u32 evCtrlChkout(cControl::Message* msg);
    void eventDecide();
    void eventCancel();
    void eventCursorV(bool noneFocus);
    void eventCursorBtn(bool noneFocus);
    void eventCursorItem();
    void eventChkout();
    void evChangeWindow();
    bool eventCheckWindow();
private:
    MtTypedArray<cItem> mItemArray;  // offset: 0x958
    rGUI* mpGUIRes;  // offset: 0x978
    cControl* mpButtonCtrl;  // offset: 0x980
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x988
    uGUIBase::cHorizontalList* mpBtnHCtrl;  // offset: 0x990
    uGUIBase::cHorizontalList* mpItemHCtrl;  // offset: 0x998
    uGUIBase::cReferenceUIButton2 mRefButtonDecide;  // offset: 0x9a0
    uGUIBase::cReferenceUIButton2 mRefButtonSolo;  // offset: 0xb30
    uGUIBase::cReferenceUIButton mRefButtonCancel;  // offset: 0xcc0
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0xe50
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[2];  // offset: 0xee8
    uGUIPopDetail01* mpDetail;  // offset: 0xf38
    uGUIPopRmcQuestInfo* mpPopBonus;  // offset: 0xf40
    guiInst mDataInst;  // offset: 0xf48
    guiObj mDataObj;  // offset: 0x1020
    missionInfo mMissionInfo;  // offset: 0x1080
    variableInfo mVariableInfo;  // offset: 0x10a4
    nGUIItem::cItemList mItemList;  // offset: 0x10c0
    MtVector4 mDetailPos;  // offset: 0x1240
    MtVector4 mPopBonusPos;  // offset: 0x1250
    MtStringEx<512> mTempStr;  // offset: 0x1260
    u32 mItemNum;  // offset: 0x1464
    u32 mOldScheduleId;  // offset: 0x1468
    f32 mCaptionFrameBottom_PosY;  // offset: 0x146c
    f32 mLv_PosY;  // offset: 0x1470
    bool mIsSetupComp;  // offset: 0x1474
    bool mIsSetupInfo;  // offset: 0x1475
    bool mIsLCAlignment;  // offset: 0x1476
    bool mIsDecide;  // offset: 0x1477
    bool mIsCancel;  // offset: 0x1478
    bool mIsMemberInfo;  // offset: 0x1479
    bool mIsEnableOrder;  // offset: 0x147a
    bool mIsExecuteCtrl;  // offset: 0x147b
    bool mIsSkipAction;  // offset: 0x147c
    bool mIsStandAlone;  // offset: 0x147d
    bool mIsGuideDetailEnable;  // offset: 0x147e
    bool mIsInitWindowActive;  // offset: 0x147f
    bool mIsSolo;  // offset: 0x1480
    u32 mPlayType;  // offset: 0x1484
    u32 mMemberNum;  // offset: 0x1488
    bool mInvitation;  // offset: 0x148c
public:
    static MyDTI DTI;
};

inline uGUIPopRmcQuestInfo* uGUIMissionInfo::getGUIPopRmcQuestInfoPtr() {
    return this->mpPopBonus;
}

inline u32 uGUIMissionInfo::getMemberNum() {
    return this->mMemberNum;
}

inline void uGUIMissionInfo::eventDecide() {
    this->mIsDecide = true;
}

inline void uGUIMissionInfo::eventCancel() {
    this->mIsCancel = true;
}

inline uGUIMissionInfo::missionInfo::missionInfo() {
}
