#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "sMouse.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class sMouseExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class sMouseExt : public sMouse
{
public:
    enum BUTTON_EX
    {
        BUTTON_EX_NOTHING = 0,
        BUTTON_EX_L = 1,
        BUTTON_EX_R = 2,
        BUTTON_EX_M = 4,
        BUTTON_EX_3 = 8,
        BUTTON_EX_4 = 16,
        BUTTON_EX_5 = 32,
        BUTTON_EX_6 = 64,
        BUTTON_EX_7 = 128,
        BUTTON_EX_WF = 4096,
        BUTTON_EX_WB = 8192,
    };
public:
    class MyDTI;
    struct STATE_EXT;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct STATE_EXT
    {
    public:
        u32 on;  // offset: 0x0
        u32 old;  // offset: 0x4
        u32 trg;  // offset: 0x8
        u32 release;  // offset: 0xc
        u32 rep;  // offset: 0x10
        u32 change;  // offset: 0x14
        u64 rep_timer[2];  // offset: 0x18
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
    sMouseExt();
    virtual ~sMouseExt();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
    void resetStateExt();
    sMouse::TYPE getCurrentType();
    bool isConnect();
    u32 getOn(sMouse::TYPE type) const;
    u32 getOld(sMouse::TYPE type) const;
    u32 getTrigger(sMouse::TYPE type) const;
    u32 getRelease(sMouse::TYPE type) const;
    u32 getChange(sMouse::TYPE type) const;
    u32 getRepeat(sMouse::TYPE type) const;
public:
    STATE_EXT mStateExt;  // offset: 0xaa8
    static MyDTI DTI;
};
