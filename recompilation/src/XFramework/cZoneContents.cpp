// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cZoneContents.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "nZone.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void cZoneContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZoneContents::DTI)->memFree(p_addr);
}

const MtDTI& cZoneContents::getDTI() const {
    return cZoneContents::DTI;
}

cZoneContents::cZoneContents() {
    mFlgUse = false;
    mIsNativeData = false;
}

cZoneContents::~cZoneContents() {
}

void cZoneContents::createProperty(MtPropertyList& s) {
    createPropertyContentsBase(s);
}

void cZoneContents::createPropertyForUI(MtPropertyList& s) {
    createProperty(s);
}

void cZoneContents::copy(cZoneContents* pContents) {
    nZone::cContentsPool::copyObjectProperty(static_cast<MtObject*>(this), static_cast<MtObject*>(pContents));
}

__attribute__((weak)) bool cZoneContents::copyResource(cZoneContents* pContents) {
    DDON_STUB("cZoneContents::copyResource")
    return {};
}

__attribute__((weak)) void cZoneContents::createPropertyContentsBase(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mName", &mName, 8193u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCategoryName", &mCategoryName, 8193u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Use", &mFlgUse, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Native", &mIsNativeData, 1u, 0u);
}

__attribute__((weak)) void cZoneContents::setCategoryName(MT_CTSTR CategoryName) {
    mName = "";
    mCategoryName = CategoryName;
}

__attribute__((weak)) void cZoneContents::setContentsName(MT_CTSTR ContentsName) {
    mName = ContentsName;
}

__attribute__((weak)) void cZoneContents::setAttribute(u32 attr) {
}

__attribute__((weak)) void cZoneContents::setAttribute(u32 TargetAttribute, bool flag) {
}

__attribute__((weak)) void cZoneContents::setBroadPhaseSearchMode(u32 SearchMode) {
}

__attribute__((weak)) void cZoneContents::setDefaultShapeType(u32 DefaultShapeType) {
}

__attribute__((weak)) void cZoneContents::setExtendObjectDTI(const MtDTI& NewExtendObjectDTI) {
}

void cZoneContents::copyMainFromGame(cZoneContents* pSourceContents) {
    if (copyResource(pSourceContents)) {
        return;
    }
    copy(pSourceContents);
    mIsNativeData = false;
}

inline cZoneContents::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneContents::MyDTI cZoneContents::DTI("cZoneContents", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cZoneContents::MyDTI::newInstance() const {
    return new (16u) cZoneContents;
}

