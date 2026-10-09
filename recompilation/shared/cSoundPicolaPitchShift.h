#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtSynchronize.h"
#include "rSoundSource.h"

// Forward declarations
class MtCriticalSection;

// Declarations
class cSoundPicolaPitchShift;

// Type aliases from DWARF
using f32 = float;
using s32 = int;
using u32 = unsigned int;

class cSoundPicolaPitchShift
{
public:
    class Resample;
public:
    class Resample
    {
    public:
        Resample();
        Resample(u32 inputSample, f32* inputData, u32 outputSample, u32 fs, u32 degree, u32 bessel, u32 alpha);
        virtual ~Resample();
        void initFIR();
        void setDegree(u32);
        u32 getDegree();
        void setFs(u32);
        u32 getFs();
        void setInputSample(u32);
        u32 getInputSample();
        void setOutputSample(u32);
        u32 getOutputSample();
        void setCoefAmp(f32);
        f32 getCoefAmp();
        void setKaiserAlpha(f32);
        f32 getKaiserAlpha();
        void setKaiserR(u32);
        u32 getKaiserR();
        void setInputData(f32* input);
        f32* getOutputData();
        void executeResample();
    private:
        u32 mDegree;  // offset: 0x8
        u32 mFs;  // offset: 0xc
        f32 mCoefAmp;  // offset: 0x10
        f32 mAlpha;  // offset: 0x14
        u32 mR;  // offset: 0x18
        f32 mFIR[2048];  // offset: 0x1c
        f32 mKaiser[2048];  // offset: 0x201c
        u32 mFIRSize;  // offset: 0x401c
        u32 mCh;  // offset: 0x4020
        f32* mpInput;  // offset: 0x4028
        f32 mOutput[2048];  // offset: 0x4030
        u32 mInputSamples;  // offset: 0x6030
        u32 mOutputSamples;  // offset: 0x6034
        f32 mUnit;  // offset: 0x6038
        static const int BUFFER_SAMPLES = 2048;
        static const int DEFAULT_DEGREE = 2;
        static const int DEFAULT_ALPHA_NUMERATOR = 4;
        static const int DEFAULT_ALPHA_DENOMINATOR = 1;
        static const int DEFAULT_R = 1;
    };
private:
    void setInputBuffer(f32* pData);
    void executeFundamentalPeriod();
    void executePitchShift();
    void executeResample();
    void setOutputBuffer(f32* pData);
public:
    cSoundPicolaPitchShift();
    ~cSoundPicolaPitchShift();
    void executeProcess(f32* pData, const u32 frames, const u32 channels);
    void initBuffer();
    f32 getFundamentalFrequency();
    s32 getCent();
    void setCent(s32 cent);
    void setSamples(s32 samples);
    void setPeriod(u32 periodNum, rSoundSource::FUNDAMENTAL_PERIOD* period);
    void setLoop(bool loop, u32 loopStart, u32 loopEnd);
    void setIndex(u32 index);
    u32 getIndex();
    bool getIsProcess();
    void processLock();
    void processUnLock();
    u32 getLatencyFlames();
    u32 getLoopCounter();
    void setNoProcess();
private:
    u32 mAmdfWindow;  // offset: 0x0
    f32 mInputBuffer[4608];  // offset: 0x4
    f32 mShiftedBuffer[1536];  // offset: 0x4804
    u32 mMinFreq;  // offset: 0x6004
    u32 mMaxFreq;  // offset: 0x6008
    u32 mMinPeriod;  // offset: 0x600c
    u32 mMaxPeriod;  // offset: 0x6010
    u32 mChannels;  // offset: 0x6014
    u32 mSamplesPerFrame;  // offset: 0x6018
    u32 mSamplesPerFrameForResample;  // offset: 0x601c
    u32 mSamplesPerFrameForResampleShift;  // offset: 0x6020
    u32 mDegree;  // offset: 0x6024
    u32 mBessel;  // offset: 0x6028
    u32 mAlpha;  // offset: 0x602c
    u32 mFundamentalPeriod;  // offset: 0x6030
    f32 mFundamentalFrequency;  // offset: 0x6034
    f32 mRatio;  // offset: 0x6038
    s32 mCent;  // offset: 0x603c
    u32 mL;  // offset: 0x6040
    u32 mTp;  // offset: 0x6044
    u32 mL_Shift;  // offset: 0x6048
    u32 mTp_Shift;  // offset: 0x604c
    s32 mGap;  // offset: 0x6050
    s32 mCount;  // offset: 0x6054
    u32 mCrossCount;  // offset: 0x6058
    f32 mResidueSamples;  // offset: 0x605c
    f32 mStackingResidueSamples;  // offset: 0x6060
    u32 mOffsetInput;  // offset: 0x6064
    u32 mOffsetShift;  // offset: 0x6068
    u32 mOffsetCalc;  // offset: 0x606c
    u32 mLoopCounter;  // offset: 0x6070
    s32 mSamples;  // offset: 0x6074
    u32 mPeriodNum;  // offset: 0x6078
    rSoundSource::FUNDAMENTAL_PERIOD* mpPeriod;  // offset: 0x6080
    bool mLoop;  // offset: 0x6088
    u32 mLoopStart;  // offset: 0x608c
    u32 mLoopEnd;  // offset: 0x6090
    Resample* mpResample;  // offset: 0x6098
    Resample* mpResampleArray[25];  // offset: 0x60a0
    u32 mIndex;  // offset: 0x6168
    u32 mLatencyFlames;  // offset: 0x616c
    bool mIsProcess;  // offset: 0x6170
    MtCriticalSection mProcessSection;  // offset: 0x6178
    static const int DEFAULT_FS = 48000;
    static const int BUFFER_SAMPLES = 2048;
    static const int DEFAULT_MIN_FREQ = 50;
    static const int DEFAULT_MAX_FREQ = 250;
    static const int DEFAULT_CHANNELS = 1;
    static const int PITCH_SHIFT_LATENCY_FLAMES = 4;
    static const int DEFAULT_DEGREE = 2;
    static const int DEFAULT_BESSEL = 1;
    static const int DEFAULT_ALPHA = 4;
    static const int DEFAULT_OFFSET_INPUT_NUM = 17;
    static const int DEFAULT_OFFSET_SHIFT_NUM = 2;
    static const int DEFAULT_OFFSET_CALC_NUM = 8;
    static const int DEFAULT_SAMPLES_PER_FRAME = 256;
    static const int CENT_PER_OCTAVE = 1200;
    static const int DEFAULT_MIN_CENT = -1200;
    static const int DEFAULT_MAX_CENT = 1200;
    static const int DEFAULT_INTERVAL_STEP = 100;
    static const int DEFAULT_INTERVAL_STEP_NUM = 25;
    static const int DEFAULT_STEP_CENTER = 12;
};
