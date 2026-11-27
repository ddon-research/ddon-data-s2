// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cLightVolume.h"
#include "../MT/MtCollision.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtPrimitive3D.h"
#include "cDraw.h"
#include "cUnit.h"
#include "nDrawResource.h"
#include "sRender.h"
#include "sScene.h"
#include "sShader2.h"
#include "uLight.h"
#include "uShadow.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void cLightVolume::draw(cDraw* pdraw, uLight* light) {
    DDON_STUB("cLightVolume::draw")
    /* stub */
}

__attribute__((weak)) cLightVolume* cLightVolume::CreateLightVolume(uLight* light) {
    DDON_STUB("cLightVolume::CreateLightVolume")
    return nullptr;
}

bool cLightVolume::isCulling(cDraw* pdraw, uLight* light) {
    return false;
}

cSphereVolume::cSphereVolume() {
    DDON_STUB("cSphereVolume::cSphereVolume")
    /* stub */
}

const MtMatrix& cSphereVolume::getMatrix() const {
    return mMat;
}

__attribute__((weak)) void cSphereVolume::draw(cDraw* pdraw) const {
    DDON_STUB("cSphereVolume::draw")
    /* stub */
}

bool cSphereVolume::isIntersect(const MtOBB& obb) const {
    return MtCollision::intersect(mSphere, obb);
}

__attribute__((weak)) void cSphereVolume::updateMatrix(const MtVector3& pos, f32 radius) {
    DDON_STUB("cSphereVolume::updateMatrix")
    /* stub */
}

