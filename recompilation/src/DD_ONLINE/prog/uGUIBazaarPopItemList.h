#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cGUIInstAnimation;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjPolygon;
class rGUI;
class rGUIMessage;
class uGUIAnnounce;

// Declarations
class uGUIBazaarPopItemList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIBazaarPopItemList : public uGUIBase
{
public:
    enum
    {
        INPUT_EVENT_DECIDE = 66,
        INPUT_EVENT_CANCEL = 67,
        INPUT_EVENT_MOVE_SELECT = 68,
        INPUT_EVENT_SELECT_LIST = 69,
    };
public:
    class MyDTI;
    class cItemData;
    class cItemPrice;
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
        cGUIObjMessage* mpObjMsgItemName;  // offset: 0x198
        cGUIObjMessage* mpObjMsgItemRank;  // offset: 0x1a0
        static MyDTI DTI;
    };
public:
    class cItemPrice : public MtObject
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
        cItemPrice();
        virtual ~cItemPrice() {}
    public:
        cGUIInstance* mpInstItemPrice;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimMsgList;  // offset: 0x10
        cGUIObjMessage* mpObjMsgPrice;  // offset: 0x18
        cGUIObjMessage* mpObjMsgPriceG;  // offset: 0x20
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x28
        cGUIObjMessage* mpObjMsgTotalPrice;  // offset: 0x30
        cGUIObjMessage* mpObjMsgTotalPriceG;  // offset: 0x38
        cGUIObjPolygon* mpObjMouseOver;  // offset: 0x40
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
    uGUIBazaarPopItemList();
    virtual ~uGUIBazaarPopItemList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void move();  // vtable slot 9
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void begin(u32 itemId);
    bool isBegin() const;
    void hide();
    void stay();
    bool isCancel() const;
    bool isDecide() const;
    void setFocus(bool isFocus);
    void setAnnouncePos(MtVector3& pos);
protected:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
private:
    void updateInit();
    void updateMove();
    void updateAnnounce();
    void updateWait();
    void initialize();
    u32 evCtrlSelectList(cControl::Message* msg);
    u32 evCtrlDecideList(cControl::Message* msg);
    u32 evCtrlCancelList(cControl::Message* msg);
    u32 evCtrlSelectPage(cControl::Message* msg);
    void evSelectPage();
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    void updateItemList();
    void updateItemIcon();
    void setPointerPos();
    bool isAddBagNum(u32 itemNo, u32 num);
    void createAnnounce();
    void resetItemListNum(s32 listNum, s32 pos);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    bool mIsBegin;  // offset: 0x8d8
    u32 mItemId;  // offset: 0x8dc
    u32 mItemIdOld;  // offset: 0x8e0
    cGUIObjMessage* mpObjMsgHeader00;  // offset: 0x8e8
    cGUIObjMessage* mpObjMsgHeader01;  // offset: 0x8f0
    cGUIObjMessage* mpObjMsgHeader02;  // offset: 0x8f8
    cGUIObjMessage* mpObjMsgResultTxt;  // offset: 0x900
    cGUIObjMessage* mpObjMsgResultNum;  // offset: 0x908
    cGUIObjMessage* mpObjMsgNoList;  // offset: 0x910
    uGUIBase::cReferenceUIVlCursor mItemSelCursor;  // offset: 0x920
    uGUIBase::cReferenceUINumPager mNumPageBtn;  // offset: 0x9d0
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0xa78
    uGUIBase::cReferenceUIBtnGuide mGuideButton;  // offset: 0xad0
    cItemData mItemData;  // offset: 0xb70
    cItemPrice mItemPrice[10];  // offset: 0xd20
    uGUIBase::cVerticalList* mpPriceListCtrl;  // offset: 0xff0
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0xff8
    MtVector3 mAnnouncePos;  // offset: 0x1000
    uGUIAnnounce* mpAnnounce;  // offset: 0x1010
    s32 mListTopOld;  // offset: 0x1018
    bool mFocus;  // offset: 0x101c
    bool mStay;  // offset: 0x101d
    bool mIsCancel;  // offset: 0x101e
    bool mIsDecide;  // offset: 0x101f
public:
    static MyDTI DTI;
    static const u32 PRICE_LIST_NUM = 10;
};

inline void* uGUIBazaarPopItemList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIBazaarPopItemList::cItemData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIBazaarPopItemList::cItemData::cItemData() {
    this->mpObjMsgItemRank = nullptr;
    this->mpObjMsgItemName = nullptr;
    this->mpInstItemData = nullptr;
}

inline uGUIBazaarPopItemList::cItemData::~cItemData() {
}

inline void* uGUIBazaarPopItemList::cItemPrice::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIBazaarPopItemList::cItemPrice::cItemPrice() {
    this->mpObjMouseOver = nullptr;
    this->mpObjMsgTotalPriceG = nullptr;
    this->mpObjMsgTotalPrice = nullptr;
    this->mpObjMsgNum = nullptr;
    this->mpObjMsgPriceG = nullptr;
    this->mpObjMsgPrice = nullptr;
    this->mpInstAnimMsgList = nullptr;
    this->mpInstItemPrice = nullptr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIBazaarPopItemList::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopItemList::DTI);
}

inline void uGUIBazaarPopItemList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopItemList::DTI)->memFree(p_addr);
}

inline void* uGUIBazaarPopItemList::cItemData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopItemList::cItemData::DTI)->memAlloc(sz, align, ::uGUIBazaarPopItemList::cItemData::DTI.::MtDTI::getID());
}

inline void uGUIBazaarPopItemList::cItemData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopItemList::cItemData::DTI)->memFree(p_addr);
}

inline void* uGUIBazaarPopItemList::cItemPrice::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopItemList::cItemPrice::DTI)->memAlloc(sz, align, ::uGUIBazaarPopItemList::cItemPrice::DTI.::MtDTI::getID());
}

inline void uGUIBazaarPopItemList::cItemPrice::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopItemList::cItemPrice::DTI)->memFree(p_addr);
}
