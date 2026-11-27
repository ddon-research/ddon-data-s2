#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class rGUI;

// Declarations
class uGUIBazaarPopInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIBazaarPopInfo : public uGUIBase
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
    uGUIBazaarPopInfo();
    virtual ~uGUIBazaarPopInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void move();  // vtable slot 9
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void begin();
    bool isBegin() const;
private:
    void updateInit();
    void updateMove();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    bool mIsBegin;  // offset: 0x8d0
public:
    static MyDTI DTI;
};

inline void* uGUIBazaarPopInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIBazaarPopInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopInfo::DTI);
}

inline void uGUIBazaarPopInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarPopInfo::DTI)->memFree(p_addr);
}
