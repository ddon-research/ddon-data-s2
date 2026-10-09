#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtLogisticMap.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtLogisticMapCycle;
class MtProperty;
class MtPropertyList;
class MtRangeF;
class MtUI;
class MtVector3;

// Declarations
class cWind;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cWind : public MtObject
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
    cWind();
    virtual ~cWind();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    MtVector3 move(f32 DeltaTime);
    void setBaseDir(const MtVector3&);
    const MtVector3& getWindVec() const;
    MtVector3 getWindDir() const;
    f32 getWindSpeed() const;
    void setDummyVec(const MtVector3&);
    void setDummyF32(f32);
    f32 getDirPitchCycle() const;
    f32 getDirPitchCycleAdd() const;
    f32 getDirPitchAmpValue() const;
    f32 getDirPitchAmpRate() const;
    MtRangeF getDirPitchParam() const;
    void setDirPitchCycle(f32 Cycle);
    void setDirPitchCycleAdd(f32 CycleAdd);
    void setDirPitchAmpValue(f32 AmpValue);
    void setDirPitchAmpRate(f32 AmpRate);
    void setDirPitchParam(const MtRangeF& Param);
    void setDirPitch(const MtRangeF& Param, f32 Cycle, f32 CycleAdd, f32 AmpValue, f32 AmpRate);
    f32 getDirYawCycle() const;
    f32 getDirYawCycleAdd() const;
    f32 getDirYawAmpValue() const;
    f32 getDirYawAmpRate() const;
    MtRangeF getDirYawParam() const;
    void setDirYawCycle(f32 Cycle);
    void setDirYawCycleAdd(f32 CycleAdd);
    void setDirYawAmpValue(f32 AmpValue);
    void setDirYawAmpRate(f32 AmpRate);
    void setDirYawParam(const MtRangeF& Param);
    void setDirYaw(const MtRangeF& Param, f32 Cycle, f32 CycleAdd, f32 AmpValue, f32 AmpRate);
    f32 getSpeedCycle() const;
    f32 getSpeedCycleAdd() const;
    f32 getSpeedAmpValue() const;
    f32 getSpeedAmpRate() const;
    MtRangeF getSpeedParam() const;
    void setSpeedCycle(f32 Cycle);
    void setSpeedCycleAdd(f32 CycleAdd);
    void setSpeedAmpValue(f32 AmpValue);
    void setSpeedAmpRate(f32 AmpRate);
    void setSpeedParam(const MtRangeF& Param);
    void setSpeed(const MtRangeF& Param, f32 Cycle, f32 CycleAdd, f32 AmpValue, f32 AmpRate);
private:
    MtVector3 mWindVec;  // offset: 0x10
    MtVector3 mBaseDir;  // offset: 0x20
    MtLogisticMapCycle mDirPitch;  // offset: 0x30
    MtLogisticMapCycle mDirYaw;  // offset: 0x40
    MtLogisticMapCycle mSpeed;  // offset: 0x50
    f32 mDirPitchParamBase;  // offset: 0x60
    f32 mDirPitchParamAmp;  // offset: 0x64
    f32 mDirYawParamBase;  // offset: 0x68
    f32 mDirYawParamAmp;  // offset: 0x6c
    f32 mSpeedParamBase;  // offset: 0x70
    f32 mSpeedParamAmp;  // offset: 0x74
    u32 mWind3268;  // offset: 0x78
    u32 mWind326c;  // offset: 0x7c
public:
    static MyDTI DTI;
};
