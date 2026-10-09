#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtColor.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/nQuest.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector2;
class cContextInstHm;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObjTextureSet;
class cGUIObject;
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cGUIListData; }
class rGUI;
class rGUIMessage;
class uGUIMap;
class uGUIPopDetail01;
class uGUISystemMsg;

// Declarations
class uGUIQuestList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nQuest { using GUIListDataArray = MtTypedArray<nQuest::cGUIListData>; }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIQuestList : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_MY_LIST_WAIT = 1,
        FLOW_MY_LIST = 2,
        FLOW_PARTY_LIST_WAIT = 3,
        FLOW_PARTY_LIST = 4,
        FLOW_INFO_WAIT = 5,
        FLOW_DETAIL = 6,
        FLOW_REWARD = 7,
        FLOW_PROGRESS = 8,
        FLOW_PRIO = 9,
        FLOW_DESTROY = 10,
        FLOW_DESTROY_WAIT = 11,
        FLOW_ORDER = 12,
        FLOW_ORDER_WAIT = 13,
        FLOW_MAP = 14,
        FLOW_END = 15,
    };
    enum
    {
        CMD_NONE = 0,
        CMD_SET_PRIO = 1,
        CMD_CLEAR_PRIO = 2,
        CMD_DESTROY = 3,
        CMD_MAP = 4,
        CMD_ORDER = 5,
    };
    enum
    {
        QUEST_UI_DISP_TYPE_WAIT_ORDER = 5,
        QUEST_UI_DISP_TYPE_LIST_NUM = 6,
    };
    enum
    {
        GUIDE_DECIDE = 0,
        GUIDE_ACTIVE_ON = 1,
        GUIDE_ACTIVE_OFF = 2,
        GUIDE_CHANGE_INFO = 3,
        GUIDE_TOGGLE = 4,
        GUIDE_NUM = 5,
    };
    enum
    {
        MENU_MAP = 0,
        MENU_PRIO = 1,
        MENU_DESTROY = 2,
        MENU_NUM = 3,
    };
    enum
    {
        TAB_DETAIL = 0,
        TAB_REWARD = 1,
        TAB_NUM = 2,
    };
    enum
    {
        TOGGLE_MY_LIST = 0,
        TOGGLE_PARTY_LIST = 1,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CLOSE = 68,
        INPUTEVENT_START = 69,
        INPUTEVENT_CHECK_ON = 70,
        INPUTEVENT_CHECK_OFF = 71,
        INPUTEVENT_TOGGLE = 72,
        INPUTEVENT_ADJUST_CURSOR = 73,
        INPUTEVENT_ADJUST_TAB = 74,
        INPUTEVENT_MOUSE_OUT = 75,
        INPUTEVENT_MOUSE_OVER = 76,
    };
public:
    class MyDTI;
    struct stMain;
    struct stList;
    struct stListHead;
    class cListItem;
    struct stInfo;
    struct stMenuIcon;
    struct stRecommend;
    struct stImage;
    struct stCaption;
    struct stProgress;
    struct stReward;
    struct stRewardItem;
    struct stBonus;
    struct stBonusItem;
    struct stVariable;
    class cListInfo;
    class cDetailInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgSubTitle;  // offset: 0x18
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x20
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0xb8
    };
public:
    struct stListHead
    {
    public:
        stListHead();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        uGUIBase::cReferenceUIChargesInfo mCharge;  // offset: 0x18
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
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x58
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x60
        cGUIObjMessage* mpObjMsgLvVal;  // offset: 0x68
        cGUIObjTexture* mpObjTexBonus;  // offset: 0x70
        cGUIInstAnimation* mpInstAnimIconClear;  // offset: 0x78
        uGUIBase::cReferenceUIIconQuest mQuestIcon;  // offset: 0x80
        static MyDTI DTI;
    };
public:
    struct stMenuIcon
    {
    public:
        stMenuIcon();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjTexture* mpObjTex;  // offset: 0x8
        cGUIObjTexture* mpObjTexFocus;  // offset: 0x10
        cGUIObjPolygon* mpObjPolyMouseCollision;  // offset: 0x18
        cGUIObjNull* mpObjNullPointer;  // offset: 0x20
        bool mIsEnable;  // offset: 0x28
    };
public:
    struct stRecommend
    {
    public:
        stRecommend();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x10
        cGUIObjMessage* mpObjMsgLvVal;  // offset: 0x18
    };
public:
    struct stImage
    {
    public:
        stImage();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjTexture* mpObjTex;  // offset: 0x8
    };
public:
    struct stCaption
    {
    public:
        stCaption();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgClient;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        cGUIObjTexture* mpObjTexBg;  // offset: 0x18
        cGUIObjTextureSet* mpObjTexBottom;  // offset: 0x20
        cGUIObjNull* mpObjNull;  // offset: 0x28
        f32 mDefaultBgSize;  // offset: 0x30
        f32 mDefaultBottomPos;  // offset: 0x34
    };
public:
    struct stProgress
    {
    public:
        stProgress();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
        cGUIObjMessage* mpObjMsgAdvance;  // offset: 0x10
        cGUIObjMessage* mpObjMsgHeader;  // offset: 0x18
        cGUIObjTexture* mpObjTexIcon;  // offset: 0x20
        cGUIObjNull* mpObjNull;  // offset: 0x28
        MtColor mDefaultAdvanceColor;  // offset: 0x30
    };
public:
    struct stRewardItem
    {
    public:
        stRewardItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x10
    };
public:
    struct stBonusItem
    {
    public:
        stBonusItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgCaption;  // offset: 0x10
        cGUIObjMessage* mpObjMsgLimit;  // offset: 0x18
        cGUIObjPolygon* mpObjPolyLine;  // offset: 0x20
        uGUIBase::cReferenceUIChargesInfo mCharge;  // offset: 0x28
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 param_questlist;  // offset: 0x0
        s32 param_questheader;  // offset: 0x4
        s32 param_scroll;  // offset: 0x8
        s32 param_bonusicon;  // offset: 0xc
        s32 param_selectreward;  // offset: 0x10
        s32 param_goal;  // offset: 0x14
        s32 param_cr_list_x;  // offset: 0x18
        s32 param_tab;  // offset: 0x1c
        s32 param_size_questimg;  // offset: 0x20
        s32 param_size_goalbase;  // offset: 0x24
        s32 param_ofst_goalbase;  // offset: 0x28
        s32 param_size_caption;  // offset: 0x2c
        s32 param_ofst_caption;  // offset: 0x30
        s32 param_size_progress;  // offset: 0x34
        s32 param_size_rewardheadr;  // offset: 0x38
        s32 param_size_reward;  // offset: 0x3c
        s32 param_size_reward0;  // offset: 0x40
        s32 param_spacing_reward;  // offset: 0x44
        s32 param_size_goalbase01;  // offset: 0x48
        s32 param_size_progress01;  // offset: 0x4c
        s32 param_size_questlv;  // offset: 0x50
        s32 param_size_selectreward;  // offset: 0x54
        s32 param_bonus_list_y;  // offset: 0x58
        s32 param_bonus_title_y;  // offset: 0x5c
        s32 param_bonus_line_y;  // offset: 0x60
        s32 param_bonus_margin;  // offset: 0x64
        s32 param_charges_size_x;  // offset: 0x68
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
    public:
        const nQuest::cGUIListData* mpData;  // offset: 0x28
        s32 mMemberIndex;  // offset: 0x30
        bool mIsMyQuest;  // offset: 0x34
        bool mIsActive;  // offset: 0x35
        bool mIsWaitOrder;  // offset: 0x36
        static MyDTI DTI;
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
        // Address: 0x01b02860 - 0x01b02861 (1 bytes)
        virtual ~cDetailInfo() {}
    public:
        cGUIInstance* mpInstPointerTarget;  // offset: 0x28
        cGUIObject* mpObjPointerTarget;  // offset: 0x30
        bool mIsReward;  // offset: 0x38
        static MyDTI DTI;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x0
        cGUIObjMessage* mpObjMsgOrder;  // offset: 0x8
        cGUIObjMessage* mpObjMsgOrderNum;  // offset: 0x10
        uGUIQuestList::stListHead mHead[10];  // offset: 0x18
        uGUIQuestList::cListItem mListItem[20];  // offset: 0xe78
        uGUIBase::cReferenceUIToggleBtn mToggle;  // offset: 0x29f8
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x2ab0
        uGUIBase::cScrollList mListCtrl;  // offset: 0x2b60
        s32 mHeadHeight;  // offset: 0x2e10
        s32 mListHeight;  // offset: 0x2e14
        MtColor mOrderNumDefColor;  // offset: 0x2e18
        f32 mActiveUpdateTimer;  // offset: 0x2e1c
        static const u32 head_num = 10;
        static const u32 item_num = 20;
    };
public:
    struct stReward
    {
    public:
        stReward();
    public:
        cGUIInstAnimation* mpInstAnimSelectBox[3];  // offset: 0x0
        cGUIObjMessage* mpObjMsgAreaName;  // offset: 0x18
        cGUIObjMessage* mpObjMsgAreaPt;  // offset: 0x20
        cGUIObjMessage* mpObjMsgAreaPtVal;  // offset: 0x28
        cGUIObjMessage* mpObjMsgXP;  // offset: 0x30
        cGUIObjMessage* mpObjMsgXPVal;  // offset: 0x38
        cGUIObjMessage* mpObjMsgGold;  // offset: 0x40
        cGUIObjMessage* mpObjMsgGoldVal;  // offset: 0x48
        cGUIObjMessage* mpObjMsgRim;  // offset: 0x50
        cGUIObjMessage* mpObjMsgRimVal;  // offset: 0x58
        cGUIObjMessage* mpObjMsgSelectReward;  // offset: 0x60
        cGUIObjMessage* mpObjMsgRandomReward;  // offset: 0x68
        cGUIObjMessage* mpObjMsgHeader;  // offset: 0x70
        cGUIObjTexture* mpObjTexIcon;  // offset: 0x78
        uGUIQuestList::stRewardItem mItem[5];  // offset: 0x80
        u32 mItemNum;  // offset: 0x850
        cGUIObjMessage* mpObjMsgClanPtLabel;  // offset: 0x858
        cGUIObjMessage* mpObjMsgClanPt;  // offset: 0x860
        cGUIObjMessage* mpObjMsgClanPtVal;  // offset: 0x868
        cGUIObjTexture* mpObjTexIconClanClearNum;  // offset: 0x870
        cGUIObjMessage* mpObjMsgClanClearNum;  // offset: 0x878
        cGUIObjMessage* mpObjMsgClanClearHeader;  // offset: 0x880
        static const u32 item_num = 5;
    };
public:
    struct stBonus
    {
    public:
        stBonus();
    public:
        cGUIObjMessage* mpObjMsgHeader;  // offset: 0x0
        cGUIObjTexture* mpObjTexIcon;  // offset: 0x8
        uGUIQuestList::stBonusItem mBonus[10];  // offset: 0x10
        static const u32 bonus_num = 10;
    };
public:
    struct stInfo
    {
    public:
        stInfo();
    public:
        cGUIInstNull* mpInstNullInfo;  // offset: 0x0
        cGUIInstNull* mpInstNullBns;  // offset: 0x8
        cGUIInstNull* mpInstNullDetail;  // offset: 0x10
        cGUIInstNull* mpInstNullCmd;  // offset: 0x18
        cGUIInstNull* mpInstNullImage;  // offset: 0x20
        cGUIInstNull* mpInstNullRecommend;  // offset: 0x28
        cGUIInstNull* mpInstNullAdvance;  // offset: 0x30
        cGUIInstNull* mpInstNullCaption;  // offset: 0x38
        cGUIInstNull* mpInstNullProgress;  // offset: 0x40
        cGUIInstNull* mpInstNullPointHeader;  // offset: 0x48
        cGUIInstNull* mpInstNullPoint;  // offset: 0x50
        cGUIInstNull* mpInstNullAreaPoint;  // offset: 0x58
        cGUIInstNull* mpInstNullReward;  // offset: 0x60
        cGUIInstNull* mpInstNullBonus;  // offset: 0x68
        cGUIInstAnimation* mpInstAnimEmblem;  // offset: 0x70
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x78
        cGUIObjMessage* mpObjMsgId;  // offset: 0x80
        cGUIObjMessage* mpObjMsgNotice;  // offset: 0x88
        cGUIObjMessage* mpObjMsgPeriod;  // offset: 0x90
        cGUIObjTexture* mpObjTexPeriod;  // offset: 0x98
        cGUIObjTexture* mpObjTexMenu;  // offset: 0xa0
        cGUIObjPolygon* mpObjPolyMask;  // offset: 0xa8
        uGUIQuestList::stMenuIcon mMenu[3];  // offset: 0xb0
        uGUIQuestList::stRecommend mRecom;  // offset: 0x140
        uGUIQuestList::stImage mImage;  // offset: 0x160
        uGUIQuestList::stCaption mCaption;  // offset: 0x170
        uGUIQuestList::stProgress mAdvance;  // offset: 0x1a8
        uGUIQuestList::stProgress mNowProgress;  // offset: 0x1e0
        uGUIQuestList::stProgress mProgress[10];  // offset: 0x218
        uGUIQuestList::stReward mReward;  // offset: 0x450
        uGUIQuestList::stBonus mBonus;  // offset: 0xce0
        uGUIBase::cReferenceUITab mTab;  // offset: 0x1bf0
        uGUIBase::cScrollListItemBase mListItem[20];  // offset: 0x1ca0
        uGUIBase::cScrollList mScrollCtrl;  // offset: 0x2380
        u32 mRewardPos;  // offset: 0x2630
        bool mIsInfoReq;  // offset: 0x2634
        cGUIInstAnimation* mpInstAnimIconClear;  // offset: 0x2638
        cGUIInstNull* mpInstNullClanPoint;  // offset: 0x2640
        cGUIInstNull* mpInstNullClanClearNum;  // offset: 0x2648
        static const u32 list_item_num = 20;
        static const u32 progress_num = 10;
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
    uGUIQuestList();
    virtual ~uGUIQuestList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setScheduleId(u32 schedule_id, bool isParty);
private:
    void setupMenuItem(stMenuIcon& menu, cGUIInstance* pInst, f32 frame);
    void setupProgressItem(stProgress& progress, cGUIInstance* pInst, cGUIInstance* pInstHeader);
    void setFlowId(u32 flow_id);
    void setupWindowActive();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateInit();
    void updateMove();
    void updateExit();
    void initCallback(u32 ErrorCode);
public:
    void setInputEvent(u32 event_id);
    void eventDecide();
    void eventCancel();
    void eventClose();
    void eventStart();
    void eventCheckOn();
    void eventCheckOff();
    void eventToggle();
    void setActiveQuest(bool isActive);
    void eventAdjustCursor();
    void eventAdjustTab();
    void eventMouseOut();
    void eventMouseOver();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlCheck(cControl::Message* msg);
    u32 evCtrlToggle(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustTab(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    bool evCtrlScrl(cControl::Message* msg);
private:
    bool isUpdateAnyList();
    bool isReleaseAnyTask();
    bool isLoadingInfo();
    const nQuest::cGUIListData* getIndexData();
    u32 getSelectListFlowId();
    u32 getSelectInfoFlowId();
    void setupMyListWait();
    void updateMyListWait();
    void setupMyList();
    void setupPartyListWait();
    void updatePartyListWait();
    void setupPartyList();
    void clearList();
    void createMyList();
    void createPartyList();
    void createListAfter();
    void createPartyMemberList(const cContextInstHm* pContext, s32& list_pos, u32& header_count, u32& quest_count, u32 schedule_id);
    void setupPartyListHeader(stListHead& head, s32 list_pos, MT_CTSTR msg);
    void updateQuestActive();
    void adjustListCursor();
    void adjustToggle();
    void decideList();
    void setListCursorPos(cListInfo* pInfo, bool isImmediate);
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    cListInfo* getListInfo(u32 index);
    cListInfo* getListInfo();
    cListItem* getListItem(u32);
    cListItem* getListItem();
    void setupQuestOrderNum();
    void updateInfoWait();
    void updateInfoReq();
    void clearInfo();
    void initInfo();
    bool isWaitOrderQuest();
    void setupInfo();
    void updateEnableChangeActive(bool isInit);
    void updateListGuide();
    void setPurposeMsg(cGUIObjMessage* pObjMsg, MT_CTSTR pMsg, nQuest::SCHEDULE_ID schedule_id);
    void setupItemIcon(u32& count, u32 id, u32 num, bool isRandom, u32 boxNo);
    void setupBonusPos(stBonusItem& bonus, s32& bonus_pos, s32& list_pos, s32& length);
    void setupDetail();
    void setupReward();
    void setupProgress();
    void adjustTab();
    void adjustInfoCursor();
    void decideInfo();
    u32 getChargeAttribute(u32 quest_type);
    void setupNull(cGUIInstNull* pInst, s32 list_pos, s32& length, s32 height);
    void addInfo(cGUIInstance* pInst, cGUIObject* pObj, s32& list_pos, s32& length, bool isReward);
    void setupDetailItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideDetailItem(uGUIBase::cScrollListItemBase* pItemBase);
    void decideMenuBtn();
    u32 callbackDummy(MtObject*, MtObject*);
    u32 callbackSetActive(MtObject*, MtObject*);
    u32 callbackClearActive(MtObject*, MtObject*);
    u32 callbackOrderCancel(MtObject*, MtObject*);
    u32 callbackMap(MtObject*, MtObject*);
    u32 callbackOrder(MtObject*, MtObject*);
    void setupPrio();
    void setupDestroy();
    void updateDestroy();
    void updateDestroyWait();
    void setupOrder();
    void updateOrder();
    void updateOrderWait();
    void setupMap();
    void updateMap();
    s32 getStageNoQuestMap(nQuest::SCHEDULE_ID sdlId);
    void setDispDetail(u32 itemId);
    void hideDetail();
    void updateDetail();
    bool questListSort(const nQuest::cGUIListData* pA, const nQuest::cGUIListData* pB, u32 param);
    void setInstAddPosX(cGUIInstNull*, f32);
    void setInstAddPosY(cGUIInstNull* pInst, f32 add);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    void callPointer(u32 prio);
    bool isClanMission(const nQuest::cGUIListData* listData) const;
    u32 getClanPoint(const nQuest::cGUIListData* listData) const;
    u32 getClanClearNum(const nQuest::cGUIListData* listData) const;
    u32 getClanClearMax(const nQuest::cGUIListData* listData) const;
    bool isClanClear(const nQuest::cGUIListData* listData) const;
private:
    MtVector2 mPointerPos;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    rGUIMessage* mpGMDRes;  // offset: 0x8d8
    u32 mFlowId;  // offset: 0x8e0
    u32 mCmdResult;  // offset: 0x8e4
    nQuest::SCHEDULE_ID mRequestScheduleId;  // offset: 0x8e8
    bool mIsAutoOpen;  // offset: 0x8f8
    bool mIsOpenPartyList;  // offset: 0x8f9
    u32 mDrawItemId;  // offset: 0x8fc
    u32 mSelectItemId;  // offset: 0x900
    stMain mMain;  // offset: 0x908
    stList mList;  // offset: 0xa20
    stInfo mInfo;  // offset: 0x3840
    stVariable mVar;  // offset: 0x5e90
    nQuest::GUIListDataArray mIndexList[6];  // offset: 0x5f00
    cControl* mpDecideCtrl;  // offset: 0x5fc0
    cControl* mpCancelCtrl;  // offset: 0x5fc8
    uGUIBase::cVerticalList* mpListCtrl;  // offset: 0x5fd0
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x5fd8
    uGUIBase::cVerticalList* mpInfoUDCtrl;  // offset: 0x5fe0
    uGUIBase::cHorizontalList* mpInfoMenuCtrl;  // offset: 0x5fe8
    uGUIBase::cHorizontalList* mpInfoRewardCtrl;  // offset: 0x5ff0
    MtStringEx<256> mTempStr;  // offset: 0x5ff8
    f32 mUpdateTimer;  // offset: 0x60fc
    uGUISystemMsg* mpSystemMsg;  // offset: 0x6100
    uGUIPopDetail01* mpPopDetail;  // offset: 0x6108
    uGUIMap* mpMap;  // offset: 0x6110
    uGUIBase::cQuestTexLoader mTexLoader;  // offset: 0x6118
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[5];  // offset: 0x61a0
    u32 mGuideBit;  // offset: 0x6268
    bool mIsFirstSetup;  // offset: 0x626c
public:
    static MyDTI DTI;
};
