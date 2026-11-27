// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rFurnitureItem.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cFurnitureGroup::getDTI() const {
    return cFurnitureGroup::DTI;
}

void cFurnitureGroup::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mID", &mID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraNo", &mCameraNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGmdIdx", &mGmdIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSortNo", &mSortNo, 0u, 0u);
}

MtUI* cFurnitureGroup::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cFurnitureGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFurnitureGroup::MyDTI cFurnitureGroup::DTI("cFurnitureGroup", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cFurnitureGroup::MyDTI::newInstance() const {
    return new (16u) cFurnitureGroup;
}

const MtDTI& cFurnitureItem::getDTI() const {
    return cFurnitureItem::DTI;
}

void cFurnitureItem::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mItemId", &mItemId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLayoutId", &mLayoutId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOmId", &mOmId, 0u, 0u);
}

MtUI* cFurnitureItem::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cFurnitureItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFurnitureItem::MyDTI cFurnitureItem::DTI("cFurnitureItem", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cFurnitureItem::MyDTI::newInstance() const {
    return new (16u) cFurnitureItem;
}

const MtDTI& cFurnitureLayout::getDTI() const {
    return cFurnitureLayout::DTI;
}

void cFurnitureLayout::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mID", &mID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsRemovable", &mIsRemovable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupId", &mGroupId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGmdIdx", &mGmdIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSortNo", &mSortNo, 0u, 0u);
}

MtUI* cFurnitureLayout::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cFurnitureLayout::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFurnitureLayout::MyDTI cFurnitureLayout::DTI("cFurnitureLayout", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cFurnitureLayout::MyDTI::newInstance() const {
    return new (16u) cFurnitureLayout;
}

const MtDTI& rFurnitureGroup::getDTI() const {
    return rFurnitureGroup::DTI;
}

bool rFurnitureGroup::loadData(MtDataReader& r, cFurnitureGroup* pData) {
    nDDOIO::readData(r, pData->mID);
    nDDOIO::readData(r, pData->mCameraNo);
    nDDOIO::readData(r, pData->mGmdIdx);
    nDDOIO::readData(r, pData->mSortNo);
    return true;
}

MT_CTSTR rFurnitureGroup::getExt() const {
    return "fng";
}

u32 rFurnitureGroup::getDataVersion() const {
    return 1;
}

inline rFurnitureGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFurnitureGroup::MyDTI rFurnitureGroup::DTI("rFurnitureGroup", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rFurnitureGroup::MyDTI::newInstance() const {
    return new (16u) rFurnitureGroup;
}

const MtDTI& rFurnitureItem::getDTI() const {
    return rFurnitureItem::DTI;
}

bool rFurnitureItem::loadData(MtDataReader& r, cFurnitureItem* pData) {
    nDDOIO::readData(r, pData->mItemId);
    nDDOIO::readData(r, pData->mLayoutId);
    nDDOIO::readData(r, pData->mOmId);
    return true;
}

MT_CTSTR rFurnitureItem::getExt() const {
    return "fni";
}

u32 rFurnitureItem::getDataVersion() const {
    return 1;
}

inline rFurnitureItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFurnitureItem::MyDTI rFurnitureItem::DTI("rFurnitureItem", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rFurnitureItem::MyDTI::newInstance() const {
    return new (16u) rFurnitureItem;
}

const MtDTI& rFurnitureLayout::getDTI() const {
    return rFurnitureLayout::DTI;
}

bool rFurnitureLayout::loadData(MtDataReader& r, cFurnitureLayout* pData) {
    nDDOIO::readData(r, pData->mID);
    nDDOIO::readData(r, pData->mIsRemovable);
    nDDOIO::readData(r, pData->mGroupId);
    nDDOIO::readData(r, pData->mGmdIdx);
    nDDOIO::readData(r, pData->mSortNo);
    return true;
}

MT_CTSTR rFurnitureLayout::getExt() const {
    return "fnl";
}

u32 rFurnitureLayout::getDataVersion() const {
    return 1;
}

inline rFurnitureLayout::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFurnitureLayout::MyDTI rFurnitureLayout::DTI("rFurnitureLayout", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rFurnitureLayout::MyDTI::newInstance() const {
    return new (16u) rFurnitureLayout;
}

template cFurnitureGroup* rTbl2<cFurnitureGroup>::getData(unsigned int);

template cFurnitureItem* rTbl2<cFurnitureItem>::getData(unsigned int);

template cFurnitureLayout* rTbl2<cFurnitureLayout>::getData(unsigned int);

template bool rTbl2<cFurnitureGroup>::load(MtStream&);

template bool rTbl2<cFurnitureItem>::load(MtStream&);

template bool rTbl2<cFurnitureLayout>::load(MtStream&);

template bool rTbl2<cFurnitureGroup>::loadCore(MtDataReader&);

template bool rTbl2<cFurnitureItem>::loadCore(MtDataReader&);

template bool rTbl2<cFurnitureLayout>::loadCore(MtDataReader&);

template const cFurnitureGroup* rTbl2<cFurnitureGroup>::getData(unsigned int) const;

template const cFurnitureItem* rTbl2<cFurnitureItem>::getData(unsigned int) const;

template const cFurnitureLayout* rTbl2<cFurnitureLayout>::getData(unsigned int) const;

template unsigned int rTbl2<cFurnitureGroup>::getDataNum() const;

template unsigned int rTbl2<cFurnitureItem>::getDataNum() const;

template unsigned int rTbl2<cFurnitureLayout>::getDataNum() const;

template rTbl2<cFurnitureGroup>::~rTbl2();

template rTbl2<cFurnitureItem>::~rTbl2();

template rTbl2<cFurnitureLayout>::~rTbl2();

