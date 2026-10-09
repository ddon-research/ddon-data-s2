#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cContentInviteAvailableUserInfo; }

// Declarations
namespace nCaplink { class ContentInviteAvailableListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class ContentInviteAvailableListGetAns : public nCaplink::ContextListener
    {
    public:
        ContentInviteAvailableListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setContentInviteInfoTbl(MtArray& entry_list);
        u32 getContentInviteAvailableUserTotal() const;
        u32 getContentInviteAvailableUserCount() const;
        nCaplink::cContentInviteAvailableUserInfo* getContentInviteAvailableUserInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mContentInviteInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
