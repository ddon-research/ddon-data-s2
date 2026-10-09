#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cControl.h"
#include "../shared/sCaplinkManager.h"
#include "../shared/uGUIBase.h"
#include "uGUICaplinkProfile.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cCaplinkProfIconLoader;
class cControl;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class rGUI;
class uGUICaplinkImageSelect;
class uGUICaplinkMailNotice;
class uGUICaplinkTag;
class uGUISystemMsg;

// Declarations
class uGUICaplinkProfileEdit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUICaplinkProfileEdit : public uGUIBase
{
public:
    enum FLOW_ID
    {
        FLOW_NONE = 0,
        FLOW_INIT = 1,
        FLOW_SELECT = 2,
        FLOW_IMG_SLCT_WAIT = 3,
        FLOW_NAME_INP_WAIT = 4,
        FLOW_COMMENT_INP_WAIT = 5,
        FLOW_PULLDOWN_EXE = 6,
        FLOW_TAGBTN_EXE = 7,
        FLOW_NOTICEBTN_EXE = 8,
        FLOW_SAVE_DLG = 9,
        FLOW_SAVE_PROFILE = 10,
        FLOW_UPDATE_PROFILE = 11,
        FLOW_SAVE_CONTENT = 12,
        FLOW_SAVE_DEVICE_SETTING = 13,
        FLOW_SAVE_NOTIFY_TIME = 14,
        FLOW_END = 15,
    };
    enum CPE_GUIDE_BIT
    {
        CPE_DECIDE = 1,
        CPE_BIT_MAX = 1,
    };
    enum CPLNK_PRF_EDIT_DEF
    {
        INVALID_NUM = -1,
        GMD_IDX_0 = 0,
    };
    enum CPLNK_BTN
    {
        BUTTON_DECIDE = 0,
        BUTTON_CANCEL = 1,
        BUTTON_NUM = 2,
    };
    enum CPLNK_V
    {
        V_MAIN = 0,
        V_BTN = 1,
        V_MAX = 2,
    };
    enum CPLNK_H
    {
        H_LIST = 0,
        H_SCROLL = 1,
        H_MAX = 2,
    };
    enum CPLNK_LIST
    {
        LIST_IMG = 0,
        LIST_NAME_TEXT = 1,
        LIST_COMMENT_TEXT = 2,
        LIST_MAX = 3,
    };
    enum CPE_ITM_KIND_NUM
    {
        SUB_DDO = 0,
        SUB_PROFILE = 1,
        SUB_CAPLINK = 2,
        SUBHEAD_NUM = 3,
        PULL_PLAY_INFO = 0,
        PULL_ONLINE_PRIVACY = 1,
        PULL_PROF_PRIVACY = 2,
        PULL_FIND_SEARCH = 3,
        PULL_CAPTALK_PRIVACY = 4,
        PULL_MAIL_RECEIVE = 5,
        PULLDOWN_NUM = 6,
        BTN_RENAME_TAG = 0,
        BTN_MAIL_SETTING = 1,
        BTN_NUM = 2,
    };
    enum
    {
        KIND_HEADER = 0,
        KIND_PULLDOWN = 1,
        KIND_BUTTON = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
        INPUTEVENT_CLOSE = 69,
    };
    enum CPLNK_DLG
    {
        DLG_SAVE = 0,
        DLG_MAX = 1,
    };
public:
    class MyDTI;
    struct stTop;
    struct stProfile;
    struct stIcon;
    struct stDetail;
    class cContentItemBase;
    struct stContentItem;
    class cPulldownContent;
    class cBtnContent;
    class cListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stTop
    {
    public:
        stTop();
    public:
        cGUIInstNull* mpNull;  // offset: 0x0
        cGUIInstAnimation* mpTitle;  // offset: 0x8
        cGUIObjMessage* mpObjTitleENG;  // offset: 0x10
        cGUIObjMessage* mpObjTitleJP;  // offset: 0x18
        uGUIBase::cReferenceUIButton mBtn[2];  // offset: 0x20
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x340
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x398
    };
public:
    struct stIcon
    {
    public:
        stIcon();
        bool isFocus();
        void setFocus(bool focus);
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimFocus;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimIcon;  // offset: 0x10
        cGUIObjNull* mpObjNullPointer;  // offset: 0x18
        cGUIObjPolygon* mpObjPolyMouseCollision;  // offset: 0x20
        cCaplinkProfIconLoader mProfIcon;  // offset: 0x28
    };
public:
    class cContentItemBase : public uGUIBase::cScrollListItemBase
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
        cContentItemBase();
        // Address: 0x01ae40b0 - 0x01ae40b1 (1 bytes)
        virtual ~cContentItemBase() {}
    public:
        cGUIInstAnimation* mpInst;  // offset: 0x58
        cGUIObjMessage* mpObjMsg;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    class cPulldownContent : public uGUICaplinkProfileEdit::cContentItemBase
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
        cPulldownContent();
        virtual ~cPulldownContent();
    public:
        uGUIBase::cReferenceUIPullDown mPullDown;  // offset: 0x70
        u32 mIndex;  // offset: 0x680
        static MyDTI DTI;
    };
public:
    class cBtnContent : public uGUICaplinkProfileEdit::cContentItemBase
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
        cBtnContent();
        // Address: 0x01ae40c0 - 0x01ae40c1 (1 bytes)
        virtual ~cBtnContent() {}
    public:
        uGUIBase::cReferenceUIButton mButton;  // offset: 0x68
        u32 mIndex;  // offset: 0x1f8
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
        // Address: 0x01ae4930 - 0x01ae4931 (1 bytes)
        virtual ~cListInfo() {}
        virtual void addMouseTouchList(cControl* pCtrl, s32 pos);  // vtable slot 6
    public:
        MT_CTSTR mpName;  // offset: 0x28
        u32 mKind;  // offset: 0x30
        u32 mKindIndex;  // offset: 0x34
        static MyDTI DTI;
    };
public:
    struct stProfile
    {
    public:
        stProfile();
    public:
        cGUIInstAnimation* mpSection;  // offset: 0x0
        cGUIObjMessage* mpObjSecMsg;  // offset: 0x8
        cGUIInstAnimation* mpImg;  // offset: 0x10
        cGUIObjMessage* mpObjImgMsg;  // offset: 0x18
        cGUIInstAnimation* mpCapname;  // offset: 0x20
        cGUIObjMessage* mpObjCapnameMsg;  // offset: 0x28
        cGUIInstAnimation* mpComment;  // offset: 0x30
        cGUIObjMessage* mpObjCommentMsg;  // offset: 0x38
        uGUIBase::cReferenceUITextBox mTxtCapname;  // offset: 0x40
        uGUIBase::cReferenceUITextBox mTxtComment;  // offset: 0x1a8
        uGUICaplinkProfileEdit::stIcon mIcon;  // offset: 0x310
        s32 mOldPos;  // offset: 0x358
    };
public:
    struct stContentItem
    {
    public:
        uGUICaplinkProfileEdit::cContentItemBase mSubhead[3];  // offset: 0x0
        uGUICaplinkProfileEdit::cPulldownContent mPullContent[6];  // offset: 0x140
        uGUICaplinkProfileEdit::cBtnContent mBtnContent[2];  // offset: 0x28a0
    };
public:
    struct stDetail
    {
    public:
        stDetail();
    public:
        cGUIObjPolygon* mpObjPolyMaskTop;  // offset: 0x0
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x8
        cGUIObjPolygon* mpObjPolyMaskBottom;  // offset: 0x10
        cGUIInstAnimation* mpInstAnmMask;  // offset: 0x18
        uGUICaplinkProfileEdit::cContentItemBase mHeader;  // offset: 0x20
        uGUICaplinkProfileEdit::stContentItem mContentItem;  // offset: 0x90
        uGUIBase::cScrollList mScrollList;  // offset: 0x2d30
        s32 mVarHeadMargin;  // offset: 0x2fe0
        s32 mVarList;  // offset: 0x2fe4
        s32 mIdxExePulldown;  // offset: 0x2fe8
        f32 mListTop;  // offset: 0x2fec
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
    uGUICaplinkProfileEdit();
    virtual ~uGUICaplinkProfileEdit();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void draw(cDraw* pDraw);  // vtable slot 12
private:
    cListInfo* getListInfo(u32 idx);
    cListInfo* getListInfo();
    void initContent(cGUIInstance* pNull, const u32 instIdx, const u32 objIdx, cContentItemBase(&Item)[3]);
    void initContent(cGUIInstance* pNull, const u32 instIdx, const u32 objIdx, cBtnContent(&Item)[2]);
    void initContent(cGUIInstance* pNull, const u32 instIdx, const u32 objIdx, cPulldownContent(&Item)[6]);
    void setupContent();
    void setupContentSub(MT_CTSTR pName, s32& top_pos, s32& list_pos, u8 kind, u32 kind_index);
    void updateScrollListDisp(uGUIBase::cScrollListItemBase* pListItem, uGUIBase::cScrollListInfoBase* pListInfo, u32 index);
    void updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void init();
    void createDlg(u32 type);
    bool saveData();
    void setFlowId(u32 flow_id);
    void updateMove();
    void updateExit();
    void reqSaveProfile();
    void updateSaveProfile();
    void reqUpdateProfile();
    void updateUpdateProfile();
    void reqSaveContent();
    void updateSaveContent();
    void reqSaveDeviceSetting();
    void updateSaveDeviceSetting();
    void reqSaveNotifyTime();
    void updateSaveNotifyTime();
    bool isModifyProf();
    bool isModifyContent();
    bool isModifyDeviceSetting();
    bool isModifyNotifyTime();
    void adjustCursor();
    s32 convOpenIndex(s32 index);
    s32 invIndex(s32 index);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void eventDecide();
    void eventCancel();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    void setCtrlFocus(cControl*, bool);
    s32 getCtrlPos(cControl*);
    s32 getCtrlLocate(uGUIBase::cVerticalList*);
private:
    uGUISystemMsg* mpSysMsg;  // offset: 0x8c8
    uGUICaplinkImageSelect* mpImgSlct;  // offset: 0x8d0
    uGUICaplinkTag* mpTagEdit;  // offset: 0x8d8
    uGUICaplinkMailNotice* mpMailNotice;  // offset: 0x8e0
    rGUI* mpGUIRes;  // offset: 0x8e8
    u32 mFlowId;  // offset: 0x8f0
    u32 mFlowIdOld;  // offset: 0x8f4
    u32 mDlgType;  // offset: 0x8f8
    cControl* mpDecideCtrl;  // offset: 0x900
    cControl* mpCancelCtrl;  // offset: 0x908
    uGUIBase::cVerticalList* mpProfileCtrl;  // offset: 0x910
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x918
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0x920
    uGUIBase::cHorizontalList* mpBtnCtrl;  // offset: 0x928
    stTop mTop;  // offset: 0x930
    stProfile mProfile;  // offset: 0xd60
    stDetail mDetail;  // offset: 0x10c0
    sCaplinkManager::cProfile mModifyProf;  // offset: 0x40b0
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0x4458
public:
    static MyDTI DTI;
};
