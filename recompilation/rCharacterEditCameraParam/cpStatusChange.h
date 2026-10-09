#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cBitCtrl.h"
#include "cEmWorkRateCtrl.h"
#include "cMethodConstantManagerBase.h"
#include "../shared/cpComponent.h"
#include "nStatusEnemy.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cBitCtrl;
class cEmWorkRateCtrl;
namespace cMethodConstantTimeName { class cMethodConstantManagerBase; }
class rBitTable;
class rDDOModelMontageEm;
class rEmScaleTable;
class rEmWorkRateTable;
class rEnemyStatusChange;
class uEnemy;

// Declarations
class cStatusChange;
class cpStatusChange;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using BitData = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cStatusChange : public MtObject
{
public:
    enum
    {
        STATUS_SLEEP = 1,
        STATUS_PLAY = 2,
        STATUS_ONE_END = 3,
        STATUS_END = 4,
    };
public:
    struct GuardData;
public:
    struct GuardData
    {
    public:
        u32 mStatus;  // offset: 0x0
        u32 mGroupNo;  // offset: 0x4
        u32 mGroupSubNo;  // offset: 0x8
        u32 mNextGroupSubNo;  // offset: 0xc
        bool mNextGroupSubOneGo;  // offset: 0x10
        bool mRepeatOnce;  // offset: 0x11
        u32 mRepeatCount;  // offset: 0x14
        f32 mTimer;  // offset: 0x18
        bool mIsStandby;  // offset: 0x1c
        bool mIsTypeCheckOk;  // offset: 0x1d
        bool mIsLocal;  // offset: 0x1e
        bool mIsRepeatFuncUse;  // offset: 0x1f
    };
public:
    cStatusChange();
    virtual ~cStatusChange();
    void init();
    void restart();
    u32 getStatus() const;
    void setStatus(u32 NewValue);
    u32 getGroupNo() const;
    void setGroupNo(u32 NewValue);
    u32 getGroupSubNo() const;
    void setGroupSubNo(u32 NewValue);
    u32 getNextGroupSubNo() const;
    void setNextGroupSubNo(u32 NewValue);
    bool isNextGroupSubOneGo() const;
    void setNextGroupSubOneGo(bool NewValue);
    bool isRepeatOnce() const;
    void setRepeatOnce(bool NewValue);
    u32 getRepeatCount() const;
    void setRepeatCount(u32 NewValue);
    f32 getTimer() const;
    void setTimer(f32 NewValue);
    bool isStandby() const;
    void setStandby(bool NewValue);
    bool isTypeCheckOk() const;
    void setTypeCheckOk(bool NewValue);
    bool isLocal() const;
    void setLocal(bool NewValue);
    bool isRepeatFuncUse() const;
    void setRepeatFuncUse(bool NewValue);
private:
    GuardData mData;  // offset: 0x8
};

class cpStatusChange : public cpComponent
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
    cpStatusChange();
    virtual ~cpStatusChange();
    virtual void setup();  // vtable slot 6
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void updatePtr();  // vtable slot 9
    void setEnemyStatusChangeRes(rEnemyStatusChange* pRes);
    void callbackChangeStatus(nStatusEnemy::CHECK_STATUS_TYPE inType, u32 param0, u32 param1, f32 param2, f32 param3);
    // Address: 0x01a5fbd0 - 0x01a5fbd1 (1 bytes)
    virtual void callbackChangeStatusEx(nStatusEnemy::CHECK_STATUS_TYPE_EX inType, nStatusEnemy::STATUS_CHANGE_REASON reason, u32 param0, u32 param1, f32 param2, f32 param3) {}  // vtable slot 15
    virtual void updateChangeStatus();  // vtable slot 16
    void setEnemyStatusChange(u32 changeStatusType, BitData bit);
    void setGroup_SubGroup(u32 group, u32 subGroup);
    void setConText(u32 groupoNo, u32 groupSubNo);
    void initStandby();
    void copyStatusOldBit();
    void checkStatusChangeBit(bool setUp);
    void setChangeStatusBit(u32 changeStatus, u32 selectNo, u32 commandSet);
    BitData integrateBitData(BitData resBit, BitData progBit, BitData progMask);
    void divideBitData(BitData bit, BitData& resBit, BitData& progBit, BitData progMask);
protected:
    void checkNextGroup(u32 checkGroup, u32 checkSubGroup, u32 nextGroupSub, bool nextGroupSubOneGo);
    void setToContextAllBit();
public:
    void moveMethodConstantMgr();
    void updateMethodConstantMgr();
    void afterMethodConstantMgr();
protected:
    bool setCallbackRepeat(u32 resourceIndex, cMethodConstantTimeName::cMethodConstantBase::CHECK_CALLBACK_PARAM checkFunc);
    bool callBackCheck(u32 index);
    bool repeatCheck_UnUse(u32 param);
    bool repeat_ExecFunc(u32 repeatCount, u32 index);
public:
    void setWorkRateTable(rEmWorkRateTable* pRes);
protected:
    u64 makeWorkRateBit(u32 statusNo) const;
    u32 makeWorkRateStatusNo(u64 bit) const;
public:
    void setScaleBit(rBitTable* pRes);
    void setScaleTable(rEmScaleTable* pRes);
    void setLocalBit(rBitTable* pRes);
    void setLocalBit2(rBitTable* pRes);
    void setSyncBit(rBitTable* pRes);
    void changeCollisionBitProg(u32 no, bool flag, bool isToContext);
    void setCollisionBitProg(BitData bit, bool isToContext);
    void setCollisionBitProgMask(BitData mask);
protected:
    void updateCollisionBit();
public:
    void setEmMotageResource(rDDOModelMontageEm* pRes);
    void setEmMotageBit(rBitTable* pRes);
    void applyMontageFirstSet(u32 montage);
    void applyMontagePartsDisp();
    void changeMontageBitProg(u32 no, bool flag, bool isToContext);
    void setMontageBitProg(BitData bit, bool isToContext);
    void setMontageBitProgMask(BitData mask);
    void applyEyelibsMontage(bool flg);
protected:
    void updateMontageBit();
protected:
    MtTypedArray<cStatusChange> mcStatusChange;  // offset: 0x50
    rEnemyStatusChange* mpResource;  // offset: 0x70
    uEnemy* mpEnemy;  // offset: 0x78
    cMethodConstantTimeName::cMethodConstantManagerBase mMethodConstantMgr;  // offset: 0x80
    cEmWorkRateCtrl mEmWorkRateCtrl;  // offset: 0x14a0
    cBitCtrl mEmScaleBitCtrl;  // offset: 0x14c8
    rEmScaleTable* mpEmScaleTableResource;  // offset: 0x14e8
    cBitCtrl mLocalBitCtrl;  // offset: 0x14f0
    cBitCtrl mLocalBitCtrl2;  // offset: 0x1510
    cBitCtrl mSyncBitCtrl;  // offset: 0x1530
    BitData mCollsionBitProg;  // offset: 0x1550
    BitData mCollsionBitProgMask;  // offset: 0x1558
    rDDOModelMontageEm* mpMontageEmResource;  // offset: 0x1560
    BitData mMontageBitProg;  // offset: 0x1568
    BitData mMontageBitProgMask;  // offset: 0x1570
    cBitCtrl mMontageBitCtrl;  // offset: 0x1578
    bool mFlgEyelidsMontage;  // offset: 0x1598
public:
    static MyDTI DTI;
};
