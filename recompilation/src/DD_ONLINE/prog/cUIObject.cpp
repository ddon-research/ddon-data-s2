// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cUIObject.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cTexturePNG::getDTI() const {
    return cTexturePNG::DTI;
}

void* cTexturePNG::operator new(size_t sz, u32 align) {
    return cTexturePNG::getAllocator()->memAlloc(sz, align, cTexturePNG::DTI.getID());
}

cTexturePNG::~cTexturePNG() {
    DDON_STUB("cTexturePNG::~cTexturePNG")
    /* stub */
}

__attribute__((weak)) void cTexturePNG::set(void* ppng, size_t size) {
    DDON_STUB("cTexturePNG::set")
    /* stub */
}

inline cTexturePNG::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cTexturePNG::MyDTI cTexturePNG::DTI("cTexturePNG", &::cUIObject::DTI, 288ul, 0u, 0u);

MtObject* cTexturePNG::MyDTI::newInstance() const {
    return new (16u) cTexturePNG;
}

const MtDTI& cUIObject::getDTI() const {
    return cUIObject::DTI;
}

void* cUIObject::operator new(size_t sz, u32 align) {
    return cUIObject::getAllocator()->memAlloc(sz, align, cUIObject::DTI.getID());
}

__attribute__((weak)) void cUIObject::operator delete(void* p_addr) {
    cUIObject::getAllocator()->memFree(p_addr);
}

MtUI* cUIObject::createUI(MtProperty& prop) {
    return nullptr;
}

__attribute__((weak)) void cUIObject::createProperty(MtPropertyList& s) {
}

inline cUIObject::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cUIObject::MyDTI cUIObject::DTI("cUIObject", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* cUIObject::MyDTI::newInstance() const {
    return new (16u) cUIObject;
}

const MtDTI& cUIResource::getDTI() const {
    return cUIResource::DTI;
}

MtUI* cUIResource::createUI(MtProperty& prop) {
    return nullptr;
}

__attribute__((weak)) void cUIResource::createProperty(MtPropertyList& s) {
}

inline cUIResource::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cUIResource::MyDTI cUIResource::DTI("cUIResource", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* cUIResource::MyDTI::newInstance() const {
    return new (16u) cUIResource;
}

