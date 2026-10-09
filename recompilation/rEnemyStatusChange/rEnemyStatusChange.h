#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;

// Declarations
class cEnemyStatusChange;
class rEnemyStatusChange;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cEnemyStatusChange : public MtObject
{
public:
    enum
    {
        SET_ONCE = 1,
        SET_EVERY_FREAM = 2,
        SET_ONCE_REP = 3,
        SET_EVERY_FREAM_END = 4,
        SET_ONCE_END = 5,
        SET_ONCE_END_REP = 6,
    };
    enum BIT_COMMAND_TYPE
    {
        COMMAND_SET = 0,
        COMMAND_OR = 1,
        COMMAND_CUT = 2,
        COMMAND_AND = 3,
        COMMAND_NOT = 4,
        COMMAND_NUM = 5,
        COMMAND_INVALID = -1,
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
    cEnemyStatusChange();
    // Address: 0x01a8bf70 - 0x01a8bf71 (1 bytes)
    virtual ~cEnemyStatusChange() {}
    bool IsTypeCheckMaster(u32 type, u32 changeStatus);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mGroupNo;  // offset: 0x8
    u32 mGroupSubNo;  // offset: 0xc
    u32 mNextGroupSubNo;  // offset: 0x10
    bool mNextGroupSubOneGo;  // offset: 0x14
    u32 mType;  // offset: 0x18
    bool mTypeReverse;  // offset: 0x1c
    u32 mRepeatSetting;  // offset: 0x20
    u32 mChangeStatus;  // offset: 0x24
    u32 mSelectNo;  // offset: 0x28
    f32 mParam[2];  // offset: 0x2c
    f32 mSystemParam[3];  // offset: 0x34
    f32 mSystemParamWait;  // offset: 0x40
    u32 mBitContrlCommand;  // offset: 0x44
    static MyDTI DTI;
    static const u32 PARAMS_NUM = 2;
    static const u32 SYSTEM_PARAMS_NUM = 3;
    static const u16 DATA_VERSION = 9;
};

class rEnemyStatusChange : public rTbl2<cEnemyStatusChange>
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
    virtual bool loadData(MtDataReader& in, cEnemyStatusChange* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cEnemyStatusChange::cEnemyStatusChange() {
    this->mGroupNo = static_cast<u32>(0);
    this->mGroupSubNo = static_cast<u32>(0);
    this->mNextGroupSubNo = static_cast<u32>(0);
    this->mType = static_cast<u32>(12);
    this->mTypeReverse = false;
    this->mRepeatSetting = static_cast<u32>(1);
    this->mChangeStatus = static_cast<u32>(1);
    this->mNextGroupSubOneGo = false;
    this->mSystemParamWait = 0.0f;
    this->mSystemParam[1] = 0.0f;
    this->mSystemParam[2] = 0.0f;
    this->mParam[1] = 0.0f;
    this->mSystemParam[0] = 0.0f;
    this->mSelectNo = static_cast<u32>(0);
    this->mParam[0] = 0.0f;
    this->mBitContrlCommand = static_cast<u32>(4);
}
