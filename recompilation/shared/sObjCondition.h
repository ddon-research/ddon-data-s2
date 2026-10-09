#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cSystem.h"
#include "nDDOGame.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cOcdInfo;
class cOcdIrAdj;
class cOcdIrAdjPL;
class cOcdPriorityParam;
namespace nObjCondition { struct stOcdActiveInfo; }
namespace nObjCondition { struct stOcdActiveMsg; }
class rAdjustParam;
class rOcdIrAdj;
class rOcdIrAdjPL;
class rOcdPriorityParam;
class rOcdStatusParamRes;

// Declarations
class sObjCondition;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class sObjCondition : public cSystem
{
    // inferred: cOcdInfo::reportCheatOcd names sObjCondition::mCntCheatOcdAlter_Gold
    friend class cOcdInfo;
public:
    enum OCD_COMMON_PATAM_TYPE
    {
        OCD_COMMON_EM = 0,
        OCD_COMMON_BIG_EM = 1,
        OCD_COMMON_HMEM = 2,
        OCD_COMMON_PL_PAWN = 3,
        OCD_COMMON_TYPE_NUM = 4,
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
    sObjCondition();
    virtual ~sObjCondition();
    static sObjCondition* getInstance();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool checkAnnihilation(u32 OcdUID, u32 otherOcdUID) const;
    const cOcdPriorityParam* getPriorityData(u32 OcdUID) const;
    u32 getOcdUID(u32 index);
    nDDOGame::ELEMENT_TYPE convertOcdToElement(u32 OcdUID) const;
    u32 convertElementToOcd(nDDOGame::ELEMENT_TYPE type) const;
    void createResource();
    void releaseResource();
    void cheatCheck();
    void composeOcdActiveMsg(nObjCondition::stOcdActiveMsg& dstMsg, const nObjCondition::stOcdActiveInfo& srcInfo);
    void decomposeOcdActiveMsg(nObjCondition::stOcdActiveInfo& dstInfo, const nObjCondition::stOcdActiveMsg& srcMsg);
    rOcdStatusParamRes* getOcdStatusCommonRes(OCD_COMMON_PATAM_TYPE type) const;
    const cOcdIrAdj* getOcdIrAdjData(u32 Lv) const;
    const cOcdIrAdjPL* getOcdIrAdjPLData(u32 itemLank) const;
private:
    void setPriorityRes(rOcdPriorityParam* pRes);
    void setStatusCommonRes(rOcdStatusParamRes* pRes, OCD_COMMON_PATAM_TYPE type);
    void setOcdIrAdjRes(rOcdIrAdj* pRes);
    rOcdIrAdj* getOcdIrAdjRes() const;
    void setOcdIrAdjPLRes(rOcdIrAdjPL* pRes);
    rOcdIrAdjPL* getOcdIrAdjPLRes() const;
public:
    u32 getCntCheatOcdAlter_PL() const;
    void setCntCheatOcdAlter_PL(u32 NewValue);
    u32 getCntCheatOcdAlter_EM() const;
    void setCntCheatOcdAlter_EM(u32 NewValue);
    u32 getCntCheatOcdAlter_Gold() const;
    void setCntCheatOcdAlter_Gold(u32 NewValue);
private:
    rAdjustParam* mpSystemParamRes;  // offset: 0x18
    rOcdPriorityParam* mpPriOrityTable;  // offset: 0x20
    nDDOUtility::cArray<rOcdStatusParamRes*, 4> mpOcdStatusCommonRes;  // offset: 0x28
    rOcdIrAdj* mpOcdIrAdjRes;  // offset: 0x48
    rOcdIrAdjPL* mpOcdIrAdjPLRes;  // offset: 0x50
    u32 mCntCheatOcdAlter_PL;  // offset: 0x58
    u32 mCntCheatOcdAlter_EM;  // offset: 0x5c
    u32 mCntCheatOcdAlter_Gold;  // offset: 0x60
    f32 mSendInterval;  // offset: 0x64
public:
    static MyDTI DTI;
    static sObjCondition* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sObjCondition* sObjCondition::getInstance() {
    return ::sObjCondition::mpInstance;
}
