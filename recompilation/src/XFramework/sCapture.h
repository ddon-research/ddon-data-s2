#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtString.h"
#include "cSystem.h"

// Forward declarations
struct MT_ENUM;
class MtAllocator;
class MtColor;
class MtDTI;
class MtFile;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSize;
class MtStream;
class MtString;
class MtUI;

// Declarations
class sCapture;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class sCapture : public cSystem
{
public:
    enum FORMAT
    {
        FMT_AVI = 0,
        FMT_BMP = 1,
        FMT_TGA = 2,
        FMT_WMV = 3,
        FMT_JPG = 4,
    };
    enum SCALE
    {
        SCALE_DEFAULT = 0,
        SCALE_REDUCTION2 = 1,
        SCALE_REDUCTION4 = 2,
        SCALE_EXPANSION2 = 3,
        SCALE_EXPANSION4 = 4,
        SCALE_EXPANSION8 = 5,
        SCALE_EXPANSION16 = 6,
    };
    enum ANTIALIASING
    {
        ANTIALIASING_NONE = 1,
        ANTIALIASING_4X = 4,
        ANTIALIASING_9X = 9,
        ANTIALIASING_16X = 16,
        ANTIALIASING_36X = 36,
        ANTIALIASING_64X = 64,
    };
    enum MOTIONBLUR
    {
        MOTIONBLUR_NONE = 1,
        MOTIONBLUR_8X = 8,
        MOTIONBLUR_16X = 16,
        MOTIONBLUR_32X = 32,
        MOTIONBLUR_64X = 64,
    };
    enum TARGET
    {
        TARGET_DESKTOP1 = 0,
        TARGET_DESKTOP2 = 1,
        TARGET_DESKTOP3 = 2,
        TARGET_DESKTOP4 = 3,
        TARGET_DEFAULT = 4,
    };
    enum CODEC
    {
        CODEC_RGB24 = 0,
        CODEC_IYUV = 1,
        CODEC_WMV9 = 2,
        CODEC_VC1 = 3,
    };
    enum ALPHA_TYPE
    {
        ALPHA_NONE = 0,
        ALPHA_BLEND = 1,
        ALPHA_COMPOSITE = 2,
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
    sCapture();
    virtual ~sCapture();
    virtual void move();  // vtable slot 7
    static sCapture* getInstance();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void createPropertyDesc(MtPropertyList& s);
    void start(u32 frame);
    void setFileName(MT_CTSTR);
    void setFolderPath(MT_CTSTR dir);
    void setCaptureDesc(FORMAT fmt, SCALE scale, ANTIALIASING aa, MOTIONBLUR mb, TARGET tgt);
    void setVideoFormat(CODEC codec, u32 quality, bool compression);
    void setJpegEncoderQuality(u32 quality);
    void setCurrentFrame(u32 frame);
    void setOverWrite(bool);
    void setBGColor(MtColor);
    void setFilePath(const MtString& path);
    MT_CTSTR getFilePath() const;
    u32 getCurrentFrame() const;
    bool isCapture() const;
    bool isCaptureEnd() const;
    void setKeepStartSetting(bool);
    bool isKeepStartSetting() const;
    u32 getFormat() const;
    const MT_ENUM* getScalingList();
    void setAlphaType(u32 type);
    void setUseTempFile(bool);
    bool isUseTempFile() const;
protected:
    void startCap();
    void getOutputPath(MT_STR path);
    bool startAVI();
    void endAVI();
    bool startWMV();
    void endWMV();
    bool startJPG();
    void endJPG();
    void output();
    void outputBMP(MtStream& in, s32 w, s32 h, s32 ct);
    void outputAVI(MtStream& in, s32 w, s32 h, s32 ct);
    void outputWMV(MtStream& in, s32 w, s32 h, s32 ct);
    void outputTGA(MtStream& in, s32 w, s32 h, s32 ct);
    void outputJPG(MtStream& in, s32 w, s32 h, s32 ct);
    void accumulation(void* pbuf, u32 pitch, u32 format);
    bool begin();
    bool end();
    void setPause(bool f);
    u32 getAlphaType();
    bool isAVIDisable();
    bool isVideoDisable();
    bool isVideoEnable() const;
    bool isMotionBlurDisable();
protected:
    MtString mFilePath;  // offset: 0x18
    MtString mFileName;  // offset: 0x20
    u32 mAlpha;  // offset: 0x28
    u32 mFormat;  // offset: 0x2c
    f32 mFps;  // offset: 0x30
    u32 mScaling;  // offset: 0x34
    u32 mAntiAliasing;  // offset: 0x38
    u32 mMotionBlur;  // offset: 0x3c
    f32 mViewBlurPower;  // offset: 0x40
    f32 mWorldBlurPower;  // offset: 0x44
    MtColor mBGColor;  // offset: 0x48
    MtColor mMemBGColor;  // offset: 0x4c
    s32 mCaptureFrame;  // offset: 0x50
    s32 mCurrentFrame;  // offset: 0x54
    s32 mSubFrameNum;  // offset: 0x58
    bool mUseTempFile;  // offset: 0x5c
    bool mCapture;  // offset: 0x5d
    bool mFrameWait;  // offset: 0x5e
    bool mFramePause;  // offset: 0x5f
    f32 mMipLODBias;  // offset: 0x60
    bool mFileOverWrite;  // offset: 0x64
    u32 mDesktopNo;  // offset: 0x68
    u32 mTarget;  // offset: 0x6c
    MtColor mClearColor[8];  // offset: 0x70
    u32 mIndex;  // offset: 0x90
    u32 mSubIndex;  // offset: 0x94
    MtSize mSrcSize;  // offset: 0x98
    MtSize mDstSize;  // offset: 0xa0
    u16* mpTempBuf;  // offset: 0xa8
    u16* mpAccBuf;  // offset: 0xb0
    MtFile* mpFile;  // offset: 0xb8
    MtStream* mpAccStream;  // offset: 0xc0
    u32* mpScanLine;  // offset: 0xc8
    bool mKeepStartSetting;  // offset: 0xd0
public:
    static MyDTI DTI;
protected:
    static sCapture* mpInstance;
};

inline void* sCapture::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void sCapture::setCurrentFrame(u32 frame) {
    this->mCurrentFrame = static_cast<s32>(frame * this->mSubFrameNum);
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void sCapture::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sCapture::DTI)->memFree(p_addr);
}
