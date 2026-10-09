#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cArcLoader.h"
#include "cSystem.h"
#include "cTalkMsgData.h"
#include "nDDOUtility.h"
#include "rAIPawnAutoWordTbl.h"
#include "rSoundStreamRequest.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cAIPawnAutoMotionNode;
class cAIPawnAutoWordNode;
class cTalkMsgData;
class rAIPawnAutoMotionTbl;
class rAIPawnAutoWordTbl;
class rSoundStreamRequest;
class uDDOModel;

// Declarations
class sAIPawnTalkMgr;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnTalkMotGroupArray = nDDOUtility::cArray<unsigned short, 44>;
using cArcLoader01 = cArcLoader<1>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sAIPawnTalkMgr : public cSystem
{
public:
    enum
    {
        ACTIVE_RNO_WAIT = 0,
        ACTIVE_RNO_MOVE = 1,
        ACTIVE_RNO_NUM = 2,
    };
public:
    class MyDTI;
    class cAIPawnTalkInfo;
    class cAIPawnTalkWaitNode;
public:
    using cReqMsgNoStack = nDDOUtility::cArray<unsigned int, 8>;
    using cReqPartyIndexStack = nDDOUtility::cArray<int, 8>;
    using cAIPawnTalkInfoStack = nDDOUtility::cArray<sAIPawnTalkMgr::cAIPawnTalkInfo, 16>;
    using cAIPawnTalkWaitPool = nDDOUtility::cArray<sAIPawnTalkMgr::cAIPawnTalkWaitNode, 32>;
    using cAIPawnTalkWaitStack = MtTypedArray<sAIPawnTalkMgr::cAIPawnTalkWaitNode>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAIPawnTalkInfo : public MtObject
    {
    public:
        enum
        {
            PW_ID_INV = -1,
        };
    public:
        class MyDTI;
    public:
        using cPawnName = nDDOUtility::cArray<char, 13>;
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
        cAIPawnTalkInfo();
        virtual ~cAIPawnTalkInfo();
        bool initPawnTalkInfo(s32 talkPawnMemberIndex);
        bool updatePawnTalkInfo(bool full);
        void resetPawnTalkInfo();
        void loadPawnVoiceArc();
        void loadPawnVoiceRes();
        void loadPawnTalkMsgData();
        void incRefCntPawnTalkInfo();
        void decRefCntPawnTalkInfo();
    public:
        MtVector3 mPawnRealPos;  // offset: 0x10
        cPawnName mPawnFirstName;  // offset: 0x20
        u32 mPawnSex;  // offset: 0x30
        u32 mPawnVoiceType;  // offset: 0x34
        u32 mPawnPersonality;  // offset: 0x38
        s32 mPawnPitch;  // offset: 0x3c
        s32 mRefCnt;  // offset: 0x40
        s32 mPawnMemberIndex;  // offset: 0x44
        s32 mPawnStageNo;  // offset: 0x48
        f32 mInfoLifeTime;  // offset: 0x4c
        bool mPawnMaster;  // offset: 0x50
        bool mPawnLeave;  // offset: 0x51
        cArcLoader01 mVoiceArc;  // offset: 0x58
        res_ptr<rSoundStreamRequest> mpVoiceRes;  // offset: 0x98
        cTalkMsgData mTalkMsgData;  // offset: 0xa0
        static MyDTI DTI;
    };
public:
    class cAIPawnTalkWaitNode : public MtObject
    {
    public:
        enum
        {
            CTR_FLAG_BE = 0,
            CTR_FLAG_MSG_REQ = 1,
            CTR_FLAG_USE_POS = 2,
            CTR_FLAG_REQ_ERASE = 3,
            CTR_FLAG_NUM = 4,
        };
    public:
        class MyDTI;
    public:
        using cCtrlFlag = nDDOUtility::cBitSet<4>;
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
        cAIPawnTalkWaitNode();
        virtual ~cAIPawnTalkWaitNode();
        void releasePawnTalkWaitNode();
        void copyWaitNode(sAIPawnTalkMgr::cAIPawnTalkWaitNode& node);
        sAIPawnTalkMgr::cAIPawnTalkInfo* getTalkInfo();
        const sAIPawnTalkMgr::cAIPawnTalkInfo* getTalkInfo() const;
    private:
        const sAIPawnTalkMgr::cAIPawnTalkInfo* getTalkInfoCore() const;
    public:
        sAIPawnTalkMgr::cAIPawnTalkInfo* mpTalkInfo;  // offset: 0x8
        u32 mReqMsgNo;  // offset: 0x10
        u32 mReqSndNo;  // offset: 0x14
        cCtrlFlag mCtrlFlag;  // offset: 0x18
        f32 mLifeTime;  // offset: 0x1c
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
    sAIPawnTalkMgr();
    virtual ~sAIPawnTalkMgr();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    static sAIPawnTalkMgr* getInstance();
    void initGame();
    void initStage();
    void reqPawnTalk(s32 talkPawnMemberIndex, u32 msgNo);
    void updateSendPawnTalk();
private:
    void reqPawnTalkCore(cAIPawnTalkInfo& info, u32 msgNo, bool usePos);
public:
    void receivePawnTalk(u32 talkPawnMemberIndex, u32 msgNo);
    void updatePawnTalkMsgActive();
    void updatePawnTalkMsgStack();
    void releasePawnTalkMsgActive();
    bool isPauseStatus();
    bool isLowLvMessage(u32 msgNo);
    void eraseLowLvMessage();
private:
    cAIPawnTalkWaitNode* allocAIPawnTalkWaitNode();
    bool updatePawnTalkMessageNode(cAIPawnTalkWaitNode& node);
    void updatePawnTalkMessageChat(cAIPawnTalkWaitNode& node);
    static bool sortFuncAIPawnTalkWaitNode(const cAIPawnTalkWaitNode* pA, const cAIPawnTalkWaitNode* pB, u32);
public:
    void initPawnTalkInfo(s32 talkPawnMemberIndex);
    void releasePawnTalkInfo(s32 talkPawnMemberIndex);
    cAIPawnTalkInfo* findPawnTalkInfo(s32 talkPawnMemberIndex, bool disablenLeave);
    void updatePawnTalkInfoStack();
    void resetPawnTalkSituation();
    void updatePawnTalkSituation();
    u32 getPawnTalkMotionNum(u32 situation);
    cAIPawnAutoMotionNode* getPawnTalkMotionNode(u32 situation, u32& beginIdx);
    u32 getPawnTalkMotionGroup(cAIPawnTalkMotGroupArray& dst, u32 situation);
    void setPawnTalkSituationQuest(bool success);
    bool isPawnTalkSituationQuestSuccess() const;
    bool isPawnTalkSituationQuestFailed() const;
    bool isPawnTalkSituationFieldIn() const;
    u32 convTalkSituationToMot(u32 situation) const;
    u32 convTalkSituationFromMot(u32 motSituation) const;
    u32 convTalkSituationWordToMsgNo(u32 wordSituation, u32 personal) const;
    u32 convTalkSituationWordToSndNo(u32 wordSituation, u32 personal) const;
    u32 lotAIPawnTalkMotioin(uDDOModel* pPawn, u32 motSituation, u32* pDstMoveType);
    u32 lotAIPawnTalkWord(uDDOModel* pPawn, u32 situation);
    f32 lotAIPawnTalkWaitFrame(uDDOModel* pPawn, u32 motSituation);
    u32 getAIPawnTalkPartyInMsg(uDDOModel* pPawn);
    void setIsSituationInBase(bool flg);
    bool isSituationInBase() const;
    void setIsSituationInBaseArea(bool flg);
    bool isSituationInBaseArea() const;
    void setIsSituationTargetCore(bool flg);
    bool isSituationTargetCore() const;
    void setPawnTalknTargetCoreTimer(f32 time);
    f32 getPawnTalknTargetCoreTimer() const;
private:
    void searchAIPawnTalkMotion(MtTypedArray<cAIPawnAutoMotionNode>& dst, uDDOModel* pPawn, u32 motGroup);
    void searchAIPawnTalkWordNode(MtTypedArray<cAIPawnAutoWordNode>& dst, uDDOModel* pPawn, u32 situation);
    cAIPawnAutoMotionNode* lotPawnTalkMotNode(uDDOModel* pPawn, u32 motSituation);
public:
    u32 mReqNum;  // offset: 0x14
    cReqMsgNoStack mReqMsgNoStack;  // offset: 0x18
    cReqPartyIndexStack mReqPartyIndexStack;  // offset: 0x38
private:
    s32 mReqCounter;  // offset: 0x58
    cAIPawnTalkInfoStack mTalkInfoStack;  // offset: 0x60
    res_ptr<rAIPawnAutoMotionTbl> mpAIPawnTalkMotionTbl;  // offset: 0xf60
    res_ptr<rAIPawnAutoWordTbl> mpAIPawnTalkWordTbl;  // offset: 0xf68
    cAIPawnTalkWaitPool mAIPawnTalkWaitPool;  // offset: 0xf70
    cAIPawnTalkWaitStack mAIPawnTalkWaitStack;  // offset: 0x1370
    bool mAIPawnTalkWaitStakAdd;  // offset: 0x1390
    cAIPawnTalkWaitNode mActiveNode;  // offset: 0x1398
    u32 mActiveRno;  // offset: 0x13b8
    u32 mActiveSoundHandle;  // offset: 0x13bc
    f32 mPawnTalkQuestSuccsessTimer;  // offset: 0x13c0
    f32 mPawnTalkQuestFailedTimer;  // offset: 0x13c4
    f32 mPawnTalkFieldInTimer;  // offset: 0x13c8
    bool mPawnTalkFieldInOldLobby;  // offset: 0x13cc
    bool mIsSituationInBase;  // offset: 0x13cd
    bool mIsSituationInBaseArea;  // offset: 0x13ce
    bool mIsSituationTargetCore;  // offset: 0x13cf
    f32 mPawnTalknTargetCoreTimer;  // offset: 0x13d0
public:
    static MyDTI DTI;
private:
    static sAIPawnTalkMgr* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sAIPawnTalkMgr* sAIPawnTalkMgr::getInstance() {
    return ::sAIPawnTalkMgr::mpInstance;
}
