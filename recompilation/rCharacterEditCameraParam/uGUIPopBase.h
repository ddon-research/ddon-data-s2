#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cControl.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtSize;
class MtVector3;
class uGUIBase;

// Declarations
class uGUIPopBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopBase : public uGUIsMenuBase
{
public:
    enum MODE
    {
        MODE_DEFAULT = 0,
        MODE_DISABLE = 1,
    };
public:
    class MyDTI;
public:
    using DATA_FUNC = u32(MtObject::*)(MtObject*, MtObject*);
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
    uGUIPopBase(u32 initFlags, bool isChatSubMenu);
    virtual ~uGUIPopBase();
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void kill();  // vtable slot 16
    virtual void end();  // vtable slot 79
    virtual void setSleepUnit(uGUIBase* p);  // vtable slot 96
    void setOffset(const MtVector3&);
    void setReverse(bool);
    virtual MtSize getWindowSize();  // vtable slot 97
    void setOutsidePriority(u32 n);
    u32 getOutsidePriority();
    void setGUIParent(uGUIBase*);
protected:
    u32 evCtrlDummy(cControl::Message*);
protected:
    u32 mOutsidePriorty;  // offset: 0x958
private:
    uGUIBase* mpSleepUnit;  // offset: 0x960
    uGUIBase* mpGUIParent;  // offset: 0x968
    MtVector3 mOffset;  // offset: 0x970
    bool mReverse;  // offset: 0x980
    bool mInit;  // offset: 0x981
    bool mIsParentKillMode;  // offset: 0x982
public:
    static MyDTI DTI;
};
