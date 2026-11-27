// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rStartPosArea.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cStartPosArea::getDTI() const {
    return cStartPosArea::DTI;
}

void cStartPosArea::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStartPosNo", &mStartPosNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaId", &mAreaId, 0u, 0u);
}

MtUI* cStartPosArea::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cStartPosArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStartPosArea::MyDTI cStartPosArea::DTI("cStartPosArea", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cStartPosArea::MyDTI::newInstance() const {
    return new (16u) cStartPosArea;
}

const MtDTI& rStartPosArea::getDTI() const {
    return rStartPosArea::DTI;
}

bool rStartPosArea::loadData(MtDataReader& in, cStartPosArea* pData) {
    nDDOIO::readData(in, pData->mStartPosNo);
    nDDOIO::readData(in, pData->mAreaId);
    return true;
}

MT_CTSTR rStartPosArea::getExt() const {
    return "sta";
}

u32 rStartPosArea::getDataVersion() const {
    return 0;
}

inline rStartPosArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStartPosArea::MyDTI rStartPosArea::DTI("rStartPosArea", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rStartPosArea::MyDTI::newInstance() const {
    return new (16u) rStartPosArea;
}

template cStartPosArea* rTbl2<cStartPosArea>::getData(unsigned int);

template bool rTbl2<cStartPosArea>::load(MtStream&);

template bool rTbl2<cStartPosArea>::loadCore(MtDataReader&);

template const cStartPosArea* rTbl2<cStartPosArea>::getData(unsigned int) const;

template unsigned int rTbl2<cStartPosArea>::getDataNum() const;

template rTbl2<cStartPosArea>::~rTbl2();

