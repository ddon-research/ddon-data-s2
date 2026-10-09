#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cUIObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cArcLoaderBase;
class uGUIPopTopSel;

// Declarations
class cGUIClanExecutor;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIClanExecutor : public cUIObject
{
public:
    enum PR
    {
        PR_NONE = 0,
        PR_INIT = 1,
        PR_WAIT = 2,
        PR_ARC = 3,
        PR_UNION = 4,
        PR_UNION_GUI = 5,
        PR_UNION_GUI_WAKEUP = 6,
        PR_EXIT = 7,
        PR_STARTEND = 8,
        PR_MAX = 9,
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
    cGUIClanExecutor();
    virtual ~cGUIClanExecutor();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void release();
    virtual void update();  // vtable slot 6
    virtual void updateUnitPtr();  // vtable slot 7
    void start(u32 flags);
    bool isEnd();
    PR getProc();
    uGUIPopTopSel* getPopTopSel() const;
private:
    void setProc(PR pr);
    bool isInit();
private:
    PR mProc;  // offset: 0x8
    PR mOldProc;  // offset: 0xc
    TICKET mArc;  // offset: 0x10
    uGUIPopTopSel* mpUnitTopSel;  // offset: 0x18
    u32 mFlags;  // offset: 0x20
    bool mIsEnd;  // offset: 0x24
    bool mIsInit;  // offset: 0x25
    bool mIsScoutEntryCancel;  // offset: 0x26
public:
    static MyDTI DTI;
    static const u32 FLAG_GAME_MENU = 1;
};
