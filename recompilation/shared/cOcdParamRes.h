#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cOcdBase;
class rOcdImmuneParamRes;

// Declarations
class cOcdImmuneParamRes;
class cOcdStatusParamRes;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cOcdImmuneParamRes : public MtObject
{
    // inferred: cOcdBase::setImuuneParamRes names cOcdImmuneParamRes::mImmuneRate
    friend class cOcdBase;
    // inferred: rOcdImmuneParamRes::loadData names cOcdImmuneParamRes::mOcdUID
    friend class rOcdImmuneParamRes;
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
    cOcdImmuneParamRes();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void copyParam(const cOcdImmuneParamRes&);
    u32 getOcdUID() const;
    f32 getImmuneRate() const;
    u32 getImmuneNum() const;
private:
    u32 mOcdUID;  // offset: 0x8
    f32 mImmuneRate;  // offset: 0xc
    u32 mImmuneNum;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cOcdStatusParamRes : public MtObject
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
    cOcdStatusParamRes();
    void copyParam(const cOcdStatusParamRes& param);
    void copyEffectiveParam(const cOcdStatusParamRes& param);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setOcdUID(u32 OcdUID);
    u32 getOcdUID() const;
    bool isEffective() const;
    f32 getEndurance() const;
    bool isTimeRecover() const;
    f32 getActiveTime() const;
    f32 getCureWaitTime() const;
    f32 getCureValue() const;
    f32 getFreeParam0() const;
    f32 getFreeParam1() const;
    void setEffective(bool isEffective);
    void setIsTimeRecover(bool isTimeRecover);
    void setEndurance(f32 endurance);
    void setActiveTime(f32 ActiveTime);
    void setCureValue(f32 CureValue);
    void setCureWaitTime(f32 value);
    void setFreeParam0(f32 FreeParam0);
    void setFreeParam1(f32 FreeParam1);
    f32 getEnduranceCheatCheck() const;
    f32 getActiveTimeCheatCheck() const;
    f32 getCureValueCheatCheck() const;
    f32 getFreeParam0CheatCheck() const;
    f32 getFreeParam1CheatCheck() const;
private:
    void setEnduranceCheatCheck(f32 value);
    void setActiveTimeCheatCheck(f32 value);
    void setCureValueCheatCheck(f32 value);
    void setFreeParam0CheatCheck(f32 value);
    void setFreeParam1CheatCheck(f32 value);
    f32 getEndurancePrivate() const;
    void setEndurancePrivate(f32 NewValue);
    f32 getActiveTimePrivate() const;
    void setActiveTimePrivate(f32 NewValue);
    f32 getCureValuePrivate() const;
    void setCureValuePrivate(f32 NewValue);
    f32 getFreeParam0Private() const;
    void setFreeParam0Private(f32 NewValue);
    f32 getFreeParam1Private() const;
    void setFreeParam1Private(f32 NewValue);
    f32 getEnduranceCheatCheckPrivate() const;
    void setEnduranceCheatCheckPrivate(f32 NewValue);
    f32 getActiveTimeCheatCheckPrivate() const;
    void setActiveTimeCheatCheckPrivate(f32 NewValue);
    f32 getCureValueCheatCheckPrivate() const;
    void setCureValueCheatCheckPrivate(f32 NewValue);
    f32 getFreeParam0CheatCheckPrivate() const;
    void setFreeParam0CheatCheckPrivate(f32 NewValue);
    f32 getFreeParam1CheatCheckPrivate() const;
    void setFreeParam1CheatCheckPrivate(f32 NewValue);
private:
    u32 mOcdUID;  // offset: 0x8
    bool mIsEffective;  // offset: 0xc
    f32 mEndurance;  // offset: 0x10
    bool mIsTimeRecover;  // offset: 0x14
    f32 mActiveTime;  // offset: 0x18
    f32 mCureWaitTime;  // offset: 0x1c
    f32 mCureValue;  // offset: 0x20
    f32 mFreeParam0;  // offset: 0x24
    f32 mFreeParam1;  // offset: 0x28
    f32 mEnduranceCheatCheck;  // offset: 0x2c
    f32 mActiveTimeCheatCheck;  // offset: 0x30
    f32 mCureValueCheatCheck;  // offset: 0x34
    f32 mFreeParam0CheatCheck;  // offset: 0x38
    f32 mFreeParam1CheatCheck;  // offset: 0x3c
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline f32 cOcdStatusParamRes::getCureWaitTime() const {
    return this->mCureWaitTime;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cOcdStatusParamRes::getEndurancePrivate() const {
    return this->mEndurance;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cOcdStatusParamRes::getActiveTimePrivate() const {
    return this->mActiveTime;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cOcdStatusParamRes::getCureValuePrivate() const {
    return this->mCureValue;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cOcdStatusParamRes::getFreeParam0Private() const {
    return this->mFreeParam0;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cOcdStatusParamRes::getFreeParam1Private() const {
    return this->mFreeParam1;
}
