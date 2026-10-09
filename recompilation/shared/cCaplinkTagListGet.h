#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cTagInfo; }

// Declarations
namespace nCaplink { class TagListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class TagListGetAns : public nCaplink::ContextListener
    {
    public:
        TagListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setTagInfoTbl(MtArray& entry_list);
        u32 getTagTotal() const;
        u32 getTagCount() const;
        nCaplink::cTagInfo* getTagInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mTagInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
