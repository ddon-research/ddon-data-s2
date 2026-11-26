// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cGridCollision.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollision.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const u32 cGridCollision::MAGIC = 0x6f637267;
const u32 cGridCollision::VERSION = 0x77c09c94;

const MtDTI& cGridCollision::getDTI() const {
    return cGridCollision::DTI;
}

void* cGridCollision::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memAlloc(sz, align, cGridCollision::DTI.mID);
}

void* cGridCollision::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cGridCollision::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memFree(p_addr);
}

cGridCollision::cGridCollision() {
    mMagic = 0;
    mVersion = 0;
    mFlgOutsideMemoryAllocate = false;
    mpGridInfo = nullptr;
    mGridSize = MtVector3::One;
    mGridSizeInv = MtVector3::One;
    mOffset = MtVector3::One;
    mGridNumX = 0;
    mGridNumZ = 0;
    mCellMode = 0;
    mTotalRegistNum = 0;
    mFlgStaticMode = false;
    mpStaticGridInfo = nullptr;
    mStaticGridRegistParamNum = 0;
    mpStaticGridRegistParam = nullptr;
    memset(mTraverseRefCount, 0, sizeof(mTraverseRefCount));
    memset(mTraverseNest, 0, sizeof(mTraverseNest));
}

cGridCollision::~cGridCollision() {
    clear();
}

__attribute__((weak)) void cGridCollision::initialize(const MtAABB& aabb, u32 GridNumX, u32 GridNumZ, u32 CellMode) {
    clear();
    const MtVector3 aabbSize = aabb.maxpos - aabb.minpos;
    mMagic = MAGIC;
    mVersion = VERSION;
    mGridSize = MtVector3(aabbSize.x / GridNumX, 0.0f, aabbSize.z / GridNumZ);
    mGridSizeInv = MtVector3(1.0f / mGridSize.x, 0.0f, 1.0f / mGridSize.z);
    mOffset = aabb.minpos;
    mGridNumX = GridNumX;
    mGridNumZ = GridNumZ;
    mBoundingAABB = aabb;
    memset(mTraverseRefCount, 0, sizeof(mTraverseRefCount));
    memset(mTraverseNest, 0, sizeof(mTraverseNest));
    mCellMode = CellMode;
    if (!mFlgStaticMode) {
        switch (mCellMode) {
        case 1:
            mpGridInfo = new cU16Array[mGridNumX * mGridNumZ];
            break;
        case 2:
            mpGridInfo = nullptr;
            break;
        case 0:
            mpGridInfo = new cU32Array[mGridNumX * mGridNumZ];
            break;
        }
    }
}

__attribute__((weak)) void cGridCollision::clear() {
    if (mpGridInfo != nullptr) {
        for (u32 i = 0; i < static_cast<u32>(mGridNumX * mGridNumZ); i++) {
            mpGridInfo[i].clear();
        }
        delete[] mpGridInfo;
        mpGridInfo = nullptr;
    }
    if (mFlgOutsideMemoryAllocate) {
        mpStaticGridInfo = nullptr;
        mpStaticGridRegistParam = nullptr;
    } else {
        if (mpStaticGridInfo != nullptr) {
            memFree(mpStaticGridInfo);
            mpStaticGridInfo = nullptr;
        }
        if (mpStaticGridRegistParam != nullptr) {
            memFree(mpStaticGridRegistParam);
            mpStaticGridRegistParam = nullptr;
        }
    }
    mFlgOutsideMemoryAllocate = false;
}

__attribute__((weak)) bool cGridCollision::getCellDataStaticU32(const MtVector3& pos, const u32* & pOutputRootU32, u32& OutputCellDataNum) const {
    DDON_STUB("cGridCollision::getCellDataStaticU32")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverse(const MtGeometry& TraverseGeometry, MtObject* pObject, nCollision::TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex) {
    DDON_STUB("cGridCollision::traverse")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseOnce(const MtGeometry& TraverseGeometry, MtObject* pObject, nCollision::TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex) {
    DDON_STUB("cGridCollision::traverseOnce")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseAdvance(const MtGeometry& TraverseGeometry, MtObject* pObject, cGridCollision::TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex) {
    DDON_STUB("cGridCollision::traverseAdvance")
    return {};
}

__attribute__((weak)) u32 cGridCollision::getGridStaticInfoLeafIndex(const cGridCollision::StaticGridInfo& GridInfo, u32 GridLeafIndex) {
    DDON_STUB("cGridCollision::getGridStaticInfoLeafIndex")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCore(const MtGeometry& TraverseGeometry, MtObject* pObject, cGridCollision::TRAVERSE_CALLBACK pCallbackFunc, uintptr SendParamU32, u32 ThreadIndex, bool FlgOneHitEnd) {
    DDON_STUB("cGridCollision::traverseCore")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traveseCallbackForCompatible(u32 x, u32 z, u32 LeafID, uintptr UserParam, uintptr SystemParam) {
    DDON_STUB("cGridCollision::traveseCallbackForCompatible")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseRay(const MtRay& ray, cGridCollision::INSIDE_TRAVERSE_CALLBACK CallbackFunc, uintptr UserParam, bool FlgOneHitEnd) {
    DDON_STUB("cGridCollision::traverseRay")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseLineSegment(const MtLineSegment& ls, cGridCollision::INSIDE_TRAVERSE_CALLBACK CallbackFunc, uintptr UserParam, bool FlgOneHitEnd) {
    DDON_STUB("cGridCollision::traverseLineSegment")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseLineSegmentCore(const MtLineSegment& lsL, cGridCollision::INSIDE_TRAVERSE_CALLBACK CallbackFunc, uintptr UserParam, bool FlgOneHitEnd, const s16 GridNoLsPt0U, const s16 GridNoLsPt0V, const s16 GridNoLsPt1U, const s16 GridNoLsPt1V, const f32 StartP0_U, const f32 StartP0_V, const s16 CheckMaxU, const s16 CheckMaxV, const f32 normalU, const f32 normalV, const f32 DirLsU, const f32 DirLsV, const s16 DirGridU, const s16 DirGridV, const s16 GridNumU, const s16 GridNumV, const bool FlgDirU_GT_Zero, const bool FlgDirV_GT_Zero, const u32 UseAxisU, const u32 UseAxisV, const f32 DebugDrawHeight) {
    DDON_STUB("cGridCollision::traverseLineSegmentCore")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainStaticNoneOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainStaticNoneOneHitEnd")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainStaticNoneDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainStaticNoneDefault")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainStaticHalfOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainStaticHalfOneHitEnd")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainStaticHalfDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainStaticHalfDefault")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainStaticFullOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainStaticFullOneHitEnd")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainStaticFullDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainStaticFullDefault")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainDefaultNoneOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainDefaultNoneOneHitEnd")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainDefaultNoneDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainDefaultNoneDefault")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainDefaultHalfOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainDefaultHalfOneHitEnd")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainDefaultHalfDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainDefaultHalfDefault")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainDefaultFullOneHitEnd(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainDefaultFullOneHitEnd")
    return {};
}

__attribute__((weak)) u32 cGridCollision::traverseCoreMainDefaultFullDefault(s32 x, s32 z, uintptr TraverseCallbackInfoPtr) {
    DDON_STUB("cGridCollision::traverseCoreMainDefaultFullDefault")
    return {};
}

inline cGridCollision::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGridCollision::MyDTI cGridCollision::DTI("cGridCollision", &::MtObject::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* cGridCollision::MyDTI::newInstance() const {
    DDON_STUB("cGridCollision::MyDTI::newInstance")
    return nullptr;
}

cGridCollisionRegistInfo::cGridCollisionRegistInfo() {
    mRegistParam = 0xFFFFFFFF;
}

cGridCollisionRegistInfo::~cGridCollisionRegistInfo() {
}

