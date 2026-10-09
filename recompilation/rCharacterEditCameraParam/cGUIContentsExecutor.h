#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cUIObject.h"
#include "../shared/nNet.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cArcLoaderBase;
namespace nNet { struct stEntryBoardItemInfo; }
class uGUIContentsBoard;
class uGUIEntryBoardInfo;
class uGUIMissionInfo;
class uGUIMissionResult;
class uGUINewspaper;
class uGUIPopEventTop;
class uGUIPopFilter;
class uGUIPopTopSel;

// Declarations
class cGUIContentsExecutor;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIContentsExecutor : public cUIObject
{
public:
    enum PR
    {
        PR_NONE = 0,
        PR_INIT = 1,
        PR_ARC = 2,
        PR_CREATE_SHOP_BOARD = 3,
        PR_MISSION_SELECT = 4,
        PR_MISSION_INFO = 5,
        PR_PARTY_INVITATION = 6,
        PR_ENTRYBOARD = 7,
        PR_ENTRYBOARD_WAIT = 8,
        PR_ENTRY_LEARDER = 9,
        PR_ENTRY_MEMBER = 10,
        PR_DEPARTURE_LEADER = 11,
        PR_DEPARTURE_MEMBER = 12,
        PR_NEWSPAPER = 13,
        PR_SELECT_MEMBER_LIST = 14,
        PR_SELECT_READY = 15,
        PR_SELECT_LESS_MEMBER = 16,
        PR_UNION_SEARCH = 17,
        PR_UNION_EXTEND = 18,
        PR_UNION_CANCEL = 19,
        PR_UNION_RECREATE = 20,
        PR_UNION_EDIT_PASS = 21,
        PR_UNION_EDIT_COMMENT = 22,
        PR_UNION_PARTY_INVITATION = 23,
        RP_PAWN_WAIT = 24,
        RP_PAWN_SELECT = 25,
        PR_EXIT_CANCEL = 26,
        PR_EXIT_START_MISSION = 27,
        PR_MAX = 28,
    };
    enum MEMBER_INFO_PROC
    {
        MEMBER_INFO_INIT = 0,
        MEMBER_INFO_MOVE = 1,
    };
    enum
    {
        STATUS_NONE = 0,
        STATUS_NET_WAIT = 1,
    };
    enum
    {
        FLG_NONE = 0,
        FLG_OPEN_MENU = 1,
        FLG_OPEN_NEWS = 2,
        FLG_OPEN_INVITE = 4,
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
    cGUIContentsExecutor();
    cGUIContentsExecutor(bool isLeader);
    void init(bool isLeader);
    virtual ~cGUIContentsExecutor();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void release();
    virtual void update();  // vtable slot 6
    virtual void updateUnitPtr();  // vtable slot 7
    void start(u32 openFlag);
    bool isEnd();
    bool isEntry();
    PR getProc();
    bool checkChangeLeader();
    void checkPreProc();
    void setNpcId(u32 npc);
private:
    void setProc(PR pr);
    void setMemberInfoProc(MEMBER_INFO_PROC pr);
    bool isInit();
    void cycleContentsCallback(u32 ErrorCode);
    void onStatus(u32 Status);
    void offStatus(u32 Status);
    bool isOnStatus(u32 Status);
    void settingEntryboardInfoEnableCtrl(bool flg);
    bool isOpenFlag(u32 flag) const;
private:
    PR mProc;  // offset: 0x8
    PR mOldProc;  // offset: 0xc
    MEMBER_INFO_PROC mMemberInfoProc;  // offset: 0x10
    TICKET mArc;  // offset: 0x18
    uGUIPopTopSel* mpUnitTopSel;  // offset: 0x20
    uGUIPopEventTop* mpUnitPopEventTop;  // offset: 0x28
    uGUIEntryBoardInfo* mpUnitEntryBoardInfo;  // offset: 0x30
    uGUIMissionResult* mpUnitMissionResult;  // offset: 0x38
    uGUIContentsBoard* mpUnitContentsBoard;  // offset: 0x40
    uGUIMissionInfo* mpUnitMissionInfo;  // offset: 0x48
    uGUINewspaper* mpUnitNewspaper;  // offset: 0x50
    uGUIPopFilter* mpUnitPopFilter;  // offset: 0x58
    nNet::stEntryBoardItemInfo mBoardInfo;  // offset: 0x60
    bool mIsEnd;  // offset: 0x140
    bool mIsInit;  // offset: 0x141
    bool mIsEntry;  // offset: 0x142
    bool mIsLeader;  // offset: 0x143
    bool mIsMemberInfoSetup;  // offset: 0x144
    bool mIsSolo;  // offset: 0x145
    u32 mStatus;  // offset: 0x148
    u32 mNpcId;  // offset: 0x14c
    u32 mOpenFlag;  // offset: 0x150
    s32 mDetailIndex;  // offset: 0x154
    u32 mPawnNum;  // offset: 0x158
public:
    static MyDTI DTI;
};
