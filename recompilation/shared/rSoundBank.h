#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtEaseCurve.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtEaseCurve;
class MtObject;
class MtStream;
class rSoundSource;

// Declarations
class rSoundBank;

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

class rSoundBank : public cResource
{
public:
    enum ElementAttribute
    {
        FIXED_KEY = 1,
        RANDOM_LEVEL = 2,
        RANDOM_PITCH = 4,
        RANDOM_PANNING = 8,
        AMP_ENVELOPE = 16,
        PITCH_ENVELOPE = 32,
        HISTORICAL_RANDOM = 64,
    };
    enum ElementAttribute2
    {
        SECONDARY = 1,
        FILTER = 2,
        RANDOM_FILTER_FREQ = 4,
        BLANK = 16,
    };
    enum OscillatorType
    {
        OT_WAVE = 0,
        OT_SINE = 1,
        OT_SQUARE = 2,
        OT_SQUARE_1_3 = 3,
        OT_SQUARE_1_7 = 4,
        OT_SAW = 5,
        OT_TRIANGLE = 6,
        OT_SAMPLE_HOLD = 7,
    };
public:
    class MyDTI;
    struct Program;
    struct Element;
    struct Bus;
    struct Header;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Program
    {
    public:
        u32 mProgramNumber : 16;  // offset: 0x0
        u32 mMonophonic : 1;  // offset: 0x0
        u32 mElementNum : 10;  // offset: 0x0
        u32 mHistoricalRandom : 1;  // offset: 0x0
        u32 mPadding : 4;  // offset: 0x0
        rSoundBank::Element* mpElements;  // offset: 0x8
        u32 mRandomAmount : 24;  // offset: 0x10
        u32 mOutputBus : 8;  // offset: 0x10
    };
public:
    struct Element
    {
    public:
        rSoundSource* mpSource;  // offset: 0x0
        u32 mDTIID;  // offset: 0x8
        u8 mOscillator;  // offset: 0xc
        u8 mAttribute;  // offset: 0xd
        u8 mAttribute2;  // offset: 0xe
        u8 mAlternateGroup;  // offset: 0xf
        u8 mRandomTrigger;  // offset: 0x10
        u8 mLevel;  // offset: 0x11
        u8 mRandomLevelLow;  // offset: 0x12
        u8 mRandomLevelHigh;  // offset: 0x13
        s8 mPan;  // offset: 0x14
        s8 mRandomPanLeft;  // offset: 0x15
        s8 mRandomPanRight;  // offset: 0x16
        u8 mLinkGroup;  // offset: 0x17
        s16 mPitch;  // offset: 0x18
        s16 mRandomPitchLow;  // offset: 0x1a
        s16 mRandomPitchHigh;  // offset: 0x1c
        u16 mDelayTime;  // offset: 0x1e
        u8 mVelocityLowRange;  // offset: 0x20
        u8 mVelocityHighRange;  // offset: 0x21
        u8 mVelocityLowLevel;  // offset: 0x22
        u8 mVelocityHighLevel;  // offset: 0x23
        MtEaseCurve mVelocityCurve;  // offset: 0x24
        u16 mAEGAttackTime;  // offset: 0x2c
        u16 mAEGDecayTime;  // offset: 0x2e
        s16 mAEGSustainRate;  // offset: 0x30
        u16 mAEGReleaseTime;  // offset: 0x32
        u16 mPEGAttackTime;  // offset: 0x34
        u16 mPEGDecayTime;  // offset: 0x36
        s16 mPEGSustainRate;  // offset: 0x38
        u16 mPEGReleaseTime;  // offset: 0x3a
        u8 mAEGSustainLevel;  // offset: 0x3c
        s8 mAEGRateScaling;  // offset: 0x3d
        s8 mAEGRateVelocitySens;  // offset: 0x3e
        s8 mPEGInitialLevel;  // offset: 0x3f
        s8 mPEGAttackLevel;  // offset: 0x40
        s8 mPEGSustainLevel;  // offset: 0x41
        s8 mPEGReleaseLevel;  // offset: 0x42
        s8 mPEGRateScaling;  // offset: 0x43
        s8 mPEGRateVelocitySens;  // offset: 0x44
        s8 mPEGRange;  // offset: 0x45
        u16 mRandomValueLow;  // offset: 0x46
        u16 mRandomValueHigh;  // offset: 0x48
        u8 mFilterType;  // offset: 0x4a
        u8 mFilterQ;  // offset: 0x4b
        s16 mFilterGain;  // offset: 0x4c
        u16 mFilterFreq;  // offset: 0x4e
        u16 mRandomFilterFreqRange;  // offset: 0x50
        s8 mFilterFreqVelocitySens;  // offset: 0x52
        u8 mOriginalKey;  // offset: 0x53
        u8 mLowKey;  // offset: 0x54
        u8 mHighKey;  // offset: 0x55
        u16 mFlangingTime;  // offset: 0x56
    };
public:
    struct Bus
    {
    public:
        f32 mLevel;  // offset: 0x0
        u8 mBusNo;  // offset: 0x4
        u8 mPadding;  // offset: 0x5
        s16 mPitch;  // offset: 0x6
    };
public:
    struct Header
    {
    public:
        s32 mMagic;  // offset: 0x0
        u32 mVersion;  // offset: 0x4
        u32 mProgramNum;  // offset: 0x8
        u32 mElementNum;  // offset: 0xc
        u32 mBusNum;  // offset: 0x10
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
    rSoundBank();
    virtual ~rSoundBank();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool loadEnd();  // vtable slot 10
    virtual bool save(MtStream& out);  // vtable slot 12
    const Program* findProgram(u32 no) const;
    const Program* getProgram(u32 index) const;
    const Element* getElement(u32 index) const;
    const Bus* getBus(u32 no) const;
    u32 getElementIndex(const Element* pElement) const;
    u32 enumAdaptedElement(bool(*pfunc)(const Element*, void*, const u32), void* pArg, u32 prg_num, u32 key, u32 vel) const;
protected:
    bool checkKeyRange(const Element* pElem, u32 key) const;
    void freeAll();
    void* memAlloc(u32 size, u32 align);
    void memFree(void*);
protected:
    u32 mProgramNum;  // offset: 0x70
    Program* mpProgramArray;  // offset: 0x78
    u32 mElementNum;  // offset: 0x80
    Element* mpElementArray;  // offset: 0x88
    u32 mBusNum;  // offset: 0x90
    Bus* mpBusArray;  // offset: 0x98
public:
    static MyDTI DTI;
    static const s8 ELEMENT_PAN_MIN = -128;
    static const s8 ELEMENT_PAN_MAX = 127;
    static const s8 ELEMENT_PAN_DEF = 0;
    static const u32 ELEMENT_PAN_AROUND = 256;
    static const u32 ELEMENT_PAN_HALF = 128;
    static const u16 ELEMENT_FLANGING_TIME_MIN = 0;
    static const u16 ELEMENT_FLANGING_TIME_MAX = 16383;
    static const u16 ELEMENT_FLANGING_TIME_DEF = 0;
protected:
    static const u32 mVersion = 4;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK10rSoundBank5MyDTI11newInstanceEv at 0x00e45800-0x00e4585e, code DWARF attributes to no inlined copy
inline rSoundBank::rSoundBank() {
    this->::cResource::mAttr = static_cast<u32>(16);
    this->mProgramNum = static_cast<u32>(0);
    this->mpProgramArray = static_cast<rSoundBank::Program*>(nullptr);
    this->mElementNum = static_cast<u32>(0);
    this->mpElementArray = static_cast<rSoundBank::Element*>(nullptr);
    this->mBusNum = static_cast<u32>(0);
    this->mpBusArray = static_cast<rSoundBank::Bus*>(nullptr);
}
