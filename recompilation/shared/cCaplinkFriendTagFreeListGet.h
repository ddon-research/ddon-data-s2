#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cFreeTagInfo; }

// Declarations
namespace nCaplink { class FriendTagFreeListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class FriendTagFreeListGetAns : public nCaplink::ContextListener
    {
    public:
        FriendTagFreeListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setFreeTagInfoTbl(MtArray& entry_list);
        u32 getFreeTagTotal() const;
        u32 getFreeTagCount() const;
        nCaplink::cFreeTagInfo* getFreeTagInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mFreeTagInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
