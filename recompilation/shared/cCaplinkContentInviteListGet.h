#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cContentInviteUserInfo; }

// Declarations
namespace nCaplink { class ContentInviteListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class ContentInviteListGetAns : public nCaplink::ContextListener
    {
    public:
        ContentInviteListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setContentInviteUserInfoTbl(MtArray& entry_list);
        u32 getContentInviteUserTotal() const;
        u32 getContentInviteUserCount() const;
        nCaplink::cContentInviteUserInfo* getContentInviteUserInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mContentInviteUserInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
