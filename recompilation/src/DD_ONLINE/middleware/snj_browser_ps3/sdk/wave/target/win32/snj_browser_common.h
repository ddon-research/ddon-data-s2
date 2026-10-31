#pragma once

#include <cstdint>
#include <cstddef>

typedef struct
{
public:
    int w;  // offset: 0x0
    int h;  // offset: 0x4
    int byt;  // offset: 0x8
    int ptc;  // offset: 0xc
    int fmt;  // offset: 0x10
    int siz;  // offset: 0x14
    int typ;  // offset: 0x18
    void* dathnd;  // offset: 0x20
    int dattyp;  // offset: 0x28
    unsigned char* datptr;  // offset: 0x30
    int datlck;  // offset: 0x38
    int datcre;  // offset: 0x3c
    unsigned char* msk;  // offset: 0x40
    int mskptc;  // offset: 0x48
} SNJ_BROWSER_BITMAP;

typedef struct
{
public:
    int x;  // offset: 0x0
    int y;  // offset: 0x4
    int w;  // offset: 0x8
    int h;  // offset: 0xc
} SNJ_BROWSER_RECT;

typedef struct
{
public:
    SNJ_BROWSER_RECT viw;  // offset: 0x0
    unsigned int hepsiz;  // offset: 0x10
    void* hepptr;  // offset: 0x18
    void* d3ddev;  // offset: 0x20
    void* d3dfnt[2];  // offset: 0x28
    int d3dfntfmt;  // offset: 0x38
    void* d3dscr;  // offset: 0x40
    unsigned short sysflg;  // offset: 0x48
    unsigned short client_type;  // offset: 0x4a
    void(*ntfprc)(int);  // offset: 0x50
    int(*imeprcini)(const void*);  // offset: 0x58
    void(*imeprcmov)();  // offset: 0x60
    void(*imeprcdrw)();  // offset: 0x68
    int(*errprcini)(int, int);  // offset: 0x70
    void(*errprcmov)();  // offset: 0x78
    void(*errprcdrw)();  // offset: 0x80
    int(*jsdprcini)(const void*);  // offset: 0x88
    void(*jsdprcmov)();  // offset: 0x90
    void(*jsdprcdrw)();  // offset: 0x98
    unsigned int(*kbdmodprc)();  // offset: 0xa0
    const int* sclsizlst;  // offset: 0xa8
    int sclnum;  // offset: 0xb0
    int sclidxdef;  // offset: 0xb4
    const char* usragt;  // offset: 0xb8
    char rootDirectory[128];  // offset: 0xc0
    unsigned int inpchrset;  // offset: 0x140
} SNJ_BROWSER_SYSINFO;
