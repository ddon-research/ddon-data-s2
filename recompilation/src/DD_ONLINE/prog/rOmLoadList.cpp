// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rOmLoadList.h"
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
extern template __attribute__((noinline)) void rTbl2<cOmLoadList>::deleteData();
#endif

const MtDTI& cOmLoadList::getDTI() const {
    return cOmLoadList::DTI;
}

cOmLoadList::~cOmLoadList() {
    if (mOmList.mLength != 0) {
        u32 v0_0 = mOmList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mOmList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mOmList.mpArray[i0_3];
                v1_0 = mOmList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mOmList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mOmList.mpArray));
    }
    mOmList.mpArray = nullptr;
    mOmList.mBufsiz = 0;
    mOmList.mLength = 0;
}

void cOmLoadList::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartPos", &mStartPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOmList", static_cast<MtObject*>(&mOmList), 0u, 0u);
}

inline cOmLoadList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOmLoadList::MyDTI cOmLoadList::DTI("cOmLoadList", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cOmLoadList::MyDTI::newInstance() const {
    return new (16u) cOmLoadList;
}

const MtDTI& cOmLoadList::cOmList::getDTI() const {
    return cOmLoadList::cOmList::DTI;
}

void cOmLoadList::cOmList::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mOmId", &mOmId, 0u, 0u);
}

inline cOmLoadList::cOmList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOmLoadList::cOmList::MyDTI cOmLoadList::cOmList::DTI("cOmLoadList::cOmList", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cOmLoadList::cOmList::MyDTI::newInstance() const {
    return new (16u) cOmLoadList::cOmList;
}

const MtDTI& rOmLoadList::getDTI() const {
    return rOmLoadList::DTI;
}

rOmLoadList::~rOmLoadList() {
}

__attribute__((weak)) bool rOmLoadList::loadData(MtDataReader& in, cOmLoadList* pData) {
    DDON_STUB("rOmLoadList::loadData")
    return {};
}

MT_CTSTR rOmLoadList::getExt() const {
    return "oll";
}

u32 rOmLoadList::getDataVersion() const {
    return 2;
}

cOmLoadList* rOmLoadList::searchData(s32 stageNo, s32 startPos) {
    cOmLoadList* v2_0;
    if ((stageNo | startPos) <= -1) {
        v2_0 = nullptr;
    } else {
        if (getDataNum() == 0) {
            v2_0 = nullptr;
        } else {
            for (unsigned int i0_2 = 0;;) {
                cOmLoadList* t0 = getData(i0_2);
                if (t0 != nullptr) {
                    if (t0->mStageNo == stageNo) {
                        if (t0->mStartPos == startPos) {
                            v2_0 = t0;
                            break;
                        }
                    }
                }
                if ((i0_2 + 1u) < getDataNum()) {
                    i0_2 += 1u;
                } else {
                    v2_0 = nullptr;
                    break;
                }
            }
        }
    }
    return v2_0;
}

inline rOmLoadList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rOmLoadList::MyDTI rOmLoadList::DTI("rOmLoadList", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rOmLoadList::MyDTI::newInstance() const {
    return new (16u) rOmLoadList;
}

template MtTypedArray<cOmLoadList::cOmList>::~MtTypedArray();

template cOmLoadList* rTbl2<cOmLoadList>::getData(unsigned int);

template bool rTbl2<cOmLoadList>::load(MtStream&);

template bool rTbl2<cOmLoadList>::loadCore(MtDataReader&);

template const cOmLoadList* rTbl2<cOmLoadList>::getData(unsigned int) const;

template unsigned int rTbl2<cOmLoadList>::getDataNum() const;

template rTbl2<cOmLoadList>::~rTbl2();

