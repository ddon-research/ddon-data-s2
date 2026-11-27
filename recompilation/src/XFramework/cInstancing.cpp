// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cInstancing.h"
#include "../MT/MtCRC.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cResource.h"
#include "nDrawConstantTable.h"
#include "nDrawResource.h"
#include "rModel.h"
#include "rTexture.h"
#include "sCamera.h"
#include "sGrass.h"
#include "sMain.h"
#include "sRender.h"
#include "sScene.h"
#include "uBaseModel.h"
#include "uCoord.h"
#include "../DD_ONLINE/prog/uOmSwingModel.h"
#include "uSwingModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void cInstancing::setup() {
}

__attribute__((weak)) void cInstancing::move() {
}

const MtDTI& cInstancingCulling::getDTI() const {
    return cInstancingCulling::DTI;
}

cInstancingCulling::~cInstancingCulling() {
    if (mpBillboardTexture == nullptr) {
        return;
    }
    mpBillboardTexture->release();
    mpBillboardTexture = nullptr;
}

__attribute__((weak)) void cInstancingCulling::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mUseBillboard", &mUseBillboard, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUVSwitchEnable", &mUVSwitchEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBillboardSize", &mBillboardSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLodBillboardDistance", &mLodBillboardDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBillboardPattern", &mBillboardPattern, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpBillboardTexture", "resource", static_cast<void*>(&mpBillboardTexture), 0u, 0u);
}

MtUI* cInstancingCulling::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cInstancingCulling::updateLODParam(rModel::MODEL_INFO* pmi) {
    mLODDistance[0] = 0.0f;
    mLODDistance[1] = static_cast<float>(pmi->middist);
    mLODDistance[2] = static_cast<float>(pmi->lowdist);
    mLODDistance[3] = mLodBillboardDistance + static_cast<float>(pmi->lowdist);
}

__attribute__((weak)) bool cInstancingCulling::begin(cDraw* pdraw, uBaseModel::LOD_TYPE lod, bool use_record) {
    DDON_STUB("cInstancingCulling::begin")
    return {};
}

__attribute__((weak)) void cInstancingCulling::end(cDraw* pdraw) {
    DDON_STUB("cInstancingCulling::end")
    /* stub */
}

void cInstancingCulling::beginRecord(cDraw* pdraw) {
    mRecord[pdraw->mJobThreadIndex].vb_buf = nullptr;
}

__attribute__((weak)) void cInstancingCulling::endRecord(cDraw* pdraw) {
    DDON_STUB("cInstancingCulling::endRecord")
    /* stub */
}

__attribute__((weak)) void cInstancingCulling::drawInstance(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, const nDraw::Material* p_material) {
    DDON_STUB("cInstancingCulling::drawInstance")
    /* stub */
}

__attribute__((weak)) void cInstancingCulling::drawBillboard(cDraw* pdraw) {
    DDON_STUB("cInstancingCulling::drawBillboard")
    /* stub */
}

const MtMatrix& cInstancingCulling::getWorldMatrix() const {
    return mReferenceWorldMatrix;
}

s32 cInstancingCulling::compare(const void* p_src1, const void* p_src2) {
    if ((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(p_src2) + 0)) >= (*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(p_src1) + 0))) {
        return -1;
    } else {
        return 1;
    }
}

__attribute__((weak)) bool cInstancingCulling::culling(cDraw* pdraw, cInstancingCulling::VisibleList* p_list, uBaseModel::LOD_TYPE lod) {
    DDON_STUB("cInstancingCulling::culling")
    return {};
}

inline cInstancingCulling::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cInstancingCulling::MyDTI cInstancingCulling::DTI("cInstancingCulling", &::MtObject::DTI, 912ul, 0u, 1u);

s32 cInstancingCulling::mListCount;

MtAllocator* cInstancingCulling::mpAllocator;

MtObject* cInstancingCulling::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& cInstancingDynamic::getDTI() const {
    return cInstancingDynamic::DTI;
}

cInstancingDynamic::~cInstancingDynamic() {
    DDON_STUB("cInstancingDynamic::~cInstancingDynamic")
    /* stub */
}

__attribute__((weak)) void cInstancingDynamic::release() {
    DDON_STUB("cInstancingDynamic::release")
    /* stub */
}

void cInstancingDynamic::createProperty(MtPropertyList& s) {
    this->cInstancingCulling::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mUseLodFade", &mUseLodFade, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseFastCulling", &mUseFastCulling, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPartsLevel", &mPartsLevel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mClusterSize", &mClusterSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDebug", &mDebug, 0u, 0u);
}

__attribute__((weak)) bool cInstancingDynamic::setupInstancing(const MtOBB& obb, const MtMatrix& world_matrix, const MtMatrix& quant_matrix) {
    DDON_STUB("cInstancingDynamic::setupInstancing")
    return {};
}

__attribute__((weak)) void cInstancingDynamic::updateAABB() {
    DDON_STUB("cInstancingDynamic::updateAABB")
    /* stub */
}

__attribute__((weak)) void cInstancingDynamic::entryInstance(u32 index, bool fadein) {
    DDON_STUB("cInstancingDynamic::entryInstance")
    /* stub */
}

__attribute__((weak)) void cInstancingDynamic::exitInstance(u32 index) {
    DDON_STUB("cInstancingDynamic::exitInstance")
    /* stub */
}

__attribute__((weak)) void cInstancingDynamic::exitInstaceFilter(u32 filter, u32 mask) {
    DDON_STUB("cInstancingDynamic::exitInstaceFilter")
    /* stub */
}

__attribute__((weak)) void cInstancingDynamic::setVisible(u32 index, bool enable) {
    DDON_STUB("cInstancingDynamic::setVisible")
    /* stub */
}

__attribute__((weak)) void cInstancingDynamic::culling(cDraw* pdraw, u32& list_num, cInstancingCulling::VisibleList* p_list, uBaseModel::LOD_TYPE lod, cInstancingCulling::InstanceInfo* p_instance) {
    DDON_STUB("cInstancingDynamic::culling")
    /* stub */
}

__attribute__((weak)) u32 cInstancingDynamic::getInstancingSize(cDraw* pdraw) {
    const bool fade_enable = mUseLodFade && ((reinterpret_cast<const cDraw::CONTEXT*>(reinterpret_cast<const char*>(pdraw) + 0x108)->drawmode & 1u) != 0);
    return getInstanceNum() * (fade_enable ? 12u : 4u);
}

MtVector4 cInstancingDynamic::getInstanceColor(u32 index, f32 fade) {
    MtVector4 result;
    result.x = 0.0f;
    result.y = 0.0f;
    result.z = 0.0f;
    result.w = fade;
    return result;
}

inline cInstancingDynamic::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cInstancingDynamic::MyDTI cInstancingDynamic::DTI("cInstancingDynamic", &::cInstancingCulling::DTI, 944ul, 0u, 1u);

MtObject* cInstancingDynamic::MyDTI::newInstance() const {
    return nullptr;
}

cInstancingDynamic::Cluster::~Cluster() {
    DDON_STUB("cInstancingDynamic::Cluster::~Cluster")
    /* stub */
}

__attribute__((weak)) void cInstancingDynamic::Cluster::add(u32 index, const MtAABB& aabb, bool fadein) {
    DDON_STUB("cInstancingDynamic::Cluster::add")
    /* stub */
}

__attribute__((weak)) bool cInstancingDynamic::Cluster::del(u32 index) {
    DDON_STUB("cInstancingDynamic::Cluster::del")
    return {};
}

__attribute__((weak)) bool cInstancingDynamic::Cluster::delFilter(u32 filter, u32 mask) {
    DDON_STUB("cInstancingDynamic::Cluster::delFilter")
    return {};
}

const MtDTI& cInstancingFromMatrices::getDTI() const {
    return cInstancingFromMatrices::DTI;
}

cInstancingFromMatrices::cInstancingFromMatrices() {
    DDON_STUB("cInstancingFromMatrices::cInstancingFromMatrices")
    /* stub */
}

__attribute__((weak)) void cInstancingFromMatrices::release() {
    DDON_STUB("cInstancingFromMatrices::release")
    /* stub */
}

__attribute__((weak)) void cInstancingFromMatrices::move() {
    DDON_STUB("cInstancingFromMatrices::move")
    /* stub */
}

s32 cInstancingFromMatrices::getId() {
    s32 i = 0;
    Area* p2 = &mArea[0];
    do {
        if ((p2->mEmpty & 1u) != 0) {
            return i;
        }
        i += 1;
        p2 += static_cast<int>(1);
    } while ((i + 0) <= 255);
    return -1;
}

__attribute__((weak)) void cInstancingFromMatrices::addInstance(u32 user_id, const MtMatrix* instance_matrices, const u32& instance_num, bool fadein) {
    DDON_STUB("cInstancingFromMatrices::addInstance")
    /* stub */
}

__attribute__((weak)) void cInstancingFromMatrices::delInstance(u32 user_id) {
    DDON_STUB("cInstancingFromMatrices::delInstance")
    /* stub */
}

u32 cInstancingFromMatrices::getInstanceNum() {
    return mInstanceNum;
}

MtMatrix cInstancingFromMatrices::getInstanceMatrix(u32 index) {
    MtMatrix mat;
    mat.m[0].x = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[0][0];
    mat.m[0].y = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[1][0];
    mat.m[0].z = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[2][0];
    mat.m[0].w = 0.0f;
    mat.m[1].x = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[0][1];
    mat.m[1].y = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[1][1];
    mat.m[1].z = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[2][1];
    mat.m[1].w = 0.0f;
    mat.m[2].x = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[0][2];
    mat.m[2].y = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[1][2];
    mat.m[2].z = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[2][2];
    mat.m[2].w = 0.0f;
    mat.m[3].x = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[0][3];
    mat.m[3].y = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[1][3];
    mat.m[3].z = mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)].m[2][3];
    mat.m[3].w = 1.0f;
    return mat;
}

MtFloat3x4& cInstancingFromMatrices::getInstanceMatrix3x4(u32 index) {
    return mArea[(index >> 8) & 255u].mpInstanceMatrices[static_cast<unsigned char>(index)];
}

__attribute__((weak)) void cInstancingFromMatrices::delInstanceProcess(u32 user_id) {
    DDON_STUB("cInstancingFromMatrices::delInstanceProcess")
    /* stub */
}

inline cInstancingFromMatrices::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cInstancingFromMatrices::MyDTI cInstancingFromMatrices::DTI("cInstancingFromMatrices", &::cInstancingDynamic::DTI, 5312ul, 0u, 0u);

__attribute__((weak)) MtObject* cInstancingFromMatrices::MyDTI::newInstance() const {
    DDON_STUB("cInstancingFromMatrices::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void cInstancingFromMatrices::Area::create(const MtMatrix* instance_matrices, const u32& instance_num, u32& current_instance_num) {
    DDON_STUB("cInstancingFromMatrices::Area::create")
    /* stub */
}

