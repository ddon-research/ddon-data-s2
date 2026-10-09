#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { class Vector4; } } } }

// Declarations
class cSoundEffect;

// Type aliases from DWARF
using f32 = float;

class cSoundEffect
{
public:
    using SoundVector = sce::Vectormath::Simd::Aos::Vector4;
public:
    cSoundEffect();
    virtual ~cSoundEffect();
protected:
    SoundVector zero();
    SoundVector replicate(const f32 val);
    SoundVector load(f32* pVal);
    SoundVector multiple(const SoundVector val1, const SoundVector val2);
    SoundVector abs(const SoundVector val);
    SoundVector max(const SoundVector val1, const SoundVector val2);
    void store(f32* pDst, const SoundVector src);
    SoundVector clamp(const SoundVector src, const SoundVector min, const SoundVector max);
};
