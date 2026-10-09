#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "nCollision.h"
#include "rGeometry2.h"
#include "uGeometry2Base.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtGeomConvex;
class MtObject;
class MtPropertyList;
class MtVector3;
class cDraw;
class cResource;
namespace nCollisionUtil { class cOwnerSystem; }
class rGeometry2;
class uGeometry2Group;
class uModel;

// Declarations
class uGeometry2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGeometry2 : public uGeometry2Base
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
    uGeometry2();
    virtual ~uGeometry2();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    bool isGeometryDraw() const;
    void setGeometryDraw(bool FlgDraw);
    bool isGeometryActive() const;
    void setGeometryActive(bool FlgActive);
    void registOwner(uModel* pOwner);
    void unregistOwner();
    uModel* getRegistOwner() const;
    bool isEnableParentGeometryGroup() const;
    uGeometry2Group* getParentGeometryGroup() const;
    void setParentGeometryGroup(uGeometry2Group* pNewParent);
    bool loadResource(rGeometry2* pRGeometry2);
    bool loadResource(MT_CTSTR RGeometry2FilePath);
    rGeometry2* getResource() const;
    void restoreGeometryFromResource();
    void updateAttachGeometry();
    u32 getGeometryNum() const;
    MtObject* getAddonObject();
    MtGeomConvex* getAttachGeometry(u32 TargetGeometryIndex) const;
    MtObject* getGeometryAddonObject(u32 TargetGeometryIndex) const;
    s32 getGeometryAttachJointNo0(u32 TargetGeometryIndex) const;
    void setGeometryAttachJointNo0(u32 TargetGeometryIndex, s32 NextAttachJointNo0);
    s32 getGeometryAttachJointNo1(u32 TargetGeometryIndex) const;
    void setGeometryAttachJointNo1(u32 TargetGeometryIndex, s32 NextAttachJointNo1);
    rGeometry2::cGeometryArray& getGeometryArray();
protected:
    virtual void evLoadResource();  // vtable slot 24
    void setResourceForUI(cResource* pRGeometry2);
    cResource* getResourceForUI();
    void setDummyU32(u32);
protected:
    nCollisionUtil::cOwnerSystem mOwnerSystem;  // offset: 0x48
    rGeometry2::cGeometryArray mGeometryArray;  // offset: 0x60
    rGeometry2* mpRGeometry2;  // offset: 0x100
    uGeometry2Group* mpGeometryGroupUnit;  // offset: 0x108
public:
    static MyDTI DTI;
};
