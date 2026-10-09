#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtSynchronize.h"

// Forward declarations
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cSystem;

// Declarations
class MtAllocator;
class MtDefaultAllocator;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using uintptr = __uintptr_t;

class MtAllocator : public MtObject
{
    // inferred: cSystem::setJobSafe names MtAllocator::mJobSafe
    friend class cSystem;
public:
    enum TYPE
    {
        TYPE_VIRTUAL = 0,
        TYPE_VIRTUAL64KB = 1,
        TYPE_PHYSICAL = 2,
        TYPE_PHYSICAL64KB = 3,
        TYPE_PHYSICAL16MB = 4,
        TYPE_DEVELOP = 5,
        TYPE_CACHE = 6,
        TYPE_SHARED = 7,
        TYPE_ONION = 8,
        TYPE_GARLIC = 9,
        TYPE_ADDR32BIT = 10,
        TYPE_UNKNOWN = 65535,
    };
    enum ATTR
    {
        ATTR_READONLY = 1,
        ATTR_THREADSAFE = 2,
        ATTR_JOBSAFE = 4,
        ATTR_FAST_STACKWALK = 8,
        ATTR_TRACE = 16,
        ATTR_DEBUG = 32,
        ATTR_MEMORYFILL = 64,
        ATTR_ZEROCLEAR = 128,
        ATTR_ERR = 65535,
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
    virtual ~MtAllocator();
    virtual void initializeAllocator(MT_CTSTR name, TYPE type, size_t size, u16 attr);  // vtable slot 6
    void acquireThreadOwnership();
    void releaseThreadOwnership();
    MT_CTSTR getName() const;
    TYPE getType() const;
    void setAttribute(u32 attr);
    u32 getAttribute() const;
    static void setJobSafe(bool f);
    static u32 getAllocatorType(MT_CTSTR type);
    static u32 getAllocatorPageSize(MT_CTSTR type);
    static u32 getAllocatorAttr(MT_CTSTR attr);
    bool isThreadSafe() const;
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    size_t getTotalSize() const;
    size_t getUsedSize() const;
    size_t getAvailSize() const;
    virtual size_t getMaxAvailSize();  // vtable slot 7
    size_t getMaxUsedSize() const;
    virtual void* memAlloc(size_t, u32) = 0;  // vtable slot 8
    virtual void* memAlloc(size_t, u32, u32) = 0;  // vtable slot 9
    virtual void* memAlloc(size_t, u32, u32, u32) = 0;  // vtable slot 10
    virtual void* memAllocTail(size_t size, u32 align);  // vtable slot 11
    virtual void* memAllocTail(size_t size, u32 align, u32 user_tag);  // vtable slot 12
    virtual void* memAllocTail(size_t size, u32 align, u32 user_tag, u32 user_data);  // vtable slot 13
    virtual void memFree(void*) = 0;  // vtable slot 14
    virtual size_t memSize(void*) = 0;  // vtable slot 15
protected:
    static void setMemoryLeakFlag(u32 alloc_idx);
    MtAllocator();
    bool isOwnerThread();
    void lock();
    void unlock();
    void setDmy(u32);
    void createInformationProperty(MtPropertyList& s);
    void createAttributeProperty(MtPropertyList& s);
    void createStatisticProperty(MtPropertyList& s);
    void createMapProperty(MtPropertyList& s);
    u32 getAllocatorIndex() const;
    void setAllocatorIndex(u32 alloc_idx);
protected:
    size_t mUsedSize;  // offset: 0x8
    size_t mMaxUsedSize;  // offset: 0x10
    size_t mTotalSize;  // offset: 0x18
private:
    MT_CHAR mNameStr[32];  // offset: 0x20
    MT_CTSTR mName;  // offset: 0x40
    u16 mType;  // offset: 0x48
    u16 mAttr;  // offset: 0x4a
    uintptr mOwner;  // offset: 0x50
    MtCriticalSection mCS;  // offset: 0x58
    u32 mAllocatorIndex;  // offset: 0x60
public:
    static MyDTI DTI;
protected:
    static bool mJobSafe;
};

class MtDefaultAllocator : public MtAllocator
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
    MtDefaultAllocator();
    virtual ~MtDefaultAllocator();
    virtual void initializeAllocator(MT_CTSTR name, MtAllocator::TYPE type, size_t size, u16 attr);  // vtable slot 6
    virtual void* memAlloc(size_t size, u32 align);  // vtable slot 8
    virtual void* memAlloc(size_t size, u32 align, u32 user_tag);  // vtable slot 9
    virtual void* memAlloc(size_t size, u32 align, u32 user_tag, u32 user_data);  // vtable slot 10
    virtual void memFree(void* padr);  // vtable slot 14
    virtual size_t memSize(void* padr);  // vtable slot 15
public:
    static MyDTI DTI;
};
