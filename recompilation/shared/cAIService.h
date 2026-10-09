#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "MtSynchronize.h"
#include "cAIObject.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;

// Declarations
class cAIService;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cAIService : public cAIObject
{
public:
    enum ATTRIBUTE
    {
        ATTR_MOVE_AFTER = 1,
        ATTR_PAUSE_MAIN = 2,
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
    cAIService();
    virtual ~cAIService();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01bc7b00 - 0x01bc7b01 (1 bytes)
    virtual void reset() {}  // vtable slot 6
    // Address: 0x01b6bc30 - 0x01b6bc31 (1 bytes)
    virtual void move() {}  // vtable slot 7
    // Address: 0x01b6b880 - 0x01b6b881 (1 bytes)
    virtual void drawDebug() {}  // vtable slot 8
    // Address: 0x01b6b890 - 0x01b6b891 (1 bytes)
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 9
    void setName(MT_CTSTR n);
    MtString& getName();
    void setAttribute(u32);
    u32 checkAttribute(u32);
    u32 getID();
    void lock();
    bool tryLock();
    void unlock();
protected:
    void setID(u32 id);
private:
    MT_CTSTR getDTIName();
    void setDTIName(MT_CTSTR);
private:
    MtString mName;  // offset: 0x8
    u32 mID;  // offset: 0x10
    u32 mAttribute;  // offset: 0x14
    MtCriticalSection mCS;  // offset: 0x18
    cAIService* mpPrevService;  // offset: 0x20
    cAIService* mpNextService;  // offset: 0x28
public:
    static MyDTI DTI;
};
