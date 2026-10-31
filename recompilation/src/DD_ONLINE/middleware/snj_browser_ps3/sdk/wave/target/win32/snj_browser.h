#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace sce { namespace Gnm { class DataFormat; } }
namespace sce { namespace Gnm { class Texture; } }

// Type aliases from DWARF
using SNJ_BROWSER_D3DFORMAT = sce::Gnm::DataFormat;
using SNJ_BROWSER_TEXTURE = sce::Gnm::Texture;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;

typedef struct
{
public:
    int tw;  // offset: 0x0
    int th;  // offset: 0x4
    void* dev;  // offset: 0x8
    void* tex;  // offset: 0x10
    void* vtxshd;  // offset: 0x18
    void* pixshd;  // offset: 0x20
    void* vtxdcl;  // offset: 0x28
    uint32_t port_handle;  // offset: 0x30
} SNJ_BROWSER_DIRECTX;

typedef struct
{
public:
    int filsiz;  // offset: 0x0
    int imgw;  // offset: 0x4
    int imgh;  // offset: 0x8
    int fntw;  // offset: 0xc
    int fnth;  // offset: 0x10
    int fntmgn;  // offset: 0x14
    int fntdatidx[2];  // offset: 0x18
} SNJ_BROWSER_FONTINFO;

typedef struct
{
public:
    bool(*CreateTexture)(int, int, SNJ_BROWSER_D3DFORMAT, SNJ_BROWSER_TEXTURE* *);  // offset: 0x0
    void(*ReleaseTexture)(SNJ_BROWSER_TEXTURE*);  // offset: 0x8
    bool(*CreateVertexShader)(void*);  // offset: 0x10
    bool(*CreateFragmentShader)(void*);  // offset: 0x18
    void(*ReleaseVertexShader)();  // offset: 0x20
    void(*ReleaseFragmentShader)();  // offset: 0x28
    void(*SetVertexShader)();  // offset: 0x30
    void(*SetFragmentShader)();  // offset: 0x38
} SNJ_BROWSER_PS4_RENDERDEVICE;
