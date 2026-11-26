// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cSoundMultiBandEQ.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSoundMultiBandEQ::getDTI() const {
    return cSoundMultiBandEQ::DTI;
}

inline void cSoundMultiBandEQ::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cSoundMultiBandEQ::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cSoundMultiBandEQ::setEQParam(u32 unit) {
    DDON_STUB("cSoundMultiBandEQ::setEQParam")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::computeAllUnit(f32* * ppSampleBuffer, u32 sampleNum) {
    DDON_STUB("cSoundMultiBandEQ::computeAllUnit")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::computeSingleUnit(f32* * ppSampleBuffer, u32 sampleNum, u32 unit_num) {
    DDON_STUB("cSoundMultiBandEQ::computeSingleUnit")
    /* stub */
}

cSoundMultiBandEQ::cSoundMultiBandEQ() {
    DDON_STUB("cSoundMultiBandEQ::cSoundMultiBandEQ")
    /* stub */
}

cSoundMultiBandEQ::~cSoundMultiBandEQ() {
}

void cSoundMultiBandEQ::setChannelNum(u32 num) {
    mChannelNum = num;
}

__attribute__((weak)) void cSoundMultiBandEQ::setBypass(bool b) {
    DDON_STUB("cSoundMultiBandEQ::setBypass")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setEnable(bool b) {
    DDON_STUB("cSoundMultiBandEQ::setEnable")
    /* stub */
}

bool cSoundMultiBandEQ::getBypass() const {
    return mBypass;
}

bool cSoundMultiBandEQ::getEnable() const {
    return mEnable;
}

bool cSoundMultiBandEQ::isAnyEnable() const {
    if (!mBypass) {
        if (mEnable) {
            return mUnitEnable != 0;
        }
    }
    return false;
}

__attribute__((weak)) void cSoundMultiBandEQ::setLowEnable(bool b) {
    DDON_STUB("cSoundMultiBandEQ::setLowEnable")
    /* stub */
}

void cSoundMultiBandEQ::setLowFreq(f32 freq) {
    mFreq.x = freq;
    setEQParam(0u);
}

void cSoundMultiBandEQ::setLowGain(f32 gain) {
    mGain.x = gain;
    setEQParam(0u);
}

void cSoundMultiBandEQ::setLowQ(f32 q) {
    mQ.x = q;
    setEQParam(0u);
}

bool cSoundMultiBandEQ::getLowEnable() const {
    return static_cast<bool>(mUnitEnable & 1u);
}

f32 cSoundMultiBandEQ::getLowFreq() const {
    return mFreq.x;
}

f32 cSoundMultiBandEQ::getLowGain() const {
    return mGain.x;
}

f32 cSoundMultiBandEQ::getLowQ() const {
    return mQ.x;
}

void cSoundMultiBandEQ::setLowType(cSoundMultiBandEQ::EQ_FILTER_TYPE type) {
    mLowType = type;
    setEQParam(0u);
}

cSoundMultiBandEQ::EQ_FILTER_TYPE cSoundMultiBandEQ::getLowType() const {
    return mLowType;
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidLowEnable(bool b) {
    DDON_STUB("cSoundMultiBandEQ::setMidLowEnable")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidLowFreq(f32 freq) {
    DDON_STUB("cSoundMultiBandEQ::setMidLowFreq")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidLowGain(f32 gain) {
    DDON_STUB("cSoundMultiBandEQ::setMidLowGain")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidLowQ(f32 q) {
    DDON_STUB("cSoundMultiBandEQ::setMidLowQ")
    /* stub */
}

bool cSoundMultiBandEQ::getMidLowEnable() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 664)) & 2) >> 1);
}

f32 cSoundMultiBandEQ::getMidLowFreq() const {
    return mFreq.y;
}

f32 cSoundMultiBandEQ::getMidLowGain() const {
    return mGain.y;
}

f32 cSoundMultiBandEQ::getMidLowQ() const {
    return mQ.y;
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidHighEnable(bool b) {
    DDON_STUB("cSoundMultiBandEQ::setMidHighEnable")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidHighFreq(f32 freq) {
    DDON_STUB("cSoundMultiBandEQ::setMidHighFreq")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidHighGain(f32 gain) {
    DDON_STUB("cSoundMultiBandEQ::setMidHighGain")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidHighQ(f32 q) {
    DDON_STUB("cSoundMultiBandEQ::setMidHighQ")
    /* stub */
}

bool cSoundMultiBandEQ::getMidHighEnable() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 664)) & 4) >> 2);
}

f32 cSoundMultiBandEQ::getMidHighFreq() const {
    return mFreq.z;
}

f32 cSoundMultiBandEQ::getMidHighGain() const {
    return mGain.z;
}

f32 cSoundMultiBandEQ::getMidHighQ() const {
    return mQ.z;
}

__attribute__((weak)) void cSoundMultiBandEQ::setHighEnable(bool b) {
    DDON_STUB("cSoundMultiBandEQ::setHighEnable")
    /* stub */
}

void cSoundMultiBandEQ::setHighFreq(f32 freq) {
    mFreq.w = freq;
    setEQParam(3u);
}

void cSoundMultiBandEQ::setHighGain(f32 gain) {
    mGain.w = gain;
    setEQParam(3u);
}

void cSoundMultiBandEQ::setHighQ(f32 q) {
    mQ.w = q;
    setEQParam(3u);
}

bool cSoundMultiBandEQ::getHighEnable() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 664)) & 8) >> 3);
}

f32 cSoundMultiBandEQ::getHighFreq() const {
    return mFreq.w;
}

f32 cSoundMultiBandEQ::getHighGain() const {
    return mGain.w;
}

f32 cSoundMultiBandEQ::getHighQ() const {
    return mQ.w;
}

void cSoundMultiBandEQ::setHighType(cSoundMultiBandEQ::EQ_FILTER_TYPE type) {
    mHighType = type;
    setEQParam(3u);
}

cSoundMultiBandEQ::EQ_FILTER_TYPE cSoundMultiBandEQ::getHighType() const {
    return mHighType;
}

__attribute__((weak)) void cSoundMultiBandEQ::setLowUnit(bool enable, cSoundMultiBandEQ::EQ_FILTER_TYPE type, f32 freq, f32 gain, f32 q) {
    DDON_STUB("cSoundMultiBandEQ::setLowUnit")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidLowUnit(bool enable, f32 freq, f32 gain, f32 q) {
    DDON_STUB("cSoundMultiBandEQ::setMidLowUnit")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setMidHighUnit(bool enable, f32 freq, f32 gain, f32 q) {
    DDON_STUB("cSoundMultiBandEQ::setMidHighUnit")
    /* stub */
}

__attribute__((weak)) void cSoundMultiBandEQ::setHighUnit(bool enable, cSoundMultiBandEQ::EQ_FILTER_TYPE type, f32 freq, f32 gain, f32 q) {
    DDON_STUB("cSoundMultiBandEQ::setHighUnit")
    /* stub */
}

void cSoundMultiBandEQ::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Bypass", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getBypass), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setBypass), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Enable", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getEnable), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "LowEnable", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getLowEnable), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setLowEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "LowType", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getLowType), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setLowType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "LowFreq", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getLowFreq), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setLowFreq), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "LowQ", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getLowQ), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setLowQ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "LowGain", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getLowGain), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setLowGain), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "MidLowEnable", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getMidLowEnable), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setMidLowEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MidLowFreq", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getMidLowFreq), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setMidLowFreq), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MidLowQ", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getMidLowQ), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setMidLowQ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MidLowGain", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getMidLowGain), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setMidLowGain), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "MidHighEnable", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getMidHighEnable), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setMidHighEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MidHighFreq", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getMidHighFreq), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setMidHighFreq), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MidHighQ", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getMidHighQ), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setMidHighQ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MidHighGain", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getMidHighGain), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setMidHighGain), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "HighEnable", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getHighEnable), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setHighEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "HighType", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getHighType), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setHighType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "HighFreq", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getHighFreq), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setHighFreq), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "HighQ", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getHighQ), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setHighQ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "HighGain", reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::getHighGain), reinterpret_cast<MT_MFUNC>(&::cSoundMultiBandEQ::setHighGain), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* cSoundMultiBandEQ::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cSoundMultiBandEQ::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSoundMultiBandEQ::MyDTI cSoundMultiBandEQ::DTI("cSoundMultiBandEQ", &::MtObject::DTI, 688ul, 0u, 0u);

s32 cSoundMultiBandEQ::mEnableUnitTable[16] = {-1, 0, 1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1};

__attribute__((weak)) MtObject* cSoundMultiBandEQ::MyDTI::newInstance() const {
    DDON_STUB("cSoundMultiBandEQ::MyDTI::newInstance")
    return nullptr;
}

