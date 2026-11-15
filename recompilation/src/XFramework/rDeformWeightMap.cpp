// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rDeformWeightMap.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cResource.h"
#include "nDrawTexture.h"
#include "nDrawVertexBuffer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rDeformWeightMap::usage() {
}

const MtDTI& rDeformWeightMap::getDTI() const {
    return rDeformWeightMap::DTI;
}

inline void* rDeformWeightMap::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rDeformWeightMap::DTI)->memAlloc(sz, align, rDeformWeightMap::DTI.mID);
}

inline void rDeformWeightMap::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rDeformWeightMap::DTI)->memFree(p_addr);
}

void rDeformWeightMap::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
}

__attribute__((weak)) bool rDeformWeightMap::save(MtStream& out) {
        MtDataWriter w(out, 4096, 4096);
        w.writeU32(mHeader.magic);
        w.writeU32(mHeader.version);
        w.writeU32(mGrassWind);
        w.writeU32(mDetailedWind);
        w.writeU32(mPseudoWind);
        w.writeF32(mWindScalePoint);
        w.writeF32(mWindScaleDirection);
        w.writeU32(mNCollision);
        w.writeF32(mNCGlobalWeight);
        w.writeU32(mImageSpaceCollision);
        w.writeU32(mApproxScrCollision);
        w.writeU32(mScrCollision);
        w.writeU32(mSbcType);
        w.writeU32(mSbcFilter);
        w.writeU32(mColliderCollision);
        w.writeU32(mColliderType);
        w.writeU32(mColliderFilter);
        w.writeF32(mVtxColSize);
        w.writeU32(mResetRestart);
        w.writeU32(mSimCulling);
        w.writeF32(mAlpha);
        w.writeU32(mMaxIterate);
        {
            MtFloat3 t1;
            t1.x = mGravity.x;
            t1.y = mGravity.y;
            t1.z = mGravity.z;
            w.writeV3(t1);
        }
        w.writeF32(mWeightOffset);
        w.writeF32(mAvoidZFight);
        w.writeF32(mWorldCoeffTrans);
        w.writeF32(mWorldCoeffRot);
        w.writeS32(mBaseJointNo);
        w.writeU32(mWindGroupMask);
        w.writeF32(mSoundThreashold);
        w.writeU32(mLocalOnly);
        w.writeU32(mNumLOD);
    
        u32 num = (mNumLOD != 0) ? mNumLOD : 1;
        for (u32 i = 0; i < num; ++i) {
            w.writeU32(mpLOD[i].mNumParticles);
            w.writeU32(mpLOD[i].mVtxTexH);
            w.writeU32(mpLOD[i].mWindBarycentricIdx);
    
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 8;
                void* buffer2 = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                transferGpu2Cpu(buffer2, mpLOD[i].mpTexInit, TEX_W, mpLOD[i].mVtxTexH, 8);
                w.write(buffer2, size);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer2);
            }
            for (u32 j = 0; j < 8; ++j) {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 8;
                void* buffer2 = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                transferGpu2Cpu(buffer2, mpLOD[i].mpTexBatchVtx[j], TEX_W, mpLOD[i].mVtxTexH, 8);
                w.write(buffer2, size);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer2);
            }
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 8;
                void* buffer2 = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                transferGpu2Cpu(buffer2, mpLOD[i].mpTexFixPrimVtx, TEX_W, mpLOD[i].mVtxTexH, 8);
                w.write(buffer2, size);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer2);
            }
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 16;
                void* buffer2 = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                transferGpu2Cpu(buffer2, mpLOD[i].mpTexFixJoint, TEX_W, mpLOD[i].mVtxTexH, 16);
                w.write(buffer2, size);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer2);
            }
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 16;
                void* buffer2 = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                transferGpu2Cpu(buffer2, mpLOD[i].mpTexFixWeight, TEX_W, mpLOD[i].mVtxTexH, 16);
                w.write(buffer2, size);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer2);
            }
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 8;
                void* buffer2 = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                transferGpu2Cpu(buffer2, mpLOD[i].mpTexFixNormal, TEX_W, mpLOD[i].mVtxTexH, 8);
                w.write(buffer2, size);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer2);
            }
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 8;
                void* buffer2 = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                transferGpu2Cpu(buffer2, mpLOD[i].mpTexWindNormal, TEX_W, mpLOD[i].mVtxTexH, 8);
                w.write(buffer2, size);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer2);
            }
    
            {
                u32 size = mpLOD[i].mpSoftBodyVB->getBufferSize();
                w.writeU32(size);
                void* buffer2 = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                void* temp3 = mpLOD[i].mpSoftBodyVB->map(nDraw::MAP_READ);
                memcpy(buffer2, temp3, size);
                mpLOD[i].mpSoftBodyVB->unmap();
                w.write(buffer2, size);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer2);
            }
    
            w.write(mpLOD[i].mVbByteIdx, mpLOD[i].mNumParticles * sizeof(u32));
            w.write(mpLOD[i].mVbPrimIdx, mpLOD[i].mNumParticles * sizeof(u32));
        }
    
        w.writeU32(mSoftBodyVBstride);
        w.writeU32(mVertexBaseNum);
        w.write(mpVertexBase, mVertexBaseNum * sizeof(u32));
        w.writeU32(mPrimNum);
        w.write(mpIsSimPerPrim, mPrimNum * sizeof(s32));
        w.write(mpReductionVertexBase, mPrimNum * sizeof(u32));
        return true;
}

__attribute__((weak)) bool rDeformWeightMap::load(MtStream& in) {
        clear();
        MtDataReader r(in, 4096);
        mHeader.magic = r.readU32();
        mHeader.version = static_cast<u8>(r.readU32());
        if (mHeader.magic != 0x4D5744 || mHeader.version != DATA_VERSION) {
            return false;
        }
    
        mGrassWind = (r.readU32() != 0);
        mDetailedWind = (r.readU32() != 0);
        mPseudoWind = (r.readU32() != 0);
        mWindScalePoint = r.readF32();
        mWindScaleDirection = r.readF32();
        mNCollision = (r.readU32() != 0);
        mNCGlobalWeight = r.readF32();
        mImageSpaceCollision = (r.readU32() != 0);
        mApproxScrCollision = (r.readU32() != 0);
        mScrCollision = (r.readU32() != 0);
        mSbcType = r.readU32();
        mSbcFilter = r.readU32();
        mColliderCollision = (r.readU32() != 0);
        mColliderType = r.readU32();
        mColliderFilter = r.readU32();
        mVtxColSize = r.readF32();
        mResetRestart = (r.readU32() != 0);
        mSimCulling = (r.readU32() != 0);
        mAlpha = r.readF32();
        mMaxIterate = r.readU32();
        MtFloat3 gravity = r.readV3();
        mGravity = gravity;
        mWeightOffset = r.readF32();
        mAvoidZFight = r.readF32();
        mWorldCoeffTrans = r.readF32();
        mWorldCoeffRot = r.readF32();
        mBaseJointNo = r.readS32();
        mWindGroupMask = r.readU32();
        mSoundThreashold = r.readF32();
        mLocalOnly = (r.readU32() != 0);
    
        mNumLOD = r.readU32();
        u32 num = (mNumLOD != 0) ? mNumLOD : 1;
        mpLOD = new LOD[num];
    
        for (u32 i = 0; i < num; ++i) {
            mpLOD[i].mNumParticles = r.readU32();
            mpLOD[i].mVtxTexH = r.readU32();
            mpLOD[i].mWindBarycentricIdx = r.readU32();
    
            mpLOD[i].mpTexInit = new (16u) nDraw::Texture(TEX_W, mpLOD[i].mVtxTexH, 1, 1, nDraw::FORMAT_R16G16B16A16_FLOAT, nDraw::USAGE_MANAGED, 0, nullptr, 0, nullptr, nDraw::TEXMEMORY_VRAM);
            for (u32 j = 0; j < 9; ++j) {
                nDraw::Texture*& t1 = (j < 8) ? mpLOD[i].mpTexBatchVtx[j] : mpLOD[i].mpTexFixPrimVtx;
                t1 = new (16u) nDraw::Texture(TEX_W, mpLOD[i].mVtxTexH, 1, 1, nDraw::FORMAT_R16G16B16A16_FLOAT, nDraw::USAGE_MANAGED, 0, nullptr, 0, nullptr, nDraw::TEXMEMORY_VRAM);
            }
            mpLOD[i].mpTexFixJoint = new (16u) nDraw::Texture(TEX_W, mpLOD[i].mVtxTexH, 1, 1, nDraw::FORMAT_R32G32B32A32_FLOAT, nDraw::USAGE_MANAGED, 0, nullptr, 0, nullptr, nDraw::TEXMEMORY_VRAM);
            mpLOD[i].mpTexFixWeight = new (16u) nDraw::Texture(TEX_W, mpLOD[i].mVtxTexH, 1, 1, nDraw::FORMAT_R32G32B32A32_FLOAT, nDraw::USAGE_MANAGED, 0, nullptr, 0, nullptr, nDraw::TEXMEMORY_VRAM);
            mpLOD[i].mpTexFixNormal = new (16u) nDraw::Texture(TEX_W, mpLOD[i].mVtxTexH, 1, 1, nDraw::FORMAT_R16G16B16A16_FLOAT, nDraw::USAGE_MANAGED, 0, nullptr, 0, nullptr, nDraw::TEXMEMORY_VRAM);
            mpLOD[i].mpTexWindNormal = new (16u) nDraw::Texture(TEX_W, mpLOD[i].mVtxTexH, 1, 1, nDraw::FORMAT_R16G16B16A16_FLOAT, nDraw::USAGE_MANAGED, 0, nullptr, 0, nullptr, nDraw::TEXMEMORY_VRAM);
    
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 8;
                void* buffer = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                r.read(buffer, size);
                transferCpu2Gpu(mpLOD[i].mpTexInit, buffer, TEX_W, mpLOD[i].mVtxTexH, 8);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer);
            }
            for (u32 j = 0; j < 9; ++j) {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 8;
                void* buffer = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                r.read(buffer, size);
                nDraw::Texture* t2 = (j < 8) ? mpLOD[i].mpTexBatchVtx[j] : mpLOD[i].mpTexFixPrimVtx;
                transferCpu2Gpu(t2, buffer, TEX_W, mpLOD[i].mVtxTexH, 8);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer);
            }
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 16;
                void* buffer = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                r.read(buffer, size);
                transferCpu2Gpu(mpLOD[i].mpTexFixJoint, buffer, TEX_W, mpLOD[i].mVtxTexH, 16);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer);
            }
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 16;
                void* buffer = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                r.read(buffer, size);
                transferCpu2Gpu(mpLOD[i].mpTexFixWeight, buffer, TEX_W, mpLOD[i].mVtxTexH, 16);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer);
            }
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 8;
                void* buffer = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                r.read(buffer, size);
                transferCpu2Gpu(mpLOD[i].mpTexFixNormal, buffer, TEX_W, mpLOD[i].mVtxTexH, 8);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer);
            }
            {
                u32 size = mpLOD[i].mVtxTexH * TEX_W * 8;
                void* buffer = MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memAlloc(size, 16);
                r.read(buffer, size);
                transferCpu2Gpu(mpLOD[i].mpTexWindNormal, buffer, TEX_W, mpLOD[i].mVtxTexH, 8);
                MtMemory::mpAllocatorType[MtMemoryAllocator::TEMPORARY]->memFree(buffer);
            }
    
            {
                u32 size = r.readU32();
                mpLOD[i].mpSoftBodyVB = new (16u) nDraw::VertexBuffer(size, nDraw::USAGE_MANAGED, nullptr);
                void* buffer = mpLOD[i].mpSoftBodyVB->map(nDraw::MAP_WRITE);
                r.read(buffer, size);
                mpLOD[i].mpSoftBodyVB->unmap();
            }
    
            mpLOD[i].mVbByteIdx = static_cast<u32*>(memAlloc(mpLOD[i].mNumParticles * sizeof(u32)));
            r.read(mpLOD[i].mVbByteIdx, mpLOD[i].mNumParticles * sizeof(u32));
            mpLOD[i].mVbPrimIdx = static_cast<u32*>(memAlloc(mpLOD[i].mNumParticles * sizeof(u32)));
            r.read(mpLOD[i].mVbPrimIdx, mpLOD[i].mNumParticles * sizeof(u32));
        }
    
        mSoftBodyVBstride = r.readU32();
        mVertexBaseNum = r.readU32();
        mpVertexBase = static_cast<u32*>(memAlloc(mVertexBaseNum * sizeof(u32)));
        r.read(mpVertexBase, mVertexBaseNum * sizeof(u32));
        mPrimNum = r.readU32();
        mpIsSimPerPrim = static_cast<s32*>(memAlloc(mPrimNum * sizeof(s32)));
        mpReductionVertexBase = static_cast<u32*>(memAlloc(mPrimNum * sizeof(u32)));
        r.read(mpIsSimPerPrim, mPrimNum * sizeof(s32));
        r.read(mpReductionVertexBase, mPrimNum * sizeof(u32));
    
        mpQuadVB = new (16u) nDraw::VertexBuffer(sizeof(MtFloat2) * 4, nDraw::USAGE_MANAGED, nullptr);
        MtFloat2 simulationVertices[4];
        simulationVertices[0].x = -1.0f; simulationVertices[0].y = 1.0f;
        simulationVertices[1].x = -1.0f; simulationVertices[1].y = -1.0f;
        simulationVertices[2].x = 1.0f; simulationVertices[2].y = 1.0f;
        simulationVertices[3].x = 1.0f; simulationVertices[3].y = -1.0f;
        void* buffer = mpQuadVB->map(nDraw::MAP_WRITE);
        memcpy(buffer, simulationVertices, sizeof(simulationVertices));
        mpQuadVB->unmap();
        return true;
}

MT_CTSTR rDeformWeightMap::getExt() const {
    return "dwm";
}

__attribute__((weak)) void rDeformWeightMap::clear() {
    if (mpLOD != nullptr) {
        delete[] mpLOD;
        mpLOD = nullptr;
    }
    if (mpQuadVB != nullptr) {
        mpQuadVB->release();
        mpQuadVB = nullptr;
    }
    mNumLOD = 0;
    if (mpVertexBase != nullptr) {
        memFree(mpVertexBase);
        mpVertexBase = nullptr;
    }
    mVertexBaseNum = 0;
    mSoftBodyVBstride = 0;
    if (mpIsSimPerPrim != nullptr) {
        memFree(mpIsSimPerPrim);
        mpIsSimPerPrim = nullptr;
    }
    if (mpReductionVertexBase != nullptr) {
        memFree(mpReductionVertexBase);
        mpReductionVertexBase = nullptr;
    }
    mPrimNum = 0;
}

rDeformWeightMap::~rDeformWeightMap() {
    this->rDeformWeightMap::clear();
}

inline rDeformWeightMap::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDeformWeightMap::MyDTI rDeformWeightMap::DTI("rDeformWeightMap", &::cResource::DTI, 304ul, 0u, 0u);

MtObject* rDeformWeightMap::MyDTI::newInstance() const {
    return new (16u) rDeformWeightMap;
}

rDeformWeightMap::LOD::~LOD() {
    if (mpTexInit != nullptr) {
        mpTexInit->release();
        mpTexInit = nullptr;
    }
    for (u32 j = 0; j < 8; ++j) {
        if (mpTexBatchVtx[j] != nullptr) {
            mpTexBatchVtx[j]->release();
            mpTexBatchVtx[j] = nullptr;
        }
    }
    if (mpTexFixPrimVtx != nullptr) {
        mpTexFixPrimVtx->release();
        mpTexFixPrimVtx = nullptr;
    }
    if (mpTexFixJoint != nullptr) {
        mpTexFixJoint->release();
        mpTexFixJoint = nullptr;
    }
    if (mpTexFixWeight != nullptr) {
        mpTexFixWeight->release();
        mpTexFixWeight = nullptr;
    }
    if (mpTexFixNormal != nullptr) {
        mpTexFixNormal->release();
        mpTexFixNormal = nullptr;
    }
    if (mpTexWindNormal != nullptr) {
        mpTexWindNormal->release();
        mpTexWindNormal = nullptr;
    }
    if (mpTexPseudoWind != nullptr) {
        mpTexPseudoWind->release();
        mpTexPseudoWind = nullptr;
    }
    if (mpSoftBodyVB != nullptr) {
        mpSoftBodyVB->release();
        mpSoftBodyVB = nullptr;
    }
    if (mVbByteIdx != nullptr) {
        memFree(mVbByteIdx);
        mVbByteIdx = nullptr;
    }
    if (mVbPrimIdx != nullptr) {
        memFree(mVbPrimIdx);
        mVbPrimIdx = nullptr;
    }
}

