// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sWorldOffset.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "../../XFramework/cSystem.h"
#include "nNetMsgData.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sMain.h"
#include "sPlayerManager.h"
#include "sSoundManager.h"
#include "../../XFramework/uCoord.h"
#include "uPlayer.h"
#include "uStageField.h"
#include "uStageJoint.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sWorldOffset::getDTI() const {
    return sWorldOffset::DTI;
}

void* sWorldOffset::operator new(size_t sz, u32 align) {
    return sWorldOffset::getAllocator()->memAlloc(sz, align, sWorldOffset::DTI.getID());
}

sWorldOffset::sWorldOffset() {
    DDON_STUB("sWorldOffset::sWorldOffset")
    /* stub */
}

sWorldOffset::~sWorldOffset() {
    sWorldOffset::mpInstance = nullptr;
}

__attribute__((weak)) void sWorldOffset::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void sWorldOffset::move() {
    DDON_STUB("sWorldOffset::move")
    /* stub */
}

void sWorldOffset::Init(const MtVector3& targetPos) {
    mIdX = -1;
    mIdZ = -1;
    mWorldOffset = MtVector3::Zero;
    mWorldAbsoluteOffset = MtVector3::Zero;
}

void sWorldOffset::clear() {
    mRno = 0;
    mIdZ = -1;
    mIdX = -1;
    mEnabelWorldOffset = false;
    mStatus = 1;
    mWorldOffset = MtVector3::Zero;
    mWorldAbsoluteOffset = MtVector3::Zero;
    mUpdate = false;
}

__attribute__((weak)) void sWorldOffset::InitEdit(const MtVector3& targetPos) {
    DDON_STUB("sWorldOffset::InitEdit")
    /* stub */
}

void sWorldOffset::clearEdit() {
    const f32 t0 = MtVector3::Zero.x;
    const f32 t1 = MtVector3::Zero.y;
    const f32 t2 = MtVector3::Zero.z;
    mWorldOffset.x = t0 - mWorldAbsoluteOffset.x;
    mWorldOffset.y = t1 - mWorldAbsoluteOffset.y;
    mWorldOffset.z = t2 - mWorldAbsoluteOffset.z;
    mWorldOffset.pad_ = 0.0f;
    mWorldAbsoluteOffset.x = mWorldAbsoluteOffset.x + (t0 - mWorldAbsoluteOffset.x);
    mWorldAbsoluteOffset.y = mWorldAbsoluteOffset.y + (t1 - mWorldAbsoluteOffset.y);
    mWorldAbsoluteOffset.z = mWorldAbsoluteOffset.z + (t2 - mWorldAbsoluteOffset.z);
    mEnabelWorldOffset = false;
    mStatus = 1;
}

__attribute__((weak)) MtVector3 sWorldOffset::getRealPos(const MtVector3& worldPos) const {
    DDON_STUB("sWorldOffset::getRealPos")
    __builtin_unreachable();
}

nNetMsgData::stNetPos sWorldOffset::getRealNetPos(const MtVector3& worldPos) const {
    nNetMsgData::stNetPos realPos;
    const f32 t0 = worldPos.x;
    realPos.x = static_cast<double>(t0);
    const f32 t1 = worldPos.y;
    realPos.y = t1;
    const f32 t2 = worldPos.z;
    realPos.z = static_cast<double>(t2);
    if (isWorldOffset()) {
        realPos.x = static_cast<double>(t0) - static_cast<double>(mWorldAbsoluteOffset.x);
        realPos.y = t1 - mWorldAbsoluteOffset.y;
        realPos.z = static_cast<double>(t2) - static_cast<double>(mWorldAbsoluteOffset.z);
    }
    return realPos;
}

__attribute__((weak)) MtVector3 sWorldOffset::getRealOffset(s32 splitN, s32 splitM) {
    DDON_STUB("sWorldOffset::getRealOffset")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 sWorldOffset::getOffsetPos(const MtVector3& RealPos) const {
    DDON_STUB("sWorldOffset::getOffsetPos")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 sWorldOffset::getOffsetNetPos(const nNetMsgData::stNetPos& RealPos) const {
    DDON_STUB("sWorldOffset::getOffsetNetPos")
    __builtin_unreachable();
}

__attribute__((weak)) bool sWorldOffset::calcOffset(const MtVector3& targetPos) {
    DDON_STUB("sWorldOffset::calcOffset")
    return {};
}

__attribute__((weak)) bool sWorldOffset::calcOffsetEx(const MtVector3& targetPos) {
    DDON_STUB("sWorldOffset::calcOffsetEx")
    return {};
}

inline sWorldOffset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sWorldOffset::MyDTI sWorldOffset::DTI("sWorldOffset", &::cSystem::DTI, 96ul, 0u, 0u);

sWorldOffset* sWorldOffset::mpInstance;

__attribute__((weak)) MtObject* sWorldOffset::MyDTI::newInstance() const {
    sWorldOffset* t1 = new (16u) sWorldOffset;
    sWorldOffset::mpInstance = t1;
    t1->mRno = 0;
    t1->mIdZ = -1;
    t1->mIdX = -1;
    t1->mEnabelWorldOffset = false;
    t1->mStatus = ST_INIT;
    t1->mWorldOffset = MtVector3::Zero;
    t1->mWorldAbsoluteOffset = MtVector3::Zero;
    t1->mUpdate = false;
    return t1;
}

