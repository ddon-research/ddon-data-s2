// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rQuestSequenceList.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestSequence::getDTI() const {
    return cQuestSequence::DTI;
}

void cQuestSequence::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSeqNo", &mSeqNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQstId", &mQstId, 0u, 0u);
}

inline cQuestSequence::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSequence::MyDTI cQuestSequence::DTI("cQuestSequence", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cQuestSequence::MyDTI::newInstance() const {
    return new (16u) cQuestSequence;
}

const MtDTI& rQuestSequenceList::getDTI() const {
    return rQuestSequenceList::DTI;
}

rQuestSequenceList::~rQuestSequenceList() {
}

bool rQuestSequenceList::loadData(MtDataReader& r, cQuestSequence* pData) {
    nDDOIO::readData(r, pData->mSeqNo);
    nDDOIO::readData(r, pData->mQstId);
    return true;
}

bool rQuestSequenceList::saveData(MtDataWriter& w, cQuestSequence* pData) {
    nDDOIO::writeData(w, pData->mSeqNo);
    nDDOIO::writeData(w, pData->mQstId);
    return true;
}

MT_CTSTR rQuestSequenceList::getExt() const {
    return "qsq";
}

u32 rQuestSequenceList::getDataVersion() const {
    return 256;
}

inline rQuestSequenceList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rQuestSequenceList::MyDTI rQuestSequenceList::DTI("rQuestSequenceList", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rQuestSequenceList::MyDTI::newInstance() const {
    return new (16u) rQuestSequenceList;
}

template cQuestSequence* rTbl2<cQuestSequence>::getData(unsigned int);

template bool rTbl2<cQuestSequence>::load(MtStream&);

template bool rTbl2<cQuestSequence>::loadCore(MtDataReader&);

template const cQuestSequence* rTbl2<cQuestSequence>::getData(unsigned int) const;

template unsigned int rTbl2<cQuestSequence>::getDataNum() const;

template rTbl2<cQuestSequence>::~rTbl2();

