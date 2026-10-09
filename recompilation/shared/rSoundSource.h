#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtFile.h"
#include "MtStream.h"
#include "MtSynchronize.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtFile;
class MtFileStream;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class rSoundSource;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rSoundSource : public cResource
{
public:
    enum Format
    {
        FORMAT_NONE = 0,
        FORAMT_PCM = 1,
        FORMAT_ADPCM = 2,
        FORMAT_UNKNOWN = 3,
    };
public:
    class MyDTI;
    struct Descriptor;
    struct FUNDAMENTAL_PERIOD;
    class SoundFile;
    struct TIMESTAMP;
    struct MARKER;
    struct STREAM_CONTEXT;
    struct RIFF_CHUNK;
    struct CHUNK_HEADER;
    struct FMT_CHUNK;
    struct SMPL_CHUNK;
    struct SAMPLELOOP;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Descriptor
    {
    public:
        u32 mChannels;  // offset: 0x0
        u32 mBits;  // offset: 0x4
        u32 mBitRate;  // offset: 0x8
        u32 mSampleRate;  // offset: 0xc
        f32 mDuration;  // offset: 0x10
        u32 mFormat;  // offset: 0x14
        u32 mStreamSize;  // offset: 0x18
        u32 mSamples;  // offset: 0x1c
        u32 mLoopStart;  // offset: 0x20
        u32 mLoopEnd;  // offset: 0x24
        u32 mWaveSize;  // offset: 0x28
        u32 mMarkerNum;  // offset: 0x2c
        u32 mPeriodNum;  // offset: 0x30
        rSoundSource::FUNDAMENTAL_PERIOD* mpPeriod;  // offset: 0x38
    };
public:
    struct FUNDAMENTAL_PERIOD
    {
    public:
        u32 samples;  // offset: 0x0
        u32 period;  // offset: 0x4
    };
public:
    class SoundFile : public MtFileStream
    {
    public:
        SoundFile();
        virtual ~SoundFile();
        bool openWithPath(MT_CTSTR path);
        static void* operator new(size_t size);
        static void operator delete(void* ptr);
    private:
        MtFile mFile;  // offset: 0x10
    };
public:
    struct TIMESTAMP
    {
    public:
        u16 Year;  // offset: 0x0
        u8 Month;  // offset: 0x2
        u8 Day;  // offset: 0x3
        u8 Hour;  // offset: 0x4
        u8 Minute;  // offset: 0x5
        u8 Second;  // offset: 0x6
        u8 padding;  // offset: 0x7
    };
public:
    struct MARKER
    {
    public:
        u8 ID;  // offset: 0x0
        u8 padding[3];  // offset: 0x1
        u32 sample;  // offset: 0x4
    };
public:
    struct STREAM_CONTEXT
    {
    public:
        void* mpBuffer;  // offset: 0x0
        u32 mBufferSize;  // offset: 0x8
        u32* mpIdentifier;  // offset: 0x10
        void* mpData;  // offset: 0x18
        u32 mCurrentSample;  // offset: 0x20
        u32 mProcessSampleNum;  // offset: 0x24
        u32 mChannelSize;  // offset: 0x28
        void* mpPreloadBuffer;  // offset: 0x30
        u32 mPreloadBufferSize;  // offset: 0x38
    };
public:
    struct RIFF_CHUNK
    {
    public:
        u32 tag;  // offset: 0x0
        u32 size;  // offset: 0x4
        u32 id;  // offset: 0x8
    };
public:
    struct CHUNK_HEADER
    {
    public:
        u32 tag;  // offset: 0x0
        u32 size;  // offset: 0x4
    };
public:
    struct FMT_CHUNK
    {
    public:
        u16 wFormatTag;  // offset: 0x0
        u16 nChannels;  // offset: 0x2
        u32 nSamplesPerSec;  // offset: 0x4
        u32 nAvgBytesPerSec;  // offset: 0x8
        u16 nBlockAlign;  // offset: 0xc
        u16 wBitsPerSample;  // offset: 0xe
        u16 cbSize;  // offset: 0x10
    };
public:
    struct SAMPLELOOP
    {
    public:
        u32 dwIdentifier;  // offset: 0x0
        u32 dwType;  // offset: 0x4
        u32 dwStart;  // offset: 0x8
        u32 dwEnd;  // offset: 0xc
        u32 dwFraction;  // offset: 0x10
        u32 dwPlayCount;  // offset: 0x14
    };
public:
    struct SMPL_CHUNK
    {
    public:
        u32 dwManufacturer;  // offset: 0x0
        u32 dwProduct;  // offset: 0x4
        u32 dwSamplePeriod;  // offset: 0x8
        u32 dwMIDIUnityNote;  // offset: 0xc
        u32 dwMIDIPitchFraction;  // offset: 0x10
        u32 dwSMPTEFormat;  // offset: 0x14
        u32 dwSMPTEOffset;  // offset: 0x18
        u32 cSampleLoops;  // offset: 0x1c
        u32 cbSmplerData;  // offset: 0x20
        rSoundSource::SAMPLELOOP Loops;  // offset: 0x24
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
    rSoundSource();
    virtual ~rSoundSource();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual void initIdentifier(u32* pid) const;  // vtable slot 16
    virtual bool prepareToBuffer();  // vtable slot 17
    bool open();
    bool close();
    u32 read(void* pdest, u32 size, u32* pid);
    void* read(u32 size, u32* pid);
    u32 seek(u32 pos, u32* pid);
    virtual void seekSampleStart(u32* pid);  // vtable slot 18
    virtual void seekLoopStart(u32* pid);  // vtable slot 19
    u32 getLength() const;
    u32 getSampleDataLength() const;
    void* getBuffer() const;
    MT_CTSTR getFilePath();
    const Descriptor& getDescriptor() const;
    void setDescriptor(const Descriptor&);
    u32 getPeriodNum() const;
    FUNDAMENTAL_PERIOD* getPeriod() const;
    u32 getSampleRate() const;
    virtual u32 getChannelNum() const;  // vtable slot 20
    u32 getSampleNum() const;
    bool isLoop() const;
    u32 getLoopStart() const;
    u32 getLoopEnd() const;
    u32 getFormat() const;
    u32 getMarkerNum() const;
    u32 getWaveSize() const;
    const TIMESTAMP getTimeStamp() const;
    void updateTimeStamp();
    virtual u32 getLoopStartPos() const;  // vtable slot 21
    virtual u32 getLoopEndPos() const;  // vtable slot 22
    virtual u32 getSampleStartPos() const;  // vtable slot 23
    bool isSelfAllocation();
    virtual bool createStreamingData(void*, u32) const;  // vtable slot 24
    // Address: 0x01bbc4a0 - 0x01bbc4a1 (1 bytes)
    virtual void destroyStreamingData(void*) const {}  // vtable slot 25
    virtual bool loadBuffer(STREAM_CONTEXT*);  // vtable slot 26
    virtual u32 getStreamingBufferSize() const;  // vtable slot 27
    void lock();
    void unlock();
    // Address: 0x01bbc4d0 - 0x01bbc4d1 (1 bytes)
    virtual void setupSource(void* pContext) {}  // vtable slot 28
    virtual bool getPlayBuffer(void* * ppBuffer, u32* pSize, void* pContext);  // vtable slot 29
    // Address: 0x01bbc4e0 - 0x01bbc4e1 (1 bytes)
    virtual void releaseSource(void* pContext) {}  // vtable slot 30
    virtual u32 getAppendedSample(void* pContext);  // vtable slot 31
    virtual u32 getPcmBytesFromSamples(u32 samples);  // vtable slot 32
    MARKER* getMarker();
    virtual u32 getMarkerStartPos(u32 markerSamplePos) const;  // vtable slot 33
    u16 getMarkerIndexFromID(u16 markerID) const;
    u16 getMarkerIndexFromSamplePos(u32 samplePos) const;
    u32 getSamplePosFromMarkerIndex(u16 markerIndex) const;
    u32 getMarkerSamplePosition(u16 markerID) const;
    virtual const MtDTI* getDTINative() const;  // vtable slot 34
    const MtDTI* getDTIChild() const;
    virtual bool checkNativeEncodeParameter(const u32 param) const;  // vtable slot 35
private:
    u16 getMarkerIndexAfterLoopStart(u16 lastIndex) const;
protected:
    void* memAlloc(u32 size, u32 align);
    void memFree(void* p_addr);
    bool setFileStream(MtFileStream& in);
    bool setBuffer(void* pbuf, u32 length);
    virtual bool init();  // vtable slot 36
    bool createMarkerToIndexTbl();
    void freeMarkerTbl();
protected:
    Descriptor mDescriptor;  // offset: 0x70
    u32 mFilePosition;  // offset: 0xb0
    void* mpBuffer;  // offset: 0xb8
    u32 mBufferLength;  // offset: 0xc0
    u32 mGlobalID;  // offset: 0xc4
    MtCriticalSection mCS;  // offset: 0xc8
    SoundFile* mpFile;  // offset: 0xd0
    s32 mOpenCtr;  // offset: 0xd8
    bool mSelfAllocation;  // offset: 0xdc
    TIMESTAMP mTimeStamp;  // offset: 0xde
    u32 mVersion;  // offset: 0xe8
    MtDTI mDTIChild;  // offset: 0xf0
    MARKER* mpMarker;  // offset: 0x128
    u16* mpMarkerIDToIndexTbl;  // offset: 0x130
    u16 mMarkerIDToIndexTblNum;  // offset: 0x138
public:
    static const u8 mMaxMarkerNumWithID = 128;
    static const u32 mMaxChannelNum = 6;
    static MyDTI DTI;
};
