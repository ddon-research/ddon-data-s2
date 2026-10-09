#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/sCaplinkManager.h"
#include "../shared/uGUIBase.h"
#include "uGUICaplinkMenuBase.h"
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
class cGUIObjMessage;
class cGUIObjPolygon;
namespace nCaplink { class cUserBaseInfo; }
class rGUI;
class uGUICaplinkFriendList;
class uGUICaplinkProfileEdit;

// Declarations
class uGUICaplinkTalk;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICaplinkTalk : public uGUICaplinkMenuBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_INIT = 1,
        FLOW_TALK_LIST = 2,
        FLOW_TALK_SUB_MENU = 3,
        FLOW_TALK_LOG = 4,
        FLOW_TALK_LEAVE = 5,
        FLOW_TALK_RENAME = 6,
        FLOW_TALK_RESIGN = 7,
        FLOW_TALK_DELETE = 8,
        FLOW_NEW = 9,
        FLOW_MEMBER_LIST = 10,
        FLOW_MEMBER_LIST_REQ = 11,
        FLOW_MEMBER_SUB_MENU = 12,
        FLOW_MEMBER_PROF = 13,
        FLOW_MEMBER_FRIEND_REQ = 14,
        FLOW_MEMBER_INVITE = 15,
        FLOW_MEMBER_TALK = 16,
        FLOW_MEMBER_KICK = 17,
        FLOW_MEMBER_REPORT = 18,
        FLOW_MEMBER_RELEASE = 19,
        FLOW_MEMBER_ATTRIBUTE = 20,
        FLOW_MEMBER_TAG = 21,
        FLOW_MEMBER_PROF_EDIT = 22,
        FLOW_MEMBER_LEAVE = 23,
        FLOW_ADD = 24,
        FLOW_END = 25,
    };
    enum
    {
        MODE_TALK = 0,
        MODE_MEMBER = 1,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
        INPUTEVENT_ADJUST_PAGE = 69,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stTalkItem;
    struct stMemberItem;
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
        s32 mParam_list01;  // offset: 0x4
        s32 mParam_cr_list_y;  // offset: 0x8
        s32 mParam_cr_list_x;  // offset: 0xc
        s32 mParam_cr_list_y01;  // offset: 0x10
    };
public:
    struct stTalkItem
    {
    public:
        stTalkItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullPointer;  // offset: 0x8
        cGUIInstAnimation* mpInstAnim;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimNew;  // offset: 0x18
        cGUIObjMessage* mpObjMsgName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgGroup;  // offset: 0x28
        cGUIObjMessage* mpObjMsgNumber;  // offset: 0x30
        cGUIObjMessage* mpObjMsgState;  // offset: 0x38
        cGUIObjMessage* mpObjMsgDate;  // offset: 0x40
        cGUIObjPolygon* mpObjNullMouseCollision;  // offset: 0x48
        uGUIBase::cReferenceUIIconFriend mIcon;  // offset: 0x50
    };
public:
    struct stMemberItem
    {
    public:
        stMemberItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullPointer;  // offset: 0x8
        cGUIInstNull* mpInstNullSubMenu;  // offset: 0x10
        cGUIInstAnimation* mpInstAnim;  // offset: 0x18
        cGUIObjMessage* mpObjMsgName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgPass;  // offset: 0x28
        cGUIObjMessage* mpObjMsgDate;  // offset: 0x30
        cGUIObjPolygon* mpObjNullMouseCollision;  // offset: 0x38
        cCaplinkProfIconLoader mProfIcon;  // offset: 0x40
        uGUIBase::cReferenceUIIconFriend mIcon;  // offset: 0x60
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNullProfile;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x10
        cGUIObjMessage* mpObjMsgGroupName;  // offset: 0x18
        cGUIObjMessage* mpObjMsgOwnerName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgName;  // offset: 0x28
        cGUIObjMessage* mpObjMsgGroup;  // offset: 0x30
        cGUIObjMessage* mpObjMsgNumber;  // offset: 0x38
        cGUIObjMessage* mpObjMsgState;  // offset: 0x40
        cGUIObjMessage* mpObjMsgDate;  // offset: 0x48
        cGUIObjMessage* mpObjMsgPass;  // offset: 0x50
        cGUIObjMessage* mpObjMsgNotice;  // offset: 0x58
        cGUIObjMessage* mpObjMsgSort;  // offset: 0x60
        cGUIObjMessage* mpObjMsgMemberNum;  // offset: 0x68
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x70
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x108
        uGUIBase::cReferenceUIButton mButton;  // offset: 0x160
        uGUIBase::cReferenceUINumPager mPage;  // offset: 0x2f0
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x3a0
        uGUICaplinkTalk::stTalkItem mTalk[15];  // offset: 0x450
        uGUICaplinkTalk::stMemberItem mMember[8];  // offset: 0xdb0
        static const u32 talk_num = 15;
        static const u32 member_num = 8;
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
    uGUICaplinkTalk();
    virtual ~uGUICaplinkTalk();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setMemberListInfo(s32 id_type, MT_CTSTR id);
    void setNewGroupInfo(MT_CTSTR group_name);
    void setChatInfo(s32 id_type, MT_CTSTR id);
private:
    void setFlowId(u32 flow_id, bool isInit);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void updateGroupData();
    void setupInit();
    void updateInit();
    void initTalkList();
    void setupTalkList();
    void setupTalkListItem(u32 list_index, u32 index);
    void adjustTalkListCursor();
    u32 getListIndex();
    u32 getListOffset();
    u32 getListNum();
    void setTopFlow(bool isInit);
    u32 getTopFlow();
    virtual void returnFlow();  // vtable slot 91
    virtual void returnEnd();  // vtable slot 92
    void initTalkListSubMenu();
    void updateTalkListSubMenu();
    void initNew();
    void updateNew();
    void initMemberList();
    void setupMemberList();
    const nCaplink::cUserBaseInfo* getMemberInfo(u32 index);
    const nCaplink::cUserBaseInfo* getMemberInfo();
    void setupMemberListItem(u32 list_index, u32 index);
    void adjustMemberListCursor();
    void initMemberListReq();
    void updateMemberListReq();
    void initMemberListSubMenu();
    void updateMemberListSubMenu();
    void initKick();
    void updateKick();
    void initProfEdit();
    void updateProfEdit();
    void initAdd();
    void updateAdd();
    void clearList();
    void setupList();
    void initPage(u32 list_num);
    MT_CTSTR getMemberUniqueId();
    MT_CTSTR getNickName();
    void adjustListPage();
    void adjustListCursor();
    void eventDecide();
    void eventCancel();
    void eventAdjustCursor();
    void eventAdjustPage();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustPage(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x978
    u32 mFlowId;  // offset: 0x980
    u32 mSubFlowId;  // offset: 0x984
    stVariable mVar;  // offset: 0x988
    stMain mMain;  // offset: 0x9a0
    u32 mMode;  // offset: 0x1cd0
    u32 mListNum;  // offset: 0x1cd4
    bool mIsSelectList;  // offset: 0x1cd8
    sCaplinkManager::cGroupChatData mGroupData;  // offset: 0x1ce0
    nCaplink::cUserBaseInfo* mpMyInfo;  // offset: 0x1df0
    nCaplink::cUserBaseInfo* mpChatTarget;  // offset: 0x1df8
    MtStringEx<33> mChatId;  // offset: 0x1e00
    s8 mChatIdType;  // offset: 0x1e28
    cControl* mpDecideCtrl;  // offset: 0x1e30
    cControl* mpCancelCtrl;  // offset: 0x1e38
    uGUIBase::cVerticalList* mpListCtrl;  // offset: 0x1e40
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0x1e48
    uGUICaplinkFriendList* mpGUICaplinkFriendList;  // offset: 0x1e50
    uGUICaplinkProfileEdit* mpGUICaplinkProfileEdit;  // offset: 0x1e58
    MtStringEx<128> mTempStr;  // offset: 0x1e60
public:
    static MyDTI DTI;
};
