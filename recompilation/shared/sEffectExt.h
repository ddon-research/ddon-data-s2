#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cEffectOnce.h"
#include "cZoneListenerEffect.h"
#include "cZoneListenerMulti.h"
#include "nDDOUtility.h"
#include "rEffectProvider.h"
#include "rTbl2.h"
#include "res_ptr.h"
#include "sCollision.h"
#include "sEffect.h"
#include "sUnit.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtVector3;
class cDamageEffInfo;
class cEfcHandle;
class cOnceRequestEffectTypeSuperErosionCam;
class cOutlineParam;
class cUnit;
class cZoneListenerEffectEFL;
class cZoneMultiStack;
class rEffect2D;
class rEffectList;
class rEffectProvider;
class rOutlineParamList;
class rTexture;
class rZone;
class uDDOModel;
class uEfCam;
class uEffect;
class uEffect2D;
class uEffect2DExt;
class uEffectExt;
class uEnemy;

// Declarations
class cVfxLightInfluence;
class rVfxLightInfluence;
class sEffectExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cVfxLightInfluence : public MtObject
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
    cVfxLightInfluence();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    f32 mLightIntensity;  // offset: 0x8
    f32 mCustom1;  // offset: 0xc
    f32 mCustom2;  // offset: 0x10
    f32 mCustom3;  // offset: 0x14
    f32 mCustom4;  // offset: 0x18
    f32 mCustom6;  // offset: 0x1c
    f32 mEnv1;  // offset: 0x20
    f32 mEnv2;  // offset: 0x24
    static const u32 DATA_VERSION = 3;
    static MyDTI DTI;
};

class rVfxLightInfluence : public rTbl2<cVfxLightInfluence>
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
    virtual bool loadData(MtDataReader& in, cVfxLightInfluence* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class sEffectExt : public sEffect
{
    // inferred: uEffect2DExt::~uEffect2DExt calls sEffectExt::removeEffect2D
    friend class uEffect2DExt;
public:
    enum OUTLINE
    {
        OUTLINE_LV_UP = 0,
        OUTLINE_HEAL_HP = 1,
        OUTLINE_HEAL_STAMINA = 2,
        OUTLINE_HEAL_STATUS = 3,
        OUTLINE_HEALING_SPOT = 4,
        OUTLINE_HOLY_ABSORB = 5,
        OUTLINE_SPECULATION_BODY = 6,
        OUTLINE_BAD_STATTUS_HIT = 7,
        OUTLINE_ST_UP_TRG = 8,
        OUTLINE_ST_DOWN_TRG = 9,
        OUTLINE_ST_UP = 10,
        OUTLINE_ST_DOWN = 11,
        OUTLINE_CHARGE_CMP = 12,
        OUTLINE_CMC_APPEAR = 13,
        OUTLINE_CMC_FURY = 14,
        OUTLINE_CMC_CHARGE_FURY = 15,
        OUTLINE_ENEMY_ANGRY = 16,
        OUTLINE_REVIVE_KODOU = 17,
        OUTLINE_REVIVE_KAISUKEN = 18,
        OUTLINE_CS_COVERSHILD = 19,
        OUTLINE_CS_JUSTRELOAD = 20,
        OUTLINE_REVIVE_PAWN_YURYO = 21,
        OUTLINE_REVIVE_PAWN_MURYO = 22,
        OUTLINE_SELECT_ELEMENT_FIRE = 23,
        OUTLINE_SELECT_ELEMENT_ICE = 24,
        OUTLINE_SELECT_ELEMENT_THUNDER = 25,
        OUTLINE_SELECT_ELEMENT_HOLY = 26,
        OUTLINE_SELECT_ELEMENT_DARK = 27,
        OUTLINE_CS_PARRY_STEP = 28,
        OUTLINE_FT_CHARGE_CMP = 29,
        OUTLINE_CS_IRON_FIELD = 30,
        OUTLINE_REINFORCEMENT = 31,
        OUTLINE_WEAKENING = 32,
        OUTLINE_REVIVE_LIFE = 33,
        OUTLINE_OCD_SHAKE_CHANE = 34,
        OUTLINE_SPECULATION_BODY_BIGEM = 35,
        OUTLINE_RAGE_SHRINK = 36,
        OUTLINE_BOOST = 37,
        OUTLINE_EVENT01 = 38,
        OUTLINE_EVENT02 = 39,
        OUTLINE_TYPE_MAX = 40,
    };
    enum OPTION_OTHERS_EFC_TYPE
    {
        OOET_PERCANT_100 = 0,
        OOET_PERCANT_50 = 1,
        OOET_PERCANT_25 = 2,
        OOET_PERCANT_0 = 3,
        OOET_PERCENT_NUM = 4,
    };
    enum
    {
        COMMON_EPV_TYPE_00 = 0,
        COMMON_EPV_TYPE_NUM = 1,
    };
    enum
    {
        TIME_FILTER_NONE = 0,
        TIME_FILTER_DAY = 1,
        TIME_FILTER_NIGHT = 2,
        TIME_FILTER_NUM = 3,
    };
    enum EFC_END_TYPE
    {
        EFC_END_TYPE_FINISH = 1,
        EFC_END_TYPE_KILL = 2,
        EFC_END_TYPE_KPHDOFF = 3,
        EFC_END_TYPE_NONE = 4,
        EFC_END_TYPE_MAX = 5,
    };
    enum EFC_STATUSAILMENTS
    {
        NONE = 0,
        FIRE = 1,
        FREEZE = 2,
        GENERAL = 3,
        OIL_WET = 4,
        STONE = 5,
        GOLD = 6,
        EROSION = 7,
        EFC_STATUSAILMENTS_MAX = 8,
    };
    enum EFFECT_DEPENDER_KIND
    {
        EDK_NONE = 0,
        EDK_ENEMY = 1,
        EDK_SCR = 2,
        EDK_MASTER_PLAYER = 3,
        EDK_OTHER_PLAYER = 4,
        DEK_NUM = 5,
    };
    enum
    {
        ZONE_TYPE_COLOR_CORRECT = 0,
        ZONE_TYPE_WIND_CONTROL = 1,
        ZONE_TYPE_EFFECT_GENERATE = 2,
        ZONE_TYPE_MAX = 3,
    };
public:
    class MyDTI;
    class cStatusAilmentsTexture;
    class cZoneEpvStack;
    class cZoneEffectUnitLayout;
    class cZoneEffectUnit;
    class cEfcCameraQuakeData;
    class cEfcCameraQuakeDataLarge;
    class cEfcCameraQuakeDataMiddle;
    class cEfcCameraQuakeDataSmall;
    class EfcParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cStatusAilmentsTexture
    {
    public:
        cStatusAilmentsTexture();
        ~cStatusAilmentsTexture();
        const rTexture* getAlbedoMap();
        const rTexture* getNormalMap();
        const rTexture* getSpecularMap();
        void setAlbedoMap(rTexture* tex);
        void setNormalMap(rTexture* tex);
        void setSpecularMap(rTexture* tex);
        void release();
        void createMap(const char* numPath);
        void createAlbedoMap(char* defPath);
        void createNormalMap(char* defPath);
        void createSpecularMap(char* defPath);
    private:
        rTexture* mpAlbedoMap;  // offset: 0x0
        rTexture* mpNormalMap;  // offset: 0x8
        rTexture* mpSpecularMap;  // offset: 0x10
    };
public:
    class cZoneEpvStack : public MtObject
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
        cZoneEpvStack();
        virtual ~cZoneEpvStack();
    public:
        res_ptr<rEffectProvider> mpEpv;  // offset: 0x8
        u32 mHandle;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cZoneEffectUnitLayout : public MtObject
    {
    public:
        class MyDTI;
    public:
        using cEfcUnitArray = nDDOUtility::cArray<sEffectExt::cZoneEffectUnit*, 256>;
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
        cZoneEffectUnitLayout();
        virtual ~cZoneEffectUnitLayout();
        void initZoneEffectUnitLayout(u32 handle);
        void updateZoneEffectUnitLayout();
        void eraseZoneEffectUnitLayout();
    public:
        u32 mHandle;  // offset: 0x8
        u32 mZoneLayoutNum;  // offset: 0xc
        cEfcUnitArray mpZoneEffectUnit;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cZoneEffectUnit : public MtObject
    {
    public:
        class MyDTI;
    public:
        using cEfcHandleArray = nDDOUtility::cArray<cEfcHandle*, 32>;
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
        cZoneEffectUnit();
        virtual ~cZoneEffectUnit();
    public:
        u32 mResourceType;  // offset: 0x8
        cEfcHandleArray mpEffectHandle;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cEfcCameraQuakeData : public MtObject
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
        cEfcCameraQuakeData();
        // Address: 0x01ac2af0 - 0x01ac2af1 (1 bytes)
        virtual ~cEfcCameraQuakeData() {}
    public:
        u32 mTaskNo;  // offset: 0x8
        f32 mHeadTime;  // offset: 0xc
        f32 mMainTime;  // offset: 0x10
        f32 mTailTime;  // offset: 0x14
        MtVector3 mMagunitude;  // offset: 0x20
        MtVector3 mPos;  // offset: 0x30
        f32 mRadius;  // offset: 0x40
        f32 mSpread;  // offset: 0x44
        f32 mDamping;  // offset: 0x48
        f32 mPeriod;  // offset: 0x4c
        f32 mRoll;  // offset: 0x50
        f32 mBalance;  // offset: 0x54
        bool mbAsync;  // offset: 0x58
        static MyDTI DTI;
    };
public:
    class cEfcCameraQuakeDataLarge : public sEffectExt::cEfcCameraQuakeData
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
        cEfcCameraQuakeDataLarge();
    public:
        static MyDTI DTI;
    };
public:
    class cEfcCameraQuakeDataMiddle : public sEffectExt::cEfcCameraQuakeData
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
        cEfcCameraQuakeDataMiddle();
    public:
        static MyDTI DTI;
    };
public:
    class cEfcCameraQuakeDataSmall : public sEffectExt::cEfcCameraQuakeData
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
        cEfcCameraQuakeDataSmall();
    public:
        static MyDTI DTI;
    };
public:
    class EfcParam
    {
    public:
        enum EFC_OPTION_FLAG
        {
            EFC_OPTION_ENABLE_VOLUME_BLEND = 1,
            EFC_OPTION_ANGLE_SET = 2,
            EFC_OPTION_ORDER_SET = 4,
            EFC_OPTION_PARENT_SPEED = 8,
            EFC_OPTION_PARENT_SCALE = 16,
            EFC_OPTION_PARENT_SCALE_OFFSET = 32,
            EFC_OPTION_WORLD_ABSOLUTE_POS = 64,
            EFC_OPTION_DISABLE_PARENT_TRANSPARENSY = 128,
            EFC_OPTION_EVENT_OFF = 256,
            EFC_OPTION_SIMPLE_EVENT_OFF = 512,
            EFC_OPTION_CAMERA_EVENT_OFF = 1024,
            EFC_OPTION_PL_ATTACK_DAMAGE = 2048,
            EFC_OPTION_EVENT_KILL = 4096,
            EFC_OPTION_PARENT_OFSPOS_QUAT_OFF = 8192,
        };
    public:
        EfcParam();
        void setPos(const MtVector3& pos);
        void setLocalPos(uDDOModel* pParent, s32 jointNo, const MtVector3& pos);
        void setAngle(const MtVector3& angle);
        void setDir(const MtVector3& dir, u32 axisType);
        void setOrder(u32);
        void setScale(f32 scale);
        void setScale(const MtVector3& scale);
        void setMaterialFlag(u32 flag);
        void setParent(uDDOModel* pParent, s32 jointNo);
        void setMoveLine(MOVE_LINE);
        void setOptionFlag(u32 flag);
        void setLoopFrame(s32 frame);
        void setMotSyncFlag(bool flag);
        void setMotSyncLeaveFlag(bool flag);
        void setMotSyncFreeSpeedFlag(bool flag);
        void setMotSyncStartFrame(f32 frame);
        void setMotSyncEndFrame(f32 frame);
        void setMotSyncMotionNo(u32 no);
        void setMotSyncBlendIndex(u32 index);
        void setDispCtrlFlag(u32 set);
    public:
        MtVector3 mPosition;  // offset: 0x0
        MtVector3 mDirection;  // offset: 0x10
        u32 mMaterialFlag;  // offset: 0x20
        u32 mAxisType : 4;  // offset: 0x24
        u32 mOrder : 4;  // offset: 0x24
        u32 mExclusionTraits : 16;  // offset: 0x24
        u32 mMotSync : 1;  // offset: 0x24
        u32 mMotSyncLeave : 1;  // offset: 0x24
        u32 mMotSyncFreeSpeed : 1;  // offset: 0x24
        u32 __Reserve__ : 5;  // offset: 0x24
        MtVector3 mScale;  // offset: 0x30
        s32 mJointNo;  // offset: 0x40
        u32 mOptionFlag;  // offset: 0x44
        MOVE_LINE mMoveLine;  // offset: 0x48
        uDDOModel* mpParent;  // offset: 0x50
        MtColor mCorrectColor;  // offset: 0x58
        s32 mLoopFrame;  // offset: 0x5c
        f32 mMotSyncStartFrame;  // offset: 0x60
        f32 mMotSyncEndFrame;  // offset: 0x64
        u32 mMotSyncMotionNo;  // offset: 0x68
        u32 mMotSyncBlendIndex;  // offset: 0x6c
        u32 mDispCtrlFlag;  // offset: 0x70
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
    sEffectExt();
    virtual ~sEffectExt();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cStatusAilmentsTexture* getAilmentsTexture(u32 ailmentKind);
    virtual void move();  // vtable slot 7
    virtual MOVE_LINE getEffectMoveLine() const;  // vtable slot 11
    virtual MOVE_LINE getEffectEventMoveLine() const;  // vtable slot 12
    virtual MOVE_LINE getEffectToolUnitMoveLine() const;  // vtable slot 13
    virtual MOVE_LINE getEffectToolUnitEventMoveLine() const;  // vtable slot 14
    virtual MOVE_LINE getEffectModelMoveLine() const;  // vtable slot 15
    virtual MOVE_LINE getEffectModelEventMoveLine() const;  // vtable slot 16
    virtual MOVE_LINE getEffectMultiFilterMoveLine() const;  // vtable slot 17
    virtual MOVE_LINE getEffectFilterMoveLine() const;  // vtable slot 18
    virtual MOVE_LINE getEffectFilterEventMoveLine() const;  // vtable slot 19
    virtual u64 getEffectFilterUnitGroupBit() const;  // vtable slot 20
    virtual MOVE_LINE getEffectLightMoveLine() const;  // vtable slot 21
    virtual MOVE_LINE getEffectLightEventMoveLine() const;  // vtable slot 22
    virtual MOVE_LINE getEffectAdhesionMoveLine() const;  // vtable slot 23
    virtual MOVE_LINE getEffectAdhesionEventMoveLine() const;  // vtable slot 24
    virtual MOVE_LINE getEffectForceMoveLine() const;  // vtable slot 25
    virtual MOVE_LINE getEffectForceEventMoveLine() const;  // vtable slot 26
    virtual uEffect* newEffect();  // vtable slot 30
    virtual uEffect2D* newEffect2D();  // vtable slot 31
    uEfCam* newCameraEffect();
    cEfcHandle* setEffect(rEffectProvider* pEPV, s32 IndexNo, s32 ElementNo, const EfcParam& param, uDDOModel* pOrigin);
    void setEffect(rEffectProvider* pEPV, s32 IndexNo, const EfcParam& param, uDDOModel* pOrigin, MtTypedArray<cEfcHandle>* pEffects);
    void setTypeEffect(rEffectProvider* pEPV, u32 effectType, const EfcParam& param, uDDOModel* pOrigin, MtTypedArray<cEfcHandle>* pEffects);
    void setTypeEffect(rEffectProvider* pEPV, s32 indexNo, u32 effectType, const EfcParam& param, uDDOModel* pOrigin, MtTypedArray<cEfcHandle>* pEffects);
    uEffect2DExt* setEffect2D(rEffect2D* pResource, uDDOModel* pActor, u32 material, u32 custom, MOVE_LINE MoveLine);
    uEffectExt* setEffectConst(rEffectList* pResource, uDDOModel* pParent, uDDOModel* pActor, u32 group, u32 material, u32 custom, MOVE_LINE MoveLine);
    void setEffectConstParam(uEffectExt* pEffectUnit, uDDOModel* pParent, u32 rotType, s32 jointNo, const MtVector3& ofsPos, const MtVector3& ofsDir, u32 AxisType, u32 Order, bool isRotConst);
    uEffectExt* setEffectStayQuat(rEffectList* pResource, uDDOModel* pParent, const MtQuaternion& Quat, const MtVector3& Pos, uDDOModel* pActor, u32 group, u32 material, u32 custom, MOVE_LINE MoveLine);
    uEffectExt* setEffectStayDir(rEffectList* pResource, uDDOModel* pParent, const MtVector3& Dir, const MtVector3& Pos, u32 AxisType, u32 Order, uDDOModel* pActor, u32 group, u32 material, u32 custom, MOVE_LINE MoveLine);
    uEfCam* setCameraEffect(rEffectList* pResource, u32 custom, MOVE_LINE MoveLine);
    void setMotSyncParam(uEffectExt* pEffectUnit, const EfcParam& param);
    void setDeadEffect(uDDOModel* pDie, MtTypedArray<cEfcHandle>* pEffects);
    void setDamageEffect(const cDamageEffInfo* const dei);
    void setArrowEffect(uDDOModel* pDmg, EfcParam& paramOrg);
    void requestVisibleArrow(uDDOModel* pModel, bool isVisible);
    void setFootSmokeEffect(uDDOModel* pParent, u32 jointId, MtTypedArray<cEfcHandle>* pEffects);
    bool setWaterRippleEffect(uDDOModel* pParent, const MtVector3& pos, f32 heightMin, f32 heightMax, bool runFlag);
    void setWaterSplashEffect(uDDOModel* pParent, const MtVector3& pos, MtTypedArray<cEfcHandle>* pEffects);
    void setScrEffect(rEffectProvider* pResource, MtVector3& pos, s32 indexNo, MtTypedArray<cEfcHandle>* pEffects);
    void setEventEffect(rEffectProvider* pResource, u32 eventNo, uDDOModel* pParent, MtTypedArray<cEfcHandle>* pEffects);
    void setEnchantEffect(uDDOModel* pUsePlayer, uDDOModel* pTargetWeapon, u32 elemType, bool isSub, MtTypedArray<cEfcHandle>* pEffects);
    void setEnchantEffect(uDDOModel* pUsePlayer, u32 elemType, bool isSub, u32 jointNo, MtTypedArray<cEfcHandle>* pEffects);
    void setEnchantEffect(uDDOModel* pUsePlayer, EfcParam& pEfcParam, u32 elemType, bool isSub, MtTypedArray<cEfcHandle>* pEffects);
    void setWeaponWaterSplashEffect(uDDOModel* pParent, const MtVector3& pos);
    void setWeaponAfterImageEffect(uDDOModel* pParent, uDDOModel* pWeapon, s32 jointNo, u32 elemType, MtTypedArray<cEfcHandle>* pEffects);
    void setTouchDownSmokeEffect(uDDOModel* pParent);
    void setSequenceGeneralEffect(uDDOModel* pParent, u32 skillId, u32 efcType, MtTypedArray<cEfcHandle>* pEffects);
    void setErosionPartsEffect(uDDOModel* pParent, u32 PartsNo, bool isBreak, MtTypedArray<cEfcHandle>* pEffects);
    void setErosionPartsBreakEffect(uDDOModel* pParent, u32 PartsNo, MtTypedArray<cEfcHandle>* pEffects);
    void setErosionPartsRegenerateEffect(uDDOModel* pParent, u32 PartsNo, MtTypedArray<cEfcHandle>* pEffects);
    s32 getErosionScalesEpvIndex(rEffectProvider* pEpv);
    s32 getErosionSuperCameraEpvIndex(rEffectProvider* pEpv);
    cEfcHandle* setCommonEffect(s32 IndexNo, s32 ElementNo, const EfcParam& param, uDDOModel* pOrigin, u32 comType);
    cEfcHandle* setE2DEffect(rEffectProvider* pEPV, s32 IndexNo, s32 ElementNo, uDDOModel* pOrigin);
    void setOcdEffect(uDDOModel* pParent, s32 jointNo, u32 OcdUID, bool isEnd, MtTypedArray<cEfcHandle>* pEffects);
    void setOcdEffectStart(uDDOModel* pParent, s32 jointNo, u32 OcdUID, MtTypedArray<cEfcHandle>* pEffects);
    void setOcdEffectEnd(uDDOModel* pParent, s32 jointNo, u32 OcdUID, MtTypedArray<cEfcHandle>* pEffects);
    void setPartsbreakEffect(uDDOModel* pTarget, u32 PartsNo, EfcParam& pEfcParam, MtTypedArray<cEfcHandle>* pEffects);
    void setPartsrevivalEffect(uDDOModel* pTarget, u32 PartsNo, EfcParam& pEfcParam, MtTypedArray<cEfcHandle>* pEffects);
    void setAlwaysEffect(uDDOModel* pParent, EfcParam& pEfcParam, MtTypedArray<cEfcHandle>* pEffects);
    void setInheritanceTypeEffect(uDDOModel* pTarget, u32 EffectType, EfcParam& pEfcParam, MtTypedArray<cEfcHandle>* pEffects);
    u32 converterElemTypeMateGrpe(u32 attr, bool isTo);
    u32 convertElementTypeToEpvMaterialGroup(u32 elemType);
    u32 convertEpvMaterialGroupToElementType(u32 mateGrp);
    u32 getUnitNum();
    void getEffect(cEfcHandle* pHandle, MtTypedArray<uEffectExt>* pArray);
    void getEffect2D(cEfcHandle* pHandle, MtTypedArray<uEffect2DExt>* pArray);
    void getCameraEffect(cEfcHandle* pHandle, MtTypedArray<uEfCam>* pArray);
    uEffectExt* getEffectUnit(cEfcHandle* pHandle, u32 no);
    uEffect2DExt* getEffect2DUnit(cEfcHandle* pHandle, u32 no);
    uEfCam* getCameraEffectUnit(cEfcHandle*, u32);
    void endEffect(cEfcHandle* pHandle, u32 endType);
    void endEffect(MtTypedArray<cEfcHandle>* pEffects, u32 endType);
    void endEventEffect();
    void endEventEffect(u32 eventNo, u32 endType, uDDOModel* pParent);
    void finishEventEffect(u32, uDDOModel*);
    void killEventEffect(u32, uDDOModel*);
    void removeEffectAll();
    void setRemoveEffectBeforeEvent();
    bool isInvalidHandle(cEfcHandle* pHandle);
    bool updateEffectHandlePtr(cEfcHandle* * ppHandle);
    void updateEffectHandlePtrArray(MtTypedArray<cEfcHandle>* pArray);
    void setHandleOwner(cEfcHandle* pHandle, cUnit* pOwner);
    void setHandleOwner(MtTypedArray<cEfcHandle>* pEffects, cUnit* pOwner);
    void createCommonResource();
    void releaseCommonResource();
    rEffectProvider* getCommonEPV(u32 Type) const;
    u32 getCommonEPVNum() const;
    void setCommonEPVNum(u32) const;
    void createStatusAilmentsTexture();
    void releaseStatusAilmentsTexture();
    cStatusAilmentsTexture* getStatusAilmentsTextureData(u32 ailments);
    cStatusAilmentsTexture* getNoneTextureData();
    cStatusAilmentsTexture* getFireTextureData();
    cStatusAilmentsTexture* getFreezeTextureData();
    cStatusAilmentsTexture* getGeneralTextureData();
    cStatusAilmentsTexture* getOilWetTextureData();
    cStatusAilmentsTexture* getStoneTextureData();
    cStatusAilmentsTexture* getGoldTextureData();
    const rTexture* getFireAlbedoMap();
    const rTexture* getFireNormalMap();
    const rTexture* getFireSpecularMap();
    const rTexture* getFreezeAlbedoMap();
    const rTexture* getFreezeNormalMap();
    const rTexture* getFreezeSpecularMap();
    const rTexture* getGeneralAlbedoMap();
    const rTexture* getGeneralNormalMap();
    const rTexture* getGeneralSpecularMap();
    const rTexture* getOilWetAlbedoMap();
    const rTexture* getOilWetNormalMap();
    const rTexture* getOilWetSpecularMap();
    const rTexture* getStoneAlbedoMap();
    const rTexture* getStoneNormalMap();
    const rTexture* getStoneSpecularMap();
    const rTexture* getGoldAlbedoMap();
    const rTexture* getGoldNormalMap();
    const rTexture* getGoldSpecularMap();
    void setFireAlbedoMap(rTexture*);
    void setFireNormalMap(rTexture*);
    void setFireSpecularMap(rTexture*);
    void setFreezeAlbedoMap(rTexture*);
    void setFreezeNormalMap(rTexture*);
    void setFreezeSpecularMap(rTexture*);
    void setGeneralAlbedoMap(rTexture*);
    void setGeneralNormalMap(rTexture*);
    void setGeneralSpecularMap(rTexture*);
    void setOilWetAlbedoMap(rTexture*);
    void setOilWetNormalMap(rTexture*);
    void setOilWetSpecularMap(rTexture*);
    void setStoneAlbedoMap(rTexture*);
    void setStoneNormalMap(rTexture*);
    void setStoneSpecularMap(rTexture*);
    void setGoldAlbedoMap(rTexture*);
    void setGoldNormalMap(rTexture*);
    void setGoldSpecularMap(rTexture*);
    s32 addEfcZone(rZone* pZone, u32 type, const MtVector3& pos);
    void releaseEfcZone(u32 handle, u32 type);
    void releaseEfcZoneAll();
    cZoneMultiStack* getEfcZoneStack(u32 type);
    void addZoneEffectProvider(rEffectProvider* pEpv, u32 handle);
    void eraseZoneEffectProvider(u32 handle);
    rEffectProvider* getZoneEffectProvider(u32 handle);
    void updateZoneEffectUnit();
    bool getZoneCheckPos(MtVector3& ckPos);
    bool updateColorUpdateCount();
    u32 getEffectAttributeBit(sCollision::TriangleInfo* pTriangle);
    u32 getCancelEfcAtrBit(u32 MaterialFlag, uDDOModel* pParent, rEffectProvider::EffectParam* pEfcParam, sCollision::TriangleInfo* pTriangle, bool isLandCheck);
    u32 getEnchantAttributeBit(uDDOModel* pParent);
    const cOutlineParam* getOutlineParam(OUTLINE no);
    void epvSetTimer(cEfcHandle* pHandle, u32 timer);
    void epvSetTimer2D(cEfcHandle*, u32);
    void epvSetTransparency(cEfcHandle* pHandle, f32 rate);
    void epvSetPos(cEfcHandle* pHandle, const MtVector3& pos);
    void epvSetOfs(cEfcHandle*, const MtVector3&);
    void epvSetScale(cEfcHandle* pHandle, const MtVector3& scale);
    void epvSetColor(cEfcHandle*, const MtColor&);
    void epvSetAngle(cEfcHandle*, const MtVector3&);
    void epvSetDir(cEfcHandle*, const MtVector3&);
    void epvSetWorkRateType(cEfcHandle*, u32);
    void epvSetDraw(cEfcHandle*, bool);
    MtVector3 epvGetPos(cEfcHandle* pHandle);
    MtVector3 epvGetScale(cEfcHandle*);
    MtVector3 epvGetAngle(cEfcHandle*);
    void epvSetPos2D(cEfcHandle*, const MtVector3&);
    void epvSetConstUpdteMode(cEfcHandle*, bool);
    void epvSetTransparencyAll(cEfcHandle* pHandle, f32 rate);
    void setTimeFilter(u32 src);
    u32 getTimeFilter() const;
    bool isRevisionCorrectType(u32 CorrectType);
    rEffectProvider* getEpvResourceFromDDOModel(uDDOModel* pModel, u32 type);
    rEffectProvider* getEpvResourceFromWeaponCategory(u32 wepCategory);
private:
    void removeEffect(uEffectExt* pue);
    void removeEffect2D(uEffect2DExt* pue);
    void removeCameraEffect(uEfCam* pue);
    uEffectExt* getEffect(cEfcHandle* pHandle, u32 no);
    uEffect2DExt* getEffect2D(cEfcHandle* pHandle, u32 no);
    uEfCam* getCameraEffect(cEfcHandle* pHandle, u32 no);
    cEfcHandle* addEffectUnit(const MtTypedArray<uEffectExt>& Array);
    cEfcHandle* addEffect2DUnit(const MtTypedArray<uEffect2DExt>& Array);
    cEfcHandle* addCameraEffectUnit(const MtTypedArray<uEffectExt>& Array);
    void removeEffect(cEfcHandle* pHandle, u32 no, u32 endType);
    void removeEffect2D(cEfcHandle* pHandle, u32 no, u32 endType);
    void removeCameraEffect(cEfcHandle* pHandle, u32 no, u32 endType);
    void removeEffect(cEfcHandle* pHandle, u32 endType);
    void removeEffect2D(cEfcHandle* pHandle, u32 endType);
    void removeCameraEffect(cEfcHandle* pHandle, u32 endType);
    void updateEffectUnitList();
    void updateEffect2DUnitList();
    void updateEfCamUnitList();
    void updateParentPtr();
    void removeEffectBeforeEvent();
    void addInvalidHandle(cEfcHandle* pHandle);
    void removeInvalidHandle(cEfcHandle* pHandle);
    void removeInvalidHandle(bool owner_check);
    void updateInvalidHandle();
    void addEventEffectHandle(cEfcHandle* pHandle);
    void removeEventEffectHandle(cEfcHandle* pHandle);
    void clearEventEffectHandle();
    cEfcHandle* getEventEffectHandle(u32 eventNo, uDDOModel* pParent);
    void setCommonEPV(rEffectProvider* resource, u32 Type);
    void createCommonEPV();
    void releaseCommonEPV();
    void resetColorUpdateCount();
    void createCommonELI();
    void releaseCommonELI();
    void setCommonELI(rVfxLightInfluence* pr);
    rVfxLightInfluence* getCommonELI();
    u32 getGroundInfo(sCollision::TriangleInfo* pInfo, const MtVector3& pos, f32 len, bool enableOM);
    MtVector3 getParentPos(u32 posType, s32 jointNo, uDDOModel* pParent);
    MtQuaternion getParentQuat(u32 rotType, s32 jointNo, uDDOModel* pParent);
    MtQuaternion calcQuat(const MtVector3& Angle, const MtQuaternion& Quat, u32 Order);
    cEfcHandle* setEflEffectEPV(rEffectProvider::EffectElement* pEfcElement, const MtVector3& camPos, const EfcParam& param, uDDOModel* pOrigin);
    cEfcHandle* setE2dEffectEPV(rEffectProvider::EffectElement* pEfcElement, const MtVector3& camPos, const EfcParam& param, uDDOModel* pOrigin);
    void setEflEffectEPVSetupCustomFlag(u32 SetType, uEffectExt* pDst, u32 customFlag, u32 relationFlag);
public:
    bool isEffectTypeDamage(u32 effectType);
    cEfcCameraQuakeData getCameraQuakeParam(u32 type);
    void setBoundaryDistance(uEffectExt* target);
    void addCreateCost(u32 Cost);
    void subCreateCost(u32 Cost);
    u32 getNowCost();
    u32 getLimitCost() const;
    void setLimitCost(u32 NewLimitCost);
    void processReduceFunc();
    uEffectExt* getAbstractEffect(uEffectExt* AbstractUnit, MOVE_LINE ml, bool farFlag);
    void processReduceStop();
    void processReduceBack();
    bool canSetEffect(rEffectProvider::EffectParam* pEfcParam, uDDOModel* pParent, uDDOModel* pOrigin);
    bool canSetEffect(u32 CustomFlag, u32 CreateCost, uDDOModel* pParent, uDDOModel* pOrigin);
private:
    s32 getJointNo_setEffect(const EfcParam& ProgEfcParam, const rEffectProvider::EffectParam* ResEfcParam);
    u32 getAxis_setEffect(const EfcParam& ProgEfcParam, const rEffectProvider::EffectParam* ResEfcParam);
    u32 getOrder_setEffect(const EfcParam& ProgEfcParam, const rEffectProvider::EffectParam* ResEfcParam);
    MtVector3 getOfsPos_setEffect(const EfcParam& ProgEfcParam, const rEffectProvider::EffectParam* ResEfcParam, u32 SetType);
    MtVector3 getOfsDir_setEffect(const EfcParam& ProgEfcParam, const rEffectProvider::EffectParam* ResEfcParam, u32 SetType, u32 AxisType);
    f32 getCharaEditHeightScale_setEffect(u32 EffectType, u32 SetType, u32 RelationType, uDDOModel* pParent);
    MtVector3 getScale_setEffect(u32 SetType, u32 RelationType, const EfcParam& ProgEfcParam, const rEffectProvider::EffectParam* ResEfcParam, const uDDOModel* pParent);
    bool getIsOfsScale_setEffect(u32 SetType, u32 RelationType, u32 EfcType);
    u32 getLoopFrame_setEffect(const EfcParam& ProgEfcParam, const rEffectProvider::EffectParam* ResEfcParam);
    f32 getCameraDistance_setEffect(const MtVector3& OfsPos, const MtVector3& CameraPos, uDDOModel* pParent);
    bool getIsDrawIsMyPlayerSys_setEffect(uDDOModel* pParent, uDDOModel* pOrigin);
    bool getIsDrawIsMyPlayerSys_setEffect_Sub(uDDOModel* pCheckModel);
    bool getIsDrawIsMyPlayer_setEffect(u32 CustomFlag, u32 EffectDependerKind);
    u32 getEffectDependerKind_setEffect(u32 CustomFlag, uDDOModel* pParent, uDDOModel* pOrigin);
    u32 getEffectDependerKind_setEffect_Sub(uDDOModel* pCheckModel);
    u32 getEnchantMaterial_setEffect(u32 MaterialFlag, uDDOModel* pParent);
    u32 getEventOffFlag_setEffect(u32 OptionFlag);
    bool getCanSetEffect_setEffect(u32 SetType, const uDDOModel* pParent);
    MtVector3 getSetEffectPos_setEffect(u32 SetType, uDDOModel* pParent, u32 PosType, u32 JointNo, MtVector3& OfsPos);
    MtQuaternion getSetEffectQuat_setEffect(u32 SetType, uDDOModel* pParent, u32 RotType, u32 JointNo);
    void getGroundInfoPos_setEffect(MtVector3* Pos, u32 SetType, MtVector3& OfsPos, u32 OptionFlag, MtQuaternion& Quat);
    void getGroundHitInfoPos_setEffect(MtVector3* Pos, u32 SetType, u32 HitFlag, bool LandSetEnable, const sCollision::TriangleInfo* Triangle, const uDDOModel* pParent);
    void getGroundHitInfoMaterial_setEffect(u32* MaterialFlag, u32 HitFlag, u32 SetType, sCollision::TriangleInfo* Triangle);
    void getGroundHitInfoTilt_setEffect(MtQuaternion* Quat, MtVector3* Dir, u32 SetType, bool LandDirEnable, u32 HitFlag, u32 AxisType, sCollision::TriangleInfo* Triangle);
    void getDrawRotate_setEffect(MtQuaternion* Quat, MtVector3* Dir, u32 SetType, u32 AxisType, u32 Order, MtVector3& OfsDir);
    uEffectExt* setEffectSubstance_setEffect(u32 SetType, uDDOModel* pParent, rEffectList* pResource, uDDOModel* pOrigin, MtQuaternion& Quat, MtVector3& Dir, MtVector3& Pos, u32 AxisType, u32 Order, u32 GroupFlag, u32 MaterialFlag, u32 CustomFlag, MOVE_LINE MoveLine);
    void setEffectParam_setEffect(u32 SetType, uEffectExt* pUnit, uDDOModel* pParent, u32 RotType, u32 JointNo, MtVector3& OfsPos, MtVector3& OfsDir, u32 AxisType, u32 Order, bool isRotConst);
    void setEffectParamAfter_setEffect(u32 SetType, uEffectExt* pUnit, rEffectProvider::EffectParam* ResEfcParam, MtVector3& EfcScale, u32 LoopFrame, u32 CustomFlag, u32 relationFlag, bool IsQuakeCancel, u32 OptionFlag, u32 EffectDependerKind, const EfcParam& pEfcParam);
    void setCalcCostToUnit(MtTypedArray<uEffectExt> tmpArray, u32 CreateCost);
    void setCalcCostToUnit(MtTypedArray<uEffect2DExt> tmpArray, u32 CreateCost);
    u32 setCalcCostToUnitSub(u32 UnitNum, u32 CreateCost);
    void setFinishFadeOutFrameToUnit(MtTypedArray<uEffectExt> tmpArray, f32 FinishFadeOutFrame);
    bool isAllGeneratorCantMove(rEffectList* pEfl, u32 GroupFlag, u32 MaterialFlag);
    s32 getHardwareDispDivideFlag();
    bool isShadowCastEffect(rEffectList* pEfl);
    MtVector3 calcGroundHitTiltLimit(MtVector3& Normal);
    void setSubPositionTgtGene(uEffectExt* pTargetUnit, MtVector3& setPos, u32 TargetGeneIdx);
public:
    void setSubPositionAllGene(cEfcHandle* pTargetHandle, MtVector3& setPos);
    void setSubPositionTgtGene(cEfcHandle* pTargetHandle, MtVector3& setPos, u32 TargetGeneIdx);
    void setOthersTransparencyPercentage(f32 set);
    void setOthersTransparencyPercentage(OPTION_OTHERS_EFC_TYPE type);
    f32 getOthersTransparencyPercentage();
    f32 convertOptionOthresTranspacencyPercentage(OPTION_OTHERS_EFC_TYPE type);
    void setRestrainIntensityParcentage(f32);
    f32 getRestrainIntensityRate();
    void onDispCtrlFlag(u32 onFlag, MtTypedArray<cEfcHandle>* pEffects);
    void offDispCtrlFlag(u32 offFlag, MtTypedArray<cEfcHandle>* pEffects);
    f32 getSuperErosionDispOffDistance();
    void addOnceRequestEffectTypeSuperErosionCamData(MtTypedArray<cEfcHandle>* pEffects, uEnemy* pEnemy);
    void relOnceRequestEffectTypeSuperErosionCamData(MtTypedArray<cEfcHandle>* pEffects, uEnemy* pEnemy);
    bool isDrawOnceRequestEffectTypeSuperErosionCamData(uEffectExt* pEffect);
private:
    bool mbHitWorld;  // offset: 0x401
    rEffectProvider* mpCommonEPV[1];  // offset: 0x408
    cStatusAilmentsTexture mStatusAilmentsTexture[8];  // offset: 0x410
    u32 mArrowHandleId;  // offset: 0x4d0
    cEfcHandle* mpArrowEffectHandle[16];  // offset: 0x4d8
    u32 mTimeFilter;  // offset: 0x558
    MtVector3 mZoneCheckPos;  // offset: 0x560
    bool mUseZoneCheckPos;  // offset: 0x570
    MtTypedArray<cZoneEpvStack> mZoneEpvArray;  // offset: 0x578
    cZoneMultiStack mZoneStack[3];  // offset: 0x598
    MtTypedArray<cZoneEffectUnitLayout> mZoneEffectUnitLayoutArray;  // offset: 0x628
    cZoneListenerEffectEFL mEFLZoneListner;  // offset: 0x650
    u32 mColorUpdateCount;  // offset: 0x7a0
    f32 mCustomIntensityScale;  // offset: 0x7a4
    rOutlineParamList* mprOutlineParamList;  // offset: 0x7a8
    bool mRemoveEffectBeforeEventFlag;  // offset: 0x7b0
public:
    u64 mCount;  // offset: 0x7b8
    u64 mGroupCount;  // offset: 0x7c0
private:
    uEffectExt* mpEffect;  // offset: 0x7c8
    uEffect2DExt* mpEffect2D;  // offset: 0x7d0
    uEffectExt* mpCameraEffect;  // offset: 0x7d8
    u32 mUnitCount;  // offset: 0x7e0
    cEfcHandle* mpInvalidHandle;  // offset: 0x7e8
    cEfcHandle* mpEventEffectHandle;  // offset: 0x7f0
    rVfxLightInfluence* mpCommonELI;  // offset: 0x7f8
    cEfcCameraQuakeData mECQ_N;  // offset: 0x800
    cEfcCameraQuakeDataLarge mECQ_L;  // offset: 0x860
    cEfcCameraQuakeDataMiddle mECQ_M;  // offset: 0x8c0
    cEfcCameraQuakeDataSmall mECQ_S;  // offset: 0x920
    f32 DDO_EFFECT_EXT_BOUNDARY_DISTANCE;  // offset: 0x980
    u32 mLimitCost;  // offset: 0x984
    u32 mNowCost;  // offset: 0x988
public:
    f32 EFFECT_PROCESS_REDUSE_LIMIT_RFPS;  // offset: 0x98c
    f32 EFFECT_PROCESS_REDUSE_UNDER_RFPS;  // offset: 0x990
    f32 EFFECT_PROCESS_REDUSE_JUDGE_INTERVAL;  // offset: 0x994
    f32 EFFECT_PROCESS_PROGRESS_FRAME;  // offset: 0x998
    f32 mProcessReduseCount;  // offset: 0x99c
    bool mNoProcessReduceFlag;  // offset: 0x9a0
    cEfcHandle* mpProcReduceEffectHandle[16];  // offset: 0x9a8
private:
    bool mIsGroundHitTiltLimitEnable;  // offset: 0xa28
    u32 mGroundHitTiltLimit;  // offset: 0xa2c
    f32 mOthersTransparencyPercentage;  // offset: 0xa30
    f32 mRestrainIntensityParcentage;  // offset: 0xa34
    f32 mSuperErosionDispOffDistance;  // offset: 0xa38
    cOnceRequestEffectTypeSuperErosionCam mCRETSEC;  // offset: 0xa40
public:
    static MyDTI DTI;
private:
    static const u32 ARROW_EFFECT_MAX = 16;
    static const u32 ZONE_LAYOUT_MAX = 256;
    static const u32 COLOR_UPDATE_COUNT_MAX = 8;
    static const f32 DEFAULT_CUSTOM_INTENSITY_SCALE;
public:
    static const u64 InvalidID = 18446744073709551615u;
    static const u64 StartID = 1;
    static const u32 UnitMax = 512;
    static const u32 EPV_TYPE_OVERRIDE_NUM = 4;
    static const u32 EPV_TYPE_OVERRIDE_TBL[4];
    static const u32 PS3_EFFECT_LIMIT_COST;
    static const u32 PS4_EFFECT_LIMIT_COST;
    static const u32 PC_EFFECT_LIMIT_COST;
    static const u32 PROC_REDUCE_OFF_MAX = 16;
private:
    static const u32 GROUND_HIT_TILT_LIMIT = 45;
};

// Inline, no code of its own: checked where it is inlined.
inline cVfxLightInfluence::cVfxLightInfluence() {
    this->mCustom4 = 0.0f;
    this->mCustom6 = 0.0f;
    this->mCustom2 = 0.0f;
    this->mCustom3 = 0.0f;
    this->mLightIntensity = 0.0f;
    this->mCustom1 = 0.0f;
    this->mEnv1 = 1.0f;
    this->mEnv2 = 1.0f;
}
