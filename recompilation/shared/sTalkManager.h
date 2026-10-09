#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cSystem.h"
#include "nQuest.h"
#include "nTalk.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cTalkMsgData;
class cTalkState;
class cpTalk;
namespace nCharacterData { struct stCharacterName; }
namespace nQuest { class QUEST_ID; }
namespace nQuest { class SCHEDULE_ID; }
namespace nTalk { class cSelectData; }
namespace nTalk { class cSelectMember; }
class rGUIMessage;
class uControl;
class uDDOModel;
class uGUIBase;
class uNpc;

// Declarations
class sTalkManager;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using CHAR_NAME = nCharacterData::stCharacterName;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nTalk { using SelectDataArray = MtTypedArray<nTalk::cSelectData>; }
namespace nTalk { using SelectMemberArray = MtTypedArray<nTalk::cSelectMember>; }
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;

class sTalkManager : public cSystem
{
public:
    enum
    {
        R0_TALK_WAIT = 0,
        R0_TALK_START = 1,
        R0_TALK_NOW = 2,
        R0_TALK_END = 3,
        R0_TALK_EXIT = 4,
    };
    enum
    {
        TALK_TYPE_NPC = 0,
        TALK_TYPE_FSM_EVENT = 1,
    };
    enum
    {
        STATUS_WAIT = 0,
        STATUS_TALK_NOW = 1,
        STATUS_EXIT = 2,
    };
    enum
    {
        R0_FSM_TELL_WAIT = 0,
        R0_FSM_TELL_INIT = 1,
        R0_FSM_TELL_MOVE = 2,
        R0_FSM_TELL_END = 3,
    };
    enum
    {
        R0_EVENT_MSG_NO = 0,
        R0_CREATE_WINDOW = 1,
        R0_DISP_MSG = 2,
        R0_DISP_MSG_WAIT = 3,
        R0_DISP_END = 4,
    };
public:
    class MyDTI;
    class cTellQueueNode;
public:
    using TellQueue = MtTypedArray<sTalkManager::cTellQueueNode>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTellQueueNode : public MtObject
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
        u32 getMsgType() const;
        nQuest::QUEST_ID getQuestId() const;
        u32 getGroupSerialNo() const;
        f32 getDispTime() const;
        f32 getWaitTime() const;
        cTellQueueNode();
        cTellQueueNode(u32 msgType, u32 questId, u32 groupSerialNo, f32 dispTime, f32 waitTime);
        virtual ~cTellQueueNode();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::QUEST_ID mQuestId;  // offset: 0x8
        u32 mMsgType;  // offset: 0x18
        u32 mGroupSerialNo;  // offset: 0x1c
        f32 mDispTime;  // offset: 0x20
        f32 mWaitTime;  // offset: 0x24
    public:
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
    void setNpcWindowText(cTalkMsgData& MsgData);
    MT_CTSTR getTalkItemName(u32 Type);
protected:
    void notifyTalkStart(uDDOModel* pUnit);
    void setTalkTarget(uDDOModel* pUnit);
    void updateDispPage();
    void resetDispPage();
public:
    uGUIBase* createGUISingleton(const MtDTI* pDTI);
    uGUIBase* setGUISingleton(uGUIBase* pGUI);
    void deleteGUISingleton();
    bool isMoveGUISingleton();
    bool isMoveGUISingleton(uGUIBase* pGUI);
    bool isEndGUISingleton();
    void notifyUpdatesQuestPurpose(nQuest::SCHEDULE_ID scheduleId);
    void notifyChangeLeader();
    uNpc* getNpcUnit() const;
    uControl* getNpcCtrl() const;
    s32 getNpcId() const;
    uDDOModel* getTalkTarget() const;
    cpTalk* getTalkComponent() const;
    u32 getNpcSex() const;
    u32 getStatus() const;
    bool isWait() const;
    bool isTalkNow() const;
    bool isTalkExited() const;
    bool isQuestTalkExited(nQuest::SCHEDULE_ID scheduleId) const;
    bool isFuncTalkNow(u32 funcId) const;
    u8 getRno() const;
    u8 getInnRno0() const;
    void setScheduleId(nQuest::SCHEDULE_ID scheduleId);
protected:
    void setRno(u8 r0);
public:
    void forceInterrupt();
    void killAllNpcMessage();
    void callFSMEventMsg(u32 MsgType, u32 QstNo, u32 GrpNo, f32 DispTime, f32 WaitTime, bool IsUseSerial, bool isHideMessage);
    void callQuestEventMsg(u32 msgType, u32 questId, u32 grSerialNo, f32 dispTime, f32 waitTime);
    void stopQuestEventMsg();
    bool isEndFSMEventMsg() const;
    bool isNormalTalk() const;
    void setSendEventMsg(bool flag);
    u32 getEventMsgType() const;
    nQuest::QUEST_ID getEventQstNo() const;
    u32 getEventMsgGrpNo() const;
    void requestPawnTalk(uDDOModel* pUnit);
    bool isPawnTalk(uDDOModel* pUnit);
    nQuest::QUEST_ID getTargetQuestId();
    bool isChangeClanManager();
    void setChangeClanManager(bool IsChange);
protected:
    void moveFSMEventMsg();
    void moveFSMEventMsg_CreateWindow();
    void moveFSMEventMsg_DispMsg();
    void moveFSMEventMsg_DispMsgWait();
    void moveFSMEventMsg_DispEnd();
    void moveQuestEventMsg();
    void moveNormalMsg();
    bool isNormalMsgInterrupt();
    void moveTalkSTart();
    void moveTalkNow();
    void moveTalkEnd();
    void moveTalkExit();
    void requestVoice(cTalkMsgData& MsgData);
public:
    void requestMessageFromGroupSerial(u32 group_serial);
    void requestMessageFromGroupType(u32 group_type);
    void stopVoice();
    void loadCommonResource();
    void releaseCommonResource();
    void releaseTalkState();
private:
    void updateUnitPtr();
public:
    bool isEndTellMsg() const;
    void moveTellMsg();
    void moveTellMsg_Wait();
    void moveTellMsg_Init();
    void moveTellMsg_Move();
    void moveTellMsg_End();
    const nTalk::cSelectData* getSelectData(s32 index) const;
    const nTalk::cSelectMember* getSelectMember(s32 index) const;
    u32 getSelectMemberNum() const;
    MT_CTSTR getFuncName(MT_CTSTR indexName) const;
    void addSelectData(u32 type, u32 param0, u32 param1);
    void addSelectMember(u32 slot, CHAR_NAME name, u32 pawnId);
    void clearSelectData();
    void clearSelectMember();
    ARC_TAGID createPawnTalkArcTag(u32 type, u32 personality);
    static sTalkManager* getInstance();
    sTalkManager();
    virtual ~sTalkManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
    void finalGame();
protected:
    nTalk::SelectDataArray mSelectData;  // offset: 0x18
    nTalk::SelectMemberArray mSelectMember;  // offset: 0x38
    TellQueue mTellQueue;  // offset: 0x58
    cTalkState* mpTalkState;  // offset: 0x78
    uDDOModel* mpTalkTarget;  // offset: 0x80
    uGUIBase* mpGUISingletonMenu;  // offset: 0x88
    rGUIMessage* mpFuncSelectItemName;  // offset: 0x90
    rGUIMessage* mpTalkSelectItemName;  // offset: 0x98
    nQuest::QUEST_ID mEventQstNo;  // offset: 0xa0
    nQuest::SCHEDULE_ID mSelectQuestScheduleId;  // offset: 0xb0
    f32 mTellMsgTimer;  // offset: 0xc0
    u32 mTalkType;  // offset: 0xc4
    s32 mDispPageIdx;  // offset: 0xc8
    u32 mVoiceStreamHandle;  // offset: 0xcc
    f32 mCheckCylinderHeight;  // offset: 0xd0
    f32 mCheckCylinderRadius;  // offset: 0xd4
    u32 mEventMsgType;  // offset: 0xd8
    u32 mEventMsgGrpNo;  // offset: 0xdc
    f32 mEventMsgDispTime;  // offset: 0xe0
    f32 mEventMsgWaitTime;  // offset: 0xe4
    f32 mEventMsgTimer;  // offset: 0xe8
    u8 mRno0;  // offset: 0xec
    u8 mTellRno;  // offset: 0xed
    bool mEventUseSerial;  // offset: 0xee
    bool mIsHideMessage;  // offset: 0xef
    bool mIsEndEventMsg;  // offset: 0xf0
    bool mSendEventMsg;  // offset: 0xf1
    bool mIsChangeClanManager;  // offset: 0xf2
public:
    static MyDTI DTI;
private:
    static sTalkManager* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sTalkManager* sTalkManager::getInstance() {
    return ::sTalkManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sTalkManager::cTellQueueNode::cTellQueueNode() {
    this->mDispTime = 0.0f;
    this->mWaitTime = 0.0f;
    this->mMsgType = static_cast<u32>(0);
    this->mGroupSerialNo = static_cast<u32>(0);
}
