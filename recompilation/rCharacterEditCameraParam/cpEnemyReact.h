#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cHitInfo;
class cHitInfoAfter;
class rEnemyReactResEx;
class uDDOModel;

// Declarations
class cEnemyReactIndividual;
class cpEnemyReact;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cEnemyReactIndividual : private MtObject
{
public:
    cEnemyReactIndividual();
    virtual ~cEnemyReactIndividual();
    void init();
public:
    u32 mResetType;  // offset: 0x8
    bool mResetTypeBlow;  // offset: 0xc
    u32 mResetTypeBlowCount;  // offset: 0x10
    bool mResetTypeShrink;  // offset: 0x14
    u32 mResetTypeShrinkCount;  // offset: 0x18
    bool mResetTypeDown;  // offset: 0x1c
    u32 mResetTypeDownCount;  // offset: 0x20
    f32 mFResetParam;  // offset: 0x24
    u32 mUResetParam;  // offset: 0x28
    u32 mBlowCount;  // offset: 0x2c
    u32 mShrinkCount;  // offset: 0x30
    u32 mDownCount;  // offset: 0x34
    u32 mUCount;  // offset: 0x38
    f32 mFCount;  // offset: 0x3c
    f32 mResetTimer;  // offset: 0x40
    bool mResetTiming;  // offset: 0x44
    bool mEnable;  // offset: 0x45
};

class cpEnemyReact : public cpComponent
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
    cpEnemyReact();
    virtual ~cpEnemyReact();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    bool checkReaction(u32 reactCheckType, uDDOModel* pDdoModel, cHitInfoAfter* pHitInfoAfter, cHitInfo* pHitInfo);
    void resetCheck(u32 reactCheckType);
    bool resetCheck(u32 idx, u32 reactCheckType);
    void addTimer(f32 ftimer);
private:
    bool checkNonTesNo(u32 checkmode, bool flg);
    bool checkOverallConditionsType(rEnemyReactResEx* pRes, uDDOModel* pDdoModel, cHitInfoAfter* pHitInfoAfter, cHitInfo* pHitInfo);
    bool checkCountConditions(u32 reactCheckType, rEnemyReactResEx* pRes, uDDOModel* pDdoModel, cHitInfoAfter* pHitInfoAfter, cHitInfo* pHitInfo);
    bool checkPlayType(u32 reactCheckType, rEnemyReactResEx* pRes, uDDOModel* pDdoModel, cHitInfoAfter* pHitInfoAfter, cHitInfo* pHitInfo);
    bool checkWhereType(rEnemyReactResEx* pRes, uDDOModel* pDdoModel, cHitInfoAfter* pHitInfoAfter, cHitInfo* pHitInfo);
public:
    void setResource(u32 index, rEnemyReactResEx* pRes);
public:
    rEnemyReactResEx* mpEnemyReactRes[8];  // offset: 0x50
    cEnemyReactIndividual mEnemyReactManager[8];  // offset: 0x90
    static MyDTI DTI;
private:
    static const u32 ENEMY_RECT_RES_NUM = 8;
};
