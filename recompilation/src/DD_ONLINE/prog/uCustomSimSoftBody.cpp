// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCustomSimSoftBody.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "cBakeModel.h"
#include "../../XFramework/rModel.h"
#include "sBakingJointOrder.h"
#include "../../XFramework/uModel.h"
#include "../../XFramework/uSimSoftBody.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCustomSimSoftBody::getDTI() const {
    return uCustomSimSoftBody::DTI;
}

inline MtAllocator* uCustomSimSoftBody::getAllocator() {
    return MtMemoryAllocator::getAllocator(uCustomSimSoftBody::DTI);
}

void* uCustomSimSoftBody::operator new(size_t sz, u32 align) {
    return uCustomSimSoftBody::getAllocator()->memAlloc(sz, align, uCustomSimSoftBody::DTI.getID());
}

inline void uCustomSimSoftBody::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uCustomSimSoftBody::DTI)->memFree(p_addr);
}

uCustomSimSoftBody::uCustomSimSoftBody() {
    mBakeRebuildComplete = false;
    mIsPause = false;
    mIsDeleteComplete = false;
    mpBakeModel = nullptr;
    enableResetRestart();
}

uCustomSimSoftBody::~uCustomSimSoftBody() {
}

void uCustomSimSoftBody::draw(cDraw* pdraw) {
    if (mBakeRebuildComplete) {
        startSimulation(10u);
    } else {
        stopSimulation();
    }
    if (!mBakeRebuildComplete) {
        return;
    }
    this->uSimSoftBody::draw(pdraw);
}

bool uCustomSimSoftBody::hasTarget() const {
    if (mpBakeModel != nullptr) {
        if (mpBakeModel->mpModel != nullptr) {
            if (mpTargetUnit != nullptr) {
                return mpTargetUnit->mpModel != nullptr;
            }
        }
    }
    return false;
}

bool uCustomSimSoftBody::isTargetEnable() const {
    return mpBakeModel->isEnable();
}

nDraw::VertexBuffer* uCustomSimSoftBody::getTargetVertexBuffer() const {
    return mpBakeModel->getVertexBuffer();
}

nDraw::IndexBuffer* uCustomSimSoftBody::getTargetIndexBuffer() const {
    return mpBakeModel->getIndexBuffer();
}

const rModel::PRIMITIVE_INFO* uCustomSimSoftBody::getTargetPrimitives() const {
    return mpBakeModel->getPrimitives();
}

u32 uCustomSimSoftBody::getTargetPrimitiveNum() const {
    return mpBakeModel->getPrimitiveNum();
}

u32 uCustomSimSoftBody::getTargetJointNum() const {
    return mpBakeModel->getJointNum();
}

bool uCustomSimSoftBody::isTargetPartsDisp(u32 no) const {
    return mpBakeModel->isPartsDisp(no);
}

const MtVector3& uCustomSimSoftBody::getTargetPos() const {
    return mpBakeModel->getPos();
}

void uCustomSimSoftBody::setTargetCommonState(cDraw* pdraw) {
    sBakingJointOrder::getInstance()->setCommonStateModelOrder(pdraw, mpBakeModel->mpCallerUnit, mpBakeModel->mpCallBack);
}

const MtMatrix& uCustomSimSoftBody::getTargetJointMatrix(s32 jointIndex) const {
    if (jointIndex != -1) {
        return mpBakeModel->getJointFromIndex(jointIndex)->mWmat;
    } else {
        return mpBakeModel->getWorldNullMatrix();
    }
}

const MtSphere& uCustomSimSoftBody::getTargetBoundingSphere() const {
    return mpTargetUnit->mBoundingSphere;
}

void uCustomSimSoftBody::getTargetBoundingAABB(MtAABB& aabb) const {
    const MtSphere& t0 = getTargetBoundingSphere();
    const f32 t1 = t0.r;
    const f32 t2 = t0.pos.y;
    const f32 t3 = t0.pos.z;
    aabb.minpos.x = t0.pos.x - t1;
    aabb.minpos.y = t2 - t1;
    aabb.minpos.z = t3 - t1;
    aabb.minpos.pad_ = 0.0f;
    const f32 t4 = t0.pos.y;
    const f32 t5 = t0.pos.z;
    aabb.maxpos.x = t1 + t0.pos.x;
    aabb.maxpos.y = t1 + t4;
    aabb.maxpos.z = t1 + t5;
    aabb.maxpos.pad_ = 0.0f;
}

__attribute__((weak)) void uCustomSimSoftBody::getTargetTightBoundingAABB(MtAABB& aabb) const {
    DDON_STUB("uCustomSimSoftBody::getTargetTightBoundingAABB")
    /* stub */
}

__attribute__((weak)) void uCustomSimSoftBody::createSkinningMatrix(MtVector4* pdst, u32 jnt_num) {
    DDON_STUB("uCustomSimSoftBody::createSkinningMatrix")
    /* stub */
}

bool uCustomSimSoftBody::isDivideDelete() const {
    return true;
}

bool uCustomSimSoftBody::isDeleteComplete() const {
    return mIsDeleteComplete;
}

inline uCustomSimSoftBody::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCustomSimSoftBody::MyDTI uCustomSimSoftBody::DTI("uCustomSimSoftBody", &::uSimSoftBody::DTI, 3712ul, 0u, 0u);

MtObject* uCustomSimSoftBody::MyDTI::newInstance() const {
    return new (16u) uCustomSimSoftBody;
}

