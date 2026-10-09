#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cpComponent.h"
#include "nCharacterData.h"
#include "nWeapon.h"
#include "sBakingJointOrder.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cArcLoaderBase;
class cBakeModel;
class cDDMaterialCtrl;
class cItemParam;
class cWeaponResTable;
namespace nDraw { class Material; }
class rDDOModelMontage;
class rEquipPartsInfo;
class rEquipPreset;
class rItemList;
class rModel;
class rPlPartsInfo;
class rWeaponResTable;
class uArmor;
class uModel;
class uWeapon;

// Declarations
class cpEquip;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cpEquip : public cpComponent
{
public:
    enum BAKE_TYPE
    {
        BAKE_TYPE_NONE = 0,
        BAKE_TYPE_SOLID = 1,
        BAKE_TYPE_SOFT = 2,
    };
    enum
    {
        MONTAGE_TYPE_PATTERN = 0,
        MONTAGE_TYPE_PATTERN_AND_COLOR = 1,
    };
    enum
    {
        WEAPON_MAIN = 0,
        WEAPON_SUB = 1,
        WEAPON_MAIN2 = 2,
        WEAPON_SUB2 = 3,
        WEAPON_MAX = 4,
    };
    enum
    {
        WEAR_BODY = 0,
        WEAR_LEG = 1,
        ARMOR_HELM = 2,
        ARMOR_BODY = 3,
        ARMOR_ARM = 4,
        ARMOR_LEG = 5,
        ARMOR_ACCESSORY = 6,
        ARMOR_MAX = 7,
        SPECIAL_ARMOR_INIT = 7,
        SPECIAL_ARMOR_AO = 7,
        SPECIAL_ARMOR_END = 8,
        ALL_ARMOR_NUM = 8,
    };
    enum
    {
        FLAG_WEAPON_CTRL_OFF = 1,
    };
public:
    class MyDTI;
    struct stRequestArc;
    struct stItemData;
    class cEquipInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stItemData
    {
    public:
        stItemData();
        stItemData(u32, s32);
    public:
        u32 mId;  // offset: 0x0
        s32 mColor;  // offset: 0x4
    };
public:
    class cEquipInfo : public MtObject
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
        cEquipInfo();
        virtual ~cEquipInfo();
        void clear();
        u32 getMaterialNum();
        nDraw::Material* getMaterial(u32 index);
        cBakeModel* getBakeModel();
        void releaseDDMrlCtrl();
        void updatePtr();
        void move(cpEquip* const pCpEquip);
    public:
        bool mUpdate;  // offset: 0x8
        uModel* mpModel;  // offset: 0x10
        rModel* mpModelRes;  // offset: 0x18
        uModel* mpOwner;  // offset: 0x20
        cWeaponResTable* mpWepResData;  // offset: 0x28
        u8 mPartsPatern;  // offset: 0x30
        s8 mColorPatern;  // offset: 0x31
        u8 mModelType;  // offset: 0x32
        u8 mOtherInfo;  // offset: 0x33
        u32 mHideInfo;  // offset: 0x34
        rDDOModelMontage* mpMontage;  // offset: 0x38
        u32 mMontageType;  // offset: 0x40
        nWeapon::WEAPON_CATEGORY mWepCategory;  // offset: 0x44
        cpEquip::BAKE_TYPE mBakeType;  // offset: 0x48
        u8 mBakeIndex;  // offset: 0x4c
        sBakingJointOrder::BAKE_HANDLE mBakeHandle;  // offset: 0x50
        cDDMaterialCtrl* mpDDMrlCtrl;  // offset: 0x58
        static MyDTI DTI;
    };
public:
    struct stRequestArc
    {
    public:
        TICKET mTicket;  // offset: 0x0
        cpEquip::stItemData mNowItem;  // offset: 0x8
        cpEquip::stItemData mLoadingItem;  // offset: 0x10
        cpEquip::stItemData mNextItem;  // offset: 0x18
        bool mIsLoading;  // offset: 0x20
        bool mIsOff;  // offset: 0x21
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
    cpEquip();
    virtual ~cpEquip();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    void compMoveAfter();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void callbackSetMotion(u32 src, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr);
    void setWeapon(u32 index, uWeapon* pWpn);
    uWeapon* getWeapon(u32 index);
    cEquipInfo* getWeaponInfo(u32 index);
    void setArmor(u32 index, uArmor* pArmor);
    uArmor* getArmor(u32 index);
    cEquipInfo* getArmorInfo(u32 index);
    void setHair(uArmor* pHair);
    uArmor* getHair();
    cEquipInfo* getHairInfo();
    void setBeard(uArmor* pBeard);
    uArmor* getBeard();
    cEquipInfo* getBeardInfo();
    void setMakeup(uArmor* pMakeup);
    uArmor* getMakeup();
    cEquipInfo* getMakeupInfo();
    void setUnderwear(uArmor* pUnderwear);
    uArmor* getUnderwear();
    cEquipInfo* getUnderwearInfo();
    void setUnderwear2(uArmor* pUnderwear2);
    uArmor* getUnderwear2();
    cEquipInfo* getUnderwear2Info();
    void setLantern(uWeapon* pLantern);
    uWeapon* getLantern();
    cEquipInfo* getLanternInfo();
    void setNpcItem(uWeapon* pNpcItem);
    uWeapon* getNpcItem();
    cEquipInfo* getNpcItemInfo();
    void killAllWeapon();
    void killAllArmor();
    void killAllEquip();
    void killWeapon(u32 index);
    void killArmor(u32 index);
    void killHair();
    void killBeard();
    void killMakeup();
    void killUnderwear();
    void killUnderwear2();
    void killLantern();
    void killNpcItem();
    void updateWeaponCtrl();
    void resetWeaponCtrl();
    bool checkUpdateArmor();
    void updateArmor();
    void setEquipPreset(rEquipPreset* pEquipPreset, u32 option);
    void updateEquipPreset();
    void requestLoadEquip(u32 itemID, u8 colorNo);
    void removeEquip(const nCharacterData::EQUIP_SLOT_TYPE category);
    bool setEquip(u32 itemID, u32 colorNo, u32 sex, const cItemParam* pItemParam, const cItemParam* pPerformanceParam, bool isDefaultDisp);
    rEquipPreset* getEquipPreset();
    void changeArmor(u64 ResId, u32 index, u8 partsPatern, s8 colorPatern);
    void changeWeapon(nWeapon::WEAPON_CATEGORY wepCategory, u64 ResId, u32 index, u8 partsPatern, s8 colorPatern);
    void resetSimulation();
    void setGrassWind(bool isGrassWind);
    void onFlag(u32 flag);
    void offFlag(u32);
    bool isFlag(u32);
    void setFlag(u32);
    u32 getFlag();
    bool isEquipPartsDisp(u32 no) const;
    void setEquipPartsDisp(bool disp, u32 no);
    void killAllArmorBJ();
    void killHairBJ();
    void killBeardBJ();
    void killMakeupBJ();
    void killUnderwearBJ();
    void killUnderwear2BJ();
    void killNpcItemBJ();
    void killWeaponBJ(u32 index);
    void applyAllArmorMontage();
    void dispWeaponInMyRoom();
protected:
    void setWeaponCtrl(nWeapon::WPN_MODEL_INDEX index, nWeapon::WPN_CTRL cmd, bool flag);
    void setWeaponDisp(nWeapon::WPN_MODEL_INDEX index, bool flag);
    static void applyPrimeFieldParts(MtObject* pObj);
    static void setPrimeFieldParts(uModel* pModel, s32 parts, cpEquip* pEquip);
    static void applyPrimeFieldPartsBJ(MtObject* pObj);
    static void setPrimeFieldPartsBJ(uModel* pModel, s32 parts, cpEquip* pEquip);
    u32 convEquipCatgoryToArmorIndex(u32 equip_category);
protected:
    stRequestArc mReqestArc[15];  // offset: 0x50
    u32 mFlag;  // offset: 0x2a8
    uModel* mpModel;  // offset: 0x2b0
    cEquipInfo mWeapon[4];  // offset: 0x2b8
    cEquipInfo mArmor[7];  // offset: 0x438
    u32 mEquipPartsDisp[16];  // offset: 0x6d8
    cEquipInfo mHair;  // offset: 0x718
    cEquipInfo mMakeup;  // offset: 0x778
    cEquipInfo mBeard;  // offset: 0x7d8
    cEquipInfo mUnderwear;  // offset: 0x838
    cEquipInfo mUnderwear2;  // offset: 0x898
    cEquipInfo mLantern;  // offset: 0x8f8
    cEquipInfo mNpcItem;  // offset: 0x958
    rItemList* mpItemList;  // offset: 0x9b8
    rWeaponResTable* mpWeaponResTable;  // offset: 0x9c0
    rEquipPreset* mpEquipPresetRes;  // offset: 0x9c8
    rPlPartsInfo* mpPartsInfo;  // offset: 0x9d0
    rEquipPartsInfo* mpEquipPartsInfo;  // offset: 0x9d8
    bool mUpdate;  // offset: 0x9e0
    bool mUpdateEquipPresetReq;  // offset: 0x9e1
    u32 mPresetOption;  // offset: 0x9e4
public:
    static MyDTI DTI;
    static const u32 PARTS_ID_BRASSIERE = 250;
    static const u32 PARTS_ID_TROUSERES = 251;
    static const u32 PARTS_ID_BREAST = 5;
    static const u32 PARTS_ID_WAIST = 8;
    static const u32 PARTS_ID_WB_WITHOUT_HAND = 100;
    static const u32 PARTS_ID_WL_WITHOUT_FOOT = 110;
};
