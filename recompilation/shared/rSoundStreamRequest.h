#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cResource.h"
#include "rSoundSource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
class rSoundSource;
class rSoundStreamSourcePackage;

// Declarations
class rSoundStreamRequest;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __intptr_t = __int64_t;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using intptr = __intptr_t;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class rSoundStreamRequest : public cResource
{
public:
    enum SOUND_STREAM_READ_TYPE
    {
        SOUND_STREAM_READ_MEMORY = 0,
        SOUND_STREAM_READ_DISK = 1,
    };
    enum SOUND_STREAM_REQUEST_COMMAND
    {
        SOUND_COMMAND_BLANK = 0,
        SOUND_COMMAND_STREAM_PLAY = 1,
        SOUND_COMMAND_STREAM_STOP = 2,
        SOUND_COMMAND_STREAM_PAUSE = 3,
        SOUND_COMMAND_STREAM_BLANK = 4,
        SOUND_COMMAND_STREAM_FADE_IN = 5,
        SOUND_COMMAND_STREAM_FADE_OUT = 6,
        SOUND_COMMAND_STREAM_MOVE_VOL_ABS = 7,
        SOUND_COMMAND_STREAM_MOVE_VOL_REL = 8,
        SOUND_COMMAND_STREAM_MOVE_VOL_RAT = 9,
        SOUND_COMMAND_STREAM_PREPARE = 10,
        SOUND_COMMAND_STREAM_RESUME = 11,
    };
    enum SOUND_STREAM_REQUEST_CATEGORY
    {
        SOUND_STREAM_REQUEST_SE = 0,
        SOUND_STREAM_REQUEST_BGM = 1,
        SOUND_STREAM_REQUEST_ENV = 2,
        SOUND_STREAM_REQUEST_VOICE = 3,
        SOUND_STREAM_REQUEST_SYSTEM = 4,
        SOUND_STREAM_REQUEST_EVENT = 5,
        SOUND_STREAM_REQUEST_CATEGORY_NUM = 6,
    };
public:
    class MyDTI;
    struct Element;
    class SoundSource;
    struct StreamInfo;
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
        s16 pad_0;  // offset: 0x2
        u32 mCategory;  // offset: 0x4
        u32 mCommand;  // offset: 0x8
        u32 mReadType;  // offset: 0xc
        u8 mGlobal;  // offset: 0x10
        u8 pad_01;  // offset: 0x11
        s16 mID_1;  // offset: 0x12
        s16 mID_2;  // offset: 0x14
        s16 mID_3;  // offset: 0x16
        u8 mPriority;  // offset: 0x18
        u8 mPrioMode;  // offset: 0x19
        s16 pad_02;  // offset: 0x1a
        u32 mLimit;  // offset: 0x1c
        s16 mLink;  // offset: 0x20
        s16 mPan;  // offset: 0x22
        f32 mVol;  // offset: 0x24
        f32 mEffectSend;  // offset: 0x28
        s32 mPitchShift;  // offset: 0x2c
        u32 mDelayTimer;  // offset: 0x30
        u32 mBookingTimer;  // offset: 0x34
        s32 mVolumeCurveID;  // offset: 0x38
        s32 mEffectCurveID;  // offset: 0x3c
        s32 mDirectionalCurveID;  // offset: 0x40
        u32 mTime;  // offset: 0x44
        u32 mKillTime;  // offset: 0x48
        u32 mFreeArea00_07;  // offset: 0x4c
        u8 mFreeArea08;  // offset: 0x50
        u8 mFreeArea09;  // offset: 0x51
        u8 mFreeArea10;  // offset: 0x52
        u8 mFreeArea11;  // offset: 0x53
        s16 mFreeArea12;  // offset: 0x54
        s16 mFreeArea13;  // offset: 0x56
        s16 mFreeArea14;  // offset: 0x58
        s16 mFreeArea15;  // offset: 0x5a
        s32 mSrcFileNameTableIndex;  // offset: 0x5c
        u32 mDiskLocation;  // offset: 0x60
        f32 mLFESend;  // offset: 0x64
        u32 mCenterVolume;  // offset: 0x68
        s32 mLFECurveID;  // offset: 0x6c
        s16 mEqNo;  // offset: 0x70
        s16 mEqEffectNo;  // offset: 0x72
        s16 mEffectNo;  // offset: 0x74
        s16 pad_03;  // offset: 0x76
        f32 mInteriorDistance;  // offset: 0x78
        f32 mDopplerScaler;  // offset: 0x7c
        s32 mSpeakerSetIndex;  // offset: 0x80
        void* mpSpeakerSet;  // offset: 0x88
        rSoundStreamRequest::SoundSource* mpSource;  // offset: 0x90
    };
public:
    class SoundSource
    {
    public:
        SoundSource();
        ~SoundSource();
        void freeSource();
        u32 getChannelNum() const;
        u32 getSampleNum() const;
        u32 getSampleRate() const;
        s32 getLoopStart() const;
        s32 getLoopEnd() const;
        u32 getLength() const;
        u32 getReadType() const;
        u32 getReadMode() const;
        void setReadType(u32 type, u32 mode);
        void makeStreamInfo(rSoundStreamRequest::StreamInfo* pinfo);
        rSoundSource* createResource();
        bool setPath(MT_CTSTR path);
        u32 getResourceDTI() const;
        void setResourceDTI(u32 id);
        u32 getResourceFormat() const;
        void setSourceIndex(u32 sourceIndex);
        MT_CTSTR getPath() const;
        rSoundSource* getSource() const;
        void setStreamSourcePackage(rSoundStreamSourcePackage* pStreamSourcePackage);
        static void* operator new(size_t size);
        static void* operator new[](size_t size);
        static void operator delete(void* ptr);
        static void operator delete[](void* ptr);
    private:
        MT_CTSTR mpResourcePath;  // offset: 0x0
        u32 mSampleNum;  // offset: 0x8
        u32 mChannelNum;  // offset: 0xc
        u32 mSampleRate;  // offset: 0x10
        u32 mStreamLength;  // offset: 0x14
        s32 mLoopStart;  // offset: 0x18
        s32 mLoopEnd;  // offset: 0x1c
        u32 mReadType;  // offset: 0x20
        u32 mReadMode;  // offset: 0x24
        u32 mDTIID;  // offset: 0x28
        u32 mFormat;  // offset: 0x2c
        u32 mSourceIndex;  // offset: 0x30
        rSoundSource* mpSource;  // offset: 0x38
        rSoundStreamSourcePackage* mpStreamSourcePackage;  // offset: 0x40
    public:
        static const s32 MAX_RPATH = 64;
    };
public:
    struct StreamInfo
    {
    public:
        uintptr mPathOffset;  // offset: 0x0
        u32 mStreamLength;  // offset: 0x8
        u32 mSampleNum;  // offset: 0xc
        u32 mChannelNum;  // offset: 0x10
        u32 mSampleRate;  // offset: 0x14
        s32 mLoopStart;  // offset: 0x18
        s32 mLoopEnd;  // offset: 0x1c
        u32 mDTIID;  // offset: 0x20
        u32 mFormat;  // offset: 0x24
    };
public:
    struct ReadHeader
    {
    public:
        s32 Magic;  // offset: 0x0
        s32 Version;  // offset: 0x4
        u32 numStream;  // offset: 0x8
        u32 numElement;  // offset: 0xc
        u32 numSpeakerSet;  // offset: 0x10
        u32 numSpeaker;  // offset: 0x14
        u32 numDirectionalCurve;  // offset: 0x18
        u32 numDirectionalCurveElement;  // offset: 0x1c
        intptr StreamInfoOffset;  // offset: 0x20
        intptr ElementOffset;  // offset: 0x28
        intptr SpeakerSetOffset;  // offset: 0x30
        intptr SpeakerOffset;  // offset: 0x38
        intptr DirectionalCurveOffset;  // offset: 0x40
        intptr DirectionalCurveElementOffset;  // offset: 0x48
    };
public:
    struct WriteHeader
    {
    public:
        s32 Magic;  // offset: 0x0
        s32 Version;  // offset: 0x4
        u32 numStream;  // offset: 0x8
        u32 numElement;  // offset: 0xc
        u32 numSpeakerSet;  // offset: 0x10
        u32 numSpeaker;  // offset: 0x14
        u32 numDirectionalCurve;  // offset: 0x18
        u32 numDirectionalCurveElement;  // offset: 0x1c
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
    rSoundStreamRequest();
    virtual ~rSoundStreamRequest();
    void freeStreamingSource();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool loadEnd();  // vtable slot 10
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    Element* getElementByIndex(u32 index) const;
    Element* getElement(u32 reqNo) const;
    s32 getElementNum() const;
    u32 getLoadedSize() const;
protected:
    void freeMemory();
    s32 findSource(const MtTypedArray<rSoundSource>& array, const rSoundSource* pSrc);
private:
    bool createReqNoToIndexTbl();
protected:
    void* memAlloc(u32 size, u32 align);
    void memFree(void* p_addr);
protected:
    u8* mpRawData;  // offset: 0x70
    u32 mElementNum;  // offset: 0x78
    Element* mpElement;  // offset: 0x80
    MtTypedArray<rSoundSource> mSourceResourceList;  // offset: 0x88
    u8* mpWave;  // offset: 0xa8
    SoundSource* mpSoundSource;  // offset: 0xb0
    u32 mSourceNum;  // offset: 0xb8
    u32 mLoadedSize;  // offset: 0xbc
    void* mpSpeakerSets;  // offset: 0xc0
    void* mpSpeakers;  // offset: 0xc8
    void* mpDirectionalCurves;  // offset: 0xd0
    void* mpDirectionalCurveElements;  // offset: 0xd8
    u32 mSpeakerSetNum;  // offset: 0xe0
    u32 mSpeakerNum;  // offset: 0xe4
    u32 mDirectionalCurveNum;  // offset: 0xe8
    u32 mDirectionalCurveElementNum;  // offset: 0xec
    rSoundStreamSourcePackage* mpStreamSourcePackage;  // offset: 0xf0
private:
    u16* mpReqNoToIndexTbl;  // offset: 0xf8
    u16 mReqNoToIndexTblNum;  // offset: 0x100
public:
    static MyDTI DTI;
private:
    static const s32 NativeFileMagic = 1381061715;
    static const s32 NativeFileVersion = 2;
};
