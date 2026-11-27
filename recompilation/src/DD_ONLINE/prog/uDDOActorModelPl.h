#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "nCharacterData.h"
#include "uDDOActorModel.h"
#include "../../XFramework/uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector4;
class cContextInstHm;
class cDraw;
class cpBakeJointHuman;
class cpCharacterEdit;
class cpEquip;
class cpJointOrder;
class cpMotionFilter;
class cpTinyChain;
class rNpcEditData;
class uFullbodyIKHuman2;
class uWeapon;

// Declarations
class uDDOActorModelPl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uDDOActorModelPl : public uDDOActorModel
{
public:
    enum UNIT_TYPE
    {
        UNIT_MY_PLAYER = 0,
        UNIT_OTHER_PLAYER = 1,
        UNIT_MAIN_PAWN = 2,
        UNIT_NPC = 3,
    };
    enum
    {
        WPN_HOLD_NORMAL = 0,
        WPN_HOLD_OFFSET = 1,
        WPN_HOLD_HIDE = 2,
        WPN_HOLD_WEAPON_NULL = 3,
    };
public:
    class MyDTI;
    class cColorCtrl;
public:
    using CalcWMatFunctionEx = void(uDDOActorModelPl::*)(uModel::Joint*);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cColorCtrl : public MtObject
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
        cColorCtrl();
        virtual ~cColorCtrl() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        s32 mMatNo;  // offset: 0x8
        MtVector4 mColor;  // offset: 0x10
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
    uDDOActorModelPl();
    virtual ~uDDOActorModelPl();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void createComponent();
    void initModel(u32 body_type);
    void initContext();
    void initCharacterEdit();
    void initIK();
    void initJointEx();
    void initWeapon();
    virtual void initEquip();  // vtable slot 45
    void initJointOrder();
    void createGunUnit();
    u32 getWeaponHold();
    s32 getArmorIndex(nCharacterData::EQUIP_SLOT_TYPE category);
    virtual bool isOkMrlCtrl();  // vtable slot 43
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setCommonState(cDraw* pdraw);  // vtable slot 32
    virtual void updateWorldMatrix();  // vtable slot 26
protected:
    void calcWMat(uModel::Joint* pwk);
    void calcWMatScaleInherit(uModel::Joint* pwk);
    void calcWMatScaleGlobal(uModel::Joint* pwk);
    void calcWMatNoScale(uModel::Joint* pwk);
    void updateJointWorldMatrixEx(const u8* jointTable, const u32 jointNum, const u32 updateWorldMode);
    void updateCharacterEdit();
public:
    void setUnitType(u32 type);
    u32 getUnitType();
    void setUnitNo(u32 no);
    u32 getUnitNo();
    void setWeaponDisp(uWeapon* pWpn);
    cContextInstHm* getContext();
protected:
    rNpcEditData* getNpcEquipRes() const;
    void setNpcEquipRes(rNpcEditData* pRes);
public:
    cpCharacterEdit* mpCharacterEdit;  // offset: 0x25e0
    cpEquip* mpEquip;  // offset: 0x25e8
    cpTinyChain* mpTinyChain;  // offset: 0x25f0
    cpBakeJointHuman* mpBakeJoint;  // offset: 0x25f8
    cpJointOrder* mpJointOrder;  // offset: 0x2600
    uFullbodyIKHuman2* mpFBIK;  // offset: 0x2608
    cpMotionFilter* mpMotionFilter;  // offset: 0x2610
private:
    bool mEnable;  // offset: 0x2618
    u32 mUnitType;  // offset: 0x261c
    u32 mUnitNo;  // offset: 0x2620
    bool mIsMyPlayer;  // offset: 0x2624
    u32 mPlayerNo;  // offset: 0x2628
    u32 mWeaponHold;  // offset: 0x262c
    u32 mWeaponHoldOld;  // offset: 0x2630
    u32 mWeaponCategory;  // offset: 0x2634
    u32 mWpnDispOff;  // offset: 0x2638
    u32 mBakeJointType;  // offset: 0x263c
    u32 mBakeJointTypeOld;  // offset: 0x2640
protected:
    cContextInstHm* mpContext;  // offset: 0x2648
    u32 mSex;  // offset: 0x2650
public:
    cColorCtrl mAlbedoCtrl[24];  // offset: 0x2660
    cColorCtrl mAlbedoBlendCtrl[24];  // offset: 0x2960
    cColorCtrl mEmissionCtrl[24];  // offset: 0x2c60
protected:
    rNpcEditData* mpNpcEquipRes;  // offset: 0x2f60
public:
    static MyDTI DTI;
    static const u32 ALB_NUM = 24;
};

inline void* uDDOActorModelPl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 uDDOActorModelPl::getWeaponHold() {
    return this->mWeaponHold;
}

inline u32 uDDOActorModelPl::getUnitNo() {
    return this->mUnitNo;
}

inline cContextInstHm* uDDOActorModelPl::getContext() {
    return this->mpContext;
}

inline void* uDDOActorModelPl::cColorCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uDDOActorModelPl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uDDOActorModelPl::DTI)->memFree(p_addr);
}

inline void uDDOActorModelPl::cColorCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uDDOActorModelPl::cColorCtrl::DTI)->memFree(p_addr);
}
