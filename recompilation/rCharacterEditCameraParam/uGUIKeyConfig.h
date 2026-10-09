#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/cGUIControlMgr.h"
#include "../shared/nDDOUtility.h"
#include "nGUIKeyConfig.h"
#include "../shared/uGUIBase.h"
#include "../shared/uGUIBaseExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtRect;
class MtString;
class MtVector2;
class cControl;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
namespace nGUIBaseExt { struct ResInfo; }
namespace nGUIKeyConfig { struct Key; }
namespace nGUIKeyConfig { class cCategoryListItems; }
namespace nGUIKeyConfig { class cInputEventHandler; }
namespace nGUIKeyConfig { class cKeyListItems; }
class rGUIMessage;
class rKeyConfigTextTable;

// Declarations
class uGUIKeyConfig;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nGUIKeyConfig { using CategoryName = MtStringEx<44>; }
namespace nGUIKeyConfig { using KeyDetail = MtString; }
namespace nGUIKeyConfig { using KeyGroupName = MtString; }
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;

class uGUIKeyConfig : public uGUIBaseExtWindow
{
public:
    enum MODE
    {
        MODE_LEFT = 0,
        MODE_RIGHT = 1,
        MODE_INPUT = 2,
        MODE_WAIT = 3,
    };
    enum CONTROL_ID
    {
        CONTROL_ID_BASE = 0,
        CONTROL_ID_CATEGORY = 1,
        CONTROL_ID_LAYOUT = 2,
        CONTROL_ID_PULLDOWN = 3,
        CONTROL_ID_KEY_LIST = 4,
        CONTROL_ID_BUTTON = 5,
        CONTROL_NUM = 6,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DEFAULT = 0,
    };
    enum LAYOUT_INDEX
    {
        LAYOUT_PULLDOWN = 0,
        LAYOUT_KEY_LIST = 1,
        LAYOUT_BUTTON = 2,
        LAYOUT_NUM = 3,
    };
    enum GMD_INDEX
    {
        GMD_DEFAULT = 0,
        GMD_GROUP = 1,
        GMD_DETAIL = 2,
    };
    enum RES_INDEX
    {
        RES_TEXTTABLE = 0,
    };
    enum BUTTON_INDEX
    {
        BUTTON_INITIALIZE = 0,
        BUTTON_BLANK_ALL = 1,
        BUTTON_UNDO = 2,
        BUTTON_CLOSE = 3,
        BUTTON_NUM = 4,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_CLOSE = 66,
        INPUTEVENT_DECIDE = 67,
        INPUTEVENT_CANCEL = 68,
        INPUTEVENT_SUBMENU_KEY_LIST = 69,
        INPUTEVENT_LAYOUT_MOVE = 70,
        INPUTEVENT_LAYOUT_MOVE_TO_KEY_LIST_TOP = 71,
        INPUTEVENT_LAYOUT_MOVE_TO_KEY_LIST_BOTTOM = 72,
        INPUTEVENT_BUTTON_MOVE = 73,
    };
public:
    class MyDTI;
    class cButtons;
    class cCategoryItem;
    class cCategoryInfo;
    class cCategoryList;
    class cList;
    class cKeySettingItem;
    class cKeyItem;
    class cKeyInfo;
    class cKeyList;
    class cKeySettingInfo;
    class KeyHistory;
    struct KeyHistoryParam;
public:
    using CategoryItems = nDDOUtility::cArray<uGUIKeyConfig::cCategoryItem, 22>;
    using KeySettingItems = nDDOUtility::cArray<uGUIKeyConfig::cKeySettingItem, 12>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cButtons
    {
    public:
        cButtons();
        void setup(uGUIKeyConfig& owner);
        void addMouseTouchList(u32 index, cControl* control);
        void setFocus(u32 index, bool isFocus);
        void setEnable(u32 index, bool isEnable);
    private:
        nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 4> mArray;  // offset: 0x0
    };
public:
    class cCategoryItem : public uGUIBase::cScrollListItemBase
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
        cCategoryItem();
        // Address: 0x01af60e0 - 0x01af60e1 (1 bytes)
        virtual ~cCategoryItem() {}
        void setup(uGUIKeyConfig& owner, cGUIInstNull* inst_null_list);
        void show(uGUIKeyConfig::cCategoryInfo& info);
        void hide();
        void setName(MT_CTSTR name);
        void setState(nGUIKeyConfig::CATEGORY_STATE state);
    private:
        cGUIInstNull* mpINST_Null_list;  // offset: 0x58
        cGUIObjMessage* mpOBJ_msg_list_m_txt;  // offset: 0x60
        cGUIObjTexture* mpOBJ_fix_check_f_check;  // offset: 0x68
    public:
        static MyDTI DTI;
    };
public:
    class cCategoryInfo : public uGUIBase::cScrollListInfoBase
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
        cCategoryInfo();
        // Address: 0x01af6090 - 0x01af6091 (1 bytes)
        virtual ~cCategoryInfo() {}
        MT_CTSTR getName() const;
        void setName(MT_CTSTR name);
        nGUIKeyConfig::CATEGORY_STATE getState() const;
        void setState(nGUIKeyConfig::CATEGORY_STATE state);
    private:
        nGUIKeyConfig::CategoryName mName;  // offset: 0x28
        nGUIKeyConfig::CATEGORY_STATE mState;  // offset: 0x58
    public:
        static MyDTI DTI;
    };
public:
    class cList
    {
        // inferred: uGUIKeyConfig::getCategoryListIndex names uGUIKeyConfig::mCategoryList.::uGUIKeyConfig::cList::mScrollList.mpVCtrl
        friend class uGUIKeyConfig;
    public:
        cList();
        virtual ~cList();
        uGUIBase::cScrollList& refScrollList();
        const uGUIBase::cScrollList& refScrollList() const;
        bool moveEvent();
        void update(f32 deltaTime);
        virtual void reset(s32 currentPos);  // vtable slot 2
        void setFocus(bool isFocus);
        bool isFocus() const;
    protected:
        virtual void applyFocusToScrollList(bool isFocus);  // vtable slot 3
    protected:
        uGUIBase::cScrollList mScrollList;  // offset: 0x10
        f32 mMaskHeight;  // offset: 0x2c0
        bool mIsFocus;  // offset: 0x2c4
    };
public:
    class cKeyItem : public uGUIBase::cScrollListItemBase
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
        cKeyItem();
        virtual ~cKeyItem() {}
        virtual void setup(uGUIKeyConfig&, cGUIInstNull*) = 0;  // vtable slot 6
        virtual void show(uGUIKeyConfig::cKeyInfo*) = 0;  // vtable slot 7
        virtual void hide() = 0;  // vtable slot 8
    public:
        static MyDTI DTI;
    };
public:
    class cKeyInfo : public uGUIBase::cScrollListInfoBase
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
        cKeyInfo();
        // Address: 0x01af6130 - 0x01af6131 (1 bytes)
        virtual ~cKeyInfo() {}
    public:
        static MyDTI DTI;
    };
public:
    class cKeyList : public uGUIKeyConfig::cList
    {
    public:
        cKeyList();
        virtual ~cKeyList();
        virtual void reset(s32 currentPos);  // vtable slot 2
        void setup(uGUIKeyConfig& owner, uGUIKeyConfig::KeySettingItems& keySettingItems);
        f32 getGroupItemHeight() const;
        f32 getSettingItemHeight() const;
        const uGUIKeyConfig::cKeySettingInfo* getInfo() const;
        uGUIKeyConfig::cKeySettingInfo* getInfo();
        void setIsInput(bool isInput);
        nGUIKeyConfig::Key getKey() const;
        void setKey(u32 itemIndex, nGUIKeyConfig::Key key);
        void setKey(nGUIKeyConfig::Key key);
        nGUIKeyConfig::KEY_STATE getState() const;
        void setState(u32 itemIndex, nGUIKeyConfig::KEY_STATE state);
        void setState(nGUIKeyConfig::KEY_STATE state);
        s32 getOverlapSerialNumber() const;
        void setOverlapSerialNumber(u32 itemIndex, s32 overlapSerialNumber);
        u32 getOption() const;
        bool getToolTipPos(MtVector2& toolTipPos) const;
        bool isHitMouseCollision(f32 x, f32 y) const;
        bool getMouseOverRect(MtRect& rect) const;
    private:
        f32 mGroupItemHeight;  // offset: 0x2c8
        f32 mSettingItemHeight;  // offset: 0x2cc
        cGUIInstAnimation* mpINST_mask01;  // offset: 0x2d0
        cGUIInstNull* mpINST_Null_scroll01;  // offset: 0x2d8
    };
public:
    class cKeySettingInfo : public uGUIKeyConfig::cKeyInfo
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
        cKeySettingInfo();
        virtual ~cKeySettingInfo();
        virtual void addMouseTouchList(cControl* control, s32 pos);  // vtable slot 6
        s32 getSerialNumber() const;
        void setSerialNumber(s32 serialNumber);
        s32 getGroupId() const;
        MT_CTSTR getGroupName() const;
        void setGroup(s32 groupId, MT_CTSTR groupName);
        nGUIKeyConfig::Key getKey() const;
        void setKey(nGUIKeyConfig::Key key);
        MT_CTSTR getDetail() const;
        void setDetail(MT_CTSTR detail);
        nGUIKeyConfig::KEY_STATE getState() const;
        void setState(nGUIKeyConfig::KEY_STATE state);
        s32 getOverlapSerialNumber() const;
        void setOverlapSerialNumber(s32 overlapSerialNumber);
        u32 getOption() const;
        void setOption(u32 option);
        bool isInput() const;
        void setIsInput(bool isInput);
        bool getToolTipPos(MtVector2& toolTipPos) const;
    private:
        s32 mSerialNumber;  // offset: 0x28
        s32 mGroupId;  // offset: 0x2c
        nGUIKeyConfig::Key mKey;  // offset: 0x30
        nGUIKeyConfig::KEY_STATE mState;  // offset: 0x34
        nGUIKeyConfig::KeyGroupName mGroupName;  // offset: 0x38
        nGUIKeyConfig::KeyDetail mDetail;  // offset: 0x40
        s32 mOverlapSerialNumber;  // offset: 0x48
        u32 mOption;  // offset: 0x4c
        bool mIsInput;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
public:
    struct KeyHistoryParam
    {
    public:
        KeyHistoryParam();
        KeyHistoryParam(nGUIKeyConfig::Key key, u32 keyListIndex);
    public:
        nGUIKeyConfig::Key mKey;  // offset: 0x0
        u32 mKeyListIndex;  // offset: 0x4
    };
public:
    class cCategoryList : public uGUIKeyConfig::cList
    {
    public:
        cCategoryList();
        virtual ~cCategoryList();
        void setup(uGUIKeyConfig& owner, uGUIKeyConfig::CategoryItems& items);
        f32 getItemSpacing() const;
        void setName(u32 itemIndex, MT_CTSTR name);
        void setState(u32 itemIndex, nGUIKeyConfig::CATEGORY_STATE state);
        void setState(nGUIKeyConfig::CATEGORY_STATE state);
    private:
        virtual void applyFocusToScrollList(bool isFocus);  // vtable slot 3
    private:
        f32 mItemSpacing;  // offset: 0x2c8
    };
public:
    class cKeySettingItem : public uGUIKeyConfig::cKeyItem
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
        cKeySettingItem();
        // Address: 0x01af5db0 - 0x01af5db1 (1 bytes)
        virtual ~cKeySettingItem() {}
        virtual void setup(uGUIKeyConfig& owner, cGUIInstNull* inst_null);  // vtable slot 6
        void addMouseTouchList(cControl* control, s32 pos);
        virtual void show(uGUIKeyConfig::cKeyInfo* info);  // vtable slot 7
        virtual void hide();  // vtable slot 8
        void setSerialNumber(s32 serialNumber);
        void setGroup(s32 groupId, MT_CTSTR groupName);
        void setKey(nGUIKeyConfig::Key key);
        void emptyKey();
        void setDetail(MT_CTSTR detail);
        void setState(nGUIKeyConfig::KEY_STATE state, bool isInput);
        void getToolTipPos(MtVector2& toolTipPos) const;
    private:
        cGUIInstNull* mpINST_Null_keylist;  // offset: 0x58
        cGUIObjMessage* mpOBJ_msg_number_m_number;  // offset: 0x60
        cGUIObjMessage* mpOBJ_msg_key_detail_m_key_detail;  // offset: 0x68
        cGUIInstAnimation* mpINST_msg_fix_key_icon;  // offset: 0x70
        cGUIObjMessage* mpOBJ_msg_fix_key_icon_m_key;  // offset: 0x78
        cGUIObjPolygon* mpOBJ_msg_fix_key_icon_f_basecolor;  // offset: 0x80
        cGUIObjPolygon* mpOBJ_msg_fix_keycategory_f_base_frame;  // offset: 0x88
        cGUIObjPolygon* mpOBJ_msg_fix_keycategory_f_base;  // offset: 0x90
        cGUIObjMessage* mpOBJ_msg_fix_keycategory_m_keycategory;  // offset: 0x98
        cGUIInstNull* mpINST_Null_tip;  // offset: 0xa0
    public:
        static MyDTI DTI;
    };
public:
    class KeyHistory : public nDDOUtility::cArray<uGUIKeyConfig::KeyHistoryParam, 1>
    {
    public:
        KeyHistory();
        u32 getNum() const;
        void clear();
        void push(nGUIKeyConfig::Key key, u32 keyListIndex);
        bool pop(uGUIKeyConfig::KeyHistoryParam& keyHistoryParam);
    private:
        u32 mStartIndex;  // offset: 0x8
        u32 mNum;  // offset: 0xc
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
    uGUIKeyConfig();
    virtual ~uGUIKeyConfig();
    void setCategoryListItems(const nGUIKeyConfig::cCategoryListItems& categoryListItems);
    void setKeyListItems(const nGUIKeyConfig::cKeyListItems& keyListItems);
    void setInputEventHandler(nGUIKeyConfig::cInputEventHandler* inputEventHandler);
    void setCategoryName(u32 categoryListIndex, MT_CTSTR categoryName);
    void setCategoryState(u32 categoryListIndex, nGUIKeyConfig::CATEGORY_STATE categoryState);
    void setCategoryListStates(const nGUIKeyConfig::cCategoryListItems& categoryListItems);
    void setKey(u32 keyListIndex, nGUIKeyConfig::Key key);
    void setKeyListStates(const nGUIKeyConfig::cKeyListItems& keyListItems);
    void setKeyListKeysAndStates(const nGUIKeyConfig::cKeyListItems& keyListItems);
    void clearKeyHistory(u32 categoryListIndex);
    u32 getCategoryListIndex() const;
    u32 getKeyListIndex() const;
    nGUIKeyConfig::SORT_TYPE getSortType() const;
    const rGUIMessage* getResMsgGroup() const;
    const rGUIMessage* getResMsgDetail() const;
    const rKeyConfigTextTable* getResTextTable() const;
    rKeyConfigTextTable* getResTextTable();
protected:
    virtual MT_CTSTR getLoadArcTagName(u32 arcIndex) const;  // vtable slot 91
    virtual const nGUIBaseExt::ResInfo* getGuiResInfo() const;  // vtable slot 93
    virtual t64 getGuiResUpdateTime() const;  // vtable slot 94
    virtual const nGUIBaseExt::ResInfo* getGmdResInfo(u32 gmdResIndex) const;  // vtable slot 95
    virtual u32 getGmdResNum() const;  // vtable slot 96
    virtual const nGUIBaseExt::ResInfo* getResInfo(u32 gmdResIndex) const;  // vtable slot 97
    virtual u32 getResNum() const;  // vtable slot 98
    virtual void setupAfterLoad();  // vtable slot 100
    virtual void onMoveInput();  // vtable slot 104
    virtual void onMoveEvent();  // vtable slot 105
    virtual void onShow();  // vtable slot 106
    virtual void onHide();  // vtable slot 107
    virtual void onUpdateShow();  // vtable slot 110
    void setDefaultTexts();
    void setupRefrences();
    void setupControls();
    u32 evCtrlClose(cControl::Message* msg);
    void evClose();
    u32 evCtrlDecide(cControl::Message* msg);
    void evDecide();
    u32 evCtrlCancel(cControl::Message* msg);
    void evCancel();
    u32 evCtrlSubMenuKeyList(cControl::Message* msg);
    void evSubMenuKeyList();
    u32 evCtrlLayoutMove(cControl::Message* msg);
    void evLayoutMove();
    void evLayoutMoveToKeyListTop();
    void evLayoutMoveToKeyListBottom();
    u32 evCtrlLayoutClick(cControl::Message* msg);
    u32 evCtrlButtonMove(cControl::Message* msg);
    void evButtonMove();
    u32 evCtrlButtonClick(cControl::Message* msg);
    bool evCtrlScrollListCategory(cControl::Message* msg);
    bool evCtrlScrollListKey(cControl::Message* msg);
    u32 evCtrlScrollListKeyMouseOver(cControl::Message* msg);
    void evScrollListMoveCursor();
    void updateButtonGuide();
    void updateFocus();
    void updateRefrences();
    void updateToolTip();
    void startInputKey();
    void cancelInputKey();
    void moveInputKey();
    void moveWait();
    void showCategoryListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideCategoryListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void showKeyListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideKeyListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setMode(MODE mode);
protected:
    MODE mMode;  // offset: 0x8fc
    cGUIControlMgr mControlMgr;  // offset: 0x900
    cGUIInstAnimation* mpINST_msg_txtguide;  // offset: 0xdb0
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0xdb8
    uGUIBase::cReferenceUIBtnGuide mButtonGuide;  // offset: 0xe10
    nDDOUtility::cArray<uGUIBase::cReferenceUIBtnGuide::stGuideBtnData, 1> mButtonGuideDatas;  // offset: 0xea8
    uGUIBase::cReferenceUITooltip mToolTip;  // offset: 0xed0
    uGUIBase::cReferenceUIPullDown mPulldown;  // offset: 0x1040
    cButtons mButtons;  // offset: 0x1650
    CategoryItems mCategoryItems;  // offset: 0x1c90
    cCategoryList mCategoryList;  // offset: 0x2630
    KeySettingItems mKeySettingItems;  // offset: 0x2900
    cKeyList mKeyList;  // offset: 0x30e0
    nDDOUtility::cArray<KeyHistory, 3> mKeyHistorys;  // offset: 0x33c0
    nGUIKeyConfig::Key mBackupKey;  // offset: 0x33f0
    nGUIKeyConfig::Key mTriggerKey;  // offset: 0x33f4
    nGUIKeyConfig::cInputEventHandler* mInputEventHandler;  // offset: 0x33f8
public:
    static MyDTI DTI;
protected:
    static const u32 BUTTON_GUIDE_BIT_SUB_MENU = 1;
    static const s32 CATEGORY_ITEM_DISP_NUM_MAX = 18;
    static const s32 CATEGORY_ITEM_NUM_MAX = 22;
    static const s32 KEY_ITEM_DISP_NUM_MAX = 8;
    static const s32 KEY_ITEM_NUM_MAX = 12;
    static const u32 KEY_HISTORY_NUM_MAX = 1;
};
