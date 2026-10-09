#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"
#include "rSoundRequest.h"
#include "rSoundStreamRequest.h"
#include "rZone.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;
class rSoundRequest;
class rSoundStreamRequest;
class rZone;

// Declarations
class rSoundAreaInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rSoundAreaInfo : public cResource
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
    u32 getMagicHeader() const;
    rSoundAreaInfo();
    virtual ~rSoundAreaInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    void setSndZoneOcclusion(rZone*);
    void setSndZoneGenerator(rZone*);
    void setSndZoneTrigger(rZone*);
    rZone* getSndZoneOcclusion();
    rZone* getSndZoneGenerator();
    rZone* getSndZoneTrigger();
    void setAttributeRes(rSoundRequest* p, u32 index);
    void setAttributeResFlag(bool, u32);
    rSoundRequest* getAttributeRes(u32 index);
    rSoundRequest* getAttributeResToScrAttr(u32 scrAttr);
    f32 getSoundEqLengthNo(u32 no);
    bool isAmbStage();
    u32 getNormalBgmNo();
    u32 getDayBgmNo();
    u32 getNightBgmNo();
    bool isCycleStage();
    u32 getCycleBgmNo();
    u32 getBtlBgmNo();
    u32 getBtlBgmOutroNo();
    rSoundRequest* getSndAmbientRes();
    rSoundStreamRequest* getSndBgmRes();
    rSoundStreamRequest* getSndCycleBgmRes();
    rSoundStreamRequest* getSndBtlBgmRes();
    void setSndBtlBgmNo(u32);
    void setSndBtlBgmOutroNo(u32);
public:
    s32 mStageNo;  // offset: 0x70
    s32 mAreaNo;  // offset: 0x74
    bool mIsAmb;  // offset: 0x78
    u32 mBgmNo;  // offset: 0x7c
    u32 mDayBgmNo;  // offset: 0x80
    u32 mNightBgmNo;  // offset: 0x84
    bool mIsSecond;  // offset: 0x88
    bool mIsAmb2;  // offset: 0x89
    u32 mBgmNo2;  // offset: 0x8c
    u32 mDayBgmNo2;  // offset: 0x90
    u32 mNightBgmNo2;  // offset: 0x94
    u32 mCycleBgmNo;  // offset: 0x98
    u32 mBtlBgmNo;  // offset: 0x9c
    u32 mBtlBgmOutroNo;  // offset: 0xa0
    bool mIsCycle;  // offset: 0xa4
    f32 mEqLength[4];  // offset: 0xa8
    res_ptr<rZone> mpSndZoneRes[3];  // offset: 0xb8
    bool mIsAttribute[32];  // offset: 0xd0
    res_ptr<rSoundRequest> mpAttributeSTQRes[32];  // offset: 0xf0
    res_ptr<rSoundRequest> mpAmbientRes;  // offset: 0x1f0
    res_ptr<rSoundStreamRequest> mpBgmSTQRes;  // offset: 0x1f8
    res_ptr<rSoundStreamRequest> mpCycleBgmSTQRes;  // offset: 0x200
    res_ptr<rSoundStreamRequest> mpBtlBgmSTQRes;  // offset: 0x208
    static MyDTI DTI;
    static const u32 DATA_VERSION = 15;
    static const u32 ATTRIBUTE_NUM_MAX = 32;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 rSoundAreaInfo::getNormalBgmNo() {
    return this->mBgmNo;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 rSoundAreaInfo::getDayBgmNo() {
    return this->mDayBgmNo;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 rSoundAreaInfo::getNightBgmNo() {
    return this->mNightBgmNo;
}
