#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"

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

inline void* rLocationData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rLocationData::Data::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* rLocationData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rLocationData::DTI)->memAlloc(sz, align, ::rLocationData::DTI.::MtDTI::getID());
}

inline void rLocationData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rLocationData::DTI)->memFree(p_addr);
}

inline rLocationData::rLocationData() {
    this->::cResource::setAttribute(22u);
    this->mpArray = nullptr;
    this->mArrayNum = 0;
}

inline void rLocationData::destruct() {
    unsigned int i0 = 0;
    if (this->mArrayNum != 0) {
        do {
            this->mpArray[i0].~Data();
            i0 += 1u;
        } while (i0 < this->mArrayNum);
    }
    ::MtMemoryAllocator::getAllocator(::rLocationData::DTI)->memFree(static_cast<void*>(this->mpArray));
    this->mpArray = nullptr;
    this->mArrayNum = 0;
}

inline void* rLocationData::Data::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rLocationData::Data::DTI)->memAlloc(sz, align, ::rLocationData::Data::DTI.::MtDTI::getID());
}

inline void rLocationData::Data::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rLocationData::Data::DTI)->memFree(p_addr);
}

inline rLocationData::Data::Data() {
    this->mPos.x = ::MtVector3::Zero.x;
    this->mPos.y = ::MtVector3::Zero.y;
    this->mPos.z = ::MtVector3::Zero.z;
    this->mPos.pad_ = 0.0f;
    this->mRadius = 100.0f;
    this->mAngle = 0.0f;
    this->mRange = 360.0f;
    this->mVersion = 0;
    this->mSafeZone = false;
    this->mMessageNo = 0;
    this->mType = 0;
    this->mWarpPointId = 0;
}
