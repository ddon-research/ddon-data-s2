// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rWeatherScript.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtRandom.h"
#include "cResPath.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "nDDOUtility.h"
#include "nWeather.h"
#include "rEffectProvider.h"
#include "../../XFramework/rSoundRequest.h"
#include "res_ptr.h"
#include "sArchiveManager.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cWSCEpv::getDTI() const {
    return cWSCEpv::DTI;
}

void cWSCEpv::setupCmd(cWeatherScriptIO& io) const {
    cWSCParam* p_param = io.getWSCParam(static_cast<const void*>(this));
    if (p_param == nullptr) {
        return;
    }
    cResource* p_res = sArchiveManager::getInstance()->createRes(mResource.getResId(), 1u, false);
    p_param->mpRes.cResPtrBase::setPtr(p_param->mpRes.mpPtr, p_res);
    if (p_res == nullptr) {
        return;
    }
    p_res->release();
}

__attribute__((weak)) bool cWSCEpv::updateCmd(cWeatherScriptIO& io) const {
    DDON_STUB("cWSCEpv::updateCmd")
    return {};
}

__attribute__((weak)) void cWSCEpv::endCmd(cWeatherScriptIO& io) const {
    DDON_STUB("cWSCEpv::endCmd")
    /* stub */
}

void cWSCEpv::load(MtDataReader& r) {
    this->cWeatherScriptCmd::load(r);
    nDDOIO::readData(r, mResource);
    nDDOIO::readData(r, mIndexNo);
    nDDOIO::readData(r, mElementNo);
}

inline cWSCEpv::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWSCEpv::MyDTI cWSCEpv::DTI("cWSCEpv", &::cWeatherScriptCmd::DTI, 96ul, 0u, 0u);

MtObject* cWSCEpv::MyDTI::newInstance() const {
    return new (16u) cWSCEpv;
}

const MtDTI& cWSCParam::getDTI() const {
    return cWSCParam::DTI;
}

cWSCParam::~cWSCParam() {
    DDON_STUB("cWSCParam::~cWSCParam")
    /* stub */
}

inline cWSCParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWSCParam::MyDTI cWSCParam::DTI("cWSCParam", &::cWeatherObjectSys::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cWSCParam::MyDTI::newInstance() const {
    DDON_STUB("cWSCParam::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cWSCSound::getDTI() const {
    return cWSCSound::DTI;
}

void cWSCSound::setupCmd(cWeatherScriptIO& io) const {
    cWSCParam* p_param = io.getWSCParam(static_cast<const void*>(this));
    if (p_param == nullptr) {
        return;
    }
    cResource* p_res = sArchiveManager::getInstance()->createRes(mResource.getResId(), 1u, false);
    p_param->mpRes.cResPtrBase::setPtr(p_param->mpRes.mpPtr, p_res);
    if (p_res != nullptr) {
        p_res->release();
    }
    p_param->mFree.elems[0] = 0;
    p_param->mFreeF32 = 0.0f;
}

__attribute__((weak)) bool cWSCSound::updateCmd(cWeatherScriptIO& io) const {
    DDON_STUB("cWSCSound::updateCmd")
    return {};
}

__attribute__((weak)) void cWSCSound::endCmd(cWeatherScriptIO& io) const {
    DDON_STUB("cWSCSound::endCmd")
    /* stub */
}

void cWSCSound::load(MtDataReader& r) {
    this->cWeatherScriptCmd::load(r);
    nDDOIO::readData(r, mResource);
    nDDOIO::readData(r, mReqNo);
    nDDOIO::readData(r, mReqType);
}

inline cWSCSound::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWSCSound::MyDTI cWSCSound::DTI("cWSCSound", &::cWeatherScriptCmd::DTI, 96ul, 0u, 0u);

MtObject* cWSCSound::MyDTI::newInstance() const {
    return new (16u) cWSCSound;
}

const MtDTI& cWSCSoundRnd::getDTI() const {
    return cWSCSoundRnd::DTI;
}

void cWSCSoundRnd::setupCmd(cWeatherScriptIO& io) const {
    cWSCParam* p_param = io.getWSCParam(static_cast<const void*>(this));
    if (p_param == nullptr) {
        return;
    }
    cResource* p_res = sArchiveManager::getInstance()->createRes(mResource.getResId(), 1u, false);
    p_param->mpRes.cResPtrBase::setPtr(p_param->mpRes.mpPtr, p_res);
    if (p_res == nullptr) {
        return;
    }
    p_res->release();
}

__attribute__((weak)) bool cWSCSoundRnd::updateCmd(cWeatherScriptIO& io) const {
    DDON_STUB("cWSCSoundRnd::updateCmd")
    return {};
}

__attribute__((weak)) void cWSCSoundRnd::endCmd(cWeatherScriptIO& io) const {
    DDON_STUB("cWSCSoundRnd::endCmd")
    /* stub */
}

void cWSCSoundRnd::load(MtDataReader& r) {
    this->cWeatherScriptCmd::load(r);
    mResource.mId = r.readU64();
    mReqFrame = r.readF32();
    mReqNos.elems[0] = r.readU32();
    mReqNos.elems[1] = r.readU32();
    mReqNos.elems[2] = r.readU32();
    mReqNos.elems[3] = r.readU32();
}

inline cWSCSoundRnd::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWSCSoundRnd::MyDTI cWSCSoundRnd::DTI("cWSCSoundRnd", &::cWeatherScriptCmd::DTI, 112ul, 0u, 0u);

MtObject* cWSCSoundRnd::MyDTI::newInstance() const {
    return new (16u) cWSCSoundRnd;
}

const MtDTI& cWSCSoundVolume::getDTI() const {
    return cWSCSoundVolume::DTI;
}

__attribute__((weak)) void cWSCSoundVolume::setupCmd(cWeatherScriptIO& io) const {
}

bool cWSCSoundVolume::updateCmd(cWeatherScriptIO& io) const {
    io.mRetSoundVolumeSub = mSoundVolume;
    return false;
}

__attribute__((weak)) void cWSCSoundVolume::endCmd(cWeatherScriptIO& io) const {
    DDON_STUB("cWSCSoundVolume::endCmd")
    /* stub */
}

void cWSCSoundVolume::load(MtDataReader& r) {
    this->cWeatherScriptCmd::load(r);
    nDDOIO::readData(r, mSoundVolume);
}

inline cWSCSoundVolume::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWSCSoundVolume::MyDTI cWSCSoundVolume::DTI("cWSCSoundVolume", &::cWeatherScriptCmd::DTI, 88ul, 0u, 0u);

MtObject* cWSCSoundVolume::MyDTI::newInstance() const {
    return new (16u) cWSCSoundVolume;
}

const MtDTI& cWSCTimer::getDTI() const {
    return cWSCTimer::DTI;
}

bool cWSCTimer::updateCmd(cWeatherScriptIO& io) const {
    return 0.0f >= mEndFrame;
}

inline cWSCTimer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWSCTimer::MyDTI cWSCTimer::DTI("cWSCTimer", &::cWeatherScriptCmd::DTI, 80ul, 0u, 0u);

MtObject* cWSCTimer::MyDTI::newInstance() const {
    return new (16u) cWSCTimer;
}

const MtDTI& cWeatherScriptCmd::getDTI() const {
    return cWeatherScriptCmd::DTI;
}

__attribute__((weak)) void cWeatherScriptCmd::setupCmd(cWeatherScriptIO& io) const {
}

bool cWeatherScriptCmd::updateCmd(cWeatherScriptIO& io) const {
    return true;
}

__attribute__((weak)) void cWeatherScriptCmd::endCmd(cWeatherScriptIO& io) const {
    DDON_STUB("cWeatherScriptCmd::endCmd")
    /* stub */
}

__attribute__((weak)) bool cWeatherScriptCmd::isUpdateForceEnd() const {
    DDON_STUB("cWeatherScriptCmd::isUpdateForceEnd")
    return {};
}

__attribute__((weak)) void cWeatherScriptCmd::load(MtDataReader& r) {
    mBeginFrame = r.readF32();
    mEndFrame = r.readF32();
    mEnableStageNo.elems[0] = r.readU32();
    mEnableStageNo.elems[1] = r.readU32();
    mEnableStageNo.elems[2] = r.readU32();
    mEnableStageNo.elems[3] = r.readU32();
    mEnableStageNo.elems[4] = r.readU32();
    mEnableStageNo.elems[5] = r.readU32();
    mEnableStageNo.elems[6] = r.readU32();
    mEnableStageNo.elems[7] = r.readU32();
    mDisableStageNo.elems[0] = r.readU32();
    mDisableStageNo.elems[1] = r.readU32();
    mDisableStageNo.elems[2] = r.readU32();
    mDisableStageNo.elems[3] = r.readU32();
    mDisableStageNo.elems[4] = r.readU32();
    mDisableStageNo.elems[5] = r.readU32();
    mDisableStageNo.elems[6] = r.readU32();
    mDisableStageNo.elems[7] = r.readU32();
}

inline cWeatherScriptCmd::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherScriptCmd::MyDTI cWeatherScriptCmd::DTI("cWeatherScriptCmd", &::cWeatherObjectRes::DTI, 80ul, 0u, 0u);

MtObject* cWeatherScriptCmd::MyDTI::newInstance() const {
    return new (16u) cWeatherScriptCmd;
}

const MtDTI& cWeatherScriptCmds::getDTI() const {
    return cWeatherScriptCmds::DTI;
}

cWeatherScriptCmds::cWeatherScriptCmds() {
    for (u32 i = 0; i < 4; i++) {
        mScripts.elems[i].setAutoDelete(true);
    }
}

cWeatherScriptCmds::~cWeatherScriptCmds() {
}

void cWeatherScriptCmds::load(MtDataReader& r) {
    nDDOIO::readMtArrayEx(r, mScripts.elems[1]);
    nDDOIO::readMtArrayEx(r, mScripts.elems[2]);
    nDDOIO::readMtArrayEx(r, mScripts.elems[3]);
}

inline cWeatherScriptCmds::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherScriptCmds::MyDTI cWeatherScriptCmds::DTI("cWeatherScriptCmds", &::cWeatherObjectRes::DTI, 136ul, 0u, 0u);

__attribute__((weak)) MtObject* cWeatherScriptCmds::MyDTI::newInstance() const {
    DDON_STUB("cWeatherScriptCmds::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cWeatherScriptIO::getDTI() const {
    return cWeatherScriptIO::DTI;
}

__attribute__((weak)) void cWeatherScriptIO::operator delete(void* p_addr) {
    cWeatherScriptIO::getAllocator()->memFree(p_addr);
}

void cWeatherScriptIO::updatePtr() {
    u32 num = mWSCParams.mLength;
    if (num != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t0 = mWSCParams.getBuffer()[static_cast<int>(i0_3)];
            if (t0 != nullptr) {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) != 0) {
                    if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(reinterpret_cast<cEfcHandle*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)))) {
                        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16)) + 96) = 0;
                        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 16) = 0;
                    }
                }
            }
            if (num != (i0_3 + 1u)) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) cWSCParam* cWeatherScriptIO::getWSCParam(const void* pOwner) {
    DDON_STUB("cWeatherScriptIO::getWSCParam")
    return nullptr;
}

void cWeatherScriptIO::releaseWSCParamAll() {
    mMoveFrame = 0.0f;
    mReqSoundVolumeAdd = 0.0f;
    u32 num = mWSCParams.mLength;
    if (num != 0) {
        MtObject* * v0_1 = mWSCParams.getBuffer();
        for (unsigned int i0_2 = 0;;) {
            if (v0_1[static_cast<int>(i0_2)] != nullptr) {
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[static_cast<int>(i0_2)]) + 52) = 2;
            }
            if (num != (i0_2 + 1u)) {
                i0_2 += 1u;
            } else {
                break;
            }
        }
    }
    if (mWSCParams.mAutoDelete) {
        u32 v6_0;
        if (num != 0) {
            u32 v3_0 = num;
            unsigned int i3_3 = 0;
            u32 v4_0;
            for (;;) {
                if (mWSCParams.mpArray[i3_3] == nullptr) {
                    v4_0 = v3_0;
                } else {
                    delete mWSCParams.mpArray[i3_3];
                    v4_0 = mWSCParams.mLength;
                }
                if ((i3_3 + 1u) < v4_0) {
                    v3_0 = v4_0;
                    i3_3 += 1u;
                } else {
                    break;
                }
            }
            v6_0 = v4_0;
        } else {
            v6_0 = 0;
        }
        memset(static_cast<void*>(mWSCParams.mpArray), 0, static_cast<size_t>(v6_0) * 8);
    }
    mWSCParams.mLength = 0;
}

inline cWeatherScriptIO::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherScriptIO::MyDTI cWeatherScriptIO::DTI("cWeatherScriptIO", &::cWeatherObjectSys::DTI, 56ul, 0u, 0u);

MtObject* cWeatherScriptIO::MyDTI::newInstance() const {
    return new (16u) cWeatherScriptIO;
}

template MtTypedArray<cWeatherScriptCmd>::~MtTypedArray();

template void nDDOIO::readMtArrayEx(MtDataReader&, MtTypedArray<cWeatherScriptCmd>&);

