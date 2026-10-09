#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"
#include "nDrawTexture.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSize;
class MtStream;
class MtUI;
namespace nDraw { class Texture; }
class rTexture;
class sGUI;

// Declarations
class rGUIFont;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class rGUIFont : public cResource
{
    // inferred: sGUI::updateDynamicFont calls rGUIFont::executeLayoutChar
    friend class sGUI;
public:
    enum TEXTURE_SIZE
    {
        TEXTURE_SIZE_256_256 = 0,
        TEXTURE_SIZE_512_256 = 1,
        TEXTURE_SIZE_512_512 = 2,
        TEXTURE_SIZE_1024_512 = 3,
        TEXTURE_SIZE_1024_1024 = 4,
        TEXTURE_SIZE_2048_1024 = 5,
        TEXTURE_SIZE_2048_2048 = 6,
        TEXTURE_SIZE_64_64 = 7,
        TEXTURE_SIZE_128_64 = 8,
        TEXTURE_SIZE_128_128 = 9,
        TEXTURE_SIZE_256_128 = 10,
        TEXTURE_SIZE_4096_1024 = 11,
        TEXTURE_SIZE_4096_2048 = 12,
        TEXTURE_SIZE_4096_4096 = 13,
        TEXTURE_SIZE_NUM = 14,
    };
    enum LAYOUT_STATUS
    {
        LAYOUT_NONE = 0,
        LAYOUT_LOAD_PREPARE = 1,
        LAYOUT_LOAD = 2,
        LAYOUT_WAITING = 3,
        LAYOUT_LAYOUTING = 4,
    };
    enum FONT_TYPE
    {
        FONT_TEXTURED = 0,
        FONT_IMAGE_BASED = 1,
        FONT_MARGE_TEXTURE = 2,
        FONT_TYPE_NUM = 3,
    };
    enum SUFFIX
    {
        SUFFIX_NONE = 0,
        SUFFIX_ID = 1,
        SUFFIX_HQ = 2,
        SUFFIX_ID_HQ = 3,
        SUFFIX_IDL = 4,
        SUFFIX_IDL_HQ = 5,
        SUFFIX_AM_NOMIP = 6,
        SUFFIX_DUMMY3 = 7,
        SUFFIX_NUM = 8,
    };
public:
    class MyDTI;
    struct SRC_CHAR;
    struct CHAR;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct SRC_CHAR
    {
    public:
        u32 textureIndex : 8;  // offset: 0x0
        u32 u : 12;  // offset: 0x0
        u32 v : 12;  // offset: 0x0
        u32 index : 16;  // offset: 0x4
        u32 padding : 16;  // offset: 0x4
        u32 layoutNext : 16;  // offset: 0x8
        u32 requestNext : 16;  // offset: 0x8
        static const u32 INVALID_INDEX = 65535;
    };
public:
    struct CHAR
    {
    public:
        u32 code;  // offset: 0x0
        u32 textureIndex : 8;  // offset: 0x4
        u32 u : 12;  // offset: 0x4
        u32 v : 12;  // offset: 0x4
        u32 offset : 8;  // offset: 0x8
        u32 tw : 12;  // offset: 0x8
        u32 th : 12;  // offset: 0x8
        u32 w : 12;  // offset: 0xc
        u32 descentIndex : 4;  // offset: 0xc
        u32 isValid : 1;  // offset: 0xc
        u32 requestLayout : 1;  // offset: 0xc
        u32 invisible : 1;  // offset: 0xc
        u32 padding : 13;  // offset: 0xc
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
    rGUIFont();
    virtual ~rGUIFont();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getSuffix() const;
    bool isDynamic() const;
    bool isLayoutEvenIntervals() const;
    u32 getFontType() const;
    u32 getFontSize() const;
    u32 getTextureNum() const;
    virtual nDraw::Texture* getTexture(u32 index) const;  // vtable slot 16
    u32 getCharNum() const;
    const CHAR* getChar(u32 code) const;
    f32 getDescent(u32 index) const;
    f32 getMaxAscent() const;
    f32 getMaxDescent() const;
    f32 getMaxHeight() const;
    static MT_CTSTR getSuffixString(u32 type);
    static MtSize getTextureWH(u32 size);
protected:
    const CHAR* searchChar(u32 code) const;
    virtual void* memAlloc(u32 size);  // vtable slot 17
    virtual void memFree(void* p_addr);  // vtable slot 18
    void setSuffix(u32 type);
    void setDynamic(bool e);
    void setLayoutEvenIntervals(bool e);
    void setFontType(u32 type);
    void setFontSize(u32 size);
    void setTextureNum(u32 size);
    void setMaxAscent(f32 v);
    void setMaxDescent(f32 v);
public:
    void clearDynamicTextureFont();
    void beginLayoutChar();
    void addLayoutChar(MT_CTSTR pStr);
    void endLayoutChar(u32 layoutCharCount);
    bool isLayouting() const;
    u32 getDynamicTextureNum() const;
    u32 getDynamicTextureSize() const;
protected:
    bool executeLayoutChar();
    void cancelLayoutChar();
    void setLayouting(bool e);
    void setDynamicTextureNum(u32 num);
    void setDynamicTextureSize(u32 type);
    static MtSize getTextureBlockSize(nDraw::FORMAT_TYPE format);
    static bool isBlockFormat(nDraw::FORMAT_TYPE format);
    void setLayoutNext(rGUIFont* pFont);
    rGUIFont* getLayoutNext() const;
protected:
    u32 mDynamicCharTW : 12;  // offset: 0x70
    u32 mDynamicCharTH : 12;  // offset: 0x70
    u32 mDynamicTextureNum : 4;  // offset: 0x70
    u32 mDynamicTextureSize : 4;  // offset: 0x70
    u32 mDynamicLineNum : 12;  // offset: 0x74
    u32 mRequestStartIndex : 16;  // offset: 0x74
    u32 padding : 4;  // offset: 0x74
    nDraw::FORMAT_TYPE mDynamicTextureFormat;  // offset: 0x78
    u32 mDynamicTextureMisc;  // offset: 0x7c
    SRC_CHAR* mpSourceChar;  // offset: 0x80
    nDraw::Texture* * mpDynamicTexture;  // offset: 0x88
    SRC_CHAR* * mpRequestLayoutCharList;  // offset: 0x90
    SRC_CHAR* * mpLayoutCharList;  // offset: 0x98
    u32 mLayoutCharCount;  // offset: 0xa0
    u32 mLayoutStatus;  // offset: 0xa4
    u32 mLayoutingTextureIndex;  // offset: 0xa8
    rTexture* mpLayoutTexture;  // offset: 0xb0
    u32 mVersion;  // offset: 0xb8
    u32 mTextureNum;  // offset: 0xbc
    u32 mCharNum;  // offset: 0xc0
    u32 mDescentNum;  // offset: 0xc4
    f32* mpDescent;  // offset: 0xc8
    CHAR* mpChar;  // offset: 0xd0
    MT_CTSTR mpTexturePath;  // offset: 0xd8
    rTexture* * mpTexture;  // offset: 0xe0
    rGUIFont* mpLayoutNext;  // offset: 0xe8
private:
    u32 mFontType : 8;  // offset: 0xf0
    u32 mFontSize : 16;  // offset: 0xf0
    u32 mSuffix : 8;  // offset: 0xf0
    u32 mAttr;  // offset: 0xf4
    f32 mMaxAscent;  // offset: 0xf8
    f32 mMaxDescent;  // offset: 0xfc
public:
    static MyDTI DTI;
    static const u32 VERSION = 68614;
private:
    static const u32 ATTR_DYNAMIC = 1;
    static const u32 ATTR_LAYOUT_EVENINTERVALS = 2;
    static const u32 ATTR_LAYOUTING = 2147483648;
    static const MtSize TEXTURE_SIZE[14];
};
