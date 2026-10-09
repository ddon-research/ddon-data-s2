#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cReaction;
class rReaction;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class cReaction : public MtObject
{
public:
    class MyDTI;
    class cCondition;
    class cTrigger;
    class cAction;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCondition : public MtObject
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
        cCondition();
        // Address: 0x01aa4150 - 0x01aa4151 (1 bytes)
        virtual ~cCondition() {}
        bool loadData(MtDataReader& r, cReaction::cCondition* pData);
    private:
        u32 getCondition();
        void setCondition(u32);
    public:
        u32 mCondition;  // offset: 0x8
        u64 mParam0;  // offset: 0x10
        u64 mParam1;  // offset: 0x18
        u32 mCkAndOR;  // offset: 0x20
        bool mReverse;  // offset: 0x24
        static MyDTI DTI;
    };
public:
    class cTrigger : public MtObject
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
        cTrigger();
        // Address: 0x01aa4140 - 0x01aa4141 (1 bytes)
        virtual ~cTrigger() {}
        bool loadData(MtDataReader& r, cReaction::cTrigger* pData);
    public:
        u32 mTrigger;  // offset: 0x8
        u32 mParam;  // offset: 0xc
        u32 mParam1;  // offset: 0x10
        u32 mCount;  // offset: 0x14
        static MyDTI DTI;
    };
public:
    class cAction : public MtObject
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
        cAction();
        // Address: 0x01aa4130 - 0x01aa4131 (1 bytes)
        virtual ~cAction() {}
        bool loadData(MtDataReader& r, cReaction::cAction* pData);
    public:
        u32 mPercent;  // offset: 0x8
        u32 mActNoLand;  // offset: 0xc
        u32 mActNoAir;  // offset: 0x10
        u32 mActNoDown;  // offset: 0x14
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
    cReaction();
    // Address: 0x01aa4120 - 0x01aa4121 (1 bytes)
    virtual ~cReaction() {}
public:
    cCondition mReactCondition[4];  // offset: 0x8
    bool mAllCondition;  // offset: 0xa8
    cTrigger mReactTrigger;  // offset: 0xb0
    cAction mReactAction[4];  // offset: 0xc8
    u32 mForceReaction;  // offset: 0x128
    u32 mActPrio;  // offset: 0x12c
    u32 mOptionFlg;  // offset: 0x130
    static MyDTI DTI;
    static const u32 REACT_COND_NUM = 4;
    static const u32 REACT_ACT_NUM = 4;
    static const u16 DATA_VERSION = 13;
};

class rReaction : public rTbl2<cReaction>
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
    virtual bool loadData(MtDataReader& r, cReaction* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cReaction::cCondition::cCondition() {
    this->mCondition = static_cast<u32>(0);
    this->mReverse = false;
    this->mCkAndOR = static_cast<u32>(0);
    this->mParam1 = static_cast<u64>(0);
    this->mParam0 = static_cast<u64>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cReaction::cTrigger::cTrigger() {
    this->mParam1 = static_cast<u32>(0);
    this->mCount = static_cast<u32>(0);
    this->mTrigger = static_cast<u32>(0);
    this->mParam = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cReaction::cAction::cAction() {
    this->mPercent = static_cast<u32>(0);
    this->mActNoLand = static_cast<u32>(4294967295);
    this->mActNoAir = static_cast<u32>(4294967295);
    this->mActNoDown = static_cast<u32>(4294967295);
}
