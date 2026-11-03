#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCharset.h"

// Forward declarations
class MtStream;

// Declarations
class MtXmlWriter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s16 = short;
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

class MtXmlWriter
{
public:
    enum ENCODE_TYPE
    {
        ENCODE_UNKNOWN = 0,
        ENCODE_UTF8 = 1,
        ENCODE_SHIFT_JIS = 2,
    };
public:
    struct SCOPE;
public:
    struct SCOPE
    {
    public:
        MT_CTSTR name;  // offset: 0x0
        u8 open;  // offset: 0x8
        u8 chr;  // offset: 0x9
        s16 count;  // offset: 0xa
    };
public:
    MtXmlWriter(MtStream& out, ENCODE_TYPE encode);
    virtual ~MtXmlWriter();
    void writeStartDocument();
    void writeEndDocument();
    void writeStartElement(MT_CTSTR name);
    void writeAttribute(MT_CTSTR attr, MT_CTSTR value);
    void writeEndElement();
    virtual void flush();  // vtable slot 2
    void writeCharacters(MT_CTSTR str);
    void writeProcessingInstruction(MT_CTSTR name, MT_CTSTR text);
    void writeNewLine();
private:
    void writeString(MT_CTSTR str);
    const MtXmlWriter& operator=(const MtXmlWriter&);
    void writeTab(s32 n);
    void writeSpace();
    void writeSlash();
    void writeBeginTag();
    void writeEndTag();
    void writeEqual();
    void writeQuotation();
    void writeBack();
    void writeCode(char code);
    void writeDirect(MT_CTSTR str);
    bool handleMultiByteSolver(MtCharset::cMultiByteSolver* pSolver, MT_CTSTR src, u32 at, u32 len);
    virtual u32 writeBytes(const void*, u32);  // vtable slot 3
private:
    MtStream& mStream;  // offset: 0x8
    SCOPE mScope[512];  // offset: 0x10
    s32 mScopePt;  // offset: 0x2010
    char mCache[4096];  // offset: 0x2014
    s32 mCachePt;  // offset: 0x3014
    ENCODE_TYPE mEncode;  // offset: 0x3018
public:
    static const s32 MAX_SCOPE = 512;
private:
    static const s32 mCacheSize = 4096;
    static const s32 mCacheMax = 3500;
};
