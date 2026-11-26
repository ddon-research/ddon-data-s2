// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpThinkBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cpComponent.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpThinkBase::getDTI() const {
    return cpThinkBase::DTI;
}

inline void* cpThinkBase::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cpThinkBase::DTI)->memAlloc(sz, align, cpThinkBase::DTI.getID());
}

inline void cpThinkBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cpThinkBase::DTI)->memFree(p_addr);
}

cpThinkBase::cpThinkBase() {
}

cpThinkBase::~cpThinkBase() {
}

f32 cpThinkBase::getAngleY() {
    return 0.0f;
}

f32 cpThinkBase::getAngleYActBegin(u32) {
    return 0.0f;
}

f32 cpThinkBase::getMoveSpeed() {
    return 0.0f;
}

u32 cpThinkBase::getMoveType() {
    return 0;
}

f32 cpThinkBase::getMoveLvLX() {
    return 0.0f;
}

const MtVector3& cpThinkBase::getTargetPos() {
    return MtVector3::Zero;
}

u32 cpThinkBase::getTargetUID() {
    return 0;
}

__attribute__((weak)) void cpThinkBase::setTargetPos(const MtVector3&) {
}

__attribute__((weak)) void cpThinkBase::setTargetUID(u32) {
}

inline cpThinkBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpThinkBase::MyDTI cpThinkBase::DTI("cpThinkBase", &::cpComponent::DTI, 80ul, 0u, 0u);

MtObject* cpThinkBase::MyDTI::newInstance() const {
    return new (16u) cpThinkBase;
}

