#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtString;

// Declarations
namespace nCaplink { class ContextListener; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nCaplink {
    class ContextListener : public ::MtObject
    {
    public:
        enum
        {
            STATUS_NONE = 0,
            STATUS_POOL = 1,
            STATUS_FINISH = 2,
            STATUS_ERROR = 3,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        ContextListener();
        virtual ~ContextListener();
        virtual void init();  // vtable slot 6
        s32 getStatus() const;
        s32 getErrorType() const;
        s32 getErrorCode() const;
        MT_CTSTR getDetailMessage() const;
        void setStatus(s32 status);
        void setError(s32 error_type, s32 error_code, MT_CTSTR detail_message);
    protected:
        s32 mStatus;  // offset: 0x8
        s32 mErrorType;  // offset: 0xc
        s32 mErrorCode;  // offset: 0x10
        MtString mDetailMessage;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink
