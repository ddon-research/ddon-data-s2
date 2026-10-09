#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "nLayout.h"
#include "rLayout.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtString;
class cGroupParam;
class cLayoutPreset;
class cLayoutSetEnemy;
class cLayoutSetOm;
namespace nLayout { struct stLayoutID; }
namespace nLayout { struct stSplitID; }
class rLayout;

// Declarations
class cLayoutSet;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cLayoutSet : public MtObject
{
    // inferred: cLayoutSetEnemy::moveSetUnit names cLayoutSet::mpGroupParam
    friend class cLayoutSetEnemy;
    // inferred: cLayoutSetOm::moveSetUnit names cLayoutSet::mpGroupParam
    friend class cLayoutSetOm;
public:
    enum STATE
    {
        STATE_EMPTY = 0,
        STATE_MOVE = 1,
        STATE_PRE_RESERVE = 2,
        STATE_RESERVE = 3,
        STATE_RESERVE_EXE = 4,
        STATE_ARC_LOAD = 5,
    };
public:
    class MyDTI;
    class cUnitData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cUnitData : public MtObject
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
        cUnitData();
        // Address: 0x019aebf0 - 0x019aebf1 (1 bytes)
        virtual ~cUnitData() {}
        void update();
        cLayoutSet::STATE getState() const;
        void setState(cLayoutSet::STATE st);
        u32 getUnitID() const;
        u32 getPrio() const;
        const rLayout::SetInfo* getSetInfo() const;
        const MtDTI* getUnitDti() const;
        u32 getType() const;
        void reserve(u32 unitID, u32 prio, const rLayout::SetInfo* pSetInfo, const MtDTI* pDti, u32 type);
        bool isReserve();
        void empty();
    private:
        cLayoutSet::STATE mState;  // offset: 0x8
        u32 mUnitID;  // offset: 0xc
        u32 mPrio;  // offset: 0x10
        const rLayout::SetInfo* mpSetInfo;  // offset: 0x18
        const MtDTI* mpDti;  // offset: 0x20
        u32 mType;  // offset: 0x28
        const cLayoutPreset* mpPreset;  // offset: 0x30
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
    cLayoutSet();
    virtual ~cLayoutSet();
    void init(MT_CTSTR path, bool isBlocking);
    void update();
    void kill();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    // Address: 0x019aeb60 - 0x019aeb61 (1 bytes)
    virtual void finish() {}  // vtable slot 8
    // Address: 0x019aeb70 - 0x019aeb71 (1 bytes)
    virtual void splitKillSub() {}  // vtable slot 9
    void setRequest();
    virtual MtObject* getUnit(u32 id);  // vtable slot 10
    static u32 checkKeyWord(MT_CTSTR dstStr, MT_CTSTR ckWord);
    virtual bool deleteAllUnit();  // vtable slot 11
    // Address: 0x019aeb90 - 0x019aeb91 (1 bytes)
    virtual void deleteUnit(MtObject* pCtrl) {}  // vtable slot 12
    virtual void updateUnitPtrArray(bool isErase);  // vtable slot 13
protected:
    virtual bool canSetUnit() const;  // vtable slot 14
    bool isSplitSbc(s32 areaNo);
    bool isUpdateArea();
    virtual bool isUseUnitData() const;  // vtable slot 15
    virtual bool isLoadAreaChangeSet() const;  // vtable slot 16
    virtual void moveSetUnit();  // vtable slot 17
    virtual MtObject* setLayoutUnit(rLayout* pLayout, u32 no, bool isFroceSet, u32 mode);  // vtable slot 18
    bool isUnitDataEmpty(u32 no);
public:
    const nLayout::stLayoutID& getLayoutID() const;
    u32 getArea() const;
    u32 getGroup() const;
    void setLayoutID(const nLayout::stLayoutID& layoutID);
    void setArea(u32);
    void setGroup(u32);
    const nLayout::stSplitID& getSplitID() const;
    s32 getSplitX() const;
    s32 getSplitZ() const;
    void setSplitID(const nLayout::stSplitID& splitID);
    void setSplitX(u32);
    void setSplitZ(u32);
    bool splitIDIsZero() const;
    rLayout* getResource() const;
    bool isFailed() const;
    bool isUsage() const;
    bool isBlocking() const;
    u32 getUnitNum() const;
    bool isValid() const;
    bool isSetup() const;
    bool isUnitSetResource();
    bool isUnitScrollSbc();
    cGroupParam* getGroupParam() const;
    void setGroupParam(cGroupParam* pParam);
    void setAreaHitBit(u32 bit);
    void setNoSet(bool b);
    void setAutoSet(bool b);
protected:
    MtArray& getUnitArray();
    MtTypedArray<cUnitData>& getUnitDataArray();
    u32 getAreaHitBit() const;
public:
    void setSubGroupBit(u32 bit);
    u32 getSubGroupBit() const;
    void setAppearBit(u32 bit);
    u32 getAppearBit() const;
protected:
    rLayout* mpRsrc;  // offset: 0x8
    bool mIsNoSet;  // offset: 0x10
    bool mIsAutoSet;  // offset: 0x11
    bool mIsBlocking;  // offset: 0x12
    bool mIsRsrcUsage;  // offset: 0x13
    bool mIsSetup;  // offset: 0x14
    bool mIsDeleted;  // offset: 0x15
    bool mIsAutoSetComplete;  // offset: 0x16
    bool mUnitSetResourceComplete;  // offset: 0x17
    bool mUnitScrollSbcComplete;  // offset: 0x18
    s32 mAreaNo;  // offset: 0x1c
private:
    MtArray mUnitArray;  // offset: 0x20
    MtTypedArray<cUnitData> mUnitDataArray;  // offset: 0x40
    nLayout::stLayoutID mLayoutID;  // offset: 0x60
    nLayout::stSplitID mSplitID;  // offset: 0x64
    MtString mUnitName;  // offset: 0x68
    cGroupParam* mpGroupParam;  // offset: 0x70
    u32 mAreaHitBit;  // offset: 0x78
    u32 mSubGroupBit;  // offset: 0x7c
    u32 mAppearBit;  // offset: 0x80
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cGroupParam* cLayoutSet::getGroupParam() const {
    return this->mpGroupParam;
}
