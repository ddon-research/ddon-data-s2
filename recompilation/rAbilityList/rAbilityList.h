#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;
namespace nCollisionUtil { struct LoadBuffer; }

// Declarations
class cAbilityData;
class cAbilityParam;
class rAbilityList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cAbilityParam : public MtObject
{
public:
    enum
    {
        PARAM_TYPE_NONE = 0,
        PARAM_TYPE_WEIGHT = 1,
        PARAM_TYPE_HP = 2,
        PARAM_TYPE_STAMINA = 3,
        PARAM_TYPE_LOST = 4,
        PARAM_TYPE_ATTACK = 5,
        PARAM_TYPE_DEFENCE = 6,
        PARAM_TYPE_M_ATTACK = 7,
        PARAM_TYPE_M_DEFENCE = 8,
        PARAM_TYPE_MUSCLE = 9,
        PARAM_TYPE_PIYO = 10,
        PARAM_TYPE_STRENGTH = 11,
        PARAM_TYPE_GUTS = 12,
        PARAM_TYPE_DEF_FIRE = 13,
        PARAM_TYPE_DEF_ICE = 14,
        PARAM_TYPE_DEF_THUNDER = 15,
        PARAM_TYPE_DEF_HORY = 16,
        PARAM_TYPE_DEF_DARK = 17,
        PARAM_TYPE_REG_FIRE = 18,
        PARAM_TYPE_REG_ICE = 19,
        PARAM_TYPE_REG_THUNDER = 20,
        PARAM_TYPE_REG_HORY = 21,
        PARAM_TYPE_REG_DARK = 22,
        PARAM_TYPE_REG_POISON = 23,
        PARAM_TYPE_REG_SLOW = 24,
        PARAM_TYPE_REG_SLEEP = 25,
        PARAM_TYPE_REG_PIYO = 26,
        PARAM_TYPE_REG_WATER = 27,
        PARAM_TYPE_REG_OIL = 28,
        PARAM_TYPE_REG_SEAL = 29,
        PARAM_TYPE_REG_CURSE = 30,
        PARAM_TYPE_REG_SOFT = 31,
        PARAM_TYPE_REG_PETRI = 32,
        PARAM_TYPE_REG_GOLD = 33,
        PARAM_TYPE_DEF_LOW_FIRE = 34,
        PARAM_TYPE_DEF_LOW_ICE = 35,
        PARAM_TYPE_DEF_LOW_THUNDER = 36,
        PARAM_TYPE_DEF_LOW_HOLY = 37,
        PARAM_TYPE_DEF_LOW_DARK = 38,
        PARAM_TYPE_DEF_LOW_ATK = 39,
        PARAM_TYPE_DEF_LOW_DEF = 40,
        PARAM_TYPE_DEF_LOW_M_ATK = 41,
        PARAM_TYPE_DEF_LOW_M_DEF = 42,
        PARAM_TYPE_SPECIAL = 43,
        PARAM_TYPE_DOWN_POWER = 44,
        PARAM_TYPE_DAMAGE_UP = 45,
        PARAM_TYPE_STUN_UP = 46,
        PARAM_TYPE_OCD_UP = 47,
        PARAM_TYPE_BLOW_UP = 48,
        PARAM_TYPE_CHANCE_UP = 49,
        PARAM_TYPE_TIRED_UP = 50,
        PARAM_TYPE_HEAL_HP_UP = 51,
        PARAM_TYPE_HEAL_STAMINA_UP = 52,
        PARAM_TYPE_DEF_EROSION = 53,
        PARAM_TYPE_DEF_ITEM_SEAL = 54,
    };
    enum
    {
        CORRECT_TYPE_ADD = 0,
        CORRECT_TYPE_RATE = 1,
    };
public:
    class MyDTI;
    class cParamData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cParamData : public MtObject
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
        cParamData();
        virtual ~cParamData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool save(MtDataWriter& w);
        bool load(MtDataReader& r);
    public:
        s32 mLv;  // offset: 0x8
        s32 mParam;  // offset: 0xc
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
    cAbilityParam();
    virtual ~cAbilityParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool save(MtDataWriter& w);
    bool load(MtDataReader& r, nCollisionUtil::LoadBuffer& buffer);
    u32 getAllocateSize() const;
    s32 getParamType() const;
    s32 getCorrectType() const;
    bool getParam(s32 Lv, s32& param) const;
    cParamData* getParamData(u32);
    cAbilityParam& operator=(const cAbilityParam& source);
private:
    s32 mParamType;  // offset: 0x8
    s32 mCorrectType;  // offset: 0xc
    MtTypedArray<cParamData> mParamDataArray;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cAbilityData : public MtObject
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
    cAbilityData();
    virtual ~cAbilityData();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void createPropertyCommon(MtPropertyList& s);
    bool save(MtDataWriter& w);
    bool load(MtDataReader& r, nCollisionUtil::LoadBuffer& buffer);
    u32 getAllocateSize() const;
    const cAbilityParam* getAbilityParam(s32 index) const;
    u32 getParamNum() const;
    cAbilityData& operator=(const cAbilityData& source);
private:
    MtTypedArray<cAbilityParam> mParamArray;  // offset: 0x8
public:
    static MyDTI DTI;
};

class rAbilityList : public cResource
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
    rAbilityList();
    virtual ~rAbilityList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    const MtTypedArray<cAbilityData>& getDataList() const;
    void setDataList(const MtArray& list);
    const cAbilityData* getData(s32 index);
protected:
    MtTypedArray<cAbilityData> mDataList;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u8 DATA_VERSION = 8;
};

// Inline, no code of its own: checked where it is inlined.
inline cAbilityData::cAbilityData() {
    this->mParamArray.::MtArray::mAutoDelete = true;
}

// Inline, no code of its own: checked where it is inlined.
inline cAbilityParam::cAbilityParam() {
    this->mParamType = static_cast<s32>(0);
    this->mCorrectType = static_cast<s32>(0);
    this->mParamDataArray.::MtArray::mAutoDelete = true;
}

// Inline, no code of its own: checked where it is inlined.
inline cAbilityParam::cParamData::cParamData() {
    this->mLv = static_cast<s32>(1);
    this->mParam = static_cast<s32>(0);
}
