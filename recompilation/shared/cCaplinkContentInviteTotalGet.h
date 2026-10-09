#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ContentInviteTotalGetAns; }

// Type aliases from DWARF
using s32 = int;

namespace nCaplink {
    class ContentInviteTotalGetAns : public nCaplink::ContextListener
    {
    public:
        ContentInviteTotalGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        s32 getTotal() const;
    private:
        s32 mTotal;  // offset: 0x20
    };
}  // namespace nCaplink
