// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpShlKeyFrame.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpComponent.h"
#include "cpShlBase.h"
#include "nDDOUtility.h"
#include "../../XFramework/uCoord.h"
#include "uShlBase.h"
#include "uShlComponentCtrl.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamCompKeyFrame::getDTI() const {
    return cShlParamCompKeyFrame::DTI;
}

inline void cShlParamCompKeyFrame::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamCompKeyFrame::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamCompKeyFrame::getComponentDTI() const {
    return cpShlKeyFrame::DTI;
}

void cShlParamCompKeyFrame::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "type", reinterpret_cast<s32*>(&type), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "curve", reinterpret_cast<s32*>(&curve), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "valueScale", &valueScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "keyFrame", &keyFrame, 0u, 0u);
}

__attribute__((weak)) void cShlParamCompKeyFrame::copy(const cShlParamComponent* pParamBase) {
    DDON_STUB("cShlParamCompKeyFrame::copy")
    /* stub */
}

inline cShlParamCompKeyFrame::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCompKeyFrame::MyDTI cShlParamCompKeyFrame::DTI("cShlParamCompKeyFrame", &::cShlParamComponent::DTI, 104ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamCompKeyFrame::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamCompKeyFrame::DTI)->memAlloc(sizeof(cShlParamCompKeyFrame), 16u, cShlParamCompKeyFrame::DTI.getID())) cShlParamCompKeyFrame;
}

const MtDTI& cpShlKeyFrame::getDTI() const {
    return cpShlKeyFrame::DTI;
}

inline void cpShlKeyFrame::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cpShlKeyFrame::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cpShlKeyFrame::initSub() {
    DDON_STUB("cpShlKeyFrame::initSub")
    /* stub */
}

__attribute__((weak)) void cpShlKeyFrame::updateSub() {
    DDON_STUB("cpShlKeyFrame::updateSub")
    /* stub */
}

inline cpShlKeyFrame::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlKeyFrame::MyDTI cpShlKeyFrame::DTI("cpShlKeyFrame", &::cpShlBase::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* cpShlKeyFrame::MyDTI::newInstance() const {
    DDON_STUB("cpShlKeyFrame::MyDTI::newInstance")
    return nullptr;
}

