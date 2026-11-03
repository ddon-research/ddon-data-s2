#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "cDynamicBVHCollision.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtArray;
class MtCapsule;
struct MtContact;
class MtCylinder;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtGeomConvex;
class MtLineSegment;
class MtMatrix;
class MtOBB;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtRay;
class MtSphere;
class MtTriangle;
class MtVector3;
class cSoundGeneratorListener;
class cSoundTriggerListener;
class cZoneContents;
class cZoneLayout;
namespace nCollisionUtil { struct LoadBuffer; }
class uSoundTrigger;

// Declarations
namespace nZone { class ShapeInfoAABB; }
namespace nZone { class ShapeInfoArea; }
namespace nZone { class ShapeInfoBase; }
namespace nZone { class ShapeInfoCapsule; }
namespace nZone { class ShapeInfoCone; }
namespace nZone { class ShapeInfoCylinder; }
namespace nZone { class ShapeInfoGlobal; }
namespace nZone { class ShapeInfoOBB; }
namespace nZone { class ShapeInfoPanel; }
namespace nZone { class ShapeInfoSphere; }
namespace nZone { class cAllocaterIntermediate; }
namespace nZone { class cContentsPool; }
namespace nZone { class cLayoutElement; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

// Functions the classes below befriend, declared first
namespace nSoundZone { nZone::ShapeInfoBase* getShapeFromZoneLayout(cZoneLayout* pZone, u32 index); }

namespace nZone {
    class ShapeInfoBase : public ::MtObject
    {
    public:
        enum SHAPE_TYPE
        {
            SHAPE_TYPE_NONE = 0,
            SHAPE_TYPE_AREA = 1,
            SHAPE_TYPE_AABB = 2,
            SHAPE_TYPE_OBB = 3,
            SHAPE_TYPE_SPHERE = 4,
            SHAPE_TYPE_CAPSULE = 5,
            SHAPE_TYPE_CYLINDER = 6,
            SHAPE_TYPE_POINT = 7,
            SHAPE_TYPE_LINE = 8,
            SHAPE_TYPE_PANEL = 9,
            SHAPE_TYPE_CONE = 10,
            SHAPE_TYPE_GLOBAL = 11,
            SHAPE_TYPE_NUM = 12,
            SHAPE_TYPE_INVALID = -1,
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
        ShapeInfoBase();
        virtual ~ShapeInfoBase();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool copy(const nZone::ShapeInfoBase& copyShape);  // vtable slot 6
        virtual void applyWorldOffset(const MtVector3& offset) {}  // vtable slot 7
        virtual SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual void loadBinary(MtDataReader& r);  // vtable slot 14
        virtual void saveBinary(MtDataWriter& w);  // vtable slot 15
        virtual bool isGetAABB() const;  // vtable slot 16
        virtual MtAABB getAABB() const;  // vtable slot 17
        virtual bool isGetBoundingSphere() const;  // vtable slot 18
        virtual MtSphere getBoundingSphere() const;  // vtable slot 19
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        virtual void setCenterPos(const MtVector3& pos) {}  // vtable slot 21
        virtual void movePosition(const MtVector3& AddPos) {}  // vtable slot 22
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {}  // vtable slot 23
        virtual void rotation(const MtMatrix& RotateMatrix) {}  // vtable slot 24
        virtual void rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const {}  // vtable slot 25
        virtual void rotationAngle(const MtVector3& RotateRadian);  // vtable slot 26
        virtual void rotationAngle(nZone::ShapeInfoBase& OutputShape, const MtVector3& RotateRadian) const;  // vtable slot 27
        virtual void mulMatrix(const MtMatrix& MulMatrix) {}  // vtable slot 28
        virtual void mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {}  // vtable slot 29
        virtual void mulMatrixByRotTransXYZ(const MtVector3& RotateRadianXYZ, const MtVector3& Translate);  // vtable slot 30
        virtual void mulMatrixByRotTransXYZ(nZone::ShapeInfoBase& OutputShape, const MtVector3& RotateRadianXYZ, const MtVector3& Translate) const;  // vtable slot 31
        virtual void mulMatrixByRotTransQuaternion(const MtQuaternion& qt, const MtVector3& Translate);  // vtable slot 32
        virtual void mulMatrixByRotTransQuaternion(nZone::ShapeInfoBase& OutputShape, const MtQuaternion& qt, const MtVector3& Translate) const;  // vtable slot 33
        virtual f32 calcWeight(const MtVector3& pos) const;  // vtable slot 34
        f32 getDecay() const;
        void setDecay(f32 decay);
        void moveCenterPos(const MtVector3&);
        void moveCenterPos(nZone::ShapeInfoBase&, const MtVector3&) const;
        void rotationCenterPos(const MtMatrix&);
        void rotationCenterPos(nZone::ShapeInfoBase&, const MtMatrix&) const;
        void mulMatrixCenterPos(const MtMatrix&);
        void mulMatrixCenterPos(nZone::ShapeInfoBase&, const MtMatrix&) const;
        bool isNativeData() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        f32 mDecay;  // offset: 0x8
        bool mIsNativeData;  // offset: 0xc
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class ShapeInfoCapsule : public nZone::ShapeInfoBase
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
        ShapeInfoCapsule();
        virtual ~ShapeInfoCapsule();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool copy(const nZone::ShapeInfoBase& copyShape);  // vtable slot 6
        virtual void applyWorldOffset(const MtVector3& offset);  // vtable slot 7
        virtual nZone::ShapeInfoBase::SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual void loadBinary(MtDataReader& r);  // vtable slot 14
        virtual void saveBinary(MtDataWriter& w);  // vtable slot 15
        virtual bool isGetAABB() const;  // vtable slot 16
        virtual MtAABB getAABB() const;  // vtable slot 17
        virtual bool isGetBoundingSphere() const;  // vtable slot 18
        virtual MtSphere getBoundingSphere() const;  // vtable slot 19
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        virtual void setCenterPos(const MtVector3& pos);  // vtable slot 21
        virtual void movePosition(const MtVector3& AddPos);  // vtable slot 22
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const;  // vtable slot 23
        virtual void rotation(const MtMatrix& RotateMatrix);  // vtable slot 24
        virtual void rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const;  // vtable slot 25
        virtual void mulMatrix(const MtMatrix& MulMatrix);  // vtable slot 28
        virtual void mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const;  // vtable slot 29
        virtual f32 calcWeight(const MtVector3& pos) const;  // vtable slot 34
        const MtCapsule& getShapeCapsule() const;
        void setShapeCapsule(const MtCapsule& capsule);
        MtVector3 getCapsulePoint0() const;
        void setCapsulePoint0(const MtVector3&);
        MtVector3 getCapsulePoint1() const;
        void setCapsulePoint1(const MtVector3&);
        f32 getCapsuleRadius() const;
        void setCapsuleRadius(f32);
        const MtCapsule& getParam() const;
        void setParam(const MtCapsule& c);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        MtCapsule mCapsule;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class ShapeInfoCone : public nZone::ShapeInfoBase
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
        ShapeInfoCone();
        virtual ~ShapeInfoCone();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool copy(const nZone::ShapeInfoBase& copyShape);  // vtable slot 6
        virtual void applyWorldOffset(const MtVector3& offset);  // vtable slot 7
        virtual nZone::ShapeInfoBase::SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual void loadBinary(MtDataReader& r);  // vtable slot 14
        virtual void saveBinary(MtDataWriter& w);  // vtable slot 15
        virtual bool isGetAABB() const;  // vtable slot 16
        virtual MtAABB getAABB() const;  // vtable slot 17
        virtual bool isGetBoundingSphere() const;  // vtable slot 18
        virtual MtSphere getBoundingSphere() const;  // vtable slot 19
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        virtual void setCenterPos(const MtVector3& pos);  // vtable slot 21
        virtual void movePosition(const MtVector3& AddPos);  // vtable slot 22
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const;  // vtable slot 23
        virtual void mulMatrix(const MtMatrix& MulMatrix);  // vtable slot 28
        virtual void mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const;  // vtable slot 29
        virtual f32 calcWeight(const MtVector3& pos) const;  // vtable slot 34
        const MtVector3& getPos() const;
        MtVector3 getPosForProperty() const;
        void setPos(const MtVector3& pos);
        f32 getHeight() const;
        void setHeight(f32 height);
        f32 getTopRadius() const;
        void setTopRadius(f32 r);
        f32 getBottomRadius() const;
        void setBottomRadius(f32 r);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        f32 mHeight;  // offset: 0x10
        f32 mTopRadius;  // offset: 0x14
        MtVector3 mPos;  // offset: 0x20
        f32 mBottomRadius;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class ShapeInfoCylinder : public nZone::ShapeInfoBase
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
        ShapeInfoCylinder();
        virtual ~ShapeInfoCylinder();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool copy(const nZone::ShapeInfoBase& copyShape);  // vtable slot 6
        virtual void applyWorldOffset(const MtVector3& offset);  // vtable slot 7
        virtual nZone::ShapeInfoBase::SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual void loadBinary(MtDataReader& r);  // vtable slot 14
        virtual void saveBinary(MtDataWriter& w);  // vtable slot 15
        virtual bool isGetAABB() const;  // vtable slot 16
        virtual MtAABB getAABB() const;  // vtable slot 17
        virtual bool isGetBoundingSphere() const;  // vtable slot 18
        virtual MtSphere getBoundingSphere() const;  // vtable slot 19
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        virtual void setCenterPos(const MtVector3& pos);  // vtable slot 21
        virtual void movePosition(const MtVector3& AddPos);  // vtable slot 22
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const;  // vtable slot 23
        virtual void rotation(const MtMatrix& RotateMatrix);  // vtable slot 24
        virtual void rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const;  // vtable slot 25
        virtual void mulMatrix(const MtMatrix& MulMatrix);  // vtable slot 28
        virtual void mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const;  // vtable slot 29
        virtual f32 calcWeight(const MtVector3& pos) const;  // vtable slot 34
        const MtCylinder& getShapeCylinder() const;
        void setShapeCylinder(const MtCylinder& c);
        MtVector3 getCylinderPoint0() const;
        void setCylinderPoint0(const MtVector3&);
        MtVector3 getCylinderPoint1() const;
        void setCylinderPoint1(const MtVector3&);
        f32 getCylinderRadius() const;
        void setCylinderRadius(f32);
        const MtCylinder& getParam() const;
        void setParam(const MtCylinder& c);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        MtCylinder mCylinder;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class ShapeInfoGlobal : public nZone::ShapeInfoBase
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
        ShapeInfoGlobal();
        virtual ~ShapeInfoGlobal();
        virtual nZone::ShapeInfoBase::SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class ShapeInfoOBB : public nZone::ShapeInfoBase
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
        ShapeInfoOBB();
        virtual ~ShapeInfoOBB();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool copy(const nZone::ShapeInfoBase& copyShape);  // vtable slot 6
        virtual void applyWorldOffset(const MtVector3& offset);  // vtable slot 7
        virtual nZone::ShapeInfoBase::SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual void loadBinary(MtDataReader& r);  // vtable slot 14
        virtual void saveBinary(MtDataWriter& w);  // vtable slot 15
        virtual bool isGetAABB() const;  // vtable slot 16
        virtual MtAABB getAABB() const;  // vtable slot 17
        virtual bool isGetBoundingSphere() const;  // vtable slot 18
        virtual MtSphere getBoundingSphere() const;  // vtable slot 19
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        virtual void setCenterPos(const MtVector3& pos);  // vtable slot 21
        virtual void movePosition(const MtVector3& AddPos);  // vtable slot 22
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const;  // vtable slot 23
        virtual void rotation(const MtMatrix& RotateMatrix);  // vtable slot 24
        virtual void rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const;  // vtable slot 25
        virtual void mulMatrix(const MtMatrix& MulMatrix);  // vtable slot 28
        virtual void mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const;  // vtable slot 29
        virtual f32 calcWeight(const MtVector3& pos) const;  // vtable slot 34
        const MtOBB& getShapeOBB() const;
        void setShapeOBB(const MtOBB& o);
        f32 getHeight() const;
        void setHeight(f32 height);
        MtVector3 getVertexMin() const;
        void setVertexMin(const MtVector3& v);
        MtVector3 getVertexMax() const;
        void setVertexMax(const MtVector3& v);
        const MtOBB& getParam() const;
        void setParam(const MtOBB& o);
        bool isEnableExtendedDecay() const;
        void setEnableExtendedDecay(bool);
        f32 getDecayY() const;
        void setDecayY(f32);
        f32 getDecayZ() const;
        void setDecayZ(f32);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        MtOBB mOBB;  // offset: 0x10
        f32 mDecayY;  // offset: 0x60
        f32 mDecayZ;  // offset: 0x64
        bool mIsEnableExtendedDecay;  // offset: 0x68
    public:
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class ShapeInfoPanel : public nZone::ShapeInfoBase
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
        ShapeInfoPanel();
        virtual ~ShapeInfoPanel();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool copy(const nZone::ShapeInfoBase& copyShape);  // vtable slot 6
        virtual void applyWorldOffset(const MtVector3& offset);  // vtable slot 7
        virtual nZone::ShapeInfoBase::SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual void loadBinary(MtDataReader& r);  // vtable slot 14
        virtual void saveBinary(MtDataWriter& w);  // vtable slot 15
        virtual bool isGetAABB() const;  // vtable slot 16
        virtual MtAABB getAABB() const;  // vtable slot 17
        virtual bool isGetBoundingSphere() const;  // vtable slot 18
        virtual MtSphere getBoundingSphere() const;  // vtable slot 19
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        virtual void setCenterPos(const MtVector3& pos);  // vtable slot 21
        virtual void movePosition(const MtVector3& AddPos);  // vtable slot 22
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const;  // vtable slot 23
        virtual void rotation(const MtMatrix& RotateMatrix);  // vtable slot 24
        virtual void rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const;  // vtable slot 25
        virtual void mulMatrix(const MtMatrix& MulMatrix);  // vtable slot 28
        virtual void mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const;  // vtable slot 29
        void shiftDiagonal();
        void reversePanelDirection();
        const MtVector3& getVertex(u32 index) const;
        void setVertex(const MtVector3& v, u32 index);
        MtTriangle getTriangle(u32 index) const;
        MtVector3 calcCenter() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        MtVector3 mVertex[4];  // offset: 0x10
    public:
        static MyDTI DTI;
        static const u32 VERTEX_NUM = 4;
        static const u32 EDGE_VERTEX_INDEX[4][2];
        static const u32 EDGE_TRIANGLE_INDEX[4];
        static const f32 DEFAULT_RENDER_NORMAL_LENGTH;
    };
}  // namespace nZone

namespace nZone {
    class ShapeInfoSphere : public nZone::ShapeInfoBase
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
        ShapeInfoSphere();
        virtual ~ShapeInfoSphere();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool copy(const nZone::ShapeInfoBase& copyShape);  // vtable slot 6
        virtual void applyWorldOffset(const MtVector3& offset);  // vtable slot 7
        virtual nZone::ShapeInfoBase::SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual void loadBinary(MtDataReader& r);  // vtable slot 14
        virtual void saveBinary(MtDataWriter& w);  // vtable slot 15
        virtual bool isGetAABB() const;  // vtable slot 16
        virtual MtAABB getAABB() const;  // vtable slot 17
        virtual bool isGetBoundingSphere() const;  // vtable slot 18
        virtual MtSphere getBoundingSphere() const;  // vtable slot 19
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        virtual void setCenterPos(const MtVector3& pos);  // vtable slot 21
        virtual void movePosition(const MtVector3& AddPos);  // vtable slot 22
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const;  // vtable slot 23
        virtual void mulMatrix(const MtMatrix& MulMatrix);  // vtable slot 28
        virtual void mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const;  // vtable slot 29
        virtual f32 calcWeight(const MtVector3& pos) const;  // vtable slot 34
        const MtSphere& getShapeSphere() const;
        void setShapeSphere(const MtSphere& s);
        const MtSphere& getParam() const;
        void setParam(const MtSphere& s);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        MtSphere mSphere;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class cAllocaterIntermediate : public ::MtObject
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
        cAllocaterIntermediate();
        virtual ~cAllocaterIntermediate() {}
    public:
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class cContentsPool : public ::MtObject
    {
    public:
        class MyDTI;
        class cContentsList;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cContentsList : public ::MtObject
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
            cContentsList(s32 DefaultGroupID);
            virtual ~cContentsList();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void copyContentsArrayFromGame(nZone::cContentsPool::cContentsList& source);
            void copyGroupID(nZone::cContentsPool::cContentsList& source);
            s32 getContentsGroupID() const;
            void setContentsGroupID(s32);
            u32 getZoneContentsNum() const;
            cZoneContents* getZoneContents(u32 index);
            const cZoneContents* getZoneContentsConst(u32) const;
            const MtDTI* getZoneContentsDTI(u32 index) const;
            s32 searchZoneContentsDTI(const MtDTI& dti, s32 StartIndex) const;
            u32 getZoneContentsNumTargetDTI(const MtDTI& dti) const;
            cZoneContents* addContents(const MtDTI& ContentsClassDTI);
            cZoneContents* insertContents(const MtDTI& ContentsClassDTI, u32 index);
            bool removeContents(const MtDTI& ContentsClassDTI);
            bool removeContents(cZoneContents* pEraseObject);
            u32 getRunCounter(u32 ThreadIndex) const;
            void updateRunCounter(u32 counter, u32 ThreadIndex);
            bool isNativeMode() const;
            void* memAlloc(size_t);
            void memFree(void*);
            size_t memSize(void*);
        public:
            MtArray mZoneContentsArray;  // offset: 0x8
            s32 mGroupID;  // offset: 0x28
        private:
            u32 mRunCounter[19];  // offset: 0x2c
            bool mFlgNativeData;  // offset: 0x78
        public:
            static MyDTI DTI;
            static MT_CTSTR PROP_TITLE_GROUP_NAME;
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
        cContentsPool();
        virtual ~cContentsPool();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        const nZone::cContentsPool& operator=(const nZone::cContentsPool& src);
        bool loadBeforeAllocateAlign4(nCollisionUtil::LoadBuffer& buffer, u32 ContentsListNum);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        cContentsList* getContentsList(u32 GroupIndex) const;
        const cContentsList* getContentsListConst(u32 GroupIndex) const;
        s32 getContentsListGroupID(u32 ContentsIndex) const;
        u32 getContentsNum() const;
        u32 getContentsListNum() const;
        void clearContents();
        void eraseContents(u32);
        bool isNativeMode() const;
        static void copyObjectProperty(MtObject* pDest, MtObject* pSrc);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        MtTypedArray<cContentsList> mContentsListArray;  // offset: 0x8
    protected:
        bool mFlgNativeData;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class cLayoutElement : public ::MtObject
    {
        friend class ::cSoundGeneratorListener;
        friend class ::cSoundTriggerListener;
        friend nZone::ShapeInfoBase* nSoundZone::getShapeFromZoneLayout(cZoneLayout* pZone, u32 index);
        friend class ::uSoundTrigger;
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
        cLayoutElement();
        virtual ~cLayoutElement();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void copy(nZone::cLayoutElement* pE);  // vtable slot 6
        u32 getShapeType() const;
        MT_CTSTR getShapeTypeName() const;
        void setShapeType(u32 type);
        void createShape(u32 NewShapeType);
        void setContentsPoolGroupID(s32 groupID);
        s32 getContentsPoolGroupID() const;
        void copyFromSystem(cZoneLayout* pOwner, nZone::cLayoutElement& src, nZone::cContentsPool& ContentsPool, u32 LayoutIndex, bool FlgCopyShallow);
        bool loadBeforeAllocateAlign16(nCollisionUtil::LoadBuffer& buffer, u32 ShapeType);
        bool loadBinary(MtDataReader& r);
        bool saveBinary(MtDataWriter& w);
        s32 getPriority() const;
        void setPriority(s32 prio);
        nZone::ShapeInfoBase* getShapeInfo() const;
        const nZone::ShapeInfoBase* getShapeInfoConst() const;
        const nZone::ShapeInfoBase* getShapeInfoResource() const;
        MtVector3 getShapeInfoCenterPos() const;
        s32 getContentsPoolID() const;
        void setContentsPoolID(s32 id);
        nZone::cContentsPool::cContentsList* getUseContentsList() const;
        void setContentsPool(nZone::cContentsPool* pContentsPool);
        nZone::cContentsPool* getContentsPool();
        cZoneContents* getContents(u32 index) const;
        cZoneContents* getContents(const MtDTI& contentsDti, u32 SearchStartIndex) const;
        u32 getContentsIndex(const MtDTI& contentsDti, u32 SearchStartIndex) const;
        u32 getContentsNum() const;
        u32 getContentsSize() const;
        void setEnable(bool flag);
        bool isEnable() const;
        void setDynamic(bool flag);
        bool isDynamic() const;
        void setIndex(u32 index);
        u32 getIndex() const;
        void setLayoutGroupIndex(u32);
        u32 getLayoutGroupIndex() const;
        void setIndexOfLayoutGroup(u32);
        u32 getIndexOfLayoutGroup() const;
        void copyShape(nZone::cLayoutElement* pSourceElement, bool FlgShallowCopyShape);
        void copyContents(nZone::cLayoutElement* pSrcElement);
        void copyContents(nZone::cContentsPool::cContentsList* pSrcContentsList);
        void setShapeInfo(nZone::ShapeInfoBase* pShape);
        void repairShapeByResource();
        void runBackwardCompatible();
        void setExtendObj(MtObject* pObj);
        MtObject* getExtendObj() const;
        u32 getUniqueID() const;
        s32 getGroupID() const;
        bool isSetInvalidGroupID() const;
        cDynamicBVHCollision::Node* getDynamicBVHNode() const;
        void setDynamicBVHNode(cDynamicBVHCollision::Node* pNode);
        cZoneLayout* getOwner() const;
        void setOwner(cZoneLayout* pOwner);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        nZone::cContentsPool::cContentsList* getContentsList() const;
        const nZone::cContentsPool::cContentsList* getContentsListConst() const;
        u32 getShapeTypeInterface() const;
        void setShapeTypeInterface(u32 type);
        void deleteShape();
        bool isEnableForUI() const;
        void setContentsPoolGroupIDForUI(s32 groupID);
        s32 getContentsPoolGroupIDForUI() const;
    protected:
        cZoneLayout* mpOwner;  // offset: 0x8
        s32 mPriority;  // offset: 0x10
        nZone::ShapeInfoBase* mpShapeInfo;  // offset: 0x18
        s32 mContentsPoolID;  // offset: 0x20
        s32 mContentsPoolGroupID;  // offset: 0x24
        bool mIsEnable;  // offset: 0x28
        bool mIsDynamic;  // offset: 0x29
        bool mFlgShallowCopyShape;  // offset: 0x2a
        u32 mIndex;  // offset: 0x2c
        u32 mLayoutGroupIndex;  // offset: 0x30
        u32 mIndexOfLayoutGroup;  // offset: 0x34
        MtObject* mpExtendObj;  // offset: 0x38
        u32 mUniqueID;  // offset: 0x40
        s32 mGroupID;  // offset: 0x44
        cDynamicBVHCollision::Node* mpDynamicBVHNode;  // offset: 0x48
        nZone::cContentsPool* mpContentsPool;  // offset: 0x50
    public:
        static MyDTI DTI;
        static const s32 MAX_PRIORITY = 1024;
        static const s32 INVALID_CONTENTS_POOL_ID = -1;
        static const s32 INVALID_CONTENTS_GROUP_ID = -1;
        static const u32 INVALID_INDEX = 4294967295;
        static const u32 INVALID_UNIQUE_ID = 4294967295;
        static const s32 INVALID_GROUP_ID = -1;
        static MT_CTSTR PROP_TITLE_CONTENTS_GROUP_ID;
        static MT_CTSTR PROP_TITLE_CONTENTS_GROUP_ID_DIRECT;
        static MT_CTSTR PROP_TITLE_SHAPE_TYPE;
        static MT_CTSTR PROP_TITLE_SHAPE_TYPE_TOOL;
    };
}  // namespace nZone

namespace nZone {
    class ShapeInfoAABB : public nZone::ShapeInfoBase
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
        ShapeInfoAABB();
        virtual ~ShapeInfoAABB();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool copy(const nZone::ShapeInfoBase& copyShape);  // vtable slot 6
        virtual void applyWorldOffset(const MtVector3& offset);  // vtable slot 7
        virtual nZone::ShapeInfoBase::SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual void loadBinary(MtDataReader& r);  // vtable slot 14
        virtual void saveBinary(MtDataWriter& w);  // vtable slot 15
        virtual bool isGetAABB() const;  // vtable slot 16
        virtual MtAABB getAABB() const;  // vtable slot 17
        virtual bool isGetBoundingSphere() const;  // vtable slot 18
        virtual MtSphere getBoundingSphere() const;  // vtable slot 19
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        virtual void setCenterPos(const MtVector3& pos);  // vtable slot 21
        virtual void movePosition(const MtVector3& AddPos);  // vtable slot 22
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const;  // vtable slot 23
        virtual void mulMatrix(const MtMatrix& MulMatrix);  // vtable slot 28
        virtual void mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const;  // vtable slot 29
        virtual f32 calcWeight(const MtVector3& pos) const;  // vtable slot 34
        const MtAABB& getShapeAABB() const;
        void setShapeAABB(const MtAABB& a);
        MtAABB scaleAABB() const;
        MtVector3 getMinpos() const;
        void setMinpos(const MtVector3&);
        MtVector3 getMaxpos() const;
        void setMaxpos(const MtVector3&);
        const MtAABB& getParam() const;
        void setParam(const MtAABB& a);
        bool isEnableExtendedDecay() const;
        void setEnableExtendedDecay(bool);
        f32 getDecayY() const;
        void setDecayY(f32);
        f32 getDecayZ() const;
        void setDecayZ(f32);
        MtVector3 getVertex(u32 AABBVertexVoronoiID) const;
        void setVertex(const MtVector3& v, u32 AABBVertexVoronoiID);
        MtVector3 getVertex000() const;
        void setVertex000(const MtVector3& v);
        MtVector3 getVertex001() const;
        void setVertex001(const MtVector3& v);
        MtVector3 getVertex010() const;
        void setVertex010(const MtVector3& v);
        MtVector3 getVertex011() const;
        void setVertex011(const MtVector3& v);
        MtVector3 getVertex100() const;
        void setVertex100(const MtVector3& v);
        MtVector3 getVertex101() const;
        void setVertex101(const MtVector3& v);
        MtVector3 getVertex110() const;
        void setVertex110(const MtVector3& v);
        MtVector3 getVertex111() const;
        void setVertex111(const MtVector3& v);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        MtAABB mAABB;  // offset: 0x10
        f32 mDecayY;  // offset: 0x30
        f32 mDecayZ;  // offset: 0x34
        bool mIsEnableExtendedDecay;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nZone

namespace nZone {
    class ShapeInfoArea : public nZone::ShapeInfoBase
    {
    public:
        enum CONCAVE_STATUS
        {
            CONCAVE_DEFAULT = 0,
            CONCAVE_VERTEX_ROLL_INVERSE = 1,
            CONCAVE_CROSS_0312 = 2,
            CONCAVE_CROSS_0123 = 3,
        };
    public:
        class MyDTI;
        class cTrianglePillar;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cTrianglePillar
        {
        public:
            cTrianglePillar();
            cTrianglePillar(const MtTriangle& BottomTriangle, f32 Height);
            MtVector3 getSupportConst(const MtVector3& v) const;
            MtVector3 getSupport(const MtVector3& v) const;
            MtVector3 getInternalPos() const;
            void trace() const;
        protected:
            MtTriangle mBottomTriangle;  // offset: 0x0
            MtVector3 mHeightOffset;  // offset: 0x30
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
        ShapeInfoArea();
        virtual ~ShapeInfoArea();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool copy(const nZone::ShapeInfoBase& copyShape);  // vtable slot 6
        virtual void applyWorldOffset(const MtVector3& offset);  // vtable slot 7
        virtual nZone::ShapeInfoBase::SHAPE_TYPE getShapeType() const;  // vtable slot 8
        virtual bool isHit(const MtVector3& pos) const;  // vtable slot 9
        virtual bool isHitLineSegment(const MtLineSegment& ls) const;  // vtable slot 10
        virtual bool isHitConvex(const MtGeomConvex& convex) const;  // vtable slot 11
        virtual bool isIntersectAABB(const MtAABB& aabb) const;  // vtable slot 12
        virtual bool getClosest(const MtVector3& pos, MtContact& contact) const;  // vtable slot 13
        virtual void loadBinary(MtDataReader& r);  // vtable slot 14
        virtual void saveBinary(MtDataWriter& w);  // vtable slot 15
        virtual bool isGetAABB() const;  // vtable slot 16
        virtual MtAABB getAABB() const;  // vtable slot 17
        virtual bool isGetBoundingSphere() const;  // vtable slot 18
        virtual MtSphere getBoundingSphere() const;  // vtable slot 19
        virtual MtVector3 getCenterPos() const;  // vtable slot 20
        virtual void setCenterPos(const MtVector3& pos);  // vtable slot 21
        virtual void movePosition(const MtVector3& AddPos);  // vtable slot 22
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const;  // vtable slot 23
        virtual void rotation(const MtMatrix& RotateMatrix);  // vtable slot 24
        virtual void rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const;  // vtable slot 25
        virtual void rotationAngle(const MtVector3& RotateRadian);  // vtable slot 26
        virtual void rotationAngle(nZone::ShapeInfoBase& OutputShape, const MtVector3& RotateRadian) const;  // vtable slot 27
        virtual void mulMatrix(const MtMatrix& MulMatrix);  // vtable slot 28
        virtual void mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const;  // vtable slot 29
        virtual void mulMatrixByRotTransXYZ(const MtVector3& RotateRadianXYZ, const MtVector3& Translate);  // vtable slot 30
        virtual void mulMatrixByRotTransXYZ(nZone::ShapeInfoBase& OutputShape, const MtVector3& RotateRadianXYZ, const MtVector3& Translate) const;  // vtable slot 31
        virtual f32 calcWeight(const MtVector3& pos) const;  // vtable slot 34
        bool isHitArea(const nZone::ShapeInfoArea& area) const;
        bool isInnerY(const MtVector3& pos) const;
        bool isInnerXZ(const MtVector3& pos) const;
        bool isConvex() const;
        bool isConvexFromLog() const;
        void createWorldVertex(MtVector3* v, MtVector3* vh, u32 num) const;
        MtVector3 getVertex(u32 index) const;
        void setVertex(const MtVector3& v, u32 index);
        f32 getBottom() const;
        void setBottom(f32 bottom);
        f32 getHeight() const;
        void setHeight(f32 height);
        MtVector3 calcCenter() const;
        MtVector3 calcCenterNoRepairY() const;
        MtTriangle getBottomTriangle(u32 TriangleIndex) const;
        MtTriangle getSideTriangle(u32 SideIndex, u32 TriangleIndex) const;
        MtVector3 getSupportConst(const MtVector3& v) const;
        MtVector3 getSupport(const MtVector3& v) const;
        MtVector3 getInternalPos() const;
        void trace() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        u32 getVertexNumForProperty() const;
        void setDummyU32(u32);
    private:
        bool isInnerXZ_Private(const MtVector3& pos) const;
        MtVector3 closestSub(const MtVector3& pos, const MtVector3& p0, const MtVector3& p0_, const MtVector3& p1, const MtVector3& p1_, f32& len) const;
        bool distanceSqSub(const MtRay& ray, const MtVector3& p0, const MtVector3& p0_, const MtVector3& p1, const MtVector3& p1_, MtVector3& pos) const;
        bool isConvex_Private() const;
        void updateConcaveParam();
        void updateConcaveCrossPos();
        MtTriangle getBottomTriangle_Private(u32 TriangleIndex) const;
        MtTriangle getSideTriangle_Private(u32 SideIndex, u32 TriangleIndex) const;
        void repairHeightAndBottom();
    protected:
        f32 mHeight;  // offset: 0x10
        f32 mBottom;  // offset: 0x14
        u32 mConcaveStatus;  // offset: 0x18
        bool mFlgConvex;  // offset: 0x1c
        MtVector3 mVertex[4];  // offset: 0x20
        MtVector3 mConcaveCrossPos;  // offset: 0x60
    public:
        static MyDTI DTI;
        static const u32 VERTEX_NUM = 4;
    };
}  // namespace nZone

inline f32 nZone::ShapeInfoArea::getBottom() const {
    return this->mBottom;
}

inline f32 nZone::ShapeInfoArea::getHeight() const {
    return this->mHeight;
}

inline void* nZone::ShapeInfoBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nZone::ShapeInfoCapsule::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline f32 nZone::ShapeInfoCone::getHeight() const {
    return this->mHeight;
}

inline void* nZone::ShapeInfoGlobal::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline f32 nZone::ShapeInfoOBB::getHeight() const {
    return this->mOBB.extent.y + this->mOBB.extent.y;
}

inline void* nZone::ShapeInfoPanel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nZone::cAllocaterIntermediate::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nZone::cAllocaterIntermediate::cAllocaterIntermediate() {
}

inline void* nZone::cContentsPool::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nZone::cContentsPool::cContentsList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 nZone::cContentsPool::cContentsList::getZoneContentsNum() const {
    return this->mZoneContentsArray.mLength;
}

inline s32 nZone::cLayoutElement::getPriority() const {
    return this->mPriority;
}

inline nZone::ShapeInfoBase* nZone::cLayoutElement::getShapeInfo() const {
    return this->mpShapeInfo;
}

inline s32 nZone::cLayoutElement::getContentsPoolID() const {
    return this->mContentsPoolID;
}

inline u32 nZone::cLayoutElement::getIndex() const {
    return this->mIndex;
}

inline MtObject* nZone::cLayoutElement::getExtendObj() const {
    return this->mpExtendObj;
}

inline u32 nZone::cLayoutElement::getUniqueID() const {
    return this->mUniqueID;
}
