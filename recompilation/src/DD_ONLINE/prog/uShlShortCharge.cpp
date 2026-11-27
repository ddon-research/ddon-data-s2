// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlShortCharge.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "uShlBase.h"
#include "uShlFollowMove.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamShortCharge::getDTI() const {
    return cShlParamShortCharge::DTI;
}

inline void cShlParamShortCharge::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamShortCharge::DTI)->memFree(p_addr);
}

MtDTI& cShlParamShortCharge::getShlDTI() const {
    return uShlShortCharge::DTI;
}

void cShlParamShortCharge::createProperty(MtPropertyList& s) {
    this->cShlParamFollowMove::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "MgcChargeRate", &MgcChargeRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "PysChargeRate", &PysChargeRate, 0u, 0u);
}

cShlParamShortCharge::~cShlParamShortCharge() {
}

__attribute__((weak)) void cShlParamShortCharge::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamShortCharge::copy")
    /* stub */
}

inline cShlParamShortCharge::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamShortCharge::MyDTI cShlParamShortCharge::DTI("cShlParamShortCharge", &::cShlParamFollowMove::DTI, 416ul, 0u, 0u);

MtObject* cShlParamShortCharge::MyDTI::newInstance() const {
    return new (16u) cShlParamShortCharge;
}

const MtDTI& uShlShortCharge::getDTI() const {
    return uShlShortCharge::DTI;
}

uShlShortCharge::~uShlShortCharge() {
}

inline uShlShortCharge::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlShortCharge::MyDTI uShlShortCharge::DTI("uShlShortCharge", &::uShlFollowMove::DTI, 10944ul, 0u, 0u);

MtObject* uShlShortCharge::MyDTI::newInstance() const {
    return new (16u) uShlShortCharge;
}

