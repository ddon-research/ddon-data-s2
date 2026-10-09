#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct MtFloat2;
struct MtFloat3;
class sAIPawnTalkMgr;

// Declarations
class MtRandom;

// Type aliases from DWARF
using f32 = float;
using f64 = double;
using u32 = unsigned int;

// Functions the classes below befriend, declared first
namespace nDDOMath { f32 random(f32 min, f32 max); }

class MtRandom
{
    // inferred: nDDOMath::random calls MtRandom::nrand
    friend f32 nDDOMath::random(f32 min, f32 max);
    // inferred: sAIPawnTalkMgr::lotAIPawnTalkWaitFrame calls MtRandom::nrand
    friend class sAIPawnTalkMgr;
public:
    MtRandom();
    MtRandom(u32 seed);
    void init(u32 seed);
    f32 randomF32();
    f64 randomF64();
    u32 randomU32();
    MtFloat2 random2D();
    MtFloat2 randomDisc();
    MtFloat3 randomHemisphericalSurface();
    MtFloat3 randomSphericalSurface();
    MtFloat3 randomSphericalBody();
    f32 randomNormBM(f32 sigma, f32 median);
    f32 randomNorm();
    static MtRandom& getInstance();
private:
    u32 nrand();
private:
    u32 mRandomX;  // offset: 0x0
    u32 mRandomY;  // offset: 0x4
    u32 mRandomZ;  // offset: 0x8
    u32 mRandomW;  // offset: 0xc
    static MtRandom instance;
};
