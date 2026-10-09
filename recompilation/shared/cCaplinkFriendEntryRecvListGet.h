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
namespace nCaplink { class FriendEntryRecvListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class FriendEntryRecvListGetAns : public nCaplink::ContextListener
    {
    public:
        FriendEntryRecvListGetAns();
        virtual void init();  // vtable slot 6
        void setFriendEntryInfoTbl(MtArray& entry_list);
        void clearFriendEntryInfoTbl();
        void setTotal(s32 total);
        s32 getFriendEntryTotal() const;
        u32 getFriendEntryCount() const;
        nCaplink::cFriendEntryInfo* getFriendEntryInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mFriendEntryInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
