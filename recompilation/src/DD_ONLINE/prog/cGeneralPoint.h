#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;
class sGeneralPoint;
class uBaseModel;
class uDDOModel;

// Declarations
class cGeneralPoint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGeneralPoint : public MtObject
{
    friend class sGeneralPoint;
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
    cGeneralPoint();
    virtual ~cGeneralPoint() {}
    uBaseModel* getBaseModelOwner();
    uDDOModel* getDDOModelOwner();
    const uDDOModel* getDDOModelOwner() const;
    virtual void updatePoint();  // vtable slot 6
    void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
    bool isRefEnable() const;
    void setRefEnable(bool IsEnable);
    s32 getCategory() const;
    void setReqCategory(s32 category);
    bool isActive() const;
    void setActive(bool isActive);
private:
    bool isGpEnable() const;
    void reqKill();
public:
    MtVector3 mPos;  // offset: 0x10
    MtVector3 mAngle;  // offset: 0x20
    f32 mRadius;  // offset: 0x30
    u32 mJntNo;  // offset: 0x34
    MtObject* mpOwner;  // offset: 0x38
    s32 mObjectID;  // offset: 0x40
    s32 mUniqueID;  // offset: 0x44
protected:
    s32 mCategoryReq;  // offset: 0x48
    s32 mCategory;  // offset: 0x4c
    bool mKillReq;  // offset: 0x50
    bool mIsRefEnable;  // offset: 0x51
    bool mIsActive;  // offset: 0x52
public:
    static MyDTI DTI;
};

inline void cGeneralPoint::setReqCategory(s32 category) {
    this->mCategoryReq = category;
}

inline void cGeneralPoint::reqKill() {
    this->mKillReq = true;
}
