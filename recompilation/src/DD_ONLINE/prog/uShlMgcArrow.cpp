// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlMgcArrow.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextPlayerInfo.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "../../XFramework/cResource.h"
#include "cpObjCollision.h"
#include "nHumanBow.h"
#include "nHumanMsg.h"
#include "rObjCollision.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#include "uShlFollowMove.h"
#include "uShlHoming.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamJob08CS13::getDTI() const {
    return cShlParamJob08CS13::DTI;
}

inline void cShlParamJob08CS13::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamJob08CS13::DTI)->memFree(p_addr);
}

MtDTI& cShlParamJob08CS13::getShlDTI() const {
    return uShlJob08CS13::DTI;
}

cShlParamJob08CS13::~cShlParamJob08CS13() {
}

void cShlParamJob08CS13::createProperty(MtPropertyList& s) {
    this->cShlParamMgcArrow::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "checkColForLockOnTarget", &checkColForLockOnTarget, 0u, 0u);
}

void cShlParamJob08CS13::copy(const cShlParamBase* pParamBase) {
    this->cShlParamMgcArrow::copy(pParamBase);
    const cShlParamJob08CS13* pParam = static_cast<const cShlParamJob08CS13*>(pParamBase);
    checkColForLockOnTarget = pParam->checkColForLockOnTarget;
}

inline cShlParamJob08CS13::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob08CS13::MyDTI cShlParamJob08CS13::DTI("cShlParamJob08CS13", &::cShlParamMgcArrow::DTI, 736ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamJob08CS13::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamJob08CS13::DTI)->memAlloc(sizeof(cShlParamJob08CS13), 16u, cShlParamJob08CS13::DTI.getID())) cShlParamJob08CS13;
}

const MtDTI& cShlParamMgcArrow::getDTI() const {
    return cShlParamMgcArrow::DTI;
}

inline void cShlParamMgcArrow::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamMgcArrow::DTI)->memFree(p_addr);
}

MtDTI& cShlParamMgcArrow::getShlDTI() const {
    return uShlMgcArrow::DTI;
}

cShlParamMgcArrow::~cShlParamMgcArrow() {
}

__attribute__((weak)) void cShlParamMgcArrow::createProperty(MtPropertyList& s) {
    this->cShlParamHoming::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "isHitCheckNextShl", &isHitCheckNextShl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isHitScrSameShl", &isHitScrSameShl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitcheckShl_charge0", &hitcheckShl_charge0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitcheckShl_charge1", &hitcheckShl_charge1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitcheckShl_charge2", &hitcheckShl_charge2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitcheckShl_just", &hitcheckShl_just, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mgcArrowhitAttr", &mgcArrowhitAttr, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isHitScrNextShl", &isHitScrNextShl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitScrShl_charge0", &hitScrShl_charge0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitScrShl_charge1", &hitScrShl_charge1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitScrShl_charge2", &hitScrShl_charge2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitScrShl_just", &hitScrShl_just, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isUndeadShl", &isUndeadShl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "undeadShl_charge0", &undeadShl_charge0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "undeadShl_charge1", &undeadShl_charge1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "undeadShl_charge2", &undeadShl_charge2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "undeadShl_just", &undeadShl_just, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isCoreShl", &isCoreShl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "coreShl_charge0", &coreShl_charge0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "coreShl_charge1", &coreShl_charge1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "coreShl_charge2", &coreShl_charge2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "coreShl_just", &coreShl_just, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isLevelScale", &isLevelScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale1", &scale1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale2", &scale2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale3", &scale3, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale4", &scale4, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale5", &scale5, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale6", &scale6, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale7", &scale7, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale8", &scale8, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale9", &scale9, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale10", &scale10, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isCs11", &isCs11, 0u, 0u);
}

void cShlParamMgcArrow::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamSpeed::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoCs11Miss", &epvNoCs11Miss, 0u, 0u);
}

void cShlParamMgcArrow::createPropertySE(MtPropertyList& s) {
    this->cShlParamHoming::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "seNoCs11Success", &seNoCs11Success, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoCs11Miss", &seNoCs11Miss, 0u, 0u);
}

__attribute__((weak)) void cShlParamMgcArrow::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamMgcArrow::copy")
    /* stub */
}

inline cShlParamMgcArrow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamMgcArrow::MyDTI cShlParamMgcArrow::DTI("cShlParamMgcArrow", &::cShlParamHoming::DTI, 736ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamMgcArrow::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamMgcArrow::DTI)->memAlloc(sizeof(cShlParamMgcArrow), 16u, cShlParamMgcArrow::DTI.getID())) cShlParamMgcArrow;
}

const MtDTI& uShlJob08CS13::getDTI() const {
    return uShlJob08CS13::DTI;
}

uShlJob08CS13::~uShlJob08CS13() {
    DDON_STUB("uShlJob08CS13::~uShlJob08CS13")
    /* stub */
}

void uShlJob08CS13::setup() {
    this->uShlHoming::setup();
    if (mLockOnTarget.get() == nullptr) {
        return;
    }
    uDDOModel* t0 = mLockOnTarget.get()->getDDOModelOwner();
    if (t0 == nullptr) {
        return;
    }
    if (getShlParamBase() == nullptr) {
        return;
    }
    if (static_cast<int>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 728)) > -1) {
        if (getObjCollisionPtr() != nullptr) {
            if (getObjCollisionPtr()->mpResource[0] != nullptr) {
                if (getObjCollisionPtr()->mpResource[0]->cResource::isUsage()) {
                    getObjCollisionPtr()->createNodeFromIndex(0u, static_cast<s32>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 728)), false, 0xFFFFFFFFu);
                    getObjCollisionPtr()->mGripAttackOnly.add(t0);
                    mExtendDieTime = mExtendDieTime + 100000.0f;
                }
            }
        }
    }
}

inline uShlJob08CS13::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob08CS13::MyDTI uShlJob08CS13::DTI("uShlJob08CS13", &::uShlMgcArrow::DTI, 11248ul, 0u, 0u);

MtObject* uShlJob08CS13::MyDTI::newInstance() const {
    return new (16u) uShlJob08CS13;
}

const MtDTI& uShlMgcArrow::getDTI() const {
    return uShlMgcArrow::DTI;
}

uShlMgcArrow::~uShlMgcArrow() {
}

__attribute__((weak)) void uShlMgcArrow::updateSub() {
    DDON_STUB("uShlMgcArrow::updateSub")
    /* stub */
}

void uShlMgcArrow::callbackCheck(cHitInfo* pHitInfo) {
    this->uShlBase::callbackCheck(pHitInfo);
    if (pHitInfo == nullptr) {
        return;
    }
    if (pHitInfo->mpDfdModel == nullptr) {
        return;
    }
    if ((pHitInfo->mpDfdModel->mUnitId & 200u) == 0) {
        return;
    }
    hitShlCreate(pHitInfo);
    setHitMark(mPos, 1.0f);
}

__attribute__((weak)) void uShlMgcArrow::callbackAttack(cHitInfo* pHitInfo) {
    DDON_STUB("uShlMgcArrow::callbackAttack")
    /* stub */
}

__attribute__((weak)) void uShlMgcArrow::hitShlCreate(cHitInfo* pHitInfo) {
    DDON_STUB("uShlMgcArrow::hitShlCreate")
    /* stub */
}

__attribute__((weak)) f32 uShlMgcArrow::getCustomSkillLevelScale() {
    DDON_STUB("uShlMgcArrow::getCustomSkillLevelScale")
    return {};
}

inline uShlMgcArrow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlMgcArrow::MyDTI uShlMgcArrow::DTI("uShlMgcArrow", &::uShlHoming::DTI, 11248ul, 0u, 0u);

MtObject* uShlMgcArrow::MyDTI::newInstance() const {
    return new (16u) uShlMgcArrow;
}

