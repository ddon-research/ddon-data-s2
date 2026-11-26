#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cpLockOn.h"
#include "cpShlShotCtrl.h"
#include "uShlBase.h"
#include "uShlHoming.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cHitInfo;
class cShlParamBase;

// Declarations
class cShlParamConstErosion;
class cShlParamMgcArrowErosion;
class cShlParamMgcArrowErosionCtrl;
class uShlConstErosion;
class uShlMgcArrowErosion;
class uShlMgcArrowErosionCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamConstErosion : public cShlParamBase
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
    cShlParamConstErosion();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
public:
    bool mOnlyAttackLockOnTarget;  // offset: 0x160
    bool mIsConstLockOnTarget;  // offset: 0x161
    static MyDTI DTI;
};

class cShlParamMgcArrowErosion : public cShlParamHoming
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
    cShlParamMgcArrowErosion();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
public:
    bool mUpdateKill;  // offset: 0x248
    bool mLandEffect;  // offset: 0x249
    s32 mLandEffectNo;  // offset: 0x24c
    f32 mLandEffectTimer;  // offset: 0x250
    bool mOnlyAttackLockOnTarget;  // offset: 0x254
    bool mIsConstLockOnTarget;  // offset: 0x255
    f32 mScrCheckHeight;  // offset: 0x258
    s32 mLandSeNo;  // offset: 0x25c
    u32 mEffectTimesPerLandSe;  // offset: 0x260
    static MyDTI DTI;
};

class cShlParamMgcArrowErosionCtrl : public cShlParamBase
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
    cShlParamMgcArrowErosionCtrl();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    s32 mShlNoShoot;  // offset: 0x160
    s32 mShlNoErosionNext;  // offset: 0x164
    s32 mShlNoErosionNextSameTarget;  // offset: 0x168
    f32 mSearchDistance;  // offset: 0x16c
    u32 mErosionMaxCountForSameTarget;  // offset: 0x170
    f32 mSameTargetErosionWaitTimer;  // offset: 0x174
    f32 mBeforeErosionShlTime;  // offset: 0x178
    f32 mBeforeErosionShlTimeArrow;  // offset: 0x17c
    f32 mAfterErosionShlTime;  // offset: 0x180
    u32 mErosionMaxCount;  // offset: 0x184
    static MyDTI DTI;
};

class uShlConstErosion : public uShlBase
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
    const cShlParamConstErosion* getShlParam() const;
    uShlConstErosion();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 17
    virtual void updateSub();  // vtable slot 175
public:
    static MyDTI DTI;
};

class uShlMgcArrowErosion : public uShlHoming
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
    const cShlParamMgcArrowErosion* getShlParam() const;
    uShlMgcArrowErosion();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 17
    virtual void updateSub();  // vtable slot 175
    void setCtrlShl(uShlMgcArrowErosionCtrl* pShl);
    virtual void callbackAttack(cHitInfo* pInfo);  // vtable slot 83
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
private:
    void updateLandEffect();
private:
    uShlMgcArrowErosionCtrl* mpShlCtrl;  // offset: 0x2be0
    bool mFlgHitAttackTest;  // offset: 0x2be8
    f32 mLandEffectTimer;  // offset: 0x2bec
    s32 mLandEffectCount;  // offset: 0x2bf0
    MtVector3 mOldEffectPos;  // offset: 0x2c00
public:
    static MyDTI DTI;
};

class uShlMgcArrowErosionCtrl : public uShlBase
{
public:
    enum
    {
        EROSION_RNO_UNDEFINED = 0,
        EROSION_RNO_INIT = 1,
        EROSION_RNO_HOMING_TARGET = 2,
        EROSION_RNO_STICK_TARGET = 3,
        EROSION_RNO_FIND_NEXT_TARGET = 4,
        EROSION_RNO_ESOSION_NEXT_TARGET = 5,
        EROSION_RNO_ESOSION_SAME_TARGET = 6,
    };
public:
    class MyDTI;
    struct stErosionInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stErosionInfo
    {
    public:
        void clear();
    public:
        u32 mTargetUID;  // offset: 0x0
        s32 mLockOnIndex[10];  // offset: 0x4
        u32 mLockedOnNum;  // offset: 0x2c
        bool mIsActive;  // offset: 0x30
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
    const cShlParamMgcArrowErosionCtrl* getShlParam() const;
    uShlMgcArrowErosionCtrl();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void updatePtr();  // vtable slot 17
    virtual void moveAfter();  // vtable slot 10
    bool callbackErosionAttack(const cHitInfo* pInfo, const uShlMgcArrowErosion& shl);
    bool searchFunc(cpLockOn::cLockOnTarget* pLockOnTarget);
    bool searchFuncAttack(cpLockOn::cLockOnTarget* pLockOnTarget);
private:
    void moveErosionCtrl(bool& is_dead);
    void getLockOnTargetUID(cpShlShotCtrl::cShlShotReqInfo& info);
    s32 getNowTargetNextLockOnID(s32& Jnt);
    void writeNowErosionInfo();
private:
    u32 mErosionRno;  // offset: 0x2ab0
    uShlBase* mpShlChild;  // offset: 0x2ab8
    stErosionInfo mErosionInfo[10];  // offset: 0x2ac0
    stErosionInfo mReqErosionInfo;  // offset: 0x2cc8
    s32 mReqErosionJnt;  // offset: 0x2cfc
    stErosionInfo mNowErosionInfo;  // offset: 0x2d00
    s32 mNowErosionJnt;  // offset: 0x2d34
    stErosionInfo mNextErosionInfo;  // offset: 0x2d38
    s32 mNextErosionJnt;  // offset: 0x2d6c
    f32 mTimer;  // offset: 0x2d70
    u32 mErosionCount;  // offset: 0x2d74
    bool mFlgErosioned;  // offset: 0x2d78
public:
    static MyDTI DTI;
};

inline void* cShlParamConstErosion::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamConstErosion::cShlParamConstErosion() {
    this->mOnlyAttackLockOnTarget = true;
    this->mIsConstLockOnTarget = true;
}

inline void* cShlParamMgcArrowErosion::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamMgcArrowErosion::cShlParamMgcArrowErosion() : mUpdateKill(true), mLandEffect(false), mLandEffectNo(-1), mLandEffectTimer(5.0f), mOnlyAttackLockOnTarget(true), mIsConstLockOnTarget(false), mScrCheckHeight(100.0f), mLandSeNo(-1), mEffectTimesPerLandSe(3u) {
}

inline void* cShlParamMgcArrowErosionCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamMgcArrowErosionCtrl::cShlParamMgcArrowErosionCtrl() {
    this->mShlNoShoot = -1;
    this->mShlNoErosionNext = -1;
    this->mShlNoErosionNextSameTarget = -1;
    this->mSearchDistance = 1000.0f;
    this->mErosionMaxCountForSameTarget = 2;
    this->mBeforeErosionShlTimeArrow = 0.0f;
    this->mAfterErosionShlTime = 0.0f;
    this->mSameTargetErosionWaitTimer = 0.0f;
    this->mBeforeErosionShlTime = 0.0f;
    this->mErosionMaxCount = 5;
}

inline void* uShlConstErosion::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlConstErosion::uShlConstErosion() {
}

inline void* uShlMgcArrowErosion::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlMgcArrowErosionCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlMgcArrowErosionCtrl::uShlMgcArrowErosionCtrl() {
    this->mpShlChild = nullptr;
    this->mErosionInfo[0].mLockOnIndex[9] = -1;
    this->mErosionInfo[0].mLockOnIndex[7] = -1;
    this->mErosionInfo[0].mLockOnIndex[8] = -1;
    this->mErosionInfo[0].mLockOnIndex[5] = -1;
    this->mErosionInfo[0].mLockOnIndex[6] = -1;
    this->mErosionInfo[0].mLockOnIndex[3] = -1;
    this->mErosionInfo[0].mLockOnIndex[4] = -1;
    this->mErosionInfo[0].mLockOnIndex[1] = -1;
    this->mErosionInfo[0].mLockOnIndex[2] = -1;
    this->mErosionInfo[0].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[0].mLockOnIndex[0] = -1;
    this->mErosionInfo[0].mLockedOnNum = 0;
    this->mErosionInfo[0].mIsActive = false;
    this->mErosionInfo[1].mLockOnIndex[9] = -1;
    this->mErosionInfo[1].mLockOnIndex[7] = -1;
    this->mErosionInfo[1].mLockOnIndex[8] = -1;
    this->mErosionInfo[1].mLockOnIndex[5] = -1;
    this->mErosionInfo[1].mLockOnIndex[6] = -1;
    this->mErosionInfo[1].mLockOnIndex[3] = -1;
    this->mErosionInfo[1].mLockOnIndex[4] = -1;
    this->mErosionInfo[1].mLockOnIndex[1] = -1;
    this->mErosionInfo[1].mLockOnIndex[2] = -1;
    this->mErosionInfo[1].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[1].mLockOnIndex[0] = -1;
    this->mErosionInfo[1].mLockedOnNum = 0;
    this->mErosionInfo[1].mIsActive = false;
    this->mErosionInfo[2].mLockOnIndex[9] = -1;
    this->mErosionInfo[2].mLockOnIndex[7] = -1;
    this->mErosionInfo[2].mLockOnIndex[8] = -1;
    this->mErosionInfo[2].mLockOnIndex[5] = -1;
    this->mErosionInfo[2].mLockOnIndex[6] = -1;
    this->mErosionInfo[2].mLockOnIndex[3] = -1;
    this->mErosionInfo[2].mLockOnIndex[4] = -1;
    this->mErosionInfo[2].mLockOnIndex[1] = -1;
    this->mErosionInfo[2].mLockOnIndex[2] = -1;
    this->mErosionInfo[2].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[2].mLockOnIndex[0] = -1;
    this->mErosionInfo[2].mLockedOnNum = 0;
    this->mErosionInfo[2].mIsActive = false;
    this->mErosionInfo[3].mLockOnIndex[9] = -1;
    this->mErosionInfo[3].mLockOnIndex[7] = -1;
    this->mErosionInfo[3].mLockOnIndex[8] = -1;
    this->mErosionInfo[3].mLockOnIndex[5] = -1;
    this->mErosionInfo[3].mLockOnIndex[6] = -1;
    this->mErosionInfo[3].mLockOnIndex[3] = -1;
    this->mErosionInfo[3].mLockOnIndex[4] = -1;
    this->mErosionInfo[3].mLockOnIndex[1] = -1;
    this->mErosionInfo[3].mLockOnIndex[2] = -1;
    this->mErosionInfo[3].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[3].mLockOnIndex[0] = -1;
    this->mErosionInfo[3].mLockedOnNum = 0;
    this->mErosionInfo[3].mIsActive = false;
    this->mErosionInfo[4].mLockOnIndex[9] = -1;
    this->mErosionInfo[4].mLockOnIndex[7] = -1;
    this->mErosionInfo[4].mLockOnIndex[8] = -1;
    this->mErosionInfo[4].mLockOnIndex[5] = -1;
    this->mErosionInfo[4].mLockOnIndex[6] = -1;
    this->mErosionInfo[4].mLockOnIndex[3] = -1;
    this->mErosionInfo[4].mLockOnIndex[4] = -1;
    this->mErosionInfo[4].mLockOnIndex[1] = -1;
    this->mErosionInfo[4].mLockOnIndex[2] = -1;
    this->mErosionInfo[4].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[4].mLockOnIndex[0] = -1;
    this->mErosionInfo[4].mLockedOnNum = 0;
    this->mErosionInfo[4].mIsActive = false;
    this->mErosionInfo[5].mLockOnIndex[9] = -1;
    this->mErosionInfo[5].mLockOnIndex[7] = -1;
    this->mErosionInfo[5].mLockOnIndex[8] = -1;
    this->mErosionInfo[5].mLockOnIndex[5] = -1;
    this->mErosionInfo[5].mLockOnIndex[6] = -1;
    this->mErosionInfo[5].mLockOnIndex[3] = -1;
    this->mErosionInfo[5].mLockOnIndex[4] = -1;
    this->mErosionInfo[5].mLockOnIndex[1] = -1;
    this->mErosionInfo[5].mLockOnIndex[2] = -1;
    this->mErosionInfo[5].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[5].mLockOnIndex[0] = -1;
    this->mErosionInfo[5].mLockedOnNum = 0;
    this->mErosionInfo[5].mIsActive = false;
    this->mErosionInfo[6].mLockOnIndex[9] = -1;
    this->mErosionInfo[6].mLockOnIndex[7] = -1;
    this->mErosionInfo[6].mLockOnIndex[8] = -1;
    this->mErosionInfo[6].mLockOnIndex[5] = -1;
    this->mErosionInfo[6].mLockOnIndex[6] = -1;
    this->mErosionInfo[6].mLockOnIndex[3] = -1;
    this->mErosionInfo[6].mLockOnIndex[4] = -1;
    this->mErosionInfo[6].mLockOnIndex[1] = -1;
    this->mErosionInfo[6].mLockOnIndex[2] = -1;
    this->mErosionInfo[6].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[6].mLockOnIndex[0] = -1;
    this->mErosionInfo[6].mLockedOnNum = 0;
    this->mErosionInfo[6].mIsActive = false;
    this->mErosionInfo[7].mLockOnIndex[9] = -1;
    this->mErosionInfo[7].mLockOnIndex[7] = -1;
    this->mErosionInfo[7].mLockOnIndex[8] = -1;
    this->mErosionInfo[7].mLockOnIndex[5] = -1;
    this->mErosionInfo[7].mLockOnIndex[6] = -1;
    this->mErosionInfo[7].mLockOnIndex[3] = -1;
    this->mErosionInfo[7].mLockOnIndex[4] = -1;
    this->mErosionInfo[7].mLockOnIndex[1] = -1;
    this->mErosionInfo[7].mLockOnIndex[2] = -1;
    this->mErosionInfo[7].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[7].mLockOnIndex[0] = -1;
    this->mErosionInfo[7].mLockedOnNum = 0;
    this->mErosionInfo[7].mIsActive = false;
    this->mErosionInfo[8].mLockOnIndex[9] = -1;
    this->mErosionInfo[8].mLockOnIndex[7] = -1;
    this->mErosionInfo[8].mLockOnIndex[8] = -1;
    this->mErosionInfo[8].mLockOnIndex[5] = -1;
    this->mErosionInfo[8].mLockOnIndex[6] = -1;
    this->mErosionInfo[8].mLockOnIndex[3] = -1;
    this->mErosionInfo[8].mLockOnIndex[4] = -1;
    this->mErosionInfo[8].mLockOnIndex[1] = -1;
    this->mErosionInfo[8].mLockOnIndex[2] = -1;
    this->mErosionInfo[8].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[8].mLockOnIndex[0] = -1;
    this->mErosionInfo[8].mLockedOnNum = 0;
    this->mErosionInfo[8].mIsActive = false;
    this->mErosionInfo[9].mLockOnIndex[9] = -1;
    this->mErosionInfo[9].mLockOnIndex[7] = -1;
    this->mErosionInfo[9].mLockOnIndex[8] = -1;
    this->mErosionInfo[9].mLockOnIndex[5] = -1;
    this->mErosionInfo[9].mLockOnIndex[6] = -1;
    this->mErosionInfo[9].mLockOnIndex[3] = -1;
    this->mErosionInfo[9].mLockOnIndex[4] = -1;
    this->mErosionInfo[9].mLockOnIndex[1] = -1;
    this->mErosionInfo[9].mLockOnIndex[2] = -1;
    this->mErosionInfo[9].mTargetUID = 0xFFFFFFFF;
    this->mErosionInfo[9].mLockOnIndex[0] = -1;
    this->mErosionInfo[9].mLockedOnNum = 0;
    this->mErosionInfo[9].mIsActive = false;
    this->mNowErosionInfo.mLockOnIndex[9] = -1;
    this->mNowErosionInfo.mLockOnIndex[7] = -1;
    this->mNowErosionInfo.mLockOnIndex[8] = -1;
    this->mNowErosionInfo.mLockOnIndex[5] = -1;
    this->mNowErosionInfo.mLockOnIndex[6] = -1;
    this->mNowErosionInfo.mLockOnIndex[3] = -1;
    this->mNowErosionInfo.mLockOnIndex[4] = -1;
    this->mNowErosionInfo.mLockOnIndex[1] = -1;
    this->mNowErosionInfo.mLockOnIndex[2] = -1;
    this->mNowErosionInfo.mTargetUID = 0xFFFFFFFF;
    this->mNowErosionInfo.mLockOnIndex[0] = -1;
    this->mNowErosionInfo.mLockedOnNum = 0;
    this->mNowErosionInfo.mIsActive = false;
    this->mNextErosionInfo.mLockOnIndex[9] = -1;
    this->mNextErosionInfo.mLockOnIndex[7] = -1;
    this->mNextErosionInfo.mLockOnIndex[8] = -1;
    this->mNextErosionInfo.mLockOnIndex[5] = -1;
    this->mNextErosionInfo.mLockOnIndex[6] = -1;
    this->mNextErosionInfo.mLockOnIndex[3] = -1;
    this->mNextErosionInfo.mLockOnIndex[4] = -1;
    this->mNextErosionInfo.mLockOnIndex[1] = -1;
    this->mNextErosionInfo.mLockOnIndex[2] = -1;
    this->mNextErosionInfo.mTargetUID = 0xFFFFFFFF;
    this->mNextErosionInfo.mLockOnIndex[0] = -1;
    this->mNextErosionInfo.mLockedOnNum = 0;
    this->mNextErosionInfo.mIsActive = false;
    this->mReqErosionInfo.mLockOnIndex[9] = -1;
    this->mReqErosionInfo.mLockOnIndex[7] = -1;
    this->mReqErosionInfo.mLockOnIndex[8] = -1;
    this->mReqErosionInfo.mLockOnIndex[5] = -1;
    this->mReqErosionInfo.mLockOnIndex[6] = -1;
    this->mReqErosionInfo.mLockOnIndex[3] = -1;
    this->mReqErosionInfo.mLockOnIndex[4] = -1;
    this->mReqErosionInfo.mLockOnIndex[1] = -1;
    this->mReqErosionInfo.mLockOnIndex[2] = -1;
    this->mReqErosionInfo.mTargetUID = 0xFFFFFFFF;
    this->mReqErosionInfo.mLockOnIndex[0] = -1;
    this->mReqErosionInfo.mLockedOnNum = 0;
    this->mReqErosionInfo.mIsActive = false;
    this->mNowErosionJnt = -1;
    this->mReqErosionJnt = -1;
    this->mNextErosionJnt = -1;
    this->mTimer = 0.0f;
    this->mErosionCount = 0;
    this->mErosionRno = 0;
    this->mFlgErosioned = false;
}

inline bool uShlMgcArrowErosionCtrl::searchFuncAttack(cpLockOn::cLockOnTarget* pLockOnTarget) {
    return true;
}
