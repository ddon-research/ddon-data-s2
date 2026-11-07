#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "cUIObject.h"
#include "nQuest.h"
#include "uGUIBase.h"
#include "uGUIGiveAndTake.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
namespace nQuest { class cGUIDeliveryData; }
class rGUI;
class rGUIMessage;
class uGUIGiveAndTake;
class uGUISystemMsg;

// Declarations
class uGUIQuestDelivery;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIQuestDelivery : public uGUIBase
{
public:
    enum
    {
        MODE_NONE = 0,
        MODE_BOX = 1,
        MODE_NPC = 2,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_LIST_INIT = 1,
        FLOW_LIST = 2,
        FLOW_DELIVERY = 3,
        FLOW_DELIVERY_WAIT = 4,
        FLOW_DELIVERY_COMPLETE = 5,
        FLOW_END = 6,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
    };
public:
    class MyDTI;
    struct stVar;
    struct stQuestTitle;
    struct stQuestList;
    class cListItem;
    struct stItemList;
    struct stItem;
    class cDeliveryItem;
    class cListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stVar
    {
    public:
        stVar();
    public:
        s32 param_list;  // offset: 0x0
        s32 param_item;  // offset: 0x4
        s32 param_cr_txt_x;  // offset: 0x8
        s32 param_cr_txt_y;  // offset: 0xc
        s32 icon_item;  // offset: 0x10
    };
public:
    struct stQuestTitle
    {
    public:
        stQuestTitle();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIObjMessage* mpObjMsgName;  // offset: 0x8
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
        virtual ~cListItem() {}
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x58
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    struct stItem
    {
    public:
        stItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsgName;  // offset: 0x10
        cGUIObjMessage* mpObjMsgBagVal;  // offset: 0x18
        cGUIObjMessage* mpObjMsgBoxVal;  // offset: 0x20
        cGUIObjMessage* mpObjMsgTerm;  // offset: 0x28
        cGUIObjMessage* mpObjMsgTermVal;  // offset: 0x30
        cGUIObjTexture* mpObjTexBag;  // offset: 0x38
        cGUIObjTexture* mpObjTexBox;  // offset: 0x40
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x50
    };
public:
    class cDeliveryItem : public cUIObject
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
        cDeliveryItem();
        cDeliveryItem(const MtString& name, u32 num);
        virtual ~cDeliveryItem();
    public:
        MtString mItemName;  // offset: 0x8
        u32 mItemNum;  // offset: 0x10
        static MyDTI DTI;
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
        virtual ~cListInfo();
    public:
        nQuest::cGUIDeliveryData* mpData;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    struct stQuestList
    {
    public:
        stQuestList();
    public:
        cGUIInstAnimation* mpInstAnimFrame;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgSubTitle;  // offset: 0x18
        uGUIQuestDelivery::cListItem mList[15];  // offset: 0x20
        uGUIBase::cScrollList mListCtrl;  // offset: 0x640
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x8f0
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x948
        static const u32 list_num = 15;
    };
public:
    struct stItemList
    {
    public:
        stItemList();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindow;  // offset: 0x8
        cGUIObjMessage* mpObjMsgListTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgQuestName;  // offset: 0x18
        uGUIQuestDelivery::stItem mList[5];  // offset: 0x20
        static const u32 list_num = 5;
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
    uGUIQuestDelivery();
    virtual ~uGUIQuestDelivery();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void setMode(u32 mode);
    void setIndexData(nQuest::cGUIDeliveryData* pIndexData);
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateInit();
    void updateMove();
    void updateExit();
    void setFlowId(u32 flow_id);
    void setupWindowActive();
    void initList();
    void updateListInit();
    bool isListUpdate();
    void createList();
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setupListSequence(uGUIBase::cScrollListItemBase* pItemBase, const nQuest::cGUIDeliveryData* pData, u32 index);
    void adjustListCursor();
    void decideList();
    cListInfo* getListInfo(u32 index);
    cListInfo* getListInfo();
    void initDelivery();
    void setupDelivery();
    void updateDelivery();
    void decideDelivery();
    void updateDeliveryWait();
    void setupDeliveryComplete();
    void updateDeliveryComplete();
    void callbackDeliveryDecide(u32 ret);
    const MtTypedArray<nQuest::cDeliveredItemInfo::cDeliverCharacterInfo>* getSetData(u32 itemId);
    u32 getDeliveryNum(u32 itemId);
    u32 getItemIdFromUID(MT_CTSTR UID);
    u32 getSelectedItemNum(u32 item_id);
    void eventDecide();
    void eventCancel();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    bool evCtrlScrl(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getQuestMsg(u32);
    MT_CTSTR getCmnMsg(u32);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDDeliveryRes;  // offset: 0x8d0
    rGUIMessage* mpGMDQuestRes;  // offset: 0x8d8
    u32 mMode;  // offset: 0x8e0
    u32 mFlowId;  // offset: 0x8e4
    const nQuest::cGUIDeliveryData* mpIndexData;  // offset: 0x8e8
    stVar mVar;  // offset: 0x8f0
    stQuestTitle mTitle;  // offset: 0x908
    stQuestList mQuest;  // offset: 0x920
    stItemList mItem;  // offset: 0x1300
    cControl* mpCtrlDecide;  // offset: 0x1c30
    cControl* mpCtrlCancel;  // offset: 0x1c38
    MtStringEx<128> mTempStr;  // offset: 0x1c40
    MtTypedArray<uGUIGiveAndTake::cItemGiveList> mTempGiveList;  // offset: 0x1cc8
    MtTypedArray<cDeliveryItem> mDeliveryList;  // offset: 0x1ce8
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x1d08
    uGUIGiveAndTake* mpGUIGiveAndTake;  // offset: 0x1d10
    bool mIsInitTitle;  // offset: 0x1d18
public:
    static MyDTI DTI;
};

inline void* uGUIQuestDelivery::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uGUIQuestDelivery::setMode(u32 mode) {
    this->mMode = 2;
}

inline uGUIQuestDelivery::stVar::stVar() {
}

inline void* uGUIQuestDelivery::cListItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIQuestDelivery::cListItem::cListItem() {
    this->mpObjMsgTitle = nullptr;
    this->mpInstAnim = nullptr;
}

inline void* uGUIQuestDelivery::cDeliveryItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIQuestDelivery::cDeliveryItem::cDeliveryItem() {
    this->mItemNum = 0;
}

inline void* uGUIQuestDelivery::cListInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
