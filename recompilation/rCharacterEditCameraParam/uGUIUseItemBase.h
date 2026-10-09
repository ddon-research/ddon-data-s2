#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/Item.h"
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/cControl.h"
#include "../shared/cItemParam.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nGUIExt.h"
#include "../shared/nGUIItem.h"
#include "../shared/sGUIExt.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtVector3;
class MtVector4;
class cItemParam;
namespace nGUIItem { class cItem; }
namespace nGUIItem { class cItemList; }
class uGUIBase;
class uGUIPopCmd01;
class uGUIPopDetail01;
class uGUIPopListDialog;
class uGUIPopNumber01;
class uGUIShopBuy;
class uGUISystemMsg;

// Declarations
class uGUIUseItemBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIUseItemBase : public uGUIsMenuBase
{
public:
    enum POPUP
    {
        POPUP_CMD = 0,
        POPUP_SUB = 1,
        POPUP_DETAIL = 2,
        POPUP_NUMBER = 3,
        POPUP_MAX = 4,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_INIT = 1,
        FLOW_WAIT = 2,
        FLOW_WAIT_OM = 3,
        FLOW_WAIT_ONE_FRAME = 4,
        FLOW_WAIT_POPUP = 5,
        FLOW_WAIT_SHARE_POPUP = 6,
        FLOW_WAIT_SORT_POPUP = 7,
        FLOW_WAIT_SERVER = 8,
        FLOW_MOVE_ITEM = 9,
        FLOW_EXIT = 10,
        FLOW_ONLINE_SHOP_POPUP = 11,
        FLOW_WAIT_ONLINE_SHOP_POPUP = 12,
        FLOW_BASE_END = 13,
    };
public:
    class MyDTI;
    struct stPopup;
    class cEquipInfo;
    class cGetItemInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stPopup
    {
    public:
        stPopup();
    public:
        bool mPosEnable;  // offset: 0x0
        MtVector3 mPos;  // offset: 0x10
    };
public:
    class cEquipInfo : public MtObject
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
        cEquipInfo();
    public:
        u32 mJobId;  // offset: 0x8
        u32 mLv;  // offset: 0xc
        nGUIItem::cItem* mpItem;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cGetItemInfo : public MtObject
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
        cGetItemInfo();
    public:
        u32 mNum;  // offset: 0x8
        MtObject* mpParam;  // offset: 0x10
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
    uGUIUseItemBase(u32 initFlags);
    virtual ~uGUIUseItemBase();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void adjustScale();  // vtable slot 84
    virtual s32 getFreeSlotNum();  // vtable slot 96
    void setSendCount(s32 n);
    s32 getSendCount();
    virtual u32 callbackUseItem(MtObject* pCaller, MtObject* pData);  // vtable slot 97
    virtual u32 callbackThrowItem(MtObject* pCaller, MtObject* pData);  // vtable slot 98
    virtual u32 callbackPopDiscardItemNum(MtObject* pCaller, MtObject* pData);  // vtable slot 99
    virtual u32 callbackPopDiscardItemList(MtObject* pCaller, MtObject* pData);  // vtable slot 100
    virtual u32 callbackGetItem(MtObject* pCaller, MtObject* pData, bool isUseNumbox, bool isAllNum);  // vtable slot 101
    virtual u32 callbackGetItems(MtObject* pCaller, MtObject* pData);  // vtable slot 102
    virtual u32 callbackExchangeItem(MtObject* pCaller, MtObject* pData);  // vtable slot 103
    virtual u32 callbackMoveItem(MtObject* pCaller, MtObject* pData);  // vtable slot 104
    virtual u32 callbackEquipItem(MtObject* pCaller, MtObject* pData);  // vtable slot 105
    virtual u32 callbackSellItem(MtObject* pCaller, MtObject* pData);  // vtable slot 106
    virtual u32 callbackPopSellItemList(MtObject* pCaller, MtObject* pData);  // vtable slot 107
    virtual u32 callbackGetItemFromOm(MtObject* pCaller, MtObject* pData);  // vtable slot 108
    virtual u32 callbackSortMenu(MtObject* pCaller, MtObject* pData);  // vtable slot 109
    virtual u32 callbackPopItemList(MtObject* pCaller, MtObject* pData);  // vtable slot 110
    virtual u32 callbackOnlineShopDialog(MtObject* pCaller, MtObject* pData);  // vtable slot 111
    // Address: 0x01b07e80 - 0x01b07e81 (1 bytes)
    virtual void updateWait() {}  // vtable slot 112
    virtual void updateExit();  // vtable slot 113
    virtual void updateWaitPopup();  // vtable slot 114
    // Address: 0x01afaf10 - 0x01afaf11 (1 bytes)
    virtual void updateShareWaitPopup() {}  // vtable slot 115
    // Address: 0x01b07e90 - 0x01b07e91 (1 bytes)
    virtual void updateWaitServer() {}  // vtable slot 116
    virtual void updateOneFrameWait();  // vtable slot 117
    // Address: 0x01afaf20 - 0x01afaf21 (1 bytes)
    virtual void updateOnlineShop() {}  // vtable slot 118
    // Address: 0x01afaf30 - 0x01afaf31 (1 bytes)
    virtual void updateOnlineShopWait() {}  // vtable slot 119
    virtual void execOneFrameWait();  // vtable slot 120
    u32 evCtrlChangeBoxCore(cControl::Message* msg, nGUIExt::MSG_REASON reason);
    u32 evCtrlChangeBox(cControl::Message* msg);
    bool isEndPopup();
    void endShareUnit();
    void setWaitServer(u32 flag);
    void setShareUnit(uGUIUseItemBase* p);
    void setUseEndShareUnit(bool result);
    MtVector4 addV4V3(const MtVector4&, const MtVector3&);
    void setPopupPos(POPUP idx, const MtVector3& pos);
    void setDetailVisible(bool b);
    MtColor getItemNumFontColor(u32 max, u32 count);
    void setOutsidePriority(u32 n);
    u32 getOutsidePriority();
    virtual void setFocus(bool b);  // vtable slot 121
    bool isFocus();
    uGUIPopDetail01* getPopDetail();
    uGUIPopNumber01* getPopNumber();
    uGUIPopListDialog* getPopListDialog();
    uGUISystemMsg* getPopSystemMsg();
    nGUIItem::cItemList& getItemList();
    // Address: 0x01afaf40 - 0x01afaf41 (1 bytes)
    virtual void setExchangeCtrl(bool b) {}  // vtable slot 122
    // Address: 0x01afaf50 - 0x01afaf51 (1 bytes)
    virtual void setExeCtrl(bool b) {}  // vtable slot 123
    virtual void setFlowId(u32 flowId);  // vtable slot 124
    virtual u32 getFlowId();  // vtable slot 125
protected:
    sGUIExt::stGatheringData* getGatheringData();
    virtual void releaseGlobalItem(bool isItemInit);  // vtable slot 126
    bool isCatchMode();
    bool isShareDti(const MtDTI& dti);
    bool isShareStart();
private:
    virtual u32 _callbackGetItem(MtObject* pCaller, MtObject* pData);  // vtable slot 127
    virtual u32 _callbackDiscardItem(MtObject* pCaller, MtObject* pData);  // vtable slot 128
    virtual u32 _callbackDiscardItems(MtObject* pCaller, MtObject* pData);  // vtable slot 129
    virtual u32 _callbackSellItems(MtObject* pCaller, MtObject* pData);  // vtable slot 130
protected:
    nItem::E_STORAGE_TYPE mFromBag;  // offset: 0x958
    nItem::E_STORAGE_TYPE mToBag;  // offset: 0x95c
    nItem::E_STORAGE_TYPE mFromBagGroup;  // offset: 0x960
    nItem::E_STORAGE_TYPE mToBagGroup;  // offset: 0x964
    uGUIUseItemBase* mpShareUnit;  // offset: 0x968
    bool mIsEndShareUnitUse;  // offset: 0x970
    nGUIItem::cItemList mItemList;  // offset: 0x978
    s32 mSendCount;  // offset: 0xaf0
    bool mFocus;  // offset: 0xaf4
    bool mIsForceUpdate;  // offset: 0xaf5
    bool mDetailVisible;  // offset: 0xaf6
    bool mIsShopExecute;  // offset: 0xaf7
    nDDOUtility::cArray<stPopup, 4> mPopupInfos;  // offset: 0xb00
    uGUIPopDetail01* mpDetail;  // offset: 0xb80
    uGUIPopNumber01* mpUnitPopNumber;  // offset: 0xb88
    uGUIPopCmd01* mpUnitPopCmd;  // offset: 0xb90
    uGUIPopCmd01* mpUnitPopCmd2;  // offset: 0xb98
    uGUIShopBuy* mpUnitPopBuy;  // offset: 0xba0
    uGUIBase* mpWaitPopBase;  // offset: 0xba8
    uGUISystemMsg* mpUnitSystemMsg;  // offset: 0xbb0
    uGUIPopListDialog* mpUnitPopList;  // offset: 0xbb8
    sGUIExt::stGatheringData* mpGatheringData;  // offset: 0xbc0
    u32 mOutsidePriorty;  // offset: 0xbc8
    u32 mPickType;  // offset: 0xbcc
    cEquipInfo mEquipInfo;  // offset: 0xbd0
    bool mIsExeCtrl;  // offset: 0xbe8
    u32 mFlowId;  // offset: 0xbec
    bool mIsCatchTrg;  // offset: 0xbf0
    cGetItemInfo mDicardInfo;  // offset: 0xbf8
    MtTypedArray<cItemParam> mListDialog;  // offset: 0xc10
private:
    bool mEndMode;  // offset: 0xc30
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool uGUIUseItemBase::isFocus() {
    return this->mFocus;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIPopDetail01* uGUIUseItemBase::getPopDetail() {
    return this->mpDetail;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUISystemMsg* uGUIUseItemBase::getPopSystemMsg() {
    return this->mpUnitSystemMsg;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIUseItemBase::cEquipInfo::cEquipInfo() {
    this->mJobId = static_cast<u32>(4294967295);
    this->mLv = static_cast<u32>(4294967295);
    this->mpItem = static_cast<nGUIItem::cItem*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIUseItemBase::cGetItemInfo::cGetItemInfo() {
    this->mNum = static_cast<u32>(0);
    this->mpParam = static_cast<MtObject*>(nullptr);
}
