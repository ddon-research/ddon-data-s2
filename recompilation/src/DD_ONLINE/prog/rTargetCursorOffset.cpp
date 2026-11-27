// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rTargetCursorOffset.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cUIObject.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cTargetCursorOffset::getDTI() const {
    return cTargetCursorOffset::DTI;
}

inline cTargetCursorOffset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cTargetCursorOffset::MyDTI cTargetCursorOffset::DTI("cTargetCursorOffset", &::cUIResource::DTI, 32ul, 0u, 0u);

MtObject* cTargetCursorOffset::MyDTI::newInstance() const {
    return new (16u) cTargetCursorOffset;
}

const MtDTI& rTargetCursorOffset::getDTI() const {
    return rTargetCursorOffset::DTI;
}

bool rTargetCursorOffset::loadData(MtDataReader& in, cTargetCursorOffset* pData) {
    pData->mId = in.readU32();
    pData->mJointNo = in.readS32();
    pData->mOffsetFromJoint = in.readV3();
    return true;
}

MT_CTSTR rTargetCursorOffset::getExt() const {
    return "tco";
}

u32 rTargetCursorOffset::getDataVersion() const {
    return 272;
}

inline rTargetCursorOffset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTargetCursorOffset::MyDTI rTargetCursorOffset::DTI("rTargetCursorOffset", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rTargetCursorOffset::MyDTI::newInstance() const {
    return new (16u) rTargetCursorOffset;
}

template cTargetCursorOffset* rTbl2<cTargetCursorOffset>::getData(unsigned int);

template bool rTbl2<cTargetCursorOffset>::load(MtStream&);

template bool rTbl2<cTargetCursorOffset>::loadCore(MtDataReader&);

template const cTargetCursorOffset* rTbl2<cTargetCursorOffset>::getData(unsigned int) const;

template unsigned int rTbl2<cTargetCursorOffset>::getDataNum() const;

template rTbl2<cTargetCursorOffset>::~rTbl2();

