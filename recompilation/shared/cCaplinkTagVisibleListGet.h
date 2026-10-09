#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cTagVisibleInfo; }

// Declarations
namespace nCaplink { class TagVisibleListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class TagVisibleListGetAns : public nCaplink::ContextListener
    {
    public:
        TagVisibleListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setTagVisibleInfoTbl(MtArray& entry_list);
        u32 getTagVisibleTotal() const;
        u32 getTagVisibleCount() const;
        nCaplink::cTagVisibleInfo* getTagVisibleInfo(s32) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mTagVisibleInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
