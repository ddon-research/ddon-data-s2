#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtAllocator.h"
#include "MtDTI.h"
#include "MtSynchronize.h"

// Forward declarations
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;

// Declarations
class MtScalableAllocator;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class MtScalableAllocator : public MtAllocator
{
public:
    enum ManagerIndex
    {
        MANAGER_0 = 0,
        MANAGER_1 = 1,
        MANAGER_2 = 2,
        MANAGER_3 = 3,
        MANAGER_4 = 4,
        MANAGER_5 = 5,
        MANAGER_6 = 6,
        MANAGER_7 = 7,
        MANAGER_MAX = 8,
    };
    enum AllocPoolType
    {
        ALLOC_POOL_NONE = 0,
        ALLOC_POOL_4KB = 1,
        ALLOC_POOL_8KB = 2,
        ALLOC_POOL_16KB = 3,
        ALLOC_POOL_32KB = 4,
        ALLOC_POOL_48KB = 5,
        ALLOC_POOL_64KB = 6,
        ALLOC_POOL_96KB = 7,
        ALLOC_POOL_128KB = 8,
        ALLOC_POOL_UNKNOWN = -1,
    };
    enum eNodeFlag
    {
        POOL = 0,
        NODE = 1,
        SYS = 2,
    };
    enum MB_TYPE
    {
        MB_USED = 0,
        MB_FREE = 1,
        MB_SYSTEM = 2,
        MB_POOL_L = 3,
        MB_POOL_G = 4,
    };
    enum ScalableAllocatorAttr
    {
        ATTR_DEV_ZERO_SIZE_ASSERT = 512,
        ATTR_DEV_ENABLE_TERM = 1024,
        ATTR_DEV_STACKWALK_4 = 2048,
        ATTR_DEV_STACKWALK_8 = 4096,
        ATTR_DEV_STACKWALK_16 = 6144,
        ATTR_DEV_STACKWALK_MASK = 6144,
        ATTR_DEV_VALIDATE_MEM = 8192,
        ATTR_DEV_CHECK_OVERRUN = 16384,
        ATTR_DEV_FAIL_ASSERT = 32768,
    };
public:
    class MyDTI;
    struct CTRLLIST;
    struct CTRL;
    struct MGR;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct CTRLLIST
    {
    public:
        CTRLLIST();
        void addHead(MtScalableAllocator::CTRL* p_ctrl);
        void addTail(MtScalableAllocator::CTRL* p_ctrl);
        void addSort(MtScalableAllocator::CTRL* p_ctrl);
        u32 remove(MtScalableAllocator::CTRL* p_ctrl);
    public:
        MtScalableAllocator::CTRL* p_head;  // offset: 0x0
        MtScalableAllocator::CTRL* p_tail;  // offset: 0x8
        u32 el_num;  // offset: 0x10
        u32 block_available;  // offset: 0x14
    };
public:
    struct CTRL
    {
    public:
        CTRL();
        void init(u32 id);
        void setWPrev(MtScalableAllocator::CTRL* p_ctrl);
        MtScalableAllocator::CTRL* getWPrev() const;
        void setWNext(MtScalableAllocator::CTRL* p_ctrl);
        MtScalableAllocator::CTRL* getWNext() const;
        void setBPrev(MtScalableAllocator::CTRL* p_ctrl);
        MtScalableAllocator::CTRL* getBPrev() const;
        void setBNext(MtScalableAllocator::CTRL* p_ctrl);
        MtScalableAllocator::CTRL* getBNext() const;
        MtScalableAllocator::CTRL* getSBlock() const;
        void setSBlock(MtScalableAllocator::CTRL* p_ctrl);
    public:
        u16 dev_magic;  // offset: 0x0
        u16 dev_mark : 8;  // offset: 0x2
        u16 dev_dbgdata : 7;  // offset: 0x2
        u16 dev_termpnt : 1;  // offset: 0x2
        MtScalableAllocator::CTRL* p_sblock;  // offset: 0x8
        u32 sblock_ctr;  // offset: 0x10
        u32 user_tag;  // offset: 0x14
        MtScalableAllocator::CTRL* p_wprev;  // offset: 0x18
        MtScalableAllocator::CTRL* p_wnext;  // offset: 0x20
        MtScalableAllocator::CTRL* p_bnext;  // offset: 0x28
        MtScalableAllocator::CTRL* p_bprev;  // offset: 0x30
        union
        {
        public:
            struct
            {
            public:
                u32 used : 1;  // offset: 0x0
                u32 used_block : 31;  // offset: 0x0
                u32 flag : 2;  // offset: 0x4
                u32 mgr_id : 5;  // offset: 0x4
                u32 call_no : 19;  // offset: 0x4
                u32 alloc_id : 6;  // offset: 0x4
            };  // offset: 0x0
            u64 tag;  // offset: 0x0
        };  // offset: 0x38
        size_t size;  // offset: 0x40
        size_t do_not_use;  // offset: 0x48
    };
public:
    struct MGR
    {
    public:
        MGR();
        void init(u32 mgr_id);
    public:
        MT_CHAR name[64];  // offset: 0x0
        MtScalableAllocator::CTRLLIST used;  // offset: 0x40
        MtScalableAllocator::CTRLLIST blank;  // offset: 0x58
        u32 id;  // offset: 0x70
        u32 curr_call_no;  // offset: 0x74
        size_t used_size;  // offset: 0x78
        MtCriticalSection cs;  // offset: 0x80
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
    virtual ~MtScalableAllocator();
    virtual void initializeAllocator(MT_CTSTR name, MtAllocator::TYPE type, size_t size, u16 attr);  // vtable slot 6
    virtual void initializeAllocator(MT_CTSTR name, MtAllocator::TYPE type, size_t size, u16 attr, u32 sa_type, u32 n_mgr);  // vtable slot 16
    virtual void initializeAllocator(MT_CTSTR name, void* p_mem, size_t size, u16 attr, u32 sa_type, u32 n_mgr);  // vtable slot 17
    static MtScalableAllocator* createAllocator(MT_CTSTR, MtAllocator::TYPE, size_t, u16);
    static MtScalableAllocator* createAllocator(MT_CTSTR name, MtAllocator::TYPE type, size_t size, u16 attr, u32 sa_type, u32 n_mgr);
    static MtScalableAllocator* createAllocator(MT_CTSTR name, void* p_mem, size_t size, u16 attr, u32 sa_type, u32 n_mgr);
    static u32 getAllocPoolType(MT_CTSTR str);
    static u16 getAllocatorAttr(MT_CTSTR str);
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void* memAlloc(size_t size, u32 align);  // vtable slot 8
    virtual void* memAlloc(size_t size, u32 align, u32 user_tag);  // vtable slot 9
    virtual void* memAlloc(size_t size, u32 align, u32 user_tag, u32 user_data);  // vtable slot 10
    virtual void* memAlloc(size_t size, ManagerIndex mgr_idx, u32 align, u32 user_tag, u32 user_data);  // vtable slot 18
    virtual void memFree(void* addr);  // vtable slot 14
    virtual size_t memSize(void* addr);  // vtable slot 15
    u32 memSizeEx(void* addr);
    void* getMemory() const;
    u32 getNumOfMgr() const;
    void setNumOfMgr(u32);
    void setMgrName(u32, const MtString&);
    u32 getPoolType() const;
    size_t getMemorySize(const MtDTI& dti);
    size_t getMemorySize(u32 user_tag);
protected:
    MtScalableAllocator();
private:
    u32 getCallNo(MGR* p_mgr);
    void detachUsedNode(MGR* p_mgr, CTRL* p_ctrl);
    void detachBlankNode(MGR* p_mgr, CTRL* p_ctrl);
    CTRL* mergeBlankNode(MGR* p_mgr, CTRL* p_ctrl, u32* err_code);
    void addUsedNode(MGR* p_mgr, CTRL* p_ctrl);
    void addBlankNode(MGR*, CTRL*);
    CTRL* allocPool(MGR* p_mgr, size_t sz, u32* err_code, bool global_search);
    MGR* getMgr(size_t sz);
    CTRL* getCtrl(void* addr);
    void* memAllocMgr(MGR* p_mgr, size_t size, u32 align, u32 user_tag, u32 user_data, u32* err_code, bool global_search);
    void addGlobalPool(CTRL* p_sblock, u32* err_code);
    CTRL* allocGlobalPool(MGR* p_mgr, size_t min_sz, size_t block_sz, u32* err_code);
    void initialize(void* p_mem, size_t aligned_size);
    void updateMemoryUsage(s64 adder);
    void set(u32);
    u32 getGlobalPoolSize() const;
    u32 getGlobalPoolNodeNum() const;
    void setPoolType(u32 type);
    static u32 calcDebugDataSize(u32 attr);
protected:
    void* mpMemoryHead;  // offset: 0x68
    void* mpMemoryTail;  // offset: 0x70
    bool mReleaseMem;  // offset: 0x78
    size_t mSize;  // offset: 0x80
    size_t mBlockNum;  // offset: 0x88
    size_t mAvailableBlockNum;  // offset: 0x90
    CTRLLIST mGlobalPool;  // offset: 0x98
    MGR mManager[8];  // offset: 0xb0
    u32 mIndexCounter;  // offset: 0x4f0
    MtCriticalSection mGlobalCS;  // offset: 0x4f8
    u32 mNumOfMgr;  // offset: 0x500
    u32 mPoolType;  // offset: 0x504
    size_t mPoolSize;  // offset: 0x508
    u32 mDebugDataSize;  // offset: 0x510
public:
    static MyDTI DTI;
    static const u16 DefaultAttr;
protected:
    static const u32 mBlockSize;
};

inline void* MtScalableAllocator::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline MtScalableAllocator::CTRL::CTRL() {
}
