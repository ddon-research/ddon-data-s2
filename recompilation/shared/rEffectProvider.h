#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cResource.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtStream;
class MtVector3;
class rEffect2D;
class rEffectList;

// Declarations
class rEffectProvider;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cWeatherFlag = nDDOUtility::cBitSet<32>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rEffectProvider : public cResource
{
public:
    enum EFC_SET_TYPE
    {
        EFC_SET_TYPE_CONST = 0,
        EFC_SET_TYPE_STAY = 1,
        EFC_SET_TYPE_WORLD = 2,
        EFC_SET_TYPE_CAMERA = 3,
        EFC_SET_TYPE_MAX = 4,
    };
    enum EFC_END_TYPE
    {
        EFC_END_TYPE_LEAVE = 0,
        EFC_END_TYPE_FINISH = 1,
        EFC_END_TYPE_KILL = 2,
        EFC_END_TYPE_MAX = 3,
    };
    enum E2D_TYPE
    {
        E2D_TYPE_NONE = 0,
        E2D_TYPE_HITOMI_BODY = 1,
        E2D_TYPE_HITOMI_EYE = 2,
        E2D_TYPE_PL_BLIND = 3,
        E2D_TYPE_ULDRAGON = 4,
        E2D_TYPE_NUM = 5,
    };
    enum PARENT_NO
    {
        PARENT00 = 0,
        PARENT_MAX = 1,
    };
    enum POS_TYPE
    {
        POS_TYPE_JOINT = 0,
        POS_TYPE_NULL = 1,
        POS_TYPE_MAX = 2,
    };
    enum ROT_TYPE
    {
        ROT_TYPE_JOINT = 0,
        ROT_TYPE_NULL = 1,
        ROT_TYPE_MAX = 2,
    };
    enum DEFAULT_COLOR_MODE
    {
        DC_MODE_OVERRIDE = 0,
        DC_MODE_ADD = 1,
        DC_MODE_MAX = 2,
    };
    enum EFC_LIST_NO
    {
        EFC_LIST_00 = 0,
        EFC_LIST_01 = 1,
        EFC_LIST_02 = 2,
        EFC_LIST_03 = 3,
        EFC_LIST_04 = 4,
        EFC_LIST_05 = 5,
        EFC_LIST_06 = 6,
        EFC_LIST_07 = 7,
        EFC_LIST_MAX = 8,
    };
    enum EFC_2D_NO
    {
        EFC_2D_00 = 0,
        EFC_2D_MAX = 1,
    };
    enum EFC_TYPE
    {
        EFC_TYPE_DEFAULT = 0,
        EFC_TYPE_MOTION = 1,
        EFC_TYPE_DAMAGE_NIKU_SLASH = 2,
        EFC_TYPE_DAMAGE_NIKU_BLOW = 3,
        EFC_TYPE_DAMAGE_NIKU_SHOT = 4,
        EFC_TYPE_DAMAGE_HAHEN_SLASH = 5,
        EFC_TYPE_DAMAGE_HAHEN_BLOW = 6,
        EFC_TYPE_DAMAGE_HAHEN_SHOT = 7,
        EFC_TYPE_WEAK_DAMAGE_1st_SLASH = 8,
        EFC_TYPE_WEAK_DAMAGE_1st_BLOW = 9,
        EFC_TYPE_WEAK_DAMAGE_1st_SHOT = 10,
        EFC_TYPE_WEAK_DAMAGE_2nd_SLASH = 11,
        EFC_TYPE_WEAK_DAMAGE_2nd_BLOW = 12,
        EFC_TYPE_WEAK_DAMAGE_2nd_SHOT = 13,
        EFC_TYPE_DEAD = 14,
        EFC_TYPE_FOOT_SMOKE_FR = 15,
        EFC_TYPE_ALWAYS = 16,
        EFC_TYPE_BREAK = 17,
        EFC_TYPE_WEAPON_WATER_SPLASH = 18,
        EFC_TYPE_WATER_SPLASH = 19,
        EFC_TYPE_SCR = 20,
        EFC_TYPE_TOUCHDOWN = 21,
        EFC_TYPE_RIPPLE_WALK = 22,
        EFC_TYPE_RIPPLE_RUN = 23,
        EFC_TYPE_FOOT_SMOKE_FL = 24,
        EFC_TYPE_FOOT_SMOKE_BR = 25,
        EFC_TYPE_FOOT_SMOKE_BL = 26,
        EFC_TYPE_EVENT = 27,
        EFC_TYPE_DAMAGE_WATER_SLASH = 28,
        EFC_TYPE_DAMAGE_WATER_BLOW = 29,
        EFC_TYPE_DAMAGE_WATER_SHOT = 30,
        EFC_TYPE_DAMAGE_ALCHEMY_SLASH = 31,
        EFC_TYPE_DAMAGE_ALCHEMY_BLOW = 32,
        EFC_TYPE_DAMAGE_ALCHEMY_SHOT = 33,
        EFC_TYPE_DAMAGE_ELEMENT = 34,
        EFC_TYPE_ST_AILMENT_ELEM_START = 35,
        EFC_TYPE_DAMAGE_DOWN = 36,
        EFC_TYPE_WEAK_DAMAGE_3rd_SLASH = 37,
        EFC_TYPE_WEAK_DAMAGE_3rd_BLOW = 38,
        EFC_TYPE_WEAK_DAMAGE_3rd_SHOT = 39,
        EFC_TYPE_ST_AILMENT_ELEM_END = 40,
        EFC_TYPE_ST_AILMENT_FAINT_START = 41,
        EFC_TYPE_ST_AILMENT_FAINT_END = 42,
        EFC_TYPE_ST_AILMENT_SLEEP_START = 43,
        EFC_TYPE_ST_AILMENT_SLEEP_END = 44,
        EFC_TYPE_ST_AILMENT_STONE_START = 45,
        EFC_TYPE_ST_AILMENT_STONE_END = 46,
        EFC_TYPE_ST_AILMENT_GOLD_START = 47,
        EFC_TYPE_ST_AILMENT_GOLD_END = 48,
        EFC_TYPE_DAMAGE_VAPOUR_SLASH = 49,
        EFC_TYPE_DAMAGE_VAPOUR_BLOW = 50,
        EFC_TYPE_DAMAGE_VAPOUR_SHOT = 51,
        EFC_TYPE_SEQUENCE7_GENELAL1 = 52,
        EFC_TYPE_SEQUENCE8_GENELAL2 = 53,
        EFC_TYPE_DAMAGE_FREEZE = 54,
        EFC_TYPE_DAMAGE_EROSION_SLASH = 55,
        EFC_TYPE_DAMAGE_EROSION_BLOW = 56,
        EFC_TYPE_DAMAGE_EROSION_SHOT = 57,
        EFC_TYPE_ST_AILMENT_EROSION_1lv_START = 58,
        EFC_TYPE_ST_AILMENT_EROSION_1lv_END = 59,
        EFC_TYPE_ST_AILMENT_EROSION_2lv_START = 60,
        EFC_TYPE_ST_AILMENT_EROSION_2lv_END = 61,
        EFC_TYPE_ST_AILMENT_EROSION_3lv_START = 62,
        EFC_TYPE_ST_AILMENT_EROSION_3lv_END = 63,
        EFC_TYPE_ST_AILMENT_EROSION_4lv_START = 64,
        EFC_TYPE_ST_AILMENT_EROSION_4lv_END = 65,
        EFC_TYPE_BREAK_EROSION_1 = 66,
        EFC_TYPE_BREAK_EROSION_2 = 67,
        EFC_TYPE_BREAK_EROSION_3 = 68,
        EFC_TYPE_BREAK_EROSION_4 = 69,
        EFC_TYPE_REGENERATE_EROSION_1 = 70,
        EFC_TYPE_REGENERATE_EROSION_2 = 71,
        EFC_TYPE_REGENERATE_EROSION_3 = 72,
        EFC_TYPE_REGENERATE_EROSION_4 = 73,
        EFC_TYPE_SCALES_EROSION = 74,
        EFC_TYPE_PARTS_BREAK1 = 75,
        EFC_TYPE_PARTS_BREAK2 = 76,
        EFC_TYPE_PARTS_BREAK3 = 77,
        EFC_TYPE_PARTS_BREAK4 = 78,
        EFC_TYPE_PARTS_BREAK5 = 79,
        EFC_TYPE_PARTS_BREAK6 = 80,
        EFC_TYPE_PARTS_BREAK7 = 81,
        EFC_TYPE_PARTS_BREAK8 = 82,
        EFC_TYPE_PARTS_BREAK9 = 83,
        EFC_TYPE_PARTS_REVIVAL1 = 84,
        EFC_TYPE_PARTS_REVIVAL2 = 85,
        EFC_TYPE_PARTS_REVIVAL3 = 86,
        EFC_TYPE_PARTS_REVIVAL4 = 87,
        EFC_TYPE_PARTS_REVIVAL5 = 88,
        EFC_TYPE_PARTS_REVIVAL6 = 89,
        EFC_TYPE_PARTS_REVIVAL7 = 90,
        EFC_TYPE_PARTS_REVIVAL8 = 91,
        EFC_TYPE_PARTS_REVIVAL9 = 92,
        EFC_TYPE_SUPER_EROSION_CAM = 93,
        EFC_TYPE_SUPER_EROSION_PARTS1_DEFAULT = 94,
        EFC_TYPE_SUPER_EROSION_PARTS2_DEFAULT = 95,
        EFC_TYPE_SUPER_EROSION_PARTS3_DEFAULT = 96,
        EFC_TYPE_SUPER_EROSION_PARTS4_DEFAULT = 97,
        EFC_TYPE_SUPER_EROSION_PARTS1_LEVEL = 98,
        EFC_TYPE_SUPER_EROSION_PARTS2_LEVEL = 99,
        EFC_TYPE_SUPER_EROSION_PARTS3_LEVEL = 100,
        EFC_TYPE_SUPER_EROSION_PARTS4_LEVEL = 101,
        EFC_TYPE_SUPER_EROSION_PARTS1_COREPOINT = 102,
        EFC_TYPE_SUPER_EROSION_PARTS2_COREPOINT = 103,
        EFC_TYPE_SUPER_EROSION_PARTS3_COREPOINT = 104,
        EFC_TYPE_SUPER_EROSION_PARTS4_COREPOINT = 105,
        EFC_TYPE_SUPER_EROSION_PARTS1_HORN = 106,
        EFC_TYPE_SUPER_EROSION_PARTS2_HORN = 107,
        EFC_TYPE_SUPER_EROSION_PARTS3_HORN = 108,
        EFC_TYPE_SUPER_EROSION_PARTS4_HORN = 109,
        EFC_TYPE_MAX = 110,
    };
    enum EFC_RESOURCE_TYPE
    {
        EFC_RESOURCE_TYPE_EFL = 0,
        EFC_RESOURCE_TYPE_E2D = 1,
        EFC_RESOURCE_TYPE_MAX = 2,
    };
    enum EFC_PARENT_RELATION_FLAG
    {
        EFC_PRF_POS = 1,
        EFC_PRF_SCALE = 2,
        EFC_PRF_ROT = 4,
        EFC_PRF_OFFSET = 8,
        EFC_PRF_SPEED = 16,
        EFC_PRF_ALPHA = 32,
        EFC_PRF_DRAW_DEFAULT = 64,
        EFC_PRF_END = -2147483648,
    };
    enum EFC_MATERIAL_GROUP
    {
        EFC_MATERIAL_GROUP_DEFAULT = 1,
        EFC_MATERIAL_GROUP_WATER = 2,
        EFC_MATERIAL_GROUP_AIR = 524288,
        EFC_MATERIAL_GROUP_EN_NONE = 1048576,
        EFC_MATERIAL_GROUP_EN_FIRE = 2097152,
        EFC_MATERIAL_GROUP_EN_ICE = 4194304,
        EFC_MATERIAL_GROUP_EN_THUNDER = 8388608,
        EFC_MATERIAL_GROUP_EN_HOLY = 16777216,
        EFC_MATERIAL_GROUP_EN_DARK = 33554432,
    };
    enum EFC_GROUP_FLAG
    {
        EFC_GROUP_FLAG_0 = 1,
        EFC_GROUP_FLAG_1 = 2,
        EFC_GROUP_FLAG_2 = 4,
        EFC_GROUP_FLAG_3 = 8,
        EFC_GROUP_FLAG_4 = 16,
        EFC_GROUP_FLAG_5 = 32,
        EFC_GROUP_FLAG_6 = 64,
        EFC_GROUP_FLAG_7 = 128,
        EFC_GROUP_FLAG_8 = 256,
        EFC_GROUP_FLAG_9 = 512,
        EFC_GROUP_FLAG_10 = 1024,
        EFC_GROUP_FLAG_11 = 2048,
        EFC_GROUP_FLAG_12 = 4096,
        EFC_GROUP_FLAG_13 = 8192,
        EFC_GROUP_FLAG_14 = 16384,
        EFC_GROUP_FLAG_15 = 32768,
        EFC_GROUP_FLAG_16 = 65536,
        EFC_GROUP_FLAG_17 = 131072,
        EFC_GROUP_FLAG_18 = 262144,
        EFC_GROUP_FLAG_19 = 524288,
        EFC_GROUP_FLAG_20 = 1048576,
        EFC_GROUP_FLAG_21 = 2097152,
        EFC_GROUP_FLAG_22 = 4194304,
        EFC_GROUP_FLAG_23 = 8388608,
        EFC_GROUP_FLAG_24 = 16777216,
        EFC_GROUP_FLAG_25 = 33554432,
        EFC_GROUP_FLAG_26 = 67108864,
        EFC_GROUP_FLAG_27 = 134217728,
        EFC_GROUP_FLAG_PS3_ON = 268435456,
        EFC_GROUP_FLAG_PS4_ON = 536870912,
        EFC_GROUP_FLAG_SYS_ISMYPLAYER = 1073741824,
        EFC_GROUP_FLAG_SYS_YOBI = -2147483648,
    };
    enum EFC_E2D_CUSTOM_FLAG
    {
        EFC_E2D_CUSTOM_WORLD_POS_MODE = 1,
        EFC_E2D_CUSTOM_COLOR_UPDATE = 32,
        EFC_E2D_CUSTOM_EVENT_OFF = 1024,
        EFC_E2D_CUSTOM_SIMPLE_EVENT_OFF = 4096,
        EFC_E2D_CUSTOM_NO_PAUSE = 65536,
        EFC_E2D_CUSTOM_CAMERA_EVENT_OFF = 131072,
        EFC_E2D_CUSTOM_PS3_OFF = 4194304,
        EFC_E2D_CUSTOM_PS4_OFF = 8388608,
    };
    enum EFC_CUSTOM_FLAG
    {
        EFC_CUSTOM_FOLLOW_SUN = 2,
        EFC_CUSTOM_ZONE_GENERATOR_POS = 16,
        EFC_CUSTOM_COLOR_UPDATE = 32,
        EFC_CUSTOM_ZONE_UNIT_COLOR = 64,
        EFC_CUSTOM_ME_ONLY = 256,
        EFC_CUSTOM_LANTERN_CANCEL = 512,
        EFC_CUSTOM_EVENT_OFF = 1024,
        EFC_CUSTOM_COLOR_UPDATE_DISTANCE_CANCEL = 2048,
        EFC_CUSTOM_SIMPLE_EVENT_OFF = 4096,
        EFC_CUSTOM_NO_PAUSE = 65536,
        EFC_CUSTOM_CAMERA_EVENT_OFF = 131072,
        EFC_CUSTOM_DAY_OFF = 262144,
        EFC_CUSTOM_NIGHT_OFF = 524288,
        EFC_CUSTOM_FOLLOW_MOON = 1048576,
        EFC_CUSTOM_PS3_OFF = 4194304,
        EFC_CUSTOM_PS4_OFF = 8388608,
        EFC_CUSTOM_OTHERS_TRANS_OFF = 16777216,
        EFC_CUSTOM_ = -2147483648,
    };
    enum EFC_CAM_CUSTOM_FLAG
    {
        EFC_CAM_CUSTOM_REPEAT = 1,
        EFC_CAM_CUSTOM_Y_ANGLE = 2,
        EFC_CAM_CUSTOM_ZONE_GENERATOR_POS = 16,
        EFC_CAM_CUSTOM_COLOR_UPDATE = 32,
        EFC_CAM_CUSTOM_ZONE_UNIT_COLOR = 64,
        EFC_CAM_CUSTOM_LANTERN_CANCEL = 512,
        EFC_CAM_CUSTOM_EVENT_OFF = 1024,
        EFC_CAM_CUSTOM_COLOR_UPDATE_DISTANCE_CANCEL = 2048,
        EFC_CAM_CUSTOM_SIMPLE_EVENT_OFF = 4096,
        EFC_CAM_CUSTOM_NO_PAUSE = 65536,
        EFC_CAM_CUSTOM_CAMERA_EVENT_OFF = 131072,
        EFC_CAM_CUSTOM_PS3_OFF = 4194304,
        EFC_CAM_CUSTOM_PS4_OFF = 8388608,
    };
    enum EFC_QUAKE_TYPE
    {
        EFC_QUAKE_NONE = 0,
        EFC_QUAKE_LARGE = 1,
        EFC_QUAKE_MIDDLE = 2,
        EFC_QUAKE_SMALL = 3,
        EFC_QUAKE_MAX = 4,
    };
    enum EFC_GROUP_ID
    {
        EFC_GROUP_ID_PS3_ON = 28,
        EFC_GROUP_ID_PS4_ON = 29,
        EFC_GROUP_ID_SYS_ISMYPLAYER = 30,
        EFC_GROUP_ID_SYS_YOBI = 31,
    };
public:
    class MyDTI;
    class INFO_PROV;
    class INFO_EFFECT;
    class INFO_BASE;
    class EffectIndex;
    class EffectElement;
    class EffectParam;
    class EffectMotSyncParam;
    class EffectEventParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class INFO_BASE : public MtObject
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
        INFO_BASE();
        cResource* getNativeResource(cResource* pResource);
        virtual bool toNative(rEffectProvider::INFO_BASE* pInfo);  // vtable slot 6
        virtual bool fromNative();  // vtable slot 7
        void clear();
    public:
        static MyDTI DTI;
    };
public:
    class EffectIndex : public MtObject
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
        EffectIndex();
        virtual ~EffectIndex();
        void clear();
        rEffectProvider::EffectElement* getEffectElement(s32 index) const;
        u32 getEffectElementNum() const;
        void setEffectElement(rEffectProvider::EffectElement* pEffectElement);
        void setEffectElementNum(u32 num);
    private:
        rEffectProvider::EffectElement* mpEffectElement;  // offset: 0x8
        u32 mEffectElementNum;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class EffectParam : public MtObject
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
        EffectParam();
        virtual ~EffectParam();
        u32 getSetType() const;
        void setSetType(u32 type);
        u32 getEndType() const;
        void setEndType(u32 type);
        MtVector3 getPosition() const;
        void setPosition(const MtVector3& Position);
        MtVector3 getCamOfs() const;
        void setCamOfs(const MtVector3& CamOfs);
        MtVector3 getDirection() const;
        void setDirection(const MtVector3& Direction);
        MtVector3 getDirectionAmp() const;
        void setDirectionAmp(const MtVector3& Amp);
        u32 getGroupFlag() const;
        void setGroupFlag(u32 GroupFlag);
        u32 getMaterialFlag() const;
        void setMaterialFlag(u32 MaterialFlag);
        u32 getAxisType() const;
        void setAxisType(u32 AxisType);
        u32 getOrder() const;
        void setOrder(u32 Order);
        f32 getScale() const;
        void setScale(f32 Scale);
        f32 getScaleAmp() const;
        void setScaleAmp(f32 Amp);
        f32 getDeltaTimeCoef() const;
        void setDeltaTimeCoef(f32 coef);
        bool getIncidenceAngleEnable() const;
        void setIncidenceAngleEnable(bool flag);
        bool getLandSetEnable() const;
        void setLandSetEnable(bool flag);
        bool getLandDirEnable() const;
        void setLandDirEnable(bool flag);
        f32 getLandLength() const;
        void setLandLength(f32 val);
        bool getOMMaterialEnable() const;
        void setOMMaterialEnable(bool flag);
        u32 getParentNo() const;
        void setParentNo(u32 ParentNo);
        u32 getPosType() const;
        void setPosType(u32 type);
        u32 getRotType() const;
        void setRotType(u32 type);
        s32 getJointNo() const;
        void setJointNo(s32 JointNo);
        MtColor getDefaultColor() const;
        void setDefaultColor(const MtColor& Color);
        f32 getDefaultColorRate() const;
        void setDefaultColorRate(f32 rate);
        u32 getDefaultColorMode() const;
        void setDefaultColorMode(u32 mode);
        f32 getAlphaScale() const;
        void setAlphaScale(f32 rate);
        u32 getLightPriority() const;
        void setLightPriority(u32 pri);
        u32 getCustomFlag() const;
        void setCustomFlag(u32 flag);
        u32 getParentRelationFlag() const;
        void setParentRelationFlagFlag(u32 flag);
        u32 getZoneCorrectType() const;
        void setZoneCorrectType(u32 flag);
        u32 getLoopFrame() const;
        void setLoopFrame(u32 LoopFrame);
        u32 getE2DType() const;
        void setE2DType(u32 type);
        u32 getAdhesionDivideMax() const;
        void setAdhesionDivideMax(u32 max);
        const cWeatherFlag& getWeatherOnBit() const;
        void setWeatherOnBit(const cWeatherFlag&);
        cWeatherFlag& WeatherOnBit();
        u32 getZoneOnBit() const;
        void setZoneOnBit(u32 set);
        u32 getQuakeType();
        void setQuakeType(u32 set);
        u32 getCreateCost();
        void setCreateCost(u32 set);
        f32 getFinishFadeOutFrame();
        void setFinishFadeOutFrame(f32 set);
    private:
        u32 mSetType;  // offset: 0x8
        u32 mEndType;  // offset: 0xc
        u32 mGroupFlag;  // offset: 0x10
        MtVector3 mPosition;  // offset: 0x20
        MtVector3 mCamOfs;  // offset: 0x30
        MtVector3 mDirection;  // offset: 0x40
        MtVector3 mDirectionAmp;  // offset: 0x50
        u32 mMaterialFlag;  // offset: 0x60
        u32 mAxisType;  // offset: 0x64
        u32 mOrder;  // offset: 0x68
        f32 mScale;  // offset: 0x6c
        f32 mScaleAmp;  // offset: 0x70
        f32 mDeltaTimeCoef;  // offset: 0x74
        u32 mParentNo;  // offset: 0x78
        u32 mPosType;  // offset: 0x7c
        u32 mRotType;  // offset: 0x80
        s32 mJointNo;  // offset: 0x84
        MtColor mDefaultColor;  // offset: 0x88
        f32 mDefaultColorRate;  // offset: 0x8c
        u32 mDefaultColorMode;  // offset: 0x90
        f32 mAlphaScale;  // offset: 0x94
        u32 mLightPriority;  // offset: 0x98
        u32 mIncidenceAngleEnable : 1;  // offset: 0x9c
        u32 mLandSetEnable : 1;  // offset: 0x9c
        u32 mLandDirEnable : 1;  // offset: 0x9c
        u32 mOMMaterialEnable : 1;  // offset: 0x9c
        u32 mZoneCorrectType : 4;  // offset: 0x9c
        u32 mLoopFrame : 16;  // offset: 0x9c
        u32 mE2DType : 3;  // offset: 0x9c
        u32 __Reserve__ : 4;  // offset: 0x9c
        f32 mLandLength;  // offset: 0xa0
        u32 mCustomFlag;  // offset: 0xa4
        u32 mParentRelationFlag;  // offset: 0xa8
        u32 mAdhesionDivideMax : 8;  // offset: 0xac
        u32 __Reserve02__ : 24;  // offset: 0xac
        cWeatherFlag mWeatherOnBit;  // offset: 0xb0
        u32 mZoneOnBit;  // offset: 0xb4
        u32 mQuakeType;  // offset: 0xb8
        u32 mCreateCost;  // offset: 0xbc
        f32 mFinishFadeOutFrame;  // offset: 0xc0
    public:
        static MyDTI DTI;
    };
public:
    class EffectMotSyncParam : public MtObject
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
        EffectMotSyncParam();
        u32 getMotionNo();
        void setMotionNo(u32 no);
        u32 getBlendIndex();
        void setBlendIndex(u32 index);
        f32 getStartFrame();
        void setStartFrame(f32 frame);
        f32 getEndFrame();
        void setEndFrame(f32 frame);
        f32 getInterval();
        void setInterval(f32 frame);
        u32 getEfcIndexNo();
        void setEfcIndexNo(u32 no);
        u32 getEfcElementNo();
        void setEfcElementNo(u32 no);
        bool getLeaveFlag() const;
        void setLeaveFlag(bool flag);
        bool getSetOnceFlag() const;
        void setSetOnceFlag(bool flag);
    private:
        u32 mMotionNo;  // offset: 0x8
        u32 mBlendIndex;  // offset: 0xc
        f32 mStartFrame;  // offset: 0x10
        f32 mEndFrame;  // offset: 0x14
        f32 mInterval;  // offset: 0x18
        u32 mLeaveFlag : 1;  // offset: 0x1c
        u32 mSetOnceFlag : 1;  // offset: 0x1c
        u32 __Reserve__ : 30;  // offset: 0x1c
        u32 mEfcIndexNo;  // offset: 0x20
        u32 mEfcElementNo;  // offset: 0x24
    public:
        static MyDTI DTI;
    };
public:
    class EffectEventParam : public MtObject
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
        EffectEventParam();
        u32 getEventWorkNo();
        void setEventWorkNo(u32 no);
        u32 getEfcIndexNo();
        void setEfcIndexNo(u32 no);
        u32 getEfcElementNo();
        void setEfcElementNo(u32 no);
    private:
        u32 mEventWorkNo;  // offset: 0x8
        u32 mEfcIndexNo;  // offset: 0xc
        u32 mEfcElementNo;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class INFO_EFFECT : public rEffectProvider::INFO_BASE
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
        INFO_EFFECT();
        virtual ~INFO_EFFECT();
        void clear();
        rEffectProvider::EffectIndex* getEffectIndex(s32 index) const;
        u32 getEffectIndexNum() const;
        rEffectProvider::EffectElement* getEffectElement(s32 IndexNo, s32 ElementNo) const;
        rEffectProvider::EffectParam* getEffectParam(s32 IndexNo, s32 ElementNo) const;
        rEffectProvider::EffectMotSyncParam* getMotSyncList(s32 index) const;
        u32 getMotSyncListNum() const;
        rEffectProvider::EffectEventParam* getEventList(s32 index) const;
        u32 getEventListNum() const;
        void setEffectIndex(rEffectProvider::EffectIndex* pEffectIndex);
        void setEffectIndexNum(u32 num);
        void setMotSyncList(rEffectProvider::EffectMotSyncParam* pMotSyncList);
        void setMotSyncListNum(u32 num);
        void setEventList(rEffectProvider::EffectEventParam* pEventList);
        void setEventListNum(u32 num);
    private:
        rEffectProvider::EffectIndex* mpEffectIndex;  // offset: 0x8
        u32 mEffectIndexNum;  // offset: 0x10
        rEffectProvider::EffectMotSyncParam* mpMotSyncList;  // offset: 0x18
        u32 mMotSyncListNum;  // offset: 0x20
        rEffectProvider::EffectEventParam* mpEventList;  // offset: 0x28
        u32 mEventListNum;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
public:
    class EffectElement : public MtObject
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
        EffectElement();
        virtual ~EffectElement();
        rEffectList* getEffectList(u32 no);
        void setEffectList(rEffectList* pEffectList, u32 no);
        u32 getEffectListNum();
        void setEffectListNum(u32);
        rEffect2D* getEffect2D(u32 no);
        void setEffect2D(rEffect2D* pEffect2D, u32 no);
        u32 getEffect2DNum();
        void setEffect2DNum(u32);
        u32 getResourceType();
        void setResourceType(u32 type);
        u32 getEffectType();
        void setEffectType(u32 type);
        rEffectProvider::EffectParam* getEffectParam();
        u32 getEffectReleaseVer();
        void setEffectReleaseVer(u32);
    private:
        rEffectList* mpEffectList[8];  // offset: 0x8
        rEffect2D* mpEffect2D[1];  // offset: 0x48
        u32 mEffectReleaseVer;  // offset: 0x50
        u32 mResourceType;  // offset: 0x54
        u32 mEffectType;  // offset: 0x58
        rEffectProvider::EffectParam mEffectParam;  // offset: 0x60
    public:
        static MyDTI DTI;
    };
public:
    class INFO_PROV : public MtObject
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
        INFO_PROV();
        void clear();
    public:
        rEffectProvider::INFO_EFFECT mEffectInfo;  // offset: 0x8
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
    rEffectProvider();
    virtual ~rEffectProvider();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
protected:
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
public:
    INFO_EFFECT* getEffectInfo();
    u32 getE2DType(s32 index, s32 element);
private:
    INFO_PROV mInfo;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u32 EP_MAGIC = 5656645;
    static const u32 EP_VERSION = 20;
};

// Inline, no code of its own: checked where it is inlined.
inline rEffectProvider::INFO_BASE::INFO_BASE() {
}

// Inline, no code of its own: checked where it is inlined.
inline rEffectProvider::EffectIndex::EffectIndex() {
    this->mpEffectElement = static_cast<rEffectProvider::EffectElement*>(nullptr);
    this->mEffectElementNum = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rEffectProvider::EffectMotSyncParam::EffectMotSyncParam() {
    this->mMotionNo = static_cast<u32>(65535);
    this->mBlendIndex = static_cast<u32>(255);
    this->mStartFrame = 0.0f;
    this->mEndFrame = 0.0f;
    this->mInterval = 0.0f;
    this->mLeaveFlag = static_cast<u32>(0);
    this->mSetOnceFlag = static_cast<u32>(0);
    this->mEfcIndexNo = static_cast<u32>(65535);
    this->mEfcElementNo = static_cast<u32>(65535);
}

// Inline, no code of its own: checked where it is inlined.
inline rEffectProvider::EffectEventParam::EffectEventParam() {
    this->mEventWorkNo = static_cast<u32>(0);
    this->mEfcIndexNo = static_cast<u32>(65535);
    this->mEfcElementNo = static_cast<u32>(65535);
}
