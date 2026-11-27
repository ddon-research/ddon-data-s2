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
namespace nCaplink { class cFriendInfo; }

// Declarations
namespace nCaplink { class FriendListGetAns; }
namespace nCaplink { class FriendListGetReqCtx; }

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
    class FriendListGetAns : public nCaplink::ContextListener
    {
    public:
        FriendListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setLimmit(s32 limmit);
        void setFriendInfoTbl(MtArray& entry_list);
        u32 getFriendTotal() const;
        u32 getFriendLimmit() const;
        u32 getFriendCount() const;
        nCaplink::cFriendInfo* getFriendInfo(s32 index) const;
        const MtArray* getFriendInfoList();
    private:
        s32 mTotal;  // offset: 0x20
        s32 mLimmit;  // offset: 0x24
        MtArray mFriendInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink

namespace nCaplink {
    class FriendListGetReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::FriendListGetReqCtx* parent);
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
            bool mbLimmit;  // offset: 0xb
            bool mbUniqueId;  // offset: 0xc
            bool mbNickname;  // offset: 0xd
            bool mbLabelname;  // offset: 0xe
            bool mbMemo;  // offset: 0xf
            bool mbPrivacy;  // offset: 0x10
            bool mbIcon;  // offset: 0x11
            bool mbComment;  // offset: 0x12
            bool mbAttribute;  // offset: 0x13
            bool mbAlive;  // offset: 0x14
            bool mbAccordAt;  // offset: 0x15
            bool mbUpdatedAt;  // offset: 0x16
            bool mbCode;  // offset: 0x17
            bool mbDetailMessage;  // offset: 0x18
            MtString mUniqueId;  // offset: 0x20
            MtString mNickname;  // offset: 0x28
            MtString mLabelname;  // offset: 0x30
            MtString mMemo;  // offset: 0x38
            s8 mPrivacy;  // offset: 0x40
            MtString mIcon;  // offset: 0x48
            MtString mComment;  // offset: 0x50
            s8 mAttribute;  // offset: 0x58
            s8 mAlive;  // offset: 0x59
            MtString mAccordAt;  // offset: 0x60
            MtString mUpdatedAt;  // offset: 0x68
            nCaplink::FriendListGetReqCtx* mpParent;  // offset: 0x70
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
        FriendListGetReqCtx();
        FriendListGetReqCtx(MT_CTSTR from_datetime, s32 offset, s32 count);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setTotal(s32 total);
        void setLimmit(s32 limmit);
        void addFriendInfo(nCaplink::cFriendInfo* info);
    private:
        MtString mUniqueId;  // offset: 0x68
        MtString mFromDatetime;  // offset: 0x70
        s32 mOffset;  // offset: 0x78
        s32 mCount;  // offset: 0x7c
        s32 mTotal;  // offset: 0x80
        s32 mLimmit;  // offset: 0x84
        MtArray mFriendInfoTbl;  // offset: 0x88
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::FriendListGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::FriendListGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::FriendListGetReqCtx::DTI)->memFree(p_addr);
}
