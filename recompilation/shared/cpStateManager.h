#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cState.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cState;
class cStateInfo;
class uDDOModel;

// Declarations
class cpStateManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpStateManager : public cpComponent
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
    cpStateManager();
    virtual ~cpStateManager();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void addState(s32 state, const MtDTI* pDti);
    virtual void setup();  // vtable slot 6
    void update();
    virtual void updatePtr();  // vtable slot 9
    virtual void kill();  // vtable slot 8
    void setState(s32 state);
    s32 getStateNo();
    const cState* getCurrentState();
public:
    uDDOModel* mpModel;  // offset: 0x50
    MtTypedArray<cStateInfo> mArray;  // offset: 0x58
    cState* mpCurrentState;  // offset: 0x78
    static MyDTI DTI;
    static const s32 INVALID_STATE = -1;
};
