// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rGUIFont.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "cResource.h"
#include "nDrawTexture.h"
#include "rTexture.h"
#include "sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rGUIFont::getDTI() const {
    return rGUIFont::DTI;
}

inline void* rGUIFont::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rGUIFont::DTI)->memAlloc(sz, align, rGUIFont::DTI.getID());
}

inline void rGUIFont::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGUIFont::DTI)->memFree(p_addr);
}

rGUIFont::~rGUIFont() {
    this->rGUIFont::clear();
}

__attribute__((weak)) bool rGUIFont::load(MtStream& in) {
    clear();
    MtDataReader r(in, 4096u);
    if (r.readU32() != 0x444647u) {
        return false;
    }
    mVersion = r.readU32();
    if (mVersion != VERSION) {
        return false;
    }
    mAttr = r.readU32();
    mSuffix = r.readU32();
    mFontType = r.readU32();
    mFontSize = r.readU32();
    mTextureNum = r.readU32();
    mCharNum = r.readU32();
    mDescentNum = r.readU32();
    mMaxAscent = r.readF32();
    mMaxDescent = r.readF32();
    mpDescent = static_cast<f32*>(memAlloc(mDescentNum * 4u));
    r.read(mpDescent, mDescentNum * 4u);
    u32 length = r.readU32();
    mpTexturePath = static_cast<MT_CTSTR>(memAlloc(length + 1u));
    r.readString(const_cast<MT_STR>(mpTexturePath), length + 1u);
    mpChar = static_cast<CHAR*>(memAlloc(mCharNum * sizeof(CHAR)));
    r.read(mpChar, mCharNum * sizeof(CHAR));
    if (isDynamic()) {
        mDynamicTextureNum = r.readU32();
        mDynamicTextureSize = r.readU32();
        mDynamicTextureFormat = static_cast<nDraw::FORMAT_TYPE>(r.readU32());
        mDynamicTextureMisc = r.readU32();
        mpSourceChar = static_cast<SRC_CHAR*>(memAlloc(mCharNum * sizeof(SRC_CHAR)));
        r.read(mpSourceChar, mCharNum * sizeof(SRC_CHAR));
        mpDynamicTexture = static_cast<nDraw::Texture**>(memAlloc(mDynamicTextureNum * sizeof(nDraw::Texture*)));
        MtSize size = getTextureWH(mDynamicTextureSize);
        for (u32 i = 0; i < mDynamicTextureNum; ++i) {
            mpDynamicTexture[i] = new (16u) nDraw::Texture(
                size.w, size.h, 1u, 1u, mDynamicTextureFormat, nDraw::USAGE_DYNAMIC,
                mDynamicTextureMisc, nullptr, 0u, nullptr, nDraw::TEXMEMORY_VRAM);
        }
        MtSize blockSize = getTextureBlockSize(mDynamicTextureFormat);
        mDynamicCharTW = 0;
        mDynamicCharTH = static_cast<u32>(getMaxHeight() + 1.0f);
        for (u32 i = 0; i < mCharNum; ++i) {
            u32 width = (mpChar[i].tw + blockSize.w - 1) & ~(blockSize.w - 1);
            mDynamicCharTW = (mDynamicCharTW < width) ? width : mDynamicCharTW;
            u32 height = (mpChar[i].th + blockSize.h - 1) & ~(blockSize.h - 1);
            mDynamicCharTH = (mDynamicCharTH < height) ? height : mDynamicCharTH;
            mpSourceChar[i].index = i;
            mpSourceChar[i].layoutNext = SRC_CHAR::INVALID_INDEX;
            mpSourceChar[i].requestNext = SRC_CHAR::INVALID_INDEX;
        }
        mDynamicLineNum = size.h / mDynamicCharTH;
        mpLayoutCharList = static_cast<SRC_CHAR**>(memAlloc(mDynamicTextureNum * mDynamicLineNum * sizeof(SRC_CHAR*)));
        for (u32 i = 0; i < mDynamicTextureNum * mDynamicLineNum; ++i) {
            mpLayoutCharList[i] = nullptr;
        }
        mpRequestLayoutCharList = static_cast<SRC_CHAR**>(memAlloc(mTextureNum * sizeof(SRC_CHAR*)));
        if (mpRequestLayoutCharList == nullptr) {
            clear();
            return false;
        }
    } else {
        mpTexture = static_cast<rTexture**>(memAlloc(mTextureNum * sizeof(rTexture*)));
        if (mpTexture == nullptr) {
            mTextureNum = 0;
            clear();
            return false;
        }
        for (u32 i = 0; i < mTextureNum; ++i) {
            mpTexture[i] = nullptr;
        }
        for (u32 i = 0; i < mTextureNum; ++i) {
            MtString path;
            path.format("%s_%02d%s", mpTexturePath, i, getSuffixString(mSuffix));
            mpTexture[i] = static_cast<rTexture*>(sResource::getInstance()->create(rTexture::DTI, path.ptr(), sResource::MODE_BLOCKING));
            if (mpTexture[i] == nullptr) {
                clear();
                return false;
            }
        }
    }
    return true;
}

bool rGUIFont::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    w.MtDataWriter::writeU32(0x444647u);
    w.MtDataWriter::writeU32(mVersion);
    w.MtDataWriter::writeU32(mAttr);
    w.MtDataWriter::writeU32(mSuffix);
    w.MtDataWriter::writeU32(mFontType);
    w.MtDataWriter::writeU32(mFontSize);
    w.MtDataWriter::writeU32(mTextureNum);
    w.MtDataWriter::writeU32(mCharNum);
    w.MtDataWriter::writeU32(mDescentNum);
    w.MtDataWriter::writeF32(mMaxAscent);
    w.MtDataWriter::writeF32(mMaxDescent);
    w.MtDataWriter::write(static_cast<const void*>(mpDescent), mDescentNum * 4u);
    w.MtDataWriter::writeU32(static_cast<unsigned int>(strlen(mpTexturePath)));
    w.writeString(mpTexturePath);
    w.MtDataWriter::write(static_cast<const void*>(mpChar), mCharNum * 16u);
    if ((mAttr & 1u) != 0) {
        w.MtDataWriter::writeU32(mDynamicTextureNum);
        w.MtDataWriter::writeU32(mDynamicTextureSize);
        w.MtDataWriter::writeU32(static_cast<u32>(mDynamicTextureFormat));
        w.MtDataWriter::writeU32(mDynamicTextureMisc);
        w.MtDataWriter::write(static_cast<const void*>(mpSourceChar), mCharNum * 12u);
    }
    return true;
}

__attribute__((weak)) void rGUIFont::clear() {
    cResource::clear();
    if (mpChar != nullptr) {
        memFree(mpChar);
        mpChar = nullptr;
    }
    memFree(const_cast<MT_STR>(mpTexturePath));
    mpTexturePath = nullptr;
    if (mpTexture != nullptr) {
        for (u32 i = 0; i < mTextureNum; ++i) {
            if (mpTexture[i] != nullptr) {
                mpTexture[i]->release();
                mpTexture[i] = nullptr;
            }
        }
        if (mpTexture != nullptr) {
            memFree(mpTexture);
            mpTexture = nullptr;
        }
    }
    mTextureNum = 0;
    mCharNum = 0;
    memFree(mpDescent);
    mpDescent = nullptr;
    if (mpDynamicTexture != nullptr) {
        for (u32 i = 0; i < mDynamicTextureNum; ++i) {
            if (mpDynamicTexture[i] != nullptr) {
                mpDynamicTexture[i]->release();
                mpDynamicTexture[i] = nullptr;
            }
        }
        if (mpDynamicTexture != nullptr) {
            memFree(mpDynamicTexture);
            mpDynamicTexture = nullptr;
        }
        if (mpLayoutCharList != nullptr) {
            memFree(mpLayoutCharList);
            mpLayoutCharList = nullptr;
        }
        if (mpRequestLayoutCharList != nullptr) {
            memFree(mpRequestLayoutCharList);
            mpRequestLayoutCharList = nullptr;
        }
    }
    if (mpSourceChar != nullptr) {
        memFree(mpSourceChar);
        mpSourceChar = nullptr;
    }
    mDynamicTextureNum = 1;
}

MtUI* rGUIFont::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

void rGUIFont::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "isDynamic", reinterpret_cast<MT_MFUNC>(&::rGUIFont::isDynamic), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setDynamic), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "LayoutEvenIntervals", reinterpret_cast<MT_MFUNC>(&::rGUIFont::isLayoutEvenIntervals), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setLayoutEvenIntervals), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Suffix", reinterpret_cast<MT_MFUNC>(&::rGUIFont::getSuffix), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setSuffix), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "FontType", reinterpret_cast<MT_MFUNC>(&::rGUIFont::getFontType), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setFontType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "FontSize", reinterpret_cast<MT_MFUNC>(&::rGUIFont::getFontSize), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setFontSize), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "TextureNum", reinterpret_cast<MT_MFUNC>(&::rGUIFont::getTextureNum), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setTextureNum), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MaxAscent", reinterpret_cast<MT_MFUNC>(&::rGUIFont::getMaxAscent), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setMaxAscent), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MaxDescent", reinterpret_cast<MT_MFUNC>(&::rGUIFont::getMaxDescent), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setMaxDescent), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "DynamicTextureNum", reinterpret_cast<MT_MFUNC>(&::rGUIFont::getDynamicTextureNum), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setDynamicTextureNum), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "DynamicTextureSize", reinterpret_cast<MT_MFUNC>(&::rGUIFont::getDynamicTextureSize), reinterpret_cast<MT_MFUNC>(&::rGUIFont::setDynamicTextureSize), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MT_CTSTR rGUIFont::getExt() const {
    return "gfd";
}

static auto ddon_emit_0x01b9e1f0 __attribute__((used)) = &rGUIFont::getSuffix;

bool rGUIFont::isDynamic() const {
    return static_cast<bool>(mAttr & 1u);
}

bool rGUIFont::isLayoutEvenIntervals() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 244)) & 2) >> 1);
}

static auto ddon_emit_0x01b9e260 __attribute__((used)) = &rGUIFont::getFontType;

static auto ddon_emit_0x01b9e280 __attribute__((used)) = &rGUIFont::getFontSize;

static auto ddon_emit_0x01b9e2b0 __attribute__((used)) = &rGUIFont::getTextureNum;

nDraw::Texture* rGUIFont::getTexture(u32 index) const {
    if ((mAttr & 1u) != 0) {
        if (index < mDynamicTextureNum) {
            return mpDynamicTexture[index];
        }
    } else {
        if (index < mTextureNum) {
            return mpTexture[index]->mpTexture;
        }
    }
    return nullptr;
}

static auto ddon_emit_0x01b9e1d0 __attribute__((used)) = &rGUIFont::getMaxAscent;

static auto ddon_emit_0x01b9e1e0 __attribute__((used)) = &rGUIFont::getMaxDescent;

__attribute__((weak)) const rGUIFont::CHAR* rGUIFont::searchChar(u32 code) const {
    DDON_STUB("rGUIFont::searchChar")
    return nullptr;
}

void* rGUIFont::memAlloc(u32 size) {
    return MtMemoryAllocator::getAllocator(rGUIFont::DTI)->memAlloc(size, 16u);
}

void rGUIFont::memFree(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGUIFont::DTI)->memFree(p_addr);
}

void rGUIFont::setSuffix(u32 type) {
    mSuffix = type;
}

void rGUIFont::setDynamic(bool e) {
    mAttr = !e ? (mAttr & 0xFFFFFFFEu) : (mAttr | 1u);
}

void rGUIFont::setLayoutEvenIntervals(bool e) {
    mAttr = !e ? (mAttr & 0xFFFFFFFDu) : (mAttr | 2u);
}

void rGUIFont::setFontType(u32 type) {
    mFontType = type;
}

void rGUIFont::setFontSize(u32 size) {
    mFontSize = size;
}

void rGUIFont::setTextureNum(u32 size) {
    mTextureNum = size;
}

void rGUIFont::setMaxAscent(f32 v) {
    mMaxAscent = v;
}

void rGUIFont::setMaxDescent(f32 v) {
    mMaxDescent = v;
}

static auto ddon_emit_0x01b9e2f0 __attribute__((used)) = &rGUIFont::getDynamicTextureNum;

static auto ddon_emit_0x01b9e320 __attribute__((used)) = &rGUIFont::getDynamicTextureSize;

__attribute__((weak)) bool rGUIFont::executeLayoutChar() {
    DDON_STUB("rGUIFont::executeLayoutChar")
    return {};
}

void rGUIFont::setDynamicTextureNum(u32 num) {
    mDynamicTextureNum = num;
}

void rGUIFont::setDynamicTextureSize(u32 type) {
    mDynamicTextureSize = type;
}

inline rGUIFont::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGUIFont::MyDTI rGUIFont::DTI("rGUIFont", &::cResource::DTI, 256ul, 0u, 0u);

const MtSize rGUIFont::TEXTURE_SIZE[14] = {
    MtSize(256, 256),
    MtSize(512, 256),
    MtSize(512, 512),
    MtSize(1024, 512),
    MtSize(1024, 1024),
    MtSize(2048, 1024),
    MtSize(2048, 2048),
    MtSize(64, 64),
    MtSize(128, 64),
    MtSize(128, 128),
    MtSize(256, 128),
    MtSize(4096, 1024),
    MtSize(4096, 2048),
    MtSize(4096, 4096),
};

__attribute__((weak)) MtObject* rGUIFont::MyDTI::newInstance() const {
    return new (16u) rGUIFont;
}

