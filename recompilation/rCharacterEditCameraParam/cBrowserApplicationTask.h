#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cBrowserPS4;

// Declarations
class cBrowserApplicationTask;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cBrowserApplicationTask : public MtObject
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
private:
    void reset_member();
    int is_initialized();
    int application_initialize();
    int application_move();
    void application_draw();
    int application_finalize_wait();
    void application_finalize();
public:
    cBrowserApplicationTask();
    cBrowserApplicationTask(cBrowserPS4* brw);
    virtual ~cBrowserApplicationTask();
    int request(int tskidx, const void* prm);
    int initialize();
    int finalize_wait();
    void finalize();
    void move();
    void draw();
private:
    cBrowserPS4* m_brw;  // offset: 0x8
    int m_ini;  // offset: 0x10
    int m_rno0;  // offset: 0x14
    int m_tskidx;  // offset: 0x18
    const void* m_prm;  // offset: 0x20
public:
    static MyDTI DTI;
};
