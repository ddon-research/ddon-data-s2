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

// Declarations
namespace nCaplink { class ChatGroupCreateAns; }
namespace nCaplink { class ChatGroupCreateReqCtx; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nCaplink {
    class ChatGroupCreateAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupCreateAns();
        virtual void init();  // vtable slot 6
        void setChatGroupInfo(MT_CTSTR id, MT_CTSTR name, MT_CTSTR owner_unique_id, s32 last_chat_id, s32 member_total, s32 member_limmit, MT_CTSTR update_at);
        MT_CTSTR getGroupId() const;
        MT_CTSTR getGroupName() const;
        MT_CTSTR getOwnerUniqueId() const;
        s32 getLastChatId() const;
        s32 getMemberTotal() const;
        s32 getMemberLimmit() const;
        MT_CTSTR getUpdateAt() const;
    private:
        MtString mGroupId;  // offset: 0x20
        MtString mGroupName;  // offset: 0x28
        MtString mOwnerUniqueId;  // offset: 0x30
        s32 mLastChatId;  // offset: 0x38
        s32 mMemberTotal;  // offset: 0x3c
        s32 mMemberLimit;  // offset: 0x40
        MtString mUpdatedAt;  // offset: 0x48
    };
}  // namespace nCaplink

namespace nCaplink {
    class ChatGroupCreateReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::ChatGroupCreateReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbGroupId;  // offset: 0x9
            bool mbGroupName;  // offset: 0xa
            bool mbOwnerUniqueId;  // offset: 0xb
            bool mbLastChatId;  // offset: 0xc
            bool mbMemberTotal;  // offset: 0xd
            bool mbMemberLimit;  // offset: 0xe
            bool mbUpdatedAt;  // offset: 0xf
            bool mbCode;  // offset: 0x10
            bool mbDetailMessage;  // offset: 0x11
            nCaplink::ChatGroupCreateReqCtx* mpParent;  // offset: 0x18
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
        ChatGroupCreateReqCtx();
        ChatGroupCreateReqCtx(MT_CTSTR group_name, s32 group_skin_id, MT_CTSTR group_message, const MtArray* user_info_list);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setGroupId(MT_CTSTR id);
        void setGroupName(MT_CTSTR name);
        void setOwnerUniqueId(MT_CTSTR unique_id);
        void setLastChatId(s32 id);
        void setMemberTotal(s32 total);
        void setMemberLimmit(s32 limmit);
        void setUpdateAt(MT_CTSTR at);
    private:
        MtString mGroupTag;  // offset: 0x68
        MtString mGroupName;  // offset: 0x70
        s32 mGroupSkinId;  // offset: 0x78
        MtString mGroupMessage;  // offset: 0x80
        s8 mIdType;  // offset: 0x88
        MtArray mUserInfoTbl;  // offset: 0x90
        MtString mGroupId;  // offset: 0xb0
        MtString mOwnerUniqueId;  // offset: 0xb8
        s32 mLastChatId;  // offset: 0xc0
        s32 mMemberTotal;  // offset: 0xc4
        s32 mMemberLimit;  // offset: 0xc8
        MtString mUpdatedAt;  // offset: 0xd0
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::ChatGroupCreateReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::ChatGroupCreateReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupCreateReqCtx::DTI)->memFree(p_addr);
}
