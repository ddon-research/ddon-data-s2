#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/rConstraint.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;
class uConstraint;

// Declarations
class rCnsTinyChain;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rCnsTinyChain : public rConstraint
{
public:
    class MyDTI;
    struct Header;
    struct ChainData;
    struct ChainGroup;
    struct ChainNode;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Header
    {
    public:
        Header();
    public:
        u32 magic;  // offset: 0x0
        u32 version;  // offset: 0x4
    };
public:
    struct ChainData
    {
    public:
        u32 ChainGroupNum;  // offset: 0x0
        u32 ChainNodeAllNum;  // offset: 0x4
        u32 Attr;  // offset: 0x8
        f32 StepTime;  // offset: 0xc
        f32 GravityScaling;  // offset: 0x10
        f32 GlobalDamping;  // offset: 0x14
        f32 GlobalTransForceCoef;  // offset: 0x18
        f32 SpringScaling;  // offset: 0x1c
        f32 WindScaling;  // offset: 0x20
        union
        {
        public:
            struct
            {
            public:
                u8 SolveStrNum;  // offset: 0x0
                u8 SolveAngNum;  // offset: 0x1
                u8 SolveMdlColNum;  // offset: 0x2
                u8 SolveSelColNum;  // offset: 0x3
            };  // offset: 0x0
            u32 calcNum0;  // offset: 0x0
        };  // offset: 0x24
        union
        {
        public:
            struct
            {
            public:
                u8 SolveScrColNum;  // offset: 0x0
                u8 SolveChnColNum;  // offset: 0x1
                u8 Reserved[2];  // offset: 0x2
            };  // offset: 0x0
            u32 calcNum1;  // offset: 0x0
        };  // offset: 0x28
    };
public:
    struct ChainGroup
    {
    public:
        u32 NodeNum;  // offset: 0x0
        u32 Attr;  // offset: 0x4
        u32 ColAttribute;  // offset: 0x8
        u32 ColGroup;  // offset: 0xc
        u32 ColType;  // offset: 0x10
        MtVector3 Gravity;  // offset: 0x20
        f32 Damping;  // offset: 0x30
        f32 TransForceCoef;  // offset: 0x34
        f32 SpringCoef;  // offset: 0x38
        f32 WindCoef;  // offset: 0x3c
        f32 LimitForce;  // offset: 0x40
        f32 FrictionCoef;  // offset: 0x44
        f32 ReflectCoef;  // offset: 0x48
    };
public:
    struct ChainNode
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u8 JointNo;  // offset: 0x0
                u8 Attr;  // offset: 0x1
                u8 Attach;  // offset: 0x2
                u8 RotMode;  // offset: 0x3
            };  // offset: 0x0
            u32 param0;  // offset: 0x0
        };  // offset: 0x0
        union
        {
        public:
            struct
            {
            public:
                u8 AngleMode;  // offset: 0x0
                u8 RefJntNo;  // offset: 0x1
                u8 ShapeObject;  // offset: 0x2
                u8 ShapeScroll;  // offset: 0x3
            };  // offset: 0x0
            u32 param1;  // offset: 0x0
        };  // offset: 0x4
        f32 R;  // offset: 0x8
        MtMatrix AngleAxis;  // offset: 0x10
        f32 AngleLimit;  // offset: 0x50
        f32 Mass;  // offset: 0x54
        f32 ElasticCoef;  // offset: 0x58
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
    rCnsTinyChain();
    virtual ~rCnsTinyChain();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual void copyUnitProperty(uConstraint* pSrcUnit);  // vtable slot 16
public:
    Header mHeader;  // offset: 0x78
    ChainData mData;  // offset: 0x80
    ChainGroup* mpChainGroup;  // offset: 0xb0
    ChainNode* mpChainNode;  // offset: 0xb8
    static MyDTI DTI;
    static const u32 DATA_VERSION = 22;
};
