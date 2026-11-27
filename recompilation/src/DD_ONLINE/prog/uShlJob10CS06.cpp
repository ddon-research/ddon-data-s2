// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlJob10CS06.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "rEffectProvider.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlCustomSpline.h"
#include "uShlSpline.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamJob10CS06::getDTI() const {
    return cShlParamJob10CS06::DTI;
}

MtDTI& cShlParamJob10CS06::getShlDTI() const {
    return uShlJob10CS06::DTI;
}

void cShlParamJob10CS06::createProperty(MtPropertyList& s) {
    this->cShlParamCustomSpline::createProperty(s);
}

__attribute__((weak)) void cShlParamJob10CS06::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamJob10CS06::copy")
    /* stub */
}

inline cShlParamJob10CS06::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob10CS06::MyDTI cShlParamJob10CS06::DTI("cShlParamJob10CS06", &::cShlParamCustomSpline::DTI, 560ul, 0u, 0u);

MtObject* cShlParamJob10CS06::MyDTI::newInstance() const {
    return new (16u) cShlParamJob10CS06;
}

const MtDTI& uShlJob10CS06::getDTI() const {
    return uShlJob10CS06::DTI;
}

uShlJob10CS06::~uShlJob10CS06() {
}

void uShlJob10CS06::setup() {
    this->uShlSpline::setup();
}

void uShlJob10CS06::kill() {
    this->uShlBase::kill();
}

void uShlJob10CS06::updatePtr() {
    this->uShlBase::updatePtr();
}

__attribute__((weak)) void uShlJob10CS06::callChargeEfc() {
    DDON_STUB("uShlJob10CS06::callChargeEfc")
    /* stub */
}

void uShlJob10CS06::callChargeSe() {
    if (mpOwner == nullptr) {
        return;
    }
    requestSE(101, static_cast<uCoord*>(this));
}

__attribute__((weak)) void uShlJob10CS06::callMaxChargeEfc() {
    DDON_STUB("uShlJob10CS06::callMaxChargeEfc")
    /* stub */
}

inline uShlJob10CS06::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob10CS06::MyDTI uShlJob10CS06::DTI("uShlJob10CS06", &::uShlCustomSpline::DTI, 11472ul, 0u, 0u);

MtObject* uShlJob10CS06::MyDTI::newInstance() const {
    return new (16u) uShlJob10CS06;
}

