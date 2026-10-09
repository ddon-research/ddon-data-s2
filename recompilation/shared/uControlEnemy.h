#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Enemy.h"
#include "MtDTI.h"
#include "MtString.h"
#include "uControl.h"

// Forward declarations
class CDataNamedEnemyParamClient;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class uDDOModel;

// Declarations
class uControlEnemy;

// Type aliases from DWARF
using CNamedEnemyParamClient = CDataNamedEnemyParamClient;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uControlEnemy : public uControl
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
    uControlEnemy();
    virtual ~uControlEnemy();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    void setOwner(uDDOModel* pOwner);
    bool isHumanEnemy();
    bool isWeakEnemy();
    u32 getTargetType();
    void setTargetType(u32 type);
    bool isAreaBoss();
    void setAreaBoss(bool f);
    bool isBigUI() const;
    void setBigUI(bool f);
    bool isWaitting() const;
    void setWaitting(bool f);
    u32 getStartThinkTbl();
    void setStartThinkTbl(u32 ThinkTbl);
    s32 getLifeAreaGroup() const;
    void setLifeAreaGroup(s32 val);
    f32 getSetScale() const;
    void setSetScale(f32 scl);
    u32 getLv() const;
    void setLv(u32 lv);
    u32 getEmReactNo() const;
    void setEmReactNo(u32 no);
    void setIsDieStageBossDispOff();
    bool isDieStageBossDispOff();
    u32 getRaidBossID() const;
    void setRaidBossID(u32 id);
    bool isRaidBoss();
    u32 getErosionMode() const;
    void setErosionMode(u32 lv);
    bool isReturnPoint2nd() const;
    void setReturnPoint2nd(bool f);
    bool isKillOneself() const;
    void setKillOneself(bool f);
    virtual MT_CTSTR getName();  // vtable slot 14
    void setFsmPath(MT_CTSTR path);
    MT_CTSTR getFsmPath() const;
    bool isSetFsm() const;
    void setFsmEvent(bool f);
    bool isFsmEvent() const;
    const CNamedEnemyParamClient getNamedEnemyParam() const;
    void setNamedEnemyParam(const CNamedEnemyParamClient&);
protected:
    bool mIsBigUI;  // offset: 0x288
    bool mIsWaitting;  // offset: 0x289
    bool mIsFsmEvent;  // offset: 0x28a
    bool mIsAreaBoss;  // offset: 0x28b
    u32 mTargetType;  // offset: 0x28c
    u32 mThinkTbl_Select;  // offset: 0x290
    s32 mLifeAreaGroup;  // offset: 0x294
    f32 mSetScale;  // offset: 0x298
    u32 mLv;  // offset: 0x29c
    u32 mEmReactNo;  // offset: 0x2a0
    bool mIsDieStageBossDispOff;  // offset: 0x2a4
    u32 mRaidBossID;  // offset: 0x2a8
    u32 mErosionMode;  // offset: 0x2ac
    bool mReturnPoint2nd;  // offset: 0x2b0
    bool mKillOneself;  // offset: 0x2b1
    MtString mUnitName;  // offset: 0x2b8
    MtString mFsmPath;  // offset: 0x2c0
    CNamedEnemyParamClient mNamedEnemyParam;  // offset: 0x2c8
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline u32 uControlEnemy::getErosionMode() const {
    return this->mErosionMode;
}
