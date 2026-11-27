#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cPrimObj.h"
#include "cPrimTagList.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cPrim;

// Declarations
class cPrimTagManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPrimTagManager : public cPrimObj
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
    cPrimTagManager();
    cPrimTagManager(u32 size);
    virtual ~cPrimTagManager();
    u32 getSize();
    void assignTags(cPrim* * p_prim, u32 prim_num);
private:
    cPrimTagList::PrimTag* mpPrimTags;  // offset: 0x8
    cPrimTagList::IndexTag* mpIndexTags;  // offset: 0x10
    u32 mSize;  // offset: 0x18
    u32 mNumOfTags;  // offset: 0x1c
public:
    static MyDTI DTI;
};

inline void* cPrimTagManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cPrimTagManager::cPrimTagManager() {
}
