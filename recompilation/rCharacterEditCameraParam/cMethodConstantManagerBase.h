#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;

// Declarations
namespace cMethodConstantTimeName { class cMethodConstantBase; }
namespace cMethodConstantTimeName { class cMethodConstantManagerBase; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

namespace cMethodConstantTimeName {
    class cMethodConstantBase : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        using REPEAT_CALLBACK_PARAM_STATUS = bool(MtObject::*)(u32, u32);
        using REPEAT_CALLBACK_PARAM = bool(MtObject::*)(u32, MtVector3&);
        using REPEAT_CALLBACK = bool(MtObject::*)(u32);
        using CHECK_CALLBACK = bool(MtObject::*)();
        using CHECK_CALLBACK_PARAM = bool(MtObject::*)(u32);
        using CHECK_CALLBACK_UNUSE_PARAM = bool(MtObject::*)(u32);
    public:
        class MyDTI : public ::MtDTI
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
        cMethodConstantBase();
        void init();
        void after();
        void applyWorldOffset(const MtVector3&, const MtVector3&);
        void setRepeatMethd(REPEAT_CALLBACK repMethodRun, u32 repCount, f32 repTimer, bool fastmethdRun, u32 syncKeepbit);
        void setRepeatMethd(MtVector3& vec, REPEAT_CALLBACK_PARAM repMethodRunParam, u32 repCount, f32 repTimer, bool fastmethdRun, u32 syncKeepbit);
        void setRepeatMethd(u32 index, REPEAT_CALLBACK_PARAM_STATUS repMethodRunParamStatus, u32 repCount, f32 repTimer, bool fastmethdRun, u32 syncKeepbit);
        bool isUse();
    private:
        void setRepeatMethodInit(u32 repCount, f32 repTimer, bool fastmethdRun, u32 syncKeepbit);
    public:
        void syncOn(u32 keepBit);
        void addTimer(f32 addTime);
        bool checkTimer();
        bool update(MtObject* pObject);
    public:
        REPEAT_CALLBACK_PARAM_STATUS mpCallbackRepeatParamStatus;  // offset: 0x8
        REPEAT_CALLBACK_PARAM mpCallbackRepeatParam;  // offset: 0x18
        REPEAT_CALLBACK mpCallbackRepeat;  // offset: 0x28
    protected:
        CHECK_CALLBACK mpCallbackCheck;  // offset: 0x38
    public:
        CHECK_CALLBACK_PARAM mpCallbackCheckParam;  // offset: 0x48
        CHECK_CALLBACK_UNUSE_PARAM mpCallbackUnUse;  // offset: 0x58
    private:
        u32 mRepCount;  // offset: 0x68
        u32 mRepCountMax;  // offset: 0x6c
        MtVector3 mParamVec;  // offset: 0x70
        u32 mIndex;  // offset: 0x80
        f32 mTimer;  // offset: 0x84
        f32 mTimerMax;  // offset: 0x88
        bool mFirstMethoRun;  // offset: 0x8c
        bool mUse;  // offset: 0x8d
        u32 mSyncCheck;  // offset: 0x90
        u32 mKeepSync;  // offset: 0x94
    public:
        static MyDTI DTI;
    };
}  // namespace cMethodConstantTimeName

namespace cMethodConstantTimeName {
    class cMethodConstantManagerBase : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cMethodConstantManagerBase();
        void after();
        void update(MtObject* pObject);
        void move(f32 deltatime);
        void init();
        void syncOn(u32);
        void applyWorldOffset(const MtVector3&, const MtVector3&);
        cMethodConstantTimeName::cMethodConstantBase* setRepeatMethd(cMethodConstantTimeName::cMethodConstantBase::REPEAT_CALLBACK repMethodRun, u32 repCount, f32 repTimer, bool fastmethdRun, u32 syncKeep);
        cMethodConstantTimeName::cMethodConstantBase* setRepeatMethd(MtVector3& vec, cMethodConstantTimeName::cMethodConstantBase::REPEAT_CALLBACK_PARAM repMethodRunParam, u32 repCount, f32 repTimer, bool fastmethdRun, u32 syncKeep);
        cMethodConstantTimeName::cMethodConstantBase* setRepeatMethd(u32 index, cMethodConstantTimeName::cMethodConstantBase::REPEAT_CALLBACK_PARAM_STATUS repMethodRunParam, u32 repCount, f32 repTimer, bool fastmethdRun, u32 syncKeep);
    private:
        cMethodConstantTimeName::cMethodConstantBase mMethodRepeat[32];  // offset: 0x10
        u32 mSyncCheck;  // offset: 0x1410
    public:
        static MyDTI DTI;
        static const u32 METHODREPEAT_MAX = 32;
    };
}  // namespace cMethodConstantTimeName
