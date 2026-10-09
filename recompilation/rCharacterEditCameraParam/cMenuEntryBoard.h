#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/EntryBoard.h"
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/cCharacterData.h"
#include "cMenuBase.h"
#include "nMenu.h"
#include "../shared/nNet.h"

// Forward declarations
class CDataEntryMemberData;
class CDataEntryRecruitData;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtVector3;
class cGUIContentsExecutor;
class cMenuSupportMenu;
namespace nMenu { struct MENU_PARTS; }
namespace nNet { struct stEntryBoardItemInfo; }
class uGUIDialogTextBox;

// Declarations
class cMenuContentsExecutor;
class cMenuCreateEntryBoardItem;
class cMenuEditCommentEntryBoardItem;
class cMenuEntryBoardInvite;
class cMenuEntryBoardItem;
class cMenuEntryBoardItemList;
class cMenuEntryBoardMember;
class cMenuEntryBoardRecruit;
class cMenuExtendEntryBoardItem;
class cMenuGetEntryBoardItem;
class cMenuInviteEntryBoardItem;
class cMenuJoinEntryBoardItem;
class cMenuLeaveEntryBoardItem;
class cMenuReadyEntryBoardItem;
class cMenuRecreateEntryBoardItem;
class cMenuReleasePassEntryBoardItem;
class cMenuStartEntryBoardItem;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cMenuContentsExecutor : public cMenuBase
{
public:
    enum CONTENTS_OPEN_TYPE
    {
        NPC_OPEN = 0,
        MENU_OPEN = 1,
        NEWS_PAPER_OPEN = 2,
        INVITATION_OPEN = 3,
    };
    enum CONTENTS_TYPE
    {
        NONE_CONTENTS_TYPE = -1,
        CYCLE_CONTENTS_TYPE = 0,
        END_CONTENTS_TYPE = 1,
        CONTENTS_TYPE_MAX = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_CYCLE_LIST_REQ = 1,
        RNO_CYCLE_LIST_WAIT = 2,
        RNO_CYCLE_COPY = 3,
        RNO_END_LIST_REQ = 4,
        RNO_END_LIST_WAIT = 5,
        RNO_END_LIST_WAIT2 = 6,
        RNO_END_LOAD = 7,
        RNO_CREATE = 8,
        RNO_WAIT = 9,
        RNO_ERROR = 10,
    };
    enum
    {
        CONTENTS_EXECUTOR_RNO_BASE = 0,
        CONTENTS_EXECUTOR_RNO_MAX = 1,
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
    cMenuContentsExecutor();
    virtual ~cMenuContentsExecutor();
    void initContentsExecutor(CONTENTS_TYPE contentsType, CONTENTS_OPEN_TYPE openType, u32 contentsScheduleId);
    nMenu::MENU_RET moveContentsExecutor();
    virtual void exitMenu();  // vtable slot 15
    bool settingScheduleQuestID();
private:
    cGUIContentsExecutor* mpGUIContentsExecutor;  // offset: 0xb0
    nNetSv::E_CONTENT_TYPE mContentsType;  // offset: 0xb8
    CONTENTS_OPEN_TYPE mOpenType;  // offset: 0xbc
    u32 mContentsScheduleId;  // offset: 0xc0
    u32 mNpcId;  // offset: 0xc4
public:
    static MyDTI DTI;
};

class cMenuCreateEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        MOVE_CREATE_ENTRY_BOARD_ITEM_RNO_INIT = 0,
        MOVE_CREATE_ENTRY_BOARD_ITEM_RNO_MENU = 1,
    };
    enum
    {
        CREATE_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        CREATE_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuCreateEntryBoardItem();
    virtual ~cMenuCreateEntryBoardItem();
    void initCreateEntryBoardItem(u64 boardId, bool solo);
    nMenu::MENU_RET moveCreateEntryBoardItem();
    virtual void exitMenu();  // vtable slot 15
private:
    s32 getRno();
private:
    u64 mBoardId;  // offset: 0xb0
    bool mIsSolo;  // offset: 0xb8
    nNet::stEntryBoardItemInfo mBoardInfo;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuEditCommentEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_WAIT = 2,
        RNO_RESULT = 3,
        RNO_ERROR = 4,
    };
    enum
    {
        EDIT_COMMENT_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        EDIT_COMMENT_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuEditCommentEntryBoardItem();
    virtual ~cMenuEditCommentEntryBoardItem();
    void initEditCommentEntryBoardItem();
    nMenu::MENU_RET moveEditCommentEntryBoardItem();
    virtual void exitMenu();  // vtable slot 15
    virtual void updatePtr();  // vtable slot 6
private:
    s32 leaveRno();
private:
    uGUIDialogTextBox* mpDlTextBox;  // offset: 0xb0
    MtString mComment;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuEntryBoardInvite : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        ENTRY_BOARD_INVITE_RNO_BASE = 0,
        ENTRY_BOARD_INVITE_RNO_MAX = 1,
    };
    enum
    {
        INVITE_TYPE_CHARACTER = 0,
        INVITE_TYPE_PARTY = 1,
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
    cMenuEntryBoardInvite();
    virtual ~cMenuEntryBoardInvite();
    void initEntryBoardInvite(s32 type, u32 characterId, MtString& firstName, MtString& lastName);
    nMenu::MENU_RET moveEntryBoardInvite();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 getNextMember(s32& index);
private:
    s32 mType;  // offset: 0xb0
    u32 mCharacterId;  // offset: 0xb4
    MtString mFirstName;  // offset: 0xb8
    MtString mLastName;  // offset: 0xc0
    s32 mInviteIndex;  // offset: 0xc8
public:
    static MyDTI DTI;
};

class cMenuEntryBoardItem : public cMenuBase
{
public:
    enum TYPE
    {
        ENTRY_BOARD_ITEM_TYPE_CREATE = 0,
        ENTRY_BOARD_ITEM_TYPE_INFO = 1,
        ENTRY_BOARD_ITEM_TYPE_JOIN = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
        RNO_RECOMMEND = 2,
        RNO_PASSWORD = 3,
        RNO_JOBLEVEL = 4,
        RNO_COMMENT = 5,
        RNO_RECRUIT = 6,
        RNO_MEMBER = 7,
        RNO_CREATE = 8,
        RNO_JOIN = 9,
        RNO_SET_MESSAGE = 10,
        RNO_CREATE_ERR = 11,
    };
    enum
    {
        ENTRY_BOARD_ITEM_RNO_BASE = 0,
        ENTRY_BOARD_ITEM_RNO_MAX = 1,
    };
    enum
    {
        ENTRY_BOARD_ITEM_PASSWORD = 0,
        ENTRY_BOARD_ITEM_PASSWORD_SETTING = 1,
        ENTRY_BOARD_ITEM_PAWN = 2,
        ENTRY_BOARD_ITEM_JOBLEVEL = 3,
        ENTRY_BOARD_ITEM_JOBLEVEL_MIN = 4,
        ENTRY_BOARD_ITEM_JOBLEVEL_MAX = 5,
        ENTRY_BOARD_ITEM_JOBLEVEL_SETTING = 6,
        ENTRY_BOARD_ITEM_COMMENT = 7,
        ENTRY_BOARD_ITEM_RECRUIT_SETTING = 8,
        ENTRY_BOARD_ITEM_RECRUIT = 9,
        ENTRY_BOARD_ITEM_MEMBER = 10,
        ENTRY_BOARD_ITEM_RECOMMEND = 11,
        ENTRY_BOARD_ITEM_ITEMRANK_SETTING = 12,
        ENTRY_BOARD_ITEM_ITEMRANK_TYPE = 13,
        ENTRY_BOARD_ITEM_ITEMRANK_MIN = 14,
        ENTRY_BOARD_ITEM_ITEMRANK_ROLL = 15,
        ENTRY_BOARD_ITEM_DECIDE = 16,
        ENTRY_BOARD_ITEM_CANCEL = 17,
        ENTRY_BOARD_ITEM_JOIN = 18,
        ENTRY_BOARD_ITEM_RETURN = 19,
        ENTRY_BOARD_ITEM_MAX = 20,
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
    cMenuEntryBoardItem();
    virtual ~cMenuEntryBoardItem();
    void initEntryBoardItem(u64 boardId, s32 type, nNet::stEntryBoardItemInfo& info, bool solo);
    nMenu::MENU_RET moveEntryBoardItem();
    TYPE getType();
    nNet::stEntryBoardItemInfo* getBoardInfo();
    void setRecruitNo(s32 n);
    s32 getRecruitNo();
    virtual void exitMenu();  // vtable slot 15
    const MtVector3& getPopRecruitPos();
    void setPopRecruitPos(const MtVector3& pos);
    void setJobLimitLvMin(s32);
    s32 getJobLimitLvMin();
    void setJobLimitLvMax(s32);
    s32 getJobLimitLvMax();
    s32 calcJoinMemberNum();
    s32 getRno();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    void setCursor(s32);
private:
    u64 mBoardId;  // offset: 0xb0
    s32 mType;  // offset: 0xb8
    nNet::stEntryBoardItemInfo* mpBoardInfo;  // offset: 0xc0
    MtString mPassword;  // offset: 0xc8
    MtString mComment;  // offset: 0xd0
    s32 mRecruitNo;  // offset: 0xd8
    s32 mJobLvMin;  // offset: 0xdc
    s32 mJobLvMax;  // offset: 0xe0
    MtVector3 mPopRecruitPos;  // offset: 0xf0
    bool mIsSolo;  // offset: 0x100
public:
    static MyDTI DTI;
};

class cMenuEntryBoardItemList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST = 3,
        RNO_CREATE = 4,
        RNO_JOIN = 5,
        RNO_SEARCH_FILTER = 6,
        RNO_DETAIL = 7,
        RNO_LIST_ERROR = 8,
    };
    enum
    {
        ENTRY_BOARD_ITEM_RNO_BASE = 0,
        ENTRY_BOARD_ITEM_RNO_MAX = 1,
    };
    enum
    {
        ENTRY_BOARD_ITEM_TOP = 0,
        ENTRY_BOARD_ITEM_CREATE = 7,
        ENTRY_BOARD_ITEM_SEARCH_SETTING = 8,
        ENTRY_BOARD_ITEM_MAX = 9,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        CREATE_ERR_QUICK_PARTY = 1,
        JOIN_ERR_QUICK_PARTY = 2,
        JOIN_ERR_NOT_MATCH_ORDER = 3,
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
    cMenuEntryBoardItemList();
    virtual ~cMenuEntryBoardItemList();
    void initEntryBoardItemList(u64 boardId, bool solo);
    nMenu::MENU_RET moveEntryBoardItemList();
    virtual void exitMenu();  // vtable slot 15
    nNet::stEntryBoardItemInfo& getBoardInfo();
    cCharacterData::stSearchFilterSetting& getSearchSetting();
    const MtVector3& getRecruitPos();
    const MtVector3& getSearchPos();
    void setRecruitPos(const MtVector3& pos);
    void setSearchPos(const MtVector3& pos);
    bool isJumpMemberList();
    void setupReturnList();
    bool isBeforeSearch();
    void setEnableCtrl(bool flg);
    s32 getRno();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    u64 mBoardId;  // offset: 0xb0
    nNet::stEntryBoardItemInfo mBoardInfo;  // offset: 0xb8
    cCharacterData::stSearchFilterSetting mSearchSetting;  // offset: 0x198
    MtVector3 mRecruitPos;  // offset: 0x2d0
    MtVector3 mSearchPos;  // offset: 0x2e0
    bool mbJumpMemberList;  // offset: 0x2f0
    bool mbReturnList;  // offset: 0x2f1
    bool mBeforeSearch;  // offset: 0x2f2
    bool mbEnableCtrl;  // offset: 0x2f3
    bool mIsSolo;  // offset: 0x2f4
public:
    static MyDTI DTI;
    static const s32 ENTRY_BOARD_ITEM_DISP_NUM = 7;
    static const s32 BOARD_ITEM_SORT_LIST_MAX = 100;
};

class cMenuEntryBoardMember : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_DETAIL_MEMBER = 2,
        RNO_DETAIL_RECRUIT = 3,
    };
    enum
    {
        ENTRY_BOARD_MEMBER_RNO_BASE = 0,
        ENTRY_BOARD_MEMBER_RNO_MAX = 1,
    };
    enum
    {
        ENTRY_BOARD_MEMBER_LEADER = 0,
        ENTRY_BOARD_MEMBER_NUM = 10,
        ENTRY_BOARD_MEMBER_MAX = 11,
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
    cMenuEntryBoardMember();
    virtual ~cMenuEntryBoardMember();
    void initEntryBoardMember(MtTypedArray<CDataEntryMemberData>& MemberList, MtTypedArray<CDataEntryRecruitData>& RecruitList, u32 num);
    nMenu::MENU_RET moveEntryBoardMember();
    virtual void exitMenu();  // vtable slot 15
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    void setCursor(s32);
    s32 getRno();
private:
    MtTypedArray<CDataEntryMemberData>* mpMemberData;  // offset: 0xb0
    MtTypedArray<CDataEntryRecruitData>* mpRecruitData;  // offset: 0xb8
    u32 mJob;  // offset: 0xc0
    u32 mNum;  // offset: 0xc4
    s32 mMenuTbl[11];  // offset: 0xc8
public:
    static MyDTI DTI;
};

class cMenuEntryBoardRecruit : public cMenuBase
{
public:
    enum
    {
        MOVE_ENTRY_BOARD_RECRUIT_RNO_INIT = 0,
        MOVE_ENTRY_BOARD_RECRUIT_RNO_SELECT = 1,
        MOVE_ENTRY_BOARD_RECRUIT_RNO_DETAIL = 2,
    };
    enum
    {
        ENTRY_BOARD_RECRUIT_RNO_BASE = 0,
        ENTRY_BOARD_RECRUIT_RNO_MAX = 1,
    };
    enum
    {
        ENTRY_BOARD_RECRUIT_LEADER = 0,
        ENTRY_BOARD_RECRUIT_NUM = 10,
        ENTRY_BOARD_RECRUIT_DECIDE = 11,
        ENTRY_BOARD_RECRUIT_CANCEL = 12,
        ENTRY_BOARD_RECRUIT_MAX = 13,
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
    cMenuEntryBoardRecruit();
    virtual ~cMenuEntryBoardRecruit();
    void initEntryBoardRecruit(MtTypedArray<CDataEntryRecruitData>& RecruitList, u32 num, s32 start);
    nMenu::MENU_RET moveEntryBoardRecruit();
    void refreshEntryBoardRecruit(MtTypedArray<CDataEntryRecruitData>& RecruitList, s32 start);
    virtual void exitMenu();  // vtable slot 15
    void setJobBit(u32 no, u32 jobBit);
    void activeCheck();
    void setStartIndex(s32 index);
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    void setCursor(s32);
    s32 getRno();
private:
    MtTypedArray<CDataEntryRecruitData>* mpDstRecruitData;  // offset: 0xb0
    MtTypedArray<CDataEntryRecruitData> mRecruitData;  // offset: 0xb8
    u32 mJob;  // offset: 0xd8
    u32 mNum;  // offset: 0xdc
    s32 mStartIndex;  // offset: 0xe0
public:
    static MyDTI DTI;
};

class cMenuExtendEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
        RNO_ERROR = 2,
    };
    enum
    {
        EXTEND_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        EXTEND_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuExtendEntryBoardItem();
    virtual ~cMenuExtendEntryBoardItem();
    void initExtendEntryBoardItem();
    nMenu::MENU_RET moveExtendEntryBoardItem();
public:
    static MyDTI DTI;
};

class cMenuGetEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_ERROR = 3,
    };
    enum
    {
        GET_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        GET_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuGetEntryBoardItem();
    virtual ~cMenuGetEntryBoardItem();
    void initGetEntryBoardItem(u64 boardId, u32 entryId, nNet::stEntryBoardItemInfo* pDstInfo, bool serverIn);
    nMenu::MENU_RET moveGetEntryBoardItem();
    virtual void exitMenu();  // vtable slot 15
private:
    s32 getRno();
private:
    nNet::stEntryBoardItemInfo* mpBoardInfo;  // offset: 0xb0
    u64 mBoardId;  // offset: 0xb8
    u32 mEntryId;  // offset: 0xc0
    bool mServerIn;  // offset: 0xc4
public:
    static MyDTI DTI;
};

class cMenuInviteEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ_WAIT = 1,
        RNO_WAIT = 2,
        RNO_JOIN_WAIT = 3,
    };
    enum
    {
        INVITE_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        INVITE_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuInviteEntryBoardItem();
    virtual ~cMenuInviteEntryBoardItem();
    void initInviteEntryBoardItem(nNet::stEntryBoardItemInfo* pDstInfo);
    nMenu::MENU_RET moveInviteEntryBoardItem();
    virtual void exitMenu();  // vtable slot 15
    bool isJumpMemberList();
    s32 getRno();
private:
    nNet::stEntryBoardItemInfo* mpBoardInfo;  // offset: 0xb0
    u64 mBoardId;  // offset: 0xb8
    u32 mEntryId;  // offset: 0xc0
    bool mIsJumpMemberList;  // offset: 0xc4
    bool mIsActiveOld;  // offset: 0xc5
public:
    static MyDTI DTI;
};

class cMenuJoinEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
        RNO_PASSWORD = 1,
    };
    enum
    {
        JOIN_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        JOIN_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuJoinEntryBoardItem();
    virtual ~cMenuJoinEntryBoardItem();
    void initJoinEntryBoardItem(u64 boardId, u32 itemId, bool isPassword);
    nMenu::MENU_RET moveJoinEntryBoardItem();
    virtual void exitMenu();  // vtable slot 15
    virtual void updatePtr();  // vtable slot 6
private:
    s32 joinRno();
private:
    u64 mBoardId;  // offset: 0xb0
    u32 mBoardItemId;  // offset: 0xb8
    bool mIsPassword;  // offset: 0xbc
    MtString mPassword;  // offset: 0xc0
    uGUIDialogTextBox* mpDlTextBox;  // offset: 0xc8
public:
    static MyDTI DTI;
};

class cMenuLeaveEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        LEAVE_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        LEAVE_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuLeaveEntryBoardItem();
    virtual ~cMenuLeaveEntryBoardItem();
    void initLeaveEntryBoardItem();
    nMenu::MENU_RET moveLeaveEntryBoardItem();
    virtual void exitMenu();  // vtable slot 15
private:
    s32 leaveRno();
private:
    MtString mBoardTitle;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuReadyEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
        RNO_ERROR = 2,
    };
    enum
    {
        READY_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        READY_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuReadyEntryBoardItem();
    virtual ~cMenuReadyEntryBoardItem();
    void initReadyEntryBoardItem();
    nMenu::MENU_RET moveReadyEntryBoardItem();
private:
    s32 readyRno();
public:
    static MyDTI DTI;
};

class cMenuRecreateEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        RECREATE_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        RECREATE_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuRecreateEntryBoardItem();
    virtual ~cMenuRecreateEntryBoardItem();
    void initRecreateEntryBoardItem();
    nMenu::MENU_RET moveRecreateEntryBoardItem();
public:
    static MyDTI DTI;
};

class cMenuReleasePassEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        RELEASE_PASS_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        RELEASE_PASS_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuReleasePassEntryBoardItem();
    virtual ~cMenuReleasePassEntryBoardItem();
    void initReleasePassEntryBoardItem();
    nMenu::MENU_RET moveReleasePassEntryBoardItem();
    virtual void exitMenu();  // vtable slot 15
private:
    s32 leaveRno();
public:
    static MyDTI DTI;
};

class cMenuStartEntryBoardItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        START_ENTRY_BOARD_ITEM_RNO_BASE = 0,
        START_ENTRY_BOARD_ITEM_RNO_MAX = 1,
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
    cMenuStartEntryBoardItem();
    virtual ~cMenuStartEntryBoardItem();
    void initStartEntryBoardItem();
    nMenu::MENU_RET moveStartEntryBoardItem();
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cMenuContentsExecutor::cMenuContentsExecutor() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuCreateEntryBoardItem::cMenuCreateEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEditCommentEntryBoardItem::cMenuEditCommentEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEntryBoardMember::cMenuEntryBoardMember() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEntryBoardRecruit::cMenuEntryBoardRecruit() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuExtendEntryBoardItem::cMenuExtendEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuGetEntryBoardItem::cMenuGetEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuInviteEntryBoardItem::cMenuInviteEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuJoinEntryBoardItem::cMenuJoinEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuLeaveEntryBoardItem::cMenuLeaveEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuReadyEntryBoardItem::cMenuReadyEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuRecreateEntryBoardItem::cMenuRecreateEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuReleasePassEntryBoardItem::cMenuReleasePassEntryBoardItem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuStartEntryBoardItem::cMenuStartEntryBoardItem() {
}
