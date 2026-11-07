#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;

// Declarations
class cNamedParam;
class rNamedParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cNamedParam : public MtObject
{
    friend class rNamedParam;
public:
    enum NAMED_TYPE
    {
        NAMED_TYPE_NONE = 1,
        NAMED_TYPE_PREFIX = 2,
        NAMED_TYPE_SUFFIX = 3,
        NAMED_TYPE_REPLACE = 4,
    };
    enum
    {
        NAMED_ID_NONE = 1,
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
    cNamedParam();
    virtual ~cNamedParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getID() const;
    void setID(u32 NewValue);
    u32 getType() const;
    void setType(u32 NewValue);
    u32 getHpRate() const;
    void setHpRate(u32 NewValue);
    u16 getExperience() const;
    void setExperience(u16 NewValue);
    u16 getAttackBasePhys() const;
    void setAttackBasePhys(u16 NewValue);
    u16 getAttackWepPhys() const;
    void setAttackWepPhys(u16 NewValue);
    u16 getDefenceBasePhys() const;
    void setDefenceBasePhys(u16 NewValue);
    u16 getDefenceWepPhys() const;
    void setDefenceWepPhys(u16 NewValue);
    u16 getAttackBaseMagic() const;
    void setAttackBaseMagic(u16 NewValue);
    u16 getAttackWepMagic() const;
    void setAttackWepMagic(u16 NewValue);
    u16 getDefenceBaseMagic() const;
    void setDefenceBaseMagic(u16 NewValue);
    u16 getDefenceWepMagic() const;
    void setDefenceWepMagic(u16 NewValue);
    u16 getPower() const;
    void setPower(u16 NewValue);
    u16 getGuardDefenceBase() const;
    void setGuardDefenceBase(u16 NewValue);
    u16 getGuardDefenceWep() const;
    void setGuardDefenceWep(u16 NewValue);
    u16 getShrinkEnduranceMain() const;
    void setShrinkEnduranceMain(u16 NewValue);
    u16 getBlowEnduranceMain() const;
    void setBlowEnduranceMain(u16 NewValue);
    u16 getDownEnduranceMain() const;
    void setDownEnduranceMain(u16 NewValue);
    u16 getShakeEnduranceMain() const;
    void setShakeEnduranceMain(u16 NewValue);
    u16 getHpSub() const;
    void setHpSub(u16 NewValue);
    u16 getShrinkEnduranceSub() const;
    void setShrinkEnduranceSub(u16 NewValue);
    u16 getBlowEnduranceSub() const;
    void setBlowEnduranceSub(u16 NewValue);
    u16 getOcdEndurance() const;
    void setOcdEndurance(u16 NewValue);
    u16 getAilmentDamage() const;
    void setAilmentDamage(u16 NewValue);
private:
    u32 mID;  // offset: 0x8
    u32 mType;  // offset: 0xc
    u32 mHpRate;  // offset: 0x10
    u16 mExperience;  // offset: 0x14
    u16 mAttackBasePhys;  // offset: 0x16
    u16 mAttackWepPhys;  // offset: 0x18
    u16 mDefenceBasePhys;  // offset: 0x1a
    u16 mDefenceWepPhys;  // offset: 0x1c
    u16 mAttackBaseMagic;  // offset: 0x1e
    u16 mAttackWepMagic;  // offset: 0x20
    u16 mDefenceBaseMagic;  // offset: 0x22
    u16 mDefenceWepMagic;  // offset: 0x24
    u16 mPower;  // offset: 0x26
    u16 mGuardDefenceBase;  // offset: 0x28
    u16 mGuardDefenceWep;  // offset: 0x2a
    u16 mShrinkEnduranceMain;  // offset: 0x2c
    u16 mBlowEnduranceMain;  // offset: 0x2e
    u16 mDownEnduranceMain;  // offset: 0x30
    u16 mShakeEnduranceMain;  // offset: 0x32
    u16 mHpSub;  // offset: 0x34
    u16 mShrinkEnduranceSub;  // offset: 0x36
    u16 mBlowEnduranceSub;  // offset: 0x38
    u16 mOcdEndurance;  // offset: 0x3a
    u16 mAilmentDamage;  // offset: 0x3c
public:
    static MyDTI DTI;
    static const u32 DATA_VERSION = 5;
};

class rNamedParam : public rTbl2<cNamedParam>
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
    virtual bool loadData(MtDataReader& in, cNamedParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline void* cNamedParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cNamedParam::getID() const {
    return this->mID;
}

inline void cNamedParam::setID(u32 NewValue) {
    this->mID = NewValue;
}

inline u32 cNamedParam::getType() const {
    return this->mType;
}

inline void cNamedParam::setType(u32 NewValue) {
    this->mType = NewValue;
}

inline u32 cNamedParam::getHpRate() const {
    return this->mHpRate;
}

inline void cNamedParam::setHpRate(u32 NewValue) {
    this->mHpRate = NewValue;
}

inline u16 cNamedParam::getExperience() const {
    return this->mExperience;
}

inline void cNamedParam::setExperience(u16 NewValue) {
    this->mExperience = NewValue;
}

inline u16 cNamedParam::getAttackBasePhys() const {
    return this->mAttackBasePhys;
}

inline void cNamedParam::setAttackBasePhys(u16 NewValue) {
    this->mAttackBasePhys = NewValue;
}

inline u16 cNamedParam::getAttackWepPhys() const {
    return this->mAttackWepPhys;
}

inline void cNamedParam::setAttackWepPhys(u16 NewValue) {
    this->mAttackWepPhys = NewValue;
}

inline u16 cNamedParam::getDefenceBasePhys() const {
    return this->mDefenceBasePhys;
}

inline void cNamedParam::setDefenceBasePhys(u16 NewValue) {
    this->mDefenceBasePhys = NewValue;
}

inline u16 cNamedParam::getDefenceWepPhys() const {
    return this->mDefenceWepPhys;
}

inline void cNamedParam::setDefenceWepPhys(u16 NewValue) {
    this->mDefenceWepPhys = NewValue;
}

inline u16 cNamedParam::getAttackBaseMagic() const {
    return this->mAttackBaseMagic;
}

inline void cNamedParam::setAttackBaseMagic(u16 NewValue) {
    this->mAttackBaseMagic = NewValue;
}

inline u16 cNamedParam::getAttackWepMagic() const {
    return this->mAttackWepMagic;
}

inline void cNamedParam::setAttackWepMagic(u16 NewValue) {
    this->mAttackWepMagic = NewValue;
}

inline u16 cNamedParam::getDefenceBaseMagic() const {
    return this->mDefenceBaseMagic;
}

inline void cNamedParam::setDefenceBaseMagic(u16 NewValue) {
    this->mDefenceBaseMagic = NewValue;
}

inline u16 cNamedParam::getDefenceWepMagic() const {
    return this->mDefenceWepMagic;
}

inline void cNamedParam::setDefenceWepMagic(u16 NewValue) {
    this->mDefenceWepMagic = NewValue;
}

inline u16 cNamedParam::getPower() const {
    return this->mPower;
}

inline void cNamedParam::setPower(u16 NewValue) {
    this->mPower = NewValue;
}

inline u16 cNamedParam::getGuardDefenceBase() const {
    return this->mGuardDefenceBase;
}

inline void cNamedParam::setGuardDefenceBase(u16 NewValue) {
    this->mGuardDefenceBase = NewValue;
}

inline u16 cNamedParam::getGuardDefenceWep() const {
    return this->mGuardDefenceWep;
}

inline void cNamedParam::setGuardDefenceWep(u16 NewValue) {
    this->mGuardDefenceWep = NewValue;
}

inline u16 cNamedParam::getShrinkEnduranceMain() const {
    return this->mShrinkEnduranceMain;
}

inline void cNamedParam::setShrinkEnduranceMain(u16 NewValue) {
    this->mShrinkEnduranceMain = NewValue;
}

inline u16 cNamedParam::getBlowEnduranceMain() const {
    return this->mBlowEnduranceMain;
}

inline void cNamedParam::setBlowEnduranceMain(u16 NewValue) {
    this->mBlowEnduranceMain = NewValue;
}

inline u16 cNamedParam::getDownEnduranceMain() const {
    return this->mDownEnduranceMain;
}

inline void cNamedParam::setDownEnduranceMain(u16 NewValue) {
    this->mDownEnduranceMain = NewValue;
}

inline u16 cNamedParam::getShakeEnduranceMain() const {
    return this->mShakeEnduranceMain;
}

inline void cNamedParam::setShakeEnduranceMain(u16 NewValue) {
    this->mShakeEnduranceMain = NewValue;
}

inline u16 cNamedParam::getHpSub() const {
    return this->mHpSub;
}

inline void cNamedParam::setHpSub(u16 NewValue) {
    this->mHpSub = NewValue;
}

inline u16 cNamedParam::getShrinkEnduranceSub() const {
    return this->mShrinkEnduranceSub;
}

inline void cNamedParam::setShrinkEnduranceSub(u16 NewValue) {
    this->mShrinkEnduranceSub = NewValue;
}

inline u16 cNamedParam::getBlowEnduranceSub() const {
    return this->mBlowEnduranceSub;
}

inline void cNamedParam::setBlowEnduranceSub(u16 NewValue) {
    this->mBlowEnduranceSub = NewValue;
}

inline u16 cNamedParam::getOcdEndurance() const {
    return this->mOcdEndurance;
}

inline void cNamedParam::setOcdEndurance(u16 NewValue) {
    this->mOcdEndurance = NewValue;
}

inline u16 cNamedParam::getAilmentDamage() const {
    return this->mAilmentDamage;
}

inline void cNamedParam::setAilmentDamage(u16 NewValue) {
    this->mAilmentDamage = NewValue;
}

inline void* rNamedParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cNamedParam::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cNamedParam::DTI)->memFree(p_addr);
}

inline void* cNamedParam::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cNamedParam::DTI)->memAlloc(sz, align, ::cNamedParam::DTI.::MtDTI::getID());
}
