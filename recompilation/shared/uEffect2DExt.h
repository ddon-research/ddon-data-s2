#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "uEffect2D.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
class cEfcHandle;
class cParticle2DGenerator;
class uDDOModel;

// Declarations
class uEffect2DExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class uEffect2DExt : public uEffect2D
{
public:
    class MyDTI;
    struct CORRECT_COLOR_PARAM;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct CORRECT_COLOR_PARAM
    {
    public:
        struct ZONE_PARAM;
    public:
        struct ZONE_PARAM
        {
        public:
            ZONE_PARAM();
            static void* operator new(size_t);
            static void operator delete(void*);
            static void* operator new[](size_t s);
            static void operator delete[](void* padr);
        public:
            u32 mColorR : 16;  // offset: 0x0
            u32 mColorG : 16;  // offset: 0x0
            u32 mColorB : 16;  // offset: 0x4
            u32 mColorA : 16;  // offset: 0x4
            u32 mIntensity;  // offset: 0x8
            u32 mColorBlend : 16;  // offset: 0xc
            u32 mIntensityBlend : 16;  // offset: 0xc
            u32 mMixColorR : 16;  // offset: 0x10
            u32 mMixColorG : 16;  // offset: 0x10
            u32 mMixColorB : 16;  // offset: 0x14
            u32 mMixColorA : 16;  // offset: 0x14
            u32 mMixIntensity;  // offset: 0x18
            u32 mMixColorBlend : 16;  // offset: 0x1c
            u32 mMixIntensityBlend : 16;  // offset: 0x1c
            u32 mCorrectType : 4;  // offset: 0x20
            u32 mFlag : 1;  // offset: 0x20
            u32 mUseSkyColor : 1;  // offset: 0x20
            u32 mUseMixColor : 1;  // offset: 0x20
            u32 mDummy : 9;  // offset: 0x20
        };
    public:
        CORRECT_COLOR_PARAM();
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
    public:
        ZONE_PARAM* mpZoneParam;  // offset: 0x0
        u32 mZoneParamNum;  // offset: 0x8
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
    uEffect2DExt();
    virtual ~uEffect2DExt();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    uEffect2DExt* getNextUnit();
    void setNextUnit(uEffect2DExt*);
    uEffect2DExt* getGroupNextUnit();
    void setGroupNextUnit(uEffect2DExt*);
    u64 getUniqueID();
    void setUniqueID(u64);
    u64 getGroupID();
    void setGroupID(u64);
    u64 getGroupNo();
    void setGroupNo(u8 no);
    cEfcHandle* getEfcHandle();
    virtual void updateParentPtr();  // vtable slot 40
    void setHitStopMode(bool Flg);
    bool getHitStopMode();
    void setWorkRateMode(bool Flg);
    bool getWorkRateMode();
    void applyCustomWorkRateType(u32);
    void setCustomWorkRateType(u32 Data);
    u32 getCustomWorkRateType();
    void setParentActor(uDDOModel* pParent, bool Flg0, bool Flg1);
    uDDOModel* getParentActor();
    void setUnitEndType(u32 type);
    u32 getUnitEndType();
    f32 getDeltaTimeCoefEx();
    void setDeltaTimeCoefEx(f32 DeltaTimeCoef);
    void setColorUpdateFlag(bool flag);
    bool getColorUpdateFlag();
    void setCameraEventOffFlag(bool flag);
    bool setCameraEventOffFlag() const;
protected:
    void buildCorrectColorFromZone();
    void updateCorrectColor();
    virtual bool createGenerator();  // vtable slot 34
    virtual void correctColorIntensity(cParticle2DGenerator* pGenerator, MtColor* pColor, u32 ColorNum, u32* pIntensity, const MtFloat2& Pos);  // vtable slot 36
private:
    bool getZoneCheckPos(MtVector3& ckPos);
    void storeColorParamFromZone(u32 no, const MtVector3& ckPos, u32 correctType);
    void updateCorrectColorParam(u32 no);
public:
    void setCreateCost(u32 Cost);
    u32 getCreateCost();
protected:
    uEffect2DExt* mpNext;  // offset: 0x1b8
    u64 mUniqueID;  // offset: 0x1c0
    uEffect2DExt* mpGroupNext;  // offset: 0x1c8
    u64 mGroupID;  // offset: 0x1d0
    cEfcHandle* mpHandle;  // offset: 0x1d8
    u8 mGroupNo;  // offset: 0x1e0
    uDDOModel* mpParentActor;  // offset: 0x1e8
    bool mHitStopMode;  // offset: 0x1f0
    bool mWorkRateMode;  // offset: 0x1f1
    u32 mCustomWorkRateType;  // offset: 0x1f4
    u32 mUnitEndType;  // offset: 0x1f8
    f32 mDeltaTimeCoefEx;  // offset: 0x1fc
private:
    u32 mCameraEventOff : 1;  // offset: 0x200
    u32 mReserve : 31;  // offset: 0x200
    CORRECT_COLOR_PARAM mCorrectColorParam;  // offset: 0x208
    bool mColorUpdate;  // offset: 0x218
    f32 mColorUpdateTimer;  // offset: 0x21c
    f32 mColorUpdateTime;  // offset: 0x220
    bool mZoneUpdateFlag;  // offset: 0x224
    u32 mCreateCost;  // offset: 0x228
public:
    static MyDTI DTI;
};
