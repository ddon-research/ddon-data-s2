// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlIntervalHit.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "cpObjCollision.h"
#include "nDDOUtility.h"
#include "rObjCollision.h"
#include "../../XFramework/sMain.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlStick.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::DTI)->memAlloc(sz, align, cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::DTI.getID());
}

inline void cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::getDTI() const {
    return cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::DTI;
}

void cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::createProperty(MtPropertyList& proplist) {
    this->::cShlParamBase::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHitInterVal", reinterpret_cast<s32*>(&mHitInterVal), 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mSeNo", &mSeNo, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mEfNo", &mEfNo, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mColNo", &mColNo, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mIsUseRandamInterVal", &mIsUseRandamInterVal, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[0]", &mRandamInterVal.elems[0], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[1]", &mRandamInterVal.elems[1], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[2]", &mRandamInterVal.elems[2], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[3]", &mRandamInterVal.elems[3], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[4]", &mRandamInterVal.elems[4], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[5]", &mRandamInterVal.elems[5], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[6]", &mRandamInterVal.elems[6], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[7]", &mRandamInterVal.elems[7], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[8]", &mRandamInterVal.elems[8], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[9]", &mRandamInterVal.elems[9], 0, 0);
}

inline cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::MyDTI cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::DTI("cShlParamIntervalHitBase", &::cShlParamBase::DTI, 416ul, 0u, 0u);

MtObject* cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::MyDTI::newInstance() const {
    return new (16u) cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>;
}

inline void* cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::DTI)->memAlloc(sz, align, cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::DTI.getID());
}

inline void cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::DTI)->memFree(p_addr);
}

const MtDTI& cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::getDTI() const {
    return cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::DTI;
}

void cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::createProperty(MtPropertyList& proplist) {
    this->::cShlParamStick::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "mHitInterVal", reinterpret_cast<s32*>(&mHitInterVal), 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mSeNo", &mSeNo, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mEfNo", &mEfNo, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mColNo", &mColNo, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mIsUseRandamInterVal", &mIsUseRandamInterVal, 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[0]", &mRandamInterVal.elems[0], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[1]", &mRandamInterVal.elems[1], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[2]", &mRandamInterVal.elems[2], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[3]", &mRandamInterVal.elems[3], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[4]", &mRandamInterVal.elems[4], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[5]", &mRandamInterVal.elems[5], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[6]", &mRandamInterVal.elems[6], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[7]", &mRandamInterVal.elems[7], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[8]", &mRandamInterVal.elems[8], 0, 0);
    proplist << MtProperty(static_cast<MtObject*>(this), "mRandamInterVal[9]", &mRandamInterVal.elems[9], 0, 0);
}

inline cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::MyDTI cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::DTI("cShlParamIntervalHitStick", &::cShlParamStick::DTI, 416ul, 0u, 0u);

MtObject* cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::MyDTI::newInstance() const {
    return new (16u) cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>;
}

template const MtDTI& uShlIntervalHit<uShlBase>::getDTI() const;

template const MtDTI& uShlIntervalHit<uShlStick>::getDTI() const;

template uShlIntervalHit<uShlBase>::~uShlIntervalHit();

template uShlIntervalHit<uShlStick>::~uShlIntervalHit();

