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

// Declarations
class cEmLvUpParam;
class rEmLvUpParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cEmLvUpParam : public MtObject
{
public:
    enum RES_STATUS
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
    cEmLvUpParam();
    // Address: 0x01a87180 - 0x01a87181 (1 bytes)
    virtual ~cEmLvUpParam() {}
    void copy(const cEmLvUpParam* pParam);
private:
    u32 mLv;  // offset: 0x8
    f32 mHp_Cor[10];  // offset: 0xc
    f32 mShP_Cor[10];  // offset: 0x34
    f32 mBlP_Cor[10];  // offset: 0x5c
    f32 mOcd_Cor;  // offset: 0x84
    f32 mAttackWepPhys_Cor;  // offset: 0x88
    f32 mAttackWepMagic_Cor;  // offset: 0x8c
    f32 mDefenceWepPhys_Cor;  // offset: 0x90
    f32 mDefenceWepMagic_Cor;  // offset: 0x94
    f32 mAttackBasePhys_Cor;  // offset: 0x98
    f32 mAttackBaseMagic_Cor;  // offset: 0x9c
    f32 mDefenceBasePhys_Cor;  // offset: 0xa0
    f32 mDefenceBaseMagic_Cor;  // offset: 0xa4
    f32 mPower_Cor;  // offset: 0xa8
    f32 mGuardDefBase_Cor;  // offset: 0xac
    f32 mGuardDefWep_Cor;  // offset: 0xb0
    f32 mDownP_Cor;  // offset: 0xb4
    f32 mShakeP_Cor;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class rEmLvUpParam : public rTbl2<cEmLvUpParam>
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
    virtual bool loadData(MtDataReader& in, cEmLvUpParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};
