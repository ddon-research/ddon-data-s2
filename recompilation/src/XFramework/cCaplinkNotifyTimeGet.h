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
namespace nCaplink { class NotifyTimeGetAns; }
namespace nCaplink { class NotifyTimeGetReqCtx; }

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
    class NotifyTimeGetAns : public nCaplink::ContextListener
    {
    public:
        NotifyTimeGetAns();
        virtual void init();  // vtable slot 6
        void setParam(s8 morning, s8 afternoon, s8 midnight, s8 evening);
        s8 getMorning() const;
        s8 getAfternoon() const;
        s8 getMidnight() const;
        s8 getEvening() const;
    private:
        s8 mMorning;  // offset: 0x20
        s8 mAfternoon;  // offset: 0x21
        s8 mMidnight;  // offset: 0x22
        s8 mEvening;  // offset: 0x23
    };
}  // namespace nCaplink

namespace nCaplink {
    class NotifyTimeGetReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::NotifyTimeGetReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbMorning;  // offset: 0x9
            bool mbAfternoon;  // offset: 0xa
            bool mbMidnight;  // offset: 0xb
            bool mbEvening;  // offset: 0xc
            bool mbCode;  // offset: 0xd
            bool mbDetailMessage;  // offset: 0xe
            s32 mChatId;  // offset: 0x10
            MtString mChatMessage;  // offset: 0x18
            nCaplink::NotifyTimeGetReqCtx* mpParent;  // offset: 0x20
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
        NotifyTimeGetReqCtx();
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setMorning(s8 morning);
        void setAfternoon(s8 afternoon);
        void setMidnight(s8 midnight);
        void setEvening(s8 evening);
    private:
        s8 mMorning;  // offset: 0x68
        s8 mAfternoon;  // offset: 0x69
        s8 mMidnight;  // offset: 0x6a
        s8 mEvening;  // offset: 0x6b
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::NotifyTimeGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::NotifyTimeGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyTimeGetReqCtx::DTI)->memFree(p_addr);
}
