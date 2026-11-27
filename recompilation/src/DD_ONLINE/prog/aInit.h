#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cAreaExt.h"
#include "cSystemCheck.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cArcLoaderBase;
class cSystemCheck;

// Declarations
class aInit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class aInit : public cAreaExt
{
public:
    enum
    {
        RNO_0_LOAD_INIT = 0,
        RNO_0_LOAD_MOVE = 1,
    };
    enum
    {
        MOVE_R0_INIT = 0,
        MOVE_R0_SYSTEM_CHECK = 1,
        MOVE_R0_TO_LOGO = 2,
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
    aInit();
    virtual ~aInit();
    virtual bool load();  // vtable slot 6
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
    virtual const MtDTI& getParentType();  // vtable slot 10
    virtual MT_CTSTR getShaderSegment();  // vtable slot 12
private:
    TICKET mArcTicket;  // offset: 0x30
    cSystemCheck mSystemCheck;  // offset: 0x38
public:
    static MyDTI DTI;
};

inline void* aInit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void aInit::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::aInit::DTI)->memFree(p_addr);
}
