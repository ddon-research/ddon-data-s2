#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtString;

// Declarations
class cGUIKeepString;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIKeepString : public MtObject
{
public:
    enum
    {
        TYPE_NONE = 0,
        TYPE_ONLINESHOP = 1,
        TYPE_NUM = 2,
    };
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
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
    cGUIKeepString();
    virtual ~cGUIKeepString();
    void saveString(u32 Type, MtString& String, u32 Arg);
    void saveString(u32 Type, MT_CTSTR pString, u32 Arg);
    MT_CTSTR getString();
    u32 getArg();
    bool isSameStringType(u32 Type);
private:
    u32 mType;  // offset: 0x8
    u32 mArg;  // offset: 0xc
    MtString mStr;  // offset: 0x10
public:
    static MyDTI DTI;
};
