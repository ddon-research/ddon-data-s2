// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCameraQuakeList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "uCameraBase.h"
#include "uCameraGame.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuakeParam::getDTI() const {
    return cQuakeParam::DTI;
}

cQuakeParam::~cQuakeParam() {
}

MtUI* cQuakeParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cQuakeParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mName", &mName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeadTime", &mHeadTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMainTime", &mMainTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTailTime", &mTailTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMagnitude", &mMagnitude, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRadius", &mRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpread", &mSpread, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDamping", &mDamping, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPeriod", &mPeriod, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRoll", &mRoll, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBalance", &mBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mbAsync", &mbAsync, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCamera1QuakeTime", &mCamera1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTarget1QuakeTime", &mTarget1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRoll1QuakeTime", &mRoll1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRandDrop", &mRandDrop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeadCurve", &mHeadCurve, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTailCurve", &mTailCurve, 0u, 0u);
}

void cQuakeParam::createPropertyTool(MtPropertyList& s) {
    createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "Start", reinterpret_cast<MT_MFUNC32>(&::cQuakeParam::QuakeStart), 0u, 15u);
    s << MtProperty(static_cast<MtObject*>(this), "Cancel", reinterpret_cast<MT_MFUNC32>(&::cQuakeParam::QuakeCancel), 0u, 15u);
}

void cQuakeParam::QuakeStart(uintptr task) const {
    uCameraGame* t0 = static_cast<sCameraExt*>(sCamera::getInstance())->getGameCamera();
    if (t0 == nullptr) {
        return;
    }
    t0->mQuake.set(task, mHeadTime, mMainTime, mTailTime, mMagnitude, mPos, mRadius, mSpread, mDamping, mPeriod, mCamera1QuakeTime, mTarget1QuakeTime, mRoll1QuakeTime, mRandDrop, static_cast<cCameraQuake::EASE_TYPE>(mHeadCurve), static_cast<cCameraQuake::EASE_TYPE>(mTailCurve), mRoll, mBalance, mbAsync);
}

void cQuakeParam::QuakeStartPos(uintptr task, const MtVector3& pos) const {
    uCameraGame* pCam = static_cast<sCameraExt*>(sCamera::getInstance())->getGameCamera();
    if (pCam == nullptr) {
        return;
    }
    pCam->mQuake.set(task, mHeadTime, mMainTime, mTailTime, mMagnitude, pos, mRadius, mSpread, mDamping, mPeriod, mCamera1QuakeTime, mTarget1QuakeTime, mRoll1QuakeTime, mRandDrop, static_cast<cCameraQuake::EASE_TYPE>(mHeadCurve), static_cast<cCameraQuake::EASE_TYPE>(mTailCurve), mRoll, mBalance, mbAsync);
}

void cQuakeParam::QuakeCancel(uintptr task) const {
    uCameraGame* pCam = static_cast<sCameraExt*>(sCamera::getInstance())->getGameCamera();
    if (pCam == nullptr) {
        return;
    }
    pCam->mQuake.del(task, false);
}

inline cQuakeParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuakeParam::MyDTI cQuakeParam::DTI("cQuakeParam", &::MtObject::DTI, 128ul, 0u, 0u);

MtObject* cQuakeParam::MyDTI::newInstance() const {
    return new (16u) cQuakeParam;
}

const MtDTI& rCameraQuakeList::getDTI() const {
    return rCameraQuakeList::DTI;
}

rCameraQuakeList::~rCameraQuakeList() {
    if (mQuakeList.mLength != 0) {
        u32 v0_0 = mQuakeList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mQuakeList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mQuakeList.mpArray[i0_3];
                v1_0 = mQuakeList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mQuakeList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mQuakeList.mpArray));
    }
    mQuakeList.mpArray = nullptr;
    mQuakeList.mBufsiz = 0;
    mQuakeList.mLength = 0;
}

void rCameraQuakeList::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mQuakeList", static_cast<MtObject*>(&mQuakeList), 0u, 0u);
}

__attribute__((weak)) void rCameraQuakeList::clear() {
}

bool rCameraQuakeList::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(1), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rCameraQuakeList::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(1), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rCameraQuakeList::DTI));
}

MT_CTSTR rCameraQuakeList::getExt() const {
    return "cql";
}

inline rCameraQuakeList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCameraQuakeList::MyDTI rCameraQuakeList::DTI("rCameraQuakeList", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rCameraQuakeList::MyDTI::newInstance() const {
    return new (16u) rCameraQuakeList;
}

