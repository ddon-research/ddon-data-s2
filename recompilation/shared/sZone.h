#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtGeomAABB.h"
#include "MtGeomCapsule.h"
#include "MtGeomCylinder.h"
#include "MtGeomOBB.h"
#include "MtGeomSphere.h"
#include "MtGeomTriangle.h"
#include "MtMath.h"
#include "MtPrimitive3D.h"
#include "cSystem.h"
#include "cZoneLayout.h"
#include "nZone.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtGeomAABB;
class MtGeomCapsule;
class MtGeomConvex;
class MtGeomCylinder;
class MtGeomOBB;
class MtGeomSphere;
class MtGeomTriangle;
class MtGeometry;
class MtLineSegment;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtUI;
class MtVector3;
class cGridCollision;
class cZoneLayout;
class cZoneListener;
namespace nZone { class cLayoutElement; }
class rZone;
class uSoundZoneBase;

// Declarations
class sZone;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using uintptr = __uintptr_t;

class sZone : public cSystem
{
    // inferred: uSoundZoneBase::setupFromResource names sZone::mZoneLayoutArray.::MtArray::mLength
    friend class uSoundZoneBase;
public:
    enum LOCK_TYPE
    {
        LOCK_TYPE_ADD_ZONE_RESOURCE = 0,
        LOCK_TYPE_DELETE_ZONE_RESOURCE = 1,
        LOCK_TYPE_ADD_LISTENER = 2,
        LOCK_TYPE_MOVE_LISTENER = 3,
        LOCK_TYPE_MAX = 4,
    };
    enum
    {
        COLLISION_TYPE_POINT = 0,
        COLLISION_TYPE_LINESEGMENT = 1,
        COLLISION_TYPE_CONVEX = 2,
    };
    enum
    {
        CHECK_PRIORITY_NONE = 0,
        CHECK_PRIORITY_SKIP = 1,
        CHECK_PRIORITY_ARRAY_CLEAR = 2,
    };
    enum DEBUG_DRAW_TYPE
    {
        DEBUG_DRAW_POINT = 0,
        DEBUG_DRAW_LINESEGMENT = 1,
        DEBUG_DRAW_MAX = 2,
    };
public:
    class MyDTI;
    class SearchParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class SearchParam
    {
    public:
        SearchParam(cZoneListener& Listener, MtTypedArray<nZone::cLayoutElement>& HitLayoutArray, u32 _ThreadIndex, u32 UseCollisionType);
        void updateGroupManager(cZoneLayout::cInGameGroupManager& SetGroupManager);
        void clearGroupManager();
        MtGeomAABB& getBroadPhaseAABB();
        cZoneLayout* getTargetZoneLayout();
        u32 getThreadIndex() const;
        MtTypedArray<nZone::cLayoutElement>* getHitArray() const;
        cZoneListener* getTargetListener() const;
        cZoneLayout::cInGameGroupManager* getGroupManager() const;
        u32 getCollisionType() const;
        const MtVector3& getListenerPos() const;
        const MtLineSegment& getListenerLS() const;
        MtGeomConvex* getListenerConvex();
    private:
        MtGeomAABB SearchAABB;  // offset: 0x0
        u32 ThreadIndex;  // offset: 0x30
        MtTypedArray<nZone::cLayoutElement>* pHitArray;  // offset: 0x38
        cZoneListener* pListener;  // offset: 0x40
        cZoneLayout::cInGameGroupManager* pGroupManager;  // offset: 0x48
        u32 CollisionType;  // offset: 0x50
        MtVector3 NowListenerPos;  // offset: 0x60
        MtLineSegment NowListenerLS;  // offset: 0x70
        MtGeomConvex* pNowListenerConvex;  // offset: 0x90
        MtGeomAABB WorkAABB;  // offset: 0xa0
        MtGeomOBB WorkOBB;  // offset: 0xd0
        MtGeomSphere WorkSphere;  // offset: 0x130
        MtGeomCapsule WorkCapsule;  // offset: 0x150
        MtGeomCylinder WorkCylinder;  // offset: 0x190
        MtGeomTriangle WorkTriangle;  // offset: 0x1d0
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
    sZone();
    virtual ~sZone();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    void setWorldOffset(u32 handle, const MtVector3& ofsPos);
    void addWorldOffset(u32, const MtVector3&);
    void applyQuaternion(const MtQuaternion& quaternion, const MtQuaternion& absolute_quaternion);
    bool isRotate(u32 TargetZoneHandle) const;
    const MtQuaternion& getQuaternion(u32 TargetZoneHandle) const;
    void setQuaternion(u32 TargetZoneHandle, const MtQuaternion& NewZoneQuaternion);
    void mulQuaternion(u32 TargetZoneHandle, const MtQuaternion& MulZoneQuaternion);
    const MtMatrix& getWorldMatrix(u32 TargetZoneHandle) const;
    const MtMatrix& getWorldInverseMatrix(u32 TargetZoneHandle) const;
    virtual void setup();  // vtable slot 10
    static sZone* getInstance();
    bool isLockFunc(LOCK_TYPE) const;
    void setLockFunc(LOCK_TYPE, bool);
    u32 addZoneLayout(rZone* pSourceResource, const MtDTI* pGroupManagerDTI);
    void deleteZoneCategory(MT_CTSTR categoryName);
    bool deleteZoneHandle(u32 handle);
    bool deleteZoneHandleByIndex(u32 index);
    void deleteAllZone();
    void resetZoneLayoutByResource(rZone* pReloadTargetResource);
    u32 getZoneLayoutNum() const;
    cZoneLayout* getZoneLayout(u32 index);
    cZoneLayout* getZoneLayoutFromIndex(u32 index);
    const cZoneLayout* getZoneLayoutFromIndex(u32 index) const;
    cZoneLayout* getZoneLayoutFromHandle(u32 handle);
    const cZoneLayout* getZoneLayoutFromHandle(u32 handle) const;
    cZoneLayout* getZoneLayoutFromName(MT_CTSTR categoryName, u32 StartIndex);
    cZoneLayout* getZoneLayoutFromCategoryClassDTI(const MtDTI& CategoryClassDTI, u32 StartIndex);
    bool addListener(cZoneListener* pTargetListener, u32 HitTargetZoneHandle);
    bool addListener(cZoneListener& TargetListener, u32 HitTargetZoneHandle);
    bool addListenerGroupManagerByIndex(cZoneListener* pTargetListener, u32 TargetGroupIndex);
    bool addListenerGroupManagerByID(cZoneListener* pTargetListener, u32 TargetGroupID);
    bool addListenerGroupManagerByIndex(cZoneListener& TargetListener, u32 TargetGroupIndex);
    bool addListenerGroupManagerByID(cZoneListener& TargetListener, u32 TargetGroupID);
    void removeListener(cZoneListener* pTargetListener);
    void removeListener(cZoneListener& TargetListener);
    void removeListenerGroupManager(cZoneListener* pTargetListener);
    void removeListenerGroupManager(cZoneListener& TargetListener);
    bool moveListener(cZoneListener* pListener);
    bool moveListener(cZoneListener& Listener);
    bool moveListenerLineSegment(cZoneListener* pListener);
    bool moveListenerLineSegment(cZoneListener& Listener);
    bool moveListenerConvex(cZoneListener* pListener);
    bool moveListenerConvex(cZoneListener& Listener);
    bool isToolMode() const;
protected:
    u32 callbackHitFoundDynamicShapeByDBVT(MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
    u32 callbackHitFoundStaticShapeByGrid(uintptr UserParam, u32 TargetIndex, uintptr SystemParam);
    u32 callbackHitFoundBroadPhaseMain(SearchParam& param, nZone::cLayoutElement& TargetElement);
    void drawHitResult(cZoneListener& TargetListener, cZoneLayout& TargetZoneLayout, nZone::cLayoutElement& TargetZoneLayoutElement, u32 DrawTargetCode, u32 ThreadIndex);
    void drawHitResult(cZoneLayout& TargetZoneLayout, nZone::cLayoutElement& TargetZoneLayoutElement, const MtVector3& pos, u32 ThreadIndex);
    void drawHitResult(cZoneLayout& TargetZoneLayout, nZone::cLayoutElement& TargetZoneLayoutElement, const MtLineSegment& ls, u32 ThreadIndex);
    void drawHitResultString(cZoneListener& TargetListener, u32 ThreadIndex);
    void drawHitResultString(const MtVector3& TargetPos, u32 ThreadIndex);
    void correctCategoryInfo();
    cZoneLayout* createZoneLayout(rZone* pSourceResource, const MtDTI* pGroupManagerDTI);
    bool deleteZoneLayout(cZoneLayout* pDeleteZoneLayout);
    bool deleteZoneLayoutCoreByIndex(u32 DeleteZoneLayoutIndex);
    u32 getJobThreadIndex() const;
    MtTypedArray<nZone::cLayoutElement>& getJobThreadHitMovementArray(u32 ThreadIndex);
    void clearJobThreadHitMovementArray(nZone::cLayoutElement& ArrayRegisterZoneLayoutElement, cZoneListener& UseZoneListener, u32 ThreadIndex);
    void clearJobThreadHitMovementArrayAll(u32 ThreadIndex);
private:
    bool addListenerGroupManagerMain(cZoneListener& TargetListener, bool FlgUseGroupIndex, u32 TargetGroupParam);
    bool isRegisterValidHandle(cZoneListener& TargetListener) const;
    void lockFunc(LOCK_TYPE type);
    void unlockFunc(LOCK_TYPE type);
    bool runHitLayoutCallback(SearchParam& param, cZoneListener& TargetListener, cZoneLayout& TargetZoneLayout);
    bool moveListenerMainForRuntime(SearchParam& param, cZoneListener& TargetListener, cZoneLayout& TargetZoneLayout, u32 CollisionType);
    bool moveListenerMainForRuntimeGrid(SearchParam& param, cGridCollision& TargetGrid, cZoneListener& TargetListener, cZoneLayout& TargetZoneLayout, cZoneLayout::cInGameGroupManager* pTargetGroupManager, u32 CollisionType);
    bool moveListenerMainForGlobal(SearchParam& param, cZoneListener& TargetListener, cZoneLayout& TargetZoneLayout, cZoneLayout::cInGameGroupManager* pTargetGroupManager, u32 CollisionType);
    bool moveListenerMainForRuntimeGroup(SearchParam& param, cZoneLayout::cInGameGroupManager& TargetGroupManager, cZoneListener& TargetListener, cZoneLayout& TargetZoneLayout, u32 CollisionType);
    bool moveListenerMainForRuntimeAll(SearchParam& param, cZoneListener& TargetListener, cZoneLayout& TargetZoneLayout, u32 CollisionType);
    bool moveListenerMainForNonBroadPhase(SearchParam& param, cZoneListener& TargetListener, cZoneLayout& TargetZoneLayout, u32 CollisionType);
    void sortHitArrayForGroupPriorityCheckByNonGroupBroadPhase(MtTypedArray<nZone::cLayoutElement>& hitLayoutArray);
    u32 checkPriority(cZoneListener& TargetListener, nZone::cLayoutElement& TargetElement, MtTypedArray<nZone::cLayoutElement>& hitLayoutArray);
protected:
    MtTypedArray<cZoneLayout> mZoneLayoutArray;  // offset: 0x18
    u32 mZoneLayoutNum;  // offset: 0x38
    MtTypedArray<nZone::cLayoutElement> mHitMovementArray[19];  // offset: 0x40
    bool mFlgRuntimeLock[4];  // offset: 0x2a0
    u32 mRunCounter[19];  // offset: 0x2a4
public:
    static MyDTI DTI;
    static const u32 ZONE_LAYOUT_MAX_NUM = 32;
protected:
    static sZone* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sZone* sZone::getInstance() {
    return ::sZone::mpInstance;
}
