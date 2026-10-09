#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nObjCondition.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cpOcdCtrl;

// Declarations
class cOcdCache;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cOcdCache : public MtObject
{
    // inferred: cpOcdCtrl::checkOcdDamageCache names cOcdCache::mReason
    friend class cpOcdCtrl;
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
    cOcdCache();
    virtual ~cOcdCache();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool isActive() const;
    void setActive(bool);
    nObjCondition::OCD_REASON getReason() const;
    void setReason(nObjCondition::OCD_REASON);
    f32 getTimer() const;
    void setTimer(f32);
    void clear();
    void update(f32 deltaTime);
    void copy(const cOcdCache& src);
private:
    bool mIsActive;  // offset: 0x8
    nObjCondition::OCD_REASON mReason;  // offset: 0xc
    f32 mTimer;  // offset: 0x10
public:
    static MyDTI DTI;
};
