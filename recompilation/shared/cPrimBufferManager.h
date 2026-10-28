#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cPrimObj.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class sPrimitive;

// Declarations
class cPrimBufferManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPrimBufferManager : public cPrimObj
{
    // inferred: sPrimitive::reserveBuffer names cPrimBufferManager::mpBuffer
    friend class sPrimitive;
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
    cPrimBufferManager();
    cPrimBufferManager(u32 size);
    virtual ~cPrimBufferManager();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& prop_list);  // vtable slot 4
    u32 reserveBuffer(void* * ptr, u32 size);
    void clear();
    void* getBuffer() const;
    void* getCurrentBuffer() const;
    u32 getTotalSize() const;
    u32 getCurrentSize() const;
private:
    void* mpBuffer;  // offset: 0x8
    void* mpCurrentPtr;  // offset: 0x10
    u32 mTotalSize;  // offset: 0x18
    u32 mCurrentSize;  // offset: 0x1c
public:
    static MyDTI DTI;
};
