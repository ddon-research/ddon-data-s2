#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cThinkMgr.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cEnemyLocalShelTable;
class rEnemyLocalShelTable;

// Declarations
class cpEnemyLocalShel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpEnemyLocalShel : public cpComponent
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
    cpEnemyLocalShel();
    virtual ~cpEnemyLocalShel();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    void compMoveAfter();
    void setResource(rEnemyLocalShelTable* pRes);
    void playResTableIdx(u32 idx);
private:
    bool play(const cEnemyLocalShelTable* pEmShelTable);
public:
    rEnemyLocalShelTable* mpEnemyLocalShelTableRes;  // offset: 0x50
private:
    cThinkMgrName::cSyncFlagCtrlName::cSyncFlagCtrl<unsigned int> mcSyncFlag;  // offset: 0x58
public:
    static MyDTI DTI;
};

inline void* cpEnemyLocalShel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpEnemyLocalShel::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpEnemyLocalShel::DTI);
}

inline void cpEnemyLocalShel::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpEnemyLocalShel::DTI)->memFree(p_addr);
}
