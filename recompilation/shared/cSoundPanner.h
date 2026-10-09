#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtMath.h"
#include "MtSynchronize.h"

// Forward declarations
class MtCriticalSection;
class MtMatrix;
class MtVector3;

// Declarations
class cSoundPanner;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;

class cSoundPanner
{
public:
    cSoundPanner();
    virtual ~cSoundPanner();
    bool getGains(const size_t index, const MtVector3& position, const size_t channels, f32& angle, f32* gain_ptr, const f32 angle_offset);
    bool getGainsWithoutRotation(const size_t index, const MtVector3& position, const size_t channels, f32& angle, f32* gain_ptr, const f32 angle_offset);
    bool getGains(const size_t channels, const f32 angle, f32* gain_ptr);
    void setSpeakerRadius(const f32 radius);
    f32 getSpeakerRadius();
    void setSpeakerAngleL(const f32 angle);
    f32 getSpeakerAngleL();
    void setSpeakerAngleR(const f32 angle);
    f32 getSpeakerAngleR();
    void setSpeakerAngleC(const f32 angle);
    f32 getSpeakerAngleC();
    void setSpeakerAngleLs(const f32 angle);
    f32 getSpeakerAngleLs();
    void setSpeakerAngleRs(const f32 angle);
    f32 getSpeakerAngleRs();
    void setSpeakerAngleLe(const f32 angle);
    f32 getSpeakerAngleLe();
    void setSpeakerAngleRe(const f32 angle);
    f32 getSpeakerAngleRe();
    bool updateListenerMatrix(const size_t index, const MtMatrix& matrix);
private:
    void setSpeakerLocalPosition();
    void localize(const MtVector3& position, const MtMatrix& matrix, MtVector3& local_position, f32& angle, const f32 angle_offset) const;
    void localizeWithoutRotation(const MtVector3& position, const MtVector3& listener, MtVector3& local_position, f32& angle, const f32 angle_offset) const;
    void pan(const size_t channels, const MtVector3& local_position, const f32 angle, const f32(&speaker_angle)[7], const MtVector3(&speaker_local_position)[7], f32* gain_ptr) const;
    void pan2ch(const MtVector3& local_position, const f32 angle, const f32(&speaker_angle)[7], const MtVector3(&speaker_local_position)[7], f32* gain_ptr) const;
    void pan4ch(const MtVector3& local_position, const f32 angle, const f32(&speaker_angle)[7], const MtVector3(&speaker_local_position)[7], f32* gain_ptr) const;
    void pan51ch(const MtVector3& local_position, const f32 angle, const f32(&speaker_angle)[7], const MtVector3(&speaker_local_position)[7], f32* gain_ptr) const;
    void pan71ch(const MtVector3& local_position, const f32 angle, const f32(&speaker_angle)[7], const MtVector3(&speaker_local_position)[7], f32* gain_ptr) const;
    bool getGainsUsingTwoDimensionalVBAP(const MtVector3& ch1, const MtVector3& ch2, const MtVector3& virtual_source, f32& g1, f32& g2) const;
private:
    MtMatrix mListenerMatrix[4];  // offset: 0x10
    MtMatrix mListenerMatrixInverse[4];  // offset: 0x110
    MtVector3 mSpeakerLocalPosition[7];  // offset: 0x210
    MtCriticalSection mCriticalSection;  // offset: 0x280
    f32 mSpeakerRadius;  // offset: 0x288
    f32 mSpeakerAngle[7];  // offset: 0x28c
public:
    static const f32 DefaultSpeakerRadius;
    static const f32 DefaultSpeakerAngleL;
    static const f32 DefaultSpeakerAngleR;
    static const f32 DefaultSpeakerAngleC;
    static const f32 DefaultSpeakerAngleLs;
    static const f32 DefaultSpeakerAngleRs;
    static const f32 DefaultSpeakerAngleLe;
    static const f32 DefaultSpeakerAngleRe;
};
