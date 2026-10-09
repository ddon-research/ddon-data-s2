#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cDelegate.h"
#include "cpComponent.h"
#include "nCatch.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cAttackParam;
class cCatchInfoParam;
class cCaughtInfoParam;
class cHitInfo;
class rCatchInfoParam;
class rCaughtInfoParam;
class uDDOModel;

// Declarations
class cCatchInfo;
class cCaughtInfo;
class cpCatchCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cCatchInfo : public MtObject
{
    // inferred: cpCatchCtrl::forceCancel names cpCatchCtrl::mCatchInfo.mCatchType
    friend class cpCatchCtrl;
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
    cCatchInfo();
    cCatchInfo(u8 type, u32 uid);
    virtual ~cCatchInfo();
    void reset();
    u8 getCatchType();
    void setCatchType(u8 type);
    u32 getCatchUid();
    void setCatchUid(u32 uid);
    u8 getCatchJointNo();
    void setCatchJointNo(u8 no);
    u8 getReleaseType();
    void setReleaseType(nCatch::RELEASE_TYPE type);
    MtVector3 getCatchHitPos();
    void setCatchHitPos(const MtVector3& vec);
private:
    u8 mCatchType;  // offset: 0x8
    u8 mJointNo;  // offset: 0x9
    u8 mReleaseType;  // offset: 0xa
    u32 mCatchUid;  // offset: 0xc
    MtVector3 mHitPos;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cCaughtInfo : public MtObject
{
    // inferred: cpCatchCtrl::updateBeardownEffectiveTimer names cpCatchCtrl::mCaughtInfo.mCatchType
    friend class cpCatchCtrl;
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
    cCaughtInfo();
    cCaughtInfo(u8 type, u32 uid);
    virtual ~cCaughtInfo();
    void reset();
    u8 getCatchType();
    void setCatchType(u8 type);
    u32 getCatchUid();
    void setCatchUid(u32 uid);
    u8 getCatchJointNo();
    void setCatchJointNo(u8 no);
    u8 getEscapeType();
    void setEscapeType(nCatch::ESCAPE_TYPE type);
    MtVector3 getCatchHitPos();
    void setCatchHitPos(const MtVector3&);
private:
    u8 mCatchType;  // offset: 0x8
    u8 mJointNo;  // offset: 0x9
    u8 mEscapeType;  // offset: 0xa
    u32 mCatchUid;  // offset: 0xc
    MtVector3 mHitPos;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cpCatchCtrl : public cpComponent
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
    cpCatchCtrl();
    virtual ~cpCatchCtrl();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void setResource(rCatchInfoParam* pRes);
    void setResource(rCaughtInfoParam* pRes);
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    void setupContextCatchCtrl(bool recvFlag);
    void callbackCatchHit(cHitInfo* pHitInfo);
    bool isCatch(u8 catchType);
    f32 getCatchLoopTimer();
    nCatch::BEARDOWN_EFFECTIVE getBeardownEffective();
    bool isBeardownEffective();
    void setBeardownEffectiveTimer();
    void updateBeardownEffectiveTimer();
    u32 getLeverGachaPoint();
    bool isLeverGachaSuccess();
    void setLeverGachaPoint();
    void updateLeverGacha();
    bool checkCatch(u8 catchType, u32 uniqId);
    void setCatch(u8 catchType, u32 uniqId);
    void setFailed();
    u32 getActNoRelease();
    bool checkCancel();
    void setCancel();
    void forceCancel();
    bool checkClutched(u8 catchType, uDDOModel& Catcher, MtVector3& hitPos);
    void setClutched(u8 catchType, u32 uniqId, u8 jointNo);
    bool checkCaught();
    void setCaught();
    bool checkEscape();
    void setEscape();
    void forceEscape();
    void disconnectEscape();
    void setDispCheck();
    void setConstrain();
    void releaseConstrain();
    void throwOm();
    void putOm();
    void setThrowOm();
    void setPutOm();
    u32 callbackGetCatchAction();
    void cancelCatchActionReq();
    void cancelCaughtActionReq();
private:
    cCatchInfo& getCatchInfo();
    cCaughtInfo& getCaughtInfo();
    bool catchHitGroupPlayer(cHitInfo* pHitInfo, uDDOModel* pAtk, const cAttackParam* pAtkParam);
    bool catchHitGroupOther(cHitInfo* pHitInfo, uDDOModel* pAtk, const cAttackParam* pAtkParam);
public:
    u8 getCatchType();
    void setCatchType(u8 type);
    u32 getCatchUid();
    u32 getCaughtUid();
private:
    cCatchInfoParam* getCatchInfoParam(u8 catchType);
    cCaughtInfoParam* getCaughtInfoParam(u8 catchType);
public:
    bool isOwnerBeaDown() const;
public:
    cDelegate_0<void> callbackSetCaught;  // offset: 0x50
    cDelegate_0<bool> checkCatchEscape;  // offset: 0x68
    uDDOModel* mpModel;  // offset: 0x80
private:
    u8 mCatchType;  // offset: 0x88
    cCatchInfo mCatchInfo;  // offset: 0x90
    rCatchInfoParam* mpCatchInfoParam;  // offset: 0xb0
    u32 mCatchActionReq;  // offset: 0xb8
    cCaughtInfo mCaughtInfo;  // offset: 0xc0
    rCaughtInfoParam* mpCaughtInfoParam;  // offset: 0xe0
    u32 mCaughtActionReq;  // offset: 0xe8
    f32 mBeardownEffectiveTimer;  // offset: 0xec
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 cCatchInfo::getCatchUid() {
    return this->mCatchUid;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cCaughtInfo::getCatchUid() {
    return this->mCatchUid;
}
