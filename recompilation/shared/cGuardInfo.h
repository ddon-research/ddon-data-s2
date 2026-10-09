#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nObjCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cBlowShrinkDmInfo;
class uEnemy;

// Declarations
class cGuardInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cGuardInfo : public MtObject
{
    // inferred: uEnemy::callbackGuard_make names cGuardInfo::mSaminaDamageAdj[0]
    friend class uEnemy;
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
    cGuardInfo();
    virtual ~cGuardInfo();
    f32 getGuardAttackAdj(nObjCollision::GUARD_ATTACK_ADJ_TYPE type) const;
    f32 getGuardDefenceAdj(nObjCollision::GUARD_DEFENCE_ADJ_TYPE type) const;
    f32 getSaminaDamageAdj(nObjCollision::STAMINA_DAMAGE_ADJ_TYPE type) const;
    void addGuardAttackAdj(nObjCollision::GUARD_ATTACK_ADJ_TYPE, f32);
    void addGuardDefenceAdj(nObjCollision::GUARD_DEFENCE_ADJ_TYPE type, f32 Adj);
    void addSaminaDamageAdj(nObjCollision::STAMINA_DAMAGE_ADJ_TYPE type, f32 Adj);
public:
    cBlowShrinkDmInfo* mpBlowShrinkInfo;  // offset: 0x8
    f32 mGuardDefenceBase;  // offset: 0x10
    f32 mGuardDefenceWep;  // offset: 0x14
    u32 mGuardDefenceResultType;  // offset: 0x18
    f32 mGuardAttack;  // offset: 0x1c
    f32 mGuardDefence;  // offset: 0x20
    f32 mStaminaDamage;  // offset: 0x24
    bool mIsJustGuardSuccess;  // offset: 0x28
    bool mIsSuccessNoReaction;  // offset: 0x29
private:
    f32 mGuardAttackAdj[4];  // offset: 0x2c
    f32 mGuardDefenceAdj[4];  // offset: 0x3c
    f32 mSaminaDamageAdj[4];  // offset: 0x4c
public:
    f32 mPawnAdjGuardDefenceBase;  // offset: 0x5c
    f32 mPawnAdjStaminaDamage;  // offset: 0x60
    static MyDTI DTI;
};
