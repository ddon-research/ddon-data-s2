#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/cUIObject.h"
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
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
namespace nCaplink { class cContentInviteUserInfo; }
namespace nCaplink { class cFriendEntryInfo; }
namespace nCaplink { class cIgnoreUserInfo; }
namespace nCaplink { class cUserBaseInfo; }
class rGUI;
class uGUICaplinkFilter;

// Declarations
class uGUICaplinkFriendList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class uGUICaplinkFriendList : public uGUICaplinkMenuBase
{
public:
    enum
    {
        MODE_NORMAL = 0,
        MODE_NEW_TALK = 1,
        MODE_ADD_TALK = 2,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_INIT = 1,
        FLOW_FRIEND = 2,
        FLOW_FRIEND_FILTER = 3,
        FLOW_FRIEND_SORT = 4,
        FLOW_FRIEND_SUB_MENU = 5,
        FLOW_FRIEND_PROF = 6,
        FLOW_FRIEND_ATTRIBUTE = 7,
        FLOW_FRIEND_TAG = 8,
        FLOW_FRIEND_INVITE = 9,
        FLOW_FRIEND_TALK = 10,
        FLOW_FRIEND_RELEASE = 11,
        FLOW_FRIEND_REPORT = 12,
        FLOW_FRIEND_ADD_TALK = 13,
        FLOW_REQUEST = 14,
        FLOW_REQUEST_REQ = 15,
        FLOW_REQUEST_SUB_MENU = 16,
        FLOW_REQUEST_PROF = 17,
        FLOW_REQUEST_TALK = 18,
        FLOW_REQUEST_CANCEL = 19,
        FLOW_REQUEST_REPORT = 20,
        FLOW_RECEIVE = 21,
        FLOW_RECEIVE_SUB_MENU = 22,
        FLOW_RECEIVE_PROF = 23,
        FLOW_RECEIVE_TALK = 24,
        FLOW_RECEIVE_CONSENT = 25,
        FLOW_RECEIVE_DELETE = 26,
        FLOW_RECEIVE_INVISIBLE = 27,
        FLOW_RECEIVE_REPORT = 28,
        FLOW_IGNORE = 29,
        FLOW_IGNORE_REQ = 30,
        FLOW_IGNORE_SUB_MENU = 31,
        FLOW_IGNORE_PROF = 32,
        FLOW_IGNORE_CANCEL = 33,
        FLOW_IGNORE_TALK = 34,
        FLOW_IGNORE_REPORT = 35,
        FLOW_INVITED = 36,
        FLOW_INVITED_REQ = 37,
        FLOW_INVITED_SUB_MENU = 38,
        FLOW_INVITED_PROF = 39,
        FLOW_INVITED_DELETE = 40,
        FLOW_INVITED_TALK = 41,
        FLOW_INVITED_REPORT = 42,
        FLOW_SEARCH = 43,
        FLOW_SEARCH_SELECT = 44,
        FLOW_SEARCH_INPUT = 45,
        FLOW_SEARCH_WAIT = 46,
        FLOW_SEARCH_SUB_MENU = 47,
        FLOW_SEARCH_PROF = 48,
        FLOW_SEARCH_FRIEND_REQ = 49,
        FLOW_SEARCH_TALK = 50,
        FLOW_SEARCH_REPORT = 51,
        FLOW_SEARCH_ADD_TALK = 52,
        FLOW_END = 53,
    };
    enum
    {
        SORT_NAME = 0,
        SORT_ATTRIBUTE = 1,
        SORT_TAG_NUM = 2,
        SORT_DATE = 3,
        SORT_NUM = 4,
    };
    enum
    {
        SEARCH_MODE_NAME = 0,
        SEARCH_MODE_PATH = 1,
        SEARCH_MODE_NUM = 2,
    };
    enum
    {
        TAB_FRIEND = 0,
        TAB_REQUEST = 1,
        TAB_RECEIVE = 2,
        TAB_IGNORE = 3,
        TAB_INVITED = 4,
        TAB_SEARCH = 5,
        TAB_NUM = 6,
    };
    enum
    {
        BUTTON_LEFT = 0,
        BUTTON_RIGHT = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
        INPUTEVENT_ADJUST_PAGE = 69,
        INPUTEVENT_ADJUST_TAB = 70,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stListItem;
    class cIndex;
public:
    using cDate = sCaplinkManager::cDate;
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
        s32 mParam_cr_txt_x;  // offset: 0x0
        s32 mParam_cr_txt_y;  // offset: 0x4
        s32 mParam_txt00_y;  // offset: 0x8
        s32 mParam_txt00_x;  // offset: 0xc
    };
public:
    struct stListItem
    {
    public:
        stListItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullPointer;  // offset: 0x8
        cGUIInstAnimation* mpInstAnim;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimNew;  // offset: 0x18
        cGUIObjMessage* mpObjMsgName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgPass;  // offset: 0x28
        cGUIObjMessage* mpObjMsgContentName;  // offset: 0x30
        cGUIObjMessage* mpObjMsgDate;  // offset: 0x38
        cGUIObjPolygon* mpObjPolyMouseCollision;  // offset: 0x40
        cCaplinkProfIconLoader mProfIcon;  // offset: 0x48
        uGUIBase::cReferenceUICheckbox mCheckBox;  // offset: 0x68
        uGUIBase::cReferenceUIIconFriend mFriendIcon;  // offset: 0xb8
    };
public:
    class cIndex : public cUIObject
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
        cIndex(u32 index);
        // Address: 0x01ae37d0 - 0x01ae37d1 (1 bytes)
        virtual ~cIndex() {}
    public:
        u64 mSortDate;  // offset: 0x8
        u16 mIndex;  // offset: 0x10
        u8 mSortAttr;  // offset: 0x12
        u8 mSortTag;  // offset: 0x13
        MT_CHAR mName[40];  // offset: 0x14
        static MyDTI DTI;
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNullPointer;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x10
        cGUIObjMessage* mpObjMsgName;  // offset: 0x18
        cGUIObjMessage* mpObjMsgPass;  // offset: 0x20
        cGUIObjMessage* mpObjMsgStatus;  // offset: 0x28
        cGUIObjMessage* mpObjMsgDate;  // offset: 0x30
        cGUIObjMessage* mpObjMsgContent;  // offset: 0x38
        cGUIObjMessage* mpObjMsgNotice;  // offset: 0x40
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x48
        cGUIObjMessage* mpObjMsgSort;  // offset: 0x50
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x60
        uGUIBase::cReferenceUITab mTab;  // offset: 0x110
        uGUIBase::cReferenceUINumPager mPage;  // offset: 0x1c0
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x268
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x300
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0x358
        uGUICaplinkFriendList::stListItem mList[8];  // offset: 0x678
        static const u32 list_num = 8;
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
    uGUICaplinkFriendList();
    virtual ~uGUICaplinkFriendList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void beginSearch();
    void beginNewTalkFriend();
    void beginNewTalkSearch();
    void beginAddTalkFriend(MT_CTSTR unique_id, s32 id_type);
    void beginAddTalkSearch(MT_CTSTR unique_id, s32 id_type);
private:
    void setFlowId(u32 flow_id, bool isInit);
    void setFlowProcess(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupInit();
    void updateInit();
    void adjustListCursor();
    void adjustListPage();
    void clearList();
    void setupList();
    void initPage(u32 num_par_page, bool isReset);
    bool isSelectButton();
    void initFriend();
    void sortFriendList(MtTypedArray<cIndex>& list);
    void setupFriendListItem(stListItem& list, u32 index);
    bool isAlreadyTalking(MT_CTSTR unique_id);
    const sCaplinkManager::cFriendData* getFriendListInfo(u32 index);
    const sCaplinkManager::cFriendData* getFriendListInfo();
    u32 getListIndex();
    u32 getListOffset();
    void initFriendFilter();
    void updateFriendFilter();
    void initFriendSort();
    void updateFriendSort();
    void initFriendSubMenu();
    void updateFriendSubMenu();
    void initRequest();
    void setupRequestListItem(stListItem& list, u32 index);
    const nCaplink::cFriendEntryInfo* getRequestListInfo(u32 index);
    const nCaplink::cFriendEntryInfo* getRequestListInfo();
    void setupRequestReq();
    void updateRequestReq();
    void initRequestSubMenu();
    void updateRequestSubMenu();
    void initReceive();
    void setupReceiveListItem(stListItem& list, u32 index);
    const sCaplinkManager::cFriendRecvData* getReceiveListInfo(u32 index);
    const sCaplinkManager::cFriendRecvData* getReceiveListInfo();
    void initReceiveSubMenu();
    void updateReceiveSubMenu();
    void initIgnore();
    void setupIgnoreListItem(stListItem& list, u32 index);
    const nCaplink::cIgnoreUserInfo* getIgnoreListInfo(u32 index);
    const nCaplink::cIgnoreUserInfo* getIgnoreListInfo();
    void setupIgnoreReq();
    void updateIgnoreReq();
    void initIgnoreSubMenu();
    void updateIgnoreSubMenu();
    void initInvited();
    void setupInvitedListItem(stListItem& list, u32 index);
    const nCaplink::cContentInviteUserInfo* getInvitedListInfo(u32 index);
    const nCaplink::cContentInviteUserInfo* getInvitedListInfo();
    void setupInvitedReq();
    void updateInvitedReq();
    void initInvitedSubMenu();
    void updateInvitedSubMenu();
    void initInvitedDelete();
    void updateInvitedDelete();
    void initSearch();
    void initSearchList();
    void setupSearchListItem(stListItem& list, u32 index);
    const nCaplink::cUserBaseInfo* getSearchListInfo(u32 index);
    const nCaplink::cUserBaseInfo* getSearchListInfo();
    void initSearchSelect();
    void updateSearchSelect();
    void initSearchInput();
    void updateSearchInput();
    void initSearchWait();
    void updateSearchWait();
    void initSearchSubMenu();
    void updateSearchSubMenu();
    MT_CTSTR getUniqueId();
    MT_CTSTR getNickName();
    void initRequestCancel();
    void updateRequestCancel();
    void initReceiveConsent();
    void updateReceiveConsent();
    void initReceiveDelete();
    void updateReceiveDelete();
    void initReceiveInvisible();
    void updateReceiveInvisible();
    void initIgnoreCancel();
    void updateIgnoreCancel();
    u32 getTopFlow();
    void setTopFlow(bool isInit);
    virtual void returnFlow();  // vtable slot 91
    virtual void returnEnd();  // vtable slot 92
    void setTab(u32 pos);
    MT_CTSTR getDateStr(MT_CTSTR date);
    MT_CTSTR getDateStr(const cDate& date);
    void eventDecide();
    void eventCancel();
    void eventAdjustCursor();
    void eventAdjustPage();
    void eventAdjustTab();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustPage(cControl::Message* msg);
    u32 evCtrlAdjustTab(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x978
    u32 mMode;  // offset: 0x980
    u32 mFlowId;  // offset: 0x984
    u32 mRequestFlowId;  // offset: 0x988
    u32 mSortNo;  // offset: 0x98c
    u32 mSearchMode;  // offset: 0x990
    u32 mButtonNum;  // offset: 0x994
    bool mIsSelectButton;  // offset: 0x998
    s32 mIdType;  // offset: 0x99c
    MtStringEx<33> mGroupId;  // offset: 0x9a0
    MtStringEx<33> mContentId;  // offset: 0x9c8
    MtStringEx<257> mContentName;  // offset: 0x9f0
    stVariable mVar;  // offset: 0xaf8
    stMain mMain;  // offset: 0xb10
    MtTypedArray<cIndex> mIndexList;  // offset: 0x19d0
    cControl* mpDecideCtrl;  // offset: 0x19f0
    cControl* mpCancelCtrl;  // offset: 0x19f8
    uGUIBase::cVerticalList* mpListCtrl;  // offset: 0x1a00
    uGUIBase::cHorizontalList* mpButtonCtrl;  // offset: 0x1a08
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0x1a10
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x1a18
    uGUICaplinkFilter* mpGUICaplinkFilter;  // offset: 0x1a20
    MtStringEx<128> mTempStr;  // offset: 0x1a28
public:
    static MyDTI DTI;
};
