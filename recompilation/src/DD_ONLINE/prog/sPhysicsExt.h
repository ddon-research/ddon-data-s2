#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/nPhysicsSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
namespace nPhysics { struct INITIALIZE_PARAMETER; }

// Declarations
class sPhysicsExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class sPhysicsExt : public nPhysics::System
{
public:
    enum
    {
        WORLD_CENTER_MODE_NORMAL = 0,
        WORLD_CENTER_MODE_CAMERA = 1,
        WORLD_CENTER_MODE_NUM = 2,
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
    sPhysicsExt(const nPhysics::INITIALIZE_PARAMETER& parameter);
    virtual ~sPhysicsExt();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    u32 getContactArrayIndex();
    void flipContactArrayIndex();
protected:
    void moveWorldCenterNormal();
    void moveWorldCenterCamera();
public:
    u32 mWorldCenterMode;  // offset: 0x9618
protected:
    u32 mContactArrayIndex;  // offset: 0x961c
public:
    static MyDTI DTI;
};

inline void* sPhysicsExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void sPhysicsExt::flipContactArrayIndex() {
    this->mContactArrayIndex = this->mContactArrayIndex ^ 1u;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* sPhysicsExt::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::sPhysicsExt::DTI);
}

inline void sPhysicsExt::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sPhysicsExt::DTI)->memFree(p_addr);
}
