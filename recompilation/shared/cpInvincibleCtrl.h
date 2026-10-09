#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cpComponent.h"
#include "nObjCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cHitInfoAfter;
class cpObjCollisionBase;
class uDDOModel;

// Declarations
class cpInvincibleCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpInvincibleCtrl : public cpComponent
{
public:
    enum DAMAGE_ATTR
    {
        DAMAGE_ATTR_NO_DAMAGE = 1,
        DAMAGE_ATTR_NO_DEATH = 2,
        DAMAGE_ATTR_NO_HP_INV = 4,
        DAMAGE_ATTR_NO_REGION_BREAK = 8,
        DAMAGE_ATTR_NO_HEAL = 16,
        DAMAGE_ATTR_NO_BLOW_INV = 32,
        DAMAGE_ATTR_NO_SHRINK_INV = 64,
        DAMAGE_ATTR_NO_DOWN_INV = 128,
        DAMAGE_ATTR_NO_SHAKE_INV = 256,
        DAMAGE_ATTR_NO_BLOW_REACT = 512,
        DAMAGE_ATTR_NO_SHRINK_REACT = 1024,
        DAMAGE_ATTR_NO_DOWN_REACT = 2048,
        DAMAGE_ATTR_NO_SHAKE_REACT = 4096,
        DAMAGE_ATTR_NO_OCD_INIT = 8192,
        DAMAGE_ATTR_NO_OCD_INIT_BAD = 16384,
        DAMAGE_ATTR_NO_OCD_INV = 32768,
        DAMAGE_ATTR_NO_OCD_EFFECT = 65536,
        DAMAGE_ATTR_OCD_TIMER_STOP = 131072,
        DAMAGE_ATTR_NO_OCD_ENDU_CURE = 262144,
        DAMAGE_ATTR_CURE_BAD_STATUS = 524288,
        DAMAGE_ATTR_NO_HIT_SE_EFF = 1048576,
        DAMAGE_ATTR_NO_HIT_STOP = 2097152,
        DAMAGE_ATTR_NO_DAMAGE_GUI = 4194304,
        DAMAGE_ATTR_NO_STORM_QUAKE = 8388608,
        DAMAGE_ATTR_NO_SHAKE = 16777216,
        DAMAGE_ATTR_NO_SHRINK_REACT_AIR = 33554432,
        DAMAGE_ATTR_NO_CATCH = 67108864,
        DAMAGE_ATTR_DAMAGE_INV_DAMAGE_UI = 134217728,
    };
public:
    class MyDTI;
    class cInvInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cInvInfo : public MtObject
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
        cInvInfo();
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
        void setAttr(u32 attr);
        u32 getAttr() const;
        u32 getAttrCheatCheack() const;
        void setPriority(u32 attr);
        u32 getPriority() const;
        u32 getPriorityCheatCheack() const;
    private:
        void setAttrCheatCheack(u32 attr);
        void setPriorityCheatCheack(u32 attr);
        u32 getAttrPrivate() const;
        void setAttrPrivate(u32 NewValue);
        u32 getAttrCheatCheackPrivate() const;
        void setAttrCheatCheackPrivate(u32 NewValue);
        u32 getPriorityPrivate() const;
        void setPriorityPrivate(u32 NewValue);
        u32 getPriorityCheatCheackPrivate() const;
        void setPriorityCheatCheackPrivate(u32 NewValue);
    private:
        u32 mAttr;  // offset: 0x8
        u32 mAttrCheatCheack;  // offset: 0xc
        u32 mPriority;  // offset: 0x10
        u32 mPriorityCheatCheack;  // offset: 0x14
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
    cpInvincibleCtrl();
    virtual ~cpInvincibleCtrl();
    virtual void setup();  // vtable slot 6
    void callbackMoveBegion();
    void before();
    void update();
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void clear();
    void setInvType(nObjCollision::UNIT_INV_TYPE type);
    void addInvType(nObjCollision::UNIT_INV_TYPE type);
    void removeInvType(nObjCollision::UNIT_INV_TYPE type);
    bool isInvTypeActive(nObjCollision::UNIT_INV_TYPE type) const;
    bool isDamageAttrActive(u32 attr) const;
    bool isDamageAttrOff(u32 attr) const;
    bool isDamageAttrOldActive(u32 attr) const;
    bool isDamageAttrOldOff(u32 attr) const;
    bool isDamageAttrActive_Through(nObjCollision::DAMAGE_ATTR_ENUM attrEnum, nObjCollision::UNIT_INV_THROUGH_TYPE type) const;
    bool isDamageAttrOldActive_Through(nObjCollision::DAMAGE_ATTR_ENUM attrEnum, nObjCollision::UNIT_INV_THROUGH_TYPE type) const;
    bool isInvThrough(nObjCollision::UNIT_INV_THROUGH_TYPE type, u32 attr) const;
    void callbackDamageAfter_calcEnd(cHitInfoAfter* pHitInfo);
private:
    cpObjCollisionBase* findCpObjCollision() const;
    void defineInvincible();
    u32 getInvTypeFlagPrivate() const;
    void setInvTypeFlagPrivate(u32 NewValue);
    u32 getInvTypeFlagOldPrivate() const;
    void setInvTypeFlagOldPrivate(u32 NewValue);
    u32 getInvTypeFlagCheatCheckPrivate() const;
    void setInvTypeFlagCheatCheckPrivate(u32 NewValue);
    u32 getInvTypeFlagOldCheatCheckPrivate() const;
    void setInvTypeFlagOldCheatCheckPrivate(u32 NewValue);
    void setInvFlag(u32 invFlag);
    u32 getInvFlag() const;
    void setInvFlagOld(u32 invFlag);
    u32 getInvFlagOld() const;
    void clearInvFlag();
    void checkCheatInvicible();
    void checkCheatInvTypeFlag(const u32 flag, const u32 checkWork);
    void checkCheatDamageAttr(const u32 attr, const u32 checkWork);
    void checkCheatDamageAttrDefine();
    void setInvFlagCheatCheck(u32 invFlag);
    u32 getInvFlagCheatCheck() const;
    void setInvFlagOldCheatCheck(u32 invFlag);
    u32 getInvFlagOldCheatCheck() const;
    u32 getDamageAttrPrivate() const;
    void setDamageAttrPrivate(u32 NewValue);
    u32 getDamageAttrOldPrivate() const;
    void setDamageAttrOldPrivate(u32 NewValue);
    u32 getDamageAttrCheatCheckPrivate() const;
    void setDamageAttrCheatCheckPrivate(u32 NewValue);
    u32 getDamageAttrOldCheatCheckPrivate() const;
    void setDamageAttrOldCheatCheckPrivate(u32 NewValue);
    void updateDamageAttr();
    void clearDamageAttr();
    void updateOtherAttr();
    void setDamageAttr(u32 attr);
    u32 getDamageAttr() const;
    void setDamageAttrOld(u32 attr);
    u32 getDamageAttrOld() const;
    void setDamageAttrCheatCheck(u32 invFlag);
    u32 getDamageAttrCheatCheck() const;
    void setDamageAttrOldCheatCheck(u32 invFlag);
    u32 getDamageAttrOldCheatCheck() const;
    void defineInvincibleThrough();
private:
    uDDOModel* mpModel;  // offset: 0x50
    cInvInfo mInvInfo[24];  // offset: 0x58
    u32 mInvTypeFlag;  // offset: 0x298
    u32 mInvTypeFlagOld;  // offset: 0x29c
    u32 mInvTypeFlagCheatCheak;  // offset: 0x2a0
    u32 mInvTypeFlagOldCheatCheak;  // offset: 0x2a4
    u32 mDamageAttr;  // offset: 0x2a8
    u32 mDamageAttrOld;  // offset: 0x2ac
    u32 mDamageAttrCheatCheck;  // offset: 0x2b0
    u32 mDamageAttrOldCheatCheck;  // offset: 0x2b4
    u32 mDamageAttrPriority[28];  // offset: 0x2b8
    u32 mDamageAttrPriorityOld[28];  // offset: 0x328
    cInvInfo mInvThroughInfo[3];  // offset: 0x398
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cpInvincibleCtrl::cInvInfo::cInvInfo() {
    this->mAttr = static_cast<u32>(0);
    this->mAttrCheatCheack = static_cast<u32>(4294967295);
    this->mPriority = static_cast<u32>(0);
    this->mPriorityCheatCheack = static_cast<u32>(4294967295);
}
