#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cHitInfo;
class cHitNode;
class rObjCollision;
class uHuman;

// Declarations
class uCorePointSearch;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uCorePointSearch : public uDDOModel
{
public:
    class MyDTI;
    class cCoreSearchInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCoreSearchInfo : public MtObject
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
        cCoreSearchInfo();
        virtual ~cCoreSearchInfo();
    public:
        rObjCollision* mprColRes;  // offset: 0x8
        u32 mIndex;  // offset: 0x10
        f32 mRadius;  // offset: 0x14
        MtVector3 mOffset0;  // offset: 0x20
        MtVector3 mOffset1;  // offset: 0x30
        static MyDTI DTI;
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
    uCorePointSearch();
    virtual ~uCorePointSearch();
    virtual void updatePtr();  // vtable slot 17
    virtual void createComponent();  // vtable slot 43
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void callbackAttackTest(cHitInfo* pHitInfo);  // vtable slot 85
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 173
    virtual void kill();  // vtable slot 16
    void setOwner(uHuman* pHm);
    void initCoreSearch(const cCoreSearchInfo& info);
private:
    cHitNode* mpNode;  // offset: 0x2470
    uHuman* mpOwnerHm;  // offset: 0x2478
    f32 mRadius;  // offset: 0x2480
    MtVector3 mOffset0;  // offset: 0x2490
    MtVector3 mOffset1;  // offset: 0x24a0
public:
    static MyDTI DTI;
};
