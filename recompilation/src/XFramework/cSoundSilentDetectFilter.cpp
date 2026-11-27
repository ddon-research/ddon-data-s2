// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cSoundSilentDetectFilter.h"
#include "cSoundMeterRms.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

cSoundSilentDetectFilter::cSoundSilentDetectFilter() {
    DDON_STUB("cSoundSilentDetectFilter::cSoundSilentDetectFilter")
    /* stub */
}

cSoundSilentDetectFilter::~cSoundSilentDetectFilter() {
    if (mpRms300 == nullptr) {
        return;
    }
    delete mpRms300;
}

void cSoundSilentDetectFilter::init(const bool enable, const u32 channelNum) {
    mEnable = enable;
    if (!enable) {
        return;
    }
    mIsInitialize = true;
    mChannelNum = channelNum;
}

void cSoundSilentDetectFilter::executeProcess(f32* pData, const u32 frames, const u32 channels) {
    if (mpRms300 == nullptr) {
        return;
    }
    if (mIsInitialize) {
        mpRms300->initialize(static_cast<unsigned char>(channels));
        mIsInitialize = false;
    }
    mpRms300->update(pData, frames, static_cast<unsigned char>(channels));
}

bool cSoundSilentDetectFilter::isEnable() {
    return mEnable;
}

u32 cSoundSilentDetectFilter::getAudioGranularitySamples() {
    if (mpRms300 != nullptr) {
        return 256;
    } else {
        return 0;
    }
}

bool cSoundSilentDetectFilter::isSilent(f32 threshold) {
    mpRms300->measure();
    if (mChannelNum != 6) {
        if (mChannelNum == 2) {
            const cSoundMeterRms::VolumeStereo& t0 = mpRms300->getRmsStereo();
            return threshold > (0.5f * (t0.l + t0.r));
        } else {
            if (mChannelNum == 1) {
                const cSoundMeterRms::Volume& t2 = mpRms300->getRmsMono();
                return threshold > t2.v;
            } else {
                return threshold > 0.0f;
            }
        }
    } else {
        const cSoundMeterRms::VolumeSurround51& t1 = mpRms300->getRmsSurround51();
        return threshold > ((t1.rs + (t1.ls + (t1.lf + (t1.c + (t1.l + t1.r))))) / 6.0f);
    }
}

