#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cContentInfo; }

// Declarations
namespace nCaplink { class ContentListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class ContentListGetAns : public nCaplink::ContextListener
    {
    public:
        ContentListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setContentInfoTbl(MtArray& entry_list);
        u32 getContentTotal() const;
        u32 getContentCount() const;
        nCaplink::cContentInfo* getContentInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mContentInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
