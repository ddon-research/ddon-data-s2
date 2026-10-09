#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cLayoutSet.h"
#include "rLayout.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cContextInstNpc;
class cSetInfoNpc;
namespace nLayout { struct stUniqueID; }
class rLayout;
class uControlNpc;

// Declarations
class cLayoutSetNpc;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cLayoutSetNpc : public cLayoutSet
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
    cLayoutSetNpc();
    virtual ~cLayoutSetNpc();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void finish();  // vtable slot 8
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtObject* setLayoutUnit(rLayout* pLayout, u32 no, bool isFroceSet, u32 mode);  // vtable slot 18
    virtual bool deleteAllUnit();  // vtable slot 11
    s32 getIndexFromID(u32 id) const;
    virtual MtObject* getUnit(u32 id);  // vtable slot 10
private:
    uControlNpc* createUnitNpc(const rLayout::SetInfo* psi);
    uControlNpc* createControl(nLayout::stUniqueID* pUniqueId, cSetInfoNpc* pSetInfoNpc, cContextInstNpc* pContext);
protected:
    virtual bool isUseUnitData() const;  // vtable slot 15
public:
    static MyDTI DTI;
};
