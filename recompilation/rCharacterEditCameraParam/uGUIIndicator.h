#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cDraw;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUIIndicator;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIIndicator : public uGUIBase
{
public:
    enum
    {
        TYPE_LOAD = 0,
        TYPE_SAVE = 1,
        TYPE_NETWORK = 2,
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
    uGUIIndicator();
    virtual ~uGUIIndicator();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setType(u32 uType);
    void setMessage(MT_CTSTR);
private:
    void updateInit();
    void updateWait();
    void updateExit();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIObjMessage* mpObjMsg;  // offset: 0x8d0
    cGUIObjColorAdjust* mpColAdjust;  // offset: 0x8d8
    u32 mType;  // offset: 0x8e0
    MtString mMessage;  // offset: 0x8e8
public:
    static MyDTI DTI;
};
