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
namespace nCaplink { class cChatGroupInfo; }

// Declarations
namespace nCaplink { class ChatGroupListGetAns; }
namespace nCaplink { class ChatGroupListGetReqCtx; }

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

namespace nCaplink {
    class ChatGroupListGetReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::ChatGroupListGetReqCtx* parent);
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
            bool mbIdType;  // offset: 0xb
            bool mbId;  // offset: 0xc
            bool mbStatus;  // offset: 0xd
            bool mbVisible;  // offset: 0xe
            bool mbGroupName;  // offset: 0xf
            bool mbGroupSkinId;  // offset: 0x10
            bool mbOwnerUniqueId;  // offset: 0x11
            bool mbOwnerNickname;  // offset: 0x12
            bool mbOwnerIcon;  // offset: 0x13
            bool mbLastChatId;  // offset: 0x14
            bool mbReadChatId;  // offset: 0x15
            bool mbMemberTotal;  // offset: 0x16
            bool mbMemberLimit;  // offset: 0x17
            bool mbUpdatedAt;  // offset: 0x18
            bool mbCode;  // offset: 0x19
            bool mbDetailMessage;  // offset: 0x1a
            s32 mIdType;  // offset: 0x1c
            MtString mId;  // offset: 0x20
            s32 mStatus;  // offset: 0x28
            s32 mVisible;  // offset: 0x2c
            MtString mGroupName;  // offset: 0x30
            s32 mGroupSkinId;  // offset: 0x38
            MtString mOwnerUniqueId;  // offset: 0x40
            MtString mOwnerNickname;  // offset: 0x48
            MtString mOwnerIcon;  // offset: 0x50
            s32 mLastChatId;  // offset: 0x58
            s32 mReadChatId;  // offset: 0x5c
            s32 mMemberTotal;  // offset: 0x60
            s32 mMemberLimit;  // offset: 0x64
            MtString mUpdatedAt;  // offset: 0x68
            nCaplink::ChatGroupListGetReqCtx* mpParent;  // offset: 0x70
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
        ChatGroupListGetReqCtx();
        ChatGroupListGetReqCtx(MT_CTSTR datetime, s32 offset, s32 count);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setTotal(s32 total);
        void setStatus(s32);
        void setGroupName(MT_CTSTR);
        void setMemberTotal(s32);
        void setMemberLimmit(s32);
        void setLastChatId(s32);
        void addChatGroupInfo(nCaplink::cChatGroupInfo* info);
    private:
        s8 mKeywordType;  // offset: 0x68
        MtString mKeyword;  // offset: 0x70
        MtString mDatetime;  // offset: 0x78
        s32 mOffset;  // offset: 0x80
        s32 mCount;  // offset: 0x84
        s32 mTotal;  // offset: 0x88
        s32 mStatus;  // offset: 0x8c
        MtString mGroupName;  // offset: 0x90
        s32 mMemberTotal;  // offset: 0x98
        s32 mMemberLimmit;  // offset: 0x9c
        s32 mLastChatId;  // offset: 0xa0
        MtArray mChatGroupInfoTbl;  // offset: 0xa8
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::ChatGroupListGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::ChatGroupListGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupListGetReqCtx::DTI)->memFree(p_addr);
}
