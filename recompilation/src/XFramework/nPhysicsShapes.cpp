// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsShapes.h"
#include "nPhysicsMathVector3.h"
#include "nPhysicsShape.h"
#include "nPhysicsStruct.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nPhysics::SHAPES::add(const MtSphere& sphere, const s32 material) {
    u32 t0 = NumShape;
    NumShape = t0 + 1u;
    Shape[t0].set(sphere);
    Shape[t0].MaterialNo = material;
}

void nPhysics::SHAPES::add(const MtCapsule& capsule, const s32 material) {
    u32 t0 = NumShape;
    NumShape = t0 + 1u;
    Shape[t0].set(capsule);
    Shape[t0].MaterialNo = material;
}

void nPhysics::SHAPES::add(const MtCylinder& cylinder, const s32 material) {
    u32 t0 = NumShape;
    NumShape = t0 + 1u;
    Shape[t0].set(cylinder);
    Shape[t0].MaterialNo = material;
}

void nPhysics::SHAPES::add(const MtOBB& obb, const s32 material) {
    u32 t0 = NumShape;
    NumShape = t0 + 1u;
    Shape[t0].set(obb);
    Shape[t0].MaterialNo = material;
}

__attribute__((weak)) nPhysics::SHAPES nPhysics::SHAPES::transform(const nPhysics::Math::Matrix& transform_matrix) const {
    DDON_STUB("nPhysics::SHAPES::transform")
    __builtin_unreachable();
}

__attribute__((weak)) void nPhysics::SHAPES::operator=(const nPhysics::SHAPES& source) {
    DDON_STUB("nPhysics::SHAPES::operator=")
    /* stub */
}

