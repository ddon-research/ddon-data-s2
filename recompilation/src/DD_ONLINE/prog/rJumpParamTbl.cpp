// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rJumpParamTbl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cJumpParam>::allocData(unsigned int);
#endif

const MtDTI& cJumpParam::getDTI() const {
    return cJumpParam::DTI;
}

inline void* cJumpParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cJumpParam::DTI)->memAlloc(sz, align, cJumpParam::DTI.getID());
}

cJumpParam::cJumpParam() {
    mSpeedY = 20.0f;
    mSpeedZ = 10.0f;
    mGravity = -2.205f;
    mAddMoveSpeedXZ = 0.0f;
    mDampingZ = 0.0f;
    mIsAwakening = false;
    mAwakeJumpAdd = 3.95f;
}

cJumpParam::~cJumpParam() {
}

void cJumpParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSpeedY", &mSpeedY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpeedZ", &mSpeedZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGravity", &mGravity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAddMoveSpeedXZ", &mAddMoveSpeedXZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDampingZ", &mDampingZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsAwakening", &mIsAwakening, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAwakeJumpAdd", &mAwakeJumpAdd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mComment", &mComment, 256u, 0u);
}

inline cJumpParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cJumpParam::MyDTI cJumpParam::DTI("cJumpParam", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cJumpParam::MyDTI::newInstance() const {
    return new (16u) cJumpParam;
}

const MtDTI& rJumpParamTbl::getDTI() const {
    return rJumpParamTbl::DTI;
}

inline void* rJumpParamTbl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rJumpParamTbl::DTI)->memAlloc(sz, align, rJumpParamTbl::DTI.getID());
}

bool rJumpParamTbl::loadData(MtDataReader& in, cJumpParam* pData) {
    if (pData != nullptr) {
        f32 t0 = in.readF32();
        pData->mSpeedY = t0;
        f32 t1 = in.readF32();
        pData->mSpeedZ = t1;
        f32 t2 = in.readF32();
        pData->mGravity = t2;
        f32 t3 = in.readF32();
        pData->mDampingZ = t3;
        f32 t4 = in.readF32();
        pData->mAddMoveSpeedXZ = t4;
        u32 t5 = in.mSeekPt;
        u32 t6 = in.mBufsiz;
        if (t5 >= t6) {
            if (in.refill()) {
                u32 t8 = in.mSeekPt;
                u8* t9 = in.mBuffer;
                u8 t10 = t9[in.mSeekPt];
                in.mSeekPt = t8 + 1u;
                pData->mIsAwakening = t10 != 0;
                f32 t12 = in.readF32();
                pData->mAwakeJumpAdd = t12;
                return true;
            } else {
                pData->mIsAwakening = false;
                f32 t12 = in.readF32();
                pData->mAwakeJumpAdd = t12;
                return true;
            }
        } else {
            u8* t9 = in.mBuffer;
            u8 t10 = t9[in.mSeekPt];
            in.mSeekPt = t5 + 1u;
            pData->mIsAwakening = t10 != 0;
            f32 t12 = in.readF32();
            pData->mAwakeJumpAdd = t12;
            return true;
        }
    } else {
        return false;
    }
}

MT_CTSTR rJumpParamTbl::getExt() const {
    return "jmp";
}

u32 rJumpParamTbl::getDataVersion() const {
    return 3;
}

inline rJumpParamTbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rJumpParamTbl::MyDTI rJumpParamTbl::DTI("rJumpParamTbl", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rJumpParamTbl::MyDTI::newInstance() const {
    return new (16u) rJumpParamTbl;
}

template cJumpParam* rTbl2<cJumpParam>::getData(unsigned int);

template bool rTbl2<cJumpParam>::load(MtStream&);

template bool rTbl2<cJumpParam>::loadCore(MtDataReader&);

template const cJumpParam* rTbl2<cJumpParam>::getData(unsigned int) const;

template unsigned int rTbl2<cJumpParam>::getDataNum() const;

template rTbl2<cJumpParam>::~rTbl2();

