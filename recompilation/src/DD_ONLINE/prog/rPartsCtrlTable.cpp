// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rPartsCtrlTable.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPartsCtrlTable::getDTI() const {
    return cPartsCtrlTable::DTI;
}

void cPartsCtrlTable::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPartsKeyNo", &mPartsKeyNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "PartsDisp", reinterpret_cast<MT_MFUNC>(&::cPartsCtrlTable::isPartsDisp), reinterpret_cast<MT_MFUNC>(&::cPartsCtrlTable::setPartsDisp), 160u, reinterpret_cast<MT_MFUNC>(&::cPartsCtrlTable::getPartsNum), reinterpret_cast<MT_MFUNC>(&::cPartsCtrlTable::setPartsNum));
}

bool cPartsCtrlTable::isPartsDisp(u32 no) const {
    return ((static_cast<unsigned long>(mPartsDisp[no >> 5]) >> static_cast<unsigned long>(no & 31u)) & 1ul) != 0;
}

__attribute__((weak)) void cPartsCtrlTable::setPartsDisp(bool disp, u32 no) {
    DDON_STUB("cPartsCtrlTable::setPartsDisp")
    /* stub */
}

static auto ddon_emit_0x01aaaeb0 __attribute__((used)) = &cPartsCtrlTable::getPartsNum;

__attribute__((weak)) void cPartsCtrlTable::setPartsNum(u32) {
}

inline cPartsCtrlTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPartsCtrlTable::MyDTI cPartsCtrlTable::DTI("cPartsCtrlTable", &::MtObject::DTI, 80ul, 0u, 0u);

MtObject* cPartsCtrlTable::MyDTI::newInstance() const {
    return new (16u) cPartsCtrlTable;
}

const MtDTI& rPartsCtrlTable::getDTI() const {
    return rPartsCtrlTable::DTI;
}

bool rPartsCtrlTable::loadData(MtDataReader& in, cPartsCtrlTable* pData) {
    pData->mPartsKeyNo = in.readS32();
    pData->mPartsDisp[0] = in.readU32();
    pData->mPartsDisp[1] = in.readU32();
    pData->mPartsDisp[2] = in.readU32();
    pData->mPartsDisp[3] = in.readU32();
    pData->mPartsDisp[4] = in.readU32();
    pData->mPartsDisp[5] = in.readU32();
    pData->mPartsDisp[6] = in.readU32();
    pData->mPartsDisp[7] = in.readU32();
    pData->mPartsDisp[8] = in.readU32();
    pData->mPartsDisp[9] = in.readU32();
    pData->mPartsDisp[10] = in.readU32();
    pData->mPartsDisp[11] = in.readU32();
    pData->mPartsDisp[12] = in.readU32();
    pData->mPartsDisp[13] = in.readU32();
    pData->mPartsDisp[14] = in.readU32();
    pData->mPartsDisp[15] = in.readU32();
    return true;
}

MT_CTSTR rPartsCtrlTable::getExt() const {
    return "ptc";
}

u32 rPartsCtrlTable::getDataVersion() const {
    return 256;
}

inline rPartsCtrlTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPartsCtrlTable::MyDTI rPartsCtrlTable::DTI("rPartsCtrlTable", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rPartsCtrlTable::MyDTI::newInstance() const {
    return new (16u) rPartsCtrlTable;
}

template cPartsCtrlTable* rTbl2<cPartsCtrlTable>::getData(unsigned int);

template bool rTbl2<cPartsCtrlTable>::load(MtStream&);

template bool rTbl2<cPartsCtrlTable>::loadCore(MtDataReader&);

template const cPartsCtrlTable* rTbl2<cPartsCtrlTable>::getData(unsigned int) const;

template unsigned int rTbl2<cPartsCtrlTable>::getDataNum() const;

template rTbl2<cPartsCtrlTable>::~rTbl2();

