#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "nShlBase.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class uDDOModel;

// Declarations
class cShlParamFollowMove;
class uShlFollowMove;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamFollowMove : public cShlParamBase
{
public:
    enum CONST_OWNER_TYPE
    {
        CONST_SHELL_OWNER = 0,
        CONST_SHELL_TARGET = 1,
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cShlParamFollowMove();
    virtual ~cShlParamFollowMove();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    s32 jointNo;  // offset: 0x160
    MtVector3 offset;  // offset: 0x170
    bool isNoConstOwner;  // offset: 0x180
    u32 mConstOwnerType;  // offset: 0x184
    nShlBase::LIMIT_FOLLOW followLimitId;  // offset: 0x188
    static MyDTI DTI;
};

class uShlFollowMove : public uShlBase
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
    const cShlParamFollowMove* getShlParam() const;
    uShlFollowMove();
    virtual ~uShlFollowMove();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setAliveOwnerStatus(u32);
    void setConstOwner(uDDOModel* pConst);
    uDDOModel* getConstOwner() const;
private:
    u32 mAliveOwnerStatus;  // offset: 0x2ab0
    uDDOModel* mpConstOwner;  // offset: 0x2ab8
public:
    static MyDTI DTI;
};

inline void* cShlParamFollowMove::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamFollowMove::cShlParamFollowMove() {
    this->jointNo = -1;
    this->mConstOwnerType = 0;
    this->isNoConstOwner = false;
    this->offset.z = 0.0f;
    this->offset.pad_ = 0.0f;
    this->offset.x = 0.0f;
    this->offset.y = 0.0f;
    this->followLimitId = static_cast<nShlBase::LIMIT_FOLLOW>(-1);
}

inline void* uShlFollowMove::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
