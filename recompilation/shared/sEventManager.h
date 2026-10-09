#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cSystem.h"
#include "nStage.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cCamExParam;
class cContextInstHm;
class cEfcHandle;
class cEventParam;
namespace nStage { struct stEventParam; }
class rCameraParamList;
class rEffectProvider;
class rEventParam;
class rSoundRequest;
class rSoundStreamRequest;
class rVibration;
class uControl;
class uCoord;
class uDDOModel;
class uGUIEventSkip;
class uGUISystemMsg;
class uHuman;
class uMovie;
class uScheduler;

// Declarations
class sEventManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sEventManager : public cSystem
{
public:
    enum SYNC_FLAG
    {
        SYNC_FLAG_READY = 0,
        SYNC_FLAG_CANCEL = 1,
        SYNC_FLAG_FINISH = 2,
    };
    enum
    {
        R0_IDLE = 0,
        R0_INIT = 1,
        R0_SYNC = 2,
        R0_PLAY = 3,
        R0_CANCEL = 4,
        R0_FINAL = 5,
        R0_INIT_FSM = 6,
        R0_PLAY_FSM = 7,
        R0_JUMP = 8,
        R0_WAIT_JUMP_STAGE = 9,
    };
    enum
    {
        RNOSKIP_EXEC = 0,
        RNOSKIP_DIALOG = 1,
        RNOSKIP_PMSKIP = 2,
        RNOSKIP_SKIP = 3,
    };
    enum
    {
        SDL_FSM_SUB_NUM = 3,
        EFC_FSM_NUM = 2,
        FSM_EFC_TYPE_COMMON = 0,
        FSM_EFC_TYPE_EVENT = 1,
        FSM_EFC_TYPE_OM = 2,
        FSM_EFC_TYPE_EVENT2 = 3,
    };
public:
    class MyDTI;
    struct EvtEPV;
    struct EvtEPVOM;
    class cNpcId;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct EvtEPV
    {
    public:
        u32 mEfcId;  // offset: 0x0
        cEfcHandle* mpEfcHandle;  // offset: 0x8
        uDDOModel* mpEfcParent;  // offset: 0x10
    };
public:
    struct EvtEPVOM
    {
    public:
        u32 mOmId;  // offset: 0x0
        rEffectProvider* mprEfcPvd;  // offset: 0x8
    };
public:
    class cNpcId : public MtObject
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
        cNpcId();
        // Address: 0x01982850 - 0x01982851 (1 bytes)
        virtual ~cNpcId() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mNpcId;  // offset: 0x8
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
    sEventManager();
    virtual ~sEventManager();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    void clear();
    static sEventManager* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void loadCmnResource();
    void releaseCmnResource();
    s32 getEventID(s32 stage, s32 no);
    void reqPlay(s32 no);
    void getEventStage(s32 eventID, s32& stage, s32& no);
    u32 getEventFrame();
    bool isPlaying();
    void setPause(bool f);
    void setFinal();
    void setCancel();
    bool movieSync();
    void updateMovieStream();
    bool loadResource();
    bool loadResourceFSM();
    f32 getFrame();
    bool reserveEvent(s32 stageNo, s32 evNo, s32 startStage, s32 startPosNo);
    void reserveEventExec();
    bool requestEvent(s32 stageNo, s32 evNo, s32 startStage, s32 startPosNo);
    bool requestEventJumpStage(s32 stageNo, s32 evNo, s32 jumpStartPosNo);
    bool finishEvent();
    bool isPlayingNow();
    bool isRequestEvent();
    bool isReserveEvent();
    void setEventPlay(bool f);
    bool isEventPlay();
    nStage::stEventParam& getReqEventParam();
    cEventParam* getExecEventParam();
    cEventParam* getEventParam(s32 event_id);
    void setSyncEvent(SYNC_FLAG type, u32 index, bool isSend);
    bool isSyncEvent(SYNC_FLAG type, u32 index);
    bool isSyncEventAll(SYNC_FLAG type);
    void clearSyncEvent(SYNC_FLAG type, u32 index, bool isSend);
    void setSyncReadyEvent();
    bool isSyncReadyEventAll();
    void setSyncFinishEvent();
    bool isSyncFinishEventAll();
    void clearSyncFinishEvent();
    bool isReadyBit(u32 index) const;
    bool isCancelBit(u32 index) const;
    bool isFinishBit(u32 index) const;
    void onReadyBit(u32 index);
    void onCancelBit(u32 index);
    void onFinishBit(u32 index);
    void offReadyBit(u32 index);
    void offCancelBit(u32 index);
    void offFinishBit(u32 index);
    void setTagIdHaveOM(uControl* pCtrl, const u32 npcId);
    void setContinuation(bool flag);
    bool isContinuation();
    void addFsmNpcId(u32 npcId);
    void clearFsmNpcList();
    const MtTypedArray<cNpcId>& getFsmNpcIdList() const;
    void updateCasting();
private:
    void move_r0_idle();
    void move_r0_init();
    void move_r0_sync();
    void move_r0_play();
    void move_r0_cancel();
    void move_r0_final();
    void move_r0_init_fsm();
    void move_r0_fsm();
    void move_r0_jump();
    void move_r0_wait_jump_stage();
    bool checkCancelButton();
    bool checkSkipButton();
public:
    rSoundStreamRequest* getFsmBgmStqr();
    void setEfcHandle(u32 id, cEfcHandle* pHandle, uDDOModel* pModel);
    s32 getEfcHandleIndex(u32 id);
    void resetEfcHandle(s32 index);
    cEfcHandle* getEfcHandle(s32 index);
    rEffectProvider* getEfcOm(u32 id);
    void resetEfcOm();
    void setEventSoundRequest(u32 eventId);
    void releaseEventSoundRequest();
    void callEventSe(u32 se, uCoord* pModel, s32 jointNo);
    void callEventSe(u32 se, MtVector3& pos);
    void reqEventVib(u32 vib);
    u32 getRnoSkip();
    void setAdjustTarget(uHuman* target);
    uHuman* getAdjustTarget();
    void onContentInterrupt();
    void clearContentInterrupt();
    bool isContentInterrupt();
    void callStartSubSdl(u32 sdl, bool isLoop);
    void killSubSdl(u32 sdl);
    rEffectProvider* getEfcPvdEx(u32 index);
    u32 getEfcPvdIndex(u32 type);
    void setEventEpvEx();
    void releaseEventEpvEx();
    void setEventCamera(u32 eventId);
    void releaseEventCamera();
    void requestEventCamera(u32 no, const uDDOModel* pObj);
    const cCamExParam* getEventCameraParam(u32 no) const;
    f32 getOMAQCScale(s32 EventId);
    void setOmAQCScaleForFSMEvent(s32 EventId);
    void resetOmAQCScaleForFSMEvent();
public:
    u32 mCastNum;  // offset: 0x14
    u32 mCastTbl[16];  // offset: 0x18
    const cContextInstHm* mpContext[8];  // offset: 0x58
private:
    union
    {
    public:
        u32 mRno;  // offset: 0x0
        struct
        {
        public:
            u32 mRno0 : 8;  // offset: 0x0
            u32 mRno1 : 8;  // offset: 0x0
            u32 mRno2 : 8;  // offset: 0x0
            u32 mRno3 : 8;  // offset: 0x0
        };  // offset: 0x0
    };  // offset: 0x98
public:
    bool mEventPlay;  // offset: 0x9c
    s32 mEndFrame;  // offset: 0xa0
    u32 mOldFrame;  // offset: 0xa4
    s32 mEventNo;  // offset: 0xa8
    uScheduler* mpScheduler;  // offset: 0xb0
    uScheduler* mpSchdlLight;  // offset: 0xb8
    uScheduler* mpSchdlFSM;  // offset: 0xc0
    uScheduler* mpSchdlFSMSub[3];  // offset: 0xc8
    rSoundStreamRequest* mpFsmBgmStqr;  // offset: 0xe0
    uMovie* mpuMovie;  // offset: 0xe8
    f32 mMovieRate;  // offset: 0xf0
    u32 mMovieTime;  // offset: 0xf4
    rEventParam* mprEventParam;  // offset: 0xf8
    cEventParam* mpParam;  // offset: 0x100
    cEventParam* mpOldParam;  // offset: 0x108
    s32 mReqEventNo;  // offset: 0x110
    nStage::stEventParam mReqEventParam;  // offset: 0x114
    s32 mLastPlayEventNo;  // offset: 0x120
    u32 mMovieState;  // offset: 0x124
    u32 mReadyBit;  // offset: 0x128
    u32 mCancelBit;  // offset: 0x12c
    u32 mFinishBit;  // offset: 0x130
    bool mIsSendBit;  // offset: 0x134
    bool mIsContinuation;  // offset: 0x135
    bool mIsContentsInterrupt;  // offset: 0x136
    f32 mMovieSyncTimer;  // offset: 0x138
    f32 mEventStreamReadyTimer;  // offset: 0x13c
    EvtEPV mEvtEPV[32];  // offset: 0x140
    EvtEPVOM mEvtEPVOM[16];  // offset: 0x440
    rEffectProvider* mprEfcPvdEx[2];  // offset: 0x540
    rSoundRequest* mprSndReq;  // offset: 0x550
    rVibration* mprVib;  // offset: 0x558
    uGUIEventSkip* mpGUIEventSkip;  // offset: 0x560
    uGUISystemMsg* mpGUIDialog;  // offset: 0x568
    uHuman* mpAdjustTarget;  // offset: 0x570
    rCameraParamList* mprCamPrm;  // offset: 0x578
    nStage::stEventParam mReserveEventParam;  // offset: 0x580
    MtTypedArray<cNpcId> mFsmNpcList;  // offset: 0x590
private:
    static sEventManager* mpInstance;
public:
    static MyDTI DTI;
    static const u32 CastMax = 16;
};

// Inline, no code of its own: checked where it is inlined.
inline sEventManager* sEventManager::getInstance() {
    return ::sEventManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sEventManager::cNpcId::cNpcId() {
    this->mNpcId = static_cast<u32>(0);
}
