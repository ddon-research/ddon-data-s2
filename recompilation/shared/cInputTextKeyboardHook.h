#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct SceImeKeycode;

// Declarations
class cInputTextKeyboardHook;
namespace nInputTextKeyboardHook { struct Keycode; }

// Type aliases from DWARF
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using u16 = unsigned short;
using uint16_t = __uint16_t;
using uint32_t = __uint32_t;

class cInputTextKeyboardHook
{
public:
    cInputTextKeyboardHook();
    virtual ~cInputTextKeyboardHook();
    virtual bool onKeyEvent(const nInputTextKeyboardHook::Keycode& keycode);  // vtable slot 2
    bool onKeyEvent(const SceImeKeycode& imeKeycode);
    static bool OnKeyEvent(cInputTextKeyboardHook* keyboardHook, const SceImeKeycode* srcKeycode, uint16_t* outKeycode, uint32_t* outStatus);
};

namespace nInputTextKeyboardHook {
    struct Keycode
    {
    public:
        void init();
        bool isValid() const;
        bool isShift() const;
        bool isCtrl() const;
        bool isAlt() const;
    public:
        u16 keyType;  // offset: 0x0
        u16 modifierFlags;  // offset: 0x2
    };
}  // namespace nInputTextKeyboardHook
