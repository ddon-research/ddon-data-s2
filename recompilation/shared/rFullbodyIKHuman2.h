#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;

// Declarations
class rFullbodyIKHuman2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rFullbodyIKHuman2 : public cResource
{
public:
    class MyDTI;
    class JointAssign;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class JointAssign : public MtObject
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
        JointAssign();
        // Address: 0x01b5b780 - 0x01b5b781 (1 bytes)
        virtual ~JointAssign() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mFBIKJntNo;  // offset: 0x8
        u32 mTargetJntNo;  // offset: 0xc
        MtVector3 mEffOffset;  // offset: 0x10
        bool mRotate;  // offset: 0x20
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
    rFullbodyIKHuman2();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 getAssignedJointNum();
    void setAssignedJointNum(u32 Num);
    JointAssign* getAssignedJoint(u32 idx);
    void setAssignedJoint(JointAssign* pJointAssign, u32 idx);
protected:
    virtual ~rFullbodyIKHuman2();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
public:
    u32 mPri;  // offset: 0x70
    u32 mIteration;  // offset: 0x74
    f32 mUpperBodyRotRate;  // offset: 0x78
    f32 mUpperBodyTransRate;  // offset: 0x7c
    f32 mUpperBodySyncRate;  // offset: 0x80
    f32 mLowerBodyRotRate;  // offset: 0x84
    f32 mLowerBodyTransRate;  // offset: 0x88
    f32 mLowerBodySyncRate;  // offset: 0x8c
    f32 mHeadLookAtRate;  // offset: 0x90
    f32 mUpperBodyLookAtRate;  // offset: 0x94
    f32 mLowerBodyLookAtRate;  // offset: 0x98
    f32 mWaistHeightLimit;  // offset: 0x9c
    JointAssign mJointAssign[27];  // offset: 0xa0
    f32 mRCollarRotBlend;  // offset: 0x5b0
    f32 mLCollarRotBlend;  // offset: 0x5b4
    f32 mRCollarUpBlend;  // offset: 0x5b8
    f32 mRCollarDownBlend;  // offset: 0x5bc
    f32 mRCollarFrontBlend;  // offset: 0x5c0
    f32 mRCollarBackBlend;  // offset: 0x5c4
    f32 mLCollarUpBlend;  // offset: 0x5c8
    f32 mLCollarDownBlend;  // offset: 0x5cc
    f32 mLCollarFrontBlend;  // offset: 0x5d0
    f32 mLCollarBackBlend;  // offset: 0x5d4
    f32 mSpineUpperRotRate;  // offset: 0x5d8
    f32 mSpine0RotRate;  // offset: 0x5dc
    f32 mSpine1RotRate;  // offset: 0x5e0
    f32 mSpine2RotRate;  // offset: 0x5e4
    f32 mSpine3RotRate;  // offset: 0x5e8
    f32 mSpine4RotRate;  // offset: 0x5ec
    static MyDTI DTI;
protected:
    static const u16 DATA_VERSION = 0;
};
