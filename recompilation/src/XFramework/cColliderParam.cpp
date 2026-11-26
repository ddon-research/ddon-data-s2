// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cColliderParam.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "nCollision.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void cColliderGeometryParam::usage() {
}

const MtDTI& cColliderGeometryParam::getDTI() const {
    return cColliderGeometryParam::DTI;
}

inline void cColliderGeometryParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cColliderGeometryParam::DTI)->memFree(p_addr);
}

cColliderGeometryParam::~cColliderGeometryParam() {
}

MtUI* cColliderGeometryParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cColliderGeometryParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "ver", reinterpret_cast<MT_MFUNC>(&::cColliderGeometryParam::getVersion), reinterpret_cast<MT_MFUNC>(&::cColliderGeometryParam::setDummyU16), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Attribute", &mAttribute, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttribute", &mAttribute, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Attribute", &mAttribute, 2u, 0u);
}

static auto ddon_emit_0x01bd70d0 __attribute__((used)) = &cColliderGeometryParam::getVersion;

u32 cColliderGeometryParam::getAttribute() const {
    return mAttribute;
}

__attribute__((weak)) void cColliderGeometryParam::setDummyU16(u16) {
}

inline cColliderGeometryParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cColliderGeometryParam::MyDTI cColliderGeometryParam::DTI("cColliderGeometryParam", &::nCollision::cAllocaterIntermediate::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cColliderGeometryParam::MyDTI::newInstance() const {
    DDON_STUB("cColliderGeometryParam::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void cColliderNodeParam::usage() {
}

const MtDTI& cColliderNodeParam::getDTI() const {
    return cColliderNodeParam::DTI;
}

inline void* cColliderNodeParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cColliderNodeParam::DTI)->memAlloc(sz, align, cColliderNodeParam::DTI.mID);
}

inline void cColliderNodeParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cColliderNodeParam::DTI)->memFree(p_addr);
}

cColliderNodeParam::~cColliderNodeParam() {
    if (!mFlgAutoDeleteUserDataPtr) {
        return;
    }
    if (mpUserDataPtr == nullptr) {
        return;
    }
    delete mpUserDataPtr;
    mpUserDataPtr = nullptr;
}

void cColliderNodeParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "ver", reinterpret_cast<MT_MFUNC>(&::cColliderNodeParam::getVersion), reinterpret_cast<MT_MFUNC>(&::cColliderNodeParam::setDummyU16), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "ColliderType", &mColliderType, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColliderType", &mColliderType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgUseActive", &mFlgUseActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgUsePassive", &mFlgUsePassive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mActiveUseFunctionID", &mActiveUseFunctionID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgUsePush", &mFlgUsePush, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Attribute", &mAttribute, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", &mGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttribute", &mAttribute, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpUserDataPtr", &mpUserDataPtr, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgAutoDeleteUserDataPtr", &mFlgAutoDeleteUserDataPtr, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ColliderType", &mColliderType, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ColliderActive", &mFlgUseActive, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ColliderPassive", &mFlgUsePassive, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ColliderPush", &mFlgUsePush, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Group    ", &mGroup, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Attribute", &mAttribute, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ActiveFunc", &mActiveUseFunctionID, 2u, 0u);
}

static auto ddon_emit_0x01bd70a0 __attribute__((used)) = &cColliderNodeParam::getVersion;

u32 cColliderNodeParam::getColliderGroup() const {
    return mGroup;
}

u32 cColliderNodeParam::getColliderType() const {
    return mColliderType;
}

bool cColliderNodeParam::getFlgUseActive() const {
    return mFlgUseActive;
}

bool cColliderNodeParam::getFlgUsePassive() const {
    return mFlgUsePassive;
}

bool cColliderNodeParam::getFlgUsePush() const {
    return mFlgUsePush;
}

u32 cColliderNodeParam::getAttribute() const {
    return mAttribute;
}

u32 cColliderNodeParam::getActiveUseFunctionID() const {
    return mActiveUseFunctionID;
}

__attribute__((weak)) void cColliderNodeParam::setDummyU16(u16) {
}

inline cColliderNodeParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cColliderNodeParam::MyDTI cColliderNodeParam::DTI("cColliderNodeParam", &::nCollision::cAllocaterIntermediate::DTI, 48ul, 0u, 0u);

MtObject* cColliderNodeParam::MyDTI::newInstance() const {
    return new (16u) cColliderNodeParam;
}

