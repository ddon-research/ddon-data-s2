#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

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
    // inferred: rNamedParam::loadData names cNamedParam::mID
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
    // Address: 0x01a9de50 - 0x01a9de51 (1 bytes)
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
