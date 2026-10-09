#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cUIObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class uDDOModel;

// Declarations
class cPcTouchAction;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPcTouchAction : public cUIObject
{
public:
    enum
    {
        RNO_NONE = 0,
        RNO_MOVE = 1,
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
    cPcTouchAction();
    virtual ~cPcTouchAction();
    void updatePtr();
    void init(uDDOModel* pOwner, uDDOModel* pTarget);
    void move();
private:
    void final();
private:
    u32 mRno;  // offset: 0x8
    uDDOModel* mpOwner;  // offset: 0x10
    uDDOModel* mpTarget;  // offset: 0x18
public:
    static MyDTI DTI;
};
