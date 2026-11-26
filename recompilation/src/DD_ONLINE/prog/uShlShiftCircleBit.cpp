// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlShiftCircleBit.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "nDDOUtility.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sControlManager.h"
#include "../../XFramework/uBaseModel.h"
#include "uControl.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamShiftCircleBit::getDTI() const {
    return cShlParamShiftCircleBit::DTI;
}

inline void* cShlParamShiftCircleBit::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamShiftCircleBit::DTI)->memAlloc(sz, align, cShlParamShiftCircleBit::DTI.getID());
}

inline void cShlParamShiftCircleBit::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamShiftCircleBit::DTI)->memFree(p_addr);
}

MtDTI& cShlParamShiftCircleBit::getShlDTI() const {
    return uShlShiftCircleBit::DTI;
}

void cShlParamShiftCircleBit::createProperty(MtPropertyList& proplist) {
    this->cShlParamBase::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "mShiftCircleBitDistance", &mShiftCircleBitDistance, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mShiftCircleBitPos", &mShiftCircleBitPos, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mTransparencyDistance", &mTransparencyDistance, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mTransparencyDistanceMax", &mTransparencyDistanceMax, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mTransparencyMax", &mTransparencyMax, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mTransparencyMin", &mTransparencyMin, 0u, 0u);
}

__attribute__((weak)) void cShlParamShiftCircleBit::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamShiftCircleBit::copy")
    /* stub */
}

inline cShlParamShiftCircleBit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamShiftCircleBit::MyDTI cShlParamShiftCircleBit::DTI("cShlParamShiftCircleBit", &::cShlParamBase::DTI, 384ul, 0u, 0u);

MtObject* cShlParamShiftCircleBit::MyDTI::newInstance() const {
    return new (16u) cShlParamShiftCircleBit;
}

const MtDTI& uShlShiftCircleBit::getDTI() const {
    return uShlShiftCircleBit::DTI;
}

inline void* uShlShiftCircleBit::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlShiftCircleBit::DTI)->memAlloc(sz, align, uShlShiftCircleBit::DTI.getID());
}

inline void uShlShiftCircleBit::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlShiftCircleBit::DTI)->memFree(p_addr);
}

void uShlShiftCircleBit::setup() {
    this->uShlBase::setup();
    mShiftCircleBitTimer = 0.0f;
}

__attribute__((weak)) void uShlShiftCircleBit::update() {
    DDON_STUB("uShlShiftCircleBit::update")
    /* stub */
}

inline uShlShiftCircleBit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlShiftCircleBit::MyDTI uShlShiftCircleBit::DTI("uShlShiftCircleBit", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlShiftCircleBit::MyDTI::newInstance() const {
    return new (16u) uShlShiftCircleBit;
}

