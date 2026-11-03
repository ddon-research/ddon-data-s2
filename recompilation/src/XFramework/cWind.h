#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtLogisticMap.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"

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

inline void* cWind::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline f32 cWind::getDirPitchCycle() const {
    return this->mDirPitch.mCycle;
}

inline f32 cWind::getDirPitchCycleAdd() const {
    return this->mDirPitch.mCycleAdd;
}

inline f32 cWind::getDirPitchAmpValue() const {
    return this->mDirPitch.::MtLogisticMap::mAmpValue;
}

inline f32 cWind::getDirPitchAmpRate() const {
    return this->mDirPitch.::MtLogisticMap::mAmpRate;
}

inline void cWind::setDirPitchCycle(f32 Cycle) {
    this->mDirPitch.mCycle = Cycle;
}

inline void cWind::setDirPitchCycleAdd(f32 CycleAdd) {
    this->mDirPitch.mCycleAdd = CycleAdd;
}

inline void cWind::setDirPitchAmpValue(f32 AmpValue) {
    if (0.01f > AmpValue) {
        this->mDirPitch.::MtLogisticMap::mAmpValue = 0.01f;
    } else {
        if (AmpValue > 0.99f) {
            this->mDirPitch.::MtLogisticMap::mAmpValue = 0.99f;
        } else {
            this->mDirPitch.::MtLogisticMap::mAmpValue = AmpValue;
        }
    }
}

inline void cWind::setDirPitchAmpRate(f32 AmpRate) {
    if (3.57f > AmpRate) {
        this->mDirPitch.::MtLogisticMap::mAmpRate = 3.57f;
    } else {
        if (AmpRate > 4.0f) {
            this->mDirPitch.::MtLogisticMap::mAmpRate = 4.0f;
        } else {
            this->mDirPitch.::MtLogisticMap::mAmpRate = AmpRate;
        }
    }
}

inline f32 cWind::getDirYawCycle() const {
    return this->mDirYaw.mCycle;
}

inline f32 cWind::getDirYawCycleAdd() const {
    return this->mDirYaw.mCycleAdd;
}

inline f32 cWind::getDirYawAmpValue() const {
    return this->mDirYaw.::MtLogisticMap::mAmpValue;
}

inline f32 cWind::getDirYawAmpRate() const {
    return this->mDirYaw.::MtLogisticMap::mAmpRate;
}

inline void cWind::setDirYawCycle(f32 Cycle) {
    this->mDirYaw.mCycle = Cycle;
}

inline void cWind::setDirYawCycleAdd(f32 CycleAdd) {
    this->mDirYaw.mCycleAdd = CycleAdd;
}

inline void cWind::setDirYawAmpValue(f32 AmpValue) {
    if (0.01f > AmpValue) {
        this->mDirYaw.::MtLogisticMap::mAmpValue = 0.01f;
    } else {
        if (AmpValue > 0.99f) {
            this->mDirYaw.::MtLogisticMap::mAmpValue = 0.99f;
        } else {
            this->mDirYaw.::MtLogisticMap::mAmpValue = AmpValue;
        }
    }
}

inline void cWind::setDirYawAmpRate(f32 AmpRate) {
    if (3.57f > AmpRate) {
        this->mDirYaw.::MtLogisticMap::mAmpRate = 3.57f;
    } else {
        if (AmpRate > 4.0f) {
            this->mDirYaw.::MtLogisticMap::mAmpRate = 4.0f;
        } else {
            this->mDirYaw.::MtLogisticMap::mAmpRate = AmpRate;
        }
    }
}

inline f32 cWind::getSpeedCycle() const {
    return this->mSpeed.mCycle;
}

inline f32 cWind::getSpeedCycleAdd() const {
    return this->mSpeed.mCycleAdd;
}

inline f32 cWind::getSpeedAmpValue() const {
    return this->mSpeed.::MtLogisticMap::mAmpValue;
}

inline f32 cWind::getSpeedAmpRate() const {
    return this->mSpeed.::MtLogisticMap::mAmpRate;
}

inline void cWind::setSpeedCycle(f32 Cycle) {
    this->mSpeed.mCycle = Cycle;
}

inline void cWind::setSpeedCycleAdd(f32 CycleAdd) {
    this->mSpeed.mCycleAdd = CycleAdd;
}

inline void cWind::setSpeedAmpValue(f32 AmpValue) {
    if (0.01f > AmpValue) {
        this->mSpeed.::MtLogisticMap::mAmpValue = 0.01f;
    } else {
        if (AmpValue > 0.99f) {
            this->mSpeed.::MtLogisticMap::mAmpValue = 0.99f;
        } else {
            this->mSpeed.::MtLogisticMap::mAmpValue = AmpValue;
        }
    }
}

inline void cWind::setSpeedAmpRate(f32 AmpRate) {
    if (3.57f > AmpRate) {
        this->mSpeed.::MtLogisticMap::mAmpRate = 3.57f;
    } else {
        if (AmpRate > 4.0f) {
            this->mSpeed.::MtLogisticMap::mAmpRate = 4.0f;
        } else {
            this->mSpeed.::MtLogisticMap::mAmpRate = AmpRate;
        }
    }
}
