#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/cResPath.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class MtVector3;
class cResPathEx;

// Declarations
class rEditStageParam;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u64 = __uint64_t;
using u8 = unsigned char;

class rEditStageParam : public cResource
{
public:
    enum
    {
        WEATHER_NUM = 2,
    };
    enum
    {
        TYPE_PLAYER_EDIT = 0,
        TYPE_PAWN_EDIT = 1,
        TYPE_BEAUTY_PARLOR = 2,
    };
    enum
    {
        FLAG_WORLD_OFFSET = 1,
    };
public:
    class MyDTI;
    class Info;
    class List;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Info : public MtObject
    {
    public:
        class MyDTI;
        class WeatherData;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class WeatherData : public MtObject
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
            WeatherData();
            // Address: 0x01a85510 - 0x01a85511 (1 bytes)
            virtual ~WeatherData() {}
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        public:
            u32 mWeatherID;  // offset: 0x8
            u32 mHour;  // offset: 0xc
            u32 mMinite;  // offset: 0x10
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
        Info();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void setModelName(const MtString& name);
        MT_CTSTR getModelName() const;
        void setFilterName(const MtString& name);
        MT_CTSTR getFilterName() const;
        void setLightName(const MtString& name);
        MT_CTSTR getLightName() const;
        void setOmListName(const MtString& name);
        MT_CTSTR getOmListName() const;
        void setWeatherStageInfoName(const MtString& name);
        MT_CTSTR getWeatherStageInfoName() const;
        void setWeatherParamInfoName(const MtString& name);
        MT_CTSTR getWeatherParamInfoName() const;
        u32 getWeatherID(u32 idx);
        u32 getHour(u32 idx);
        u32 getMinite(u32 idx);
        u32 getWeatherNum();
        u64 getSkyWepResId() const;
        u64 getRoomWepResId() const;
        u64 getEpvResId() const;
        s32 getEpvIndexAlways() const;
        s32 getEpvIndexDay() const;
        s32 getEpvIndexNight() const;
        bool isWorldOffset();
        bool isChangeTime();
    public:
        MT_CHAR mModelSdl[64];  // offset: 0x8
        MT_CHAR mFilterSdl[64];  // offset: 0x48
        MT_CHAR mLightSdl[64];  // offset: 0x88
        MT_CHAR mOmListSdl[64];  // offset: 0xc8
        u32 mReverb;  // offset: 0x108
        MtVector3 mPlPos;  // offset: 0x110
        f32 mPlRotY;  // offset: 0x120
        MT_CHAR mWeatherStageInfo[64];  // offset: 0x124
        MT_CHAR mWeatherParamInfo[64];  // offset: 0x164
        WeatherData mWeatherData[2];  // offset: 0x1a8
        cResPathEx mpSkyWep;  // offset: 0x1d8
        cResPathEx mpRoomWep;  // offset: 0x1e0
        cResPathEx mpEpv;  // offset: 0x1e8
        s32 mEpvIndexAlways;  // offset: 0x1f0
        s32 mEpvIndexDay;  // offset: 0x1f4
        s32 mEpvIndexNight;  // offset: 0x1f8
        u32 mFlag;  // offset: 0x1fc
        static MyDTI DTI;
    };
public:
    class List : public MtObject
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
        List();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        s8 getListNo(u32 idx);
        void setListNo(s8 no, u32 idx);
        u32 getListNoNum();
        void setListNoNum(u32);
    public:
        s8 mListTbl[8];  // offset: 0x8
        static MyDTI DTI;
        static const u32 LIST_TBL_NUM = 8;
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
    rEditStageParam();
    virtual ~rEditStageParam();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual Info* getInfo(u32 index) const;  // vtable slot 16
    virtual u32 getNum() const;  // vtable slot 17
    virtual List* getList(u32 index) const;  // vtable slot 18
    virtual u32 getListNum() const;  // vtable slot 19
    void getStageList(u32 type, MtArray& ar);
    s32 getStageListNo(u32 type, u32 index);
    u32 getStageListNum(u32 type);
    ARC_TAGID getStageArcTagId(u32 type, u32 index);
public:
    Info* mpArrayInfo;  // offset: 0x70
    u32 mArrayInfoNum;  // offset: 0x78
    List* mpArrayList;  // offset: 0x80
    u32 mArrayListNum;  // offset: 0x88
    static MyDTI DTI;
    static const u8 DATA_VERSION = 12;
};

// Inline, no code of its own: checked where it is inlined.
inline rEditStageParam::Info::WeatherData::WeatherData() {
    this->mWeatherID = static_cast<u32>(1);
    this->mHour = static_cast<u32>(12);
    this->mMinite = static_cast<u32>(0);
}
