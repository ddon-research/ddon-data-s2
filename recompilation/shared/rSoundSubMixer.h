#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class rSoundSimpleCurve;

// Declarations
class rSoundSubMixer;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rSoundSubMixer : public cResource
{
public:
    class MyDTI;
    class Fader;
    struct NATIVE_FILE_HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Fader : public MtObject
    {
    public:
        enum FADER_MODE
        {
            FADER_MODE_NONE = 0,
            FADER_MODE_TRANSITION = 1,
            FADER_MODE_SUSTAIN = 2,
            FADER_MODE_RELEASE = 4,
        };
        enum FADER_STATUS
        {
            FADER_STATUS_NONE = 0,
            FADER_STATUS_TRANSITION = 1,
            FADER_STATUS_SUSTAIN = 2,
            FADER_STATUS_RELEASE = 3,
            FADER_STATUS_DESTROY = 4,
        };
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
        Fader();
        virtual ~Fader();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        u8 getFaderID();
        void setFaderID(u8 faderID);
        s16 getSendID();
        void setSendID(s16 sendID);
        f32 getVol();
        void setVol(f32 vol);
        s8 getEqNo();
        void setEqNo(s8 eqNo);
        s8 getEffectNo();
        void setEffectNo(s8 effectNo);
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
        MtString getName();
        void setName(MtString name);
        MtString getComment();
        void setComment(MtString);
        bool getSetFlag();
        void setSetFlag(bool setFlag);
        void copyFaderWoIdStr(rSoundSubMixer::Fader* pPostFader);
        void copyFaderWoStr(rSoundSubMixer::Fader* pPostFader);
        void copyFader(rSoundSubMixer::Fader* pPostFader);
    protected:
        f32 mVol;  // offset: 0x8
        s16 mSendID;  // offset: 0xc
        u16 mTransitionTime;  // offset: 0xe
        s16 mCurve;  // offset: 0x10
        u16 mSustainTime;  // offset: 0x12
        u16 mReleaseTime;  // offset: 0x14
        u8 mFaderID;  // offset: 0x16
        s8 mEqNo;  // offset: 0x17
        s8 mEffectNo;  // offset: 0x18
        bool mAbs;  // offset: 0x19
        bool mSetFlag;  // offset: 0x1a
    public:
        static const f32 DEFAULT_VOL;
        static const u16 DEFAULT_TRANSITIONTIME = 0;
        static const u16 DEFAULT_SUSTAINTIME = 0;
        static const u16 DEFAULT_RELEASETIME = 0;
        static const u16 DEFAULT_ELAPSEDTIME = 0;
        static const s16 DEFAULT_CURVE = -1;
        static const s16 DEFAULT_SENDID = -1;
        static const u8 DEFAULT_FADER_ID = 0;
        static const s8 DEFAULT_EQNO = -2;
        static const s8 DEFAULT_EFFECTNO = -2;
        static const bool DEFAULT_ABS = 0;
        static const bool FADER_PASS = 0;
        static const bool FADER_BYPASS = 1;
        static const bool CALC_NECESSARY = 1;
        static const bool CALC_UNNECESSARY = 0;
        static const bool SET_NECESSARY = 1;
        static const bool SET_UNNECESSARY = 0;
        static MyDTI DTI;
    };
public:
    struct NATIVE_FILE_HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u32 Version;  // offset: 0x4
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
    rSoundSubMixer();
    virtual ~rSoundSubMixer();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool convert(MtStream& out);  // vtable slot 13
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    bool getActive();
    void setActive(bool active);
    s8 getPriority();
    void setPriority(s8 priority);
    s32* getEQPreset();
    s32 getEQPreset(u32 index);
    void setEQPreset(u32, s32);
    s32* getReverbPreset();
    s32 getReverbPreset(u32 index);
    void setReverbPreset(u32, s32);
    MtString getSceneName();
    void setSceneName(MtString);
    u8 getMaxFaderID();
    void add();
    void add(Fader* pFader);
    void erase(u8 index);
    void erase(Fader* pFader);
    virtual void clear();  // vtable slot 15
    Fader* getFader(u8 index);
    Fader* getFaderByID(u8 id);
    u16 getFaderSize();
    bool createFaderIDToIndexTbl();
    bool determineCanBeSetSubMixer(rSoundSubMixer* pPostSubMixer);
    bool setSubMixer(rSoundSubMixer* pPostSubMixer);
    bool initCalc(u32 step);
    bool checkCalculationFader();
    bool checkCalculationFaderParam(u8 index, u8 sendIndex, Fader* pFader);
    bool calcTransition(f32 frameMsec);
    bool calcOutput();
    void setBypass(u8 index, u8 sendIndex, bool bypass);
    u32 getCurveStyle();
    void setCurveStyle(u32 curveStyle);
    rSoundSimpleCurve* getResourceSimpleCurve(u8 index);
    void setResourceSimpleCurve(u8 index, rSoundSimpleCurve* res);
    void setCalc(u8 index, bool calc);
    void setCalcBypass(u8 index, u8 sendIndex, bool bypass);
    f32 getCalcVol(u8 index, u8 sendIndex);
    void setCalcVol(u8 index, u8 sendIndex, f32 vol);
    s8 getCalcEqNo(u8 index, u8 sendIndex);
    void setCalcEqNo(u8 index, u8 sendIndex, s8 no);
    s8 getCalcEffectNo(u8 index, u8 sendIndex);
    void setCalcEffectNo(u8 index, u8 sendIndex, s8 no);
    bool getCalcAbs(u8 index, u8 sendIndex);
    void setCalcAbs(u8 index, u8 sendIndex, bool abs);
    s16 getCalcCurve(u8 index, u8 sendIndex);
    u16 getCalcTransitionTime(u8 index, u8 sendIndex);
    u16 getCalcSustainTime(u8 index, u8 sendIndex);
    u16 getCalcReleaseTime(u8 index, u8 sendIndex);
    Fader* getOutputFader(u8 index);
protected:
    bool checkSendLoop(u32 step);
protected:
    MtTypedArray<Fader> mFaders;  // offset: 0x70
    MtTypedArray<Fader> mOutputFaders;  // offset: 0x90
    s32 mEQPreset[9];  // offset: 0xb0
    s32 mReverbPreset[4];  // offset: 0xd4
    bool mActive;  // offset: 0xe4
    s8 mPriority;  // offset: 0xe5
    u16 mIDToIndexTblNum;  // offset: 0xe6
    s16* mpIDToIndexTbl;  // offset: 0xe8
    u32 mCurveStyle;  // offset: 0xf0
    rSoundSimpleCurve* mpSimpleCurve[4];  // offset: 0xf8
    u32 mSendNumAll;  // offset: 0x118
    u8* mpSendBuff;  // offset: 0x120
    u8* mpCalcBuff;  // offset: 0x128
    bool* mpCalc;  // offset: 0x130
    u16* mpSendNum;  // offset: 0x138
    s16* * mpaSendIndex;  // offset: 0x140
    bool* * mpaBypass;  // offset: 0x148
    f32* * mpaVol;  // offset: 0x150
    s8* * mpaEqNo;  // offset: 0x158
    s8* * mpaEffectNo;  // offset: 0x160
    bool* * mpaAbs;  // offset: 0x168
    bool* * mpaTransitionFlag;  // offset: 0x170
    u8* * mpaTransitionMode;  // offset: 0x178
    u8* * mpaTransitionStatus;  // offset: 0x180
    s16* * mpaCurve;  // offset: 0x188
    u16* * mpaTransitionTime;  // offset: 0x190
    u16* * mpaSustainTime;  // offset: 0x198
    u16* * mpaReleaseTime;  // offset: 0x1a0
    f32* * mpaStartVol;  // offset: 0x1a8
    f32* * mpaTargetVol;  // offset: 0x1b0
    f32* * mpaEndVol;  // offset: 0x1b8
    s8* * mpaOrgEqNo;  // offset: 0x1c0
    s8* * mpaOrgEffectNo;  // offset: 0x1c8
    bool* * mpaOrgAbs;  // offset: 0x1d0
    s16* * mpaOrgCurve;  // offset: 0x1d8
    u16* * mpaElapsedTime;  // offset: 0x1e0
public:
    static const u32 MAX_FADER = 256;
    static const u32 MAX_SEND_FADER = 256;
    static const u32 MAX_EQ_PRESET = 9;
    static const u32 MAX_REVERB_PRESET = 4;
    static const u32 MAX_CURVE_NUM = 4;
    static const s32 DEFAULT_EQ_PRESET = -1;
    static const s32 DEFAULT_REVERB_PRESET = -1;
    static const s16 DEFAULT_FADER_INDEX = -1;
    static const s8 DEFAULT_PRIORITY = -2;
    static const s8 RESET_PRIORITY = -1;
    static MyDTI DTI;
private:
    static const u32 NativeFileMagic = 1381518675;
    static const u32 NativeFileVersion = 1;
};

// Inline, no code of its own: checked where it is inlined.
inline bool rSoundSubMixer::getActive() {
    return this->mActive;
}

// Inline, no code of its own: checked where it is inlined.
inline u8 rSoundSubMixer::Fader::getFaderID() {
    return this->mFaderID;
}

// Inline, no code of its own: checked where it is inlined.
inline s16 rSoundSubMixer::Fader::getSendID() {
    return this->mSendID;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 rSoundSubMixer::Fader::getVol() {
    return this->mVol;
}

// Inline, no code of its own: checked where it is inlined.
inline s8 rSoundSubMixer::Fader::getEqNo() {
    return this->mEqNo;
}

// Inline, no code of its own: checked where it is inlined.
inline s8 rSoundSubMixer::Fader::getEffectNo() {
    return this->mEffectNo;
}

// Inline, no code of its own: checked where it is inlined.
inline bool rSoundSubMixer::Fader::getAbs() {
    return this->mAbs;
}

// Inline, no code of its own: checked where it is inlined.
inline s16 rSoundSubMixer::Fader::getCurve() {
    return this->mCurve;
}

// Inline, no code of its own: checked where it is inlined.
inline u16 rSoundSubMixer::Fader::getTransitionTime() {
    return this->mTransitionTime;
}

// Inline, no code of its own: checked where it is inlined.
inline u16 rSoundSubMixer::Fader::getSustainTime() {
    return this->mSustainTime;
}

// Inline, no code of its own: checked where it is inlined.
inline u16 rSoundSubMixer::Fader::getReleaseTime() {
    return this->mReleaseTime;
}

// Inline, no code of its own: checked where it is inlined.
inline bool rSoundSubMixer::Fader::getSetFlag() {
    return this->mSetFlag;
}
