// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rModel.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "nDrawIndexBuffer.h"
#include "nDrawMaterial.h"
#include "nDrawResource.h"
#include "nDrawVertexBuffer.h"
#include "rMaterial.h"
#include "sRender.h"
#include "sResource.h"
#include "sShader2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rModel::usage() {
}

const MtDTI& rModel::getDTI() const {
    return rModel::DTI;
}

inline void* rModel::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rModel::DTI)->memAlloc(sz, align, rModel::DTI.mID);
}

inline void rModel::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(p_addr);
}

inline rModel::rModel() : mRCNInfo() {
    mAttr = 16;
    mJointInfo = nullptr;
    mJointNum = 0;
    mBoundaryInfo = nullptr;
    mPrimitiveNum = 0;
    mPrimitiveInfo = nullptr;
    mImat = nullptr;
    mLmat = nullptr;
    mPartsNum = 0;
    mPartsInfo = nullptr;
    mVertexBufsize = 0;
    mVertexNum = 0;
    mIndexNum = 0;
    mMaterialNum = 0;
    mPolygonNum = 0;
    mpVertexBuffer = nullptr;
    mpIndexBuffer = nullptr;
    mMaterialName = nullptr;
    mpMaterials = nullptr;
    mpMaterial = nullptr;
    memset(static_cast<void*>(&mJointTable[0]), 255, 256ul);
}

bool rModel::loadEnd() {
    initMaterial();
    return true;
}

__attribute__((weak)) bool rModel::load(MtStream& in) {
    DDON_STUB("rModel::load")
    return {};
}

bool rModel::save(MtStream& out) {
    return false;
}

MtUI* rModel::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

__attribute__((weak)) void rModel::createProperty(MtPropertyList& s) {
    DDON_STUB("rModel::createProperty")
    /* stub */
}

__attribute__((weak)) void rModel::clear() {
    if ((sRender::mpInstance) != nullptr) {
        if (mpMaterials != nullptr) {
            if (mMaterialNum != 0) {
                u32 v0_0 = mMaterialNum;
                nDraw::Material* * v0_1 = mpMaterials;
                unsigned int i0_3 = 0;
                u32 v1_0;
                for (;;) {
                    if (v0_1[i0_3] != nullptr) {
                        v0_1[i0_3]->release();
                        mpMaterials[i0_3] = nullptr;
                        if ((i0_3 + 1u) >= mMaterialNum) {
                            v1_0 = mMaterialNum;
                            break;
                        }
                        v0_0 = mMaterialNum;
                    } else {
                        if ((i0_3 + 1u) >= v0_0) {
                            v1_0 = v0_0;
                            break;
                        }
                    }
                    v0_1 = mpMaterials;
                    i0_3 += 1u;
                }
                if (v1_0 > 4u) {
                    nDraw::Material* * t0 = mpMaterials;
                    MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(static_cast<void*>(t0));
                }
            }
            mpMaterials = nullptr;
        }
        if (mpVertexBuffer != nullptr) {
            mpVertexBuffer->release();
            mpVertexBuffer = nullptr;
        }
        if (mpIndexBuffer != nullptr) {
            mpIndexBuffer->release();
            mpIndexBuffer = nullptr;
        }
        if (mpMaterial != nullptr) {
            mpMaterial->release();
            mpMaterial = nullptr;
        }
        const u32 t1 = getDTI().mID;
        MtMatrix* t2 = mLmat;
        u32 t3 = rModel::DTI.mID;
        MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(static_cast<void*>(t2));
        if (t1 != t3) {
            MtMatrix* t4 = mImat;
            MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(static_cast<void*>(t4));
            JOINT_INFO* t5 = mJointInfo;
            MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(static_cast<void*>(t5));
            PRIMITIVE_INFO* t6 = mPrimitiveInfo;
            MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(static_cast<void*>(t6));
            PARTS_INFO* t7 = mPartsInfo;
            MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(static_cast<void*>(t7));
            BOUNDARY_INFO* t8 = mBoundaryInfo;
            MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(static_cast<void*>(t8));
            MATERIAL_NAME* t9 = mMaterialName;
            MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(static_cast<void*>(t9));
        }
        mLmat = nullptr;
        mImat = nullptr;
        mJointInfo = nullptr;
        mPrimitiveInfo = nullptr;
        mBoundaryInfo = nullptr;
        mPartsInfo = nullptr;
        mMaterialName = nullptr;
        mPrimitiveNum = 0;
        mMaterialNum = 0;
        mJointNum = 0;
        mPartsNum = 0;
        mRCNInfo.triangle_num = 0;
        if (mRCNInfo.triangle != nullptr) {
            mRCNInfo.triangle->release();
            mRCNInfo.triangle = nullptr;
        }
        if (mRCNInfo.vertex_to_index != nullptr) {
            mRCNInfo.vertex_to_index->release();
            mRCNInfo.vertex_to_index = nullptr;
        }
        u32* t10 = mRCNInfo.map_vertex_base;
        MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(static_cast<void*>(t10));
        mRCNInfo.map_vertex_base = nullptr;
    }
}

MT_CTSTR rModel::getExt() const {
    return "mod";
}

const nDraw::Material* rModel::getMaterial(u32 index) const {
    return mpMaterials[index];
}

rMaterial* rModel::getMaterialResource() {
    return mpMaterial;
}

u32 rModel::getPrimitiveIndexFromParts(u32 parts_no) {
    if (mPrimitiveNum != 0) {
        u32 i = 0;
        PRIMITIVE_INFO* p2 = mPrimitiveInfo;
        do {
            if (p2->parts_no == parts_no) {
                return i;
            }
            i += 1u;
            p2 += static_cast<int>(1);
        } while (i < mPrimitiveNum);
    }
    return 0;
}

u32 rModel::getRCNWidth() {
    return mRCNInfo.width;
}

u32 rModel::getRCNHeight() {
    return mRCNInfo.height;
}

rModel::~rModel() {
    this->rModel::clear();
}

__attribute__((weak)) void rModel::initMaterial() {
    sResource* t0 = sResource::mpInstance;
    cResource* t1 = t0->create(rMaterial::DTI, &mPath[0], 1u);
    mpMaterial = static_cast<rMaterial*>(t1);
    u32 t3 = mMaterialNum;
    nDraw::Material* * v0_0;
    unsigned int i0_3;
    if (t3 <= 4u) {
        mpMaterials = &mpMaterialsStack[0];
        if (t3 != 0) {
            v0_0 = &mpMaterialsStack[0];
            i0_3 = 0;
        } else {
            return;
        }
    } else {
        MtAllocator* t4 = MtMemoryAllocator::getAllocator(rModel::DTI);
        unsigned long t6 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t4) + 0);
        void* t7 = t4->memAlloc(t3 * 8u, 16u);
        u32 t9 = mMaterialNum;
        mpMaterials = static_cast<nDraw::Material* *>(t7);
        if (t9 != 0) {
            v0_0 = static_cast<nDraw::Material* *>(t7);
            i0_3 = 0;
        } else {
            return;
        }
    }
    for (;;) {
        v0_0[i0_3] = nullptr;
        rMaterial* t10 = mpMaterial;
        if (t10 != nullptr) {
            MATERIAL_NAME* t11 = mMaterialName;
            nDraw::Material* t12 = t10->getMaterial(&t11[i0_3].name[0]);
            nDraw::Material* * t14 = mpMaterials;
            t14[i0_3] = t12;
        }
        nDraw::Material* * t15 = mpMaterials;
        nDraw::Material* t16 = t15[i0_3];
        if (t16 == nullptr) {
            sShader2* t17 = sShader2::mpInstance;
            nDraw::Material* t18 = t17->mpNullMaterial;
            t15[i0_3] = t18;
            nDraw::Material* * t19 = mpMaterials;
            nDraw::Material* t20 = t19[i0_3];
            bool t21 = t20->addRef();
        } else {
            bool t21 = t16->addRef();
        }
        if ((i0_3 + 1u) >= mMaterialNum) {
            break;
        } else {
            v0_0 = mpMaterials;
            i0_3 += 1u;
        }
    }
}

inline rModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rModel::MyDTI rModel::DTI("rModel", &::cResource::DTI, 672ul, 0u, 0u);

MtObject* rModel::MyDTI::newInstance() const {
    return new (16u) rModel;
}

