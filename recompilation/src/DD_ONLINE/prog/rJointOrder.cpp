// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rJointOrder.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cJointOrder>::allocData(unsigned int);
#endif

const MtDTI& cJointOrder::getDTI() const {
    return cJointOrder::DTI;
}

cJointOrder::~cJointOrder() {
    if (mpJointTable == nullptr) {
        return;
    }
    MtMemoryAllocator::getAllocator(cJointOrder::DTI)->memFree(static_cast<void*>(mpJointTable));
    mpJointTable = nullptr;
}

inline cJointOrder::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cJointOrder::MyDTI cJointOrder::DTI("cJointOrder", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cJointOrder::MyDTI::newInstance() const {
    return new (16u) cJointOrder;
}

const MtDTI& rJointOrder::getDTI() const {
    return rJointOrder::DTI;
}

rJointOrder::~rJointOrder() {
}

bool rJointOrder::loadData(MtDataReader& r, cJointOrder* pData) {
    u8* t0 = pData->mpJointTable;
    if (t0 != nullptr) {
        pData->mNum = 0;
        MtAllocator* t1 = MtMemoryAllocator::getAllocator(cJointOrder::DTI);
        unsigned long t3 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t1) + 0);
        u8* t4 = pData->mpJointTable;
        t1->memFree(static_cast<void*>(t4));
        pData->mpJointTable = nullptr;
        u32 t6 = r.readU32();
        pData->mNum = t6;
        MtAllocator* t8 = MtMemoryAllocator::getAllocator(cJointOrder::DTI);
        unsigned long t10 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 0);
        u32 t11 = pData->mNum;
        void* t12 = t8->memAlloc(t11, 16u);
        if ((pData->mpJointTable = static_cast<u8*>(t12)) != nullptr) {
            u32 t14 = pData->mNum;
            void* t15 = memset(t12, 0, t14);
            if (pData->mNum == 0) {
                return true;
            }
        } else {
            pData->mNum = 0;
            return false;
        }
    } else {
        u32 t6 = r.readU32();
        pData->mNum = t6;
        MtAllocator* t8 = MtMemoryAllocator::getAllocator(cJointOrder::DTI);
        unsigned long t10 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t8) + 0);
        u32 t11 = pData->mNum;
        void* t12 = t8->memAlloc(t11, 16u);
        if ((pData->mpJointTable = static_cast<u8*>(t12)) != nullptr) {
            u32 t14 = pData->mNum;
            void* t15 = memset(t12, 0, t14);
            if (pData->mNum == 0) {
                return true;
            }
        } else {
            pData->mNum = 0;
            return false;
        }
    }
    u32 i = 0;
    do {
        u8* t17 = pData->mpJointTable;
        u32 t18 = r.mSeekPt;
        u32 t19 = r.mBufsiz;
        if (t18 >= t19) {
            bool t20 = r.refill();
            if (t20) {
                u32 t22 = r.mSeekPt;
                u8* t23 = r.mBuffer;
                u8 t24 = t23[r.mSeekPt];
                r.mSeekPt = t22 + 1u;
                t17[i] = t24;
            } else {
                t17[i] = 0;
            }
        } else {
            u8* t23 = r.mBuffer;
            u8 t24 = t23[r.mSeekPt];
            r.mSeekPt = t18 + 1u;
            t17[i] = t24;
        }
        i += 1u;
    } while (i < pData->mNum);
    return true;
}

MT_CTSTR rJointOrder::getExt() const {
    return "jnt_order";
}

u32 rJointOrder::getDataVersion() const {
    return 3;
}

__attribute__((weak)) bool rJointOrder::loadCore(MtDataReader& r) {
        u32 dat_num;
        this->::rTbl2Base::readDataValue(r, dat_num);
        u32 t0 = dat_num;
        if (this->mpData != nullptr) {
            size_t* t1 = reinterpret_cast<size_t*>(this->mpData) - 1;
            cJointOrder* t9 = this->mpData;
            cJointOrder* t7 = t9 + *t1;
            while (t7 != t9) {
                --t7;
                t7->cJointOrder::~cJointOrder();
            }
            MtMemoryAllocator::getAllocator(cJointOrder::DTI)->memFree(t1);
            this->mpData = nullptr;
        }
        this->mDataNum = 0;
        if (t0 != 0) {
            size_t t2 = t0;
            size_t t6 = t2 * sizeof(cJointOrder) + sizeof(size_t);
            size_t* t3 = static_cast<size_t*>(MtMemoryAllocator::getAllocator(cJointOrder::DTI)->memAlloc(t6, 16u, cJointOrder::DTI.getID()));
            *t3 = t2;
            cJointOrder* t4 = reinterpret_cast<cJointOrder*>(t3 + 1);
            cJointOrder* t5 = t4;
            do {
                new (t5) cJointOrder;
                ++t5;
            } while (t5 != reinterpret_cast<cJointOrder*>(reinterpret_cast<char*>(t3) + t6));
            this->mpData = t4;
            this->mDataNum = t0;
        }
        if (dat_num != 0) {
            u32 i = 0;
            cJointOrder* p_dat = this->mpData;
            do {
                if (!this->loadData(r, &p_dat[i])) {
                    return false;
                }
                i += 1u;
            } while (i < dat_num);
        }
        return true;
}

inline rJointOrder::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rJointOrder::MyDTI rJointOrder::DTI("rJointOrder", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rJointOrder::MyDTI::newInstance() const {
    return new (16u) rJointOrder;
}

template cJointOrder* rTbl2<cJointOrder>::getData(unsigned int);

template bool rTbl2<cJointOrder>::load(MtStream&);

template bool rTbl2<cJointOrder>::loadCore(MtDataReader&);

template const cJointOrder* rTbl2<cJointOrder>::getData(unsigned int) const;

template unsigned int rTbl2<cJointOrder>::getDataNum() const;

template rTbl2<cJointOrder>::~rTbl2();

