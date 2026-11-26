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
#include "../MT/MtProperty.h"
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

inline u32 sResource::getRModelDataReaderBufferSizeByte() const {
    return this->mRModelDataReaderBufferSizeKB << 10;
}

inline MtSphere& MtSphere::operator=(const MtSphere& s) {
    __builtin_memcpy(this, &s, sizeof(MtSphere));
    return *this;
}

inline const MtVector3& MtVector3::operator=(const MtVector4& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->pad_ = 0.0f;
    return *this;
}

__attribute__((weak)) bool rModel::load(MtStream& in) {
    u32 t1 = sResource::getInstance()->getRModelDataReaderBufferSizeByte();
    u32 t2 = in.getLength();
    MtDataReader r(in, t2 < t1 ? t2 : t1);
    MODEL_HDR hdr;
    r.read(&hdr, sizeof(MODEL_HDR));
    if (hdr.magic != 0x444f4du || hdr.version != DATA_VERSION) {
        return false;
    }
    const u32 boundary_num = r.readU32();
    u32 AllocSize = static_cast<u32>(
        sizeof(MtMatrix) * hdr.jnt_num +
        sizeof(MtMatrix) * hdr.jnt_num +
        sizeof(BOUNDARY_INFO) * boundary_num +
        sizeof(PARTS_INFO) * hdr.parts_num +
        sizeof(PRIMITIVE_INFO) * hdr.primitive_num +
        sizeof(JOINT_INFO) * hdr.jnt_num +
        sizeof(MATERIAL_NAME) * hdr.material_num);
    u8* t3 = static_cast<u8*>(MtMemoryAllocator::getAllocator(rModel::DTI)->memAlloc(AllocSize, 16u));
    if (t3 == nullptr) {
        return false;
    }
    u32 t4 = 0;
    void* t5 = t3 + t4;
    t4 += static_cast<u32>(sizeof(MtMatrix) * hdr.jnt_num);
    mLmat = static_cast<MtMatrix*>(t5);
    t5 = t3 + t4;
    t4 += static_cast<u32>(sizeof(MtMatrix) * hdr.jnt_num);
    mImat = static_cast<MtMatrix*>(t5);
    t5 = t3 + t4;
    t4 += static_cast<u32>(sizeof(BOUNDARY_INFO)) * boundary_num;
    mBoundaryInfo = static_cast<BOUNDARY_INFO*>(t5);
    t5 = t3 + t4;
    t4 += static_cast<u32>(sizeof(PARTS_INFO) * hdr.parts_num);
    mPartsInfo = static_cast<PARTS_INFO*>(t5);
    t5 = t3 + t4;
    t4 += static_cast<u32>(sizeof(PRIMITIVE_INFO) * hdr.primitive_num);
    mPrimitiveInfo = static_cast<PRIMITIVE_INFO*>(t5);
    t5 = t3 + t4;
    t4 += static_cast<u32>(sizeof(JOINT_INFO) * hdr.jnt_num);
    mJointInfo = static_cast<JOINT_INFO*>(t5);
    t5 = t3 + t4;
    mMaterialName = static_cast<MATERIAL_NAME*>(t5);
    mJointNum = hdr.jnt_num;
    mPrimitiveNum = hdr.primitive_num;
    mMaterialNum = hdr.material_num;
    mPolygonNum = hdr.polygon_num;
    mVertexNum = hdr.vertex_num;
    mVertexBufsize = hdr.vertexbuf_size;
    mIndexNum = hdr.index_num;
    mPartsNum = hdr.parts_num;
    mBoundingSphere = hdr.bounding_sphere;
    mBoundingBox = hdr.bounding_box;
    mModelInfo = hdr.modelinfo;
    const f32& t7 = mBoundingBox.minpos.y < mBoundingBox.minpos.x ? mBoundingBox.minpos.y : mBoundingBox.minpos.x;
    const f32& t8 = mBoundingBox.minpos.z < t7 ? mBoundingBox.minpos.z : t7;
    f32 minv = t8;
    const f32& t9 = mBoundingBox.maxpos.x < mBoundingBox.maxpos.y ? mBoundingBox.maxpos.y : mBoundingBox.maxpos.x;
    const f32& t10 = t9 < mBoundingBox.maxpos.z ? mBoundingBox.maxpos.z : t9;
    f32 maxv = t10;
    if (hdr.jnt_num != 0) {
        mQuantPosScale = maxv - minv;
        mQuantPosOffset = mBoundingBox.minpos;
        r.skip(static_cast<u32>(hdr.joint_info) - r.getPosition());
        r.read(mJointInfo, hdr.jnt_num * sizeof(JOINT_INFO));
        r.read(mLmat, hdr.jnt_num * sizeof(MtMatrix));
        r.read(mImat, hdr.jnt_num * sizeof(MtMatrix));
        r.read(mJointTable, sizeof(mJointTable));
    } else {
        mQuantPosScale = 1.0f;
        mQuantPosOffset = MtVector4::Zero;
    }
    if (hdr.parts_num != 0) {
        r.skip(static_cast<u32>(hdr.parts_info) - r.getPosition());
        r.read(mPartsInfo, hdr.parts_num * sizeof(PARTS_INFO));
    }
    r.skip(static_cast<u32>(hdr.material_info) - r.getPosition());
    r.read(mMaterialName, hdr.material_num * sizeof(MATERIAL_NAME));
    r.skip(static_cast<u32>(hdr.primitive_info) - r.getPosition());
    r.read(mPrimitiveInfo, mPrimitiveNum * sizeof(PRIMITIVE_INFO));
    u32 id = 1;
    for (u32 i = 0; i < mPrimitiveNum; ++i) {
        PRIMITIVE_INFO* pi = &mPrimitiveInfo[i];
        pi->connect_id = id;
        if (i + 1 < mPrimitiveNum) {
            PRIMITIVE_INFO* pni = &mPrimitiveInfo[i + 1];
            if (pi->inputlayout != pni->inputlayout ||
                pi->vertex_base != pni->vertex_base ||
                pi->material_no != pni->material_no ||
                pi->vertex_stride != pni->vertex_stride ||
                pi->topology != pni->topology) {
                ++id;
            }
        }
    }
    r.read(mBoundaryInfo, boundary_num * sizeof(BOUNDARY_INFO));
    BOUNDARY_INFO* pb = mBoundaryInfo;
    for (u32 i = 0; i < mPrimitiveNum; ++i) {
        PRIMITIVE_INFO* pp = &mPrimitiveInfo[i];
        pp->inputlayout = sShader2::getInstance()->remapObjectHandle(pp->inputlayout);
        pp->boundary = pb;
        pb += pp->boundary_num;
    }
    nDraw::USAGE_TYPE vertex_usage = nDraw::USAGE_DEFAULT;
    if (mVertexBufsize != 0) {
        r.skip(static_cast<u32>(hdr.vertex_data) - r.getPosition());
        mpVertexBuffer = new (16u) nDraw::VertexBuffer(hdr.vertexbuf_size, vertex_usage, nullptr);
        void* pvbuf = mpVertexBuffer->map(nDraw::MAP_WRITE_DISCARD);
        void* tmp = MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memAlloc(mVertexBufsize, 16u);
        r.read(tmp, mVertexBufsize);
        memcpy(pvbuf, tmp, mVertexBufsize);
        mpVertexBuffer->unmap();
        MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memFree(tmp);
    }
    nDraw::USAGE_TYPE index_usage = nDraw::USAGE_DEFAULT;
    r.skip(static_cast<u32>(hdr.index_data) - r.getPosition());
    mpIndexBuffer = new (16u) nDraw::IndexBuffer(hdr.index_num * sizeof(u16), index_usage, nullptr);
    void* pibuf = mpIndexBuffer->map(nDraw::MAP_WRITE_DISCARD);
    {
        void* tmp = MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memAlloc(mIndexNum * sizeof(u16), 16u);
        r.read(tmp, mIndexNum * sizeof(u16));
        memcpy(pibuf, tmp, mIndexNum * sizeof(u16));
        mpIndexBuffer->unmap();
        MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memFree(tmp);
    }
    r.skip(static_cast<u32>(hdr.rcn_data) - r.getPosition());
    mRCNInfo.triangle_num = r.readU32();
    if (mRCNInfo.triangle_num != 0) {
        mRCNInfo.width = r.readU16();
        mRCNInfo.height = r.readU16();
        u32 t6 = hdr.primitive_num * sizeof(u32);
        mRCNInfo.map_vertex_base = static_cast<u32*>(MtMemoryAllocator::getAllocator(rModel::DTI)->memAlloc(t6, 16u));
        for (u32 i = 0; i < hdr.primitive_num; ++i) {
            mRCNInfo.map_vertex_base[i] = r.readU32();
        }
        {
            u32 data_size = r.readU32();
            void* data = MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memAlloc(data_size, 16u);
            r.read(data, data_size);
            mRCNInfo.triangle = new (16u) nDraw::VertexBuffer(data_size, nDraw::USAGE_DEFAULT, data);
            MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memFree(data);
        }
        {
            u32 data_size = r.readU32();
            void* data = MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memAlloc(data_size, 16u);
            r.read(data, data_size);
            mRCNInfo.vertex_to_index = new (16u) nDraw::VertexBuffer(data_size, nDraw::USAGE_DEFAULT, data);
            MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memFree(data);
        }
    }
    return true;
}

bool rModel::save(MtStream& out) {
    return false;
}

MtUI* rModel::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

void rModel::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNum", &mJointNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPrimitiveNum", &mPrimitiveNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPolygonNum", &mPolygonNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVertexNum", &mVertexNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndexNum", &mIndexNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaterialNum", &mMaterialNum, 1u, 0u);
}

__attribute__((weak)) void rModel::clear() {
        if (sRender::mpInstance == nullptr) {
            return;
        }
        if (mpMaterials != nullptr) {
            for (u32 i = 0; i < mMaterialNum; i++) {
                if (mpMaterials[i] != nullptr) {
                    mpMaterials[i]->release();
                    mpMaterials[i] = nullptr;
                }
            }
            if (mMaterialNum > 4) {
                {
                    void* p = mpMaterials;
                    MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(p);
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
        u32 id = getDTI().mID;
        void* pLmat = mLmat;
        u32 modelId = rModel::DTI.mID;
        MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(pLmat);
        if (id != modelId) {
            {
                void* p = mImat;
                MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(p);
            }
            {
                void* p = mJointInfo;
                MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(p);
            }
            {
                void* p = mPrimitiveInfo;
                MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(p);
            }
            {
                void* p = mPartsInfo;
                MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(p);
            }
            {
                void* p = mBoundaryInfo;
                MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(p);
            }
            {
                void* p = mMaterialName;
                MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(p);
            }
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
        {
            void* p = mRCNInfo.map_vertex_base;
            MtMemoryAllocator::getAllocator(rModel::DTI)->memFree(p);
        }
        mRCNInfo.map_vertex_base = nullptr;
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

