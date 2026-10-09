#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollisionUtil.h"
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "nCollisionDefine.h"

// Forward declarations
class MtAABB;
class MtAllocator;
namespace MtCollisionUtil { class MtArrayEx; }
namespace MtCollisionUtil { class MtDtiObject; }
class MtColor;
struct MtContact;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtGeomConvex;
class MtObject;
class MtPropertyList;
class MtStream;
class MtString;
class MtVector3;
namespace nCollision { class cGeometryExpansion; }
class rGeometry2;
class uGeometry2;
class uModel;

// Declarations
namespace nCollision { class cCollisionNode; }
namespace nCollision { class cCollisionNodeObject; }
namespace nCollision { class cGeometry; }
namespace nCollision { class cGeometryJointGroup; }
namespace nCollision { class cMotionSequenceSupport; }
namespace nCollision { class cObjectBase; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using u32 = unsigned int;
namespace nCollision { using OBJ_FILTER_FUNC_GEOMETRY_PASSIVE = bool(MtObject::*)(nCollision::cCollisionNode&, u32, void*); }
namespace nCollision { using OBJ_FILTER_FUNC_NODE_PASSIVE = bool(MtObject::*)(nCollision::cCollisionNode&, void*); }
namespace nCollision { using OBJ_HIT_FUNC = void(MtObject::*)(nCollision::cCollisionNode&, nCollision::cCollisionNode&, u32, u32, MtContact&, void*); }
namespace nCollision { using OBJ_HIT_FUNC_FILTERING_GEOMETRY = bool(MtObject::*)(nCollision::cCollisionNode&, nCollision::cCollisionNode&, u32, u32, void*); }
namespace nCollision { using OBJ_HIT_FUNC_FILTERING_NODE = bool(MtObject::*)(nCollision::cCollisionNode&, nCollision::cCollisionNode&, void*); }
namespace nCollision { using OBJ_HIT_FUNC_PASSIVE = void(MtObject::*)(nCollision::cCollisionNode&, u32, MtContact&, void*); }
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using uintptr = __uintptr_t;

namespace nCollision {
    class cMotionSequenceSupport : public ::MtObject
    {
    public:
        enum RULE
        {
            RULE_NONE = 0,
            RULE_EQUAL = 1,
            RULE_AND = 2,
            RULE_NOT_EQUAL = 3,
            RULE_NAND = 4,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cMotionSequenceSupport();
        virtual ~cMotionSequenceSupport();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void initWorkParam();
        bool isActive() const;
        void setActive(bool FlgActive);
        u32 getSequenceCheckRule() const;
        void setSequenceCheckRule(u32 NewRuleCode);
        u32 getTargetMotionListIndex() const;
        void setTargetMotionListIndex(u32 NewMotionListIndex);
        u32 getTargetMotionSequencePageNo() const;
        void setTargetMotionSequencePageNo(u32 TargetPageNo);
        u32 getTargetSequenceSyncBit() const;
        void setTargetSequenceSyncBit(u32 SyncBit);
        bool updateSequence(uModel& TargetModel);
        u32 getBeforeUpdateSquenceBit() const;
        void clearBeforeUpdateSquenceBit();
        bool isEnableSequence() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        bool mFlgActive;  // offset: 0x8
        u32 mBitCheckRule;  // offset: 0xc
        u32 mTargetMotionListIndex;  // offset: 0x10
        u32 mTargetMotionSequencePageNo;  // offset: 0x14
        u32 mTargetSequenceBit;  // offset: 0x18
        u32 mNowSequenceBit;  // offset: 0x1c
        u32 mTargetBeforeMotionNo;  // offset: 0x20
        f32 mTargetBeforeMotionFrame;  // offset: 0x24
    public:
        static MyDTI DTI;
    };
}  // namespace nCollision

namespace nCollision {
    class cObjectBase : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cObjectBase();
        virtual ~cObjectBase();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r, MtStream& in);  // vtable slot 6
        virtual bool save(MtDataWriter& w, MtStream& out);  // vtable slot 7
        virtual void move();  // vtable slot 8
        virtual void copy(const nCollision::cObjectBase& src);  // vtable slot 9
        virtual bool isActive() const;  // vtable slot 10
        virtual void setActive(bool FlgSetActive);  // vtable slot 11
        bool isDisp() const;
        void setDisp(bool FlgDisp);
        bool isDispZTest() const;
        void setDispZTest(bool FlgDisp);
        MT_CTSTR getName() const;
        void setName(const MtString& str);
        nCollision::cObjectBase& operator=(const nCollision::cObjectBase&);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        bool isActiveInterface() const;
        void setActiveInterface(bool);
        void setDummyU32(u32 num);
        void setDummyBool(bool flg);
        void setDummyAABB(MtAABB&);
        void setDummyString(const MtString& str);
    protected:
        bool mFlgActive;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
}  // namespace nCollision

namespace nCollision {
    class cCollisionNode : public nCollision::cObjectBase
    {
        // inferred: rGeometry2::getGeometryNum names nCollision::cCollisionNode::mGeometryArray.::MtArray::mLength
        friend class ::rGeometry2;
        // inferred: uGeometry2::getGeometryNum names uGeometry2::mGeometryArray.::nCollision::cCollisionNode::mGeometryArray.::MtArray::mLength
        friend class ::uGeometry2;
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cCollisionNode(const MtDTI* pEditGeometryDTI);
        virtual ~cCollisionNode();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r, MtStream& in);  // vtable slot 6
        virtual bool save(MtDataWriter& w, MtStream& out);  // vtable slot 7
        virtual void move();  // vtable slot 8
        virtual void copy(const nCollision::cObjectBase& src);  // vtable slot 9
        virtual void copyEx(const nCollision::cCollisionNode& src, bool FlgSkipEditDTI, bool FlgGeometryInsideDataCopy);  // vtable slot 12
        virtual void initialize();  // vtable slot 13
        virtual void setup();  // vtable slot 14
        void updateBoundingAABB();
        virtual u32 addGeometry(MtGeomConvex* pGeomConvex, bool FlgEnableDeepCopy);  // vtable slot 15
        virtual u32 setGeometry(MtGeomConvex* pGeomConvex, u32 RegistArrayIndex, bool FlgEnableDeepCopy);  // vtable slot 16
        virtual u32 insertGeometry(MtGeomConvex* pGeomConvex, u32 RegistArrayIndex, bool FlgEnableDeepCopy);  // vtable slot 17
        virtual MtGeomConvex* getGeometry(u32 TargetGeometryIndex);  // vtable slot 18
        virtual MtGeomConvex* getGeometryConst(u32 TargetGeometryIndex) const;  // vtable slot 19
        virtual bool eraseGeometry(u32 TargetGeometryIndex, bool FlgResize);  // vtable slot 20
        virtual void eraseGeometryAll();  // vtable slot 21
        bool isGeometryRegist(u32 TargetGeometryIndex) const;
        bool isGeometryLocalAllocate(u32 TargetGeometryIndex) const;
        u32 getGeometryNum() const;
        bool isGeometryActive(u32 TargetGeometryIndex) const;
        bool setGeometryActive(bool NextActiveFlag, u32 TargetGeometryIndex);
        void setGeometryActiveAll(bool NextActiveFlag);
        void setGeometryActiveAllTrue();
        void setGeometryActiveAllFalse();
        bool isGeometryDisp(u32 TargetGeometryIndex);
        bool setGeometryDisp(bool NextDispFlag, u32 TargetGeometryIndex);
        void setGeometryDispAll(bool NextDispFlag);
        void setGeometryDispAllTrue();
        void setGeometryDispAllFalse();
        const MtAABB& getBoundingAABB() const;
        const MtAABB* getGeometryBoundingAABB(u32 TargetGeometryIndex) const;
        const MtDTI* getEditDTI() const;
        MT_CTSTR getEditDTIName() const;
        MtColor getDispColor() const;
        void setDispColor(MtColor color);
        bool isSetup() const;
        nCollision::cGeometry* getGeometryClass(u32 TargetIndex);
        const nCollision::cGeometry* getGeometryClassConst(u32 TargetIndex) const;
        bool setGeometryClass(nCollision::cGeometry* pNewGeometry, u32 RegistArrayIndex);
        bool insertGeometryClass(nCollision::cGeometry* pNewGeometry, u32 RegistArrayIndex);
        nCollision::cCollisionNode& operator=(const nCollision::cCollisionNode&);
        virtual void callbackGeometryListMove(MtObject* pTool, u32 ElementIndex);  // vtable slot 22
        virtual void callbackGeometryAdd(u32 ElementIndex);  // vtable slot 23
        virtual void callbackGeometryDelete(u32 ElementIndex);  // vtable slot 24
        // Address: 0x01b85820 - 0x01b85821 (1 bytes)
        virtual void callbackGeometryDeleteSpace() {}  // vtable slot 25
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        bool isSetupMove(bool FlgSetupUpdate);
        void callbackGeometryListMoveInterface(MtObject* pTool, u32 ElementIndex);
        void callbackGeometryInsertTopInterface(u32 ElementIndex);
        void callbackGeometryInsertUnderInterface(u32 ElementIndex);
        void callbackGeometryInsertBottomSpaceInterface(u32 ElementIndex);
        void callbackGeometryDeleteSpaceInterface(u32 ElementIndex);
        void callbackGeometryCopyTopInterface(u32 ElementIndex);
        void callbackGeometryCopyUnderInterface(u32 ElementIndex);
        void callbackGeometryCopyBottomSpaceInterface(u32 ElementIndex);
        void callbackGeometryDeleteResizeInterface(u32 ElementIndex);
        void callbackGeometryDeleteNoResizeInterface(u32 ElementIndex);
    protected:
        const MtDTI* mpEditDTI;  // offset: 0x10
        MtCollisionUtil::MtArrayEx mGeometryArray;  // offset: 0x18
        MtAABB mBoundingAABB;  // offset: 0x50
        MtColor mDispColor;  // offset: 0x70
        bool mFlgSetup;  // offset: 0x74
    public:
        static MyDTI DTI;
    };
}  // namespace nCollision

namespace nCollision {
    class cCollisionNodeObject : public nCollision::cCollisionNode
    {
    public:
        class MyDTI;
        struct HitCheckResult;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct HitCheckResult
        {
        public:
            void intialize();
        public:
            bool FlgGroupOK;  // offset: 0x0
            bool FlgAttributeOK;  // offset: 0x1
            bool FlgTotalAABBOK;  // offset: 0x2
            u16 DetailHitCheckNum;  // offset: 0x4
            u16 DetailHitCheckHitNum;  // offset: 0x6
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
        cCollisionNodeObject();
        virtual ~cCollisionNodeObject();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r, MtStream& in);  // vtable slot 6
        virtual bool save(MtDataWriter& w, MtStream& out);  // vtable slot 7
        virtual void move();  // vtable slot 8
        virtual void copy(const nCollision::cObjectBase& src);  // vtable slot 9
        virtual u32 addGeometry(MtGeomConvex* pGeomConvex, bool FlgEnableDeepCopy);  // vtable slot 15
        virtual u32 setGeometry(MtGeomConvex* pGeomConvex, u32 RegistArrayIndex, bool FlgEnableDeepCopy);  // vtable slot 16
        virtual void initialize();  // vtable slot 13
        virtual void setup();  // vtable slot 14
        virtual void addPropertyCallbackGroup(MtPropertyList& s);  // vtable slot 26
        bool isGeometryActiveByUserID(u32 TargetGeometryUserID) const;
        bool setGeometryActiveByUserID(bool NextActiveFlag, u32 TargetGeometryUserID);
        bool isGeometryDispByUserID(u32 TargetGeometryUserID);
        bool setGeometryDispByUserID(bool NextDispFlag, u32 TargetGeometryUserID);
        HitCheckResult hitCheck(nCollision::cCollisionNodeObject& PassiveNode, nCollision::COLLISION_TYPE CollisionType, MtObject* pCallbackOwnerObj, nCollision::OBJ_HIT_FUNC pCallbackFunc, nCollision::OBJ_HIT_FUNC_FILTERING_NODE pCallbackFuncFilteringNode, nCollision::OBJ_HIT_FUNC_FILTERING_GEOMETRY pCallbackFuncFilteringGeometry, void* pUserSendParam);
        HitCheckResult hitCheck(const MtAABB& HitCheckGeometryAABB, const MtGeomConvex& HitCheckGeometry, nCollision::COLLISION_TYPE CollisionType, MtObject* pCallbackOwnerObj, nCollision::OBJ_HIT_FUNC_PASSIVE pCallbackFunc, nCollision::OBJ_FILTER_FUNC_NODE_PASSIVE pCallbackFuncFilteringNode, nCollision::OBJ_FILTER_FUNC_GEOMETRY_PASSIVE pCallbackFuncFilteringGeometry, void* pUserSendParam, u32 TargetGroup, u32 TargetAttribute, const MtVector3& MoveVector);
        u32 addGeometry(MtGeomConvex* pGeomConvex, u32 GeometryAttribute, u32 GeometryUserID, MtObject* pGeometryUserPtr, bool FlgGeometryLocalAlloc, bool FlgAutoDeleteUserPtr);
        u32 setGeometry(MtGeomConvex* pGeomConvex, u32 RegistGeometryArrayIndex, u32 GeometryAttribute, u32 GeometryUserID, MtObject* pGeometryUserPtr, bool FlgGeometryLocalAlloc, bool FlgAutoDeleteUserPtr);
        u32 getGeometryAttribute(u32 TargetGeometryIndex) const;
        bool setGeometryAttribute(u32 NewAttribute, u32 TargetGeometryIndex);
        u32 getGeometryAttributeByUserID(u32 TargetGeometryUserID) const;
        bool setGeometryAttributeByUserID(u32 NewAttribute, u32 TargetGeometryUserID);
        u32 getGeometryUserID(u32 TargetGeometryIndex) const;
        bool setGeometryUserID(u32 NewUserID, u32 TargetGeometryIndex);
        MtObject* getGeometryUserPtr(u32 TargetGeometryIndex) const;
        bool setGeometryUserPtr(MtObject* pUserPtr, u32 TargetGeometryIndex);
        MtObject* getGeometryUserPtrByUserID(u32 TargetGeometryUserID);
        bool setGeometryUserPtrByUserID(MtObject* pUserPtr, u32 TargetGeometryUserID);
        bool isGeometryAutoDeleteUserPtr(u32 TargetGeometryIndex) const;
        bool setGeometryAutoDeleteUserPtr(bool FlgUsePtrDelete, u32 TargetGeometryIndex);
        bool isGeometryAutoDeleteUserPtrByUserID(u32 TargetGeometryUserID) const;
        bool setGeometryAutoDeleteUserPtrByUserID(bool FlgUsePtrDelete, u32 TargetGeometryUserID);
        const MtVector3& getMoveVector() const;
        void setMoveVector(const MtVector3& _setvec);
        u32 getGroup() const;
        void setGroup(u32 group);
        bool isTargetGroup(u32 TargetGroupFilter) const;
        u32 getAttribute() const;
        void setAttribute(u32 attribute);
        bool isTargetAttribute(u32 TargetAttributeFilter);
        void registOwner(MtObject* pOwner);
        bool isRegistOwner() const;
        MtObject* getOwner() const;
        void registCallbackSetup(MT_MFUNC pSetupFunction);
        bool isRegistCallbackSetup() const;
        MT_MFUNC getCallbackSetup() const;
        u32 getUserDataU32() const;
        void setUserDataU32(u32);
        MtObject* getUserDataPtr() const;
        void setUserDataPtr(MtObject* ptr);
        void unregistUserDataPtr();
        bool isAutoDeleteUserPtr() const;
        void setAutoDeleteUserPtr(bool FlgUsePtrDelete);
        nCollision::cGeometryExpansion* getEditGeometryClass(u32 TargetIndex);
        const nCollision::cGeometryExpansion* getEditGeometryClassConst(u32 TargetIndex) const;
        nCollision::cGeometryExpansion* getEditGeometryClassByUserID(u32 TargetUserID);
        const nCollision::cGeometryExpansion* getEditGeometryClassConstByUserID(u32 TargetUserID) const;
        nCollision::cCollisionNodeObject& operator=(const nCollision::cCollisionNodeObject&);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        uintptr getUserPtrAddr();
    protected:
        MtObject* mpOwner;  // offset: 0x78
        MT_MFUNC mpCallbackFuncSetup;  // offset: 0x80
        u32 mGroup;  // offset: 0x90
        u32 mAttribute;  // offset: 0x94
        MtVector3 mMoveVector;  // offset: 0xa0
        u32 mUserDataU32;  // offset: 0xb0
        MtObject* mpUserDataPtr;  // offset: 0xb8
        bool mFlgAutoDeleteUserDataPtr;  // offset: 0xc0
    public:
        static MyDTI DTI;
        static const u32 DEFAULT_GROUP = 4294967295;
        static const u32 DEFAULT_ATTRIBUTE = 4294967295;
        static const u16 VERSION = 1;
    };
}  // namespace nCollision

namespace nCollision {
    class cGeometry : public nCollision::cObjectBase
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cGeometry();
        virtual ~cGeometry();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r, MtStream& in);  // vtable slot 6
        virtual bool save(MtDataWriter& w, MtStream& out);  // vtable slot 7
        virtual void move();  // vtable slot 8
        virtual void copy(const nCollision::cObjectBase& src);  // vtable slot 9
        virtual void updateBoundingAABB();  // vtable slot 12
        virtual void evGeometryTypeChange();  // vtable slot 13
        virtual void registGeometryByType(u32 GeometryType);  // vtable slot 14
        void registGeometry(MtGeomConvex* pRegistGeomConvex, bool FlgAllocateLocal);
        void unregistGeometry();
        u32 getGeometryType() const;
        MtGeomConvex* getRegistGeometry();
        MtGeomConvex* getRegistGeometryConst() const;
        bool isRegistGeometry() const;
        bool isLocalAllocateRegistGeometry() const;
        bool isIntersect(nCollision::cGeometry& TargetGeometry) const;
        bool getClosest(nCollision::cGeometry& TargetGeometry, MtContact& contact) const;
        bool getClosestXZ(nCollision::cGeometry& TargetGeometry, MtContact& contact) const;
        bool isFind(nCollision::cGeometry& TargetGeometry, const MtVector3& ThisMoveVector, MtContact& contact) const;
        bool isContact(nCollision::cGeometry& TargetGeometry, const MtVector3& ThisMoveVector, const MtVector3& TargetMoveVector, MtContact& contact) const;
        const MtAABB& getBoundingAABB() const;
        MtVector3 getGeomConvexForToolPt0();
        MtVector3 getGeomConvexForToolPt1();
        MtVector3 getGeomConvexForToolPt2();
        void setGeomConvexForToolPt0(const MtVector3&);
        void setGeomConvexForToolPt1(const MtVector3&);
        void setGeomConvexForToolPt2(const MtVector3&);
        MtVector3 getGeomConvexForToolSize();
        void setGeomConvexForToolSize(const MtVector3&);
        MtVector3 getGeomConvexForToolRotate();
        void setGeomConvexForToolRotate(const MtVector3&);
        f32 getGeomConvexForToolPt0X();
        f32 getGeomConvexForToolPt0Y();
        f32 getGeomConvexForToolPt0Z();
        f32 getGeomConvexForToolPt1X();
        f32 getGeomConvexForToolPt1Y();
        f32 getGeomConvexForToolPt1Z();
        f32 getGeomConvexForToolPt2X();
        f32 getGeomConvexForToolPt2Y();
        f32 getGeomConvexForToolPt2Z();
        f32 getGeomConvexForToolSizeX();
        f32 getGeomConvexForToolSizeY();
        f32 getGeomConvexForToolSizeZ();
        f32 getGeomConvexForToolRotateX();
        f32 getGeomConvexForToolRotateY();
        f32 getGeomConvexForToolRotateZ();
        void setGeomConvexForToolPt0X(f32);
        void setGeomConvexForToolPt0Y(f32);
        void setGeomConvexForToolPt0Z(f32);
        void setGeomConvexForToolPt1X(f32);
        void setGeomConvexForToolPt1Y(f32);
        void setGeomConvexForToolPt1Z(f32);
        void setGeomConvexForToolPt2X(f32);
        void setGeomConvexForToolPt2Y(f32);
        void setGeomConvexForToolPt2Z(f32);
        void setGeomConvexForToolSizeX(f32);
        void setGeomConvexForToolSizeY(f32);
        void setGeomConvexForToolSizeZ(f32);
        void setGeomConvexForToolRotateX(f32);
        void setGeomConvexForToolRotateY(f32);
        void setGeomConvexForToolRotateZ(f32);
        nCollision::cGeometry& operator=(const nCollision::cGeometry&);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        bool isRunDetailHitCheck(const nCollision::cGeometry& TargetGeometry) const;
        void registGeometryForUI(MtGeomConvex* pRegistGeomConvex);
        void registGeometryByTypeInterface(u32 GeometryType);
    protected:
        MtGeomConvex* mpGeometry;  // offset: 0x10
        bool mFlgAllocateGeometry;  // offset: 0x18
        MtAABB mGeometryBoundingAABB;  // offset: 0x20
    public:
        static MyDTI DTI;
        static const u32 CONVEX_ENABLE_NONE = 0;
        static const u32 CONVEX_ENABLE_SPHERE = 1;
        static const u32 CONVEX_ENABLE_CAPSULE = 2;
        static const u32 CONVEX_ENABLE_SWEPTSPHRE = 4;
        static const u32 CONVEX_ENABLE_AABB = 8;
        static const u32 CONVEX_ENABLE_OBB = 16;
        static const u32 CONVEX_ENABLE_TRIANGLE = 32;
        static const u32 CONVEX_ENABLE_CYLINDER = 64;
        static const u32 CONVEX_ENABLE_CONVEX_HULL = 128;
        static const u32 CONVEX_ENABLE_ALL = 4294967295;
    };
}  // namespace nCollision

namespace nCollision {
    class cGeometryJointGroup : public nCollision::cCollisionNode
    {
    public:
        enum
        {
            FREE_PARAM_0 = 0,
            FREE_PARAM_1 = 1,
            FREE_PARAM_2 = 2,
            FREE_PARAM_3 = 3,
            FREE_PARAM_MAX = 4,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cGeometryJointGroup(const MtDTI* pEditGeometryDTI);
        virtual ~cGeometryJointGroup();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void copy(const nCollision::cObjectBase& src);  // vtable slot 9
        virtual void move();  // vtable slot 8
        virtual bool isActive() const;  // vtable slot 10
        virtual void setActive(bool FlgSetActive);  // vtable slot 11
        virtual void copyEx(const nCollision::cCollisionNode& src, bool FlgSkipEditDTI, bool FlgGeometryInsideDataCopy);  // vtable slot 12
        virtual void callbackGeometryAdd(u32 ElementIndex);  // vtable slot 23
        virtual void copyEx(const nCollision::cGeometryJointGroup& src, bool FlgGeometryInsideDataCopy, bool FlgCopyFreeFlag, bool FlgCopyFreeSpace);  // vtable slot 26
        void copyRemoveFreeObject(const nCollision::cObjectBase& src);
        u32 getFreeParameter(u32 FreeParameterIndex) const;
        void setFreeParameter(u32 SetParam, u32 FreeParameterIndex);
        MtObject* getFreeObject() const;
        void setFreeObject(MtObject* pObj);
        void setFreeObjectByDTI(const MtDTI* pDti);
        MtObject* getGeometryFreeObject(u32 GeometryIndex);
        void setGeometryFreeObjectByDTI(const MtDTI* pDti);
        MtGeomConvex* getAttachGeometryFromIndex(u32 TargetGeometryIndex) const;
        MtGeomConvex* getLocalGeometryFromIndex(u32 TargetGeometryIndex) const;
        MtGeomConvex* getAttachGeometryFromID(u32 TargetGeometryID) const;
        MtGeomConvex* getLocalGeometryFromID(u32 TargetGeometryID) const;
        u32 getGeometryFreeParameterFromIndex(u32 TargetGeometryIndex, u32 TargetFreeParameterIndex) const;
        void setGeometryFreeParameterFromIndex(u32 SetParam, u32 TargetGeometryIndex, u32 TargetFreeParameterIndex);
        u32 getGeometryFreeParameterFromID(u32 TargetGeometryID, u32 TargetFreeParameterIndex) const;
        void setGeometryFreeParameterFromID(u32 SetParam, u32 TargetGeometryID, u32 TargetFreeParameterIndex);
        MtObject* getGeometryFreeObjectFromIndex(u32 TargetGeometryIndex) const;
        void setGeometryFreeObjectFromIndex(MtObject* pGeometryFreeObject, u32 TargetGeometryIndex);
        MtObject* getGeometryFreeObjectFromID(u32 TargetGeometryID) const;
        void setGeometryFreeObjectFromID(MtObject* pGeometryFreeObject, u32 TargetGeometryID);
        void setGeometryFreeObjectAll(const MtDTI* pGeometryFreeObjectDTI);
        s32 getGeometryAttachJointNo0FromIndex(u32 TargetGeometryIndex) const;
        void setGeometryAttachJointNo0FromIndex(s32 NextAttachJointNo0, u32 TargetGeometryIndex);
        s32 getGeometryAttachJointNo0FromID(u32 TargetGeometryID) const;
        void setGeometryAttachJointNo0FromID(s32 NextAttachJointNo0, u32 TargetGeometryID);
        s32 getGeometryAttachJointNo1FromIndex(u32 TargetGeometryIndex) const;
        void setGeometryAttachJointNo1FromIndex(s32 NextAttachJointNo1, u32 TargetGeometryIndex);
        s32 getGeometryAttachJointNo1FromID(u32 TargetGeometryID) const;
        void setGeometryAttachJointNo1FromID(s32 NextAttachJointNo1, u32 TargetGeometryID);
        void setAttachModel(uModel* pAttachModel);
        uModel* getAttachModel() const;
        void updateAttachGeometry();
        void restoreSweptSphere();
        bool isEnableMotionSequenceSync() const;
        void setEnableMotionSequenceSync(bool FlgEnable);
        nCollision::cMotionSequenceSupport* getSequenceSupportClass();
        u32 getUniqueID() const;
        u32 getGeometryUniqueID(u32 TableIndex) const;
        u32 getGeometryUniqueIDNum() const;
        u32 getGeometryIndexFromID(u32 GeometryID) const;
        void* memAlloc(size_t s);
        void memFree(void* padr);
        size_t memSize(void*);
        void setUniqueID(u32 UniqueID);
    protected:
        void setUniqueIDTableNumForInside(u32 num);
        u32 getUniqueIDTableNumForInside();
        void setUniqueIDTableForInside(u32 UniqueID, u32 TargetIndex);
        u32 getUniqueIDTableForInside(u32 TargetIndex);
    protected:
        u32 mFreeParam[4];  // offset: 0x78
        MtObject* mpFreeObject;  // offset: 0x88
        uModel* mpAttachModel;  // offset: 0x90
        u32 mUniqueID;  // offset: 0x98
        u32 mUniqueIDTableNum;  // offset: 0x9c
        u32* mpUniqueIDTable;  // offset: 0xa0
        nCollision::cMotionSequenceSupport* mpMotionSequenceSupport;  // offset: 0xa8
        MtCollisionUtil::MtDtiObject mGeometryFreeObjectDTI;  // offset: 0xb0
    public:
        static MyDTI DTI;
        static const u32 INVALID_ID = 4294967295;
    };
}  // namespace nCollision
