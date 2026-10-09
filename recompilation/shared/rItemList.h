#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"
#include "nCharacterData.h"
#include "nWeapon.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
namespace nGUIItem { class cItem; }
class sItemManager;
class uHuman;

// Declarations
class rItemList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rItemList : public cResource
{
public:
    enum USE_CATEGORY
    {
        USE_CATEGORY_DUMMY = 0,
        USE_CATEGORY_NONE = 1,
        USE_CATEGORY_THROW = 2,
        USE_CATEGORY_MINE = 3,
        USE_CATEGORY_LUMBER = 4,
        USE_CATEGORY_KEY = 5,
        USE_CATEGORY_JOBITEM = 6,
        USE_CATEGORY_UNUSE = 7,
        USE_CATEGORY_DOOR_KEY = 8,
        USE_CATEGORY_NUM = 9,
    };
    enum MATERIAL_CATEGORY
    {
        MATERIAL_CATEGORY_START = 0,
        MATERIAL_CATEGORY_NONE = 0,
        MATERIAL_CATEGORY_METAL = 1,
        MATERIAL_CATEGORY_STONE = 2,
        MATERIAL_CATEGORY_SAND = 3,
        MATERIAL_CATEGORY_CLOTH = 4,
        MATERIAL_CATEGORY_THREAD = 5,
        MATERIAL_CATEGORY_WOOL = 6,
        MATERIAL_CATEGORY_BARK = 7,
        MATERIAL_CATEGORY_BONE = 8,
        MATERIAL_CATEGORY_FANG = 9,
        MATERIAL_CATEGORY_HORN = 10,
        MATERIAL_CATEGORY_SHELL = 11,
        MATERIAL_CATEGORY_WING = 12,
        MATERIAL_CATEGORY_JEWEL = 13,
        MATERIAL_CATEGORY_GRASS = 14,
        MATERIAL_CATEGORY_FLOWER = 15,
        MATERIAL_CATEGORY_NUTS = 16,
        MATERIAL_CATEGORY_MUSHROOM = 17,
        MATERIAL_CATEGORY_WOODCHIP = 18,
        MATERIAL_CATEGORY_LIQUID = 19,
        MATERIAL_CATEGORY_BANDEROLE = 20,
        MATERIAL_CATEGORY_ALCHE = 21,
        MATERIAL_CATEGORY_MEAT = 22,
        MATERIAL_CATEGORY_OTHER = 23,
        MATERIAL_CATEGORY_ELEMENT_WEP = 24,
        MATERIAL_CATEGORY_ELEMENT_ARMOR = 25,
        MATERIAL_CATEGORY_SPECIAL_WEP = 26,
        MATERIAL_CATEGORY_SPECIAL_ARMOR = 27,
        MATERIAL_CATEGORY_COLOR = 28,
        MATERIAL_CATEGORY_APPRAISAL = 29,
        MATERIAL_CATEGORY_SPECIALTY_GOODS = 30,
        MATERIAL_CATEGORY_NUM = 31,
    };
    enum KIND_TYPE
    {
        KIND_TYPE_NONE = 0,
        KIND_TYPE_S8_START = 1,
        KIND_TYPE_POISON_DEF = 1,
        KIND_TYPE_SLOW_DEF = 2,
        KIND_TYPE_OIL_DEF = 3,
        KIND_TYPE_BLIND_DEF = 4,
        KIND_TYPE_SLEEP_DEF = 5,
        KIND_TYPE_WATER_DEF = 6,
        KIND_TYPE_SEAL_DEF = 7,
        KIND_TYPE_SOFTBODY_DEF = 8,
        KIND_TYPE_STONE_DEF = 9,
        KIND_TYPE_GOLD_DEF = 10,
        KIND_TYPE_SPREAD_DEF = 11,
        KIND_TYPE_FROZEN_DEF = 12,
        KIND_TYPE_SHOCK_DEF = 13,
        KIND_TYPE_SAINT_DEF = 14,
        KIND_TYPE_SWOON_DEF = 15,
        KIND_TYPE_CURSE_DEF = 16,
        KIND_TYPE_DONW_FIRE = 17,
        KIND_TYPE_DOWN_ICE = 18,
        KIND_TYPE_DOWN_THUNDER = 19,
        KIND_TYPE_DOWN_SAINT = 20,
        KIND_TYPE_DOWN_BLIND = 21,
        KIND_TYPE_DOWN_ATTACK = 22,
        KIND_TYPE_DOWN_DEFENCE = 23,
        KIND_TYPE_DOWN_MAGIC_AT = 24,
        KIND_TYPE_DOWN_MAGIC_DEF = 25,
        KIND_TYPE_EROSION_DEF = 26,
        KIND_TYPE_ITEMSEAL_DEF = 27,
        KIND_TYPE_S8_END = 28,
        KIND_TYPE_S8_NUM = 27,
        KIND_TYPE_U8_START = 28,
        KIND_TYPE_SPIRIT = 28,
        KIND_TYPE_SHIELD_STAMINA = 29,
        KIND_TYPE_TSHIELD_STORAGE = 30,
        KIND_TYPE_ARROW_NUM = 31,
        KIND_TYPE_U8_END = 32,
        KIND_TYPE_U8_NUM = 4,
        KIND_TYPE_S16_START = 32,
        KIND_TYPE_FIRE_ELE_DEF = 32,
        KIND_TYPE_ICE_ELE_DEF = 33,
        KIND_TYPE_THUNDER_ELE_DEF = 34,
        KIND_TYPE_SAINT_ELE_DEF = 35,
        KIND_TYPE_DARK_ELE_DEF = 36,
        KIND_TYPE_S16_END = 37,
        KIND_TYPE_S16_NUM = 5,
        KIND_TYPE_U16_START = 37,
        KIND_TYPE_POISON_SAV = 37,
        KIND_TYPE_SLOW_SAV = 38,
        KIND_TYPE_OIL_SAV = 39,
        KIND_TYPE_BLIND_SAV = 40,
        KIND_TYPE_SLEEP_SAV = 41,
        KIND_TYPE_WATER_SAV = 42,
        KIND_TYPE_SEAL_SAV = 43,
        KIND_TYPE_SOFTBODY_SAV = 44,
        KIND_TYPE_STONE_SAV = 45,
        KIND_TYPE_GOLD_SAV = 46,
        KIND_TYPE_SPRED_SAV = 47,
        KIND_TYPE_FREEZE_SAV = 48,
        KIND_TYPE_SHOCK_SAV = 49,
        KIND_TYPE_CROSS_SAV = 50,
        KIND_TYPE_DOWN_FIRE_SAV = 51,
        KIND_TYPE_DOWN_ICE_SAV = 52,
        KIND_TYPE_DOWN_THUNDER_SAV = 53,
        KIND_TYPE_DOWN_SAINT_SAV = 54,
        KIND_TYPE_DOWN_BLIND_SAV = 55,
        KIND_TYPE_DOWN_ATTACK_SAV = 56,
        KIND_TYPE_DOWN_DEF_SAV = 57,
        KIND_TYPE_DOWN_MAGIC_SAV = 58,
        KIND_TYPE_DOWN_MAGIC_DEF_SAV = 59,
        KIND_TYPE_STAN_SAV = 60,
        KIND_TYPE_U16_END = 61,
        KIND_TYPE_U16_NUM = 24,
    };
    enum ITEM_CATEGORY
    {
        CATEGORY_NONE = 0,
        CATEGORY_USE_ITEM = 1,
        CATEGORY_MATERIAL_ITEM = 2,
        CATEGORY_ARMS = 3,
        CATEGORY_KEY_ITEM = 4,
        CATEGORY_JOB_ITEM = 5,
        CATEGORY_FURNITURE = 6,
        CATEGORY_CRAFT_RECIPE = 7,
        CATEGORY_NUM = 8,
    };
    enum SEX_TYPE
    {
        SEX_TYPE_NONE = 0,
        SEX_TYPE_BOTH = 1,
        SEX_TYPE_MAN = 2,
        SEX_TYPE_WOMAN = 3,
        SEX_TYPE_NUM = 4,
    };
public:
    class MyDTI;
    class rItemParam;
    class rParam;
    class rVsEnemyParam;
    class rWeaponParam;
    class rEquipParamS8;
    class rItemParamXml;
    class rProtectorParam;
    class rEquipParamS32;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class rParam : public MtObject
    {
    public:
        enum PARAM_KIND
        {
            KIND_NONE = 0,
            HP_RECOVER = 1,
            ST_RECOVER = 2,
            POISON_CLEAR = 3,
            SlOW_CLEAR = 4,
            SLEEP_CLEAR = 5,
            STAN_CLEAR = 6,
            WATER_CLEAR = 7,
            OIL_CLEAR = 8,
            SEAL_CLEAR = 9,
            SOFTBODY_CLEAR = 10,
            STONE_CLEAR = 11,
            GOLD_CLEAR = 12,
            SPREAD_CLEAR = 13,
            FREEZE_CLEAR = 14,
            FALLFIRE_CLEAR = 15,
            FALLICE_CLEAR = 16,
            FALLTHUNDER_CLEAR = 17,
            FALLSAINT_CLEAR = 18,
            FALLBLIND_CLEAR = 19,
            FALLATTACK_CLEAR = 20,
            FALLDEF_CLEAR = 21,
            FALLMAGIC_CLEAR = 22,
            FALLMAGICDEF_CLEAR = 23,
            ATTACK_UP = 24,
            DEFENCE_UP = 25,
            MAGICATTACK_UP = 26,
            MAGICDEFENSE_UP = 27,
            POWERREV_UP = 28,
            DURABILITY_UP = 29,
            SPIRIT_UP = 30,
            HP_UP = 31,
            ENDURANCE_UP = 32,
            BLIND_CLEAR = 33,
            REVIVAL_ONE = 34,
            REVIVAL_THREE = 35,
            LANTERN_ON = 36,
            GOLD_CHANGE = 110,
            RIM_CHANGE = 111,
            DOGMA_CHANGE = 112,
            MEDAL_POISON = 113,
            MEDAL_SLEEP = 114,
            MEDAL_STAN = 115,
            MEDAL_FALLFIRE = 116,
            MEDAL_FALLICE = 117,
            MEDAL_FALLTHUNDER = 118,
            MEDAL_FALLSAINT = 119,
            MEDAL_FALLBLIND = 120,
            MEDAL_SEAL = 121,
            MEDAL_STONE = 122,
            MEDAL_GOLD = 123,
            CURRENCY = 124,
            THUNDER_CLEAR = 125,
            EROSION_CLEAR = 126,
            EROSION_GUARD_UP = 127,
            JOB_POINT = 128,
            AREA_POINT = 129,
            SKILL_LEARN = 130,
            ABILITY_LEARN = 131,
            PAWN_USE = 132,
            KIND_NUM = 133,
        };
        enum ELEMENT_PARAM_KIND
        {
            KIND_NONE_ELEMENT = 0,
            WEIGHT_DOWN_ELEMENT = 1,
            SpredSav_UP_ELEMENT = 2,
            FreezeSav_UP_ELEMENT = 3,
            ShockSav_UP_ELEMENT = 4,
            CrossSav_UP_ELEMENT = 5,
            BlindSav_UP_ELEMENT = 6,
            ATTACK_UP_ELEMENT = 7,
            MAGICATTACK_UP_ELEMENT = 8,
            POWERREV_UP_ELEMENT = 9,
            StanSav_UP_ELEMENT = 10,
            PoisonSav_UP_ELEMENT = 11,
            SlowSav_UP_ELEMENT = 12,
            SleepSav_UP_ELEMENT = 13,
            WaterSav_UP_ELEMENT = 14,
            OilSav_UP_ELEMENT = 15,
            SealSav_UP_ELEMENT = 16,
            SoftBodySav_UP_ELEMENT = 17,
            StoneSav_UP_ELEMENT = 18,
            GoldSav_UP_ELEMENT = 19,
            FallFireSav_UP_ELEMENT = 20,
            FallIceSav_UP_ELEMENT = 21,
            FallThunderSav_UP_ELEMENT = 22,
            FallSaintSav_UP_ELEMENT = 23,
            FallBlindSav_UP_ELEMENT = 24,
            FallAttackSav_UP_ELEMENT = 25,
            FallDefSav_UP_ELEMENT = 26,
            FallMagicSav_UP_ELEMENT = 27,
            FallMagicDefSav_UP_ELEMENT = 28,
            DEFENCE_UP_ELEMENT = 29,
            MAGICDEFENSE_UP_ELEMENT = 30,
            DURABILITY_UP_ELEMENT = 31,
            SPIRIT_UP_ELEMENT = 32,
            HP_UP_ELEMENT = 33,
            ST_UP_ELEMENT = 34,
            ShinRyokuRev_UP_ELEMENT = 35,
            FireEleDef_UP_ELEMENT = 36,
            IceEleDef_UP_ELEMENT = 37,
            ThunderEleDef_UP_ELEMENT = 38,
            SaintEleDef_UP_ELEMENT = 39,
            DarkEleDef_UP_ELEMENT = 40,
            SpredDef_UP_ELEMENT = 41,
            FreezeDef_UP_ELEMENT = 42,
            ShockDef_UP_ELEMENT = 43,
            CrossDef_UP_ELEMENT = 44,
            BlindDef_UP_ELEMENT = 45,
            PoisonDef_UP_ELEMENT = 46,
            SlowDef_UP_ELEMENT = 47,
            SleepDef_UP_ELEMENT = 48,
            StanDef_UP_ELEMENT = 49,
            WaterDef_UP_ELEMENT = 50,
            OilDef_UP_ELEMENT = 51,
            SealDef_UP_ELEMENT = 52,
            CurseDef_UP_ELEMENT = 53,
            SoftBodyDef_UP_ELEMENT = 54,
            StoneDef_UP_ELEMENT = 55,
            GoldDef_UP_ELEMENT = 56,
            FallFireDef_UP_ELEMENT = 57,
            FallIceDef_UP_ELEMENT = 58,
            FallThunderDef_UP_ELEMENT = 59,
            FallSaintDef_UP_ELEMENT = 60,
            FallBlindDef_UP_ELEMENT = 61,
            FallAttackDef_UP_ELEMENT = 62,
            FallDefenceDef_UP_ELEMENT = 63,
            FallMagicAttackDef_UP_ELEMENT = 64,
            FallMagicDefenceDef_UP_ELEMENT = 65,
            VsEm00_UP_ELEMENT = 66,
            VsEm01_UP_ELEMENT = 67,
            VsEm02_UP_ELEMENT = 68,
            VsEm03_UP_ELEMENT = 69,
            VsEm04_UP_ELEMENT = 70,
            VsEm05_UP_ELEMENT = 71,
            VsEm06_UP_ELEMENT = 72,
            VsEm07_UP_ELEMENT = 73,
            VsEm08_UP_ELEMENT = 74,
            VsEm09_UP_ELEMENT = 75,
            VsEm10_UP_ELEMENT = 76,
            VsEm11_UP_ELEMENT = 77,
            VsEm12_UP_ELEMENT = 78,
            VsEm13_UP_ELEMENT = 79,
            VsEm14_UP_ELEMENT = 80,
            Color_ELEMENT = 81,
            DASH_ST_UP = 82,
            JUMP_UP = 83,
            CLIME_SPD_UP = 84,
            AWAKENING_WEIGHT_LIGHTRY = 85,
            LOW_LV_EXP_UP = 86,
            ABILITY = 87,
            VsEm15_UP_ELEMENT = 88,
            ELEMENT_PARAM_KIND_NUM = 89,
        };
        enum
        {
            CRAFT_COLOR_START = 1,
            CRAFT_COLOR_ALL = 1,
            CRAFT_COLOR_DEFAULT = 2,
            CRAFT_COLOR_RED = 3,
            CRAFT_COLOR_GREEN = 4,
            CRAFT_COLOR_BLUE = 5,
            CRAFT_COLOR_YELLOW = 6,
            CRAFT_COLOR_PINK = 7,
            CRAFT_COLOR_BLACK = 8,
            CRAFT_COLOR_END = 9,
            CRAFT_COLOR_NUM = 8,
        };
    public:
        class MyDTI;
    public:
        typedef struct
        {
        public:
            u16 mAreaId;  // offset: 0x0
            u16 mPoint;  // offset: 0x2
            u16 padding;  // offset: 0x4
        } AP_GET;
    public:
        typedef struct
        {
        public:
            u16 mJobId;  // offset: 0x0
            u16 mPoint;  // offset: 0x2
            u16 padding;  // offset: 0x4
        } JP_GET;
    public:
        typedef struct
        {
        public:
            u16 mAbilityNo;  // offset: 0x0
            u16 mLv;  // offset: 0x2
            u16 padding;  // offset: 0x4
        } ABILITY_ASSIGNMENT;
    public:
        typedef struct
        {
        public:
            u16 mJobId;  // offset: 0x0
            u16 mSkillNo;  // offset: 0x2
            u16 padding;  // offset: 0x4
        } SKILL_LEARNING;
    public:
        typedef struct
        {
        public:
            u16 mAbilityNo;  // offset: 0x0
            u16 padding1;  // offset: 0x2
            u16 padding2;  // offset: 0x4
        } ABILITY_LEARNING;
    public:
        typedef union
        {
        public:
            struct
            {
            public:
                u16 mParam1;  // offset: 0x0
                u16 mParam2;  // offset: 0x2
                u16 mParam3;  // offset: 0x4
            };  // offset: 0x0
            rItemList::rParam::AP_GET mAp;  // offset: 0x0
            rItemList::rParam::JP_GET mJp;  // offset: 0x0
            rItemList::rParam::ABILITY_ASSIGNMENT mAbilityAssignment;  // offset: 0x0
            rItemList::rParam::SKILL_LEARNING mSkillLearning;  // offset: 0x0
            rItemList::rParam::ABILITY_LEARNING mAbilityLearning;  // offset: 0x0
        } PARAM;
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
        rParam(s16 kind, u16 num1, u16 num2, u16 num3);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual bool load(MtDataReader& in);  // vtable slot 6
        virtual bool save(MtDataWriter& out);  // vtable slot 7
        PARAM_KIND getKindType();
        ELEMENT_PARAM_KIND getElementKindType();
        u16 getKindParam();
        u16 getKindParam2();
        u16 getKindParam3();
        u16 getApAreaId();
        u16 getApAreaPoint();
        u16 getJpJobId();
        u16 getJpJobPoint();
        u16 getAbilityAssignmentNo();
        u16 getAbilityAssignmentLv();
        u16 getSkillLearnJobId();
        u16 getSkillLearnJobPoint();
        u16 getAbilityLearningAbilityNo();
        void setParam(rItemList::rParam* pParam);
    private:
        s16 mKindType;  // offset: 0x8
        PARAM mParam;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
public:
    class rVsEnemyParam : public MtObject
    {
    public:
        enum EM_PHYLOGENY_KIND
        {
            EM_PHYLOGENY_KIND_NONE = 0,
            EM_PHYLOGENY_KIND_01 = 1,
            EM_PHYLOGENY_KIND_02 = 2,
            EM_PHYLOGENY_KIND_03 = 3,
            EM_PHYLOGENY_KIND_04 = 4,
            EM_PHYLOGENY_KIND_05 = 5,
            EM_PHYLOGENY_KIND_06 = 6,
            EM_PHYLOGENY_KIND_07 = 7,
            EM_PHYLOGENY_KIND_08 = 8,
            EM_PHYLOGENY_KIND_09 = 9,
            EM_PHYLOGENY_KIND_0A = 10,
            EM_PHYLOGENY_KIND_0B = 11,
            EM_PHYLOGENY_KIND_0C = 12,
            EM_PHYLOGENY_KIND_0D = 13,
            EM_PHYLOGENY_KIND_0E = 14,
            EM_PHYLOGENY_KIND_0F = 15,
            EM_PHYLOGENY_KIND_10 = 16,
            EM_PHYLOGENY_KIND_NUM = 17,
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
        rVsEnemyParam(EM_PHYLOGENY_KIND kind, u16 num);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual bool load(MtDataReader& in);  // vtable slot 6
        virtual bool save(MtDataWriter& out);  // vtable slot 7
        EM_PHYLOGENY_KIND getKindType();
        u16 getKindParam();
        void setParam(rItemList::rVsEnemyParam* pParam);
    private:
        u8 mKindType;  // offset: 0x8
        u16 mParam;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
public:
    class rWeaponParam : public MtObject
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
        rWeaponParam();
        virtual ~rWeaponParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual bool load(MtDataReader& in, rItemList::rEquipParamS8* pArray, u32* pUseNum);  // vtable slot 6
        virtual bool save(MtDataWriter& out);  // vtable slot 7
        void setParam(rItemList::rWeaponParam* pParam);
        void setParam(rItemList::rItemParamXml* pParam, rItemList::rEquipParamS8* pEquipParamS8, u32* pUseNum);
        u32 setKindParam(rItemList::rItemParamXml* pParam, rItemList::rEquipParamS8* pEquipParamS8List);
    public:
        u32 mModelTagId;  // offset: 0x8
        u32 mPowerRev;  // offset: 0xc
        u32 mChance;  // offset: 0x10
        u32 mDefense;  // offset: 0x14
        u32 mMagicDefense;  // offset: 0x18
        u32 mDurability;  // offset: 0x1c
        u32 mAttack;  // offset: 0x20
        u32 mMagicAttack;  // offset: 0x24
        u32 mShieldStagger;  // offset: 0x28
        rItemList::rEquipParamS8* mpEquipParamS8List;  // offset: 0x30
        u16 mWeight;  // offset: 0x38
        u16 mMaxHpRev;  // offset: 0x3a
        u16 mMaxStRev;  // offset: 0x3c
        u8 mWepCategory;  // offset: 0x3e
        u8 mColorNo;  // offset: 0x3f
        u8 mSex;  // offset: 0x40
        u8 mModelParts;  // offset: 0x41
        u8 mEleSlot;  // offset: 0x42
        u8 mPhysicalType;  // offset: 0x43
        u8 mElementType;  // offset: 0x44
        u8 mEquipParamS8Num;  // offset: 0x45
        static MyDTI DTI;
    };
public:
    class rEquipParamS8 : public MtObject
    {
    public:
        enum
        {
            FORM_TYPE_S8 = 0,
            FORM_TYPE_U8 = 1,
            FORM_TYPE_S16 = 2,
            FORM_TYPE_U16 = 3,
        };
    public:
        class MyDTI;
    public:
        typedef union
        {
        public:
            struct
            {
            public:
                s8 mValueS8;  // offset: 0x0
                u8 mPaddingS8;  // offset: 0x1
            };  // offset: 0x0
            struct
            {
            public:
                u8 mValueU8;  // offset: 0x0
                u8 mPaddingU8;  // offset: 0x1
            };  // offset: 0x0
            struct
            {
            public:
                s16 mValueS16;  // offset: 0x0
            };  // offset: 0x0
            struct
            {
            public:
                u16 mValueU16;  // offset: 0x0
            };  // offset: 0x0
        } PARAM;
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
        rEquipParamS8();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual bool load(MtDataReader& in);  // vtable slot 6
        virtual bool save(MtDataWriter& out);  // vtable slot 7
        rItemList::KIND_TYPE getKindType();
        void setKindParamS8(rItemList::KIND_TYPE kind, s8 value);
        s8 getKindParamS8();
        void setKindParamU8(rItemList::KIND_TYPE kind, u8 value);
        s8 getKindParamU8();
        void setKindParamS16(rItemList::KIND_TYPE kind, s16 value);
        s16 getKindParamS16();
        void setKindParamU16(rItemList::KIND_TYPE kind, u16 value);
        s16 getKindParamU16();
    private:
        u8 mKindType;  // offset: 0x8
        u8 mForm;  // offset: 0x9
        PARAM mValue;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
public:
    class rItemParamXml : public MtObject
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
        rItemParamXml();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void createParamProperty(MtPropertyList& s);
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setItemParamNum(u32);
        u32 getItemParamNumXml();
        bool isWeapon();
        bool isProtector();
        u32 getVsEmParamNum();
        u32 getUseJob();
        u32 getKindNum();
    public:
        u32 mItemId;  // offset: 0x8
        u32 mNameId;  // offset: 0xc
        rItemList::ITEM_CATEGORY mCategory;  // offset: 0x10
        rItemList::MATERIAL_CATEGORY mMaterialCategory;  // offset: 0x14
        u32 mPrice;  // offset: 0x18
        bool mIsSell;  // offset: 0x1c
        bool mIsBazaar;  // offset: 0x1d
        u8 mStackMax;  // offset: 0x1e
        u8 mRank;  // offset: 0x1f
        u8 mGrade;  // offset: 0x20
        u8 mIconColNo;  // offset: 0x21
        u16 mIconNo;  // offset: 0x22
        u8 mArrowNum;  // offset: 0x24
        u8 mTShieldStorage;  // offset: 0x25
        u32 mSortNo;  // offset: 0x28
        u32 mNameSortNo;  // offset: 0x2c
        rItemList::USE_CATEGORY mUseType;  // offset: 0x30
        u32 mAttackStatus;  // offset: 0x34
        bool mIsUnUseLobby;  // offset: 0x38
        nWeapon::WEAPON_CATEGORY mWepCategory;  // offset: 0x3c
        u8 mEquip;  // offset: 0x40
        u8 mPhysicalType;  // offset: 0x41
        u8 mElementType;  // offset: 0x42
        u8 mEleSlot;  // offset: 0x43
        bool mIsJob01;  // offset: 0x44
        bool mIsJob02;  // offset: 0x45
        bool mIsJob03;  // offset: 0x46
        bool mIsJob04;  // offset: 0x47
        bool mIsJob05;  // offset: 0x48
        bool mIsJob06;  // offset: 0x49
        bool mIsJob07;  // offset: 0x4a
        bool mIsJob08;  // offset: 0x4b
        bool mIsJob09;  // offset: 0x4c
        bool mIsJob10;  // offset: 0x4d
        u16 mIsUseLv;  // offset: 0x4e
        u16 mWeight;  // offset: 0x50
        bool mIsUseNpc;  // offset: 0x52
        u8 mColorNo;  // offset: 0x53
        u8 mSex;  // offset: 0x54
        u8 mModelParts;  // offset: 0x55
        u8 mShieldStamina;  // offset: 0x56
        u32 mModelTagId;  // offset: 0x58
        u32 mAttack;  // offset: 0x5c
        u32 mMagicAttack;  // offset: 0x60
        u32 mPowerRev;  // offset: 0x64
        u32 mShieldStagger;  // offset: 0x68
        u16 mVsEm00;  // offset: 0x6c
        u16 mVsEm01;  // offset: 0x6e
        u16 mVsEm02;  // offset: 0x70
        u16 mVsEm03;  // offset: 0x72
        u16 mVsEm04;  // offset: 0x74
        u16 mVsEm05;  // offset: 0x76
        u16 mVsEm06;  // offset: 0x78
        u16 mVsEm07;  // offset: 0x7a
        u16 mVsEm08;  // offset: 0x7c
        u16 mVsEm09;  // offset: 0x7e
        u16 mVsEm0a;  // offset: 0x80
        u16 mVsEm0b;  // offset: 0x82
        u16 mVsEm0c;  // offset: 0x84
        u16 mVsEm0d;  // offset: 0x86
        u16 mVsEm0e;  // offset: 0x88
        u16 mVsEm0f;  // offset: 0x8a
        u8 mSpirit;  // offset: 0x8c
        u16 mPoisonSav;  // offset: 0x8e
        u16 mSlowSav;  // offset: 0x90
        u16 mOilSav;  // offset: 0x92
        u16 mBlindSav;  // offset: 0x94
        u16 mSleepSav;  // offset: 0x96
        u16 mWaterSav;  // offset: 0x98
        u16 mSealSav;  // offset: 0x9a
        u16 mSoftBodySav;  // offset: 0x9c
        u16 mStoneSav;  // offset: 0x9e
        u16 mGoldSav;  // offset: 0xa0
        u16 mSpredSav;  // offset: 0xa2
        u16 mFreezeSav;  // offset: 0xa4
        u16 mShockSav;  // offset: 0xa6
        u16 mCrossSav;  // offset: 0xa8
        u16 mStanSav;  // offset: 0xaa
        u16 mFallFireSav;  // offset: 0xac
        u16 mFallIceSav;  // offset: 0xae
        u16 mFallThunderSav;  // offset: 0xb0
        u16 mFallSaintSav;  // offset: 0xb2
        u16 mFallBlindSav;  // offset: 0xb4
        u16 mFallAttackSav;  // offset: 0xb6
        u16 mFallDefSav;  // offset: 0xb8
        u16 mFallMagicSav;  // offset: 0xba
        u16 mFallMagicDefSav;  // offset: 0xbc
        u32 mChance;  // offset: 0xc0
        u32 mDefense;  // offset: 0xc4
        u32 mMagicDefense;  // offset: 0xc8
        u32 mDurability;  // offset: 0xcc
        u16 mMaxHpRev;  // offset: 0xd0
        u16 mMaxStRev;  // offset: 0xd2
        s16 mFireEleDef;  // offset: 0xd4
        s16 mIceEleDef;  // offset: 0xd6
        s16 mThunderEleDef;  // offset: 0xd8
        s16 mSaintEleDef;  // offset: 0xda
        s16 mDarkEleDef;  // offset: 0xdc
        s8 mPoisonDef;  // offset: 0xde
        s8 mSlowDef;  // offset: 0xdf
        s8 mOilDef;  // offset: 0xe0
        s8 mBlindDef;  // offset: 0xe1
        s8 mSleepDef;  // offset: 0xe2
        s8 mWaterDef;  // offset: 0xe3
        s8 mSealDef;  // offset: 0xe4
        s8 mSoftBodyDef;  // offset: 0xe5
        s8 mStoneDef;  // offset: 0xe6
        s8 mGoldDef;  // offset: 0xe7
        s8 mSpredDef;  // offset: 0xe8
        s8 mFreezeDef;  // offset: 0xe9
        s8 mShockDef;  // offset: 0xea
        s8 mCrossDef;  // offset: 0xeb
        s8 mStanDef;  // offset: 0xec
        s8 mCurseDef;  // offset: 0xed
        s8 mFallFireDef;  // offset: 0xee
        s8 mFallIceDef;  // offset: 0xef
        s8 mFallThunderDef;  // offset: 0xf0
        s8 mFallSaintDef;  // offset: 0xf1
        s8 mFallBlindDef;  // offset: 0xf2
        s8 mFallAttackDef;  // offset: 0xf3
        s8 mFallDefenceDef;  // offset: 0xf4
        s8 mFallMagicAttackDef;  // offset: 0xf5
        s8 mFallMagicDefenceDef;  // offset: 0xf6
        s8 mErosionDef;  // offset: 0xf7
        s8 mItemSealDef;  // offset: 0xf8
        u8 mEquipSubCategory;  // offset: 0xf9
        rItemList::rParam* mpItemParamList;  // offset: 0x100
        u32 mParamNum;  // offset: 0x108
        MtTypedArray<rItemList::rParam> mItemParamList;  // offset: 0x110
        rItemList::rVsEnemyParam* mpVsEmList;  // offset: 0x130
        u32 mVsEmNum;  // offset: 0x138
        MtTypedArray<rItemList::rVsEnemyParam> mVsEmList;  // offset: 0x140
        static MyDTI DTI;
    };
public:
    class rProtectorParam : public MtObject
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
        rProtectorParam();
        virtual ~rProtectorParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual bool load(MtDataReader& in, rItemList::rEquipParamS8* pArray, u32* pUseNum);  // vtable slot 6
        virtual bool save(MtDataWriter& out);  // vtable slot 7
        void setParam(rItemList::rProtectorParam* pParam);
        void setParam(rItemList::rItemParamXml* pParam, rItemList::rEquipParamS8* pEquipParamS8, u32* pUseNum);
        u32 setKindParam(rItemList::rItemParamXml* pParam, rItemList::rEquipParamS8* pEquipParamS8List);
    public:
        u32 mModelTagId;  // offset: 0x8
        u32 mPowerRev;  // offset: 0xc
        u32 mChance;  // offset: 0x10
        u32 mDefense;  // offset: 0x14
        u32 mMagicDefense;  // offset: 0x18
        u32 mDurability;  // offset: 0x1c
        u32 mAttack;  // offset: 0x20
        u32 mMagicAttack;  // offset: 0x24
        rItemList::rEquipParamS8* mpEquipParamS8List;  // offset: 0x28
        u16 mWeight;  // offset: 0x30
        u16 mMaxHpRev;  // offset: 0x32
        u16 mMaxStRev;  // offset: 0x34
        u8 mColorNo;  // offset: 0x36
        u8 mSex;  // offset: 0x37
        u8 mModelParts;  // offset: 0x38
        u8 mEleSlot;  // offset: 0x39
        u8 mEquipParamS8Num;  // offset: 0x3a
        static MyDTI DTI;
    };
public:
    class rEquipParamS32 : public MtObject
    {
    public:
        enum
        {
            FORM_TYPE_S32 = 0,
            FORM_TYPE_U32 = 1,
        };
    public:
        class MyDTI;
    public:
        typedef union
        {
        public:
            struct
            {
            public:
                s32 mValueS32;  // offset: 0x0
            };  // offset: 0x0
            struct
            {
            public:
                u32 mValueU32;  // offset: 0x0
            };  // offset: 0x0
        } PARAM;
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
        rEquipParamS32();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual bool load(MtDataReader& in);  // vtable slot 6
        virtual bool save(MtDataWriter& out);  // vtable slot 7
        rItemList::KIND_TYPE getKindType();
        void setKindParamS32(rItemList::KIND_TYPE kind, s32 value);
        s8 getKindParamS32();
        void setKindParamU32(rItemList::KIND_TYPE kind, u32 value);
        s16 getKindParamU32();
    private:
        u8 mKindType;  // offset: 0x8
        u8 mForm;  // offset: 0x9
        PARAM mValue;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
public:
    class rItemParam : public MtObject
    {
        // inferred: nGUIItem::cItem::isThrowItem names rItemList::rItemParam::mCategory
        friend class nGUIItem::cItem;
        // inferred: sItemManager::reqKeyItemGetAnnounce names rItemList::rItemParam::mCategory
        friend class sItemManager;
        // inferred: uHuman::makeOcdAttackInfoCore names rItemList::rItemParam::mRank
        friend class uHuman;
    public:
        enum EQUIP_SUB_CATEGORY
        {
            EQUIP_SUB_CATEGORY_NONE = 0,
            EQUIP_SUB_CATEGORY_TOP = 1,
            EQUIP_SUB_CATEGORY_JEWELRY_COMMON = 1,
            EQUIP_SUB_CATEGORY_JEWELRY_RING = 2,
            EQUIP_SUB_CATEGORY_JEWELRY_BRACELET = 3,
            EQUIP_SUB_CATEGORY_JEWELRY_PIERCE = 4,
            EQUIP_SUB_CATEGORY_MAX = 5,
            EQUIP_SUB_CATEGORY_NUM = 4,
        };
        enum PHYSICAL_TYPE
        {
            PHYSICAL_TYPE_SWORD = 0,
            PHYSICAL_TYPE_HIT = 1,
            PHYSICAL_TYPE_ARROW = 2,
            PHYSICAL_TYPE_NUM = 3,
        };
        enum PHYSICAL_DEF_TYPE
        {
            PHYSICAL_DEF_TYPE_SWORD = 0,
            PHYSICAL_DEF_TYPE_HIT = 1,
            PHYSICAL_DEF_TYPE_ARROW = 2,
            PHYSICAL_DEF_TYPE_NUM = 3,
        };
        enum FLAG_TYPE
        {
            FLAG_TYPE_SELL = 0,
            FLAG_TYPE_BAZAAR = 1,
            FLAG_TYPE_UNUSE_LOBBY = 2,
            FLAG_TYPE_USE_NPC = 3,
            FLAG_TYPE_NUM = 4,
        };
        enum ELEMENT_TYPE
        {
            ELEMENT_TYPE_NONE = 0,
            ELEMENT_TYPE_FIRE = 1,
            ELEMENT_TYPE_ICE = 2,
            ELEMENT_TYPE_THUNDER = 3,
            ELEMENT_TYPE_SAINT = 4,
            ELEMENT_TYPE_DARK = 5,
            ELEMENT_TYPE_NUM = 6,
        };
    public:
        class MyDTI;
    public:
        typedef union
        {
        public:
            struct
            {
            public:
                u8 mEquipCategory;  // offset: 0x0
                u8 _padding;  // offset: 0x1
                u16 mEquipSubCategory;  // offset: 0x2
            };  // offset: 0x0
            rItemList::USE_CATEGORY mUseCategory;  // offset: 0x0
            rItemList::MATERIAL_CATEGORY mMaterialCategory;  // offset: 0x0
            u32 mCategory;  // offset: 0x0
        } SUB_CATEGORY;
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
        rItemParam();
        virtual ~rItemParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void createParamProperty(MtPropertyList& s);
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void copy(rItemList::rItemParamXml* src, void* pWeaponList, u32* pWeaponNum, void* pProtectorList, u32* pProtectorNum, void* pVsParamList, u32* pVsParamNum, void* pParamList, u32* pParamNum, void* pEquipParamS8List, u32* pEquipParamS8Num, bool isXml);
        virtual bool load(MtDataReader& in, void* pWeaponListData, u32* pWeaponNum, void* pProtectorListData, u32* pProtectorNum, void* pVsListData, u32* pVsNum, void* pParamListData, u32* pParamNum, void* pEquipParamS8List, u32* pEquipParamS8Num);  // vtable slot 6
        virtual bool save(MtDataWriter& out);  // vtable slot 7
        void releaseWork();
        bool setVsParam(rItemList::rVsEnemyParam* pParam, void* pArrayData, u32 no);
        bool setWeaponParam(rItemList::rWeaponParam* pParam, void* pData);
        bool setProtectorParam(rItemList::rProtectorParam* pParam, void* pData);
        u32 getItemId() const;
        MT_CTSTR getItemName() const;
        void getItemInfo(MtString& retStr) const;
        u32 getStackMax(nCharacterData::ITEM_BAG_TYPE bagType) const;
        u16 getIconNo() const;
        u8 getIconColNo() const;
        rItemList::ITEM_CATEGORY getItemCategory() const;
        void setItemCategory(rItemList::ITEM_CATEGORY);
        rItemList::MATERIAL_CATEGORY getMaterialCategory() const;
        void setMaterialCategory(rItemList::MATERIAL_CATEGORY);
        u32 getPrice() const;
        bool isSell() const;
        bool isBazaar() const;
        u16 getRank() const;
        u8 getGrade() const;
        bool getUseJob(u32 jobType) const;
        u32 getSortNo() const;
        u32 getNameSortNo() const;
        rItemList::USE_CATEGORY getUseType() const;
        u32 getAttackStatus() const;
        bool isUnUseLobby() const;
        u32 getWepCategory() const;
        u32 getEquipCategory() const;
        EQUIP_SUB_CATEGORY getEquipSubCategory() const;
        bool isCanEquip(u32 slotType);
        bool isWeapon() const;
        bool isArmor() const;
        bool isCostume() const;
        u8 getPhysicalType() const;
        u8 getElementType() const;
        u32 getUseJob() const;
        u32 getUseLv() const;
        u16 getWight() const;
        bool isUseNpc() const;
        u8 getEleSlot() const;
        s8 getMaterialColNo() const;
        u8 getSex() const;
        u32 getModelTagId() const;
        u8 getModelParts() const;
        u8 getMontageHelmOffOffset() const;
        u32 getAttack() const;
        u32 getMagicAttack() const;
        u32 getPowerRev() const;
        u32 getShieldStagger() const;
        u32 getDefense() const;
        u32 getMagicDefense() const;
        u32 getDurability() const;
        u16 getMaxHpRev() const;
        u16 getMaxStRev() const;
        void getKindParamList(MtTypedArray<rItemList::rEquipParamS8>& list);
        u32 getChanceNum() const;
        u16 getVsEmParamVal(rItemList::rVsEnemyParam::EM_PHYLOGENY_KIND type);
        u32 getVsEmNum();
        rItemList::rVsEnemyParam* getVsEmParam(u32 index);
        u32 getItemParamNum();
        void setItemParamNum(u32);
        rItemList::rParam* getItemParam(u32 no);
        rItemList::rParam* getItemParam(rItemList::rParam::PARAM_KIND kind);
        u32 getItemParamToParam(rItemList::rParam::PARAM_KIND kind);
        u32 getItemInstructionNum();
    private:
        bool isWeaponElement();
        bool isProtectorElement();
    private:
        u32 mItemId;  // offset: 0x8
    public:
        u32 mNameId;  // offset: 0xc
    private:
        SUB_CATEGORY mCategory2;  // offset: 0x10
        u32 mPrice;  // offset: 0x14
        u32 mSortNo;  // offset: 0x18
        u32 mNameSortNo;  // offset: 0x1c
        u32 mAttackStatus;  // offset: 0x20
        u32 mIsUseJob;  // offset: 0x24
        rItemList::rParam* mpItemParamList;  // offset: 0x28
        u32 mParamNum;  // offset: 0x30
        rItemList::rVsEnemyParam* mpVsEmList;  // offset: 0x38
        u32 mVsEmNum;  // offset: 0x40
        rItemList::rWeaponParam* mpWeaponParam;  // offset: 0x48
        rItemList::rProtectorParam* mpProtectorParam;  // offset: 0x50
        u16 mFlag;  // offset: 0x58
        u16 mIconNo;  // offset: 0x5a
        u16 mIsUseLv;  // offset: 0x5c
        u8 mCategory;  // offset: 0x5e
        u8 mStackMax;  // offset: 0x5f
        u8 mRank;  // offset: 0x60
        u8 mGrade;  // offset: 0x61
        u8 mIconColNo;  // offset: 0x62
    public:
        static MyDTI DTI;
        static const u32 PARAM_MAX = 10;
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
    rItemList();
    virtual ~rItemList();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual u32 getListNum() const;  // vtable slot 16
    void releaseWork();
    virtual rItemParam* getItemList(u32 no) const;  // vtable slot 17
    virtual rItemParam* getItemListByIndex(u32 index) const;  // vtable slot 18
    virtual rItemParam* getItemListByArcTagNo(u32 arcTagNo) const;  // vtable slot 19
    void createIndexTable();
public:
    rItemParam* mpItemList;  // offset: 0x70
    u32 mArrayDataNum;  // offset: 0x78
    rParam* mpParamList;  // offset: 0x80
    u32 mArrayParamDataNum;  // offset: 0x88
    rVsEnemyParam* mpVsParamList;  // offset: 0x90
    u32 mArrayVsParamDataNum;  // offset: 0x98
    rWeaponParam* mpWeaponParamList;  // offset: 0xa0
    u32 mArrayWeaponParamDataNum;  // offset: 0xa8
    rProtectorParam* mpProtectParamList;  // offset: 0xb0
    u32 mArrayProtectParamDataNum;  // offset: 0xb8
    rEquipParamS8* mpEquipParamS8List;  // offset: 0xc0
    u32 mArrayEquipParamS8DataNum;  // offset: 0xc8
    u16* mpIndexTbl;  // offset: 0xd0
    u32 mMaxId;  // offset: 0xd8
    static MyDTI DTI;
    static const u32 GRADE_MAX = 5;
protected:
    static const u8 DATA_VERSION = 58;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: specialized to the arguments every copy passes (DW_AT_const_value; 023 T608, 2.7.0 specialized-constant constructors); approximate: no recompile checks its other arguments
inline rItemList::rVsEnemyParam::rVsEnemyParam(rItemList::rVsEnemyParam::EM_PHYLOGENY_KIND kind, u16 num) {
    this->mKindType = static_cast<u8>(0);
    this->mParam = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rItemList::rWeaponParam::rWeaponParam() {
    this->mWeight = static_cast<u16>(0);
    this->mMaxHpRev = static_cast<u16>(0);
    this->mMaxStRev = static_cast<u16>(0);
    this->mColorNo = static_cast<u8>(0);
    this->mAttack = static_cast<u32>(0);
    this->mMagicAttack = static_cast<u32>(0);
    this->mMagicDefense = static_cast<u32>(0);
    this->mDurability = static_cast<u32>(0);
    this->mChance = static_cast<u32>(0);
    this->mDefense = static_cast<u32>(0);
    this->mModelTagId = static_cast<u32>(0);
    this->mPowerRev = static_cast<u32>(0);
    this->mSex = static_cast<u8>(1);
    this->mWepCategory = static_cast<u8>(0);
    this->mShieldStagger = static_cast<u32>(0);
    this->mpEquipParamS8List = static_cast<rItemList::rEquipParamS8*>(nullptr);
    this->mEquipParamS8Num = static_cast<u8>(0);
    this->mModelParts = static_cast<u8>(0);
    this->mEleSlot = static_cast<u8>(0);
    this->mPhysicalType = static_cast<u8>(0);
    this->mElementType = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rItemList::rProtectorParam::rProtectorParam() {
    this->mAttack = static_cast<u32>(0);
    this->mMagicAttack = static_cast<u32>(0);
    this->mMagicDefense = static_cast<u32>(0);
    this->mDurability = static_cast<u32>(0);
    this->mChance = static_cast<u32>(0);
    this->mDefense = static_cast<u32>(0);
    this->mModelTagId = static_cast<u32>(0);
    this->mPowerRev = static_cast<u32>(0);
    this->mColorNo = static_cast<u8>(0);
    this->mMaxStRev = static_cast<u16>(0);
    this->mWeight = static_cast<u16>(0);
    this->mMaxHpRev = static_cast<u16>(0);
    this->mSex = static_cast<u8>(1);
    this->mModelParts = static_cast<u8>(0);
    this->mEleSlot = static_cast<u8>(0);
    this->mpEquipParamS8List = static_cast<rItemList::rEquipParamS8*>(nullptr);
    this->mEquipParamS8Num = static_cast<u8>(0);
}
