#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cEfcHandle;
class cHitInfo;

// Declarations
class cShlParamFriendSupport;
class uShlFriendSupport;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamFriendSupport : public cShlParamBase
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamFriendSupport();
    virtual ~cShlParamFriendSupport();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    s32 mCheckShl;  // offset: 0x160
    f32 mConstInterval;  // offset: 0x164
    f32 mSpeedInit;  // offset: 0x168
    f32 mAccel;  // offset: 0x16c
    f32 mSpeedLimit;  // offset: 0x170
    f32 mDistanceLimit;  // offset: 0x174
    bool mFlgStopArrive;  // offset: 0x178
    s32 mJobCommonEffectIndex;  // offset: 0x17c
    s32 mJobCommonEffectNo;  // offset: 0x180
    static MyDTI DTI;
};

class uShlFriendSupport : public uShlBase
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
    const cShlParamFriendSupport* getShlParam() const;
    uShlFriendSupport();
    virtual ~uShlFriendSupport();
    virtual void initSub();  // vtable slot 177
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
    virtual void updateSub();  // vtable slot 175
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void kill();  // vtable slot 16
private:
    void movePos();
private:
    f32 mSpeedY;  // offset: 0x2ab0
    bool mFlgMove;  // offset: 0x2ab4
    cEfcHandle* mpJobCommonEfcHandle;  // offset: 0x2ab8
public:
    static MyDTI DTI;
};

inline void* cShlParamFriendSupport::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamFriendSupport::cShlParamFriendSupport() {
    this->mCheckShl = -1;
    this->mConstInterval = 30.0f;
    this->mSpeedLimit = 0.0f;
    this->mDistanceLimit = 0.0f;
    this->mSpeedInit = 0.0f;
    this->mAccel = 0.0f;
    this->mFlgStopArrive = true;
    this->mJobCommonEffectIndex = -1;
    this->mJobCommonEffectNo = -1;
}

inline void* uShlFriendSupport::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlFriendSupport::uShlFriendSupport() {
    this->mSpeedY = 0.0f;
    this->mFlgMove = false;
    this->mpJobCommonEfcHandle = nullptr;
}
