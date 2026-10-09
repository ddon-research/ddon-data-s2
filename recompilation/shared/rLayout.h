#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"
#include "nLayout.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class MtStream;
class MtString;
class MtVector3;
class cSetInfo;
class cSetInfoEnemy;
class cSetInfoGeneralPoint;
class cSetInfoNpc;
class cSetInfoOm;
class cSetInfoOmBadStatus;
class cSetInfoOmBoard;
class cSetInfoOmBowlOfLife;
class cSetInfoOmCtrl;
class cSetInfoOmDoor;
class cSetInfoOmElfSW;
class cSetInfoOmFall;
class cSetInfoOmGather;
class cSetInfoOmHakuryuu;
class cSetInfoOmHeal;
class cSetInfoOmLadder;
class cSetInfoOmLever;
class cSetInfoOmNav;
class cSetInfoOmRange;
class cSetInfoOmText;
class cSetInfoOmTreasureBox;
class cSetInfoOmWall;
class cSetInfoOmWarp;
namespace nLayout { struct stLayoutID; }
namespace nLayout { struct stSplitID; }

// Declarations
class rLayout;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class rLayout : public cResource
{
public:
    enum TYPE
    {
        TYPE_SCR = 0,
        TYPE_PLAN = 1,
        TYPE_ENEMY = 2,
        TYPE_NPC = 3,
        TYPE_TARGET = 4,
        TYPE_NUM = 5,
    };
    enum SET_INFO_ALLOC
    {
        SET_INFO_ALLOC_ENEMY = 0,
        SET_INFO_ALLOC_NPC = 1,
        SET_INFO_ALLOC_GENERALPOINT = 2,
        SET_INFO_ALLOC_OM = 3,
        SET_INFO_ALLOC_OM_BOARD = 4,
        SET_INFO_ALLOC_OM_BOWLOFLIFE = 5,
        SET_INFO_ALLOC_OM_CTRL = 6,
        SET_INFO_ALLOC_OM_DOOR = 7,
        SET_INFO_ALLOC_OM_ELFSW = 8,
        SET_INFO_ALLOC_OM_FALL = 9,
        SET_INFO_ALLOC_OM_GATHER = 10,
        SET_INFO_ALLOC_OM_TREASUREBOX = 11,
        SET_INFO_ALLOC_OM_HAKURYUU = 12,
        SET_INFO_ALLOC_OM_HEAL = 13,
        SET_INFO_ALLOC_OM_LADDER = 14,
        SET_INFO_ALLOC_OM_LEVER = 15,
        SET_INFO_ALLOC_OM_NAV = 16,
        SET_INFO_ALLOC_OM_RANGE = 17,
        SET_INFO_ALLOC_OM_TEXT = 18,
        SET_INFO_ALLOC_OM_WALL = 19,
        SET_INFO_ALLOC_OM_WARP = 20,
        SET_INFO_ALLOC_OM_BADSTATUS = 21,
        SET_INFO_ALLOC_NUM = 22,
    };
public:
    class MyDTI;
    class SetInfo;
    struct SetInfoBuffer;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class SetInfo : public MtObject
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
        SetInfo();
        virtual ~SetInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r, rLayout::SetInfoBuffer& buffer);  // vtable slot 6
        MT_CTSTR getName();
        void setDummy(const MtString&);
        s32 getID() const;
        void setID(s32 val);
        bool operator==(const rLayout::SetInfo&) const;
        bool operator!=(const rLayout::SetInfo&) const;
        void release();
        const nLayout::stLayoutID& getLayoutID() const;
        u32 getArea() const;
        u32 getGroup() const;
        void setLayoutID(const nLayout::stLayoutID&);
        void setArea(u32 area);
        void setGroup(u32 group);
        const nLayout::stSplitID& getSplitID() const;
        s32 getSplitX() const;
        s32 getSplitZ() const;
        void setSplitID(const nLayout::stSplitID&);
        void setSplitX(u32 x);
        void setSplitZ(u32 z);
        MtVector3 getSetPos() const;
        void setSetPos(MtVector3& pos);
    public:
        s32 mID;  // offset: 0x8
        cSetInfo* mpInfo;  // offset: 0x10
    private:
        nLayout::stLayoutID mLayoutID;  // offset: 0x18
        nLayout::stSplitID mSplitID;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
public:
    struct SetInfoBuffer
    {
    public:
        cSetInfoEnemy* pSetInfoEnemy;  // offset: 0x0
        cSetInfoNpc* pSetInfoNpc;  // offset: 0x8
        cSetInfoGeneralPoint* pSetInfoGeneralPoint;  // offset: 0x10
        cSetInfoOm* pSetInfoOm;  // offset: 0x18
        cSetInfoOmBoard* pSetInfoOmBoard;  // offset: 0x20
        cSetInfoOmBowlOfLife* pSetInfoOmBowlOfLife;  // offset: 0x28
        cSetInfoOmCtrl* pSetInfoOmCtrl;  // offset: 0x30
        cSetInfoOmDoor* pSetInfoOmDoor;  // offset: 0x38
        cSetInfoOmElfSW* pSetInfoOmElfSW;  // offset: 0x40
        cSetInfoOmFall* pSetInfoOmFall;  // offset: 0x48
        cSetInfoOmGather* pSetInfoOmGather;  // offset: 0x50
        cSetInfoOmTreasureBox* pSetInfoOmTreasureBox;  // offset: 0x58
        cSetInfoOmHakuryuu* pSetInfoOmHakuryuu;  // offset: 0x60
        cSetInfoOmHeal* pSetInfoOmHeal;  // offset: 0x68
        cSetInfoOmLadder* pSetInfoOmLadder;  // offset: 0x70
        cSetInfoOmLever* pSetInfoOmLever;  // offset: 0x78
        cSetInfoOmNav* pSetInfoOmNav;  // offset: 0x80
        cSetInfoOmRange* pSetInfoOmRange;  // offset: 0x88
        cSetInfoOmText* pSetInfoOmText;  // offset: 0x90
        cSetInfoOmWall* pSetInfoOmWall;  // offset: 0x98
        cSetInfoOmWarp* pSetInfoOmWarp;  // offset: 0xa0
        cSetInfoOmBadStatus* pSetInfoOmBadStatus;  // offset: 0xa8
        MtArray* pSetInfoSingleNewArray;  // offset: 0xb0
        u32 AvailNums[22];  // offset: 0xb8
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
    rLayout();
    virtual ~rLayout();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    void destruct();
    virtual void clear();  // vtable slot 15
    u32 getDataVersion() const;
    u32 getMagicHeader() const;
    TYPE getLotType() const;
    const nLayout::stLayoutID& getLayoutID() const;
    u32 getGroup() const;
    const nLayout::stSplitID& getSplitID() const;
    s32 getSplitX() const;
    s32 getSplitZ() const;
private:
    bool operator==(const rLayout&) const;
protected:
    void setup();
public:
    virtual SetInfo* getSetInfo(u32 index) const;  // vtable slot 16
    virtual u32 getSetInfoNum() const;  // vtable slot 17
    virtual s32 getID(u32 no) const;  // vtable slot 18
    u64 getID() const;
    u8 getIndex(u32) const;
    static void filePath2LayoutID(TYPE& lotType, nLayout::stLayoutID& layoutID, MT_CTSTR filePath);
    static void filePath2SplitID(nLayout::stSplitID& splitID, MT_CTSTR filePath);
protected:
    SetInfo* mpArray;  // offset: 0x70
    u32 mArrayNum;  // offset: 0x78
    u8 mIndex[256];  // offset: 0x7c
    u32 mSetInfoNeedNums[22];  // offset: 0x17c
    void* mpSetInfoBuffer;  // offset: 0x1d8
    MtArray mSetInfoSingleNewArray;  // offset: 0x1e0
    TYPE mLotType;  // offset: 0x200
    nLayout::stLayoutID mLayoutID;  // offset: 0x204
    nLayout::stSplitID mSplitID;  // offset: 0x208
public:
    static MyDTI DTI;
    static const s32 DATA_VERSION;
    static MT_CTSTR typeKeyWord[5];
};
