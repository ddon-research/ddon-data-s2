#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;

// Declarations
class cCorePointMsg;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u16 = unsigned short;
using u32 = unsigned int;

class cCorePointMsg : public MtObject
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
    cCorePointMsg();
    void copy(const cCorePointMsg& msg);
    void setRegionCorePointID(u16 ID);
    u16 getRegionCorePointID() const;
    void setActiveTimer(u16 time);
    u16 getActiveTimer() const;
    void setCreatedTime(t64 time);
    t64 getCreatedTime() const;
    bool isSended() const;
    void notifySended();
    void requestErace();
    bool isEraceRequest() const;
    void setStandby(bool);
    bool isStandby() const;
private:
    s16 mRegionCorePointID;  // offset: 0x8
    s16 mActiveTimer;  // offset: 0xa
    t64 mCreatedTime;  // offset: 0x10
    bool mNetFlag;  // offset: 0x18
    bool mIsErase;  // offset: 0x19
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCorePointMsg::cCorePointMsg() {
    this->mRegionCorePointID = static_cast<s16>(-1);
    this->mActiveTimer = static_cast<s16>(-1);
    this->mCreatedTime = static_cast<t64>(0);
    this->mNetFlag = false;
    this->mIsErase = false;
}
