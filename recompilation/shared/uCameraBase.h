#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "uCamera.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;

// Declarations
class cCameraQuake;
class uCameraBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using uintptr = __uintptr_t;

class cCameraQuake : public MtObject
{
public:
    enum STATE
    {
        STATE_EMPTY = 0,
        STATE_SET = 1,
        STATE_ACTIVE = 2,
    };
    enum EASE_TYPE
    {
        EASE_SMOOTH = 0,
        EASE_LINER = 1,
        EASE_EXPONENT = 2,
    };
    enum
    {
        QUAKE_TASK_0 = 0,
        QUAKE_TASK_FSM_0 = 1,
        QUAKE_MOT_SEQ_0 = 2,
        QUAKE_MOT_SEQ_1 = 3,
        QUAKE_MOT_SEQ_2 = 4,
        QUAKE_MOT_SEQ_3 = 5,
        QUAKE_GAME_CAMERA_0 = 6,
        QUAKE_GAME_CAMERA_1 = 7,
        QUAKE_TASK_EFF_0 = 8,
        QUAKE_TASK_EFF_1 = 9,
        QUAKE_TASK_EFF_2 = 10,
        QUAKE_TASK_EFF_3 = 11,
        QUAKE_TASK_12 = 12,
        QUAKE_TASK_13 = 13,
        QUAKE_TASK_14 = 14,
        QUAKE_TASK_15 = 15,
        QUAKE_TASK_MAX = 16,
    };
public:
    class MyDTI;
    struct QUAKE_TASK;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct QUAKE_TASK
    {
    public:
        cCameraQuake::STATE mState;  // offset: 0x0
        uintptr mNo;  // offset: 0x8
        f32 mTime;  // offset: 0x10
        f32 mHeadTime;  // offset: 0x14
        f32 mMainTime;  // offset: 0x18
        f32 mTailTime;  // offset: 0x1c
        MtVector3 mMagnitude;  // offset: 0x20
        MtVector3 mPos;  // offset: 0x30
        f32 mRadius;  // offset: 0x40
        f32 mSpread;  // offset: 0x44
        f32 mDamping;  // offset: 0x48
        f32 mPeriod;  // offset: 0x4c
        f32 mCamera1QuakeTime;  // offset: 0x50
        f32 mTarget1QuakeTime;  // offset: 0x54
        f32 mRoll1QuakeTime;  // offset: 0x58
        f32 mRndDrop;  // offset: 0x5c
        cCameraQuake::EASE_TYPE mHeadCurve;  // offset: 0x60
        cCameraQuake::EASE_TYPE mTailCurve;  // offset: 0x64
        f32 mRoll;  // offset: 0x68
        f32 mBalance;  // offset: 0x6c
        bool mbAsync;  // offset: 0x70
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
    cCameraQuake();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void init();  // vtable slot 6
    virtual void update(const f32 deltaTime, const f32 deltaSec);  // vtable slot 7
    void set(uintptr taskNo, f32 headTime, f32 mainTime, f32 tailTime, const MtVector3& magnitude, const MtVector3& pos, f32 radius, f32 spread, f32 damping, f32 period, f32 cam1QuakeTime, f32 tar1QuakeTime, f32 roll1QuakeTime, f32 randDrop, EASE_TYPE headCurve, EASE_TYPE tailCurve, f32 roll, f32 balance, bool bAsync);
    void del(uintptr taskNo, bool foceDel);
    void scheduler(f32 deltaSec);
    void execute(f32 deltaSec);
    void setSleep(bool);
    void setCameraPos(const MtVector3& pos);
    void setTargetPos(const MtVector3& target);
    const MtVector3& getCameraPos() const;
    const MtVector3& getTargetPos() const;
    void setCameraAim(const MtVector3&);
    MtVector3 getCameraAim();
    void setCameraUp(const MtVector3& up);
    void setFovAim(const f32);
    f32 getFovAim();
    void setRoll(const f32 roll);
    f32 getRoll();
    MtMatrix getViewMat();
private:
    QUAKE_TASK mTask[16];  // offset: 0x10
    f32 mGain;  // offset: 0x810
    MtVector3 mMagnitude;  // offset: 0x820
    f32 mRollMag;  // offset: 0x830
    f32 mBalance;  // offset: 0x834
    bool mbAsync;  // offset: 0x838
    f32 mCamera1QuakeTime;  // offset: 0x83c
    f32 mTarget1QuakeTime;  // offset: 0x840
    f32 mRoll1QuakeTime;  // offset: 0x844
    f32 mCameraTimer[3];  // offset: 0x848
    f32 mTargetTimer[3];  // offset: 0x854
    f32 mRollTimer;  // offset: 0x860
    f32 mCameraAmp[3];  // offset: 0x864
    f32 mTargetAmp[3];  // offset: 0x870
    f32 mRollAmp;  // offset: 0x87c
    f32 mCameraCycle[3];  // offset: 0x880
    f32 mTargetCycle[3];  // offset: 0x88c
    f32 mRollCycle;  // offset: 0x898
    bool mbCameraInit[3];  // offset: 0x89c
    bool mbTargetInit[3];  // offset: 0x89f
    bool mbRollInit;  // offset: 0x8a2
    f32 mRndDrop;  // offset: 0x8a4
    bool mbQuakeActive;  // offset: 0x8a8
    bool mbSleep;  // offset: 0x8a9
    MtVector3 mCameraPos;  // offset: 0x8b0
    MtVector3 mCameraUp;  // offset: 0x8c0
    MtVector3 mTargetPos;  // offset: 0x8d0
    f32 mRoll;  // offset: 0x8e0
    MtVector3 mCameraAim;  // offset: 0x8f0
    MtVector3 mTargetAim;  // offset: 0x900
    MtVector3 mCamUpAim;  // offset: 0x910
    f32 mFovAim;  // offset: 0x920
    s32 mQuakeNo;  // offset: 0x924
public:
    static MyDTI DTI;
};

class uCameraBase : public uCamera
{
public:
    enum FOV_TYPE
    {
        FOV_V = 0,
        FOV_H = 1,
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
    uCameraBase();
    virtual ~uCameraBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual MtMatrix getViewMat();  // vtable slot 25
    virtual MtMatrix getProjMat();  // vtable slot 26
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void init();  // vtable slot 27
    virtual void update(const f32 deltaTime, const f32 deltaSec);  // vtable slot 28
    // Address: 0x01ad0980 - 0x01ad0981 (1 bytes)
    virtual void setFinalPos() {}  // vtable slot 29
    void setCameraAim(const MtVector3&);
    MtVector3 getCameraAim();
    void setTargetAim(const MtVector3&);
    MtVector3 getTargetAim();
    void setCamUpAim(const MtVector3&);
    MtVector3 getCamUpAim();
    void setFovAim(const f32);
    f32 getFovAim();
    void setRoll(const f32 roll);
    f32 getRoll();
    void setRollAim(const f32);
    f32 getRollAim();
    f32 getAngleX();
    f32 getAngleY();
    void resetCameraUp();
    void setInitial(bool);
    bool isInitial();
    void setFinal(bool flag);
    bool isFinal();
    f32 getDeltaTime();
    f32 getDeltaSec();
    bool intersectSphere(const MtSphere& spr);
    static void calcAngle(f32& outX, f32& outY, const MtVector3& pos1, const MtVector3& pos2);
    static void calcAngle(f32& outX, f32& outY, const MtVector3& vec);
    static f32 calcAngleX(const MtVector3& vec);
    static f32 calcAngleY(const MtVector3& vec);
private:
    void calcFrustum(bool bDisp);
public:
    static f32 calcRoll(const MtVector3& cameraPos, const MtVector3& targetPos, const MtVector3& cameraUp);
    static bool calcCameraUp(const MtVector3& cameraPos, const MtVector3& targetPos, const f32 roll, MtVector3& cameraUp);
    void setQuake(uintptr taskNo, f32 headTime, f32 mainTime, f32 tailTime, const MtVector3& magnitude, const MtVector3& pos, f32 radius, f32 spread, f32 damping, f32 period, f32 roll, f32 balance, bool bAsync, f32 cam1QuakeTime, f32 tar1QuakeTime, f32 roll1QuakeTime, f32 randDrop, cCameraQuake::EASE_TYPE headCurve, cCameraQuake::EASE_TYPE tailCurve);
    void delQuake(uintptr taskNo, bool isForceDel);
    void initQuake();
    void setQuakeSleep(bool);
protected:
    MtVector3 mCameraAim;  // offset: 0xb0
    MtVector3 mTargetAim;  // offset: 0xc0
    MtVector3 mCamUpAim;  // offset: 0xd0
    f32 mFovAim;  // offset: 0xe0
    f32 mRoll;  // offset: 0xe4
    f32 mRollAim;  // offset: 0xe8
    bool mbInitial;  // offset: 0xec
    bool mbFinal;  // offset: 0xed
    FOV_TYPE mFovType;  // offset: 0xf0
private:
    MtVector4 mFrustum[6];  // offset: 0x100
protected:
    cCameraQuake mQuake;  // offset: 0x160
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool uCameraBase::isInitial() {
    return this->mbInitial;
}
