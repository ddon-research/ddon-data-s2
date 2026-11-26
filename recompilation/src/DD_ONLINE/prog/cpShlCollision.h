#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class cShlParamCompCollision;
class cpShlCollision;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamCompCollision : public cShlParamComponent
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
    virtual const MtDTI& getComponentDTI() const;  // vtable slot 6
    cShlParamCompCollision();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamComponent* pParamBase);  // vtable slot 7
public:
    s32 seq_0;  // offset: 0x8
    s32 at_0;  // offset: 0xc
    s32 shared_uid_0;  // offset: 0x10
    f32 colTimer_0;  // offset: 0x14
    s32 seq_1;  // offset: 0x18
    s32 at_1;  // offset: 0x1c
    s32 shared_uid_1;  // offset: 0x20
    f32 colTimer_1;  // offset: 0x24
    s32 seq_2;  // offset: 0x28
    s32 at_2;  // offset: 0x2c
    s32 shared_uid_2;  // offset: 0x30
    static MyDTI DTI;
};

class cpShlCollision : public cpShlBase
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
public:
    static MyDTI DTI;
};

inline void* cShlParamCompCollision::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCompCollision::cShlParamCompCollision() {
    this->seq_0 = -1;
    this->at_0 = -1;
    this->shared_uid_0 = -1;
    this->colTimer_0 = 500.0f;
    this->seq_1 = -1;
    this->at_1 = -1;
    this->shared_uid_1 = -1;
    this->colTimer_1 = 1000.0f;
    this->seq_2 = -1;
    this->at_2 = -1;
    this->shared_uid_2 = -1;
}

inline void* cpShlCollision::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
