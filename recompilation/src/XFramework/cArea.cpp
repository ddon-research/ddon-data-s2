// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cArea.h"
#include "../MT/MtDTI.h"
#include "../MT/MtFile.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "../MT/MtSynchronize.h"
#include "cResource.h"
#include "rArchive.h"
#include "sResource.h"
#include "sShader2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cArea::getDTI() const {
    return cArea::DTI;
}

cArea::cArea() {
    DDON_STUB("cArea::cArea")
    /* stub */
}

cArea::~cArea() {
    DDON_STUB("cArea::~cArea")
    /* stub */
}

__attribute__((weak)) bool cArea::load() {
    DDON_STUB("cArea::load")
    return {};
}

void cArea::final() {
    if (mpShaderArchive == nullptr) {
        return;
    }
    mpShaderArchive->release();
    mpShaderArchive = nullptr;
}

const MtDTI& cArea::getParentType() {
    return cArea::DTI;
}

MT_CTSTR cArea::getName() {
    return getDTI().getName();
}

__attribute__((weak)) MT_CTSTR cArea::getShaderSegment() {
    DDON_STUB("cArea::getShaderSegment")
    return {};
}

void cArea::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mInit", &mInit, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRno", &this->mRno, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaPt", &mAreaPt, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpShaderArchive", "resource", static_cast<void*>(&mpShaderArchive), 2u, 0u);
}

MtUI* cArea::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cArea::MyDTI cArea::DTI("cArea", &::MtObject::DTI, 48ul, 0u, 1u);

MtObject* cArea::MyDTI::newInstance() const {
    return nullptr;
}

