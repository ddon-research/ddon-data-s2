#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/ime_types.h"
#include "sIME.h"

// Forward declarations
struct SceImeTextAreaProperty;

// Declarations
namespace nIMEPS4 { class InputInfo; }

// Type aliases from DWARF
using __uint32_t = unsigned int;
using u32 = unsigned int;
using uint32_t = __uint32_t;

namespace nIMEPS4 {
    class InputInfo : public nIME::InputInfo
    {
    public:
        InputInfo();
        virtual ~InputInfo();
        nIMEPS4::InputInfo& operator=(const nIMEPS4::InputInfo& other);
        virtual void clear();  // vtable slot 2
        virtual u32 getCaretIndex() const;  // vtable slot 3
        virtual nIME::CHARACTER_ATTRIBUTE getCharacterAttribute(u32 characterIndex) const;  // vtable slot 4
        void setParam(u32 editCaretIndex, u32 editAreaNum, const SceImeTextAreaProperty(&editAreaPropertys)[4]);
    private:
        uint32_t mEditCaretIndex;  // offset: 0x8
        uint32_t mEditAreaNum;  // offset: 0xc
        SceImeTextAreaProperty mEditAreaPropertys[4];  // offset: 0x10
    };
}  // namespace nIMEPS4
