// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsInertiaTensor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "nPhysicsSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nPhysics::InertiaTensor::getDTI() const {
    return nPhysics::InertiaTensor::DTI;
}

nPhysics::InertiaTensor::InertiaTensor() {
    mBasic.m[0].x = ::MtMatrix::Zero.m[0].x;
    mBasic.m[0].y = ::MtMatrix::Zero.m[0].y;
    mBasic.m[0].z = ::MtMatrix::Zero.m[0].z;
    mBasic.m[0].w = ::MtMatrix::Zero.m[0].w;
    mBasic.m[1].x = ::MtMatrix::Zero.m[1].x;
    mBasic.m[1].y = ::MtMatrix::Zero.m[1].y;
    mBasic.m[1].z = ::MtMatrix::Zero.m[1].z;
    mBasic.m[1].w = ::MtMatrix::Zero.m[1].w;
    mBasic.m[2].x = ::MtMatrix::Zero.m[2].x;
    mBasic.m[2].y = ::MtMatrix::Zero.m[2].y;
    mBasic.m[2].z = ::MtMatrix::Zero.m[2].z;
    mBasic.m[2].w = ::MtMatrix::Zero.m[2].w;
    mBasic.m[3].x = ::MtMatrix::Zero.m[3].x;
    mBasic.m[3].y = ::MtMatrix::Zero.m[3].y;
    mBasic.m[3].z = ::MtMatrix::Zero.m[3].z;
    mBasic.m[3].w = ::MtMatrix::Zero.m[3].w;
    mCurrentInverse.m[0].x = ::MtMatrix::Zero.m[0].x;
    mCurrentInverse.m[0].y = ::MtMatrix::Zero.m[0].y;
    mCurrentInverse.m[0].z = ::MtMatrix::Zero.m[0].z;
    mCurrentInverse.m[0].w = ::MtMatrix::Zero.m[0].w;
    mCurrentInverse.m[1].x = ::MtMatrix::Zero.m[1].x;
    mCurrentInverse.m[1].y = ::MtMatrix::Zero.m[1].y;
    mCurrentInverse.m[1].z = ::MtMatrix::Zero.m[1].z;
    mCurrentInverse.m[1].w = ::MtMatrix::Zero.m[1].w;
    mCurrentInverse.m[2].x = ::MtMatrix::Zero.m[2].x;
    mCurrentInverse.m[2].y = ::MtMatrix::Zero.m[2].y;
    mCurrentInverse.m[2].z = ::MtMatrix::Zero.m[2].z;
    mCurrentInverse.m[2].w = ::MtMatrix::Zero.m[2].w;
    mCurrentInverse.m[3].x = ::MtMatrix::Zero.m[3].x;
    mCurrentInverse.m[3].y = ::MtMatrix::Zero.m[3].y;
    mCurrentInverse.m[3].z = ::MtMatrix::Zero.m[3].z;
    mCurrentInverse.m[3].w = ::MtMatrix::Zero.m[3].w;
    mCurrent.m[0].x = ::MtMatrix::Zero.m[0].x;
    mCurrent.m[0].y = ::MtMatrix::Zero.m[0].y;
    mCurrent.m[0].z = ::MtMatrix::Zero.m[0].z;
    mCurrent.m[0].w = ::MtMatrix::Zero.m[0].w;
    mCurrent.m[1].x = ::MtMatrix::Zero.m[1].x;
    mCurrent.m[1].y = ::MtMatrix::Zero.m[1].y;
    mCurrent.m[1].z = ::MtMatrix::Zero.m[1].z;
    mCurrent.m[1].w = ::MtMatrix::Zero.m[1].w;
    mCurrent.m[2].x = ::MtMatrix::Zero.m[2].x;
    mCurrent.m[2].y = ::MtMatrix::Zero.m[2].y;
    mCurrent.m[2].z = ::MtMatrix::Zero.m[2].z;
    mCurrent.m[2].w = ::MtMatrix::Zero.m[2].w;
    mCurrent.m[3].x = ::MtMatrix::Zero.m[3].x;
    mCurrent.m[3].y = ::MtMatrix::Zero.m[3].y;
    mCurrent.m[3].z = ::MtMatrix::Zero.m[3].z;
    mCurrent.m[3].w = ::MtMatrix::Zero.m[3].w;
    mCurrentInverse.m[0].x = ::MtMatrix::Zero.m[0].x;
    mCurrentInverse.m[0].y = ::MtMatrix::Zero.m[0].y;
    mCurrentInverse.m[0].z = ::MtMatrix::Zero.m[0].z;
    mCurrentInverse.m[0].w = ::MtMatrix::Zero.m[0].w;
    mCurrentInverse.m[1].x = ::MtMatrix::Zero.m[1].x;
    mCurrentInverse.m[1].y = ::MtMatrix::Zero.m[1].y;
    mCurrentInverse.m[1].z = ::MtMatrix::Zero.m[1].z;
    mCurrentInverse.m[1].w = ::MtMatrix::Zero.m[1].w;
    mCurrentInverse.m[2].x = ::MtMatrix::Zero.m[2].x;
    mCurrentInverse.m[2].y = ::MtMatrix::Zero.m[2].y;
    mCurrentInverse.m[2].z = ::MtMatrix::Zero.m[2].z;
    mCurrentInverse.m[2].w = ::MtMatrix::Zero.m[2].w;
    mCurrentInverse.m[3].x = ::MtMatrix::Zero.m[3].x;
    mCurrentInverse.m[3].y = ::MtMatrix::Zero.m[3].y;
    mCurrentInverse.m[3].z = ::MtMatrix::Zero.m[3].z;
    mCurrentInverse.m[3].w = ::MtMatrix::Zero.m[3].w;
}

void nPhysics::InertiaTensor::setInertiaTensor(const MtMatrix& inertia_tensor) {
    mBasic.m[0].x = inertia_tensor.m[0].x;
    mBasic.m[0].y = inertia_tensor.m[0].y;
    mBasic.m[0].z = inertia_tensor.m[0].z;
    mBasic.m[0].w = inertia_tensor.m[0].w;
    mBasic.m[1].x = inertia_tensor.m[1].x;
    mBasic.m[1].y = inertia_tensor.m[1].y;
    mBasic.m[1].z = inertia_tensor.m[1].z;
    mBasic.m[1].w = inertia_tensor.m[1].w;
    mBasic.m[2].x = inertia_tensor.m[2].x;
    mBasic.m[2].y = inertia_tensor.m[2].y;
    mBasic.m[2].z = inertia_tensor.m[2].z;
    mBasic.m[2].w = inertia_tensor.m[2].w;
    mBasic.m[3].x = inertia_tensor.m[3].x;
    mBasic.m[3].y = inertia_tensor.m[3].y;
    mBasic.m[3].z = inertia_tensor.m[3].z;
    mBasic.m[3].w = inertia_tensor.m[3].w;
    mBasic.m[3].x = ::MtVector4::AxisW.x;
    mBasic.m[3].y = ::MtVector4::AxisW.y;
    mBasic.m[3].z = ::MtVector4::AxisW.z;
    mBasic.m[3].w = ::MtVector4::AxisW.w;
    MtMatrix frame104(mBasic.inverse());
    mBasicInverse.m[0].x = frame104.m[0].x;
    mBasicInverse.m[0].y = frame104.m[0].y;
    mBasicInverse.m[0].z = frame104.m[0].z;
    mBasicInverse.m[0].w = frame104.m[0].w;
    mBasicInverse.m[1].x = frame104.m[1].x;
    mBasicInverse.m[1].y = frame104.m[1].y;
    mBasicInverse.m[1].z = frame104.m[1].z;
    mBasicInverse.m[1].w = frame104.m[1].w;
    mBasicInverse.m[2].x = frame104.m[2].x;
    mBasicInverse.m[2].y = frame104.m[2].y;
    mBasicInverse.m[2].z = frame104.m[2].z;
    mBasicInverse.m[2].w = frame104.m[2].w;
    mBasicInverse.m[3].x = frame104.m[3].x;
    mBasicInverse.m[3].y = frame104.m[3].y;
    mBasicInverse.m[3].z = frame104.m[3].z;
    mBasicInverse.m[3].w = frame104.m[3].w;
    update(::MtQuaternion::Identity);
}

__attribute__((weak)) void nPhysics::InertiaTensor::update(const MtQuaternion& rotation) {
    DDON_STUB("nPhysics::InertiaTensor::update")
    /* stub */
}

__attribute__((weak)) void nPhysics::InertiaTensor::add(const MtMatrix& inertia_tensor) {
    DDON_STUB("nPhysics::InertiaTensor::add")
    /* stub */
}

__attribute__((weak)) MtMatrix nPhysics::InertiaTensor::calculate(const MtOBB& obb, const f32 mass) {
    DDON_STUB("nPhysics::InertiaTensor::calculate")
    __builtin_unreachable();
}

__attribute__((weak)) MtMatrix nPhysics::InertiaTensor::calculate(const MtSphere& sphere, const f32 mass) {
    DDON_STUB("nPhysics::InertiaTensor::calculate")
    __builtin_unreachable();
}

__attribute__((weak)) MtMatrix nPhysics::InertiaTensor::calculate(const MtCapsule& capsule, const f32 mass) {
    DDON_STUB("nPhysics::InertiaTensor::calculate")
    __builtin_unreachable();
}

__attribute__((weak)) MtMatrix nPhysics::InertiaTensor::calculate(const MtCylinder& cylinder, const f32 mass) {
    DDON_STUB("nPhysics::InertiaTensor::calculate")
    __builtin_unreachable();
}

inline nPhysics::InertiaTensor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nPhysics::InertiaTensor::MyDTI nPhysics::InertiaTensor::DTI("nPhysics::InertiaTensor", &::MtObject::DTI, 272ul, 0u, 0u);

MtObject* nPhysics::InertiaTensor::MyDTI::newInstance() const {
    return new (16u) ::nPhysics::InertiaTensor;
}

