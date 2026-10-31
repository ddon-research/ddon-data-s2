#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../generated/shared/ime_types.h"
#include "sIME.h"

// Forward declarations
struct SceImeTextAreaProperty;

// Declarations
namespace nIMEPS4 { class CandidateDispInfo; }
namespace nIMEPS4 { class InputInfo; }

// Type aliases from DWARF
using MT_WCHAR = wchar_t;
using MT_CWSTR = const MT_WCHAR*;
using __uint32_t = unsigned int;
using u32 = unsigned int;
using uint32_t = __uint32_t;

namespace nIMEPS4 {
    class CandidateDispInfo : public nIME::CandidateDispInfo
    {
    public:
        CandidateDispInfo();
        virtual ~CandidateDispInfo();
        nIMEPS4::CandidateDispInfo& operator=(const nIMEPS4::CandidateDispInfo& other);
        virtual void clear();  // vtable slot 2
        virtual void setDispString(u32 dispIndex, MT_CWSTR str);  // vtable slot 3
        virtual MT_CWSTR getDispString(u32 dispIndex) const;  // vtable slot 4
        virtual u32 getDispNumMax() const;  // vtable slot 5
    private:
        MT_WCHAR mDispList[10][56];  // offset: 0x10
    };
}  // namespace nIMEPS4

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
