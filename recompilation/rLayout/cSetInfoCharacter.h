#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "cSetInfoCoord.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cSetInfo;
class cUnit;

// Declarations
class cSetInfoCharacter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSetInfoCharacter : public cSetInfoCoord
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
    cSetInfoCharacter();
    virtual ~cSetInfoCharacter();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    static MyDTI DTI;
};
