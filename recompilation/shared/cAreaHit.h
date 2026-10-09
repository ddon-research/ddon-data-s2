#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "MtString.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtMatrix;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;
namespace nZone { class ShapeInfoAABB; }
namespace nZone { class ShapeInfoArea; }
namespace nZone { class ShapeInfoBase; }
namespace nZone { class ShapeInfoCone; }
namespace nZone { class ShapeInfoCylinder; }
namespace nZone { class ShapeInfoOBB; }
namespace nZone { class ShapeInfoSphere; }
class uDDOModel;

// Declarations
class AreaHitShape;
class cAreaHit;

enum AREAHIT_SHAPE_TYPE_ENUM
{
    AREAHIT_SHAPE_TYPE_NONE = 0,
    AREAHIT_SHAPE_TYPE_BOX = 1,
    AREAHIT_SHAPE_TYPE_SPHERE = 2,
    AREAHIT_SHAPE_TYPE_CYLINDER = 3,
    AREAHIT_SHAPE_TYPE_DUMMY_04 = 4,
    AREAHIT_SHAPE_TYPE_DUMMY_05 = 5,
    AREAHIT_SHAPE_TYPE_CONE = 6,
    AREAHIT_SHAPE_TYPE_DUMMY_07 = 7,
    AREAHIT_SHAPE_TYPE_AABB = 8,
    AREAHIT_SHAPE_TYPE_OBB = 9,
    AREAHIT_SHAPE_TYPE_MAX = 10,
};

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using ZShape = nZone::ShapeInfoBase;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class AreaHitShape : public MtObject
{
public:
    class MyDTI;
    struct NativeAllocInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct NativeAllocInfo
    {
    public:
        nZone::ShapeInfoArea* pShapeBoxArray;  // offset: 0x0
        u32 ShapeBoxUseNum;  // offset: 0x8
        u32 ShapeBoxMaxNum;  // offset: 0xc
        nZone::ShapeInfoSphere* pShapeSphereArray;  // offset: 0x10
        u32 ShapeSphereUseNum;  // offset: 0x18
        u32 ShapeSphereMaxNum;  // offset: 0x1c
        nZone::ShapeInfoCylinder* pShapeCylinderArray;  // offset: 0x20
        u32 ShapeCylinderUseNum;  // offset: 0x28
        u32 ShapeCylinderMaxNum;  // offset: 0x2c
        nZone::ShapeInfoCone* pShapeConeArray;  // offset: 0x30
        u32 ShapeConeUseNum;  // offset: 0x38
        u32 ShapeConeMaxNum;  // offset: 0x3c
        nZone::ShapeInfoAABB* pShapeAABBArray;  // offset: 0x40
        u32 ShapeAABBUseNum;  // offset: 0x48
        u32 ShapeAABBMaxNum;  // offset: 0x4c
        nZone::ShapeInfoOBB* pShapeOBBArray;  // offset: 0x50
        u32 ShapeOBBUseNum;  // offset: 0x58
        u32 ShapeOBBMaxNum;  // offset: 0x5c
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
    AreaHitShape();
    virtual ~AreaHitShape();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r, NativeAllocInfo* pBuffer);  // vtable slot 6
    virtual bool save(MtDataWriter& w);  // vtable slot 7
    void traceForIOCheck();
    virtual AreaHitShape& operator=(const AreaHitShape& shape);  // vtable slot 8
    static AreaHitShape* createShape(AREAHIT_SHAPE_TYPE_ENUM e);
    MT_CTSTR getName();
    void setName(MtString name);
    void setAngFlag(bool flag);
    bool getAngleFlag() const;
    void setCkAngle(f32 ang);
    f32 getCkAngle() const;
    void setCkRange(f32 ang);
    f32 getCkRange() const;
    void setTowardFlag(bool);
    bool getTowardFlag() const;
    void setCkToward(f32 ang);
    f32 getCkToward() const;
    void applyWorldOffset(const MtVector3& offset);
    AREAHIT_SHAPE_TYPE_ENUM getShapeType() const;
    MtVector3 getCenter() const;
    void setCenter(const MtVector3& pos);
    MtVector3 getWidth() const;
    void setWidth(f32 x, f32 y, f32 z);
    void setWidth(const MtVector3& width);
    f32 getRadiusBottom() const;
    f32 getRadiusTop() const;
    void setRadius(f32 radius, f32 radiusTop);
    f32 getHeight() const;
    void setHeight(f32 height);
    MtVector3 getAngle() const;
    void setAngle(f32 x, f32 y, f32 z);
    void setAngle(const MtVector3& ang);
    bool hitCheck(const MtVector3& tarPos) const;
    bool hitCheckAng(const MtVector3& tarPos, f32 ang) const;
    bool hitCheckBoundingBox(const MtVector3& tarPos) const;
    bool hitCheckOffset(const MtVector3& ofsPos, const MtVector3& ofsAng, const MtVector3& tarPos) const;
    bool hitCheckOffsetAng(const MtVector3& ofsPos, const MtVector3& ofsAng, const MtVector3& tarPos, f32 ang) const;
    bool calcIntersectionLine(cAreaHit* pArea, const MtVector3& pos0, const MtVector3& pos1, MtVector3& pos_out) const;
    void mulMatrix(const MtMatrix& mat, const MtVector3& ctr);
    bool angCheck(f32 ang) const;
    bool calcIntersectionLine2Line2D(const MtVector3& pos0, const MtVector3& pos1, const MtVector3& pos2, const MtVector3& pos3, MtVector3& pos_out) const;
    MtString getName() const;
    // Address: 0x019504c0 - 0x019504c1 (1 bytes)
    virtual void makeCircle() {}  // vtable slot 9
    void setZone(ZShape* p);
    ZShape* getZone() const;
    void deleteZone();
    const MtAABB& getZoneBoundingBox() const;
protected:
    MtString mName;  // offset: 0x8
    f32 mCheckAngle;  // offset: 0x10
    f32 mCheckRange;  // offset: 0x14
    f32 mCheckToward;  // offset: 0x18
    bool mAngleFlag;  // offset: 0x1c
    bool mTowardFlag;  // offset: 0x1d
private:
    bool mIsDeleteZone;  // offset: 0x1e
    ZShape* mpZone;  // offset: 0x20
    MtAABB mZoneBoundingBox;  // offset: 0x30
public:
    static MyDTI DTI;
};

class cAreaHit : public MtObject
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
    cAreaHit();
    virtual ~cAreaHit();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void createToolProperty(MtPropertyList& s);
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void setup(AREAHIT_SHAPE_TYPE_ENUM type, MtObject* pOwner);  // vtable slot 6
    virtual void final();  // vtable slot 7
    virtual void move();  // vtable slot 8
    void update();
    void copyShape(AreaHitShape* pShape);
    u16 getUniqueID();
    void setFix(bool);
    bool isFix();
    virtual bool collide(uDDOModel* pObj);  // vtable slot 9
    virtual bool collide(const MtVector3& pos, f32 ang);  // vtable slot 10
    void collidePlayer();
    void collideEnemy();
    void collideNpc();
    void collideSpecify();
    virtual bool checkToward(const uDDOModel* pObj);  // vtable slot 11
    void setOwner(MtObject* pOwner);
    MtObject* getOwner();
    void setEnable(bool flag);
    bool isEnable();
    void setAttribute(u32 attr);
    u32 getAttribute();
    void addDetectionInfo(u32 info);
    u32 getDetectionInfo();
    bool isDetected(u32 flag);
    MtVector3 getCenter() const;
    void setOffset(const MtVector3& offset);
    MtVector3 getOffset() const;
    void setCkAngle(f32 a);
    void setCkRange(f32 r);
    void setCkToward(f32 r);
    void setRotate(f32 x, f32 y, f32 z);
    void setRotate(const MtVector3& rot);
    void setWidth(f32 x, f32 y, f32 z);
    void setWidth(const MtVector3& width);
    void setRadius(f32 radius, f32 radiusTop);
    void setHeight(f32 height);
    void setAngle(f32 x, f32 y, f32 z);
    void setAngle(const MtVector3& rot);
    AreaHitShape* getShapePtr() const;
    void setShapePtr(AreaHitShape*);
    ZShape* getZonePtr() const;
    void setShape(AREAHIT_SHAPE_TYPE_ENUM type);
    AREAHIT_SHAPE_TYPE_ENUM getShape();
    void setSpTarget(uDDOModel*);
    void setRefPos(const MtVector3&);
    void setRefJointNo(u32);
    void setOwnerJointNo(u32);
    u32 getOwnerJointNo();
    void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
private:
    void getTargetPos(uDDOModel* pObj, MtVector3* pTargetPos, MtVector3* pTargetUnderPos) const;
    f32 yaw(const MtVector3& vec);
private:
    MtObject* mpOwner;  // offset: 0x8
    u32 mOwnerId;  // offset: 0x10
    bool mbEnable;  // offset: 0x14
    bool mbFix;  // offset: 0x15
    u16 mUID;  // offset: 0x16
    u32 mDetect;  // offset: 0x18
    AreaHitShape* mpShape;  // offset: 0x20
    u32 mAttr;  // offset: 0x28
    MtVector3 mWorld;  // offset: 0x30
    MtVector3 mLocal;  // offset: 0x40
    MtVector3 mRotate;  // offset: 0x50
    f32 mCkAngle;  // offset: 0x60
    f32 mCkRange;  // offset: 0x64
    f32 mCkToward;  // offset: 0x68
    uDDOModel* mpSpTarget;  // offset: 0x70
    MtVector3 mRefPos;  // offset: 0x80
    u32 mRefJointNo;  // offset: 0x90
    u32 mOwnerJointNo;  // offset: 0x94
public:
    static MyDTI DTI;
};
