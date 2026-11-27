#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cEnemyMaterialTable;
class rEnemyMaterialTable;

// Declarations
class cpEnemyMaterial;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpEnemyMaterial : public cpComponent
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
    cpEnemyMaterial();
    virtual ~cpEnemyMaterial();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    void setResource(rEnemyMaterialTable* pRes);
    void playResTableIdx(u32 idx);
private:
    bool play(const cEnemyMaterialTable* pEmEffectTable);
public:
    rEnemyMaterialTable* mpEnemyMaterialTableRes;  // offset: 0x50
    static MyDTI DTI;
};

inline void* cpEnemyMaterial::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpEnemyMaterial::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpEnemyMaterial::DTI);
}

inline void cpEnemyMaterial::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpEnemyMaterial::DTI)->memFree(p_addr);
}
