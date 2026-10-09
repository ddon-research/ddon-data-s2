#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "nCastUtility.h"
#include "nEnemy.h"
#include "nEnemyID.h"
#include "sUnitManager.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector2;
class cContextInterface;
class cEmBaseInfoSv;
class cEnemyGroup;
class cHumanEnemyCustomSkill;
class cHumanEnemyEquip;
class rAdjustParam;
class rEmBaseInfoSv;
class rEnemyGroup;
class rHumanEnemyCustomSkill;
class rHumanEnemyEquip;
class rHumanEnemyPreset;
class uBaseModel;
class uCharacter;
class uDDOModel;
class uPlayer;

// Declarations
class sEnemyManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sEnemyManager : public sUnitManager
{
public:
    class MyDTI;
    class cEnemyDistanceInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cEnemyDistanceInfo
    {
    public:
        cEnemyDistanceInfo();
        ~cEnemyDistanceInfo();
        void init();
        void update();
        bool isHaveMinInfoForUpdate(u32 UnitNum, uPlayer* pPlayer);
        void updateNearestDistance(f32* pUpdate, uCharacter* pEnemy, uPlayer* pPlayer);
        void updateNearestDistanceSuperErosion(f32* pUpdate, uCharacter* pChara, uPlayer* pPlayer);
        f32 getNearestDistance();
        f32 getNearestDistanceSuperErosion();
    private:
        f32 mNearestDistance;  // offset: 0x0
        f32 mNearestDistanceSuperErosion;  // offset: 0x4
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
    sEnemyManager();
    virtual ~sEnemyManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool update();  // vtable slot 12
    static sEnemyManager* getInstance();
    void createResource();
    void releaseResource();
    estUnitType<uDDOModel, void> createUnit(u32 unique_id, u32 enemyID);
    bool isCategoryActive(nEnemy::ENEMY_CATEGORY category, u32 enemyID) const;
    void sendRaidInfoToServer(u32 RaidBossId, cContextInterface& context);
    void sendRaidInfoToServer(uCharacter* pRaidBoss);
private:
    bool isCategoryActive(nEnemy::ENEMY_CATEGORY category, nEnemy::ENEMY_ID enemyID) const;
    const cEmBaseInfoSv* findEmBaseInfoSv(u32 enemyID) const;
    const cEmBaseInfoSv* findEmBaseInfoSv(nEnemy::ENEMY_ID enemyID) const;
    void setEmBaseInfoSv(rEmBaseInfoSv* pEmBaseInfo);
public:
    virtual u32 getLodDistDataKindNum();  // vtable slot 18
    virtual u32 getLodDistDataKind(uBaseModel* bm);  // vtable slot 19
    virtual MtVector2 getLosDistDataParam(u32 num);  // vtable slot 20
    virtual void setLODDist(uBaseModel* bm);  // vtable slot 21
    f32 getShakeChanceAdjust(u32 index) const;
    const cHumanEnemyEquip* getHumanEnemyEquipData(u32 presetId) const;
    const cHumanEnemyCustomSkill* getHumanEnemyCustomSkill(u32 presetId) const;
    u32 getHumanEnemyEditType(u32 presetId) const;
    bool isHumanEnemyMontageRandom(u32 presetId) const;
    bool isHumanEnemyBeginBattleVoice(u32 presetId) const;
    bool isHumanEnemyOriginalCsArc(u32 presetId) const;
    bool isRageEnemy();
    f32 getEmAdjustParam(nEnemy::EM_ADJUST_PARAM param) const;
    u32 getEnemyGroupId(u32 em_id);
    s32 getMsgIndexFromEnemyId(u32 em_id);
    s32 getMsgIndexFromEnemyGroup(u32 em_group);
private:
    cEnemyGroup* getEnemyGroupData(u32 em_id);
public:
    cEnemyDistanceInfo* getEnemyDistanceInfo();
private:
    rEmBaseInfoSv* mpEmBaseInfoSv;  // offset: 0xa0
    rAdjustParam* mprShakeChanceAdj;  // offset: 0xa8
    rHumanEnemyPreset* mprHumanEmPriset;  // offset: 0xb0
    rHumanEnemyEquip* mprHumanEmEquip;  // offset: 0xb8
    rHumanEnemyCustomSkill* mprHumanEmCustomSkill;  // offset: 0xc0
public:
    f32 mSystemTimer;  // offset: 0xc8
    f32 mSystemTimerMax;  // offset: 0xcc
private:
    rAdjustParam* mpEnemyAdjustParam;  // offset: 0xd0
    rEnemyGroup* mpEnemyGroup;  // offset: 0xd8
    cEnemyDistanceInfo mEnemyDistanceInfo;  // offset: 0xe0
    static sEnemyManager* mpInstance;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sEnemyManager* sEnemyManager::getInstance() {
    return ::sEnemyManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sEnemyManager::cEnemyDistanceInfo::~cEnemyDistanceInfo() {
}
