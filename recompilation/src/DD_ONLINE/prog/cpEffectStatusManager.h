#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
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
class cEffectStatus;
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

class cEffectStatus : public MtObject
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
    cEffectStatus();
    virtual ~cEffectStatus() {}
    void registerSynchronizeEffect(cEfcHandle& EfcHandle, u64 syncFlag, sEffectExt::EFC_END_TYPE endType, s32 IndexNo, s32 ElementNo);
    cEfcHandle* setSynchronizeEffect(u64, sEffectExt::EFC_END_TYPE, rEffectProvider*, s32, s32, const sEffectExt::EfcParam&, uDDOModel*);
    bool updateHandle();
    void deleteHandle();
    void deleteHandle(u32 endType);
    void updateSyncFlag(u64 syncFlag);
    cEfcHandle* getEfcHandle() const;
    s32 getIndexNo() const;
    s32 getElementNo() const;
    bool checkSyncFlag(u64 syncFlag) const;
private:
    u64 mSyncFlag;  // offset: 0x8
    s32 mIndexNo;  // offset: 0x10
    s32 mElementNo;  // offset: 0x14
    sEffectExt::EFC_END_TYPE mEndType;  // offset: 0x18
    cEfcHandle* mpEfcHandle;  // offset: 0x20
public:
    static MyDTI DTI;
};

class cpEffectStatusManager : public cpComponent
{
    friend class cpErosionEnemyBase;
    friend class cpHugeble;
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

inline cEffectStatus::cEffectStatus() {
    this->mSyncFlag = 0;
    this->mIndexNo = -1;
    this->mElementNo = -1;
    this->mEndType = static_cast<sEffectExt::EFC_END_TYPE>(4);
    this->mpEfcHandle = nullptr;
}

inline cpEffectStatusManager::cpEffectStatusManager() {
    this->mEffectArray.mAutoDelete = true;
}
