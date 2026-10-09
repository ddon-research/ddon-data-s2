#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nErosionEnemy.h"
#include "nRegionStatus.h"
#include "rErosionRegion.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cErosionRegionRes;
class cpErosionEnemy;
class uCharacter;
class uEnemy;

// Declarations
class cErosionRegion;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cErosionRegion : public MtObject
{
public:
    enum CHANGE_STATE_REQ
    {
        CHANGE_STATE_REQ_NONE = 0,
        CHANGE_STATE_REQ_BREAK = 1,
        CHANGE_STATE_REQ_GENERATE = 2,
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
    cErosionRegion();
    void updatePtr();
    void updateEfcHandle();
    void beforeErosionRegion();
    void updateErosionRegion();
    void clearErosionRegion();
    void setErosionRes(const cErosionRegionRes& data);
    void setParentRegionNo(nRegionStatus::P_REGION_TYPE regionNo);
    void setErosionOwner(uCharacter* pEnemy, cpErosionEnemy* pCpErosionEnemy);
    bool isInvalid() const;
    nRegionStatus::P_REGION_CATEGORY getRegionCategory() const;
    nRegionStatus::P_REGION_TYPE getRegionNo() const;
    bool isActiveErosion() const;
    bool isRegenerate() const;
    bool isEnableBreak() const;
    void regenerateErosion();
    void breakErosion();
    void setupContextErosion(bool recvFlag, bool initSet);
    nErosionEnemy::EROSION_REGION_INIT_STATE getInitState() const;
    void setInitState(nErosionEnemy::EROSION_REGION_INIT_STATE state);
private:
    void updateWait();
    void updateActive();
    void changeErosionMode(nErosionEnemy::EROSION_MODE mode);
    nErosionEnemy::EROSION_MODE getErosionMode() const;
    void changeStateGenerate(bool isSetup);
    void changeStateBreak(bool isSetup);
    void setChangeStateReq(CHANGE_STATE_REQ stateReq);
private:
    cpErosionEnemy* mpErosionEnemy;  // offset: 0x8
    uEnemy* mpEnemy;  // offset: 0x10
    cErosionRegionRes mErosionRegionRes;  // offset: 0x18
    nErosionEnemy::EROSION_MODE mErosionMode;  // offset: 0x58
    nRegionStatus::P_REGION_TYPE mRegionNo;  // offset: 0x5c
    bool mIsSeted;  // offset: 0x60
    CHANGE_STATE_REQ mChangeStateReq;  // offset: 0x64
    nErosionEnemy::EROSION_REGION_INIT_STATE mInitState;  // offset: 0x68
public:
    static MyDTI DTI;
};
