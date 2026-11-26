// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uScrollCollisionGeometry.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtGeomAABB.h"
#include "../MT/MtGeomCapsule.h"
#include "../MT/MtGeomOBB.h"
#include "../MT/MtGeomSphere.h"
#include "../MT/MtGeomTriangle.h"
#include "../MT/MtGeometry3D.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "nCollision.h"
#include "rCollision.h"
#include "rGeometry2.h"
#include "rGeometry3.h"
#include "sCollision.h"
#include "uCoord.h"
#include "uScrollCollision.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uScrollCollisionGeometry::usage() {
}

const MtDTI& uScrollCollisionGeometry::getDTI() const {
    return uScrollCollisionGeometry::DTI;
}

void* uScrollCollisionGeometry::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uScrollCollisionGeometry::DTI)->memAlloc(sz, align, uScrollCollisionGeometry::DTI.mID);
}

inline void uScrollCollisionGeometry::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uScrollCollisionGeometry::DTI)->memFree(p_addr);
}

uScrollCollisionGeometry::uScrollCollisionGeometry() {
    DDON_STUB("uScrollCollisionGeometry::uScrollCollisionGeometry")
    /* stub */
}

__attribute__((noinline)) uScrollCollisionGeometry::~uScrollCollisionGeometry() {
    DDON_STUB("uScrollCollisionGeometry::~uScrollCollisionGeometry")
    /* stub */
}

void uScrollCollisionGeometry::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgEnableOwner", &mFlgEnableOwner, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpOwner", &mpOwner, 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpPlusData", &mpPlusData, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgAlwayUpdate", &mFlgAlwayUpdate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgUpdateOnce", &mFlgUpdateOnce, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgStopSet", &mFlgStopSet, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgStopSetControl", &mFlgStopSetControl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColliderGeometryArray", static_cast<MtObject*>(&mColliderGeometryArray), 0u, 0u);
    mScrFilter.createPropertySupport(s, static_cast<MtObject*>(this), "ScrollType", "ScrollGroup", "ScrollGroupIndex");
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ScrollType(Bit)", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::getScrType), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::setScrType), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "MatrixReset", static_cast<MT_MFUNC>(&::uScrollCollisionGeometry::resetScrMoveMatrix), 10u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mFlgAutoSync", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::isEnableAutoSync), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::setEnableAutoSync), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mFlgAutoSyncEnableMove", &mFlgAutoSyncEnableMove, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgReserveMatrixSet", &mFlgReserveMatrixSet, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgReserveResetSet", &mFlgReserveResetSet, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReserveMatrix", &mReserveMatrix, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_MATRIX, "MoveMatrix", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::getMatrixForUI), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::setScrMoveMatrixForUI), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mScrMatrix", static_cast<MtObject*>(&mScrMatrix), 0u, 0u);
}

void uScrollCollisionGeometry::setup() {
    mpScrollRegisterInfo = (sCollision::mpInstance)->sCollision::registerScrollCollisionNode(*this);
    updateBoundingAABB();
}

__attribute__((weak)) void uScrollCollisionGeometry::draw(cDraw* pdraw) {
}

__attribute__((weak)) void uScrollCollisionGeometry::kill() {
    DDON_STUB("uScrollCollisionGeometry::kill")
    /* stub */
}

__attribute__((weak)) void uScrollCollisionGeometry::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uScrollCollisionGeometry::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) MtGeomConvex* uScrollCollisionGeometry::getGeometry(u32 GeometryIndex) {
    DDON_STUB("uScrollCollisionGeometry::getGeometry")
    return nullptr;
}

__attribute__((weak)) const MtGeomConvex* uScrollCollisionGeometry::getGeometryConst(u32 GeometryIndex) const {
    DDON_STUB("uScrollCollisionGeometry::getGeometryConst")
    return nullptr;
}

__attribute__((weak)) const MtAABB* uScrollCollisionGeometry::getGeometryBoundingAABBConst(u32 GeometryIndex) const {
    DDON_STUB("uScrollCollisionGeometry::getGeometryBoundingAABBConst")
    return nullptr;
}

__attribute__((weak)) uScrollCollisionGeometry::cGeometryInfo& uScrollCollisionGeometry::getGeometryInfo(u32 GeometryIndex) {
    DDON_STUB("uScrollCollisionGeometry::getGeometryInfo")
    __builtin_unreachable();
}

__attribute__((weak)) const uScrollCollisionGeometry::cGeometryInfo& uScrollCollisionGeometry::getGeometryInfoConst(u32 GeometryIndex) const {
    DDON_STUB("uScrollCollisionGeometry::getGeometryInfoConst")
    __builtin_unreachable();
}

bool uScrollCollisionGeometry::isGeometryActive(u32 GeometryIndex) const {
    if (GeometryIndex < mColliderGeometryArray.mLength) {
        return (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mColliderGeometryArray.mpArray[GeometryIndex]) + 96)) != 0;
    } else {
        return false;
    }
}

u32 uScrollCollisionGeometry::getGeometryInfoNum() const {
    return mColliderGeometryArray.mLength;
}

__attribute__((weak)) void uScrollCollisionGeometry::setGeometryInfoNum(u32 NewGeometryNum) {
    DDON_STUB("uScrollCollisionGeometry::setGeometryInfoNum")
    /* stub */
}

__attribute__((weak)) rCollision::MaterialInfo* uScrollCollisionGeometry::getGeometryMaterial(u32 GeometryIndex) {
    DDON_STUB("uScrollCollisionGeometry::getGeometryMaterial")
    return nullptr;
}

bool uScrollCollisionGeometry::isMoveByScrMatrix() {
    return mScrMatrix.mFlgMoveEnable;
}

bool uScrollCollisionGeometry::isResetSetByScrMatrix() {
    return mScrMatrix.mFlgMatResetSet;
}

void uScrollCollisionGeometry::setEnableStopSetControl(bool FlgStopSetControl) {
    mFlgStopSetControl = FlgStopSetControl;
}

__attribute__((weak)) void uScrollCollisionGeometry::setScrMoveMatrix(const MtMatrix& MoveMatrix, bool FlgStopSet) {
    DDON_STUB("uScrollCollisionGeometry::setScrMoveMatrix")
    /* stub */
}

__attribute__((weak)) void uScrollCollisionGeometry::setScrMoveMatrixForUI(const MtMatrix& MoveMatrix) {
    DDON_STUB("uScrollCollisionGeometry::setScrMoveMatrixForUI")
    /* stub */
}

__attribute__((weak)) MtMatrix uScrollCollisionGeometry::getMatrixForUI() {
    DDON_STUB("uScrollCollisionGeometry::getMatrixForUI")
    __builtin_unreachable();
}

void uScrollCollisionGeometry::resetScrMoveMatrix() {
    mScrMatrix.setMatrixForGame(static_cast<const MtMatrix*>(nullptr), true, true);
}

void uScrollCollisionGeometry::setScrFilter(const nCollision::cScrCommonFilter& ScrFilter) {
    mScrFilter = ScrFilter;
}

u32 uScrollCollisionGeometry::getScrType() {
    return mScrFilter.mScrType;
}

void uScrollCollisionGeometry::setScrType(u32 type) {
    mScrFilter.mScrType = type;
}

u8 uScrollCollisionGeometry::getScrGroupIndex() {
    return mScrFilter.mScrGroupIndex;
}

bool uScrollCollisionGeometry::isScrTarget(u32 TargetType, u32 TargetGroup) {
    if ((TargetType & mScrFilter.mScrType) != 0) {
        return (TargetGroup & mScrFilter.mScrGroup) != 0;
    } else {
        return false;
    }
}

__attribute__((weak)) void uScrollCollisionGeometry::registOwner(MtObject* pOwner) {
    DDON_STUB("uScrollCollisionGeometry::registOwner")
    /* stub */
}

void uScrollCollisionGeometry::unregistOwner() {
    mpOwner = nullptr;
}

MtObject* uScrollCollisionGeometry::getOwner() {
    return mpOwner;
}

const MtAABB& uScrollCollisionGeometry::getBoundingAABB() {
    return mBoundingAABB;
}

__attribute__((weak)) void uScrollCollisionGeometry::updateBoundingAABB() {
    DDON_STUB("uScrollCollisionGeometry::updateBoundingAABB")
    /* stub */
}

bool uScrollCollisionGeometry::isEnableAutoSync() {
    return mFlgAutoSync;
}

__attribute__((weak)) void uScrollCollisionGeometry::setEnableAutoSync(bool FlgEnableSet) {
    DDON_STUB("uScrollCollisionGeometry::setEnableAutoSync")
    /* stub */
}

void uScrollCollisionGeometry::setEnableAutoSyncMove(bool FlgEnableSet) {
    mFlgAutoSyncEnableMove = FlgEnableSet;
}

void uScrollCollisionGeometry::moveForSystem() {
    if ((mBeFlag - 1u) <= 1u) {
        if (mFlgEnableOwner) {
            if (mpOwner != nullptr) {
                if (mFlgOwnerUnit) {
                    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpOwner) + 16)) & 7u) - 3u) <= 1u) {
                        kill();
                    } else {
                        syncOwner();
                        if (!mFlgUpdateOnce) {
                            if (mFlgAlwayUpdate) {
                                if (mFlgReserveMatrixSet) {
                                    const u32 MoveCode = mScrMatrix.setMatrixForGame(&mReserveMatrix, mFlgReserveResetSet, mFlgStopSetControl);
                                    mFlgStopSet = mFlgReserveResetSet;
                                    mFlgReserveMatrixSet = false;
                                    updateBoundingAABB();
                                    (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, MoveCode);
                                } else {
                                    updateBoundingAABB();
                                    (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, 0u);
                                }
                                mFlgUpdateOnce = false;
                            }
                        } else {
                            if (mFlgReserveMatrixSet) {
                                const u32 MoveCode = mScrMatrix.setMatrixForGame(&mReserveMatrix, mFlgReserveResetSet, mFlgStopSetControl);
                                mFlgStopSet = mFlgReserveResetSet;
                                mFlgReserveMatrixSet = false;
                                updateBoundingAABB();
                                (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, MoveCode);
                            } else {
                                updateBoundingAABB();
                                (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, 0u);
                            }
                            mFlgUpdateOnce = false;
                        }
                    }
                } else {
                    syncOwner();
                    if (!mFlgUpdateOnce) {
                        if (mFlgAlwayUpdate) {
                            if (mFlgReserveMatrixSet) {
                                const u32 MoveCode = mScrMatrix.setMatrixForGame(&mReserveMatrix, mFlgReserveResetSet, mFlgStopSetControl);
                                mFlgStopSet = mFlgReserveResetSet;
                                mFlgReserveMatrixSet = false;
                                updateBoundingAABB();
                                (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, MoveCode);
                            } else {
                                updateBoundingAABB();
                                (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, 0u);
                            }
                            mFlgUpdateOnce = false;
                        }
                    } else {
                        if (mFlgReserveMatrixSet) {
                            const u32 MoveCode = mScrMatrix.setMatrixForGame(&mReserveMatrix, mFlgReserveResetSet, mFlgStopSetControl);
                            mFlgStopSet = mFlgReserveResetSet;
                            mFlgReserveMatrixSet = false;
                            updateBoundingAABB();
                            (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, MoveCode);
                        } else {
                            updateBoundingAABB();
                            (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, 0u);
                        }
                        mFlgUpdateOnce = false;
                    }
                }
            } else {
                kill();
            }
        } else {
            syncOwner();
            if (!mFlgUpdateOnce) {
                if (mFlgAlwayUpdate) {
                    if (mFlgReserveMatrixSet) {
                        const u32 MoveCode = mScrMatrix.setMatrixForGame(&mReserveMatrix, mFlgReserveResetSet, mFlgStopSetControl);
                        mFlgStopSet = mFlgReserveResetSet;
                        mFlgReserveMatrixSet = false;
                        updateBoundingAABB();
                        (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, MoveCode);
                    } else {
                        updateBoundingAABB();
                        (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, 0u);
                    }
                    mFlgUpdateOnce = false;
                }
            } else {
                if (mFlgReserveMatrixSet) {
                    const u32 MoveCode = mScrMatrix.setMatrixForGame(&mReserveMatrix, mFlgReserveResetSet, mFlgStopSetControl);
                    mFlgStopSet = mFlgReserveResetSet;
                    mFlgReserveMatrixSet = false;
                    updateBoundingAABB();
                    (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, MoveCode);
                } else {
                    updateBoundingAABB();
                    (sCollision::mpInstance)->sCollision::updateScrollCollisionNode(*mpScrollRegisterInfo, 0u);
                }
                mFlgUpdateOnce = false;
            }
        }
    }
}

__attribute__((weak)) void uScrollCollisionGeometry::syncOwner() {
    DDON_STUB("uScrollCollisionGeometry::syncOwner")
    /* stub */
}

__attribute__((weak)) void uScrollCollisionGeometry::applyWorldOffsetByAbsoluteWithGeometry2(const MtVector3& absolute_offset) {
    DDON_STUB("uScrollCollisionGeometry::applyWorldOffsetByAbsoluteWithGeometry2")
    /* stub */
}

__attribute__((weak)) void uScrollCollisionGeometry::applyWorldOffsetByAbsoluteWithGeometry3(const MtVector3& absolute_offset) {
    DDON_STUB("uScrollCollisionGeometry::applyWorldOffsetByAbsoluteWithGeometry3")
    /* stub */
}

inline uScrollCollisionGeometry::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uScrollCollisionGeometry::MyDTI uScrollCollisionGeometry::DTI("uScrollCollisionGeometry", &::uScrollCollision::DTI, 368ul, 0u, 0u);

__attribute__((weak)) MtObject* uScrollCollisionGeometry::MyDTI::newInstance() const {
    DDON_STUB("uScrollCollisionGeometry::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uScrollCollisionGeometry::cGeometryInfo::getDTI() const {
    return uScrollCollisionGeometry::cGeometryInfo::DTI;
}

uScrollCollisionGeometry::cGeometryInfo::~cGeometryInfo() {
    if (mpGeomConvex == nullptr) {
        return;
    }
    delete mpGeomConvex;
    mpGeomConvex = nullptr;
}

void uScrollCollisionGeometry::cGeometryInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpOwner", reinterpret_cast<MtObject* *>(&mpOwner), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mElementIndex", &mElementIndex, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Type", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::cGeometryInfo::getGeomConvexType), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::cGeometryInfo::setGeomConvexType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Active", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::cGeometryInfo::isActive), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::cGeometryInfo::setActive), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "Geometry", reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::cGeometryInfo::getGeomConvex), reinterpret_cast<MT_MFUNC>(&::uScrollCollisionGeometry::cGeometryInfo::setGeomConvex), 132u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Attribute", &mGeomMaterialInfo.attribute, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "UserAttr0", &mGeomMaterialInfo.attr[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "UserAttr1", &mGeomMaterialInfo.attr[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "UserAttr2", &mGeomMaterialInfo.attr[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "UserAttr3", &mGeomMaterialInfo.attr[3], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Attribute(List)", &mGeomMaterialInfo.attribute, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "UserAttr0(List)", &mGeomMaterialInfo.attr[0], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "UserAttr1(List)", &mGeomMaterialInfo.attr[1], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "UserAttr2(List)", &mGeomMaterialInfo.attr[2], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "UserAttr3(List)", &mGeomMaterialInfo.attr[3], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpOwner", reinterpret_cast<MtObject* *>(&mpOwner), 0u, 0u);
}

__attribute__((weak)) void uScrollCollisionGeometry::cGeometryInfo::setGeomConvexType(u32 GeometryType) {
    DDON_STUB("uScrollCollisionGeometry::cGeometryInfo::setGeomConvexType")
    /* stub */
}

u32 uScrollCollisionGeometry::cGeometryInfo::getGeomConvexType() const {
    return mpGeomConvex->mType;
}

MtGeomConvex* uScrollCollisionGeometry::cGeometryInfo::getGeomConvex() {
    return mpGeomConvex;
}

__attribute__((weak)) void uScrollCollisionGeometry::cGeometryInfo::setGeomConvex(MtGeomConvex* pNewGeomConvex) {
    DDON_STUB("uScrollCollisionGeometry::cGeometryInfo::setGeomConvex")
    /* stub */
}

void uScrollCollisionGeometry::cGeometryInfo::copyGeomConvex(MtGeomConvex& NewGeomConvex) {
    setGeomConvexType(NewGeomConvex.mType);
    mpGeomConvex->copy(NewGeomConvex);
}

rCollision::MaterialInfo& uScrollCollisionGeometry::cGeometryInfo::getGeomConvexMaterial() {
    return mGeomMaterialInfo;
}

const rCollision::MaterialInfo& uScrollCollisionGeometry::cGeometryInfo::getGeomConvexMaterialConst() const {
    return mGeomMaterialInfo;
}

__attribute__((weak)) void uScrollCollisionGeometry::cGeometryInfo::setGeomConvexMaterial(const rCollision::MaterialInfo& Material) {
    DDON_STUB("uScrollCollisionGeometry::cGeometryInfo::setGeomConvexMaterial")
    /* stub */
}

bool uScrollCollisionGeometry::cGeometryInfo::isActive() const {
    return mFlgActive;
}

void uScrollCollisionGeometry::cGeometryInfo::setActive(bool FlgActive) {
    mFlgActive = FlgActive;
}

inline uScrollCollisionGeometry::cGeometryInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uScrollCollisionGeometry::cGeometryInfo::MyDTI uScrollCollisionGeometry::cGeometryInfo::DTI("uScrollCollisionGeometry::cGeometryInfo", &::MtObject::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* uScrollCollisionGeometry::cGeometryInfo::MyDTI::newInstance() const {
    DDON_STUB("uScrollCollisionGeometry::cGeometryInfo::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uScrollCollisionGeometry::cGeometryInfo>::~MtTypedArray();

