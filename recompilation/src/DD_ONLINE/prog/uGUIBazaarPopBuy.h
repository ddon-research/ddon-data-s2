#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "sBazaarManager.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIObjMessage;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIBazaarPopBuy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIBazaarPopBuy : public uGUIBase
{
public:
    enum BPB_GUIDE_BIT
    {
        BPB_INP_NUM = 1,
        BPB_BIT_MAX = 1,
    };
    enum
    {
        MENU_TAG_SELECT_DECIDE = 0,
        MENU_TAG_SELECT_CANCEL = 1,
        MENU_TAG_SELECT_NUM = 2,
    };
    enum
    {
        MENU_TAG_BAG_SELECT = 0,
        MENU_TAG_STORAGE_SELECT = 1,
        MENU_TAG_DEC_TO_CAN = 2,
        MENU_TAG_NUM = 3,
    };
    enum
    {
        INPUT_EVENT_DECIDE = 66,
        INPUT_EVENT_CANCEL = 67,
        INPUT_EVENT_MOVE = 68,
        INPUT_EVENT_SELECT = 69,
        INPUT_EVENT_DIRECT_SETTING = 70,
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
    uGUIBazaarPopBuy();
    virtual ~uGUIBazaarPopBuy();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void move();  // vtable slot 9
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void begin(bool isSelect);
    void hide();
    bool isBegin() const;
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
    void initialize();
    u32 evCtrlSelectMenu(cControl::Message* msg);
    u32 evCtrlDecideMenu(cControl::Message* msg);
    u32 evCtrlCancelMenu(cControl::Message* msg);
    u32 evCtrlStartMenu(cControl::Message* msg);
    u32 evCtrlDecSelectMenu(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    void setPointerPos();
    void calcBagHaveNum(u32 itemNo);
    void eventSelectStorage(u32 tag);
    void eventDirectSetting(u32 tag);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    uGUIBase::cReferenceUIButton mDecideBtn;  // offset: 0x8d8
    uGUIBase::cReferenceUIButton mCancelBtn;  // offset: 0xa68
    uGUIBase::cReferenceUINumBox mBagBoxBtn;  // offset: 0xbf8
    uGUIBase::cReferenceUINumBox mStorageBoxBtn;  // offset: 0xd10
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xe28
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0xec0
    cGUIObjMessage* mpObjMsgTitle;  // offset: 0xee8
    cGUIObjMessage* mpObjMsgPrpTyNum;  // offset: 0xef0
    cGUIObjMessage* mpObjMsgPrpTyG;  // offset: 0xef8
    uGUIBase::cHorizontalList* mpDecToCanCtrl;  // offset: 0xf00
    uGUIBase::cHorizontalList* mpBagNumBoxCtrl;  // offset: 0xf08
    uGUIBase::cHorizontalList* mpStorageNumBoxCtrl;  // offset: 0xf10
    uGUIBase::cVerticalList* mpMenuCtrl;  // offset: 0xf18
    bool mIsBegin;  // offset: 0xf20
    bool mFocus;  // offset: 0xf21
    bool mIsSelect;  // offset: 0xf22
    sBazaarManager::cBazaarItemInfoData* mpItemData;  // offset: 0xf28
    s32 mBagNum[7];  // offset: 0xf30
    bool mIsCancel;  // offset: 0xf4c
    bool mIsDecide;  // offset: 0xf4d
public:
    static MyDTI DTI;
    static const u32 mMenuTag[];
    static const u32 mDecideTag[];
};

inline void* uGUIBazaarPopBuy::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIBazaarPopBuy::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopBuy::DTI);
}

inline void uGUIBazaarPopBuy::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopBuy::DTI)->memFree(p_addr);
}
