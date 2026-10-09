#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "cDynamicBVHCollision.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtArray;
struct MtContact;
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
class MtSphere;
class MtTriangle;
class MtVector3;
class cZoneContents;
class cZoneLayout;
namespace nCollisionUtil { struct LoadBuffer; }
class uSoundTrigger;

// Declarations
namespace nZone { class ShapeInfoBase; }
namespace nZone { class ShapeInfoOBB; }
namespace nZone { class ShapeInfoPanel; }
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
        // Address: 0x01b89140 - 0x01b89141 (1 bytes)
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
        // Address: 0x01b89260 - 0x01b89261 (1 bytes)
        virtual void setCenterPos(const MtVector3& pos) {}  // vtable slot 21
        // Address: 0x01b89270 - 0x01b89271 (1 bytes)
        virtual void movePosition(const MtVector3& AddPos) {}  // vtable slot 22
        // Address: 0x01b89280 - 0x01b89281 (1 bytes)
        virtual void movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {}  // vtable slot 23
        // Address: 0x01b89290 - 0x01b89291 (1 bytes)
        virtual void rotation(const MtMatrix& RotateMatrix) {}  // vtable slot 24
        // Address: 0x01b892a0 - 0x01b892a1 (1 bytes)
        virtual void rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const {}  // vtable slot 25
        virtual void rotationAngle(const MtVector3& RotateRadian);  // vtable slot 26
        virtual void rotationAngle(nZone::ShapeInfoBase& OutputShape, const MtVector3& RotateRadian) const;  // vtable slot 27
        // Address: 0x01b895c0 - 0x01b895c1 (1 bytes)
        virtual void mulMatrix(const MtMatrix& MulMatrix) {}  // vtable slot 28
        // Address: 0x01b895d0 - 0x01b895d1 (1 bytes)
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
        // inferred: nSoundZone::getShapeFromZoneLayout names nZone::cLayoutElement::mpShapeInfo
        friend nZone::ShapeInfoBase* nSoundZone::getShapeFromZoneLayout(cZoneLayout* pZone, u32 index);
        // inferred: uSoundTrigger::initPanel names nZone::cLayoutElement::mpShapeInfo
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

// Inline, no code of its own: checked where it is inlined.
inline nZone::cAllocaterIntermediate::cAllocaterIntermediate() {
}

// Inline, no code of its own: checked where it is inlined.
inline u32 nZone::cLayoutElement::getIndex() const {
    return this->mIndex;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline MtObject* nZone::cLayoutElement::getExtendObj() const {
    return this->mpExtendObj;
}
