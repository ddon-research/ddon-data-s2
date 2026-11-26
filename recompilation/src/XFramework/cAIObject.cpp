// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cAIObject.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAIObject::getDTI() const {
    return cAIObject::DTI;
}

inline void* cAIObject::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAIObject::DTI)->memAlloc(sz, align, cAIObject::DTI.mID);
}

inline void cAIObject::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIObject::DTI)->memFree(p_addr);
}

cAIObject::cAIObject() {
}

cAIObject::~cAIObject() {
}

MtUI* cAIObject::createUI(MtProperty& prop) {
    return nullptr;
}

__attribute__((weak)) void cAIObject::createProperty(MtPropertyList& s) {
}

inline cAIObject::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIObject::MyDTI cAIObject::DTI("cAIObject", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* cAIObject::MyDTI::newInstance() const {
    return new (16u) cAIObject;
}

const MtDTI& cAIResource::getDTI() const {
    return cAIResource::DTI;
}

inline void* cAIResource::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAIResource::DTI)->memAlloc(sz, align, cAIResource::DTI.mID);
}

inline void cAIResource::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIResource::DTI)->memFree(p_addr);
}

cAIResource::cAIResource() {
}

cAIResource::~cAIResource() {
}

MtUI* cAIResource::createUI(MtProperty& prop) {
    return nullptr;
}

__attribute__((weak)) void cAIResource::createProperty(MtPropertyList& s) {
}

inline cAIResource::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIResource::MyDTI cAIResource::DTI("cAIResource", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* cAIResource::MyDTI::newInstance() const {
    return new (16u) cAIResource;
}

