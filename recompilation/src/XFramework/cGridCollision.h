#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"

#include "../MT/MtAllocator.h"
#include "nCollision.h"

#include <string.h>

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
struct MtFloat3;
class MtGeometry;
class MtLineSegment;
class MtMatrix;
class MtRay;
class MtRayY;
class MtVector3;

namespace nCollisionUtil { struct LoadBuffer; }

// Declarations
class cGridCollision;
class cGridCollisionRegistInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using u32 = unsigned int;
using uintptr = __uintptr_t;
namespace nCollision { using TRAVERSE_CALLBACK = u32(MtObject::*)(uintptr, u32, uintptr); }
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;

class cGridCollision : public MtObject
{
public:
    enum CELL_MODE
    {
        CELLMODE_U32 = 0,
        CELLMODE_U16 = 1,
        CELLMODE_NONE = 2,
    };
public:
    template <typename _TYPE, unsigned int _BUFFER_OVER_ADD_SIZE> class cCellRegisterArray;
    class MyDTI;
    class cCellRegisterArrayBase;
    struct StaticGridInfo;
    struct TraverseSystemParam;
    struct TraverseCompatibileInfo;
    struct TraverseCallbackInfo;
public:
    using TRAVERSE_CALLBACK = u32(MtObject::*)(u32, u32, u32, uintptr, uintptr);
    using cU16Array = cGridCollision::cCellRegisterArray<unsigned short, 2>;
    using cU32Array = cGridCollision::cCellRegisterArray<unsigned int, 2>;
    using INSIDE_TRAVERSE_CALLBACK = u32(MtObject::*)(s32, s32, uintptr);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCellRegisterArrayBase
    {
    public:
        cCellRegisterArrayBase();
        ~cCellRegisterArrayBase();
        u16 length() const;
        void clear();
        static void* operator new(size_t);
        static void* operator new[](size_t sz);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void* padr);
        void* memAlloc(size_t);
        void memFree(void* padr);
        size_t memSize(void*);
        static MtAllocator* getAllocator();
    protected:
        void* mpArrayData;  // offset: 0x0
        u16 mArrayRegisterNum;  // offset: 0x8
        u16 mArrayBufferNum;  // offset: 0xa
    };
public:
    struct StaticGridInfo
    {
    public:
        u16 mLeafNum;  // offset: 0x0
        u32 mLeafStart;  // offset: 0x4
    };
public:
    struct TraverseSystemParam
    {
    public:
        void initialize(u32 _NowTraverseCount, u32 _NowThreadIndex, u32 _NowNest);
    public:
        u32 mNowTraverseCount;  // offset: 0x0
        u32 mNowThreadIndex;  // offset: 0x4
        u32 mNowNest;  // offset: 0x8
    };
public:
    struct TraverseCompatibileInfo
    {
    public:
        MtObject* pObject;  // offset: 0x0
        nCollision::TRAVERSE_CALLBACK pCallbackFunc;  // offset: 0x8
        size_t SendParamU32;  // offset: 0x18
    };
public:
    struct TraverseCallbackInfo
    {
    public:
        MtObject* pObject;  // offset: 0x0
        cGridCollision::TRAVERSE_CALLBACK pCallbackFunc;  // offset: 0x8
        size_t UserParam;  // offset: 0x18
        u32 LeafID;  // offset: 0x20
        size_t SystemParam;  // offset: 0x28
    };
public:
    template <typename _TYPE, unsigned int _BUFFER_OVER_ADD_SIZE>
    class cCellRegisterArray : public cGridCollision::cCellRegisterArrayBase
    {
    public:
        cCellRegisterArray();
        ~cCellRegisterArray();
        bool add(_TYPE param);
        bool erase(u32 EraseElementIndex);
        _TYPE at(u32 GetElementIndex) const;
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
    cGridCollision();
    virtual ~cGridCollision();
    void initialize(const MtAABB& aabb, u32 GridNumX, u32 GridNumZ, u32 CellMode);
    void clear();
    bool registParam(const MtAABB& aabb, u32 param, cGridCollisionRegistInfo& OutputRegistInfo);
    void unregistParam(cGridCollisionRegistInfo& RegistInfo);
    void changeStaticMode();
    bool isStaticMode() const;
    bool getCellDataStaticU16(const MtVector3& pos, const u16* & pOutputRootU16, u32& OutputCellDataNum) const;
    bool getCellDataStaticU32(const MtVector3& pos, const u32* & pOutputRootU32, u32& OutputCellDataNum) const;
    u32 traverse(const MtAABB& TraverseAABB, MtObject* pObject, nCollision::TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex);
    u32 traverse(const MtGeometry& TraverseGeometry, MtObject* pObject, nCollision::TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex);
    u32 traverseOnce(const MtGeometry& TraverseGeometry, MtObject* pObject, nCollision::TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex);
    u32 traverseAdvance(const MtGeometry& TraverseGeometry, MtObject* pObject, TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex);
    u32 traverseAdvanceOnce(const MtGeometry& TraverseGeometry, MtObject* pObject, TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex);
    bool convertLocalAABB2GridArea(const MtAABB& aabbL, s16& OutMinX, s16& OutMinZ, s16& OutMaxX, s16& OutMaxZ);
    bool convertLocalLineSegment2GridArea(const MtLineSegment&, s16&, s16&, s16&, s16&);
    bool convertWorldAABB2GridArea(const MtAABB& aabb, s16& OutMinX, s16& OutMinZ, s16& OutMaxX, s16& OutMaxZ);
    bool convertWorldLineSegment2GridArea(const MtLineSegment&, s16&, s16&, s16&, s16&);
    f32 convertLocalPosX2GridX(f32 x) const;
    f32 convertLocalPosZ2GridZ(f32 z) const;
    f32 convertLocalPosElement2GridElement(f32 pos, u32 AxisNo);
    f32 convertWorldPosX2GridX(f32 x);
    f32 convertWorldPosZ2GridZ(f32 z);
    f32 convertWorldPosElement2GridElement(f32, u32);
    f32 getLocalGridPosX(s16) const;
    f32 getLocalGridPosZ(s16) const;
    f32 getLocalGridPos(s32 GridNo, s16 AxisNo) const;
    f32 getWorldGridPosX(s16 GridNo) const;
    f32 getWorldGridPosZ(s16 GridNo) const;
    f32 getWorldGridPos(s16, s32) const;
    s32 getGridNumX() const;
    s32 getGridNumZ() const;
    s32 getGridNum(u32 AxisNo) const;
    u32 getGridNum() const;
    const MtVector3& getGridSize() const;
    const MtVector3& getGridSizeInverse() const;
    const MtVector3& getOffset() const;
    MtAABB getLocalGridAABB(s32, s32) const;
    MtAABB getLocalGridAABB(s32, s32, u32, u32) const;
    MtAABB getWorldGridAABB(s32, s32) const;
    MtAABB getWorldGridAABB(s32, s32, u32, u32) const;
    u32 getGridID(s32 x, s32 z) const;
    cU16Array* getGridInfo16(s32 x, s32 z);
    const cU16Array* getGridInfo16Const(s32, s32) const;
    cU32Array* getGridInfo32(s32 x, s32 z);
    const cU32Array* getGridInfo32Const(s32, s32) const;
    u32 getGridInfoRegistNum(s32 x, s32 z);
    StaticGridInfo* getGridStaticInfo(s32 x, s32 z);
    const StaticGridInfo* getGridStaticInfoConst(s32 x, s32 z) const;
    u32 getGridStaticInfoLeafIndex(const StaticGridInfo& GridInfo, u32 GridLeafIndex);
    const MtAABB& getBoundingAABBConst() const;
    u8 getCellMode() const;
    u32 getStaticGridRegistParamNum() const;
    void* memAlloc(u32 s);
    void memFree(void* padr);
    size_t memSize(void*);
    u32 getInsideWorkSize() const;
    bool copy(cGridCollision& src, const MtMatrix& mat);

    template <typename IO_CLASS> inline bool load(IO_CLASS& in, nCollisionUtil::LoadBuffer* pBuffer);
private:
    template <typename IO_CLASS> bool loadCore(IO_CLASS& in, const bool FlgEnableEndianChange, nCollisionUtil::LoadBuffer* pBuffer);

    template <typename IO_CLASS> bool saveCore(IO_CLASS& out, const bool FlgEnableEndianChange);
    friend class rZone;
public:
    template <typename IO_CLASS> inline bool save(IO_CLASS& out);
private:
public:
private:
    u32 traverseCore(const MtGeometry& TraverseGeometry, MtObject* pObject, TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex, bool FlgOneHitEnd);
    void addRefCount(const u32 ThreadIndex, TraverseSystemParam& SendParam);
    void subRefCount(const u32 ThreadIndex);
protected:
    u32 traveseCallbackForCompatible(u32 x, u32 z, u32 LeafID, uintptr UserParam, uintptr SystemParam);
    u32 traverseAABB(s16 startU, s16 startV, s16 endU, s16 endV, INSIDE_TRAVERSE_CALLBACK CallbackFunc, uintptr UserParam, bool FlgOneHitEnd);
    u32 traverseRayY(const MtRayY& rayY, INSIDE_TRAVERSE_CALLBACK CallbackFunc, uintptr UserParam, bool FlgOneHitEnd);
    u32 traverseRay(const MtRay& ray, INSIDE_TRAVERSE_CALLBACK CallbackFunc, uintptr UserParam, bool FlgOneHitEnd);
    u32 traverseLineSegment(const MtLineSegment& ls, INSIDE_TRAVERSE_CALLBACK CallbackFunc, uintptr UserParam, bool FlgOneHitEnd);
    u32 traverseLineSegmentCore(const MtLineSegment& lsL, INSIDE_TRAVERSE_CALLBACK CallbackFunc, uintptr UserParam, bool FlgOneHitEnd, const s16 GridNoLsPt0U, const s16 GridNoLsPt0V, const s16 GridNoLsPt1U, const s16 GridNoLsPt1V, const f32 StartP0_U, const f32 StartP0_V, const s16 CheckMaxU, const s16 CheckMaxV, const f32 normalU, const f32 normalV, const f32 DirLsU, const f32 DirLsV, const s16 DirGridU, const s16 DirGridV, const s16 GridNumU, const s16 GridNumV, const bool FlgDirU_GT_Zero, const bool FlgDirV_GT_Zero, const u32 UseAxisU, const u32 UseAxisV, const f32 DebugDrawHeight);
    u32 loadGridHalfDefault(s32 x, s32 z, uintptr DataReaderPtr);
    u32 loadGridFullDefault(s32 x, s32 z, uintptr DataReaderPtr);
    u32 loadGridHalfEndianChange(s32 x, s32 z, uintptr DataReaderPtr);
    u32 loadGridFullEndianChange(s32 x, s32 z, uintptr DataReaderPtr);
    u32 saveGridHalfDefault(s32 x, s32 z, uintptr DataReaderPtr);
    u32 saveGridFullDefault(s32 x, s32 z, uintptr DataReaderPtr);
    u32 saveGridHalfEndianChange(s32, s32, uintptr);
    u32 saveGridFullEndianChange(s32, s32, uintptr);
    u32 registParamCoreHalf(s32 x, s32 z, u32 registParam);
    u32 registParamCoreFull(s32 x, s32 z, u32 registParam);
    u32 unregistParamHalf(s32 x, s32 z, u32 TargetParam);
    u32 unregistParamFull(s32 x, s32 z, u32 TargetParam);
    u32 countRegistData(s32 x, s32 z, uintptr CountPtr);
    u32 changeStaticModeCoreHalf(s32 x, s32 z, uintptr StaticDataRootPtr);
    u32 changeStaticModeCoreFull(s32 x, s32 z, uintptr StaticDataRootPtr);
    u32 traverseCoreMainStaticNoneOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainStaticNoneDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainStaticHalfOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainStaticHalfDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainStaticFullOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainStaticFullDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainDefaultNoneOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainDefaultNoneDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainDefaultHalfOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainDefaultHalfDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainDefaultFullOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
    u32 traverseCoreMainDefaultFullDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr);
protected:
    u32 mMagic;  // offset: 0x8
    u32 mVersion;  // offset: 0xc
    bool mFlgOutsideMemoryAllocate;  // offset: 0x10
    MtAABB mBoundingAABB;  // offset: 0x20
    MtVector3 mGridSize;  // offset: 0x40
    MtVector3 mGridSizeInv;  // offset: 0x50
    MtVector3 mOffset;  // offset: 0x60
    cCellRegisterArrayBase* mpGridInfo;  // offset: 0x70
    u16 mGridNumX;  // offset: 0x78
    u16 mGridNumPadding;  // offset: 0x7a
    u16 mGridNumZ;  // offset: 0x7c
    u32 mTraverseRefCount[19][2];  // offset: 0x80
    u8 mTraverseNest[19];  // offset: 0x118
    u32 mTotalRegistNum;  // offset: 0x12c
    u8 mCellMode;  // offset: 0x130
    bool mFlgStaticMode;  // offset: 0x131
    StaticGridInfo* mpStaticGridInfo;  // offset: 0x138
    u32 mStaticGridRegistParamNum;  // offset: 0x140
    void* mpStaticGridRegistParam;  // offset: 0x148
public:
    static MyDTI DTI;
    static const u32 MAGIC;
    static const u32 VERSION;
    static const u8 TRAVERSE_MAX_NEST = 2;
    static const u32 DEFAULT_GRID_NUM = 128;
    static const u32 NOREGIST_WORK_PARAM = 4294967295;
    static const bool FLAG_MODE_STATIC = 1;
    static const bool FLAG_MODE_DEFAULT = 0;
    static const bool FLAG_MODE_ENDIAN_CHANGE_ENABLE = 1;
    static const bool FLAG_MODE_ENDIAN_CHANGE_DISABLE = 0;
    static const bool FLAG_MODE_ONE_HIT_END = 1;
    static const bool FLAG_MODE_ALL_HIT_CHECK = 0;
};

class alignas(16) cGridCollisionRegistInfo
{
public:
    cGridCollisionRegistInfo();
    ~cGridCollisionRegistInfo();
    void initialize(u32 RegistParam, const MtAABB& RegistAABB);
    bool isEqualRefCount(u32 NowCount, u32 ThreadIndex, u32 NestIndex) const;
    bool isEqualRefCount(const cGridCollision::TraverseSystemParam& GridSystemParam) const;
    void updateRefCount(u32 NowCount, u32 ThreadIndex, u32 NestIndex);
    void updateRefCount(const cGridCollision::TraverseSystemParam& GridSystemParam);
    const MtAABB& getRegistAABB() const;
    u32 getRegistParam() const;
    u32 getTraverseRefCount(u32 ThreadIndex, u32 NestIndex) const;
    bool isRegistedData() const;
    static void* operator new(size_t);
    static void* operator new[](size_t sz);
    static void* operator new(size_t sz, void* p);
    static void* operator new[](size_t, void*);
    static void operator delete(void*);
    static void operator delete[](void* padr);
    void* memAlloc(size_t);
    void memFree(void*);
    size_t memSize(void*);
    static MtAllocator* getAllocator();
    void copy(cGridCollisionRegistInfo& src, const MtMatrix& mat);

    template <typename IO_CLASS> inline bool load(IO_CLASS& r);

    template <typename IO_CLASS> inline bool save(IO_CLASS& w);
protected:
    MtFloat3 mRegistAABBMinPos;  // offset: 0x0
    u32 mRegistParam;  // offset: 0xc
    MtFloat3 mRegistAABBMaxPos;  // offset: 0x10
    u32 mTraverseRefCount[19][2];  // offset: 0x1c
};

inline void* cGridCollisionRegistInfo::operator new(size_t sz, void* p) {
    return p;
}

template <typename IO_CLASS>
inline bool cGridCollision::load(IO_CLASS& in, nCollisionUtil::LoadBuffer* pBuffer) {
    return loadCore(in, false, pBuffer);
}

template <typename IO_CLASS>
inline bool cGridCollisionRegistInfo::load(IO_CLASS& r) {
    r.read(&mRegistAABBMinPos, sizeof(mRegistAABBMinPos));
    r.read(&mRegistParam, sizeof(mRegistParam));
    r.read(&mRegistAABBMaxPos, sizeof(mRegistAABBMaxPos));
    memset(mTraverseRefCount, 0, sizeof(mTraverseRefCount));
    return true;
}

inline void* cGridCollision::memAlloc(u32 s) {
    return ::MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memAlloc(s, 16u, cGridCollision::DTI.getID());
}
inline void cGridCollision::memFree(void* padr) {
    ::MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memFree(padr);
}
inline void* cGridCollision::cCellRegisterArrayBase::memAlloc(size_t s) {
    return ::MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memAlloc(s, 16u);
}
inline void cGridCollision::cCellRegisterArrayBase::memFree(void* padr) {
    ::MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memFree(padr);
}
inline void* cGridCollision::cCellRegisterArrayBase::operator new[](size_t sz) {
    return ::MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memAlloc(sz, 16u);
}
inline void cGridCollision::cCellRegisterArrayBase::operator delete[](void* padr) {
    ::MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memFree(padr);
}
inline cGridCollision::cCellRegisterArrayBase::cCellRegisterArrayBase() : mpArrayData(nullptr), mArrayRegisterNum(0), mArrayBufferNum(0) {
}
inline void cGridCollision::cCellRegisterArrayBase::clear() {
    if (mpArrayData != nullptr) {
        memFree(mpArrayData);
        mpArrayData = nullptr;
    }
    mArrayRegisterNum = 0;
    mArrayBufferNum = 0;
}
inline cGridCollision::cCellRegisterArrayBase::~cCellRegisterArrayBase() {
    clear();
}
template <typename _TYPE, unsigned int _BUFFER_OVER_ADD_SIZE>
inline cGridCollision::cCellRegisterArray<_TYPE, _BUFFER_OVER_ADD_SIZE>::cCellRegisterArray() {
}
template <typename _TYPE, unsigned int _BUFFER_OVER_ADD_SIZE>
inline cGridCollision::cCellRegisterArray<_TYPE, _BUFFER_OVER_ADD_SIZE>::~cCellRegisterArray() {
}
template <typename _TYPE, unsigned int _BUFFER_OVER_ADD_SIZE>
inline bool cGridCollision::cCellRegisterArray<_TYPE, _BUFFER_OVER_ADD_SIZE>::add(_TYPE param) {
    if (mArrayRegisterNum >= mArrayBufferNum) {
        void* pNewArray = memAlloc((mArrayBufferNum + _BUFFER_OVER_ADD_SIZE) * sizeof(_TYPE));
        if (pNewArray == nullptr) {
            return false;
        }
        if (mpArrayData != nullptr) {
            memcpy(pNewArray, mpArrayData, mArrayRegisterNum * sizeof(_TYPE));
            memFree(mpArrayData);
        }
        mpArrayData = pNewArray;
        mArrayBufferNum += _BUFFER_OVER_ADD_SIZE;
    }
    static_cast<_TYPE*>(mpArrayData)[mArrayRegisterNum] = param;
    mArrayRegisterNum++;
    return true;
}
inline cGridCollision::cU16Array* cGridCollision::getGridInfo16(s32 x, s32 z) {
    if (x >= mGridNumX || z >= mGridNumZ) {
        return nullptr;
    }
    return &static_cast<cU16Array*>(mpGridInfo)[x + z * mGridNumX];
}
inline cGridCollision::cU32Array* cGridCollision::getGridInfo32(s32 x, s32 z) {
    if (x >= mGridNumX || z >= mGridNumZ) {
        return nullptr;
    }
    return &static_cast<cU32Array*>(mpGridInfo)[x + z * mGridNumX];
}

template <typename IO_CLASS>
bool cGridCollision::loadCore(IO_CLASS& in, const bool FlgEnableEndianChange, nCollisionUtil::LoadBuffer* pBuffer) {
    clear();
    in.read(&mMagic, sizeof(mMagic));
    if (mMagic != MAGIC) {
        return false;
    }
    in.read(&mVersion, sizeof(mVersion));
    if (mVersion != VERSION) {
        return false;
    }
    in.read(&mBoundingAABB, sizeof(mBoundingAABB));
    in.read(&mGridNumX, sizeof(mGridNumX));
    in.read(&mGridNumZ, sizeof(mGridNumZ));
    in.read(&mCellMode, sizeof(mCellMode));
    in.read(&mFlgStaticMode, sizeof(mFlgStaticMode));
    initialize(mBoundingAABB, mGridNumX, mGridNumZ, mCellMode);
    if (mFlgStaticMode) {
        if (pBuffer != nullptr) {
            mFlgOutsideMemoryAllocate = true;
            mpStaticGridInfo = static_cast<StaticGridInfo*>(pBuffer->allocate(mGridNumX * mGridNumZ * sizeof(StaticGridInfo)));
        } else {
            mFlgOutsideMemoryAllocate = false;
            mpStaticGridInfo = static_cast<StaticGridInfo*>(memAlloc(mGridNumX * mGridNumZ * sizeof(StaticGridInfo)));
        }
        in.read(mpStaticGridInfo, mGridNumX * mGridNumZ * sizeof(StaticGridInfo));
        in.read(&mStaticGridRegistParamNum, sizeof(mStaticGridRegistParamNum));
        if (mCellMode == 0) {
            const u32 Size = mStaticGridRegistParamNum * sizeof(u32);
            mpStaticGridRegistParam = pBuffer != nullptr ? pBuffer->allocate(Size) : memAlloc(Size);
            in.read(mpStaticGridRegistParam, Size);
        } else if (mCellMode == 1) {
            const u32 Size = mStaticGridRegistParamNum * sizeof(u16);
            mpStaticGridRegistParam = pBuffer != nullptr ? pBuffer->allocate(Size) : memAlloc(Size);
            in.read(mpStaticGridRegistParam, Size);
        }
        return true;
    }
    mFlgOutsideMemoryAllocate = false;
    if (mCellMode == 1) {
        for (s32 x = 0; x < mGridNumX; x++) {
            for (s32 z = 0; z < mGridNumZ; z++) {
                cU16Array* pGridInfo = getGridInfo16(x, z);
                u32 RegistNum;
                in.read(&RegistNum, sizeof(RegistNum));
                for (u32 i = 0; i < RegistNum; i++) {
                    u16 Param;
                    in.read(&Param, sizeof(Param));
                    pGridInfo->add(Param);
                }
            }
        }
    } else if (mCellMode == 0) {
        for (s32 x = 0; x < mGridNumX; x++) {
            for (s32 z = 0; z < mGridNumZ; z++) {
                cU32Array* pGridInfo = getGridInfo32(x, z);
                u32 RegistNum;
                in.read(&RegistNum, sizeof(RegistNum));
                for (u32 i = 0; i < RegistNum; i++) {
                    u32 Param;
                    in.read(&Param, sizeof(Param));
                    pGridInfo->add(Param);
                }
            }
        }
    }
    return true;
}

template <typename IO_CLASS>
inline bool cGridCollisionRegistInfo::save(IO_CLASS& w) {
    w.write(&mRegistAABBMinPos, sizeof(mRegistAABBMinPos));
    w.write(&mRegistParam, sizeof(mRegistParam));
    w.write(&mRegistAABBMaxPos, sizeof(mRegistAABBMaxPos));
    return true;
}
template <typename IO_CLASS>
inline bool cGridCollision::save(IO_CLASS& out) {
    return saveCore(out, false);
}
inline u16 cGridCollision::cCellRegisterArrayBase::length() const {
    return mArrayRegisterNum;
}
template <typename _TYPE, unsigned int _BUFFER_OVER_ADD_SIZE>
inline _TYPE cGridCollision::cCellRegisterArray<_TYPE, _BUFFER_OVER_ADD_SIZE>::at(u32 GetElementIndex) const {
    return static_cast<const _TYPE*>(mpArrayData)[GetElementIndex];
}

template <typename IO_CLASS>
bool cGridCollision::saveCore(IO_CLASS& out, const bool FlgEnableEndianChange) {
    mMagic = MAGIC;
    mVersion = VERSION;
    out.write(&mMagic, sizeof(mMagic));
    out.write(&mVersion, sizeof(mVersion));
    out.write(&mBoundingAABB, sizeof(mBoundingAABB));
    out.write(&mGridNumX, sizeof(mGridNumX));
    out.write(&mGridNumZ, sizeof(mGridNumZ));
    out.write(&mCellMode, sizeof(mCellMode));
    out.write(&mFlgStaticMode, sizeof(mFlgStaticMode));
    if (mFlgStaticMode) {
        if (!FlgEnableEndianChange) {
            out.write(mpStaticGridInfo, mGridNumX * mGridNumZ * sizeof(StaticGridInfo));
            out.write(&mStaticGridRegistParamNum, sizeof(mStaticGridRegistParamNum));
            if (mCellMode == 0) {
                out.write(mpStaticGridRegistParam, mStaticGridRegistParamNum * sizeof(u32));
            } else if (mCellMode == 1) {
                out.write(mpStaticGridRegistParam, mStaticGridRegistParamNum * sizeof(u16));
            }
        }
    } else if (mCellMode == 0) {
        for (s32 x = 0; x < mGridNumX; x++) {
            for (s32 z = 0; z < mGridNumZ; z++) {
                const cU32Array* pGridInfo = &static_cast<cU32Array*>(mpGridInfo)[x + z * mGridNumX];
                u32 RegistNum = pGridInfo->length();
                out.write(&RegistNum, sizeof(RegistNum));
                for (u32 i = 0; i < RegistNum; i++) {
                    u32 Param = pGridInfo->at(i);
                    out.write(&Param, sizeof(Param));
                }
            }
        }
    } else if (mCellMode == 1) {
        for (s32 x = 0; x < mGridNumX; x++) {
            for (s32 z = 0; z < mGridNumZ; z++) {
                const cU16Array* pGridInfo = &static_cast<cU16Array*>(mpGridInfo)[x + z * mGridNumX];
                u32 RegistNum = pGridInfo->length();
                out.write(&RegistNum, sizeof(RegistNum));
                for (u32 i = 0; i < RegistNum; i++) {
                    u16 Param = pGridInfo->at(i);
                    out.write(&Param, sizeof(Param));
                }
            }
        }
    }
    return true;
}
