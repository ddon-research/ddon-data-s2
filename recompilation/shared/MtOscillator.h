#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class MtOscillator;

// Type aliases from DWARF
using f32 = float;

class MtOscillator
{
public:
    enum Type
    {
        SAW = 0,
        SQUARE = 1,
        TRIANGLE = 2,
        SINE = 3,
        NOISE = 4,
        FORCEWORD = -1,
    };
public:
    using UpdateFunc = void(MtOscillator::*)(f32);
public:
    MtOscillator();
    MtOscillator(Type type, f32 default_value, f32 amp, f32 freq);
    ~MtOscillator();
    Type getType() const;
    void setType(Type type);
    f32 getValue() const;
    void setValue(f32 value);
    f32 getDefaultValue() const;
    void setDefaultValue(f32);
    f32 getAmplitude() const;
    void setAmplitude(f32);
    f32 getCurrentAmplitude() const;
    bool isEnable() const;
    void enable(bool en);
    void reset();
    f32 getFrequency() const;
    void setFrequency(f32);
    void update(f32 delta_time);
    f32 getFrameTime() const;
    void setFrameTime(f32);
    bool isEnvMode() const;
    void enableEnvMode(bool en);
    bool isTriggerMode() const;
    void enableTriggerMode(bool en);
    void trigger();
    bool isTriggered() const;
    f32 getEnvTime() const;
    void setEnvTime(f32 env_time);
private:
    void updateSaw(f32 dt);
    void updateSquare(f32 dt);
    void updateTriangle(f32 dt);
    void updateSine(f32 dt);
    void updateNoise(f32 dt);
    void envUpdate(f32 dt);
private:
    Type mType;  // offset: 0x0
    f32 mDefaultValue;  // offset: 0x4
    f32 mCurrentValue;  // offset: 0x8
    f32 mAmplitude;  // offset: 0xc
    f32 mCurrentAmp;  // offset: 0x10
    f32 mFrameTime;  // offset: 0x14
    f32 mFrequency;  // offset: 0x18
    f32 mCurrentTime;  // offset: 0x1c
    bool mEnable;  // offset: 0x20
    bool mEnvMode;  // offset: 0x21
    bool mTriggerMode;  // offset: 0x22
    bool mTriggerEnd;  // offset: 0x23
    f32 mEnvelopeTime;  // offset: 0x24
    f32 mCurrentEnvTime;  // offset: 0x28
    UpdateFunc mpUpdateFunc;  // offset: 0x30
};
