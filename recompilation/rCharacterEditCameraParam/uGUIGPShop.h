#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/Common.h"
#include "../shared/Error.h"
#include "../shared/GP.h"
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cControl.h"
#include "../shared/cGUIControlMgr.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class CDataCommonU32;
class CDataGPShopDisplayLineup;
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtString;
class MtVector2;
class cControl;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjChildAnimationRoot;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjTexture;
class cGUIObject;
class rGUI;
class rGUIMessage;
class uGUIGPConfirm;
class uGUIGPShopDialog;
class uGUISystemMsg;

// Declarations
class uGUIGPShop;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGPShop : public uGUIBase
{
public:
    enum SHOPMENU_TYPE
    {
        SHOPMENU_CHARGE = 0,
        SHOPMENU_USED = 1,
        SHOPMENU_VOICE_PICKUP = 2,
        SHOPMENU_VOICE_MAN = 3,
        SHOPMENU_VOICE_WOMAN = 4,
    };
    enum
    {
        SHOPTYPE_SHOP = 0,
        SHOPTYPE_CHARGE = 1,
        SHOPTYPE_USED = 2,
        SHOPTYPE_NOUSE = 3,
        SHOPTYPE_HISTORY = 4,
    };
    enum
    {
        BROWSERTYPE_INVALID = 0,
        BROWSERTYPE_NONE = 1,
        BROWSERTYPE_BANNER = 2,
        BROWSERTYPE_GOLDSTONE = 3,
        BROWSERTYPE_DETAIL = 4,
        BROWSERTYPE_USELIST = 5,
        BROWSERTYPE_CAPCHARGE = 6,
        BROWSERTYPE_COGHISTORY = 7,
        BROWSERTYPE_COGCREDITCARD = 8,
        BROWSERTYPE_COGPASSPORT = 9,
    };
    enum
    {
        MENU_LIST_MAX = 8,
        SHOP_ITEM_DISP_MAX = 7,
        SHOP_ITEM_MAX = 9,
        CHARGE_ITEM_DISP_MAX = 5,
        CHARGE_ITEM_MAX = 7,
        TICKET_LIST_DISP_MAX = 10,
        TICKET_LIST_MAX = 12,
        USED_LIST_DISP_MAX = 6,
        USED_LIST_MAX = 8,
        NOUSE_LIST_DISP_MAX = 6,
        NOUSE_LIST_MAX = 8,
        HISTORY_LIST_DISP_MAX = 15,
        HISTORY_LIST_MAX = 17,
        COG_LIST_DISP_MAX = 5,
        COG_LIST_MAX = 7,
    };
    enum
    {
        BUTTON_LEFT = 0,
        BUTTON_DETAIL = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        MODE_MENU = 0,
        MODE_CONTENTS = 1,
    };
    enum
    {
        MGR_ID_MENU = 0,
        MGR_ID_MENU_GP = 1,
        MGR_ID_MENU_MENU = 2,
        MGR_ID_MENU_BTN = 3,
        MGR_ID_ITEM = 4,
        MGR_ID_GP = 5,
        MGR_ID_GP_CAP = 6,
        MGR_ID_GP_ITEM = 7,
    };
    enum
    {
        SHOPMENU_LIST_GP = 0,
        SHOPMENU_LIST_MENU = 1,
        SHOPMENU_LIST_BUTTON = 2,
        SHOPMENU_LIST_NUM = 3,
    };
    enum
    {
        MGR_ID_MENU2 = 0,
        MGR_ID_MENU2_MENU = 1,
        MGR_ID_MENU2_BUTTON = 2,
        MGR_ID_USED = 3,
        MGR_ID_NOUSE = 4,
        MGR_ID_HISTORY = 5,
    };
    enum
    {
        STATUSMENU_LIST_MENU = 0,
        STATUSMENU_LIST_BUTTON = 1,
        STATUSMENU_LIST_NUM = 2,
    };
    enum
    {
        CONTROL_CATEGORY_GPSHOP = 0,
        CONTROL_CATEGORY_GPSHOPTAB = 1,
        CONTROL_CATEGORY_STATUS = 2,
    };
    enum
    {
        GP_LIST_CAP = 0,
        GP_LIST_ITEM = 1,
        GP_LIST_NUM = 2,
    };
    enum
    {
        SL_ITEM_TYPE_TICKET = 0,
        SL_ITEM_TYPE_USED = 1,
    };
    enum
    {
        TICKET_CONTENTS = 0,
        TICKET_KIND_NUM = 1,
    };
    enum
    {
        STATUSMENU_START = 0,
        STATUSMENU_USED = 0,
        STATUSMENU_NOUSE = 1,
        STATUSMENU_HISTORY = 2,
        STATUSMENU_END = 3,
        STATUSMENU_BUTTON = 3,
        STATUSMENU_NUM = 3,
        STATUSMENU_FIXMENU_NUM = 1,
    };
    enum
    {
        CLICK_STATUS_BUTTON = 0,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_STARTGPDIALOG = 67,
        INPUTEVENT_STARTGPDIALOG2 = 68,
        INPUTEVENT_OPENGSBUY = 69,
        INPUTEVENT_CHANGESHOPMENU = 70,
        INPUTEVENT_VIEWBANNER = 71,
        INPUTEVENT_OPERATESHOP = 72,
        INPUTEVENT_OPERATESHOPMENU = 73,
        INPUTEVENT_SELECTSHOPMENU = 74,
        INPUTEVENT_CHANGESELECTSHOPITEM = 75,
        INPUTEVENT_SELECTSHOPITEMBUY = 76,
        INPUTEVENT_SELECTSHOPITEMDETAIL = 77,
        INPUTEVENT_ITEMBUY = 78,
        INPUTEVENT_CHANGESELECTSHOPBUTTON = 79,
        INPUTEVENT_STARTSHOPDETAIL = 80,
        INPUTEVENT_OPERATECHARGE = 81,
        INPUTEVENT_CHANGESELECTCHARGEITEM = 82,
        INPUTEVENT_MOUSECLICKCAPBUY = 83,
        INPUTEVENT_MOUSECLICKGPBUY = 84,
        INPUTEVENT_CHARGESTARTLIST = 85,
        INPUTEVENT_DONTCHARGE = 86,
        INPUTEVENT_GSBUY = 87,
        INPUTEVENT_TOSTATUS = 88,
        INPUTEVENT_VIEWGSDETAIL = 89,
        INPUTEVENT_CHANGESTATUSMENU = 90,
        INPUTEVENT_SELECTSTATUSMENU = 91,
        INPUTEVENT_OPERATESTATUSMENU = 92,
        INPUTEVENT_TOSHOP = 93,
        INPUTEVENT_OPERATEUSED = 94,
        INPUTEVENT_CHANGESELECTUSEDITEM = 95,
        INPUTEVENT_CHANGESELECTUSEDBUTTON = 96,
        INPUTEVENT_STARTUSEDDETAIL = 97,
        INPUTEVENT_USEITEM = 98,
        INPUTEVENT_STARTNOUSEDETAIL = 99,
        INPUTEVENT_OPERATENOUSE = 100,
        INPUTEVENT_CHANGESELECTNOUSEITEM = 101,
        INPUTEVENT_CHANGESELECTNOUSEBUTTON = 102,
        INPUTEVENT_OPERATEHISTORY = 103,
        INPUTEVENT_CHANGESELECTHISTORYITEM = 104,
        INPUTEVENT_OPERATECOG = 105,
        INPUTEVENT_EXECCOGITEM = 106,
        INPUTEVENT_NO_ACTION = 107,
    };
    enum
    {
        COG_LIST_HISTORY = 0,
        COG_LIST_LOGINSKIP = 1,
        COG_LIST_CREDITCARD = 2,
        COG_LIST_PASSPORT = 3,
        COG_LIST_NUM = 4,
    };
    enum
    {
        CAPCHARGE_ST_NORMAL = 0,
        CAPCHARGE_ST_BATTLE = 1,
        CAPCHARGE_ST_NOCHARGE = 2,
    };
public:
    class MyDTI;
    struct _MsgInst;
    struct _ItemDetail;
    struct _ItemIcon;
    class cScrollShopDispList;
    struct _ShopList;
    class cScrollChargeDispList;
    class cScrollTicketDispList;
    class cScrollStatusDispBase;
    class cScrollStatusDispList;
    class cScrollHistoryDispList;
    struct _HistoryList;
    class cScrollCOGDispList;
    struct _COGInfo;
    class cScrollShopItemList;
    class cScrollChargeItemList;
    class cScrollTicketItemList;
    class cScrollStatusItemList;
    class cScrollHistoryItemList;
    class cScrollCOGItemList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct _MsgInst
    {
    public:
        cGUIInstAnimation* pInst;  // offset: 0x0
        cGUIObjMessage* pMessage;  // offset: 0x8
    };
public:
    struct _ItemIcon
    {
    public:
        void clear();
    public:
        cGUIObjTexture* pItem;  // offset: 0x0
        cGUIObjTexture* pAttr;  // offset: 0x8
    };
public:
    struct _ShopList
    {
    public:
        void clear();
    public:
        cGUIInstNull* pNull;  // offset: 0x0
        cGUIInstAnimation* pPlate;  // offset: 0x8
        cGUIInstAnimation* pBuyButton;  // offset: 0x10
        cGUIObjMessage* pBuyButtonMsg;  // offset: 0x18
        cGUIObjNull* pBuyPointerPos;  // offset: 0x20
        cGUIInstAnimation* pDetailButton;  // offset: 0x28
        cGUIObjNull* pDetailPointerPos;  // offset: 0x30
        uGUIGPShop::_ItemIcon Icon;  // offset: 0x38
        cGUIObjMessage* pCategory;  // offset: 0x48
        cGUIObjMessage* pName;  // offset: 0x50
        cGUIObjMessage* pPrice;  // offset: 0x58
        cGUIObjMessage* pTimeUnit;  // offset: 0x60
        union
        {
        public:
            cGUIObjTexture* pSaleMark;  // offset: 0x0
            cGUIInstAnimation* pTime;  // offset: 0x0
        };  // offset: 0x68
        bool isEnable;  // offset: 0x70
    };
public:
    class cScrollChargeDispList : public uGUIBase::cScrollListItemBase
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
        cScrollChargeDispList();
        // Address: 0x01af1e00 - 0x01af1e01 (1 bytes)
        virtual ~cScrollChargeDispList() {}
    public:
        uGUIGPShop::_ShopList mInst;  // offset: 0x58
        s32 mIndex;  // offset: 0xd0
        static MyDTI DTI;
    };
public:
    class cScrollStatusDispBase : public uGUIBase::cScrollListItemBase
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
        cScrollStatusDispBase();
        virtual ~cScrollStatusDispBase() {}
    public:
        s32 mIndex;  // offset: 0x58
        static MyDTI DTI;
    };
public:
    class cScrollStatusDispList : public uGUIGPShop::cScrollStatusDispBase
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
        cScrollStatusDispList();
        // Address: 0x01af1de0 - 0x01af1de1 (1 bytes)
        virtual ~cScrollStatusDispList() {}
    public:
        uGUIGPShop::_ShopList mInst;  // offset: 0x60
        cGUIInstance* mpMouseInst2;  // offset: 0xd8
        cGUIObject* mpMouseObj2;  // offset: 0xe0
        static MyDTI DTI;
    };
public:
    struct _HistoryList
    {
    public:
        void clear();
    public:
        cGUIInstAnimation* pInst;  // offset: 0x0
        cGUIObjMessage* pTime;  // offset: 0x8
        cGUIObjMessage* pItemName;  // offset: 0x10
        cGUIObjMessage* pNum;  // offset: 0x18
    };
public:
    class cScrollCOGDispList : public uGUIBase::cScrollListItemBase
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
        cScrollCOGDispList();
        // Address: 0x01af1dc0 - 0x01af1dc1 (1 bytes)
        virtual ~cScrollCOGDispList() {}
    public:
        cGUIInstNull* mpNull;  // offset: 0x58
        uGUIBase::cReferenceUIButton mButton;  // offset: 0x60
        cGUIObjMessage* mpTitle;  // offset: 0x1f0
        cGUIObjNull* mpText;  // offset: 0x1f8
        cGUIObjMessage* mpTextMsg;  // offset: 0x200
        static MyDTI DTI;
    };
public:
    struct _COGInfo
    {
    public:
        u32 TitleMsgId;  // offset: 0x0
        u32 ButtonMsgId;  // offset: 0x4
    };
public:
    class cScrollShopItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollShopItemList();
        cScrollShopItemList(f32 Top, f32 Bottom);
        // Address: 0x01af1f10 - 0x01af1f11 (1 bytes)
        virtual ~cScrollShopItemList() {}
    public:
        static MyDTI DTI;
    };
public:
    class cScrollChargeItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollChargeItemList();
        cScrollChargeItemList(f32 Top, f32 Bottom);
        // Address: 0x01af20c0 - 0x01af20c1 (1 bytes)
        virtual ~cScrollChargeItemList() {}
    public:
        static MyDTI DTI;
    };
public:
    class cScrollTicketItemList : public uGUIBase::cScrollListInfoBase
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
    private:
        cScrollTicketItemList();
    public:
        cScrollTicketItemList(f32 Top, f32 Bottom);
        // Address: 0x01af2070 - 0x01af2071 (1 bytes)
        virtual ~cScrollTicketItemList() {}
    public:
        static MyDTI DTI;
    };
public:
    class cScrollStatusItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollStatusItemList();
        cScrollStatusItemList(f32 Top, f32 Bottom, u32 Idx);
        // Address: 0x01af1fb0 - 0x01af1fb1 (1 bytes)
        virtual ~cScrollStatusItemList() {}
        virtual void addMouseTouchList(cControl* pCtrl, s32 Pos);  // vtable slot 6
    public:
        u32 mLegendIndex;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    class cScrollHistoryItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollHistoryItemList();
        cScrollHistoryItemList(f32 Top, f32 Bottom);
        // Address: 0x01af1f60 - 0x01af1f61 (1 bytes)
        virtual ~cScrollHistoryItemList() {}
    public:
        static MyDTI DTI;
    };
public:
    class cScrollCOGItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollCOGItemList();
        cScrollCOGItemList(f32, f32);
        // Address: 0x01af22b0 - 0x01af22b1 (1 bytes)
        virtual ~cScrollCOGItemList() {}
    public:
        static MyDTI DTI;
    };
public:
    struct _ItemDetail
    {
    public:
        void clear();
    public:
        cGUIInstNull* pNull;  // offset: 0x0
        uGUIGPShop::_ItemIcon Icon;  // offset: 0x8
        cGUIObjMessage* pItemCategory;  // offset: 0x18
        cGUIObjMessage* pItemName;  // offset: 0x20
        cGUIObjMessage* pNum;  // offset: 0x28
        cGUIObjChildAnimationRoot* pGP;  // offset: 0x30
        cGUIObjTexture* pSaleIcon;  // offset: 0x38
        cGUIObjMessage* pNum0;  // offset: 0x40
        cGUIObjMessage* pNum1;  // offset: 0x48
        cGUIObjTexture* pArrow;  // offset: 0x50
        cGUIObjMessage* pNum2;  // offset: 0x58
        cGUIObjMessage* pDetail;  // offset: 0x60
        cGUIObjNull* pMoney;  // offset: 0x68
        cGUIObjMessage* pMoneyNum;  // offset: 0x70
        cGUIObjMessage* pSale;  // offset: 0x78
        cGUIObjTexture* pWindowLC;  // offset: 0x80
        cGUIObjTexture* pWindowCC;  // offset: 0x88
        cGUIObjTexture* pWindowRC;  // offset: 0x90
        cGUIObjTexture* pWindowLD;  // offset: 0x98
        cGUIObjTexture* pWindowCD;  // offset: 0xa0
        cGUIObjTexture* pWindowRD;  // offset: 0xa8
        f32 BaseH;  // offset: 0xb0
    };
public:
    class cScrollShopDispList : public uGUIBase::cScrollListItemBase
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
        cScrollShopDispList();
        // Address: 0x01af1e10 - 0x01af1e11 (1 bytes)
        virtual ~cScrollShopDispList() {}
    public:
        uGUIGPShop::_ShopList mInst;  // offset: 0x58
        s32 mIndex;  // offset: 0xd0
        s32 mInstId;  // offset: 0xd4
        static MyDTI DTI;
    };
public:
    class cScrollTicketDispList : public uGUIGPShop::cScrollStatusDispBase
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
        cScrollTicketDispList();
        // Address: 0x01af1df0 - 0x01af1df1 (1 bytes)
        virtual ~cScrollTicketDispList() {}
    public:
        cGUIInstAnimation* mpInst;  // offset: 0x60
        cGUIObjMessage* mpName;  // offset: 0x68
        cGUIObjMessage* mpNum;  // offset: 0x70
        static MyDTI DTI;
    };
public:
    class cScrollHistoryDispList : public uGUIBase::cScrollListItemBase
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
        cScrollHistoryDispList();
        // Address: 0x01af1dd0 - 0x01af1dd1 (1 bytes)
        virtual ~cScrollHistoryDispList() {}
    public:
        uGUIGPShop::_HistoryList mInst;  // offset: 0x58
        s32 mIndex;  // offset: 0x78
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
    void setStartType(SHOPMENU_TYPE Type);
    void setNGCAPCharge();
    void setGPDialogOpen();
    static void setSystemMessageForBuy();
    uGUIGPShop();
    virtual ~uGUIGPShop();
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void adjustScale();  // vtable slot 84
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateWait();
    void updateShop();
    void updateCharge();
    void updateUsed();
    void updateNoUse();
    void updateHistory();
    void updateCOG();
    void updateChangePage();
    void updateCommon();
    void initCommon();
    void initShopCommon();
    void initShop();
    void initCharge();
    void initStatusCommon();
    void initUsed();
    void initNoUse();
    void initHistory();
    void initCOG();
    void initCallBack();
    void initCallBack2();
    void initCallBack3();
    void initCallBack4();
    void initCallBack5();
    void lineupCallBack();
    void urlCallBack();
    void chargeCallBack();
    void usedCallBack();
    void legendpawnCallBack();
    void nouseCallBack();
    void nouseCallBackForDetail();
    void historyCallBack();
    void cogCallBack();
    void initGetCAPCallBack();
    void setupShopMenu();
    void setupCharge();
    void setupStatusMenu();
    void setupStatusUsed();
    void setupStatusNoUse();
    void setupStatusHistory();
    u32 evCtrlStart(cControl::Message* pMsg);
    u32 evCtrlShopMenuCancel(cControl::Message* pMsg);
    u32 evCtrlShopMenuDecide(cControl::Message* pMsg);
    u32 evCtrlShopMenuCursorUD(cControl::Message* pMsg);
    u32 evCtrlShopMenuMouseClick(cControl::Message* pMsg);
    u32 evCtrlShopMenuChangeStatus(cControl::Message* pMsg);
    u32 evCtrlShopToBrowser(cControl::Message* pMsg);
    u32 evCtrlShopCancel(cControl::Message* pMsg);
    u32 evCtrlShopDecide(cControl::Message* pMsg);
    u32 evCtrlShopCursorUD(cControl::Message* pMsg);
    u32 evCtrlShopCursorLR(cControl::Message* pMsg);
    u32 evCtrlShopMouseClick(cControl::Message* pMsg);
    u32 evCtrlChargeCancel(cControl::Message* pMsg);
    u32 evCtrlChargeDecide(cControl::Message* pMsg);
    u32 evCtrlChargeCursorUD(cControl::Message* pMsg);
    u32 evCtrlChargeToBrowser(cControl::Message* pMsg);
    u32 evCtrlChargeMouseClick(cControl::Message* pMsg);
    u32 evCtrlStatusMenuCancel(cControl::Message* pMsg);
    u32 evCtrlStatusMenuDecide(cControl::Message* pMsg);
    u32 evCtrlStatusMenuCursorUD(cControl::Message* pMsg);
    u32 evCtrlStatusMenuMouseClick(cControl::Message* pMsg);
    u32 evCtrlStatusMenuChangeShop(cControl::Message* pMsg);
    u32 evCtrlUsedCancel(cControl::Message* pMsg);
    u32 evCtrlUsedDecide(cControl::Message* pMsg);
    u32 evCtrlUsedCursorUD(cControl::Message* pMsg);
    u32 evCtrlUsedCursorLR(cControl::Message* pMsg);
    u32 evCtrlNoUseCancel(cControl::Message* pMsg);
    u32 evCtrlNoUseDecide(cControl::Message* pMsg);
    u32 evCtrlNoUseCursorUD(cControl::Message* pMsg);
    u32 evCtrlNoUseCursorLR(cControl::Message* pMsg);
    u32 evCtrlHistoryCancel(cControl::Message* pMsg);
    u32 evCtrlHistoryDecide(cControl::Message* pMsg);
    u32 evCtrlHistoryCursorUD(cControl::Message* pMsg);
    u32 evCtrlCOGCancel(cControl::Message* pMsg);
    u32 evCtrlCOGDecide(cControl::Message* pMsg);
    void updateShopMenuCursor();
    void updateShopDisp(u32 MenuId);
    void updateShopPage(u32 MenuId);
    void updateShopCursor(bool IsOperate);
    void updateShopButton(bool IsOperate);
    void updateChargeDisp();
    void updateChargeCursor(bool IsOperate);
    void updateStatusMenuCursor();
    void updateUsedDisp();
    void updateUsedCursor(bool IsOperate);
    void updateUsedButton(bool IsOperate);
    void updateNoUseDisp();
    void updateNoUseCursor(bool IsOperate);
    void updateNoUseButton(bool IsOperate);
    void updateHistoryDisp();
    void updateHistoryCursor(bool IsOperate);
    void updateCOGDisp();
    void updateCOGCursor(bool IsOperate);
    void updateGP();
    void updateCAP();
    void updateScrollChargeListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollChargeListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateScrollUsedListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollUsedListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateScrollNoUseListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollNoUseListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateScrollHistoryListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollHistoryListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateScrollCOGListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollCOGListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateScrollShopListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollShopListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void setType(u32 Type);
    void startType();
    void setKeyStatus(u32 Mode);
    void setMenuCursorSequence(cGUIInstAnimation* pInst);
    void setDetail(bool IsDisp);
    bool updateDetail();
    void setButtonSequence(bool IsOperate, _ShopList& Item, u32 ButtonId);
    void setButtonSequenceCore(cGUIInstAnimation* pButton, bool IsOperate, bool IsFocus, bool Enable);
    void startBrowser(u32 BrowserType);
    void endBrowser();
    void toStatusPage();
    void toShopPage();
    void setBuyItemDialog();
    void setBuyGSDialog();
    void setUseItemDialog();
    bool moveDialogShop();
    void buyCallBack();
    void lineupCallBackForBuy();
    const CDataGPShopDisplayLineup* getItemInfo();
    bool isEnableDetailDisp();
    bool moveDialogGS();
    void buyGSCallBack();
    bool moveDialogUse();
    void useCallBack();
    void useCallBack2();
    void useCallBack3();
    void updateLineupForBuy();
    bool moveDialogCOG();
    void offCOGLoginSkipCallBack();
    void resetShopCursor();
    void resetChargeCursor();
    void resetUsedCursor();
    void resetNoUseCursor();
    void resetHistoryCursor();
    void resetCOGCursor();
    bool initRequestServer();
    bool capRequestServer();
    bool menuRequestServer();
    bool urlRequestServer();
    bool goldstoneRequestServer();
    bool shoplistRequestServer();
    bool lineupRequestServer();
    bool usedRequestServer();
    bool cogidRequestServer();
    bool legendpawnRequestServer();
    bool nouseRequestServer();
    bool historyRequestServer();
    bool cogRequestServer();
    bool offCOGLoginSkipRequestServer();
    bool buyGoldStoneRequestServer();
    bool buyRequestServer();
    bool useRequestServer();
    bool use2RequestServer();
    s32 getShopCursorInstNo();
    s32 getChargeCursorInstNo();
    u32 getCourseNum(u32 Id);
    void startGPDialog();
    bool manageGPDialog();
    void updateShopMenuPointer();
    void updateStatusMenuPointer();
    s32 getUsedListInstNo();
    s32 getNoUseListInstNo();
    void onShopMenuRequest(u32 Id);
    void setPointerPos(cGUIObject* pObj, const MtVector2& Ofs);
    void initDetail(_ItemDetail& Detail, u32 NullInstId, u32 InfoInstId, u32 FrameInstId, u32 IconId);
    void setDetailExplain(_ItemDetail& Detail, MT_CTSTR pExplain);
    void setCenterWindowSize(cGUIObjTexture* pObj, f32 Height);
    void setBottomWindowPos(cGUIObjTexture* pObj, f32 Height);
    u32 getShopMenuId(u32 ArrayId);
    MT_CTSTR getShopMenuName(u32 ArrayId);
    MT_CTSTR getCategoryName(u32 CategoryId);
    void manageBrowser();
    void manageExecBrowser();
    void initShopMenuCursorPos();
    void changeShopMenu();
    void changeStatusList();
    void shiftShopMenu();
    void shiftShopList();
    void shiftStatusMenu();
    void shiftUsedList();
    void shiftNoUseList();
    void shiftHistoryList();
    void shiftCOGList();
    void setItemURL(MtString& Str);
    bool checkBuyPawnRequestServer();
    bool checkBuyVoiceRequestServer();
    bool checkBuyOutRightRequestServer();
    void checkBuyCallBack();
    void checkBuyCallBackPawn();
    void checkBuyCallBackPawnVoice();
    void checkBuyCallBackOutRight();
    void setAlreadyBuyDialog();
    void initCOGListDisp(u32 Index, cScrollCOGDispList* pDisp);
    void execCOGItem();
    void setCOGURL(MtString& Str, u32 BrowserType);
    void setMyWindowStatusForBrowserExec(bool IsBrowserActive);
    void setItemIcon(_ItemIcon& Icon, u32 ItemIconId, u32 AttrIconId);
    bool isPossibleCAPCharge();
    u32 getCAPChargeState();
    bool isBuySelectedChargeItem();
    bool isBuySelectedShopItem();
    void funcErrorGetCAPCallBack(nError::ERROR_CODE Error);
    void initForNoGetCAP();
    void funcErrorGetCAPCallBackAfterBrowser(nError::ERROR_CODE Error);
    void clearAllShopMenuRequest();
    void updateIndicator();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    uGUIGPShopDialog* mpGPDialog;  // offset: 0x8d8
    uGUISystemMsg* mpDialog;  // offset: 0x8e0
    uGUISystemMsg* mpDialog2;  // offset: 0x8e8
    uGUIGPConfirm* mpGPConfirm;  // offset: 0x8f0
    bool mIsGPDialogOpen;  // offset: 0x8f8
    bool mIsCAPChargeBrowserExec;  // offset: 0x8f9
    bool mIsGetCAPSuccess;  // offset: 0x8fa
    cGUIControlMgr mShopControl;  // offset: 0x900
    cGUIControlMgr mStatusControl;  // offset: 0xdb0
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x1260
    bool mIsNGCAPCharge;  // offset: 0x12b8
    u32 mType;  // offset: 0x12bc
    u32 mHoldBrowserType;  // offset: 0x12c0
    u32 mReqBrowserType;  // offset: 0x12c4
    bool mIsBrowserExec;  // offset: 0x12c8
    bool mIsBrowserLowPriority;  // offset: 0x12c9
    bool mIsPageChange;  // offset: 0x12ca
    f32 mCount;  // offset: 0x12cc
    u32 mMode;  // offset: 0x12d0
    u32 mGPNum;  // offset: 0x12d4
    u32 mCAPNum;  // offset: 0x12d8
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x12e0
    s32 mShopMenuNum;  // offset: 0x1378
    s32 mShopMenuSelected;  // offset: 0x137c
    uGUIBase::cReferenceUIVlCursor mShopMenuCursor;  // offset: 0x1380
    uGUIBase::cScrollList mShopScrollbar;  // offset: 0x1430
    f32 mShopBaseY;  // offset: 0x16e0
    f32 mShopOfsH;  // offset: 0x16e4
    s32 mShopItemNum;  // offset: 0x16e8
    s32 mShopCursorX;  // offset: 0x16ec
    bool mIsShopMenuRequest[8];  // offset: 0x16f0
    MtTypedArray<CDataCommonU32> mBuyIdList;  // offset: 0x16f8
    u32 mBuyId;  // offset: 0x1718
    s32 mChargeNum;  // offset: 0x171c
    s32 mChargeSelected;  // offset: 0x1720
    uGUIBase::cScrollList mChargeScrollbar;  // offset: 0x1730
    f32 mChargeBaseY;  // offset: 0x19e0
    f32 mChargeOfsH;  // offset: 0x19e4
    bool mIsChargeRequest;  // offset: 0x19e8
    s32 mStatusMenuNum;  // offset: 0x19ec
    s32 mStatusMenuSelected;  // offset: 0x19f0
    uGUIBase::cReferenceUIVlCursor mStatusMenuCursor;  // offset: 0x1a00
    s32 mUsedListNum;  // offset: 0x1ab0
    s32 mUsedCourseNum;  // offset: 0x1ab4
    s32 mLegendPawnNum;  // offset: 0x1ab8
    s32 mCpResetNum;  // offset: 0x1abc
    s32 mUsedCursorX;  // offset: 0x1ac0
    uGUIBase::cScrollList mUsedScrollbar;  // offset: 0x1ad0
    f32 mTicketBaseY;  // offset: 0x1d80
    f32 mTicketOfsH;  // offset: 0x1d84
    f32 mUsedBaseY;  // offset: 0x1d88
    f32 mUsedOfsH;  // offset: 0x1d8c
    bool mIsUsedRequest;  // offset: 0x1d90
    bool mIsLegendPawnRequest;  // offset: 0x1d91
    uGUIBase::cReferenceUIVlCursor mUsedCursor;  // offset: 0x1da0
    s32 mNoUseListNum;  // offset: 0x1e50
    s32 mNoUseCursorX;  // offset: 0x1e54
    uGUIBase::cScrollList mNoUseScrollbar;  // offset: 0x1e60
    f32 mNoUseBaseY;  // offset: 0x2110
    f32 mNoUseOfsH;  // offset: 0x2114
    bool mIsNoUseRequest;  // offset: 0x2118
    s32 mHistoryListNum;  // offset: 0x211c
    uGUIBase::cScrollList mHistoryScrollbar;  // offset: 0x2120
    uGUIBase::cReferenceUIVlCursor mHistoryCursor;  // offset: 0x23d0
    f32 mHistoryBaseY;  // offset: 0x2480
    f32 mHistoryOfsH;  // offset: 0x2484
    bool mIsHistoryRequest;  // offset: 0x2488
    uGUIBase::cScrollList mCOGScrollbar;  // offset: 0x2490
    f32 mCOGBaseY;  // offset: 0x2740
    f32 mCOGOfsH;  // offset: 0x2744
    bool mIsCOGRequest;  // offset: 0x2748
    cGUIObjMessage* mpTitleEng;  // offset: 0x2750
    cGUIObjMessage* mpTitleJp;  // offset: 0x2758
    cGUIInstAnimation* mpNoList;  // offset: 0x2760
    cGUIInstAnimation* mpNoListUsed;  // offset: 0x2768
    _MsgInst mCharge;  // offset: 0x2770
    cGUIInstAnimation* mpChargeBuy;  // offset: 0x2780
    _MsgInst mShopMenuList[8];  // offset: 0x2788
    uGUIBase::cReferenceUIButton mShopStatus;  // offset: 0x2808
    _ItemDetail mShopDetail;  // offset: 0x2998
    MtFloat2 mNullBannerPos;  // offset: 0x2a50
    cGUIObjMessage* mpShopTitle;  // offset: 0x2a58
    MtTypedArray<CDataGPShopDisplayLineup> mLineup[8];  // offset: 0x2a60
    cScrollShopDispList mShopItem[9];  // offset: 0x2b60
    cGUIObjMessage* mpCapNum;  // offset: 0x32f8
    cGUIObjMessage* mpCOGId;  // offset: 0x3300
    cScrollChargeDispList mChargeItem[7];  // offset: 0x3308
    cGUIInstAnimation* mpCOGLogOff;  // offset: 0x38f0
    MtFloat2 mNullGSBannerPos;  // offset: 0x38f8
    MtFloat2 mNullGSDetailPos;  // offset: 0x3900
    MtFloat2 mNullCAPWebPos;  // offset: 0x3908
    cGUIInstAnimation* mpCAPChargeButton;  // offset: 0x3910
    cGUIObjNull* mpCAPChargePointerPos;  // offset: 0x3918
    _MsgInst mStatusGS;  // offset: 0x3920
    cGUIInstAnimation* mpStatusChargeBuy;  // offset: 0x3930
    _MsgInst mStatusMenuList[8];  // offset: 0x3938
    uGUIBase::cReferenceUIButton mStatusShop;  // offset: 0x39b8
    cGUIObjMessage* mpStatusTitle;  // offset: 0x3b48
    cScrollTicketDispList mTicketList[12];  // offset: 0x3b50
    cGUIInstAnimation* mpUsedTitle;  // offset: 0x40f0
    cScrollStatusDispList mUsedList[8];  // offset: 0x40f8
    cScrollStatusDispList mNoUseList[8];  // offset: 0x4838
    _ItemDetail mNoUseDetail;  // offset: 0x4f78
    cScrollHistoryDispList mHistoryList[17];  // offset: 0x5030
    cScrollCOGDispList mCOGList[7];  // offset: 0x58b0
    cGUIObjMessage* mpStatusCOGId;  // offset: 0x66e8
    MtFloat2 mBrowserPos;  // offset: 0x66f0
public:
    static MyDTI DTI;
private:
    static const u32 mCTStatusMenuNameTable[3];
    static const u32 mCTTicketNameTable[1];
    static const _COGInfo mCTCOGInfoTable[4];
};
