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
namespace nCaplink { class NotifyTimeModifyAns; }
namespace nCaplink { class NotifyTimeModifyReqCtx; }

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
    class NotifyTimeModifyAns : public nCaplink::ContextListener
    {
    public:
        NotifyTimeModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink

namespace nCaplink {
    class NotifyTimeModifyReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::NotifyTimeModifyReqCtx* parent);
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
            nCaplink::NotifyTimeModifyReqCtx* mpParent;  // offset: 0x18
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
        NotifyTimeModifyReqCtx();
        NotifyTimeModifyReqCtx(s8 morning, s8 afternoon, s8 midnight, s8 evening);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
    private:
        s8 mMorning;  // offset: 0x68
        s8 mAfternoon;  // offset: 0x69
        s8 mMidnight;  // offset: 0x6a
        s8 mEvening;  // offset: 0x6b
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::NotifyTimeModifyReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::NotifyTimeModifyReqCtx::NotifyTimeModifyReqCtx() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::NotifyTimeModifyReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyTimeModifyReqCtx::DTI)->memFree(p_addr);
}
