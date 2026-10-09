#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class rTable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class rTable : public cResource
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
    rTable();
    virtual ~rTable();
    virtual const MtDTI& getDataDTI();  // vtable slot 16
    virtual const MtDTI& getNativeDTI();  // vtable slot 17
    virtual u16 getDataVersion();  // vtable slot 18
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    MtObject* getDataBase(u32 Idx);
    void setDataBase(MtObject* pData, u32 Idx);
    u32 getDataNum() const;
    void setDataNum(u32 Num);
public:
    u32 mUParam32[4];  // offset: 0x70
    u64 mUParam64[2];  // offset: 0x80
    MtArray mArray;  // offset: 0x90
    static MyDTI DTI;
    static const u32 mMagic = 4997716;
};
