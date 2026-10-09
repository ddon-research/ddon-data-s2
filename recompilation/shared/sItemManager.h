#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Character.h"
#include "Item.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "MtSynchronize.h"
#include "cItemParam.h"
#include "cSystem.h"
#include "nCharacterData.h"
#include "rItemList.h"
#include "rShopGoods.h"

// Forward declarations
class BitReader;
class BitWriter;
class CDataC2SChangeCharacterEquipInfo;
class CDataCommonU32;
class CDataCommonU8;
class CDataEquipElementParam;
class CDataEquipItemInfo;
class CDataItemList;
class CDataItemUIDList;
class CDataItemUpdateResult;
class CDataJewelryEquipLimit;
class CDataMoveItemUIDFromTo;
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cArcLoaderBase;
class cContextInstHm;
class cCraftParam;
class cItemParam;
class cShopGoods;
namespace nCharacterData { struct stEquipData; }
class rGUIMessage;
class rItemList;
class rShopGoods;

// Declarations
class sItemManager;

// Type aliases from DWARF
using C2SChangeCharacterEquipInfoVec = MtTypedArray<CDataC2SChangeCharacterEquipInfo>;
using CItemList = CDataItemList;
using CItemUpdateResult = CDataItemUpdateResult;
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using CommonU8Vec = MtTypedArray<CDataCommonU8>;
using EquipItemInfoVec = MtTypedArray<CDataEquipItemInfo>;
using ItemUIDListVec = MtTypedArray<CDataItemUIDList>;
using ItemUpdateResultVec = MtTypedArray<CDataItemUpdateResult>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MoveItemUIDFromToVec = MtTypedArray<CDataMoveItemUIDFromTo>;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class sItemManager : public cSystem
{
public:
    enum SortType
    {
        SORT_NONE = 0,
        SORT_ASC = 1,
        SORT_DESC = 2,
        SORT_NUM = 3,
    };
    enum STORAGE_FILLTER_TYPE
    {
        STORAGE_FILLTER_TYPE_ALL = 0,
        STORAGE_FILLTER_TYPE_CRAFT = 1,
        STORAGE_FILLTER_TYPE_DELIVER = 2,
        STORAGE_FILLTER_TYPE_SHOP = 3,
        SOTRAGE_FILLTER_TYPE_EQUIP = 4,
        STORAGE_FILLTER_TYPE_POST = 5,
        STORAGE_FILLTER_TYPE_BAGGAGE_FREE = 6,
        STORAGE_FILLTER_TYPE_BAGGAGE = 7,
        STORAGE_FILLTER_TYPE_ITEM_LIST = 8,
        STORAGE_FILLTER_TYPE_LOGIN_LIST = 9,
        STORAGE_FILLTER_TYPE_NUM = 10,
    };
    enum LIMIT_TYPE
    {
        LIMIT_TYPE_NONE = 0,
        LIMIT_TYPE_OUT = 1,
        LIMIT_TYPE_IN = 2,
    };
    enum GET_LIST_RESULT
    {
        GET_LIST_RESULT_WAIT = 0,
        GET_LIST_RESULT_SUCCESS = 1,
        GET_LIST_RESULT_ERROR = 2,
    };
    enum
    {
        REQ_GET_GP_SUCCESS = 0,
        REQ_GET_GP_WAIT = 1,
        REQ_GET_GP_FAILED = 2,
        REQ_GET_GP_NUM = 3,
    };
    enum USE_POINT_FOR
    {
        USE_POINT_FOR_HP_UP = 0,
        USE_POINT_FOR_ST_UP = 1,
        USE_POINT_FOR_LOSTTIMER_UP = 2,
        USE_POINT_FOR_MAX = 3,
    };
    enum PACKET_TYPE
    {
        PACKET_TYPE_PARTY = 0,
        PACKET_TYPE_LOBBY = 1,
        PACKET_TYPE_PAWN = 2,
        PACKET_TYPE_MINE_FOR_BAG = 3,
        PACKET_TYPE_MINE_FOR_STORAGE = 4,
        PACKET_TYPE_PARTY_CREST = 5,
        PACKET_TYPE_PARTY_COLOR = 6,
        PACKET_TYPE_PARTY_PAWN_CREST = 7,
        PACKET_TYPE_PARTY_PAWN_COLOR = 8,
    };
    enum EQUIP_HIDE_PACKET_TYPE
    {
        EQUIP_HIDE_PACKET_TYPE_NONE = 0,
        EQUIP_HIDE_PACKET_TYPE_HEAD = 1,
        EQUIP_HIDE_PACKET_TYPE_LANTERN = 2,
    };
    enum EQUIP_HIDE_PACKET_PL_TYPE
    {
        EQUIP_HIDE_PACKET_PL_TYPE_NONE = 0,
        EQUIP_HIDE_PACKET_PL_TYPE_MY_PLAYER = 1,
        EQUIP_HIDE_PACKET_PL_TYPE_MY_PAWN = 2,
        EQUIP_HIDE_PACKET_PL_TYPE_OTHER = 3,
    };
    enum DealReqType
    {
        DEAL_BUY = 0,
        DEAL_SELL = 1,
    };
public:
    class MyDTI;
    struct stJobEquipData;
    class cShop;
    class stRequest;
    class cItemBag;
    class cSortParam;
    class cItemParamList;
    class cEquipList;
    class cChangeJob;
    class cGPDetail;
    struct stSortData;
    struct cSwitchStorage;
    class cHideEquip;
    class cItemList;
public:
    typedef struct
    {
    public:
        u8 mCategory;  // offset: 0x0
        u8 mLimit;  // offset: 0x1
    } JewelryEquipLimit;
public:
    using EXEC_METHOD = bool(MtObject::*)(void*);
    using RECV_FUNC = void(MtObject::*)(void*);
    using RECV_FUNC2 = bool(MtObject::*)(void*);
    using RECV_FUNC3 = bool(MtObject::*)(bool, s32);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stJobEquipData
    {
    public:
        u16 wepMain;  // offset: 0x0
        u16 wepSub;  // offset: 0x2
        u16 protectHelm;  // offset: 0x4
        u16 protectBody;  // offset: 0x6
        u16 protectLeg;  // offset: 0x8
        u16 protectArm;  // offset: 0xa
        u16 wearBody;  // offset: 0xc
        u16 wearLeg;  // offset: 0xe
        u16 accessory;  // offset: 0x10
        u16 jewelry1;  // offset: 0x12
        u16 jewelry2;  // offset: 0x14
    };
public:
    class cShop : public MtObject
    {
        // inferred: sItemManager::releaseResource names sItemManager::cShop::mpGoodsList
        friend class sItemManager;
    public:
        enum ShopType
        {
            SHOP_TYPE_ITEM = 0,
            SHOP_TYPE_ARMS = 1,
            SHOP_TYPE_MATERIAL = 2,
            SHOP_TYPE_GENERAL = 3,
            SHOP_TYPE_DOGMA01 = 4,
            SHOP_TYPE_DOGMA02 = 5,
            SHOP_TYPE_DOGMA03 = 6,
            SHOP_TYPE_NUM = 7,
        };
    public:
        cShop();
        virtual ~cShop();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void releaseResource();
        MtTypedArray<cShopGoods>* getGoodsList();
        void buyGoods(sItemManager::stRequest* pReq);
        void sellItem(sItemManager::stRequest* pReq);
        bool isEnableSell();
        cShopGoods* getGoodsInfo(u32 index) const;
        bool reduceStock(u32, u32);
        bool searchGoods(u32, u32*);
        bool isAvailableCategory(rItemList::ITEM_CATEGORY);
        u32 getShopNo();
        u32 getGoodsTypeNum();
        bool setGoodsList(sItemManager::stRequest* pReq);
        void setBusy(bool isBusy, s32 err_code);
        bool canBuy(u32 goodsIndex);
        bool canBuy(cShopGoods* pGoods);
        nCharacter::E_WALLET_POINT_TYPE getPointType();
    private:
        bool mIsBusy;  // offset: 0x8
        s32 mResult;  // offset: 0xc
        u32 mShopNo;  // offset: 0x10
        MtTypedArray<cShopGoods> mGoods;  // offset: 0x18
        rShopGoods* mpGoodsList;  // offset: 0x38
    };
public:
    class stRequest : public MtObject
    {
    public:
        enum
        {
            REQ_STATUS_WAIT = 0,
            REQ_STATUS_BUSY = 1,
            REQ_STATUS_FINISH = 2,
        };
        enum
        {
            RNO_REQ = 0,
            RNO_WAIT = 1,
            RNO_WAIT2 = 2,
            RNO_WAIT3 = 3,
            RNO_WAIT4 = 4,
            RNO_WAIT5 = 5,
            RNO_WAIT6 = 6,
            RNO_DEBUG_ITEM_ADD = 7,
        };
        enum
        {
            RNO2_GET_LIST_REQ = 0,
            RNO2_GET_LIST_WAIT = 1,
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
        stRequest();
        virtual ~stRequest();
        s32 getErrCode() const;
        bool getResult() const;
        u32 getItemNo() const;
        MT_CTSTR getUID() const;
        u32 getTargetBag() const;
        u32 getParam(u32 index) const;
        void setResultCancel(bool isCancel);
        bool isResultCancel();
        bool isExit(void* ptr);
    public:
        void* mpParent;  // offset: 0x8
        sItemManager::EXEC_METHOD mpFunc;  // offset: 0x10
        sItemManager::RECV_FUNC mpRecvFunc;  // offset: 0x20
        MtObject* mpParam[4];  // offset: 0x30
        u32 mStatus;  // offset: 0x50
        void* mpBagParent;  // offset: 0x58
        sItemManager::RECV_FUNC2 mpBagFunc;  // offset: 0x60
        sItemManager::RECV_FUNC3 mpBagResultFunc;  // offset: 0x70
        MtString mUID;  // offset: 0x80
        s32 mErrCode;  // offset: 0x88
        u32 mRno;  // offset: 0x8c
        u32 mRno2;  // offset: 0x90
        bool mResult;  // offset: 0x94
        bool mIsResultCancel;  // offset: 0x95
        u8 mType;  // offset: 0x96
        bool mIsWaitNotice;  // offset: 0x97
        static MyDTI DTI;
        static const u32 REQ_PARAM_NUM = 4;
    };
public:
    class cSortParam : public MtObject
    {
    public:
        enum SORT_TYPE
        {
            SORT_TYPE_NONE = 0,
            SORT_TYPE_ID = 1,
            SORT_TYPE_NAME = 2,
            SORT_TYPE_GRADE = 3,
            SORT_TYPE_RANK = 4,
            SORT_TYPE_SELL = 5,
            SORT_TYPE_CATEGORY = 6,
            SORT_TYPE_MATERIAL_PRI = 7,
            SORT_TYPE_WEAPON_PRI = 8,
            SORT_TYPE_NUM = 9,
        };
        enum SORT_DIR
        {
            SORT_DIR_NONE = 0,
            SORT_DIR_DEC = 1,
            SORT_DIR_INC = 2,
            SORT_DIR_NUM = 3,
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
        cSortParam();
        void init();
        bool sortBySpace(const cItemParam* src, const cItemParam* dst, u32 param);
        bool sortByItemId(const cItemParam* src, const cItemParam* dst, u32 param);
        bool sortByName(const cItemParam* src, const cItemParam* dst, u32 param);
        bool sortByGrade(const cItemParam* src, const cItemParam* dst, u32 param);
        bool sortByRank(const cItemParam* src, const cItemParam* dst, u32 param);
        bool sortBySell(const cItemParam* src, const cItemParam* dst, u32 param);
        bool sortByUseItemCategory(const cItemParam* src, const cItemParam* dst, u32 param);
        bool sortByMaterialItemCategory(const cItemParam* src, const cItemParam* dst, u32 param);
        bool sortByArmsItemCategory(const cItemParam* src, const cItemParam* dst, u32 param);
        bool sortByCustomSort(const cItemParam* src, const cItemParam* dst, u32 param);
    public:
        u8 mSortType;  // offset: 0x8
        u8 mSortDir;  // offset: 0x9
        static MyDTI DTI;
    };
public:
    class cItemParamList : public MtObject
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
        cItemParamList();
        // Address: 0x01ac6300 - 0x01ac6301 (1 bytes)
        virtual ~cItemParamList() {}
        void setItemParam(cItemParam* pParam);
        cItemParam* getItemParam();
    private:
        cItemParam* mpItemParam;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class cEquipList : public MtObject
    {
    public:
        enum
        {
            EQUIP_TYPE_PERFORMANCE = 1,
            EQUIP_TYPE_VISUAL = 2,
            EQUIP_TYPE_MUN = 3,
        };
    public:
        class MyDTI;
        class cEquipData;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cEquipData : public MtObject
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
            cEquipData();
            void setItemParam(cItemParam*);
            cItemParam* getItemParam();
            void setCategory(u32);
            u32 getCategory();
            void setTargetNo(u32);
            u32 getTargetNo();
            void setIsNone(bool);
            bool isNone();
        private:
            cItemParam* mpItemParam;  // offset: 0x8
            u32 mCategory;  // offset: 0x10
            u32 mTargetNo;  // offset: 0x14
            bool mIsNone;  // offset: 0x18
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
        cEquipList();
        virtual ~cEquipList();
        bool addEquipList(cItemParam* pItem, u32 category, u32 type, bool isNone);
        cEquipData* getEquipData(u32);
        u32 getListNum();
        void setPawnId(u32 pawnId);
        u32 getPawnId();
        void setStorageType(u32 type);
        u32 getStorageType();
    public:
        C2SChangeCharacterEquipInfoVec mServerEquipList;  // offset: 0x8
    private:
        u32 mPawnId;  // offset: 0x28
        u32 mStorageType;  // offset: 0x2c
        MtTypedArray<cEquipData> mEquipList;  // offset: 0x30
        void* mpPacket;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
public:
    class cChangeJob : public MtObject
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
        cChangeJob();
        // Address: 0x01ac5dc0 - 0x01ac5dc1 (1 bytes)
        virtual ~cChangeJob() {}
        void setPawnId(u32 pawnId);
        u32 getPawnId();
        void setJob(u8 job);
        u8 getJob();
        void setPacket(void* pPacket);
        void* getPacket();
    private:
        u32 mPawnId;  // offset: 0x8
        u8 mJob;  // offset: 0xc
        void* mpPacket;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cGPDetail : public MtObject
    {
    public:
        enum
        {
            SERVER_RESULT_NONE = 0,
            SERVER_RESULT_WAIT = 1,
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
        cGPDetail();
        virtual ~cGPDetail();
        void setUseLimit(u64 limit);
        void move();
        void check();
        u32 reqGetGP();
    private:
        u32 reqGetGPCore();
    public:
        u64 mUseLimit;  // offset: 0x8
        f32 mRepeatWaitTime;  // offset: 0x10
        MtCriticalSection mCS;  // offset: 0x18
        u8 mServerResult;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    struct stSortData
    {
    public:
        void setDefaultData();
        bool serialize(BitWriter& w) const;
        bool deserialize(BitReader& r, u32 version, u32 releaseVersion);
    public:
        u16* mpSortData;  // offset: 0x0
        u64 mSendTime;  // offset: 0x8
        bool mIsUpdate;  // offset: 0x10
        u16 mSendSize;  // offset: 0x12
        u8 mSortType;  // offset: 0x14
        u8 mStorageType;  // offset: 0x15
    };
public:
    struct cSwitchStorage
    {
    public:
        cSwitchStorage();
    public:
        bool mIsSwitch;  // offset: 0x0
        nItem::E_STORAGE_TYPE mTargetStorage;  // offset: 0x4
        nItem::E_STORAGE_TYPE mChangeStorage;  // offset: 0x8
    };
public:
    class cHideEquip : public MtObject
    {
    public:
        enum
        {
            PL_TYPE_MY_PLAYER = 0,
            PL_TYPE_MY_PAWN = 1,
        };
        enum
        {
            EQUIP_TYPE_HEAD = 0,
            EQUIP_TYPE_LANTERN = 1,
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
        cHideEquip();
        // Address: 0x01ac5e80 - 0x01ac5e81 (1 bytes)
        virtual ~cHideEquip() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        u8 getPlType();
        u8 getEquipType();
        bool isHideOff();
    public:
        u8 mPlType;  // offset: 0x8
        u8 mEquipType;  // offset: 0x9
        bool mIsHideOff;  // offset: 0xa
        static MyDTI DTI;
    };
public:
    class cItemList : public MtObject
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
        cItemList();
        // Address: 0x019761c0 - 0x019761c1 (1 bytes)
        virtual ~cItemList() {}
        void setItemNo(u32 itemNo);
        u32 getItemNo();
        void setItemNum(u32 num);
        u32 getItemNum();
    private:
        u32 mItemNo;  // offset: 0x8
        u32 mItemNum;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
public:
    class cItemBag : public MtObject
    {
    public:
        enum ITEM_CATEGORY
        {
            ITEM_CATEGORY_NONE = 0,
            ITEM_CATEGORY_USE_ITEM = 1,
            ITEM_CATEGORY_MATERIAL_ITEM = 2,
            ITEM_CATEGORY_ARMS_ITEM = 3,
            ITEM_CATEGORY_KEY_ITEM = 4,
            ITEM_CATEGORY_JOB_ITEM = 5,
            ITEM_CATEGORY_EQUIP_ITEM = 8,
            ITEM_CATEGORY_ALL_ITEM = 9,
            ITEM_CATEGORY_NONE_ITEM = -1,
        };
        enum UPGRADE_RESULT
        {
            UPGRADE_RESULT_NONE = 0,
            UPGRADE_RESULT_PL = 1,
            UPGRADE_RESULT_PAWN = 2,
            UPGRADE_RESULT_NUM = 3,
        };
        enum
        {
            ITEM_SLOT_CONTROL_EXCHANGE = 0,
            ITEM_SLOT_CONTROL_SEPARATE = 1,
            ITEM_SLOT_CONTROL_COLLECT = 2,
            ITEM_SLOT_CONTROL_NUM = 3,
        };
        enum
        {
            ITEM_NO_NONE = 0,
            ITEM_NO_START = 1,
            ITEM_NO_END = 500,
            ITEM_NO_NUM = 501,
        };
    public:
        class MyDTI;
        class cGetItemListData;
        class cGatheringItemData;
        class cCraftStartData;
        class cCraftUpGradeData;
        class cCraftColorChange;
        class cAreaMasterSuppyData;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cGetItemListData : public MtObject
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
            cGetItemListData();
            virtual ~cGetItemListData();
        public:
            u32 mItemId;  // offset: 0x8
            u32 mItemNum;  // offset: 0xc
            u32 mEquipCharcaterId;  // offset: 0x10
            u32 mEquipPawnId;  // offset: 0x14
            u32 mSlotType;  // offset: 0x18
            u32 mSlotNo;  // offset: 0x1c
            u32 mEquipPoint;  // offset: 0x20
            u8 mCharType;  // offset: 0x24
            u8 mColor;  // offset: 0x25
            u8 mStorageType;  // offset: 0x26
            cCraftParam mCraftParamList;  // offset: 0x28
            static MyDTI DTI;
        };
    public:
        class cGatheringItemData : public MtObject
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
            cGatheringItemData();
            // Address: 0x01ac4e70 - 0x01ac4e71 (1 bytes)
            virtual ~cGatheringItemData() {}
            void setStageId(u32 stageId);
            u32 getStageId();
            void setGroupId(u32 groupId);
            u32 getGroupId();
            void setLayerNo(u32 layerNo);
            u32 getLayerNo();
            void setPosId(u32 posId);
            u32 getPosId();
        private:
            u32 mStageId;  // offset: 0x8
            u32 mGroupId;  // offset: 0xc
            u32 mLayerNo;  // offset: 0x10
            u32 mPosId;  // offset: 0x14
        public:
            static MyDTI DTI;
        };
    public:
        class cCraftStartData : public MtObject
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
            cCraftStartData();
            virtual ~cCraftStartData();
            void setRecipeId(u32 recipeId);
            u32 getRecipeId();
            void setMainPawnId(u32 pawnId);
            u32 getMainPawnId();
            void setToppingUID(MT_CTSTR UID);
            MT_CTSTR getToppingUID();
            void setCreateCount(u8 createCount);
            u8 getCreateCount();
        private:
            u32 mRecipeId;  // offset: 0x8
            u32 mMainPawnId;  // offset: 0xc
            MtString mToppingUID;  // offset: 0x10
            u8 mCreateCount;  // offset: 0x18
        public:
            static MyDTI DTI;
        };
    public:
        class cCraftUpGradeData : public MtObject
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
            cCraftUpGradeData();
            virtual ~cCraftUpGradeData();
            void setMainPawnId(u32 pawnId);
            u32 getMainPawnId();
            void setUID(MT_CTSTR UID);
            MT_CTSTR getUID();
        private:
            u32 mMainPawnId;  // offset: 0x8
            MtString mUID;  // offset: 0x10
        public:
            static MyDTI DTI;
        };
    public:
        class cCraftColorChange : public MtObject
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
            cCraftColorChange();
            virtual ~cCraftColorChange();
            void setMainPawnId(u32 pawnId);
            u32 getMainPawnId();
            void setColor(u8 color);
            u8 getColor();
            void setUID(MT_CTSTR UID);
            MT_CTSTR getUID();
        private:
            u32 mMainPawnId;  // offset: 0x8
            u8 mColor;  // offset: 0xc
            MtString mUID;  // offset: 0x10
        public:
            static MyDTI DTI;
        };
    public:
        class cAreaMasterSuppyData : public MtObject
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
            cAreaMasterSuppyData();
            // Address: 0x01ac5e00 - 0x01ac5e01 (1 bytes)
            virtual ~cAreaMasterSuppyData() {}
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void setAreaID(u32 areaID);
            u32 getAreaID();
            void setCancel(bool isCancel);
            bool isCancel();
        private:
            u32 mAreaID;  // offset: 0x8
            bool mIsCancel;  // offset: 0xc
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
        cItemBag();
        virtual ~cItemBag();
        void releaseBag();
        void createSlot(ITEM_CATEGORY category, u32 num);
        void createSortDataToServer(ITEM_CATEGORY category);
        void createList(u32 num);
        void removeList(u32 no);
        void removeEquipList(u32 no);
        cItemParam* getItemParam(u32 no);
        cItemParam* getItemParamToCategory(ITEM_CATEGORY category, u32 no);
        cItemParam* getItemParamToSort(ITEM_CATEGORY category, u32 no);
        cItemParam* getItemParamByIndex(u32 index, u32 no);
        cItemParam* getItemParamToServerSlot(u32 cateIdx, u32 serverSlot);
        sItemManager::cItemParamList* getItemParamListByIndex(u32 no);
        u32 getItemBagSlotMaxNum(ITEM_CATEGORY category);
        u32 getItemBagNum();
        u32 getItemBagNumToUse();
        u32 getSlotMaxNum(ITEM_CATEGORY category);
        u32 getSlotMaxNumToUse(ITEM_CATEGORY category);
        u32 getItemBagNum(ITEM_CATEGORY category);
        u32 getItemBagNumToUse(ITEM_CATEGORY category);
        u32 getItemNum(u32 index);
        u32 getItemTotalNum(u32 ItemNo);
        u32 getItemTotalNum(u32 ItemNo, rItemList::ITEM_CATEGORY rCategory);
        u32 getItemTotalNum(cItemParam* pItemParam, ITEM_CATEGORY category);
        u32 getItemTotalNumMyPL(cItemParam* pItemParam, ITEM_CATEGORY category);
        u32 getItemUseSlotNum(u32 ItemNo);
        bool searchItem(u32 ItemNo, u32* pIndex);
        bool searchItemToSetStartIndex(u32 ItemNo, u32* pIndex);
        bool searchItemToNumLessIndex(u32 ItemNo, u32* pIndex);
        bool searchItemUID(MT_CTSTR UID, u32* pIndex);
        bool searchItemUIDForCategory(ITEM_CATEGORY category, MT_CTSTR UID, u32* pIndex);
        bool searchItemUIDForSort(ITEM_CATEGORY category, MT_CTSTR UID, u32* pIndex);
        u32 getItemMaxStackSlotNo(u32 ItemNo, s32* pSlotNo);
        u32 getItemAddMaxNum(u32 ItemNo);
        u32 getItemAddMaxInExistSlot(u32 ItemNo);
        bool isBusy();
        s32 getResult();
        u32 getUseItemEmptySlotNum();
        u32 getArmItemEmptySlotNum();
        u32 getMaterialItemEmptySlotNum();
        u32 getKeyItemEmptySlotNum();
        u32 getJobItemEmptySlotNum();
        u32 getAllItemEmptySlotNum();
        u32 getEmptySlotNum(ITEM_CATEGORY category);
        u32 getSlotMaxNumByIndex(u32 cateIdx);
        void exchangeItemSlotToSort(ITEM_CATEGORY category, u32 srcSlotNo, u32 dstSlotNo);
        bool isBazaarExhibitItem();
        void setTargetNo(u32 TargetNo);
        u32 getTargetNo();
        void setUseItemSlotNum(u32 slotNum);
        u32 getUseItemSlotNum();
        void setArmItemSlotNum(u32 slotNum);
        u32 getArmItemSlotNum();
        void setMaterialItemSlotNum(u32 slotNum);
        u32 getMaterialItemSlotNum();
        void setKeyItemSlotNum(u32 slotNum);
        u32 getKeyItemSlotNum();
        void setJobItemSlotNum(u32 slotNum);
        u32 getJobItemSlotNum();
        void setEquipItemSlotNum(u32 slotNum);
        u32 getEquipItemSlotNum();
        void setAllItemSlotNum(u32 slotNum);
        u32 getAllItemSlotNum();
        void setSortParam(ITEM_CATEGORY category, sItemManager::cSortParam::SORT_TYPE sortType, sItemManager::cSortParam::SORT_DIR sortDir);
        bool isStorageToBagCategoryOverFlow(u32 targetNo, MT_CTSTR UID, u32 Num);
        bool isCategoryOverFlow(u32 itemNo, u32 Num);
        u32 getItemCategoryNum(u32 itemNo, u32 Num);
        u32 getItemCategoryToArmsNum(u32 itemNo, u32 Num);
        bool isEmptySlotItemAdd(MtTypedArray<sItemManager::cItemList>& list);
        u32 getEmptySlotNumWhenItemAdd(u32 ItemNo, u32 Num, ITEM_CATEGORY searchCategory);
        u32 getEmptySlotNumWhenItemSub(u32 ItemNo, u32 Num, ITEM_CATEGORY searchCategory);
        bool isEmptyItemAdd(MtTypedArray<sItemManager::cItemList>& list, MtTypedArray<sItemManager::cItemList>* pRetList);
        bool getItemList(sItemManager::stRequest* pReq);
        bool deleteItem(sItemManager::stRequest* pReq);
        bool setEquip(sItemManager::stRequest* pReq);
        bool changeJob(sItemManager::stRequest* pReq);
        bool addItemNotice(CItemList* pUpdateItem);
        void sortStrageItem(ITEM_CATEGORY category, sItemManager::cSortParam::SORT_TYPE sortType, sItemManager::cSortParam::SORT_DIR sortDir);
        void setServerSort(bool flag);
        static u32 getStorageCategoryIndex(ITEM_CATEGORY category);
        static u32 getCategoryIndex(rItemList::ITEM_CATEGORY category);
        static u32 getCategoryIndex(ITEM_CATEGORY category);
        static ITEM_CATEGORY getIndexCategory(u32 cateIdx);
        static rItemList::ITEM_CATEGORY getItemCategoryToStorageCategory(ITEM_CATEGORY category);
        ITEM_CATEGORY getStorageCategotyToItemCategory(rItemList::ITEM_CATEGORY category);
        cGetItemListData* getItemListData();
        ITEM_CATEGORY convServerSlotType(nItem::E_STORAGE_TYPE type);
        void deleteSortData(u32 cateIdx);
        void sortSpaceSlot2(u32 cateIdx);
        MtTypedArray<cItemParam>& getSortList(u8 sortType);
        bool isEffectvie();
        void setEffective(bool isEffective);
    private:
        bool addItem(sItemManager::stRequest* pReq);
        bool moveItems(sItemManager::stRequest* pReq);
        bool checkItem(sItemManager::stRequest* pReq);
        bool useItem(sItemManager::stRequest* pReq);
        bool slotControlItem(sItemManager::stRequest* pReq);
        bool addGatheringItems(sItemManager::stRequest* pReq);
        bool addDropItems(sItemManager::stRequest* pReq);
        bool addPawnExpeditionRewardDropItems(sItemManager::stRequest* pReq);
        bool deliverItem(sItemManager::stRequest* pReq);
        bool getRewardBoxItem(sItemManager::stRequest* pReq);
        bool startCraft(sItemManager::stRequest* pReq);
        bool getCraftItem(sItemManager::stRequest* pReq);
        cContextInstHm* upGradeEquipChange(MT_CTSTR UID, UPGRADE_RESULT& result, bool isUpGrade);
        bool startCraftUpGrade(sItemManager::stRequest* pReq);
        bool startCraftElementAttach(sItemManager::stRequest* pReq);
        bool startCraftElementDetach(sItemManager::stRequest* pReq);
        bool startCraftColorChange(sItemManager::stRequest* pReq);
        bool urocoHPLevelUp(sItemManager::stRequest* pReq);
        bool urocoStaminaLevelUp(sItemManager::stRequest* pReq);
        bool urocoLostTimerLevelUp(sItemManager::stRequest* pReq);
        bool addGold(sItemManager::stRequest* pReq);
        bool useGold(sItemManager::stRequest* pReq);
        bool getShopList(sItemManager::stRequest* pReq);
        bool getAreaMasterSupply(sItemManager::stRequest* pReq);
        bool noticeItemList(sItemManager::stRequest* pReq);
        void setBusy(bool isBusy, s32 err_code);
        bool resetItemListCommon(sItemManager::stRequest* pReq);
        void addSortData(u32 cateIdx, u32 slotNo, cItemParam* pItemParam);
        void deleteSortDataCore(u32 cateIdx, cItemParam* pDst, s32 eraseSlot);
        void deleteSortDataToItemList(u32 cateIdx, cItemParam* pDst);
        u32 getItemListNum();
        void setItemListNum(u32 num);
        void addItemListNum(u32);
        void sortSpaceSlot(u32 cateIdx);
    private:
        bool mIsEffective;  // offset: 0x8
        MtTypedArray<cItemParam> mItem[7];  // offset: 0x10
        cItemParam mItemSortDummy;  // offset: 0xf0
        bool mIsServerSort;  // offset: 0x168
        MtTypedArray<cItemParam> mItemSortData[7];  // offset: 0x170
        sItemManager::cSortParam mSortParam[7];  // offset: 0x250
        MtTypedArray<sItemManager::cItemParamList> mItemList;  // offset: 0x2c0
        u32 mItemListNum;  // offset: 0x2e0
        u32 mRequestBuff[10];  // offset: 0x2e4
        bool mIsBusy;  // offset: 0x30c
        s32 mResult;  // offset: 0x310
        u32 mTargetNo;  // offset: 0x314
        u32 mUseItemSlotNum;  // offset: 0x318
        u32 mArmItemSlotNum;  // offset: 0x31c
        u32 mMaterialItemSlotNum;  // offset: 0x320
        u32 mKeyItemSlotNum;  // offset: 0x324
        u32 mJobItemSlotNum;  // offset: 0x328
        u32 mEquipItemSlotNum;  // offset: 0x32c
        u32 mAllItemSlotNum;  // offset: 0x330
        cGetItemListData mGetItemList;  // offset: 0x338
    public:
        static MyDTI DTI;
        static const u32 MAX_REQUEST_NUM = 10;
        static const u32 ITEM_CATEGORY_NUM = 7;
        static const u32 ItemCategoryTbl[7];
        static const u8 customSortPrioMaterial[8];
        static const u8 customSortPrioEquip[8];
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
    sItemManager();
    virtual ~sItemManager();
private:
    void setEquipToUpGrade();
public:
    static sItemManager* getInstance();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    void loadResource();
    void releaseResource();
    void releaseGame();
    void setItemBag(u32 TargetNo);
    void createItemSlot(u32 TargetNo);
    void releaseItemBag();
    cItemBag* setLinkItem(nCharacterData::ITEM_BAG_TYPE no);
    cItemBag* setLinkItem(nItem::E_STORAGE_TYPE no);
    bool canSellCategory(rItemList::ITEM_CATEGORY category);
    rItemList::rItemParam* getItemParam(u32 ItemNo) const;
    rItemList::rItemParam* getItemParamByIndex(u32 index);
    rItemList::rItemParam* getItemParamByAtcTagNo(u32 arcTagNo);
    bool isItemBagTypeToServer(nItem::E_STORAGE_TYPE type);
    nItem::E_STORAGE_TYPE getItemNetStorageType(nItem::E_STORAGE_TYPE group, rItemList::rItemParam* pParam);
    nItem::E_STORAGE_TYPE getItemNetStorageType(nCharacterData::ITEM_BAG_TYPE type, cItemBag::ITEM_CATEGORY category);
    nCharacterData::ITEM_BAG_TYPE getItemBagType(nItem::E_STORAGE_TYPE group);
    nCharacterData::ITEM_BAG_TYPE getItemBagTypeToServer(nItem::E_STORAGE_TYPE type);
    nItem::E_STORAGE_TYPE getItemBagGroupeType(nItem::E_STORAGE_TYPE type);
    nItem::E_STORAGE_TYPE getItemBagGroupeType(nCharacterData::ITEM_BAG_TYPE type);
    nItem::E_STORAGE_TYPE convStorageTypeToServer(nCharacterData::ITEM_BAG_TYPE storageType);
    void getServerStorageList(CommonU8Vec& storageList, nCharacterData::ITEM_BAG_TYPE type);
    u32 getItemListNum();
    u32 getItemIdToUID(MT_CTSTR UID, u32 targetNo);
    u32 getBagTypeToUID(MT_CTSTR UID, u32* pIndex);
    cShop* getActiveShop();
private:
    s32 getItemSysLogCallSub(CItemUpdateResult* pData);
public:
    void getItemSysLogCall(void* packet);
    void addGoldToServer(u32 addNum, u32 totalNum, u32 type, u32 extraNum, bool isLog);
    void subGoldToServer(u32 subNum, u32 totalNum, u32 type, bool isLog);
    void setGoldToServer(u32 totalNum, u32 type);
    void setGoldToServerDirect(u32 totalNum, u32 type);
    u64 getGold();
    u64 getRim();
    u64 getGp();
    u32 reqGetGP();
    void updateGP(void* packet);
    void setGpUseLimit(s64 useLimit);
    u64 getDogma();
    u64 getTicket();
    u64 getSupportPt();
    u64 getCpReset();
    void setGp(u64 Gp);
private:
    void setGold(u64 Gold);
    void setRim(u64 Rim);
    void setDogma(u64 Do);
    void setTicket(u64 Ticket);
    void setSupportPt(u64 Support);
    void setCpReset(u64 CpReset);
    u64 getPoint(nCharacter::E_WALLET_POINT_TYPE type);
    void setPoint(nCharacter::E_WALLET_POINT_TYPE type, u64 pointNum);
public:
    void setEquipItemSlotNum(u32);
    void setMyPawnSlotNum(u32);
    u32 getMyPawnSlotNum();
    void setJobEquip(nCharacterData::stEquipData& Data, u8 job);
    bool isEquip(u32 ItemNo);
    void getTargetItemSlotList(MtTypedArray<cItemParam>& list, u32 bagNo, u16 itemNo, SortType sortType);
    cChangeJob* getJobParam();
    bool isWeaponCategory(nCharacterData::EQUIP_CATEGORY category);
    bool isArmorCategory(nCharacterData::EQUIP_CATEGORY category);
    void setEquipToServer(void* packet, u32 type);
    void setEquipContext(cContextInstHm* pContext, const EquipItemInfoVec* pEquipList, bool calcEquip);
    void setEquipElementContext(cContextInstHm* pContext, const MtTypedArray<CDataEquipElementParam>* pElementList, u8 slotNo, u8 equipType, bool calcEquip);
    void setEquipColorContext(cContextInstHm* pContext, u8 colorNo, u8 slotNo, u8 equipType);
    void updateHideEquip(void* packet, u32 plType, u32 equipType);
    void reqKeyItemGetAnnounce(u32 ItemId);
    void callbackItemNotice(void* param);
    void resetWaitNotice(u8 type);
    void noticeItemUpdate(ItemUpdateResultVec& list);
    void loadItemNameGmd();
    rGUIMessage* getItemNameGmd() const;
    void releaseItemNameGmd();
    void loadItemInfoGmd();
    rGUIMessage* getItemInfoGmd() const;
    void releaseItemInfoGmd();
    void setEquipUpGradeToServer(void* packet, u32 type);
    void callbackItemResult(void* param);
    s32 getEquipItemNum(u32 charID, u8 charType);
    s32 getEquipItemToBagEmptySlotNum(nCharacterData::ITEM_BAG_TYPE targetBag, u32 charID, u8 charType);
    s32 getEquipItemToTotalBagEmptySlotNum(u32 charID, u8 charType);
    s32 createUseItemList(cItemBag* pBag, u32 itemId, u32 needNum, u32* pShortNum, bool isCountOnly);
    void releseRequestCommand();
    bool isEmptyItemAdd(nCharacterData::ITEM_BAG_TYPE type, MtTypedArray<cItemList>& list, MtTypedArray<cItemList>& retList);
    nCharacter::E_WALLET_POINT_TYPE isCurrency(u32 itemNo);
    stSortData* getSortData(u32 index);
    void sendSortData(bool isTimeOff);
    void sendSortDataOnce(u32 sortType, bool isTimeOff);
    u8 getSortBinaryIndex(nCharacterData::ITEM_BAG_TYPE bagType, cItemBag::ITEM_CATEGORY category);
    u8 getSortType(nCharacterData::ITEM_BAG_TYPE bagType, cItemBag::ITEM_CATEGORY category);
    void releaseSortBinary(u32 index, bool isUpdate);
    u32 getItemNumAllBag(STORAGE_FILLTER_TYPE type, u32 ItemId);
    cItemParam* getItemParamToEquipCharacter(u32 charID, u32 type, u32 itemID, u8 equipSlot);
    void setShopBuyLimit(u32 limit);
    u32 getShopBuyLimit();
    bool isUseBaggageStorage();
    void getFillterStorageList(STORAGE_FILLTER_TYPE type, CommonU32Vec& list);
    bool isInGameLimitBagType(nCharacterData::ITEM_BAG_TYPE type, LIMIT_TYPE limit);
    void releaseBag();
    void initSwitchStorage();
    void setSwitchStorage(bool isSwitch, nItem::E_STORAGE_TYPE target, nItem::E_STORAGE_TYPE change);
    bool isSwitchStorage();
    nItem::E_STORAGE_TYPE getSwitchTargetStorage();
    nItem::E_STORAGE_TYPE getSwitchChangeStorage();
    nCharacterData::ITEM_BAG_TYPE getSwitchStorageType(nItem::E_STORAGE_TYPE type);
    cItemBag* getEnableUseItemStorage();
    u32 getWalletItemToPoint(u32 itemId, u32 num, nCharacter::E_WALLET_POINT_TYPE& walletType);
    void settingJewelryEquipLimit(const MtTypedArray<CDataJewelryEquipLimit>& list);
    u8 getJewelryEquipLimit(rItemList::rItemParam::EQUIP_SUB_CATEGORY category);
private:
    void initJewelryEquipLimit();
    bool getItemListFunc(stRequest* pReq);
    GET_LIST_RESULT getItemListCore(stRequest* pReq, u32 targetNo);
    bool moveItemsFunc(stRequest* pReq);
    bool checkItemFunc(stRequest* pReq);
    bool useItemFunc(stRequest* pReq);
    bool useItemsFunc(stRequest* pReq);
    bool deleteItemFunc(stRequest* pReq);
    bool slotControlItemFunc(stRequest* pReq);
    bool addGatheringItemsFunc(stRequest* pReq);
    bool addDropItemsFunc(stRequest* pReq);
    bool addPawnExpeditionRewardDropsFunc(stRequest* pReq);
    bool deliverItemFunc(stRequest* pReq);
    bool getRewardBoxItemFunc(stRequest* pReq);
    bool startCraftFunc(stRequest* pReq);
    bool getCraftItemFunc(stRequest* pReq);
    bool startCraftUpGradeFunc(stRequest* pReq);
    bool startCraftElementAttachFunc(stRequest* pReq);
    bool startCraftElementDetachFunc(stRequest* pReq);
    bool startCraftColorChangeFunc(stRequest* pReq);
    bool urocoHPLevelUpFunc(stRequest* pReq);
    bool urocoStaminaLevelUpFunc(stRequest* pReq);
    bool urocoLostTimerLevelUpFunc(stRequest* pReq);
    bool getShopListFunc(stRequest* pReq);
    bool getGoodsListFunc(stRequest* pReq);
    bool buyGoodsFunc(stRequest* pReq);
    bool sellItemFunc(stRequest* pReq);
    bool setEquipFunc(stRequest* pReq);
    bool updateHideEquipFunc(stRequest* pReq);
    bool changeJobFunc(stRequest* pReq);
    bool getAreaMasterSupplyFunc(stRequest* pReq);
    bool noticeItemListFunc(stRequest* pReq);
    void callMethod();
    cEquipList* createEquipList();
    void deleteEquipList(cEquipList* pList);
    MT_CTSTR getUpGradeItemUID();
    u32 getUpGradeItemInBag();
    u32 getUpGradeItemToPawnId();
    u8 getUpGradeItemToCharType();
    void setSortBinary(nCharacterData::ITEM_BAG_TYPE bagType, cItemBag::ITEM_CATEGORY category, u8 sortType, MtTypedArray<cItemParam>& list, bool isOverWrite);
public:
    TICKET mShopArcTicket;  // offset: 0x18
    cShop* mActiveShop;  // offset: 0x20
private:
    JewelryEquipLimit mJewelryEquipLimit[4];  // offset: 0x28
    MtTypedArray<stRequest> mRequest;  // offset: 0x30
    MtTypedArray<cItemBag> mBag;  // offset: 0x50
    u64 mPoint[9];  // offset: 0x70
    rItemList* mpItemParamList;  // offset: 0xb8
    MtTypedArray<cEquipList> mEquipList;  // offset: 0xc0
    u32 mEquipItemSlotNum;  // offset: 0xe0
    u32 mMyPawnSlotNum;  // offset: 0xe4
    MtString mUpGradeItemUID;  // offset: 0xe8
    u32 mUpGradeItemInBag;  // offset: 0xf0
    u32 mUpGradeItemToPawnId;  // offset: 0xf4
    u8 mUpGradeItemToCharType;  // offset: 0xf8
    cChangeJob mJobParam;  // offset: 0x100
    MoveItemUIDFromToVec mSlotControlList;  // offset: 0x118
    rGUIMessage* mprItemNameGmd;  // offset: 0x138
    rGUIMessage* mprItemInfoGmd;  // offset: 0x140
    cGPDetail mGPControl;  // offset: 0x148
    ItemUIDListVec mUseItemList[10];  // offset: 0x170
    stSortData mSortData[12];  // offset: 0x2b0
    u32 mShopBuyLimit;  // offset: 0x3d0
    cSwitchStorage mSwitchStorage;  // offset: 0x3d4
public:
    static MyDTI DTI;
    static const u32 ShopBuyLimit = 999;
    static const u32 MAX_STOCK_METHOD = 10;
    static const stJobEquipData equip_tbl[10];
    static const u32 SORT_SAVE_BUFF_SIZE = 1024;
private:
    static sItemManager* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sItemManager* sItemManager::getInstance() {
    return ::sItemManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sItemManager::cItemBag::cGetItemListData::cGetItemListData() {
    this->mStorageType = static_cast<u8>(0);
    this->mCharType = static_cast<u8>(0);
    this->mColor = static_cast<u8>(0);
    this->mEquipPoint = static_cast<u32>(0);
    this->mSlotType = static_cast<u32>(0);
    this->mSlotNo = static_cast<u32>(0);
    this->mEquipCharcaterId = static_cast<u32>(0);
    this->mEquipPawnId = static_cast<u32>(0);
    this->mItemId = static_cast<u32>(0);
    this->mItemNum = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sItemManager::cItemBag::cGatheringItemData::cGatheringItemData() {
    this->mLayerNo = static_cast<u32>(0);
    this->mPosId = static_cast<u32>(0);
    this->mStageId = static_cast<u32>(0);
    this->mGroupId = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sItemManager::cItemBag::cAreaMasterSuppyData::cAreaMasterSuppyData() {
    this->mAreaID = static_cast<u32>(0);
    this->mIsCancel = false;
}

// Inline, no code of its own: checked where it is inlined.
inline sItemManager::cSortParam::cSortParam() {
    this->mSortType = static_cast<u8>(0);
    this->mSortDir = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sItemManager::cItemParamList::cItemParamList() {
    this->mpItemParam = static_cast<cItemParam*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline sItemManager::cEquipList::cEquipData::cEquipData() {
    this->mCategory = static_cast<u32>(16);
    this->mpItemParam = static_cast<cItemParam*>(nullptr);
    this->mTargetNo = static_cast<u32>(0);
    this->mIsNone = false;
}

// Inline, no code of its own: checked where it is inlined.
inline sItemManager::cChangeJob::cChangeJob() {
    this->mPawnId = static_cast<u32>(0);
    this->mJob = static_cast<u8>(255);
    this->mpPacket = static_cast<void*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline sItemManager::cHideEquip::cHideEquip() {
    this->mPlType = static_cast<u8>(0);
    this->mEquipType = static_cast<u8>(0);
    this->mIsHideOff = false;
}

// Inline, no code of its own: checked where it is inlined.
inline sItemManager::cItemList::cItemList() {
    this->mItemNo = static_cast<u32>(0);
    this->mItemNum = static_cast<u32>(0);
}
