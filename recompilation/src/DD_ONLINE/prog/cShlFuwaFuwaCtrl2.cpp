// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cShlFuwaFuwaCtrl2.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlFuwaFuwaCtrl2::getDTI() const {
    return cShlFuwaFuwaCtrl2::DTI;
}

inline void* cShlFuwaFuwaCtrl2::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlFuwaFuwaCtrl2::DTI)->memAlloc(sz, align, cShlFuwaFuwaCtrl2::DTI.getID());
}

inline void cShlFuwaFuwaCtrl2::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlFuwaFuwaCtrl2::DTI)->memFree(p_addr);
}

cShlFuwaFuwaCtrl2::cShlFuwaFuwaCtrl2() {
    mPos = MtVector3::Zero;
    mDisplace = MtVector3::Zero;
    mPeriodTimer = MtVector3::Zero;
    mPeriod = MtVector3::Zero;
    mScale = MtVector3::Zero;
    mInitPeriod = MtVector3::Zero;
    mInitScale = MtVector3::Zero;
    mInitRandom = MtVector3::Zero;
    mIsEnd = false;
    mInterFrame = 0.0f;
    mFuwaFuwaOption = 0;
    mSeqTimer = 0.0f;
    mInitInterFrame = 0.0f;
}

cShlFuwaFuwaCtrl2::~cShlFuwaFuwaCtrl2() {
}

__attribute__((weak)) void cShlFuwaFuwaCtrl2::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void cShlFuwaFuwaCtrl2::init(uShlBase* pShl, const cShlFuwaFuwaInfo2& srcInfo) {
    DDON_STUB("cShlFuwaFuwaCtrl2::init")
    /* stub */
}

__attribute__((weak)) void cShlFuwaFuwaCtrl2::updateFuwa(uShlBase* pShl, f32 deltaTime) {
    DDON_STUB("cShlFuwaFuwaCtrl2::updateFuwa")
    /* stub */
}

inline cShlFuwaFuwaCtrl2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlFuwaFuwaCtrl2::MyDTI cShlFuwaFuwaCtrl2::DTI("cShlFuwaFuwaCtrl2", &::MtObject::DTI, 192ul, 0u, 0u);

MtObject* cShlFuwaFuwaCtrl2::MyDTI::newInstance() const {
    return new (16u) cShlFuwaFuwaCtrl2;
}

const MtDTI& cShlFuwaFuwaInfo2::getDTI() const {
    return cShlFuwaFuwaInfo2::DTI;
}

inline void* cShlFuwaFuwaInfo2::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlFuwaFuwaInfo2::DTI)->memAlloc(sz, align, cShlFuwaFuwaInfo2::DTI.getID());
}

inline void cShlFuwaFuwaInfo2::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShlFuwaFuwaInfo2::DTI)->memFree(p_addr);
}

cShlFuwaFuwaInfo2::cShlFuwaFuwaInfo2() {
    mInterFrame = 0.0f;
    mFuwaFuwaOption = 0;
    mRandom = 0.0f;
    mTime = 0.0f;
    mPeriod = 0.0f;
    mScale = 0.0f;
}

cShlFuwaFuwaInfo2::~cShlFuwaFuwaInfo2() {
}

void cShlFuwaFuwaInfo2::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\345\221\250\346\234\237", &mPeriod, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\271\343\202\261\343\203\274\343\203\253", &mScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\251\343\203\263\343\203\200\343\203\240", &mRandom, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\234\211\345\212\271\346\231\202\351\226\223", &mTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\243\234\351\226\223\343\203\225\343\203\254\343\203\274\343\203\240", &mInterFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\201\265\343\202\217\343\201\265\343\202\217\343\202\252\343\203\227\343\202\267\343\203\247\343\203\263", &mFuwaFuwaOption, 0u, 0u);
}

__attribute__((weak)) void cShlFuwaFuwaInfo2::copy(const cShlFuwaFuwaInfo2& srcInfo) {
    DDON_STUB("cShlFuwaFuwaInfo2::copy")
    /* stub */
}

inline cShlFuwaFuwaInfo2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlFuwaFuwaInfo2::MyDTI cShlFuwaFuwaInfo2::DTI("cShlFuwaFuwaInfo2", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cShlFuwaFuwaInfo2::MyDTI::newInstance() const {
    return new (16u) cShlFuwaFuwaInfo2;
}

