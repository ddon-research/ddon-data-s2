#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/Character.h"
#include "Protocol/PacketData/Common.h"
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cSystem.h"
#include "rItemList.h"

// Forward declarations
class CDataCommonU32;
class CDataItemStorageIndicateNum;
class CDataItemUIDList;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;

// Declarations
class sBazaarManager;

// Type aliases from DWARF
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using ItemStorageIndicateNumVec = MtTypedArray<CDataItemStorageIndicateNum>;
using ItemUIDListVec = MtTypedArray<CDataItemUIDList>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class sBazaarManager : public cSystem
{
public:
    enum
    {
        GET_BAZAAR_EXHIBIT_POSSIBLE_NUM_RESULT_NONE = 0,
        GET_BAZAAR_EXHIBIT_POSSIBLE_NUM_RESULT_WAIT = 1,
        GET_BAZAAR_EXHIBIT_POSSIBLE_NUM_RESULT_SUCCESS = 2,
        GET_BAZAAR_EXHIBIT_POSSIBLE_NUM_RESULT_ERROR = 3,
    };
    enum
    {
        CHARACTER_LIST_TASK_RNO_WAIT = 0,
        CHARACTER_LIST_TASK_RNO_EXHIBIT_POSSIBLE_REQ = 1,
        CHARACTER_LIST_TASK_RNO_EXHIBIT_POSSIBLE_WAIT = 2,
        CHARACTER_LIST_TASK_RNO_REQ = 3,
        CHARACTER_LIST_TASK_RNO_REQ_WAIT = 4,
        CHARACTER_LIST_TASK_RNO_ERROR = 5,
        CHARACTER_LIST_TASK_RNO_FINISH = 6,
    };
    enum
    {
        GET_ANEXHIBIT_ITEM_REQ_RESULT_NONE = 0,
        GET_ANEXHIBIT_ITEM_REQ_RESULT_WAIT = 1,
        GET_ANEXHIBIT_ITEM_REQ_RESULT_SUCCESS = 2,
        GET_ANEXHIBIT_ITEM_REQ_RESULT_ERROR = 3,
    };
    enum
    {
        GET_ANEXHIBIT_ITEM_INFO_REQ_RESULT_NONE = 0,
        GET_ANEXHIBIT_ITEM_INFO_REQ_RESULT_WAIT = 1,
        GET_ANEXHIBIT_ITEM_INFO_REQ_RESULT_SUCCESS = 2,
        GET_ANEXHIBIT_ITEM_INFO_REQ_RESULT_ERROR = 3,
    };
    enum
    {
        GET_ANEXHIBIT_ITEM_HISTORY_REQ_RESULT_NONE = 0,
        GET_ANEXHIBIT_ITEM_HISTORY_REQ_RESULT_WAIT = 1,
        GET_ANEXHIBIT_ITEM_HISTORY_REQ_RESULT_SUCCESS = 2,
        GET_ANEXHIBIT_ITEM_HISTORY_REQ_RESULT_ERROR = 3,
    };
    enum
    {
        GET_ANEXHIBIT_ITEM_PROCEEDS_REQ_RESULT_NONE = 0,
        GET_ANEXHIBIT_ITEM_PROCEEDS_REQ_RESULT_WAIT = 1,
        GET_ANEXHIBIT_ITEM_PROCEEDS_REQ_RESULT_SUCCESS = 2,
        GET_ANEXHIBIT_ITEM_PROCEEDS_REQ_RESULT_ERROR = 3,
    };
    enum
    {
        GET_PRIM_LIMIT_RESULT_NONE = 0,
        GET_PRIM_LIMIT_RESULT_WAIT = 1,
        GET_PRIM_LIMIT_RESULT_SUCCESS = 2,
        GET_PRIM_LIMIT_RESULT_ERROR = 3,
    };
    enum
    {
        START_EXHIBIT_RESULT_NONE = 0,
        START_EXHIBIT_RESULT_WAIT = 1,
        START_EXHIBIT_RESULT_SUCCESS = 2,
        START_EXHIBIT_RESULT_ERROR = 3,
    };
    enum
    {
        CANCEL_EXHIBIT_RESULT_NONE = 0,
        CANCEL_EXHIBIT_RESULT_WAIT = 1,
        CANCEL_EXHIBIT_RESULT_SUCCESS = 2,
        CANCEL_EXHIBIT_RESULT_ERROR = 3,
    };
    enum
    {
        GET_BAZAAR_PROCEEDS_RESULT_NONE = 0,
        GET_BAZAAR_PROCEEDS_RESULT_WAIT = 1,
        GET_BAZAAR_PROCEEDS_RESULT_SUCCESS = 2,
        GET_BAZAAR_PROCEEDS_RESULT_ERROR = 3,
        GET_BAZAAR_PROCEEDS_RESULT_FINISH = 4,
    };
    enum
    {
        RESTART_EXHIBIT_RESULT_NONE = 0,
        RESTART_EXHIBIT_RESULT_WAIT = 1,
        RESTART_EXHIBIT_RESULT_SUCCESS = 2,
        RESTART_EXHIBIT_RESULT_ERROR = 3,
    };
public:
    class MyDTI;
    class cBazaarCharListCtrl;
    class cBazaarCharListData;
    class cBazaarProceedsCtrl;
    class cBazaarItemListCtrl;
    class cBazaarItemListData;
    class cBazaarItemInfoCtrl;
    class cBazaarItemInfoData;
    class cBazaarItemHistoryData;
    class cBazaarItemPrimLimit;
    class cBazaarExhibitItemCtrl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cBazaarCharListData : public MtObject
    {
    public:
        enum
        {
            STATE_ERROR = 0,
            STATE_NONE = 1,
            STATE_EXHIBIT = 2,
            STATE_TIMEOVER = 3,
            STATE_PROCEEDS = 4,
            STATE_LOCK = 5,
        };
        enum
        {
            COLOR_TYPE_NORMAL = 0,
            COLOR_TYPE_NEAR_TIME = 1,
            COLOR_TYPE_TIMEOVER = 2,
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
        cBazaarCharListData();
        virtual ~cBazaarCharListData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setState(u8 state);
        u8 getState();
        void setItemId(u32 id);
        u32 getItemId();
        void setNum(u16 num);
        u16 getNum();
        void setPrice(u32 price);
        u32 getPrice();
        void setTime(s64 time);
        s64 getTime();
        void setProceeds(u32 num);
        s64 getProceeds();
        void setBazaarId(u64 id);
        u64 getBazaarId();
        void setCharId(u64);
        u64 getCharId();
        void setSequence(u16 seq);
        u16 getSequence();
        void calcElapsedTime();
        MT_CTSTR getElapsedTimeStr();
        u8 getColorType();
        void setItemParam(rItemList::rItemParam* prItemParam);
        rItemList::rItemParam* getItemParam();
    private:
        u8 mState;  // offset: 0x8
        u32 mItemId;  // offset: 0xc
        u16 mNum;  // offset: 0x10
        u32 mPrice;  // offset: 0x14
        s64 mTime;  // offset: 0x18
        u32 mProceeds;  // offset: 0x20
        u64 mBazaarId;  // offset: 0x28
        u64 mCharId;  // offset: 0x30
        u16 mSequence;  // offset: 0x38
        MtString mElapsedTimeStr;  // offset: 0x40
        u8 mElapsedTimeCol;  // offset: 0x48
        rItemList::rItemParam* mpItemParam;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
public:
    class cBazaarProceedsCtrl : public MtObject
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
        cBazaarProceedsCtrl();
        virtual ~cBazaarProceedsCtrl();
        void init();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setProceeds(u32 num);
        u32 getProceeds();
    private:
        u32 mProceeds;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class cBazaarItemListData : public MtObject
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
        cBazaarItemListData();
        virtual ~cBazaarItemListData() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setItemId(u32 itemId);
        u32 getItemId();
        void setItemParam(rItemList::rItemParam* pParam);
        rItemList::rItemParam* getItemParam();
        void setEventNum(u16 num);
        u16 getEventNum();
    private:
        u32 mItemId;  // offset: 0x8
        rItemList::rItemParam* mpItemParam;  // offset: 0x10
        u16 mEventNum;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
public:
    class cBazaarItemInfoData : public MtObject
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
        cBazaarItemInfoData();
        virtual ~cBazaarItemInfoData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setItemId(u32 itemId);
        u32 getItemId();
        void setItemParam(rItemList::rItemParam* pParam);
        rItemList::rItemParam* getItemParam();
        void setBazaarId(u64 bazaarId);
        u64 getBazaarId();
        void setSequence(u16 seq);
        u16 getSequence();
        void setNum(u16 num);
        u16 getNum();
        void setPrice(u32 price);
        u32 getPrice();
        void setTime(s64 time);
        s64 getTime();
        MT_CTSTR getExhibitTimeStr();
    private:
        u32 mItemId;  // offset: 0x8
        rItemList::rItemParam* mpItemParam;  // offset: 0x10
        u64 mBazaarId;  // offset: 0x18
        u16 mSequence;  // offset: 0x20
        u16 mNum;  // offset: 0x22
        u32 mPrice;  // offset: 0x24
        s64 mTime;  // offset: 0x28
        MtString mExhibitTimeStr;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
public:
    class cBazaarItemHistoryData : public MtObject
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
        cBazaarItemHistoryData();
        virtual ~cBazaarItemHistoryData() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setItemId(u32 itemId);
        u32 getItemId();
        void setItemParam(rItemList::rItemParam* pParam);
        rItemList::rItemParam* getItemParam();
        void setNum(u16 num);
        u16 getNum();
        void setPrice(u32 price);
        u32 getPrice();
        void setCreated(s64 created);
        s64 getCreated();
    private:
        u32 mItemId;  // offset: 0x8
        rItemList::rItemParam* mpItemParam;  // offset: 0x10
        u16 mNum;  // offset: 0x18
        u32 mPrice;  // offset: 0x1c
        s64 mCreated;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    class cBazaarItemPrimLimit : public MtObject
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
        cBazaarItemPrimLimit();
        virtual ~cBazaarItemPrimLimit() {}
        void init();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setItemId(u32 itemId);
        u32 getItemId();
        void setLow(u32 low);
        u32 getLow();
        void setHigh(u32 high);
        u32 getHigh();
        void setNumLimit(u32 num);
        u32 getNumLimit();
    private:
        u32 getItemIdPrivate() const;
        void setItemIdPrivate(u32 NewValue);
        u32 getLowPrivate() const;
        void setLowPrivate(u32 NewValue);
        u32 getHighPrivate() const;
        void setHighPrivate(u32 NewValue);
    private:
        u32 mItemId_pri;  // offset: 0x8
        u32 mLow_pri;  // offset: 0xc
        u32 mHigh_pri;  // offset: 0x10
        u32 mNumLimit;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
public:
    class cBazaarExhibitItemCtrl : public MtObject
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
        cBazaarExhibitItemCtrl();
        virtual ~cBazaarExhibitItemCtrl() {}
        void init();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setBazaarId(u64 bazaarId);
        u64 getBazaarId();
        void setResult(s32 result);
        s32 getResult();
        void setErrorType(u16 errorType);
        u16 getErrorType();
        void setItemId(u32 itemId);
        u32 getItemId();
    private:
        u64 mBazaarId;  // offset: 0x8
        s32 mResult;  // offset: 0x10
        u16 mErrorType;  // offset: 0x14
        u32 mItemId;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
public:
    class cBazaarCharListCtrl : public MtObject
    {
        friend class sBazaarManager;
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
        cBazaarCharListCtrl();
        virtual ~cBazaarCharListCtrl();
        void init();
        void finish();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        sBazaarManager::cBazaarCharListData* getBazaarCharListData(u32 index);
        void setSelectNo(s32 index);
        s32 getSelectNo();
        u32 getItemSlot();
        u32 getUseSlot();
        void addUpdateCnt();
        bool isUpdate();
        void setPossibleNum(u32 num);
        u32 getPossibleNum() const;
        void setPossibleAddNum(u32 num);
        u32 getPossibleAddNum() const;
    public:
        MtTypedArray<sBazaarManager::cBazaarCharListData> mData;  // offset: 0x8
    private:
        s32 mSelectNo;  // offset: 0x28
        u32 mUpdateCnt;  // offset: 0x2c
        u32 mUpdateCntOld;  // offset: 0x30
        u32 mPossibleNum;  // offset: 0x34
        u32 mAddNum;  // offset: 0x38
    public:
        static MyDTI DTI;
        static const u32 DATA_MAX = 5;
    };
public:
    class cBazaarItemListCtrl : public MtObject
    {
        friend class sBazaarManager;
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
        cBazaarItemListCtrl();
        virtual ~cBazaarItemListCtrl();
        void init();
        void finish();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setSelectNo(s32 index);
        s32 getSelectNo();
        u32 getListNum();
        u32 getItemNo();
    public:
        MtTypedArray<sBazaarManager::cBazaarItemListData> mItemList;  // offset: 0x8
    private:
        s32 mSelectNo;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
public:
    class cBazaarItemInfoCtrl : public MtObject
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
        cBazaarItemInfoCtrl();
        virtual ~cBazaarItemInfoCtrl();
        void init();
        void finish();
        void initHistory();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setItemId(u32 itemId);
        u32 getItemId();
        void setItemParam(rItemList::rItemParam* pParam);
        rItemList::rItemParam* getItemParam();
        void setSelectNo(s32 selectNo);
        s32 getSelectNo();
        void setProceedsResult(s32 result);
        s32 getProceedsResult();
    public:
        MtTypedArray<sBazaarManager::cBazaarItemInfoData> mItemInfo;  // offset: 0x8
        MtTypedArray<sBazaarManager::cBazaarItemHistoryData> mItemHistory;  // offset: 0x28
    private:
        u32 mItemId;  // offset: 0x48
        rItemList::rItemParam* mpItemParam;  // offset: 0x50
        s32 mSelectNo;  // offset: 0x58
        s32 mProceedsResult;  // offset: 0x5c
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
    static sBazaarManager* getInstance();
    sBazaarManager();
    virtual ~sBazaarManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    void startBazaar();
    void finishBazaar();
    bool reqBazaarExhibitPossibleNum();
    void moveBazaarExhibitPossibleNum();
    void setBazaarExhibitPossibleNumToServer(void* packet);
    u8 getResultBazaarExhibitPossibleNum();
    void reqBazaarCharList();
    void moveBazaarCharList();
    void setBazaarCharListToServer(void* packet);
    u8 getResultBazaarCharList();
    bool reqGetBazaarProceeds();
    void moveGetBazaarProceeds();
    void setBazaarProceedsToServer(void* packet);
    u32 getResultGetBazaarProceeds();
    bool createExhibitItemList(MT_CTSTR UID, u32 num);
    void eraseExhibitItemList(MT_CTSTR UID);
    void clearExhibitItemList();
    bool createAnExhibitItemList(u32 itemId);
    void eraseAnExhibitItemList(u32 itemId);
    void clearAnExhibitItemList();
    u32 getAnExhibitItemListNum();
    bool reqGetAnExhibitItemList();
    void moveGetAnExhibitItemList();
    void setBazaarGetAnExhibitItemListToServer(void* packet);
    u8 getResultGetAnExhibitItem();
    bool reqGetAnExhibitItemInfo(u32 itemId);
    void moveGetAnExhibitItemInfo();
    void setBazaarGetAnExhibitItemInfoToServer(void* packet);
    u32 getResultAnExhibitItemInfo();
    bool reqGetAnExhibitItemHistory(u32 itemId);
    void moveGetAnExhibitItemHistory();
    void setBazaarGetAnExhibitItemHistoryToServer(void* packet);
    u32 getGetAnExhibitItemHistoryReqResult();
    bool createAnExhibitItemProceedsList(u32 itemNum, u8 storageType);
    bool changeAnExhibitItemProceedsList(u32 itemNum, u8 storageType);
    void clearAnExhibitItemProceedsList();
    bool checkAnExhibitItemProceedsList();
    bool reqGetAnExhibitItemProceeds();
    void moveGetAnExhibitItemProceeds();
    void setBazaarGetAnExhibitItemProceedsToServer(void* packet);
    u32 getAnExhibitItemProceedsReqResult();
    bool reqGetPrimLimit(u32 itemId);
    void moveGetPrimLimit();
    void setBazaarGetPrimLimitToServer(void* packet);
    u8 getResultPriceLimit();
    bool reqStartExhibitItem();
    void moveExhibitItem();
    void setBazaarExhibitItemToServer(void* packet);
    u8 getResultStartExhibit();
    void setExhibitItemPrice(u32 price);
    u32 getExhibitItemPrice();
    bool reqReStartExhibitItem();
    void moveReExhibitItem();
    void setBazaarReExhibitItemToServer(void* packet);
    u8 getResultReStartExhibit();
    bool reqCancelExhibitItem();
    void moveCancelExhibitItem();
    void setBazaarCancelExhibitItemToServer(void* packet);
    u32 getResultCancelExhibitItem();
    cBazaarCharListCtrl* getBazaarCharListCtrl();
    cBazaarProceedsCtrl* getBazaarProceedsCtrl();
    cBazaarItemListCtrl* getBazaarItemListCtrl();
    cBazaarItemInfoCtrl* getBazaarItemInfoCtrl();
    cBazaarItemPrimLimit* getBazaarItemPrimLimitCtrl();
    cBazaarExhibitItemCtrl* getBazaarExhibitItemCtrl();
    void setBagType(u32 type);
    void SetBazzarSearchSuccessionTime(u32 time);
    u32 GetBazzarSearchSuccessionTime();
    void SetBazzarSearchSuccessionCount(u32 count);
    u32 GetBazzarSearchSuccessionCount();
    void SetBazzarSearchSuccessionCautionTime(u32 time);
    u32 GetBazzarSearchSuccessionCautionTime();
private:
    u32 mBazaarCharListTaskRno;  // offset: 0x14
    u32 mGetBazaarProceedsReqResult;  // offset: 0x18
    cBazaarCharListCtrl mCharInfoCtrl;  // offset: 0x20
    cBazaarProceedsCtrl mProceedsCtrl;  // offset: 0x60
    cBazaarItemListCtrl mItemListCtrl;  // offset: 0x70
    cBazaarItemInfoCtrl mItemInfoCtrl;  // offset: 0xa0
    cBazaarItemPrimLimit mItemPrimCtrl;  // offset: 0x100
    cBazaarExhibitItemCtrl mExhibitItemCtrl;  // offset: 0x118
    u32 mBagType;  // offset: 0x138
    u32 mExhibitItemPrice;  // offset: 0x13c
    ItemUIDListVec mExhibitItemList;  // offset: 0x140
    CommonU32Vec mGetAnExhibitItemList;  // offset: 0x160
    ItemStorageIndicateNumVec mPurchaseItemList;  // offset: 0x180
    u16 mPurchaseItemNum;  // offset: 0x1a0
    u8 mPurchaseItemStorage;  // offset: 0x1a2
    u32 mGetExhibitPossibleNumResult;  // offset: 0x1a4
    u32 mGetAnExhibitItemReqResult;  // offset: 0x1a8
    u32 mGetAnExhibitItemInfoReqResult;  // offset: 0x1ac
    u32 mGetAnExhibitItemHistoryReqResult;  // offset: 0x1b0
    u32 mGetAnExhibitItemProceedsReqResult;  // offset: 0x1b4
    u32 mGetPrimLimitReqResult;  // offset: 0x1b8
    u32 mStartExhibitReqResult;  // offset: 0x1bc
    u32 mReStartExhibitReqResult;  // offset: 0x1c0
    u32 mCancelExhibitReqResult;  // offset: 0x1c4
    u32 mBazzarSearchSuccessionTime;  // offset: 0x1c8
    u32 mBazzarSearchSuccessionCount;  // offset: 0x1cc
    u32 mBazzarSearchSuccessionCautionTime;  // offset: 0x1d0
public:
    static MyDTI DTI;
    static const u64 mBazaarCanUseTime;
private:
    static sBazaarManager* mpInstance;
};

inline sBazaarManager* sBazaarManager::getInstance() {
    return ::sBazaarManager::mpInstance;
}

inline u32 sBazaarManager::getResultGetBazaarProceeds() {
    return this->mGetBazaarProceedsReqResult;
}

inline u32 sBazaarManager::getResultAnExhibitItemInfo() {
    return this->mGetAnExhibitItemInfoReqResult;
}

inline u32 sBazaarManager::getGetAnExhibitItemHistoryReqResult() {
    return this->mGetAnExhibitItemHistoryReqResult;
}

inline u32 sBazaarManager::getAnExhibitItemProceedsReqResult() {
    return this->mGetAnExhibitItemProceedsReqResult;
}

inline u32 sBazaarManager::getResultCancelExhibitItem() {
    return this->mCancelExhibitReqResult;
}

inline sBazaarManager::cBazaarCharListCtrl* sBazaarManager::getBazaarCharListCtrl() {
    return &this->mCharInfoCtrl;
}

inline sBazaarManager::cBazaarItemInfoCtrl* sBazaarManager::getBazaarItemInfoCtrl() {
    return &this->mItemInfoCtrl;
}

inline void sBazaarManager::SetBazzarSearchSuccessionTime(u32 time) {
    this->mBazzarSearchSuccessionTime = time;
}

inline void sBazaarManager::SetBazzarSearchSuccessionCount(u32 count) {
    this->mBazzarSearchSuccessionCount = count;
}

inline u32 sBazaarManager::GetBazzarSearchSuccessionCount() {
    return this->mBazzarSearchSuccessionCount;
}

inline void sBazaarManager::SetBazzarSearchSuccessionCautionTime(u32 time) {
    this->mBazzarSearchSuccessionCautionTime = time;
}

inline sBazaarManager::cBazaarCharListCtrl::cBazaarCharListCtrl() {
    this->mData.::MtArray::mAutoDelete = true;
    this->mSelectNo = -1;
    this->mPossibleNum = 0;
    this->mAddNum = 0;
    this->mUpdateCnt = 0;
    this->mUpdateCntOld = 0;
}

inline sBazaarManager::cBazaarCharListData::cBazaarCharListData() {
    this->mState = 0;
    this->mItemId = 0;
    this->mNum = 0;
    this->mpItemParam = nullptr;
    this->mElapsedTimeCol = 0;
    this->mPrice = 0;
    this->mTime = 0;
    this->mProceeds = 0;
    this->mSequence = 0;
    this->mCharId = 0;
    this->mBazaarId = 0;
}

inline u32 sBazaarManager::cBazaarCharListData::getItemId() {
    return this->mItemId;
}

inline s64 sBazaarManager::cBazaarCharListData::getTime() {
    return this->mTime;
}

inline u64 sBazaarManager::cBazaarCharListData::getBazaarId() {
    return this->mBazaarId;
}

inline sBazaarManager::cBazaarProceedsCtrl::cBazaarProceedsCtrl() {
    this->mProceeds = 0;
}

inline sBazaarManager::cBazaarItemListCtrl::cBazaarItemListCtrl() {
    this->mItemList.::MtArray::mAutoDelete = true;
    this->mSelectNo = -1;
}

inline sBazaarManager::cBazaarItemListData::cBazaarItemListData() {
    this->mItemId = 0;
    this->mEventNum = 0;
    this->mpItemParam = nullptr;
}

inline u32 sBazaarManager::cBazaarItemListData::getItemId() {
    return this->mItemId;
}

inline void sBazaarManager::cBazaarItemListData::setEventNum(u16 num) {
    this->mEventNum = num;
}

inline sBazaarManager::cBazaarItemInfoCtrl::cBazaarItemInfoCtrl() {
    this->mItemInfo.::MtArray::mAutoDelete = true;
    this->mItemHistory.::MtArray::mAutoDelete = true;
    this->mItemId = 0;
    this->mpItemParam = nullptr;
    this->mSelectNo = -1;
    this->mProceedsResult = -1;
}

inline sBazaarManager::cBazaarItemInfoData::cBazaarItemInfoData() {
    this->mItemId = 0;
    this->mTime = 0;
    this->mSequence = 0;
    this->mNum = 0;
    this->mPrice = 0;
    this->mBazaarId = 0;
    this->mpItemParam = nullptr;
}

inline sBazaarManager::cBazaarItemHistoryData::cBazaarItemHistoryData() {
    this->mItemId = 0;
    this->mpItemParam = nullptr;
    this->mNum = 0;
    this->mPrice = 0;
    this->mCreated = 0;
}

inline sBazaarManager::cBazaarItemPrimLimit::cBazaarItemPrimLimit() {
    this->mHigh_pri = 0;
    this->mNumLimit = 0;
    this->mItemId_pri = 0;
    this->mLow_pri = 0;
}

inline sBazaarManager::cBazaarExhibitItemCtrl::cBazaarExhibitItemCtrl() {
    this->mBazaarId = 0;
    this->mResult = 0;
    this->mErrorType = 0;
    this->mItemId = 0;
}
