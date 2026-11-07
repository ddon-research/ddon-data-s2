#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtVector3;

namespace nSound {
    enum ChannelNumber
    {
        ChannelNumber_1ch = 1,
        ChannelNumber_2ch = 2,
        ChannelNumber_21ch = 3,
        ChannelNumber_4ch = 4,
        ChannelNumber_5ch = 5,
        ChannelNumber_51ch = 6,
        ChannelNumber_7ch = 7,
        ChannelNumber_71ch = 8,
    };
}  // namespace nSound

namespace nSound {
    enum Channel_2ch
    {
        Channel_2ch_L = 0,
        Channel_2ch_R = 1,
        Channel_2ch_Max = 2,
    };
}  // namespace nSound

namespace nSound {
    enum Channel_4ch
    {
        Channel_4ch_L = 0,
        Channel_4ch_R = 1,
        Channel_4ch_Ls = 2,
        Channel_4ch_Rs = 3,
        Channel_4ch_Max = 4,
    };
}  // namespace nSound

namespace nSound {
    enum Channel_51ch
    {
        Channel_51ch_L = 0,
        Channel_51ch_R = 1,
        Channel_51ch_C = 2,
        Channel_51ch_LFE = 3,
        Channel_51ch_Ls = 4,
        Channel_51ch_Rs = 5,
        Channel_51ch_Max = 6,
    };
}  // namespace nSound

namespace nSound {
    enum Channel_5ch
    {
        Channel_5ch_L = 0,
        Channel_5ch_R = 1,
        Channel_5ch_C = 2,
        Channel_5ch_Ls = 3,
        Channel_5ch_Rs = 4,
        Channel_5ch_Max = 5,
    };
}  // namespace nSound

namespace nSound {
    enum Channel_71ch
    {
        Channel_71ch_L = 0,
        Channel_71ch_R = 1,
        Channel_71ch_C = 2,
        Channel_71ch_LFE = 3,
        Channel_71ch_Ls = 4,
        Channel_71ch_Rs = 5,
        Channel_71ch_Le = 6,
        Channel_71ch_Re = 7,
        Channel_71ch_Max = 8,
    };
}  // namespace nSound

namespace nSound {
    enum Channel_7ch
    {
        Channel_7ch_L = 0,
        Channel_7ch_R = 1,
        Channel_7ch_C = 2,
        Channel_7ch_Ls = 3,
        Channel_7ch_Rs = 4,
        Channel_7ch_Le = 5,
        Channel_7ch_Re = 6,
        Channel_7ch_Max = 7,
    };
}  // namespace nSound

namespace nSound {
    enum Channel_UpDownMixLevels
    {
        Channel_UpDownMixLevels_C = 0,
        Channel_UpDownMixLevels_LFE = 1,
        Channel_UpDownMixLevels_Ls = 2,
        Channel_UpDownMixLevels_Rs = 3,
        Channel_UpDownMixLevels_Le = 4,
        Channel_UpDownMixLevels_Re = 5,
        Channel_UpDownMixLevels_Max = 6,
    };
}  // namespace nSound

namespace nSound {
    enum Listener
    {
        Listener_0 = 0,
        Listener_1 = 1,
        Listener_2 = 2,
        Listener_3 = 3,
        Listener_Max = 4,
    };
}  // namespace nSound

// Type aliases from DWARF
using _Sizet = long unsigned int;
using f32 = float;
using s8 = signed char;
using size_t = _Sizet;
using u8 = unsigned char;

namespace nSound {

    bool applyInteriorPanning(const f32 distance, const f32 interior_distance, const size_t channels, f32* gain_ptr);
    f32 panningParameterToRadiansOnInverseXInverseY(const s8 panning_parameter);
    bool divideAmplitudeHardCenterAndPhantomCenterUsingPanDepth(const size_t channels, f32* gain_ptr, const f32 ratio);
    bool divideAmplitudeHardCenterAndPhantomCenter(const size_t channels, f32* gain_ptr, const f32 ratio);
    bool applyPanDepthMinus3dB(const size_t channels, f32* gain_ptr);
    f32 panningParameterToRadiansOnInverseXInverseYTurnedHalfPi(const u8 panning_parameter);
    f32 normalizeRadiansMinusPiToPi(const f32 angle);
    f32 getDistance(const MtVector3& source, const MtVector3& listener);
    void filling(const f32 value, f32* gain_ptr, const u8 channels);
    f32 amplitudeToDecibel(const f32 amplitude_value);
    f32 decibelToAmplitude(const f32 decibel_value);
    void filling(const f32 value, f32* gain_ptr, const size_t number_of_sets, const u8 channels);
    void upDownMix51chTo2ch(f32* up_down_mix_levels_ptr, f32* data_ptr);
    void upDownMix51chTo71ch(f32* up_down_mix_levels_ptr, f32* data_ptr);
    void upDownMix71chTo2ch(f32* up_down_mix_levels_ptr, f32* data_ptr);
    void upDownMix71chTo51ch(f32* up_down_mix_levels_ptr, f32* data_ptr);
    bool upDownMix(const u8 channels_process, const u8 channels_output, f32* up_down_mix_levels_ptr, f32* data_ptr);
    void zeroFilling(f32* gain_ptr, const u8 channels);

}  // namespace nSound
