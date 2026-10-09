#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtStlAllocator.h"
#include "MtStlCustom.h"
#include "MtString.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"
#include "uGUIBaseExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cControl;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
namespace nGUIBaseExt { struct ResInfo; }
namespace nGUIMyRoom { class cListInputEventHandler; }
namespace nGUIMyRoom { class cListItems; }
namespace nGUIMyRoom { class cPopupListInputEventHandler; }
namespace nGUIMyRoom { class cPopupListItems; }

// Declarations
class uGUIMyRoom;
class uGUIMyRoomBase;
class uGUIMyRoomPopup;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;

class uGUIMyRoomBase : public uGUIBaseExtWindow
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
protected:
    uGUIMyRoomBase();
    virtual ~uGUIMyRoomBase();
    virtual MT_CTSTR getLoadArcTagName(u32 arcIndex) const;  // vtable slot 91
    virtual const nGUIBaseExt::ResInfo* getGuiResInfo() const;  // vtable slot 93
    virtual t64 getGuiResUpdateTime() const;  // vtable slot 94
    virtual const nGUIBaseExt::ResInfo* getGmdResInfo(u32 gmdResIndex) const;  // vtable slot 95
    virtual u32 getGmdResNum() const;  // vtable slot 96
    virtual void setupAfterLoad();  // vtable slot 100
protected:
    cGUIInstNull* mpINST_Null_main;  // offset: 0x900
    cGUIInstNull* mpINST_Null_pop;  // offset: 0x908
    cGUIControlMgr mControlMgr;  // offset: 0x910
public:
    static MyDTI DTI;
};

class uGUIMyRoomPopup : public uGUIMyRoomBase
{
public:
    enum CONTROL_ID
    {
        CONTROL_ID_BASE = 0,
        CONTROL_ID_LAYOUT = 1,
        CONTROL_ID_LIST = 2,
        CONTROL_ID_BUTTON = 3,
    };
    enum LAYOUT_ID
    {
        LAYOUT_ID_LIST = 0,
        LAYOUT_ID_BUTTON = 1,
        LAYOUT_NUM = 2,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DEFAULT = 0,
    };
    enum BUTTON_ID
    {
        BUTTON_ID_DECIDE = 0,
        BUTTON_ID_CANCEL = 1,
        BUTTON_NUM = 2,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_MOVE_LAYOUT = 68,
        INPUTEVENT_MOVE_BUTTON = 69,
        INPUTEVENT_SELECT_LIST_TOP = 70,
        INPUTEVENT_SELECT_LIST_BOTTOM = 71,
    };
public:
    class MyDTI;
    class cTitle;
    class cButtons;
    class cList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTitle
    {
    public:
        cTitle();
        void setup(uGUIMyRoomPopup& owner);
        void set(MT_CTSTR title);
    private:
        cGUIObjMessage* mpOBJ_msg_poptitile_m_poptitle;  // offset: 0x0
    };
public:
    class cButtons
    {
    public:
        cButtons();
        void setup(uGUIMyRoomPopup& owner);
        void addMouseTouchList(u32 buttonId, cControl* control);
        void setFocus(u32 buttonId, bool isFocus);
    private:
        nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mButtons;  // offset: 0x0
    };
public:
    class cList
    {
    public:
        class cInfo;
        class cItem;
    public:
        using Items = nDDOUtility::cArray<uGUIMyRoomPopup::cList::cItem, 8>;
    public:
        class cInfo : public uGUIBase::cScrollListInfoBase
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
            cInfo();
            virtual ~cInfo();
            virtual void addMouseTouchList(cControl* control, s32 pos);  // vtable slot 6
            void moveInput();
            bool moveEvent(uGUIMyRoomPopup& owner, uGUIMyRoomPopup::cList& list, nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler);
            bool onDecide(uGUIMyRoomPopup& owner, uGUIMyRoomPopup::cList& list, nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler);
            MT_CTSTR getString() const;
            void setString(MT_CTSTR str);
            u32 getListSize() const;
            void setListSize(u32 listSize);
            MT_CTSTR getListString(u32 listIndex) const;
            void setListString(u32 listIndex, MT_CTSTR str);
            u32 getListIndex() const;
            void setListIndex(u32 listIndex);
            uGUIMyRoomPopup::cList::cItem* getItem();
        private:
            MtString mString;  // offset: 0x28
            MtStlVector<MtString, MtStlAllocator<MtString> > mList;  // offset: 0x30
            u32 mListIndex;  // offset: 0x50
        public:
            static MyDTI DTI;
        };
    public:
        class cItem : public uGUIBase::cScrollListItemBase
        {
        public:
            enum MODE
            {
                MODE_CHECKBOX = 0,
                MODE_PULLDOWN = 1,
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
            cItem();
            virtual ~cItem();
            void setup(uGUIMyRoomPopup& owner, cGUIInstNull* inst_null_list03);
            void addMouseTouchList(cControl* control, s32 pos);
            void moveInput();
            bool moveEvent(uGUIMyRoomPopup& owner, uGUIMyRoomPopup::cList& list, uGUIMyRoomPopup::cList::cInfo& info, nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler);
            bool onDecide(uGUIMyRoomPopup& owner, uGUIMyRoomPopup::cList& list, uGUIMyRoomPopup::cList::cInfo& info, nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler);
            void setFocus(bool isFocus);
            void show(uGUIMyRoomPopup::cList::cInfo& info);
            void hide();
        private:
            void setNullPriority(u32 priority);
        private:
            MODE mMode;  // offset: 0x58
            u32 mDefaultNullPriority;  // offset: 0x5c
            cGUIInstNull* mpINST_Null_list03;  // offset: 0x60
            cGUIInstAnimation* mpInstRootCheckbox;  // offset: 0x68
            cGUIInstAnimation* mpInstRootPulldown;  // offset: 0x70
            cGUIObjMessage* mpOBJ_msg_popcheck_m_popcheck;  // offset: 0x78
            cGUIObjMessage* mpOBJ_msg_poppulldown_m_poppulldowm;  // offset: 0x80
            uGUIBase::cReferenceUICheckbox mCheckbox;  // offset: 0x88
            uGUIBase::cReferenceUIPullDown mPulldown;  // offset: 0xe0
            f32 mDefaultItemSpacing;  // offset: 0x6f0
        public:
            static MyDTI DTI;
        private:
            static const u32 PULLDOWN_VISIBLE_SIZE = 5;
            static const u32 PULLDOWN_WAKEUP_PRIORITY_PLUS = 1;
        };
    public:
        cList();
        void setup(uGUIMyRoomPopup& owner);
        bool moveInput();
        void moveEvent(uGUIMyRoomPopup& owner, nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler);
        void onDecide(uGUIMyRoomPopup& owner, nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler);
        void update(f32 deltaTime);
        void setItems(const nGUIMyRoom::cPopupListItems& listItems, MT_CTSTR removeString, cGUIControlMgr& controlMgr, u32 controlId, u32 parentId, s32 movePos);
        u32 getItemNum() const;
        u32 getItemIndex() const;
        void setItemIndex(u32 itemIndex, bool isImmediate);
        u32 getItemListIndex(u32 itemIndex) const;
        void setFocus(bool isFocus);
        void showItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
        void hideItem(uGUIBase::cScrollListItemBase* pItemBase);
    private:
        void resetList();
        void resetDisp();
        cInfo* getCurrentInfo();
    private:
        f32 mMaskHeight;  // offset: 0x0
        f32 mItemSpacing;  // offset: 0x4
        cInfo* mActiveInfo;  // offset: 0x8
        uGUIBase::cScrollList mScrollList;  // offset: 0x10
        Items mItems;  // offset: 0x2c0
        static const s32 DISP_ITEM_NUM_MAX = 6;
        static const s32 ITEM_NUM_MAX = 8;
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
    uGUIMyRoomPopup();
    virtual ~uGUIMyRoomPopup();
    void setTitle(MT_CTSTR title);
    void setListItems(const nGUIMyRoom::cPopupListItems& listItems);
    void setInputEventHandler(nGUIMyRoom::cPopupListInputEventHandler* popupListInputEventHandler);
protected:
    virtual void setupAfterLoad();  // vtable slot 100
    virtual void onMoveInput();  // vtable slot 104
    virtual void onMoveEvent();  // vtable slot 105
    virtual void onShow();  // vtable slot 106
    virtual void onHide();  // vtable slot 107
    virtual void onUpdateShow();  // vtable slot 110
private:
    void setupRefrences();
    void setupControls();
    u32 evCtrlDecide(cControl::Message* msg);
    void evDecide();
    u32 evCtrlCancel(cControl::Message* msg);
    void evCancel();
    u32 evCtrlMoveLayout(cControl::Message* msg);
    void evMoveLayout();
    u32 evCtrlMoveButton(cControl::Message* msg);
    void evMoveButton();
    u32 evCtrlButtonMouseDecide(cControl::Message* msg);
    void evSelectListTop();
    void evSelectListBottom();
    void evMoveCursor();
    bool evCtrlScrollList(cControl::Message* msg);
    void updateFocus();
    void showListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
private:
    nGUIMyRoom::cPopupListInputEventHandler* mPopupListInputEventHandler;  // offset: 0xdc0
    u32 mFocusUpdateDelayFrame;  // offset: 0xdc8
    cTitle mTitle;  // offset: 0xdd0
    cButtons mButtons;  // offset: 0xdd8
    cList mList;  // offset: 0x1100
public:
    static MyDTI DTI;
};

class uGUIMyRoom : public uGUIMyRoomBase
{
public:
    enum CONTROL_ID
    {
        CONTROL_ID_BASE = 0,
        CONTROL_ID_LIST = 1,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DEFAULT = 0,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
    };
public:
    class MyDTI;
    class cTitle;
    class cPartnerPawnInfo;
    class cList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTitle
    {
    public:
        cTitle();
        void setup(uGUIMyRoom& owner);
    private:
        cGUIObjMessage* mpOBJ_msg_title_m_title00;  // offset: 0x0
        cGUIObjMessage* mpOBJ_msg_title_m_title01;  // offset: 0x8
    };
public:
    class cPartnerPawnInfo
    {
    public:
        cPartnerPawnInfo();
        void setup(uGUIMyRoom& owner);
        void setName(MT_CTSTR name);
        void setJob(u32 jobId);
        void setJobLevel(u32 jobLevel);
        void setCraftLevel(u32 craftLevel);
    private:
        cGUIObjMessage* mpOBJ_window_m_membername;  // offset: 0x0
        cGUIObjMessage* mpOBJ_window_m_lvnum00;  // offset: 0x8
        cGUIObjMessage* mpOBJ_window_m_lvnum01;  // offset: 0x10
        uGUIBase::cReferenceUIIconJob mIconJob;  // offset: 0x18
        uGUIBase::cReferenceUIIconCraftLv mIconCraftLv;  // offset: 0x70
    };
public:
    class cList
    {
        // inferred: uGUIMyRoom::getItemIndex names uGUIMyRoom::mList.mScrollList.mpVCtrl
        friend class uGUIMyRoom;
    public:
        class cItem;
        class cInfo;
    public:
        using Items = nDDOUtility::cArray<uGUIMyRoom::cList::cItem, 9>;
    public:
        class cItem : public uGUIBase::cScrollListItemBase
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
            cItem();
            // Address: 0x01af8f30 - 0x01af8f31 (1 bytes)
            virtual ~cItem() {}
            void setup(uGUIMyRoom& owner, cGUIInstNull* inst_null_list01);
            void show(uGUIMyRoom::cList::cInfo& info);
            void hide();
        private:
            cGUIInstNull* mpINST_Null_list01;  // offset: 0x58
            cGUIObjMessage* mpOBJ_msg_list_m_list;  // offset: 0x60
        public:
            static MyDTI DTI;
        };
    public:
        class cInfo : public uGUIBase::cScrollListInfoBase
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
            cInfo();
            virtual ~cInfo();
            MT_CTSTR getString() const;
            void setString(MT_CTSTR str);
        private:
            MtString mString;  // offset: 0x28
        public:
            static MyDTI DTI;
        };
    public:
        cList();
        void setup(uGUIMyRoom& owner);
        void moveEvent();
        void update(f32 deltaTime);
        void setItems(const nGUIMyRoom::cListItems& listItems, cGUIControlMgr& controlMgr, u32 controlId, u32 categoryId);
        u32 getItemIndex() const;
        bool isItemDisable(u32 itemIndex) const;
        void showItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
        void hideItem(uGUIBase::cScrollListItemBase* pItemBase);
    private:
        void reset();
    private:
        f32 mMaskHeight;  // offset: 0x0
        f32 mItemSpacing;  // offset: 0x4
        uGUIBase::cScrollList mScrollList;  // offset: 0x10
        Items mItems;  // offset: 0x2c0
        static const s32 DISP_ITEM_NUM_MAX = 7;
        static const s32 ITEM_NUM_MAX = 9;
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
    uGUIMyRoom();
    virtual ~uGUIMyRoom();
    void setPawnInfo(MT_CTSTR name, u32 jobId, u32 jobLevel, u32 craftLevel);
    void setListItems(const nGUIMyRoom::cListItems& listItems);
    void setInputEventHandler(nGUIMyRoom::cListInputEventHandler* listInputEventHandler);
    u32 getItemIndex() const;
protected:
    virtual void setupAfterLoad();  // vtable slot 100
    virtual void onMoveInput();  // vtable slot 104
    virtual void onMoveEvent();  // vtable slot 105
    virtual void onShow();  // vtable slot 106
    virtual void onHide();  // vtable slot 107
    virtual void onUpdateShow();  // vtable slot 110
private:
    void setupRefrences();
    void setupControls();
    u32 evCtrlDecide(cControl::Message* msg);
    void evDecide();
    u32 evCtrlCancel(cControl::Message* msg);
    void evCancel();
    void evMoveCursor();
    bool evCtrlScrollList(cControl::Message* msg);
    void showListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
private:
    nGUIMyRoom::cListInputEventHandler* mListInputEventHandler;  // offset: 0xdc0
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0xdc8
    uGUIBase::cReferenceUIBtnGuide mButtonGuide;  // offset: 0xe20
    cTitle mTitle;  // offset: 0xeb8
    cPartnerPawnInfo mPartnerPawnInfo;  // offset: 0xec8
    cList mList;  // offset: 0xf90
public:
    static MyDTI DTI;
};
