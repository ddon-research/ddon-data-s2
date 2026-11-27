// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpCheckWallCliff.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "cActList.h"
#include "cDelegate.h"
#include "cState.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpComponent.h"
#include "cpFsmCtrl.h"
#include "cpPawnThink.h"
#include "cpStateManager.h"
#include "nDDOUtility.h"
#include "../../XFramework/rCollisionHeightField.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "sGame.h"
#include "sPlayerManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#include "uNpc.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpCheckWallCliff::getDTI() const {
    return cpCheckWallCliff::DTI;
}

void* cpCheckWallCliff::operator new(size_t sz, u32 align) {
    return cpCheckWallCliff::getAllocator()->memAlloc(sz, align, cpCheckWallCliff::DTI.getID());
}

cpCheckWallCliff::cpCheckWallCliff() {
    DDON_STUB("cpCheckWallCliff::cpCheckWallCliff")
    /* stub */
}

__attribute__((noinline)) cpCheckWallCliff::~cpCheckWallCliff() {
    DDON_STUB("cpCheckWallCliff::~cpCheckWallCliff")
    /* stub */
}

__attribute__((weak)) void cpCheckWallCliff::setup() {
    DDON_STUB("cpCheckWallCliff::setup")
    /* stub */
}

void cpCheckWallCliff::update() {
    mIsWallStop = false;
    moveCheckWall();
}

__attribute__((weak)) void cpCheckWallCliff::compMoveAfter() {
    moveCheckCliff2();
    
    const MtVector4 t1 = mpModel->mWmat.m[3];
    if ((mpModel->mIsPlayer || mpModel->mIsPawn) && (mpModel->mObjStatus & 1) == 0) {
        return;
    }
    
    mFallPreventionPosList.elems[3] = mFallPreventionPosList.elems[2];
    mFallPreventionPosList.elems[2] = mFallPreventionPosList.elems[1];
    mFallPreventionPosList.elems[1] = mFallPreventionPosList.elems[0];
    mFallPreventionPosList.elems[0] = MtVector3(t1.x, t1.y, t1.z);
}

void cpCheckWallCliff::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mFallPreventionPosList.elems[0].x = offset.x + mFallPreventionPosList.elems[0].x;
    mFallPreventionPosList.elems[0].y = offset.y + mFallPreventionPosList.elems[0].y;
    mFallPreventionPosList.elems[0].z = offset.z + mFallPreventionPosList.elems[0].z;
    mFallPreventionPosList.elems[1].x = offset.x + mFallPreventionPosList.elems[1].x;
    mFallPreventionPosList.elems[1].y = offset.y + mFallPreventionPosList.elems[1].y;
    mFallPreventionPosList.elems[1].z = offset.z + mFallPreventionPosList.elems[1].z;
    mFallPreventionPosList.elems[2].x = offset.x + mFallPreventionPosList.elems[2].x;
    mFallPreventionPosList.elems[2].y = offset.y + mFallPreventionPosList.elems[2].y;
    mFallPreventionPosList.elems[2].z = offset.z + mFallPreventionPosList.elems[2].z;
    mFallPreventionPosList.elems[3].x = offset.x + mFallPreventionPosList.elems[3].x;
    mFallPreventionPosList.elems[3].y = offset.y + mFallPreventionPosList.elems[3].y;
    mFallPreventionPosList.elems[3].z = offset.z + mFallPreventionPosList.elems[3].z;
    mFallPreventionCorrectPos.x = offset.x + mFallPreventionCorrectPos.x;
    mFallPreventionCorrectPos.y = offset.y + mFallPreventionCorrectPos.y;
    mFallPreventionCorrectPos.z = offset.z + mFallPreventionCorrectPos.z;
}

__attribute__((weak)) void cpCheckWallCliff::moveCheckWall() {
    DDON_STUB("cpCheckWallCliff::moveCheckWall")
    /* stub */
}

__attribute__((weak)) void cpCheckWallCliff::moveCheckCliff2() {
    DDON_STUB("cpCheckWallCliff::moveCheckCliff2")
    /* stub */
}

__attribute__((weak)) cpCheckWallCliff::PREVENTION_TYPE cpCheckWallCliff::getPreventionType() {
    DDON_STUB("cpCheckWallCliff::getPreventionType")
    return {};
}

__attribute__((weak)) bool cpCheckWallCliff::checkFallPreventionGround(cpCheckWallCliff::PREVENTION_TYPE type) {
    DDON_STUB("cpCheckWallCliff::checkFallPreventionGround")
    return {};
}

__attribute__((weak)) bool cpCheckWallCliff::checkFallPrevention() {
    DDON_STUB("cpCheckWallCliff::checkFallPrevention")
    return {};
}

void cpCheckWallCliff::setWallCheckDate(s32 jnt, f32 range, u32 filter) {
    mWallCheckCnsJnt = jnt;
    mWallCheckRange = range;
    mWallCheckFilter = filter;
}

void cpCheckWallCliff::setCliffCheckDate(s32 jnt, f32 forword, f32 height, u32 filter) {
    mCliffCheckCnsJnt = jnt;
    mCliffCheckRangeForward = forword;
    mCliffCheckRangeHeight = height;
    mCliffCheckFilter = filter;
}

inline cpCheckWallCliff::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpCheckWallCliff::MyDTI cpCheckWallCliff::DTI("cpCheckWallCliff", &::cpComponent::DTI, 432ul, 0u, 0u);

__attribute__((weak)) MtObject* cpCheckWallCliff::MyDTI::newInstance() const {
    DDON_STUB("cpCheckWallCliff::MyDTI::newInstance")
    return nullptr;
}

