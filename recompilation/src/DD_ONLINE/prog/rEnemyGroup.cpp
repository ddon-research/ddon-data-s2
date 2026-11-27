// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEnemyGroup.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cEnemyGroup>::deleteData();
#endif

const MtDTI& cEnemyGroup::getDTI() const {
    return cEnemyGroup::DTI;
}

cEnemyGroup::~cEnemyGroup() {
    if (mEmList.mLength != 0) {
        u32 v0_0 = mEmList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mEmList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mEmList.mpArray[i0_3];
                v1_0 = mEmList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mEmList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mEmList.mpArray));
    }
    mEmList.mpArray = nullptr;
    mEmList.mBufsiz = 0;
    mEmList.mLength = 0;
}

void cEnemyGroup::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEnemyGroupId", &mEnemyGroupId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgIndex", &mMsgIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEmList", static_cast<MtObject*>(&mEmList), 0u, 0u);
}

inline cEnemyGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEnemyGroup::MyDTI cEnemyGroup::DTI("cEnemyGroup", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cEnemyGroup::MyDTI::newInstance() const {
    return new (16u) cEnemyGroup;
}

const MtDTI& cEnemyGroup::cEmList::getDTI() const {
    return cEnemyGroup::cEmList::DTI;
}

void cEnemyGroup::cEmList::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEmId", &mEmId, 0u, 0u);
}

inline cEnemyGroup::cEmList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEnemyGroup::cEmList::MyDTI cEnemyGroup::cEmList::DTI("cEnemyGroup::cEmList", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cEnemyGroup::cEmList::MyDTI::newInstance() const {
    return new (16u) cEnemyGroup::cEmList;
}

const MtDTI& rEnemyGroup::getDTI() const {
    return rEnemyGroup::DTI;
}

__attribute__((weak)) bool rEnemyGroup::loadData(MtDataReader& in, cEnemyGroup* pData) {
    if (pData == nullptr) {
        return false;
    }
    pData->mEnemyGroupId = in.readU32();
    pData->mMsgIndex = in.readU32();
    const u32 nArray = in.readU32();
    for (u32 i = 0; i < nArray; ++i) {
        cEnemyGroup::cEmList* p = new (16u) cEnemyGroup::cEmList;
        if (p != nullptr) {
            p->load(in);
            pData->addEmList(p);
        }
    }
    return true;
}

MT_CTSTR rEnemyGroup::getExt() const {
    return "emg";
}

u32 rEnemyGroup::getDataVersion() const {
    return 1;
}

inline rEnemyGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEnemyGroup::MyDTI rEnemyGroup::DTI("rEnemyGroup", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEnemyGroup::MyDTI::newInstance() const {
    return new (16u) rEnemyGroup;
}

template MtTypedArray<cEnemyGroup::cEmList>::~MtTypedArray();

template cEnemyGroup* rTbl2<cEnemyGroup>::getData(unsigned int);

template bool rTbl2<cEnemyGroup>::load(MtStream&);

template bool rTbl2<cEnemyGroup>::loadCore(MtDataReader&);

template const cEnemyGroup* rTbl2<cEnemyGroup>::getData(unsigned int) const;

template unsigned int rTbl2<cEnemyGroup>::getDataNum() const;

template rTbl2<cEnemyGroup>::~rTbl2();

