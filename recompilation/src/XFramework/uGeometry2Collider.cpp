// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGeometry2Collider.h"
#include "../MT/MtCollection.h"
#include "../MT/MtCollision.h"
#include "../MT/MtCollisionUtil.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cColliderParam.h"
#include "cUnit.h"
#include "nCollisionNode.h"
#include "sCollision.h"
#include "sMain.h"
#include "uGeometry2.h"
#include "uGeometry2Base.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uGeometry2Collider::usage() {
}

const MtDTI& uGeometry2Collider::getDTI() const {
    return uGeometry2Collider::DTI;
}

uGeometry2Collider::~uGeometry2Collider() {
    DDON_STUB("uGeometry2Collider::~uGeometry2Collider")
    /* stub */
}

__attribute__((weak)) void uGeometry2Collider::createProperty(MtPropertyList& s) {
    DDON_STUB("uGeometry2Collider::createProperty")
    /* stub */
}

__attribute__((weak)) void uGeometry2Collider::move() {
    DDON_STUB("uGeometry2Collider::move")
    /* stub */
}

__attribute__((weak)) void uGeometry2Collider::registNode2Collider() {
    DDON_STUB("uGeometry2Collider::registNode2Collider")
    /* stub */
}

void uGeometry2Collider::registOwner(uModel* pOwner) {
    mpOwner = pOwner;
}

void uGeometry2Collider::registAttachGeometry(uGeometry2* pGeometry2Unit) {
    mpAttachGeometry = pGeometry2Unit;
    restoreNodeFromGeometry();
}

uGeometry2* uGeometry2Collider::getRegistAttachGeometry() {
    return mpAttachGeometry;
}

__attribute__((weak)) void uGeometry2Collider::restoreNodeFromGeometry() {
    DDON_STUB("uGeometry2Collider::restoreNodeFromGeometry")
    /* stub */
}

__attribute__((weak)) void uGeometry2Collider::callbackColliderSetup() {
    DDON_STUB("uGeometry2Collider::callbackColliderSetup")
    /* stub */
}

__attribute__((weak)) void uGeometry2Collider::callbackColliderCollisionDetect(sCollision::CALLBACK_MODE mode, sCollision::Node* pThisNode, sCollision::Node* pNode, MtContact* pContact, u32 param, sCollision::TriangleInfo* pTriInfo, u32 HitGeomThisID, u32 HitGeomID, bool Hited) {
    DDON_STUB("uGeometry2Collider::callbackColliderCollisionDetect")
    /* stub */
}

inline uGeometry2Collider::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGeometry2Collider::MyDTI uGeometry2Collider::DTI("uGeometry2Collider", &::uGeometry2Base::DTI, 416ul, 0u, 0u);

__attribute__((weak)) MtObject* uGeometry2Collider::MyDTI::newInstance() const {
    DDON_STUB("uGeometry2Collider::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGeometry2Collider::cContactInfo::getDTI() const {
    return uGeometry2Collider::cContactInfo::DTI;
}

uGeometry2Collider::cContactInfo::~cContactInfo() {
}

void uGeometry2Collider::cContactInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpHitActiveNode", reinterpret_cast<MtObject* *>(&mpHitActiveNode), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpHitPassiveNode", reinterpret_cast<MtObject* *>(&mpHitPassiveNode), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHitActiveNodeGeometryIndex", &mHitActiveNodeGeometryIndex, 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHitPassiveNodeGeometryIndex", &mHitPassiveNodeGeometryIndex, 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "pos(X)       ", &mContactResult.pos.x, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "pos(Y)       ", &mContactResult.pos.y, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "pos(Z)       ", &mContactResult.pos.z, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "normal(X)    ", &mContactResult.normal.x, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "normal(Y)    ", &mContactResult.normal.y, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "normal(Z)    ", &mContactResult.normal.z, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "distance     ", &mContactResult.distance, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "toi          ", &mContactResult.toi, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "bFind        ", &mContactResult.bFind, 2u, 0u);
}

inline uGeometry2Collider::cContactInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGeometry2Collider::cContactInfo::MyDTI uGeometry2Collider::cContactInfo::DTI("uGeometry2Collider::cContactInfo", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* uGeometry2Collider::cContactInfo::MyDTI::newInstance() const {
    DDON_STUB("uGeometry2Collider::cContactInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGeometry2Collider::cNodeGeometryInfo::getDTI() const {
    return uGeometry2Collider::cNodeGeometryInfo::DTI;
}

uGeometry2Collider::cNodeGeometryInfo::~cNodeGeometryInfo() {
}

void uGeometry2Collider::cNodeGeometryInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpRegistGeometry", reinterpret_cast<MtObject* *>(&mpRegistGeometry), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRegistGeometryParam", reinterpret_cast<MtObject* *>(&mpRegistGeometryParam), 16u, 0u);
}

inline uGeometry2Collider::cNodeGeometryInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGeometry2Collider::cNodeGeometryInfo::MyDTI uGeometry2Collider::cNodeGeometryInfo::DTI("uGeometry2Collider::cNodeGeometryInfo", &::MtObject::DTI, 88ul, 0u, 0u);

MtObject* uGeometry2Collider::cNodeGeometryInfo::MyDTI::newInstance() const {
    return new (16u) uGeometry2Collider::cNodeGeometryInfo;
}

