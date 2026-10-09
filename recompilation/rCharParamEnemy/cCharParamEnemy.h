#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "cCharParam.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class cCharParamEnemy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cCharParamEnemy : public cCharParam
{
public:
    class MyDTI;
    class cJumpAttackSpeed;
    class cGuardCounter;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cJumpAttackSpeed : public MtObject
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
        cJumpAttackSpeed();
        // Address: 0x01960fd0 - 0x01960fd1 (1 bytes)
        virtual ~cJumpAttackSpeed() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        bool mIsValid;  // offset: 0x8
        f32 mSpeedZ;  // offset: 0xc
        f32 mSpeedY;  // offset: 0x10
        f32 mGravity;  // offset: 0x14
        static MyDTI DTI;
    };
public:
    class cGuardCounter : public MtObject
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
        cGuardCounter();
        // Address: 0x01960fc0 - 0x01960fc1 (1 bytes)
        virtual ~cGuardCounter() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u8 mTimes;  // offset: 0x8
        u8 mPercent;  // offset: 0x9
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
    cCharParamEnemy();
    // Address: 0x01960f70 - 0x01960f71 (1 bytes)
    virtual ~cCharParamEnemy() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void paramClassCopy(MtObject* pObject);  // vtable slot 6
public:
    f32 mAttackBasePhys;  // offset: 0xc
    f32 mAttackBaseMagic;  // offset: 0x10
    f32 mAttackWepPhys;  // offset: 0x14
    f32 mAttackWepMagic;  // offset: 0x18
    f32 mDefenceBasePhys;  // offset: 0x1c
    f32 mDefenceBaseMagic;  // offset: 0x20
    f32 mDefenceWepPhys;  // offset: 0x24
    f32 mDefenceWepMagic;  // offset: 0x28
    f32 mPower;  // offset: 0x2c
    f32 mWeight;  // offset: 0x30
    f32 mGuardAttackBase;  // offset: 0x34
    f32 mGuardDefenceBase;  // offset: 0x38
    f32 mGuardDefenceWep;  // offset: 0x3c
    u32 mWeaponTypeSe;  // offset: 0x40
    u32 mEnemyBodySizeSe;  // offset: 0x44
    u32 mPushGroup;  // offset: 0x48
    u32 mScrAdjustType;  // offset: 0x4c
    u32 mScrAdjustSize;  // offset: 0x50
    f32 mShakeCureRateRage;  // offset: 0x54
    cJumpAttackSpeed mJumpAttackSpeed[4];  // offset: 0x58
    f32 mFallDamageCheckHeight;  // offset: 0xb8
    u32 mUseMotionBlendNum;  // offset: 0xbc
    bool mUseMotionHistory;  // offset: 0xc0
    u32 mUseMotionHistoryNum;  // offset: 0xc4
    f32 mReturnTerritoryContTime;  // offset: 0xc8
    u8 mBeardownEffective;  // offset: 0xcc
    cGuardCounter mGuardCounter[10];  // offset: 0xd0
    u32 mGuardReactionCheckType;  // offset: 0x170
    f32 mEnemyScaleBase;  // offset: 0x174
    f32 mEnemyScaleThinkTable;  // offset: 0x178
    bool mIsShakedActionEnemy;  // offset: 0x17c
    u32 mHangdType;  // offset: 0x180
    f32 mcThinkMgrScaleParam;  // offset: 0x184
    f32 mEnemyLinkRadiusA;  // offset: 0x188
    bool mEnemyLinkRadiusBOn;  // offset: 0x18c
    f32 mEnemyLinkRadiusB;  // offset: 0x190
    f32 mEvaluationPLJobs[10];  // offset: 0x194
    f32 mEvaluationPLSex[2];  // offset: 0x1bc
    bool mDownPerformanceOff;  // offset: 0x1c4
    bool mIsDispDownGuage;  // offset: 0x1c5
    bool mIsNoneAdbantageBGM;  // offset: 0x1c6
    bool mIsUseEnchant;  // offset: 0x1c7
    u32 mEnchantType;  // offset: 0x1c8
    u32 mDamageSpecialAdjType;  // offset: 0x1cc
    u32 mDamageBounisFlag;  // offset: 0x1d0
    f32 mShrinkBounisShakeRate;  // offset: 0x1d4
    f32 mShakeRateSequence;  // offset: 0x1d8
    f32 mScaleDispGui;  // offset: 0x1dc
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCharParamEnemy::cJumpAttackSpeed::cJumpAttackSpeed() {
    this->mIsValid = false;
    this->mSpeedZ = 10.0f;
    this->mSpeedY = 35.0f;
    this->mGravity = -3.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline cCharParamEnemy::cGuardCounter::cGuardCounter() {
    this->mTimes = static_cast<u8>(0);
    this->mPercent = static_cast<u8>(0);
}
