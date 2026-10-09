#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cResource.h"
#include "nCollisionNode.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
class MtCylinder;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtGeomConvex;
class MtMatrix;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtStream;
class MtTriangle;
class MtUI;
class MtVector3;
namespace nCollision { class cCollisionNode; }
namespace nCollision { class cObjectBase; }
class rGeometry2Group;
class uModel;

// Declarations
class rGeometry2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rGeometry2 : public cResource
{
public:
    class MyDTI;
    class cGeometryArray;
    class cGeometry;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cGeometryArray : public nCollision::cCollisionNode
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
        cGeometryArray(const MtDTI* pEditGeometryDTI);
        virtual ~cGeometryArray();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r, MtStream& in);  // vtable slot 6
        virtual bool save(MtDataWriter& w, MtStream& out);  // vtable slot 7
        virtual void copy(const nCollision::cObjectBase& src);  // vtable slot 9
        virtual void move();  // vtable slot 8
        virtual bool isActive() const;  // vtable slot 10
        virtual void setActive(bool FlgSetActive);  // vtable slot 11
        virtual void copyEx(const nCollision::cCollisionNode& src, bool FlgSkipEditDTI, bool FlgGeometryInsideDataCopy);  // vtable slot 12
        void copyRemoveAddonObject(const nCollision::cObjectBase& src);
        MtObject* getAddonObject() const;
        void setAddonObject(MtObject* pObj);
        void setAddonObjectByDTI(const MtDTI* pDti);
        MtGeomConvex* getAttachGeometry(u32 TargetGeometryIndex) const;
        MtGeomConvex* getLocalGeometry(u32 TargetGeometryIndex) const;
        MtObject* getGeometryAddonObject(u32 TargetGeometryIndex) const;
        void setGeometryAddonObject(MtObject* pGeometryAddonObject, u32 TargetGeometryIndex);
        void setGeometryAddonObjectAll(const MtDTI* pGeometryAddonObjectDTI);
        s32 getGeometryAttachJointNo0(u32 TargetGeometryIndex) const;
        void setGeometryAttachJointNo0(u32 TargetGeometryIndex, s32 NextAttachJointNo0);
        s32 getGeometryAttachJointNo1(u32 TargetGeometryIndex) const;
        void setGeometryAttachJointNo1(u32 TargetGeometryIndex, s32 NextAttachJointNo1);
        void setAttachModel(uModel* pAttachModel);
        uModel* getAttachModel();
        void updateAttachGeometry();
        void restoreSweptSphere();
        bool isEnableSequence() const;
        void setEnableSequence(bool FlgNextEnableSequence);
        u8 getSequenceMotionListIndex() const;
        void setSequenceMotionListIndex(u8 NextSequenceMotionListIndex);
        u8 getSequenceIndex() const;
        void setSequenceIndex(u8 NextSequenceIndex);
        u8 getSequenceBit() const;
        void setSequenceBit(u8 NextSequenceBitIndex);
    protected:
        MtObject* mpAddonObject;  // offset: 0x78
        uModel* mpAttachModel;  // offset: 0x80
        bool mFlgEnableSequence;  // offset: 0x88
        u8 mMotionListIndex;  // offset: 0x89
        u8 mSequenceIndex;  // offset: 0x8a
        u8 mTargetSequenceBitIndex;  // offset: 0x8b
        u32 mBeforeSequenceMotionNo;  // offset: 0x8c
        s32 mBeforeSequenceFrameIndex;  // offset: 0x90
    public:
        static MyDTI DTI;
    };
public:
    class cGeometry : public nCollision::cGeometry
    {
    public:
        enum ATTACH_TYPE
        {
            ATTACH_TYPE_NULL = 0,
            ATTACH_TYPE_JOINT_POS = 1,
            ATTACH_TYPE_JOINT_LOCAL = 2,
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
        cGeometry();
        virtual ~cGeometry();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r, MtStream& in);  // vtable slot 6
        virtual bool save(MtDataWriter& w, MtStream& out);  // vtable slot 7
        virtual void move();  // vtable slot 8
        virtual bool isActive() const;  // vtable slot 10
        virtual void setActive(bool FlgSetActive);  // vtable slot 11
        virtual void updateBoundingAABB();  // vtable slot 12
        virtual void evGeometryTypeChange();  // vtable slot 13
        virtual void copy(const nCollision::cObjectBase& src);  // vtable slot 9
        virtual void registGeometryByType(u32 GeometryType);  // vtable slot 14
        void updateAttachGeometry();
        void restoreSweptSphere();
        u32 getAttachMode() const;
        void setAttachMode(u32 NewAttachMode);
        u8 getJointNo0() const;
        void setJointNo0(u8 NewJointIndex0);
        u8 getJointNo1() const;
        void setJointNo1(u8 NewJointIndex1);
        bool isEnableScale() const;
        void setEnableScale(bool FlgNewScaleEnable);
        void setAttachModel(uModel* pModel);
        MtGeomConvex* getAttachGeometry() const;
        MtSphere getAttachGeometryBySphere();
        void setAttachGeometryBySphere(const MtSphere& sphere);
        MtCapsule getAttachGeometryByCapsule();
        void setAttachGeometryByCapsule(const MtCapsule& capsule);
        MtOBB getAttachGeometryByOBB();
        void setAttachGeometryByOBB(const MtOBB& obb);
        MtCylinder getAttachGeometryByCylinder();
        void setAttachGeometryByCylinder(const MtCylinder& cylinder);
        MtCapsule getAttachGeometryByLineSweptSphere();
        void setAttachGeometryByLineSweptSphere(const MtCapsule& capsule);
        MtSphere getAttachGeometryByLineSweptSpherePos1Sphere();
        void setAttachGeometryByLineSweptSpherePos1Sphere(const MtSphere& sphere);
        MtTriangle getAttachGeometryByTriangle();
        void setAttachGeometryByTriangle(const MtTriangle& triangle);
        MtObject* getAddonObject() const;
        void setAddonObject(MtObject* pObj);
        void setAddonObjectByDTI(const MtDTI* pDti);
    protected:
        MtMatrix getAttachMatrix0();
        MtMatrix getAttachMatrix1();
        MtMatrix getAttachMatrix(u8 JointIndex);
        MtVector3 getAttachScale();
        f32 getAttachScaleMaxElement();
    protected:
        MtGeomConvex* mpAttachGeometry;  // offset: 0x40
        u8 mAttachMode;  // offset: 0x48
        u8 mJointNo0;  // offset: 0x49
        u8 mJointNo1;  // offset: 0x4a
        bool mFlgEnableScale;  // offset: 0x4b
        MtObject* mpAddonObject;  // offset: 0x50
        uModel* mpAttachModel;  // offset: 0x58
        MtVector3 mBeforeAttachPos0;  // offset: 0x60
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
    rGeometry2();
    virtual ~rGeometry2();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    const cGeometryArray* getGeometryArray() const;
    const cGeometry* getGeometry(u32 GeometryIndex) const;
    u32 getGeometryNum() const;
    bool isIncludeResource() const;
    rGeometry2Group* getParentResource() const;
protected:
    void setParentResource(rGeometry2Group* pRGeometryGroup);
protected:
    u32 mMagic;  // offset: 0x70
    u32 mVersion;  // offset: 0x74
    cGeometryArray* mpGeometry;  // offset: 0x78
    rGeometry2Group* mpParentResource;  // offset: 0x80
public:
    static MyDTI DTI;
    static const u32 MAGIC = 846161255;
    static const u32 VERSION = 201032100;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK10rGeometry25MyDTI11newInstanceEv at 0x0121d150-0x0121d188, code DWARF attributes to no inlined copy
inline rGeometry2::rGeometry2() {
    this->::cResource::mAttr = static_cast<u32>(22);
    this->mpParentResource = static_cast<rGeometry2Group*>(nullptr);
    this->mpGeometry = static_cast<rGeometry2::cGeometryArray*>(nullptr);
}
