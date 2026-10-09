#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cAIObject.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
class MtDTI;
class MtObject;
class MtPoint;
class MtSphere;
class MtVector3;
class cAIGridParam;
class cPawnEnableArea;
class uDDOModel;

// Declarations
class cAIGrid;
template <typename T> class cAIGridArrayResult;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIGridArrayResultIndex = cAIGridArrayResult<int>;
using cAIGridArrayResultPoint = cAIGridArrayResult<MtPoint>;
using cAIGridArrayResultPos = cAIGridArrayResult<MtVector3>;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cAIGrid : public cAIObject
{
public:
    class MyDTI;
public:
    using NearCheckFunc = bool(*)(cAIGrid*, s32, s32, const MtVector3&, void*);
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
    cAIGrid();
    cAIGrid(f32 x, f32 z);
    virtual ~cAIGrid();
private:
    void constructor();
public:
    void initGridNum(s32 x, s32 z);
    void initGridLen(f32 x, f32 z);
    void releaseGrid();
    void clearGrid();
    void setMaxMinHeight(f32, f32);
private:
    bool isNoUse() const;
public:
    void moveGridCenter(const MtVector3& centerOfsPos, bool shift);
    void moveGridZero(const MtVector3& zero, bool shift);
    void setGridValue(const cAIGridParam& param, const MtVector3& pos);
    void setGridValue(s32 val, f32 decreaseRatio, f32 maxRadius, f32 minRadius, const MtVector3& pos, u32 flag);
    void setGridValue(s32 val, f32 decreaseRatio, const MtSphere& shape, u32 flag);
    void setGridValue(s32 val, f32 decreaseRatio, const MtCapsule& shape, u32 flag);
    void setGridValue(s32 val, f32 decreaseRatio, const cPawnEnableArea& area, f32 angle, const MtVector3& pos, u32 flag);
    void setGridValue(s32 val, f32 decreaseRatio, f32 maxRadius, f32 minRadius, f32 angleRadius, f32 angle, const MtVector3& pos, u32 flag);
    void copyGrid(const cAIGrid& src);
    void onGrid(const cAIGrid& src, s32 val);
    bool createWayGrid(MtVector3* pDst, const MtVector3& startPos, const MtVector3& targetPos, const cAIGrid& disable, bool disableSlant);
    bool judgeCanUseHealingArrow(const MtVector3& startPos, const MtVector3& targetPos, const cAIGrid& disable);
private:
    void createWayGridSubSetDisable(const cAIGrid& disable);
    void createWayGridSubSetEnable(const MtVector3& pos);
    bool createWayGridSubTrace(const MtVector3& startPos, const MtVector3& targetPos, bool disableSlant);
    void createWayGridSubTraceSub(cAIGridArrayResultPoint& dst, s32 x, s32 z, s32 val, s32 add);
    bool createWayGridSubEnableWay(u32 targetGridX, u32 targetGridZ, u32 srcGridX, u32 srcGridZ);
    bool createWayGridSubEnableWayDisableSlant(u32 targetGridX, u32 targetGridZ, u32 srcGridX, u32 srcGridZ);
public:
    s32 getGridIndex(const MtVector3& pos) const;
    s32 getGridIndex(s32 x, s32 z) const;
    const s32* getGridValue(const MtVector3& pos) const;
    const s32* getGridValue(s32 x, s32 z) const;
    const s32* getGridValue(s32 index) const;
    bool getGridPos(MtVector3* pDst, s32 x, s32 z) const;
    bool getGridPos(MtVector3* pDst, s32 index) const;
    bool getGridPos(MtPoint* pDst, const MtVector3& pos) const;
    void getGridArray(cAIGridArrayResultPos* pDst, s32 minVal, s32 maxVal);
    void getGridArray(cAIGridArrayResultIndex* pDst, s32 minVal, s32 maxVal);
    bool getGridNearPos(MtVector3* pDst, const MtVector3& pos, s32 minVal, s32 maxVal, uDDOModel& owner, NearCheckFunc func, void* pParam);
    bool checkSafePos(const MtVector3& pos, s32 minVal, s32 maxVal, uDDOModel& owner, NearCheckFunc func, void* pParam);
private:
    s32* getGridValuePtr(const MtVector3& pos);
    s32* getGridValuePtr(s32 x, s32 z);
    s32* getGridValuePtr(s32 index);
public:
    static bool isGridNearPosNone(cAIGrid* pGrid, s32 gridIdx, s32 gridVal, const MtVector3& aimPos, void* pParam);
    static bool isGridNearPosRay(cAIGrid* pGrid, s32 gridIdx, s32 gridVal, const MtVector3& aimPos, void* pParam);
    void indexSort(cAIGridArrayResultIndex& dst);
private:
    void getGridPosDirect(MtVector3* pDst, s32 index) const;
    void getGridPointDirect(MtPoint* pDst, s32 index) const;
private:
    MtVector3 mGridZeroRealPos;  // offset: 0x10
    s32 mGridXNum;  // offset: 0x20
    s32 mGridZNum;  // offset: 0x24
    s32* mpGridValue;  // offset: 0x28
    f32 mGridEnableYMin;  // offset: 0x30
    f32 mGridEnableYMax;  // offset: 0x34
public:
    static MyDTI DTI;
};

template <typename T>
class cAIGridArrayResult
{
public:
    cAIGridArrayResult();
    ~cAIGridArrayResult();
    bool init(s32 max);
    void release();
    void addResult(const T& val);
    void addResultOnly(const T& val);
    const T& getResult(s32 idx) const;
    s32 getResultNum() const;
public:
    T* mpGridRet;  // offset: 0x0
    s16 mGridNum;  // offset: 0x8
    s16 mGridMax;  // offset: 0xa
};
