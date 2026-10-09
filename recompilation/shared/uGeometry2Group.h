#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollisionUtil.h"
#include "MtDTI.h"
#include "nCollision.h"
#include "uGeometry2Base.h"

// Forward declarations
class MtAllocator;
namespace MtCollisionUtil { class MtArrayEx; }
namespace MtCollisionUtil { class MtDtiSelecter; }
class MtDTI;
class MtObject;
class MtPropertyList;
class cDraw;
class cResource;
namespace nCollisionUtil { class cOwnerSystem; }
class rGeometry2Group;
class uGeometry2;
class uModel;

// Declarations
class uGeometry2Group;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using JOBHANDLE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGeometry2Group : public uGeometry2Base
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
    uGeometry2Group();
    virtual ~uGeometry2Group();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    void registOwner(uModel* pOwner);
    void unregistOwner();
    uModel* getRegistOwner() const;
    bool loadResource(rGeometry2Group* pRGeometryGroup);
    bool loadResource(MT_CTSTR RGeometryGroupFilePath);
    rGeometry2Group* getResource() const;
    void restoreGeometryFromResource();
    uGeometry2* getGeometryGroup(u32 GroupIndex);
    u32 getGeometryGroupNum() const;
    bool getGeometryActive(u32 GroupIndex);
    void setGeometryGroupDispAll(bool FlgSetDisp);
    void setGeometryGroupDispAllON();
    void setGeometryGroupDispAllOFF();
    void changeGeometryDTI(const MtDTI* pGeometry2DTI);
    void* memAlloc(size_t s);
    void memFree(void* padr);
    size_t memSize(void*);
protected:
    virtual void evLoadResource();  // vtable slot 24
    void updateGeometry(u32 GeometryIndex);
    void setResourceForUI(cResource* pRGeometryGroup);
    cResource* getResourceForUI();
protected:
    nCollisionUtil::cOwnerSystem mOwnerSystem;  // offset: 0x48
    MtCollisionUtil::MtArrayEx mGeometryGroupArray;  // offset: 0x60
    rGeometry2Group* mpRGeometryGroup;  // offset: 0x98
    MtCollisionUtil::MtDtiSelecter mGeometryDTI;  // offset: 0xa0
    JOBHANDLE* mpDelayJobHandle;  // offset: 0xb0
    bool mFlgMultiThread;  // offset: 0xb8
    u32 mMultiThreadGroupNumMin;  // offset: 0xbc
public:
    static MyDTI DTI;
    static const u32 MULTI_THREAD_GROUP_NUM_MIN = 10;
};
