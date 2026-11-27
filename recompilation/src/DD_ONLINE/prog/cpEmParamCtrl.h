#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"
#include "../../generated/shared/nEnemy.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cCharParamEnemy;
class cEmLvUpParam;
class cpOcdCtrl;
class uEnemy;

// Declarations
class cpEmParamCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpEmParamCtrl : public cpComponent
{
public:
    enum PARAM_TYPE
    {
        INVALID_TYPE = 0,
        PARAM_TYPE_INIT = 1,
        PHYS_ATK_BASE = 1,
        MAG_ATK_BASE = 2,
        PHYS_ATK_WEP = 3,
        MAG_ATK_WEP = 4,
        PHYS_DEF_BASE = 5,
        MAG_DEF_BASE = 6,
        PHYS_DEF_WEP = 7,
        MAG_DEF_WEP = 8,
        POWER = 9,
        GUARD_DEF_BASE = 10,
        GUARD_DEF_WEP = 11,
        HP_MAX = 12,
        SHP_MAX = 13,
        BLP_MAX = 14,
        DOWN_MAX = 15,
        SHAKE_MAX = 16,
        OCD_ALL_ENDURANCE_MAX = 17,
        RAGE_SHRINK_MAX = 18,
        PARAM_TYPE_NUM = 19,
        TYPE_ALL = 20,
    };
    enum ENDURANCE_TYPE
    {
        TYPE_SHRINK = 0,
        TYPE_BLOW = 1,
        TYPE_RAGE_SHRINK = 2,
    };
public:
    class MyDTI;
    struct stTempInfoSet;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stTempInfoSet
    {
    public:
        stTempInfoSet();
    public:
        cCharParamEnemy* mpEnemyParam;  // offset: 0x0
        cpOcdCtrl* mpOcdCtrl;  // offset: 0x8
        const cEmLvUpParam* mpLvUpParam;  // offset: 0x10
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
    cpEmParamCtrl();
    virtual ~cpEmParamCtrl();
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 15
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void updatePtr();  // vtable slot 9
    void calcSetStatus(PARAM_TYPE type, nEnemy::PARAM_RESET_TYPE resetType);
    void calcOcdEnduranceMax(u32 OcdUID, nEnemy::PARAM_RESET_TYPE resetType);
private:
    void callCalcFunc(PARAM_TYPE type, stTempInfoSet tempInfo, nEnemy::PARAM_RESET_TYPE resetType);
    void calcPhysAtkBase(stTempInfoSet& info);
    void calcMagAtkBase(stTempInfoSet& info);
    void calcPhysAtkWep(stTempInfoSet& info);
    void calcMagAtkWep(stTempInfoSet& info);
    void calcPhysDefBase(stTempInfoSet& info);
    void calcMagDefBase(stTempInfoSet& info);
    void calcPhysDefWep(stTempInfoSet& info);
    void calcMagDefWep(stTempInfoSet& info);
    void calcPower(stTempInfoSet& info);
    void calcGuardDefBase(stTempInfoSet& info);
    void calcGuardDefWep(stTempInfoSet& info);
    void calcHpMax(stTempInfoSet& info, bool reset);
    void calcShpMax(stTempInfoSet& info, bool reset);
    void calcBlpMax(stTempInfoSet& info, bool reset);
    void calcDownMax(stTempInfoSet& info, bool reset);
    void calcShakeMax(stTempInfoSet& info, bool reset);
    void calcOcdEnduranceMax(u32 OcdUID, stTempInfoSet& info, bool reset);
    void calcRageShrinkMax(stTempInfoSet& info, bool reset);
    f32 calcShrinkBlowAdj(ENDURANCE_TYPE type, u32 regionNo, stTempInfoSet& info) const;
    bool makeTempInfoSet(stTempInfoSet& info);
private:
    uEnemy* mpEnemy;  // offset: 0x50
public:
    static MyDTI DTI;
};

inline void* cpEmParamCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpEmParamCtrl::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpEmParamCtrl::DTI);
}

inline void cpEmParamCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpEmParamCtrl::DTI)->memFree(p_addr);
}
