#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtPrimitive2D.h"
#include "cUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSize;
class MtUI;
struct SceAvPlayerFrameInfoEx;
class cDraw;
namespace nDraw { class Texture; }
struct pthread;
class rMovie;
class rRenderTargetTexture;

// Declarations
class uMovie;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SceAvPlayerHandle = void*;
using pthread_t = pthread*;
using ScePthread = pthread_t;
using _Sizet = long unsigned int;
using __int32_t = int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using int32_t = __int32_t;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class uMovie : public cUnit
{
public:
    enum STATUS
    {
        EMPTY = 0,
        INITIALIZING = 1,
        INITIALIZED = 2,
        BUFFERING = 3,
        IDLE = 4,
        PLAYING = 5,
        PAUSED = 6,
        RESUME = 7,
        STOPPED = 8,
        TERMINATING = 9,
        TERMINATED = 10,
    };
    enum PRESENTATION_MODE
    {
        FRAME_BASE = 0,
        TIME_BASE = 1,
    };
public:
    class MyDTI;
    class soundDecode;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class soundDecode
    {
    public:
        enum STATE
        {
            NONE = 0,
            BUFFERING = 1,
            PLAYABLE = 2,
            PLAYING = 3,
            END = 4,
        };
    public:
        soundDecode(SceAvPlayerHandle handle, const uintptr soundID);
        virtual ~soundDecode();
        void createTread();
        static void* threadEntry(void* pArg);
        void threadExecute();
        void setState(const u32 state);
        u32 getState();
        void setVideoFrameTime(const u32 time);
        void resetSoundFrameTime();
        bool joinThread();
    private:
        void getAvPlayerSoundData();
    private:
        SceAvPlayerHandle mPlayer;  // offset: 0x8
        ScePthread mThread;  // offset: 0x10
        uintptr mSoundID;  // offset: 0x18
        STATE mState;  // offset: 0x20
        t64 mVideoLatestFrameTimeStamp;  // offset: 0x28
        t64 mSoundLatestFrameTimeStamp;  // offset: 0x30
        static const u32 SLEEP_TIME = 16;
        static const u32 DECODE_SYNC_BUFFERTIME = 165;
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
    uMovie();
    virtual ~uMovie();
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void play();
    void pause();
    void stop();
    void shutdown();
    bool isPlayable() const;
    u32 getDrawFrame() const;
    STATUS getStatus() const;
    void setStatus(STATUS status);
    bool getLoop() const;
    void setLoop(bool b);
    bool getClear() const;
    void setClear(bool);
    bool getAudioEnable() const;
    void setAudioEnable(bool b);
    bool isHaveAudioStream();
    void setHaveAudioStream();
    u32 getCategory() const;
    void setCategory(u32 category);
    u32 getVolume() const;
    void setVolume(u32 vol);
    void setAudioRestricted(bool);
    u32 getMovieDuration() const;
    void setMovieDuration(const u32 movieLength);
    u32 getPresentationMode() const;
    void setPresentationMode(u32);
    void setMovie(rMovie* pmovie);
    rMovie* getMovie();
    void setRenderTarget(rRenderTargetTexture* prt);
    rRenderTargetTexture* getRenderTarget() const;
    void setupSound(const u32 channels, const u32 sampleRate);
    void setupVideo(const u32 videoHeight, const u32 videoWidth);
    void startSoundBuffering();
    SceAvPlayerHandle getPlayerHandle();
private:
    bool isCanDecode();
    void initialize();
    void buffering();
    void videoBuffering();
    void idle();
    void playing();
    void getAvPlayerVideoData();
    void updateDrawIndex();
    void updateNextDrawIndex();
    void paused();
    void resume();
    void terminating();
    void terminated();
    void createDecodeTexture();
    void releaseDecodeTexture();
    void setDecodeTexture(const int index, SceAvPlayerFrameInfoEx& sceAvplayerData);
    void allocDecodeTextureMemory(MtSize videoSize);
    void freeDecodeTextureMemory();
    t64 getCurrentMsTime();
    void updatePlayTime();
    void loopReset();
    u32 getPrevIndex(const int nowIndex);
    u32 getNextIndex(const int nowIndex);
    static void* allocate(void* parg, u32 alignment, u32 size);
    static void deallocate(void* parg, void* memPtr);
    static void* allocateTexture(void* parg, u32 alignment, u32 size);
    static void deallocateTexture(void* parg, void* memPtr);
    static void eventCallback(void* parg, int32_t argEventId, int32_t argSourceId, void* argEventData);
    static int openFile(void* parg, const char* argFilename);
    static int closeFile(void* parg);
    static int readOffsetFile(void* parg, u8* argBuffer, u64 argPosition, u32 argLength);
    static u64 sizeFile(void* parg);
private:
    STATUS mStatus;  // offset: 0x48
    SceAvPlayerHandle mPlayer;  // offset: 0x50
    rMovie* mpMovie;  // offset: 0x58
    rMovie* mpNextMovie;  // offset: 0x60
    rRenderTargetTexture* mpMovieTexture;  // offset: 0x68
    u32 mDrawFrame;  // offset: 0x70
    MtSize mMovieSize;  // offset: 0x78
    u32 mMovieDuration;  // offset: 0x80
    bool mIsLoop;  // offset: 0x84
    bool mIsVideoBufferingOver;  // offset: 0x85
    bool mIsPlayable;  // offset: 0x86
    bool mClear;  // offset: 0x87
    u32 mDrawIndex;  // offset: 0x88
    u32 mDecodeIndex;  // offset: 0x8c
    u8* mDecodeVideoMemoryPtr;  // offset: 0x90
    nDraw::Texture* mDecodeTextureLuma[20];  // offset: 0x98
    nDraw::Texture* mDecodeTextureChroma[20];  // offset: 0x138
    bool mIsHaveAudioStream;  // offset: 0x1d8
    bool mAudioEnable;  // offset: 0x1d9
    u32 mAudioChannels;  // offset: 0x1dc
    u32 mAudioSampleRate;  // offset: 0x1e0
    u32 mVolume;  // offset: 0x1e4
    u32 mCategory;  // offset: 0x1e8
    bool mAudioRestricted;  // offset: 0x1ec
    soundDecode* mSoundThread;  // offset: 0x1f0
    u32 mPresentMode;  // offset: 0x1f8
    t64 mMoviePlayTime;  // offset: 0x200
    t64 mMovieStartTime;  // offset: 0x208
    t64 mMoviePausedTime;  // offset: 0x210
    u64 mMovieTimeStamp[20];  // offset: 0x218
    t64 mKeepPreviousFrameTime;  // offset: 0x2b8
    bool mIsDebug;  // offset: 0x2c0
public:
    static MyDTI DTI;
private:
    static const u32 MAXNUM_BUFFER_TEXTURE = 20;
    static const u32 MOVIE_FRAME_INTERVAL = 33;
};

inline void* uMovie::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uMovie::STATUS uMovie::getStatus() const {
    return this->mStatus;
}

inline void uMovie::setStatus(uMovie::STATUS status) {
    this->mStatus = status;
}

inline u32 uMovie::getCategory() const {
    return this->mCategory;
}

inline void uMovie::setCategory(u32 category) {
    this->mCategory = category;
}

inline u32 uMovie::getVolume() const {
    return this->mVolume;
}

inline void uMovie::setVolume(u32 vol) {
    this->mVolume = vol;
}

inline rMovie* uMovie::getMovie() {
    return this->mpMovie;
}

inline rRenderTargetTexture* uMovie::getRenderTarget() const {
    return this->mpMovieTexture;
}
