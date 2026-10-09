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
class cEnemyLocalEstTable;
class rEnemyLocalEst;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cEnemyLocalEstTable : public MtObject
{
public:
    enum
    {
        STATUS_NOT = 1,
        STATUS_COLLISION = 2,
        STATUS_PARTS = 3,
        STATUS_WORKRATE = 4,
        STATUS_SCALE = 5,
        STATUS_LOCAL = 6,
        STATUS_LOCAL2 = 7,
        STATUS_MONTAGE = 8,
        STATUS_SYNCBIT = 9,
        STATUS_PARTSNO = 10,
    };
    enum
    {
        CTRL_TYPE_NOT = 1,
        CTRL_TYPE_EFFECT = 2,
        CTRL_TYPE_SOUND = 3,
        CTRL_TYPE_MATERIAL = 4,
        CTRL_TYPE_SHELL = 5,
        CTRL_TYPE_PRELIMINARY_01 = 6,
        CTRL_TYPE_PRELIMINARY_02 = 7,
        CTRL_TYPE_PRELIMINARY_03 = 8,
        CTRL_TYPE_PRELIMINARY_04 = 9,
        CTRL_TYPE_PRELIMINARY_05 = 10,
        CTRL_TYPE_PRELIMINARY_06 = 11,
        CTRL_TYPE_PRELIMINARY_07 = 12,
        CTRL_TYPE_PRELIMINARY_08 = 13,
        CTRL_TYPE_PRELIMINARY_09 = 14,
        CTRL_TYPE_PRELIMINARY_10 = 15,
        CTRL_TYPE_STATUS_REGEION = 16,
        CTRL_TYPE_STATUS_COLLISION = 17,
        CTRL_TYPE_STATUS_PARTS = 18,
        CTRL_TYPE_STATUS_WORKRATE = 19,
        CTRL_TYPE_STATUS_SCALE = 20,
        CTRL_TYPE_STATUS_LOCAL = 21,
        CTRL_TYPE_STATUS_LOCAL2 = 22,
        CTRL_TYPE_STATUS_MONTAGE = 23,
        CTRL_TYPE_STATUS_SYNCBIT = 24,
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
    cEnemyLocalEstTable();
    // Address: 0x01a8abd0 - 0x01a8abd1 (1 bytes)
    virtual ~cEnemyLocalEstTable() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mIdx;  // offset: 0x8
    bool mSetUpOff;  // offset: 0xc
    u32 mStatus;  // offset: 0x10
    u32 mBitNo;  // offset: 0x14
    bool mCheckBit;  // offset: 0x18
    bool mPlayAlways;  // offset: 0x19
    u32 mControlType;  // offset: 0x1c
    u32 mControlIndex;  // offset: 0x20
    u32 mBitContrlCommand;  // offset: 0x24
    static MyDTI DTI;
    static const u16 DATA_VERSION = 259;
};

class rEnemyLocalEst : public rTbl2<cEnemyLocalEstTable>
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
    virtual bool loadData(MtDataReader& in, cEnemyLocalEstTable* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cEnemyLocalEstTable::cEnemyLocalEstTable() {
    this->mSetUpOff = false;
    this->mStatus = static_cast<u32>(1);
    this->mCheckBit = true;
    this->mPlayAlways = false;
    this->mBitNo = static_cast<u32>(0);
    this->mIdx = static_cast<u32>(1);
    this->mControlType = static_cast<u32>(1);
    this->mControlIndex = static_cast<u32>(1);
    this->mBitContrlCommand = static_cast<u32>(4);
}
