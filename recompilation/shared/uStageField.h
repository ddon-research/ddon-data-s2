#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtSynchronize.h"
#include "cSplitBase.h"
#include "cUnit.h"
#include "nStage.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtVector3;
class cDraw;
class cSplitArc;
class cSplitLot;
struct stStageSplitData;

// Declarations
class uStageFieldCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uStageFieldCtrl : public cUnit
{
public:
    enum
    {
        SPLIT_NUM_X = 3,
        SPLIT_NUM_Z = 3,
        SPLIT_NUM = 9,
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
    uStageFieldCtrl();
    virtual ~uStageFieldCtrl();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void initSplitData(s32 stageNo);
    s32 getNowX() const;
    s32 getNowZ() const;
    bool calcFieldArea(const MtVector3& pos, s32& outX, s32& outZ);
    bool isSetup();
    void sbcSetMatrix();
    const stStageSplitData* getSplitData();
    u32 getSplitNumX() const;
    u32 getSplitNumZ() const;
    f32 getSplitLengthX() const;
    f32 getSplitLengthZ() const;
    f32 getSplitStartPosX() const;
    f32 getSplitStartPosZ() const;
    void setBlockArcLoad(s32 stageNo, MtVector3& plPos);
    bool isBlockArcLoadOk();
protected:
    void updateXZ();
private:
    bool isSplitLot(s32 x, s32 z);
    s32 getSplitLotStatus(s32 x, s32 z);
    cSplitLot* getSplitLot(s32 x, s32 z);
    MtVector3 getMyPlayerPos();
    bool checkPlayerRange(s32 x, s32 z);
    bool checkPlayerRangePos(s32 x, s32 z, MtVector3& pos) const;
    void calcEnableSplitAreaRange(s32 areaX, s32 areaZ, s32& xmin, s32& xmax, s32& zmin, s32& zmax) const;
    bool updateLot(bool isBlocking, bool update);
    void setLotResource();
    bool isSetResourceSplitLot(s32 x, s32 z, bool update);
    bool updateArc(bool isBlocking, bool update);
    bool isBlockArcLoadOk(s32 x, s32 z);
private:
    s32 mAreaNo;  // offset: 0x48
    s32 mNowX;  // offset: 0x4c
    s32 mNowZ;  // offset: 0x50
    s32 mOldX;  // offset: 0x54
    s32 mOldZ;  // offset: 0x58
    bool mIsSetup;  // offset: 0x5c
    bool mIsSetupOffsetModel;  // offset: 0x5d
    bool mIsSetupOffsetLight;  // offset: 0x5e
    stStageSplitData mSplitData;  // offset: 0x60
    MtTypedArray<cSplitLot> mSplitLotAry;  // offset: 0x78
    MtTypedArray<cSplitArc> mSplitArcAry;  // offset: 0x98
    MtCriticalSection mCS;  // offset: 0xb8
public:
    static MyDTI DTI;
private:
    static const stStageSplitData mSplitDataTbl[];
};

// Inline, no code of its own: checked where it is inlined.
inline bool uStageFieldCtrl::isSetup() {
    return this->mIsSetup;
}
