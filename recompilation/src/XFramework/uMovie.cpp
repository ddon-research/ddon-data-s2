// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_kernel.h>
#include <string.h>
#include "uMovie.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtFile.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cResource.h"
#include "cUnit.h"
#include "nDrawBuffer.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "rMovie.h"
#include "rRenderTargetTexture.h"
#include "sRender.h"
#include "sResource.h"
#include "sSound.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uMovie::usage() {
}

const MtDTI& uMovie::getDTI() const {
    return uMovie::DTI;
}

uMovie::uMovie() {
    mDrawMode = 1;
    mStatus = EMPTY;
    mSoundThread = nullptr;
    mpMovieTexture = nullptr;
    mpNextMovie = nullptr;
    mpMovie = nullptr;
    mPlayer = nullptr;
    mDrawFrame = 0xFFFFFFFF;
    mMovieSize.w = static_cast<s32>(static_cast<unsigned int>(MtSize::Zero.wh));
    mMovieSize.h = static_cast<s32>(MtSize::Zero.wh >> 32);
    mIsPlayable = false;
    mIsLoop = false;
    mIsVideoBufferingOver = false;
    mMovieDuration = 0;
    mClear = true;
    mAudioChannels = 0;
    mAudioSampleRate = 0;
    memset(static_cast<void*>(&mDrawIndex), 0, 338ul);
    mVolume = 127;
    mCategory = 1;
    mAudioRestricted = false;
    mPresentMode = 0;
    memset(static_cast<void*>(&mMoviePlayTime), 0, 193ul);
}

__attribute__((noinline)) uMovie::~uMovie() {
    DDON_STUB("uMovie::~uMovie")
    /* stub */
}

__attribute__((weak)) void uMovie::move() {
    DDON_STUB("uMovie::move")
    /* stub */
}

__attribute__((weak)) void uMovie::draw(cDraw* pdraw) {
    DDON_STUB("uMovie::draw")
    /* stub */
}

void uMovie::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mDrawIndex", &mDrawIndex, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDecodeIndex", &mDecodeIndex, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPresentMode", &mPresentMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsLoop", &mIsLoop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAudioEnable", &mAudioEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAudioRestricted", &mAudioRestricted, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsHaveAudioStream", &mIsHaveAudioStream, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mClear", &mClear, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Movie", "resource", reinterpret_cast<MT_MFUNC>(&::uMovie::getMovie), reinterpret_cast<MT_MFUNC>(&::uMovie::setMovie), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpRenderTarget", "resource", reinterpret_cast<MT_MFUNC>(&::uMovie::getRenderTarget), reinterpret_cast<MT_MFUNC>(&::uMovie::setRenderTarget), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mMovieSize.w", &mMovieSize.w, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMovieSize.h", &mMovieSize.h, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAudioChannels", &mAudioChannels, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAudioSampleRate", &mAudioSampleRate, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDrawFrame", &mDrawFrame, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMovieDuration", &mMovieDuration, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Play", static_cast<MT_MFUNC>(&::uMovie::play), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Pause", static_cast<MT_MFUNC>(&::uMovie::pause), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Stop", static_cast<MT_MFUNC>(&::uMovie::stop), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "ShutDown", static_cast<MT_MFUNC>(&::uMovie::shutdown), 10u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Volume", reinterpret_cast<MT_MFUNC>(&::uMovie::getVolume), reinterpret_cast<MT_MFUNC>(&::uMovie::setVolume), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Category", reinterpret_cast<MT_MFUNC>(&::uMovie::getCategory), reinterpret_cast<MT_MFUNC>(&::uMovie::setCategory), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mStatus", reinterpret_cast<MT_MFUNC>(&::uMovie::getStatus), reinterpret_cast<MT_MFUNC>(&::uMovie::setStatus), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mIsDebug", &mIsDebug, 0u, 0u);
}

MtUI* uMovie::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

__attribute__((weak)) void uMovie::play() {
    DDON_STUB("uMovie::play")
    /* stub */
}

__attribute__((weak)) void uMovie::pause() {
    DDON_STUB("uMovie::pause")
    /* stub */
}

void uMovie::stop() {
    mStatus = STOPPED;
}

void uMovie::shutdown() {
    mStatus = TERMINATING;
}

static auto ddon_emit_0x01b63930 __attribute__((used)) = &uMovie::getStatus;

static auto ddon_emit_0x01b638c0 __attribute__((used)) = &uMovie::setStatus;

static auto ddon_emit_0x01b63910 __attribute__((used)) = &uMovie::getCategory;

static auto ddon_emit_0x01b63920 __attribute__((used)) = &uMovie::setCategory;

static auto ddon_emit_0x01b638f0 __attribute__((used)) = &uMovie::getVolume;

static auto ddon_emit_0x01b63900 __attribute__((used)) = &uMovie::setVolume;

void uMovie::setMovie(rMovie* pmovie) {
    if (mStatus != EMPTY) {
        return;
    }
    if (mpNextMovie != nullptr) {
        mpNextMovie->release();
        mpNextMovie = nullptr;
    }
    if (pmovie != nullptr) {
        mpNextMovie = pmovie;
        pmovie->addRef();
    }
    mStatus = INITIALIZING;
}

static auto ddon_emit_0x01b638d0 __attribute__((used)) = &uMovie::getMovie;

void uMovie::setRenderTarget(rRenderTargetTexture* prt) {
    if (mpMovieTexture != nullptr) {
        mpMovieTexture->release();
        mpMovieTexture = nullptr;
    }
    if (prt == nullptr) {
        return;
    }
    mpMovieTexture = prt;
    prt->addRef();
}

static auto ddon_emit_0x01b638e0 __attribute__((used)) = &uMovie::getRenderTarget;

__attribute__((weak)) void uMovie::initialize() {
    DDON_STUB("uMovie::initialize")
    /* stub */
}

__attribute__((weak)) void uMovie::videoBuffering() {
    DDON_STUB("uMovie::videoBuffering")
    /* stub */
}

__attribute__((weak)) void uMovie::playing() {
    DDON_STUB("uMovie::playing")
    /* stub */
}

__attribute__((weak)) void uMovie::terminating() {
    DDON_STUB("uMovie::terminating")
    /* stub */
}

__attribute__((weak)) void uMovie::createDecodeTexture() {
    DDON_STUB("uMovie::createDecodeTexture")
    /* stub */
}

__attribute__((weak)) void uMovie::setDecodeTexture(const int index, SceAvPlayerFrameInfoEx& sceAvplayerData) {
    DDON_STUB("uMovie::setDecodeTexture")
    /* stub */
}

void* uMovie::allocate(void* parg, u32 alignment, u32 size) {
    return MtMemoryAllocator::getAllocator(cResource::DTI)->memAlloc(size, alignment);
}

void uMovie::deallocate(void* parg, void* memPtr) {
    MtMemoryAllocator::getAllocator(cResource::DTI)->memFree(memPtr);
}

void* uMovie::allocateTexture(void* parg, u32 alignment, u32 size) {
    return MtMemory::mpAllocatorType[5]->memAlloc(size, alignment);
}

void uMovie::deallocateTexture(void* parg, void* memPtr) {
    MtMemory::mpAllocatorType[5]->memFree(memPtr);
}

__attribute__((weak)) void uMovie::eventCallback(void* parg, int32_t argEventId, int32_t argSourceId, void* argEventData) {
    DDON_STUB("uMovie::eventCallback")
    /* stub */
}

int uMovie::openFile(void* parg, const char* argFilename) {
    return 1;
}

int uMovie::closeFile(void* parg) {
    return 1;
}

__attribute__((weak)) int uMovie::readOffsetFile(void* parg, u8* argBuffer, u64 argPosition, u32 argLength) {
    DDON_STUB("uMovie::readOffsetFile")
    return {};
}

__attribute__((weak)) u64 uMovie::sizeFile(void* parg) {
    DDON_STUB("uMovie::sizeFile")
    return {};
}

inline uMovie::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uMovie::MyDTI uMovie::DTI("uMovie", &::cUnit::DTI, 712ul, 0u, 0u);

MtObject* uMovie::MyDTI::newInstance() const {
    return new (16u) uMovie;
}

uMovie::soundDecode::~soundDecode() {
}

__attribute__((weak)) void uMovie::soundDecode::createTread() {
    DDON_STUB("uMovie::soundDecode::createTread")
    /* stub */
}

__attribute__((weak)) void* uMovie::soundDecode::threadEntry(void* pArg) {
    DDON_STUB("uMovie::soundDecode::threadEntry")
    return nullptr;
}

void uMovie::soundDecode::threadExecute() {
    mSoundLatestFrameTimeStamp = 0;
    mVideoLatestFrameTimeStamp = 0;
    STATE v1_0;
    for (;;) {
        v1_0 = mState;
        for (;;) {
            switch (static_cast<unsigned int>(v1_0 - 1)) {
                case 0:
                {
                    if ((sSound::mpInstance)->sSound::isAvailableWriteExternalVoice(mSoundID, 8u)) {
                        getAvPlayerSoundData();
                        goto loop_f5754a_next;
                    } else {
                        mState = PLAYABLE;
                        v1_0 = PLAYABLE;
                    }
                    break;
                }
                case 1:
                {
                    sceKernelUsleep(16000u);
                    goto loop_f5754a_next;
                }
                case 2:
                {
                    goto loop_f57560_end;
                }
                case 3:
                {
                    return;
                }
                default:
                {
                    break;
                }
            }
        }
        loop_f57560_end:;
        if ((sSound::mpInstance)->sSound::isAvailableWriteExternalVoice(mSoundID, 8u)) {
            getAvPlayerSoundData();
        } else {
            sceKernelUsleep(16000u);
        }
        loop_f5754a_next:;
    }
}

__attribute__((weak)) void uMovie::soundDecode::getAvPlayerSoundData() {
    DDON_STUB("uMovie::soundDecode::getAvPlayerSoundData")
    /* stub */
}

