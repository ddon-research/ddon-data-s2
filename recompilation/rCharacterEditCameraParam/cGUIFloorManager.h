#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtUI;
class MtVector3;
class rGUIMapSetting;

// Declarations
class cGUIFloorManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIFloorManager : public MtObject
{
public:
    class MyDTI;
    class cParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cParam : public MtObject
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
        cParam();
        virtual ~cParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setResource(rGUIMapSetting* pRes);
        rGUIMapSetting* getResource();
        void setFloorBaseIdOfs(s32 sFloorBaseIdOfs);
        s32 getFloorBaseIdOfs();
        void setFloorGroupNo(s32 id);
        s32 getFloorGroupNo();
    private:
        rGUIMapSetting* mpRes;  // offset: 0x8
        s32 mFloorBaseIdOfs;  // offset: 0x10
        s32 mFloorGroupNo;  // offset: 0x14
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
    cGUIFloorManager();
    virtual ~cGUIFloorManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setPartsIndex(u32 index);
    void release();
    void add(rGUIMapSetting* pRes, s32 gropuNo);
    void clear();
    bool isEnableFloor();
    rGUIMapSetting* getCurrentRes();
    s32 getFloorId();
    void setFloorId(s32 sFloorId);
    const MtFloat2& getCenter(u32 idx);
    u32 getTextureNumX(u32 idx);
    u32 getTextureNumY(u32 idx);
    f32 getFoundationScale(u32 idx);
    f32 getOffsetPosX(u32 idx);
    f32 getOffsetPosY(u32 idx);
    s32 getFloorBaseId(u32 idx, bool bOfs);
    u32 getFloorBaseSizeId(u32 idx);
    u32 getPartsLength();
    u32 getHouseTopNum(u32 idx);
    const MtRect& getMapSize(u32 idx);
    s32 getFloorGroupNo(u32 idx);
    s32 getHitPartsIdx();
    s32 getHitFloorGroupNo();
    virtual void update();  // vtable slot 6
    void execHitCheck();
    void execHitPartyCheck();
    void execHitNpcCheck();
    s32 getFloorIdFromPos(const MtVector3& vPos, u32& uHitPartsIdx, u32& uHitIdx, s32& uHitGroupNo, s32 sPartsIdx);
    void setFloorBaseIdOfs(u32 idx, s32 sFloorBaseIdOfs);
    bool isWarpDungeon();
private:
    rGUIMapSetting* getResPrivate(u32 idx);
private:
    MtTypedArray<cParam> mParamArray;  // offset: 0x8
    u32 mPartsIndex;  // offset: 0x28
    rGUIMapSetting* mpCurrentRes;  // offset: 0x30
    s32 mFloorId;  // offset: 0x38
    u32 mHitPartsIdx;  // offset: 0x3c
    u32 mHitIdx;  // offset: 0x40
    s32 mHitGroupNo;  // offset: 0x44
    bool mIsWarpDungeon;  // offset: 0x48
public:
    static MyDTI DTI;
    static const u32 BIT_SIZE = 256;
    static const s32 DISABLE_FLOOR;
    static const s32 DISABLE_GROUP;
    static const u32 DISABLE_FLOORIDX = 4294967295;
    static const u32 DISABLE_INDEX = 4294967295;
};

// Inline, no code of its own: checked where it is inlined.
inline cGUIFloorManager::cParam::cParam() {
    this->mpRes = static_cast<rGUIMapSetting*>(nullptr);
    this->mFloorBaseIdOfs = static_cast<s32>(0);
    this->mFloorGroupNo = static_cast<s32>(-1);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline s32 cGUIFloorManager::cParam::getFloorGroupNo() {
    return this->mFloorGroupNo;
}
