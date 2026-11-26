#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../generated/shared/nDDOGame.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class cShlParamEnchant;
class uShlEnchant;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamEnchant : public cShlParamBase
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
    cShlParamEnchant();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    nDDOGame::ELEMENT_TYPE getElementType() const;
    f32 getEnchantTime() const;
    f32 getEnchantRate() const;
    f32 getAilmentDamage() const;
    f32 getEnchantIntervalTime() const;
    s32 getCustomSkillId() const;
    f32 getEnchantTimeSkill(s32 skill_lv) const;
    f32 getEnchantRateSkill(s32 skill_lv) const;
    f32 getKillDistance() const;
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
private:
    nDDOGame::ELEMENT_TYPE mElementType;  // offset: 0x160
    f32 mEnchantTime;  // offset: 0x164
    f32 mEnchantRate;  // offset: 0x168
    f32 mAilmentDamage;  // offset: 0x16c
    f32 mEnchantIntervalTime;  // offset: 0x170
    s32 mCustomSkillNo;  // offset: 0x174
    f32 mEnchantExtendTime[10];  // offset: 0x178
    f32 mEnchantExtendRate[10];  // offset: 0x1a0
    f32 mKillDistance;  // offset: 0x1c8
public:
    static MyDTI DTI;
};

class uShlEnchant : public uShlBase
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
    const cShlParamEnchant* getShlParam() const;
    uShlEnchant();
    virtual ~uShlEnchant() {}
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 174
    nDDOGame::ELEMENT_TYPE getElementType() const;
    f32 getEnchantTime() const;
    f32 getEnchantRate() const;
    f32 getAilmentDamage() const;
    f32 getEnchantIntervalTime() const;
private:
    void storeCustomSkillLevel();
    void checkDistance();
private:
    s32 mOwnerCustomSkillLv;  // offset: 0x2ab0
public:
    static MyDTI DTI;
};

inline void* cShlParamEnchant::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamEnchant::cShlParamEnchant() {
    this->mElementType = static_cast<nDDOGame::ELEMENT_TYPE>(1);
    this->mEnchantTime = 0.0f;
    this->mEnchantRate = 0.0f;
    this->mAilmentDamage = 0.0f;
    this->mEnchantIntervalTime = -1.0f;
    this->mCustomSkillNo = -1;
    this->mEnchantExtendRate[8] = 0.0f;
    this->mEnchantExtendRate[9] = 0.0f;
    this->mEnchantExtendRate[6] = 0.0f;
    this->mEnchantExtendRate[7] = 0.0f;
    this->mEnchantExtendRate[4] = 0.0f;
    this->mEnchantExtendRate[5] = 0.0f;
    this->mEnchantExtendRate[2] = 0.0f;
    this->mEnchantExtendRate[3] = 0.0f;
    this->mEnchantExtendRate[0] = 0.0f;
    this->mEnchantExtendRate[1] = 0.0f;
    this->mEnchantExtendTime[8] = 0.0f;
    this->mEnchantExtendTime[9] = 0.0f;
    this->mEnchantExtendTime[6] = 0.0f;
    this->mEnchantExtendTime[7] = 0.0f;
    this->mEnchantExtendTime[4] = 0.0f;
    this->mEnchantExtendTime[5] = 0.0f;
    this->mEnchantExtendTime[2] = 0.0f;
    this->mEnchantExtendTime[3] = 0.0f;
    this->mEnchantExtendTime[0] = 0.0f;
    this->mEnchantExtendTime[1] = 0.0f;
    this->mKillDistance = -1.0f;
}

inline nDDOGame::ELEMENT_TYPE cShlParamEnchant::getElementType() const {
    return this->mElementType;
}

inline f32 cShlParamEnchant::getAilmentDamage() const {
    return this->mAilmentDamage;
}

inline f32 cShlParamEnchant::getEnchantIntervalTime() const {
    return this->mEnchantIntervalTime;
}

inline void* uShlEnchant::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlEnchant::uShlEnchant() {
    this->mOwnerCustomSkillLv = -1;
}
