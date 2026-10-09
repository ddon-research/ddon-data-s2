#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cControl.h"
#include "../shared/cItemParam.h"
#include "../shared/nCharacterData.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstNull;
class cItemParam;
class rGUI;
class rGUIMessage;
class uGUIAreaMaster;
class uGUIPopDetail01;
class uGUIPopNumber01;
class uGUISystemMsg;

// Declarations
class uGUIGiveAndTake;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGiveAndTake : public uGUIBase
{
    // inferred: uGUIAreaMaster::eventCancel names uGUIGiveAndTake::mSleep
    friend class uGUIAreaMaster;
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_INIT = 1,
        FLOW_SLEEP = 2,
        FLOW_WAIT = 3,
        FLOW_CANCEL_DIALOG = 4,
        FLOW_FINISH_DIALOG = 5,
        FLOW_POP_NUM = 6,
        FLOW_END = 7,
    };
    enum
    {
        MODE_TAKE = 0,
        MODE_GIVE = 1,
    };
    enum
    {
        TYPE_TAKE = 0,
        TYPE_DELIVERY = 1,
    };
    enum
    {
        BAGF_NONE = 0,
        BAGF_PLAYER = 1,
        BAGF_WAREHOUSE = 2,
    };
    enum
    {
        CF_BAGREF = 0,
        CF_SELITEM = 1,
        CF_ENDCMD = 2,
    };
    enum
    {
        RNO_POPNUM_INIT = 0,
        RNO_POPNUM_WAIT = 1,
        RNO_POPNUM_CHKNUM = 2,
        RNO_POPNUM_END = 3,
    };
    enum
    {
        ENDPARAM_NONE = 0,
        ENDPARAM_TAKE_DECIDE = 1,
        ENDPARAM_TAKE_CANCEL = 2,
        ENDPARAM_GIVE_DECIDE = 3,
        ENDPARAM_GIVE_CANCEL = 4,
    };
    enum
    {
        INPUTEVENT_CANCEL = 66,
        INPUTEVENT_MOVE = 67,
        INPUTEVENT_DECIDE_ALL_RECEIVE = 68,
        INPUTEVENT_DECIDE_BUTTON = 69,
        INPUTEVENT_MOVE_BUTTON = 70,
        INPUTEVENT_DECIDE_LIST = 71,
        INPUTEVENT_MOVE_LIST = 72,
        INPUTEVENT_TOGGLE = 73,
    };
public:
    class MyDTI;
    class cItemInfoList;
    class cItemGiveList;
    class cItemList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cItemInfoList : public MtObject
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
        cItemInfoList();
        // Address: 0x01af1c60 - 0x01af1c61 (1 bytes)
        virtual ~cItemInfoList() {}
    public:
        u32 mItemNo;  // offset: 0x8
        u32 mItemNum;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cItemGiveList : public MtObject
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
        cItemGiveList();
        // Address: 0x01af1c10 - 0x01af1c11 (1 bytes)
        virtual ~cItemGiveList() {}
    public:
        MT_CTSTR mItemUID;  // offset: 0x8
        u32 mItemNum;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cItemList : public MtObject
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
        cItemList();
        virtual ~cItemList();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x8
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x10
        cItemParam mParam;  // offset: 0x190
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
    uGUIGiveAndTake();
    virtual ~uGUIGiveAndTake();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void move();  // vtable slot 9
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void addItemInfo(u32 uItemNo, u32 uItemNum);
    void resetItemInfo();
    const MtTypedArray<cItemGiveList>& getItemGiveList() const;
    const MtTypedArray<cItemInfoList>& getItemInfoList() const;
    void setMode(u32 uMode);
    u32 getMode();
    void setType(u32 uType);
    u32 getEndParam();
    void setSleep(bool bSleep);
    bool isSleep();
    void setBagF(u32 uFlg);
    u32 getBagRefF();
protected:
    virtual void adjustScale();  // vtable slot 84
private:
    void setFlowId(u32 uFlowId);
    void updateSleep();
    void updateInit();
    void updateWait();
    void updateWaitCancelDialog();
    void updateWaitFinishDialog();
    void updateWaitPopNumber();
    void updateExit();
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlMove(cControl::Message* msg);
    u32 evCtrlFoCDecide(cControl::Message* msg);
    u32 evCtrlFoCMove(cControl::Message* msg);
    u32 evCtrlItemListMove(cControl::Message* msg);
    u32 evCtrlItemListDecide(cControl::Message* msg);
    u32 evCtrlItemTakeAllDecide(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    u32 evCtrlToggle(cControl::Message* msg);
    void setupCtrl();
    void setDrawDetail(const cItemParam& param);
    void hideDetail();
    void updateDetail();
    void createItemInfoList(bool bUpdate);
    void resetItemIcon(bool bUpdate);
    void addItemFromBag(nCharacterData::ITEM_BAG_TYPE bagType, u32 uItemId, u32& uIndex);
    cItemGiveList* getGiveItemFromUIDPtr(MT_CTSTR pUID);
    cItemInfoList* getItemInfoFromItemId(u32 uItemId);
    void createDialog(MT_CTSTR msg);
    void takeItem();
    void updateDisp();
    void checkAllDelivery();
    MT_CTSTR getMsg(u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGUIMsg;  // offset: 0x8d0
    u32 mFlowId;  // offset: 0x8d8
    u32 mMode;  // offset: 0x8dc
    u32 mType;  // offset: 0x8e0
    u32 mBagF;  // offset: 0x8e4
    u32 mBagRefF;  // offset: 0x8e8
    u32 mCtrlFocus;  // offset: 0x8ec
    u32 mRnoPopNumber;  // offset: 0x8f0
    u32 mEndParam;  // offset: 0x8f4
    u32 mPopNumberMax;  // offset: 0x8f8
    u32 mSelectNum;  // offset: 0x8fc
    cItemParam mDrawItem;  // offset: 0x900
    cItemParam mSelectItem;  // offset: 0x978
    cControl* mpCtrl;  // offset: 0x9f0
    uGUIBase::cHorizontalList* mpCtrlFoC;  // offset: 0x9f8
    uGUIBase::cMatrix* mpCtrlItemList;  // offset: 0xa00
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0xa08
    uGUIPopNumber01* mpGUIPopNumber;  // offset: 0xa10
    uGUIPopDetail01* mpGUIPopDetail;  // offset: 0xa18
    uGUIBase::cReferenceUIToggleBtn mToggleBtnBagRef;  // offset: 0xa20
    uGUIBase::cReferenceUIButton mBtnFinish;  // offset: 0xad0
    uGUIBase::cReferenceUIButton mBtnCancel;  // offset: 0xc60
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0xdf0
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0xe48
    MtTypedArray<cItemInfoList> mItemInfoList;  // offset: 0xee0
    MtTypedArray<cItemGiveList> mItemGiveList;  // offset: 0xf00
    cItemList mItemList[20];  // offset: 0xf20
    f32 mSizeItemIcon;  // offset: 0x3860
    cGUIInstNull* mpInstNullSystemMsg;  // offset: 0x3868
    cGUIInstNull* mpInstNullPopNumber;  // offset: 0x3870
    cGUIInstNull* mpInstNullItemDetail;  // offset: 0x3878
    cGUIInstNull* mpInstNullBagPlayer;  // offset: 0x3880
    cGUIInstNull* mpInstNullBagWarehouse;  // offset: 0x3888
    cGUIInstNull* mpInstNullGiveWindowR;  // offset: 0x3890
    bool mSleep;  // offset: 0x3898
    bool mIsVisibleDetail;  // offset: 0x3899
    bool mIsFirst;  // offset: 0x389a
public:
    static MyDTI DTI;
    static const u32 ITEMLIST_ROW = 4;
    static const u32 ITEMLIST_COL = 5;
    static const u32 ITEMLIST_NUM = 20;
};

// Inline, no code of its own: checked where it is inlined.
inline uGUIGiveAndTake::cItemInfoList::cItemInfoList() {
    this->mItemNo = static_cast<u32>(0);
    this->mItemNum = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIGiveAndTake::cItemGiveList::cItemGiveList() {
    this->mItemUID = static_cast<MT_CTSTR>(nullptr);
    this->mItemNum = static_cast<u32>(0);
}
