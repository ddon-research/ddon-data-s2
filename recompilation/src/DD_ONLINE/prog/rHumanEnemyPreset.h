#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cHumanEnemyPreset;
class rHumanEnemyPreset;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cHumanEnemyPreset : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 7,
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
    cHumanEnemyPreset();
    virtual ~cHumanEnemyPreset() {}
public:
    u32 mId;  // offset: 0x8
    u32 mCustomSkillListId;  // offset: 0xc
    u32 mEquipListId;  // offset: 0x10
    u32 mEditType;  // offset: 0x14
    bool mIsDisableMontageRandam;  // offset: 0x18
    bool mIsDisableBeginBattleVoice;  // offset: 0x19
    bool mIsOriginalCustomSkillArc;  // offset: 0x1a
    static MyDTI DTI;
};

class rHumanEnemyPreset : public rTbl2<cHumanEnemyPreset>
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
    virtual bool loadData(MtDataReader& r, cHumanEnemyPreset* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline cHumanEnemyPreset::cHumanEnemyPreset() {
    this->mIsOriginalCustomSkillArc = false;
    this->mIsDisableMontageRandam = false;
    this->mIsDisableBeginBattleVoice = false;
    this->mEquipListId = 0;
    this->mEditType = 0;
    this->mId = 0;
    this->mCustomSkillListId = 0;
}
