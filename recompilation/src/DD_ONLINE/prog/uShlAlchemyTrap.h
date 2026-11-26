#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "uShlAlchemyObj.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cHitInfo;
class cShlParamBase;

// Declarations
class cShlParamAlchemyTrap;
class cShlParamAlchemyTrapAttack;
class uShlAlchemyTrap;
class uShlAlchemyTrapAttack;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamAlchemyTrap : public cShlParamAlchemyObj
{
public:
    class MyDTI;
    class cTrapAttackShlInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTrapAttackShlInfo : public MtObject
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
        cTrapAttackShlInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copyData(cShlParamAlchemyTrap::cTrapAttackShlInfo& base);
    public:
        f32 mCheckDisMin;  // offset: 0x8
        f32 mCheckDisMax;  // offset: 0xc
        s32 mCreateShlNo;  // offset: 0x10
        bool mUseKnockBack;  // offset: 0x14
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamAlchemyTrap();
    virtual ~cShlParamAlchemyTrap();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    s32 getCustomSkillId() const;
    u32 getCheckCount(u32 index) const;
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    void copyList(const cShlParamAlchemyTrap* pParam);
public:
    f32 mCheckShlIntervalTime;  // offset: 0x1ac
    s32 mCustomSkillNo;  // offset: 0x1b0
    u32 mCheckCount[10];  // offset: 0x1b4
    bool mTurnTarget;  // offset: 0x1dc
    MtTypedArray<cTrapAttackShlInfo> mCreateShlInfoArray;  // offset: 0x1e0
    static MyDTI DTI;
};

class cShlParamAlchemyTrapAttack : public cShlParamBase
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
    cShlParamAlchemyTrapAttack();
    virtual ~cShlParamAlchemyTrapAttack();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    static MyDTI DTI;
};

class uShlAlchemyTrap : public uShlAlchemyObj
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
    const cShlParamAlchemyTrap* getShlParam() const;
    uShlAlchemyTrap();
    virtual ~uShlAlchemyTrap();
    virtual void setup();  // vtable slot 6
    void setupSubMaxCount();
    virtual void updateSub();  // vtable slot 175
    virtual void updatePtr();  // vtable slot 17
    virtual void callbackAttackTest(cHitInfo* pHitInfo);  // vtable slot 85
private:
    void createAttackShl(cHitInfo* pHitInfo);
    s32 getAttackShlNo(f32 dis_sq, bool& use_knockBack);
private:
    f32 mCheckShlIntervalTime;  // offset: 0x2b78
    u32 mMaxCount;  // offset: 0x2b7c
public:
    static MyDTI DTI;
};

class uShlAlchemyTrapAttack : public uShlBase
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
    const cShlParamAlchemyTrapAttack* getShlParam() const;
    uShlAlchemyTrapAttack();
    virtual ~uShlAlchemyTrapAttack();
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo);  // vtable slot 74
    void setKnockBackPos(const MtVector3& pos);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
private:
    MtVector3 mKnockBackPos;  // offset: 0x2ab0
    bool mFlgNextTrap;  // offset: 0x2ac0
public:
    static MyDTI DTI;
};

inline void* cShlParamAlchemyTrap::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamAlchemyTrap::cShlParamAlchemyTrap() : mCheckShlIntervalTime(60.0f), mCustomSkillNo(-1), mTurnTarget(true) {
    for (u32 i = 0; i < 10u; i++) {
        mCheckCount[i] = 5u;
    }
    mTurnTarget = true;
    mCreateShlInfoArray.setAutoDelete(true);
}

inline void* cShlParamAlchemyTrap::cTrapAttackShlInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamAlchemyTrap::cTrapAttackShlInfo::cTrapAttackShlInfo() {
    this->mCheckDisMin = 0.0f;
    this->mCheckDisMax = 0.0f;
    this->mCreateShlNo = -1;
    this->mUseKnockBack = false;
}

inline void* cShlParamAlchemyTrapAttack::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlAlchemyTrap::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlAlchemyTrap::uShlAlchemyTrap() {
    this->mCheckShlIntervalTime = 0.0f;
    this->mMaxCount = 5;
}

inline void* uShlAlchemyTrapAttack::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
