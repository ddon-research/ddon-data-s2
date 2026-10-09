#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class rEffectProvider;
class uDDOModel;

// Declarations
class cEfcMotSync;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cEfcMotSync : public MtObject
{
public:
    class MyDTI;
    class SyncManageFactor;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class SyncManageFactor : public MtObject
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
        SyncManageFactor();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setMotionNo(u32 no);
        u32 getMotionNo() const;
        void setBlendIndex(u32 index);
        u32 getBlendIndex() const;
        void setStartFrame(f32);
        void setStartFrame(f32 frame, f32 interval);
        f32 getStartFrame() const;
        void setEndFrame(f32 frame);
        f32 getEndFrame() const;
        void setInterval(f32);
        f32 getInterval() const;
        bool getLeaveFlag() const;
        void setLeaveFlag(bool flag);
        bool getFreeSpeedFlag() const;
        void setFreeSpeedFlag(bool flag);
        bool getFreeScaleFlag() const;
        void setFreeScaleFlag(bool flag);
        bool getFreeOffsetFlag() const;
        void setFreeOffsetFlag(bool flag);
        bool getSetOnceFlag() const;
        void setSetOnceFlag(bool flag);
        void setEfcIndexNo(s32 no);
        s32 getEfcIndexNo() const;
        void setEfcElementNo(s32 no);
        s32 getEfcElementNo() const;
        void setResource(rEffectProvider* pResource);
        rEffectProvider* getResource() const;
        void setSetFlag(u32 flag, u32 blend);
        u32 getSetFlag(u32 blend) const;
        void setOldFrame(f32 frame, u32 blend);
        f32 getOldFrame(u32 blend) const;
        void setStartFrameEx(f32);
        void setStartFrameEx(f32, f32);
        void resetStartFrameEx();
        void updateStartFrameEx();
        f32 getStartFrameEx() const;
    private:
        u32 mMotionNo;  // offset: 0x8
        u32 mBlendIndex;  // offset: 0xc
        f32 mStartFrame;  // offset: 0x10
        f32 mEndFrame;  // offset: 0x14
        f32 mInterval;  // offset: 0x18
        bool mLeaveFlag;  // offset: 0x1c
        bool mFreeSpeedFlag;  // offset: 0x1d
        bool mFreeScaleFlag;  // offset: 0x1e
        bool mFreeOffsetFlag;  // offset: 0x1f
        bool mSetOnceFlag;  // offset: 0x20
        s32 mEfcIndexNo;  // offset: 0x24
        s32 mEfcElementNo;  // offset: 0x28
        rEffectProvider* mprEPV;  // offset: 0x30
        u32 mSetFlag[8];  // offset: 0x38
        f32 mOldFrame[8];  // offset: 0x58
        f32 mStartFrameEx;  // offset: 0x78
    public:
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
    cEfcMotSync();
    virtual ~cEfcMotSync();
    void setupFromProv(rEffectProvider* pEPV);
    void clear();
    void moveSync(uDDOModel* pChar);
private:
    SyncManageFactor* mpSyncManageList;  // offset: 0x8
    u32 mSyncManageNum;  // offset: 0x10
public:
    static MyDTI DTI;
};
