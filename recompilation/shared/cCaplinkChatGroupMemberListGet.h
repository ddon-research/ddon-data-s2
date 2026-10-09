#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtString.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
class MtString;
namespace nCaplink { class cUserBaseInfo; }

// Declarations
namespace nCaplink { class ChatGroupMemberListGetAns; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class ChatGroupMemberListGetAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupMemberListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setGroupInfo(MT_CTSTR group_name, s32 group_skin_id, MT_CTSTR owner_unique_id, MT_CTSTR owner_nickname, MT_CTSTR owner_icon);
        void setUserInfoTbl(MtArray* user_list);
        MT_CTSTR getGroupName() const;
        s32 getGroupSkinId() const;
        MT_CTSTR getOwnerUniqueId() const;
        MT_CTSTR getOwnerNickname() const;
        s32 getUserInfoTotal() const;
        u32 getUserInfoCount() const;
        nCaplink::cUserBaseInfo* getUserInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtString mGroupName;  // offset: 0x28
        s32 mGroupSkinId;  // offset: 0x30
        MtString mOwnerUniqueId;  // offset: 0x38
        MtString mOwnerNickname;  // offset: 0x40
        MtString mOwnerIcon;  // offset: 0x48
        MtArray mUserInfoTbl;  // offset: 0x50
    };
}  // namespace nCaplink
