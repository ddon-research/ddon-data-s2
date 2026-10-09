#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cUserContentInfo; }

// Declarations
namespace nCaplink { class UserProfileContentListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class UserProfileContentListGetAns : public nCaplink::ContextListener
    {
    public:
        UserProfileContentListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setUserContentTagInfoTbl(MtArray& entry_list);
        s32 getUserContentTagTotal() const;
        u32 getUserContentTagCount() const;
        nCaplink::cUserContentInfo* getUserContentTagInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mUserContentTagInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
