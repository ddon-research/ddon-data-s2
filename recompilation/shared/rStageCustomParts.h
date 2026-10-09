#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "cResPath.h"
#include "cResource.h"
#include "nZoneUnitCtrl.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class cResPathEx;

// Declarations
class rStageCustomParts;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class rStageCustomParts : public cResource
{
public:
    class MyDTI;
    class Param;
    class Info;
    class Filter;
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
        // Address: 0x01ab2dc0 - 0x01ab2dc1 (1 bytes)
        virtual ~Param() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(rStageCustomParts::Param* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        f32 mDelta;  // offset: 0x8
        f32 mOffsetY;  // offset: 0xc
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
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
        virtual void setModelName(const MtString& name);  // vtable slot 6
        MT_CTSTR getModelName() const;
        virtual void setScrSbcName(const MtString& name, u32 idx);  // vtable slot 7
        MT_CTSTR getScrSbcName(u32 idx) const;
        void setScrSbcNameNum(u32);
        u32 getScrSbcNameNum() const;
        virtual void setEffSbcName(const MtString& name, u32 idx);  // vtable slot 8
        MT_CTSTR getEffSbcName(u32 idx) const;
        void setEffSbcNameNum(u32);
        u32 getEffSbcNameNum() const;
        virtual void setLightName(const MtString& name);  // vtable slot 9
        MT_CTSTR getLightName() const;
        virtual void setNaviMeshName(const MtString& name);  // vtable slot 10
        MT_CTSTR getNaviMeshName() const;
        virtual void setEpvName(const MtString& name);  // vtable slot 11
        MT_CTSTR getEpvName() const;
        virtual void setOccluderName(const MtString& name);  // vtable slot 12
        MT_CTSTR getOccluderName() const;
        s32 getEpvIndexAlways() const;
        s32 getEpvIndexDay() const;
        s32 getEpvIndexNight() const;
        u64 getEfcColorZone() const;
        u64 getEfcCtrlZone() const;
        u64 getIndoorZoneScr() const;
        u64 getIndoorZoneEfc() const;
        u64 getLightAndFogZone() const;
        u64 getSoundAreaInfo() const;
        u64 getZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE type) const;
        u64 getZoneStatus() const;
    public:
        MT_CHAR mModel[64];  // offset: 0x8
        MT_CHAR mScrSbc[3][64];  // offset: 0x48
        MT_CHAR mEffSbc[3][64];  // offset: 0x108
        MT_CHAR mLight[64];  // offset: 0x1c8
        MT_CHAR mNaviMesh[64];  // offset: 0x208
        MT_CHAR mEpv[64];  // offset: 0x248
        MT_CHAR mOccluder[64];  // offset: 0x288
        u16 mAreaNo;  // offset: 0x2c8
        u16 mType;  // offset: 0x2ca
        u32 mSize;  // offset: 0x2cc
        f32 mOffsetZ;  // offset: 0x2d0
        s32 mEpvIndexAlways;  // offset: 0x2d4
        s32 mEpvIndexDay;  // offset: 0x2d8
        s32 mEpvIndexNight;  // offset: 0x2dc
        MtColor mColor;  // offset: 0x2e0
        MtString mComment;  // offset: 0x2e8
        cResPathEx mEfcColorZone;  // offset: 0x2f0
        cResPathEx mEfcCtrlZone;  // offset: 0x2f8
        cResPathEx mIndoorZoneScr;  // offset: 0x300
        cResPathEx mIndoorZoneEfc;  // offset: 0x308
        cResPathEx mLightAndFogZone;  // offset: 0x310
        cResPathEx mSoundAreaInfo;  // offset: 0x318
        cResPathEx mZoneUnitCtrl[3];  // offset: 0x320
        cResPathEx mZoneStatus;  // offset: 0x338
        static MyDTI DTI;
    };
public:
    class Filter : public MtObject
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
        Filter();
        // Address: 0x01ab3010 - 0x01ab3011 (1 bytes)
        virtual ~Filter() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void copy(rStageCustomParts::Filter* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
        virtual void setFilterName(const MtString& name);  // vtable slot 6
        MT_CTSTR getFilterName() const;
    public:
        MT_CHAR mFilter[64];  // offset: 0x8
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
    rStageCustomParts();
    virtual ~rStageCustomParts();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    Param* getParam();
    virtual Info* getInfo(u32 index) const;  // vtable slot 16
    virtual u32 getInfoNum() const;  // vtable slot 17
    virtual Filter* getFilter(u32 index) const;  // vtable slot 18
    virtual u32 getFilterNum() const;  // vtable slot 19
    u32 getAreaSize(u32 areaNo);
    u32 getAreaType(u32 areaNo);
    MT_CTSTR getFilterName(u32 index);
    virtual Info* searchInfo(u32 areaNo) const;  // vtable slot 20
    f32 getDelta() const;
    f32 getOffsetY() const;
protected:
    Param mParam;  // offset: 0x70
    Info* mpArrayInfo;  // offset: 0x80
    u32 mArrayInfoNum;  // offset: 0x88
    Filter* mpArrayFilter;  // offset: 0x90
    u32 mArrayFilterNum;  // offset: 0x98
public:
    static MyDTI DTI;
protected:
    static const u8 DATA_VERSION = 17;
};

// Inline, no code of its own: checked where it is inlined.
inline rStageCustomParts::Param::Param() {
    this->mDelta = -100.0f;
    this->mOffsetY = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline void rStageCustomParts::Filter::clear() {
    this->mFilter[0] = static_cast<char>(0);
}
