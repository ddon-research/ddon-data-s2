#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtVector3;
class cpComponent;
class cpRootComponent;

// Declarations
class cComponentManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cComponentManager : public MtObject
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
    cComponentManager();
    virtual ~cComponentManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setOwner(MtObject* pOwner);
    void setupComponentPtr();
    cpComponent* getRootComponent() const;
    void setup();
    void move();
    void sync();
    void moveAfter();
    void kill();
    void updatePtr();
    void updateEfcHandle();
    void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
    cpComponent* find(const MtDTI& DTI, bool IsKindOf);
    cpComponent* find(MT_CTSTR name);
    void deleteComponent();
    cpComponent* getComponent(u32 index);
    u32 getComponentNum();
    void setComponent(cpComponent* pComp, u32 index);
    void setComponentNum(u32);
protected:
    cpRootComponent* mpRootComponent;  // offset: 0x8
    MtObject* mpOwner;  // offset: 0x10
public:
    static MyDTI DTI;
};
