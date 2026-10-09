#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cFSMUnit;
class uCnsJointOffset;
class uEnemy;
class uModel;

// Declarations
class cpFsmCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpFsmCtrl : public cpComponent
{
public:
    class MyDTI;
    struct _stCnsEyeBall;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct _stCnsEyeBall
    {
    public:
        _stCnsEyeBall();
        void deleate();
        bool create();
        void set(uModel* pModel, u32 jointL, u32 jointR, u32 pri);
        void setRot(const MtVector3& rot);
    public:
        uCnsJointOffset* mL;  // offset: 0x0
        uCnsJointOffset* mR;  // offset: 0x8
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
    bool isEnable() const;
    bool isEndSetMotion() const;
    void notifySetMotion();
    void notifyEndSetMotion();
    bool isSetVelocity() const;
    const MtVector3& getVelocity() const;
    void setVelocity(const MtVector3& velocity, const MtVector3& acceleration);
    const MtVector3& getAcceleration() const;
    void setIsHover(bool isHover);
    bool isHover() const;
    void setFingerMotionNo(u32 motNo);
    bool isUseFingerMotion();
    u32 getFingerMotionNo();
    void resetFingerMotion();
    void setFingerHokan(f32 frame);
    f32 getFingerHokan();
    void setFingerSpeed(f32 speed);
    f32 getFingerSpeed();
    void setEyeBallRotStart(const MtVector3&);
    const MtVector3& getEyeBallRotStart();
    void setEyeBallRotNow(const MtVector3&);
    const MtVector3& getEyeBallRotNow();
    void setEyeBallRotTarget(const MtVector3& rot);
    const MtVector3& getEyeBallRotTarget();
    void notifySetEyeBall();
    void notifyEndSetEyeBall();
    bool isEndEyeBallMove() const;
    void setEnableNoFall(bool isEnable);
    bool isEnableNoFall() const;
    bool setupFSM(MT_CTSTR filePath);
    virtual void move();  // vtable slot 7
    bool createConstraint(u32 jointL, u32 jointR, u32 pri);
    void setEyeBallTargetRot(const MtVector3& rot);
    void updateEyeBallRot(u32 nowFrame, u32 hokanFrame);
    void updateEyeBallRot();
protected:
    void stopEnemyThink(uEnemy* pEnemy) const;
public:
    cpFsmCtrl();
    virtual ~cpFsmCtrl();
protected:
    cFSMUnit* mpFSMUnit;  // offset: 0x50
    bool mIsEndSetMotion;  // offset: 0x58
    bool mIsSetVelocity;  // offset: 0x59
    MtVector3 mVelocity;  // offset: 0x60
    MtVector3 mAcceleration;  // offset: 0x70
    bool mIsHover;  // offset: 0x80
    bool mIsPlayOK;  // offset: 0x81
    bool mIsFingerMotion;  // offset: 0x82
    u32 mFingerMotNo;  // offset: 0x84
    f32 mFingerHokan;  // offset: 0x88
    f32 mFingerSpeed;  // offset: 0x8c
    _stCnsEyeBall mCnsEyeBallCtrl;  // offset: 0x90
    MtVector3 mEyeBallRotStart;  // offset: 0xa0
    MtVector3 mEyeBallRotNow;  // offset: 0xb0
    MtVector3 mEyeBallRotTarget;  // offset: 0xc0
    bool mIsEndEyeBallMove;  // offset: 0xd0
    bool mEnableNoFall;  // offset: 0xd1
public:
    static MyDTI DTI;
};
