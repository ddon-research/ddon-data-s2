#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cThinkMgr.h"
#include "cpThinkBase.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtVector3;
namespace cThinkMgrName { class cThinkMgr; }
class kTHINKDATA;
class uDDOModel;

// Declarations
class cRage;
class cpEnemyThink;
class rRageTable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cRage : public MtObject
{
public:
    enum MIND_STATUS
    {
        MIND_NORMAL = 0,
        MIND_ANGER = 1,
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
    cRage();
    // Address: 0x01a597d0 - 0x01a597d1 (1 bytes)
    virtual ~cRage() {}
    void copy(cRage* src);
    bool checkRageStatus(uDDOModel* pModel);
public:
    bool mEnable;  // offset: 0x8
    u32 mStatusStartHpPer;  // offset: 0xc
    u32 mStatusEndHpPer;  // offset: 0x10
    u32 mMindStatus;  // offset: 0x14
    f32 mMindStatusFrameMax;  // offset: 0x18
    bool mMindStatusForced;  // offset: 0x1c
    f32 mMindStatusFrame;  // offset: 0x20
    u32 mNowMindStatus;  // offset: 0x24
    static MyDTI DTI;
    static const u16 DATA_VERSION = 257;
};

class cpEnemyThink : public cpThinkBase
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
    cpEnemyThink();
    virtual ~cpEnemyThink();
    virtual void setup();  // vtable slot 6
    void before();
    u32 callbackGetAction();
    virtual void updatePtr();  // vtable slot 9
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    u32 getActionNo();
    bool getThinkStop();
    void setThinkStop(bool enable);
    bool isChangeRage();
    void setEnemyThinkTargetLock(uDDOModel*, const MtVector3&);
    bool IsFsmTarget();
    void setEnemyThinkTargetLockFlg(bool enable);
    void checkThinkMode();
    uDDOModel* getNewTarget();
    MtVector3 getTargetJumpPos();
    void setTargetJumpPos(MtVector3& pos);
    f32 getTargetJumpDir();
    void setTargetJumpDir(f32 dir);
    static bool setTargetThinkMgr(const kTHINKDATA& tbl, MtObject* pMtObj, cThinkMgrName::cThinkMgr* pThinkmgr, u32 targetDataIdx);
    void setResourceRage(rRageTable* pRes);
    const MtVector3& getDamagePos() const;
    void setDamagePos(const MtVector3&);
    bool isBigEnemy() const;
    void setIsBigEnemy(const bool flg);
    cThinkMgrName::cThinkMgr* getcThink();
    void calcSetTargetQuat(const MtVector3& tag, f32 speed);
public:
    uDDOModel* mpModel;  // offset: 0x50
private:
    bool mIsBigEnemy;  // offset: 0x58
    MtVector3 mDamagePos;  // offset: 0x60
    cThinkMgrName::cThinkMgr mcThink;  // offset: 0x70
    bool mIsThinkStop;  // offset: 0x1380
    bool mIsFmsTarget;  // offset: 0x1381
    uDDOModel* mpFsmTarget;  // offset: 0x1388
    MtVector3 mVecFsmTarget;  // offset: 0x1390
    MtVector3 mTargetJumpPos;  // offset: 0x13a0
    f32 mTargetJumpDir;  // offset: 0x13b0
public:
    rRageTable* mpRageTable;  // offset: 0x13b8
    MtTypedArray<cRage> mRage;  // offset: 0x13c0
    bool mIsRage;  // offset: 0x13e0
    static MyDTI DTI;
};

class rRageTable : public rTbl2<cRage>
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
    virtual bool loadData(MtDataReader& in, cRage* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cRage::cRage() {
    this->mMindStatusFrame = 0.0f;
    this->mNowMindStatus = static_cast<u32>(0);
    this->mMindStatusForced = false;
    this->mMindStatus = static_cast<u32>(0);
    this->mMindStatusFrameMax = 0.0f;
    this->mStatusStartHpPer = static_cast<u32>(0);
    this->mStatusEndHpPer = static_cast<u32>(0);
    this->mEnable = true;
}
