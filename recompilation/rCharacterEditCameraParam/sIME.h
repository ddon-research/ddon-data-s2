#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nIME { class InputInfo; }

namespace nIME {
    enum CHARACTER_ATTRIBUTE
    {
        CHARACTER_ATTRIBUTE_CONFIRMED = 0,
        CHARACTER_ATTRIBUTE_SELECTED = 1,
        CHARACTER_ATTRIBUTE_BEFORE_CONVERT = 2,
        CHARACTER_ATTRIBUTE_CONVERTING = 3,
    };
}  // namespace nIME

// Type aliases from DWARF
using u32 = unsigned int;

namespace nIME {
    class InputInfo
    {
    public:
        InputInfo();
        virtual ~InputInfo();
        virtual void clear() = 0;  // vtable slot 2
        virtual u32 getCaretIndex() const = 0;  // vtable slot 3
        virtual nIME::CHARACTER_ATTRIBUTE getCharacterAttribute(u32) const = 0;  // vtable slot 4
    };
}  // namespace nIME
