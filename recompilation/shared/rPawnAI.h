#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cAIObject.h"
#include "cPawnActInterface.h"
#include "nDDOUtility.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtString;
class MtVector3;
class cGeneralPoint;
class cPawnActInterBase;
class cPawnEnableArea;
class uCharacter;

// Declarations
class cPawnAIActInter;
class cPawnAIAction;
class rPawnAIAction;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnActSupportFlag = nDDOUtility::cBitSet<33>;
using cAIPawnActionGroupFlag = nDDOUtility::cBitSet<128>;
using cAIPawnOcdArray = nDDOUtility::cArray<unsigned int, 16>;
using cPawnAIActCancelFlag = nDDOUtility::cBitSet<22>;
using cPawnAIActComCheckFlag = nDDOUtility::cBitSet<10>;
using cPawnAIActComCtrlFlag = nDDOUtility::cBitSet<11>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPawnAIActInter : public cAIResource
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
    cPawnAIActInter();
    virtual ~cPawnAIActInter();
    cPawnActInterBase* getInter();
    void load(MtDataReader& r);
    void save(MtDataWriter& w);
    static u32 convNameID(MT_CTSTR name);
public:
    u32 mNameID;  // offset: 0x8
    nDDOUtility::cScopedPtr<cPawnActInterBase> mpCmdInter;  // offset: 0x10
    static MyDTI DTI;
};

class cPawnAIAction : public cAIResource
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
    cPawnAIAction();
    virtual ~cPawnAIAction();
    u32 getPawnActID() const;
    u32 getPawnAIActInterNum() const;
    cPawnAIActInter* getPawnAIActInter(u32 idx);
    f32 getPawnAIStandOffFrame() const;
    static u32 convPawnActID(MT_CTSTR name);
    bool isEnableActInterPre(uCharacter& owner, const cPawnAIActComCheckFlag& checkFlag) const;
    s32 getEnableActInterRate(uCharacter& owner, cGeneralPoint* pTarget, MtString* pLog, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const;
    bool isEffectiveActInter(uCharacter& owner) const;
    bool isActInterGroup(uCharacter* pOwner, const cAIPawnActionGroupFlag& flag);
    u32 exclusionByStamina(uCharacter* pOwner) const;
    void getActInterOcd(uCharacter& owner, cAIPawnOcdArray& dst);
    s32 getJustRangeActNo() const;
    static void findActInterfaceFromGroup(MtTypedArray<cPawnAIAction>* pDst, uCharacter* pOwner, MtTypedArray<cPawnAIAction>& src, u32 group);
    static void findActInterfaceFromGroup(MtTypedArray<cPawnAIAction>* pDst, uCharacter* pOwner, MtTypedArray<cPawnAIAction>& src, const cAIPawnActionGroupFlag& group);
    static cPawnAIAction* findActInterfaceFromID(rPawnAIAction* pRes, u32 id);
    static cPawnAIAction* findActInterfaceFromID(MtTypedArray<rPawnAIAction>& res, u32 id);
    static cPawnAIAction* findActInterfaceFromID(MtTypedArray<cPawnAIAction>& src, u32 id);
    void load(MtDataReader& r);
public:
    u32 mPawnActID;  // offset: 0x8
    cAIPawnActionGroupFlag mGroup;  // offset: 0xc
    f32 mLifeFrame;  // offset: 0x1c
    f32 mStandOffFrame;  // offset: 0x20
    MtTypedArray<cPawnAIActInter> mpActInters;  // offset: 0x28
    cPawnAIActComCtrlFlag mPawnAIActComCtrlFlag;  // offset: 0x48
    u32 mPawnAIActComCtrlOrderID;  // offset: 0x4c
    cPawnAIActCancelFlag mPawnAIActCancelFlag;  // offset: 0x50
    u32 mEnableJobFlag;  // offset: 0x54
    cPawnAIActComCheckFlag mPawnAIActComEnableFlag;  // offset: 0x58
    cPawnAIActComCheckFlag mPawnAIActComDisableFlag;  // offset: 0x5c
    s32 mUseRate;  // offset: 0x60
    f32 mUseRangeMin;  // offset: 0x64
    f32 mUseRangeMax;  // offset: 0x68
    u32 mEnableJobCharge;  // offset: 0x6c
    u32 mProperTargetType;  // offset: 0x70
    f32 mStaminaRateMin;  // offset: 0x74
    f32 mStaminaRateMax;  // offset: 0x78
    f32 mUseRateFromStaminaVeryLow;  // offset: 0x7c
    f32 mUseRateFromStaminaLow;  // offset: 0x80
    f32 mUseRateFromStaminaMiddleLow;  // offset: 0x84
    f32 mUseRateFromStaminaMiddleHigh;  // offset: 0x88
    f32 mUseRateFromStaminaHigh;  // offset: 0x8c
    f32 mUseRateFromStaminaVeryHigh;  // offset: 0x90
    f32 mSupportHpRateMin;  // offset: 0x94
    f32 mSupportHpRateMax;  // offset: 0x98
    cAIPawnActSupportFlag mSupportPawnActFlag;  // offset: 0x9c
    u32 mAIPawnGroupThinkID;  // offset: 0xa4
    s32 mJustRangeActNo;  // offset: 0xa8
    s32 mJustRangeJob;  // offset: 0xac
    static MyDTI DTI;
};

class rPawnAIAction : public rTbl2<cPawnAIAction>
{
public:
    enum
    {
        DATA_VERSION = 68,
    };
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
    rPawnAIAction();
    virtual ~rPawnAIAction();
    virtual bool loadData(MtDataReader& r, cPawnAIAction* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cPawnAIActInter::cPawnAIActInter() {
    this->mNameID = static_cast<u32>(0);
}
