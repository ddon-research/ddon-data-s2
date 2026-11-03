#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cpComponent.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtHermiteCurve;
class MtObject;
class MtVector3;
class uHuman;

// Declarations
class cpHmHeadCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpHmHeadCtrl : public cpComponent
{
public:
    enum CTRL_MODE
    {
        C_MODE_NORMAL = 0,
        C_MODE_BATTLE = 1,
        C_MODE_TOUCH_TARGET = 2,
    };
public:
    class MyDTI;
    class cActParam;
public:
    using TargetOfsTbl = nDDOUtility::cArray<MtVector3, 7>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cActParam : public MtObject
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
        cActParam();
        cActParam(const MtHermiteCurve& Curve, s32 targetIndex, u32 nextIndex, f32 moveTime, f32 waitTime);
        void init(const MtHermiteCurve& Curve, s32 targetIndex, u32 nextIndex, f32 moveTime, f32 waitTime);
        cpHmHeadCtrl::cActParam& operator=(const cpHmHeadCtrl::cActParam& src);
    public:
        MtHermiteCurve mCurve;  // offset: 0x8
        s32 mTargetIndex;  // offset: 0x48
        u32 mNextActIndex;  // offset: 0x4c
        f32 mMoveTime;  // offset: 0x50
        f32 mWaitTime;  // offset: 0x54
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
    cpHmHeadCtrl();
    virtual ~cpHmHeadCtrl();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    virtual void move();  // vtable slot 7
    void compMoveAfter();
    virtual void setActive(bool active);  // vtable slot 13
    bool checkThrough();
    void reset();
    void updateNormalMode();
    void updateBattleMode();
    void updateLookAtTouchTargetMode();
    void requestThrough();
private:
    void clearHeadCtrl();
private:
    uHuman* mpHuman;  // offset: 0x50
    TargetOfsTbl mTargetOfsTbl;  // offset: 0x60
    cActParam mActTbl[3][5];  // offset: 0xd0
    const MtHermiteCurve mDefaultCurve;  // offset: 0x5f8
    CTRL_MODE mCtrlMode;  // offset: 0x638
    u32 mOldActNo;  // offset: 0x63c
    f32 mWaitTime;  // offset: 0x640
    f32 mWaitTimer;  // offset: 0x644
    u32 mActPattern;  // offset: 0x648
    u32 mOldActPattern;  // offset: 0x64c
    u32 mActIndex;  // offset: 0x650
    f32 mActTimer;  // offset: 0x654
    f32 mActTimer2;  // offset: 0x658
    u32 mActState;  // offset: 0x65c
    bool mThroughRequest;  // offset: 0x660
public:
    static MyDTI DTI;
private:
    static const u32 ACT_PATTERN_NUM = 3;
    static const u32 ACT_TBL_NUM = 5;
    static const u32 TGT_OFS_TBL_NUM = 7;
};

inline void* cpHmHeadCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cpHmHeadCtrl::requestThrough() {
    this->mThroughRequest = true;
}

inline void* cpHmHeadCtrl::cActParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cpHmHeadCtrl::cActParam::cActParam() {
    this->mTargetIndex = -1;
    this->mNextActIndex = 0;
    this->mMoveTime = 0.0f;
    this->mWaitTime = 0.0f;
}
