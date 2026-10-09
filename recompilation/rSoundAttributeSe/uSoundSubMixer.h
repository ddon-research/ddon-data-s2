#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtSynchronize.h"
#include "../shared/cUnit.h"
#include "../shared/rSoundSubMixer.h"
#include "../shared/sSound.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class rSoundSimpleCurve;
class rSoundSubMixer;

// Declarations
class uSoundSubMixer;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using f32 = float;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class uSoundSubMixer : public cUnit
{
public:
    class MyDTI;
    class CurrentSubMixer;
    class FaderParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class CurrentSubMixer : public rSoundSubMixer
    {
    public:
        class MyDTI;
        class CurrentFader;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class CurrentFader : public rSoundSubMixer::Fader
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
            CurrentFader();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
            void setSubMixer(uSoundSubMixer* pSubMxer);
            void setSubMixerIndex(u8 index);
            void setFaderIndex(u8 index);
        private:
            f32 getVol();
            void setVol(f32 vol);
            bool getAbs();
            void setAbs(bool abs);
            s16 getCurve();
            void setCurve(s16 curve);
            u16 getTransitionTime();
            void setTransitionTime(u16 transitionTime);
            u16 getSustainTime();
            void setSustainTime(u16 sustainTime);
            u16 getReleaseTime();
            void setReleaseTime(u16 releaseTime);
            s8 getEqNo();
            void setEqNo(s8 eqNo);
            s8 getEffectNo();
            void setEffectNo(s8 effectNo);
        private:
            uSoundSubMixer* mpSoundSubMixer;  // offset: 0x20
            u8 mSubMixerIndex;  // offset: 0x28
            u8 mFaderIndex;  // offset: 0x29
        public:
            static MyDTI DTI;
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
        CurrentSubMixer();
        void add(rSoundSubMixer::Fader* pFader);
        s16 getIndexByID(u8 id);
    public:
        static MyDTI DTI;
    };
public:
    class FaderParam : public rSoundSubMixer::Fader
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
        FaderParam();
        virtual ~FaderParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setFader(rSoundSubMixer::Fader* pFader);
        void setSubMixer(uSoundSubMixer* pSubMxer);
    private:
        uSoundSubMixer* mpSoundSubMixer;  // offset: 0x20
    public:
        static MyDTI DTI;
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
    uSoundSubMixer();
    virtual ~uSoundSubMixer();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void clear();
    virtual void move();  // vtable slot 9
    bool initSubMixer(u8 subMixerNum, rSoundSubMixer* pPostSubMixer);
    void mergeSubMixer(u8 subMixerIndex, rSoundSubMixer* pSubMixer);
    void mergeSimpleCurve(u8 curveIndex, rSoundSimpleCurve* pCurve);
    void setUseFreeAreaNo(s8 freeAreaNo);
    s8 getUseFreeAreaNo();
    f32 getSeMasterVolume();
    f32 getBgmMasterVolume();
    f32 getEnvMasterVolume();
    f32 getVoiceMasterVolume();
    f32 getSystemMasterVolume();
    f32 getEventMasterVolume();
private:
    b8 getIsActiveSubMixer0();
    b8 getIsActiveSubMixer1();
    b8 getIsActiveSubMixer2();
    b8 getIsActiveSubMixer3();
    b8 getIsActiveSubMixer4();
    b8 getIsActiveSubMixer5();
    b8 getIsActiveSubMixer6();
    b8 getIsActiveSubMixer7();
    void setIsActiveSubMixer0(b8 isActiveSubMixer);
    void setIsActiveSubMixer1(b8 isActiveSubMixer);
    void setIsActiveSubMixer2(b8 isActiveSubMixer);
    void setIsActiveSubMixer3(b8 isActiveSubMixer);
    void setIsActiveSubMixer4(b8 isActiveSubMixer);
    void setIsActiveSubMixer5(b8 isActiveSubMixer);
    void setIsActiveSubMixer6(b8 isActiveSubMixer);
    void setIsActiveSubMixer7(b8 isActiveSubMixer);
    rSoundSubMixer* getResourceSubMixer(u8 index);
    rSoundSubMixer* getResourceSubMixer0();
    rSoundSubMixer* getResourceSubMixer1();
    rSoundSubMixer* getResourceSubMixer2();
    rSoundSubMixer* getResourceSubMixer3();
    rSoundSubMixer* getResourceSubMixer4();
    rSoundSubMixer* getResourceSubMixer5();
    rSoundSubMixer* getResourceSubMixer6();
    rSoundSubMixer* getResourceSubMixer7();
    void setResourceSubMixer(u8 index, rSoundSubMixer* res);
    void setResourceSubMixer0(rSoundSubMixer* res);
    void setResourceSubMixer1(rSoundSubMixer* res);
    void setResourceSubMixer2(rSoundSubMixer* res);
    void setResourceSubMixer3(rSoundSubMixer* res);
    void setResourceSubMixer4(rSoundSubMixer* res);
    void setResourceSubMixer5(rSoundSubMixer* res);
    void setResourceSubMixer6(rSoundSubMixer* res);
    void setResourceSubMixer7(rSoundSubMixer* res);
    void mergeSubMixer0();
    void mergeSubMixer1();
    void mergeSubMixer2();
    void mergeSubMixer3();
    void mergeSubMixer4();
    void mergeSubMixer5();
    void mergeSubMixer6();
    void mergeSubMixer7();
    void mergeSubMixerAll();
    void setResourceSimpleCurve(u8 index, rSoundSimpleCurve* res);
    void setResourceSimpleCurve0(rSoundSimpleCurve* res);
    void setResourceSimpleCurve1(rSoundSimpleCurve* res);
    void setResourceSimpleCurve2(rSoundSimpleCurve* res);
    void setResourceSimpleCurve3(rSoundSimpleCurve* res);
    rSoundSimpleCurve* getResourceSimpleCurve(u8 index);
    rSoundSimpleCurve* getResourceSimpleCurve0();
    rSoundSimpleCurve* getResourceSimpleCurve1();
    rSoundSimpleCurve* getResourceSimpleCurve2();
    rSoundSimpleCurve* getResourceSimpleCurve3();
    void mergeSimpleCurve0();
    void mergeSimpleCurve1();
    void mergeSimpleCurve2();
    void mergeSimpleCurve3();
    void executeMergeSubMixer(u8 subMixerIndex, rSoundSubMixer* pSubMixer);
    void executeMergeSimpleCurve(u8 curveIndex, rSoundSimpleCurve* pCurve);
    void setSubMixerActivate(u8 subMixerIndex, bool b);
    bool getSubMixerActivate(u8 subMixerIndex);
    u32 getCurveStyle();
    void setCurveStyle(u32 curveStyle);
    void setPreset();
    f32 getCalcFaderVol(u8 subMixerIndex, u8 faderIndex);
    void setCalcFaderVol(u8 subMixerIndex, u8 faderIndex, f32 vol);
    bool getCalcFaderAbs(u8 subMixerIndex, u8 faderIndex);
    void setCalcFaderAbs(u8 subMixerIndex, u8 faderIndex, bool abs);
    s16 getCalcFaderCurve(u8 subMixerIndex, u8 faderIndex);
    u16 getCalcFaderTransitionTime(u8 subMixerIndex, u8 faderIndex);
    u16 getCalcFaderSustainTime(u8 subMixerIndex, u8 faderIndex);
    u16 getCalcFaderReleaseTime(u8 subMixerIndex, u8 faderIndex);
    s8 getCalcFaderEqNo(u8 subMixerIndex, u8 faderIndex);
    void setCalcFaderEqNo(u8 subMixerIndex, u8 faderIndex, s8 no);
    s8 getCalcFaderEffectNo(u8 subMixerIndex, u8 faderIndex);
    void setCalcFaderEffectNo(u8 subMixerIndex, u8 faderIndex, s8 no);
    u8 getFaderParamNum();
    FaderParam* getFaderParam(u8 index);
    FaderParam* getFaderParamByID(u8 faderID);
    void applyFaderParameter();
    static void applyVoiceCallback(sSound::VoiceAccessor& va, void* p);
    static void applyExtractCallback(sSound::VoiceAccessor& va, void* p);
    void applyAllParameter(sSound::VoiceAccessor& va, FaderParam* pFader);
    void applyEqNo(sSound::VoiceAccessor& va, s8 eqIndex);
    void applyEffectNo(sSound::VoiceAccessor& va, s8 efcIndex);
    void createPropertyGroupSystemMasterVolume(MtPropertyList& s);
    void createPropertyGroupSubMixerEQ(MtPropertyList& s);
    void createPropertyGroupSubMixerEffect(MtPropertyList& s);
    void createPropertyGroupDebugButton(MtPropertyList& s);
    void createPropertyGroupSubMixerMonitor(MtPropertyList& s);
    void createPropertyGroupInitSubMixer(MtPropertyList& s);
    void createPropertyGroupSubMixerCurveResource(MtPropertyList& s);
    void createPropertyGroupSubMixer(MtPropertyList& s);
protected:
    virtual s32 getFaderID(sSound::VoiceAccessor& va);  // vtable slot 24
    virtual void applyVol(sSound::VoiceAccessor& va, f32 volume);  // vtable slot 25
    virtual void applyEfcSend(sSound::VoiceAccessor& va, f32 efcSend);  // vtable slot 26
private:
    MtTypedArray<rSoundSubMixer::Fader>* viewptr_submixer0_faders;  // offset: 0x48
    MtTypedArray<rSoundSubMixer::Fader>* viewptr_submixer1_faders;  // offset: 0x50
    MtTypedArray<rSoundSubMixer::Fader>* viewptr_submixer2_faders;  // offset: 0x58
    MtTypedArray<rSoundSubMixer::Fader>* viewptr_submixer3_faders;  // offset: 0x60
    MtTypedArray<rSoundSubMixer::Fader>* viewptr_submixer4_faders;  // offset: 0x68
    MtTypedArray<rSoundSubMixer::Fader>* viewptr_submixer5_faders;  // offset: 0x70
    MtTypedArray<rSoundSubMixer::Fader>* viewptr_submixer6_faders;  // offset: 0x78
    MtTypedArray<rSoundSubMixer::Fader>* viewptr_submixer7_faders;  // offset: 0x80
    MtCriticalSection mSoundSubMixerSection;  // offset: 0x88
    MtCriticalSection mSoundSimpleCurveSection;  // offset: 0x90
    MtTypedArray<CurrentSubMixer> mCurrentSubMixers;  // offset: 0x98
    MtTypedArray<rSoundSubMixer> mCalcFaderSubMixers;  // offset: 0xb8
    MtTypedArray<FaderParam> mFaderParam;  // offset: 0xd8
    rSoundSubMixer mCalcSendSubMixer;  // offset: 0xf8
    rSoundSubMixer* mpInitSubMixerResource;  // offset: 0x2e0
    rSoundSubMixer* mpSubMixerResource[8];  // offset: 0x2e8
    rSoundSimpleCurve* mpSimpleCurveResource[4];  // offset: 0x328
    s32 mEQPreset[9];  // offset: 0x348
    s32 mReverbPreset[4];  // offset: 0x36c
    u32 mCurveStyle;  // offset: 0x37c
    u8 mCurrentSubMixerNum;  // offset: 0x380
    u8 mCalcFaderSubMixerNum;  // offset: 0x381
    u16 mFaderNum;  // offset: 0x382
    u8 mCalcFaderNum;  // offset: 0x384
    s8 mUseFreeAreaNo;  // offset: 0x385
    bool mIsInitialize;  // offset: 0x386
    static const u32 MAX_CURVE_RESORCE = 4;
    static const u32 MAX_SUBMIXER = 8;
    static const u32 MAX_CALC_FADER = 32;
public:
    static MyDTI DTI;
private:
    static const u32 width_field_thin_under = 20;
    static const u32 width_field_thin = 24;
    static const u32 width_field_thin_over = 32;
    static const u32 width_field_narrow_under = 36;
    static const u32 width_field_narrow = 40;
    static const u32 width_field_narrow_over = 44;
    static const u32 width_field_normal_under = 48;
    static const u32 width_field_normal = 56;
    static const u32 width_field_normal_over = 64;
    static const u32 width_field_wide_under = 68;
    static const u32 width_field_wide = 80;
    static const u32 width_field_wide_over = 128;
    static const u32 width_field_wide_more = 490;
    static const u32 MAX_EQ_PRESET = 4;
    static const u32 MAX_EQMASTER_PRESET = 1;
    static const u32 MAX_EFFECT_PRESET = 4;
};

// Inline, no code of its own: checked where it is inlined.
inline uSoundSubMixer::CurrentSubMixer::CurrentSubMixer() {
}

// Inline, no code of its own: checked where it is inlined.
inline uSoundSubMixer::CurrentSubMixer::CurrentFader::CurrentFader() {
    this->mpSoundSubMixer = static_cast<uSoundSubMixer*>(nullptr);
    this->mSubMixerIndex = static_cast<u8>(0);
    this->mFaderIndex = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline uSoundSubMixer::FaderParam::FaderParam() {
    this->mpSoundSubMixer = static_cast<uSoundSubMixer*>(nullptr);
}
