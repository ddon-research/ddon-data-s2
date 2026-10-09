#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtCollision.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cUnit.h"
#include "sCollision.h"
#include "uGeometry2Base.h"

// Forward declarations
class MtAllocator;
class MtArray;
struct MtContact;
class MtDTI;
class MtObject;
class MtPropertyList;
class cColliderGeometryParam;
class cColliderNodeParam;
namespace nCollision { class cGeometryExpansion; }
class uGeometry2;
class uModel;

// Declarations
class uGeometry2Collider;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGeometry2Collider : public uGeometry2Base
{
public:
    class MyDTI;
    class cContactInfo;
    class cNodeGeometryInfo;
public:
    using CALLBACK_COLLIDER_SETUP = void(MtObject::*)(sCollision::Node&);
    using CALLBACK_COLLIDER_MOVE = void(MtObject::*)(sCollision::Node&);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cContactInfo : public MtObject
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
        cContactInfo();
        virtual ~cContactInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void initialize(sCollision::Node& HitActiveNode, sCollision::Node& HitPassiveNode, u32 HitActiveNodeGeometryIndex, u32 HitPassiveNodeGeometryIndex, const MtContact& ContactResult);
        const sCollision::Node& getHitActiveNode() const;
        const sCollision::Node& getHitPassiveNode() const;
        u32 getHitActiveNodeGeometryIndex() const;
        u32 getHitPassiveNodeGeometryIndex() const;
        const MtContact& getContactResult() const;
    protected:
        sCollision::Node* mpHitActiveNode;  // offset: 0x8
        sCollision::Node* mpHitPassiveNode;  // offset: 0x10
        u32 mHitActiveNodeGeometryIndex;  // offset: 0x18
        u32 mHitPassiveNodeGeometryIndex;  // offset: 0x1c
        MtContact mContactResult;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    class cNodeGeometryInfo : public cUnit
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
        cNodeGeometryInfo();
        virtual ~cNodeGeometryInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void registGeometry(nCollision::cGeometryExpansion* pGeometry);
        void registGeometryParam(cColliderGeometryParam* pGeometryParam);
    protected:
        nCollision::cGeometryExpansion* mpRegistGeometry;  // offset: 0x48
        cColliderGeometryParam* mpRegistGeometryParam;  // offset: 0x50
    public:
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
    uGeometry2Collider();
    virtual ~uGeometry2Collider();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    sCollision::Node& getColliderNode();
    void registNodeParam(cColliderNodeParam* pNodeParam);
    cColliderNodeParam* getRegistNodeParam();
    void registNode2Collider();
    u32 getContactBufferRunNum() const;
    MtArray* getContactBufferArray(u32 ColliderRunIndex, u32 ThreadID);
    cContactInfo* getContactBuffer(u32 ColliderRunIndex, u32 ThreadID, u32 BufferIndex);
    u32 getContactBufferArrayNum(u32 ColliderRunIndex, u32 ThreadID);
    void eraseContactBufferArrayAll();
    bool isUseActive() const;
    bool isUsePassive() const;
    u32 getUseColliderType() const;
    u32 getUseColliderActiveAttribute() const;
    u32 getUseColliderActiveCollisionTypeID() const;
    void setUseForceActive(bool FlgActive);
    void setUseForcePassive(bool FlgPassive);
    void setUseResourceType(bool FlgUseResourceType);
    void setDefaultType(u32 DefaultType);
    void setUseResourceAttribute(bool FlgUseResourceAttribute);
    void setDefaultAttribute(u32 DefaultAttribute);
    void setFlgUseResourceActiveUseFunctionID(bool FlgUseResourceActiveUseFunctionID);
    void setDefaultActiveUseFunctionID(u32 DefaultActiveUseFunctionID);
    void registOwner(uModel* pOwner);
    uModel* getRegistOwner();
    void unregistOwner();
    void registCallbackFuncSetup(CALLBACK_COLLIDER_SETUP pCallbackSetup);
    void registCallbackFuncMove(CALLBACK_COLLIDER_MOVE pCallbackMove);
    void getContactResult(MtArray& ResultOutputArray, bool FlgSort, bool FlgSortAll);
    void registAttachGeometry(uGeometry2* pGeometry2Unit);
    uGeometry2* getRegistAttachGeometry();
    void restoreNodeFromGeometry();
protected:
    void callbackColliderSetup();
    void callbackColliderCollisionDetect(sCollision::CALLBACK_MODE mode, sCollision::Node* pThisNode, sCollision::Node* pNode, MtContact* pContact, u32 param, sCollision::TriangleInfo* pTriInfo, u32 HitGeomThisID, u32 HitGeomID, bool Hited);
protected:
    uModel* mpOwner;  // offset: 0x48
    CALLBACK_COLLIDER_SETUP mpCallbackSetup;  // offset: 0x50
    CALLBACK_COLLIDER_MOVE mpCallbackMove;  // offset: 0x60
    uGeometry2* mpAttachGeometry;  // offset: 0x70
    sCollision::Node mColliderNode;  // offset: 0x80
    cColliderNodeParam* mpRegistNodeParam;  // offset: 0x160
    MtArray mHitNodeArrayArray;  // offset: 0x168
    bool mFlgForceRegistActive;  // offset: 0x188
    bool mFlgForceRegistPassive;  // offset: 0x189
    bool mFlgUseResourceType;  // offset: 0x18a
    u32 mDefaultType;  // offset: 0x18c
    bool mFlgUseResourceAttribute;  // offset: 0x190
    u32 mDefaultAttribute;  // offset: 0x194
    bool mFlgUseResourceActiveUseFunctionID;  // offset: 0x198
    u32 mDefaultActiveUseFunctionID;  // offset: 0x19c
public:
    static MyDTI DTI;
};
