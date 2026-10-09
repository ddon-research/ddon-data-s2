#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "sIMEPS4.h"

// Forward declarations
class MtPoint;
class MtRect;
namespace nIMEPS4 { class InputInfo; }

// Declarations
namespace nInputText { struct ConvertInfo; }
namespace nInputText { class cUnicodeString; }

namespace nInputText {
    enum CHARACTER_ATTRIBUTE
    {
        CHARACTER_ATTRIBUTE_CONFIRMED = 0,
        CHARACTER_ATTRIBUTE_SELECTED = 1,
        CHARACTER_ATTRIBUTE_BEFORE_CONVERT = 2,
        CHARACTER_ATTRIBUTE_CONVERTING = 3,
        CHARACTER_ATTRIBUTE_INVALID = 4,
    };
}  // namespace nInputText

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_WCHAR = wchar_t;
using MT_CWSTR = const MT_WCHAR*;
using MT_WSTR = MT_WCHAR*;
using f32 = float;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nInputText {
    class cUnicodeString
    {
    public:
        cUnicodeString();
        ~cUnicodeString();
        operator const wchar_t *() const;
        operator wchar_t *();
        void clear();
        void setSelect(u32 index);
        void startSelect();
        void cancelSelect();
        void controlSelect(bool isSelect);
        bool isSelecting() const;
        bool getSelectRange(u32* pTop, u32* pLen, u32* pEnd) const;
        bool forward();
        bool backward();
        u32 setCharacterIndex(u32 characterIndex);
        u32 setSelectCharacterIndex(u32 selectCharacterIndex);
        u32 moveTop();
        u32 moveEnd();
        bool moveSelectTop();
        bool moveSelectEnd();
        u32 insert(MT_CWSTR src);
        u32 copy(MT_CWSTR src);
        void copy(const nInputText::cUnicodeString& other);
        u32 fill(MT_WCHAR c, u32 characterCount);
        bool deleteForward();
        bool deleteBackward();
        bool deleteSelect();
        void cut(u32 maxCharacterCount);
        bool moveFromPoint(MtPoint CurPos, f32 base_x, f32 base_y, MtRect limit, u8 grp_no, u32 fw, u32 fh);
        u32 getIndex() const;
        u32 getSelectIndex() const;
        u32 getCharacterIndex() const;
        u32 getSelectCharacterIndex() const;
        u32 getLength() const;
        u32 getCharacterCount() const;
        MT_CWSTR top() const;
        MT_CWSTR current() const;
        MT_CTSTR getUtf8();
        void setUtf8(MT_CTSTR utf8);
    private:
        u32 mIndex;  // offset: 0x0
        u32 mSelectIndex;  // offset: 0x4
        MT_WCHAR mBuffer[2048];  // offset: 0x8
        MT_CHAR mBufferUtf8[6144];  // offset: 0x1008
    };
}  // namespace nInputText

namespace nInputText {
    struct ConvertInfo
    {
    public:
        ConvertInfo();
        void clear();
        void copy(const nInputText::ConvertInfo& other);
        u32 getCaretPos() const;
        nInputText::CHARACTER_ATTRIBUTE getCharacterAttribute(u32 charcterIndex) const;
    public:
        nInputText::cUnicodeString mString;  // offset: 0x0
        nIMEPS4::InputInfo mInputInfo;  // offset: 0x2808
    };
}  // namespace nInputText
