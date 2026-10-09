#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cEfcHandle;
class uDDOModel;

// Declarations
class cCyclePartInfo;
class cCyclePartReqInfo;
class cEffectCycleCtrl;

namespace nEffectCycle {
    enum CYCLE_PART_KILL_PAHSE
    {
        PART_KILL_PAHSE_INVALID = 0,
        PART_KILL_PAHSE_NONE = 1,
        PART_KILL_PAHSE_RESERVE = 2,
        PART_KILL_PAHSE_STANBY = 3,
    };
}  // namespace nEffectCycle

namespace nEffectCycle {
    enum CYCLE_PART_PAHSE
    {
        PART_PAHSE_INVALID = 0,
        PART_PAHSE_WAIT = 1,
        PART_PAHSE_LOOP = 2,
        PART_PAHSE_END = 3,
        PART_PAHSE_KILL = 4,
    };
}  // namespace nEffectCycle

namespace nEffectCycle {
    enum CYCLE_PART_TYPE
    {
        PART_TYPE_INVALID = 0,
        PART_TYPE_REST = 1,
        PART_TYPE_EFFCT_CALL = 2,
    };
}  // namespace nEffectCycle

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCyclePartInfo : public MtObject
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
    cCyclePartInfo();
    virtual ~cCyclePartInfo();
    void updatePtr();
    void updateEfcHandle();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void reset();
    void getInfoFromReq(cCyclePartReqInfo& reqInfo);
    void partInit();
    void partMove();
    void partEnd();
    void kill();
    cEfcHandle* setPartEffect();
    cEfcHandle* setPartEndEffect();
    void callOutLine();
    void changePartPhase(nEffectCycle::CYCLE_PART_PAHSE phase);
    void requestPartEnd();
    bool isKillRequest() const;
    void reqestKillReserve();
    void reqestKill();
public:
    f32 mEffLoopTimer;  // offset: 0x8
    f32 mEffLoopTimerMax;  // offset: 0xc
    s32 mEpvIndex;  // offset: 0x10
    s32 mEpvElement;  // offset: 0x14
    bool mIsEffect;  // offset: 0x18
    s32 mEpvFinishIndex;  // offset: 0x1c
    s32 mEpvFinishElement;  // offset: 0x20
    bool mIsEndEffect;  // offset: 0x24
    s32 mOutLineIndex;  // offset: 0x28
    bool mIsOutLine;  // offset: 0x2c
    bool mIsActive;  // offset: 0x2d
    cEfcHandle* mpEfcHandle;  // offset: 0x30
    cEffectCycleCtrl* mpEffectCycleCtrl;  // offset: 0x38
    uDDOModel* mpModel;  // offset: 0x40
    nEffectCycle::CYCLE_PART_PAHSE mPartPhase;  // offset: 0x48
    nEffectCycle::CYCLE_PART_TYPE mPartType;  // offset: 0x4c
    nEffectCycle::CYCLE_PART_KILL_PAHSE mPartKillPhase;  // offset: 0x50
    s32 mCycleOrder;  // offset: 0x54
    static MyDTI DTI;
};

class cCyclePartReqInfo : public MtObject
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
    cCyclePartReqInfo();
public:
    f32 mEffLoopTime;  // offset: 0x8
    s32 mEpvIndex;  // offset: 0xc
    s32 mEpvElement;  // offset: 0x10
    bool mIsEffect;  // offset: 0x14
    s32 mEpvFinishIndex;  // offset: 0x18
    s32 mEpvFinishElement;  // offset: 0x1c
    bool mIsEndEffect;  // offset: 0x20
    s32 mOutLineIndex;  // offset: 0x24
    bool mIsOutLine;  // offset: 0x28
    nEffectCycle::CYCLE_PART_TYPE mPartType;  // offset: 0x2c
    static MyDTI DTI;
};

class cEffectCycleCtrl : public MtObject
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
    cEffectCycleCtrl();
    virtual ~cEffectCycleCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void updatePtr();
    void updateEfcHandle();
    void update();
    void kill();
    void setOwner(uDDOModel* pModel);
    void requestInsertCyclePart(cCyclePartReqInfo& reqInfo, s32 Order);
    void reqestKillCyclePart(s32 Order);
    void reqestForceKillCyclePart(s32 Order);
    bool isOrderExist(s32 Order) const;
    void setEffectFlag(bool flag);
    void setEndEffectFlag(bool flag);
    void setOutLineFlag(bool flag);
private:
    void checkKillReqest();
    void updateEffectCycle();
    void registCyclePart(cCyclePartInfo* pInfo);
    bool erasetCyclePart(s32 Order);
    bool erasetCyclePartFromIndex(s32 index);
    s32 findCyclePartIndex(s32 Order) const;
private:
    s32 mCurrentPartIndex;  // offset: 0x8
    MtTypedArray<cCyclePartInfo> mEffectPartArray;  // offset: 0x10
    uDDOModel* mpModel;  // offset: 0x30
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCyclePartInfo::cCyclePartInfo() {
    this->mEffLoopTimer = 0.0f;
    this->mEffLoopTimerMax = 30.0f;
    this->mEpvIndex = static_cast<s32>(-1);
    this->mEpvElement = static_cast<s32>(-1);
    this->mIsEffect = false;
    this->mEpvFinishIndex = static_cast<s32>(-1);
    this->mEpvFinishElement = static_cast<s32>(-1);
    this->mIsEndEffect = false;
    this->mOutLineIndex = static_cast<s32>(-1);
    this->mIsOutLine = false;
    this->mIsActive = false;
    this->mpModel = static_cast<uDDOModel*>(nullptr);
    this->mpEffectCycleCtrl = static_cast<cEffectCycleCtrl*>(nullptr);
    this->mpEfcHandle = static_cast<cEfcHandle*>(nullptr);
    this->mCycleOrder = static_cast<s32>(-10000);
    this->mPartPhase = static_cast<nEffectCycle::CYCLE_PART_PAHSE>(0);
    this->mPartType = static_cast<nEffectCycle::CYCLE_PART_TYPE>(0);
    this->mPartKillPhase = static_cast<nEffectCycle::CYCLE_PART_KILL_PAHSE>(1);
}

// Inline, no code of its own: checked where it is inlined.
inline cCyclePartReqInfo::cCyclePartReqInfo() {
    this->mEffLoopTime = 30.0f;
    this->mEpvIndex = static_cast<s32>(-1);
    this->mEpvElement = static_cast<s32>(-1);
    this->mIsEffect = false;
    this->mEpvFinishIndex = static_cast<s32>(-1);
    this->mEpvFinishElement = static_cast<s32>(-1);
    this->mIsEndEffect = false;
    this->mOutLineIndex = static_cast<s32>(-1);
    this->mIsOutLine = false;
    this->mPartType = static_cast<nEffectCycle::CYCLE_PART_TYPE>(0);
}
