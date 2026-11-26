// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uScrollCollisionGeometryModel.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "rGeometry2.h"
#include "sUnit.h"
#include "uGeometry2.h"
#include "uModel.h"
#include "uScrollCollision.h"
#include "uScrollCollisionGeometry.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uScrollCollisionGeometryModel::usage() {
}

const MtDTI& uScrollCollisionGeometryModel::getDTI() const {
    return uScrollCollisionGeometryModel::DTI;
}

inline void* uScrollCollisionGeometryModel::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uScrollCollisionGeometryModel::DTI)->memAlloc(sz, align, uScrollCollisionGeometryModel::DTI.mID);
}

inline void uScrollCollisionGeometryModel::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uScrollCollisionGeometryModel::DTI)->memFree(p_addr);
}

uScrollCollisionGeometryModel::~uScrollCollisionGeometryModel() {
    if (mpScrGeometryUnit_Outside != nullptr) {
        mpScrGeometryUnit_Outside->unregistOwner();
        mpScrGeometryUnit_Outside = nullptr;
    }
    if (mFlgGroupMode) {
        return;
    }
    if (mpRGeometry != nullptr) {
        mpRGeometry->release();
        mpRGeometry = nullptr;
    }
    if (mpGeometryUnit_Inside == nullptr) {
        return;
    }
    delete mpGeometryUnit_Inside;
    mpGeometryUnit_Inside = nullptr;
}

void uScrollCollisionGeometryModel::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\202\242\343\202\257\343\203\206\343\202\243\343\203\226", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::isActiveScrGeometryUnit), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::setActiveScrGeometryUnit), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\346\217\217\347\224\273", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::isDrawScrGeometryUnit), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::setDrawScrGeometryUnit), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\260\343\203\253\343\203\274\343\203\227\343\203\242\343\203\274\343\203\211", &mFlgGroupMode, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\246\252\343\203\246\343\203\213\343\203\203\343\203\210", reinterpret_cast<MtObject* *>(&mpParentGeometryGroup), 17u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\252\343\203\274\343\203\212\343\203\274\347\231\273\351\214\262", &mFlgOwnerRegist, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\270\343\202\252\343\203\241\343\203\210\343\203\252\343\203\252\343\202\275\343\203\274\343\202\271(.geo2)", "resource", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::getRegistResource), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::registResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "\343\202\252\343\203\274\343\203\212\343\203\274\343\203\242\343\203\207\343\203\253(uModel)", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::getOwner), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::registOwner), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\270\343\202\252\343\203\241\343\203\210\343\203\252\343\203\246\343\203\213\343\203\203\343\203\210", reinterpret_cast<MtObject* *>(&mpGeometryUnit_Inside), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\237\272\346\234\254SCR\343\203\246\343\203\213\343\203\203\343\203\210", reinterpret_cast<MtObject* *>(&mpScrGeometryUnit_Outside), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "\345\275\242\347\212\266\346\225\260", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::getScrGeometryNum), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometryModel::setDummyU32), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MT_CTSTR uScrollCollisionGeometryModel::getName() {
    return getDTI().mName;
}

void uScrollCollisionGeometryModel::setup() {
    this->cUnit::setup();
}

void uScrollCollisionGeometryModel::move() {
    if (mpGeometryUnit_Inside != nullptr) {
        mpGeometryUnit_Inside->move();
        if (mpOwnerModel != nullptr) {
            if (!(!mFlgGroupMode && ((mpOwnerModel->mBeFlag & 7u) == 3))) {
                if ((mpOwnerModel->mBeFlag & 7u) == 4) {
                    kill();
                    return;
                } else {
                    bool t0 = mpGeometryUnit_Inside->isGeometryActive();
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpScrGeometryUnit_Outside) + 16) = !t0 ? ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpScrGeometryUnit_Outside) + 16)) & 0xFFFFFBFFu) : ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpScrGeometryUnit_Outside) + 16)) | 1024u);
                    if (t0) {
                        const u32 GeometryNum = mpGeometryUnit_Inside->getGeometryNum();
                        if (GeometryNum != 0) {
                            for (unsigned int i0_3 = 0;;) {
                                MtGeomConvex* t1 = mpGeometryUnit_Inside->getAttachGeometry(i0_3);
                                mpScrGeometryUnit_Outside->getGeometryInfo(i0_3).copyGeomConvex(*t1);
                                if (GeometryNum != (i0_3 + 1u)) {
                                    i0_3 += 1u;
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                }
            } else {
                kill();
                return;
            }
        } else {
            if (!mFlgGroupMode) {
                if (mFlgOwnerRegist) {
                    kill();
                    return;
                }
            }
        }
    }
}

void uScrollCollisionGeometryModel::sync() {
    if (mpGeometryUnit_Inside == nullptr) {
        return;
    }
    mpGeometryUnit_Inside->sync();
}

__attribute__((weak)) void uScrollCollisionGeometryModel::moveAfter() {
}

__attribute__((weak)) bool uScrollCollisionGeometryModel::registResource(rGeometry2* pRGeometry2) {
    DDON_STUB("uScrollCollisionGeometryModel::registResource")
    return {};
}

rGeometry2* uScrollCollisionGeometryModel::getRegistResource() {
    return mpRGeometry;
}

void uScrollCollisionGeometryModel::registOwner(uModel* pOwner) {
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

uModel* uScrollCollisionGeometryModel::getOwner() {
    return mpOwnerModel;
}

bool uScrollCollisionGeometryModel::isActiveScrGeometryUnit() const {
    if (mpGeometryUnit_Inside != nullptr) {
        return mpGeometryUnit_Inside->isGeometryActive();
    } else {
        return false;
    }
}

void uScrollCollisionGeometryModel::setActiveScrGeometryUnit(bool FlgSetActive) {
    if (mpGeometryUnit_Inside == nullptr) {
        return;
    }
    mpGeometryUnit_Inside->setGeometryActive(FlgSetActive);
}

__attribute__((weak)) bool uScrollCollisionGeometryModel::isDrawScrGeometryUnit() const {
    DDON_STUB("uScrollCollisionGeometryModel::isDrawScrGeometryUnit")
    return {};
}

__attribute__((weak)) void uScrollCollisionGeometryModel::setDrawScrGeometryUnit(bool FlgSetDraw) {
    DDON_STUB("uScrollCollisionGeometryModel::setDrawScrGeometryUnit")
    /* stub */
}

u32 uScrollCollisionGeometryModel::getScrGeometryNum() const {
    if (mpScrGeometryUnit_Outside != nullptr) {
        return mpScrGeometryUnit_Outside->getGeometryInfoNum();
    } else {
        return 0;
    }
}

__attribute__((weak)) void uScrollCollisionGeometryModel::registMemberToUnit() {
    DDON_STUB("uScrollCollisionGeometryModel::registMemberToUnit")
    /* stub */
}

__attribute__((weak)) void uScrollCollisionGeometryModel::setDummyU32(u32) {
}

void uScrollCollisionGeometryModel::setGroupGeometry(uModel* pOwnerModel, uScrollCollisionGeometryGroupModel* pParentUnit, uGeometry2* pGroupGeometry) {
    mFlgGroupMode = true;
    mpParentGeometryGroup = pParentUnit;
    mpGeometryUnit_Inside = pGroupGeometry;
    if (pOwnerModel == nullptr) {
        return;
    }
    unsigned int t0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pOwnerModel) + 16);
    u32 t1 = (sUnit::mpInstance)->getMoveLineOrder(mMoveLine);
    if ((sUnit::mpInstance)->getMoveLineOrder(pOwnerModel->mMoveLine) < t1) {
        mFlgOwnerRegist = true;
        mpOwnerModel = pOwnerModel;
        registMemberToUnit();
    }
}

inline uScrollCollisionGeometryModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uScrollCollisionGeometryModel::MyDTI uScrollCollisionGeometryModel::DTI("uScrollCollisionGeometryModel", &::uScrollCollision::DTI, 136ul, 0u, 0u);

MtObject* uScrollCollisionGeometryModel::MyDTI::newInstance() const {
    return new (16u) uScrollCollisionGeometryModel;
}

