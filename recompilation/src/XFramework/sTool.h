#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "sToolBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPoint;

// Declarations
class sTool;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class sTool : public sToolBase
{
public:
    enum OP_MODE
    {
        OP_DEFAULT = 0,
        OP_PAD1 = 1,
        OP_PAD2 = 2,
        OP_PAD3 = 3,
        OP_PAD4 = 4,
        OP_NUM = 5,
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
    sTool(u32 buf_size);
    virtual ~sTool() {}
    void exit();
    virtual void load(MT_CTSTR path, MtPoint spt);  // vtable slot 12
    virtual void save(MT_CTSTR path) {}  // vtable slot 13
    bool isActive();
    void setActive(bool);
    void setOperationMode(u32);
    OP_MODE getOperationMode();
    void setDispPage(u8);
    bool isDisp(u8);
    virtual MT_CTSTR getPageGroupName(u32 page);  // vtable slot 14
    virtual MT_CTSTR getPageName(u32 page);  // vtable slot 15
    u32 getTraceLogNum();
    MT_CTSTR getTraceLog(u32);
    void clearTraceLog();
public:
    static MyDTI DTI;
};

inline void* sTool::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void sTool::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sTool::DTI)->memFree(p_addr);
}
