#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtString.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtString;
namespace nCaplink { class cUserBaseInfo; }
class uGUICaplinkTalk;

// Declarations
namespace nCaplink { class ChatGroupMemberListGetAns; }
namespace nCaplink { class ChatGroupMemberListGetReqCtx; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nCaplink {
    class ChatGroupMemberListGetAns : public nCaplink::ContextListener
    {
        friend class ::uGUICaplinkTalk;
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

namespace nCaplink {
    class ChatGroupMemberListGetReqCtx : public nCaplink::HttpRequestContext
    {
    public:
        class MyDTI;
        class JsonParser;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class JsonParser : public MtJsonReader::Handler
        {
        public:
            JsonParser();
            void setParent(nCaplink::ChatGroupMemberListGetReqCtx* parent);
            virtual void beginArray();  // vtable slot 2
            virtual void endArray();  // vtable slot 3
            virtual void beginObject();  // vtable slot 4
            virtual void endObject();  // vtable slot 5
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbArray;  // offset: 0x9
            bool mbTotal;  // offset: 0xa
            bool mbGroupName;  // offset: 0xb
            bool mbGroupSkinId;  // offset: 0xc
            bool mbOwnerUniqueId;  // offset: 0xd
            bool mbOwnerNickname;  // offset: 0xe
            bool mbOwnerIcon;  // offset: 0xf
            bool mbUniqueId;  // offset: 0x10
            bool mbNickname;  // offset: 0x11
            bool mbIcon;  // offset: 0x12
            bool mbCode;  // offset: 0x13
            bool mbDetailMessage;  // offset: 0x14
            MtString mUniqueId;  // offset: 0x18
            MtString mNickname;  // offset: 0x20
            MtString mIcon;  // offset: 0x28
            nCaplink::ChatGroupMemberListGetReqCtx* mpParent;  // offset: 0x30
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        ChatGroupMemberListGetReqCtx();
        ChatGroupMemberListGetReqCtx(MT_CTSTR group_id, s32 offset, s32 count);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setTotal(s32 total);
        void setGroupName(MT_CTSTR group_name);
        void setGroupSkinId(s32 group_skin_id);
        void setOwnerUniqueId(MT_CTSTR owner_unique_id);
        void setOwnerNickname(MT_CTSTR owner_nickname);
        void setOwnerIcon(MT_CTSTR owner_icon);
        void setUserInfo(nCaplink::cUserBaseInfo* info);
    private:
        MtString mUniqueId;  // offset: 0x68
        s32 mOffset;  // offset: 0x70
        s32 mCount;  // offset: 0x74
        s32 mTotal;  // offset: 0x78
        MtString mGroupName;  // offset: 0x80
        s32 mGroupSkinId;  // offset: 0x88
        MtString mOwnerUniqueId;  // offset: 0x90
        MtString mOwnerNickname;  // offset: 0x98
        MtString mOwnerIcon;  // offset: 0xa0
        MtArray mUserInfoTbl;  // offset: 0xa8
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::ChatGroupMemberListGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::ChatGroupMemberListGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupMemberListGetReqCtx::DTI)->memFree(p_addr);
}
