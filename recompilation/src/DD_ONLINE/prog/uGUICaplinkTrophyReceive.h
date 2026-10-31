#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "uGUIBase.h"
#include "uGUICaplinkProfile.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cCaplinkProfIconLoader;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
class rGUI;
class uGUICaplinkTopMenu;
class uGUISystemMsg;

// Declarations
class uGUICaplinkTrophyReceive;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICaplinkTrophyReceive : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_SERVER_WAIT = 1,
        FLOW_LIST = 2,
        FLOW_DETAIL = 3,
        FLOW_CONFIRM = 4,
        FLOW_NOTICE = 5,
        FLOW_END = 6,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CLOSE = 68,
    };
    enum
    {
        REQ_FLAG_RECEIVE_REWARD = 0,
        REQ_FLAG_NUM = 1,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stList;
    class cListItem;
    struct stDetail;
    struct stReward;
    class cListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 mParam_ofst_list_item_x;  // offset: 0x0
        s32 mParam_ofst_list_y;  // offset: 0x4
        s32 mParam_ofst_rewarditem_y;  // offset: 0x8
        s32 mParam_size_caption_y;  // offset: 0xc
        s32 mParam_ofst_star_x;  // offset: 0x10
        s32 mParam_size_difficulty_y;  // offset: 0x14
        s32 mParam_ofst_caption_y;  // offset: 0x18
        s32 mParam_cr_list_x;  // offset: 0x1c
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstAnimation* mpInstAnimStatusIcon;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimLoading;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgSubTitle;  // offset: 0x18
        cGUIObjMessage* mpObjMsgContentName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgCompleteNum;  // offset: 0x28
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x30
        cCaplinkProfIconLoader mIcon;  // offset: 0x88
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
        virtual ~cListItem();
    public:
        cGUIInstAnimation* mpInstAnimStatusIcon;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimStatus;  // offset: 0x60
        cGUIObjMessage* mpObjMsgTrophyName;  // offset: 0x68
        cGUIObjMessage* mpObjMsgStatus;  // offset: 0x70
        uGUIBase::cReferenceUIIconItem mItemIcon[3];  // offset: 0x80
        static MyDTI DTI;
        static const u32 reward_num = 3;
    };
public:
    struct stReward
    {
    public:
        stReward();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x20
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
        s32 mId;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x0
        uGUIBase::cScrollList mListCtrl;  // offset: 0x10
        uGUICaplinkTrophyReceive::cListItem mList[9];  // offset: 0x2c0
        static const u32 item_num = 9;
    };
public:
    struct stDetail
    {
    public:
        stDetail();
    public:
        cGUIInstNull* mpInstNullReward;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimStar[10];  // offset: 0x8
        cGUIInstAnimation* mpInstAnimStamp;  // offset: 0x58
        cGUIObjMessage* mpObjMsgTrophyName;  // offset: 0x60
        cGUIObjMessage* mpObjMsgDifficulty;  // offset: 0x68
        cGUIObjMessage* mpObjMsgCaptionTitle;  // offset: 0x70
        cGUIObjMessage* mpObjMsgCaption;  // offset: 0x78
        cGUIObjMessage* mpObjMsgReward;  // offset: 0x80
        cGUIObjMessage* mpObjMsgPeriod;  // offset: 0x88
        cGUIObjTexture* mpObjTexCaptionBG;  // offset: 0x90
        cGUIObjTexture* mpObjTexCaptionBottom;  // offset: 0x98
        f32 mTopOffset;  // offset: 0xa0
        f32 mCaptionBGDefaultSize;  // offset: 0xa4
        f32 mCaptionBottomDefaultPos;  // offset: 0xa8
        uGUICaplinkTrophyReceive::stReward mReward[3];  // offset: 0xb0
        uGUIBase::cReferenceUIButton2 mButton;  // offset: 0x590
        static const u32 star_num = 10;
        static const u32 reward_num = 3;
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
    uGUICaplinkTrophyReceive();
    virtual ~uGUICaplinkTrophyReceive();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void setOwner(uGUICaplinkTopMenu* pOwner);
private:
    void setFlowId(u32 flow_id, bool is_init);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupCompleteNum();
    void setupList();
    void setupDetail();
    u32 getItemId(s32 type, s32 id);
    u32 getItemIdFromWalletPointType(s32 type);
    void setupListItem(uGUIBase::cScrollListItemBase* pListItem, uGUIBase::cScrollListInfoBase* pListInfo, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pListItem);
    cListInfo* getListInfo();
    cListInfo* getListInfo(u32 index);
    void setupConfirm();
    void updateConfirm();
    void setupNotice();
    void updateNotice();
    void eventDecide();
    void eventCancel();
    void eventClose();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlButton(cControl::Message* msg);
    bool evCtrlScrl(cControl::Message* msg);
    bool isRequest(u32 flag);
    void setRequest(u32 flag);
    void clearRequest(u32 flag);
    void requestServer(u32 next_flow_id);
    void requestNext();
    bool requestReceiveReward();
    void callbackReceiveReward();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mFlowId;  // offset: 0x8d0
    u32 mFlowIdNext;  // offset: 0x8d4
    u32 mRequestFlag;  // offset: 0x8d8
    MtStringEx<33> mContentId;  // offset: 0x8dc
    stVariable mVar;  // offset: 0x904
    stMain mMain;  // offset: 0x928
    stList mList;  // offset: 0x9d0
    stDetail mDetail;  // offset: 0x3990
    cControl* mpDecideCtrl;  // offset: 0x40b0
    cControl* mpCancelCtrl;  // offset: 0x40b8
    cControl* mpButtonCtrl;  // offset: 0x40c0
    uGUICaplinkTopMenu* mpOwner;  // offset: 0x40c8
    uGUISystemMsg* mpSystemMsg;  // offset: 0x40d0
    MtStringEx<256> mTempStr;  // offset: 0x40d8
public:
    static MyDTI DTI;
};
