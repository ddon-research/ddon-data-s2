// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlFuwaFuwa2.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "cShlFuwaFuwaCtrl2.h"
#include "../../XFramework/cUnit.h"
#include "cpLockOn.h"
#include "nDDOUtility.h"
#include "sSetManager.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamFuwaFuwa2::getDTI() const {
    return cShlParamFuwaFuwa2::DTI;
}

MtDTI& cShlParamFuwaFuwa2::getShlDTI() const {
    return uShlFuwaFuwa2::DTI;
}

cShlParamFuwaFuwa2::cShlParamFuwaFuwa2() {
    mSeqNoMax = 0u;
}

void cShlParamFuwaFuwa2::createProperty(MtPropertyList& s) {
    this->cShlParamSpeed::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mSeqNoMax", &mSeqNoMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFuwaFuwaInfoArray.elems", &mFuwaFuwaInfoArray.elems[0], 32u, 8u);
}

void cShlParamFuwaFuwa2::copy(const cShlParamBase* pParamBase) {
    this->cShlParamSpeed::copy(pParamBase);
    const cShlParamFuwaFuwa2* pParam = static_cast<const cShlParamFuwaFuwa2*>(pParamBase);
    mFuwaFuwaInfoArray.elems[0].copy(pParam->mFuwaFuwaInfoArray.elems[0]);
    mFuwaFuwaInfoArray.elems[1].copy(pParam->mFuwaFuwaInfoArray.elems[1]);
    mFuwaFuwaInfoArray.elems[2].copy(pParam->mFuwaFuwaInfoArray.elems[2]);
    mFuwaFuwaInfoArray.elems[3].copy(pParam->mFuwaFuwaInfoArray.elems[3]);
    mFuwaFuwaInfoArray.elems[4].copy(pParam->mFuwaFuwaInfoArray.elems[4]);
    mFuwaFuwaInfoArray.elems[5].copy(pParam->mFuwaFuwaInfoArray.elems[5]);
    mFuwaFuwaInfoArray.elems[6].copy(pParam->mFuwaFuwaInfoArray.elems[6]);
    mFuwaFuwaInfoArray.elems[7].copy(pParam->mFuwaFuwaInfoArray.elems[7]);
    mSeqNoMax = pParam->mSeqNoMax;
}

inline cShlParamFuwaFuwa2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamFuwaFuwa2::MyDTI cShlParamFuwaFuwa2::DTI("cShlParamFuwaFuwa2", &::cShlParamSpeed::DTI, 768ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamFuwaFuwa2::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamFuwaFuwa2::DTI)->memAlloc(sizeof(cShlParamFuwaFuwa2), 16u, cShlParamFuwaFuwa2::DTI.getID())) cShlParamFuwaFuwa2;
}

const MtDTI& uShlFuwaFuwa2::getDTI() const {
    return uShlFuwaFuwa2::DTI;
}

uShlFuwaFuwa2::~uShlFuwaFuwa2() {
}

void uShlFuwaFuwa2::setup() {
    this->uShlSpeed::setup();
}

void uShlFuwaFuwa2::kill() {
    this->uShlSpeed::kill();
}

void uShlFuwaFuwa2::createProperty(MtPropertyList& s) {
    this->uDDOModel::createProperty(s);
}

void uShlFuwaFuwa2::draw(cDraw* pDraw) {
    this->uDDOModel::draw(pDraw);
}

__attribute__((weak)) void uShlFuwaFuwa2::initSub() {
    DDON_STUB("uShlFuwaFuwa2::initSub")
    /* stub */
}

__attribute__((weak)) void uShlFuwaFuwa2::updateSub() {
    DDON_STUB("uShlFuwaFuwa2::updateSub")
    /* stub */
}

inline uShlFuwaFuwa2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlFuwaFuwa2::MyDTI uShlFuwaFuwa2::DTI("uShlFuwaFuwa2", &::uShlSpeed::DTI, 11360ul, 0u, 0u);

MtObject* uShlFuwaFuwa2::MyDTI::newInstance() const {
    return new (16u) uShlFuwaFuwa2;
}

