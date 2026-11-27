#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "rItemList.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstance;
class cGUIObjMessage;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIBazaarPopPriceSetting;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIBazaarPopPriceSetting : public uGUIBase
{
public:
    enum BPPS_GUIDE_BIT
    {
        BPPS_INP_NUM = 1,
        BPPS_BIT_MAX = 1,
    };
    enum
    {
        MENU_TAG_SELECT_DECIDE = 0,
        MENU_TAG_SELECT_CANCEL = 1,
        MENU_TAG_SELECT_NUM = 2,
    };
    enum
    {
        MENU_TAG_GOLD_SELECT = 0,
        MENU_TAG_NUM_SELECT = 1,
        MENU_TAG_DEC_TO_CAN = 2,
        MENU_TAG_NUM = 3,
    };
    enum
    {
        MODE_EXHIBIT = 0,
        MODE_RE_EXHIBIT = 1,
    };
    enum
    {
        INPUT_EVENT_DECIDE = 66,
        INPUT_EVENT_CANCEL = 67,
        INPUT_EVENT_MOVE_SELECT = 68,
    };
public:
    class MyDTI;
    class cItemData;
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
    uGUIBazaarPopPriceSetting();
    virtual ~uGUIBazaarPopPriceSetting();
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
    void setItemParam(rItemList::rItemParam* pItemParam);
    void setBagItemNum(u32 num);
    void setPriceNum(u32 num);
    void setMode(u32 mode);
    u32 getItemNo();
    s32 getItemNum() const;
    s32 getItemPrice() const;
    bool isCancel() const;
    bool isDecide() const;
    void setFocus(bool isFocus);
protected:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
private:
    void updateInit();
    void updateMove();
    void updateWait();
    void updateConfirm();
    void initialize();
    void setItem();
    u32 evCtrlSelectMenu(cControl::Message* msg);
    u32 evCtrlDecideMenu(cControl::Message* msg);
    u32 evCtrlCancelMenu(cControl::Message* msg);
    u32 evCtrlStartMenu(cControl::Message* msg);
    u32 evCtrlDecSelectMenu(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    void setPointerPos();
    u32 getMenuTagToPos(u32 tagId);
    void eventDirectSetting(u32 tag);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8d8
    cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x8e0
    cGUIObjMessage* mpObjMsgPriceGold;  // offset: 0x8e8
    cGUIObjMessage* mpObjMsgPriceGoldTxt;  // offset: 0x8f0
    cGUIObjMessage* mpObjMsgPriceNum;  // offset: 0x8f8
    cGUIObjMessage* mpObjMsgPriceNumGold;  // offset: 0x900
    cGUIObjMessage* mpObjMsgPriceRestrict;  // offset: 0x908
    cGUIObjMessage* mpObjMsgNumRestrict;  // offset: 0x910
    cGUIObjMessage* mpObjMsgTotalPriceNum;  // offset: 0x918
    cGUIObjMessage* mpObjMsgTotalPriceSymbol;  // offset: 0x920
    uGUIBase::cReferenceUIButton mDecideBtn;  // offset: 0x928
    uGUIBase::cReferenceUIButton mCancelBtn;  // offset: 0xab8
    uGUIBase::cReferenceUINumBox mGoldBoxBtn;  // offset: 0xc48
    uGUIBase::cReferenceUINumBox mNumBoxBtn;  // offset: 0xd60
    cItemData mItemData;  // offset: 0xe80
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x1020
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0x10b8
    uGUIBase::cHorizontalList* mpDecToCanCtrl;  // offset: 0x10e0
    uGUIBase::cVerticalList* mpMenuCtrl;  // offset: 0x10e8
    bool mIsBegin;  // offset: 0x10f0
    u32 mMode;  // offset: 0x10f4
    rItemList::rItemParam* mpItemParam;  // offset: 0x10f8
    u32 mBagItemNum;  // offset: 0x1100
    u32 mRePriceNum;  // offset: 0x1104
    s32 mPrice;  // offset: 0x1108
    s32 mItemNum;  // offset: 0x110c
    bool mFocus;  // offset: 0x1110
    bool mStay;  // offset: 0x1111
    bool mIsCancel;  // offset: 0x1112
    bool mIsDecide;  // offset: 0x1113
public:
    static MyDTI DTI;
    static const u32 mMenuTag[];
    static const u32 mDecideTag[];
};

inline void* uGUIBazaarPopPriceSetting::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uGUIBazaarPopPriceSetting::setItemParam(rItemList::rItemParam* pItemParam) {
    this->mpItemParam = pItemParam;
}

inline void uGUIBazaarPopPriceSetting::setBagItemNum(u32 num) {
    this->mBagItemNum = num;
}

inline s32 uGUIBazaarPopPriceSetting::getItemNum() const {
    return this->mItemNum;
}

inline s32 uGUIBazaarPopPriceSetting::getItemPrice() const {
    return this->mPrice;
}

inline void* uGUIBazaarPopPriceSetting::cItemData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIBazaarPopPriceSetting::cItemData::cItemData() {
    this->mpObjMsgItemName = nullptr;
    this->mpInstItemData = nullptr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIBazaarPopPriceSetting::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopPriceSetting::DTI);
}

inline void uGUIBazaarPopPriceSetting::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopPriceSetting::DTI)->memFree(p_addr);
}

inline void* uGUIBazaarPopPriceSetting::cItemData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopPriceSetting::cItemData::DTI)->memAlloc(sz, align, ::uGUIBazaarPopPriceSetting::cItemData::DTI.::MtDTI::getID());
}

inline void uGUIBazaarPopPriceSetting::cItemData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopPriceSetting::cItemData::DTI)->memFree(p_addr);
}
