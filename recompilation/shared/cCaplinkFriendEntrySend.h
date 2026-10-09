#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class FriendEntrySendAns; }

// Type aliases from DWARF
using s32 = int;

namespace nCaplink {
    class FriendEntrySendAns : public nCaplink::ContextListener
    {
    public:
        FriendEntrySendAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setLimmit(s32 limmit);
        s32 getTotal() const;
        s32 getLimmit() const;
    private:
        s32 mTotal;  // offset: 0x20
        s32 mLimmit;  // offset: 0x24
    };
}  // namespace nCaplink
