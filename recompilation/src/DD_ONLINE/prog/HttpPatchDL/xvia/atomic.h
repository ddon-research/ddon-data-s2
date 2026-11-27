#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../MT/MtSynchronize.h"

// Forward declarations
class MtCriticalSection;

// Declarations
class via_atomic_bool;

// Type aliases from DWARF
using s32 = int;

namespace via {
    namespace Atomic {

        s32 inc(volatile s32* addend);
        s32 dec(volatile s32* addend);
        s32 add(volatile s32* addend, s32 value);

    }  // namespace Atomic
}  // namespace via

class via_atomic_bool
{
public:
    via_atomic_bool();
    virtual ~via_atomic_bool();
    operator bool() const;
    const bool& operator=(bool b);
public:
    bool mBool;  // offset: 0x8
    MtCriticalSection mCs;  // offset: 0x10
};
