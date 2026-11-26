// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uScrollCollisionGeometryGroupModel.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtCollisionUtil.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "sUnit.h"
#include "uGeometry2Group.h"
#include "uModel.h"
#include "uScrollCollision.h"
#include "uScrollCollisionGeometryModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uScrollCollisionGeometryGroupModel::usage() {
}

const MtDTI& uScrollCollisionGeometryGroupModel::getDTI() const {
    return uScrollCollisionGeometryGroupModel::DTI;
}

inline void uScrollCollisionGeometryGroupModel::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uScrollCollisionGeometryGroupModel::DTI)->memFree(p_addr);
}

__attribute__((noinline)) uScrollCollisionGeometryGroupModel::~uScrollCollisionGeometryGroupModel() {
    DDON_STUB("uScrollCollisionGeometryGroupModel::~uScrollCollisionGeometryGroupModel")
    /* stub */
}

void uScrollCollisionGeometryGroupModel::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\252\343\203\274\343\203\212\343\203\274\347\231\273\351\214\262", &mFlgOwnerRegist, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\270\343\202\252\343\203\241\343\203\210\343\203\252\343\202\260\343\203\253\343\203\274\343\203\227\343\203\252\343\202\275\343\203\274\343\202\271(.geo2g)", "resource", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryGroupModel::getRegistResource), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryGroupModel::registResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "\343\202\252\343\203\274\343\203\212\343\203\274\343\203\242\343\203\207\343\203\253(uModel)", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryGroupModel::getOwner), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryGroupModel::registOwner), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\270\343\202\252\343\203\241\343\203\210\343\203\252\343\202\260\343\203\253\343\203\274\343\203\227\343\203\246\343\203\213\343\203\203\343\203\210", reinterpret_cast<MtObject* *>(&mpGeometryGroupUnit_Inside), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\270\343\202\252\343\203\241\343\203\210\343\203\252\343\203\246\343\203\213\343\203\203\343\203\210\343\203\252\343\202\271\343\203\210", static_cast<MtObject*>(&mGeometryUnitArray), 1u, 0u);
}

MT_CTSTR uScrollCollisionGeometryGroupModel::getName() {
    return getDTI().mName;
}

void uScrollCollisionGeometryGroupModel::setup() {
    this->cUnit::setup();
}

__attribute__((weak)) void uScrollCollisionGeometryGroupModel::move() {
    DDON_STUB("uScrollCollisionGeometryGroupModel::move")
    /* stub */
}

__attribute__((weak)) void uScrollCollisionGeometryGroupModel::sync() {
    DDON_STUB("uScrollCollisionGeometryGroupModel::sync")
    /* stub */
}

__attribute__((weak)) void uScrollCollisionGeometryGroupModel::moveAfter() {
    DDON_STUB("uScrollCollisionGeometryGroupModel::moveAfter")
    /* stub */
}

__attribute__((weak)) bool uScrollCollisionGeometryGroupModel::registResource(rGeometry2Group* pRGeometry2) {
    DDON_STUB("uScrollCollisionGeometryGroupModel::registResource")
    return {};
}

rGeometry2Group* uScrollCollisionGeometryGroupModel::getRegistResource() {
    return mpRGeometryGroup;
}

void uScrollCollisionGeometryGroupModel::registOwner(uModel* pOwner) {
    if (pOwner == nullptr) {
        return;
    }
    unsigned int t0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pOwner) + 16);
    u32 t1 = (sUnit::mpInstance)->getMoveLineOrder(mMoveLine);
    if ((sUnit::mpInstance)->getMoveLineOrder(pOwner->mMoveLine) < t1) {
        mFlgOwnerRegist = true;
        mpOwnerModel = pOwner;
        registMemberToUnit();
    }
}

uModel* uScrollCollisionGeometryGroupModel::getOwner() {
    return mpOwnerModel;
}

__attribute__((weak)) void uScrollCollisionGeometryGroupModel::registMemberToUnit() {
    DDON_STUB("uScrollCollisionGeometryGroupModel::registMemberToUnit")
    /* stub */
}

inline uScrollCollisionGeometryGroupModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uScrollCollisionGeometryGroupModel::MyDTI uScrollCollisionGeometryGroupModel::DTI("uScrollCollisionGeometryGroupModel", &::uScrollCollision::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* uScrollCollisionGeometryGroupModel::MyDTI::newInstance() const {
    DDON_STUB("uScrollCollisionGeometryGroupModel::MyDTI::newInstance")
    return nullptr;
}

