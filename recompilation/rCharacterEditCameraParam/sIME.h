#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace nInputText { struct CandidateList; }

// Declarations
namespace nIME { class CandidateDispInfo; }
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
using MT_WCHAR = wchar_t;
using MT_CWSTR = const MT_WCHAR*;
using u32 = unsigned int;

namespace nIME {
    class CandidateDispInfo
    {
        // inferred: nInputText::CandidateList::getCandidateListCount names nInputText::CandidateList::mCandidateDispInfo.::nIME::CandidateDispInfo::mListNum
        friend struct nInputText::CandidateList;
    public:
        CandidateDispInfo();
        virtual ~CandidateDispInfo();
        virtual void clear();  // vtable slot 2
        void setListNum(u32 listNum);
        void setListSelectIndex(u32 listSelectIndex);
        virtual void setDispString(u32, MT_CWSTR) = 0;  // vtable slot 3
        virtual MT_CWSTR getDispString(u32) const = 0;  // vtable slot 4
        virtual u32 getDispNumMax() const = 0;  // vtable slot 5
        u32 getListNum() const;
        u32 getListSelectIndex() const;
        u32 getPageNum() const;
        u32 getDispPageIndex() const;
        u32 getDispStartIndex() const;
        u32 getDispIndex() const;
        u32 getDispNum() const;
    private:
        u32 mListNum;  // offset: 0x8
        u32 mListSelectIndex;  // offset: 0xc
    };
}  // namespace nIME

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

// Inline, no code of its own: checked where it is inlined.
// inferred: parameters bound at each inlined copy's entry: the body its copies' regions agree on (026 P6b1); approximate: no recompile checks it
inline u32 nIME::CandidateDispInfo::getListNum() const {
    return this->mListNum;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: parameters bound at each inlined copy's entry: the body its copies' regions agree on (026 P6b1); approximate: no recompile checks it
inline u32 nIME::CandidateDispInfo::getListSelectIndex() const {
    return this->mListSelectIndex;
}
