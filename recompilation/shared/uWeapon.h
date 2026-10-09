#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "nWeapon.h"
#include "uCnsWeapon.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtVector3;
class cWeaponResTable;
class rDDOModelMontage;
class rModel;
class uCnsWeapon;
class uModel;

// Declarations
class uWeapon;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_SEARCHID = u32;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u8 = unsigned char;

class uWeapon : public uDDOModel
{
public:
    enum WPN_MODE
    {
        WPN_MODE_DEFAULT = 0,
        WPN_MODE_HOLD = 1,
        WPN_MODE_NORMAL = 2,
        WPN_MODE_USE_DAMAGE_OFFSET = 3,
        WPN_MODE_FORCE_DAMAGE_OFFSET = 4,
        WPN_MODE_SPECIAL_OFFSET = 5,
        WPN_MODE_NUM = 6,
    };
    enum
    {
        CONST_OFFSET = 0,
        CONST_SKIN = 1,
        CONST_NUM = 2,
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
    uWeapon();
    virtual ~uWeapon();
    static uWeapon* createWeaponModel(nWeapon::WEAPON_CATEGORY wepCategory, cWeaponResTable* pWepResData, uModel* pParent, nWeapon::MODEL_TYPE model_type, u8 partsPatern, s8 colorPatern);
    static uWeapon* createWeaponModel(nWeapon::OTHER_MODEL_INDEX index, cWeaponResTable* pWepResData, uModel* pParent, u8 partsPatern, s8 colorPatern);
    static uWeapon* createWeaponModel(nWeapon::NPC_ITEM_INDEX index, uModel* pParent);
protected:
    static uWeapon* createWeaponModelCore(u32 index, cWeaponResTable* pWepResData, uModel* pParent, nWeapon::MODEL_TYPE model_type, u8 partsPatern, s8 colorPatern);
public:
    virtual void setup();  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void updateOffset();
    void callbackUpdateMatrix();
    void callbackSetMotion(u32 src, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr);
    void setWepCategory(nWeapon::WEAPON_CATEGORY wepCategory);
    nWeapon::WEAPON_CATEGORY getWepCategory();
    cWeaponResTable* getArchiveInfo();
    void setWeaponMode(WPN_MODE mode);
    WPN_MODE getWeaponMode();
    static u32 getNpcItemArcTag(u32 index);
    rModel* getModelRes();
    u8 getModelType();
    u8 getOtherInfo();
    u32 getHideInfo();
    void setParts(u8 partsPatern);
    void setParts(ARC_TAGID ArcTagId, ARC_SEARCHID SearchId, u8 partsPatern);
    void setColor(s8 colorPatern);
    void setColor(ARC_TAGID ArcTagId, ARC_SEARCHID SearchId, s8 colorPatern);
    uModel* getOwner();
public:
    WPN_MODE mMode;  // offset: 0x246c
    WPN_MODE mStatus;  // offset: 0x2470
    u32 mOffsetNo;  // offset: 0x2474
    bool mDisp;  // offset: 0x2478
    u8 mPartsPatern;  // offset: 0x2479
    s8 mColorPatern;  // offset: 0x247a
    u8 mModelType;  // offset: 0x247b
    u8 mOtherInfo;  // offset: 0x247c
    u32 mHideInfo;  // offset: 0x2480
    rDDOModelMontage* mpMontage;  // offset: 0x2488
    u32 mMontageType;  // offset: 0x2490
    nWeapon::WEAPON_CATEGORY mWepCategory;  // offset: 0x2494
    uModel* mpOwner;  // offset: 0x2498
    cWeaponResTable* mpWepResData;  // offset: 0x24a0
    rModel* mpModelRes;  // offset: 0x24a8
    u32 mConstType;  // offset: 0x24b0
    s32 mCnsJointNo[4];  // offset: 0x24b4
    f32 mCnsFat[4];  // offset: 0x24c4
    MtVector3 mCnsRot[4];  // offset: 0x24e0
    MtVector3 mCnsTrans[4];  // offset: 0x2520
    MtTypedArray<uCnsWeapon> mCnsWeapon;  // offset: 0x2560
    MtMatrix mOffsetRot;  // offset: 0x2580
    MtVector3 mOffsetTrans;  // offset: 0x25c0
    u32 mCnsJntNo;  // offset: 0x25d0
    f32 mWeaponScale;  // offset: 0x25d4
    f32 mFatRate;  // offset: 0x25d8
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cWeaponResTable* uWeapon::getArchiveInfo() {
    return this->mpWepResData;
}

// Inline, no code of its own: checked where it is inlined.
inline uModel* uWeapon::getOwner() {
    return this->mpOwner;
}
