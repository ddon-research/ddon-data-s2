// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlFireWall.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpObjCollision.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "../../XFramework/sCollision.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamFireWallCtrl::getDTI() const {
    return cShlParamFireWallCtrl::DTI;
}

inline void cShlParamFireWallCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamFireWallCtrl::DTI)->memFree(p_addr);
}

MtDTI& cShlParamFireWallCtrl::getShlDTI() const {
    return uShlFireWallCtrl::DTI;
}

void cShlParamFireWallCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "laserDist", &laserDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "laserRange", &laserRange, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "laserHeight", &laserHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "wallInter", &wallInter, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "wallRandom", &wallRandom, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "wait_2", &wait_2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "wait_3", &wait_3, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNoWall", &shlNoWall, 0u, 0u);
}

void cShlParamFireWallCtrl::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoLight", &epvNoLight, 0u, 0u);
}

void cShlParamFireWallCtrl::createPropertySE(MtPropertyList& s) {
    this->cShlParamBase::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "seNoLoopL", &seNoLoopL, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoLoopC", &seNoLoopC, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoLoopR", &seNoLoopR, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoLoopStopL", &seNoLoopStopL, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoLoopStopC", &seNoLoopStopC, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoLoopStopR", &seNoLoopStopR, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoYochoL", &seNoYochoL, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoYochoR", &seNoYochoR, 0u, 0u);
}

cShlParamFireWallCtrl::~cShlParamFireWallCtrl() {
}

__attribute__((weak)) void cShlParamFireWallCtrl::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamFireWallCtrl::copy")
    /* stub */
}

inline cShlParamFireWallCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamFireWallCtrl::MyDTI cShlParamFireWallCtrl::DTI("cShlParamFireWallCtrl", &::cShlParamBase::DTI, 432ul, 0u, 0u);

MtObject* cShlParamFireWallCtrl::MyDTI::newInstance() const {
    return new (16u) cShlParamFireWallCtrl;
}

const MtDTI& uShlFireWallCtrl::getDTI() const {
    return uShlFireWallCtrl::DTI;
}

uShlFireWallCtrl::~uShlFireWallCtrl() {
}

__attribute__((weak)) void uShlFireWallCtrl::setup() {
    DDON_STUB("uShlFireWallCtrl::setup")
    /* stub */
}

__attribute__((weak)) void uShlFireWallCtrl::updateSub() {
    DDON_STUB("uShlFireWallCtrl::updateSub")
    /* stub */
}

void uShlFireWallCtrl::kill() {
    requestSE(static_cast<s32>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 408)), mPos);
    requestSE(static_cast<s32>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 412)), mPos);
    requestSE(static_cast<s32>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 416)), mPos);
    this->uShlBase::kill();
}

__attribute__((weak)) void uShlFireWallCtrl::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlFireWallCtrl::applyWorldOffset")
    /* stub */
}

inline uShlFireWallCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlFireWallCtrl::MyDTI uShlFireWallCtrl::DTI("uShlFireWallCtrl", &::uShlBase::DTI, 11568ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlFireWallCtrl::MyDTI::newInstance() const {
    DDON_STUB("uShlFireWallCtrl::MyDTI::newInstance")
    return nullptr;
}

