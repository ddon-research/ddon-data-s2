#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class MtBigInt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using s64 = __int64_t;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class MtBigInt
{
public:
    using word = u64;
public:
    MtBigInt();
    MtBigInt(s64 num);
    explicit MtBigInt(MT_CTSTR num_str);
    MtBigInt(const MtBigInt& bi);
    ~MtBigInt();
    bool operator==(const MtBigInt& num) const;
    bool operator!=(const MtBigInt&) const;
    bool operator<(const MtBigInt& num) const;
    bool operator<=(const MtBigInt& num) const;
    bool operator>(const MtBigInt& num) const;
    bool operator>=(const MtBigInt&) const;
    MtBigInt operator-() const;
    bool operator!() const;
    MtBigInt& operator++();
    MtBigInt& operator--();
    MtBigInt operator++(int);
    MtBigInt operator--(int);
    operator unsigned int() const;
    operator unsigned long() const;
    operator bool() const;
    MtBigInt& addBigInt(const MtBigInt& num);
    MtBigInt& subBigInt(const MtBigInt& num);
    MtBigInt& mulBigInt(const MtBigInt& num);
    MtBigInt& divBigInt(const MtBigInt& num);
    MtBigInt& operator<<=(u32 shift_num);
    MtBigInt& operator>>=(u32 shift_num);
    MtBigInt& operator&=(const MtBigInt& num);
    MtBigInt& operator|=(const MtBigInt& num);
    MtBigInt& operator^=(const MtBigInt& num);
    MtBigInt operator<<(u32 shift_num) const;
    MtBigInt operator>>(u32 shift_num) const;
    MtBigInt operator&(const MtBigInt& num) const;
    MtBigInt operator|(const MtBigInt& num) const;
    MtBigInt operator^(const MtBigInt& num) const;
    void setZero();
    void setMax();
    void setLongLong(s64 num);
    void setNot();
    void setNeg();
    void setImmediate(MT_CTSTR num_str);
    void square();
    bool isMinus() const;
    bool isZero() const;
    word getWord(u32) const;
    void setWord(u32 index, word value);
    void getDecNum(u8* out) const;
    u32 getUsedWordSize() const;
    u32 getUsedByteSize() const;
    u32 getUsedBitSize() const;
    u32 getAvailableBit() const;
    void getFromBuffer(const u8* in, u32 size);
    void set2Buffer(u8* out, u32 size) const;
private:
    word mNumArray[132];  // offset: 0x0
public:
    static const u32 BI_WORD_SIZE = 64;
    static const u32 BI_ARRAY_MAX = 132;
};

// Inline, no code of its own: checked where it is inlined.
inline MtBigInt::~MtBigInt() {
}
