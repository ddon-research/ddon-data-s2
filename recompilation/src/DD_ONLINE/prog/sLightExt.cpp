// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "sLightExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cUnit.h"
#include "../../generated/shared/nDDOIO.h"
#include "nDDOUtility.h"
#include "rTable.h"
#include "sFlag.h"
#include "sGame.h"
#include "../../XFramework/sResource.h"
#include "../../XFramework/sUnit.h"
#include "sWeatherManager.h"
#include "../../XFramework/uLight.h"
#include "uLightExt.h"
#include "uSkyLight.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cActorLight::getDTI() const {
    return cActorLight::DTI;
}

s32 cActorLight::getStageNo() {
    return mStageNo;
}

void cActorLight::setStageNo(s32 no) {
    mStageNo = no;
}

void cActorLight::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "mStageNo", reinterpret_cast<MT_MFUNC>(&::cActorLight::getStageNo), reinterpret_cast<MT_MFUNC>(&::cActorLight::setStageNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mName", &mName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColor", &mColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBalance", &mBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ShadowGroup0", &mShadowAtten.x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ShadowGroup1", &mShadowAtten.y, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStart", &mStart, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnd", &mEnd, 0u, 0u);
}

MtUI* cActorLight::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cActorLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cActorLight::MyDTI cActorLight::DTI("cActorLight", &::MtObject::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cActorLight::MyDTI::newInstance() const {
    return new (16u) cActorLight;
}

const MtDTI& rActorLight::getDTI() const {
    return rActorLight::DTI;
}

const MtDTI& rActorLight::getDataDTI() {
    return cActorLight::DTI;
}

MT_CTSTR rActorLight::getExt() const {
    return "ali";
}

u16 rActorLight::getDataVersion() {
    return 1;
}

bool rActorLight::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    return loadData(r);
}

__attribute__((weak)) bool rActorLight::loadData(MtDataReader& in) {
    bool ret = false;
    u32 magic = in.readU32();
    u32 version = in.readU16();
    if (magic == rTable::mMagic && version == cActorLight::DATA_VERSION) {
        u32 dmy = in.readU16();
        u32 Num = in.readU32();
        for (u32 i = 0; i < Num; i++) {
            cActorLight* pObj = new (16u) cActorLight;
            if (pObj != nullptr) {
                if (loadData(in, pObj)) {
                    mArray.add(pObj);
                }
            }
        }
        ret = true;
    }
    return ret;
}

__attribute__((weak)) bool rActorLight::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    return saveData(w);
}

inline rActorLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rActorLight::MyDTI rActorLight::DTI("rActorLight", &::rTable::DTI, 176ul, 0u, 0u);

MtObject* rActorLight::MyDTI::newInstance() const {
    return new (16u) rActorLight;
}

const MtDTI& sLightExt::getDTI() const {
    return sLightExt::DTI;
}

void* sLightExt::operator new(size_t sz, u32 align) {
    return sLightExt::getAllocator()->memAlloc(sz, align, sLightExt::DTI.getID());
}

sLightExt::sLightExt() {
    sLightExt::mpInstance = this;
    mRno = 0;
    mbEnableActorLight2 = true;
    mbDispSunDir = false;
    mpuTargetModel = nullptr;
    mprActorLight = nullptr;
    mpuActorLight = nullptr;
    mZoneFadeFrame = 30.0f;
    mbIsEditRoom = false;
}

sLightExt::~sLightExt() {
    sLightExt::mpInstance = nullptr;
}

__attribute__((weak)) void sLightExt::reset() {
}

__attribute__((weak)) void sLightExt::move() {
    DDON_STUB("sLightExt::move")
    /* stub */
}

void sLightExt::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mbEnableActorLight2", &mbEnableActorLight2, 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mbDispSunDir", &mbDispSunDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpuActorLight", reinterpret_cast<MtObject* *>(&mpuActorLight), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mprActorLight", "resource", static_cast<void*>(&mprActorLight), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpuTargetModel", reinterpret_cast<MtObject* *>(&mpuTargetModel), 16u, 0u);
}

__attribute__((weak)) void sLightExt::stageInit(s32 bind_type) {
    DDON_STUB("sLightExt::stageInit")
    /* stub */
}

void sLightExt::stageFinal() {
    if (mpuActorLight != nullptr) {
        mpuActorLight->kill();
        mpuActorLight = nullptr;
    }
    if (mprActorLight == nullptr) {
        return;
    }
    mprActorLight->release();
    mprActorLight = nullptr;
}

void sLightExt::requestStateTransSpritDragon() {
    u32 v0_8 = mStateTransSpritDragonArray.mLength;
    if (v0_8 != 0) {
        for (u32 ArrayIdx = 0;;) {
            static_cast<cStateTransitionFromGameInfo*>(mStateTransSpritDragonArray.mpArray[ArrayIdx])->start();
            if (v0_8 != (ArrayIdx + 1u)) {
                ArrayIdx = ArrayIdx + 1u;
            } else {
                break;
            }
        }
    }
}

void sLightExt::forceStateTransEndSpritDragon() {
    u32 v0_8 = mStateTransSpritDragonArray.mLength;
    if (v0_8 != 0) {
        for (u32 ArrayIdx = 0;;) {
            static_cast<cStateTransitionFromGameInfo*>(mStateTransSpritDragonArray.mpArray[ArrayIdx])->forceEnd();
            if (v0_8 != (ArrayIdx + 1u)) {
                ArrayIdx = ArrayIdx + 1u;
            } else {
                break;
            }
        }
    }
}

void sLightExt::addStateTransSpritDragon(cStateTransitionFromGameInfo* pAdd) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        u32 t0 = mStateTransSpritDragonArray.mLength;
        u32 t1 = mStateTransSpritDragonArray.mBufsiz;
        if (t0 < t1) {
            mStateTransSpritDragonArray.mLength = t0 + 1u;
            mStateTransSpritDragonArray.mpArray[t0] = static_cast<MtObject*>(pAdd);
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
            memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
            memcpy(t2, static_cast<const void*>(mStateTransSpritDragonArray.mpArray), static_cast<size_t>(mStateTransSpritDragonArray.mLength) * 8);
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mStateTransSpritDragonArray.mpArray));
            mStateTransSpritDragonArray.mpArray = static_cast<MtObject* *>(t2);
            mStateTransSpritDragonArray.mBufsiz = t1 + 32u;
            u32 t3 = mStateTransSpritDragonArray.mLength;
            mStateTransSpritDragonArray.mLength = t3 + 1u;
            mStateTransSpritDragonArray.mpArray[t3] = static_cast<MtObject*>(pAdd);
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    } else {
        u32 t0 = mStateTransSpritDragonArray.mLength;
        u32 t1 = mStateTransSpritDragonArray.mBufsiz;
        if (t0 < t1) {
            mStateTransSpritDragonArray.mLength = t0 + 1u;
            mStateTransSpritDragonArray.mpArray[t0] = static_cast<MtObject*>(pAdd);
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
            memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
            memcpy(t2, static_cast<const void*>(mStateTransSpritDragonArray.mpArray), static_cast<size_t>(mStateTransSpritDragonArray.mLength) * 8);
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mStateTransSpritDragonArray.mpArray));
            mStateTransSpritDragonArray.mpArray = static_cast<MtObject* *>(t2);
            mStateTransSpritDragonArray.mBufsiz = t1 + 32u;
            u32 t3 = mStateTransSpritDragonArray.mLength;
            mStateTransSpritDragonArray.mLength = t3 + 1u;
            mStateTransSpritDragonArray.mpArray[t3] = static_cast<MtObject*>(pAdd);
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    }
}

__attribute__((weak)) void sLightExt::relStateTransSpritDragon(cStateTransitionFromGameInfo* pRel) {
    DDON_STUB("sLightExt::relStateTransSpritDragon")
    /* stub */
}

inline sLightExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sLightExt::MyDTI sLightExt::DTI("sLightExt", &::cSystem::DTI, 96ul, 0u, 0u);

sLightExt* sLightExt::mpInstance;

__attribute__((weak)) MtObject* sLightExt::MyDTI::newInstance() const {
    DDON_STUB("sLightExt::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cStateTransitionFromGameInfo>::~MtTypedArray();

