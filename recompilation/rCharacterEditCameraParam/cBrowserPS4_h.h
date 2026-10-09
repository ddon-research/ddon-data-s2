#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtSynchronize.h"
#include "snj_browser.h"
#include "snj_browser_common.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtPoint;
class MtPropertyList;
class cBrowserApplicationTask;
class cBrowserRenderDevicePS4;

// Declarations
class cBrowserKeepString;
class cBrowserPS4;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SNJ_BROWSER_JSFUNC = void(*)(void*, void* *, void* *, void*);
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cBrowserKeepString : public MtObject
{
public:
    class MyDTI;
    struct stString;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stString
    {
    public:
        MT_CHAR mString[127];  // offset: 0x0
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
    cBrowserKeepString();
    cBrowserKeepString(u32 KeepMaxNum);
    virtual ~cBrowserKeepString();
    MT_CTSTR setString(MT_CTSTR String);
protected:
    void init();
    void finalize();
protected:
    MtCriticalSection mCS;  // offset: 0x8
    u32 mIndex;  // offset: 0x10
    u32 mKeepMaxNum;  // offset: 0x14
    stString* mpStringBuff;  // offset: 0x18
public:
    static MyDTI DTI;
    static const u32 MAX_KEEP_CHAR = 127;
};

class cBrowserPS4 : public MtObject
{
public:
    enum ValidDevice
    {
        VALID_DEVICE_MOUSE = 0,
        VALID_DEVICE_PAD = 1,
        VALID_DEVIDE_INVALID = 2,
    };
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
    void setPos(const int x, const int y);
private:
    void reset_member();
public:
    cBrowserPS4();
    virtual ~cBrowserPS4();
    int initialize(void* memptr, size_t memsiz, int x, int y, int vw, int vh, int tw, int th, unsigned int flg, int(*imeprcini)(const void*), void(*imeprcmov)(), void(*imeprcdrw)(), int(*errprcini)(int, int), void(*errprcmov)(), void(*errprcdrw)(), int(*jsdprcini)(const void*), void(*jsdprcmov)(), void(*jsdprcdrw)());
    void ime_exit(const char* str);
    void err_exit();
    void jsd_exit(int ret, char* iptres);
    void set_url(const char* url);
    void set_error_url(int knd, const char* url);
    void jump_url(const char* url);
    void goto_start_page();
    void goto_error_page(int knd);
    int pause_start();
    void pause_end();
    int call_task(int tskidx, const void* prm);
    void add_js_function(const char* fncnam, SNJ_BROWSER_JSFUNC fnc);
    int get_error_category(int typ, int knd);
    int get_error_flowtype(int typ, int knd);
    void move(const bool isControl, const bool isDispCursor);
    void draw();
    void close();
    void finalize();
    int finalize_wait();
    int reboot();
    int is_initialized();
    int is_game();
    int verify_string(const char* s);
    int get_using_memory();
    void call_js_function(const char* pFunctionStr);
    const char* get_user_agent();
    u32 checkValidDevice();
    bool checkInputPad();
    bool checkInputMouse();
    bool isMouseInBrowser(const MtPoint& pos);
    void quick_copy(void* param);
    bool setDrawBuffer(void* pDst, u32 pitch, u32 width, u32 height, u32 bpp);
    bool feedbackBuffer(void* pDst, u32 pitch, u32 width, u32 height, u32 bpp);
    // Address: 0x00018c40 - 0x00018c41 (1 bytes)
    virtual void createProperty(MtPropertyList& s) {}  // vtable slot 4
    cBrowserRenderDevicePS4* getRenderDevice();
private:
    SNJ_BROWSER_SYSINFO m_sysinf;  // offset: 0x8
    cBrowserApplicationTask* m_brwtsk;  // offset: 0x150
    SNJ_BROWSER_PS4_RENDERDEVICE m_dev;  // offset: 0x158
    cBrowserRenderDevicePS4* m_pRenderDevice;  // offset: 0x198
    SNJ_BROWSER_DIRECTX m_dx;  // offset: 0x1a0
    void* m_memptr;  // offset: 0x1d8
    size_t m_memsiz;  // offset: 0x1e0
    int m_ini;  // offset: 0x1e8
    unsigned int m_flg;  // offset: 0x1ec
    int m_dspx;  // offset: 0x1f0
    int m_dspy;  // offset: 0x1f4
    int m_dspw;  // offset: 0x1f8
    int m_dsph;  // offset: 0x1fc
    int m_texw;  // offset: 0x200
    int m_texh;  // offset: 0x204
    float m_vel;  // offset: 0x208
    int m_accfrm;  // offset: 0x20c
    float mVeclocityCtr;  // offset: 0x210
    float mVeclocityRate;  // offset: 0x214
public:
    u32 mValidDevice;  // offset: 0x218
    cBrowserKeepString mKeepJSString;  // offset: 0x220
    static MyDTI DTI;
    static const char* mUserAgentTable[2][2];
    static const u32 URL_STRING_KEEP_NUM = 10;
};
