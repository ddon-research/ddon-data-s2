#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "rItemList.h"
#include "sItemManager.h"
#include "uGUIBase.h"

// Forward declarations
class CDataStorageItemUIDList;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
class cUnit;
namespace nGUIItem { class cItem; }
class rGUI;
class rGUIMessage;
class uGUISystemMsg;

// Declarations
class uGUIShopBuy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using StorageItemUIDListVec = MtTypedArray<CDataStorageItemUIDList>;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class uGUIShopBuy : public uGUIBase
{
public:
    enum
    {
        MODE_NONE = 0,
        MODE_BUY = 1,
        MODE_SELL = 2,
        MODE_NUM = 3,
    };
    enum
    {
        BUTTON_POS_OK = 0,
        BUTTON_POS_NG = 1,
    };
    enum
    {
        LIST_V_BUY_MYBAG = 0,
        LIST_V_BUY_BOX = 1,
        LIST_V_BUY_BUTTON = 2,
        LIST_V_BUY_ALLNUM = 3,
        LIST_V_SELL_NUM = 0,
        LIST_V_SELL_BUTTON = 1,
        LIST_V_SELL_ALLNUM = 2,
    };
    enum
    {
        CLICK_OK = 0,
        CLICK_NG = 1,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_PUSH0_LARROW = 67,
        INPUTEVENT_PUSH0_RARROW = 68,
        INPUTEVENT_PUSH1_LARROW = 69,
        INPUTEVENT_PUSH1_RARROW = 70,
        INPUTEVENT_UPDATECURSOR = 71,
        INPUTEVENT_DECIDE = 72,
        INPUTEVENT_BUY = 73,
        INPUTEVENT_SELL = 74,
        INPUTEVENT_DENY = 75,
        INPUTEVENT_UPDATEDISP = 76,
        INPUTEVENT_STARTEDIT = 77,
    };
    enum SHOPB_GUIDE_BIT
    {
        SHOPB_INP_NUM = 1,
        SHOPB_BIT_MAX = 1,
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
    uGUIShopBuy();
    virtual ~uGUIShopBuy();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setupBuy(sItemManager::cShop::ShopType Type);
    void setupSell();
    void setInfoBuy(u32 GoodsIdx, const rItemList::rItemParam* pItem, u64 Price);
    void setInfoSell(const nGUIItem::cItem* pItemInfo);
    void setInfoSellEx(const nGUIItem::cItem* pItemInfo, u32 InitSellNum, u32 CursorPos);
    void setCallUnit(cUnit* pUnit);
    bool isActive();
    void setBOType();
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateWait();
    void updateExit();
    u32 evCtrlCancel(cControl::Message* pMsg);
    u32 evCtrlDecide(cControl::Message* pMsg);
    u32 evCtrlStartNumEdit(cControl::Message* pMsg);
    u32 evCtrlMouseClick(cControl::Message* pMsg);
    u32 evCtrlCursorUD(cControl::Message* pMsg);
    u32 evCtrlCursorLR(cControl::Message* pMsg);
    u32 evCtrlCursorLRBuy(cControl::Message* pMsg);
    u32 evCtrlCursorLRSell(cControl::Message* pMsg);
    void initCommon();
    void initBuy();
    void initSell();
    void updateMoney();
    void updateCursor();
    void setDecide();
    void setBuy();
    void setSell();
    void updateEnableOKButton();
    bool isLimitMoney();
    bool isLimitSellNum();
    void announceCallBack(void* pParam);
    void announceCallBack1(void* pParam);
    void dummyCallBack(void*);
    void sellCallBack(void*);
    void initParams();
    bool isMoveDialog();
    bool checkEnableUse();
    bool isEnableOKButton();
    u64 getMyMoney();
    u32 getBuyNumMax(u32 BagType);
    u32 getSellNumMax();
    bool isConditionItem();
    void initIcon();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    uGUIBase::cVerticalList* mpCtrl;  // offset: 0x8d8
    s32 mVerticalNum;  // offset: 0x8e0
    cUnit* mpCallUnit;  // offset: 0x8e8
    uGUISystemMsg* mpDialog;  // offset: 0x8f0
    u32 mMode;  // offset: 0x8f8
    bool mIsEditMode;  // offset: 0x8fc
    u32 mButtonCursorPos;  // offset: 0x900
    cGUIInstNull* mpRoot;  // offset: 0x908
    uGUIBase::cReferenceUIButton mButton0;  // offset: 0x910
    uGUIBase::cReferenceUIButton mButton1;  // offset: 0xaa0
    uGUIBase::cReferenceUINumBox mNumBox0;  // offset: 0xc30
    uGUIBase::cReferenceUINumBox mNumBox1;  // offset: 0xd48
    f32 mButtonSizeX;  // offset: 0xe60
    cGUIObjMessage* mpMessage;  // offset: 0xe68
    cGUIInstAnimation* mpNumBox0;  // offset: 0xe70
    cGUIInstAnimation* mpNumBox1;  // offset: 0xe78
    cGUIObjMessage* mpMoney;  // offset: 0xe80
    cGUIObjMessage* mpMonetaryUnit;  // offset: 0xe88
    cGUIObjTexture* mpMoneyMark;  // offset: 0xe90
    cGUIInstAnimation* mpButton0;  // offset: 0xe98
    cGUIInstAnimation* mpButton1;  // offset: 0xea0
    const rItemList::rItemParam* mpBuyItemInfo;  // offset: 0xea8
    u32 mBuyGoodsIdx;  // offset: 0xeb0
    u64 mPrice;  // offset: 0xeb8
    const nGUIItem::cItem* mpSellItemInfo;  // offset: 0xec0
    u32 mNowSelectNum;  // offset: 0xec8
    u64 mNowMoney;  // offset: 0xed0
    bool mIsBuyOK;  // offset: 0xed8
    sItemManager::cShop::ShopType mType;  // offset: 0xedc
    bool mIsGoldType;  // offset: 0xee0
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0xee8
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0xf80
    u32 mBuyHaveMax[7];  // offset: 0xfa8
    u32 mSellHaveMax;  // offset: 0xfc4
    StorageItemUIDListVec mItemList;  // offset: 0xfc8
public:
    static MyDTI DTI;
private:
    static const s32 mCTButtonIdTable[3];
};
