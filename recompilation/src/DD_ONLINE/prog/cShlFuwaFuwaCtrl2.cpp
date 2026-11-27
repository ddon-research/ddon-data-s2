// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cShlFuwaFuwaCtrl2.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
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
    s << MtProperty(static_cast<MtObject*>(this), "周期", &mPeriod, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "スケール", &mScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ランダム", &mRandom, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "有効時間", &mTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "補間フレーム", &mInterFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ふわふわオプション", &mFuwaFuwaOption, 0u, 0u);
}

void cShlFuwaFuwaInfo2::copy(const cShlFuwaFuwaInfo2& srcInfo) {
    mPeriod = srcInfo.mPeriod;
    mScale = srcInfo.mScale;
    mRandom = srcInfo.mRandom;
    mTime = srcInfo.mTime;
    mInterFrame = srcInfo.mInterFrame;
    mFuwaFuwaOption = srcInfo.mFuwaFuwaOption;
}

inline cShlFuwaFuwaInfo2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlFuwaFuwaInfo2::MyDTI cShlFuwaFuwaInfo2::DTI("cShlFuwaFuwaInfo2", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cShlFuwaFuwaInfo2::MyDTI::newInstance() const {
    return new (16u) cShlFuwaFuwaInfo2;
}

