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
#include "sBazaarManager.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector2;
class MtVector3;
class cGUIInstAnimation;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjPolygon;
class rGUI;
class rGUIMessage;
class uGUIPopDetail01;

// Declarations
class uGUIBazaarItemSearch;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIBazaarItemSearch : public uGUIBase
{
public:
    enum BIS_GUIDE_BIT
    {
        BIS_INP_NUM = 1,
        BIS_BIT_MAX = 1,
    };
    enum
    {
        CATEGORY_BIG_TAG_1 = 0,
        CATEGORY_BIG_TAG_2 = 1,
        CATEGORY_BIG_TAG_3 = 2,
        CATEGORY_BIG_TAG_4 = 3,
        CATEGORY_BIG_TAG_5 = 4,
        CATEGORY_BIG_TAG_6 = 5,
        CATEGORY_BIG_TAG_7 = 6,
        CATEGORY_BIG_TAG_8 = 7,
        CATEGORY_BIG_TAG_NUM = 8,
    };
    enum
    {
        CATEGORY_TAG_BIG = 0,
        CATEGORY_TAG_SMALL = 1,
        CATEGORY_TAG_NUM = 2,
    };
    enum
    {
        MENU_TAG_CATEGORY = 0,
        MENU_TAG_RANK = 1,
        MENU_TAG_CATEGORY_SEARCH = 2,
        MENU_TAG_FREEWORD = 3,
        MENU_TAG_FREEWORD_SEARCH = 4,
        MENU_TAG_NUM = 5,
    };
    enum
    {
        INPUT_EVENT_DECIDE = 66,
        INPUT_EVENT_CANCEL = 67,
        INPUT_EVENT_MENU_SEL = 68,
        INPUT_EVENT_SELECT_PAGE = 69,
        INPUT_EVENT_SEARCH = 70,
        INPUT_EVENT_SELECT_RANK_LEFT = 71,
        INPUT_EVENT_SELECT_RANK_RIGHT = 72,
        INPUT_EVENT_SELECT_RANK = 73,
        INPUT_EVENT_ITEM_SELECT = 74,
        INPUT_EVENT_RANK_DIRECT = 75,
        INPUT_EVENT_RANK_DIRECT_MOUSE = 76,
    };
    enum SORT_DIR
    {
        DEC_DIR = 0,
        INC_DIR = 1,
    };
public:
    class MyDTI;
    class cItemData;
    class cCategoryBigData;
    class cCategoryData;
    struct KEYWORD;
    class cSearchItemData;
public:
    typedef struct
    {
    public:
        s8 mCategoryNum;  // offset: 0x0
        const u8* mpCategorys;  // offset: 0x8
    } CATEGORYS;
public:
    typedef struct
    {
    public:
        u8 mGmdIdx;  // offset: 0x0
        const uGUIBazaarItemSearch::CATEGORYS* mpTags;  // offset: 0x8
    } CATEGORY_DATA;
public:
    typedef struct
    {
    public:
        u8 mGmdIdx;  // offset: 0x0
        u8 mTag;  // offset: 0x1
        s8 mTableNum;  // offset: 0x2
        const uGUIBazaarItemSearch::CATEGORY_DATA* mpTable;  // offset: 0x8
    } CATEGORY_BIG_DATA;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cItemData : public MtObject
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
        cItemData();
        virtual ~cItemData();
    public:
        uGUIBase::cReferenceUIIconItem mItemIcon;  // offset: 0x10
        cGUIInstance* mpInstItemData;  // offset: 0x190
        cGUIInstAnimation* mpInstAnimMsgList;  // offset: 0x198
        cGUIObjMessage* mpObjMsgItemName;  // offset: 0x1a0
        cGUIObjMessage* mpObjMsgItemNum;  // offset: 0x1a8
        cGUIObjPolygon* mpObjMouseOver;  // offset: 0x1b0
        static MyDTI DTI;
    };
public:
    class cCategoryData : public MtObject
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
    public:
        MtString mStr;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    struct KEYWORD
    {
    public:
        MT_CTSTR key;  // offset: 0x0
        bool bNot;  // offset: 0x8
        bool bOr;  // offset: 0x9
    };
public:
    class cSearchItemData : public MtObject
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
        cSearchItemData();
        cSearchItemData(u32 itemNo, u32 sortNo);
        virtual ~cSearchItemData() {}
    public:
        u32 mItemNo;  // offset: 0x8
        u32 mSortNo;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cCategoryBigData : public MtObject
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
        cCategoryBigData();
        virtual ~cCategoryBigData();
    public:
        MtString mStr;  // offset: 0x8
        u8 mMsgIdx;  // offset: 0x10
        u8 mTag;  // offset: 0x11
        MtTypedArray<uGUIBazaarItemSearch::cCategoryData> mData;  // offset: 0x18
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
    uGUIBazaarItemSearch();
    virtual ~uGUIBazaarItemSearch();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void move();  // vtable slot 9
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void begin();
    void hide();
    void stay();
    void beginList();
    bool isBegin() const;
    bool isCancel() const;
    bool isDecide() const;
    void setFocus(bool isFocus = false);
    u32 getSelectPos();
    u32 getSelectMainCategory();
    u32 getSelectSubCategory();
    void setDetailPos(MtVector3& pos);
    void setKeyword(MtString& keyword);
    MT_CTSTR getKeyword();
    void setFreeword(MtString& str);
    bool isFreewordMatch(MT_CTSTR src);
    bool sortByID(const cSearchItemData* src, const cSearchItemData* dst, u32 param);
protected:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual void adjustScale();  // vtable slot 84
private:
    void updateInit();
    void updateMove();
    void updateFreeWordWait();
    void updateSearch();
    void retSearchToMove();
    void updateWait();
    void initialize();
    u32 evCtrlSelectCategory(cControl::Message* msg);
    u32 evCtrlDecideCategory(cControl::Message* msg);
    u32 evCtrlSelectMenu(cControl::Message* msg);
    u32 evCtrlLRSelectMenu(cControl::Message* msg);
    u32 evCtrlDecideMenu(cControl::Message* msg);
    u32 evCtrlCancelMenu(cControl::Message* msg);
    u32 evCtrlSelectList(cControl::Message* msg);
    u32 evCtrlDecideList(cControl::Message* msg);
    u32 evCtrlCancelList(cControl::Message* msg);
    u32 evCtrlSelectPage(cControl::Message* msg);
    u32 evCtrlStartMenu(cControl::Message* msg);
    void evSelectPage();
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32);
    void setSmallCateMessage();
    u32 createItemList();
    void clearItemList();
    void setItem(u32 index, sBazaarManager::cBazaarItemListData* pListData);
    void clearItem(u32 index, sBazaarManager::cBazaarItemListData* pListData);
    void createItemDetail();
    void setItemDetail();
    bool createSearchItemList();
    bool strString(const char* s1, const char* s2);
    void updateItemIcon();
    void setPointerPos();
    void referenceFocusAllOff();
    void resetItemListNum(s32 listNum, s32 pos);
    void eventSelectRank();
    void eventRankDirect();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8d8
    cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x8e0
    cGUIObjMessage* mpObjMsgSearchHeader00;  // offset: 0x8e8
    cGUIObjMessage* mpObjMsgSearchHeader01;  // offset: 0x8f0
    cGUIObjMessage* mpObjMsgSubHeader00;  // offset: 0x8f8
    cGUIObjMessage* mpObjMsgSubHeader01;  // offset: 0x900
    cGUIObjMessage* mpObjMsgNumTxt;  // offset: 0x908
    cGUIObjMessage* mpObjMsgSearchAnnounce;  // offset: 0x910
    cGUIObjMessage* mpObjMsgSearchNum;  // offset: 0x918
    cGUIObjMessage* mpObjMsgSearchNumTxt;  // offset: 0x920
    cGUIInstance* mpItemListResultMsg;  // offset: 0x928
    uGUIBase::cReferenceUIVlCursor mItemSelCursor;  // offset: 0x930
    uGUIBase::cReferenceUIButton mCateSearchBtn;  // offset: 0x9e0
    uGUIBase::cReferenceUIButton mFreeSearchBtn;  // offset: 0xb70
    uGUIBase::cReferenceUINumPager mNumPageBtn;  // offset: 0xd00
    uGUIBase::cReferenceUIPullDown mCateBigPullDown;  // offset: 0xdb0
    uGUIBase::cReferenceUIPullDown mCateSmallPullDown;  // offset: 0x13c0
    s32 mBigPullDownSelOld;  // offset: 0x19d0
    uGUIBase::cReferenceUINumBox mNumBoxBtn;  // offset: 0x19d8
    uGUIBase::cReferenceUITextBox mTextBox;  // offset: 0x1af0
    cItemData mItemData[10];  // offset: 0x1c60
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x2de0
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0x2e78
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0x2ea0
    uGUIPopDetail01* mpItemDetail;  // offset: 0x2ef8
    uGUIBase::cHorizontalList* mpCategoryCtrl;  // offset: 0x2f00
    uGUIBase::cVerticalList* mpMenuCtrl;  // offset: 0x2f08
    uGUIBase::cVerticalList* mpItemListCtrl;  // offset: 0x2f10
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0x2f18
    uGUIBase::cHorizontalList* mpHnumboxCtrl;  // offset: 0x2f20
    bool mIsBegin;  // offset: 0x2f28
    bool mFocus;  // offset: 0x2f29
    bool mStay;  // offset: 0x2f2a
    cCategoryBigData mCategoryList[8];  // offset: 0x2f30
    s32 mListTopOld;  // offset: 0x30f0
    MtVector3 mDetailPos;  // offset: 0x3100
    MtString mFreeword;  // offset: 0x3110
    MT_CHAR mFreewordStr[16];  // offset: 0x3118
    u32 mFreewordNum;  // offset: 0x3128
    KEYWORD mKeyword[16];  // offset: 0x3130
    bool mIsCancel;  // offset: 0x3230
    bool mIsDecide;  // offset: 0x3231
    MtVector2 mPointerOfs;  // offset: 0x3238
    bool mIsSearchOver;  // offset: 0x3240
    u32 mMainCategoryIdx;  // offset: 0x3244
    u32 mSubCategoryIdx;  // offset: 0x3248
public:
    static MyDTI DTI;
    static const u32 CATEGORY_BIG_1_CATEGORY_SMALL_NUM = 6;
    static const u32 CATEGORY_BIG_2_CATEGORY_SMALL_NUM = 4;
    static const u32 CATEGORY_BIG_3_CATEGORY_SMALL_NUM = 7;
    static const u32 CATEGORY_BIG_4_CATEGORY_SMALL_NUM = 4;
    static const u32 CATEGORY_BIG_5_CATEGORY_SMALL_NUM = 4;
    static const u32 CATEGORY_BIG_6_CATEGORY_SMALL_NUM = 3;
    static const u32 CATEGORY_BIG_7_CATEGORY_SMALL_NUM = 3;
    static const u32 CATEGORY_BIG_8_CATEGORY_SMALL_NUM = 1;
    static const u32 mCategoryTag[];
    static const u32 mMenuTag[];
    static const u8 mMenuTag1None[];
    static const CATEGORYS mMenuTag1NoneCategorys[];
    static const u8 mMenuTag2None[];
    static const CATEGORYS mMenuTag2NoneCategorys[];
    static const u8 mMenuTag3None[];
    static const CATEGORYS mMenuTag3NoneCategorys[];
    static const u8 mMenuTag4None[];
    static const CATEGORYS mMenuTag4NoneCategorys[];
    static const u8 mMenuTag5None[];
    static const CATEGORYS mMenuTag5NoneCategorys[];
    static const u8 mMenuTag6None[];
    static const CATEGORYS mMenuTag6NoneCategorys[];
    static const u8 mMenuTag7None[];
    static const CATEGORYS mMenuTag7NoneCategorys[];
    static const u8 mMenuTag8None[];
    static const CATEGORYS mMenuTag8NoneCategorys[];
    static const u8 mMenuTagStone[];
    static const CATEGORYS mMenuTagStoneCategorys[];
    static const u8 mMenuTagMetal[];
    static const CATEGORYS mMenuTagMetalCategorys[];
    static const u8 mMenuTagSand[];
    static const CATEGORYS mMenuTagSandCategorys[];
    static const u8 mMenuTagJewel[];
    static const CATEGORYS mMenuTagJewelCategorys[];
    static const u8 mMenuTagLiquid[];
    static const CATEGORYS mMenuTagLiquidCategorys[];
    static const u8 mMenuTagGrass[];
    static const CATEGORYS mMenuTagGrassCategorys[];
    static const u8 mMenuTagMushroom[];
    static const CATEGORYS mMenuTagMushroomCategorys[];
    static const u8 mMenuTagWoodchip[];
    static const CATEGORYS mMenuTagWoodchipCategorys[];
    static const u8 mMenuTagBark[];
    static const CATEGORYS mMenuTagBarkCategorys[];
    static const u8 mMenuTagBone[];
    static const CATEGORYS mMenuTagBoneCategorys[];
    static const u8 mMenuTagFang[];
    static const CATEGORYS mMenuTagFangCategorys[];
    static const u8 mMenuTagHorn[];
    static const CATEGORYS mMenuTagHornCategorys[];
    static const u8 mMenuTagWing[];
    static const CATEGORYS mMenuTagWingCategorys[];
    static const u8 mMenuTagMeat[];
    static const CATEGORYS mMenuTagMeatCategorys[];
    static const u8 mMenuTagCloth[];
    static const CATEGORYS mMenuTagClothCategorys[];
    static const u8 mMenuTagThread[];
    static const CATEGORYS mMenuTagThreadCategorys[];
    static const u8 mMenuTagWool[];
    static const CATEGORYS mMenuTagWoolCategorys[];
    static const u8 mMenuTagBanderole[];
    static const CATEGORYS mMenuTagBanderoleCategorys[];
    static const u8 mMenuTagOther[];
    static const CATEGORYS mMenuTagOtherCategorys[];
    static const u8 mMenuTagColor[];
    static const CATEGORYS mMenuTagColorCategorys[];
    static const u8 mMenuTagElementWep[];
    static const CATEGORYS mMenuTagElementWepCategorys[];
    static const u8 mMenuTagElementArmor[];
    static const CATEGORYS mMenuTagElementArmorCategorys[];
    static const u8 mMenuTagSpecialWep[];
    static const CATEGORYS mMenuTagSpecialWepCategorys[];
    static const u8 mMenuTagSpecialArmor[];
    static const CATEGORYS mMenuTagSpecialArmorCategorys[];
    static const CATEGORY_DATA mMiniPulldownBigTag1Msg[];
    static const CATEGORY_DATA mMiniPulldownBigTag2Msg[];
    static const CATEGORY_DATA mMiniPulldownBigTag3Msg[];
    static const CATEGORY_DATA mMiniPulldownBigTag4Msg[];
    static const CATEGORY_DATA mMiniPulldownBigTag5Msg[];
    static const CATEGORY_DATA mMiniPulldownBigTag6Msg[];
    static const CATEGORY_DATA mMiniPulldownBigTag7Msg[];
    static const CATEGORY_DATA mMiniPulldownBigTag8Msg[];
    static const CATEGORY_BIG_DATA mBigPulldownMsg[];
    static const u32 mBigCategoryMenuList[];
    static const u32 ITEM_LIST_NUM = 10;
    static const u32 MAX_KEY_WORD = 16;
};

inline void* uGUIBazaarItemSearch::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 uGUIBazaarItemSearch::getSelectMainCategory() {
    return static_cast<u32>(this->mCateBigPullDown.mCursorIdx);
}

inline u32 uGUIBazaarItemSearch::getSelectSubCategory() {
    return static_cast<u32>(this->mCateSmallPullDown.mCursorIdx);
}

inline void* uGUIBazaarItemSearch::cItemData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIBazaarItemSearch::cItemData::cItemData() {
    this->mpObjMouseOver = nullptr;
    this->mpObjMsgItemNum = nullptr;
    this->mpObjMsgItemName = nullptr;
    this->mpInstAnimMsgList = nullptr;
    this->mpInstItemData = nullptr;
}

inline uGUIBazaarItemSearch::cItemData::~cItemData() {
}

inline void* uGUIBazaarItemSearch::cCategoryBigData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIBazaarItemSearch::cCategoryBigData::cCategoryBigData() {
    this->mData.::MtArray::mAutoDelete = true;
    this->mMsgIdx = 0;
    this->mTag = 0;
}

inline void* uGUIBazaarItemSearch::cCategoryData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIBazaarItemSearch::cSearchItemData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIBazaarItemSearch::cSearchItemData::cSearchItemData() {
    this->mItemNo = 0;
    this->mSortNo = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIBazaarItemSearch::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarItemSearch::DTI);
}

inline void uGUIBazaarItemSearch::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarItemSearch::DTI)->memFree(p_addr);
}

inline void uGUIBazaarItemSearch::setFocus(bool isFocus) {
    this->mFocus = false;
    this->mpItemListCtrl->setFocus(false);
    this->mpPageCtrl->setFocus(false);
}

inline void uGUIBazaarItemSearch::eventRankDirect() {
    this->mNumBoxBtn.::uGUIBase::cReferenceUINumBox::setMode(static_cast<uGUIBase::cReferenceUINumBox::MODE>(1));
    this->mpMenuCtrl->setFocus(false);
    this->mpHnumboxCtrl->setFocus(false);
    this->mpCategoryCtrl->setFocus(false);
}

inline void* uGUIBazaarItemSearch::cItemData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarItemSearch::cItemData::DTI)->memAlloc(sz, align, ::uGUIBazaarItemSearch::cItemData::DTI.::MtDTI::getID());
}

inline void uGUIBazaarItemSearch::cItemData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarItemSearch::cItemData::DTI)->memFree(p_addr);
}

inline void* uGUIBazaarItemSearch::cCategoryBigData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarItemSearch::cCategoryBigData::DTI)->memAlloc(sz, align, ::uGUIBazaarItemSearch::cCategoryBigData::DTI.::MtDTI::getID());
}

inline void uGUIBazaarItemSearch::cCategoryBigData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarItemSearch::cCategoryBigData::DTI)->memFree(p_addr);
}

inline void* uGUIBazaarItemSearch::cSearchItemData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarItemSearch::cSearchItemData::DTI)->memAlloc(sz, align, ::uGUIBazaarItemSearch::cSearchItemData::DTI.::MtDTI::getID());
}

inline void uGUIBazaarItemSearch::cSearchItemData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarItemSearch::cSearchItemData::DTI)->memFree(p_addr);
}
