#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cpJobBase.h"
#include "cpLockOn.h"
#include "nDDOUtility.h"
#include "nHuman.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cAttackParam;
class cHitGeom;
class cHitInfo;
class cHitInfoAfter;
class cShlNotifyInfo;
class uDDOModel;
class uHuman;
class uJobEquip;
class uShlBakuensen;
class uShlBase;

// Declarations
class cpJob02;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using HP_DATATYPE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpJob02 : public cpJobBase
{
    // inferred: uHuman::isJob02Cs11End names cpJob02::mKaenkoromoInfo.mTimer
    friend class uHuman;
public:
    enum eCS12CounterType
    {
        eCs12CounterInvalid = 0,
        eCS12CounterSmall = 1,
        eCS12CounterLarge = 2,
    };
public:
    class MyDTI;
    class cPullUpInfo;
    class cKaenKoromoInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cPullUpInfo : public MtObject
    {
    public:
        class MyDTI;
        struct info;
    public:
        using InfoArray = nDDOUtility::cArray<cpJob02::cPullUpInfo::info, 3>;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct info
        {
        public:
            bool mIsEnable;  // offset: 0x0
            u32 mTargetUID;  // offset: 0x4
            MtVector3 mHitPos;  // offset: 0x10
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
        cPullUpInfo();
        void clear();
    public:
        InfoArray mInfoArray;  // offset: 0x10
        u32 mCheckPhase;  // offset: 0x70
        static MyDTI DTI;
    };
public:
    class cKaenKoromoInfo : public MtObject
    {
    public:
        enum eExecPhase
        {
            eExecSetup = 0,
            eExecUpdate = 1,
            eExecNone = 2,
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
        cKaenKoromoInfo();
        void update(uHuman& human);
        void setup(uHuman& human, f32 time, u32 skillLv);
        void clear(uHuman& human);
        bool isKaenKoromoEnable() const;
    public:
        HP_DATATYPE mDamage;  // offset: 0x8
        f32 mDamageTimer;  // offset: 0x10
        f32 mDamageInterval;  // offset: 0x14
        f32 mTimer;  // offset: 0x18
        eExecPhase mExecPhase;  // offset: 0x1c
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
    cpJob02();
    virtual ~cpJob02();
    virtual void setup();  // vtable slot 6
    virtual void before();  // vtable slot 15
    virtual void update();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 9
    virtual void reset();  // vtable slot 20
    virtual void setupJobData();  // vtable slot 21
    virtual void setupJobDataSafeArea();  // vtable slot 22
    void compMoveAfter();
    virtual void kill();  // vtable slot 8
    virtual void init();  // vtable slot 19
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    virtual void callbackCatch(cHitInfo* pHitInfo);  // vtable slot 48
    virtual void callbackCatch_Shl(cShlNotifyInfo* pInfo);  // vtable slot 49
    virtual void callbackDamage(cHitInfo* pHitInfo);  // vtable slot 33
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 30
    virtual void callbackAttackTest(cHitInfo* pHitInfo);  // vtable slot 34
    virtual void callbackDamageTest(cHitInfo* pHitInfo);  // vtable slot 36
    virtual void callbackCaughtTest(cHitInfo* pHitInfo);  // vtable slot 37
    virtual void callbackCreateShl(uShlBase* pShl);  // vtable slot 52
    virtual void callbackOcdSeal();  // vtable slot 51
    virtual void checkReplaceInfo(cHitInfoAfter& HitInfo);  // vtable slot 58
    const MtVector3& getWireHitPos() const;
    void setWireHitPos(const MtVector3& pos);
    bool isWireHit() const;
    void setIsWireHit(const bool);
    bool isLockOnMode() const;
    const cPullUpInfo& getPullUpInfo() const;
    u32 getCHeckPhase() const;
    void clearPullUpInfo();
    bool checkCndEnableDelayCombo() const;
    void updateLookAtPos();
    void updateLockOnMode();
    bool isCheckLockOnModeActPal() const;
    const cpLockOn::cLockOnTarget* getLockonTarget(f32 range, f32 angle);
    bool checkCndSuccessAttackAvoid() const;
    void setSuccessAttackAvoid(bool flag);
    void checkCs03AvoidFlg();
    MtVector3 getLookAtPos() const;
    f32 getWireLookAtLength() const;
    f32 getWireLockRange() const;
    f32 getWireLockAngle(bool isWide) const;
    bool checkSkillLevel(s32 ActNo, nHuman::HM_SKILL_LV skillLv) const;
    bool isEnableCustom06() const;
    bool checkTransCS06(s32 ActNo);
    void setCS06WaitTimer(nHuman::HM_SKILL_LV skillLv);
    f32 getCS06WaitTimer() const;
    f32 getCS06WaitTimeMax() const;
    bool checkForceTransCS12();
    void countupSecondJump();
    bool isCanSecondJump() const;
    void setupKaenKoromo(f32 time, u32 skillLv);
    void clearKaenKoromo();
    bool isKaenKoromoEnable() const;
    bool isCS12CounterSmall() const;
    bool isCS12CounterLarge() const;
    void clearCS12Counter();
    void setCounterWait(bool flag);
    bool isSetBakuensen() const;
    void igniteBakuensenShl();
    uShlBakuensen* getShlBakuensen();
private:
    void callbackCatch_sub(const cAttackParam* pAttackParam, uDDOModel* pDfdModel, const MtVector3& hitPos);
    void createWireModel(MT_CTSTR jobTag);
    bool calcHitPos(const cHitGeom* pGeom, const MtVector3& pos, MtVector3* pPos, MtVector3* pNormal);
public:
    u32 getAirKamaeNaoshiCnt() const;
    void addAirKamaeNaoshiCnt();
    bool isCs10HitCamera() const;
    void onCs10HitCamera();
    void countupAirCS13();
    bool isCanAirCS13() const;
    void countupAirCS14();
    bool isCanAirCS14() const;
    virtual void callbackCSChange();  // vtable slot 54
public:
    uJobEquip* mpWire;  // offset: 0x58
    bool mIsBakuensenSet;  // offset: 0x60
private:
    bool mIsWireHit;  // offset: 0x61
    MtVector3 mWireHitPos;  // offset: 0x70
    bool mIsAvoid_CS03;  // offset: 0x80
    bool mIsLockOnMode;  // offset: 0x81
    MtVector3 mLookAtPos;  // offset: 0x90
    cPullUpInfo mPullUpInfo;  // offset: 0xa0
    u32 mCheckPhase;  // offset: 0x120
    f32 mCustom06WaitTime;  // offset: 0x124
    u32 mSeocndJumpCount;  // offset: 0x128
    cKaenKoromoInfo mKaenkoromoInfo;  // offset: 0x130
    eCS12CounterType mCS12CounterType;  // offset: 0x150
    u32 mAirKamaeNaoshiCnt;  // offset: 0x154
    bool mIsCaounterWait;  // offset: 0x158
    MtVector3 mCs10HitPos;  // offset: 0x160
    bool mIsCs10HitCamera;  // offset: 0x170
    f32 mCs10HitCameraTimer;  // offset: 0x174
protected:
    uShlBakuensen* mpShlBakuensen;  // offset: 0x178
public:
    u32 mAirCountCS13;  // offset: 0x180
    u32 mAirCountCS14;  // offset: 0x184
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cpJob02::cKaenKoromoInfo::cKaenKoromoInfo() {
    this->mTimer = 0.0f;
    this->mDamageTimer = 0.0f;
    this->mDamageInterval = 0.0f;
    this->mDamage = static_cast<HP_DATATYPE>(0);
    this->mExecPhase = static_cast<cpJob02::cKaenKoromoInfo::eExecPhase>(2);
}
