#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cAreaHit.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cAreaHit;

// Declarations
class AHShapeBox;
class AHShapeBoxRotate;
class AHShapeCone;
class AHShapeCylinder;
class AHShapePolygon;
class AHShapeSphere;
class AHShapeTriangle;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class AHShapeBox : public AreaHitShape
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
    AHShapeBox();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual AreaHitShape& operator=(const AreaHitShape& shape);  // vtable slot 8
    virtual bool hitCheck(const MtVector3& pos) const;  // vtable slot 10
    virtual bool calcIntersectionLine(cAreaHit* pArea, const MtVector3& pos0, const MtVector3& pos1, MtVector3& pos_out) const;  // vtable slot 11
protected:
    virtual void makeCircle();  // vtable slot 9
public:
    void setPos(u32 posNo, MtVector3& pos);
    void setPos(u32 posNo, f32 vecX, f32 vecY, f32 vecZ);
    MtVector3 getPos(u32 posNo) const;
    virtual void setCenter(const MtVector3& pos);  // vtable slot 12
    virtual MtVector3 getCenter() const;  // vtable slot 13
    void setHeight(f32);
    virtual f32 getHeight();  // vtable slot 14
    f32 getPosY();
    virtual AREAHIT_SHAPE_TYPE_ENUM getShapeType() const;  // vtable slot 15
protected:
    MtVector3 mPos[4];  // offset: 0x50
    f32 mPosY;  // offset: 0x90
    f32 mHeight;  // offset: 0x94
    MtVector3 mCircleCenter;  // offset: 0xa0
    f32 mCircleRadSq;  // offset: 0xb0
public:
    static MyDTI DTI;
    static const u32 POS_NUM = 4;
};

class AHShapeBoxRotate : public AreaHitShape
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
    AHShapeBoxRotate();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual AreaHitShape& operator=(const AreaHitShape& shape);  // vtable slot 8
    virtual void makeCircle();  // vtable slot 9
    virtual MtVector3 getCenter() const;  // vtable slot 10
    virtual void setCenter(const MtVector3& pos);  // vtable slot 11
    void setHeight(f32);
    virtual f32 getHeight();  // vtable slot 12
    void setPos(u32 posNo, MtVector3& pos);
    void setPos(u32 posNo, f32 vecX, f32 vecY, f32 vecZ);
    MtVector3 getPos(u32 posNo) const;
    virtual AREAHIT_SHAPE_TYPE_ENUM getShapeType() const;  // vtable slot 13
    virtual bool hitCheck(const MtVector3& _pos) const;  // vtable slot 14
    u32 getNum() const;
    void setNum(const u32);
    virtual MtVector3 getAngle() const;  // vtable slot 15
    virtual void setAngle(const MtVector3& ang);  // vtable slot 16
protected:
    f32 mHeight;  // offset: 0x50
    MtVector3 mCtr;  // offset: 0x60
    MtVector3 mPos[4];  // offset: 0x70
    MtVector3 mAngle;  // offset: 0xb0
    MtVector3 mCircleCenter;  // offset: 0xc0
    f32 mCircleRadSq;  // offset: 0xd0
public:
    static MyDTI DTI;
    static const u32 POS_NUM = 4;
};

class AHShapeCone : public AreaHitShape
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
    AHShapeCone();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual AreaHitShape& operator=(const AreaHitShape& shape);  // vtable slot 8
    virtual bool hitCheck(const MtVector3& pos) const;  // vtable slot 10
    virtual void setCenter(const MtVector3& pos);  // vtable slot 11
    virtual MtVector3 getCenter() const;  // vtable slot 12
    void setTopRadius(f32);
    f32 getTopRadius();
    void setBottomRadius(f32);
    f32 getBottomRadius();
    virtual f32 getHeight();  // vtable slot 13
    virtual AREAHIT_SHAPE_TYPE_ENUM getShapeType() const;  // vtable slot 14
public:
    MtVector3 mCenterPos;  // offset: 0x50
    f32 mHeight;  // offset: 0x60
    f32 mTopRadius;  // offset: 0x64
    f32 mBottomRadius;  // offset: 0x68
    static MyDTI DTI;
};

class AHShapeCylinder : public AreaHitShape
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
    AHShapeCylinder();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual AreaHitShape& operator=(const AreaHitShape& shape);  // vtable slot 8
    virtual bool hitCheck(const MtVector3& pos) const;  // vtable slot 10
    virtual MtVector3 getCenter() const;  // vtable slot 11
    virtual void setCenter(const MtVector3& pos);  // vtable slot 12
    void setHeight(f32);
    virtual f32 getHeight();  // vtable slot 13
    void setRadius(f32);
    f32 getRadius();
    virtual AREAHIT_SHAPE_TYPE_ENUM getShapeType() const;  // vtable slot 14
protected:
    MtVector3 mCenterPos;  // offset: 0x50
    f32 mHeight;  // offset: 0x60
    f32 mRadius;  // offset: 0x64
public:
    static MyDTI DTI;
};

class AHShapePolygon : public AreaHitShape
{
public:
    class MyDTI;
    class PosUnit;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class PosUnit : public MtObject
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
        PosUnit(const MtVector3& pos, u32 index0, u32 index1);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual AHShapePolygon::PosUnit& operator=(const AHShapePolygon::PosUnit& unit);  // vtable slot 6
        void setPos(const MtVector3& pos);
        MtVector3 getPos();
        MtVector3* getPosPtr();
        void checkSetChild0(u32 posNo);
        void checkSetChild1(u32 posNo);
        u32 getChildIndex0();
        u32 getChildIndex1();
        void setOwner(AHShapePolygon*);
    protected:
        AHShapePolygon* mpOwner;  // offset: 0x8
        MtVector3 mPos;  // offset: 0x10
    public:
        u32 mChildPosIndex[2];  // offset: 0x20
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
    AHShapePolygon();
    virtual ~AHShapePolygon();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual AreaHitShape& operator=(const AreaHitShape& shape);  // vtable slot 8
    virtual bool hitCheck(const MtVector3& tarPos) const;  // vtable slot 10
    virtual void makeCircle();  // vtable slot 9
    void changeChildPos(PosUnit* pUnit, u32 index, u32 posNo);
    void setCreate(bool);
    void setDelete(bool, s32);
    void setPos(u32 posNo, MtVector3& pos);
    MtVector3 getPos(u32 posNo) const;
    MtVector3* getPosPtr(u32 posNo);
    void setHeight(f32 height);
    virtual MtVector3 getCenter() const;  // vtable slot 11
    virtual void setCenter(const MtVector3& pos);  // vtable slot 12
    virtual AREAHIT_SHAPE_TYPE_ENUM getShapeType() const;  // vtable slot 13
protected:
    MtArray mPosList;  // offset: 0x50
    MtArray mShapeList;  // offset: 0x70
    f32 mHeight;  // offset: 0x90
    f32 mPosY;  // offset: 0x94
    bool mbCreate;  // offset: 0x98
    bool mbDelete;  // offset: 0x99
    s32 mDelIndex;  // offset: 0x9c
    MtVector3 mCircleCenter;  // offset: 0xa0
    f32 mCircleRadSq;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class AHShapeSphere : public AreaHitShape
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
    AHShapeSphere();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual AreaHitShape& operator=(const AreaHitShape& shape);  // vtable slot 8
    virtual bool hitCheck(const MtVector3& pos) const;  // vtable slot 10
    virtual MtVector3 getCenter() const;  // vtable slot 11
    virtual void setCenter(const MtVector3& pos);  // vtable slot 12
    void setRadius(f32);
    f32 getRadius();
    virtual AREAHIT_SHAPE_TYPE_ENUM getShapeType() const;  // vtable slot 13
protected:
    MtVector3 mCenterPos;  // offset: 0x50
    f32 mRadius;  // offset: 0x60
public:
    static MyDTI DTI;
};

class AHShapeTriangle : public AreaHitShape
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
    AHShapeTriangle();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual AreaHitShape& operator=(const AreaHitShape& shape);  // vtable slot 8
    virtual bool hitCheck(const MtVector3& pos) const;  // vtable slot 10
    void setCorePos(MtVector3* pos, u32 index);
    MtVector3 getCorePos() const;
    void setSubPos(u32 index, MtVector3* pos);
    void setHeight(f32 height);
protected:
    MtVector3* mCorePos;  // offset: 0x50
    MtVector3* mSubPos[2];  // offset: 0x58
    f32 mHeight;  // offset: 0x68
public:
    u32 mIndex;  // offset: 0x6c
    static MyDTI DTI;
    static const u32 SUBPOS_NUM = 2;
};

inline void* AHShapeBox::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* AHShapeBoxRotate::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* AHShapeCone::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* AHShapeCylinder::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* AHShapePolygon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* AHShapePolygon::PosUnit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* AHShapeSphere::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* AHShapeTriangle::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline AHShapeTriangle::AHShapeTriangle() {
    this->mSubPos[1] = nullptr;
    this->mSubPos[0] = nullptr;
    this->mCorePos = nullptr;
    this->mHeight = 100.0f;
    this->mIndex = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void AHShapeBox::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::AHShapeBox::DTI)->memFree(p_addr);
}

inline void AHShapeBoxRotate::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::AHShapeBoxRotate::DTI)->memFree(p_addr);
}

inline void* AHShapeCone::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::AHShapeCone::DTI)->memAlloc(sz, align, ::AHShapeCone::DTI.::MtDTI::getID());
}

inline void AHShapeCone::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::AHShapeCone::DTI)->memFree(p_addr);
}

inline AHShapeCone::AHShapeCone() {
    this->mCenterPos.x = ::MtVector3::Zero.x;
    this->mCenterPos.y = ::MtVector3::Zero.y;
    this->mCenterPos.z = ::MtVector3::Zero.z;
    this->mCenterPos.pad_ = 0.0f;
    this->mHeight = 300.0f;
    this->mTopRadius = 250.0f;
    this->mBottomRadius = 100.0f;
}

inline void* AHShapeCylinder::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::AHShapeCylinder::DTI)->memAlloc(sz, align, ::AHShapeCylinder::DTI.::MtDTI::getID());
}

inline void AHShapeCylinder::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::AHShapeCylinder::DTI)->memFree(p_addr);
}

inline AHShapeCylinder::AHShapeCylinder() {
    this->mCenterPos.x = ::MtVector3::Zero.x;
    this->mCenterPos.y = ::MtVector3::Zero.y;
    this->mCenterPos.z = ::MtVector3::Zero.z;
    this->mCenterPos.pad_ = 0.0f;
    this->mHeight = 300.0f;
    this->mRadius = 200.0f;
}

inline void AHShapePolygon::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::AHShapePolygon::DTI)->memFree(p_addr);
}

inline void AHShapePolygon::PosUnit::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::AHShapePolygon::PosUnit::DTI)->memFree(p_addr);
}

inline void* AHShapeSphere::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::AHShapeSphere::DTI)->memAlloc(sz, align, ::AHShapeSphere::DTI.::MtDTI::getID());
}

inline void AHShapeSphere::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::AHShapeSphere::DTI)->memFree(p_addr);
}

inline AHShapeSphere::AHShapeSphere() {
    this->mCenterPos.x = ::MtVector3::Zero.x;
    this->mCenterPos.y = ::MtVector3::Zero.y;
    this->mCenterPos.z = ::MtVector3::Zero.z;
    this->mCenterPos.pad_ = 0.0f;
    this->mRadius = 100.0f;
}

inline void* AHShapeTriangle::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::AHShapeTriangle::DTI)->memAlloc(sz, align, ::AHShapeTriangle::DTI.::MtDTI::getID());
}

inline void AHShapeTriangle::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::AHShapeTriangle::DTI)->memFree(p_addr);
}
