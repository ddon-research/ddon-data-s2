// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cZoneCategoryStatus.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cZoneContents.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cZoneCategoryCheckState::getDTI() const {
    return cZoneCategoryCheckState::DTI;
}

inline void* cZoneCategoryCheckState::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cZoneCategoryCheckState::DTI)->memAlloc(sz, align, cZoneCategoryCheckState::DTI.getID());
}

inline void cZoneCategoryCheckState::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cZoneCategoryCheckState::DTI)->memFree(p_addr);
}

cZoneCategoryCheckState::~cZoneCategoryCheckState() {
}

u32 cZoneCategoryCheckState::getCheckState() const {
    return mStateBit;
}

void cZoneCategoryCheckState::createProperty(MtPropertyList& s) {
    this->cZoneContents::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mStateBit", &mStateBit, 0u, 0u);
}

inline cZoneCategoryCheckState::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneCategoryCheckState::MyDTI cZoneCategoryCheckState::DTI("cZoneCategoryCheckState", &::cZoneCategoryStatusBase::DTI, 32ul, 0u, 0u);

MtObject* cZoneCategoryCheckState::MyDTI::newInstance() const {
    return new (16u) cZoneCategoryCheckState;
}

const MtDTI& cZoneCategoryStatus::getDTI() const {
    return cZoneCategoryStatus::DTI;
}

inline void* cZoneCategoryStatus::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cZoneCategoryStatus::DTI)->memAlloc(sz, align, cZoneCategoryStatus::DTI.getID());
}

inline void cZoneCategoryStatus::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cZoneCategoryStatus::DTI)->memFree(p_addr);
}

cZoneCategoryStatus::~cZoneCategoryStatus() {
}

u32 cZoneCategoryStatus::getChangeStatus() const {
    return 4101;
}

void cZoneCategoryStatus::createProperty(MtPropertyList& s) {
    this->cZoneContents::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mChangeStatus", &mChangeStatus, 0u, 0u);
}

inline cZoneCategoryStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneCategoryStatus::MyDTI cZoneCategoryStatus::DTI("cZoneCategoryStatus", &::cZoneCategoryStatusBase::DTI, 32ul, 0u, 0u);

MtObject* cZoneCategoryStatus::MyDTI::newInstance() const {
    return new (16u) cZoneCategoryStatus;
}

const MtDTI& cZoneCategoryStatusBase::getDTI() const {
    return cZoneCategoryStatusBase::DTI;
}

inline void* cZoneCategoryStatusBase::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cZoneCategoryStatusBase::DTI)->memAlloc(sz, align, cZoneCategoryStatusBase::DTI.getID());
}

inline void cZoneCategoryStatusBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cZoneCategoryStatusBase::DTI)->memFree(p_addr);
}

inline cZoneCategoryStatusBase::cZoneCategoryStatusBase() {
    setAttribute(32768u, true);
    setAttribute(0x10000u, true);
}

inline cZoneCategoryStatusBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneCategoryStatusBase::MyDTI cZoneCategoryStatusBase::DTI("cZoneCategoryStatusBase", &::cZoneContents::DTI, 32ul, 0u, 0u);

MtObject* cZoneCategoryStatusBase::MyDTI::newInstance() const {
    return new (16u) cZoneCategoryStatusBase;
}

