#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtSize;
class MtString;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstScissorMask;
class cGUIObjPolygon;
class cGUIObject;
class rGUI;

// Declarations
class uGUIPopFilter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopFilter : public uGUIsMenuBase
{
public:
    enum REF_TYPE
    {
        REF_NONE = 0,
        REF_CHECKBOX = 1,
        REF_NUMBOX = 2,
        REF_ICON = 3,
        REF_PULLDOWN = 4,
        REF_RESET = 5,
        REF_MAX = 6,
    };
    enum ATTR_BIT
    {
        ATTR_NONE = 0,
        ATTR_MAX = 1,
        ATTR_MIN = 2,
        ATTR_ALL = 4,
    };
    enum TITLE_PRE
    {
        TITLE_U = 0,
        TITLE_D = 1,
    };
    enum BUTTON_CTRL
    {
        BTN_0 = 0,
        BTN_1 = 1,
        BTN_NUM = 2,
    };
    enum CLICK_CTRL
    {
        CLICK_DECIDE = 0,
        CLICK_CANCEL = 1,
        CLICK_ICON_00 = 2,
        CLICK_ICON_01 = 3,
        CLICK_ICON_02 = 4,
        CLICK_ICON_03 = 5,
        CLICK_ICON_04 = 6,
        CLICK_ICON_05 = 7,
        CLICK_ICON_06 = 8,
        CLICK_ICON_07 = 9,
        CLICK_ICON_08 = 10,
        CLICK_ICON_09 = 11,
        CLICK_RESET = 12,
        CLICK_CTRL_MAX = 13,
        CLICK_REF = 14,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_UP = 68,
        INPUTEVENT_DOWN = 69,
        INPUTEVENT_START_BTN = 70,
        INPUTEVENT_ADJUST = 71,
        INPUTEVENT_NUMBOX_START = 72,
        INPUTEVENT_NUMBOX_MOVE_L = 73,
        INPUTEVENT_NUMBOX_MOVE_R = 74,
        INPUTEVENT_JOB_L = 75,
        INPUTEVENT_JOB_R = 76,
    };
public:
    class MyDTI;
    class cData;
    struct stMain;
    struct stList;
    class cListItem;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cData : public uGUIBase::cScrollListInfoBase
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
        cData();
    public:
        uGUIPopFilter::REF_TYPE mType;  // offset: 0x28
        uGUIPopFilter::ATTR_BIT mAttr;  // offset: 0x2c
        uGUIPopFilter::TITLE_PRE mTitle;  // offset: 0x30
        u32 mRefIndex;  // offset: 0x34
        u32 mExtindex;  // offset: 0x38
        s32 mDefault;  // offset: 0x3c
        s32 mMin;  // offset: 0x40
        s32 mMax;  // offset: 0x44
        bool mSetup;  // offset: 0x48
        bool mEnable;  // offset: 0x49
        bool mVisible;  // offset: 0x4a
        bool mGrayOut;  // offset: 0x4b
        MT_CTSTR mTitleName;  // offset: 0x50
        MT_CTSTR mRefName;  // offset: 0x58
        f32 mOfs;  // offset: 0x60
        s32 mRefId;  // offset: 0x64
        s32 mTitleId;  // offset: 0x68
        s32 mTitleVal;  // offset: 0x6c
        u32 mJob;  // offset: 0x70
        u32 mPullDownNum;  // offset: 0x74
        s32 mPullDownSize;  // offset: 0x78
        MT_CTSTR mPullDownlist[20];  // offset: 0x80
        s32 mPullDownlistId[20];  // offset: 0x120
        MtString mRefNameStr;  // offset: 0x170
        static MyDTI DTI;
        static const u32 listnum = 20;
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstFooter;  // offset: 0x0
        cGUIInstScissorMask* mpInstScissorMask;  // offset: 0x8
        cGUIInstNull* mpInstScrool;  // offset: 0x10
        cGUIObjPolygon* mpObjCol;  // offset: 0x18
        cGUIInstNull* mpInstNumBox;  // offset: 0x20
        cGUIInstNull* mpInstCheckBox;  // offset: 0x28
        cGUIInstNull* mpInstPullDown;  // offset: 0x30
        cGUIInstNull* mpInstResetBtn;  // offset: 0x38
        cGUIInstNull* mpInstJobIcon;  // offset: 0x40
        cGUIInstAnimation* mpInstMsgHeader;  // offset: 0x48
        cGUIInstAnimation* mpInstBtn0;  // offset: 0x50
        cGUIInstAnimation* mpInstBtn1;  // offset: 0x58
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
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x58
        cGUIInstAnimation* mpInstMsgHeader;  // offset: 0x60
        cGUIObject* mpMsgObj;  // offset: 0x68
        uGUIBase::cDupliInstAnim mpInstJobIcon[10];  // offset: 0x70
        uGUIBase::cReferenceUIIconButton mRefIconJob[10];  // offset: 0x200
        uGUIPopFilter::REF_TYPE mType;  // offset: 0x6b0
        u32 mRefIndex;  // offset: 0x6b4
        static MyDTI DTI;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        uGUIPopFilter::cListItem mList[20];  // offset: 0x0
        uGUIBase::cScrollList mListCtrl;  // offset: 0x8660
        f32 mListTop;  // offset: 0x8910
        static const u32 list_num = 20;
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
    uGUIPopFilter(MT_CTSTR title);
    virtual ~uGUIPopFilter();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void setupListItem(cListItem* pItem, cData* pInfo, u32 index, bool select);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setVisibleRef(cListItem* pItem, bool visible);
    void setWindowTitle(MT_CTSTR title);
    void setWindowTitle(s32 id);
    void setBtnTitle(MT_CTSTR btitle1, MT_CTSTR btitle2);
    void setBtnTitle(s32 id, s32 id2);
    void editRefName(u32 idx, MtString str);
    void setSize(MtSize size);
    void setAdjustSize(bool flag);
    bool addReference(REF_TYPE type, s32 def, MT_CTSTR str, TITLE_PRE style, s32 max, s32 min, MT_CTSTR name, ATTR_BIT bit);
    bool addReference(REF_TYPE type, s32 def, s32 titleid, TITLE_PRE style, s32 nameid, s32 max, s32 min, ATTR_BIT bit);
    bool addJobIcon(s32 def, MT_CTSTR str, bool all, MT_CTSTR checkboxname, TITLE_PRE style);
    bool addJobIcon(s32 def, s32 strid, bool all, s32 checkboxnameid, TITLE_PRE style);
    bool addReferenceMaxMin(s32 defmax, s32 defmin, s32 max, s32 min, MT_CTSTR title, MT_CTSTR strmax, MT_CTSTR strmin, TITLE_PRE style);
    bool addReferenceMaxMin(s32 defmax, s32 defmin, s32 max, s32 min, s32 titleid, s32 strmaxid, s32 strminid, TITLE_PRE style);
    bool addCheckBox(s32 nameid, s32 def, s32 titleid, TITLE_PRE style);
    bool addCheckBox(MT_CTSTR name, s32 def, MT_CTSTR title, TITLE_PRE style);
    void setCheckBoxTitle(u32 idx, s32 titleid, s32 val);
    bool addNumBox(s32 def, s32 max, s32 min, s32 nameid, s32 titleid, TITLE_PRE style);
    bool addNumBox(s32 def, s32 max, s32 min, MT_CTSTR name, MT_CTSTR title, TITLE_PRE style);
    bool addResetBtn(MT_CTSTR name);
    bool addResetBtn(s32 nameid);
    bool addPullDown(s32 def, MT_CTSTR title, s32 listsize, TITLE_PRE style);
    bool addPullDown(s32 def, s32 titleid, s32 listsize, TITLE_PRE style);
    void addPullDownList(u32 idx, MT_CTSTR listname);
    void addPullDownList(u32 idx, s32 id);
    void setListSize(u32 idx, s32 size);
    void setReferenceEnable(u32 idx, bool enable);
    void setGrayOut(u32 idx, bool flag);
    bool setParam(u32 idx, s32 param);
    s32 getParam(u32 idx);
    void onChangeNumBox();
    bool isDecide();
    bool isCancel();
    void setDecideEnable(bool flag);
    s32 getRefIndex(REF_TYPE type);
    void setNotClose(bool flag);
    void setWaitReq(bool flag);
    void setCheckNum(s32 num);
    void setBtnDefautPos(u32 pos);
private:
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateNone();
    void updateWakeUp();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void init();
    void clearList();
    void createList();
    void clearButtonCursor();
    void adjustButtonCursor();
    cData* getListInfo(u32);
    void evDecide();
    void evCancel();
    void evAdjustCursor();
    void evNumBoxStart();
    void evNumBoxMoveL();
    void evNumBoxMoveR();
    void evJobL();
    void evJobR();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlUp(cControl::Message* msg);
    u32 evCtrlDown(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlBtnClick(cControl::Message* msg);
    u32 evCtrlNumBoxMoveL(cControl::Message* msg);
    u32 evCtrlNumBoxMoveR(cControl::Message* msg);
    s32 getCtrlPos(cControl* pCtrl);
    void createReference(u32 idx);
    REF_TYPE getRefType(s32 idx);
    bool isExistEditNumBox();
    bool allJobCheck(u32 job);
    void setAllJob(bool allon, u32 idx);
    void resetParam();
    bool isCheckNum();
private:
    rGUI* mpGUIRes;  // offset: 0x958
    cGUIInstNull* mpInstNull;  // offset: 0x960
    uGUIBase::cAdjustableWindow mWindow;  // offset: 0x968
    MtSize mSize;  // offset: 0xa08
    MtSize mSizeOld;  // offset: 0xa10
    MtTypedArray<cData> mData;  // offset: 0xa18
    MtTypedArray<uGUIBase::cReferenceUICheckbox> mCheckBox;  // offset: 0xa38
    MtTypedArray<uGUIBase::cReferenceUINumBox> mNumBox;  // offset: 0xa58
    MtTypedArray<uGUIBase::cReferenceUIPullDown> mPullDown;  // offset: 0xa78
    MT_CTSTR mWindowTitle;  // offset: 0xa98
    s32 mWindowTitleId;  // offset: 0xaa0
    MT_CTSTR mBtnTitle1;  // offset: 0xaa8
    s32 mBtnTitleId1;  // offset: 0xab0
    MT_CTSTR mBtnTitle2;  // offset: 0xab8
    s32 mBtnTitleId2;  // offset: 0xac0
    MT_CTSTR mWarning;  // offset: 0xac8
    s32 mWarningId;  // offset: 0xad0
    f32 mListSizeY;  // offset: 0xad4
    bool mAdjustSize;  // offset: 0xad8
    bool mRefresh;  // offset: 0xad9
    uGUIBase::cReferenceUIButton mBtn[2];  // offset: 0xae0
    uGUIBase::cReferenceUIIconButton mResetBtn;  // offset: 0xe00
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xe78
    cControl* mpButtonCtrl;  // offset: 0xf10
    uGUIBase::cVerticalList* mpClickCtrl;  // offset: 0xf18
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0xf20
    bool mWaitReq;  // offset: 0xf28
    bool mNotClose;  // offset: 0xf29
    u32 mSelectJob;  // offset: 0xf2c
    stMain mMain;  // offset: 0xf30
    stList mList;  // offset: 0xf90
    bool mBtnCtrl;  // offset: 0x98b0
    bool mDecide;  // offset: 0x98b1
    bool mCancel;  // offset: 0x98b2
    bool mIsEnable[2];  // offset: 0x98b3
    bool mIsPullDownWakeup;  // offset: 0x98b5
    f32 mPullDownOfs;  // offset: 0x98b8
    s32 mCheckNum;  // offset: 0x98bc
    u32 mBtnPos;  // offset: 0x98c0
public:
    static MyDTI DTI;
};
