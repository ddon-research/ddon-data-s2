// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlJob10CS04.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpShlShotCtrl.h"
#include "cpjob10.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamJob10CS04::getDTI() const {
    return cShlParamJob10CS04::DTI;
}

inline void* cShlParamJob10CS04::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamJob10CS04::DTI)->memAlloc(sz, align, cShlParamJob10CS04::DTI.getID());
}

inline void cShlParamJob10CS04::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamJob10CS04::DTI)->memFree(p_addr);
}

MtDTI& cShlParamJob10CS04::getShlDTI() const {
    return uShlJob10CS04::DTI;
}

void cShlParamJob10CS04::createProperty(MtPropertyList& s) {
    this->cShlParamSpeed::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mDieShlIdx", &mDieShlIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDieDistance", &mDieDistance, 0u, 0u);
}

cShlParamJob10CS04::~cShlParamJob10CS04() {
}

void cShlParamJob10CS04::copy(const cShlParamBase* pParamBase) {
    this->cShlParamSpeed::copy(pParamBase);
    const cShlParamJob10CS04* pParam = static_cast<const cShlParamJob10CS04*>(pParamBase);
    mDieShlIdx = pParam->mDieShlIdx;
    mDieDistance = pParam->mDieDistance;
}

inline cShlParamJob10CS04::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob10CS04::MyDTI cShlParamJob10CS04::DTI("cShlParamJob10CS04", &::cShlParamSpeed::DTI, 512ul, 0u, 0u);

MtObject* cShlParamJob10CS04::MyDTI::newInstance() const {
    return new (16u) cShlParamJob10CS04;
}

const MtDTI& uShlJob10CS04::getDTI() const {
    return uShlJob10CS04::DTI;
}

inline void* uShlJob10CS04::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlJob10CS04::DTI)->memAlloc(sz, align, uShlJob10CS04::DTI.getID());
}

inline void uShlJob10CS04::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlJob10CS04::DTI)->memFree(p_addr);
}

inline const cShlParamJob10CS04* uShlJob10CS04::getShlParam() const {
    return static_cast<const cShlParamJob10CS04*>(mpShlParam2);
}

inline uShlJob10CS04::uShlJob10CS04() {
    mFlgCreateDieShl = false;
    mDiePos = MtVector3::Zero;
}

void uShlJob10CS04::setup() {
    this->uShlSpeed::setup();
}

__attribute__((weak)) void uShlJob10CS04::updateSub() {
    DDON_STUB("uShlJob10CS04::updateSub")
    /* stub */
}

void uShlJob10CS04::kill() {
    this->uShlSpeed::kill();
}

__attribute__((weak)) void uShlJob10CS04::progKillReqOrg() {
    DDON_STUB("uShlJob10CS04::progKillReqOrg")
    /* stub */
}

__attribute__((weak)) void uShlJob10CS04::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlJob10CS04::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uShlJob10CS04::callbackAttack(cHitInfo* pHitInfo) {
    DDON_STUB("uShlJob10CS04::callbackAttack")
    /* stub */
}

void uShlJob10CS04::setDiePos(const MtVector3& pos) {
    mDiePos = pos;
}

inline uShlJob10CS04::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob10CS04::MyDTI uShlJob10CS04::DTI("uShlJob10CS04", &::uShlSpeed::DTI, 11168ul, 0u, 0u);

MtObject* uShlJob10CS04::MyDTI::newInstance() const {
    return new (16u) uShlJob10CS04;
}

