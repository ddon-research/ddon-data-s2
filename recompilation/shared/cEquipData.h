#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cItemParam.h"
#include "nCharacterData.h"
#include "rItemList.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cItemParam;
namespace nCharacterData { struct stEquipData; }
namespace nEquipDataJewelry { class cJewelryData; }
class uDDOModel;
class uHuman;

// Declarations
class cEquipData;
namespace nEquipAbilityInfo { class cEquipAbilityData; }

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

namespace nEquipAbilityInfo {
    class cEquipAbilityData : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cEquipAbilityData();
        cEquipAbilityData(u32, s32);
        // Address: 0x0196dcf0 - 0x0196dcf1 (1 bytes)
        virtual ~cEquipAbilityData() {}
        u32 getID() const;
        void setID(u32 Id);
        s32 getLv() const;
        void setLv(s32 Lv);
    private:
        u32 mId;  // offset: 0x8
        s32 mLv;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
}  // namespace nEquipAbilityInfo

class cEquipData : public MtObject
{
    // inferred: uHuman::makeOcdAttackInfoCore names cEquipData::mKindParamU16[0]
    friend class uHuman;
public:
    enum
    {
        EQUIP_OPT_VISUAL_ON = 0,
        EQUIP_OPT_HELM_OFF = 1,
        EQUIP_OPT_LANTERN_OFF = 2,
        EQUIP_OPT_NUM = 3,
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
    cEquipData();
    virtual ~cEquipData();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setEquipFromCharacterData(const nCharacterData::stEquipData& src);
    void retEquipToCharacterData(nCharacterData::stEquipData& dst) const;
    void setHumanEnemyEquip(u32 presetId, u32 seed);
    void copyEquipData(cEquipData* pSrc);
    cEquipData& operator=(const cEquipData& source);
    static u32 convEquipCateToIndex(nCharacterData::EQUIP_SLOT_TYPE category);
    static u32 convEquipCateWepToIndex(nCharacterData::EQUIP_SLOT_TYPE category);
    static nCharacterData::EQUIP_SLOT_TYPE convEquipCateToSlotType(nCharacterData::EQUIP_CATEGORY equip_category);
    static nCharacterData::EQUIP_CATEGORY convSlotTypeToEquipCate(nCharacterData::EQUIP_SLOT_TYPE slot_type);
    static bool isWepCategory(nCharacterData::EQUIP_SLOT_TYPE category);
    static u32 convEquipCateArmorToIndex(nCharacterData::EQUIP_SLOT_TYPE category);
    static bool isArmorCategory(nCharacterData::EQUIP_SLOT_TYPE category);
    static nCharacterData::EQUIP_SLOT_TYPE convIndexToEquipCate(u32 index);
    static u32 getEquipCategoryNum();
    bool checkEquipCategory(nCharacterData::EQUIP_SLOT_TYPE category);
    void init();
    u8 getPresetMax() const;
    u8 getPresetNum() const;
    void setEquipVisual(bool flag);
    bool checkEquipVisual() const;
    void setHelmVisualOff(bool flag);
    bool checkHelmVisualOff() const;
    bool checkHelmVisualChange();
    void setLanternVisualOff(bool flag);
    bool checkLanternVisualOff() const;
    bool checkLanternVisualChange();
    u8 getEquipOpt() const;
    void setEquipOpt(u8);
    u8 getJewelrySlotNum() const;
    void setJewelrySlotNum(u8 Num);
    const cItemParam* getEquipParam(u8 category, u8 type, bool isMarge) const;
    u16 getEquip(u8 category, u8 type, bool isMarge) const;
    bool isCostume(nCharacterData::EQUIP_TYPE type) const;
    void setEquip(u8 category, u8 type, const cItemParam* pItem);
    void setEquipNoItemParam(u8 category, u8 type, u32 id);
    bool isEquipChangeAll(u8 type, bool isMarge);
    bool isEquipChange(u8 type, u32 category, bool isMarge);
    bool isEquipVisualExceptArmor() const;
    void condisionInit();
    void condisionReset(u8 type, bool isMarge);
    void setEquipCondition(u8 category, bool condition);
    bool getEquipCondition(u8 category);
    bool isLanternEquip();
    void setAbilityUse(bool isUse);
    u32 calcCrestElement(u32* pParam, u32* pType, u32 wepElement);
    u32 getAttack() const;
    u32 getMagicAttack() const;
    u32 getPowerRev() const;
    u32 getShieldStagger() const;
    u32 getShieldStamina() const;
    u32 getTShieldStorage() const;
    u32 getTShieldStorageForUI() const;
    u32 getPoisonSav() const;
    u32 getSlowSav() const;
    u32 getOilSav() const;
    u32 getBlindSav() const;
    u32 getSleepSav() const;
    u32 getWaterSav() const;
    u32 getSealSav() const;
    u32 getSoftBodySav() const;
    u32 getStoneSav() const;
    u32 getGoldSav() const;
    u32 getSpredSav() const;
    u32 getFreezeSav() const;
    u32 getShockSav() const;
    u32 getCrossSav() const;
    u32 getStanSav() const;
    u32 getFallFireSav() const;
    u32 getFallIceSav() const;
    u32 getFallThunderSav() const;
    u32 getFallSaintSav() const;
    u32 getFallBlindSav() const;
    u32 getFallAttackSav() const;
    u32 getFallDefSav() const;
    u32 getFallMagicSav() const;
    u32 getFallMagicDefSav() const;
    u32 getDefense() const;
    u32 getMagicDefense() const;
    u32 getDurability() const;
    u32 getSpirit() const;
    u32 getVsEm(u8 type) const;
    u32 getMainWepPhysical() const;
    u32 getSubWepPhysical() const;
    u32 getMainWepElement() const;
    u32 getSubWepElement() const;
    u32 getChanceNum() const;
    u16 getMaxHpRev() const;
    u16 getMaxStRev() const;
    s16 getFireEleDef() const;
    s16 getIceEleDef() const;
    s16 getThunderEleDef() const;
    s16 getSaintEleDef() const;
    s16 getDarkEleDef() const;
    s16 getPoisonDef() const;
    s16 getSlowDef() const;
    s16 getOilDef() const;
    s16 getBlindDef() const;
    s16 getSleepDef() const;
    s16 getWaterDef() const;
    s16 getSealDef() const;
    s16 getSoftBodyDef() const;
    s16 getStoneDef() const;
    s16 getGoldDef() const;
    s16 getSpredDef() const;
    s16 getFreezeDef() const;
    s16 getShockDef() const;
    s16 getCrossDef() const;
    s16 getStanDef() const;
    s16 getCurseDef() const;
    s16 getFallFireDef() const;
    s16 getFallIceDef() const;
    s16 getFallThunderDef() const;
    s16 getFallSaintDef() const;
    s16 getFallBlindDef() const;
    s16 getFallAttackDef() const;
    s16 getFallDefenceDef() const;
    s16 getFallMagicAttackDef() const;
    s16 getFallMagicDefenceDef() const;
    s16 getErosionDef() const;
    s16 getItemSealDef() const;
    u16 getWeight() const;
    u8 getArrowNum() const;
    u8 getAwakeParam() const;
    u32 getArrowEquip(nCharacterData::ARROW_EQUIP index) const;
    void setArrowEquip(nCharacterData::ARROW_EQUIP index, u32 id);
    void updateEquipData();
    void attachCraftEnchantElement(uDDOModel* pTarget, bool isMain);
    u32 getItemRankAverage() const;
    u32 getMainWeaponItemRank() const;
    u32 getItemAbilityNum() const;
    void getItemAbilityData(u32 index, u32* pAbilityId, s32* pLv) const;
    void getItemAbilityData(MtTypedArray<nEquipAbilityInfo::cEquipAbilityData>& list);
    void getJewelryKindNum(MtTypedArray<nEquipDataJewelry::cJewelryData>& list) const;
private:
    void calcStatus();
    u32 convElementType(rItemList::rItemParam::ELEMENT_TYPE type);
    void calcWeightDownElement(rItemList::rParam* pElementParam);
    void calcSpredSavUpElement(rItemList::rParam* pElementParam);
    void calcFreezeSavUpElement(rItemList::rParam* pElementParam);
    void calcShockSavUpElement(rItemList::rParam* pElementParam);
    void calcCrossSavUpElement(rItemList::rParam* pElementParam);
    void calcBlindSavUpElement(rItemList::rParam* pElementParam);
    void calcAttackUpElement(rItemList::rParam* pElementParam);
    void calcMagicAttackUpElement(rItemList::rParam* pElementParam);
    void calcPowerRevUpElement(rItemList::rParam* pElementParam);
    void calcStanSavUpElement(rItemList::rParam* pElementParam);
    void calcPoisonSavUpElement(rItemList::rParam* pElementParam);
    void calcSlowSavUpElement(rItemList::rParam* pElementParam);
    void calcSleepSavUpElement(rItemList::rParam* pElementParam);
    void calcWaterSavUpElement(rItemList::rParam* pElementParam);
    void calcOilSavUpElement(rItemList::rParam* pElementParam);
    void calcSealSavUpElement(rItemList::rParam* pElementParam);
    void calcSoftBodySavUpElement(rItemList::rParam* pElementParam);
    void calcStoneSavUpElement(rItemList::rParam* pElementParam);
    void calcGoldSavUpElement(rItemList::rParam* pElementParam);
    void calcFallFireSavUpElement(rItemList::rParam* pElementParam);
    void calcFallIceSavUpElement(rItemList::rParam* pElementParam);
    void calcFallThunderSavUpElement(rItemList::rParam* pElementParam);
    void calcFallSaintSavUpElement(rItemList::rParam* pElementParam);
    void calcFallBlindSavUpElement(rItemList::rParam* pElementParam);
    void calcFallAttackSavUpElement(rItemList::rParam* pElementParam);
    void calcFallDefSavUpElement(rItemList::rParam* pElementParam);
    void calcFallMagicSavUpElement(rItemList::rParam* pElementParam);
    void calcFallMagicDefSavUpElement(rItemList::rParam* pElementParam);
    void calcDefenceUpElement(rItemList::rParam* pElementParam);
    void calcMagicDefenseUpElement(rItemList::rParam* pElementParam);
    void calcDurabilityUpElement(rItemList::rParam* pElementParam);
    void calcSpiritUpElement(rItemList::rParam* pElementParam);
    void calcHPUpElement(rItemList::rParam* pElementParam);
    void calcSTUpElement(rItemList::rParam* pElementParam);
    void calcShinRyokuRevUpElement(rItemList::rParam* pElementParam);
    void calcFireEleDefUpElement(rItemList::rParam* pElementParam);
    void calcIceEleDefUpElement(rItemList::rParam* pElementParam);
    void calcThunderEleDefUpElement(rItemList::rParam* pElementParam);
    void calcSaintEleDefUpElement(rItemList::rParam* pElementParam);
    void calcDarkEleDefUpElement(rItemList::rParam* pElementParam);
    void calcSpredDefUpElement(rItemList::rParam* pElementParam);
    void calcFreezeDefUpElement(rItemList::rParam* pElementParam);
    void calcShockDefUpElement(rItemList::rParam* pElementParam);
    void calcCrossDefUpElement(rItemList::rParam* pElementParam);
    void calcBlindDefUpElement(rItemList::rParam* pElementParam);
    void calcPoisonDefUpElement(rItemList::rParam* pElementParam);
    void calcSlowDefUpElement(rItemList::rParam* pElementParam);
    void calcSleepDefUpElement(rItemList::rParam* pElementParam);
    void calcStanDefUpElement(rItemList::rParam* pElementParam);
    void calcWaterDefUpElement(rItemList::rParam* pElementParam);
    void calcOilDefUpElement(rItemList::rParam* pElementParam);
    void calcSealDefUpElement(rItemList::rParam* pElementParam);
    void calcCurseDefUpElement(rItemList::rParam* pElementParam);
    void calcSoftBodyDefUpElement(rItemList::rParam* pElementParam);
    void calcStoneDefUpElement(rItemList::rParam* pElementParam);
    void calcGoldDefUpElement(rItemList::rParam* pElementParam);
    void calcFallFireDefUpElement(rItemList::rParam* pElementParam);
    void calcFallIceDefUpElement(rItemList::rParam* pElementParam);
    void calcFallThunderDefUpElement(rItemList::rParam* pElementParam);
    void calcFallSaintDefUpElement(rItemList::rParam* pElementParam);
    void calcFallBlindDefUpElement(rItemList::rParam* pElementParam);
    void calcFallAttackDefUpElement(rItemList::rParam* pElementParam);
    void calcFallDefenceDefUpElement(rItemList::rParam* pElementParam);
    void calcFallMagicAttackDefUpElement(rItemList::rParam* pElementParam);
    void calcFallMagicDefenceDefUpElement(rItemList::rParam* pElementParam);
    void calcVsEm00UpElement(rItemList::rParam* pElementParam);
    void calcVsEm01UpElement(rItemList::rParam* pElementParam);
    void calcVsEm02UpElement(rItemList::rParam* pElementParam);
    void calcVsEm03UpElement(rItemList::rParam* pElementParam);
    void calcVsEm04UpElement(rItemList::rParam* pElementParam);
    void calcVsEm05UpElement(rItemList::rParam* pElementParam);
    void calcVsEm06UpElement(rItemList::rParam* pElementParam);
    void calcVsEm07UpElement(rItemList::rParam* pElementParam);
    void calcVsEm08UpElement(rItemList::rParam* pElementParam);
    void calcVsEm09UpElement(rItemList::rParam* pElementParam);
    void calcVsEm10UpElement(rItemList::rParam* pElementParam);
    void calcVsEm11UpElement(rItemList::rParam* pElementParam);
    void calcVsEm12UpElement(rItemList::rParam* pElementParam);
    void calcVsEm13UpElement(rItemList::rParam* pElementParam);
    void calcVsEm14UpElement(rItemList::rParam* pElementParam);
    void calcVsEm15UpElement(rItemList::rParam* pElementParam);
    void calcColorElement(rItemList::rParam* pElementParam);
    void calcDashStUpElement(rItemList::rParam* pElementParam);
    void calcJumpUpElement(rItemList::rParam* pElementParam);
    void calcClimeSpdUpElement(rItemList::rParam* pElementParam);
    void calcAwakeningWeightLightryElement(rItemList::rParam* pElementParam);
    void calcLowLvExpUpElement(rItemList::rParam* pElementParam);
    void calcAbilityElement(rItemList::rParam* pElementParam);
    void calcAbnormalParamS8(rItemList::KIND_TYPE type, s8 value);
    void calcEleParamS8(rItemList::KIND_TYPE type, u16 value);
    void calcAbnormalParamU8(rItemList::KIND_TYPE type, u8 value);
    void calcEleParamU8(rItemList::KIND_TYPE type, u16 value);
    void calcAbnormalParamS16(rItemList::KIND_TYPE type, s16 value);
    void calcEleParamS16(rItemList::KIND_TYPE type, u16 value);
    void calcAbnormalParamU16(rItemList::KIND_TYPE type, u16 value);
    void calcEleParamU16(rItemList::KIND_TYPE type, u16 value);
private:
    cItemParam mEquip[2][15];  // offset: 0x8
    u32 mEquipOld[15];  // offset: 0xe18
    u8 mColorOld[15];  // offset: 0xe54
    bool mIsEquipCondition[15];  // offset: 0xe63
    u16 mPreset[10][2][15];  // offset: 0xe72
    u8 mPresetMax;  // offset: 0x10ca
    u8 mPresetNum;  // offset: 0x10cb
    u8 mEquipOpt;  // offset: 0x10cc
    u8 mEquipOptOld;  // offset: 0x10cd
    u8 mJewelrySlotNum;  // offset: 0x10ce
    u32 mArrowEquip[2];  // offset: 0x10d0
    u32 mStAttack;  // offset: 0x10d8
    u32 mStMagicAttack;  // offset: 0x10dc
    u32 mStPowerRev;  // offset: 0x10e0
    u32 mStShieldStagger;  // offset: 0x10e4
    u32 mStDefense;  // offset: 0x10e8
    u32 mStMagicDefense;  // offset: 0x10ec
    u32 mStDurability;  // offset: 0x10f0
    u32 mStChanceNum;  // offset: 0x10f4
    u32 mStVsEm[17];  // offset: 0x10f8
    u32 mMainWepPhysical;  // offset: 0x113c
    u32 mSubWepPhysical;  // offset: 0x1140
    u32 mMainWepElement;  // offset: 0x1144
    u32 mMainWepElementOld;  // offset: 0x1148
    u32 mSubWepElement;  // offset: 0x114c
    u32 mSubWepElementOld;  // offset: 0x1150
    u16 mStMaxHpRev;  // offset: 0x1154
    u16 mStMaxStRev;  // offset: 0x1156
    u32 mKindParamU16[24];  // offset: 0x1158
    s32 mKindParamS16[5];  // offset: 0x11b8
    u16 mKindParamU8[4];  // offset: 0x11cc
    s16 mKindParamS8[27];  // offset: 0x11d4
    u16 mStWeight;  // offset: 0x120a
    u8 mAwakeParam;  // offset: 0x120c
    bool mIsAbilityUse;  // offset: 0x120d
    nEquipAbilityInfo::cEquipAbilityData mAbilityData[5];  // offset: 0x1210
    u8 mAbilityNum;  // offset: 0x1260
public:
    static MyDTI DTI;
private:
    static const nCharacterData::EQUIP_SLOT_TYPE mEquipTbl[];
    static const bool mCostumeDisableSlotTbl[];
    static const nCharacterData::EQUIP_SLOT_TYPE mEquipWepTbl[];
    static const nCharacterData::EQUIP_SLOT_TYPE mEquipArmorTbl[];
};

// Inline, no code of its own: checked where it is inlined.
inline nEquipAbilityInfo::cEquipAbilityData::cEquipAbilityData() {
    this->mId = static_cast<u32>(0);
    this->mLv = static_cast<s32>(0);
}
