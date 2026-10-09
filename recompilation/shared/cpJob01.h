#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpJobBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cHitInfo;
class cHitInfoAfter;
class uHuman;

// Declarations
class cpJob01;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpJob01 : public cpJobBase
{
    // inferred: uHuman::checkGuardModeCancel names cpJob01::mGuardModeNoCancelTimer
    friend class uHuman;
public:
    enum GUARD_COLL_INDEX
    {
        GUARD_COLL_NORMAL = 8,
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
    cpJob01();
    virtual ~cpJob01();
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 16
    virtual void setupJobData();  // vtable slot 21
    virtual void callbackHitLand();  // vtable slot 31
    virtual void callbackGuard(cHitInfo* pHitInfo);  // vtable slot 26
    virtual void callbackGuard_calc(cHitInfo* pHitInfo);  // vtable slot 28
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo);  // vtable slot 24
    virtual void callbackReplaceHitInfo_Def(cHitInfo* pHitInfo);  // vtable slot 25
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 30
    virtual void callbackCatch(cHitInfo* pHitInfo);  // vtable slot 48
    virtual void checkReplaceInfo(cHitInfoAfter& HitInfo);  // vtable slot 58
    bool checkCndEnableDelayCombo() const;
    void setGuardModeNoCancelTimer(f32 time);
    bool isGuardModeCancelEnable() const;
    bool isSuccessCounter() const;
    void clearSuccessCounter();
    void setCounterWait(bool flag);
    bool isCanCustom13();
    bool isGuardMode() const;
protected:
    void updateGuardInfo();
    bool cheakSequence(uHuman& human, u32 bit, u32 seqPage, u32& work);
    bool isJustGuard() const;
    void replaceHitInfo_CUSTOM_08(cHitInfo* pHitInfo);
protected:
    bool mIsGuardMode;  // offset: 0x58
    f32 mJustGuardTimer;  // offset: 0x5c
    f32 mGuardModeNoCancelTimer;  // offset: 0x60
    bool mIsCaounterWait;  // offset: 0x64
    bool mIsSuccessCounter;  // offset: 0x65
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cpJob01::cpJob01() {
    this->mIsGuardMode = false;
    this->mIsCaounterWait = false;
    this->mIsSuccessCounter = false;
    this->mJustGuardTimer = 0.0f;
    this->mGuardModeNoCancelTimer = 0.0f;
}
