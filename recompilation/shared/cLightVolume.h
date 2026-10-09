#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class cDraw;
class uLight;

// Declarations
class cLightVolume;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;

class cLightVolume
{
public:
    cLightVolume();
    virtual ~cLightVolume() {}
    virtual void update(uLight*) = 0;  // vtable slot 2
    void draw(cDraw* pdraw, uLight* light);
    static cLightVolume* CreateLightVolume(uLight* light);
    void beginCBLightVolumeReduce(cDraw* pdraw, f32 Disable);
    static void* operator new(size_t s);
    static void operator delete(void* padr);
    static void* operator new[](size_t s);
    static void operator delete[](void* padr);
private:
    virtual bool isCulling(cDraw* pdraw, uLight* light);  // vtable slot 3
    virtual void drawVolume(cDraw*, uLight*, bool) = 0;  // vtable slot 4
};
