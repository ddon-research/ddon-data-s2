#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cControl.h"
#include "../shared/nCharacterData.h"
#include "nMenu.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class CDataCommunityCharacterBaseInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstNull;
class cGUIInstance;
class cGUIObject;
class cMenuActiveList;
class cMenuBase;
class cMenuBlackList;
class cMenuFriendList;
class cMenuRecentList;
namespace nCharacterData { struct stCharacterName; }
class rGUI;
class rGUIMessage;
class sGUIExt;

// Declarations
class uGUICommunityList;

// Type aliases from DWARF
using CHAR_NAME = nCharacterData::stCharacterName;
using CommunityCharacterBaseInfoVec = MtTypedArray<CDataCommunityCharacterBaseInfo>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICommunityList : public uGUIBase
{
    // inferred: sGUIExt::reqCloseCommunityList names uGUICommunityList::mReqClose
    friend class sGUIExt;
public:
    enum
    {
        INPUTEVENT_INIT = 66,
        INPUTEVENT_TAB_LEFT = 67,
        INPUTEVENT_TAB_RIGHT = 68,
        INPUTEVENT_UPDATECURSOR = 69,
        INPUTEVENT_DISP_MODE_CHANGE = 70,
        INPUTEVENT_DECIDE = 71,
        INPUTEVENT_CANCEL = 72,
        INPUTEVENT_LIST_UPDATE = 73,
        INPUTEVENT_UP = 74,
        INPUTEVENT_DOWN = 75,
        INPUTEVENT_LEFT = 76,
        INPUTEVENT_RIGHT = 77,
    };
    enum ROUTINE_NO
    {
        R_NO_COM_WAIT = 0,
        R_NO_MAIN_LOOP = 1,
        R_NO_END = 2,
        R_NO_MAX = 3,
    };
    enum EX_END_TYPE
    {
        NORMAL = 0,
        CANCEL = 1,
        SUCCESS = 2,
        EX_END_TYPE_MAX = 3,
    };
    enum MODE
    {
        FRIEND_LIST = 0,
        ACTIVE_LIST = 1,
        NEAR_PLAYER = 2,
        BLACK_LIST = 3,
        TAB_NUM = 4,
    };
    enum ACTIVE_MODE_BIT
    {
        FRIEND_LIST_BIT = 1,
        ACTIVE_LIST_BIT = 2,
        NEAR_PLAYER_BIT = 4,
        BLACK_LIST_BIT = 8,
        ALL_TAB_BIT = 15,
    };
    enum ACTION_RSTRICT_BIT
    {
        TELL_ONLY_BIT = 1,
        CTRL_CHAT_BIT = 2,
        GET_CHAR_INFO_BIT = 4,
        NORMAL_BIT = 0,
    };
public:
    class MyDTI;
    class cTabData;
    class cTabDataInData;
    class cScrollDispList;
    class cScrollItemList;
    class cTabDataFriendList;
    class cTabDataActiveList;
    class cTabDataNearPlayerList;
    class cTabDataBlackList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTabDataInData : public MtObject
    {
    public:
        enum DISP_PATTERN
        {
            DEFAULT = 0,
            APPLY = 1,
            CONFIRM = 2,
            CATEGORY = 3,
        };
        enum ADD_INFO
        {
            INFO_NONE = 0,
            INFO_FRIEND = 1,
            INFO_CLAN = 2,
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
        cTabDataInData();
        // Address: 0x01aeeeb0 - 0x01aeeeb1 (1 bytes)
        virtual ~cTabDataInData() {}
        void clearData();
        void setInstancePointer(cGUIInstNull* pInst);
        cGUIInstance* getInstancePointer(cGUIInstNull* pInst, u32 instId);
        void reflectMessage();
        void copyInstanceExecuteFlag();
        void reflectIcon();
        void switchCommentUnion(bool IsComment);
        void referenceSetup();
        MT_CTSTR getGMDMessage(u32 GmdIdx);
    public:
        uGUICommunityList* mpOwner;  // offset: 0x8
        cGUIInstNull* mpInst;  // offset: 0x10
        cGUIInstance* mpInstMesList00;  // offset: 0x18
        cGUIInstance* mpInstFixIcon;  // offset: 0x20
        cGUIObject* mpObjMouseOver;  // offset: 0x28
        u32 mOwnerTabId;  // offset: 0x30
        MT_CHAR mpName[256];  // offset: 0x34
        u32 mJob;  // offset: 0x134
        u32 mLv;  // offset: 0x138
        u32 mServer;  // offset: 0x13c
        u32 mLobby;  // offset: 0x140
        MT_CHAR mpComment[256];  // offset: 0x144
        MT_CHAR mpUnion[256];  // offset: 0x244
        bool mIsFavorite;  // offset: 0x344
        bool mIsDisable;  // offset: 0x345
        u32 mOnlineStatus;  // offset: 0x348
        u32 mDispPattern;  // offset: 0x34c
        u32 mListType;  // offset: 0x350
        s32 mAddInfo;  // offset: 0x354
        uGUIBase::cReferenceUIIconOnlineStatus mOnlineStatusIcon;  // offset: 0x358
        static const u32 STR_MAX_LENGTH = 256;
        static MyDTI DTI;
    };
public:
    class cScrollDispList : public uGUIBase::cScrollListItemBase
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
        cScrollDispList();
        // Address: 0x01aeea60 - 0x01aeea61 (1 bytes)
        virtual ~cScrollDispList() {}
    public:
        cGUIInstNull* mpInstance;  // offset: 0x58
        uGUICommunityList::cTabDataInData* mpInData;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    class cScrollItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollItemList();
        cScrollItemList(f32 Top, f32 Bottom, u32 index, u32 listType);
        // Address: 0x01aeea80 - 0x01aeea81 (1 bytes)
        virtual ~cScrollItemList() {}
    public:
        u32 mIndex;  // offset: 0x28
        s32 mListType;  // offset: 0x2c
        static MyDTI DTI;
    };
public:
    class cTabData : public MtObject
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
        cTabData();
        virtual ~cTabData();
        virtual void init();  // vtable slot 6
        virtual nMenu::MENU_RET move();  // vtable slot 7
        virtual u32 getDispDataNum();  // vtable slot 8
        virtual u32 getMakeArrayDataNum();  // vtable slot 9
        u32 getCursorXSize();
        u32 getCursorYSize();
        void setFlowId(u32 set);
        u32 getFlowId();
        void setOwner(uGUICommunityList* set);
        uGUICommunityList* getOwner();
        void createScrollList();
        virtual void updateScrollList();  // vtable slot 10
        void setFocus(bool flag);
        uGUICommunityList::cTabDataInData* getDataArray(u32 index);
        u32 getDataArrayNum();
        void setData();
        // Address: 0x01aee3f0 - 0x01aee3f1 (1 bytes)
        virtual void setDisplay() {}  // vtable slot 11
        virtual void copyExecuteFlag();  // vtable slot 12
        void createData(u32 tabIndex);
        virtual void linkInstancePointer(u32 DataPos, cGUIInstNull* pInst);  // vtable slot 13
        virtual void referenceSetup();  // vtable slot 14
        // Address: 0x01aee400 - 0x01aee401 (1 bytes)
        virtual void setInDataParam(uGUICommunityList::cTabDataInData* pInData, s32 listType, u32 listIndex) {}  // vtable slot 15
        // Address: 0x01aee410 - 0x01aee411 (1 bytes)
        virtual void setNoListMessage() {}  // vtable slot 16
        void switchCommentUnion(bool IsComment);
        void setComment(MT_STR pDst, MT_CTSTR pSrc);
        cMenuFriendList* getMenuFriendList();
        cMenuActiveList* getMenuActiveList();
        cMenuRecentList* getMenuRecentList();
        cMenuBlackList* getMenuBlackList();
        virtual bool isMenuListCompListup();  // vtable slot 17
        virtual s32 getSMenuCursorX();  // vtable slot 18
        virtual s32 getSMenuCursorY();  // vtable slot 19
        virtual bool getRemakeListFlag();  // vtable slot 20
        virtual cMenuBase* getMyMenu();  // vtable slot 21
        virtual u32 getListCount();  // vtable slot 22
        virtual u32 getListIndex(u32 index);  // vtable slot 23
        virtual s32 getListType(u32 index);  // vtable slot 24
        bool isMenuListBusy();
        MT_CTSTR getGMDMessage(u32 GmdIdx);
    private:
        uGUICommunityList* mpOwner;  // offset: 0x8
        u32 mFlowId;  // offset: 0x10
        MtTypedArray<uGUICommunityList::cTabDataInData> mDataArray;  // offset: 0x18
    public:
        uGUIBase::cScrollList mScrollList;  // offset: 0x40
        uGUICommunityList::cScrollDispList mScrollDispList[15];  // offset: 0x2f0
        static MyDTI DTI;
    };
public:
    class cTabDataFriendList : public uGUICommunityList::cTabData
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
        cTabDataFriendList();
        virtual ~cTabDataFriendList();
        virtual void init();  // vtable slot 6
        virtual nMenu::MENU_RET move();  // vtable slot 7
        virtual u32 getMakeArrayDataNum();  // vtable slot 9
        virtual bool isMenuListCompListup();  // vtable slot 17
        virtual void setInDataParam(uGUICommunityList::cTabDataInData* pInData, s32 listType, u32 listIndex);  // vtable slot 15
        virtual void setNoListMessage();  // vtable slot 16
        virtual bool getRemakeListFlag();  // vtable slot 20
        virtual cMenuBase* getMyMenu();  // vtable slot 21
        virtual u32 getListCount();  // vtable slot 22
        virtual u32 getListIndex(u32 index);  // vtable slot 23
        virtual s32 getListType(u32 index);  // vtable slot 24
    public:
        static MyDTI DTI;
    };
public:
    class cTabDataActiveList : public uGUICommunityList::cTabData
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
        cTabDataActiveList();
        virtual ~cTabDataActiveList();
        virtual void init();  // vtable slot 6
        virtual nMenu::MENU_RET move();  // vtable slot 7
        virtual u32 getMakeArrayDataNum();  // vtable slot 9
        virtual bool isMenuListCompListup();  // vtable slot 17
        virtual void setInDataParam(uGUICommunityList::cTabDataInData* pInData, s32 listType, u32 listIndex);  // vtable slot 15
        virtual void setNoListMessage();  // vtable slot 16
        virtual void updateScrollList();  // vtable slot 10
        virtual bool getRemakeListFlag();  // vtable slot 20
        virtual cMenuBase* getMyMenu();  // vtable slot 21
        virtual u32 getListCount();  // vtable slot 22
        virtual u32 getListIndex(u32 index);  // vtable slot 23
        virtual s32 getListType(u32 index);  // vtable slot 24
    public:
        static const u32 CATEGORY_NUM = 4;
        static MyDTI DTI;
    };
public:
    class cTabDataNearPlayerList : public uGUICommunityList::cTabData
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
        cTabDataNearPlayerList();
        virtual ~cTabDataNearPlayerList();
        virtual void init();  // vtable slot 6
        virtual nMenu::MENU_RET move();  // vtable slot 7
        virtual u32 getMakeArrayDataNum();  // vtable slot 9
        virtual void linkInstancePointer(u32 DataPos, cGUIInstNull* pInst);  // vtable slot 13
        virtual bool isMenuListCompListup();  // vtable slot 17
        virtual void setInDataParam(uGUICommunityList::cTabDataInData* pInData, s32 listType, u32 listIndex);  // vtable slot 15
        virtual void setNoListMessage();  // vtable slot 16
        virtual bool getRemakeListFlag();  // vtable slot 20
        virtual cMenuBase* getMyMenu();  // vtable slot 21
        virtual u32 getListCount();  // vtable slot 22
        virtual u32 getListIndex(u32 index);  // vtable slot 23
    public:
        static const u32 LIST_VERTICAL_NUM;
        static MyDTI DTI;
    };
public:
    class cTabDataBlackList : public uGUICommunityList::cTabData
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
        cTabDataBlackList();
        virtual ~cTabDataBlackList();
        virtual void init();  // vtable slot 6
        virtual nMenu::MENU_RET move();  // vtable slot 7
        virtual u32 getMakeArrayDataNum();  // vtable slot 9
        virtual void linkInstancePointer(u32 DataPos, cGUIInstNull* pInst);  // vtable slot 13
        virtual bool isMenuListCompListup();  // vtable slot 17
        virtual void setInDataParam(uGUICommunityList::cTabDataInData* pInData, s32 listType, u32 listIndex);  // vtable slot 15
        virtual void setNoListMessage();  // vtable slot 16
        virtual bool getRemakeListFlag();  // vtable slot 20
        virtual cMenuBase* getMyMenu();  // vtable slot 21
        virtual u32 getListCount();  // vtable slot 22
        virtual u32 getListIndex(u32 index);  // vtable slot 23
    public:
        static const u32 LIST_VERTICAL_NUM;
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
    uGUICommunityList(u32 Mode, u32 ActiveModeBit, u32 ActionRestrictBit, bool isChatSubMenu);
    virtual ~uGUICommunityList();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getExEndType();
    CHAR_NAME& getDstCharName();
    u32 getDstCharacterId();
    void setExcludeList(CommunityCharacterBaseInfoVec* pExcludeList);
    void reqCloseUI();
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlTabLeft(cControl::Message* msg);
    void tabLeft();
    u32 evCtrlTabRight(cControl::Message* msg);
    void tabRight();
    void setTabPos();
    void evCtrlTabCommon();
    u32 evCtrlDispModeChange(cControl::Message* msg);
    void changeDispMode();
    void setDispMode(bool mode);
    bool getDispMode();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    void createDisplay();
    void createTabData();
    void initScrollList(cTabData* pTabData);
    void updateScrollList(cTabData* pTabData);
    void updateScrollListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem);
    bool isExclude(u32 characterId);
    void createCtrl();
    void setFixedMessage();
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
    void loop();
    rGUIMessage* getMessageRes();
    MT_CTSTR getGMDMessage(u32 GmdIdx);
private:
    u32 mRoNo;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    rGUIMessage* mpGMDComList;  // offset: 0x8d8
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x8e0
    uGUIBase::cReferenceUITab mTab;  // offset: 0x8f0
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x9a0
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0xa38
    s32 mTabPos;  // offset: 0xa90
    s32 mOldTabPos;  // offset: 0xa94
    u32 mTabNum;  // offset: 0xa98
    MtTypedArray<cTabData> mTabData;  // offset: 0xaa0
    u32 mModeBit;  // offset: 0xac0
    u32 mActionRestrictBit;  // offset: 0xac4
    u32 mExEndType;  // offset: 0xac8
    bool mDispMode;  // offset: 0xacc
    bool mReqClose;  // offset: 0xacd
    bool mClearFlag;  // offset: 0xace
    CHAR_NAME mDstName;  // offset: 0xacf
    u32 mDstCharacterId;  // offset: 0xae8
    CommunityCharacterBaseInfoVec* mpExcludeList;  // offset: 0xaf0
public:
    static const u32 LIST_NUM = 15;
    static const f32 LIST_HEIGHT;
    static const f32 COM_LIMIT_FRAME;
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rGUIMessage* uGUICommunityList::getMessageRes() {
    return this->mpGMDComList;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUICommunityList::cTabDataInData::cTabDataInData() {
    this->mOwnerTabId = static_cast<u32>(0);
    this->mpName[0] = static_cast<char>(0);
    this->mJob = static_cast<u32>(0);
    this->mpInstFixIcon = static_cast<cGUIInstance*>(nullptr);
    this->mpInstMesList00 = static_cast<cGUIInstance*>(nullptr);
    this->mpInst = static_cast<cGUIInstNull*>(nullptr);
    this->mpOwner = static_cast<uGUICommunityList*>(nullptr);
    this->mLv = static_cast<u32>(1);
    this->mServer = static_cast<u32>(0);
    this->mLobby = static_cast<u32>(0);
    this->mpComment[0] = static_cast<char>(0);
    this->mpUnion[0] = static_cast<char>(0);
    this->mIsFavorite = false;
    this->mIsDisable = false;
    this->mOnlineStatus = static_cast<u32>(0);
    this->mDispPattern = static_cast<u32>(0);
    this->mAddInfo = static_cast<s32>(0);
}
