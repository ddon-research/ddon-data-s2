// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rNpcMeetingPlace.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cNpcMeetingPlace::getDTI() const {
    return cNpcMeetingPlace::DTI;
}

void cNpcMeetingPlace::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mNpcId", &mNpcId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartPosNo", &mStartPosNo, 0u, 0u);
}

inline cNpcMeetingPlace::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cNpcMeetingPlace::MyDTI cNpcMeetingPlace::DTI("cNpcMeetingPlace", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cNpcMeetingPlace::MyDTI::newInstance() const {
    return new (16u) cNpcMeetingPlace;
}

const MtDTI& rNpcMeetingPlace::getDTI() const {
    return rNpcMeetingPlace::DTI;
}

bool rNpcMeetingPlace::loadData(MtDataReader& in, cNpcMeetingPlace* pData) {
    if (pData != nullptr) {
        pData->mNpcId = in.readU32();
        pData->mStageNo = in.readS32();
        pData->mStartPosNo = in.readU32();
        return true;
    } else {
        return false;
    }
}

MT_CTSTR rNpcMeetingPlace::getExt() const {
    return "nmp";
}

u32 rNpcMeetingPlace::getDataVersion() const {
    return 0;
}

inline rNpcMeetingPlace::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNpcMeetingPlace::MyDTI rNpcMeetingPlace::DTI("rNpcMeetingPlace", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rNpcMeetingPlace::MyDTI::newInstance() const {
    return new (16u) rNpcMeetingPlace;
}

template cNpcMeetingPlace* rTbl2<cNpcMeetingPlace>::getData(unsigned int);

template bool rTbl2<cNpcMeetingPlace>::load(MtStream&);

template bool rTbl2<cNpcMeetingPlace>::loadCore(MtDataReader&);

template const cNpcMeetingPlace* rTbl2<cNpcMeetingPlace>::getData(unsigned int) const;

template unsigned int rTbl2<cNpcMeetingPlace>::getDataNum() const;

template rTbl2<cNpcMeetingPlace>::~rTbl2();

