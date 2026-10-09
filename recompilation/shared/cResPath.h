#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtDTI;

// Declarations
class cResPathBase;
class cResPathEx;
template <typename T> class cResPath;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;

class cResPathBase
{
public:
    u64 getResId() const;
    bool isNone() const;
public:
    u64 mId;  // offset: 0x0
};

class cResPathEx : public cResPathBase
{
public:
    void setResDti(const MtDTI*);
};

template <typename T>
class cResPath : public cResPathBase
{
};

// Inline, no code of its own: checked where it is inlined.
inline u64 cResPathBase::getResId() const {
    return this->mId;
}
