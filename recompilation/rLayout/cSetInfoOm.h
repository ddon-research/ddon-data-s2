#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/MtPrimitive3D.h"
#include "../shared/cOmControl.h"
#include "../shared/cResPath.h"
#include "cSetInfoCoord.h"
#include "../shared/rAIFSM.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cSetInfo;
class cUnit;
class rAIFSM;

// Declarations
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

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cSetInfoOm : public cSetInfoCoord
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
    cSetInfoOm();
    virtual ~cSetInfoOm();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    bool mDisableEffect;  // offset: 0x44
    bool mDisableOnlyEffect;  // offset: 0x45
    bool mOpenFlag;  // offset: 0x46
    bool mEnableSyncLight;  // offset: 0x47
    bool mEnableZone;  // offset: 0x48
    u32 mInitMtnNo;  // offset: 0x4c
    u32 mAreaMasterNo;  // offset: 0x50
    u16 mAreaReleaseNo;  // offset: 0x54
    bool mAreaReleaseON;  // offset: 0x56
    bool mAreaReleaseOFF;  // offset: 0x57
    u32 mWarpPointId;  // offset: 0x58
    u32 mKeyNo;  // offset: 0x5c
    bool mIsBreakLink;  // offset: 0x60
    bool mIsBreakQuest;  // offset: 0x61
    u16 mBreakKind;  // offset: 0x62
    u16 mBreakGroup;  // offset: 0x64
    u16 mBreakID;  // offset: 0x66
    u32 mQuestFlag;  // offset: 0x68
    bool mIsNoSbc;  // offset: 0x6c
    bool mIsMyQuest;  // offset: 0x6d
    static MyDTI DTI;
};

class cSetInfoOmBadStatus : public cSetInfoOm
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
    cSetInfoOmBadStatus();
    virtual ~cSetInfoOmBadStatus();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    f32 mBadRadius;  // offset: 0x70
    f32 mBadHeight;  // offset: 0x74
    MtVector3 mBadPos;  // offset: 0x80
    u32 mBreakHitNum;  // offset: 0x90
    static MyDTI DTI;
};

class cSetInfoOmBoard : public cSetInfoOm
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
    cSetInfoOmBoard();
    virtual ~cSetInfoOmBoard();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    u32 mBoardID;  // offset: 0x70
    static MyDTI DTI;
};

class cSetInfoOmBowlOfLife : public cSetInfoOm
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
    cSetInfoOmBowlOfLife();
    virtual ~cSetInfoOmBowlOfLife();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    bool mbWaitBowlOfLife;  // offset: 0x6e
    bool mbFullBowlOfLife;  // offset: 0x6f
    bool mbSetEM;  // offset: 0x70
    bool mbInvisible;  // offset: 0x71
    bool mIsQuest;  // offset: 0x72
    u32 mQuestId;  // offset: 0x74
    u16 mKind;  // offset: 0x78
    u16 mGroup;  // offset: 0x7a
    u16 mID;  // offset: 0x7c
    static MyDTI DTI;
};

class cSetInfoOmCtrl : public cSetInfoOm
{
public:
    class MyDTI;
    class cLinkParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLinkParam : public MtObject
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
        cLinkParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u16 mKind;  // offset: 0x8
        u16 mGroup;  // offset: 0xa
        u16 mID;  // offset: 0xc
        u32 mTransition;  // offset: 0x10
        u32 mState;  // offset: 0x14
        s32 mCamEvNo;  // offset: 0x18
        cResPath<rAIFSM> mrFSMCam;  // offset: 0x20
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
    cSetInfoOmCtrl();
    virtual ~cSetInfoOmCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    u32 mKeyItemNo;  // offset: 0x70
    cLinkParam mLinkParam[4];  // offset: 0x78
    bool mIsQuest;  // offset: 0x118
    u32 mQuestId;  // offset: 0x11c
    s32 mAddGroupNo;  // offset: 0x120
    s32 mAddSubGroupNo;  // offset: 0x124
    static MyDTI DTI;
    static const u32 LINK_UNIT_NUM = 4;
};

class cSetInfoOmDoor : public cSetInfoOm
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
    cSetInfoOmDoor();
    virtual ~cSetInfoOmDoor();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    bool mbPRT;  // offset: 0x6e
    MtVector3 mPRTPos;  // offset: 0x70
    f32 mPRTScale;  // offset: 0x80
    u32 mTextType;  // offset: 0x84
    u32 mTextQuestNo;  // offset: 0x88
    u32 mTextNo;  // offset: 0x8c
    u32 mQuestID;  // offset: 0x90
    static MyDTI DTI;
};

class cSetInfoOmElfSW : public cSetInfoOm
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
    cSetInfoOmElfSW();
    virtual ~cSetInfoOmElfSW();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    u32 mPLCount;  // offset: 0x70
    static MyDTI DTI;
};

class cSetInfoOmFall : public cSetInfoOm
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
    cSetInfoOmFall();
    virtual ~cSetInfoOmFall();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    f32 mFallHeight;  // offset: 0x70
    static MyDTI DTI;
};

class cSetInfoOmGather : public cSetInfoOm
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
    cSetInfoOmGather();
    virtual ~cSetInfoOmGather();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
    void setGatheringType(u32);
public:
    u32 mItemListID;  // offset: 0x70
    u32 mGatheringType;  // offset: 0x74
    bool mIsGatherEnemy;  // offset: 0x78
    s16 mEnemyGroupNo;  // offset: 0x7a
    static MyDTI DTI;
};

class cSetInfoOmHakuryuu : public cSetInfoOm
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
    cSetInfoOmHakuryuu();
    virtual ~cSetInfoOmHakuryuu();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    u32 mStoneLevel;  // offset: 0x70
    static MyDTI DTI;
};

class cSetInfoOmHeal : public cSetInfoOm
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
    cSetInfoOmHeal();
    virtual ~cSetInfoOmHeal();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    u32 mHealType;  // offset: 0x70
    static MyDTI DTI;
};

class cSetInfoOmLadder : public cSetInfoOm
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
    cSetInfoOmLadder();
    virtual ~cSetInfoOmLadder();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    u32 mHeight;  // offset: 0x70
    static MyDTI DTI;
};

class cSetInfoOmLever : public cSetInfoOm
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
    cSetInfoOmLever();
    virtual ~cSetInfoOmLever();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    bool mbReqLever;  // offset: 0x6e
    s32 mCamEvNo;  // offset: 0x70
    cResPath<rAIFSM> mFSMCamEv;  // offset: 0x78
    static MyDTI DTI;
};

class cSetInfoOmNav : public cSetInfoOm
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
    cSetInfoOmNav();
    virtual ~cSetInfoOmNav();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    MtVector3 mNavOBBExtent;  // offset: 0x70
    static MyDTI DTI;
};

class cSetInfoOmRange : public cSetInfoOm
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
    cSetInfoOmRange();
    virtual ~cSetInfoOmRange();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    f32 mRange;  // offset: 0x70
    u32 mGrp;  // offset: 0x74
    bool mIsAll;  // offset: 0x78
    bool mIsOneTime;  // offset: 0x79
    static MyDTI DTI;
};

class cSetInfoOmText : public cSetInfoOm
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
    cSetInfoOmText();
    virtual ~cSetInfoOmText();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    u32 mTextNo;  // offset: 0x70
    u32 mTextQuestNo;  // offset: 0x74
    u32 mTextType;  // offset: 0x78
    static MyDTI DTI;
};

class cSetInfoOmTreasureBox : public cSetInfoOmGather
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
    cSetInfoOmTreasureBox();
    virtual ~cSetInfoOmTreasureBox();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    static MyDTI DTI;
};

class cSetInfoOmWall : public cSetInfoOm
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
    cSetInfoOmWall();
    virtual ~cSetInfoOmWall();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
public:
    u32 mWallType;  // offset: 0x70
    MtOBB mNavOBB;  // offset: 0x80
    static MyDTI DTI;
};

class cSetInfoOmWarp : public cSetInfoOm
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
    cSetInfoOmWarp();
    virtual ~cSetInfoOmWarp();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual bool applyParam(cOmControl::InputLot& param) const;  // vtable slot 14
    virtual void copy(cSetInfo* p);  // vtable slot 11
    u32 getStageNo(u32 idx);
    void setStageNo(u32 val, u32 idx);
    u32 getStartPosNo(u32 idx);
    void setStartPosNo(u32 val, u32 idx);
    u32 getQuestNo(u32 idx);
    void setQuestNo(u32 val, u32 idx);
    u32 getFlagNo(u32 idx);
    void setFlagNo(u32 val, u32 idx);
    u32 getSpotId(u32 idx);
    void setSpotId(u32 val, u32 idx);
    u32 getDataNum();
    void setDataNum(u32);
public:
    u32 mStageNo[3];  // offset: 0x70
    u32 mStartPosNo[3];  // offset: 0x7c
    u32 mQuestNo[3];  // offset: 0x88
    u32 mFlagNo[3];  // offset: 0x94
    u32 mSpotId[3];  // offset: 0xa0
    u32 mTextType;  // offset: 0xac
    u32 mTextQuestNo;  // offset: 0xb0
    u32 mTextNo;  // offset: 0xb4
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cSetInfoOmCtrl::cLinkParam::cLinkParam() {
    this->mKind = static_cast<u16>(0);
    this->mGroup = static_cast<u16>(0);
    this->mID = static_cast<u16>(0);
    this->mTransition = static_cast<u32>(0);
    this->mState = static_cast<u32>(0);
    this->mCamEvNo = static_cast<s32>(-1);
}
