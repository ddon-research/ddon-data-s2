#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "nCollision.h"
#include "rCollision.h"
#include "sCollision.h"
#include "uScrollCollision.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCapsule;
class MtDTI;
class MtGeomConvex;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtSphere;
class MtVector3;
class cDraw;
class cResource;
namespace nCollision { class cScrCollisionMoveMatrix; }
namespace nCollision { class cScrCommonFilter; }
class rCollisionObj;
class rGeometry2;
class rGeometry3;

// Declarations
class uScrollCollisionGeometry;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uScrollCollisionGeometry : public uScrollCollision
{
public:
    class MyDTI;
    class cGeometryInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cGeometryInfo : public MtObject
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
        cGeometryInfo(uScrollCollisionGeometry* pOwner, u32 ElementID);
        virtual ~cGeometryInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setGeomConvexType(u32 GeometryType);
        u32 getGeomConvexType() const;
        MtGeomConvex* getGeomConvex();
        const MtGeomConvex* getGeomConvexConst() const;
        void setGeomConvex(MtGeomConvex* pNewGeomConvex);
        void copyGeomConvex(MtGeomConvex& NewGeomConvex);
        rCollision::MaterialInfo& getGeomConvexMaterial();
        const rCollision::MaterialInfo& getGeomConvexMaterialConst() const;
        void setGeomConvexMaterial(const rCollision::MaterialInfo& Material);
        void registOwner(uScrollCollisionGeometry* pOwner, u32 ElementIndex);
        void setElementIndex(u32);
        u32 getElementIndex();
        bool isActive() const;
        void setActive(bool FlgActive);
        const MtAABB& getBoundingAABB() const;
        void updateBoundingAABB();
        const uScrollCollisionGeometry::cGeometryInfo& operator=(const uScrollCollisionGeometry::cGeometryInfo& src);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        uScrollCollisionGeometry* mpOwner;  // offset: 0x8
        u32 mElementIndex;  // offset: 0x10
        MtGeomConvex* mpGeomConvex;  // offset: 0x18
        MtAABB mBoundingAABB;  // offset: 0x20
        rCollision::MaterialInfo mGeomMaterialInfo;  // offset: 0x40
        bool mFlgActive;  // offset: 0x60
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
    uScrollCollisionGeometry();
    virtual ~uScrollCollisionGeometry();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void removeFromCollisionSystem();
    cGeometryInfo& addGeometry(const MtGeomConvex& GeomConvex, const rCollision::MaterialInfo& Material);
    MtGeomConvex* getGeometry(u32 GeometryIndex);
    const MtGeomConvex* getGeometryConst(u32 GeometryIndex) const;
    const MtAABB* getGeometryBoundingAABBConst(u32 GeometryIndex) const;
    cGeometryInfo& getGeometryInfo(u32 GeometryIndex);
    cGeometryInfo& setGeometryInfo(const MtGeomConvex& GeomConvex, const rCollision::MaterialInfo& Material, u32 GeometryIndex);
    const cGeometryInfo& getGeometryInfoConst(u32 GeometryIndex) const;
    bool isGeometryActive(u32 GeometryIndex) const;
    void setGeometryActive(bool FlgActive, u32 GeometryIndex);
    u32 getGeometryInfoNum() const;
    void setGeometryInfoNum(u32 NewGeometryNum);
    rCollision::MaterialInfo* getGeometryMaterial(u32 GeometryIndex);
    const rCollision::MaterialInfo* getGeometryMaterialConst(u32 GeometryIndex) const;
    void setGeometryMaterial(const rCollision::MaterialInfo& Material, u32 GeometryIndex);
    bool isMoveByScrMatrix();
    bool isResetSetByScrMatrix();
    bool isEnableStopSetControl() const;
    void setEnableStopSetControl(bool FlgStopSetControl);
    void setMatrix(const MtMatrix&, bool);
    void setScrMoveAndStopMatrix(const MtMatrix&);
    void setScrMovingMatrix(const MtMatrix&);
    void setScrMoveMatrix(const MtMatrix& MoveMatrix, bool FlgStopSet);
    void setScrMoveMatrixForUI(const MtMatrix& MoveMatrix);
    const MtMatrix& getMatrix() const;
    const MtMatrix& getScrMoveMatrixNow() const;
    const MtMatrix& getScrMoveMatrixOld() const;
    const MtMatrix& getScrMoveMatrixByID(u32 MoveMatrixID) const;
    const MtMatrix& getScrMoveMatrixInverseNow() const;
    const MtMatrix& getScrMoveMatrixInverseOld() const;
    const MtMatrix& getScrMoveMatrixInverseByID(u32 MoveMatrixID) const;
    MtMatrix getMatrixForUI();
    void resetScrMoveMatrix();
    bool isActiveGeomtry(u32 GeometryIndex);
    void setActiveGeomtry(bool set, u32 GeometryIndex);
    void setScrFilter(const nCollision::cScrCommonFilter& ScrFilter);
    u32 getScrType();
    void setScrType(u32 type);
    u32 getScrGroup();
    u8 getScrGroupIndex();
    void setScrGroup(u8 group);
    bool isScrTarget(u32 TargetType, u32 TargetGroup);
    bool importResource(rCollisionObj* pResourceObj);
    bool importResource(rGeometry2* pResourceGeometry);
    bool importResource(rGeometry3* pResourceGeometry, u32 index);
    bool exportResource(MT_CTSTR OutputFileName, u32 ExportType);
    bool isEnableOwner();
    void registOwner(MtObject* pOwner);
    void unregistOwner();
    MtObject* getOwner();
    bool isEnablePlusData();
    void registPlusData(MtObject* pPlusData);
    void unregistPlusData();
    MtObject* getPlusData();
    MtAABB getBoundingAABBLocal();
    MtSphere getBoundingSphereLocal();
    MtCapsule getBoundingCapsuleLocal();
    const MtAABB& getBoundingAABB();
    void updateBoundingAABB();
    bool isEnableAutoSync();
    void setEnableAutoSync(bool FlgEnableSet);
    bool isEnableAutoSyncMove();
    void setEnableAutoSyncMove(bool FlgEnableSet);
    void* memAlloc(size_t s);
    void memFree(void* padr);
    size_t memSize(void*);
protected:
    void moveForSystem();
    void syncOwner();
    u32 setScrMoveMatrixForSystem();
    cGeometryInfo& getGeometryInfoCore(u32 GeometryIndex);
    const cGeometryInfo& getGeometryInfoCoreConst(u32 GeometryIndex) const;
    cGeometryInfo* createNewGeometryInfo();
    void saveImportResource(cResource& ImportResource);
    void applyWorldOffsetByAbsoluteWithCollisionObj(const MtVector3& absolute_offset);
    void applyWorldOffsetByAbsoluteWithGeometry2(const MtVector3& absolute_offset);
    void applyWorldOffsetByAbsoluteWithGeometry3(const MtVector3& absolute_offset);
    void applyWorldOffsetByDifference(const MtVector3& offset);
protected:
    MtObject* mpOwner;  // offset: 0x48
    MtObject* mpPlusData;  // offset: 0x50
    MtTypedArray<cGeometryInfo> mColliderGeometryArray;  // offset: 0x58
    sCollision::SbcObject::cRegisterInfo* mpScrollRegisterInfo;  // offset: 0x78
    MtAABB mBoundingAABB;  // offset: 0x80
    nCollision::cScrCommonFilter mScrFilter;  // offset: 0xa0
    nCollision::cScrCollisionMoveMatrix mScrMatrix;  // offset: 0xb8
    cResource* mpImportResource;  // offset: 0x100
    u32 mGeometry3UseGroupIndex;  // offset: 0x108
    MtMatrix mReserveMatrix;  // offset: 0x110
    bool mFlgReserveResetSet;  // offset: 0x150
    bool mFlgReserveMatrixSet;  // offset: 0x151
    bool mFlgAutoSync;  // offset: 0x152
    bool mFlgAutoSyncEnableMove;  // offset: 0x153
    MtVector3* mpAutoSyncBeforeParentPos;  // offset: 0x158
    MtQuaternion* mpAutoSyncBeforeParentQt;  // offset: 0x160
    bool mFlgAlwayUpdate;  // offset: 0x168
    bool mFlgUpdateOnce;  // offset: 0x169
    bool mFlgStopSet;  // offset: 0x16a
    bool mFlgEnableOwner;  // offset: 0x16b
    bool mFlgOwnerUCoord;  // offset: 0x16c
    bool mFlgOwnerUnit;  // offset: 0x16d
    bool mFlgStopSetControl;  // offset: 0x16e
public:
    static MyDTI DTI;
};
