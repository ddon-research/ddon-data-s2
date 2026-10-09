#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cDynamicBVHCollision.h"
#include "nZone.h"
#include "rZone.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtPropertyList;
class MtQuaternion;
class MtString;
class MtVector3;
class cDynamicBVHCollision;
class cGridCollision;
class cGridCollisionRegistInfo;
class cZoneListener;
namespace nZone { class cContentsPool; }
namespace nZone { class cLayoutElement; }
class rZone;
class sZone;
class uSoundZoneBase;

// Declarations
class cZoneLayout;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cZoneLayout : public MtObject
{
    // inferred: cZoneListener::isRotateZoneLayout names cZoneLayout::mFlgEnableQuaternion
    friend class cZoneListener;
    // inferred: nZone::cLayoutElement::getShapeInfoResource names cZoneLayout::mpNativeResource
    friend class nZone::cLayoutElement;
    // inferred: sZone::applyWorldOffset calls cZoneLayout::applyWorldOffset
    friend class sZone;
    // inferred: uSoundZoneBase::setupFromResource calls cZoneLayout::applyWorldOffset
    friend class uSoundZoneBase;
public:
    class MyDTI;
    class cInGameGroupManager;
    class cDynamicBVHMaster;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cInGameGroupManager : public MtObject
    {
        // inferred: cZoneLayout::getGlobalLayoutElementNum names cZoneLayout::cInGameGroupManager::mpResourceGroupManager
        friend class cZoneLayout;
        // inferred: nZone::cLayoutElement::isEnable names cZoneLayout::cInGameGroupManager::mFlgEnable
        friend class nZone::cLayoutElement;
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
        cInGameGroupManager();
        virtual ~cInGameGroupManager();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void move();  // vtable slot 6
        u32 getIndex() const;
        MtObject* getUserOwner() const;
        void registerUserOwner(MtObject*);
        cZoneLayout* getSystemOwner() const;
        nZone::cLayoutElement* getGroupLayoutElementFromIndex(u32 index) const;
        s32 getGroupID() const;
        bool isNoGroupLayoutManager() const;
        s32 getGroupLayoutIndex(u32 index) const;
        u32 getGroupLayoutIndexNum() const;
        s32 getGroupGlobalLayoutIndex(u32 index) const;
        u32 getGroupGlobalLayoutIndexNum() const;
        bool isEnable() const;
        void setEnable(bool enable);
        void setLayoutEnableAll(bool enable);
        cGridCollisionRegistInfo* getGridRegisterInfoFromResource(nZone::cLayoutElement& src);
        cGridCollision* getGrid() const;
        cDynamicBVHCollision* getDynamicBVH();
        bool isEnableStopShape() const;
        void requestUpdateDBVT(nZone::cLayoutElement& RequestData);
    private:
        // Address: 0x01b25700 - 0x01b25701 (1 bytes)
        virtual void evRegisterResource() {}  // vtable slot 7
        void registerIndex(u32 index);
        void registerOwner(cZoneLayout* pOwnerLayout);
        void registerResourceGroupManager(rZone::cGroupManager* pOfflineGroupManager);
    private:
        u32 mIndex;  // offset: 0x8
        MtObject* mpUserOwner;  // offset: 0x10
        cZoneLayout* mpSystemOwner;  // offset: 0x18
        rZone::cGroupManager* mpResourceGroupManager;  // offset: 0x20
        bool mFlgEnable;  // offset: 0x28
        cZoneLayout::cDynamicBVHMaster* mpDynamicBvhMaster;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
public:
    class cDynamicBVHMaster : public MtObject
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
        cDynamicBVHMaster();
        virtual ~cDynamicBVHMaster();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void update();
        void requestUpdateDBVT(nZone::cLayoutElement& RequestData, u32 ThreadIndex);
        cDynamicBVHCollision& getDynamicBVH();
        u32 getRegisterNum() const;
    protected:
        cDynamicBVHCollision mDynamicBVH;  // offset: 0x8
        s32 mDynamicBVHRequestNum;  // offset: 0x78
        MtTypedArray<nZone::cLayoutElement> mDBVTUpdateArray[6];  // offset: 0x80
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
    cZoneLayout(const MtDTI* pGroupManagerDTI);
    virtual ~cZoneLayout();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void move();
    void setValueFromResource(rZone* pSourceResource);
    void repairValueFromResource();
    bool isUseResource(rZone* pRZone) const;
    const MtString& getCategoryName() const;
    u32 getCategoryDtiID() const;
    void setLayoutEnableByGroupManager(const cInGameGroupManager& group, bool flag);
    void setLayoutEnableByGroupManagerIndex(u32 GroupManagerIndex, bool flag);
    void setLayoutEnableByGroupID(u32 GroupID, bool flag);
    nZone::cLayoutElement* getLayoutElement(u32 index);
    bool getLayoutElementUniqueID(u32 index, u32& output);
    bool getLayoutElementGroupID(u32 index, s32& output);
    nZone::cLayoutElement* getLayoutElementFromUniqueID(u32 UniqueID);
    u32 getLayoutElementNum() const;
    nZone::cLayoutElement* getGlobalLayoutElement(u32 GlobalShapeIndex);
    u32 getGlobalLayoutElementNum();
    nZone::cLayoutElement* getGlobalLayoutElement(cInGameGroupManager& TargetGroupManager, u32 GlobalShapeIndex);
    u32 getGlobalLayoutElementNum(cInGameGroupManager& TargetGroupManager);
    cInGameGroupManager* getGroupManagerFromLayout(nZone::cLayoutElement& src);
    const cInGameGroupManager* getGroupManagerFromLayoutConst(const nZone::cLayoutElement& src) const;
    cInGameGroupManager* getGroupManagerFromGroupID(s32 GroupID);
    const cInGameGroupManager* getGroupManagerFromGroupIDConst(s32 GroupID) const;
    cInGameGroupManager* getGroupManagerFromIndex(s32 GroupIndex);
    const cInGameGroupManager* getGroupManagerFromIndexConst(s32 GroupIndex) const;
    u32 getGroupManagerNum() const;
    void setLayoutEnableByGroupManager(cInGameGroupManager& group, bool FlgEnable);
    void setLayoutEnableByGroupIndex(u32 GroupIndex, bool FlgEnable);
    const nZone::cLayoutElement* getResourceLayoutElement(const nZone::cLayoutElement& src);
    const nZone::cLayoutElement* getResourceLayoutElementFromUniqueID(const nZone::cLayoutElement&);
    const MtVector3& getWorldOffset() const;
    bool isEnableApplyOffset() const;
    u32 getBroadPhaseMode() const;
    bool isRotate() const;
    const MtQuaternion& getQuaternion() const;
    const MtMatrix& getWorldMatrix() const;
    const MtMatrix& getWorldInverseMatrix() const;
    cGridCollisionRegistInfo* getGridRegisterInfoFromResource(nZone::cLayoutElement& src);
    cGridCollision* getGrid() const;
    cDynamicBVHCollision* getDynamicBVH();
    bool isEnableStopShapeAll() const;
    u32 getIndex() const;
    u32 getHandle() const;
    void setUseRealtimeEdit(bool flag);
    const rZone* getNativeResourceConst() const;
private:
    MT_CTSTR getCategoryNameForProperty() const;
    void setIndex(u32 NewIndexFromSystem);
    void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
    MtVector3 getWorldOffsetForPropDynamic() const;
    MtQuaternion getQuaternionForPropDynamic() const;
    MtVector3 getAngleForUI() const;
    void setAngleForUI(const MtVector3& NewDegreeAngle);
    void setWorldOffset(const MtVector3& NewWorldOffset);
    void addWorldOffset(const MtVector3& AddWorldOffset);
    void setQuaternion(const MtQuaternion& NewZoneQuaternion);
    void mulQuaternion(const MtQuaternion& MulZoneQuaternion);
    void requestUpdateDBVT(nZone::cLayoutElement& RequestData);
private:
    u32 mIndex;  // offset: 0x8
    rZone* mpNativeResource;  // offset: 0x10
    MtVector3 mWorldOffset;  // offset: 0x20
    MtQuaternion mQuaternion;  // offset: 0x30
    MtMatrix mWorldMatrix;  // offset: 0x40
    MtMatrix mWorldInverseMatrix;  // offset: 0x80
    nZone::cLayoutElement* mpLayoutElementArray;  // offset: 0xc0
    u32 mLayoutElementNum;  // offset: 0xc8
    nZone::cContentsPool* mpContentsPool;  // offset: 0xd0
    const MtDTI* mpGroupManagerDTI;  // offset: 0xd8
    MtTypedArray<cInGameGroupManager> mGroupManagerArray;  // offset: 0xe0
    cDynamicBVHMaster* mpDynamicBvhMaster;  // offset: 0x100
    bool mFlgActive;  // offset: 0x108
    bool mFlgEnableApplyOffset;  // offset: 0x109
    bool mFlgEnableQuaternion;  // offset: 0x10a
public:
    static MyDTI DTI;
    static const u32 INVALID_ID;
    static const u32 INVALID_INDEX;
    static const u32 INVALID_HANDLE;
    static const MtString INVALID_PATH;
};
