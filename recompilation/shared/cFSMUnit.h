#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cAIUserProcess.h"
#include "cFSMBase.h"
#include "uCoord.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class uEnemy;
class uHuman;
class uNpc;

// Declarations
class cFSMUnit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cFSMUnit : public cFSMBase
{
public:
    enum
    {
        STATE_WAIT = 0,
        STATE_RUN = 1,
    };
    enum
    {
        TARGET_TYPE_PLAYER = 0,
        TARGET_TYPE_NPC = 1,
    };
    enum
    {
        JOINT_NO_EYEBALL_L = 94,
        JOINT_NO_EYEBALL_R = 87,
    };
    enum
    {
        EM_DIE_INIT = 0,
        EM_DIE_WAIT_EFFECT = 1,
        EM_DIE_WAIT_END = 2,
        EM_DIE_END = 3,
    };
    enum
    {
        MOVE_TYPE_WALK = 0,
        MOVE_TYPE_RUN = 1,
        MOVE_TYPE_DASH = 2,
    };
public:
    class MyDTI;
    class uEvHeadTarget;
    class cParamSetMotion;
    class cParamSetAction;
    class cParamSetNeck;
    class cParamSetWait;
    class cParamSetGoto;
    class cParamSetGotoTarget;
    class cParamSetMotionGoto;
    class cParamSetEffect;
    class cParamSetEyeBall;
    class cParamSetEmDie;
    class cParamSetWaypoint;
    class cParamSetChangeThink;
    class cParamSetAdjustScrHit;
    class cParamSetAttendNpc;
    class cParamSetDisableTouchAction;
    class cParamSetDispWeapon;
    class cParamSetShadowCast;
    class cParamSetHaveThing;
    class cParamSetCallSe;
    class cParamSetHakuryuStoneLevel;
    class cParamSetParts;
    class cParamSetVibUnit;
    class cParamSetEmMontage;
    class cParamSetHeadCtrl;
    class cParamSetEyeClose;
    class cParamSetDispMiniMap;
    class cParamSetIK;
    class cParamSetEnemyHP;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class uEvHeadTarget : public uCoord
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
        uEvHeadTarget();
        uEvHeadTarget(u32 type, u32 group, u32 id);
        virtual ~uEvHeadTarget();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void setup();  // vtable slot 6
        virtual void move();  // vtable slot 9
        virtual void kill();  // vtable slot 16
        const MtVector3& getTargetPos();
        void updateParam();
    public:
        u32 mType;  // offset: 0x110
        u32 mGroup;  // offset: 0x114
        u32 mId;  // offset: 0x118
        MtVector3 mTargetPos;  // offset: 0x120
        MtVector3 mTargetOfsPos;  // offset: 0x130
        s32 mTargetJointId;  // offset: 0x140
        static MyDTI DTI;
    };
public:
    class cParamSetMotion : public cAICopiableParameter
    {
    public:
        enum
        {
            A_NONE = 0,
            A_LOOP_OFF = 1,
            A_SET_END_FRAME = 2,
            A_ALL = -1,
        };
        enum
        {
            MOTION_SE_NONE = -1,
            MOTION_SE_PL_BASE = 0,
            MOTION_SE_PL_VOICE = 1,
            MOTION_SE_PL_SKILL = 2,
            MOTION_SE_PL_JOB = 3,
            MOTION_SE_PL_MAIN_WEP = 4,
            MOTION_SE_PL_FREE_0 = 5,
            MOTION_SE_PL_SUB_WEP = 6,
            MOTION_SE_PL_FREE_1 = 7,
            MOTION_SE_PL_ARMOR = 8,
            MOTION_SE_PL_FREE_2 = 9,
            MOTION_SE_PL_OM = 10,
            MOTION_SE_PL_SPECIAL = 11,
            MOTION_SE_NPC_VOICE = 12,
            MOTION_SE_PL_STAGE = 13,
            MOTION_SE_EM_SHARE = 14,
            MOTION_SE_NUM = 15,
        };
        enum
        {
            BANK_MOT_COMMON = 0,
            BANK_MOT_DAMAGE = 1,
            BANK_MOT_GRIP = 2,
            BANK_MOT_JOB_CM = 3,
            BANK_MOT_JOB_AT = 4,
            BANK_MOT_NPC_SP = 5,
            BANK_MOT_EMO = 6,
            BANK_MOT_CAUGHT = 7,
            BANK_MOT_NPC = 8,
            BANK_MOT_ENEMY = 9,
            BANK_MOT_DEMO = 10,
            BANK_MOT_FACIAL = 11,
            BANK_MOT_FINGER = 12,
            BANK_MOT_EM_NORMAL = 13,
            BANK_MOT_EM_ATTACK = 14,
            BANK_MOT_EM_DAMAGE = 15,
            BANK_MOT_EM_ATTACK_AIR = 16,
            BANK_MOT_EM_EXTRA = 17,
            BANK_MOT_EM_NPC = 18,
            BANK_MOT_NPC_SS = 19,
            BANK_MOT_EVT_NPC_SP = 20,
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
        u32 getMotionNo() const;
        cParamSetMotion();
        virtual ~cParamSetMotion();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mBankNo;  // offset: 0x8
        u32 mMotNo;  // offset: 0xc
        f32 mHokan;  // offset: 0x10
        f32 mStartFrame;  // offset: 0x14
        f32 mEndFrame;  // offset: 0x18
        f32 mMotSpeed;  // offset: 0x1c
        bool mIsLoop;  // offset: 0x20
        bool mIsSetEndFrame;  // offset: 0x21
        bool mIsNullTransFix;  // offset: 0x22
        bool mIsNullTransOff;  // offset: 0x23
        bool mIsNullAngleFix;  // offset: 0x24
        bool mIsSetDir;  // offset: 0x25
        bool mIsDispItem;  // offset: 0x26
        MtVector3 mDir;  // offset: 0x30
        f32 mSpeed;  // offset: 0x40
        bool mIsCallVoice;  // offset: 0x44
        bool mIsUseFingerMotion;  // offset: 0x45
        u32 mFingerMotionNo;  // offset: 0x48
        f32 mFingerHokan;  // offset: 0x4c
        f32 mFingerSpeed;  // offset: 0x50
        bool mIsDisableFall;  // offset: 0x54
        s32 mMotionSeOffBank;  // offset: 0x58
        static MyDTI DTI;
    };
public:
    class cParamSetAction : public cAICopiableParameter
    {
    public:
        enum
        {
            ACTTYPE_DRAWN_SWORD = 0,
            ACTTYPE_PAY_SWORN = 1,
            ACTTYPE_NUM = 2,
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
        u32 getActionNo() const;
        cParamSetAction();
        virtual ~cParamSetAction();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mActionType;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetNeck : public cAICopiableParameter
    {
    public:
        enum
        {
            TARGET_POSITION = 0,
            TARGET_PLAYER = 1,
            TARGET_NPC = 2,
            TARGET_ENEMY = 3,
            TARGET_NUM = 4,
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
        cParamSetNeck();
        virtual ~cParamSetNeck();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        bool mIsSetNeck;  // offset: 0x8
        u32 mTargetType;  // offset: 0xc
        MtVector3 mTargetPos;  // offset: 0x10
        u32 mTargetGroup;  // offset: 0x20
        u32 mTargetSetId;  // offset: 0x24
        s32 mTargetJointId;  // offset: 0x28
        bool mDisableSequence;  // offset: 0x2c
        bool mIsAutoOffCtrl;  // offset: 0x2d
        f32 mSpeedRate;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    class cParamSetWait : public cAICopiableParameter
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
        cParamSetWait();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        bool mIsSetDir;  // offset: 0x8
        MtVector3 mDir;  // offset: 0x10
        f32 mSpeed;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class cParamSetGoto : public cAICopiableParameter
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
        cParamSetGoto();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        MtVector3 mTargetPos;  // offset: 0x10
        u8 mRunType;  // offset: 0x20
        f32 mStopBorder;  // offset: 0x24
        bool mIsSetDir;  // offset: 0x28
        bool mIsPathFinding;  // offset: 0x29
        MtVector3 mDir;  // offset: 0x30
        f32 mSpeed;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class cParamSetGotoTarget : public cAICopiableParameter
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
        cParamSetGotoTarget();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u8 mTargetType;  // offset: 0x8
        u8 mRunType;  // offset: 0x9
        s32 mTargetId;  // offset: 0xc
        bool mIsSetBorder;  // offset: 0x10
        bool mIsPathFinding;  // offset: 0x11
        f32 mStopBorder;  // offset: 0x14
        bool mIsUseWarp;  // offset: 0x18
        f32 mWarpDist;  // offset: 0x1c
        bool mEnableNoFall;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class cParamSetMotionGoto : public cFSMUnit::cParamSetMotion
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
        cParamSetMotionGoto();
        virtual ~cParamSetMotionGoto();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        MtVector3 mTargetPos;  // offset: 0x60
        f32 mStopBorder;  // offset: 0x70
        bool mIsSetVelocity;  // offset: 0x74
        MtVector3 mVelocity;  // offset: 0x80
        MtVector3 mAcceleration;  // offset: 0x90
        f32 mVelocityScalar;  // offset: 0xa0
        f32 mAccelerationScalar;  // offset: 0xa4
        bool mIsHover;  // offset: 0xa8
        bool mIsPosHokan;  // offset: 0xa9
        static MyDTI DTI;
    };
public:
    class cParamSetEffect : public cAICopiableParameter
    {
    public:
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
        cParamSetEffect();
        virtual ~cParamSetEffect();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mEfcId;  // offset: 0x8
        u16 mAct;  // offset: 0xc
        u16 mType;  // offset: 0xe
        u16 mIndex;  // offset: 0x10
        u16 mElement;  // offset: 0x12
        u32 mOmId;  // offset: 0x14
        bool mHaveItem;  // offset: 0x18
        static MyDTI DTI;
    };
public:
    class cParamSetEyeBall : public cAICopiableParameter
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
        cParamSetEyeBall();
        virtual ~cParamSetEyeBall();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        MtVector3 mTargetAngle;  // offset: 0x10
        u32 mHokanFrame;  // offset: 0x20
        u32 mDelayFrame;  // offset: 0x24
        static MyDTI DTI;
    };
public:
    class cParamSetEmDie : public cAICopiableParameter
    {
    public:
        enum
        {
            ACT_UNIT_HIDE = 0,
            ACT_UNIT_KILL = 1,
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
        cParamSetEmDie();
        virtual ~cParamSetEmDie();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mAct;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetWaypoint : public cAICopiableParameter
    {
    public:
        enum
        {
            TYPE_DIRECT = 0,
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
        cParamSetWaypoint();
        virtual ~cParamSetWaypoint();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mType;  // offset: 0x8
        s32 mGotoPointNo;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cParamSetChangeThink : public cAICopiableParameter
    {
    public:
        enum
        {
            THINK_NONE = 0,
            THINK_PLAYER = 1,
            THINK_ENEMY = 2,
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
        cParamSetChangeThink();
        virtual ~cParamSetChangeThink();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mThink;  // offset: 0x8
        bool mIsInvincible;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cParamSetAdjustScrHit : public cAICopiableParameter
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
        cParamSetAdjustScrHit();
        virtual ~cParamSetAdjustScrHit();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        bool mIsStop;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetAttendNpc : public cAICopiableParameter
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
        cParamSetAttendNpc();
        virtual ~cParamSetAttendNpc();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        bool mIsAttend;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetDisableTouchAction : public cAICopiableParameter
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
        cParamSetDisableTouchAction();
        virtual ~cParamSetDisableTouchAction();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        bool mIsDisableTouch;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetDispWeapon : public cAICopiableParameter
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
        cParamSetDispWeapon();
        virtual ~cParamSetDispWeapon();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        bool mIsDispWepMain;  // offset: 0x8
        bool mIsDispWepSub;  // offset: 0x9
        static MyDTI DTI;
    };
public:
    class cParamSetShadowCast : public cAICopiableParameter
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
        cParamSetShadowCast();
        virtual ~cParamSetShadowCast();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        bool mIsShadowCast;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetHaveThing : public cAICopiableParameter
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
        cParamSetHaveThing();
        virtual ~cParamSetHaveThing();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mHaveThing;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetCallSe : public cAICopiableParameter
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
        cParamSetCallSe();
        virtual ~cParamSetCallSe();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mSeId;  // offset: 0x8
        s32 mJointNo;  // offset: 0xc
        u32 mDelayFrame;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cParamSetHakuryuStoneLevel : public cAICopiableParameter
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
        cParamSetHakuryuStoneLevel();
        virtual ~cParamSetHakuryuStoneLevel();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mStoneLevel;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetParts : public cAICopiableParameter
    {
    public:
        enum
        {
            PARTS_OFF = 0,
            PARTS_ON = 1,
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
        cParamSetParts();
        virtual ~cParamSetParts();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mType;  // offset: 0x8
        u32 mParts;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cParamSetVibUnit : public cAICopiableParameter
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
        cParamSetVibUnit();
        virtual ~cParamSetVibUnit();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mVib;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetEmMontage : public cAICopiableParameter
    {
    public:
        enum
        {
            MONTAGE_OFF = 0,
            MONTAGE_ON = 1,
            MONTAGE_SET = 2,
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
        cParamSetEmMontage();
        virtual ~cParamSetEmMontage();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mType;  // offset: 0x8
        u32 mMontage;  // offset: 0xc
        bool mDisableMotSeq;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cParamSetHeadCtrl : public cAICopiableParameter
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
        cParamSetHeadCtrl();
        virtual ~cParamSetHeadCtrl();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        s16 mHeadCtrl;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetEyeClose : public cAICopiableParameter
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
        cParamSetEyeClose();
        virtual ~cParamSetEyeClose();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        bool mEyeClose;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetDispMiniMap : public cAICopiableParameter
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
        cParamSetDispMiniMap();
        virtual ~cParamSetDispMiniMap();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        bool mIsDispMiniMap;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetIK : public cAICopiableParameter
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
        cParamSetIK();
        virtual ~cParamSetIK();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        bool mActive;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cParamSetEnemyHP : public cAICopiableParameter
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
        cParamSetEnemyHP();
        virtual ~cParamSetEnemyHP();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        f32 mHPParcentage;  // offset: 0x8
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
    u32 getStatus() const;
protected:
    void setStatus(u32 status);
public:
    virtual void callbackUpdate();  // vtable slot 7
    u32 stateUpdateSetWait(MtObject* pParam, MtObject* pCaller);
    u32 stateSetWait(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetGoto(MtObject* pParam, MtObject* pCaller);
    u32 stateSetGoto(MtObject* pParam, MtObject* pCaller);
    u32 stateExitSetGoto(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetGotoTarget(MtObject* pParam, MtObject* pCaller);
    u32 stateSetGotoTarget(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetMotion(MtObject* pParam, MtObject* pCaller);
    u32 stateSetMotion(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetMotionGoto(MtObject* pParam, MtObject* pCaller);
    u32 stateSetMotionGoto(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetAction(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetEffect(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetNeck(MtObject* pParam, MtObject* pCaller);
    u32 stateSetNeck(MtObject* pParam, MtObject* pCaller);
    u32 stateExitSetNeck(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetEyeBall(MtObject* pParam, MtObject* pCaller);
    u32 stateSetEyeBall(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetEmDie(MtObject* pParam, MtObject* pCaller);
    u32 stateSetEmDie(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetWaypoint(MtObject* pParam, MtObject* pCaller);
    u32 stateSetWaypoint(MtObject* pParam, MtObject* pCaller);
    u32 stateExitSetWaypoint(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateChangeThink(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetAdjScr(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetAttendNpc(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetDisableTouchAction(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetOpenDoor(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetDispWeapon(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetShadowCast(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetHaveThing(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetCallSeUnit(MtObject* pParam, MtObject* pCaller);
    u32 stateSetCallSeUnit(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetHakuryuStoneLevel(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetParts(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetVibUnit(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetEmMontage(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetHeadCtrl(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetEyeClose(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetDispMiniMap(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetIK(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetGotoInitPos(MtObject* pParam, MtObject* pCaller);
    u32 stateSetGotoInitPos(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSetEnemyHP(MtObject* pParam, MtObject* pCaller);
    bool isStop();
    bool isStop(const MtVector3& targetPos);
    f32 getStopBorder() const;
    bool isEndSetMotion() const;
    bool isEndSetNeck() const;
    bool isLand() const;
    bool isGoalWaypoint() const;
    u32 getHp() const;
    f32 getHpPercent() const;
    f32 getDistanceToPlayer() const;
    f32 getDistanceToLeader() const;
    bool isUpdateWaypoint() const;
    f32 getDistanceToEnemy() const;
    bool isBattleStartMogock();
    bool isDiedMogock();
    bool isChangeMaster() const;
    void setChangeMaster();
    bool isExistEnemyUnit() const;
    bool isTouchActionFromPlayer() const;
    f32 getDistanceToInitPos() const;
protected:
    void setStopBorder(f32 stopBorder);
    void openDoor();
    bool setWaitInput();
    bool setMoveInput(const MtVector3& targetPos, u8 moveType);
    void followNpcWarp(f32 distance, uNpc* pNpc);
    void implStateUpdateSetMotionHuman(uHuman* pHuman, cParamSetMotion* pParam);
    void implStateUpdateSetActionHuman(uHuman* pHuman, cParamSetAction* pParam);
    void implStateSetNeckNpc(uNpc* pNpc, cParamSetNeck* pParam);
    void implStateUpdateSetMotionEnemy(uEnemy* pEnemy, cParamSetMotion* pParam);
    void implStateUpdateSetActionEnemy(uEnemy* pEnemy, cParamSetAction* pParam);
    void implStateSetNeckEnemy(uEnemy* pEnemy, cParamSetNeck* pParam);
public:
    cFSMUnit();
    virtual void move();  // vtable slot 6
protected:
    virtual void createPropertyFSM(MtPropertyList& s);  // vtable slot 9
protected:
    u32 mStatus;  // offset: 0xb4
    u32 mStartFrame;  // offset: 0xb8
    u32 mRnoSE;  // offset: 0xbc
    u32 mStartEyeBallFrame;  // offset: 0xc0
    u32 mRnoEye;  // offset: 0xc4
    f32 mCallEffectTimer;  // offset: 0xc8
    MtVector3 mTargetPos;  // offset: 0xd0
    MtVector3 mOldPos;  // offset: 0xe0
    MtVector3 mOldPosPast;  // offset: 0xf0
    MtVector3 mDir;  // offset: 0x100
    MtVector3 mNoMovePos;  // offset: 0x110
    MtVector3 mWarpTargetPos;  // offset: 0x120
    f32 mStopBorder;  // offset: 0x130
    f32 mWaitTimer;  // offset: 0x134
    f32 mNoMoveTimer;  // offset: 0x138
    u32 mTargetUID;  // offset: 0x13c
    bool mIsSetPathFinding;  // offset: 0x140
    bool mIsSetDir;  // offset: 0x141
    bool mIsPosHokan;  // offset: 0x142
    bool mIsForceWarp;  // offset: 0x143
    bool mCanMove;  // offset: 0x144
    bool mIsGotoPlayer;  // offset: 0x145
    bool mIsChangeMaster;  // offset: 0x146
    uEvHeadTarget* mpEvHeadTarget;  // offset: 0x148
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetAction::cParamSetAction() {
    this->mActionType = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetGotoTarget::cParamSetGotoTarget() {
    this->mTargetType = static_cast<u8>(0);
    this->mRunType = static_cast<u8>(0);
    this->mTargetId = static_cast<s32>(-1);
    this->mIsSetBorder = false;
    this->mIsPathFinding = false;
    this->mStopBorder = 100.0f;
    this->mIsUseWarp = false;
    this->mWarpDist = 3500.0f;
    this->mEnableNoFall = false;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetEffect::cParamSetEffect() {
    this->mHaveItem = false;
    this->mIndex = static_cast<u16>(0);
    this->mElement = static_cast<u16>(0);
    this->mOmId = static_cast<u32>(0);
    this->mEfcId = static_cast<u32>(0);
    this->mAct = static_cast<u16>(0);
    this->mType = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetEmDie::cParamSetEmDie() {
    this->mAct = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetWaypoint::cParamSetWaypoint() {
    this->mType = static_cast<u32>(0);
    this->mGotoPointNo = static_cast<s32>(-1);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetChangeThink::cParamSetChangeThink() {
    this->mThink = static_cast<u32>(0);
    this->mIsInvincible = true;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetAdjustScrHit::cParamSetAdjustScrHit() {
    this->mIsStop = false;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetAttendNpc::cParamSetAttendNpc() {
    this->mIsAttend = false;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetDisableTouchAction::cParamSetDisableTouchAction() {
    this->mIsDisableTouch = false;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetDispWeapon::cParamSetDispWeapon() {
    this->mIsDispWepMain = true;
    this->mIsDispWepSub = true;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetShadowCast::cParamSetShadowCast() {
    this->mIsShadowCast = false;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetHaveThing::cParamSetHaveThing() {
    this->mHaveThing = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetCallSe::cParamSetCallSe() {
    this->mSeId = static_cast<u32>(0);
    this->mJointNo = static_cast<s32>(-1);
    this->mDelayFrame = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetHakuryuStoneLevel::cParamSetHakuryuStoneLevel() {
    this->mStoneLevel = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetParts::cParamSetParts() {
    this->mType = static_cast<u32>(0);
    this->mParts = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetVibUnit::cParamSetVibUnit() {
    this->mVib = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetEmMontage::cParamSetEmMontage() {
    this->mType = static_cast<u32>(0);
    this->mMontage = static_cast<u32>(0);
    this->mDisableMotSeq = true;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetHeadCtrl::cParamSetHeadCtrl() {
    this->mHeadCtrl = static_cast<s16>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetEyeClose::cParamSetEyeClose() {
    this->mEyeClose = true;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetDispMiniMap::cParamSetDispMiniMap() {
    this->mIsDispMiniMap = true;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetIK::cParamSetIK() {
    this->mActive = false;
}

// Inline, no code of its own: checked where it is inlined.
inline cFSMUnit::cParamSetEnemyHP::cParamSetEnemyHP() {
    this->mHPParcentage = 1.0f;
}
