#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtStlAllocator.h"
#include "MtStlCustom.h"
#include "MtString.h"
#include "cResPath.h"
#include "cResource.h"
#include "nZoneUnitCtrl.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtDataReader;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class MtVector3;
class cResPathEx;

// Declarations
class rStageJoint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class rStageJoint : public cResource
{
public:
    enum
    {
        JOINT_AREA_MAX = 16,
        AREA_MAX = 128,
    };
public:
    class MyDTI;
    class Param;
    class Info;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Param : public MtObject
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
        Param();
        virtual ~Param();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void copy(rStageJoint::Param* src);
        bool load(MtDataReader& r);
        void clear();
        void setAreaNumX(u32 numX);
        u32 getAreaNumX() const;
        void setAreaNumZ(u32 numZ);
        u32 getAreaNumZ() const;
        void setAreaData(s8 val, u32 idx);
        void setAreaData(s8 val, u32 z, u32 x);
        s8 getAreaData(u32 idx) const;
        s8 getAreaData(u32 z, u32 x) const;
        void setAreaNum(u32);
        u32 getAreaNum() const;
        bool getXZFromAreaIdx(u32 idx, u32& outX, u32& outZ);
    public:
        f32 mStartX;  // offset: 0x8
        f32 mStartZ;  // offset: 0xc
        f32 mDeltaX;  // offset: 0x10
        f32 mDeltaZ;  // offset: 0x14
        u32 mAreaNumX;  // offset: 0x18
        u32 mAreaNumZ;  // offset: 0x1c
        s8* * mpArea;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class Info : public MtObject
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
        Info();
        virtual ~Info();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void copy(rStageJoint::Info* src);
        bool load(MtDataReader& r);
        void clear();
        void setModelName(const MtString& name);
        MT_CTSTR getModelName() const;
        void setScrSbcName(const MtString& name, u32 idx);
        MT_CTSTR getScrSbcName(u32 idx) const;
        void setScrSbcNameNum(u32);
        u32 getScrSbcNameNum() const;
        void setEffSbcName(const MtString& name, u32 idx);
        MT_CTSTR getEffSbcName(u32 idx) const;
        void setEffSbcNameNum(u32);
        u32 getEffSbcNameNum() const;
        void setLightName(const MtString& name);
        MT_CTSTR getLightName() const;
        void setNaviMeshName(const MtString& name);
        MT_CTSTR getNaviMeshName() const;
        void setPlantTreeName(const MtString& name);
        MT_CTSTR getPlantTreeName() const;
        void setEpvName(const MtString& name);
        MT_CTSTR getEpvName() const;
        void setSndInfoName(const MtString& name);
        MT_CTSTR getSndInfoName() const;
        u64 getEfcColorZone() const;
        u64 getEfcCtrlZone() const;
        u64 getIndoorZoneScr() const;
        u64 getIndoorZoneEfc() const;
        u64 getLightAndFogZone() const;
        u64 getZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE type) const;
        u64 getZoneStatus() const;
        bool addJointArea(s8 newJoinedAreaIdx);
        void clearJointAreas();
        bool hasInfo() const;
    public:
        MT_CHAR mModel[64];  // offset: 0x8
        MT_CHAR mScrSbc[3][64];  // offset: 0x48
        MT_CHAR mEffSbc[3][64];  // offset: 0x108
        MT_CHAR mLight[64];  // offset: 0x1c8
        MT_CHAR mNaviMesh[64];  // offset: 0x208
        MT_CHAR mPlantTree[64];  // offset: 0x248
        MT_CHAR mEpv[64];  // offset: 0x288
        MT_CHAR mSndInfo[64];  // offset: 0x2c8
        s8 mJoint[16];  // offset: 0x308
        MtColor mColor;  // offset: 0x318
        s32 mEpvIndexAlways;  // offset: 0x31c
        s32 mEpvIndexDay;  // offset: 0x320
        s32 mEpvIndexNight;  // offset: 0x324
        cResPathEx mEfcColorZone;  // offset: 0x328
        cResPathEx mEfcCtrlZone;  // offset: 0x330
        cResPathEx mIndoorZoneScr;  // offset: 0x338
        cResPathEx mIndoorZoneEfc;  // offset: 0x340
        cResPathEx mLightAndFogZone;  // offset: 0x348
        cResPathEx mZoneUnitCtrl[3];  // offset: 0x350
        cResPathEx mZoneStatus;  // offset: 0x368
        MtString mComment;  // offset: 0x370
        u32 mVersion;  // offset: 0x378
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
    rStageJoint();
    virtual ~rStageJoint();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    Param* getParam();
    Info* getPersistentInfo();
    virtual Info* getInfo(u32 index) const;  // vtable slot 16
    virtual u32 getInfoNum() const;  // vtable slot 17
    s32 getAreaNo(const MtVector3& pos) const;
    s32 getAreaNo(s32 z, s32 x) const;
    bool isValidTileCoordinates(s32 z, s32 x) const;
    MtStlVector<signed char, MtStlAllocator<signed char> > getAreasSurroundingTile(s32 z, s32 x, bool includeOwnArea) const;
    MtStlVector<MtVector3, MtStlAllocator<MtVector3> > getVerticesOfTile(s32 z, s32 x) const;
protected:
    Param mParam;  // offset: 0x70
    Info* mpArrayInfo;  // offset: 0x98
    u32 mArrayInfoNum;  // offset: 0xa0
    Info mPersistentInfo;  // offset: 0xa8
public:
    static const u32 PERSISTENT_MDL_AREA_NO;
    static MyDTI DTI;
protected:
    static const u8 DATA_VERSION = 19;
};
