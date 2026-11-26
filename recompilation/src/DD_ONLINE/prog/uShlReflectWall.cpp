// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlReflectWall.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpShlShotCtrl.h"
#include "sEffectExt.h"
#include "sLockOnManager.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlHoming.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamReflectWall::getDTI() const {
    return cShlParamReflectWall::DTI;
}

inline void cShlParamReflectWall::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamReflectWall::DTI)->memFree(p_addr);
}

MtDTI& cShlParamReflectWall::getShlDTI() const {
    return uShlReflectWall::DTI;
}

cShlParamReflectWall::~cShlParamReflectWall() {
}

void cShlParamReflectWall::createProperty(MtPropertyList& s) {
    this->cShlParamHoming::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "isReflectWall", &isReflectWall, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "reflectCheckRadius", &reflectCheckRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "reflectCnt", &reflectCnt, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNoReflectWall", &shlNoReflectWall, 0u, 0u);
}

void cShlParamReflectWall::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoReflectWall", &epvNoReflectWall, 0u, 0u);
}

__attribute__((weak)) void cShlParamReflectWall::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamReflectWall::copy")
    /* stub */
}

inline cShlParamReflectWall::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamReflectWall::MyDTI cShlParamReflectWall::DTI("cShlParamReflectWall", &::cShlParamHoming::DTI, 608ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamReflectWall::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamReflectWall::DTI)->memAlloc(sizeof(cShlParamReflectWall), 16u, cShlParamReflectWall::DTI.getID())) cShlParamReflectWall;
}

const MtDTI& uShlReflectWall::getDTI() const {
    return uShlReflectWall::DTI;
}

inline void* uShlReflectWall::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlReflectWall::DTI)->memAlloc(sz, align, uShlReflectWall::DTI.getID());
}

inline void uShlReflectWall::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlReflectWall::DTI)->memFree(p_addr);
}

inline const cShlParamReflectWall* uShlReflectWall::getShlParam() const {
    return static_cast<const cShlParamReflectWall*>(mpShlParam2);
}

uShlReflectWall::~uShlReflectWall() {
}

__attribute__((weak)) void uShlReflectWall::updateSub() {
    DDON_STUB("uShlReflectWall::updateSub")
    /* stub */
}

inline uShlReflectWall::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlReflectWall::MyDTI uShlReflectWall::DTI("uShlReflectWall", &::uShlHoming::DTI, 11232ul, 0u, 0u);

MtObject* uShlReflectWall::MyDTI::newInstance() const {
    return new (16u) uShlReflectWall;
}

