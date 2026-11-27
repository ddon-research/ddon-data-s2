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
namespace nCaplink { class cChatUserInfo; }

// Declarations
namespace nCaplink { class ChatListGetAns; }
namespace nCaplink { class ChatListGetReqCtx; }

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
    class ChatListGetAns : public nCaplink::ContextListener
    {
    public:
        ChatListGetAns();
        virtual void init();  // vtable slot 6
        void setChatGroupInfo(s32 status, MT_CTSTR group_name, s32 member_total, s32 member_limmit, s32 last_chat_id);
        void setChatUserInfoTbl(MtArray* user_list);
        s32 getChatStatus() const;
        MT_CTSTR getChatGroupName() const;
        s32 getChatMemberTotal() const;
        s32 getChatMemberLimmit() const;
        s32 getChatLastChatId() const;
        u32 getChatUserCount() const;
        nCaplink::cChatUserInfo* getChatUserInfo(s32 index) const;
    private:
        s32 mChatStatus;  // offset: 0x20
        MtString mChatGroupName;  // offset: 0x28
        s32 mChatMemberTotal;  // offset: 0x30
        s32 mChatMemberLimmit;  // offset: 0x34
        s32 mChatLastChatId;  // offset: 0x38
        MtArray mChatUserInfoTbl;  // offset: 0x40
    };
}  // namespace nCaplink

namespace nCaplink {
    class ChatListGetReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::ChatListGetReqCtx* parent);
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
            bool mbStatus;  // offset: 0xa
            bool mbGroupName;  // offset: 0xb
            bool mbMemberTotal;  // offset: 0xc
            bool mbMemberLimmit;  // offset: 0xd
            bool mbLastChatId;  // offset: 0xe
            bool mbChatId;  // offset: 0xf
            bool mbUniqueId;  // offset: 0x10
            bool mbNickname;  // offset: 0x11
            bool mbIcon;  // offset: 0x12
            bool mbChatType;  // offset: 0x13
            bool mbMessage;  // offset: 0x14
            bool mbStampId;  // offset: 0x15
            bool mbStamp;  // offset: 0x16
            bool mbStampComment;  // offset: 0x17
            bool mbImage;  // offset: 0x18
            bool mbImagePixelSize;  // offset: 0x19
            bool mbPosition;  // offset: 0x1a
            bool mbPlatformId;  // offset: 0x1b
            bool mbContentId;  // offset: 0x1c
            bool mbCreatedAt;  // offset: 0x1d
            bool mbCode;  // offset: 0x1e
            bool mbDetailMessage;  // offset: 0x1f
            s32 mChatId;  // offset: 0x20
            MtString mUniqueId;  // offset: 0x28
            MtString mNickname;  // offset: 0x30
            MtString mIcon;  // offset: 0x38
            s32 mChatType;  // offset: 0x40
            MtString mMessage;  // offset: 0x48
            s32 mStampId;  // offset: 0x50
            MtString mStamp;  // offset: 0x58
            MtString mStampComment;  // offset: 0x60
            MtString mImage;  // offset: 0x68
            MtString mImagePixelSize;  // offset: 0x70
            MtString mPosition;  // offset: 0x78
            s32 mPlatformId;  // offset: 0x80
            MtString mContentId;  // offset: 0x88
            MtString mCreatedAt;  // offset: 0x90
            nCaplink::ChatListGetReqCtx* mpParent;  // offset: 0x98
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
        ChatListGetReqCtx();
        ChatListGetReqCtx(s32 id_type, MT_CTSTR id, s32 offset_id, s32 count);
        ChatListGetReqCtx(MT_CTSTR unique_id, s32 id_type, MT_CTSTR id, s32 offset_id, s32 count);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setStatus(s32 status);
        void setGroupName(MT_CTSTR group_name);
        void setMemberTotal(s32 member_total);
        void setMemberLimmit(s32 member_limmit);
        void setLastChatId(s32 last_chat_id);
        void addChatUserInfo(nCaplink::cChatUserInfo* info);
    private:
        MtString mUniqueId;  // offset: 0x68
        s32 mIdType;  // offset: 0x70
        MtString mId;  // offset: 0x78
        s32 mOffsetId;  // offset: 0x80
        s32 mCount;  // offset: 0x84
        s32 mStatus;  // offset: 0x88
        MtString mGroupName;  // offset: 0x90
        s32 mMemberTotal;  // offset: 0x98
        s32 mMemberLimmit;  // offset: 0x9c
        s32 mLastChatId;  // offset: 0xa0
        MtArray mChatUserInfoTbl;  // offset: 0xa8
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::ChatListGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::ChatListGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::ChatListGetReqCtx::DTI)->memFree(p_addr);
}
