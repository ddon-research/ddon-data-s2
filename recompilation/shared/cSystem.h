#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;

// Declarations
class cSystem;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSystem : public MtObject
{
public:
    class MyDTI;
    class cAutoCriticalSection;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAutoCriticalSection
    {
    public:
        cAutoCriticalSection(cSystem* p);
        ~cAutoCriticalSection();
    protected:
        cSystem* mpSys;  // offset: 0x0
    };
public:
    static MtDTI* getMyDTIPtr();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    // Address: 0x01abc8e0 - 0x01abc8e1 (1 bytes)
    virtual void reset() {}  // vtable slot 6
    // Address: 0x01abc8f0 - 0x01abc8f1 (1 bytes)
    virtual void move() {}  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01a672a0 - 0x01a672a1 (1 bytes)
    virtual void createMenu(MtPropertyList&) {}  // vtable slot 8
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    // Address: 0x01a672b0 - 0x01a672b1 (1 bytes)
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 9
protected:
    cSystem();
    virtual ~cSystem();
    void lock();
    bool tryLock();
    void unlock();
    void setThreadSafe(bool f);
    bool isThreadSafe();
    static bool isJobSafe();
public:
    static void usage();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
protected:
    static void setJobSafe(bool f);
private:
    MtCriticalSection mCS;  // offset: 0x8
    bool mThreadSafe;  // offset: 0x10
public:
    static MyDTI DTI;
    static const u32 MAX_JOBTHREAD = 6;
private:
    static MtAllocator* mpAllocator;
    static bool mJobSafe;
};
