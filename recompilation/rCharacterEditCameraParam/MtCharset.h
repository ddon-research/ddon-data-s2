#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class MtCharset;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class MtCharset
{
public:
    enum eEncodingType
    {
        ET_UNKNOWN = 0,
        ET_ASCII = 1,
        ET_SJIS = 2,
        ET_UTF8 = 3,
        ET_UTF8N = 4,
    };
    enum eElementType
    {
        TYPE_UNKNOWN = 0,
        TYPE_ASCII = 1,
        TYPE_KANA = 2,
        TYPE_HANKANA = 2,
        TYPE_KANJI = 3,
    };
    enum eUTF16Type
    {
        TYPE_UTF16_LE = 0,
        TYPE_UTF16_BE = 1,
        TYPE_UTF16_LE_BOM = 2,
        TYPE_UTF16_BE_BOM = 3,
    };
public:
    class cMultiByteSolver;
    class cSolver;
public:
    class cSolver
    {
    public:
        cSolver();
        virtual ~cSolver() {}
    };
public:
    class cMultiByteSolver : public MtCharset::cSolver
    {
    public:
        cMultiByteSolver();
        virtual ~cMultiByteSolver();
        void init(MT_CTSTR str);
        void solve(MT_CTSTR str, u32 at, u32 len);
        bool isDividable() const;
        bool isLeadByte() const;
        u32 getRemainBytes() const;
    private:
        MtCharset::eEncodingType mEncoding;  // offset: 0x8
        u8 mLeadByte;  // offset: 0xc
        u8 mCurrentByte;  // offset: 0xd
        u32 mByteLength;  // offset: 0x10
        u32 mEndIndex;  // offset: 0x14
    };
public:
    MtCharset();
    ~MtCharset();
    static u32 convertUTF8toSJIS(MT_CTSTR pUtf8Str, s32 nUtf8Len, char* pSjisBuffer, s32 nSjisLen);
    static u32 convertSJIStoUTF8(const char* pSjisStr, s32 nSjisLen, MT_STR pUtf8Buffer, s32 nUtf8Len);
    static u32 convertSJIStoJIS(const char* pSjisStr, s32 nSjisLen, char* pJisBuffer, s32 nJisLen);
    static eEncodingType estimateCharEncoding(const void* pStringIn, s32 nLength);
    static bool isAsciiString(MT_CTSTR pString, s32 nLength);
    static bool isSjisChar(MT_CTSTR p2byteStr);
    static bool isSjisChar(MT_CTSTR pSJISString, u32 pos);
    static s32 calcUTF8ByteInSJIS(MT_CTSTR pUtf8Str, s32 nPos);
    static s32 countCharBytesUTF8AsSJIS(MT_CTSTR pUtf8Str);
    static s32 validateUTF8(MT_CTSTR pUtf8Str, s32 nLength);
    static u32 getCharLengthUTF8(const u8 c);
    static u32 getCharLengthSJIS(const u8 c, const u8 c2, eElementType* pType);
    static u32 getCharLengthUTF16(const u16 c, bool* pSurrogate);
    static u32 lengthUTF8(MT_CTSTR pUtf8Str, s32 nUtf8Len);
    static u32 getCharUTF8(MT_STR pChar, MT_CTSTR pUtf8Str, u32 index);
    static u32 getUnicodeUTF8(MT_CTSTR pUtf8Str);
    static u32 convertUTF8toUnicode(MT_CTSTR pUtf8Str, s32 nUtf8Len, u32* pUnicodeBuffer, s32 nUnicodeLen);
    static bool isUTF16hasSurrogatePairs(const void* pUtf16Str, s32 nUtf16Len, bool isBEIfNonBOM);
    static u32 convertUTF16toUTF8(const void* pUtf16Str, s32 nUtf16Len, void* pUtf8Buffer, s32 nUtf8Len, bool isBEIfNonBOM);
    static u32 convertUTF8toUTF16(const void* pUtf8Str, s32 nUtf8Len, void* pUtf16Buffer, s32 nUtf16Len, eUTF16Type convTarget);
private:
    static u32 fromUTF8toSJIS(const u8* pUTF8, const s32 nUTF8, char* pSJIS, const s32 nSJIS);
    static u32 fromSJIStoUTF8(const char* pSJIS, const s32 nSJIS, u8* pUTF8, const s32 nUTF8);
    static u32 fromSJIStoJIS(const char* pSJIS, const s32 nSJIS, char* pJIS, const s32 nJISIn);
    static u32 fromJIStoSJIS(const char* pJIS, const s32 nJIS, char* pSJIS, const s32 nSJISIn);
    static u32 fromUTF16toUTF8(const u16* pUTF16, const s32 nUTF16, u8* pUTF8, const s32 nUTF8, bool isBEIfNonBOM);
    static u32 fromUTF8toUTF16(const u8* pUTF8, const s32 nUTF8, u16* pUTF16, const s32 nUTF16, const eUTF16Type convTarget);
};

// Inline, no code of its own: checked where it is inlined.
inline MtCharset::cSolver::cSolver() {
}
