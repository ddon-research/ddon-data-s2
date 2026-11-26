#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cAIUserProcess.h"
#include "cFSMRelate.h"

// Forward declarations
struct MT_ENUM;
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cAICopiableParameter;
class cFSMRelate;
class cScenario;

// Declarations
class cFSMOrderParam;
class cFSMOrderParamAreaHit;
class cFSMOrderParamBGMCommon;
class cFSMOrderParamBGMRequest;
class cFSMOrderParamBGMStop;
class cFSMOrderParamCallAnnounce;
class cFSMOrderParamCallEvent;
class cFSMOrderParamCamera;
class cFSMOrderParamChangeBattleThink;
class cFSMOrderParamCheckLayout;
class cFSMOrderParamCtrlSubSdl;
class cFSMOrderParamFlagCommon;
class cFSMOrderParamFlagQuest;
class cFSMOrderParamIsMyQuestFlag;
class cFSMOrderParamJumpArea;
class cFSMOrderParamJumpPos;
class cFSMOrderParamQuestInfo;
class cFSMOrderParamSetCallSe;
class cFSMOrderParamSetDispUnit;
class cFSMOrderParamSetEffect;
class cFSMOrderParamSetEnemy;
class cFSMOrderParamSetFade;
class cFSMOrderParamSetLayout;
class cFSMOrderParamSetLocationName;
class cFSMOrderParamSetOpenDoor;
class cFSMOrderParamSetVib;
class cFSMOrderParamStartQuake;
class cFSMOrderParamStopQuake;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cFSMOrderParam : public cAICopiableParameter
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
public:
    static MyDTI DTI;
};

class cFSMOrderParamAreaHit : public cFSMOrderParam
{
public:
    enum
    {
        ACT_IS_HIT = 0,
        ACT_IS_DETECT = 1,
        ACT_IS_DONE = 2,
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
    cScenario* getScenario() const;
    cFSMOrderParamAreaHit();
    virtual ~cFSMOrderParamAreaHit();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mAct;  // offset: 0x8
    u32 mTaskType;  // offset: 0xc
    u32 mSceNo;  // offset: 0x10
    static MyDTI DTI;
};

class cFSMOrderParamBGMCommon : public cFSMOrderParam
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
    cFSMOrderParamBGMCommon();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mRequestNo;  // offset: 0x8
    static MyDTI DTI;
};

class cFSMOrderParamBGMRequest : public cFSMOrderParam
{
public:
    enum
    {
        BGM_REQ_EDIT_FIELD = 0,
        BGM_REQ_EDIT_BATTLE = 1,
        BGM_REQ_EDIT_QUEST = 2,
        BGM_REQ_EDIT_EV_QUEST_START = 3,
        BGM_REQ_EDIT_EV_QUEST_END = 4,
        BGM_REQ_EDIT_EV_ANGER_01 = 5,
        BGM_REQ_EDIT_EV_DANGER_01 = 6,
        BGM_REQ_EDIT_EV_HORROR_01 = 7,
        BGM_REQ_EDIT_EV_PRESURE_01 = 8,
        BGM_REQ_EDIT_EV_RELAX_01 = 9,
        BGM_REQ_EDIT_EV_SAD_01 = 10,
        BGM_REQ_EDIT_EV_KISHIDAN = 11,
        BGM_REQ_EDIT_EV_ONESHOT_01 = 12,
        BGM_REQ_EDIT_EV_ONESHOT_02 = 13,
        BGM_REQ_EDIT_EV_ONESHOT_03 = 14,
        BGM_REQ_EDIT_EV_ONESHOT_04 = 15,
        BGM_REQ_EDIT_EV_FSM_BATTLE_01 = 16,
        BGM_REQ_EDIT_EV_FSM_BATTLE_02 = 17,
        BGM_REQ_EDIT_EV_FSM_BATTLE_SP = 18,
        BGM_REQ_EDIT_EV_FSM_BATTLE_SPEND = 19,
        BGM_REQ_EDIT_EV_RANSEN_BGM = 20,
        BGM_REQ_EDIT_EV_ANGER_02 = 21,
        BGM_REQ_EDIT_EV_SAD_02 = 22,
        BGM_REQ_EDIT_EV_ST0411_EV00 = 23,
        BGM_REQ_EDIT_EV_Q22_ST0410_EV10 = 24,
        BGM_REQ_EDIT_EV_MAIN_TITLE = 25,
        BGM_REQ_EDIT_STOP = 26,
        BGM_REQ_EDIT_BATTLE_CONTINUE = 27,
        BGM_REQ_EDIT_EV_Q22_ST0201_EV95 = 28,
        BGM_REQ_EDIT_EV_EM_002 = 29,
        BGM_REQ_EDIT_EV_ST0418_EV005 = 30,
        BGM_REQ_EDIT_EV_RES = 31,
        BGM_REQ_EDIT_QUEST_FIX = 32,
    };
    enum
    {
        BGM_REQ_FILED = 0,
        BGM_REQ_BATTLE = 1,
        BGM_REQ_EVENT = 2,
        BGM_REQ_QUEST = 3,
        BGM_REQ_STOP = 4,
        BGM_REQ_BATTLE_CONTINUE = 5,
        BGM_REQ_EVENT_RES = 6,
        BGM_REQ_QUEST_FIX = 7,
        BGM_REQ_NUM = 8,
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
    void setRequestEditType(u32 editType);
    u32 getRequestEditType() const;
    cFSMOrderParamBGMRequest();
    virtual ~cFSMOrderParamBGMRequest();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mBgmRequestType;  // offset: 0x8
    u32 mBgmRequestNo;  // offset: 0xc
    u32 mBgmRequestEditType;  // offset: 0x10
    static MyDTI DTI;
};

class cFSMOrderParamBGMStop : public cFSMOrderParam
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
    cFSMOrderParamBGMStop();
    virtual ~cFSMOrderParamBGMStop() {}
public:
    static MyDTI DTI;
};

class cFSMOrderParamCallAnnounce : public cFSMOrderParam
{
public:
    enum
    {
        TYPE_COMMON = 0,
        TYPE_QUEST = 1,
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
    cFSMOrderParamCallAnnounce();
    virtual ~cFSMOrderParamCallAnnounce();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mType;  // offset: 0x8
    u32 mQuestId;  // offset: 0xc
    u32 mMsgNo;  // offset: 0x10
    static MyDTI DTI;
};

class cFSMOrderParamCallEvent : public cFSMOrderParam
{
public:
    class MyDTI;
    class cNpcId;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
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
        virtual ~cNpcId() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void copy(cFSMOrderParamCallEvent::cNpcId* pSrc);  // vtable slot 6
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
    cFSMOrderParamCallEvent();
    virtual ~cFSMOrderParamCallEvent();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void copy(cAICopiableParameter* pParam);  // vtable slot 6
public:
    s32 mStageNo;  // offset: 0x8
    s32 mEventNo;  // offset: 0xc
    MtTypedArray<cNpcId> mNpcArray;  // offset: 0x10
    static MyDTI DTI;
};

class cFSMOrderParamCamera : public cFSMOrderParam
{
public:
    enum
    {
        CAM_TYPE_WITH_FADE = 0,
        CAM_TYPE_WITHOUT_FADE = 1,
        CAM_TYPE_ENEMY = 2,
    };
    enum
    {
        CAM_ACT_START = 0,
        CAM_ACT_END = 1,
        CAM_ACT_ONCE = 2,
    };
    enum
    {
        CAM_RES_STAGE = 0,
        CAM_RES_EVENT = 1,
    };
    enum
    {
        SET_POS_NO = 0,
        SET_POS_MANUAL = 1,
        SET_POS_STARTPOS = 2,
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
    cFSMOrderParamCamera();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    s32 mCamId;  // offset: 0x8
    u8 mCamType;  // offset: 0xc
    u8 mActType;  // offset: 0xd
    u8 mCamRes;  // offset: 0xe
    bool mCantActPl;  // offset: 0xf
    bool mIsFsmEvent;  // offset: 0x10
    bool mIsSelfDisplayed;  // offset: 0x11
    bool mIsEnemyAndNpcDisplayed;  // offset: 0x12
    bool mIsMessageCleared;  // offset: 0x13
    bool mIsSelfStopped;  // offset: 0x14
    u8 mSetPosType;  // offset: 0x15
    u32 mStartPosNo;  // offset: 0x18
    f32 mPlStopTime;  // offset: 0x1c
    static MyDTI DTI;
};

class cFSMOrderParamChangeBattleThink : public cFSMOrderParam
{
public:
    enum
    {
        BTL_TNK_NONE = 0,
        BTL_TNK_PLAYER = 1,
        BTL_TNK_ENEMY = 2,
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
    cFSMOrderParamChangeBattleThink();
    virtual ~cFSMOrderParamChangeBattleThink() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    s32 mGroup;  // offset: 0x8
    s32 mId;  // offset: 0xc
    u32 mBattleThink;  // offset: 0x10
    static MyDTI DTI;
};

class cFSMOrderParamCheckLayout : public cFSMOrderParam
{
public:
    enum
    {
        ACT_ENABLE = 0,
        ACT_UNENABLE = 1,
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
    cFSMOrderParamCheckLayout();
    virtual ~cFSMOrderParamCheckLayout();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mActType;  // offset: 0x8
    u32 mStageNo;  // offset: 0xc
    u32 mLotNo;  // offset: 0x10
    static MyDTI DTI;
};

class cFSMOrderParamCtrlSubSdl : public cFSMOrderParam
{
public:
    enum
    {
        CTRL_SUB_SDL_START = 0,
        CTRL_SUB_SDL_KILL = 1,
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
    cFSMOrderParamCtrlSubSdl();
    virtual ~cFSMOrderParamCtrlSubSdl() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mCtrl;  // offset: 0x8
    u32 mSdlNo;  // offset: 0xc
    bool mIsLoop;  // offset: 0x10
    static MyDTI DTI;
};

class cFSMOrderParamFlagCommon : public cFSMOrderParam
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
    cFSMOrderParamFlagCommon();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    s32 mFlagNo;  // offset: 0x8
    static MyDTI DTI;
    static const MT_ENUM tblEnumFlagBool[];
};

class cFSMOrderParamFlagQuest : public cFSMOrderParam
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
    cFSMOrderParamFlagQuest();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mQuestNo;  // offset: 0x8
    s32 mFlagNo;  // offset: 0xc
    static MyDTI DTI;
};

class cFSMOrderParamIsMyQuestFlag : public cFSMOrderParam
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
    cFSMOrderParamIsMyQuestFlag();
    virtual ~cFSMOrderParamIsMyQuestFlag();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mArrayIdx;  // offset: 0x8
    u32 mQuestId;  // offset: 0xc
    u32 mFlagNo;  // offset: 0x10
    static MyDTI DTI;
};

class cFSMOrderParamJumpArea : public cFSMOrderParam
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
    cFSMOrderParamJumpArea();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mJumpStageNo;  // offset: 0x8
    u32 mJumpStagePosNo;  // offset: 0xc
    static MyDTI DTI;
};

class cFSMOrderParamJumpPos : public cFSMOrderParam
{
public:
    enum
    {
        TYPE_DIRECT = 0,
        TYPE_START_POS = 1,
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
    cFSMOrderParamJumpPos();
    virtual ~cFSMOrderParamJumpPos();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mJumpType;  // offset: 0x8
    u32 mJumpStagePosNo;  // offset: 0xc
    MtVector3 mPos;  // offset: 0x10
    f32 mFadeOutTime;  // offset: 0x20
    f32 mFadeInTime;  // offset: 0x24
    static MyDTI DTI;
};

class cFSMOrderParamQuestInfo : public cFSMOrderParam
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
    cFSMOrderParamQuestInfo();
    virtual ~cFSMOrderParamQuestInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mQuestType;  // offset: 0x8
    u32 mQuestId;  // offset: 0xc
    static MyDTI DTI;
};

class cFSMOrderParamSetCallSe : public cFSMOrderParam
{
public:
    enum
    {
        TARGET_OM = 0,
        TARGET_NPC = 1,
        TARGET_EM = 2,
        TARGET_POS = 3,
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
    cFSMOrderParamSetCallSe();
    virtual ~cFSMOrderParamSetCallSe() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mSeId;  // offset: 0x8
    u32 mTarget;  // offset: 0xc
    s32 mGroup;  // offset: 0x10
    s32 mId;  // offset: 0x14
    s32 mJointNo;  // offset: 0x18
    u32 mDelayFrame;  // offset: 0x1c
    MtVector3 mPos;  // offset: 0x20
    static MyDTI DTI;
};

class cFSMOrderParamSetDispUnit : public cFSMOrderParam
{
public:
    enum
    {
        ACT_SHOW = 0,
        ACT_HIDE = 1,
    };
    enum
    {
        TARGET_NPC = 0,
        TARGET_EM = 1,
        TARGET_OM = 2,
        TARGET_QST = 3,
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
    cFSMOrderParamSetDispUnit();
    virtual ~cFSMOrderParamSetDispUnit();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mAct;  // offset: 0x8
    u32 mTarget;  // offset: 0xc
    u32 mGroupNo;  // offset: 0x10
    u32 mSetId;  // offset: 0x14
    u32 mQstId;  // offset: 0x18
    bool mIsStopMove;  // offset: 0x1c
    static MyDTI DTI;
};

class cFSMOrderParamSetEffect : public cFSMOrderParam
{
public:
    enum
    {
        TARGET_OM = 0,
        TARGET_NPC = 1,
        TARGET_EM = 2,
        TARGET_POS = 3,
    };
    enum
    {
        ACT_PLAY = 0,
        ACT_FINISH = 1,
        ACT_KILL = 2,
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
    cFSMOrderParamSetEffect();
    virtual ~cFSMOrderParamSetEffect() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u16 mEfcId;  // offset: 0x8
    u16 mTarget;  // offset: 0xa
    s32 mGroup;  // offset: 0xc
    s32 mId;  // offset: 0x10
    u16 mAct;  // offset: 0x14
    u16 mType;  // offset: 0x16
    u16 mIndex;  // offset: 0x18
    u16 mElement;  // offset: 0x1a
    u32 mOmId;  // offset: 0x1c
    bool mHaveItem;  // offset: 0x20
    MtVector3 mPos;  // offset: 0x30
    MtVector3 mAng;  // offset: 0x40
    MtVector3 mScl;  // offset: 0x50
    static MyDTI DTI;
};

class cFSMOrderParamSetEnemy : public cFSMOrderParam
{
public:
    class MyDTI;
    class cSetEmInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cSetEmInfo : public MtObject
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
        u32 getEnemyId() const;
        const MtVector3 getPos() const;
        const MtVector3 getAngleZXY() const;
        cSetEmInfo(u32 id, u32 groupId, u32 layoutId);

        cSetEmInfo() : mEnemyId(0), mMat(MtMatrix::Identity), mGroupId(0), mSetId(0), mErosionLv(0) {
        }
        virtual ~cSetEmInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mEnemyId;  // offset: 0x8
        MtMatrix mMat;  // offset: 0x10
        cFSMRelate mFsmPath;  // offset: 0x50
        u32 mGroupId;  // offset: 0x68
        u32 mSetId;  // offset: 0x6c
        u32 mErosionLv;  // offset: 0x70
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
    cFSMOrderParamSetEnemy();
    virtual ~cFSMOrderParamSetEnemy();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void copy(cAICopiableParameter* pParam);  // vtable slot 6
    void getId(u32& groupId, u32& layoutId);
public:
    MtTypedArray<cSetEmInfo> mSetEnemyInfo;  // offset: 0x8
protected:
    u32 mGroupId;  // offset: 0x28
    u32 mLayoutId;  // offset: 0x2c
public:
    static MyDTI DTI;
protected:
    static const u32 mGroupID_MIN = 257;
    static const u32 mGroupID_MAX = 500;
    static const u32 mLayoutID_MIN = 0;
    static const u32 mLayoutID_MAX = 31;
};

class cFSMOrderParamSetFade : public cFSMOrderParam
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
    cFSMOrderParamSetFade();
    virtual ~cFSMOrderParamSetFade() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mFadeType;  // offset: 0x8
    f32 mFadeTime;  // offset: 0xc
    static MyDTI DTI;
};

class cFSMOrderParamSetLayout : public cFSMOrderParam
{
public:
    enum
    {
        ACT_ON = 0,
        ACT_OFF = 1,
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
    cFSMOrderParamSetLayout();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u16 mActType;  // offset: 0x8
    u16 mStageNo;  // offset: 0xa
    u16 mFlagNo;  // offset: 0xc
    static MyDTI DTI;
};

class cFSMOrderParamSetLocationName : public cFSMOrderParam
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
    cFSMOrderParamSetLocationName();
    virtual ~cFSMOrderParamSetLocationName() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mStageNo;  // offset: 0x8
    static MyDTI DTI;
};

class cFSMOrderParamSetOpenDoor : public cFSMOrderParam
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
    cFSMOrderParamSetOpenDoor();
    virtual ~cFSMOrderParamSetOpenDoor() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mGroupNo;  // offset: 0x8
    u32 mSetNo;  // offset: 0xc
    u32 mQuestId;  // offset: 0x10
    bool mIsQuestSet;  // offset: 0x14
    static MyDTI DTI;
};

class cFSMOrderParamSetVib : public cFSMOrderParam
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
    cFSMOrderParamSetVib();
    virtual ~cFSMOrderParamSetVib() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mVib;  // offset: 0x8
    u32 mNum;  // offset: 0xc
    f32 mWaitSec;  // offset: 0x10
    static MyDTI DTI;
};

class cFSMOrderParamStartQuake : public cFSMOrderParam
{
public:
    enum
    {
        TARGET_PLAYER = 0,
        TARGET_WORLD = 1,
        TARGET_NPC = 2,
        TARGET_EM = 3,
        TARGET_OM = 4,
        TARGET_NUM = 5,
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
    cFSMOrderParamStartQuake();
    virtual ~cFSMOrderParamStartQuake();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mTargetType;  // offset: 0x8
    u32 mTargetGroup;  // offset: 0xc
    u32 mTargetId;  // offset: 0x10
    f32 mHeadTime;  // offset: 0x14
    f32 mMainTime;  // offset: 0x18
    f32 mTailTime;  // offset: 0x1c
    MtVector3 mMagnitude;  // offset: 0x20
    MtVector3 mPos;  // offset: 0x30
    f32 mRadius;  // offset: 0x40
    f32 mSpread;  // offset: 0x44
    f32 mDamping;  // offset: 0x48
    f32 mPeriod;  // offset: 0x4c
    f32 mRoll;  // offset: 0x50
    f32 mBalance;  // offset: 0x54
    bool mIsAsync;  // offset: 0x58
    f32 mCamera1QuakeTime;  // offset: 0x5c
    f32 mTarget1QuakeTime;  // offset: 0x60
    f32 mRoll1QuakeTime;  // offset: 0x64
    f32 mRandDrop;  // offset: 0x68
    u32 mHeadCurve;  // offset: 0x6c
    u32 mTailCurve;  // offset: 0x70
    static MyDTI DTI;
};

class cFSMOrderParamStopQuake : public cFSMOrderParam
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
    cFSMOrderParamStopQuake();
    virtual ~cFSMOrderParamStopQuake();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    bool mIsForceStop;  // offset: 0x8
    static MyDTI DTI;
};

inline void* cFSMOrderParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamAreaHit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamBGMCommon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamBGMRequest::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cFSMOrderParamBGMRequest::getRequestEditType() const {
    return this->mBgmRequestEditType;
}

inline void* cFSMOrderParamBGMStop::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamCallAnnounce::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamCallEvent::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamCallEvent::cNpcId::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cFSMOrderParamCallEvent::cNpcId::cNpcId() {
    this->mNpcId = 0;
}

inline void* cFSMOrderParamCamera::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamChangeBattleThink::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamCheckLayout::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamCtrlSubSdl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamFlagCommon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamFlagQuest::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamIsMyQuestFlag::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamJumpArea::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamJumpPos::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamQuestInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetCallSe::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetDispUnit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetEffect::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetEnemy::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetEnemy::cSetEmInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetFade::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetLayout::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetLocationName::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetOpenDoor::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamSetVib::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamStartQuake::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamStopQuake::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
