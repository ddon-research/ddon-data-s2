// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGeometry2GroupCollider.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollision.h"
#include "../MT/MtCollisionUtil.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cUnit.h"
#include "nCollision.h"
#include "sCollision.h"
#include "uGeometry2Base.h"
#include "uGeometry2Collider.h"
#include "uGeometry2Group.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uGeometry2GroupCollider::usage() {
}

const MtDTI& uGeometry2GroupCollider::getDTI() const {
    return uGeometry2GroupCollider::DTI;
}

inline void uGeometry2GroupCollider::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGeometry2GroupCollider::DTI)->memFree(p_addr);
}

uGeometry2GroupCollider::uGeometry2GroupCollider() {
    DDON_STUB("uGeometry2GroupCollider::uGeometry2GroupCollider")
    /* stub */
}

uGeometry2GroupCollider::~uGeometry2GroupCollider() {
}

void uGeometry2GroupCollider::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mOwnerSystem", static_cast<MtObject*>(&mOwnerSystem), 4u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpGeometryGroupUnit", reinterpret_cast<MT_MFUNC>(&::uGeometry2GroupCollider::getRegistGeometryGroupUnit), reinterpret_cast<MT_MFUNC>(&::uGeometry2GroupCollider::registGeometryGroupUnit), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mFlgRegistCollider", &mFlgRegistCollider, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNodeArray", static_cast<MtObject*>(&mNodeArray), 2u, 0u);
}

MT_CTSTR uGeometry2GroupCollider::getName() {
    return uGeometry2GroupCollider::DTI.mName;
}

void uGeometry2GroupCollider::setup() {
    this->cUnit::setup();
}

__attribute__((weak)) void uGeometry2GroupCollider::move() {
    DDON_STUB("uGeometry2GroupCollider::move")
    /* stub */
}

__attribute__((weak)) void uGeometry2GroupCollider::sync() {
}

__attribute__((weak)) void uGeometry2GroupCollider::moveAfter() {
}

__attribute__((weak)) void uGeometry2GroupCollider::draw(cDraw* pdraw) {
    DDON_STUB("uGeometry2GroupCollider::draw")
    /* stub */
}

void uGeometry2GroupCollider::registGeometryGroupUnit(uGeometry2Group* pGeometryGroup) {
    if (pGeometryGroup != mpGeometryGroupUnit) {
        mpGeometryGroupUnit = pGeometryGroup;
        restoreNodeFromGeometry();
        MtObject* v0_11 = mOwnerSystem.getRegistOwner();
        u32 v0_10 = mNodeArray.mLength;
        if (v0_10 != 0) {
            for (unsigned int i0_3 = 0;;) {
                if (mNodeArray.mpArray[i0_3] != nullptr) {
                    static_cast<uGeometry2Collider*>(mNodeArray.mpArray[i0_3])->registOwner(static_cast<uModel*>(v0_11));
                }
                if (v0_10 != (i0_3 + 1u)) {
                    i0_3 = i0_3 + 1u;
                } else {
                    break;
                }
            }
        }
    }
}

uGeometry2Group* uGeometry2GroupCollider::getRegistGeometryGroupUnit() const {
    return mpGeometryGroupUnit;
}

__attribute__((weak)) void uGeometry2GroupCollider::restoreNodeFromGeometry() {
    DDON_STUB("uGeometry2GroupCollider::restoreNodeFromGeometry")
    /* stub */
}

inline uGeometry2GroupCollider::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGeometry2GroupCollider::MyDTI uGeometry2GroupCollider::DTI("uGeometry2GroupCollider", &::uGeometry2Base::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* uGeometry2GroupCollider::MyDTI::newInstance() const {
    DDON_STUB("uGeometry2GroupCollider::MyDTI::newInstance")
    return nullptr;
}

