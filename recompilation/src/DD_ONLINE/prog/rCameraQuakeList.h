#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class MtVector3;
class sCameraExt;

// Declarations
class cQuakeParam;
class rCameraQuakeList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class cQuakeParam : public MtObject
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
    cQuakeParam();
    virtual ~cQuakeParam();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyTool(MtPropertyList& s);  // vtable slot 6
    void QuakeStart(uintptr task) const;
    void QuakeStartPos(uintptr task, const MtVector3& pos) const;
    void QuakeCancel(uintptr task) const;
    cQuakeParam& operator=(const cQuakeParam&);
    void copy(const cQuakeParam* pParam);
public:
    MtString mName;  // offset: 0x8
    f32 mHeadTime;  // offset: 0x10
    f32 mMainTime;  // offset: 0x14
    f32 mTailTime;  // offset: 0x18
    MtVector3 mMagnitude;  // offset: 0x20
    MtVector3 mPos;  // offset: 0x30
    f32 mRadius;  // offset: 0x40
    f32 mSpread;  // offset: 0x44
    f32 mDamping;  // offset: 0x48
    f32 mPeriod;  // offset: 0x4c
    f32 mRoll;  // offset: 0x50
    f32 mBalance;  // offset: 0x54
    bool mbAsync;  // offset: 0x58
    f32 mCamera1QuakeTime;  // offset: 0x5c
    f32 mTarget1QuakeTime;  // offset: 0x60
    f32 mRoll1QuakeTime;  // offset: 0x64
    f32 mRandDrop;  // offset: 0x68
    u32 mHeadCurve;  // offset: 0x6c
    u32 mTailCurve;  // offset: 0x70
    static MyDTI DTI;
};

class rCameraQuakeList : public cResource
{
    friend class sCameraExt;
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
    rCameraQuakeList();
    virtual ~rCameraQuakeList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    const MtArray& getQuakeList() const;
    void setQuakeList(const MtArray& list);
    const cQuakeParam* getQuakeParam(u32 index);
protected:
    MtArray mQuakeList;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u8 DATA_VERSION = 1;
};

inline void* cQuakeParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rCameraQuakeList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cQuakeParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cQuakeParam::DTI)->memFree(p_addr);
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cQuakeParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuakeParam::DTI)->memAlloc(sz, align, ::cQuakeParam::DTI.::MtDTI::getID());
}

inline cQuakeParam::cQuakeParam() {
    this->mTailTime = 0.0f;
    this->mHeadTime = 0.0f;
    this->mMainTime = 0.0f;
    this->mMagnitude.x = ::MtVector3::Zero.x;
    this->mMagnitude.y = ::MtVector3::Zero.y;
    this->mMagnitude.z = ::MtVector3::Zero.z;
    this->mMagnitude.pad_ = 0.0f;
    this->mPos.x = ::MtVector3::Zero.x;
    this->mPos.y = ::MtVector3::Zero.y;
    this->mPos.z = ::MtVector3::Zero.z;
    this->mbAsync = false;
    this->mBalance = 0.0f;
    this->mPeriod = 0.0f;
    this->mRoll = 0.0f;
    this->mSpread = 0.0f;
    this->mDamping = 0.0f;
    this->mPos.pad_ = 0.0f;
    this->mRadius = 0.0f;
    this->mCamera1QuakeTime = 0.1f;
    this->mTarget1QuakeTime = 0.1f;
    this->mRoll1QuakeTime = 0.1f;
    this->mRandDrop = 0.5f;
    this->mHeadCurve = 1;
    this->mTailCurve = 1;
}

inline void* rCameraQuakeList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rCameraQuakeList::DTI)->memAlloc(sz, align, ::rCameraQuakeList::DTI.::MtDTI::getID());
}

inline void rCameraQuakeList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rCameraQuakeList::DTI)->memFree(p_addr);
}

inline rCameraQuakeList::rCameraQuakeList() {
    this->::cResource::setAttribute(18u);
    this->mQuakeList.mAutoDelete = true;
}
