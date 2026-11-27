// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundSubMixer.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#include "rSoundSimpleCurve.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rSoundSubMixer::getDTI() const {
    return rSoundSubMixer::DTI;
}

void* rSoundSubMixer::operator new(size_t sz, u32 align) {
    return rSoundSubMixer::getAllocator()->memAlloc(sz, align, rSoundSubMixer::DTI.getID());
}

rSoundSubMixer::rSoundSubMixer() {
    mActive = true;
    mPriority = DEFAULT_PRIORITY;
    mIDToIndexTblNum = 0;
    mpIDToIndexTbl = nullptr;
    mCurveStyle = rSoundSimpleCurve::CURVE_STYLE_LINEAR;
    mSendNumAll = 0;
    mpSendBuff = nullptr;
    mpCalcBuff = nullptr;
    mpCalc = nullptr;
    mpSendNum = nullptr;
    mpaSendIndex = nullptr;
    mpaBypass = nullptr;
    mpaVol = nullptr;
    mpaEqNo = nullptr;
    mpaEffectNo = nullptr;
    mpaAbs = nullptr;
    mpaTransitionFlag = nullptr;
    mpaTransitionMode = nullptr;
    mpaTransitionStatus = nullptr;
    mpaCurve = nullptr;
    mpaTransitionTime = nullptr;
    mpaSustainTime = nullptr;
    mpaReleaseTime = nullptr;
    mpaStartVol = nullptr;
    mpaTargetVol = nullptr;
    mpaEndVol = nullptr;
    mpaOrgEqNo = nullptr;
    mpaOrgEffectNo = nullptr;
    mpaOrgAbs = nullptr;
    mpaOrgCurve = nullptr;
    mpaElapsedTime = nullptr;
    setAttribute(ATTR_NATIVE | ATTR_SAVEABLE);
    mFaders.setAutoDelete(true);
    mOutputFaders.setAutoDelete(true);
    for (u32 i = 0; i < MAX_EQ_PRESET; i++) {
        mEQPreset[i] = DEFAULT_EQ_PRESET;
    }
    for (u32 i = 0; i < MAX_REVERB_PRESET; i++) {
        mReverbPreset[i] = DEFAULT_REVERB_PRESET;
    }
    for (u32 i = 0; i < MAX_CURVE_NUM; i++) {
        mpSimpleCurve[i] = nullptr;
    }
}

__attribute__((noinline)) rSoundSubMixer::~rSoundSubMixer() {
    if (mpSimpleCurve[0] != nullptr) {
        mpSimpleCurve[0]->cResource::release();
        mpSimpleCurve[0] = nullptr;
    }
    if (mpSimpleCurve[1] != nullptr) {
        mpSimpleCurve[1]->cResource::release();
        mpSimpleCurve[1] = nullptr;
    }
    if (mpSimpleCurve[2] != nullptr) {
        mpSimpleCurve[2]->cResource::release();
        mpSimpleCurve[2] = nullptr;
    }
    if (mpSimpleCurve[3] != nullptr) {
        mpSimpleCurve[3]->cResource::release();
        mpSimpleCurve[3] = nullptr;
    }
    MtMemoryAllocator::getAllocator(rSoundSubMixer::DTI)->memFree(static_cast<void*>(mpCalcBuff));
    MtMemoryAllocator::getAllocator(rSoundSubMixer::DTI)->memFree(static_cast<void*>(mpSendBuff));
    MtMemoryAllocator::getAllocator(rSoundSubMixer::DTI)->memFree(static_cast<void*>(mpIDToIndexTbl));
    if (mOutputFaders.mLength != 0) {
        u32 v0_0 = mOutputFaders.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mOutputFaders.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mOutputFaders.mpArray[i0_3];
                v1_0 = mOutputFaders.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mOutputFaders.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mOutputFaders.mpArray));
    }
    mOutputFaders.mpArray = nullptr;
    mOutputFaders.mBufsiz = 0;
    mOutputFaders.mLength = 0;
    if (mFaders.mLength != 0) {
        u32 v3_0 = mFaders.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mFaders.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mFaders.mpArray[i3_3];
                v4_0 = mFaders.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFaders.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mFaders.mpArray));
    }
    mFaders.mpArray = nullptr;
    mFaders.mBufsiz = 0;
    mFaders.mLength = 0;
}

void rSoundSubMixer::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mActive", &mActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPriority", &mPriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEQPreset", &mEQPreset[0], 32u, 9u);
    s << MtProperty(static_cast<MtObject*>(this), "mReverbPreset", &mReverbPreset[0], 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "mCurveStyle", &mCurveStyle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFaders", static_cast<MtObject*>(&mFaders), 0u, 0u);
}

MtUI* rSoundSubMixer::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

__attribute__((weak)) bool rSoundSubMixer::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    NATIVE_FILE_HEADER header;
    r.read(&header, sizeof(header));
    if (header.Magic != NativeFileMagic) {
        return false;
    }
    if (header.Version != NativeFileVersion) {
        return false;
    }
    mFaders.deleteAll(true);
    r.read(&mActive, sizeof(mActive));
    mPriority = r.readS8();
    r.align(4);
    r.read(mEQPreset, sizeof(mEQPreset));
    r.read(mReverbPreset, sizeof(mReverbPreset));
    u32 faderNum = r.readU32();
    for (u32 i = 0; i < faderNum; i++) {
        Fader* pFader = new (16u) Fader;
        pFader->setFaderID(r.readU8());
        pFader->setSendID(r.readS16());
        pFader->setVol(r.readF32());
        pFader->setEqNo(r.readS8());
        pFader->setEffectNo(r.readS8());
        // workaround
        u8 absByte = 0;
        r.read(&absByte, sizeof(absByte));
        __builtin_memcpy(&pFader->mAbs, &absByte, sizeof(absByte));
        r.align(4);
        pFader->setTransitionTime(r.readU16());
        pFader->setCurve(r.readS16());
        pFader->setSustainTime(r.readU16());
        pFader->setReleaseTime(static_cast<u16>(r.readS16()));
        mFaders.add(pFader);
        r.align(4);
    }
    if (!createFaderIDToIndexTbl()) {
        mFaders.deleteAll(true);
        return false;
    }
    return true;
}

__attribute__((weak)) bool rSoundSubMixer::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    NATIVE_FILE_HEADER header;
    header.Magic = NativeFileMagic;
    header.Version = NativeFileVersion;
    w.write(&header, sizeof(header));
    w.write(&mActive, sizeof(mActive));
    w.writeS8(mPriority);
    w.align(4);
    w.write(mEQPreset, sizeof(mEQPreset));
    w.write(mReverbPreset, sizeof(mReverbPreset));
    w.writeU32(mFaders.length());
    for (u32 i = 0; i < mFaders.length(); i++) {
        Fader* pFader = static_cast<Fader*>(mFaders.mpArray[static_cast<s32>(i)]);
        w.writeU8(pFader->getFaderID());
        w.writeS16(pFader->getSendID());
        w.writeF32(pFader->getVol());
        w.writeS8(pFader->getEqNo());
        w.writeS8(pFader->getEffectNo());
        // workaround
        u8 abs;
        __builtin_memcpy(&abs, &pFader->mAbs, sizeof(abs));
        w.write(&abs, sizeof(abs));
        w.align(4);
        w.writeU16(pFader->getTransitionTime());
        w.writeS16(pFader->getCurve());
        w.writeU16(pFader->getSustainTime());
        w.writeS16(static_cast<s16>(pFader->getReleaseTime()));
        w.align(4);
    }
    return true;
}

bool rSoundSubMixer::convert(MtStream& out) {
    this->rSoundSubMixer::save(out);
    return true;
}

MT_CTSTR rSoundSubMixer::getExt() const {
    return "smxr";
}

__attribute__((weak)) void rSoundSubMixer::add() {
    DDON_STUB("rSoundSubMixer::add")
    /* stub */
}

__attribute__((weak)) void rSoundSubMixer::add(rSoundSubMixer::Fader* pFader) {
    DDON_STUB("rSoundSubMixer::add")
    /* stub */
}

void rSoundSubMixer::clear() {
    if (mFaders.mLength != 0) {
        u32 v0_0 = mFaders.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mFaders.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mFaders.mpArray[i0_3];
                v1_0 = mFaders.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFaders.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mFaders.mpArray));
    }
    mFaders.mpArray = nullptr;
    mFaders.mBufsiz = 0;
    mFaders.mLength = 0;
}

__attribute__((weak)) bool rSoundSubMixer::createFaderIDToIndexTbl() {
    MtMemoryAllocator::getAllocator(rSoundSubMixer::DTI)->memFree(mpIDToIndexTbl);
    mIDToIndexTblNum = getMaxFaderID() + 1;
    mpIDToIndexTbl = static_cast<s16*>(MtMemoryAllocator::getAllocator(rSoundSubMixer::DTI)->memAlloc(sizeof(s16) * mIDToIndexTblNum, 16u));
    if (mpIDToIndexTbl == nullptr) {
        return false;
    }
    memset(mpIDToIndexTbl, DEFAULT_FADER_INDEX, sizeof(s16) * mIDToIndexTblNum);
    for (u16 i = 0; i < mFaders.length(); i++) {
        Fader* pFader = static_cast<Fader*>(mFaders.mpArray[i]);
        if (pFader != nullptr) {
            mpIDToIndexTbl[pFader->getFaderID()] = static_cast<s16>(i);
        }
    }
    return true;
}

__attribute__((weak)) bool rSoundSubMixer::determineCanBeSetSubMixer(rSoundSubMixer* pPostSubMixer) {
    DDON_STUB("rSoundSubMixer::determineCanBeSetSubMixer")
    return {};
}

__attribute__((weak)) bool rSoundSubMixer::initCalc(u32 step) {
    DDON_STUB("rSoundSubMixer::initCalc")
    return {};
}

__attribute__((weak)) bool rSoundSubMixer::checkCalculationFader() {
    DDON_STUB("rSoundSubMixer::checkCalculationFader")
    return {};
}

__attribute__((weak)) bool rSoundSubMixer::checkCalculationFaderParam(u8 index, u8 sendIndex, rSoundSubMixer::Fader* pFader) {
    DDON_STUB("rSoundSubMixer::checkCalculationFaderParam")
    return {};
}

__attribute__((weak)) bool rSoundSubMixer::calcTransition(f32 frameMsec) {
    DDON_STUB("rSoundSubMixer::calcTransition")
    return {};
}

__attribute__((weak)) bool rSoundSubMixer::calcOutput() {
    DDON_STUB("rSoundSubMixer::calcOutput")
    return {};
}

__attribute__((weak)) void rSoundSubMixer::setResourceSimpleCurve(u8 index, rSoundSimpleCurve* res) {
    DDON_STUB("rSoundSubMixer::setResourceSimpleCurve")
    /* stub */
}

__attribute__((weak)) bool rSoundSubMixer::checkSendLoop(u32 step) {
    DDON_STUB("rSoundSubMixer::checkSendLoop")
    return {};
}

inline rSoundSubMixer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundSubMixer::MyDTI rSoundSubMixer::DTI("rSoundSubMixer", &::cResource::DTI, 488ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundSubMixer::MyDTI::newInstance() const {
    // workaround
    void* memory = MtMemoryAllocator::getAllocator(rSoundSubMixer::DTI)->memAlloc(sizeof(rSoundSubMixer), 16u, rSoundSubMixer::DTI.getID());
    return new (memory) rSoundSubMixer;
}

const MtDTI& rSoundSubMixer::Fader::getDTI() const {
    return rSoundSubMixer::Fader::DTI;
}

rSoundSubMixer::Fader::Fader() {
    mVol = 0.0f;
    mSendID = -1;
    mTransitionTime = 0;
    mCurve = -1;
    mSustainTime = 0;
    mReleaseTime = 0;
    mFaderID = 0;
    mEqNo = -2;
    mEffectNo = -2;
    mAbs = false;
    mSetFlag = true;
}

rSoundSubMixer::Fader::~Fader() {
}

void rSoundSubMixer::Fader::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mFaderID", &mFaderID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSendID", &mSendID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVol", &mVol, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAbs", &mAbs, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCurve", &mCurve, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTransitionTime", &mTransitionTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSustainTime", &mSustainTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReleaseTime", &mReleaseTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEqNo", &mEqNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectNo", &mEffectNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSetFlag", &mSetFlag, 8192u, 0u);
}

MtUI* rSoundSubMixer::Fader::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void rSoundSubMixer::Fader::copyFaderWoIdStr(rSoundSubMixer::Fader* pPostFader) {
    if (pPostFader == nullptr) {
        return;
    }
    mVol = pPostFader->getVol();
    mEqNo = pPostFader->getEqNo();
    mEffectNo = pPostFader->getEffectNo();
    mAbs = pPostFader->getAbs();
    mTransitionTime = pPostFader->getTransitionTime();
    mCurve = pPostFader->getCurve();
    mSustainTime = pPostFader->getSustainTime();
    mReleaseTime = pPostFader->getReleaseTime();
    mSetFlag = pPostFader->getSetFlag();
}

void rSoundSubMixer::Fader::copyFader(rSoundSubMixer::Fader* pPostFader) {
    if (pPostFader == nullptr) {
        return;
    }
    mVol = pPostFader->getVol();
    mEqNo = pPostFader->getEqNo();
    mEffectNo = pPostFader->getEffectNo();
    mAbs = pPostFader->getAbs();
    mTransitionTime = pPostFader->getTransitionTime();
    mCurve = pPostFader->getCurve();
    mSustainTime = pPostFader->getSustainTime();
    mReleaseTime = pPostFader->getReleaseTime();
    mSetFlag = pPostFader->getSetFlag();
    mFaderID = pPostFader->getFaderID();
    mSendID = pPostFader->getSendID();
}

inline rSoundSubMixer::Fader::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundSubMixer::Fader::MyDTI rSoundSubMixer::Fader::DTI("rSoundSubMixer::Fader", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rSoundSubMixer::Fader::MyDTI::newInstance() const {
    return new (16u) rSoundSubMixer::Fader;
}

template MtTypedArray<rSoundSubMixer::Fader>::~MtTypedArray();

