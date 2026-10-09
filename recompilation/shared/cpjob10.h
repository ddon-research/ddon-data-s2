#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cpJobBase.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cEfcHandle;
class cHitInfo;
class cHitInfoAfter;
class uDDOModel;
class uHuman;

// Declarations
class cpJob10;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nDDOUtility { using cKeyFrameValueF32 = nDDOUtility::cKeyFrameValue<float, MtObject>; }
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cpJob10 : public cpJobBase
{
public:
    enum BOOST_MODE
    {
        BOOST_MODE_NORMAL = 0,
        BOOST_MODE_NUKE = 1,
        BOOST_MODE_SUPPORT = 2,
        BOOST_MODE_BREAK = 3,
    };
    enum CS08_SHL_SIZE
    {
        CS08_SHL_SIZE_1 = 0,
        CS08_SHL_SIZE_2 = 1,
        CS08_SHL_SIZE_3 = 2,
        CS08_SHL_SIZE_4 = 3,
        CS08_SHL_SIZE_5 = 4,
        CS08_SHL_SIZE_6 = 5,
    };
    enum RAMPAGE_TYPE
    {
        RAMPAGE_FAILED = 0,
        RAMPAGE_SMALL = 1,
        RAMPAGE_BIG = 2,
    };
public:
    class MyDTI;
    class cSpiritManager;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cSpiritManager : public MtObject
    {
        // inferred: cpJob10::init calls cpJob10::cSpiritManager::readContext
        friend class cpJob10;
    public:
        enum SPIRIT_STATE
        {
            SPIRIT_STATE_NORMAL = 0,
            SPIRIT_STATE_BOOST = 1,
        };
    public:
        class MyDTI;
        class cSpiritStateNormal;
        class cSpiritState;
        class cSpiritStateBoost;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cSpiritState : public MtObject
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
            cSpiritState();
            void setParent(cpJob10::cSpiritManager* pParent);
            uHuman* getHuman() const;
            virtual cpJob10::cSpiritManager::SPIRIT_STATE getSpiritState() const;  // vtable slot 6
            // Address: 0x01981980 - 0x01981981 (1 bytes)
            virtual void attack(f32 addval) {}  // vtable slot 7
            // Address: 0x01981990 - 0x01981991 (1 bytes)
            virtual void dodge() {}  // vtable slot 8
            virtual f32 getDecreaseVal();  // vtable slot 9
            // Address: 0x019819a0 - 0x019819a1 (1 bytes)
            virtual void init() {}  // vtable slot 10
            // Address: 0x019818d0 - 0x019818d1 (1 bytes)
            virtual void update() {}  // vtable slot 11
            virtual f32 getSpiritTimer() const;  // vtable slot 12
            // Address: 0x019819c0 - 0x019819c1 (1 bytes)
            virtual void setSpiritTimer(f32 val) {}  // vtable slot 13
            virtual f32 getBreakTimer() const;  // vtable slot 14
            // Address: 0x019818f0 - 0x019818f1 (1 bytes)
            virtual void setBreakTimer(f32 val) {}  // vtable slot 15
            virtual cpJob10::BOOST_MODE getBoostMode() const;  // vtable slot 16
            // Address: 0x01981910 - 0x01981911 (1 bytes)
            virtual void setBoostMode(cpJob10::BOOST_MODE boostMode) {}  // vtable slot 17
        protected:
            cpJob10::cSpiritManager* mpParent;  // offset: 0x8
        public:
            static MyDTI DTI;
        };
    public:
        class cSpiritStateBoost : public cpJob10::cSpiritManager::cSpiritState
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
            cSpiritStateBoost();
            virtual cpJob10::cSpiritManager::SPIRIT_STATE getSpiritState() const;  // vtable slot 6
            virtual f32 getDecreaseVal();  // vtable slot 9
            virtual cpJob10::BOOST_MODE getBoostMode() const;  // vtable slot 16
            virtual void setBoostMode(cpJob10::BOOST_MODE boostMode);  // vtable slot 17
        private:
            u8 mBoostMode;  // offset: 0x10
        public:
            static MyDTI DTI;
        };
    public:
        class cSpiritStateNormal : public cpJob10::cSpiritManager::cSpiritState
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
            cSpiritStateNormal();
            virtual void attack(f32 addval);  // vtable slot 7
            virtual void dodge();  // vtable slot 8
            virtual f32 getDecreaseVal();  // vtable slot 9
            virtual void init();  // vtable slot 10
            virtual f32 getSpiritTimer() const;  // vtable slot 12
            virtual void setSpiritTimer(f32 val);  // vtable slot 13
        private:
            f32 mSpiritTimer;  // offset: 0x10
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
        cpJob10::BOOST_MODE getBoostMode() const;
        bool isFulfill() const;
        f32 getSpiritRate() const;
    private:
        f32 getSpirit() const;
        void setSpirit(f32 val);
        uHuman* getHuman() const;
    public:
        SPIRIT_STATE getSpiritState() const;
        void attack(f32 addval);
        void dodge();
        void setupJobDataSafeArea();
        void init();
        void update();
        void reqChangeBoostMode(cpJob10::BOOST_MODE boostMode);
        void addSpirit(f32 addval, f32 rate);
        void reqEndBoost();
    private:
        void syncContext();
        void writeContext();
        void readContext();
        void decreaseSpirit();
        bool boostEndCheck();
    public:
        cSpiritManager();
        cSpiritManager(cpJob10* pParent);
        f32 getSpirit_Gi() const;
        void setSpirit_Gi(f32 NewValue);
    private:
        cSpiritStateNormal mStateNormal;  // offset: 0x8
        cSpiritStateBoost mStateBoost;  // offset: 0x20
        cSpiritState* mpStateNow;  // offset: 0x38
        cpJob10* mpParent;  // offset: 0x40
        f32 mSpirit_Gi;  // offset: 0x48
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
    cpJob10();
    virtual ~cpJob10();
    virtual void init();  // vtable slot 19
    virtual void setup();  // vtable slot 6
    virtual void setupJobData();  // vtable slot 21
    virtual void setupJobDataSafeArea();  // vtable slot 22
    virtual void before();  // vtable slot 15
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void update();  // vtable slot 16
    void compMoveAfter();
    virtual void reset();  // vtable slot 20
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 30
    virtual void callbackDamage(cHitInfo* pHitLocalInfo);  // vtable slot 33
    virtual void callbackDamageTest(cHitInfo* pHitInfo);  // vtable slot 36
    virtual void callbackCaughtTest(cHitInfo* pHitInfo);  // vtable slot 37
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 44
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    virtual void callbackReqEnchant();  // vtable slot 59
    void EffectProc();
    void BoostBoostProc();
protected:
    bool canDodge(cHitInfo* pHitInfo) const;
public:
    void reqBoostMode(BOOST_MODE mode);
    bool isBoosting();
    u32 getBoostMode() const;
    bool canReqBoost() const;
    void addSpirit(f32 addval);
    f32 getSpiritRate() const;
    void reqAttackChargeSpirit(cHitInfo* pHitInfo);
    u8 getRampageType();
    void setRampageType(u8);
    u32 convertBoostMotNo(u32 motNo);
    bool isBoostMot(u32 motNo);
    void setJob10Motion(u32 motNo, bool forcible, u32 attr, f32 hokan, f32 frame, f32 speed);
    u16 getActFreeWork() const;
    void setActFreeWork(u16 work);
    u16 getItemActFreeWork() const;
    void setItemActFreeWrok(u16 item);
    void reqDispNoSpirit();
    bool canEndureInClimb();
    bool checkCndEnableDelayCombo() const;
    void callbackFantasticBoost();
    void rgeEndBoostMode();
    bool checkCanEndBoost();
    void onJob10ActionEndFlg();
private:
    void updateJob10UI();
public:
    void ControlNmSup();
    void SetNSTimer();
    void reqHealPartyHealAll();
    void reqSupLimitBreak();
private:
    void reqSupLimitBreakShl(u32 id);
public:
    bool canUseCs02Air() const;
    void useCs02Air();
    void resetUseNumCs02Air();
    bool canUseCs02Shrink() const;
    bool canUseCs02AirBlow() const;
    bool canUseCs02Dodge() const;
    bool canUseCs02() const;
    bool canUseCs02FromCs03() const;
    f32 getCs04RotX() const;
    void setCs04RotX(f32);
    void resetCs04RotX();
    MtVector3 getCs04AimPos() const;
    f32 getCs04LockOnRange() const;
private:
    void updateCS04();
public:
    bool isExistImpactForce();
    const MtVector3 getImpactForcePos(bool isNextLv) const;
    void reqCS05Explosion(bool islv6);
    void setInitCS05();
    void setEndCS05();
    void updateCS05();
    f32 getCS05Timer();
    bool isSpritBarrier();
    void updateCs06();
    void reqActiveSpritBarrier(bool isLv2);
    void reqReleaseSpritBarrier();
    void reqPoseSpritBarrier();
    void reqUnPoseSpritBarrier();
    bool isSpritBarrierCharged();
    const MtVector3 getSpritBarrierPos() const;
    bool isBarrierPoweruped();
    void setBarrierPoweruped(bool flg);
    void spritBarrierDamageNotice(cHitInfo* pHitLocalInfo);
    void spritBarrierAttackNotice(f32 attackval);
    const MtVector3& getCs08Pos() const;
    f32 getCs08ChargeRate() const;
    f32 getCs08ChargeRateCache() const;
    CS08_SHL_SIZE getCs08ShlSize() const;
    CS08_SHL_SIZE getCs08ShlSizeCache() const;
    void setCs08ShlSizeCache(CS08_SHL_SIZE shlSize);
    f32 getCs08PreShlChargeFrameMax() const;
protected:
    bool canShotCs08PreShl() const;
    u32 getCs08PreShlEffectTimerMax() const;
public:
    void generateShlCs08(u32 skillLv);
    void updateCs08();
    void requestCs08Effect();
    void updateCs08Effect();
    void killCs08Effect();
    void updateCs08Pos();
    bool canShotCs08Shl() const;
    void updateChargeRateCache();
private:
    cSpiritManager* mpSpiritMgr;  // offset: 0x58
    bool isDispBoostEft;  // offset: 0x60
    bool isDispBoostNukeSe;  // offset: 0x61
    bool isDispBoostSupSe;  // offset: 0x62
    bool isJob10ActionEnd;  // offset: 0x63
    f32 mChargeCoolDown;  // offset: 0x64
    u8 mRampageType;  // offset: 0x68
    bool isDispHanyouEft;  // offset: 0x69
    bool isDispZanzouEft;  // offset: 0x6a
    cEfcHandle* mEfcLanceHanyouHnd;  // offset: 0x70
    cEfcHandle* mEfcLanceZanzouHnd;  // offset: 0x78
    cEfcHandle* mEfcLanceNormalHnd;  // offset: 0x80
    cEfcHandle* mEfcLanceNukeBoostHnd;  // offset: 0x88
    cEfcHandle* mEfcLanceSupportBoostHnd;  // offset: 0x90
    cEfcHandle* mEfcBoostAuraHnd;  // offset: 0x98
    bool mIsDispNoSpiritUi;  // offset: 0xa0
    f32 mDispNoSpiritUiTimer;  // offset: 0xa4
    f32 mCantDispNoSpiritUiTimer;  // offset: 0xa8
    f32 mCantDispNoSpiritSeTimer;  // offset: 0xac
    bool mIsCanClimbEndure;  // offset: 0xb0
    f32 mCanClimbEndureTimer;  // offset: 0xb4
public:
    bool mDispBoostSelectHud;  // offset: 0xb8
private:
    f32 mNormalSupporTimer;  // offset: 0xbc
    u32 mUseNumCustom02Air;  // offset: 0xc0
    f32 mCustom4RotX;  // offset: 0xc4
    MtVector3 mCS04AimPos;  // offset: 0xd0
    bool mIsReqDeleteCS05;  // offset: 0xe0
    f32 mCS05DleteTimer;  // offset: 0xe4
    f32 mCS05DleteTimerMax;  // offset: 0xe8
    f32 mCS05Timer;  // offset: 0xec
public:
    bool mIsActiveSpritBarrier;  // offset: 0xf0
    u32 mSpritBarrierCount;  // offset: 0xf4
    f32 mBarrierChargeForce;  // offset: 0xf8
    f32 mBarrierBreakImuneTimer;  // offset: 0xfc
    bool mIsBarrierPoweruped;  // offset: 0x100
private:
    nDDOUtility::cKeyFrameValueF32 mCs08ShlKeyFrame;  // offset: 0x108
    uDDOModel* mpCs08EfcUnit;  // offset: 0x158
    cEfcHandle* mpCs08EfcHnd;  // offset: 0x160
    cEfcHandle* mpCs08EfcHndSphere;  // offset: 0x168
    MtVector3 mCs08ShlPos;  // offset: 0x170
    f32 mCs08ContinueFrame;  // offset: 0x180
    f32 mCs08ContinueFrameMax;  // offset: 0x184
    f32 mCs08ShlEfcEpvCenterTimer;  // offset: 0x188
    f32 mCs08ChargeRateCache;  // offset: 0x18c
    u16 mCs08ShlSizeCache;  // offset: 0x190
    bool mHsCs08Shl;  // offset: 0x192
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cpJob10::cSpiritManager::cSpiritState::cSpiritState() {
    this->mpParent = static_cast<cpJob10::cSpiritManager*>(nullptr);
}
