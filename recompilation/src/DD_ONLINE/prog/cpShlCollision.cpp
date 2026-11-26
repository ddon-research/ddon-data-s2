// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpShlCollision.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpComponent.h"
#include "cpShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamCompCollision::getDTI() const {
    return cShlParamCompCollision::DTI;
}

inline void* cShlParamCompCollision::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamCompCollision::DTI)->memAlloc(sz, align, cShlParamCompCollision::DTI.getID());
}

inline void cShlParamCompCollision::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamCompCollision::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamCompCollision::getComponentDTI() const {
    return cpShlCollision::DTI;
}

void cShlParamCompCollision::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "seq_0", &seq_0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "at_0", &at_0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shared_uid_0", &shared_uid_0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "colTimer_0", &colTimer_0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seq_1", &seq_1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "at_1", &at_1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shared_uid_1", &shared_uid_1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "colTimer_1", &colTimer_1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seq_2", &seq_2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "at_2", &at_2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shared_uid_2", &shared_uid_2, 0u, 0u);
}

void cShlParamCompCollision::copy(const cShlParamComponent* pParamBase) {
    this->cShlParamComponent::copy(pParamBase);
    const cShlParamCompCollision* pParam = static_cast<const cShlParamCompCollision*>(pParamBase);
    seq_0 = pParam->seq_0;
    at_0 = pParam->at_0;
    shared_uid_0 = pParam->shared_uid_0;
    colTimer_0 = pParam->colTimer_0;
    seq_1 = pParam->seq_1;
    at_1 = pParam->at_1;
    shared_uid_1 = pParam->shared_uid_1;
    colTimer_1 = pParam->colTimer_1;
    seq_2 = pParam->seq_2;
    at_2 = pParam->at_2;
    shared_uid_2 = pParam->shared_uid_2;
}

inline cShlParamCompCollision::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCompCollision::MyDTI cShlParamCompCollision::DTI("cShlParamCompCollision", &::cShlParamComponent::DTI, 56ul, 0u, 0u);

MtObject* cShlParamCompCollision::MyDTI::newInstance() const {
    return new (16u) cShlParamCompCollision;
}

const MtDTI& cpShlCollision::getDTI() const {
    return cpShlCollision::DTI;
}

inline void cpShlCollision::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cpShlCollision::DTI)->memFree(p_addr);
}

inline cpShlCollision::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlCollision::MyDTI cpShlCollision::DTI("cpShlCollision", &::cpShlBase::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* cpShlCollision::MyDTI::newInstance() const {
    DDON_STUB("cpShlCollision::MyDTI::newInstance")
    return nullptr;
}

