#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nDDOGame.h"
#include "nObjCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cHitInfoAfterCommon;
class uHuman;

// Declarations
class cOcdDamageInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cOcdDamageInfo : public MtObject
{
    // inferred: uHuman::makeOcdAttackInfoCore names cOcdDamageInfo::mWepItemRank
    friend class uHuman;
public:
    enum ELEMENT_FINAL_TYPE
    {
        FINAL_ELEMENT_NONE = 0,
        FINAL_ELEMENT_WEP = 1,
        FINAL_ELEMENT_ENCHANT = 2,
        FINAL_ELEMENT_ATTACK_PATAM = 3,
    };
public:
    class MyDTI;
    struct stDamageData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stDamageData
    {
    public:
        stDamageData();
        f32 getOcdAttackAdj(nObjCollision::OCD_ATTACK_ADJ_TYPE type) const;
        f32 getOcdDefenceAdj(nObjCollision::OCD_DEFENCE_ADJ_TYPE type) const;
        void addOcdAttackAdj(nObjCollision::OCD_ATTACK_ADJ_TYPE type, f32 Adj);
        void addOcdDefenceAdj(nObjCollision::OCD_DEFENCE_ADJ_TYPE type, f32 Adj);
        void clear();
        u32 getOcdUID() const;
    public:
        f32 mWepAttack;  // offset: 0x0
        f32 mEnchantAttack;  // offset: 0x4
        f32 mSkillAttack;  // offset: 0x8
        f32 mDamage;  // offset: 0xc
    private:
        u32 mOcdUID;  // offset: 0x10
        f32 mOcdAttackAdj[4];  // offset: 0x14
        f32 mOcdDefenceAdj[4];  // offset: 0x24
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
    cOcdDamageInfo();
    stDamageData* getOcdDataFromUID(u32 OcdUID);
    stDamageData* getOcdDataFromIndex(u32 index);
    stDamageData* getOcdDataEnchantTarget(nDDOGame::ELEMENT_TYPE type);
    void getInfoFromCM(const cHitInfoAfterCommon& info);
    void clear();
    void setWepItemRank(u16 rank);
    u16 getWepItemRank() const;
    void setOcdIrAdj(f32 adj);
    f32 getOcdIrAdj() const;
    void setElementFinalType(ELEMENT_FINAL_TYPE type);
    ELEMENT_FINAL_TYPE getElementFinalType() const;
public:
    nDDOGame::ELEMENT_TYPE mWepElmentType;  // offset: 0x8
    nDDOGame::ELEMENT_TYPE mEnchantOcdType;  // offset: 0xc
    nDDOGame::ELEMENT_TYPE mEnchantResultType;  // offset: 0x10
    nDDOGame::ELEMENT_TYPE mElementResultType;  // offset: 0x14
    bool mIsElementNone;  // offset: 0x18
private:
    u16 mWepItemRank;  // offset: 0x1a
    f32 mOcdIrAdj;  // offset: 0x1c
    stDamageData mOcdBadData[31];  // offset: 0x20
    ELEMENT_FINAL_TYPE mElementFinalType;  // offset: 0x66c
public:
    static MyDTI DTI;
};
