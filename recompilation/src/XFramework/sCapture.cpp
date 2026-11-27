// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sCapture.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtFile.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtRandom.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cSystem.h"
#include "nDrawTexture.h"
#include "sCamera.h"
#include "sMain.h"
#include "sRender.h"
#include "sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sCapture::getDTI() const {
    return sCapture::DTI;
}

void* sCapture::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sCapture::DTI)->memAlloc(sz, align, sCapture::DTI.mID);
}

sCapture::sCapture() {
    DDON_STUB("sCapture::sCapture")
    /* stub */
}

__attribute__((noinline)) sCapture::~sCapture() {
    DDON_STUB("sCapture::~sCapture")
    /* stub */
}

__attribute__((weak)) void sCapture::move() {
    DDON_STUB("sCapture::move")
    /* stub */
}

MtUI* sCapture::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sCapture::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mFilePath", reinterpret_cast<MT_MFUNC>(&::sCapture::getFilePath), reinterpret_cast<MT_MFUNC>(&::sCapture::setFilePath), 384u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mFileName", &mFileName, 256u, 0u);
    createPropertyDesc(s);
    s << MtProperty(static_cast<MtObject*>(this), "mBGColor", &mBGColor, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mCurrentFrame", reinterpret_cast<MT_MFUNC>(&::sCapture::getCurrentFrame), reinterpret_cast<MT_MFUNC>(&::sCapture::setCurrentFrame), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mCaptureFrame", &mCaptureFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Start Capture", static_cast<MT_MFUNC>(&::sCapture::startCap), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "mFileOverWrite", &mFileOverWrite, 0u, 0u);
}

__attribute__((weak)) void sCapture::createPropertyDesc(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mTarget", &mTarget, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFormat", &mFormat, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScaling", &mScaling, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAntiAliasing", &mAntiAliasing, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mAlpha", reinterpret_cast<MT_MFUNC>(&::sCapture::getAlphaType), reinterpret_cast<MT_MFUNC>(&::sCapture::setAlphaType), 384u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mMotionBlur", &mMotionBlur, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mViewBlurPower", &mViewBlurPower, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWorldBlurPower", &mWorldBlurPower, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFps", &mFps, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseTempFile", &mUseTempFile, 256u, 0u);
}

__attribute__((weak)) void sCapture::setFolderPath(MT_CTSTR dir) {
    DDON_STUB("sCapture::setFolderPath")
    /* stub */
}

static auto ddon_emit_0x01b9e9f0 __attribute__((used)) = &sCapture::setCurrentFrame;

__attribute__((weak)) void sCapture::setFilePath(const MtString& path) {
    DDON_STUB("sCapture::setFilePath")
    /* stub */
}

__attribute__((weak)) MT_CTSTR sCapture::getFilePath() const {
    DDON_STUB("sCapture::getFilePath")
    return {};
}

__attribute__((weak)) u32 sCapture::getCurrentFrame() const {
    DDON_STUB("sCapture::getCurrentFrame")
    return {};
}

void sCapture::setAlphaType(u32 type) {
    mAlpha = type;
    if (type != 0) {
        if (((sRender::mpInstance)->mSceneAttribute & 2048u) == 0) {
            (sRender::mpInstance)->sRender::setSceneAttribute((sRender::mpInstance)->mSceneAttribute | 2048u);
        }
    } else {
        if (((sRender::mpInstance)->mSceneAttribute & 2048u) != 0) {
            (sRender::mpInstance)->sRender::setSceneAttribute((sRender::mpInstance)->mSceneAttribute & 0xFFFFF7FFu);
        }
    }
}

void sCapture::startCap() {
    if (!begin()) {
        end();
    }
}

__attribute__((weak)) void sCapture::getOutputPath(MT_STR path) {
    DDON_STUB("sCapture::getOutputPath")
    /* stub */
}

__attribute__((weak)) void sCapture::outputBMP(MtStream& in, s32 w, s32 h, s32 ct) {
    DDON_STUB("sCapture::outputBMP")
    /* stub */
}

__attribute__((weak)) void sCapture::outputTGA(MtStream& in, s32 w, s32 h, s32 ct) {
    DDON_STUB("sCapture::outputTGA")
    /* stub */
}

__attribute__((weak)) void sCapture::accumulation(void* pbuf, u32 pitch, u32 format) {
    DDON_STUB("sCapture::accumulation")
    /* stub */
}

__attribute__((weak)) bool sCapture::begin() {
    DDON_STUB("sCapture::begin")
    return {};
}

__attribute__((weak)) bool sCapture::end() {
    DDON_STUB("sCapture::end")
    return {};
}

u32 sCapture::getAlphaType() {
    return mAlpha;
}

inline sCapture::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCapture::MyDTI sCapture::DTI("sCapture", &::cSystem::DTI, 216ul, 0u, 0u);

sCapture* sCapture::mpInstance;

__attribute__((weak)) MtObject* sCapture::MyDTI::newInstance() const {
    DDON_STUB("sCapture::MyDTI::newInstance")
    return nullptr;
}

