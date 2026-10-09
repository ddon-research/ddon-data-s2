#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/cUIObject.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cDraw;
class cGUIInstAnimation;
class cGUIObjMessage;
class cGUIObjTextureRef;
class cGUIObject;
class rGUI;

// Declarations
class cCaplinkProfIconLoader;
class uGUICaplinkProfile;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCaplinkProfIconLoader : public cUIObject
{
public:
    cCaplinkProfIconLoader();
    virtual ~cCaplinkProfIconLoader();
    void setup(cGUIObject* pObjTex);
    void request(u32 icon_index);
    void request(MT_CTSTR url);
    void update();
    void clear();
    void setVisible(bool isVisible);
    bool isVisible();
public:
    cGUIObjTextureRef* mpObjTex;  // offset: 0x8
    u32 mIconIndex;  // offset: 0x10
    s32 mId;  // offset: 0x14
    bool mIsUpdate;  // offset: 0x18
};

class uGUICaplinkProfile : public uGUIBase
{
public:
    enum
    {
        MODE_SMALL = 0,
        MODE_FULL = 1,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_INFO_REQ = 1,
        FLOW_CONTENT_REQ = 2,
        FLOW_DISP_SMALL = 3,
        FLOW_DISP_LIST = 4,
        FLOW_DISP_FULL = 5,
        FLOW_END = 6,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_PAGE = 76,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stInfo;
    struct stGame;
    class cListItem;
    class cListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 mParam_list_y;  // offset: 0x0
        s32 mParam_point_x;  // offset: 0x4
        s32 mParam_btn_x;  // offset: 0x8
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x8
        uGUIBase::cReferenceUIButton mButton;  // offset: 0x10
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x1a0
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x238
    };
public:
    struct stInfo
    {
    public:
        stInfo();
    public:
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x0
        cGUIObjMessage* mpObjMsgNameTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgName;  // offset: 0x10
        cGUIObjMessage* mpObjMsgIdTitle;  // offset: 0x18
        cGUIObjMessage* mpObjMsgId;  // offset: 0x20
        cGUIObjMessage* mpObjMsgCommentTitle;  // offset: 0x28
        cGUIObjMessage* mpObjMsgComment;  // offset: 0x30
        cCaplinkProfIconLoader mProfIcon;  // offset: 0x38
        uGUIBase::cReferenceUIPageDot mDot;  // offset: 0x58
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
        // Address: 0x01ae3f50 - 0x01ae3f51 (1 bytes)
        virtual ~cListItem() {}
    public:
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x58
        cGUIObjMessage* mpObjMsgCharacter;  // offset: 0x60
        uGUIBase::cReferenceUIIconOnlineStatus mIcon;  // offset: 0x68
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
        // Address: 0x01ae3f60 - 0x01ae3f61 (1 bytes)
        virtual ~cListInfo() {}
    public:
        MtStringEx<257> mContentName;  // offset: 0x28
        MtStringEx<513> mCharacterName;  // offset: 0x130
        bool mIsOnline;  // offset: 0x338
        static MyDTI DTI;
    };
public:
    struct stGame
    {
    public:
        stGame();
    public:
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x0
        cGUIObjMessage* mpObjMsgPlaying;  // offset: 0x8
        cGUIObjMessage* mpObjMsgStatus;  // offset: 0x10
        uGUICaplinkProfile::cListItem mList[20];  // offset: 0x18
        uGUIBase::cScrollList mListCtrl;  // offset: 0xe80
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
    uGUICaplinkProfile(u32 mode);
    virtual ~uGUICaplinkProfile();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setUniqueId(uGUIBase* pParent, MT_CTSTR unique_id);
private:
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupList();
    void setupInfo();
    void setupGame();
    void setupFull();
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void eventDecide();
    void eventCancel();
    void eventPage();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlPage(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mFlowId;  // offset: 0x8d0
    stVariable mVar;  // offset: 0x8d4
    stMain mMain;  // offset: 0x8e0
    stInfo mInfo;  // offset: 0xb70
    stGame mGame;  // offset: 0xc50
    MtStringEx<33> mUniqueId;  // offset: 0x1d80
    u32 mFriendIndex;  // offset: 0x1da8
    u32 mMode;  // offset: 0x1dac
    cControl* mpDecideCtrl;  // offset: 0x1db0
    cControl* mpCancelCtrl;  // offset: 0x1db8
    cControl* mpPageCtrl;  // offset: 0x1dc0
    uGUIBase* mpParent;  // offset: 0x1dc8
public:
    static MyDTI DTI;
};
