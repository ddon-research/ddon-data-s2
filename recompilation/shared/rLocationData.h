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
class MtDataReader;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;

// Declarations
class rLocationData;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rLocationData : public cResource
{
public:
    enum
    {
        TYPE_ONCE = 0,
        TYPE_TRIGGER = 1,
    };
public:
    class MyDTI;
    class Data;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Data : public MtObject
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
        Data();
        // Address: 0x01a9b9d0 - 0x01a9b9d1 (1 bytes)
        virtual ~Data() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool load(MtDataReader& r);
        void copy(rLocationData::Data* src);
        bool hitcheck(MtVector3& pl_pos, f32 pl_ang_y);
        bool hitcheck(MtVector3& pl_pos);
        bool isSafeZone();
    public:
        MtVector3 mPos;  // offset: 0x10
        f32 mRadius;  // offset: 0x20
        f32 mAngle;  // offset: 0x24
        f32 mRange;  // offset: 0x28
        u16 mMessageNo;  // offset: 0x2c
        u16 mType;  // offset: 0x2e
        u32 mWarpPointId;  // offset: 0x30
        bool mSafeZone;  // offset: 0x34
        u32 mVersion;  // offset: 0x38
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
    rLocationData();
    virtual ~rLocationData();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MT_CTSTR getName() const;  // vtable slot 16
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual Data* getData(u32 index) const;  // vtable slot 17
    virtual u32 getDataNum() const;  // vtable slot 18
public:
    Data* mpArray;  // offset: 0x70
    u32 mArrayNum;  // offset: 0x78
    static const u32 LOCATION_NUM = 128;
    static const u8 DATA_VERSION = 16;
    static MyDTI DTI;
};
