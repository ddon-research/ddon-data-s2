#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/Common.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "uGUIBase.h"

// Forward declarations
class CDataCommonU32;
class CDataRankingData;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector2;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObject;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIRankingBoard;

// Type aliases from DWARF
using CRankingData = CDataRankingData;
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using RankingDataVec = MtTypedArray<CDataRankingData>;
using _Sizet = long unsigned int;
using __int64_t = long int;
using f32 = float;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIRankingBoard : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_GET_LIST = 1,
        FLOW_UPDATE_LIST = 2,
        FLOW_INIT = 3,
        FLOW_LIST = 4,
        FLOW_GET_RANK = 5,
        FLOW_RANK = 6,
        FLOW_STATUS = 7,
        FLOW_END = 8,
    };
    enum
    {
        TAB_WHOLE = 0,
        TAB_CLAN = 1,
        TAB_NUM = 2,
    };
    enum
    {
        TYPE_DEFAULT = 0,
        TYPE_MYRANK = 1,
        TYPE_NUM = 2,
    };
    enum
    {
        REQ_FLAG_GET_BOARD_LIST = 0,
        REQ_FLAG_GET_DATA_RANK = 1,
        REQ_FLAG_GET_DATA_CHARACTER_ID = 2,
        REQ_FLAG_GET_CLAN_MEMBER = 3,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CANCEL_FORCE = 68,
        INPUTEVENT_CHANGE_TYPE = 69,
        INPUTEVENT_PAGE = 70,
        INPUTEVENT_ADJUST_TAB = 71,
    };
public:
    class MyDTI;
    struct stList;
    class cListItem;
    struct stRanking;
    class cRankingItem;
    struct stMyRanking;
    class cListInfo;
    class cRankingInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
        cGUIInstNull* mpInstNull;  // offset: 0x58
        cGUIInstAnimation* mpInstAnim;  // offset: 0x60
        cGUIInstAnimation* mpInstAnimNewIcon;  // offset: 0x68
        cGUIObjNull* mpObjNullFocus;  // offset: 0x70
        cGUIObjMessage* mpObjMsgState;  // offset: 0x78
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x80
        cGUIObjMessage* mpObjMsgPeriod;  // offset: 0x88
        cGUIObjTexture* mpObjTexIcon;  // offset: 0x90
        static MyDTI DTI;
    };
public:
    class cRankingItem : public uGUIBase::cScrollListItemBase
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
        cRankingItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x58
        cGUIInstAnimation* mpInstAnim;  // offset: 0x60
        cGUIObjMessage* mpObjMsgName;  // offset: 0x68
        cGUIObjMessage* mpObjMsgClanName;  // offset: 0x70
        cGUIObjMessage* mpObjMsgRanking;  // offset: 0x78
        cGUIObjMessage* mpObjMsgRankingUnit;  // offset: 0x80
        cGUIObjMessage* mpObjMsgPt;  // offset: 0x88
        cGUIObjMessage* mpObjMsgPtUnit;  // offset: 0x90
        cGUIObjNull* mpObjNullSortRank;  // offset: 0x98
        cGUIObjMessage* mpObjMsgSortRank;  // offset: 0xa0
        cGUIObjTexture* mpObjTexIcon;  // offset: 0xa8
        cGUIObjTexture* mpObjTexBase;  // offset: 0xb0
        static MyDTI DTI;
    };
public:
    struct stMyRanking
    {
    public:
        stMyRanking();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjNull* mpObjNullMyRank;  // offset: 0x8
        cGUIObjMessage* mpObjMsgSortRank;  // offset: 0x10
        cGUIObjMessage* mpObjMsgRanking;  // offset: 0x18
        cGUIObjMessage* mpObjMsgRankingUnit;  // offset: 0x20
        cGUIObjMessage* mpObjMsgName;  // offset: 0x28
        cGUIObjMessage* mpObjMsgClanName;  // offset: 0x30
        cGUIObjMessage* mpObjMsgPt;  // offset: 0x38
        cGUIObjMessage* mpObjMsgPtUnit;  // offset: 0x40
        cGUIObjMessage* mpObjMsgPlInfo;  // offset: 0x48
        cGUIObjNull* mpObjNullState;  // offset: 0x50
        cGUIObjMessage* mpObjMsgState;  // offset: 0x58
        cGUIObjNull* mpObjNullNotJoin;  // offset: 0x60
        cGUIObjMessage* mpObjMsgNotJoin;  // offset: 0x68
        cGUIObjNull* mpObjNullLastcount;  // offset: 0x70
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
        u32 mBoardId;  // offset: 0x28
        u32 mQuestId;  // offset: 0x2c
        u8 mState;  // offset: 0x30
        u32 mRegisterdNum;  // offset: 0x34
        s64 mBeginTime;  // offset: 0x38
        s64 mEndTime;  // offset: 0x40
        s64 mExpireTime;  // offset: 0x48
        s64 mModifiedTime;  // offset: 0x50
        bool mIsLoadQuestName;  // offset: 0x58
        static MyDTI DTI;
    };
public:
    class cRankingInfo : public uGUIBase::cScrollListInfoBase
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
        cRankingInfo();
    public:
        s32 mRank;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstAnimation* mpInstAnimFrame;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x10
        cGUIObjMessage* mpObjMsgNotice;  // offset: 0x18
        cGUIObjPolygon* mpObjPolyMaskTop;  // offset: 0x20
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x28
        cGUIObjPolygon* mpObjPolyMaskBottom;  // offset: 0x30
        uGUIRankingBoard::cListItem mList[8];  // offset: 0x38
        uGUIBase::cScrollList mListCtrl;  // offset: 0x500
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x7b0
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x848
        MtVector2 mPointerPos;  // offset: 0x8a0
        f32 mListTop;  // offset: 0x8a8
        f32 mListOffset;  // offset: 0x8ac
        static const u32 list_num = 8;
    };
public:
    struct stRanking
    {
    public:
        stRanking();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimFrame;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x18
        cGUIObjMessage* mpObjMsgContentsTitle;  // offset: 0x20
        cGUIObjMessage* mpObjMsgPeriod;  // offset: 0x28
        cGUIObjMessage* mpObjMsgUpdate;  // offset: 0x30
        cGUIObjMessage* mpObjMsgNotice;  // offset: 0x38
        cGUIObjMessage* mpObjMsgRank;  // offset: 0x40
        cGUIObjMessage* mpObjMsgName;  // offset: 0x48
        cGUIObjMessage* mpObjMsgClan;  // offset: 0x50
        cGUIObjMessage* mpObjMsgPoint;  // offset: 0x58
        cGUIObjPolygon* mpObjPolyMaskTop;  // offset: 0x60
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x68
        cGUIObjPolygon* mpObjPolyMaskBottom;  // offset: 0x70
        uGUIRankingBoard::cRankingItem mList[14];  // offset: 0x78
        uGUIBase::cScrollList mListCtrl;  // offset: 0xa90
        uGUIBase::cReferenceUITab mTab;  // offset: 0xd40
        uGUIBase::cReferenceUINumPager mPage;  // offset: 0xdf0
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0xe98
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0xf30
        MtVector2 mPointerPos;  // offset: 0xf88
        u32 mDispTab;  // offset: 0xf90
        u32 mType;  // offset: 0xf94
        u32 mTotalNum;  // offset: 0xf98
        f32 mListTop;  // offset: 0xf9c
        f32 mListOffset;  // offset: 0xfa0
        u32 mQuestId;  // offset: 0xfa4
        bool mIsLoadQuestName;  // offset: 0xfa8
        static const u32 list_num = 14;
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
    uGUIRankingBoard();
    virtual ~uGUIRankingBoard();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setupRankingItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideRankingItem(uGUIBase::cScrollListItemBase* pItemBase);
private:
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupPointerDefaultPos();
    void createList();
    void setupList();
    void adjustListCursor();
    void decideList();
    void cancelList();
    void updateList();
    void setupRankBase();
    void setPlInfoPanel(u32 period, bool isJoin);
    void setupTimeStr(s64 in_time);
    void setupTimeStr(s64 in_begin, s64 in_end);
    void clearMyRankSpace();
    void createRank();
    void setupRank();
    void adjustRankCursor();
    void adjustRankTab();
    void decideRank();
    void cancelRank();
    void setupStatus();
    void updateQuestName();
    cListInfo* getListInfo(u32 index);
    cListInfo* getListInfo();
    cRankingInfo* getRankInfo(u32);
    cRankingInfo* getRankInfo();
    const CRankingData* getRankData(u32 index);
    const CRankingData* getMyRankData();
    bool isDispRanking();
    void changePage(u32 in_page);
    void changeTab(u32 in_tab);
    void changeType(u32 in_type);
    void resetList();
    bool isRequest(u32 flag);
    void setRequest(u32 flag);
    void clearRequest(u32 flag);
    bool isCompleteRequest();
    void requestServer();
    bool requestGetBoardList();
    void callbackGetBoardList();
    bool requestGetDataRank();
    void callbackGetDataRank();
    bool requestGetDataCharId();
    void callbackGetDataCharId();
    bool requestGetClanMember();
    void callbackGetClanMember();
    void eventDecide();
    void eventCancel();
    void eventCancelForce();
    void eventChangeType();
    void eventPage();
    void eventAdjustCursor();
    void eventAdjustTab();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlCancelForce(cControl::Message* msg);
    u32 evCtrlChangeType(cControl::Message* msg);
    u32 evCtrlPage(cControl::Message* msg);
    u32 evCtrlAdjustTab(cControl::Message*);
    void setCtrlFocus(cControl* pCtrl, bool isFocus);
    s32 getCtrlPos(cControl* pCtrl);
    s32 getCtrlLocate(uGUIBase::cVerticalList*);
    s32 getCtrlNum(cControl*);
    void setCtrlPos(cControl* pCtrl, s32 pos);
    void setObjFrame(cGUIObject* pObj, f32 frame);
    MT_CTSTR getMsg(u32);
    MT_CTSTR getCmnMsg(u32 index);
    void callPointer(u32);
private:
    MtVector2 mPointerPos;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    rGUIMessage* mpGMDRes;  // offset: 0x8d8
    cGUIInstNull* mpInstNull;  // offset: 0x8e0
    u32 mRequestFlag;  // offset: 0x8e8
    u32 mFlowId;  // offset: 0x8ec
    u32 mReqIndex;  // offset: 0x8f0
    u32 mReqPage;  // offset: 0x8f4
    u32 mReqTab;  // offset: 0x8f8
    u32 mReqType;  // offset: 0x8fc
    stList mList;  // offset: 0x900
    stRanking mRank;  // offset: 0x11b0
    stMyRanking mMyRank;  // offset: 0x2160
    cControl* mpDecideCtrl;  // offset: 0x21d8
    cControl* mpCancelCtrl;  // offset: 0x21e0
    cControl* mpTypeCtrl;  // offset: 0x21e8
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0x21f0
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x21f8
    MtStringEx<128> mTempStr;  // offset: 0x2200
    const RankingDataVec* mpRankList;  // offset: 0x2288
    const RankingDataVec* mpMyRankList;  // offset: 0x2290
    CommonU32Vec mCharIdList;  // offset: 0x2298
    bool mIsCompleteRequest;  // offset: 0x22b8
    bool mIsUpdateNextFrame;  // offset: 0x22b9
    bool mIsRankReq;  // offset: 0x22ba
    s32 mReqNo;  // offset: 0x22bc
    s32 mSaveRankPos;  // offset: 0x22c0
    u32 mSaveFlowId;  // offset: 0x22c4
    t64 mLastUpdateTime;  // offset: 0x22c8
public:
    static MyDTI DTI;
};

inline void* uGUIRankingBoard::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool uGUIRankingBoard::isCompleteRequest() {
    return this->mIsCompleteRequest;
}

inline void* uGUIRankingBoard::cListItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIRankingBoard::cListItem::cListItem() {
    this->mpObjTexIcon = nullptr;
    this->mpObjMsgPeriod = nullptr;
    this->mpObjMsgTitle = nullptr;
    this->mpObjMsgState = nullptr;
    this->mpObjNullFocus = nullptr;
    this->mpInstAnimNewIcon = nullptr;
    this->mpInstAnim = nullptr;
    this->mpInstNull = nullptr;
}

inline void* uGUIRankingBoard::cRankingItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIRankingBoard::cRankingItem::cRankingItem() {
    this->mpObjTexBase = nullptr;
    this->mpObjTexIcon = nullptr;
    this->mpObjMsgSortRank = nullptr;
    this->mpObjNullSortRank = nullptr;
    this->mpObjMsgPtUnit = nullptr;
    this->mpObjMsgPt = nullptr;
    this->mpObjMsgRankingUnit = nullptr;
    this->mpObjMsgRanking = nullptr;
    this->mpObjMsgClanName = nullptr;
    this->mpObjMsgName = nullptr;
    this->mpInstAnim = nullptr;
    this->mpInstNull = nullptr;
}

inline uGUIRankingBoard::stMyRanking::stMyRanking() {
}

inline void* uGUIRankingBoard::cListInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIRankingBoard::cRankingInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
