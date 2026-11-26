// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlSpeed.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "../../XFramework/cUnit.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "nShlBase.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sCollision.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sShlManager.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "sWorkRate.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamSpeed::getDTI() const {
    return cShlParamSpeed::DTI;
}

inline void* cShlParamSpeed::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamSpeed::DTI)->memAlloc(sz, align, cShlParamSpeed::DTI.getID());
}

inline void cShlParamSpeed::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamSpeed::DTI)->memFree(p_addr);
}

MtDTI& cShlParamSpeed::getShlDTI() const {
    return uShlSpeed::DTI;
}

cShlParamSpeed::~cShlParamSpeed() {
}

void cShlParamSpeed::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "spd", &spd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "spdMax", &spdMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "spdAccel", &spdAccel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "spdAccelDist", &spdAccelDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "gravity", &gravity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "gravityMax", &gravityMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "gravityAccel", &gravityAccel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "gravityDist", &gravityDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dieDist", &dieDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dieFlag", &dieFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isTurnMoveVec", &isTurnMoveVec, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitSlowRate", &hitSlowRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitSlowFrame", &hitSlowFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitAdjustPosRate", &hitAdjustPosRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitAdjustCount", &hitAdjustCount, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isFuwaMove", &isFuwaMove, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "fuwaPeriod", &fuwaPeriod, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "fuwaScale", &fuwaScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "fuwaRandom", &fuwaRandom, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isAutoLockon", &isAutoLockon, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "lockonDist", &lockonDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "lockonDeg", &lockonDeg, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "lockonOption", &lockonOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitShlNo", &hitShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "floorHitShlNo", &floorHitShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlOptionSpeed", &shlOptionSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dirAdjustDist", &dirAdjustDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isEnchantShotSE", &isEnchantShotSE, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "useGravityMin", &useGravityMin, 0u, 0u);
}

void cShlParamSpeed::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoScrHit", &epvNoScrHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scrHitEfType", reinterpret_cast<s32*>(&scrHitEfType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoHitSlow", &epvNoHitSlow, 0u, 0u);
}

void cShlParamSpeed::createPropertySE(MtPropertyList& s) {
    this->cShlParamBase::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "seHitScrResType", reinterpret_cast<s32*>(&seHitScrResType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoScrHit", &seNoScrHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoHitSlow", &seNoHitSlow, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoHitSlowStop", &seNoHitSlowStop, 0u, 0u);
}

__attribute__((weak)) void cShlParamSpeed::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamSpeed::copy")
    /* stub */
}

inline cShlParamSpeed::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamSpeed::MyDTI cShlParamSpeed::DTI("cShlParamSpeed", &::cShlParamBase::DTI, 496ul, 0u, 0u);

MtObject* cShlParamSpeed::MyDTI::newInstance() const {
    return new (16u) cShlParamSpeed;
}

const MtDTI& uShlSpeed::getDTI() const {
    return uShlSpeed::DTI;
}

inline void uShlSpeed::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlSpeed::DTI)->memFree(p_addr);
}

uShlSpeed::uShlSpeed() {
    DDON_STUB("uShlSpeed::uShlSpeed")
    /* stub */
}

uShlSpeed::~uShlSpeed() {
    DDON_STUB("uShlSpeed::~uShlSpeed")
    /* stub */
}

__attribute__((weak)) void uShlSpeed::setup() {
    DDON_STUB("uShlSpeed::setup")
    /* stub */
}

__attribute__((weak)) void uShlSpeed::initSub() {
    DDON_STUB("uShlSpeed::initSub")
    /* stub */
}

__attribute__((weak)) void uShlSpeed::updateSub() {
    DDON_STUB("uShlSpeed::updateSub")
    /* stub */
}

void uShlSpeed::kill() {
    this->uShlBase::kill();
}

void uShlSpeed::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
}

__attribute__((weak)) void uShlSpeed::callbackAttack(cHitInfo* pHitInfo) {
    DDON_STUB("uShlSpeed::callbackAttack")
    /* stub */
}

__attribute__((weak)) bool uShlSpeed::isDie() {
    DDON_STUB("uShlSpeed::isDie")
    return {};
}

__attribute__((weak)) void uShlSpeed::movePos() {
    DDON_STUB("uShlSpeed::movePos")
    /* stub */
}

__attribute__((weak)) u32 uShlSpeed::getCollisionIndex() const {
    DDON_STUB("uShlSpeed::getCollisionIndex")
    return {};
}

__attribute__((weak)) void uShlSpeed::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlSpeed::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uShlSpeed::checkScr() {
    DDON_STUB("uShlSpeed::checkScr")
    /* stub */
}

f32 uShlSpeed::getShlSpeedDeltaTime() {
    return mSpeedDeltaTime;
}

__attribute__((weak)) uShlBase* uShlSpeed::createNextShlWithNormal(u32 index, u32 shotSts, bool isNow, const MtVector3& normal) {
    DDON_STUB("uShlSpeed::createNextShlWithNormal")
    return nullptr;
}

__attribute__((weak)) void uShlSpeed::setScrHitEfct(const MtVector3& pos, f32 scale) {
    DDON_STUB("uShlSpeed::setScrHitEfct")
    /* stub */
}

bool uShlSpeed::callbackRegistInterPolateGeom(MtVector3& oldPos, const MtVector3& currentPos, f32 radius, const cHitGeom* pGeom) {
    if (mCreateSeqNo == getShlParamBase()->seq_0) {
        return false;
    } else {
        oldPos.x = mInterPos.x;
        oldPos.y = mInterPos.y;
        oldPos.z = mInterPos.z;
        oldPos.pad_ = 0.0f;
        return true;
    }
}

inline uShlSpeed::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlSpeed::MyDTI uShlSpeed::DTI("uShlSpeed", &::uShlBase::DTI, 11152ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlSpeed::MyDTI::newInstance() const {
    DDON_STUB("uShlSpeed::MyDTI::newInstance")
    return nullptr;
}

