// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlHoming.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtRandom.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "sLockOnManager.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamHoming::getDTI() const {
    return cShlParamHoming::DTI;
}

inline void cShlParamHoming::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamHoming::DTI)->memFree(p_addr);
}

MtDTI& cShlParamHoming::getShlDTI() const {
    return uShlHoming::DTI;
}

cShlParamHoming::~cShlParamHoming() {
}

__attribute__((weak)) void cShlParamHoming::createProperty(MtPropertyList& s) {
    this->cShlParamSpeed::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "isSpecifyTargetPos", &isSpecifyTargetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgRad", &hmgRad, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgRadFrame", &hmgRadFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgBgnDist", &hmgBgnDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgEndTargetDist", &hmgEndTargetDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgEndRad", &hmgEndRad, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgEndFrame", &hmgEndFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgEndWaitHmgRad", &hmgEndWaitHmgRad, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgEndWaitSpdMax", &hmgEndWaitSpdMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgEndWaitEndFrame", &hmgEndWaitEndFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgEndHmgRad", &hmgEndHmgRad, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgEndSpdMax", &hmgEndSpdMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmgType", reinterpret_cast<s32*>(&hmgType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmInitSpd", &hmInitSpd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmAccel", &hmAccel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmMaxSpped", &hmMaxSpped, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmHmgRad", &hmHmgRad, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmEndTargetDist", &hmEndTargetDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmEndRad", &hmEndRad, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmRotate", &hmRotate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hmIsRotateRndFlip", &hmIsRotateRndFlip, 0u, 0u);
}

void cShlParamHoming::createPropertySE(MtPropertyList& s) {
    this->cShlParamSpeed::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "seNoHoming", &seNoHoming, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "homingSeDeg", &homingSeDeg, 0u, 0u);
}

__attribute__((weak)) void cShlParamHoming::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamHoming::copy")
    /* stub */
}

inline cShlParamHoming::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamHoming::MyDTI cShlParamHoming::DTI("cShlParamHoming", &::cShlParamSpeed::DTI, 592ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamHoming::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamHoming::DTI)->memAlloc(sizeof(cShlParamHoming), 16u, cShlParamHoming::DTI.getID())) cShlParamHoming;
}

const MtDTI& cShlParamJob08CS12Npc::getDTI() const {
    return cShlParamJob08CS12Npc::DTI;
}

inline void cShlParamJob08CS12Npc::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamJob08CS12Npc::DTI)->memFree(p_addr);
}

MtDTI& cShlParamJob08CS12Npc::getShlDTI() const {
    return uShlJob08CS12Npc::DTI;
}

cShlParamJob08CS12Npc::~cShlParamJob08CS12Npc() {
}

void cShlParamJob08CS12Npc::createProperty(MtPropertyList& s) {
    this->cShlParamHoming::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "objHitShlNo", &objHitShlNo, 0u, 0u);
}

__attribute__((weak)) void cShlParamJob08CS12Npc::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamJob08CS12Npc::copy")
    /* stub */
}

inline cShlParamJob08CS12Npc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob08CS12Npc::MyDTI cShlParamJob08CS12Npc::DTI("cShlParamJob08CS12Npc", &::cShlParamHoming::DTI, 592ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamJob08CS12Npc::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamJob08CS12Npc::DTI)->memAlloc(sizeof(cShlParamJob08CS12Npc), 16u, cShlParamJob08CS12Npc::DTI.getID())) cShlParamJob08CS12Npc;
}

const MtDTI& uShlHoming::getDTI() const {
    return uShlHoming::DTI;
}

uShlHoming::uShlHoming() {
    mHomingPos.z = 0.0f;
    mHomingPos.pad_ = 0.0f;
    mHomingPos.x = 0.0f;
    mHomingPos.y = 0.0f;
    mHomingEndFlag = 0;
    mHomingEndFrame = 0.0f;
    mHomingRadAdd = 0.0f;
    mHomingFrame = 0.0f;
    mHmgPhase = HP_BGN;
    mHomingRad = 0.0f;
    mHMHmgPhase = HP_NOW;
    mHomingMoveVec.z = 1.0f;
    mHomingMoveVec.y = 1.0f;
    mHomingMoveVec.x = 1.0f;
    mHomingRadSE = 0.0f;
    mExHomingRadAdd = 0.0f;
    mHomingMoveVec.pad_ = 0.0f;
    mHMSpeed = 0.0f;
}

uShlHoming::~uShlHoming() {
}

__attribute__((weak)) void uShlHoming::setup() {
    DDON_STUB("uShlHoming::setup")
    /* stub */
}

void uShlHoming::kill() {
    this->uShlSpeed::kill();
}

__attribute__((weak)) void uShlHoming::homingPosMove(f32 spd) {
    DDON_STUB("uShlHoming::homingPosMove")
    /* stub */
}

void uShlHoming::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    this->uShlSpeed::applyWorldOffset(offset, absolute_offset);
    mHomingPos.x = offset.x + mHomingPos.x;
    mHomingPos.y = offset.y + mHomingPos.y;
    mHomingPos.z = offset.z + mHomingPos.z;
}

__attribute__((weak)) void uShlHoming::movePosSub(f32 speed) {
    DDON_STUB("uShlHoming::movePosSub")
    /* stub */
}

__attribute__((weak)) void uShlHoming::moveSpeedSub() {
}

inline uShlHoming::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlHoming::MyDTI uShlHoming::DTI("uShlHoming", &::uShlSpeed::DTI, 11232ul, 0u, 0u);

MtObject* uShlHoming::MyDTI::newInstance() const {
    return new (16u) uShlHoming;
}

const MtDTI& uShlJob08CS12Npc::getDTI() const {
    return uShlJob08CS12Npc::DTI;
}

uShlJob08CS12Npc::~uShlJob08CS12Npc() {
    DDON_STUB("uShlJob08CS12Npc::~uShlJob08CS12Npc")
    /* stub */
}

void uShlJob08CS12Npc::updateSub() {
    this->uShlSpeed::updateSub();
    if (mpOwner == nullptr) {
        return;
    }
    if ((mpOwner->mUnitId & 16u) == 0) {
        return;
    }
    if (mpOwner->getActMgrPtr()->getActionNo() != 4107) {
        requestKill();
    }
}

__attribute__((weak)) void uShlJob08CS12Npc::callbackAttack(cHitInfo* pHitInfo) {
    DDON_STUB("uShlJob08CS12Npc::callbackAttack")
    /* stub */
}

inline uShlJob08CS12Npc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob08CS12Npc::MyDTI uShlJob08CS12Npc::DTI("uShlJob08CS12Npc", &::uShlHoming::DTI, 11232ul, 0u, 0u);

MtObject* uShlJob08CS12Npc::MyDTI::newInstance() const {
    return new (16u) uShlJob08CS12Npc;
}

