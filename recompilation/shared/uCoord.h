#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;

// Declarations
class uCoord;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uCoord : public cUnit
{
public:
    enum ORDER
    {
        ORDER_XYZ = 0,
        ORDER_XZY = 1,
        ORDER_YXZ = 2,
        ORDER_YZX = 3,
        ORDER_ZXY = 4,
        ORDER_ZYX = 5,
    };
    enum PARENT_FLAG
    {
        PARENT_ANGLE = 1,
        PARENT_SCALE = 2,
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
    uCoord();
    virtual ~uCoord();
    virtual bool getBoundary(MtSphere* pdst);  // vtable slot 13
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void setParent(uCoord* pparent, s32 parent_no);  // vtable slot 24
    uCoord* getParent();
    s32 getParentNo();
    void setPos(const MtVector3& pos);
    void setAngle(const MtVector3& agl);
    void setAngleZXY(const MtVector4& v);
    void setAngle(f32 a);
    void setScale(const MtVector3& scl);
    void setQuat(const MtQuaternion& quat);
    const MtQuaternion& getQuat() const;
    const MtVector3& getPos() const;
    MtVector3 getWorldPos() const;
    MtVector3 getAngle() const;
    const MtVector3& getScale() const;
    virtual void updateLocalMatrix();  // vtable slot 25
    virtual void updateWorldMatrix();  // vtable slot 26
    virtual const MtMatrix& getWorldMatrix(s32 parent_no) const;  // vtable slot 27
    const MtMatrix& getLocalMatrix() const;
    const MtMatrix& getWorldNullMatrix() const;
    void setOrder(u32 order);
    u32 getOrder();
    void setParentFlags(u32 flags);
    u32 getParentFlags();
public:
    uCoord* mpParent;  // offset: 0x48
    s32 mParentNo;  // offset: 0x50
    u32 mOrder : 16;  // offset: 0x54
    u32 mParentFlags : 16;  // offset: 0x54
    MtVector3 mPos;  // offset: 0x60
    MtQuaternion mQuat;  // offset: 0x70
    MtVector3 mScale;  // offset: 0x80
    MtMatrix mLmat;  // offset: 0x90
    MtMatrix mWmat;  // offset: 0xd0
    static MyDTI DTI;
};
