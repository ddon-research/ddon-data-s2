#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "nGUIExt.h"
#include "nQuest.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
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
namespace nQuest { class cGUIInfoData; }
class rGUI;
class rGUIMessage;
class uGUIPopDetail01;
class uGUIPopRmcQuestInfo;
class uGUIQuestBoard;
class uGUIQuestBoardBase;

// Declarations
class uGUIQuestInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIQuestInfo : public uGUIBase
{
    friend class uGUIQuestBoard;
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_WAIT = 1,
        FLOW_INFO = 2,
        FLOW_ORDER_WAIT = 3,
        FLOW_END = 4,
    };
    enum
    {
        QUEST_INFO_RESULT_NONE = 0,
        QUEST_INFO_RESULT_DECIDE = 1,
        QUEST_INFO_RESULT_CANCEL = 2,
        QUEST_INFO_RESULT_INVALID = 3,
    };
    enum QI_GUIDE_BIT
    {
        QI_DETAIL = 1,
        QI_BIT_MAX = 1,
    };
    enum
    {
        POINT_XP = 0,
        POINT_G = 1,
        POINT_R = 2,
        POINT_NUM = 3,
    };
    enum
    {
        BTN_YES = 0,
        BTN_NO = 1,
        BTN_NUM = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stDetail;
    struct stPoint;
    struct stRewardBase;
    class cRewardItem;
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
        s32 param_itemlist;  // offset: 0x0
        s32 param_btn_emphasis_x;  // offset: 0x4
        s32 param_btn_size_x;  // offset: 0x8
        s32 param_mainquest_pos_x;  // offset: 0xc
        s32 param_size_questimg;  // offset: 0x10
        s32 param_size_questlv;  // offset: 0x14
        s32 param_size_terms00;  // offset: 0x18
        s32 param_ofst_terms00;  // offset: 0x1c
        s32 param_size_caption;  // offset: 0x20
        s32 param_ofst_caption;  // offset: 0x24
        s32 param_size_rewardheader;  // offset: 0x28
        s32 param_size_reward;  // offset: 0x2c
        s32 param_size_reward01;  // offset: 0x30
        s32 param_spacing_reward;  // offset: 0x34
        s32 param_size_reward_notxt;  // offset: 0x38
        s32 param_size_reward_txt;  // offset: 0x3c
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNullCmd;  // offset: 0x0
        cGUIInstNull* mpInstNullBonus;  // offset: 0x8
        cGUIInstNull* mpInstNullDetail;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x18
        cGUIInstAnimation* mpInstAnimEmblem;  // offset: 0x20
        cGUIInstAnimation* mpInstAnimPeriod;  // offset: 0x28
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x30
        cGUIObjMessage* mpObjMsgPeriod;  // offset: 0x38
        cGUIObjTexture* mpObjTexPeriod;  // offset: 0x40
        uGUIBase::cReferenceUIButton2 mBtnYes;  // offset: 0x48
        uGUIBase::cReferenceUIButton mBtnNo;  // offset: 0x1d8
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x368
    };
public:
    struct stPoint
    {
    public:
        stPoint();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgPt;  // offset: 0x8
        cGUIObjMessage* mpObjMsgVal;  // offset: 0x10
    };
public:
    struct stRewardBase
    {
    public:
        stRewardBase();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
    };
public:
    struct stReward
    {
    public:
        stReward();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x10
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
        virtual void addMouseTouchList(cControl* pCtrl, s32 pos);  // vtable slot 6
    public:
        cGUIInstance* mpInstPointerTarget;  // offset: 0x28
        cGUIObject* mpObjPointerTarget;  // offset: 0x30
        bool mIsReward;  // offset: 0x38
        static MyDTI DTI;
    };
public:
    class cRewardItem : public uGUIBase::cScrollListItemBase
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
        cRewardItem();
    public:
        u32 mRewardIndex;  // offset: 0x58
        u32 mRewardNum;  // offset: 0x5c
        uGUIQuestInfo::stReward mReward[5];  // offset: 0x60
        static MyDTI DTI;
        static const u32 reward_num = 5;
    };
public:
    struct stDetail
    {
    public:
        stDetail();
    public:
        cGUIInstNull* mpInstNullImage;  // offset: 0x0
        cGUIInstNull* mpInstNullLv;  // offset: 0x8
        cGUIInstNull* mpInstNullTerms;  // offset: 0x10
        cGUIInstNull* mpInstNullCaption;  // offset: 0x18
        cGUIInstNull* mpInstNullPointHeader;  // offset: 0x20
        cGUIInstNull* mpInstNullPoint;  // offset: 0x28
        cGUIInstNull* mpInstNullAreaPoint;  // offset: 0x30
        cGUIInstNull* mpInstNullReward;  // offset: 0x38
        cGUIInstAnimation* mpInstAnimTerms;  // offset: 0x40
        cGUIObjMessage* mpObjMsgLvRecmd;  // offset: 0x48
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x50
        cGUIObjMessage* mpObjMsgLvVal;  // offset: 0x58
        cGUIObjMessage* mpObjMsgTermsHeader;  // offset: 0x60
        cGUIObjMessage* mpObjMsgTerms;  // offset: 0x68
        cGUIObjMessage* mpObjMsgCaption;  // offset: 0x70
        cGUIObjMessage* mpObjMsgClient;  // offset: 0x78
        cGUIObjMessage* mpObjMsgPointHeader;  // offset: 0x80
        cGUIObjMessage* mpObjMsgArea;  // offset: 0x88
        cGUIObjMessage* mpObjMsgAreaPt;  // offset: 0x90
        cGUIObjMessage* mpObjMsgAreaPtVal;  // offset: 0x98
        cGUIObjNull* mpObjNullCaption;  // offset: 0xa0
        cGUIObjTexture* mpObjTexImage;  // offset: 0xa8
        cGUIObjTexture* mpObjTexIconTermsIcon;  // offset: 0xb0
        cGUIObjTexture* mpObjTexIconPointIcon;  // offset: 0xb8
        cGUIObjTexture* mpObjTexCaptionBg;  // offset: 0xc0
        cGUIObjTextureSet* mpObjTexCaptionBottom;  // offset: 0xc8
        cGUIObjPolygon* mpObjPolyMask;  // offset: 0xd0
        uGUIQuestInfo::stPoint mPoint[3];  // offset: 0xd8
        uGUIQuestInfo::stRewardBase mRewardBase[3];  // offset: 0x120
        uGUIQuestInfo::cRewardItem mReward;  // offset: 0x150
        uGUIBase::cScrollListItemBase mListItem[10];  // offset: 0x980
        uGUIBase::cScrollList mScrollCtrl;  // offset: 0xcf0
        f32 mDefaultCaptionBgSize;  // offset: 0xfa0
        f32 mDefaultCaptionBottomPos;  // offset: 0xfa4
        cGUIInstAnimation* mpInstAnimIconClear;  // offset: 0xfa8
        cGUIInstNull* mpInstNullClanPoint;  // offset: 0xfb0
        cGUIInstNull* mpInstNullClanTerms;  // offset: 0xfb8
        cGUIObjMessage* mpObjMsgClan;  // offset: 0xfc0
        cGUIObjMessage* mpObjMsgClanPt;  // offset: 0xfc8
        cGUIObjMessage* mpObjMsgClanPtVal;  // offset: 0xfd0
        cGUIObjTexture* mpObjTexIconClanTermsIcon;  // offset: 0xfd8
        cGUIObjMessage* mpObjMsgClanTermsHeader;  // offset: 0xfe0
        cGUIObjMessage* mpObjMsgClanClearPtVal;  // offset: 0xfe8
        static const u32 list_item_num = 10;
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
    uGUIQuestInfo(u32 initFlags);
    virtual ~uGUIQuestInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void setOwner(uGUIQuestBoardBase* pOwner);
    void setIndexData(nQuest::SCHEDULE_ID scheduleId);
    const nQuest::cGUIInfoData& getIndexData();
    void setFocus(bool isFocus);
    void requestEnd();
    u32 getQuestInfoResult();
    void clearDetail();
    bool isCleared();
    void setWaitFlow();
    void setDispPos(const MtVector3& pos);
protected:
    virtual void adjustScale();  // vtable slot 84
private:
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void updateWait();
    void setupDetail();
    void setupNull(cGUIInstNull* pInst, s32 list_pos, s32& length, s32 height);
    void addInfo(cGUIInstance* pInst, cGUIObject* pObj, s32& list_pos, s32& length, bool isReward);
    void setupItemIcon(u32& count, u32 id, u32 num, bool isRandom, bool isOffset);
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setupInfo();
    void updateInfo();
    void order();
    void updateOrderWait();
    void cancelInfo();
    void adjustCursor();
    void clearFocus();
    void hideItemDetail();
    void setupItemDetail(u32 item_id);
    void updateItemDetail();
    void eventDecide();
    void eventCancel();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
public:
    void setMode(nGUIExt::QUEST_DISP_MODE mode);
private:
    bool isModeClanMission() const;
    bool isClanMission() const;
    u32 getClanPoint() const;
    u32 getClanClearNum() const;
    u32 getClanClearMax() const;
    bool isClanClear() const;
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    cGUIInstNull* mpInstNull;  // offset: 0x8d8
    u32 mFlowId;  // offset: 0x8e0
    u32 mDrawItemId;  // offset: 0x8e4
    u32 mSelectItemId;  // offset: 0x8e8
    stVariable mVar;  // offset: 0x8ec
    stMain mMain;  // offset: 0x930
    stDetail mDetail;  // offset: 0xd30
    cControl* mpDecideCtrl;  // offset: 0x1d20
    cControl* mpCancelCtrl;  // offset: 0x1d28
    uGUIBase::cVerticalList* mpUDCtrl;  // offset: 0x1d30
    uGUIBase::cHorizontalList* mpLRCtrl;  // offset: 0x1d38
    uGUIBase::cHorizontalList* mpBtnCtrl;  // offset: 0x1d40
    nQuest::cGUIInfoData mIndexData;  // offset: 0x1d48
    uGUIQuestBoardBase* mpOwner;  // offset: 0x1d68
    uGUIPopDetail01* mpPopDetail;  // offset: 0x1d70
    uGUIPopRmcQuestInfo* mpPopBonus;  // offset: 0x1d78
    u32 mQuestInfoResult;  // offset: 0x1d80
    MtStringEx<256> mTempStr;  // offset: 0x1d84
    MtVector3 mDispPos;  // offset: 0x1e90
    uGUIBase::cQuestTexLoader mTexLoader;  // offset: 0x1ea0
    bool mIsCleared;  // offset: 0x1f28
    bool mIsUpdateDetail;  // offset: 0x1f29
    bool mIsMove;  // offset: 0x1f2a
    bool mIsOrderEnable;  // offset: 0x1f2b
    bool mIsEnd;  // offset: 0x1f2c
    bool mIsUpdateAfterDraw;  // offset: 0x1f2d
    bool mIsWaitOrderProgress;  // offset: 0x1f2e
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0x1f30
    u32 mMode;  // offset: 0x1f58
public:
    static MyDTI DTI;
};

inline void uGUIQuestInfo::setOwner(uGUIQuestBoardBase* pOwner) {
    this->mpOwner = pOwner;
}

inline u32 uGUIQuestInfo::getQuestInfoResult() {
    return this->mQuestInfoResult;
}

inline uGUIQuestInfo::stVariable::stVariable() {
}

inline uGUIQuestInfo::stPoint::stPoint() {
}

inline uGUIQuestInfo::stRewardBase::stRewardBase() {
}
