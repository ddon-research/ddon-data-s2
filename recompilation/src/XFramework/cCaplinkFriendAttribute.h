#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class FriendAttributeAns; }

// Type aliases from DWARF
using s32 = int;

namespace nCaplink {
    class FriendAttributeAns : public nCaplink::ContextListener
    {
    public:
        FriendAttributeAns();
        virtual void init();  // vtable slot 6
        void setFriendTotal(s32 friend_total);
        void setFriendLimmit(s32 friend_limmit);
        s32 getFriendTotal() const;
        s32 getFriendLimmit() const;
    private:
        s32 mFriendTotal;  // offset: 0x20
        s32 mFriendLimmit;  // offset: 0x24
    };
}  // namespace nCaplink
