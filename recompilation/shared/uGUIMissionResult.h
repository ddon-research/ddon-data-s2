#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "GpCourseEffect.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "cControl.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjNull;
class rGUI;
class uGUIPopDetail01;
class uGUISystemMsg;

// Declarations
class uGUIMissionResult;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMissionResult : public uGUIBase
{
public:
    enum
    {
        RNORD_INIT = 0,
        RNORD_CREATE = 1,
        RNORD_WAIT = 2,
        RNORD_DONE = 3,
    };
    enum
    {
        RESULT_TAB_START = 0,
        RESULT_TAB_REWARD = 0,
        RESULT_TAB_SCORE = 1,
        RESULT_TAB_NUM = 2,
    };
    enum
    {
        SCROLL_ITEM_ITEM = 0,
        SCROLL_ITEM_DESTITEM = 1,
        SCROLL_ITEM_CHARGE = 2,
        SCROLL_ITEM_NUM = 3,
    };
    enum
    {
        VLID_START = 0,
        REWARD_VLID_ITEM = 0,
        REWARD_VLID_ITEM_DEST = 1,
        REWARD_VLID_FINISH = 2,
        REWARD_VLID_NUM = 3,
        SCORE_VLID_LIST = 0,
        SCORE_VLID_FINISH = 1,
        SCORE_VLID_NUM = 2,
    };
    enum
    {
        INPUTEVENT_VL_MOVE = 66,
        INPUTEVENT_TO_FINISH = 67,
        INPUTEVENT_PAGE_MOVE = 68,
        INPUTEVENT_ITEM_MOVE = 69,
        INPUTEVENT_TAB_CTRL = 70,
        INPUTEVENT_EXIT = 71,
    };
public:
    class MyDTI;
    struct stRow;
    class cChargeEffectInfo;
    struct stResultData;
    class cPointList;
    class cItemList;
    struct stResultScore;
    class cResultScrollItem;
    class cResultScrollInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stRow
    {
    public:
        cGUIInstAnimation* mpInst;  // offset: 0x0
        cGUIObjNull* mpObjNull;  // offset: 0x8
        cGUIObjMessage* mpObjMsgName;  // offset: 0x10
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x18
        cGUIObjMessage* mpObjMsgNumClass;  // offset: 0x20
        cGUIObjMessage* mpObjMsgPt;  // offset: 0x28
        cGUIObjMessage* mpObjMsgPtClass;  // offset: 0x30
    };
public:
    class cChargeEffectInfo : public MtObject
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
        cChargeEffectInfo();
        // Address: 0x01af86b0 - 0x01af86b1 (1 bytes)
        virtual ~cChargeEffectInfo() {}
    public:
        u32 mCourseId;  // offset: 0x8
        u32 mEffectId;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cPointList : public MtObject
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
        cPointList();
        virtual ~cPointList();
    public:
        MtString mStrName;  // offset: 0x8
        MtString mStrNum;  // offset: 0x10
        MtString mStrNumClass;  // offset: 0x18
        MtString mStrPt;  // offset: 0x20
        MtString mStrPtClass;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    class cItemList : public MtObject
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
        cItemList();
        // Address: 0x01af8700 - 0x01af8701 (1 bytes)
        virtual ~cItemList() {}
    public:
        u32 mItemNo;  // offset: 0x8
        u32 mItemNum;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    struct stResultScore
    {
    public:
        stResultScore();
    public:
        cGUIInstAnimation* mpInst;  // offset: 0x0
        cGUIObjMessage* mpObjMsgNameLabel;  // offset: 0x8
        cGUIObjMessage* mpObjMsgPointLabel;  // offset: 0x10
        cGUIObjMessage* mpObjMsgUnitLabel;  // offset: 0x18
    };
public:
    class cResultScrollItem : public uGUIBase::cScrollListItemBase
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
        cResultScrollItem();
        // Address: 0x01af83a0 - 0x01af83a1 (1 bytes)
        virtual ~cResultScrollItem() {}
    public:
        cGUIInstAnimation* mpInstHeader;  // offset: 0x58
        cGUIInstance* mpInstNoReward;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    class cResultScrollInfo : public uGUIBase::cScrollListInfoBase
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
        cResultScrollInfo();
        // Address: 0x01af8620 - 0x01af8621 (1 bytes)
        virtual ~cResultScrollInfo() {}
    public:
        MT_CTSTR mpListHeader;  // offset: 0x28
        f32 mDistX;  // offset: 0x30
        f32 mDistY;  // offset: 0x34
        static MyDTI DTI;
    };
public:
    struct stResultData
    {
    public:
        stResultData();
    public:
        MT_CTSTR mResTitle;  // offset: 0x0
        bool mIsCharge;  // offset: 0x8
        MtTypedArray<uGUIMissionResult::cPointList> mResPointList;  // offset: 0x10
        MtTypedArray<uGUIMissionResult::cItemList> mRewardList;  // offset: 0x30
        u32 mScoreTech;  // offset: 0x50
        u32 mScoreThis;  // offset: 0x54
        u32 mBonusScore;  // offset: 0x58
        u32 mScoreTotal;  // offset: 0x5c
        u32 mBonusJP;  // offset: 0x60
        u32 mBonusEXP;  // offset: 0x64
        bool mIsDestTarget;  // offset: 0x68
        MtTypedArray<uGUIMissionResult::cItemList> mDestRewardList;  // offset: 0x70
        bool mIsNewTechScore;  // offset: 0x90
        u32 mScoreBestTech;  // offset: 0x94
        bool mIsRanking;  // offset: 0x98
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
    uGUIMissionResult();
    virtual ~uGUIMissionResult();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
private:
    void updateInit();
    void updateWaitRwdDialog();
    void updateRewardWait();
    void updateScoreWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void evVLMove();
    void evVLToFinish();
    void evPageMove();
    void evItemMove();
    void evFinishExit();
    void evTabMove();
    u32 evVLCtrlMove(cControl::Message* msg);
    u32 evVLCtrlToFinish(cControl::Message* msg);
    u32 evHLPageMove(cControl::Message* msg);
    u32 evHLItemMove(cControl::Message* msg);
    u32 evHLItemMoveMouse(cControl::Message* msg);
    u32 evFinishCtrlExit(cControl::Message* msg);
    u32 evCtrlTabMove(cControl::Message* msg);
    void updateDisp();
    void updateRewardItemDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateRewardItemHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateCursor();
    void updateRewardTabCursor();
    void updateScoreTabCursor();
    void unFocusRewardIcon();
    void updateDetail();
    void showDetail(u32 itemID);
    void hideDetail();
    bool isVisibleDetail();
    void setupResultData();
    void addPointList(MtString name, MtString num, MtString numClass, MtString pt, MtString ptClass);
    void initResultWindow();
    void initResultController();
    void setTabType(u32 type);
    void setRewardTab();
    void setScoreTab();
    void setCommon();
    void setControl();
    void setChargeEffect();
    u32 getPagerMax();
    void makeGrandMissionPointString(MtString& str, s32 num);
    bool isRanking();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x8d0
    uGUIBase::cReferenceUINumPager mPager;  // offset: 0x8d8
    uGUIBase::cReferenceUIIconItem mRewardIcon[8];  // offset: 0x980
    uGUIBase::cReferenceUIIconItem mRewardDestIcon[8];  // offset: 0x1580
    uGUIBase::cReferenceUIButton2 mBtnFinish;  // offset: 0x2180
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x2310
    uGUIBase::cReferenceUIChargesInfo mCharge;  // offset: 0x23a8
    uGUIBase::cReferenceUITab mTab;  // offset: 0x2500
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0x25b0
    uGUIPopDetail01* mpGUIPopDetail;  // offset: 0x2608
    stRow mRows[5];  // offset: 0x2610
    cGUIInstNull* mpInstNullList;  // offset: 0x2728
    cGUIInstNull* mpInstNullItemDetail;  // offset: 0x2730
    cGUIObjMessage* mpObjMsgCntDown;  // offset: 0x2738
    uGUIBase::cVerticalList* mpVLCmnCtrl;  // offset: 0x2740
    uGUIBase::cHorizontalList* mpHLPageCtrl;  // offset: 0x2748
    uGUIBase::cHorizontalList* mpHLReward;  // offset: 0x2750
    uGUIBase::cHorizontalList* mpHLDestReward;  // offset: 0x2758
    cControl* mpFinishCtrl;  // offset: 0x2760
    s32 mDialogIdx;  // offset: 0x2768
    u32 mRnoRwdDialog;  // offset: 0x276c
    f32 mSizeItemIcon;  // offset: 0x2770
    f32 mCount;  // offset: 0x2774
    s32 mCountIntOld;  // offset: 0x2778
    f32 mCountScore;  // offset: 0x277c
    u32 mCountScoreUValOld;  // offset: 0x2780
    f32 mCountScoreT;  // offset: 0x2784
    u32 mCountScoreTUValOld;  // offset: 0x2788
    MtTypedArray<cChargeEffectInfo> mChargeEffectEnableList;  // offset: 0x2790
    f32 mCountScoreTechB;  // offset: 0x27b0
    u32 mCountScoreTechBUValOld;  // offset: 0x27b4
    bool mIsOnceUpdate;  // offset: 0x27b8
    stResultData mResultData;  // offset: 0x27c0
    stResultScore mScore;  // offset: 0x2860
    stResultScore mScoreTotal;  // offset: 0x2880
    stResultScore mScoreTechBest;  // offset: 0x28a0
    cGUIObjMessage* mpObjMsgTitle;  // offset: 0x28c0
    uGUIBase::cHorizontalList* mpCtrlTab;  // offset: 0x28c8
    uGUIBase::cScrollList mScrollList;  // offset: 0x28d0
    cResultScrollItem mResultScrollItem[3];  // offset: 0x2b80
    cGUIObjMessage* mpObjMsgNoPointList;  // offset: 0x2cb8
    cGUIObjMessage* mpObjMsgNoRewardList;  // offset: 0x2cc0
    cGUIInstAnimation* mpInstScoreBase;  // offset: 0x2cc8
    cGUIInstAnimation* mpInstUpdate;  // offset: 0x2cd0
    u32 mNowTab;  // offset: 0x2cd8
    bool mIsSetup;  // offset: 0x2cdc
public:
    static MyDTI DTI;
    static const u32 ROWS_MAX = 5;
    static const u32 ITEMDISP_MAX = 8;
    static const u32 SEC_SCORECNT = 1;
private:
    static const nGpCourse::E_GP_COURSE_EFFECT mChargeEffectTable[];
};

// Inline, no code of its own: checked where it is inlined.
inline uGUIMissionResult::cChargeEffectInfo::cChargeEffectInfo() {
    this->mCourseId = static_cast<u32>(0);
    this->mEffectId = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIMissionResult::cItemList::cItemList() {
    this->mItemNo = static_cast<u32>(0);
    this->mItemNum = static_cast<u32>(0);
}
