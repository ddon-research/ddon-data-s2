#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../generated/shared/nWeapon.h"
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

inline void* uWeapon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cWeaponResTable* uWeapon::getArchiveInfo() {
    return this->mpWepResData;
}

inline rModel* uWeapon::getModelRes() {
    return this->mpModelRes;
}

inline uModel* uWeapon::getOwner() {
    return this->mpOwner;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* uWeapon::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uWeapon::DTI)->memAlloc(sz, align, ::uWeapon::DTI.::MtDTI::getID());
}

inline void uWeapon::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uWeapon::DTI)->memFree(p_addr);
}

inline uWeapon::uWeapon() {
    this->mpOwner = nullptr;
    this->mCnsJointNo[0] = -1;
    this->mCnsJointNo[1] = -1;
    this->mCnsRot[0].x = ::MtVector3::Zero.x;
    this->mCnsRot[0].y = ::MtVector3::Zero.y;
    this->mCnsRot[0].z = ::MtVector3::Zero.z;
    this->mCnsRot[0].pad_ = 0.0f;
    this->mCnsTrans[1].x = ::MtVector3::Zero.x;
    this->mCnsTrans[1].y = ::MtVector3::Zero.y;
    this->mCnsTrans[1].z = ::MtVector3::Zero.z;
    this->mCnsTrans[1].pad_ = 0.0f;
    this->mCnsTrans[0].x = this->mCnsTrans[1].x;
    this->mCnsTrans[0].y = this->mCnsTrans[1].y;
    this->mCnsTrans[0].z = this->mCnsTrans[1].z;
    this->mCnsTrans[0].pad_ = 0.0f;
    this->mMode = static_cast<uWeapon::WPN_MODE>(0);
    this->mStatus = static_cast<uWeapon::WPN_MODE>(2);
    this->mWepCategory = static_cast<nWeapon::WEAPON_CATEGORY>(0);
    this->mpWepResData = nullptr;
    this->mOffsetRot.m[0].x = ::MtMatrix::Identity.m[0].x;
    this->mOffsetRot.m[0].y = ::MtMatrix::Identity.m[0].y;
    this->mOffsetRot.m[0].z = ::MtMatrix::Identity.m[0].z;
    this->mOffsetRot.m[0].w = ::MtMatrix::Identity.m[0].w;
    this->mOffsetRot.m[1].x = ::MtMatrix::Identity.m[1].x;
    this->mOffsetRot.m[1].y = ::MtMatrix::Identity.m[1].y;
    this->mOffsetRot.m[1].z = ::MtMatrix::Identity.m[1].z;
    this->mOffsetRot.m[1].w = ::MtMatrix::Identity.m[1].w;
    this->mOffsetRot.m[2].x = ::MtMatrix::Identity.m[2].x;
    this->mOffsetRot.m[2].y = ::MtMatrix::Identity.m[2].y;
    this->mOffsetRot.m[2].z = ::MtMatrix::Identity.m[2].z;
    this->mOffsetRot.m[2].w = ::MtMatrix::Identity.m[2].w;
    this->mOffsetRot.m[3].x = ::MtMatrix::Identity.m[3].x;
    this->mOffsetRot.m[3].y = ::MtMatrix::Identity.m[3].y;
    this->mOffsetRot.m[3].z = ::MtMatrix::Identity.m[3].z;
    this->mOffsetRot.m[3].w = ::MtMatrix::Identity.m[3].w;
    this->mOffsetTrans.x = ::MtVector3::Zero.x;
    this->mOffsetTrans.y = ::MtVector3::Zero.y;
    this->mOffsetTrans.z = ::MtVector3::Zero.z;
    this->mOffsetTrans.pad_ = 0.0f;
    this->mCnsJntNo = 255;
    this->mWeaponScale = 1.0f;
    this->mFatRate = 1.0f;
    this->mOffsetNo = 0;
    this->mConstType = 0;
    this->mPartsPatern = 0;
    this->mColorPatern = -1;
    this->mModelType = 10;
    this->mOtherInfo = 0;
    this->mHideInfo = 0;
    this->mpMontage = nullptr;
    this->mMontageType = 0;
    this->mpModelRes = nullptr;
    this->mDisp = true;
}
