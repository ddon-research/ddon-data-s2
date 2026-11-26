#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cZoneContents.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class cZoneCategoryCheckState;
class cZoneCategoryStatus;
class cZoneCategoryStatusBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cZoneCategoryStatusBase : public cZoneContents
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
    cZoneCategoryStatusBase();
    virtual ~cZoneCategoryStatusBase() {}
public:
    static MyDTI DTI;
};

class cZoneCategoryCheckState : public cZoneCategoryStatusBase
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
    cZoneCategoryCheckState();
    virtual ~cZoneCategoryCheckState();
    u32 getCheckState() const;
    void setCheckState(u32 state);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    u32 mStateBit;  // offset: 0x1c
public:
    static MyDTI DTI;
};

class cZoneCategoryStatus : public cZoneCategoryStatusBase
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
    cZoneCategoryStatus();
    virtual ~cZoneCategoryStatus();
    u32 getChangeStatus() const;
    void setChangeStatus(u32 ocd);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    u32 mChangeStatus;  // offset: 0x1c
public:
    static MyDTI DTI;
};

inline void* cZoneCategoryCheckState::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cZoneCategoryCheckState::cZoneCategoryCheckState() {
    this->mStateBit = 0;
}

inline void* cZoneCategoryStatus::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cZoneCategoryStatus::cZoneCategoryStatus() {
    this->mChangeStatus = 4101;
}

inline void* cZoneCategoryStatusBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
