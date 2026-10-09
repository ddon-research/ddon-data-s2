#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtStream;

// Declarations
class MtXmlReader;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class MtXmlReader
{
public:
    enum ENCODE_TYPE
    {
        ENCODE_UNKNOWN = 0,
        ENCODE_UTF8 = 1,
        ENCODE_SHIFT_JIS = 2,
        ENCODE_UTF16BE = 3,
        ENCODE_UTF16LE = 4,
        ENCODE_AS_IS = 5,
    };
    enum eValidateResult
    {
        VALIDATE_ERROR_NOERROR = 0,
        VALIDATE_ERROR_STREAM = 1,
        VALIDATE_ERROR_RETRY = 2,
        VALIDATE_ERROR_CANCEL = 3,
    };
    enum PARSE_STATE
    {
        STT_DEFAULT = 0,
        STT_BEGIN_PARSE = 1,
        STT_UTF16LE = 2,
        STT_UTF16BE = 3,
        STT_UTF8 = 4,
        STT_BEGIN_TAG = 5,
        STT_BEGIN_TAG_N = 6,
        STT_BEGIN_PROCINST = 7,
        STT_BEGIN_DTD = 8,
        STT_END_TAG = 9,
        STT_END_TAG_N = 10,
        STT_BEGIN_ELEMENT = 11,
        STT_ELEMENT = 12,
        STT_ATTRIBUTE = 13,
        STT_END_ATTRIBUTE = 14,
        STT_BEGIN_ATTRIBUTE = 15,
        STT_END_ELEMENT = 16,
        STT_ERROR = 17,
        STT_PRE_ATTRVALUE = 18,
        STT_BEGIN_ATTRVALUE = 19,
        STT_END_ATTRVALUE = 20,
        STT_PROCINST_DATA = 21,
        STT_END_PROCINST = 22,
        STT_XML_HEADER = 23,
        STT_XML_BEGIN_VERSION = 24,
        STT_XML_VERSION = 25,
        STT_XML_BEGIN_ENCODING = 26,
        STT_XML_ENCODING = 27,
        STT_PRE_PROCINST = 28,
        STT_CHARACTERS = 29,
        STT_SPCHAR_BEGIN = 30,
        STT_SPCHAR = 31,
        STT_SPCHAR_NUMERIC = 32,
        STT_SPCHAR_NUMERIC_DEC = 33,
        STT_SPCHAR_NUMERIC_HEX = 34,
        STT_SPCHAR_END = 35,
        STT_EXCLAMATION = 36,
        STT_BEGIN_COMMENT = 37,
        STT_COMMENT = 38,
        STT_COMMENT2 = 39,
        STT_END_COMMENT = 40,
    };
public:
    template <typename T, unsigned int ALLOCATOR_INDEX> class managed_dynamic_array;
    class Handler;
    struct ATTRIBUTE;
    struct WORK;
    struct ATTRIBUTE_METADATA;
public:
    class Handler
    {
    public:
        Handler();
        virtual ~Handler();
        virtual void endDocument();  // vtable slot 2
        virtual void endElement(MT_CTSTR localname);  // vtable slot 3
        virtual void characters(MT_CTSTR chars, const u32);  // vtable slot 4
        virtual void ignorableWhitespace(MT_CTSTR, u32);  // vtable slot 5
        virtual void processingInstruction(MT_CTSTR target, MT_CTSTR data);  // vtable slot 6
        virtual void startDocument();  // vtable slot 7
        virtual void startElement(MT_CTSTR localname, MtXmlReader::ATTRIBUTE* attr, u32 attr_num);  // vtable slot 8
        MT_CTSTR getAttrValue(MT_CTSTR attrName, MtXmlReader::ATTRIBUTE* attr, u32 attr_num);
        bool hasAttribute(MT_CTSTR attrName, MtXmlReader::ATTRIBUTE* attr, u32 attr_num);
        virtual void error(MT_CTSTR error);  // vtable slot 9
        bool isError();
    protected:
        bool mError;  // offset: 0x8
    };
public:
    struct ATTRIBUTE
    {
    public:
        MT_CTSTR name;  // offset: 0x0
        MT_CTSTR value;  // offset: 0x8
    };
public:
    struct ATTRIBUTE_METADATA
    {
    public:
        size_t pname;  // offset: 0x0
        size_t pvalue;  // offset: 0x8
        u16 name_is_resolved : 1;  // offset: 0x10
        u16 value_is_resolved : 1;  // offset: 0x10
        u16 name_is_allocated : 1;  // offset: 0x10
        u16 value_is_allocated : 1;  // offset: 0x10
    };
public:
    struct WORK
    {
    public:
        ~WORK();
        void resetAttr();
    public:
        MtXmlReader::ENCODE_TYPE encode_type;  // offset: 0x0
        size_t plocalname;  // offset: 0x8
        size_t ptarget;  // offset: 0x10
        size_t pdata;  // offset: 0x18
        u32 attr_num;  // offset: 0x20
        MtXmlReader::ATTRIBUTE attr[512];  // offset: 0x28
        MtXmlReader::ATTRIBUTE_METADATA attr_meta[512];  // offset: 0x2028
    };
public:
    MtXmlReader(MtStream& in, ENCODE_TYPE encode);
    virtual ~MtXmlReader();
    virtual bool parse(Handler& handler);  // vtable slot 2
    static eValidateResult validate(MtStream& in);
private:
    void decodeAttributes(WORK* pWork, u8* pbase);
    const MtXmlReader& operator=(const MtXmlReader&);
private:
    MtStream& mStream;  // offset: 0x8
    ENCODE_TYPE mEncode;  // offset: 0x10
    static const s32 MAX_SRC_BUFSIZE = 4096;
    static const s32 MAX_DST_BUFSIZE = 4096;
};
