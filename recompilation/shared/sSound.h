#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPerformance.h"
#include "MtProperty.h"
#include "MtSynchronize.h"
#include "MtThread.h"
#include "audioout.h"
#include "cSoundCompressor.h"
#include "cSoundLimitter.h"
#include "cSoundMultiBandEQ.h"
#include "cSoundPanner.h"
#include "cSoundSilentDetectFilter.h"
#include "cSystem.h"
#include "ngs2_sce_reverb.h"
#include "ngs2_system.h"
#include "rSoundBank.h"
#include "rSoundRequest.h"
#include "rSoundSource.h"
#include "rSoundStreamRequest.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPerformanceTimer;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtUI;
class MtVector3;
struct SceNgs2ContextBufferInfo;
struct SceNgs2RackOption;
struct SceNgs2ReverbI3DL2Param;
struct SceNgs2SamplerVoiceState;
struct SceNgs2UserFxProcessContext;
struct SceNgs2WaveformBlock;
struct SceNgs2WaveformFormat;
struct SceNgs2WaveformInfo;
class cSoundCompressor;
class cSoundLimitter;
class cSoundMultiBandEQ;
class cSoundPanner;
class cSoundPicolaPitchShift;
class cSoundSilentDetectFilter;
class rSoundBank;
class rSoundCurveSet;
class rSoundDirectionalSet;
class rSoundEQ;
class rSoundRequest;
class rSoundReverb;
class rSoundSource;
class rSoundSourceStreamAT9;
class rSoundStreamRequest;
class uCoord;

// Declarations
class sSound;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using uintptr_t = __uintptr_t;
using SceNgs2Handle = uintptr_t;
using __int32_t = int;
using int32_t = __int32_t;
using SceUserServiceUserId = int32_t;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __intptr_t = __int64_t;
using f32 = float;
using intptr = __intptr_t;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sSound : public cSystem
{
public:
    enum VOICE_STATUS
    {
        VOICE_STATUS_STOP = 0,
        VOICE_STATUS_PLAY = 1,
        VOICE_STATUS_PAUSE = 2,
        VOICE_STATUS_PREPARE = 3,
        VOICE_STATUS_STOPPING = 4,
        VOICE_STATUS_NUM = 5,
    };
    enum VOICE_COMMAND
    {
        VOICE_COMMAND_INIT = 0,
        VOICE_COMMAND_REQUEST = 1,
        VOICE_COMMAND_STOP = 2,
        VOICE_COMMAND_PAUSE = 3,
        VOICE_COMMAND_RESUME = 4,
        VOICE_COMMAND_PREPARE = 5,
    };
    enum REQUEST_TYPE
    {
        REQUEST_TYPE_NO_POSITION = 0,
        REQUEST_TYPE_POSITION = 1,
        REQUEST_TYPE_PURSUE = 2,
    };
    enum EFFECT_TYPE
    {
        FX_NONE = -1,
        FX_REVERB = 0,
        FX_EQ = 1,
        FX_DELAY = 2,
        FX_MAX = 3,
    };
    enum ENTRY_COMMAND
    {
        ENTRY_COMMAND_INIT = 0,
        ENTRY_COMMAND_REQUEST = 1,
        ENTRY_COMMAND_PLAY = 2,
        ENTRY_COMMAND_STOP = 3,
        ENTRY_COMMAND_PAUSE = 4,
        ENTRY_COMMAND_RESUME = 5,
        ENTRY_COMMAND_CONTROL = 6,
        ENTRY_COMMAND_FADE = 7,
    };
    enum REVERB_MODE
    {
        REVERB_MODE_MONO = 0,
        REVERB_MODE_STEREO = 1,
    };
    enum DISTANCE_CURVE_TYPE
    {
        DISTANCE_CURVE_TYPE_VOLUME = 0,
        DISTANCE_CURVE_TYPE_REVERB = 1,
        DISTANCE_CURVE_TYPE_LFE = 2,
    };
    enum ENC_SOUND_KIND
    {
        ENC_SOUND_KIND_ALL = 0,
        ENC_SOUND_KIND_SE = 1,
        ENC_SOUND_KIND_STREAM = 2,
    };
    enum STOP_TYPE
    {
        STOP_TYPE_NORMAL = 0,
        STOP_TYPE_KEYOFF = 1,
        STOP_TYPE_KEYOFF_WITH_RELEASETIME = 2,
    };
    enum PAUSE_STATUS
    {
        PAUSE_STATUS_INIT = 0,
        PAUSE_STATUS_NORMAL = 1,
        PAUSE_STATUS_DELAYTIMER = 2,
        PAUSE_STATUS_ALL = 4,
        PAUSE_STATUS_SYSTEM = 8,
    };
    enum VOICE_CATEGORY
    {
        VOICE_CATEGORY_SE = 0,
        VOICE_CATEGORY_BGM = 1,
        VOICE_CATEGORY_ENV = 2,
        VOICE_CATEGORY_VOICE = 3,
        VOICE_CATEGORY_SYSTEM = 4,
        VOICE_CATEGORY_EVENT = 5,
    };
    enum SoundPlatform
    {
        SOUND_PF_UNKNOWN = 0,
        SOUND_PF_PS4 = 512,
        SOUND_PF_ALL = 65535,
    };
    enum VOLUME_MODE
    {
        VOLUME_MODE_FLOAT = 0,
        VOLUME_MODE_DECIBEL = 1,
    };
    enum CONTROL_TYPE
    {
        CONTROL_TYPE_POSITION = 0,
        CONTROL_TYPE_FADEIN = 1,
        CONTROL_TYPE_VOLUME_ABS = 2,
        CONTROL_TYPE_VOLUME_REL = 3,
        CONTROL_TYPE_VOLUME_RATIO = 4,
        CONTROL_TYPE_EFFECT_VOLUME_ABS = 5,
        CONTROL_TYPE_EFFECT_VOLUME_REL = 6,
        CONTROL_TYPE_EFFECT_VOLUME_RATIO = 7,
        CONTROL_TYPE_PAN_ABS = 8,
        CONTROL_TYPE_PAN_REL = 9,
        CONTROL_TYPE_PITCH_ABS = 10,
        CONTROL_TYPE_PITCH_REL = 11,
        CONTROL_TYPE_LISTENING = 12,
        CONTROL_TYPE_UPDATE_VOLUME_ONCE = 13,
        CONTROL_TYPE_MULTI_LISTENING = 14,
        CONTROL_TYPE_WORK_AREA = 15,
        CONTROL_TYPE_DELAYTIMER = 16,
        CONTROL_TYPE_EXTERNAL_VOLUME = 17,
        CONTROL_TYPE_EXTERNAL_EFFECT_VOLUME = 18,
        CONTROL_TYPE_PRIORITY = 19,
        CONTROL_TYPE_PRIORITY_MODE = 20,
        CONTROL_TYPE_EXTRACT_PARAM = 21,
        CONTROL_TYPE_CENTERVOLUME = 22,
        CONTROL_TYPE_SE_PROGRAM_NO = 23,
        CONTROL_TYPE_QUATERNION = 24,
        CONTROL_TYPE_COORD = 25,
        CONTROL_TYPE_PLAY_POSITION = 26,
        CONTROL_TYPE_PLAY_MARKER = 27,
        CONTROL_TYPE_REVERB_SEND_ABS = 28,
        CONTROL_TYPE_FILTER_FREQ_ABS = 29,
        CONTROL_TYPE_POSITION_OFFSET = 30,
        CONTROL_TYPE_VOLUMECURVEID = 31,
        CONTROL_TYPE_EFFECTCURVEID = 32,
        CONTROL_TYPE_DIRECTIONALCURVEID = 33,
        CONTROL_TYPE_EFFECT = 34,
        CONTROL_TYPE_EQ = 35,
        CONTROL_TYPE_SET_VOLUME_ABS = 36,
        CONTROL_TYPE_SET_VOLUME_REL = 37,
        CONTROL_TYPE_SET_VOLUME_RATIO = 38,
        CONTROL_TYPE_VSURROUND_BYPASS = 39,
        CONTROL_TYPE_LFE_VOLUME_ABS = 40,
        CONTROL_TYPE_LFE_VOLUME_REL = 41,
        CONTROL_TYPE_LFE_VOLUME_RATIO = 42,
        CONTROL_TYPE_LFECURVEID = 43,
        CONTROL_TYPE_EQ_EFFECT = 44,
        CONTROL_TYPE_DOPPLERSCALER = 45,
        CONTROL_TYPE_INTERLEAVED_DATA_VOLUME = 46,
        CONTROL_TYPE_PICOLA_PITCHSHIFT = 47,
        CONTROL_TYPE_STREAM_SILENT_DETECT = 48,
        CONTROL_TYPE_NAITVEPARAM = 49,
    };
    enum BANK_REQUEST_TYPE
    {
        BANK_REQUEST_TYPE_PROGRAM = 0,
        BANK_REQUEST_TYPE_ELEMENT = 1,
    };
    enum FADE_TYPE
    {
        FADE_TYPE_FADEIN = 0,
        FADE_TYPE_MOVEVOL_ABS = 1,
        FADE_TYPE_MOVEVOL_REL = 2,
        FADE_TYPE_MOVEVOL_RAT = 3,
        FADE_TYPE_FADEOUT = 4,
    };
    enum MARKER_PLAY_TYPE
    {
        MARKER_PLAY_TYPE_ID = 0,
        MARKER_PLAY_TYPE_SAMPLE = 1,
        MARKER_PLAY_TYPE_INDEX = 2,
    };
    enum EQ_CATEGORY
    {
        EQC_CATEGORY0 = 0,
        EQC_CATEGORY1 = 1,
        EQC_CATEGORY2 = 2,
        EQC_CATEGORY3 = 3,
        EQC_CATEGORY_R0 = 4,
        EQC_CATEGORY_R1 = 5,
        EQC_CATEGORY_R2 = 6,
        EQC_CATEGORY_R3 = 7,
        EQC_MASTER = 8,
        EQC_MAX = 9,
    };
    enum EQ_ENABLE_SW
    {
        EQES_NONE = 0,
        EQES_LOW = 1,
        EQES_MIDLOW = 2,
        EQES_MIDHIGH = 4,
        EQES_HIGH = 8,
        EQES_ALL = 15,
    };
    enum EQ_FILTER_TYPE
    {
        EQFT_PEQ = 0,
        EQFT_LSF = 1,
        EQFT_HPF = 2,
        EQFT_HSF = 3,
        EQFT_LPF = 4,
    };
    enum STATUS
    {
        STATUS_STOP = 0,
        STATUS_PLAY = 1,
        STATUS_PAUSE = 2,
        STATUS_PREPARE = 3,
        STATUS_STOPPING = 4,
        STATUS_NUM = 5,
    };
public:
    class MyDTI;
    class NativeVoicePool;
    class NativeVoice;
    class Voice;
    class VoiceAccessor;
    struct _SOUND_EXTRACT_PARAM;
    class NativeSystem;
    class StreamVoice;
    class SeVoice;
    class ExternalVoice;
    class SeEntry;
    class Entry;
    union ControlParam;
    class StreamEntry;
    struct SE_ENTRY_PARAMETER;
    struct STREAM_ENTRY_PARAMETER;
    class EffectBase;
    class EffectUnitBase;
    struct Listening;
    struct SpeakerAngle;
    class UpdateThread;
    class LoadThread;
    struct SeRequestItem;
    struct RandomHistory;
    struct SoundFrameCallback;
    class ReverbResource;
    struct ReverbParameter;
    class EffectResourceWork;
    struct REVERB_PARAMETER;
    struct ReverbParameterWork;
    class EQResource;
    struct EQParameter;
    struct EQ_PARAMETER;
    struct EQParameterWork;
    struct SOUNDDRIVER_INIT_PARAM;
    class SeEntryControlParam;
    class EntryControlParam;
    struct SeExtractParam;
    class StreamEntryControlParam;
    class NativeSystemPS4;
    class NGS2System;
    class AudioOut;
    class AudioOutThread;
    class AudioOutPort;
    class NGS2Routing;
    class NGS2VoiceMastering;
    class NGS2Voice;
    class NGS2RackMastering;
    class NGS2Rack;
    class NGS2RackSampler;
    class SeVoiceAccessor;
    class StreamVoiceAccessor;
    class NGS2VoiceSampler;
    class NGS2VoiceSubmixer;
    class NGS2VoiceReverb;
    class NGS2RackSubmixer;
    class NGS2RackReverb;
    class NGS2VoiceSubmixerEQ;
    class NGS2VoiceSubmixerCompLimitter;
    class NGS2VoiceSubmixerSilentDetectFilter;
    class NGS2RoutingNoEffect;
    class NGS2RoutingReverbEQ;
    class NativeVoicePS4;
    class NativeVoiceSePS4;
    class NativeVoiceStreamPS4;
    class NativeVoiceExternalPS4;
    class NativeVoicePoolPS4;
public:
    using CALLBACK_FUNC = void(*)(sSound::VoiceAccessor&, void*);
    using SOUND_EXTRACT_PARAM = sSound::_SOUND_EXTRACT_PARAM;
    using SOUNDDRIVER_INIT_PARAM = sSound::SOUNDDRIVER_INIT_PARAM;
    using ENTRY_CALLBACK_FUNC = void(*)(void*);
    using USER_FX_FUNC = s32(*)(f32* *, const u32, const u32, void*);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class NativeVoice
    {
    public:
        NativeVoice();
        virtual ~NativeVoice() {}
        virtual void init();  // vtable slot 2
        virtual void setupVoice(sSound::Voice* pVoice);  // vtable slot 3
        virtual void freeVoice();  // vtable slot 4
        virtual void freeBuffer();  // vtable slot 5
        virtual void prepare();  // vtable slot 6
        virtual void play();  // vtable slot 7
        virtual void stop();  // vtable slot 8
        virtual void stopCompel();  // vtable slot 9
        virtual void pause();  // vtable slot 10
        virtual void resume();  // vtable slot 11
        virtual void playExternal();  // vtable slot 12
        virtual void stopExternal();  // vtable slot 13
        virtual void pauseExternal();  // vtable slot 14
        virtual void resumeExternal();  // vtable slot 15
        virtual void updateExternal();  // vtable slot 16
        virtual void updateVoiceParams(sSound::Voice* pVoice);  // vtable slot 17
        virtual void applyVolume();  // vtable slot 18
        virtual void applyPitch();  // vtable slot 19
        virtual void applyFilter();  // vtable slot 20
        virtual void updateVolume(sSound::Voice* pVoice);  // vtable slot 21
        virtual void updatePan(sSound::Voice* pVoice);  // vtable slot 22
        virtual bool isEnd();  // vtable slot 23
        virtual bool isPrepared();  // vtable slot 24
        virtual void shutdown();  // vtable slot 25
        virtual void loadBuffer();  // vtable slot 26
        virtual void updateBuffer();  // vtable slot 27
        virtual void updateCurrentPlayPosition();  // vtable slot 28
        virtual void setupForPresetOscillator();  // vtable slot 29
        virtual void setupForWaveOscillator();  // vtable slot 30
        virtual bool openSource();  // vtable slot 31
        virtual bool closeSource();  // vtable slot 32
        virtual void updatePCMStream();  // vtable slot 33
        virtual bool isAvailableWrite(u32 threshold) const;  // vtable slot 34
        virtual void write(void* pbuf, u32 size);  // vtable slot 35
        virtual void fill();  // vtable slot 36
        virtual bool isBufferFill();  // vtable slot 37
        virtual void setVoiceChannelNum(u32 channelNum);  // vtable slot 38
        virtual void setWaveInputTypeExternal(s32 type);  // vtable slot 39
        virtual void setRestrictedExternal(bool restricted);  // vtable slot 40
        virtual s32 getPicolaPitchShiftNo() const;  // vtable slot 41
        virtual void setPicolaPitchShiftNo(s32 no);  // vtable slot 42
        virtual s32 getSilentDetect(rSoundStreamRequest* pRequest, u32 reqNo, uintptr thisId);  // vtable slot 43
    };
public:
    class Voice
    {
    public:
        enum VOICE_TYPE
        {
            VOICE_TYPE_SE = 0,
            VOICE_TYPE_STREAM = 1,
            VOICE_TYPE_EXTERNAL = 2,
        };
    public:
        Voice();
        virtual ~Voice();
        void init();
        void final();
        virtual void play();  // vtable slot 2
        virtual void stop();  // vtable slot 3
        void pause();
        void resume();
        virtual void update();  // vtable slot 4
        void updatePosition();
        void updateVolume();
        void setVolume(f32 vol);
        void setPitch(f32 pitch);
        void setPan(s32 pan);
        u32 getStatus() const;
        u32 getPriority() const;
        const rSoundSource* getSource() const;
        void setSource(rSoundSource* pSource);
        void setCallback(sSound::CALLBACK_FUNC cb, void* arg);
        void callback();
        f32 getCategoryMasterVolume() const;
        bool isRequestKeyMatching(uintptr requestID, u32 reqNo, uintptr thisID);
        bool isRequestIdMatching(uintptr requestID, u32 global, s32 ID_1, s32 ID_2, s32 ID_3, uintptr thisId);
    protected:
        void updatePan();
        void updatePitch();
        void updateFilter();
        void applyVolume();
        void applyPitch();
        void applyFilter();
        virtual void freeVoice();  // vtable slot 5
        void updateVolume1ch(f32 dry_vol, f32 efc_vol, f32 lfe_vol);
        void updateVolume2ch(f32 dry_vol, f32 efc_vol, f32 lfe_vol);
        void updateVolume6ch(f32 dry_vol, f32 efc_vol, f32 lfe_vol);
        void updateVolumeSpeakerSet(f32 dry_vol, f32 efc_vol, f32 lfe_vol);
        void checkSurroundVolume(f32* surroundVol, f32* effectSendLevel);
    public:
        sSound::VOICE_STATUS mStatus;  // offset: 0x8
        sSound::VOICE_COMMAND mVoiceCommand;  // offset: 0xc
        uintptr mRequestId;  // offset: 0x10
        u32 mReqNo;  // offset: 0x18
        uintptr mThisId;  // offset: 0x20
        u32 mGlobal;  // offset: 0x28
        s32 mID_1;  // offset: 0x2c
        s32 mID_2;  // offset: 0x30
        s32 mID_3;  // offset: 0x34
        u32 mPriority;  // offset: 0x38
        u32 mPrioMode;  // offset: 0x3c
        u32 mLimit;  // offset: 0x40
        u32 mRequestCount;  // offset: 0x44
        u32 mCategory;  // offset: 0x48
        MtVector3 mPosition;  // offset: 0x50
        MtVector3 mPositionOffset;  // offset: 0x60
        MtQuaternion mQuaternion;  // offset: 0x70
        uCoord* mpCoord;  // offset: 0x80
        s32 mJointNo;  // offset: 0x88
        f32 mVolume;  // offset: 0x8c
        s32 mPan;  // offset: 0x90
        s32 mPitch;  // offset: 0x94
        f32 mRatioVolume;  // offset: 0x98
        f32 mRatioEffectVolume;  // offset: 0x9c
        f32 mReverbSendLevel;  // offset: 0xa0
        u32 mChannelNum;  // offset: 0xa4
        s32 mVolumeCurveId;  // offset: 0xa8
        s32 mEffectCurveId;  // offset: 0xac
        s32 mDirectionalCurveId;  // offset: 0xb0
        u32 mBookingTimer;  // offset: 0xb4
        s32 mLink;  // offset: 0xb8
        u32 mPauseStatus;  // offset: 0xbc
        sSound::REQUEST_TYPE mRequestType;  // offset: 0xc0
        f32 mFinalPitch;  // offset: 0xc4
        sSound::CALLBACK_FUNC mpCallbackFunc;  // offset: 0xc8
        void* mpCallbackArg;  // offset: 0xd0
        intptr mWorkArea[2];  // offset: 0xd8
        f32 mExternalVolume;  // offset: 0xe8
        f32 mExternalEffectVolume;  // offset: 0xec
        VOICE_TYPE mVoiceType;  // offset: 0xf0
        u32 mVoiceIndex;  // offset: 0xf4
        u32 mStartTime;  // offset: 0xf8
        u32 mPauseStartTime;  // offset: 0xfc
        u32 mDelayTime;  // offset: 0x100
        u32 mPlay : 1;  // offset: 0x104
        u32 mForceUpdate : 1;  // offset: 0x104
        u32 mDynamicVolume : 1;  // offset: 0x104
        u32 mDynamicPitch : 1;  // offset: 0x104
        u32 mFilterEnable : 1;  // offset: 0x104
        u32 mFilterType : 3;  // offset: 0x104
        f32 mFilterFreq;  // offset: 0x108
        f32 mFilterGain;  // offset: 0x10c
        f32 mFilterQ;  // offset: 0x110
        f32 mFinalFilterFreq;  // offset: 0x114
        bool mIsUpdateVolume;  // offset: 0x118
        bool mUpdateVolumeTrigger;  // offset: 0x119
        f32 mEffectSendLevel[8];  // offset: 0x11c
        f32 mLFEVolume;  // offset: 0x13c
        f32 mRatioLFEVolume;  // offset: 0x140
        u32 mCenterVolume;  // offset: 0x144
        s32 mLFECurveId;  // offset: 0x148
        s32 mEqNo;  // offset: 0x14c
        s32 mEqEffectNo;  // offset: 0x150
        s32 mListeningIndexBit;  // offset: 0x154
        f32 mDistance[4][8];  // offset: 0x158
        f32 mSurroundVolume[8][8];  // offset: 0x1d8
        f32 mPannerGains[8][4][8];  // offset: 0x2d8
        f32 mInterleavedDataVolume[8];  // offset: 0x6d8
        f32 mIntersectVolume[4][8];  // offset: 0x6f8
        f32 mExternalLFEVolume;  // offset: 0x778
        f32 mDopplerScaler;  // offset: 0x77c
        s32 mDopplerEffect;  // offset: 0x780
        f32 mInteriorDistance;  // offset: 0x784
        void* mpSpeakerSet;  // offset: 0x788
        MtVector3 mSpeakerPosition[4][8];  // offset: 0x790
        f32 mSpeakerDirectionalIntensity[4][8];  // offset: 0x990
        f32 mExtraVolume;  // offset: 0xa10
        f32 mExtraPitch;  // offset: 0xa14
        s8 mExtraPan;  // offset: 0xa18
        f32 mExtraFilterFreq;  // offset: 0xa1c
        u32 mEffectNo : 3;  // offset: 0xa20
        void* mpNativeParam;  // offset: 0xa28
        rSoundSource* mpSource;  // offset: 0xa30
        sSound::NativeVoice* mpNativeVoice;  // offset: 0xa38
        u32 mVoiceNum : 3;  // offset: 0xa40
        u32 mMidi : 1;  // offset: 0xa40
        u32 mVSurroundBypass : 1;  // offset: 0xa40
        u32 padding;  // offset: 0xa44
    };
public:
    class VoiceAccessor
    {
    public:
        VoiceAccessor(sSound::Voice* pVoice);
        ~VoiceAccessor();
        u32 getChannelNum() const;
        f32 getVolume(u32 volMode) const;
        f32 getEffectVolume(u32 volMode) const;
        void setVolumeAbs(f32 vol, u32 volMode);
        void setEffectVolumeAbs(f32 vol, u32 volMode);
        void setVolumeRel(f32 vol, u32 volMode);
        void setEffectVolumeRel(f32 vol, u32 volMode);
        void setVolumeRatio(f32 vol);
        void setEffectVolumeRatio(f32 vol);
        s32 getPitch() const;
        void setPitchAbs(s32 pitch);
        void setPitchRel(s32 pitch);
        s32 getPan() const;
        void setPanAbs(u32 pan);
        void setPanRel(s32 pan);
        MtVector3 getPosition() const;
        void setPositionAbs(const MtVector3& pos);
        void setPositionRel(const MtVector3& pos);
        s32 getFreeArea(u32 no) const;
        u32 getRequestNo() const;
        uintptr getThisId() const;
        size_t getListeningIndex() const;
        void setListeningIndex(size_t index);
        bool isLoop() const;
        intptr getWorkArea(u32 no) const;
        void setWorkArea(u32 no, intptr value);
        f32 getExternalVolume(u32 volMode) const;
        f32 getExternalEffectVolume(u32 volMode) const;
        f32 getExternalLFEVolume(u32 volMode) const;
        void setExternalVolume(f32 volume, u32 volMode);
        void setExternalEffectVolume(f32 volume, u32 volMode);
        void setExternalLFEVolume(f32 volume, u32 volMode);
        void setDelayTimer(u32 delayTime);
        u8 getPriority() const;
        void setPriority(u8 priority);
        u8 getPriorityMode() const;
        void setPriorityMode(u8 priorityMode);
        void setCenterVol(const u32 volume);
        u32 getCenterVol() const;
        void setExtractParam(sSound::SOUND_EXTRACT_PARAM param);
        sSound::SOUND_EXTRACT_PARAM getExtractParam();
        uCoord* getCoord() const;
        void setCoord(uCoord* pCoord);
        void setPositionOffset(const MtVector3& pos);
        MtVector3 getPositionOffset() const;
        void stopVoice();
        bool isSeVoice() const;
        bool isStreamVoice() const;
        void setVolumeCurveID(s32 id);
        s32 getVolumeCurveID() const;
        void setEffectCurveID(s32 id);
        s32 getEffectCurveID() const;
        void setDirectionalCurveID(s32 id);
        s32 getDirectionalCurveID() const;
        s32 getEffectIndex() const;
        void setEffectIndex(s32 index);
        u32 getRequestType();
        u32 getVoiceIndex();
        void setVSurroundBypass(bool bypass);
        u32 getCategory() const;
        f32 getLFEVolume(u32 volMode) const;
        void setLFEVolumeAbs(f32 vol, u32 volMode);
        void setLFEVolumeRel(f32 vol, u32 volMode);
        void setLFEVolumeRatio(f32 vol);
        f32 getSurroundVolume(u32 volMode) const;
        void setLFECurveID(s32 id);
        s32 getLFECurveID() const;
        s32 getEqIndex() const;
        void setEqIndex(s32 index);
        s32 getEqEffectIndex() const;
        void setEqEffectIndex(s32 index);
        bool doesHaveSpeakerSet() const;
        u32 getSpeakerSetting() const;
        MtVector3 getSpeakerPosition(u32 spk_num, s32 listeningIndex) const;
        MtVector3 getWorldSpeakerPosition(u32 spk_num, s32 listeningIndex) const;
        f32 getIntersectVolume(s32 listeningIndex, u32 volMode) const;
        void setIntersectVolume(f32 intersectVolume, s32 listeningIndex, u32 volMode);
        f32 getSpeakerIntersectVolume(u32 speakerIndex, s32 listeningIndex, u32 volMode);
        void setSpeakerIntersectVolume(f32 intersectVolume, u32 speakerIndex, s32 listeningIndex, u32 volMode);
        f32 getDistanceVolume(s32 listeningIndex, u32 volMode) const;
        f32 getInterleavedDataVolume(size_t speakerIndex, u32 volMode);
        void setInterleavedDataVolume(size_t speakerIndex, f32 volume, u32 volMode);
    protected:
        sSound::Voice* mpVoice;  // offset: 0x0
    };
public:
    struct _SOUND_EXTRACT_PARAM
    {
    public:
        s16 ID_1;  // offset: 0x0
        s16 ID_2;  // offset: 0x2
        s16 ID_3;  // offset: 0x4
        u16 BookingTimer;  // offset: 0x6
        u8 GlobalID;  // offset: 0x8
        u8 Limit;  // offset: 0x9
        u8 Priority;  // offset: 0xa
        u8 PriorityMode;  // offset: 0xb
        u32 padding[2];  // offset: 0xc
    };
public:
    class NativeSystem
    {
    public:
        NativeSystem();
        virtual ~NativeSystem();
        // Address: 0x01ba8c30 - 0x01ba8c31 (1 bytes)
        virtual void init() {}  // vtable slot 2
        // Address: 0x01ba8c40 - 0x01ba8c41 (1 bytes)
        virtual void setUpdateThreadPriority() {}  // vtable slot 3
        // Address: 0x01ba8c50 - 0x01ba8c51 (1 bytes)
        virtual void setLoadThreadPriority() {}  // vtable slot 4
        // Address: 0x01ba8c60 - 0x01ba8c61 (1 bytes)
        virtual void move() {}  // vtable slot 5
        virtual void updateExecute();  // vtable slot 6
        virtual void loadExecute();  // vtable slot 7
        virtual void updateVoice();  // vtable slot 8
        // Address: 0x01ba8c90 - 0x01ba8c91 (1 bytes)
        virtual void setRouting(const u32 routing) {}  // vtable slot 9
        virtual u32 getRouting() const;  // vtable slot 10
        // Address: 0x01ba8cb0 - 0x01ba8cb1 (1 bytes)
        virtual void correctVolume(sSound::Voice* pVoice) {}  // vtable slot 11
        // Address: 0x01ba8cc0 - 0x01ba8cc1 (1 bytes)
        virtual void initAudio() {}  // vtable slot 12
        // Address: 0x01ba8cd0 - 0x01ba8cd1 (1 bytes)
        virtual void finalAudio() {}  // vtable slot 13
        // Address: 0x01ba8ce0 - 0x01ba8ce1 (1 bytes)
        virtual void createProperty(MtPropertyList& s) {}  // vtable slot 14
        // Address: 0x01ba8cf0 - 0x01ba8cf1 (1 bytes)
        virtual void createUI(MtProperty& prop) {}  // vtable slot 15
        virtual u32 getWarningUpdateInterval() const;  // vtable slot 16
        // Address: 0x01ba8d10 - 0x01ba8d11 (1 bytes)
        virtual void createEffect(u32 index, u32 type) {}  // vtable slot 17
        // Address: 0x01ba8d20 - 0x01ba8d21 (1 bytes)
        virtual void setFX(const void* pParam) {}  // vtable slot 18
        // Address: 0x01ba8d30 - 0x01ba8d31 (1 bytes)
        virtual void getFX(void* pParam) {}  // vtable slot 19
        virtual sSound::EFFECT_TYPE getFxType(u32 index) const;  // vtable slot 20
        virtual u16 getPlatform();  // vtable slot 21
        virtual f32 getCategoryMasterVolume(u32 category, const sSound::Voice* pVoice);  // vtable slot 22
        // Address: 0x01ba8d60 - 0x01ba8d61 (1 bytes)
        virtual void setEQEnable(u32 index, bool enable) {}  // vtable slot 23
        virtual bool checkFileAccessEnable() const;  // vtable slot 24
        // Address: 0x01ba8d80 - 0x01ba8d81 (1 bytes)
        virtual void setReverbOutputChannel(u32 reverbIndex, u32 speakerIndex, bool b) {}  // vtable slot 25
        virtual bool getReverbOutputChannel(u32 reverbIndex, u32 speakerIndex);  // vtable slot 26
        // Address: 0x01ba8da0 - 0x01ba8da1 (1 bytes)
        virtual void updateUpDownMixGains() {}  // vtable slot 27
        virtual u32 getSystemChannelNum() const;  // vtable slot 28
        // Address: 0x01ba8dc0 - 0x01ba8dc1 (1 bytes)
        virtual void updateChannelsProcess() {}  // vtable slot 29
        void setUpdateThreadInterval(const u32 updateThreadInterval);
        bool getPICOLAPitchShiftEnable();
        virtual void setPICOLAPitchShiftEnable(bool b);  // vtable slot 30
        s32 getPICOLAPitchShiftFreeAreaNo();
        void setPICOLAPitchShiftFreeAreaNo(s32);
        virtual void initPICOLAPitchShift();  // vtable slot 31
        virtual void releasePICOLAPitchShift();  // vtable slot 32
        virtual bool checkPICOLAPitchShift(s32 picolaPitchShiftNo, rSoundSource* pSource);  // vtable slot 33
        virtual void setupPICOLAPitchShift(sSound::StreamVoice* pStreamVoice);  // vtable slot 34
        virtual bool preparePICOLAPitchShift(s32 picolaPitchShiftNo, rSoundSource* pSource, u32 startPosition);  // vtable slot 35
        virtual void picolaProcessLock(u32 index);  // vtable slot 36
        virtual void picolaProcessUnLock(u32 index);  // vtable slot 37
        virtual cSoundPicolaPitchShift* getPICOLAPitchShift(const s32 index);  // vtable slot 38
    protected:
        void initPicolaBuffer(u32 index);
        void setSamples(u32 index, s32 samples);
        void setPeriod(u32 index, u32 periodNum, rSoundSource::FUNDAMENTAL_PERIOD* period);
        void setLoop(u32 index, bool loop, u32 loopStart, u32 loopEnd);
    public:
        virtual f32 getStreamSilentDecectionThreshold();  // vtable slot 39
        // Address: 0x01ba8e50 - 0x01ba8e51 (1 bytes)
        virtual void setStreamSilentDecectionThreshold(f32 dB) {}  // vtable slot 40
    protected:
        u32 mUpdateThreadInterval;  // offset: 0x8
        cSoundPicolaPitchShift* mpPICOLAPitchShift[4];  // offset: 0x10
        bool mPICOLAPitchShiftEnable;  // offset: 0x30
        s32 mPICOLAPitchShiftFreeAreaNo;  // offset: 0x34
        static const u32 DEFAULT_UPDATE_THREAD_INTERVAL = 20;
        static const u32 LOAD_THREAD_INTERVAL = 50;
    };
public:
    class StreamVoice : public sSound::Voice
    {
    public:
        enum FADE_STATUS
        {
            FADE_STATUS_IDLE = 0,
            FADE_STATUS_FADEIN = 1,
            FADE_STATUS_VOLUME_MOVE = 2,
            FADE_STATUS_FADEOUT = 3,
        };
        enum SHUTDOWN_STATUS
        {
            SHUTDOWN_STATUS_IDLE = 0,
            SHUTDOWN_STATUS_CLOSE = 1,
            SHUTDOWN_STATUS_FREE = 2,
        };
    public:
        StreamVoice();
        virtual ~StreamVoice();
        void init();
        void final();
        void acquireVoice();
        void prepare();
        virtual void play();  // vtable slot 2
        virtual void stop();  // vtable slot 3
        virtual void update();  // vtable slot 4
        void stopCompel();
        virtual void resume();  // vtable slot 6
        void fadeControl();
        void setFadeParam(u32 fadeType, u32 fadeTime, f32 volume, f32 effectSend, f32 lfeSend);
        void setStreamRequest(rSoundStreamRequest* pResource);
        rSoundStreamRequest* getRequest() const;
        void updateBuffer();
        void loadBuffer();
        void executeCommand();
    private:
        void setup();
        bool getNativeVoice();
        virtual void freeVoice();  // vtable slot 5
        void freeResource();
        void shutdown();
        void closeSource();
    public:
        FADE_STATUS mFadeStatus;  // offset: 0xa48
        f32 mFadeTargetVolume;  // offset: 0xa4c
        f32 mFadeTargetEffectVolume;  // offset: 0xa50
        f32 mFadeVolume;  // offset: 0xa54
        f32 mFadeEffectVolume;  // offset: 0xa58
        f32 mFadeVolumeRatio;  // offset: 0xa5c
        f32 mFadeEffectVolumeRatio;  // offset: 0xa60
        f32 mFadeTargetLFEVolume;  // offset: 0xa64
        f32 mFadeLFEVolume;  // offset: 0xa68
        f32 mFadeLFEVolumeRatio;  // offset: 0xa6c
        s32 mPicolaPitchShiftCent;  // offset: 0xa70
        u32 mFadeTime;  // offset: 0xa74
        u32 mStartPosition;  // offset: 0xa78
        u32 mFrameTime;  // offset: 0xa7c
        u32 mAbsoluteTime;  // offset: 0xa80
        rSoundStreamRequest::SOUND_STREAM_READ_TYPE mReadType;  // offset: 0xa84
        u32 mSourceID;  // offset: 0xa88
        bool mIsRelease;  // offset: 0xa8c
        bool mIsEnd;  // offset: 0xa8d
        bool mIsStreamActive;  // offset: 0xa8e
        bool mIsSourceOpen;  // offset: 0xa8f
        bool mIsPreparePause;  // offset: 0xa90
        bool mIsStopped;  // offset: 0xa91
        u32 mMarkerValue;  // offset: 0xa94
        u16 mMarkerType;  // offset: 0xa98
        u16 mMarkerIndex;  // offset: 0xa9a
        rSoundStreamRequest::SoundSource* mpStreamSource;  // offset: 0xaa0
        u32 mCurrentPlayPosition;  // offset: 0xaa8
        bool mEnableSilentDetection;  // offset: 0xaac
        rSoundStreamRequest* mpStreamRequest;  // offset: 0xab0
        u32 mIdentifier;  // offset: 0xab8
        u32 mAbort : 1;  // offset: 0xabc
        MtCriticalSection mStreamLoadSection;  // offset: 0xac0
        SHUTDOWN_STATUS mShutdownStatus;  // offset: 0xac8
    };
public:
    class SeVoice : public sSound::Voice
    {
    public:
        SeVoice();
        virtual ~SeVoice();
        void init();
        void final();
        void prepare(u32 prog_no, u32 elem_index, u32 vel, u32 key);
        virtual void play();  // vtable slot 2
        virtual void stop();  // vtable slot 3
        void keyOff();
        virtual void update();  // vtable slot 4
        void setBank(rSoundBank* pBank);
        void setRequest(rSoundRequest* pResource);
        rSoundRequest* getRequest() const;
        rSoundBank* getBank() const;
        void applyEnvelope();
        void executeCommand();
        virtual void freeVoice();  // vtable slot 5
    private:
        bool setup();
        bool getNativeVoice();
        void freeResource();
        void setupForPresetOscillator();
        void setupForWaveOscillator();
        void setupWithBank(u32 prog_no, u32 elem_index, u32 vel, u32 key);
        bool applyAmpEnvelope(const rSoundBank::Element* pe, u32 absolute_time, u32 time);
        void applyPitchEnvelope(const rSoundBank::Element* pe, u32 absolute_time, u32 time);
    public:
        rSoundBank* mpBank;  // offset: 0xa48
        u32 mProgramNumber : 16;  // offset: 0xa50
        u32 mElementIndex : 16;  // offset: 0xa50
        u32 mOscillator : 4;  // offset: 0xa54
        u32 mKey : 8;  // offset: 0xa54
        u32 mFlangingTime : 12;  // offset: 0xa54
        f32 mAmpEnvelope;  // offset: 0xa58
        f32 mPitchEnvelope;  // offset: 0xa5c
        u32 mAmpAttackTime;  // offset: 0xa60
        u32 mAmpDecayTime;  // offset: 0xa64
        u32 mAmpReleaseTime;  // offset: 0xa68
        f32 mInvAmpAttackTime;  // offset: 0xa6c
        f32 mInvAmpDecayTime;  // offset: 0xa70
        f32 mInvAmpReleaseTime;  // offset: 0xa74
        f32 mAmpSustainLevel;  // offset: 0xa78
        f32 mAmpSustainRate;  // offset: 0xa7c
        u32 mPitchAttackTime;  // offset: 0xa80
        u32 mPitchDecayTime;  // offset: 0xa84
        u32 mPitchReleaseTime;  // offset: 0xa88
        f32 mInvPitchAttackTime;  // offset: 0xa8c
        f32 mInvPitchDecayTime;  // offset: 0xa90
        f32 mInvPitchReleaseTime;  // offset: 0xa94
        f32 mPitchInitialLevel;  // offset: 0xa98
        f32 mPitchAttackLevel;  // offset: 0xa9c
        f32 mPitchSustainLevel;  // offset: 0xaa0
        f32 mPitchReleaseLevel;  // offset: 0xaa4
        f32 mPitchSustainRate;  // offset: 0xaa8
        u32 mKeyOff : 1;  // offset: 0xaac
        u32 mRelease : 1;  // offset: 0xaac
        f32 mNoteOffAmpLevel;  // offset: 0xab0
        f32 mNoteOffPitchLevel;  // offset: 0xab4
        u32 mNoteOffStartTime;  // offset: 0xab8
        f32 mElementVolume;  // offset: 0xabc
        f32 mElementPitch;  // offset: 0xac0
        f32 mExternalFilterFreq;  // offset: 0xac4
        rSoundRequest* mpRequest;  // offset: 0xac8
    };
public:
    class ExternalVoice : public sSound::Voice
    {
    public:
        ExternalVoice();
        virtual ~ExternalVoice();
        virtual bool setup();  // vtable slot 6
        virtual void init();  // vtable slot 7
        virtual void play();  // vtable slot 2
        virtual void stop();  // vtable slot 3
        virtual void pause();  // vtable slot 8
        virtual void resume();  // vtable slot 9
        virtual void update();  // vtable slot 4
        // Address: 0x01ba8eb0 - 0x01ba8eb1 (1 bytes)
        virtual void setPitch() {}  // vtable slot 10
        virtual void freeResource();  // vtable slot 11
        void setBitsPerSample(u32 bits);
        void setSampleRate(u32 rate);
        void setWaveInputType(s32 type);
        bool isAvailableWrite(u32 threshold) const;
        void write(void* pbuf, u32 size);
        void fill();
        bool isBufferFill();
        void setVoiceChannelNum(u32 channelNum);
        void final();
        void lock();
        void unlock();
    public:
        u32 mWritePosition;  // offset: 0xa48
        u32 mReadPosition;  // offset: 0xa4c
        u32 mBitsPerSample;  // offset: 0xa50
        u32 mSampleRate;  // offset: 0xa54
        MtCriticalSection mExtVoiceCS;  // offset: 0xa58
    };
public:
    union ControlParam
    {
    public:
        uintptr uParam[5];  // offset: 0x0
        intptr sParam[5];  // offset: 0x0
        f32 fParam[5];  // offset: 0x0
        void* pParam[5];  // offset: 0x0
        f32 Position[5];  // offset: 0x0
        sSound::SOUND_EXTRACT_PARAM exParam;  // offset: 0x0
    };
public:
    struct SE_ENTRY_PARAMETER
    {
    public:
        rSoundRequest* mpResource;  // offset: 0x0
        u32 mReqNo;  // offset: 0x8
        uintptr mThisId;  // offset: 0x10
    };
public:
    struct STREAM_ENTRY_PARAMETER
    {
    public:
        rSoundStreamRequest* mpResource;  // offset: 0x0
        u32 mReqNo;  // offset: 0x8
        uintptr mThisId;  // offset: 0x10
    };
public:
    class EffectBase : public MtObject
    {
    public:
        EffectBase();
        virtual ~EffectBase();
        virtual void init();  // vtable slot 6
        virtual void final();  // vtable slot 7
        virtual bool getEnable() const;  // vtable slot 8
        virtual void setEnable(bool e);  // vtable slot 9
        virtual void applyParameter();  // vtable slot 10
        virtual f32 getOutputLevel() const;  // vtable slot 11
        virtual void setOutputLevel(f32 lv);  // vtable slot 12
        virtual const void* getParameter() const;  // vtable slot 13
        virtual void setParameter(const void* pParam);  // vtable slot 14
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        s32 getType() const;
        static void* operator new(size_t);
        static void operator delete(void* p);
    protected:
        void setEffectUnit(sSound::EffectUnitBase* peu);
        void setParameterInfo(void* pParam, u32 size);
    protected:
        s32 mType;  // offset: 0x8
        f32 mOutputLevel;  // offset: 0xc
        u32 mOutputChannelNum;  // offset: 0x10
        bool mModify;  // offset: 0x14
        bool mEnable;  // offset: 0x15
        u32 mParameterSize;  // offset: 0x18
        void* mpParameter;  // offset: 0x20
        sSound::EffectUnitBase* mpEffectUnit;  // offset: 0x28
    };
public:
    class EffectUnitBase
    {
    public:
        EffectUnitBase();
        virtual ~EffectUnitBase() {}
        virtual void init();  // vtable slot 2
        virtual void final();  // vtable slot 3
        virtual void clear();  // vtable slot 4
    protected:
        void beginProcess();
        void endProcess();
    };
public:
    struct Listening
    {
    public:
        MtVector3 OldPosition;  // offset: 0x0
        MtMatrix ListeningMatrix;  // offset: 0x10
        MtMatrix ListeningMatrixInverse;  // offset: 0x50
    };
public:
    struct SpeakerAngle
    {
    public:
        f32 frontAngle;  // offset: 0x0
        f32 surroundAngle;  // offset: 0x4
        f32 enhanceAngle;  // offset: 0x8
    };
public:
    class UpdateThread : public MtThread
    {
    public:
        UpdateThread();
        virtual ~UpdateThread();
        virtual void execute(void*);  // vtable slot 6
    };
public:
    class LoadThread : public MtThread
    {
    public:
        LoadThread();
        virtual ~LoadThread();
        virtual void execute(void*);  // vtable slot 6
    };
public:
    struct SeRequestItem
    {
    public:
        rSoundBank* mpBank;  // offset: 0x0
        u32 mProgramNumber;  // offset: 0x8
        u32 mElementIndex;  // offset: 0xc
        f32 mVolume;  // offset: 0x10
        u32 mPriority;  // offset: 0x14
        u32 mID;  // offset: 0x18
        void* mpUser;  // offset: 0x20
        u32 mVelocity;  // offset: 0x28
        u32 mKey;  // offset: 0x2c
    };
public:
    struct RandomHistory
    {
    public:
        const rSoundBank* mpBank;  // offset: 0x0
        u32 mProgramNumber : 16;  // offset: 0x8
        u32 mElementIndex : 16;  // offset: 0x8
    };
public:
    struct SoundFrameCallback
    {
    public:
        MtObject* mpObject;  // offset: 0x0
        MT_MFUNC mpFunction;  // offset: 0x8
    };
public:
    struct ReverbParameter
    {
    public:
        s32 mRoom;  // offset: 0x0
        s32 mRoomHF;  // offset: 0x4
        f32 mDecayTime;  // offset: 0x8
        f32 mDecayHFRatio;  // offset: 0xc
        s32 mReflections;  // offset: 0x10
        f32 mReflectionsDelay;  // offset: 0x14
        s32 mReverb;  // offset: 0x18
        f32 mReverbDelay;  // offset: 0x1c
        f32 mDiffusion;  // offset: 0x20
        f32 mDensity;  // offset: 0x24
        f32 mHFReference;  // offset: 0x28
        f32 mEarlyReflectionScaler;  // offset: 0x2c
        f32 mLFreference;  // offset: 0x30
        f32 mRoomLF;  // offset: 0x34
    };
public:
    class EffectResourceWork
    {
    public:
        enum FADE_STATUS
        {
            FADE_STATUS_IDLE = 0,
            FADE_STATUS_START = 1,
            FADE_STATUS_MOVE = 2,
        };
    public:
        EffectResourceWork();
        virtual ~EffectResourceWork() {}
        void init();
    public:
        u32 mId;  // offset: 0x8
        FADE_STATUS mFadeStatus;  // offset: 0xc
        f32 mFadeTime;  // offset: 0x10
        f32 mFadeElapsedTime;  // offset: 0x14
        u32 mResourceIndex;  // offset: 0x18
    };
public:
    struct REVERB_PARAMETER
    {
    public:
        u32 mEffectType;  // offset: 0x0
        u32 mIndex;  // offset: 0x4
        bool mEnable;  // offset: 0x8
        f32 mOutputLevel;  // offset: 0xc
        sSound::ReverbParameter mReverbParameter;  // offset: 0x10
    };
public:
    struct ReverbParameterWork
    {
    public:
        f32 mRoom;  // offset: 0x0
        f32 mRoomHF;  // offset: 0x4
        f32 mDecayTime;  // offset: 0x8
        f32 mDecayHFRatio;  // offset: 0xc
        f32 mReflections;  // offset: 0x10
        f32 mReflectionsDelay;  // offset: 0x14
        f32 mReverb;  // offset: 0x18
        f32 mReverbDelay;  // offset: 0x1c
        f32 mDiffusion;  // offset: 0x20
        f32 mDensity;  // offset: 0x24
        f32 mHFReference;  // offset: 0x28
        f32 mEarlyReflectionScaler;  // offset: 0x2c
        f32 mLFreference;  // offset: 0x30
        f32 mRoomLF;  // offset: 0x34
    };
public:
    struct EQParameter
    {
    public:
        u32 mEnable;  // offset: 0x0
        u32 mLowType;  // offset: 0x4
        u32 mHighType;  // offset: 0x8
        f32 mLowFreq;  // offset: 0xc
        f32 mLowGain;  // offset: 0x10
        f32 mLowQ;  // offset: 0x14
        f32 mMidLowFreq;  // offset: 0x18
        f32 mMidLowGain;  // offset: 0x1c
        f32 mMidLowQ;  // offset: 0x20
        f32 mMidHighFreq;  // offset: 0x24
        f32 mMidHighGain;  // offset: 0x28
        f32 mMidHighQ;  // offset: 0x2c
        f32 mHighFreq;  // offset: 0x30
        f32 mHighGain;  // offset: 0x34
        f32 mHighQ;  // offset: 0x38
    };
public:
    struct EQ_PARAMETER
    {
    public:
        u32 mEffectType;  // offset: 0x0
        u32 mCategory;  // offset: 0x4
        sSound::EQParameter mEQParameter;  // offset: 0x8
    };
public:
    struct EQParameterWork
    {
    public:
        u32 mEnable;  // offset: 0x0
        u32 mLowType;  // offset: 0x4
        u32 mHighType;  // offset: 0x8
        f32 mLowFreq;  // offset: 0xc
        f32 mLowGain;  // offset: 0x10
        f32 mLowQ;  // offset: 0x14
        f32 mMidLowFreq;  // offset: 0x18
        f32 mMidLowGain;  // offset: 0x1c
        f32 mMidLowQ;  // offset: 0x20
        f32 mMidHighFreq;  // offset: 0x24
        f32 mMidHighGain;  // offset: 0x28
        f32 mMidHighQ;  // offset: 0x2c
        f32 mHighFreq;  // offset: 0x30
        f32 mHighGain;  // offset: 0x34
        f32 mHighQ;  // offset: 0x38
    };
public:
    struct SOUNDDRIVER_INIT_PARAM
    {
    public:
        SOUNDDRIVER_INIT_PARAM();
    public:
        sSound::REVERB_MODE mReverbMode;  // offset: 0x0
        u32 mChannelsProcess;  // offset: 0x4
        bool mBgmPortEnable;  // offset: 0x8
        u32 mPadSpeakerPortNum;  // offset: 0xc
        bool mRestrictedPortEnable;  // offset: 0x10
    };
public:
    class EntryControlParam
    {
    public:
        EntryControlParam();
        ~EntryControlParam();
        void init();
    public:
        u8 mPriority;  // offset: 0x0
        bool mPriorityIsLink;  // offset: 0x1
        u8 mPrioMode;  // offset: 0x2
        bool mPrioModeIsLink;  // offset: 0x3
        s16 mID_1;  // offset: 0x4
        s16 mID_2;  // offset: 0x6
        s16 mID_3;  // offset: 0x8
        u16 mBookingTimer;  // offset: 0xa
        u8 mGlobalID;  // offset: 0xc
        u8 mLimit;  // offset: 0xd
        bool mExtractParamIsLink;  // offset: 0xe
    };
public:
    struct SeExtractParam
    {
    public:
        sSound::SeEntry* pEntry;  // offset: 0x0
        rSoundRequest* pRequest;  // offset: 0x8
        rSoundRequest::Element* pRequestElement;  // offset: 0x10
        s32 entryReqNo;  // offset: 0x18
        u8 priority;  // offset: 0x1c
        u8 prioMode;  // offset: 0x1d
        s16 id1;  // offset: 0x1e
        s16 id2;  // offset: 0x20
        s16 id3;  // offset: 0x22
        u16 bookingTimer;  // offset: 0x24
        u8 globalID;  // offset: 0x26
        u8 limit;  // offset: 0x27
        s16 parogramNo;  // offset: 0x28
    };
public:
    class StreamEntryControlParam : public sSound::EntryControlParam
    {
    public:
        StreamEntryControlParam();
        ~StreamEntryControlParam();
        void init();
    };
public:
    class AudioOutThread : public MtThread
    {
    public:
        AudioOutThread(void* pContext);
        virtual ~AudioOutThread();
        virtual void execute(void* pContext);  // vtable slot 6
    };
public:
    class AudioOutPort
    {
    public:
        AudioOutPort();
        virtual ~AudioOutPort();
        bool init(const u32 audioOutPortType, const SceUserServiceUserId userId, const bool restricted);
        bool final();
        bool output(const u32 bufferIndex);
        bool getPortState(SceAudioOutPortState& portState);
        f32* getBufferBlock(const u32 bufferIndex);
        u32 getBufferBlockSize();
    private:
        s32 mPortHandle;  // offset: 0x8
        f32* mpBuffer;  // offset: 0x10
        u32 mChannelNum;  // offset: 0x18
        u32 mAudioOutPortType;  // offset: 0x1c
    };
public:
    class NGS2Voice
    {
    public:
        NGS2Voice();
        // Address: 0x012a0580 - 0x012a0581 (1 bytes)
        virtual ~NGS2Voice() {}
        virtual void init();  // vtable slot 2
        virtual bool play();  // vtable slot 3
        virtual bool stop();  // vtable slot 4
        virtual bool pause();  // vtable slot 5
        virtual bool resume();  // vtable slot 6
        virtual bool patch(const SceNgs2Handle destHandle, const u32 port);  // vtable slot 7
        bool setPortVolume(const f32 volume, const u32 port);
        bool setMatrixLevels(const f32* pMatrixLevels, const u32 matrixId, const u32 numLevels);
        bool setPortMatrix(const u32 port, const u32 matrixId);
        virtual bool setPitch(const f32 pitch);  // vtable slot 8
        virtual u32 getStateFlags();  // vtable slot 9
        SceNgs2Handle getVoiceHandle();
    protected:
        SceNgs2Handle mVoiceHandle;  // offset: 0x8
    };
public:
    class NGS2Rack
    {
    public:
        NGS2Rack();
        // Address: 0x012a0b90 - 0x012a0b91 (1 bytes)
        virtual ~NGS2Rack() {}
        virtual bool create(const SceNgs2RackOption* pRackOption);  // vtable slot 2
        virtual bool destroy();  // vtable slot 3
        SceNgs2Handle getRackHandle();
        SceNgs2Handle getVoiceHandle(const u32 voiceIndex);
    protected:
        SceNgs2Handle mRackHandle;  // offset: 0x8
        u32 mRackId;  // offset: 0x10
    };
public:
    class NGS2RackSampler : public sSound::NGS2Rack
    {
    public:
        NGS2RackSampler();
        virtual ~NGS2RackSampler();
    };
public:
    class SeVoiceAccessor : public sSound::VoiceAccessor
    {
    public:
        SeVoiceAccessor(sSound::Voice* pVoice);
        ~SeVoiceAccessor();
        const rSoundRequest* getRequest() const;
        void fadeInVoice(const u32 attackTime);
        void keyOffVoice();
        void keyOffVoice(const u32 releaseTime);
        void setProgramNo(const u32 number);
        u32 getProgramNo() const;
    };
public:
    class StreamVoiceAccessor : public sSound::VoiceAccessor
    {
    public:
        StreamVoiceAccessor(sSound::Voice* pVoice);
        ~StreamVoiceAccessor();
        const rSoundStreamRequest* getRequest() const;
        u32 getFadeStatus() const;
        u32 getCurrentPlayPosition() const;
        void fadeOutVoice(const u32 fadeTime);
    };
public:
    class NGS2VoiceSampler : public sSound::NGS2Voice
    {
    public:
        NGS2VoiceSampler();
        virtual ~NGS2VoiceSampler();
        virtual void init();  // vtable slot 2
        bool parseWaveformData(const void* pData, const u32 dataSize);
        bool parseWaveformFile(const MT_CHAR* pPath, const u32 fileOffset);
        void setWaveformFormat(const SceNgs2WaveformFormat& waveformFormat);
        bool setupVoice(const SceNgs2Handle voiceHandle);
        bool addWaveformBlocks(const void* pData);
        bool addWaveformBlocks(const void* pData, const u32 dataSize, const u32 numSamples, const u32 numSkipSamples, const bool isOnlyData, const bool isEnd);
        bool getVoiceState(SceNgs2SamplerVoiceState& voiceState);
        bool getWaveformInfo(SceNgs2WaveformInfo& waveformInfo);
        bool setWaveformInfo(SceNgs2WaveformInfo& waveformInfo);
        bool calcWaveformBlock(const u32 samplePos, const u32 numSamples, SceNgs2WaveformBlock& outBlock);
        bool setUserFx(void* pArg);
        bool setUserFx(sSound::USER_FX_FUNC func, void* pArg);
    protected:
        virtual s32 process(f32* * ppData, const u32 samples, const u32 channels, void* pArg);  // vtable slot 10
    private:
        static s32 userFxHandlerByProcessFunc(SceNgs2UserFxProcessContext* pContext);
        static s32 userFxHandlerByUserFunc(SceNgs2UserFxProcessContext* pContext);
    private:
        SceNgs2WaveformInfo mWaveformInfo;  // offset: 0x10
        sSound::USER_FX_FUNC mpUserFxFunc;  // offset: 0xd8
    };
public:
    class NGS2VoiceSubmixer : public sSound::NGS2Voice
    {
    public:
        NGS2VoiceSubmixer();
        virtual ~NGS2VoiceSubmixer() {}
        bool setupVoice(const SceNgs2Handle voiceHandle, const u32 channels);
        bool setUserFx(void* pArg);
        bool setUserFx(sSound::USER_FX_FUNC func, void* pArg);
        void addRef();
        void releaseRef();
        u32 getRefCount();
    protected:
        virtual s32 process(f32* * ppData, const u32 samples, const u32 channels, void* pArg);  // vtable slot 10
    private:
        static s32 userFxHandlerByProcessFunc(SceNgs2UserFxProcessContext* pContext);
        static s32 userFxHandlerByUserFunc(SceNgs2UserFxProcessContext* pContext);
    private:
        sSound::USER_FX_FUNC mpUserFxFunc;  // offset: 0x10
        u32 mRefCount;  // offset: 0x18
    };
public:
    class NGS2VoiceReverb : public sSound::NGS2Voice
    {
    public:
        NGS2VoiceReverb();
        virtual ~NGS2VoiceReverb();
        bool setupVoice(const SceNgs2Handle voiceHandle, const u32 inputChannels, const u32 outputChannels);
        void getReverbParamI3DL2(SceNgs2ReverbI3DL2Param& param);
        bool setReverbParamI3DL2(const SceNgs2ReverbI3DL2Param& param);
        void addRef();
        void releaseRef();
        u32 getRefCount();
    private:
        SceNgs2ReverbI3DL2Param mReverbI3DL2Param;  // offset: 0x10
        u32 mRefCount;  // offset: 0x68
    };
public:
    class NGS2RackSubmixer : public sSound::NGS2Rack
    {
    public:
        NGS2RackSubmixer();
        virtual ~NGS2RackSubmixer();
    };
public:
    class NGS2RackReverb : public sSound::NGS2Rack
    {
    public:
        NGS2RackReverb();
        virtual ~NGS2RackReverb();
    };
public:
    class NGS2VoiceSubmixerEQ : public sSound::NGS2VoiceSubmixer
    {
    public:
        NGS2VoiceSubmixerEQ();
        virtual ~NGS2VoiceSubmixerEQ();
        void setChannels(const u32 channels);
        virtual s32 process(f32* * pData, const u32 samples, const u32 channels, void* pArg);  // vtable slot 10
        cSoundMultiBandEQ* getMultiBandEQ();
    private:
        cSoundMultiBandEQ mMultiBandEQ;  // offset: 0x20
    };
public:
    class NGS2VoiceSubmixerCompLimitter : public sSound::NGS2VoiceSubmixer
    {
    public:
        NGS2VoiceSubmixerCompLimitter();
        virtual ~NGS2VoiceSubmixerCompLimitter();
        virtual s32 process(f32* * pData, const u32 samples, const u32 channels, void* pArg);  // vtable slot 10
    private:
        cSoundCompressor mCompressor;  // offset: 0x20
        cSoundLimitter mLimitter;  // offset: 0x100
        f32* mpInterleaveBuffer;  // offset: 0x128
    };
public:
    class NGS2VoiceSubmixerSilentDetectFilter : public sSound::NGS2VoiceSubmixer
    {
    public:
        NGS2VoiceSubmixerSilentDetectFilter();
        virtual ~NGS2VoiceSubmixerSilentDetectFilter();
        virtual s32 process(f32* * ppData, const u32 samples, const u32 channels, void* pArg);  // vtable slot 10
        bool isSilent();
    private:
        void mixChannels(f32* * ppData, const u32 samples, const u32 channels);
    private:
        cSoundSilentDetectFilter mSilentDetectFilter;  // offset: 0x20
        f32 mSilentThreshold;  // offset: 0x38
        f32* mpMixBuffer;  // offset: 0x40
    };
public:
    class NativeVoicePool
    {
    public:
        NativeVoicePool();
        virtual ~NativeVoicePool() {}
        virtual sSound::NativeVoice* getNativeVoice(sSound::Voice::VOICE_TYPE voiceType, u32 index);  // vtable slot 2
    protected:
        sSound::NativeVoice* mppNativeVoiceSe[96];  // offset: 0x8
        sSound::NativeVoice* mppNativeVoiceStream[8];  // offset: 0x308
        sSound::NativeVoice* mppNativeVoiceExternal[1];  // offset: 0x348
    };
public:
    class Entry
    {
    public:
        Entry();
        ~Entry();
        void init();
        bool isControlKeyMatching(uintptr requestID, u32 reqNo, uintptr thisID);
    public:
        uintptr mRequestId;  // offset: 0x0
        u32 mReqNo;  // offset: 0x8
        uintptr mThisId;  // offset: 0x10
        sSound::ENTRY_COMMAND mEntryCommand;  // offset: 0x18
        u32 mEntryType;  // offset: 0x1c
        sSound::ControlParam mParam;  // offset: 0x20
        sSound::CALLBACK_FUNC mpCallbackFunc;  // offset: 0x48
        void* mpCallbackArg;  // offset: 0x50
        bool mIsLink;  // offset: 0x58
        void* mpNativeParam;  // offset: 0x60
    };
public:
    class StreamEntry : public sSound::Entry
    {
    public:
        StreamEntry();
        ~StreamEntry();
        void init();
        void setStreamRequest(rSoundStreamRequest* pResource);
        rSoundStreamRequest* getStreamRequest() const;
    private:
        rSoundStreamRequest* mpStreamRequest;  // offset: 0x68
        bool mEnableSilentDetection;  // offset: 0x70
    };
public:
    class ReverbResource
    {
        // inferred: sSound::moveEffect names sSound::mReverbResource.mpReverbResourceWork[0]
        friend class sSound;
    public:
        class ReverbResourceWork;
    public:
        class ReverbResourceWork : public sSound::EffectResourceWork
        {
        public:
            ReverbResourceWork();
            virtual ~ReverbResourceWork() {}
            virtual void init();  // vtable slot 2
            virtual void move(rSoundReverb* pReverb);  // vtable slot 3
        public:
            u32 mEffectIndex;  // offset: 0x1c
            sSound::REVERB_PARAMETER mFadeReverbParam;  // offset: 0x20
            sSound::ReverbParameter mReverbParameterOrg;  // offset: 0x68
            sSound::ReverbParameterWork mReverbParameterWork;  // offset: 0xa0
            f32 mOutputLevelOrg;  // offset: 0xd8
            f32 mOutputLevelWork;  // offset: 0xdc
        };
    public:
        ReverbResource();
        ~ReverbResource();
        void move();
        void setResource(rSoundReverb* pReverb);
        void setId(u32 id, u32 reverbIndex, u32 fadeTimeMsec);
        u32 getId(u32 reverbIndex);
        rSoundReverb* getResource() const;
        void deleteResource();
    private:
        rSoundReverb* mpReverb;  // offset: 0x0
        ReverbResourceWork* mpReverbResourceWork[4];  // offset: 0x8
    };
public:
    class EQResource
    {
        // inferred: sSound::moveEffect names sSound::mEQResource.mpEQResourceWork[0]
        friend class sSound;
    public:
        class EQResourceWork;
    public:
        class EQResourceWork : public sSound::EffectResourceWork
        {
        public:
            EQResourceWork();
            virtual ~EQResourceWork() {}
            virtual void init();  // vtable slot 2
            virtual void move(rSoundEQ* pEQ);  // vtable slot 3
        public:
            sSound::EQ_PARAMETER mFadeEQParam;  // offset: 0x1c
            sSound::EQParameter mEQParameterOrg;  // offset: 0x60
            sSound::EQParameterWork mEQParameterWork;  // offset: 0x9c
        };
    public:
        EQResource();
        ~EQResource();
        void move();
        void setResource(rSoundEQ* pEQ);
        void setId(u32 id, u32 fadeTimeMsec);
        u32 getId(u32 categoryEQIndex);
        rSoundEQ* getResource() const;
        void deleteResource();
    private:
        rSoundEQ* mpEQ;  // offset: 0x0
        EQResourceWork* mpEQResourceWork[9];  // offset: 0x8
    };
public:
    class SeEntryControlParam : public sSound::EntryControlParam
    {
    public:
        SeEntryControlParam();
        ~SeEntryControlParam();
        void init();
    public:
        s16 mProgramNo;  // offset: 0x10
        bool mProgramNoIsLink;  // offset: 0x12
    };
public:
    class AudioOut
    {
    public:
        enum AUDIO_OUT_PORT_TYPE
        {
            AUDIO_OUT_PORT_TYPE_MAIN = 0,
            AUDIO_OUT_PORT_TYPE_BGM = 1,
            AUDIO_OUT_PORT_TYPE_PAD_SPEAKER = 2,
        };
        enum AUDIO_OUT_PORT
        {
            AUDIO_OUT_PORT_MAIN = 0,
            AUDIO_OUT_PORT_BGM = 1,
            AUDIO_OUT_PORT_PAD_SPEAKER0 = 2,
            AUDIO_OUT_PORT_PAD_SPEAKER1 = 3,
            AUDIO_OUT_PORT_PAD_SPEAKER2 = 4,
            AUDIO_OUT_PORT_PAD_SPEAKER3 = 5,
            AUDIO_OUT_PORT_RESTRICTED = 6,
            AUDIO_OUT_PORT_MAX = 7,
        };
    public:
        AudioOut(const bool bgmPortEnable, const u32 padSpeakerPortNum, const bool restrictedPortEnable);
        virtual ~AudioOut();
        bool init();
        bool final();
        bool getBgmPortEnable();
        u32 getPadSpeakerPortNum();
        bool getRestrictedPortEnable();
        u32 getAudioOutChannels();
        void executeAudioOut();
        void lockProcess();
        void unlockProcess();
    private:
        void render();
        void output();
        void upDownMix();
    private:
        sSound::AudioOutThread mAudioOutThread;  // offset: 0x8
        u32 mBufferIndex;  // offset: 0x78
        bool mBgmPortEnable;  // offset: 0x7c
        u32 mPadSpeakerPortNum;  // offset: 0x80
        bool mRestrictedPortEnable;  // offset: 0x84
        sSound::AudioOutPort mAudioOutPortMain;  // offset: 0x88
        sSound::AudioOutPort mAudioOutPortBgm;  // offset: 0xa8
        sSound::AudioOutPort mAudioOutPortPadSpeaker[4];  // offset: 0xc8
        sSound::AudioOutPort mAudioOutPortRestricted;  // offset: 0x148
        MtCriticalSection mAudioOutProcessSection;  // offset: 0x168
    public:
        static const u32 PAD_SPEAKER_PORT_MAX = 4;
        static const u32 BUFFER_BLOCK_NUM = 2;
        static u32 REQUEST_PAD_SPEAKER[4];
        static u32 REQUEST_RESTRICTED;
        static const u32 MAX_GRAIN_SAMPLES = 512;
        static const u32 NUM_GRAIN_SAMPLES = 256;
    private:
        static const s32 AUDIO_OUT_THREAD_PRIORITY = 256;
        static const u32 UPDATE_THREAD_AFFINITY_MASK = 32;
    };
public:
    class NGS2VoiceMastering : public sSound::NGS2Voice
    {
    public:
        NGS2VoiceMastering();
        virtual ~NGS2VoiceMastering();
        virtual bool setupVoice(const SceNgs2Handle voiceHandle);  // vtable slot 10
        bool setOutputPort(const u32 index);
    };
public:
    class NGS2RackMastering : public sSound::NGS2Rack
    {
    public:
        NGS2RackMastering();
        virtual ~NGS2RackMastering();
    };
public:
    class NativeVoicePS4 : public sSound::NativeVoice
    {
    public:
        NativeVoicePS4();
        NativeVoicePS4(u32 index);
        virtual ~NativeVoicePS4();
        virtual void init();  // vtable slot 2
        virtual void play();  // vtable slot 7
        virtual void stop();  // vtable slot 8
        virtual void pause();  // vtable slot 10
        virtual void resume();  // vtable slot 11
        virtual void updateVoiceParams(sSound::Voice* pVoice);  // vtable slot 17
        virtual void applyVolume();  // vtable slot 18
        virtual void applyPitch();  // vtable slot 19
        virtual bool isEnd();  // vtable slot 23
        virtual void freeVoice();  // vtable slot 4
    protected:
        bool getAudioOutPort(const sSound::Voice* pVoice);
        void connectRouting();
        void disconnectRouting();
        sSound::NGS2Routing* getRouting();
        void updateMatrixLevels();
        void updateEffectSendLevel();
    protected:
        sSound::NGS2VoiceSampler mVoiceSampler;  // offset: 0x8
        f32 mMatrixLevels[64];  // offset: 0xe8
        f32 mEffectSendLevel;  // offset: 0x1e8
        u32 mChannelNum;  // offset: 0x1ec
        f32 mPitch;  // offset: 0x1f0
        u32 mIndex;  // offset: 0x1f4
        sSound::Voice* mpVoice;  // offset: 0x1f8
        sSound::AudioOut::AUDIO_OUT_PORT mAudioOutPort;  // offset: 0x200
    };
public:
    class NativeVoiceSePS4 : public sSound::NativeVoicePS4
    {
    public:
        NativeVoiceSePS4(u32 index);
        virtual ~NativeVoiceSePS4();
        virtual void init();  // vtable slot 2
        virtual void setupVoice(sSound::Voice* pVoice);  // vtable slot 3
    };
public:
    class NativeVoiceStreamPS4 : public sSound::NativeVoicePS4
    {
    public:
        NativeVoiceStreamPS4(u32 index);
        virtual ~NativeVoiceStreamPS4();
        virtual void init();  // vtable slot 2
        virtual void setupVoice(sSound::Voice* pVoice);  // vtable slot 3
        virtual void applyVolume();  // vtable slot 18
        virtual void applyPitch();  // vtable slot 19
        virtual bool isPrepared();  // vtable slot 24
        virtual bool openSource();  // vtable slot 31
        virtual bool closeSource();  // vtable slot 32
        virtual void prepare();  // vtable slot 6
        virtual void loadBuffer();  // vtable slot 26
        virtual void updateBuffer();  // vtable slot 27
        static s32 process(f32* * ppData, const u32 samples, const u32 channels, void* pArg);
        virtual s32 getPicolaPitchShiftNo() const;  // vtable slot 41
        virtual void setPicolaPitchShiftNo(s32 no);  // vtable slot 42
        virtual s32 getSilentDetect(rSoundStreamRequest* pRequest, u32 reqNo, uintptr thisId);  // vtable slot 43
    private:
        const u32 STREAM_BUFFER_SIZE;  // offset: 0x204
        const u32 STREAM_BUFFER_LOWER_SIZE;  // offset: 0x208
        const u32 STREAM_INTERLEAVE_BUFFER_SIZE;  // offset: 0x20c
        u8* mpBuffer;  // offset: 0x210
        f32* mpInterleaveBuffer;  // offset: 0x218
        u32 mLoadWaveformBlockIndex;  // offset: 0x220
        u32 mUpdateWaveformBlockIndex;  // offset: 0x224
        u32 mLoadBlockFileOffset;  // offset: 0x228
        u32 mUpdateBlockFileOffset;  // offset: 0x22c
        u32 mReadPosition;  // offset: 0x230
        u32 mWritePosition;  // offset: 0x234
        u32 mReserveSize;  // offset: 0x238
        u32 mDecodedDataSize;  // offset: 0x23c
        volatile u32 mRemainSize;  // offset: 0x240
        MtCriticalSection mLoadUpdateSection;  // offset: 0x248
        rSoundSourceStreamAT9* mpSource;  // offset: 0x250
        u32 mSourceID;  // offset: 0x258
        bool mIsPrepared;  // offset: 0x25c
        s32 mPicolaPitchShiftNo;  // offset: 0x260
        u32 mDecodedSamples;  // offset: 0x264
        cSoundSilentDetectFilter mSilentDetectFilter;  // offset: 0x268
    };
public:
    class NativeVoiceExternalPS4 : public sSound::NativeVoicePS4
    {
    public:
        NativeVoiceExternalPS4(u32 index);
        virtual ~NativeVoiceExternalPS4();
        virtual void init();  // vtable slot 2
        virtual void setupVoice(sSound::Voice* pVoice);  // vtable slot 3
        virtual void playExternal();  // vtable slot 12
        virtual void stopExternal();  // vtable slot 13
        virtual void pauseExternal();  // vtable slot 14
        virtual void resumeExternal();  // vtable slot 15
        virtual void updateExternal();  // vtable slot 16
        virtual bool isAvailableWrite(u32 threshold) const;  // vtable slot 34
        virtual void write(void* pbuf, u32 size);  // vtable slot 35
        virtual void fill();  // vtable slot 36
        virtual void setVoiceChannelNum(u32 channelNum);  // vtable slot 38
        virtual void setRestrictedExternal(bool restricted);  // vtable slot 40
    private:
        u32 EXTERNAL_BUFFER_SIZE;  // offset: 0x204
        u32 EXTERNAL_BUFFER_LOWER_SIZE;  // offset: 0x208
        u32 EXTERNAL_ADD_BLOCK_SIZE;  // offset: 0x20c
        sSound::Voice* mpVoice;  // offset: 0x210
        void* mpBuffer;  // offset: 0x218
        u32 mWritePosition;  // offset: 0x220
        u32 mReadPosition;  // offset: 0x224
        u32 mRemainSize;  // offset: 0x228
        u32 mDecodedDataSize;  // offset: 0x22c
        u32 mDecodedDataSizeBlock;  // offset: 0x230
        bool mIsRestricted;  // offset: 0x234
        MtCriticalSection mRemainSection;  // offset: 0x238
    };
public:
    class NativeVoicePoolPS4 : public sSound::NativeVoicePool
    {
    public:
        NativeVoicePoolPS4();
        virtual ~NativeVoicePoolPS4();
    };
public:
    class SeEntry : public sSound::Entry
    {
    public:
        SeEntry();
        ~SeEntry();
        void init();
        void setRequest(rSoundRequest* pResource);
        void setBank(rSoundBank* pResource);
        rSoundRequest* getRequest() const;
        rSoundBank* getBank() const;
    private:
        rSoundRequest* mpRequest;  // offset: 0x68
        rSoundBank* mpBank;  // offset: 0x70
    public:
        u32 mProgramNo;  // offset: 0x78
    };
public:
    class NGS2System
    {
    public:
        enum ROUTING
        {
            ROUTING_NO_EFFECT = 0,
            ROUTING_REVERB_EQ = 1,
        };
    public:
        NGS2System(const bool bgmPortEnable, const u32 padSpeakerPortNum, const bool restrictedPortEnable);
        virtual ~NGS2System();
        bool init(const ROUTING routingIndex);
        bool final();
        void update();
        u32 getRouting() const;
        void setRouting(const u32 routingIndex);
        void getFX(void* pParam);
        void setFX(const void* pParam);
        void setReverbOutputChannel(const u32 reverbIndex, const u32 speakerIndex, const bool b);
        bool getReverbOutputChannel(const u32 reverbIndex, const u32 speakerIndex);
        void updateAudioOut();
        SceNgs2Handle getSystemHandle();
        SceNgs2Handle getVoiceHandleSe(const u32 voiceIndex);
        SceNgs2Handle getVoiceHandleStream(const u32 voiceIndex);
        SceNgs2Handle getVoiceHandleExternal(const u32 voiceIndex);
        sSound::NGS2Routing* getNGS2RoutingMain();
        sSound::NGS2Routing* getNGS2RoutingBgm();
        sSound::NGS2Routing* getNGS2RoutingPadSpeaker(const u32 padSpeakerIndex);
        sSound::NGS2Routing* getNGS2RoutingRestricted();
        bool getBgmPortEnable();
        u32 getPadSpeakerPortNum();
        bool getRestrictedPortEnable();
        u32 getSystemChannels();
        static s32 memAlloc(SceNgs2ContextBufferInfo* pInfo);
        static s32 memFree(SceNgs2ContextBufferInfo* pInfo);
    private:
        void updateAudioOutNoEffect();
        void updateAudioOutReverbEQ();
    private:
        sSound::AudioOut mAudioOut;  // offset: 0x8
        SceNgs2Handle mSystemHandle;  // offset: 0x178
        sSound::NGS2Routing* mpNGS2RoutingMain;  // offset: 0x180
        sSound::NGS2Routing* mpNGS2RoutingBgm;  // offset: 0x188
        sSound::NGS2Routing* mpNGS2RoutingPadSpeaker[4];  // offset: 0x190
        sSound::NGS2Routing* mpNGS2RoutingRestricted;  // offset: 0x1b0
        sSound::NGS2RackSampler mRackSamplerSe;  // offset: 0x1b8
        sSound::NGS2RackSampler mRackSamplerStream;  // offset: 0x1d0
        sSound::NGS2RackSampler mRackSamplerExternal;  // offset: 0x1e8
        ROUTING mRoutingIndex;  // offset: 0x200
        MtCriticalSection mRoutingSection;  // offset: 0x208
    };
public:
    class NGS2Routing
    {
    public:
        NGS2Routing();
        virtual ~NGS2Routing();
        virtual bool init(const u32 outputPort);  // vtable slot 2
        virtual bool final();  // vtable slot 3
        // Address: 0x012a14c0 - 0x012a14c1 (1 bytes)
        virtual void update() {}  // vtable slot 4
        // Address: 0x012a14d0 - 0x012a14d1 (1 bytes)
        virtual void addRef(const void* pParam) {}  // vtable slot 5
        // Address: 0x012a14e0 - 0x012a14e1 (1 bytes)
        virtual void releaseRef(const void* pParam) {}  // vtable slot 6
        // Address: 0x012a14f0 - 0x012a14f1 (1 bytes)
        virtual void getFX(void* pParam) {}  // vtable slot 7
        // Address: 0x012a1500 - 0x012a1501 (1 bytes)
        virtual void setFX(const void* pParam) {}  // vtable slot 8
        // Address: 0x012a1510 - 0x012a1511 (1 bytes)
        virtual void setReverbOutputChannel(const u32 reverbIndex, const u32 speakerIndex, const bool b) {}  // vtable slot 9
        virtual bool getReverbOutputChannel(const u32 reverbIndex, const u32 speakerIndex);  // vtable slot 10
        SceNgs2Handle getVoiceHandleMastering();
        virtual SceNgs2Handle getDstVoiceHandleDry(void* pParam);  // vtable slot 11
        virtual SceNgs2Handle getDstVoiceHandleWet(void* pParam);  // vtable slot 12
    protected:
        sSound::NGS2VoiceMastering mVoiceMastering;  // offset: 0x8
        sSound::NGS2RackMastering mRackMastering;  // offset: 0x18
        MtCriticalSection mRefCountSection;  // offset: 0x30
    };
public:
    class NGS2RoutingNoEffect : public sSound::NGS2Routing
    {
    public:
        NGS2RoutingNoEffect();
        virtual ~NGS2RoutingNoEffect();
        virtual bool init(const u32 outputPort);  // vtable slot 2
        virtual bool final();  // vtable slot 3
    };
public:
    class NGS2RoutingReverbEQ : public sSound::NGS2Routing
    {
    public:
        struct REFERENCE_COUNT_PARAM;
        struct DST_PARAM_DRY;
        struct DST_PARAM_WET;
    public:
        struct REFERENCE_COUNT_PARAM
        {
        public:
            s32 mEQIndex;  // offset: 0x0
            s32 mReverbIndex;  // offset: 0x4
            s32 mEQReverbIndex;  // offset: 0x8
        };
    public:
        struct DST_PARAM_DRY
        {
        public:
            s32 mEQIndex;  // offset: 0x0
        };
    public:
        struct DST_PARAM_WET
        {
        public:
            s32 mReverbIndex;  // offset: 0x0
            s32 mEQReverbIndex;  // offset: 0x4
        };
    public:
        NGS2RoutingReverbEQ();
        virtual ~NGS2RoutingReverbEQ();
        virtual bool init(const u32 outputPort);  // vtable slot 2
        virtual bool final();  // vtable slot 3
        virtual void update();  // vtable slot 4
        virtual void getFX(void* pParam);  // vtable slot 7
        virtual void setFX(const void* pParam);  // vtable slot 8
        virtual void addRef(const void* pParam);  // vtable slot 5
        virtual void releaseRef(const void* pParam);  // vtable slot 6
        virtual void setReverbOutputChannel(const u32 reverbIndex, const u32 speakerIndex, const bool b);  // vtable slot 9
        virtual bool getReverbOutputChannel(const u32 reverbIndex, const u32 speakerIndex);  // vtable slot 10
        virtual SceNgs2Handle getDstVoiceHandleDry(void* pParam);  // vtable slot 11
        virtual SceNgs2Handle getDstVoiceHandleWet(void* pParam);  // vtable slot 12
    private:
        void setRouting();
        void getReverbMatrixLevels(f32* matrixLevels);
    private:
        sSound::NGS2RackSubmixer mRackCompLimitter;  // offset: 0x38
        sSound::NGS2VoiceSubmixerCompLimitter mVoiceCompLimitter;  // offset: 0x50
        sSound::NGS2RackSubmixer mRackMasterEQ;  // offset: 0x180
        sSound::NGS2VoiceSubmixerEQ mVoiceMasterEQ;  // offset: 0x1a0
        sSound::NGS2RackSubmixer mRackReverbSilentDetectFilter;  // offset: 0x470
        sSound::NGS2VoiceSubmixerSilentDetectFilter mVoiceReverbSilentDetectFilter[4];  // offset: 0x488
        sSound::NGS2RackReverb mRackReverb;  // offset: 0x5a8
        sSound::NGS2VoiceReverb mVoiceReverb[4];  // offset: 0x5c0
        sSound::NGS2RackSubmixer mRackEQ;  // offset: 0x780
        sSound::NGS2VoiceSubmixerEQ mVoiceEQ[4];  // offset: 0x7a0
        sSound::NGS2RackSubmixer mRackEQReverb;  // offset: 0x12e0
        sSound::NGS2VoiceSubmixerEQ mVoiceEQReverb[4][4];  // offset: 0x1300
        f32 mReverbOutputLevel[8];  // offset: 0x4000
    };
public:
    class NativeSystemPS4 : public sSound::NativeSystem
    {
    public:
        class PS4Property;
        class ReverbResourceWorkPS4;
        class EQResourceWorkPS4;
    public:
        class PS4Property : public MtObject
        {
        public:
            class MyDTI;
        public:
            class MyDTI : public MtDTI
            {
            public:
                MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                virtual MtObject* newInstance() const;  // vtable slot 2
            };
        public:
            static MtDTI* getMyDTIPtr();
            static void usage();
            virtual const MtDTI& getDTI() const;  // vtable slot 5
            static MtAllocator* getAllocator();
            static void setAllocator(u32);
            static void* operator new(size_t sz, u32 align);
            static void* operator new[](size_t sz, u32 align);
            static void* operator new(size_t sz, void* p_addr);
            static void* operator new[](size_t sz, void* p_addr);
            static void operator delete(void* p_addr);
            static void operator delete[](void* p_addr);
            static void operator delete(void* p_addr, u32 align);
            static void operator delete[](void* p_addr, u32 align);
            PS4Property();
            // Address: 0x01ba8c00 - 0x01ba8c01 (1 bytes)
            virtual ~PS4Property() {}
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
            u32 getRouting();
            void setRouting(const u32 routing);
        public:
            static MyDTI DTI;
        };
    public:
        class ReverbResourceWorkPS4 : public sSound::ReverbResource::ReverbResourceWork
        {
        public:
            ReverbResourceWorkPS4();
            // Address: 0x01ba8ef0 - 0x01ba8ef1 (1 bytes)
            virtual ~ReverbResourceWorkPS4() {}
            virtual void init();  // vtable slot 2
            virtual void move(rSoundReverb* pReverb);  // vtable slot 3
        private:
            sSound::REVERB_PARAMETER mReverbParamSet;  // offset: 0xe0
            bool mIsParamSet;  // offset: 0x128
        };
    public:
        class EQResourceWorkPS4 : public sSound::EQResource::EQResourceWork
        {
        public:
            EQResourceWorkPS4();
            // Address: 0x01ba8f10 - 0x01ba8f11 (1 bytes)
            virtual ~EQResourceWorkPS4() {}
            virtual void init();  // vtable slot 2
            virtual void move(rSoundEQ* pEQ);  // vtable slot 3
        private:
            sSound::EQ_PARAMETER mEQParamSet;  // offset: 0xd8
            bool mIsParamSet;  // offset: 0x11c
        };
    public:
        NativeSystemPS4(sSound::SOUNDDRIVER_INIT_PARAM* pInit);
        virtual ~NativeSystemPS4();
        virtual void initAudio();  // vtable slot 12
        virtual void finalAudio();  // vtable slot 13
        virtual void setUpdateThreadPriority();  // vtable slot 3
        virtual void setLoadThreadPriority();  // vtable slot 4
        virtual void updateExecute();  // vtable slot 6
        virtual void loadExecute();  // vtable slot 7
        virtual void getFX(void* pParam);  // vtable slot 19
        virtual void setFX(const void* pParam);  // vtable slot 18
        virtual void setReverbOutputChannel(u32 reverbIndex, u32 speakerIndex, bool b);  // vtable slot 25
        virtual bool getReverbOutputChannel(u32 reverbIndex, u32 speakerIndex);  // vtable slot 26
        virtual void setRouting(const u32 routing);  // vtable slot 9
        virtual u32 getRouting() const;  // vtable slot 10
        virtual sSound::EFFECT_TYPE getFxType(u32 index) const;  // vtable slot 20
        virtual u32 getSystemChannelNum() const;  // vtable slot 28
        sSound::NGS2System* getNGS2System();
        virtual u16 getPlatform();  // vtable slot 21
        void interleave(f32* * ppIn, f32* pOut, const u32 samples, const u32 channels);
        void deinterleave(f32* pIn, f32* * ppOut, const u32 samples, const u32 channels);
        bool getIsStreamSilentDetection();
        void setIsStreamSilentDetection(bool b);
        virtual f32 getStreamSilentDecectionThreshold();  // vtable slot 39
        virtual void setStreamSilentDecectionThreshold(f32 dB);  // vtable slot 40
    private:
        sSound::NGS2System mNGS2System;  // offset: 0x38
        u32 mSystemChannelNum;  // offset: 0x248
        bool mEnableSilentDetection;  // offset: 0x24c
        f32 mSilentDetectThreshold;  // offset: 0x250
        sSound::NGS2System::ROUTING mRoutingIndex;  // offset: 0x254
        PS4Property mPS4Property;  // offset: 0x258
        static const s32 UPDATE_THREAD_PRIORITY = 640;
        static const s32 LOAD_THREAD_PRIORITY = 700;
        static const u32 UPDATE_THREAD_AFFINITY_MASK = 16;
        static const u32 LOAD_THREAD_AFFINITY_MASK = 16;
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    sSound(u32 efx0, u32 efx1, SOUNDDRIVER_INIT_PARAM* pParams);
    virtual ~sSound();
    virtual void finalize();  // vtable slot 10
    void freeAllResources();
    void init();
    virtual void move();  // vtable slot 7
    virtual void setup();  // vtable slot 11
    virtual void reset();  // vtable slot 6
    static sSound* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    bool setActiveListeningMatrix(const MtMatrix& listeningMatrix);
    bool setListeningMatrix(const MtMatrix& listeningMatrix, size_t index);
    void setActiveListeningPosition(const MtVector3& listeningPosition);
    void setListeningPosition(const MtVector3& listeningPosition, size_t index);
    void setActiveListeningAngle(const MtVector3& ang);
    void setListeningAngle(const MtVector3& ang, size_t index);
    MtMatrix getListeningMatrix(size_t index) const;
    MtMatrix getListeningMatrixInverse(size_t index) const;
    MtVector3 getListeningPosition(size_t index) const;
    MtVector3 getListeningAngle(size_t index) const;
    void setActiveListening(size_t index, bool b);
    bool getActiveListening(size_t index);
    size_t getActiveListeningBit();
    void setListeningMuteFlag(size_t index, bool b);
    bool getListeningMuteFlag(size_t index);
    void setTotalMasterVolume(f32 totalMasterVolume, u32 volMode);
    f32 getTotalMasterVolume(u32 volMode);
    void setSeMasterVolume(f32 seMasterVolume, u32 volMode);
    f32 getSeMasterVolume(u32 volMode);
    void setBgmMasterVolume(f32 bgmMasterVolume, u32 volMode);
    f32 getBgmMasterVolume(u32 volMode);
    void setEnvMasterVolume(f32 envMasterVolume, u32 volMode);
    f32 getEnvMasterVolume(u32 volMode);
    void setVoiceMasterVolume(f32 voiceMasterVolume, u32 volMode);
    f32 getVoiceMasterVolume(u32 volMode);
    void setSystemMasterVolume(f32 systemMasterVolume, u32 volMode);
    f32 getSystemMasterVolume(u32 volMode);
    void setEventMasterVolume(f32 eventMasterVolume, u32 volMode);
    f32 getEventMasterVolume(u32 volMode);
    void setLFEMasterVolume(f32 lfeMasterVolume, u32 volMode);
    f32 getLFEMasterVolume(u32 volMode);
    void setSpeakerAngle51Front(const f32 degree);
    void setSpeakerAngle51Surround(const f32 degree);
    void setSpeakerAngle51(const f32 front_degree, const f32 surround_degree);
    void setSpeakerAngle51Default();
    void setSpeakerAngle51ItuR();
    f32 getSpeakerAngle51Front();
    f32 getSpeakerAngle51Surround();
    void setSpeakerAngle71Front(const f32 degree);
    void setSpeakerAngle71Surround(const f32 degree);
    void setSpeakerAngle71Enhance(const f32 degree);
    void setSpeakerAngle71(const f32 front_degree, const f32 surround_degree, const f32 enhance_degree);
    void setSpeakerAngle71Default();
    void setSpeakerAngle71ItuR();
    f32 getSpeakerAngle71Front();
    f32 getSpeakerAngle71Surround();
    f32 getSpeakerAngle71Enhance();
    void setFX(const void* pParam);
    void getFX(void* pParam);
    void setEQ(rSoundEQ* pEQ);
    rSoundEQ* getEQ() const;
    void setEQId(u32 id, u32 fadeTimeMsec);
    u32 getEQId(u32);
    void deleteEQ();
    void deleteEQ(rSoundEQ* pEQ);
    void setReverbOutputChannel(u32, u32, bool);
    bool getReverbOutputChannel(u32, u32);
    bool getPICOLAPitchShiftEnable();
    void setPICOLAPitchShiftEnable(bool);
    s32 getPICOLAPitchShiftFreeAreaNo();
    void setPICOLAPitchShiftFreeAreaNo(s32);
    void setEQEnable(u32 index, bool enable);
    void setReverb(rSoundReverb* pReverb);
    rSoundReverb* getReverb() const;
    void setReverbId(u32 id, u32 reverbIndex, u32 fadeTimeMsec);
    u32 getReverbId(u32);
    void deleteReverb();
    void deleteReverb(rSoundReverb* pReverb);
    bool getCompressorEnable();
    void setCompressorEnable(const bool);
    f32 getCompressorThreshold();
    void setCompressorThreshold(const f32);
    f32 getCompressorRatio();
    void setCompressorRatio(const f32);
    f32 getCompressorAttackTime();
    void setCompressorAttackTime(const f32);
    f32 getCompressorReleaseTime();
    void setCompressorReleaseTime(const f32);
    f32 getCompressorPostGain();
    void setCompressorPostGain(const f32);
    bool getLimitterEnable();
    void setLimitterEnable(const bool);
    f32 getLimitterThreshold();
    void setLimitterThreshold(const f32);
    f32 getLimitterOutCeiling();
    void setLimitterOutCeiling(const f32);
    f32 getUpDownMixCenterGain();
    f32 getUpDownMixLFEGain();
    f32 getUpDownMixSurroundGain();
    f32 getUpDownMixEnhanceGain();
    void setUpDownMixCenterGain(const f32 gain_decibel);
    void setUpDownMixLFEGain(const f32 gain_decibel);
    void setUpDownMixSurroundGain(const f32 gain_decibel);
    void setUpDownMixEnhanceGain(const f32 gain_decibel);
    void setUpDownMixDefaultGains();
    void setSeRequestKill(bool b);
    bool getSeRequestKill();
    void setStreamRequestKill(bool b);
    bool getStreamRequestKill();
    void setDryMute(bool b);
    bool getDryMute();
    void setWetMute(bool b);
    bool getWetMute();
    void setSoundCurveSet(rSoundCurveSet* pSoundCurve);
    rSoundCurveSet* getSoundCurveSet() const;
    void setSoundDirectionalSet(rSoundDirectionalSet* pSoundDirectionalSet);
    rSoundDirectionalSet* getSoundDirectionalSet() const;
    f32 getDistanceCurveVolume(DISTANCE_CURVE_TYPE curveType, u32 curveId, MtVector3& soundPosition, s32 listeningIndex, u32 volMode);
    void setDopplerMasterScaler(f32 scale);
    f32 getDopplerMasterScaler();
    f32 getSonicSpeed() const;
    void setSonicSpeed(f32);
    size_t getListeningNum();
    void pauseAllCompel();
    void resumeAllCompel();
    bool isPause() const;
    static f32 calcFloat2Decibel(f32 v);
    static f32 calcDecibel2Float(f32 v);
    u32 getSystemChannelNum() const;
    bool getIsStereoLFE();
    void setIsStereoLFE(bool b);
    bool getIs51SourceDiffuse();
    void setIs51SourceDiffuse(const bool b);
    f32 getStreamSilentDecectionThreshold();
    void setStreamSilentDecectionThreshold(f32 dB);
    s32 getSilentDetect(rSoundStreamRequest* pRequest, u32 reqNo, uintptr thisId);
    MT_CHAR* getEncPathSe();
    MT_CHAR* getEncPathStream();
    void setEncPath(MT_CHAR* pchar, ENC_SOUND_KIND encKind);
    void setUpdateThreadInterval(const u32 updateThreadInterval);
    u32 getChannelsProcess() const;
    void setChannelsProcess(const u32 channels);
    u32 getChannelsOutput() const;
    bool getIsPanDepthMinus3dB();
    void setIsPanDepthMinus3dB(const bool isPanDepthMinus3dB);
    bool getIsStreamSourcePackage();
    void setIsStreamSourcePackage(const bool b);
    void requestSe(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, CALLBACK_FUNC cb, void* arg);
    void requestSe(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, const MtVector3& position, CALLBACK_FUNC cb, void* arg);
    void requestSe(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, const MtVector3& position, const MtQuaternion& quaternion, CALLBACK_FUNC cb, void* arg);
    void requestSe(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, const uCoord* pCoord, s32 jointNo, CALLBACK_FUNC cb, void* arg);
    void requestSe(rSoundBank* pBank, u32 prog, u32 elem, f32 volume, f32 pitch, u32 pan, u32 prio, uintptr thisId, u32 vel, u32 key, u32 category, bool isMidi);
    void requestSe(rSoundBank* pBank, u32 elem, uintptr thisId, u32 vel, u32 key);
    void stopSe(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void keyOffSe(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void keyOffSe(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 releaseTime, bool isLink);
    void keyOffSe(u32 noteNo, uintptr thisId);
    void stopSeCompel(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void pauseSe(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void resumeSe(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void setSePosition(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, bool isLink);
    void setSePosition(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, const MtQuaternion& quaternion, bool isLink);
    void setSeFadeIn(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 attackTime, bool isLink);
    void setSeVolumeAbs(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setSeVolumeRel(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setSeVolumeRatio(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    void setSeVolumeSequence(uintptr thisId, f32 volume);
    f32 getSeVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setSeEffectVolumeAbs(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setSeEffectVolumeRel(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setSeEffectVolumeRatio(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    f32 getSeEffectVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setSeVolumeOfAllAbs(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setSeVolumeOfAllRel(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setSeVolumeOfAllRatio(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    void setSePanAbs(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 pan, bool isLink);
    void setSePanRel(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 pan, bool isLink);
    void setSePanSequence(uintptr thisId, u32 pan);
    s32 getSePan(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setSePitchAbs(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 pitch, bool isLink);
    void setSePitchRel(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 pitch, bool isLink);
    void setSePitchSequence(uintptr thisId, s32 pitch);
    s32 getSePitch(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setSeReverbSendLevelSequence(uintptr thisId, f32 send_level);
    void setSeFilterFreqSequence(uintptr thisId, f32 freq);
    void setSeListeningIndex(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 index, bool isLink);
    void setSeMultiListeningIndex(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 indexBit, bool isLink);
    void setSeWorkArea(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 no, intptr val, bool isLink);
    intptr getSeWorkArea(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 no);
    void setSeDelayTimer(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 delayTime, bool isLink);
    void setSeExternalVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    f32 getSeExternalVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setSeExternalEffectVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    f32 getSeExternalEffectVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setSePriority(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u8 priority, bool isLink);
    u8 getSePriority(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setSePriorityMode(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u8 priorityMode, bool isLink);
    u8 getSePriorityMode(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setSeExtractParam(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, SOUND_EXTRACT_PARAM param, bool isLink);
    SOUND_EXTRACT_PARAM getSeExtractParam(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setSeCenterVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 centervol, bool isLink);
    u8 getSeConterVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setSeProgramNo(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 programNo, bool isLink);
    s16 getSeProgramNo(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setSeCoord(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const uCoord* pCoord, bool isLink);
    uCoord* getSeCoord(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    s32 getSeFreeArea(rSoundRequest* pRequest, const u32 reqNo, const u32 freeAreaNo);
    void setSePositionOffset(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& offset, bool isLink);
    MtVector3 getSePositionOffset(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setSeVolumeCurveID(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 id, bool isLink);
    void setSeEffectCurveID(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 id, bool isLink);
    void setSeDirectionalCurveID(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 id, bool isLink);
    void setSeEqIndex(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 index, bool isLink);
    void setSeEffectIndex(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 index, bool isLink);
    void setSeUpdateVolumeOnce(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void setSeVSurroundBypass(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, bool bypass, bool isLink);
    void setSeLFEVolumeAbs(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setSeLFEVolumeRel(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setSeLFEVolumeRatio(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    f32 getSeLFEVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setSeEqEffectIndex(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 index, bool isLink);
    void setSeLFECurveID(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 index, bool isLink);
    void setSeDopplerScaler(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 dopplerScaler, bool isLink);
    void setSeInterleavedDataVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 speakerIndex, f32 volume, bool isLink, u32 volMode);
    f32 getSeInterleavedDataVolume(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 speakerIndex, u32 volMode);
    u32 getSeStatus(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    u32 getCategory(rSoundRequest* pRequest, u32 reqNo);
    bool getSeIsLoop(rSoundRequest* pRequest, const u32 reqNo);
    u32 getSeMax();
    u32 getSeVoiceNum() const;
    void setSeVoiceNum(const u32 seVoiceNum);
    u32 getSeLinkMax() const;
    void setSeLinkMax(u32 max);
    u32 getReverbChannelNum() const;
    u32 getReverbOutputChannelNum() const;
    u32 getSeEntryNum() const;
    void setSeEntryNum(const u32 seEntryNum);
protected:
    const SeVoice* getSeVoice(u32);
public:
    void requestStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, CALLBACK_FUNC cb, void* arg);
    void requestStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, CALLBACK_FUNC cb, void* arg);
    void requestStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, const MtQuaternion& quaternion, CALLBACK_FUNC cb, void* arg);
    void requestStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const uCoord* pCoord, s32 jointNo, CALLBACK_FUNC cb, void* arg);
    void stopStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void stopStreamCompel(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void fadeOutStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 fadeOutTime, bool isLink);
    void pauseStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void resumeStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void setStreamPosition(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, bool isLink);
    void setStreamPosition(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, const MtQuaternion& quaternion, bool isLink);
    void setStreamVolumeAbs(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setStreamVolumeRel(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setStreamVolumeRatio(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    f32 getStreamVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setStreamEffectVolumeAbs(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setStreamEffectVolumeRel(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setStreamEffectVolumeRatio(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    f32 getStreamEffectVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setStreamVolumeOfAllAbs(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setStreamVolumeOfAllRel(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setStreamVolumeOfAllRatio(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    void setStreamMoveVolumeAbs(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 moveVolTime, f32 volume, f32 efcSend, f32 lfeSend, bool isLink, u32 volMode);
    void setStreamMoveVolumeRel(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 moveVolTime, f32 volume, f32 efcSend, f32 lfeSend, bool isLink, u32 volMode);
    void setStreamMoveVolumeRatio(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 moveVolTime, f32 volume, f32 efcSend, f32 lfeSend, bool isLink);
    void setStreamFadeIn(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 fadeInTime, f32 volume, f32 efcSend, f32 lfeSend, bool isLink, u32 volMode);
    void setStreamPanAbs(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 pan, bool isLink);
    void setStreamPanRel(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 pan, bool isLink);
    s32 getStreamPan(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamPitchAbs(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 pitch, bool isLink);
    void setStreamPitchRel(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 pitch, bool isLink);
    s32 getStreamPitch(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamListeningIndex(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 index, bool isLink);
    void setStreamMultiListeningIndex(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 indexBit, bool isLink);
    void setStreamWorkArea(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 no, intptr val, bool isLink);
    intptr getStreamWorkArea(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 no);
    void setStreamDelayTimer(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 delayTime, bool isLink);
    void setStreamExternalVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    f32 getStreamExternalVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setStreamExternalEffectVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    f32 getStreamExternalEffectVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setStreamPriority(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u8 priority, bool isLink);
    u8 getStreamPriority(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamPriorityMode(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u8 priorityMode, bool isLink);
    u8 getStreamPriorityMode(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamExtractParam(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, SOUND_EXTRACT_PARAM param, bool isLink);
    SOUND_EXTRACT_PARAM getStreamExtractParam(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamCenterVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 centervol, bool isLink);
    u8 getStreamConterVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamCoord(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const uCoord* pCoord, bool isLink);
    uCoord* getStreamCoord(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamPlayPosition(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 playPositionSample, bool isLink);
    u32 getStreamPlayPosition(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamMarkerByID(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u16 markerID, bool isLink);
    void setStreamMarkerBySamplePosition(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 markerSamplePos, bool isLink);
    void setStreamMarkerByIndex(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u16 markerIndex, bool isLink);
    u32 getStreamMarkerSamplePosition(rSoundStreamRequest* pRequest, const u32 reqNo, const u16 markerID);
    s32 getStreamFreeArea(rSoundStreamRequest* pRequest, const u32 reqNo, const u32 freeAreaNo);
    u32 getStreamCurrentPlayPosition(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamPositionOffset(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& offset, bool isLink);
    MtVector3 getStreamPositionOffset(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    void setStreamVolumeCurveID(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 id, bool isLink);
    void setStreamEffectCurveID(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 id, bool isLink);
    void setStreamDirectionalCurveID(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 id, bool isLink);
    void setStreamEqIndex(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 index, bool isLink);
    void setStreamEffectIndex(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 index, bool isLink);
    void setStreamUpdateVolumeOnce(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, bool isLink);
    void setStreamVSurroundBypass(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, bool bypass, bool isLink);
    void setStreamLFEVolumeAbs(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setStreamLFEVolumeRel(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink, u32 volMode);
    void setStreamLFEVolumeRatio(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    f32 getStreamLFEVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 volMode);
    void setStreamLFECurveID(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 id, bool isLink);
    void setStreamEqEffectIndex(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 index, bool isLink);
    void setStreamDopplerScaler(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 dopplerScaler, bool isLink);
    void setStreamInterleavedDataVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 speakerIndex, f32 volume, bool isLink, u32 volMode);
    f32 getStreamInterleavedDataVolume(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 speakerIndex, u32 volMode);
    void setStreamPICOLAPitchShift(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const s32 cent);
    void setStreamSilentDetect(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const bool enable);
    u32 getStreamStatus(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    u32 getStreamStatus(u32 voiceIndex);
    u32 getCategory(rSoundStreamRequest* pRequest, u32 reqNo);
    bool getStreamIsLoop(rSoundStreamRequest* pRequest, const u32 reqNo);
    u32 getStreamMax();
    u32 getStreamVoiceNum() const;
    void setStreamVoiceNum(const u32 streamVoiceNum);
    u32 getStreamLinkMax() const;
    void setStreamLinkMax(u32 max);
    u32 getStreamEntryNum() const;
    void setStreamEntryNum(const u32 streamEntryNum);
protected:
    const StreamVoice* getStreamVoice(u32 index);
public:
    void requestExternalVoice(uintptr thisId, u32 bits);
    bool isAvailableWriteExternalVoice(uintptr thisId, u32 threshold);
    void setExternalVoiceChannelNum(uintptr thisId, u32 channel_num);
    void setExternalVoiceVolume(uintptr thisId, f32 volume, u32 volMode);
    void playExternalVoice(uintptr thisId);
    void stopExternalVoice(uintptr thisId);
    void pauseExternalVoice(uintptr thisId);
    void resumeExternalVoice(uintptr thisId);
    void destroyExternalVoice(uintptr thisId);
    void writeExternalVoice(uintptr thisId, void* pbuf, u32 size);
    void fillExternalVoice(uintptr thisId);
    bool isBufferFillExternalVoice(uintptr thisId);
    void setExternalVoiceCategory(uintptr thisId, u32 category);
    void enumSeVoice(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, CALLBACK_FUNC cb, void* pDat);
    void enumStreamVoice(rSoundStreamRequest* pRequest, u32 reqNo, uintptr thisId, CALLBACK_FUNC cb, void* pDat);
    void enumSeEntry(ENTRY_CALLBACK_FUNC cb, void* pDat);
    void enumStreamEntry(ENTRY_CALLBACK_FUNC cb, void* pDat);
    const SE_ENTRY_PARAMETER* getSeEntryParameter() const;
    const STREAM_ENTRY_PARAMETER* getStreamEntryParameter() const;
    void setSeEntryEndMarker();
    void setStreamEntryEndMarker();
    void protectSeEntryEndMarker();
    void protectStreamEntryEndMarker();
    void unprotectSeEntryEndMarker();
    void unprotectStreamEntryEndMarker();
    void registerExtractPlayCallback(CALLBACK_FUNC pFunc, void* pArg, uintptr id);
    void unregisterExtractPlayCallback(uintptr id);
    EffectBase* getEffect(u32) const;
    bool getEffectEnable(u32 index) const;
    void setEffectEnable(u32 index, bool enable);
    void setEffectParameter(u32 index, void* param);
    void setEffectOutputLevel(u32 index, f32 l);
    s32 findRandomHistory(const rSoundBank* pBank, u16 prog) const;
    void addRandomHistory(const rSoundBank* pBank, u32 prog, u32 elem);
    void removeRandomHistory(const rSoundBank* pBank, u16 prog);
    bool registerSoundFrameCallback(MtObject* pObject, MT_MFUNC pFunc);
    void unregisterSoundFrameCallback(MtObject* pObject, MT_MFUNC pFunc);
    void executeSoundFrame();
    f32 toDB(f32) const;
    f32 toDB_8(f32) const;
    f32 toRatio(f32) const;
    f32 toRatio_8(f32) const;
    const void* getPresetBuffer(u32 type, u32 oct) const;
    f32 getPresetFrequencyRatio() const;
    f32 getSampleHoldFrequencyRatio() const;
private:
    void moveSe();
    void moveStream();
    void moveSystemPause();
    void moveEffect();
    void extractRequestSe(SeEntry* pEntry);
    void extractPlaySe(SeEntry* pEntry, rSoundRequest* pRequest, rSoundRequest::Element* pRequestElement, s32 entryReqNo, SeEntryControlParam* pSeEntryControlParam);
    void extractPlaySe(SeEntry* pEntry);
    void stopExclusiveSeVoice(const rSoundBank* pBank, u32 prog_no, u32 elem_index);
    bool checkFlanging(const rSoundBank* pBank, u32 elem_index) const;
    SeVoice* getAvailableSeVoice(u8 playPriority, u8 playPrioMode);
    static bool extractPlaySeCallback(const rSoundBank::Element* pBankElement, void* p, const u32 count);
    bool executeExtractPlaySe(const rSoundBank::Element* pBankElement, SeExtractParam* pParam, const u32 count);
    void extractStopSe(rSoundRequest* pRequest, rSoundRequest::Element* pRequestElement, uintptr thisId, STOP_TYPE stopType, const SeEntryControlParam& SeEntryControlParam);
    void extractStopSe(SeEntry* pEntry);
    void extractPauseSe(SeEntry* pEntry);
    void extractResumeSe(SeEntry* pEntry);
    void extractControlSe(SeEntry* pEntry);
    void extractRequestStream(StreamEntry* pEntry);
    s32 extractPlayStream(StreamEntry* pEntry, rSoundStreamRequest* pRequest, rSoundStreamRequest::Element* pRequestElement, s32 entryReqNo, StreamEntryControlParam* pStreamEntryControlParam);
    void extractStopStream(rSoundStreamRequest* pRequest, rSoundStreamRequest::Element* pRequestElement, uintptr thisId, STOP_TYPE stopType, const StreamEntryControlParam& StreamEntryControlParam);
    void extractStopStream(StreamEntry* pEntry);
    void extractPauseStream(StreamEntry* pEntry);
    void extractPauseStream(rSoundStreamRequest* pRequest, rSoundStreamRequest::Element* pRequestElement, uintptr thisId, const StreamEntryControlParam& StreamEntryControlParam);
    void extractResumeStream(StreamEntry* pEntry);
    void extractResumeStream(rSoundStreamRequest* pRequest, rSoundStreamRequest::Element* pRequestElement, uintptr thisId, const StreamEntryControlParam& StreamEntryControlParam);
    void extractControlStream(StreamEntry* pEntry);
    void extractFadeStream(StreamEntry* pEntry);
    void extractFadeStream(rSoundStreamRequest* pRequest, rSoundStreamRequest::Element* pRequestElement, uintptr thisId, u32 fadeType, const StreamEntryControlParam& StreamEntryControlParam);
    bool getGains(const size_t index, const MtVector3& position, const size_t channels, f32& angle, f32* gain_ptr, const f32 angle_offset);
    bool getGainsWithoutRotation(const size_t index, const MtVector3& position, const size_t channels, f32& angle, f32* gain_ptr, const f32 angle_offset);
    bool getGains(const size_t channels, const f32 angle, f32* gain_ptr);
    f32 getAttenuationDirection(const u32 id, const f32 angle) const;
    f32 calculateSurroundCurveVolume(f32 distance, DISTANCE_CURVE_TYPE curveType, s32 curveId);
    void updateSpeakerAngle();
    SeVoice* getLowPrioritySeVoice(rSoundRequest* pRequest, u32 global, s32 ID_1, s32 ID_2, s32 ID_3, uintptr thisId, bool isRelease);
    StreamVoice* getLowPriorityStreamVoice(rSoundStreamRequest* pRequest, u32 global, s32 ID_1, s32 ID_2, s32 ID_3, uintptr thisId, bool isRelease);
    SeVoice* getNewestSeVoice(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId);
    StreamVoice* getNewestStreamVoice(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId);
    s32 getSeLinkRequestNo(rSoundRequest* pRequest, const u32 reqNo);
    s32 getStreamLinkRequestNo(rSoundStreamRequest* pRequest, const u32 reqNo);
    void setSeEntry(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, ControlParam& param, bool isLink, ENTRY_COMMAND entryCommand, u32 entryType, CALLBACK_FUNC cb, void* arg, void* pNativeParam);
    void setSeEntry(rSoundBank* pBank, u32 noteNo, u32 prio, uintptr thisId, ControlParam& param, u32 entryType);
    void setStreamEntry(rSoundStreamRequest* pRequest, u32 reqNo, uintptr thisId, ControlParam& param, bool isLink, ENTRY_COMMAND entryCommand, u32 entryType, CALLBACK_FUNC cb, void* arg, void* pNativeParam);
    void clearSeEntry();
    void clearStreamEntry();
    void setVoiceParam(Voice* pVoice, Entry* pEntry);
    void getSeEntryControlParam(SeEntryControlParam* pSeEntryControlParam, SeEntry* pOriginalEntry);
    void getSeEntryControlParamEx(SeEntryControlParam* pSeEntryControlParam, SeEntry* pOriginalEntry);
    void getStreamEntryControlParam(StreamEntryControlParam* pStreamEntryControlParam, StreamEntry* pOriginalEntry);
    void getStreamEntryControlParamEx(StreamEntryControlParam* pStreamEntryControlParam, StreamEntry* pOriginalEntry);
    void updateSeEntryCoord();
    void updateStreamEntryCoord();
    rSoundReverb* getReverbResource();
    void setReverbResource(rSoundReverb* pReverb);
    void setListeningMatrix0(const MtMatrix& listeningMatrix);
    void setListeningMatrix1(const MtMatrix& listeningMatrix);
    void setListeningMatrix2(const MtMatrix& listeningMatrix);
    void setListeningMatrix3(const MtMatrix& listeningMatrix);
    MtMatrix getListeningMatrix0();
    MtMatrix getListeningMatrix1();
    MtMatrix getListeningMatrix2();
    MtMatrix getListeningMatrix3();
    void setTotalMasterVolumeDecibel(f32 vol_dB);
    f32 getTotalMasterVolumeDecibel();
    void setSeMasterVolumeDecibel(f32 vol_dB);
    f32 getSeMasterVolumeDecibel();
    void setBgmMasterVolumeDecibel(f32 vol_dB);
    f32 getBgmMasterVolumeDecibel();
    void setEnvMasterVolumeDecibel(f32 vol_dB);
    f32 getEnvMasterVolumeDecibel();
    void setVoiceMasterVolumeDecibel(f32 vol_dB);
    f32 getVoiceMasterVolumeDecibel();
    void setSystemMasterVolumeDecibel(f32 vol_dB);
    f32 getSystemMasterVolumeDecibel();
    void setEventMasterVolumeDecibel(f32 vol_dB);
    f32 getEventMasterVolumeDecibel();
    void setLFEMasterVolumeDecibel(f32 vol_dB);
    f32 getLFEMasterVolumeDecibel();
    void setActiveListening0(bool b);
    void setActiveListening1(bool b);
    void setActiveListening2(bool b);
    void setActiveListening3(bool b);
    bool getActiveListening0();
    bool getActiveListening1();
    bool getActiveListening2();
    bool getActiveListening3();
    void setListeningMuteFlag0(bool b);
    void setListeningMuteFlag1(bool b);
    void setListeningMuteFlag2(bool b);
    void setListeningMuteFlag3(bool b);
    bool getListeningMuteFlag0();
    bool getListeningMuteFlag1();
    bool getListeningMuteFlag2();
    bool getListeningMuteFlag3();
    void stopAllSe();
    void stopAllStream();
    void pauseAll();
    void resumeAll();
    void resolveEntry();
    void updateSe();
    void updateStream();
    void updateExternal();
    bool isUpdateFrame() const;
    u32 getUpdateTime() const;
    void createEffect(u32 index, u32 type);
    void updateUpDownMixGains();
    void initAudio();
    void finalAudio();
    void makeSineWave(void* pbuf, u32 step);
    void makeSquareWave(void* pbuf, u32 step);
    void makeSquare13Wave(void* pbuf, u32 step);
    void makeSquare17Wave(void* pbuf, u32 step);
    void makeSawWave(void* pbuf, u32 step);
    void makeTriangleWave(void* pbuf, u32 step);
    void makeSampleHoldWave(void* pbuf);
public:
    void playSynthPresetSequence(u32);
    void updateStreamBuffer();
    void loadStreamBuffer();
    NativeVoice* getNativeVoice(Voice::VOICE_TYPE type, u32 index);
private:
    u16 getCurrentPlatform();
public:
    NativeSystemPS4* getNativeSystemPS4() const;
private:
    NGS2System* getNGS2System();
public:
    void requestSePadSpeaker(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 padNo, CALLBACK_FUNC cb, void* arg);
    void requestSePadSpeaker(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 padNo, const MtVector3& position, CALLBACK_FUNC cb, void* arg);
    void requestSePadSpeaker(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 padNo, const MtVector3& position, const MtQuaternion& quaternion, CALLBACK_FUNC cb, void* arg);
    void requestSePadSpeaker(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 padNo, const uCoord* pCoord, s32 jointNo, CALLBACK_FUNC cb, void* arg);
    void requestStreamPadSpeaker(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 padNo, CALLBACK_FUNC cb, void* arg);
    void requestStreamPadSpeaker(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 padNo, const MtVector3& position, CALLBACK_FUNC cb, void* arg);
    void requestStreamPadSpeaker(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 padNo, const MtVector3& position, const MtQuaternion& quaternion, CALLBACK_FUNC cb, void* arg);
    void requestStreamPadSpeaker(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 padNo, const uCoord* pCoord, s32 jointNo, CALLBACK_FUNC cb, void* arg);
    void requestSeRestricted(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, CALLBACK_FUNC cb, void* arg);
    void requestSeRestricted(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, CALLBACK_FUNC cb, void* arg);
    void requestSeRestricted(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, const MtQuaternion& quaternion, CALLBACK_FUNC cb, void* arg);
    void requestSeRestricted(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, const uCoord* pCoord, s32 jointNo, CALLBACK_FUNC cb, void* arg);
    void requestStreamRestricted(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, CALLBACK_FUNC cb, void* arg);
    void requestStreamRestricted(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, CALLBACK_FUNC cb, void* arg);
    void requestStreamRestricted(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, const MtQuaternion& quaternion, CALLBACK_FUNC cb, void* arg);
    void requestStreamRestricted(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const uCoord* pCoord, s32 jointNo, CALLBACK_FUNC cb, void* arg);
    void setExternalVoiceRestricted(uintptr thisId, bool restricted);
private:
    NativeVoicePool* mpNativeVoicePool;  // offset: 0x18
public:
    NativeSystem* mpNativeSystem;  // offset: 0x20
protected:
    bool mFinalizeDone;  // offset: 0x28
private:
    MtPerformanceTimer mPerfCount;  // offset: 0x30
public:
    SeVoice mSeVoice[96];  // offset: 0x50
    StreamVoice mStreamVoice[8];  // offset: 0x40e50
    ExternalVoice mExtVoice;  // offset: 0x464d0
    SeEntry* mpSeEntry;  // offset: 0x46f30
    StreamEntry* mpStreamEntry;  // offset: 0x46f38
    MtCriticalSection mSeEntrySection;  // offset: 0x46f40
    MtCriticalSection mStreamEntrySection;  // offset: 0x46f48
    MtCriticalSection mSeEntryEndMarkerSection;  // offset: 0x46f50
    MtCriticalSection mStreamEntryEndMarkerSection;  // offset: 0x46f58
    u32 mSeVoiceNum;  // offset: 0x46f60
    u32 mStreamVoiceNum;  // offset: 0x46f64
    u32 mSeLinkMax;  // offset: 0x46f68
    u32 mStreamLinkMax;  // offset: 0x46f6c
    u32 mSeEntryNum;  // offset: 0x46f70
    u32 mStreamEntryNum;  // offset: 0x46f74
    SE_ENTRY_PARAMETER mSeEntryParameter;  // offset: 0x46f78
    STREAM_ENTRY_PARAMETER mStreamEntryParameter;  // offset: 0x46f90
    SeEntry* mpSeEntryReadPtr;  // offset: 0x46fa8
    SeEntry* mpSeEntryWritePtr;  // offset: 0x46fb0
    SeEntry* mpSeEntryEndMarker;  // offset: 0x46fb8
    StreamEntry* mpStreamEntryReadPtr;  // offset: 0x46fc0
    StreamEntry* mpStreamEntryWritePtr;  // offset: 0x46fc8
    StreamEntry* mpStreamEntryEndMarker;  // offset: 0x46fd0
    EffectBase* mpEffect[4];  // offset: 0x46fd8
    u32 mReverbChannelNum;  // offset: 0x46ff8
    cSoundCompressor mCompressor;  // offset: 0x47000
    cSoundLimitter mLimitter;  // offset: 0x470e0
    f32 mTotalMasterVolume;  // offset: 0x47108
    f32 mSeMasterVolume;  // offset: 0x4710c
    f32 mBgmMasterVolume;  // offset: 0x47110
    f32 mEnvMasterVolume;  // offset: 0x47114
    f32 mVoiceMasterVolume;  // offset: 0x47118
    f32 mSystemMasterVolume;  // offset: 0x4711c
    f32 mEventMasterVolume;  // offset: 0x47120
    f32 mLFEMasterVolume;  // offset: 0x47124
    Listening mListening[4];  // offset: 0x47130
    size_t mActiveListeningIndexBit;  // offset: 0x47370
    f32 mUpDownMixGains[6];  // offset: 0x47378
    f32 mSonicSpeed;  // offset: 0x47390
    f32 mDopplerMasterScaler;  // offset: 0x47394
    cSoundPanner mPanner;  // offset: 0x473a0
    SpeakerAngle mSpeakerAngle51;  // offset: 0x47650
    SpeakerAngle mSpeakerAngle71;  // offset: 0x4765c
    u32 mChannelsProcess;  // offset: 0x47668
    bool mIs51SourceDiffuse;  // offset: 0x4766c
    f32 mFrameMsec;  // offset: 0x47670
    u32 mFrameCount;  // offset: 0x47674
    u32 mUpdateFrame;  // offset: 0x47678
    u32 mUpdateTime;  // offset: 0x4767c
    u32 mRequestCount;  // offset: 0x47680
    bool mIsAllPause;  // offset: 0x47684
    bool mIsSystemPause;  // offset: 0x47685
    bool mIsStereoLFE;  // offset: 0x47686
    bool mIsPanDepthMinus3dB;  // offset: 0x47687
    void* mpPresetBuffer;  // offset: 0x47688
    f32 mPresetFrequencyRatio;  // offset: 0x47690
    f32 mSampleHoldFrequencyRatio;  // offset: 0x47694
    CALLBACK_FUNC mpExtractPlayCallback;  // offset: 0x47698
    void* mpExtrackPlayCallbackArg;  // offset: 0x476a0
    uintptr mExtrackPlayCallbackID;  // offset: 0x476a8
    bool mIsStreamSourcePackage;  // offset: 0x476b0
private:
    UpdateThread mUpdateThread;  // offset: 0x476b8
    MtCriticalSection mUpdateSection;  // offset: 0x47728
    MtCriticalSection mFrameCallbackSection;  // offset: 0x47730
    LoadThread mLoadThread;  // offset: 0x47738
    MtCriticalSection mStreamLoadSection;  // offset: 0x477a8
    SeRequestItem mSeRequestQueue[32];  // offset: 0x477b0
    s32 mCurrentSeRequest;  // offset: 0x47db0
    RandomHistory mRandomHistory[16];  // offset: 0x47db8
    RandomHistory* mpCurrentRandomHistory;  // offset: 0x47eb8
    SoundFrameCallback mpSoundFrameCallback[8];  // offset: 0x47ec0
    rSoundCurveSet* mpCurveSet;  // offset: 0x47f80
    rSoundDirectionalSet* mpDirectionalSet;  // offset: 0x47f88
    ReverbResource mReverbResource;  // offset: 0x47f90
    EQResource mEQResource;  // offset: 0x47fb8
    u16 mCurrentPlatform;  // offset: 0x48008
public:
    static MyDTI DTI;
    static const MtProperty::TYPE PROP_TYPE_BOOL = static_cast<MtProperty::TYPE>(3);
    static const s32 REQUEST_VOLUME_MIN = -96;
    static const s32 REQUEST_VOLUME_MAX = 6;
    static const s32 REQUEST_EFFECT_VOLUME_MIN = -96;
    static const s32 REQUEST_EFFECT_VOLUME_MAX = 6;
    static const s32 REQUEST_LFE_VOLUME_MIN = -96;
    static const s32 REQUEST_LFE_VOLUME_MAX = 6;
    static const u32 REQUEST_PAN_MIN = 0;
    static const u32 REQUEST_PAN_MAX = 255;
    static const s32 REQUEST_PITCH_MIN = -2400;
    static const s32 REQUEST_PITCH_MAX = 2400;
    static const s32 CATEGORY_MASTER_VOLUME_MIN = -96;
    static const s32 CATEGORY_MASTER_VOLUME_MAX = 6;
    static const u32 SE_VOICE_MAX = 96;
    static const u32 STREAM_VOICE_MAX = 8;
    static const u32 EXTERNAL_VOICE_MAX = 1;
    static const u32 LISTENING_MAX = 4;
    static const u32 WORK_AREA_NUM = 2;
    static const u32 FREE_AREA_NUM = 16;
    static const u32 DEFAULT_SE_ENTRY_NUM = 1024;
    static const u32 DEFAULT_STREAM_ENTRY_NUM = 32;
    static const u32 CATEGORY_EQ_NUM = 4;
    static const u32 FX_NUM = 2;
    static const u32 PICOLA_PITCHSHIFT_NUM = 4;
    static const u32 SOUND_FRAME_CALLBACK_MAX = 8;
    static const u32 CHANNEL_NUM_MONAURAL = 1;
    static const u32 CHANNEL_NUM_STEREO = 2;
    static const u32 CHANNEL_NUM_SURROUND_51 = 6;
    static const u32 BASE_FREQUENCY = 48000;
    static const u32 OUTPUT_CHANNEL_MAX = 6;
    static const u32 mEffectNum = 4;
    static const u32 mEQNum = 9;
    static const f32 MIN_REVERB_OUTPUTLEVEL;
    static const f32 MAX_REVERB_OUTPUTLEVEL;
    static const f32 DEFAULT_REVERB_OUTPUTLEVEL;
    static const u32 SYNTH_FREQ = 32728;
    static const u32 SYNTH_BUFFER_SIZE = 2048;
    static const u32 MAX_SE_REQUEST_NUM = 32;
    static const u32 NO_MARKER_SAMPLE_POS = 4294967295;
    static const u32 DEFAULT_MARKER_ID = 127;
    static const u32 WARNING_UPDATE_INTERVAL = 100;
    static const f32 SPEAKER_ANGLE_FRONT_DEFAULT;
    static const f32 SPEAKER_ANGLE_FRONT_MIN;
    static const f32 SPEAKER_ANGLE_FRONT_MAX;
    static const f32 SPEAKER_ANGLE_SURROUND_DEFAULT;
    static const f32 SPEAKER_ANGLE_SURROUND_MIN;
    static const f32 SPEAKER_ANGLE_SURROUND_MAX;
    static const f32 SPEAKER_ANGLE_ENHANCE_DEFAULT;
    static const f32 SPEAKER_ANGLE_ENHANCE_MIN;
    static const f32 SPEAKER_ANGLE_ENHANCE_MAX;
    static sSound* mpInstance;
private:
    static const u32 MAX_RANDOM_HISTORY = 16;
public:
    static const f32 I3DL2_REVERB_MIN_OUTPUT_LEVEL;
    static const s32 I3DL2_REVERB_MIN_ROOM;
    static const s32 I3DL2_REVERB_MIN_ROOM_HF;
    static const f32 I3DL2_REVERB_MIN_DECAY_TIME;
    static const f32 I3DL2_REVERB_MIN_DECAY_HF_RATIO;
    static const s32 I3DL2_REVERB_MIN_REFLECTIONS;
    static const f32 I3DL2_REVERB_MIN_REFLECTIONS_DELAY;
    static const s32 I3DL2_REVERB_MIN_REVERB;
    static const f32 I3DL2_REVERB_MIN_REVERB_DELAY;
    static const f32 I3DL2_REVERB_MIN_DIFFUSION;
    static const f32 I3DL2_REVERB_MIN_DENSITY;
    static const f32 I3DL2_REVERB_MIN_HF_REFERENCE;
    static const f32 I3DL2_REVERB_MIN_EARLYREFLECTIONSCALER;
    static const f32 I3DL2_REVERB_MIN_LF_REFERENCE;
    static const f32 I3DL2_REVERB_MIN_ROOM_LF;
    static const f32 I3DL2_REVERB_MAX_OUTPUT_LEVEL;
    static const s32 I3DL2_REVERB_MAX_ROOM;
    static const s32 I3DL2_REVERB_MAX_ROOM_HF;
    static const f32 I3DL2_REVERB_MAX_DECAY_TIME;
    static const f32 I3DL2_REVERB_MAX_DECAY_HF_RATIO;
    static const s32 I3DL2_REVERB_MAX_REFLECTIONS;
    static const f32 I3DL2_REVERB_MAX_REFLECTIONS_DELAY;
    static const s32 I3DL2_REVERB_MAX_REVERB;
    static const f32 I3DL2_REVERB_MAX_REVERB_DELAY;
    static const f32 I3DL2_REVERB_MAX_DIFFUSION;
    static const f32 I3DL2_REVERB_MAX_DENSITY;
    static const f32 I3DL2_REVERB_MAX_HF_REFERENCE;
    static const f32 I3DL2_REVERB_MAX_EARLYREFLECTIONSCALER;
    static const f32 I3DL2_REVERB_MAX_LF_REFERENCE;
    static const f32 I3DL2_REVERB_MAX_ROOM_LF;
    static const f32 I3DL2_REVERB_DEFAULT_OUTPUT_LEVEL;
    static const s32 I3DL2_REVERB_DEFAULT_ROOM;
    static const s32 I3DL2_REVERB_DEFAULT_ROOM_HF;
    static const f32 I3DL2_REVERB_DEFAULT_DECAY_TIME;
    static const f32 I3DL2_REVERB_DEFAULT_DECAY_HF_RATIO;
    static const s32 I3DL2_REVERB_DEFAULT_REFLECTIONS;
    static const f32 I3DL2_REVERB_DEFAULT_REFLECTIONS_DELAY;
    static const s32 I3DL2_REVERB_DEFAULT_REVERB;
    static const f32 I3DL2_REVERB_DEFAULT_REVERB_DELAY;
    static const f32 I3DL2_REVERB_DEFAULT_DIFFUSION;
    static const f32 I3DL2_REVERB_DEFAULT_DENSITY;
    static const f32 I3DL2_REVERB_DEFAULT_HF_REFERENCE;
    static const f32 I3DL2_REVERB_DEFAULT_EARLYREFLECTIONSCALER;
    static const f32 I3DL2_REVERB_DEFAULT_LF_REFERENCE;
    static const f32 I3DL2_REVERB_DEFAULT_ROOM_LF;
    static const f32 I3DL2_REVERB_DEFAULT_WETDRYMIX;
    static const f32 I3DL2_REVERB_DEFAULT_LF_ROOMROLLOFFFACTOR;
    static const f32 EQ_DEFAULT_LOW_FREQ;
    static const f32 EQ_DEFAULT_MID_LOW_FREQ;
    static const f32 EQ_DEFAULT_MID_HIGH_FREQ;
    static const f32 EQ_DEFAULT_HIGH_FREQ;
    static const f32 EQ_DEFAULT_GAIN;
    static const f32 EQ_DEFAULT_Q;
};

// Inline, no code of its own: checked where it is inlined.
inline sSound* sSound::getInstance() {
    return ::sSound::mpInstance;
}
