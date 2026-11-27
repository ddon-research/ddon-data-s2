// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsMass.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nPhysics::Mass::getDTI() const {
    return nPhysics::Mass::DTI;
}

nPhysics::Mass::Mass() {
    mMass = 0.0f;
    mInverseMass = 0.0f;
}

void nPhysics::Mass::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mMass", &mMass, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mInverseMass", &mInverseMass, 0u, 0u);
}

__attribute__((weak)) void nPhysics::Mass::add(const f32 mass) {
    DDON_STUB("nPhysics::Mass::add")
    /* stub */
}

f32 nPhysics::Mass::calculate(const MtOBB& obb, const f32 density) {
    return 0.001f * (density * ((obb.extent.z + obb.extent.z) * ((obb.extent.x + obb.extent.x) * (obb.extent.y + obb.extent.y))));
}

f32 nPhysics::Mass::calculate(const MtSphere& sphere, const f32 density) {
    return 0.001f * (density * ((sphere.r * (sphere.r * (sphere.r * 12.566371f))) / 3.0f));
}

__attribute__((weak)) f32 nPhysics::Mass::calculate(const MtCapsule& capsule, const f32 density) {
    DDON_STUB("nPhysics::Mass::calculate")
    return {};
}

__attribute__((weak)) f32 nPhysics::Mass::calculate(const MtCylinder& cylinder, const f32 density) {
    DDON_STUB("nPhysics::Mass::calculate")
    return {};
}

f32 nPhysics::Mass::getMass() const {
    return mMass;
}

f32 nPhysics::Mass::getInverseMass() const {
    return mInverseMass;
}

void nPhysics::Mass::setMass(f32 mass) {
    mMass = mass;
    if (mass != 0.0f) {
        mInverseMass = 1.0f / mass;
    } else {
        mInverseMass = 0.0f;
    }
}

inline nPhysics::Mass::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nPhysics::Mass::MyDTI nPhysics::Mass::DTI("nPhysics::Mass", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* nPhysics::Mass::MyDTI::newInstance() const {
    DDON_STUB("nPhysics::Mass::MyDTI::newInstance")
    return nullptr;
}

