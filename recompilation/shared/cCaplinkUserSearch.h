#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cUserBaseInfo; }

// Declarations
namespace nCaplink { class UserSearchAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class UserSearchAns : public nCaplink::ContextListener
    {
    public:
        UserSearchAns();
        virtual void init();  // vtable slot 6
        void setUserInfoTbl(MtArray& user_list);
        u32 getUserCount() const;
        nCaplink::cUserBaseInfo* getUserInfo(s32 index) const;
    private:
        MtArray mUserInfoTbl;  // offset: 0x20
    };
}  // namespace nCaplink
