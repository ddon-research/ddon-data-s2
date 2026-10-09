#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cContentTagInfo; }

// Declarations
namespace nCaplink { class FriendTagContentListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class FriendTagContentListGetAns : public nCaplink::ContextListener
    {
    public:
        FriendTagContentListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setContentTagInfoTbl(MtArray& entry_list);
        s32 getFriendTagContentTotal() const;
        u32 getFriendTagContentCount() const;
        nCaplink::cContentTagInfo* getContentTagInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mContentTagInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
