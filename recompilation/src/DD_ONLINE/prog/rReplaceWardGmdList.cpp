// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rReplaceWardGmdList.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cResPath.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../XFramework/rGUIMessage.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cReplaceWardGmdList::getDTI() const {
    return cReplaceWardGmdList::DTI;
}

inline cReplaceWardGmdList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cReplaceWardGmdList::MyDTI cReplaceWardGmdList::DTI("cReplaceWardGmdList", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cReplaceWardGmdList::MyDTI::newInstance() const {
    return new (16u) cReplaceWardGmdList;
}

const MtDTI& rReplaceWardGmdList::getDTI() const {
    return rReplaceWardGmdList::DTI;
}

bool rReplaceWardGmdList::loadData(MtDataReader& r, cReplaceWardGmdList* pData) {
    nDDOIO::readData(r, pData->mGmdResPath);
    return true;
}

MT_CTSTR rReplaceWardGmdList::getExt() const {
    return "repgmdlist";
}

u32 rReplaceWardGmdList::getDataVersion() const {
    return 1;
}

inline rReplaceWardGmdList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rReplaceWardGmdList::MyDTI rReplaceWardGmdList::DTI("rReplaceWardGmdList", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rReplaceWardGmdList::MyDTI::newInstance() const {
    return new (16u) rReplaceWardGmdList;
}

template cReplaceWardGmdList* rTbl2<cReplaceWardGmdList>::getData(unsigned int);

template bool rTbl2<cReplaceWardGmdList>::load(MtStream&);

template bool rTbl2<cReplaceWardGmdList>::loadCore(MtDataReader&);

template const cReplaceWardGmdList* rTbl2<cReplaceWardGmdList>::getData(unsigned int) const;

template unsigned int rTbl2<cReplaceWardGmdList>::getDataNum() const;

template rTbl2<cReplaceWardGmdList>::~rTbl2();

