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
class cAttackParam;
class cDmJobAdjParam;
class cDmJobPawnAdjParam;
class cDmLvPawnAdjParam;
class uDDOModel;

// Declarations
class cBlowShrinkDmInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cBlowShrinkDmInfo : public MtObject
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
    cBlowShrinkDmInfo();
    f32 calcBaseShrinkAttack(const cAttackParam* pAttackParam);
    f32 calcBaseBlowAttack(const cAttackParam* pAttackParam);
    f32 calcSaveShrinkBlowAttack(const cDmJobAdjParam* pJobAdjParam, uDDOModel* pDefender);
    f32 getShrinkAttackAdj(nObjCollision::SHRINK_ATTACK_ADJ_TYPE type) const;
    f32 getShrinkDefenceAdj(nObjCollision::SHRINK_DEFENCE_ADJ_TYPE type) const;
    f32 getBlowAttackAdj(nObjCollision::BLOW_ATTACK_ADJ_TYPE type) const;
    f32 getBlowDefenceAdj(nObjCollision::BLOW_DEFENCE_ADJ_TYPE type) const;
    f32 getDownAttackAdj(nObjCollision::DOWN_ATTACK_ADJ_TYPE type) const;
    f32 getDownDefenceAdj(nObjCollision::DOWN_DEFENCE_ADJ_TYPE type) const;
    f32 getShakeAttackAdj(nObjCollision::SHAKE_ATTACK_ADJ_TYPE type) const;
    f32 getShakeDefenceAdj(nObjCollision::SHAKE_DEFENCE_ADJ_TYPE type) const;
    void addShrinkAttackAdj(nObjCollision::SHRINK_ATTACK_ADJ_TYPE type, f32 Adj);
    void addShrinkDefenceAdj(nObjCollision::SHRINK_DEFENCE_ADJ_TYPE type, f32 Adj);
    void addBlowAttackAdj(nObjCollision::BLOW_ATTACK_ADJ_TYPE type, f32 Adj);
    void addBlowDefenceAdj(nObjCollision::BLOW_DEFENCE_ADJ_TYPE type, f32 Adj);
    void addDownAttackAdj(nObjCollision::DOWN_ATTACK_ADJ_TYPE type, f32 Adj);
    void addDownDefenceAdj(nObjCollision::DOWN_DEFENCE_ADJ_TYPE type, f32 Adj);
    void addShakeAttackAdj(nObjCollision::SHAKE_ATTACK_ADJ_TYPE type, f32 Adj);
    void addShakeDefenceAdj(nObjCollision::SHAKE_DEFENCE_ADJ_TYPE type, f32 Adj);
    void clear();
    void setBlowReason(nObjCollision::BLOW_REASON reason, nObjCollision::REACTION_TYPE type);
    nObjCollision::BLOW_REASON getBlowReason(nObjCollision::REACTION_TYPE type) const;
    void setForceShrinkType(nObjCollision::FORCE_REACTION_TYPE type);
    void setForceBlowType(nObjCollision::FORCE_REACTION_TYPE type);
    void setForceShakeType(nObjCollision::FORCE_REACTION_TYPE type);
    void setForceDownType(nObjCollision::FORCE_REACTION_TYPE type);
    nObjCollision::FORCE_REACTION_TYPE getForceShrinkType() const;
    nObjCollision::FORCE_REACTION_TYPE getForceBlowType() const;
    nObjCollision::FORCE_REACTION_TYPE getForceShakeType() const;
    nObjCollision::FORCE_REACTION_TYPE getForceDownType() const;
public:
    f32 mPower;  // offset: 0x8
    f32 mBlowWep;  // offset: 0xc
    f32 mShrinkWep;  // offset: 0x10
    f32 mDownBase;  // offset: 0x14
    f32 mDownWep;  // offset: 0x18
    f32 mShakeBase;  // offset: 0x1c
    f32 mWeight;  // offset: 0x20
    f32 mBlowCutRate;  // offset: 0x24
    f32 mShrinkCutRate;  // offset: 0x28
    f32 mDownCutRate;  // offset: 0x2c
    f32 mShakeCutRate;  // offset: 0x30
    f32 mRageShrinkRate;  // offset: 0x34
    f32 mBlowValue;  // offset: 0x38
    f32 mShrinkValue;  // offset: 0x3c
    f32 mDownValue;  // offset: 0x40
    f32 mShakeValue;  // offset: 0x44
    f32 mRageShrinkValue;  // offset: 0x48
    bool mIsRageShrink_Shrink;  // offset: 0x4c
    f32 mPawnAdjShrinkBlowAt;  // offset: 0x50
    f32 mPawnAdjFinalDamageShrink;  // offset: 0x54
    f32 mPawnAdjFinalDamageBlow;  // offset: 0x58
    const cDmJobPawnAdjParam* mpJobPawnAdjParam_AT;  // offset: 0x60
    const cDmLvPawnAdjParam* mpDmLvPawnAdjParam_AT;  // offset: 0x68
    const cDmJobPawnAdjParam* mpJobPawnAdjParam_DF;  // offset: 0x70
    const cDmLvPawnAdjParam* mpDmLvPawnAdjParam_DF;  // offset: 0x78
private:
    nObjCollision::BLOW_REASON mBlowReason[7];  // offset: 0x80
    nObjCollision::FORCE_REACTION_TYPE mForceShrinkType;  // offset: 0x9c
    nObjCollision::FORCE_REACTION_TYPE mForceBlowType;  // offset: 0xa0
    nObjCollision::FORCE_REACTION_TYPE mForceShakeType;  // offset: 0xa4
    nObjCollision::FORCE_REACTION_TYPE mForceDownType;  // offset: 0xa8
    f32 mShrinkAttackAdj[4];  // offset: 0xac
    f32 mShrinkDefenceAdj[4];  // offset: 0xbc
    f32 mBlowAttackAdj[4];  // offset: 0xcc
    f32 mBlowDefenceAdj[4];  // offset: 0xdc
    f32 mDownAttackAdj[4];  // offset: 0xec
    f32 mDownDefenceAdj[4];  // offset: 0xfc
    f32 mShakeAttackAdj[4];  // offset: 0x10c
    f32 mShakeDefenceAdj[4];  // offset: 0x11c
public:
    static MyDTI DTI;
};
