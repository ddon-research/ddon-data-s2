#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtAllocator;

// Declarations
class MtString;
template <int _size> class MtStringEx;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

class MtString
{
public:
    struct STRING;
public:
    struct STRING
    {
    public:
        s32 ref;  // offset: 0x0
        u32 length;  // offset: 0x4
        u8 str[1];  // offset: 0x8
    };
public:
    static void setAllocator(MtAllocator* pa);
    static MtAllocator* getAllocator();
    static u32 length(MT_CTSTR s);
    static void copy(MT_STR a, MT_CTSTR b);
    static void copy(MT_STR a, MT_CTSTR b, const u32 max);
    static void concatenate(MT_STR a, MT_CTSTR b, const u32 max);
    static s32 compare(MT_CTSTR a, MT_CTSTR b);
    static s32 compare(MT_CTSTR a, MT_CTSTR b, u32 n);
    static s32 icompare(MT_CTSTR a, MT_CTSTR b);
    static s32 icompare(MT_CTSTR, MT_CTSTR, u32);
    static MT_CTSTR strstr(MT_CTSTR from, MT_CTSTR key);
    static MT_CTSTR stristr(MT_CTSTR from, MT_CTSTR key);
    MtString();
    MtString(MT_CTSTR str);
    MtString(const MtString& str);
    ~MtString();
    u32 length() const;
    MT_CTSTR ptr() const;
    const MtString& copy(MT_CTSTR str);
    const MtString& copy(const MtString& str);
    s32 compare(MT_CTSTR str) const;
    s32 compare(const MtString& str) const;
    s32 icompare(const MtString& str) const;
    void concat(MT_CHAR c);
    void concat(MT_CTSTR str);
    void concat(const MtString& str);
    const MtString& format(MT_CTSTR format, ...);
    operator const char *() const;
    const MtString& operator=(MT_CTSTR str);
    const MtString& operator=(const MtString& str);
    void operator+=(MT_CHAR c);
    void operator+=(MT_CTSTR str);
    void operator+=(const MtString& str);
    MtString operator+(MT_CTSTR str);
    MtString operator+(const MtString& str);
    bool operator==(MT_CTSTR str) const;
    bool operator==(const MtString& str) const;
    bool operator!=(MT_CTSTR str) const;
    bool operator!=(const MtString& str) const;
    bool operator<(MT_CTSTR) const;
    bool operator<(const MtString& str) const;
    bool operator>(MT_CTSTR) const;
    bool operator>(const MtString& str) const;
    bool operator<=(MT_CTSTR) const;
    bool operator<=(const MtString&) const;
    bool operator>=(MT_CTSTR) const;
    bool operator>=(const MtString&) const;
protected:
    void create(MT_CTSTR str);
    void release();
    s32 compare(STRING* a, STRING* b) const;
    STRING* concat(STRING* a, STRING* b);
protected:
    STRING* value;  // offset: 0x0
private:
    static MtAllocator* mpAllocator;
};

// Layout verified against DWARF for MtStringEx<1024>, MtStringEx<128>, MtStringEx<16>, MtStringEx<21>, MtStringEx<24>, MtStringEx<256>, MtStringEx<257>, MtStringEx<32>, MtStringEx<33>, MtStringEx<4096>, MtStringEx<44>, MtStringEx<49>, MtStringEx<512>, MtStringEx<513>, MtStringEx<6144>, MtStringEx<64>, MtStringEx<81>
template <int _size>
class MtStringEx
{
public:
    MtStringEx();
    MtStringEx(MT_CTSTR str);
    MtStringEx(const MtString& str);
    u32 length() const;
    MT_CTSTR ptr() const;
    MT_CTSTR copy(MT_CTSTR str);
    void concat(MT_CTSTR str);
    s32 compare(MT_CTSTR str) const;
    MT_CTSTR format(MT_CTSTR format, ...);
    operator const char *() const;
    MT_CTSTR operator=(MT_CTSTR str);
    MT_CTSTR operator=(const MtString& str);
    void operator+=(MT_CTSTR str);
    void operator+=(MtString str);
    bool operator==(MT_CTSTR str) const;
    void concat(MT_CHAR c);
    void operator+=(MT_CHAR c);
protected:
    u32 mLength;  // offset: 0x0
    char mStr[_size];  // offset: 0x4
};

// Inline, no code of its own: checked where it is inlined.
inline MtString::MtString() {
    this->value = static_cast<MtString::STRING*>(nullptr);
}
