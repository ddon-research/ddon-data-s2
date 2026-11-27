#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtString.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
namespace nCaplink { class NotifyDeviceSettingAns; }
namespace nCaplink { class NotifyDeviceSettingReqCtx; }

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
    class NotifyDeviceSettingAns : public nCaplink::ContextListener
    {
    public:
        NotifyDeviceSettingAns();
        virtual void init();  // vtable slot 6
        void setParam(s8 all, s8 profile, s8 fri, s8 timeline, s8 chat, s8 game);
        s8 getAll() const;
        s8 getProfile() const;
        s8 getFriend() const;
        s8 getTimeline() const;
        s8 getChat() const;
        s8 getGame() const;
    private:
        s8 mAll;  // offset: 0x20
        s8 mProfile;  // offset: 0x21
        s8 mFriend;  // offset: 0x22
        s8 mTimeline;  // offset: 0x23
        s8 mChat;  // offset: 0x24
        s8 mGame;  // offset: 0x25
    };
}  // namespace nCaplink

namespace nCaplink {
    class NotifyDeviceSettingReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::NotifyDeviceSettingReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbAll;  // offset: 0x9
            bool mbProfile;  // offset: 0xa
            bool mbFriend;  // offset: 0xb
            bool mbTimeline;  // offset: 0xc
            bool mbChat;  // offset: 0xd
            bool mbGame;  // offset: 0xe
            bool mbCode;  // offset: 0xf
            bool mbDetailMessage;  // offset: 0x10
            s32 mChatId;  // offset: 0x14
            MtString mChatMessage;  // offset: 0x18
            nCaplink::NotifyDeviceSettingReqCtx* mpParent;  // offset: 0x20
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
        NotifyDeviceSettingReqCtx();
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setAll(s8 all);
        void setProfile(s8 profile);
        void setFriend(s8 fri);
        void setTimeline(s8 timeline);
        void setChat(s8 chat);
        void setGame(s8 game);
    private:
        s8 mAll;  // offset: 0x68
        s8 mProfile;  // offset: 0x69
        s8 mFriend;  // offset: 0x6a
        s8 mTimeline;  // offset: 0x6b
        s8 mChat;  // offset: 0x6c
        s8 mGame;  // offset: 0x6d
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::NotifyDeviceSettingReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::NotifyDeviceSettingReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyDeviceSettingReqCtx::DTI)->memFree(p_addr);
}
