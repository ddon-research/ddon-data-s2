#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class uDDOModel;

// Declarations
class cpReturnTerritory;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpReturnTerritory : public cpComponent
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
    cpReturnTerritory();
    virtual ~cpReturnTerritory();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    const MtVector3& getHomePoint() const;
    void setHomePoint();
    f32 getHomeRange() const;
    void setHomeRange(f32);
    f32 referenceLimitTimer();
    bool isArrivalHomePoint();
    bool isTimeLimit();
    void resetTimer();
    f32 getReturnTerritoryLimitTime();
    void setReturnTerritoryLimitTime(f32 time);
public:
    uDDOModel* mpModel;  // offset: 0x50
private:
    bool mIsIntoReturn;  // offset: 0x58
    f32 mReturnTerritoryLimitTime;  // offset: 0x5c
    f32 mReturnTerritoryTimer;  // offset: 0x60
    MtVector3 mHomePoint;  // offset: 0x70
    f32 mHomeRange;  // offset: 0x80
public:
    static MyDTI DTI;
};

inline void* cpReturnTerritory::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cpReturnTerritory::resetTimer() {
    this->mIsIntoReturn = true;
    this->mReturnTerritoryTimer = 0.0f;
}

inline void cpReturnTerritory::setReturnTerritoryLimitTime(f32 time) {
    this->mReturnTerritoryLimitTime = time;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpReturnTerritory::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpReturnTerritory::DTI);
}

inline void cpReturnTerritory::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpReturnTerritory::DTI)->memFree(p_addr);
}
