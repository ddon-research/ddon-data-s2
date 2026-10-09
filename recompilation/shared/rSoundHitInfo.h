#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class rSoundHitInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rSoundHitInfo : public cResource
{
public:
    enum
    {
        ATTACK_CATEGORY_SLASH_NONE = 0,
        ATTACK_CATEGORY_SLASH_NOT_EFFECTIVE = 1,
        ATTACK_CATEGORY_SLASH_S = 2,
        ATTACK_CATEGORY_SLASH_M = 3,
        ATTACK_CATEGORY_SLASH_L = 4,
        ATTACK_CATEGORY_SLASH_LL = 5,
        ATTACK_CATEGORY_SLASH_G_S = 6,
        ATTACK_CATEGORY_SLASH_G_M = 7,
        ATTACK_CATEGORY_SLASH_G_L = 8,
        ATTACK_CATEGORY_SLASH_G_LL = 9,
        ATTACK_CATEGORY_STRIKE_S = 10,
        ATTACK_CATEGORY_STRIKE_M = 11,
        ATTACK_CATEGORY_STRIKE_L = 12,
        ATTACK_CATEGORY_STRIKE_LL = 13,
        ATTACK_CATEGORY_STRIKE_G_S = 14,
        ATTACK_CATEGORY_STRIKE_G_M = 15,
        ATTACK_CATEGORY_STRIKE_G_L = 16,
        ATTACK_CATEGORY_STRIKE_G_LL = 17,
        ATTACK_CATEGORY_SHOOT_NONE = 18,
        ATTACK_CATEGORY_SHOOT_NOT_EFFECTIVE = 19,
        ATTACK_CATEGORY_SHOOT_S = 20,
        ATTACK_CATEGORY_SHOOT_M = 21,
        ATTACK_CATEGORY_SHOOT_L = 22,
        ATTACK_CATEGORY_SHOOT_LL = 23,
        ATTACK_CATEGORY_NONE = 24,
        ATTACK_CATEGORY_NONE_GOOD = 25,
        ATTACK_CATEGORY_MAX = 26,
    };
public:
    class MyDTI;
    class cSoundHitInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cSoundHitInfo : public MtObject
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
        cSoundHitInfo();
        virtual ~cSoundHitInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void copy(rSoundHitInfo::cSoundHitInfo* pSrc, u32 version);
        bool load(MtDataReader& in);
        bool save(MtDataWriter& out);
        s32 getBody() const;
        s32 getBone() const;
        s32 getIron() const;
        s32 getStone() const;
        s32 getWood() const;
        s32 getWater() const;
        s32 getSmoke() const;
        s32 getAalche() const;
        s32 getIce() const;
        s32 getWeek1() const;
        s32 getWeek2() const;
        s32 getEtc00() const;
        s32 getEtc01() const;
        s32 getEtc02() const;
        s32 getEtc03() const;
        s32 getEtc04() const;
        s32 getEtc05() const;
        s32 getEtc06() const;
    private:
        s32 mBody;  // offset: 0x8
        s32 mBone;  // offset: 0xc
        s32 mIron;  // offset: 0x10
        s32 mStone;  // offset: 0x14
        s32 mWood;  // offset: 0x18
        s32 mWater;  // offset: 0x1c
        s32 mSmoke;  // offset: 0x20
        s32 mAalche;  // offset: 0x24
        s32 mIce;  // offset: 0x28
        s32 mWeek1;  // offset: 0x2c
        s32 mWeek2;  // offset: 0x30
        s32 mEtc00;  // offset: 0x34
        s32 mEtc01;  // offset: 0x38
        s32 mEtc02;  // offset: 0x3c
        s32 mEtc03;  // offset: 0x40
        s32 mEtc04;  // offset: 0x44
        s32 mEtc05;  // offset: 0x48
        s32 mEtc06;  // offset: 0x4c
    public:
        static MyDTI DTI;
        static const u32 DATA_VERSION = 5;
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
    rSoundHitInfo();
    virtual ~rSoundHitInfo();
    void releaseWork();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    cSoundHitInfo* getHitInfo(u32 AttackType, u32 AttackLevel, u32 AttackReaction, bool isThrust);
public:
    cSoundHitInfo* mpArrayData;  // offset: 0x70
    u32 mArrayDataNum;  // offset: 0x78
    u32 mVersion;  // offset: 0x7c
    static MyDTI DTI;
    static const u32 CATEGORY_NUM = 6;
private:
    static const s32 NativeFileMagic = 4802643;
    static const s32 NativeVersion = 5;
};

// Inline, no code of its own: checked where it is inlined.
inline rSoundHitInfo::cSoundHitInfo::cSoundHitInfo() {
    this->mEtc05 = static_cast<s32>(-1);
    this->mEtc06 = static_cast<s32>(-1);
    this->mEtc03 = static_cast<s32>(-1);
    this->mEtc04 = static_cast<s32>(-1);
    this->mEtc01 = static_cast<s32>(-1);
    this->mEtc02 = static_cast<s32>(-1);
    this->mWeek2 = static_cast<s32>(-1);
    this->mEtc00 = static_cast<s32>(-1);
    this->mIce = static_cast<s32>(-1);
    this->mWeek1 = static_cast<s32>(-1);
    this->mSmoke = static_cast<s32>(-1);
    this->mAalche = static_cast<s32>(-1);
    this->mWood = static_cast<s32>(-1);
    this->mWater = static_cast<s32>(-1);
    this->mIron = static_cast<s32>(-1);
    this->mStone = static_cast<s32>(-1);
    this->mBody = static_cast<s32>(-1);
    this->mBone = static_cast<s32>(-1);
}
