#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtProperty.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtProperty;

// Declarations
class MtPropertyList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class MtPropertyList : public MtObject
{
public:
    class MyDTI;
    struct poolChain;
    class Iterator;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct poolChain
    {
    public:
        MtProperty* pPool;  // offset: 0x0
        u16 poolPt;  // offset: 0x8
        u16 poolSize;  // offset: 0xa
        MtPropertyList::poolChain* pPrev;  // offset: 0x10
        MtPropertyList::poolChain* pNext;  // offset: 0x18
    };
public:
    class Iterator
    {
    public:
        Iterator(MtProperty* pe);
        operator MtProperty *();
        s32 getIndex();
        MtProperty* operator++(int);
        MtProperty* operator++();
    private:
        MtProperty* mpElement;  // offset: 0x0
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
    MtPropertyList();
    MtPropertyList(MtProperty* prop);
    MtPropertyList(const MtPropertyList& s);
    const MtPropertyList& operator=(const MtPropertyList& s);
    virtual ~MtPropertyList();
    MtProperty* find(MtProperty::TYPE type, MT_CTSTR name) const;
    MtProperty* find(MT_CTSTR name) const;
    MtProperty* operator[](int index);
    void clear();
    u32 length();
    MtProperty* begin() const;
    MtProperty* end() const;
    MtProperty* insert(const MtProperty& prop, MtProperty* ptarget);
    MtProperty* insert(MtPropertyList& ss, MtProperty* ptarget);
    void remove(MtProperty* pp);
    void trace();
    static u32 getMaxUsed();
    static void releaseElementPool();
    void operator<<(const MtProperty& prop);
    void operator<<(s32);
    MtProperty* insert(s32);
    void add(const MtProperty& prop);
private:
    poolChain* allocateChain(u16 allocateSize);
    MtProperty* newElement();
private:
    MtProperty* mpElement;  // offset: 0x8
public:
    static MyDTI DTI;
private:
    static const u16 BASE_ELEMENTPOOL = 2048;
    static const u16 INCR_ELEMENTPOOL = 1024;
    static MtProperty* mpEmpty;
    static poolChain* mpPool;
    static MtProperty mBasePool[2048];
    static poolChain mBaseChain;
    static u32 mMaxUsed;
    static MtCriticalSection mCS;
};
