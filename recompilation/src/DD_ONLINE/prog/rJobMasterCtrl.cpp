// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rJobMasterCtrl.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cJobMasterCtrl::getDTI() const {
    return cJobMasterCtrl::DTI;
}

void cJobMasterCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mJobId", &mJobId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartJobLevel", &mStartJobLevel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFirstTalkGrpSerial", &mFirstTalkGrpSerial, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTraningTalkGrpSerial", &mTraningTalkGrpSerial, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFirstOrderTalkGrpSerial", &mFirstOrderTalkGrpSerial, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJobTutorialQuestId", &mJobTutorialQuestId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJobMasterTutorialQuestId", &mJobMasterTutorialQuestId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaId", &mAreaId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaRank", &mAreaRank, 0u, 0u);
}

inline cJobMasterCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cJobMasterCtrl::MyDTI cJobMasterCtrl::DTI("cJobMasterCtrl", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cJobMasterCtrl::MyDTI::newInstance() const {
    return new (16u) cJobMasterCtrl;
}

const MtDTI& rJobMasterCtrl::getDTI() const {
    return rJobMasterCtrl::DTI;
}

rJobMasterCtrl::~rJobMasterCtrl() {
}

bool rJobMasterCtrl::loadData(MtDataReader& r, cJobMasterCtrl* pData) {
    nDDOIO::readData(r, pData->mJobId);
    nDDOIO::readData(r, pData->mStartJobLevel);
    nDDOIO::readData(r, pData->mFirstTalkGrpSerial);
    nDDOIO::readData(r, pData->mTraningTalkGrpSerial);
    nDDOIO::readData(r, pData->mFirstOrderTalkGrpSerial);
    nDDOIO::readData(r, pData->mJobTutorialQuestId);
    nDDOIO::readData(r, pData->mJobMasterTutorialQuestId);
    nDDOIO::readData(r, pData->mAreaId);
    nDDOIO::readData(r, pData->mAreaRank);
    return true;
}

bool rJobMasterCtrl::saveData(MtDataWriter& w, cJobMasterCtrl* pData) {
    nDDOIO::writeData(w, pData->mJobId);
    nDDOIO::writeData(w, pData->mStartJobLevel);
    nDDOIO::writeData(w, pData->mFirstTalkGrpSerial);
    nDDOIO::writeData(w, pData->mTraningTalkGrpSerial);
    nDDOIO::writeData(w, pData->mFirstOrderTalkGrpSerial);
    nDDOIO::writeData(w, pData->mJobTutorialQuestId);
    nDDOIO::writeData(w, pData->mJobMasterTutorialQuestId);
    nDDOIO::writeData(w, pData->mAreaId);
    nDDOIO::writeData(w, pData->mAreaRank);
    return true;
}

MT_CTSTR rJobMasterCtrl::getExt() const {
    return "jmc";
}

u32 rJobMasterCtrl::getDataVersion() const {
    return 256;
}

inline rJobMasterCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rJobMasterCtrl::MyDTI rJobMasterCtrl::DTI("rJobMasterCtrl", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rJobMasterCtrl::MyDTI::newInstance() const {
    return new (16u) rJobMasterCtrl;
}

template cJobMasterCtrl* rTbl2<cJobMasterCtrl>::getData(unsigned int);

template bool rTbl2<cJobMasterCtrl>::load(MtStream&);

template bool rTbl2<cJobMasterCtrl>::loadCore(MtDataReader&);

template const cJobMasterCtrl* rTbl2<cJobMasterCtrl>::getData(unsigned int) const;

template unsigned int rTbl2<cJobMasterCtrl>::getDataNum() const;

template rTbl2<cJobMasterCtrl>::~rTbl2();

