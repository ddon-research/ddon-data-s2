#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/Item.h"
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/cControl.h"
#include "../shared/nCharacterData.h"
#include "../shared/sItemManager.h"
#include "../shared/uGUIBase.h"
#include "uGUIUseItemBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtSize;
class MtVector4;
class cArcLoaderBase;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
namespace nGUIItem { class cItem; }
class rGUI;
class uGUIItemIcon;
class uGUIPopCmd01;

// Declarations
class uGUIItemBase01;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIItemBase01 : public uGUIUseItemBase
{
public:
    enum CHECK_MODE_STATE
    {
        CHECK_MODE_STATE_NONE = 0,
        CHECK_MODE_STATE_ALL = 1,
        CHECK_MODE_STATE_ALL_CLEAR = 2,
    };
    enum STORAGE_COURSE_STATE
    {
        STORAGE_COURSE_STATE_NONE = 0,
        STORAGE_COURSE_STATE_UNKNOWN = 1,
        STORAGE_COURSE_STATE_UNUSE = 2,
        STORAGE_COURSE_STATE_USE = 3,
    };
    enum
    {
        CF_ITEM = 0,
        CF_VLIST = 1,
    };
    enum SW
    {
        SW_ITEM = 0,
        SW_KEY_ITEM = 1,
        SW_STORAGE = 2,
        SW_DELIVERY = 3,
        SW_CHEST = 4,
    };
    enum
    {
        PUT_CHECK_BIT_CATEGORY = 0,
        PUT_CHECK_BIT_NUM = 1,
        PUT_CHECK_BIT_SPACE = 2,
        PUT_CHECK_BIT_WEAPON = 3,
        PUT_CHECK_BIT_SAME = 4,
        PUT_CHECK_BIT_POST = 5,
        PUT_CHECK_BIT_MAX = 6,
    };
    enum
    {
        INPUT_EVENT_BASE_CATCH = 66,
        INPUT_EVENT_BASE_CATCH_RELEASE = 67,
        INPUT_EVENT_BASE_SUBMENU = 68,
        INPUT_EVENT_BASE_CHECK_MODE = 69,
        INPUT_EVENT_BASE_CHECK_MODE_CLEAR = 70,
        INPUT_EVENT_BASE_CHECK_MODE_ALL = 71,
        INPUT_EVENT_BASE_CURSOR_MOVE = 72,
        INPUT_EVENT_BASE_END = 73,
    };
public:
    class MyDTI;
    struct cData;
    class cGUIItem;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct cData
    {
    public:
        cGUIObjMessage* mpOBJ_msg_item_m_item;  // offset: 0x0
        cGUIInstNull* mpINST_Null;  // offset: 0x8
        cGUIObjMessage* mpOBJ_msg_top_m_top00;  // offset: 0x10
        cGUIObjMessage* mpOBJ_msg_top_m_top01;  // offset: 0x18
        cGUIObjMessage* mpOBJ_msg_skip_l_m_skip01;  // offset: 0x20
        cGUIObjMessage* mpOBJ_msg_skip_r_m_skip01;  // offset: 0x28
        cGUIInstAnimation* mpINST_fix_window;  // offset: 0x30
        cGUIInstAnimation* mpINST_fix_item_frame;  // offset: 0x38
        cGUIInstAnimation* mpINST_window_frame;  // offset: 0x40
        cGUIInstNull* mpINST_Null_under;  // offset: 0x48
        cGUIInstNull* mpINST_Null_item;  // offset: 0x50
        cGUIInstNull* mpINST_Null_detail00;  // offset: 0x58
        cGUIInstNull* mpINST_Null_detail01;  // offset: 0x60
        cGUIInstNull* mpINST_Null_popnumber;  // offset: 0x68
        cGUIInstNull* mpINST_Null_popsell;  // offset: 0x70
        cGUIInstNull* mpINST_Null_itemwindow;  // offset: 0x78
    };
public:
    class cGUIItem : public MtObject
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
        cGUIItem();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpINST_icon_shortcut;  // offset: 0x30
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x40
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
    uGUIItemBase01(u32 initFlags);
    virtual ~uGUIItemBase01();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void adjustScale();  // vtable slot 84
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual void setStopAllContol(bool b);  // vtable slot 66
    void setTabIdx(s32 idx);
    s32 getTabIdx();
    nGUIItem::cItem* getSelectItem();
    virtual void refresh();  // vtable slot 131
    void setIsDetailCreate(bool b);
    void setStorageType(nCharacterData::ITEM_BAG_TYPE bagType);
    nCharacterData::ITEM_BAG_TYPE getStorageType();
    void setPutItem(nGUIItem::cItem* pCatchItem, bool isTogle);
    void checkAddStackNumCore(sItemManager::cItemBag* pBag, nCharacterData::ITEM_BAG_TYPE type, nGUIItem::cItem* pItem, u32* pAddNum, s32* pMsg, s32* pSlotNo);
    void checkAddStackNum(nCharacterData::ITEM_BAG_TYPE type, nGUIItem::cItem* pItem, u32* pAddNum, s32* pMsg, s32* pSlotNo);
    void checkAddStackNum(nItem::E_STORAGE_TYPE serverStorage, nGUIItem::cItem* pItem, u32* pAddNum, s32* pMsg, s32* pSlotNo);
    void checkAddMaxNumCore(sItemManager::cItemBag* pBag, nGUIItem::cItem* pItem, u32* pAddNum, s32* pMsg);
    void checkAddMaxNum(nCharacterData::ITEM_BAG_TYPE type, nGUIItem::cItem* pItem, u32* pAddNum, s32* pMsg);
    void checkAddMaxNum(nItem::E_STORAGE_TYPE type, nGUIItem::cItem* pItem, u32* pAddNum, s32* pMsg);
    void checkAddListMaxNumCore(sItemManager::cItemBag* pBag, MtTypedArray<nGUIItem::cItem>* pItemList, s32* pMsg);
    void checkAddListMaxNum(nCharacterData::ITEM_BAG_TYPE type, MtTypedArray<nGUIItem::cItem>* pItemList, s32* pMsg);
    void checkAddListMaxNum(nItem::E_STORAGE_TYPE serverStorage, MtTypedArray<nGUIItem::cItem>* pItemList, s32* pMsg);
    void setPutItemCore(nGUIItem::cItem* pCatchItem, u32 checkBit);
    bool isCategoryCheck(nItem::E_STORAGE_TYPE catchType, nItem::E_STORAGE_TYPE baseType);
    void resetPutItem();
    void catchCancel(bool isSe);
    virtual void setFlowId(u32 flowId);  // vtable slot 124
    bool isCheckMode();
    void setCheckMode(bool checkMode);
    bool isMouseMode();
    CHECK_MODE_STATE isCheckModeAll();
    CHECK_MODE_STATE isCheckModeAllCore(u32 start, u32 num);
    STORAGE_COURSE_STATE getStorageCourse(nItem::E_STORAGE_TYPE groupType);
    bool isOnlineShopStart();
    bool isDisablePlStatusCore(nGUIItem::cItem* pItem);
    bool isDisablePlStatus(nGUIItem::cItem* pItem);
    virtual nItem::E_STORAGE_TYPE getServerStorageType();  // vtable slot 132
    u32 evSortBest(MtObject* pCaller, MtObject* pData);
    u32 evSortSellUp(MtObject* pCaller, MtObject* pData);
    u32 evSortSellDown(MtObject* pCaller, MtObject* pData);
    u32 evSortSellName(MtObject* pCaller, MtObject* pData);
    u32 evSortMaterialPri(MtObject* pCaller, MtObject* pData);
    u32 evSortWeaponPri(MtObject* pCaller, MtObject* pData);
    u32 evSell(MtObject* pCaller, MtObject* pData);
    u32 evSellsFromBag(MtObject* pCaller, MtObject* pData);
    u32 evSellsFromBox(MtObject* pCaller, MtObject* pData);
    u32 evSellsFromExBox(MtObject* pCaller, MtObject* pData);
    u32 evMoveItem(MtObject* pCaller, MtObject* pData);
    u32 evMultiDiscard(MtObject* pCaller, MtObject* pData);
    u32 evUse(MtObject* pCaller, MtObject* pData);
    u32 evDiscard(MtObject* pCaller, MtObject* pData);
    u32 evDiscardsFromBag(MtObject* pCaller, MtObject* pData);
    u32 evDiscardsFromBox(MtObject* pCaller, MtObject* pData);
    u32 evDiscardsFromExBox(MtObject* pCaller, MtObject* pData);
    u32 evCatch(MtObject* pCaller, MtObject* pData);
    u32 evThrow(MtObject* pCaller, MtObject* pData);
    u32 evExChange(MtObject* pCaller, MtObject* pData);
    u32 evSend(MtObject* pCaller, MtObject* pData);
    u32 evSendNum(MtObject*, MtObject*);
    virtual u32 _evSend(MtObject* pCaller, MtObject* pData, bool isUseNumBox, bool isAllNum);  // vtable slot 133
    u32 evSendBag(MtObject* pCaller, MtObject* pData);
    u32 evSendsBag(MtObject* pCaller, MtObject* pData);
    u32 evSendsBagFromBox(MtObject* pCaller, MtObject* pData);
    u32 evSendsBagFromExBox(MtObject* pCaller, MtObject* pData);
    u32 evSendsBagFromBaggageFree(MtObject* pCaller, MtObject* pData);
    u32 evSendsBagFromBaggageRental00(MtObject* pCaller, MtObject* pData);
    u32 evSendNumBag(MtObject* pCaller, MtObject* pData);
    u32 evSendBox(MtObject* pCaller, MtObject* pData);
    u32 evSendsBox(MtObject* pCaller, MtObject* pData);
    u32 evSendsBoxFromBag(MtObject* pCaller, MtObject* pData);
    u32 evSendsBoxFromExBox(MtObject* pCaller, MtObject* pData);
    u32 evSendNumBox(MtObject* pCaller, MtObject* pData);
    u32 evSendEx(MtObject* pCaller, MtObject* pData);
    u32 evSendsEx(MtObject* pCaller, MtObject* pData);
    u32 evSendsExFromBag(MtObject* pCaller, MtObject* pData);
    u32 evSendsExFromBox(MtObject* pCaller, MtObject* pData);
    u32 evSendNumEx(MtObject* pCaller, MtObject* pData);
    u32 evSendBaggage(MtObject* pCaller, MtObject* pData);
    u32 evSendsBaggage(MtObject* pCaller, MtObject* pData);
    u32 evSendsBaggageFreeFromBag(MtObject* pCaller, MtObject* pData);
    u32 evSendsBaggageRental00FromBag(MtObject* pCaller, MtObject* pData);
    u32 evSendNumBaggageFree(MtObject* pCaller, MtObject* pData);
    u32 evSendNumBaggageRental00(MtObject* pCaller, MtObject* pData);
    u32 evSortMenu(MtObject* pCaller, MtObject* pData);
    u32 evOnlineShop(MtObject* pCaller, MtObject* pData);
    virtual void setExchangeCtrl(bool b);  // vtable slot 122
    virtual void setExeCtrl(bool b);  // vtable slot 123
    virtual void setMouseTouchCtrl(bool b);  // vtable slot 134
    virtual u32 evCheckModeClear(cControl::Message* msg);  // vtable slot 135
    void setCtrlFocus(u32 focusType);
protected:
    virtual bool isUpdateItemCBF();  // vtable slot 136
    virtual bool isMatrixHeightLimitOver();  // vtable slot 137
    void setupItem(cGUIItem* pItem, cGUIInstNull* pInst);
    // Address: 0x01ae0330 - 0x01ae0331 (1 bytes)
    virtual void createPopCmd(uGUIPopCmd01* p, nGUIItem::cItem* pItem) {}  // vtable slot 138
    // Address: 0x01af32d0 - 0x01af32d1 (1 bytes)
    virtual void loadItem() {}  // vtable slot 139
    virtual void setRow(s32 idx);  // vtable slot 140
    // Address: 0x01af3350 - 0x01af3351 (1 bytes)
    virtual void setTitle() {}  // vtable slot 141
    void setTitleCore(MT_CTSTR title1, MT_CTSTR title2);
    virtual void execCatchFunc();  // vtable slot 142
    virtual bool exchangeStorageCatchItem();  // vtable slot 143
    virtual bool exchangeCatchItem(nItem::E_STORAGE_TYPE* pTargetType, nItem::E_STORAGE_TYPE* pBaseType);  // vtable slot 144
    virtual void createVlistCtrl();  // vtable slot 145
    virtual void evCancelFunc(cControl::Message* msg);  // vtable slot 146
    MT_CTSTR getGMDParam(u32 id);
    virtual void updateInit();  // vtable slot 93
    virtual void updateWait();  // vtable slot 112
    virtual void updateWaitServer();  // vtable slot 116
    virtual void updateMoveItem();  // vtable slot 147
    virtual void updateWaitSort();  // vtable slot 148
    virtual void updateWaitPopup();  // vtable slot 114
    virtual void updateShareWaitPopup();  // vtable slot 115
    virtual void updateOnlineShop();  // vtable slot 118
    virtual void updateOnlineShopWait();  // vtable slot 119
    virtual void settingItemInit();  // vtable slot 149
    virtual void settingItem(bool isEnableGuide, bool isSetting);  // vtable slot 150
    virtual void updateDetail();  // vtable slot 151
    virtual void executeCtrl();  // vtable slot 152
    virtual bool isExecuteDecide();  // vtable slot 153
    virtual void moveMousePointerCtrl(bool isEnableGuide);  // vtable slot 154
    virtual bool subMenuItemSetting(MtObject* p);  // vtable slot 155
    virtual bool subMenuItemsSetting(MtObject* p);  // vtable slot 156
    virtual bool subMenuItemSpaceSetting(MtObject* p);  // vtable slot 157
    virtual void subMenuItemStorageBagSetting(uGUIPopCmd01* pSubMenu, bool isList, MtObject* pData);  // vtable slot 158
    virtual void subMenuItemStorageBoxSetting(uGUIPopCmd01* pSubMenu, bool isList, MtObject* pData, nCharacterData::ITEM_BAG_TYPE type);  // vtable slot 159
    virtual void subMenuItemStorageExBoxSetting(uGUIPopCmd01* pSubMenu, bool isList, MtObject* pData);  // vtable slot 160
    virtual void subMenuItemExBoxSetting(uGUIPopCmd01* pSubMenu, bool isList, MtObject* pData, nCharacterData::ITEM_BAG_TYPE type);  // vtable slot 161
    virtual void subMenuItemBagSetting(uGUIPopCmd01* pSubMenu, bool isList, MtObject* pData, nCharacterData::ITEM_BAG_TYPE type);  // vtable slot 162
    virtual void subMenuItemBaggageSetting(uGUIPopCmd01* pSubMenu, bool isList, MtObject* pData, nCharacterData::ITEM_BAG_TYPE targetType);  // vtable slot 163
    virtual sItemManager::cItemBag::ITEM_CATEGORY getTab2Category();  // vtable slot 164
    virtual s32 getCategory2TabIdx(sItemManager::cItemBag::ITEM_CATEGORY category);  // vtable slot 165
    u32 getStartIndex();
    s32 getSelectIdx();
    virtual u32 getItemDrawNum();  // vtable slot 166
    virtual u32 getItemMaxDrawNum();  // vtable slot 167
    virtual u32 getRowNum();  // vtable slot 168
    // Address: 0x01af3370 - 0x01af3371 (1 bytes)
    virtual void setupGuideBtn() {}  // vtable slot 169
    // Address: 0x01af3380 - 0x01af3381 (1 bytes)
    virtual void setGuideBtn() {}  // vtable slot 170
    // Address: 0x01ae0390 - 0x01ae0391 (1 bytes)
    virtual void setWindowMouseOver() {}  // vtable slot 171
    virtual bool getVListChange();  // vtable slot 172
    virtual u32 evCtrlMove(cControl::Message* msg);  // vtable slot 173
    virtual u32 evCtrlMouseOut(cControl::Message* msg);  // vtable slot 174
    virtual u32 evCtrlLBRB(cControl::Message* msg);  // vtable slot 175
    virtual u32 evCtrlSubWindow(cControl::Message* msg);  // vtable slot 176
    virtual u32 evCtrlCheckMode(cControl::Message* msg);  // vtable slot 177
    virtual u32 evCtrlCatch(cControl::Message* msg);  // vtable slot 178
    virtual u32 evCtrlDecide(cControl::Message* msg);  // vtable slot 179
    virtual u32 evCtrlCancel(cControl::Message* msg);  // vtable slot 180
    virtual u32 evCtrlChangeBox(cControl::Message* msg);  // vtable slot 181
    virtual u32 evCtrlStart(cControl::Message* msg);  // vtable slot 182
    virtual u32 evCtrlMoveFocusCtrl(cControl::Message* msg);  // vtable slot 183
    virtual u32 evCtrlRelease(cControl::Message* msg);  // vtable slot 184
    virtual u32 evSubMenu(cControl::Message* msg);  // vtable slot 185
    virtual u32 evCheckMode(cControl::Message* msg);  // vtable slot 186
    virtual u32 evCheckModeAll(cControl::Message* msg);  // vtable slot 187
    u32 evCtrlDrag(cControl::Message* msg);
    u32 evCtrlDrop(cControl::Message* msg);
protected:
    cData mData;  // offset: 0xc38
    rGUI* mpGUIRes;  // offset: 0xcb8
    MtVector4 mDefaultUnderPos;  // offset: 0xcc0
    s32 mRow;  // offset: 0xcd0
    s32 mPageTabNo;  // offset: 0xcd4
    MtSize mItemSpaceSize;  // offset: 0xcd8
    nCharacterData::ITEM_BAG_TYPE mStorageType;  // offset: 0xce0
    nItem::E_STORAGE_TYPE mServerStorageType;  // offset: 0xce4
    nItem::E_STORAGE_TYPE mServerStorageTypeOld;  // offset: 0xce8
    uGUIItemIcon* mpUnitIcon;  // offset: 0xcf0
    MtTypedArray<cGUIItem> mGUIItems;  // offset: 0xcf8
    bool mIsCatchMode;  // offset: 0xd18
    bool mIsDetailCreate;  // offset: 0xd19
    bool mIsDetailVisibleFirst;  // offset: 0xd1a
    bool mIsMouseOverPermit;  // offset: 0xd1b
    bool mIsMouseOver;  // offset: 0xd1c
    bool mIsOnlineShopStart;  // offset: 0xd1d
    bool mCheckMode;  // offset: 0xd1e
    uGUIBase::cReferenceUITab mTab;  // offset: 0xd20
    uGUIBase::cReferenceUIBtnGuide mButtonGuide;  // offset: 0xdd0
    uGUIBase::cReferenceUIBtnGuide mButtonGuide2;  // offset: 0xe68
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0xf00
    TICKET mTicket;  // offset: 0xf58
    cControl* mpCtrlButton;  // offset: 0xf60
    uGUIBase::cVerticalList* mpCtrlV;  // offset: 0xf68
    uGUIBase::cHorizontalList* mpCtrlH;  // offset: 0xf70
    uGUIBase::cMatrix* mpCtrlMatrix;  // offset: 0xf78
    uGUIBase::cHorizontalList* mpCtrlTab;  // offset: 0xf80
    s32 mMatrixSelPos;  // offset: 0xf88
    u32 mCtrlFocus;  // offset: 0xf8c
    u32 mCtrlFocusOld;  // offset: 0xf90
public:
    static MyDTI DTI;
    static const u32 DEFAULT_COL = 5;
    static const u32 MAX_PAGE = 2;
    static const u32 MAX_ITEM_NUM = 40;
};

// Inline, no code of its own: checked where it is inlined.
inline bool uGUIItemBase01::isCheckMode() {
    return this->mCheckMode;
}
