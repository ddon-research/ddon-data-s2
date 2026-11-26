// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rPlayerExpTable.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPlayerExpTable::getDTI() const {
    return cPlayerExpTable::DTI;
}

inline void* cPlayerExpTable::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cPlayerExpTable::DTI)->memAlloc(sz, align, cPlayerExpTable::DTI.getID());
}

inline void cPlayerExpTable::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cPlayerExpTable::DTI)->memFree(p_addr);
}

void cPlayerExpTable::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\345\277\205\350\246\201\347\265\214\351\250\223\345\200\244", &mNeedExp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\276\227\343\202\211\343\202\214\343\202\213\350\201\267\346\245\255\343\203\235\343\202\244\343\203\263\343\203\210", &mGainJobPoint, 0u, 0u);
}

inline cPlayerExpTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPlayerExpTable::MyDTI cPlayerExpTable::DTI("cPlayerExpTable", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cPlayerExpTable::MyDTI::newInstance() const {
    return new (16u) cPlayerExpTable;
}

const MtDTI& rPlayerExpTable::getDTI() const {
    return rPlayerExpTable::DTI;
}

inline void* rPlayerExpTable::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rPlayerExpTable::DTI)->memAlloc(sz, align, rPlayerExpTable::DTI.getID());
}

inline void rPlayerExpTable::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rPlayerExpTable::DTI)->memFree(p_addr);
}

bool rPlayerExpTable::loadData(MtDataReader& in, cPlayerExpTable* pData) {
    nDDOIO::readData(in, pData->mNeedExp);
    nDDOIO::readData(in, pData->mGainJobPoint);
    return true;
}

MT_CTSTR rPlayerExpTable::getExt() const {
    return "exp";
}

u32 rPlayerExpTable::getDataVersion() const {
    return 2;
}

void rPlayerExpTable::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
}

inline rPlayerExpTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPlayerExpTable::MyDTI rPlayerExpTable::DTI("rPlayerExpTable", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rPlayerExpTable::MyDTI::newInstance() const {
    return new (16u) rPlayerExpTable;
}

template cPlayerExpTable* rTbl2<cPlayerExpTable>::getData(unsigned int);

template bool rTbl2<cPlayerExpTable>::load(MtStream&);

template bool rTbl2<cPlayerExpTable>::loadCore(MtDataReader&);

template const cPlayerExpTable* rTbl2<cPlayerExpTable>::getData(unsigned int) const;

template unsigned int rTbl2<cPlayerExpTable>::getDataNum() const;

template rTbl2<cPlayerExpTable>::~rTbl2();

