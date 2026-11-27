// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uModelEx.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "uCoord.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uActorModel::usage() {
}

const MtDTI& uActorModel::getDTI() const {
    return uActorModel::DTI;
}

uActorModel::uActorModel() {
    DDON_STUB("uActorModel::uActorModel")
    /* stub */
}

uActorModel::~uActorModel() {
    DDON_STUB("uActorModel::~uActorModel")
    /* stub */
}

void uActorModel::createProperty(MtPropertyList& s) {
    this->uModel::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetPos", &mOffsetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetAngle", &mOffsetAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpMontage", "resource", static_cast<void*>(&mpMontage), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMontageNo", &mMontageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConstraint", static_cast<MtObject*>(&mConstraint[0]), 32u, 64u);
}

MtUI* uActorModel::createUI(MtProperty& prop) {
    return this->uModel::createUI(prop);
}

void uActorModel::kill() {
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) != 0) {
        return;
    }
    if ((mBeFlag - 1u) <= 1u) {
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
    }
}

__attribute__((weak)) void uActorModel::move() {
    DDON_STUB("uActorModel::move")
    /* stub */
}

inline uActorModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uActorModel::MyDTI uActorModel::DTI("uActorModel", &::uModel::DTI, 9616ul, 0u, 0u);

__attribute__((weak)) MtObject* uActorModel::MyDTI::newInstance() const {
    DDON_STUB("uActorModel::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uActorModel::Constraint::getDTI() const {
    return uActorModel::Constraint::DTI;
}

__attribute__((weak)) void uActorModel::Constraint::adjust(uModel::Joint* pjnt, uModel* pmod) {
    DDON_STUB("uActorModel::Constraint::adjust")
    /* stub */
}

__attribute__((weak)) void uActorModel::Constraint::setJointNo(u32 no) {
    DDON_STUB("uActorModel::Constraint::setJointNo")
    /* stub */
}

static auto ddon_emit_0x01b633a0 __attribute__((used)) = &uActorModel::Constraint::getJointNo;

void uActorModel::Constraint::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mParentJntNo", &mParentJntNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mJntNo", reinterpret_cast<MT_MFUNC>(&::uActorModel::Constraint::getJointNo), reinterpret_cast<MT_MFUNC>(&::uActorModel::Constraint::setJointNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* uActorModel::Constraint::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline uActorModel::Constraint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uActorModel::Constraint::MyDTI uActorModel::Constraint::DTI("uActorModel::Constraint", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* uActorModel::Constraint::MyDTI::newInstance() const {
    return new (16u) uActorModel::Constraint;
}

