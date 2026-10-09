#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cpComponent.h"
#include "sEffectExt.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class cEfcHandle;
class cpErosionEnemyBase;
class cpHugeble;
class rEffectProvider;
class uDDOModel;
class uHuman;

// Declarations
class cpEffectStatusManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

// Functions the classes below befriend, declared first
namespace nHumanActUtility { void reqOnSyncFlag(uHuman* pHuman, u64 syncFlag); }

class cpEffectStatusManager : public cpComponent
{
    // inferred: cpErosionEnemyBase::reqOnSyncFlag names cpEffectStatusManager::mSyncFlag
    friend class cpErosionEnemyBase;
    // inferred: cpHugeble::syncHugebleDeathEff names cpEffectStatusManager::mSyncFlag
    friend class cpHugeble;
    // inferred: nHumanActUtility::reqOnSyncFlag names cpEffectStatusManager::mSyncFlag
    friend void nHumanActUtility::reqOnSyncFlag(uHuman* pHuman, u64 syncFlag);
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
    cpEffectStatusManager();
    virtual ~cpEffectStatusManager();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    void onSyncFlag(u64 flag);
    void offSyncFlag(u64 flag);
    void clearSyncFlag();
    void copySyncFlagtoOld();
    u64 getSyncFlag();
    u64 getSyncFlagOld();
    bool setSynchronizeEffect(u64 syncFlag, sEffectExt::EFC_END_TYPE endType, rEffectProvider* pEPV, s32 IndexNo, s32 ElementNo, const sEffectExt::EfcParam& param, uDDOModel* pOrigin);
    void after();
    void endEffect(s32 IndexNo, s32 ElementNo);
    void allKill(sEffectExt::EFC_END_TYPE type);
    virtual void updateEfcHandle();  // vtable slot 10
    cEfcHandle* getEfcHandle(u64 syncFlag);
protected:
    MtArray mEffectArray;  // offset: 0x50
    u64 mSyncFlag;  // offset: 0x70
    u64 mSyncFlagOld;  // offset: 0x78
public:
    static MyDTI DTI;
};
