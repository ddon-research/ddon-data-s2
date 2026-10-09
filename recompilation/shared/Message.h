#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataErrorMessage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class CDataErrorMessage : public CPacketDataBase
{
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
    explicit CDataErrorMessage();
    explicit CDataErrorMessage(u32, u32, const char*, const char*);
public:
    u32 m_unMessageID;  // offset: 0x8
    u32 m_unErrorID;  // offset: 0xc
    MtString m_wstrMessage;  // offset: 0x10
    MtString m_wstrDevelopMessage;  // offset: 0x18
    static MyDTI DTI;
};
