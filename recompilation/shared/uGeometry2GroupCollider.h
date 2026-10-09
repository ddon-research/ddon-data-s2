#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollision.h"
#include "MtCollisionUtil.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "nCollision.h"
#include "sCollision.h"
#include "uGeometry2Base.h"
#include "uGeometry2Collider.h"

// Forward declarations
class MtAllocator;
class MtArray;
namespace MtCollisionUtil { class MtArrayEx; }
struct MtContact;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cDraw;
namespace nCollisionUtil { class cOwnerSystem; }
class uGeometry2Collider;
class uGeometry2Group;
class uModel;

// Declarations
class uGeometry2GroupCollider;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGeometry2GroupCollider : public uGeometry2Base
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
    uGeometry2GroupCollider();
    virtual ~uGeometry2GroupCollider();
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
    void registCallbackFuncSetup(uGeometry2Collider::CALLBACK_COLLIDER_SETUP pCallbackSetup);
    void registCallbackFuncMove(uGeometry2Collider::CALLBACK_COLLIDER_MOVE pCallbackMove);
    void registGeometryGroupUnit(uGeometry2Group* pGeometryGroup);
    uGeometry2Group* getRegistGeometryGroupUnit() const;
    void restoreNodeFromGeometry();
    uGeometry2Collider* getGeometry2Collider(u32 NodeIndex);
    u32 getColliderNodeNum() const;
    void getContactResultAll(MtArray& ResultOutputArray, bool FlgSort, bool FlgSortAll);
    void getContactResult(MtArray& ResultOutputArray, u32 NodeIndex, bool FlgSort, bool FlgSortAll);
    void updatePushStatus();
    const MtVector3& getPushVector() const;
    void* memAlloc(size_t);
    void memFree(void*);
    size_t memSize(void*);
protected:
    void registOwnerChildAll(uModel* pOwner);
    void unregistOwnerChildAll();
protected:
    nCollisionUtil::cOwnerSystem mOwnerSystem;  // offset: 0x48
    uGeometry2Collider::CALLBACK_COLLIDER_SETUP mpCallbackSetup;  // offset: 0x60
    uGeometry2Collider::CALLBACK_COLLIDER_MOVE mpCallbackMove;  // offset: 0x70
    uGeometry2Group* mpGeometryGroupUnit;  // offset: 0x80
    bool mFlgRegistCollider;  // offset: 0x88
    MtCollisionUtil::MtArrayEx mNodeArray;  // offset: 0x90
    MtContact mPushContactResult;  // offset: 0xd0
    MtContact mPushContactResultBefore;  // offset: 0x100
    u32 mPushContactResultBeforeSaveFrmNum;  // offset: 0x130
    f32 mPushPercent;  // offset: 0x134
    MtVector3 mPushVector;  // offset: 0x140
public:
    static MyDTI DTI;
};
