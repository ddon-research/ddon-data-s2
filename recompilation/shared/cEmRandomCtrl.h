#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace nObjCollision { struct stDmageVecInfo; }
class uCharacter;

// Declarations
class cEmRandomCtrl;

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

class cEmRandomCtrl
{
public:
    cEmRandomCtrl();
    void randomDamageVec(nObjCollision::stDmageVecInfo& vecInfo, uCharacter* pEnemy);
    f32 makeRandomDownTime(uCharacter* pEnemy);
    f32 makeRandomErosionTime(f32 time, uCharacter* pEnemy);
    f32 makeRandomErosionScale(f32 scaleMax, f32 scaleMin, uCharacter* pEnemy);
private:
    void init(u32 seed);
    u32 randomU32();
    f32 randomF32();
    u32 nrand();
private:
    u32 mRandomX;  // offset: 0x0
    u32 mRandomY;  // offset: 0x4
    u32 mRandomZ;  // offset: 0x8
    u32 mRandomW;  // offset: 0xc
};
