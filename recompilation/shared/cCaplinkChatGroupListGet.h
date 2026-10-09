#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
namespace nCaplink { class cChatGroupInfo; }

// Declarations
namespace nCaplink { class ChatGroupListGetAns; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class ChatGroupListGetAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setChatGroupInfoTbl(MtArray* user_list);
        s32 getChatGroupTotal() const;
        u32 getChatGroupCount() const;
        nCaplink::cChatGroupInfo* getChatGroupInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mChatGroupInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink
