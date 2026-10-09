#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cUnit.h"
#include "nCollisionNode.h"
#include "sCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cDraw;
class cResource;
namespace nCollision { class cGeometryJointGroup; }
class rGeometry3;
class uModel;

// Declarations
class uGeometry3;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGeometry3 : public cUnit
{
public:
    enum
    {
        USER_PTR_DEFAULT = 0,
        USER_PTR_NOACCESS = 1,
        USER_PTR_FREESPACE_OBJECT = 2,
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
    uGeometry3();
    virtual ~uGeometry3();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    void registAttachModel(uModel* pAttachModel);
    void unregistAttachModel();
    uModel* getAttachModel() const;
    bool isActive() const;
    void setActive(bool FlgActive);
    void restoreSweptSphere();
    bool loadResource(rGeometry3* pRGeometry);
    bool loadResource(MT_CTSTR ResourcePath);
    rGeometry3* getResource() const;
    void restoreGeometryFromResource();
    bool isNoResourceMode() const;
    bool isUseGroupID() const;
    bool isUseGroupIndex() const;
    void setUseTargetGroupID(u32 NewTargetGroupID);
    void setUseTargetGroupIndex(u32 NewTargetGroupIndex);
    u32 getUseGroupID() const;
    void setUseGroupID(u32 NewTargetGroupID);
    u32 getUseGroupIndex() const;
    void setUseGroupIndex(u32 NewGroupIndex);
    nCollision::cGeometryJointGroup& getUseGeometryArray();
    const nCollision::cGeometryJointGroup* getUseGeometryArrayFromResource();
    bool isEnableTargetGeometryArrayFromResource(bool FlgTargetGroup, u32 TargetParam);
    sCollision::Node* makeNewColliderNode(const MtDTI& NodeClassDTI);
    void entrustColliderNode(sCollision::Node& EntrustNode);
    void setGeometryToColliderNode(sCollision::Node* pTargetNode);
    sCollision::Node* getEntrustColliderNode();
    u32 getUserPtrUseMode(u32) const;
    void setUserPtrUseMode(u32);
    void drawGeometry();
protected:
    void makeNewColliderNodeForUI();
    void setResourceForUI(cResource* pRGeometry);
    cResource* getResourceForUI();
    bool isHideUI_GroupID();
    bool isHideUI_GroupIndex();
    void setDummyU32(u32);
protected:
    rGeometry3* mpRGeometry;  // offset: 0x48
    nCollision::cGeometryJointGroup mGeometryGroup;  // offset: 0x50
    sCollision::Node* mpColliderNode;  // offset: 0x110
    u32 mUseGroupID;  // offset: 0x118
    u32 mUseGroupIndex;  // offset: 0x11c
    bool mFlgUseGroupID;  // offset: 0x120
    u32 mUserPtrUseMode;  // offset: 0x124
public:
    static MyDTI DTI;
};
