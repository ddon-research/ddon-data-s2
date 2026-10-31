#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class _localArrayContainer;

// Declarations
class _localArrayBase;
template <typename T, long unsigned int WARN_SIZE, long unsigned int ERR_SIZE> class localArray;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class _localArrayBase
{
public:
    _localArrayBase(const _localArrayContainer& container);
protected:
    _localArrayBase();
    void* getBuffer();
    u32 getSizeBuffer();
protected:
    void* mpBuffer;  // offset: 0x0
    size_t mSizeBuffer;  // offset: 0x8
};

template <typename T, long unsigned int WARN_SIZE, long unsigned int ERR_SIZE>
class localArray : public _localArrayBase
{
public:
    localArray(const _localArrayContainer& container);
    void fill(u8 value);
    T& operator[](size_t index);
protected:
    void validate();
protected:
    size_t mElementNum;  // offset: 0x10
};

inline _localArrayBase::_localArrayBase() {
}
