// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlSpline.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "../../XFramework/rCollisionHeightField.h"
#include "../../XFramework/sCollision.h"
#include "sEffectExt.h"
#include "../../XFramework/uCoord.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamSpline::getDTI() const {
    return cShlParamSpline::DTI;
}

inline void* cShlParamSpline::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamSpline::DTI)->memAlloc(sz, align, cShlParamSpline::DTI.getID());
}

inline void cShlParamSpline::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlParamSpline::DTI)->memFree(p_addr);
}

MtDTI& cShlParamSpline::getShlDTI() const {
    return uShlSpline::DTI;
}

__attribute__((noinline)) cShlParamSpline::~cShlParamSpline() {
    for (u32 i = 0; i < nodeList.mLength; i++) {
        delete nodeList.mpArray[i];
    }
    if (nodeList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(nodeList.mpArray));
    }
    nodeList.mpArray = nullptr;
    nodeList.mBufsiz = 0;
    nodeList.mLength = 0;
}

void cShlParamSpline::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "spd", &spd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "spdMax", &spdMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "spdAccel", &spdAccel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "topSpeed", &topSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "offset", &offset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "offsetRnd", &offsetRnd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dieFlag", &dieFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "followTime", &followTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitShlNo", &hitShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "floorHitShlNo", &floorHitShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlOptionSpline", &shlOptionSpline, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "parabolaHeight", &parabolaHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isValidLimit", &isValidLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "limitDist", &limitDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "limitAngle", &limitAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isUpValidLimit", &isUpValidLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "limitUpAngle", &limitUpAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mhokan", &mhokan, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParabolaXAng", &mParabolaXAng, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "nodeList", static_cast<MtObject*>(&nodeList), 0u, 0u);
}

void cShlParamSpline::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoScrHit", &epvNoScrHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scrHitEfType", reinterpret_cast<s32*>(&scrHitEfType), 0u, 0u);
}

void cShlParamSpline::createPropertySE(MtPropertyList& s) {
    this->cShlParamBase::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "seNoScrHit", &seNoScrHit, 0u, 0u);
}

__attribute__((weak)) void cShlParamSpline::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamSpline::copy")
    /* stub */
}

__attribute__((weak)) void cShlParamSpline::addnodeList(const cShlParamSpline* pParam) {
    DDON_STUB("cShlParamSpline::addnodeList")
    /* stub */
}

inline cShlParamSpline::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamSpline::MyDTI cShlParamSpline::DTI("cShlParamSpline", &::cShlParamBase::DTI, 512ul, 0u, 0u);

MtObject* cShlParamSpline::MyDTI::newInstance() const {
    return new (16u) cShlParamSpline;
}

const MtDTI& cShlParamSpline::cSplineShlNodeParam::getDTI() const {
    return cShlParamSpline::cSplineShlNodeParam::DTI;
}

inline MtAllocator* cShlParamSpline::cSplineShlNodeParam::getAllocator() {
    return MtMemoryAllocator::getAllocator(cShlParamSpline::cSplineShlNodeParam::DTI);
}

void* cShlParamSpline::cSplineShlNodeParam::operator new(size_t sz, u32 align) {
    return cShlParamSpline::cSplineShlNodeParam::getAllocator()->memAlloc(sz, align, cShlParamSpline::cSplineShlNodeParam::DTI.getID());
}

__attribute__((weak)) void cShlParamSpline::cSplineShlNodeParam::operator delete(void* p_addr) {
    cShlParamSpline::cSplineShlNodeParam::getAllocator()->memFree(p_addr);
}

inline cShlParamSpline::cSplineShlNodeParam::cSplineShlNodeParam() {
    mOffset = MtVector3::Zero;
}

cShlParamSpline::cSplineShlNodeParam::~cSplineShlNodeParam() {
    return;
}

void cShlParamSpline::cSplineShlNodeParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mOffset", &mOffset, 0u, 0u);
}

inline cShlParamSpline::cSplineShlNodeParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamSpline::cSplineShlNodeParam::MyDTI cShlParamSpline::cSplineShlNodeParam::DTI("cShlParamSpline::cSplineShlNodeParam", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cShlParamSpline::cSplineShlNodeParam::MyDTI::newInstance() const {
    return new (16u) cShlParamSpline::cSplineShlNodeParam;
}

const MtDTI& uShlSpline::getDTI() const {
    return uShlSpline::DTI;
}

inline void uShlSpline::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlSpline::DTI)->memFree(p_addr);
}

uShlSpline::uShlSpline() {
    DDON_STUB("uShlSpline::uShlSpline")
    /* stub */
}

uShlSpline::~uShlSpline() {
}

__attribute__((weak)) void uShlSpline::setup() {
    DDON_STUB("uShlSpline::setup")
    /* stub */
}

__attribute__((weak)) void uShlSpline::initSub() {
}

__attribute__((weak)) void uShlSpline::updateSub() {
    DDON_STUB("uShlSpline::updateSub")
    /* stub */
}

__attribute__((weak)) bool uShlSpline::isDie() {
    DDON_STUB("uShlSpline::isDie")
    return {};
}

__attribute__((weak)) void uShlSpline::movePos() {
    DDON_STUB("uShlSpline::movePos")
    /* stub */
}

__attribute__((weak)) void uShlSpline::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlSpline::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uShlSpline::checkScr() {
    DDON_STUB("uShlSpline::checkScr")
    /* stub */
}

__attribute__((weak)) void uShlSpline::setScrHitEfct(const MtVector3& pos, f32 scale) {
    DDON_STUB("uShlSpline::setScrHitEfct")
    /* stub */
}

inline uShlSpline::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlSpline::MyDTI uShlSpline::DTI("uShlSpline", &::uShlBase::DTI, 11456ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlSpline::MyDTI::newInstance() const {
    DDON_STUB("uShlSpline::MyDTI::newInstance")
    return nullptr;
}

