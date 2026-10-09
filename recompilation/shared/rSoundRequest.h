#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cResource.h"
#include "rSoundBank.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
class rSoundBank;

// Declarations
class rSoundRequest;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __intptr_t = __int64_t;
using f32 = float;
using intptr = __intptr_t;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rSoundRequest : public cResource
{
public:
    enum SOUND_REQUEST_CATEGORY
    {
        SOUND_REQUEST_SE = 0,
        SOUND_REQUEST_ENV = 1,
        SOUND_REQUEST_VOICE = 2,
        SOUND_REQUEST_SYSTEM = 3,
        SOUND_REQUEST_CATEGORY_NUM = 4,
    };
public:
    class MyDTI;
    struct Element;
    struct ReadHeader;
    struct WriteHeader;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Element
    {
    public:
        u16 mReqNo;  // offset: 0x0
        u8 mKey;  // offset: 0x2
        u8 mVelocity;  // offset: 0x3
        u32 mCategory;  // offset: 0x4
        u32 mCommand;  // offset: 0x8
        u8 mGlobal;  // offset: 0xc
        u8 pad_01;  // offset: 0xd
        s16 mID_1;  // offset: 0xe
        s16 mID_2;  // offset: 0x10
        s16 mID_3;  // offset: 0x12
        u8 mPriority;  // offset: 0x14
        u8 mPrioMode;  // offset: 0x15
        s16 pad_02;  // offset: 0x16
        u32 mLimit;  // offset: 0x18
        s16 mLink;  // offset: 0x1c
        s16 mProgramNo;  // offset: 0x1e
        s16 mPan;  // offset: 0x20
        s16 pad_04;  // offset: 0x22
        f32 mVol;  // offset: 0x24
        f32 mEffectSend;  // offset: 0x28
        s32 mPitchShift;  // offset: 0x2c
        u32 mDelayTimer;  // offset: 0x30
        u32 mBookingTimer;  // offset: 0x34
        s32 mVolumeCurveID;  // offset: 0x38
        s32 mEffectCurveID;  // offset: 0x3c
        s32 mDirectionalCurveID;  // offset: 0x40
        u32 mFreeArea00_07;  // offset: 0x44
        u8 mFreeArea08;  // offset: 0x48
        u8 mFreeArea09;  // offset: 0x49
        u8 mFreeArea10;  // offset: 0x4a
        u8 mFreeArea11;  // offset: 0x4b
        s16 mFreeArea12;  // offset: 0x4c
        s16 mFreeArea13;  // offset: 0x4e
        s16 mFreeArea14;  // offset: 0x50
        s16 mFreeArea15;  // offset: 0x52
        s32 mBankFileNameTableIndex;  // offset: 0x54
        rSoundBank* mpBank;  // offset: 0x58
        cResource* mpPackage;  // offset: 0x60
        f32 mLFESend;  // offset: 0x68
        s32 mLFECurveID;  // offset: 0x6c
        u32 mCenterVolume;  // offset: 0x70
        s16 mEqNo;  // offset: 0x74
        s16 mEqEffectNo;  // offset: 0x76
        s16 mEffectNo;  // offset: 0x78
        s16 pad_03;  // offset: 0x7a
        f32 mInteriorDistance;  // offset: 0x7c
        f32 mDopplerScaler;  // offset: 0x80
        s32 mSpeakerSetIndex;  // offset: 0x84
        void* mpSpeakerSet;  // offset: 0x88
    };
public:
    struct ReadHeader
    {
    public:
        s32 Magic;  // offset: 0x0
        s32 Version;  // offset: 0x4
        u32 numElement;  // offset: 0x8
        u32 numSpeakerSet;  // offset: 0xc
        u32 numSpeaker;  // offset: 0x10
        u32 numDirectionalCurve;  // offset: 0x14
        u32 numDirectionalCurveElement;  // offset: 0x18
        u32 padding;  // offset: 0x1c
        intptr FilePathOffset;  // offset: 0x20
        intptr SpeakerSetOffset;  // offset: 0x28
        intptr SpeakerOffset;  // offset: 0x30
        intptr DirectionalCurveOffset;  // offset: 0x38
        intptr DirectionalCurveElementOffset;  // offset: 0x40
    };
public:
    struct WriteHeader
    {
    public:
        s32 Magic;  // offset: 0x0
        s32 Version;  // offset: 0x4
        u32 numElement;  // offset: 0x8
        u32 numSpeakerSet;  // offset: 0xc
        u32 numSpeaker;  // offset: 0x10
        u32 numDirectionalCurve;  // offset: 0x14
        u32 numDirectionalCurveElement;  // offset: 0x18
        u32 padding;  // offset: 0x1c
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
    rSoundRequest();
    virtual ~rSoundRequest();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    Element* getElementByIndex(u32 index) const;
    Element* getElement(u32 reqNo) const;
    s32 getElementNum() const;
protected:
    void freeMemory();
    void setup();
    s32 findSource(const MtTypedArray<rSoundBank>& array, const rSoundBank* pbnk);
private:
    bool createReqNoToIndexTbl();
protected:
    void* memAlloc(u32 size, u32 align);
    void memFree(void* p_addr);
protected:
    u8* mpRawData;  // offset: 0x70
    u32 mElementNum;  // offset: 0x78
    Element* mpElement;  // offset: 0x80
    void* mpSpeakerSets;  // offset: 0x88
    void* mpSpeakers;  // offset: 0x90
    void* mpDirectionalCurves;  // offset: 0x98
    void* mpDirectionalCurveElements;  // offset: 0xa0
    u32 mSpeakerSetNum;  // offset: 0xa8
    u32 mSpeakerNum;  // offset: 0xac
    u32 mDirectionalCurveNum;  // offset: 0xb0
    u32 mDirectionalCurveElementNum;  // offset: 0xb4
    MtTypedArray<rSoundBank> mBankList;  // offset: 0xb8
private:
    u16* mpReqNoToIndexTbl;  // offset: 0xd8
    u16 mReqNoToIndexTblNum;  // offset: 0xe0
public:
    static MyDTI DTI;
private:
    static const s32 NativeFileMagic = 1381061203;
    static const s32 NativeFileVersion = 3;
};
