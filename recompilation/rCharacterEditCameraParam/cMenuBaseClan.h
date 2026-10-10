#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/Clan.h"
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cCharacterData.h"
#include "cMenuBase.h"
#include "nMenu.h"
#include "../shared/nNet.h"

// Forward declarations
class CDataClanMemberInfo;
class CDataClanParam;
class CDataClanScoutEntryParam;
class CDataCommunityCharacterBaseInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cMenuSupportMenu;
namespace nCharacterData { struct stCharacterName; }
namespace nMenu { struct MENU_PARTS; }
namespace nNet { struct stClanEmblem; }
class uGUIBase;
class uGUIPopFilter;

// Declarations
class cMenuApplyClan;
class cMenuApproveClan;
class cMenuApproveInvitedClan;
class cMenuCancelApplyClan;
class cMenuCancelClanScoutEntry;
class cMenuCancelInviteClan;
class cMenuClanApplyList;
class cMenuClanApplyManager;
class cMenuClanApproveDirectInvite;
class cMenuClanAuthority;
class cMenuClanChangeMaster;
class cMenuClanDirectInvite;
class cMenuClanDirectInvitedList;
class cMenuClanExpelMember;
class cMenuClanHistory;
class cMenuClanInfoDisp;
class cMenuClanInfoManager;
class cMenuClanInviteList;
class cMenuClanInvitedList;
class cMenuClanJoinReqList;
class cMenuClanList;
class cMenuClanMemberList;
class cMenuClanScoutEntry;
class cMenuClanScoutEntryList;
class cMenuClanSetMemberRank;
class cMenuCreateClan;
class cMenuEditClan;
class cMenuEditClanComment;
class cMenuEditClanDay;
class cMenuEditClanEmblem;
class cMenuEditClanEntryComment;
class cMenuEditClanFeature;
class cMenuEditClanHour;
class cMenuEditClanMessage;
class cMenuEditClanMotto;
class cMenuGetClanBaseInfo;
class cMenuGetClanDetail;
class cMenuGetMyClan;
class cMenuGetMyScoutEntry;
class cMenuInviteClan;
class cMenuQuitClan;
class cMenuSetClanName;
class cMenuSetClanNickName;

// Type aliases from DWARF
using CClanParam = CDataClanParam;
using CClanScoutEntryParam = CDataClanScoutEntryParam;
using ClanMemberInfoVec = MtTypedArray<CDataClanMemberInfo>;
using CommunityCharacterBaseInfoVec = MtTypedArray<CDataCommunityCharacterBaseInfo>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cMenuApplyClan : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        APPLY_CLAN_RNO_BASE = 0,
        APPLY_CLAN_RNO_MAX = 1,
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
    cMenuApplyClan();
    virtual ~cMenuApplyClan();
    void initApplyClan(u32 clanId, MtString& clanName);
    nMenu::MENU_RET moveApplyClan();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mClanId;  // offset: 0xb0
    MtString mClanName;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuApproveClan : public cMenuBase
{
public:
    enum
    {
        MOVE_APPROVE_CLAN_RNO_DLG_FLOW = 0,
    };
    enum
    {
        APPROVE_CLAN_RNO_BASE = 0,
        APPROVE_CLAN_RNO_MAX = 1,
    };
    enum
    {
        APPROVE_CLAN_TYPE_ALLOW = 0,
        APPROVE_CLAN_TYPE_DENY = 1,
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
    cMenuApproveClan();
    virtual ~cMenuApproveClan();
    void initApproveClan(u32 type, u32 reqId, MtString& charFirstName, MtString& charLastName);
    nMenu::MENU_RET moveApproveClan();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mType;  // offset: 0xb0
    u32 mReqId;  // offset: 0xb4
    MtString mCharFirstName;  // offset: 0xb8
    MtString mCharLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuApproveInvitedClan : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        APPROVE_INVITED_CLAN_RNO_BASE = 0,
        APPROVE_INVITED_CLAN_RNO_MAX = 1,
    };
    enum
    {
        APPROVE_INVITED_CLAN_TYPE_ALLOW = 0,
        APPROVE_INVITED_CLAN_TYPE_DENY = 1,
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
    cMenuApproveInvitedClan();
    virtual ~cMenuApproveInvitedClan();
    void initApproveInvitedClan(u32 type, u32 inviteId, MtString& clanName);
    nMenu::MENU_RET moveApproveInvitedClan();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mType;  // offset: 0xb0
    u32 mInvitedId;  // offset: 0xb4
    MtString mClanName;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuCancelApplyClan : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        CANCEL_APPLY_CLAN_RNO_BASE = 0,
        CANCEL_APPLY_CLAN_RNO_MAX = 1,
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
    cMenuCancelApplyClan();
    virtual ~cMenuCancelApplyClan();
    void initCancelApplyClan(u32 reqId);
    nMenu::MENU_RET moveCancelApplyClan();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mReqId;  // offset: 0xb0
    MtString mClanName;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuCancelClanScoutEntry : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_REQ_WAIT = 2,
        RNO_ERROR = 3,
        RNO_RESULT = 4,
    };
    enum
    {
        CANCEL_CLAN_SCOUT_ENTRY_RNO_BASE = 0,
        CANCEL_CLAN_SCOUT_ENTRY_RNO_MAX = 1,
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
    cMenuCancelClanScoutEntry();
    virtual ~cMenuCancelClanScoutEntry();
    void initCancelClanScoutEntry();
    nMenu::MENU_RET moveCancelClanScoutEntry();
    virtual void exitMenu();  // vtable slot 15
public:
    static MyDTI DTI;
};

class cMenuCancelInviteClan : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        CANCEL_INVITE_CLAN_RNO_BASE = 0,
        CANCEL_INVITE_CLAN_RNO_MAX = 1,
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
    cMenuCancelInviteClan();
    virtual ~cMenuCancelInviteClan();
    void initCancelInviteClan(u32 inviteId);
    nMenu::MENU_RET moveCancelInviteClan();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mInviteId;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuClanApplyList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST = 3,
        RNO_SUB_MENU = 4,
        RNO_LIST_ERROR = 5,
    };
    enum
    {
        CLAN_APPLY_LIST_RNO_BASE = 0,
        CLAN_APPLY_LIST_RNO_MAX = 1,
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
    cMenuClanApplyList();
    virtual ~cMenuClanApplyList();
    void initClanApplyList(uGUIBase* pRefGUI);
    nMenu::MENU_RET moveClanApplyList();
public:
    static MyDTI DTI;
};

class cMenuClanApplyManager : public cMenuBase
{
public:
    enum MODE
    {
        MODE_NONE = 0,
        MODE_LEADER = 1,
        MODE_USER = 2,
    };
    enum
    {
        CLAN_APPLY_MANAGER_CURSOR_TAB_SELECT = 0,
        CLAN_APPLY_MANAGER_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
        RNO_TAB_SELECT = 2,
        RNO_NO_TAB = 3,
    };
    enum
    {
        CLAN_APPLY_MANAGER_RNO_BASE = 0,
        CLAN_APPLY_MANAGER_RNO_JOIN_REQ_LIST = 1,
        CLAN_APPLY_MANAGER_RNO_INVITE_LIST = 2,
        CLAN_APPLY_MANAGER_RNO_APPLY_LIST = 3,
        CLAN_APPLY_MANAGER_RNO_INVITED_LIST = 4,
        CLAN_APPLY_MANAGER_RNO_DIRECT_INVITED_LIST = 5,
        CLAN_APPLY_MANAGER_RNO_MAX = 6,
    };
    enum
    {
        TAB_MENU_RNO_INIT = 0,
        TAB_MENU_RNO_MOVE = 1,
    };
    enum
    {
        CLAN_APPLY_MANAGER_TAB_JOIN_REQ_LIST = 0,
        CLAN_APPLY_MANAGER_TAB_INVITE_LIST = 1,
        CLAN_APPLY_MANAGER_TAB_APPLY_LIST = 2,
        CLAN_APPLY_MANAGER_TAB_INVITED_LIST = 3,
        CLAN_APPLY_MANAGER_TAB_DIRECT_INVITED_LIST = 4,
        CLAN_APPLY_MANAGER_TAB_MAX = 5,
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
    cMenuClanApplyManager();
    virtual ~cMenuClanApplyManager();
    void initClanApplyManager(s32 initTab, MODE mode);
    nMenu::MENU_RET moveClanApplyManager();
    virtual void exitMenu();  // vtable slot 15
    MODE getMode();
private:
    MODE mMode;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuClanApproveDirectInvite : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
    };
    enum
    {
        CLAN_DIRECT_INVITERNO_BASE = 0,
        CLAN_DIRECT_INVITERNO_MAX = 1,
    };
    enum
    {
        APPROVE_INVITED_CLAN_TYPE_ALLOW = 0,
        APPROVE_INVITED_CLAN_TYPE_DENY = 1,
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
    cMenuClanApproveDirectInvite();
    virtual ~cMenuClanApproveDirectInvite();
    void initClanApproveDirectInvite(u32 type, u32 clanId, MtString& clanName);
    nMenu::MENU_RET moveClanApproveDirectInvite();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mType;  // offset: 0xb0
    u32 mClanId;  // offset: 0xb4
    MtString mClanName;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuClanAuthority : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
        RNO_REQ_WAIT = 1,
    };
    enum
    {
        CLAN_AUTHORITY_BASE = 0,
        CLAN_AUTHORITY_MAX = 1,
    };
    enum
    {
        FILTER_INVITE = 0,
        FILTER_JOINT = 1,
        FILTER_DIRECT_INVITE = 2,
        FILTER_POINT = 3,
        FILTER_SUBMASTER = 4,
        FILTER_MAX = 5,
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
    cMenuClanAuthority();
    virtual ~cMenuClanAuthority();
    void initClanAuthority(u32 memberId, MtString& charFirstName, MtString& charLastName, u32 rank, u32 permission, bool change);
    nMenu::MENU_RET moveClanAuthority();
    virtual void exitMenu();  // vtable slot 15
private:
    uGUIPopFilter* mpFilter;  // offset: 0xb0
    u32 mMemberId;  // offset: 0xb8
    u32 mRank;  // offset: 0xbc
    u32 mPermission;  // offset: 0xc0
    bool mChange;  // offset: 0xc4
    MtString mCharFirstName;  // offset: 0xc8
    MtString mCharLastName;  // offset: 0xd0
public:
    static MyDTI DTI;
};

class cMenuClanChangeMaster : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        CLAN_CHANGE_MASTER_RNO_BASE = 0,
        CLAN_CHANGE_MASTER_RNO_MAX = 1,
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
    cMenuClanChangeMaster();
    virtual ~cMenuClanChangeMaster();
    void initClanChangeMaster(u32 memberId, MtString& charFirstName, MtString& charLastName);
    nMenu::MENU_RET moveClanChangeMaster();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mMemberId;  // offset: 0xb0
    MtString mCharFirstName;  // offset: 0xb8
    MtString mCharLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuClanDirectInvite : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
    };
    enum
    {
        CLAN_DIRECT_INVITERNO_BASE = 0,
        CLAN_DIRECT_INVITERNO_MAX = 1,
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
    cMenuClanDirectInvite();
    virtual ~cMenuClanDirectInvite();
    void initClanDirectInvite(u32 characterId, MtString& charFirstName, MtString& charLastName);
    nMenu::MENU_RET moveClanDirectInvite();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mCharacterId;  // offset: 0xb0
    MtString mCharFirstName;  // offset: 0xb8
    MtString mCharLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuClanDirectInvitedList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_LIST = 1,
        RNO_SUB_MENU = 2,
        RNO_LIST_ERROR = 3,
    };
    enum
    {
        CLAN_DIRECT_INVITED_LIST_RNO_BASE = 0,
        CLAN_DIRECT_INVITED_LIST_RNO_MAX = 1,
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
    cMenuClanDirectInvitedList();
    virtual ~cMenuClanDirectInvitedList();
    void initClanDirectInvitedList(uGUIBase* pRefGUI);
    nMenu::MENU_RET moveClanDirectInvitedList();
public:
    static MyDTI DTI;
    static const s32 CLAN_DIRECT_INVITED_LIST_DISP_NUM = 11;
    static const s32 CLAN_DIRECT_INVITED_SORT_LIST_MAX = 256;
};

class cMenuClanExpelMember : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        CLAN_EXPEL_MEMBER_RNO_BASE = 0,
        CLAN_EXPEL_MEMBER_RNO_MAX = 1,
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
    cMenuClanExpelMember();
    virtual ~cMenuClanExpelMember();
    void initClanExpelMember(u32 memberId, MtString& charFirstName, MtString& charLastName);
    nMenu::MENU_RET moveClanExpelMember();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mMemberId;  // offset: 0xb0
    MtString mCharFirstName;  // offset: 0xb8
    MtString mCharLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuClanHistory : public cMenuBase
{
public:
    enum
    {
        MOVE_CLAN_HISTORY_RNO_INIT = 0,
        MOVE_CLAN_HISTORY_RNO_REQ = 1,
        MOVE_CLAN_HISTORY_RNO_WAIT = 2,
        MOVE_CLAN_HISTORY_RNO_LIST = 3,
        MOVE_CLAN_HISTORY_RNO_ERROR = 4,
    };
    enum
    {
        CLAN_MEMBER_LIST_RNO_BASE = 0,
        CLAN_MEMBER_LIST_RNO_MAX = 1,
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
    cMenuClanHistory();
    virtual ~cMenuClanHistory();
    virtual void exitMenu();  // vtable slot 15
    void initClanHistory(uGUIBase* refGUI);
    nMenu::MENU_RET moveClanHistory();
public:
    static MyDTI DTI;
};

class cMenuClanInfoDisp : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_MENU = 3,
    };
    enum
    {
        CLAN_INFO_DISP_RNO_BASE = 0,
        CLAN_INFO_DISP_RNO_MAX = 1,
    };
    enum
    {
        CLAN_INFO_DISP_CURSOR_SELECT = 0,
        CLAN_INFO_DISP_CURSOR_MAX = 1,
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
    cMenuClanInfoDisp();
    virtual ~cMenuClanInfoDisp();
    void initClanInfoDisp(CClanParam& dstParam, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveClanInfoDisp();
    CClanParam* getClanParam();
private:
    s32 getRno();
private:
    CClanParam* mpClanParam;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuClanInfoManager : public cMenuBase
{
public:
    enum MODE
    {
        MODE_MEMBER = 0,
        MODE_LEADER = 1,
        MODE_SEARCH = 2,
    };
    enum
    {
        CLAN_INFO_MANAGER_CURSOR_TAB_SELECT = 0,
        CLAN_INFO_MANAGER_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
        RNO_TAB_SELECT = 2,
    };
    enum
    {
        CLAN_INFO_MANAGER_RNO_BASE = 0,
        CLAN_INFO_MANAGER_RNO_INFO = 1,
        CLAN_INFO_MANAGER_RNO_MEMBER = 2,
        CLAN_INFO_MANAGER_RNO_HISTORY = 3,
        CLAN_INFO_MANAGER_RNO_MAX = 4,
    };
    enum
    {
        TAB_MENU_RNO_INIT = 0,
        TAB_MENU_RNO_MOVE = 1,
    };
    enum
    {
        CLAN_INFO_MANAGER_TAB_INFO = 0,
        CLAN_INFO_MANAGER_TAB_MEMBER = 1,
        CLAN_INFO_MANAGER_TAB_HISTORY = 2,
        CLAN_INFO_MANAGER_TAB_MAX = 3,
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
    cMenuClanInfoManager();
    virtual ~cMenuClanInfoManager();
    void initClanInfoManager(CClanParam& clanParam, s32 initTab, MODE mode, u32 prio);
    nMenu::MENU_RET moveClanInfoManager();
    virtual void exitMenu();  // vtable slot 15
    MODE getMode();
private:
    MODE mMode;  // offset: 0xb0
    CClanParam* mpClanParam;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuClanInviteList : public cMenuBase
{
public:
    enum
    {
        MOVE_CLAN_INVITE_LIST_RNO_INIT = 0,
        MOVE_CLAN_INVITE_LIST_RNO_REQ = 1,
        MOVE_CLAN_INVITE_LIST_RNO_WAIT = 2,
        MOVE_CLAN_INVITE_LIST_RNO_LIST = 3,
        MOVE_CLAN_INVITE_LIST_RNO_SUB_MENU = 4,
        MOVE_CLAN_INVITE_LIST_RNO_LIST_ERROR = 5,
    };
    enum
    {
        CLAN_INVITE_LIST_RNO_BASE = 0,
        CLAN_INVITE_LIST_RNO_MAX = 1,
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
    cMenuClanInviteList();
    virtual ~cMenuClanInviteList();
    void initClanInviteList(uGUIBase* pRefGUI);
    nMenu::MENU_RET moveClanInviteList();
    virtual void exitMenu();  // vtable slot 15
public:
    static MyDTI DTI;
    static const s32 CLAN_INVITE_LIST_DISP_NUM = 11;
    static const s32 CLAN_INVITE_SORT_LIST_MAX = 256;
};

class cMenuClanInvitedList : public cMenuBase
{
public:
    enum
    {
        MOVE_CLAN_INVITED_LIST_RNO_INIT = 0,
        MOVE_CLAN_INVITED_LIST_RNO_REQ = 1,
        MOVE_CLAN_INVITED_LIST_RNO_WAIT = 2,
        MOVE_CLAN_INVITED_LIST_RNO_LIST = 3,
        MOVE_CLAN_INVITED_LIST_RNO_SUB_MENU = 4,
        MOVE_CLAN_INVITED_LIST_RNO_LIST_ERROR = 5,
    };
    enum
    {
        CLAN_INVITED_LIST_RNO_BASE = 0,
        CLAN_INVITED_LIST_RNO_MAX = 1,
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
    cMenuClanInvitedList();
    virtual ~cMenuClanInvitedList();
    void initClanInvitedList(uGUIBase* pRefGUI);
    nMenu::MENU_RET moveClanInvitedList();
public:
    static MyDTI DTI;
    static const s32 CLAN_INVITED_LIST_DISP_NUM = 11;
    static const s32 CLAN_INVITED_SORT_LIST_MAX = 256;
};

class cMenuClanJoinReqList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST = 3,
        RNO_SUB_MENU = 4,
        RNO_LIST_ERROR = 5,
    };
    enum
    {
        CLAN_JOIN_REQ_LIST_RNO_BASE = 0,
        CLAN_JOIN_REQ_LIST_RNO_MAX = 1,
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
    cMenuClanJoinReqList();
    virtual ~cMenuClanJoinReqList();
    void initClanJoinReqList(u32 clanId, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveClanJoinReqList();
private:
    u32 mClanId;  // offset: 0xb0
public:
    static MyDTI DTI;
    static const s32 CLAN_JOIN_REQ_LIST_DISP_NUM = 11;
    static const s32 CLAN_JOIN_REQ_SORT_LIST_MAX = 256;
};

class cMenuClanList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_START = 1,
        RNO_REQ = 2,
        RNO_WAIT = 3,
        RNO_LIST = 4,
        RNO_SEARCH_FILTER = 5,
        RNO_LIST0 = 6,
        RNO_SUB_MENU = 7,
        RNO_LISTERROR = 8,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
    };
    enum
    {
        CLAN_LIST_TOP = 0,
        SEARCH_SETTING = 4,
        CLAN_LIST_MENU_MAX = 5,
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
    cMenuClanList();
    virtual ~cMenuClanList();
    void initClanList();
    nMenu::MENU_RET moveClanList();
    virtual void exitMenu();  // vtable slot 15
    const cCharacterData::stSearchFilterSetting& getSearchSetting();
private:
    cCharacterData::stSearchFilterSetting mSearchSetting;  // offset: 0xb0
    bool mIsSearchEnd;  // offset: 0x1dc
public:
    static MyDTI DTI;
    static const s32 DISP_NUM = 4;
    static const s32 CLAN_SORT_LIST_MAX = 256;
};

class cMenuClanMemberList : public cMenuBase
{
public:
    enum
    {
        TYPE_NORMAL = 0,
        TYPE_SEARCH = 1,
        TYPE_RET_NAME = 2,
        TYPE_GET_ONLY = 3,
    };
    enum
    {
        MOVE_CLAN_MEMBER_LIST_RNO_INIT = 0,
        MOVE_CLAN_MEMBER_LIST_RNO_REQ = 1,
        MOVE_CLAN_MEMBER_LIST_RNO_WAIT = 2,
        MOVE_CLAN_MEMBER_LIST_RNO_SHOW_GUI = 3,
        MOVE_CLAN_MEMBER_LIST_RNO_LIST = 4,
        MOVE_CLAN_MEMBER_LIST_RNO_SUB_MENU = 5,
        MOVE_CLAN_MEMBER_LIST_RNO_LIST_ERROR = 6,
    };
    enum
    {
        CLAN_MEMBER_LIST_RNO_BASE = 0,
        CLAN_MEMBER_LIST_RNO_MAX = 1,
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
    cMenuClanMemberList();
    virtual ~cMenuClanMemberList();
    virtual void exitMenu();  // vtable slot 15
    void initClanMemberList(u32 clanId, u32 type, nCharacterData::stCharacterName* pDstName, u32* pCharacterId, CommunityCharacterBaseInfoVec* pExcludeList);
    nMenu::MENU_RET moveClanMemberList();
    u32 getClanMemberDispNum();
    const ClanMemberInfoVec* getClanMemberList();
    bool isMyClan();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    u32 getListLength();
private:
    u32 mClanId;  // offset: 0xb0
    u32 mType;  // offset: 0xb4
    nCharacterData::stCharacterName* mpDstName;  // offset: 0xb8
    u32* mpDstCharacterId;  // offset: 0xc0
    CommunityCharacterBaseInfoVec* mpExcludeList;  // offset: 0xc8
    const ClanMemberInfoVec* mpMemberList;  // offset: 0xd0
    bool mIsMyClan;  // offset: 0xd8
public:
    static MyDTI DTI;
};

class cMenuClanScoutEntry : public cMenuBase
{
public:
    enum
    {
        MOVE_CLAN_SCOUT_ENTRY_RNO_INIT = 0,
        MOVE_CLAN_SCOUT_ENTRY_RNO_MENU = 1,
        MOVE_CLAN_SCOUT_ENTRY_RNO_LV = 2,
        MOVE_CLAN_SCOUT_ENTRY_RNO_MEMBER_NUM = 3,
        MOVE_CLAN_SCOUT_ENTRY_RNO_MOTTO = 4,
        MOVE_CLAN_SCOUT_ENTRY_RNO_DAY = 5,
        MOVE_CLAN_SCOUT_ENTRY_RNO_HOUR = 6,
        MOVE_CLAN_SCOUT_ENTRY_RNO_FEATURE = 7,
        MOVE_CLAN_SCOUT_ENTRY_RNO_COMMENT = 8,
        MOVE_CLAN_SCOUT_ENTRY_RNO_ENTRY = 9,
        MOVE_CLAN_SCOUT_ENTRY_RNO_ENTRY_RESULT = 10,
        MOVE_CLAN_SCOUT_ENTRY_RNO_ENTRY_ERR = 11,
    };
    enum
    {
        CLAN_SCOUT_ENTRY_RNO_BASE = 0,
        CLAN_SCOUT_ENTRY_RNO_MAX = 1,
    };
    enum
    {
        CLAN_SCOUT_ENTRY_LV = 0,
        CLAN_SCOUT_ENTRY_MEMBER_NUM = 1,
        CLAN_SCOUT_ENTRY_MOTTO = 2,
        CLAN_SCOUT_ENTRY_DAY = 3,
        CLAN_SCOUT_ENTRY_HOUR = 4,
        CLAN_SCOUT_ENTRY_FEATURE = 5,
        CLAN_SCOUT_ENTRY_COMMENT = 6,
        CLAN_SCOUT_ENTRY_MESSAGE = 7,
        CLAN_SCOUT_ENTRY_DECIDE = 8,
        CLAN_SCOUT_ENTRY_CANCEL = 9,
        CLAN_SCOUT_ENTRY_MAX = 10,
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
    cMenuClanScoutEntry();
    virtual ~cMenuClanScoutEntry();
    void initClanScoutEntry();
    nMenu::MENU_RET moveClanScoutEntry();
    CClanScoutEntryParam& getScoutEntryParam();
private:
    u32 getIndexBitParam(u32 bits);
private:
    CClanScoutEntryParam mEntryParam;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuClanScoutEntryList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST = 3,
        RNO_SUB_MENU = 4,
        RNO_LIST_ERROR = 5,
    };
    enum
    {
        CLAN_SCOUT_ENTRY_LIST_RNO_BASE = 0,
        CLAN_SCOUT_ENTRY_LIST_RNO_MAX = 1,
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
    cMenuClanScoutEntryList();
    virtual ~cMenuClanScoutEntryList();
    void initClanScoutEntryList();
    nMenu::MENU_RET moveClanScoutEntryList();
    virtual void exitMenu();  // vtable slot 15
public:
    static MyDTI DTI;
    static const s32 CLAN_SCOUT_ENTRY_LIST_DISP_NUM = 10;
    static const s32 CLAN_SCOUT_ENTRY_SORT_LIST_MAX = 256;
};

class cMenuClanSetMemberRank : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        CLAN_SET_MEMBER_RANK_RNO_BASE = 0,
        CLAN_SET_MEMBER_RANK_RNO_MAX = 1,
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
    cMenuClanSetMemberRank();
    virtual ~cMenuClanSetMemberRank();
    void initClanSetMemberRank(u32 memberId, s32 rank, MtString& charFirstName, MtString& charLastName);
    nMenu::MENU_RET moveClanSetMemberRank();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mMemberId;  // offset: 0xb0
    s32 mRank;  // offset: 0xb4
    MtString mCharFirstName;  // offset: 0xb8
    MtString mCharLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuCreateClan : public cMenuBase
{
public:
    enum
    {
        MOVE_CREATE_CLAN_RNO_INIT = 0,
        MOVE_CREATE_CLAN_RNO_NAME = 1,
        MOVE_CREATE_CLAN_RNO_NICKNAME = 2,
        MOVE_CREATE_CLAN_RNO_MENU = 3,
        MOVE_CREATE_CLAN_RNO_CREATE = 4,
    };
    enum
    {
        CREATE_CLAN_RNO_BASE = 0,
        CREATE_CLAN_RNO_MAX = 1,
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
    cMenuCreateClan();
    virtual ~cMenuCreateClan();
    void initCreateClan();
    nMenu::MENU_RET moveCreateClan();
    virtual void exitMenu();  // vtable slot 15
private:
    s32 getRno();
private:
    CClanParam mClanParam;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuEditClan : public cMenuBase
{
public:
    enum
    {
        EDIT_CLAN_TYPE_CREATE = 0,
        EDIT_CLAN_TYPE_NORMAL = 1,
        EDIT_CLAN_TYPE_DISP_ONLY = 2,
    };
    enum
    {
        MOVE_EDIT_CLAN_RNO_INIT = 0,
        MOVE_EDIT_CLAN_RNO_MENU = 1,
        MOVE_EDIT_CLAN_RNO_NAME = 2,
        MOVE_EDIT_CLAN_RNO_NICKNAME = 3,
        MOVE_EDIT_CLAN_RNO_EMBLEM = 4,
        MOVE_EDIT_CLAN_RNO_MOTTO = 5,
        MOVE_EDIT_CLAN_RNO_DAY = 6,
        MOVE_EDIT_CLAN_RNO_HOUR = 7,
        MOVE_EDIT_CLAN_RNO_FEATURE = 8,
        MOVE_EDIT_CLAN_RNO_COMMENT = 9,
        MOVE_EDIT_CLAN_RNO_MESSAGE = 10,
        MOVE_EDIT_CLAN_RNO_OPEN_SETTING = 11,
        MOVE_EDIT_CLAN_RNO_DIALOG = 12,
    };
    enum
    {
        EDIT_CLAN_RNO_BASE = 0,
        EDIT_CLAN_RNO_MAX = 1,
    };
    enum
    {
        EDIT_CLAN_NAME = 0,
        EDIT_CLAN_NICKNAME = 1,
        EDIT_CLAN_EMBLEM = 2,
        EDIT_CLAN_MOTTO = 3,
        EDIT_CLAN_DAY = 4,
        EDIT_CLAN_HOUR = 5,
        EDIT_CLAN_FEATURE = 6,
        EDIT_CLAN_COMMENT = 7,
        EDIT_CLAN_MESSAGE = 8,
        EDIT_CLAN_LEADER_NAME = 9,
        EDIT_CLAN_DECIDE = 10,
        EDIT_CLAN_CANCEL = 11,
        EDIT_CLAN_MAX = 12,
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
    cMenuEditClan();
    virtual ~cMenuEditClan();
    void initEditClan(s32 editType, CClanParam& dstParam, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveEditClan();
    virtual void exitMenu();  // vtable slot 15
    CClanParam* getClanParam();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    bool checkCancel();
    void setCursor(s32);
    s32 getRno();
    u32 getIndexBitParam(u32 bits);
private:
    s32 mEditType;  // offset: 0xb0
    CClanParam* mpClanParam;  // offset: 0xb8
    MT_CHAR mMessage[217];  // offset: 0xc0
    nNet::stClanEmblem mEmblem;  // offset: 0x199
    CClanParam mClanParamBackup;  // offset: 0x1a0
public:
    static MyDTI DTI;
};

class cMenuEditClanComment : public cMenuBase
{
public:
    enum
    {
        MOVE_EDIT_CLAN_COMMENT_RNO_INIT = 0,
        MOVE_EDIT_CLAN_COMMENT_RNO_MENU = 1,
        MOVE_EDIT_CLAN_COMMENT_RNO_INPUT = 2,
    };
    enum
    {
        EDIT_CLAN_COMMENT_RNO_BASE = 0,
        EDIT_CLAN_COMMENT_RNO_MAX = 1,
    };
    enum
    {
        EDIT_CLAN_COMMENT_INPUT = 0,
        EDIT_CLAN_COMMENT_DECIDE = 1,
        EDIT_CLAN_COMMENT_CANCEL = 2,
        EDIT_CLAN_COMMENT_MAX = 3,
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
    cMenuEditClanComment();
    virtual ~cMenuEditClanComment();
    void initEditClanComment(MtString& dstComment, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveEditClanComment();
private:
    MT_CHAR mClanComment[217];  // offset: 0xb0
    MtString* mpDstComment;  // offset: 0x190
public:
    static MyDTI DTI;
};

class cMenuEditClanDay : public cMenuBase
{
public:
    enum
    {
        MOVE_EDIT_CLAN_DAY_RNO_INIT = 0,
        MOVE_EDIT_CLAN_DAY_RNO_MENU = 1,
    };
    enum
    {
        EDIT_CLAN_DAY_RNO_BASE = 0,
        EDIT_CLAN_DAY_RNO_MAX = 1,
    };
    enum
    {
        EDIT_CLAN_DAY_DECIDE = 4,
        EDIT_CLAN_DAY_CANCEL = 5,
        EDIT_CLAN_DAY_MAX = 6,
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
    cMenuEditClanDay();
    virtual ~cMenuEditClanDay();
    void initEditClanDay(u32* pDay, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveEditClanDay();
    u32 getClanDayIndex(u32 cursor);
private:
    u32 mDay;  // offset: 0xb0
    u32* mpDay;  // offset: 0xb8
public:
    static MyDTI DTI;
    static const u32 PAGE_DISP_NUM = 4;
};

class cMenuEditClanEmblem : public cMenuBase
{
public:
    enum
    {
        MOVE_EDIT_CLAN_EMBLEM_RNO_INIT = 0,
        MOVE_EDIT_CLAN_EMBLEM_RNO_MENU = 1,
        MOVE_EDIT_CLAN_EMBLEM_RNO_DIALOG = 2,
    };
    enum
    {
        EDIT_CLAN_EMBLEM_RNO_BASE = 0,
        EDIT_CLAN_EMBLEM_RNO_MAX = 1,
    };
    enum
    {
        EDIT_CLAN_EMBLEM_MARK = 0,
        EDIT_CLAN_EMBLEM_BASE = 1,
        EDIT_CLAN_EMBLEM_BASE_MAIN_COL = 2,
        EDIT_CLAN_EMBLEM_BASE_SUB_COL = 3,
        EDIT_CLAN_EMBLEM_DECIDE = 4,
        EDIT_CLAN_EMBLEM_CANCEL = 5,
        EDIT_CLAN_EMBLEM_MAX = 6,
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
    cMenuEditClanEmblem();
    virtual ~cMenuEditClanEmblem();
    void initEditClanEmblem(nNet::stClanEmblem* pEmblem, uGUIBase* pParentGUI);
    nMenu::MENU_RET moveEditClanEmblem();
    virtual void exitMenu();  // vtable slot 15
    bool checkCancel();
private:
    nNet::stClanEmblem mEmblem;  // offset: 0xb0
    nNet::stClanEmblem* mpEmblem;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuEditClanEntryComment : public cMenuBase
{
public:
    enum
    {
        MOVE_EDIT_CLAN_ENTRY_COMMENT_RNO_INIT = 0,
        MOVE_EDIT_CLAN_ENTRY_COMMENT_RNO_MENU = 1,
        MOVE_EDIT_CLAN_ENTRY_COMMENT_RNO_INPUT = 2,
    };
    enum
    {
        EDIT_CLAN_ENTRY_COMMENT_RNO_BASE = 0,
        EDIT_CLAN_ENTRY_COMMENT_RNO_MAX = 1,
    };
    enum
    {
        EDIT_CLAN_ENTRY_COMMENT_INPUT = 0,
        EDIT_CLAN_ENTRY_COMMENT_DECIDE = 1,
        EDIT_CLAN_ENTRY_COMMENT_CANCEL = 2,
        EDIT_CLAN_ENTRY_COMMENT_MAX = 3,
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
    cMenuEditClanEntryComment();
    virtual ~cMenuEditClanEntryComment();
    void initEditClanEntryComment(MtString& dstComment, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveEditClanEntryComment();
private:
    MT_CHAR mClanEntryComment[67];  // offset: 0xb0
    MtString* mpDstComment;  // offset: 0xf8
public:
    static MyDTI DTI;
};

class cMenuEditClanFeature : public cMenuBase
{
public:
    enum
    {
        MOVE_EDIT_CLAN_FEATURE_RNO_INIT = 0,
        MOVE_EDIT_CLAN_FEATURE_RNO_MENU = 1,
    };
    enum
    {
        EDIT_CLAN_FEATURE_RNO_BASE = 0,
        EDIT_CLAN_FEATURE_RNO_MAX = 1,
    };
    enum
    {
        EDIT_CLAN_FEATURE_DECIDE = 8,
        EDIT_CLAN_FEATURE_CANCEL = 9,
        EDIT_CLAN_FEATURE_MAX = 10,
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
    cMenuEditClanFeature();
    virtual ~cMenuEditClanFeature();
    void initEditClanFeature(u32* pFeature, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveEditClanFeature();
    u32 getClanFeatureIndex(u32 cursor);
private:
    u32 mFeature;  // offset: 0xb0
    u32* mpFeature;  // offset: 0xb8
public:
    static MyDTI DTI;
    static const u32 PAGE_DISP_NUM = 8;
};

class cMenuEditClanHour : public cMenuBase
{
public:
    enum
    {
        MOVE_EDIT_CLAN_HOUR_RNO_INIT = 0,
        MOVE_EDIT_CLAN_HOUR_RNO_MENU = 1,
    };
    enum
    {
        EDIT_CLAN_HOUR_RNO_BASE = 0,
        EDIT_CLAN_HOUR_RNO_MAX = 1,
    };
    enum
    {
        EDIT_CLAN_HOUR_DECIDE = 4,
        EDIT_CLAN_HOUR_CANCEL = 5,
        EDIT_CLAN_HOUR_MAX = 6,
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
    cMenuEditClanHour();
    virtual ~cMenuEditClanHour();
    void initEditClanHour(u32* pHour, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveEditClanHour();
    u32 getClanHourIndex(u32 cursor);
private:
    u32 mHour;  // offset: 0xb0
    u32* mpHour;  // offset: 0xb8
public:
    static MyDTI DTI;
    static const u32 PAGE_DISP_NUM = 4;
};

class cMenuEditClanMessage : public cMenuBase
{
public:
    enum
    {
        MOVE_EDIT_CLAN_MESSAGE_RNO_INIT = 0,
        MOVE_EDIT_CLAN_MESSAGE_RNO_MENU = 1,
        MOVE_EDIT_CLAN_MESSAGE_RNO_INPUT = 2,
    };
    enum
    {
        EDIT_CLAN_MESSAGE_RNO_BASE = 0,
        EDIT_CLAN_MESSAGE_RNO_MAX = 1,
    };
    enum
    {
        EDIT_CLAN_MESSAGE_INPUT = 0,
        EDIT_CLAN_MESSAGE_DECIDE = 1,
        EDIT_CLAN_MESSAGE_CANCEL = 2,
        EDIT_CLAN_MESSAGE_MAX = 3,
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
    cMenuEditClanMessage();
    virtual ~cMenuEditClanMessage();
    void initEditClanMessage(MT_CHAR* pClanMessage, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveEditClanMessage();
private:
    MT_CHAR mClanMessage[217];  // offset: 0xb0
    MT_CHAR* mpClanMessage;  // offset: 0x190
public:
    static MyDTI DTI;
};

class cMenuEditClanMotto : public cMenuBase
{
public:
    enum
    {
        MOVE_EDIT_CLAN_MOTTO_RNO_INIT = 0,
        MOVE_EDIT_CLAN_MOTTO_RNO_MENU = 1,
    };
    enum
    {
        EDIT_CLAN_MOTTO_RNO_BASE = 0,
        EDIT_CLAN_MOTTO_RNO_MAX = 1,
    };
    enum
    {
        EDIT_CLAN_MOTTO_DECIDE = 8,
        EDIT_CLAN_MOTTO_CANCEL = 9,
        EDIT_CLAN_MOTTO_MAX = 10,
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
    cMenuEditClanMotto();
    virtual ~cMenuEditClanMotto();
    void initEditClanMotto(u32* pMotto, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveEditClanMotto();
    u32 getClanMottoIndex(u32 cursor);
private:
    u32 mMotto;  // offset: 0xb0
    u32* mpMotto;  // offset: 0xb8
public:
    static MyDTI DTI;
    static const u32 PAGE_DISP_NUM = 8;
};

class cMenuGetClanBaseInfo : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ_WAIT = 1,
        RNO_ERROR = 2,
    };
    enum
    {
        GET_CLAN_BASE_INFO_RNO_BASE = 0,
        GET_CLAN_BASE_INFO_RNO_MAX = 1,
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
    cMenuGetClanBaseInfo();
    virtual ~cMenuGetClanBaseInfo();
    void initGetClanBaseInfo();
    nMenu::MENU_RET moveGetClanBaseInfo();
public:
    static MyDTI DTI;
};

class cMenuGetClanDetail : public cMenuBase
{
public:
    enum
    {
        MOVE_GET_CLAN_DETAIL_RNO_INIT = 0,
        MOVE_GET_CLAN_DETAIL_RNO_REQ_WAIT = 1,
        MOVE_GET_CLAN_DETAIL_RNO_ERROR = 2,
    };
    enum
    {
        GET_CLAN_DETAIL_RNO_BASE = 0,
        GET_CLAN_DETAIL_RNO_MAX = 1,
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
    cMenuGetClanDetail();
    virtual ~cMenuGetClanDetail();
    void initGetClanDetail(u32 clanId, CClanParam& dstParam);
    nMenu::MENU_RET moveGetClanDetail();
private:
    u32 mClanId;  // offset: 0xb0
    CClanParam* mpClanParam;  // offset: 0xb8
    bool mIsMyClan;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuGetMyClan : public cMenuBase
{
public:
    enum
    {
        MOVE_GET_MY_CLAN_RNO_INIT = 0,
        MOVE_GET_MY_CLAN_RNO_REQ_WAIT = 1,
        MOVE_GET_MY_CLAN_RNO_ERROR = 2,
    };
    enum
    {
        GET_MY_CLAN_RNO_BASE = 0,
        GET_MY_CLAN_RNO_MAX = 1,
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
    cMenuGetMyClan();
    virtual ~cMenuGetMyClan();
    void initGetMyClan();
    nMenu::MENU_RET moveGetMyClan();
public:
    static MyDTI DTI;
};

class cMenuGetMyScoutEntry : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ_WAIT = 1,
        RNO_ERROR = 2,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
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
    cMenuGetMyScoutEntry();
    virtual ~cMenuGetMyScoutEntry();
    void initGetMyScoutEntry();
    nMenu::MENU_RET moveGetMyScoutEntry();
public:
    static MyDTI DTI;
};

class cMenuInviteClan : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        INVITE_CLAN_RNO_BASE = 0,
        INVITE_CLAN_RNO_MAX = 1,
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
    cMenuInviteClan();
    virtual ~cMenuInviteClan();
    void initInviteClan(u32 entryId, MtString& charFirstName, MtString& charLastName);
    nMenu::MENU_RET moveInviteClan();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mEntryId;  // offset: 0xb0
    MtString mCharFirstName;  // offset: 0xb8
    MtString mCharLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuQuitClan : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_DLG_FLOW = 1,
    };
    enum
    {
        QUIT_CLAN_RNO_BASE = 0,
        QUIT_CLAN_RNO_MAX = 1,
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
    cMenuQuitClan();
    virtual ~cMenuQuitClan();
    void initQuitClan();
    nMenu::MENU_RET moveQuitClan();
public:
    static MyDTI DTI;
};

class cMenuSetClanName : public cMenuBase
{
public:
    enum
    {
        SET_TYPE_CREATE = 0,
    };
    enum
    {
        MOVE_SET_CLAN_NAME_RNO_INIT = 0,
        MOVE_SET_CLAN_NAME_RNO_MENU = 1,
        MOVE_SET_CLAN_NAME_RNO_NAME = 2,
    };
    enum
    {
        SET_CLAN_NAME_RNO_BASE = 0,
        SET_CLAN_NAME_RNO_MAX = 1,
    };
    enum
    {
        SET_CLAN_NAME_NAME = 0,
        SET_CLAN_NAME_DECIDE = 1,
        SET_CLAN_NAME_CANCEL = 2,
        SET_CLAN_NAME_MAX = 3,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        SET_CLAN_NAME_ERR_LENGTH = 1,
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
    cMenuSetClanName();
    virtual ~cMenuSetClanName();
    void initSetClanName(s32 setType, MtString& dstClanName, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveSetClanName();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    void setCursor(s32);
    s32 getRno();
private:
    s32 mSetType;  // offset: 0xb0
    MT_CHAR mClanName[13];  // offset: 0xb4
    MtString* mpDstClanName;  // offset: 0xc8
public:
    static MyDTI DTI;
};

class cMenuSetClanNickName : public cMenuBase
{
public:
    enum
    {
        SET_TYPE_CREATE = 0,
    };
    enum
    {
        MOVE_SET_CLAN_NICKNAME_RNO_INIT = 0,
        MOVE_SET_CLAN_NICKNAME_RNO_MENU = 1,
        MOVE_SET_CLAN_NICKNAME_RNO_NAME = 2,
    };
    enum
    {
        SET_CLAN_NICKNAME_RNO_BASE = 0,
        SET_CLAN_NICKNAME_RNO_MAX = 1,
    };
    enum
    {
        SET_CLAN_NICKNAME_NAME = 0,
        SET_CLAN_NICKNAME_DECIDE = 1,
        SET_CLAN_NICKNAME_CANCEL = 2,
        SET_CLAN_NICKNAME_MAX = 3,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        SET_CLAN_NICKNAME_ERR_LENGTH = 1,
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
    cMenuSetClanNickName();
    virtual ~cMenuSetClanNickName();
    void initSetClanNickName(s32 setType, MtString& dstClanNickName, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveSetClanNickName();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    s32 getRno();
    void setCursor(s32);
private:
    s32 mSetType;  // offset: 0xb0
    MT_CHAR mClanNickName[4];  // offset: 0xb4
    MtString* mpDstClanNickName;  // offset: 0xb8
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cMenuApplyClan::cMenuApplyClan() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuApproveInvitedClan::cMenuApproveInvitedClan() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuCancelApplyClan::cMenuCancelApplyClan() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuCancelClanScoutEntry::cMenuCancelClanScoutEntry() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuCancelInviteClan::cMenuCancelInviteClan() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanApplyList::cMenuClanApplyList() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanApplyManager::cMenuClanApplyManager() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanApproveDirectInvite::cMenuClanApproveDirectInvite() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanDirectInvitedList::cMenuClanDirectInvitedList() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanHistory::cMenuClanHistory() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanInfoDisp::cMenuClanInfoDisp() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanInfoManager::cMenuClanInfoManager() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanInviteList::cMenuClanInviteList() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanInvitedList::cMenuClanInvitedList() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanJoinReqList::cMenuClanJoinReqList() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanList::cMenuClanList() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanMemberList::cMenuClanMemberList() {
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cMenuClanScoutEntry::cMenuClanScoutEntry() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuClanScoutEntryList::cMenuClanScoutEntryList() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEditClanComment::cMenuEditClanComment() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEditClanDay::cMenuEditClanDay() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEditClanEmblem::cMenuEditClanEmblem() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEditClanEntryComment::cMenuEditClanEntryComment() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEditClanFeature::cMenuEditClanFeature() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEditClanHour::cMenuEditClanHour() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEditClanMessage::cMenuEditClanMessage() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuEditClanMotto::cMenuEditClanMotto() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuGetClanBaseInfo::cMenuGetClanBaseInfo() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuGetClanDetail::cMenuGetClanDetail() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuGetMyClan::cMenuGetMyClan() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuGetMyScoutEntry::cMenuGetMyScoutEntry() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuQuitClan::cMenuQuitClan() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuSetClanName::cMenuSetClanName() {
}

// Inline, no code of its own: checked where it is inlined.
inline cMenuSetClanNickName::cMenuSetClanNickName() {
}
