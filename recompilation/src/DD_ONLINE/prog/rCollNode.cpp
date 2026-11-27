// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCollNode.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rCollGeom.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cCollNode>::allocData(unsigned int);
#endif

const MtDTI& cCollNode::getDTI() const {
    return cCollNode::DTI;
}

cCollNode::~cCollNode() {
    if (mpCollGeom == nullptr) {
        return;
    }
    mpCollGeom->release();
    mpCollGeom = nullptr;
}

void cCollNode::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpCollGeom", reinterpret_cast<MtObject* *>(&mpCollGeom), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttr", &mAttr, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColNodeFlag", &mColNodeFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHitCollisionFlag", &mHitCollisionFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNodeID", &mNodeID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 1u, 0u);
}

inline cCollNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCollNode::MyDTI cCollNode::DTI("cCollNode", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cCollNode::MyDTI::newInstance() const {
    return new (16u) cCollNode;
}

const MtDTI& rCollNode::getDTI() const {
    return rCollNode::DTI;
}

void* rCollNode::operator new(size_t sz, u32 align) {
    return rCollNode::getAllocator()->memAlloc(sz, align, rCollNode::DTI.getID());
}

rCollNode::~rCollNode() {
}

__attribute__((weak)) bool rCollNode::loadData(MtDataReader& in, cCollNode* pData) {
    if (pData->mpCollGeom != nullptr) {
        pData->mpCollGeom->release();
        pData->mpCollGeom = nullptr;
    }
    pData->mpCollGeom = new (16u) rCollGeom;
    if (pData->mpCollGeom != nullptr) {
        if (!pData->mpCollGeom->loadRoot(in)) {
            return false;
        }
    }
    nDDOIO::readData(in, pData->mAttr);
    nDDOIO::readData(in, pData->mNodeID);
    nDDOIO::readData(in, pData->mIndex);
    nDDOIO::readData(in, pData->mColNodeFlag);
    nDDOIO::readData(in, pData->mHitCollisionFlag);
    return true;
}

MT_CTSTR rCollNode::getExt() const {
    return "coll_node";
}

u32 rCollNode::getDataVersion() const {
    return 110;
}

__attribute__((weak)) bool rCollNode::loadCore(MtDataReader& r) {
    u32 dat_num;
    this->::rTbl2Base::readDataValue(r, dat_num);
    u32 t0 = dat_num;
    if (this->mpData != nullptr) {
        delete[] this->mpData;
        this->mpData = nullptr;
    }
    this->mDataNum = 0;
    if (t0 != 0) {
        this->mpData = new (16u) cCollNode[t0];
        this->mDataNum = t0;
    }
    if (dat_num != 0) {
        u32 i = 0;
        cCollNode* p_dat = this->mpData;
        do {
            if (!this->loadData(r, &p_dat[i])) {
                return false;
            }
            i += 1u;
        } while (i < dat_num);
    }
    return true;
}

inline rCollNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCollNode::MyDTI rCollNode::DTI("rCollNode", &::rTbl2Base::DTI, 160ul, 0u, 0u);

MtObject* rCollNode::MyDTI::newInstance() const {
    return new (16u) rCollNode;
}

template cCollNode* rTbl2<cCollNode>::getData(unsigned int);

template bool rTbl2<cCollNode>::load(MtStream&);

template bool rTbl2<cCollNode>::loadCore(MtDataReader&);

template const cCollNode* rTbl2<cCollNode>::getData(unsigned int) const;

template unsigned int rTbl2<cCollNode>::getDataNum() const;

template rTbl2<cCollNode>::~rTbl2();

