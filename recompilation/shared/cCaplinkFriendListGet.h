#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cFriendInfo; }

// Declarations
namespace nCaplink { class FriendListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class FriendListGetAns : public nCaplink::ContextListener
    {
    public:
        FriendListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setLimmit(s32 limmit);
        void setFriendInfoTbl(MtArray& entry_list);
        u32 getFriendTotal() const;
        u32 getFriendLimmit() const;
        u32 getFriendCount() const;
        nCaplink::cFriendInfo* getFriendInfo(s32 index) const;
        const MtArray* getFriendInfoList();
    private:
        s32 mTotal;  // offset: 0x20
        s32 mLimmit;  // offset: 0x24
        MtArray mFriendInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
