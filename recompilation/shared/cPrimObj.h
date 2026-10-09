#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class cPrimObj;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPrimObj : public MtObject
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
    cPrimObj();
    // Address: 0x01b6cc60 - 0x01b6cc61 (1 bytes)
    virtual ~cPrimObj() {}
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    // Address: 0x01b6ccb0 - 0x01b6ccb1 (1 bytes)
    virtual void createProperty(MtPropertyList& prop_list) {}  // vtable slot 4
    static u32 getUsedMemory();
public:
    static MyDTI DTI;
private:
    static u32 mPrimUsedMemory;
    static MtAllocator* mpAllocator;
};

// Inline, no code of its own: checked where it is inlined.
inline cPrimObj::cPrimObj() {
}
