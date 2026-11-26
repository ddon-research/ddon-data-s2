// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlDividedCalled.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamDividedCalled::getDTI() const {
    return cShlParamDividedCalled::DTI;
}

inline void* cShlParamDividedCalled::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamDividedCalled::DTI)->memAlloc(sz, align, cShlParamDividedCalled::DTI.getID());
}

inline void cShlParamDividedCalled::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamDividedCalled::DTI)->memFree(p_addr);
}

MtDTI& cShlParamDividedCalled::getShlDTI() const {
    return uShlDividedCalled::DTI;
}

void cShlParamDividedCalled::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "shlList", static_cast<MtObject*>(&shlList), 0u, 0u);
}

__attribute__((noinline)) cShlParamDividedCalled::~cShlParamDividedCalled() {
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

void cShlParamDividedCalled::copy(const cShlParamBase* pParamBase) {
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
    addShlList(static_cast<const cShlParamDividedCalled*>(pParamBase));
}

__attribute__((weak)) void cShlParamDividedCalled::addShlList(const cShlParamDividedCalled* pParam) {
    DDON_STUB("cShlParamDividedCalled::addShlList")
    /* stub */
}

inline cShlParamDividedCalled::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamDividedCalled::MyDTI cShlParamDividedCalled::DTI("cShlParamDividedCalled", &::cShlParamBase::DTI, 384ul, 0u, 0u);

MtObject* cShlParamDividedCalled::MyDTI::newInstance() const {
    return new (16u) cShlParamDividedCalled;
}

const MtDTI& cShlParamDividedCalled::cDividedCalledParam::getDTI() const {
    return cShlParamDividedCalled::cDividedCalledParam::DTI;
}

inline void* cShlParamDividedCalled::cDividedCalledParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamDividedCalled::cDividedCalledParam::DTI)->memAlloc(sz, align, cShlParamDividedCalled::cDividedCalledParam::DTI.getID());
}

inline void cShlParamDividedCalled::cDividedCalledParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamDividedCalled::cDividedCalledParam::DTI)->memFree(p_addr);
}

void cShlParamDividedCalled::cDividedCalledParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "value", &value, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNo", &shlNo, 0u, 0u);
}

void cShlParamDividedCalled::cDividedCalledParam::createPropertyTool(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "value", &value, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNo", &shlNo, 0u, 0u);
}

inline cShlParamDividedCalled::cDividedCalledParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamDividedCalled::cDividedCalledParam::MyDTI cShlParamDividedCalled::cDividedCalledParam::DTI("cShlParamDividedCalled::cDividedCalledParam", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cShlParamDividedCalled::cDividedCalledParam::MyDTI::newInstance() const {
    return new (16u) cShlParamDividedCalled::cDividedCalledParam;
}

const MtDTI& uShlDividedCalled::getDTI() const {
    return uShlDividedCalled::DTI;
}

inline void* uShlDividedCalled::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlDividedCalled::DTI)->memAlloc(sz, align, uShlDividedCalled::DTI.getID());
}

inline void uShlDividedCalled::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlDividedCalled::DTI)->memFree(p_addr);
}

uShlDividedCalled::~uShlDividedCalled() {
}

void uShlDividedCalled::setup() {
    this->uShlBase::setup();
}

__attribute__((weak)) void uShlDividedCalled::updateSub() {
    DDON_STUB("uShlDividedCalled::updateSub")
    /* stub */
}

inline uShlDividedCalled::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlDividedCalled::MyDTI uShlDividedCalled::DTI("uShlDividedCalled", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlDividedCalled::MyDTI::newInstance() const {
    return new (16u) uShlDividedCalled;
}

