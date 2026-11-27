// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlPadCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpInput.h"
#include "cpShlShotCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "sLockOnManager.h"
#include "sShlManager.h"
#include "sWorkRate.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlHoming.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamJob08Cs12Homing::getDTI() const {
    return cShlParamJob08Cs12Homing::DTI;
}

inline void cShlParamJob08Cs12Homing::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamJob08Cs12Homing::DTI)->memFree(p_addr);
}

MtDTI& cShlParamJob08Cs12Homing::getShlDTI() const {
    return uShlJob08Cs12Homing::DTI;
}

cShlParamJob08Cs12Homing::~cShlParamJob08Cs12Homing() {
}

void cShlParamJob08Cs12Homing::createProperty(MtPropertyList& s) {
    this->cShlParamHoming::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "maxHit", &maxHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "objHitShlNo", &objHitShlNo[0], 32u, 5u);
    s << MtProperty(static_cast<MtObject*>(this), "finishShlNo", &finishShlNo, 0u, 0u);
}

__attribute__((weak)) void cShlParamJob08Cs12Homing::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamJob08Cs12Homing::copy")
    /* stub */
}

inline cShlParamJob08Cs12Homing::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob08Cs12Homing::MyDTI cShlParamJob08Cs12Homing::DTI("cShlParamJob08Cs12Homing", &::cShlParamHoming::DTI, 624ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamJob08Cs12Homing::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamJob08Cs12Homing::DTI)->memAlloc(sizeof(cShlParamJob08Cs12Homing), 16u, cShlParamJob08Cs12Homing::DTI.getID())) cShlParamJob08Cs12Homing;
}

const MtDTI& cShlParamJob08Cs12Pad::getDTI() const {
    return cShlParamJob08Cs12Pad::DTI;
}

inline void cShlParamJob08Cs12Pad::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamJob08Cs12Pad::DTI)->memFree(p_addr);
}

MtDTI& cShlParamJob08Cs12Pad::getShlDTI() const {
    return uShlJob08Cs12Pad::DTI;
}

cShlParamJob08Cs12Pad::~cShlParamJob08Cs12Pad() {
}

__attribute__((weak)) void cShlParamJob08Cs12Pad::createProperty(MtPropertyList& s) {
    cShlParamSpeed::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "padCtrlDeg", &padCtrlDeg, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "ctrlDist", &ctrlDist, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "objHitShlNo", &objHitShlNo, 0, 0);
}

__attribute__((weak)) void cShlParamJob08Cs12Pad::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamJob08Cs12Pad::copy")
    /* stub */
}

inline cShlParamJob08Cs12Pad::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob08Cs12Pad::MyDTI cShlParamJob08Cs12Pad::DTI("cShlParamJob08Cs12Pad", &::cShlParamPadCtrl::DTI, 512ul, 0u, 0u);

MtObject* cShlParamJob08Cs12Pad::MyDTI::newInstance() const {
    return new (16u) cShlParamJob08Cs12Pad;
}

const MtDTI& cShlParamPadCtrl::getDTI() const {
    return cShlParamPadCtrl::DTI;
}

MtDTI& cShlParamPadCtrl::getShlDTI() const {
    return uShlPadCtrl::DTI;
}

cShlParamPadCtrl::~cShlParamPadCtrl() {
}

void cShlParamPadCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamSpeed::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "padCtrlDeg", &padCtrlDeg, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ctrlDist", &ctrlDist, 0u, 0u);
}

void cShlParamPadCtrl::copy(const cShlParamBase* pParamBase) {
    this->cShlParamSpeed::copy(pParamBase);
    const cShlParamPadCtrl* pParam = static_cast<const cShlParamPadCtrl*>(pParamBase);
    padCtrlDeg = pParam->padCtrlDeg;
    ctrlDist = pParam->ctrlDist;
}

inline cShlParamPadCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamPadCtrl::MyDTI cShlParamPadCtrl::DTI("cShlParamPadCtrl", &::cShlParamSpeed::DTI, 512ul, 0u, 0u);

MtObject* cShlParamPadCtrl::MyDTI::newInstance() const {
    return new (16u) cShlParamPadCtrl;
}

const MtDTI& uShlJob08Cs12Homing::getDTI() const {
    return uShlJob08Cs12Homing::DTI;
}

__attribute__((weak)) void uShlJob08Cs12Homing::updateSub() {
    DDON_STUB("uShlJob08Cs12Homing::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlJob08Cs12Homing::callbackAttack(cHitInfo* pHitInfo) {
    DDON_STUB("uShlJob08Cs12Homing::callbackAttack")
    /* stub */
}

inline uShlJob08Cs12Homing::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob08Cs12Homing::MyDTI uShlJob08Cs12Homing::DTI("uShlJob08Cs12Homing", &::uShlHoming::DTI, 11248ul, 0u, 0u);

MtObject* uShlJob08Cs12Homing::MyDTI::newInstance() const {
    return new (16u) uShlJob08Cs12Homing;
}

const MtDTI& uShlJob08Cs12Pad::getDTI() const {
    return uShlJob08Cs12Pad::DTI;
}

__attribute__((weak)) void uShlJob08Cs12Pad::updateSub() {
    DDON_STUB("uShlJob08Cs12Pad::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlJob08Cs12Pad::callbackAttack(cHitInfo* pHitInfo) {
    DDON_STUB("uShlJob08Cs12Pad::callbackAttack")
    /* stub */
}

inline uShlJob08Cs12Pad::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob08Cs12Pad::MyDTI uShlJob08Cs12Pad::DTI("uShlJob08Cs12Pad", &::uShlPadCtrl::DTI, 11152ul, 0u, 0u);

MtObject* uShlJob08Cs12Pad::MyDTI::newInstance() const {
    return new (16u) uShlJob08Cs12Pad;
}

const MtDTI& uShlPadCtrl::getDTI() const {
    return uShlPadCtrl::DTI;
}

uShlPadCtrl::~uShlPadCtrl() {
}

void uShlPadCtrl::setup() {
    this->uShlSpeed::setup();
}

__attribute__((weak)) void uShlPadCtrl::updateSub() {
    DDON_STUB("uShlPadCtrl::updateSub")
    /* stub */
}

inline uShlPadCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlPadCtrl::MyDTI uShlPadCtrl::DTI("uShlPadCtrl", &::uShlSpeed::DTI, 11152ul, 0u, 0u);

MtObject* uShlPadCtrl::MyDTI::newInstance() const {
    return new (16u) uShlPadCtrl;
}

