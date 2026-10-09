#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "nDDOUtility.h"
#include "rEffectList.h"
#include "sCollision.h"
#include "uEffect.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;
class cEfcHandle;
class cParticle;
class cParticleGenerator;
class cParticleManager;
class uDDOModel;

// Declarations
class uEffectExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using cWeatherFlag = nDDOUtility::cBitSet<32>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class uEffectExt : public uEffect
{
public:
    enum
    {
        LIGHT_INF_CUSTOM1 = 0,
        LIGHT_INF_CUSTOM2 = 1,
        LIGHT_INF_CUSTOM3 = 2,
        LIGHT_INF_CUSTOM4 = 3,
        LIGHT_INF_CUSTOM6 = 4,
        LIGHT_INF_NUM = 5,
    };
    enum PROCESS_REDUCE_TURN
    {
        PRT_NORMAL = 0,
        PRT_DOWN = 1,
        PRT_UP = 2,
        PRT_MAX = 3,
    };
    enum EFFECT_KIND
    {
        EFFECT_KIND_ST = 1,
        EFFECT_KIND_EV = 2,
        EFFECT_KIND_TT = 4,
        EFFECT_KIND_RAIN = 8,
        EFFECT_KIND_MAX = -1,
    };
public:
    class MyDTI;
    struct CORRECT_COLOR_PARAM;
    struct stColor16;
    struct stColorAttr;
    struct CORRECT_WIND_PARAM;
    class cRequestDispCtrlFlagCtrl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stColor16
    {
    public:
        uEffectExt::stColor16& operator=(const uEffectExt::stColor16&);
        uEffectExt::stColor16& operator=(u32 val);
        void eqRGB(uEffectExt::stColor16&);
        void eqRGB(const MtColor& val);
        void mulRGB(u32 rate);
        void mulRGB(const MtColor& val, u32 rate);
        void mulRGB(f32);
    public:
        u32 R : 16;  // offset: 0x0
        u32 G : 16;  // offset: 0x0
        u32 B : 16;  // offset: 0x4
        u32 A : 16;  // offset: 0x4
    };
public:
    struct stColorAttr
    {
    public:
        uEffectExt::stColorAttr& operator=(const uEffectExt::stColorAttr&);
        uEffectExt::stColorAttr& operator=(u16 val);
    public:
        u32 Intensity;  // offset: 0x0
        u32 ColorBlend : 16;  // offset: 0x4
        u32 IntensityBlend : 16;  // offset: 0x4
    };
public:
    struct CORRECT_WIND_PARAM
    {
    public:
        struct ZONE_WIND_PARAM;
    public:
        struct ZONE_WIND_PARAM
        {
        public:
            ZONE_WIND_PARAM();
            static void* operator new(size_t);
            static void operator delete(void*);
            static void* operator new[](size_t s);
            static void operator delete[](void* padr);
        public:
            MtVector3 mDirection;  // offset: 0x0
            u32 mFlag : 1;  // offset: 0x10
            u32 mDummy : 31;  // offset: 0x10
        };
    public:
        CORRECT_WIND_PARAM();
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
    public:
        ZONE_WIND_PARAM* mpZoneWindParam;  // offset: 0x0
        u32 mZoneWindParamNum;  // offset: 0x8
    };
public:
    class cRequestDispCtrlFlagCtrl
    {
    public:
        enum EFC_DISP_CTRL
        {
            EFC_MOVE_ABNORMAL_DISP_OFF_REQUEST = 1,
            EFC_MOVE_STOP_ABNORMAL_DISP_OFF_CONST = 2,
            EFC_DISTANCE_SUPER_EROSION_DISP_OFF = 4,
            EFC_ONECE_EFFECT_TYPE_DISP_OFF = 8,
        };
    public:
        cRequestDispCtrlFlagCtrl();
        void init();
        void init(uEffectExt* pOwner);
        void update();
        void onDispCtrlFlag(u32 on);
        void offDispCtrlFlag(u32 off);
        void setDispCtrlFlag(u32 set);
        f32 getApplicationRate();
        bool isProgressDispOff();
    private:
        u32 mDispCtrlFlag;  // offset: 0x0
        f32 mApplicationRate;  // offset: 0x4
        uEffectExt* mpOwner;  // offset: 0x8
    };
public:
    struct CORRECT_COLOR_PARAM
    {
    public:
        struct ZONE_PARAM;
        struct GENERAL_PARAM;
    public:
        struct ZONE_PARAM
        {
        public:
            ZONE_PARAM();
            f32 getShadowRate();
            static void* operator new(size_t);
            static void operator delete(void*);
            static void* operator new[](size_t s);
            static void operator delete[](void* padr);
        public:
            uEffectExt::stColor16 mBaseColor;  // offset: 0x0
            uEffectExt::stColorAttr mBaseAttr;  // offset: 0x8
            uEffectExt::stColor16 mShadowColor;  // offset: 0x10
            uEffectExt::stColorAttr mShadowAttr;  // offset: 0x18
            uEffectExt::stColor16 mMixColor;  // offset: 0x20
            uEffectExt::stColorAttr mMixAttr;  // offset: 0x28
            uEffectExt::stColor16 mMixShadowColor;  // offset: 0x30
            uEffectExt::stColorAttr mMixShadowAttr;  // offset: 0x38
            f32 mEnvMapPowerScale;  // offset: 0x40
            f32 mShadowRate;  // offset: 0x44
            f32 mLanternRate;  // offset: 0x48
            u32 mLanternColorR : 16;  // offset: 0x4c
            u32 mLanternColorG : 16;  // offset: 0x4c
            u32 mLanternColorB : 16;  // offset: 0x50
            u32 mLanternColorBlend : 16;  // offset: 0x50
            u32 mLanternIntensity;  // offset: 0x54
            u32 mLanternIntensityBlend : 16;  // offset: 0x58
            u32 mCorrectType : 4;  // offset: 0x58
            u32 mFlag : 1;  // offset: 0x58
            u32 mUseSkyColor : 1;  // offset: 0x58
            u32 mUseShadowColor : 1;  // offset: 0x58
            u32 mUseMixColor : 1;  // offset: 0x58
            u32 mAlwaysLantern : 1;  // offset: 0x58
            u32 mUsePointLightSupp : 1;  // offset: 0x58
            u32 mDummy : 6;  // offset: 0x58
            f32 mUpdateTimer;  // offset: 0x5c
        };
    public:
        struct GENERAL_PARAM
        {
        public:
            static void* operator new(size_t);
            static void operator delete(void*);
            static void* operator new[](size_t);
            static void operator delete[](void*);
        public:
            uEffectExt::stColor16 mColor;  // offset: 0x0
            u32 mRate : 16;  // offset: 0x8
            u32 mFlag : 1;  // offset: 0x8
            u32 mMode : 8;  // offset: 0x8
            u32 mDummy : 7;  // offset: 0x8
        };
    public:
        CORRECT_COLOR_PARAM();
        void setGeneralColor(const MtColor& color, f32 rate, f32 alpha_rate, u32 mode);
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
    public:
        ZONE_PARAM* mpZoneParam;  // offset: 0x0
        u32 mZoneParamNum;  // offset: 0x8
        GENERAL_PARAM mGeneralParam;  // offset: 0xc
        u32 mTransparency;  // offset: 0x18
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
    uEffectExt();
    virtual ~uEffectExt();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void updateDeltaTimeRate();  // vtable slot 39
    void setSucceedParam(uEffectExt* pUnit);
    uEffectExt* getNextUnit() const;
    void setNextUnit(uEffectExt*);
    uEffectExt* getGroupNextUnit() const;
    void setGroupNextUnit(uEffectExt*);
    u64 getUniqueID() const;
    void setUniqueID(u64);
    u64 getGroupID() const;
    void setGroupID(u64);
    u64 getGroupNo() const;
    void setGroupNo(u8 no);
    virtual void updateParentPtr();  // vtable slot 81
    void setHitStopMode(bool Flg);
    bool getHitStopMode() const;
    void setWorkRateMode(bool Flg);
    bool getWorkRateMode() const;
    void applyCustomWorkRateType(u32);
    void setCustomWorkRateType(u32 Data);
    u32 getCustomWorkRateType() const;
    void setParentActor(uDDOModel* pParent, bool Flg0, bool Flg1);
    uDDOModel* getParentActor() const;
    void setParentBaseModelFlag(bool Flg);
    bool getParentBaseModelFlag() const;
    void setParentTransparency(bool Flg);
    bool getParentTransparency() const;
    void setTransparencyExt(f32 val);
    f32 getTransparencyExt() const;
    void setParentDrawModeDefault(bool flag);
    bool getParentDrawModeDefault();
    void setGeneralCorrectColor(const MtColor& color, f32 rate, f32 alpha_rate, u32 mode);
    void setUnitEndType(u32 type);
    u32 getUnitEndType() const;
    f32 getDeltaTimeCoefEx() const;
    void setDeltaTimeCoefEx(f32 DeltaTimeCoef);
    void setCCTransparency(f32 val);
    f32 getCCTransparency() const;
    void setQuakeCancel(bool flag);
    bool getQuakeCancel() const;
    void setLanternCancel();
    bool getLanternCancel() const;
    void setMotSyncFlag(bool flag);
    bool getMotSyncFlag() const;
    void setMotSyncMotionNo(u32 no);
    u32 getMotSyncMotionNo() const;
    void setMotSyncBlendIndex(u32 idx);
    u32 getMotSyncBlendIndex() const;
    void setMotSyncStartFrame(f32 frame);
    f32 getMotSyncStartFrame() const;
    void setMotSyncEndFrame(f32 frame);
    f32 getMotSyncEndFrame() const;
    bool getMotSyncLeaveFlag() const;
    void setMotSyncLeaveFlag(bool flag);
    bool getMotSyncFreeSpeedFlag() const;
    void setMotSyncFreeSpeedFlag(bool flag);
    void setFollowSunFlag(bool flag);
    bool getFollowSunFlag() const;
    void setFollowMoon(bool flag);
    bool getFollowMoon() const;
    void setZoneCheckGeneratorFlag(bool flag);
    bool getZoneCheckGeneratorFlag() const;
    void setZoneUnitColorFlag();
    bool getZoneUnitColorFlag() const;
    void setColorUpdateFlag(bool flag);
    bool getColorUpdateFlag() const;
    void setZoneCorrectType(u32);
    u32 getZoneCorrectType() const;
    void setColorUpdateDistCancelFlag(bool flag);
    bool getColorUpdateDistCancelFlag() const;
    void setFineWeatherOffFlag(bool flag);
    bool getFineWeatherOffFlag() const;
    void setCloudyWeatherOffFlag(bool flag);
    bool getCloudyWeatherOffFlag() const;
    void setRainWeatherOffFlag(bool flag);
    bool getRainWeatherOffFlag() const;
    void setWeatherOnFlag(s32 weatherID, bool flag);
    void setWeatherOnFlag(const cWeatherFlag& flag);
    bool isWeatherOnFlag(s32 weatherID) const;
    void setCameraEventOffFlag(bool flag);
    bool getCameraEventOffFlag() const;
    void setEventKillFlag(bool flag);
    bool getEventKillFlag() const;
    void setDayNightBlendOffFlag(bool flag);
    bool getDayNightBlendOffFlag() const;
    void setDayNightBlendOffNFlag(bool flag);
    bool getDayNightBlendOffNFlag() const;
    void setInDoorScrlEfcOn(u32 bit);
    u32 getInDoorScrlEfcOn() const;
    void setQuakeType(u32 set);
    u32 getQuakeType();
    void setCameraQuake();
protected:
    void buildCorrectColorFromZone();
    void updateCorrectColor();
    void buildWindParamFromZone();
    virtual uEffect* openEffect();  // vtable slot 57
    virtual bool createGenerator();  // vtable slot 58
    virtual void initParticleCustom(cParticleGenerator* pGenerator, cParticle* pParticle, f32 LifeRate);  // vtable slot 49
    virtual bool moveParticleCustom(cParticleGenerator* pGenerator, cParticle* pParticle);  // vtable slot 50
    virtual void correctColorIntensity(cParticleGenerator* pGenerator, MtColor* pColor, u32 ColorNum, u32* pIntensity);  // vtable slot 41
    virtual u32 updateParticlePosForce(u32 ForceType, f32 ForceRate, const MtVector3& ForceVec, MtVector3& Pos);  // vtable slot 71
    virtual u32 checkCollisionLine(sCollision::TriangleInfo* pTriangleInfo, u32* pPtclFlag, const MtLineSegment& LineSegment, rEffectList::EFL_PARAM_COLL* pCollParam);  // vtable slot 72
    virtual u32 checkCollsionSphere(sCollision::TriangleInfo* pTriangleInfo, u32* pPtclFlag, MtVector3& Pos, const MtVector3& OldPos, f32 Radius, rEffectList::EFL_PARAM_COLL* pCollParam);  // vtable slot 73
    virtual u32 setCollBounceReaction(rEffectList::EFL_PARAM_COLL* pCollParam, sCollision::TriangleInfo* pInfo, u32 Attribute);  // vtable slot 74
    virtual u32 setCollFinishReaction(rEffectList::EFL_PARAM_COLL* pCollParam, sCollision::TriangleInfo* pInfo, u32 Attribute);  // vtable slot 75
    virtual u32 getCollBounceMaterialFlag(sCollision::TriangleInfo* pTriangleInfo) const;  // vtable slot 76
    virtual u32 getCollFinishMaterialFlag(sCollision::TriangleInfo* pTriangleInfo) const;  // vtable slot 77
    virtual f32 correctModelEnvMapPower(cParticleGenerator* pGenerator, const MtVector3& Pos, f32 OrgEnvMapPower);  // vtable slot 42
    virtual MtVector4 correctFilterColor(cParticleGenerator* pGenerator, const MtVector3& Pos, const MtVector4& OrgColor);  // vtable slot 43
    virtual MtVector3 correctLightColor(cParticleGenerator* pGenerator, const MtVector3& Pos, const MtVector3& OrgColor);  // vtable slot 44
    virtual void requestSoundSe(cParticleManager* pManager);  // vtable slot 78
    virtual void stopSoundSe(cParticleManager* pManager);  // vtable slot 79
    virtual bool checkEffectList(u32 ListNo);  // vtable slot 61
private:
    bool isEndMotSync() const;
    bool isKillMotSync() const;
    bool getZoneCheckPosFromUnit(MtVector3& ckPos) const;
    bool getZoneCheckPosFromGenerator(MtVector3& ckPos, cParticleManager* pManager) const;
    void storeColorParamFromZone(u32 no, const MtVector3& ckPos, u32 correctType);
    void storeWindParamFromZone(u32 no, const MtVector3& ckPos);
    void updateCorrectColorParam(u32 no, const MtVector3& ckPos);
    void setupBlendColor(stColor16& dstColor, stColorAttr& dstAttr, f32 colorBlend, f32 intensity, f32 intensityBlend, const MtColor& color);
    void correctColorIntensitySub(const stColor16& color, const stColorAttr& attr, const stColor16& mixColor, const stColorAttr& mixAttr, CORRECT_COLOR_PARAM::ZONE_PARAM* pZoneParam, bool useLantan, MtColor* pColor, u32 colorNum, u32* pIntensity);
    void storeColorParamFromZoneSub(stColor16& dstColor, stColorAttr& dstAttr, f32 colorBlend, f32 intensity, f32 intensityBlend, const MtColor& color);
    void storeColorParamFromZoneSubMix(stColor16& dstColor, stColorAttr& dstAttr, f32 colorBlend, f32 intensity, f32 intensityBlend, const MtColor& color);
    f32 getShadowRate(const MtVector3& ckPos) const;
    void setCorrectColor(const MtVector3& color);
    MtVector3 getCorrectColor() const;
    void setCorrectColorRate(f32 rate);
    f32 getCorrectColorRate() const;
    void setCorrectColorAlpha(f32 alpha);
    f32 getCorrectColorAlpha() const;
    f32 getWeatherOffTransparency(u32 weatherType) const;
    bool isAlwaysLantern() const;
    void setupLightInf();
public:
    void resetEffectKind();
    virtual bool isEffectSt();  // vtable slot 80
    bool isEffectRain();
private:
    bool checkStageResource();
    bool checkEventResource();
    bool checkTitleResource();
    bool checkResourceKind(MT_CTSTR str);
public:
    void setCreateCost(u32 Cost);
    u32 getCreateCost();
    void setProcessReduceStart();
    void setProcessReduceEnd();
    f32 getProcessReduceCoef();
    virtual void doFinish();  // vtable slot 34
    void setFinishFadeOutFrame(f32 set);
    u32 getLimitedRestartNum();
    bool isForceStartLimitedRestart(u32 LimitedRestartNum);
    void forceStartLimitedRestart();
    void moveLimitedRestart();
    void setOthersTransparencyPercentage(f32 set);
    f32 getOthersTransparencyPercentage();
    void setEpvPos(const MtVector3& set);
    MtVector3 getEpvPos();
    bool getWorldOffsetDifference(MtVector3* WorldOffsetDifference);
    cRequestDispCtrlFlagCtrl* getRDCFC();
protected:
    uEffectExt* mpNext;  // offset: 0x258
    u64 mUniqueID;  // offset: 0x260
    uEffectExt* mpGroupNext;  // offset: 0x268
    u64 mGroupID;  // offset: 0x270
    cEfcHandle* mpHandle;  // offset: 0x278
    u8 mGroupNo;  // offset: 0x280
private:
    f32 mTransparencyExt;  // offset: 0x284
    f32 mTransparencyCoefBuffer;  // offset: 0x288
    u32 mHitStopMode : 1;  // offset: 0x28c
    u32 mWorkRateMode : 1;  // offset: 0x28c
    u32 mParentBaseModelFlag : 1;  // offset: 0x28c
    u32 mParentTransparency : 1;  // offset: 0x28c
    u32 mEnableMotSync : 1;  // offset: 0x28c
    u32 mFollowSun : 1;  // offset: 0x28c
    u32 mColorUpdate : 1;  // offset: 0x28c
    u32 mZoneCheckGenerator : 1;  // offset: 0x28c
    u32 mZoneUnitColor : 1;  // offset: 0x28c
    u32 mColorUpdateDistCancel : 1;  // offset: 0x28c
    u32 mZoneUpdateFlag : 1;  // offset: 0x28c
    u32 mFineWeatherOff : 1;  // offset: 0x28c
    u32 mCloudyWeatherOff : 1;  // offset: 0x28c
    u32 mRainWeatherOff : 1;  // offset: 0x28c
    u32 mCameraEventOff : 1;  // offset: 0x28c
    u32 mEventKill : 1;  // offset: 0x28c
    u32 mDayNightBlendOff : 1;  // offset: 0x28c
    u32 mDayNightBlendOffN : 1;  // offset: 0x28c
    u32 mFollowMoon : 1;  // offset: 0x28c
    u32 mParentDrawModeDefault : 1;  // offset: 0x28c
    u32 mPrtDrawModeDefaultReq : 1;  // offset: 0x28c
    u32 mReserve21 : 1;  // offset: 0x28c
    u32 mReserve22 : 1;  // offset: 0x28c
    u32 mReserve23 : 1;  // offset: 0x28c
    u32 mReserve24 : 1;  // offset: 0x28c
    u32 mReserve25 : 1;  // offset: 0x28c
    u32 mReserve26 : 1;  // offset: 0x28c
    u32 mReserve27 : 1;  // offset: 0x28c
    u32 mReserve28 : 1;  // offset: 0x28c
    u32 mReserve29 : 1;  // offset: 0x28c
    u32 mReserve30 : 1;  // offset: 0x28c
    u32 mReserve31 : 1;  // offset: 0x28c
    cWeatherFlag mWeatherOnBit;  // offset: 0x290
    u32 mInDoorScrlEfcOn;  // offset: 0x294
    f32 mInDoorScrlEfcRate;  // offset: 0x298
    uDDOModel* mpParentActor;  // offset: 0x2a0
    u32 mCustomWorkRateType;  // offset: 0x2a8
    CORRECT_COLOR_PARAM mCorrectColorParam;  // offset: 0x2b0
    CORRECT_WIND_PARAM mCorrectWindParam;  // offset: 0x2d0
    u32 mUnitEndType;  // offset: 0x2e0
    f32 mDeltaTimeCoefEx;  // offset: 0x2e4
    f32 mColorUpdateTime;  // offset: 0x2e8
    bool mQuakeCancel;  // offset: 0x2ec
    bool mLanternCancel;  // offset: 0x2ed
    u32 mQuakeType;  // offset: 0x2f0
    bool mbLighting;  // offset: 0x2f4
    u32 mLightInf[5];  // offset: 0x2f8
    MtColor mLightColor;  // offset: 0x30c
    f32 mLightInten;  // offset: 0x310
    u32 mMotSyncBlendIndex : 6;  // offset: 0x314
    u32 mMotSyncMotionNo : 16;  // offset: 0x314
    u32 mMotSync_Reserve : 10;  // offset: 0x314
    f32 mMotSyncStartFrame;  // offset: 0x318
    f32 mMotSyncEndFrame;  // offset: 0x31c
    bool mMotSyncLeaveFlag;  // offset: 0x320
    bool mMotSyncFreeSpeedFlag;  // offset: 0x321
    f32 mFollowSunDist;  // offset: 0x324
    f32 mFollowMoonDist;  // offset: 0x328
    u32 mZoneCorrectType;  // offset: 0x32c
    u32 mEffectKind;  // offset: 0x330
    u32 mCreateCost;  // offset: 0x334
    f32 mProcessTransparencyCoef;  // offset: 0x338
    u32 mProcessReduceFlag;  // offset: 0x33c
    f32 mFinishFadeOutFrame;  // offset: 0x340
    f32 mFinishFadeOutPassage;  // offset: 0x344
    f32 mOthersTransparencyPercentage;  // offset: 0x348
    MtVector3 mEpvPos;  // offset: 0x350
    cRequestDispCtrlFlagCtrl mRDCFC;  // offset: 0x360
public:
    static MyDTI DTI;
private:
    static const f32 COLOR_UPDATE_DISTANCE;
    static const f32 SUN_DISTANCE;
};
