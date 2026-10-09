#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cDraw;
class cHitNode;
class uOmModel;

// Declarations
class cpOmLadder;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpOmLadder : public cpComponent
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
    cpOmLadder();
    virtual ~cpOmLadder();
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void compMoveAfter();
    void setupModelUnit();
    // Address: 0x01a5df40 - 0x01a5df41 (1 bytes)
    virtual void draw(cDraw* pDraw) {}  // vtable slot 15
public:
    uOmModel* mpuOm;  // offset: 0x50
    bool mbSetup;  // offset: 0x58
    u32 mHeight;  // offset: 0x5c
    cHitNode* mpHitNode[3];  // offset: 0x60
    f32 mOfsY[24];  // offset: 0x78
    static MyDTI DTI;
    static const u32 UnitNum = 24;
};
