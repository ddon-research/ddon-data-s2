// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cBVHCollision.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollision.h"
#include "../MT/MtCollisionMath.h"
#include "../MT/MtDTI.h"

#include "../MT/MtDataReader.h"
#include "nCollision.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cBVHCollision::getDTI() const {
    return cBVHCollision::DTI;
}

void* cBVHCollision::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cBVHCollision::DTI)->memAlloc(sz, align, cBVHCollision::DTI.mID);
}

void* cBVHCollision::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

cBVHCollision::cBVHCollision() {
    memset(&mHeader, 0, sizeof(mHeader));
    mpRootNodeBinary = nullptr;
    mpRootNodeBinaryOptimize = nullptr;
    mpRootNodeQuad = nullptr;
    mpLeafIndexArray = nullptr;
    mpBuildOnlineWork = nullptr;
}

cBVHCollision::~cBVHCollision() {
    clear();
}

bool cBVHCollision::load(MtDataReader& fin, nCollisionUtil::LoadBuffer* pBuffer) {
    return loadCore(fin, false, pBuffer);
}

__attribute__((weak)) bool cBVHCollision::loadCore(MtDataReader& fin, bool FlgEndianChenge, nCollisionUtil::LoadBuffer* pBuffer) {
    clear();
    fin.read(&mHeader, sizeof(mHeader));
    const u32 MyMagic = 0x43485642;
    if (mHeader.magic != MyMagic) {
        memset(&mHeader, 0, sizeof(mHeader));
        return false;
    }
    if (mHeader.version != 0x77b17b24) {
        memset(&mHeader, 0, sizeof(mHeader));
        return false;
    }
    switch (mHeader.type) {
    case 1: {
        const u32 AllocateSize = sizeof(NodeQuad) * mHeader.NodeNum;
        if (pBuffer != nullptr) {
            mHeader.FlgNodeOutsideAllocateMemory = true;
            mpRootNodeQuad = static_cast<NodeQuad*>(pBuffer->allocate(AllocateSize));
        } else {
            mHeader.FlgNodeOutsideAllocateMemory = false;
            mpRootNodeQuad = static_cast<NodeQuad*>(MtMemoryAllocator::getAllocator(cBVHCollision::DTI)->memAlloc(AllocateSize, 16u));
        }
        fin.read(mpRootNodeQuad, AllocateSize);
        break;
    }
    case 2: {
        const u32 AllocateSize = sizeof(NodeBinaryOptimize) * mHeader.NodeNum;
        if (pBuffer != nullptr) {
            mHeader.FlgNodeOutsideAllocateMemory = true;
            mpRootNodeBinaryOptimize = static_cast<NodeBinaryOptimize*>(pBuffer->allocate(AllocateSize));
        } else {
            mHeader.FlgNodeOutsideAllocateMemory = false;
            mpRootNodeBinaryOptimize = static_cast<NodeBinaryOptimize*>(MtMemoryAllocator::getAllocator(cBVHCollision::DTI)->memAlloc(AllocateSize, 16u));
        }
        fin.read(mpRootNodeBinaryOptimize, sizeof(NodeBinaryOptimize) * mHeader.NodeNum);
        break;
    }
    }
    return true;
}

__attribute__((weak)) void cBVHCollision::clear() {
    if (mHeader.FlgBasicAllocedMultiple) {
        deleteNodeBinaryBaseCore(mpRootNodeBinary);
        if (mpRootNodeBinary != nullptr) {
            delete[] mpRootNodeBinary;
            mpRootNodeBinary = nullptr;
        }
    } else if (mpRootNodeBinary != nullptr) {
        delete mpRootNodeBinary;
        mpRootNodeBinary = nullptr;
    }
    if (mpRootNodeBinaryOptimize != nullptr) {
        void* t5 = mpRootNodeBinaryOptimize;
        MtMemoryAllocator::getAllocator(cBVHCollision::DTI)->memFree(t5);
        mpRootNodeBinaryOptimize = nullptr;
    }
    if (!mHeader.FlgNodeOutsideAllocateMemory) {
        if (mpRootNodeQuad != nullptr) {
            void* t6 = mpRootNodeQuad;
            MtMemoryAllocator::getAllocator(cBVHCollision::DTI)->memFree(t6);
            mpRootNodeQuad = nullptr;
        }
    } else {
        mpRootNodeQuad = nullptr;
    }
    if (mpLeafIndexArray != nullptr) {
        void* t7 = mpLeafIndexArray;
        MtMemoryAllocator::getAllocator(cBVHCollision::DTI)->memFree(t7);
        mpLeafIndexArray = nullptr;
    }
    if (mpBuildOnlineWork != nullptr) {
        delete mpBuildOnlineWork;
        mpBuildOnlineWork = nullptr;
    }
}

void cBVHCollision::buildOnlineFast(const MtAABB& TotalAABB, MtAABB* aabbArray, bool FlgForceRebuild) {
    buildOnlineFast_MemoryAllocate();
    mpBuildOnlineWork->mNowNodeUseID = 0;
    mpBuildOnlineWork->mFlgMyLocalAABB = false;
    mpBuildOnlineWork->mpLocalAABB = aabbArray;
    mHeader.aabb.minpos.x = TotalAABB.minpos.x;
    mHeader.aabb.minpos.y = TotalAABB.minpos.y;
    mHeader.aabb.minpos.z = TotalAABB.minpos.z;
    mHeader.aabb.minpos.pad_ = 0.0f;
    mHeader.aabb.maxpos.x = TotalAABB.maxpos.x;
    mHeader.aabb.maxpos.y = TotalAABB.maxpos.y;
    mHeader.aabb.maxpos.z = TotalAABB.maxpos.z;
    mHeader.aabb.maxpos.pad_ = 0.0f;
    buildOnlineFastCore(FlgForceRebuild);
}

__attribute__((weak)) void cBVHCollision::buildOnlineFast_MemoryAllocate() {
    DDON_STUB("cBVHCollision::buildOnlineFast_MemoryAllocate")
    /* stub */
}

__attribute__((weak)) void cBVHCollision::buildOnlineFastCore(bool FlgForceRebuild) {
    DDON_STUB("cBVHCollision::buildOnlineFastCore")
    /* stub */
}

__attribute__((weak)) void cBVHCollision::registOwnerCore(MtObject* pOwner, u32 LeafNum, bool FlgUseOnline, bool FlgUseOnlineFastOnly) {
    DDON_STUB("cBVHCollision::registOwnerCore")
    /* stub */
}

__attribute__((weak)) void cBVHCollision::deleteNodeBinaryBaseCore(cBVHCollision::NodeBinaryBasic* pNowNode) {
    DDON_STUB("cBVHCollision::deleteNodeBinaryBaseCore")
    /* stub */
}

__attribute__((weak)) void cBVHCollision::initializeBVHSystemBuffer() {
    DDON_STUB("cBVHCollision::initializeBVHSystemBuffer")
    /* stub */
}

__attribute__((weak)) void cBVHCollision::releaseBVHSystemBuffer() {
    DDON_STUB("cBVHCollision::releaseBVHSystemBuffer")
    /* stub */
}

inline cBVHCollision::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cBVHCollision::MyDTI cBVHCollision::DTI("cBVHCollision", &::MtObject::DTI, 128ul, 0u, 0u);

cBVHCollision::TraverseStack* cBVHCollision::mpTraverseStack[2][19];

u32 cBVHCollision::mTraverseStackNest[19];

__attribute__((weak)) MtObject* cBVHCollision::MyDTI::newInstance() const {
    DDON_STUB("cBVHCollision::MyDTI::newInstance")
    return nullptr;
}

cBVHCollision::NodeBinaryBasic::~NodeBinaryBasic() {
    for (u32 i = 0; i < 2; i++) {
        if (!aFlgDelete[i]) {
            if (pChild[i] != nullptr) {
                delete pChild[i];
                pChild[i] = nullptr;
            }
        }
    }
}

__attribute__((weak)) MtCollisionUtil::MtVectorU4 cBVHCollision::NodeQuad::isIntersectRayYAll(const MtRayY& rayY) const {
    DDON_STUB("cBVHCollision::NodeQuad::isIntersectRayYAll")
    __builtin_unreachable();
}

__attribute__((weak)) MtCollisionUtil::MtVectorU4 cBVHCollision::NodeQuad::isIntersectRayAll(const MtRay& ray) const {
    DDON_STUB("cBVHCollision::NodeQuad::isIntersectRayAll")
    __builtin_unreachable();
}

__attribute__((weak)) MtCollisionUtil::MtVectorU4 cBVHCollision::NodeQuad::isIntersectLSAll(const MtLineSegment& ls) const {
    DDON_STUB("cBVHCollision::NodeQuad::isIntersectLSAll")
    __builtin_unreachable();
}

__attribute__((weak)) MtCollisionUtil::MtVectorU4 cBVHCollision::NodeQuad::isIntersectAABBAll(const MtAABB& aabb) const {
    DDON_STUB("cBVHCollision::NodeQuad::isIntersectAABBAll")
    __builtin_unreachable();
}

const MtDTI& cBVHCollision::cWorkBuildOnlineFast::getDTI() const {
    return cBVHCollision::cWorkBuildOnlineFast::DTI;
}

inline cBVHCollision::cWorkBuildOnlineFast::cWorkBuildOnlineFast() {
    mFlgMyLocalAABB = false;
    mFlgUsedBuildOnlineFast = false;
    mNowNodeUseID = 0;
    mNowNodeMax = 0;
    mpLocalAABB = nullptr;
    memset(static_cast<void*>(&mpStackOnlineBuildAll), 0, 264ul);
}

cBVHCollision::cWorkBuildOnlineFast::~cWorkBuildOnlineFast() {
    if (mFlgMyLocalAABB) {
        MtAABB* t0 = mpLocalAABB;
        if (t0 != nullptr) {
            MtMemoryAllocator::getAllocator(cBVHCollision::cWorkBuildOnlineFast::DTI)->memFree(static_cast<void*>(t0));
            JobParamOfLine* t1 = mpStackOnlineBuildAll;
            if (t1 != nullptr) {
                MtMemoryAllocator::getAllocator(cBVHCollision::cWorkBuildOnlineFast::DTI)->memFree(static_cast<void*>(t1));
            }
        } else {
            JobParamOfLine* t1 = mpStackOnlineBuildAll;
            if (t1 != nullptr) {
                MtMemoryAllocator::getAllocator(cBVHCollision::cWorkBuildOnlineFast::DTI)->memFree(static_cast<void*>(t1));
            }
        }
    } else {
        JobParamOfLine* t1 = mpStackOnlineBuildAll;
        if (t1 != nullptr) {
            MtMemoryAllocator::getAllocator(cBVHCollision::cWorkBuildOnlineFast::DTI)->memFree(static_cast<void*>(t1));
        }
    }
}

inline cBVHCollision::cWorkBuildOnlineFast::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cBVHCollision::cWorkBuildOnlineFast::MyDTI cBVHCollision::cWorkBuildOnlineFast::DTI("cBVHCollision::cWorkBuildOnlineFast", &::MtObject::DTI, 304ul, 0u, 0u);

MtObject* cBVHCollision::cWorkBuildOnlineFast::MyDTI::newInstance() const {
    return new (16u) cBVHCollision::cWorkBuildOnlineFast;
}

