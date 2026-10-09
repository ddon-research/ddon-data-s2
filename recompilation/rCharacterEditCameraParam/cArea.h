#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class rArchive;

// Declarations
class cArea;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cArea : public MtObject
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
    cArea();
    virtual ~cArea();
    bool isInit();
    cArea* getChild();
    const cArea* getChild() const;
    cArea* getParent();
    const cArea* getParent() const;
    virtual bool load();  // vtable slot 6
    // Address: 0x01b5b9d0 - 0x01b5b9d1 (1 bytes)
    virtual void init() {}  // vtable slot 7
    // Address: 0x0194fce0 - 0x0194fce1 (1 bytes)
    virtual void move() {}  // vtable slot 8
    virtual void final();  // vtable slot 9
    virtual const MtDTI& getParentType();  // vtable slot 10
    virtual MT_CTSTR getName();  // vtable slot 11
    virtual MT_CTSTR getShaderSegment();  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    void lock();
    void unlock();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
protected:
    union
    {
    public:
        u32 mRno;  // offset: 0x0
        struct
        {
        public:
            u32 mRno0 : 8;  // offset: 0x0
            u32 mRno1 : 8;  // offset: 0x0
            u32 mRno2 : 8;  // offset: 0x0
            u32 mRno3 : 8;  // offset: 0x0
        };  // offset: 0x0
    };  // offset: 0x8
private:
    MtCriticalSection mCs;  // offset: 0x10
    bool mInit;  // offset: 0x18
    s32 mAreaPt;  // offset: 0x1c
    MtString mSegmentName;  // offset: 0x20
    rArchive* mpShaderArchive;  // offset: 0x28
public:
    static MyDTI DTI;
private:
    static MtAllocator* mpAllocator;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool cArea::isInit() {
    return this->mInit;
}
