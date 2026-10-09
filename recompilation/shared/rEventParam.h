#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;
class MtString;

// Declarations
class cEventParam;
class rEventParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cEventParam : public MtObject
{
public:
    enum EVENT_TYPE
    {
        TYPE_CUTIN = 0,
        TYPE_MOVIE = 1,
        TYPE_FSM = 2,
    };
    enum LIGHT_CTRL_TYPE
    {
        LIGHT_CTRL_NONE = 0,
        LIGHT_CTRL_ALL = 1,
        LIGHT_CTRL_NO_NIGHT = 2,
        LIGHT_CTRL_ONLY_NIGHT = 3,
    };
    enum OM_CTRL_TYPE
    {
        OM_CTRL_NORMAL = 0,
        OM_CTRL_NO_DISP = 1,
        OM_CTRL_NO_SET = 2,
        OM_CTRL_UPDATE = 3,
        OM_CTRL_ARC_LOAD = 4,
    };
    enum EVENT_FLAG
    {
        FLAG_NONE = 0,
        FLAG_LIGHT1 = 1,
        FLAG_DUMMY = 2,
        FLAG_NO_FSM_SDL = 4,
        FLAG_NO_PARTY = 8,
        FLAG_CHG_SUB_MIXER = 16,
        FLAG_ON_STG_BGM = 32,
        FLAG_ON_BTL_BGM = 64,
    };
public:
    class MyDTI;
    class cOmList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cOmList : public MtObject
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
        cOmList();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(cEventParam::cOmList* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        u32 mOmId;  // offset: 0x8
        u16 mCtrlType;  // offset: 0xc
        u16 mLotType;  // offset: 0xe
        s16 mGroupNo;  // offset: 0x10
        s16 mSetId;  // offset: 0x12
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
    cEventParam();
    virtual ~cEventParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setFileName(const MtString& name);  // vtable slot 6
    MT_CTSTR getFileName() const;
    bool isCutIn();
    bool isMovie();
    bool isFsm();
    bool isPartyEv() const;
    bool isFlag(u16 flag) const;
    cOmList* getOmList(u32 index) const;
    u32 getOmListNum() const;
    MtTypedArray<cOmList>* getOmArray();
    void addOmList(cOmList* p);
    u32 getQuestId() const;
    u32 getLightCtrl() const;
    s16 getSubMixerBefore() const;
    s16 getSubMixerAfter() const;
public:
    u16 mType;  // offset: 0x8
    u16 mStage;  // offset: 0xa
    u16 mEvNo;  // offset: 0xc
    u16 mFlag;  // offset: 0xe
    MtString mFname;  // offset: 0x10
    u32 mQuestId;  // offset: 0x18
    u32 mLightCtrl;  // offset: 0x1c
    u8 mStartFadeType;  // offset: 0x20
    u8 mEndFadeType;  // offset: 0x21
    s16 mSubMixerBefore;  // offset: 0x22
    s16 mSubMixerAfter;  // offset: 0x24
    MtTypedArray<cOmList> mOmList;  // offset: 0x28
    f32 mOmAQCScale;  // offset: 0x48
    u32 mVersion;  // offset: 0x4c
    static MyDTI DTI;
    static const u16 DATA_VERSION = 18;
};

class rEventParam : public rTbl2<cEventParam>
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
    virtual bool loadData(MtDataReader& in, cEventParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool load(MtStream& in);  // vtable slot 11
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cEventParam::cOmList::cOmList() {
    this->mOmId = static_cast<u32>(0);
    this->mCtrlType = static_cast<u16>(0);
    this->mLotType = static_cast<u16>(0);
    this->mGroupNo = static_cast<s16>(-1);
    this->mSetId = static_cast<s16>(-1);
}
