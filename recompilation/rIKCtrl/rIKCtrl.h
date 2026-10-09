#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResPath.h"
#include "../shared/rCnsIK.h"
#include "../shared/rFullbodyIKHuman2.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class rCnsIK;
class rFullbodyIKHuman2;

// Declarations
class cIKCtrl;
class rIKCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cIKCtrl : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 2,
    };
    enum TYPE
    {
        TYPE_ARM = 0,
        TYPE_LEG = 1,
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
    cIKCtrl();
    // Address: 0x01a95550 - 0x01a95551 (1 bytes)
    virtual ~cIKCtrl() {}
public:
    u32 mDummy;  // offset: 0x8
    static MyDTI DTI;
};

class rIKCtrl : public rTbl2<cIKCtrl>
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
    rIKCtrl();
    virtual ~rIKCtrl();
    virtual bool loadData(MtDataReader& r, cIKCtrl* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    cResPath<rCnsIK> mCnsIKResPath_RArm;  // offset: 0x80
    cResPath<rCnsIK> mCnsIKResPath_LArm;  // offset: 0x88
    cResPath<rCnsIK> mCnsIKResPath_RLeg;  // offset: 0x90
    cResPath<rCnsIK> mCnsIKResPath_LLeg;  // offset: 0x98
    cResPath<rFullbodyIKHuman2> mFullbodyIKResPath;  // offset: 0xa0
    u32 mRArmType;  // offset: 0xa8
    u32 mLArmType;  // offset: 0xac
    u32 mRLegType;  // offset: 0xb0
    u32 mLLegType;  // offset: 0xb4
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cIKCtrl::cIKCtrl() {
    this->mDummy = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rIKCtrl::rIKCtrl() {
    this->mRArmType = static_cast<u32>(0);
    this->mLArmType = static_cast<u32>(0);
    this->mRLegType = static_cast<u32>(1);
    this->mLLegType = static_cast<u32>(1);
}
