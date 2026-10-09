#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "sNetworkExt.h"

// Forward declarations
class CDataGatheringItemElement;
class MtAllocator;
class MtDTI;
class MtString;

// Declarations
class ItemGetInfo;
class cGatherItemList;

// Type aliases from DWARF
using GatheringItemElementVec = MtTypedArray<CDataGatheringItemElement>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class ItemGetInfo : public MtObject
{
    // inferred: cGatherItemList::reqGather names cGatherItemList::mItemGetInfo[0].mID
    friend class cGatherItemList;
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
    ItemGetInfo();
    s32 getID() const;
    void setID(s32 NewValue);
    s32 getItemID() const;
    void setItemID(s32 NewValue);
    u32 getNum() const;
    void setNum(u32 NewValue);
private:
    s32 mID;  // offset: 0x8
    s32 mItemID;  // offset: 0xc
    u32 mNum;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cGatherItemList : public MtObject
{
public:
    enum GATHER_TYPE
    {
        GATHER_SET = 0,
        GATHER_DROP = 1,
        GATHER_PAWN_EXPEDITION = 2,
    };
    enum
    {
        GATHER_IDLE = 0,
        GATHER_REQ = 1,
        GATHER_WAIT = 2,
        GATHER_END = 3,
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
    cGatherItemList();
    virtual ~cGatherItemList();
    bool move();
    void reqGather(u32 groupId, u32 layerNo, u32 posId, u32 type);
    void reqGatherAgain();
    bool isItemGetListComplete();
    bool isError() const;
    bool isAppearEnemy() const;
    void clearItemGetInfo();
    u32 getItemGetInfoMax() const;
    u32 getItemGetInfoNum() const;
    ItemGetInfo* getItemGetInfo(u32 idx);
    bool addItemGetInfo(u32 id, u32 itemId, u32 num);
    void setItemGetList(const GatheringItemElementVec& list);
    u32 getGatherType() const;
    void setGatherType(u32);
    u32 getItemListGroupId();
    u32 getItemListLayerNo();
    u32 getItemListPosId();
    void setItemUID(MtString uid);
    void setAppearEnemy();
protected:
    sNetworkExt::NET_STAT getStatus();
    bool getItemList(u32 groupId, u32 layerNo, u32 posId, MT_CTSTR UID);
protected:
    u8 mRno;  // offset: 0x8
    bool mError;  // offset: 0x9
    bool mAppearEnemy;  // offset: 0xa
    u32 mGatherType;  // offset: 0xc
    u32 mGroupId;  // offset: 0x10
    u32 mLayerNo;  // offset: 0x14
    u32 mPosId;  // offset: 0x18
    MtString mItemUID;  // offset: 0x20
    ItemGetInfo mItemGetInfo[10];  // offset: 0x28
public:
    static MyDTI DTI;
    static const u32 ITEM_GET_INFO_NUM = 10;
};

// Inline, no code of its own: checked where it is inlined.
inline ItemGetInfo::ItemGetInfo() {
    this->mID = static_cast<s32>(0);
    this->mItemID = static_cast<s32>(0);
    this->mNum = static_cast<u32>(0);
}
