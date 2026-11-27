#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uGUIServerUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class uGUISystemMsg;

// Declarations
class uGUIServerUIDialog;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIServerUIDialog : public uGUIServerUIBase
{
public:
    enum
    {
        MODE_DEFAULT = 0,
        MODE_LIST = 1,
        MODE_SELECT = 2,
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
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    uGUIServerUIDialog(u32 mode);
    virtual ~uGUIServerUIDialog();
private:
    void initDialog();
    void updateInit();
    void updateWait();
    void updateExit();
private:
    u32 mMode;  // offset: 0x95c
    s32 mCancelPos;  // offset: 0x960
    uGUISystemMsg* mpDialog;  // offset: 0x968
public:
    static MyDTI DTI;
};

inline void* uGUIServerUIDialog::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIServerUIDialog::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIServerUIDialog::DTI);
}

inline void uGUIServerUIDialog::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIServerUIDialog::DTI)->memFree(p_addr);
}
