#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "rItemList.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstAnimation;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjTexture;
class rGUI;
class rGUIMessage;
class rSoundRequest;

// Declarations
class uGUIBazaarDealSheet;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIBazaarDealSheet : public uGUIBase
{
public:
    enum
    {
        FLAG_TYPE_UPDATE_LIST = 0,
        FLAG_TYPE_MAX = 1,
    };
    enum
    {
        MENU_TAG_DEAL_START = 0,
        MENU_TAG_DEAL_00 = 0,
        MENU_TAG_DEAL_01 = 1,
        MENU_TAG_DEAL_02 = 2,
        MENU_TAG_DEAL_03 = 3,
        MENU_TAG_DEAL_04 = 4,
        MENU_TAG_DEAL_05 = 5,
        MENU_TAG_DEAL_06 = 6,
        MENU_TAG_DEAL_07 = 7,
        MENU_TAG_DEAL_08 = 8,
        MENU_TAG_DEAL_09 = 9,
        MENU_TAG_SALE = 10,
        MENU_TAG_NUM = 11,
    };
    enum
    {
        INPUT_EVENT_DECIDE = 66,
        INPUT_EVENT_CANCEL = 67,
        INPUT_EVENT_EXHIBIT = 68,
        INPUT_EVENT_PAGE = 69,
        INPUT_EVENT_LIST_CURSOR = 70,
        INPUT_EVENT_SHORTCUT = 71,
        INPUT_EVENT_SALE_TOUCH_DECIDE = 72,
    };
public:
    class MyDTI;
    class cDealData;
    class cListData;
public:
    typedef struct
    {
    public:
        u8 mGmdIdx;  // offset: 0x0
        u8 mTag;  // offset: 0x1
    } CATEGORY_DATA;
public:
    using cFlag = nDDOUtility::cBitSet<1>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cDealData : public MtObject
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
        cDealData();
        virtual ~cDealData();
    public:
        cGUIInstance* mpInstDealNull;  // offset: 0x8
        uGUIBase::cReferenceUIIconItem mItemIcon;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimDealList;  // offset: 0x190
        cGUIObjNull* mpObjNullItem;  // offset: 0x198
        cGUIObjMessage* mpObjMsgName;  // offset: 0x1a0
        cGUIObjMessage* mpObjMsgCate;  // offset: 0x1a8
        cGUIObjMessage* mpObjMsgDate;  // offset: 0x1b0
        cGUIObjNull* mpObjNullSale;  // offset: 0x1b8
        cGUIObjMessage* mpObjMsgSaleTxt;  // offset: 0x1c0
        cGUIObjMessage* mpObjMsgSaleNum;  // offset: 0x1c8
        cGUIObjMessage* mpObjMsgGoldNum;  // offset: 0x1d0
        cGUIObjMessage* mpObjMsgGoldG;  // offset: 0x1d8
        cGUIObjNull* mpObjNullInfo;  // offset: 0x1e0
        cGUIObjMessage* mpObjMsgInfoTxt;  // offset: 0x1e8
        cGUIObjNull* mpObjNullProfit;  // offset: 0x1f0
        cGUIObjMessage* mpObjMsgProfitTxt;  // offset: 0x1f8
        cGUIObjNull* mpObjNullProfitNum;  // offset: 0x200
        cGUIObjMessage* mpObjMsgProfitNum;  // offset: 0x208
        cGUIObjMessage* mpObjMsgProfitNumG;  // offset: 0x210
        cGUIObjTexture* mpObjTexIcon;  // offset: 0x218
        cGUIObjNull* mpObjNullPointer;  // offset: 0x220
        u32 mTag;  // offset: 0x228
        static MyDTI DTI;
    };
public:
    class cListData : public MtObject
    {
    public:
        enum
        {
            STATE_EXHIBIT = 0,
            STATE_TIMEOVER = 1,
            STATE_PROCEEDS = 2,
            STATE_LOCK = 3,
            STATE_NONE = 4,
        };
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
        cListData();
        virtual ~cListData() {}
    public:
        u32 mId;  // offset: 0x8
        u8 mState;  // offset: 0xc
        u8 mSortState;  // offset: 0xd
        static MyDTI DTI;
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
    uGUIBazaarDealSheet();
    virtual ~uGUIBazaarDealSheet();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void move();  // vtable slot 9
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void begin();
    void hide();
    void stay();
    bool isBegin() const;
    bool isCancel() const;
    bool isDecide() const;
    u32 getSelectNo();
    u32 getSelectTag();
    s32 getSelectBazaarListIdx();
    f32 getSelHSize();
    void createMenuTag();
    bool isSMenuShortCut() const;
    bool sortByCustomSort(const cListData* src, const cListData* dst, u32 param);
protected:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
private:
    void updateInit();
    void updateMove();
    void updateWait();
    void initialize();
    u32 evCtrlSelectMenu(cControl::Message* msg);
    u32 evCtrlDecideMenu(cControl::Message* msg);
    u32 evCtrlCancelMenu(cControl::Message* msg);
    u32 evCtrlShortCut(cControl::Message* msg);
    u32 evCtrlSelectPage(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    void updateDealList();
    u8 getGmdToCategory(rItemList::rItemParam* prItemParam);
    void setDateColor(cGUIObjMessage* pObj, u8 color);
    void setPointerPos();
    u32 getCharListDataMax();
    void resetMenuCtrl();
    void eventDecide();
    void eventListCursor();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rSoundRequest* mpSNDRes;  // offset: 0x8d8
    bool mIsBegin;  // offset: 0x8e0
    cGUIObjMessage* mpObjMsgTop00;  // offset: 0x8e8
    cGUIObjMessage* mpObjMsgTop01;  // offset: 0x8f0
    cGUIObjMessage* mpObjMsgStatusTotalSaleTxt;  // offset: 0x8f8
    cGUIObjMessage* mpObjMsgStatusTotalSaleNum;  // offset: 0x900
    cGUIObjMessage* mpObjMsgStatusTotalSaleG;  // offset: 0x908
    cGUIObjMessage* mpObjMsgStatusDealTxt;  // offset: 0x910
    cGUIObjMessage* mpObjMsgStatusDealNum;  // offset: 0x918
    cDealData mDealData[5];  // offset: 0x920
    MtColor mBaseTimeColor;  // offset: 0x1410
    uGUIBase::cReferenceUIButton2 mSaleBtn;  // offset: 0x1418
    uGUIBase::cReferenceUINumPager mNumPageBtn;  // offset: 0x15a8
    uGUIBase::cReferenceUIBtnGuide mButtonGuide;  // offset: 0x1650
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0x16e8
    uGUIBase::cVerticalList* mpMenuCtrl;  // offset: 0x1740
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0x1748
    u32 mCurrentOld;  // offset: 0x1750
    f32 mSelCursorH;  // offset: 0x1754
    u32 mPageOld;  // offset: 0x1758
    cFlag mFlag;  // offset: 0x175c
    u32 mTagList[6];  // offset: 0x1760
    bool mIsShortCut;  // offset: 0x1778
    u32 mListDataMax;  // offset: 0x177c
    bool mIsCancel;  // offset: 0x1780
    bool mIsDecide;  // offset: 0x1781
public:
    static MyDTI DTI;
    static const CATEGORY_DATA mCategoryMsg[];
};

inline void* uGUIBazaarDealSheet::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool uGUIBazaarDealSheet::isBegin() const {
    return this->mIsBegin;
}

inline f32 uGUIBazaarDealSheet::getSelHSize() {
    return this->mSelCursorH;
}

inline void* uGUIBazaarDealSheet::cDealData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIBazaarDealSheet::cDealData::~cDealData() {
}

inline void* uGUIBazaarDealSheet::cListData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIBazaarDealSheet::cListData::cListData() {
    this->mId = 0;
    this->mState = 0;
    this->mSortState = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIBazaarDealSheet::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarDealSheet::DTI);
}

inline void uGUIBazaarDealSheet::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarDealSheet::DTI)->memFree(p_addr);
}

inline void* uGUIBazaarDealSheet::cDealData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarDealSheet::cDealData::DTI)->memAlloc(sz, align, ::uGUIBazaarDealSheet::cDealData::DTI.::MtDTI::getID());
}

inline void uGUIBazaarDealSheet::cDealData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarDealSheet::cDealData::DTI)->memFree(p_addr);
}

inline void* uGUIBazaarDealSheet::cListData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarDealSheet::cListData::DTI)->memAlloc(sz, align, ::uGUIBazaarDealSheet::cListData::DTI.::MtDTI::getID());
}

inline void uGUIBazaarDealSheet::cListData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarDealSheet::cListData::DTI)->memFree(p_addr);
}
