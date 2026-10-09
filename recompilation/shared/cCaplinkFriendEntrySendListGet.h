#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cFriendEntryInfo; }

// Declarations
namespace nCaplink { class FriendEntrySendListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class FriendEntrySendListGetAns : public nCaplink::ContextListener
    {
    public:
        FriendEntrySendListGetAns();
        virtual void init();  // vtable slot 6
        void setFriendEntryInfoTbl(MtArray& entry_list);
        void clearFriendEntryInfoTbl();
        void setTotal(s32 total);
        s32 getFriendEntryTotal() const;
        u32 getFriendEntryCount() const;
        nCaplink::cFriendEntryInfo* getFriendEntryInfo(s32 index) const;
    private:
        MtArray mFriendEntryInfoTbl;  // offset: 0x20
        s32 mTotal;  // offset: 0x40
    };
}  // namespace nCaplink
