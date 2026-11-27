// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsRigidBody.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "nPhysicsBase.h"
#include "nPhysicsInertiaTensor.h"
#include "nPhysicsList.h"
#include "nPhysicsMass.h"
#include "nPhysicsPower.h"
#include "nPhysicsShapes.h"
#include "nPhysicsStruct.h"
#include "nPhysicsSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nPhysics::RigidBody::getDTI() const {
    return nPhysics::RigidBody::DTI;
}

void* nPhysics::RigidBody::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nPhysics::RigidBody::DTI)->memAlloc(sz, align, ::nPhysics::RigidBody::DTI.mID);
}

void nPhysics::RigidBody::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nPhysics::RigidBody::DTI)->memFree(p_addr);
}

nPhysics::RigidBody::RigidBody() {
    DDON_STUB("nPhysics::RigidBody::RigidBody")
    /* stub */
}

nPhysics::RigidBody::~RigidBody() {
    DDON_STUB("nPhysics::RigidBody::~RigidBody")
    /* stub */
}

__attribute__((weak)) MtVector3 nPhysics::RigidBody::getPosition() const {
    DDON_STUB("nPhysics::RigidBody::getPosition")
    __builtin_unreachable();
}

__attribute__((weak)) MtQuaternion nPhysics::RigidBody::getRotation() const {
    DDON_STUB("nPhysics::RigidBody::getRotation")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 nPhysics::RigidBody::getLinearVelocity() const {
    DDON_STUB("nPhysics::RigidBody::getLinearVelocity")
    __builtin_unreachable();
}

__attribute__((weak)) void nPhysics::RigidBody::setLinearVelocity(const MtVector3& velocity) {
    DDON_STUB("nPhysics::RigidBody::setLinearVelocity")
    /* stub */
}

__attribute__((weak)) MtVector3 nPhysics::RigidBody::getAngularVelocity() const {
    DDON_STUB("nPhysics::RigidBody::getAngularVelocity")
    __builtin_unreachable();
}

__attribute__((weak)) void nPhysics::RigidBody::setPosture(const MtVector3& position, const MtQuaternion& rotation, const MtVector3& linear_velocity, const MtVector3& angular_velocity) {
    DDON_STUB("nPhysics::RigidBody::setPosture")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::addForcePrivate(const MtVector4& force) {
    DDON_STUB("nPhysics::RigidBody::addForcePrivate")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::addTorquePrivate(const MtVector4& torque) {
    DDON_STUB("nPhysics::RigidBody::addTorquePrivate")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::sleepSystem() {
    DDON_STUB("nPhysics::RigidBody::sleepSystem")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::wakeupSystem() {
    DDON_STUB("nPhysics::RigidBody::wakeupSystem")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::addForce(const MtVector3& force, const MtVector3& position, const f32 time) {
    DDON_STUB("nPhysics::RigidBody::addForce")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::addTorque(const MtVector3& torque, const f32 time) {
    DDON_STUB("nPhysics::RigidBody::addTorque")
    /* stub */
}

__attribute__((weak)) MtVector3 nPhysics::RigidBody::getVelocityOfPosition(const MtVector3& position) const {
    DDON_STUB("nPhysics::RigidBody::getVelocityOfPosition")
    __builtin_unreachable();
}

__attribute__((weak)) void nPhysics::RigidBody::initialize(const nPhysics::RigidBody::INITIALIZER& initializer) {
    DDON_STUB("nPhysics::RigidBody::initialize")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::clear() {
    DDON_STUB("nPhysics::RigidBody::clear")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::sleep() {
    DDON_STUB("nPhysics::RigidBody::sleep")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::wakeup() {
    DDON_STUB("nPhysics::RigidBody::wakeup")
    /* stub */
}

void nPhysics::RigidBody::destroy() {
    nPhysics::RIGID_BODY_STATUS* t0 = mStatus;
    if ((t0->CurrentStatus & 0x800000u) != 0) {
        if ((t0->Status & 0x800000u) != 0) {
            t0->AddState = t0->AddState & 0xFF7FFFFFu;
            t0->RemoveState = t0->RemoveState | 0x800000u;
            t0->CurrentStatus = t0->CurrentStatus & 0xFF7FFFFFu;
            (::nPhysics::System::mInstance)->::nPhysics::System::enable_rigid_body(this);
        }
    }
    (::nPhysics::System::mInstance)->::nPhysics::System::removeRigidBody(this);
}

void nPhysics::RigidBody::enable() {
    nPhysics::RIGID_BODY_STATUS* t0 = mStatus;
    if ((t0->CurrentStatus & 0x800000u) == 0) {
        return;
    }
    if ((t0->Status & 0x800000u) == 0) {
        return;
    }
    t0->AddState = t0->AddState & 0xFF7FFFFFu;
    t0->RemoveState = t0->RemoveState | 0x800000u;
    t0->CurrentStatus = t0->CurrentStatus & 0xFF7FFFFFu;
    (::nPhysics::System::mInstance)->::nPhysics::System::enable_rigid_body(this);
}

void nPhysics::RigidBody::disable() {
    nPhysics::RIGID_BODY_STATUS* t0 = mStatus;
    if ((t0->CurrentStatus & 0x800000u) != 0) {
        return;
    }
    if ((t0->Status & 0x800000u) == 0) {
        t0->AddState = t0->AddState | 0x800000u;
        t0->RemoveState = t0->RemoveState & 0xFF7FFFFFu;
        t0->CurrentStatus = t0->CurrentStatus | 0x800000u;
        (::nPhysics::System::mInstance)->::nPhysics::System::disable_rigid_body(this);
    }
}

void nPhysics::RigidBody::setID(const u32 id) {
    mID = id;
    mCurrentData = &(::nPhysics::System::mInstance)->mCurrentRigidBodyData[id];
    mPreviousData = &(::nPhysics::System::mInstance)->mPreservedRigidBodyData[id * 2u];
    mNextData = &(::nPhysics::System::mInstance)->mPreservedRigidBodyData[(id * 2u) | 1u];
    mInterpolationData = &(::nPhysics::System::mInstance)->mInterpolationRigidBodyData[id];
    mShapes = &(::nPhysics::System::mInstance)->mRigidBodyShapes[id];
    mTransformedShapes = &(::nPhysics::System::mInstance)->mTransformedRigidBodyShapes[id];
    mPower = &(::nPhysics::System::mInstance)->mRigidBodyPower[id];
    mInformation = &(::nPhysics::System::mInstance)->mRigidBodyInformation[id];
    mStatus = &(::nPhysics::System::mInstance)->mRigidBodyStatus[id];
    mCollisionInformation = &(::nPhysics::System::mInstance)->mCollisionInformation[id];
}

inline nPhysics::RigidBody::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nPhysics::RigidBody::MyDTI nPhysics::RigidBody::DTI("nPhysics::RigidBody", &::nPhysics::Base::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* nPhysics::RigidBody::MyDTI::newInstance() const {
    DDON_STUB("nPhysics::RigidBody::MyDTI::newInstance")
    return nullptr;
}

nPhysics::RigidBody::INITIALIZER::INITIALIZER() {
    DDON_STUB("nPhysics::RigidBody::INITIALIZER::INITIALIZER")
    /* stub */
}

nPhysics::RigidBody::INITIALIZER::~INITIALIZER() {
}

__attribute__((weak)) void nPhysics::RigidBody::INITIALIZER::add_shape(const MtSphere& sphere, const f32 density, const s32 material_no, const u32 flag) {
    DDON_STUB("nPhysics::RigidBody::INITIALIZER::add_shape")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::INITIALIZER::add_shape(const MtCapsule& capsule, const f32 density, const s32 material_no, const u32 flag) {
    DDON_STUB("nPhysics::RigidBody::INITIALIZER::add_shape")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::INITIALIZER::add_shape(const MtCylinder& cylinder, const f32 density, const s32 material_no, const u32 flag) {
    DDON_STUB("nPhysics::RigidBody::INITIALIZER::add_shape")
    /* stub */
}

__attribute__((weak)) void nPhysics::RigidBody::INITIALIZER::add_shape(const MtOBB& obb, const f32 density, const s32 material_no, const u32 flag) {
    DDON_STUB("nPhysics::RigidBody::INITIALIZER::add_shape")
    /* stub */
}

