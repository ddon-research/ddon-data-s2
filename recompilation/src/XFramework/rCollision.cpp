// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCollision.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtStream.h"
#include "cBVHCollision.h"
#include "cGridCollision.h"
#include "cResource.h"
#include "nCollision.h"
#include "sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rCollision::getDTI() const {
    return rCollision::DTI;
}

rCollision::~rCollision() {
    this->rCollision::clear();
}

bool rCollision::load(MtStream& in) {
    u32 t0 = (sResource::mpInstance)->mRCollisionDataReaderBufferSizeKB;
    u32 t1 = in.getLength();
    MtDataReader r(in, (t1 < (t0 * 1024u)) ? t1 : (t0 * 1024u));
    bool t2 = loadCore(r, false);
    return t2;
}

__attribute__((weak)) void rCollision::clear() {
    if (mpTriangle != nullptr && reinterpret_cast<Vertex*>(mpTriangle + mHeader.TotalTriangleNum) == mpVertex) {
        releasePartsBroadPhaseData();
        if (mpBvh != nullptr) {
            mpBvh->~cBVHCollision();
            mpBvh = nullptr;
        }
        if (mpGrid != nullptr) {
            mpGrid->~cGridCollision();
            mpGrid = nullptr;
        }
        if (mpPartsInfo != nullptr) {
            void* t1 = mpPartsInfo;
            MtMemoryAllocator::getAllocator(rCollision::DTI)->memFree(t1);
            mpPartsInfo = nullptr;
        }
        if (mpGridRegistInfo != nullptr) {
            const u32 PartsNum = mHeader.PartsInfoNum;
            for (u32 i = 0; i < PartsNum; i++) {
                mpGridRegistInfo[i].~cGridCollisionRegistInfo();
            }
            mpGridRegistInfo = nullptr;
        }
    } else {
        releasePartsBroadPhaseData();
        if (mpPartsInfo != nullptr) {
            void* t2 = mpPartsInfo;
            MtMemoryAllocator::getAllocator(rCollision::DTI)->memFree(t2);
            mpPartsInfo = nullptr;
        }
        mHeader.PartsInfoNum = 0;
        if (mpLeaf != nullptr) {
            void* t3 = mpLeaf;
            MtMemoryAllocator::getAllocator(rCollision::DTI)->memFree(t3);
            mpLeaf = nullptr;
        }
        mHeader.TotalLeafNum = 0;
        if (mpTriangle != nullptr) {
            void* t4 = mpTriangle;
            MtMemoryAllocator::getAllocator(rCollision::DTI)->memFree(t4);
            mpTriangle = nullptr;
        }
        mHeader.TotalTriangleNum = 0;
        if (mpVertex != nullptr) {
            void* t5 = mpVertex;
            MtMemoryAllocator::getAllocator(rCollision::DTI)->memFree(t5);
            mpVertex = nullptr;
        }
        mHeader.TotalVertexNum = 0;
        if (mpMaterialInfo != nullptr) {
            void* t6 = mpMaterialInfo;
            MtMemoryAllocator::getAllocator(rCollision::DTI)->memFree(t6);
            mpMaterialInfo = nullptr;
        }
        mpMaterialInfo = nullptr;
        mHeader.MaterialInfoNum = 0;
        if (mpBvh != nullptr) {
            delete mpBvh;
            mpBvh = nullptr;
        }
        if (mpGrid != nullptr) {
            delete mpGrid;
            mpGrid = nullptr;
        }
        if (mpGridRegistInfo != nullptr) {
            cGridCollisionRegistInfo* t7 = mpGridRegistInfo;
            size_t t8 = *(reinterpret_cast<size_t*>(t7) - 1);
            for (cGridCollisionRegistInfo* t9 = t7 + t8; t9 != t7;) {
                (--t9)->~cGridCollisionRegistInfo();
            }
            void* t10 = reinterpret_cast<char*>(t7) - 16;
            MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memFree(t10);
            mpGridRegistInfo = nullptr;
        }
    }
    if (mpSbcModifyClassIDArray != nullptr) {
        void* t11 = mpSbcModifyClassIDArray;
        MtMemoryAllocator::getAllocator(rCollision::DTI)->memFree(t11);
        mpSbcModifyClassIDArray = nullptr;
    }
}

MT_CTSTR rCollision::getExt() const {
    return "sbc";
}

__attribute__((weak)) u32 rCollision::traversePartsSpaceDivision(const MtGeometry& TraverseConvex, MtObject* pOwner, nCollision::TRAVERSE_CALLBACK pCallback, uintptr CallbackParam, u32 ThreadIndex) {
    DDON_STUB("rCollision::traversePartsSpaceDivision")
    return {};
}

__attribute__((weak)) u32 rCollision::traversePartsSpaceDivisionOnce(const MtGeometry& TraverseConvex, MtObject* pOwner, nCollision::TRAVERSE_CALLBACK pCallback, uintptr CallbackParam, u32 ThreadIndex) {
    DDON_STUB("rCollision::traversePartsSpaceDivisionOnce")
    return {};
}

__attribute__((weak)) u32 rCollision::traverseTriangleSpaceDivision(u32 PartsIndex, const MtGeometry& TraverseConvex, MtObject* pOwner, nCollision::TRAVERSE_CALLBACK pCallback, uintptr CallbackParam, u32 ThreadIndex) {
    DDON_STUB("rCollision::traverseTriangleSpaceDivision")
    return {};
}

__attribute__((weak)) u32 rCollision::traverseTriangleSpaceDivisionOnce(u32 PartsIndex, const MtGeometry& TraverseConvex, MtObject* pOwner, nCollision::TRAVERSE_CALLBACK pCallback, uintptr CallbackParam, u32 ThreadIndex) {
    DDON_STUB("rCollision::traverseTriangleSpaceDivisionOnce")
    return {};
}

__attribute__((weak)) bool rCollision::loadCore(MtDataReader& r, bool FlgEndianChange) {
    clear();
    Header LoadHeaderInfo;
    r.read(&LoadHeaderInfo, sizeof(LoadHeaderInfo));
    if (LoadHeaderInfo.Id[0] != 'S' || LoadHeaderInfo.Id[1] != 'B' || LoadHeaderInfo.Id[2] != 'C') {
        return false;
    }
    const u32 SubVersion = LoadHeaderInfo.Version % 100;
    const u32 MainVersion = LoadHeaderInfo.Version - SubVersion;
    if (MainVersion != 2011120600) {
        return false;
    }
    u32 BroadPhaseInsideBufferSize;
    r.read(&BroadPhaseInsideBufferSize, sizeof(BroadPhaseInsideBufferSize));
    nCollisionUtil::LoadBuffer buffer;
    if (!bulkAllocateMemoryAll(LoadHeaderInfo, BroadPhaseInsideBufferSize, buffer)) {
        return false;
    }
    u32 i;
    u32 j;
    mpPartsInfo = static_cast<PartsInfo*>(buffer.allocate(sizeof(PartsInfo) * LoadHeaderInfo.PartsInfoNum));
    r.read(mpPartsInfo, sizeof(PartsInfo) * LoadHeaderInfo.PartsInfoNum);
    for (i = 0; i < LoadHeaderInfo.PartsInfoNum; i++) {
        mpPartsInfo[i].pGridRegistInfo = nullptr;
        mpPartsInfo[i].pGrid = nullptr;
        mpPartsInfo[i].pBvh = nullptr;
    }
    mHeader.PartsInfoNum = LoadHeaderInfo.PartsInfoNum;
    {
        bool FlgTriangleLoadResult = true;
        for (i = 0; i < LoadHeaderInfo.PartsInfoNum; i++) {
            switch (LoadHeaderInfo.SpaceDivisionTypeTriangle) {
            case 0:
            case 1: {
                mpPartsInfo[i].pBvh = buffer.allocateNewBy<cBVHCollision>(1);
                if (!mpPartsInfo[i].pBvh->load(r, &buffer)) {
                    FlgTriangleLoadResult = false;
                }
                break;
            }
            case 2: {
                mpPartsInfo[i].pGrid = buffer.allocateNewBy<cGridCollision>(1);
                mpPartsInfo[i].pGridRegistInfo = buffer.allocateNewBy<cGridCollisionRegistInfo>(mpPartsInfo[i].LeafNum);
                const u32 LeafNum = mpPartsInfo[i].LeafNum;
                for (j = 0; j < LeafNum; j++) {
                    mpPartsInfo[i].pGridRegistInfo[j].load(r);
                }
                break;
            }
            }
            if (!FlgTriangleLoadResult) {
                break;
            }
        }
        if (!FlgTriangleLoadResult) {
            clear();
            return false;
        }
    }
    {
        bool FlgPartsLoadResult = true;
        switch (LoadHeaderInfo.SpaceDivisionTypeParts) {
        case 0:
        case 1: {
            mpBvh = buffer.allocateNewBy<cBVHCollision>(1);
            FlgPartsLoadResult = mpBvh->load(r, &buffer);
            break;
        }
        case 2: {
            mpGrid = buffer.allocateNewBy<cGridCollision>(1);
            mpGridRegistInfo = buffer.allocateNewBy<cGridCollisionRegistInfo>(LoadHeaderInfo.PartsInfoNum);
            const u32 PartsNum = LoadHeaderInfo.PartsInfoNum;
            for (j = 0; j < PartsNum; j++) {
                mpGridRegistInfo[j].load(r);
            }
            break;
        }
        }
        if (!FlgPartsLoadResult) {
            clear();
            return false;
        }
    }
    mpTriangle = static_cast<Triangle*>(buffer.allocate(sizeof(Triangle) * LoadHeaderInfo.TotalTriangleNum));
    r.read(mpTriangle, sizeof(Triangle) * LoadHeaderInfo.TotalTriangleNum);
    mHeader.TotalTriangleNum = LoadHeaderInfo.TotalTriangleNum;
    mpVertex = static_cast<Vertex*>(buffer.allocate(sizeof(Vertex) * LoadHeaderInfo.TotalVertexNum));
    r.read(mpVertex, sizeof(Vertex) * LoadHeaderInfo.TotalVertexNum);
    mHeader.TotalVertexNum = LoadHeaderInfo.TotalVertexNum;
    mpMaterialInfo = static_cast<MaterialInfo*>(buffer.allocate(sizeof(MaterialInfo) * LoadHeaderInfo.MaterialInfoNum));
    r.read(mpMaterialInfo, sizeof(MaterialInfo) * LoadHeaderInfo.MaterialInfoNum);
    mHeader.MaterialInfoNum = LoadHeaderInfo.MaterialInfoNum;
    mpLeaf = static_cast<Leaf*>(buffer.allocate(sizeof(Leaf) * LoadHeaderInfo.TotalLeafNum));
    r.read(mpLeaf, sizeof(Leaf) * LoadHeaderInfo.TotalLeafNum);
    mHeader.TotalLeafNum = LoadHeaderInfo.TotalLeafNum;
    {
        bool FlgTriangleLoadResult = true;
        for (i = 0; i < LoadHeaderInfo.PartsInfoNum; i++) {
            switch (LoadHeaderInfo.SpaceDivisionTypeTriangle) {
            case 2:
                if (!mpPartsInfo[i].pGrid->load(r, &buffer)) {
                    FlgTriangleLoadResult = false;
                }
                break;
            }
            if (!FlgTriangleLoadResult) {
                break;
            }
        }
        if (!FlgTriangleLoadResult) {
            clear();
            return false;
        }
    }
    {
        bool FlgPartsLoadResult = true;
        switch (LoadHeaderInfo.SpaceDivisionTypeParts) {
        case 2:
            FlgPartsLoadResult = mpGrid->load(r, &buffer);
            break;
        }
        if (!FlgPartsLoadResult) {
            clear();
            return false;
        }
    }
    mHeader = LoadHeaderInfo;
    return true;
}

__attribute__((weak)) void rCollision::releasePartsBroadPhaseData() {
    if (mpPartsInfo != nullptr) {
        if (mpTriangle != nullptr && reinterpret_cast<Vertex*>(mpTriangle + mHeader.TotalTriangleNum) == mpVertex) {
            for (u32 i = 0; i < mHeader.PartsInfoNum; i++) {
                if (mpPartsInfo[i].pBvh != nullptr) {
                    mpPartsInfo[i].pBvh->~cBVHCollision();
                    mpPartsInfo[i].pBvh = nullptr;
                }
                if (mpPartsInfo[i].pGrid != nullptr) {
                    mpPartsInfo[i].pGrid->~cGridCollision();
                    mpPartsInfo[i].pGrid = nullptr;
                }
                if (mpPartsInfo[i].pGridRegistInfo != nullptr) {
                    const u32 PartsTriangleNum = mpPartsInfo[i].TriangleNum;
                    for (u32 j = 0; j < PartsTriangleNum; j++) {
                        mpPartsInfo[i].pGridRegistInfo[j].~cGridCollisionRegistInfo();
                    }
                    mpPartsInfo[i].pGridRegistInfo = nullptr;
                }
            }
        } else {
            for (u32 i = 0; i < mHeader.PartsInfoNum; i++) {
                if (mpPartsInfo[i].pBvh != nullptr) {
                    delete mpPartsInfo[i].pBvh;
                    mpPartsInfo[i].pBvh = nullptr;
                }
                if (mpPartsInfo[i].pGrid != nullptr) {
                    delete mpPartsInfo[i].pGrid;
                    mpPartsInfo[i].pGrid = nullptr;
                }
                if (mpPartsInfo[i].pGridRegistInfo != nullptr) {
                    cGridCollisionRegistInfo* t1 = mpPartsInfo[i].pGridRegistInfo;
                    size_t t2 = *(reinterpret_cast<size_t*>(t1) - 1);
                    for (cGridCollisionRegistInfo* t3 = t1 + t2; t3 != t1;) {
                        (--t3)->~cGridCollisionRegistInfo();
                    }
                    void* t4 = reinterpret_cast<char*>(t1) - 16;
                    MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memFree(t4);
                    mpPartsInfo[i].pGridRegistInfo = nullptr;
                }
            }
        }
    }
}

__attribute__((weak)) bool rCollision::bulkAllocateMemoryAll(const rCollision::Header& LoadHeaderInfo, u32 BroadPhaseInsideWorkSize, nCollisionUtil::LoadBuffer& AllocateResult) {
    if (mHeader.PartsInfoNum != 0) {
        return false;
    }
    if (mHeader.MaterialInfoNum != 0) {
        return false;
    }
    if (mHeader.TotalLeafNum != 0) {
        return false;
    }
    if (mHeader.TotalTriangleNum != 0) {
        return false;
    }
    if (mHeader.TotalVertexNum != 0) {
        return false;
    }
    if (mpBvh != nullptr) {
        delete mpBvh;
        mpBvh = nullptr;
    }
    if (mpGrid != nullptr) {
        delete mpGrid;
        mpGrid = nullptr;
    }
    u32 AllocateSize = sizeof(PartsInfo) * LoadHeaderInfo.PartsInfoNum;
    AllocateSize += sizeof(MaterialInfo) * LoadHeaderInfo.MaterialInfoNum;
    AllocateSize += sizeof(Triangle) * LoadHeaderInfo.TotalTriangleNum;
    AllocateSize += sizeof(Vertex) * LoadHeaderInfo.TotalVertexNum;
    switch (LoadHeaderInfo.SpaceDivisionTypeTriangle) {
    case 0:
    case 1:
        AllocateSize += sizeof(cBVHCollision) * LoadHeaderInfo.PartsInfoNum;
        break;
    case 2:
        AllocateSize += sizeof(cGridCollision) * LoadHeaderInfo.PartsInfoNum;
        AllocateSize += sizeof(cGridCollisionRegistInfo) * LoadHeaderInfo.TotalLeafNum;
        break;
    }
    switch (LoadHeaderInfo.SpaceDivisionTypeParts) {
    case 0:
    case 1:
        AllocateSize += sizeof(cBVHCollision);
        break;
    case 2:
        AllocateSize += sizeof(cGridCollision) + sizeof(cGridCollisionRegistInfo) * LoadHeaderInfo.PartsInfoNum;
        break;
    }
    AllocateSize += BroadPhaseInsideWorkSize;
    AllocateSize += sizeof(Leaf) * LoadHeaderInfo.TotalLeafNum;
    u8* pAllocateData = static_cast<u8*>(MtMemoryAllocator::getAllocator(rCollision::DTI)->memAlloc(AllocateSize, 16u));
    if (pAllocateData == nullptr) {
        return false;
    }
    memset(pAllocateData, 0, AllocateSize);
    AllocateResult.pBuffer = pAllocateData;
    AllocateResult.Position = 0;
    AllocateResult.Size = AllocateSize;
    return true;
}

inline rCollision::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCollision::MyDTI rCollision::DTI("rCollision", &::cResource::DTI, 272ul, 0u, 0u);

__attribute__((weak)) MtObject* rCollision::MyDTI::newInstance() const {
    return new(16u) rCollision();
}

