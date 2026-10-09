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
class MtPropertyList;
class MtString;
namespace nAI { class EnumObject; }

// Declarations
namespace nAI { class EnumProp; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nAI {
    class EnumProp : public ::MtObject
    {
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
        EnumProp(s32 value);
        virtual ~EnumProp();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void open();
        void setValue(s32);
        u32 getValue() const;
        MT_CTSTR getName() const;
        nAI::EnumProp& operator=(nAI::EnumProp& p);
        bool operator==(nAI::EnumProp& p);
        bool operator!=(nAI::EnumProp& p);
        s8 operator=(s8);
        u8 operator=(u8);
        s16 operator=(s16);
        u16 operator=(u16);
        s32 operator=(s32);
        u32 operator=(u32);
        s64 operator=(s64);
        u64 operator=(u64);
        operator signed char();
        operator unsigned char();
        operator short();
        operator unsigned short();
        operator int();
        operator unsigned int();
        operator long();
        operator unsigned long();
    public:
        s32 mValue;  // offset: 0x8
    private:
        MtString mName;  // offset: 0x10
        MtString mEnumName;  // offset: 0x18
        nAI::EnumObject* mpEnumObject;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nAI
