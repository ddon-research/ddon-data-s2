#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
class MtCylinder;
class MtDTI;
class MtDataReader;
class MtDataWriter;
struct MtFloat3A;
struct MtFloat3x3;
class MtOBB;
class MtObject;
class MtSphere;
class MtStream;
class MtVector3;
class cGeomConvexHull;

// Declarations
class rRigidBody;

// Type aliases from DWARF
using BYTE = unsigned char;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rRigidBody : public cResource
{
public:
    class MyDTI;
    struct HEADER;
    struct RIGID_BODY;
    struct GEOMETRY;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u32 Version;  // offset: 0x4
        u32 NumLevel : 8;  // offset: 0x8
        u32 NumRigidBody : 24;  // offset: 0x8
        u32 NumGeometry;  // offset: 0xc
        MtFloat3A ModelScale;  // offset: 0x10
        u32 NumParameter;  // offset: 0x1c
        u32 StartShowBit[4];  // offset: 0x20
    };
public:
    struct RIGID_BODY
    {
    public:
        s32 JointNo;  // offset: 0x0
        u32 StateBit;  // offset: 0x4
        u32 CollisionID;  // offset: 0x8
        u32 CollisionBit;  // offset: 0xc
        u32 PartBit[4];  // offset: 0x10
        MtFloat3A CenterOffset;  // offset: 0x20
        f32 Restitution;  // offset: 0x2c
        f32 StaticFriction;  // offset: 0x30
        f32 KineticFriction;  // offset: 0x34
        f32 LinearDamping;  // offset: 0x38
        f32 AngularDamping;  // offset: 0x3c
        MtFloat3x3 InertiaTensor;  // offset: 0x40
        u32 padding;  // offset: 0x64
        rRigidBody::GEOMETRY* Geometry;  // offset: 0x68
        u32 NumGeometry;  // offset: 0x70
        f32 Mass;  // offset: 0x74
        MtFloat3A LinearVelocity;  // offset: 0x78
        f32 MaxLinearVelocity;  // offset: 0x84
        MtFloat3A AngularVelocity;  // offset: 0x88
        f32 MaxAngularVelocity;  // offset: 0x94
        u32 reserve;  // offset: 0x98
        u32 LevelBit;  // offset: 0x9c
        u32 PrimaryFilter;  // offset: 0xa0
        u32 PrimaryAttribute;  // offset: 0xa4
        u32 SecondaryFilter;  // offset: 0xa8
        u32 SecondaryAttribute;  // offset: 0xac
        u32 ScrollType;  // offset: 0xb0
        u32 ScrollFilter;  // offset: 0xb4
    };
public:
    struct GEOMETRY
    {
    public:
        MtSphere getSphere() const;
        MtCapsule getCapsule() const;
        MtOBB getOBB() const;
        MtCylinder getCylinder() const;
        cGeomConvexHull getConvexHull() const;
    public:
        s32 Type : 16;  // offset: 0x0
        s32 MaterialNo : 16;  // offset: 0x0
        u32 padding;  // offset: 0x4
        f32* Parameter;  // offset: 0x8
        u32 UseBit;  // offset: 0x10
        f32 Density;  // offset: 0x14
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
    rRigidBody();
    virtual ~rRigidBody();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool save(MtStream& output);  // vtable slot 12
    virtual bool load(MtStream& input);  // vtable slot 11
protected:
    bool saveCore(MtDataWriter& writer);
    bool loadCore(MtDataReader& reader);
public:
    virtual void clear();  // vtable slot 15
    u32 getNumRigidBody() const;
    u32 getNumGeometry() const;
    MtVector3 getModelScale() const;
    const RIGID_BODY& getRigidBody(const u32 index) const;
    s32 getJointNo(const u32 index) const;
    bool isStartShowParts(const u32 index);
private:
    HEADER mHeader;  // offset: 0x70
    BYTE* mBuffer;  // offset: 0xa0
    RIGID_BODY* mRigidBody;  // offset: 0xa8
public:
    static const u32 MAX_PART = 128;
    static MyDTI DTI;
};
