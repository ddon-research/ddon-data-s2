#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cOmComponent.h"
#include "uSwingModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cDraw;
class cOmComponent;
class cOmControl;
class cOmTreeControl;
class cpEffectProvider;

// Declarations
class uOmSwingModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uOmSwingModel : public uSwingModel
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
    uOmSwingModel();
    virtual ~uOmSwingModel();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updateEfcHandle();  // vtable slot 38
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    u32 getUId() const;
    void setUId(u32);
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void updateLodDistance();  // vtable slot 39
    virtual f32 getLodDist(f32 vdist, const MtVector3& cpos);  // vtable slot 37
public:
    cOmComponent mOmComp;  // offset: 0x11e8
    s32 mOmID;  // offset: 0x12c0
    cOmControl* mpControl;  // offset: 0x12c8
    cOmTreeControl* mpTree;  // offset: 0x12d0
    cpEffectProvider* mpcPrv;  // offset: 0x12d8
    static MyDTI DTI;
};
