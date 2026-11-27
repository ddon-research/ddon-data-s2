// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtDtiSelecter.h"
#include "MtDTI.h"
#include "MtMemoryAllocator.h"
#include "MtObject.h"
#include "MtProperty.h"
#include "MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtDtiSelecter::getDTI() const {
    return MtDtiSelecter::DTI;
}

MtDtiSelecter::MtDtiSelecter() {
    mpUseDTI = nullptr;
}

MtDtiSelecter::~MtDtiSelecter() {
}

MtUI* MtDtiSelecter::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void MtDtiSelecter::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "DtiDropDownList", reinterpret_cast<MT_MFUNC>(&::MtDtiSelecter::getSelectDtiID), reinterpret_cast<MT_MFUNC>(&::MtDtiSelecter::setSelectDtiID), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "EditDtiName", reinterpret_cast<MT_MFUNC>(&::MtDtiSelecter::getSelectDtiName), reinterpret_cast<MT_MFUNC>(&::MtDtiSelecter::setSelectDtiName), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "EditDtiID", reinterpret_cast<MT_MFUNC>(&::MtDtiSelecter::getSelectDtiID), reinterpret_cast<MT_MFUNC>(&::MtDtiSelecter::setSelectDtiID), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MT_CTSTR MtDtiSelecter::getSelectDtiName() const {
    if (mpUseDTI != nullptr) {
        return mpUseDTI->mName;
    } else {
        return "-";
    }
}

__attribute__((weak)) void MtDtiSelecter::setSelectDtiName(const MtString& NewDtiName) {
    DDON_STUB("MtDtiSelecter::setSelectDtiName")
    /* stub */
}

u32 MtDtiSelecter::getSelectDtiID() const {
    if (mpUseDTI != nullptr) {
        return mpUseDTI->mID;
    } else {
        return 0;
    }
}

void MtDtiSelecter::setSelectDtiID(u32 NewDtiID) {
    const MtDTI* t0 = MtDTI::from(NewDtiID);
    if (mpUseDTI == t0) {
        return;
    }
    mpUseDTI = t0;
}

void MtDtiSelecter::setSelectDti(const MtDTI* pNewDti) {
    if (pNewDti == mpUseDTI) {
        return;
    }
    mpUseDTI = pNewDti;
}

inline MtDtiSelecter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtDtiSelecter::MyDTI MtDtiSelecter::DTI("MtDtiSelecter", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* MtDtiSelecter::MyDTI::newInstance() const {
    DDON_STUB("MtDtiSelecter::MyDTI::newInstance")
    return nullptr;
}

