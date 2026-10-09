#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cDraw;
class cGUIInstAnimation;
class rGUI;

// Declarations
class uGUIMousePointer;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMousePointer : public uGUIBase
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
    uGUIMousePointer();
    virtual ~uGUIMousePointer();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setAnmType(u32 uAnmType);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    bool checkDraw();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstAnimation* mpInstAnim;  // offset: 0x8d0
    f32 mAlpha;  // offset: 0x8d8
    f32 mRemainingTime;  // offset: 0x8dc
    f32 mRemainingTimeMax;  // offset: 0x8e0
public:
    static MyDTI DTI;
};
