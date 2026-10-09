#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cIgnoreUserInfo; }

// Declarations
namespace nCaplink { class UserIgnoreListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class UserIgnoreListGetAns : public nCaplink::ContextListener
    {
    public:
        UserIgnoreListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setIgnoreUserInfoTbl(MtArray& entry_list);
        s32 getIgnoreUserTotal() const;
        u32 getIgnoreUserCount() const;
        nCaplink::cIgnoreUserInfo* getIgnoreUserInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mIgnoreUserInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
