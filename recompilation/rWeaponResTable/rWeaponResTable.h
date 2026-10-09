#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cResPath.h"
#include "../shared/rDDOModelMontage.h"
#include "../shared/rDeformWeightMap.h"
#include "../shared/rEffectProvider.h"
#include "../shared/rModel.h"
#include "../shared/rSoundRequest.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class MtString;
class rDDOModelMontage;
class rDeformWeightMap;
class rEffectProvider;
class rModel;
class rSoundRequest;

// Declarations
class cWeaponResTable;
class rWeaponResTable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class cWeaponResTable : public MtObject
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
    cWeaponResTable();
    virtual ~cWeaponResTable();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u16 getResVer();
    bool isCheck();
    u32 getTagId();
    MT_CTSTR getArcTag();
    u32 getSex();
    u64 getModelResId();
    u64 getModelResId2();
    u64 getSoftBodyResId();
    u64 getEffcResId();
    u64 getSndResId();
    u64 getMontageResId();
    u64 getMontageResId2();
public:
    u16 mResVer;  // offset: 0x8
    bool mIsCheck;  // offset: 0xa
    u32 mMTag;  // offset: 0xc
    MtString mComment;  // offset: 0x10
    MtString mArcTag;  // offset: 0x18
    u32 mSex;  // offset: 0x20
    cResPath<rModel> mpModelRes;  // offset: 0x28
    cResPath<rModel> mpModelRes2;  // offset: 0x30
    cResPath<rDeformWeightMap> mpDeformWeightMapRes;  // offset: 0x38
    cResPath<rEffectProvider> mpEffRes;  // offset: 0x40
    cResPath<rSoundRequest> mpSndRes;  // offset: 0x48
    cResPath<rDDOModelMontage> mpMontageRes;  // offset: 0x50
    cResPath<rDDOModelMontage> mpMontageRes2;  // offset: 0x58
    static MyDTI DTI;
    static const u32 DATA_VERSION = 9;
};

class rWeaponResTable : public rTbl2<cWeaponResTable>
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
    virtual bool loadData(MtDataReader& in, cWeaponResTable* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};
