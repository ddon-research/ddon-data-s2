#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "rTbl2.h"
#include "uCharacterEdit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;

// Declarations
class cCharacterEditCameraParam;
class rCharacterEditCameraParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCharacterEditCameraParam : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 4,
    };
public:
    class MyDTI;
    class cCameraParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCameraParam : public MtObject
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
        cCameraParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        s32 mAttachJoint;  // offset: 0x8
        MtVector3 mGlobalOffset;  // offset: 0x10
        MtVector3 mCameraOffset;  // offset: 0x20
        MtVector3 mTargetOffset;  // offset: 0x30
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
    cCharacterEditCameraParam();
    virtual ~cCharacterEditCameraParam();
public:
    MtString mName;  // offset: 0x8
    bool mUseFarParam;  // offset: 0x10
    f32 mNearFarParcent;  // offset: 0x14
    f32 mDefaultLength;  // offset: 0x18
    uCharacterEditCameraBase::cLimit mLimitRotateX;  // offset: 0x20
    uCharacterEditCameraBase::cLimit mLimitRotateY;  // offset: 0x30
    uCharacterEditCameraBase::cLimit mLimitLength;  // offset: 0x40
    cCameraParam mNear;  // offset: 0x50
    cCameraParam mFar;  // offset: 0x90
    static MyDTI DTI;
};

class rCharacterEditCameraParam : public rTbl2<cCharacterEditCameraParam>
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
    virtual bool loadData(MtDataReader& r, cCharacterEditCameraParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline void* cCharacterEditCameraParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCharacterEditCameraParam::cCameraParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rCharacterEditCameraParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cCharacterEditCameraParam::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCharacterEditCameraParam::DTI)->memFree(p_addr);
}

inline void* cCharacterEditCameraParam::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cCharacterEditCameraParam::DTI)->memAlloc(sz, align, ::cCharacterEditCameraParam::DTI.::MtDTI::getID());
}

inline MtAllocator* cCharacterEditCameraParam::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cCharacterEditCameraParam::DTI);
}

inline void* cCharacterEditCameraParam::operator new(size_t sz, u32 align) {
    return ::cCharacterEditCameraParam::getAllocator()->memAlloc(sz, align, ::cCharacterEditCameraParam::DTI.::MtDTI::getID());
}

inline void cCharacterEditCameraParam::operator delete(void* p_addr) {
    ::cCharacterEditCameraParam::getAllocator()->memFree(p_addr);
}

inline cCharacterEditCameraParam::cCharacterEditCameraParam() {
    mUseFarParam = false;
    mNearFarParcent = 0.5f;
    mDefaultLength = 200.0f;
    mLimitRotateX.set(0.4f, -0.7f);
    mLimitLength.set(440.0f, 170.0f);
}

inline MtAllocator* rCharacterEditCameraParam::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::rCharacterEditCameraParam::DTI);
}

inline void rCharacterEditCameraParam::operator delete(void* p_addr) {
    ::rCharacterEditCameraParam::getAllocator()->memFree(p_addr);
}

#include "../../generated/shared/nDDOIO.h"

inline bool cCharacterEditCameraParam::cCameraParam::load(MtDataReader& r) {
    nDDOIO::readData(r, mAttachJoint);
    nDDOIO::readData(r, mCameraOffset);
    nDDOIO::readData(r, mTargetOffset);
    nDDOIO::readData(r, mGlobalOffset);
    return true;
}

inline void* cCharacterEditCameraParam::cCameraParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cCharacterEditCameraParam::cCameraParam::DTI)->memAlloc(sz, align, ::cCharacterEditCameraParam::cCameraParam::DTI.::MtDTI::getID());
}

inline void cCharacterEditCameraParam::cCameraParam::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCharacterEditCameraParam::cCameraParam::DTI)->memFree(p_addr);
}

inline cCharacterEditCameraParam::cCameraParam::cCameraParam() {
    this->mAttachJoint = 3;
    this->mTargetOffset.x = ::MtVector3::Zero.x;
    this->mTargetOffset.y = ::MtVector3::Zero.y;
    this->mTargetOffset.z = ::MtVector3::Zero.z;
    this->mTargetOffset.pad_ = 0.0f;
    this->mCameraOffset.x = this->mTargetOffset.x;
    this->mCameraOffset.y = this->mTargetOffset.y;
    this->mCameraOffset.z = this->mTargetOffset.z;
    this->mCameraOffset.pad_ = 0.0f;
    this->mGlobalOffset.x = this->mCameraOffset.x;
    this->mGlobalOffset.y = this->mCameraOffset.y;
    this->mGlobalOffset.z = this->mCameraOffset.z;
    this->mGlobalOffset.pad_ = 0.0f;
}

inline void* rCharacterEditCameraParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rCharacterEditCameraParam::DTI)->memAlloc(sz, align, ::rCharacterEditCameraParam::DTI.::MtDTI::getID());
}
