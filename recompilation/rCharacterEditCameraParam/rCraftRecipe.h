#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class rCraftRecipe;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rCraftRecipe : public cResource
{
public:
    enum NPC_ACTION
    {
        NPC_ACTION_NONE = 0,
        NPC_ACTION_STITHY = 1,
        NPC_ACTION_DESK = 2,
        NPC_ACTION_COOK = 3,
        NPC_ACTION_NUM = 4,
    };
public:
    class MyDTI;
    class cCraftRecipe;
    class cMaterialData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMaterialData : public MtObject
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
        cMaterialData();
        // Address: 0x01a83e90 - 0x01a83e91 (1 bytes)
        virtual ~cMaterialData() {}
        u32 getItemId() const;
        u8 getNum() const;
        bool isSp() const;
    public:
        u32 mItemId;  // offset: 0x8
        u32 mNum;  // offset: 0xc
        bool mIsSp;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cCraftRecipe : public MtObject
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
        cCraftRecipe();
        virtual ~cCraftRecipe();
        void releaseWork();
        u32 getRecipeId() const;
        u32 getItemId() const;
        u32 getCreateTime() const;
        u8 getCreateNum() const;
        u32 getGold() const;
        u32 getExp() const;
        u32 getCanCreateRank() const;
        u32 getMaterialListNum() const;
        rCraftRecipe::cMaterialData* getMaterialData(u32 index);
        bool isBaggage() const;
    public:
        u32 mRecipeId;  // offset: 0x8
        u32 mItemId;  // offset: 0xc
        u32 mCreateTime;  // offset: 0x10
        u8 mCreateNum;  // offset: 0x14
        u32 mGold;  // offset: 0x18
        u32 mExp;  // offset: 0x1c
        u32 mRank;  // offset: 0x20
        rCraftRecipe::NPC_ACTION mNpcAction;  // offset: 0x24
        bool mIsBaggage;  // offset: 0x28
        rCraftRecipe::cMaterialData* mpArrayData;  // offset: 0x30
        u32 mMaterialDataListNum;  // offset: 0x38
        MtTypedArray<rCraftRecipe::cMaterialData> mMaterialDataList;  // offset: 0x40
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
    rCraftRecipe();
    virtual ~rCraftRecipe();
public:
    cCraftRecipe* mpArrayData;  // offset: 0x70
    u32 mArrayDataNum;  // offset: 0x78
    static MyDTI DTI;
    static const s32 NativeFileMagic = 5260114;
    static const s32 NativeVersion = 6;
};
