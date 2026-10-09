#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cOnceRequestEffectTypeSuperErosionCamData;
class uEffectExt;
class uEnemy;

// Declarations
class cOnceRequestEffectType;
class cOnceRequestEffectTypeData;
class cOnceRequestEffectTypeSuperErosionCam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cOnceRequestEffectTypeData : public MtObject
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
    virtual void init();  // vtable slot 6
    void setEffect(uEffectExt* set);
    void setPriority(u32 set);
    void setIsDraw(bool set);
    uEffectExt* getEffect();
    u32 getPriority();
    bool getIsDraw();
private:
    uEffectExt* mpEffect;  // offset: 0x8
    u32 mPriority;  // offset: 0x10
    bool mIsDraw;  // offset: 0x14
public:
    static MyDTI DTI;
};

class cOnceRequestEffectType : public MtObject
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
    cOnceRequestEffectType();
    virtual ~cOnceRequestEffectType();
    virtual void init();  // vtable slot 6
    virtual void release();  // vtable slot 7
    virtual void release(u32 Idx);  // vtable slot 8
    virtual void update();  // vtable slot 9
    u32 getDataNum();
    void addData(cOnceRequestEffectTypeData* add);
    void addData(uEffectExt* pEffect);
    void relData(uEffectExt* pEffect);
    cOnceRequestEffectTypeData* getData(u32 idx);
private:
    MtTypedArray<cOnceRequestEffectTypeData> mORETD;  // offset: 0x8
public:
    static MyDTI DTI;
};

class cOnceRequestEffectTypeSuperErosionCam : public cOnceRequestEffectType
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
    virtual void update();  // vtable slot 9
    void addData(cOnceRequestEffectTypeSuperErosionCamData* add);
    void addData(uEffectExt* pEffect, uEnemy* pEnemy);
    void relData(uEffectExt* pEffect, uEnemy* pEnemy);
    bool isDraw(uEffectExt* pEffect);
    cOnceRequestEffectTypeSuperErosionCamData* getData(u32 idx);
public:
    static MyDTI DTI;
};
