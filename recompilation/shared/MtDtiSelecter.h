#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;

// Declarations
class MtDtiSelecter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class MtDtiSelecter : public MtObject
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
    MtDtiSelecter();
    virtual ~MtDtiSelecter();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool save(MtDataWriter& w);
    bool load(MtDataReader& r);
    MT_CTSTR getSelectDtiName() const;
    void setSelectDtiName(const MtString& NewDtiName);
    u32 getSelectDtiID() const;
    void setSelectDtiID(u32 NewDtiID);
    const MtDTI* getSelectDti() const;
    void setSelectDti(const MtDTI* pNewDti);
    MtObject* newInstanceBySetDti();
protected:
    const MtDTI* mpUseDTI;  // offset: 0x8
public:
    static MyDTI DTI;
};
