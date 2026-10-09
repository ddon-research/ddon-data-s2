#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
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
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class rGUI;
class uGUICaplinkChat;
class uGUICaplinkFriendList;
class uGUICaplinkProfile;
class uGUICaplinkProfileEdit;
class uGUICaplinkTalk;
class uGUICaplinkTrophyList;
class uGUICaplinkTrophyReceive;
class uGUICaplinkTrophyTop;
class uGUISystemMsg;

// Declarations
class cCaptrophyContentData;
class cCaptrophyData;
class cCaptrophyRelationData;
class cCaptrophyRewardData;
class uGUICaplinkTopMenu;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;

class cCaptrophyData : public cUIObject
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
    cCaptrophyData();
public:
    MtStringEx<257> mName;  // offset: 0x8
    MtStringEx<513> mText;  // offset: 0x110
    s32 mId;  // offset: 0x318
    s8 mDifficulty;  // offset: 0x31c
    s8 mComplete;  // offset: 0x31d
    s8 mReceive;  // offset: 0x31e
    static MyDTI DTI;
};

class cCaptrophyRewardData : public cUIObject
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
    cCaptrophyRewardData();
public:
    s32 mRewardType;  // offset: 0x8
    s32 mRewardId;  // offset: 0xc
    s32 mRewardNum;  // offset: 0x10
    static MyDTI DTI;
};

class cCaptrophyRelationData : public cUIObject
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
    cCaptrophyRelationData();
public:
    cCaptrophyData mTrophy;  // offset: 0x8
    MtTypedArray<cCaptrophyRewardData> mReward;  // offset: 0x328
    static MyDTI DTI;
};

class cCaptrophyContentData : public cUIObject
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
    cCaptrophyContentData();
public:
    MtTypedArray<cCaptrophyRelationData> mTrophy;  // offset: 0x8
    MtStringEx<33> mContentId;  // offset: 0x28
    MtStringEx<257> mContentFullName;  // offset: 0x50
    MtStringEx<257> mIconUrl;  // offset: 0x158
    static MyDTI DTI;
};

class uGUICaplinkTopMenu : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_LOAD_ICON = 1,
        FLOW_LIST = 2,
        FLOW_FRIEND = 3,
        FLOW_TALK = 4,
        FLOW_CHAT = 5,
        FLOW_SEARCH = 6,
        FLOW_PROFILE = 7,
        FLOW_ABOUT = 8,
        FLOW_TROPHY = 9,
        FLOW_TROPHY_LIST = 10,
        FLOW_TROPHY_GET = 11,
        FLOW_END = 12,
    };
    enum
    {
        GUIDE_CHANGE_INFO = 0,
        GUIDE_NUM = 1,
    };
    enum
    {
        MENU_TROPHY = 0,
        MENU_FRIEND = 1,
        MENU_TALK = 2,
        MENU_SEARCH = 3,
        MENU_PROFILE = 4,
        MENU_ABOUT = 5,
        MENU_NUM = 6,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stListItem;
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
        s32 mParam_list;  // offset: 0x0
        s32 mParam_cr_txt_x;  // offset: 0x4
        s32 mParam_cr_txt_y;  // offset: 0x8
    };
public:
    struct stListItem
    {
    public:
        stListItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        cGUIObjPolygon* mpObjPolyMouseCollision;  // offset: 0x18
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNullProf;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x10
        uGUICaplinkTopMenu::stListItem mList[6];  // offset: 0x18
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0xe0
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x190
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x1e8
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
    uGUICaplinkTopMenu();
    virtual ~uGUICaplinkTopMenu();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void setChatInfo(s32 id_type, MT_CTSTR id);
    s32 getChatIdType();
    void setContentId(MT_CTSTR id);
    MT_CTSTR getContentId();
    MT_CTSTR getDDOIconUrl();
    MtTypedArray<cCaptrophyData>& getCaptrophyData();
    MtTypedArray<cCaptrophyContentData>& getCaptrophyContentData();
    cCaptrophyData* getCaptrophyData(s32 id);
    cCaptrophyContentData* getCaptrophyContentData(MT_CTSTR content_id);
    cCaptrophyRelationData* getCaptrophyRelationData(MT_CTSTR content_id, s32 id);
    void setupCaptrophyInfo();
    void setupCaptrophyListInfo();
    void setupCaptrophyRelationInfo();
    void getCaptrophyCompleteNum(u32& out_num, u32& out_total);
    void getCaptrophyCompleteNum(const cCaptrophyContentData* pContent, u32& out_num, u32& out_total, u32& out_receive);
private:
    void setFlowId(u32 flow_id, bool is_init);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupLoadIcon();
    void updateLoadIcon();
    void setupList();
    void adjustListCursor();
    void createProf(MT_CTSTR unique_id, u32 mode);
    void deleteProf();
    void setupFriend();
    void updateFriend();
    void setupTalk();
    void updateTalk();
    void setupChat();
    void updateChat();
    void setupSearch();
    void updateSearch();
    void setupProfile();
    void updateProfile();
    void setupAbout();
    void updateAbout();
    void setupTrophy();
    void updateTrophy();
    void setupTrophyList();
    void updateTrophyList();
    void setupTrophyGet();
    void updateTrophyGet();
    void eventDecide();
    void eventCancel();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mFlowId;  // offset: 0x8d0
    bool mIsLoginRetry;  // offset: 0x8d4
    u32 mRno0;  // offset: 0x8d8
    u32 mRno1;  // offset: 0x8dc
    u32 mRno2;  // offset: 0x8e0
    stVariable mVar;  // offset: 0x8e4
    stMain mMain;  // offset: 0x8f0
    MtStringEx<33> mChatId;  // offset: 0xb70
    s8 mChatIdType;  // offset: 0xb98
    MtStringEx<33> mContentId;  // offset: 0xb9c
    MtStringEx<257> mDDOIconUrl;  // offset: 0xbc4
    cControl* mpDecideCtrl;  // offset: 0xcd0
    cControl* mpCancelCtrl;  // offset: 0xcd8
    uGUIBase::cVerticalList* mpListCtrl;  // offset: 0xce0
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0xce8
    uGUICaplinkProfile* mpGUICaplinkProfile;  // offset: 0xcf0
    uGUICaplinkFriendList* mpGUICaplinkFriendList;  // offset: 0xcf8
    uGUICaplinkProfileEdit* mpGUICaplinkProfileEdit;  // offset: 0xd00
    uGUICaplinkTalk* mpGUICaplinkTalk;  // offset: 0xd08
    uGUICaplinkChat* mpGUICaplinkChat;  // offset: 0xd10
    uGUICaplinkTrophyTop* mpGUICaplinkTrophyTop;  // offset: 0xd18
    uGUICaplinkTrophyList* mpGUICaplinkTrophyList;  // offset: 0xd20
    uGUICaplinkTrophyReceive* mpGUICaplinkTrophyReceive;  // offset: 0xd28
    MtTypedArray<cCaptrophyData> mCaptrophyData;  // offset: 0xd30
    MtTypedArray<cCaptrophyContentData> mCaptrophyContentData;  // offset: 0xd50
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mGuideTable[1];  // offset: 0xd70
public:
    static MyDTI DTI;
};
