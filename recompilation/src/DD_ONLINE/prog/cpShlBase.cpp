// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpShlBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cpComponent.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamComponent::getDTI() const {
    return cShlParamComponent::DTI;
}

inline void cShlParamComponent::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamComponent::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamComponent::getComponentDTI() const {
    return cpShlBase::DTI;
}

__attribute__((weak)) void cShlParamComponent::copy(const cShlParamComponent* pParam) {
}

inline cShlParamComponent::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamComponent::MyDTI cShlParamComponent::DTI("cShlParamComponent", &::MtObject::DTI, 8ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamComponent::MyDTI::newInstance() const {
    DDON_STUB("cShlParamComponent::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cpShlBase::getDTI() const {
    return cpShlBase::DTI;
}

inline void* cpShlBase::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cpShlBase::DTI)->memAlloc(sz, align, cpShlBase::DTI.getID());
}

inline void cpShlBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cpShlBase::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cpShlBase::initSub() {
}

__attribute__((weak)) void cpShlBase::updateSub() {
}

void cpShlBase::setParam(cShlParamComponent* pParam) {
    mpParam = pParam;
}

inline cpShlBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlBase::MyDTI cpShlBase::DTI("cpShlBase", &::cpComponent::DTI, 88ul, 0u, 0u);

MtObject* cpShlBase::MyDTI::newInstance() const {
    return new (16u) cpShlBase;
}

