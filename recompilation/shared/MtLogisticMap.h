#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class cWind;

// Declarations
class MtLogisticMap;
class MtLogisticMapCycle;

// Type aliases from DWARF
using f32 = float;

class MtLogisticMap
{
    // inferred: cWind::getDirPitchAmpValue names cWind::mDirPitch.::MtLogisticMap::mAmpValue
    friend class cWind;
public:
    MtLogisticMap();
    void init();
    f32 updateAmpValue();
    f32 getAmpValue() const;
    void setAmpValue(f32 AmpValue);
    f32 getAmpRate() const;
    void setAmpRate(f32 AmpRate);
private:
    f32 mAmpValue;  // offset: 0x0
    f32 mAmpRate;  // offset: 0x4
};

class MtLogisticMapCycle : public MtLogisticMap
{
    // inferred: cWind::getDirPitchCycle names cWind::mDirPitch.mCycle
    friend class cWind;
public:
    MtLogisticMapCycle();
    f32 update(f32 DeltaTime);
    f32 getCycle() const;
    void setCycle(f32 Cycle);
    f32 getCycleAdd() const;
    void setCycleAdd(f32 CycleAdd);
private:
    f32 mCycle;  // offset: 0x8
    f32 mCycleAdd;  // offset: 0xc
};
