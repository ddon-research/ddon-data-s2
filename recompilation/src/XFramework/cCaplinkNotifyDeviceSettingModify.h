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
namespace nCaplink { class NotifyDeviceSettingModifyAns; }
namespace nCaplink { class NotifyDeviceSettingModifyReqCtx; }

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
    class NotifyDeviceSettingModifyAns : public nCaplink::ContextListener
    {
    public:
        NotifyDeviceSettingModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink

namespace nCaplink {
    class NotifyDeviceSettingModifyReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::NotifyDeviceSettingModifyReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbCode;  // offset: 0x9
            bool mbDetailMessage;  // offset: 0xa
            s32 mChatId;  // offset: 0xc
            MtString mChatMessage;  // offset: 0x10
            nCaplink::NotifyDeviceSettingModifyReqCtx* mpParent;  // offset: 0x18
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
        NotifyDeviceSettingModifyReqCtx();
        NotifyDeviceSettingModifyReqCtx(s8 all, s8 profile, s8 fri, s8 timeline, s8 chat, s8 game);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
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

inline void* nCaplink::NotifyDeviceSettingModifyReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::NotifyDeviceSettingModifyReqCtx::NotifyDeviceSettingModifyReqCtx() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::NotifyDeviceSettingModifyReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyDeviceSettingModifyReqCtx::DTI)->memFree(p_addr);
}
