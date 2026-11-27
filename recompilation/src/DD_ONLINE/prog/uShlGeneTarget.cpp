// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlGeneTarget.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpShlShotCtrl.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlGenerator.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamGeneTarget::getDTI() const {
    return cShlParamGeneTarget::DTI;
}

MtDTI& cShlParamGeneTarget::getShlDTI() const {
    return uShlGeneTarget::DTI;
}

__attribute__((noinline)) cShlParamGeneTarget::~cShlParamGeneTarget() {
    for (u32 i = 0; i < shlList.mLength; i++) {
        delete shlList.mpArray[i];
    }
    if (shlList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(shlList.mpArray));
    }
    shlList.mpArray = nullptr;
    shlList.mBufsiz = 0;
    shlList.mLength = 0;
}

void cShlParamGeneTarget::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "shlList", static_cast<MtObject*>(&shlList), 0u, 0u);
}

void cShlParamGeneTarget::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
}

void cShlParamGeneTarget::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    if (shlList.mLength != 0) {
        u32 v0_0 = shlList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (shlList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete shlList.mpArray[i0_3];
                v1_0 = shlList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (shlList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(shlList.mpArray));
    }
    shlList.mpArray = nullptr;
    shlList.mBufsiz = 0;
    shlList.mLength = 0;
    addShlList(static_cast<const cShlParamGeneTarget*>(pParamBase));
}

__attribute__((weak)) void cShlParamGeneTarget::addShlList(const cShlParamGeneTarget* pParam) {
    DDON_STUB("cShlParamGeneTarget::addShlList")
    /* stub */
}

inline cShlParamGeneTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamGeneTarget::MyDTI cShlParamGeneTarget::DTI("cShlParamGeneTarget", &::cShlParamBase::DTI, 384ul, 0u, 0u);

MtObject* cShlParamGeneTarget::MyDTI::newInstance() const {
    return new (16u) cShlParamGeneTarget;
}

const MtDTI& cShlParamGeneTarget::cShootCtrlParamGeneTarget::getDTI() const {
    return cShlParamGeneTarget::cShootCtrlParamGeneTarget::DTI;
}

void cShlParamGeneTarget::cShootCtrlParamGeneTarget::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "waitFrame", &waitFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNo", &shlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "offset", &offset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "degY", &degY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "distScale", &distScale, 0u, 0u);
}

inline cShlParamGeneTarget::cShootCtrlParamGeneTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamGeneTarget::cShootCtrlParamGeneTarget::MyDTI cShlParamGeneTarget::cShootCtrlParamGeneTarget::DTI("cShlParamGeneTarget::cShootCtrlParamGeneTarget", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cShlParamGeneTarget::cShootCtrlParamGeneTarget::MyDTI::newInstance() const {
    return new (16u) cShlParamGeneTarget::cShootCtrlParamGeneTarget;
}

const MtDTI& uShlGeneTarget::getDTI() const {
    return uShlGeneTarget::DTI;
}

uShlGeneTarget::~uShlGeneTarget() {
}

void uShlGeneTarget::setup() {
    this->uShlGenerator::setup();
}

__attribute__((weak)) void uShlGeneTarget::updateSub() {
    DDON_STUB("uShlGeneTarget::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlGeneTarget::setShl(u32 shlNo, const MtVector3& offset, f32 degY, f32 scale) {
    DDON_STUB("uShlGeneTarget::setShl")
    /* stub */
}

inline uShlGeneTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlGeneTarget::MyDTI uShlGeneTarget::DTI("uShlGeneTarget", &::uShlGenerator::DTI, 10960ul, 0u, 0u);

MtObject* uShlGeneTarget::MyDTI::newInstance() const {
    return new (16u) uShlGeneTarget;
}

